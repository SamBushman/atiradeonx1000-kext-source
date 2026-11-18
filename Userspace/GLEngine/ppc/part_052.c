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
  undefined *renderFunc;
  
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushTriQuadStripFunc_001122c8;
  renderFunc = PTR__gleFeedbackQuadStripFunc_00112264;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    renderFunc = PTR__gleSelectQuadStripFunc_00112268;
  }
  *(undefined **)(glContext + 0x4a08) = renderFunc;
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
  undefined *feedbackOrSelectFunc;
  
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushPolygonFunc_00112260;
  feedbackOrSelectFunc = PTR__gleFeedbackPolygonFunc_00112244;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    feedbackOrSelectFunc = PTR__gleSelectPolygonFunc_00112248;
  }
  *(undefined **)(glContext + 0x4a08) = feedbackOrSelectFunc;
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
double _gleClipPolyPlane(int glContext,int *polygonList,int vertexCount,int *outputList,int *outVertexCount,double forwardedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
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
            forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int,double))(glContext + 0x49c8))
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
            forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int,double))(glContext + 0x49c8))
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
        return forwardedFloatArg1;
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
  return forwardedFloatArg1;
}

/* _gleCullPolygonStack @ 0xebc00 (192 bytes) */
int _gleCullPolygonStack(glContext, vertexRecords, vertexCount, windingFlip, backFacing)
  int glContext;
  float *vertexRecords;
  int vertexCount;
  uint windingFlip;
  uint *backFacing;
{
  float firstX;
  float firstY;
  float lastY;
  float lastX;
  uint orientation;
  float lastXTimesPreviousY;
  float previousX;
  float signedAreaSum;
  int remaining;
  int vertexIndex;
  
  firstX = *vertexRecords;
  firstY = vertexRecords[1];
  lastY = firstY;
  lastX = firstX;
  signedAreaSum = FLOAT_00108e50;
  if (1 < vertexCount) {
    remaining = vertexCount + -1;
    vertexIndex = 1;
    previousX = firstX;
    do {
      lastX = vertexRecords[vertexIndex * 0x40];
      lastXTimesPreviousY = lastX * lastY;
      lastY = vertexRecords[vertexIndex * 0x40 + 1];
      signedAreaSum = signedAreaSum + ((previousX * lastY - lastXTimesPreviousY));
      remaining = remaining + -1;
      vertexIndex = vertexIndex + 1;
      previousX = lastX;
    } while (remaining != 0);
  }
  orientation = -(uint)((bool)*(char *)(glContext + 0x4fe1) ==
            FLOAT_00108e50 < signedAreaSum + ((lastX * firstY - firstX * lastY)) ^ windingFlip) >> 0x1f;
  if (*(byte *)(glContext + 0x4fe3) == orientation) {
    return 1;
  }
  *backFacing = orientation ^ 1;
  return 0;
}

/* _gleCullTriangle @ 0xebcc0 (152 bytes) */
undefined4 _gleCullTriangle(int glContext,float *vertex0,float *vertex1,float *vertex2,uint windingFlip,uint *backFacing,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  uint orientation;
  
  orientation = -(uint)((bool)*(char *)(glContext + 0x4fe1) ==
            FLOAT_00108e50 <
            (*vertex0 * vertex1[1] - *vertex1 * vertex0[1]) +
            ((*vertex1 * vertex2[1] - *vertex2 * vertex1[1])) +
            ((*vertex2 * vertex0[1] - *vertex0 * vertex2[1])) ^ windingFlip) >> 0x1f;
  if (*(byte *)(glContext + 0x4fe3) == orientation) {
    return 1;
  }
  *backFacing = orientation ^ 1;
  return 0;
}

/* _gleCullQuad @ 0xebd58 (160 bytes) */
undefined4 _gleCullQuad(int glContext,float *vertex0,float *vertex1,float *vertex2,float *vertex3,uint *backFacingOut,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  uint frontFacing;
  
  frontFacing = (uint)((bool)*(char *)(glContext + 0x4fe1) ==
                FLOAT_00108e50 <
                (*vertex0 * vertex1[1] - *vertex1 * vertex0[1]) +
                ((*vertex1 * vertex2[1] - *vertex2 * vertex1[1])) +
                ((*vertex2 * vertex3[1] - *vertex3 * vertex2[1])) +
                ((*vertex3 * vertex0[1] - *vertex0 * vertex3[1])));
  if (*(byte *)(glContext + 0x4fe3) == frontFacing) {
    return 1;
  }
  *backFacingOut = frontFacing ^ 1;
  return 0;
}

/* _gleCullPolygonPtrStack @ 0xebdf8 (184 bytes) */
int _gleCullPolygonPtrStack(glContext, polygonListThenCursor, vertexCount, backFacingOut)
  int glContext;
  undefined4 *polygonListThenCursor;
  int vertexCount;
  uint *backFacingOut;
{
  uint frontFacing;
  float lastPointX;
  float lastPointY;
  float previousPointX;
  float previousPointY;
  float areaSum;
  int edgesLeft;
  float *firstPoint;
  
  firstPoint = (float *)*polygonListThenCursor;
  lastPointX = *firstPoint;
  lastPointY = firstPoint[1];
  areaSum = FLOAT_00108e50;
  if (1 < vertexCount) {
    edgesLeft = vertexCount + -1;
    previousPointX = lastPointX;
    previousPointY = lastPointY;
    do {
      polygonListThenCursor = polygonListThenCursor + 1;
      lastPointX = *(float *)*polygonListThenCursor;
      lastPointY = ((float *)*polygonListThenCursor)[1];
      areaSum = areaSum + ((previousPointX * lastPointY - lastPointX * previousPointY));
      edgesLeft = edgesLeft + -1;
      previousPointX = lastPointX;
      previousPointY = lastPointY;
    } while (edgesLeft != 0);
  }
  frontFacing = (uint)((bool)*(char *)(glContext + 0x4fe1) ==
                FLOAT_00108e50 < areaSum + ((lastPointX * firstPoint[1] - *firstPoint * lastPointY)));
  if (*(byte *)(glContext + 0x4fe3) == frontFacing) {
    return 1;
  }
  *backFacingOut = frontFacing ^ 1;
  return 0;
}

/* _gleFeedbackPolygonFunc_body @ 0xebeb4 (1112 bytes) */
void _gleFeedbackPolygonFunc_body(glContext)
  int glContext;
{
  char cullEnabled;
  ushort facePolygonMode;
  bool vertexProgramThenFixedFunctionPath;
  bool lightingActive;
  bool twoSidedLighting;
  int *listCursorThenClipDestThenFlipCursor;
  uint clipFlagsThenFlipCount;
  int cullResultThenPolygonModeThenVertexPtr;
  undefined4 planeClippedFlag;
  code *lightingFunc;
  int *spareList;
  int *polygonList;
  uint vertexCountThenClippedCount;
  int firstVertexThenCursorThenCullResultThenPolygonMode;
  uint remainingVertices;
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStackWord_ffffff88;
  double incomingStackWord_ffffff90;
  uint clippedCount;
  int backFacing [5];
  
  vertexProgramThenFixedFunctionPath = false;
  backFacing[0] = 0;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    vertexProgramThenFixedFunctionPath = true;
  }
  vertexProgramThenFixedFunctionPath = !vertexProgramThenFixedFunctionPath;
  lightingActive = false;
  if ((vertexProgramThenFixedFunctionPath) && (*(char *)(glContext + 0x30aa) != '\0')) {
    lightingActive = true;
  }
  twoSidedLighting = false;
  if ((lightingActive) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  cullEnabled = *(char *)(glContext + 0x4fe0);
  firstVertexThenCursorThenCullResultThenPolygonMode = *(int *)(glContext + 0x4854);
  if ((int)*(short *)(glContext + 0x487c) == 0) {
    return;
  }
  vertexCountThenClippedCount = (uint)(*(int *)(glContext + 0x4858) - firstVertexThenCursorThenCullResultThenPolygonMode) / (uint)(int)*(short *)(glContext + 0x487c);
  if ((int)vertexCountThenClippedCount < 3) {
    return;
  }
  if (vertexProgramThenFixedFunctionPath) {
    clipFlagsThenFlipCount = (**(code **)(glContext + 0x5060))(glContext,firstVertexThenCursorThenCullResultThenPolygonMode,vertexCountThenClippedCount);
  }
  else {
    clipFlagsThenFlipCount = _gleVPEmulate(glContext,vertexCountThenClippedCount);
  }
  if ((clipFlagsThenFlipCount & 0xff00) != 0) {
    return;
  }
  if (vertexProgramThenFixedFunctionPath) {
    if (*(char *)(glContext + 0x53e4) != '\0') {
      (**(code **)(glContext + 0x53dc))(glContext,firstVertexThenCursorThenCullResultThenPolygonMode,vertexCountThenClippedCount);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      (**(code **)(glContext + 0x5064))(glContext,firstVertexThenCursorThenCullResultThenPolygonMode,vertexCountThenClippedCount);
    }
    if ((lightingActive) || (*(char *)(glContext + 0x53e6) != '\0')) {
      (**(code **)(glContext + 0x5068))(glContext,firstVertexThenCursorThenCullResultThenPolygonMode,vertexCountThenClippedCount);
    }
    if (*(char *)(glContext + 0x53e5) != '\0') {
      (**(code **)(glContext + 0x53e0))(glContext,firstVertexThenCursorThenCullResultThenPolygonMode,vertexCountThenClippedCount);
    }
  }
  else {
    firstVertexThenCursorThenCullResultThenPolygonMode = *(int *)(glContext + 0x4864);
  }
  if (((clipFlagsThenFlipCount & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if ((cullEnabled != '\0') &&
       (cullResultThenPolygonModeThenVertexPtr = ((int (*)())_gleCullPolygonStack)(glContext,firstVertexThenCursorThenCullResultThenPolygonMode,vertexCountThenClippedCount,0,backFacing), cullResultThenPolygonModeThenVertexPtr != 0)) {
      return;
    }
    (**(code **)(glContext + 0x506c))(glContext,firstVertexThenCursorThenCullResultThenPolygonMode,vertexCountThenClippedCount,0);
    if (twoSidedLighting) {
      lightingFunc = *(code **)(backFacing[0] * 4 + glContext + 0x4de8);
    }
    else {
      if (!lightingActive) goto LAB_000ec290;
      lightingFunc = *(code **)(glContext + 0x4de8);
    }
    (*lightingFunc)(glContext,firstVertexThenCursorThenCullResultThenPolygonMode,vertexCountThenClippedCount);
LAB_000ec290:
    if (backFacing[0] == 0) {
      facePolygonMode = *(ushort *)(glContext + 0x34d0);
    }
    else {
      facePolygonMode = *(ushort *)(glContext + 0x34d2);
    }
    cullResultThenPolygonModeThenVertexPtr = facePolygonMode - 0x1b00;
    if ((*(char *)(glContext + 0x4a18) != '\0') && (cullResultThenPolygonModeThenVertexPtr == 1)) {
      cullResultThenPolygonModeThenVertexPtr = 3;
    }
    if ((!vertexProgramThenFixedFunctionPath) && (lightingActive)) {
      _gleVPFlipColors(glContext,firstVertexThenCursorThenCullResultThenPolygonMode,vertexCountThenClippedCount,backFacing[0]);
    }
    _gleFeedbackPolygon(glContext,firstVertexThenCursorThenCullResultThenPolygonMode,vertexCountThenClippedCount,cullResultThenPolygonModeThenVertexPtr);
    return;
  }
  forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, firstVertexThenCursorThenCullResultThenPolygonMode, vertexCountThenClippedCount, 0);
  polygonList = *(int **)(glContext + 0x4870);
  spareList = *(int **)(glContext + 0x4874);
  listCursorThenClipDestThenFlipCursor = polygonList;
  remainingVertices = vertexCountThenClippedCount;
  if (0 < (int)vertexCountThenClippedCount) {
    do {
      *listCursorThenClipDestThenFlipCursor = firstVertexThenCursorThenCullResultThenPolygonMode;
      firstVertexThenCursorThenCullResultThenPolygonMode = firstVertexThenCursorThenCullResultThenPolygonMode + 0x100;
      remainingVertices = remainingVertices - 1;
      listCursorThenClipDestThenFlipCursor = listCursorThenClipDestThenFlipCursor + 1;
    } while (remainingVertices != 0);
  }
  if (!vertexProgramThenFixedFunctionPath) {
    *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  }
  planeClippedFlag = 0;
  listCursorThenClipDestThenFlipCursor = spareList;
  if (*(char *)(glContext + 0x4e18) != '\0') {
    ((double (*)())_gleClipPolyPlane)(glContext,polygonList,vertexCountThenClippedCount,spareList,&clippedCount,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
                      incomingFpr6,incomingFpr7,incomingFpr8,incomingStackWord_ffffff88,incomingStackWord_ffffff90);
    if (clippedCount == 0) {
      return;
    }
    planeClippedFlag = 1;
    listCursorThenClipDestThenFlipCursor = polygonList;
    polygonList = spareList;
    vertexCountThenClippedCount = clippedCount;
  }
  if ((clipFlagsThenFlipCount & 0xff) != 0) {
    _gleClipPoly(glContext,polygonList,vertexCountThenClippedCount,clipFlagsThenFlipCount & 0xff,listCursorThenClipDestThenFlipCursor,&clippedCount,planeClippedFlag);
    if (clippedCount == 0) {
      return;
    }
    if (0 < (int)clippedCount) {
      polygonList = listCursorThenClipDestThenFlipCursor;
      vertexCountThenClippedCount = clippedCount;
    }
  }
  if ((cullEnabled != '\0') &&
     (firstVertexThenCursorThenCullResultThenPolygonMode = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,vertexCountThenClippedCount,backFacing), firstVertexThenCursorThenCullResultThenPolygonMode != 0)) {
    return;
  }
  if (twoSidedLighting) {
    lightingFunc = *(code **)(backFacing[0] * 4 + glContext + 0x4df0);
  }
  else {
    if (!lightingActive) goto LAB_000ec180;
    lightingFunc = *(code **)(glContext + 0x4df0);
  }
  (*lightingFunc)(glContext,polygonList,vertexCountThenClippedCount);
LAB_000ec180:
  if (backFacing[0] == 0) {
    facePolygonMode = *(ushort *)(glContext + 0x34d0);
  }
  else {
    facePolygonMode = *(ushort *)(glContext + 0x34d2);
  }
  firstVertexThenCursorThenCullResultThenPolygonMode = facePolygonMode - 0x1b00;
  if ((*(char *)(glContext + 0x4a18) != '\0') && (firstVertexThenCursorThenCullResultThenPolygonMode == 1)) {
    firstVertexThenCursorThenCullResultThenPolygonMode = 3;
  }
  if (((!vertexProgramThenFixedFunctionPath) && (lightingActive)) && (listCursorThenClipDestThenFlipCursor = polygonList, clipFlagsThenFlipCount = vertexCountThenClippedCount, 0 < (int)vertexCountThenClippedCount)) {
    do {
      cullResultThenPolygonModeThenVertexPtr = *listCursorThenClipDestThenFlipCursor;
      listCursorThenClipDestThenFlipCursor = listCursorThenClipDestThenFlipCursor + 1;
      _gleVPFlipColors(glContext,cullResultThenPolygonModeThenVertexPtr,1,backFacing[0]);
      clipFlagsThenFlipCount = clipFlagsThenFlipCount - 1;
    } while (clipFlagsThenFlipCount != 0);
  }
  _gleFeedbackPolygonPtr(glContext,polygonList,vertexCountThenClippedCount,firstVertexThenCursorThenCullResultThenPolygonMode);
  return;
}

