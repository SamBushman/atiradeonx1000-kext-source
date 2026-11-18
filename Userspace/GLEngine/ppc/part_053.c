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
  int vertexWriteCursor;
  int iVar4;
  int vertexSizeThenSavedByteCount;
  uint remainingQwords;
  undefined8 savedVertexBytes [64];
  int bufferVertexCapacity [5];
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
    (**(code **)(glContext + 0x4a0c))(glContext);
    return;
  }
  vertexSizeThenSavedByteCount = (int)*(short *)(glContext + 0x487c);
  switch(*(undefined2 *)(glContext + 0x4a10)) {
  case 2:
    if (*(char *)(glContext + 0x4a18) == '\0') {
      iVar4 = 0;
      iVar2 = *(int *)(glContext + 0x4854);
      iVar1 = *(int *)(glContext + 0x4868);
      if (0 < vertexSizeThenSavedByteCount) {
        remainingQwords = vertexSizeThenSavedByteCount + 7U >> 3;
        do {
          *(undefined8 *)(iVar2 + -0x100 + iVar4) = *(undefined8 *)(iVar1 + iVar4);
          iVar4 = iVar4 + 8;
          remainingQwords = remainingQwords - 1;
        } while (remainingQwords != 0);
      }
    }
  case 3:
    iVar2 = 0;
    iVar1 = *(int *)(glContext + 0x4858);
    *(undefined1 *)(glContext + 0x4a18) = 1;
    if (0 < vertexSizeThenSavedByteCount) {
      remainingQwords = vertexSizeThenSavedByteCount + 7U >> 3;
      do {
        *(undefined8 *)((int)savedVertexBytes + iVar2) = *(undefined8 *)((iVar1 - vertexSizeThenSavedByteCount) + iVar2);
        iVar2 = iVar2 + 8;
        remainingQwords = remainingQwords - 1;
      } while (remainingQwords != 0);
    }
    break;
  case 5:
  case 8:
    iVar2 = vertexSizeThenSavedByteCount * 2;
    iVar4 = 0;
    vertexWriteCursor = *(int *)(glContext + 0x4858);
    iVar1 = vertexSizeThenSavedByteCount * -2;
    vertexSizeThenSavedByteCount = iVar2;
    if (0 < iVar2) {
      remainingQwords = iVar2 + 7U >> 3;
      do {
        *(undefined8 *)((int)savedVertexBytes + iVar4) = *(undefined8 *)(vertexWriteCursor + iVar1 + iVar4);
        iVar4 = iVar4 + 8;
        remainingQwords = remainingQwords - 1;
      } while (remainingQwords != 0);
    }
    break;
  case 6:
    iVar2 = 0;
    iVar4 = *(int *)(glContext + 0x4858);
    iVar1 = *(int *)(glContext + 0x4868);
    if (0 < vertexSizeThenSavedByteCount) {
      do {
        *(undefined8 *)((int)savedVertexBytes + iVar2) = *(undefined8 *)(iVar1 + iVar2);
        iVar2 = iVar2 + 8;
      } while (iVar2 < vertexSizeThenSavedByteCount);
    }
    iVar2 = 0;
    if (0 < vertexSizeThenSavedByteCount) {
      remainingQwords = vertexSizeThenSavedByteCount + 7U >> 3;
      do {
        *(undefined8 *)((int)savedVertexBytes + iVar2 + vertexSizeThenSavedByteCount) = *(undefined8 *)((iVar4 - vertexSizeThenSavedByteCount) + iVar2);
        iVar2 = iVar2 + 8;
        remainingQwords = remainingQwords - 1;
      } while (remainingQwords != 0);
    }
    break;
  case 9:
    iVar2 = 0;
    iVar4 = *(int *)(glContext + 0x4858);
    iVar1 = *(int *)(glContext + 0x4868);
    if (0 < vertexSizeThenSavedByteCount) {
      do {
        *(undefined8 *)((int)savedVertexBytes + iVar2) = *(undefined8 *)(iVar1 + iVar2);
        iVar2 = iVar2 + 8;
      } while (iVar2 < vertexSizeThenSavedByteCount);
    }
    iVar2 = 0;
    iVar4 = iVar4 - vertexSizeThenSavedByteCount;
    if (0 < vertexSizeThenSavedByteCount) {
      remainingQwords = vertexSizeThenSavedByteCount + 7U >> 3;
      do {
        *(undefined8 *)((int)savedVertexBytes + iVar2 + vertexSizeThenSavedByteCount) = *(undefined8 *)(iVar4 + iVar2);
        iVar2 = iVar2 + 8;
        remainingQwords = remainingQwords - 1;
      } while (remainingQwords != 0);
    }
    if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
      *(undefined1 *)(iVar4 + *(short *)(glContext + 0x487e)) = 0;
    }
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  bufferVertexCapacity[0] = *(int *)(glContext + 0x4a14);
  iVar2 = (**(code **)(glContext + 0x46e8))
                    (*(undefined4 *)(glContext + 0x4688),(int)*(short *)(glContext + 0x4a10),bufferVertexCapacity);
  *(int *)(glContext + 0x4868) = iVar2;
  *(int *)(glContext + 0x485c) = iVar2 + *(short *)(glContext + 0x487c) * bufferVertexCapacity[0];
  switch(*(undefined2 *)(glContext + 0x4a10)) {
  default:
    goto switchD_000f37d0_caseD_0;
  case 2:
  case 3:
    iVar1 = 0;
    if (0 < vertexSizeThenSavedByteCount) {
      remainingQwords = vertexSizeThenSavedByteCount + 7U >> 3;
      do {
        *(undefined8 *)(iVar2 + iVar1) = *(undefined8 *)((int)savedVertexBytes + iVar1);
        iVar1 = iVar1 + 8;
        remainingQwords = remainingQwords - 1;
      } while (remainingQwords != 0);
    }
    break;
  case 9:
    if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
      *(undefined1 *)((int)savedVertexBytes + (int)*(short *)(glContext + 0x487e)) = 0;
    }
  case 6:
    vertexSizeThenSavedByteCount = vertexSizeThenSavedByteCount << 1;
  case 5:
  case 8:
    iVar1 = 0;
    if (0 < vertexSizeThenSavedByteCount) {
      remainingQwords = vertexSizeThenSavedByteCount + 7U >> 3;
      do {
        *(undefined8 *)(iVar2 + iVar1) = *(undefined8 *)((int)savedVertexBytes + iVar1);
        iVar1 = iVar1 + 8;
        remainingQwords = remainingQwords - 1;
      } while (remainingQwords != 0);
    }
  }
  iVar2 = iVar2 + vertexSizeThenSavedByteCount;
switchD_000f37d0_caseD_0:
  *(int *)(glContext + 0x4858) = iVar2;
  *(undefined4 *)(glContext + 0x486c) = 0;
  return;
}

