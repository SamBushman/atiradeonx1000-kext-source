#include "decls.h"

/* _gleFeedbackLineStrip @ 0xcc278 (284 bytes) */
void _gleFeedbackLineStrip(glContext, param_2, param_3, param_4)
  undefined4 glContext;
  int param_2;
  int param_3;
  int param_4;
{
  double dVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  dVar1 = DOUBLE_00108d70;
  if (1 < param_3) {
    if (param_4 == 0) {
      uVar3 = 0x702;
      uVar2 = 0x702;
    }
    else if (param_4 == 1) {
      uVar2 = 0x707;
      uVar3 = 0x702;
    }
    else {
      uVar3 = 0x707;
      uVar2 = 0x707;
    }
    uVar5 = param_2 + 0x100;
    ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar2) - DOUBLE_00108d70))
    ;
    _gleFeedbackHitRecord(glContext,param_2);
    _gleFeedbackHitRecord(glContext,uVar5);
    uVar4 = (param_2 + param_3 * 0x100) - 0x100;
    if (uVar5 < uVar4) {
      do {
        uVar6 = uVar5 + 0x100;
        ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar3) - dVar1));
        _gleFeedbackHitRecord(glContext,uVar5);
        _gleFeedbackHitRecord(glContext,uVar6);
        uVar5 = uVar6;
      } while (uVar6 < uVar4);
    }
  }
  return;
}

/* _gleFeedbackLineLoop @ 0xcc394 (344 bytes) */
void _gleFeedbackLineLoop(glContext, param_2, param_3, param_4)
  undefined4 glContext;
  int param_2;
  int param_3;
  int param_4;
{
  double dVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  dVar1 = DOUBLE_00108d70;
  if (0 < param_3) {
    if (param_4 == 0) {
      uVar3 = 0x702;
      uVar2 = 0x702;
    }
    else if (param_4 == 1) {
      uVar2 = 0x707;
      uVar3 = 0x702;
    }
    else {
      uVar3 = 0x707;
      uVar2 = 0x707;
    }
    uVar5 = param_2 + 0x100;
    ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar2) - DOUBLE_00108d70))
    ;
    _gleFeedbackHitRecord(glContext,param_2);
    _gleFeedbackHitRecord(glContext,uVar5);
    uVar4 = (param_2 + param_3 * 0x100) - 0x100;
    if (uVar5 < uVar4) {
      uVar6 = uVar5;
      do {
        uVar5 = uVar6 + 0x100;
        ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar3) - dVar1));
        _gleFeedbackHitRecord(glContext,uVar6);
        _gleFeedbackHitRecord(glContext,uVar5);
        uVar6 = uVar5;
      } while (uVar5 < uVar4);
    }
    ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar3) - DOUBLE_00108d70))
    ;
    _gleFeedbackHitRecord(glContext,uVar5);
    _gleFeedbackHitRecord(glContext,param_2);
  }
  return;
}

/* _gleFeedbackLinesPtr @ 0xcc4ec (276 bytes) */
void _gleFeedbackLinesPtr(glContext, param_2, param_3, param_4)
  undefined4 glContext;
  undefined4 *param_2;
  int param_3;
  int param_4;
{
  undefined4 *puVar1;
  double dVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  dVar2 = DOUBLE_00108d70;
  if (1 < param_3) {
    if (param_4 == 0) {
      uVar4 = 0x702;
      uVar3 = 0x702;
    }
    else if (param_4 == 1) {
      uVar3 = 0x707;
      uVar4 = 0x702;
    }
    else {
      uVar4 = 0x707;
      uVar3 = 0x707;
    }
    puVar5 = param_2 + 2;
    ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar3) - DOUBLE_00108d70))
    ;
    _gleFeedbackHitRecord(glContext,*param_2);
    _gleFeedbackHitRecord(glContext,param_2[1]);
    if (puVar5 < param_2 + param_3 + -1) {
      do {
        ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar4) - dVar2));
        _gleFeedbackHitRecord(glContext,*puVar5);
        puVar1 = puVar5 + 1;
        puVar5 = puVar5 + 2;
        _gleFeedbackHitRecord(glContext,*puVar1);
      } while (puVar5 < param_2 + param_3 + -1);
    }
  }
  return;
}

/* _gleFeedbackPolygon @ 0xcc600 (480 bytes) */
void _gleFeedbackPolygon(glContext, firstVertex, vertexCount, polygonModeIndex)
  undefined4 glContext;
  uint firstVertex;
  uint vertexCount;
  uint polygonModeIndex;
{
  uint edgeStart;
  double intToDoubleBias;
  undefined4 lineToken;
  uint uVar4;
  
  intToDoubleBias = DOUBLE_00108d70;
  uVar4 = polygonModeIndex & 3;
  lineToken = 0x707;
  if (uVar4 != 1) {
    if (uVar4 == 0) {
      uVar4 = firstVertex + vertexCount * 0x100;
      for (; firstVertex < uVar4; firstVertex = firstVertex + 0x100) {
        if ((*(char *)(firstVertex + 0x7c) != '\0') && (*(char *)(firstVertex + 0x7d) == '\0')) {
          ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f28);
          _gleFeedbackHitRecord(glContext,firstVertex);
        }
      }
      return;
    }
    if (uVar4 == 2) {
      ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f30);
      ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,vertexCount ^ 0x80000000) -
                                               DOUBLE_00108d58));
      uVar4 = firstVertex + vertexCount * 0x100;
      for (; firstVertex < uVar4; firstVertex = firstVertex + 0x100) {
        _gleFeedbackHitRecord(glContext,firstVertex);
      }
      return;
    }
    if (uVar4 != 3) {
      return;
    }
    lineToken = 0x702;
  }
  uVar4 = firstVertex;
  while (edgeStart = uVar4, edgeStart < (firstVertex + vertexCount * 0x100) - 0x100) {
    uVar4 = edgeStart + 0x100;
    if (*(char *)(edgeStart + 0x7c) != '\0') {
      ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,lineToken) - intToDoubleBias));
      _gleFeedbackHitRecord(glContext,edgeStart);
      _gleFeedbackHitRecord(glContext,uVar4);
      lineToken = 0x702;
    }
  }
  if (*(char *)(edgeStart + 0x7c) != '\0') {
    ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f34);
    _gleFeedbackHitRecord(glContext,edgeStart);
    _gleFeedbackHitRecord(glContext,firstVertex);
  }
  return;
}

/* _gleFeedbackTriangles @ 0xcc7e0 (612 bytes) */
double _gleFeedbackTriangles(undefined4 glContext,int vertexCursor,int vertexCount,uint polygonModeIndex,double fparam_1)
{
  uint polygonModeBits;
  double dVar2;
  double dVar3;
  undefined4 lineToken;
  int lastTriangleStart;
  int triangleStart;
  
  dVar3 = DOUBLE_00108dd0;
  dVar2 = DOUBLE_00108d70;
  polygonModeBits = polygonModeIndex & 3;
  lastTriangleStart = vertexCount + -3;
  triangleStart = 0;
  if (polygonModeBits == 1) {
    if (-1 < lastTriangleStart) {
      do {
        lineToken = 0x707;
        if (*(char *)(vertexCursor + 0x7c) != '\0') {
          ((void (*)())_gleFeedbackToken)(glContext,(double)(float)dVar3);
          _gleFeedbackHitRecord(glContext,vertexCursor);
          fparam_1 = (double)_gleFeedbackHitRecord(glContext,vertexCursor + 0x100);
          lineToken = 0x702;
        }
        if (*(char *)(vertexCursor + 0x17c) != '\0') {
          ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,lineToken) - dVar2));
          _gleFeedbackHitRecord(glContext,vertexCursor + 0x100);
          fparam_1 = (double)_gleFeedbackHitRecord(glContext,vertexCursor + 0x200);
          lineToken = 0x702;
        }
        if (*(char *)(vertexCursor + 0x27c) != '\0') {
          ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,lineToken) - dVar2));
          _gleFeedbackHitRecord(glContext,vertexCursor + 0x200);
          fparam_1 = (double)_gleFeedbackHitRecord(glContext,vertexCursor);
        }
        triangleStart = triangleStart + 3;
        vertexCursor = vertexCursor + 0x300;
      } while (triangleStart <= lastTriangleStart);
    }
  }
  else if (polygonModeBits == 0) {
    if (-1 < lastTriangleStart) {
      do {
        if (*(char *)(vertexCursor + 0x7c) != '\0') {
          ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f28);
          fparam_1 = (double)_gleFeedbackHitRecord(glContext,vertexCursor);
        }
        if (*(char *)(vertexCursor + 0x17c) != '\0') {
          ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f28);
          fparam_1 = (double)_gleFeedbackHitRecord(glContext,vertexCursor + 0x100);
        }
        if (*(char *)(vertexCursor + 0x27c) != '\0') {
          ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f28);
          fparam_1 = (double)_gleFeedbackHitRecord(glContext,vertexCursor + 0x200);
        }
        triangleStart = triangleStart + 3;
        vertexCursor = vertexCursor + 0x300;
      } while (triangleStart <= lastTriangleStart);
    }
  }
  else if ((polygonModeBits == 2) && (-1 < lastTriangleStart)) {
    do {
      triangleStart = triangleStart + 3;
      ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f30);
      ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f38);
      _gleFeedbackHitRecord(glContext,vertexCursor);
      _gleFeedbackHitRecord(glContext,vertexCursor + 0x100);
      fparam_1 = (double)_gleFeedbackHitRecord(glContext,vertexCursor + 0x200);
      vertexCursor = vertexCursor + 0x300;
    } while (triangleStart <= lastTriangleStart);
  }
  return fparam_1;
}

/* _gleFeedbackTriangleFan @ 0xcca44 (472 bytes) */
double _gleFeedbackTriangleFan(glContext, centerVertex, vertexCursor, vertexCount, polygonModeIndex)
  undefined4 glContext;
  undefined4 centerVertex;
  int vertexCursor;
  int vertexCount;
  uint polygonModeIndex;
{
  uint polygonModeBits;
  int iVar2;
  int triangleIndex;
  int nextVertex;
  float tokenValue;
  
  polygonModeBits = polygonModeIndex & 3;
  iVar2 = vertexCount + -2;
  triangleIndex = 0;
  if (polygonModeBits == 1) {
    if (-1 < iVar2) {
      tokenValue = (double)FLOAT_00108f34;
      do {
        nextVertex = vertexCursor + 0x100;
        triangleIndex = triangleIndex + 1;
        ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f2c);
        _gleFeedbackHitRecord(glContext,centerVertex);
        _gleFeedbackHitRecord(glContext,vertexCursor);
        ((void (*)())_gleFeedbackToken)(glContext,(double)tokenValue);
        _gleFeedbackHitRecord(glContext,vertexCursor);
        _gleFeedbackHitRecord(glContext,nextVertex);
        ((void (*)())_gleFeedbackToken)(glContext,(double)tokenValue);
        _gleFeedbackHitRecord(glContext,nextVertex);
        _gleFeedbackHitRecord(glContext,centerVertex);
        vertexCursor = nextVertex;
      } while (triangleIndex <= iVar2);
    }
  }
  else if (polygonModeBits == 0) {
    if (-1 < iVar2) {
      tokenValue = (double)FLOAT_00108f28;
      do {
        triangleIndex = triangleIndex + 1;
        ((void (*)())_gleFeedbackToken)(glContext,(double)tokenValue);
        _gleFeedbackHitRecord(glContext,centerVertex);
        ((void (*)())_gleFeedbackToken)(glContext,(double)tokenValue);
        _gleFeedbackHitRecord(glContext,vertexCursor);
        ((void (*)())_gleFeedbackToken)(glContext,(double)tokenValue);
        _gleFeedbackHitRecord(glContext,vertexCursor + 0x100);
        vertexCursor = vertexCursor + 0x100;
      } while (triangleIndex <= iVar2);
    }
  }
  else if ((polygonModeBits == 2) && (-1 < iVar2)) {
    iVar2 = vertexCount + -1;
    do {
      ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f30);
      ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f38);
      _gleFeedbackHitRecord(glContext,centerVertex);
      _gleFeedbackHitRecord(glContext,vertexCursor);
      _gleFeedbackHitRecord(glContext,vertexCursor + 0x100);
      iVar2 = iVar2 + -1;
      vertexCursor = vertexCursor + 0x100;
    } while (iVar2 != 0);
  }
  return;
}

/* _gleFeedbackTriangleStrip @ 0xccc1c (764 bytes) */
double _gleFeedbackTriangleStrip(glContext, firstVertexThenCursor, vertexCount, polygonMode)
  undefined4 glContext;
  int firstVertexThenCursor;
  int vertexCount;
  uint polygonMode;
{
  bool hasSecondTriangle;
  uint modeBits;
  int lastTriangleIndex;
  int pairIndex;
  int thirdVertex;
  int secondOrThirdVertex;
  float primitiveToken;
  
  modeBits = polygonMode & 3;
  lastTriangleIndex = vertexCount + -3;
  pairIndex = 0;
  if (modeBits == 1) {
    hasSecondTriangle = 0 < lastTriangleIndex;
    if (-1 < lastTriangleIndex) {
      primitiveToken = (double)FLOAT_00108f34;
      do {
        secondOrThirdVertex = firstVertexThenCursor + 0x100;
        thirdVertex = firstVertexThenCursor + 0x200;
        ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f2c);
        _gleFeedbackHitRecord(glContext,firstVertexThenCursor);
        _gleFeedbackHitRecord(glContext,secondOrThirdVertex);
        ((void (*)())_gleFeedbackToken)(glContext,(double)primitiveToken);
        _gleFeedbackHitRecord(glContext,secondOrThirdVertex);
        _gleFeedbackHitRecord(glContext,thirdVertex);
        ((void (*)())_gleFeedbackToken)(glContext,(double)primitiveToken);
        _gleFeedbackHitRecord(glContext,thirdVertex);
        _gleFeedbackHitRecord(glContext,firstVertexThenCursor);
        if (hasSecondTriangle) {
          ((void (*)())_gleFeedbackToken)(glContext,(double)primitiveToken);
          _gleFeedbackHitRecord(glContext,thirdVertex);
          _gleFeedbackHitRecord(glContext,secondOrThirdVertex);
          ((void (*)())_gleFeedbackToken)(glContext,(double)primitiveToken);
          _gleFeedbackHitRecord(glContext,secondOrThirdVertex);
          _gleFeedbackHitRecord(glContext,firstVertexThenCursor + 0x300);
          ((void (*)())_gleFeedbackToken)(glContext,(double)primitiveToken);
          _gleFeedbackHitRecord(glContext,firstVertexThenCursor + 0x300);
          _gleFeedbackHitRecord(glContext,thirdVertex);
        }
        pairIndex = pairIndex + 2;
        hasSecondTriangle = pairIndex < lastTriangleIndex;
        firstVertexThenCursor = thirdVertex;
      } while (pairIndex <= lastTriangleIndex);
    }
  }
  else if (modeBits == 0) {
    hasSecondTriangle = 0 < lastTriangleIndex;
    if (-1 < lastTriangleIndex) {
      primitiveToken = (double)FLOAT_00108f28;
      do {
        secondOrThirdVertex = firstVertexThenCursor + 0x200;
        ((void (*)())_gleFeedbackToken)(glContext,(double)primitiveToken);
        _gleFeedbackHitRecord(glContext,firstVertexThenCursor);
        ((void (*)())_gleFeedbackToken)(glContext,(double)primitiveToken);
        _gleFeedbackHitRecord(glContext,firstVertexThenCursor + 0x100);
        ((void (*)())_gleFeedbackToken)(glContext,(double)primitiveToken);
        _gleFeedbackHitRecord(glContext,secondOrThirdVertex);
        if (hasSecondTriangle) {
          ((void (*)())_gleFeedbackToken)(glContext,(double)primitiveToken);
          _gleFeedbackHitRecord(glContext,secondOrThirdVertex);
          ((void (*)())_gleFeedbackToken)(glContext,(double)primitiveToken);
          _gleFeedbackHitRecord(glContext,firstVertexThenCursor + 0x100);
          ((void (*)())_gleFeedbackToken)(glContext,(double)primitiveToken);
          _gleFeedbackHitRecord(glContext,firstVertexThenCursor + 0x300);
        }
        pairIndex = pairIndex + 2;
        hasSecondTriangle = pairIndex < lastTriangleIndex;
        firstVertexThenCursor = secondOrThirdVertex;
      } while (pairIndex <= lastTriangleIndex);
    }
  }
  else if ((modeBits == 2) && (hasSecondTriangle = 0 < lastTriangleIndex, -1 < lastTriangleIndex)) {
    primitiveToken = (double)FLOAT_00108f30;
    do {
      secondOrThirdVertex = firstVertexThenCursor + 0x200;
      ((void (*)())_gleFeedbackToken)(glContext,(double)primitiveToken);
      ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f38);
      _gleFeedbackHitRecord(glContext,firstVertexThenCursor);
      _gleFeedbackHitRecord(glContext,firstVertexThenCursor + 0x100);
      _gleFeedbackHitRecord(glContext,secondOrThirdVertex);
      if (hasSecondTriangle) {
        ((void (*)())_gleFeedbackToken)(glContext,(double)primitiveToken);
        ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f38);
        _gleFeedbackHitRecord(glContext,secondOrThirdVertex);
        _gleFeedbackHitRecord(glContext,firstVertexThenCursor + 0x100);
        _gleFeedbackHitRecord(glContext,firstVertexThenCursor + 0x300);
      }
      pairIndex = pairIndex + 2;
      hasSecondTriangle = pairIndex < lastTriangleIndex;
      firstVertexThenCursor = secondOrThirdVertex;
    } while (pairIndex <= lastTriangleIndex);
  }
  return;
}

