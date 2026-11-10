#include "decls.h"

/* _gleMap1Vertex4dLoad @ 0xde520 (156 bytes) */
void _gleMap1Vertex4dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,int param_8,int *param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  
  iVar2 = 0;
  dVar4 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_9 = param_7;
  param_9[1] = (int)GH_F2U((float)fparam_1);
  param_9[3] = (int)GH_F2U((float)dVar4);
  param_9[2] = (int)GH_F2U((float)fparam_2);
  if (0 < param_7) {
    do {
      iVar1 = iVar2 * 8;
      iVar2 = iVar2 + param_6;
      iVar3 = iVar1 + param_8;
      param_9[4] = (int)GH_F2U((float)*(double *)(iVar1 + param_8));
      param_9[5] = (int)GH_F2U((float)*(double *)(iVar3 + 8));
      param_9[6] = (int)GH_F2U((float)*(double *)(iVar3 + 0x10));
      param_9[7] = (int)GH_F2U((float)*(double *)(iVar3 + 0x18));
      param_9 = param_9 + 4;
      param_7 = param_7 + -1;
    } while (param_7 != 0);
    return;
  }
  return;
}

/* _gleMap1ColordLoad @ 0xde5bc (156 bytes) */
void _gleMap1ColordLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,int param_8,int *param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  
  iVar2 = 0;
  dVar4 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_9 = param_7;
  param_9[1] = (int)GH_F2U((float)fparam_1);
  param_9[3] = (int)GH_F2U((float)dVar4);
  param_9[2] = (int)GH_F2U((float)fparam_2);
  if (0 < param_7) {
    do {
      iVar1 = iVar2 * 8;
      iVar2 = iVar2 + param_6;
      iVar3 = iVar1 + param_8;
      param_9[4] = (int)GH_F2U((float)*(double *)(iVar1 + param_8));
      param_9[5] = (int)GH_F2U((float)*(double *)(iVar3 + 8));
      param_9[6] = (int)GH_F2U((float)*(double *)(iVar3 + 0x10));
      param_9[7] = (int)GH_F2U((float)*(double *)(iVar3 + 0x18));
      param_9 = param_9 + 4;
      param_7 = param_7 + -1;
    } while (param_7 != 0);
    return;
  }
  return;
}

/* _gleMap1IndexdLoad @ 0xde658 (112 bytes) */
void _gleMap1IndexdLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,double *param_8,int *param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float *pfVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  param_9[1] = (int)GH_F2U((float)fparam_1);
  *param_9 = param_7;
  param_9[2] = (int)GH_F2U((float)fparam_2);
  param_9[3] = (int)GH_F2U((float)dVar2);
  if (param_7 < 1) {
    return;
  }
  pfVar1 = (float *)(param_9 + 4);
  do {
    dVar2 = *param_8;
    param_8 = param_8 + param_6;
    *pfVar1 = (float)dVar2;
    pfVar1 = pfVar1 + 1;
    param_7 = param_7 + -1;
  } while (param_7 != 0);
  return;
}

/* _gleMap1NormaldLoad @ 0xde6c8 (144 bytes) */
void _gleMap1NormaldLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,int param_8,int *param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  
  iVar2 = 0;
  dVar4 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_9 = param_7;
  param_9[1] = (int)GH_F2U((float)fparam_1);
  param_9[3] = (int)GH_F2U((float)dVar4);
  param_9[2] = (int)GH_F2U((float)fparam_2);
  if (0 < param_7) {
    do {
      iVar1 = iVar2 * 8;
      iVar2 = iVar2 + param_6;
      iVar3 = iVar1 + param_8;
      param_9[4] = (int)GH_F2U((float)*(double *)(iVar1 + param_8));
      param_9[5] = (int)GH_F2U((float)*(double *)(iVar3 + 8));
      param_9[6] = (int)GH_F2U((float)*(double *)(iVar3 + 0x10));
      param_9 = param_9 + 3;
      param_7 = param_7 + -1;
    } while (param_7 != 0);
    return;
  }
  return;
}

/* _gleMap1Texture1dLoad @ 0xde758 (112 bytes) */
void _gleMap1Texture1dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,double *param_8,int *param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float *pfVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  param_9[1] = (int)GH_F2U((float)fparam_1);
  *param_9 = param_7;
  param_9[2] = (int)GH_F2U((float)fparam_2);
  param_9[3] = (int)GH_F2U((float)dVar2);
  if (param_7 < 1) {
    return;
  }
  pfVar1 = (float *)(param_9 + 4);
  do {
    dVar2 = *param_8;
    param_8 = param_8 + param_6;
    *pfVar1 = (float)dVar2;
    pfVar1 = pfVar1 + 1;
    param_7 = param_7 + -1;
  } while (param_7 != 0);
  return;
}

/* _gleMap1Texture2dLoad @ 0xde7c8 (120 bytes) */
void _gleMap1Texture2dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,double *param_8,int *param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double *pdVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  param_9[1] = (int)GH_F2U((float)fparam_1);
  *param_9 = param_7;
  param_9[2] = (int)GH_F2U((float)fparam_2);
  param_9[3] = (int)GH_F2U((float)dVar2);
  if (0 < param_7) {
    do {
      param_9[4] = (int)GH_F2U((float)*param_8);
      pdVar1 = param_8 + 1;
      param_8 = param_8 + param_6;
      param_9[5] = (int)GH_F2U((float)*pdVar1);
      param_9 = param_9 + 2;
      param_7 = param_7 + -1;
    } while (param_7 != 0);
    return;
  }
  return;
}

/* _gleMap1Texture3dLoad @ 0xde840 (144 bytes) */
void _gleMap1Texture3dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,int param_8,int *param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  
  iVar2 = 0;
  dVar4 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_9 = param_7;
  param_9[1] = (int)GH_F2U((float)fparam_1);
  param_9[3] = (int)GH_F2U((float)dVar4);
  param_9[2] = (int)GH_F2U((float)fparam_2);
  if (0 < param_7) {
    do {
      iVar1 = iVar2 * 8;
      iVar2 = iVar2 + param_6;
      iVar3 = iVar1 + param_8;
      param_9[4] = (int)GH_F2U((float)*(double *)(iVar1 + param_8));
      param_9[5] = (int)GH_F2U((float)*(double *)(iVar3 + 8));
      param_9[6] = (int)GH_F2U((float)*(double *)(iVar3 + 0x10));
      param_9 = param_9 + 3;
      param_7 = param_7 + -1;
    } while (param_7 != 0);
    return;
  }
  return;
}

/* _gleMap1Texture4dLoad @ 0xde8d0 (156 bytes) */
void _gleMap1Texture4dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,int param_8,int *param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  
  iVar2 = 0;
  dVar4 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_9 = param_7;
  param_9[1] = (int)GH_F2U((float)fparam_1);
  param_9[3] = (int)GH_F2U((float)dVar4);
  param_9[2] = (int)GH_F2U((float)fparam_2);
  if (0 < param_7) {
    do {
      iVar1 = iVar2 * 8;
      iVar2 = iVar2 + param_6;
      iVar3 = iVar1 + param_8;
      param_9[4] = (int)GH_F2U((float)*(double *)(iVar1 + param_8));
      param_9[5] = (int)GH_F2U((float)*(double *)(iVar3 + 8));
      param_9[6] = (int)GH_F2U((float)*(double *)(iVar3 + 0x10));
      param_9[7] = (int)GH_F2U((float)*(double *)(iVar3 + 0x18));
      param_9 = param_9 + 4;
      param_7 = param_7 + -1;
    } while (param_7 != 0);
    return;
  }
  return;
}

/* _gleMap1VertexAttrib1dLoad @ 0xde96c (112 bytes) */
void _gleMap1VertexAttrib1dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,double *param_8,int *param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float *pfVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  param_9[1] = (int)GH_F2U((float)fparam_1);
  *param_9 = param_7;
  param_9[2] = (int)GH_F2U((float)fparam_2);
  param_9[3] = (int)GH_F2U((float)dVar2);
  if (param_7 < 1) {
    return;
  }
  pfVar1 = (float *)(param_9 + 4);
  do {
    dVar2 = *param_8;
    param_8 = param_8 + param_6;
    *pfVar1 = (float)dVar2;
    pfVar1 = pfVar1 + 1;
    param_7 = param_7 + -1;
  } while (param_7 != 0);
  return;
}

/* _gleMap1VertexAttrib2dLoad @ 0xde9dc (120 bytes) */
void _gleMap1VertexAttrib2dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,double *param_8,int *param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double *pdVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  param_9[1] = (int)GH_F2U((float)fparam_1);
  *param_9 = param_7;
  param_9[2] = (int)GH_F2U((float)fparam_2);
  param_9[3] = (int)GH_F2U((float)dVar2);
  if (0 < param_7) {
    do {
      param_9[4] = (int)GH_F2U((float)*param_8);
      pdVar1 = param_8 + 1;
      param_8 = param_8 + param_6;
      param_9[5] = (int)GH_F2U((float)*pdVar1);
      param_9 = param_9 + 2;
      param_7 = param_7 + -1;
    } while (param_7 != 0);
    return;
  }
  return;
}

/* _gleMap1VertexAttrib3dLoad @ 0xdea54 (144 bytes) */
void _gleMap1VertexAttrib3dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,int param_8,int *param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  
  iVar2 = 0;
  dVar4 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_9 = param_7;
  param_9[1] = (int)GH_F2U((float)fparam_1);
  param_9[3] = (int)GH_F2U((float)dVar4);
  param_9[2] = (int)GH_F2U((float)fparam_2);
  if (0 < param_7) {
    do {
      iVar1 = iVar2 * 8;
      iVar2 = iVar2 + param_6;
      iVar3 = iVar1 + param_8;
      param_9[4] = (int)GH_F2U((float)*(double *)(iVar1 + param_8));
      param_9[5] = (int)GH_F2U((float)*(double *)(iVar3 + 8));
      param_9[6] = (int)GH_F2U((float)*(double *)(iVar3 + 0x10));
      param_9 = param_9 + 3;
      param_7 = param_7 + -1;
    } while (param_7 != 0);
    return;
  }
  return;
}

/* _gleMap1VertexAttrib4dLoad @ 0xdeae4 (156 bytes) */
void _gleMap1VertexAttrib4dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,int param_8,int *param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  
  iVar2 = 0;
  dVar4 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_9 = param_7;
  param_9[1] = (int)GH_F2U((float)fparam_1);
  param_9[3] = (int)GH_F2U((float)dVar4);
  param_9[2] = (int)GH_F2U((float)fparam_2);
  if (0 < param_7) {
    do {
      iVar1 = iVar2 * 8;
      iVar2 = iVar2 + param_6;
      iVar3 = iVar1 + param_8;
      param_9[4] = (int)GH_F2U((float)*(double *)(iVar1 + param_8));
      param_9[5] = (int)GH_F2U((float)*(double *)(iVar3 + 8));
      param_9[6] = (int)GH_F2U((float)*(double *)(iVar3 + 0x10));
      param_9[7] = (int)GH_F2U((float)*(double *)(iVar3 + 0x18));
      param_9 = param_9 + 4;
      param_7 = param_7 + -1;
    } while (param_7 != 0);
    return;
  }
  return;
}

/* _gleMap1Vertex3fLoad @ 0xdeb80 (112 bytes) */
int _gleMap1Vertex3fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,int *param_7,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  fVar2 = FLOAT_00108e54;
  iVar3 = 0;
  *param_7 = param_5;
  param_7[1] = (int)GH_F2U((float)fparam_1);
  param_7[2] = (int)GH_F2U((float)fparam_2);
  param_7[3] = (int)GH_F2U((float)((fVar2 / (float)(fparam_2 - fparam_1))));
  if (0 < param_5) {
    do {
      iVar1 = iVar3 * 4;
      iVar3 = iVar3 + param_4;
      iVar4 = iVar1 + param_6;
      param_7[4] = *(int *)(iVar1 + param_6);
      param_7[5] = *(int *)(iVar4 + 4);
      param_7[6] = *(int *)(iVar4 + 8);
      param_7 = param_7 + 3;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    return;
  }
  return;
}

/* _gleMap1Vertex4fLoad @ 0xdebf0 (120 bytes) */
int _gleMap1Vertex4fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,int *param_7,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  fVar2 = FLOAT_00108e54;
  iVar3 = 0;
  *param_7 = param_5;
  param_7[1] = (int)GH_F2U((float)fparam_1);
  param_7[2] = (int)GH_F2U((float)fparam_2);
  param_7[3] = (int)GH_F2U((float)((fVar2 / (float)(fparam_2 - fparam_1))));
  if (0 < param_5) {
    do {
      iVar1 = iVar3 * 4;
      iVar3 = iVar3 + param_4;
      iVar4 = iVar1 + param_6;
      param_7[4] = *(int *)(iVar1 + param_6);
      param_7[5] = *(int *)(iVar4 + 4);
      param_7[6] = *(int *)(iVar4 + 8);
      param_7[7] = *(int *)(iVar4 + 0xc);
      param_7 = param_7 + 4;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    return;
  }
  return;
}

