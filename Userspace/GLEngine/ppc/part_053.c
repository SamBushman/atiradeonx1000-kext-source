#include "decls.h"

/* _gleBeginRSLNoop @ 0xf34d4 (44 bytes) */
void _gleBeginRSLNoop(glContext)
  int glContext;
{
  undefined *flushNoop;
  
  flushNoop = PTR__gleFlushNoop_001113e4;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderNoop_001113e0;
  *(undefined **)(glContext + 0x4a0c) = flushNoop;
  return;
}

/* _gleFlushPrimitiveTCLRDirtyFunc @ 0xf3500 (856 bytes) */
void _gleFlushPrimitiveTCLRDirtyFunc(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined8 local_220 [64];
  int local_20 [5];
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
    (**(code **)(glContext + 0x4a0c))(glContext);
    return;
  }
  iVar5 = (int)*(short *)(glContext + 0x487c);
  switch(*(undefined2 *)(glContext + 0x4a10)) {
  case 2:
    if (*(char *)(glContext + 0x4a18) == '\0') {
      iVar4 = 0;
      iVar2 = *(int *)(glContext + 0x4854);
      iVar1 = *(int *)(glContext + 0x4868);
      if (0 < iVar5) {
        uVar6 = iVar5 + 7U >> 3;
        do {
          *(undefined8 *)(iVar2 + -0x100 + iVar4) = *(undefined8 *)(iVar1 + iVar4);
          iVar4 = iVar4 + 8;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
    }
  case 3:
    iVar2 = 0;
    iVar1 = *(int *)(glContext + 0x4858);
    *(undefined1 *)(glContext + 0x4a18) = 1;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + iVar2) = *(undefined8 *)((iVar1 - iVar5) + iVar2);
        iVar2 = iVar2 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 5:
  case 8:
    iVar2 = iVar5 * 2;
    iVar4 = 0;
    iVar3 = *(int *)(glContext + 0x4858);
    iVar1 = iVar5 * -2;
    iVar5 = iVar2;
    if (0 < iVar2) {
      uVar6 = iVar2 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + iVar4) = *(undefined8 *)(iVar3 + iVar1 + iVar4);
        iVar4 = iVar4 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 6:
    iVar2 = 0;
    iVar4 = *(int *)(glContext + 0x4858);
    iVar1 = *(int *)(glContext + 0x4868);
    if (0 < iVar5) {
      do {
        *(undefined8 *)((int)local_220 + iVar2) = *(undefined8 *)(iVar1 + iVar2);
        iVar2 = iVar2 + 8;
      } while (iVar2 < iVar5);
    }
    iVar2 = 0;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + iVar2 + iVar5) = *(undefined8 *)((iVar4 - iVar5) + iVar2);
        iVar2 = iVar2 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 9:
    iVar2 = 0;
    iVar4 = *(int *)(glContext + 0x4858);
    iVar1 = *(int *)(glContext + 0x4868);
    if (0 < iVar5) {
      do {
        *(undefined8 *)((int)local_220 + iVar2) = *(undefined8 *)(iVar1 + iVar2);
        iVar2 = iVar2 + 8;
      } while (iVar2 < iVar5);
    }
    iVar2 = 0;
    iVar4 = iVar4 - iVar5;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)local_220 + iVar2 + iVar5) = *(undefined8 *)(iVar4 + iVar2);
        iVar2 = iVar2 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
      *(undefined1 *)(iVar4 + *(short *)(glContext + 0x487e)) = 0;
    }
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  local_20[0] = *(int *)(glContext + 0x4a14);
  iVar2 = (**(code **)(glContext + 0x46e8))
                    (*(undefined4 *)(glContext + 0x4688),(int)*(short *)(glContext + 0x4a10),local_20);
  *(int *)(glContext + 0x4868) = iVar2;
  *(int *)(glContext + 0x485c) = iVar2 + *(short *)(glContext + 0x487c) * local_20[0];
  switch(*(undefined2 *)(glContext + 0x4a10)) {
  default:
    goto switchD_000f37d0_caseD_0;
  case 2:
  case 3:
    iVar1 = 0;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)(iVar2 + iVar1) = *(undefined8 *)((int)local_220 + iVar1);
        iVar1 = iVar1 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 9:
    if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
      *(undefined1 *)((int)local_220 + (int)*(short *)(glContext + 0x487e)) = 0;
    }
  case 6:
    iVar5 = iVar5 << 1;
  case 5:
  case 8:
    iVar1 = 0;
    if (0 < iVar5) {
      uVar6 = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)(iVar2 + iVar1) = *(undefined8 *)((int)local_220 + iVar1);
        iVar1 = iVar1 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
  }
  iVar2 = iVar2 + iVar5;
switchD_000f37d0_caseD_0:
  *(int *)(glContext + 0x4858) = iVar2;
  *(undefined4 *)(glContext + 0x486c) = 0;
  return;
}

/* _gleBeginPrimitiveTCLRDirtyFunc @ 0xf38a8 (176 bytes) */
void _gleBeginPrimitiveTCLRDirtyFunc(glContext)
  int glContext;
{
  short sVar1;
  undefined *renderPrimitiveTCLFunc;
  int iVar3;
  int local_20 [5];
  
  local_20[0] = *(int *)(glContext + 0x4a14);
  *(undefined1 *)(glContext + 0x4a18) = 0;
  if (local_20[0] == 0) {
    sVar1 = *(short *)(glContext + 0x4880);
  }
  else {
    sVar1 = *(short *)(glContext + 0x4882);
  }
  iVar3 = (**(code **)(glContext + 0x46e8))
                    (*(undefined4 *)(glContext + 0x4688),(int)*(short *)(glContext + 0x4a10),local_20);
  *(undefined4 *)(glContext + 0x486c) = 0;
  renderPrimitiveTCLFunc = PTR__gleRenderPrimitiveTCLFunc_001113cc;
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushPrimitiveTCLRDirtyFunc_001113c8;
  *(int *)(glContext + 0x485c) = iVar3 + sVar1 * local_20[0];
  *(undefined **)(glContext + 0x4a08) = renderPrimitiveTCLFunc;
  *(undefined2 *)(glContext + 0x4a12) = *(undefined2 *)(glContext + 0x4a10);
  *(short *)(glContext + 0x487c) = sVar1;
  *(int *)(glContext + 0x4868) = iVar3;
  *(int *)(glContext + 0x4858) = iVar3;
  return;
}

/* _gleUpdateScissorData @ 0xf3958 (44 bytes) */
void _gleUpdateScissorData(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x3188) < 0) {
    *(undefined4 *)(param_1 + 0x3188) = 0;
  }
  if (-1 < *(int *)(param_1 + 0x318c)) {
    return;
  }
  *(undefined4 *)(param_1 + 0x318c) = 0;
  return;
}

/* _gleSelectHit @ 0xf3984 (8 bytes) */
double _gleSelectHit(glContext, param_2)
  undefined4 glContext;
  int param_2;
{
  ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(param_2 + 8));
  return;
}

/* _gleSelectHitRecord @ 0xf398c (340 bytes) */
void _gleSelectHitRecord(int glContext,double floatArg1)
{
  uint depthValue;
  uint copiedWord;
  uint *selectCursor;
  uint *hitRecord;
  uint *selectBufferEnd;
  uint *nameCountSlot;
  uint *nameStackCursor;
  double scaledDepth;
  
  if (*(char *)(glContext + 0x4fc9) != '\0') {
    return;
  }
  scaledDepth = floatArg1 * DOUBLE_00108da8;
  selectCursor = *(uint **)(glContext + 0x4e24);
  selectBufferEnd = (uint *)(*(int *)(glContext + 20000) + *(int *)(glContext + 0x4e28) * 4);
  if (DOUBLE_00108d80 <= scaledDepth) {
    depthValue = (int)(scaledDepth - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    depthValue = (uint)(int)scaledDepth;
  }
  if (*(char *)(glContext + 0x4fc8) != '\0') {
    hitRecord = *(uint **)(glContext + 0x4fc0);
    if (depthValue < *hitRecord) {
      *hitRecord = depthValue;
      hitRecord = *(uint **)(glContext + 0x4fc0);
    }
    if (depthValue <= hitRecord[1]) {
      return;
    }
    hitRecord[1] = depthValue;
    return;
  }
  *(undefined1 *)(glContext + 0x4fc8) = 1;
  if (selectCursor != selectBufferEnd) {
    *selectCursor = (*(int *)(glContext + 0x4fbc) - glContext) + -0x4e2c >> 2;
    nameCountSlot = selectCursor + 1;
    *(int *)(glContext + 0x4fc4) = *(int *)(glContext + 0x4fc4) + 1;
    if (nameCountSlot != selectBufferEnd) {
      *(uint **)(glContext + 0x4fc0) = nameCountSlot;
      *nameCountSlot = depthValue;
      if (selectCursor + 2 != selectBufferEnd) {
        selectCursor[2] = depthValue;
        nameStackCursor = (uint *)(glContext + 0x4e2c);
        selectCursor = selectCursor + 3;
        if (nameStackCursor < *(uint **)(glContext + 0x4fbc)) {
          do {
            if (selectCursor == selectBufferEnd) goto LAB_000f3a4c;
            copiedWord = *nameStackCursor;
            nameStackCursor = nameStackCursor + 1;
            *selectCursor = copiedWord;
            selectCursor = selectCursor + 1;
          } while (nameStackCursor < *(uint **)(glContext + 0x4fbc));
        }
        *(uint **)(glContext + 0x4e24) = selectCursor;
        return;
      }
    }
  }
LAB_000f3a4c:
  *(uint **)(glContext + 0x4e24) = selectBufferEnd;
  *(undefined1 *)(glContext + 0x4fc9) = 1;
  return;
}

/* _gleSelectPoints @ 0xf3ae0 (84 bytes) */
void _gleSelectPoints(glContext, param_2, param_3)
  undefined4 glContext;
  uint param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = param_2 + param_3 * 0x100;
  for (; param_2 < uVar1; param_2 = param_2 + 0x100) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(param_2 + 8));
  }
  return;
}

/* _gleSelectPointsPtr @ 0xf3b34 (88 bytes) */
void _gleSelectPointsPtr(glContext, param_2, param_3)
  undefined4 glContext;
  int *param_2;
  int param_3;
{
  int *piVar1;
  
  piVar1 = param_2 + param_3;
  for (; param_2 < piVar1; param_2 = param_2 + 1) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(*param_2 + 8));
  }
  return;
}

/* _gleSelectLines @ 0xf3b8c (100 bytes) */
void _gleSelectLines(glContext, param_2, param_3)
  undefined4 glContext;
  uint param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = param_2 + param_3 * 0x100;
  for (; param_2 < iVar1 - 0x100U; param_2 = param_2 + 0x200) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(param_2 + 8));
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(param_2 + 0x108));
  }
  return;
}

/* _gleSelectLineStrip @ 0xf3bf0 (100 bytes) */
void _gleSelectLineStrip(glContext, param_2, param_3)
  undefined4 glContext;
  uint param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = param_2 + param_3 * 0x100;
  for (; param_2 < iVar1 - 0x100U; param_2 = param_2 + 0x100) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(param_2 + 8));
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(param_2 + 0x108));
  }
  return;
}

/* _gleSelectLineLoop_body @ 0xf3c60 (112 bytes) */
void _gleSelectLineLoop_body(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  uint uVar1;
  
  for (uVar1 = param_2; uVar1 < param_3 - 0x100U; uVar1 = uVar1 + 0x100) {
    ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(uVar1 + 8));
    ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(uVar1 + 0x108));
  }
  ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(uVar1 + 8));
  ((void (*)())_gleSelectHitRecord)(param_1,(double)*(float *)(param_2 + 8));
  return;
}

/* _gleSelectLinesPtr @ 0xf3cd0 (108 bytes) */
void _gleSelectLinesPtr(glContext, param_2, param_3)
  undefined4 glContext;
  int *param_2;
  int param_3;
{
  int *piVar1;
  
  piVar1 = param_2 + param_3 + -1;
  for (; param_2 < piVar1; param_2 = param_2 + 2) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(*param_2 + 8));
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(param_2[1] + 8));
  }
  return;
}

/* _gleSelectPolygon @ 0xf3d3c (84 bytes) */
void _gleSelectPolygon(glContext, param_2, param_3)
  undefined4 glContext;
  uint param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = param_2 + param_3 * 0x100;
  for (; param_2 < uVar1; param_2 = param_2 + 0x100) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(param_2 + 8));
  }
  return;
}

/* _gleSelectPolygonPtr @ 0xf3d90 (88 bytes) */
double _gleSelectPolygonPtr(glContext, param_2, param_3)
  undefined4 glContext;
  int *param_2;
  int param_3;
{
  int *piVar1;
  
  piVar1 = param_2 + param_3;
  for (; param_2 < piVar1; param_2 = param_2 + 1) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(*param_2 + 8));
  }
  return;
}

/* _gleSelectTriangles @ 0xf3de8 (116 bytes) */
double _gleSelectTriangles(glContext, param_2, param_3)
  undefined4 glContext;
  uint param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (-1 < param_3 + -3) {
    do {
      for (uVar2 = param_2; uVar2 < param_2 + 0x300; uVar2 = uVar2 + 0x100) {
        ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(uVar2 + 8));
      }
      iVar1 = iVar1 + 3;
      param_2 = param_2 + 0x300;
    } while (iVar1 <= param_3 + -3);
  }
  return;
}

/* _gleSelectTriangleFan @ 0xf3e5c (124 bytes) */
double _gleSelectTriangleFan(glContext, param_2, param_3, param_4)
  undefined4 glContext;
  int param_2;
  uint param_3;
  int param_4;
{
  int iVar1;
  uint uVar2;
  
  if (-1 < param_4 + -2) {
    iVar1 = param_4 + -1;
    do {
      ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(param_2 + 8));
      for (uVar2 = param_3; uVar2 < param_3 + 0x200; uVar2 = uVar2 + 0x100) {
        ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(uVar2 + 8));
      }
      iVar1 = iVar1 + -1;
      param_3 = param_3 + 0x100;
    } while (iVar1 != 0);
  }
  return;
}

/* _gleSelectTriangleStrip @ 0xf3ed8 (108 bytes) */
double _gleSelectTriangleStrip(glContext, param_2, param_3)
  undefined4 glContext;
  uint param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  
  if (-1 < param_3 + -3) {
    iVar1 = param_3 + -2;
    do {
      for (uVar2 = param_2; uVar2 < param_2 + 0x300; uVar2 = uVar2 + 0x100) {
        ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(uVar2 + 8));
      }
      iVar1 = iVar1 + -1;
      param_2 = param_2 + 0x100;
    } while (iVar1 != 0);
  }
  return;
}

/* _gleSelectQuads @ 0xf3f44 (116 bytes) */
double _gleSelectQuads(glContext, param_2, param_3)
  undefined4 glContext;
  uint param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (-1 < param_3 + -4) {
    do {
      for (uVar2 = param_2; uVar2 < param_2 + 0x400; uVar2 = uVar2 + 0x100) {
        ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(uVar2 + 8));
      }
      iVar1 = iVar1 + 4;
      param_2 = param_2 + 0x400;
    } while (iVar1 <= param_3 + -4);
  }
  return;
}

