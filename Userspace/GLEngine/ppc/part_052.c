#include "decls.h"

/* _gleBeginQuadsRenderFlat @ 0xeb680 (52 bytes) */
void _gleBeginQuadsRenderFlat(glContext)
  int glContext;
{
  undefined *flushAtomicFunc;
  
  flushAtomicFunc = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushAtomicFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderFlatQuadsFunc_00112284;
  return;
}

/* _gleBeginQuadsRenderTCLRDirty @ 0xeb6b4 (60 bytes) */
void _gleBeginQuadsRenderTCLRDirty(glContext)
  int glContext;
{
  undefined *flushAtomicTCLRDirtyFunc;
  undefined *renderQuadsTCLFunc;
  
  renderQuadsTCLFunc = PTR__gleRenderQuadsTCLFunc_00112280;
  flushAtomicTCLRDirtyFunc = PTR__gleFlushAtomicTCLRDirtyFunc_00112210;
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = flushAtomicTCLRDirtyFunc;
  *(undefined **)(glContext + 0x4a08) = renderQuadsTCLFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginQuadStripRenderSmooth @ 0xeb6f0 (52 bytes) */
void _gleBeginQuadStripRenderSmooth(glContext)
  int glContext;
{
  undefined *flushTriQuadStripFunc;
  
  flushTriQuadStripFunc = PTR__gleFlushTriQuadStripFunc_001122c8;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushTriQuadStripFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderSmoothQuadStripFunc_00112274;
  return;
}

/* _gleBeginQuadStripRenderFlat @ 0xeb724 (52 bytes) */
void _gleBeginQuadStripRenderFlat(glContext)
  int glContext;
{
  undefined *flushTriQuadStripFunc;
  
  flushTriQuadStripFunc = PTR__gleFlushTriQuadStripFunc_001122c8;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushTriQuadStripFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderFlatQuadStripFunc_00112270;
  return;
}

/* _gleBeginQuadStripRenderTCL @ 0xeb758 (52 bytes) */
void _gleBeginQuadStripRenderTCL(glContext)
  int glContext;
{
  undefined *flushTriQuadStripTCLFunc;
  
  flushTriQuadStripTCLFunc = PTR__gleFlushTriQuadStripTCLFunc_001122bc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushTriQuadStripTCLFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderQuadStripTCLFunc_0011226c;
  return;
}

/* _gleBeginQuadStripRenderTCLRDirty @ 0xeb78c (60 bytes) */
void _gleBeginQuadStripRenderTCLRDirty(glContext)
  int glContext;
{
  undefined *renderQuadStripTCLFunc;
  undefined *flushTriQuadStripTCLRDirtyFunc;
  
  flushTriQuadStripTCLRDirtyFunc = PTR__gleFlushTriQuadStripTCLRDirtyFunc_001122b4;
  renderQuadStripTCLFunc = PTR__gleRenderQuadStripTCLFunc_0011226c;
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = flushTriQuadStripTCLRDirtyFunc;
  *(undefined **)(glContext + 0x4a08) = renderQuadStripTCLFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginQuadStripSelectFeedback @ 0xeb7c8 (76 bytes) */
void _gleBeginQuadStripSelectFeedback(glContext)
  int glContext;
{
  undefined *puVar1;
  
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushTriQuadStripFunc_001122c8;
  puVar1 = PTR__gleFeedbackQuadStripFunc_00112264;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectQuadStripFunc_00112268;
  }
  *(undefined **)(glContext + 0x4a08) = puVar1;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginPolygonRenderSmooth @ 0xeb814 (60 bytes) */
void _gleBeginPolygonRenderSmooth(glContext)
  int glContext;
{
  undefined *renderSmoothPolygonFunc;
  undefined *flushPolygonFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  flushPolygonFunc = PTR__gleFlushPolygonFunc_00112260;
  renderSmoothPolygonFunc = PTR__gleRenderSmoothPolygonFunc_0011225c;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushPolygonFunc;
  *(undefined **)(glContext + 0x4a08) = renderSmoothPolygonFunc;
  return;
}

/* _gleBeginPolygonRenderFlat @ 0xeb850 (60 bytes) */
void _gleBeginPolygonRenderFlat(glContext)
  int glContext;
{
  undefined *renderFlatPolygonFunc;
  undefined *flushPolygonFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  flushPolygonFunc = PTR__gleFlushPolygonFunc_00112260;
  renderFlatPolygonFunc = PTR__gleRenderFlatPolygonFunc_00112258;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushPolygonFunc;
  *(undefined **)(glContext + 0x4a08) = renderFlatPolygonFunc;
  return;
}

/* _gleBeginPolygonRenderTCLRDirty @ 0xeb88c (68 bytes) */
void _gleBeginPolygonRenderTCLRDirty(glContext)
  int glContext;
{
  undefined *flushPolygonTCLRDirtyFunc;
  undefined *renderPolygonTCLFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  renderPolygonTCLFunc = PTR__gleRenderPolygonTCLFunc_00112250;
  flushPolygonTCLRDirtyFunc = PTR__gleFlushPolygonTCLRDirtyFunc_0011224c;
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = flushPolygonTCLRDirtyFunc;
  *(undefined **)(glContext + 0x4a08) = renderPolygonTCLFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginPolygonSelectFeedback @ 0xeb8d0 (76 bytes) */
void _gleBeginPolygonSelectFeedback(glContext)
  int glContext;
{
  undefined *puVar1;
  
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushPolygonFunc_00112260;
  puVar1 = PTR__gleFeedbackPolygonFunc_00112244;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectPolygonFunc_00112248;
  }
  *(undefined **)(glContext + 0x4a08) = puVar1;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _glePolyCentroid @ 0xeb91c (244 bytes) */
void _glePolyCentroid(undefined4 unusedArg1,float *vertices,int vertexCount,float *centroidX,float *centroidY,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  float crossTerm;
  float lastY;
  float firstX;
  float firstY;
  float areaSum;
  float centroidSumX;
  float centroidSumY;
  float closingCross;
  int remaining;
  float *vertexCursor;
  float *lastVertex;
  
  lastVertex = vertices;
  areaSum = FLOAT_00108e50;
  centroidSumX = FLOAT_00108e50;
  centroidSumY = FLOAT_00108e50;
  if (1 < vertexCount) {
    remaining = vertexCount + -1;
    vertexCursor = vertices;
    do {
      lastVertex = vertexCursor + 0x40;
      crossTerm = *vertexCursor * vertexCursor[0x41] - vertexCursor[0x40] * vertexCursor[1];
      centroidSumY = (vertexCursor[1] + vertexCursor[0x41]) * crossTerm + centroidSumY;
      centroidSumX = (*vertexCursor + vertexCursor[0x40]) * crossTerm + centroidSumX;
      areaSum = areaSum + crossTerm;
      remaining = remaining + -1;
      vertexCursor = lastVertex;
    } while (remaining != 0);
  }
  lastY = lastVertex[1];
  firstX = *vertices;
  firstY = vertices[1];
  closingCross = *lastVertex * firstY - firstX * lastY;
  areaSum = areaSum + closingCross;
  if ((areaSum < FLOAT_00108e80) && (FLOAT_00108f3c < areaSum)) {
    *centroidX = firstX;
    *centroidY = vertices[1];
    return;
  }
  areaSum = FLOAT_00108e54 / (areaSum * FLOAT_00108f38);
  *centroidX = ((*lastVertex + firstX) * closingCross + centroidSumX) * areaSum;
  *centroidY = ((lastY + firstY) * closingCross + centroidSumY) * areaSum;
  return;
}

/* _gleClipPolyPlane @ 0xeba10 (496 bytes) */
double _gleClipPolyPlane(int glContext,int *polygonList,int vertexCount,int *outputList,int *outVertexCount,double fparam_1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  float startWord09ThenDistance;
  float planeB;
  float planeA;
  float firstWord08;
  float distanceEnd;
  float planeC;
  float firstWord0a;
  float planeD;
  float firstWord0b;
  float floatZero;
  int resultCount;
  int nextVertex;
  int planeIndexThenEquation;
  int firstVertex;
  int activePlaneCount;
  int copyIndex;
  int *planeIndexPtr;
  int planePass;
  int copyRemaining;
  int newVertexCursor;
  int *passInputList;
  int *passInputEnd;
  int *outputCursor;
  int *edgeStart;
  
  activePlaneCount = *(int *)(glContext + 0x4dfc);
  resultCount = 0;
  passInputEnd = polygonList + vertexCount;
  newVertexCursor = *(int *)(glContext + 0x4858);
  planePass = 0;
  if (0 < activePlaneCount) {
    planeIndexPtr = (int *)(glContext + 0x4e00);
    outputCursor = outputList;
    passInputList = polygonList;
    do {
      polygonList = outputCursor;
      planeIndexThenEquation = *planeIndexPtr;
      firstVertex = *passInputList;
      planeIndexPtr = planeIndexPtr + 1;
      planeIndexThenEquation = glContext + planeIndexThenEquation * 0x10;
      startWord09ThenDistance = *(float *)(firstVertex + 0x24);
      planeB = *(float *)(planeIndexThenEquation + 0x4190);
      planeA = *(float *)(planeIndexThenEquation + 0x418c);
      firstWord08 = *(float *)(firstVertex + 0x20);
      planeC = *(float *)(planeIndexThenEquation + 0x4194);
      firstWord0a = *(float *)(firstVertex + 0x28);
      planeD = *(float *)(planeIndexThenEquation + 0x4198);
      firstWord0b = *(float *)(firstVertex + 0x2c);
      *passInputEnd = firstVertex;
      floatZero = FLOAT_00108e50;
      outputCursor = polygonList;
      startWord09ThenDistance = firstWord0b * planeD + (firstWord0a * planeC + (firstWord08 * planeA + startWord09ThenDistance * planeB));
      for (edgeStart = passInputList; edgeStart < passInputEnd; edgeStart = edgeStart + 1) {
        nextVertex = edgeStart[1];
        distanceEnd = *(float *)(nextVertex + 0x2c) * planeD +
                (*(float *)(nextVertex + 0x28) * planeC +
                (*(float *)(nextVertex + 0x20) * planeA + *(float *)(nextVertex + 0x24) * planeB));
        if (startWord09ThenDistance < floatZero) {
          if (floatZero <= distanceEnd) {
            fparam_1 = (double)(**(double ( **)(int,int,int,int,double))(glContext + 0x49c8))
                                         (glContext, *edgeStart, nextVertex, newVertexCursor, (double)(startWord09ThenDistance / (startWord09ThenDistance - distanceEnd)));
LAB_000ebb68:
            *outputCursor = newVertexCursor;
            newVertexCursor = newVertexCursor + 0x100;
            outputCursor = outputCursor + 1;
          }
        }
        else {
          *outputCursor = *edgeStart;
          outputCursor = outputCursor + 1;
          if (distanceEnd < floatZero) {
            fparam_1 = (double)(**(double ( **)(int,int,int,int,double))(glContext + 0x49c8))
                                         (glContext, edgeStart[1], *edgeStart, newVertexCursor, (double)(distanceEnd / (distanceEnd - startWord09ThenDistance)));
            *(undefined1 *)(newVertexCursor + 0x7c) = 0;
            goto LAB_000ebb68;
          }
        }
        startWord09ThenDistance = distanceEnd;
      }
      resultCount = (int)outputCursor - (int)polygonList >> 2;
      if (resultCount < 3) {
        *outVertexCount = 0;
        return fparam_1;
      }
      planePass = planePass + 1;
      passInputEnd = polygonList + resultCount;
      outputCursor = passInputList;
      passInputList = polygonList;
    } while (planePass < activePlaneCount);
  }
  if ((polygonList != outputList) && (copyIndex = 0, copyRemaining = resultCount, 0 < resultCount)) {
    do {
      outputList[copyIndex] = polygonList[copyIndex];
      copyRemaining = copyRemaining + -1;
      copyIndex = copyIndex + 1;
    } while (copyRemaining != 0);
  }
  *outVertexCount = resultCount;
  *(int *)(glContext + 0x4858) = newVertexCursor;
  return fparam_1;
}

/* _gleCullPolygonStack @ 0xebc00 (192 bytes) */
int _gleCullPolygonStack(glContext, param_2, param_3, param_4, param_5)
  int glContext;
  float *param_2;
  int param_3;
  uint param_4;
  uint *param_5;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = fVar2;
  fVar4 = fVar1;
  fVar8 = FLOAT_00108e50;
  if (1 < param_3) {
    iVar9 = param_3 + -1;
    iVar10 = 1;
    fVar7 = fVar1;
    do {
      fVar4 = param_2[iVar10 * 0x40];
      fVar6 = fVar4 * fVar3;
      fVar3 = param_2[iVar10 * 0x40 + 1];
      fVar8 = fVar8 + ((fVar7 * fVar3 - fVar6));
      iVar9 = iVar9 + -1;
      iVar10 = iVar10 + 1;
      fVar7 = fVar4;
    } while (iVar9 != 0);
  }
  uVar5 = -(uint)((bool)*(char *)(glContext + 0x4fe1) ==
            FLOAT_00108e50 < fVar8 + ((fVar4 * fVar2 - fVar1 * fVar3)) ^ param_4) >> 0x1f;
  if (*(byte *)(glContext + 0x4fe3) == uVar5) {
    return 1;
  }
  *param_5 = uVar5 ^ 1;
  return 0;
}

/* _gleCullTriangle @ 0xebcc0 (152 bytes) */
undefined4 _gleCullTriangle(int glContext,float *param_2,float *param_3,float *param_4,uint param_5,uint *param_6,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  uint uVar1;
  
  uVar1 = -(uint)((bool)*(char *)(glContext + 0x4fe1) ==
            FLOAT_00108e50 <
            (*param_2 * param_3[1] - *param_3 * param_2[1]) +
            ((*param_3 * param_4[1] - *param_4 * param_3[1])) +
            ((*param_4 * param_2[1] - *param_2 * param_4[1])) ^ param_5) >> 0x1f;
  if (*(byte *)(glContext + 0x4fe3) == uVar1) {
    return 1;
  }
  *param_6 = uVar1 ^ 1;
  return 0;
}

/* _gleCullQuad @ 0xebd58 (160 bytes) */
undefined4 _gleCullQuad(int glContext,float *param_2,float *param_3,float *param_4,float *param_5,uint *param_6,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  uint uVar1;
  
  uVar1 = (uint)((bool)*(char *)(glContext + 0x4fe1) ==
                FLOAT_00108e50 <
                (*param_2 * param_3[1] - *param_3 * param_2[1]) +
                ((*param_3 * param_4[1] - *param_4 * param_3[1])) +
                ((*param_4 * param_5[1] - *param_5 * param_4[1])) +
                ((*param_5 * param_2[1] - *param_2 * param_5[1])));
  if (*(byte *)(glContext + 0x4fe3) == uVar1) {
    return 1;
  }
  *param_6 = uVar1 ^ 1;
  return 0;
}

/* _gleCullPolygonPtrStack @ 0xebdf8 (184 bytes) */
int _gleCullPolygonPtrStack(glContext, param_2, param_3, param_4)
  int glContext;
  undefined4 *param_2;
  int param_3;
  uint *param_4;
{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  
  pfVar8 = (float *)*param_2;
  fVar2 = *pfVar8;
  fVar3 = pfVar8[1];
  fVar6 = FLOAT_00108e50;
  if (1 < param_3) {
    iVar7 = param_3 + -1;
    fVar4 = fVar2;
    fVar5 = fVar3;
    do {
      param_2 = param_2 + 1;
      fVar2 = *(float *)*param_2;
      fVar3 = ((float *)*param_2)[1];
      fVar6 = fVar6 + ((fVar4 * fVar3 - fVar2 * fVar5));
      iVar7 = iVar7 + -1;
      fVar4 = fVar2;
      fVar5 = fVar3;
    } while (iVar7 != 0);
  }
  uVar1 = (uint)((bool)*(char *)(glContext + 0x4fe1) ==
                FLOAT_00108e50 < fVar6 + ((fVar2 * pfVar8[1] - *pfVar8 * fVar3)));
  if (*(byte *)(glContext + 0x4fe3) == uVar1) {
    return 1;
  }
  *param_4 = uVar1 ^ 1;
  return 0;
}

/* _gleFeedbackPolygonFunc_body @ 0xebeb4 (1112 bytes) */
void _gleFeedbackPolygonFunc_body(glContext)
  int glContext;
{
  char cVar1;
  ushort facePolygonMode;
  bool bVar3;
  bool bVar4;
  bool twoSidedLighting;
  int *piVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  code *pcVar10;
  int *spareList;
  int *polygonList;
  uint uVar13;
  int iVar14;
  uint uVar15;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  uint local_40;
  int local_3c [5];
  
  bVar3 = false;
  local_3c[0] = 0;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    bVar3 = true;
  }
  bVar3 = !bVar3;
  bVar4 = false;
  if ((bVar3) && (*(char *)(glContext + 0x30aa) != '\0')) {
    bVar4 = true;
  }
  twoSidedLighting = false;
  if ((bVar4) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  cVar1 = *(char *)(glContext + 0x4fe0);
  iVar14 = *(int *)(glContext + 0x4854);
  if ((int)*(short *)(glContext + 0x487c) == 0) {
    return;
  }
  uVar13 = (uint)(*(int *)(glContext + 0x4858) - iVar14) / (uint)(int)*(short *)(glContext + 0x487c);
  if ((int)uVar13 < 3) {
    return;
  }
  if (bVar3) {
    uVar7 = (**(code **)(glContext + 0x5060))(glContext,iVar14,uVar13);
  }
  else {
    uVar7 = _gleVPEmulate(glContext,uVar13);
  }
  if ((uVar7 & 0xff00) != 0) {
    return;
  }
  if (bVar3) {
    if (*(char *)(glContext + 0x53e4) != '\0') {
      (**(code **)(glContext + 0x53dc))(glContext,iVar14,uVar13);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      (**(code **)(glContext + 0x5064))(glContext,iVar14,uVar13);
    }
    if ((bVar4) || (*(char *)(glContext + 0x53e6) != '\0')) {
      (**(code **)(glContext + 0x5068))(glContext,iVar14,uVar13);
    }
    if (*(char *)(glContext + 0x53e5) != '\0') {
      (**(code **)(glContext + 0x53e0))(glContext,iVar14,uVar13);
    }
  }
  else {
    iVar14 = *(int *)(glContext + 0x4864);
  }
  if (((uVar7 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if ((cVar1 != '\0') &&
       (iVar8 = ((int (*)())_gleCullPolygonStack)(glContext,iVar14,uVar13,0,local_3c), iVar8 != 0)) {
      return;
    }
    (**(code **)(glContext + 0x506c))(glContext,iVar14,uVar13,0);
    if (twoSidedLighting) {
      pcVar10 = *(code **)(local_3c[0] * 4 + glContext + 0x4de8);
    }
    else {
      if (!bVar4) goto LAB_000ec290;
      pcVar10 = *(code **)(glContext + 0x4de8);
    }
    (*pcVar10)(glContext,iVar14,uVar13);
LAB_000ec290:
    if (local_3c[0] == 0) {
      facePolygonMode = *(ushort *)(glContext + 0x34d0);
    }
    else {
      facePolygonMode = *(ushort *)(glContext + 0x34d2);
    }
    iVar8 = facePolygonMode - 0x1b00;
    if ((*(char *)(glContext + 0x4a18) != '\0') && (iVar8 == 1)) {
      iVar8 = 3;
    }
    if ((!bVar3) && (bVar4)) {
      _gleVPFlipColors(glContext,iVar14,uVar13,local_3c[0]);
    }
    _gleFeedbackPolygon(glContext,iVar14,uVar13,iVar8);
    return;
  }
  fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, iVar14, uVar13, 0);
  polygonList = *(int **)(glContext + 0x4870);
  spareList = *(int **)(glContext + 0x4874);
  piVar6 = polygonList;
  uVar15 = uVar13;
  if (0 < (int)uVar13) {
    do {
      *piVar6 = iVar14;
      iVar14 = iVar14 + 0x100;
      uVar15 = uVar15 - 1;
      piVar6 = piVar6 + 1;
    } while (uVar15 != 0);
  }
  if (!bVar3) {
    *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  }
  uVar9 = 0;
  piVar6 = spareList;
  if (*(char *)(glContext + 0x4e18) != '\0') {
    ((double (*)())_gleClipPolyPlane)(glContext,polygonList,uVar13,spareList,&local_40,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
                      incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90);
    if (local_40 == 0) {
      return;
    }
    uVar9 = 1;
    piVar6 = polygonList;
    polygonList = spareList;
    uVar13 = local_40;
  }
  if ((uVar7 & 0xff) != 0) {
    _gleClipPoly(glContext,polygonList,uVar13,uVar7 & 0xff,piVar6,&local_40,uVar9);
    if (local_40 == 0) {
      return;
    }
    if (0 < (int)local_40) {
      polygonList = piVar6;
      uVar13 = local_40;
    }
  }
  if ((cVar1 != '\0') &&
     (iVar14 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,uVar13,local_3c), iVar14 != 0)) {
    return;
  }
  if (twoSidedLighting) {
    pcVar10 = *(code **)(local_3c[0] * 4 + glContext + 0x4df0);
  }
  else {
    if (!bVar4) goto LAB_000ec180;
    pcVar10 = *(code **)(glContext + 0x4df0);
  }
  (*pcVar10)(glContext,polygonList,uVar13);
LAB_000ec180:
  if (local_3c[0] == 0) {
    facePolygonMode = *(ushort *)(glContext + 0x34d0);
  }
  else {
    facePolygonMode = *(ushort *)(glContext + 0x34d2);
  }
  iVar14 = facePolygonMode - 0x1b00;
  if ((*(char *)(glContext + 0x4a18) != '\0') && (iVar14 == 1)) {
    iVar14 = 3;
  }
  if (((!bVar3) && (bVar4)) && (piVar6 = polygonList, uVar7 = uVar13, 0 < (int)uVar13)) {
    do {
      iVar8 = *piVar6;
      piVar6 = piVar6 + 1;
      _gleVPFlipColors(glContext,iVar8,1,local_3c[0]);
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  _gleFeedbackPolygonPtr(glContext,polygonList,uVar13,iVar14);
  return;
}

/* _gleFeedbackTrianglesFunc_body @ 0xec310 (1276 bytes) */
void _gleFeedbackTrianglesFunc_body(glContext)
  int glContext;
{
  char cVar1;
  ushort facePolygonMode;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool twoSidedLighting;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  code *pcVar11;
  int iVar12;
  uint *spareList;
  uint *puVar14;
  uint uVar15;
  uint *polygonList;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int polygonVertexCount;
  int iVar21;
  double dVar22;
  double extraout_f1;
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
  int backFacing;
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
  twoSidedLighting = false;
  if (((bVar3) && (*(char *)(glContext + 0x30aa) != '\0')) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  cVar1 = *(char *)(glContext + 0x4fe0);
  uVar19 = *(uint *)(glContext + 0x4854);
  if (((int)*(short *)(glContext + 0x487c) != 0) &&
     (uVar15 = (*(int *)(glContext + 0x4858) - uVar19) / (uint)(int)*(short *)(glContext + 0x487c),
     2 < (int)uVar15)) {
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
        if (cVar1 == '\0') {
          if (bVar5) {
            dVar22 = (double)(**(double ( **)(int,int,int))(glContext + 0x4de8))(glContext, uVar19, uVar15);
          }
          ((double (*)())_gleFeedbackTriangles)(glContext,uVar19,uVar15,*(ushort *)(glContext + 0x34d0) - 0x1b00,dVar22)
          ;
        }
        else {
          uVar15 = (uVar19 + uVar15 * 0x100) - 0x300;
          do {
            bVar4 = false;
            iVar20 = 0;
            uVar9 = uVar19;
            uVar18 = uVar19;
            if (uVar19 <= uVar15) {
              do {
                iVar10 = ((undefined4 (*)())_gleCullTriangle)(glContext,uVar19,uVar19 + 0x100,uVar19 + 0x200,0,&backFacing,
                                          dVar22,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                          incomingStack_ffffff78,incomingStack_ffffff80);
                dVar22 = dVar22;
                if (iVar10 == 0) {
                  if (iVar12 != backFacing) {
                    bVar4 = true;
                  }
                  if ((bVar4) && (uVar9 = uVar19, 0 < iVar20)) break;
                  iVar20 = iVar20 + 3;
                  iVar12 = backFacing;
                  uVar17 = uVar18;
                }
                else {
                  uVar17 = uVar19 + 0x300;
                  uVar9 = uVar17;
                  if (0 < iVar20) break;
                }
                uVar19 = uVar19 + 0x300;
                uVar9 = uVar19;
                uVar18 = uVar17;
              } while (uVar19 <= uVar15);
              if (2 < iVar20) {
                if (twoSidedLighting) {
                  pcVar11 = *(code **)(iVar12 * 4 + glContext + 0x4de8);
LAB_000ec5d0:
                  dVar22 = (double)(*((double (*)(int,int,int))pcVar11))(glContext, uVar18, iVar20);
                }
                else if (bVar5) {
                  pcVar11 = *(code **)(glContext + 0x4de8);
                  goto LAB_000ec5d0;
                }
                if ((!bVar3) && (bVar5)) {
                  dVar22 = (double)_gleVPFlipColors(glContext,uVar18,iVar20,iVar12);
                }
                if (iVar12 == 0) {
                  facePolygonMode = *(ushort *)(glContext + 0x34d0);
                }
                else {
                  facePolygonMode = *(ushort *)(glContext + 0x34d2);
                }
                dVar22 = (double)((double (*)())_gleFeedbackTriangles)(glContext,uVar18,iVar20,facePolygonMode - 0x1b00,dVar22);
              }
            }
            uVar19 = uVar9;
          } while (uVar9 <= uVar15);
        }
      }
      else {
        dVar22 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, uVar19, uVar15, 0);
        iVar12 = uVar19 + uVar15 * 0x100;
        polygonList = *(uint **)(glContext + 0x4870);
        spareList = *(uint **)(glContext + 0x4874);
        for (; uVar19 <= iVar12 - 0x300U; uVar19 = uVar19 + 0x300) {
          polygonList[1] = uVar19 + 0x100;
          polygonList[2] = uVar19 + 0x200;
          *polygonList = uVar19;
          if (bVar3) {
            uVar8 = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            uVar8 = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = uVar8;
          puVar14 = spareList;
          iVar20 = 3;
          puVar7 = polygonList;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar22 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,local_4c,dVar22,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             puVar14 = polygonList, polygonVertexCount = local_4c[0], puVar7 = spareList, local_4c[0] != 0)) {
            polygonList = puVar7;
            spareList = puVar14;
            if ((uVar9 & 0xff) != 0) {
              dVar22 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,uVar9 & 0xff,puVar14,local_4c,1);
              if (local_4c[0] == 0) goto LAB_000ec7e4;
              if (0 < local_4c[0]) {
                spareList = polygonList;
                polygonVertexCount = local_4c[0];
                polygonList = puVar14;
              }
            }
            if ((cVar1 == '\0') ||
               (iVar10 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing),
               dVar22 = f1AfterCall1, iVar10 == 0)) {
              iVar10 = backFacing;
              if (twoSidedLighting) {
                pcVar11 = *(code **)(backFacing * 4 + glContext + 0x4df0);
LAB_000ec778:
                (*pcVar11)(glContext,polygonList,polygonVertexCount);
              }
              else if (bVar5) {
                pcVar11 = *(code **)(glContext + 0x4df0);
                goto LAB_000ec778;
              }
              if (((!bVar3) && (bVar5)) && (puVar14 = polygonList, iVar21 = polygonVertexCount, 0 < polygonVertexCount)) {
                do {
                  _gleVPFlipColors(glContext,*puVar14,1,iVar10);
                  iVar21 = iVar21 + -1;
                  puVar14 = puVar14 + 1;
                } while (iVar21 != 0);
              }
              if (iVar10 == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              dVar22 = (double)_gleFeedbackPolygonPtr(glContext,polygonList,polygonVertexCount,facePolygonMode - 0x1b00);
            }
          }
LAB_000ec7e4: ;
        }
      }
    }
  }
  return;
}