/* _gleMap1ColorfLoad @ 0xdec68 (120 bytes) */
int _gleMap1ColorfLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,int *param_7,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  fVar2 = FLOAT_00108e54;
  iVar3 = 0;
  *param_7 = param_5;
  param_7[1] = (int)GH_F2U((float)fparam_1);
  param_7[2] = (int)GH_F2U((float)fparam_2);
  param_7[3] = (int)GH_F2U((float)((fVar2 / (float)(fparam_2 - fparam_1))));
  if (0 < param_5) {
    do {
      iVar1 = iVar3 * 4;
      iVar3 = iVar3 + param_4;
      iVar4 = iVar1 + param_6;
      param_7[4] = *(int *)(iVar1 + param_6);
      param_7[5] = *(int *)(iVar4 + 4);
      param_7[6] = *(int *)(iVar4 + 8);
      param_7[7] = *(int *)(iVar4 + 0xc);
      param_7 = param_7 + 4;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    return;
  }
  return;
}

/* _gleMap1IndexfLoad @ 0xdece0 (92 bytes) */
int _gleMap1IndexfLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int *param_6,int *param_7,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  float fVar2;
  int *piVar3;
  
  fVar2 = FLOAT_00108e54;
  *param_7 = param_5;
  param_7[1] = (int)GH_F2U((float)fparam_1);
  param_7[2] = (int)GH_F2U((float)fparam_2);
  param_7[3] = (int)GH_F2U((float)((fVar2 / (float)(fparam_2 - fparam_1))));
  if (param_5 < 1) {
    return;
  }
  piVar3 = param_7 + 4;
  do {
    iVar1 = *param_6;
    param_6 = param_6 + param_4;
    *piVar3 = iVar1;
    piVar3 = piVar3 + 1;
    param_5 = param_5 + -1;
  } while (param_5 != 0);
  return;
}

/* _gleMap1NormalfLoad @ 0xded3c (112 bytes) */
int _gleMap1NormalfLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,int *param_7,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  fVar2 = FLOAT_00108e54;
  iVar3 = 0;
  *param_7 = param_5;
  param_7[1] = (int)GH_F2U((float)fparam_1);
  param_7[2] = (int)GH_F2U((float)fparam_2);
  param_7[3] = (int)GH_F2U((float)((fVar2 / (float)(fparam_2 - fparam_1))));
  if (0 < param_5) {
    do {
      iVar1 = iVar3 * 4;
      iVar3 = iVar3 + param_4;
      iVar4 = iVar1 + param_6;
      param_7[4] = *(int *)(iVar1 + param_6);
      param_7[5] = *(int *)(iVar4 + 4);
      param_7[6] = *(int *)(iVar4 + 8);
      param_7 = param_7 + 3;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    return;
  }
  return;
}

/* _gleMap1Texture1fLoad @ 0xdedac (92 bytes) */
int _gleMap1Texture1fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int *param_6,int *param_7,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  float fVar2;
  int *piVar3;
  
  fVar2 = FLOAT_00108e54;
  *param_7 = param_5;
  param_7[1] = (int)GH_F2U((float)fparam_1);
  param_7[2] = (int)GH_F2U((float)fparam_2);
  param_7[3] = (int)GH_F2U((float)((fVar2 / (float)(fparam_2 - fparam_1))));
  if (param_5 < 1) {
    return;
  }
  piVar3 = param_7 + 4;
  do {
    iVar1 = *param_6;
    param_6 = param_6 + param_4;
    *piVar3 = iVar1;
    piVar3 = piVar3 + 1;
    param_5 = param_5 + -1;
  } while (param_5 != 0);
  return;
}

/* _gleMap1Texture2fLoad @ 0xdee08 (96 bytes) */
int _gleMap1Texture2fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int *param_6,int *param_7,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int *piVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e54;
  *param_7 = param_5;
  param_7[1] = (int)GH_F2U((float)fparam_1);
  param_7[2] = (int)GH_F2U((float)fparam_2);
  param_7[3] = (int)GH_F2U((float)((fVar2 / (float)(fparam_2 - fparam_1))));
  if (0 < param_5) {
    do {
      param_7[4] = *param_6;
      piVar1 = param_6 + 1;
      param_6 = param_6 + param_4;
      param_7[5] = *piVar1;
      param_7 = param_7 + 2;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    return;
  }
  return;
}

/* _gleMap1Texture3fLoad @ 0xdee68 (112 bytes) */
int _gleMap1Texture3fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,int *param_7,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  fVar2 = FLOAT_00108e54;
  iVar3 = 0;
  *param_7 = param_5;
  param_7[1] = (int)GH_F2U((float)fparam_1);
  param_7[2] = (int)GH_F2U((float)fparam_2);
  param_7[3] = (int)GH_F2U((float)((fVar2 / (float)(fparam_2 - fparam_1))));
  if (0 < param_5) {
    do {
      iVar1 = iVar3 * 4;
      iVar3 = iVar3 + param_4;
      iVar4 = iVar1 + param_6;
      param_7[4] = *(int *)(iVar1 + param_6);
      param_7[5] = *(int *)(iVar4 + 4);
      param_7[6] = *(int *)(iVar4 + 8);
      param_7 = param_7 + 3;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    return;
  }
  return;
}

/* _gleMap1Texture4fLoad @ 0xdeed8 (120 bytes) */
int _gleMap1Texture4fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,int *param_7,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  fVar2 = FLOAT_00108e54;
  iVar3 = 0;
  *param_7 = param_5;
  param_7[1] = (int)GH_F2U((float)fparam_1);
  param_7[2] = (int)GH_F2U((float)fparam_2);
  param_7[3] = (int)GH_F2U((float)((fVar2 / (float)(fparam_2 - fparam_1))));
  if (0 < param_5) {
    do {
      iVar1 = iVar3 * 4;
      iVar3 = iVar3 + param_4;
      iVar4 = iVar1 + param_6;
      param_7[4] = *(int *)(iVar1 + param_6);
      param_7[5] = *(int *)(iVar4 + 4);
      param_7[6] = *(int *)(iVar4 + 8);
      param_7[7] = *(int *)(iVar4 + 0xc);
      param_7 = param_7 + 4;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    return;
  }
  return;
}

/* _gleMap1VertexAttrib1fLoad @ 0xdef50 (92 bytes) */
void _gleMap1VertexAttrib1fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int *param_6,int *param_7,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  float fVar2;
  int *piVar3;
  
  fVar2 = FLOAT_00108e54;
  *param_7 = param_5;
  param_7[1] = (int)GH_F2U((float)fparam_1);
  param_7[2] = (int)GH_F2U((float)fparam_2);
  param_7[3] = (int)GH_F2U((float)((fVar2 / (float)(fparam_2 - fparam_1))));
  if (param_5 < 1) {
    return;
  }
  piVar3 = param_7 + 4;
  do {
    iVar1 = *param_6;
    param_6 = param_6 + param_4;
    *piVar3 = iVar1;
    piVar3 = piVar3 + 1;
    param_5 = param_5 + -1;
  } while (param_5 != 0);
  return;
}

/* _gleMap1VertexAttrib2fLoad @ 0xdefac (96 bytes) */
void _gleMap1VertexAttrib2fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int *param_6,int *param_7,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int *piVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e54;
  *param_7 = param_5;
  param_7[1] = (int)GH_F2U((float)fparam_1);
  param_7[2] = (int)GH_F2U((float)fparam_2);
  param_7[3] = (int)GH_F2U((float)((fVar2 / (float)(fparam_2 - fparam_1))));
  if (0 < param_5) {
    do {
      param_7[4] = *param_6;
      piVar1 = param_6 + 1;
      param_6 = param_6 + param_4;
      param_7[5] = *piVar1;
      param_7 = param_7 + 2;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    return;
  }
  return;
}

/* _gleMap1VertexAttrib3fLoad @ 0xdf00c (112 bytes) */
void _gleMap1VertexAttrib3fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,int *param_7,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  fVar2 = FLOAT_00108e54;
  iVar3 = 0;
  *param_7 = param_5;
  param_7[1] = (int)GH_F2U((float)fparam_1);
  param_7[2] = (int)GH_F2U((float)fparam_2);
  param_7[3] = (int)GH_F2U((float)((fVar2 / (float)(fparam_2 - fparam_1))));
  if (0 < param_5) {
    do {
      iVar1 = iVar3 * 4;
      iVar3 = iVar3 + param_4;
      iVar4 = iVar1 + param_6;
      param_7[4] = *(int *)(iVar1 + param_6);
      param_7[5] = *(int *)(iVar4 + 4);
      param_7[6] = *(int *)(iVar4 + 8);
      param_7 = param_7 + 3;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    return;
  }
  return;
}

/* _gleMap1VertexAttrib4fLoad @ 0xdf07c (120 bytes) */
void _gleMap1VertexAttrib4fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,int *param_7,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  fVar2 = FLOAT_00108e54;
  iVar3 = 0;
  *param_7 = param_5;
  param_7[1] = (int)GH_F2U((float)fparam_1);
  param_7[2] = (int)GH_F2U((float)fparam_2);
  param_7[3] = (int)GH_F2U((float)((fVar2 / (float)(fparam_2 - fparam_1))));
  if (0 < param_5) {
    do {
      iVar1 = iVar3 * 4;
      iVar3 = iVar3 + param_4;
      iVar4 = iVar1 + param_6;
      param_7[4] = *(int *)(iVar1 + param_6);
      param_7[5] = *(int *)(iVar4 + 4);
      param_7[6] = *(int *)(iVar4 + 8);
      param_7[7] = *(int *)(iVar4 + 0xc);
      param_7 = param_7 + 4;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    return;
  }
  return;
}

/* _gleEvalMap1 @ 0xdf0f4 (968 bytes) */
void _gleEvalMap1(int param_1,double fparam_1)
{
  byte bVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 in_r6;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  uint uVar15;
  byte *pbVar16;
  undefined4 *puVar17;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  
  puVar4 = (undefined4 *)_gleGetMapData(param_1);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    return;
  }
  iVar9 = *(int *)(param_1 + 0x4858);
  if (iVar9 == *(int *)(param_1 + 0x485c)) {
    (**(code **)(param_1 + 0x4a0c))(param_1);
    iVar9 = *(int *)(param_1 + 0x4858);
  }
  iVar10 = *(int *)(param_1 + 0x4860);
  iVar11 = iVar10;
  if (*(char *)(param_1 + 0x7515) != '\0') {
    iVar11 = iVar10 + 0xc;
    ((void (*)())_gleEvalDomain1Coord)(param_1,puVar4 + 0x52,puVar4[0x4e],in_r6,3,iVar10,
               (double)((float)(fparam_1 - (double)GH_U2F((unsigned int)(puVar4[0x4f]))) * GH_U2F((unsigned int)(puVar4[0x51]))),in_f2
               ,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90,
               in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8);
  }
  if (*(char *)(param_1 + 0x7516) != '\0') {
    ((void (*)())_gleEvalDomain1Color)(param_1,puVar4 + 0x74,puVar4[0x70],in_r6,4,iVar11,
               (double)((float)(fparam_1 - (double)GH_U2F((unsigned int)(puVar4[0x71]))) * GH_U2F((unsigned int)(puVar4[0x73]))),in_f2
               ,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90,
               in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8);
    if (*(char *)(param_1 + 0x4df8) != '\0') {
      (**(code **)(param_1 + 0x4de0))(param_1,iVar11);
    }
    iVar11 = iVar11 + 0x10;
  }
  bVar1 = *(byte *)(param_1 + 0x751c);
  if (bVar1 == 8) {
    fVar2 = GH_U2F((unsigned int)(puVar4[0xb9]));
    fVar3 = GH_U2F((unsigned int)(puVar4[0xbb]));
    uVar7 = puVar4[0xb8];
    puVar5 = puVar4 + 0xbc;
    uVar8 = 2;
    iVar10 = iVar11 + 8;
LAB_000df2c8:
    ((void (*)())_gleEvalDomain1Coord)(param_1,puVar5,uVar7,in_r6,uVar8,iVar11,
               (double)((float)(fparam_1 - (double)fVar2) * fVar3),in_f2,in_f3,in_f4,in_f5,in_f6,
               in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98,in_stack_ffffffa0,
               in_stack_ffffffa8);
    iVar11 = iVar10;
  }
  else if (bVar1 < 9) {
    if (bVar1 == 4) {
      fVar2 = GH_U2F((unsigned int)(puVar4[0xab]));
      fVar3 = GH_U2F((unsigned int)(puVar4[0xad]));
      uVar7 = puVar4[0xaa];
      puVar5 = puVar4 + 0xae;
      uVar8 = 1;
      iVar10 = iVar11 + 4;
      goto LAB_000df2c8;
    }
  }
  else {
    if (bVar1 == 0xc) {
      iVar10 = iVar11 + 0xc;
      ((void (*)())_gleEvalDomain1Coord)(param_1,puVar4 + 0xd4,puVar4[0xd0],in_r6,3,iVar11,
                 (double)((float)(fparam_1 - (double)GH_U2F((unsigned int)(puVar4[0xd1]))) * GH_U2F((unsigned int)(puVar4[0xd3]))),
                 in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90,
                 in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8);
      uVar15 = *(uint *)(param_1 + 0x486c) | 1;
    }
    else {
      if (bVar1 != 0x10) goto LAB_000df2d0;
      iVar10 = iVar11 + 0x10;
      ((void (*)())_gleEvalDomain1Coord)(param_1,puVar4 + 0xf6,puVar4[0xf2],in_r6,4,iVar11,
                 (double)((float)(fparam_1 - (double)GH_U2F((unsigned int)(puVar4[0xf3]))) * GH_U2F((unsigned int)(puVar4[0xf5]))),
                 in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90,
                 in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8);
      uVar15 = *(uint *)(param_1 + 0x486c) | 3;
    }
    *(uint *)(param_1 + 0x486c) = uVar15;
    iVar11 = iVar10;
  }