/* _gleBeginPrimitiveTCLRDirtyFunc @ 0xf38a8 (176 bytes) */
void _gleBeginPrimitiveTCLRDirtyFunc(glContext)
  int glContext;
{
  short vertexStride;
  undefined *renderPrimitiveTCLFunc;
  int vertexBuffer;
  int vertexCountArg [5];
  
  vertexCountArg[0] = *(int *)(glContext + 0x4a14);
  *(undefined1 *)(glContext + 0x4a18) = 0;
  if (vertexCountArg[0] == 0) {
    vertexStride = *(short *)(glContext + 0x4880);
  }
  else {
    vertexStride = *(short *)(glContext + 0x4882);
  }
  vertexBuffer = (**(code **)(glContext + 0x46e8))
                    (*(undefined4 *)(glContext + 0x4688),(int)*(short *)(glContext + 0x4a10),vertexCountArg);
  *(undefined4 *)(glContext + 0x486c) = 0;
  renderPrimitiveTCLFunc = PTR__gleRenderPrimitiveTCLFunc_001113cc;
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushPrimitiveTCLRDirtyFunc_001113c8;
  *(int *)(glContext + 0x485c) = vertexBuffer + vertexStride * vertexCountArg[0];
  *(undefined **)(glContext + 0x4a08) = renderPrimitiveTCLFunc;
  *(undefined2 *)(glContext + 0x4a12) = *(undefined2 *)(glContext + 0x4a10);
  *(short *)(glContext + 0x487c) = vertexStride;
  *(int *)(glContext + 0x4868) = vertexBuffer;
  *(int *)(glContext + 0x4858) = vertexBuffer;
  return;
}

/* _gleUpdateScissorData @ 0xf3958 (44 bytes) */
void _gleUpdateScissorData(glContext)
  int glContext;
{
  if (*(int *)(glContext + 0x3188) < 0) {
    *(undefined4 *)(glContext + 0x3188) = 0;
  }
  if (-1 < *(int *)(glContext + 0x318c)) {
    return;
  }
  *(undefined4 *)(glContext + 0x318c) = 0;
  return;
}

/* _gleSelectHit @ 0xf3984 (8 bytes) */
double _gleSelectHit(glContext, vertex)
  undefined4 glContext;
  int vertex;
{
  ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(vertex + 8));
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
void _gleSelectPoints(glContext, vertexCursor, vertexCount)
  undefined4 glContext;
  uint vertexCursor;
  int vertexCount;
{
  uint vertexEnd;
  
  vertexEnd = vertexCursor + vertexCount * 0x100;
  for (; vertexCursor < vertexEnd; vertexCursor = vertexCursor + 0x100) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(vertexCursor + 8));
  }
  return;
}

/* _gleSelectPointsPtr @ 0xf3b34 (88 bytes) */
void _gleSelectPointsPtr(glContext, pointerCursor, pointCount)
  undefined4 glContext;
  int *pointerCursor;
  int pointCount;
{
  int *pointerEnd;
  
  pointerEnd = pointerCursor + pointCount;
  for (; pointerCursor < pointerEnd; pointerCursor = pointerCursor + 1) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(*pointerCursor + 8));
  }
  return;
}

/* _gleSelectLines @ 0xf3b8c (100 bytes) */
void _gleSelectLines(glContext, vertexCursor, vertexCount)
  undefined4 glContext;
  uint vertexCursor;
  int vertexCount;
{
  int vertexEnd;
  
  vertexEnd = vertexCursor + vertexCount * 0x100;
  for (; vertexCursor < vertexEnd - 0x100U; vertexCursor = vertexCursor + 0x200) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(vertexCursor + 8));
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(vertexCursor + 0x108));
  }
  return;
}

/* _gleSelectLineStrip @ 0xf3bf0 (100 bytes) */
void _gleSelectLineStrip(glContext, vertexCursor, vertexCount)
  undefined4 glContext;
  uint vertexCursor;
  int vertexCount;
{
  int vertexEnd;
  
  vertexEnd = vertexCursor + vertexCount * 0x100;
  for (; vertexCursor < vertexEnd - 0x100U; vertexCursor = vertexCursor + 0x100) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(vertexCursor + 8));
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(vertexCursor + 0x108));
  }
  return;
}

/* _gleSelectLineLoop_body @ 0xf3c60 (112 bytes) */
void _gleSelectLineLoop_body(glContext, firstVertex, vertexEnd)
  undefined4 glContext;
  uint firstVertex;
  int vertexEnd;
{
  uint vertexCursor;
  
  for (vertexCursor = firstVertex; vertexCursor < vertexEnd - 0x100U; vertexCursor = vertexCursor + 0x100) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(vertexCursor + 8));
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(vertexCursor + 0x108));
  }
  ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(vertexCursor + 8));
  ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(firstVertex + 8));
  return;
}

/* _gleSelectLinesPtr @ 0xf3cd0 (108 bytes) */
void _gleSelectLinesPtr(glContext, listCursor, listCount)
  undefined4 glContext;
  int *listCursor;
  int listCount;
{
  int *lastEntry;
  
  lastEntry = listCursor + listCount + -1;
  for (; listCursor < lastEntry; listCursor = listCursor + 2) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(*listCursor + 8));
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(listCursor[1] + 8));
  }
  return;
}

/* _gleSelectPolygon @ 0xf3d3c (84 bytes) */
void _gleSelectPolygon(glContext, vertexCursor, vertexCount)
  undefined4 glContext;
  uint vertexCursor;
  int vertexCount;
{
  uint vertexEnd;
  
  vertexEnd = vertexCursor + vertexCount * 0x100;
  for (; vertexCursor < vertexEnd; vertexCursor = vertexCursor + 0x100) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(vertexCursor + 8));
  }
  return;
}

/* _gleSelectPolygonPtr @ 0xf3d90 (88 bytes) */
double _gleSelectPolygonPtr(glContext, listCursor, listCount)
  undefined4 glContext;
  int *listCursor;
  int listCount;
{
  int *listEnd;
  
  listEnd = listCursor + listCount;
  for (; listCursor < listEnd; listCursor = listCursor + 1) {
    ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(*listCursor + 8));
  }
  return;
}

/* _gleSelectTriangles @ 0xf3de8 (116 bytes) */
double _gleSelectTriangles(glContext, vertexCursor, vertexCount)
  undefined4 glContext;
  uint vertexCursor;
  int vertexCount;
{
  int verticesConsumed;
  uint primitiveVertex;
  
  verticesConsumed = 0;
  if (-1 < vertexCount + -3) {
    do {
      for (primitiveVertex = vertexCursor; primitiveVertex < vertexCursor + 0x300; primitiveVertex = primitiveVertex + 0x100) {
        ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(primitiveVertex + 8));
      }
      verticesConsumed = verticesConsumed + 3;
      vertexCursor = vertexCursor + 0x300;
    } while (verticesConsumed <= vertexCount + -3);
  }
  return;
}

/* _gleSelectTriangleFan @ 0xf3e5c (124 bytes) */
double _gleSelectTriangleFan(glContext, hubVertex, vertexCursor, vertexCount)
  undefined4 glContext;
  int hubVertex;
  uint vertexCursor;
  int vertexCount;
{
  int trianglesRemaining;
  uint triangleVertexCursor;
  
  if (-1 < vertexCount + -2) {
    trianglesRemaining = vertexCount + -1;
    do {
      ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(hubVertex + 8));
      for (triangleVertexCursor = vertexCursor; triangleVertexCursor < vertexCursor + 0x200; triangleVertexCursor = triangleVertexCursor + 0x100) {
        ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(triangleVertexCursor + 8));
      }
      trianglesRemaining = trianglesRemaining + -1;
      vertexCursor = vertexCursor + 0x100;
    } while (trianglesRemaining != 0);
  }
  return;
}