/* _gleFeedbackTriangleStripFunc_body @ 0xec810 (1544 bytes) */
void _gleFeedbackTriangleStripFunc_body(glContext)
  int glContext;
{
  char cullEnabled;
  ushort facePolygonMode;
  bool noVertexProgram;
  bool facingChanged;
  bool lightingEnabled;
  bool twoSidedLighting;
  bool windingFlip;
  uint runStart;
  uint *puVar9;
  undefined4 batchEndReset;
  uint stripParity;
  uint emitStart;
  uint flipCursor;
  uint batchClipCodes;
  uint lastTriangleStart;
  int iVar13;
  int polygonVertexCount;
  int polygonCullResult;
  uint *puVar15;
  uint *flipColorsCursor;
  uint *flipVertexCursor;
  code *lightFunc;
  int previousFacing;
  int flipColorsVerticesLeft;
  int flipVerticesLeft;
  int *triangleVertexList;
  uint *spareList;
  uint uVar20;
  uint uVar21;
  uint vertexCount;
  uint newRunStart;
  int iVar23;
  uint *polygonVertexList;
  uint nextVertex;
  uint vertexCursor;
  double dVar27;
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
  int backFacing;
  int clippedCount [3];
  
  previousFacing = -1;
  noVertexProgram = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    noVertexProgram = true;
  }
  noVertexProgram = !noVertexProgram;
  lightingEnabled = false;
  if ((noVertexProgram) && (*(char *)(glContext + 0x30aa) != '\0')) {
    lightingEnabled = true;
  }
  twoSidedLighting = false;
  if (((noVertexProgram) && (*(char *)(glContext + 0x30aa) != '\0')) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  uVar20 = 0;
  cullEnabled = *(char *)(glContext + 0x4fe0);
  vertexCursor = *(uint *)(glContext + 0x4854);
  if (((int)*(short *)(glContext + 0x487c) != 0) &&
     (vertexCount = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
     2 < (int)vertexCount)) {
    if (noVertexProgram) {
      batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount);
    }
    else {
      batchClipCodes = _gleVPEmulate(glContext,vertexCount);
    }
    if ((batchClipCodes & 0xff00) == 0) {
      if (noVertexProgram) {
        if (*(char *)(glContext + 0x53e4) != '\0') {
          (**(code **)(glContext + 0x53dc))(glContext,vertexCursor,vertexCount);
        }
        if (*(char *)(glContext + 0x50b4) != '\0') {
          (**(code **)(glContext + 0x5064))(glContext,vertexCursor,vertexCount);
        }
        if ((lightingEnabled) || (*(char *)(glContext + 0x53e6) != '\0')) {
          (**(code **)(glContext + 0x5068))(glContext,vertexCursor,vertexCount);
        }
        if (*(char *)(glContext + 0x53e5) != '\0') {
          (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,vertexCount);
        }
      }
      else {
        vertexCursor = *(uint *)(glContext + 0x4864);
      }
      if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        dVar27 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCount, 0);
        if (cullEnabled == '\0') {
          if (lightingEnabled) {
            (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,vertexCount);
          }
          _gleFeedbackTriangleStrip(glContext,vertexCursor,vertexCount,*(ushort *)(glContext + 0x34d0) - 0x1b00);
        }
        else {
          triangleVertexList = *(int **)(glContext + 0x4870);
          lastTriangleStart = (vertexCursor + vertexCount * 0x100) - 0x300;
          uVar21 = 0;
          do {
            facingChanged = false;
            iVar23 = 0;
            stripParity = uVar21;
            runStart = vertexCursor;
            while (uVar21 = stripParity, vertexCursor <= lastTriangleStart) {
              nextVertex = vertexCursor + 0x100;
              iVar13 = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,nextVertex,vertexCursor + 0x200,stripParity,&backFacing,dVar27
                                        ,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78
                                        ,incomingStack_ffffff80);
              dVar27 = f1AfterCall;
              if (iVar13 == 0) {
                if (previousFacing != backFacing) {
                  facingChanged = true;
                }
                if ((facingChanged) && (0 < iVar23)) break;
                if (iVar23 == 0) {
                  uVar20 = stripParity;
                }
                iVar23 = iVar23 + 1;
                previousFacing = backFacing;
                newRunStart = runStart;
              }
              else {
                newRunStart = nextVertex;
                uVar21 = stripParity ^ 1;
                vertexCursor = nextVertex;
                if (0 < iVar23) break;
              }
              stripParity = stripParity ^ 1;
              vertexCursor = nextVertex;
              runStart = newRunStart;
            }
            iVar13 = iVar23 + 2;
            if (2 < iVar13) {
              if (twoSidedLighting) {
                if (facingChanged) {
                  flipCursor = runStart;
                  do {
                    *(byte *)(flipCursor + 0x7e) = *(byte *)(flipCursor + 0x7e) | 6;
                    flipCursor = flipCursor + 0x100;
                  } while ((int)flipCursor <= (int)(runStart + 0x100));
                }
                lightFunc = *(code **)(previousFacing * 4 + glContext + 0x4de8);
LAB_000ecb18:
                (*lightFunc)(glContext,runStart,iVar13);
              }
              else if (lightingEnabled) {
                lightFunc = *(code **)(glContext + 0x4de8);
                goto LAB_000ecb18;
              }
              if ((!noVertexProgram) && (lightingEnabled)) {
                _gleVPFlipColors(glContext,runStart,iVar13,previousFacing);
              }
              emitStart = runStart;
              if (uVar20 != 0) {
                emitStart = runStart + 0x100;
                *triangleVertexList = runStart + 0x200;
                triangleVertexList[2] = runStart;
                triangleVertexList[1] = emitStart;
                if (previousFacing != 0) {
                  facePolygonMode = *(ushort *)(glContext + 0x34d2);
                }
                else {
                  facePolygonMode = *(ushort *)(glContext + 0x34d0);
                }
                iVar13 = iVar23 + 1;
                dVar27 = (double)_gleFeedbackPolygonPtr(glContext,triangleVertexList,3,facePolygonMode - 0x1b00);
                if (iVar13 < 3) goto LAB_000ecbb8;
              }
              if (previousFacing != 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              dVar27 = (double)_gleFeedbackTriangleStrip(glContext,emitStart,iVar13,facePolygonMode - 0x1b00);
            }
LAB_000ecbb8: ;
          } while (vertexCursor <= lastTriangleStart);
        }
      }
      else {
        facingChanged = false;
        dVar27 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCount, 0);
        polygonVertexList = *(uint **)(glContext + 0x4870);
        uVar20 = (vertexCursor + vertexCount * 0x100) - 0x300;
        spareList = *(uint **)(glContext + 0x4874);
        if (vertexCursor <= uVar20) {
          windingFlip = false;
          do {
            windingFlip = !windingFlip;
            if (windingFlip) {
              polygonVertexList[2] = vertexCursor + 0x200;
              *polygonVertexList = vertexCursor;
            }
            else {
              *polygonVertexList = vertexCursor + 0x200;
              polygonVertexList[2] = vertexCursor;
            }
            vertexCursor = vertexCursor + 0x100;
            polygonVertexList[1] = vertexCursor;
            if (noVertexProgram) {
              batchEndReset = *(undefined4 *)(glContext + 0x485c);
            }
            else {
              batchEndReset = *(undefined4 *)(glContext + 0x4854);
            }
            *(undefined4 *)(glContext + 0x4858) = batchEndReset;
            puVar15 = spareList;
            iVar13 = 3;
            puVar9 = polygonVertexList;
            iVar23 = previousFacing;
            if ((*(char *)(glContext + 0x4e18) == '\0') ||
               (dVar27 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonVertexList,3,spareList,clippedCount,dVar27,incomingFpr2,
                                                   incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                   incomingStack_ffffff78,incomingStack_ffffff80),
               puVar15 = polygonVertexList, polygonVertexCount = clippedCount[0], puVar9 = spareList, clippedCount[0] != 0)) {
              polygonVertexList = puVar9;
              spareList = puVar15;
              if ((batchClipCodes & 0xff) != 0) {
                dVar27 = (double)_gleClipPoly(glContext,polygonVertexList,polygonVertexCount,batchClipCodes & 0xff,puVar15,clippedCount,
                                              1);
                if (clippedCount[0] == 0) goto LAB_000ecdf0;
                if (0 < clippedCount[0]) {
                  spareList = polygonVertexList;
                  polygonVertexCount = clippedCount[0];
                  polygonVertexList = puVar15;
                }
              }
              if ((cullEnabled == '\0') ||
                 (polygonCullResult = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonVertexList,polygonVertexCount,&backFacing),
                 dVar27 = f1AfterCall1, polygonCullResult == 0)) {
                iVar23 = backFacing;
                if (previousFacing != backFacing) {
                  facingChanged = true;
                }
                if (twoSidedLighting) {
                  if (facingChanged) {
                    flipVertexCursor = polygonVertexList;
                    flipVerticesLeft = polygonVertexCount;
                    if (0 < polygonVertexCount) {
                      do {
                        *(byte *)(*flipVertexCursor + 0x7e) = *(byte *)(*flipVertexCursor + 0x7e) | 6;
                        flipVerticesLeft = flipVerticesLeft + -1;
                        flipVertexCursor = flipVertexCursor + 1;
                      } while (flipVerticesLeft != 0);
                    }
                    facingChanged = false;
                  }
                  lightFunc = *(code **)(backFacing * 4 + glContext + 0x4df0);
LAB_000ecd84:
                  (*lightFunc)(glContext,polygonVertexList,polygonVertexCount);
                }
                else if (lightingEnabled) {
                  lightFunc = *(code **)(glContext + 0x4df0);
                  goto LAB_000ecd84;
                }
                if (((!noVertexProgram) && (lightingEnabled)) && (flipColorsCursor = polygonVertexList, flipColorsVerticesLeft = polygonVertexCount, 0 < polygonVertexCount)) {
                  do {
                    _gleVPFlipColors(glContext,*flipColorsCursor,1,iVar23);
                    flipColorsVerticesLeft = flipColorsVerticesLeft + -1;
                    flipColorsCursor = flipColorsCursor + 1;
                  } while (flipColorsVerticesLeft != 0);
                }
                if (iVar23 == 0) {
                  facePolygonMode = *(ushort *)(glContext + 0x34d0);
                }
                else {
                  facePolygonMode = *(ushort *)(glContext + 0x34d2);
                }
                dVar27 = (double)_gleFeedbackPolygonPtr(glContext,polygonVertexList,polygonVertexCount,facePolygonMode - 0x1b00);
              }
            }
LAB_000ecdf0:
            previousFacing = iVar23;
          } while (vertexCursor <= uVar20);
        }
      }
    }
  }
  return;
}

/* _gleFeedbackTriangleFanFunc_body @ 0xece1c (1448 bytes) */
void _gleFeedbackTriangleFanFunc_body(glContext)
  int glContext;
{
  char cullEnabled;
  ushort facePolygonMode;
  bool fixedFunctionPath;
  bool facingChanged;
  bool lightingActive;
  bool twoSidedLighting;
  undefined4 bufferEnd;
  uint clipFlags;
  uint lastTriangleLimit;
  int cullResult;
  int cullResultThenBackFacing;
  int facingTableSlot;
  int *oldPolygonList;
  int *vertexPtrCursor;
  code *lightingFunc;
  int previousBackFacing;
  int remainingVertices;
  int *spareList;
  uint fanThirdVertex;
  uint runEndVertex;
  int vertexCursor;
  uint vertexCount;
  uint fanCursor;
  int polygonVertexCount;
  int runTriangleCount;
  int *newPolygonList;
  int *polygonList;
  uint fanSecondVertex;
  uint nextFanVertex;
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
  double incomingStack_ffffff68;
  double incomingStack_ffffff70;
  int backFacing;
  int clipCount [6];
  
  previousBackFacing = -1;
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
  cullEnabled = *(char *)(glContext + 0x4fe0);
  vertexCursor = *(int *)(glContext + 0x4854);
  if (((int)*(short *)(glContext + 0x487c) != 0) &&
     (vertexCount = (uint)(*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c)
     , 2 < (int)vertexCount)) {
    if (fixedFunctionPath) {
      clipFlags = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount);
    }
    else {
      clipFlags = _gleVPEmulate(glContext,vertexCount);
    }
    if ((clipFlags & 0xff00) == 0) {
      if (fixedFunctionPath) {
        if (*(char *)(glContext + 0x53e4) != '\0') {
          (**(code **)(glContext + 0x53dc))(glContext,vertexCursor,vertexCount);
        }
        if (*(char *)(glContext + 0x50b4) != '\0') {
          (**(code **)(glContext + 0x5064))(glContext,vertexCursor,vertexCount);
        }
        if ((lightingActive) || (*(char *)(glContext + 0x53e6) != '\0')) {
          (**(code **)(glContext + 0x5068))(glContext,vertexCursor,vertexCount);
        }
        if (*(char *)(glContext + 0x53e5) != '\0') {
          (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,vertexCount);
        }
      }
      else {
        vertexCursor = *(int *)(glContext + 0x4864);
      }
      if (((clipFlags & 0xff) != 0) || (*(char *)(glContext + 0x4e18) != '\0')) {
        facingChanged = false;
        forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCount, 0);
        fanSecondVertex = vertexCursor + 0x100;
        polygonList = *(int **)(glContext + 0x4870);
        spareList = *(int **)(glContext + 0x4874);
joined_r0x000ed1dc:
        do {
          if ((vertexCursor + vertexCount * 0x100) - 0x200 < fanSecondVertex) {
            return;
          }
          fanThirdVertex = fanSecondVertex + 0x100;
          *polygonList = vertexCursor;
          polygonList[1] = fanSecondVertex;
          polygonList[2] = fanThirdVertex;
          if (fixedFunctionPath) {
            bufferEnd = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            bufferEnd = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = bufferEnd;
          oldPolygonList = spareList;
          polygonVertexCount = 3;
          newPolygonList = polygonList;
          fanSecondVertex = fanThirdVertex;
        } while ((*(char *)(glContext + 0x4e18) != '\0') &&
                (forwardedFloatArg1 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,clipCount,forwardedFloatArg1,incomingFpr2,
                                                    incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                    incomingStack_ffffff68,incomingStack_ffffff70),
                oldPolygonList = polygonList, polygonVertexCount = clipCount[0], newPolygonList = spareList, clipCount[0] == 0));
        spareList = oldPolygonList;
        polygonList = newPolygonList;
        if ((clipFlags & 0xff) != 0) goto code_r0x000ed254;
        goto LAB_000ed294;
      }
      forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCount, 0);
      if (cullEnabled == '\0') {
        if (lightingActive) {
          (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,vertexCount);
        }
        _gleFeedbackTriangleFan
                  (glContext,vertexCursor,vertexCursor + 0x100,vertexCount - 1,*(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        lastTriangleLimit = (vertexCursor + vertexCount * 0x100) - 0x200;
        fanCursor = vertexCursor + 0x100;
        do {
          facingChanged = false;
          runTriangleCount = 0;
          nextFanVertex = fanCursor;
          do {
            while( true ) {
              runEndVertex = nextFanVertex;
              if (lastTriangleLimit < fanCursor) goto LAB_000ed0b0;
              nextFanVertex = fanCursor + 0x100;
              cullResult = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,fanCursor,nextFanVertex,0,&backFacing,forwardedFloatArg1,incomingFpr2,incomingFpr3,
                                       incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff68,
                                       incomingStack_ffffff70);
              forwardedFloatArg1 = f1AfterCall;
              if (cullResult != 0) break;
              if (previousBackFacing != backFacing) {
                facingChanged = true;
              }
              if ((facingChanged) && (0 < runTriangleCount)) goto LAB_000ed0b0;
              runTriangleCount = runTriangleCount + 1;
              previousBackFacing = backFacing;
              fanCursor = nextFanVertex;
              nextFanVertex = runEndVertex;
            }
            fanCursor = nextFanVertex;
          } while (runTriangleCount < 1);
LAB_000ed0b0:
          runTriangleCount = runTriangleCount + 1;
          if (1 < runTriangleCount) {
            if (twoSidedLighting) {
              if (facingChanged) {
                *(byte *)(vertexCursor + 0x7e) = *(byte *)(vertexCursor + 0x7e) | 6;
                *(byte *)(runEndVertex + 0x7e) = *(byte *)(runEndVertex + 0x7e) | 6;
              }
              facingTableSlot = previousBackFacing * 4 + glContext;
              (**(code **)(facingTableSlot + 0x4de8))(glContext,vertexCursor,1);
              lightingFunc = *(code **)(facingTableSlot + 0x4de8);
LAB_000ed144:
              (*lightingFunc)(glContext,runEndVertex,runTriangleCount);
            }
            else if (lightingActive) {
              (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,1);
              lightingFunc = *(code **)(glContext + 0x4de8);
              goto LAB_000ed144;
            }
            if ((!fixedFunctionPath) && (lightingActive)) {
              _gleVPFlipColors(glContext,runEndVertex,runTriangleCount,previousBackFacing);
            }
            if (previousBackFacing == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            forwardedFloatArg1 = (double)_gleFeedbackTriangleFan(glContext,vertexCursor,runEndVertex,runTriangleCount,facePolygonMode - 0x1b00);
          }
        } while (fanCursor <= lastTriangleLimit);
      }
    }
  }
  return;
code_r0x000ed254:
  forwardedFloatArg1 = (double)_gleClipPoly(glContext,newPolygonList,polygonVertexCount,clipFlags & 0xff,oldPolygonList,clipCount,1);
  if (clipCount[0] == 0) goto joined_r0x000ed1dc;
  if (0 < clipCount[0]) {
    spareList = newPolygonList;
    polygonVertexCount = clipCount[0];
    polygonList = oldPolygonList;
  }