/* _gleFeedbackTrianglesFunc_body @ 0xec310 (1276 bytes) */
void _gleFeedbackTrianglesFunc_body(glContext)
  int glContext;
{
  char cullEnabled;
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
  uint *oldPolygonListThenVertexPtrCursor;
  uint vertexCountThenLastTriangleStart;
  uint *polygonList;
  uint nextRunStart;
  uint runStart;
  uint vertexCursor;
  int iVar20;
  int polygonVertexCount;
  int remainingVertices;
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
  cullEnabled = *(char *)(glContext + 0x4fe0);
  vertexCursor = *(uint *)(glContext + 0x4854);
  if (((int)*(short *)(glContext + 0x487c) != 0) &&
     (vertexCountThenLastTriangleStart = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
     2 < (int)vertexCountThenLastTriangleStart)) {
    if (fixedFunctionPath) {
      clipFlagsThenResumeCursor = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCountThenLastTriangleStart);
    }
    else {
      clipFlagsThenResumeCursor = _gleVPEmulate(glContext,vertexCountThenLastTriangleStart);
    }
    if ((clipFlagsThenResumeCursor & 0xff00) == 0) {
      if (fixedFunctionPath) {
        if (*(char *)(glContext + 0x53e4) != '\0') {
          (**(code **)(glContext + 0x53dc))(glContext,vertexCursor,vertexCountThenLastTriangleStart);
        }
        if (*(char *)(glContext + 0x50b4) != '\0') {
          (**(code **)(glContext + 0x5064))(glContext,vertexCursor,vertexCountThenLastTriangleStart);
        }
        if ((lightingActive) || (*(char *)(glContext + 0x53e6) != '\0')) {
          (**(code **)(glContext + 0x5068))(glContext,vertexCursor,vertexCountThenLastTriangleStart);
        }
        if (*(char *)(glContext + 0x53e5) != '\0') {
          (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,vertexCountThenLastTriangleStart);
        }
      }
      else {
        vertexCursor = *(uint *)(glContext + 0x4864);
      }
      if (((clipFlagsThenResumeCursor & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCountThenLastTriangleStart, 0);
        if (cullEnabled == '\0') {
          if (lightingActive) {
            forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x4de8))(glContext, vertexCursor, vertexCountThenLastTriangleStart);
          }
          ((double (*)())_gleFeedbackTriangles)(glContext,vertexCursor,vertexCountThenLastTriangleStart,*(ushort *)(glContext + 0x34d0) - 0x1b00,forwardedFloatArg1)
          ;
        }
        else {
          vertexCountThenLastTriangleStart = (vertexCursor + vertexCountThenLastTriangleStart * 0x100) - 0x300;
          do {
            facingChanged = false;
            iVar20 = 0;
            clipFlagsThenResumeCursor = vertexCursor;
            runStart = vertexCursor;
            if (vertexCursor <= vertexCountThenLastTriangleStart) {
              do {
                cullResultThenBackFacing = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x200,0,&backFacing,
                                          forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                          incomingStack_ffffff78,incomingStack_ffffff80);
                forwardedFloatArg1 = forwardedFloatArg1;
                if (cullResultThenBackFacing == 0) {
                  if (previousBackFacingThenVertexArrayEnd != backFacing) {
                    facingChanged = true;
                  }
                  if ((facingChanged) && (clipFlagsThenResumeCursor = vertexCursor, 0 < iVar20)) break;
                  iVar20 = iVar20 + 3;
                  previousBackFacingThenVertexArrayEnd = backFacing;
                  nextRunStart = runStart;
                }
                else {
                  nextRunStart = vertexCursor + 0x300;
                  clipFlagsThenResumeCursor = nextRunStart;
                  if (0 < iVar20) break;
                }
                vertexCursor = vertexCursor + 0x300;
                clipFlagsThenResumeCursor = vertexCursor;
                runStart = nextRunStart;
              } while (vertexCursor <= vertexCountThenLastTriangleStart);
              if (2 < iVar20) {
                if (twoSidedLighting) {
                  lightingFunc = *(code **)(previousBackFacingThenVertexArrayEnd * 4 + glContext + 0x4de8);
LAB_000ec5d0:
                  forwardedFloatArg1 = (double)(*((double (*)(int,int,int))lightingFunc))(glContext, runStart, iVar20);
                }
                else if (lightingActive) {
                  lightingFunc = *(code **)(glContext + 0x4de8);
                  goto LAB_000ec5d0;
                }
                if ((!fixedFunctionPath) && (lightingActive)) {
                  forwardedFloatArg1 = (double)_gleVPFlipColors(glContext,runStart,iVar20,previousBackFacingThenVertexArrayEnd);
                }
                if (previousBackFacingThenVertexArrayEnd == 0) {
                  facePolygonMode = *(ushort *)(glContext + 0x34d0);
                }
                else {
                  facePolygonMode = *(ushort *)(glContext + 0x34d2);
                }
                forwardedFloatArg1 = (double)((double (*)())_gleFeedbackTriangles)(glContext,runStart,iVar20,facePolygonMode - 0x1b00,forwardedFloatArg1);
              }
            }
            vertexCursor = clipFlagsThenResumeCursor;
          } while (clipFlagsThenResumeCursor <= vertexCountThenLastTriangleStart);
        }
      }
      else {
        forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCountThenLastTriangleStart, 0);
        previousBackFacingThenVertexArrayEnd = vertexCursor + vertexCountThenLastTriangleStart * 0x100;
        polygonList = *(uint **)(glContext + 0x4870);
        spareList = *(uint **)(glContext + 0x4874);
        for (; vertexCursor <= previousBackFacingThenVertexArrayEnd - 0x300U; vertexCursor = vertexCursor + 0x300) {
          polygonList[1] = vertexCursor + 0x100;
          polygonList[2] = vertexCursor + 0x200;
          *polygonList = vertexCursor;
          if (fixedFunctionPath) {
            bufferEnd = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            bufferEnd = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = bufferEnd;
          oldPolygonListThenVertexPtrCursor = spareList;
          polygonVertexCount = 3;
          newPolygonList = polygonList;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (forwardedFloatArg1 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,clipCount,forwardedFloatArg1,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             oldPolygonListThenVertexPtrCursor = polygonList, polygonVertexCount = clipCount[0], newPolygonList = spareList, clipCount[0] != 0)) {
            polygonList = newPolygonList;
            spareList = oldPolygonListThenVertexPtrCursor;
            if ((clipFlagsThenResumeCursor & 0xff) != 0) {
              forwardedFloatArg1 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,clipFlagsThenResumeCursor & 0xff,oldPolygonListThenVertexPtrCursor,clipCount,1);
              if (clipCount[0] == 0) goto LAB_000ec7e4;
              if (0 < clipCount[0]) {
                spareList = polygonList;
                polygonVertexCount = clipCount[0];
                polygonList = oldPolygonListThenVertexPtrCursor;
              }
            }
            if ((cullEnabled == '\0') ||
               (cullResultThenBackFacing = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing),
               forwardedFloatArg1 = f1AfterCall1, cullResultThenBackFacing == 0)) {
              cullResultThenBackFacing = backFacing;
              if (twoSidedLighting) {
                lightingFunc = *(code **)(backFacing * 4 + glContext + 0x4df0);
LAB_000ec778:
                (*lightingFunc)(glContext,polygonList,polygonVertexCount);
              }
              else if (lightingActive) {
                lightingFunc = *(code **)(glContext + 0x4df0);
                goto LAB_000ec778;
              }
              if (((!fixedFunctionPath) && (lightingActive)) && (oldPolygonListThenVertexPtrCursor = polygonList, remainingVertices = polygonVertexCount, 0 < polygonVertexCount)) {
                do {
                  _gleVPFlipColors(glContext,*oldPolygonListThenVertexPtrCursor,1,cullResultThenBackFacing);
                  remainingVertices = remainingVertices + -1;
                  oldPolygonListThenVertexPtrCursor = oldPolygonListThenVertexPtrCursor + 1;
                } while (remainingVertices != 0);
              }
              if (cullResultThenBackFacing == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              forwardedFloatArg1 = (double)_gleFeedbackPolygonPtr(glContext,polygonList,polygonVertexCount,facePolygonMode - 0x1b00);
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
  double incomingStackWord_ffffff78;
  double incomingStackWord_ffffff80;
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
                                        ,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStackWord_ffffff78
                                        ,incomingStackWord_ffffff80);
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
            polygonVertexCount = 3;
            puVar9 = polygonVertexList;
            iVar23 = previousFacing;
            if ((*(char *)(glContext + 0x4e18) == '\0') ||
               (dVar27 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonVertexList,3,spareList,clippedCount,dVar27,incomingFpr2,
                                                   incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                   incomingStackWord_ffffff78,incomingStackWord_ffffff80),
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
  double incomingStackWord_ffffff68;
  double incomingStackWord_ffffff70;
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
                                                    incomingStackWord_ffffff68,incomingStackWord_ffffff70),
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
                                       incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStackWord_ffffff68,
                                       incomingStackWord_ffffff70);
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
  char cullEnabled;
  ushort facePolygonMode;
  bool fixedFunctionPath;
  bool facingChanged;
  bool lightingActive;
  bool twoSidedLighting;
  uint quadStartThenRunStart;
  undefined4 bufferEnd;
  uint clipFlagsThenRunStartOrNextQuadStart;
  int cullResultThenBackFacing;
  uint *oldPolygonListThenVertexPtrCursor;
  code *lightingHook;
  int previousBackFacingThenRemainingVertices;
  uint *spareList;
  uint nextQuadStart;
  uint vertexCountThenLastQuadStart;
  int iVar17;
  int polygonVertexCount;
  uint *newPolygonList;
  uint *polygonList;
  uint vertexCursor;
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
  int clipCount [3];
  
  previousBackFacingThenRemainingVertices = -1;
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
  vertexCursor = *(uint *)(glContext + 0x4854);
  if (((int)*(short *)(glContext + 0x487c) != 0) &&
     (vertexCountThenLastQuadStart = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
     3 < (int)vertexCountThenLastQuadStart)) {
    if (fixedFunctionPath) {
      clipFlagsThenRunStartOrNextQuadStart = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCountThenLastQuadStart);
    }
    else {
      clipFlagsThenRunStartOrNextQuadStart = _gleVPEmulate(glContext,vertexCountThenLastQuadStart);
    }
    if ((clipFlagsThenRunStartOrNextQuadStart & 0xff00) == 0) {
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
      if (((clipFlagsThenRunStartOrNextQuadStart & 0xff) != 0) || (*(char *)(glContext + 0x4e18) != '\0')) {
        facingChanged = false;
        forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCountThenLastQuadStart, 0);
        polygonList = *(uint **)(glContext + 0x4870);
        spareList = *(uint **)(glContext + 0x4874);
        quadStartThenRunStart = vertexCursor;
joined_r0x000ed748:
        do {
          if ((vertexCursor + vertexCountThenLastQuadStart * 0x100) - 0x400 < quadStartThenRunStart) {
            return;
          }
          nextQuadStart = quadStartThenRunStart + 0x200;
          polygonList[1] = quadStartThenRunStart + 0x100;
          polygonList[2] = quadStartThenRunStart + 0x300;
          *polygonList = quadStartThenRunStart;
          polygonList[3] = nextQuadStart;
          if (fixedFunctionPath) {
            bufferEnd = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            bufferEnd = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = bufferEnd;
          oldPolygonListThenVertexPtrCursor = spareList;
          polygonVertexCount = 4;
          newPolygonList = polygonList;
          quadStartThenRunStart = nextQuadStart;
        } while ((*(char *)(glContext + 0x4e18) != '\0') &&
                (forwardedFloatArg1 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,clipCount,forwardedFloatArg1,incomingFpr2,
                                                    incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                    incomingStack_ffffff78,incomingStack_ffffff80),
                oldPolygonListThenVertexPtrCursor = polygonList, polygonVertexCount = clipCount[0], newPolygonList = spareList, clipCount[0] == 0));
        spareList = oldPolygonListThenVertexPtrCursor;
        polygonList = newPolygonList;
        if ((clipFlagsThenRunStartOrNextQuadStart & 0xff) != 0) goto code_r0x000ed7cc;
        goto LAB_000ed80c;
      }
      forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCountThenLastQuadStart, 0);
      if (cullEnabled == '\0') {
        if (lightingActive) {
          (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,vertexCountThenLastQuadStart);
        }
        _gleFeedbackQuadStrip(glContext,vertexCursor,vertexCountThenLastQuadStart,*(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        vertexCountThenLastQuadStart = (vertexCursor + vertexCountThenLastQuadStart * 0x100) - 0x400;
        do {
          facingChanged = false;
          iVar17 = 0;
          clipFlagsThenRunStartOrNextQuadStart = vertexCursor;
          do {
            while( true ) {
              quadStartThenRunStart = clipFlagsThenRunStartOrNextQuadStart;
              if (vertexCountThenLastQuadStart < vertexCursor) goto LAB_000ed654;
              clipFlagsThenRunStartOrNextQuadStart = vertexCursor + 0x200;
              cullResultThenBackFacing = ((undefined4 (*)())_gleCullQuad)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x300,clipFlagsThenRunStartOrNextQuadStart,&backFacing,
                                    forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                    incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88);
              forwardedFloatArg1 = f1AfterCall;
              if (cullResultThenBackFacing != 0) break;
              if (previousBackFacingThenRemainingVertices != backFacing) {
                facingChanged = true;
              }
              if ((facingChanged) && (0 < iVar17)) goto LAB_000ed654;
              iVar17 = iVar17 + 2;
              previousBackFacingThenRemainingVertices = backFacing;
              vertexCursor = clipFlagsThenRunStartOrNextQuadStart;
              clipFlagsThenRunStartOrNextQuadStart = quadStartThenRunStart;
            }
            vertexCursor = clipFlagsThenRunStartOrNextQuadStart;
          } while (iVar17 < 1);
LAB_000ed654:
          iVar17 = iVar17 + 2;
          if (3 < iVar17) {
            if (twoSidedLighting) {
              if (facingChanged) {
                clipFlagsThenRunStartOrNextQuadStart = quadStartThenRunStart;
                do {
                  *(byte *)(clipFlagsThenRunStartOrNextQuadStart + 0x7e) = *(byte *)(clipFlagsThenRunStartOrNextQuadStart + 0x7e) | 6;
                  clipFlagsThenRunStartOrNextQuadStart = clipFlagsThenRunStartOrNextQuadStart + 0x100;
                } while ((int)clipFlagsThenRunStartOrNextQuadStart <= (int)(quadStartThenRunStart + 0x100));
              }
              lightingHook = *(code **)(previousBackFacingThenRemainingVertices * 4 + glContext + 0x4de8);
LAB_000ed6b4:
              (*lightingHook)(glContext,quadStartThenRunStart,iVar17);
            }
            else if (lightingActive) {
              lightingHook = *(code **)(glContext + 0x4de8);
              goto LAB_000ed6b4;
            }
            if ((!fixedFunctionPath) && (lightingActive)) {
              _gleVPFlipColors(glContext,quadStartThenRunStart,iVar17,previousBackFacingThenRemainingVertices);
            }
            if (previousBackFacingThenRemainingVertices == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            forwardedFloatArg1 = (double)_gleFeedbackQuadStrip(glContext,quadStartThenRunStart,iVar17,facePolygonMode - 0x1b00);
          }
        } while (vertexCursor <= vertexCountThenLastQuadStart);
      }
    }
  }
  return;
code_r0x000ed7cc:
  forwardedFloatArg1 = (double)_gleClipPoly(glContext,newPolygonList,polygonVertexCount,clipFlagsThenRunStartOrNextQuadStart & 0xff,oldPolygonListThenVertexPtrCursor,clipCount,1);
  if (clipCount[0] == 0) goto joined_r0x000ed748;
  if (0 < clipCount[0]) {
    spareList = newPolygonList;
    polygonVertexCount = clipCount[0];
    polygonList = oldPolygonListThenVertexPtrCursor;
  }
LAB_000ed80c:
  if ((cullEnabled != '\0') &&
     (cullResultThenBackFacing = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing), forwardedFloatArg1 = f1AfterCall1,
     cullResultThenBackFacing != 0)) goto joined_r0x000ed748;
  cullResultThenBackFacing = backFacing;
  if (previousBackFacingThenRemainingVertices != backFacing) {
    facingChanged = true;
  }
  if (twoSidedLighting) {
    if (facingChanged) {
      oldPolygonListThenVertexPtrCursor = polygonList;
      previousBackFacingThenRemainingVertices = polygonVertexCount;
      if (0 < polygonVertexCount) {
        do {
          *(byte *)(*oldPolygonListThenVertexPtrCursor + 0x7e) = *(byte *)(*oldPolygonListThenVertexPtrCursor + 0x7e) | 6;
          previousBackFacingThenRemainingVertices = previousBackFacingThenRemainingVertices + -1;
          oldPolygonListThenVertexPtrCursor = oldPolygonListThenVertexPtrCursor + 1;
        } while (previousBackFacingThenRemainingVertices != 0);
      }
      facingChanged = false;
    }
    lightingHook = *(code **)(backFacing * 4 + glContext + 0x4df0);
  }
  else {
    if (!lightingActive) goto LAB_000ed8b4;
    lightingHook = *(code **)(glContext + 0x4df0);
  }
  (*lightingHook)(glContext,polygonList,polygonVertexCount);
