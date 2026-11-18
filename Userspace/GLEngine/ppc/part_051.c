#include "decls.h"

/* _gleInsertPixel_A_Short @ 0xea224 (52 bytes) */
void _gleInsertPixel_A_Short(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  *dst = (short)(int)(*(float *)(pixel + 0x10) * FLOAT_00108f74);
  return;
}

/* _gleInsertPixel_A_Ushort @ 0xea258 (52 bytes) */
void _gleInsertPixel_A_Ushort(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  *dst = (short)(int)(*(float *)(pixel + 0x10) * FLOAT_00108ea0);
  return;
}

/* _gleInsertPixel_A_Int @ 0xea28c (52 bytes) */
void _gleInsertPixel_A_Int(pixel, dst)
  int pixel;
  int *dst;
{
  *dst = (int)((double)*(float *)(pixel + 0x10) * DOUBLE_00108d90);
  return;
}

/* _gleInsertPixel_A_Uint @ 0xea2c0 (96 bytes) */
void _gleInsertPixel_A_Uint(pixel, dst)
  int pixel;
  uint *dst;
{
  uint channelValue;
  double scaledChannel;
  
  scaledChannel = (double)*(float *)(pixel + 0x10) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  *dst = channelValue;
  return;
}

/* _gleInsertPixel_A_Float @ 0xea320 (12 bytes) */
void _gleInsertPixel_A_Float(pixel, dst)
  int pixel;
  undefined4 *dst;
{
  *dst = *(undefined4 *)(pixel + 0x10);
  return;
}

/* _gleInsertPixel_L_Byte @ 0xea32c (52 bytes) */
void _gleInsertPixel_L_Byte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  *dst = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f6c);
  return;
}

/* _gleInsertPixel_L_Ubyte @ 0xea360 (52 bytes) */
void _gleInsertPixel_L_Ubyte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  *dst = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f70);
  return;
}

/* _gleInsertPixel_L_Short @ 0xea394 (52 bytes) */
void _gleInsertPixel_L_Short(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  *dst = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108f74);
  return;
}

/* _gleInsertPixel_L_Ushort @ 0xea3c8 (52 bytes) */
void _gleInsertPixel_L_Ushort(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  *dst = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0);
  return;
}

/* _gleInsertPixel_L_Int @ 0xea3fc (52 bytes) */
void _gleInsertPixel_L_Int(pixel, dst)
  int pixel;
  int *dst;
{
  *dst = (int)((double)*(float *)(pixel + 4) * DOUBLE_00108d90);
  return;
}

/* _gleInsertPixel_L_Uint @ 0xea430 (96 bytes) */
void _gleInsertPixel_L_Uint(pixel, dst)
  int pixel;
  uint *dst;
{
  uint channelValue;
  double scaledChannel;
  
  scaledChannel = (double)*(float *)(pixel + 4) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  *dst = channelValue;
  return;
}

/* _gleInsertPixel_L_Float @ 0xea490 (12 bytes) */
void _gleInsertPixel_L_Float(pixel, dst)
  int pixel;
  undefined4 *dst;
{
  *dst = *(undefined4 *)(pixel + 4);
  return;
}

/* _gleInsertPixel_LA_Byte @ 0xea49c (76 bytes) */
void _gleInsertPixel_LA_Byte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f6c;
  *dst = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f6c);
  dst[1] = (char)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_LA_Ubyte @ 0xea4e8 (76 bytes) */
void _gleInsertPixel_LA_Ubyte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f70;
  *dst = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f70);
  dst[1] = (char)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_LA_Short @ 0xea534 (76 bytes) */
void _gleInsertPixel_LA_Short(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f74;
  *dst = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108f74);
  dst[1] = (short)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_LA_Ushort @ 0xea580 (76 bytes) */
void _gleInsertPixel_LA_Ushort(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108ea0;
  *dst = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0);
  dst[1] = (short)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_LA_Int @ 0xea5cc (76 bytes) */
void _gleInsertPixel_LA_Int(pixel, dst)
  int pixel;
  int *dst;
{
  double scaledChannel;
  
  scaledChannel = DOUBLE_00108d90;
  *dst = (int)((double)*(float *)(pixel + 4) * DOUBLE_00108d90);
  dst[1] = (int)((double)*(float *)(pixel + 0x10) * scaledChannel);
  return;
}