LAB_000ed294:
  if ((cullEnabled != '\0') &&
     (cullResultThenBackFacing = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing), forwardedFloatArg1 = f1AfterCall1,
     cullResultThenBackFacing != 0)) goto joined_r0x000ed1dc;
  cullResultThenBackFacing = backFacing;
  if (previousBackFacing != backFacing) {
    facingChanged = true;
  }
  if (twoSidedLighting) {
    if (facingChanged) {
      vertexPtrCursor = polygonList;
      remainingVertices = polygonVertexCount;
      if (0 < polygonVertexCount) {
        do {
          *(byte *)(*vertexPtrCursor + 0x7e) = *(byte *)(*vertexPtrCursor + 0x7e) | 6;
          remainingVertices = remainingVertices + -1;
          vertexPtrCursor = vertexPtrCursor + 1;
        } while (remainingVertices != 0);
      }
      facingChanged = false;
    }
    lightingFunc = *(code **)(backFacing * 4 + glContext + 0x4df0);
  }
  else {
    if (!lightingActive) goto LAB_000ed33c;
    lightingFunc = *(code **)(glContext + 0x4df0);
  }
  (*lightingFunc)(glContext,polygonList,polygonVertexCount);
LAB_000ed33c:
  if (((!fixedFunctionPath) && (lightingActive)) && (remainingVertices = polygonVertexCount, vertexPtrCursor = polygonList, 0 < polygonVertexCount)) {
    do {
      _gleVPFlipColors(glContext,*vertexPtrCursor,1,cullResultThenBackFacing);
      remainingVertices = remainingVertices + -1;
      vertexPtrCursor = vertexPtrCursor + 1;
    } while (remainingVertices != 0);
  }
  if (cullResultThenBackFacing == 0) {
    facePolygonMode = *(ushort *)(glContext + 0x34d0);
  }
  else {
    facePolygonMode = *(ushort *)(glContext + 0x34d2);
  }
  forwardedFloatArg1 = (double)_gleFeedbackPolygonPtr(glContext,polygonList,polygonVertexCount,facePolygonMode - 0x1b00);
  previousBackFacing = cullResultThenBackFacing;
  goto joined_r0x000ed1dc;
}

/* _gleFeedbackQuadStripFunc_body @ 0xed3c8 (1396 bytes) */
void _gleFeedbackQuadStripFunc_body(glContext)
  int glContext;
{
  char cVar1;
  ushort facePolygonMode;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool twoSidedLighting;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  code *pcVar12;
  int iVar13;
  uint *spareList;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int polygonVertexCount;
  uint *puVar18;
  uint *polygonList;
  uint vertexCursor;
  double dVar21;
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
  int local_4c [3];
  
  iVar13 = -1;
  bVar3 = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    bVar3 = true;
  }
  bVar3 = !bVar3;
  bVar5 = false;
  if ((bVar3) && (*(char *)(glContext + 0x30aa) != '\0')) {
    bVar5 = true;
  }
  twoSidedLighting = false;
  if (((bVar3) && (*(char *)(glContext + 0x30aa) != '\0')) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  cVar1 = *(char *)(glContext + 0x4fe0);
  vertexCursor = *(uint *)(glContext + 0x4854);
  if (((int)*(short *)(glContext + 0x487c) != 0) &&
     (uVar16 = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
     3 < (int)uVar16)) {
    if (bVar3) {
      uVar9 = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,uVar16);
    }
    else {
      uVar9 = _gleVPEmulate(glContext,uVar16);
    }
    if ((uVar9 & 0xff00) == 0) {
      if (bVar3) {
        if (*(char *)(glContext + 0x53e4) != '\0') {
          (**(code **)(glContext + 0x53dc))(glContext,vertexCursor,uVar16);
        }
        if (*(char *)(glContext + 0x50b4) != '\0') {
          (**(code **)(glContext + 0x5064))(glContext,vertexCursor,uVar16);
        }
        if ((bVar5) || (*(char *)(glContext + 0x53e6) != '\0')) {
          (**(code **)(glContext + 0x5068))(glContext,vertexCursor,uVar16);
        }
        if (*(char *)(glContext + 0x53e5) != '\0') {
          (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,uVar16);
        }
      }
      else {
        vertexCursor = *(uint *)(glContext + 0x4864);
      }
      if (((uVar9 & 0xff) != 0) || (*(char *)(glContext + 0x4e18) != '\0')) {
        bVar4 = false;
        dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, uVar16, 0);
        polygonList = *(uint **)(glContext + 0x4870);
        spareList = *(uint **)(glContext + 0x4874);
        uVar7 = vertexCursor;
joined_r0x000ed748:
        do {
          if ((vertexCursor + uVar16 * 0x100) - 0x400 < uVar7) {
            return;
          }
          uVar15 = uVar7 + 0x200;
          polygonList[1] = uVar7 + 0x100;
          polygonList[2] = uVar7 + 0x300;
          *polygonList = uVar7;
          polygonList[3] = uVar15;
          if (bVar3) {
            uVar8 = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            uVar8 = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = uVar8;
          puVar11 = spareList;
          iVar17 = 4;
          puVar18 = polygonList;
          uVar7 = uVar15;
        } while ((*(char *)(glContext + 0x4e18) != '\0') &&
                (dVar21 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,local_4c,dVar21,incomingFpr2,
                                                    incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                    incomingStack_ffffff78,incomingStack_ffffff80),
                puVar11 = polygonList, polygonVertexCount = local_4c[0], puVar18 = spareList, local_4c[0] == 0));
        spareList = puVar11;
        polygonList = puVar18;
        if ((uVar9 & 0xff) != 0) goto code_r0x000ed7cc;
        goto LAB_000ed80c;
      }
      dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, uVar16, 0);
      if (cVar1 == '\0') {
        if (bVar5) {
          (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,uVar16);
        }
        _gleFeedbackQuadStrip(glContext,vertexCursor,uVar16,*(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        uVar16 = (vertexCursor + uVar16 * 0x100) - 0x400;
        do {
          bVar4 = false;
          iVar17 = 0;
          uVar9 = vertexCursor;
          do {
            while( true ) {
              uVar7 = uVar9;
              if (uVar16 < vertexCursor) goto LAB_000ed654;
              uVar9 = vertexCursor + 0x200;
              iVar10 = ((undefined4 (*)())_gleCullQuad)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x300,uVar9,&backFacing,
                                    dVar21,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                    incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88);
              dVar21 = f1AfterCall;
              if (iVar10 != 0) break;
              if (iVar13 != backFacing) {
                bVar4 = true;
              }
              if ((bVar4) && (0 < iVar17)) goto LAB_000ed654;
              iVar17 = iVar17 + 2;
              iVar13 = backFacing;
              vertexCursor = uVar9;
              uVar9 = uVar7;
            }
            vertexCursor = uVar9;
          } while (iVar17 < 1);
LAB_000ed654:
          iVar17 = iVar17 + 2;
          if (3 < iVar17) {
            if (twoSidedLighting) {
              if (bVar4) {
                uVar9 = uVar7;
                do {
                  *(byte *)(uVar9 + 0x7e) = *(byte *)(uVar9 + 0x7e) | 6;
                  uVar9 = uVar9 + 0x100;
                } while ((int)uVar9 <= (int)(uVar7 + 0x100));
              }
              pcVar12 = *(code **)(iVar13 * 4 + glContext + 0x4de8);
LAB_000ed6b4:
              (*pcVar12)(glContext,uVar7,iVar17);
            }
            else if (bVar5) {
              pcVar12 = *(code **)(glContext + 0x4de8);
              goto LAB_000ed6b4;
            }
            if ((!bVar3) && (bVar5)) {
              _gleVPFlipColors(glContext,uVar7,iVar17,iVar13);
            }
            if (iVar13 == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            dVar21 = (double)_gleFeedbackQuadStrip(glContext,uVar7,iVar17,facePolygonMode - 0x1b00);
          }
        } while (vertexCursor <= uVar16);
      }
    }
  }
  return;
code_r0x000ed7cc:
  dVar21 = (double)_gleClipPoly(glContext,puVar18,polygonVertexCount,uVar9 & 0xff,puVar11,local_4c,1);
  if (local_4c[0] == 0) goto joined_r0x000ed748;
  if (0 < local_4c[0]) {
    spareList = puVar18;
    polygonVertexCount = local_4c[0];
    polygonList = puVar11;
  }
LAB_000ed80c:
  if ((cVar1 != '\0') &&
     (iVar10 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing), dVar21 = f1AfterCall1,
     iVar10 != 0)) goto joined_r0x000ed748;
  iVar10 = backFacing;
  if (iVar13 != backFacing) {
    bVar4 = true;
  }
  if (twoSidedLighting) {
    if (bVar4) {
      puVar11 = polygonList;
      iVar13 = polygonVertexCount;
      if (0 < polygonVertexCount) {
        do {
          *(byte *)(*puVar11 + 0x7e) = *(byte *)(*puVar11 + 0x7e) | 6;
          iVar13 = iVar13 + -1;
          puVar11 = puVar11 + 1;
        } while (iVar13 != 0);
      }
      bVar4 = false;
    }
    pcVar12 = *(code **)(backFacing * 4 + glContext + 0x4df0);
  }
  else {
    if (!bVar5) goto LAB_000ed8b4;
    pcVar12 = *(code **)(glContext + 0x4df0);
  }
  (*pcVar12)(glContext,polygonList,polygonVertexCount);
LAB_000ed8b4:
  if (((!bVar3) && (bVar5)) && (puVar11 = polygonList, iVar13 = polygonVertexCount, 0 < polygonVertexCount)) {
    do {
      _gleVPFlipColors(glContext,*puVar11,1,iVar10);
      iVar13 = iVar13 + -1;
      puVar11 = puVar11 + 1;
    } while (iVar13 != 0);
  }
  if (iVar10 == 0) {
    facePolygonMode = *(ushort *)(glContext + 0x34d0);
  }
  else {
    facePolygonMode = *(ushort *)(glContext + 0x34d2);
  }
  dVar21 = (double)_gleFeedbackPolygonPtr(glContext,polygonList,polygonVertexCount,facePolygonMode - 0x1b00);
  iVar13 = iVar10;
  goto joined_r0x000ed748;
}

/* _gleRenderSmoothPolygonFunc_body @ 0xed940 (956 bytes) */
void _gleRenderSmoothPolygonFunc_body(glContext)
  int glContext;
{
  bool bVar1;
  bool texturingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  int *piVar6;
  int iVar7;
  uint batchClipCodes;
  undefined4 uVar9;
  code *pcVar10;
  int *spareList;
  int *polygonList;
  int *piVar13;
  int iVar14;
  double f1AfterCall;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  int local_40;
  int local_3c [4];
  
  local_3c[0] = 0;
  iVar7 = _gleTexEnableBits(glContext);
  twoSidedLighting = false;
  bVar1 = (int)-(uint)*(byte *)(glContext + 0x30aa) < 0;
  if ((bVar1) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  piVar13 = *(int **)(glContext + 0x4854);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  iVar14 = *(int *)(glContext + 0x4858) - (int)piVar13 >> 8;
  if (iVar14 < 3) {
    return;
  }
  batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,piVar13,iVar14);
  if ((batchClipCodes & 0xff00) != 0) {
    return;
  }
  texturingEnabled = iVar7 != 0;
  fparam_1 = f1AfterCall;
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, piVar13, iVar14);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, piVar13, iVar14);
  }
  if (bVar1) {
LAB_000eda38:
    fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, piVar13, iVar14);
LAB_000eda50:
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e5) != '\0')) {
      fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, piVar13, iVar14);
    }
  }
  else if (texturingEnabled) {
    if (*(char *)(glContext + 0x53e6) != '\0') goto LAB_000eda38;
    goto LAB_000eda50;
  }
  if (((batchClipCodes & 0xff) != 0) || (*(char *)(glContext + 0x4e18) != '\0')) {
    if (texturingEnabled) {
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, piVar13, iVar14, 0);
    }
    polygonList = *(int **)(glContext + 0x4870);
    spareList = *(int **)(glContext + 0x4874);
    piVar6 = polygonList;
    iVar7 = iVar14;
    if (0 < iVar14) {
      do {
        *piVar6 = (int)piVar13;
        piVar13 = piVar13 + 0x40;
        iVar7 = iVar7 + -1;
        piVar6 = piVar6 + 1;
      } while (iVar7 != 0);
    }
    uVar9 = 0;
    piVar6 = spareList;
    if (*(char *)(glContext + 0x4e18) != '\0') {
      ((double (*)())_gleClipPolyPlane)(glContext,polygonList,iVar14,spareList,&local_40,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
                        incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90);
      if (local_40 == 0) {
        return;
      }
      uVar9 = 1;
      piVar6 = polygonList;
      iVar14 = local_40;
      polygonList = spareList;
    }
    piVar13 = polygonList;
    if ((batchClipCodes & 0xff) != 0) {
      _gleClipPoly(glContext,polygonList,iVar14,batchClipCodes & 0xff,piVar6,&local_40,uVar9);
      if (local_40 == 0) {
        return;
      }
      if (0 < local_40) {
        iVar14 = local_40;
        piVar13 = piVar6;
      }
    }
    if ((faceTestNeeded != '\0') &&
       (iVar7 = ((int (*)())_gleCullPolygonPtrStack)(glContext,piVar13,iVar14,local_3c), iVar7 != 0)) {
      return;
    }
    if (twoSidedLighting) {
      pcVar10 = *(code **)(local_3c[0] * 4 + glContext + 0x4df0);
LAB_000edbbc:
      (*pcVar10)(glContext,piVar13,iVar14);
    }
    else if (bVar1) {
      pcVar10 = *(code **)(glContext + 0x4df0);
      goto LAB_000edbbc;
    }
    if (local_3c[0] == 0) {
      facePolygonMode = *(ushort *)(glContext + 0x34d0);
    }
    else {
      facePolygonMode = *(ushort *)(glContext + 0x34d2);
    }
    iVar7 = facePolygonMode - 0x1b00;
    if ((*(char *)(glContext + 0x4a18) != '\0') && (iVar7 == 1)) {
      iVar7 = 3;
    }
    pcVar10 = *(code **)(glContext + 0x46e0);
    goto LAB_000edcd4;
  }
  if ((faceTestNeeded != '\0') &&
     (iVar7 = ((int (*)())_gleCullPolygonStack)(glContext,piVar13,iVar14,0,local_3c), iVar7 != 0)) {
    return;
  }
  if (texturingEnabled) {
    (**(code **)(glContext + 0x506c))(glContext,piVar13,iVar14,0);
  }
  if (twoSidedLighting) {
    pcVar10 = *(code **)(local_3c[0] * 4 + glContext + 0x4de8);
LAB_000edc8c:
    (*pcVar10)(glContext,piVar13,iVar14);
  }
  else if (bVar1) {
    pcVar10 = *(code **)(glContext + 0x4de8);
    goto LAB_000edc8c;
  }
  if (local_3c[0] == 0) {
    facePolygonMode = *(ushort *)(glContext + 0x34d0);
  }
  else {
    facePolygonMode = *(ushort *)(glContext + 0x34d2);
  }
  iVar7 = facePolygonMode - 0x1b00;
  if ((*(char *)(glContext + 0x4a18) != '\0') && (iVar7 == 1)) {
    iVar7 = 3;
  }
  pcVar10 = *(code **)(glContext + 0x46c0);
LAB_000edcd4:
  (*pcVar10)(*(undefined4 *)(glContext + 0x4688),piVar13,iVar14,iVar7);
  return;
}

/* _gleRenderFlatPolygonFunc_body @ 0xedd00 (984 bytes) */
void _gleRenderFlatPolygonFunc_body(glContext)
  int glContext;
{
  bool lightingEnabled;
  bool texturingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  int *piVar6;
  int iVar7;
  uint batchClipCodes;
  undefined4 uVar9;
  code *pcVar10;
  int *spareList;
  char lightingPending;
  int *polygonList;
  int *piVar14;
  int iVar15;
  double f1AfterCall;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  int local_40;
  int local_3c [3];
  
  local_3c[0] = 0;
  iVar7 = _gleTexEnableBits(glContext);
  lightingPending = *(char *)(glContext + 0x30aa);
  twoSidedLighting = false;
  lightingEnabled = lightingPending != '\0';
  if ((lightingEnabled) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  piVar14 = *(int **)(glContext + 0x4854);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  iVar15 = *(int *)(glContext + 0x4858) - (int)piVar14 >> 8;
  if ((2 < iVar15) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,piVar14,iVar15), (batchClipCodes & 0xff00) == 0)) {
    texturingEnabled = iVar7 != 0;
    fparam_1 = f1AfterCall;
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
      fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, piVar14, iVar15);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, piVar14, iVar15);
    }
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e6) != '\0') {
        lightingPending = '\0';
        fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, piVar14, iVar15);
      }
      if (*(char *)(glContext + 0x53e5) != '\0') {
        fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, piVar14, iVar15);
      }
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if ((faceTestNeeded != '\0') &&
         (iVar7 = ((int (*)())_gleCullPolygonStack)(glContext,piVar14,iVar15,0,local_3c), iVar7 != 0)) {
        return;
      }
      if (texturingEnabled) {
        (**(code **)(glContext + 0x506c))(glContext,piVar14,iVar15,0);
      }
      if (lightingPending != '\0') {
        (**(code **)(glContext + 0x5068))(glContext,piVar14,1);
      }
      if (lightingEnabled) {
        iVar7 = 0x4de0;
        if (twoSidedLighting) {
          iVar7 = local_3c[0] * 4 + 0x4de0;
        }
        (**(code **)(glContext + iVar7 + 8))(glContext,piVar14,1);
      }
      if (local_3c[0] == 0) {
        facePolygonMode = *(ushort *)(glContext + 0x34d0);
      }
      else {
        facePolygonMode = *(ushort *)(glContext + 0x34d2);
      }
      iVar7 = facePolygonMode - 0x1b00;
      if ((*(char *)(glContext + 0x4a18) != '\0') && (iVar7 == 1)) {
        iVar7 = 3;
      }
      pcVar10 = *(code **)(glContext + 0x46c0);
    }
    else {
      if (texturingEnabled) {
        fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, piVar14, iVar15, 0);
      }
      polygonList = *(int **)(glContext + 0x4870);
      spareList = *(int **)(glContext + 0x4874);
      piVar6 = polygonList;
      iVar7 = iVar15;
      if (0 < iVar15) {
        do {
          *piVar6 = (int)piVar14;
          piVar14 = piVar14 + 0x40;
          iVar7 = iVar7 + -1;
          piVar6 = piVar6 + 1;
        } while (iVar7 != 0);
      }
      uVar9 = 0;
      piVar6 = spareList;
      if (*(char *)(glContext + 0x4e18) != '\0') {
        ((double (*)())_gleClipPolyPlane)(glContext,polygonList,iVar15,spareList,&local_40,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
                          incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90);
        if (local_40 == 0) {
          return;
        }
        uVar9 = 1;
        piVar6 = polygonList;
        iVar15 = local_40;
        polygonList = spareList;
      }
      piVar14 = polygonList;
      if ((batchClipCodes & 0xff) != 0) {
        _gleClipPoly(glContext,polygonList,iVar15,batchClipCodes & 0xff,piVar6,&local_40,uVar9);
        if (local_40 == 0) {
          return;
        }
        if (0 < local_40) {
          iVar15 = local_40;
          piVar14 = piVar6;
        }
      }
      if ((faceTestNeeded != '\0') &&
         (iVar7 = ((int (*)())_gleCullPolygonPtrStack)(glContext,piVar14,iVar15,local_3c), iVar7 != 0)) {
        return;
      }
      if (lightingPending != '\0') {
        (**(code **)(glContext + 0x5068))(glContext,*piVar14,1);
      }
      if (lightingEnabled) {
        iVar7 = 0x4de0;
        if (twoSidedLighting) {
          iVar7 = local_3c[0] * 4 + 0x4de0;
        }
        (**(code **)(glContext + iVar7 + 8))(glContext,*piVar14,1);
      }
      if (local_3c[0] == 0) {
        facePolygonMode = *(ushort *)(glContext + 0x34d0);
      }
      else {
        facePolygonMode = *(ushort *)(glContext + 0x34d2);
      }
      iVar7 = facePolygonMode - 0x1b00;
      if ((*(char *)(glContext + 0x4a18) != '\0') && (iVar7 == 1)) {
        iVar7 = 3;
      }
      pcVar10 = *(code **)(glContext + 0x46e0);
    }
    (*pcVar10)(*(undefined4 *)(glContext + 0x4688),piVar14,iVar15,iVar7);
  }
  return;
}

/* _gleRenderSmoothTrianglesFunc_body @ 0xee104 (1140 bytes) */
void _gleRenderSmoothTrianglesFunc_body(glContext)
  int glContext;
{
  bool bVar1;
  bool texturingEnabled;
  bool bVar2;
  byte lightingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  uint batchClipCodes;
  code *pcVar10;
  int iVar11;
  uint *spareList;
  uint *puVar13;
  uint *polygonList;
  uint uVar15;
  uint vertexCursor;
  uint uVar17;
  int iVar18;
  int vertexCount;
  double f1AfterCall;
  double dVar19;
  double extraout_f1_00;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  int local_40;
  int local_3c [3];
  
  iVar11 = -1;
  iVar8 = _gleTexEnableBits(glContext);
  lightingEnabled = *(byte *)(glContext + 0x30aa);
  twoSidedLighting = false;
  if ((lightingEnabled != 0) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  vertexCursor = *(uint *)(glContext + 0x4854);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  vertexCount = (int)(*(int *)(glContext + 0x4858) - vertexCursor) >> 8;
  if (vertexCount < 3) {
    return;
  }
  batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount);
  if ((batchClipCodes & 0xff00) != 0) {
    return;
  }
  texturingEnabled = iVar8 != 0;
  dVar19 = f1AfterCall;
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
    dVar19 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, vertexCount);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    dVar19 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCount);
  }
  bVar2 = (int)-(uint)lightingEnabled < 0;
  if (bVar2) {
LAB_000ee1fc:
    dVar19 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, vertexCount);
  }
  else {
    if (!texturingEnabled) goto LAB_000ee23c;
    if (*(char *)(glContext + 0x53e6) != '\0') goto LAB_000ee1fc;
  }
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e5) != '\0')) {
    dVar19 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, vertexCursor, vertexCount);
  }
