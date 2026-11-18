#include "decls.h"

/* _gleMap1Vertex4dLoad @ 0xde520 (156 bytes) */
void _gleMap1Vertex4dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int stride,int order,int points,int *mapData,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
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
      mapData[7] = (int)GH_F2U((float)*(double *)(pointAddr + 0x18));
      mapData = mapData + 4;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1ColordLoad @ 0xde5bc (156 bytes) */
void _gleMap1ColordLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int stride,int order,int points,int *mapData,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
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
      mapData[7] = (int)GH_F2U((float)*(double *)(pointAddr + 0x18));
      mapData = mapData + 4;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1IndexdLoad @ 0xde658 (112 bytes) */
void _gleMap1IndexdLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int stride,int order,double *points,int *mapData,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float *destPtr;
  double dVar2;
  
  dVar2 = DOUBLE_00108d68 / (u2 - u1);
  mapData[1] = (int)GH_F2U((float)u1);
  *mapData = order;
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((float)dVar2);
  if (order < 1) {
    return;
  }
  destPtr = (float *)(mapData + 4);
  do {
    dVar2 = *points;
    points = points + stride;
    *destPtr = (float)dVar2;
    destPtr = destPtr + 1;
    order = order + -1;
  } while (order != 0);
  return;
}

/* _gleMap1NormaldLoad @ 0xde6c8 (144 bytes) */
void _gleMap1NormaldLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int stride,int order,int points,int *mapData,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
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

/* _gleMap1Texture1dLoad @ 0xde758 (112 bytes) */
void _gleMap1Texture1dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int stride,int order,double *points,int *mapData,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float *destPtr;
  double dVar2;
  
  dVar2 = DOUBLE_00108d68 / (u2 - u1);
  mapData[1] = (int)GH_F2U((float)u1);
  *mapData = order;
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((float)dVar2);
  if (order < 1) {
    return;
  }
  destPtr = (float *)(mapData + 4);
  do {
    dVar2 = *points;
    points = points + stride;
    *destPtr = (float)dVar2;
    destPtr = destPtr + 1;
    order = order + -1;
  } while (order != 0);
  return;
}

