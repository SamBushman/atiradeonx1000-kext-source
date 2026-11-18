#include "decls.h"

/* _gleBeginLinesRenderTCLRDirty @ 0xd78f4 (60 bytes) */
void _gleBeginLinesRenderTCLRDirty(glContext)
  int glContext;
{
  undefined *flushAtomicTCLRDirtyFunc;
  undefined *renderLinesTCLFunc;
  
  renderLinesTCLFunc = PTR__gleRenderLinesTCLFunc_00112214;
  flushAtomicTCLRDirtyFunc = PTR__gleFlushAtomicTCLRDirtyFunc_00112210;
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = flushAtomicTCLRDirtyFunc;
  *(undefined **)(glContext + 0x4a08) = renderLinesTCLFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginLinesSelectFeedback @ 0xd7930 (76 bytes) */
void _gleBeginLinesSelectFeedback(glContext)
  int glContext;
{
  undefined *puVar1;
  
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushAtomicFunc_00112224;
  puVar1 = PTR__gleFeedbackLinesFunc_00112208;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectLinesFunc_0011220c;
  }
  *(undefined **)(glContext + 0x4a08) = puVar1;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginLineStripRenderSmooth @ 0xd797c (60 bytes) */
void _gleBeginLineStripRenderSmooth(glContext)
  int glContext;
{
  undefined *renderSmoothLineStripFunc;
  undefined *flushLineStripFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  flushLineStripFunc = PTR__gleFlushLineStripFunc_00112204;
  renderSmoothLineStripFunc = PTR__gleRenderSmoothLineStripFunc_00112200;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushLineStripFunc;
  *(undefined **)(glContext + 0x4a08) = renderSmoothLineStripFunc;
  return;
}

/* _gleBeginLineStripRenderFlat @ 0xd79b8 (60 bytes) */
void _gleBeginLineStripRenderFlat(glContext)
  int glContext;
{
  undefined *renderFlatLineStripFunc;
  undefined *flushLineStripFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  flushLineStripFunc = PTR__gleFlushLineStripFunc_00112204;
  renderFlatLineStripFunc = PTR__gleRenderFlatLineStripFunc_001121fc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushLineStripFunc;
  *(undefined **)(glContext + 0x4a08) = renderFlatLineStripFunc;
  return;
}

/* _gleBeginLineStripRenderTCLRDirty @ 0xd79f4 (68 bytes) */
void _gleBeginLineStripRenderTCLRDirty(glContext)
  int glContext;
{
  undefined *flushLineStripTCLRDirtyFunc;
  undefined *renderLineStripTCLFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  renderLineStripTCLFunc = PTR__gleRenderLineStripTCLFunc_001121f4;
  flushLineStripTCLRDirtyFunc = PTR__gleFlushLineStripTCLRDirtyFunc_001121f0;
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = flushLineStripTCLRDirtyFunc;
  *(undefined **)(glContext + 0x4a08) = renderLineStripTCLFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginLineStripSelectFeedback @ 0xd7a38 (76 bytes) */
void _gleBeginLineStripSelectFeedback(glContext)
  int glContext;
{
  undefined *feedbackOrSelectFunc;
  
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushLineStripFunc_00112204;
  feedbackOrSelectFunc = PTR__gleFeedbackLineStripFunc_001121e8;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    feedbackOrSelectFunc = PTR__gleSelectLineStripFunc_001121ec;
  }
  *(undefined **)(glContext + 0x4a08) = feedbackOrSelectFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginLineLoopRenderSmooth @ 0xd7a84 (60 bytes) */
void _gleBeginLineLoopRenderSmooth(glContext)
  int glContext;
{
  undefined *renderSmoothLineLoopFunc;
  undefined *flushLineLoopFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  flushLineLoopFunc = PTR__gleFlushLineLoopFunc_001121e4;
  renderSmoothLineLoopFunc = PTR__gleRenderSmoothLineLoopFunc_001121e0;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushLineLoopFunc;
  *(undefined **)(glContext + 0x4a08) = renderSmoothLineLoopFunc;
  return;
}

/* _gleBeginLineLoopRenderFlat @ 0xd7ac0 (60 bytes) */
void _gleBeginLineLoopRenderFlat(glContext)
  int glContext;
{
  undefined *renderFlatLineLoopFunc;
  undefined *flushLineLoopFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  flushLineLoopFunc = PTR__gleFlushLineLoopFunc_001121e4;
  renderFlatLineLoopFunc = PTR__gleRenderFlatLineLoopFunc_001121dc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushLineLoopFunc;
  *(undefined **)(glContext + 0x4a08) = renderFlatLineLoopFunc;
  return;
}

/* _gleBeginLineLoopRenderTCLRDirty @ 0xd7afc (68 bytes) */
void _gleBeginLineLoopRenderTCLRDirty(glContext)
  int glContext;
{
  undefined *flushLineLoopTCLRDirtyFunc;
  undefined *renderLineLoopTCLFunc;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  renderLineLoopTCLFunc = PTR__gleRenderLineLoopTCLFunc_001121d4;
  flushLineLoopTCLRDirtyFunc = PTR__gleFlushLineLoopTCLRDirtyFunc_001121d0;
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = flushLineLoopTCLRDirtyFunc;
  *(undefined **)(glContext + 0x4a08) = renderLineLoopTCLFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginLineLoopSelectFeedback @ 0xd7b40 (84 bytes) */
void _gleBeginLineLoopSelectFeedback(glContext)
  int glContext;
{
  undefined *flushFuncThenFeedbackOrSelectFunc;
  
  flushFuncThenFeedbackOrSelectFunc = PTR__gleFlushLineLoopFunc_001121e4;
  *(undefined1 *)(glContext + 0x4a18) = 0;
  *(undefined **)(glContext + 0x4a0c) = flushFuncThenFeedbackOrSelectFunc;
  flushFuncThenFeedbackOrSelectFunc = PTR__gleFeedbackLineLoopFunc_001121c8;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    flushFuncThenFeedbackOrSelectFunc = PTR__gleSelectLineLoopFunc_001121cc;
  }
  *(undefined **)(glContext + 0x4a08) = flushFuncThenFeedbackOrSelectFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleClipLines @ 0xd7b94 (284 bytes) */
int _gleClipLines(glContext, lineList, entryCount, planeMask)
  int glContext;
  int *lineList;
  int entryCount;
  undefined4 planeMask;
{
  byte clipResult;
  byte planeBit;
  int lineStartVertex;
  int *outputCursor;
  int *inputCursor;
  int lineEndVertex;
  
  planeBit = 1;
  do {
    if (((byte)planeMask & planeBit) != 0) {
      outputCursor = lineList;
      for (inputCursor = lineList; inputCursor < lineList + entryCount + -1; inputCursor = inputCursor + 2) {
        lineStartVertex = *inputCursor;
        lineEndVertex = inputCursor[1];
        if ((planeBit & *(byte *)(lineStartVertex + 0x7f)) == 0) {
          if ((planeBit & *(byte *)(lineEndVertex + 0x7f)) != 0) {
            clipResult = (**(code **)(glContext + 0x49cc))(glContext,lineEndVertex,lineStartVertex,lineEndVertex,planeBit);
            (*(unsigned char *)((unsigned char *)&(planeMask) + 3)) = (byte)planeMask | clipResult;
          }
          *outputCursor = lineStartVertex;
          outputCursor[1] = lineEndVertex;
LAB_000d7c68:
          outputCursor = outputCursor + 2;
        }
        else if ((planeBit & *(byte *)(lineEndVertex + 0x7f)) == 0) {
          clipResult = (**(code **)(glContext + 0x49cc))(glContext,lineStartVertex,lineEndVertex,lineStartVertex,planeBit);
          *outputCursor = lineStartVertex;
          (*(unsigned char *)((unsigned char *)&(planeMask) + 3)) = (byte)planeMask | clipResult;
          outputCursor[1] = lineEndVertex;
          goto LAB_000d7c68;
        }
      }
      entryCount = (int)outputCursor - (int)lineList >> 2;
      if (entryCount < 2) {
        return 0;
      }
    }
    planeBit = planeBit << 1;
    if (0x20 < planeBit) {
      return entryCount;
    }
  } while( true );
}

/* _gleClipLinesPlane @ 0xd7cb0 (360 bytes) */
int _gleClipLinesPlane(int glContext,int *lineVertexList,int vertexPointerCount,double unusedFloatArg1)
{
  float planeX;
  float planeW;
  float planeY;
  float planeZ;
  float fVar5;
  float startDistance;
  float fVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int planeCount;
  int planeLoopIndex;
  int *planeIndexCursor;
  int *outCursor;
  int *inCursor;
  int startVertex;
  
  planeCount = *(int *)(glContext + 0x4dfc);
  planeLoopIndex = 0;
  iVar10 = vertexPointerCount;
  if (0 < planeCount) {
    planeIndexCursor = (int *)(glContext + 0x4e00);
    do {
      fVar7 = FLOAT_00108e50;
      iVar10 = *planeIndexCursor;
      planeIndexCursor = planeIndexCursor + 1;
      iVar10 = glContext + iVar10 * 0x10;
      planeX = *(float *)(iVar10 + 0x418c);
      planeW = *(float *)(iVar10 + 0x4198);
      planeY = *(float *)(iVar10 + 0x4190);
      planeZ = *(float *)(iVar10 + 0x4194);
      outCursor = lineVertexList;
      for (inCursor = lineVertexList; inCursor < lineVertexList + vertexPointerCount + -1; inCursor = inCursor + 2) {
        startVertex = *inCursor;
        iVar10 = inCursor[1];
        startDistance = *(float *)(startVertex + 0x2c) * planeW +
                (*(float *)(startVertex + 0x28) * planeZ +
                (*(float *)(startVertex + 0x20) * planeX + *(float *)(startVertex + 0x24) * planeY));
        fVar5 = *(float *)(iVar10 + 0x2c) * planeW +
                (*(float *)(iVar10 + 0x28) * planeZ +
                (*(float *)(iVar10 + 0x20) * planeX + *(float *)(iVar10 + 0x24) * planeY));
        if (startDistance < fVar7) {
          if (fVar7 <= fVar5) {
            fVar5 = startDistance / (startDistance - fVar5);
            iVar8 = iVar10;
            iVar9 = startVertex;
LAB_000d7dc4:
            (**(int ( **)(int,int,int,int,double))(glContext + 0x49c8))(glContext, iVar9, iVar8, iVar9, (double)fVar5);
            goto LAB_000d7dd0;
          }
        }
        else {
          if (fVar5 < fVar7) {
            fVar5 = fVar5 / (fVar5 - startDistance);
            iVar8 = startVertex;
            iVar9 = iVar10;
            goto LAB_000d7dc4;
          }
LAB_000d7dd0:
          *outCursor = startVertex;
          outCursor[1] = iVar10;
          outCursor = outCursor + 2;
        }
      }
      vertexPointerCount = (int)outCursor - (int)lineVertexList >> 2;
      iVar10 = 0;
    } while ((1 < vertexPointerCount) && (planeLoopIndex = planeLoopIndex + 1, iVar10 = vertexPointerCount, planeLoopIndex < planeCount));
  }
  return iVar10;
}

/* _gleFeedbackLinesFunc_body @ 0xd7e1c (776 bytes) */
void _gleFeedbackLinesFunc_body(glContext, unusedArg2, unusedArg3)
  int glContext;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
{
  uint *pairSecondVertexSlot;
  bool vertexProgramThenFixedFunctionPath;
  uint vertexEndThenRemainingVertices;
  uint clipFlags;
  int vertexEnd;
  uint *listCursor;
  uint vertexCountThenClippedCount;
  uint vertexCursor;
  uint *polygonList;
  double forwardedF1ThenIntToDoubleBias;
  
  vertexProgramThenFixedFunctionPath = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    vertexProgramThenFixedFunctionPath = true;
  }
  vertexCursor = *(uint *)(glContext + 0x4854);
  if (((int)*(short *)(glContext + 0x487c) != 0) &&
     (vertexCountThenClippedCount = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
     1 < (int)vertexCountThenClippedCount)) {
    vertexProgramThenFixedFunctionPath = !vertexProgramThenFixedFunctionPath;
    if (vertexProgramThenFixedFunctionPath) {
      clipFlags = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCountThenClippedCount);
    }
    else {
      clipFlags = _gleVPEmulate(glContext,vertexCountThenClippedCount);
    }
    if ((clipFlags & 0xff00) == 0) {
      if (vertexProgramThenFixedFunctionPath) {
        if (*(char *)(glContext + 0x53e4) != '\0') {
          (**(code **)(glContext + 0x53dc))(glContext,vertexCursor,vertexCountThenClippedCount);
        }
        if (*(char *)(glContext + 0x50b4) != '\0') {
          (**(code **)(glContext + 0x5064))(glContext,vertexCursor,vertexCountThenClippedCount);
        }
        if ((*(char *)(glContext + 0x30aa) != '\0') || (*(char *)(glContext + 0x53e6) != '\0')) {
          (**(code **)(glContext + 0x5068))(glContext,vertexCursor,vertexCountThenClippedCount);
        }
      }
      else {
        vertexCursor = *(uint *)(glContext + 0x4864);
      }
      if (((clipFlags & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        if ((vertexProgramThenFixedFunctionPath) && (*(char *)(glContext + 0x53e5) != '\0')) {
          (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,vertexCountThenClippedCount);
        }
        (**(code **)(glContext + 0x506c))(glContext,vertexCursor,vertexCountThenClippedCount,0);
        if ((vertexProgramThenFixedFunctionPath) && (*(char *)(glContext + 0x30aa) != '\0')) {
          (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,vertexCountThenClippedCount);
        }
        vertexEnd = vertexCursor + vertexCountThenClippedCount * 0x100;
        for (; vertexCursor < vertexEnd - 0x100U; vertexCursor = vertexCursor + 0x200) {
          ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f2c);
          _gleFeedbackHitRecord(glContext,vertexCursor);
          _gleFeedbackHitRecord(glContext,vertexCursor + 0x100);
        }
        return;
      }
      if ((vertexProgramThenFixedFunctionPath) && (*(char *)(glContext + 0x53e5) != '\0')) {
        (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,vertexCountThenClippedCount);
      }
      forwardedF1ThenIntToDoubleBias = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCountThenClippedCount, 0);
      vertexEndThenRemainingVertices = vertexCursor + vertexCountThenClippedCount * 0x100;
      polygonList = *(uint **)(glContext + 0x4870);
      if (vertexCursor < vertexEndThenRemainingVertices) {
        vertexEndThenRemainingVertices = (vertexEndThenRemainingVertices - vertexCursor) + 0xff >> 8;
        listCursor = polygonList;
        do {
          *listCursor = vertexCursor;
          vertexCursor = vertexCursor + 0x100;
          listCursor = listCursor + 1;
          vertexEndThenRemainingVertices = vertexEndThenRemainingVertices - 1;
        } while (vertexEndThenRemainingVertices != 0);
      }
      if (((*(char *)(glContext + 0x4e18) == '\0') ||
          (vertexCountThenClippedCount = ((int (*)())_gleClipLinesPlane)(glContext,polygonList,vertexCountThenClippedCount,forwardedF1ThenIntToDoubleBias), vertexCountThenClippedCount != 0)) &&
         (((clipFlags & 0xff) == 0 ||
          (vertexCountThenClippedCount = ((int (*)())_gleClipLines)(glContext,polygonList,vertexCountThenClippedCount,clipFlags & 0xff), vertexCountThenClippedCount != 0)))) {
        if ((vertexProgramThenFixedFunctionPath) && (*(char *)(glContext + 0x30aa) != '\0')) {
          (**(code **)(glContext + 0x4df0))(glContext,polygonList,vertexCountThenClippedCount);
        }
        forwardedF1ThenIntToDoubleBias = DOUBLE_00108d70;
        if (1 < (int)vertexCountThenClippedCount) {
          listCursor = polygonList + 2;
          ((void (*)())_gleFeedbackToken)(glContext,(double)(float)(4503599627372295.0 - DOUBLE_00108d70));
          _gleFeedbackHitRecord(glContext,*polygonList);
          _gleFeedbackHitRecord(glContext,polygonList[1]);
          if (listCursor < polygonList + (vertexCountThenClippedCount - 1)) {
            do {
              ((void (*)())_gleFeedbackToken)(glContext,(double)(float)(4503599627372295.0 - forwardedF1ThenIntToDoubleBias));
              _gleFeedbackHitRecord(glContext,*listCursor);
              pairSecondVertexSlot = listCursor + 1;
              listCursor = listCursor + 2;
              _gleFeedbackHitRecord(glContext,*pairSecondVertexSlot);
            } while (listCursor < polygonList + (vertexCountThenClippedCount - 1));
          }
        }
        return;
      }
    }
  }
  return;
}

/* _gleFeedbackLineStripFunc_body @ 0xd811c (828 bytes) */
void _gleFeedbackLineStripFunc_body(glContext, unusedArg2, unusedArg3)
  int glContext;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
{
  uint *pairSecondVertexSlot;
  undefined4 firstSegmentToken;
  int vertexEndThenListCount;
  uint clipFlagsThenSegmentStart;
  bool vertexProgramThenFixedFunctionThenNewStrip;
  undefined4 nextSegmentToken;
  uint *polygonList;
  uint copyDestinationThenNextVertex;
  uint vertexCount;
  uint vertexCursor;
  uint *listCursor;
  double intToDoubleBiasThenForwardedF1;
  double f1AfterCall;
  
  vertexProgramThenFixedFunctionThenNewStrip = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    vertexProgramThenFixedFunctionThenNewStrip = true;
  }
  vertexCursor = *(uint *)(glContext + 0x4854);
  if (((int)*(short *)(glContext + 0x487c) != 0) &&
     (vertexCount = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
     1 < (int)vertexCount)) {
    vertexProgramThenFixedFunctionThenNewStrip = !vertexProgramThenFixedFunctionThenNewStrip;
    if (vertexProgramThenFixedFunctionThenNewStrip) {
      clipFlagsThenSegmentStart = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount);
    }
    else {
      clipFlagsThenSegmentStart = _gleVPEmulate(glContext,vertexCount);
    }
    if ((clipFlagsThenSegmentStart & 0xff00) == 0) {
      if (vertexProgramThenFixedFunctionThenNewStrip) {
        if (*(char *)(glContext + 0x53e4) != '\0') {
          (**(code **)(glContext + 0x53dc))(glContext,vertexCursor,vertexCount);
        }
        if (*(char *)(glContext + 0x50b4) != '\0') {
          (**(code **)(glContext + 0x5064))(glContext,vertexCursor,vertexCount);
        }
        if ((*(char *)(glContext + 0x30aa) != '\0') || (*(char *)(glContext + 0x53e6) != '\0')) {
          (**(code **)(glContext + 0x5068))(glContext,vertexCursor,vertexCount);
        }
      }
      else {
        vertexCursor = *(uint *)(glContext + 0x4864);
      }
      if (((clipFlagsThenSegmentStart & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        if ((vertexProgramThenFixedFunctionThenNewStrip) && (*(char *)(glContext + 0x53e5) != '\0')) {
          (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,vertexCount);
        }
        (**(code **)(glContext + 0x506c))(glContext,vertexCursor,vertexCount,0);
        if ((vertexProgramThenFixedFunctionThenNewStrip) && (*(char *)(glContext + 0x30aa) != '\0')) {
          (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,vertexCount);
        }
        intToDoubleBiasThenForwardedF1 = DOUBLE_00108d70;
        vertexProgramThenFixedFunctionThenNewStrip = *(char *)(glContext + 0x4a18) == '\0';
        if (1 < (int)vertexCount) {
          if (vertexProgramThenFixedFunctionThenNewStrip) {
            if (vertexProgramThenFixedFunctionThenNewStrip) {
              firstSegmentToken = 0x707;
              nextSegmentToken = 0x702;
            }
            else {
              nextSegmentToken = 0x707;
              firstSegmentToken = 0x707;
            }
          }
          else {
            nextSegmentToken = 0x702;
            firstSegmentToken = 0x702;
          }
          clipFlagsThenSegmentStart = vertexCursor + 0x100;
          ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,firstSegmentToken) -
                                                   DOUBLE_00108d70));
          _gleFeedbackHitRecord(glContext,vertexCursor);
          _gleFeedbackHitRecord(glContext,clipFlagsThenSegmentStart);
          vertexCursor = (vertexCursor + vertexCount * 0x100) - 0x100;
          if (clipFlagsThenSegmentStart < vertexCursor) {
            do {
              copyDestinationThenNextVertex = clipFlagsThenSegmentStart + 0x100;
              ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,nextSegmentToken) - intToDoubleBiasThenForwardedF1)
                               );
              _gleFeedbackHitRecord(glContext,clipFlagsThenSegmentStart);
              _gleFeedbackHitRecord(glContext,copyDestinationThenNextVertex);
              clipFlagsThenSegmentStart = copyDestinationThenNextVertex;
            } while (copyDestinationThenNextVertex < vertexCursor);
          }
        }
        return;
      }
      if ((vertexProgramThenFixedFunctionThenNewStrip) && (*(char *)(glContext + 0x53e5) != '\0')) {
        (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,vertexCount);
      }
      intToDoubleBiasThenForwardedF1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCount, 0);
      polygonList = *(uint **)(glContext + 0x4870);
      vertexEndThenListCount = vertexCursor + vertexCount * 0x100;
      listCursor = polygonList;
      if (vertexProgramThenFixedFunctionThenNewStrip) {
        copyDestinationThenNextVertex = *(uint *)(glContext + 0x4858);
      }
      else {
        copyDestinationThenNextVertex = *(uint *)(glContext + 0x4854);
      }
      while (vertexCursor < vertexEndThenListCount - 0x100U) {
        *listCursor = vertexCursor;
        _memcpy(copyDestinationThenNextVertex,vertexCursor + 0x100,0x100);
        listCursor[1] = copyDestinationThenNextVertex;
        copyDestinationThenNextVertex = copyDestinationThenNextVertex + 0x100;
        listCursor = listCursor + 2;
        vertexCursor = vertexCursor + 0x100;
        intToDoubleBiasThenForwardedF1 = f1AfterCall;
      }
      vertexEndThenListCount = (int)listCursor - (int)polygonList >> 2;
      if (((*(char *)(glContext + 0x4e18) == '\0') ||
          (vertexEndThenListCount = ((int (*)())_gleClipLinesPlane)(glContext,polygonList,vertexEndThenListCount,intToDoubleBiasThenForwardedF1), vertexEndThenListCount != 0)) &&
         (((clipFlagsThenSegmentStart & 0xff) == 0 ||
          (vertexEndThenListCount = ((int (*)())_gleClipLines)(glContext,polygonList,vertexEndThenListCount,clipFlagsThenSegmentStart & 0xff), vertexEndThenListCount != 0)))) {
        if ((vertexProgramThenFixedFunctionThenNewStrip) && (*(char *)(glContext + 0x30aa) != '\0')) {
          (**(code **)(glContext + 0x4df0))(glContext,polygonList,vertexEndThenListCount);
        }
        intToDoubleBiasThenForwardedF1 = DOUBLE_00108d70;
        vertexProgramThenFixedFunctionThenNewStrip = *(char *)(glContext + 0x4a18) == '\0';
        if (1 < vertexEndThenListCount) {
          if (vertexProgramThenFixedFunctionThenNewStrip) {
            if (vertexProgramThenFixedFunctionThenNewStrip) {
              firstSegmentToken = 0x707;
              nextSegmentToken = 0x702;
            }
            else {
              nextSegmentToken = 0x707;
              firstSegmentToken = 0x707;
            }
          }
          else {
            nextSegmentToken = 0x702;
            firstSegmentToken = 0x702;
          }
          listCursor = polygonList + 2;
          ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,firstSegmentToken) -
                                                   DOUBLE_00108d70));
          _gleFeedbackHitRecord(glContext,*polygonList);
          _gleFeedbackHitRecord(glContext,polygonList[1]);
          if (listCursor < polygonList + vertexEndThenListCount + -1) {
            do {
              ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,nextSegmentToken) - intToDoubleBiasThenForwardedF1)
                               );
              _gleFeedbackHitRecord(glContext,*listCursor);
              pairSecondVertexSlot = listCursor + 1;
              listCursor = listCursor + 2;
              _gleFeedbackHitRecord(glContext,*pairSecondVertexSlot);
            } while (listCursor < polygonList + vertexEndThenListCount + -1);
          }
        }
        return;
      }
    }
  }
  return;
}