/* _gleFeedbackQuads @ 0xccf18 (508 bytes) */
double _gleFeedbackQuads(glContext, firstVertexThenCursor, vertexCount, polygonMode)
  undefined4 glContext;
  int firstVertexThenCursor;
  int vertexCount;
  uint polygonMode;
{
  uint modeBits;
  double intToDoubleBias;
  undefined4 segmentTokenType;
  int lastQuadIndex;
  int vertexIndex;
  int quadStartThenVerticesLeft;
  int edgeStartVertex;
  int edgeCounterThenPointVertex;
  
  intToDoubleBias = DOUBLE_00108d70;
  modeBits = polygonMode & 3;
  lastQuadIndex = vertexCount + -4;
  vertexIndex = 0;
  if (modeBits == 1) {
    quadStartThenVerticesLeft = firstVertexThenCursor;
    if (-1 < lastQuadIndex) {
      do {
        segmentTokenType = 0x707;
        edgeStartVertex = vertexIndex * 0x100 + firstVertexThenCursor;
        edgeCounterThenPointVertex = 2;
        do {
          if (*(char *)(edgeStartVertex + 0x7c) != '\0') {
            ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,segmentTokenType) - intToDoubleBias));
            _gleFeedbackHitRecord(glContext,edgeStartVertex);
            _gleFeedbackHitRecord(glContext,edgeStartVertex + 0x100);
            segmentTokenType = 0x702;
          }
          edgeCounterThenPointVertex = edgeCounterThenPointVertex + -1;
          edgeStartVertex = edgeStartVertex + 0x100;
        } while (-1 < edgeCounterThenPointVertex);
        if (*(char *)(quadStartThenVerticesLeft + 0x37c) != '\0') {
          ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,segmentTokenType) - intToDoubleBias));
          _gleFeedbackHitRecord(glContext,quadStartThenVerticesLeft + 0x300);
          _gleFeedbackHitRecord(glContext,quadStartThenVerticesLeft);
        }
        vertexIndex = vertexIndex + 4;
        quadStartThenVerticesLeft = quadStartThenVerticesLeft + 0x400;
      } while (vertexIndex <= lastQuadIndex);
    }
  }
  else if (modeBits == 0) {
    if (-1 < lastQuadIndex) {
      do {
        quadStartThenVerticesLeft = 3;
        edgeCounterThenPointVertex = vertexIndex * 0x100 + firstVertexThenCursor;
        do {
          if (*(char *)(edgeCounterThenPointVertex + 0x7c) != '\0') {
            ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f28);
            _gleFeedbackHitRecord(glContext,edgeCounterThenPointVertex);
          }
          quadStartThenVerticesLeft = quadStartThenVerticesLeft + -1;
          edgeCounterThenPointVertex = edgeCounterThenPointVertex + 0x100;
        } while (-1 < quadStartThenVerticesLeft);
        vertexIndex = vertexIndex + 4;
      } while (vertexIndex <= lastQuadIndex);
    }
  }
  else if ((modeBits == 2) && (-1 < lastQuadIndex)) {
    do {
      vertexIndex = vertexIndex + 4;
      ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f30);
      ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108ea8);
      _gleFeedbackHitRecord(glContext,firstVertexThenCursor);
      _gleFeedbackHitRecord(glContext,firstVertexThenCursor + 0x100);
      _gleFeedbackHitRecord(glContext,firstVertexThenCursor + 0x200);
      _gleFeedbackHitRecord(glContext,firstVertexThenCursor + 0x300);
      firstVertexThenCursor = firstVertexThenCursor + 0x400;
    } while (vertexIndex <= lastQuadIndex);
  }
  return;
}

/* _gleFeedbackQuadStrip @ 0xcd114 (552 bytes) */
double _gleFeedbackQuadStrip(glContext, vertexCursor, vertexCount, polygonModeIndex)
  undefined4 glContext;
  int vertexCursor;
  int vertexCount;
  uint polygonModeIndex;
{
  uint polygonModeBits;
  int lastQuadStart;
  int quadStart;
  int nextQuadVertex;
  float tokenValue;
  
  polygonModeBits = polygonModeIndex & 3;
  lastQuadStart = vertexCount + -4;
  quadStart = 0;
  if (polygonModeBits == 1) {
    if (-1 < lastQuadStart) {
      tokenValue = (double)FLOAT_00108f34;
      do {
        ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f2c);
        quadStart = quadStart + 2;
        _gleFeedbackHitRecord(glContext,vertexCursor);
        _gleFeedbackHitRecord(glContext,vertexCursor + 0x100);
        ((void (*)())_gleFeedbackToken)(glContext,(double)tokenValue);
        nextQuadVertex = vertexCursor + 0x200;
        _gleFeedbackHitRecord(glContext,vertexCursor + 0x100);
        _gleFeedbackHitRecord(glContext,vertexCursor + 0x300);
        ((void (*)())_gleFeedbackToken)(glContext,(double)tokenValue);
        _gleFeedbackHitRecord(glContext,vertexCursor + 0x300);
        _gleFeedbackHitRecord(glContext,nextQuadVertex);
        ((void (*)())_gleFeedbackToken)(glContext,(double)tokenValue);
        _gleFeedbackHitRecord(glContext,nextQuadVertex);
        _gleFeedbackHitRecord(glContext,vertexCursor);
        vertexCursor = nextQuadVertex;
      } while (quadStart <= lastQuadStart);
    }
  }
  else if (polygonModeBits == 0) {
    if (-1 < lastQuadStart) {
      tokenValue = (double)FLOAT_00108f28;
      do {
        quadStart = quadStart + 2;
        ((void (*)())_gleFeedbackToken)(glContext,(double)tokenValue);
        _gleFeedbackHitRecord(glContext,vertexCursor);
        ((void (*)())_gleFeedbackToken)(glContext,(double)tokenValue);
        _gleFeedbackHitRecord(glContext,vertexCursor + 0x100);
        ((void (*)())_gleFeedbackToken)(glContext,(double)tokenValue);
        _gleFeedbackHitRecord(glContext,vertexCursor + 0x300);
        ((void (*)())_gleFeedbackToken)(glContext,(double)tokenValue);
        _gleFeedbackHitRecord(glContext,vertexCursor + 0x200);
        vertexCursor = vertexCursor + 0x200;
      } while (quadStart <= lastQuadStart);
    }
  }
  else if ((polygonModeBits == 2) && (-1 < lastQuadStart)) {
    do {
      quadStart = quadStart + 2;
      ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f30);
      ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108ea8);
      _gleFeedbackHitRecord(glContext,vertexCursor);
      _gleFeedbackHitRecord(glContext,vertexCursor + 0x100);
      _gleFeedbackHitRecord(glContext,vertexCursor + 0x300);
      _gleFeedbackHitRecord(glContext,vertexCursor + 0x200);
      vertexCursor = vertexCursor + 0x200;
    } while (quadStart <= lastQuadStart);
  }
  return;
}

/* _gleTestFence @ 0xcd33c (212 bytes) */
int _gleTestFence(glContext, param_2, fence)
  int glContext;
  int param_2;
  undefined4 fence;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  iVar3 = 1;
  iVar4 = 0;
  if (param_2 == 0) {
    iVar2 = _gleLookupHashObject(glContext + 0x543c,fence);
    iVar4 = iVar3;
    if (iVar2 == 0) {
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
    }
    else {
      iVar5 = glContext + 0x10000;
      uVar6 = 0;
      if (*(char *)(glContext + 0x85a4) != '\0') {
        puVar7 = (undefined4 *)(iVar2 + 0x10);
        do {
          bVar1 = iVar4 != 0;
          iVar4 = 0;
          if ((bVar1) &&
             (iVar3 = (**(code **)(*(int *)(iVar5 + -0x777c) + 0x1c0))
                                (*(undefined4 *)(iVar5 + -0x7a54),0,*puVar7), iVar3 != 0)) {
            iVar4 = 1;
          }
          uVar6 = uVar6 + 1;
          iVar5 = iVar5 + 0x2e0;
          puVar7 = puVar7 + 1;
        } while (uVar6 < *(byte *)(glContext + 0x85a4));
      }
    }
  }
  return iVar4;
}

/* _gleFinishFence @ 0xcd410 (172 bytes) */
void _gleFinishFence(glContext, param_2, fence)
  int glContext;
  int param_2;
  undefined4 fence;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  if (param_2 == 0) {
    iVar3 = _gleLookupHashObject(glContext + 0x543c,fence);
    if (iVar3 == 0) {
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
    }
    else {
      iVar5 = glContext + 0x10000;
      uVar6 = 0;
      if (*(char *)(glContext + 0x85a4) != '\0') {
        puVar7 = (undefined4 *)(iVar3 + 0x10);
        do {
          piVar1 = (int *)(iVar5 + -0x777c);
          uVar4 = *puVar7;
          uVar6 = uVar6 + 1;
          puVar7 = puVar7 + 1;
          puVar2 = (undefined4 *)(iVar5 + -0x7a54);
          iVar5 = iVar5 + 0x2e0;
          (**(code **)(*piVar1 + 0x1c4))(*puVar2,0,uVar4);
        } while (uVar6 < *(byte *)(glContext + 0x85a4));
      }
    }
  }
  return;
}

/* _gleBindRenderbuffer @ 0xcd4bc (268 bytes) */
void _gleBindRenderbuffer(glContext, renderbuffer)
  int glContext;
  int renderbuffer;
{
  undefined *freeTextureObject;
  int iVar2;
  int iVar3;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  undefined4 *renderbufferObject;
  
  iVar2 = *(int *)(glContext + 0x5148);
  renderbufferObject = (undefined4 *)0x0;
  if (renderbuffer != 0) {
    renderbufferObject = (undefined4 *)_gleLookupHashObject(((unsigned char *)0x00001004) + iVar2,renderbuffer);
    if (renderbufferObject == (undefined4 *)0x0) {
      renderbufferObject = (undefined4 *)_malloc(0xaac);
      freeTextureObject = PTR__gleFreeTextureObject_00112154;
      *renderbufferObject = 0;
      renderbufferObject[2] = 1;
      renderbufferObject[3] = freeTextureObject;
      renderbufferObject[1] = renderbuffer;
      _gleInitializeGLTexture(0x2000,1,renderbufferObject + 4,incomingR6,incomingR7,incomingR8,1);
      *(undefined2 *)((int)renderbufferObject + 0x4e) = 0x85bf;
      *(undefined2 *)(renderbufferObject + 0x12) = 0x812f;
      *(undefined2 *)(renderbufferObject + 0x13) = 0x2600;
      *(undefined2 *)(renderbufferObject + 0x11) = 0x812f;
      *(undefined2 *)((int)renderbufferObject + 0x46) = 0x812f;
      *(undefined2 *)((int)renderbufferObject + 0x4a) = 0x2600;
      _gleCreatePluginTexture(glContext,renderbufferObject + 4);
      _gleAddHashNameAndObject(glContext,((unsigned char *)0x00001004) + iVar2,renderbufferObject);
    }
    renderbufferObject[2] = renderbufferObject[2] + 1;
  }
  iVar2 = *(int *)(glContext + 0x7448);
  if ((iVar2 != 0) && (iVar3 = *(int *)(iVar2 + 8) + -1, *(int *)(iVar2 + 8) = iVar3, iVar3 == 0)) {
    _gleFreeTextureObject(glContext,iVar2);
  }
  *(undefined4 **)(glContext + 0x7448) = renderbufferObject;
  return;
}