/* _gleMap1Texture2dLoad @ 0xde7c8 (120 bytes) */
void _gleMap1Texture2dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int stride,int order,double *points,int *mapData,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double *secondComponentPtr;
  double invUDelta;
  
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  mapData[1] = (int)GH_F2U((float)u1);
  *mapData = order;
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((float)invUDelta);
  if (0 < order) {
    do {
      mapData[4] = (int)GH_F2U((float)*points);
      secondComponentPtr = points + 1;
      points = points + stride;
      mapData[5] = (int)GH_F2U((float)*secondComponentPtr);
      mapData = mapData + 2;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1Texture3dLoad @ 0xde840 (144 bytes) */
void _gleMap1Texture3dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int stride,int order,int points,int *mapData,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
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

/* _gleMap1Texture4dLoad @ 0xde8d0 (156 bytes) */
void _gleMap1Texture4dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int stride,int order,int points,int *mapData,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
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
      mapData[7] = (int)GH_F2U((float)*(double *)(pointAddr + 0x18));
      mapData = mapData + 4;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1VertexAttrib1dLoad @ 0xde96c (112 bytes) */
void _gleMap1VertexAttrib1dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int stride,int order,double *points,int *mapData,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float *destPtr;
  double dVar2;
  
  dVar2 = DOUBLE_00108d68 / (u2 - u1);
  mapData[1] = (int)GH_F2U((float)u1);
  *mapData = order;
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((float)dVar2);
  if (order < 1) {
    return;
  }
  destPtr = (float *)(mapData + 4);
  do {
    dVar2 = *points;
    points = points + stride;
    *destPtr = (float)dVar2;
    destPtr = destPtr + 1;
    order = order + -1;
  } while (order != 0);
  return;
}

/* _gleMap1VertexAttrib2dLoad @ 0xde9dc (120 bytes) */
void _gleMap1VertexAttrib2dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int stride,int order,double *points,int *mapData,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double *secondComponentPtr;
  double invUDelta;
  
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  mapData[1] = (int)GH_F2U((float)u1);
  *mapData = order;
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((float)invUDelta);
  if (0 < order) {
    do {
      mapData[4] = (int)GH_F2U((float)*points);
      secondComponentPtr = points + 1;
      points = points + stride;
      mapData[5] = (int)GH_F2U((float)*secondComponentPtr);
      mapData = mapData + 2;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1VertexAttrib3dLoad @ 0xdea54 (144 bytes) */
void _gleMap1VertexAttrib3dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int stride,int order,int points,int *mapData,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
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

/* _gleMap1VertexAttrib4dLoad @ 0xdeae4 (156 bytes) */
void _gleMap1VertexAttrib4dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int stride,int order,int points,int *mapData,double u1,double u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
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
      mapData[7] = (int)GH_F2U((float)*(double *)(pointAddr + 0x18));
      mapData = mapData + 4;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1Vertex3fLoad @ 0xdeb80 (112 bytes) */
int _gleMap1Vertex3fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int stride,int order,int points,int *mapData,float u1,float u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int pointByteOffset;
  float one;
  int pointElementOffset;
  int pointAddr;
  
  one = FLOAT_00108e54;
  pointElementOffset = 0;
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((one / (u2 - u1)));
  if (0 < order) {
    do {
      pointByteOffset = pointElementOffset * 4;
      pointElementOffset = pointElementOffset + stride;
      pointAddr = pointByteOffset + points;
      mapData[4] = *(int *)(pointByteOffset + points);
      mapData[5] = *(int *)(pointAddr + 4);
      mapData[6] = *(int *)(pointAddr + 8);
      mapData = mapData + 3;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1Vertex4fLoad @ 0xdebf0 (120 bytes) */
int _gleMap1Vertex4fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int stride,int order,int points,int *mapData,float u1,float u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int pointByteOffset;
  float one;
  int pointElementOffset;
  int pointAddr;
  
  one = FLOAT_00108e54;
  pointElementOffset = 0;
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((one / (u2 - u1)));
  if (0 < order) {
    do {
      pointByteOffset = pointElementOffset * 4;
      pointElementOffset = pointElementOffset + stride;
      pointAddr = pointByteOffset + points;
      mapData[4] = *(int *)(pointByteOffset + points);
      mapData[5] = *(int *)(pointAddr + 4);
      mapData[6] = *(int *)(pointAddr + 8);
      mapData[7] = *(int *)(pointAddr + 0xc);
      mapData = mapData + 4;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1ColorfLoad @ 0xdec68 (120 bytes) */
int _gleMap1ColorfLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int stride,int order,int points,int *mapData,float u1,float u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int pointByteOffset;
  float one;
  int pointElementOffset;
  int pointAddr;
  
  one = FLOAT_00108e54;
  pointElementOffset = 0;
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((one / (u2 - u1)));
  if (0 < order) {
    do {
      pointByteOffset = pointElementOffset * 4;
      pointElementOffset = pointElementOffset + stride;
      pointAddr = pointByteOffset + points;
      mapData[4] = *(int *)(pointByteOffset + points);
      mapData[5] = *(int *)(pointAddr + 4);
      mapData[6] = *(int *)(pointAddr + 8);
      mapData[7] = *(int *)(pointAddr + 0xc);
      mapData = mapData + 4;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1IndexfLoad @ 0xdece0 (92 bytes) */
int _gleMap1IndexfLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int stride,int order,int *points,int *mapData,float u1,float u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int pointValue;
  float one;
  int *destPtr;
  
  one = FLOAT_00108e54;
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((one / (u2 - u1)));
  if (order < 1) {
    return;
  }
  destPtr = mapData + 4;
  do {
    pointValue = *points;
    points = points + stride;
    *destPtr = pointValue;
    destPtr = destPtr + 1;
    order = order + -1;
  } while (order != 0);
  return;
}

/* _gleMap1NormalfLoad @ 0xded3c (112 bytes) */
int _gleMap1NormalfLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int stride,int order,int points,int *mapData,float u1,float u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int pointByteOffset;
  float one;
  int pointElementOffset;
  int pointAddr;
  
  one = FLOAT_00108e54;
  pointElementOffset = 0;
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((one / (u2 - u1)));
  if (0 < order) {
    do {
      pointByteOffset = pointElementOffset * 4;
      pointElementOffset = pointElementOffset + stride;
      pointAddr = pointByteOffset + points;
      mapData[4] = *(int *)(pointByteOffset + points);
      mapData[5] = *(int *)(pointAddr + 4);
      mapData[6] = *(int *)(pointAddr + 8);
      mapData = mapData + 3;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1Texture1fLoad @ 0xdedac (92 bytes) */
int _gleMap1Texture1fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int stride,int order,int *points,int *mapData,float u1,float u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int pointValue;
  float one;
  int *destPtr;
  
  one = FLOAT_00108e54;
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((one / (u2 - u1)));
  if (order < 1) {
    return;
  }
  destPtr = mapData + 4;
  do {
    pointValue = *points;
    points = points + stride;
    *destPtr = pointValue;
    destPtr = destPtr + 1;
    order = order + -1;
  } while (order != 0);
  return;
}

/* _gleMap1Texture2fLoad @ 0xdee08 (96 bytes) */
int _gleMap1Texture2fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int stride,int order,int *points,int *mapData,float u1,float u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int *secondComponentPtr;
  float one;
  
  one = FLOAT_00108e54;
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((one / (u2 - u1)));
  if (0 < order) {
    do {
      mapData[4] = *points;
      secondComponentPtr = points + 1;
      points = points + stride;
      mapData[5] = *secondComponentPtr;
      mapData = mapData + 2;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1Texture3fLoad @ 0xdee68 (112 bytes) */
int _gleMap1Texture3fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int stride,int order,int points,int *mapData,float u1,float u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int pointByteOffset;
  float one;
  int pointElementOffset;
  int pointAddr;
  
  one = FLOAT_00108e54;
  pointElementOffset = 0;
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((one / (u2 - u1)));
  if (0 < order) {
    do {
      pointByteOffset = pointElementOffset * 4;
      pointElementOffset = pointElementOffset + stride;
      pointAddr = pointByteOffset + points;
      mapData[4] = *(int *)(pointByteOffset + points);
      mapData[5] = *(int *)(pointAddr + 4);
      mapData[6] = *(int *)(pointAddr + 8);
      mapData = mapData + 3;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1Texture4fLoad @ 0xdeed8 (120 bytes) */
int _gleMap1Texture4fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int stride,int order,int points,int *mapData,float u1,float u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int pointByteOffset;
  float one;
  int pointElementOffset;
  int pointAddr;
  
  one = FLOAT_00108e54;
  pointElementOffset = 0;
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((one / (u2 - u1)));
  if (0 < order) {
    do {
      pointByteOffset = pointElementOffset * 4;
      pointElementOffset = pointElementOffset + stride;
      pointAddr = pointByteOffset + points;
      mapData[4] = *(int *)(pointByteOffset + points);
      mapData[5] = *(int *)(pointAddr + 4);
      mapData[6] = *(int *)(pointAddr + 8);
      mapData[7] = *(int *)(pointAddr + 0xc);
      mapData = mapData + 4;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1VertexAttrib1fLoad @ 0xdef50 (92 bytes) */
void _gleMap1VertexAttrib1fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int stride,int order,int *points,int *mapData,float u1,float u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int pointValue;
  float one;
  int *destPtr;
  
  one = FLOAT_00108e54;
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((one / (u2 - u1)));
  if (order < 1) {
    return;
  }
  destPtr = mapData + 4;
  do {
    pointValue = *points;
    points = points + stride;
    *destPtr = pointValue;
    destPtr = destPtr + 1;
    order = order + -1;
  } while (order != 0);
  return;
}

/* _gleMap1VertexAttrib2fLoad @ 0xdefac (96 bytes) */
void _gleMap1VertexAttrib2fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int stride,int order,int *points,int *mapData,float u1,float u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int *secondComponentPtr;
  float one;
  
  one = FLOAT_00108e54;
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((one / (u2 - u1)));
  if (0 < order) {
    do {
      mapData[4] = *points;
      secondComponentPtr = points + 1;
      points = points + stride;
      mapData[5] = *secondComponentPtr;
      mapData = mapData + 2;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1VertexAttrib3fLoad @ 0xdf00c (112 bytes) */
void _gleMap1VertexAttrib3fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int stride,int order,int points,int *mapData,float u1,float u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int pointByteOffset;
  float one;
  int pointElementOffset;
  int pointAddr;
  
  one = FLOAT_00108e54;
  pointElementOffset = 0;
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((one / (u2 - u1)));
  if (0 < order) {
    do {
      pointByteOffset = pointElementOffset * 4;
      pointElementOffset = pointElementOffset + stride;
      pointAddr = pointByteOffset + points;
      mapData[4] = *(int *)(pointByteOffset + points);
      mapData[5] = *(int *)(pointAddr + 4);
      mapData[6] = *(int *)(pointAddr + 8);
      mapData = mapData + 3;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleMap1VertexAttrib4fLoad @ 0xdf07c (120 bytes) */
void _gleMap1VertexAttrib4fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int stride,int order,int points,int *mapData,float u1,float u2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int pointByteOffset;
  float one;
  int pointElementOffset;
  int pointAddr;
  
  one = FLOAT_00108e54;
  pointElementOffset = 0;
  *mapData = order;
  mapData[1] = (int)GH_F2U((float)u1);
  mapData[2] = (int)GH_F2U((float)u2);
  mapData[3] = (int)GH_F2U((one / (u2 - u1)));
  if (0 < order) {
    do {
      pointByteOffset = pointElementOffset * 4;
      pointElementOffset = pointElementOffset + stride;
      pointAddr = pointByteOffset + points;
      mapData[4] = *(int *)(pointByteOffset + points);
      mapData[5] = *(int *)(pointAddr + 4);
      mapData[6] = *(int *)(pointAddr + 8);
      mapData[7] = *(int *)(pointAddr + 0xc);
      mapData = mapData + 4;
      order = order + -1;
    } while (order != 0);
    return;
  }
  return;
}

/* _gleEvalMap1 @ 0xdf0f4 (968 bytes) */
void _gleEvalMap1(int glContext,float floatArg1)
{
  byte attribByteSize;
  byte slotByteSize;
  float domainStart;
  float domainScale;
  float domainScale2;
  float offsetFromStart;
  undefined4 *mapDataThenPoints;
  undefined4 *controlPoints;
  undefined4 *selectedPoints;
  undefined4 order;
  undefined4 hookResult;
  undefined4 incomingR6;
  undefined4 components;
  int vertexWritePos;
  int outStart;
  int nextOut;
  int out;
  undefined4 *slotMapTable;
  undefined4 *puVar13;
  undefined4 *puVar14;
  uint flagsUpdated;
  uint slotMask;
  byte *sizeCursor;
  undefined4 *slotMapCursor;
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
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  
  mapDataThenPoints = (undefined4 *)_gleGetMapData(glContext);
  if (*(short *)(glContext + 0x4a10) < 0) {
    return;
  }
  vertexWritePos = *(int *)(glContext + 0x4858);
  if (vertexWritePos == *(int *)(glContext + 0x485c)) {
    (**(code **)(glContext + 0x4a0c))(glContext);
    vertexWritePos = *(int *)(glContext + 0x4858);
  }
  outStart = *(int *)(glContext + 0x4860);
  out = outStart;
  if (*(char *)(glContext + 0x7515) != '\0') {
    out = outStart + 0xc;
    ((void (*)())_gleEvalDomain1Coord)(glContext,mapDataThenPoints + 0x52,mapDataThenPoints[0x4e],incomingR6,3,outStart,
               (double)((float)(floatArg1 - (double)GH_U2F((unsigned int)(mapDataThenPoints[0x4f]))) * GH_U2F((unsigned int)(mapDataThenPoints[0x51]))),incomingFpr2
               ,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90,
               incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8);
  }
  if (*(char *)(glContext + 0x7516) != '\0') {
    ((void (*)())_gleEvalDomain1Color)(glContext,mapDataThenPoints + 0x74,mapDataThenPoints[0x70],incomingR6,4,out,
               (double)((float)(floatArg1 - (double)GH_U2F((unsigned int)(mapDataThenPoints[0x71]))) * GH_U2F((unsigned int)(mapDataThenPoints[0x73]))),incomingFpr2
               ,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90,
               incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8);
    if (*(char *)(glContext + 0x4df8) != '\0') {
      (**(code **)(glContext + 0x4de0))(glContext,out);
    }
    out = out + 0x10;
  }
  attribByteSize = *(byte *)(glContext + 0x751c);
  if (attribByteSize == 8) {
    domainStart = GH_U2F((unsigned int)(mapDataThenPoints[0xb9]));
    domainScale2 = GH_U2F((unsigned int)(mapDataThenPoints[0xbb]));
    order = mapDataThenPoints[0xb8];
    controlPoints = mapDataThenPoints + 0xbc;
    components = 2;
    nextOut = out + 8;
LAB_000df2c8:
    ((void (*)())_gleEvalDomain1Coord)(glContext,controlPoints,order,incomingR6,components,out,
               (double)((floatArg1 - domainStart) * domainScale2),incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,
               incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98,incomingStack_ffffffa0,
               incomingStack_ffffffa8);
    out = nextOut;
  }
  else if (attribByteSize < 9) {
    if (attribByteSize == 4) {
      domainStart = GH_U2F((unsigned int)(mapDataThenPoints[0xab]));
      domainScale2 = GH_U2F((unsigned int)(mapDataThenPoints[0xad]));
      order = mapDataThenPoints[0xaa];
      controlPoints = mapDataThenPoints + 0xae;
      components = 1;
      nextOut = out + 4;
      goto LAB_000df2c8;
    }
  }
  else {
    if (attribByteSize == 0xc) {
      nextOut = out + 0xc;
      ((void (*)())_gleEvalDomain1Coord)(glContext,mapDataThenPoints + 0xd4,mapDataThenPoints[0xd0],incomingR6,3,out,
                 (double)((float)(floatArg1 - (double)GH_U2F((unsigned int)(mapDataThenPoints[0xd1]))) * GH_U2F((unsigned int)(mapDataThenPoints[0xd3]))),
                 incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90,
                 incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8);
      flagsUpdated = *(uint *)(glContext + 0x486c) | 1;
    }
    else {
      if (attribByteSize != 0x10) goto LAB_000df2d0;
      nextOut = out + 0x10;
      ((void (*)())_gleEvalDomain1Coord)(glContext,mapDataThenPoints + 0xf6,mapDataThenPoints[0xf2],incomingR6,4,out,
                 (double)((float)(floatArg1 - (double)GH_U2F((unsigned int)(mapDataThenPoints[0xf3]))) * GH_U2F((unsigned int)(mapDataThenPoints[0xf5]))),
                 incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90,
                 incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8);
      flagsUpdated = *(uint *)(glContext + 0x486c) | 3;
    }
    *(uint *)(glContext + 0x486c) = flagsUpdated;
    out = nextOut;
  }
LAB_000df2d0:
  slotMask = *(uint *)(glContext + 0x74d8);
  if (slotMask != 0) {
    slotMapTable = mapDataThenPoints + 0xb2e;
    sizeCursor = (byte *)(glContext + 0x7524);
    controlPoints = slotMapTable;
    puVar13 = slotMapTable;
    puVar14 = slotMapTable;
    slotMapCursor = mapDataThenPoints;
    do {
      slotByteSize = *sizeCursor;
      sizeCursor = sizeCursor + 1;
      if (slotByteSize == 8) {
        domainScale = GH_U2F((unsigned int)(slotMapCursor[0xb2d]));
        offsetFromStart = (float)(floatArg1 - (double)GH_U2F((unsigned int)(slotMapCursor[0xb2b])));
        order = slotMapCursor[0xb2a];
        components = 2;
        nextOut = out + 8;
        selectedPoints = puVar13;
LAB_000df3c0:
        ((void (*)())_gleEvalDomain1Coord)(glContext,selectedPoints,order,incomingR6,components,out,(double)(offsetFromStart * domainScale),incomingFpr2,incomingFpr3,incomingFpr4
                   ,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98,
                   incomingStack_ffffffa0,incomingStack_ffffffa8);
        out = nextOut;
      }
      else {
        if (8 < slotByteSize) {
          if (slotByteSize == 0xc) {
            domainScale = GH_U2F((unsigned int)(slotMapCursor[0xb2d]));
            offsetFromStart = (float)(floatArg1 - (double)GH_U2F((unsigned int)(slotMapCursor[0xb2b])));
            order = slotMapCursor[0xb2a];
            components = 3;
            nextOut = out + 0xc;
            selectedPoints = slotMapTable;
          }
          else {
            if (slotByteSize != 0x10) goto LAB_000df3c8;
            domainScale = GH_U2F((unsigned int)(slotMapCursor[0xb2d]));
            offsetFromStart = (float)(floatArg1 - (double)GH_U2F((unsigned int)(slotMapCursor[0xb2b])));
            order = slotMapCursor[0xb2a];
            components = 4;
            nextOut = out + 0x10;
            selectedPoints = controlPoints;
          }
          goto LAB_000df3c0;
        }
        if (slotByteSize == 4) {
          domainScale = GH_U2F((unsigned int)(slotMapCursor[0xb2d]));
          offsetFromStart = (float)(floatArg1 - (double)GH_U2F((unsigned int)(slotMapCursor[0xb2b])));
          order = slotMapCursor[0xb2a];
          components = 1;
          nextOut = out + 4;
          selectedPoints = puVar14;
          goto LAB_000df3c0;
        }
      }
LAB_000df3c8:
      slotMask = slotMask >> 1;
      controlPoints = controlPoints + 0x2c;
      slotMapTable = slotMapTable + 0x2c;
      puVar13 = puVar13 + 0x2c;
      slotMapCursor = slotMapCursor + 0x2c;
      puVar14 = puVar14 + 0x2c;
    } while (slotMask != 0);
  }
  if (*(char *)(glContext + 0x7514) == '\f') {
    domainStart = GH_U2F((unsigned int)(mapDataThenPoints[1]));
    domainScale2 = GH_U2F((unsigned int)(mapDataThenPoints[3]));
    order = *mapDataThenPoints;
    mapDataThenPoints = mapDataThenPoints + 4;
    components = 3;
  }
  else {
    if (*(char *)(glContext + 0x7514) != '\x10') {
      if ((*(char *)(glContext + 0x4664) == '\0') || (*(char *)(glContext + 0x7524) == '\0')) {
        if (*(int *)(glContext + 0x5434) == 0) {
          return;
        }
        if (*(char *)(glContext + 0x7524) == '\0') {
          return;
        }
      }
      goto LAB_000df478;
    }
    domainStart = GH_U2F((unsigned int)(mapDataThenPoints[0x23]));
    domainScale2 = GH_U2F((unsigned int)(mapDataThenPoints[0x25]));
    order = mapDataThenPoints[0x22];
    mapDataThenPoints = mapDataThenPoints + 0x26;
    components = 4;
  }
  ((void (*)())_gleEvalDomain1Coord)(glContext,mapDataThenPoints,order,incomingR6,components,out,
             (double)((floatArg1 - domainStart) * domainScale2),incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7
             ,incomingFpr8,incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98,incomingStack_ffffffa0,
             incomingStack_ffffffa8);
LAB_000df478:
  *(int *)(glContext + 0x48ec) = glContext + 0x7508;
  hookResult = (**(code **)(glContext + 0x4898))(glContext,*(undefined4 *)(glContext + 0x4860),vertexWritePos);
  *(undefined4 *)(glContext + 0x48ec) = 0;
  *(undefined4 *)(glContext + 0x4858) = hookResult;
  return;
}

/* _gleComputeFirstPartial @ 0xdf4bc (108 bytes) */
void _gleComputeFirstPartial(unusedArg1, param_2, param_3, param_4)
  undefined4 unusedArg1;
  float *param_2;
  float *param_3;
  float *param_4;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = param_2[1];
  fVar2 = *param_2;
  fVar3 = param_2[2];
  fVar4 = param_3[3];
  fVar5 = param_2[3];
  param_3[2] = param_3[2] * fVar5 - fVar4 * fVar3;
  *param_3 = *param_3 * fVar5 - fVar4 * fVar2;
  param_3[1] = param_3[1] * fVar5 - fVar4 * fVar1;
  param_4[1] = param_4[1] * fVar5 - fVar4 * fVar1;
  *param_4 = *param_4 * fVar5 - fVar4 * fVar2;
  param_4[2] = param_4[2] * fVar5 - fVar4 * fVar3;
  return;
}

/* _gleInitMap2Data @ 0xdf528 (496 bytes) */
void _gleInitMap2Data(glContext)
  int glContext;
{
  int evalStateCursor;
  undefined1 *mapDimensionCursor;
  int remaining;
  
  evalStateCursor = *(int *)(glContext + 0x7450);
  remaining = 0x10;
  *(undefined4 *)(evalStateCursor + 0x478) = 1;
  *(undefined4 *)(evalStateCursor + 0x47c) = 1;
  *(undefined4 *)(evalStateCursor + 0x480) = 0;
  mapDimensionCursor = (undefined1 *)(evalStateCursor + 0x9db8);
  *(undefined4 *)(evalStateCursor + 0x484) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x490) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x488) = 0;
  *(undefined4 *)(evalStateCursor + 0x48c) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x494) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x498) = 0;
  *(undefined4 *)(evalStateCursor + 0x49c) = 0;
  *(undefined4 *)(evalStateCursor + 0x4a0) = 0;
  *(undefined4 *)(evalStateCursor + 0x948) = 1;
  *(undefined4 *)(evalStateCursor + 0x94c) = 1;
  *(undefined4 *)(evalStateCursor + 0x950) = 0;
  *(undefined4 *)(evalStateCursor + 0x954) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x960) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x958) = 0;
  *(undefined4 *)(evalStateCursor + 0x95c) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x964) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x968) = 0;
  *(undefined4 *)(evalStateCursor + 0x96c) = 0;
  *(undefined4 *)(evalStateCursor + 0x970) = 0;
  *(undefined4 *)(evalStateCursor + 0x974) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0xfa8) = 1;
  *(undefined4 *)(evalStateCursor + 0xfac) = 1;
  *(undefined4 *)(evalStateCursor + 0xfb0) = 0;
  *(undefined4 *)(evalStateCursor + 0xfb4) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0xfc0) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0xfb8) = 0;
  *(undefined4 *)(evalStateCursor + 0xfbc) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0xfc4) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0xfc8) = 0;
  *(undefined4 *)(evalStateCursor + 0xfcc) = 0;
  *(undefined4 *)(evalStateCursor + 0xfd0) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1478) = 1;
  *(undefined4 *)(evalStateCursor + 0x147c) = 1;
  *(undefined4 *)(evalStateCursor + 0x1480) = 0;
  *(undefined4 *)(evalStateCursor + 0x1484) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1490) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1488) = 0;
  *(undefined4 *)(evalStateCursor + 0x148c) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1494) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1498) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x149c) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x14a0) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x14a4) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1ad8) = 1;
  *(undefined4 *)(evalStateCursor + 0x1adc) = 1;
  *(undefined4 *)(evalStateCursor + 0x1ae0) = 0;
  *(undefined4 *)(evalStateCursor + 0x1ae4) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1af0) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1ae8) = 0;
  *(undefined4 *)(evalStateCursor + 0x1aec) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1af4) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1af8) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1c88) = 1;
  *(undefined4 *)(evalStateCursor + 0x1c8c) = 1;
  *(undefined4 *)(evalStateCursor + 0x1c90) = 0;
  *(undefined4 *)(evalStateCursor + 0x1c94) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1ca0) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1c98) = 0;
  *(undefined4 *)(evalStateCursor + 0x1c9c) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1ca4) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1ca8) = 0;
  *(undefined4 *)(evalStateCursor + 0x1e38) = 1;
  *(undefined4 *)(evalStateCursor + 0x1e3c) = 1;
  *(undefined4 *)(evalStateCursor + 0x1e40) = 0;
  *(undefined4 *)(evalStateCursor + 0x264c) = 1;
  *(undefined4 *)(evalStateCursor + 0x1e44) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1e50) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1e48) = 0;
  *(undefined4 *)(evalStateCursor + 0x1e4c) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1e54) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x1e58) = 0;
  *(undefined4 *)(evalStateCursor + 0x1e5c) = 0;
  *(undefined4 *)(evalStateCursor + 0x2178) = 1;
  *(undefined4 *)(evalStateCursor + 0x217c) = 1;
  *(undefined4 *)(evalStateCursor + 0x2180) = 0;
  *(undefined4 *)(evalStateCursor + 0x2184) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x2190) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x2188) = 0;
  *(undefined4 *)(evalStateCursor + 0x218c) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x2194) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x2198) = 0;
  *(undefined4 *)(evalStateCursor + 0x219c) = 0;
  *(undefined4 *)(evalStateCursor + 0x21a0) = 0;
  *(undefined4 *)(evalStateCursor + 0x2648) = 1;
  *(undefined4 *)(evalStateCursor + 0x2650) = 0;
  *(undefined4 *)(evalStateCursor + 0x2654) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x2660) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x2658) = 0;
  *(undefined4 *)(evalStateCursor + 0x265c) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x2664) = 0x3f800000;
  *(undefined4 *)(evalStateCursor + 0x2668) = 0;
  *(undefined4 *)(evalStateCursor + 0x266c) = 0;
  *(undefined4 *)(evalStateCursor + 0x2670) = 0;
  *(undefined4 *)(evalStateCursor + 0x2674) = 0x3f800000;
  do {
    *mapDimensionCursor = 4;
    mapDimensionCursor = mapDimensionCursor + 1;
    *(undefined4 *)(evalStateCursor + 0x37a8) = 1;
    *(undefined4 *)(evalStateCursor + 0x37ac) = 1;
    *(undefined4 *)(evalStateCursor + 0x37b0) = 0;
    *(undefined4 *)(evalStateCursor + 0x37b4) = 0x3f800000;
    *(undefined4 *)(evalStateCursor + 0x37c0) = 0x3f800000;
    *(undefined4 *)(evalStateCursor + 0x37b8) = 0;
    *(undefined4 *)(evalStateCursor + 0x37bc) = 0x3f800000;
    *(undefined4 *)(evalStateCursor + 0x37c4) = 0x3f800000;
    *(undefined4 *)(evalStateCursor + 0x37c8) = 0;
    *(undefined4 *)(evalStateCursor + 0x37cc) = 0;
    *(undefined4 *)(evalStateCursor + 0x37d0) = 0;
    *(undefined4 *)(evalStateCursor + 0x37d4) = 0x3f800000;
    evalStateCursor = evalStateCursor + 0x660;
    remaining = remaining + -1;
  } while (remaining != 0);
  return;
}