/* _gleFeedbackLineLoopFunc_body @ 0xd845c (932 bytes) */
void _gleFeedbackLineLoopFunc_body(glContext)
  int glContext;
{
  uint *pairSecondVertexSlot;
  int copyOffset;
  undefined4 firstSegmentToken;
  int doublewordsLeft;
  uint closeSourceThenClipFlagsThenSecondVertex;
  bool vertexProgramThenFixedFunctionThenNewLoop;
  int bufferEndThenVertexEndThenListCount;
  int copyIndex;
  short vertexStride;
  undefined4 nextSegmentToken;
  uint *polygonList;
  uint vertexCursor;
  uint *listCursor;
  uint vertexCountThenCopyCursor;
  double intToDoubleBiasThenForwardedF1;
  double f1AfterCall;
  
  vertexProgramThenFixedFunctionThenNewLoop = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    vertexProgramThenFixedFunctionThenNewLoop = true;
  }
  vertexStride = *(short *)(glContext + 0x487c);
  vertexCursor = *(uint *)(glContext + 0x4854);
  if ((int)vertexStride != 0) {
    bufferEndThenVertexEndThenListCount = *(int *)(glContext + 0x4858);
    vertexCountThenCopyCursor = (bufferEndThenVertexEndThenListCount - vertexCursor) / (uint)(int)vertexStride;
    if (*(short *)(glContext + 0x4a10) < 0) {
      if ((int)vertexCountThenCopyCursor < 1) {
        return;
      }
      closeSourceThenClipFlagsThenSecondVertex = vertexCursor - 0x100;
      if (*(char *)(glContext + 0x4a18) == '\0') {
        closeSourceThenClipFlagsThenSecondVertex = vertexCursor;
      }
      copyIndex = 0;
      doublewordsLeft = (int)vertexStride >> 3;
      if (0 < doublewordsLeft) {
        do {
          copyOffset = copyIndex * 8;
          copyIndex = copyIndex + 1;
          *(undefined8 *)(copyOffset + bufferEndThenVertexEndThenListCount) = *(undefined8 *)(copyOffset + closeSourceThenClipFlagsThenSecondVertex);
          doublewordsLeft = doublewordsLeft + -1;
        } while (doublewordsLeft != 0);
        vertexStride = *(short *)(glContext + 0x487c);
      }
      vertexCountThenCopyCursor = vertexCountThenCopyCursor + 1;
      *(int *)(glContext + 0x4858) = bufferEndThenVertexEndThenListCount + vertexStride;
    }
    vertexProgramThenFixedFunctionThenNewLoop = !vertexProgramThenFixedFunctionThenNewLoop;
    if (vertexProgramThenFixedFunctionThenNewLoop) {
      closeSourceThenClipFlagsThenSecondVertex = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCountThenCopyCursor);
    }
    else {
      closeSourceThenClipFlagsThenSecondVertex = _gleVPEmulate(glContext,vertexCountThenCopyCursor);
    }
    if ((closeSourceThenClipFlagsThenSecondVertex & 0xff00) == 0) {
      if (vertexProgramThenFixedFunctionThenNewLoop) {
        if (*(char *)(glContext + 0x53e4) != '\0') {
          (**(code **)(glContext + 0x53dc))(glContext,vertexCursor,vertexCountThenCopyCursor);
        }
        if (*(char *)(glContext + 0x50b4) != '\0') {
          (**(code **)(glContext + 0x5064))(glContext,vertexCursor,vertexCountThenCopyCursor);
        }
        if ((*(char *)(glContext + 0x30aa) != '\0') || (*(char *)(glContext + 0x53e6) != '\0')) {
          (**(code **)(glContext + 0x5068))(glContext,vertexCursor,vertexCountThenCopyCursor);
        }
      }
      else {
        vertexCursor = *(uint *)(glContext + 0x4864);
      }
      if (((closeSourceThenClipFlagsThenSecondVertex & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        if ((vertexProgramThenFixedFunctionThenNewLoop) && (*(char *)(glContext + 0x53e5) != '\0')) {
          (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,vertexCountThenCopyCursor);
        }
        (**(code **)(glContext + 0x506c))(glContext,vertexCursor,vertexCountThenCopyCursor,0);
        if ((vertexProgramThenFixedFunctionThenNewLoop) && (*(char *)(glContext + 0x30aa) != '\0')) {
          (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,vertexCountThenCopyCursor);
        }
        intToDoubleBiasThenForwardedF1 = DOUBLE_00108d70;
        vertexProgramThenFixedFunctionThenNewLoop = *(char *)(glContext + 0x4a18) == '\0';
        if (1 < (int)vertexCountThenCopyCursor) {
          if (vertexProgramThenFixedFunctionThenNewLoop) {
            if (vertexProgramThenFixedFunctionThenNewLoop) {
              firstSegmentToken = 0x707;
              nextSegmentToken = 0x702;
            }
            else {
              nextSegmentToken = 0x707;
              firstSegmentToken = 0x707;
            }
          }
          else {
            nextSegmentToken = 0x702;
            firstSegmentToken = 0x702;
          }
          closeSourceThenClipFlagsThenSecondVertex = vertexCursor + 0x100;
          ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,firstSegmentToken) -
                                                   DOUBLE_00108d70));
          _gleFeedbackHitRecord(glContext,vertexCursor);
          _gleFeedbackHitRecord(glContext,closeSourceThenClipFlagsThenSecondVertex);
          vertexCursor = (vertexCursor + vertexCountThenCopyCursor * 0x100) - 0x100;
          if (closeSourceThenClipFlagsThenSecondVertex < vertexCursor) {
            do {
              vertexCountThenCopyCursor = closeSourceThenClipFlagsThenSecondVertex + 0x100;
              ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,nextSegmentToken) - intToDoubleBiasThenForwardedF1
                                                       ));
              _gleFeedbackHitRecord(glContext,closeSourceThenClipFlagsThenSecondVertex);
              _gleFeedbackHitRecord(glContext,vertexCountThenCopyCursor);
              closeSourceThenClipFlagsThenSecondVertex = vertexCountThenCopyCursor;
            } while (vertexCountThenCopyCursor < vertexCursor);
          }
        }
        return;
      }
      if ((vertexProgramThenFixedFunctionThenNewLoop) && (*(char *)(glContext + 0x53e5) != '\0')) {
        (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,vertexCountThenCopyCursor);
      }
      intToDoubleBiasThenForwardedF1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCountThenCopyCursor, 0);
      polygonList = *(uint **)(glContext + 0x4870);
      bufferEndThenVertexEndThenListCount = vertexCursor + vertexCountThenCopyCursor * 0x100;
      listCursor = polygonList;
      if (vertexProgramThenFixedFunctionThenNewLoop) {
        vertexCountThenCopyCursor = *(uint *)(glContext + 0x4858);
      }
      else {
        vertexCountThenCopyCursor = *(uint *)(glContext + 0x4854);
      }
      while (vertexCursor < bufferEndThenVertexEndThenListCount - 0x100U) {
        *listCursor = vertexCursor;
        _memcpy(vertexCountThenCopyCursor,vertexCursor + 0x100,0x100);
        listCursor[1] = vertexCountThenCopyCursor;
        vertexCountThenCopyCursor = vertexCountThenCopyCursor + 0x100;
        listCursor = listCursor + 2;
        vertexCursor = vertexCursor + 0x100;
        intToDoubleBiasThenForwardedF1 = f1AfterCall;
      }
      bufferEndThenVertexEndThenListCount = (int)listCursor - (int)polygonList >> 2;
      if (((*(char *)(glContext + 0x4e18) == '\0') ||
          (bufferEndThenVertexEndThenListCount = ((int (*)())_gleClipLinesPlane)(glContext,polygonList,bufferEndThenVertexEndThenListCount,intToDoubleBiasThenForwardedF1), bufferEndThenVertexEndThenListCount != 0)) &&
         (((closeSourceThenClipFlagsThenSecondVertex & 0xff) == 0 ||
          (bufferEndThenVertexEndThenListCount = ((int (*)())_gleClipLines)(glContext,polygonList,bufferEndThenVertexEndThenListCount,closeSourceThenClipFlagsThenSecondVertex & 0xff), bufferEndThenVertexEndThenListCount != 0)))) {
        if ((vertexProgramThenFixedFunctionThenNewLoop) && (*(char *)(glContext + 0x30aa) != '\0')) {
          (**(code **)(glContext + 0x4df0))(glContext,polygonList,bufferEndThenVertexEndThenListCount);
        }
        intToDoubleBiasThenForwardedF1 = DOUBLE_00108d70;
        vertexProgramThenFixedFunctionThenNewLoop = *(char *)(glContext + 0x4a18) == '\0';
        if (1 < bufferEndThenVertexEndThenListCount) {
          if (vertexProgramThenFixedFunctionThenNewLoop) {
            if (vertexProgramThenFixedFunctionThenNewLoop) {
              firstSegmentToken = 0x707;
              nextSegmentToken = 0x702;
            }
            else {
              nextSegmentToken = 0x707;
              firstSegmentToken = 0x707;
            }
          }
          else {
            nextSegmentToken = 0x702;
            firstSegmentToken = 0x702;
          }
          listCursor = polygonList + 2;
          ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,firstSegmentToken) -
                                                   DOUBLE_00108d70));
          _gleFeedbackHitRecord(glContext,*polygonList);
          _gleFeedbackHitRecord(glContext,polygonList[1]);
          if (listCursor < polygonList + bufferEndThenVertexEndThenListCount + -1) {
            do {
              ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,nextSegmentToken) - intToDoubleBiasThenForwardedF1
                                                       ));
              _gleFeedbackHitRecord(glContext,*listCursor);
              pairSecondVertexSlot = listCursor + 1;
              listCursor = listCursor + 2;
              _gleFeedbackHitRecord(glContext,*pairSecondVertexSlot);
            } while (listCursor < polygonList + bufferEndThenVertexEndThenListCount + -1);
          }
        }
        return;
      }
    }
  }
  return;
}

/* _gleRenderSmoothLinesFunc_body @ 0xd8828 (716 bytes) */
void _gleRenderSmoothLinesFunc_body(glContext)
  int glContext;
{
  bool texturingEnabled;
  uint uVar2;
  int texEnableBits;
  uint batchClipCodes;
  uint *puVar5;
  uint vertexCursor;
  uint *polygonList;
  int iVar8;
  double f1AfterCall;
  double fparam_1;
  
  texEnableBits = _gleTexEnableBits(glContext);
  vertexCursor = *(uint *)(glContext + 0x4854);
  iVar8 = (int)(*(int *)(glContext + 0x4858) - vertexCursor) >> 8;
  if ((1 < iVar8) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,iVar8), (batchClipCodes & 0xff00) == 0)) {
    texturingEnabled = texEnableBits != 0;
    fparam_1 = f1AfterCall;
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
      fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, iVar8);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, iVar8);
    }
    if ((*(char *)(glContext + 0x30aa) != '\0') || ((texturingEnabled && (*(char *)(glContext + 0x53e6) != '\0'))))
    {
      fparam_1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, iVar8);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (texturingEnabled) {
        if (*(char *)(glContext + 0x53e5) != '\0') {
          (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,iVar8);
        }
        (**(code **)(glContext + 0x506c))(glContext,vertexCursor,iVar8,0);
      }
      if (*(char *)(glContext + 0x30aa) != '\0') {
        (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,iVar8);
      }
                    
                    
      (**(code **)(glContext + 0x46b4))(*(undefined4 *)(glContext + 0x4688),vertexCursor,iVar8);
      return;
    }
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,iVar8);
      }
      fparam_1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, iVar8, 0);
    }
    uVar2 = vertexCursor + iVar8 * 0x100;
    polygonList = *(uint **)(glContext + 0x4870);
    if (vertexCursor < uVar2) {
      uVar2 = (uVar2 - vertexCursor) + 0xff >> 8;
      puVar5 = polygonList;
      do {
        *puVar5 = vertexCursor;
        vertexCursor = vertexCursor + 0x100;
        puVar5 = puVar5 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (iVar8 = ((int (*)())_gleClipLinesPlane)(glContext,polygonList,iVar8,fparam_1), iVar8 == 0)) {
      return;
    }
    if (((batchClipCodes & 0xff) == 0) ||
       (iVar8 = ((int (*)())_gleClipLines)(glContext,polygonList,iVar8,batchClipCodes & 0xff), iVar8 != 0)) {
      if (*(char *)(glContext + 0x30aa) != '\0') {
        (**(code **)(glContext + 0x4df0))(glContext,polygonList,iVar8);
      }
                    
                    
      (**(code **)(glContext + 0x46dc))(*(undefined4 *)(glContext + 0x4688),polygonList,iVar8,2);
      return;
    }
  }
  return;
}

/* _gleRenderSmoothLineStripFunc_body @ 0xd8af8 (728 bytes) */
void _gleRenderSmoothLineStripFunc_body(glContext)
  int glContext;
{
  bool texturingEnabled;
  char stripContinued;
  uint *vertexCursor;
  int texEnableBits;
  uint batchClipCodes;
  code *drawCallback;
  uint *polygonList;
  uint *listCursor;
  uint *firstVertex;
  int vertexCountThenListCount;
  uint copyDestination;
  double f1AfterCall;
  double forwardedFloatArg1;
  double f1AfterCall1;
  
  texEnableBits = _gleTexEnableBits(glContext);
  firstVertex = *(uint **)(glContext + 0x4854);
  vertexCountThenListCount = *(int *)(glContext + 0x4858) - (int)firstVertex >> 8;
  if ((vertexCountThenListCount < 2) ||
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,firstVertex,vertexCountThenListCount), (batchClipCodes & 0xff00) != 0)) {
    return;
  }
  texturingEnabled = texEnableBits != 0;
  forwardedFloatArg1 = f1AfterCall;
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
    forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, firstVertex, vertexCountThenListCount);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, firstVertex, vertexCountThenListCount);
  }
  if ((*(char *)(glContext + 0x30aa) != '\0') || ((texturingEnabled && (*(char *)(glContext + 0x53e6) != '\0')))) {
    forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, firstVertex, vertexCountThenListCount);
  }
  if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,firstVertex,vertexCountThenListCount);
      }
      (**(code **)(glContext + 0x506c))(glContext,firstVertex,vertexCountThenListCount,0);
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      (**(code **)(glContext + 0x4de8))(glContext,firstVertex,vertexCountThenListCount);
    }
    stripContinued = *(char *)(glContext + 0x4a18);
    drawCallback = *(code **)(glContext + 0x46b8);
    polygonList = firstVertex;
  }
  else {
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,firstVertex,vertexCountThenListCount);
      }
      forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, firstVertex, vertexCountThenListCount, 0);
    }
    polygonList = *(uint **)(glContext + 0x4870);
    copyDestination = *(uint *)(glContext + 0x4858);
    vertexCursor = firstVertex;
    listCursor = polygonList;
    while (vertexCursor < firstVertex + vertexCountThenListCount * 0x40 + -0x40) {
      *listCursor = (uint)vertexCursor;
      _memcpy(copyDestination,vertexCursor + 0x40,0x100);
      listCursor[1] = copyDestination;
      copyDestination = copyDestination + 0x100;
      listCursor = listCursor + 2;
      vertexCursor = vertexCursor + 0x40;
      forwardedFloatArg1 = f1AfterCall1;
    }
    vertexCountThenListCount = (int)listCursor - (int)polygonList >> 2;
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (vertexCountThenListCount = ((int (*)())_gleClipLinesPlane)(glContext,polygonList,vertexCountThenListCount,forwardedFloatArg1), vertexCountThenListCount == 0)) {
      return;
    }
    if (((batchClipCodes & 0xff) != 0) &&
       (vertexCountThenListCount = ((int (*)())_gleClipLines)(glContext,polygonList,vertexCountThenListCount,batchClipCodes & 0xff), vertexCountThenListCount == 0)) {
      return;
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      (**(code **)(glContext + 0x4df0))(glContext,polygonList,vertexCountThenListCount);
    }
    stripContinued = *(char *)(glContext + 0x4a18);
    drawCallback = *(code **)(glContext + 0x46dc);
  }
                    
                    
  (*drawCallback)(*(undefined4 *)(glContext + 0x4688),polygonList,vertexCountThenListCount,stripContinued == '\0');
  return;
}

/* _gleRenderSmoothLineLoopFunc_body @ 0xd8dd4 (824 bytes) */
void _gleRenderSmoothLineLoopFunc_body(glContext)
  int glContext;
{
  bool texturingEnabled;
  char cVar2;
  int copyWordsLeft;
  short vertexStride;
  int texEnableBits;
  uint batchClipCodes;
  uint *puVar7;
  int batchEnd;
  int copyWordIndex;
  code *UNRECOVERED_JUMPTABLE;
  uint *polygonList;
  uint *listCursor;
  uint *batchStart;
  int vertexCount;
  uint copyDestination;
  double f1AfterCall;
  double lastCalleeF1;
  double f1AfterCall1;
  
  texEnableBits = _gleTexEnableBits(glContext);
  batchStart = *(uint **)(glContext + 0x4854);
  batchEnd = *(int *)(glContext + 0x4858);
  vertexCount = batchEnd - (int)batchStart >> 8;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (vertexCount < 1) {
      return;
    }
    puVar7 = batchStart + -0x40;
    if (*(char *)(glContext + 0x4a18) == '\0') {
      puVar7 = batchStart;
    }
    vertexStride = *(short *)(glContext + 0x487c);
    copyWordIndex = 0;
    copyWordsLeft = (int)vertexStride >> 3;
    if (0 < copyWordsLeft) {
      do {
        *(undefined8 *)(copyWordIndex * 8 + batchEnd) = *(undefined8 *)(puVar7 + copyWordIndex * 2);
        copyWordsLeft = copyWordsLeft + -1;
        copyWordIndex = copyWordIndex + 1;
      } while (copyWordsLeft != 0);
      vertexStride = *(short *)(glContext + 0x487c);
    }
    vertexCount = vertexCount + 1;
    *(int *)(glContext + 0x4858) = batchEnd + vertexStride;
  }
  batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,batchStart,vertexCount);
  if ((batchClipCodes & 0xff00) != 0) {
    return;
  }
  texturingEnabled = texEnableBits != 0;
  lastCalleeF1 = f1AfterCall;
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
    lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, batchStart, vertexCount);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, batchStart, vertexCount);
  }
  if ((*(char *)(glContext + 0x30aa) != '\0') || ((texturingEnabled && (*(char *)(glContext + 0x53e6) != '\0')))) {
    lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, batchStart, vertexCount);
  }
  if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,batchStart,vertexCount);
      }
      (**(code **)(glContext + 0x506c))(glContext,batchStart,vertexCount,0);
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      (**(code **)(glContext + 0x4de8))(glContext,batchStart,vertexCount);
    }
    cVar2 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b8);
    polygonList = batchStart;
  }
  else {
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,batchStart,vertexCount);
      }
      lastCalleeF1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, batchStart, vertexCount, 0);
    }
    polygonList = *(uint **)(glContext + 0x4870);
    copyDestination = *(uint *)(glContext + 0x4858);
    puVar7 = batchStart;
    listCursor = polygonList;
    while (puVar7 < batchStart + vertexCount * 0x40 + -0x40) {
      *listCursor = (uint)puVar7;
      _memcpy(copyDestination,puVar7 + 0x40,0x100);
      listCursor[1] = copyDestination;
      copyDestination = copyDestination + 0x100;
      listCursor = listCursor + 2;
      puVar7 = puVar7 + 0x40;
      lastCalleeF1 = f1AfterCall1;
    }
    vertexCount = (int)listCursor - (int)polygonList >> 2;
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (vertexCount = ((int (*)())_gleClipLinesPlane)(glContext,polygonList,vertexCount,lastCalleeF1), vertexCount == 0)) {
      return;
    }
    if (((batchClipCodes & 0xff) != 0) &&
       (vertexCount = ((int (*)())_gleClipLines)(glContext,polygonList,vertexCount,batchClipCodes & 0xff), vertexCount == 0)) {
      return;
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      (**(code **)(glContext + 0x4df0))(glContext,polygonList,vertexCount);
    }
    cVar2 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46dc);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(glContext + 0x4688),polygonList,vertexCount,cVar2 == '\0');
  return;
}

/* _gleRenderFlatLinesFunc_body @ 0xd9110 (780 bytes) */
void _gleRenderFlatLinesFunc_body(glContext)
  int glContext;
{
  bool texturingEnabled;
  int texEnableBits;
  uint secondVertexCursor;
  uint batchClipCodes;
  uint *polygonList;
  uint vertexEndThenRemainingVertices;
  int vertexCountThenListCount;
  uint vertexCursor;
  uint *listCursorThenSecondSlotCursor;
  double f1AfterCall;
  double forwardedFloatArg1;
  
  texEnableBits = _gleTexEnableBits(glContext);
  vertexCursor = *(uint *)(glContext + 0x4854);
  vertexCountThenListCount = (int)(*(int *)(glContext + 0x4858) - vertexCursor) >> 8;
  if ((1 < vertexCountThenListCount) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCountThenListCount), (batchClipCodes & 0xff00) == 0)) {
    texturingEnabled = texEnableBits != 0;
    forwardedFloatArg1 = f1AfterCall;
    if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
      forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexCursor, vertexCountThenListCount);
    }
    if (*(char *)(glContext + 0x50b4) != '\0') {
      forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCountThenListCount);
    }
    if ((*(char *)(glContext + 0x30aa) != '\0') || ((texturingEnabled && (*(char *)(glContext + 0x53e6) != '\0'))))
    {
      forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexCursor, vertexCountThenListCount);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      if (texturingEnabled) {
        if (*(char *)(glContext + 0x53e5) != '\0') {
          (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,vertexCountThenListCount);
        }
        (**(code **)(glContext + 0x506c))(glContext,vertexCursor,vertexCountThenListCount,0);
      }
      if (*(char *)(glContext + 0x30aa) != '\0') {
        for (secondVertexCursor = vertexCursor + 0x100; secondVertexCursor < vertexCursor + vertexCountThenListCount * 0x100; secondVertexCursor = secondVertexCursor + 0x200) {
          (**(code **)(glContext + 0x4de8))(glContext,secondVertexCursor,1);
        }
      }
                    
                    
      (**(code **)(glContext + 0x46b4))(*(undefined4 *)(glContext + 0x4688),vertexCursor,vertexCountThenListCount);
      return;
    }
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,vertexCountThenListCount);
      }
      forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCountThenListCount, 0);
    }
    polygonList = *(uint **)(glContext + 0x4870);
    vertexEndThenRemainingVertices = vertexCursor + vertexCountThenListCount * 0x100;
    if (vertexCursor < vertexEndThenRemainingVertices) {
      vertexEndThenRemainingVertices = (vertexEndThenRemainingVertices - vertexCursor) + 0xff >> 8;
      listCursorThenSecondSlotCursor = polygonList;
      do {
        *listCursorThenSecondSlotCursor = vertexCursor;
        vertexCursor = vertexCursor + 0x100;
        listCursorThenSecondSlotCursor = listCursorThenSecondSlotCursor + 1;
        vertexEndThenRemainingVertices = vertexEndThenRemainingVertices - 1;
      } while (vertexEndThenRemainingVertices != 0);
    }
    if (((*(char *)(glContext + 0x4e18) == '\0') ||
        (vertexCountThenListCount = ((int (*)())_gleClipLinesPlane)(glContext,polygonList,vertexCountThenListCount,forwardedFloatArg1), vertexCountThenListCount != 0)) &&
       (((batchClipCodes & 0xff) == 0 ||
        (vertexCountThenListCount = ((int (*)())_gleClipLines)(glContext,polygonList,vertexCountThenListCount,batchClipCodes & 0xff), vertexCountThenListCount != 0)))) {
      if (*(char *)(glContext + 0x30aa) != '\0') {
        for (listCursorThenSecondSlotCursor = polygonList + 1; listCursorThenSecondSlotCursor < polygonList + vertexCountThenListCount; listCursorThenSecondSlotCursor = listCursorThenSecondSlotCursor + 2) {
          (**(code **)(glContext + 0x4df0))(glContext,listCursorThenSecondSlotCursor,1);
        }
      }
                    
                    
      (**(code **)(glContext + 0x46dc))(*(undefined4 *)(glContext + 0x4688),polygonList,vertexCountThenListCount,2);
      return;
    }
  }
  return;
}