LAB_000ee23c:
  if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (texturingEnabled) {
      dVar19 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCount, 0);
    }
    if (faceTestNeeded == '\0') {
      if (bVar2) {
        (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,vertexCount);
      }
      (**(code **)(glContext + 0x46c4))
                (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCount,
                 *(ushort *)(glContext + 0x34d0) - 0x1b00);
    }
    else {
      uVar9 = (vertexCursor + vertexCount * 0x100) - 0x300;
      do {
        bVar1 = false;
        iVar8 = 0;
        uVar15 = vertexCursor;
        uVar17 = vertexCursor;
        if (vertexCursor <= uVar9) {
          do {
            iVar18 = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x200,0,&local_40,
                                      dVar19,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                      incomingStack_ffffff88,incomingStack_ffffff90);
            dVar19 = dVar19;
            if (iVar18 == 0) {
              if (iVar11 != local_40) {
                bVar1 = true;
              }
              if ((bVar1) && (uVar17 = vertexCursor, 0 < iVar8)) break;
              iVar8 = iVar8 + 3;
              iVar11 = local_40;
              uVar17 = uVar15;
            }
            else {
              uVar17 = vertexCursor + 0x300;
              if (0 < iVar8) break;
            }
            vertexCursor = vertexCursor + 0x300;
            uVar15 = uVar17;
            uVar17 = vertexCursor;
          } while (vertexCursor <= uVar9);
          if (2 < iVar8) {
            if (twoSidedLighting) {
              pcVar10 = *(code **)(iVar11 * 4 + glContext + 0x4de8);
LAB_000ee37c:
              (*pcVar10)(glContext,uVar15,iVar8);
            }
            else if (bVar2) {
              pcVar10 = *(code **)(glContext + 0x4de8);
              goto LAB_000ee37c;
            }
            if (iVar11 == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            dVar19 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46c4))
                                       (*(undefined4 *)(glContext + 0x4688), uVar15, iVar8, facePolygonMode - 0x1b00);
          }
        }
        vertexCursor = uVar17;
      } while (uVar17 <= uVar9);
    }
  }
  else {
    if (texturingEnabled) {
      dVar19 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCount, 0);
    }
    polygonList = *(uint **)(glContext + 0x4870);
    spareList = *(uint **)(glContext + 0x4874);
    uVar17 = (vertexCursor + vertexCount * 0x100) - 0x300;
    if (vertexCursor <= uVar17) {
      do {
        polygonList[1] = vertexCursor + 0x100;
        polygonList[2] = vertexCursor + 0x200;
        *polygonList = vertexCursor;
        *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
        puVar13 = spareList;
        puVar7 = polygonList;
        iVar11 = 3;
        if ((*(char *)(glContext + 0x4e18) == '\0') ||
           (dVar19 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,local_3c,dVar19,incomingFpr2,incomingFpr3
                                               ,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,
                                               incomingStack_ffffff90), puVar13 = polygonList,
           puVar7 = spareList, iVar11 = local_3c[0], local_3c[0] != 0)) {
          polygonList = puVar7;
          spareList = puVar13;
          if ((batchClipCodes & 0xff) != 0) {
            dVar19 = (double)_gleClipPoly(glContext,polygonList,iVar11,batchClipCodes & 0xff,puVar13,local_3c,1);
            if (local_3c[0] == 0) goto LAB_000ee550;
            if (0 < local_3c[0]) {
              spareList = polygonList;
              polygonList = puVar13;
              iVar11 = local_3c[0];
            }
          }
          if ((faceTestNeeded == '\0') ||
             (iVar8 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,iVar11,&local_40),
             dVar19 = f1AfterCall2, iVar8 == 0)) {
            iVar8 = local_40;
            if (twoSidedLighting) {
              pcVar10 = *(code **)(local_40 * 4 + glContext + 0x4df0);
LAB_000ee514:
              (*pcVar10)(glContext,polygonList,iVar11);
            }
            else if (bVar2) {
              pcVar10 = *(code **)(glContext + 0x4df0);
              goto LAB_000ee514;
            }
            if (iVar8 == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            dVar19 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                       (*(undefined4 *)(glContext + 0x4688), polygonList, iVar11, facePolygonMode - 0x1b00);
          }
        }
LAB_000ee550:
        vertexCursor = vertexCursor + 0x300;
      } while (vertexCursor <= uVar17);
    }
  }
  return;
}

/* _gleRenderFlatTrianglesFunc_body @ 0xee57c (1312 bytes) */
void _gleRenderFlatTrianglesFunc_body(glContext)
  int glContext;
{
  bool lightingEnabled;
  bool bVar2;
  bool texturingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint batchClipCodes;
  int runLightVertex;
  int iVar10;
  uint *spareList;
  uint *puVar12;
  int runLightedVertices;
  char lightingPending;
  uint runStart;
  uint *polygonList;
  int iVar17;
  uint triangleCursor;
  uint uVar19;
  double f1AfterCall;
  double dVar20;
  double extraout_f1_00;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  int backFacing;
  int clippedCount [6];
  
  iVar10 = -1;
  iVar7 = _gleTexEnableBits(glContext);
  lightingPending = *(char *)(glContext + 0x30aa);
  twoSidedLighting = false;
  lightingEnabled = lightingPending != '\0';
  if ((lightingEnabled) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  triangleCursor = *(uint *)(glContext + 0x4854);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  iVar17 = (int)(*(int *)(glContext + 0x4858) - triangleCursor) >> 8;
  if ((2 < iVar17) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,triangleCursor,iVar17), (batchClipCodes & 0xff00) == 0)) {
    texturingEnabled = iVar7 != 0;
    dVar20 = f1AfterCall;
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
      dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, triangleCursor, iVar17);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, triangleCursor, iVar17);
    }
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e6) != '\0') {
        lightingPending = '\0';
        dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, triangleCursor, iVar17);
      }
      if (*(char *)(glContext + 0x53e5) != '\0') {
        dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, triangleCursor, iVar17);
      }
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (texturingEnabled) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, triangleCursor, iVar17, 0);
      }
      if (faceTestNeeded == '\0') {
        if (lightingEnabled) {
          iVar10 = 0;
          if (-1 < iVar17 + -3) {
            iVar7 = triangleCursor + 0x200;
            do {
              if (lightingPending != '\0') {
                (**(code **)(glContext + 0x5068))(glContext,iVar7,1);
              }
              iVar10 = iVar10 + 3;
              (**(code **)(glContext + 0x4de8))(glContext,iVar7,1);
              iVar7 = iVar7 + 0x300;
            } while (iVar10 <= iVar17 + -3);
          }
        }
        (**(code **)(glContext + 0x46c4))
                  (*(undefined4 *)(glContext + 0x4688),triangleCursor,iVar17,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        uVar8 = (triangleCursor + iVar17 * 0x100) - 0x300;
        do {
          iVar7 = 0;
          bVar2 = false;
          runStart = triangleCursor;
          uVar19 = triangleCursor;
          if (triangleCursor <= uVar8) {
            do {
              iVar17 = ((undefined4 (*)())_gleCullTriangle)(glContext,triangleCursor,triangleCursor + 0x100,triangleCursor + 0x200,0,&backFacing,
                                        dVar20,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                        incomingStack_ffffff78,incomingStack_ffffff80);
              dVar20 = dVar20;
              if (iVar17 == 0) {
                if (iVar10 != backFacing) {
                  bVar2 = true;
                }
                if ((bVar2) && (uVar19 = triangleCursor, 0 < iVar7)) break;
                iVar7 = iVar7 + 3;
                iVar10 = backFacing;
                uVar19 = runStart;
              }
              else {
                uVar19 = triangleCursor + 0x300;
                if (0 < iVar7) break;
              }
              triangleCursor = triangleCursor + 0x300;
              runStart = uVar19;
              uVar19 = triangleCursor;
            } while (triangleCursor <= uVar8);
            if (2 < iVar7) {
              if (lightingEnabled) {
                iVar17 = iVar10;
                if (!twoSidedLighting) {
                  iVar17 = 0;
                }
                runLightedVertices = 0;
                if (-1 < iVar7 + -3) {
                  runLightVertex = runStart + 0x200;
                  do {
                    if (lightingPending != '\0') {
                      (**(code **)(glContext + 0x5068))(glContext,runLightVertex,1);
                    }
                    runLightedVertices = runLightedVertices + 3;
                    (**(code **)(iVar17 * 4 + glContext + 0x4de8))(glContext,runLightVertex,1);
                    runLightVertex = runLightVertex + 0x300;
                  } while (runLightedVertices <= iVar7 + -3);
                }
              }
              if (iVar10 == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46c4))
                                         (*(undefined4 *)(glContext + 0x4688), runStart, iVar7, facePolygonMode - 0x1b00);
            }
          }
          triangleCursor = uVar19;
        } while (uVar19 <= uVar8);
      }
    }
    else {
      if (texturingEnabled) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, triangleCursor, iVar17, 0);
      }
      polygonList = *(uint **)(glContext + 0x4870);
      iVar10 = triangleCursor + iVar17 * 0x100;
      spareList = *(uint **)(glContext + 0x4874);
      for (; triangleCursor <= iVar10 - 0x300U; triangleCursor = triangleCursor + 0x300) {
        uVar19 = triangleCursor + 0x200;
        polygonList[1] = triangleCursor + 0x100;
        *polygonList = triangleCursor;
        polygonList[2] = uVar19;
        *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
        puVar12 = spareList;
        puVar6 = polygonList;
        iVar7 = 3;
        if ((*(char *)(glContext + 0x4e18) == '\0') ||
           (dVar20 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,clippedCount,dVar20,incomingFpr2,incomingFpr3
                                               ,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                               incomingStack_ffffff80), puVar12 = polygonList,
           puVar6 = spareList, iVar7 = clippedCount[0], clippedCount[0] != 0)) {
          polygonList = puVar6;
          spareList = puVar12;
          if ((batchClipCodes & 0xff) != 0) {
            dVar20 = (double)_gleClipPoly(glContext,polygonList,iVar7,batchClipCodes & 0xff,puVar12,clippedCount,1);
            if (clippedCount[0] == 0) goto LAB_000eea74;
            if (0 < clippedCount[0]) {
              spareList = polygonList;
              polygonList = puVar12;
              iVar7 = clippedCount[0];
            }
          }
          if ((faceTestNeeded == '\0') ||
             (iVar17 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,iVar7,&backFacing),
             dVar20 = f1AfterCall2, iVar17 == 0)) {
            if (lightingPending != '\0') {
              (**(code **)(glContext + 0x5068))(glContext,uVar19,1);
            }
            if (lightingEnabled) {
              iVar17 = 0x4de0;
              if (twoSidedLighting) {
                iVar17 = backFacing * 4 + 0x4de0;
              }
              (**(code **)(glContext + iVar17 + 8))(glContext,uVar19,1);
            }
            *(undefined8 *)(*polygonList + 0x30) = *(undefined8 *)(triangleCursor + 0x230);
            *(undefined8 *)(*polygonList + 0x38) = *(undefined8 *)(triangleCursor + 0x238);
            if (backFacing == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                       (*(undefined4 *)(glContext + 0x4688), polygonList, iVar7, facePolygonMode - 0x1b00);
          }
        }
LAB_000eea74: ;
      }
    }
  }
  return;
}

/* _gleRenderSmoothTriangleStripFunc_body @ 0xeeac8 (1412 bytes) */
void _gleRenderSmoothTriangleStripFunc_body(glContext)
  int glContext;
{
  bool facingChanged;
  bool texturingEnabled;
  bool lightingActive;
  byte lightingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  bool windingFlip;
  uint runStart;
  uint *newPolygonList;
  uint stripParityOrRunCursor;
  int texBitsOrRunCountOrBackFacing;
  uint parityCarry;
  uint batchClipCodes;
  int polygonCullResult;
  uint *oldListOrVertexPtrCursor;
  code *lightingFunc;
  uint runStartParityOrLastLimit;
  int *polygonScratch;
  int previousBackFacingOrRemaining;
  uint lastTriangleLimit;
  uint nextRunStart;
  uint *spareList;
  uint vertexCursor;
  uint nextVertex;
  uint *polygonVerts;
  int cullResultOrVertexCount;
  int vertexCount;
  double f1AfterCall;
  double forwardedFloatArg1;
  double f1AfterCall1;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  int backFacing;
  int clipCount [4];
  
  previousBackFacingOrRemaining = -1;
  texBitsOrRunCountOrBackFacing = _gleTexEnableBits(glContext);
  lightingEnabled = *(byte *)(glContext + 0x30aa);
  twoSidedLighting = false;
  if ((lightingEnabled != 0) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  vertexCursor = *(uint *)(glContext + 0x4854);
  runStartParityOrLastLimit = 0;
  faceTestNeeded = *(char *)(glContext + 0x34de);
  vertexCount = (int)(*(int *)(glContext + 0x4858) - vertexCursor) >> 8;
  if (vertexCount < 3) {
    return;
  }
  batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount);
  if ((batchClipCodes & 0xff00) != 0) {
    return;
  }
  texturingEnabled = texBitsOrRunCountOrBackFacing != 0;
  forwardedFloatArg1 = f1AfterCall;
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
    forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, vertexCount);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCount);
  }
  lightingActive = (int)-(uint)lightingEnabled < 0;
  if (lightingActive) {
LAB_000eebc4:
    forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, vertexCount);
  }
  else {
    if (!texturingEnabled) goto LAB_000eec04;
    if (*(char *)(glContext + 0x53e6) != '\0') goto LAB_000eebc4;
  }
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e5) != '\0')) {
    forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, vertexCursor, vertexCount);
  }
LAB_000eec04:
  if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (texturingEnabled) {
      forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCount, 0);
    }
    if (faceTestNeeded == '\0') {
      if (lightingActive) {
        (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,vertexCount);
      }
      (**(code **)(glContext + 0x46cc))
                (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCount,
                 *(ushort *)(glContext + 0x34d0) - 0x1b00);
    }
    else {
      polygonScratch = *(int **)(glContext + 0x4870);
      lastTriangleLimit = (vertexCursor + vertexCount * 0x100) - 0x300;
      parityCarry = 0;
      do {
        facingChanged = false;
        texBitsOrRunCountOrBackFacing = 0;
        stripParityOrRunCursor = parityCarry;
        runStart = vertexCursor;
        while (parityCarry = stripParityOrRunCursor, vertexCursor <= lastTriangleLimit) {
          nextVertex = vertexCursor + 0x100;
          cullResultOrVertexCount = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,nextVertex,vertexCursor + 0x200,stripParityOrRunCursor,&backFacing,forwardedFloatArg1,
                                    incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                    incomingStack_ffffff80);
          forwardedFloatArg1 = f1AfterCall1;
          if (cullResultOrVertexCount == 0) {
            if (previousBackFacingOrRemaining != backFacing) {
              facingChanged = true;
            }
            if ((facingChanged) && (0 < texBitsOrRunCountOrBackFacing)) break;
            if (texBitsOrRunCountOrBackFacing == 0) {
              runStartParityOrLastLimit = stripParityOrRunCursor;
            }
            texBitsOrRunCountOrBackFacing = texBitsOrRunCountOrBackFacing + 1;
            previousBackFacingOrRemaining = backFacing;
            nextRunStart = runStart;
          }
          else {
            nextRunStart = nextVertex;
            parityCarry = stripParityOrRunCursor ^ 1;
            vertexCursor = nextVertex;
            if (0 < texBitsOrRunCountOrBackFacing) break;
          }
          stripParityOrRunCursor = stripParityOrRunCursor ^ 1;
          vertexCursor = nextVertex;
          runStart = nextRunStart;
        }
        cullResultOrVertexCount = texBitsOrRunCountOrBackFacing + 2;
        if (2 < cullResultOrVertexCount) {
          if (twoSidedLighting) {
            if (facingChanged) {
              stripParityOrRunCursor = runStart;
              do {
                *(byte *)(stripParityOrRunCursor + 0x7e) = *(byte *)(stripParityOrRunCursor + 0x7e) | 6;
                stripParityOrRunCursor = stripParityOrRunCursor + 0x100;
              } while ((int)stripParityOrRunCursor <= (int)(runStart + 0x100));
            }
            lightingFunc = *(code **)(previousBackFacingOrRemaining * 4 + glContext + 0x4de8);
LAB_000eed90:
            (*lightingFunc)(glContext,runStart,cullResultOrVertexCount);
          }
          else if (lightingActive) {
            lightingFunc = *(code **)(glContext + 0x4de8);
            goto LAB_000eed90;
          }
          stripParityOrRunCursor = runStart;
          if (runStartParityOrLastLimit != 0) {
            stripParityOrRunCursor = runStart + 0x100;
            *polygonScratch = runStart + 0x200;
            polygonScratch[2] = runStart;
            polygonScratch[1] = stripParityOrRunCursor;
            if (previousBackFacingOrRemaining != 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            cullResultOrVertexCount = texBitsOrRunCountOrBackFacing + 1;
            forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                       (*(undefined4 *)(glContext + 0x4688), polygonScratch, 3, facePolygonMode - 0x1b00);
            if (cullResultOrVertexCount < 3) goto LAB_000eee24;
          }
          if (previousBackFacingOrRemaining != 0) {
            facePolygonMode = *(ushort *)(glContext + 0x34d2);
          }
          else {
            facePolygonMode = *(ushort *)(glContext + 0x34d0);
          }
          forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46cc))
                                     (*(undefined4 *)(glContext + 0x4688), stripParityOrRunCursor, cullResultOrVertexCount, facePolygonMode - 0x1b00);
        }
LAB_000eee24: ;
      } while (vertexCursor <= lastTriangleLimit);
    }
  }
  else {
    if (texturingEnabled) {
      forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCount, 0);
    }
    facingChanged = false;
    runStartParityOrLastLimit = (vertexCursor + vertexCount * 0x100) - 0x300;
    spareList = *(uint **)(glContext + 0x4874);
    polygonVerts = *(uint **)(glContext + 0x4870);
    if (vertexCursor <= runStartParityOrLastLimit) {
      windingFlip = false;
      do {
        windingFlip = !windingFlip;
        if (windingFlip) {
          polygonVerts[2] = vertexCursor + 0x200;
          *polygonVerts = vertexCursor;
        }
        else {
          *polygonVerts = vertexCursor + 0x200;
          polygonVerts[2] = vertexCursor;
        }
        vertexCursor = vertexCursor + 0x100;
        polygonVerts[1] = vertexCursor;
        *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
        oldListOrVertexPtrCursor = spareList;
        newPolygonList = polygonVerts;
        cullResultOrVertexCount = 3;
        texBitsOrRunCountOrBackFacing = previousBackFacingOrRemaining;
        if ((*(char *)(glContext + 0x4e18) == '\0') ||
           (forwardedFloatArg1 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonVerts,3,spareList,clipCount,forwardedFloatArg1,incomingFpr2,incomingFpr3
                                               ,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                               incomingStack_ffffff80), oldListOrVertexPtrCursor = polygonVerts,
           newPolygonList = spareList, cullResultOrVertexCount = clipCount[0], clipCount[0] != 0)) {
          polygonVerts = newPolygonList;
          spareList = oldListOrVertexPtrCursor;
          if ((batchClipCodes & 0xff) != 0) {
            forwardedFloatArg1 = (double)_gleClipPoly(glContext,polygonVerts,cullResultOrVertexCount,batchClipCodes & 0xff,oldListOrVertexPtrCursor,clipCount,1);
            if (clipCount[0] == 0) goto LAB_000ef024;
            if (0 < clipCount[0]) {
              spareList = polygonVerts;
              polygonVerts = oldListOrVertexPtrCursor;
              cullResultOrVertexCount = clipCount[0];
            }
          }
          if ((faceTestNeeded == '\0') ||
             (polygonCullResult = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonVerts,cullResultOrVertexCount,&backFacing),
             forwardedFloatArg1 = f1AfterCall2, polygonCullResult == 0)) {
            texBitsOrRunCountOrBackFacing = backFacing;
            if (previousBackFacingOrRemaining != backFacing) {
              facingChanged = true;
            }
            if (twoSidedLighting) {
              if (facingChanged) {
                oldListOrVertexPtrCursor = polygonVerts;
                previousBackFacingOrRemaining = cullResultOrVertexCount;
                if (0 < cullResultOrVertexCount) {
                  do {
                    *(byte *)(*oldListOrVertexPtrCursor + 0x7e) = *(byte *)(*oldListOrVertexPtrCursor + 0x7e) | 6;
                    previousBackFacingOrRemaining = previousBackFacingOrRemaining + -1;
                    oldListOrVertexPtrCursor = oldListOrVertexPtrCursor + 1;
                  } while (previousBackFacingOrRemaining != 0);
                }
                facingChanged = false;
              }
              lightingFunc = *(code **)(backFacing * 4 + glContext + 0x4df0);
LAB_000eefe8:
              (*lightingFunc)(glContext,polygonVerts,cullResultOrVertexCount);
            }
            else if (lightingActive) {
              lightingFunc = *(code **)(glContext + 0x4df0);
              goto LAB_000eefe8;
            }
            if (texBitsOrRunCountOrBackFacing == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                       (*(undefined4 *)(glContext + 0x4688), polygonVerts, cullResultOrVertexCount, facePolygonMode - 0x1b00);
          }
        }
LAB_000ef024:
        previousBackFacingOrRemaining = texBitsOrRunCountOrBackFacing;
      } while (vertexCursor <= runStartParityOrLastLimit);
    }
  }
  return;
}

/* _gleRenderFlatTriangleStripFunc_body @ 0xef050 (1396 bytes) */
void _gleRenderFlatTriangleStripFunc_body(glContext)
  int glContext;
{
  bool lightingEnabled;
  bool bVar2;
  bool windingFlip;
  bool texturingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint batchClipCodes;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  int iVar14;
  int polygonVertexCount;
  uint uVar15;
  uint uVar16;
  uint *spareList;
  uint *puVar18;
  char lightingPending;
  int iVar19;
  uint vertexCursor;
  uint uVar22;
  int iVar23;
  uint *puVar24;
  int iVar25;
  int vertexCount;
  double f1AfterCall;
  double dVar26;
  double f1AfterCall1;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  int backFacing;
  int local_4c [5];
  
  iVar14 = -1;
  iVar9 = _gleTexEnableBits(glContext);
  lightingPending = *(char *)(glContext + 0x30aa);
  twoSidedLighting = false;
  lightingEnabled = lightingPending != '\0';
  if ((lightingEnabled) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  vertexCursor = *(uint *)(glContext + 0x4854);
  uVar12 = 0;
  faceTestNeeded = *(char *)(glContext + 0x34de);
  vertexCount = (int)(*(int *)(glContext + 0x4858) - vertexCursor) >> 8;
  if ((2 < vertexCount) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount), (batchClipCodes & 0xff00) == 0)) {
    texturingEnabled = iVar9 != 0;
    dVar26 = f1AfterCall;
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
      dVar26 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, vertexCount);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      dVar26 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCount);
    }
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e6) != '\0') {
        lightingPending = '\0';
        dVar26 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, vertexCount);
      }
      if (*(char *)(glContext + 0x53e5) != '\0') {
        dVar26 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, vertexCursor, vertexCount);
      }
    }
    if (lightingPending != '\0') {
      dVar26 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor + 0x200, vertexCount + -2);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (texturingEnabled) {
        dVar26 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCount, 0);
      }
      if (faceTestNeeded == '\0') {
        if ((lightingEnabled) && (-1 < vertexCount + -3)) {
          iVar9 = vertexCount + -2;
          iVar14 = vertexCursor + 0x200;
          do {
            (**(code **)(glContext + 0x4de8))(glContext,iVar14,1);
            iVar9 = iVar9 + -1;
            iVar14 = iVar14 + 0x100;
          } while (iVar9 != 0);
        }
        (**(code **)(glContext + 0x46cc))
                  (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCount,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        piVar13 = *(int **)(glContext + 0x4870);
        uVar15 = (vertexCursor + vertexCount * 0x100) - 0x300;
        uVar10 = 0;
        do {
          iVar9 = 0;
          bVar2 = false;
          uVar11 = uVar10;
          uVar6 = vertexCursor;
          while (uVar10 = uVar11, vertexCursor <= uVar15) {
            uVar22 = vertexCursor + 0x100;
            iVar25 = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,uVar22,vertexCursor + 0x200,uVar11,&backFacing,dVar26,
                                      incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                      incomingStack_ffffff80);
            dVar26 = f1AfterCall1;
            if (iVar25 == 0) {
              if (iVar14 != backFacing) {
                bVar2 = true;
              }
              if ((bVar2) && (0 < iVar9)) break;
              if (iVar9 == 0) {
                uVar12 = uVar11;
              }
              iVar9 = iVar9 + 1;
              iVar14 = backFacing;
              uVar16 = uVar6;
            }
            else {
              uVar16 = uVar22;
              uVar10 = uVar11 ^ 1;
              vertexCursor = uVar22;
              if (0 < iVar9) break;
            }
            uVar11 = uVar11 ^ 1;
            vertexCursor = uVar22;
            uVar6 = uVar16;
          }
          iVar25 = iVar9 + 2;
          if (2 < iVar25) {
            if (lightingEnabled) {
              iVar8 = iVar14;
              if (!twoSidedLighting) {
                iVar8 = 0;
              }
              if (-1 < iVar9 + -1) {
                iVar19 = iVar9;
                iVar23 = uVar6 + 0x200;
                do {
                  (**(code **)(iVar8 * 4 + glContext + 0x4de8))(glContext,iVar23,1);
                  iVar19 = iVar19 + -1;
                  iVar23 = iVar23 + 0x100;
                } while (iVar19 != 0);
              }
            }
            uVar11 = uVar6;
            if (uVar12 != 0) {
              uVar11 = uVar6 + 0x100;
              *piVar13 = uVar6 + 0x200;
              piVar13[2] = uVar6;
              piVar13[1] = uVar11;
              if (iVar14 != 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              iVar25 = iVar9 + 1;
              dVar26 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), piVar13, 3, facePolygonMode - 0x1b00);
              if (iVar25 < 3) goto LAB_000ef3cc;
            }
            if (iVar14 != 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            dVar26 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46cc))
                                       (*(undefined4 *)(glContext + 0x4688), uVar11, iVar25, facePolygonMode - 0x1b00);
          }