/* _gleRenderbufferStorage @ 0xcd5c8 (612 bytes) */
void _gleRenderbufferStorage(glContext, target, internalformat, width, height)
  int glContext;
  undefined4 target;
  uint internalformat;
  int width;
  int height;
{
  byte levelFlags;
  int attachedObject;
  int rendererIndex;
  int *attachmentCursor;
  int attachmentNameBase;
  undefined4 *srcCursor;
  undefined4 *dstCursor;
  undefined4 dataType;
  undefined4 dataFormat;
  undefined4 copiedWord;
  int renderbufferBody;
  int attachmentRecordCursor;
  int framebufferObject;
  int renderbuffer;
  int levelImage;
  int attachmentIndex;
  
  renderbuffer = *(int *)(glContext + 0x7448);
  if (renderbuffer == 0) {
    return;
  }
  renderbufferBody = renderbuffer + 0x10;
  if ((((internalformat == 0x1902) || (internalformat == 0x81a5)) || (internalformat == 0x81a6)) || (internalformat == 0x81a7))
  {
    dataFormat = 0x1902;
  }
  else {
    if (((internalformat != 0x1901) && (internalformat != 0x8d46)) &&
       ((internalformat != 0x8d47 && ((internalformat != 0x8d48 && (internalformat != 0x8d49)))))) {
      dataFormat = 0x80e1;
      dataType = 0x8367;
      goto LAB_000cd6a0;
    }
    dataFormat = 0x1901;
  }
  dataType = 0x1405;
LAB_000cd6a0:
  levelImage = renderbuffer + 0xd4;
  if ((*(byte *)(renderbuffer + 0xdf) & 0x20) != 0) {
    _gleDeletePluginTextureLevel(glContext,renderbufferBody,levelImage,0,0);
    if (*(int *)(renderbuffer + 0xe8) != 0) {
      levelFlags = *(byte *)(renderbuffer + 0xdf);
      if ((levelFlags & 1) == 0) {
        _gleFreeTextureLevel(glContext,renderbufferBody,levelImage);
        levelFlags = *(byte *)(renderbuffer + 0xdf);
      }
      else {
        *(undefined4 *)(renderbuffer + 0xe8) = 0;
      }
      *(byte *)(renderbuffer + 0xdf) = levelFlags & 0xef;
    }
    *(byte *)(renderbuffer + 0xdf) = *(byte *)(renderbuffer + 0xdf) & 0xdf;
  }
  _gleCreateTextureLevel(glContext,renderbufferBody,levelImage,internalformat & 0xffff,width,height,1,0,dataFormat,dataType,0,0);
  if ((width != 0) && (height != 0)) {
    _gleCreatePluginTextureLevel(glContext,renderbufferBody,levelImage,0,0,internalformat & 0xffff);
  }
  framebufferObject = *(int *)(glContext + 0x744c);
  if (framebufferObject != 0) {
    attachmentNameBase = framebufferObject + 0x10;
    attachmentCursor = (int *)(framebufferObject + 0xd4);
    attachmentIndex = 0;
    attachmentRecordCursor = attachmentNameBase;
    do {
      attachedObject = *attachmentCursor;
      attachmentCursor = attachmentCursor + 1;
      if (attachedObject == renderbuffer) {
        *(undefined4 *)(attachmentRecordCursor + 0x20) = target;
        rendererIndex = 0;
        *(undefined4 *)(attachmentRecordCursor + 0x28) = 0;
        *(undefined4 *)(attachmentRecordCursor + 0x24) = 0;
        *(undefined4 *)(attachmentRecordCursor + 0x2c) = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          dstCursor = (undefined4 *)(attachmentNameBase + 0xe0);
          srcCursor = (undefined4 *)(renderbuffer + 0x10);
          do {
            copiedWord = *srcCursor;
            rendererIndex = rendererIndex + 1;
            srcCursor = srcCursor + 1;
            *dstCursor = copiedWord;
            dstCursor = dstCursor + 8;
          } while (rendererIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      attachmentIndex = attachmentIndex + 1;
      attachmentNameBase = attachmentNameBase + 4;
      attachmentRecordCursor = attachmentRecordCursor + 0x18;
    } while (attachmentIndex < 6);
  }
  return;
}

/* _gleCreatePluginFramebuffer @ 0xcd82c (132 bytes) */
void _gleCreatePluginFramebuffer(glContext, param_2)
  int glContext;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = glContext + 0x10000;
  iVar4 = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    iVar5 = param_2;
    iVar6 = param_2 + 0xe0;
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      iVar4 = iVar4 + 1;
      (**(code **)(*piVar1 + 0x1fc))(*puVar2,iVar5,param_2 + 0x20,iVar6);
      iVar5 = iVar5 + 4;
      iVar6 = iVar6 + 0x20;
    } while (iVar4 < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _gleDestroyPluginFramebuffer @ 0xcd8b0 (120 bytes) */
void _gleDestroyPluginFramebuffer(glContext, param_2)
  int glContext;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = glContext + 0x10000;
  iVar5 = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar4 + -0x777c);
      iVar3 = iVar5 * 4;
      puVar2 = (undefined4 *)(iVar4 + -0x7a54);
      iVar4 = iVar4 + 0x2e0;
      iVar5 = iVar5 + 1;
      (**(code **)(*piVar1 + 0x204))(*puVar2,*(undefined4 *)(iVar3 + param_2));
      *(undefined4 *)(iVar3 + param_2) = 0;
    } while (iVar5 < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _gleCreateFramebufferObject @ 0xcd928 (344 bytes) */
int _gleCreateFramebufferObject(glContext, framebuffer)
  int glContext;
  undefined4 framebuffer;
{
  undefined *freeFramebufferObject;
  undefined2 *halfwordCursor;
  undefined4 *clearCursor;
  undefined4 *rendererCursor;
  undefined4 *attachmentCursor;
  undefined4 *clearCursor2;
  undefined4 *rendererClearCursor;
  undefined4 *newObjectThenCursor;
  int remaining;
  int loopIndex;
  int remaining4;
  int remaining3;
  int remaining2;
  int innerRemaining;
  undefined4 *framebufferObject;
  
  newObjectThenCursor = (undefined4 *)_gleVecAlloc((uint)*(byte *)(glContext + 0x85a4) * 0x20 + 0xf0);
  framebufferObject = newObjectThenCursor;
  freeFramebufferObject = PTR__gleFreeFramebufferObject_00110e20;
  newObjectThenCursor[2] = 1;
  newObjectThenCursor[3] = freeFramebufferObject;
  newObjectThenCursor[1] = framebuffer;
  clearCursor = newObjectThenCursor + 0x35;
  *newObjectThenCursor = 0;
  remaining = 6;
  do {
    *clearCursor = 0;
    clearCursor = clearCursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  remaining2 = 8;
  newObjectThenCursor[0x3b] = 1;
  clearCursor2 = newObjectThenCursor + 4;
  do {
    *clearCursor2 = 0;
    clearCursor2 = clearCursor2 + 1;
    remaining2 = remaining2 + -1;
  } while (remaining2 != 0);
  remaining3 = 3;
  *(undefined2 *)(newObjectThenCursor + 0x30) = 0x8ce0;
  halfwordCursor = (undefined2 *)((int)newObjectThenCursor + 0xc2);
  do {
    *halfwordCursor = 0;
    halfwordCursor = halfwordCursor + 1;
    remaining3 = remaining3 + -1;
  } while (remaining3 != 0);
  remaining4 = 6;
  *(undefined2 *)(newObjectThenCursor + 0x32) = 0x8ce0;
  newObjectThenCursor[0x34] = 0;
  attachmentCursor = newObjectThenCursor;
  do {
    attachmentCursor[0xc] = 0;
    attachmentCursor[0xd] = 0;
    attachmentCursor[0xe] = 0;
    attachmentCursor[0xf] = 0;
    attachmentCursor[0x11] = 0;
    attachmentCursor[0x10] = 0;
    attachmentCursor = attachmentCursor + 6;
    remaining4 = remaining4 + -1;
  } while (remaining4 != 0);
  loopIndex = 0;
  rendererCursor = newObjectThenCursor;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      rendererClearCursor = rendererCursor + 0x3c;
      innerRemaining = 6;
      do {
        *rendererClearCursor = 0;
        rendererClearCursor = rendererClearCursor + 1;
        innerRemaining = innerRemaining + -1;
      } while (innerRemaining != 0);
      newObjectThenCursor[0x42] = 0;
      loopIndex = loopIndex + 1;
      newObjectThenCursor[0x43] = 0;
      newObjectThenCursor = newObjectThenCursor + 8;
      rendererCursor = rendererCursor + 8;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return (int)framebufferObject;
}

/* _gleFreeFramebufferObject @ 0xcda80 (116 bytes) */
void _gleFreeFramebufferObject(glContext, param_2)
  undefined4 glContext;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = 5;
  ((void (*)())_gleDestroyPluginFramebuffer)(glContext,param_2 + 0x10);
  piVar4 = (int *)(param_2 + 0xd4);
  do {
    iVar2 = *piVar4;
    piVar4 = piVar4 + 1;
    if ((iVar2 != 0) && (iVar1 = *(int *)(iVar2 + 8) + -1, *(int *)(iVar2 + 8) = iVar1, iVar1 == 0))
    {
      _gleFreeTextureObject(glContext,iVar2);
    }
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  _gleVecFree(param_2);
  return;
}

/* _gleUpdateFramebufferDirtyBits @ 0xcdaf4 (192 bytes) */
void _gleUpdateFramebufferDirtyBits(glContext, param_2)
  int glContext;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_2 + 0xdc) != 0) {
    return;
  }
  iVar1 = 0;
  while ((iVar2 = *(int *)(iVar1 * 4 + param_2 + 0xc4), iVar2 == 0 ||
         (iVar3 = param_2 + iVar1 * 0x18,
         *(int *)(iVar3 + 0x30) ==
         *(int *)(iVar2 + *(int *)(iVar3 + 0x24) * 0x168 + *(int *)(iVar3 + 0x28) * 0x18 + 0xd4))))
  {
    iVar1 = iVar1 + 1;
    if (5 < iVar1) {
      return;
    }
  }
  iVar1 = 0;
  *(undefined4 *)(param_2 + 0xdc) = 1;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      *(undefined4 *)(param_2 + 0xf8) = 1;
      iVar1 = iVar1 + 1;
      *(undefined4 *)(param_2 + 0xfc) = 0;
      param_2 = param_2 + 0x20;
    } while (iVar1 < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  return;
}

/* _gleBindFramebuffer @ 0xcdbb4 (1100 bytes) */
void _gleBindFramebuffer(glContext, framebuffer)
  int glContext;
  int framebuffer;
{
  bool noFramebuffer;
  int attachedTexture;
  int oldAttachedTexture;
  int levelBase;
  int faceMaskBase;
  int framebufferObject;
  int sharedObjectsReloaded;
  int maskBase;
  undefined4 *tableCursor;
  undefined4 *pluginHandleCursor;
  byte levelFlags;
  undefined4 *tableDest;
  int pluginHandleArray;
  int previousFramebuffer;
  int *slotCursor;
  int *oldSlotCursor;
  int attachmentFace;
  int slotRecord;
  int slotsLeft;
  uint rendererIndex;
  uint slotIndex;
  uint attachmentLevelThenMip;
  undefined4 sharedObjects;
  undefined4 boundPluginHandle;
  undefined4 pluginHandle;
  int textureBase;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  sharedObjects = *(undefined4 *)(glContext + 0x5148);
  if (framebuffer == 0) {
    rendererIndex = 0;
    framebufferObject = 0;
    noFramebuffer = true;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      tableCursor = (undefined4 *)(glContext + 0x8880);
      do {
        *tableCursor = 0;
        rendererIndex = rendererIndex + 1;
        tableCursor = tableCursor + 0xb8;
        noFramebuffer = true;
      } while (rendererIndex < *(byte *)(glContext + 0x85a4));
    }
  }
  else {
    framebufferObject = _gleLookupHashObject(sharedObjects,framebuffer);
    noFramebuffer = framebufferObject == 0;
    if (noFramebuffer) {
      framebufferObject = ((int (*)())_gleCreateFramebufferObject)(glContext,framebuffer);
      pluginHandleArray = framebufferObject + 0x10;
      ((void (*)())_gleCreatePluginFramebuffer)(glContext,pluginHandleArray);
      _gleAddHashNameAndObject(glContext,sharedObjects,framebufferObject);
      noFramebuffer = framebufferObject == 0;
    }
    else {
      pluginHandleArray = framebufferObject + 0x10;
    }
    slotIndex = 0;
    slotCursor = (int *)(framebufferObject + 0xd4);
    slotRecord = framebufferObject;
    do {
      attachedTexture = *slotCursor;
      slotCursor = slotCursor + 1;
      if (attachedTexture != 0) {
        textureBase = attachedTexture + 0x10;
        attachmentFace = *(int *)(slotRecord + 0x34);
        attachmentLevelThenMip = *(uint *)(slotRecord + 0x38);
        levelBase = textureBase + attachmentFace * 0x168 + attachmentLevelThenMip * 0x18;
        if (*(int *)(attachedTexture + 0x30) == 0) {
LAB_000cdca4:
          sharedObjectsReloaded = *(int *)(glContext + 0x5148);
        }
        else {
          sharedObjectsReloaded = *(int *)(glContext + 0x5148);
          if (*(int *)(attachedTexture + 0x30) !=
              *(int *)((uint)*(byte *)(glContext + 0x85a8) * 4 + sharedObjectsReloaded + 0x8054)) {
            _gleSynchronizePluginTextureLevels(glContext,textureBase);
            goto LAB_000cdca4;
          }
        }
        *(undefined4 *)(attachedTexture + 0x30) =
             *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + sharedObjectsReloaded + 0x8054);
        *(byte *)(levelBase + 0xcf) = *(byte *)(levelBase + 0xcf) | 0x80;
        if (*(int *)(levelBase + 0xd8) != 0) {
          levelFlags = *(byte *)(levelBase + 0xcf);
          if (((levelFlags & 1) == 0) && (*(short *)(attachedTexture + 0x4e) == -0x7a43)) {
            _gleFreeTextureLevel(glContext,textureBase,levelBase + 0xc4);
            levelFlags = *(byte *)(levelBase + 0xcf);
          }
          maskBase = attachmentFace * 2 + textureBase;
          *(byte *)(levelBase + 0xcf) = levelFlags & 0xef;
          *(ushort *)(maskBase + 0xa0) =
               *(ushort *)(maskBase + 0xa0) &
               ((ushort)(-2 << (attachmentLevelThenMip & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (attachmentLevelThenMip & 0x1f)));
        }
        *(byte *)(levelBase + 0xcf) = *(byte *)(levelBase + 0xcf) | 0x40;
        if ((((*(uint *)(attachedTexture + 0x7c) & 0x8000) != 0) && ((int)*(short *)(attachedTexture + 0x70) == attachmentLevelThenMip))
           && (attachmentLevelThenMip = attachmentLevelThenMip + 1, (int)attachmentLevelThenMip <= (int)(uint)*(byte *)(attachedTexture + 0x93))) {
          faceMaskBase = attachmentFace * 2 + textureBase;
          attachmentFace = attachmentLevelThenMip * 0x18 + attachmentFace * 0x168 + textureBase + 0xc4;
          do {
            if (*(int *)(attachmentFace + 0x14) != 0) {
              if (((*(byte *)(attachmentFace + 0xb) & 1) == 0) && (*(short *)(attachedTexture + 0x4e) == -0x7a43)) {
                _gleFreeTextureLevel(glContext,textureBase,attachmentFace);
              }
              *(byte *)(attachmentFace + 0xb) = *(byte *)(attachmentFace + 0xb) & 0xef;
              *(ushort *)(faceMaskBase + 0xa0) =
                   *(ushort *)(faceMaskBase + 0xa0) & ~(ushort)(1 << (attachmentLevelThenMip & 0x3f));
            }
            attachmentLevelThenMip = attachmentLevelThenMip + 1;
            *(byte *)(attachmentFace + 0xb) = *(byte *)(attachmentFace + 0xb) | 0x40;
            attachmentFace = attachmentFace + 0x18;
          } while ((int)attachmentLevelThenMip <= (int)(uint)*(byte *)(attachedTexture + 0x93));
        }
      }
      slotIndex = slotIndex + 1;
      slotRecord = slotRecord + 0x18;
    } while (slotIndex < 6);
    rendererIndex = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      pluginHandleCursor = (undefined4 *)(framebufferObject + 0x10);
      tableDest = (undefined4 *)(glContext + 0x8880);
      do {
        pluginHandle = *pluginHandleCursor;
        rendererIndex = rendererIndex + 1;
        pluginHandleCursor = pluginHandleCursor + 1;
        *tableDest = pluginHandle;
        tableDest = tableDest + 0xb8;
      } while (rendererIndex < *(byte *)(glContext + 0x85a4));
    }
    ((void (*)())_gleUpdateFramebufferDirtyBits)(glContext,pluginHandleArray);
    *(int *)(framebufferObject + 8) = *(int *)(framebufferObject + 8) + 1;
  }
  previousFramebuffer = *(int *)(glContext + 0x744c);
  *(int *)(glContext + 0x744c) = framebufferObject;
  if (noFramebuffer) {
    boundPluginHandle = 0;
  }
  else {
    boundPluginHandle = *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + framebufferObject + 0x10);
  }
  fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x4778))
                               (*(undefined4 *)(glContext + 0x4688), 0x5b, boundPluginHandle, 0);
  *(undefined1 *)(glContext + 0x7582) = *(undefined1 *)(*(int *)(glContext + 0x468c) + 0x25);
  if ((noFramebuffer) ||
     ((*(int *)(framebufferObject + 0xec) == 0 &&
      (((previousFramebuffer == 0 || (*(short *)(previousFramebuffer + 0xca) != *(short *)(framebufferObject + 0xca))) ||
       (*(short *)(previousFramebuffer + 0xcc) != *(short *)(framebufferObject + 0xcc))))))) {
    ((void (*)())_gleUpdateViewScissorData)(glContext,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  }
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000180;
  if (previousFramebuffer != 0) {
    slotsLeft = 6;
    oldSlotCursor = (int *)(previousFramebuffer + 0xd4);
    framebufferObject = previousFramebuffer;
    do {
      oldAttachedTexture = *oldSlotCursor;
      oldSlotCursor = oldSlotCursor + 1;
      if (oldAttachedTexture != 0) {
        oldAttachedTexture = oldAttachedTexture + *(int *)(framebufferObject + 0x34) * 0x168 + *(int *)(framebufferObject + 0x38) * 0x18;
        *(byte *)(oldAttachedTexture + 0xdf) = *(byte *)(oldAttachedTexture + 0xdf) & 0x7f;
      }
      framebufferObject = framebufferObject + 0x18;
      slotsLeft = slotsLeft + -1;
    } while (slotsLeft != 0);
    framebufferObject = *(int *)(previousFramebuffer + 8) + -1;
    *(int *)(previousFramebuffer + 8) = framebufferObject;
    if (framebufferObject == 0) {
      ((void (*)())_gleFreeFramebufferObject)(glContext,previousFramebuffer);
      return;
    }
  }
  return;
}