/* _gleRenderFlatLineStripFunc_body @ 0xd9420 (760 bytes) */
void _gleRenderFlatLineStripFunc_body(glContext)
  int glContext;
{
  bool texturingEnabled;
  char cVar2;
  uint *sourceVertex;
  int texEnableBits;
  uint batchClipCodes;
  code *UNRECOVERED_JUMPTABLE;
  uint *polygonList;
  int vertexCount;
  uint copyDestination;
  uint *vertexArrayThenLightCursor;
  uint *listCursor;
  double f1AfterCall;
  double lastCalleeF1;
  double f1AfterCall1;
  
  texEnableBits = _gleTexEnableBits(glContext);
  vertexArrayThenLightCursor = *(uint **)(glContext + 0x4854);
  vertexCount = *(int *)(glContext + 0x4858) - (int)vertexArrayThenLightCursor >> 8;
  if ((vertexCount < 2) ||
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexArrayThenLightCursor,vertexCount), (batchClipCodes & 0xff00) != 0)) {
    return;
  }
  texturingEnabled = texEnableBits != 0;
  lastCalleeF1 = f1AfterCall;
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
    lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, vertexArrayThenLightCursor, vertexCount);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexArrayThenLightCursor, vertexCount);
  }
  if ((*(char *)(glContext + 0x30aa) != '\0') || ((texturingEnabled && (*(char *)(glContext + 0x53e6) != '\0')))) {
    lastCalleeF1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, vertexArrayThenLightCursor, vertexCount);
  }
  if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,vertexArrayThenLightCursor,vertexCount);
      }
      (**(code **)(glContext + 0x506c))(glContext,vertexArrayThenLightCursor,vertexCount,0);
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      (**(code **)(glContext + 0x4de8))(glContext,vertexArrayThenLightCursor + 0x40,vertexCount + -1);
    }
    cVar2 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b8);
    polygonList = vertexArrayThenLightCursor;
  }
  else {
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,vertexArrayThenLightCursor,vertexCount);
      }
      lastCalleeF1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexArrayThenLightCursor, vertexCount, 0);
    }
    polygonList = *(uint **)(glContext + 0x4870);
    copyDestination = *(uint *)(glContext + 0x4858);
    sourceVertex = vertexArrayThenLightCursor;
    listCursor = polygonList;
    while (sourceVertex < vertexArrayThenLightCursor + vertexCount * 0x40 + -0x40) {
      *listCursor = (uint)sourceVertex;
      _memcpy(copyDestination,sourceVertex + 0x40,0x100);
      listCursor[1] = copyDestination;
      copyDestination = copyDestination + 0x100;
      listCursor = listCursor + 2;
      sourceVertex = sourceVertex + 0x40;
      lastCalleeF1 = f1AfterCall1;
    }
    vertexCount = (int)listCursor - (int)polygonList >> 2;
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (vertexCount = ((int (*)())_gleClipLinesPlane)(glContext,polygonList,vertexCount,lastCalleeF1), vertexCount == 0)) {
      return;
    }
    if (((batchClipCodes & 0xff) != 0) &&
       (vertexCount = ((int (*)())_gleClipLines)(glContext,polygonList,vertexCount,batchClipCodes & 0xff), vertexCount == 0)) {
      return;
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      for (vertexArrayThenLightCursor = polygonList + 1; vertexArrayThenLightCursor < polygonList + vertexCount; vertexArrayThenLightCursor = vertexArrayThenLightCursor + 2) {
        (**(code **)(glContext + 0x4df0))(glContext,vertexArrayThenLightCursor,1);
      }
    }
    cVar2 = *(char *)(glContext + 0x4a18);
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46dc);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(glContext + 0x4688),polygonList,vertexCount,cVar2 == '\0');
  return;
}

/* _gleRenderFlatLineLoopFunc_body @ 0xd971c (856 bytes) */
void _gleRenderFlatLineLoopFunc_body(glContext)
  int glContext;
{
  bool texturingEnabled;
  char loopContinued;
  int doublewordsLeft;
  short vertexStride;
  int texEnableBits;
  uint batchClipCodes;
  uint *closeSourceThenVertexCursor;
  int bufferEnd;
  int copyIndex;
  code *drawCallback;
  uint *polygonList;
  uint copyDestination;
  int vertexCountThenListCount;
  uint *firstVertexThenListCursor;
  uint *listCursor;
  double f1AfterCall;
  double forwardedFloatArg1;
  double f1AfterCall1;
  
  texEnableBits = _gleTexEnableBits(glContext);
  firstVertexThenListCursor = *(uint **)(glContext + 0x4854);
  bufferEnd = *(int *)(glContext + 0x4858);
  vertexCountThenListCount = bufferEnd - (int)firstVertexThenListCursor >> 8;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (vertexCountThenListCount < 1) {
      return;
    }
    closeSourceThenVertexCursor = firstVertexThenListCursor + -0x40;
    if (*(char *)(glContext + 0x4a18) == '\0') {
      closeSourceThenVertexCursor = firstVertexThenListCursor;
    }
    vertexStride = *(short *)(glContext + 0x487c);
    copyIndex = 0;
    doublewordsLeft = (int)vertexStride >> 3;
    if (0 < doublewordsLeft) {
      do {
        *(undefined8 *)(copyIndex * 8 + bufferEnd) = *(undefined8 *)(closeSourceThenVertexCursor + copyIndex * 2);
        doublewordsLeft = doublewordsLeft + -1;
        copyIndex = copyIndex + 1;
      } while (doublewordsLeft != 0);
      vertexStride = *(short *)(glContext + 0x487c);
    }
    vertexCountThenListCount = vertexCountThenListCount + 1;
    *(int *)(glContext + 0x4858) = bufferEnd + vertexStride;
  }
  batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,firstVertexThenListCursor,vertexCountThenListCount);
  if ((batchClipCodes & 0xff00) != 0) {
    return;
  }
  texturingEnabled = texEnableBits != 0;
  forwardedFloatArg1 = f1AfterCall;
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
    forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x53dc))(glContext, firstVertexThenListCursor, vertexCountThenListCount);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, firstVertexThenListCursor, vertexCountThenListCount);
  }
  if ((*(char *)(glContext + 0x30aa) != '\0') || ((texturingEnabled && (*(char *)(glContext + 0x53e6) != '\0')))) {
    forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5068))(glContext, firstVertexThenListCursor, vertexCountThenListCount);
  }
  if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,firstVertexThenListCursor,vertexCountThenListCount);
      }
      (**(code **)(glContext + 0x506c))(glContext,firstVertexThenListCursor,vertexCountThenListCount,0);
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      (**(code **)(glContext + 0x4de8))(glContext,firstVertexThenListCursor + 0x40,vertexCountThenListCount + -1);
    }
    loopContinued = *(char *)(glContext + 0x4a18);
    drawCallback = *(code **)(glContext + 0x46b8);
    polygonList = firstVertexThenListCursor;
  }
  else {
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,firstVertexThenListCursor,vertexCountThenListCount);
      }
      forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, firstVertexThenListCursor, vertexCountThenListCount, 0);
    }
    polygonList = *(uint **)(glContext + 0x4870);
    copyDestination = *(uint *)(glContext + 0x4858);
    closeSourceThenVertexCursor = firstVertexThenListCursor;
    listCursor = polygonList;
    while (closeSourceThenVertexCursor < firstVertexThenListCursor + vertexCountThenListCount * 0x40 + -0x40) {
      *listCursor = (uint)closeSourceThenVertexCursor;
      _memcpy(copyDestination,closeSourceThenVertexCursor + 0x40,0x100);
      listCursor[1] = copyDestination;
      copyDestination = copyDestination + 0x100;
      listCursor = listCursor + 2;
      closeSourceThenVertexCursor = closeSourceThenVertexCursor + 0x40;
      forwardedFloatArg1 = f1AfterCall1;
    }
    vertexCountThenListCount = (int)listCursor - (int)polygonList >> 2;
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (vertexCountThenListCount = ((int (*)())_gleClipLinesPlane)(glContext,polygonList,vertexCountThenListCount,forwardedFloatArg1), vertexCountThenListCount == 0)) {
      return;
    }
    if (((batchClipCodes & 0xff) != 0) &&
       (vertexCountThenListCount = ((int (*)())_gleClipLines)(glContext,polygonList,vertexCountThenListCount,batchClipCodes & 0xff), vertexCountThenListCount == 0)) {
      return;
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      for (firstVertexThenListCursor = polygonList + 1; firstVertexThenListCursor < polygonList + vertexCountThenListCount; firstVertexThenListCursor = firstVertexThenListCursor + 2) {
        (**(code **)(glContext + 0x4df0))(glContext,firstVertexThenListCursor,1);
      }
    }
    loopContinued = *(char *)(glContext + 0x4a18);
    drawCallback = *(code **)(glContext + 0x46dc);
  }
                    
                    
  (*drawCallback)(*(undefined4 *)(glContext + 0x4688),polygonList,vertexCountThenListCount,loopContinued == '\0');
  return;
}

/* _gleSelectLinesFunc @ 0xd9a74 (412 bytes) */
void _gleSelectLinesFunc(glContext)
  int glContext;
{
  bool vertexProgramActive;
  uint uVar2;
  uint batchClipCodes;
  uint *listCursor;
  uint vertexCount;
  uint vertexCursor;
  uint *polygonList;
  double f1AfterCall;
  double dVar8;
  
  vertexProgramActive = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    vertexProgramActive = true;
  }
  vertexCursor = *(uint *)(glContext + 0x4854);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (vertexCount = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
      1 < (int)vertexCount)) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount), (batchClipCodes & 0xff00) == 0)) {
    dVar8 = f1AfterCall;
    if (vertexProgramActive) {
      vertexCursor = *(uint *)(glContext + 0x4864);
    }
    else if (*(char *)(glContext + 0x4e18) != '\0') {
      dVar8 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCount);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      _gleSelectLines(glContext,vertexCursor,vertexCount);
      return;
    }
    uVar2 = vertexCursor + vertexCount * 0x100;
    polygonList = *(uint **)(glContext + 0x4870);
    if (vertexCursor < uVar2) {
      uVar2 = (uVar2 - vertexCursor) + 0xff >> 8;
      listCursor = polygonList;
      do {
        *listCursor = vertexCursor;
        vertexCursor = vertexCursor + 0x100;
        listCursor = listCursor + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (vertexCount = ((int (*)())_gleClipLinesPlane)(glContext,polygonList,vertexCount,dVar8), vertexCount == 0)) {
      return;
    }
    if (((batchClipCodes & 0xff) == 0) ||
       (vertexCount = ((int (*)())_gleClipLines)(glContext,polygonList,vertexCount,batchClipCodes & 0xff), vertexCount != 0)) {
      _gleSelectLinesPtr(glContext,polygonList,vertexCount);
      return;
    }
  }
  return;
}

/* _gleSelectLineStripFunc_body @ 0xd9c14 (484 bytes) */
void _gleSelectLineStripFunc_body(glContext)
  int glContext;
{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  uint batchClipCodes;
  uint *polygonList;
  uint uVar6;
  uint vertexCount;
  uint vertexCursor;
  double f1AfterCall;
  double dVar8;
  double f1AfterCall1;
  
  bVar1 = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    bVar1 = true;
  }
  vertexCursor = *(uint *)(glContext + 0x4854);
  if ((((int)*(short *)(glContext + 0x487c) != 0) &&
      (vertexCount = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
      1 < (int)vertexCount)) &&
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCount), (batchClipCodes & 0xff00) == 0)) {
    dVar8 = f1AfterCall;
    if (bVar1) {
      vertexCursor = *(uint *)(glContext + 0x4864);
    }
    else if (*(char *)(glContext + 0x4e18) != '\0') {
      dVar8 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCount);
    }
    if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
      _gleSelectLineStrip(glContext,vertexCursor,vertexCount);
      return;
    }
    polygonList = *(uint **)(glContext + 0x4870);
    iVar3 = vertexCursor + vertexCount * 0x100;
    puVar2 = polygonList;
    if (bVar1) {
      uVar6 = *(uint *)(glContext + 0x4854);
    }
    else {
      uVar6 = *(uint *)(glContext + 0x4858);
    }
    while (vertexCursor < iVar3 - 0x100U) {
      *puVar2 = vertexCursor;
      _memcpy(uVar6,vertexCursor + 0x100,0x100);
      puVar2[1] = uVar6;
      uVar6 = uVar6 + 0x100;
      puVar2 = puVar2 + 2;
      vertexCursor = vertexCursor + 0x100;
      dVar8 = f1AfterCall1;
    }
    iVar3 = (int)puVar2 - (int)polygonList >> 2;
    if (((*(char *)(glContext + 0x4e18) == '\0') ||
        (iVar3 = ((int (*)())_gleClipLinesPlane)(glContext,polygonList,iVar3,dVar8), iVar3 != 0)) &&
       (((batchClipCodes & 0xff) == 0 ||
        (iVar3 = ((int (*)())_gleClipLines)(glContext,polygonList,iVar3,batchClipCodes & 0xff), iVar3 != 0)))) {
      _gleSelectLinesPtr(glContext,polygonList,iVar3);
      return;
    }
  }
  return;
}

/* _gleSelectLineLoopFunc_body @ 0xd9dfc (588 bytes) */
void _gleSelectLineLoopFunc_body(glContext)
  int glContext;
{
  int copyOffset;
  bool vertexProgramPath;
  uint *listCursor;
  int doublewordsLeft;
  uint closeSource;
  uint batchClipCodes;
  int bufferEndThenVertexEndThenListCount;
  short vertexStride;
  int copyIndex;
  uint *polygonList;
  uint vertexCursor;
  uint vertexCountThenCopyDestination;
  double f1AfterCall;
  double forwardedFloatArg1;
  double f1AfterCall1;
  
  vertexProgramPath = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    vertexProgramPath = true;
  }
  vertexStride = *(short *)(glContext + 0x487c);
  vertexCursor = *(uint *)(glContext + 0x4854);
  if ((int)vertexStride != 0) {
    bufferEndThenVertexEndThenListCount = *(int *)(glContext + 0x4858);
    vertexCountThenCopyDestination = (bufferEndThenVertexEndThenListCount - vertexCursor) / (uint)(int)vertexStride;
    if (*(short *)(glContext + 0x4a10) < 0) {
      if ((int)vertexCountThenCopyDestination < 1) {
        return;
      }
      closeSource = vertexCursor - 0x100;
      if (*(char *)(glContext + 0x4a18) == '\0') {
        closeSource = vertexCursor;
      }
      copyIndex = 0;
      doublewordsLeft = (int)vertexStride >> 3;
      if (0 < doublewordsLeft) {
        do {
          copyOffset = copyIndex * 8;
          copyIndex = copyIndex + 1;
          *(undefined8 *)(copyOffset + bufferEndThenVertexEndThenListCount) = *(undefined8 *)(copyOffset + closeSource);
          doublewordsLeft = doublewordsLeft + -1;
        } while (doublewordsLeft != 0);
        vertexStride = *(short *)(glContext + 0x487c);
      }
      vertexCountThenCopyDestination = vertexCountThenCopyDestination + 1;
      *(int *)(glContext + 0x4858) = bufferEndThenVertexEndThenListCount + vertexStride;
    }
    batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCountThenCopyDestination);
    if ((batchClipCodes & 0xff00) == 0) {
      forwardedFloatArg1 = f1AfterCall;
      if (vertexProgramPath) {
        vertexCursor = *(uint *)(glContext + 0x4864);
      }
      else if (*(char *)(glContext + 0x4e18) != '\0') {
        forwardedFloatArg1 = (double)(**(double ( **)(int,int,int))(glContext + 0x5064))(glContext, vertexCursor, vertexCountThenCopyDestination);
      }
      if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        _gleSelectLineStrip(glContext,vertexCursor,vertexCountThenCopyDestination);
        return;
      }
      polygonList = *(uint **)(glContext + 0x4870);
      bufferEndThenVertexEndThenListCount = vertexCursor + vertexCountThenCopyDestination * 0x100;
      listCursor = polygonList;
      if (vertexProgramPath) {
        vertexCountThenCopyDestination = *(uint *)(glContext + 0x4854);
      }
      else {
        vertexCountThenCopyDestination = *(uint *)(glContext + 0x4858);
      }
      while (vertexCursor < bufferEndThenVertexEndThenListCount - 0x100U) {
        *listCursor = vertexCursor;
        _memcpy(vertexCountThenCopyDestination,vertexCursor + 0x100,0x100);
        listCursor[1] = vertexCountThenCopyDestination;
        vertexCountThenCopyDestination = vertexCountThenCopyDestination + 0x100;
        listCursor = listCursor + 2;
        vertexCursor = vertexCursor + 0x100;
        forwardedFloatArg1 = f1AfterCall1;
      }
      bufferEndThenVertexEndThenListCount = (int)listCursor - (int)polygonList >> 2;
      if (((*(char *)(glContext + 0x4e18) == '\0') ||
          (bufferEndThenVertexEndThenListCount = ((int (*)())_gleClipLinesPlane)(glContext,polygonList,bufferEndThenVertexEndThenListCount,forwardedFloatArg1), bufferEndThenVertexEndThenListCount != 0)) &&
         (((batchClipCodes & 0xff) == 0 ||
          (bufferEndThenVertexEndThenListCount = ((int (*)())_gleClipLines)(glContext,polygonList,bufferEndThenVertexEndThenListCount,batchClipCodes & 0xff), bufferEndThenVertexEndThenListCount != 0)))) {
        _gleSelectLinesPtr(glContext,polygonList,bufferEndThenVertexEndThenListCount);
        return;
      }
    }
  }
  return;
}

/* _gleVAClipLine @ 0xda048 (320 bytes) */
int _gleVAClipLine(glContext, forwardedArg2, clipCodes, lineIndices)
  int glContext;
  undefined4 forwardedArg2;
  int clipCodes;
  int *lineIndices;
{
  byte combinedCodes;
  int *newFreeIndexCursor;
  undefined4 result;
  int newEndVertex;
  int newStartVertex;
  int startVertex;
  int *freeIndexCursor;
  int endVertex;
  byte endCode;
  byte startCode;
  byte planeBit;
  
  startVertex = *lineIndices;
  endVertex = lineIndices[1];
  startCode = *(byte *)(clipCodes + startVertex) & 0x3f;
  freeIndexCursor = *(int **)(glContext + 0x499c);
  endCode = *(byte *)(clipCodes + endVertex) & 0x3f;
  result = 0;
  newStartVertex = *freeIndexCursor;
  newEndVertex = freeIndexCursor[1];
  if ((startCode & endCode) == 0) {
    combinedCodes = startCode | endCode;
    result = 2;
    if (combinedCodes != 0) {
      planeBit = 1;
      do {
        if ((combinedCodes & planeBit) != 0) {
          if ((startCode & planeBit) == 0) {
            (**(code **)(glContext + 0x49c4))(glContext,forwardedArg2,clipCodes,endVertex,startVertex,newEndVertex,planeBit);
            endCode = *(byte *)(clipCodes + newEndVertex);
            endVertex = newEndVertex;
          }
          else {
            (**(code **)(glContext + 0x49c4))(glContext,forwardedArg2,clipCodes,startVertex,endVertex,newStartVertex,planeBit);
            startCode = *(byte *)(clipCodes + newStartVertex);
            startVertex = newStartVertex;
          }
          if ((startCode & endCode) != 0) {
            return 0;
          }
          combinedCodes = startCode | endCode;
          if (combinedCodes == 0) break;
        }
        planeBit = planeBit << 1;
      } while (planeBit < 0x21);
      if (startVertex == newStartVertex) {
        newFreeIndexCursor = freeIndexCursor + 1;
        *lineIndices = newStartVertex;
        if (endVertex == newEndVertex) {
          newFreeIndexCursor = freeIndexCursor + 2;
          lineIndices[1] = endVertex;
        }
        *(int **)(glContext + 0x499c) = newFreeIndexCursor;
      }
      else {
        lineIndices[1] = endVertex;
        freeIndexCursor[1] = newStartVertex;
        *(int **)(glContext + 0x499c) = freeIndexCursor + 1;
      }
      result = 2;
    }
  }
  return result;
}

