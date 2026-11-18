#include "decls.h"

/* _gleLightMaterialRGBAChange_FB_A @ 0x32efc (224 bytes) */
void _gleLightMaterialRGBAChange_FB_A(glContext, param_2)
  int glContext;
  undefined8 *param_2;
{
  byte bVar1;
  undefined8 *puVar2;
  int iVar3;
  int glContextWord5424;
  int iVar4;
  int iVar5;
  int loopIndex;
  undefined8 uVar7;
  
  loopIndex = 0;
  do {
    puVar2 = (undefined8 *)((int (*)())_glePushMaterial)(glContext,loopIndex);
    *puVar2 = *param_2;
    uVar7 = param_2[1];
    *(ushort *)((int)puVar2 + 0x234) = *(ushort *)((int)puVar2 + 0x234) | 0x404;
    puVar2[1] = uVar7;
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar1 = *(byte *)(loopIndex * 6 + *(int *)(glContext + 0x5420) + 0x2c0);
    }
    else {
      bVar1 = *(byte *)(loopIndex * 6 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f4);
    }
    iVar4 = loopIndex * 6;
    iVar5 = (bVar1 >> 3 & 0x1c) + glContext;
    loopIndex = loopIndex + 1;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar1 & 0x1f);
    bVar1 = *(byte *)(iVar4 + glContextWord5424 + 0x2c0);
    iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
    *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
  } while (loopIndex < 2);
  return;
}

/* _glePushMaterial @ 0x32fdc (260 bytes) */
int _glePushMaterial(glContext, param_2)
  int glContext;
  int param_2;
{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  puVar3 = *(undefined8 **)(param_2 * 4 + glContext + 0x4dd0);
  if (((*(ushort *)(glContext + 0x4a10) & 0x8000) == 0) && (*(int *)(puVar3 + 0x3c) != 0)) {
    puVar2 = *(undefined8 **)(glContext + 0x4dd8);
    if (puVar2 == (undefined8 *)0x0) {
      puVar2 = (undefined8 *)_gleVecAlloc(0x240);
      *(undefined4 *)((int)puVar2 + 500) = 0xbf800000;
    }
    else {
      *(undefined4 *)(glContext + 0x4dd8) = *(undefined4 *)((int)puVar2 + 0x23c);
    }
    *puVar2 = *puVar3;
    puVar2[1] = puVar3[1];
    puVar2[2] = puVar3[2];
    puVar2[3] = puVar3[3];
    puVar2[4] = puVar3[4];
    puVar2[5] = puVar3[5];
    puVar2[6] = puVar3[6];
    uVar4 = puVar3[7];
    *(undefined4 *)(puVar2 + 0x47) = 0;
    puVar2[7] = uVar4;
    uVar1 = *(undefined4 *)(puVar3 + 8);
    *(undefined4 *)(puVar2 + 0x3c) = 0;
    *(undefined8 **)(puVar3 + 0x47) = puVar2;
    *(undefined4 *)(puVar2 + 8) = uVar1;
    *(undefined8 **)((int)puVar2 + 0x23c) = puVar3;
    *(undefined8 **)(param_2 * 4 + glContext + 0x4dd0) = puVar2;
    *(undefined4 *)((int)puVar2 + 0x234) = 0x1f000000;
    puVar3 = puVar2;
  }
  else if ((*(ushort *)(glContext + 0x4a10) & 0x8000) != 0) {
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 1;
  }
  return puVar3;
}

/* _gleLightMaterialRGBAChange_FB_D @ 0x330e0 (224 bytes) */
void _gleLightMaterialRGBAChange_FB_D(glContext, param_2)
  int glContext;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int glContextWord5424;
  int iVar3;
  int iVar4;
  int loopIndex;
  undefined8 uVar6;
  
  loopIndex = 0;
  do {
    iVar2 = ((int (*)())_glePushMaterial)(glContext,loopIndex);
    *(undefined8 *)(iVar2 + 0x10) = *param_2;
    uVar6 = param_2[1];
    *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x808;
    *(undefined8 *)(iVar2 + 0x18) = uVar6;
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar1 = *(byte *)(loopIndex * 6 + *(int *)(glContext + 0x5420) + 0x2c1);
    }
    else {
      bVar1 = *(byte *)(loopIndex * 6 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f5);
    }
    iVar3 = loopIndex * 6;
    iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
    loopIndex = loopIndex + 1;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
    bVar1 = *(byte *)(iVar3 + glContextWord5424 + 0x2c1);
    iVar2 = (bVar1 >> 3 & 0x1c) + glContext;
    *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  } while (loopIndex < 2);
  return;
}

/* _gleLightMaterialShineChange_FB @ 0x331c0 (220 bytes) */
void _gleLightMaterialShineChange_FB(int glContext,float fparam_1)
{
  byte bVar1;
  int iVar2;
  int glContextWord5424;
  int iVar3;
  int iVar4;
  uint loopIndex;
  
  loopIndex = 0;
  do {
    iVar2 = ((int (*)())_glePushMaterial)(glContext,loopIndex);
    *(float *)(iVar2 + 0x40) = (float)fparam_1;
    *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x101;
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar1 = *(byte *)(loopIndex * 6 + *(int *)(glContext + 0x5420) + 0x2c4);
    }
    else {
      bVar1 = *(byte *)(loopIndex * 6 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f8);
    }
    iVar3 = loopIndex * 6;
    iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
    loopIndex = loopIndex + 1;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
    bVar1 = *(byte *)(iVar3 + glContextWord5424 + 0x2c4);
    iVar2 = (bVar1 >> 3 & 0x1c) + glContext;
    *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  } while (loopIndex < 2);
  return;
}