LAB_000df2d0:
  uVar15 = *(uint *)(param_1 + 0x74d8);
  if (uVar15 != 0) {
    puVar12 = puVar4 + 0xb2e;
    pbVar16 = (byte *)(param_1 + 0x7524);
    puVar5 = puVar12;
    puVar13 = puVar12;
    puVar14 = puVar12;
    puVar17 = puVar4;
    do {
      bVar1 = *pbVar16;
      pbVar16 = pbVar16 + 1;
      if (bVar1 == 8) {
        fVar2 = GH_U2F((unsigned int)(puVar17[0xb2d]));
        fVar3 = (float)(fparam_1 - (double)GH_U2F((unsigned int)(puVar17[0xb2b])));
        uVar7 = puVar17[0xb2a];
        uVar8 = 2;
        iVar10 = iVar11 + 8;
        puVar6 = puVar13;
LAB_000df3c0:
        ((void (*)())_gleEvalDomain1Coord)(param_1,puVar6,uVar7,in_r6,uVar8,iVar11,(double)(fVar3 * fVar2),in_f2,in_f3,in_f4
                   ,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98,
                   in_stack_ffffffa0,in_stack_ffffffa8);
        iVar11 = iVar10;
      }
      else {
        if (8 < bVar1) {
          if (bVar1 == 0xc) {
            fVar2 = GH_U2F((unsigned int)(puVar17[0xb2d]));
            fVar3 = (float)(fparam_1 - (double)GH_U2F((unsigned int)(puVar17[0xb2b])));
            uVar7 = puVar17[0xb2a];
            uVar8 = 3;
            iVar10 = iVar11 + 0xc;
            puVar6 = puVar12;
          }
          else {
            if (bVar1 != 0x10) goto LAB_000df3c8;
            fVar2 = GH_U2F((unsigned int)(puVar17[0xb2d]));
            fVar3 = (float)(fparam_1 - (double)GH_U2F((unsigned int)(puVar17[0xb2b])));
            uVar7 = puVar17[0xb2a];
            uVar8 = 4;
            iVar10 = iVar11 + 0x10;
            puVar6 = puVar5;
          }
          goto LAB_000df3c0;
        }
        if (bVar1 == 4) {
          fVar2 = GH_U2F((unsigned int)(puVar17[0xb2d]));
          fVar3 = (float)(fparam_1 - (double)GH_U2F((unsigned int)(puVar17[0xb2b])));
          uVar7 = puVar17[0xb2a];
          uVar8 = 1;
          iVar10 = iVar11 + 4;
          puVar6 = puVar14;
          goto LAB_000df3c0;
        }
      }
LAB_000df3c8:
      uVar15 = uVar15 >> 1;
      puVar5 = puVar5 + 0x2c;
      puVar12 = puVar12 + 0x2c;
      puVar13 = puVar13 + 0x2c;
      puVar17 = puVar17 + 0x2c;
      puVar14 = puVar14 + 0x2c;
    } while (uVar15 != 0);
  }
  if (*(char *)(param_1 + 0x7514) == '\f') {
    fVar2 = GH_U2F((unsigned int)(puVar4[1]));
    fVar3 = GH_U2F((unsigned int)(puVar4[3]));
    uVar7 = *puVar4;
    puVar4 = puVar4 + 4;
    uVar8 = 3;
  }
  else {
    if (*(char *)(param_1 + 0x7514) != '\x10') {
      if ((*(char *)(param_1 + 0x4664) == '\0') || (*(char *)(param_1 + 0x7524) == '\0')) {
        if (*(int *)(param_1 + 0x5434) == 0) {
          return;
        }
        if (*(char *)(param_1 + 0x7524) == '\0') {
          return;
        }
      }
      goto LAB_000df478;
    }
    fVar2 = GH_U2F((unsigned int)(puVar4[0x23]));
    fVar3 = GH_U2F((unsigned int)(puVar4[0x25]));
    uVar7 = puVar4[0x22];
    puVar4 = puVar4 + 0x26;
    uVar8 = 4;
  }
  ((void (*)())_gleEvalDomain1Coord)(param_1,puVar4,uVar7,in_r6,uVar8,iVar11,
             (double)((float)(fparam_1 - (double)fVar2) * fVar3),in_f2,in_f3,in_f4,in_f5,in_f6,in_f7
             ,in_f8,in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98,in_stack_ffffffa0,
             in_stack_ffffffa8);
LAB_000df478:
  *(int *)(param_1 + 0x48ec) = param_1 + 0x7508;
  uVar7 = (**(code **)(param_1 + 0x4898))(param_1,*(undefined4 *)(param_1 + 0x4860),iVar9);
  *(undefined4 *)(param_1 + 0x48ec) = 0;
  *(undefined4 *)(param_1 + 0x4858) = uVar7;
  return;
}