/* _gleVAClipPoly @ 0xda188 (692 bytes) */
int _gleVAClipPoly(glContext, forwardedArg2, clipCodes, indexCount, indices)
  int glContext;
  undefined4 forwardedArg2;
  int clipCodes;
  int indexCount;
  uint *indices;
{
  byte newCode;
  uint vertexIndex;
  uint newVertex;
  byte bVar3;
  int resultCount;
  uint firstGeneratedIndex;
  uint *dstPoly;
  uint *puVar7;
  uint *srcPoly;
  uint *puVar9;
  int planeIndex;
  int copyIndex;
  byte orCodes;
  uint *freeIndexCursor;
  uint *srcEnd;
  uint *dstCursor;
  uint remaining;
  uint edgeVertexIndex;
  int copyRemaining;
  undefined4 uStack0000001c;
  uint local_f0 [20];
  uint local_a0 [21];
  
  firstGeneratedIndex = *(int *)(glContext + 0x4988) + *(int *)(glContext + 0x4984);
  orCodes = 0;
  bVar3 = 0xff;
  freeIndexCursor = *(uint **)(glContext + 0x499c);
  if (indices < indices + indexCount) {
    remaining = (uint)((int)(indices + indexCount) + (3 - (int)indices)) >> 2;
    puVar9 = indices;
    do {
      vertexIndex = *puVar9;
      puVar9 = puVar9 + 1;
      bVar3 = bVar3 & *(byte *)(clipCodes + vertexIndex);
      orCodes = orCodes | *(byte *)(clipCodes + vertexIndex);
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  resultCount = 0;
  if (((bVar3 & 0x3f) == 0) && (resultCount = indexCount, (orCodes & 0xc3) != 0)) {
    srcEnd = indices + indexCount;
    resultCount = 0;
    planeIndex = 0;
    bVar3 = 1;
    dstPoly = local_f0;
    srcPoly = indices;
    puVar9 = local_a0;
    uStack0000001c = forwardedArg2;
    do {
      puVar7 = dstPoly;
      if ((orCodes & bVar3) != 0) {
        *srcEnd = *srcPoly;
        puVar7 = srcPoly + 1;
        srcEnd[1] = *puVar7;
        dstCursor = dstPoly;
        for (; puVar7 <= srcEnd; puVar7 = puVar7 + 1) {
          edgeVertexIndex = *puVar7;
          if (((&_out_codes)[planeIndex] & ~*(byte *)(clipCodes + edgeVertexIndex)) == 0) {
            if ((bVar3 & *(byte *)(clipCodes + puVar7[1])) == 0) {
              newVertex = *freeIndexCursor;
              freeIndexCursor = freeIndexCursor + 1;
              (**(code **)(glContext + 0x49c4))
                        (glContext,uStack0000001c,clipCodes,edgeVertexIndex,puVar7[1],newVertex,bVar3);
              newCode = *(byte *)(clipCodes + newVertex);
              *dstCursor = newVertex;
              dstCursor = dstCursor + 1;
              edgeVertexIndex = *puVar7;
              orCodes = orCodes | newCode;
            }
            if (firstGeneratedIndex <= edgeVertexIndex) {
              *puVar9 = edgeVertexIndex;
LAB_000da318:
              puVar9 = puVar9 + 1;
            }
          }
          else if ((bVar3 & *(byte *)(clipCodes + edgeVertexIndex)) == 0) {
            *dstCursor = edgeVertexIndex;
            dstCursor = dstCursor + 1;
            edgeVertexIndex = puVar7[1];
            if (((&_out_codes)[planeIndex] & ~*(byte *)(clipCodes + edgeVertexIndex)) == 0) {
              newVertex = *freeIndexCursor;
              freeIndexCursor = freeIndexCursor + 1;
              (**(code **)(glContext + 0x49c4))
                        (glContext,uStack0000001c,clipCodes,edgeVertexIndex,*puVar7,newVertex,bVar3);
              newCode = *(byte *)(clipCodes + newVertex);
              *dstCursor = newVertex;
              orCodes = orCodes | newCode;
LAB_000da384:
              dstCursor = dstCursor + 1;
            }
            else if ((bVar3 & *(byte *)(clipCodes + edgeVertexIndex)) != 0) goto LAB_000da380;
          }
          else if ((bVar3 & *(byte *)(clipCodes + puVar7[-1])) != 0) {
            if ((bVar3 & *(byte *)(clipCodes + puVar7[1])) == 0) {
LAB_000da380:
              *dstCursor = edgeVertexIndex;
              goto LAB_000da384;
            }
            if (firstGeneratedIndex <= edgeVertexIndex) {
              *puVar9 = edgeVertexIndex;
              goto LAB_000da318;
            }
          }
        }
        resultCount = (int)dstCursor - (int)dstPoly >> 2;
        if (local_a0 < puVar9) {
          remaining = (uint)((int)puVar9 + (3 - (int)local_a0)) >> 2;
          do {
            puVar9 = puVar9 + -1;
            freeIndexCursor = freeIndexCursor + -1;
            *freeIndexCursor = *puVar9;
            remaining = remaining - 1;
          } while (remaining != 0);
        }
        if (resultCount < 3) {
          return 0;
        }
        srcEnd = dstPoly + resultCount;
        puVar7 = srcPoly;
        srcPoly = dstPoly;
      }
      planeIndex = planeIndex + 1;
      bVar3 = bVar3 << 1;
      dstPoly = puVar7;
    } while (planeIndex < 6);
    if ((srcPoly != indices) && (copyIndex = 0, copyRemaining = resultCount, 0 < resultCount)) {
      do {
        indices[copyIndex] = srcPoly[copyIndex];
        copyRemaining = copyRemaining + -1;
        copyIndex = copyIndex + 1;
      } while (copyRemaining != 0);
    }
    *(uint **)(glContext + 0x499c) = freeIndexCursor;
  }
  return resultCount;
}

/* _gleFlushIndexStack @ 0xda43c (92 bytes) */
void _gleFlushIndexStack(glContext)
  int glContext;
{
  int *indexLimit;
  int *indexCursor;
  int nextIndexValue;
  uint remaining;
  
  indexCursor = (int *)(*(int *)(glContext + 0x49a0) + *(int *)(glContext + 0x4988) * 4);
  indexLimit = (int *)(*(int *)(glContext + 0x499c) + 0x48);
  *(int **)(glContext + 0x499c) = indexCursor;
  nextIndexValue = *(int *)(glContext + 0x4984) + *(int *)(glContext + 0x4988);
  if (indexCursor < indexLimit) {
    remaining = (uint)((int)indexLimit + (3 - (int)indexCursor)) >> 2;
    do {
      *indexCursor = nextIndexValue;
      indexCursor = indexCursor + 1;
      nextIndexValue = nextIndexValue + 1;
      remaining = remaining - 1;
    } while (remaining != 0);
  }
                    
                    
  (**(code **)(glContext + 0x47b8))(*(undefined4 *)(glContext + 0x4688));
  return;
}

/* _gleCompileTCLVertexArray @ 0xda498 (1052 bytes) */
int _gleCompileTCLVertexArray(glContext)
  int glContext;
{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  int *piVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int local_40 [6];
  
  iVar15 = 0;
  if (*(int *)(glContext + 0x49ac) == 0) {
    return glContext;
  }
  iVar16 = *(int *)(glContext + 0x4988);
  uVar14 = *(undefined4 *)(glContext + 0x49a4);
  uVar2 = *(ushort *)(glContext + 0x4990);
  uVar18 = *(uint *)(glContext + 0x4980);
  if (*(short *)(glContext + 0x4992) == 0) {
    uVar18 = uVar18 & 0xffff;
    *(undefined2 *)(glContext + 0x4992) = 1;
  }
  iVar11 = *(int *)(glContext + 0x49a0);
  uVar7 = *(uint *)(glContext + 0x49b0);
  iVar6 = *(int *)(glContext + 0x4994) + (*(int *)(glContext + 0x499c) - iVar11 >> 2);
  if ((uVar18 & 0x10) == 0) {
    if ((uVar18 & 8) == 0) {
      bVar1 = 7 < (uVar7 >> 0xc & 0xf);
    }
    else {
      if (7 < (uVar7 >> 0xc & 0xf)) goto LAB_000da56c;
      bVar1 = 0xb < (uVar7 >> 4 & 0xf);
    }
    if (bVar1) goto LAB_000da56c;
LAB_000da574:
    uVar18 = uVar18 & 0xfffffffb;
  }
  else {
    if ((((uVar7 >> 0xc & 0xf) < 8) && ((uVar7 >> 4 & 0xf) < 0xc)) && ((uVar7 & 0xf) < 0xc))
    goto LAB_000da574;
LAB_000da56c:
    uVar18 = uVar18 | 4;
  }
  uVar9 = uVar18 & 0xffff;
  if (uVar9 == uVar18 >> 0x10) {
    iVar3 = *(int *)(glContext + 0x4998) - iVar6;
    uVar17 = (uint)uVar2;
    goto LAB_000da680;
  }
  uVar17 = uVar18 & 4;
  if (uVar17 != (uVar18 >> 0x10 & 4)) {
    *(uint *)(glContext + 0x497c) = *(uint *)(glContext + 0x497c) | uVar18 & 0x1f;
  }
  if ((uVar18 & 0x10) == 0) {
    if ((uVar18 & 8) == 0) {
      if (uVar17 == 0) {
        uVar17 = 0x10;
        uVar12 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x7c);
      }
      else {
        uVar17 = 0x14;
        uVar12 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x82);
      }
    }
    else {
      if (uVar17 != 0) {
        uVar17 = 0x24;
        *(uint *)(glContext + 0x498c) = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x84);
        if ((*(uint *)(*(int *)(glContext + 0x468c) + 0x94) & 8) == 0) {
          uVar17 = 0x20;
        }
        goto LAB_000da61c;
      }
      uVar17 = 0x18;
      uVar12 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x7e);
    }
LAB_000da658:
    *(short *)(glContext + 0x4990) = (short)uVar17;
    *(uint *)(glContext + 0x498c) = uVar12;
  }
  else {
    if (uVar17 == 0) {
      uVar17 = 0x20;
      uVar12 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x80);
      goto LAB_000da658;
    }
    uVar17 = 0x34;
    *(uint *)(glContext + 0x498c) = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x86);
    if ((*(uint *)(*(int *)(glContext + 0x468c) + 0x94) & 8) == 0) {
      uVar17 = 0x2c;
    }
LAB_000da61c:
    *(short *)(glContext + 0x4990) = (short)uVar17;
  }
  iVar3 = 0;
  *(uint *)(glContext + 0x4980) = uVar9 | uVar18 << 0x10;
LAB_000da680:
  local_40[0] = iVar16 + 8;
  if (iVar3 < local_40[0]) {
    iVar15 = *(int *)(glContext + 0x49a8);
    bVar1 = iVar15 == 0;
    if (!bVar1) {
      (**(code **)(glContext + 0x47c8))(*(undefined4 *)(glContext + 0x4688),iVar15);
    }
    iVar6 = (**(code **)(glContext + 0x47c4))
                      (*(undefined4 *)(glContext + 0x4688),*(undefined4 *)(glContext + 0x498c),local_40)
    ;
    if (iVar6 == 0) {
      *(uint *)(glContext + 0x4980) = uVar9;
      *(undefined4 *)(glContext + 0x4998) = 0;
      *(undefined4 *)(glContext + 0x4994) = 0;
      *(undefined4 *)(glContext + 0x49a4) = 0;
      if (bVar1) {
        return 0;
      }
      uVar14 = (**(code **)(glContext + 0x47cc))(*(undefined4 *)(glContext + 0x4688),iVar15);
      *(undefined4 *)(glContext + 0x49a8) = 0;
      return uVar14;
    }
    *(undefined4 *)(glContext + 0x4994) = 0;
    *(int *)(glContext + 0x4998) = local_40[0];
    *(int *)(glContext + 0x49a8) = iVar6;
    *(int *)(glContext + 0x49a4) = iVar6;
    iVar11 = *(int *)(glContext + 0x49a0);
    uVar7 = *(uint *)(glContext + 0x49b0);
  }
  else {
    bVar1 = true;
    *(int *)(glContext + 0x4994) = iVar6;
    iVar6 = *(int *)(glContext + 0x49a8) + iVar6 * uVar17;
    *(int *)(glContext + 0x49a4) = iVar6;
  }
  *(int *)(glContext + 0x499c) = iVar11 + iVar16 * 4;
  uVar12 = 0;
  uVar9 = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334);
  if ((uVar9 & 0x10000) != 0) {
    uVar12 = 5;
  }
  if ((uVar9 & 0x40000) != 0) {
    uVar12 = uVar12 | 2;
  }
  if ((uVar9 & 0x1000000) != 0) {
    uVar12 = uVar12 | 8;
  }
  if ((uVar9 & 0x2000000) != 0) {
    uVar12 = uVar12 | 0x10;
  }
  piVar10 = *(int **)(glContext + 0x49b4);
  uVar18 = (uVar18 & uVar12) << 0x15 |
           (uVar18 & (*(uint *)(glContext + 0x497c) | ~uVar12) & 0x1f) << 0x10 | uVar7 | 0x30000000;
  piVar4 = piVar10;
  do {
    if (uVar18 == piVar4[2]) {
      if (piVar4 != piVar10) {
        piVar13 = (int *)piVar4[1];
        *piVar13 = *piVar4;
        *(int **)(*piVar4 + 4) = piVar13;
        puVar8 = (undefined4 *)piVar10[1];
        *puVar8 = piVar4;
        piVar4[1] = (int)puVar8;
        *piVar4 = (int)piVar10;
        piVar10[1] = (int)piVar4;
        *(int **)(glContext + 0x49b4) = piVar4;
      }
      pcVar5 = (code *)(piVar4 + 8);
      goto LAB_000da850;
    }
    piVar4 = (int *)*piVar4;
  } while (piVar4 != piVar10);
  if ((*(uint *)PTR__gle_processor_0011204c & 0x10) == 0) {
    pcVar5 = (code *)_gleBuildCompileFuncTCLNO(glContext,uVar18);
  }
  else {
    pcVar5 = (code *)_gleBuildCompileFuncTCLAV(glContext,uVar18);
  }
LAB_000da850:
  uVar14 = (*pcVar5)(glContext,iVar6,uVar14,uVar17,(uint)uVar2);
  *(uint *)(glContext + 0x497c) = ~*(uint *)(glContext + 0x4980) & 0x1f;
  if (!bVar1) {
    uVar14 = (**(code **)(glContext + 0x47cc))(*(undefined4 *)(glContext + 0x4688),iVar15);
  }
  return uVar14;
}

/* _gleCompileClippedVertexArray @ 0xda8b4 (1136 bytes) */
int _gleCompileClippedVertexArray(glContext)
  int glContext;
{
  bool skipBufferRelease;
  ushort cachedStride;
  uint bufferKind;
  uint enableFlags;
  int *interpCacheNode;
  int *newIndexCursor;
  int *compileCacheHead;
  undefined4 interpFunc;
  int *compileCacheNode;
  int *indexCursor;
  code *compiledFunc;
  int remainingCapacity;
  int cursorByteOffset;
  undefined4 *interpCacheTail;
  undefined4 *compileCacheTail;
  int iVar10;
  int indexArrayBase;
  int *interpCacheHead;
  int *compileNodePrev;
  int *interpNodePrev;
  undefined4 uVar13;
  undefined4 releaseResult;
  int iVar14;
  int vertexCount;
  uint vertexStride;
  int oldBuffer;
  uint formatFlagsThenCompileKey;
  int runValue;
  uint interpKey;
  uint enableMask;
  uint fillCount;
  int requestedSize [4];
  
  oldBuffer = 0;
  iVar14 = glContext;
  if (*(int *)(glContext + 0x49ac) != 0) {
    vertexCount = *(int *)(glContext + 0x4988);
    uVar13 = *(undefined4 *)(glContext + 0x49a4);
    cachedStride = *(ushort *)(glContext + 0x4990);
    formatFlagsThenCompileKey = *(uint *)(glContext + 0x4980);
    if (*(short *)(glContext + 0x4992) == 0) {
      indexArrayBase = *(int *)(glContext + 0x49a0);
    }
    else {
      formatFlagsThenCompileKey = formatFlagsThenCompileKey & 0xffff;
      *(undefined2 *)(glContext + 0x4992) = 0;
      indexArrayBase = *(int *)(glContext + 0x49a0);
      *(int *)(glContext + 0x499c) = indexArrayBase + *(int *)(*(int *)(glContext + 0x468c) + 0x88) * 4;
    }
    indexCursor = *(int **)(glContext + 0x499c) + 0x11;
    cursorByteOffset = (int)indexCursor - indexArrayBase;
    for (runValue = *(int *)(glContext + 0x4984) + (cursorByteOffset >> 2);
        (*(int **)(glContext + 0x499c) <= indexCursor && (cursorByteOffset = (int)indexCursor - indexArrayBase, *indexCursor == runValue))
        ; runValue = runValue + -1) {
      indexCursor = indexCursor + -1;
      cursorByteOffset = (int)indexCursor - indexArrayBase;
    }
    interpKey = formatFlagsThenCompileKey & 0xffff;
    iVar10 = *(int *)(glContext + 0x4994) + (cursorByteOffset >> 2) + 1;
    if (interpKey == formatFlagsThenCompileKey >> 0x10) {
      remainingCapacity = *(int *)(glContext + 0x4998) - iVar10;
      vertexStride = (uint)cachedStride;
    }
    else {
      *(uint *)(glContext + 0x4980) = interpKey | formatFlagsThenCompileKey << 0x10;
      if ((formatFlagsThenCompileKey & 0x10) == 0) {
        if ((formatFlagsThenCompileKey & 8) == 0) {
          if ((formatFlagsThenCompileKey & 4) == 0) {
            vertexStride = 0x14;
            bufferKind = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x7c);
          }
          else {
            vertexStride = 0x18;
            bufferKind = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x82);
          }
        }
        else if ((formatFlagsThenCompileKey & 4) == 0) {
          vertexStride = 0x1c;
          bufferKind = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x7e);
        }
        else {
          vertexStride = 0x20;
          bufferKind = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x84);
        }
      }
      else if ((formatFlagsThenCompileKey & 4) == 0) {
        vertexStride = 0x28;
        bufferKind = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x80);
      }
      else {
        vertexStride = 0x2c;
        bufferKind = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x86);
      }
      interpCacheHead = *(int **)(glContext + 0x49b8);
      *(short *)(glContext + 0x4990) = (short)vertexStride;
      *(uint *)(glContext + 0x498c) = bufferKind;
      interpCacheNode = interpCacheHead;
      do {
        if (interpKey == interpCacheNode[2]) {
          if (interpCacheNode != interpCacheHead) {
            interpNodePrev = (int *)interpCacheNode[1];
            *interpNodePrev = *interpCacheNode;
            *(int **)(*interpCacheNode + 4) = interpNodePrev;
            interpCacheTail = (undefined4 *)interpCacheHead[1];
            *interpCacheTail = interpCacheNode;
            interpCacheNode[1] = (int)interpCacheTail;
            *interpCacheNode = (int)interpCacheHead;
            interpCacheHead[1] = (int)interpCacheNode;
            *(int **)(glContext + 0x49b8) = interpCacheNode;
          }
          *(int **)(glContext + 0x49c4) = interpCacheNode + 8;
          goto LAB_000daa98;
        }
        interpCacheNode = (int *)*interpCacheNode;
      } while (interpCacheNode != interpCacheHead);
      interpFunc = _gleBuildInterpFunc(glContext,interpKey);
      *(undefined4 *)(glContext + 0x49c4) = interpFunc;
LAB_000daa98:
      remainingCapacity = 0;
    }
    requestedSize[0] = vertexCount * 2 + 0x12;
    if (requestedSize[0] < remainingCapacity) {
      skipBufferRelease = true;
      *(int *)(glContext + 0x4994) = iVar10;
      iVar10 = *(int *)(glContext + 0x49a8) + iVar10 * vertexStride;
    }
    else {
      oldBuffer = *(int *)(glContext + 0x49a8);
      skipBufferRelease = oldBuffer == 0;
      if (!skipBufferRelease) {
        (**(code **)(glContext + 0x47c8))(*(undefined4 *)(glContext + 0x4688),oldBuffer,iVar10);
      }
      iVar10 = (**(code **)(glContext + 0x47c4))
                         (*(undefined4 *)(glContext + 0x4688),*(undefined4 *)(glContext + 0x498c),
                          requestedSize);
      if (iVar10 == 0) {
        *(uint *)(glContext + 0x4980) = interpKey;
        *(undefined4 *)(glContext + 0x4998) = 0;
        *(undefined4 *)(glContext + 0x4994) = 0;
        *(undefined4 *)(glContext + 0x49a4) = 0;
        if (skipBufferRelease) {
          return 0;
        }
        releaseResult = (**(code **)(glContext + 0x47cc))(*(undefined4 *)(glContext + 0x4688),oldBuffer);
        *(undefined4 *)(glContext + 0x49a8) = 0;
        return releaseResult;
      }
      *(undefined4 *)(glContext + 0x4994) = 0;
      *(int *)(glContext + 0x4998) = requestedSize[0];
      *(int *)(glContext + 0x49a8) = iVar10;
    }
    *(int *)(glContext + 0x49a4) = iVar10;
    newIndexCursor = (int *)(*(int *)(glContext + 0x49a0) + vertexCount * 4);
    if (newIndexCursor <= indexCursor) {
      fillCount = (uint)((int)indexCursor + (4 - (int)newIndexCursor)) >> 2;
      do {
        *indexCursor = runValue;
        indexCursor = indexCursor + -1;
        runValue = runValue + -1;
        fillCount = fillCount - 1;
      } while (fillCount != 0);
    }
    *(int **)(glContext + 0x499c) = newIndexCursor;
    enableFlags = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334);
    enableMask = 0;
    if ((enableFlags & 0x10000) != 0) {
      enableMask = 5;
    }
    if ((enableFlags & 0x40000) != 0) {
      enableMask = enableMask | 2;
    }
    if ((enableFlags & 0x1000000) != 0) {
      enableMask = enableMask | 8;
    }
    if ((enableFlags & 0x2000000) != 0) {
      enableMask = enableMask | 0x10;
    }
    formatFlagsThenCompileKey = (formatFlagsThenCompileKey & enableMask) << 0x15 |
             (formatFlagsThenCompileKey & (*(uint *)(glContext + 0x497c) | ~enableMask) & 0x1f) << 0x10 |
             *(uint *)(glContext + 0x49b0) | (uint)*(ushort *)(glContext + 0x4fe8) << 0x18;
    if (*(undefined **)(glContext + 0x5080) == ((unsigned char *)0x00001101)) {
      formatFlagsThenCompileKey = formatFlagsThenCompileKey | 0x10000000;
    }
    compileCacheHead = *(int **)(glContext + 0x49b4);
    compileCacheNode = compileCacheHead;
    do {
      if (formatFlagsThenCompileKey == compileCacheNode[2]) {
        if (compileCacheNode != compileCacheHead) {
          compileNodePrev = (int *)compileCacheNode[1];
          *compileNodePrev = *compileCacheNode;
          *(int **)(*compileCacheNode + 4) = compileNodePrev;
          compileCacheTail = (undefined4 *)compileCacheHead[1];
          *compileCacheTail = compileCacheNode;
          compileCacheNode[1] = (int)compileCacheTail;
          *compileCacheNode = (int)compileCacheHead;
          compileCacheHead[1] = (int)compileCacheNode;
          *(int **)(glContext + 0x49b4) = compileCacheNode;
        }
        compiledFunc = (code *)(compileCacheNode + 8);
        goto LAB_000dacc0;
      }
      compileCacheNode = (int *)*compileCacheNode;
    } while (compileCacheNode != compileCacheHead);
    if ((*(uint *)PTR__gle_processor_0011204c & 0x10) == 0) {
      compiledFunc = (code *)_gleBuildCompileFuncNO(glContext,formatFlagsThenCompileKey);
    }
    else {
      compiledFunc = (code *)_gleBuildCompileFuncAV(glContext,formatFlagsThenCompileKey);
    }
LAB_000dacc0:
    iVar14 = (*compiledFunc)(glContext,iVar10,uVar13,vertexStride,(uint)cachedStride);
    *(uint *)(glContext + 0x497c) = ~*(uint *)(glContext + 0x4980) & 0x1f;
    if (!skipBufferRelease) {
      iVar14 = (**(code **)(glContext + 0x47cc))(*(undefined4 *)(glContext + 0x4688),oldBuffer);
    }
  }
  return iVar14;
}

/* _gleCompileVertexArray @ 0xdad24 (20 bytes) */
double _gleCompileVertexArray(glContext)
  int glContext;
{
  if (*(char *)(glContext + 0x7580) != '\0') {
    ((int (*)())_gleCompileTCLVertexArray)(glContext);
    return;
  }
  ((int (*)())_gleCompileClippedVertexArray)(glContext);
  return;
}