/* _gleFramebufferTexture @ 0xce000 (852 bytes) */
void _gleFramebufferTexture(glContext, attachmentIndex, targetIndex, textureObject, face, level, zoffset)
  int glContext;
  int attachmentIndex;
  undefined4 targetIndex;
  int textureObject;
  int face;
  uint level;
  undefined4 zoffset;
{
  undefined4 copiedWord;
  undefined4 *dstCursor;
  int attachmentBaseThenTemp;
  uint loopIndex;
  uint loopIndexThenMipLevel;
  undefined4 *srcCursor;
  undefined4 *nextLevelCursor;
  int attachmentSlotPtr;
  int levelOffset;
  int attachmentRecord;
  int oldAttachmentRecord;
  byte levelFlags;
  int oldTexture;
  undefined4 *dstCursor2;
  undefined4 *textureBody;
  
  attachmentBaseThenTemp = *(int *)(glContext + 0x744c) + 0x10;
  attachmentSlotPtr = attachmentIndex * 4 + attachmentBaseThenTemp;
  *(undefined4 *)(*(int *)(glContext + 0x744c) + 0xec) = 1;
  oldTexture = *(int *)(attachmentSlotPtr + 0xc4);
  *(int *)(attachmentSlotPtr + 0xc4) = textureObject;
  if (oldTexture != 0) {
    oldAttachmentRecord = attachmentIndex * 0x18 + attachmentBaseThenTemp;
    oldAttachmentRecord = oldTexture + *(int *)(oldAttachmentRecord + 0x24) * 0x168 + *(int *)(oldAttachmentRecord + 0x28) * 0x18;
    *(byte *)(oldAttachmentRecord + 0xdf) = *(byte *)(oldAttachmentRecord + 0xdf) & 0x7f;
  }
  if (textureObject == 0) {
    attachmentRecord = attachmentBaseThenTemp + attachmentIndex * 0x18;
    *(undefined4 *)(attachmentRecord + 0x20) = 0;
    *(undefined4 *)(attachmentRecord + 0x30) = 0;
    loopIndex = 0;
    *(undefined4 *)(attachmentRecord + 0x24) = 0;
    *(undefined4 *)(attachmentRecord + 0x28) = 0;
    *(undefined4 *)(attachmentRecord + 0x2c) = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      dstCursor2 = (undefined4 *)(attachmentIndex * 4 + attachmentBaseThenTemp + 0xe0);
      do {
        *dstCursor2 = 0;
        loopIndex = loopIndex + 1;
        *(undefined4 *)(attachmentBaseThenTemp + 0xf8) = 1;
        dstCursor2 = dstCursor2 + 8;
        *(undefined4 *)(attachmentBaseThenTemp + 0xfc) = 0;
        attachmentBaseThenTemp = attachmentBaseThenTemp + 0x20;
      } while (loopIndex < *(byte *)(glContext + 0x85a4));
    }
  }
  else {
    attachmentRecord = attachmentBaseThenTemp + attachmentIndex * 0x18;
    *(undefined4 *)(attachmentRecord + 0x20) = targetIndex;
    *(undefined4 *)(attachmentRecord + 0x2c) = zoffset;
    *(undefined4 *)(attachmentRecord + 0x30) = 0;
    *(int *)(attachmentRecord + 0x24) = face;
    loopIndexThenMipLevel = 0;
    *(uint *)(attachmentRecord + 0x28) = level;
    textureBody = (undefined4 *)(textureObject + 0x10);
    levelOffset = level * 0x18 + face * 0x168;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      dstCursor = (undefined4 *)(attachmentIndex * 4 + attachmentBaseThenTemp + 0xe0);
      srcCursor = textureBody;
      do {
        copiedWord = *srcCursor;
        loopIndexThenMipLevel = loopIndexThenMipLevel + 1;
        *(undefined4 *)(attachmentBaseThenTemp + 0xf8) = 1;
        srcCursor = srcCursor + 1;
        *dstCursor = copiedWord;
        dstCursor = dstCursor + 8;
        *(undefined4 *)(attachmentBaseThenTemp + 0xfc) = 0;
        attachmentBaseThenTemp = attachmentBaseThenTemp + 0x20;
      } while (loopIndexThenMipLevel < *(byte *)(glContext + 0x85a4));
    }
    *(undefined4 *)(textureObject + 0x30) =
         *(undefined4 *)
          ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
    attachmentBaseThenTemp = textureBody[face * 0x5a + level * 6 + 0x36];
    *(byte *)((int)textureBody + levelOffset + 0xcf) = *(byte *)((int)textureBody + levelOffset + 0xcf) | 0x80;
    if (attachmentBaseThenTemp != 0) {
      levelFlags = *(byte *)((int)textureBody + levelOffset + 0xcf);
      if (((levelFlags & 1) == 0) && (*(short *)(textureObject + 0x4e) == -0x7a43)) {
        _gleFreeTextureLevel(glContext,textureBody,textureBody + face * 0x5a + level * 6 + 0x31);
        levelFlags = *(byte *)((int)textureBody + levelOffset + 0xcf);
      }
      *(byte *)((int)textureBody + levelOffset + 0xcf) = levelFlags & 0xef;
      *(ushort *)((int)textureBody + face * 2 + 0xa0) =
           *(ushort *)((int)textureBody + face * 2 + 0xa0) &
           ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f)));
    }
    *(byte *)((int)textureBody + levelOffset + 0xcf) = *(byte *)((int)textureBody + levelOffset + 0xcf) | 0x40;
    if ((((*(uint *)(textureObject + 0x7c) & 0x8000) != 0) && ((int)*(short *)(textureObject + 0x70) == level)
        ) && (loopIndexThenMipLevel = level + 1, (int)loopIndexThenMipLevel <= (int)(uint)*(byte *)(textureObject + 0x93))) {
      nextLevelCursor = textureBody + face * 0x5a + loopIndexThenMipLevel * 6 + 0x31;
      do {
        if (nextLevelCursor[5] != 0) {
          if (((*(byte *)((int)nextLevelCursor + 0xb) & 1) == 0) && (*(short *)(textureObject + 0x4e) == -0x7a43))
          {
            _gleFreeTextureLevel(glContext,textureBody,nextLevelCursor);
          }
          *(byte *)((int)nextLevelCursor + 0xb) = *(byte *)((int)nextLevelCursor + 0xb) & 0xef;
          *(ushort *)((int)textureBody + face * 2 + 0xa0) =
               *(ushort *)((int)textureBody + face * 2 + 0xa0) & ~(ushort)(1 << (loopIndexThenMipLevel & 0x3f));
        }
        loopIndexThenMipLevel = loopIndexThenMipLevel + 1;
        *(byte *)((int)nextLevelCursor + 0xb) = *(byte *)((int)nextLevelCursor + 0xb) | 0x40;
        nextLevelCursor = nextLevelCursor + 6;
      } while ((int)loopIndexThenMipLevel <= (int)(uint)*(byte *)(textureObject + 0x93));
    }
    *(int *)(textureObject + 8) = *(int *)(textureObject + 8) + 1;
  }
  if ((oldTexture != 0) && (attachmentBaseThenTemp = *(int *)(oldTexture + 8) + -1, *(int *)(oldTexture + 8) = attachmentBaseThenTemp, attachmentBaseThenTemp == 0)) {
    _gleFreeTextureObject(glContext,oldTexture);
  }
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  return;
}

/* _gleCheckFramebufferAttachmentCompleteness @ 0xce354 (196 bytes) */
double _gleCheckFramebufferAttachmentCompleteness(unusedArg1, param_2, param_3, param_4)
  undefined4 unusedArg1;
  int param_2;
  int *param_3;
  int param_4;
{
  int iVar1;
  
  param_3[5] = 1;
  iVar1 = param_2 + param_3[1] * 0x168 + param_3[2] * 0x18;
  param_3[4] = *(int *)(iVar1 + 0xc4);
  if (*(short *)(iVar1 + 200) == 0) {
    return;
  }
  if (*(short *)(iVar1 + 0xca) == 0) {
    return;
  }
  if (*param_3 == 1) {
    if ((int)((uint)*(ushort *)(iVar1 + 0xcc) + (uint)*(byte *)(iVar1 + 0xce)) <= param_3[3]) {
      return;
    }
    if (param_3[3] < (int)-(uint)*(byte *)(iVar1 + 0xce)) {
      return;
    }
  }
  if (((param_4 < 4) && (*(short *)(param_2 + 0x26) != 0x1907)) &&
     (*(short *)(param_2 + 0x26) != 0x1908)) {
    return;
  }
  if ((param_4 == 4) && (*(short *)(param_2 + 0x26) != 0x1902)) {
    return;
  }
  if ((param_4 == 5) && (*(short *)(param_2 + 0x26) != 0x1901)) {
    return;
  }
  param_3[5] = 0;
  return;
}