/* _gleLightMaterialRGBAChange_FB_S @ 0x3329c (224 bytes) */
void _gleLightMaterialRGBAChange_FB_S(glContext, rgba)
  int glContext;
  undefined8 *rgba;
{
  byte dirtyBitIndex;
  int material;
  int dirtyWordAddress348;
  int glContextWord5424;
  int dirtyBitTableOffset;
  int dirtyWordAddress324;
  int loopIndex;
  undefined8 rgbaBlueAlpha;
  
  loopIndex = 0;
  do {
    material = ((int (*)())_glePushMaterial)(glContext,loopIndex);
    *(undefined8 *)(material + 0x20) = *rgba;
    rgbaBlueAlpha = rgba[1];
    *(ushort *)(material + 0x234) = *(ushort *)(material + 0x234) | 0x1010;
    *(undefined8 *)(material + 0x28) = rgbaBlueAlpha;
    if (*(int *)(glContext + 0x5434) == 0) {
      dirtyBitIndex = *(byte *)(loopIndex * 6 + *(int *)(glContext + 0x5420) + 0x2c2);
    }
    else {
      dirtyBitIndex = *(byte *)(loopIndex * 6 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f6);
    }
    dirtyBitTableOffset = loopIndex * 6;
    dirtyWordAddress324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
    loopIndex = loopIndex + 1;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWordAddress324 + 0x324) = *(uint *)(dirtyWordAddress324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
    dirtyBitIndex = *(byte *)(dirtyBitTableOffset + glContextWord5424 + 0x2c2);
    dirtyWordAddress348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
    *(uint *)(dirtyWordAddress348 + 0x348) = *(uint *)(dirtyWordAddress348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
  } while (loopIndex < 2);
  return;
}

/* _glPushMatrix_Exec @ 0x3337c (244 bytes) */
int _glPushMatrix_Exec(glContext)
  int glContext;
{
  undefined4 glErrorCode;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int matrixModeIndex;
  
  matrixModeIndex = *(int *)(glContext + 0x4ff4);
  if ((*(short *)(glContext + 0x4a10) < 0) && (matrixModeIndex < 0x18)) {
    iVar1 = matrixModeIndex * 4;
    iVar3 = *(int *)(iVar1 + *(int *)(glContext + 0x4ff8));
    iVar4 = *(int *)(iVar1 + glContext + 0x4ffc);
    if (iVar4 < *(int *)(iVar1 + *(int *)(glContext + 0x4ff8) + 4) - iVar3) {
      uVar2 = ((int (*)())_gleCopyMatrix)(glContext + matrixModeIndex * 0x40 + 0x1bc0,
                             *(int *)(glContext + 0x4678) + (iVar3 + iVar4) * 0x40);
      if (matrixModeIndex == 4) {
        if ((*(uint *)(glContext + 0x50b0) & 0x10) != 0) {
          ((double (*)())_gleModelMatInvert)(glContext);
        }
        uVar2 = ((int (*)())_gleCopyMatrix)(glContext + 0x22c0,*(int *)(glContext + 0x4678) + iVar4 * 0x40 + 0x2b00);
      }
      *(int *)(iVar1 + glContext + 0x4ffc) = iVar4 + 1;
      return uVar2;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return glContext;
    }
    glErrorCode = 0x503;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return glContext;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return glContext;
}

/* _gleCopyMatrix @ 0x33470 (68 bytes) */
int _gleCopyMatrix(param_1, param_2)
  undefined8 *param_1;
  undefined8 *param_2;
{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[5];
  param_2[6] = param_1[6];
  param_2[7] = param_1[7];
  return;
}

/* _gleModelMatInvert @ 0x334b4 (188 bytes) */
double _gleModelMatInvert(int glContext)
{
  int loopIndex;
  int remaining;
  double invertResultOrRescaleFactor;
  double normalLengthThenRescaleFactor;
  
  *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) & 0xffffffef;
  invertResultOrRescaleFactor = (double)(*(double ( *)(int,int))_gleInvertMatrix)(glContext, 4);
  if (*(char *)(glContext + 0x280e) == '\0') {
    *(undefined4 *)(glContext + 0x2804) = 0x3f800000;
  }
  else {
    normalLengthThenRescaleFactor = _sqrt((double)(*(float *)(glContext + 0x22e8) * *(float *)(glContext + 0x22e8) +
                          (*(float *)(glContext + 0x22d8) * *(float *)(glContext + 0x22d8) +
                          *(float *)(glContext + 0x22c8) * *(float *)(glContext + 0x22c8))));
    remaining = 0x10;
    loopIndex = 0;
    normalLengthThenRescaleFactor = DOUBLE_00108d68 / normalLengthThenRescaleFactor;
    invertResultOrRescaleFactor = (double)(float)normalLengthThenRescaleFactor;
    do {
      *(float *)(loopIndex + glContext + 0x22c0) =
           (float)((double)*(float *)(loopIndex + glContext + 0x22c0) * invertResultOrRescaleFactor);
      loopIndex = loopIndex + 4;
      remaining = remaining + -1;
    } while (remaining != 0);
    *(float *)(glContext + 0x2804) = (float)normalLengthThenRescaleFactor;
  }
  return invertResultOrRescaleFactor;
}

/* _gleSetupInvertMatrix @ 0x33570 (80 bytes) */
void _gleSetupInvertMatrix()
{
  _gleInvertMatrix = PTR__gleInvertMatrix_601_00110e80;
  if ((*(uint *)PTR__gle_processor_0011204c & 0x10) != 0) {
    _gleInvertMatrix = PTR__gleInvertMatrix_AltiVec_00110e84;
  }
                    
                    
  (*(code *)_gleInvertMatrix)();
  return;
}

/* _glPopMatrix_Exec @ 0x33830 (276 bytes) */
int _glPopMatrix_Exec(glContext)
  int glContext;
{
  undefined4 glErrorCode;
  uint uVar1;
  undefined4 uVar2;
  int glContextWord4678;
  int iVar4;
  int iVar5;
  int remaining;
  int matrixModeIndex;
  uint uVar8;
  
  matrixModeIndex = *(int *)(glContext + 0x4ff4);
  if ((*(short *)(glContext + 0x4a10) < 0) && (matrixModeIndex < 0x18)) {
    iVar4 = matrixModeIndex * 4 + glContext;
    remaining = *(int *)(iVar4 + 0x4ffc);
    if (0 < remaining) {
      remaining = remaining + -1;
      glContextWord4678 = *(int *)(glContext + 0x4678);
      iVar5 = *(int *)(matrixModeIndex * 4 + *(int *)(glContext + 0x4ff8));
      *(int *)(iVar4 + 0x4ffc) = remaining;
      uVar2 = ((int (*)())_gleCopyMatrix)(glContextWord4678 + (iVar5 + remaining) * 0x40,glContext + matrixModeIndex * 0x40 + 0x1bc0);
      uVar8 = *(uint *)(glContext + 0x50a8);
      *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | uVar8;
      if ((matrixModeIndex == 4) && ((uVar8 & *(uint *)(glContext + 0x505c) & 0xfffffc) != 0)) {
        uVar2 = ((int (*)())_gleCopyMatrix)(*(int *)(glContext + 0x4678) + remaining * 0x40 + 0x2b00,glContext + 0x22c0);
        uVar1 = uVar8 & 0xfffffc;
        uVar8 = uVar8 & 0xff000003;
        *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) & ~uVar1;
      }
      *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | uVar8;
      return uVar2;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return glContext;
    }
    glErrorCode = 0x504;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return glContext;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return glContext;
}

/* _glGenLists_Exec @ 0x33944 (188 bytes) */
int _glGenLists_Exec(glContext, listRange)
  int glContext;
  int listRange;
{
  undefined4 glErrorCode;
  undefined4 uVar1;
  int sharedState;
  
  if (listRange < 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(short *)(glContext + 0x4a10) < 0) {
      sharedState = *(int *)(glContext + 0x5148);
      if (*(char *)(sharedState + 0x8024) != '\0') {
        _pthread_mutex_lock(sharedState + 0x8028);
        sharedState = *(int *)(glContext + 0x5148);
      }
      uVar1 = _gleGenHashNames(sharedState + 0x300c,listRange);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        return uVar1;
      }
      return uVar1;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _glNewList_Exec @ 0x33a00 (116 bytes) */
void _glNewList_Exec(glContext, list, mode)
  int glContext;
  int list;
  int mode;
{
  undefined4 glErrorCode;
  
  if (list == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else if (mode - 0x1300U < 2) {
    if ((*(int *)(glContext + 0x5408) == 0) && (*(short *)(glContext + 0x4a10) < 0)) {
      ((int (*)())_gleNewList)(glContext,list,mode);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _gleNewList @ 0x33a74 (22516 bytes) */
int _gleNewList(glContext, list, mode)
  int glContext;
  undefined4 list;
  undefined *mode;
{
  uint emptySlotMask;
  undefined *destructor;
  undefined4 *displayListBlock;
  undefined4 compDispatchResult;
  
  displayListBlock = (undefined4 *)_malloc(0x1000);
  displayListBlock[10] = 0;
  *(undefined4 *)(glContext + 0x5400) = 0x2c;
  destructor = PTR__gleFreeDisplayListObject_00110a24;
  *(undefined4 *)(glContext + 0x53fc) = 0x1000;
  displayListBlock[1] = list;
  displayListBlock[2] = 1;
  displayListBlock[3] = destructor;
  *(undefined **)(glContext + 0x5408) = mode;
  *(undefined4 **)(glContext + 0x53e8) = displayListBlock;
  *(undefined4 *)(glContext + 0x53ec) = 0;
  *(undefined4 *)(glContext + 0x53f0) = 0;
  *displayListBlock = 0;
  displayListBlock[4] = 0;
  displayListBlock[5] = 0;
  displayListBlock[6] = 0;
  displayListBlock[7] = 0;
  displayListBlock[9] = 0;
  if (mode == ((unsigned char *)0x00001300)) {
    compDispatchResult = _gliCompDispatchTable(glContext);
    return compDispatchResult;
  }
  emptySlotMask = -(uint)(**(int **)(glContext + 0x4684) == 0);
  *(undefined **)(*(uint *)(glContext + 0x4680) & emptySlotMask | (uint)*(int **)(glContext + 0x4684) & ~emptySlotMask)
       = PTR__glAccum_CompExec_00112c00;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 4) == 0);
  *(undefined **)((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 4)
       = PTR__glAlphaFunc_CompExec_00112bfc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xc) =
       PTR__glArrayElement_CompExec_00112bf8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x10) =
       PTR__glBegin_CompExec_001122e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x14) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x14) =
       PTR__glBindTexture_CompExec_00112bf4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x18) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x18) =
       PTR__glBitmap_CompExec_00112bf0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1c) =
       PTR__glBlendFunc_CompExec_00112bec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x20) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x20) =
       PTR__glCallList_CompExec_00112be8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x24) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x24) =
       PTR__glCallLists_CompExec_00112be4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x28) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x28) =
       PTR__glClear_CompExec_00112be0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2c) =
       PTR__glClearAccum_CompExec_00112bdc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x30) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x30) =
       PTR__glClearColor_CompExec_00112bd8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x34) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x34) =
       PTR__glClearDepth_CompExec_00112bd4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x38) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x38) =
       PTR__glClearIndex_CompExec_00112bd0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3c) =
       PTR__glClearStencil_CompExec_00112bcc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x40) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x40) =
       PTR__glClipPlane_CompExec_00112bc8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x44) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x44) =
       PTR__glColor3b_CompExec_00112bc4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x48) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x48) =
       PTR__glColor3bv_CompExec_00112bc0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4c) =
       PTR__glColor3d_CompExec_00112bbc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x50) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x50) =
       PTR__glColor3dv_CompExec_00112bb8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x54) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x54) =
       PTR__glColor3f_CompExec_00112bb4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x58) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x58) =
       PTR__glColor3fv_CompExec_00112bb0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5c) =
       PTR__glColor3i_CompExec_00112bac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x60) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x60) =
       PTR__glColor3iv_CompExec_00112ba8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 100) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 100) =
       PTR__glColor3s_CompExec_00112ba4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x68) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x68) =
       PTR__glColor3sv_CompExec_00112ba0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6c) =
       PTR__glColor3ub_CompExec_00112b9c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x70) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x70) =
       PTR__glColor3ubv_CompExec_00112b98;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x74) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x74) =
       PTR__glColor3ui_CompExec_00112b94;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x78) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x78) =
       PTR__glColor3uiv_CompExec_00112b90;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7c) =
       PTR__glColor3us_CompExec_00112b8c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x80) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x80) =
       PTR__glColor3usv_CompExec_00112b88;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x84) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x84) =
       PTR__glColor4b_CompExec_00112b84;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x88) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x88) =
       PTR__glColor4bv_CompExec_00112b80;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8c) =
       PTR__glColor4d_CompExec_00112b7c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x90) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x90) =
       PTR__glColor4dv_CompExec_00112b78;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x94) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x94) =
       PTR__glColor4f_CompExec_00112b74;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x98) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x98) =
       PTR__glColor4fv_CompExec_00112b70;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9c) =
       PTR__glColor4i_CompExec_00112b6c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa0) =
       PTR__glColor4iv_CompExec_00112b68;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa4) =
       PTR__glColor4s_CompExec_00112b64;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa8) =
       PTR__glColor4sv_CompExec_00112b60;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xac) =
       PTR__glColor4ub_CompExec_00112b5c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xb0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xb0) =
       PTR__glColor4ubv_CompExec_00112b58;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xb4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xb4) =
       PTR__glColor4ui_CompExec_00112b54;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xb8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xb8) =
       PTR__glColor4uiv_CompExec_00112b50;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xbc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xbc) =
       PTR__glColor4us_CompExec_00112b4c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xc0) =
       PTR__glColor4usv_CompExec_00112b48;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xc4) =
       PTR__glColorMask_CompExec_00112b44;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 200) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 200) =
       PTR__glColorMaterial_CompExec_00112b40;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xd0) =
       PTR__glCopyPixels_CompExec_00112b3c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xd4) =
       PTR__glCopyTexImage1D_CompExec_00112b38;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xd8) =
       PTR__glCopyTexImage2D_CompExec_00112b34;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xdc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xdc) =
       PTR__glCopyTexSubImage1D_CompExec_00112b30;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xe0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xe0) =
       PTR__glCopyTexSubImage2D_CompExec_00112b2c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xe4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xe4) =
       PTR__glCullFace_CompExec_00112b28;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xf0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xf0) =
       PTR__glDepthFunc_CompExec_00112b24;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xf4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xf4) =
       PTR__glDepthMask_CompExec_00112b20;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xf8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xf8) =
       PTR__glDepthRange_CompExec_00112b1c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xfc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xfc) =
       PTR__glDisable_CompExec_00112b18;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x104) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x104) =
       PTR__glDrawArrays_CompExec_00112b14;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x108) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x108) =
       PTR__glDrawBuffer_CompExec_00112b10;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x10c) =
       PTR__glDrawElements_CompExec_00112b0c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x110) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x110) =
       PTR__glDrawPixels_CompExec_00112b08;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x114) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x114) =
       PTR__glEdgeFlag_CompExec_00112b04;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x11c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x11c) =
       PTR__glEdgeFlagv_CompExec_00112b00;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x120) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x120) =
       PTR__glEnable_CompExec_00112afc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x128) =
       PTR__glEnd_CompExec_00112384;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x130) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x130) =
       PTR__glEvalCoord1d_CompExec_00112af8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x134) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x134) =
       PTR__glEvalCoord1dv_CompExec_00112af4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x138) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x138) =
       PTR__glEvalCoord1f_CompExec_00112af0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x13c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x13c) =
       PTR__glEvalCoord1fv_CompExec_00112aec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x140) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x140) =
       PTR__glEvalCoord2d_CompExec_00112ae8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x144) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x144) =
       PTR__glEvalCoord2dv_CompExec_00112ae4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x148) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x148) =
       PTR__glEvalCoord2f_CompExec_00112ae0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x14c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x14c) =
       PTR__glEvalCoord2fv_CompExec_00112adc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x150) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x150) =
       PTR__glEvalMesh1_CompExec_00112ad8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x154) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x154) =
       PTR__glEvalMesh2_CompExec_00112ad4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x158) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x158) =
       PTR__glEvalPoint1_CompExec_00112ad0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x15c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x15c) =
       PTR__glEvalPoint2_CompExec_00112acc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x16c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x16c) =
       PTR__glFogf_CompExec_00112ac8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x170) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x170) =
       PTR__glFogfv_CompExec_00112ac4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x174) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x174) =
       PTR__glFogi_CompExec_00112ac0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x178) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x178) =
       PTR__glFogiv_CompExec_00112abc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x17c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x17c) =
       PTR__glFrontFace_CompExec_00112ab8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x180) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x180) =
       PTR__glFrustum_CompExec_00112ab4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x200) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x200) =
       PTR__glHint_CompExec_00112ab0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x204) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x204) =
       PTR__glIndexMask_CompExec_00112aac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x20c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x20c) =
       PTR__glIndexd_CompExec_00112aa8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x210) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x210) =
       PTR__glIndexdv_CompExec_00112aa4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x214) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x214) =
       PTR__glIndexf_CompExec_00112aa0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x218) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x218) =
       PTR__glIndexfv_CompExec_00112a9c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x21c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x21c) =
       PTR__glIndexi_CompExec_00112a98;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x220) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x220) =
       PTR__glIndexiv_CompExec_00112a94;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x224) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x224) =
       PTR__glIndexs_CompExec_00112a90;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x228) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x228) =
       PTR__glIndexsv_CompExec_00112a8c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x22c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x22c) =
       PTR__glIndexub_CompExec_00112a88;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x230) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x230) =
       PTR__glIndexubv_CompExec_00112a84;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x234) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x234) =
       PTR__glInitNames_CompExec_00112a80;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x248) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x248) =
       PTR__glLightModelf_CompExec_00112a7c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x24c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x24c) =
       PTR__glLightModelfv_CompExec_00112a78;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x250) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x250) =
       PTR__glLightModeli_CompExec_00112a74;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x254) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x254) =
       PTR__glLightModeliv_CompExec_00112a70;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 600) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 600) =
       PTR__glLightf_CompExec_00112a6c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x25c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x25c) =
       PTR__glLightfv_CompExec_00112a68;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x260) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x260) =
       PTR__glLighti_CompExec_00112a64;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x264) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x264) =
       PTR__glLightiv_CompExec_00112a60;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x268) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x268) =
       PTR__glLineStipple_CompExec_00112a5c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x26c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x26c) =
       PTR__glLineWidth_CompExec_00112a58;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x270) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x270) =
       PTR__glListBase_CompExec_00112a54;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x274) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x274) =
       PTR__glLoadIdentity_CompExec_00112a50;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x278) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x278) =
       PTR__glLoadMatrixd_CompExec_00112a4c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x27c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x27c) =
       PTR__glLoadMatrixf_CompExec_00112a48;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x280) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x280) =
       PTR__glLoadName_CompExec_00112a44;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x284) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x284) =
       PTR__glLogicOp_CompExec_00112a40;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x288) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x288) =
       PTR__glMap1d_CompExec_00112a3c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x28c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x28c) =
       PTR__glMap1f_CompExec_00112a38;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x290) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x290) =
       PTR__glMap2d_CompExec_00112a34;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x294) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x294) =
       PTR__glMap2f_CompExec_00112a30;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x298) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x298) =
       PTR__glMapGrid1d_CompExec_00112a2c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x29c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x29c) =
       PTR__glMapGrid1f_CompExec_00112a28;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2a0) =
       PTR__glMapGrid2d_CompExec_00112a24;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2a4) =
       PTR__glMapGrid2f_CompExec_00112a20;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2a8) =
       PTR__glMaterialf_CompExec_00112a1c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2ac) =
       PTR__glMaterialfv_CompExec_00112a18;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2b0) =
       PTR__glMateriali_CompExec_00112a14;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2b4) =
       PTR__glMaterialiv_CompExec_00112a10;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2b8) =
       PTR__glMatrixMode_CompExec_00112a0c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 700) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 700) =
       PTR__glMultMatrixd_CompExec_00112a08;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2c0) =
       PTR__glMultMatrixf_CompExec_00112a04;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2c8) =
       PTR__glNormal3b_CompExec_00112a00;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2cc) =
       PTR__glNormal3bv_CompExec_001129fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2d0) =
       PTR__glNormal3d_CompExec_001129f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2d4) =
       PTR__glNormal3dv_CompExec_001129f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2d8) =
       PTR__glNormal3f_CompExec_001129f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2dc) =
       PTR__glNormal3fv_CompExec_001129ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2e0) =
       PTR__glNormal3i_CompExec_001129e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2e4) =
       PTR__glNormal3iv_CompExec_001129e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2e8) =
       PTR__glNormal3s_CompExec_001129e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2ec) =
       PTR__glNormal3sv_CompExec_001129dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2f4) =
       PTR__glOrtho_CompExec_001129d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2f8) =
       PTR__glPassThrough_CompExec_001129d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2fc) =
       PTR__glPixelMapfv_CompExec_001129d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x300) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x300) =
       PTR__glPixelMapuiv_CompExec_001129cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x304) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x304) =
       PTR__glPixelMapusv_CompExec_001129c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x310) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x310) =
       PTR__glPixelTransferf_CompExec_001129c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x314) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x314) =
       PTR__glPixelTransferi_CompExec_001129c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x318) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x318) =
       PTR__glPixelZoom_CompExec_001129bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x31c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x31c) =
       PTR__glPointSize_CompExec_001129b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 800) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 800) =
       PTR__glPolygonMode_CompExec_001129b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x324) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x324) =
       PTR__glPolygonOffset_CompExec_001129b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x328) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x328) =
       PTR__glPolygonStipple_CompExec_001129ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x32c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x32c) =
       PTR__glPopAttrib_CompExec_001129a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x334) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x334) =
       PTR__glPopMatrix_CompExec_001129a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x338) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x338) =
       PTR__glPopName_CompExec_001129a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x33c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x33c) =
       PTR__glPrioritizeTextures_CompExec_0011299c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x340) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x340) =
       PTR__glPushAttrib_CompExec_00112998;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x348) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x348) =
       PTR__glPushMatrix_CompExec_00112994;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x34c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x34c) =
       PTR__glPushName_CompExec_00112990;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x350) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x350) =
       PTR__glRasterPos2d_CompExec_0011298c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x354) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x354) =
       PTR__glRasterPos2dv_CompExec_00112988;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x358) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x358) =
       PTR__glRasterPos2f_CompExec_00112984;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x35c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x35c) =
       PTR__glRasterPos2fv_CompExec_00112980;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x360) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x360) =
       PTR__glRasterPos2i_CompExec_0011297c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x364) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x364) =
       PTR__glRasterPos2iv_CompExec_00112978;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x368) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x368) =
       PTR__glRasterPos2s_CompExec_00112974;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x36c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x36c) =
       PTR__glRasterPos2sv_CompExec_00112970;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x370) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x370) =
       PTR__glRasterPos3d_CompExec_0011296c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x374) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x374) =
       PTR__glRasterPos3dv_CompExec_00112968;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x378) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x378) =
       PTR__glRasterPos3f_CompExec_00112964;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x37c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x37c) =
       PTR__glRasterPos3fv_CompExec_00112960;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x380) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x380) =
       PTR__glRasterPos3i_CompExec_0011295c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 900) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 900) =
       PTR__glRasterPos3iv_CompExec_00112958;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x388) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x388) =
       PTR__glRasterPos3s_CompExec_00112954;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x38c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x38c) =
       PTR__glRasterPos3sv_CompExec_00112950;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x390) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x390) =
       PTR__glRasterPos4d_CompExec_0011294c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x394) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x394) =
       PTR__glRasterPos4dv_CompExec_00112948;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x398) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x398) =
       PTR__glRasterPos4f_CompExec_00112944;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x39c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x39c) =
       PTR__glRasterPos4fv_CompExec_00112940;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3a0) =
       PTR__glRasterPos4i_CompExec_0011293c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3a4) =
       PTR__glRasterPos4iv_CompExec_00112938;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3a8) =
       PTR__glRasterPos4s_CompExec_00112934;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3ac) =
       PTR__glRasterPos4sv_CompExec_00112930;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3b0) =
       PTR__glReadBuffer_CompExec_0011292c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3b8) =
       PTR__glRectd_CompExec_00112928;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3bc) =
       PTR__glRectdv_CompExec_00112924;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3c0) =
       PTR__glRectf_CompExec_00112920;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3c4) =
       PTR__glRectfv_CompExec_0011291c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3c8) =
       PTR__glRecti_CompExec_00112918;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3cc) =
       PTR__glRectiv_CompExec_00112914;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3d0) =
       PTR__glRects_CompExec_00112910;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3d4) =
       PTR__glRectsv_CompExec_0011290c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3dc) =
       PTR__glRotated_CompExec_00112908;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3e0) =
       PTR__glRotatef_CompExec_00112904;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3e4) =
       PTR__glScaled_CompExec_00112900;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 1000) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 1000) =
       PTR__glScalef_CompExec_001128fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3ec) =
       PTR__glScissor_CompExec_001128f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3f4) =
       PTR__glShadeModel_CompExec_001128f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3f8) =
       PTR__glStencilFunc_CompExec_001128f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3fc) =
       PTR__glStencilMask_CompExec_001128ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x400) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x400) =
       PTR__glStencilOp_CompExec_001128e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x404) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x404) =
       PTR__glTexCoord1d_CompExec_001128e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x408) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x408) =
       PTR__glTexCoord1dv_CompExec_001128e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x40c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x40c) =
       PTR__glTexCoord1f_CompExec_001128dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x410) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x410) =
       PTR__glTexCoord1fv_CompExec_001128d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x414) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x414) =
       PTR__glTexCoord1i_CompExec_001128d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x418) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x418) =
       PTR__glTexCoord1iv_CompExec_001128d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x41c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x41c) =
       PTR__glTexCoord1s_CompExec_001128cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x420) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x420) =
       PTR__glTexCoord1sv_CompExec_001128c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x424) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x424) =
       PTR__glTexCoord2d_CompExec_001128c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x428) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x428) =
       PTR__glTexCoord2dv_CompExec_001128c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x42c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x42c) =
       PTR__glTexCoord2f_CompExec_001128bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x430) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x430) =
       PTR__glTexCoord2fv_CompExec_001128b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x434) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x434) =
       PTR__glTexCoord2i_CompExec_001128b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x438) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x438) =
       PTR__glTexCoord2iv_CompExec_001128b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x43c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x43c) =
       PTR__glTexCoord2s_CompExec_001128ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x440) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x440) =
       PTR__glTexCoord2sv_CompExec_001128a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x444) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x444) =
       PTR__glTexCoord3d_CompExec_001128a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x448) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x448) =
       PTR__glTexCoord3dv_CompExec_001128a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x44c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x44c) =
       PTR__glTexCoord3f_CompExec_0011289c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x450) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x450) =
       PTR__glTexCoord3fv_CompExec_00112898;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x454) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x454) =
       PTR__glTexCoord3i_CompExec_00112894;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x458) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x458) =
       PTR__glTexCoord3iv_CompExec_00112890;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x45c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x45c) =
       PTR__glTexCoord3s_CompExec_0011288c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x460) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x460) =
       PTR__glTexCoord3sv_CompExec_00112888;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x464) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x464) =
       PTR__glTexCoord4d_CompExec_00112884;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x468) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x468) =
       PTR__glTexCoord4dv_CompExec_00112880;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x46c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x46c) =
       PTR__glTexCoord4f_CompExec_0011287c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x470) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x470) =
       PTR__glTexCoord4fv_CompExec_00112878;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x474) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x474) =
       PTR__glTexCoord4i_CompExec_00112874;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x478) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x478) =
       PTR__glTexCoord4iv_CompExec_00112870;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x47c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x47c) =
       PTR__glTexCoord4s_CompExec_0011286c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x480) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x480) =
       PTR__glTexCoord4sv_CompExec_00112868;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x488) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x488) =
       PTR__glTexEnvf_CompExec_00112864;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x48c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x48c) =
       PTR__glTexEnvfv_CompExec_00112860;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x490) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x490) =
       PTR__glTexEnvi_CompExec_0011285c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x494) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x494) =
       PTR__glTexEnviv_CompExec_00112858;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x498) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x498) =
       PTR__glTexGend_CompExec_00112854;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x49c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x49c) =
       PTR__glTexGendv_CompExec_00112850;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4a0) =
       PTR__glTexGenf_CompExec_0011284c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4a4) =
       PTR__glTexGenfv_CompExec_00112848;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4a8) =
       PTR__glTexGeni_CompExec_00112844;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4ac) =
       PTR__glTexGeniv_CompExec_00112840;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4b0) =
       PTR__glTexImage1D_CompExec_0011283c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4b4) =
       PTR__glTexImage2D_CompExec_00112838;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4b8) =
       PTR__glTexParameterf_CompExec_00112834;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4bc) =
       PTR__glTexParameterfv_CompExec_00112830;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4c0) =
       PTR__glTexParameteri_CompExec_0011282c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4c4) =
       PTR__glTexParameteriv_CompExec_00112828;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4c8) =
       PTR__glTexSubImage1D_CompExec_00112824;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4cc) =
       PTR__glTexSubImage2D_CompExec_00112820;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4d0) =
       PTR__glTranslated_CompExec_0011281c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4d4) =
       PTR__glTranslatef_CompExec_00112818;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4d8) =
       PTR__glVertex2d_CompExec_00112814;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4dc) =
       PTR__glVertex2dv_CompExec_00112810;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4e0) =
       PTR__glVertex2f_CompExec_0011280c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4e4) =
       PTR__glVertex2fv_CompExec_00112808;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4e8) =
       PTR__glVertex2i_CompExec_00112804;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4ec) =
       PTR__glVertex2iv_CompExec_00112800;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4f0) =
       PTR__glVertex2s_CompExec_001127fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4f4) =
       PTR__glVertex2sv_CompExec_001127f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4f8) =
       PTR__glVertex3d_CompExec_001127f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4fc) =
       PTR__glVertex3dv_CompExec_001127f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x500) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x500) =
       PTR__glVertex3f_CompExec_001127ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x504) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x504) =
       PTR__glVertex3fv_CompExec_001127e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x508) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x508) =
       PTR__glVertex3i_CompExec_001127e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x50c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x50c) =
       PTR__glVertex3iv_CompExec_001127e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x510) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x510) =
       PTR__glVertex3s_CompExec_001127dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x514) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x514) =
       PTR__glVertex3sv_CompExec_001127d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x518) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x518) =
       PTR__glVertex4d_CompExec_001127d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x51c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x51c) =
       PTR__glVertex4dv_CompExec_001127d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x520) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x520) =
       PTR__glVertex4f_CompExec_001127cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x524) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x524) =
       PTR__glVertex4fv_CompExec_001127c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x528) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x528) =
       PTR__glVertex4i_CompExec_001127c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x52c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x52c) =
       PTR__glVertex4iv_CompExec_001127c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x530) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x530) =
       PTR__glVertex4s_CompExec_001127bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x534) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x534) =
       PTR__glVertex4sv_CompExec_001127b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x53c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x53c) =
       PTR__glViewport_CompExec_001127b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x544) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x544) =
       PTR__glBlendColor_CompExec_001127b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x548) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x548) =
       PTR__glBlendEquation_CompExec_001127ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x558) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x558) =
       PTR__glActiveTexture_CompExec_001127a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x55c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x55c) =
       PTR__glMultiTexCoord1d_CompExec_001127a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x560) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x560) =
       PTR__glMultiTexCoord1dv_CompExec_001127a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x564) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x564) =
       PTR__glMultiTexCoord1f_CompExec_0011279c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x568) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x568) =
       PTR__glMultiTexCoord1fv_CompExec_00112798;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x56c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x56c) =
       PTR__glMultiTexCoord1i_CompExec_00112794;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x570) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x570) =
       PTR__glMultiTexCoord1iv_CompExec_00112790;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x574) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x574) =
       PTR__glMultiTexCoord1s_CompExec_0011278c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x578) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x578) =
       PTR__glMultiTexCoord1sv_CompExec_00112788;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x57c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x57c) =
       PTR__glMultiTexCoord2d_CompExec_00112784;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x580) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x580) =
       PTR__glMultiTexCoord2dv_CompExec_00112780;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x584) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x584) =
       PTR__glMultiTexCoord2f_CompExec_0011277c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x588) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x588) =
       PTR__glMultiTexCoord2fv_CompExec_00112778;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x58c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x58c) =
       PTR__glMultiTexCoord2i_CompExec_00112774;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x590) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x590) =
       PTR__glMultiTexCoord2iv_CompExec_00112770;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x594) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x594) =
       PTR__glMultiTexCoord2s_CompExec_0011276c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x598) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x598) =
       PTR__glMultiTexCoord2sv_CompExec_00112768;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x59c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x59c) =
       PTR__glMultiTexCoord3d_CompExec_00112764;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5a0) =
       PTR__glMultiTexCoord3dv_CompExec_00112760;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5a4) =
       PTR__glMultiTexCoord3f_CompExec_0011275c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5a8) =
       PTR__glMultiTexCoord3fv_CompExec_00112758;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5ac) =
       PTR__glMultiTexCoord3i_CompExec_00112754;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5b0) =
       PTR__glMultiTexCoord3iv_CompExec_00112750;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5b4) =
       PTR__glMultiTexCoord3s_CompExec_0011274c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5b8) =
       PTR__glMultiTexCoord3sv_CompExec_00112748;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5bc) =
       PTR__glMultiTexCoord4d_CompExec_00112744;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5c0) =
       PTR__glMultiTexCoord4dv_CompExec_00112740;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5c4) =
       PTR__glMultiTexCoord4f_CompExec_0011273c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5c8) =
       PTR__glMultiTexCoord4fv_CompExec_00112738;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5cc) =
       PTR__glMultiTexCoord4i_CompExec_00112734;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5d0) =
       PTR__glMultiTexCoord4iv_CompExec_00112730;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5d4) =
       PTR__glMultiTexCoord4s_CompExec_0011272c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5d8) =
       PTR__glMultiTexCoord4sv_CompExec_00112728;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5dc) =
       PTR__glLoadTransposeMatrixd_CompExec_00112724;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5e0) =
       PTR__glLoadTransposeMatrixf_CompExec_00112720;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5e4) =
       PTR__glMultTransposeMatrixd_CompExec_0011271c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5e8) =
       PTR__glMultTransposeMatrixf_CompExec_00112718;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x654) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x654) =
       PTR__glDrawRangeElements_CompExec_00112714;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6d8) =
       PTR__glTexImage3D_CompExec_00112710;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6dc) =
       PTR__glTexSubImage3D_CompExec_0011270c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6e0) =
       PTR__glCopyTexSubImage3D_CompExec_00112708;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x658) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x658) =
       PTR__glColorTable_CompExec_00112704;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x65c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x65c) =
       PTR__glColorTableParameterfv_CompExec_00112700;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x660) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x660) =
       PTR__glColorTableParameteriv_CompExec_001126fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x664) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x664) =
       PTR__glCopyColorTable_CompExec_001126f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x674) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x674) =
       PTR__glColorSubTable_CompExec_001126f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x678) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x678) =
       PTR__glCopyColorSubTable_CompExec_001126f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x67c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x67c) =
       PTR__glConvolutionFilter1D_CompExec_001126ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x680) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x680) =
       PTR__glConvolutionFilter2D_CompExec_001126e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x684) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x684) =
       PTR__glConvolutionParameterf_CompExec_001126e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x688) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x688) =
       PTR__glConvolutionParameterfv_CompExec_001126e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x68c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x68c) =
       PTR__glConvolutionParameteri_CompExec_001126dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x690) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x690) =
       PTR__glConvolutionParameteriv_CompExec_001126d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x694) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x694) =
       PTR__glCopyConvolutionFilter1D_CompExec_001126d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x698) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x698) =
       PTR__glCopyConvolutionFilter2D_CompExec_001126d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6ac) =
       PTR__glSeparableFilter2D_CompExec_001126cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6c8) =
       PTR__glHistogram_CompExec_001126c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6cc) =
       PTR__glMinmax_CompExec_001126c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6d0) =
       PTR__glResetHistogram_CompExec_001126c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6d4) =
       PTR__glResetMinmax_CompExec_001126bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5ec) =
       PTR__glCompressedTexImage3D_CompExec_001126b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5f0) =
       PTR__glCompressedTexImage2D_CompExec_001126b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5f4) =
       PTR__glCompressedTexImage1D_CompExec_001126b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5f8) =
       PTR__glCompressedTexSubImage3D_CompExec_001126ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5fc) =
       PTR__glCompressedTexSubImage2D_CompExec_001126a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x600) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x600) =
       PTR__glCompressedTexSubImage1D_CompExec_001126a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x608) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x608) =
       PTR__glSecondaryColor3b_CompExec_001126a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x60c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x60c) =
       PTR__glSecondaryColor3bv_CompExec_0011269c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x610) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x610) =
       PTR__glSecondaryColor3d_CompExec_00112698;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x614) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x614) =
       PTR__glSecondaryColor3dv_CompExec_00112694;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x618) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x618) =
       PTR__glSecondaryColor3f_CompExec_00112690;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x61c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x61c) =
       PTR__glSecondaryColor3fv_CompExec_0011268c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x620) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x620) =
       PTR__glSecondaryColor3i_CompExec_00112688;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x624) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x624) =
       PTR__glSecondaryColor3iv_CompExec_00112684;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x628) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x628) =
       PTR__glSecondaryColor3s_CompExec_00112680;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x62c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x62c) =
       PTR__glSecondaryColor3sv_CompExec_0011267c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x630) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x630) =
       PTR__glSecondaryColor3ub_CompExec_00112678;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x634) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x634) =
       PTR__glSecondaryColor3ubv_CompExec_00112674;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x638) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x638) =
       PTR__glSecondaryColor3ui_CompExec_00112670;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x63c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x63c) =
       PTR__glSecondaryColor3uiv_CompExec_0011266c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x640) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x640) =
       PTR__glSecondaryColor3us_CompExec_00112668;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x644) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x644) =
       PTR__glSecondaryColor3usv_CompExec_00112664;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x72c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x72c) =
       PTR__glSampleCoverage_CompExec_00112660;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x730) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x730) =
       PTR__glSamplePass_CompExec_0011265c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8e4) =
       PTR__glWindowPos2d_CompExec_00112658;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8e8) =
       PTR__glWindowPos2dv_CompExec_00112654;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8ec) =
       PTR__glWindowPos2f_CompExec_00112650;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8f0) =
       PTR__glWindowPos2fv_CompExec_0011264c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8f4) =
       PTR__glWindowPos2i_CompExec_00112648;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8f8) =
       PTR__glWindowPos2iv_CompExec_00112644;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8fc) =
       PTR__glWindowPos2s_CompExec_00112640;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x900) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x900) =
       PTR__glWindowPos2sv_CompExec_0011263c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x904) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x904) =
       PTR__glWindowPos3d_CompExec_00112638;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x908) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x908) =
       PTR__glWindowPos3dv_CompExec_00112634;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x90c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x90c) =
       PTR__glWindowPos3f_CompExec_00112630;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x910) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x910) =
       PTR__glWindowPos3fv_CompExec_0011262c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x914) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x914) =
       PTR__glWindowPos3i_CompExec_00112628;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x918) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x918) =
       PTR__glWindowPos3iv_CompExec_00112624;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x91c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x91c) =
       PTR__glWindowPos3s_CompExec_00112620;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x920) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x920) =
       PTR__glWindowPos3sv_CompExec_0011261c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x894) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x894) =
       PTR__glVertexArrayParameteriEXT_CompExec_00112618;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6e4) =
       PTR__glCombinerParameterfvNV_CompExec_00112614;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6e8) =
       PTR__glCombinerParameterfNV_CompExec_00112610;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6ec) =
       PTR__glCombinerParameterivNV_CompExec_0011260c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6f0) =
       PTR__glCombinerParameteriNV_CompExec_00112608;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6f4) =
       PTR__glCombinerInputNV_CompExec_00112604;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6f8) =
       PTR__glCombinerOutputNV_CompExec_00112600;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6fc) =
       PTR__glFinalCombinerInputNV_CompExec_001125fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x718) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x718) =
       PTR__glCombinerStageParameterfvNV_CompExec_001125f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x738) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x738) =
       PTR__glPNTrianglesfATIX_CompExec_001125f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x734) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x734) =
       PTR__glPNTrianglesiATIX_CompExec_001125f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x75c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x75c) =
       PTR__glBindProgramARB_CompExec_001125ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x76c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x76c) =
       PTR__glVertexAttrib1sARB_CompExec_001125e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x770) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x770) =
       PTR__glVertexAttrib1fARB_CompExec_001125e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x774) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x774) =
       PTR__glVertexAttrib1dARB_CompExec_001125e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x778) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x778) =
       PTR__glVertexAttrib2sARB_CompExec_001125dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x77c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x77c) =
       PTR__glVertexAttrib2fARB_CompExec_001125d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x780) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x780) =
       PTR__glVertexAttrib2dARB_CompExec_001125d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x784) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x784) =
       PTR__glVertexAttrib3sARB_CompExec_001125d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x788) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x788) =
       PTR__glVertexAttrib3fARB_CompExec_001125cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x78c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x78c) =
       PTR__glVertexAttrib3dARB_CompExec_001125c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x790) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x790) =
       PTR__glVertexAttrib4sARB_CompExec_001125c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x794) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x794) =
       PTR__glVertexAttrib4fARB_CompExec_001125c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x798) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x798) =
       PTR__glVertexAttrib4dARB_CompExec_001125bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x79c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x79c) =
       PTR__glVertexAttrib4NubARB_CompExec_001125b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7a0) =
       PTR__glVertexAttrib1svARB_CompExec_001125b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7a4) =
       PTR__glVertexAttrib1fvARB_CompExec_001125b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7a8) =
       PTR__glVertexAttrib1dvARB_CompExec_001125ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7ac) =
       PTR__glVertexAttrib2svARB_CompExec_001125a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7b0) =
       PTR__glVertexAttrib2fvARB_CompExec_001125a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7b4) =
       PTR__glVertexAttrib2dvARB_CompExec_001125a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7b8) =
       PTR__glVertexAttrib3svARB_CompExec_0011259c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7bc) =
       PTR__glVertexAttrib3fvARB_CompExec_00112598;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7c0) =
       PTR__glVertexAttrib3dvARB_CompExec_00112594;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7c4) =
       PTR__glVertexAttrib4bvARB_CompExec_00112590;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7c8) =
       PTR__glVertexAttrib4svARB_CompExec_0011258c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7cc) =
       PTR__glVertexAttrib4ivARB_CompExec_00112588;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 2000) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 2000) =
       PTR__glVertexAttrib4ubvARB_CompExec_00112584;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7d4) =
       PTR__glVertexAttrib4usvARB_CompExec_00112580;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7d8) =
       PTR__glVertexAttrib4uivARB_CompExec_0011257c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7dc) =
       PTR__glVertexAttrib4fvARB_CompExec_00112578;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7e0) =
       PTR__glVertexAttrib4dvARB_CompExec_00112574;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7e4) =
       PTR__glVertexAttrib4NbvARB_CompExec_00112570;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7e8) =
       PTR__glVertexAttrib4NsvARB_CompExec_0011256c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7ec) =
       PTR__glVertexAttrib4NivARB_CompExec_00112568;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7f0) =
       PTR__glVertexAttrib4NubvARB_CompExec_00112564;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7f4) =
       PTR__glVertexAttrib4NusvARB_CompExec_00112560;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7f8) =
       PTR__glVertexAttrib4NuivARB_CompExec_0011255c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x818) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x818) =
       PTR__glProgramEnvParameter4dARB_CompExec_00112558;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x81c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x81c) =
       PTR__glProgramEnvParameter4dvARB_CompExec_00112554;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x820) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x820) =
       PTR__glProgramEnvParameter4fARB_CompExec_00112550;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x824) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x824) =
       PTR__glProgramEnvParameter4fvARB_CompExec_0011254c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x828) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x828) =
       PTR__glProgramLocalParameter4dARB_CompExec_00112548;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x82c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x82c) =
       PTR__glProgramLocalParameter4dvARB_CompExec_00112544;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x830) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x830) =
       PTR__glProgramLocalParameter4fARB_CompExec_00112540;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x834) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x834) =
       PTR__glProgramLocalParameter4fvARB_CompExec_0011253c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x848) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x848) =
       PTR__glProgramStringARB_CompExec_00112538;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x854) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x854) =
       PTR__glEnableVertexAttribARB_CompExec_00112534;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x858) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x858) =
       PTR__glDisableVertexAttribARB_CompExec_00112530;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x860) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x860) =
       PTR__glMapVertexAttrib1dARB_CompExec_0011252c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x864) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x864) =
       PTR__glMapVertexAttrib1fARB_CompExec_00112528;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x868) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x868) =
       PTR__glMapVertexAttrib2dARB_CompExec_00112524;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x86c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x86c) =
       PTR__glMapVertexAttrib2fARB_CompExec_00112520;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x744) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x744) =
       PTR__glSetFenceAPPLE_CompExec_0011251c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x750) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x750) =
       PTR__glFinishFenceAPPLE_CompExec_00112518;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x758) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x758) =
       PTR__glFinishObjectAPPLE_CompExec_00112514;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x870) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x870) =
       PTR__glPointParameterf_CompExec_00112510;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x874) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x874) =
       PTR__glPointParameterfv_CompExec_0011250c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x878) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x878) =
       PTR__glPointParameteriARB_CompExec_00112508;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x87c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x87c) =
       PTR__glPointParameterivARB_CompExec_00112504;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x880) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x880) =
       PTR__glFogCoordf_CompExec_00112500;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x884) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x884) =
       PTR__glFogCoordfv_CompExec_001124fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x888) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x888) =
       PTR__glFogCoordd_CompExec_001124f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x88c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x88c) =
       PTR__glFogCoorddv_CompExec_001124f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x898) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x898) =
       PTR__glBindVertexArrayEXT_CompExec_001124f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8ac) =
       PTR__glDrawElementArrayAPPLE_CompExec_001124ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8b0) =
       PTR__glDrawRangeElementArrayAPPLE_CompExec_001124e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa60) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa60) =
       PTR__glMultiDrawRangeElementArrayAPPLE_CompExec_001124e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa5c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa5c) =
       PTR__glMultiDrawElementArrayAPPLE_CompExec_001124e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x540) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x540) =
       PTR__glBlendFuncSeparate_CompExec_001124dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x728) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x728) =
       PTR__glBlendEquationSeparateEXT_CompExec_001124d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8dc) =
       PTR__glMultiDrawArrays_CompExec_001124d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8e0) =
       PTR__glMultiDrawElements_CompExec_001124d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8b4) =
       PTR__glWeightbvARB_CompExec_001124cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8b8) =
       PTR__glWeightsvARB_CompExec_001124c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8bc) =
       PTR__glWeightivARB_CompExec_001124c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8c0) =
       PTR__glWeightfvARB_CompExec_001124c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8c4) =
       PTR__glWeightdvARB_CompExec_001124bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8c8) =
       PTR__glWeightubvARB_CompExec_001124b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8cc) =
       PTR__glWeightusvARB_CompExec_001124b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8d0) =
       PTR__glWeightuivARB_CompExec_001124b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8d8) =
       PTR__glVertexBlendARB_CompExec_001124ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x924) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x924) =
       PTR__glActiveStencilFace_CompExec_001124a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x928) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x928) =
       PTR__glStencilOpSeparateATI_CompExec_001124a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x92c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x92c) =
       PTR__glStencilFuncSeparateATI_CompExec_001124a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x960) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x960) =
       PTR__glUseProgramObjectARB_CompExec_0011249c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x968) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x968) =
       PTR__glUniform1fARB_CompExec_00112498;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x96c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x96c) =
       PTR__glUniform2fARB_CompExec_00112494;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x970) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x970) =
       PTR__glUniform3fARB_CompExec_00112490;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x974) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x974) =
       PTR__glUniform4fARB_CompExec_0011248c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x978) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x978) =
       PTR__glUniform1iARB_CompExec_00112488;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x97c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x97c) =
       PTR__glUniform2iARB_CompExec_00112484;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x980) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x980) =
       PTR__glUniform3iARB_CompExec_00112480;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x984) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x984) =
       PTR__glUniform4iARB_CompExec_0011247c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x988) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x988) =
       PTR__glUniform1fvARB_CompExec_00112478;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x98c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x98c) =
       PTR__glUniform2fvARB_CompExec_00112474;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x990) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x990) =
       PTR__glUniform3fvARB_CompExec_00112470;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x994) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x994) =
       PTR__glUniform4fvARB_CompExec_0011246c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x998) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x998) =
       PTR__glUniform1ivARB_CompExec_00112468;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x99c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x99c) =
       PTR__glUniform2ivARB_CompExec_00112464;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9a0) =
       PTR__glUniform3ivARB_CompExec_00112460;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9a4) =
       PTR__glUniform4ivARB_CompExec_0011245c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9a8) =
       PTR__glUniformMatrix2fvARB_CompExec_00112458;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9ac) =
       PTR__glUniformMatrix3fvARB_CompExec_00112454;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9b0) =
       PTR__glUniformMatrix4fvARB_CompExec_00112450;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9f4) =
       PTR__glBeginQuery_CompExec_0011244c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9f8) =
       PTR__glEndQuery_CompExec_00112448;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa34) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa34) =
       PTR__glDepthBoundsEXT_CompExec_00112444;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa38) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa38) =
       PTR__glDrawBuffersARB_CompExec_00112440;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa3c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa3c) =
       PTR__glIsShader_Exec_00113b9c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa40) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa40) =
       PTR__glIsProgram_Exec_00113b98;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa44) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa44) =
       PTR__glGetShaderiv_Exec_00113b94;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa48) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa48) =
       PTR__glGetProgramiv_Exec_00113b90;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa4c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa4c) =
       PTR__glGetShaderInfoLog_Exec_00113b8c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa50) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa50) =
       PTR__glGetProgramInfoLog_Exec_00113b88;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa54) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa54) =
       PTR__glStencilFuncSeparate_CompExec_0011243c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa58) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa58) =
       PTR__glStencilMaskSeparate_CompExec_00112438;
  return glContext;
}