/* _gleExecuteTCLVertexArray @ 0xdad38 (352 bytes) */
void _gleExecuteTCLVertexArray(glContext, mode, firstThenNextSequentialIndex, count, indexType, indices)
  int glContext;
  undefined4 mode;
  int firstThenNextSequentialIndex;
  int count;
  uint indexType;
  int indices;
{
  int indicesLeft;
  undefined4 errorCode;
  int *indexWriteCursor;
  int *sequentialIndices;
  
  if (indexType == 0x1403) {
LAB_000dad94:
    indices = indices + firstThenNextSequentialIndex;
LAB_000dad98:
                    
                    
    (**(code **)(glContext + 0x46e4))
              (*(undefined4 *)(glContext + 0x4688),*(undefined4 *)(glContext + 0x49a8),mode,
               *(int *)(glContext + 0x4984) - *(int *)(glContext + 0x4994),count,indexType,
               indices + firstThenNextSequentialIndex);
    return;
  }
  if (indexType < 0x1404) {
    if (indexType == 0x1401) goto LAB_000dad98;
  }
  else {
    if (indexType == 0x1405) {
      indices = indices + firstThenNextSequentialIndex * 2;
      goto LAB_000dad94;
    }
    if (indexType == 0x14ff) {
      sequentialIndices = (int *)_malloc(count << 2);
      if (sequentialIndices != (int *)0x0) {
        if (firstThenNextSequentialIndex < firstThenNextSequentialIndex + count) {
          indicesLeft = (firstThenNextSequentialIndex + count) - firstThenNextSequentialIndex;
          indexWriteCursor = sequentialIndices;
          do {
            *indexWriteCursor = firstThenNextSequentialIndex;
            indexWriteCursor = indexWriteCursor + 1;
            firstThenNextSequentialIndex = firstThenNextSequentialIndex + 1;
            indicesLeft = indicesLeft + -1;
          } while (indicesLeft != 0);
        }
        (**(code **)(glContext + 0x46e4))
                  (*(undefined4 *)(glContext + 0x4688),*(undefined4 *)(glContext + 0x49a8),mode,
                   *(int *)(glContext + 0x4984) - *(int *)(glContext + 0x4994),count,0x1405,sequentialIndices);
        _free(sequentialIndices);
        return;
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      errorCode = 0x505;
      goto LAB_000dae80;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  errorCode = 0x500;
LAB_000dae80:
  *(undefined4 *)(glContext + 0x7574) = errorCode;
  return;
}

/* _gleExecuteClippedVertexArray @ 0xdae98 (4556 bytes) */
int _gleExecuteClippedVertexArray(glContext, mode, firstThenNextSequentialIndex, count, indexType, indices)
  dword *glContext;
  uint mode;
  uint firstThenNextSequentialIndex;
  int count;
  uint indexType;
  dword *indices;
{
  bool moreVertices;
  uint uVar2;
  byte bVar4;
  byte clipFlags;
  uint uVar3;
  undefined4 r3AfterCall;
  dword *pdVar5;
  dword *r3AfterCall1;
  uint uVar6;
  uint uVar7;
  dword *pdVar8;
  dword *drawIndices;
  int iVar9;
  int indexSize;
  int iVar10;
  int clipFlagTable;
  uint uVar12;
  byte bVar13;
  byte clipFlags2;
  byte clipFlags3;
  byte clipFlags4;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int runElementsThenAdvanceBytes;
  int verticesRemaining;
  int runLength;
  dword *pdVar20;
  dword *indexCursor;
  uint *puVar21;
  uint *indexReadCursor;
  uint *indexReadCursor2;
  int iVar23;
  int runElementsThenAdvanceBytes2;
  uint uStack0000001c;
  int iStack00000024;
  dword *pdStack0000002c;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84 [5];
  uint indexMask;
  int ownsIndexArray;
  code *drawHook;
  int local_64;
  uint flushThreshold;
  int local_5c;
  
  drawHook = (code *)glContext[0x11b9];
  uStack0000001c = mode;
  iStack00000024 = count;
  pdStack0000002c = indices;
  if ((undefined *)glContext[0x1420] == ((unsigned char *)0x00001101)) {
    ((void (*)())_gleExecuteTCLVertexArray)(glContext,mode,firstThenNextSequentialIndex,count,indexType,indices);
    return (dword *)r3AfterCall;
  }
  if ((*(short *)((int)glContext + 0x34d6) == 0x408) && (3 < mode)) {
    return glContext;
  }
  if (indexType == 0x1403) {
    indexMask = 0xffff;
    indexCursor = (dword *)((int)indices + firstThenNextSequentialIndex * 2 + -2);
    indexSize = 2;
LAB_000daf8c:
    ownsIndexArray = 0;
    pdVar5 = glContext;
    pdStack0000002c = indices;
  }
  else {
    if (indexType < 0x1404) {
      if (indexType != 0x1401) {
LAB_000db014:
        if (glContext[0x1d5d] != 0) {
          return glContext;
        }
        uVar2 = 0x500;
        pdVar20 = glContext;
LAB_000db024:
        glContext[0x1d5d] = uVar2;
        return pdVar20;
      }
      indexMask = 0xff;
      indexSize = 1;
      indexCursor = (dword *)((int)indices + (firstThenNextSequentialIndex - 3));
      goto LAB_000daf8c;
    }
    if (indexType == 0x1405) {
      indexSize = 4;
      indexCursor = indices + firstThenNextSequentialIndex;
      indexMask = 0xffffffff;
      goto LAB_000daf8c;
    }
    if (indexType != 0x14ff) goto LAB_000db014;
    indexType = 0x1405;
    pdVar5 = (dword *)_malloc(count << 2);
    if (pdVar5 == (dword *)0x0) {
      if (glContext[0x1d5d] != 0) {
        return (dword *)0;
      }
      uVar2 = 0x505;
      pdVar20 = (dword *)0x0;
      goto LAB_000db024;
    }
    indexMask = 0xffffffff;
    indexSize = 4;
    ownsIndexArray = 1;
    indexCursor = pdVar5;
    pdStack0000002c = pdVar5;
    if ((int)firstThenNextSequentialIndex < (int)(firstThenNextSequentialIndex + iStack00000024)) {
      iVar10 = (firstThenNextSequentialIndex + iStack00000024) - firstThenNextSequentialIndex;
      pdVar8 = pdVar5;
      do {
        *pdVar8 = firstThenNextSequentialIndex;
        firstThenNextSequentialIndex = firstThenNextSequentialIndex + 1;
        pdVar8 = pdVar8 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
  }
  uVar2 = glContext[0x1261];
  clipFlagTable = glContext[0x126b] - uVar2;
  local_64 = glContext[0x1269] - uVar2 * *(ushort *)(glContext + 0x1264);
  flushThreshold = (glContext[0x1268] + glContext[0x1266] * 4 + glContext[0x1265] * -4) - 0x48;
  iVar10 = uVar2 - glContext[0x1265];
  drawIndices = pdStack0000002c;
  switch(uStack0000001c) {
  case 0:
    runLength = 0;
    verticesRemaining = iStack00000024;
    if (iStack00000024 < 1) goto switchD_000db0a0_default;
    do {
      uVar2 = *indexCursor;
      indexCursor = (dword *)((int)indexCursor + indexSize);
      if (*(char *)(clipFlagTable + (uVar2 & indexMask)) == '\0') {
        runLength = runLength + 1;
      }
      else if (runLength == 0) {
        drawIndices = (dword *)((int)drawIndices + indexSize);
      }
      else {
        pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],uStack0000001c,iVar10,runLength,
                                      indexType,drawIndices);
        iVar23 = runLength + 1;
        runLength = 0;
        drawIndices = (dword *)((int)drawIndices + iVar23 * indexSize);
      }
      verticesRemaining = verticesRemaining + -1;
    } while (verticesRemaining != 0);
    break;
  case 1:
    iVar18 = 1;
    runLength = 0;
    if (iStack00000024 < 2) goto switchD_000db0a0_default;
    do {
      uVar12 = *indexCursor & indexMask;
      uVar2 = *(uint *)((int)indexCursor + indexSize) & indexMask;
      clipFlags4 = *(byte *)(clipFlagTable + uVar12);
      clipFlags3 = *(byte *)(clipFlagTable + uVar2);
      indexCursor = (dword *)((int)indexCursor + indexSize + indexSize);
      if (((clipFlags4 | clipFlags3) & 0xc3) == 0) {
        runLength = runLength + 2;
      }
      else {
        runElementsThenAdvanceBytes2 = indexSize << 1;
        if (runLength != 0) {
          pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],uStack0000001c,iVar10,runLength
                                        ,indexType,drawIndices);
          runElementsThenAdvanceBytes2 = runLength + 2;
          runLength = 0;
          runElementsThenAdvanceBytes2 = runElementsThenAdvanceBytes2 * indexSize;
        }
        drawIndices = (dword *)((int)drawIndices + runElementsThenAdvanceBytes2);
        if ((clipFlags4 & clipFlags3 & 0x3f) == 0) {
          local_e0 = uVar12;
          local_dc = uVar2;
          if (flushThreshold <= glContext[0x1267]) {
            ((void (*)())_gleFlushIndexStack)(glContext);
          }
          pdVar5 = (dword *)((int (*)())_gleVAClipLine)(glContext,local_64,clipFlagTable,&local_e0);
          if (pdVar5 != (dword *)0x0) {
            pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],uStack0000001c,iVar10,2,
                                          0x1405,&local_e0);
          }
        }
      }
      iVar18 = iVar18 + 2;
    } while (iVar18 < iStack00000024);
    break;
  case 2:
    runLength = 0;
    uVar12 = *indexCursor & indexMask;
    clipFlags4 = *(byte *)(clipFlagTable + uVar12);
    uVar2 = uVar12;
    clipFlags3 = clipFlags4;
    if (1 < iStack00000024) {
      verticesRemaining = iStack00000024 + -1;
      uVar16 = uVar12;
      bVar13 = clipFlags4;
      do {
        indexCursor = (dword *)((int)indexCursor + indexSize);
        uVar2 = *indexCursor & indexMask;
        clipFlags3 = *(byte *)(clipFlagTable + uVar2);
        if (((bVar13 | clipFlags3) & 0xc3) == 0) {
          runLength = runLength + 1;
        }
        else {
          runElementsThenAdvanceBytes2 = indexSize;
          if (runLength != 0) {
            runElementsThenAdvanceBytes2 = runLength + 1;
            runLength = 0;
            pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],3,iVar10,runElementsThenAdvanceBytes2,indexType,
                                          drawIndices);
            runElementsThenAdvanceBytes2 = runElementsThenAdvanceBytes2 * indexSize;
          }
          drawIndices = (dword *)((int)drawIndices + runElementsThenAdvanceBytes2);
          if ((bVar13 & clipFlags3 & 0x3f) == 0) {
            local_e0 = uVar16;
            local_dc = uVar2;
            if (flushThreshold <= glContext[0x1267]) {
              ((void (*)())_gleFlushIndexStack)(glContext);
            }
            pdVar5 = (dword *)((int (*)())_gleVAClipLine)(glContext,local_64,clipFlagTable,&local_e0);
            if (pdVar5 != (dword *)0x0) {
              pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],3,iVar10,2,0x1405,
                                            &local_e0);
            }
          }
        }
        verticesRemaining = verticesRemaining + -1;
        uVar16 = uVar2;
        bVar13 = clipFlags3;
      } while (verticesRemaining != 0);
    }
    if (runLength == iStack00000024 + -1) {
      uVar2 = glContext[0x126a];
      runLength = iStack00000024;
      goto LAB_000dbe34;
    }
    if (runLength != 0) {
      pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],3,iVar10,runLength + 1,indexType,
                                    drawIndices);
    }
    local_e0 = uVar2;
    local_dc = uVar12;
    if (((clipFlags4 | clipFlags3) & 0xc3) != 0) {
      if ((clipFlags4 & clipFlags3 & 0x3f) != 0) goto switchD_000db0a0_default;
      iVar9 = ((int (*)())_gleVAClipLine)(glContext,local_64,clipFlagTable,&local_e0);
      pdVar5 = (dword *)0x0;
      if (iVar9 == 0) goto switchD_000db0a0_default;
    }
    uVar2 = glContext[0x126a];
    uVar12 = 3;
    uVar16 = glContext[0x11a2];
    runLength = 2;
    indexType = 0x1405;
    drawIndices = &local_e0;
    goto LAB_000dbe44;
  case 3:
    runLength = 0;
    if (iStack00000024 < 2) goto switchD_000db0a0_default;
    verticesRemaining = iStack00000024 + -1;
    uVar2 = *indexCursor & indexMask;
    clipFlags4 = *(byte *)(clipFlagTable + (*indexCursor & indexMask));
    do {
      indexCursor = (dword *)((int)indexCursor + indexSize);
      uVar12 = *indexCursor & indexMask;
      clipFlags3 = *(byte *)(clipFlagTable + uVar12);
      if (((clipFlags4 | clipFlags3) & 0xc3) == 0) {
        runLength = runLength + 1;
      }
      else {
        runElementsThenAdvanceBytes2 = indexSize;
        if (runLength != 0) {
          runElementsThenAdvanceBytes2 = runLength + 1;
          runLength = 0;
          pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],uStack0000001c,iVar10,runElementsThenAdvanceBytes2
                                        ,indexType,drawIndices);
          runElementsThenAdvanceBytes2 = runElementsThenAdvanceBytes2 * indexSize;
        }
        drawIndices = (dword *)((int)drawIndices + runElementsThenAdvanceBytes2);
        if ((clipFlags4 & clipFlags3 & 0x3f) == 0) {
          local_e0 = uVar2;
          local_dc = uVar12;
          if (flushThreshold <= glContext[0x1267]) {
            ((void (*)())_gleFlushIndexStack)(glContext);
          }
          pdVar5 = (dword *)((int (*)())_gleVAClipLine)(glContext,local_64,clipFlagTable,&local_e0);
          if (pdVar5 != (dword *)0x0) {
            pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],uStack0000001c,iVar10,2,
                                          0x1405,&local_e0);
          }
        }
      }
      verticesRemaining = verticesRemaining + -1;
      uVar2 = uVar12;
      clipFlags4 = clipFlags3;
    } while (verticesRemaining != 0);
    if (runLength == 0) goto switchD_000db0a0_default;
    uVar2 = glContext[0x126a];
    runLength = runLength + 1;
    goto LAB_000dbe34;
  case 4:
    if ((indexType == 0x1403) || (indexType == 0x1401)) {
      iVar18 = 2;
      runLength = 0;
      if (iStack00000024 < 3) goto switchD_000db0a0_default;
      do {
        indexReadCursor2 = (uint *)((int)indexCursor + indexSize + indexSize);
        uVar16 = *indexCursor & indexMask;
        uVar12 = *(uint *)((int)indexCursor + indexSize) & indexMask;
        uVar2 = *indexReadCursor2 & indexMask;
        clipFlags4 = *(byte *)(clipFlagTable + uVar16);
        clipFlags3 = *(byte *)(clipFlagTable + uVar12);
        indexCursor = (dword *)((int)indexReadCursor2 + indexSize);
        clipFlags2 = *(byte *)(clipFlagTable + uVar2);
        if (((clipFlags4 | clipFlags3 | clipFlags2) & 0xc3) == 0) {
          runLength = runLength + 3;
        }
        else {
          runElementsThenAdvanceBytes2 = indexSize * 3;
          if (runLength != 0) {
            pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],uStack0000001c,iVar10,
                                          runLength,indexType,drawIndices);
            runElementsThenAdvanceBytes2 = runLength + 3;
            runLength = 0;
            runElementsThenAdvanceBytes2 = runElementsThenAdvanceBytes2 * indexSize;
          }
          drawIndices = (dword *)((int)drawIndices + runElementsThenAdvanceBytes2);
          if ((clipFlags4 & clipFlags3 & clipFlags2 & 0x3f) == 0) {
            local_e0 = uVar16;
            local_dc = uVar12;
            local_d8 = uVar2;
            if (flushThreshold <= glContext[0x1267]) {
              ((void (*)())_gleFlushIndexStack)(glContext);
            }
            pdVar5 = (dword *)((int (*)())_gleVAClipPoly)(glContext,local_64,clipFlagTable,3,&local_e0);
            if (pdVar5 != (dword *)0x0) {
              pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],9,iVar10,pdVar5,0x1405,
                                            &local_e0);
            }
          }
        }
        iVar18 = iVar18 + 3;
      } while (iVar18 < iStack00000024);
    }
    else {
      iVar9 = 2;
      runLength = 0;
      if (iStack00000024 < 3) goto switchD_000db0a0_default;
      do {
        clipFlags4 = *(byte *)(clipFlagTable + *indexCursor);
        clipFlags3 = *(byte *)(clipFlagTable + indexCursor[1]);
        clipFlags2 = *(byte *)(clipFlagTable + indexCursor[2]);
        if (((clipFlags4 | clipFlags3 | clipFlags2) & 0xc3) == 0) {
          runLength = runLength + 3;
        }
        else {
          if (runLength == 0) {
            drawIndices = drawIndices + 3;
          }
          else {
            pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],uStack0000001c,iVar10,
                                          runLength,indexType,drawIndices);
            iVar18 = runLength + 3;
            runLength = 0;
            drawIndices = drawIndices + iVar18;
          }
          if ((clipFlags4 & clipFlags3 & clipFlags2 & 0x3f) == 0) {
            local_e0 = *indexCursor;
            local_dc = indexCursor[1];
            local_d8 = indexCursor[2];
            if (flushThreshold <= glContext[0x1267]) {
              ((void (*)())_gleFlushIndexStack)(glContext);
            }
            pdVar5 = (dword *)((int (*)())_gleVAClipPoly)(glContext,local_64,clipFlagTable,3,&local_e0);
            if (pdVar5 != (dword *)0x0) {
              pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],9,iVar10,pdVar5,0x1405,
                                            &local_e0);
            }
          }
        }
        iVar9 = iVar9 + 3;
        indexCursor = indexCursor + 3;
      } while (iVar9 < iStack00000024);
    }
    break;
  case 5:
    uVar16 = 2;
    runLength = 0;
    indexReadCursor2 = (uint *)((int)indexCursor + indexSize);
    clipFlags4 = *(byte *)(clipFlagTable + (*indexCursor & indexMask));
    uVar2 = *indexReadCursor2 & indexMask;
    uVar12 = *indexCursor & indexMask;
    clipFlags3 = *(byte *)(clipFlagTable + (*indexReadCursor2 & indexMask));
    if (iStack00000024 < 3) goto switchD_000db0a0_default;
    do {
      uVar3 = uVar2;
      indexReadCursor2 = (uint *)((int)indexReadCursor2 + indexSize);
      uVar2 = *indexReadCursor2 & indexMask;
      clipFlags2 = *(byte *)(clipFlagTable + uVar2);
      if (((clipFlags4 | clipFlags3 | clipFlags2) & 0xc3) == 0) {
        runLength = runLength + 1;
        clipFlags4 = clipFlags3;
      }
      else {
        runElementsThenAdvanceBytes = indexSize;
        if (runLength != 0) {
          pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],uStack0000001c,iVar10,
                                        runLength + 2,indexType,drawIndices);
          runElementsThenAdvanceBytes = runLength + 1;
          runLength = 0;
          runElementsThenAdvanceBytes = runElementsThenAdvanceBytes * indexSize;
        }
        drawIndices = (dword *)((int)drawIndices + runElementsThenAdvanceBytes);
        if ((uVar16 & 1) == 0) {
          clipFlags3 = clipFlags3 | 0xc3;
        }
        bVar4 = clipFlags4 & clipFlags3;
        clipFlags4 = clipFlags3;
        if ((bVar4 & clipFlags2 & 0x3f) == 0) {
          local_e0 = uVar12;
          local_dc = uVar3;
          local_d8 = uVar2;
          if (flushThreshold <= glContext[0x1267]) {
            ((void (*)())_gleFlushIndexStack)(glContext);
          }
          pdVar5 = (dword *)((int (*)())_gleVAClipPoly)(glContext,local_64,clipFlagTable,3,&local_e0);
          if (pdVar5 != (dword *)0x0) {
            pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],9,iVar10,pdVar5,0x1405,
                                          &local_e0);
          }
        }
      }
      uVar16 = uVar16 + 1;
      uVar12 = uVar3;
      clipFlags3 = clipFlags2;
    } while ((int)uVar16 < iStack00000024);
    goto LAB_000dbe1c;
  case 6:
    uVar12 = *indexCursor & indexMask;
    uVar2 = *(uint *)((int)indexCursor + indexSize) & indexMask;
    clipFlags4 = *(byte *)(clipFlagTable + uVar12);
    clipFlags3 = *(byte *)(clipFlagTable + uVar2);
    indexReadCursor2 = (uint *)((int)indexCursor + indexSize + indexSize);
    if (((clipFlags4 | clipFlags3) & 0xc3) == 0) {
      runLength = 2;
      bVar13 = 0;
      uVar16 = 0;
      moreVertices = 2 < iStack00000024;
      if (moreVertices) {
        do {
          bVar13 = clipFlags3;
          uVar16 = uVar2;
          uVar2 = *indexReadCursor2;
          clipFlags3 = *(byte *)(clipFlagTable + (uVar2 & indexMask));
          if ((clipFlags3 & 0xc3) != 0) break;
          runLength = runLength + 1;
          indexReadCursor2 = (uint *)((int)indexReadCursor2 + indexSize);
          moreVertices = runLength < iStack00000024;
          uVar2 = uVar2 & indexMask;
        } while (moreVertices);
        if (2 < runLength) {
          pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],uStack0000001c,iVar10,runLength
                                        ,indexType,pdStack0000002c);
        }
      }
    }
    else {
      runLength = 2;
      moreVertices = 2 < iStack00000024;
      uVar16 = uVar2;
      bVar13 = clipFlags3;
    }
    if (moreVertices) {
      do {
        uVar3 = *indexReadCursor2;
        runLength = runLength + 1;
        indexReadCursor2 = (uint *)((int)indexReadCursor2 + indexSize);
        uVar3 = uVar3 & indexMask;
        clipFlags3 = *(byte *)(clipFlagTable + uVar3);
        uVar2 = uVar3;
        if (((clipFlags4 | bVar13 | clipFlags3) & 0xc3) == 0) {
          pdVar5 = (dword *)((int)((unsigned char *)0x0) + 3);
          moreVertices = runLength < iStack00000024;
          if (moreVertices) {
            puVar21 = local_84;
            while( true ) {
              uVar17 = *indexReadCursor2 & indexMask;
              clipFlags2 = *(byte *)(clipFlagTable + uVar17);
              if ((clipFlags2 & 0xc3) != 0) break;
              runLength = runLength + 1;
              *puVar21 = uVar17;
              indexReadCursor2 = (uint *)((int)indexReadCursor2 + indexSize);
              moreVertices = runLength < iStack00000024;
              puVar21 = puVar21 + 1;
              pdVar5 = (dword *)((int)pdVar5 + 1);
              uVar2 = uVar17;
              clipFlags3 = clipFlags2;
              if ((!moreVertices) || (7 < (int)pdVar5)) break;
            }
          }
          uVar7 = glContext[0x11a2];
          uVar6 = glContext[0x126a];
          puVar21 = &local_90;
          uVar17 = uStack0000001c;
          local_90 = uVar12;
          local_8c = uVar16;
          local_88 = uVar3;
LAB_000dbb38:
          pdVar5 = (dword *)(*drawHook)(uVar7,uVar6,uVar17,iVar10,pdVar5,0x1405,puVar21);
          uVar3 = uVar2;
        }
        else {
          moreVertices = runLength < iStack00000024;
          if ((clipFlags4 & bVar13 & clipFlags3 & 0x3f) == 0) {
            local_e0 = uVar12;
            local_dc = uVar16;
            local_d8 = uVar3;
            if (flushThreshold <= glContext[0x1267]) {
              ((void (*)())_gleFlushIndexStack)(glContext);
            }
            pdVar5 = (dword *)((int (*)())_gleVAClipPoly)(glContext,local_64,clipFlagTable,3,&local_e0);
            moreVertices = runLength < iStack00000024;
            if (pdVar5 != (dword *)0x0) {
              uVar6 = glContext[0x126a];
              uVar7 = glContext[0x11a2];
              uVar17 = 9;
              puVar21 = &local_e0;
              goto LAB_000dbb38;
            }
          }
        }
        uVar16 = uVar3;
        bVar13 = clipFlags3;
      } while (moreVertices);
    }
    goto switchD_000db0a0_default;
  case 7:
    iVar18 = 3;
    runLength = 0;
    if (iStack00000024 < 4) goto switchD_000db0a0_default;
    do {
      uVar3 = *indexCursor & indexMask;
      indexReadCursor2 = (uint *)((int)indexCursor + indexSize + indexSize);
      uVar16 = *(uint *)((int)indexCursor + indexSize) & indexMask;
      clipFlags4 = *(byte *)(clipFlagTable + uVar3);
      indexReadCursor = (uint *)((int)indexReadCursor2 + indexSize);
      uVar12 = *indexReadCursor2 & indexMask;
      clipFlags3 = *(byte *)(clipFlagTable + uVar16);
      uVar2 = *indexReadCursor & indexMask;
      clipFlags2 = *(byte *)(clipFlagTable + uVar12);
      clipFlags = *(byte *)(clipFlagTable + uVar2);
      indexCursor = (dword *)((int)indexReadCursor + indexSize);
      if (((clipFlags4 | clipFlags3 | clipFlags2 | clipFlags) & 0xc3) == 0) {
        runLength = runLength + 4;
      }
      else {
        runElementsThenAdvanceBytes2 = indexSize << 2;
        if (runLength != 0) {
          pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],uStack0000001c,iVar10,runLength
                                        ,indexType,drawIndices);
          runElementsThenAdvanceBytes2 = runLength + 4;
          runLength = 0;
          runElementsThenAdvanceBytes2 = runElementsThenAdvanceBytes2 * indexSize;
        }
        drawIndices = (dword *)((int)drawIndices + runElementsThenAdvanceBytes2);
        if ((clipFlags4 & clipFlags3 & clipFlags2 & clipFlags & 0x3f) == 0) {
          local_e0 = uVar3;
          local_dc = uVar16;
          local_d8 = uVar12;
          local_d4 = uVar2;
          if (flushThreshold <= glContext[0x1267]) {
            ((void (*)())_gleFlushIndexStack)(glContext);
          }
          pdVar5 = (dword *)((int (*)())_gleVAClipPoly)(glContext,local_64,clipFlagTable,4,&local_e0);
          if (pdVar5 != (dword *)0x0) {
            pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],9,iVar10,pdVar5,0x1405,
                                          &local_e0);
          }
        }
      }
      iVar18 = iVar18 + 4;
    } while (iVar18 < iStack00000024);
    break;
  case 8:
    iVar18 = 3;
    runLength = 0;
    indexReadCursor2 = (uint *)((int)indexCursor + indexSize);
    if (iStack00000024 < 4) goto switchD_000db0a0_default;
    local_5c = indexSize << 1;
    uVar2 = *indexReadCursor2 & indexMask;
    uVar12 = *indexCursor & indexMask;
    clipFlags4 = *(byte *)(clipFlagTable + (*indexCursor & indexMask));
    clipFlags3 = *(byte *)(clipFlagTable + (*indexReadCursor2 & indexMask));
    do {
      indexReadCursor = (uint *)((int)indexReadCursor2 + indexSize);
      indexReadCursor2 = (uint *)((int)indexReadCursor + indexSize);
      uVar3 = *indexReadCursor & indexMask;
      clipFlags2 = *(byte *)(clipFlagTable + uVar3);
      uVar16 = *indexReadCursor2 & indexMask;
      clipFlags = *(byte *)(clipFlagTable + uVar16);
      if (((clipFlags4 | clipFlags3 | clipFlags2 | clipFlags) & 0xc3) == 0) {
        runLength = runLength + 2;
      }
      else {
        runElementsThenAdvanceBytes2 = local_5c;
        if (runLength != 0) {
          runElementsThenAdvanceBytes2 = runLength + 2;
          runLength = 0;
          pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],uStack0000001c,iVar10,runElementsThenAdvanceBytes2
                                        ,indexType,drawIndices);
          runElementsThenAdvanceBytes2 = runElementsThenAdvanceBytes2 * indexSize;
        }
        drawIndices = (dword *)((int)drawIndices + runElementsThenAdvanceBytes2);
        if ((clipFlags4 & clipFlags3 & clipFlags2 & clipFlags & 0x3f) == 0) {
          local_e0 = uVar12;
          local_dc = uVar2;
          local_d8 = uVar16;
          local_d4 = uVar3;
          if (flushThreshold <= glContext[0x1267]) {
            ((void (*)())_gleFlushIndexStack)(glContext);
          }
          pdVar5 = (dword *)((int (*)())_gleVAClipPoly)(glContext,local_64,clipFlagTable,4,&local_e0);
          if (pdVar5 != (dword *)0x0) {
            pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],9,iVar10,pdVar5,0x1405,
                                          &local_e0);
          }
        }
      }
      iVar18 = iVar18 + 2;
      uVar2 = uVar16;
      uVar12 = uVar3;
      clipFlags4 = clipFlags2;
      clipFlags3 = clipFlags;
    } while (iVar18 < iStack00000024);