/* _gleUpdateFramebufferCompleteness @ 0xce418 (588 bytes) */
void _gleUpdateFramebufferCompleteness(int glContext,int framebufferObject,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,undefined4 unusedArg6,undefined4 unusedArg7,double fparam_1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  ushort drawBufferEnum;
  undefined4 framebufferStatus;
  int attachedImage;
  uint uVar4;
  int iVar5;
  int *piVar6;
  ushort *drawBufferPtr;
  short colorAttachmentFormat;
  int attachmentIndex;
  uint distinctImageCount;
  int *attachmentSlotPtr;
  int iVar12;
  int seenImages [8];
  
  colorAttachmentFormat = 0;
  *(undefined1 *)(glContext + 0x759d) = 0;
  *(undefined4 *)(framebufferObject + 0xdc) = 0;
  *(undefined2 *)(framebufferObject + 0xba) = 0;
  attachmentIndex = 0;
  *(undefined2 *)(framebufferObject + 0xbc) = 0;
  attachmentSlotPtr = (int *)(framebufferObject + 0xc4);
  distinctImageCount = 0;
  iVar12 = framebufferObject;
  do {
    iVar5 = *attachmentSlotPtr;
    attachmentSlotPtr = attachmentSlotPtr + 1;
    uVar4 = distinctImageCount;
    if (iVar5 != 0) {
      attachedImage = iVar5 + 0x10 + *(int *)(iVar12 + 0x24) * 0x168 + *(int *)(iVar12 + 0x28) * 0x18;
      if (*(int *)(iVar12 + 0x30) != *(int *)(attachedImage + 0xc4)) {
        fparam_1 = (double)((double (*)())_gleCheckFramebufferAttachmentCompleteness)(glContext,iVar5 + 0x10,iVar12 + 0x20,attachmentIndex);
      }
      if (*(int *)(iVar12 + 0x34) != 0) {
        framebufferStatus = 0x8cd6;
        goto LAB_000ce630;
      }
      if (*(short *)(framebufferObject + 0xba) == 0) {
        *(undefined2 *)(framebufferObject + 0xba) = *(undefined2 *)(attachedImage + 200);
        *(undefined2 *)(framebufferObject + 0xbc) = *(undefined2 *)(attachedImage + 0xca);
      }
      else if ((*(short *)(framebufferObject + 0xba) != *(short *)(attachedImage + 200)) ||
              (*(short *)(framebufferObject + 0xbc) != *(short *)(attachedImage + 0xca))) {
        *(undefined4 *)(framebufferObject + 0xc0) = 0x8cd9;
        return;
      }
      if (attachmentIndex < 4) {
        if (colorAttachmentFormat == 0) {
          colorAttachmentFormat = *(short *)(iVar5 + 0x88);
        }
        else if (colorAttachmentFormat != *(short *)(iVar5 + 0x88)) {
          framebufferStatus = 0x8cda;
          goto LAB_000ce630;
        }
      }
      uVar4 = 0;
      if (distinctImageCount != 0) {
        piVar6 = seenImages;
        do {
          iVar5 = *piVar6;
          piVar6 = piVar6 + 1;
          if (iVar5 == attachedImage + 0xc4) {
            framebufferStatus = 0x8cd8;
            goto LAB_000ce630;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < distinctImageCount);
      }
      uVar4 = distinctImageCount + 1;
      seenImages[distinctImageCount] = attachedImage + 0xc4;
    }
    attachmentIndex = attachmentIndex + 1;
    iVar12 = iVar12 + 0x18;
    distinctImageCount = uVar4;
  } while (attachmentIndex < 6);
  if (uVar4 == 0) {
    framebufferStatus = 0x8cd7;
  }
  else {
    iVar12 = 0;
    drawBufferPtr = (ushort *)(framebufferObject + 0xb0);
    do {
      drawBufferEnum = *drawBufferPtr;
      drawBufferPtr = drawBufferPtr + 1;
      if ((drawBufferEnum != 0) && (*(int *)((drawBufferEnum - 0x8ce0) * 4 + framebufferObject + 0xc4) == 0)) {
        framebufferStatus = 0x8cdb;
        goto LAB_000ce630;
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < 4);
    if ((*(ushort *)(framebufferObject + 0xb8) == 0) ||
       (*(int *)((*(ushort *)(framebufferObject + 0xb8) - 0x8ce0) * 4 + framebufferObject + 0xc4) != 0)) {
      ((void (*)())_gleUpdateViewScissorData)(glContext,fparam_1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
      *(undefined4 *)(framebufferObject + 0xc0) = 0;
      *(undefined1 *)(glContext + 0x759d) = 1;
      return;
    }
    framebufferStatus = 0x8cdc;
  }
LAB_000ce630:
  *(undefined4 *)(framebufferObject + 0xc0) = framebufferStatus;
  return;
}

/* _gleCheckFramebufferStatus @ 0xce664 (1200 bytes) */
int _gleCheckFramebufferStatus(int glContext,int framebufferRecord,int *param_3,undefined4 forwardedArg4,undefined4 forwardedArg5,undefined4 forwardedArg6,undefined4 forwardedArg7,double fparam_1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  bool rendererInfoByte79Clear;
  bool stateClean;
  char rendererInfoByte79;
  int *dirtyBitArrayCursor;
  int dirtyBitArrayWord;
  int framebufferObject;
  int matrixFuncDirty;
  int statusCode;
  int remaining;
  int clearIndex;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  double f1AfterCall1;
  double extraout_f1_01;
  double f1AfterCall3;
  double f1AfterCall4;
  
  if (*(int *)(framebufferRecord + 0xdc) != 0) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferRecord,param_3,forwardedArg4,forwardedArg5,forwardedArg6,forwardedArg7,fparam_1,floatArg2,floatArg3,
               floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
    fparam_1 = fparam_1;
  }
  if (*(int *)(framebufferRecord + 0xc0) != 0) {
    return *(int *)(framebufferRecord + 0xc0);
  }
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = f1AfterCall1;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    dirtyFlagWords = (int *)(glContext + 0x310);
    rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,param_3,forwardedArg4,forwardedArg5,forwardedArg6,matrixFuncDirty,fparam_1,floatArg2,
                 floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000ce7a4:
      dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      dirtyBitArrayCursor = (int *)(glContext + 0x324);
      do {
        dirtyBitArrayWord = *dirtyBitArrayCursor;
        dirtyBitArrayCursor = dirtyBitArrayCursor + 1;
        if (dirtyBitArrayWord != 0) {
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
        goto LAB_000ce7a4;
      }
    }
    rendererInfoByte79Clear = rendererInfoByte79 == '\0';
    if (rendererInfoByte79Clear) {
      dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
    }
    else {
      dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
    }
    if (rendererInfoByte79Clear) {
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
           (fparam_1 = f1AfterCall3, (dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0')))
        {
          if ((dispatchFlags & 4) == 0) {
            dispatchFlags = dispatchFlags & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
      }
    }
    clearIndex = 0;
    param_3 = dirtyFlagWords;
    do {
      clearIndex = clearIndex + 1;
      *param_3 = 0;
      param_3 = param_3 + 1;
    } while (clearIndex < 0x13);
  }
  if (-1 < *(int *)((uint)*(byte *)(glContext + 0x85a8) * 0x20 + framebufferRecord + 0xfc)) goto LAB_000cead8;
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = f1AfterCall4;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_000cead8;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,param_3,forwardedArg4,forwardedArg5,forwardedArg6,matrixFuncDirty,fparam_1,floatArg2,floatArg3
               ,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000ce9d4:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    dirtyBitArrayCursor = (int *)(glContext + 0x324);
    do {
      dirtyBitArrayWord = *dirtyBitArrayCursor;
      dirtyBitArrayCursor = dirtyBitArrayCursor + 1;
      if (dirtyBitArrayWord != 0) {
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
      goto LAB_000ce9d4;
    }
  }
  rendererInfoByte79Clear = rendererInfoByte79 == '\0';
  if (rendererInfoByte79Clear) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (rendererInfoByte79Clear) {
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
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
  }
  remaining = 0x13;
  do {
    *dirtyFlagWords = 0;
    dirtyFlagWords = dirtyFlagWords + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
LAB_000cead8:
  statusCode = 0x8cdd;
  if ((*(uint *)((uint)*(byte *)(glContext + 0x85a8) * 0x20 + framebufferRecord + 0xfc) & 1) == 0) {
    statusCode = 0x8cd5;
  }
  return statusCode;
}

/* _gleSynchronizePluginFramebuffer @ 0xceb14 (172 bytes) */
int _gleSynchronizePluginFramebuffer(glContext)
  int glContext;
{
  int iVar1;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int iVar2;
  int *piVar3;
  
  iVar2 = glContext;
  if (*(int *)(glContext + 0x744c) != 0) {
    piVar3 = (int *)(*(int *)(glContext + 0x744c) + 0xd4);
    iVar2 = 5;
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      if (iVar1 != 0) {
        _gleSynchronizePluginTextureLevels(glContext,iVar1 + 0x10);
      }
      iVar2 = iVar2 + -1;
    } while (-1 < iVar2);
    iVar1 = (uint)*(byte *)(glContext + 0x85a6) * 4 + *(int *)(glContext + 0x744c);
    iVar2 = (uint)*(byte *)(glContext + 0x85a6) * 0x2e0 + glContext;
    iVar2 = (**(code **)(*(int *)(iVar2 + 0x8884) + 0x138))
                      (*(undefined4 *)(iVar2 + 0x85ac),0x5b,*(undefined4 *)(iVar1 + 0x10),0,incomingR7,
                       incomingR8,iVar1);
  }
  *(undefined1 *)(glContext + 0x7582) = *(undefined1 *)(*(int *)(glContext + 0x468c) + 0x25);
  return iVar2;
}

/* _gleFreeFramebufferState @ 0xcebc0 (256 bytes) */
void _gleFreeFramebufferState(glContext)
  int glContext;
{
  int framebufferRefCount;
  int textureObject;
  int framebufferObjectThenRefCount;
  
  framebufferObjectThenRefCount = *(int *)(glContext + 0x744c);
  textureObject = *(int *)(glContext + 0x7448);
  if (framebufferObjectThenRefCount != 0) {
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    framebufferRefCount = *(int *)(framebufferObjectThenRefCount + 8) + -1;
    *(int *)(framebufferObjectThenRefCount + 8) = framebufferRefCount;
    if (framebufferRefCount == 0) {
      ((void (*)())_gleFreeFramebufferObject)(glContext,framebufferObjectThenRefCount);
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (textureObject != 0) {
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    framebufferObjectThenRefCount = *(int *)(textureObject + 8) + -1;
    *(int *)(textureObject + 8) = framebufferObjectThenRefCount;
    if (framebufferObjectThenRefCount == 0) {
      _gleFreeTextureObject(glContext,textureObject);
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
  }
  return;
}

/* _gleGenerateMipmap @ 0xcecc0 (208 bytes) */
void _gleGenerateMipmap(glContext, target)
  int glContext;
  undefined4 target;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  puVar3 = (undefined4 *)_gleLookUpNonProxyTexture(glContext,target);
  if ((*(ushort *)(puVar3 + 9) & 0xf) != 2) {
    iVar5 = 6;
    if ((*(ushort *)(puVar3 + 9) & 0xf) != 0) {
      iVar5 = 1;
    }
    iVar6 = 0;
    if (iVar5 != 0) {
      do {
        iVar7 = iVar6 + 1;
        _gleGenMipmapsToLevel
                  (glContext,puVar3,iVar6,(int)*(short *)(puVar3 + 0x18),
                   (int)*(short *)((int)puVar3 + 0x62),0);
        iVar6 = iVar7;
      } while (iVar7 < iVar5);
    }
    iVar5 = glContext + 0x10000;
    iVar6 = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      do {
        piVar1 = (int *)(iVar5 + -0x777c);
        uVar4 = *puVar3;
        iVar6 = iVar6 + 1;
        puVar3 = puVar3 + 1;
        puVar2 = (undefined4 *)(iVar5 + -0x7a54);
        iVar5 = iVar5 + 0x2e0;
        (**(code **)(*piVar1 + 0x154))(*puVar2,uVar4,0x80);
      } while (iVar6 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
  }
  return;
}

/* _gleFogExp2 @ 0xced90 (56 bytes) */
double _gleFogExp2(int glContext,float floatArg1)
{
  float densityDistanceThenNegSquare;
  float one;
  
  densityDistanceThenNegSquare = (*(float *)(glContext + 0x3150) * floatArg1);
  one = *(float *)(glContext + 0x24);
  densityDistanceThenNegSquare = densityDistanceThenNegSquare * -densityDistanceThenNegSquare;
  return (double)(one / ((((*(float *)(glContext + 0x38) * densityDistanceThenNegSquare - *(float *)(glContext + 0x34)) *
                             densityDistanceThenNegSquare + *(float *)(glContext + 0x30)) * densityDistanceThenNegSquare - one) * densityDistanceThenNegSquare + one));
}

/* _gleLFSParse @ 0xcedc8 (612 bytes) */
void _gleLFSParse(glContext)
  int glContext;
{
  uint usageFlags;
  int slotCursor;
  int stream;
  int parseStatus;
  int chunk;
  uint listIndex;
  uint newUsageFlags;
  undefined4 sourceString;
  undefined4 streamBuffer;
  int *chunkList;
  int oldStream;
  int parser;
  int programObject;
  int remaining;
  int streamSize [7];
  
  programObject = *(int *)(glContext + 0x5424);
  chunkList = (int *)0x0;
  sourceString = *(undefined4 *)(programObject + 0x14);
  oldStream = *(int *)(programObject + 0x4e4);
  if (*(int *)(programObject + 0x4cc) != 0) {
    _gleVecFree(*(int *)(programObject + 0x4cc));
    *(undefined4 *)(programObject + 0x4cc) = 0;
  }
  if (oldStream != 0) {
    _LFSStreamFree(oldStream);
  }
  parser = ((int (*)())_LFSParserCreate)();
  ((int (*)())_LFSParserAttachString)(parser,sourceString,1);
  stream = _LFSStreamCreate();
  ((void (*)())_LFSParserAttachStream)(parser,stream);
  parseStatus = ((int (*)())_LFSParserParse)(parser);
  if (parseStatus == 0) {
    *(undefined4 *)(programObject + 0x4e8) = 0;
    listIndex = 0;
    do {
      if (listIndex == 0) {
        chunkList = *(int **)(stream + 4);
      }
      if (listIndex == 1) {
        chunkList = *(int **)(stream + 0xc);
      }
      for (chunk = *chunkList; chunk != 0; chunk = *(int *)(chunk + 0x4c)) {
        if (*(int *)(chunk + 8) == 5) {
          switch(*(undefined4 *)(chunk + 0xc)) {
          case 0:
            usageFlags = *(uint *)(programObject + 0x4e8) | 1;
            break;
          case 1:
            usageFlags = *(uint *)(programObject + 0x4e8) | 2;
            break;
          case 2:
            usageFlags = *(uint *)(programObject + 0x4e8) | 4;
            break;
          case 3:
            usageFlags = *(uint *)(programObject + 0x4e8) | 8;
            break;
          case 4:
            usageFlags = *(uint *)(programObject + 0x4e8) | 0x10;
            break;
          case 5:
            usageFlags = *(uint *)(programObject + 0x4e8) | 0x20;
            break;
          case 6:
            usageFlags = *(uint *)(programObject + 0x4e8) | 0x40;
            break;
          case 7:
            usageFlags = *(uint *)(programObject + 0x4e8) | 0x80;
            break;
          default:
            goto switchD_000ceebc_default;
          }
          *(uint *)(programObject + 0x4e8) = usageFlags;
        }
switchD_000ceebc_default: ;
      }
      listIndex = listIndex + 1;
    } while (listIndex < 2);
    for (chunk = **(int **)(stream + 0x10); chunk != 0; chunk = *(int *)(chunk + 0x4c)) {
      slotCursor = chunk + 4;
      remaining = 3;
      do {
        if (*(int *)(slotCursor + 0x14) == 4) {
          if (*(int *)(slotCursor + 0x18) == 0) {
            newUsageFlags = *(uint *)(programObject + 0x4e8) | 0x100;
          }
          else {
            if (*(int *)(slotCursor + 0x18) != 1) goto LAB_000cefac;
            newUsageFlags = *(uint *)(programObject + 0x4e8) | 0x200;
          }
          *(uint *)(programObject + 0x4e8) = newUsageFlags;
        }
LAB_000cefac:
        slotCursor = slotCursor + 0x10;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
    *(int *)(programObject + 0x4e4) = stream;
    _LFSStreamGetStream(stream,0,streamSize);
    streamBuffer = _gleVecAlloc(streamSize[0] << 2);
    *(undefined4 *)(programObject + 0x4cc) = streamBuffer;
    _LFSStreamGetStream(stream,streamBuffer,streamSize);
    **(undefined1 **)(glContext + 0x5418) = 0;
    *(undefined4 *)(glContext + 0x541c) = 0xffffffff;
  }
  else {
    _snprintf(*(char **)(glContext + 0x5418),0x600,"Error on line %i: %s;",*(int *)(parser + 0x460) + 1
              ,parser + 0x5c);
    *(undefined4 *)(glContext + 0x541c) = 0;
  }
  ((void (*)())_LFSParserFree)(parser);
  return;
}

/* _LFSParserCreate @ 0xcf04c (60 bytes) */
int _LFSParserCreate()
{
  undefined4 uVar1;
  
  uVar1 = _calloc(0x46c,1);
  ((int (*)())_LFSParserInit)(uVar1);
  return uVar1;
}

/* _LFSParserInit @ 0xcf088 (12 bytes) */
int _LFSParserInit(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  
  uVar1 = _memset(param_1,0,0x46c);
  return uVar1;
}

/* _LFSParserShutdown @ 0xcf094 (12 bytes) */
int _LFSParserShutdown(parser)
  undefined4 parser;
{
  undefined4 attachResult;
  
  attachResult = ((int (*)())_LFSParserAttachString)(parser,0,0);
  return attachResult;
}

/* _LFSParserFree @ 0xcf0a0 (48 bytes) */
void _LFSParserFree(parser)
  undefined4 parser;
{
  ((int (*)())_LFSParserShutdown)(parser);
  _free(parser);
  return;
}

/* _LFSParserAttachStream @ 0xcf0d0 (64 bytes) */
void _LFSParserAttachStream(parser, stream)
  int parser;
  undefined4 stream;
{
  if (*(int *)(parser + 0x14) != 0) {
    _LFSStreamFree(*(int *)(parser + 0x14));
  }
  *(undefined4 *)(parser + 0x14) = stream;
  return;
}

/* _LFSParserCheckForNewline @ 0xcf110 (96 bytes) */
int _LFSParserCheckForNewline(unusedArg1, param_2, param_3, param_4, param_5)
  undefined4 unusedArg1;
  int param_2;
  int param_3;
  uint param_4;
  undefined4 *param_5;
{
  char cVar1;
  
  if (param_3 + 1U < param_4) {
    cVar1 = *(char *)(param_2 + param_3);
    if ((cVar1 == '\r') && (*(char *)(param_2 + param_3 + 1) == '\n')) {
      *param_5 = 2;
      return true;
    }
  }
  else {
    cVar1 = *(char *)(param_2 + param_3);
  }
  if (cVar1 == '\n') {
    return true;
  }
  return cVar1 == '\r';
}

/* _LFSParserPreprocessString @ 0xcf170 (568 bytes) */
int _LFSParserPreprocessString(forwardedArg1, sourceString)
  undefined4 forwardedArg1;
  int sourceString;
{
  char currentChar;
  bool inComment;
  uint sourceLength;
  int newlineFound;
  undefined1 *processedString;
  uint sourceIndex;
  int iVar7;
  undefined1 *outputCursor;
  int sourceAdvance [5];
  
  sourceIndex = 0;
  sourceLength = _strlen(sourceString);
  inComment = false;
  iVar7 = 0;
  if (sourceLength != 0) {
    do {
      sourceAdvance[0] = 1;
      if (inComment) {
        newlineFound = ((int (*)())_LFSParserCheckForNewline)(forwardedArg1,sourceString,sourceIndex,sourceLength,sourceAdvance);
        if ((newlineFound != 0) || (*(char *)(sourceString + sourceIndex) == '\0')) {
          inComment = false;
        }
LAB_000cf24c:
        iVar7 = iVar7 + 1;
      }
      else {
        currentChar = *(char *)(sourceString + sourceIndex);
        if (currentChar != '#') {
          if (((((currentChar == '[') || (currentChar == ']')) || (currentChar == '=')) ||
              ((currentChar == '{' || (currentChar == '}')))) ||
             ((currentChar == ';' || ((currentChar == '.' || (currentChar == ',')))))) {
            iVar7 = iVar7 + 2;
          }
          goto LAB_000cf24c;
        }
        inComment = true;
      }
      sourceIndex = sourceIndex + sourceAdvance[0];
    } while (sourceIndex < sourceLength);
  }
  sourceIndex = 0;
  processedString = (undefined1 *)_calloc(iVar7 + 1,1);
  inComment = false;
  outputCursor = processedString;
  if (sourceLength != 0) {
    do {
      sourceAdvance[0] = 1;
      if (inComment) {
        iVar7 = ((int (*)())_LFSParserCheckForNewline)(forwardedArg1,sourceString,sourceIndex,sourceLength,sourceAdvance);
        if (iVar7 != 0) {
          *outputCursor = 10;
          inComment = false;
          outputCursor = outputCursor + 1;
        }
        if (*(char *)(sourceString + sourceIndex) == '\0') {
          inComment = false;
          *outputCursor = 0;
          goto LAB_000cf37c;
        }
      }
      else {
        currentChar = *(char *)(sourceString + sourceIndex);
        if (currentChar == '#') {
          inComment = true;
        }
        else {
          if ((((currentChar == '[') || (currentChar == ']')) || (currentChar == '=')) ||
             (((currentChar == '{' || (currentChar == '}')) ||
              ((currentChar == ';' || ((currentChar == '.' || (currentChar == ',')))))))) {
            *outputCursor = 0x20;
            outputCursor[1] = currentChar;
            outputCursor = outputCursor + 2;
            *outputCursor = 0x20;
          }
          else {
            iVar7 = ((int (*)())_LFSParserCheckForNewline)(forwardedArg1,sourceString,sourceIndex,sourceLength,sourceAdvance);
            if (iVar7 == 0) {
              *outputCursor = *(undefined1 *)(sourceString + sourceIndex);
            }
            else {
              *outputCursor = 10;
            }
          }
LAB_000cf37c:
          outputCursor = outputCursor + 1;
        }
      }
      sourceIndex = sourceIndex + sourceAdvance[0];
    } while (sourceIndex < sourceLength);
  }
  return processedString;
}

/* _LFSParserAttachString @ 0xcf3a8 (252 bytes) */
int _LFSParserAttachString(parser, sourceString, preprocessFlag)
  int *parser;
  int sourceString;
  int preprocessFlag;
{
  int iVar1;
  int textCopy;
  uint textLength;
  uint scanPosition;
  int stepLength [4];
  
  if (*parser == 0) {
    if (sourceString != 0) {
      if (preprocessFlag == 0) {
        iVar1 = _strlen(sourceString);
        textCopy = _calloc(iVar1 + 1,1);
        *parser = textCopy;
        _memmove(textCopy,sourceString,iVar1);
      }
      else {
        iVar1 = ((int (*)())_LFSParserPreprocessString)(parser,sourceString);
        *parser = iVar1;
      }
      scanPosition = 0;
      textLength = _strlen(*parser);
      parser[2] = 0;
      parser[1] = textLength;
      if (textLength != 0) {
        do {
          stepLength[0] = 1;
          iVar1 = ((int (*)())_LFSParserCheckForNewline)(parser,*parser,scanPosition,textLength,stepLength);
          if (iVar1 != 0) {
            parser[2] = parser[2] + 1;
          }
          textLength = parser[1];
          scanPosition = scanPosition + stepLength[0];
        } while (scanPosition < textLength);
      }
    }
  }
  else {
    _free(*parser);
    parser[1] = 0;
    *parser = 0;
  }
  return;
}

/* _LFSParserEatWhiteSpace @ 0xcf4a4 (76 bytes) */
void _LFSParserEatWhiteSpace(parser)
  int *parser;
{
  uint currentChar;
  int position;
  
  while( true ) {
    position = parser[3];
    if (position == parser[1]) {
      return;
    }
    currentChar = (uint)*(byte *)(*parser + position);
    if ((1 < currentChar - 9) && (currentChar != 0x20)) break;
    parser[3] = position + 1;
    if (currentChar == 10) {
      parser[4] = parser[4] + 1;
    }
  }
  return;
}

/* _LFSParserGetCharacter @ 0xcf4f0 (252 bytes) */
int _LFSParserGetCharacter(parser, outChar, backward)
  int *parser;
  byte *outChar;
  int backward;
{
  bool forward;
  bool pendingWhitespace;
  bool charProduced;
  int cursor;
  uint charValue;
  
  forward = backward == 0;
  charProduced = false;
  pendingWhitespace = false;
  do {
    if (forward) {
      cursor = parser[3];
      if (cursor == parser[1]) {
        return 1;
      }
    }
    else {
      if (parser[3] == 0) {
        return 1;
      }
      cursor = parser[3] + -1;
      parser[3] = cursor;
    }
    *outChar = *(byte *)(*parser + cursor);
    if (forward) {
      parser[3] = parser[3] + 1;
    }
    charValue = (uint)*outChar;
    if (charValue == 10) {
      if (forward) {
        cursor = parser[4] + 1;
      }
      else {
        cursor = parser[4] + -1;
      }
      parser[4] = cursor;
      charValue = (uint)*outChar;
    }
    if ((charValue - 9 < 2) || ((char)charValue == ' ')) {
      if (parser[3] == parser[1]) {
        *outChar = 0x20;
        goto LAB_000cf5b0;
      }
      pendingWhitespace = true;
    }
    else {
LAB_000cf5b0:
      if (pendingWhitespace) {
        *outChar = 0x20;
        if (forward) {
          cursor = parser[3] + -1;
        }
        else {
          cursor = parser[3] + 1;
        }
        parser[3] = cursor;
      }
      charProduced = true;
    }
    if (charProduced) {
      return 0;
    }
  } while( true );
}

/* _LFSParserRewind @ 0xcf5ec (92 bytes) */
int _LFSParserRewind(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  undefined1 auStack_20 [20];
  
  iVar1 = 0;
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      iVar1 = ((int (*)())_LFSParserGetCharacter)(param_1,auStack_20,1);
      if (param_2 == 0) {
        return iVar1;
      }
    } while (iVar1 == 0);
  }
  return iVar1;
}

/* _LFSParserGetPart @ 0xcf648 (188 bytes) */
int _LFSParserGetPart(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  char local_30 [16];
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = *(undefined4 *)(param_1 + 0xc);
  local_1c = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x45c) = local_20;
  *(undefined4 *)(param_1 + 0x460) = local_1c;
  local_30[0] = '\0';
  ((void (*)())_LFSParserEatWhiteSpace)(param_1);
  uVar2 = 0;
  do {
    iVar1 = ((int (*)())_LFSParserGetCharacter)(param_1,local_30,0);
    if (iVar1 != 0) break;
    if (local_30[0] == ' ') {
      ((int (*)())_LFSParserRewind)(param_1,1);
      break;
    }
    *(char *)(param_2 + uVar2) = local_30[0];
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xff);
  *(undefined1 *)(param_2 + uVar2) = 0;
  if ((uVar2 == 0) || (uVar2 == 0xff)) {
    uVar2 = 0;
  }
  return uVar2;
}

/* _LFSParserGetScalars @ 0xcf704 (400 bytes) */
int _LFSParserGetScalars(param_1, param_2, param_3)
  int param_1;
  float *param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  char local_350 [256];
  char local_250 [256];
  undefined1 auStack_150 [256];
  undefined4 local_50;
  undefined4 local_4c;
  char *local_40 [7];
  
  uVar1 = 0;
  if (*param_3 != 0) {
    local_50 = *(undefined4 *)(param_1 + 0xc);
    local_4c = *(undefined4 *)(param_1 + 0x10);
    iVar3 = 0;
    do {
      iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_350);
      if (iVar2 == 0) {
        return 8;
      }
      local_50 = *(undefined4 *)(param_1 + 0xc);
      local_4c = *(undefined4 *)(param_1 + 0x10);
      iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_250);
      if (iVar2 == 0) {
        return 8;
      }
      if (local_250[0] == '.') {
        iVar2 = ((int (*)())_LFSParserGetPart)(param_1,auStack_150);
        if (iVar2 == 0) {
          return 8;
        }
        _strcat(local_350,local_250);
        _strcat(local_350,auStack_150);
      }
      else {
        *(undefined4 *)(param_1 + 0x10) = local_4c;
        *(undefined4 *)(param_1 + 0xc) = local_50;
      }
      dVar4 = (double)((double (*)())_gle_strtod)(local_350,local_40);
      *param_2 = (float)dVar4;
      if (local_40[0] == local_350) {
        uVar1 = 9;
        goto LAB_000cf86c;
      }
      iVar3 = iVar3 + 1;
      param_2 = param_2 + 1;
      uVar1 = 0;
      if (iVar3 == *param_3) goto LAB_000cf878;
      local_50 = *(undefined4 *)(param_1 + 0xc);
      local_4c = *(undefined4 *)(param_1 + 0x10);
      iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_350);
      if (iVar2 == 0) {
        return 8;
      }
    } while (local_350[0] == ',');
    uVar1 = 10;
LAB_000cf86c:
    *(undefined4 *)(param_1 + 0x10) = local_4c;
    *(undefined4 *)(param_1 + 0xc) = local_50;
LAB_000cf878:
    *param_3 = iVar3;
  }
  return uVar1;
}

/* _LFSParserParseArray @ 0xcf894 (188 bytes) */
int _LFSParserParseArray(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  int iVar1;
  int iVar2;
  char local_130 [256];
  undefined4 local_30 [4];
  int local_20 [5];
  
  local_20[0] = 1;
  iVar1 = ((int (*)())_LFSParserGetPart)(param_1,local_130);
  iVar2 = 8;
  if ((((iVar1 != 0) && (iVar2 = 0x10, local_130[0] == '[')) &&
      (iVar2 = ((int (*)())_LFSParserGetScalars)(param_1,local_30,local_20), iVar2 == 0)) &&
     (iVar2 = 0x10, local_20[0] == 1)) {
    *param_2 = local_30[0];
    iVar1 = ((int (*)())_LFSParserGetPart)(param_1,local_130);
    iVar2 = 8;
    if (iVar1 != 0) {
      iVar2 = (uint)(local_130[0] != ']') * 0x10;
    }
  }
  return iVar2;
}

/* _LFSParserParseRegister @ 0xcf950 (356 bytes) */
int _LFSParserParseRegister(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  uint *param_3;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  char local_110;
  undefined1 auStack_10f [259];
  
  iVar4 = ((int (*)())_LFSParserGetPart)(param_1,&local_110);
  if (iVar4 == 0) {
    return 8;
  }
  iVar4 = _memcmp(&local_110,"color0",7);
  if (iVar4 == 0) {
    *param_2 = 4;
    *param_3 = 0;
    return 0;
  }
  iVar4 = _memcmp(&local_110,"color1",7);
  uVar2 = 4;
  if (iVar4 == 0) {
LAB_000cfa84:
    *param_2 = uVar2;
    uVar3 = 1;
LAB_000cfa8c:
    *param_3 = uVar3;
  }
  else {
    if (local_110 == 'c') {
      *param_2 = 2;
      uVar3 = _atoi(auStack_10f);
      bVar1 = 8 < uVar3;
      *param_3 = uVar3;
      uVar2 = 5;
    }
    else {
      if (local_110 < 'd') {
        if (local_110 != '0') {
          if (local_110 != '1') {
            return 5;
          }
          uVar2 = 3;
          goto LAB_000cfa84;
        }
        uVar3 = 0;
        *param_2 = 3;
        goto LAB_000cfa8c;
      }
      if (local_110 == 'r') {
        *param_2 = 1;
        uVar3 = _atoi(auStack_10f);
        bVar1 = 6 < uVar3;
        *param_3 = uVar3;
        uVar2 = 0x1d;
      }
      else {
        if (local_110 != 't') {
          return 5;
        }
        *param_2 = 5;
        uVar3 = _atoi(auStack_10f);
        bVar1 = 6 < uVar3;
        *param_3 = uVar3;
        uVar2 = 0x1e;
      }
    }
    if (bVar1) {
      return uVar2;
    }
  }
  return 0;
}

/* _LFSParserParseDestinationMask @ 0xcfab4 (244 bytes) */
int _LFSParserParseDestinationMask(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char local_110 [264];
  
  uVar4 = ((int (*)())_LFSParserGetPart)(param_1,local_110);
  iVar5 = 8;
  if (uVar4 != 0) {
    *(undefined4 *)(param_2 + 8) = 0;
    uVar3 = 0;
    iVar5 = 0;
    if (uVar4 != 0) {
      do {
        cVar1 = local_110[uVar3];
        if (cVar1 == 'b') {
          if ((*(uint *)(param_2 + 8) & 0x40000) == 0) {
            uVar2 = *(uint *)(param_2 + 8) | 0x40000;
            goto LAB_000cfb70;
          }
LAB_000cfb78:
          iVar5 = 6;
        }
        else {
          if (cVar1 < 'c') {
            if ((cVar1 == 'a') && ((*(uint *)(param_2 + 8) & 0x80000) == 0)) {
              uVar2 = *(uint *)(param_2 + 8) | 0x80000;
              goto LAB_000cfb70;
            }
            goto LAB_000cfb78;
          }
          if (cVar1 != 'g') {
            if ((cVar1 == 'r') && ((*(uint *)(param_2 + 8) & 0x10000) == 0)) {
              uVar2 = *(uint *)(param_2 + 8) | 0x10000;
              goto LAB_000cfb70;
            }
            goto LAB_000cfb78;
          }
          if ((*(uint *)(param_2 + 8) & 0x20000) != 0) goto LAB_000cfb78;
          uVar2 = *(uint *)(param_2 + 8) | 0x20000;
LAB_000cfb70:
          *(uint *)(param_2 + 8) = uVar2;
        }
        uVar3 = uVar3 + 1;
      } while ((uVar3 < uVar4) && (iVar5 == 0));
    }
  }
  return iVar5;
}

/* _LFSParserParseDestinationModifiers @ 0xcfba8 (460 bytes) */
int _LFSParserParseDestinationModifiers(parser, destination)
  int parser;
  int destination;
{
  uint modifierBits;
  int partOrCompareResult;
  undefined4 status;
  char tokenBuffer [256];
  undefined4 savedCursor;
  undefined4 savedLine;
  
  partOrCompareResult = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
  status = 8;
  if (partOrCompareResult != 0) {
    partOrCompareResult = _memcmp(tokenBuffer,"2x",3);
    modifierBits = 0x1000;
    if (partOrCompareResult != 0) {
      partOrCompareResult = _memcmp(tokenBuffer,"4x",3);
      modifierBits = 0x2000;
      if (partOrCompareResult != 0) {
        partOrCompareResult = _memcmp(tokenBuffer,"8x",3);
        modifierBits = 0x3000;
        if (partOrCompareResult != 0) {
          partOrCompareResult = _memcmp(tokenBuffer,"half",5);
          modifierBits = 0x4000;
          if (partOrCompareResult != 0) {
            partOrCompareResult = _memcmp(tokenBuffer,"quarter",8);
            modifierBits = 0x5000;
            if (partOrCompareResult != 0) {
              partOrCompareResult = _memcmp(tokenBuffer,"eighth",7);
              modifierBits = 0x6000;
              if (partOrCompareResult != 0) {
                partOrCompareResult = _memcmp(tokenBuffer,"sat",4);
                if (partOrCompareResult != 0) {
                  return 7;
                }
                modifierBits = *(uint *)(destination + 0xc) | 0x8000;
              }
            }
          }
        }
      }
    }
    *(uint *)(destination + 0xc) = modifierBits;
    savedCursor = *(undefined4 *)(parser + 0xc);
    savedLine = *(undefined4 *)(parser + 0x10);
    partOrCompareResult = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
    status = 8;
    if (partOrCompareResult != 0) {
      if (tokenBuffer[0] == '.') {
        partOrCompareResult = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
        status = 8;
        if (partOrCompareResult != 0) {
          partOrCompareResult = _memcmp(tokenBuffer,"sat",4);
          status = 7;
          if (partOrCompareResult == 0) {
            status = 0;
            *(uint *)(destination + 0xc) = *(uint *)(destination + 0xc) | 0x8000;
          }
        }
      }
      else {
        status = 0;
        *(undefined4 *)(parser + 0x10) = savedLine;
        *(undefined4 *)(parser + 0xc) = savedCursor;
      }
    }
  }
  return status;
}

/* _LFSParserParseDestination @ 0xcfd74 (308 bytes) */
int _LFSParserParseDestination(parser, destination)
  int parser;
  int *destination;
{
  int status;
  char tokenBuffer [256];
  undefined4 savedCursor;
  undefined4 savedLine;
  int registerKind;
  int registerIndex [4];
  
  status = ((int (*)())_LFSParserParseRegister)(parser,&registerKind,registerIndex);
  if (status != 0) {
    return status;
  }
  destination[2] = 0xf0000;
  destination[1] = registerIndex[0];
  *destination = registerKind;
  if (registerKind != 1) {
    return 5;
  }
  savedCursor = *(undefined4 *)(parser + 0xc);
  savedLine = *(undefined4 *)(parser + 0x10);
  status = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
  if (status == 0) {
    return 8;
  }
  if (tokenBuffer[0] == '.') {
    savedCursor = *(undefined4 *)(parser + 0xc);
    savedLine = *(undefined4 *)(parser + 0x10);
    status = ((int (*)())_LFSParserParseDestinationMask)(parser,destination);
    if (status == 0) {
      savedCursor = *(undefined4 *)(parser + 0xc);
      savedLine = *(undefined4 *)(parser + 0x10);
      status = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
      if (status == 0) {
        return 8;
      }
      if (tokenBuffer[0] != '.') goto LAB_000cfe58;
    }
    else {
      *(undefined4 *)(parser + 0x10) = savedLine;
      *(undefined4 *)(parser + 0xc) = savedCursor;
    }
    status = ((int (*)())_LFSParserParseDestinationModifiers)(parser,destination);
    if (status != 0) {
      return status;
    }
  }
  else {
LAB_000cfe58:
    *(undefined4 *)(parser + 0x10) = savedLine;
    *(undefined4 *)(parser + 0xc) = savedCursor;
  }
  return 0;
}

/* _LFSParserParseSourceModifier @ 0xcfea8 (336 bytes) */
int _LFSParserParseSourceModifier(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char local_120 [256];
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar3 = 0;
  do {
    iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_120);
    if (iVar2 == 0) {
      return 8;
    }
    iVar2 = _memcmp(local_120,"neg",4);
    if (iVar2 == 0) {
      uVar1 = *(uint *)(param_2 + 0xc) | 0x100;
    }
    else {
      iVar2 = _memcmp(local_120,"2x",3);
      if (iVar2 == 0) {
        uVar1 = *(uint *)(param_2 + 0xc) | 0x200;
      }
      else {
        iVar2 = _memcmp(local_120,"bias",5);
        if (iVar2 == 0) {
          uVar1 = *(uint *)(param_2 + 0xc) | 0x400;
        }
        else {
          iVar2 = _memcmp(local_120,"comp",5);
          if (iVar2 != 0) {
            return 0xb;
          }
          uVar1 = *(uint *)(param_2 + 0xc) | 0x800;
        }
      }
    }
    *(uint *)(param_2 + 0xc) = uVar1;
    local_20 = *(undefined4 *)(param_1 + 0xc);
    local_1c = *(undefined4 *)(param_1 + 0x10);
    iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_120);
    if (iVar2 == 0) {
      return 8;
    }
    if (local_120[0] != '.') {
      *(undefined4 *)(param_1 + 0x10) = local_1c;
      *(undefined4 *)(param_1 + 0xc) = local_20;
      return 0;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 4);
  return 0;
}

/* _LFSParserParseSourceVar @ 0xcfff8 (540 bytes) */
int _LFSParserParseSourceVar(parser, sourceVar)
  int parser;
  int *sourceVar;
{
  int statusOrSwizzle;
  int bindingOrCompareResult;
  char tokenBuffer [256];
  undefined4 savedCursor;
  undefined4 savedLine;
  int registerKind;
  int registerIndex [4];
  
  statusOrSwizzle = ((int (*)())_LFSParserParseRegister)(parser,&registerKind,registerIndex);
  if (statusOrSwizzle != 0) {
    return statusOrSwizzle;
  }
  *sourceVar = registerKind;
  sourceVar[1] = registerIndex[0];
  if (registerKind == 2) {
    statusOrSwizzle = *(int *)**(undefined4 **)(parser + 0x14);
    while( true ) {
      if (statusOrSwizzle == 0) {
        return 0x12;
      }
      if (*(int *)(statusOrSwizzle + 8) == registerIndex[0]) break;
      statusOrSwizzle = *(int *)(statusOrSwizzle + 0x4c);
    }
  }
  savedCursor = *(undefined4 *)(parser + 0xc);
  savedLine = *(undefined4 *)(parser + 0x10);
  statusOrSwizzle = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
  if (statusOrSwizzle == 0) {
    return 8;
  }
  if (tokenBuffer[0] != '.') goto LAB_000d01ec;
  savedCursor = *(undefined4 *)(parser + 0xc);
  savedLine = *(undefined4 *)(parser + 0x10);
  statusOrSwizzle = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
  if (statusOrSwizzle == 0) {
    return 8;
  }
  bindingOrCompareResult = _memcmp(tokenBuffer,"r",2);
  statusOrSwizzle = 0x1000;
  if (bindingOrCompareResult == 0) {
LAB_000d0164:
    sourceVar[2] = statusOrSwizzle;
  }
  else {
    bindingOrCompareResult = _memcmp(tokenBuffer,"g",2);
    statusOrSwizzle = 0x2000;
    if (bindingOrCompareResult == 0) goto LAB_000d0164;
    bindingOrCompareResult = _memcmp(tokenBuffer,"b",2);
    statusOrSwizzle = 0x3000;
    if (bindingOrCompareResult == 0) goto LAB_000d0164;
    statusOrSwizzle = _memcmp(tokenBuffer,"a",2);
    if (statusOrSwizzle == 0) {
      statusOrSwizzle = 0x4000;
      goto LAB_000d0164;
    }
    *(undefined4 *)(parser + 0x10) = savedLine;
    *(undefined4 *)(parser + 0xc) = savedCursor;
    statusOrSwizzle = ((int (*)())_LFSParserParseSourceModifier)(parser,sourceVar);
    if (statusOrSwizzle != 0) {
      return statusOrSwizzle;
    }
  }
  if (sourceVar[2] == 0) {
    return 0;
  }
  savedCursor = *(undefined4 *)(parser + 0xc);
  savedLine = *(undefined4 *)(parser + 0x10);
  statusOrSwizzle = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
  if (statusOrSwizzle == 0) {
    return 8;
  }
  if (tokenBuffer[0] == '.') {
    statusOrSwizzle = ((int (*)())_LFSParserParseSourceModifier)(parser,sourceVar);
    if (statusOrSwizzle == 0) {
      return 0;
    }
    return statusOrSwizzle;
  }
LAB_000d01ec:
  *(undefined4 *)(parser + 0x10) = savedLine;
  *(undefined4 *)(parser + 0xc) = savedCursor;
  return 0;
}

/* _LFSParserParseOperation @ 0xd0214 (1192 bytes) */
int _LFSParserParseOperation(parser)
  int parser;
{
  bool alphaPairsWithRgb;
  int swizzle;
  int statusOrCompareOrPart;
  uint sourceCount;
  uint passIndex;
  uint constantRegCount;
  uint pendingMask;
  uint sourceIndex;
  int *sourceCursor;
  char tokenBuffer [256];
  uint opcode;
  undefined1 destination [8];
  uint destWriteMask;
  int sources [15];
  int constantUseCount [8];
  
  constantRegCount = 0;
  _memset(&opcode,0,0x44);
  constantUseCount[0] = 0;
  constantUseCount[1] = 0;
  sourceCount = 0;
  constantUseCount[2] = 0;
  constantUseCount[3] = 0;
  constantUseCount[4] = 0;
  constantUseCount[5] = 0;
  constantUseCount[6] = 0;
  constantUseCount[7] = 0;
  statusOrCompareOrPart = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
  if (statusOrCompareOrPart == 0) {
    return 8;
  }
  statusOrCompareOrPart = _memcmp(tokenBuffer,"MOV",4);
  if (statusOrCompareOrPart == 0) {
    opcode = 0;
  }
  else {
    statusOrCompareOrPart = _memcmp(tokenBuffer,"ADD",4);
    opcode = 0x100;
    if (statusOrCompareOrPart != 0) {
      statusOrCompareOrPart = _memcmp(tokenBuffer,"MUL",4);
      opcode = 0x200;
      if (statusOrCompareOrPart != 0) {
        statusOrCompareOrPart = _memcmp(tokenBuffer,"SUB",4);
        opcode = 0x300;
        if (statusOrCompareOrPart != 0) {
          statusOrCompareOrPart = _memcmp(tokenBuffer,"DOT3",5);
          opcode = 0x400;
          if (statusOrCompareOrPart != 0) {
            statusOrCompareOrPart = _memcmp(tokenBuffer,"DOT4",5);
            opcode = 0x500;
            if (statusOrCompareOrPart != 0) {
              statusOrCompareOrPart = _memcmp(tokenBuffer,"MAD",4);
              opcode = 0x600;
              if (statusOrCompareOrPart != 0) {
                statusOrCompareOrPart = _memcmp(tokenBuffer,"LERP",5);
                opcode = 0x700;
                if (statusOrCompareOrPart != 0) {
                  statusOrCompareOrPart = _memcmp(tokenBuffer,"CND",4);
                  opcode = 0x800;
                  if (statusOrCompareOrPart != 0) {
                    statusOrCompareOrPart = _memcmp(tokenBuffer,"CND0",5);
                    opcode = 0x900;
                    if (statusOrCompareOrPart != 0) {
                      statusOrCompareOrPart = _memcmp(tokenBuffer,"DOT2ADD",8);
                      if (statusOrCompareOrPart != 0) {
                        return 3;
                      }
                      opcode = 0xa00;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (opcode == 0) {
    sourceCount = 1;
  }
  else if (opcode < 0x501) {
    sourceCount = 2;
  }
  else if (opcode < 0xa01) {
    sourceCount = 3;
  }
  statusOrCompareOrPart = ((int (*)())_LFSParserParseDestination)(parser,destination);
  if (statusOrCompareOrPart != 0) {
    return statusOrCompareOrPart;
  }
  sourceIndex = 0;
  if (sourceCount != 0) {
    sourceCursor = sources;
    do {
      statusOrCompareOrPart = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
      if (statusOrCompareOrPart == 0) {
        return 8;
      }
      if (tokenBuffer[0] != ',') {
        return 10;
      }
      statusOrCompareOrPart = ((int (*)())_LFSParserParseSourceVar)(parser,sourceCursor);
      if (sources[sourceIndex * 4] == 2) {
        if (constantUseCount[sources[sourceIndex * 4 + 1]] == 0) {
          constantRegCount = constantRegCount + 1;
        }
        constantUseCount[sources[sourceIndex * 4 + 1]] = constantUseCount[sources[sourceIndex * 4 + 1]] + 1;
      }
      if ((*(char *)(parser + 0x19) != '\x03') && (sources[sourceIndex * 4] == 4)) {
        return 0x14;
      }
      if ((sources[sourceIndex * 4] == 4) && (sources[sourceIndex * 4 + 1] == 1)) {
        if ((destWriteMask & 0x80000) == 0) {
          if (sources[sourceIndex * 4 + 2] == 0x4000) {
            return 0x1c;
          }
        }
        else {
          swizzle = sources[sourceIndex * 4 + 2];
          if (((swizzle != 0x1000) && (swizzle != 0x2000)) && (swizzle != 0x3000)) {
            return 0x1c;
          }
        }
      }
      if (statusOrCompareOrPart != 0) {
        return statusOrCompareOrPart;
      }
      sourceIndex = sourceIndex + 1;
      sourceCursor = sourceCursor + 4;
    } while (sourceIndex < sourceCount);
    if (2 < constantRegCount) {
      return 0x13;
    }
  }
  passIndex = (uint)*(byte *)(parser + 0x19);
  alphaPairsWithRgb = false;
  pendingMask = *(uint *)(passIndex * 0x10 + parser + 0x1c);
  if (pendingMask != 0) {
    if (((((pendingMask & 0x10000) != 0) || ((pendingMask & 0x20000) != 0)) || ((pendingMask & 0x40000) != 0)) &&
       (((*(uint *)(passIndex * 0x10 + parser + 0x1c) & 0x80000) == 0 && (destWriteMask == 0x80000)))) {
      alphaPairsWithRgb = true;
    }
    statusOrCompareOrPart = passIndex * 0x10 + parser;
    *(int *)(statusOrCompareOrPart + 0x20) = *(int *)(statusOrCompareOrPart + 0x20) + 1;
    *(undefined4 *)((uint)*(byte *)(parser + 0x19) * 0x10 + parser + 0x1c) = 0;
    passIndex = (uint)*(byte *)(parser + 0x19);
    if (alphaPairsWithRgb) goto LAB_000d064c;
  }
  if (((destWriteMask & 0x70000) == 0) || ((destWriteMask & 0x80000) != 0)) {
    statusOrCompareOrPart = passIndex * 0x10 + parser;
    *(int *)(statusOrCompareOrPart + 0x20) = *(int *)(statusOrCompareOrPart + 0x20) + 1;
  }
  else {
    statusOrCompareOrPart = passIndex * 0x10 + parser;
    if (7 < *(uint *)(statusOrCompareOrPart + 0x20)) {
      return 0x16;
    }
    *(uint *)(statusOrCompareOrPart + 0x1c) = destWriteMask;
  }
  passIndex = (uint)*(byte *)(parser + 0x19);
LAB_000d064c:
  statusOrCompareOrPart = 0x16;
  if (*(uint *)(passIndex * 0x10 + parser + 0x20) < 9) {
    if (passIndex == 2) {
      _LFSStreamAddPreliminaryPassOperation(*(undefined4 *)(parser + 0x14),&opcode);
    }
    else {
      if (passIndex != 3) {
        return 0xc;
      }
      _LFSStreamAddOutputPassOperation(*(undefined4 *)(parser + 0x14),&opcode);
    }
    statusOrCompareOrPart = 0;
  }
  return statusOrCompareOrPart;
}

/* _LFSParserParseRegisterInit @ 0xd06bc (940 bytes) */
int _LFSParserParseRegisterInit(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  char local_140 [256];
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_20 [5];
  
  piVar5 = (int *)0x0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_140);
  iVar3 = 8;
  if (iVar2 != 0) {
    iVar2 = _memcmp(local_140,"PassTexCoord",0xd);
    if (iVar2 == 0) {
      local_40 = 0;
    }
    else {
      iVar2 = _memcmp(local_140,"SampleMap",10);
      if (iVar2 != 0) {
        return 3;
      }
      local_40 = 0x10;
    }
    iVar3 = ((int (*)())_LFSParserParseRegister)(param_1,local_20,&local_34);
    if ((iVar3 == 0) && (iVar3 = 5, local_20[0] == 1)) {
      iVar3 = 0x17;
      iVar2 = (uint)*(byte *)(param_1 + 0x19) * 0x10 + param_1 + local_34;
      if (*(char *)(iVar2 + 0x24) == '\0') {
        *(undefined1 *)(iVar2 + 0x24) = 1;
        iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_140);
        iVar3 = 8;
        if (((((iVar2 != 0) && (iVar3 = 10, local_140[0] == ',')) &&
             (iVar3 = ((int (*)())_LFSParserParseRegister)(param_1,&local_3c,&local_38), iVar3 == 0)) &&
            ((local_3c == 1 || (iVar3 = 5, local_3c == 5)))) &&
           ((*(char *)(param_1 + 0x19) != '\x02' || (iVar3 = 0x18, local_3c != 1)))) {
          iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_140);
          iVar3 = 8;
          if ((iVar2 != 0) && (iVar3 = 0xe, local_140[0] == '.')) {
            iVar2 = ((int (*)())_LFSParserGetPart)(param_1,local_140);
            iVar3 = 8;
            if (iVar2 != 0) {
              iVar2 = _memcmp(local_140,"str",4);
              if (iVar2 == 0) {
                iVar2 = 0;
              }
              else {
                iVar3 = _memcmp(local_140,"stq",4);
                iVar2 = 0x100;
                if (iVar3 != 0) {
                  iVar3 = _memcmp(local_140,"str_dr",7);
                  iVar2 = 0x200;
                  if (iVar3 != 0) {
                    iVar2 = _memcmp(local_140,"stq_dq",7);
                    if (iVar2 != 0) {
                      return 0xe;
                    }
                    iVar2 = 0x300;
                  }
                }
              }
              local_30 = iVar2;
              if (local_3c == 5) {
                uVar4 = 0;
                do {
                  if (uVar4 == 0) {
                    piVar5 = *(int **)(*(int *)(param_1 + 0x14) + 4);
                  }
                  else if (uVar4 == 1) {
                    piVar5 = *(int **)(*(int *)(param_1 + 0x14) + 0xc);
                  }
                  for (iVar2 = *piVar5; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4c)) {
                    if ((*(int *)(iVar2 + 8) == 5) && (*(int *)(iVar2 + 0xc) == local_38)) {
                      if (local_30 == 0) {
                        iVar3 = *(int *)(iVar2 + 0x14);
                        if ((iVar3 != 0x200) && (iVar3 != 0)) {
                          return 0x19;
                        }
                      }
                      else {
                        iVar3 = *(int *)(iVar2 + 0x14);
                      }
                      if (((local_30 == 0x100) && (iVar3 != 0x300)) && (iVar3 != 0x100)) {
                        return 0x19;
                      }
                      if (((iVar3 == 0) && (local_30 != 0x200)) && (local_30 != 0)) {
                        return 0x19;
                      }
                      if (((iVar3 == 0x100) && (local_30 != 0x300)) && (local_30 != 0x100)) {
                        return 0x19;
                      }
                    }
                  }
                  uVar4 = uVar4 + 1;
                } while (uVar4 < 2);
              }
              cVar1 = *(char *)(param_1 + 0x19);
              if (((cVar1 == '\x03') && (local_3c == 1)) &&
                 ((local_30 == 0x100 || (local_30 == 0x300)))) {
                iVar3 = 0x1a;
              }
              else {
                if (cVar1 == '\x02') {
                  _LFSStreamAddPreliminaryPassRegisterInit
                            (*(undefined4 *)(param_1 + 0x14),&local_40);
                }
                else {
                  if (cVar1 != '\x03') {
                    return 0xc;
                  }
                  _LFSStreamAddOutputPassRegisterInit(*(undefined4 *)(param_1 + 0x14),&local_40);
                }
                iVar3 = 0;
              }
            }
          }
        }
      }
    }
  }
  return iVar3;
}

/* _LFSParserParseConstantBinding @ 0xd0a68 (748 bytes) */
int _LFSParserParseConstantBinding(parser)
  int parser;
{
  int status;
  int partLength;
  int compareResult;
  int bindingNode;
  int tokenLength;
  char tokenBuffer [256];
  int bindingKind;
  int registerIndex;
  uint envIndex;
  undefined4 constantIndex;
  uint localIndex;
  float literalValue [4];
  longlong floatToIntTemp;
  longlong floatToIntTemp2;
  int registerInfo [5];
  
  bindingKind = 0;
  localIndex = 0;
  registerIndex = 0;
  envIndex = 0;
  constantIndex = 0;
  status = ((int (*)())_LFSParserParseRegister)(parser,registerInfo,&registerIndex);
  if ((status == 0) && (status = 5, registerInfo[0] == 2)) {
    for (bindingNode = *(int *)**(undefined4 **)(parser + 0x14); bindingNode != 0;
        bindingNode = *(int *)(bindingNode + 0x4c)) {
      if (*(int *)(bindingNode + 8) == registerIndex) {
        return 0x11;
      }
    }
    tokenLength = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
    status = 8;
    if ((tokenLength != 0) && (status = 0xf, tokenBuffer[0] == '=')) {
      tokenLength = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
      status = 8;
      if (tokenLength != 0) {
        compareResult = _memcmp(tokenBuffer,"program",8);
        if (compareResult == 0) {
          partLength = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
          if (partLength == 0) {
            return 8;
          }
          if (tokenBuffer[0] != '.') {
            return 0xf;
          }
          partLength = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
          if (partLength == 0) {
            return 8;
          }
          compareResult = _memcmp(tokenBuffer,"env",4);
          if (compareResult == 0) {
            bindingKind = compareResult;
            status = ((int (*)())_LFSParserParseArray)(parser,literalValue);
            if (status != 0) {
              return status;
            }
            if (DOUBLE_00108d80 <= (double)literalValue[0]) {
              envIndex = (uint)(int)((double)literalValue[0] - DOUBLE_00108d80);
              floatToIntTemp2 = (longlong)(int)envIndex;
              envIndex = envIndex ^ 0x80000000;
            }
            else {
              envIndex = (uint)(int)literalValue[0];
              floatToIntTemp = (longlong)(int)envIndex;
            }
          }
          else {
            compareResult = _memcmp(tokenBuffer,"local",6);
            if (compareResult != 0) {
              return 0xf;
            }
            bindingKind = 2;
            status = ((int (*)())_LFSParserParseArray)(parser,literalValue);
            if (status != 0) {
              return status;
            }
            if (DOUBLE_00108d80 <= (double)literalValue[0]) {
              localIndex = (uint)(int)((double)literalValue[0] - DOUBLE_00108d80);
              floatToIntTemp = (longlong)(int)localIndex;
              localIndex = localIndex ^ 0x80000000;
            }
            else {
              localIndex = (uint)(int)literalValue[0];
              floatToIntTemp2 = (longlong)(int)localIndex;
            }
          }
        }
        else {
          compareResult = _memcmp(tokenBuffer,"{",2);
          if (compareResult != 0) {
            return 0xf;
          }
          bindingKind = 1;
          registerInfo[1] = 4;
          literalValue[0] = 0.0;
          literalValue[3] = 0.0;
          literalValue[2] = 0.0;
          literalValue[1] = 0.0;
          ((int (*)())_LFSParserGetScalars)(parser,literalValue,registerInfo + 1);
          partLength = ((int (*)())_LFSParserGetPart)(parser,tokenBuffer);
          if (partLength == 0) {
            return 8;
          }
          if (tokenBuffer[0] != '}') {
            return 0xf;
          }
          constantIndex = *(undefined4 *)(*(int *)(*(int *)(parser + 0x14) + 0x14) + 8);
          _LFSStreamAddConstant(*(int *)(parser + 0x14),literalValue);
        }
        _LFSStreamAddConstantBinding(*(undefined4 *)(parser + 0x14),&bindingKind);
        status = 0;
      }
    }
  }
  return status;
}

/* _LFSParserParseInstruction @ 0xd0d54 (516 bytes) */
int _LFSParserParseInstruction(parser)
  int parser;
{
  int iVar1;
  char partText [256];
  undefined4 savedPosition0;
  undefined4 savedPosition1;
  
  savedPosition0 = *(undefined4 *)(parser + 0xc);
  savedPosition1 = *(undefined4 *)(parser + 0x10);
  iVar1 = ((int (*)())_LFSParserGetPart)(parser,partText);
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = _memcmp(partText,"StartConstants",0xf);
  if (iVar1 == 0) {
    *(undefined1 *)(parser + 0x3a) = 1;
    *(undefined1 *)(parser + 0x19) = 1;
    goto LAB_000d0f14;
  }
  iVar1 = _memcmp(partText,"EndConstants",0xd);
  if (iVar1 != 0) {
    iVar1 = _memcmp(partText,"StartPrelimPass",0x10);
    if (iVar1 == 0) {
      *(undefined1 *)(parser + 0x19) = 2;
      *(undefined1 *)(parser + 0x4a) = 1;
      goto LAB_000d0f14;
    }
    iVar1 = _memcmp(partText,"EndPass",8);
    if (iVar1 != 0) {
      iVar1 = _memcmp(partText,"StartOutputPass",0x10);
      if (iVar1 == 0) {
        *(undefined1 *)(parser + 0x19) = 3;
        *(undefined1 *)(parser + 0x5a) = 1;
      }
      else {
        iVar1 = _memcmp(partText,"CONSTANT",9);
        if (iVar1 == 0) {
          if (*(char *)(parser + 0x19) != '\x01') {
            return 0xd;
          }
          iVar1 = ((int (*)())_LFSParserParseConstantBinding)(parser);
        }
        else {
          iVar1 = _memcmp(partText,"PassTexCoord",0xd);
          if ((iVar1 == 0) || (iVar1 = _memcmp(partText,"SampleMap",10), iVar1 == 0)) {
            *(undefined4 *)(parser + 0x10) = savedPosition1;
            *(undefined4 *)(parser + 0xc) = savedPosition0;
            iVar1 = ((int (*)())_LFSParserParseRegisterInit)(parser);
          }
          else {
            *(undefined4 *)(parser + 0x10) = savedPosition1;
            *(undefined4 *)(parser + 0xc) = savedPosition0;
            iVar1 = ((int (*)())_LFSParserParseOperation)(parser);
          }
        }
        if (iVar1 != 0) {
          return iVar1;
        }
      }
      goto LAB_000d0f14;
    }
  }
  *(undefined1 *)(parser + 0x19) = 0;
LAB_000d0f14:
  iVar1 = ((int (*)())_LFSParserGetPart)(parser,partText);
  if (iVar1 == 0) {
    return 8;
  }
  if (partText[0] == ';') {
    return 0;
  }
  return 2;
}

/* _LFSParserParseVersion @ 0xd0f58 (160 bytes) */
int _LFSParserParseVersion(param_1)
  undefined4 param_1;
{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  char local_120 [16];
  char local_110 [256];
  
  uVar4 = 0;
  pcVar3 = local_110;
  do {
    iVar1 = ((int (*)())_LFSParserGetCharacter)(param_1,local_120,0);
    if (iVar1 != 0) {
      return 8;
    }
    *pcVar3 = local_120[0];
    if (local_120[0] != ' ') {
      pcVar3 = pcVar3 + 1;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0xc);
  iVar1 = _memcmp(local_110,"!!ATIfs1.0",10);
  uVar2 = 0x1f;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  return uVar2;
}

/* _LFSParserParse @ 0xd0ff8 (136 bytes) */
int _LFSParserParse(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = ((int (*)())_LFSParserParseVersion)(param_1);
  while (iVar1 == 0) {
    iVar1 = ((int (*)())_LFSParserParseInstruction)(param_1);
  }
  if ((iVar1 == 1) &&
     ((*(char *)(param_1 + 0x4a) == '\0' ||
      (iVar1 = 0x15, *(int *)(*(int *)(*(int *)(param_1 + 0x14) + 8) + 8) != 0)))) {
    iVar1 = 0;
  }
  else {
    ((void (*)())_LFSParserBuildErrorString)(param_1,iVar1);
  }
  return iVar1;
}

/* _LFSParserBuildErrorString @ 0xd1080 (580 bytes) */
void _LFSParserBuildErrorString(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  char *pcVar2;
  undefined1 auStack_120 [256];
  undefined4 local_20;
  undefined4 local_1c;
  
  switch(param_2) {
  default:
    pcVar2 = "";
    break;
  case 1:
    pcVar2 = "end of stream";
    break;
  case 2:
    pcVar2 = "missing semicolon";
    break;
  case 3:
    pcVar2 = "unrecognised instruction";
    break;
  case 4:
    pcVar2 = "invalid program header";
    break;
  case 5:
    pcVar2 = "invalid register";
    break;
  case 6:
    pcVar2 = "malformed destination mask";
    break;
  case 7:
    pcVar2 = "malformed destination modifier";
    break;
  case 8:
    pcVar2 = "unexpected end of file";
    break;
  case 9:
    pcVar2 = "invalid identifier name";
    break;
  case 10:
    pcVar2 = "missing comma";
    break;
  case 0xb:
    pcVar2 = "malformed source modifier";
    break;
  case 0xc:
    pcVar2 = "operation outside of pass block";
    break;
  case 0xd:
    pcVar2 = "constant binding outside of constant block";
    break;
  case 0xe:
    pcVar2 = "malformed source selector";
    break;
  case 0xf:
    pcVar2 = "malformed constant binding";
    break;
  case 0x10:
    pcVar2 = "malformed array specifier";
    break;
  case 0x11:
    pcVar2 = "SEMANTIC RESTRICTION #1 - constant already bound";
    break;
  case 0x12:
    pcVar2 = "SEMANTIC RESTRICTION #1 - constant not bound";
    break;
  case 0x13:
    pcVar2 = "SEMANTIC RESTRICTION #2 - greater than 2 constant arguments";
    break;
  case 0x14:
    pcVar2 = "SEMANTIC RESTRICTION #3 - color arguments used in non output pass";
    break;
  case 0x15:
    pcVar2 = "SEMANTIC RESTRICTION #4 - no alu operations in preliminary pass";
    break;
  case 0x16:
    pcVar2 = "SEMANTIC RESTRICTION #5 - excess color/alpha pairs in pass";
    break;
  case 0x17:
    pcVar2 = "SEMANTIC RESTRICTION #6 - destination register overwritten in same pass";
    break;
  case 0x18:
    pcVar2 = "SEMANTIC RESTRICTION #7 - register init with register argument in preliminary pass";
    break;
  case 0x19:
    pcVar2 = "SEMANTIC RESTRICTION #8 - same texture coordinate with selector exists";
    break;
  case 0x1a:
    pcVar2 = "SEMANTIC RESTRICTION #9 - this selector is not allowed in the output pass";
    break;
  case 0x1b:
    pcVar2 = "SEMANTIC RESTRICTION #10 - no writemask is allowed for this instruction";
    break;
  case 0x1c:
    pcVar2 = "SEMANTIC RESTRICTION #11 - alpha component cannot be read for secondary color";
    break;
  case 0x1d:
    pcVar2 = "SEMANTIC RESTRICTION #12 - register number exceeds supported";
    break;
  case 0x1e:
    pcVar2 = "SEMANTIC RESTRICTION #13 - texture unit number exceeds supported";
    break;
  case 0x1f:
    pcVar2 = "missing or invalid version token";
  }
  local_20 = *(undefined4 *)(param_1 + 0xc);
  local_1c = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x45c);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x460);
  iVar1 = ((int (*)())_LFSParserGetPart)(param_1,auStack_120);
  if (iVar1 == 0) {
    _sprintf((char *)(param_1 + 0x5c),"%s",pcVar2);
  }
  else {
    _sprintf((char *)(param_1 + 0x5c),"%s (hint: \'%s\')",pcVar2,auStack_120);
  }
  *(undefined4 *)(param_1 + 0xc) = local_20;
  *(undefined4 *)(param_1 + 0x10) = local_1c;
  return;
}

/* _LFSStreamChunkCreate @ 0xd1344 (12 bytes) */
int _LFSStreamChunkCreate()
{
  undefined4 uVar1;
  
  uVar1 = _calloc(0x50,1);
  return uVar1;
}

/* _LFSStreamChunkCreateFromChunk @ 0xd1350 (64 bytes) */
int _LFSStreamChunkCreateFromChunk(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())_LFSStreamChunkCreate)();
  _memcpy(uVar1,param_1,0x50);
  return uVar1;
}

/* _LFSStreamChunkGetStream @ 0xd1394 (408 bytes) */
int _LFSStreamChunkGetStream(param_1, unusedArg2, param_3, param_4)
  byte *param_1;
  undefined4 unusedArg2;
  undefined4 *param_3;
  int param_4;
{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_20 [8];
  
  *param_3 = 1;
  bVar1 = *param_1;
  local_20[0] = 0;
  if (bVar1 != 2) {
    if (2 < bVar1) {
      if (bVar1 != 3) {
        if (bVar1 != 4) {
          return 0;
        }
        *param_3 = 4;
        _memmove(local_20,param_1 + param_4 * 4 + 4,4);
        return local_20[0];
      }
      uVar4 = *(uint *)(param_1 + 4);
      uVar5 = *(int *)(param_1 + 8) << 0x14 | uVar4 | 0x60000000;
      if (uVar4 == 1) {
        iVar3 = *(int *)(param_1 + 0x10);
      }
      else if (uVar4 == 0) {
        iVar3 = *(int *)(param_1 + 0xc);
      }
      else {
        if (uVar4 != 2) {
          return uVar5;
        }
        iVar3 = *(int *)(param_1 + 0x14);
      }
      return uVar5 | iVar3 << 0xc;
    }
    if (bVar1 != 1) {
      return 0;
    }
    return *(int *)(param_1 + 0xc) << 0x14 | *(int *)(param_1 + 0x10) << 0xc |
           *(uint *)(param_1 + 0x14) | *(uint *)(param_1 + 4) | *(uint *)(param_1 + 8) | 0x20000000;
  }
  uVar4 = *(uint *)(param_1 + 4);
  uVar2 = 2;
  if ((uVar4 != 0) && (uVar2 = 3, 0x500 < uVar4)) {
    if (0xa00 < uVar4) goto LAB_000d1440;
    uVar2 = 4;
  }
  *param_3 = uVar2;
LAB_000d1440:
  if (param_4 == 0) {
    uVar4 = *(int *)(param_1 + 0xc) << 0x14 | *(uint *)(param_1 + 0x10) | *(uint *)(param_1 + 0x14)
            | *(uint *)(param_1 + 4) | 0x30000000;
  }
  else {
    iVar3 = param_4 + -1;
    uVar4 = *(int *)(param_1 + iVar3 * 0x10 + 0x1c) << 0x14 |
            *(uint *)(param_1 + iVar3 * 0x10 + 0x20) | *(uint *)(param_1 + iVar3 * 0x10 + 0x24) |
            *(uint *)(param_1 + iVar3 * 0x10 + 0x18) | 0x40000000;
  }
  return uVar4;
}

/* _LFSStreamChunkCompare @ 0xd152c (124 bytes) */
int _LFSStreamChunkCompare(chunkA, chunkB)
  char *chunkA;
  char *chunkB;
{
  int memcmpResult;
  bool chunksDiffer;
  
  chunksDiffer = true;
  if (*chunkA == *chunkB) {
    memcmpResult = _memcmp(chunkA + 4,chunkB + 4,0x14);
    chunksDiffer = true;
    if (memcmpResult == 0) {
      memcmpResult = _memcmp(chunkA + 4,chunkB + 4,0x44);
      chunksDiffer = memcmpResult != 0;
    }
  }
  return chunksDiffer;
}

/* _LFSStreamChunkOutputDebugInfo @ 0xd15a8 (684 bytes) */
void _LFSStreamChunkOutputDebugInfo(chunk)
  byte *chunk;
{
  byte chunkKind;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *lastFormat;
  undefined4 lastValue;
  uint sourceIndex;
  uint nextSourceIndex;
  byte *sourceVarCursor;
  float constantX;
  float constantZ;
  float constantY;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  _puts("LFSStreamChunk {");
  chunkKind = *chunk;
  if (chunkKind == 2) {
    _puts("      operation {");
    _printf("         type = 0x%lx;\n",*(undefined4 *)(chunk + 4));
    sourceIndex = 0;
    sourceVarCursor = chunk;
    do {
      nextSourceIndex = sourceIndex + 1;
      _printf("         sourcevar[%i] {\n",sourceIndex);
      _printf("            registertype = 0x%lx;\n",*(undefined4 *)(sourceVarCursor + 0x18));
      _printf("            registerindex = %i;\n",*(undefined4 *)(sourceVarCursor + 0x1c));
      _printf("            replicate = 0x%lx;\n",*(undefined4 *)(sourceVarCursor + 0x20));
      _printf("            modifiers = 0x%lx;\n",*(undefined4 *)(sourceVarCursor + 0x24));
      _puts("         };");
      sourceVarCursor = sourceVarCursor + 0x10;
      sourceIndex = nextSourceIndex;
    } while (nextSourceIndex < 3);
    _puts("         destvar {");
    _printf("            registertype = 0x%lx;\n",*(undefined4 *)(chunk + 8));
    _printf("            registerindex = %i;\n",*(undefined4 *)(chunk + 0xc));
    _printf("            mask = 0x%lx;\n",*(undefined4 *)(chunk + 0x10));
    _printf("            modifiers = 0x%lx;\n",*(undefined4 *)(chunk + 0x14));
    _puts("         };");
  }
  else {
    if (chunkKind < 3) {
      if (chunkKind != 1) goto LAB_000d1838;
      _puts("      registerinit {");
      _printf("         type = 0x%lx;\n",*(undefined4 *)(chunk + 4));
      _puts("         source {");
      _printf("            registertype = 0x%lx;\n",*(undefined4 *)(chunk + 8));
      _printf("            registerindex = %i;\n",*(undefined4 *)(chunk + 0xc));
      _puts("         };");
      _printf("         destregisterindex = %i;\n",*(undefined4 *)(chunk + 0x10));
      lastValue = *(undefined4 *)(chunk + 0x14);
      lastFormat = "         selector = 0x%lx;\n";
    }
    else {
      if (chunkKind != 3) {
        if (chunkKind == 4) {
          constantX = (double)*(float *)(chunk + 4);
          constantY = (double)*(float *)(chunk + 8);
          constantZ = (double)*(float *)(chunk + 0xc);
          local_30 = (undefined4)((ulonglong)(double)*(float *)(chunk + 0x10) >> 0x20);
          lastValue = local_30;
          local_30 = (undefined4)((ulonglong)(double)constantX >> 0x20);
          uVar2 = local_30;
          uStack_2c = SUB84((double)constantX,0);
          uVar4 = uStack_2c;
          local_30 = (undefined4)((ulonglong)(double)constantY >> 0x20);
          uVar3 = local_30;
          uStack_2c = SUB84((double)constantY,0);
          uVar5 = uStack_2c;
          local_30 = (undefined4)((ulonglong)(double)constantZ >> 0x20);
          uStack_2c = SUB84((double)constantZ,0);
          _printf("      constant = { %f, %f, %f, %f }\n;",(double)constantX,(double)constantY,(double)constantZ,
                  (double)*(float *)(chunk + 0x10),uVar2,uVar4,uVar3,uVar5,local_30,uStack_2c,
                  lastValue);
        }
        goto LAB_000d1838;
      }
      _puts("      constantbinding {");
      _printf("         type = 0x%lx;\n",*(undefined4 *)(chunk + 4));
      _printf("         constantindex = %i;\n",*(undefined4 *)(chunk + 8));
      _printf("         envparameterindex = %i;\n",*(undefined4 *)(chunk + 0xc));
      _printf("         inlineconstantindex = %i;\n",*(undefined4 *)(chunk + 0x10));
      lastValue = *(undefined4 *)(chunk + 0x14);
      lastFormat = "         localparameterindex = %i;\n";
    }
    _printf(lastFormat,lastValue);
  }
  _puts("      };");
LAB_000d1838:
  _puts("   };");
  return;
}