/* _gleSelectQuadStrip @ 0xf3fb8 (116 bytes) */
double _gleSelectQuadStrip(glContext, param_2, param_3)
  undefined4 glContext;
  uint param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (-1 < param_3 + -4) {
    do {
      for (uVar2 = param_2; uVar2 < param_2 + 0x400; uVar2 = uVar2 + 0x100) {
        ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(uVar2 + 8));
      }
      iVar1 = iVar1 + 2;
      param_2 = param_2 + 0x200;
    } while (iVar1 <= param_3 + -4);
  }
  return;
}

/* _gleDetachShaderObjectIterFunc @ 0xf402c (180 bytes) */
void _gleDetachShaderObjectIterFunc(unusedArg1, objectRecord)
  undefined4 unusedArg1;
  int objectRecord;
{
  int attachedCount;
  int *attachedObjects;
  int attachedObject;
  int loopIndex;
  int *attachedCursor;
  
  if (*(int *)(objectRecord + 0x10) == 0x8b40) {
    attachedCount = *(int *)(objectRecord + 0x48);
    loopIndex = 0;
    if (attachedCount < 1) {
      attachedObjects = *(int **)(objectRecord + 0x44);
    }
    else {
      attachedObjects = *(int **)(objectRecord + 0x44);
      attachedCursor = attachedObjects;
      do {
        attachedObject = *attachedCursor;
        if (attachedObject != 0) {
          *(int *)(attachedObject + 8) = *(int *)(attachedObject + 8) + -1;
        }
        loopIndex = loopIndex + 1;
        attachedCursor = attachedCursor + 1;
      } while (loopIndex < attachedCount);
    }
    if (attachedObjects != (int *)0x0) {
      _free(attachedObjects);
    }
    *(undefined4 *)(objectRecord + 0x48) = 0;
    *(undefined4 *)(objectRecord + 0x44) = 0;
  }
  if (*(char *)(objectRecord + 0x14) == '\0') {
    *(int *)(objectRecord + 8) = *(int *)(objectRecord + 8) + -1;
  }
  return;
}

/* _gleFreeShaderObject @ 0xf40e0 (868 bytes) */
void _gleFreeShaderObject(glContext, shaderObject)
  int glContext;
  int shaderObject;
{
  int *rendererDispatch;
  undefined4 *rendererContextPtr;
  int freeTargetOrLoopIndex;
  int refCountMinusOne;
  int subObjectOrCount;
  int attachedListOrByteOffset;
  int attachedObject;
  
  if (*(int *)(shaderObject + 0x10) == 0x8b40) {
    if (*(int *)(shaderObject + 0x18) != 0) {
      _free(*(int *)(shaderObject + 0x18));
    }
    subObjectOrCount = *(int *)(shaderObject + 0x20);
    if (*(int *)(subObjectOrCount + 0x518) != 0) {
      freeTargetOrLoopIndex = *(int *)(*(int *)(subObjectOrCount + 0x518) + 0x20);
      if (freeTargetOrLoopIndex != 0) {
        _gleVecFree(freeTargetOrLoopIndex);
        subObjectOrCount = *(int *)(shaderObject + 0x20);
      }
      freeTargetOrLoopIndex = *(int *)(*(int *)(subObjectOrCount + 0x518) + 8);
      if (freeTargetOrLoopIndex != 0) {
        _gleVecFree(freeTargetOrLoopIndex);
        subObjectOrCount = *(int *)(shaderObject + 0x20);
      }
      freeTargetOrLoopIndex = *(int *)(*(int *)(subObjectOrCount + 0x518) + 0xc);
      if (freeTargetOrLoopIndex != 0) {
        _gleVecFree(freeTargetOrLoopIndex);
        subObjectOrCount = *(int *)(shaderObject + 0x20);
      }
      freeTargetOrLoopIndex = *(int *)(*(int *)(subObjectOrCount + 0x518) + 0x18);
      if (freeTargetOrLoopIndex != 0) {
        _gleVecFree(freeTargetOrLoopIndex);
        subObjectOrCount = *(int *)(shaderObject + 0x20);
      }
      freeTargetOrLoopIndex = *(int *)(*(int *)(subObjectOrCount + 0x518) + 0x1c);
      if (freeTargetOrLoopIndex != 0) {
        _gleVecFree(freeTargetOrLoopIndex);
        subObjectOrCount = *(int *)(shaderObject + 0x20);
      }
      _gleVecFree(*(undefined4 *)(subObjectOrCount + 0x518));
    }
    subObjectOrCount = *(int *)(shaderObject + 0x24);
    if (*(int *)(subObjectOrCount + 0x518) != 0) {
      freeTargetOrLoopIndex = *(int *)(*(int *)(subObjectOrCount + 0x518) + 0x20);
      if (freeTargetOrLoopIndex != 0) {
        _gleVecFree(freeTargetOrLoopIndex);
        subObjectOrCount = *(int *)(shaderObject + 0x24);
      }
      freeTargetOrLoopIndex = *(int *)(*(int *)(subObjectOrCount + 0x518) + 8);
      if (freeTargetOrLoopIndex != 0) {
        _gleVecFree(freeTargetOrLoopIndex);
        subObjectOrCount = *(int *)(shaderObject + 0x24);
      }
      freeTargetOrLoopIndex = *(int *)(*(int *)(subObjectOrCount + 0x518) + 0xc);
      if (freeTargetOrLoopIndex != 0) {
        _gleVecFree(freeTargetOrLoopIndex);
        subObjectOrCount = *(int *)(shaderObject + 0x24);
      }
      freeTargetOrLoopIndex = *(int *)(*(int *)(subObjectOrCount + 0x518) + 0x18);
      if (freeTargetOrLoopIndex != 0) {
        _gleVecFree(freeTargetOrLoopIndex);
        subObjectOrCount = *(int *)(shaderObject + 0x24);
      }
      freeTargetOrLoopIndex = *(int *)(*(int *)(subObjectOrCount + 0x518) + 0x1c);
      if (freeTargetOrLoopIndex != 0) {
        _gleVecFree(freeTargetOrLoopIndex);
        subObjectOrCount = *(int *)(shaderObject + 0x24);
      }
      _gleVecFree(*(undefined4 *)(subObjectOrCount + 0x518));
    }
    subObjectOrCount = *(int *)(shaderObject + 0x20);
    if (*(int *)(subObjectOrCount + 0x4dc) != 0) {
      _PPEmulatorProgramFree(*(int *)(subObjectOrCount + 0x4dc));
      subObjectOrCount = *(int *)(shaderObject + 0x20);
    }
    if (*(int *)(subObjectOrCount + 0x508) != 0) {
      _gleVecFree(*(int *)(subObjectOrCount + 0x508));
    }
    subObjectOrCount = *(int *)(*(int *)(shaderObject + 0x24) + 0x508);
    if (subObjectOrCount != 0) {
      _gleVecFree(subObjectOrCount);
    }
    subObjectOrCount = *(int *)(*(int *)(shaderObject + 0x20) + 0x51c);
    if (subObjectOrCount != 0) {
      _gleVecFree(subObjectOrCount);
    }
    subObjectOrCount = *(int *)(*(int *)(shaderObject + 0x24) + 0x51c);
    if (subObjectOrCount != 0) {
      _gleVecFree(subObjectOrCount);
    }
    subObjectOrCount = *(int *)(shaderObject + 0x48);
    freeTargetOrLoopIndex = 0;
    if (subObjectOrCount < 1) {
      attachedListOrByteOffset = *(int *)(shaderObject + 0x44);
    }
    else {
      attachedListOrByteOffset = *(int *)(shaderObject + 0x44);
      do {
        attachedObject = *(int *)(freeTargetOrLoopIndex * 4 + attachedListOrByteOffset);
        if ((attachedObject != 0) &&
           (refCountMinusOne = *(int *)(attachedObject + 8) + -1, *(int *)(attachedObject + 8) = refCountMinusOne, refCountMinusOne == 1)) {
          _gleDeleteHashNameAndObject
                    (glContext,*(int *)(glContext + 0x5148) + 0x6018,*(undefined4 *)(attachedObject + 4));
          subObjectOrCount = *(int *)(shaderObject + 0x48);
          attachedListOrByteOffset = *(int *)(shaderObject + 0x44);
        }
        freeTargetOrLoopIndex = freeTargetOrLoopIndex + 1;
      } while (freeTargetOrLoopIndex < subObjectOrCount);
    }
    if (attachedListOrByteOffset != 0) {
      _free(attachedListOrByteOffset);
    }
    if (*(int *)(shaderObject + 0x40) != 0) {
      _ShDestruct(*(int *)(shaderObject + 0x40));
    }
    subObjectOrCount = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      freeTargetOrLoopIndex = glContext + 0x85a0;
      do {
        attachedListOrByteOffset = subObjectOrCount * 4;
        subObjectOrCount = subObjectOrCount + 1;
        (**(code **)(*(int *)(freeTargetOrLoopIndex + 0x2e4) + 0x1a0))
                  (*(undefined4 *)(freeTargetOrLoopIndex + 0xc),
                   *(undefined4 *)(attachedListOrByteOffset + *(int *)(shaderObject + 0x20) + 0x4e4));
        rendererDispatch = (int *)(freeTargetOrLoopIndex + 0x2e4);
        rendererContextPtr = (undefined4 *)(freeTargetOrLoopIndex + 0xc);
        freeTargetOrLoopIndex = freeTargetOrLoopIndex + 0x2e0;
        (**(code **)(*rendererDispatch + 0x1a0))
                  (*rendererContextPtr,*(undefined4 *)(attachedListOrByteOffset + *(int *)(shaderObject + 0x24) + 0x4e4));
      } while (subObjectOrCount < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
    if (*(int *)(shaderObject + 0x20) != 0) {
      _gleVecFree(*(int *)(shaderObject + 0x20));
    }
    if (*(int *)(shaderObject + 0x24) != 0) {
      _gleVecFree(*(int *)(shaderObject + 0x24));
    }
    if (*(int *)(shaderObject + 0x4c) != 0) {
      _gleVecFree(*(int *)(shaderObject + 0x4c));
    }
  }
  else if ((*(int *)(shaderObject + 0x10) == 0x8b48) && (*(int *)(shaderObject + 0x20) - 0x8b30U < 2)) {
    if (*(int *)(shaderObject + 0x2c) != 0) {
      _free(*(int *)(shaderObject + 0x2c));
    }
    if (*(int *)(shaderObject + 0x18) != 0) {
      _free(*(int *)(shaderObject + 0x18));
    }
    if (*(int *)(shaderObject + 0x30) != 0) {
      _ShDestruct(*(int *)(shaderObject + 0x30));
    }
  }
  _gleVecFree(shaderObject);
  return;
}

/* _gleShaderDataUpdateParams @ 0xf4444 (1020 bytes) */
void _gleShaderDataUpdateParams(shaderData)
  int shaderData;
{
  int parameterTableOffset;
  uint componentKind;
  uint elementKind;
  int parameterCount;
  uint elementPart;
  int parameterBlock;
  uint parameterWord;
  uint updatedMaskWord;
  int iVar7;
  uint parameterIndex;
  undefined1 parameterIndexByte;
  uint parameterSlot;
  uint parameterSlot3;
  uint halfSelect;
  uint parameterSlot2;
  
  parameterBlock = *(int *)(shaderData + 0x508);
  parameterIndex = 0;
  parameterCount = *(int *)(parameterBlock + 0x28);
  parameterTableOffset = *(int *)(parameterBlock + 0x2c);
  if (parameterCount < 1) {
    return;
  }
  do {
    parameterWord = *(uint *)(parameterIndex * 8 + parameterBlock + parameterTableOffset * 8);
    parameterIndexByte = (undefined1)parameterIndex;
    switch(parameterWord >> 0x10 & 0x1f) {
    default:
      goto switchD_000f44b0_caseD_0;
    case 1:
      *(undefined1 *)((parameterWord & 0xffff) + shaderData + 0x8c) = parameterIndexByte;
      break;
    case 2:
      *(undefined1 *)((parameterWord & 0xffff) + shaderData + 0x18c) = parameterIndexByte;
      break;
    case 3:
      parameterSlot = parameterWord & 0xff;
      switch(parameterWord >> 8 & 0xf) {
      case 0:
        *(undefined1 *)(parameterSlot * 7 + shaderData + 0x28c) = parameterIndexByte;
        break;
      case 1:
        *(undefined1 *)(parameterSlot * 7 + shaderData + 0x28d) = parameterIndexByte;
        break;
      case 2:
        *(undefined1 *)(parameterSlot * 7 + shaderData + 0x28e) = parameterIndexByte;
        break;
      case 3:
        *(undefined1 *)(parameterSlot * 7 + shaderData + 0x28f) = parameterIndexByte;
        break;
      case 4:
        *(undefined1 *)(parameterSlot * 7 + shaderData + 0x290) = parameterIndexByte;
        break;
      case 5:
        *(undefined1 *)(parameterSlot * 7 + shaderData + 0x291) = parameterIndexByte;
        break;
      case 6:
        *(undefined1 *)(parameterSlot * 7 + shaderData + 0x292) = parameterIndexByte;
      }
      break;
    case 4:
      componentKind = parameterWord >> 9 & 3;
      parameterSlot2 = parameterWord & 0xff;
      parameterWord = parameterWord >> 8 & 1;
      if (componentKind == 1) {
        *(undefined1 *)(parameterSlot2 * 6 + parameterWord * 3 + shaderData + 0x2c5) = parameterIndexByte;
      }
      else if (componentKind < 2) {
        if (componentKind == 0) {
          *(undefined1 *)(parameterSlot2 * 6 + parameterWord * 3 + shaderData + 0x2c4) = parameterIndexByte;
        }
      }
      else if (componentKind == 2) {
        *(undefined1 *)(parameterSlot2 * 6 + parameterWord * 3 + shaderData + 0x2c6) = parameterIndexByte;
      }
      break;
    case 5:
      halfSelect = parameterWord & 1;
      switch(parameterWord >> 1 & 7) {
      case 0:
        *(undefined1 *)(halfSelect * 6 + shaderData + 0x2f4) = parameterIndexByte;
        break;
      case 1:
        *(undefined1 *)(halfSelect * 6 + shaderData + 0x2f5) = parameterIndexByte;
        break;
      case 2:
        *(undefined1 *)(halfSelect * 6 + shaderData + 0x2f6) = parameterIndexByte;
        break;
      case 3:
        *(undefined1 *)(halfSelect * 6 + shaderData + 0x2f7) = parameterIndexByte;
        break;
      case 4:
        *(undefined1 *)(halfSelect * 6 + shaderData + 0x2f8) = parameterIndexByte;
        break;
      case 5:
        *(undefined1 *)(halfSelect * 6 + shaderData + 0x2f9) = parameterIndexByte;
      }
      break;
    case 6:
      *(undefined1 *)(shaderData + 0x358) = parameterIndexByte;
      break;
    case 7:
      *(undefined1 *)((parameterWord & 0x1f) * 4 + shaderData + (parameterWord >> 5 & 7) + 0x300) = parameterIndexByte;
      break;
    case 8:
      *(undefined1 *)((parameterWord & 0x1f) * 4 + shaderData + (parameterWord >> 5 & 7) + 800) = parameterIndexByte;
      break;
    case 10:
      *(undefined1 *)((parameterWord & 0xff) + shaderData + 0x350) = parameterIndexByte;
      break;
    case 0xb:
      *(undefined1 *)(shaderData + 0x356) = parameterIndexByte;
      break;
    case 0xc:
      *(undefined1 *)(shaderData + 0x357) = parameterIndexByte;
      break;
    case 0xd:
      *(undefined1 *)(shaderData + 0x359) = parameterIndexByte;
      break;
    case 0xe:
      *(undefined1 *)(shaderData + 0x35a) = parameterIndexByte;
      break;
    case 0x10:
      parameterSlot3 = parameterWord & 0xff;
      switch(parameterWord >> 8 & 7) {
      case 0:
        parameterSlot3 = 0;
        goto LAB_000f4800;
      case 1:
        parameterSlot3 = 3;
        goto LAB_000f4800;
      case 2:
        parameterSlot3 = 2;
        goto LAB_000f4800;
      case 3:
        parameterSlot3 = parameterSlot3 + 4;
        break;
      case 4:
        parameterSlot3 = parameterSlot3 + 0x10;
        break;
      case 5:
        parameterSlot3 = parameterSlot3 + 8;
        break;
      default:
        parameterSlot3 = 0xffffffff;
      }
      if (parameterSlot3 != 0xffffffff) {
LAB_000f4800:
        elementKind = parameterWord >> 0xe & 3;
        elementPart = parameterWord >> 0xc & 3;
        if (elementKind == 1) {
          *(undefined1 *)(parameterSlot3 * 4 + shaderData + elementPart + 0x41c) = parameterIndexByte;
        }
        else if (elementKind < 2) {
          if (elementKind == 0) {
            *(undefined1 *)(parameterSlot3 * 4 + shaderData + elementPart + 0x35c) = parameterIndexByte;
          }
        }
        else {
          if (elementKind == 2) {
            updatedMaskWord = *(uint *)(shaderData + 4) | 1 << (parameterSlot3 & 0x3f);
            *(undefined1 *)(parameterSlot3 * 4 + shaderData + elementPart + 0x3bc) = parameterIndexByte;
          }
          else {
            if (elementKind != 3) break;
            updatedMaskWord = *(uint *)(shaderData + 4) | 1 << (parameterSlot3 & 0x3f);
            *(undefined1 *)(parameterSlot3 * 4 + shaderData + elementPart + 0x47c) = parameterIndexByte;
          }
LAB_000f48a0:
          *(uint *)(shaderData + 4) = updatedMaskWord;
        }
      }
      break;
    case 0x12:
      updatedMaskWord = *(uint *)(shaderData + 4) | 0x10;
      goto LAB_000f48a0;
    }
    iVar7 = ((int)parameterIndex >> 5) * 4 + shaderData;
    *(uint *)(iVar7 + 8) = *(uint *)(iVar7 + 8) | 1 << (parameterIndex & 0x1f);
switchD_000f44b0_caseD_0:
    parameterIndex = parameterIndex + 1;
    if (parameterCount <= (int)parameterIndex) {
      return;
    }
  } while( true );
}

/* _gleShaderParse @ 0xf48d8 (244 bytes) */
void _gleShaderParse(glContext, param_2)
  int glContext;
  int param_2;
{
  int iVar1;
  undefined1 uVar4;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 local_20 [4];
  
  if (*(char *)(param_2 + 0x24) != '\0') {
    iVar1 = *(int *)(param_2 + 0x30);
    local_20[0] = *(undefined4 *)(param_2 + 0x2c);
    *(undefined1 *)(param_2 + 0x25) = 0;
    if (iVar1 == 0) {
      iVar1 = _ShConstructCompiler(*(int *)(param_2 + 0x20) != 0x8b31,0);
      *(int *)(param_2 + 0x30) = iVar1;
    }
    uVar4 = _ShCompile(iVar1,local_20,1,*(undefined4 *)(glContext + 0x7594),
                       *(undefined4 *)(glContext + 0x7598));
    *(undefined1 *)(param_2 + 0x24) = 0;
    *(undefined1 *)(param_2 + 0x25) = uVar4;
    uVar2 = _ShGetInfoLog(*(undefined4 *)(param_2 + 0x30));
    uVar2 = _strlen(uVar2);
    *(undefined4 *)(param_2 + 0x1c) = uVar2;
    if (*(int *)(param_2 + 0x18) != 0) {
      _free(*(int *)(param_2 + 0x18));
    }
    *(undefined4 *)(param_2 + 0x18) = 0;
    if (*(int *)(param_2 + 0x1c) != 0) {
      iVar1 = _malloc(*(int *)(param_2 + 0x1c) + 1);
      *(int *)(param_2 + 0x18) = iVar1;
      if (iVar1 != 0) {
        pcVar3 = (char *)_ShGetInfoLog(*(undefined4 *)(param_2 + 0x30));
        _strncpy(*(char **)(param_2 + 0x18),pcVar3,*(size_t *)(param_2 + 0x1c));
      }
    }
  }
  return;
}

/* _gleCheckCompressedTexImageArgs @ 0xf49cc (212 bytes) */
int _gleCheckCompressedTexImageArgs(glContext, unusedArg2, internalformat, border, width, height, depth, imageSize)
  int glContext;
  undefined4 unusedArg2;
  int internalformat;
  int border;
  int width;
  int height;
  int depth;
  int imageSize;
{
  undefined4 errorCode;
  int iVar2;
  
  if (internalformat < 0x83f4) {
    if (0x83f1 < internalformat) goto LAB_000f4a24;
    if (internalformat < 0x83f0) goto LAB_000f4a2c;
    iVar2 = 3;
  }
  else {
    if (internalformat != 0x8837) {
LAB_000f4a2c:
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0;
      }
      errorCode = 0x500;
      goto LAB_000f4a94;
    }
LAB_000f4a24:
    iVar2 = 4;
  }
  if (border == 0) {
    if (imageSize == (width + 3 >> 2) * (height + 3 >> 2) * depth << iVar2) {
      return 1;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x502;
  }
LAB_000f4a94:
  *(undefined4 *)(glContext + 0x7574) = errorCode;
  return 0;
}

/* _gleCheckTexImage1DArgs @ 0xf4aa0 (284 bytes) */
int _gleCheckTexImage1DArgs(glContext, target, level, internalformat, width, border, format, type)
  int glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  int width;
  int border;
  undefined4 format;
  undefined4 type;
{
  undefined4 errorCode;
  int iVar2;
  int texture;
  uint uVar4;
  
  texture = _gleLookUpTexture1D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
    goto LAB_000f4b68;
  }
  if (((*(uint *)(glContext + 0x3410) & 1) != 0) && (*(short *)(glContext + 13000) == -0x7fea)) {
    width = (width - *(int *)(glContext + 0x32d0)) + 1;
  }
  uVar4 = width + border * -2;
  if (-1 < (int)uVar4) {
    if ((uVar4 & uVar4 - 1) == 0) {
      iVar2 = *(int *)(glContext + 0x468c);
    }
    else {
      iVar2 = *(int *)(glContext + 0x468c);
      if ((*(uint *)(iVar2 + 0x124) & 0x80000) == 0) goto LAB_000f4b58;
    }
    if ((int)uVar4 <= (int)(uint)*(ushort *)(iVar2 + 0xbc)) {
      iVar2 = _gleCheckTexImageArgs(glContext,level,format,type,internalformat,border,1,1);
      if (iVar2 != 0) {
        return texture;
      }
      return 0;
    }
  }
LAB_000f4b58:
  if (*(int *)(glContext + 0x7574) != 0) {
    return 0;
  }
  errorCode = 0x501;
LAB_000f4b68:
  *(undefined4 *)(glContext + 0x7574) = errorCode;
  return 0;
}