LAB_000dbe1c:
    if (runLength == 0) goto switchD_000db0a0_default;
    uVar2 = glContext[0x126a];
    runLength = runLength + 2;
    goto LAB_000dbe34;
  case 9:
    uVar12 = *indexCursor & indexMask;
    uVar2 = *(uint *)((int)indexCursor + indexSize) & indexMask;
    clipFlags4 = *(byte *)(clipFlagTable + uVar12);
    clipFlags3 = *(byte *)(clipFlagTable + uVar2);
    indexReadCursor2 = (uint *)((int)indexCursor + indexSize + indexSize);
    if (((clipFlags4 | clipFlags3) & 0xc3) == 0) {
      runLength = 2;
      bVar13 = 0;
      uVar16 = 0;
      moreVertices = 2 < iStack00000024;
      if (moreVertices) {
        do {
          bVar13 = clipFlags3;
          uVar16 = uVar2;
          uVar2 = *indexReadCursor2;
          clipFlags3 = *(byte *)(clipFlagTable + (uVar2 & indexMask));
          if ((clipFlags3 & 0xc3) != 0) break;
          runLength = runLength + 1;
          indexReadCursor2 = (uint *)((int)indexReadCursor2 + indexSize);
          moreVertices = runLength < iStack00000024;
          uVar2 = uVar2 & indexMask;
        } while (moreVertices);
        if (2 < runLength) {
          pdVar5 = (dword *)(*drawHook)(glContext[0x11a2],glContext[0x126a],uStack0000001c,iVar10,runLength
                                        ,indexType,pdStack0000002c);
        }
      }
    }
    else {
      runLength = 2;
      moreVertices = 2 < iStack00000024;
      uVar16 = uVar2;
      bVar13 = clipFlags3;
    }
    if (moreVertices) {
      do {
        uVar3 = *indexReadCursor2;
        runLength = runLength + 1;
        indexReadCursor2 = (uint *)((int)indexReadCursor2 + indexSize);
        uVar3 = uVar3 & indexMask;
        clipFlags3 = *(byte *)(clipFlagTable + uVar3);
        uVar2 = uVar3;
        if (((clipFlags4 | bVar13 | clipFlags3) & 0xc3) == 0) {
          pdVar5 = (dword *)((int)((unsigned char *)0x0) + 3);
          moreVertices = runLength < iStack00000024;
          if (moreVertices) {
            puVar21 = local_84;
            while( true ) {
              uVar17 = *indexReadCursor2 & indexMask;
              clipFlags2 = *(byte *)(clipFlagTable + uVar17);
              if ((clipFlags2 & 0xc3) != 0) break;
              runLength = runLength + 1;
              *puVar21 = uVar17;
              indexReadCursor2 = (uint *)((int)indexReadCursor2 + indexSize);
              moreVertices = runLength < iStack00000024;
              puVar21 = puVar21 + 1;
              pdVar5 = (dword *)((int)pdVar5 + 1);
              uVar2 = uVar17;
              clipFlags3 = clipFlags2;
              if ((!moreVertices) || (7 < (int)pdVar5)) break;
            }
          }
          uVar17 = glContext[0x11a2];
          uVar7 = glContext[0x126a];
          puVar21 = &local_90;
          local_90 = uVar12;
          local_8c = uVar16;
          local_88 = uVar3;
LAB_000dc04c:
          pdVar5 = (dword *)(*drawHook)(uVar17,uVar7,uStack0000001c,iVar10,pdVar5,0x1405,puVar21);
          uVar3 = uVar2;
        }
        else {
          moreVertices = runLength < iStack00000024;
          if ((clipFlags4 & bVar13 & clipFlags3 & 0x3f) == 0) {
            local_e0 = uVar12;
            local_dc = uVar16;
            local_d8 = uVar3;
            if (flushThreshold <= glContext[0x1267]) {
              ((void (*)())_gleFlushIndexStack)(glContext);
            }
            pdVar5 = (dword *)((int (*)())_gleVAClipPoly)(glContext,local_64,clipFlagTable,3,&local_e0);
            moreVertices = runLength < iStack00000024;
            if (pdVar5 != (dword *)0x0) {
              uVar7 = glContext[0x126a];
              uVar17 = glContext[0x11a2];
              puVar21 = &local_e0;
              goto LAB_000dc04c;
            }
          }
        }
        uVar16 = uVar3;
        bVar13 = clipFlags3;
      } while (moreVertices);
    }
  default:
    goto switchD_000db0a0_default;
  }
  if (runLength != 0) {
    uVar2 = glContext[0x126a];
LAB_000dbe34:
    uVar16 = glContext[0x11a2];
    uVar12 = uStack0000001c;
LAB_000dbe44:
    pdVar5 = (dword *)(*drawHook)(uVar16,uVar2,uVar12,iVar10,runLength,indexType,drawIndices);
  }
switchD_000db0a0_default:
  if (ownsIndexArray != 0) {
    _free(pdStack0000002c);
    pdVar5 = r3AfterCall1;
  }
  return pdVar5;
}

/* _gleExecuteVertexArray @ 0xdc08c (20 bytes) */
void _gleExecuteVertexArray(glContext, param_2, param_3, param_4, param_5, param_6)
  int glContext;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  if (*(char *)(glContext + 0x7580) != '\0') {
    ((void (*)())_gleExecuteTCLVertexArray)(glContext,param_2,param_3,param_4,param_5,param_6);
    return;
  }
  ((int (*)())_gleExecuteClippedVertexArray)(glContext,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* _gleLightMaterialRGBAChange_F_A @ 0xdc0a0 (184 bytes) */
void _gleLightMaterialRGBAChange_F_A(glContext, rgba)
  int glContext;
  undefined8 *rgba;
{
  byte dirtyBitIndex;
  undefined8 *material;
  int glContextPtr5424ThenDirtyWordAddress348;
  int dirtyWordAddress324;
  undefined8 rgbaBlueAlpha;
  
  material = (undefined8 *)_glePushMaterial(glContext,0);
  *material = *rgba;
  rgbaBlueAlpha = rgba[1];
  *(ushort *)((int)material + 0x234) = *(ushort *)((int)material + 0x234) | 0x404;
  material[1] = rgbaBlueAlpha;
  if (*(int *)(glContext + 0x5434) == 0) {
    dirtyBitIndex = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c0);
  }
  else {
    dirtyBitIndex = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f4);
  }
  dirtyWordAddress324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  glContextPtr5424ThenDirtyWordAddress348 = *(int *)(glContext + 0x5424);
  *(uint *)(dirtyWordAddress324 + 0x324) = *(uint *)(dirtyWordAddress324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
  dirtyBitIndex = *(byte *)(glContextPtr5424ThenDirtyWordAddress348 + 0x2c0);
  glContextPtr5424ThenDirtyWordAddress348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  *(uint *)(glContextPtr5424ThenDirtyWordAddress348 + 0x348) = *(uint *)(glContextPtr5424ThenDirtyWordAddress348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_F_D @ 0xdc158 (184 bytes) */
void _gleLightMaterialRGBAChange_F_D(glContext, rgba)
  int glContext;
  undefined8 *rgba;
{
  byte dirtyBitIndex;
  int materialThenGlContextPtr5424ThenDirtyWordAddress348;
  int dirtyWordAddress324;
  undefined8 rgbaBlueAlpha;
  
  materialThenGlContextPtr5424ThenDirtyWordAddress348 = _glePushMaterial(glContext,0);
  *(undefined8 *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x10) = *rgba;
  rgbaBlueAlpha = rgba[1];
  *(ushort *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x234) = *(ushort *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x234) | 0x808;
  *(undefined8 *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x18) = rgbaBlueAlpha;
  if (*(int *)(glContext + 0x5434) == 0) {
    dirtyBitIndex = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c1);
  }
  else {
    dirtyBitIndex = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f5);
  }
  dirtyWordAddress324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  materialThenGlContextPtr5424ThenDirtyWordAddress348 = *(int *)(glContext + 0x5424);
  *(uint *)(dirtyWordAddress324 + 0x324) = *(uint *)(dirtyWordAddress324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
  dirtyBitIndex = *(byte *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x2c1);
  materialThenGlContextPtr5424ThenDirtyWordAddress348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  *(uint *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x348) = *(uint *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
  return;
}

/* _gleLightMaterialShineChange_B @ 0xdc210 (180 bytes) */
void _gleLightMaterialShineChange_B(int glContext,float floatArg1)
{
  byte dirtyBitIndex;
  int materialThenGlContextPtr5424ThenDirtyWordAddress348;
  int dirtyWordAddress324;
  
  materialThenGlContextPtr5424ThenDirtyWordAddress348 = _glePushMaterial(glContext,1);
  *(float *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x40) = (float)floatArg1;
  *(ushort *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x234) = *(ushort *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x234) | 0x101;
  if (*(int *)(glContext + 0x5434) == 0) {
    dirtyBitIndex = *(byte *)(*(int *)(glContext + 0x5420) + 0x2ca);
  }
  else {
    dirtyBitIndex = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2fe);
  }
  dirtyWordAddress324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  materialThenGlContextPtr5424ThenDirtyWordAddress348 = *(int *)(glContext + 0x5424);
  *(uint *)(dirtyWordAddress324 + 0x324) = *(uint *)(dirtyWordAddress324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
  dirtyBitIndex = *(byte *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x2ca);
  materialThenGlContextPtr5424ThenDirtyWordAddress348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  *(uint *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x348) = *(uint *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_E @ 0xdc2c4 (184 bytes) */
void _gleLightMaterialRGBAChange_B_E(glContext, param_2)
  int glContext;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar2 = _glePushMaterial(glContext,1);
  *(undefined8 *)(iVar2 + 0x30) = *param_2;
  uVar4 = param_2[1];
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x202;
  *(undefined8 *)(iVar2 + 0x38) = uVar4;
  if (*(int *)(glContext + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c9);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2fd);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
  iVar2 = *(int *)(glContext + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2c9);
  iVar2 = (bVar1 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_A @ 0xdc37c (184 bytes) */
void _gleLightMaterialRGBAChange_B_A(glContext, rgba)
  int glContext;
  undefined8 *rgba;
{
  byte dirtyBitIndex;
  undefined8 *material;
  int glContextPtr5424ThenDirtyWordAddress348;
  int dirtyWordAddress324;
  undefined8 rgbaBlueAlpha;
  
  material = (undefined8 *)_glePushMaterial(glContext,1);
  *material = *rgba;
  rgbaBlueAlpha = rgba[1];
  *(ushort *)((int)material + 0x234) = *(ushort *)((int)material + 0x234) | 0x404;
  material[1] = rgbaBlueAlpha;
  if (*(int *)(glContext + 0x5434) == 0) {
    dirtyBitIndex = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c6);
  }
  else {
    dirtyBitIndex = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2fa);
  }
  dirtyWordAddress324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  glContextPtr5424ThenDirtyWordAddress348 = *(int *)(glContext + 0x5424);
  *(uint *)(dirtyWordAddress324 + 0x324) = *(uint *)(dirtyWordAddress324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
  dirtyBitIndex = *(byte *)(glContextPtr5424ThenDirtyWordAddress348 + 0x2c6);
  glContextPtr5424ThenDirtyWordAddress348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  *(uint *)(glContextPtr5424ThenDirtyWordAddress348 + 0x348) = *(uint *)(glContextPtr5424ThenDirtyWordAddress348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_D @ 0xdc434 (184 bytes) */
void _gleLightMaterialRGBAChange_B_D(glContext, rgba)
  int glContext;
  undefined8 *rgba;
{
  byte dirtyBitIndex;
  int materialThenGlContextPtr5424ThenDirtyWordAddress348;
  int dirtyWordAddress324;
  undefined8 rgbaBlueAlpha;
  
  materialThenGlContextPtr5424ThenDirtyWordAddress348 = _glePushMaterial(glContext,1);
  *(undefined8 *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x10) = *rgba;
  rgbaBlueAlpha = rgba[1];
  *(ushort *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x234) = *(ushort *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x234) | 0x808;
  *(undefined8 *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x18) = rgbaBlueAlpha;
  if (*(int *)(glContext + 0x5434) == 0) {
    dirtyBitIndex = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c7);
  }
  else {
    dirtyBitIndex = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2fb);
  }
  dirtyWordAddress324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  materialThenGlContextPtr5424ThenDirtyWordAddress348 = *(int *)(glContext + 0x5424);
  *(uint *)(dirtyWordAddress324 + 0x324) = *(uint *)(dirtyWordAddress324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
  dirtyBitIndex = *(byte *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x2c7);
  materialThenGlContextPtr5424ThenDirtyWordAddress348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  *(uint *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x348) = *(uint *)(materialThenGlContextPtr5424ThenDirtyWordAddress348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_S @ 0xdc4ec (184 bytes) */
void _gleLightMaterialRGBAChange_B_S(glContext, param_2)
  int glContext;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar2 = _glePushMaterial(glContext,1);
  *(undefined8 *)(iVar2 + 0x20) = *param_2;
  uVar4 = param_2[1];
  *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x1010;
  *(undefined8 *)(iVar2 + 0x28) = uVar4;
  if (*(int *)(glContext + 0x5434) == 0) {
    bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c8);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2fc);
  }
  iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
  iVar2 = *(int *)(glContext + 0x5424);
  *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar2 + 0x2c8);
  iVar2 = (bVar1 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_B_AD @ 0xdc5a4 (296 bytes) */
void _gleLightMaterialRGBAChange_B_AD(glContext, rgba)
  int glContext;
  undefined8 *rgba;
{
  byte dirtyBitIndex;
  undefined8 *material;
  int glContextPtr5424;
  int glContextWord5434ThenDirtyWordAddress;
  int dirtyWordAddress;
  undefined8 rgbaBlueAlpha;
  
  material = (undefined8 *)_glePushMaterial(glContext,1);
  *material = *rgba;
  material[1] = rgba[1];
  material[2] = *rgba;
  rgbaBlueAlpha = rgba[1];
  *(ushort *)((int)material + 0x234) = *(ushort *)((int)material + 0x234) | 0xc0c;
  material[3] = rgbaBlueAlpha;
  glContextWord5434ThenDirtyWordAddress = *(int *)(glContext + 0x5434);
  if (glContextWord5434ThenDirtyWordAddress == 0) {
    dirtyBitIndex = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c6);
  }
  else {
    dirtyBitIndex = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2fa);
  }
  dirtyWordAddress = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  glContextPtr5424 = *(int *)(glContext + 0x5424);
  *(uint *)(dirtyWordAddress + 0x324) = *(uint *)(dirtyWordAddress + 0x324) | 1 << (dirtyBitIndex & 0x1f);
  dirtyBitIndex = *(byte *)(glContextPtr5424 + 0x2c6);
  dirtyWordAddress = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  *(uint *)(dirtyWordAddress + 0x348) = *(uint *)(dirtyWordAddress + 0x348) | 1 << (dirtyBitIndex & 0x1f);
  if (glContextWord5434ThenDirtyWordAddress == 0) {
    dirtyBitIndex = *(byte *)(*(int *)(glContext + 0x5420) + 0x2c7);
  }
  else {
    dirtyBitIndex = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2fb);
  }
  glContextWord5434ThenDirtyWordAddress = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  *(uint *)(glContextWord5434ThenDirtyWordAddress + 0x324) = *(uint *)(glContextWord5434ThenDirtyWordAddress + 0x324) | 1 << (dirtyBitIndex & 0x1f);
  dirtyBitIndex = *(byte *)(glContextPtr5424 + 0x2c7);
  glContextWord5434ThenDirtyWordAddress = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  *(uint *)(glContextWord5434ThenDirtyWordAddress + 0x348) = *(uint *)(glContextWord5434ThenDirtyWordAddress + 0x348) | 1 << (dirtyBitIndex & 0x1f);
  return;
}

/* _gleLightMaterialRGBAChange_FB_E @ 0xdc6cc (224 bytes) */
void _gleLightMaterialRGBAChange_FB_E(glContext, param_2)
  int glContext;
  undefined8 *param_2;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  iVar5 = 0;
  do {
    iVar2 = _glePushMaterial(glContext,iVar5);
    *(undefined8 *)(iVar2 + 0x30) = *param_2;
    uVar6 = param_2[1];
    *(ushort *)(iVar2 + 0x234) = *(ushort *)(iVar2 + 0x234) | 0x202;
    *(undefined8 *)(iVar2 + 0x38) = uVar6;
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar1 = *(byte *)(iVar5 * 6 + *(int *)(glContext + 0x5420) + 0x2c3);
    }
    else {
      bVar1 = *(byte *)(iVar5 * 6 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f7);
    }
    iVar3 = iVar5 * 6;
    iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
    iVar5 = iVar5 + 1;
    iVar2 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
    bVar1 = *(byte *)(iVar3 + iVar2 + 0x2c3);
    iVar2 = (bVar1 >> 3 & 0x1c) + glContext;
    *(uint *)(iVar2 + 0x348) = *(uint *)(iVar2 + 0x348) | 1 << (bVar1 & 0x1f);
  } while (iVar5 < 2);
  return;
}