LAB_000ed8b4:
  if (((!fixedFunctionPath) && (lightingActive)) && (oldPolygonListThenVertexPtrCursor = polygonList, previousBackFacingThenRemainingVertices = polygonVertexCount, 0 < polygonVertexCount)) {
    do {
      _gleVPFlipColors(glContext,*oldPolygonListThenVertexPtrCursor,1,cullResultThenBackFacing);
      previousBackFacingThenRemainingVertices = previousBackFacingThenRemainingVertices + -1;
      oldPolygonListThenVertexPtrCursor = oldPolygonListThenVertexPtrCursor + 1;
    } while (previousBackFacingThenRemainingVertices != 0);
  }
  if (cullResultThenBackFacing == 0) {
    facePolygonMode = *(ushort *)(glContext + 0x34d0);
  }
  else {
    facePolygonMode = *(ushort *)(glContext + 0x34d2);
  }
  forwardedFloatArg1 = (double)_gleFeedbackPolygonPtr(glContext,polygonList,polygonVertexCount,facePolygonMode - 0x1b00);
  previousBackFacingThenRemainingVertices = cullResultThenBackFacing;
  goto joined_r0x000ed748;
}

/* _gleRenderSmoothPolygonFunc_body @ 0xed940 (956 bytes) */
void _gleRenderSmoothPolygonFunc_body(glContext)
  int glContext;
{
  bool lightingEnabled;
  bool texturingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  int *polygonListCursor;
  int *clipOutputList;
  int texEnableBitsThenCullResult;
  int remainingThenCullResult;
  int polygonModeIndex;
  uint batchClipCodes;
  undefined4 planeClipRan;
  code *faceLightFunc;
  code *drawPolygonFunc;
  int *spareList;
  int *polygonList;
  int *polygonVertices;
  int polygonVertexCount;
  double f1AfterCall;
  double f1AfterHookCall;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  int clippedVertexCount;
  int backFacing [4];
  
  backFacing[0] = 0;
  texEnableBitsThenCullResult = _gleTexEnableBits(glContext);
  twoSidedLighting = false;
  lightingEnabled = (int)-(uint)*(byte *)(glContext + 0x30aa) < 0;
  if ((lightingEnabled) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  polygonVertices = *(int **)(glContext + 0x4854);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  polygonVertexCount = *(int *)(glContext + 0x4858) - (int)polygonVertices >> 8;
  if (polygonVertexCount < 3) {
    return;
  }
  batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,polygonVertices,polygonVertexCount);
  if ((batchClipCodes & 0xff00) != 0) {
    return;
  }
  texturingEnabled = texEnableBitsThenCullResult != 0;
  f1AfterHookCall = f1AfterCall;
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
    f1AfterHookCall = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, polygonVertices, polygonVertexCount);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    f1AfterHookCall = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, polygonVertices, polygonVertexCount);
  }
  if (lightingEnabled) {
LAB_000eda38:
    f1AfterHookCall = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, polygonVertices, polygonVertexCount);
LAB_000eda50:
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e5) != '\0')) {
      f1AfterHookCall = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, polygonVertices, polygonVertexCount);
    }
  }
  else if (texturingEnabled) {
    if (*(char *)(glContext + 0x53e6) != '\0') goto LAB_000eda38;
    goto LAB_000eda50;
  }
  if (((batchClipCodes & 0xff) != 0) || (*(char *)(glContext + 0x4e18) != '\0')) {
    if (texturingEnabled) {
      f1AfterHookCall = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, polygonVertices, polygonVertexCount, 0);
    }
    polygonList = *(int **)(glContext + 0x4870);
    spareList = *(int **)(glContext + 0x4874);
    polygonListCursor = polygonList;
    remainingThenCullResult = polygonVertexCount;
    if (0 < polygonVertexCount) {
      do {
        *polygonListCursor = (int)polygonVertices;
        polygonVertices = polygonVertices + 0x40;
        remainingThenCullResult = remainingThenCullResult + -1;
        polygonListCursor = polygonListCursor + 1;
      } while (remainingThenCullResult != 0);
    }
    planeClipRan = 0;
    clipOutputList = spareList;
    if (*(char *)(glContext + 0x4e18) != '\0') {
      ((double (*)())_gleClipPolyPlane)(glContext,polygonList,polygonVertexCount,spareList,&clippedVertexCount,f1AfterHookCall,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
                        incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90);
      if (clippedVertexCount == 0) {
        return;
      }
      planeClipRan = 1;
      clipOutputList = polygonList;
      polygonVertexCount = clippedVertexCount;
      polygonList = spareList;
    }
    polygonVertices = polygonList;
    if ((batchClipCodes & 0xff) != 0) {
      _gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,clipOutputList,&clippedVertexCount,planeClipRan);
      if (clippedVertexCount == 0) {
        return;
      }
      if (0 < clippedVertexCount) {
        polygonVertexCount = clippedVertexCount;
        polygonVertices = clipOutputList;
      }
    }
    if ((faceTestNeeded != '\0') &&
       (remainingThenCullResult = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonVertices,polygonVertexCount,backFacing), remainingThenCullResult != 0)) {
      return;
    }
    if (twoSidedLighting) {
      faceLightFunc = *(code **)(backFacing[0] * 4 + glContext + 0x4df0);
LAB_000edbbc:
      (*faceLightFunc)(glContext,polygonVertices,polygonVertexCount);
    }
    else if (lightingEnabled) {
      faceLightFunc = *(code **)(glContext + 0x4df0);
      goto LAB_000edbbc;
    }
    if (backFacing[0] == 0) {
      facePolygonMode = *(ushort *)(glContext + 0x34d0);
    }
    else {
      facePolygonMode = *(ushort *)(glContext + 0x34d2);
    }
    polygonModeIndex = facePolygonMode - 0x1b00;
    if ((*(char *)(glContext + 0x4a18) != '\0') && (polygonModeIndex == 1)) {
      polygonModeIndex = 3;
    }
    drawPolygonFunc = *(code **)(glContext + 0x46e0);
    goto LAB_000edcd4;
  }
  if ((faceTestNeeded != '\0') &&
     (texEnableBitsThenCullResult = ((int (*)())_gleCullPolygonStack)(glContext,polygonVertices,polygonVertexCount,0,backFacing), texEnableBitsThenCullResult != 0)) {
    return;
  }
  if (texturingEnabled) {
    (**(code **)(glContext + 0x506c))(glContext,polygonVertices,polygonVertexCount,0);
  }
  if (twoSidedLighting) {
    faceLightFunc = *(code **)(backFacing[0] * 4 + glContext + 0x4de8);
LAB_000edc8c:
    (*faceLightFunc)(glContext,polygonVertices,polygonVertexCount);
  }
  else if (lightingEnabled) {
    faceLightFunc = *(code **)(glContext + 0x4de8);
    goto LAB_000edc8c;
  }
  if (backFacing[0] == 0) {
    facePolygonMode = *(ushort *)(glContext + 0x34d0);
  }
  else {
    facePolygonMode = *(ushort *)(glContext + 0x34d2);
  }
  polygonModeIndex = facePolygonMode - 0x1b00;
  if ((*(char *)(glContext + 0x4a18) != '\0') && (polygonModeIndex == 1)) {
    polygonModeIndex = 3;
  }
  drawPolygonFunc = *(code **)(glContext + 0x46c0);
LAB_000edcd4:
  (*drawPolygonFunc)(*(undefined4 *)(glContext + 0x4688),polygonVertices,polygonVertexCount,polygonModeIndex);
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
  int *polygonListCursor;
  int *clipOutputList;
  int texEnableBitsThenCullResultThenRemaining;
  int polygonModeIndex;
  int lightFuncTableOffset;
  uint batchClipCodes;
  undefined4 computeClipCodes;
  code *drawPolygonFunc;
  int *spareList;
  char lightingPending;
  int *polygonList;
  int *polygonVertices;
  int polygonVertexCount;
  double f1AfterCall;
  double lastCalleeF1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  int clippedVertexCount;
  int backFacing [3];
  
  backFacing[0] = 0;
  texEnableBitsThenCullResultThenRemaining = _gleTexEnableBits(glContext);
  lightingPending = *(char *)(glContext + 0x30aa);
  twoSidedLighting = false;
  lightingEnabled = lightingPending != '\0';
  if ((lightingEnabled) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  polygonVertices = *(int **)(glContext + 0x4854);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  polygonVertexCount = *(int *)(glContext + 0x4858) - (int)polygonVertices >> 8;
  if ((2 < polygonVertexCount) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,polygonVertices,polygonVertexCount), (batchClipCodes & 0xff00) == 0)) {
    texturingEnabled = texEnableBitsThenCullResultThenRemaining != 0;
    lastCalleeF1 = f1AfterCall;
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
      lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, polygonVertices, polygonVertexCount);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, polygonVertices, polygonVertexCount);
    }
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e6) != '\0') {
        lightingPending = '\0';
        lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, polygonVertices, polygonVertexCount);
      }
      if (*(char *)(glContext + 0x53e5) != '\0') {
        lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, polygonVertices, polygonVertexCount);
      }
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if ((faceTestNeeded != '\0') &&
         (texEnableBitsThenCullResultThenRemaining = ((int (*)())_gleCullPolygonStack)(glContext,polygonVertices,polygonVertexCount,0,backFacing), texEnableBitsThenCullResultThenRemaining != 0)) {
        return;
      }
      if (texturingEnabled) {
        (**(code **)(glContext + 0x506c))(glContext,polygonVertices,polygonVertexCount,0);
      }
      if (lightingPending != '\0') {
        (**(code **)(glContext + 0x5068))(glContext,polygonVertices,1);
      }
      if (lightingEnabled) {
        lightFuncTableOffset = 0x4de0;
        if (twoSidedLighting) {
          lightFuncTableOffset = backFacing[0] * 4 + 0x4de0;
        }
        (**(code **)(glContext + lightFuncTableOffset + 8))(glContext,polygonVertices,1);
      }
      if (backFacing[0] == 0) {
        facePolygonMode = *(ushort *)(glContext + 0x34d0);
      }
      else {
        facePolygonMode = *(ushort *)(glContext + 0x34d2);
      }
      polygonModeIndex = facePolygonMode - 0x1b00;
      if ((*(char *)(glContext + 0x4a18) != '\0') && (polygonModeIndex == 1)) {
        polygonModeIndex = 3;
      }
      drawPolygonFunc = *(code **)(glContext + 0x46c0);
    }
    else {
      if (texturingEnabled) {
        lastCalleeF1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, polygonVertices, polygonVertexCount, 0);
      }
      polygonList = *(int **)(glContext + 0x4870);
      spareList = *(int **)(glContext + 0x4874);
      polygonListCursor = polygonList;
      texEnableBitsThenCullResultThenRemaining = polygonVertexCount;
      if (0 < polygonVertexCount) {
        do {
          *polygonListCursor = (int)polygonVertices;
          polygonVertices = polygonVertices + 0x40;
          texEnableBitsThenCullResultThenRemaining = texEnableBitsThenCullResultThenRemaining + -1;
          polygonListCursor = polygonListCursor + 1;
        } while (texEnableBitsThenCullResultThenRemaining != 0);
      }
      computeClipCodes = 0;
      clipOutputList = spareList;
      if (*(char *)(glContext + 0x4e18) != '\0') {
        ((double (*)())_gleClipPolyPlane)(glContext,polygonList,polygonVertexCount,spareList,&clippedVertexCount,lastCalleeF1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
                          incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90);
        if (clippedVertexCount == 0) {
          return;
        }
        computeClipCodes = 1;
        clipOutputList = polygonList;
        polygonVertexCount = clippedVertexCount;
        polygonList = spareList;
      }
      polygonVertices = polygonList;
      if ((batchClipCodes & 0xff) != 0) {
        _gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,clipOutputList,&clippedVertexCount,computeClipCodes);
        if (clippedVertexCount == 0) {
          return;
        }
        if (0 < clippedVertexCount) {
          polygonVertexCount = clippedVertexCount;
          polygonVertices = clipOutputList;
        }
      }
      if ((faceTestNeeded != '\0') &&
         (texEnableBitsThenCullResultThenRemaining = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonVertices,polygonVertexCount,backFacing), texEnableBitsThenCullResultThenRemaining != 0)) {
        return;
      }
      if (lightingPending != '\0') {
        (**(code **)(glContext + 0x5068))(glContext,*polygonVertices,1);
      }
      if (lightingEnabled) {
        lightFuncTableOffset = 0x4de0;
        if (twoSidedLighting) {
          lightFuncTableOffset = backFacing[0] * 4 + 0x4de0;
        }
        (**(code **)(glContext + lightFuncTableOffset + 8))(glContext,*polygonVertices,1);
      }
      if (backFacing[0] == 0) {
        facePolygonMode = *(ushort *)(glContext + 0x34d0);
      }
      else {
        facePolygonMode = *(ushort *)(glContext + 0x34d2);
      }
      polygonModeIndex = facePolygonMode - 0x1b00;
      if ((*(char *)(glContext + 0x4a18) != '\0') && (polygonModeIndex == 1)) {
        polygonModeIndex = 3;
      }
      drawPolygonFunc = *(code **)(glContext + 0x46e0);
    }
    (*drawPolygonFunc)(*(undefined4 *)(glContext + 0x4688),polygonVertices,polygonVertexCount,polygonModeIndex);
  }
  return;
}

/* _gleRenderSmoothTrianglesFunc_body @ 0xee104 (1140 bytes) */
void _gleRenderSmoothTrianglesFunc_body(glContext)
  int glContext;
{
  bool facingChanged;
  bool texturingEnabled;
  bool lightingActive;
  byte lightingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  uint *newPolygonList;
  int texEnableBitsThenRunCountThenCullResultThenBackFacing;
  uint lastTriangleStart;
  uint batchClipCodes;
  code *lightingFunc;
  int previousBackFacingThenPolygonVertexCount;
  uint *spareList;
  uint *oldPolygonList;
  uint *polygonList;
  uint runStart;
  uint vertexCursor;
  uint nextRunStartThenLastTriangleStart;
  int cullResult;
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
  double incomingStackWord_ffffff88;
  double incomingStackWord_ffffff90;
  int backFacing;
  int clipCount [3];
  
  previousBackFacingThenPolygonVertexCount = -1;
  texEnableBitsThenRunCountThenCullResultThenBackFacing = _gleTexEnableBits(glContext);
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
  texturingEnabled = texEnableBitsThenRunCountThenCullResultThenBackFacing != 0;
  forwardedFloatArg1 = f1AfterCall;
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
    forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, vertexCount);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCount);
  }
  lightingActive = (int)-(uint)lightingEnabled < 0;
  if (lightingActive) {
LAB_000ee1fc:
    forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, vertexCount);
  }
  else {
    if (!texturingEnabled) goto LAB_000ee23c;
    if (*(char *)(glContext + 0x53e6) != '\0') goto LAB_000ee1fc;
  }
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e5) != '\0')) {
    forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, vertexCursor, vertexCount);
  }