/* _gleCheckCopyTexImage1DArgs @ 0xf4bbc (268 bytes) */
int _gleCheckCopyTexImage1DArgs(glContext, target, level, internalformat, width, border)
  int glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  int width;
  int border;
{
  undefined4 errorCode;
  int iVar2;
  int texture;
  uint uVar4;
  
  texture = _gleLookUpNonProxyTexture1D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
    goto LAB_000f4c7c;
  }
  if (((*(uint *)(glContext + 0x3410) & 1) != 0) && (*(short *)(glContext + 13000) == -0x7fea)) {
    width = (width - *(int *)(glContext + 0x32d0)) + 1;
  }
  uVar4 = width + border * -2;
  if (-1 < (int)uVar4) {
    if ((uVar4 & uVar4 - 1) == 0) {
      iVar2 = *(int *)(glContext + 0x468c);
    }
    else {
      iVar2 = *(int *)(glContext + 0x468c);
      if ((*(uint *)(iVar2 + 0x124) & 0x80000) == 0) goto LAB_000f4c6c;
    }
    if ((int)uVar4 <= (int)(uint)*(ushort *)(iVar2 + 0xbc)) {
      iVar2 = _gleCheckCopyTexImageArgs(glContext,level,internalformat,border,1,1);
      if (iVar2 != 0) {
        return texture;
      }
      return 0;
    }
  }
LAB_000f4c6c:
  if (*(int *)(glContext + 0x7574) != 0) {
    return 0;
  }
  errorCode = 0x501;
LAB_000f4c7c:
  *(undefined4 *)(glContext + 0x7574) = errorCode;
  return 0;
}

/* _gleCheckColorTableArgs @ 0xf4cc8 (228 bytes) */
int _gleCheckColorTableArgs(glContext, target, internalformat, width, format, type)
  int glContext;
  undefined4 target;
  undefined4 internalformat;
  uint width;
  undefined4 format;
  undefined4 type;
{
  undefined4 uVar1;
  int colorTable;
  int iVar3;
  
  colorTable = _gleLookUpColorTable(glContext,target);
  if (colorTable == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
  }
  else {
    iVar3 = _gleCheckTexImageArgs(glContext,0,format,type,internalformat,0,0,0);
    if (iVar3 == 0) {
      return 0;
    }
    if (((int)width < 0) || ((width & width - 1) != 0)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0;
      }
      uVar1 = 0x501;
    }
    else {
      if ((int)width < 0x4001) {
        return colorTable;
      }
      if ((*(ushort *)(colorTable + 0x24) & 0x100) != 0) {
        return 0;
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0;
      }
      uVar1 = 0x8031;
    }
  }
  *(undefined4 *)(glContext + 0x7574) = uVar1;
  return 0;
}

/* _gleCheckCopyColorTableArgs @ 0xf4dac (212 bytes) */
int _gleCheckCopyColorTableArgs(glContext, target, internalformat, width)
  int glContext;
  undefined4 target;
  undefined4 internalformat;
  uint width;
{
  undefined4 uVar1;
  int colorTable;
  int iVar3;
  
  colorTable = _gleLookUpNonProxyColorTable(glContext,target);
  if (colorTable == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
  }
  else {
    iVar3 = _gleCheckCopyTexImageArgs(glContext,0,internalformat,0,0,0);
    if (iVar3 == 0) {
      return 0;
    }
    if (((int)width < 0) || ((width & width - 1) != 0)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0;
      }
      uVar1 = 0x501;
    }
    else {
      if ((int)width < 0x4001) {
        return colorTable;
      }
      if ((*(ushort *)(colorTable + 0x24) & 0x100) != 0) {
        return 0;
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0;
      }
      uVar1 = 0x8031;
    }
  }
  *(undefined4 *)(glContext + 0x7574) = uVar1;
  return 0;
}

/* _gleCheckCompressedTexImage2DArgs @ 0xf4e80 (360 bytes) */
int _gleCheckCompressedTexImage2DArgs(glContext, target, level, internalformat, width, height, border, imageSize)
  int glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  int width;
  int height;
  int border;
  undefined4 imageSize;
{
  undefined4 errorCode;
  ushort uVar2;
  uint uVar3;
  int texture;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  texture = _gleLookUpTexture2D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
    goto LAB_000f4f94;
  }
  uVar6 = height + border * -2;
  uVar7 = width + border * -2;
  uVar2 = *(ushort *)(texture + 0x24) & 0xf;
  if (uVar2 == 2) {
    if (((-1 < (int)uVar7) &&
        (uVar3 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xc0), (int)uVar7 <= (int)uVar3)) &&
       (-1 < (int)uVar6)) {
LAB_000f4f80:
      if ((int)uVar6 <= (int)uVar3) {
LAB_000f4fa0:
        iVar5 = ((int (*)())_gleCheckCompressedTexImageArgs)(glContext,level,internalformat,border,uVar7,uVar6,1,imageSize);
        if (iVar5 != 0) {
          return texture;
        }
        return 0;
      }
    }
  }
  else {
    if (uVar2 < 3) {
      if ((*(ushort *)(texture + 0x24) & 0xf) != 0) goto LAB_000f4fa0;
      if ((uVar7 != uVar6) ||
         ((int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xc2) < (int)uVar6))
      goto LAB_000f4f84;
    }
    else if (uVar2 != 3) goto LAB_000f4fa0;
    if (((-1 < (int)uVar7) &&
        ((((uVar7 & uVar7 - 1) == 0 &&
          (uVar3 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xbc), (int)uVar7 <= (int)uVar3))
         && (-1 < (int)uVar6)))) && ((uVar6 & uVar6 - 1) == 0)) goto LAB_000f4f80;
  }
LAB_000f4f84:
  if (*(int *)(glContext + 0x7574) != 0) {
    return 0;
  }
  errorCode = 0x501;
LAB_000f4f94:
  *(undefined4 *)(glContext + 0x7574) = errorCode;
  return 0;
}

/* _gleCheckCompressedTexImage3DArgs @ 0xf4fe8 (296 bytes) */
int _gleCheckCompressedTexImage3DArgs(glContext, target, level, internalformat, width, height, depth, border, imageSize)
  int glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  int width;
  int height;
  uint depth;
  int border;
  undefined4 imageSize;
{
  undefined4 errorCode;
  uint uVar2;
  int texture;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  texture = _gleLookUpTexture3D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
    uVar5 = height + border * -2;
    uVar6 = width + border * -2;
    if (((*(ushort *)(texture + 0x24) & 0xf) != 1) ||
       ((((((-1 < (int)uVar6 && ((uVar6 & uVar6 - 1) == 0)) &&
           (uVar2 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xbe), (int)uVar6 <= (int)uVar2))
          && ((-1 < (int)uVar5 && ((uVar5 & uVar5 - 1) == 0)))) &&
         (((int)uVar5 <= (int)uVar2 && ((-1 < (int)depth && ((depth & depth - 1) == 0)))))) &&
        ((int)depth <= (int)uVar2)))) {
      iVar4 = ((int (*)())_gleCheckCompressedTexImageArgs)(glContext,level,internalformat,border,uVar6,uVar5,depth,imageSize);
      if (iVar4 != 0) {
        return texture;
      }
      return 0;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x501;
  }
  *(undefined4 *)(glContext + 0x7574) = errorCode;
  return 0;
}