/* _gleInsertPixel_LA_Uint @ 0xea618 (168 bytes) */
void _gleInsertPixel_LA_Uint(pixel, dst)
  int pixel;
  uint *dst;
{
  uint channelValue;
  double scaledChannel;
  
  scaledChannel = (double)*(float *)(pixel + 4) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  *dst = channelValue;
  scaledChannel = (double)*(float *)(pixel + 0x10) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  dst[1] = channelValue;
  return;
}

/* _gleInsertPixel_LA_Float @ 0xea6c0 (20 bytes) */
void _gleInsertPixel_LA_Float(pixel, dst)
  int pixel;
  undefined4 *dst;
{
  *dst = *(undefined4 *)(pixel + 4);
  dst[1] = *(undefined4 *)(pixel + 0x10);
  return;
}

/* _gleInsertPixel_Index_Byte @ 0xea6d4 (12 bytes) */
void _gleInsertPixel_Index_Byte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  *dst = *(undefined1 *)(pixel + 0x1b);
  return;
}

/* _gleInsertPixel_Index_Ubyte @ 0xea6e0 (12 bytes) */
void _gleInsertPixel_Index_Ubyte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  *dst = *(undefined1 *)(pixel + 0x1b);
  return;
}

/* _gleInsertPixel_Index_Short @ 0xea6ec (12 bytes) */
void _gleInsertPixel_Index_Short(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  *dst = *(undefined2 *)(pixel + 0x1a);
  return;
}

/* _gleInsertPixel_Index_Ushort @ 0xea6f8 (12 bytes) */
void _gleInsertPixel_Index_Ushort(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  *dst = *(undefined2 *)(pixel + 0x1a);
  return;
}

/* _gleInsertPixel_Index_Int @ 0xea704 (12 bytes) */
void _gleInsertPixel_Index_Int(pixel, dst)
  int pixel;
  undefined4 *dst;
{
  *dst = *(undefined4 *)(pixel + 0x18);
  return;
}

/* _gleInsertPixel_Index_Uint @ 0xea710 (12 bytes) */
void _gleInsertPixel_Index_Uint(pixel, dst)
  int pixel;
  undefined4 *dst;
{
  *dst = *(undefined4 *)(pixel + 0x18);
  return;
}

/* _gleInsertPixel_Index_Float @ 0xea71c (104 bytes) */
void _gleInsertPixel_Index_Float(pixel, dst)
  int pixel;
  float *dst;
{
  *dst = (float)((double)CONCAT44(0x43300000,*(uint *)(pixel + 0x1c) ^ 0x80000000) -
                    DOUBLE_00108d58) * FLOAT_00108f78 +
             (float)((double)CONCAT44(0x43300000,*(uint *)(pixel + 0x18) ^ 0x80000000) -
                    DOUBLE_00108d58);
  return;
}

/* _gleInsertPixel_Depth_Byte @ 0xea784 (52 bytes) */
void _gleInsertPixel_Depth_Byte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  *dst = (char)(int)(*(float *)(pixel + 0x14) * FLOAT_00108f6c);
  return;
}

/* _gleInsertPixel_Depth_Ubyte @ 0xea7b8 (52 bytes) */
void _gleInsertPixel_Depth_Ubyte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  *dst = (char)(int)(*(float *)(pixel + 0x14) * FLOAT_00108f70);
  return;
}

/* _gleInsertPixel_Depth_Short @ 0xea7ec (52 bytes) */
void _gleInsertPixel_Depth_Short(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  *dst = (short)(int)(*(float *)(pixel + 0x14) * FLOAT_00108f74);
  return;
}

/* _gleInsertPixel_Depth_Ushort @ 0xea820 (52 bytes) */
void _gleInsertPixel_Depth_Ushort(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  *dst = (short)(int)(*(float *)(pixel + 0x14) * FLOAT_00108ea0);
  return;
}