LAB_000ef3cc: ;
        } while (vertexCursor <= uVar15);
      }
    }
    else {
      if (texturingEnabled) {
        dVar26 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCount, 0);
      }
      uVar12 = (vertexCursor + vertexCount * 0x100) - 0x300;
      spareList = *(uint **)(glContext + 0x4874);
      puVar24 = *(uint **)(glContext + 0x4870);
      if (vertexCursor <= uVar12) {
        windingFlip = false;
        do {
          windingFlip = !windingFlip;
          if (windingFlip) {
            *puVar24 = vertexCursor;
            puVar24[1] = vertexCursor + 0x100;
            puVar24[2] = vertexCursor + 0x200;
          }
          else {
            puVar24[2] = vertexCursor;
            *puVar24 = vertexCursor + 0x200;
            puVar24[1] = vertexCursor + 0x100;
          }
          uVar15 = vertexCursor + 0x100;
          *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
          puVar18 = spareList;
          puVar7 = puVar24;
          iVar14 = 3;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar26 = (double)((double (*)())_gleClipPolyPlane)(glContext,puVar24,3,spareList,local_4c,dVar26,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             puVar18 = puVar24, puVar7 = spareList, polygonVertexCount = local_4c[0], local_4c[0] != 0)) {
            puVar24 = puVar7;
            spareList = puVar18;
            if ((batchClipCodes & 0xff) != 0) {
              dVar26 = (double)_gleClipPoly(glContext,puVar24,polygonVertexCount,batchClipCodes & 0xff,puVar18,local_4c,1)
              ;
              if (local_4c[0] == 0) goto LAB_000ef59c;
              if (0 < local_4c[0]) {
                spareList = puVar24;
                puVar24 = puVar18;
                polygonVertexCount = local_4c[0];
              }
            }
            if ((faceTestNeeded == '\0') ||
               (iVar9 = ((int (*)())_gleCullPolygonPtrStack)(glContext,puVar24,polygonVertexCount,&backFacing),
               dVar26 = f1AfterCall2, iVar9 == 0)) {
              if (lightingEnabled) {
                iVar9 = 0x4de0;
                if (twoSidedLighting) {
                  iVar9 = backFacing * 4 + 0x4de0;
                }
                (**(code **)(glContext + iVar9 + 8))(glContext,vertexCursor + 0x200,1);
              }
              *(undefined8 *)(*puVar24 + 0x30) = *(undefined8 *)(vertexCursor + 0x230);
              *(undefined8 *)(*puVar24 + 0x38) = *(undefined8 *)(vertexCursor + 0x238);
              if (backFacing == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              dVar26 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), puVar24, polygonVertexCount, facePolygonMode - 0x1b00);
            }
          }
LAB_000ef59c:
          vertexCursor = uVar15;
        } while (uVar15 <= uVar12);
      }
    }
  }
  return;
}

/* _gleRenderSmoothTriangleFanFunc_body @ 0xef5f4 (1300 bytes) */
void _gleRenderSmoothTriangleFanFunc_body(glContext)
  int glContext;
{
  bool bVar1;
  bool texturingEnabled;
  bool bVar2;
  byte lightingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint batchClipCodes;
  int iVar10;
  int *piVar11;
  code *pcVar12;
  int iVar13;
  int *spareList;
  uint uVar15;
  int vertexCursor;
  int *piVar17;
  int *polygonList;
  int iVar19;
  uint uVar20;
  double f1AfterCall;
  double dVar21;
  double f1AfterCall1;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  int backFacing;
  int local_4c [4];
  
  iVar13 = -1;
  iVar8 = _gleTexEnableBits(glContext);
  lightingEnabled = *(byte *)(glContext + 0x30aa);
  twoSidedLighting = false;
  if ((lightingEnabled != 0) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  vertexCursor = *(int *)(glContext + 0x4854);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  iVar19 = *(int *)(glContext + 0x4858) - vertexCursor >> 8;
  if (iVar19 < 3) {
    return;
  }
  batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,iVar19);
  if ((batchClipCodes & 0xff00) != 0) {
    return;
  }
  texturingEnabled = iVar8 != 0;
  dVar21 = f1AfterCall;
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
    dVar21 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, iVar19);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    dVar21 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, iVar19);
  }
  bVar2 = (int)-(uint)lightingEnabled < 0;
  if (bVar2) {
LAB_000ef6ec:
    dVar21 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, iVar19);
  }
  else {
    if (!texturingEnabled) goto LAB_000ef72c;
    if (*(char *)(glContext + 0x53e6) != '\0') goto LAB_000ef6ec;
  }
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e5) != '\0')) {
    dVar21 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, vertexCursor, iVar19);
  }
LAB_000ef72c:
  if (((batchClipCodes & 0xff) != 0) || (*(char *)(glContext + 0x4e18) != '\0')) {
    if (texturingEnabled) {
      dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, iVar19, 0);
    }
    bVar1 = false;
    uVar15 = vertexCursor + 0x100;
    polygonList = *(int **)(glContext + 0x4870);
    spareList = *(int **)(glContext + 0x4874);
joined_r0x000ef960:
    do {
      if ((vertexCursor + iVar19 * 0x100) - 0x200U < uVar15) {
        return;
      }
      uVar20 = uVar15 + 0x100;
      *polygonList = vertexCursor;
      polygonList[1] = uVar15;
      polygonList[2] = uVar20;
      *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
      piVar11 = spareList;
      piVar17 = polygonList;
      iVar8 = 3;
      uVar15 = uVar20;
    } while ((*(char *)(glContext + 0x4e18) != '\0') &&
            (dVar21 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,local_4c,dVar21,incomingFpr2,
                                                incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                incomingStack_ffffff78,incomingStack_ffffff80),
            piVar11 = polygonList, piVar17 = spareList, iVar8 = local_4c[0], local_4c[0] == 0));
    spareList = piVar11;
    polygonList = piVar17;
    if ((batchClipCodes & 0xff) != 0) goto code_r0x000ef9c8;
    goto LAB_000efa08;
  }
  if (texturingEnabled) {
    dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, iVar19, 0);
  }
  if (faceTestNeeded == '\0') {
    if (bVar2) {
      (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,iVar19);
    }
    (**(code **)(glContext + 0x46c8))
              (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCursor + 0x100,iVar19 + -1,
               *(ushort *)(glContext + 0x34d0) - 0x1b00);
  }
  else {
    uVar9 = vertexCursor + 0x100;
    uVar15 = (vertexCursor + iVar19 * 0x100) - 0x200;
    do {
      bVar1 = false;
      iVar8 = 0;
      uVar20 = uVar9;
      do {
        while( true ) {
          uVar7 = uVar20;
          if (uVar15 < uVar9) goto LAB_000ef844;
          uVar20 = uVar9 + 0x100;
          iVar19 = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,uVar9,uVar20,0,&backFacing,dVar21,incomingFpr2,incomingFpr3,incomingFpr4
                                    ,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,incomingStack_ffffff80);
          dVar21 = f1AfterCall1;
          if (iVar19 != 0) break;
          if (iVar13 != backFacing) {
            bVar1 = true;
          }
          if ((bVar1) && (0 < iVar8)) goto LAB_000ef844;
          iVar8 = iVar8 + 1;
          iVar13 = backFacing;
          uVar9 = uVar20;
          uVar20 = uVar7;
        }
        uVar9 = uVar20;
      } while (iVar8 < 1);
LAB_000ef844:
      iVar8 = iVar8 + 1;
      if (1 < iVar8) {
        if (twoSidedLighting) {
          if (bVar1) {
            *(byte *)(vertexCursor + 0x7e) = *(byte *)(vertexCursor + 0x7e) | 6;
            *(byte *)(uVar7 + 0x7e) = *(byte *)(uVar7 + 0x7e) | 6;
          }
          iVar19 = iVar13 * 4 + glContext;
          (**(code **)(iVar19 + 0x4de8))(glContext,vertexCursor,1);
          pcVar12 = *(code **)(iVar19 + 0x4de8);
LAB_000ef8d8:
          (*pcVar12)(glContext,uVar7,iVar8);
        }
        else if (bVar2) {
          (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,1);
          pcVar12 = *(code **)(glContext + 0x4de8);
          goto LAB_000ef8d8;
        }
        if (iVar13 == 0) {
          facePolygonMode = *(ushort *)(glContext + 0x34d0);
        }
        else {
          facePolygonMode = *(ushort *)(glContext + 0x34d2);
        }
        dVar21 = (double)(**(double ( **)(int,int,int,int,int))(glContext + 0x46c8))
                                   (*(undefined4 *)(glContext + 0x4688), vertexCursor, uVar7, iVar8, facePolygonMode - 0x1b00);
      }
    } while (uVar9 <= uVar15);
  }
  return;
code_r0x000ef9c8:
  dVar21 = (double)_gleClipPoly(glContext,piVar17,iVar8,batchClipCodes & 0xff,piVar11,local_4c,1);
  if (local_4c[0] == 0) goto joined_r0x000ef960;
  if (0 < local_4c[0]) {
    spareList = piVar17;
    polygonList = piVar11;
    iVar8 = local_4c[0];
  }
LAB_000efa08:
  if ((faceTestNeeded != '\0') &&
     (iVar10 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,iVar8,&backFacing), dVar21 = f1AfterCall2,
     iVar10 != 0)) goto joined_r0x000ef960;
  iVar10 = backFacing;
  if (iVar13 != backFacing) {
    bVar1 = true;
  }
  if (twoSidedLighting) {
    if (bVar1) {
      piVar11 = polygonList;
      iVar13 = iVar8;
      if (0 < iVar8) {
        do {
          *(byte *)(*piVar11 + 0x7e) = *(byte *)(*piVar11 + 0x7e) | 6;
          iVar13 = iVar13 + -1;
          piVar11 = piVar11 + 1;
        } while (iVar13 != 0);
      }
      bVar1 = false;
    }
    pcVar12 = *(code **)(backFacing * 4 + glContext + 0x4df0);
  }
  else {
    if (!bVar2) goto LAB_000efab0;
    pcVar12 = *(code **)(glContext + 0x4df0);
  }
  (*pcVar12)(glContext,polygonList,iVar8);
LAB_000efab0:
  if (iVar10 == 0) {
    facePolygonMode = *(ushort *)(glContext + 0x34d0);
  }
  else {
    facePolygonMode = *(ushort *)(glContext + 0x34d2);
  }
  dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                             (*(undefined4 *)(glContext + 0x4688), polygonList, iVar8, facePolygonMode - 0x1b00);
  iVar13 = iVar10;
  goto joined_r0x000ef960;
}

/* _gleRenderFlatTriangleFanFunc_body @ 0xefb0c (1244 bytes) */
void _gleRenderFlatTriangleFanFunc_body(glContext)
  int glContext;
{
  bool lightingEnabled;
  bool bVar2;
  bool texturingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint batchClipCodes;
  int iVar10;
  int polygonVertexCount;
  uint uVar11;
  int *spareList;
  int *piVar13;
  int vertexCursor;
  uint uVar15;
  int *polygonList;
  int iVar17;
  uint uVar18;
  char lightingPending;
  double f1AfterCall;
  double dVar20;
  double f1AfterCall1;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  int backFacing;
  int local_4c [6];
  
  iVar10 = -1;
  iVar8 = _gleTexEnableBits(glContext);
  lightingPending = *(char *)(glContext + 0x30aa);
  twoSidedLighting = false;
  lightingEnabled = lightingPending != '\0';
  if ((lightingEnabled) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  vertexCursor = *(int *)(glContext + 0x4854);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  iVar17 = *(int *)(glContext + 0x4858) - vertexCursor >> 8;
  if ((2 < iVar17) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,iVar17), (batchClipCodes & 0xff00) == 0)) {
    texturingEnabled = iVar8 != 0;
    dVar20 = f1AfterCall;
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
      dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, iVar17);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, iVar17);
    }
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e6) != '\0') {
        lightingPending = '\0';
        dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, iVar17);
      }
      if (*(char *)(glContext + 0x53e5) != '\0') {
        dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, vertexCursor, iVar17);
      }
    }
    if (lightingPending != '\0') {
      dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor + 0x200, iVar17 + -2);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (texturingEnabled) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, iVar17, 0);
      }
      if (faceTestNeeded == '\0') {
        if ((lightingEnabled) && (iVar10 = iVar17 + -2, 0 < iVar10)) {
          iVar8 = vertexCursor + 0x200;
          do {
            (**(code **)(glContext + 0x4de8))(glContext,iVar8,1);
            iVar10 = iVar10 + -1;
            iVar8 = iVar8 + 0x100;
          } while (iVar10 != 0);
        }
        (**(code **)(glContext + 0x46c8))
                  (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCursor + 0x100,iVar17 + -1,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        uVar9 = vertexCursor + 0x100;
        uVar11 = (vertexCursor + iVar17 * 0x100) - 0x200;
        do {
          iVar8 = 0;
          bVar2 = false;
          uVar18 = uVar9;
          do {
            while( true ) {
              uVar15 = uVar18;
              if (uVar11 < uVar9) goto LAB_000efd88;
              uVar18 = uVar9 + 0x100;
              iVar17 = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,uVar9,uVar18,0,&backFacing,dVar20,incomingFpr2,incomingFpr3,
                                        incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                        incomingStack_ffffff80);
              dVar20 = f1AfterCall1;
              if (iVar17 != 0) break;
              if (iVar10 != backFacing) {
                bVar2 = true;
              }
              if ((bVar2) && (0 < iVar8)) goto LAB_000efd88;
              iVar8 = iVar8 + 1;
              iVar10 = backFacing;
              uVar9 = uVar18;
              uVar18 = uVar15;
            }
            uVar9 = uVar18;
          } while (iVar8 < 1);
LAB_000efd88:
          iVar17 = iVar8 + 1;
          if (1 < iVar17) {
            if (lightingEnabled) {
              iVar7 = iVar10;
              if (!twoSidedLighting) {
                iVar7 = 0;
              }
              if (-1 < iVar8 + -1) {
                uVar18 = uVar15;
                do {
                  uVar18 = uVar18 + 0x100;
                  (**(code **)(iVar7 * 4 + glContext + 0x4de8))(glContext,uVar18,1);
                  iVar8 = iVar8 + -1;
                } while (iVar8 != 0);
              }
            }
            if (iVar10 == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            dVar20 = (double)(**(double ( **)(int,int,int,int,int))(glContext + 0x46c8))
                                       (*(undefined4 *)(glContext + 0x4688), vertexCursor, uVar15, iVar17, facePolygonMode - 0x1b00);
          }
        } while (uVar9 <= uVar11);
      }
    }
    else {
      if (texturingEnabled) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, iVar17, 0);
      }
      polygonList = *(int **)(glContext + 0x4870);
      uVar11 = (vertexCursor + iVar17 * 0x100) - 0x200;
      spareList = *(int **)(glContext + 0x4874);
      if (vertexCursor + 0x100U <= uVar11) {
        uVar18 = vertexCursor + 0x100U;
        do {
          uVar15 = uVar18 + 0x100;
          *polygonList = vertexCursor;
          polygonList[1] = uVar18;
          polygonList[2] = uVar15;
          *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
          piVar13 = spareList;
          piVar6 = polygonList;
          iVar10 = 3;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar20 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,local_4c,dVar20,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             piVar13 = polygonList, piVar6 = spareList, polygonVertexCount = local_4c[0], local_4c[0] != 0)) {
            polygonList = piVar6;
            spareList = piVar13;
            if ((batchClipCodes & 0xff) != 0) {
              dVar20 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,piVar13,local_4c,1);
              if (local_4c[0] == 0) goto LAB_000effc0;
              if (0 < local_4c[0]) {
                spareList = polygonList;
                polygonList = piVar13;
                polygonVertexCount = local_4c[0];
              }
            }
            if ((faceTestNeeded == '\0') ||
               (iVar8 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing),
               dVar20 = f1AfterCall2, iVar8 == 0)) {
              if (lightingEnabled) {
                if (twoSidedLighting) {
                  iVar8 = backFacing * 4 + 0x4de0;
                }
                else {
                  iVar8 = 0x4de0;
                }
                (**(code **)(glContext + iVar8 + 8))(glContext,uVar15,1);
              }
              *(undefined8 *)(*polygonList + 0x30) = *(undefined8 *)(uVar18 + 0x130);
              *(undefined8 *)(*polygonList + 0x38) = *(undefined8 *)(uVar18 + 0x138);
              if (backFacing == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), polygonList, polygonVertexCount, facePolygonMode - 0x1b00);
            }
          }
LAB_000effc0:
          uVar18 = uVar15;
        } while (uVar15 <= uVar11);
      }
    }
  }
  return;
}

/* _gleRenderSmoothQuadsFunc_body @ 0xeffec (1148 bytes) */
void _gleRenderSmoothQuadsFunc_body(glContext)
  int glContext;
{
  bool facingChanged;
  bool texturingEnabled;
  bool lightingActive;
  byte lightingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  uint *puVar7;
  int iVar8;
  uint lastQuadStart;
  uint batchClipCodes;
  code *pcVar10;
  int iVar11;
  uint *spareList;
  uint *puVar13;
  uint *polygonList;
  uint uVar15;
  int cullResult;
  int vertexCount;
  uint vertexCursor;
  uint uVar18;
  double f1AfterCall;
  double dVar19;
  double extraout_f1_00;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  double incomingStack_ffffff98;
  int backFacing;
  int clippedCount [3];
  
  iVar11 = -1;
  iVar8 = _gleTexEnableBits(glContext);
  lightingEnabled = *(byte *)(glContext + 0x30aa);
  twoSidedLighting = false;
  if ((lightingEnabled != 0) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  vertexCursor = *(uint *)(glContext + 0x4854);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  vertexCount = (int)(*(int *)(glContext + 0x4858) - vertexCursor) >> 8;
  if (vertexCount < 4) {
    return;
  }
  batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount);
  if ((batchClipCodes & 0xff00) != 0) {
    return;
  }
  texturingEnabled = iVar8 != 0;
  dVar19 = f1AfterCall;
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
    dVar19 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, vertexCount);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    dVar19 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCount);
  }
  lightingActive = (int)-(uint)lightingEnabled < 0;
  if (lightingActive) {
LAB_000f00e4:
    dVar19 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, vertexCount);
  }
  else {
    if (!texturingEnabled) goto LAB_000f0124;
    if (*(char *)(glContext + 0x53e6) != '\0') goto LAB_000f00e4;
  }
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e5) != '\0')) {
    dVar19 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, vertexCursor, vertexCount);
  }
LAB_000f0124:
  if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (texturingEnabled) {
      dVar19 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCount, 0);
    }
    if (faceTestNeeded == '\0') {
      if (lightingActive) {
        (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,vertexCount);
      }
      (**(code **)(glContext + 0x46d0))
                (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCount,
                 *(ushort *)(glContext + 0x34d0) - 0x1b00);
    }
    else {
      lastQuadStart = (vertexCursor + vertexCount * 0x100) - 0x400;
      do {
        facingChanged = false;
        iVar8 = 0;
        uVar15 = vertexCursor;
        uVar18 = vertexCursor;
        if (vertexCursor <= lastQuadStart) {
          do {
            cullResult = ((undefined4 (*)())_gleCullQuad)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x200,vertexCursor + 0x300,
                                  &backFacing,dVar19,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                  incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98);
            dVar19 = dVar19;
            if (cullResult == 0) {
              if (iVar11 != backFacing) {
                facingChanged = true;
              }
              if ((facingChanged) && (uVar18 = vertexCursor, 0 < iVar8)) break;
              iVar8 = iVar8 + 4;
              iVar11 = backFacing;
              uVar18 = uVar15;
            }
            else {
              uVar18 = vertexCursor + 0x400;
              if (0 < iVar8) break;
            }
            vertexCursor = vertexCursor + 0x400;
            uVar15 = uVar18;
            uVar18 = vertexCursor;
          } while (vertexCursor <= lastQuadStart);
          if (3 < iVar8) {
            if (twoSidedLighting) {
              pcVar10 = *(code **)(iVar11 * 4 + glContext + 0x4de8);
LAB_000f0264:
              (*pcVar10)(glContext,uVar15,iVar8);
            }
            else if (lightingActive) {
              pcVar10 = *(code **)(glContext + 0x4de8);
              goto LAB_000f0264;
            }
            if (iVar11 == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            dVar19 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46d0))
                                       (*(undefined4 *)(glContext + 0x4688), uVar15, iVar8, facePolygonMode - 0x1b00);
          }
        }
        vertexCursor = uVar18;
      } while (uVar18 <= lastQuadStart);
    }
  }
  else {
    if (texturingEnabled) {
      dVar19 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCount, 0);
    }
    polygonList = *(uint **)(glContext + 0x4870);
    spareList = *(uint **)(glContext + 0x4874);
    uVar18 = (vertexCursor + vertexCount * 0x100) - 0x400;
    if (vertexCursor <= uVar18) {
      do {
        polygonList[1] = vertexCursor + 0x100;
        polygonList[2] = vertexCursor + 0x200;
        polygonList[3] = vertexCursor + 0x300;
        *polygonList = vertexCursor;
        *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
        puVar13 = spareList;
        puVar7 = polygonList;
        iVar11 = 4;
        if ((*(char *)(glContext + 0x4e18) == '\0') ||
           (dVar19 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,clippedCount,dVar19,incomingFpr2,incomingFpr3
                                               ,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,
                                               incomingStack_ffffff90), puVar13 = polygonList,
           puVar7 = spareList, iVar11 = clippedCount[0], clippedCount[0] != 0)) {
          polygonList = puVar7;
          spareList = puVar13;
          if ((batchClipCodes & 0xff) != 0) {
            dVar19 = (double)_gleClipPoly(glContext,polygonList,iVar11,batchClipCodes & 0xff,puVar13,clippedCount,1);
            if (clippedCount[0] == 0) goto LAB_000f0440;
            if (0 < clippedCount[0]) {
              spareList = polygonList;
              polygonList = puVar13;
              iVar11 = clippedCount[0];
            }
          }
          if ((faceTestNeeded == '\0') ||
             (iVar8 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,iVar11,&backFacing),
             dVar19 = f1AfterCall2, iVar8 == 0)) {
            iVar8 = backFacing;
            if (twoSidedLighting) {
              pcVar10 = *(code **)(backFacing * 4 + glContext + 0x4df0);
LAB_000f0404:
              (*pcVar10)(glContext,polygonList,iVar11);
            }
            else if (lightingActive) {
              pcVar10 = *(code **)(glContext + 0x4df0);
              goto LAB_000f0404;
            }
            if (iVar8 == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            dVar19 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                       (*(undefined4 *)(glContext + 0x4688), polygonList, iVar11, facePolygonMode - 0x1b00);
          }
        }
LAB_000f0440:
        vertexCursor = vertexCursor + 0x400;
      } while (vertexCursor <= uVar18);
    }
  }
  return;
}