/* _gleSelectTriangleStrip @ 0xf3ed8 (108 bytes) */
double _gleSelectTriangleStrip(glContext, vertexCursor, vertexCount)
  undefined4 glContext;
  uint vertexCursor;
  int vertexCount;
{
  int trianglesRemaining;
  uint triangleVertexCursor;
  
  if (-1 < vertexCount + -3) {
    trianglesRemaining = vertexCount + -2;
    do {
      for (triangleVertexCursor = vertexCursor; triangleVertexCursor < vertexCursor + 0x300; triangleVertexCursor = triangleVertexCursor + 0x100) {
        ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(triangleVertexCursor + 8));
      }
      trianglesRemaining = trianglesRemaining + -1;
      vertexCursor = vertexCursor + 0x100;
    } while (trianglesRemaining != 0);
  }
  return;
}

/* _gleSelectQuads @ 0xf3f44 (116 bytes) */
double _gleSelectQuads(glContext, vertexCursor, vertexCount)
  undefined4 glContext;
  uint vertexCursor;
  int vertexCount;
{
  int quadVertexIndex;
  uint quadVertex;
  
  quadVertexIndex = 0;
  if (-1 < vertexCount + -4) {
    do {
      for (quadVertex = vertexCursor; quadVertex < vertexCursor + 0x400; quadVertex = quadVertex + 0x100) {
        ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(quadVertex + 8));
      }
      quadVertexIndex = quadVertexIndex + 4;
      vertexCursor = vertexCursor + 0x400;
    } while (quadVertexIndex <= vertexCount + -4);
  }
  return;
}

/* _gleSelectQuadStrip @ 0xf3fb8 (116 bytes) */
double _gleSelectQuadStrip(glContext, vertexCursor, vertexCount)
  undefined4 glContext;
  uint vertexCursor;
  int vertexCount;
{
  int verticesConsumed;
  uint primitiveVertex;
  
  verticesConsumed = 0;
  if (-1 < vertexCount + -4) {
    do {
      for (primitiveVertex = vertexCursor; primitiveVertex < vertexCursor + 0x400; primitiveVertex = primitiveVertex + 0x100) {
        ((void (*)())_gleSelectHitRecord)(glContext,(double)*(float *)(primitiveVertex + 8));
      }
      verticesConsumed = verticesConsumed + 2;
      vertexCursor = vertexCursor + 0x200;
    } while (verticesConsumed <= vertexCount + -4);
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
  int parameterMaskBase;
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
    parameterMaskBase = ((int)parameterIndex >> 5) * 4 + shaderData;
    *(uint *)(parameterMaskBase + 8) = *(uint *)(parameterMaskBase + 8) | 1 << (parameterIndex & 0x1f);
switchD_000f44b0_caseD_0:
    parameterIndex = parameterIndex + 1;
    if (parameterCount <= (int)parameterIndex) {
      return;
    }
  } while( true );
}