/* _gleInsertPixel_Depth_Int @ 0xea854 (52 bytes) */
void _gleInsertPixel_Depth_Int(pixel, dst)
  int pixel;
  int *dst;
{
  *dst = (int)((double)*(float *)(pixel + 0x14) * DOUBLE_00108d90);
  return;
}

/* _gleInsertPixel_Depth_Uint @ 0xea888 (96 bytes) */
void _gleInsertPixel_Depth_Uint(pixel, dst)
  int pixel;
  uint *dst;
{
  uint channelValue;
  double scaledChannel;
  
  scaledChannel = (double)*(float *)(pixel + 0x14) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  *dst = channelValue;
  return;
}

/* _gleInsertPixel_Depth_Float @ 0xea8e8 (12 bytes) */
void _gleInsertPixel_Depth_Float(pixel, dst)
  int pixel;
  undefined4 *dst;
{
  *dst = *(undefined4 *)(pixel + 0x14);
  return;
}

/* _gleBeginPointsRender @ 0xea8f4 (52 bytes) */
void _gleBeginPointsRender(glContext)
  int glContext;
{
  undefined *flushAtomicFunc;
  
  flushAtomicFunc = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushAtomicFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderPointsFunc_00112240;
  return;
}

/* _gleBeginPointsRenderTCL @ 0xea928 (52 bytes) */
void _gleBeginPointsRenderTCL(glContext)
  int glContext;
{
  undefined *flushAtomicTCLFunc;
  
  flushAtomicTCLFunc = PTR__gleFlushAtomicTCLFunc_00112218;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushAtomicTCLFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderPointsTCLFunc_0011223c;
  return;
}