/* _gleRenderFlatQuadsFunc_body @ 0xf046c (1320 bytes) */
void _gleRenderFlatQuadsFunc_body(glContext)
  int glContext;
{
  bool lightingEnabled;
  bool bVar2;
  bool texturingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint batchClipCodes;
  int iVar9;
  int iVar10;
  uint *spareList;
  uint *puVar12;
  int iVar13;
  char lightingPending;
  uint uVar15;
  uint *polygonList;
  int iVar17;
  uint uVar18;
  uint uVar19;
  double f1AfterCall;
  double dVar20;
  double extraout_f1_00;
  double f1AfterCall2;
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
  int local_4c [6];
  
  iVar10 = -1;
  iVar7 = _gleTexEnableBits(glContext);
  lightingPending = *(char *)(glContext + 0x30aa);
  twoSidedLighting = false;
  lightingEnabled = lightingPending != '\0';
  if ((lightingEnabled) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  uVar18 = *(uint *)(glContext + 0x4854);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  iVar17 = (int)(*(int *)(glContext + 0x4858) - uVar18) >> 8;
  if ((3 < iVar17) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,uVar18,iVar17), (batchClipCodes & 0xff00) == 0)) {
    texturingEnabled = iVar7 != 0;
    dVar20 = f1AfterCall;
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
      dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, uVar18, iVar17);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, uVar18, iVar17);
    }
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e6) != '\0') {
        lightingPending = '\0';
        dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, uVar18, iVar17);
      }
      if (*(char *)(glContext + 0x53e5) != '\0') {
        dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, uVar18, iVar17);
      }
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (texturingEnabled) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, uVar18, iVar17, 0);
      }
      if (faceTestNeeded == '\0') {
        if (lightingEnabled) {
          iVar10 = 0;
          if (-1 < iVar17 + -4) {
            iVar7 = uVar18 + 0x300;
            do {
              if (lightingPending != '\0') {
                (**(code **)(glContext + 0x5068))(glContext,iVar7,1);
              }
              iVar10 = iVar10 + 4;
              (**(code **)(glContext + 0x4de8))(glContext,iVar7,1);
              iVar7 = iVar7 + 0x400;
            } while (iVar10 <= iVar17 + -4);
          }
        }
        (**(code **)(glContext + 0x46d0))
                  (*(undefined4 *)(glContext + 0x4688),uVar18,iVar17,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        uVar8 = (uVar18 + iVar17 * 0x100) - 0x400;
        do {
          iVar7 = 0;
          bVar2 = false;
          uVar15 = uVar18;
          uVar19 = uVar18;
          if (uVar18 <= uVar8) {
            do {
              iVar17 = ((undefined4 (*)())_gleCullQuad)(glContext,uVar18,uVar18 + 0x100,uVar18 + 0x200,uVar18 + 0x300,
                                    &backFacing,dVar20,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                    incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88);
              dVar20 = dVar20;
              if (iVar17 == 0) {
                if (iVar10 != backFacing) {
                  bVar2 = true;
                }
                if ((bVar2) && (uVar19 = uVar18, 0 < iVar7)) break;
                iVar7 = iVar7 + 4;
                iVar10 = backFacing;
                uVar19 = uVar15;
              }
              else {
                uVar19 = uVar18 + 0x400;
                if (0 < iVar7) break;
              }
              uVar18 = uVar18 + 0x400;
              uVar15 = uVar19;
              uVar19 = uVar18;
            } while (uVar18 <= uVar8);
            if (3 < iVar7) {
              if (lightingEnabled) {
                iVar17 = iVar10;
                if (!twoSidedLighting) {
                  iVar17 = 0;
                }
                iVar13 = 0;
                if (-1 < iVar7 + -4) {
                  iVar9 = uVar15 + 0x300;
                  do {
                    if (lightingPending != '\0') {
                      (**(code **)(glContext + 0x5068))(glContext,iVar9,1);
                    }
                    iVar13 = iVar13 + 4;
                    (**(code **)(iVar17 * 4 + glContext + 0x4de8))(glContext,iVar9,1);
                    iVar9 = iVar9 + 0x400;
                  } while (iVar13 <= iVar7 + -4);
                }
              }
              if (iVar10 == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46d0))
                                         (*(undefined4 *)(glContext + 0x4688), uVar15, iVar7, facePolygonMode - 0x1b00);
            }
          }
          uVar18 = uVar19;
        } while (uVar19 <= uVar8);
      }
    }
    else {
      if (texturingEnabled) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, uVar18, iVar17, 0);
      }
      polygonList = *(uint **)(glContext + 0x4870);
      iVar10 = uVar18 + iVar17 * 0x100;
      spareList = *(uint **)(glContext + 0x4874);
      for (; uVar18 <= iVar10 - 0x400U; uVar18 = uVar18 + 0x400) {
        uVar19 = uVar18 + 0x300;
        polygonList[1] = uVar18 + 0x100;
        polygonList[2] = uVar18 + 0x200;
        *polygonList = uVar18;
        polygonList[3] = uVar19;
        *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
        puVar12 = spareList;
        puVar6 = polygonList;
        iVar7 = 4;
        if ((*(char *)(glContext + 0x4e18) == '\0') ||
           (dVar20 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,local_4c,dVar20,incomingFpr2,incomingFpr3
                                               ,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                               incomingStack_ffffff80), puVar12 = polygonList,
           puVar6 = spareList, iVar7 = local_4c[0], local_4c[0] != 0)) {
          polygonList = puVar6;
          spareList = puVar12;
          if ((batchClipCodes & 0xff) != 0) {
            dVar20 = (double)_gleClipPoly(glContext,polygonList,iVar7,batchClipCodes & 0xff,puVar12,local_4c,1);
            if (local_4c[0] == 0) goto LAB_000f096c;
            if (0 < local_4c[0]) {
              spareList = polygonList;
              polygonList = puVar12;
              iVar7 = local_4c[0];
            }
          }
          if ((faceTestNeeded == '\0') ||
             (iVar17 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,iVar7,&backFacing),
             dVar20 = f1AfterCall2, iVar17 == 0)) {
            if (lightingPending != '\0') {
              (**(code **)(glContext + 0x5068))(glContext,uVar19,1);
            }
            if (lightingEnabled) {
              iVar17 = 0x4de0;
              if (twoSidedLighting) {
                iVar17 = backFacing * 4 + 0x4de0;
              }
              (**(code **)(glContext + iVar17 + 8))(glContext,uVar19,1);
            }
            *(undefined8 *)(*polygonList + 0x30) = *(undefined8 *)(uVar18 + 0x330);
            *(undefined8 *)(*polygonList + 0x38) = *(undefined8 *)(uVar18 + 0x338);
            if (backFacing == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                       (*(undefined4 *)(glContext + 0x4688), polygonList, iVar7, facePolygonMode - 0x1b00);
          }
        }
LAB_000f096c: ;
      }
    }
  }
  return;
}

/* _gleRenderSmoothQuadStripFunc_body @ 0xf09c0 (1256 bytes) */
void _gleRenderSmoothQuadStripFunc_body(glContext)
  int glContext;
{
  bool facingChanged;
  bool texturingEnabled;
  bool lightingActive;
  byte lightingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  int iVar7;
  uint lastQuadStart;
  uint batchClipCodes;
  int iVar9;
  uint *puVar10;
  code *pcVar11;
  int iVar12;
  uint *spareList;
  uint uVar14;
  uint vertexCursor;
  uint uVar16;
  uint *puVar17;
  uint *polygonList;
  int cullResult;
  int vertexCount;
  double f1AfterCall;
  double dVar20;
  double f1AfterCall1;
  double f1AfterCall2;
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
  int clippedCount [5];
  
  iVar12 = -1;
  iVar7 = _gleTexEnableBits(glContext);
  lightingEnabled = *(byte *)(glContext + 0x30aa);
  twoSidedLighting = false;
  if ((lightingEnabled != 0) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  vertexCursor = *(uint *)(glContext + 0x4854);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  vertexCount = (int)(*(int *)(glContext + 0x4858) - vertexCursor) >> 8;
  if (vertexCount < 4) {
    return;
  }
  batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount);
  if ((batchClipCodes & 0xff00) != 0) {
    return;
  }
  texturingEnabled = iVar7 != 0;
  dVar20 = f1AfterCall;
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
    dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, vertexCount);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCount);
  }
  lightingActive = (int)-(uint)lightingEnabled < 0;
  if (lightingActive) {
LAB_000f0ab8:
    dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, vertexCount);
  }
  else {
    if (!texturingEnabled) goto LAB_000f0af8;
    if (*(char *)(glContext + 0x53e6) != '\0') goto LAB_000f0ab8;
  }
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e5) != '\0')) {
    dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, vertexCursor, vertexCount);
  }
LAB_000f0af8:
  if (((batchClipCodes & 0xff) != 0) || (*(char *)(glContext + 0x4e18) != '\0')) {
    if (texturingEnabled) {
      dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCount, 0);
    }
    facingChanged = false;
    uVar16 = vertexCursor;
    spareList = *(uint **)(glContext + 0x4874);
    polygonList = *(uint **)(glContext + 0x4870);
joined_r0x000f0cf4:
    do {
      if ((vertexCursor + vertexCount * 0x100) - 0x400 < uVar16) {
        return;
      }
      uVar14 = uVar16 + 0x200;
      *polygonList = uVar16;
      polygonList[1] = uVar16 + 0x100;
      polygonList[2] = uVar16 + 0x300;
      polygonList[3] = uVar14;
      *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
      puVar10 = spareList;
      puVar17 = polygonList;
      iVar7 = 4;
      uVar16 = uVar14;
    } while ((*(char *)(glContext + 0x4e18) != '\0') &&
            (dVar20 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,clippedCount,dVar20,incomingFpr2,
                                                incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                incomingStack_ffffff78,incomingStack_ffffff80),
            puVar10 = polygonList, puVar17 = spareList, iVar7 = clippedCount[0], clippedCount[0] == 0));
    spareList = puVar10;
    polygonList = puVar17;
    if ((batchClipCodes & 0xff) != 0) goto code_r0x000f0d68;
    goto LAB_000f0da8;
  }
  if (texturingEnabled) {
    dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCount, 0);
  }
  if (faceTestNeeded == '\0') {
    if (lightingActive) {
      (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,vertexCount);
    }
    (**(code **)(glContext + 0x46d4))
              (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCount,
               *(ushort *)(glContext + 0x34d0) - 0x1b00);
  }
  else {
    lastQuadStart = (vertexCursor + vertexCount * 0x100) - 0x400;
    do {
      facingChanged = false;
      iVar7 = 0;
      uVar16 = vertexCursor;
      do {
        while( true ) {
          uVar14 = uVar16;
          if (lastQuadStart < vertexCursor) goto LAB_000f0c0c;
          uVar16 = vertexCursor + 0x200;
          cullResult = ((undefined4 (*)())_gleCullQuad)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x300,uVar16,&backFacing,dVar20
                                ,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                incomingStack_ffffff80,incomingStack_ffffff88);
          dVar20 = f1AfterCall1;
          if (cullResult != 0) break;
          if (iVar12 != backFacing) {
            facingChanged = true;
          }
          if ((facingChanged) && (0 < iVar7)) goto LAB_000f0c0c;
          iVar7 = iVar7 + 2;
          iVar12 = backFacing;
          vertexCursor = uVar16;
          uVar16 = uVar14;
        }
        vertexCursor = uVar16;
      } while (iVar7 < 1);
LAB_000f0c0c:
      iVar7 = iVar7 + 2;
      if (3 < iVar7) {
        if (twoSidedLighting) {
          if (facingChanged) {
            uVar16 = uVar14;
            do {
              *(byte *)(uVar16 + 0x7e) = *(byte *)(uVar16 + 0x7e) | 6;
              uVar16 = uVar16 + 0x100;
            } while ((int)uVar16 <= (int)(uVar14 + 0x100));
          }
          pcVar11 = *(code **)(iVar12 * 4 + glContext + 0x4de8);
LAB_000f0c6c:
          (*pcVar11)(glContext,uVar14,iVar7);
        }
        else if (lightingActive) {
          pcVar11 = *(code **)(glContext + 0x4de8);
          goto LAB_000f0c6c;
        }
        if (iVar12 == 0) {
          facePolygonMode = *(ushort *)(glContext + 0x34d0);
        }
        else {
          facePolygonMode = *(ushort *)(glContext + 0x34d2);
        }
        dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46d4))
                                   (*(undefined4 *)(glContext + 0x4688), uVar14, iVar7, facePolygonMode - 0x1b00);
      }
    } while (vertexCursor <= lastQuadStart);
  }
  return;
code_r0x000f0d68:
  dVar20 = (double)_gleClipPoly(glContext,puVar17,iVar7,batchClipCodes & 0xff,puVar10,clippedCount,1);
  if (clippedCount[0] == 0) goto joined_r0x000f0cf4;
  if (0 < clippedCount[0]) {
    spareList = puVar17;
    polygonList = puVar10;
    iVar7 = clippedCount[0];
  }
LAB_000f0da8:
  if ((faceTestNeeded != '\0') &&
     (iVar9 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,iVar7,&backFacing), dVar20 = f1AfterCall2,
     iVar9 != 0)) goto joined_r0x000f0cf4;
  iVar9 = backFacing;
  if (iVar12 != backFacing) {
    facingChanged = true;
  }
  if (twoSidedLighting) {
    if (facingChanged) {
      puVar10 = polygonList;
      iVar12 = iVar7;
      if (0 < iVar7) {
        do {
          *(byte *)(*puVar10 + 0x7e) = *(byte *)(*puVar10 + 0x7e) | 6;
          iVar12 = iVar12 + -1;
          puVar10 = puVar10 + 1;
        } while (iVar12 != 0);
      }
      facingChanged = false;
    }
    pcVar11 = *(code **)(backFacing * 4 + glContext + 0x4df0);
  }
  else {
    if (!lightingActive) goto LAB_000f0e50;
    pcVar11 = *(code **)(glContext + 0x4df0);
  }
  (*pcVar11)(glContext,polygonList,iVar7);
LAB_000f0e50:
  if (iVar9 == 0) {
    facePolygonMode = *(ushort *)(glContext + 0x34d0);
  }
  else {
    facePolygonMode = *(ushort *)(glContext + 0x34d2);
  }
  dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                             (*(undefined4 *)(glContext + 0x4688), polygonList, iVar7, facePolygonMode - 0x1b00);
  iVar12 = iVar9;
  goto joined_r0x000f0cf4;
}

/* _gleRenderFlatQuadStripFunc_body @ 0xf0eac (1336 bytes) */
void _gleRenderFlatQuadStripFunc_body(glContext)
  int glContext;
{
  bool lightingEnabled;
  bool bVar2;
  bool texturingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint batchClipCodes;
  int iVar9;
  int iVar10;
  int polygonVertexCount;
  uint *puVar11;
  uint *spareList;
  char lightingPending;
  int iVar14;
  uint uVar15;
  uint vertexCursor;
  uint uVar17;
  uint *puVar18;
  uint *polygonList;
  int iVar20;
  int vertexCount;
  double f1AfterCall;
  double dVar21;
  double f1AfterCall1;
  double f1AfterCall2;
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
  int local_4c [5];
  
  iVar10 = -1;
  iVar7 = _gleTexEnableBits(glContext);
  lightingPending = *(char *)(glContext + 0x30aa);
  twoSidedLighting = false;
  lightingEnabled = lightingPending != '\0';
  if ((lightingEnabled) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  vertexCursor = *(uint *)(glContext + 0x4854);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  vertexCount = (int)(*(int *)(glContext + 0x4858) - vertexCursor) >> 8;
  if ((3 < vertexCount) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount), (batchClipCodes & 0xff00) == 0)) {
    texturingEnabled = iVar7 != 0;
    dVar21 = f1AfterCall;
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
      dVar21 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, vertexCount);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      dVar21 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCount);
    }
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e6) != '\0') {
        lightingPending = '\0';
        dVar21 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, vertexCount);
      }
      if (*(char *)(glContext + 0x53e5) != '\0') {
        dVar21 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, vertexCursor, vertexCount);
      }
    }
    if (((batchClipCodes & 0xff) != 0) || (*(char *)(glContext + 0x4e18) != '\0')) {
      if (texturingEnabled) {
        dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCount, 0);
      }
      uVar17 = vertexCursor;
      spareList = *(uint **)(glContext + 0x4874);
      polygonList = *(uint **)(glContext + 0x4870);
joined_r0x000f1240:
      do {
        uVar6 = uVar17;
        if ((vertexCursor + vertexCount * 0x100) - 0x400 < uVar6) {
          return;
        }
        uVar17 = uVar6 + 0x200;
        uVar15 = uVar6 + 0x300;
        *polygonList = uVar6;
        polygonList[1] = uVar6 + 0x100;
        polygonList[2] = uVar15;
        polygonList[3] = uVar17;
        *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
        puVar11 = spareList;
        puVar18 = polygonList;
        iVar10 = 4;
      } while ((*(char *)(glContext + 0x4e18) != '\0') &&
              (dVar21 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,local_4c,dVar21,incomingFpr2,
                                                  incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                  incomingStack_ffffff78,incomingStack_ffffff80),
              puVar11 = polygonList, puVar18 = spareList, polygonVertexCount = local_4c[0], local_4c[0] == 0));
      spareList = puVar11;
      polygonList = puVar18;
      if ((batchClipCodes & 0xff) != 0) goto code_r0x000f12b4;
      goto LAB_000f12f4;
    }
    if (texturingEnabled) {
      dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCount, 0);
    }
    if (faceTestNeeded == '\0') {
      if (lightingEnabled) {
        iVar10 = 0;
        if (-1 < vertexCount + -4) {
          iVar7 = vertexCursor + 0x300;
          do {
            if (lightingPending != '\0') {
              (**(code **)(glContext + 0x5068))(glContext,iVar7,1);
            }
            iVar10 = iVar10 + 2;
            (**(code **)(glContext + 0x4de8))(glContext,iVar7,1);
            iVar7 = iVar7 + 0x200;
          } while (iVar10 <= vertexCount + -4);
        }
      }
      (**(code **)(glContext + 0x46d4))
                (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCount,
                 *(ushort *)(glContext + 0x34d0) - 0x1b00);
    }
    else {
      uVar8 = (vertexCursor + vertexCount * 0x100) - 0x400;
      do {
        iVar7 = 0;
        bVar2 = false;
        uVar17 = vertexCursor;
        do {
          while( true ) {
            uVar6 = uVar17;
            if (uVar8 < vertexCursor) goto LAB_000f1138;
            uVar17 = vertexCursor + 0x200;
            iVar20 = ((undefined4 (*)())_gleCullQuad)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x300,uVar17,&backFacing,
                                  dVar21,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78
                                  ,incomingStack_ffffff80,incomingStack_ffffff88);
            dVar21 = f1AfterCall1;
            if (iVar20 != 0) break;
            if (iVar10 != backFacing) {
              bVar2 = true;
            }
            if ((bVar2) && (0 < iVar7)) goto LAB_000f1138;
            iVar7 = iVar7 + 2;
            iVar10 = backFacing;
            vertexCursor = uVar17;
            uVar17 = uVar6;
          }
          vertexCursor = uVar17;
        } while (iVar7 < 1);
LAB_000f1138:
        if (3 < iVar7 + 2) {
          if (lightingEnabled) {
            iVar20 = iVar10;
            if (!twoSidedLighting) {
              iVar20 = 0;
            }
            iVar14 = 0;
            if (-1 < iVar7 + -2) {
              iVar9 = uVar6 + 0x300;
              do {
                if (lightingPending != '\0') {
                  (**(code **)(glContext + 0x5068))(glContext,iVar9,1);
                }
                iVar14 = iVar14 + 2;
                (**(code **)(iVar20 * 4 + glContext + 0x4de8))(glContext,iVar9,1);
                iVar9 = iVar9 + 0x200;
              } while (iVar14 <= iVar7 + -2);
            }
          }
          if (iVar10 == 0) {
            facePolygonMode = *(ushort *)(glContext + 0x34d0);
          }
          else {
            facePolygonMode = *(ushort *)(glContext + 0x34d2);
          }
          dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46d4))
                                     (*(undefined4 *)(glContext + 0x4688), uVar6, iVar7 + 2, facePolygonMode - 0x1b00);
        }
      } while (vertexCursor <= uVar8);
    }
  }
  return;
code_r0x000f12b4:
  dVar21 = (double)_gleClipPoly(glContext,puVar18,polygonVertexCount,batchClipCodes & 0xff,puVar11,local_4c,1);
  if (local_4c[0] != 0) {
    if (0 < local_4c[0]) {
      spareList = puVar18;
      polygonList = puVar11;
      polygonVertexCount = local_4c[0];
    }
LAB_000f12f4:
    if ((faceTestNeeded == '\0') ||
       (iVar7 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing), dVar21 = f1AfterCall2,
       iVar7 == 0)) {
      if (lightingPending != '\0') {
        (**(code **)(glContext + 0x5068))(glContext,uVar15,1);
      }
      if (lightingEnabled) {
        iVar7 = 0x4de0;
        if (twoSidedLighting) {
          iVar7 = backFacing * 4 + 0x4de0;
        }
        (**(code **)(glContext + iVar7 + 8))(glContext,uVar15,1);
      }
      *(undefined8 *)(*polygonList + 0x30) = *(undefined8 *)(uVar6 + 0x330);
      *(undefined8 *)(*polygonList + 0x38) = *(undefined8 *)(uVar6 + 0x338);
      if (backFacing == 0) {
        facePolygonMode = *(ushort *)(glContext + 0x34d0);
      }
      else {
        facePolygonMode = *(ushort *)(glContext + 0x34d2);
      }
      dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                 (*(undefined4 *)(glContext + 0x4688), polygonList, polygonVertexCount, facePolygonMode - 0x1b00);
    }
  }
  goto joined_r0x000f1240;
}