LAB_000ee23c:
  if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (texturingEnabled) {
      forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCount, 0);
    }
    if (faceTestNeeded == '\0') {
      if (lightingActive) {
        (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,vertexCount);
      }
      (**(code **)(glContext + 0x46c4))
                (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCount,
                 *(ushort *)(glContext + 0x34d0) - 0x1b00);
    }
    else {
      lastTriangleStart = (vertexCursor + vertexCount * 0x100) - 0x300;
      do {
        facingChanged = false;
        texEnableBitsThenRunCountThenCullResultThenBackFacing = 0;
        runStart = vertexCursor;
        nextRunStartThenLastTriangleStart = vertexCursor;
        if (vertexCursor <= lastTriangleStart) {
          do {
            cullResult = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x200,0,&backFacing,
                                      forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                      incomingStackWord_ffffff88,incomingStackWord_ffffff90);
            forwardedFloatArg1 = forwardedFloatArg1;
            if (cullResult == 0) {
              if (previousBackFacingThenPolygonVertexCount != backFacing) {
                facingChanged = true;
              }
              if ((facingChanged) && (nextRunStartThenLastTriangleStart = vertexCursor, 0 < texEnableBitsThenRunCountThenCullResultThenBackFacing)) break;
              texEnableBitsThenRunCountThenCullResultThenBackFacing = texEnableBitsThenRunCountThenCullResultThenBackFacing + 3;
              previousBackFacingThenPolygonVertexCount = backFacing;
              nextRunStartThenLastTriangleStart = runStart;
            }
            else {
              nextRunStartThenLastTriangleStart = vertexCursor + 0x300;
              if (0 < texEnableBitsThenRunCountThenCullResultThenBackFacing) break;
            }
            vertexCursor = vertexCursor + 0x300;
            runStart = nextRunStartThenLastTriangleStart;
            nextRunStartThenLastTriangleStart = vertexCursor;
          } while (vertexCursor <= lastTriangleStart);
          if (2 < texEnableBitsThenRunCountThenCullResultThenBackFacing) {
            if (twoSidedLighting) {
              lightingFunc = *(code **)(previousBackFacingThenPolygonVertexCount * 4 + glContext + 0x4de8);
LAB_000ee37c:
              (*lightingFunc)(glContext,runStart,texEnableBitsThenRunCountThenCullResultThenBackFacing);
            }
            else if (lightingActive) {
              lightingFunc = *(code **)(glContext + 0x4de8);
              goto LAB_000ee37c;
            }
            if (previousBackFacingThenPolygonVertexCount == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46c4))
                                       (*(undefined4 *)(glContext + 0x4688), runStart, texEnableBitsThenRunCountThenCullResultThenBackFacing, facePolygonMode - 0x1b00);
          }
        }
        vertexCursor = nextRunStartThenLastTriangleStart;
      } while (nextRunStartThenLastTriangleStart <= lastTriangleStart);
    }
  }
  else {
    if (texturingEnabled) {
      forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCount, 0);
    }
    polygonList = *(uint **)(glContext + 0x4870);
    spareList = *(uint **)(glContext + 0x4874);
    nextRunStartThenLastTriangleStart = (vertexCursor + vertexCount * 0x100) - 0x300;
    if (vertexCursor <= nextRunStartThenLastTriangleStart) {
      do {
        polygonList[1] = vertexCursor + 0x100;
        polygonList[2] = vertexCursor + 0x200;
        *polygonList = vertexCursor;
        *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
        oldPolygonList = spareList;
        newPolygonList = polygonList;
        previousBackFacingThenPolygonVertexCount = 3;
        if ((*(char *)(glContext + 0x4e18) == '\0') ||
           (forwardedFloatArg1 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,clipCount,forwardedFloatArg1,incomingFpr2,incomingFpr3
                                               ,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStackWord_ffffff88,
                                               incomingStackWord_ffffff90), oldPolygonList = polygonList,
           newPolygonList = spareList, previousBackFacingThenPolygonVertexCount = clipCount[0], clipCount[0] != 0)) {
          polygonList = newPolygonList;
          spareList = oldPolygonList;
          if ((batchClipCodes & 0xff) != 0) {
            forwardedFloatArg1 = (double)_gleClipPoly(glContext,polygonList,previousBackFacingThenPolygonVertexCount,batchClipCodes & 0xff,oldPolygonList,clipCount,1);
            if (clipCount[0] == 0) goto LAB_000ee550;
            if (0 < clipCount[0]) {
              spareList = polygonList;
              polygonList = oldPolygonList;
              previousBackFacingThenPolygonVertexCount = clipCount[0];
            }
          }
          if ((faceTestNeeded == '\0') ||
             (texEnableBitsThenRunCountThenCullResultThenBackFacing = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,previousBackFacingThenPolygonVertexCount,&backFacing),
             forwardedFloatArg1 = f1AfterCall2, texEnableBitsThenRunCountThenCullResultThenBackFacing == 0)) {
            texEnableBitsThenRunCountThenCullResultThenBackFacing = backFacing;
            if (twoSidedLighting) {
              lightingFunc = *(code **)(backFacing * 4 + glContext + 0x4df0);
LAB_000ee514:
              (*lightingFunc)(glContext,polygonList,previousBackFacingThenPolygonVertexCount);
            }
            else if (lightingActive) {
              lightingFunc = *(code **)(glContext + 0x4df0);
              goto LAB_000ee514;
            }
            if (texEnableBitsThenRunCountThenCullResultThenBackFacing == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                       (*(undefined4 *)(glContext + 0x4688), polygonList, previousBackFacingThenPolygonVertexCount, facePolygonMode - 0x1b00);
          }
        }
LAB_000ee550:
        vertexCursor = vertexCursor + 0x300;
      } while (vertexCursor <= nextRunStartThenLastTriangleStart);
    }
  }
  return;
}

/* _gleRenderFlatTrianglesFunc_body @ 0xee57c (1312 bytes) */
void _gleRenderFlatTrianglesFunc_body(glContext)
  int glContext;
{
  bool lightingEnabled;
  bool facingChanged;
  bool texturingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  uint *puVar6;
  int iVar7;
  int lightVertex;
  int texEnableBits;
  uint uVar8;
  uint batchClipCodes;
  int runLightVertex;
  int runFacing;
  int batchEnd;
  int lightedVertices;
  uint *spareList;
  uint *puVar12;
  int runLightedVertices;
  char lightingPending;
  uint runStart;
  uint *polygonList;
  int vertexCount;
  int lightFuncIndex;
  int cullResult;
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
  
  runFacing = -1;
  texEnableBits = _gleTexEnableBits(glContext);
  lightingPending = *(char *)(glContext + 0x30aa);
  twoSidedLighting = false;
  lightingEnabled = lightingPending != '\0';
  if ((lightingEnabled) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  triangleCursor = *(uint *)(glContext + 0x4854);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  vertexCount = (int)(*(int *)(glContext + 0x4858) - triangleCursor) >> 8;
  if ((2 < vertexCount) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,triangleCursor,vertexCount), (batchClipCodes & 0xff00) == 0)) {
    texturingEnabled = texEnableBits != 0;
    dVar20 = f1AfterCall;
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
      dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, triangleCursor, vertexCount);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, triangleCursor, vertexCount);
    }
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e6) != '\0') {
        lightingPending = '\0';
        dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, triangleCursor, vertexCount);
      }
      if (*(char *)(glContext + 0x53e5) != '\0') {
        dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, triangleCursor, vertexCount);
      }
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (texturingEnabled) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, triangleCursor, vertexCount, 0);
      }
      if (faceTestNeeded == '\0') {
        if (lightingEnabled) {
          lightedVertices = 0;
          if (-1 < vertexCount + -3) {
            lightVertex = triangleCursor + 0x200;
            do {
              if (lightingPending != '\0') {
                (**(code **)(glContext + 0x5068))(glContext,lightVertex,1);
              }
              lightedVertices = lightedVertices + 3;
              (**(code **)(glContext + 0x4de8))(glContext,lightVertex,1);
              lightVertex = lightVertex + 0x300;
            } while (lightedVertices <= vertexCount + -3);
          }
        }
        (**(code **)(glContext + 0x46c4))
                  (*(undefined4 *)(glContext + 0x4688),triangleCursor,vertexCount,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        uVar8 = (triangleCursor + vertexCount * 0x100) - 0x300;
        do {
          iVar7 = 0;
          facingChanged = false;
          runStart = triangleCursor;
          uVar19 = triangleCursor;
          if (triangleCursor <= uVar8) {
            do {
              cullResult = ((undefined4 (*)())_gleCullTriangle)(glContext,triangleCursor,triangleCursor + 0x100,triangleCursor + 0x200,0,&backFacing,
                                        dVar20,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                        incomingStack_ffffff78,incomingStack_ffffff80);
              dVar20 = dVar20;
              if (cullResult == 0) {
                if (runFacing != backFacing) {
                  facingChanged = true;
                }
                if ((facingChanged) && (uVar19 = triangleCursor, 0 < iVar7)) break;
                iVar7 = iVar7 + 3;
                runFacing = backFacing;
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
                lightFuncIndex = runFacing;
                if (!twoSidedLighting) {
                  lightFuncIndex = 0;
                }
                runLightedVertices = 0;
                if (-1 < iVar7 + -3) {
                  runLightVertex = runStart + 0x200;
                  do {
                    if (lightingPending != '\0') {
                      (**(code **)(glContext + 0x5068))(glContext,runLightVertex,1);
                    }
                    runLightedVertices = runLightedVertices + 3;
                    (**(code **)(lightFuncIndex * 4 + glContext + 0x4de8))(glContext,runLightVertex,1);
                    runLightVertex = runLightVertex + 0x300;
                  } while (runLightedVertices <= iVar7 + -3);
                }
              }
              if (runFacing == 0) {
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
        dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, triangleCursor, vertexCount, 0);
      }
      polygonList = *(uint **)(glContext + 0x4870);
      batchEnd = triangleCursor + vertexCount * 0x100;
      spareList = *(uint **)(glContext + 0x4874);
      for (; triangleCursor <= batchEnd - 0x300U; triangleCursor = triangleCursor + 0x300) {
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
             (vertexCount = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,iVar7,&backFacing),
             dVar20 = f1AfterCall2, vertexCount == 0)) {
            if (lightingPending != '\0') {
              (**(code **)(glContext + 0x5068))(glContext,uVar19,1);
            }
            if (lightingEnabled) {
              vertexCount = 0x4de0;
              if (twoSidedLighting) {
                vertexCount = backFacing * 4 + 0x4de0;
              }
              (**(code **)(glContext + vertexCount + 8))(glContext,uVar19,1);
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
  bool orientationChanged;
  bool windingFlip;
  bool texturingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  uint runStart;
  uint *nextPolygonList;
  int lightFaceIndex;
  int texEnableBits;
  int runTriangleCount;
  int triangleCount;
  uint carriedParity;
  uint batchClipCodes;
  uint stripParity;
  uint drawStart;
  uint runStartParity;
  uint lastTriangleStartClip;
  int *firstTrianglePolygon;
  int iVar14;
  int polygonVertexCount;
  uint lastTriangleStart;
  uint nextCursor;
  uint nextRunStart;
  uint *spareList;
  uint *nextSpareList;
  char lightingPending;
  int remaining;
  uint vertexCursor;
  uint nextVertexCursor;
  int runLitVertex;
  uint *polygonList;
  int cullResult;
  int runVertexCount;
  int vertexCount;
  double f1AfterCall;
  double lastCalleeF1;
  double f1AfterCall1;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStackWord_ffffff78;
  double incomingStackWord_ffffff80;
  int backFacing;
  int clippedVertexCount [5];
  
  iVar14 = -1;
  texEnableBits = _gleTexEnableBits(glContext);
  lightingPending = *(char *)(glContext + 0x30aa);
  twoSidedLighting = false;
  lightingEnabled = lightingPending != '\0';
  if ((lightingEnabled) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  vertexCursor = *(uint *)(glContext + 0x4854);
  runStartParity = 0;
  faceTestNeeded = *(char *)(glContext + 0x34de);
  vertexCount = (int)(*(int *)(glContext + 0x4858) - vertexCursor) >> 8;
  if ((2 < vertexCount) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount), (batchClipCodes & 0xff00) == 0)) {
    texturingEnabled = texEnableBits != 0;
    lastCalleeF1 = f1AfterCall;
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
      lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, vertexCount);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCount);
    }
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e6) != '\0') {
        lightingPending = '\0';
        lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, vertexCount);
      }
      if (*(char *)(glContext + 0x53e5) != '\0') {
        lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, vertexCursor, vertexCount);
      }
    }
    if (lightingPending != '\0') {
      lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor + 0x200, vertexCount + -2);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (texturingEnabled) {
        lastCalleeF1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCount, 0);
      }
      if (faceTestNeeded == '\0') {
        if ((lightingEnabled) && (-1 < vertexCount + -3)) {
          triangleCount = vertexCount + -2;
          iVar14 = vertexCursor + 0x200;
          do {
            (**(code **)(glContext + 0x4de8))(glContext,iVar14,1);
            triangleCount = triangleCount + -1;
            iVar14 = iVar14 + 0x100;
          } while (triangleCount != 0);
        }
        (**(code **)(glContext + 0x46cc))
                  (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCount,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        firstTrianglePolygon = *(int **)(glContext + 0x4870);
        lastTriangleStart = (vertexCursor + vertexCount * 0x100) - 0x300;
        carriedParity = 0;
        do {
          runTriangleCount = 0;
          orientationChanged = false;
          stripParity = carriedParity;
          runStart = vertexCursor;
          while (carriedParity = stripParity, vertexCursor <= lastTriangleStart) {
            nextVertexCursor = vertexCursor + 0x100;
            cullResult = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,nextVertexCursor,vertexCursor + 0x200,stripParity,&backFacing,lastCalleeF1,
                                      incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStackWord_ffffff78,
                                      incomingStackWord_ffffff80);
            lastCalleeF1 = f1AfterCall1;
            if (cullResult == 0) {
              if (iVar14 != backFacing) {
                orientationChanged = true;
              }
              if ((orientationChanged) && (0 < runTriangleCount)) break;
              if (runTriangleCount == 0) {
                runStartParity = stripParity;
              }
              runTriangleCount = runTriangleCount + 1;
              iVar14 = backFacing;
              nextRunStart = runStart;
            }
            else {
              nextRunStart = nextVertexCursor;
              carriedParity = stripParity ^ 1;
              vertexCursor = nextVertexCursor;
              if (0 < runTriangleCount) break;
            }
            stripParity = stripParity ^ 1;
            vertexCursor = nextVertexCursor;
            runStart = nextRunStart;
          }
          runVertexCount = runTriangleCount + 2;
          if (2 < runVertexCount) {
            if (lightingEnabled) {
              lightFaceIndex = iVar14;
              if (!twoSidedLighting) {
                lightFaceIndex = 0;
              }
              if (-1 < runTriangleCount + -1) {
                remaining = runTriangleCount;
                runLitVertex = runStart + 0x200;
                do {
                  (**(code **)(lightFaceIndex * 4 + glContext + 0x4de8))(glContext,runLitVertex,1);
                  remaining = remaining + -1;
                  runLitVertex = runLitVertex + 0x100;
                } while (remaining != 0);
              }
            }
            drawStart = runStart;
            if (runStartParity != 0) {
              drawStart = runStart + 0x100;
              *firstTrianglePolygon = runStart + 0x200;
              firstTrianglePolygon[2] = runStart;
              firstTrianglePolygon[1] = drawStart;
              if (iVar14 != 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              runVertexCount = runTriangleCount + 1;
              lastCalleeF1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), firstTrianglePolygon, 3, facePolygonMode - 0x1b00);
              if (runVertexCount < 3) goto LAB_000ef3cc;
            }
            if (iVar14 != 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            lastCalleeF1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46cc))
                                       (*(undefined4 *)(glContext + 0x4688), drawStart, runVertexCount, facePolygonMode - 0x1b00);
          }