/* _gleBeginPointsRenderTCLRDirty @ 0xea95c (60 bytes) */
void _gleBeginPointsRenderTCLRDirty(glContext)
  int glContext;
{
  undefined *flushAtomicTCLRDirtyFunc;
  undefined *renderPointsTCLFunc;
  
  renderPointsTCLFunc = PTR__gleRenderPointsTCLFunc_0011223c;
  flushAtomicTCLRDirtyFunc = PTR__gleFlushAtomicTCLRDirtyFunc_00112210;
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = flushAtomicTCLRDirtyFunc;
  *(undefined **)(glContext + 0x4a08) = renderPointsTCLFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginPointsSelectFeedback @ 0xea998 (76 bytes) */
void _gleBeginPointsSelectFeedback(glContext)
  int glContext;
{
  undefined *puVar1;
  
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushAtomicFunc_00112224;
  puVar1 = PTR__gleFeedbackPointsFunc_00112234;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectPointsFunc_00112238;
  }
  *(undefined **)(glContext + 0x4a08) = puVar1;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleClipPoints @ 0xea9e4 (76 bytes) */
int _gleClipPoints(unusedArg1, vertexCursor, vertexCount, pointList)
  undefined4 unusedArg1;
  uint vertexCursor;
  int vertexCount;
  uint *pointList;
{
  uint vertexEndThenRemaining;
  uint *listCursor;
  
  vertexEndThenRemaining = vertexCursor + vertexCount * 0x100;
  listCursor = pointList;
  if (vertexCursor < vertexEndThenRemaining) {
    vertexEndThenRemaining = (vertexEndThenRemaining - vertexCursor) + 0xff >> 8;
    do {
      if (*(char *)(vertexCursor + 0x7f) == '\0') {
        *listCursor = vertexCursor;
        listCursor = listCursor + 1;
      }
      vertexCursor = vertexCursor + 0x100;
      vertexEndThenRemaining = vertexEndThenRemaining - 1;
    } while (vertexEndThenRemaining != 0);
  }
  return (int)listCursor - (int)pointList >> 2;
}

/* _gleClipPointsPlane @ 0xeaa30 (244 bytes) */
int _gleClipPointsPlane(glContext, points, pointCount)
  int glContext;
  int *points;
  int pointCount;
{
  float planeA;
  float planeD;
  float planeB;
  float planeC;
  float zero;
  int planeRecord;
  int point;
  int planeLoopIndex;
  int *planeIndexCursor;
  int *keepCursor;
  int *readCursor;
  int planeCount;
  uint remaining;
  
  zero = FLOAT_00108e50;
  planeLoopIndex = 0;
  planeCount = *(int *)(glContext + 0x4dfc);
  if ((0 < planeCount) && (0 < pointCount)) {
    planeIndexCursor = (int *)(glContext + 0x4e00);
    do {
      planeRecord = *planeIndexCursor;
      planeIndexCursor = planeIndexCursor + 1;
      planeRecord = glContext + planeRecord * 0x10;
      planeA = *(float *)(planeRecord + 0x418c);
      planeD = *(float *)(planeRecord + 0x4198);
      planeB = *(float *)(planeRecord + 0x4190);
      planeC = *(float *)(planeRecord + 0x4194);
      keepCursor = points;
      if (points < points + pointCount) {
        remaining = (uint)((int)(points + pointCount) + (3 - (int)points)) >> 2;
        readCursor = points;
        do {
          point = *readCursor;
          if (zero <= *(float *)(point + 0x2c) * planeD +
                       (*(float *)(point + 0x28) * planeC +
                       (*(float *)(point + 0x20) * planeA + *(float *)(point + 0x24) * planeB))) {
            *keepCursor = point;
            keepCursor = keepCursor + 1;
          }
          readCursor = readCursor + 1;
          remaining = remaining - 1;
        } while (remaining != 0);
      }
      planeLoopIndex = planeLoopIndex + 1;
      pointCount = (int)keepCursor - (int)points >> 2;
    } while ((planeLoopIndex < planeCount) && (0 < pointCount));
  }
  return pointCount;
}

/* _gleFeedbackPointsFunc_body @ 0xeab28 (700 bytes) */
void _gleFeedbackPointsFunc_body(glContext, unusedArg2, unusedArg3)
  int glContext;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
{
  bool fixedFunctionPath;
  uint batchClipCodes;
  int pointCount;
  undefined4 *pointListCursor;
  undefined4 *pointListEnd;
  uint vertexCursor;
  uint vertexCountThenEnd;
  
  fixedFunctionPath = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    fixedFunctionPath = true;
  }
  vertexCursor = *(uint *)(glContext + 0x4854);
  if (((int)*(short *)(glContext + 0x487c) != 0) &&
     (vertexCountThenEnd = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
     0 < (int)vertexCountThenEnd)) {
    fixedFunctionPath = !fixedFunctionPath;
    if (fixedFunctionPath) {
      batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCountThenEnd);
    }
    else {
      batchClipCodes = _gleVPEmulate(glContext,vertexCountThenEnd);
    }
    if ((batchClipCodes & 0xff00) == 0) {
      if (fixedFunctionPath) {
        if (*(char *)(glContext + 0x53e4) != '\0') {
          (**(code **)(glContext + 0x53dc))(glContext,vertexCursor,vertexCountThenEnd);
        }
        if (*(char *)(glContext + 0x50b4) != '\0') {
          (**(code **)(glContext + 0x5064))(glContext,vertexCursor,vertexCountThenEnd);
        }
        if ((*(char *)(glContext + 0x30aa) != '\0') || (*(char *)(glContext + 0x53e6) != '\0')) {
          (**(code **)(glContext + 0x5068))(glContext,vertexCursor,vertexCountThenEnd);
        }
      }
      else {
        vertexCursor = *(uint *)(glContext + 0x4864);
      }
      if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        if ((fixedFunctionPath) && (*(char *)(glContext + 0x53e5) != '\0')) {
          (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,vertexCountThenEnd);
        }
        (**(code **)(glContext + 0x506c))(glContext,vertexCursor,vertexCountThenEnd,0);
        if ((fixedFunctionPath) && (*(char *)(glContext + 0x30aa) != '\0')) {
          (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,vertexCountThenEnd);
        }
        vertexCountThenEnd = vertexCursor + vertexCountThenEnd * 0x100;
        for (; vertexCursor < vertexCountThenEnd; vertexCursor = vertexCursor + 0x100) {
          ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f28);
          _gleFeedbackHitRecord(glContext,vertexCursor);
        }
        return;
      }
      if ((fixedFunctionPath) && (*(char *)(glContext + 0x53e5) != '\0')) {
        (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,vertexCountThenEnd);
      }
      (**(code **)(glContext + 0x5074))(glContext,vertexCursor,vertexCountThenEnd,0);
      pointListCursor = *(undefined4 **)(glContext + 0x4870);
      pointCount = ((int (*)())_gleClipPoints)(glContext,vertexCursor,vertexCountThenEnd,pointListCursor);
      if ((pointCount != 0) &&
         ((*(char *)(glContext + 0x4e18) == '\0' ||
          (pointCount = ((int (*)())_gleClipPointsPlane)(glContext,pointListCursor,pointCount), pointCount != 0)))) {
        if ((fixedFunctionPath) && (*(char *)(glContext + 0x30aa) != '\0')) {
          (**(code **)(glContext + 0x4df0))(glContext,pointListCursor,pointCount);
        }
        pointListEnd = pointListCursor + pointCount;
        for (; pointListCursor < pointListEnd; pointListCursor = pointListCursor + 1) {
          ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f28);
          _gleFeedbackHitRecord(glContext,*pointListCursor);
        }
        return;
      }
    }
  }
  return;
}