/* _gleSelectPolygonFunc_body @ 0xf13e8 (664 bytes) */
void _gleSelectPolygonFunc_body(glContext)
  int glContext;
{
  char cullFaceEnabled;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  uint uVar5;
  uint batchClipCodes;
  int iVar6;
  undefined4 uVar7;
  int *spareList;
  int *polygonList;
  uint uVar10;
  int iVar11;
  uint uVar12;
  double f1AfterCall;
  double dVar13;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  uint local_40;
  undefined4 local_3c [5];
  
  bVar2 = false;
  local_3c[0] = 0;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    bVar2 = true;
  }
  bVar3 = false;
  if ((bVar2) && (*(char *)(glContext + 0x4666) != '\0')) {
    bVar3 = true;
  }
  cullFaceEnabled = *(char *)(glContext + 0x34da);
  iVar11 = *(int *)(glContext + 0x4854);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (uVar10 = (uint)(*(int *)(glContext + 0x4858) - iVar11) /
                (uint)(int)*(short *)(glContext + 0x487c), 2 < (int)uVar10)) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,iVar11,uVar10), (batchClipCodes & 0xff00) == 0)) {
    dVar13 = f1AfterCall;
    if (bVar2) {
      iVar11 = *(int *)(glContext + 0x4864);
    }
    else if (*(char *)(glContext + 0x4e18) != '\0') {
      dVar13 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, iVar11, uVar10);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if ((cullFaceEnabled == '\0') ||
         (iVar6 = ((int (*)())_gleCullPolygonStack)(glContext,iVar11,uVar10,0,local_3c), iVar6 == 0)) {
        if ((bVar2) && (bVar3)) {
          _gleVPFlipColors(glContext,iVar11,uVar10,local_3c[0]);
        }
        _gleSelectPolygon(glContext,iVar11,uVar10);
      }
    }
    else {
      polygonList = *(int **)(glContext + 0x4870);
      spareList = *(int **)(glContext + 0x4874);
      piVar4 = polygonList;
      uVar12 = uVar10;
      if (0 < (int)uVar10) {
        do {
          *piVar4 = iVar11;
          iVar11 = iVar11 + 0x100;
          uVar12 = uVar12 - 1;
          piVar4 = piVar4 + 1;
        } while (uVar12 != 0);
      }
      if (bVar2) {
        *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
      }
      uVar7 = 0;
      piVar4 = spareList;
      if (*(char *)(glContext + 0x4e18) != '\0') {
        ((double (*)())_gleClipPolyPlane)(glContext,polygonList,uVar10,spareList,&local_40,dVar13,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
                          incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90);
        if (local_40 == 0) {
          return;
        }
        uVar7 = 1;
        piVar4 = polygonList;
        polygonList = spareList;
        uVar10 = local_40;
      }
      if ((batchClipCodes & 0xff) != 0) {
        _gleClipPoly(glContext,polygonList,uVar10,batchClipCodes & 0xff,piVar4,&local_40,uVar7);
        if (local_40 == 0) {
          return;
        }
        if (0 < (int)local_40) {
          polygonList = piVar4;
          uVar10 = local_40;
        }
      }
      if ((cullFaceEnabled == '\0') ||
         (iVar11 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,uVar10,local_3c), iVar11 == 0)) {
        if ((bVar2) && ((bVar3 && (piVar4 = polygonList, uVar5 = uVar10, 0 < (int)uVar10)))) {
          do {
            iVar11 = *piVar4;
            piVar4 = piVar4 + 1;
            _gleVPFlipColors(glContext,iVar11,1,local_3c[0]);
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
        }
        _gleSelectPolygonPtr(glContext,polygonList,uVar10);
      }
    }
  }
  return;
}

/* _gleSelectTrianglesFunc_body @ 0xf1684 (848 bytes) */
void _gleSelectTrianglesFunc_body(glContext)
  int glContext;
{
  char cullFaceEnabled;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint batchClipCodes;
  int iVar8;
  int iVar9;
  int polygonVertexCount;
  uint *spareList;
  uint *puVar11;
  uint *polygonList;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint vertexCursor;
  int iVar17;
  double f1AfterCall;
  double dVar18;
  double extraout_f1_00;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  int backFacing;
  int local_4c [6];
  
  iVar9 = -1;
  bVar2 = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    bVar2 = true;
  }
  bVar2 = !bVar2;
  bVar4 = false;
  if ((!bVar2) && (*(char *)(glContext + 0x4666) != '\0')) {
    bVar4 = true;
  }
  cullFaceEnabled = *(char *)(glContext + 0x34da);
  vertexCursor = *(uint *)(glContext + 0x4854);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (uVar13 = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
      2 < (int)uVar13)) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,uVar13), (batchClipCodes & 0xff00) == 0)) {
    dVar18 = f1AfterCall;
    if (bVar2) {
      if (*(char *)(glContext + 0x4e18) != '\0') {
        dVar18 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, uVar13);
      }
    }
    else {
      vertexCursor = *(uint *)(glContext + 0x4864);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (cullFaceEnabled == '\0') {
        _gleSelectTriangles(glContext,vertexCursor,uVar13);
      }
      else {
        uVar13 = (vertexCursor + uVar13 * 0x100) - 0x300;
        do {
          bVar3 = false;
          iVar17 = 0;
          uVar7 = vertexCursor;
          uVar15 = vertexCursor;
          if (vertexCursor <= uVar13) {
            do {
              iVar8 = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x200,0,&backFacing,
                                       dVar18,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                       incomingStack_ffffff78,incomingStack_ffffff80);
              dVar18 = dVar18;
              if (iVar8 == 0) {
                if (iVar9 != backFacing) {
                  bVar3 = true;
                }
                if ((bVar3) && (uVar7 = vertexCursor, 0 < iVar17)) break;
                iVar17 = iVar17 + 3;
                iVar9 = backFacing;
                uVar14 = uVar15;
              }
              else {
                uVar14 = vertexCursor + 0x300;
                uVar7 = uVar14;
                if (0 < iVar17) break;
              }
              vertexCursor = vertexCursor + 0x300;
              uVar7 = vertexCursor;
              uVar15 = uVar14;
            } while (vertexCursor <= uVar13);
            if (2 < iVar17) {
              if ((!bVar2) && (bVar4)) {
                _gleVPFlipColors(glContext,uVar15,iVar17,iVar9);
              }
              dVar18 = (double)_gleSelectTriangles(glContext,uVar15,iVar17);
            }
          }
          vertexCursor = uVar7;
        } while (uVar7 <= uVar13);
      }
    }
    else {
      polygonList = *(uint **)(glContext + 0x4870);
      uVar13 = (vertexCursor + uVar13 * 0x100) - 0x300;
      spareList = *(uint **)(glContext + 0x4874);
      if (vertexCursor <= uVar13) {
        do {
          polygonList[1] = vertexCursor + 0x100;
          polygonList[2] = vertexCursor + 0x200;
          *polygonList = vertexCursor;
          if (bVar2) {
            uVar6 = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            uVar6 = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = uVar6;
          puVar11 = spareList;
          puVar5 = polygonList;
          iVar9 = 3;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar18 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,local_4c,dVar18,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             puVar11 = polygonList, puVar5 = spareList, polygonVertexCount = local_4c[0], local_4c[0] != 0)) {
            polygonList = puVar5;
            spareList = puVar11;
            if ((batchClipCodes & 0xff) != 0) {
              dVar18 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,puVar11,local_4c,1);
              if (local_4c[0] == 0) goto LAB_000f19ac;
              if (0 < local_4c[0]) {
                spareList = polygonList;
                polygonList = puVar11;
                polygonVertexCount = local_4c[0];
              }
            }
            if ((cullFaceEnabled == '\0') ||
               (iVar17 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing),
               dVar18 = f1AfterCall2, iVar17 == 0)) {
              iVar17 = backFacing;
              if ((!bVar2) && ((bVar4 && (puVar11 = polygonList, iVar8 = polygonVertexCount, 0 < polygonVertexCount)))) {
                do {
                  _gleVPFlipColors(glContext,*puVar11,1,iVar17);
                  iVar8 = iVar8 + -1;
                  puVar11 = puVar11 + 1;
                } while (iVar8 != 0);
              }
              dVar18 = (double)_gleSelectPolygonPtr(glContext,polygonList,polygonVertexCount);
            }
          }
LAB_000f19ac:
          vertexCursor = vertexCursor + 0x300;
        } while (vertexCursor <= uVar13);
      }
    }
  }
  return;
}

/* _gleSelectTriangleStripFunc_body @ 0xf19d8 (996 bytes) */
void _gleSelectTriangleStripFunc_body(glContext)
  int glContext;
{
  char cullFaceEnabled;
  bool noVertexProgram;
  bool bVar3;
  bool windingFlip;
  bool vertexProgramTwoSide;
  uint runStart;
  uint *puVar6;
  undefined4 batchEndReset;
  uint uVar8;
  uint batchClipCodes;
  int iVar9;
  int iVar10;
  int polygonVertexCount;
  uint uVar11;
  uint *spareList;
  uint *puVar13;
  int *triangleVertexList;
  uint newRunStart;
  uint uVar16;
  uint vertexCount;
  int iVar17;
  uint *polygonVertexList;
  uint nextVertex;
  uint uVar20;
  uint vertexCursor;
  double f1AfterCall;
  double dVar22;
  double f1AfterCall1;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  int backFacing;
  int clippedCount [5];
  
  iVar10 = -1;
  noVertexProgram = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    noVertexProgram = true;
  }
  noVertexProgram = !noVertexProgram;
  vertexProgramTwoSide = false;
  if ((!noVertexProgram) && (*(char *)(glContext + 0x4666) != '\0')) {
    vertexProgramTwoSide = true;
  }
  uVar11 = 0;
  cullFaceEnabled = *(char *)(glContext + 0x34da);
  vertexCursor = *(uint *)(glContext + 0x4854);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (vertexCount = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
      2 < (int)vertexCount)) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount), (batchClipCodes & 0xff00) == 0)) {
    dVar22 = f1AfterCall;
    if (noVertexProgram) {
      if (*(char *)(glContext + 0x4e18) != '\0') {
        dVar22 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCount);
      }
    }
    else {
      vertexCursor = *(uint *)(glContext + 0x4864);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (cullFaceEnabled == '\0') {
        _gleSelectTriangleStrip(glContext,vertexCursor,vertexCount);
      }
      else {
        triangleVertexList = *(int **)(glContext + 0x4870);
        uVar8 = (vertexCursor + vertexCount * 0x100) - 0x300;
        uVar16 = 0;
        do {
          bVar3 = false;
          iVar17 = 0;
          uVar20 = uVar16;
          runStart = vertexCursor;
          while (uVar16 = uVar20, vertexCursor <= uVar8) {
            nextVertex = vertexCursor + 0x100;
            iVar9 = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,nextVertex,vertexCursor + 0x200,uVar20,&backFacing,dVar22,
                                     incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                     incomingStack_ffffff80);
            dVar22 = f1AfterCall1;
            if (iVar9 == 0) {
              if (iVar10 != backFacing) {
                bVar3 = true;
              }
              if ((bVar3) && (0 < iVar17)) break;
              if (iVar17 == 0) {
                uVar11 = uVar20;
              }
              iVar17 = iVar17 + 1;
              iVar10 = backFacing;
              newRunStart = runStart;
            }
            else {
              newRunStart = nextVertex;
              uVar16 = uVar20 ^ 1;
              vertexCursor = nextVertex;
              if (0 < iVar17) break;
            }
            uVar20 = uVar20 ^ 1;
            vertexCursor = nextVertex;
            runStart = newRunStart;
          }
          iVar9 = iVar17 + 2;
          if (2 < iVar9) {
            if ((!noVertexProgram) && (vertexProgramTwoSide)) {
              _gleVPFlipColors(glContext,runStart,iVar9,iVar10);
            }
            uVar20 = runStart;
            if (uVar11 != 0) {
              uVar20 = runStart + 0x100;
              triangleVertexList[2] = runStart;
              iVar9 = iVar17 + 1;
              *triangleVertexList = runStart + 0x200;
              triangleVertexList[1] = uVar20;
              dVar22 = (double)_gleSelectPolygonPtr(glContext,triangleVertexList,3);
              if (iVar9 < 3) goto LAB_000f1c00;
            }
            dVar22 = (double)_gleSelectTriangleStrip(glContext,uVar20,iVar9);
          }
LAB_000f1c00: ;
        } while (vertexCursor <= uVar8);
      }
    }
    else {
      polygonVertexList = *(uint **)(glContext + 0x4870);
      uVar11 = (vertexCursor + vertexCount * 0x100) - 0x300;
      spareList = *(uint **)(glContext + 0x4874);
      if (vertexCursor <= uVar11) {
        windingFlip = false;
        do {
          windingFlip = !windingFlip;
          if (windingFlip) {
            polygonVertexList[2] = vertexCursor + 0x200;
            *polygonVertexList = vertexCursor;
          }
          else {
            *polygonVertexList = vertexCursor + 0x200;
            polygonVertexList[2] = vertexCursor;
          }
          vertexCursor = vertexCursor + 0x100;
          polygonVertexList[1] = vertexCursor;
          if (noVertexProgram) {
            batchEndReset = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            batchEndReset = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = batchEndReset;
          puVar13 = spareList;
          iVar10 = 3;
          puVar6 = polygonVertexList;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar22 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonVertexList,3,spareList,clippedCount,dVar22,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             puVar13 = polygonVertexList, polygonVertexCount = clippedCount[0], puVar6 = spareList, clippedCount[0] != 0)) {
            polygonVertexList = puVar6;
            spareList = puVar13;
            if ((batchClipCodes & 0xff) != 0) {
              dVar22 = (double)_gleClipPoly(glContext,polygonVertexList,polygonVertexCount,batchClipCodes & 0xff,puVar13,clippedCount,1);
              if (clippedCount[0] == 0) goto LAB_000f1d94;
              if (0 < clippedCount[0]) {
                spareList = polygonVertexList;
                polygonVertexCount = clippedCount[0];
                polygonVertexList = puVar13;
              }
            }
            if ((cullFaceEnabled == '\0') ||
               (iVar17 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonVertexList,polygonVertexCount,&backFacing),
               dVar22 = f1AfterCall2, iVar17 == 0)) {
              iVar17 = backFacing;
              if ((!noVertexProgram) && ((vertexProgramTwoSide && (iVar9 = polygonVertexCount, puVar13 = polygonVertexList, 0 < polygonVertexCount)))) {
                do {
                  _gleVPFlipColors(glContext,*puVar13,1,iVar17);
                  iVar9 = iVar9 + -1;
                  puVar13 = puVar13 + 1;
                } while (iVar9 != 0);
              }
              dVar22 = (double)_gleSelectPolygonPtr(glContext,polygonVertexList,polygonVertexCount);
            }
          }
LAB_000f1d94: ;
        } while (vertexCursor <= uVar11);
      }
    }
  }
  return;
}

/* _gleSelectTriangleFanFunc_body @ 0xf1dc0 (860 bytes) */
void _gleSelectTriangleFanFunc_body(glContext)
  int glContext;
{
  char cullFaceEnabled;
  bool noVertexProgram;
  bool facingChanged;
  bool vertexProgramTwoSide;
  int *piVar5;
  undefined4 batchEndReset;
  uint uVar7;
  uint batchClipCodes;
  int iVar8;
  int iVar9;
  int polygonVertexCount;
  int *spareList;
  int *piVar11;
  uint uVar12;
  int vertexCursor;
  int *polygonList;
  uint uVar15;
  int iVar16;
  uint uVar17;
  double f1AfterCall;
  double dVar18;
  double f1AfterCall1;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  int backFacing;
  int local_4c [5];
  
  iVar9 = -1;
  noVertexProgram = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    noVertexProgram = true;
  }
  noVertexProgram = !noVertexProgram;
  vertexProgramTwoSide = false;
  if ((!noVertexProgram) && (*(char *)(glContext + 0x4666) != '\0')) {
    vertexProgramTwoSide = true;
  }
  cullFaceEnabled = *(char *)(glContext + 0x34da);
  vertexCursor = *(int *)(glContext + 0x4854);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (uVar15 = (uint)(*(int *)(glContext + 0x4858) - vertexCursor) /
                (uint)(int)*(short *)(glContext + 0x487c), 2 < (int)uVar15)) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,uVar15), (batchClipCodes & 0xff00) == 0)) {
    dVar18 = f1AfterCall;
    if (noVertexProgram) {
      if (*(char *)(glContext + 0x4e18) != '\0') {
        dVar18 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, uVar15);
      }
    }
    else {
      vertexCursor = *(int *)(glContext + 0x4864);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (cullFaceEnabled == '\0') {
        _gleSelectTriangleFan(glContext,vertexCursor,vertexCursor + 0x100,uVar15 - 1);
      }
      else {
        uVar7 = vertexCursor + 0x100;
        uVar15 = (vertexCursor + uVar15 * 0x100) - 0x200;
        do {
          facingChanged = false;
          iVar16 = 0;
          uVar17 = uVar7;
          do {
            while( true ) {
              uVar12 = uVar17;
              if (uVar15 < uVar7) goto LAB_000f1f60;
              uVar17 = uVar7 + 0x100;
              iVar8 = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,uVar7,uVar17,0,&backFacing,dVar18,incomingFpr2,incomingFpr3,
                                       incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                       incomingStack_ffffff80);
              dVar18 = f1AfterCall1;
              if (iVar8 != 0) break;
              if (iVar9 != backFacing) {
                facingChanged = true;
              }
              if ((facingChanged) && (0 < iVar16)) goto LAB_000f1f60;
              iVar16 = iVar16 + 1;
              iVar9 = backFacing;
              uVar7 = uVar17;
              uVar17 = uVar12;
            }
            uVar7 = uVar17;
          } while (iVar16 < 1);
LAB_000f1f60:
          iVar16 = iVar16 + 1;
          if (1 < iVar16) {
            if ((!noVertexProgram) && (vertexProgramTwoSide)) {
              _gleVPFlipColors(glContext,uVar12,iVar16,iVar9);
            }
            dVar18 = (double)_gleSelectTriangleFan(glContext,vertexCursor,uVar12,iVar16);
          }
        } while (uVar7 <= uVar15);
      }
    }
    else {
      polygonList = *(int **)(glContext + 0x4870);
      uVar15 = (vertexCursor + uVar15 * 0x100) - 0x200;
      spareList = *(int **)(glContext + 0x4874);
      if (vertexCursor + 0x100U <= uVar15) {
        uVar17 = vertexCursor + 0x100U;
        do {
          uVar12 = uVar17 + 0x100;
          *polygonList = vertexCursor;
          polygonList[1] = uVar17;
          polygonList[2] = uVar12;
          if (noVertexProgram) {
            batchEndReset = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            batchEndReset = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = batchEndReset;
          piVar11 = spareList;
          piVar5 = polygonList;
          iVar9 = 3;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar18 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,local_4c,dVar18,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             piVar11 = polygonList, piVar5 = spareList, polygonVertexCount = local_4c[0], local_4c[0] != 0)) {
            polygonList = piVar5;
            spareList = piVar11;
            if ((batchClipCodes & 0xff) != 0) {
              dVar18 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,piVar11,local_4c,1);
              if (local_4c[0] == 0) goto LAB_000f20f4;
              if (0 < local_4c[0]) {
                spareList = polygonList;
                polygonList = piVar11;
                polygonVertexCount = local_4c[0];
              }
            }
            if ((cullFaceEnabled == '\0') ||
               (iVar16 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing),
               dVar18 = f1AfterCall2, iVar16 == 0)) {
              iVar16 = backFacing;
              if ((!noVertexProgram) && ((vertexProgramTwoSide && (piVar11 = polygonList, iVar8 = polygonVertexCount, 0 < polygonVertexCount)))) {
                do {
                  _gleVPFlipColors(glContext,*piVar11,1,iVar16);
                  iVar8 = iVar8 + -1;
                  piVar11 = piVar11 + 1;
                } while (iVar8 != 0);
              }
              dVar18 = (double)_gleSelectPolygonPtr(glContext,polygonList,polygonVertexCount);
            }
          }
LAB_000f20f4:
          uVar17 = uVar12;
        } while (uVar12 <= uVar15);
      }
    }
  }
  return;
}

/* _gleSelectQuadsFunc_body @ 0xf2120 (856 bytes) */
void _gleSelectQuadsFunc_body(glContext)
  int glContext;
{
  char cullFaceEnabled;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint batchClipCodes;
  int iVar8;
  int iVar9;
  int polygonVertexCount;
  uint *spareList;
  uint *puVar11;
  uint uVar12;
  uint *polygonList;
  uint uVar14;
  uint vertexCursor;
  int iVar16;
  double f1AfterCall;
  double dVar17;
  double extraout_f1_00;
  double f1AfterCall2;
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
  int local_4c [6];
  
  iVar9 = -1;
  bVar2 = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    bVar2 = true;
  }
  bVar2 = !bVar2;
  bVar4 = false;
  if ((!bVar2) && (*(char *)(glContext + 0x4666) != '\0')) {
    bVar4 = true;
  }
  cullFaceEnabled = *(char *)(glContext + 0x34da);
  vertexCursor = *(uint *)(glContext + 0x4854);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (uVar12 = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
      3 < (int)uVar12)) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,uVar12), (batchClipCodes & 0xff00) == 0)) {
    dVar17 = f1AfterCall;
    if (bVar2) {
      if (*(char *)(glContext + 0x4e18) != '\0') {
        dVar17 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, uVar12);
      }
    }
    else {
      vertexCursor = *(uint *)(glContext + 0x4864);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (cullFaceEnabled == '\0') {
        _gleSelectQuads(glContext,vertexCursor,uVar12);
      }
      else {
        uVar12 = (vertexCursor + uVar12 * 0x100) - 0x400;
        do {
          bVar3 = false;
          iVar16 = 0;
          uVar14 = vertexCursor;
          uVar7 = vertexCursor;
          if (vertexCursor <= uVar12) {
            do {
              iVar8 = ((undefined4 (*)())_gleCullQuad)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x200,vertexCursor + 0x300,
                                   &backFacing,dVar17,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                   incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88);
              dVar17 = dVar17;
              if (iVar8 == 0) {
                if (iVar9 != backFacing) {
                  bVar3 = true;
                }
                if ((bVar3) && (uVar7 = vertexCursor, 0 < iVar16)) break;
                iVar16 = iVar16 + 4;
                iVar9 = backFacing;
                uVar7 = uVar14;
              }
              else {
                uVar7 = vertexCursor + 0x400;
                if (0 < iVar16) break;
              }
              vertexCursor = vertexCursor + 0x400;
              uVar14 = uVar7;
              uVar7 = vertexCursor;
            } while (vertexCursor <= uVar12);
            if (3 < iVar16) {
              if ((!bVar2) && (bVar4)) {
                _gleVPFlipColors(glContext,uVar14,iVar16,iVar9);
              }
              dVar17 = (double)_gleSelectQuads(glContext,uVar14,iVar16);
            }
          }
          vertexCursor = uVar7;
        } while (uVar7 <= uVar12);
      }
    }
    else {
      polygonList = *(uint **)(glContext + 0x4870);
      uVar12 = (vertexCursor + uVar12 * 0x100) - 0x400;
      spareList = *(uint **)(glContext + 0x4874);
      if (vertexCursor <= uVar12) {
        do {
          polygonList[1] = vertexCursor + 0x100;
          polygonList[2] = vertexCursor + 0x200;
          polygonList[3] = vertexCursor + 0x300;
          *polygonList = vertexCursor;
          if (bVar2) {
            uVar6 = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            uVar6 = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = uVar6;
          puVar11 = spareList;
          iVar9 = 4;
          puVar5 = polygonList;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar17 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,local_4c,dVar17,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             puVar11 = polygonList, polygonVertexCount = local_4c[0], puVar5 = spareList, local_4c[0] != 0)) {
            polygonList = puVar5;
            spareList = puVar11;
            if ((batchClipCodes & 0xff) != 0) {
              dVar17 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,puVar11,local_4c,1);
              if (local_4c[0] == 0) goto LAB_000f2450;
              if (0 < local_4c[0]) {
                spareList = polygonList;
                polygonVertexCount = local_4c[0];
                polygonList = puVar11;
              }
            }
            if ((cullFaceEnabled == '\0') ||
               (iVar16 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing),
               dVar17 = f1AfterCall2, iVar16 == 0)) {
              iVar16 = backFacing;
              if ((!bVar2) && ((bVar4 && (puVar11 = polygonList, iVar8 = polygonVertexCount, 0 < polygonVertexCount)))) {
                do {
                  _gleVPFlipColors(glContext,*puVar11,1,iVar16);
                  iVar8 = iVar8 + -1;
                  puVar11 = puVar11 + 1;
                } while (iVar8 != 0);
              }
              dVar17 = (double)_gleSelectPolygonPtr(glContext,polygonList,polygonVertexCount);
            }
          }