LAB_000ef3cc: ;
        } while (vertexCursor <= lastTriangleStart);
      }
    }
    else {
      if (texturingEnabled) {
        lastCalleeF1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCount, 0);
      }
      lastTriangleStartClip = (vertexCursor + vertexCount * 0x100) - 0x300;
      spareList = *(uint **)(glContext + 0x4874);
      polygonList = *(uint **)(glContext + 0x4870);
      if (vertexCursor <= lastTriangleStartClip) {
        windingFlip = false;
        do {
          windingFlip = !windingFlip;
          if (windingFlip) {
            *polygonList = vertexCursor;
            polygonList[1] = vertexCursor + 0x100;
            polygonList[2] = vertexCursor + 0x200;
          }
          else {
            polygonList[2] = vertexCursor;
            *polygonList = vertexCursor + 0x200;
            polygonList[1] = vertexCursor + 0x100;
          }
          nextCursor = vertexCursor + 0x100;
          *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
          nextSpareList = spareList;
          nextPolygonList = polygonList;
          polygonVertexCount = 3;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (lastCalleeF1 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,clippedVertexCount,lastCalleeF1,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStackWord_ffffff78,incomingStackWord_ffffff80),
             nextSpareList = polygonList, nextPolygonList = spareList, polygonVertexCount = clippedVertexCount[0], clippedVertexCount[0] != 0)) {
            polygonList = nextPolygonList;
            spareList = nextSpareList;
            if ((batchClipCodes & 0xff) != 0) {
              lastCalleeF1 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,nextSpareList,clippedVertexCount,1)
              ;
              if (clippedVertexCount[0] == 0) goto LAB_000ef59c;
              if (0 < clippedVertexCount[0]) {
                spareList = polygonList;
                polygonList = nextSpareList;
                polygonVertexCount = clippedVertexCount[0];
              }
            }
            if ((faceTestNeeded == '\0') ||
               (texEnableBits = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing),
               lastCalleeF1 = f1AfterCall2, texEnableBits == 0)) {
              if (lightingEnabled) {
                texEnableBits = 0x4de0;
                if (twoSidedLighting) {
                  texEnableBits = backFacing * 4 + 0x4de0;
                }
                (**(code **)(glContext + texEnableBits + 8))(glContext,vertexCursor + 0x200,1);
              }
              *(undefined8 *)(*polygonList + 0x30) = *(undefined8 *)(vertexCursor + 0x230);
              *(undefined8 *)(*polygonList + 0x38) = *(undefined8 *)(vertexCursor + 0x238);
              if (backFacing == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              lastCalleeF1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                         (*(undefined4 *)(glContext + 0x4688), polygonList, polygonVertexCount, facePolygonMode - 0x1b00);
            }
          }
LAB_000ef59c:
          vertexCursor = nextCursor;
        } while (nextCursor <= lastTriangleStartClip);
      }
    }
  }
  return;
}

/* _gleRenderSmoothTriangleFanFunc_body @ 0xef5f4 (1300 bytes) */
void _gleRenderSmoothTriangleFanFunc_body(glContext)
  int glContext;
{
  bool orientationChanged;
  bool texturingEnabled;
  bool bVar2;
  byte lightingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  uint runRimStart;
  int iVar8;
  uint rimCursor;
  uint batchClipCodes;
  int cullResultThenBackFacing;
  int *nextSpareList;
  int *polygonVertexCursor;
  code *faceLightFunc;
  int runBackFacing;
  int remaining;
  int *spareList;
  uint clipRimCursor;
  uint lastRimStart;
  int vertexCursor;
  int *nextPolygonList;
  int *polygonList;
  int vertexCount;
  int faceTableBase;
  int cullResult;
  uint clipRimNext;
  uint nextRimVertex;
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
  int clippedVertexCount [4];
  
  runBackFacing = -1;
  iVar8 = _gleTexEnableBits(glContext);
  lightingEnabled = *(byte *)(glContext + 0x30aa);
  twoSidedLighting = false;
  if ((lightingEnabled != 0) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  vertexCursor = *(int *)(glContext + 0x4854);
  faceTestNeeded = *(char *)(glContext + 0x34de);
  vertexCount = *(int *)(glContext + 0x4858) - vertexCursor >> 8;
  if (vertexCount < 3) {
    return;
  }
  batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount);
  if ((batchClipCodes & 0xff00) != 0) {
    return;
  }
  texturingEnabled = iVar8 != 0;
  dVar21 = f1AfterCall;
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
    dVar21 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, vertexCount);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    dVar21 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCount);
  }
  bVar2 = (int)-(uint)lightingEnabled < 0;
  if (bVar2) {
LAB_000ef6ec:
    dVar21 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, vertexCount);
  }
  else {
    if (!texturingEnabled) goto LAB_000ef72c;
    if (*(char *)(glContext + 0x53e6) != '\0') goto LAB_000ef6ec;
  }
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e5) != '\0')) {
    dVar21 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, vertexCursor, vertexCount);
  }
LAB_000ef72c:
  if (((batchClipCodes & 0xff) != 0) || (*(char *)(glContext + 0x4e18) != '\0')) {
    if (texturingEnabled) {
      dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCount, 0);
    }
    orientationChanged = false;
    clipRimCursor = vertexCursor + 0x100;
    polygonList = *(int **)(glContext + 0x4870);
    spareList = *(int **)(glContext + 0x4874);
joined_r0x000ef960:
    do {
      if ((vertexCursor + vertexCount * 0x100) - 0x200U < clipRimCursor) {
        return;
      }
      clipRimNext = clipRimCursor + 0x100;
      *polygonList = vertexCursor;
      polygonList[1] = clipRimCursor;
      polygonList[2] = clipRimNext;
      *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
      nextSpareList = spareList;
      nextPolygonList = polygonList;
      iVar8 = 3;
      clipRimCursor = clipRimNext;
    } while ((*(char *)(glContext + 0x4e18) != '\0') &&
            (dVar21 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,clippedVertexCount,dVar21,incomingFpr2,
                                                incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                incomingStack_ffffff78,incomingStack_ffffff80),
            nextSpareList = polygonList, nextPolygonList = spareList, iVar8 = clippedVertexCount[0], clippedVertexCount[0] == 0));
    spareList = nextSpareList;
    polygonList = nextPolygonList;
    if ((batchClipCodes & 0xff) != 0) goto code_r0x000ef9c8;
    goto LAB_000efa08;
  }
  if (texturingEnabled) {
    dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCount, 0);
  }
  if (faceTestNeeded == '\0') {
    if (bVar2) {
      (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,vertexCount);
    }
    (**(code **)(glContext + 0x46c8))
              (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCursor + 0x100,vertexCount + -1,
               *(ushort *)(glContext + 0x34d0) - 0x1b00);
  }
  else {
    rimCursor = vertexCursor + 0x100;
    lastRimStart = (vertexCursor + vertexCount * 0x100) - 0x200;
    do {
      orientationChanged = false;
      iVar8 = 0;
      nextRimVertex = rimCursor;
      do {
        while( true ) {
          runRimStart = nextRimVertex;
          if (lastRimStart < rimCursor) goto LAB_000ef844;
          nextRimVertex = rimCursor + 0x100;
          cullResult = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,rimCursor,nextRimVertex,0,&backFacing,dVar21,incomingFpr2,incomingFpr3,incomingFpr4
                                    ,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,incomingStack_ffffff80);
          dVar21 = f1AfterCall1;
          if (cullResult != 0) break;
          if (runBackFacing != backFacing) {
            orientationChanged = true;
          }
          if ((orientationChanged) && (0 < iVar8)) goto LAB_000ef844;
          iVar8 = iVar8 + 1;
          runBackFacing = backFacing;
          rimCursor = nextRimVertex;
          nextRimVertex = runRimStart;
        }
        rimCursor = nextRimVertex;
      } while (iVar8 < 1);
LAB_000ef844:
      iVar8 = iVar8 + 1;
      if (1 < iVar8) {
        if (twoSidedLighting) {
          if (orientationChanged) {
            *(byte *)(vertexCursor + 0x7e) = *(byte *)(vertexCursor + 0x7e) | 6;
            *(byte *)(runRimStart + 0x7e) = *(byte *)(runRimStart + 0x7e) | 6;
          }
          faceTableBase = runBackFacing * 4 + glContext;
          (**(code **)(faceTableBase + 0x4de8))(glContext,vertexCursor,1);
          faceLightFunc = *(code **)(faceTableBase + 0x4de8);
LAB_000ef8d8:
          (*faceLightFunc)(glContext,runRimStart,iVar8);
        }
        else if (bVar2) {
          (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,1);
          faceLightFunc = *(code **)(glContext + 0x4de8);
          goto LAB_000ef8d8;
        }
        if (runBackFacing == 0) {
          facePolygonMode = *(ushort *)(glContext + 0x34d0);
        }
        else {
          facePolygonMode = *(ushort *)(glContext + 0x34d2);
        }
        dVar21 = (double)(**(double ( **)(int,int,int,int,int))(glContext + 0x46c8))
                                   (*(undefined4 *)(glContext + 0x4688), vertexCursor, runRimStart, iVar8, facePolygonMode - 0x1b00);
      }
    } while (rimCursor <= lastRimStart);
  }
  return;
code_r0x000ef9c8:
  dVar21 = (double)_gleClipPoly(glContext,nextPolygonList,iVar8,batchClipCodes & 0xff,nextSpareList,clippedVertexCount,1);
  if (clippedVertexCount[0] == 0) goto joined_r0x000ef960;
  if (0 < clippedVertexCount[0]) {
    spareList = nextPolygonList;
    polygonList = nextSpareList;
    iVar8 = clippedVertexCount[0];
  }
LAB_000efa08:
  if ((faceTestNeeded != '\0') &&
     (cullResultThenBackFacing = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,iVar8,&backFacing), dVar21 = f1AfterCall2,
     cullResultThenBackFacing != 0)) goto joined_r0x000ef960;
  cullResultThenBackFacing = backFacing;
  if (runBackFacing != backFacing) {
    orientationChanged = true;
  }
  if (twoSidedLighting) {
    if (orientationChanged) {
      polygonVertexCursor = polygonList;
      remaining = iVar8;
      if (0 < iVar8) {
        do {
          *(byte *)(*polygonVertexCursor + 0x7e) = *(byte *)(*polygonVertexCursor + 0x7e) | 6;
          remaining = remaining + -1;
          polygonVertexCursor = polygonVertexCursor + 1;
        } while (remaining != 0);
      }
      orientationChanged = false;
    }
    faceLightFunc = *(code **)(backFacing * 4 + glContext + 0x4df0);
  }
  else {
    if (!bVar2) goto LAB_000efab0;
    faceLightFunc = *(code **)(glContext + 0x4df0);
  }
  (*faceLightFunc)(glContext,polygonList,iVar8);
LAB_000efab0:
  if (cullResultThenBackFacing == 0) {
    facePolygonMode = *(ushort *)(glContext + 0x34d0);
  }
  else {
    facePolygonMode = *(ushort *)(glContext + 0x34d2);
  }
  dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                             (*(undefined4 *)(glContext + 0x4688), polygonList, iVar8, facePolygonMode - 0x1b00);
  runBackFacing = cullResultThenBackFacing;
  goto joined_r0x000ef960;
}