/* _glCullFace_CompExec @ 0x39268 (56 bytes) */
void _glCullFace_CompExec(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  ((int (*)())_glCullFace_Comp)(glContext,mode);
  ((void (*)())_glCullFace_Exec)(glContext,mode);
  return;
}

/* _glCullFace_Comp @ 0x392a0 (76 bytes) */
int _glCullFace_Comp(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)((int (*)())_gleAddListItem)(glContext,PTR__glCullFace_ListExec_00110084,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = mode;
  }
  return listRecord;
}

/* _gleAddListItem @ 0x392ec (292 bytes) */
int _gleAddListItem(glContext, param_2, param_3)
  int glContext;
  undefined4 param_2;
  int param_3;
{
  int reallocatedBlock2;
  int reallocatedBlock;
  int iVar1;
  int glContextWord5400;
  int glContextPtr53e8;
  uint uVar3;
  int iVar4;
  int glContextWord54002;
  uint uVar5;
  int *piVar6;
  
  uVar5 = param_3 + 4;
  glContextWord5400 = *(int *)(glContext + 0x5400);
  if ((uint)(*(int *)(glContext + 0x53fc) - glContextWord5400) < uVar5) {
    uVar3 = glContextWord5400 + uVar5;
    if ((0x2000000 < uVar3) && (uVar3 = 0x2000000, 0x1ffffff < uVar5)) {
      uVar3 = param_3 + 0x24;
    }
    reallocatedBlock2 = _realloc(*(undefined4 *)(glContext + 0x53e8),glContextWord5400 + uVar3);
    *(int *)(glContext + 0x53e8) = reallocatedBlock2;
    if (reallocatedBlock2 != 0) {
      *(uint *)(glContext + 0x53fc) = glContextWord5400 + uVar3;
      goto LAB_00039364;
    }
LAB_000393a0:
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x505;
    }
    iVar1 = 0;
  }
  else {
LAB_00039364:
    glContextPtr53e8 = *(int *)(glContext + 0x53e8);
    piVar6 = (int *)(glContextPtr53e8 + 0x10);
    iVar1 = glContextPtr53e8;
    if (*(uint *)(glContextPtr53e8 + 0x18) <= *(int *)(glContextPtr53e8 + 0x10) + 1U) {
      iVar4 = *(uint *)(glContextPtr53e8 + 0x18) * 2 + 2;
      reallocatedBlock = _realloc(*(undefined4 *)(glContextPtr53e8 + 0x14),iVar4 * 4);
      *(int *)(glContextPtr53e8 + 0x14) = reallocatedBlock;
      if (reallocatedBlock == 0) goto LAB_000393a0;
      *(int *)(glContextPtr53e8 + 0x18) = iVar4;
      iVar1 = *(int *)(glContext + 0x53e8);
    }
    glContextWord54002 = *(int *)(glContext + 0x5400);
    *(undefined4 *)(iVar1 + glContextWord54002) = param_2;
    iVar1 = iVar1 + glContextWord54002 + 4;
    *(uint *)(*piVar6 * 4 + *(int *)(glContextPtr53e8 + 0x14)) = uVar5;
    *piVar6 = *piVar6 + 1;
    *(uint *)(glContext + 0x5400) = *(int *)(glContext + 0x5400) + uVar5;
  }
  return iVar1;
}