/* _gleInvertMatrix_601_body @ 0xdc7b8 (1320 bytes) */
void _gleInvertMatrix_601_body(glContext)
  int glContext;
{
  float candidate;
  float swapTemp;
  float pivotThenReciprocal;
  float eliminationFactor;
  float zero;
  float one;
  int scanRemaining;
  int maxIndexPlus8;
  float *scanCursor;
  int pivotPlus4;
  int nextPivotIndex;
  int pivotIndex;
  int maxIndex;
  int maxIndexPlus12;
  int scanIndex;
  int maxIndexPlus4;
  float *inverseMatrix;
  int pivotPlus8;
  int pivotPlus12;
  float workMatrix [4];
  float workMatrix4;
  float workMatrix5;
  float workMatrix6;
  float workMatrix7;
  float workMatrix8;
  float workMatrix9;
  float workMatrix10;
  float workMatrix11;
  float workMatrix12;
  float workMatrix13;
  float workMatrix14;
  float workMatrix15;
  
  one = FLOAT_00108e54;
  zero = FLOAT_00108e50;
  workMatrix[0] = *(float *)(glContext + 0x1bc0);
  workMatrix4 = *(float *)(glContext + 0x1bc4);
  workMatrix8 = *(float *)(glContext + 0x1bc8);
  workMatrix12 = *(float *)(glContext + 0x1bcc);
  workMatrix[1] = *(float *)(glContext + 0x1bd0);
  workMatrix5 = *(float *)(glContext + 0x1bd4);
  workMatrix9 = *(float *)(glContext + 0x1bd8);
  workMatrix13 = *(float *)(glContext + 0x1bdc);
  workMatrix[2] = *(float *)(glContext + 0x1be0);
  workMatrix6 = *(float *)(glContext + 0x1be4);
  workMatrix10 = *(float *)(glContext + 0x1be8);
  workMatrix14 = *(float *)(glContext + 0x1bec);
  workMatrix[3] = *(float *)(glContext + 0x1bf0);
  workMatrix7 = *(float *)(glContext + 0x1bf4);
  workMatrix11 = *(float *)(glContext + 0x1bf8);
  inverseMatrix = (float *)(glContext + 0x21c0);
  workMatrix15 = *(float *)(glContext + 0x1bfc);
  *(float *)(glContext + 0x21c0) = FLOAT_00108e54;
  *(float *)(glContext + 0x21c4) = zero;
  *(float *)(glContext + 0x21c8) = zero;
  *(float *)(glContext + 0x21cc) = zero;
  *(float *)(glContext + 0x21d0) = zero;
  *(float *)(glContext + 0x21d4) = one;
  *(float *)(glContext + 0x21d8) = zero;
  *(float *)(glContext + 0x21dc) = zero;
  *(float *)(glContext + 0x21e0) = zero;
  *(float *)(glContext + 0x21e4) = zero;
  *(float *)(glContext + 0x21e8) = one;
  *(float *)(glContext + 0x21ec) = zero;
  *(float *)(glContext + 0x21f0) = zero;
  *(float *)(glContext + 0x21f4) = zero;
  *(float *)(glContext + 0x21f8) = zero;
  *(float *)(glContext + 0x21fc) = one;
  pivotIndex = 0;
  while( true ) {
    nextPivotIndex = pivotIndex + 1;
    pivotThenReciprocal = workMatrix[pivotIndex * 5];
    pivotPlus4 = pivotIndex + 4;
    pivotPlus8 = pivotIndex + 8;
    pivotPlus12 = pivotIndex + 0xc;
    maxIndex = pivotIndex;
    if (nextPivotIndex != 4) {
      scanCursor = workMatrix + pivotIndex * 4 + nextPivotIndex;
      scanRemaining = 4 - nextPivotIndex;
      scanIndex = nextPivotIndex;
      do {
        candidate = *scanCursor;
        scanCursor = scanCursor + 1;
        if (ABS(pivotThenReciprocal) < ABS(candidate)) {
          maxIndex = scanIndex;
          pivotThenReciprocal = candidate;
        }
        scanIndex = scanIndex + 1;
        scanRemaining = scanRemaining + -1;
      } while (scanRemaining != 0);
    }
    if (maxIndex != pivotIndex) {
      swapTemp = inverseMatrix[pivotIndex];
      maxIndexPlus4 = maxIndex + 4;
      inverseMatrix[pivotIndex] = inverseMatrix[maxIndex];
      maxIndexPlus8 = maxIndex + 8;
      inverseMatrix[maxIndex] = swapTemp;
      maxIndexPlus12 = maxIndex + 0xc;
      swapTemp = workMatrix[pivotIndex];
      workMatrix[pivotIndex] = workMatrix[maxIndex];
      workMatrix[maxIndex] = swapTemp;
      swapTemp = inverseMatrix[pivotPlus4];
      inverseMatrix[pivotPlus4] = inverseMatrix[maxIndexPlus4];
      inverseMatrix[maxIndexPlus4] = swapTemp;
      swapTemp = workMatrix[pivotPlus4];
      workMatrix[pivotPlus4] = workMatrix[maxIndexPlus4];
      workMatrix[maxIndexPlus4] = swapTemp;
      swapTemp = inverseMatrix[pivotPlus8];
      inverseMatrix[pivotPlus8] = inverseMatrix[maxIndexPlus8];
      inverseMatrix[maxIndexPlus8] = swapTemp;
      swapTemp = workMatrix[pivotPlus8];
      workMatrix[pivotPlus8] = workMatrix[maxIndexPlus8];
      workMatrix[maxIndexPlus8] = swapTemp;
      swapTemp = inverseMatrix[pivotPlus12];
      inverseMatrix[pivotPlus12] = inverseMatrix[maxIndexPlus12];
      inverseMatrix[maxIndexPlus12] = swapTemp;
      swapTemp = workMatrix[pivotPlus12];
      workMatrix[pivotPlus12] = workMatrix[maxIndexPlus12];
      workMatrix[maxIndexPlus12] = swapTemp;
    }
    if (pivotThenReciprocal == zero) break;
    pivotThenReciprocal = one / pivotThenReciprocal;
    workMatrix[pivotIndex] = workMatrix[pivotIndex] * pivotThenReciprocal;
    inverseMatrix[pivotIndex] = inverseMatrix[pivotIndex] * pivotThenReciprocal;
    workMatrix[pivotPlus4] = workMatrix[pivotPlus4] * pivotThenReciprocal;
    inverseMatrix[pivotPlus4] = inverseMatrix[pivotPlus4] * pivotThenReciprocal;
    workMatrix[pivotPlus8] = workMatrix[pivotPlus8] * pivotThenReciprocal;
    inverseMatrix[pivotPlus8] = inverseMatrix[pivotPlus8] * pivotThenReciprocal;
    workMatrix[pivotPlus12] = workMatrix[pivotPlus12] * pivotThenReciprocal;
    inverseMatrix[pivotPlus12] = inverseMatrix[pivotPlus12] * pivotThenReciprocal;
    if (pivotIndex != 0) {
      eliminationFactor = workMatrix[pivotIndex * 4];
      workMatrix[0] = -(workMatrix[pivotIndex] * eliminationFactor - workMatrix[0]);
      *inverseMatrix = -(inverseMatrix[pivotIndex] * eliminationFactor - *inverseMatrix);
      workMatrix4 = -(workMatrix[pivotPlus4] * eliminationFactor - workMatrix4);
      *(float *)(glContext + 0x21d0) = -(inverseMatrix[pivotPlus4] * eliminationFactor - *(float *)(glContext + 0x21d0));
      workMatrix8 = -(workMatrix[pivotPlus8] * eliminationFactor - workMatrix8);
      *(float *)(glContext + 0x21e0) = -(inverseMatrix[pivotPlus8] * eliminationFactor - *(float *)(glContext + 0x21e0));
      workMatrix12 = -(workMatrix[pivotPlus12] * eliminationFactor - workMatrix12);
      *(float *)(glContext + 0x21f0) = -(inverseMatrix[pivotPlus12] * eliminationFactor - *(float *)(glContext + 0x21f0));
    }
    if (pivotIndex != 1) {
      eliminationFactor = workMatrix[pivotIndex * 4 + 1];
      workMatrix[1] = -(workMatrix[pivotIndex] * eliminationFactor - workMatrix[1]);
      *(float *)(glContext + 0x21c4) = -(inverseMatrix[pivotIndex] * eliminationFactor - *(float *)(glContext + 0x21c4));
      workMatrix5 = -(workMatrix[pivotPlus4] * eliminationFactor - workMatrix5);
      *(float *)(glContext + 0x21d4) = -(inverseMatrix[pivotPlus4] * eliminationFactor - *(float *)(glContext + 0x21d4));
      workMatrix9 = -(workMatrix[pivotPlus8] * eliminationFactor - workMatrix9);
      *(float *)(glContext + 0x21e4) = -(inverseMatrix[pivotPlus8] * eliminationFactor - *(float *)(glContext + 0x21e4));
      workMatrix13 = -(workMatrix[pivotPlus12] * eliminationFactor - workMatrix13);
      *(float *)(glContext + 0x21f4) = -(inverseMatrix[pivotPlus12] * eliminationFactor - *(float *)(glContext + 0x21f4));
    }
    if (pivotIndex != 2) {
      eliminationFactor = workMatrix[pivotIndex * 4 + 2];
      workMatrix[2] = -(workMatrix[pivotIndex] * eliminationFactor - workMatrix[2]);
      *(float *)(glContext + 0x21c8) = -(inverseMatrix[pivotIndex] * eliminationFactor - *(float *)(glContext + 0x21c8));
      workMatrix6 = -(workMatrix[pivotPlus4] * eliminationFactor - workMatrix6);
      *(float *)(glContext + 0x21d8) = -(inverseMatrix[pivotPlus4] * eliminationFactor - *(float *)(glContext + 0x21d8));
      workMatrix10 = -(workMatrix[pivotPlus8] * eliminationFactor - workMatrix10);
      *(float *)(glContext + 0x21e8) = -(inverseMatrix[pivotPlus8] * eliminationFactor - *(float *)(glContext + 0x21e8));
      workMatrix14 = -(workMatrix[pivotPlus12] * eliminationFactor - workMatrix14);
      *(float *)(glContext + 0x21f8) = -(inverseMatrix[pivotPlus12] * eliminationFactor - *(float *)(glContext + 0x21f8));
    }
    if (pivotIndex != 3) {
      eliminationFactor = workMatrix[pivotIndex * 4 + 3];
      workMatrix[3] = -(workMatrix[pivotIndex] * eliminationFactor - workMatrix[3]);
      *(float *)(glContext + 0x21cc) = -(inverseMatrix[pivotIndex] * eliminationFactor - *(float *)(glContext + 0x21cc));
      workMatrix7 = -(workMatrix[pivotPlus4] * eliminationFactor - workMatrix7);
      *(float *)(glContext + 0x21dc) = -(inverseMatrix[pivotPlus4] * eliminationFactor - *(float *)(glContext + 0x21dc));
      workMatrix11 = -(workMatrix[pivotPlus8] * eliminationFactor - workMatrix11);
      *(float *)(glContext + 0x21ec) = -(inverseMatrix[pivotPlus8] * eliminationFactor - *(float *)(glContext + 0x21ec));
      workMatrix15 = -(workMatrix[pivotPlus12] * eliminationFactor - workMatrix15);
      *(float *)(glContext + 0x21fc) = -(inverseMatrix[pivotPlus12] * eliminationFactor - *(float *)(glContext + 0x21fc));
    }
    pivotIndex = nextPivotIndex;
    if (nextPivotIndex == 4) {
      return;
    }
  }
  *(float *)(glContext + 0x21fc) = one;
  *(float *)(glContext + 0x21f8) = zero;
  *inverseMatrix = one;
  *(float *)(glContext + 0x21c4) = zero;
  *(float *)(glContext + 0x21c8) = zero;
  *(float *)(glContext + 0x21cc) = zero;
  *(float *)(glContext + 0x21d0) = zero;
  *(float *)(glContext + 0x21d4) = one;
  *(float *)(glContext + 0x21d8) = zero;
  *(float *)(glContext + 0x21dc) = zero;
  *(float *)(glContext + 0x21e0) = zero;
  *(float *)(glContext + 0x21e4) = zero;
  *(float *)(glContext + 0x21e8) = one;
  *(float *)(glContext + 0x21ec) = zero;
  *(float *)(glContext + 0x21f0) = zero;
  *(float *)(glContext + 0x21f4) = zero;
  return;
}

/* _gleLoadTransposeMatrixf @ 0xdcce0 (132 bytes) */
int _gleLoadTransposeMatrixf(srcMatrix, dstMatrix)
  undefined4 *srcMatrix;
  undefined4 *dstMatrix;
{
  *dstMatrix = *srcMatrix;
  dstMatrix[1] = srcMatrix[4];
  dstMatrix[2] = srcMatrix[8];
  dstMatrix[3] = srcMatrix[0xc];
  dstMatrix[4] = srcMatrix[1];
  dstMatrix[5] = srcMatrix[5];
  dstMatrix[6] = srcMatrix[9];
  dstMatrix[7] = srcMatrix[0xd];
  dstMatrix[8] = srcMatrix[2];
  dstMatrix[9] = srcMatrix[6];
  dstMatrix[10] = srcMatrix[10];
  dstMatrix[0xb] = srcMatrix[0xe];
  dstMatrix[0xc] = srcMatrix[3];
  dstMatrix[0xd] = srcMatrix[7];
  dstMatrix[0xe] = srcMatrix[0xb];
  dstMatrix[0xf] = srcMatrix[0xf];
  return;
}

/* _gleLoadTransposeMatrixd @ 0xdcd64 (196 bytes) */
int _gleLoadTransposeMatrixd(srcMatrix, dstMatrix)
  double *srcMatrix;
  float *dstMatrix;
{
  *dstMatrix = (float)*srcMatrix;
  dstMatrix[1] = (float)srcMatrix[4];
  dstMatrix[2] = (float)srcMatrix[8];
  dstMatrix[3] = (float)srcMatrix[0xc];
  dstMatrix[4] = (float)srcMatrix[1];
  dstMatrix[5] = (float)srcMatrix[5];
  dstMatrix[6] = (float)srcMatrix[9];
  dstMatrix[7] = (float)srcMatrix[0xd];
  dstMatrix[8] = (float)srcMatrix[2];
  dstMatrix[9] = (float)srcMatrix[6];
  dstMatrix[10] = (float)srcMatrix[10];
  dstMatrix[0xb] = (float)srcMatrix[0xe];
  dstMatrix[0xc] = (float)srcMatrix[3];
  dstMatrix[0xd] = (float)srcMatrix[7];
  dstMatrix[0xe] = (float)srcMatrix[0xb];
  dstMatrix[0xf] = (float)srcMatrix[0xf];
  return;
}

/* _gleGetMatrixf @ 0xdce28 (132 bytes) */
void _gleGetMatrixf(srcMatrix, dstMatrix)
  undefined4 *srcMatrix;
  undefined4 *dstMatrix;
{
  *dstMatrix = *srcMatrix;
  dstMatrix[1] = srcMatrix[1];
  dstMatrix[2] = srcMatrix[2];
  dstMatrix[3] = srcMatrix[3];
  dstMatrix[4] = srcMatrix[4];
  dstMatrix[5] = srcMatrix[5];
  dstMatrix[6] = srcMatrix[6];
  dstMatrix[7] = srcMatrix[7];
  dstMatrix[8] = srcMatrix[8];
  dstMatrix[9] = srcMatrix[9];
  dstMatrix[10] = srcMatrix[10];
  dstMatrix[0xb] = srcMatrix[0xb];
  dstMatrix[0xc] = srcMatrix[0xc];
  dstMatrix[0xd] = srcMatrix[0xd];
  dstMatrix[0xe] = srcMatrix[0xe];
  dstMatrix[0xf] = srcMatrix[0xf];
  return;
}

/* _gleGetTransposeMatrixf @ 0xdceac (132 bytes) */
void _gleGetTransposeMatrixf(srcMatrix, dstMatrix)
  undefined4 *srcMatrix;
  undefined4 *dstMatrix;
{
  *dstMatrix = *srcMatrix;
  dstMatrix[1] = srcMatrix[4];
  dstMatrix[2] = srcMatrix[8];
  dstMatrix[3] = srcMatrix[0xc];
  dstMatrix[4] = srcMatrix[1];
  dstMatrix[5] = srcMatrix[5];
  dstMatrix[6] = srcMatrix[9];
  dstMatrix[7] = srcMatrix[0xd];
  dstMatrix[8] = srcMatrix[2];
  dstMatrix[9] = srcMatrix[6];
  dstMatrix[10] = srcMatrix[10];
  dstMatrix[0xb] = srcMatrix[0xe];
  dstMatrix[0xc] = srcMatrix[3];
  dstMatrix[0xd] = srcMatrix[7];
  dstMatrix[0xe] = srcMatrix[0xb];
  dstMatrix[0xf] = srcMatrix[0xf];
  return;
}

/* _gleGetTransposeMatrixd @ 0xdcf30 (132 bytes) */
void _gleGetTransposeMatrixd(srcMatrix, dstMatrix)
  float *srcMatrix;
  double *dstMatrix;
{
  *dstMatrix = (double)*srcMatrix;
  dstMatrix[1] = (double)srcMatrix[4];
  dstMatrix[2] = (double)srcMatrix[8];
  dstMatrix[3] = (double)srcMatrix[0xc];
  dstMatrix[4] = (double)srcMatrix[1];
  dstMatrix[5] = (double)srcMatrix[5];
  dstMatrix[6] = (double)srcMatrix[9];
  dstMatrix[7] = (double)srcMatrix[0xd];
  dstMatrix[8] = (double)srcMatrix[2];
  dstMatrix[9] = (double)srcMatrix[6];
  dstMatrix[10] = (double)srcMatrix[10];
  dstMatrix[0xb] = (double)srcMatrix[0xe];
  dstMatrix[0xc] = (double)srcMatrix[3];
  dstMatrix[0xd] = (double)srcMatrix[7];
  dstMatrix[0xe] = (double)srcMatrix[0xb];
  dstMatrix[0xf] = (double)srcMatrix[0xf];
  return;
}

/* _gleMultTransposeMatrixf @ 0xdcfb4 (836 bytes) */
void _gleMultTransposeMatrixf(leftMatrix, rightMatrix, productMatrix)
  float *leftMatrix;
  float *rightMatrix;
  float *productMatrix;
{
  *productMatrix = leftMatrix[0xc] * rightMatrix[0xc] +
             (leftMatrix[8] * rightMatrix[8] + (*leftMatrix * *rightMatrix + leftMatrix[4] * rightMatrix[4]));
  productMatrix[4] = leftMatrix[0xc] * rightMatrix[0xd] +
               (leftMatrix[8] * rightMatrix[9] + (*leftMatrix * rightMatrix[1] + leftMatrix[4] * rightMatrix[5]));
  productMatrix[8] = leftMatrix[0xc] * rightMatrix[0xe] +
               (leftMatrix[8] * rightMatrix[10] + (*leftMatrix * rightMatrix[2] + leftMatrix[4] * rightMatrix[6]));
  productMatrix[0xc] = leftMatrix[0xc] * rightMatrix[0xf] +
                 (leftMatrix[8] * rightMatrix[0xb] + (*leftMatrix * rightMatrix[3] + leftMatrix[4] * rightMatrix[7]));
  productMatrix[1] = leftMatrix[0xd] * rightMatrix[0xc] +
               (leftMatrix[9] * rightMatrix[8] + (leftMatrix[1] * *rightMatrix + leftMatrix[5] * rightMatrix[4]));
  productMatrix[5] = leftMatrix[0xd] * rightMatrix[0xd] +
               (leftMatrix[9] * rightMatrix[9] + (leftMatrix[1] * rightMatrix[1] + leftMatrix[5] * rightMatrix[5]));
  productMatrix[9] = leftMatrix[0xd] * rightMatrix[0xe] +
               (leftMatrix[9] * rightMatrix[10] + (leftMatrix[1] * rightMatrix[2] + leftMatrix[5] * rightMatrix[6]));
  productMatrix[0xd] = leftMatrix[0xd] * rightMatrix[0xf] +
                 (leftMatrix[9] * rightMatrix[0xb] + (leftMatrix[1] * rightMatrix[3] + leftMatrix[5] * rightMatrix[7]));
  productMatrix[2] = leftMatrix[0xe] * rightMatrix[0xc] +
               (leftMatrix[10] * rightMatrix[8] + (leftMatrix[2] * *rightMatrix + leftMatrix[6] * rightMatrix[4]));
  productMatrix[6] = leftMatrix[0xe] * rightMatrix[0xd] +
               (leftMatrix[10] * rightMatrix[9] + (leftMatrix[2] * rightMatrix[1] + leftMatrix[6] * rightMatrix[5]));
  productMatrix[10] = leftMatrix[0xe] * rightMatrix[0xe] +
                (leftMatrix[10] * rightMatrix[10] + (leftMatrix[2] * rightMatrix[2] + leftMatrix[6] * rightMatrix[6]));
  productMatrix[0xe] = leftMatrix[0xe] * rightMatrix[0xf] +
                 (leftMatrix[10] * rightMatrix[0xb] + (leftMatrix[2] * rightMatrix[3] + leftMatrix[6] * rightMatrix[7]));
  productMatrix[3] = leftMatrix[0xf] * rightMatrix[0xc] +
               (leftMatrix[0xb] * rightMatrix[8] + (leftMatrix[3] * *rightMatrix + leftMatrix[7] * rightMatrix[4]));
  productMatrix[7] = leftMatrix[0xf] * rightMatrix[0xd] +
               (leftMatrix[0xb] * rightMatrix[9] + (leftMatrix[3] * rightMatrix[1] + leftMatrix[7] * rightMatrix[5]));
  productMatrix[0xb] = leftMatrix[0xf] * rightMatrix[0xe] +
                 (leftMatrix[0xb] * rightMatrix[10] + (leftMatrix[3] * rightMatrix[2] + leftMatrix[7] * rightMatrix[6]));
  productMatrix[0xf] = leftMatrix[0xf] * rightMatrix[0xf] +
                 (leftMatrix[0xb] * rightMatrix[0xb] + (leftMatrix[3] * rightMatrix[3] + leftMatrix[7] * rightMatrix[7]));
  return;
}

/* _gleMultTransposeMatrixd @ 0xdd2f8 (900 bytes) */
void _gleMultTransposeMatrixd(leftMatrix, rightMatrix, productMatrix)
  float *leftMatrix;
  double *rightMatrix;
  float *productMatrix;
{
  *productMatrix = (float)((double)leftMatrix[0xc] * rightMatrix[0xc] +
                    ((double)leftMatrix[8] * rightMatrix[8] +
                    ((double)*leftMatrix * *rightMatrix + (double)leftMatrix[4] * rightMatrix[4])));
  productMatrix[4] = (float)((double)leftMatrix[0xc] * rightMatrix[0xd] +
                      ((double)leftMatrix[8] * rightMatrix[9] +
                      ((double)*leftMatrix * rightMatrix[1] + (double)leftMatrix[4] * rightMatrix[5])));
  productMatrix[8] = (float)((double)leftMatrix[0xc] * rightMatrix[0xe] +
                      ((double)leftMatrix[8] * rightMatrix[10] +
                      ((double)*leftMatrix * rightMatrix[2] + (double)leftMatrix[4] * rightMatrix[6])));
  productMatrix[0xc] = (float)((double)leftMatrix[0xc] * rightMatrix[0xf] +
                        ((double)leftMatrix[8] * rightMatrix[0xb] +
                        ((double)*leftMatrix * rightMatrix[3] + (double)leftMatrix[4] * rightMatrix[7])));
  productMatrix[1] = (float)((double)leftMatrix[0xd] * rightMatrix[0xc] +
                      ((double)leftMatrix[9] * rightMatrix[8] +
                      ((double)leftMatrix[1] * *rightMatrix + (double)leftMatrix[5] * rightMatrix[4])));
  productMatrix[5] = (float)((double)leftMatrix[0xd] * rightMatrix[0xd] +
                      ((double)leftMatrix[9] * rightMatrix[9] +
                      ((double)leftMatrix[1] * rightMatrix[1] + (double)leftMatrix[5] * rightMatrix[5])));
  productMatrix[9] = (float)((double)leftMatrix[0xd] * rightMatrix[0xe] +
                      ((double)leftMatrix[9] * rightMatrix[10] +
                      ((double)leftMatrix[1] * rightMatrix[2] + (double)leftMatrix[5] * rightMatrix[6])));
  productMatrix[0xd] = (float)((double)leftMatrix[0xd] * rightMatrix[0xf] +
                        ((double)leftMatrix[9] * rightMatrix[0xb] +
                        ((double)leftMatrix[1] * rightMatrix[3] + (double)leftMatrix[5] * rightMatrix[7])));
  productMatrix[2] = (float)((double)leftMatrix[0xe] * rightMatrix[0xc] +
                      ((double)leftMatrix[10] * rightMatrix[8] +
                      ((double)leftMatrix[2] * *rightMatrix + (double)leftMatrix[6] * rightMatrix[4])));
  productMatrix[6] = (float)((double)leftMatrix[0xe] * rightMatrix[0xd] +
                      ((double)leftMatrix[10] * rightMatrix[9] +
                      ((double)leftMatrix[2] * rightMatrix[1] + (double)leftMatrix[6] * rightMatrix[5])));
  productMatrix[10] = (float)((double)leftMatrix[0xe] * rightMatrix[0xe] +
                       ((double)leftMatrix[10] * rightMatrix[10] +
                       ((double)leftMatrix[2] * rightMatrix[2] + (double)leftMatrix[6] * rightMatrix[6])));
  productMatrix[0xe] = (float)((double)leftMatrix[0xe] * rightMatrix[0xf] +
                        ((double)leftMatrix[10] * rightMatrix[0xb] +
                        ((double)leftMatrix[2] * rightMatrix[3] + (double)leftMatrix[6] * rightMatrix[7])));
  productMatrix[3] = (float)((double)leftMatrix[0xf] * rightMatrix[0xc] +
                      ((double)leftMatrix[0xb] * rightMatrix[8] +
                      ((double)leftMatrix[3] * *rightMatrix + (double)leftMatrix[7] * rightMatrix[4])));
  productMatrix[7] = (float)((double)leftMatrix[0xf] * rightMatrix[0xd] +
                      ((double)leftMatrix[0xb] * rightMatrix[9] +
                      ((double)leftMatrix[3] * rightMatrix[1] + (double)leftMatrix[7] * rightMatrix[5])));
  productMatrix[0xb] = (float)((double)leftMatrix[0xf] * rightMatrix[0xe] +
                        ((double)leftMatrix[0xb] * rightMatrix[10] +
                        ((double)leftMatrix[3] * rightMatrix[2] + (double)leftMatrix[7] * rightMatrix[6])));
  productMatrix[0xf] = (float)((double)leftMatrix[0xf] * rightMatrix[0xf] +
                        ((double)leftMatrix[0xb] * rightMatrix[0xb] +
                        ((double)leftMatrix[3] * rightMatrix[3] + (double)leftMatrix[7] * rightMatrix[7])));
  return;
}

/* _gleMultTransposeMatrix @ 0xdd67c (836 bytes) */
void _gleMultTransposeMatrix(leftMatrix, rightMatrix, productMatrix)
  float *leftMatrix;
  float *rightMatrix;
  float *productMatrix;
{
  *productMatrix = leftMatrix[0xc] * rightMatrix[0xc] +
             (leftMatrix[8] * rightMatrix[8] + (*leftMatrix * *rightMatrix + leftMatrix[4] * rightMatrix[4]));
  productMatrix[4] = leftMatrix[0xc] * rightMatrix[0xd] +
               (leftMatrix[8] * rightMatrix[9] + (*leftMatrix * rightMatrix[1] + leftMatrix[4] * rightMatrix[5]));
  productMatrix[8] = leftMatrix[0xc] * rightMatrix[0xe] +
               (leftMatrix[8] * rightMatrix[10] + (*leftMatrix * rightMatrix[2] + leftMatrix[4] * rightMatrix[6]));
  productMatrix[0xc] = leftMatrix[0xc] * rightMatrix[0xf] +
                 (leftMatrix[8] * rightMatrix[0xb] + (*leftMatrix * rightMatrix[3] + leftMatrix[4] * rightMatrix[7]));
  productMatrix[1] = leftMatrix[0xd] * rightMatrix[0xc] +
               (leftMatrix[9] * rightMatrix[8] + (leftMatrix[1] * *rightMatrix + leftMatrix[5] * rightMatrix[4]));
  productMatrix[5] = leftMatrix[0xd] * rightMatrix[0xd] +
               (leftMatrix[9] * rightMatrix[9] + (leftMatrix[1] * rightMatrix[1] + leftMatrix[5] * rightMatrix[5]));
  productMatrix[9] = leftMatrix[0xd] * rightMatrix[0xe] +
               (leftMatrix[9] * rightMatrix[10] + (leftMatrix[1] * rightMatrix[2] + leftMatrix[5] * rightMatrix[6]));
  productMatrix[0xd] = leftMatrix[0xd] * rightMatrix[0xf] +
                 (leftMatrix[9] * rightMatrix[0xb] + (leftMatrix[1] * rightMatrix[3] + leftMatrix[5] * rightMatrix[7]));
  productMatrix[2] = leftMatrix[0xe] * rightMatrix[0xc] +
               (leftMatrix[10] * rightMatrix[8] + (leftMatrix[2] * *rightMatrix + leftMatrix[6] * rightMatrix[4]));
  productMatrix[6] = leftMatrix[0xe] * rightMatrix[0xd] +
               (leftMatrix[10] * rightMatrix[9] + (leftMatrix[2] * rightMatrix[1] + leftMatrix[6] * rightMatrix[5]));
  productMatrix[10] = leftMatrix[0xe] * rightMatrix[0xe] +
                (leftMatrix[10] * rightMatrix[10] + (leftMatrix[2] * rightMatrix[2] + leftMatrix[6] * rightMatrix[6]));
  productMatrix[0xe] = leftMatrix[0xe] * rightMatrix[0xf] +
                 (leftMatrix[10] * rightMatrix[0xb] + (leftMatrix[2] * rightMatrix[3] + leftMatrix[6] * rightMatrix[7]));
  productMatrix[3] = leftMatrix[0xf] * rightMatrix[0xc] +
               (leftMatrix[0xb] * rightMatrix[8] + (leftMatrix[3] * *rightMatrix + leftMatrix[7] * rightMatrix[4]));
  productMatrix[7] = leftMatrix[0xf] * rightMatrix[0xd] +
               (leftMatrix[0xb] * rightMatrix[9] + (leftMatrix[3] * rightMatrix[1] + leftMatrix[7] * rightMatrix[5]));
  productMatrix[0xb] = leftMatrix[0xf] * rightMatrix[0xe] +
                 (leftMatrix[0xb] * rightMatrix[10] + (leftMatrix[3] * rightMatrix[2] + leftMatrix[7] * rightMatrix[6]));
  productMatrix[0xf] = leftMatrix[0xf] * rightMatrix[0xf] +
                 (leftMatrix[0xb] * rightMatrix[0xb] + (leftMatrix[3] * rightMatrix[3] + leftMatrix[7] * rightMatrix[7]));
  return;
}