/* _gleRenderFlatTriangleFanFunc_body @ 0xefb0c (1244 bytes) */
void _gleRenderFlatTriangleFanFunc_body(glContext)
  int glContext;
{
  bool lightingEnabled;
  bool orientationChanged;
  bool texturingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  int *nextPolygonList;
  int lightFaceIndex;
  int iVar8;
  uint uVar9;
  uint batchClipCodes;
  int iVar10;
  int polygonVertexCount;
  uint lastRimStart;
  int *spareList;
  int *nextSpareList;
  int vertexCursor;
  uint uVar15;
  uint clipNextVertex;
  int *polygonList;
  int vertexCount;
  int runVertexCount;
  int cullResult;
  uint uVar18;
  uint clipRimCursor;
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
  int clippedVertexCount [6];
  
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
  vertexCount = *(int *)(glContext + 0x4858) - vertexCursor >> 8;
  if ((2 < vertexCount) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount), (batchClipCodes & 0xff00) == 0)) {
    texturingEnabled = iVar8 != 0;
    dVar20 = f1AfterCall;
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
      dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, vertexCount);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCount);
    }
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e6) != '\0') {
        lightingPending = '\0';
        dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, vertexCount);
      }
      if (*(char *)(glContext + 0x53e5) != '\0') {
        dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, vertexCursor, vertexCount);
      }
    }
    if (lightingPending != '\0') {
      dVar20 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor + 0x200, vertexCount + -2);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (texturingEnabled) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCount, 0);
      }
      if (faceTestNeeded == '\0') {
        if ((lightingEnabled) && (iVar10 = vertexCount + -2, 0 < iVar10)) {
          iVar8 = vertexCursor + 0x200;
          do {
            (**(code **)(glContext + 0x4de8))(glContext,iVar8,1);
            iVar10 = iVar10 + -1;
            iVar8 = iVar8 + 0x100;
          } while (iVar10 != 0);
        }
        (**(code **)(glContext + 0x46c8))
                  (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCursor + 0x100,vertexCount + -1,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        uVar9 = vertexCursor + 0x100;
        lastRimStart = (vertexCursor + vertexCount * 0x100) - 0x200;
        do {
          iVar8 = 0;
          orientationChanged = false;
          uVar18 = uVar9;
          do {
            while( true ) {
              uVar15 = uVar18;
              if (lastRimStart < uVar9) goto LAB_000efd88;
              uVar18 = uVar9 + 0x100;
              cullResult = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,uVar9,uVar18,0,&backFacing,dVar20,incomingFpr2,incomingFpr3,
                                        incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                        incomingStack_ffffff80);
              dVar20 = f1AfterCall1;
              if (cullResult != 0) break;
              if (iVar10 != backFacing) {
                orientationChanged = true;
              }
              if ((orientationChanged) && (0 < iVar8)) goto LAB_000efd88;
              iVar8 = iVar8 + 1;
              iVar10 = backFacing;
              uVar9 = uVar18;
              uVar18 = uVar15;
            }
            uVar9 = uVar18;
          } while (iVar8 < 1);
LAB_000efd88:
          runVertexCount = iVar8 + 1;
          if (1 < runVertexCount) {
            if (lightingEnabled) {
              lightFaceIndex = iVar10;
              if (!twoSidedLighting) {
                lightFaceIndex = 0;
              }
              if (-1 < iVar8 + -1) {
                uVar18 = uVar15;
                do {
                  uVar18 = uVar18 + 0x100;
                  (**(code **)(lightFaceIndex * 4 + glContext + 0x4de8))(glContext,uVar18,1);
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
                                       (*(undefined4 *)(glContext + 0x4688), vertexCursor, uVar15, runVertexCount, facePolygonMode - 0x1b00);
          }
        } while (uVar9 <= lastRimStart);
      }
    }
    else {
      if (texturingEnabled) {
        dVar20 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCount, 0);
      }
      polygonList = *(int **)(glContext + 0x4870);
      lastRimStart = (vertexCursor + vertexCount * 0x100) - 0x200;
      spareList = *(int **)(glContext + 0x4874);
      if (vertexCursor + 0x100U <= lastRimStart) {
        clipRimCursor = vertexCursor + 0x100U;
        do {
          clipNextVertex = clipRimCursor + 0x100;
          *polygonList = vertexCursor;
          polygonList[1] = clipRimCursor;
          polygonList[2] = clipNextVertex;
          *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
          nextSpareList = spareList;
          nextPolygonList = polygonList;
          polygonVertexCount = 3;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar20 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,clippedVertexCount,dVar20,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             nextSpareList = polygonList, nextPolygonList = spareList, polygonVertexCount = clippedVertexCount[0], clippedVertexCount[0] != 0)) {
            polygonList = nextPolygonList;
            spareList = nextSpareList;
            if ((batchClipCodes & 0xff) != 0) {
              dVar20 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,nextSpareList,clippedVertexCount,1);
              if (clippedVertexCount[0] == 0) goto LAB_000effc0;
              if (0 < clippedVertexCount[0]) {
                spareList = polygonList;
                polygonList = nextSpareList;
                polygonVertexCount = clippedVertexCount[0];
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
                (**(code **)(glContext + iVar8 + 8))(glContext,clipNextVertex,1);
              }
              *(undefined8 *)(*polygonList + 0x30) = *(undefined8 *)(clipRimCursor + 0x130);
              *(undefined8 *)(*polygonList + 0x38) = *(undefined8 *)(clipRimCursor + 0x138);
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
          clipRimCursor = clipNextVertex;
        } while (clipNextVertex <= lastRimStart);
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
  bool orientationChanged;
  bool texturingEnabled;
  char faceTestNeeded;
  ushort facePolygonMode;
  bool twoSidedLighting;
  uint *nextPolygonList;
  int texEnableBits;
  int polygonVertexCount;
  int quadLastVertex;
  uint lastQuadStart;
  uint batchClipCodes;
  int litVertex;
  int runBackFacing;
  int batchEnd;
  int litQuadCount;
  uint *spareList;
  uint *nextSpareList;
  int litVertexCount;
  char lightingPending;
  uint runStart;
  uint *polygonList;
  int vertexCount;
  int lightFaceIndex;
  int cullResult;
  uint vertexCursor;
  uint nextRunStart;
  uint quadLastVertexPtr;
  double f1AfterCall;
  double lastCalleeF1;
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
  int clippedVertexCount [6];
  
  runBackFacing = -1;
  texEnableBits = _gleTexEnableBits(glContext);
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
    texturingEnabled = texEnableBits != 0;
    lastCalleeF1 = f1AfterCall;
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
      lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, vertexCount);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCount);
    }
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e6) != '\0') {
        lightingPending = '\0';
        lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, vertexCount);
      }
      if (*(char *)(glContext + 0x53e5) != '\0') {
        lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53e0))(glContext, vertexCursor, vertexCount);
      }
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (texturingEnabled) {
        lastCalleeF1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCount, 0);
      }
      if (faceTestNeeded == '\0') {
        if (lightingEnabled) {
          litQuadCount = 0;
          if (-1 < vertexCount + -4) {
            quadLastVertex = vertexCursor + 0x300;
            do {
              if (lightingPending != '\0') {
                (**(code **)(glContext + 0x5068))(glContext,quadLastVertex,1);
              }
              litQuadCount = litQuadCount + 4;
              (**(code **)(glContext + 0x4de8))(glContext,quadLastVertex,1);
              quadLastVertex = quadLastVertex + 0x400;
            } while (litQuadCount <= vertexCount + -4);
          }
        }
        (**(code **)(glContext + 0x46d0))
                  (*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCount,
                   *(ushort *)(glContext + 0x34d0) - 0x1b00);
      }
      else {
        lastQuadStart = (vertexCursor + vertexCount * 0x100) - 0x400;
        do {
          polygonVertexCount = 0;
          orientationChanged = false;
          runStart = vertexCursor;
          nextRunStart = vertexCursor;
          if (vertexCursor <= lastQuadStart) {
            do {
              cullResult = ((undefined4 (*)())_gleCullQuad)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x200,vertexCursor + 0x300,
                                    &backFacing,lastCalleeF1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                    incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88);
              lastCalleeF1 = lastCalleeF1;
              if (cullResult == 0) {
                if (runBackFacing != backFacing) {
                  orientationChanged = true;
                }
                if ((orientationChanged) && (nextRunStart = vertexCursor, 0 < polygonVertexCount)) break;
                polygonVertexCount = polygonVertexCount + 4;
                runBackFacing = backFacing;
                nextRunStart = runStart;
              }
              else {
                nextRunStart = vertexCursor + 0x400;
                if (0 < polygonVertexCount) break;
              }
              vertexCursor = vertexCursor + 0x400;
              runStart = nextRunStart;
              nextRunStart = vertexCursor;
            } while (vertexCursor <= lastQuadStart);
            if (3 < polygonVertexCount) {
              if (lightingEnabled) {
                lightFaceIndex = runBackFacing;
                if (!twoSidedLighting) {
                  lightFaceIndex = 0;
                }
                litVertexCount = 0;
                if (-1 < polygonVertexCount + -4) {
                  litVertex = runStart + 0x300;
                  do {
                    if (lightingPending != '\0') {
                      (**(code **)(glContext + 0x5068))(glContext,litVertex,1);
                    }
                    litVertexCount = litVertexCount + 4;
                    (**(code **)(lightFaceIndex * 4 + glContext + 0x4de8))(glContext,litVertex,1);
                    litVertex = litVertex + 0x400;
                  } while (litVertexCount <= polygonVertexCount + -4);
                }
              }
              if (runBackFacing == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              lastCalleeF1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46d0))
                                         (*(undefined4 *)(glContext + 0x4688), runStart, polygonVertexCount, facePolygonMode - 0x1b00);
            }
          }
          vertexCursor = nextRunStart;
        } while (nextRunStart <= lastQuadStart);
      }
    }
    else {
      if (texturingEnabled) {
        lastCalleeF1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCount, 0);
      }
      polygonList = *(uint **)(glContext + 0x4870);
      batchEnd = vertexCursor + vertexCount * 0x100;
      spareList = *(uint **)(glContext + 0x4874);
      for (; vertexCursor <= batchEnd - 0x400U; vertexCursor = vertexCursor + 0x400) {
        quadLastVertexPtr = vertexCursor + 0x300;
        polygonList[1] = vertexCursor + 0x100;
        polygonList[2] = vertexCursor + 0x200;
        *polygonList = vertexCursor;
        polygonList[3] = quadLastVertexPtr;
        *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
        nextSpareList = spareList;
        nextPolygonList = polygonList;
        polygonVertexCount = 4;
        if ((*(char *)(glContext + 0x4e18) == '\0') ||
           (lastCalleeF1 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,clippedVertexCount,lastCalleeF1,incomingFpr2,incomingFpr3
                                               ,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                               incomingStack_ffffff80), nextSpareList = polygonList,
           nextPolygonList = spareList, polygonVertexCount = clippedVertexCount[0], clippedVertexCount[0] != 0)) {
          polygonList = nextPolygonList;
          spareList = nextSpareList;
          if ((batchClipCodes & 0xff) != 0) {
            lastCalleeF1 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,nextSpareList,clippedVertexCount,1);
            if (clippedVertexCount[0] == 0) goto LAB_000f096c;
            if (0 < clippedVertexCount[0]) {
              spareList = polygonList;
              polygonList = nextSpareList;
              polygonVertexCount = clippedVertexCount[0];
            }
          }
          if ((faceTestNeeded == '\0') ||
             (vertexCount = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing),
             lastCalleeF1 = f1AfterCall2, vertexCount == 0)) {
            if (lightingPending != '\0') {
              (**(code **)(glContext + 0x5068))(glContext,quadLastVertexPtr,1);
            }
            if (lightingEnabled) {
              vertexCount = 0x4de0;
              if (twoSidedLighting) {
                vertexCount = backFacing * 4 + 0x4de0;
              }
              (**(code **)(glContext + vertexCount + 8))(glContext,quadLastVertexPtr,1);
            }
            *(undefined8 *)(*polygonList + 0x30) = *(undefined8 *)(vertexCursor + 0x330);
            *(undefined8 *)(*polygonList + 0x38) = *(undefined8 *)(vertexCursor + 0x338);
            if (backFacing == 0) {
              facePolygonMode = *(ushort *)(glContext + 0x34d0);
            }
            else {
              facePolygonMode = *(ushort *)(glContext + 0x34d2);
            }
            lastCalleeF1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46e0))
                                       (*(undefined4 *)(glContext + 0x4688), polygonList, polygonVertexCount, facePolygonMode - 0x1b00);
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
  uint runStart;
  int iVar7;
  uint lastQuadStart;
  uint batchClipCodes;
  int litVertex;
  int iVar10;
  int polygonVertexCount;
  uint *nextSpareList;
  uint *spareList;
  char lightingPending;
  int litVertexIndex;
  uint quadLastVertexPtr;
  uint vertexCursor;
  uint uVar17;
  uint *nextPolygonList;
  uint *polygonList;
  int cullResult;
  int lightFaceIndex;
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
  double incomingStackWord_ffffff78;
  double incomingStackWord_ffffff80;
  double incomingStackWord_ffffff88;
  int backFacing;
  int clippedVertexCount [5];
  
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
        runStart = uVar17;
        if ((vertexCursor + vertexCount * 0x100) - 0x400 < runStart) {
          return;
        }
        uVar17 = runStart + 0x200;
        quadLastVertexPtr = runStart + 0x300;
        *polygonList = runStart;
        polygonList[1] = runStart + 0x100;
        polygonList[2] = quadLastVertexPtr;
        polygonList[3] = uVar17;
        *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x485c);
        nextSpareList = spareList;
        nextPolygonList = polygonList;
        polygonVertexCount = 4;
      } while ((*(char *)(glContext + 0x4e18) != '\0') &&
              (dVar21 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,clippedVertexCount,dVar21,incomingFpr2,
                                                  incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                  incomingStackWord_ffffff78,incomingStackWord_ffffff80),
              nextSpareList = polygonList, nextPolygonList = spareList, polygonVertexCount = clippedVertexCount[0], clippedVertexCount[0] == 0));
      spareList = nextSpareList;
      polygonList = nextPolygonList;
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
      lastQuadStart = (vertexCursor + vertexCount * 0x100) - 0x400;
      do {
        iVar7 = 0;
        bVar2 = false;
        uVar17 = vertexCursor;
        do {
          while( true ) {
            runStart = uVar17;
            if (lastQuadStart < vertexCursor) goto LAB_000f1138;
            uVar17 = vertexCursor + 0x200;
            cullResult = ((undefined4 (*)())_gleCullQuad)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x300,uVar17,&backFacing,
                                  dVar21,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStackWord_ffffff78
                                  ,incomingStackWord_ffffff80,incomingStackWord_ffffff88);
            dVar21 = f1AfterCall1;
            if (cullResult != 0) break;
            if (iVar10 != backFacing) {
              bVar2 = true;
            }
            if ((bVar2) && (0 < iVar7)) goto LAB_000f1138;
            iVar7 = iVar7 + 2;
            iVar10 = backFacing;
            vertexCursor = uVar17;
            uVar17 = runStart;
          }
          vertexCursor = uVar17;
        } while (iVar7 < 1);
LAB_000f1138:
        if (3 < iVar7 + 2) {
          if (lightingEnabled) {
            lightFaceIndex = iVar10;
            if (!twoSidedLighting) {
              lightFaceIndex = 0;
            }
            litVertexIndex = 0;
            if (-1 < iVar7 + -2) {
              litVertex = runStart + 0x300;
              do {
                if (lightingPending != '\0') {
                  (**(code **)(glContext + 0x5068))(glContext,litVertex,1);
                }
                litVertexIndex = litVertexIndex + 2;
                (**(code **)(lightFaceIndex * 4 + glContext + 0x4de8))(glContext,litVertex,1);
                litVertex = litVertex + 0x200;
              } while (litVertexIndex <= iVar7 + -2);
            }
          }
          if (iVar10 == 0) {
            facePolygonMode = *(ushort *)(glContext + 0x34d0);
          }
          else {
            facePolygonMode = *(ushort *)(glContext + 0x34d2);
          }
          dVar21 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x46d4))
                                     (*(undefined4 *)(glContext + 0x4688), runStart, iVar7 + 2, facePolygonMode - 0x1b00);
        }
      } while (vertexCursor <= lastQuadStart);
    }
  }
  return;