/* _glCullFace_Exec @ 0x39410 (156 bytes) */
void _glCullFace_Exec(glContext, mode)
  int glContext;
  uint mode;
{
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    return;
  }
  if (((mode < 0x404) || ((0x405 < mode && (mode != 0x408)))) &&
     (*(int *)(glContext + 0x7574) == 0)) {
    *(undefined4 *)(glContext + 0x7574) = 0x500;
  }
  *(short *)(glContext + 0x34d6) = (short)mode;
  _gleUpdatePolyMode(glContext);
  _gleUpdatePrimitiveData(glContext);
  return;
}

/* _glEnable_CompExec @ 0x394ac (56 bytes) */
void _glEnable_CompExec(glContext, cap)
  undefined4 glContext;
  undefined4 cap;
{
  ((int (*)())_glEnable_Comp)(glContext,cap);
  _glEnable_Exec(glContext,cap);
  return;
}

/* _glEnable_Comp @ 0x394e4 (76 bytes) */
int _glEnable_Comp(glContext, cap)
  undefined4 glContext;
  undefined4 cap;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)((int (*)())_gleAddListItem)(glContext,PTR__glEnable_ListExec_001100b4,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = cap;
  }
  return listRecord;
}

/* _glLoadName_CompExec @ 0x39530 (56 bytes) */
void _glLoadName_CompExec(glContext, name)
  undefined4 glContext;
  undefined4 name;
{
  ((int (*)())_glLoadName_Comp)(glContext,name);
  ((void (*)())_glLoadName_Exec)(glContext,name);
  return;
}