/* _gleShaderParse @ 0xf48d8 (244 bytes) */
void _gleShaderParse(glContext, shaderObject)
  int glContext;
  int shaderObject;
{
  int iVar1;
  undefined1 compileSucceeded;
  undefined4 uVar2;
  char *infoLog;
  undefined4 sourceStrings [4];
  
  if (*(char *)(shaderObject + 0x24) != '\0') {
    iVar1 = *(int *)(shaderObject + 0x30);
    sourceStrings[0] = *(undefined4 *)(shaderObject + 0x2c);
    *(undefined1 *)(shaderObject + 0x25) = 0;
    if (iVar1 == 0) {
      iVar1 = _ShConstructCompiler(*(int *)(shaderObject + 0x20) != 0x8b31,0);
      *(int *)(shaderObject + 0x30) = iVar1;
    }
    compileSucceeded = _ShCompile(iVar1,sourceStrings,1,*(undefined4 *)(glContext + 0x7594),
                       *(undefined4 *)(glContext + 0x7598));
    *(undefined1 *)(shaderObject + 0x24) = 0;
    *(undefined1 *)(shaderObject + 0x25) = compileSucceeded;
    uVar2 = _ShGetInfoLog(*(undefined4 *)(shaderObject + 0x30));
    uVar2 = _strlen(uVar2);
    *(undefined4 *)(shaderObject + 0x1c) = uVar2;
    if (*(int *)(shaderObject + 0x18) != 0) {
      _free(*(int *)(shaderObject + 0x18));
    }
    *(undefined4 *)(shaderObject + 0x18) = 0;
    if (*(int *)(shaderObject + 0x1c) != 0) {
      iVar1 = _malloc(*(int *)(shaderObject + 0x1c) + 1);
      *(int *)(shaderObject + 0x18) = iVar1;
      if (iVar1 != 0) {
        infoLog = (char *)_ShGetInfoLog(*(undefined4 *)(shaderObject + 0x30));
        _strncpy(*(char **)(shaderObject + 0x18),infoLog,*(size_t *)(shaderObject + 0x1c));
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
  int blockSizeShift;
  
  if (internalformat < 0x83f4) {
    if (0x83f1 < internalformat) goto LAB_000f4a24;
    if (internalformat < 0x83f0) goto LAB_000f4a2c;
    blockSizeShift = 3;
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
    blockSizeShift = 4;
  }
  if (border == 0) {
    if (imageSize == (width + 3 >> 2) * (height + 3 >> 2) * depth << blockSizeShift) {
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
  int rendererInfo;
  int imageCheckResult;
  int texture;
  uint innerWidth;
  
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
  innerWidth = width + border * -2;
  if (-1 < (int)innerWidth) {
    if ((innerWidth & innerWidth - 1) == 0) {
      rendererInfo = *(int *)(glContext + 0x468c);
    }
    else {
      rendererInfo = *(int *)(glContext + 0x468c);
      if ((*(uint *)(rendererInfo + 0x124) & 0x80000) == 0) goto LAB_000f4b58;
    }
    if ((int)innerWidth <= (int)(uint)*(ushort *)(rendererInfo + 0xbc)) {
      imageCheckResult = _gleCheckTexImageArgs(glContext,level,format,type,internalformat,border,1,1);
      if (imageCheckResult != 0) {
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
  int rendererInfoThenArgsCheckResult;
  int texture;
  uint innerWidth;
  
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
  innerWidth = width + border * -2;
  if (-1 < (int)innerWidth) {
    if ((innerWidth & innerWidth - 1) == 0) {
      rendererInfoThenArgsCheckResult = *(int *)(glContext + 0x468c);
    }
    else {
      rendererInfoThenArgsCheckResult = *(int *)(glContext + 0x468c);
      if ((*(uint *)(rendererInfoThenArgsCheckResult + 0x124) & 0x80000) == 0) goto LAB_000f4c6c;
    }
    if ((int)innerWidth <= (int)(uint)*(ushort *)(rendererInfoThenArgsCheckResult + 0xbc)) {
      rendererInfoThenArgsCheckResult = _gleCheckCopyTexImageArgs(glContext,level,internalformat,border,1,1);
      if (rendererInfoThenArgsCheckResult != 0) {
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
  undefined4 glErrorCode;
  int colorTable;
  int texImageArgsCheck;
  
  colorTable = _gleLookUpColorTable(glContext,target);
  if (colorTable == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x500;
  }
  else {
    texImageArgsCheck = _gleCheckTexImageArgs(glContext,0,format,type,internalformat,0,0,0);
    if (texImageArgsCheck == 0) {
      return 0;
    }
    if (((int)width < 0) || ((width & width - 1) != 0)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0;
      }
      glErrorCode = 0x501;
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
      glErrorCode = 0x8031;
    }
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _gleCheckCopyColorTableArgs @ 0xf4dac (212 bytes) */
int _gleCheckCopyColorTableArgs(glContext, target, internalformat, width)
  int glContext;
  undefined4 target;
  undefined4 internalformat;
  uint width;
{
  undefined4 glErrorCode;
  int colorTable;
  int texArgsResult;
  
  colorTable = _gleLookUpNonProxyColorTable(glContext,target);
  if (colorTable == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x500;
  }
  else {
    texArgsResult = _gleCheckCopyTexImageArgs(glContext,0,internalformat,0,0,0);
    if (texArgsResult == 0) {
      return 0;
    }
    if (((int)width < 0) || ((width & width - 1) != 0)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0;
      }
      glErrorCode = 0x501;
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
      glErrorCode = 0x8031;
    }
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
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
  ushort textureKind;
  uint maxTextureSize;
  int texture;
  int argsValid;
  uint innerHeight;
  uint innerWidth;
  
  texture = _gleLookUpTexture2D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
    goto LAB_000f4f94;
  }
  innerHeight = height + border * -2;
  innerWidth = width + border * -2;
  textureKind = *(ushort *)(texture + 0x24) & 0xf;
  if (textureKind == 2) {
    if (((-1 < (int)innerWidth) &&
        (maxTextureSize = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xc0), (int)innerWidth <= (int)maxTextureSize)) &&
       (-1 < (int)innerHeight)) {
LAB_000f4f80:
      if ((int)innerHeight <= (int)maxTextureSize) {
LAB_000f4fa0:
        argsValid = ((int (*)())_gleCheckCompressedTexImageArgs)(glContext,level,internalformat,border,innerWidth,innerHeight,1,imageSize);
        if (argsValid != 0) {
          return texture;
        }
        return 0;
      }
    }
  }
  else {
    if (textureKind < 3) {
      if ((*(ushort *)(texture + 0x24) & 0xf) != 0) goto LAB_000f4fa0;
      if ((innerWidth != innerHeight) ||
         ((int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xc2) < (int)innerHeight))
      goto LAB_000f4f84;
    }
    else if (textureKind != 3) goto LAB_000f4fa0;
    if (((-1 < (int)innerWidth) &&
        ((((innerWidth & innerWidth - 1) == 0 &&
          (maxTextureSize = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xbc), (int)innerWidth <= (int)maxTextureSize))
         && (-1 < (int)innerHeight)))) && ((innerHeight & innerHeight - 1) == 0)) goto LAB_000f4f80;
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
  uint maxTexture3DSize;
  int texture;
  int argsCheckResult;
  uint innerHeight;
  uint innerWidth;
  
  texture = _gleLookUpTexture3D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
    innerHeight = height + border * -2;
    innerWidth = width + border * -2;
    if (((*(ushort *)(texture + 0x24) & 0xf) != 1) ||
       ((((((-1 < (int)innerWidth && ((innerWidth & innerWidth - 1) == 0)) &&
           (maxTexture3DSize = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xbe), (int)innerWidth <= (int)maxTexture3DSize))
          && ((-1 < (int)innerHeight && ((innerHeight & innerHeight - 1) == 0)))) &&
         (((int)innerHeight <= (int)maxTexture3DSize && ((-1 < (int)depth && ((depth & depth - 1) == 0)))))) &&
        ((int)depth <= (int)maxTexture3DSize)))) {
      argsCheckResult = ((int (*)())_gleCheckCompressedTexImageArgs)(glContext,level,internalformat,border,innerWidth,innerHeight,depth,imageSize);
      if (argsCheckResult != 0) {
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
  bool levelInRange;
  undefined4 errorCode;
  int levelSlotThenRangeResult;
  int texture;
  
  texture = _gleLookUpNonProxyTexture1D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
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
    levelSlotThenRangeResult = texture + level * 0x18;
    if ((*(byte *)(levelSlotThenRangeResult + 0xcf) & 0x20) != 0) {
      if (((*(uint *)(glContext + 0x3410) & 1) != 0) && (*(short *)(glContext + 13000) == -0x7fea)) {
        width = (width - *(int *)(glContext + 0x32d0)) + 1;
      }
      levelSlotThenRangeResult = _gleCheckTexSubImageRange
                        (glContext,levelSlotThenRangeResult + 0xc4,xoffset,width,(uint)*(ushort *)(levelSlotThenRangeResult + 200));
      if (levelSlotThenRangeResult != 0) {
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
  bool levelInRange;
  undefined4 errorCode;
  int readBufferExtentX;
  int xRangeValid;
  int texture;
  int readBufferExtentY;
  int levelImageThenYRangeValid;
  
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
  levelImageThenYRangeValid = texture + 0xc4 + level * 0x18;
  if (target - 0x8515U < 6) {
    levelImageThenYRangeValid = texture + 0xc4 + target * 0x168 + level * 0x18 + -0xbb2588;
  }
  if (((*(byte *)(levelImageThenYRangeValid + 0xb) & 0x20) == 0) ||
     ((*(short *)(levelImageThenYRangeValid + 0x12) == 0 &&
      (((((width & 3) != 0 && (width != *(ushort *)(levelImageThenYRangeValid + 4))) ||
        (((height & 3) != 0 && (height != *(ushort *)(levelImageThenYRangeValid + 6))))) ||
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
    readBufferExtentY = *(int *)(glContext + 0x3354);
    readBufferExtentX = *(int *)(glContext + 0x3350);
  }
  else {
    if (*(short *)(glContext + 0x3308) != -0x7fea) goto LAB_000f550c;
    readBufferExtentY = *(int *)(glContext + 0x3314);
    readBufferExtentX = *(int *)(glContext + 0x3310);
  }
  width = (width - readBufferExtentX) + 1;
  height = (height - readBufferExtentY) + 1;
LAB_000f550c:
  xRangeValid = _gleCheckTexSubImageRange(glContext,levelImageThenYRangeValid,xoffset,width,(uint)*(ushort *)(levelImageThenYRangeValid + 4));
  if (xRangeValid == 0) {
    return 0;
  }
  levelImageThenYRangeValid = _gleCheckTexSubImageRange(glContext,levelImageThenYRangeValid,yoffset,height,(uint)*(ushort *)(levelImageThenYRangeValid + 6));
  if (levelImageThenYRangeValid != 0) {
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
  int argsCheckThenLevelSlotThenZRangeResult;
  int rangeCheckResult;
  int textureLevel;
  
  texture = _gleLookUpNonProxyTexture3D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
    if ((format != 0x1902) || (*(short *)(texture + 0x26) == 0x1902)) {
      argsCheckThenLevelSlotThenZRangeResult = _gleCheckTexSubImageArgs(glContext,level,format,type);
      if (argsCheckThenLevelSlotThenZRangeResult == 0) {
        return 0;
      }
      argsCheckThenLevelSlotThenZRangeResult = texture + level * 0x18;
      textureLevel = argsCheckThenLevelSlotThenZRangeResult + 0xc4;
      if ((*(byte *)(argsCheckThenLevelSlotThenZRangeResult + 0xcf) & 0x20) != 0) {
        rangeCheckResult = _gleCheckTexSubImageRange
                          (glContext,textureLevel,xoffset,width,(uint)*(ushort *)(argsCheckThenLevelSlotThenZRangeResult + 200));
        if (rangeCheckResult == 0) {
          return 0;
        }
        rangeCheckResult = _gleCheckTexSubImageRange
                          (glContext,textureLevel,yoffset,height,(uint)*(ushort *)(argsCheckThenLevelSlotThenZRangeResult + 0xca));
        if (rangeCheckResult != 0) {
          argsCheckThenLevelSlotThenZRangeResult = _gleCheckTexSubImageRange
                            (glContext,textureLevel,zoffset,depth,(uint)*(ushort *)(argsCheckThenLevelSlotThenZRangeResult + 0xcc));
          if (argsCheckThenLevelSlotThenZRangeResult != 0) {
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
  bool levelInRange;
  undefined4 errorCode;
  int levelSlotThenZRangeResult;
  int texture;
  int rangeCheckResult;
  int textureLevel;
  
  texture = _gleLookUpNonProxyTexture3D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
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
    levelSlotThenZRangeResult = texture + level * 0x18;
    textureLevel = levelSlotThenZRangeResult + 0xc4;
    if ((*(byte *)(levelSlotThenZRangeResult + 0xcf) & 0x20) != 0) {
      rangeCheckResult = _gleCheckTexSubImageRange
                        (glContext,textureLevel,xoffset,width,(uint)*(ushort *)(levelSlotThenZRangeResult + 200));
      if (rangeCheckResult == 0) {
        return 0;
      }
      rangeCheckResult = _gleCheckTexSubImageRange
                        (glContext,textureLevel,yoffset,height,(uint)*(ushort *)(levelSlotThenZRangeResult + 0xca));
      if (rangeCheckResult != 0) {
        levelSlotThenZRangeResult = _gleCheckTexSubImageRange
                          (glContext,textureLevel,zoffset,depth,(uint)*(ushort *)(levelSlotThenZRangeResult + 0xcc));
        if (levelSlotThenZRangeResult != 0) {
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
  int argsCheckThenTextureLevelThenZRangeResult;
  int rangeCheckResult;
  
  texture = _gleLookUpNonProxyTexture3D(glContext,target);
  if (texture == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
    argsCheckThenTextureLevelThenZRangeResult = ((int (*)())_gleCheckCompressedTexImageArgs)(glContext,level,format,0,width,height,depth,imageSize);
    if (argsCheckThenTextureLevelThenZRangeResult == 0) {
      return 0;
    }
    argsCheckThenTextureLevelThenZRangeResult = texture + 0xc4 + level * 0x18;
    if (target - 0x8515U < 6) {
      argsCheckThenTextureLevelThenZRangeResult = texture + 0xc4 + target * 0x168 + level * 0x18 + -0xbb2588;
    }
    if (*(int *)(argsCheckThenTextureLevelThenZRangeResult + 0x14) != 0) {
      rangeCheckResult = ((int (*)())_gleCheckCompressedTexSubImageRange)(glContext,argsCheckThenTextureLevelThenZRangeResult,xoffset,width,(uint)*(ushort *)(argsCheckThenTextureLevelThenZRangeResult + 4),3);
      if (rangeCheckResult == 0) {
        return 0;
      }
      rangeCheckResult = ((int (*)())_gleCheckCompressedTexSubImageRange)(glContext,argsCheckThenTextureLevelThenZRangeResult,yoffset,height,(uint)*(ushort *)(argsCheckThenTextureLevelThenZRangeResult + 6),3);
      if (rangeCheckResult != 0) {
        argsCheckThenTextureLevelThenZRangeResult = ((int (*)())_gleCheckCompressedTexSubImageRange)(glContext,argsCheckThenTextureLevelThenZRangeResult,zoffset,depth,(uint)*(ushort *)(argsCheckThenTextureLevelThenZRangeResult + 8),0);
        if (argsCheckThenTextureLevelThenZRangeResult != 0) {
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
  int checkResult;
  
  colorTable = _gleLookUpNonProxyColorTable(glContext,target);
  if (colorTable == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
    checkResult = _gleCheckTexSubImageArgs(glContext,0,format,type);
    if (checkResult == 0) {
      return 0;
    }
    if (*(int *)(colorTable + 0xc0) != 0) {
      checkResult = _gleCheckTexSubImageRange
                        (glContext,colorTable + 0xac,start,count,(uint)*(ushort *)(colorTable + 0xb0));
      if (checkResult != 0) {
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
  int rangeCheckResult;
  
  colorTable = _gleLookUpNonProxyColorTable(glContext,target);
  if (colorTable == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    errorCode = 0x500;
  }
  else {
    if (*(int *)(colorTable + 0xc0) != 0) {
      rangeCheckResult = _gleCheckTexSubImageRange
                        (glContext,colorTable + 0xac,start,count,(uint)*(ushort *)(colorTable + 0xb0));
      if (rangeCheckResult != 0) {
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
void _gleVtxTextureCoordGenObjectSlow(glContext, vertexStartThenCursor, vertexCount)
  int glContext;
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
  uint vertexEndThenRemaining;
  uint remaining;
  
  vertexEndThenRemaining = vertexStartThenCursor + vertexCount * 0x100;
  if ((*(char *)(glContext + 0x3d78) != '\0') && (*(short *)(glContext + 0x3ce8) == 0x2401)) {
    objectPlaneSD = *(float *)(glContext + 0x3d08);
    objectPlaneSA = *(float *)(glContext + 0x3cfc);
    objectPlaneSB = *(float *)(glContext + 0x3d00);
    objectPlaneSC = *(float *)(glContext + 0x3d04);
    if (vertexStartThenCursor < vertexEndThenRemaining) {
      remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
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
  if ((*(char *)(glContext + 0x3d79) != '\0') && (*(short *)(glContext + 0x3d0c) == 0x2401)) {
    objectPlaneTD = *(float *)(glContext + 0x3d2c);
    objectPlaneTA = *(float *)(glContext + 0x3d20);
    objectPlaneTB = *(float *)(glContext + 0x3d24);
    objectPlaneTC = *(float *)(glContext + 0x3d28);
    if (vertexStartThenCursor < vertexEndThenRemaining) {
      remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
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
  if ((*(char *)(glContext + 0x3d7a) != '\0') && (*(short *)(glContext + 0x3d30) == 0x2401)) {
    objectPlaneRD = *(float *)(glContext + 0x3d50);
    objectPlaneRA = *(float *)(glContext + 0x3d44);
    objectPlaneRB = *(float *)(glContext + 0x3d48);
    objectPlaneRC = *(float *)(glContext + 0x3d4c);
    if (vertexStartThenCursor < vertexEndThenRemaining) {
      remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
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
    *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  }
  if (*(char *)(glContext + 0x3d7b) == '\0') {
    return;
  }
  if (*(short *)(glContext + 0x3d54) != 0x2401) {
    return;
  }
  objectPlaneQD = *(float *)(glContext + 0x3d74);
  objectPlaneQA = *(float *)(glContext + 0x3d68);
  objectPlaneQB = *(float *)(glContext + 0x3d6c);
  objectPlaneQC = *(float *)(glContext + 0x3d70);
  if (vertexStartThenCursor < vertexEndThenRemaining) {
    vertexEndThenRemaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
    do {
      *(float *)(vertexStartThenCursor + 0x8c) =
           objectPlaneQD * *(float *)(vertexStartThenCursor + 0x2c) +
           (objectPlaneQC * *(float *)(vertexStartThenCursor + 0x28) +
           (objectPlaneQA * *(float *)(vertexStartThenCursor + 0x20) + objectPlaneQB * *(float *)(vertexStartThenCursor + 0x24)));
      vertexStartThenCursor = vertexStartThenCursor + 0x100;
      vertexEndThenRemaining = vertexEndThenRemaining - 1;
    } while (vertexEndThenRemaining != 0);
  }
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  return;
}

/* _gleVtxTextureCoordGenEyeSlow @ 0xf5f48 (1288 bytes) */
void _gleVtxTextureCoordGenEyeSlow(int glContext,uint vertexStartThenCursor,int vertexCount,double forwardedFloatArg1ThenCalleeResult)
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
        forwardedFloatArg1ThenCalleeResult = (double)((double (*)())_gleSphereGenST)(glContext,vertexCursor2 + 0x20,vertexCursor2 + 0x40,&sphereMapS,forwardedFloatArg1ThenCalleeResult);
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
        forwardedFloatArg1ThenCalleeResult = (double)(**(double ( **)(int,int,int))vectorNormalize)(glContext, vertexCursor2 + 0x20, &eyeDirectionX);
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
        forwardedFloatArg1ThenCalleeResult = (double)((double (*)())_gleSphereGenST)(glContext,vertexCursor2 + 0x20,vertexCursor2 + 0x40,&sphereMapS,forwardedFloatArg1ThenCalleeResult);
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
void _gleVtxTextureCoordGenEyeST(glContext, vertexCursor, vertexCount)
  int glContext;
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
  uint vertexEndThenRemaining;
  
  vertexEndThenRemaining = vertexCursor + vertexCount * 0x100;
  eyePlaneSD = *(float *)(glContext + 0x3cf8);
  eyePlaneSB = *(float *)(glContext + 0x3cf0);
  eyePlaneSC = *(float *)(glContext + 0x3cf4);
  eyePlaneTA = *(float *)(glContext + 0x3d10);
  eyePlaneTD = *(float *)(glContext + 0x3d1c);
  eyePlaneSA = *(float *)(glContext + 0x3cec);
  eyePlaneTB = *(float *)(glContext + 0x3d14);
  eyePlaneTC = *(float *)(glContext + 0x3d18);
  if (vertexEndThenRemaining <= vertexCursor) {
    return;
  }
  vertexEndThenRemaining = (vertexEndThenRemaining - vertexCursor) + 0xff >> 8;
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
    vertexEndThenRemaining = vertexEndThenRemaining - 1;
  } while (vertexEndThenRemaining != 0);
  return;
}

/* _gleVtxTextureCoordGenObjectST @ 0xf64dc (140 bytes) */
void _gleVtxTextureCoordGenObjectST(glContext, vertexCursor, vertexCount)
  int glContext;
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
  uint vertexEndThenRemaining;
  
  vertexEndThenRemaining = vertexCursor + vertexCount * 0x100;
  objectPlaneSD = *(float *)(glContext + 0x3d08);
  objectPlaneSB = *(float *)(glContext + 0x3d00);
  objectPlaneSC = *(float *)(glContext + 0x3d04);
  objectPlaneTA = *(float *)(glContext + 0x3d20);
  objectPlaneTD = *(float *)(glContext + 0x3d2c);
  objectPlaneSA = *(float *)(glContext + 0x3cfc);
  objectPlaneTB = *(float *)(glContext + 0x3d24);
  objectPlaneTC = *(float *)(glContext + 0x3d28);
  if (vertexEndThenRemaining <= vertexCursor) {
    return;
  }
  vertexEndThenRemaining = (vertexEndThenRemaining - vertexCursor) + 0xff >> 8;
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
    vertexEndThenRemaining = vertexEndThenRemaining - 1;
  } while (vertexEndThenRemaining != 0);
  return;
}

/* _gleVtxTextureCoordGenSphereST @ 0xf6568 (92 bytes) */
void _gleVtxTextureCoordGenSphereST(undefined4 glContext,uint vertexCursor,int vertexCount,double forwardedFloatArg1)
{
  uint vertexEnd;
  
  vertexEnd = vertexCursor + vertexCount * 0x100;
  for (; vertexCursor < vertexEnd; vertexCursor = vertexCursor + 0x100) {
    forwardedFloatArg1 = (double)((double (*)())_gleSphereGenST)(glContext,vertexCursor + 0x20,vertexCursor + 0x40,vertexCursor + 0x80,forwardedFloatArg1
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
  float dotThenTwiceDot;
  undefined *vectorNormalize;
  uint vertexEnd;
  float normalizedEyeX;
  float normalizedEyeY;
  float normalizedEyeZ;
  
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  vertexEnd = vertexCursor + vertexCount * 0x100;
  for (; vertexCursor < vertexEnd; vertexCursor = vertexCursor + 0x100) {
    (**(code **)vectorNormalize)(glContext,vertexCursor + 0x20,&normalizedEyeX);
    dotThenTwiceDot = *(float *)(vertexCursor + 0x48) * normalizedEyeZ +
            (*(float *)(vertexCursor + 0x40) * normalizedEyeX + *(float *)(vertexCursor + 0x44) * normalizedEyeY);
    dotThenTwiceDot = dotThenTwiceDot + dotThenTwiceDot;
    *(float *)(vertexCursor + 0x84) = -(*(float *)(vertexCursor + 0x44) * dotThenTwiceDot - normalizedEyeY);
    *(float *)(vertexCursor + 0x80) = -(*(float *)(vertexCursor + 0x40) * dotThenTwiceDot - normalizedEyeX);
  }
  return;
}

/* _gleVtxTextureCoordGenReflectSTR @ 0xf666c (188 bytes) */
void _gleVtxTextureCoordGenReflectSTR(int glContext,uint vertexCursor,int vertexCount,double forwardedFloatArg1ThenCalleeResult)
{
  float dotThenTwiceDot;
  undefined *vectorNormalize;
  uint vertexEnd;
  float normalizedEyeX;
  float normalizedEyeY;
  float normalizedEyeZ;
  
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  vertexEnd = vertexCursor + vertexCount * 0x100;
  for (; vertexCursor < vertexEnd; vertexCursor = vertexCursor + 0x100) {
    forwardedFloatArg1ThenCalleeResult = (double)(**(double ( **)(int,int,int,double))vectorNormalize)(glContext, vertexCursor + 0x20, &normalizedEyeX, forwardedFloatArg1ThenCalleeResult);
    dotThenTwiceDot = *(float *)(vertexCursor + 0x48) * normalizedEyeZ +
            (*(float *)(vertexCursor + 0x40) * normalizedEyeX + *(float *)(vertexCursor + 0x44) * normalizedEyeY);
    dotThenTwiceDot = dotThenTwiceDot + dotThenTwiceDot;
    *(float *)(vertexCursor + 0x88) = -(*(float *)(vertexCursor + 0x48) * dotThenTwiceDot - normalizedEyeZ);
    *(float *)(vertexCursor + 0x80) = -(*(float *)(vertexCursor + 0x40) * dotThenTwiceDot - normalizedEyeX);
    *(float *)(vertexCursor + 0x84) = -(*(float *)(vertexCursor + 0x44) * dotThenTwiceDot - normalizedEyeY);
  }
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  return;
}

/* _gleVtxTextureCoordGenNormalST @ 0xf6728 (60 bytes) */
void _gleVtxTextureCoordGenNormalST(unusedArg1, vertexCursor, vertexCount)
  undefined4 unusedArg1;
  uint vertexCursor;
  int vertexCount;
{
  uint vertexEndThenRemaining;
  
  vertexEndThenRemaining = vertexCursor + vertexCount * 0x100;
  if (vertexEndThenRemaining <= vertexCursor) {
    return;
  }
  vertexEndThenRemaining = (vertexEndThenRemaining - vertexCursor) + 0xff >> 8;
  do {
    *(undefined4 *)(vertexCursor + 0x80) = *(undefined4 *)(vertexCursor + 0x40);
    *(undefined4 *)(vertexCursor + 0x84) = *(undefined4 *)(vertexCursor + 0x44);
    vertexCursor = vertexCursor + 0x100;
    vertexEndThenRemaining = vertexEndThenRemaining - 1;
  } while (vertexEndThenRemaining != 0);
  return;
}

/* _gleVtxTextureCoordGenNormalSTR @ 0xf6764 (80 bytes) */
void _gleVtxTextureCoordGenNormalSTR(glContext, vertexCursor, vertexCount)
  int glContext;
  uint vertexCursor;
  int vertexCount;
{
  uint vertexEndThenRemaining;
  
  vertexEndThenRemaining = vertexCursor + vertexCount * 0x100;
  if (vertexCursor < vertexEndThenRemaining) {
    vertexEndThenRemaining = (vertexEndThenRemaining - vertexCursor) + 0xff >> 8;
    do {
      *(undefined4 *)(vertexCursor + 0x80) = *(undefined4 *)(vertexCursor + 0x40);
      *(undefined4 *)(vertexCursor + 0x84) = *(undefined4 *)(vertexCursor + 0x44);
      *(undefined4 *)(vertexCursor + 0x88) = *(undefined4 *)(vertexCursor + 0x48);
      vertexCursor = vertexCursor + 0x100;
      vertexEndThenRemaining = vertexEndThenRemaining - 1;
    } while (vertexEndThenRemaining != 0);
  }
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  return;
}

/* _gleMultiVtxTextureCoordGenWrapObject @ 0xf67b8 (112 bytes) */
void _gleMultiVtxTextureCoordGenWrapObject(glContext, vertices, vertexCount)
  int glContext;
  undefined4 vertices;
  undefined4 vertexCount;
{
  uint texUnit;
  int unitRecordCursor;
  
  texUnit = 0;
  unitRecordCursor = glContext + 0x5300;
  do {
    if (*(char *)(unitRecordCursor + 0x1c) != '\0') {
      (**(code **)(unitRecordCursor + 0x14))(glContext,vertices,vertexCount,texUnit);
    }
    texUnit = texUnit + 1;
    unitRecordCursor = unitRecordCursor + 0xc;
  } while (texUnit < 8);
  return;
}

/* _gleMultiVtxTextureCoordGenWrapEye @ 0xf6828 (112 bytes) */
void _gleMultiVtxTextureCoordGenWrapEye(glContext, vertices, vertexCount)
  int glContext;
  undefined4 vertices;
  undefined4 vertexCount;
{
  uint textureUnit;
  int texGenRecord;
  
  textureUnit = 0;
  texGenRecord = glContext + 0x5300;
  do {
    if (*(char *)(texGenRecord + 0x1c) != '\0') {
      (**(code **)(texGenRecord + 0x18))(glContext,vertices,vertexCount,textureUnit);
    }
    textureUnit = textureUnit + 1;
    texGenRecord = texGenRecord + 0xc;
  } while (textureUnit < 8);
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
  uint vertexEndThenRemaining;
  uint vertexCursor;
  int unitByteOffsetThenStateAddress;
  uint remaining;
  
  unitByteOffsetThenStateAddress = texUnit * 0x94;
  vertexEndThenRemaining = vertexStartThenCursor + vertexCount * 0x100;
  unitState = unitByteOffsetThenStateAddress + glContext;
  if ((*(char *)(unitState + 0x3d78) != '\0') && (*(short *)(unitState + 0x3ce8) == 0x2401)) {
    objectPlaneSA = *(float *)(unitState + 0x3cfc);
    objectPlaneSD = *(float *)(unitState + 0x3d08);
    objectPlaneSB = *(float *)(unitState + 0x3d00);
    objectPlaneSC = *(float *)(unitState + 0x3d04);
    if (vertexStartThenCursor < vertexEndThenRemaining) {
      remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
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
  unitState = unitByteOffsetThenStateAddress + glContext;
  if ((*(char *)(unitState + 0x3d79) != '\0') && (*(short *)(unitState + 0x3d0c) == 0x2401)) {
    objectPlaneTA = *(float *)(unitState + 0x3d20);
    objectPlaneTD = *(float *)(unitState + 0x3d2c);
    objectPlaneTB = *(float *)(unitState + 0x3d24);
    objectPlaneTC = *(float *)(unitState + 0x3d28);
    if (vertexStartThenCursor < vertexEndThenRemaining) {
      remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
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
  unitState = unitByteOffsetThenStateAddress + glContext;
  if ((*(char *)(unitState + 0x3d7a) != '\0') && (*(short *)(unitState + 0x3d30) == 0x2401)) {
    objectPlaneRA = *(float *)(unitState + 0x3d44);
    objectPlaneRD = *(float *)(unitState + 0x3d50);
    objectPlaneRB = *(float *)(unitState + 0x3d48);
    objectPlaneRC = *(float *)(unitState + 0x3d4c);
    if (vertexStartThenCursor < vertexEndThenRemaining) {
      remaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
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
  unitByteOffsetThenStateAddress = unitByteOffsetThenStateAddress + glContext;
  if (*(char *)(unitByteOffsetThenStateAddress + 0x3d7b) == '\0') {
    return;
  }
  if (*(short *)(unitByteOffsetThenStateAddress + 0x3d54) != 0x2401) {
    return;
  }
  objectPlaneQA = *(float *)(unitByteOffsetThenStateAddress + 0x3d68);
  objectPlaneQD = *(float *)(unitByteOffsetThenStateAddress + 0x3d74);
  objectPlaneQB = *(float *)(unitByteOffsetThenStateAddress + 0x3d6c);
  objectPlaneQC = *(float *)(unitByteOffsetThenStateAddress + 0x3d70);
  if (vertexStartThenCursor < vertexEndThenRemaining) {
    vertexEndThenRemaining = (vertexEndThenRemaining - vertexStartThenCursor) + 0xff >> 8;
    do {
      objectYPtr = (float *)(vertexStartThenCursor + 0x24);
      texCoordSlot = texUnit * 0x10 + vertexStartThenCursor;
      objectXPtr = (float *)(vertexStartThenCursor + 0x20);
      objectZPtr = (float *)(vertexStartThenCursor + 0x28);
      objectWPtr = (float *)(vertexStartThenCursor + 0x2c);
      vertexStartThenCursor = vertexStartThenCursor + 0x100;
      *(float *)(texCoordSlot + 0x8c) =
           objectPlaneQD * *objectWPtr + (objectPlaneQC * *objectZPtr + (objectPlaneQA * *objectXPtr + objectPlaneQB * *objectYPtr));
      vertexEndThenRemaining = vertexEndThenRemaining - 1;
    } while (vertexEndThenRemaining != 0);
  }
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 2;
  return;
}

/* _gleMultiVtxTextureCoordGenEyeSlow @ 0xf6ac0 (1408 bytes) */
void _gleMultiVtxTextureCoordGenEyeSlow(int glContext,uint vertexStartThenCursor,int vertexCount,int texUnit,double forwardedFloatArg1)
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
          forwardedFloatArg1 = (double)((double (*)())_gleSphereGenST)(glContext,vertexCursor2 + 0x20,vertexCursor2 + 0x40,&sphereMapS,forwardedFloatArg1
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
        forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))vectorNormalize)(glContext, vertexCursor2 + 0x20, &eyeDirectionX);
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
          forwardedFloatArg1 = (double)((double (*)())_gleSphereGenST)(glContext,vertexCursor2 + 0x20,vertexCursor2 + 0x40,&sphereMapS,forwardedFloatArg1
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
void _gleMultiVtxTextureCoordGenObjectST(glContext, vertexCursor, vertexCount, texUnit)
  int glContext;
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
  float objectY;
  float objectX;
  float objectZ;
  float objectW;
  uint vertexEndThenRemainingVertices;
  int texUnitRecord;
  int texCoordSlot;
  
  vertexEndThenRemainingVertices = vertexCursor + vertexCount * 0x100;
  texUnitRecord = glContext + texUnit * 0x94;
  objectPlaneTA = *(float *)(texUnitRecord + 0x3d20);
  objectPlaneSD = *(float *)(texUnitRecord + 0x3d08);
  objectPlaneSB = *(float *)(texUnitRecord + 0x3d00);
  objectPlaneSC = *(float *)(texUnitRecord + 0x3d04);
  objectPlaneTD = *(float *)(texUnitRecord + 0x3d2c);
  objectPlaneSA = *(float *)(texUnitRecord + 0x3cfc);
  objectPlaneTB = *(float *)(texUnitRecord + 0x3d24);
  objectPlaneTC = *(float *)(texUnitRecord + 0x3d28);
  if (vertexEndThenRemainingVertices <= vertexCursor) {
    return;
  }
  vertexEndThenRemainingVertices = (vertexEndThenRemainingVertices - vertexCursor) + 0xff >> 8;
  do {
    objectY = *(float *)(vertexCursor + 0x24);
    texCoordSlot = texUnit * 0x10 + vertexCursor;
    objectX = *(float *)(vertexCursor + 0x20);
    objectZ = *(float *)(vertexCursor + 0x28);
    objectW = *(float *)(vertexCursor + 0x2c);
    vertexCursor = vertexCursor + 0x100;
    *(float *)(texCoordSlot + 0x84) = objectPlaneTD * objectW + (objectPlaneTC * objectZ + (objectPlaneTA * objectX + objectPlaneTB * objectY));
    *(float *)(texCoordSlot + 0x80) = objectPlaneSD * objectW + (objectPlaneSC * objectZ + (objectPlaneSA * objectX + objectPlaneSB * objectY));
    vertexEndThenRemainingVertices = vertexEndThenRemainingVertices - 1;
  } while (vertexEndThenRemainingVertices != 0);
  return;
}

/* _gleMultiVtxTextureCoordGenSphereST @ 0xf7178 (108 bytes) */
void _gleMultiVtxTextureCoordGenSphereST(undefined4 glContext,uint vertexCursor,int vertexCount,int textureUnit,double forwardedFloatArg1ThenCalleeResult)
{
  int eyePosition;
  int normal;
  uint vertexEnd;
  int stOut;
  
  vertexEnd = vertexCursor + vertexCount * 0x100;
  if (vertexCursor < vertexEnd) {
    stOut = vertexCursor + textureUnit * 0x10 + 0x80;
    do {
      eyePosition = vertexCursor + 0x20;
      normal = vertexCursor + 0x40;
      vertexCursor = vertexCursor + 0x100;
      forwardedFloatArg1ThenCalleeResult = (double)((double (*)())_gleSphereGenST)(glContext,eyePosition,normal,stOut,forwardedFloatArg1ThenCalleeResult);
      stOut = stOut + 0x100;
    } while (vertexCursor < vertexEnd);
  }
  return;
}

/* _gleMultiVtxTextureCoordGenReflectST @ 0xf71e4 (184 bytes) */
void _gleMultiVtxTextureCoordGenReflectST(glContext, vertexCursor, vertexCount, textureUnit)
  undefined4 glContext;
  uint vertexCursor;
  int vertexCount;
  int textureUnit;
{
  float *normalYPtr;
  float dotThenTwiceDot;
  undefined *vectorNormalize;
  int texCoordSlot;
  uint vertexEnd;
  float normalizedEyeX;
  float normalizedEyeY;
  float normalizedEyeZ;
  
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  vertexEnd = vertexCursor + vertexCount * 0x100;
  if (vertexCursor < vertexEnd) {
    do {
      (**(code **)vectorNormalize)(glContext,vertexCursor + 0x20,&normalizedEyeX);
      texCoordSlot = textureUnit * 0x10 + vertexCursor;
      dotThenTwiceDot = *(float *)(vertexCursor + 0x48) * normalizedEyeZ +
              (*(float *)(vertexCursor + 0x40) * normalizedEyeX + *(float *)(vertexCursor + 0x44) * normalizedEyeY);
      dotThenTwiceDot = dotThenTwiceDot + dotThenTwiceDot;
      *(float *)(texCoordSlot + 0x80) = -(*(float *)(vertexCursor + 0x40) * dotThenTwiceDot - normalizedEyeX);
      normalYPtr = (float *)(vertexCursor + 0x44);
      vertexCursor = vertexCursor + 0x100;
      *(float *)(texCoordSlot + 0x84) = -(*normalYPtr * dotThenTwiceDot - normalizedEyeY);
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
void _gleMultiVtxTextureCoordGenNormalST(unusedArg1, vertexCursor, vertexCount, textureUnit)
  undefined4 unusedArg1;
  uint vertexCursor;
  int vertexCount;
  int textureUnit;
{
  undefined4 *normalYPtr;
  uint vertexEndThenRemaining;
  int texCoordSlot;
  
  vertexEndThenRemaining = vertexCursor + vertexCount * 0x100;
  if (vertexEndThenRemaining <= vertexCursor) {
    return;
  }
  vertexEndThenRemaining = (vertexEndThenRemaining - vertexCursor) + 0xff >> 8;
  do {
    texCoordSlot = textureUnit * 0x10 + vertexCursor;
    *(undefined4 *)(texCoordSlot + 0x80) = *(undefined4 *)(vertexCursor + 0x40);
    normalYPtr = (undefined4 *)(vertexCursor + 0x44);
    vertexCursor = vertexCursor + 0x100;
    *(undefined4 *)(texCoordSlot + 0x84) = *normalYPtr;
    vertexEndThenRemaining = vertexEndThenRemaining - 1;
  } while (vertexEndThenRemaining != 0);
  return;
}