/* _gleMap2Vertex3dLoad @ 0xdf718 (244 bytes) */
void _gleMap2Vertex3dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int ustride,int uorder,undefined4 unusedArg8,undefined4 unusedArg9,undefined4 unusedArg10,undefined4 unusedArg11,int vstride,int vorder,int points,int *mapData,double u1,double u2,double v1,double v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double *lastComponentPtr;
  double one;
  double *pointPtr;
  int uIndex;
  int uElementOffset;
  int destRecord;
  int *destPtr;
  int vRemaining;
  double invUDelta;
  
  one = DOUBLE_00108d68;
  uIndex = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[6] = (int)GH_F2U((float)invUDelta);
  mapData[7] = (int)GH_F2U((float)(one / (v2 - v1)));
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        pointPtr = (double *)(uElementOffset * 8 + points);
        destPtr = mapData + destRecord * 3;
        vRemaining = vorder;
        do {
          destPtr[8] = (int)GH_F2U((float)*pointPtr);
          destPtr[9] = (int)GH_F2U((float)pointPtr[1]);
          lastComponentPtr = pointPtr + 2;
          pointPtr = pointPtr + vstride;
          destPtr[10] = (int)GH_F2U((float)*lastComponentPtr);
          destPtr = destPtr + 3;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2Vertex4dLoad @ 0xdf80c (256 bytes) */
void _gleMap2Vertex4dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int ustride,int uorder,undefined4 unusedArg8,undefined4 unusedArg9,undefined4 unusedArg10,undefined4 unusedArg11,int vstride,int vorder,int points,int *mapData,double u1,double u2,double v1,double v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double *lastComponentPtr;
  double one;
  double *pointPtr;
  int uIndex;
  int uElementOffset;
  int destRecord;
  int *destPtr;
  int vRemaining;
  double invUDelta;
  
  one = DOUBLE_00108d68;
  uIndex = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[6] = (int)GH_F2U((float)invUDelta);
  mapData[7] = (int)GH_F2U((float)(one / (v2 - v1)));
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        destPtr = mapData + destRecord * 4;
        pointPtr = (double *)(uElementOffset * 8 + points);
        vRemaining = vorder;
        do {
          destPtr[8] = (int)GH_F2U((float)*pointPtr);
          destPtr[9] = (int)GH_F2U((float)pointPtr[1]);
          destPtr[10] = (int)GH_F2U((float)pointPtr[2]);
          lastComponentPtr = pointPtr + 3;
          pointPtr = pointPtr + vstride;
          destPtr[0xb] = (int)GH_F2U((float)*lastComponentPtr);
          destPtr = destPtr + 4;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2ColordLoad @ 0xdf90c (256 bytes) */
void _gleMap2ColordLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int ustride,int uorder,undefined4 unusedArg8,undefined4 unusedArg9,undefined4 unusedArg10,undefined4 unusedArg11,int vstride,int vorder,int points,int *mapData,double u1,double u2,double v1,double v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double *lastComponentPtr;
  double one;
  double *pointPtr;
  int uIndex;
  int uElementOffset;
  int destRecord;
  int *destPtr;
  int vRemaining;
  double invUDelta;
  
  one = DOUBLE_00108d68;
  uIndex = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[6] = (int)GH_F2U((float)invUDelta);
  mapData[7] = (int)GH_F2U((float)(one / (v2 - v1)));
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        destPtr = mapData + destRecord * 4;
        pointPtr = (double *)(uElementOffset * 8 + points);
        vRemaining = vorder;
        do {
          destPtr[8] = (int)GH_F2U((float)*pointPtr);
          destPtr[9] = (int)GH_F2U((float)pointPtr[1]);
          destPtr[10] = (int)GH_F2U((float)pointPtr[2]);
          lastComponentPtr = pointPtr + 3;
          pointPtr = pointPtr + vstride;
          destPtr[0xb] = (int)GH_F2U((float)*lastComponentPtr);
          destPtr = destPtr + 4;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2IndexdLoad @ 0xdfa0c (224 bytes) */
void _gleMap2IndexdLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int ustride,int uorder,undefined4 unusedArg8,undefined4 unusedArg9,undefined4 unusedArg10,undefined4 unusedArg11,int vstride,int vorder,int points,int *mapData,double u1,double u2,double v1,double v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float *pfVar1;
  int uIndex;
  int uElementOffset;
  int destRecord;
  double *pointPtr;
  int vRemaining;
  double dVar7;
  double invUDelta;
  
  dVar7 = DOUBLE_00108d68;
  uIndex = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[6] = (int)GH_F2U((float)invUDelta);
  mapData[7] = (int)GH_F2U((float)(dVar7 / (v2 - v1)));
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        pointPtr = (double *)(uElementOffset * 8 + points);
        pfVar1 = (float *)(mapData + destRecord + 8);
        vRemaining = vorder;
        do {
          dVar7 = *pointPtr;
          pointPtr = pointPtr + vstride;
          *pfVar1 = (float)dVar7;
          pfVar1 = pfVar1 + 1;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2NormaldLoad @ 0xdfaec (244 bytes) */
void _gleMap2NormaldLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int ustride,int uorder,undefined4 unusedArg8,undefined4 unusedArg9,undefined4 unusedArg10,undefined4 unusedArg11,int vstride,int vorder,int points,int *mapData,double u1,double u2,double v1,double v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double *lastComponentPtr;
  double one;
  double *pointPtr;
  int uIndex;
  int uElementOffset;
  int destRecord;
  int *destPtr;
  int vRemaining;
  double invUDelta;
  
  one = DOUBLE_00108d68;
  uIndex = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[6] = (int)GH_F2U((float)invUDelta);
  mapData[7] = (int)GH_F2U((float)(one / (v2 - v1)));
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        pointPtr = (double *)(uElementOffset * 8 + points);
        destPtr = mapData + destRecord * 3;
        vRemaining = vorder;
        do {
          destPtr[8] = (int)GH_F2U((float)*pointPtr);
          destPtr[9] = (int)GH_F2U((float)pointPtr[1]);
          lastComponentPtr = pointPtr + 2;
          pointPtr = pointPtr + vstride;
          destPtr[10] = (int)GH_F2U((float)*lastComponentPtr);
          destPtr = destPtr + 3;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2Texture1dLoad @ 0xdfbe0 (224 bytes) */
void _gleMap2Texture1dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int ustride,int uorder,undefined4 unusedArg8,undefined4 unusedArg9,undefined4 unusedArg10,undefined4 unusedArg11,int vstride,int vorder,int points,int *mapData,double u1,double u2,double v1,double v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float *pfVar1;
  int uIndex;
  int uElementOffset;
  int destRecord;
  double *pointPtr;
  int vRemaining;
  double dVar7;
  double invUDelta;
  
  dVar7 = DOUBLE_00108d68;
  uIndex = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[6] = (int)GH_F2U((float)invUDelta);
  mapData[7] = (int)GH_F2U((float)(dVar7 / (v2 - v1)));
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        pointPtr = (double *)(uElementOffset * 8 + points);
        pfVar1 = (float *)(mapData + destRecord + 8);
        vRemaining = vorder;
        do {
          dVar7 = *pointPtr;
          pointPtr = pointPtr + vstride;
          *pfVar1 = (float)dVar7;
          pfVar1 = pfVar1 + 1;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2Texture2dLoad @ 0xdfcc0 (252 bytes) */
void _gleMap2Texture2dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int ustride,int uorder,undefined4 unusedArg8,undefined4 unusedArg9,undefined4 unusedArg10,undefined4 unusedArg11,int vstride,int vorder,int points,int *mapData,double u1,double u2,double v1,double v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double *pointSPtr;
  int sByteOffset;
  int *destPtr;
  int uElementOffset;
  int destRecord;
  int uRowBase;
  double *pointTPtr;
  int uIndex;
  int vRemaining;
  double invUDelta;
  double unitConstant;
  double pointT;
  
  unitConstant = DOUBLE_00108d68;
  uIndex = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = uorder;
  mapData[1] = vorder;
  uElementOffset = 0;
  mapData[6] = (int)GH_F2U((float)invUDelta);
  mapData[7] = (int)GH_F2U((float)(unitConstant / (v2 - v1)));
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  if (0 < uorder) {
    destRecord = 0;
    uRowBase = points;
    do {
      if (0 < vorder) {
        destPtr = mapData + destRecord * 2;
        pointTPtr = (double *)(uRowBase + 8);
        sByteOffset = uElementOffset << 3;
        vRemaining = vorder;
        do {
          pointSPtr = (double *)(points + sByteOffset);
          sByteOffset = sByteOffset + vstride * 8;
          destPtr[8] = (int)GH_F2U((float)*pointSPtr);
          pointT = *pointTPtr;
          pointTPtr = pointTPtr + vstride;
          destPtr[9] = (int)GH_F2U((float)pointT);
          destPtr = destPtr + 2;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      uRowBase = uRowBase + ustride * 8;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2Texture3dLoad @ 0xdfdbc (244 bytes) */
void _gleMap2Texture3dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int ustride,int uorder,undefined4 unusedArg8,undefined4 unusedArg9,undefined4 unusedArg10,undefined4 unusedArg11,int vstride,int vorder,int points,int *mapData,double u1,double u2,double v1,double v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double *lastComponentPtr;
  double one;
  double *pointPtr;
  int uIndex;
  int uElementOffset;
  int destRecord;
  int *destPtr;
  int vRemaining;
  double invUDelta;
  
  one = DOUBLE_00108d68;
  uIndex = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[6] = (int)GH_F2U((float)invUDelta);
  mapData[7] = (int)GH_F2U((float)(one / (v2 - v1)));
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        pointPtr = (double *)(uElementOffset * 8 + points);
        destPtr = mapData + destRecord * 3;
        vRemaining = vorder;
        do {
          destPtr[8] = (int)GH_F2U((float)*pointPtr);
          destPtr[9] = (int)GH_F2U((float)pointPtr[1]);
          lastComponentPtr = pointPtr + 2;
          pointPtr = pointPtr + vstride;
          destPtr[10] = (int)GH_F2U((float)*lastComponentPtr);
          destPtr = destPtr + 3;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2Texture4dLoad @ 0xdfeb0 (256 bytes) */
void _gleMap2Texture4dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int ustride,int uorder,undefined4 unusedArg8,undefined4 unusedArg9,undefined4 unusedArg10,undefined4 unusedArg11,int vstride,int vorder,int points,int *mapData,double u1,double u2,double v1,double v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double *lastComponentPtr;
  double one;
  double *pointPtr;
  int uIndex;
  int uElementOffset;
  int destRecord;
  int *destPtr;
  int vRemaining;
  double invUDelta;
  
  one = DOUBLE_00108d68;
  uIndex = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[6] = (int)GH_F2U((float)invUDelta);
  mapData[7] = (int)GH_F2U((float)(one / (v2 - v1)));
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        destPtr = mapData + destRecord * 4;
        pointPtr = (double *)(uElementOffset * 8 + points);
        vRemaining = vorder;
        do {
          destPtr[8] = (int)GH_F2U((float)*pointPtr);
          destPtr[9] = (int)GH_F2U((float)pointPtr[1]);
          destPtr[10] = (int)GH_F2U((float)pointPtr[2]);
          lastComponentPtr = pointPtr + 3;
          pointPtr = pointPtr + vstride;
          destPtr[0xb] = (int)GH_F2U((float)*lastComponentPtr);
          destPtr = destPtr + 4;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2VertexAttrib1dLoad @ 0xdffb0 (224 bytes) */
void _gleMap2VertexAttrib1dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int ustride,int uorder,undefined4 unusedArg8,undefined4 unusedArg9,undefined4 unusedArg10,undefined4 unusedArg11,int vstride,int vorder,int points,int *mapData,double u1,double u2,double v1,double v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float *pfVar1;
  int uIndex;
  int uElementOffset;
  int destRecord;
  double *pointPtr;
  int vRemaining;
  double dVar7;
  double invUDelta;
  
  dVar7 = DOUBLE_00108d68;
  uIndex = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[6] = (int)GH_F2U((float)invUDelta);
  mapData[7] = (int)GH_F2U((float)(dVar7 / (v2 - v1)));
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        pointPtr = (double *)(uElementOffset * 8 + points);
        pfVar1 = (float *)(mapData + destRecord + 8);
        vRemaining = vorder;
        do {
          dVar7 = *pointPtr;
          pointPtr = pointPtr + vstride;
          *pfVar1 = (float)dVar7;
          pfVar1 = pfVar1 + 1;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2VertexAttrib2dLoad @ 0xe0090 (252 bytes) */
void _gleMap2VertexAttrib2dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int ustride,int uorder,undefined4 unusedArg8,undefined4 unusedArg9,undefined4 unusedArg10,undefined4 unusedArg11,int vstride,int vorder,int points,int *mapData,double u1,double u2,double v1,double v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double *pdVar1;
  int iVar2;
  int *destPtr;
  int uElementOffset;
  int destRecord;
  int iVar6;
  double *pdVar7;
  int uIndex;
  int vRemaining;
  double invUDelta;
  double dVar11;
  
  dVar11 = DOUBLE_00108d68;
  uIndex = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = uorder;
  mapData[1] = vorder;
  uElementOffset = 0;
  mapData[6] = (int)GH_F2U((float)invUDelta);
  mapData[7] = (int)GH_F2U((float)(dVar11 / (v2 - v1)));
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  if (0 < uorder) {
    destRecord = 0;
    iVar6 = points;
    do {
      if (0 < vorder) {
        destPtr = mapData + destRecord * 2;
        pdVar7 = (double *)(iVar6 + 8);
        iVar2 = uElementOffset << 3;
        vRemaining = vorder;
        do {
          pdVar1 = (double *)(points + iVar2);
          iVar2 = iVar2 + vstride * 8;
          destPtr[8] = (int)GH_F2U((float)*pdVar1);
          dVar11 = *pdVar7;
          pdVar7 = pdVar7 + vstride;
          destPtr[9] = (int)GH_F2U((float)dVar11);
          destPtr = destPtr + 2;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      iVar6 = iVar6 + ustride * 8;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2VertexAttrib3dLoad @ 0xe018c (244 bytes) */
void _gleMap2VertexAttrib3dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int ustride,int uorder,undefined4 unusedArg8,undefined4 unusedArg9,undefined4 unusedArg10,undefined4 unusedArg11,int vstride,int vorder,int points,int *mapData,double u1,double u2,double v1,double v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double *lastComponentPtr;
  double one;
  double *pointPtr;
  int uIndex;
  int uElementOffset;
  int destRecord;
  int *destPtr;
  int vRemaining;
  double invUDelta;
  
  one = DOUBLE_00108d68;
  uIndex = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[6] = (int)GH_F2U((float)invUDelta);
  mapData[7] = (int)GH_F2U((float)(one / (v2 - v1)));
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        pointPtr = (double *)(uElementOffset * 8 + points);
        destPtr = mapData + destRecord * 3;
        vRemaining = vorder;
        do {
          destPtr[8] = (int)GH_F2U((float)*pointPtr);
          destPtr[9] = (int)GH_F2U((float)pointPtr[1]);
          lastComponentPtr = pointPtr + 2;
          pointPtr = pointPtr + vstride;
          destPtr[10] = (int)GH_F2U((float)*lastComponentPtr);
          destPtr = destPtr + 3;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2VertexAttrib4dLoad @ 0xe0280 (256 bytes) */
void _gleMap2VertexAttrib4dLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,int ustride,int uorder,undefined4 unusedArg8,undefined4 unusedArg9,undefined4 unusedArg10,undefined4 unusedArg11,int vstride,int vorder,int points,int *mapData,double u1,double u2,double v1,double v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double *lastComponentPtr;
  double one;
  double *pointPtr;
  int uIndex;
  int uElementOffset;
  int destRecord;
  int *destPtr;
  int vRemaining;
  double invUDelta;
  
  one = DOUBLE_00108d68;
  uIndex = 0;
  invUDelta = DOUBLE_00108d68 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[6] = (int)GH_F2U((float)invUDelta);
  mapData[7] = (int)GH_F2U((float)(one / (v2 - v1)));
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        destPtr = mapData + destRecord * 4;
        pointPtr = (double *)(uElementOffset * 8 + points);
        vRemaining = vorder;
        do {
          destPtr[8] = (int)GH_F2U((float)*pointPtr);
          destPtr[9] = (int)GH_F2U((float)pointPtr[1]);
          destPtr[10] = (int)GH_F2U((float)pointPtr[2]);
          lastComponentPtr = pointPtr + 3;
          pointPtr = pointPtr + vstride;
          destPtr[0xb] = (int)GH_F2U((float)*lastComponentPtr);
          destPtr = destPtr + 4;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2Vertex3fLoad @ 0xe0380 (204 bytes) */
void _gleMap2Vertex3fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int ustride,int uorder,undefined4 unusedArg6,undefined4 unusedArg7,int vstride,int vorder,int points,int *mapData,float u1,float u2,float v1,float v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int *lastComponentPtr;
  float invUDelta;
  float one;
  int *pointPtr;
  int uIndex;
  int uElementOffset;
  int *destPtr;
  int destRecord;
  int vRemaining;
  
  one = FLOAT_00108e54;
  uIndex = 0;
  invUDelta = FLOAT_00108e54 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  mapData[6] = (int)GH_F2U(invUDelta);
  mapData[7] = (int)GH_F2U((one / (v2 - v1)));
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        pointPtr = (int *)(uElementOffset * 4 + points);
        destPtr = mapData + destRecord * 3;
        vRemaining = vorder;
        do {
          destPtr[8] = *pointPtr;
          destPtr[9] = pointPtr[1];
          lastComponentPtr = pointPtr + 2;
          pointPtr = pointPtr + vstride;
          destPtr[10] = *lastComponentPtr;
          destPtr = destPtr + 3;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2Vertex4fLoad @ 0xe044c (212 bytes) */
void _gleMap2Vertex4fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int ustride,int uorder,undefined4 unusedArg6,undefined4 unusedArg7,int vstride,int vorder,int points,int *mapData,float u1,float u2,float v1,float v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int *lastComponentPtr;
  float invUDelta;
  float one;
  int *pointPtr;
  int uIndex;
  int uElementOffset;
  int *destPtr;
  int destRecord;
  int vRemaining;
  
  one = FLOAT_00108e54;
  uIndex = 0;
  invUDelta = FLOAT_00108e54 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  mapData[6] = (int)GH_F2U(invUDelta);
  mapData[7] = (int)GH_F2U((one / (v2 - v1)));
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        destPtr = mapData + destRecord * 4;
        pointPtr = (int *)(uElementOffset * 4 + points);
        vRemaining = vorder;
        do {
          destPtr[8] = *pointPtr;
          destPtr[9] = pointPtr[1];
          destPtr[10] = pointPtr[2];
          lastComponentPtr = pointPtr + 3;
          pointPtr = pointPtr + vstride;
          destPtr[0xb] = *lastComponentPtr;
          destPtr = destPtr + 4;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2ColorfLoad @ 0xe0520 (212 bytes) */
void _gleMap2ColorfLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int ustride,int uorder,undefined4 unusedArg6,undefined4 unusedArg7,int vstride,int vorder,int points,int *mapData,float u1,float u2,float v1,float v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int *lastComponentPtr;
  float invUDelta;
  float one;
  int *pointPtr;
  int uIndex;
  int uElementOffset;
  int *destPtr;
  int destRecord;
  int vRemaining;
  
  one = FLOAT_00108e54;
  uIndex = 0;
  invUDelta = FLOAT_00108e54 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  mapData[6] = (int)GH_F2U(invUDelta);
  mapData[7] = (int)GH_F2U((one / (v2 - v1)));
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        destPtr = mapData + destRecord * 4;
        pointPtr = (int *)(uElementOffset * 4 + points);
        vRemaining = vorder;
        do {
          destPtr[8] = *pointPtr;
          destPtr[9] = pointPtr[1];
          destPtr[10] = pointPtr[2];
          lastComponentPtr = pointPtr + 3;
          pointPtr = pointPtr + vstride;
          destPtr[0xb] = *lastComponentPtr;
          destPtr = destPtr + 4;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2IndexfLoad @ 0xe05f4 (192 bytes) */
void _gleMap2IndexfLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int ustride,int uorder,undefined4 unusedArg6,undefined4 unusedArg7,int vstride,int vorder,int points,int *mapData,float u1,float u2,float v1,float v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int iVar1;
  float invUDelta;
  float one;
  int *piVar4;
  int uIndex;
  int uElementOffset;
  int *pointPtr;
  int destRecord;
  int vRemaining;
  
  one = FLOAT_00108e54;
  uIndex = 0;
  invUDelta = FLOAT_00108e54 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  mapData[6] = (int)GH_F2U(invUDelta);
  mapData[7] = (int)GH_F2U((one / (v2 - v1)));
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        pointPtr = (int *)(uElementOffset * 4 + points);
        piVar4 = mapData + destRecord + 8;
        vRemaining = vorder;
        do {
          iVar1 = *pointPtr;
          pointPtr = pointPtr + vstride;
          *piVar4 = iVar1;
          piVar4 = piVar4 + 1;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2NormalfLoad @ 0xe06b4 (204 bytes) */
void _gleMap2NormalfLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int ustride,int uorder,undefined4 unusedArg6,undefined4 unusedArg7,int vstride,int vorder,int points,int *mapData,float u1,float u2,float v1,float v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int *lastComponentPtr;
  float invUDelta;
  float one;
  int *pointPtr;
  int uIndex;
  int uElementOffset;
  int *destPtr;
  int destRecord;
  int vRemaining;
  
  one = FLOAT_00108e54;
  uIndex = 0;
  invUDelta = FLOAT_00108e54 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  mapData[6] = (int)GH_F2U(invUDelta);
  mapData[7] = (int)GH_F2U((one / (v2 - v1)));
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        pointPtr = (int *)(uElementOffset * 4 + points);
        destPtr = mapData + destRecord * 3;
        vRemaining = vorder;
        do {
          destPtr[8] = *pointPtr;
          destPtr[9] = pointPtr[1];
          lastComponentPtr = pointPtr + 2;
          pointPtr = pointPtr + vstride;
          destPtr[10] = *lastComponentPtr;
          destPtr = destPtr + 3;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2Texture1fLoad @ 0xe0780 (192 bytes) */
void _gleMap2Texture1fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int ustride,int uorder,undefined4 unusedArg6,undefined4 unusedArg7,int vstride,int vorder,int points,int *mapData,float u1,float u2,float v1,float v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int iVar1;
  float invUDelta;
  float one;
  int *piVar4;
  int uIndex;
  int uElementOffset;
  int *pointPtr;
  int destRecord;
  int vRemaining;
  
  one = FLOAT_00108e54;
  uIndex = 0;
  invUDelta = FLOAT_00108e54 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  mapData[6] = (int)GH_F2U(invUDelta);
  mapData[7] = (int)GH_F2U((one / (v2 - v1)));
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        pointPtr = (int *)(uElementOffset * 4 + points);
        piVar4 = mapData + destRecord + 8;
        vRemaining = vorder;
        do {
          iVar1 = *pointPtr;
          pointPtr = pointPtr + vstride;
          *piVar4 = iVar1;
          piVar4 = piVar4 + 1;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2Texture2fLoad @ 0xe0840 (216 bytes) */
void _gleMap2Texture2fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int ustride,int uorder,undefined4 unusedArg6,undefined4 unusedArg7,int vstride,int vorder,int points,int *mapData,float u1,float u2,float v1,float v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int iVar1;
  int *piVar2;
  float invUDelta;
  float one;
  int iVar5;
  int *destPtr;
  int uElementOffset;
  int destRecord;
  int uIndex;
  int iVar10;
  int *piVar11;
  int vRemaining;
  
  one = FLOAT_00108e54;
  uIndex = 0;
  invUDelta = FLOAT_00108e54 / (u2 - u1);
  uElementOffset = 0;
  *mapData = uorder;
  mapData[1] = vorder;
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  mapData[6] = (int)GH_F2U(invUDelta);
  mapData[7] = (int)GH_F2U((one / (v2 - v1)));
  if (0 < uorder) {
    destRecord = 0;
    iVar10 = points;
    do {
      if (0 < vorder) {
        destPtr = mapData + destRecord * 2;
        piVar11 = (int *)(iVar10 + 4);
        iVar5 = uElementOffset << 2;
        vRemaining = vorder;
        do {
          piVar2 = (int *)(points + iVar5);
          iVar5 = iVar5 + vstride * 4;
          destPtr[8] = *piVar2;
          iVar1 = *piVar11;
          piVar11 = piVar11 + vstride;
          destPtr[9] = iVar1;
          destPtr = destPtr + 2;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      iVar10 = iVar10 + ustride * 4;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2Texture3fLoad @ 0xe0918 (204 bytes) */
void _gleMap2Texture3fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int ustride,int uorder,undefined4 unusedArg6,undefined4 unusedArg7,int vstride,int vorder,int points,int *mapData,float u1,float u2,float v1,float v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int *lastComponentPtr;
  float invUDelta;
  float one;
  int *pointPtr;
  int uIndex;
  int uElementOffset;
  int *destPtr;
  int destRecord;
  int vRemaining;
  
  one = FLOAT_00108e54;
  uIndex = 0;
  invUDelta = FLOAT_00108e54 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  mapData[6] = (int)GH_F2U(invUDelta);
  mapData[7] = (int)GH_F2U((one / (v2 - v1)));
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        pointPtr = (int *)(uElementOffset * 4 + points);
        destPtr = mapData + destRecord * 3;
        vRemaining = vorder;
        do {
          destPtr[8] = *pointPtr;
          destPtr[9] = pointPtr[1];
          lastComponentPtr = pointPtr + 2;
          pointPtr = pointPtr + vstride;
          destPtr[10] = *lastComponentPtr;
          destPtr = destPtr + 3;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2Texture4fLoad @ 0xe09e4 (212 bytes) */
void _gleMap2Texture4fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int ustride,int uorder,undefined4 unusedArg6,undefined4 unusedArg7,int vstride,int vorder,int points,int *mapData,float u1,float u2,float v1,float v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int *lastComponentPtr;
  float invUDelta;
  float one;
  int *pointPtr;
  int uIndex;
  int uElementOffset;
  int *destPtr;
  int destRecord;
  int vRemaining;
  
  one = FLOAT_00108e54;
  uIndex = 0;
  invUDelta = FLOAT_00108e54 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  mapData[6] = (int)GH_F2U(invUDelta);
  mapData[7] = (int)GH_F2U((one / (v2 - v1)));
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        destPtr = mapData + destRecord * 4;
        pointPtr = (int *)(uElementOffset * 4 + points);
        vRemaining = vorder;
        do {
          destPtr[8] = *pointPtr;
          destPtr[9] = pointPtr[1];
          destPtr[10] = pointPtr[2];
          lastComponentPtr = pointPtr + 3;
          pointPtr = pointPtr + vstride;
          destPtr[0xb] = *lastComponentPtr;
          destPtr = destPtr + 4;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2VertexAttrib1fLoad @ 0xe0ab8 (192 bytes) */
void _gleMap2VertexAttrib1fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int ustride,int uorder,undefined4 unusedArg6,undefined4 unusedArg7,int vstride,int vorder,int points,int *mapData,float u1,float u2,float v1,float v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int iVar1;
  float invUDelta;
  float one;
  int *piVar4;
  int uIndex;
  int uElementOffset;
  int *pointPtr;
  int destRecord;
  int vRemaining;
  
  one = FLOAT_00108e54;
  uIndex = 0;
  invUDelta = FLOAT_00108e54 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  mapData[6] = (int)GH_F2U(invUDelta);
  mapData[7] = (int)GH_F2U((one / (v2 - v1)));
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        pointPtr = (int *)(uElementOffset * 4 + points);
        piVar4 = mapData + destRecord + 8;
        vRemaining = vorder;
        do {
          iVar1 = *pointPtr;
          pointPtr = pointPtr + vstride;
          *piVar4 = iVar1;
          piVar4 = piVar4 + 1;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2VertexAttrib2fLoad @ 0xe0b78 (216 bytes) */
void _gleMap2VertexAttrib2fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int ustride,int uorder,undefined4 unusedArg6,undefined4 unusedArg7,int vstride,int vorder,int points,int *mapData,float u1,float u2,float v1,float v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int iVar1;
  int *piVar2;
  float invUDelta;
  float one;
  int iVar5;
  int *destPtr;
  int uElementOffset;
  int destRecord;
  int uIndex;
  int iVar10;
  int *piVar11;
  int vRemaining;
  
  one = FLOAT_00108e54;
  uIndex = 0;
  invUDelta = FLOAT_00108e54 / (u2 - u1);
  uElementOffset = 0;
  *mapData = uorder;
  mapData[1] = vorder;
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  mapData[6] = (int)GH_F2U(invUDelta);
  mapData[7] = (int)GH_F2U((one / (v2 - v1)));
  if (0 < uorder) {
    destRecord = 0;
    iVar10 = points;
    do {
      if (0 < vorder) {
        destPtr = mapData + destRecord * 2;
        piVar11 = (int *)(iVar10 + 4);
        iVar5 = uElementOffset << 2;
        vRemaining = vorder;
        do {
          piVar2 = (int *)(points + iVar5);
          iVar5 = iVar5 + vstride * 4;
          destPtr[8] = *piVar2;
          iVar1 = *piVar11;
          piVar11 = piVar11 + vstride;
          destPtr[9] = iVar1;
          destPtr = destPtr + 2;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      iVar10 = iVar10 + ustride * 4;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2VertexAttrib3fLoad @ 0xe0c50 (204 bytes) */
void _gleMap2VertexAttrib3fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int ustride,int uorder,undefined4 unusedArg6,undefined4 unusedArg7,int vstride,int vorder,int points,int *mapData,float u1,float u2,float v1,float v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int *lastComponentPtr;
  float invUDelta;
  float one;
  int *pointPtr;
  int uIndex;
  int uElementOffset;
  int *destPtr;
  int destRecord;
  int vRemaining;
  
  one = FLOAT_00108e54;
  uIndex = 0;
  invUDelta = FLOAT_00108e54 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  mapData[6] = (int)GH_F2U(invUDelta);
  mapData[7] = (int)GH_F2U((one / (v2 - v1)));
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        pointPtr = (int *)(uElementOffset * 4 + points);
        destPtr = mapData + destRecord * 3;
        vRemaining = vorder;
        do {
          destPtr[8] = *pointPtr;
          destPtr[9] = pointPtr[1];
          lastComponentPtr = pointPtr + 2;
          pointPtr = pointPtr + vstride;
          destPtr[10] = *lastComponentPtr;
          destPtr = destPtr + 3;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleMap2VertexAttrib4fLoad @ 0xe0d1c (212 bytes) */
void _gleMap2VertexAttrib4fLoad(undefined4 unusedArg1,undefined4 unusedArg2,undefined4 unusedArg3,int ustride,int uorder,undefined4 unusedArg6,undefined4 unusedArg7,int vstride,int vorder,int points,int *mapData,float u1,float u2,float v1,float v2,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int *lastComponentPtr;
  float invUDelta;
  float one;
  int *pointPtr;
  int uIndex;
  int uElementOffset;
  int *destPtr;
  int destRecord;
  int vRemaining;
  
  one = FLOAT_00108e54;
  uIndex = 0;
  invUDelta = FLOAT_00108e54 / (u2 - u1);
  *mapData = uorder;
  uElementOffset = 0;
  mapData[1] = vorder;
  mapData[2] = (int)GH_F2U((float)u1);
  mapData[3] = (int)GH_F2U((float)u2);
  mapData[4] = (int)GH_F2U((float)v1);
  mapData[5] = (int)GH_F2U((float)v2);
  mapData[6] = (int)GH_F2U(invUDelta);
  mapData[7] = (int)GH_F2U((one / (v2 - v1)));
  if (0 < uorder) {
    destRecord = 0;
    do {
      if (0 < vorder) {
        destPtr = mapData + destRecord * 4;
        pointPtr = (int *)(uElementOffset * 4 + points);
        vRemaining = vorder;
        do {
          destPtr[8] = *pointPtr;
          destPtr[9] = pointPtr[1];
          destPtr[10] = pointPtr[2];
          lastComponentPtr = pointPtr + 3;
          pointPtr = pointPtr + vstride;
          destPtr[0xb] = *lastComponentPtr;
          destPtr = destPtr + 4;
          vRemaining = vRemaining + -1;
        } while (vRemaining != 0);
      }
      uIndex = uIndex + 1;
      destRecord = destRecord + vorder;
      uElementOffset = uElementOffset + ustride;
    } while (uIndex < uorder);
  }
  return;
}

/* _gleEvalMap2 @ 0xe0df0 (1504 bytes) */
void _gleEvalMap2(int glContext,float floatArg1,float floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  byte attribByteSize;
  byte slotByteSize;
  float uNormalized;
  float vNormalized;
  undefined *vectorNormalize;
  undefined4 uorder;
  undefined4 hookResult;
  int selectedPoints;
  undefined4 vorder;
  undefined4 incomingR7;
  undefined4 incomingR8;
  undefined4 components;
  int outputEnd;
  float *outStart;
  float *nextOut;
  float *out;
  int mapDataThenPoints;
  int controlPointsThenSlotPointsFor4Components;
  int slotPointsFor2Components;
  int slotPointsFor3Components;
  int slotPointsFor1Component;
  uint flagsUpdated;
  uint slotMask;
  int slotMapCursor;
  byte *sizeCursor;
  float slotUNormalized;
  float lastUNormalized;
  float slotVNormalized;
  float lastVNormalized;
  double incomingFpr9;
  double incomingFpr10;
  float lastVOffset3;
  float lastVOffset4;
  double incomingStack_ffffff48;
  double incomingStack_ffffff50;
  double incomingStack_ffffff58;
  double incomingStack_ffffff60;
  double incomingStack_ffffff68;
  float deriv1X;
  float deriv1Y;
  float deriv1Z;
  float deriv2X;
  float deriv2Y;
  float deriv2Z;
  
  mapDataThenPoints = *(int *)(glContext + 0x7450);
  if (*(short *)(glContext + 0x4a10) < 0) {
    return;
  }
  outputEnd = *(int *)(glContext + 0x4858);
  if (outputEnd == *(int *)(glContext + 0x485c)) {
    (**(code **)(glContext + 0x4a0c))(glContext);
    outputEnd = *(int *)(glContext + 0x4858);
  }
  outStart = *(float **)(glContext + 0x4860);
  out = outStart;
  if (*(char *)(glContext + 0x7555) != '\0') {
    if (*(char *)(glContext + 0x74f2) == '\0') {
      ((void (*)())_gleEvalDomain2Coord)(glContext,mapDataThenPoints + 0xfc8,*(undefined4 *)(mapDataThenPoints + 0xfa8),
                 *(undefined4 *)(mapDataThenPoints + 0xfac),incomingR7,incomingR8,3,outStart,
                 (double)((floatArg1 - *(float *)(mapDataThenPoints + 0xfb0)) *
                         *(float *)(mapDataThenPoints + 0xfc0)),
                 (double)((floatArg2 - *(float *)(mapDataThenPoints + 0xfb8)) *
                         *(float *)(mapDataThenPoints + 0xfc4)),floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,
                 floatArg8,incomingStack_ffffff48,incomingStack_ffffff50,incomingStack_ffffff58,incomingStack_ffffff60,
                 incomingStack_ffffff68);
    }
    out = outStart + 3;
  }
  if (*(char *)(glContext + 0x7556) != '\0') {
    ((void (*)())_gleEvalDomain2Color)(glContext,mapDataThenPoints + 0x1498,*(undefined4 *)(mapDataThenPoints + 0x1478),
               *(undefined4 *)(mapDataThenPoints + 0x147c),incomingR7,incomingR8,4,out,
               (double)((floatArg1 - *(float *)(mapDataThenPoints + 0x1480)) *
                       *(float *)(mapDataThenPoints + 0x1490)),
               (double)((floatArg2 - *(float *)(mapDataThenPoints + 0x1488)) *
                       *(float *)(mapDataThenPoints + 0x1494)),floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,
               floatArg8,incomingStack_ffffff48,incomingStack_ffffff50,incomingStack_ffffff58,incomingStack_ffffff60,
               incomingStack_ffffff68);
    if (*(char *)(glContext + 0x4df8) != '\0') {
      (**(code **)(glContext + 0x4de0))(glContext,out);
    }
    out = out + 4;
  }
  attribByteSize = *(byte *)(glContext + 0x755c);
  if (attribByteSize == 8) {
    uorder = *(undefined4 *)(mapDataThenPoints + 0x1e38);
    controlPointsThenSlotPointsFor4Components = mapDataThenPoints + 0x1e58;
    uNormalized = (floatArg1 - *(float *)(mapDataThenPoints + 0x1e40)) * *(float *)(mapDataThenPoints + 0x1e50);
    vorder = *(undefined4 *)(mapDataThenPoints + 0x1e3c);
    vNormalized = (floatArg2 - *(float *)(mapDataThenPoints + 0x1e48)) * *(float *)(mapDataThenPoints + 0x1e54);
    components = 2;
    nextOut = out + 2;
LAB_000e105c:
    ((void (*)())_gleEvalDomain2Coord)(glContext,controlPointsThenSlotPointsFor4Components,uorder,vorder,incomingR7,incomingR8,components,out,(double)uNormalized,(double)vNormalized,
               floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8,incomingStack_ffffff48,
               incomingStack_ffffff50,incomingStack_ffffff58,incomingStack_ffffff60,incomingStack_ffffff68);
    out = nextOut;
  }
  else if (attribByteSize < 9) {
    if (attribByteSize == 4) {
      uorder = *(undefined4 *)(mapDataThenPoints + 0x1c88);
      controlPointsThenSlotPointsFor4Components = mapDataThenPoints + 0x1ca8;
      uNormalized = (floatArg1 - *(float *)(mapDataThenPoints + 0x1c90)) * *(float *)(mapDataThenPoints + 0x1ca0);
      vorder = *(undefined4 *)(mapDataThenPoints + 0x1c8c);
      vNormalized = (floatArg2 - *(float *)(mapDataThenPoints + 0x1c98)) * *(float *)(mapDataThenPoints + 0x1ca4);
      components = 1;
      nextOut = out + 1;
      goto LAB_000e105c;
    }
  }
  else {
    if (attribByteSize == 0xc) {
      nextOut = out + 3;
      ((void (*)())_gleEvalDomain2Coord)(glContext,mapDataThenPoints + 0x2198,*(undefined4 *)(mapDataThenPoints + 0x2178),
                 *(undefined4 *)(mapDataThenPoints + 0x217c),incomingR7,incomingR8,3,out,
                 (double)((floatArg1 - *(float *)(mapDataThenPoints + 0x2180)) *
                         *(float *)(mapDataThenPoints + 0x2190)),
                 (double)((floatArg2 - *(float *)(mapDataThenPoints + 0x2188)) *
                         *(float *)(mapDataThenPoints + 0x2194)),floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,
                 floatArg8,incomingStack_ffffff48,incomingStack_ffffff50,incomingStack_ffffff58,incomingStack_ffffff60,
                 incomingStack_ffffff68);
      flagsUpdated = *(uint *)(glContext + 0x486c) | 1;
    }
    else {
      if (attribByteSize != 0x10) goto LAB_000e1060;
      nextOut = out + 4;
      ((void (*)())_gleEvalDomain2Coord)(glContext,mapDataThenPoints + 0x2668,*(undefined4 *)(mapDataThenPoints + 0x2648),
                 *(undefined4 *)(mapDataThenPoints + 0x264c),incomingR7,incomingR8,4,out,
                 (double)((floatArg1 - *(float *)(mapDataThenPoints + 0x2650)) *
                         *(float *)(mapDataThenPoints + 0x2660)),
                 (double)((floatArg2 - *(float *)(mapDataThenPoints + 0x2658)) *
                         *(float *)(mapDataThenPoints + 0x2664)),floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,
                 floatArg8,incomingStack_ffffff48,incomingStack_ffffff50,incomingStack_ffffff58,incomingStack_ffffff60,
                 incomingStack_ffffff68);
      flagsUpdated = *(uint *)(glContext + 0x486c) | 3;
    }
    *(uint *)(glContext + 0x486c) = flagsUpdated;
    out = nextOut;
  }
LAB_000e1060:
  slotMask = *(uint *)(glContext + 0x74dc);
  if (slotMask != 0) {
    slotPointsFor3Components = mapDataThenPoints + 0x37c8;
    sizeCursor = (byte *)(glContext + 0x7564);
    controlPointsThenSlotPointsFor4Components = slotPointsFor3Components;
    slotPointsFor2Components = slotPointsFor3Components;
    slotPointsFor1Component = slotPointsFor3Components;
    slotMapCursor = mapDataThenPoints;
    do {
      slotByteSize = *sizeCursor;
      sizeCursor = sizeCursor + 1;
      if (slotByteSize == 8) {
        uorder = *(undefined4 *)(slotMapCursor + 0x37a8);
        slotUNormalized = (double)((floatArg1 - *(float *)(slotMapCursor + 0x37b0)) *
                         *(float *)(slotMapCursor + 0x37c0));
        vorder = *(undefined4 *)(slotMapCursor + 0x37ac);
        slotVNormalized = (double)((floatArg2 - *(float *)(slotMapCursor + 0x37b8)) *
                         *(float *)(slotMapCursor + 0x37c4));
        components = 2;
        nextOut = out + 2;
        selectedPoints = slotPointsFor2Components;
LAB_000e11b0:
        ((void (*)())_gleEvalDomain2Coord)(glContext,selectedPoints,uorder,vorder,incomingR7,incomingR8,components,out,(double)slotUNormalized,(double)slotVNormalized,floatArg3,
                   floatArg4,floatArg5,floatArg6,floatArg7,floatArg8,incomingStack_ffffff48,incomingStack_ffffff50,
                   incomingStack_ffffff58,incomingStack_ffffff60,incomingStack_ffffff68);
        out = nextOut;
      }
      else {
        if (8 < slotByteSize) {
          if (slotByteSize == 0xc) {
            uorder = *(undefined4 *)(slotMapCursor + 0x37a8);
            slotUNormalized = (double)((floatArg1 - *(float *)(slotMapCursor + 0x37b0)) *
                             *(float *)(slotMapCursor + 0x37c0));
            vorder = *(undefined4 *)(slotMapCursor + 0x37ac);
            slotVNormalized = (double)((floatArg2 - *(float *)(slotMapCursor + 0x37b8)) *
                             *(float *)(slotMapCursor + 0x37c4));
            components = 3;
            nextOut = out + 3;
            selectedPoints = slotPointsFor3Components;
          }
          else {
            if (slotByteSize != 0x10) goto LAB_000e11b4;
            uorder = *(undefined4 *)(slotMapCursor + 0x37a8);
            slotUNormalized = (double)((floatArg1 - *(float *)(slotMapCursor + 0x37b0)) *
                             *(float *)(slotMapCursor + 0x37c0));
            vorder = *(undefined4 *)(slotMapCursor + 0x37ac);
            slotVNormalized = (double)((floatArg2 - *(float *)(slotMapCursor + 0x37b8)) *
                             *(float *)(slotMapCursor + 0x37c4));
            components = 4;
            nextOut = out + 4;
            selectedPoints = controlPointsThenSlotPointsFor4Components;
          }
          goto LAB_000e11b0;
        }
        if (slotByteSize == 4) {
          uorder = *(undefined4 *)(slotMapCursor + 0x37a8);
          slotUNormalized = (double)((floatArg1 - *(float *)(slotMapCursor + 0x37b0)) *
                           *(float *)(slotMapCursor + 0x37c0));
          vorder = *(undefined4 *)(slotMapCursor + 0x37ac);
          slotVNormalized = (double)((floatArg2 - *(float *)(slotMapCursor + 0x37b8)) *
                           *(float *)(slotMapCursor + 0x37c4));
          components = 1;
          nextOut = out + 1;
          selectedPoints = slotPointsFor1Component;
          goto LAB_000e11b0;
        }
      }
LAB_000e11b4:
      slotMask = slotMask >> 1;
      controlPointsThenSlotPointsFor4Components = controlPointsThenSlotPointsFor4Components + 0x660;
      slotPointsFor3Components = slotPointsFor3Components + 0x660;
      slotPointsFor2Components = slotPointsFor2Components + 0x660;
      slotMapCursor = slotMapCursor + 0x660;
      slotPointsFor1Component = slotPointsFor1Component + 0x660;
    } while (slotMask != 0);
  }
  if (*(char *)(glContext + 0x7554) == '\f') {
    lastVOffset3 = (double)(floatArg2 - *(float *)(mapDataThenPoints + 0x488));
    lastUNormalized = (double)((floatArg1 - *(float *)(mapDataThenPoints + 0x480)) * *(float *)(mapDataThenPoints + 0x490));
    lastVNormalized = (double)(lastVOffset3 * *(float *)(mapDataThenPoints + 0x494));
    if (*(char *)(glContext + 0x74f2) == '\0') {
      vorder = *(undefined4 *)(mapDataThenPoints + 0x47c);
      uorder = *(undefined4 *)(mapDataThenPoints + 0x478);
      mapDataThenPoints = mapDataThenPoints + 0x498;
      components = 3;
LAB_000e1350:
      ((void (*)())_gleEvalDomain2Coord)(glContext,mapDataThenPoints,uorder,vorder,incomingR7,incomingR8,components,out,(double)lastUNormalized,(double)lastVNormalized,floatArg3,
                 floatArg4,floatArg5,floatArg6,floatArg7,floatArg8,incomingStack_ffffff48,incomingStack_ffffff50,
                 incomingStack_ffffff58,incomingStack_ffffff60,incomingStack_ffffff68);
      goto LAB_000e1388;
    }
    ((void (*)())_gleEvalDomainDeriv2Coord)(glContext,mapDataThenPoints + 0x498,*(undefined4 *)(mapDataThenPoints + 0x478),
               *(undefined4 *)(mapDataThenPoints + 0x47c),incomingR7,incomingR8,3,&deriv1X,&deriv2X,out,(double)lastUNormalized,
               (double)lastVNormalized,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8,incomingFpr9,incomingFpr10,
               (double)*(float *)(mapDataThenPoints + 0x494),(double)*(float *)(mapDataThenPoints + 0x490),(double)lastVOffset3);
  }
  else {
    if (*(char *)(glContext + 0x7554) != '\x10') {
      if ((*(char *)(glContext + 0x4664) == '\0') || (*(char *)(glContext + 0x7564) == '\0')) {
        if (*(int *)(glContext + 0x5434) == 0) {
          return;
        }
        if (*(char *)(glContext + 0x7564) == '\0') {
          return;
        }
      }
      goto LAB_000e1388;
    }
    lastVOffset4 = (double)(floatArg2 - *(float *)(mapDataThenPoints + 0x958));
    lastUNormalized = (double)((floatArg1 - *(float *)(mapDataThenPoints + 0x950)) * *(float *)(mapDataThenPoints + 0x960));
    lastVNormalized = (double)(lastVOffset4 * *(float *)(mapDataThenPoints + 0x964));
    if (*(char *)(glContext + 0x74f2) == '\0') {
      vorder = *(undefined4 *)(mapDataThenPoints + 0x94c);
      uorder = *(undefined4 *)(mapDataThenPoints + 0x948);
      mapDataThenPoints = mapDataThenPoints + 0x968;
      components = 4;
      goto LAB_000e1350;
    }
    ((void (*)())_gleEvalDomainDeriv2Coord)(glContext,mapDataThenPoints + 0x968,*(undefined4 *)(mapDataThenPoints + 0x948),
               *(undefined4 *)(mapDataThenPoints + 0x94c),incomingR7,incomingR8,4,&deriv1X,&deriv2X,out,(double)lastUNormalized,
               (double)lastVNormalized,floatArg3,floatArg4,floatArg5,floatArg6,floatArg7,floatArg8,incomingFpr9,incomingFpr10,
               (double)*(float *)(mapDataThenPoints + 0x964),(double)*(float *)(mapDataThenPoints + 0x960),(double)lastVOffset4);
    ((void (*)())_gleComputeFirstPartial)(glContext,out,&deriv1X,&deriv2X);
  }
  vectorNormalize = PTR__gleVectorNormalize_00112064;
  *outStart = deriv1Y * deriv2Z - deriv1Z * deriv2Y;
  outStart[1] = deriv1Z * deriv2X - deriv1X * deriv2Z;
  outStart[2] = deriv1X * deriv2Y - deriv1Y * deriv2X;
  (**(code **)vectorNormalize)(glContext,outStart,outStart);
LAB_000e1388:
  *(int *)(glContext + 0x48ec) = glContext + 0x7548;
  hookResult = (**(code **)(glContext + 0x489c))(glContext,*(undefined4 *)(glContext + 0x4860),outputEnd);
  *(undefined4 *)(glContext + 0x48ec) = 0;
  *(undefined4 *)(glContext + 0x4858) = hookResult;
  return;
}

/* _gleFreeQueryObject @ 0xe13d0 (128 bytes) */
void _gleFreeQueryObject(glContext, queryObject)
  int glContext;
  int queryObject;
{
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  int rendererRecordCursor;
  int loopIndex;
  int rendererQuerySlot;
  
  rendererRecordCursor = glContext + 0x10000;
  loopIndex = 0;
  rendererQuerySlot = queryObject;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
      loopIndex = loopIndex + 1;
      rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
      rendererRecordCursor = rendererRecordCursor + 0x2e0;
      (**(code **)(*rendererCallbacks + 0x1cc))(*rendererHandlePtr,*(undefined4 *)(rendererQuerySlot + 0x10));
      *(undefined4 *)(rendererQuerySlot + 0x10) = 0;
      rendererQuerySlot = rendererQuerySlot + 4;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  _free(queryObject);
  return;
}

/* _gleCreateQueryObject @ 0xe1450 (200 bytes) */
int _gleCreateQueryObject(glContext, id)
  int glContext;
  undefined4 id;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined *freeQueryObject;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  puVar5 = (undefined4 *)_malloc(0x30);
  freeQueryObject = PTR__gleFreeQueryObject_00110e8c;
  puVar5[2] = 1;
  puVar5[3] = freeQueryObject;
  puVar5[1] = id;
  puVar4 = puVar5 + 4;
  *puVar5 = 0;
  iVar7 = 8;
  do {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = glContext + 0x10000;
  iVar6 = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    puVar4 = puVar5 + 4;
    do {
      piVar1 = (int *)(iVar7 + -0x777c);
      puVar2 = (undefined4 *)(iVar7 + -0x7a54);
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 0x2e0;
      (**(code **)(*piVar1 + 0x1c8))(*puVar2,puVar4);
      puVar4 = puVar4 + 1;
    } while (iVar6 < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return puVar5;
}

/* _pow_10 @ 0xe1518 (156 bytes) */
double _pow_10(int param_1)
{
  undefined *puVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108d68;
  if (param_1 < 1) {
    if (-1 < param_1) {
      return DOUBLE_00108d68;
    }
    for (; param_1 < -0x20; param_1 = param_1 + 0x20) {
      dVar2 = dVar2 * DOUBLE_00108df8;
    }
    puVar1 = &_down_1 + param_1 * -8;
  }
  else {
    for (; 0x20 < param_1; param_1 = param_1 + -0x20) {
      dVar2 = dVar2 * DOUBLE_00108e00;
    }
    puVar1 = &_up_0 + param_1 * 8;
  }
  return dVar2 * *(double *)(puVar1 + -8);
}

/* _gle_strtod @ 0xe15b4 (824 bytes) */
double _gle_strtod(byte *textCursor,undefined4 *endPtrOut)
{
  bool atDecimalPoint;
  bool parsedDigits;
  bool negativeExponent;
  bool negative;
  int integerDigitsLeft;
  int exponentDigitsLeft;
  byte currentChar;
  byte *integerCursor;
  byte *exponentSignCursor;
  byte *fractionCursor;
  byte *fractionStart;
  byte *exponentCursor;
  double value;
  double integerPlace;
  double exponentThenScale;
  double fractionValue;
  double exponentPlace;
  byte *pbStack00000018;
  
  negative = false;
  negativeExponent = false;
  parsedDigits = false;
  if (*textCursor == 0x2b) {
LAB_000e1614:
    textCursor = textCursor + 1;
  }
  else if (*textCursor == 0x2d) {
    negative = true;
    goto LAB_000e1614;
  }
  currentChar = *textCursor;
  atDecimalPoint = currentChar == 0x2e;
  pbStack00000018 = textCursor;
  value = DOUBLE_00108d60;
  if (currentChar == 0) {
LAB_000e16f8:
    if (atDecimalPoint) goto LAB_000e16fc;
  }
  else {
    if (!atDecimalPoint) {
      if ((currentChar != 0x65) && (integerCursor = textCursor, currentChar != 0x45)) {
        while (currentChar - 0x30 < 10) {
          currentChar = integerCursor[1];
          integerCursor = integerCursor + 1;
        }
        if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
          pbStack00000018 = integerCursor;
        }
        integerCursor = integerCursor + -1;
        if (textCursor <= integerCursor) {
          integerDigitsLeft = (int)integerCursor - (int)(textCursor + -1);
          integerPlace = DOUBLE_00108d68;
          do {
            currentChar = *integerCursor;
            integerCursor = integerCursor + -1;
            value = ((double)CONCAT44(0x43300000,(int)(char)currentChar - 0x30U ^ 0x80000000) -
                    DOUBLE_00108d58) * integerPlace + value;
            integerPlace = integerPlace * DOUBLE_00108e10;
            integerDigitsLeft = integerDigitsLeft + -1;
          } while (integerDigitsLeft != 0);
        }
        currentChar = *pbStack00000018;
        parsedDigits = true;
        atDecimalPoint = currentChar == 0x2e;
      }
      goto LAB_000e16f8;
    }
LAB_000e16fc:
    fractionStart = pbStack00000018 + 1;
    currentChar = pbStack00000018[1];
    fractionCursor = fractionStart;
    while (currentChar - 0x30 < 10) {
      fractionCursor = fractionCursor + 1;
      currentChar = *fractionCursor;
    }
    fractionValue = DOUBLE_00108d60;
    if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
      pbStack00000018 = fractionCursor;
    }
    while (fractionCursor = fractionCursor + -1, fractionStart <= fractionCursor) {
      fractionValue = fractionValue * DOUBLE_00108e08 +
               (((double)CONCAT44(0x43300000,(int)(char)*fractionCursor - 0x30U ^ 0x80000000) -
               DOUBLE_00108d58));
    }
    parsedDigits = true;
    currentChar = *pbStack00000018;
    value = fractionValue * DOUBLE_00108e08 + value;
  }
  if ((!parsedDigits) || ((currentChar != 0x65 && (currentChar != 0x45)))) goto LAB_000e18b8;
  exponentSignCursor = pbStack00000018 + 1;
  if (*exponentSignCursor == 0x2b) {
LAB_000e17ec:
    exponentSignCursor = pbStack00000018 + 2;
  }
  else if (*exponentSignCursor == 0x2d) {
    negativeExponent = true;
    goto LAB_000e17ec;
  }
  currentChar = *exponentSignCursor;
  exponentCursor = exponentSignCursor;
  while (currentChar - 0x30 < 10) {
    exponentCursor = exponentCursor + 1;
    currentChar = *exponentCursor;
  }
  pbStack00000018 = exponentSignCursor;
  if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
    pbStack00000018 = exponentCursor;
  }
  exponentCursor = exponentCursor + -1;
  exponentThenScale = DOUBLE_00108d60;
  if (exponentSignCursor <= exponentCursor) {
    exponentDigitsLeft = (int)exponentCursor - (int)(exponentSignCursor + -1);
    exponentPlace = DOUBLE_00108d68;
    do {
      currentChar = *exponentCursor;
      exponentCursor = exponentCursor + -1;
      exponentThenScale = ((double)CONCAT44(0x43300000,(int)(char)currentChar - 0x30U ^ 0x80000000) - DOUBLE_00108d58
               ) * exponentPlace + exponentThenScale;
      exponentPlace = exponentPlace * DOUBLE_00108e10;
      exponentDigitsLeft = exponentDigitsLeft + -1;
    } while (exponentDigitsLeft != 0);
  }
  if (negativeExponent) {
    exponentThenScale = -exponentThenScale;
  }
  exponentThenScale = (double)((double (*)())_pow_10)((int)exponentThenScale);
  value = value * exponentThenScale;
LAB_000e18b8:
  if (negative) {
    value = -value;
  }
  if (endPtrOut != (undefined4 *)0x0) {
    *endPtrOut = pbStack00000018;
  }
  return value;
}

/* _gle_dtostr @ 0xe18ec (1096 bytes) */
char * _gle_dtostr(undefined4 unusedArg1,undefined4 unusedArg2,char *buffer,uint bufferSize,double value,double tolerance,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  char *exponentWritePtr;
  char *exponentReverseEnd;
  char swapTemp;
  double ten;
  int reverseSpan;
  char *bufferEnd;
  char *writePtr;
  char *reverseRight;
  char *resultPtr;
  char *exponentDigitsStart;
  double doubleZero;
  double scaledValue;
  double pow10OfExponent;
  double decimalExponentRounded;
  double pow10OfNegExponent;
  double fractionDigitValue;
  double integerPartOfValue;
  double oneTenth;
  double scaledTolerance;
  double tenForFraction;
  double integerPartRemaining;
  double integerPartTimesTenth;
  uint exponent [6];
  
  doubleZero = DOUBLE_00108d60;
  bufferEnd = buffer + bufferSize;
  if (tolerance <= DOUBLE_00108d60) {
    tolerance = DOUBLE_00108e18;
  }
  if (bufferSize < 2) {
    return (char *)0x0;
  }
  if (value < DOUBLE_00108d60) {
    value = -value;
    *buffer = '-';
    buffer = buffer + 1;
  }
  scaledTolerance = tolerance;
  if (doubleZero < value) {
    if ((value < DOUBLE_00108e20) || (DOUBLE_00108e30 < value)) {
      _frexp(value,exponent);
      decimalExponentRounded = _round(((double)CONCAT44(0x43300000,exponent[0] ^ 0x80000000) - DOUBLE_00108d58) *
                     DOUBLE_00108e28);
      exponent[0] = (uint)(int)decimalExponentRounded;
      pow10OfExponent = (double)((double (*)())_pow_10)(exponent[0]);
      pow10OfNegExponent = (double)((double (*)())_pow_10)(-exponent[0]);
      scaledTolerance = tolerance * pow10OfExponent;
      scaledValue = value * pow10OfNegExponent;
    }
    else {
      exponent[0] = 0;
      scaledValue = value;
    }
    for (; DOUBLE_00108e10 <= scaledValue + tolerance * DOUBLE_00108dc0; scaledValue = scaledValue * DOUBLE_00108e08) {
      exponent[0] = exponent[0] + 1;
      scaledTolerance = scaledTolerance * DOUBLE_00108e10;
    }
    for (; scaledValue + tolerance * DOUBLE_00108dc0 < DOUBLE_00108d68; scaledValue = scaledValue * DOUBLE_00108e10) {
      exponent[0] = exponent[0] - 1;
      scaledTolerance = scaledTolerance * DOUBLE_00108e08;
    }
    if (3 < (int)(((int)exponent[0] >> 0x1f ^ exponent[0]) - ((int)exponent[0] >> 0x1f)))
    goto LAB_000e1adc;
  }
  exponent[0] = 0;
  scaledValue = value;
  tolerance = scaledTolerance;
LAB_000e1adc:
  scaledValue = tolerance * DOUBLE_00108dc0 + scaledValue;
  integerPartRemaining = _floor(scaledValue);
  ten = DOUBLE_00108e10;
  oneTenth = DOUBLE_00108e08;
  writePtr = buffer;
  while (tolerance < integerPartRemaining) {
    if (writePtr == bufferEnd) {
      return (char *)0x0;
    }
    integerPartTimesTenth = integerPartRemaining * oneTenth;
    integerPartRemaining = _floor(integerPartTimesTenth);
    *writePtr = (char)(int)((integerPartTimesTenth - integerPartRemaining) * ten) + '0';
    writePtr = writePtr + 1;
  }
  if (buffer < writePtr) {
    reverseSpan = (int)writePtr - (int)buffer;
    reverseRight = writePtr;
    while (1 < reverseSpan) {
      reverseRight = reverseRight + -1;
      swapTemp = *reverseRight;
      *reverseRight = *buffer;
      *buffer = swapTemp;
      buffer = buffer + 1;
      reverseSpan = (int)reverseRight - (int)buffer;
    }
  }
  else {
    *writePtr = '0';
    writePtr = writePtr + 1;
  }
  integerPartOfValue = _floor(scaledValue);
  tenForFraction = DOUBLE_00108e10;
  scaledValue = scaledValue - integerPartOfValue;
  if (tolerance < scaledValue) {
    if (writePtr == bufferEnd) {
      return (char *)0x0;
    }
    *writePtr = '.';
    writePtr = writePtr + 1;
    do {
      if (writePtr == bufferEnd) {
        return (char *)0x0;
      }
      scaledValue = scaledValue * tenForFraction;
      tolerance = tolerance * tenForFraction;
      fractionDigitValue = _floor(scaledValue);
      scaledValue = scaledValue - fractionDigitValue;
      *writePtr = (char)(int)fractionDigitValue + '0';
      writePtr = writePtr + 1;
    } while (tolerance < scaledValue);
  }
  else if (exponent[0] == 0) {
    if ((int)bufferEnd - (int)writePtr < 2) {
      return (char *)0x0;
    }
    *writePtr = '.';
    writePtr[1] = '0';
    writePtr = writePtr + 2;
  }
  if (exponent[0] != 0) {
    if ((int)bufferEnd - (int)writePtr < 3) {
      return (char *)0x0;
    }
    *writePtr = 'e';
    exponentDigitsStart = writePtr + 1;
    exponentWritePtr = exponentDigitsStart;
    if ((int)exponent[0] < 0) {
      exponent[0] = -exponent[0];
      *exponentDigitsStart = '-';
      exponentDigitsStart = writePtr + 2;
      exponentWritePtr = exponentDigitsStart;
    }
    while (writePtr = exponentWritePtr, 0 < (int)exponent[0]) {
      if (writePtr == bufferEnd) {
        return (char *)0x0;
      }
      *writePtr = (char)exponent[0] + (char)((int)exponent[0] / 10) * -10 + '0';
      exponent[0] = (int)exponent[0] / 10;
      exponentWritePtr = writePtr + 1;
    }
    reverseSpan = (int)writePtr - (int)exponentDigitsStart;
    exponentReverseEnd = writePtr;
    while (1 < reverseSpan) {
      exponentReverseEnd = exponentReverseEnd + -1;
      swapTemp = *exponentReverseEnd;
      *exponentReverseEnd = *exponentDigitsStart;
      *exponentDigitsStart = swapTemp;
      exponentDigitsStart = exponentDigitsStart + 1;
      reverseSpan = (int)exponentReverseEnd - (int)exponentDigitsStart;
    }
  }
  resultPtr = (char *)0x0;
  if (writePtr != bufferEnd) {
    *writePtr = '\0';
    resultPtr = writePtr;
  }
  return resultPtr;
}