code_r0x000f12b4:
  dVar21 = (double)_gleClipPoly(glContext,nextPolygonList,polygonVertexCount,batchClipCodes & 0xff,nextSpareList,clippedVertexCount,1);
  if (clippedVertexCount[0] != 0) {
    if (0 < clippedVertexCount[0]) {
      spareList = nextPolygonList;
      polygonList = nextSpareList;
      polygonVertexCount = clippedVertexCount[0];
    }
LAB_000f12f4:
    if ((faceTestNeeded == '\0') ||
       (iVar7 = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing), dVar21 = f1AfterCall2,
       iVar7 == 0)) {
      if (lightingPending != '\0') {
        (**(code **)(glContext + 0x5068))(glContext,quadLastVertexPtr,1);
      }
      if (lightingEnabled) {
        iVar7 = 0x4de0;
        if (twoSidedLighting) {
          iVar7 = backFacing * 4 + 0x4de0;
        }
        (**(code **)(glContext + iVar7 + 8))(glContext,quadLastVertexPtr,1);
      }
      *(undefined8 *)(*polygonList + 0x30) = *(undefined8 *)(runStart + 0x330);
      *(undefined8 *)(*polygonList + 0x38) = *(undefined8 *)(runStart + 0x338);
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
  bool vertexProgramPath;
  bool vertexProgramTwoSide;
  int *polygonListCursor;
  int *polygonVertexCursor;
  int *clipOutputList;
  uint flipRemaining;
  uint batchClipCodes;
  int cullResult;
  undefined4 computeClipCodes;
  int *spareList;
  int *polygonList;
  uint polygonVertexCount;
  int vertexCursorThenCullResultThenFlippedVertex;
  uint remaining;
  double f1AfterCall;
  double lastCalleeF1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  uint clippedVertexCount;
  undefined4 backFacing [5];
  
  vertexProgramPath = false;
  backFacing[0] = 0;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    vertexProgramPath = true;
  }
  vertexProgramTwoSide = false;
  if ((vertexProgramPath) && (*(char *)(glContext + 0x4666) != '\0')) {
    vertexProgramTwoSide = true;
  }
  cullFaceEnabled = *(char *)(glContext + 0x34da);
  vertexCursorThenCullResultThenFlippedVertex = *(int *)(glContext + 0x4854);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (polygonVertexCount = (uint)(*(int *)(glContext + 0x4858) - vertexCursorThenCullResultThenFlippedVertex) /
                (uint)(int)*(short *)(glContext + 0x487c), 2 < (int)polygonVertexCount)) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursorThenCullResultThenFlippedVertex,polygonVertexCount), (batchClipCodes & 0xff00) == 0)) {
    lastCalleeF1 = f1AfterCall;
    if (vertexProgramPath) {
      vertexCursorThenCullResultThenFlippedVertex = *(int *)(glContext + 0x4864);
    }
    else if (*(char *)(glContext + 0x4e18) != '\0') {
      lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursorThenCullResultThenFlippedVertex, polygonVertexCount);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if ((cullFaceEnabled == '\0') ||
         (cullResult = ((int (*)())_gleCullPolygonStack)(glContext,vertexCursorThenCullResultThenFlippedVertex,polygonVertexCount,0,backFacing), cullResult == 0)) {
        if ((vertexProgramPath) && (vertexProgramTwoSide)) {
          _gleVPFlipColors(glContext,vertexCursorThenCullResultThenFlippedVertex,polygonVertexCount,backFacing[0]);
        }
        _gleSelectPolygon(glContext,vertexCursorThenCullResultThenFlippedVertex,polygonVertexCount);
      }
    }
    else {
      polygonList = *(int **)(glContext + 0x4870);
      spareList = *(int **)(glContext + 0x4874);
      polygonListCursor = polygonList;
      remaining = polygonVertexCount;
      if (0 < (int)polygonVertexCount) {
        do {
          *polygonListCursor = vertexCursorThenCullResultThenFlippedVertex;
          vertexCursorThenCullResultThenFlippedVertex = vertexCursorThenCullResultThenFlippedVertex + 0x100;
          remaining = remaining - 1;
          polygonListCursor = polygonListCursor + 1;
        } while (remaining != 0);
      }
      if (vertexProgramPath) {
        *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
      }
      computeClipCodes = 0;
      clipOutputList = spareList;
      if (*(char *)(glContext + 0x4e18) != '\0') {
        ((double (*)())_gleClipPolyPlane)(glContext,polygonList,polygonVertexCount,spareList,&clippedVertexCount,lastCalleeF1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
                          incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90);
        if (clippedVertexCount == 0) {
          return;
        }
        computeClipCodes = 1;
        clipOutputList = polygonList;
        polygonList = spareList;
        polygonVertexCount = clippedVertexCount;
      }
      if ((batchClipCodes & 0xff) != 0) {
        _gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,clipOutputList,&clippedVertexCount,computeClipCodes);
        if (clippedVertexCount == 0) {
          return;
        }
        if (0 < (int)clippedVertexCount) {
          polygonList = clipOutputList;
          polygonVertexCount = clippedVertexCount;
        }
      }
      if ((cullFaceEnabled == '\0') ||
         (vertexCursorThenCullResultThenFlippedVertex = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,backFacing), vertexCursorThenCullResultThenFlippedVertex == 0)) {
        if ((vertexProgramPath) && ((vertexProgramTwoSide && (polygonVertexCursor = polygonList, flipRemaining = polygonVertexCount, 0 < (int)polygonVertexCount)))) {
          do {
            vertexCursorThenCullResultThenFlippedVertex = *polygonVertexCursor;
            polygonVertexCursor = polygonVertexCursor + 1;
            _gleVPFlipColors(glContext,vertexCursorThenCullResultThenFlippedVertex,1,backFacing[0]);
            flipRemaining = flipRemaining - 1;
          } while (flipRemaining != 0);
        }
        _gleSelectPolygonPtr(glContext,polygonList,polygonVertexCount);
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
  bool fixedFunctionPath;
  bool orientationChanged;
  bool vertexProgramTwoSide;
  uint *nextPolygonList;
  undefined4 vertexEndValue;
  uint resumeCursor;
  uint batchClipCodes;
  int cullResult;
  int flipRemaining;
  int iVar9;
  int polygonVertexCount;
  uint *spareList;
  uint *nextSpareList;
  uint *polygonVertexCursor;
  uint *polygonList;
  uint vertexCountThenLastTriangleStart;
  uint nextRunStart;
  uint runStart;
  uint vertexCursor;
  int runVertexCount;
  int cullResultThenBackFacing;
  double f1AfterCall;
  double f1AfterHookCall;
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
  int clippedVertexCount [6];
  
  iVar9 = -1;
  fixedFunctionPath = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    fixedFunctionPath = true;
  }
  fixedFunctionPath = !fixedFunctionPath;
  vertexProgramTwoSide = false;
  if ((!fixedFunctionPath) && (*(char *)(glContext + 0x4666) != '\0')) {
    vertexProgramTwoSide = true;
  }
  cullFaceEnabled = *(char *)(glContext + 0x34da);
  vertexCursor = *(uint *)(glContext + 0x4854);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (vertexCountThenLastTriangleStart = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
      2 < (int)vertexCountThenLastTriangleStart)) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCountThenLastTriangleStart), (batchClipCodes & 0xff00) == 0)) {
    f1AfterHookCall = f1AfterCall;
    if (fixedFunctionPath) {
      if (*(char *)(glContext + 0x4e18) != '\0') {
        f1AfterHookCall = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCountThenLastTriangleStart);
      }
    }
    else {
      vertexCursor = *(uint *)(glContext + 0x4864);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (cullFaceEnabled == '\0') {
        _gleSelectTriangles(glContext,vertexCursor,vertexCountThenLastTriangleStart);
      }
      else {
        vertexCountThenLastTriangleStart = (vertexCursor + vertexCountThenLastTriangleStart * 0x100) - 0x300;
        do {
          orientationChanged = false;
          runVertexCount = 0;
          resumeCursor = vertexCursor;
          runStart = vertexCursor;
          if (vertexCursor <= vertexCountThenLastTriangleStart) {
            do {
              cullResult = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x200,0,&backFacing,
                                       f1AfterHookCall,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                       incomingStack_ffffff78,incomingStack_ffffff80);
              f1AfterHookCall = f1AfterHookCall;
              if (cullResult == 0) {
                if (iVar9 != backFacing) {
                  orientationChanged = true;
                }
                if ((orientationChanged) && (resumeCursor = vertexCursor, 0 < runVertexCount)) break;
                runVertexCount = runVertexCount + 3;
                iVar9 = backFacing;
                nextRunStart = runStart;
              }
              else {
                nextRunStart = vertexCursor + 0x300;
                resumeCursor = nextRunStart;
                if (0 < runVertexCount) break;
              }
              vertexCursor = vertexCursor + 0x300;
              resumeCursor = vertexCursor;
              runStart = nextRunStart;
            } while (vertexCursor <= vertexCountThenLastTriangleStart);
            if (2 < runVertexCount) {
              if ((!fixedFunctionPath) && (vertexProgramTwoSide)) {
                _gleVPFlipColors(glContext,runStart,runVertexCount,iVar9);
              }
              f1AfterHookCall = (double)_gleSelectTriangles(glContext,runStart,runVertexCount);
            }
          }
          vertexCursor = resumeCursor;
        } while (resumeCursor <= vertexCountThenLastTriangleStart);
      }
    }
    else {
      polygonList = *(uint **)(glContext + 0x4870);
      vertexCountThenLastTriangleStart = (vertexCursor + vertexCountThenLastTriangleStart * 0x100) - 0x300;
      spareList = *(uint **)(glContext + 0x4874);
      if (vertexCursor <= vertexCountThenLastTriangleStart) {
        do {
          polygonList[1] = vertexCursor + 0x100;
          polygonList[2] = vertexCursor + 0x200;
          *polygonList = vertexCursor;
          if (fixedFunctionPath) {
            vertexEndValue = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            vertexEndValue = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = vertexEndValue;
          nextSpareList = spareList;
          nextPolygonList = polygonList;
          polygonVertexCount = 3;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (f1AfterHookCall = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,clippedVertexCount,f1AfterHookCall,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             nextSpareList = polygonList, nextPolygonList = spareList, polygonVertexCount = clippedVertexCount[0], clippedVertexCount[0] != 0)) {
            polygonList = nextPolygonList;
            spareList = nextSpareList;
            if ((batchClipCodes & 0xff) != 0) {
              f1AfterHookCall = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,nextSpareList,clippedVertexCount,1);
              if (clippedVertexCount[0] == 0) goto LAB_000f19ac;
              if (0 < clippedVertexCount[0]) {
                spareList = polygonList;
                polygonList = nextSpareList;
                polygonVertexCount = clippedVertexCount[0];
              }
            }
            if ((cullFaceEnabled == '\0') ||
               (cullResultThenBackFacing = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing),
               f1AfterHookCall = f1AfterCall2, cullResultThenBackFacing == 0)) {
              cullResultThenBackFacing = backFacing;
              if ((!fixedFunctionPath) && ((vertexProgramTwoSide && (polygonVertexCursor = polygonList, flipRemaining = polygonVertexCount, 0 < polygonVertexCount)))) {
                do {
                  _gleVPFlipColors(glContext,*polygonVertexCursor,1,cullResultThenBackFacing);
                  flipRemaining = flipRemaining + -1;
                  polygonVertexCursor = polygonVertexCursor + 1;
                } while (flipRemaining != 0);
              }
              f1AfterHookCall = (double)_gleSelectPolygonPtr(glContext,polygonList,polygonVertexCount);
            }
          }
LAB_000f19ac:
          vertexCursor = vertexCursor + 0x300;
        } while (vertexCursor <= vertexCountThenLastTriangleStart);
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
  bool facingChanged;
  bool windingFlip;
  bool vertexProgramTwoSide;
  uint runStart;
  uint *puVar6;
  undefined4 batchEndReset;
  uint uVar8;
  uint batchClipCodes;
  int runVertexCount;
  int remaining;
  int cullResult;
  int iVar10;
  int polygonVertexCount;
  uint uVar11;
  uint *spareList;
  uint *puVar13;
  uint *flipCursor;
  int *triangleVertexList;
  uint newRunStart;
  uint uVar16;
  uint vertexCount;
  int iVar17;
  int runTriangleCount;
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
          facingChanged = false;
          runTriangleCount = 0;
          uVar20 = uVar16;
          runStart = vertexCursor;
          while (uVar16 = uVar20, vertexCursor <= uVar8) {
            nextVertex = vertexCursor + 0x100;
            cullResult = ((undefined4 (*)())_gleCullTriangle)(glContext,vertexCursor,nextVertex,vertexCursor + 0x200,uVar20,&backFacing,dVar22,
                                     incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff78,
                                     incomingStack_ffffff80);
            dVar22 = f1AfterCall1;
            if (cullResult == 0) {
              if (iVar10 != backFacing) {
                facingChanged = true;
              }
              if ((facingChanged) && (0 < runTriangleCount)) break;
              if (runTriangleCount == 0) {
                uVar11 = uVar20;
              }
              runTriangleCount = runTriangleCount + 1;
              iVar10 = backFacing;
              newRunStart = runStart;
            }
            else {
              newRunStart = nextVertex;
              uVar16 = uVar20 ^ 1;
              vertexCursor = nextVertex;
              if (0 < runTriangleCount) break;
            }
            uVar20 = uVar20 ^ 1;
            vertexCursor = nextVertex;
            runStart = newRunStart;
          }
          runVertexCount = runTriangleCount + 2;
          if (2 < runVertexCount) {
            if ((!noVertexProgram) && (vertexProgramTwoSide)) {
              _gleVPFlipColors(glContext,runStart,runVertexCount,iVar10);
            }
            uVar20 = runStart;
            if (uVar11 != 0) {
              uVar20 = runStart + 0x100;
              triangleVertexList[2] = runStart;
              runVertexCount = runTriangleCount + 1;
              *triangleVertexList = runStart + 0x200;
              triangleVertexList[1] = uVar20;
              dVar22 = (double)_gleSelectPolygonPtr(glContext,triangleVertexList,3);
              if (runVertexCount < 3) goto LAB_000f1c00;
            }
            dVar22 = (double)_gleSelectTriangleStrip(glContext,uVar20,runVertexCount);
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
          polygonVertexCount = 3;
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
              if ((!noVertexProgram) && ((vertexProgramTwoSide && (remaining = polygonVertexCount, flipCursor = polygonVertexList, 0 < polygonVertexCount)))) {
                do {
                  _gleVPFlipColors(glContext,*flipCursor,1,iVar17);
                  remaining = remaining + -1;
                  flipCursor = flipCursor + 1;
                } while (remaining != 0);
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
  double incomingStackWord_ffffff78;
  double incomingStackWord_ffffff80;
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
                                       incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStackWord_ffffff78,
                                       incomingStackWord_ffffff80);
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
          polygonVertexCount = 3;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar18 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,3,spareList,local_4c,dVar18,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStackWord_ffffff78,incomingStackWord_ffffff80),
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
  bool vertexProgramThenFixedFunctionPath;
  bool facingChanged;
  bool flipColorsNeeded;
  uint *newPolygonList;
  undefined4 bufferEnd;
  uint nextRunStartThenResumeCursor;
  uint batchClipCodes;
  int cullResultThenFlipCount;
  int iVar9;
  int polygonVertexCount;
  uint *spareList;
  uint *oldPolygonListThenVertexPtrCursor;
  uint vertexCountThenLastQuadStart;
  uint *polygonList;
  uint runStart;
  uint vertexCursor;
  int runVertexCountThenCullResultThenBackFacing;
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
  double incomingStackWord_ffffff78;
  double incomingStackWord_ffffff80;
  double incomingStackWord_ffffff88;
  int backFacing;
  int clipCount [6];
  
  iVar9 = -1;
  vertexProgramThenFixedFunctionPath = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    vertexProgramThenFixedFunctionPath = true;
  }
  vertexProgramThenFixedFunctionPath = !vertexProgramThenFixedFunctionPath;
  flipColorsNeeded = false;
  if ((!vertexProgramThenFixedFunctionPath) && (*(char *)(glContext + 0x4666) != '\0')) {
    flipColorsNeeded = true;
  }
  cullFaceEnabled = *(char *)(glContext + 0x34da);
  vertexCursor = *(uint *)(glContext + 0x4854);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (vertexCountThenLastQuadStart = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
      3 < (int)vertexCountThenLastQuadStart)) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCountThenLastQuadStart), (batchClipCodes & 0xff00) == 0)) {
    forwardedFloatArg1 = f1AfterCall;
    if (vertexProgramThenFixedFunctionPath) {
      if (*(char *)(glContext + 0x4e18) != '\0') {
        forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCountThenLastQuadStart);
      }
    }
    else {
      vertexCursor = *(uint *)(glContext + 0x4864);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (cullFaceEnabled == '\0') {
        _gleSelectQuads(glContext,vertexCursor,vertexCountThenLastQuadStart);
      }
      else {
        vertexCountThenLastQuadStart = (vertexCursor + vertexCountThenLastQuadStart * 0x100) - 0x400;
        do {
          facingChanged = false;
          runVertexCountThenCullResultThenBackFacing = 0;
          runStart = vertexCursor;
          nextRunStartThenResumeCursor = vertexCursor;
          if (vertexCursor <= vertexCountThenLastQuadStart) {
            do {
              cullResultThenFlipCount = ((undefined4 (*)())_gleCullQuad)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x200,vertexCursor + 0x300,
                                   &backFacing,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                   incomingStackWord_ffffff78,incomingStackWord_ffffff80,incomingStackWord_ffffff88);
              forwardedFloatArg1 = forwardedFloatArg1;
              if (cullResultThenFlipCount == 0) {
                if (iVar9 != backFacing) {
                  facingChanged = true;
                }
                if ((facingChanged) && (nextRunStartThenResumeCursor = vertexCursor, 0 < runVertexCountThenCullResultThenBackFacing)) break;
                runVertexCountThenCullResultThenBackFacing = runVertexCountThenCullResultThenBackFacing + 4;
                iVar9 = backFacing;
                nextRunStartThenResumeCursor = runStart;
              }
              else {
                nextRunStartThenResumeCursor = vertexCursor + 0x400;
                if (0 < runVertexCountThenCullResultThenBackFacing) break;
              }
              vertexCursor = vertexCursor + 0x400;
              runStart = nextRunStartThenResumeCursor;
              nextRunStartThenResumeCursor = vertexCursor;
            } while (vertexCursor <= vertexCountThenLastQuadStart);
            if (3 < runVertexCountThenCullResultThenBackFacing) {
              if ((!vertexProgramThenFixedFunctionPath) && (flipColorsNeeded)) {
                _gleVPFlipColors(glContext,runStart,runVertexCountThenCullResultThenBackFacing,iVar9);
              }
              forwardedFloatArg1 = (double)_gleSelectQuads(glContext,runStart,runVertexCountThenCullResultThenBackFacing);
            }
          }
          vertexCursor = nextRunStartThenResumeCursor;
        } while (nextRunStartThenResumeCursor <= vertexCountThenLastQuadStart);
      }
    }
    else {
      polygonList = *(uint **)(glContext + 0x4870);
      vertexCountThenLastQuadStart = (vertexCursor + vertexCountThenLastQuadStart * 0x100) - 0x400;
      spareList = *(uint **)(glContext + 0x4874);
      if (vertexCursor <= vertexCountThenLastQuadStart) {
        do {
          polygonList[1] = vertexCursor + 0x100;
          polygonList[2] = vertexCursor + 0x200;
          polygonList[3] = vertexCursor + 0x300;
          *polygonList = vertexCursor;
          if (vertexProgramThenFixedFunctionPath) {
            bufferEnd = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            bufferEnd = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = bufferEnd;
          oldPolygonListThenVertexPtrCursor = spareList;
          polygonVertexCount = 4;
          newPolygonList = polygonList;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (forwardedFloatArg1 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,clipCount,forwardedFloatArg1,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStackWord_ffffff78,incomingStackWord_ffffff80),
             oldPolygonListThenVertexPtrCursor = polygonList, polygonVertexCount = clipCount[0], newPolygonList = spareList, clipCount[0] != 0)) {
            polygonList = newPolygonList;
            spareList = oldPolygonListThenVertexPtrCursor;
            if ((batchClipCodes & 0xff) != 0) {
              forwardedFloatArg1 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,oldPolygonListThenVertexPtrCursor,clipCount,1);
              if (clipCount[0] == 0) goto LAB_000f2450;
              if (0 < clipCount[0]) {
                spareList = polygonList;
                polygonVertexCount = clipCount[0];
                polygonList = oldPolygonListThenVertexPtrCursor;
              }
            }
            if ((cullFaceEnabled == '\0') ||
               (runVertexCountThenCullResultThenBackFacing = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing),
               forwardedFloatArg1 = f1AfterCall2, runVertexCountThenCullResultThenBackFacing == 0)) {
              runVertexCountThenCullResultThenBackFacing = backFacing;
              if ((!vertexProgramThenFixedFunctionPath) && ((flipColorsNeeded && (oldPolygonListThenVertexPtrCursor = polygonList, cullResultThenFlipCount = polygonVertexCount, 0 < polygonVertexCount)))) {
                do {
                  _gleVPFlipColors(glContext,*oldPolygonListThenVertexPtrCursor,1,runVertexCountThenCullResultThenBackFacing);
                  cullResultThenFlipCount = cullResultThenFlipCount + -1;
                  oldPolygonListThenVertexPtrCursor = oldPolygonListThenVertexPtrCursor + 1;
                } while (cullResultThenFlipCount != 0);
              }
              forwardedFloatArg1 = (double)_gleSelectPolygonPtr(glContext,polygonList,polygonVertexCount);
            }
          }