/* _gleComputeFirstPartial @ 0xdf4bc (108 bytes) */
void _gleComputeFirstPartial(param_1, param_2, param_3, param_4)
  undefined4 param_1;
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
void _gleInitMap2Data(param_1)
  int param_1;
{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x7450);
  iVar3 = 0x10;
  *(undefined4 *)(iVar1 + 0x478) = 1;
  *(undefined4 *)(iVar1 + 0x47c) = 1;
  *(undefined4 *)(iVar1 + 0x480) = 0;
  puVar2 = (undefined1 *)(iVar1 + 0x9db8);
  *(undefined4 *)(iVar1 + 0x484) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x490) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x488) = 0;
  *(undefined4 *)(iVar1 + 0x48c) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x494) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x498) = 0;
  *(undefined4 *)(iVar1 + 0x49c) = 0;
  *(undefined4 *)(iVar1 + 0x4a0) = 0;
  *(undefined4 *)(iVar1 + 0x948) = 1;
  *(undefined4 *)(iVar1 + 0x94c) = 1;
  *(undefined4 *)(iVar1 + 0x950) = 0;
  *(undefined4 *)(iVar1 + 0x954) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x960) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x958) = 0;
  *(undefined4 *)(iVar1 + 0x95c) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x964) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x968) = 0;
  *(undefined4 *)(iVar1 + 0x96c) = 0;
  *(undefined4 *)(iVar1 + 0x970) = 0;
  *(undefined4 *)(iVar1 + 0x974) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0xfa8) = 1;
  *(undefined4 *)(iVar1 + 0xfac) = 1;
  *(undefined4 *)(iVar1 + 0xfb0) = 0;
  *(undefined4 *)(iVar1 + 0xfb4) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0xfc0) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0xfb8) = 0;
  *(undefined4 *)(iVar1 + 0xfbc) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0xfc4) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0xfc8) = 0;
  *(undefined4 *)(iVar1 + 0xfcc) = 0;
  *(undefined4 *)(iVar1 + 0xfd0) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1478) = 1;
  *(undefined4 *)(iVar1 + 0x147c) = 1;
  *(undefined4 *)(iVar1 + 0x1480) = 0;
  *(undefined4 *)(iVar1 + 0x1484) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1490) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1488) = 0;
  *(undefined4 *)(iVar1 + 0x148c) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1494) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1498) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x149c) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x14a0) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x14a4) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1ad8) = 1;
  *(undefined4 *)(iVar1 + 0x1adc) = 1;
  *(undefined4 *)(iVar1 + 0x1ae0) = 0;
  *(undefined4 *)(iVar1 + 0x1ae4) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1af0) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1ae8) = 0;
  *(undefined4 *)(iVar1 + 0x1aec) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1af4) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1af8) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1c88) = 1;
  *(undefined4 *)(iVar1 + 0x1c8c) = 1;
  *(undefined4 *)(iVar1 + 0x1c90) = 0;
  *(undefined4 *)(iVar1 + 0x1c94) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1ca0) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1c98) = 0;
  *(undefined4 *)(iVar1 + 0x1c9c) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1ca4) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1ca8) = 0;
  *(undefined4 *)(iVar1 + 0x1e38) = 1;
  *(undefined4 *)(iVar1 + 0x1e3c) = 1;
  *(undefined4 *)(iVar1 + 0x1e40) = 0;
  *(undefined4 *)(iVar1 + 0x264c) = 1;
  *(undefined4 *)(iVar1 + 0x1e44) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1e50) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1e48) = 0;
  *(undefined4 *)(iVar1 + 0x1e4c) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1e54) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x1e58) = 0;
  *(undefined4 *)(iVar1 + 0x1e5c) = 0;
  *(undefined4 *)(iVar1 + 0x2178) = 1;
  *(undefined4 *)(iVar1 + 0x217c) = 1;
  *(undefined4 *)(iVar1 + 0x2180) = 0;
  *(undefined4 *)(iVar1 + 0x2184) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x2190) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x2188) = 0;
  *(undefined4 *)(iVar1 + 0x218c) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x2194) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x2198) = 0;
  *(undefined4 *)(iVar1 + 0x219c) = 0;
  *(undefined4 *)(iVar1 + 0x21a0) = 0;
  *(undefined4 *)(iVar1 + 0x2648) = 1;
  *(undefined4 *)(iVar1 + 0x2650) = 0;
  *(undefined4 *)(iVar1 + 0x2654) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x2660) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x2658) = 0;
  *(undefined4 *)(iVar1 + 0x265c) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x2664) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x2668) = 0;
  *(undefined4 *)(iVar1 + 0x266c) = 0;
  *(undefined4 *)(iVar1 + 0x2670) = 0;
  *(undefined4 *)(iVar1 + 0x2674) = 0x3f800000;
  do {
    *puVar2 = 4;
    puVar2 = puVar2 + 1;
    *(undefined4 *)(iVar1 + 0x37a8) = 1;
    *(undefined4 *)(iVar1 + 0x37ac) = 1;
    *(undefined4 *)(iVar1 + 0x37b0) = 0;
    *(undefined4 *)(iVar1 + 0x37b4) = 0x3f800000;
    *(undefined4 *)(iVar1 + 0x37c0) = 0x3f800000;
    *(undefined4 *)(iVar1 + 0x37b8) = 0;
    *(undefined4 *)(iVar1 + 0x37bc) = 0x3f800000;
    *(undefined4 *)(iVar1 + 0x37c4) = 0x3f800000;
    *(undefined4 *)(iVar1 + 0x37c8) = 0;
    *(undefined4 *)(iVar1 + 0x37cc) = 0;
    *(undefined4 *)(iVar1 + 0x37d0) = 0;
    *(undefined4 *)(iVar1 + 0x37d4) = 0x3f800000;
    iVar1 = iVar1 + 0x660;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* _gleMap2Vertex3dLoad @ 0xdf718 (244 bytes) */
void _gleMap2Vertex3dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12,int param_13,int param_14,int *param_15,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double *pdVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  double dVar9;
  
  dVar2 = DOUBLE_00108d68;
  iVar4 = 0;
  dVar9 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_15 = param_7;
  iVar5 = 0;
  param_15[1] = param_13;
  param_15[6] = (int)GH_F2U((float)dVar9);
  param_15[7] = (int)GH_F2U((float)(dVar2 / (fparam_4 - fparam_3)));
  param_15[2] = (int)GH_F2U((float)fparam_1);
  param_15[3] = (int)GH_F2U((float)fparam_2);
  param_15[4] = (int)GH_F2U((float)fparam_3);
  param_15[5] = (int)GH_F2U((float)fparam_4);
  if (0 < param_7) {
    iVar6 = 0;
    do {
      if (0 < param_13) {
        pdVar3 = (double *)(iVar5 * 8 + param_14);
        piVar7 = param_15 + iVar6 * 3;
        iVar8 = param_13;
        do {
          piVar7[8] = (int)GH_F2U((float)*pdVar3);
          piVar7[9] = (int)GH_F2U((float)pdVar3[1]);
          pdVar1 = pdVar3 + 2;
          pdVar3 = pdVar3 + param_12;
          piVar7[10] = (int)GH_F2U((float)*pdVar1);
          piVar7 = piVar7 + 3;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + param_13;
      iVar5 = iVar5 + param_6;
    } while (iVar4 < param_7);
  }
  return;
}

/* _gleMap2Vertex4dLoad @ 0xdf80c (256 bytes) */
void _gleMap2Vertex4dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12,int param_13,int param_14,int *param_15,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double *pdVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  double dVar9;
  
  dVar2 = DOUBLE_00108d68;
  iVar4 = 0;
  dVar9 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_15 = param_7;
  iVar5 = 0;
  param_15[1] = param_13;
  param_15[6] = (int)GH_F2U((float)dVar9);
  param_15[7] = (int)GH_F2U((float)(dVar2 / (fparam_4 - fparam_3)));
  param_15[2] = (int)GH_F2U((float)fparam_1);
  param_15[3] = (int)GH_F2U((float)fparam_2);
  param_15[4] = (int)GH_F2U((float)fparam_3);
  param_15[5] = (int)GH_F2U((float)fparam_4);
  if (0 < param_7) {
    iVar6 = 0;
    do {
      if (0 < param_13) {
        piVar7 = param_15 + iVar6 * 4;
        pdVar3 = (double *)(iVar5 * 8 + param_14);
        iVar8 = param_13;
        do {
          piVar7[8] = (int)GH_F2U((float)*pdVar3);
          piVar7[9] = (int)GH_F2U((float)pdVar3[1]);
          piVar7[10] = (int)GH_F2U((float)pdVar3[2]);
          pdVar1 = pdVar3 + 3;
          pdVar3 = pdVar3 + param_12;
          piVar7[0xb] = (int)GH_F2U((float)*pdVar1);
          piVar7 = piVar7 + 4;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + param_13;
      iVar5 = iVar5 + param_6;
    } while (iVar4 < param_7);
  }
  return;
}

/* _gleMap2ColordLoad @ 0xdf90c (256 bytes) */
void _gleMap2ColordLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12,int param_13,int param_14,int *param_15,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double *pdVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  double dVar9;
  
  dVar2 = DOUBLE_00108d68;
  iVar4 = 0;
  dVar9 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_15 = param_7;
  iVar5 = 0;
  param_15[1] = param_13;
  param_15[6] = (int)GH_F2U((float)dVar9);
  param_15[7] = (int)GH_F2U((float)(dVar2 / (fparam_4 - fparam_3)));
  param_15[2] = (int)GH_F2U((float)fparam_1);
  param_15[3] = (int)GH_F2U((float)fparam_2);
  param_15[4] = (int)GH_F2U((float)fparam_3);
  param_15[5] = (int)GH_F2U((float)fparam_4);
  if (0 < param_7) {
    iVar6 = 0;
    do {
      if (0 < param_13) {
        piVar7 = param_15 + iVar6 * 4;
        pdVar3 = (double *)(iVar5 * 8 + param_14);
        iVar8 = param_13;
        do {
          piVar7[8] = (int)GH_F2U((float)*pdVar3);
          piVar7[9] = (int)GH_F2U((float)pdVar3[1]);
          piVar7[10] = (int)GH_F2U((float)pdVar3[2]);
          pdVar1 = pdVar3 + 3;
          pdVar3 = pdVar3 + param_12;
          piVar7[0xb] = (int)GH_F2U((float)*pdVar1);
          piVar7 = piVar7 + 4;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + param_13;
      iVar5 = iVar5 + param_6;
    } while (iVar4 < param_7);
  }
  return;
}

/* _gleMap2IndexdLoad @ 0xdfa0c (224 bytes) */
void _gleMap2IndexdLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12,int param_13,int param_14,int *param_15,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double *pdVar5;
  int iVar6;
  double dVar7;
  double dVar8;
  
  dVar7 = DOUBLE_00108d68;
  iVar2 = 0;
  dVar8 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_15 = param_7;
  iVar3 = 0;
  param_15[1] = param_13;
  param_15[6] = (int)GH_F2U((float)dVar8);
  param_15[7] = (int)GH_F2U((float)(dVar7 / (fparam_4 - fparam_3)));
  param_15[2] = (int)GH_F2U((float)fparam_1);
  param_15[3] = (int)GH_F2U((float)fparam_2);
  param_15[4] = (int)GH_F2U((float)fparam_3);
  param_15[5] = (int)GH_F2U((float)fparam_4);
  if (0 < param_7) {
    iVar4 = 0;
    do {
      if (0 < param_13) {
        pdVar5 = (double *)(iVar3 * 8 + param_14);
        pfVar1 = (float *)(param_15 + iVar4 + 8);
        iVar6 = param_13;
        do {
          dVar7 = *pdVar5;
          pdVar5 = pdVar5 + param_12;
          *pfVar1 = (float)dVar7;
          pfVar1 = pfVar1 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + param_13;
      iVar3 = iVar3 + param_6;
    } while (iVar2 < param_7);
  }
  return;
}

/* _gleMap2NormaldLoad @ 0xdfaec (244 bytes) */
void _gleMap2NormaldLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12,int param_13,int param_14,int *param_15,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double *pdVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  double dVar9;
  
  dVar2 = DOUBLE_00108d68;
  iVar4 = 0;
  dVar9 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_15 = param_7;
  iVar5 = 0;
  param_15[1] = param_13;
  param_15[6] = (int)GH_F2U((float)dVar9);
  param_15[7] = (int)GH_F2U((float)(dVar2 / (fparam_4 - fparam_3)));
  param_15[2] = (int)GH_F2U((float)fparam_1);
  param_15[3] = (int)GH_F2U((float)fparam_2);
  param_15[4] = (int)GH_F2U((float)fparam_3);
  param_15[5] = (int)GH_F2U((float)fparam_4);
  if (0 < param_7) {
    iVar6 = 0;
    do {
      if (0 < param_13) {
        pdVar3 = (double *)(iVar5 * 8 + param_14);
        piVar7 = param_15 + iVar6 * 3;
        iVar8 = param_13;
        do {
          piVar7[8] = (int)GH_F2U((float)*pdVar3);
          piVar7[9] = (int)GH_F2U((float)pdVar3[1]);
          pdVar1 = pdVar3 + 2;
          pdVar3 = pdVar3 + param_12;
          piVar7[10] = (int)GH_F2U((float)*pdVar1);
          piVar7 = piVar7 + 3;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + param_13;
      iVar5 = iVar5 + param_6;
    } while (iVar4 < param_7);
  }
  return;
}

/* _gleMap2Texture1dLoad @ 0xdfbe0 (224 bytes) */
void _gleMap2Texture1dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12,int param_13,int param_14,int *param_15,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double *pdVar5;
  int iVar6;
  double dVar7;
  double dVar8;
  
  dVar7 = DOUBLE_00108d68;
  iVar2 = 0;
  dVar8 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_15 = param_7;
  iVar3 = 0;
  param_15[1] = param_13;
  param_15[6] = (int)GH_F2U((float)dVar8);
  param_15[7] = (int)GH_F2U((float)(dVar7 / (fparam_4 - fparam_3)));
  param_15[2] = (int)GH_F2U((float)fparam_1);
  param_15[3] = (int)GH_F2U((float)fparam_2);
  param_15[4] = (int)GH_F2U((float)fparam_3);
  param_15[5] = (int)GH_F2U((float)fparam_4);
  if (0 < param_7) {
    iVar4 = 0;
    do {
      if (0 < param_13) {
        pdVar5 = (double *)(iVar3 * 8 + param_14);
        pfVar1 = (float *)(param_15 + iVar4 + 8);
        iVar6 = param_13;
        do {
          dVar7 = *pdVar5;
          pdVar5 = pdVar5 + param_12;
          *pfVar1 = (float)dVar7;
          pfVar1 = pfVar1 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + param_13;
      iVar3 = iVar3 + param_6;
    } while (iVar2 < param_7);
  }
  return;
}

/* _gleMap2Texture2dLoad @ 0xdfcc0 (252 bytes) */
void _gleMap2Texture2dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12,int param_13,int param_14,int *param_15,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double *pdVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  double *pdVar7;
  int iVar8;
  int iVar9;
  double dVar10;
  double dVar11;
  
  dVar11 = DOUBLE_00108d68;
  iVar8 = 0;
  dVar10 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_15 = param_7;
  param_15[1] = param_13;
  iVar4 = 0;
  param_15[6] = (int)GH_F2U((float)dVar10);
  param_15[7] = (int)GH_F2U((float)(dVar11 / (fparam_4 - fparam_3)));
  param_15[2] = (int)GH_F2U((float)fparam_1);
  param_15[3] = (int)GH_F2U((float)fparam_2);
  param_15[4] = (int)GH_F2U((float)fparam_3);
  param_15[5] = (int)GH_F2U((float)fparam_4);
  if (0 < param_7) {
    iVar5 = 0;
    iVar6 = param_14;
    do {
      if (0 < param_13) {
        piVar3 = param_15 + iVar5 * 2;
        pdVar7 = (double *)(iVar6 + 8);
        iVar2 = iVar4 << 3;
        iVar9 = param_13;
        do {
          pdVar1 = (double *)(param_14 + iVar2);
          iVar2 = iVar2 + param_12 * 8;
          piVar3[8] = (int)GH_F2U((float)*pdVar1);
          dVar11 = *pdVar7;
          pdVar7 = pdVar7 + param_12;
          piVar3[9] = (int)GH_F2U((float)dVar11);
          piVar3 = piVar3 + 2;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      iVar8 = iVar8 + 1;
      iVar6 = iVar6 + param_6 * 8;
      iVar5 = iVar5 + param_13;
      iVar4 = iVar4 + param_6;
    } while (iVar8 < param_7);
  }
  return;
}

/* _gleMap2Texture3dLoad @ 0xdfdbc (244 bytes) */
void _gleMap2Texture3dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12,int param_13,int param_14,int *param_15,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double *pdVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  double dVar9;
  
  dVar2 = DOUBLE_00108d68;
  iVar4 = 0;
  dVar9 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_15 = param_7;
  iVar5 = 0;
  param_15[1] = param_13;
  param_15[6] = (int)GH_F2U((float)dVar9);
  param_15[7] = (int)GH_F2U((float)(dVar2 / (fparam_4 - fparam_3)));
  param_15[2] = (int)GH_F2U((float)fparam_1);
  param_15[3] = (int)GH_F2U((float)fparam_2);
  param_15[4] = (int)GH_F2U((float)fparam_3);
  param_15[5] = (int)GH_F2U((float)fparam_4);
  if (0 < param_7) {
    iVar6 = 0;
    do {
      if (0 < param_13) {
        pdVar3 = (double *)(iVar5 * 8 + param_14);
        piVar7 = param_15 + iVar6 * 3;
        iVar8 = param_13;
        do {
          piVar7[8] = (int)GH_F2U((float)*pdVar3);
          piVar7[9] = (int)GH_F2U((float)pdVar3[1]);
          pdVar1 = pdVar3 + 2;
          pdVar3 = pdVar3 + param_12;
          piVar7[10] = (int)GH_F2U((float)*pdVar1);
          piVar7 = piVar7 + 3;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + param_13;
      iVar5 = iVar5 + param_6;
    } while (iVar4 < param_7);
  }
  return;
}

/* _gleMap2Texture4dLoad @ 0xdfeb0 (256 bytes) */
void _gleMap2Texture4dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12,int param_13,int param_14,int *param_15,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double *pdVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  double dVar9;
  
  dVar2 = DOUBLE_00108d68;
  iVar4 = 0;
  dVar9 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_15 = param_7;
  iVar5 = 0;
  param_15[1] = param_13;
  param_15[6] = (int)GH_F2U((float)dVar9);
  param_15[7] = (int)GH_F2U((float)(dVar2 / (fparam_4 - fparam_3)));
  param_15[2] = (int)GH_F2U((float)fparam_1);
  param_15[3] = (int)GH_F2U((float)fparam_2);
  param_15[4] = (int)GH_F2U((float)fparam_3);
  param_15[5] = (int)GH_F2U((float)fparam_4);
  if (0 < param_7) {
    iVar6 = 0;
    do {
      if (0 < param_13) {
        piVar7 = param_15 + iVar6 * 4;
        pdVar3 = (double *)(iVar5 * 8 + param_14);
        iVar8 = param_13;
        do {
          piVar7[8] = (int)GH_F2U((float)*pdVar3);
          piVar7[9] = (int)GH_F2U((float)pdVar3[1]);
          piVar7[10] = (int)GH_F2U((float)pdVar3[2]);
          pdVar1 = pdVar3 + 3;
          pdVar3 = pdVar3 + param_12;
          piVar7[0xb] = (int)GH_F2U((float)*pdVar1);
          piVar7 = piVar7 + 4;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + param_13;
      iVar5 = iVar5 + param_6;
    } while (iVar4 < param_7);
  }
  return;
}

/* _gleMap2VertexAttrib1dLoad @ 0xdffb0 (224 bytes) */
void _gleMap2VertexAttrib1dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12,int param_13,int param_14,int *param_15,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double *pdVar5;
  int iVar6;
  double dVar7;
  double dVar8;
  
  dVar7 = DOUBLE_00108d68;
  iVar2 = 0;
  dVar8 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_15 = param_7;
  iVar3 = 0;
  param_15[1] = param_13;
  param_15[6] = (int)GH_F2U((float)dVar8);
  param_15[7] = (int)GH_F2U((float)(dVar7 / (fparam_4 - fparam_3)));
  param_15[2] = (int)GH_F2U((float)fparam_1);
  param_15[3] = (int)GH_F2U((float)fparam_2);
  param_15[4] = (int)GH_F2U((float)fparam_3);
  param_15[5] = (int)GH_F2U((float)fparam_4);
  if (0 < param_7) {
    iVar4 = 0;
    do {
      if (0 < param_13) {
        pdVar5 = (double *)(iVar3 * 8 + param_14);
        pfVar1 = (float *)(param_15 + iVar4 + 8);
        iVar6 = param_13;
        do {
          dVar7 = *pdVar5;
          pdVar5 = pdVar5 + param_12;
          *pfVar1 = (float)dVar7;
          pfVar1 = pfVar1 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + param_13;
      iVar3 = iVar3 + param_6;
    } while (iVar2 < param_7);
  }
  return;
}

/* _gleMap2VertexAttrib2dLoad @ 0xe0090 (252 bytes) */
void _gleMap2VertexAttrib2dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12,int param_13,int param_14,int *param_15,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double *pdVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  double *pdVar7;
  int iVar8;
  int iVar9;
  double dVar10;
  double dVar11;
  
  dVar11 = DOUBLE_00108d68;
  iVar8 = 0;
  dVar10 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_15 = param_7;
  param_15[1] = param_13;
  iVar4 = 0;
  param_15[6] = (int)GH_F2U((float)dVar10);
  param_15[7] = (int)GH_F2U((float)(dVar11 / (fparam_4 - fparam_3)));
  param_15[2] = (int)GH_F2U((float)fparam_1);
  param_15[3] = (int)GH_F2U((float)fparam_2);
  param_15[4] = (int)GH_F2U((float)fparam_3);
  param_15[5] = (int)GH_F2U((float)fparam_4);
  if (0 < param_7) {
    iVar5 = 0;
    iVar6 = param_14;
    do {
      if (0 < param_13) {
        piVar3 = param_15 + iVar5 * 2;
        pdVar7 = (double *)(iVar6 + 8);
        iVar2 = iVar4 << 3;
        iVar9 = param_13;
        do {
          pdVar1 = (double *)(param_14 + iVar2);
          iVar2 = iVar2 + param_12 * 8;
          piVar3[8] = (int)GH_F2U((float)*pdVar1);
          dVar11 = *pdVar7;
          pdVar7 = pdVar7 + param_12;
          piVar3[9] = (int)GH_F2U((float)dVar11);
          piVar3 = piVar3 + 2;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      iVar8 = iVar8 + 1;
      iVar6 = iVar6 + param_6 * 8;
      iVar5 = iVar5 + param_13;
      iVar4 = iVar4 + param_6;
    } while (iVar8 < param_7);
  }
  return;
}

/* _gleMap2VertexAttrib3dLoad @ 0xe018c (244 bytes) */
void _gleMap2VertexAttrib3dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12,int param_13,int param_14,int *param_15,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double *pdVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  double dVar9;
  
  dVar2 = DOUBLE_00108d68;
  iVar4 = 0;
  dVar9 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_15 = param_7;
  iVar5 = 0;
  param_15[1] = param_13;
  param_15[6] = (int)GH_F2U((float)dVar9);
  param_15[7] = (int)GH_F2U((float)(dVar2 / (fparam_4 - fparam_3)));
  param_15[2] = (int)GH_F2U((float)fparam_1);
  param_15[3] = (int)GH_F2U((float)fparam_2);
  param_15[4] = (int)GH_F2U((float)fparam_3);
  param_15[5] = (int)GH_F2U((float)fparam_4);
  if (0 < param_7) {
    iVar6 = 0;
    do {
      if (0 < param_13) {
        pdVar3 = (double *)(iVar5 * 8 + param_14);
        piVar7 = param_15 + iVar6 * 3;
        iVar8 = param_13;
        do {
          piVar7[8] = (int)GH_F2U((float)*pdVar3);
          piVar7[9] = (int)GH_F2U((float)pdVar3[1]);
          pdVar1 = pdVar3 + 2;
          pdVar3 = pdVar3 + param_12;
          piVar7[10] = (int)GH_F2U((float)*pdVar1);
          piVar7 = piVar7 + 3;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + param_13;
      iVar5 = iVar5 + param_6;
    } while (iVar4 < param_7);
  }
  return;
}

/* _gleMap2VertexAttrib4dLoad @ 0xe0280 (256 bytes) */
void _gleMap2VertexAttrib4dLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12,int param_13,int param_14,int *param_15,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double *pdVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  double dVar9;
  
  dVar2 = DOUBLE_00108d68;
  iVar4 = 0;
  dVar9 = DOUBLE_00108d68 / (fparam_2 - fparam_1);
  *param_15 = param_7;
  iVar5 = 0;
  param_15[1] = param_13;
  param_15[6] = (int)GH_F2U((float)dVar9);
  param_15[7] = (int)GH_F2U((float)(dVar2 / (fparam_4 - fparam_3)));
  param_15[2] = (int)GH_F2U((float)fparam_1);
  param_15[3] = (int)GH_F2U((float)fparam_2);
  param_15[4] = (int)GH_F2U((float)fparam_3);
  param_15[5] = (int)GH_F2U((float)fparam_4);
  if (0 < param_7) {
    iVar6 = 0;
    do {
      if (0 < param_13) {
        piVar7 = param_15 + iVar6 * 4;
        pdVar3 = (double *)(iVar5 * 8 + param_14);
        iVar8 = param_13;
        do {
          piVar7[8] = (int)GH_F2U((float)*pdVar3);
          piVar7[9] = (int)GH_F2U((float)pdVar3[1]);
          piVar7[10] = (int)GH_F2U((float)pdVar3[2]);
          pdVar1 = pdVar3 + 3;
          pdVar3 = pdVar3 + param_12;
          piVar7[0xb] = (int)GH_F2U((float)*pdVar1);
          piVar7 = piVar7 + 4;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + param_13;
      iVar5 = iVar5 + param_6;
    } while (iVar4 < param_7);
  }
  return;
}

/* _gleMap2Vertex3fLoad @ 0xe0380 (204 bytes) */
void _gleMap2Vertex3fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int *param_11,float fparam_1,float fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  fVar3 = FLOAT_00108e54;
  iVar5 = 0;
  fVar2 = FLOAT_00108e54 / (float)(fparam_2 - fparam_1);
  *param_11 = param_5;
  iVar6 = 0;
  param_11[1] = param_9;
  param_11[2] = (int)GH_F2U((float)fparam_1);
  param_11[3] = (int)GH_F2U((float)fparam_2);
  param_11[4] = (int)GH_F2U((float)fparam_3);
  param_11[5] = (int)GH_F2U((float)fparam_4);
  param_11[6] = (int)GH_F2U(fVar2);
  param_11[7] = (int)GH_F2U((float)((fVar3 / (float)(fparam_4 - fparam_3))));
  if (0 < param_5) {
    iVar8 = 0;
    do {
      if (0 < param_9) {
        piVar4 = (int *)(iVar6 * 4 + param_10);
        piVar7 = param_11 + iVar8 * 3;
        iVar9 = param_9;
        do {
          piVar7[8] = *piVar4;
          piVar7[9] = piVar4[1];
          piVar1 = piVar4 + 2;
          piVar4 = piVar4 + param_8;
          piVar7[10] = *piVar1;
          piVar7 = piVar7 + 3;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + param_9;
      iVar6 = iVar6 + param_4;
    } while (iVar5 < param_5);
  }
  return;
}

/* _gleMap2Vertex4fLoad @ 0xe044c (212 bytes) */
void _gleMap2Vertex4fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int *param_11,float fparam_1,float fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  fVar3 = FLOAT_00108e54;
  iVar5 = 0;
  fVar2 = FLOAT_00108e54 / (float)(fparam_2 - fparam_1);
  *param_11 = param_5;
  iVar6 = 0;
  param_11[1] = param_9;
  param_11[2] = (int)GH_F2U((float)fparam_1);
  param_11[3] = (int)GH_F2U((float)fparam_2);
  param_11[4] = (int)GH_F2U((float)fparam_3);
  param_11[5] = (int)GH_F2U((float)fparam_4);
  param_11[6] = (int)GH_F2U(fVar2);
  param_11[7] = (int)GH_F2U((float)((fVar3 / (float)(fparam_4 - fparam_3))));
  if (0 < param_5) {
    iVar8 = 0;
    do {
      if (0 < param_9) {
        piVar7 = param_11 + iVar8 * 4;
        piVar4 = (int *)(iVar6 * 4 + param_10);
        iVar9 = param_9;
        do {
          piVar7[8] = *piVar4;
          piVar7[9] = piVar4[1];
          piVar7[10] = piVar4[2];
          piVar1 = piVar4 + 3;
          piVar4 = piVar4 + param_8;
          piVar7[0xb] = *piVar1;
          piVar7 = piVar7 + 4;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + param_9;
      iVar6 = iVar6 + param_4;
    } while (iVar5 < param_5);
  }
  return;
}

/* _gleMap2ColorfLoad @ 0xe0520 (212 bytes) */
void _gleMap2ColorfLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int *param_11,float fparam_1,float fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  fVar3 = FLOAT_00108e54;
  iVar5 = 0;
  fVar2 = FLOAT_00108e54 / (float)(fparam_2 - fparam_1);
  *param_11 = param_5;
  iVar6 = 0;
  param_11[1] = param_9;
  param_11[2] = (int)GH_F2U((float)fparam_1);
  param_11[3] = (int)GH_F2U((float)fparam_2);
  param_11[4] = (int)GH_F2U((float)fparam_3);
  param_11[5] = (int)GH_F2U((float)fparam_4);
  param_11[6] = (int)GH_F2U(fVar2);
  param_11[7] = (int)GH_F2U((float)((fVar3 / (float)(fparam_4 - fparam_3))));
  if (0 < param_5) {
    iVar8 = 0;
    do {
      if (0 < param_9) {
        piVar7 = param_11 + iVar8 * 4;
        piVar4 = (int *)(iVar6 * 4 + param_10);
        iVar9 = param_9;
        do {
          piVar7[8] = *piVar4;
          piVar7[9] = piVar4[1];
          piVar7[10] = piVar4[2];
          piVar1 = piVar4 + 3;
          piVar4 = piVar4 + param_8;
          piVar7[0xb] = *piVar1;
          piVar7 = piVar7 + 4;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + param_9;
      iVar6 = iVar6 + param_4;
    } while (iVar5 < param_5);
  }
  return;
}

/* _gleMap2IndexfLoad @ 0xe05f4 (192 bytes) */
void _gleMap2IndexfLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int *param_11,float fparam_1,float fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  fVar3 = FLOAT_00108e54;
  iVar5 = 0;
  fVar2 = FLOAT_00108e54 / (float)(fparam_2 - fparam_1);
  *param_11 = param_5;
  iVar6 = 0;
  param_11[1] = param_9;
  param_11[2] = (int)GH_F2U((float)fparam_1);
  param_11[3] = (int)GH_F2U((float)fparam_2);
  param_11[4] = (int)GH_F2U((float)fparam_3);
  param_11[5] = (int)GH_F2U((float)fparam_4);
  param_11[6] = (int)GH_F2U(fVar2);
  param_11[7] = (int)GH_F2U((float)((fVar3 / (float)(fparam_4 - fparam_3))));
  if (0 < param_5) {
    iVar8 = 0;
    do {
      if (0 < param_9) {
        piVar7 = (int *)(iVar6 * 4 + param_10);
        piVar4 = param_11 + iVar8 + 8;
        iVar9 = param_9;
        do {
          iVar1 = *piVar7;
          piVar7 = piVar7 + param_8;
          *piVar4 = iVar1;
          piVar4 = piVar4 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + param_9;
      iVar6 = iVar6 + param_4;
    } while (iVar5 < param_5);
  }
  return;
}

/* _gleMap2NormalfLoad @ 0xe06b4 (204 bytes) */
void _gleMap2NormalfLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int *param_11,float fparam_1,float fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  fVar3 = FLOAT_00108e54;
  iVar5 = 0;
  fVar2 = FLOAT_00108e54 / (float)(fparam_2 - fparam_1);
  *param_11 = param_5;
  iVar6 = 0;
  param_11[1] = param_9;
  param_11[2] = (int)GH_F2U((float)fparam_1);
  param_11[3] = (int)GH_F2U((float)fparam_2);
  param_11[4] = (int)GH_F2U((float)fparam_3);
  param_11[5] = (int)GH_F2U((float)fparam_4);
  param_11[6] = (int)GH_F2U(fVar2);
  param_11[7] = (int)GH_F2U((float)((fVar3 / (float)(fparam_4 - fparam_3))));
  if (0 < param_5) {
    iVar8 = 0;
    do {
      if (0 < param_9) {
        piVar4 = (int *)(iVar6 * 4 + param_10);
        piVar7 = param_11 + iVar8 * 3;
        iVar9 = param_9;
        do {
          piVar7[8] = *piVar4;
          piVar7[9] = piVar4[1];
          piVar1 = piVar4 + 2;
          piVar4 = piVar4 + param_8;
          piVar7[10] = *piVar1;
          piVar7 = piVar7 + 3;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + param_9;
      iVar6 = iVar6 + param_4;
    } while (iVar5 < param_5);
  }
  return;
}

/* _gleMap2Texture1fLoad @ 0xe0780 (192 bytes) */
void _gleMap2Texture1fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int *param_11,float fparam_1,float fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  fVar3 = FLOAT_00108e54;
  iVar5 = 0;
  fVar2 = FLOAT_00108e54 / (float)(fparam_2 - fparam_1);
  *param_11 = param_5;
  iVar6 = 0;
  param_11[1] = param_9;
  param_11[2] = (int)GH_F2U((float)fparam_1);
  param_11[3] = (int)GH_F2U((float)fparam_2);
  param_11[4] = (int)GH_F2U((float)fparam_3);
  param_11[5] = (int)GH_F2U((float)fparam_4);
  param_11[6] = (int)GH_F2U(fVar2);
  param_11[7] = (int)GH_F2U((float)((fVar3 / (float)(fparam_4 - fparam_3))));
  if (0 < param_5) {
    iVar8 = 0;
    do {
      if (0 < param_9) {
        piVar7 = (int *)(iVar6 * 4 + param_10);
        piVar4 = param_11 + iVar8 + 8;
        iVar9 = param_9;
        do {
          iVar1 = *piVar7;
          piVar7 = piVar7 + param_8;
          *piVar4 = iVar1;
          piVar4 = piVar4 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + param_9;
      iVar6 = iVar6 + param_4;
    } while (iVar5 < param_5);
  }
  return;
}

/* _gleMap2Texture2fLoad @ 0xe0840 (216 bytes) */
void _gleMap2Texture2fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int *param_11,float fparam_1,float fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  
  fVar4 = FLOAT_00108e54;
  iVar9 = 0;
  fVar3 = FLOAT_00108e54 / (float)(fparam_2 - fparam_1);
  iVar7 = 0;
  *param_11 = param_5;
  param_11[1] = param_9;
  param_11[2] = (int)GH_F2U((float)fparam_1);
  param_11[3] = (int)GH_F2U((float)fparam_2);
  param_11[4] = (int)GH_F2U((float)fparam_3);
  param_11[5] = (int)GH_F2U((float)fparam_4);
  param_11[6] = (int)GH_F2U(fVar3);
  param_11[7] = (int)GH_F2U((float)((fVar4 / (float)(fparam_4 - fparam_3))));
  if (0 < param_5) {
    iVar8 = 0;
    iVar10 = param_10;
    do {
      if (0 < param_9) {
        piVar6 = param_11 + iVar8 * 2;
        piVar11 = (int *)(iVar10 + 4);
        iVar5 = iVar7 << 2;
        iVar12 = param_9;
        do {
          piVar2 = (int *)(param_10 + iVar5);
          iVar5 = iVar5 + param_8 * 4;
          piVar6[8] = *piVar2;
          iVar1 = *piVar11;
          piVar11 = piVar11 + param_8;
          piVar6[9] = iVar1;
          piVar6 = piVar6 + 2;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
      iVar9 = iVar9 + 1;
      iVar10 = iVar10 + param_4 * 4;
      iVar8 = iVar8 + param_9;
      iVar7 = iVar7 + param_4;
    } while (iVar9 < param_5);
  }
  return;
}

/* _gleMap2Texture3fLoad @ 0xe0918 (204 bytes) */
void _gleMap2Texture3fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int *param_11,float fparam_1,float fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  fVar3 = FLOAT_00108e54;
  iVar5 = 0;
  fVar2 = FLOAT_00108e54 / (float)(fparam_2 - fparam_1);
  *param_11 = param_5;
  iVar6 = 0;
  param_11[1] = param_9;
  param_11[2] = (int)GH_F2U((float)fparam_1);
  param_11[3] = (int)GH_F2U((float)fparam_2);
  param_11[4] = (int)GH_F2U((float)fparam_3);
  param_11[5] = (int)GH_F2U((float)fparam_4);
  param_11[6] = (int)GH_F2U(fVar2);
  param_11[7] = (int)GH_F2U((float)((fVar3 / (float)(fparam_4 - fparam_3))));
  if (0 < param_5) {
    iVar8 = 0;
    do {
      if (0 < param_9) {
        piVar4 = (int *)(iVar6 * 4 + param_10);
        piVar7 = param_11 + iVar8 * 3;
        iVar9 = param_9;
        do {
          piVar7[8] = *piVar4;
          piVar7[9] = piVar4[1];
          piVar1 = piVar4 + 2;
          piVar4 = piVar4 + param_8;
          piVar7[10] = *piVar1;
          piVar7 = piVar7 + 3;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + param_9;
      iVar6 = iVar6 + param_4;
    } while (iVar5 < param_5);
  }
  return;
}

/* _gleMap2Texture4fLoad @ 0xe09e4 (212 bytes) */
void _gleMap2Texture4fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int *param_11,float fparam_1,float fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  fVar3 = FLOAT_00108e54;
  iVar5 = 0;
  fVar2 = FLOAT_00108e54 / (float)(fparam_2 - fparam_1);
  *param_11 = param_5;
  iVar6 = 0;
  param_11[1] = param_9;
  param_11[2] = (int)GH_F2U((float)fparam_1);
  param_11[3] = (int)GH_F2U((float)fparam_2);
  param_11[4] = (int)GH_F2U((float)fparam_3);
  param_11[5] = (int)GH_F2U((float)fparam_4);
  param_11[6] = (int)GH_F2U(fVar2);
  param_11[7] = (int)GH_F2U((float)((fVar3 / (float)(fparam_4 - fparam_3))));
  if (0 < param_5) {
    iVar8 = 0;
    do {
      if (0 < param_9) {
        piVar7 = param_11 + iVar8 * 4;
        piVar4 = (int *)(iVar6 * 4 + param_10);
        iVar9 = param_9;
        do {
          piVar7[8] = *piVar4;
          piVar7[9] = piVar4[1];
          piVar7[10] = piVar4[2];
          piVar1 = piVar4 + 3;
          piVar4 = piVar4 + param_8;
          piVar7[0xb] = *piVar1;
          piVar7 = piVar7 + 4;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + param_9;
      iVar6 = iVar6 + param_4;
    } while (iVar5 < param_5);
  }
  return;
}

/* _gleMap2VertexAttrib1fLoad @ 0xe0ab8 (192 bytes) */
void _gleMap2VertexAttrib1fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int *param_11,float fparam_1,float fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  fVar3 = FLOAT_00108e54;
  iVar5 = 0;
  fVar2 = FLOAT_00108e54 / (float)(fparam_2 - fparam_1);
  *param_11 = param_5;
  iVar6 = 0;
  param_11[1] = param_9;
  param_11[2] = (int)GH_F2U((float)fparam_1);
  param_11[3] = (int)GH_F2U((float)fparam_2);
  param_11[4] = (int)GH_F2U((float)fparam_3);
  param_11[5] = (int)GH_F2U((float)fparam_4);
  param_11[6] = (int)GH_F2U(fVar2);
  param_11[7] = (int)GH_F2U((float)((fVar3 / (float)(fparam_4 - fparam_3))));
  if (0 < param_5) {
    iVar8 = 0;
    do {
      if (0 < param_9) {
        piVar7 = (int *)(iVar6 * 4 + param_10);
        piVar4 = param_11 + iVar8 + 8;
        iVar9 = param_9;
        do {
          iVar1 = *piVar7;
          piVar7 = piVar7 + param_8;
          *piVar4 = iVar1;
          piVar4 = piVar4 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + param_9;
      iVar6 = iVar6 + param_4;
    } while (iVar5 < param_5);
  }
  return;
}

/* _gleMap2VertexAttrib2fLoad @ 0xe0b78 (216 bytes) */
void _gleMap2VertexAttrib2fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int *param_11,float fparam_1,float fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  
  fVar4 = FLOAT_00108e54;
  iVar9 = 0;
  fVar3 = FLOAT_00108e54 / (float)(fparam_2 - fparam_1);
  iVar7 = 0;
  *param_11 = param_5;
  param_11[1] = param_9;
  param_11[2] = (int)GH_F2U((float)fparam_1);
  param_11[3] = (int)GH_F2U((float)fparam_2);
  param_11[4] = (int)GH_F2U((float)fparam_3);
  param_11[5] = (int)GH_F2U((float)fparam_4);
  param_11[6] = (int)GH_F2U(fVar3);
  param_11[7] = (int)GH_F2U((float)((fVar4 / (float)(fparam_4 - fparam_3))));
  if (0 < param_5) {
    iVar8 = 0;
    iVar10 = param_10;
    do {
      if (0 < param_9) {
        piVar6 = param_11 + iVar8 * 2;
        piVar11 = (int *)(iVar10 + 4);
        iVar5 = iVar7 << 2;
        iVar12 = param_9;
        do {
          piVar2 = (int *)(param_10 + iVar5);
          iVar5 = iVar5 + param_8 * 4;
          piVar6[8] = *piVar2;
          iVar1 = *piVar11;
          piVar11 = piVar11 + param_8;
          piVar6[9] = iVar1;
          piVar6 = piVar6 + 2;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
      iVar9 = iVar9 + 1;
      iVar10 = iVar10 + param_4 * 4;
      iVar8 = iVar8 + param_9;
      iVar7 = iVar7 + param_4;
    } while (iVar9 < param_5);
  }
  return;
}

/* _gleMap2VertexAttrib3fLoad @ 0xe0c50 (204 bytes) */
void _gleMap2VertexAttrib3fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int *param_11,float fparam_1,float fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  fVar3 = FLOAT_00108e54;
  iVar5 = 0;
  fVar2 = FLOAT_00108e54 / (float)(fparam_2 - fparam_1);
  *param_11 = param_5;
  iVar6 = 0;
  param_11[1] = param_9;
  param_11[2] = (int)GH_F2U((float)fparam_1);
  param_11[3] = (int)GH_F2U((float)fparam_2);
  param_11[4] = (int)GH_F2U((float)fparam_3);
  param_11[5] = (int)GH_F2U((float)fparam_4);
  param_11[6] = (int)GH_F2U(fVar2);
  param_11[7] = (int)GH_F2U((float)((fVar3 / (float)(fparam_4 - fparam_3))));
  if (0 < param_5) {
    iVar8 = 0;
    do {
      if (0 < param_9) {
        piVar4 = (int *)(iVar6 * 4 + param_10);
        piVar7 = param_11 + iVar8 * 3;
        iVar9 = param_9;
        do {
          piVar7[8] = *piVar4;
          piVar7[9] = piVar4[1];
          piVar1 = piVar4 + 2;
          piVar4 = piVar4 + param_8;
          piVar7[10] = *piVar1;
          piVar7 = piVar7 + 3;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + param_9;
      iVar6 = iVar6 + param_4;
    } while (iVar5 < param_5);
  }
  return;
}

/* _gleMap2VertexAttrib4fLoad @ 0xe0d1c (212 bytes) */
void _gleMap2VertexAttrib4fLoad(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int *param_11,float fparam_1,float fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  fVar3 = FLOAT_00108e54;
  iVar5 = 0;
  fVar2 = FLOAT_00108e54 / (float)(fparam_2 - fparam_1);
  *param_11 = param_5;
  iVar6 = 0;
  param_11[1] = param_9;
  param_11[2] = (int)GH_F2U((float)fparam_1);
  param_11[3] = (int)GH_F2U((float)fparam_2);
  param_11[4] = (int)GH_F2U((float)fparam_3);
  param_11[5] = (int)GH_F2U((float)fparam_4);
  param_11[6] = (int)GH_F2U(fVar2);
  param_11[7] = (int)GH_F2U((float)((fVar3 / (float)(fparam_4 - fparam_3))));
  if (0 < param_5) {
    iVar8 = 0;
    do {
      if (0 < param_9) {
        piVar7 = param_11 + iVar8 * 4;
        piVar4 = (int *)(iVar6 * 4 + param_10);
        iVar9 = param_9;
        do {
          piVar7[8] = *piVar4;
          piVar7[9] = piVar4[1];
          piVar7[10] = piVar4[2];
          piVar1 = piVar4 + 3;
          piVar4 = piVar4 + param_8;
          piVar7[0xb] = *piVar1;
          piVar7 = piVar7 + 4;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + param_9;
      iVar6 = iVar6 + param_4;
    } while (iVar5 < param_5);
  }
  return;
}

/* _gleEvalMap2 @ 0xe0df0 (1504 bytes) */
void _gleEvalMap2(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  byte bVar1;
  float fVar2;
  float fVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 uVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  byte *pbVar20;
  double dVar21;
  double dVar22;
  double in_f9;
  double in_f10;
  double dVar23;
  double in_stack_ffffff48;
  double in_stack_ffffff50;
  double in_stack_ffffff58;
  double in_stack_ffffff60;
  double in_stack_ffffff68;
  float local_70;
  float local_6c;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  
  iVar13 = *(int *)(param_1 + 0x7450);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    return;
  }
  iVar9 = *(int *)(param_1 + 0x4858);
  if (iVar9 == *(int *)(param_1 + 0x485c)) {
    (**(code **)(param_1 + 0x4a0c))(param_1);
    iVar9 = *(int *)(param_1 + 0x4858);
  }
  pfVar10 = *(float **)(param_1 + 0x4860);
  pfVar12 = pfVar10;
  if (*(char *)(param_1 + 0x7555) != '\0') {
    if (*(char *)(param_1 + 0x74f2) == '\0') {
      ((void (*)())_gleEvalDomain2Coord)(param_1,iVar13 + 0xfc8,*(undefined4 *)(iVar13 + 0xfa8),
                 *(undefined4 *)(iVar13 + 0xfac),in_r7,in_r8,3,pfVar10,
                 (double)((float)(fparam_1 - (double)*(float *)(iVar13 + 0xfb0)) *
                         *(float *)(iVar13 + 0xfc0)),
                 (double)((float)(fparam_2 - (double)*(float *)(iVar13 + 0xfb8)) *
                         *(float *)(iVar13 + 0xfc4)),fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                 fparam_8,in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,in_stack_ffffff60,
                 in_stack_ffffff68);
    }
    pfVar12 = pfVar10 + 3;
  }
  if (*(char *)(param_1 + 0x7556) != '\0') {
    ((void (*)())_gleEvalDomain2Color)(param_1,iVar13 + 0x1498,*(undefined4 *)(iVar13 + 0x1478),
               *(undefined4 *)(iVar13 + 0x147c),in_r7,in_r8,4,pfVar12,
               (double)((float)(fparam_1 - (double)*(float *)(iVar13 + 0x1480)) *
                       *(float *)(iVar13 + 0x1490)),
               (double)((float)(fparam_2 - (double)*(float *)(iVar13 + 0x1488)) *
                       *(float *)(iVar13 + 0x1494)),fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
               fparam_8,in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,in_stack_ffffff60,
               in_stack_ffffff68);
    if (*(char *)(param_1 + 0x4df8) != '\0') {
      (**(code **)(param_1 + 0x4de0))(param_1,pfVar12);
    }
    pfVar12 = pfVar12 + 4;
  }
  bVar1 = *(byte *)(param_1 + 0x755c);
  if (bVar1 == 8) {
    uVar5 = *(undefined4 *)(iVar13 + 0x1e38);
    iVar14 = iVar13 + 0x1e58;
    fVar2 = (float)(fparam_1 - (double)*(float *)(iVar13 + 0x1e40)) * *(float *)(iVar13 + 0x1e50);
    uVar7 = *(undefined4 *)(iVar13 + 0x1e3c);
    fVar3 = (float)(fparam_2 - (double)*(float *)(iVar13 + 0x1e48)) * *(float *)(iVar13 + 0x1e54);
    uVar8 = 2;
    pfVar11 = pfVar12 + 2;
LAB_000e105c:
    ((void (*)())_gleEvalDomain2Coord)(param_1,iVar14,uVar5,uVar7,in_r7,in_r8,uVar8,pfVar12,(double)fVar2,(double)fVar3,
               fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff48,
               in_stack_ffffff50,in_stack_ffffff58,in_stack_ffffff60,in_stack_ffffff68);
    pfVar12 = pfVar11;
  }
  else if (bVar1 < 9) {
    if (bVar1 == 4) {
      uVar5 = *(undefined4 *)(iVar13 + 0x1c88);
      iVar14 = iVar13 + 0x1ca8;
      fVar2 = (float)(fparam_1 - (double)*(float *)(iVar13 + 0x1c90)) * *(float *)(iVar13 + 0x1ca0);
      uVar7 = *(undefined4 *)(iVar13 + 0x1c8c);
      fVar3 = (float)(fparam_2 - (double)*(float *)(iVar13 + 0x1c98)) * *(float *)(iVar13 + 0x1ca4);
      uVar8 = 1;
      pfVar11 = pfVar12 + 1;
      goto LAB_000e105c;
    }
  }
  else {
    if (bVar1 == 0xc) {
      pfVar11 = pfVar12 + 3;
      ((void (*)())_gleEvalDomain2Coord)(param_1,iVar13 + 0x2198,*(undefined4 *)(iVar13 + 0x2178),
                 *(undefined4 *)(iVar13 + 0x217c),in_r7,in_r8,3,pfVar12,
                 (double)((float)(fparam_1 - (double)*(float *)(iVar13 + 0x2180)) *
                         *(float *)(iVar13 + 0x2190)),
                 (double)((float)(fparam_2 - (double)*(float *)(iVar13 + 0x2188)) *
                         *(float *)(iVar13 + 0x2194)),fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                 fparam_8,in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,in_stack_ffffff60,
                 in_stack_ffffff68);
      uVar18 = *(uint *)(param_1 + 0x486c) | 1;
    }
    else {
      if (bVar1 != 0x10) goto LAB_000e1060;
      pfVar11 = pfVar12 + 4;
      ((void (*)())_gleEvalDomain2Coord)(param_1,iVar13 + 0x2668,*(undefined4 *)(iVar13 + 0x2648),
                 *(undefined4 *)(iVar13 + 0x264c),in_r7,in_r8,4,pfVar12,
                 (double)((float)(fparam_1 - (double)*(float *)(iVar13 + 0x2650)) *
                         *(float *)(iVar13 + 0x2660)),
                 (double)((float)(fparam_2 - (double)*(float *)(iVar13 + 0x2658)) *
                         *(float *)(iVar13 + 0x2664)),fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                 fparam_8,in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,in_stack_ffffff60,
                 in_stack_ffffff68);
      uVar18 = *(uint *)(param_1 + 0x486c) | 3;
    }
    *(uint *)(param_1 + 0x486c) = uVar18;
    pfVar12 = pfVar11;
  }
LAB_000e1060:
  uVar18 = *(uint *)(param_1 + 0x74dc);
  if (uVar18 != 0) {
    iVar16 = iVar13 + 0x37c8;
    pbVar20 = (byte *)(param_1 + 0x7564);
    iVar14 = iVar16;
    iVar15 = iVar16;
    iVar17 = iVar16;
    iVar19 = iVar13;
    do {
      bVar1 = *pbVar20;
      pbVar20 = pbVar20 + 1;
      if (bVar1 == 8) {
        uVar5 = *(undefined4 *)(iVar19 + 0x37a8);
        dVar21 = (double)((float)(fparam_1 - (double)*(float *)(iVar19 + 0x37b0)) *
                         *(float *)(iVar19 + 0x37c0));
        uVar7 = *(undefined4 *)(iVar19 + 0x37ac);
        dVar22 = (double)((float)(fparam_2 - (double)*(float *)(iVar19 + 0x37b8)) *
                         *(float *)(iVar19 + 0x37c4));
        uVar8 = 2;
        pfVar11 = pfVar12 + 2;
        iVar6 = iVar15;
LAB_000e11b0:
        ((void (*)())_gleEvalDomain2Coord)(param_1,iVar6,uVar5,uVar7,in_r7,in_r8,uVar8,pfVar12,dVar21,dVar22,fparam_3,
                   fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,
                   in_stack_ffffff58,in_stack_ffffff60,in_stack_ffffff68);
        pfVar12 = pfVar11;
      }
      else {
        if (8 < bVar1) {
          if (bVar1 == 0xc) {
            uVar5 = *(undefined4 *)(iVar19 + 0x37a8);
            dVar21 = (double)((float)(fparam_1 - (double)*(float *)(iVar19 + 0x37b0)) *
                             *(float *)(iVar19 + 0x37c0));
            uVar7 = *(undefined4 *)(iVar19 + 0x37ac);
            dVar22 = (double)((float)(fparam_2 - (double)*(float *)(iVar19 + 0x37b8)) *
                             *(float *)(iVar19 + 0x37c4));
            uVar8 = 3;
            pfVar11 = pfVar12 + 3;
            iVar6 = iVar16;
          }
          else {
            if (bVar1 != 0x10) goto LAB_000e11b4;
            uVar5 = *(undefined4 *)(iVar19 + 0x37a8);
            dVar21 = (double)((float)(fparam_1 - (double)*(float *)(iVar19 + 0x37b0)) *
                             *(float *)(iVar19 + 0x37c0));
            uVar7 = *(undefined4 *)(iVar19 + 0x37ac);
            dVar22 = (double)((float)(fparam_2 - (double)*(float *)(iVar19 + 0x37b8)) *
                             *(float *)(iVar19 + 0x37c4));
            uVar8 = 4;
            pfVar11 = pfVar12 + 4;
            iVar6 = iVar14;
          }
          goto LAB_000e11b0;
        }
        if (bVar1 == 4) {
          uVar5 = *(undefined4 *)(iVar19 + 0x37a8);
          dVar21 = (double)((float)(fparam_1 - (double)*(float *)(iVar19 + 0x37b0)) *
                           *(float *)(iVar19 + 0x37c0));
          uVar7 = *(undefined4 *)(iVar19 + 0x37ac);
          dVar22 = (double)((float)(fparam_2 - (double)*(float *)(iVar19 + 0x37b8)) *
                           *(float *)(iVar19 + 0x37c4));
          uVar8 = 1;
          pfVar11 = pfVar12 + 1;
          iVar6 = iVar17;
          goto LAB_000e11b0;
        }
      }
LAB_000e11b4:
      uVar18 = uVar18 >> 1;
      iVar14 = iVar14 + 0x660;
      iVar16 = iVar16 + 0x660;
      iVar15 = iVar15 + 0x660;
      iVar19 = iVar19 + 0x660;
      iVar17 = iVar17 + 0x660;
    } while (uVar18 != 0);
  }
  if (*(char *)(param_1 + 0x7554) == '\f') {
    dVar23 = (double)(float)(fparam_2 - (double)*(float *)(iVar13 + 0x488));
    dVar21 = (double)(float)((double)(float)(fparam_1 - (double)*(float *)(iVar13 + 0x480)) *
                            (double)*(float *)(iVar13 + 0x490));
    dVar22 = (double)(float)(dVar23 * (double)*(float *)(iVar13 + 0x494));
    if (*(char *)(param_1 + 0x74f2) == '\0') {
      uVar7 = *(undefined4 *)(iVar13 + 0x47c);
      uVar5 = *(undefined4 *)(iVar13 + 0x478);
      iVar13 = iVar13 + 0x498;
      uVar8 = 3;
LAB_000e1350:
      ((void (*)())_gleEvalDomain2Coord)(param_1,iVar13,uVar5,uVar7,in_r7,in_r8,uVar8,pfVar12,dVar21,dVar22,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,
                 in_stack_ffffff58,in_stack_ffffff60,in_stack_ffffff68);
      goto LAB_000e1388;
    }
    ((void (*)())_gleEvalDomainDeriv2Coord)(param_1,iVar13 + 0x498,*(undefined4 *)(iVar13 + 0x478),
               *(undefined4 *)(iVar13 + 0x47c),in_r7,in_r8,3,&local_70,&local_60,pfVar12,dVar21,
               dVar22,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_f9,in_f10,
               (double)*(float *)(iVar13 + 0x494),(double)*(float *)(iVar13 + 0x490),dVar23);
  }
  else {
    if (*(char *)(param_1 + 0x7554) != '\x10') {
      if ((*(char *)(param_1 + 0x4664) == '\0') || (*(char *)(param_1 + 0x7564) == '\0')) {
        if (*(int *)(param_1 + 0x5434) == 0) {
          return;
        }
        if (*(char *)(param_1 + 0x7564) == '\0') {
          return;
        }
      }
      goto LAB_000e1388;
    }
    dVar23 = (double)(float)(fparam_2 - (double)*(float *)(iVar13 + 0x958));
    dVar21 = (double)(float)((double)(float)(fparam_1 - (double)*(float *)(iVar13 + 0x950)) *
                            (double)*(float *)(iVar13 + 0x960));
    dVar22 = (double)(float)(dVar23 * (double)*(float *)(iVar13 + 0x964));
    if (*(char *)(param_1 + 0x74f2) == '\0') {
      uVar7 = *(undefined4 *)(iVar13 + 0x94c);
      uVar5 = *(undefined4 *)(iVar13 + 0x948);
      iVar13 = iVar13 + 0x968;
      uVar8 = 4;
      goto LAB_000e1350;
    }
    ((void (*)())_gleEvalDomainDeriv2Coord)(param_1,iVar13 + 0x968,*(undefined4 *)(iVar13 + 0x948),
               *(undefined4 *)(iVar13 + 0x94c),in_r7,in_r8,4,&local_70,&local_60,pfVar12,dVar21,
               dVar22,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_f9,in_f10,
               (double)*(float *)(iVar13 + 0x964),(double)*(float *)(iVar13 + 0x960),dVar23);
    ((void (*)())_gleComputeFirstPartial)(param_1,pfVar12,&local_70,&local_60);
  }
  puVar4 = PTR__gleVectorNormalize_00112064;
  *pfVar10 = local_6c * local_58 - local_68 * local_5c;
  pfVar10[1] = local_68 * local_60 - local_70 * local_58;
  pfVar10[2] = local_70 * local_5c - local_6c * local_60;
  (**(code **)puVar4)(param_1,pfVar10,pfVar10);
LAB_000e1388:
  *(int *)(param_1 + 0x48ec) = param_1 + 0x7548;
  uVar5 = (**(code **)(param_1 + 0x489c))(param_1,*(undefined4 *)(param_1 + 0x4860),iVar9);
  *(undefined4 *)(param_1 + 0x48ec) = 0;
  *(undefined4 *)(param_1 + 0x4858) = uVar5;
  return;
}

/* _gleFreeQueryObject @ 0xe13d0 (128 bytes) */
void _gleFreeQueryObject(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_1 + 0x10000;
  iVar4 = 0;
  iVar5 = param_2;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      iVar4 = iVar4 + 1;
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      (**(code **)(*piVar1 + 0x1cc))(*puVar2,*(undefined4 *)(iVar5 + 0x10));
      *(undefined4 *)(iVar5 + 0x10) = 0;
      iVar5 = iVar5 + 4;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  _free(param_2);
  return;
}

/* _gleCreateQueryObject @ 0xe1450 (200 bytes) */
int _gleCreateQueryObject(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  puVar5 = (undefined4 *)_malloc(0x30);
  puVar3 = PTR__gleFreeQueryObject_00110e8c;
  puVar5[2] = 1;
  puVar5[3] = puVar3;
  puVar5[1] = param_2;
  puVar4 = puVar5 + 4;
  *puVar5 = 0;
  iVar7 = 8;
  do {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = param_1 + 0x10000;
  iVar6 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    puVar4 = puVar5 + 4;
    do {
      piVar1 = (int *)(iVar7 + -0x777c);
      puVar2 = (undefined4 *)(iVar7 + -0x7a54);
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 0x2e0;
      (**(code **)(*piVar1 + 0x1c8))(*puVar2,puVar4);
      puVar4 = puVar4 + 1;
    } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x85a4));
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
double _gle_strtod(byte *param_1,undefined4 *param_2)
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  byte *pbStack00000018;
  
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  if (*param_1 == 0x2b) {
LAB_000e1614:
    param_1 = param_1 + 1;
  }
  else if (*param_1 == 0x2d) {
    bVar4 = true;
    goto LAB_000e1614;
  }
  bVar6 = *param_1;
  bVar1 = bVar6 == 0x2e;
  pbStack00000018 = param_1;
  dVar9 = DOUBLE_00108d60;
  if (bVar6 == 0) {
LAB_000e16f8:
    if (bVar1) goto LAB_000e16fc;
  }
  else {
    if (!bVar1) {
      if ((bVar6 != 0x65) && (pbVar7 = param_1, bVar6 != 0x45)) {
        while (bVar6 - 0x30 < 10) {
          bVar6 = pbVar7[1];
          pbVar7 = pbVar7 + 1;
        }
        if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
          pbStack00000018 = pbVar7;
        }
        pbVar7 = pbVar7 + -1;
        if (param_1 <= pbVar7) {
          iVar5 = (int)pbVar7 - (int)(param_1 + -1);
          dVar10 = DOUBLE_00108d68;
          do {
            bVar6 = *pbVar7;
            pbVar7 = pbVar7 + -1;
            dVar9 = ((double)CONCAT44(0x43300000,(int)(char)bVar6 - 0x30U ^ 0x80000000) -
                    DOUBLE_00108d58) * dVar10 + dVar9;
            dVar10 = dVar10 * DOUBLE_00108e10;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        bVar6 = *pbStack00000018;
        bVar2 = true;
        bVar1 = bVar6 == 0x2e;
      }
      goto LAB_000e16f8;
    }
LAB_000e16fc:
    pbVar8 = pbStack00000018 + 1;
    bVar6 = pbStack00000018[1];
    pbVar7 = pbVar8;
    while (bVar6 - 0x30 < 10) {
      pbVar7 = pbVar7 + 1;
      bVar6 = *pbVar7;
    }
    dVar10 = DOUBLE_00108d60;
    if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
      pbStack00000018 = pbVar7;
    }
    while (pbVar7 = pbVar7 + -1, pbVar8 <= pbVar7) {
      dVar10 = dVar10 * DOUBLE_00108e08 +
               (((double)CONCAT44(0x43300000,(int)(char)*pbVar7 - 0x30U ^ 0x80000000) -
               DOUBLE_00108d58));
    }
    bVar2 = true;
    bVar6 = *pbStack00000018;
    dVar9 = dVar10 * DOUBLE_00108e08 + dVar9;
  }
  if ((!bVar2) || ((bVar6 != 0x65 && (bVar6 != 0x45)))) goto LAB_000e18b8;
  pbVar7 = pbStack00000018 + 1;
  if (*pbVar7 == 0x2b) {
LAB_000e17ec:
    pbVar7 = pbStack00000018 + 2;
  }
  else if (*pbVar7 == 0x2d) {
    bVar3 = true;
    goto LAB_000e17ec;
  }
  bVar6 = *pbVar7;
  pbVar8 = pbVar7;
  while (bVar6 - 0x30 < 10) {
    pbVar8 = pbVar8 + 1;
    bVar6 = *pbVar8;
  }
  pbStack00000018 = pbVar7;
  if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
    pbStack00000018 = pbVar8;
  }
  pbVar8 = pbVar8 + -1;
  dVar10 = DOUBLE_00108d60;
  if (pbVar7 <= pbVar8) {
    iVar5 = (int)pbVar8 - (int)(pbVar7 + -1);
    dVar11 = DOUBLE_00108d68;
    do {
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + -1;
      dVar10 = ((double)CONCAT44(0x43300000,(int)(char)bVar6 - 0x30U ^ 0x80000000) - DOUBLE_00108d58
               ) * dVar11 + dVar10;
      dVar11 = dVar11 * DOUBLE_00108e10;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (bVar3) {
    dVar10 = -dVar10;
  }
  dVar10 = (double)((double (*)())_pow_10)((int)dVar10);
  dVar9 = dVar9 * dVar10;
LAB_000e18b8:
  if (bVar4) {
    dVar9 = -dVar9;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = pbStack00000018;
  }
  return dVar9;
}

/* _gle_dtostr @ 0xe18ec (1096 bytes) */
char * _gle_dtostr(undefined4 param_1,undefined4 param_2,char *param_3,uint param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  char *pcVar1;
  char cVar2;
  double dVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  uint local_50 [6];
  
  dVar8 = DOUBLE_00108d60;
  pcVar5 = param_3 + param_4;
  if (fparam_2 <= DOUBLE_00108d60) {
    fparam_2 = DOUBLE_00108e18;
  }
  if (param_4 < 2) {
    return (char *)0x0;
  }
  if (fparam_1 < DOUBLE_00108d60) {
    fparam_1 = -fparam_1;
    *param_3 = '-';
    param_3 = param_3 + 1;
  }
  dVar10 = fparam_2;
  if (dVar8 < fparam_1) {
    if ((fparam_1 < DOUBLE_00108e20) || (DOUBLE_00108e30 < fparam_1)) {
      _frexp(fparam_1,local_50);
      dVar8 = _round(((double)CONCAT44(0x43300000,local_50[0] ^ 0x80000000) - DOUBLE_00108d58) *
                     DOUBLE_00108e28);
      local_50[0] = (uint)(int)dVar8;
      dVar8 = (double)((double (*)())_pow_10)(local_50[0]);
      dVar9 = (double)((double (*)())_pow_10)(-local_50[0]);
      dVar10 = fparam_2 * dVar8;
      dVar8 = fparam_1 * dVar9;
    }
    else {
      local_50[0] = 0;
      dVar8 = fparam_1;
    }
    for (; DOUBLE_00108e10 <= dVar8 + fparam_2 * DOUBLE_00108dc0; dVar8 = dVar8 * DOUBLE_00108e08) {
      local_50[0] = local_50[0] + 1;
      dVar10 = dVar10 * DOUBLE_00108e10;
    }
    for (; dVar8 + fparam_2 * DOUBLE_00108dc0 < DOUBLE_00108d68; dVar8 = dVar8 * DOUBLE_00108e10) {
      local_50[0] = local_50[0] - 1;
      dVar10 = dVar10 * DOUBLE_00108e08;
    }
    if (3 < (int)(((int)local_50[0] >> 0x1f ^ local_50[0]) - ((int)local_50[0] >> 0x1f)))
    goto LAB_000e1adc;
  }
  local_50[0] = 0;
  dVar8 = fparam_1;
  fparam_2 = dVar10;
LAB_000e1adc:
  dVar8 = fparam_2 * DOUBLE_00108dc0 + dVar8;
  dVar10 = _floor(dVar8);
  dVar3 = DOUBLE_00108e10;
  dVar9 = DOUBLE_00108e08;
  pcVar6 = param_3;
  while (fparam_2 < dVar10) {
    if (pcVar6 == pcVar5) {
      return (char *)0x0;
    }
    dVar11 = dVar10 * dVar9;
    dVar10 = _floor(dVar11);
    *pcVar6 = (char)(int)((dVar11 - dVar10) * dVar3) + '0';
    pcVar6 = pcVar6 + 1;
  }
  if (param_3 < pcVar6) {
    iVar4 = (int)pcVar6 - (int)param_3;
    pcVar7 = pcVar6;
    while (1 < iVar4) {
      pcVar7 = pcVar7 + -1;
      cVar2 = *pcVar7;
      *pcVar7 = *param_3;
      *param_3 = cVar2;
      param_3 = param_3 + 1;
      iVar4 = (int)pcVar7 - (int)param_3;
    }
  }
  else {
    *pcVar6 = '0';
    pcVar6 = pcVar6 + 1;
  }
  dVar9 = _floor(dVar8);
  dVar10 = DOUBLE_00108e10;
  dVar8 = dVar8 - dVar9;
  if (dVar8 <= fparam_2) {
    if (local_50[0] == 0) {
      if ((int)pcVar5 - (int)pcVar6 < 2) {
        return (char *)0x0;
      }
      *pcVar6 = '.';
      pcVar6[1] = '0';
      pcVar6 = pcVar6 + 2;
    }
  }
  else {
    if (pcVar6 == pcVar5) {
      return (char *)0x0;
    }
    *pcVar6 = '.';
    pcVar6 = pcVar6 + 1;
    do {
      if (pcVar6 == pcVar5) {
        return (char *)0x0;
      }
      dVar8 = dVar8 * dVar10;
      fparam_2 = fparam_2 * dVar10;
      dVar9 = _floor(dVar8);
      dVar8 = dVar8 - dVar9;
      *pcVar6 = (char)(int)dVar9 + '0';
      pcVar6 = pcVar6 + 1;
    } while (fparam_2 < dVar8);
  }
  if (local_50[0] != 0) {
    if ((int)pcVar5 - (int)pcVar6 < 3) {
      return (char *)0x0;
    }
    *pcVar6 = 'e';
    pcVar7 = pcVar6 + 1;
    pcVar1 = pcVar7;
    if ((int)local_50[0] < 0) {
      local_50[0] = -local_50[0];
      *pcVar7 = '-';
      pcVar7 = pcVar6 + 2;
      pcVar1 = pcVar7;
    }
    while (pcVar6 = pcVar1, 0 < (int)local_50[0]) {
      if (pcVar6 == pcVar5) {
        return (char *)0x0;
      }
      *pcVar6 = (char)local_50[0] + (char)((int)local_50[0] / 10) * -10 + '0';
      local_50[0] = (int)local_50[0] / 10;
      pcVar1 = pcVar6 + 1;
    }
    iVar4 = (int)pcVar6 - (int)pcVar7;
    pcVar1 = pcVar6;
    while (1 < iVar4) {
      pcVar1 = pcVar1 + -1;
      cVar2 = *pcVar1;
      *pcVar1 = *pcVar7;
      *pcVar7 = cVar2;
      pcVar7 = pcVar7 + 1;
      iVar4 = (int)pcVar1 - (int)pcVar7;
    }
  }
  pcVar7 = (char *)0x0;
  if (pcVar6 != pcVar5) {
    *pcVar6 = '\0';
    pcVar7 = pcVar6;
  }
  return pcVar7;
}