/* _glLoadName_Comp @ 0x39568 (76 bytes) */
int _glLoadName_Comp(glContext, name)
  undefined4 glContext;
  undefined4 name;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)((int (*)())_gleAddListItem)(glContext,PTR__glLoadName_ListExec_001102ac,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = name;
  }
  return listRecord;
}

/* _glLoadName_Exec @ 0x395b4 (80 bytes) */
void _glLoadName_Exec(glContext, name)
  int glContext;
  undefined4 name;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (*(int *)(glContext + 0x4e1c) != 0x1c02) {
      return;
    }
    if (*(int *)(glContext + 0x4fbc) != glContext + 0x4e2c) {
      *(undefined4 *)(*(int *)(glContext + 0x4fbc) + -4) = name;
      *(undefined1 *)(glContext + 0x4fc8) = 0;
      return;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glMaterialfv_CompExec @ 0x39604 (72 bytes) */
void _glMaterialfv_CompExec(glContext, face, pname, params)
  undefined4 glContext;
  undefined4 face;
  undefined4 pname;
  undefined4 params;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glMaterialfv_Comp)(glContext,face,pname,params);
  ((void (*)())_glMaterialfv_Exec)(glContext,face,pname,params,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                     incomingFpr8);
  return;
}

/* _glMaterialfv_Comp @ 0x3964c (284 bytes) */
int _glMaterialfv_Comp(glContext, face, pname, params)
  int glContext;
  undefined4 face;
  undefined *pname;
  undefined4 *params;
{
  undefined *puVar1;
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)((int (*)())_gleAddListItem)(glContext,PTR__glMaterialfv_ListExec_001101ec,0x18);
  if (listRecord == (undefined4 *)0x0) {
    return listRecord;
  }
  if (pname != (undefined *)0x1600) {
    if (pname < (undefined *)0x1601) {
      if (pname != ((unsigned char *)0x00001201)) {
        if (((unsigned char *)0x00001201) < pname) {
          puVar1 = ((unsigned char *)0x00001202);
        }
        else {
          puVar1 = ((unsigned char *)0x00001200);
        }
        if (pname != puVar1) goto LAB_00039740;
      }
    }
    else if (pname != (undefined *)0x1602) {
      if (pname < (undefined *)0x1602) {
        *listRecord = face;
        listRecord[1] = pname;
        listRecord[2] = *params;
        return listRecord;
      }
      if (pname == (undefined *)0x1603) {
        *listRecord = face;
        listRecord[1] = 0x1603;
        listRecord[2] = *params;
        listRecord[3] = params[1];
        listRecord[4] = params[2];
        return listRecord;
      }
LAB_00039740:
      if (*(int *)(glContext + 0x7574) != 0) {
        return listRecord;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x500;
      return listRecord;
    }
  }
  *listRecord = face;
  listRecord[1] = pname;
  listRecord[2] = *params;
  listRecord[3] = params[1];
  listRecord[4] = params[2];
  listRecord[5] = params[3];
  return listRecord;
}