/* _gleRenderPointsFunc_body @ 0xeae0c (620 bytes) */
void _gleRenderPointsFunc_body(glContext)
  int glContext;
{
  bool texturingEnabled;
  int renderPoints;
  int texEnableBits;
  uint batchClipCodes;
  undefined4 rendererHandle;
  code *UNRECOVERED_JUMPTABLE;
  int vertexCursor;
  int pointCount;
  
  texEnableBits = _gleTexEnableBits(glContext);
  vertexCursor = *(int *)(glContext + 0x4854);
  pointCount = *(int *)(glContext + 0x4858) - vertexCursor >> 8;
  if ((pointCount < 1) ||
     (batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,pointCount), (batchClipCodes & 0xff00) != 0)) {
    return;
  }
  texturingEnabled = texEnableBits != 0;
  if ((texturingEnabled) && (*(char *)(glContext + 0x53e4) != '\0')) {
    (**(code **)(glContext + 0x53dc))(glContext,vertexCursor,pointCount);
  }
  if (*(char *)(glContext + 0x50b4) != '\0') {
    (**(code **)(glContext + 0x5064))(glContext,vertexCursor,pointCount);
  }
  if ((*(char *)(glContext + 0x30aa) != '\0') || (*(char *)(glContext + 0x53e6) != '\0')) {
    (**(code **)(glContext + 0x5068))(glContext,vertexCursor,pointCount);
  }
  if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,pointCount);
      }
      (**(code **)(glContext + 0x506c))(glContext,vertexCursor,pointCount,0);
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,pointCount);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b0);
    rendererHandle = *(undefined4 *)(glContext + 0x4688);
    renderPoints = vertexCursor;
  }
  else {
    if (texturingEnabled) {
      if (*(char *)(glContext + 0x53e5) != '\0') {
        (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,pointCount);
      }
      (**(code **)(glContext + 0x5074))(glContext,vertexCursor,pointCount,0);
    }
    renderPoints = *(int *)(glContext + 0x4870);
    pointCount = ((int (*)())_gleClipPoints)(glContext,vertexCursor,pointCount,renderPoints);
    if (pointCount == 0) {
      return;
    }
    if ((*(char *)(glContext + 0x4e18) != '\0') &&
       (pointCount = ((int (*)())_gleClipPointsPlane)(glContext,renderPoints,pointCount), pointCount == 0)) {
      return;
    }
    if (*(char *)(glContext + 0x30aa) != '\0') {
      (**(code **)(glContext + 0x4df0))(glContext,renderPoints,pointCount);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46d8);
    rendererHandle = *(undefined4 *)(glContext + 0x4688);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(rendererHandle,renderPoints,pointCount);
  return;
}