LAB_000f2450:
          vertexCursor = vertexCursor + 0x400;
        } while (vertexCursor <= vertexCountThenLastQuadStart);
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
  bool vertexProgramThenFixedFunctionPath;
  bool facingChanged;
  bool flipColorsNeeded;
  uint *newPolygonList;
  undefined4 bufferEnd;
  uint nextQuadStartThenRunStart;
  uint batchClipCodes;
  int cullResultThenFlipCount;
  int iVar9;
  int polygonVertexCount;
  uint *spareList;
  uint *oldPolygonListThenVertexPtrCursor;
  uint runStartThenNextQuadStart;
  uint vertexCountThenLastQuadStart;
  int runVertexCountThenCullResultThenBackFacing;
  uint *polygonList;
  uint vertexCursor;
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
  double incomingStack_ffffff88;
  int backFacing;
  int clipCount [6];
  
  iVar9 = -1;
  vertexProgramThenFixedFunctionPath = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    vertexProgramThenFixedFunctionPath = true;
  }
  vertexProgramThenFixedFunctionPath = !vertexProgramThenFixedFunctionPath;
  flipColorsNeeded = false;
  if ((!vertexProgramThenFixedFunctionPath) && (*(char *)(glContext + 0x4666) != '\0')) {
    flipColorsNeeded = true;
  }
  cullFaceEnabled = *(char *)(glContext + 0x34da);
  vertexCursor = *(uint *)(glContext + 0x4854);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (vertexCountThenLastQuadStart = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
      3 < (int)vertexCountThenLastQuadStart)) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCountThenLastQuadStart), (batchClipCodes & 0xff00) == 0)) {
    forwardedFloatArg1 = f1AfterCall;
    if (vertexProgramThenFixedFunctionPath) {
      if (*(char *)(glContext + 0x4e18) != '\0') {
        forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCountThenLastQuadStart);
      }
    }
    else {
      vertexCursor = *(uint *)(glContext + 0x4864);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (cullFaceEnabled == '\0') {
        _gleSelectQuadStrip(glContext,vertexCursor,vertexCountThenLastQuadStart);
      }
      else {
        vertexCountThenLastQuadStart = (vertexCursor + vertexCountThenLastQuadStart * 0x100) - 0x400;
        do {
          facingChanged = false;
          runVertexCountThenCullResultThenBackFacing = 0;
          nextQuadStartThenRunStart = vertexCursor;
          do {
            while( true ) {
              runStartThenNextQuadStart = nextQuadStartThenRunStart;
              if (vertexCountThenLastQuadStart < vertexCursor) goto LAB_000f2614;
              nextQuadStartThenRunStart = vertexCursor + 0x200;
              cullResultThenFlipCount = ((undefined4 (*)())_gleCullQuad)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x300,nextQuadStartThenRunStart,&backFacing,
                                   forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                   incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88);
              forwardedFloatArg1 = f1AfterCall1;
              if (cullResultThenFlipCount != 0) break;
              if (iVar9 != backFacing) {
                facingChanged = true;
              }
              if ((facingChanged) && (0 < runVertexCountThenCullResultThenBackFacing)) goto LAB_000f2614;
              runVertexCountThenCullResultThenBackFacing = runVertexCountThenCullResultThenBackFacing + 2;
              iVar9 = backFacing;
              vertexCursor = nextQuadStartThenRunStart;
              nextQuadStartThenRunStart = runStartThenNextQuadStart;
            }
            vertexCursor = nextQuadStartThenRunStart;
          } while (runVertexCountThenCullResultThenBackFacing < 1);
LAB_000f2614:
          runVertexCountThenCullResultThenBackFacing = runVertexCountThenCullResultThenBackFacing + 2;
          if (3 < runVertexCountThenCullResultThenBackFacing) {
            if ((!vertexProgramThenFixedFunctionPath) && (flipColorsNeeded)) {
              _gleVPFlipColors(glContext,runStartThenNextQuadStart,runVertexCountThenCullResultThenBackFacing,iVar9);
            }
            forwardedFloatArg1 = (double)_gleSelectQuadStrip(glContext,runStartThenNextQuadStart,runVertexCountThenCullResultThenBackFacing);
          }
        } while (vertexCursor <= vertexCountThenLastQuadStart);
      }
    }
    else {
      polygonList = *(uint **)(glContext + 0x4870);
      spareList = *(uint **)(glContext + 0x4874);
      vertexCountThenLastQuadStart = (vertexCursor + vertexCountThenLastQuadStart * 0x100) - 0x400;
      if (vertexCursor <= vertexCountThenLastQuadStart) {
        do {
          runStartThenNextQuadStart = vertexCursor + 0x200;
          polygonList[1] = vertexCursor + 0x100;
          polygonList[2] = vertexCursor + 0x300;
          *polygonList = vertexCursor;
          polygonList[3] = runStartThenNextQuadStart;
          if (vertexProgramThenFixedFunctionPath) {
            bufferEnd = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            bufferEnd = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = bufferEnd;
          oldPolygonListThenVertexPtrCursor = spareList;
          polygonVertexCount = 4;
          newPolygonList = polygonList;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (forwardedFloatArg1 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,clipCount,forwardedFloatArg1,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             oldPolygonListThenVertexPtrCursor = polygonList, polygonVertexCount = clipCount[0], newPolygonList = spareList, clipCount[0] != 0)) {
            polygonList = newPolygonList;
            spareList = oldPolygonListThenVertexPtrCursor;
            if ((batchClipCodes & 0xff) != 0) {
              forwardedFloatArg1 = (double)_gleClipPoly(glContext,polygonList,polygonVertexCount,batchClipCodes & 0xff,oldPolygonListThenVertexPtrCursor,clipCount,1);
              if (clipCount[0] == 0) goto LAB_000f27ac;
              if (0 < clipCount[0]) {
                spareList = polygonList;
                polygonVertexCount = clipCount[0];
                polygonList = oldPolygonListThenVertexPtrCursor;
              }
            }
            if ((cullFaceEnabled == '\0') ||
               (runVertexCountThenCullResultThenBackFacing = ((int (*)())_gleCullPolygonPtrStack)(glContext,polygonList,polygonVertexCount,&backFacing),
               forwardedFloatArg1 = f1AfterCall2, runVertexCountThenCullResultThenBackFacing == 0)) {
              runVertexCountThenCullResultThenBackFacing = backFacing;
              if ((!vertexProgramThenFixedFunctionPath) && ((flipColorsNeeded && (oldPolygonListThenVertexPtrCursor = polygonList, cullResultThenFlipCount = polygonVertexCount, 0 < polygonVertexCount)))) {
                do {
                  _gleVPFlipColors(glContext,*oldPolygonListThenVertexPtrCursor,1,runVertexCountThenCullResultThenBackFacing);
                  cullResultThenFlipCount = cullResultThenFlipCount + -1;
                  oldPolygonListThenVertexPtrCursor = oldPolygonListThenVertexPtrCursor + 1;
                } while (cullResultThenFlipCount != 0);
              }
              forwardedFloatArg1 = (double)_gleSelectPolygonPtr(glContext,polygonList,polygonVertexCount);
            }
          }
LAB_000f27ac:
          vertexCursor = runStartThenNextQuadStart;
        } while (runStartThenNextQuadStart <= vertexCountThenLastQuadStart);
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
  int doubleWordCountThenRemaining;
  undefined8 *srcCursor;
  undefined8 *dstCursor;
  undefined8 copiedWord;
  undefined8 lastVertexCopy [33];
  
  doubleWordCountThenRemaining = (int)*(short *)(glContext + 0x487c) >> 3;
  if (0 < doubleWordCountThenRemaining) {
    dstCursor = lastVertexCopy;
    srcCursor = (undefined8 *)(*(int *)(glContext + 0x4858) + -0x100);
    do {
      copiedWord = *srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursor = copiedWord;
      dstCursor = dstCursor + 1;
      doubleWordCountThenRemaining = doubleWordCountThenRemaining + -1;
    } while (doubleWordCountThenRemaining != 0);
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  _glePopMaterials(glContext);
  _gleSubmitVertexCopy(glContext,lastVertexCopy);
  return;
}

/* _gleFlushLineStripTCLFunc @ 0xf2bf8 (124 bytes) */
void _gleFlushLineStripTCLFunc(glContext)
  int glContext;
{
  int copyOffset;
  int vertexBufferEnd;
  int vertexSize;
  int vertexBufferStart;
  uint remaining;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  vertexSize = (int)*(short *)(glContext + 0x487c);
  copyOffset = 0;
  vertexBufferEnd = *(int *)(glContext + 0x4858);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  vertexBufferStart = *(int *)(glContext + 0x4854);
  if (0 < vertexSize) {
    remaining = vertexSize + 7U >> 3;
    do {
      *(undefined8 *)(vertexBufferStart + copyOffset) = *(undefined8 *)((vertexBufferEnd - vertexSize) + copyOffset);
      copyOffset = copyOffset + 8;
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  *(int *)(glContext + 0x4858) = vertexBufferStart + vertexSize;
  return;
}

/* _gleFlushLineStripTCLRDirtyFunc @ 0xf2c74 (236 bytes) */
void _gleFlushLineStripTCLRDirtyFunc(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int bufferStart;
  int copyOffset;
  int vertexStride;
  int oldWriteCursor;
  uint remaining;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
                    
                    
    (**(code **)(glContext + 0x4a0c))(glContext);
    return;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  vertexStride = (int)*(short *)(glContext + 0x487c);
  copyOffset = 0;
  oldWriteCursor = *(int *)(glContext + 0x4858);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  bufferStart = *(int *)(glContext + 0x4854);
  if (0 < vertexStride) {
    remaining = vertexStride + 7U >> 3;
    do {
      *(undefined8 *)(bufferStart + copyOffset) = *(undefined8 *)((oldWriteCursor - vertexStride) + copyOffset);
      copyOffset = copyOffset + 8;
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(int *)(glContext + 0x4858) = bufferStart + vertexStride;
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
  short vertexSize;
  int copyBytes;
  int copyOffset;
  int vertexBufferEnd;
  int vertexBufferStart;
  uint remaining;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  vertexSize = *(short *)(glContext + 0x487c);
  copyOffset = 0;
  vertexBufferEnd = *(int *)(glContext + 0x4858);
  copyBytes = vertexSize * 2;
  vertexBufferStart = *(int *)(glContext + 0x4854);
  if (0 < copyBytes) {
    remaining = copyBytes + 7U >> 3;
    do {
      *(undefined8 *)(vertexBufferStart + copyOffset) = *(undefined8 *)(vertexBufferEnd + vertexSize * -2 + copyOffset);
      copyOffset = copyOffset + 8;
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  *(int *)(glContext + 0x4858) = vertexBufferStart + copyBytes;
  return;
}

/* _gleFlushTriQuadStripTCLRDirtyFunc @ 0xf2e9c (232 bytes) */
void _gleFlushTriQuadStripTCLRDirtyFunc(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  short vertexStride;
  int carriedBytes;
  int bufferStart;
  int copyOffset;
  int oldWriteCursor;
  uint remaining;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
                    
                    
    (**(code **)(glContext + 0x4a0c))(glContext);
    return;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  vertexStride = *(short *)(glContext + 0x487c);
  copyOffset = 0;
  oldWriteCursor = *(int *)(glContext + 0x4858);
  carriedBytes = vertexStride * 2;
  bufferStart = *(int *)(glContext + 0x4854);
  if (0 < carriedBytes) {
    remaining = carriedBytes + 7U >> 3;
    do {
      *(undefined8 *)(bufferStart + copyOffset) = *(undefined8 *)(oldWriteCursor + vertexStride * -2 + copyOffset);
      copyOffset = copyOffset + 8;
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(int *)(glContext + 0x4858) = bufferStart + carriedBytes;
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
  int copyOffset;
  int copyDestination;
  int vertexStride;
  int oldWriteCursor;
  uint remaining;
  
  (**(code **)(glContext + 0x4a08))(glContext);
  vertexStride = (int)*(short *)(glContext + 0x487c);
  copyOffset = 0;
  oldWriteCursor = *(int *)(glContext + 0x4858);
  copyDestination = *(int *)(glContext + 0x4854) + vertexStride;
  if (0 < vertexStride) {
    remaining = vertexStride + 7U >> 3;
    do {
      *(undefined8 *)(copyDestination + copyOffset) = *(undefined8 *)((oldWriteCursor - vertexStride) + copyOffset);
      copyOffset = copyOffset + 8;
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  *(int *)(glContext + 0x4858) = copyDestination + vertexStride;
  return;
}

/* _gleFlushTriangleFanTCLRDirtyFunc @ 0xf30c4 (232 bytes) */
void _gleFlushTriangleFanTCLRDirtyFunc(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int copyDestination;
  int copyByteOffset;
  int copyByteCount;
  int vertexWriteCursor;
  uint copyUnitCount;
  
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
                    
                    
    (**(code **)(glContext + 0x4a0c))(glContext);
    return;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  copyByteCount = (int)*(short *)(glContext + 0x487c);
  copyByteOffset = 0;
  vertexWriteCursor = *(int *)(glContext + 0x4858);
  copyDestination = *(int *)(glContext + 0x4854) + copyByteCount;
  if (0 < copyByteCount) {
    copyUnitCount = copyByteCount + 7U >> 3;
    do {
      *(undefined8 *)(copyDestination + copyByteOffset) = *(undefined8 *)((vertexWriteCursor - copyByteCount) + copyByteOffset);
      copyByteOffset = copyByteOffset + 8;
      copyUnitCount = copyUnitCount - 1;
    } while (copyUnitCount != 0);
  }
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(int *)(glContext + 0x4858) = copyDestination + copyByteCount;
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
  int copyOffset;
  int bufferStartThenCopyDestination;
  undefined1 savedVertexFlagByte;
  int vertexStride;
  int lastVertex;
  uint remaining;
  
  savedVertexFlagByte = 0;
  vertexStride = (int)*(short *)(glContext + 0x487c);
  lastVertex = *(int *)(glContext + 0x4858) - vertexStride;
  if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
    savedVertexFlagByte = *(undefined1 *)(lastVertex + *(short *)(glContext + 0x487e));
    *(undefined1 *)(lastVertex + *(short *)(glContext + 0x487e)) = 0;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  bufferStartThenCopyDestination = *(int *)(glContext + 0x4854);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
    *(undefined1 *)(lastVertex + *(short *)(glContext + 0x487e)) = savedVertexFlagByte;
    *(undefined1 *)(bufferStartThenCopyDestination + *(short *)(glContext + 0x487e)) = 0;
  }
  copyOffset = 0;
  bufferStartThenCopyDestination = bufferStartThenCopyDestination + vertexStride;
  if (0 < vertexStride) {
    remaining = vertexStride + 7U >> 3;
    do {
      *(undefined8 *)(bufferStartThenCopyDestination + copyOffset) = *(undefined8 *)(lastVertex + copyOffset);
      copyOffset = copyOffset + 8;
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  *(int *)(glContext + 0x4858) = bufferStartThenCopyDestination + vertexStride;
  return;
}

/* _gleFlushPolygonTCLRDirtyFunc @ 0xf3378 (328 bytes) */
void _gleFlushPolygonTCLRDirtyFunc(int glContext,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  int copyOffset;
  int bufferStartThenCopyDest;
  undefined1 savedRecordByte;
  int carriedByteCount;
  int carriedStart;
  uint copyChunksRemaining;
  
  savedRecordByte = 0;
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8);
                    
                    
    (**(code **)(glContext + 0x4a0c))(glContext);
    return;
  }
  carriedByteCount = (int)*(short *)(glContext + 0x487c);
  carriedStart = *(int *)(glContext + 0x4858) - carriedByteCount;
  if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
    savedRecordByte = *(undefined1 *)(carriedStart + *(short *)(glContext + 0x487e));
    *(undefined1 *)(carriedStart + *(short *)(glContext + 0x487e)) = 0;
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  bufferStartThenCopyDest = *(int *)(glContext + 0x4854);
  *(undefined1 *)(glContext + 0x4a18) = 1;
  if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
    *(undefined1 *)(carriedStart + *(short *)(glContext + 0x487e)) = savedRecordByte;
    *(undefined1 *)(bufferStartThenCopyDest + *(short *)(glContext + 0x487e)) = 0;
  }
  copyOffset = 0;
  bufferStartThenCopyDest = bufferStartThenCopyDest + carriedByteCount;
  if (0 < carriedByteCount) {
    copyChunksRemaining = carriedByteCount + 7U >> 3;
    do {
      *(undefined8 *)(bufferStartThenCopyDest + copyOffset) = *(undefined8 *)(carriedStart + copyOffset);
      copyOffset = copyOffset + 8;
      copyChunksRemaining = copyChunksRemaining - 1;
    } while (copyChunksRemaining != 0);
  }
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(int *)(glContext + 0x4858) = bufferStartThenCopyDest + carriedByteCount;
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