/* _glDisable_CompExec @ 0x39768 (56 bytes) */
void _glDisable_CompExec(glContext, cap)
  undefined4 glContext;
  undefined4 cap;
{
  ((int (*)())_glDisable_Comp)(glContext,cap);
  _glDisable_Exec(glContext,cap);
  return;
}

/* _glDisable_Comp @ 0x397a0 (76 bytes) */
int _glDisable_Comp(glContext, cap)
  undefined4 glContext;
  undefined4 cap;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)((int (*)())_gleAddListItem)(glContext,PTR__glDisable_ListExec_001100b0,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = cap;
  }
  return listRecord;
}

/* _glColor4f_CompExec @ 0x397ec (164 bytes) */
void _glColor4f_CompExec(int glContext,float red,float green,float blue,float alpha)
{
  ((void (*)())_glColor4f_Comp)(glContext,red,green,blue,alpha);
  if (*(char *)(glContext + 0x4df8) != '\0') {
    ((void (*)())_glColor4f_ColorMat_Exec)(glContext,red,green,blue,alpha);
    return;
  }
  ((void (*)())_glColor4f_NoColorMat_Exec)(glContext,red,green,blue,alpha);
  return;
}

/* _glColor4f_Comp @ 0x39890 (92 bytes) */
void _glColor4f_Comp(undefined4 glContext,float red,float green,float blue,float alpha)
{
  float *listRecord;
  
  listRecord = (float *)((int (*)())_gleAddListItem)(glContext,PTR__glColor4_ListExec_00110058,0x10);
  if (listRecord != (float *)0x0) {
    listRecord[3] = (float)alpha;
    *listRecord = (float)red;
    listRecord[1] = (float)green;
    listRecord[2] = (float)blue;
  }
  return;
}

/* _glColor4f_NoColorMat_Exec @ 0x398ec (20 bytes) */
void _glColor4f_NoColorMat_Exec(int glContext,float red,float green,float blue,float alpha)
{
  *(float *)(glContext + 0x2ac) = (float)alpha;
  *(float *)(glContext + 0x2a0) = (float)red;
  *(float *)(glContext + 0x2a4) = (float)green;
  *(float *)(glContext + 0x2a8) = (float)blue;
  return;
}

/* _glBegin_CompExec @ 0x39900 (112 bytes) */
void _glBegin_CompExec(glContext, mode)
  int glContext;
  undefined4 mode;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    return;
  }
  ((int (*)())_glBegin_Comp)(glContext,mode);
  ((void (*)())_glBegin_Exec)(glContext,mode,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glBegin_Comp @ 0x39970 (76 bytes) */
int _glBegin_Comp(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)((int (*)())_gleAddListItem)(glContext,PTR__glBegin_ListExec_0011001c,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = mode;
  }
  return listRecord;
}

/* _gleBeginLineStripRenderTCL @ 0x399bc (60 bytes) */
void _gleBeginLineStripRenderTCL(glContext)
  int glContext;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  puVar2 = PTR__gleFlushLineStripTCLFunc_001121f8;
  puVar1 = PTR__gleRenderLineStripTCLFunc_001121f4;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = puVar2;
  *(undefined **)(glContext + 0x4a08) = puVar1;
  return;
}

/* _glVertex3d_CompExec @ 0x399f8 (96 bytes) */
void _glVertex3d_CompExec(undefined4 glContext,double x,double y,double z)
{
  ((float * (*)())_glVertex3d_Comp)(glContext,x,y,z);
  ((void (*)())_glVertex3d_Exec)(glContext,x,y,z);
  return;
}

/* _glVertex3d_Comp @ 0x39a58 (128 bytes) */
float * _glVertex3d_Comp(undefined4 glContext,double x,double y,double z)
{
  float *listRecord;
  
  listRecord = (float *)((int (*)())_gleAddListItem)(glContext,PTR__glVertex3_ListExec_00110414,0xc);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)x;
    listRecord[1] = (float)y;
    listRecord[2] = (float)z;
  }
  return listRecord;
}