/* _gleSelectPointsFunc @ 0xeb078 (352 bytes) */
void _gleSelectPointsFunc(glContext)
  int glContext;
{
  bool vertexProgramPath;
  uint batchClipCodes;
  undefined4 pointList;
  int vertexCursorThenPointCount;
  uint vertexCount;
  
  vertexProgramPath = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    vertexProgramPath = true;
  }
  vertexCursorThenPointCount = *(int *)(glContext + 0x4854);
  if (((int)*(short *)(glContext + 0x487c) != 0) &&
     (vertexCount = (uint)(*(int *)(glContext + 0x4858) - vertexCursorThenPointCount) / (uint)(int)*(short *)(glContext + 0x487c),
     0 < (int)vertexCount)) {
    batchClipCodes = (**(code **)(glContext + 0x5060))(glContext,vertexCursorThenPointCount,vertexCount);
    if ((batchClipCodes & 0xff00) == 0) {
      if (vertexProgramPath) {
        vertexCursorThenPointCount = *(int *)(glContext + 0x4864);
      }
      else if (*(char *)(glContext + 0x4e18) != '\0') {
        (**(code **)(glContext + 0x5064))(glContext,vertexCursorThenPointCount,vertexCount);
      }
      if (((batchClipCodes & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        _gleSelectPoints(glContext,vertexCursorThenPointCount,vertexCount);
        return;
      }
      pointList = *(undefined4 *)(glContext + 0x4870);
      vertexCursorThenPointCount = ((int (*)())_gleClipPoints)(glContext,vertexCursorThenPointCount,vertexCount,pointList);
      if ((vertexCursorThenPointCount != 0) &&
         ((*(char *)(glContext + 0x4e18) == '\0' ||
          (vertexCursorThenPointCount = ((int (*)())_gleClipPointsPlane)(glContext,pointList,vertexCursorThenPointCount), vertexCursorThenPointCount != 0)))) {
        _gleSelectPointsPtr(glContext,pointList,vertexCursorThenPointCount);
        return;
      }
    }
  }
  return;
}

/* _glePolyArea @ 0xeb1d8 (128 bytes) */
double _glePolyArea(undefined4 unusedArg1,float *vertices,int vertexCount,undefined4 unusedArg4,undefined4 unusedArg5,undefined4 unusedArg6,undefined4 unusedArg7,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  float firstX;
  float firstY;
  float lastX;
  float lastY;
  float previousY;
  float previousX;
  float doubledArea;
  float *vertexCursor;
  uint iterationsLeft;
  
  vertexCursor = vertices + 0x40;
  firstX = *vertices;
  firstY = vertices[1];
  lastY = firstY;
  lastX = firstX;
  doubledArea = FLOAT_00108e50;
  if (vertexCursor < vertices + vertexCount * 0x40) {
    iterationsLeft = (uint)((int)(vertices + vertexCount * 0x40) + (0xff - (int)vertexCursor)) >> 8;
    previousY = firstY;
    previousX = firstX;
    do {
      lastX = *vertexCursor;
      lastY = vertexCursor[1];
      vertexCursor = vertexCursor + 0x40;
      doubledArea = doubledArea + ((previousX * lastY - lastX * previousY));
      iterationsLeft = iterationsLeft - 1;
      previousY = lastY;
      previousX = lastX;
    } while (iterationsLeft != 0);
  }
  return (double)(doubledArea + ((lastX * firstY - firstX * lastY)));
}

/* _glePolyAreaPtr @ 0xeb258 (136 bytes) */
double _glePolyAreaPtr(undefined4 unusedArg1,undefined4 *vertexPtrs,int vertexCount,undefined4 unusedArg4,undefined4 unusedArg5,undefined4 unusedArg6,undefined4 unusedArg7)
{
  float lastPointX;
  float lastPointY;
  float areaSum;
  float previousPointX;
  float previousPointY;
  float *currentPoint;
  float *firstPoint;
  undefined4 *nextVertexSlot;
  uint verticesLeft;
  
  nextVertexSlot = vertexPtrs + 1;
  firstPoint = (float *)*vertexPtrs;
  lastPointX = *firstPoint;
  lastPointY = firstPoint[1];
  areaSum = FLOAT_00108e50;
  if (nextVertexSlot < vertexPtrs + vertexCount) {
    verticesLeft = (uint)((int)(vertexPtrs + vertexCount) + (3 - (int)nextVertexSlot)) >> 2;
    previousPointX = lastPointX;
    previousPointY = lastPointY;
    do {
      currentPoint = (float *)*nextVertexSlot;
      nextVertexSlot = nextVertexSlot + 1;
      lastPointX = *currentPoint;
      lastPointY = currentPoint[1];
      areaSum = areaSum + ((previousPointX * lastPointY - lastPointX * previousPointY));
      verticesLeft = verticesLeft - 1;
      previousPointX = lastPointX;
      previousPointY = lastPointY;
    } while (verticesLeft != 0);
  }
  return (double)(areaSum + ((lastPointX * firstPoint[1] - *firstPoint * lastPointY)));
}

/* _gleBeginTrianglesRenderSmooth @ 0xeb2e0 (52 bytes) */
void _gleBeginTrianglesRenderSmooth(glContext)
  int glContext;
{
  undefined *flushAtomicFunc;
  
  flushAtomicFunc = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushAtomicFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderSmoothTrianglesFunc_001122dc;
  return;
}

/* _gleBeginTrianglesRenderFlat @ 0xeb314 (52 bytes) */
void _gleBeginTrianglesRenderFlat(glContext)
  int glContext;
{
  undefined *flushAtomicFunc;
  
  flushAtomicFunc = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushAtomicFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderFlatTrianglesFunc_001122d8;
  return;
}

/* _gleBeginTrianglesRenderTCL @ 0xeb348 (52 bytes) */
void _gleBeginTrianglesRenderTCL(glContext)
  int glContext;
{
  undefined *flushAtomicTCLFunc;
  
  flushAtomicTCLFunc = PTR__gleFlushAtomicTCLFunc_00112218;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushAtomicTCLFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderTrianglesTCLFunc_001122d4;
  return;
}

/* _gleBeginTrianglesRenderTCLRDirty @ 0xeb37c (60 bytes) */
void _gleBeginTrianglesRenderTCLRDirty(glContext)
  int glContext;
{
  undefined *flushAtomicTCLRDirtyFunc;
  undefined *renderTrianglesTCLFunc;
  
  renderTrianglesTCLFunc = PTR__gleRenderTrianglesTCLFunc_001122d4;
  flushAtomicTCLRDirtyFunc = PTR__gleFlushAtomicTCLRDirtyFunc_00112210;
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = flushAtomicTCLRDirtyFunc;
  *(undefined **)(glContext + 0x4a08) = renderTrianglesTCLFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginTrianglesSelectFeedback @ 0xeb3b8 (76 bytes) */
void _gleBeginTrianglesSelectFeedback(glContext)
  int glContext;
{
  undefined *puVar1;
  
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushAtomicFunc_00112224;
  puVar1 = PTR__gleFeedbackTrianglesFunc_001122cc;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectTrianglesFunc_001122d0;
  }
  *(undefined **)(glContext + 0x4a08) = puVar1;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginTriangleStripRenderSmooth @ 0xeb404 (52 bytes) */
void _gleBeginTriangleStripRenderSmooth(glContext)
  int glContext;
{
  undefined *flushTriQuadStripFunc;
  
  flushTriQuadStripFunc = PTR__gleFlushTriQuadStripFunc_001122c8;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushTriQuadStripFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderSmoothTriangleStripFunc_001122c4;
  return;
}

/* _gleBeginTriangleStripRenderFlat @ 0xeb438 (52 bytes) */
void _gleBeginTriangleStripRenderFlat(glContext)
  int glContext;
{
  undefined *flushTriQuadStripFunc;
  
  flushTriQuadStripFunc = PTR__gleFlushTriQuadStripFunc_001122c8;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushTriQuadStripFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderFlatTriangleStripFunc_001122c0;
  return;
}

/* _gleBeginTriangleStripRenderTCL @ 0xeb46c (52 bytes) */
void _gleBeginTriangleStripRenderTCL(glContext)
  int glContext;
{
  undefined *flushTriQuadStripTCLFunc;
  
  flushTriQuadStripTCLFunc = PTR__gleFlushTriQuadStripTCLFunc_001122bc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushTriQuadStripTCLFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderTriangleStripTCLFunc_001122b8;
  return;
}

/* _gleBeginTriangleStripRenderTCLRDirty @ 0xeb4a0 (60 bytes) */
void _gleBeginTriangleStripRenderTCLRDirty(glContext)
  int glContext;
{
  undefined *flushTriQuadStripTCLRDirtyFunc;
  undefined *renderTriangleStripTCLFunc;
  
  renderTriangleStripTCLFunc = PTR__gleRenderTriangleStripTCLFunc_001122b8;
  flushTriQuadStripTCLRDirtyFunc = PTR__gleFlushTriQuadStripTCLRDirtyFunc_001122b4;
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = flushTriQuadStripTCLRDirtyFunc;
  *(undefined **)(glContext + 0x4a08) = renderTriangleStripTCLFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginTriangleStripSelectFeedback @ 0xeb4dc (76 bytes) */
void _gleBeginTriangleStripSelectFeedback(glContext)
  int glContext;
{
  undefined *renderFunc;
  
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushTriQuadStripFunc_001122c8;
  renderFunc = PTR__gleFeedbackTriangleStripFunc_001122ac;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    renderFunc = PTR__gleSelectTriangleStripFunc_001122b0;
  }
  *(undefined **)(glContext + 0x4a08) = renderFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginTriangleFanRenderSmooth @ 0xeb528 (52 bytes) */
void _gleBeginTriangleFanRenderSmooth(glContext)
  int glContext;
{
  undefined *flushTriangleFanFunc;
  
  flushTriangleFanFunc = PTR__gleFlushTriangleFanFunc_001122a8;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushTriangleFanFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderSmoothTriangleFanFunc_001122a4;
  return;
}

/* _gleBeginTriangleFanRenderFlat @ 0xeb55c (52 bytes) */
void _gleBeginTriangleFanRenderFlat(glContext)
  int glContext;
{
  undefined *flushTriangleFanFunc;
  
  flushTriangleFanFunc = PTR__gleFlushTriangleFanFunc_001122a8;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushTriangleFanFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderFlatTriangleFanFunc_001122a0;
  return;
}

/* _gleBeginTriangleFanRenderTCL @ 0xeb590 (52 bytes) */
void _gleBeginTriangleFanRenderTCL(glContext)
  int glContext;
{
  undefined *flushTriangleFanTCLFunc;
  
  flushTriangleFanTCLFunc = PTR__gleFlushTriangleFanTCLFunc_0011229c;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushTriangleFanTCLFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderTriangleFanTCLFunc_00112298;
  return;
}

/* _gleBeginTriangleFanRenderTCLRDirty @ 0xeb5c4 (60 bytes) */
void _gleBeginTriangleFanRenderTCLRDirty(glContext)
  int glContext;
{
  undefined *flushTriangleFanTCLRDirtyFunc;
  undefined *renderTriangleFanTCLFunc;
  
  renderTriangleFanTCLFunc = PTR__gleRenderTriangleFanTCLFunc_00112298;
  flushTriangleFanTCLRDirtyFunc = PTR__gleFlushTriangleFanTCLRDirtyFunc_00112294;
  *(undefined4 *)(glContext + 0x486c) = 0;
  *(undefined **)(glContext + 0x4a0c) = flushTriangleFanTCLRDirtyFunc;
  *(undefined **)(glContext + 0x4a08) = renderTriangleFanTCLFunc;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginTriangleFanSelectFeedback @ 0xeb600 (76 bytes) */
void _gleBeginTriangleFanSelectFeedback(glContext)
  int glContext;
{
  undefined *puVar1;
  
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushTriangleFanFunc_001122a8;
  puVar1 = PTR__gleFeedbackTriangleFanFunc_0011228c;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectTriangleFanFunc_00112290;
  }
  *(undefined **)(glContext + 0x4a08) = puVar1;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleBeginQuadsRenderSmooth @ 0xeb64c (52 bytes) */
void _gleBeginQuadsRenderSmooth(glContext)
  int glContext;
{
  undefined *flushAtomicFunc;
  
  flushAtomicFunc = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushAtomicFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderSmoothQuadsFunc_00112288;
  return;
}