/* _gleCheckCompressedTexSubImageRange @ 0xf5110 (92 bytes) */
int _gleCheckCompressedTexSubImageRange(glContext, levelInfo, offset, size, levelSize, alignMask)
  int glContext;
  int levelInfo;
  uint offset;
  uint size;
  int levelSize;
  uint alignMask;
{
  if (((-1 < (int)size) && ((int)-(uint)*(byte *)(levelInfo + 10) <= (int)offset)) &&
     ((int)(offset + size) <= (int)(levelSize + (uint)*(byte *)(levelInfo + 10)))) {
    if ((offset & alignMask) == 0) {
      if ((size & alignMask) == 0) {
        return 1;
      }
    }
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return 0;
}

/* _gleCheckTexSubImage1DArgs @ 0xf516c (280 bytes) */
int _gleCheckTexSubImage1DArgs(glContext, target, level, xoffset, width, format, type)
  int glContext;
  undefined4 target;
  int level;
  undefined4 xoffset;
  int width;
  int format;
  undefined4 type;
{
  undefined4 errorCode;
  int texture;
  int argsCheckResultThenLevelRecordThenRangeResult;
  
  texture = _gleLookUpNonProxyTexture1D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
    if ((format != 0x1902) || (*(short *)(texture + 0x26) == 0x1902)) {
      argsCheckResultThenLevelRecordThenRangeResult = _gleCheckTexSubImageArgs(glContext,level,format,type);
      if (argsCheckResultThenLevelRecordThenRangeResult == 0) {
        return 0;
      }
      argsCheckResultThenLevelRecordThenRangeResult = texture + level * 0x18;
      if ((*(byte *)(argsCheckResultThenLevelRecordThenRangeResult + 0xcf) & 0x20) != 0) {
        if (((*(uint *)(glContext + 0x3410) & 1) != 0) && (*(short *)(glContext + 13000) == -0x7fea)) {
          width = (width - *(int *)(glContext + 0x32d0)) + 1;
        }
        argsCheckResultThenLevelRecordThenRangeResult = _gleCheckTexSubImageRange
                          (glContext,argsCheckResultThenLevelRecordThenRangeResult + 0xc4,xoffset,width,(uint)*(ushort *)(argsCheckResultThenLevelRecordThenRangeResult + 200));
        if (argsCheckResultThenLevelRecordThenRangeResult != 0) {
          return texture;
        }
        return 0;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = errorCode;
  return 0;
}

/* _gleCheckCopyTexSubImage1DArgs @ 0xf5284 (268 bytes) */
int _gleCheckCopyTexSubImage1DArgs(glContext, target, level, xoffset, width)
  int glContext;
  undefined4 target;
  uint level;
  undefined4 xoffset;
  int width;
{
  bool bVar1;
  undefined4 errorCode;
  int iVar3;
  int texture;
  
  texture = _gleLookUpNonProxyTexture1D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
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
    iVar3 = texture + level * 0x18;
    if ((*(byte *)(iVar3 + 0xcf) & 0x20) != 0) {
      if (((*(uint *)(glContext + 0x3410) & 1) != 0) && (*(short *)(glContext + 13000) == -0x7fea)) {
        width = (width - *(int *)(glContext + 0x32d0)) + 1;
      }
      iVar3 = _gleCheckTexSubImageRange
                        (glContext,iVar3 + 0xc4,xoffset,width,(uint)*(ushort *)(iVar3 + 200));
      if (iVar3 != 0) {
        return texture;
      }
      return 0;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = errorCode;
  return 0;
}

/* _gleCheckCopyTexSubImage2DArgs @ 0xf5390 (476 bytes) */
int _gleCheckCopyTexSubImage2DArgs(glContext, target, level, xoffset, yoffset, width, height)
  int glContext;
  int target;
  uint level;
  uint xoffset;
  uint yoffset;
  uint width;
  uint height;
{
  bool bVar1;
  undefined4 errorCode;
  int iVar3;
  int texture;
  int iVar5;
  int iVar6;
  
  texture = _gleLookUpNonProxyTexture2D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
LAB_000f549c:
    *(undefined4 *)(glContext + 0x7574) = errorCode;
    return 0;
  }
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
  iVar6 = texture + 0xc4 + level * 0x18;
  if (target - 0x8515U < 6) {
    iVar6 = texture + 0xc4 + target * 0x168 + level * 0x18 + -0xbb2588;
  }
  if (((*(byte *)(iVar6 + 0xb) & 0x20) == 0) ||
     ((*(short *)(iVar6 + 0x12) == 0 &&
      (((((width & 3) != 0 && (width != *(ushort *)(iVar6 + 4))) ||
        (((height & 3) != 0 && (height != *(ushort *)(iVar6 + 6))))) ||
       (((xoffset & 3) != 0 || ((yoffset & 3) != 0)))))))) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x502;
    goto LAB_000f549c;
  }
  if ((*(uint *)(glContext + 0x3410) & 2) == 0) {
    if (((*(uint *)(glContext + 0x3410) & 4) == 0) || (*(short *)(glContext + 0x3348) != -0x7fea))
    goto LAB_000f550c;
    iVar5 = *(int *)(glContext + 0x3354);
    iVar3 = *(int *)(glContext + 0x3350);
  }
  else {
    if (*(short *)(glContext + 0x3308) != -0x7fea) goto LAB_000f550c;
    iVar5 = *(int *)(glContext + 0x3314);
    iVar3 = *(int *)(glContext + 0x3310);
  }
  width = (width - iVar3) + 1;
  height = (height - iVar5) + 1;
LAB_000f550c:
  iVar3 = _gleCheckTexSubImageRange(glContext,iVar6,xoffset,width,(uint)*(ushort *)(iVar6 + 4));
  if (iVar3 == 0) {
    return 0;
  }
  iVar6 = _gleCheckTexSubImageRange(glContext,iVar6,yoffset,height,(uint)*(ushort *)(iVar6 + 6));
  if (iVar6 != 0) {
    return texture;
  }
  return 0;
}

/* _gleCheckTexSubImage3DArgs @ 0xf556c (316 bytes) */
int _gleCheckTexSubImage3DArgs(glContext, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type)
  int glContext;
  undefined4 target;
  int level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 zoffset;
  undefined4 width;
  undefined4 height;
  undefined4 depth;
  int format;
  undefined4 type;
{
  undefined4 errorCode;
  int texture;
  int iVar3;
  int iVar4;
  int iVar5;
  
  texture = _gleLookUpNonProxyTexture3D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
    if ((format != 0x1902) || (*(short *)(texture + 0x26) == 0x1902)) {
      iVar3 = _gleCheckTexSubImageArgs(glContext,level,format,type);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = texture + level * 0x18;
      iVar5 = iVar3 + 0xc4;
      if ((*(byte *)(iVar3 + 0xcf) & 0x20) != 0) {
        iVar4 = _gleCheckTexSubImageRange
                          (glContext,iVar5,xoffset,width,(uint)*(ushort *)(iVar3 + 200));
        if (iVar4 == 0) {
          return 0;
        }
        iVar4 = _gleCheckTexSubImageRange
                          (glContext,iVar5,yoffset,height,(uint)*(ushort *)(iVar3 + 0xca));
        if (iVar4 != 0) {
          iVar3 = _gleCheckTexSubImageRange
                            (glContext,iVar5,zoffset,depth,(uint)*(ushort *)(iVar3 + 0xcc));
          if (iVar3 != 0) {
            return texture;
          }
          return 0;
        }
        return 0;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = errorCode;
  return 0;
}

/* _gleCheckCopyTexSubImage3DArgs @ 0xf56a8 (308 bytes) */
int _gleCheckCopyTexSubImage3DArgs(glContext, target, level, xoffset, yoffset, zoffset, width, height, depth)
  int glContext;
  undefined4 target;
  uint level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 zoffset;
  undefined4 width;
  undefined4 height;
  undefined4 depth;
{
  bool bVar1;
  undefined4 errorCode;
  int iVar3;
  int texture;
  int iVar5;
  int iVar6;
  
  texture = _gleLookUpNonProxyTexture3D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
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
    iVar3 = texture + level * 0x18;
    iVar6 = iVar3 + 0xc4;
    if ((*(byte *)(iVar3 + 0xcf) & 0x20) != 0) {
      iVar5 = _gleCheckTexSubImageRange
                        (glContext,iVar6,xoffset,width,(uint)*(ushort *)(iVar3 + 200));
      if (iVar5 == 0) {
        return 0;
      }
      iVar5 = _gleCheckTexSubImageRange
                        (glContext,iVar6,yoffset,height,(uint)*(ushort *)(iVar3 + 0xca));
      if (iVar5 != 0) {
        iVar3 = _gleCheckTexSubImageRange
                          (glContext,iVar6,zoffset,depth,(uint)*(ushort *)(iVar3 + 0xcc));
        if (iVar3 != 0) {
          return texture;
        }
        return 0;
      }
      return 0;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = errorCode;
  return 0;
}

/* _gleCheckCompressedTexSubImage2DArgs @ 0xf57dc (320 bytes) */
int _gleCheckCompressedTexSubImage2DArgs(glContext, target, level, xoffset, yoffset, width, height, format, imageSize)
  int glContext;
  int target;
  int level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 width;
  undefined4 height;
  undefined4 format;
  undefined4 imageSize;
{
  undefined4 errorCode;
  int texture;
  int argsCheckResult;
  int levelRecordThenRangeResult;
  int xRangeCheckResult;
  
  texture = _gleLookUpNonProxyTexture2D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
    argsCheckResult = ((int (*)())_gleCheckCompressedTexImageArgs)(glContext,level,format,0,width,height,1,imageSize);
    if (argsCheckResult == 0) {
      return 0;
    }
    levelRecordThenRangeResult = texture + 0xc4 + level * 0x18;
    if (target - 0x8515U < 6) {
      levelRecordThenRangeResult = texture + 0xc4 + target * 0x168 + level * 0x18 + -0xbb2588;
    }
    if (*(int *)(levelRecordThenRangeResult + 0x14) != 0) {
      xRangeCheckResult = ((int (*)())_gleCheckCompressedTexSubImageRange)(glContext,levelRecordThenRangeResult,xoffset,width,(uint)*(ushort *)(levelRecordThenRangeResult + 4),3);
      if (xRangeCheckResult == 0) {
        return 0;
      }
      levelRecordThenRangeResult = ((int (*)())_gleCheckCompressedTexSubImageRange)(glContext,levelRecordThenRangeResult,yoffset,height,(uint)*(ushort *)(levelRecordThenRangeResult + 6),3);
      if (levelRecordThenRangeResult != 0) {
        return texture;
      }
      return 0;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = errorCode;
  return 0;
}

/* _gleCheckCompressedTexSubImage3DArgs @ 0xf591c (364 bytes) */
int _gleCheckCompressedTexSubImage3DArgs(glContext, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize)
  int glContext;
  int target;
  int level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 zoffset;
  undefined4 width;
  undefined4 height;
  undefined4 depth;
  undefined4 format;
  undefined4 imageSize;
{
  undefined4 errorCode;
  int texture;
  int iVar3;
  int iVar4;
  
  texture = _gleLookUpNonProxyTexture3D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
    iVar3 = ((int (*)())_gleCheckCompressedTexImageArgs)(glContext,level,format,0,width,height,depth,imageSize);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = texture + 0xc4 + level * 0x18;
    if (target - 0x8515U < 6) {
      iVar3 = texture + 0xc4 + target * 0x168 + level * 0x18 + -0xbb2588;
    }
    if (*(int *)(iVar3 + 0x14) != 0) {
      iVar4 = ((int (*)())_gleCheckCompressedTexSubImageRange)(glContext,iVar3,xoffset,width,(uint)*(ushort *)(iVar3 + 4),3);
      if (iVar4 == 0) {
        return 0;
      }
      iVar4 = ((int (*)())_gleCheckCompressedTexSubImageRange)(glContext,iVar3,yoffset,height,(uint)*(ushort *)(iVar3 + 6),3);
      if (iVar4 != 0) {
        iVar3 = ((int (*)())_gleCheckCompressedTexSubImageRange)(glContext,iVar3,zoffset,depth,(uint)*(ushort *)(iVar3 + 8),0);
        if (iVar3 != 0) {
          return texture;
        }
        return 0;
      }
      return 0;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = errorCode;
  return 0;
}

/* _gleCheckColorSubTableArgs @ 0xf5a88 (200 bytes) */
int _gleCheckColorSubTableArgs(glContext, target, start, count, format, type)
  int glContext;
  undefined4 target;
  undefined4 start;
  undefined4 count;
  undefined4 format;
  undefined4 type;
{
  undefined4 errorCode;
  int colorTable;
  int iVar3;
  
  colorTable = _gleLookUpNonProxyColorTable(glContext,target);
  if (colorTable == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
    iVar3 = _gleCheckTexSubImageArgs(glContext,0,format,type);
    if (iVar3 == 0) {
      return 0;
    }
    if (*(int *)(colorTable + 0xc0) != 0) {
      iVar3 = _gleCheckTexSubImageRange
                        (glContext,colorTable + 0xac,start,count,(uint)*(ushort *)(colorTable + 0xb0));
      if (iVar3 != 0) {
        return colorTable;
      }
      return 0;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = errorCode;
  return 0;
}

/* _gleCheckCopyColorSubTableArgs @ 0xf5b50 (160 bytes) */
int _gleCheckCopyColorSubTableArgs(glContext, target, start, count)
  int glContext;
  undefined4 target;
  undefined4 start;
  undefined4 count;
{
  undefined4 errorCode;
  int colorTable;
  int iVar3;
  
  colorTable = _gleLookUpNonProxyColorTable(glContext,target);
  if (colorTable == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
    if (*(int *)(colorTable + 0xc0) != 0) {
      iVar3 = _gleCheckTexSubImageRange
                        (glContext,colorTable + 0xac,start,count,(uint)*(ushort *)(colorTable + 0xb0));
      if (iVar3 != 0) {
        return colorTable;
      }
      return 0;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = errorCode;
  return 0;
}

/* _gleSphereGenST @ 0xf5bf0 (356 bytes) */
double _gleSphereGenST(undefined4 glContext,undefined4 eyePosition,float *normal,float *stOut,double unusedFloatArg1)
{
  float dotThenDoubledThenReflectZPlusOneThenLengthSquared;
  undefined4 incomingR7;
  undefined4 incomingR8;
  double inverseLength;
  float reflectX;
  float reflectY;
  float lengthSquaredThenNewtonTermThenOffset;
  float estimateProduct;
  float eyeDirectionX;
  float eyeDirectionY;
  float eyeDirectionZ;
  
  (**(code **)PTR__gleVectorNormalize_00112064)(glContext,eyePosition,&eyeDirectionX,stOut,incomingR7,incomingR8);
  dotThenDoubledThenReflectZPlusOneThenLengthSquared = normal[2] * eyeDirectionZ + (*normal * eyeDirectionX + normal[1] * eyeDirectionY);
  dotThenDoubledThenReflectZPlusOneThenLengthSquared = dotThenDoubledThenReflectZPlusOneThenLengthSquared + dotThenDoubledThenReflectZPlusOneThenLengthSquared;
  reflectY = -(double)(normal[1] * dotThenDoubledThenReflectZPlusOneThenLengthSquared - eyeDirectionY);
  reflectX = -(double)(*normal * dotThenDoubledThenReflectZPlusOneThenLengthSquared - eyeDirectionX);
  dotThenDoubledThenReflectZPlusOneThenLengthSquared = (-(normal[2] * dotThenDoubledThenReflectZPlusOneThenLengthSquared - eyeDirectionZ) + FLOAT_00108e54);
  dotThenDoubledThenReflectZPlusOneThenLengthSquared = dotThenDoubledThenReflectZPlusOneThenLengthSquared * dotThenDoubledThenReflectZPlusOneThenLengthSquared + (reflectX * reflectX + (reflectY * reflectY));
  lengthSquaredThenNewtonTermThenOffset = (double)dotThenDoubledThenReflectZPlusOneThenLengthSquared;
  inverseLength = (double)FLOAT_00108e50;
  if ((!((double)lengthSquaredThenNewtonTermThenOffset <= (double)FLOAT_00108e50)) && (inverseLength = (double)lengthSquaredThenNewtonTermThenOffset, (double)lengthSquaredThenNewtonTermThenOffset != (double)FLOAT_00108e54)) {
    inverseLength = (double)GH_U2F((unsigned int)((0x5f375a00 - ((uint)GH_F2U(dotThenDoubledThenReflectZPlusOneThenLengthSquared) >> 1))));
    estimateProduct = (double)(float)((double)(float)((double)lengthSquaredThenNewtonTermThenOffset * inverseLength) * inverseLength);
    lengthSquaredThenNewtonTermThenOffset = (double)(float)(DOUBLE_00108e40 - (double)estimateProduct);
    inverseLength = (double)(float)(inverseLength * DOUBLE_00108e38 * (double)lengthSquaredThenNewtonTermThenOffset *
                           (DOUBLE_00108e48 -
                           (double)((estimateProduct * lengthSquaredThenNewtonTermThenOffset) * lengthSquaredThenNewtonTermThenOffset)));
  }
  if ((double)FLOAT_00108e80 < inverseLength) {
    lengthSquaredThenNewtonTermThenOffset = (double)FLOAT_00108e90;
    stOut[1] = (float)((double)reflectY * inverseLength + (double)lengthSquaredThenNewtonTermThenOffset);
    *stOut = (float)((double)reflectX * inverseLength + (double)lengthSquaredThenNewtonTermThenOffset);
  }
  else {
    stOut[1] = 0.5;
    *stOut = 0.5;
  }
  return;
}

/* _gleVtxTextureCoordGenObjectSlow @ 0xf5d54 (500 bytes) */
void _gleVtxTextureCoordGenObjectSlow(param_1, vertexStartThenCursor, vertexCount)
  int param_1;
  uint vertexStartThenCursor;
  int vertexCount;
{
  float objectPlaneSD;
  float objectPlaneQD;
  float objectPlaneRD;
  float objectPlaneTD;
  float objectPlaneSA;
  float objectPlaneQA;
  float objectPlaneRA;
  float objectPlaneTA;
  float objectPlaneSB;
  float objectPlaneQB;
  float objectPlaneRB;
  float objectPlaneTB;
  float objectPlaneSC;
  float objectPlaneQC;
  float objectPlaneRC;
  float objectPlaneTC;
  uint vertexCursor;
  uint uVar6;
  uint remaining;
  
  uVar6 = vertexStartThenCursor + vertexCount * 0x100;
  if ((*(char *)(param_1 + 0x3d78) != '\0') && (*(short *)(param_1 + 0x3ce8) == 0x2401)) {
    objectPlaneSD = *(float *)(param_1 + 0x3d08);
    objectPlaneSA = *(float *)(param_1 + 0x3cfc);
    objectPlaneSB = *(float *)(param_1 + 0x3d00);
    objectPlaneSC = *(float *)(param_1 + 0x3d04);
    if (vertexStartThenCursor < uVar6) {
      remaining = (uVar6 - vertexStartThenCursor) + 0xff >> 8;
      vertexCursor = vertexStartThenCursor;
      do {
        *(float *)(vertexCursor + 0x80) =
             objectPlaneSD * *(float *)(vertexCursor + 0x2c) +
             (objectPlaneSC * *(float *)(vertexCursor + 0x28) +
             (objectPlaneSA * *(float *)(vertexCursor + 0x20) + objectPlaneSB * *(float *)(vertexCursor + 0x24)));
        vertexCursor = vertexCursor + 0x100;
        remaining = remaining - 1;
      } while (remaining != 0);
    }
  }
  if ((*(char *)(param_1 + 0x3d79) != '\0') && (*(short *)(param_1 + 0x3d0c) == 0x2401)) {
    objectPlaneTD = *(float *)(param_1 + 0x3d2c);
    objectPlaneTA = *(float *)(param_1 + 0x3d20);
    objectPlaneTB = *(float *)(param_1 + 0x3d24);
    objectPlaneTC = *(float *)(param_1 + 0x3d28);
    if (vertexStartThenCursor < uVar6) {
      remaining = (uVar6 - vertexStartThenCursor) + 0xff >> 8;
      vertexCursor = vertexStartThenCursor;
      do {
        *(float *)(vertexCursor + 0x84) =
             objectPlaneTD * *(float *)(vertexCursor + 0x2c) +
             (objectPlaneTC * *(float *)(vertexCursor + 0x28) +
             (objectPlaneTA * *(float *)(vertexCursor + 0x20) + objectPlaneTB * *(float *)(vertexCursor + 0x24)));
        vertexCursor = vertexCursor + 0x100;
        remaining = remaining - 1;
      } while (remaining != 0);
    }
  }
  if ((*(char *)(param_1 + 0x3d7a) != '\0') && (*(short *)(param_1 + 0x3d30) == 0x2401)) {
    objectPlaneRD = *(float *)(param_1 + 0x3d50);
    objectPlaneRA = *(float *)(param_1 + 0x3d44);
    objectPlaneRB = *(float *)(param_1 + 0x3d48);
    objectPlaneRC = *(float *)(param_1 + 0x3d4c);
    if (vertexStartThenCursor < uVar6) {
      remaining = (uVar6 - vertexStartThenCursor) + 0xff >> 8;
      vertexCursor = vertexStartThenCursor;
      do {
        *(float *)(vertexCursor + 0x88) =
             objectPlaneRD * *(float *)(vertexCursor + 0x2c) +
             (objectPlaneRC * *(float *)(vertexCursor + 0x28) +
             (objectPlaneRA * *(float *)(vertexCursor + 0x20) + objectPlaneRB * *(float *)(vertexCursor + 0x24)));
        vertexCursor = vertexCursor + 0x100;
        remaining = remaining - 1;
      } while (remaining != 0);
    }
    *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  }
  if (*(char *)(param_1 + 0x3d7b) == '\0') {
    return;
  }
  if (*(short *)(param_1 + 0x3d54) != 0x2401) {
    return;
  }
  objectPlaneQD = *(float *)(param_1 + 0x3d74);
  objectPlaneQA = *(float *)(param_1 + 0x3d68);
  objectPlaneQB = *(float *)(param_1 + 0x3d6c);
  objectPlaneQC = *(float *)(param_1 + 0x3d70);
  if (vertexStartThenCursor < uVar6) {
    uVar6 = (uVar6 - vertexStartThenCursor) + 0xff >> 8;
    do {
      *(float *)(vertexStartThenCursor + 0x8c) =
           objectPlaneQD * *(float *)(vertexStartThenCursor + 0x2c) +
           (objectPlaneQC * *(float *)(vertexStartThenCursor + 0x28) +
           (objectPlaneQA * *(float *)(vertexStartThenCursor + 0x20) + objectPlaneQB * *(float *)(vertexStartThenCursor + 0x24)));
      vertexStartThenCursor = vertexStartThenCursor + 0x100;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  return;
}

/* _gleVtxTextureCoordGenEyeSlow @ 0xf5f48 (1288 bytes) */
void _gleVtxTextureCoordGenEyeSlow(int glContext,uint vertexStartThenCursor,int vertexCount,double fparam_1)
{
  float normalDotEyeDirection;
  float eyePlaneQD;
  float eyePlaneRD;
  float eyePlaneTD;
  float eyePlaneSD;
  float eyePlaneSA;
  float eyePlaneQA;
  float eyePlaneRA;
  float eyePlaneTA;
  float eyePlaneSB;
  float eyePlaneQB;
  float eyePlaneRB;
  float eyePlaneTB;
  float eyePlaneSC;
  float eyePlaneQC;
  float eyePlaneRC;
  float eyePlaneTC;
  ushort texGenMode;
  undefined *vectorNormalize;
  uint vertexEndThenRemaining;
  uint vertexCursor;
  uint vertexCursor2;
  uint remaining;
  undefined4 sphereMapS;
  undefined4 sphereMapT;
  float eyeDirectionX;
  float eyeDirectionY;
  float eyeDirectionZ;
  
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  vertexEndThenRemaining = vertexStartThenCursor + vertexCount * 0x100;
  if (*(char *)(glContext + 0x3d78) != '\0') {
    texGenMode = *(ushort *)(glContext + 0x3ce8);
    vertexCursor2 = vertexStartThenCursor;
    if (texGenMode == 0x2402) {
      for (; vertexCursor2 < vertexEndThenRemaining; vertexCursor2 = vertexCursor2 + 0x100) {
        fparam_1 = (double)((double (*)())_gleSphereGenST)(glContext,vertexCursor2 + 0x20,vertexCursor2 + 0x40,&sphereMapS,fparam_1);
        *(undefined4 *)(vertexCursor2 + 0x80) = sphereMapS;
      }
    }
    else if (texGenMode < 0x2403) {
      if (texGenMode == 0x2400) {
        eyePlaneSD = *(float *)(glContext + 0x3cf8);
        eyePlaneSA = *(float *)(glContext + 0x3cec);
        eyePlaneSB = *(float *)(glContext + 0x3cf0);
        eyePlaneSC = *(float *)(glContext + 0x3cf4);
        if (vertexStartThenCursor < vertexEndThenRemaining) {
          remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
          vertexCursor = vertexStartThenCursor;
          do {
            *(float *)(vertexCursor + 0x80) =
                 eyePlaneSD * *(float *)(vertexCursor + 0x2c) +
                 (eyePlaneSC * *(float *)(vertexCursor + 0x28) +
                 (eyePlaneSA * *(float *)(vertexCursor + 0x20) + eyePlaneSB * *(float *)(vertexCursor + 0x24)));
            vertexCursor = vertexCursor + 0x100;
            remaining = remaining - 1;
          } while (remaining != 0);
        }
      }
    }
    else if (texGenMode == 0x8511) {
      if (vertexStartThenCursor < vertexEndThenRemaining) {
        remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
        vertexCursor = vertexStartThenCursor;
        do {
          *(undefined4 *)(vertexCursor + 0x80) = *(undefined4 *)(vertexCursor + 0x40);
          vertexCursor = vertexCursor + 0x100;
          remaining = remaining - 1;
        } while (remaining != 0);
      }
    }
    else if ((texGenMode == 0x8512) && (vertexStartThenCursor < vertexEndThenRemaining)) {
      do {
        fparam_1 = (double)(**(double ( **)(int,int,int))vectorNormalize)(glContext, vertexCursor2 + 0x20, &eyeDirectionX);
        normalDotEyeDirection = *(float *)(vertexCursor2 + 0x48) * eyeDirectionZ +
                (*(float *)(vertexCursor2 + 0x40) * eyeDirectionX + *(float *)(vertexCursor2 + 0x44) * eyeDirectionY);
        *(float *)(vertexCursor2 + 0x80) = -(*(float *)(vertexCursor2 + 0x40) * (normalDotEyeDirection + normalDotEyeDirection) - eyeDirectionX);
        vertexCursor2 = vertexCursor2 + 0x100;
      } while (vertexCursor2 < vertexEndThenRemaining);
    }
  }
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  if (*(char *)(glContext + 0x3d79) != '\0') {
    texGenMode = *(ushort *)(glContext + 0x3d0c);
    vertexCursor2 = vertexStartThenCursor;
    if (texGenMode == 0x2402) {
      for (; vertexCursor2 < vertexEndThenRemaining; vertexCursor2 = vertexCursor2 + 0x100) {
        fparam_1 = (double)((double (*)())_gleSphereGenST)(glContext,vertexCursor2 + 0x20,vertexCursor2 + 0x40,&sphereMapS,fparam_1);
        *(undefined4 *)(vertexCursor2 + 0x84) = sphereMapT;
      }
    }
    else if (texGenMode < 0x2403) {
      if (texGenMode == 0x2400) {
        eyePlaneTD = *(float *)(glContext + 0x3d1c);
        eyePlaneTA = *(float *)(glContext + 0x3d10);
        eyePlaneTB = *(float *)(glContext + 0x3d14);
        eyePlaneTC = *(float *)(glContext + 0x3d18);
        if (vertexStartThenCursor < vertexEndThenRemaining) {
          remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
          vertexCursor = vertexStartThenCursor;
          do {
            *(float *)(vertexCursor + 0x84) =
                 eyePlaneTD * *(float *)(vertexCursor + 0x2c) +
                 (eyePlaneTC * *(float *)(vertexCursor + 0x28) +
                 (eyePlaneTA * *(float *)(vertexCursor + 0x20) + eyePlaneTB * *(float *)(vertexCursor + 0x24)));
            vertexCursor = vertexCursor + 0x100;
            remaining = remaining - 1;
          } while (remaining != 0);
        }
      }
    }
    else if (texGenMode == 0x8511) {
      if (vertexStartThenCursor < vertexEndThenRemaining) {
        remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
        vertexCursor = vertexStartThenCursor;
        do {
          *(undefined4 *)(vertexCursor + 0x84) = *(undefined4 *)(vertexCursor + 0x44);
          vertexCursor = vertexCursor + 0x100;
          remaining = remaining - 1;
        } while (remaining != 0);
      }
    }
    else if ((texGenMode == 0x8512) && (vertexStartThenCursor < vertexEndThenRemaining)) {
      do {
        (**(code **)vectorNormalize)(glContext,vertexCursor2 + 0x20,&eyeDirectionX);
        normalDotEyeDirection = *(float *)(vertexCursor2 + 0x48) * eyeDirectionZ +
                (*(float *)(vertexCursor2 + 0x40) * eyeDirectionX + *(float *)(vertexCursor2 + 0x44) * eyeDirectionY);
        *(float *)(vertexCursor2 + 0x84) = -(*(float *)(vertexCursor2 + 0x44) * (normalDotEyeDirection + normalDotEyeDirection) - eyeDirectionY);
        vertexCursor2 = vertexCursor2 + 0x100;
      } while (vertexCursor2 < vertexEndThenRemaining);
    }
  }
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  if (*(char *)(glContext + 0x3d7a) != '\0') {
    texGenMode = *(ushort *)(glContext + 0x3d30);
    if (texGenMode == 0x8511) {
      if (vertexStartThenCursor < vertexEndThenRemaining) {
        remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
        vertexCursor = vertexStartThenCursor;
        do {
          *(undefined4 *)(vertexCursor + 0x88) = *(undefined4 *)(vertexCursor + 0x48);
          vertexCursor = vertexCursor + 0x100;
          remaining = remaining - 1;
        } while (remaining != 0);
      }
    }
    else if (texGenMode < 0x8512) {
      if (texGenMode == 0x2400) {
        eyePlaneRD = *(float *)(glContext + 0x3d40);
        eyePlaneRA = *(float *)(glContext + 0x3d34);
        eyePlaneRB = *(float *)(glContext + 0x3d38);
        eyePlaneRC = *(float *)(glContext + 0x3d3c);
        if (vertexStartThenCursor < vertexEndThenRemaining) {
          remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
          vertexCursor = vertexStartThenCursor;
          do {
            *(float *)(vertexCursor + 0x88) =
                 eyePlaneRD * *(float *)(vertexCursor + 0x2c) +
                 (eyePlaneRC * *(float *)(vertexCursor + 0x28) +
                 (eyePlaneRA * *(float *)(vertexCursor + 0x20) + eyePlaneRB * *(float *)(vertexCursor + 0x24)));
            vertexCursor = vertexCursor + 0x100;
            remaining = remaining - 1;
          } while (remaining != 0);
        }
      }
    }
    else if ((texGenMode == 0x8512) && (vertexStartThenCursor < vertexEndThenRemaining)) {
      vertexCursor2 = vertexStartThenCursor;
      do {
        (**(code **)vectorNormalize)(glContext,vertexCursor2 + 0x20,&eyeDirectionX);
        normalDotEyeDirection = *(float *)(vertexCursor2 + 0x48) * eyeDirectionZ +
                (*(float *)(vertexCursor2 + 0x40) * eyeDirectionX + *(float *)(vertexCursor2 + 0x44) * eyeDirectionY);
        *(float *)(vertexCursor2 + 0x88) = -(*(float *)(vertexCursor2 + 0x48) * (normalDotEyeDirection + normalDotEyeDirection) - eyeDirectionZ);
        vertexCursor2 = vertexCursor2 + 0x100;
      } while (vertexCursor2 < vertexEndThenRemaining);
    }
    *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  }
  if (*(char *)(glContext + 0x3d7b) != '\0') {
    if (*(short *)(glContext + 0x3d54) == 0x2400) {
      eyePlaneQD = *(float *)(glContext + 0x3d64);
      eyePlaneQA = *(float *)(glContext + 0x3d58);
      eyePlaneQB = *(float *)(glContext + 0x3d5c);
      eyePlaneQC = *(float *)(glContext + 0x3d60);
      if (vertexStartThenCursor < vertexEndThenRemaining) {
        vertexEndThenRemaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
        do {
          *(float *)(vertexStartThenCursor + 0x8c) =
               eyePlaneQD * *(float *)(vertexStartThenCursor + 0x2c) +
               (eyePlaneQC * *(float *)(vertexStartThenCursor + 0x28) +
               (eyePlaneQA * *(float *)(vertexStartThenCursor + 0x20) + eyePlaneQB * *(float *)(vertexStartThenCursor + 0x24)));
          vertexStartThenCursor = vertexStartThenCursor + 0x100;
          vertexEndThenRemaining = vertexEndThenRemaining - 1;
        } while (vertexEndThenRemaining != 0);
      }
    }
    *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 2;
  }
  return;
}

/* _gleVtxTextureCoordGenEyeST @ 0xf6450 (140 bytes) */
void _gleVtxTextureCoordGenEyeST(param_1, vertexCursor, vertexCount)
  int param_1;
  uint vertexCursor;
  int vertexCount;
{
  float eyePlaneSD;
  float eyePlaneSB;
  float eyePlaneSC;
  float eyePlaneTA;
  float eyePlaneTD;
  float eyePlaneSA;
  float eyePlaneTB;
  float eyePlaneTC;
  uint uVar9;
  
  uVar9 = vertexCursor + vertexCount * 0x100;
  eyePlaneSD = *(float *)(param_1 + 0x3cf8);
  eyePlaneSB = *(float *)(param_1 + 0x3cf0);
  eyePlaneSC = *(float *)(param_1 + 0x3cf4);
  eyePlaneTA = *(float *)(param_1 + 0x3d10);
  eyePlaneTD = *(float *)(param_1 + 0x3d1c);
  eyePlaneSA = *(float *)(param_1 + 0x3cec);
  eyePlaneTB = *(float *)(param_1 + 0x3d14);
  eyePlaneTC = *(float *)(param_1 + 0x3d18);
  if (uVar9 <= vertexCursor) {
    return;
  }
  uVar9 = (uVar9 - vertexCursor) + 0xff >> 8;
  do {
    *(float *)(vertexCursor + 0x84) =
         eyePlaneTD * *(float *)(vertexCursor + 0x2c) +
         (eyePlaneTC * *(float *)(vertexCursor + 0x28) +
         (eyePlaneTA * *(float *)(vertexCursor + 0x20) + eyePlaneTB * *(float *)(vertexCursor + 0x24)));
    *(float *)(vertexCursor + 0x80) =
         eyePlaneSD * *(float *)(vertexCursor + 0x2c) +
         (eyePlaneSC * *(float *)(vertexCursor + 0x28) +
         (eyePlaneSA * *(float *)(vertexCursor + 0x20) + eyePlaneSB * *(float *)(vertexCursor + 0x24)));
    vertexCursor = vertexCursor + 0x100;
    uVar9 = uVar9 - 1;
  } while (uVar9 != 0);
  return;
}

/* _gleVtxTextureCoordGenObjectST @ 0xf64dc (140 bytes) */
void _gleVtxTextureCoordGenObjectST(param_1, vertexCursor, vertexCount)
  int param_1;
  uint vertexCursor;
  int vertexCount;
{
  float objectPlaneSD;
  float objectPlaneSB;
  float objectPlaneSC;
  float objectPlaneTA;
  float objectPlaneTD;
  float objectPlaneSA;
  float objectPlaneTB;
  float objectPlaneTC;
  uint uVar9;
  
  uVar9 = vertexCursor + vertexCount * 0x100;
  objectPlaneSD = *(float *)(param_1 + 0x3d08);
  objectPlaneSB = *(float *)(param_1 + 0x3d00);
  objectPlaneSC = *(float *)(param_1 + 0x3d04);
  objectPlaneTA = *(float *)(param_1 + 0x3d20);
  objectPlaneTD = *(float *)(param_1 + 0x3d2c);
  objectPlaneSA = *(float *)(param_1 + 0x3cfc);
  objectPlaneTB = *(float *)(param_1 + 0x3d24);
  objectPlaneTC = *(float *)(param_1 + 0x3d28);
  if (uVar9 <= vertexCursor) {
    return;
  }
  uVar9 = (uVar9 - vertexCursor) + 0xff >> 8;
  do {
    *(float *)(vertexCursor + 0x84) =
         objectPlaneTD * *(float *)(vertexCursor + 0x2c) +
         (objectPlaneTC * *(float *)(vertexCursor + 0x28) +
         (objectPlaneTA * *(float *)(vertexCursor + 0x20) + objectPlaneTB * *(float *)(vertexCursor + 0x24)));
    *(float *)(vertexCursor + 0x80) =
         objectPlaneSD * *(float *)(vertexCursor + 0x2c) +
         (objectPlaneSC * *(float *)(vertexCursor + 0x28) +
         (objectPlaneSA * *(float *)(vertexCursor + 0x20) + objectPlaneSB * *(float *)(vertexCursor + 0x24)));
    vertexCursor = vertexCursor + 0x100;
    uVar9 = uVar9 - 1;
  } while (uVar9 != 0);
  return;
}

/* _gleVtxTextureCoordGenSphereST @ 0xf6568 (92 bytes) */
void _gleVtxTextureCoordGenSphereST(undefined4 param_1,uint vertexCursor,int vertexCount,double fparam_1)
{
  uint vertexEnd;
  
  vertexEnd = vertexCursor + vertexCount * 0x100;
  for (; vertexCursor < vertexEnd; vertexCursor = vertexCursor + 0x100) {
    fparam_1 = (double)((double (*)())_gleSphereGenST)(param_1,vertexCursor + 0x20,vertexCursor + 0x40,vertexCursor + 0x80,fparam_1
                                      );
  }
  return;
}

/* _gleVtxTextureCoordGenReflectST @ 0xf65c4 (168 bytes) */
void _gleVtxTextureCoordGenReflectST(glContext, vertexCursor, vertexCount)
  undefined4 glContext;
  uint vertexCursor;
  int vertexCount;
{
  float fVar1;
  undefined *vectorNormalize;
  uint vertexEnd;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  vertexEnd = vertexCursor + vertexCount * 0x100;
  for (; vertexCursor < vertexEnd; vertexCursor = vertexCursor + 0x100) {
    (**(code **)vectorNormalize)(glContext,vertexCursor + 0x20,&fStack_30);
    fVar1 = *(float *)(vertexCursor + 0x48) * fStack_28 +
            (*(float *)(vertexCursor + 0x40) * fStack_30 + *(float *)(vertexCursor + 0x44) * fStack_2c);
    fVar1 = fVar1 + fVar1;
    *(float *)(vertexCursor + 0x84) = -(*(float *)(vertexCursor + 0x44) * fVar1 - fStack_2c);
    *(float *)(vertexCursor + 0x80) = -(*(float *)(vertexCursor + 0x40) * fVar1 - fStack_30);
  }
  return;
}

/* _gleVtxTextureCoordGenReflectSTR @ 0xf666c (188 bytes) */
void _gleVtxTextureCoordGenReflectSTR(int param_1,uint vertexCursor,int vertexCount,double fparam_1)
{
  float fVar1;
  undefined *vectorNormalize;
  uint vertexEnd;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  vertexEnd = vertexCursor + vertexCount * 0x100;
  for (; vertexCursor < vertexEnd; vertexCursor = vertexCursor + 0x100) {
    fparam_1 = (double)(**(double ( **)(int,int,int,double))vectorNormalize)(param_1, vertexCursor + 0x20, &fStack_30, fparam_1);
    fVar1 = *(float *)(vertexCursor + 0x48) * fStack_28 +
            (*(float *)(vertexCursor + 0x40) * fStack_30 + *(float *)(vertexCursor + 0x44) * fStack_2c);
    fVar1 = fVar1 + fVar1;
    *(float *)(vertexCursor + 0x88) = -(*(float *)(vertexCursor + 0x48) * fVar1 - fStack_28);
    *(float *)(vertexCursor + 0x80) = -(*(float *)(vertexCursor + 0x40) * fVar1 - fStack_30);
    *(float *)(vertexCursor + 0x84) = -(*(float *)(vertexCursor + 0x44) * fVar1 - fStack_2c);
  }
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

/* _gleVtxTextureCoordGenNormalST @ 0xf6728 (60 bytes) */
void _gleVtxTextureCoordGenNormalST(unusedArg1, vertexCursor, vertexCount)
  undefined4 unusedArg1;
  uint vertexCursor;
  int vertexCount;
{
  uint uVar1;
  
  uVar1 = vertexCursor + vertexCount * 0x100;
  if (uVar1 <= vertexCursor) {
    return;
  }
  uVar1 = (uVar1 - vertexCursor) + 0xff >> 8;
  do {
    *(undefined4 *)(vertexCursor + 0x80) = *(undefined4 *)(vertexCursor + 0x40);
    *(undefined4 *)(vertexCursor + 0x84) = *(undefined4 *)(vertexCursor + 0x44);
    vertexCursor = vertexCursor + 0x100;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}

/* _gleVtxTextureCoordGenNormalSTR @ 0xf6764 (80 bytes) */
void _gleVtxTextureCoordGenNormalSTR(param_1, vertexCursor, vertexCount)
  int param_1;
  uint vertexCursor;
  int vertexCount;
{
  uint uVar1;
  
  uVar1 = vertexCursor + vertexCount * 0x100;
  if (vertexCursor < uVar1) {
    uVar1 = (uVar1 - vertexCursor) + 0xff >> 8;
    do {
      *(undefined4 *)(vertexCursor + 0x80) = *(undefined4 *)(vertexCursor + 0x40);
      *(undefined4 *)(vertexCursor + 0x84) = *(undefined4 *)(vertexCursor + 0x44);
      *(undefined4 *)(vertexCursor + 0x88) = *(undefined4 *)(vertexCursor + 0x48);
      vertexCursor = vertexCursor + 0x100;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

/* _gleMultiVtxTextureCoordGenWrapObject @ 0xf67b8 (112 bytes) */
void _gleMultiVtxTextureCoordGenWrapObject(glContext, vertices, vertexCount)
  int glContext;
  undefined4 vertices;
  undefined4 vertexCount;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = glContext + 0x5300;
  do {
    if (*(char *)(iVar2 + 0x1c) != '\0') {
      (**(code **)(iVar2 + 0x14))(glContext,vertices,vertexCount,uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 0xc;
  } while (uVar1 < 8);
  return;
}

/* _gleMultiVtxTextureCoordGenWrapEye @ 0xf6828 (112 bytes) */
void _gleMultiVtxTextureCoordGenWrapEye(glContext, vertices, vertexCount)
  int glContext;
  undefined4 vertices;
  undefined4 vertexCount;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = glContext + 0x5300;
  do {
    if (*(char *)(iVar2 + 0x1c) != '\0') {
      (**(code **)(iVar2 + 0x18))(glContext,vertices,vertexCount,uVar1);
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 0xc;
  } while (uVar1 < 8);
  return;
}

/* _gleMultiVtxTextureCoordGenObjectSlow @ 0xf6898 (552 bytes) */
void _gleMultiVtxTextureCoordGenObjectSlow(glContext, vertexStartThenCursor, vertexCount, texUnit)
  int glContext;
  uint vertexStartThenCursor;
  int vertexCount;
  int texUnit;
{
  float *objectYPtr;
  float *objectXPtr;
  float *objectZPtr;
  float *objectWPtr;
  float objectPlaneSA;
  float objectPlaneQA;
  float objectPlaneRA;
  float objectPlaneTA;
  float objectPlaneSD;
  float objectPlaneQD;
  float objectPlaneRD;
  float objectPlaneTD;
  float objectPlaneSB;
  float objectPlaneQB;
  float objectPlaneRB;
  float objectPlaneTB;
  float objectPlaneSC;
  float objectPlaneQC;
  float objectPlaneRC;
  float objectPlaneTC;
  int unitState;
  int texCoordSlot;
  uint uVar10;
  uint vertexCursor;
  int iVar12;
  uint remaining;
  
  iVar12 = texUnit * 0x94;
  uVar10 = vertexStartThenCursor + vertexCount * 0x100;
  unitState = iVar12 + glContext;
  if ((*(char *)(unitState + 0x3d78) != '\0') && (*(short *)(unitState + 0x3ce8) == 0x2401)) {
    objectPlaneSA = *(float *)(unitState + 0x3cfc);
    objectPlaneSD = *(float *)(unitState + 0x3d08);
    objectPlaneSB = *(float *)(unitState + 0x3d00);
    objectPlaneSC = *(float *)(unitState + 0x3d04);
    if (vertexStartThenCursor < uVar10) {
      remaining = (uVar10 - vertexStartThenCursor) + 0xff >> 8;
      vertexCursor = vertexStartThenCursor;
      do {
        objectYPtr = (float *)(vertexCursor + 0x24);
        texCoordSlot = texUnit * 0x10 + vertexCursor;
        objectXPtr = (float *)(vertexCursor + 0x20);
        objectZPtr = (float *)(vertexCursor + 0x28);
        objectWPtr = (float *)(vertexCursor + 0x2c);
        vertexCursor = vertexCursor + 0x100;
        *(float *)(texCoordSlot + 0x80) =
             objectPlaneSD * *objectWPtr + (objectPlaneSC * *objectZPtr + (objectPlaneSA * *objectXPtr + objectPlaneSB * *objectYPtr));
        remaining = remaining - 1;
      } while (remaining != 0);
    }
  }
  unitState = iVar12 + glContext;
  if ((*(char *)(unitState + 0x3d79) != '\0') && (*(short *)(unitState + 0x3d0c) == 0x2401)) {
    objectPlaneTA = *(float *)(unitState + 0x3d20);
    objectPlaneTD = *(float *)(unitState + 0x3d2c);
    objectPlaneTB = *(float *)(unitState + 0x3d24);
    objectPlaneTC = *(float *)(unitState + 0x3d28);
    if (vertexStartThenCursor < uVar10) {
      remaining = (uVar10 - vertexStartThenCursor) + 0xff >> 8;
      vertexCursor = vertexStartThenCursor;
      do {
        objectYPtr = (float *)(vertexCursor + 0x24);
        texCoordSlot = texUnit * 0x10 + vertexCursor;
        objectXPtr = (float *)(vertexCursor + 0x20);
        objectZPtr = (float *)(vertexCursor + 0x28);
        objectWPtr = (float *)(vertexCursor + 0x2c);
        vertexCursor = vertexCursor + 0x100;
        *(float *)(texCoordSlot + 0x84) =
             objectPlaneTD * *objectWPtr + (objectPlaneTC * *objectZPtr + (objectPlaneTA * *objectXPtr + objectPlaneTB * *objectYPtr));
        remaining = remaining - 1;
      } while (remaining != 0);
    }
  }
  unitState = iVar12 + glContext;
  if ((*(char *)(unitState + 0x3d7a) != '\0') && (*(short *)(unitState + 0x3d30) == 0x2401)) {
    objectPlaneRA = *(float *)(unitState + 0x3d44);
    objectPlaneRD = *(float *)(unitState + 0x3d50);
    objectPlaneRB = *(float *)(unitState + 0x3d48);
    objectPlaneRC = *(float *)(unitState + 0x3d4c);
    if (vertexStartThenCursor < uVar10) {
      remaining = (uVar10 - vertexStartThenCursor) + 0xff >> 8;
      vertexCursor = vertexStartThenCursor;
      do {
        objectYPtr = (float *)(vertexCursor + 0x24);
        texCoordSlot = texUnit * 0x10 + vertexCursor;
        objectXPtr = (float *)(vertexCursor + 0x20);
        objectZPtr = (float *)(vertexCursor + 0x28);
        objectWPtr = (float *)(vertexCursor + 0x2c);
        vertexCursor = vertexCursor + 0x100;
        *(float *)(texCoordSlot + 0x88) =
             objectPlaneRD * *objectWPtr + (objectPlaneRC * *objectZPtr + (objectPlaneRA * *objectXPtr + objectPlaneRB * *objectYPtr));
        remaining = remaining - 1;
      } while (remaining != 0);
    }
    *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  }
  iVar12 = iVar12 + glContext;
  if (*(char *)(iVar12 + 0x3d7b) == '\0') {
    return;
  }
  if (*(short *)(iVar12 + 0x3d54) != 0x2401) {
    return;
  }
  objectPlaneQA = *(float *)(iVar12 + 0x3d68);
  objectPlaneQD = *(float *)(iVar12 + 0x3d74);
  objectPlaneQB = *(float *)(iVar12 + 0x3d6c);
  objectPlaneQC = *(float *)(iVar12 + 0x3d70);
  if (vertexStartThenCursor < uVar10) {
    uVar10 = (uVar10 - vertexStartThenCursor) + 0xff >> 8;
    do {
      objectYPtr = (float *)(vertexStartThenCursor + 0x24);
      texCoordSlot = texUnit * 0x10 + vertexStartThenCursor;
      objectXPtr = (float *)(vertexStartThenCursor + 0x20);
      objectZPtr = (float *)(vertexStartThenCursor + 0x28);
      objectWPtr = (float *)(vertexStartThenCursor + 0x2c);
      vertexStartThenCursor = vertexStartThenCursor + 0x100;
      *(float *)(texCoordSlot + 0x8c) =
           objectPlaneQD * *objectWPtr + (objectPlaneQC * *objectZPtr + (objectPlaneQA * *objectXPtr + objectPlaneQB * *objectYPtr));
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
  }
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 2;
  return;
}

/* _gleMultiVtxTextureCoordGenEyeSlow @ 0xf6ac0 (1408 bytes) */
void _gleMultiVtxTextureCoordGenEyeSlow(int glContext,uint vertexStartThenCursor,int vertexCount,int texUnit,double fparam_1)
{
  undefined4 *normalComponentPtr;
  float *eyeYOrNormalYPtr;
  float *eyeXOrNormalXPtr;
  float *eyeZOrNormalZPtr;
  float *eyeWPtr;
  float normalDotEyeDirection;
  float eyePlaneQA;
  float eyePlaneRA;
  float eyePlaneTA;
  float eyePlaneSA;
  float eyePlaneSD;
  float eyePlaneQD;
  float eyePlaneRD;
  float eyePlaneTD;
  float eyePlaneSB;
  float eyePlaneQB;
  float eyePlaneRB;
  float eyePlaneTB;
  float eyePlaneSC;
  float eyePlaneQC;
  float eyePlaneRC;
  float eyePlaneTC;
  ushort texGenMode;
  undefined *vectorNormalize;
  int unitState;
  int texCoordSlot;
  int unitOffsetThenUnitState;
  uint vertexEndThenRemaining;
  uint vertexCursor;
  uint vertexCursor2;
  uint remaining;
  undefined4 sphereMapS;
  undefined4 sphereMapT;
  float eyeDirectionX;
  float eyeDirectionY;
  float eyeDirectionZ;
  
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  unitOffsetThenUnitState = texUnit * 0x94;
  unitState = unitOffsetThenUnitState + glContext;
  vertexEndThenRemaining = vertexStartThenCursor + vertexCount * 0x100;
  if (*(char *)(unitState + 0x3d78) != '\0') {
    texGenMode = *(ushort *)(unitState + 0x3ce8);
    if (texGenMode == 0x2402) {
      if (vertexStartThenCursor < vertexEndThenRemaining) {
        vertexCursor2 = vertexStartThenCursor;
        do {
          fparam_1 = (double)((double (*)())_gleSphereGenST)(glContext,vertexCursor2 + 0x20,vertexCursor2 + 0x40,&sphereMapS,fparam_1
                                            );
          texCoordSlot = texUnit * 0x10 + vertexCursor2;
          vertexCursor2 = vertexCursor2 + 0x100;
          *(undefined4 *)(texCoordSlot + 0x80) = sphereMapS;
        } while (vertexCursor2 < vertexEndThenRemaining);
      }
    }
    else if (texGenMode < 0x2403) {
      if (texGenMode == 0x2400) {
        eyePlaneSA = *(float *)(unitState + 0x3cec);
        eyePlaneSD = *(float *)(unitState + 0x3cf8);
        eyePlaneSB = *(float *)(unitState + 0x3cf0);
        eyePlaneSC = *(float *)(unitState + 0x3cf4);
        if (vertexStartThenCursor < vertexEndThenRemaining) {
          remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
          vertexCursor = vertexStartThenCursor;
          do {
            eyeYOrNormalYPtr = (float *)(vertexCursor + 0x24);
            texCoordSlot = texUnit * 0x10 + vertexCursor;
            eyeXOrNormalXPtr = (float *)(vertexCursor + 0x20);
            eyeZOrNormalZPtr = (float *)(vertexCursor + 0x28);
            eyeWPtr = (float *)(vertexCursor + 0x2c);
            vertexCursor = vertexCursor + 0x100;
            *(float *)(texCoordSlot + 0x80) =
                 eyePlaneSD * *eyeWPtr + (eyePlaneSC * *eyeZOrNormalZPtr + (eyePlaneSA * *eyeXOrNormalXPtr + eyePlaneSB * *eyeYOrNormalYPtr));
            remaining = remaining - 1;
          } while (remaining != 0);
        }
      }
    }
    else if (texGenMode == 0x8511) {
      if (vertexStartThenCursor < vertexEndThenRemaining) {
        remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
        vertexCursor = vertexStartThenCursor;
        do {
          normalComponentPtr = (undefined4 *)(vertexCursor + 0x40);
          texCoordSlot = texUnit * 0x10 + vertexCursor;
          vertexCursor = vertexCursor + 0x100;
          *(undefined4 *)(texCoordSlot + 0x80) = *normalComponentPtr;
          remaining = remaining - 1;
        } while (remaining != 0);
      }
    }
    else if ((texGenMode == 0x8512) && (vertexStartThenCursor < vertexEndThenRemaining)) {
      vertexCursor2 = vertexStartThenCursor;
      do {
        fparam_1 = (double)(**(double ( **)(int,int,int))vectorNormalize)(glContext, vertexCursor2 + 0x20, &eyeDirectionX);
        eyeYOrNormalYPtr = (float *)(vertexCursor2 + 0x44);
        texCoordSlot = texUnit * 0x10 + vertexCursor2;
        eyeXOrNormalXPtr = (float *)(vertexCursor2 + 0x40);
        eyeZOrNormalZPtr = (float *)(vertexCursor2 + 0x48);
        vertexCursor2 = vertexCursor2 + 0x100;
        normalDotEyeDirection = *eyeZOrNormalZPtr * eyeDirectionZ + (*eyeXOrNormalXPtr * eyeDirectionX + *eyeYOrNormalYPtr * eyeDirectionY);
        *(float *)(texCoordSlot + 0x80) = -(*eyeXOrNormalXPtr * (normalDotEyeDirection + normalDotEyeDirection) - eyeDirectionX);
      } while (vertexCursor2 < vertexEndThenRemaining);
    }
  }
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  unitState = unitOffsetThenUnitState + glContext;
  if (*(char *)(unitState + 0x3d79) != '\0') {
    texGenMode = *(ushort *)(unitState + 0x3d0c);
    if (texGenMode == 0x2402) {
      if (vertexStartThenCursor < vertexEndThenRemaining) {
        vertexCursor2 = vertexStartThenCursor;
        do {
          fparam_1 = (double)((double (*)())_gleSphereGenST)(glContext,vertexCursor2 + 0x20,vertexCursor2 + 0x40,&sphereMapS,fparam_1
                                            );
          texCoordSlot = texUnit * 0x10 + vertexCursor2;
          vertexCursor2 = vertexCursor2 + 0x100;
          *(undefined4 *)(texCoordSlot + 0x84) = sphereMapT;
        } while (vertexCursor2 < vertexEndThenRemaining);
      }
    }
    else if (texGenMode < 0x2403) {
      if (texGenMode == 0x2400) {
        eyePlaneTA = *(float *)(unitState + 0x3d10);
        eyePlaneTD = *(float *)(unitState + 0x3d1c);
        eyePlaneTB = *(float *)(unitState + 0x3d14);
        eyePlaneTC = *(float *)(unitState + 0x3d18);
        if (vertexStartThenCursor < vertexEndThenRemaining) {
          remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
          vertexCursor = vertexStartThenCursor;
          do {
            eyeYOrNormalYPtr = (float *)(vertexCursor + 0x24);
            texCoordSlot = texUnit * 0x10 + vertexCursor;
            eyeXOrNormalXPtr = (float *)(vertexCursor + 0x20);
            eyeZOrNormalZPtr = (float *)(vertexCursor + 0x28);
            eyeWPtr = (float *)(vertexCursor + 0x2c);
            vertexCursor = vertexCursor + 0x100;
            *(float *)(texCoordSlot + 0x84) =
                 eyePlaneTD * *eyeWPtr + (eyePlaneTC * *eyeZOrNormalZPtr + (eyePlaneTA * *eyeXOrNormalXPtr + eyePlaneTB * *eyeYOrNormalYPtr));
            remaining = remaining - 1;
          } while (remaining != 0);
        }
      }
    }
    else if (texGenMode == 0x8511) {
      if (vertexStartThenCursor < vertexEndThenRemaining) {
        remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
        vertexCursor = vertexStartThenCursor;
        do {
          normalComponentPtr = (undefined4 *)(vertexCursor + 0x44);
          texCoordSlot = texUnit * 0x10 + vertexCursor;
          vertexCursor = vertexCursor + 0x100;
          *(undefined4 *)(texCoordSlot + 0x84) = *normalComponentPtr;
          remaining = remaining - 1;
        } while (remaining != 0);
      }
    }
    else if ((texGenMode == 0x8512) && (vertexStartThenCursor < vertexEndThenRemaining)) {
      vertexCursor2 = vertexStartThenCursor;
      do {
        (**(code **)vectorNormalize)(glContext,vertexCursor2 + 0x20,&eyeDirectionX);
        eyeYOrNormalYPtr = (float *)(vertexCursor2 + 0x44);
        texCoordSlot = texUnit * 0x10 + vertexCursor2;
        eyeXOrNormalXPtr = (float *)(vertexCursor2 + 0x40);
        eyeZOrNormalZPtr = (float *)(vertexCursor2 + 0x48);
        vertexCursor2 = vertexCursor2 + 0x100;
        normalDotEyeDirection = *eyeZOrNormalZPtr * eyeDirectionZ + (*eyeXOrNormalXPtr * eyeDirectionX + *eyeYOrNormalYPtr * eyeDirectionY);
        *(float *)(texCoordSlot + 0x84) = -(*eyeYOrNormalYPtr * (normalDotEyeDirection + normalDotEyeDirection) - eyeDirectionY);
      } while (vertexCursor2 < vertexEndThenRemaining);
    }
  }
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  unitState = unitOffsetThenUnitState + glContext;
  if (*(char *)(unitState + 0x3d7a) != '\0') {
    texGenMode = *(ushort *)(unitState + 0x3d30);
    if (texGenMode == 0x8511) {
      if (vertexStartThenCursor < vertexEndThenRemaining) {
        remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
        vertexCursor = vertexStartThenCursor;
        do {
          normalComponentPtr = (undefined4 *)(vertexCursor + 0x48);
          texCoordSlot = texUnit * 0x10 + vertexCursor;
          vertexCursor = vertexCursor + 0x100;
          *(undefined4 *)(texCoordSlot + 0x88) = *normalComponentPtr;
          remaining = remaining - 1;
        } while (remaining != 0);
      }
    }
    else if (texGenMode < 0x8512) {
      if (texGenMode == 0x2400) {
        eyePlaneRA = *(float *)(unitState + 0x3d34);
        eyePlaneRD = *(float *)(unitState + 0x3d40);
        eyePlaneRB = *(float *)(unitState + 0x3d38);
        eyePlaneRC = *(float *)(unitState + 0x3d3c);
        if (vertexStartThenCursor < vertexEndThenRemaining) {
          remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
          vertexCursor = vertexStartThenCursor;
          do {
            eyeYOrNormalYPtr = (float *)(vertexCursor + 0x24);
            texCoordSlot = texUnit * 0x10 + vertexCursor;
            eyeXOrNormalXPtr = (float *)(vertexCursor + 0x20);
            eyeZOrNormalZPtr = (float *)(vertexCursor + 0x28);
            eyeWPtr = (float *)(vertexCursor + 0x2c);
            vertexCursor = vertexCursor + 0x100;
            *(float *)(texCoordSlot + 0x88) =
                 eyePlaneRD * *eyeWPtr + (eyePlaneRC * *eyeZOrNormalZPtr + (eyePlaneRA * *eyeXOrNormalXPtr + eyePlaneRB * *eyeYOrNormalYPtr));
            remaining = remaining - 1;
          } while (remaining != 0);
        }
      }
    }
    else if ((texGenMode == 0x8512) && (vertexStartThenCursor < vertexEndThenRemaining)) {
      vertexCursor2 = vertexStartThenCursor;
      do {
        (**(code **)vectorNormalize)(glContext,vertexCursor2 + 0x20,&eyeDirectionX);
        eyeYOrNormalYPtr = (float *)(vertexCursor2 + 0x44);
        texCoordSlot = texUnit * 0x10 + vertexCursor2;
        eyeXOrNormalXPtr = (float *)(vertexCursor2 + 0x40);
        eyeZOrNormalZPtr = (float *)(vertexCursor2 + 0x48);
        vertexCursor2 = vertexCursor2 + 0x100;
        normalDotEyeDirection = *eyeZOrNormalZPtr * eyeDirectionZ + (*eyeXOrNormalXPtr * eyeDirectionX + *eyeYOrNormalYPtr * eyeDirectionY);
        *(float *)(texCoordSlot + 0x88) = -(*eyeZOrNormalZPtr * (normalDotEyeDirection + normalDotEyeDirection) - eyeDirectionZ);
      } while (vertexCursor2 < vertexEndThenRemaining);
    }
    *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  }
  unitOffsetThenUnitState = unitOffsetThenUnitState + glContext;
  if (*(char *)(unitOffsetThenUnitState + 0x3d7b) != '\0') {
    if (*(short *)(unitOffsetThenUnitState + 0x3d54) == 0x2400) {
      eyePlaneQA = *(float *)(unitOffsetThenUnitState + 0x3d58);
      eyePlaneQD = *(float *)(unitOffsetThenUnitState + 0x3d64);
      eyePlaneQB = *(float *)(unitOffsetThenUnitState + 0x3d5c);
      eyePlaneQC = *(float *)(unitOffsetThenUnitState + 0x3d60);
      if (vertexStartThenCursor < vertexEndThenRemaining) {
        vertexEndThenRemaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
        do {
          eyeYOrNormalYPtr = (float *)(vertexStartThenCursor + 0x24);
          texCoordSlot = texUnit * 0x10 + vertexStartThenCursor;
          eyeXOrNormalXPtr = (float *)(vertexStartThenCursor + 0x20);
          eyeZOrNormalZPtr = (float *)(vertexStartThenCursor + 0x28);
          eyeWPtr = (float *)(vertexStartThenCursor + 0x2c);
          vertexStartThenCursor = vertexStartThenCursor + 0x100;
          *(float *)(texCoordSlot + 0x8c) =
               eyePlaneQD * *eyeWPtr + (eyePlaneQC * *eyeZOrNormalZPtr + (eyePlaneQA * *eyeXOrNormalXPtr + eyePlaneQB * *eyeYOrNormalYPtr));
          vertexEndThenRemaining = vertexEndThenRemaining - 1;
        } while (vertexEndThenRemaining != 0);
      }
    }
    *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 2;
  }
  return;
}

/* _gleMultiVtxTextureCoordGenEyeST @ 0xf7040 (156 bytes) */
void _gleMultiVtxTextureCoordGenEyeST(param_1, vertexCursor, vertexCount, texUnit)
  int param_1;
  uint vertexCursor;
  int vertexCount;
  int texUnit;
{
  float eyePlaneTA;
  float eyePlaneSD;
  float eyePlaneSB;
  float eyePlaneSC;
  float eyePlaneTD;
  float eyePlaneSA;
  float eyePlaneTB;
  float eyePlaneTC;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  int iVar14;
  int texCoordSlot;
  
  uVar13 = vertexCursor + vertexCount * 0x100;
  iVar14 = param_1 + texUnit * 0x94;
  eyePlaneTA = *(float *)(iVar14 + 0x3d10);
  eyePlaneSD = *(float *)(iVar14 + 0x3cf8);
  eyePlaneSB = *(float *)(iVar14 + 0x3cf0);
  eyePlaneSC = *(float *)(iVar14 + 0x3cf4);
  eyePlaneTD = *(float *)(iVar14 + 0x3d1c);
  eyePlaneSA = *(float *)(iVar14 + 0x3cec);
  eyePlaneTB = *(float *)(iVar14 + 0x3d14);
  eyePlaneTC = *(float *)(iVar14 + 0x3d18);
  if (uVar13 <= vertexCursor) {
    return;
  }
  uVar13 = (uVar13 - vertexCursor) + 0xff >> 8;
  do {
    fVar9 = *(float *)(vertexCursor + 0x24);
    texCoordSlot = texUnit * 0x10 + vertexCursor;
    fVar10 = *(float *)(vertexCursor + 0x20);
    fVar11 = *(float *)(vertexCursor + 0x28);
    fVar12 = *(float *)(vertexCursor + 0x2c);
    vertexCursor = vertexCursor + 0x100;
    *(float *)(texCoordSlot + 0x84) = eyePlaneTD * fVar12 + (eyePlaneTC * fVar11 + (eyePlaneTA * fVar10 + eyePlaneTB * fVar9));
    *(float *)(texCoordSlot + 0x80) = eyePlaneSD * fVar12 + (eyePlaneSC * fVar11 + (eyePlaneSA * fVar10 + eyePlaneSB * fVar9));
    uVar13 = uVar13 - 1;
  } while (uVar13 != 0);
  return;
}

/* _gleMultiVtxTextureCoordGenObjectST @ 0xf70dc (156 bytes) */
void _gleMultiVtxTextureCoordGenObjectST(param_1, vertexCursor, vertexCount, texUnit)
  int param_1;
  uint vertexCursor;
  int vertexCount;
  int texUnit;
{
  float objectPlaneTA;
  float objectPlaneSD;
  float objectPlaneSB;
  float objectPlaneSC;
  float objectPlaneTD;
  float objectPlaneSA;
  float objectPlaneTB;
  float objectPlaneTC;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  int iVar14;
  int texCoordSlot;
  
  uVar13 = vertexCursor + vertexCount * 0x100;
  iVar14 = param_1 + texUnit * 0x94;
  objectPlaneTA = *(float *)(iVar14 + 0x3d20);
  objectPlaneSD = *(float *)(iVar14 + 0x3d08);
  objectPlaneSB = *(float *)(iVar14 + 0x3d00);
  objectPlaneSC = *(float *)(iVar14 + 0x3d04);
  objectPlaneTD = *(float *)(iVar14 + 0x3d2c);
  objectPlaneSA = *(float *)(iVar14 + 0x3cfc);
  objectPlaneTB = *(float *)(iVar14 + 0x3d24);
  objectPlaneTC = *(float *)(iVar14 + 0x3d28);
  if (uVar13 <= vertexCursor) {
    return;
  }
  uVar13 = (uVar13 - vertexCursor) + 0xff >> 8;
  do {
    fVar9 = *(float *)(vertexCursor + 0x24);
    texCoordSlot = texUnit * 0x10 + vertexCursor;
    fVar10 = *(float *)(vertexCursor + 0x20);
    fVar11 = *(float *)(vertexCursor + 0x28);
    fVar12 = *(float *)(vertexCursor + 0x2c);
    vertexCursor = vertexCursor + 0x100;
    *(float *)(texCoordSlot + 0x84) = objectPlaneTD * fVar12 + (objectPlaneTC * fVar11 + (objectPlaneTA * fVar10 + objectPlaneTB * fVar9));
    *(float *)(texCoordSlot + 0x80) = objectPlaneSD * fVar12 + (objectPlaneSC * fVar11 + (objectPlaneSA * fVar10 + objectPlaneSB * fVar9));
    uVar13 = uVar13 - 1;
  } while (uVar13 != 0);
  return;
}

/* _gleMultiVtxTextureCoordGenSphereST @ 0xf7178 (108 bytes) */
void _gleMultiVtxTextureCoordGenSphereST(undefined4 param_1,uint vertexCursor,int vertexCount,int param_4,double fparam_1)
{
  int iVar1;
  int iVar2;
  uint vertexEnd;
  int iVar4;
  
  vertexEnd = vertexCursor + vertexCount * 0x100;
  if (vertexCursor < vertexEnd) {
    iVar4 = vertexCursor + param_4 * 0x10 + 0x80;
    do {
      iVar1 = vertexCursor + 0x20;
      iVar2 = vertexCursor + 0x40;
      vertexCursor = vertexCursor + 0x100;
      fparam_1 = (double)((double (*)())_gleSphereGenST)(param_1,iVar1,iVar2,iVar4,fparam_1);
      iVar4 = iVar4 + 0x100;
    } while (vertexCursor < vertexEnd);
  }
  return;
}

/* _gleMultiVtxTextureCoordGenReflectST @ 0xf71e4 (184 bytes) */
void _gleMultiVtxTextureCoordGenReflectST(glContext, vertexCursor, vertexCount, param_4)
  undefined4 glContext;
  uint vertexCursor;
  int vertexCount;
  int param_4;
{
  float *pfVar1;
  float fVar2;
  undefined *vectorNormalize;
  int texCoordSlot;
  uint vertexEnd;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  vertexEnd = vertexCursor + vertexCount * 0x100;
  if (vertexCursor < vertexEnd) {
    do {
      (**(code **)vectorNormalize)(glContext,vertexCursor + 0x20,&fStack_30);
      texCoordSlot = param_4 * 0x10 + vertexCursor;
      fVar2 = *(float *)(vertexCursor + 0x48) * fStack_28 +
              (*(float *)(vertexCursor + 0x40) * fStack_30 + *(float *)(vertexCursor + 0x44) * fStack_2c);
      fVar2 = fVar2 + fVar2;
      *(float *)(texCoordSlot + 0x80) = -(*(float *)(vertexCursor + 0x40) * fVar2 - fStack_30);
      pfVar1 = (float *)(vertexCursor + 0x44);
      vertexCursor = vertexCursor + 0x100;
      *(float *)(texCoordSlot + 0x84) = -(*pfVar1 * fVar2 - fStack_2c);
    } while (vertexCursor < vertexEnd);
  }
  return;
}

/* _gleMultiVtxTextureCoordGenReflectSTR @ 0xf729c (212 bytes) */
void _gleMultiVtxTextureCoordGenReflectSTR(int glContext,uint vertexCursor,int vertexCount,int texUnit,double forwardedF1)
{
  float *normalZPtr;
  float normalDotEyeDirection;
  float doubledNormalDotEyeDirection;
  undefined *vectorNormalize;
  int texCoordSlot;
  uint vertexEnd;
  float eyeDirectionX;
  float eyeDirectionY;
  float eyeDirectionZ;
  
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  vertexEnd = vertexCursor + vertexCount * 0x100;
  if (vertexCursor < vertexEnd) {
    do {
      forwardedF1 = (double)(**(double ( **)(int,int,int,double))vectorNormalize)(glContext, vertexCursor + 0x20, &eyeDirectionX, forwardedF1);
      texCoordSlot = texUnit * 0x10 + vertexCursor;
      normalDotEyeDirection = *(float *)(vertexCursor + 0x48) * eyeDirectionZ +
              (*(float *)(vertexCursor + 0x40) * eyeDirectionX + *(float *)(vertexCursor + 0x44) * eyeDirectionY);
      doubledNormalDotEyeDirection = normalDotEyeDirection + normalDotEyeDirection;
      *(float *)(texCoordSlot + 0x80) = -(*(float *)(vertexCursor + 0x40) * doubledNormalDotEyeDirection - eyeDirectionX);
      *(float *)(texCoordSlot + 0x84) = -(*(float *)(vertexCursor + 0x44) * doubledNormalDotEyeDirection - eyeDirectionY);
      normalZPtr = (float *)(vertexCursor + 0x48);
      vertexCursor = vertexCursor + 0x100;
      *(float *)(texCoordSlot + 0x88) = -(*normalZPtr * doubledNormalDotEyeDirection - eyeDirectionZ);
    } while (vertexCursor < vertexEnd);
  }
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  return;
}

/* _gleMultiVtxTextureCoordGenNormalST @ 0xf7370 (68 bytes) */
void _gleMultiVtxTextureCoordGenNormalST(unusedArg1, vertexCursor, vertexCount, param_4)
  undefined4 unusedArg1;
  uint vertexCursor;
  int vertexCount;
  int param_4;
{
  undefined4 *puVar1;
  uint uVar2;
  int texCoordSlot;
  
  uVar2 = vertexCursor + vertexCount * 0x100;
  if (uVar2 <= vertexCursor) {
    return;
  }
  uVar2 = (uVar2 - vertexCursor) + 0xff >> 8;
  do {
    texCoordSlot = param_4 * 0x10 + vertexCursor;
    *(undefined4 *)(texCoordSlot + 0x80) = *(undefined4 *)(vertexCursor + 0x40);
    puVar1 = (undefined4 *)(vertexCursor + 0x44);
    vertexCursor = vertexCursor + 0x100;
    *(undefined4 *)(texCoordSlot + 0x84) = *puVar1;
    uVar2 = uVar2 - 1;
  } while (uVar2 != 0);
  return;
}