/* _glVertex3d_Exec @ 0x39ad8 (52 bytes) */
void _glVertex3d_Exec(int glContext,double x,double y,double z)
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x28);
  }
                    
                    
  (*((int (*)(int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (glContext, (double)(float)x, (double)(float)y, (double)(float)z, (double)*(float *)(glContext + 0x24));
  return;
}

/* _gleSetFuncOutputDesc @ 0x39b0c (1348 bytes) */
void _gleSetFuncOutputDesc(glContext, forceOutputFlag, outputDesc)
  int glContext;
  int forceOutputFlag;
  uint *outputDesc;
{
  char glContextByte7580;
  bool hasLeadingOutput;
  uint remainingNeeds;
  undefined4 programInfo;
  int loopIndex;
  uint neededOutputs;
  uint outputMask;
  int outputCountWithLighting;
  int loopIndex2;
  int programObject;
  int streamCount;
  int loopIndex3;
  uint outputBits;
  uint streamWordCount;
  ushort texCoordStreamBase;
  ushort attribStreamBase;
  ushort *dstCursor;
  uint needBitIndex;
  uint outputMaskCandidate;
  uint programNeeds;
  uint loopIndex5;
  int outputCount;
  int streamByteOffset;
  int loopIndex4;
  longlong outputBit;
  longlong attribBit;
  
  *outputDesc = 0x204000;
  *(undefined2 *)(glContext + 0x487e) = 0x7c;
  if (*(int *)(glContext + 0x4e1c) == 0x1c00) {
    outputBits = 0x10000;
    outputCount = 1;
    if (*(char *)(glContext + 0x466c) == '\0') {
      if (*(char *)(glContext + 0x41f8) == '\0') {
        neededOutputs = *(uint *)(glContext + 0x514c);
        programNeeds = neededOutputs;
      }
      else {
        loopIndex3 = 0;
        neededOutputs = *(uint *)(glContext + 0x514c);
        programNeeds = neededOutputs;
        if (0 < *(int *)(glContext + 0x41fc)) {
          do {
            loopIndex2 = 0;
            do {
              loopIndex = 0;
              do {
                if (*(short *)((loopIndex3 * 0x10 + loopIndex2 * 6 + loopIndex) * 8 + glContext + 0x4220) == -0x7ad3
                   ) {
                  programNeeds = programNeeds | 0x200;
                  loopIndex3 = 8;
                  loopIndex2 = 2;
                  loopIndex = 4;
                }
                loopIndex = loopIndex + 1;
              } while (loopIndex < 4);
              loopIndex2 = loopIndex2 + 1;
            } while (loopIndex2 < 2);
            loopIndex3 = loopIndex3 + 1;
          } while (loopIndex3 < *(int *)(glContext + 0x41fc));
        }
        loopIndex3 = 0;
        do {
          if (*(short *)(loopIndex3 * 8 + glContext + 0x4624) == -0x7ad3) {
            programNeeds = programNeeds | 0x200;
            loopIndex3 = 7;
          }
          loopIndex3 = loopIndex3 + 1;
        } while (loopIndex3 < 7);
      }
    }
    else {
      programObject = *(int *)(glContext + 0x5424);
      if (*(short *)(programObject + 0x4c8) == -0x7e00) {
        programNeeds = *(uint *)(programObject + 0x4e8);
      }
      else {
        programObject = *(int *)(programObject + 0x4cc);
        programInfo = 0;
        if (programObject != 0) {
          programInfo = *(undefined4 *)(programObject + 0x20);
          programObject = programObject + *(int *)(programObject + 0x24) * 8;
        }
        programNeeds = _glePPSetFuncNeeds(programObject,programInfo);
      }
      neededOutputs = programNeeds & 0xff;
    }
    needBitIndex = 0;
    do {
      remainingNeeds = neededOutputs >> (needBitIndex & 0x3f);
      if ((remainingNeeds & 1) == 0) {
        if (remainingNeeds == 0) goto LAB_00039cc0;
      }
      else {
        outputCount = outputCount + 1;
        outputBit = ((longlong (*)())___ashldi3)(0,0x1000000,needBitIndex);
        outputBits = outputBits | (uint)outputBit;
      }
      needBitIndex = needBitIndex + 1;
    } while( true );
  }
  if (*(int *)(glContext + 0x4e1c) == 0x1c01) {
    outputMask = 0x1070080;
    streamCount = 5;
    if (*(char *)(glContext + 0x30aa) != '\0') {
      streamCount = 7;
      outputMask = 0x10700e0;
    }
  }
  else {
    outputMask = 0x10000;
    streamCount = 1;
  }
LAB_00039e14:
  hasLeadingOutput = (outputMask & 0x80) != 0;
  *outputDesc = *outputDesc | streamCount << 0x18;
  if (hasLeadingOutput) {
    *(undefined2 *)(outputDesc + 1) = 0xb0df;
  }
  streamWordCount = (uint)hasLeadingOutput;
  if ((outputMask & 0x10000) != 0) {
    streamByteOffset = streamWordCount * 2;
    streamWordCount = streamWordCount + 1;
    *(undefined2 *)((int)outputDesc + streamByteOffset + 4) = 0x308;
  }
  if ((outputMask & 0x20000) != 0) {
    streamByteOffset = streamWordCount * 2;
    streamWordCount = streamWordCount + 1;
    *(undefined2 *)((int)outputDesc + streamByteOffset + 4) = 0x610;
  }
  if ((outputMask & 0x40000) != 0) {
    streamByteOffset = streamWordCount * 2;
    streamWordCount = streamWordCount + 1;
    *(undefined2 *)((int)outputDesc + streamByteOffset + 4) = 0xb0c;
  }
  if ((outputMask & 0x80000) != 0) {
    streamByteOffset = streamWordCount * 2;
    streamWordCount = streamWordCount + 1;
    *(undefined2 *)((int)outputDesc + streamByteOffset + 4) = 0xc17;
  }
  if ((outputMask & 0x100000) != 0) {
    streamByteOffset = streamWordCount * 2;
    streamWordCount = streamWordCount + 1;
    *(undefined2 *)((int)outputDesc + streamByteOffset + 4) = 0x1214;
  }
  if ((outputMask & 0x200000) != 0) {
    streamByteOffset = streamWordCount * 2;
    streamWordCount = streamWordCount + 1;
    *(ushort *)((int)outputDesc + streamByteOffset + 4) = (*(byte *)(glContext + 0x4660) - 1) * 0x100 | 0x1418;
  }
  loopIndex5 = 0;
  dstCursor = (ushort *)((int)outputDesc + streamWordCount * 2 + 4);
  texCoordStreamBase = 0x2000;
  do {
    outputBit = ((longlong (*)())___ashldi3)(0,0x1000000,loopIndex5);
    if ((outputMask & (uint)outputBit) == 0) {
      if ((outputMask & -0x1000000 << (loopIndex5 & 0x3f) & 0xff000000) == 0) break;
    }
    else {
      streamWordCount = streamWordCount + 1;
      *dstCursor = texCoordStreamBase | (ushort)((int)(loopIndex5 * 0x10 + 0x80) >> 2) | 0x300;
      dstCursor = dstCursor + 1;
    }
    loopIndex5 = loopIndex5 + 1;
    texCoordStreamBase = texCoordStreamBase + 0x400;
  } while ((int)loopIndex5 < 8);
  attribStreamBase = 0xa800;
  dstCursor = (ushort *)((int)outputDesc + streamWordCount * 2 + 4);
  loopIndex4 = 0;
  do {
    attribBit = ((longlong (*)())___ashldi3)(0,0x20,loopIndex4);
    if ((outputMask & (uint)attribBit) != 0) {
      streamWordCount = streamWordCount + 1;
      *dstCursor = attribStreamBase | (ushort)(loopIndex4 * 4 + 0x74 >> 2) | 0xc0;
      dstCursor = dstCursor + 1;
    }
    loopIndex4 = loopIndex4 + 1;
    attribStreamBase = attribStreamBase + 0x400;
  } while (loopIndex4 < 2);
  if ((outputMask & 0x400000) != 0) {
    *(undefined2 *)((int)outputDesc + streamWordCount * 2 + 4) = 0x185f;
  }
  return;
LAB_00039cc0:
  if ((*(short *)(glContext + 0x3166) == -0x7baf) || ((programNeeds & 0x400) != 0)) {
    outputBits = outputBits | 0x80000;
    outputCount = outputCount + 1;
  }
  if (*(char *)(glContext + 0x4661) != '\0') {
    outputBits = outputBits | 0x200000;
    outputCount = outputCount + 1;
  }
  if (*(int *)(glContext + 0x34d0) != 0x1b021b02) {
    outputBits = outputBits | 0x400000;
    outputCount = outputCount + 1;
  }
  glContextByte7580 = *(char *)(glContext + 0x7580);
  if (glContextByte7580 == '\0') {
    outputBits = outputBits | 0x80;
    outputCount = outputCount + 1;
  }
  if (*(char *)(glContext + 0x30aa) == '\0') {
    outputMask = outputBits | 0x40000;
    streamCount = outputCount + 1;
    if (((programNeeds & 0x200) != 0) || (*(char *)(glContext + 0x4fea) != '\0')) {
      outputMask = outputBits | 0x140000;
      streamCount = outputCount + 2;
    }
    if (((*(int *)(glContext + 0x514c) == 0) || (*(char *)(glContext + 0x53e6) == '\0')) &&
       (*(char *)(glContext + 0x280c) == '\0')) goto LAB_00039e14;
    outputMask = outputMask | 0x20000;
  }
  else {
    outputMaskCandidate = outputBits | 0x20000;
    outputCountWithLighting = outputCount + 1;
    if ((*(char *)(glContext + 0x30ab) != '\0') && ((glContextByte7580 != '\0' || (forceOutputFlag != 0)))) {
      outputMaskCandidate = outputBits | 0x60000;
      outputCountWithLighting = outputCount + 2;
    }
    outputMask = outputMaskCandidate;
    streamCount = outputCountWithLighting;
    if (glContextByte7580 == '\0') {
      outputMask = outputMaskCandidate | 0x20;
      streamCount = outputCountWithLighting + 1;
      if (*(char *)(glContext + 0x30ac) != '\0') {
        outputMask = outputMaskCandidate | 0x60;
        streamCount = outputCountWithLighting + 2;
      }
    }
    if ((programNeeds & 0x200) == 0) goto LAB_00039e14;
    outputMask = outputMask | 0x100000;
  }
  streamCount = streamCount + 1;
  goto LAB_00039e14;
}

/* ___ashldi3 @ 0x3a050 (96 bytes) */
longlong ___ashldi3(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  uint uVar1;
  undefined4 local_2c;
  
  if (param_3 == 0) {
    return CONCAT44(param_1,param_2);
  }
  uVar1 = 0x20 - param_3;
  if ((int)uVar1 < 1) {
    uVar1 = param_2 << (-uVar1 & 0x3f);
    local_2c = 0;
  }
  else {
    local_2c = param_2 << (param_3 & 0x3f);
    uVar1 = param_1 << (param_3 & 0x3f) | param_2 >> (uVar1 & 0x3f);
  }
  return CONCAT44(uVar1,local_2c);
}

/* _glEnd_CompExec @ 0x3a0b0 (48 bytes) */
void _glEnd_CompExec(glContext)
  undefined4 glContext;
{
  ((int (*)())_glEnd_Comp)(glContext);
  ((double (*)())_glEnd_Exec)(glContext);
  return;
}

/* _glEnd_Comp @ 0x3a0e0 (32 bytes) */
int _glEnd_Comp(glContext)
  undefined4 glContext;
{
  undefined4 listRecord;
  
  listRecord = ((int (*)())_gleAddListItem)(glContext,PTR__glEnd_ListExec_001100b8,0);
  return listRecord;
}

/* _glEnd_Exec @ 0x3a100 (128 bytes) */
double _glEnd_Exec(glContext)
  int glContext;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    return;
  }
  *(undefined2 *)(glContext + 0x4a10) = 0xffff;
  *(undefined4 *)(glContext + 0x4884) = *(undefined4 *)(glContext + 0xd8);
  (**(code **)(glContext + 0x4a08))(glContext);
  ((int (*)())_glePopAndCopyMaterials)(glContext);
  return;
}

/* _glePopAndCopyMaterials @ 0x3a1b0 (152 bytes) */
int _glePopAndCopyMaterials(glContext)
  int glContext;
{
  int glContextPtr4dd8;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = glContext + 0x2c20;
  iVar4 = glContext;
  do {
    iVar2 = *(int *)(iVar4 + 0x4dd0);
    if (*(int *)(iVar2 + 0x23c) != 0) {
      glContextPtr4dd8 = *(int *)(glContext + 0x4dd8);
      iVar3 = *(int *)(iVar5 + 0x238);
      *(int *)(iVar3 + 0x23c) = glContextPtr4dd8;
      if (glContextPtr4dd8 != 0) {
        *(int *)(glContextPtr4dd8 + 0x238) = iVar3;
      }
      *(int *)(glContext + 0x4dd8) = iVar2;
      *(int *)(iVar4 + 0x4dd0) = iVar5;
      _memcpy(iVar5,iVar2,0x240);
      *(undefined4 *)(iVar5 + 0x23c) = 0;
      iVar2 = iVar5;
    }
    iVar4 = iVar4 + 4;
    *(undefined1 *)(iVar2 + 0x236) = 0;
    *(undefined4 *)(iVar2 + 0x1e0) = 0;
    *(undefined1 *)(iVar2 + 0x235) = 0;
    iVar5 = iVar5 + 0x240;
  } while (iVar4 <= glContext + 4);
  return;
}

/* _glLineWidth_CompExec @ 0x3a248 (64 bytes) */
void _glLineWidth_CompExec(undefined4 glContext,float width)
{
  ((float * (*)())_glLineWidth_Comp)(glContext,width);
  ((void (*)())_glLineWidth_Exec)(glContext,width);
  return;
}

/* _glLineWidth_Comp @ 0x3a288 (84 bytes) */
float * _glLineWidth_Comp(undefined4 glContext,float width)
{
  float *listRecord;
  
  listRecord = (float *)((int (*)())_gleAddListItem)(glContext,PTR__glLineWidth_ListExec_00110158,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)width;
  }
  return listRecord;
}