/* _glePreEvaluate @ 0xdd9cc (164 bytes) */
void _glePreEvaluate(undefined4 unusedArg1,int order,undefined4 unusedArg3,float *coeffs,float u,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double newCoeff;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float dVar6;
  float oneMinusU;
  
  if (order == 1) {
    *coeffs = 1.0;
    return;
  }
  dVar6 = (double)FLOAT_00108e54;
  coeffs[1] = (float)u;
  oneMinusU = (double)(dVar6 - u);
  *coeffs = (dVar6 - u);
  if (order != 2) {
    iVar5 = 2;
    if (2 < order) {
      do {
        iVar3 = 1;
        dVar6 = (double)(*coeffs * u);
        *coeffs = (oneMinusU * *coeffs);
        if (1 < iVar5) {
          iVar2 = iVar5 + -1;
          iVar4 = iVar3;
          do {
            iVar3 = iVar4 + 1;
            newCoeff = (double)oneMinusU * (double)coeffs[iVar4] + (double)dVar6;
            dVar6 = (double)(coeffs[iVar4] * u);
            coeffs[iVar4] = (float)newCoeff;
            iVar2 = iVar2 + -1;
            iVar4 = iVar3;
          } while (iVar2 != 0);
        }
        iVar5 = iVar5 + 1;
        coeffs[iVar3] = (float)(double)dVar6;
      } while (iVar5 < order);
      return;
    }
    return;
  }
  return;
}

/* _glePreEvaluateWithDeriv @ 0xdda70 (356 bytes) */
void _glePreEvaluateWithDeriv(undefined4 unusedArg1,int order,undefined4 unusedArg3,float *coefficients,float *derivatives,float floatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double blended;
  float oneMinusU;
  float previousCoefficient;
  int innerCount;
  int nextIndex;
  int degree;
  int coefficientIndex;
  int coefficientIndexA;
  int differenceCount;
  float *coefficientCursor;
  int degreeCursor;
  float oneMinusUValue;
  float carry;
  
  oneMinusU = (FLOAT_00108e54 - floatArg1);
  oneMinusUValue = (double)oneMinusU;
  if (order == 1) {
    *coefficients = FLOAT_00108e54;
    *derivatives = 0.0;
    return;
  }
  if (order == 2) {
    derivatives[1] = FLOAT_00108e54;
    *derivatives = -1.0;
    coefficients[1] = (float)floatArg1;
    *coefficients = oneMinusU;
    return;
  }
  degree = order + -1;
  degreeCursor = 2;
  *coefficients = oneMinusU;
  coefficients[1] = (float)floatArg1;
  if (2 < degree) {
    do {
      nextIndex = 1;
      carry = (double)(*coefficients * floatArg1);
      *coefficients = (oneMinusUValue * *coefficients);
      if (1 < degreeCursor) {
        innerCount = degreeCursor + -1;
        coefficientIndexA = nextIndex;
        do {
          nextIndex = coefficientIndexA + 1;
          blended = (double)oneMinusUValue * (double)coefficients[coefficientIndexA] + (double)carry;
          carry = (double)(coefficients[coefficientIndexA] * floatArg1);
          coefficients[coefficientIndexA] = (float)blended;
          innerCount = innerCount + -1;
          coefficientIndexA = nextIndex;
        } while (innerCount != 0);
      }
      degreeCursor = degreeCursor + 1;
      coefficients[nextIndex] = (float)(double)carry;
    } while (degreeCursor < degree);
  }
  differenceCount = order + -2;
  *derivatives = -*coefficients;
  nextIndex = 1;
  coefficientCursor = coefficients;
  if (degree < 2) {
    differenceCount = 1;
  }
  do {
    coefficientIndex = nextIndex;
    previousCoefficient = *coefficientCursor;
    coefficientCursor = coefficientCursor + 1;
    derivatives[coefficientIndex] = previousCoefficient - coefficients[coefficientIndex];
    differenceCount = differenceCount + -1;
    nextIndex = coefficientIndex + 1;
  } while (differenceCount != 0);
  nextIndex = 1;
  derivatives[coefficientIndex + 1] = coefficients[coefficientIndex];
  carry = (double)(*coefficients * floatArg1);
  *coefficients = (oneMinusUValue * *coefficients);
  if (1 < degreeCursor) {
    degreeCursor = degreeCursor + -1;
    coefficientIndex = nextIndex;
    do {
      nextIndex = coefficientIndex + 1;
      blended = (double)oneMinusUValue * (double)coefficients[coefficientIndex] + (double)carry;
      carry = (double)(coefficients[coefficientIndex] * floatArg1);
      coefficients[coefficientIndex] = (float)blended;
      degreeCursor = degreeCursor + -1;
      coefficientIndex = nextIndex;
    } while (degreeCursor != 0);
  }
  coefficients[nextIndex] = (float)(double)carry;
  return;
}

/* _gleEvalDomain1Color @ 0xddbd4 (244 bytes) */
void _gleEvalDomain1Color(undefined4 glContext,int points,int order,undefined4 unusedArg4,int components,int out,float u,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,float unusedFloatArg12,float unusedFloatArg13)
{
  float coeff;
  float controlValue;
  int componentByteOffset;
  float *pointPtr;
  float *coeffPtr;
  int component;
  int pointsRemaining;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  double incomingStack_ffffffb0;
  double incomingStack_ffffffb8;
  
  if (((double)GH_U2F((unsigned int)_uvalue_c) != u) || (_uorder_c != order)) {
    ((void (*)())_glePreEvaluate)(glContext,order,order,&_ucoeff_c,u,floatArg2,floatArg3,floatArg4,floatArg5,
                    floatArg6,floatArg7,floatArg8,incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8
                    ,incomingStack_ffffffb0,incomingStack_ffffffb8);
    _uvalue_c = GH_F2U((float)u);
    _utype_c = 2;
    _uorder_c = order;
  }
  component = 0;
  if (0 < components) {
    do {
      componentByteOffset = component * 4;
      *(undefined4 *)(out + componentByteOffset) = 0;
      pointPtr = (float *)(points + componentByteOffset);
      if (0 < order) {
        coeffPtr = (float *)&_ucoeff_c;
        pointsRemaining = order;
        do {
          coeff = *coeffPtr;
          coeffPtr = coeffPtr + 1;
          controlValue = *pointPtr;
          pointPtr = pointPtr + components;
          *(float *)(out + componentByteOffset) = coeff * controlValue + *(float *)(out + componentByteOffset);
          pointsRemaining = pointsRemaining + -1;
        } while (pointsRemaining != 0);
      }
      component = component + 1;
    } while (component < components);
  }
  return;
}

/* _gleEvalDomain1Coord @ 0xddcc8 (244 bytes) */
void _gleEvalDomain1Coord(undefined4 glContext,int points,int order,undefined4 unusedArg4,int components,int out,float u,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,float unusedFloatArg12,float unusedFloatArg13)
{
  float coeff;
  float controlValue;
  int componentByteOffset;
  float *pointPtr;
  float *coeffPtr;
  int component;
  int pointsRemaining;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  double incomingStack_ffffffb0;
  double incomingStack_ffffffb8;
  
  if (((double)GH_U2F((unsigned int)_uvalue_c) != u) || (_uorder_c != order)) {
    ((void (*)())_glePreEvaluate)(glContext,order,order,&_ucoeff_c,u,floatArg2,floatArg3,floatArg4,floatArg5,
                    floatArg6,floatArg7,floatArg8,incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8
                    ,incomingStack_ffffffb0,incomingStack_ffffffb8);
    _uvalue_c = GH_F2U((float)u);
    _utype_c = 2;
    _uorder_c = order;
  }
  component = 0;
  if (0 < components) {
    do {
      componentByteOffset = component * 4;
      *(undefined4 *)(out + componentByteOffset) = 0;
      pointPtr = (float *)(points + componentByteOffset);
      if (0 < order) {
        coeffPtr = (float *)&_ucoeff_c;
        pointsRemaining = order;
        do {
          coeff = *coeffPtr;
          coeffPtr = coeffPtr + 1;
          controlValue = *pointPtr;
          pointPtr = pointPtr + components;
          *(float *)(out + componentByteOffset) = coeff * controlValue + *(float *)(out + componentByteOffset);
          pointsRemaining = pointsRemaining + -1;
        } while (pointsRemaining != 0);
      }
      component = component + 1;
    } while (component < components);
  }
  return;
}

/* _gleEvalDomain2Color @ 0xdddbc (420 bytes) */
void _gleEvalDomain2Color(undefined4 glContext,int points,int uorder,int vorder,undefined4 unusedArg5,undefined4 unusedArg6,int components,int out,float u,float v,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,float unusedFloatArg12,float unusedFloatArg13)
{
  float vSum;
  float controlValue;
  int componentByteOffset;
  int uRemaining;
  float *vCoeffPtr;
  int iVar6;
  float *uCoeffPtr;
  float *pointPtr;
  int vRemaining;
  float dVar10;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  
  iVar6 = uorder;
  dVar10 = v;
  if (((double)GH_U2F((unsigned int)_uvalue_c) != u) || (_uorder_c != uorder)) {
    ((void (*)())_glePreEvaluate)(glContext,uorder,uorder,&_ucoeff_c,u,v,floatArg3,floatArg4,floatArg5,
                    floatArg6,floatArg7,floatArg8,incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98
                    ,incomingStack_ffffffa0,incomingStack_ffffffa8);
    _uvalue_c = GH_F2U((float)u);
    _utype_c = 2;
    _uorder_c = uorder;
  }
  if (((double)GH_U2F((unsigned int)_vvalue_c) != v) || (_vorder_c != vorder)) {
    ((void (*)())_glePreEvaluate)(glContext,vorder,iVar6,&_vcoeff_c,v,(double)dVar10,floatArg3,floatArg4,floatArg5,
                    floatArg6,floatArg7,floatArg8,incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98
                    ,incomingStack_ffffffa0,incomingStack_ffffffa8);
    _vvalue_c = GH_F2U((float)v);
    _vtype_c = 2;
    _vorder_c = vorder;
  }
  iVar6 = 0;
  if (0 < components) {
    do {
      componentByteOffset = iVar6 * 4;
      *(undefined4 *)(componentByteOffset + out) = 0;
      pointPtr = (float *)(points + componentByteOffset);
      if (0 < uorder) {
        uCoeffPtr = (float *)&_ucoeff_c;
        uRemaining = uorder;
        do {
          vSum = *pointPtr;
          pointPtr = pointPtr + components;
          vSum = GH_U2F((unsigned int)_vcoeff_c) * vSum;
          if (1 < vorder) {
            vRemaining = vorder + -1;
            vCoeffPtr = &_vcoeff_c;
            do {
              vCoeffPtr = vCoeffPtr + 1;
              controlValue = *pointPtr;
              pointPtr = pointPtr + components;
              vSum = *vCoeffPtr * controlValue + vSum;
              vRemaining = vRemaining + -1;
            } while (vRemaining != 0);
          }
          controlValue = *uCoeffPtr;
          uRemaining = uRemaining + -1;
          uCoeffPtr = uCoeffPtr + 1;
          *(float *)(componentByteOffset + out) = controlValue * vSum + *(float *)(componentByteOffset + out);
        } while (uRemaining != 0);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < components);
  }
  return;
}

/* _gleEvalDomain2Coord @ 0xddf60 (420 bytes) */
void _gleEvalDomain2Coord(undefined4 glContext,int points,int uorder,int vorder,undefined4 unusedArg5,undefined4 unusedArg6,int components,int out,float u,float v,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,float unusedFloatArg12,float unusedFloatArg13)
{
  float vSum;
  float controlValue;
  int componentByteOffset;
  int uRemaining;
  float *vCoeffPtr;
  int uorderThenComponentIndex;
  float *uCoeffPtr;
  float *pointPtr;
  int vRemaining;
  float vCopy;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  
  uorderThenComponentIndex = uorder;
  vCopy = v;
  if (((double)GH_U2F((unsigned int)_uvalue_c) != u) || (_uorder_c != uorder)) {
    ((void (*)())_glePreEvaluate)(glContext,uorder,uorder,&_ucoeff_c,u,v,floatArg3,floatArg4,floatArg5,
                    floatArg6,floatArg7,floatArg8,incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98
                    ,incomingStack_ffffffa0,incomingStack_ffffffa8);
    _uvalue_c = GH_F2U((float)u);
    _utype_c = 2;
    _uorder_c = uorder;
  }
  if (((double)GH_U2F((unsigned int)_vvalue_c) != v) || (_vorder_c != vorder)) {
    ((void (*)())_glePreEvaluate)(glContext,vorder,uorderThenComponentIndex,&_vcoeff_c,v,(double)vCopy,floatArg3,floatArg4,floatArg5,
                    floatArg6,floatArg7,floatArg8,incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98
                    ,incomingStack_ffffffa0,incomingStack_ffffffa8);
    _vvalue_c = GH_F2U((float)v);
    _vtype_c = 2;
    _vorder_c = vorder;
  }
  uorderThenComponentIndex = 0;
  if (0 < components) {
    do {
      componentByteOffset = uorderThenComponentIndex * 4;
      *(undefined4 *)(componentByteOffset + out) = 0;
      pointPtr = (float *)(points + componentByteOffset);
      if (0 < uorder) {
        uCoeffPtr = (float *)&_ucoeff_c;
        uRemaining = uorder;
        do {
          vSum = *pointPtr;
          pointPtr = pointPtr + components;
          vSum = GH_U2F((unsigned int)_vcoeff_c) * vSum;
          if (1 < vorder) {
            vRemaining = vorder + -1;
            vCoeffPtr = &_vcoeff_c;
            do {
              vCoeffPtr = vCoeffPtr + 1;
              controlValue = *pointPtr;
              pointPtr = pointPtr + components;
              vSum = *vCoeffPtr * controlValue + vSum;
              vRemaining = vRemaining + -1;
            } while (vRemaining != 0);
          }
          controlValue = *uCoeffPtr;
          uRemaining = uRemaining + -1;
          uCoeffPtr = uCoeffPtr + 1;
          *(float *)(componentByteOffset + out) = controlValue * vSum + *(float *)(componentByteOffset + out);
        } while (uRemaining != 0);
      }
      uorderThenComponentIndex = uorderThenComponentIndex + 1;
    } while (uorderThenComponentIndex < components);
  }
  return;
}

/* _gleEvalDomainDeriv2Coord @ 0xde104 (572 bytes) */
void _gleEvalDomainDeriv2Coord(undefined4 glContext,int controlPoints,int uOrder,int vOrder,undefined4 unusedArg5,undefined4 unusedArg6,int componentCount,int outDerivU,int outDerivV,int outValue,float floatArg1,float floatArg2,double floatArg3,double floatArg4,float floatArg5,float floatArg6,float floatArg7,float floatArg8,float unusedFloatArg9,float unusedFloatArg10,float unusedFloatArg11,float unusedFloatArg12,float unusedFloatArg13)
{
  float fVar1;
  float controlPointValue;
  int componentByteOffset;
  float derivVSum;
  float vDerivRowSum;
  float valueSum;
  float derivUSum;
  int uIndex;
  float *controlPointCursor;
  int vIndex;
  int nextUIndex;
  int nextVIndex;
  int iVar12;
  int componentIndex;
  float dVar13;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  double incomingStack_ffffff98;
  
  iVar12 = uOrder;
  dVar13 = floatArg2;
  if ((((double)GH_U2F((unsigned int)_uvalue_c) != floatArg1) || (_utype_c != 1)) || (_uorder_c != uOrder)) {
    ((void (*)())_glePreEvaluateWithDeriv)(glContext,uOrder,uOrder,&_ucoeff_c,&_ucoeffDeriv_c,floatArg1,floatArg2,floatArg3,
               floatArg4,floatArg5,floatArg6,floatArg7,floatArg8,incomingStack_ffffff78,incomingStack_ffffff80,
               incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98);
    _utype_c = 1;
    _uvalue_c = GH_F2U((float)floatArg1);
    _uorder_c = uOrder;
  }
  if ((((double)GH_U2F((unsigned int)_vvalue_c) != floatArg2) || (_vtype_c != 1)) || (_vorder_c != vOrder)) {
    ((void (*)())_glePreEvaluateWithDeriv)(glContext,vOrder,iVar12,&_vcoeff_c,&_vcoeffDeriv_c,floatArg2,(double)dVar13,floatArg3,floatArg4,
               floatArg5,floatArg6,floatArg7,floatArg8,incomingStack_ffffff78,incomingStack_ffffff80,
               incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98);
    _vtype_c = 1;
    _vvalue_c = GH_F2U((float)floatArg2);
    _vorder_c = vOrder;
  }
  componentIndex = 0;
  if (0 < componentCount) {
    do {
      uIndex = 0;
      componentByteOffset = componentIndex * 4;
      controlPointCursor = (float *)(controlPoints + componentByteOffset);
      derivVSum = FLOAT_00108e50;
      valueSum = FLOAT_00108e50;
      derivUSum = FLOAT_00108e50;
      if (0 < uOrder) {
        do {
          vIndex = 1;
          fVar1 = *controlPointCursor;
          controlPointCursor = controlPointCursor + componentCount;
          vDerivRowSum = GH_U2F((unsigned int)_vcoeffDeriv_c) * fVar1;
          fVar1 = GH_U2F((unsigned int)_vcoeff_c) * fVar1;
          if (1 < vOrder) {
            do {
              nextVIndex = vIndex + 1;
              controlPointValue = *controlPointCursor;
              controlPointCursor = controlPointCursor + componentCount;
              vDerivRowSum = GH_U2F((unsigned int)((&_vcoeffDeriv_c)[vIndex])) * controlPointValue + vDerivRowSum;
              fVar1 = GH_U2F((unsigned int)((&_vcoeff_c)[vIndex])) * controlPointValue + fVar1;
              vIndex = nextVIndex;
            } while (nextVIndex < vOrder);
          }
          nextUIndex = uIndex + 1;
          derivVSum = GH_U2F((unsigned int)((&_ucoeff_c)[uIndex])) * vDerivRowSum + derivVSum;
          derivUSum = GH_U2F((unsigned int)((&_ucoeffDeriv_c)[uIndex])) * fVar1 + derivUSum;
          valueSum = GH_U2F((unsigned int)((&_ucoeff_c)[uIndex])) * fVar1 + valueSum;
          uIndex = nextUIndex;
        } while (nextUIndex < uOrder);
      }
      componentIndex = componentIndex + 1;
      *(float *)(componentByteOffset + outValue) = valueSum;
      *(float *)(componentByteOffset + outDerivU) = derivUSum;
      *(float *)(componentByteOffset + outDerivV) = derivVSum;
    } while (componentIndex < componentCount);
  }
  return;
}

/* _gleInitMap1Data @ 0xde340 (336 bytes) */
void _gleInitMap1Data(glContext)
  int glContext;
{
  undefined4 *map1Cursor;
  undefined4 *componentCountCursor;
  int remaining;
  
  map1Cursor = *(undefined4 **)(glContext + 0x7450);
  remaining = 0x10;
  *map1Cursor = 1;
  map1Cursor[1] = 0;
  map1Cursor[2] = 0x3f800000;
  componentCountCursor = map1Cursor + 0x276a;
  map1Cursor[3] = 0x3f800000;
  map1Cursor[4] = 0;
  map1Cursor[5] = 0;
  map1Cursor[6] = 0;
  map1Cursor[0x22] = 1;
  map1Cursor[0x23] = 0;
  map1Cursor[0x24] = 0x3f800000;
  map1Cursor[0x25] = 0x3f800000;
  map1Cursor[0x26] = 0;
  map1Cursor[0x27] = 0;
  map1Cursor[0x28] = 0;
  map1Cursor[0x29] = 0x3f800000;
  map1Cursor[0x4e] = 1;
  map1Cursor[0x4f] = 0;
  map1Cursor[0x50] = 0x3f800000;
  map1Cursor[0x51] = 0x3f800000;
  map1Cursor[0x52] = 0;
  map1Cursor[0x53] = 0;
  map1Cursor[0x54] = 0x3f800000;
  map1Cursor[0x70] = 1;
  map1Cursor[0x71] = 0;
  map1Cursor[0x72] = 0x3f800000;
  map1Cursor[0x73] = 0x3f800000;
  map1Cursor[0x74] = 0x3f800000;
  map1Cursor[0x75] = 0x3f800000;
  map1Cursor[0x76] = 0x3f800000;
  map1Cursor[0x77] = 0x3f800000;
  map1Cursor[0x9c] = 1;
  map1Cursor[0x9d] = 0;
  map1Cursor[0x9e] = 0x3f800000;
  map1Cursor[0xf2] = 1;
  map1Cursor[0x9f] = 0x3f800000;
  map1Cursor[0xa0] = 0x3f800000;
  map1Cursor[0xaa] = 1;
  map1Cursor[0xab] = 0;
  map1Cursor[0xac] = 0x3f800000;
  map1Cursor[0xad] = 0x3f800000;
  map1Cursor[0xae] = 0;
  map1Cursor[0xb8] = 1;
  map1Cursor[0xb9] = 0;
  map1Cursor[0xba] = 0x3f800000;
  map1Cursor[0xbb] = 0x3f800000;
  map1Cursor[0xbc] = 0;
  map1Cursor[0xbd] = 0;
  map1Cursor[0xd0] = 1;
  map1Cursor[0xd1] = 0;
  map1Cursor[0xd2] = 0x3f800000;
  map1Cursor[0xd3] = 0x3f800000;
  map1Cursor[0xd4] = 0;
  map1Cursor[0xd5] = 0;
  map1Cursor[0xd6] = 0;
  map1Cursor[0xf3] = 0;
  map1Cursor[0xf4] = 0x3f800000;
  map1Cursor[0xf5] = 0x3f800000;
  map1Cursor[0xf6] = 0;
  map1Cursor[0xf7] = 0;
  map1Cursor[0xf8] = 0;
  map1Cursor[0xf9] = 0x3f800000;
  do {
    *(undefined1 *)componentCountCursor = 4;
    componentCountCursor = (undefined4 *)((int)componentCountCursor + 1);
    map1Cursor[0xb2a] = 1;
    map1Cursor[0xb2b] = 0;
    map1Cursor[0xb2c] = 0x3f800000;
    map1Cursor[0xb2d] = 0x3f800000;
    map1Cursor[0xb2e] = 0;
    map1Cursor[0xb2f] = 0;
    map1Cursor[0xb30] = 0;
    map1Cursor[0xb31] = 0x3f800000;
    map1Cursor = map1Cursor + 0x2c;
    remaining = remaining + -1;
  } while (remaining != 0);
  return;
}

/* _gleMap1Vertex3dLoad @ 0xde490 (144 bytes) */
void _gleMap1Vertex3dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int stride,int order,int points,int *mapData,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int pointByteOffset;
  int pointElementOffset;
  int pointAddr;
  double invUDelta;
  
  pointElementOffset = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)invUDelta);
  mapData[2] = (int)GH_F2U((float)u2);
  if (0 < order) {
    do {
      pointByteOffset = pointElementOffset * 8;
      pointElementOffset = pointElementOffset + stride;
      pointAddr = pointByteOffset + points;
      mapData[4] = (int)GH_F2U((float)*(double *)(pointByteOffset + points));
      mapData[5] = (int)GH_F2U((float)*(double *)(pointAddr + 8));
      mapData[6] = (int)GH_F2U((float)*(double *)(pointAddr + 0x10));
      mapData = mapData + 3;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