LAB_000f2450:
          vertexCursor = vertexCursor + 0x400;
        } while (vertexCursor <= uVar12);
      }
    }
  }
  return;
}

/* _gleSelectQuadStripFunc_body @ 0xf247c (856 bytes) */
void _gleSelectQuadStripFunc_body(glContext)
  int glContext;
{
  char cullFaceEnabled;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint batchClipCodes;
  int iVar8;
  int iVar9;
  int polygonVertexCount;
  uint *spareList;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint *polygonList;
  uint vertexCursor;
  double f1AfterCall;
  double dVar17;
  double f1AfterCall1;
  double f1AfterCall2;
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
  int local_4c [6];
  
  iVar9 = -1;
  bVar2 = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    bVar2 = true;
  }
  bVar2 = !bVar2;
  bVar4 = false;
  if ((!bVar2) && (*(char *)(glContext + 0x4666) != '\0')) {
    bVar4 = true;
  }
  cullFaceEnabled = *(char *)(glContext + 0x34da);
  vertexCursor = *(uint *)(glContext + 0x4854);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (uVar13 = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
      3 < (int)uVar13)) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,uVar13), (batchClipCodes & 0xff00) == 0)) {
    dVar17 = f1AfterCall;
    if (bVar2) {
      if (*(char *)(glContext + 0x4e18) != '\0') {
        dVar17 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, uVar13);
      }
    }
    else {
      vertexCursor = *(uint *)(glContext + 0x4864);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (cullFaceEnabled == '\0') {
        _gleSelectQuadStrip(glContext,vertexCursor,uVar13);
      }
      else {
        uVar13 = (vertexCursor + uVar13 * 0x100) - 0x400;
        do {
          bVar3 = false;
          iVar14 = 0;
          uVar7 = vertexCursor;
          do {
            while( true ) {
              uVar12 = uVar7;
              if (uVar13 < vertexCursor) goto LAB_000f2614;
              uVar7 = vertexCursor + 0x200;
              iVar8 = ((undefined4 (*)())_gleCullQuad)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x300,uVar7,&backFacing,
                                   dVar17,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                   incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88);
              dVar17 = f1AfterCall1;
              if (iVar8 != 0) break;
              if (iVar9 != backFacing) {
                bVar3 = true;
              }
              if ((bVar3) && (0 < iVar14)) goto LAB_000f2614;
              iVar14 = iVar14 + 2;
              iVar9 = backFacing;
              vertexCursor = uVar7;
              uVar7 = uVar12;
            }
            vertexCursor = uVar7;
          } while (iVar14 < 1);
LAB_000f2614:
          iVar14 = iVar14 + 2;
          if (3 < iVar14) {
            if ((!bVar2) && (bVar4)) {
              _gleVPFlipColors(glContext,uVar12,iVar14,iVar9);
            }
            dVar17 = (double)_gleSelectQuadStrip(glContext,uVar12,iVar14);
          }
        } while (vertexCursor <= uVar13);
      }
    }
    else {
      polygonList = *(uint **)(glContext + 0x4870);
      spareList = *(uint **)(glContext + 0x4874);
      uVar13 = (vertexCursor + uVar13 * 0x100) - 0x400;
      if (vertexCursor <= uVar13) {
        do {
          uVar12 = vertexCursor + 0x200;
          polygonList[1] = vertexCursor + 0x100;
          polygonList[2] = vertexCursor + 0x300;
          *polygonList = vertexCursor;
          polygonList[3] = uVar12;
          if (bVar2) {
            uVar6 = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            uVar6 = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = uVar6;
          puVar11 = spareList;
          iVar9 = 4;
          puVar5 = polygonList;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar17 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,local_4c,dVar17,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             puVar11 = polygonList, polygonVertexCount = local_4c[0], puVar5 = spareList, local_4c[0] != 0)) {
            polygonList = puVar5;
            spareList = puVar11;
            if ((batchClipCodes & 0xff) != 0) {
              dVar17 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,puVar11,local_4c,1);
              if (local_4c[0] == 0) goto LAB_000f27ac;
              if (0 < local_4c[0]) {
                spareList = polygonList;
                polygonVertexCount = local_4c[0];
                polygonList = puVar11;
              }
            }
            if ((cullFaceEnabled == '\0') ||
               (iVar14 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing),
               dVar17 = f1AfterCall2, iVar14 == 0)) {
              iVar14 = backFacing;
              if ((!bVar2) && ((bVar4 && (puVar11 = polygonList, iVar8 = polygonVertexCount, 0 < polygonVertexCount)))) {
                do {
                  _gleVPFlipColors(glContext,*puVar11,1,iVar14);
                  iVar8 = iVar8 + -1;
                  puVar11 = puVar11 + 1;
                } while (iVar8 != 0);
              }
              dVar17 = (double)_gleSelectPolygonPtr(glContext,polygonList,polygonVertexCount);
            }
          }
LAB_000f27ac:
          vertexCursor = uVar12;
        } while (uVar12 <= uVar13);
      }
    }
  }
  return;
}

/* _gleFlushAtomicFunc @ 0xf27d4 (64 bytes) */
void _gleFlushAtomicFunc(glContext)
  int glContext;
{
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  _glePopMaterials(glContext);
  return;
}

/* _gleFlushAtomicTCLRDirtyFunc @ 0xf2814 (172 bytes) */
void _gleFlushAtomicTCLRDirtyFunc(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
                    
                    
    (**(code **)(glContext + 0x4a0c))(glContext);
    return;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleFlushLineLoopFunc @ 0xf28c0 (212 bytes) */
void _gleFlushLineLoopFunc(glContext)
  int glContext;
{
  int iVar1;
  short sVar3;
  undefined8 *puVar2;
  undefined8 *puVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 local_110 [33];
  
  if (*(char *)(glContext + 0x4a18) == '\0') {
    sVar3 = *(short *)(glContext + 0x487c);
    iVar5 = 0;
    if ((int)sVar3 >> 3 < 1) goto LAB_000f291c;
    do {
      iVar1 = iVar5 * 8;
      iVar5 = iVar5 + 1;
      *(undefined8 *)(iVar1 + *(int *)(glContext + 0x4854) + -0x100) =
           *(undefined8 *)(iVar1 + *(int *)(glContext + 0x4854));
    } while (iVar5 < (int)sVar3 >> 3);
  }
  sVar3 = *(short *)(glContext + 0x487c);
LAB_000f291c:
  iVar5 = (int)sVar3 >> 3;
  if (0 < iVar5) {
    puVar4 = local_110;
    puVar2 = (undefined8 *)(*(int *)(glContext + 0x4858) + -0x100);
    do {
      uVar6 = *puVar2;
      puVar2 = puVar2 + 1;
      *puVar4 = uVar6;
      puVar4 = puVar4 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  _glePopMaterials(glContext);
  _gleSubmitVertexCopy(glContext,local_110);
  return;
}

/* _gleFlushLineLoopTCLFunc @ 0xf2994 (180 bytes) */
void _gleFlushLineLoopTCLFunc(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar3 = (int)*(short *)(glContext + 0x487c);
  iVar4 = *(int *)(glContext + 0x4854);
  if (*(char *)(glContext + 0x4a18) == '\0') {
    iVar1 = 0;
    if (0 < iVar3) {
      uVar5 = iVar3 + 7U >> 3;
      do {
        *(undefined8 *)(iVar4 + -0x100 + iVar1) = *(undefined8 *)(iVar4 + iVar1);
        iVar1 = iVar1 + 8;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    *(undefined1 *)(glContext + 0x4a18) = 1;
  }
  iVar1 = 0;
  iVar2 = *(int *)(glContext + 0x4858);
  if (0 < iVar3) {
    uVar5 = iVar3 + 7U >> 3;
    do {
      *(undefined8 *)(iVar4 + iVar1) = *(undefined8 *)((iVar2 - iVar3) + iVar1);
      iVar1 = iVar1 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  *(int *)(glContext + 0x4858) = iVar4 + iVar3;
  return;
}

/* _gleFlushLineLoopTCLRDirtyFunc @ 0xf2a48 (292 bytes) */
void _gleFlushLineLoopTCLRDirtyFunc(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
                    
                    
    (**(code **)(glContext + 0x4a0c))(glContext);
    return;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar3 = (int)*(short *)(glContext + 0x487c);
  iVar1 = *(int *)(glContext + 0x4854);
  if (*(char *)(glContext + 0x4a18) == '\0') {
    iVar2 = 0;
    if (0 < iVar3) {
      uVar5 = iVar3 + 7U >> 3;
      do {
        *(undefined8 *)(iVar1 + -0x100 + iVar2) = *(undefined8 *)(iVar1 + iVar2);
        iVar2 = iVar2 + 8;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    *(undefined1 *)(glContext + 0x4a18) = 1;
  }
  iVar2 = 0;
  iVar4 = *(int *)(glContext + 0x4858);
  if (0 < iVar3) {
    uVar5 = iVar3 + 7U >> 3;
    do {
      *(undefined8 *)(iVar1 + iVar2) = *(undefined8 *)((iVar4 - iVar3) + iVar2);
      iVar2 = iVar2 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(int *)(glContext + 0x4858) = iVar1 + iVar3;
  return;
}

/* _gleFlushLineStripFunc @ 0xf2b6c (140 bytes) */
void _gleFlushLineStripFunc(glContext)
  int glContext;
{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 local_110 [33];
  
  iVar1 = (int)*(short *)(glContext + 0x487c) >> 3;
  if (0 < iVar1) {
    puVar3 = local_110;
    puVar2 = (undefined8 *)(*(int *)(glContext + 0x4858) + -0x100);
    do {
      uVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      *puVar3 = uVar4;
      puVar3 = puVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  _glePopMaterials(glContext);
  _gleSubmitVertexCopy(glContext,local_110);
  return;
}

/* _gleFlushLineStripTCLFunc @ 0xf2bf8 (124 bytes) */
void _gleFlushLineStripTCLFunc(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar3 = (int)*(short *)(glContext + 0x487c);
  iVar1 = 0;
  iVar2 = *(int *)(glContext + 0x4858);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  iVar4 = *(int *)(glContext + 0x4854);
  if (0 < iVar3) {
    uVar5 = iVar3 + 7U >> 3;
    do {
      *(undefined8 *)(iVar4 + iVar1) = *(undefined8 *)((iVar2 - iVar3) + iVar1);
      iVar1 = iVar1 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  *(int *)(glContext + 0x4858) = iVar4 + iVar3;
  return;
}

/* _gleFlushLineStripTCLRDirtyFunc @ 0xf2c74 (236 bytes) */
void _gleFlushLineStripTCLRDirtyFunc(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
                    
                    
    (**(code **)(glContext + 0x4a0c))(glContext);
    return;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar3 = (int)*(short *)(glContext + 0x487c);
  iVar2 = 0;
  iVar4 = *(int *)(glContext + 0x4858);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  iVar1 = *(int *)(glContext + 0x4854);
  if (0 < iVar3) {
    uVar5 = iVar3 + 7U >> 3;
    do {
      *(undefined8 *)(iVar1 + iVar2) = *(undefined8 *)((iVar4 - iVar3) + iVar2);
      iVar2 = iVar2 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(int *)(glContext + 0x4858) = iVar1 + iVar3;
  return;
}

/* _gleFlushTriQuadStripFunc @ 0xf2d60 (196 bytes) */
void _gleFlushTriQuadStripFunc(glContext)
  int glContext;
{
  short sVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 local_210 [32];
  undefined8 local_110 [33];
  
  sVar1 = *(short *)(glContext + 0x487c);
  iVar2 = (int)sVar1 >> 3;
  if (0 < iVar2) {
    puVar4 = local_210;
    puVar3 = (undefined8 *)(*(int *)(glContext + 0x4858) + -0x200);
    do {
      uVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      *puVar4 = uVar5;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = (int)sVar1 >> 3;
  if (0 < iVar2) {
    puVar4 = local_110;
    puVar3 = (undefined8 *)(*(int *)(glContext + 0x4858) + -0x100);
    do {
      uVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      *puVar4 = uVar5;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  _glePopMaterials(glContext);
  _gleSubmitVertexCopy(glContext,local_210);
  _gleSubmitVertexCopy(glContext,local_110);
  return;
}

/* _gleFlushTriQuadStripTCLFunc @ 0xf2e24 (120 bytes) */
void _gleFlushTriQuadStripTCLFunc(glContext)
  int glContext;
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  sVar1 = *(short *)(glContext + 0x487c);
  iVar3 = 0;
  iVar4 = *(int *)(glContext + 0x4858);
  iVar2 = sVar1 * 2;
  iVar5 = *(int *)(glContext + 0x4854);
  if (0 < iVar2) {
    uVar6 = iVar2 + 7U >> 3;
    do {
      *(undefined8 *)(iVar5 + iVar3) = *(undefined8 *)(iVar4 + sVar1 * -2 + iVar3);
      iVar3 = iVar3 + 8;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  *(int *)(glContext + 0x4858) = iVar5 + iVar2;
  return;
}

/* _gleFlushTriQuadStripTCLRDirtyFunc @ 0xf2e9c (232 bytes) */
void _gleFlushTriQuadStripTCLRDirtyFunc(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
                    
                    
    (**(code **)(glContext + 0x4a0c))(glContext);
    return;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  sVar1 = *(short *)(glContext + 0x487c);
  iVar4 = 0;
  iVar5 = *(int *)(glContext + 0x4858);
  iVar2 = sVar1 * 2;
  iVar3 = *(int *)(glContext + 0x4854);
  if (0 < iVar2) {
    uVar6 = iVar2 + 7U >> 3;
    do {
      *(undefined8 *)(iVar3 + iVar4) = *(undefined8 *)(iVar5 + sVar1 * -2 + iVar4);
      iVar4 = iVar4 + 8;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(int *)(glContext + 0x4858) = iVar3 + iVar2;
  return;
}

/* _gleFlushTriangleFanFunc @ 0xf2f84 (200 bytes) */
void _gleFlushTriangleFanFunc(glContext)
  int glContext;
{
  short sVar1;
  int iVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 *puVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 local_210 [32];
  undefined8 local_110 [33];
  
  sVar1 = *(short *)(glContext + 0x487c);
  iVar2 = (int)sVar1 >> 3;
  if (0 < iVar2) {
    iVar6 = *(int *)(glContext + 0x4854);
    iVar4 = 0;
    do {
      local_210[iVar4] = *(undefined8 *)(iVar4 * 8 + iVar6);
      iVar2 = iVar2 + -1;
      iVar4 = iVar4 + 1;
    } while (iVar2 != 0);
  }
  iVar2 = (int)sVar1 >> 3;
  if (0 < iVar2) {
    puVar5 = local_110;
    puVar3 = (undefined8 *)(*(int *)(glContext + 0x4858) + -0x100);
    do {
      uVar7 = *puVar3;
      puVar3 = puVar3 + 1;
      *puVar5 = uVar7;
      puVar5 = puVar5 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  _glePopMaterials(glContext);
  _gleSubmitVertexCopy(glContext,local_210);
  _gleSubmitVertexCopy(glContext,local_110);
  return;
}

/* _gleFlushTriangleFanTCLFunc @ 0xf304c (120 bytes) */
void _gleFlushTriangleFanTCLFunc(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar3 = (int)*(short *)(glContext + 0x487c);
  iVar1 = 0;
  iVar4 = *(int *)(glContext + 0x4858);
  iVar2 = *(int *)(glContext + 0x4854) + iVar3;
  if (0 < iVar3) {
    uVar5 = iVar3 + 7U >> 3;
    do {
      *(undefined8 *)(iVar2 + iVar1) = *(undefined8 *)((iVar4 - iVar3) + iVar1);
      iVar1 = iVar1 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  *(int *)(glContext + 0x4858) = iVar2 + iVar3;
  return;
}

/* _gleFlushTriangleFanTCLRDirtyFunc @ 0xf30c4 (232 bytes) */
void _gleFlushTriangleFanTCLRDirtyFunc(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
                    
                    
    (**(code **)(glContext + 0x4a0c))(glContext);
    return;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar3 = (int)*(short *)(glContext + 0x487c);
  iVar2 = 0;
  iVar4 = *(int *)(glContext + 0x4858);
  iVar1 = *(int *)(glContext + 0x4854) + iVar3;
  if (0 < iVar3) {
    uVar5 = iVar3 + 7U >> 3;
    do {
      *(undefined8 *)(iVar1 + iVar2) = *(undefined8 *)((iVar4 - iVar3) + iVar2);
      iVar2 = iVar2 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(int *)(glContext + 0x4858) = iVar1 + iVar3;
  return;
}

/* _gleFlushPolygonFunc @ 0xf31ac (240 bytes) */
void _gleFlushPolygonFunc(glContext)
  int glContext;
{
  short sVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 local_210 [15];
  undefined1 local_194;
  undefined8 local_110 [32];
  
  sVar1 = *(short *)(glContext + 0x487c);
  iVar2 = (int)sVar1 >> 3;
  if (0 < iVar2) {
    iVar5 = *(int *)(glContext + 0x4854);
    iVar6 = 0;
    do {
      local_210[iVar6] = *(undefined8 *)(iVar6 * 8 + iVar5);
      iVar2 = iVar2 + -1;
      iVar6 = iVar6 + 1;
    } while (iVar2 != 0);
  }
  iVar6 = 0;
  iVar2 = (int)sVar1 >> 3;
  if (iVar2 < 1) {
    iVar5 = *(int *)(glContext + 0x4858);
  }
  else {
    iVar5 = *(int *)(glContext + 0x4858);
    puVar4 = local_110;
    puVar3 = (undefined8 *)(iVar5 + -0x100);
    do {
      iVar6 = iVar6 + 1;
      uVar7 = *puVar3;
      puVar3 = puVar3 + 1;
      *puVar4 = uVar7;
      puVar4 = puVar4 + 1;
    } while (iVar6 < iVar2);
  }
  *(undefined1 *)(iVar5 + -0x84) = 0;
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  _glePopMaterials(glContext);
  local_194 = 0;
  _gleSubmitVertexCopy(glContext,local_210);
  _gleSubmitVertexCopy(glContext,local_110);
  return;
}

/* _gleFlushPolygonTCLFunc @ 0xf329c (220 bytes) */
void _gleFlushPolygonTCLFunc(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar3 = 0;
  iVar4 = (int)*(short *)(glContext + 0x487c);
  iVar5 = *(int *)(glContext + 0x4858) - iVar4;
  if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
    uVar3 = *(undefined1 *)(iVar5 + *(short *)(glContext + 0x487e));
    *(undefined1 *)(iVar5 + *(short *)(glContext + 0x487e)) = 0;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar2 = *(int *)(glContext + 0x4854);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
    *(undefined1 *)(iVar5 + *(short *)(glContext + 0x487e)) = uVar3;
    *(undefined1 *)(iVar2 + *(short *)(glContext + 0x487e)) = 0;
  }
  iVar1 = 0;
  iVar2 = iVar2 + iVar4;
  if (0 < iVar4) {
    uVar6 = iVar4 + 7U >> 3;
    do {
      *(undefined8 *)(iVar2 + iVar1) = *(undefined8 *)(iVar5 + iVar1);
      iVar1 = iVar1 + 8;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  *(int *)(glContext + 0x4858) = iVar2 + iVar4;
  return;
}

/* _gleFlushPolygonTCLRDirtyFunc @ 0xf3378 (328 bytes) */
void _gleFlushPolygonTCLRDirtyFunc(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar3 = 0;
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
                    
                    
    (**(code **)(glContext + 0x4a0c))(glContext);
    return;
  }
  iVar4 = (int)*(short *)(glContext + 0x487c);
  iVar5 = *(int *)(glContext + 0x4858) - iVar4;
  if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
    uVar3 = *(undefined1 *)(iVar5 + *(short *)(glContext + 0x487e));
    *(undefined1 *)(iVar5 + *(short *)(glContext + 0x487e)) = 0;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  iVar2 = *(int *)(glContext + 0x4854);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
    *(undefined1 *)(iVar5 + *(short *)(glContext + 0x487e)) = uVar3;
    *(undefined1 *)(iVar2 + *(short *)(glContext + 0x487e)) = 0;
  }
  iVar1 = 0;
  iVar2 = iVar2 + iVar4;
  if (0 < iVar4) {
    uVar6 = iVar4 + 7U >> 3;
    do {
      *(undefined8 *)(iVar2 + iVar1) = *(undefined8 *)(iVar5 + iVar1);
      iVar1 = iVar1 + 8;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(int *)(glContext + 0x4858) = iVar2 + iVar4;
  return;
}

/* _gleInitPrimitiveData @ 0xf34c0 (4 bytes) */
void _gleInitPrimitiveData()
{
  return;
}

/* _gleRenderNoop @ 0xf34c4 (4 bytes) */
void _gleRenderNoop()
{
  return;
}

/* _gleFlushNoop @ 0xf34c8 (12 bytes) */
void _gleFlushNoop(glContext)
  int glContext;
{
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