/* _glLineWidth_Exec @ 0x3a2dc (112 bytes) */
void _glLineWidth_Exec(int glContext,float width)
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (!(width <= (double)FLOAT_00108e50)) {
      *(float *)(glContext + 0x3180) = (float)width;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x4000;
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

/* _glClear_CompExec @ 0x3a34c (56 bytes) */
void _glClear_CompExec(glContext, mask)
  undefined4 glContext;
  undefined4 mask;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glClear_Comp)(glContext,mask);
  ((void (*)())_glClear_Exec)(glContext,mask,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glClear_Comp @ 0x3a384 (76 bytes) */
int _glClear_Comp(glContext, mask)
  undefined4 glContext;
  undefined4 mask;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)((int (*)())_gleAddListItem)(glContext,PTR__glClear_ListExec_00110038,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = mask;
  }
  return listRecord;
}

/* _gleSetEnable_STENCIL_TEST @ 0x3a3d0 (56 bytes) */
void _gleSetEnable_STENCIL_TEST(glContext, unusedArg2, enable)
  int glContext;
  undefined4 unusedArg2;
  int enable;
{
  uint faceShift;
  uint newEnableBits;
  
  faceShift = *(byte *)(glContext + 0x7583) & 0x1f;
  newEnableBits = *(uint *)(glContext + 0x3520) & (-2 << faceShift | 0xfffffffeU >> 0x20 - faceShift) |
          enable << (*(byte *)(glContext + 0x7583) & 0x3f);
  if (*(uint *)(glContext + 0x3520) == newEnableBits) {
    return;
  }
  *(uint *)(glContext + 0x3520) = newEnableBits;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x10000000;
  return;
}

/* _glStencilFunc_CompExec @ 0x3a408 (72 bytes) */
void _glStencilFunc_CompExec(glContext, func, ref, mask)
  undefined4 glContext;
  undefined4 func;
  undefined4 ref;
  undefined4 mask;
{
  ((int (*)())_glStencilFunc_Comp)(glContext,func,ref,mask);
  ((void (*)())_glStencilFunc_Exec)(glContext,func,ref,mask);
  return;
}

/* _glStencilFunc_Comp @ 0x3a450 (92 bytes) */
int _glStencilFunc_Comp(glContext, func, ref, mask)
  undefined4 glContext;
  undefined4 func;
  undefined4 ref;
  undefined4 mask;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)((int (*)())_gleAddListItem)(glContext,PTR__glStencilFunc_ListExec_0011031c,0xc);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[2] = mask;
    *listRecord = func;
    listRecord[1] = ref;
  }
  return listRecord;
}

/* _glStencilFunc_Exec @ 0x3a4ac (164 bytes) */
void _glStencilFunc_Exec(glContext, func, ref, mask)
  int glContext;
  int func;
  uint ref;
  undefined4 mask;
{
  undefined4 glErrorCode;
  uint uVar2;
  int iVar3;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (func - 0x200U < 8) {
      if ((int)ref < 0) {
        ref = 0;
      }
      else {
        uVar2 = 0xffffffff >> (0x20U - *(int *)(*(int *)(glContext + 0x468c) + 0x40) & 0x3f);
        if (uVar2 < ref) {
          ref = uVar2;
        }
      }
      iVar3 = (uint)*(byte *)(glContext + 0x7583) * 0x10 + glContext;
      *(undefined4 *)(iVar3 + 0x34f8) = mask;
      *(uint *)(iVar3 + 0x34fc) = ref;
      *(short *)(iVar3 + 0x3500) = (short)func;
      *(short *)(glContext + 0x3518) = (short)func;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x10000000;
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

/* _glStencilOp_CompExec @ 0x3a550 (72 bytes) */
void _glStencilOp_CompExec(glContext, fail, zfail, zpass)
  undefined4 glContext;
  undefined4 fail;
  undefined4 zfail;
  undefined4 zpass;
{
  ((int (*)())_glStencilOp_Comp)(glContext,fail,zfail,zpass);
  ((void (*)())_glStencilOp_Exec)(glContext,fail,zfail,zpass);
  return;
}

/* _glStencilOp_Comp @ 0x3a598 (92 bytes) */
int _glStencilOp_Comp(glContext, fail, zfail, zpass)
  undefined4 glContext;
  undefined4 fail;
  undefined4 zfail;
  undefined4 zpass;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)((int (*)())_gleAddListItem)(glContext,PTR__glStencilOp_ListExec_00110318,0xc);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[2] = zpass;
    *listRecord = fail;
    listRecord[1] = zfail;
  }
  return listRecord;
}

/* _glStencilOp_Exec @ 0x3a5f4 (268 bytes) */
void _glStencilOp_Exec(glContext, fail, zfail, zpass)
  int glContext;
  uint fail;
  uint zfail;
  uint zpass;
{
  undefined4 glErrorCode;
  int iVar2;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0003a658;
  }
  if (fail < 0x1e04) {
    if (((0x1dff < fail) || (fail == 0)) || (fail == 0x150a)) {
LAB_0003a660:
      if (zfail < 0x1e04) {
        if (((0x1dff < zfail) || (zfail == 0)) || (zfail == 0x150a)) {
LAB_0003a694:
          if (zpass < 0x1e04) {
            if (((0x1dff < zpass) || (zpass == 0)) || (zpass == 0x150a)) {
LAB_0003a6c8:
              iVar2 = (uint)*(byte *)(glContext + 0x7583) * 0x10 + glContext;
              *(short *)(iVar2 + 0x3506) = (short)zpass;
              *(short *)(iVar2 + 0x3502) = (short)fail;
              *(short *)(iVar2 + 0x3504) = (short)zfail;
              *(short *)(glContext + 0x351a) = (short)fail;
              *(short *)(glContext + 0x351c) = (short)zfail;
              *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x10000000;
              *(short *)(glContext + 0x351e) = (short)zpass;
              return;
            }
          }
          else if (zpass - 0x8507 < 2) goto LAB_0003a6c8;
        }
      }
      else if (zfail - 0x8507 < 2) goto LAB_0003a694;
    }
  }
  else if (fail - 0x8507 < 2) goto LAB_0003a660;
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_0003a658:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glColorMask_CompExec @ 0x3a700 (80 bytes) */
void _glColorMask_CompExec(glContext, red, green, blue, alpha)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 alpha;
{
  ((int (*)())_glColorMask_Comp)(glContext,red,green,blue,alpha);
  _glColorMask_Exec(glContext,red,green,blue,alpha);
  return;
}

/* _glColorMask_Comp @ 0x3a750 (100 bytes) */
int _glColorMask_Comp(glContext, red, green, blue, alpha)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
  undefined4 alpha;
{
  undefined1 *listRecord;
  
  listRecord = (undefined1 *)((int (*)())_gleAddListItem)(glContext,PTR__glColorMask_ListExec_001101dc,4);
  if (listRecord != (undefined1 *)0x0) {
    listRecord[3] = (undefined1)alpha;
    *listRecord = (undefined1)red;
    listRecord[1] = (undefined1)green;
    listRecord[2] = (undefined1)blue;
  }
  return listRecord;
}

/* _glDepthMask_CompExec @ 0x3a7b4 (56 bytes) */
void _glDepthMask_CompExec(glContext, flag)
  undefined4 glContext;
  undefined4 flag;
{
  ((int (*)())_glDepthMask_Comp)(glContext,flag);
  _glDepthMask_Exec(glContext,flag);
  return;
}

/* _glDepthMask_Comp @ 0x3a7ec (76 bytes) */
int _glDepthMask_Comp(glContext, flag)
  undefined4 glContext;
  undefined4 flag;
{
  undefined1 *listRecord;
  
  listRecord = (undefined1 *)((int (*)())_gleAddListItem)(glContext,PTR__glDepthMask_ListExec_001101d8,4);
  if (listRecord != (undefined1 *)0x0) {
    *listRecord = (undefined1)flag;
  }
  return listRecord;
}

/* _gleBeginQuadsRenderTCL @ 0x3a838 (52 bytes) */
void _gleBeginQuadsRenderTCL(glContext)
  int glContext;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushAtomicTCLFunc_00112218;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = puVar1;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderQuadsTCLFunc_00112280;
  return;
}

/* _glNormal3f_CompExec @ 0x3a86c (96 bytes) */
void _glNormal3f_CompExec(undefined4 glContext,float nx,float ny,float nz)
{
  ((float * (*)())_glNormal3f_Comp)(glContext,nx,ny,nz);
  ((void (*)())_glNormal3f_Exec)(glContext,nx,ny,nz);
  return;
}

