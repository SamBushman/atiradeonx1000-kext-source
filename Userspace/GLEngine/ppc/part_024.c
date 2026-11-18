#include "decls.h"

/* _glRects_Comp @ 0x849dc (132 bytes) */
int _glRects_Comp(glContext, x1, y1, x2, y2)
  undefined4 glContext;
  undefined4 x1;
  undefined4 y1;
  undefined4 x2;
  undefined4 y2;
{
  undefined4 endResult;
  
  _glBegin_Comp(glContext,9);
  _glVertex2s_Comp(glContext,x1,y1);
  _glVertex2s_Comp(glContext,x2,y1);
  _glVertex2s_Comp(glContext,x2,y2);
  _glVertex2s_Comp(glContext,x1,y2);
  endResult = _glEnd_Comp(glContext);
  return endResult;
}

/* _glRects_Exec @ 0x84a60 (188 bytes) */
void _glRects_Exec(int glContext,undefined4 x1,undefined4 y1,undefined4 x2,undefined4 y2,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    return;
  }
  ((void (*)())_glBegin_Exec)(glContext,9,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  _glVertex2s_Exec(glContext,x1,y1);
  _glVertex2s_Exec(glContext,x2,y1);
  _glVertex2s_Exec(glContext,x2,y2);
  _glVertex2s_Exec(glContext,x1,y2);
  _glEnd_Exec(glContext);
  return;
}

/* _glRects_CompExec @ 0x84b1c (80 bytes) */
void _glRects_CompExec(glContext, x1, y1, x2, y2)
  undefined4 glContext;
  undefined4 x1;
  undefined4 y1;
  undefined4 x2;
  undefined4 y2;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glRects_Comp)(glContext,x1,y1,x2,y2);
  ((void (*)())_glRects_Exec)(glContext,x1,y1,x2,y2,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7
                ,incomingFpr8);
  return;
}

/* _glRectdv_Comp @ 0x84b6c (124 bytes) */
int _glRectdv_Comp(glContext, v1, v2)
  undefined4 glContext;
  double *v1;
  double *v2;
{
  undefined4 uVar1;
  
  _glBegin_Comp(glContext,9);
  ((float * (*)())_glVertex2d_Comp)(glContext,*v1,v1[1]);
  ((float * (*)())_glVertex2d_Comp)(glContext,*v2,v1[1]);
  ((float * (*)())_glVertex2d_Comp)(glContext,*v2,v2[1]);
  ((float * (*)())_glVertex2d_Comp)(glContext,*v1,v2[1]);
  uVar1 = _glEnd_Comp(glContext);
  return uVar1;
}

/* _glRectdv_Exec @ 0x84be8 (180 bytes) */
void _glRectdv_Exec(int glContext,double *v1,double *v2,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    return;
  }
  ((void (*)())_glBegin_Exec)(glContext,9,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  ((void (*)())_glVertex2d_Exec)(glContext,*v1,v1[1]);
  ((void (*)())_glVertex2d_Exec)(glContext,*v2,v1[1]);
  ((void (*)())_glVertex2d_Exec)(glContext,*v2,v2[1]);
  ((void (*)())_glVertex2d_Exec)(glContext,*v1,v2[1]);
  _glEnd_Exec(glContext);
  return;
}

/* _glRectdv_CompExec @ 0x84c9c (64 bytes) */
void _glRectdv_CompExec(glContext, v1, v2)
  undefined4 glContext;
  undefined4 v1;
  undefined4 v2;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glRectdv_Comp)(glContext,v1,v2);
  ((void (*)())_glRectdv_Exec)(glContext,v1,v2,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRectfv_Comp @ 0x84cdc (124 bytes) */
int _glRectfv_Comp(glContext, v1, v2)
  undefined4 glContext;
  float *v1;
  float *v2;
{
  undefined4 endResult;
  
  _glBegin_Comp(glContext,9);
  ((float * (*)())_glVertex2f_Comp)(glContext,(double)*v1,(double)v1[1]);
  ((float * (*)())_glVertex2f_Comp)(glContext,(double)*v2,(double)v1[1]);
  ((float * (*)())_glVertex2f_Comp)(glContext,(double)*v2,(double)v2[1]);
  ((float * (*)())_glVertex2f_Comp)(glContext,(double)*v1,(double)v2[1]);
  endResult = _glEnd_Comp(glContext);
  return endResult;
}

/* _glRectfv_Exec @ 0x84d58 (180 bytes) */
void _glRectfv_Exec(int glContext,undefined4 v1,undefined4 v2,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    return;
  }
  ((void (*)())_glBegin_Exec)(glContext,9,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  ((void (*)())_glVertex2f_Exec)(glContext,(double)*(float *)v1,(double)((float *)v1)[1]);
  ((void (*)())_glVertex2f_Exec)(glContext,(double)*(float *)v2,(double)((float *)v1)[1]);
  ((void (*)())_glVertex2f_Exec)(glContext,(double)*(float *)v2,(double)((float *)v2)[1]);
  ((void (*)())_glVertex2f_Exec)(glContext,(double)*(float *)v1,(double)((float *)v2)[1]);
  _glEnd_Exec(glContext);
  return;
}

/* _glRectfv_CompExec @ 0x84e0c (64 bytes) */
void _glRectfv_CompExec(glContext, v1, v2)
  undefined4 glContext;
  undefined4 v1;
  undefined4 v2;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glRectfv_Comp)(glContext,v1,v2);
  ((void (*)())_glRectfv_Exec)(glContext,v1,v2,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRectiv_Comp @ 0x84e4c (124 bytes) */
int _glRectiv_Comp(glContext, v1, v2)
  undefined4 glContext;
  undefined4 *v1;
  undefined4 *v2;
{
  undefined4 uVar1;
  
  _glBegin_Comp(glContext,9);
  _glVertex2i_Comp(glContext,*v1,v1[1]);
  _glVertex2i_Comp(glContext,*v2,v1[1]);
  _glVertex2i_Comp(glContext,*v2,v2[1]);
  _glVertex2i_Comp(glContext,*v1,v2[1]);
  uVar1 = _glEnd_Comp(glContext);
  return uVar1;
}

/* _glRectiv_Exec @ 0x84ec8 (180 bytes) */
void _glRectiv_Exec(int glContext,undefined4 *v1,undefined4 *v2,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    return;
  }
  ((void (*)())_glBegin_Exec)(glContext,9,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  _glVertex2i_Exec(glContext,*v1,v1[1]);
  _glVertex2i_Exec(glContext,*v2,v1[1]);
  _glVertex2i_Exec(glContext,*v2,v2[1]);
  _glVertex2i_Exec(glContext,*v1,v2[1]);
  _glEnd_Exec(glContext);
  return;
}

/* _glRectiv_CompExec @ 0x84f7c (64 bytes) */
void _glRectiv_CompExec(glContext, v1, v2)
  undefined4 glContext;
  undefined4 v1;
  undefined4 v2;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glRectiv_Comp)(glContext,v1,v2);
  ((void (*)())_glRectiv_Exec)(glContext,v1,v2,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRectsv_Comp @ 0x84fbc (124 bytes) */
int _glRectsv_Comp(glContext, v1, v2)
  undefined4 glContext;
  short *v1;
  short *v2;
{
  undefined4 uVar1;
  
  _glBegin_Comp(glContext,9);
  _glVertex2s_Comp(glContext,(int)*v1,(int)v1[1]);
  _glVertex2s_Comp(glContext,(int)*v2,(int)v1[1]);
  _glVertex2s_Comp(glContext,(int)*v2,(int)v2[1]);
  _glVertex2s_Comp(glContext,(int)*v1,(int)v2[1]);
  uVar1 = _glEnd_Comp(glContext);
  return uVar1;
}

/* _glRectsv_Exec @ 0x85038 (180 bytes) */
void _glRectsv_Exec(int glContext,short *v1,short *v2,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    return;
  }
  ((void (*)())_glBegin_Exec)(glContext,9,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  _glVertex2s_Exec(glContext,(int)*v1,(int)v1[1]);
  _glVertex2s_Exec(glContext,(int)*v2,(int)v1[1]);
  _glVertex2s_Exec(glContext,(int)*v2,(int)v2[1]);
  _glVertex2s_Exec(glContext,(int)*v1,(int)v2[1]);
  _glEnd_Exec(glContext);
  return;
}

/* _glRectsv_CompExec @ 0x850ec (64 bytes) */
void _glRectsv_CompExec(glContext, v1, v2)
  undefined4 glContext;
  undefined4 v1;
  undefined4 v2;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glRectsv_Comp)(glContext,v1,v2);
  ((void (*)())_glRectsv_Exec)(glContext,v1,v2,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRotateZ_ListExec @ 0x8512c (44 bytes) */
undefined4 _glRotateZ_ListExec(undefined4 glContext,float *listRecord,double unusedFloatArg1,double unusedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  double incomingStack_ffffffc8;
  double incomingStack_ffffffd0;
  double incomingStack_ffffffd8;
  
  ((void (*)())_glRotateZ_Exec)(glContext,(double)*listRecord,(double)listRecord[1],forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,
                  forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffffb8,incomingStack_ffffffc0,incomingStack_ffffffc8,
                  incomingStack_ffffffd0,incomingStack_ffffffd8);
  return 8;
}

/* _glRotateXYZ_ListExec @ 0x85158 (644 bytes) */
undefined4 _glRotateXYZ_ListExec(int glContext,float *listRecord,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float rotElem1;
  float rotElem4;
  float rotElem7;
  float matrixElem4;
  float secondMatrixElem3;
  float secondMatrixElem4;
  float matrixElem3;
  float rotElem0;
  float rotElem3;
  float rotElem6;
  float matrixElem5;
  float secondMatrixElem10;
  float secondMatrixElem0;
  float matrixElem11;
  float matrixElem0;
  float secondMatrixElem11;
  float secondMatrixElem8;
  float matrixElem10;
  float rotElem8;
  float rotElem2;
  float matrixElem6;
  float secondMatrixElem5;
  float rotElem5;
  float matrixElem8;
  float secondMatrixElem6;
  float matrixElem1;
  float secondMatrixElem1;
  float matrixElem7;
  float secondMatrixElem7;
  float matrixElem2;
  float secondMatrixElem2;
  float matrixElem9;
  float secondMatrixElem9;
  float *currentMatrix;
  float *secondMatrix;
  uint uVar20;
  uint uVar21;
  
  currentMatrix = *(float **)(glContext + 0x4fec);
  uVar21 = *(uint *)(glContext + 0x50a8);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    rotElem1 = listRecord[1];
    rotElem4 = listRecord[4];
    rotElem7 = listRecord[7];
    matrixElem4 = currentMatrix[4];
    rotElem0 = *listRecord;
    rotElem3 = listRecord[3];
    rotElem6 = listRecord[6];
    matrixElem5 = currentMatrix[5];
    matrixElem0 = *currentMatrix;
    rotElem8 = listRecord[8];
    rotElem2 = listRecord[2];
    matrixElem6 = currentMatrix[6];
    rotElem5 = listRecord[5];
    matrixElem8 = currentMatrix[8];
    matrixElem1 = currentMatrix[1];
    matrixElem7 = currentMatrix[7];
    matrixElem2 = currentMatrix[2];
    matrixElem9 = currentMatrix[9];
    currentMatrix[8] = matrixElem8 * rotElem8 + (matrixElem0 * rotElem6 + matrixElem4 * rotElem7);
    *currentMatrix = matrixElem8 * rotElem2 + (matrixElem0 * rotElem0 + matrixElem4 * rotElem1);
    currentMatrix[4] = matrixElem8 * rotElem5 + (matrixElem0 * rotElem3 + matrixElem4 * rotElem4);
    matrixElem3 = currentMatrix[3];
    matrixElem10 = currentMatrix[10];
    currentMatrix[9] = matrixElem9 * rotElem8 + (matrixElem1 * rotElem6 + matrixElem5 * rotElem7);
    currentMatrix[1] = matrixElem9 * rotElem2 + (matrixElem1 * rotElem0 + matrixElem5 * rotElem1);
    currentMatrix[5] = matrixElem9 * rotElem5 + (matrixElem1 * rotElem3 + matrixElem5 * rotElem4);
    matrixElem11 = currentMatrix[0xb];
    currentMatrix[10] = matrixElem10 * rotElem8 + (matrixElem2 * rotElem6 + matrixElem6 * rotElem7);
    currentMatrix[2] = matrixElem10 * rotElem2 + (matrixElem2 * rotElem0 + matrixElem6 * rotElem1);
    currentMatrix[6] = matrixElem10 * rotElem5 + (matrixElem2 * rotElem3 + matrixElem6 * rotElem4);
    currentMatrix[0xb] = matrixElem11 * rotElem8 + (matrixElem3 * rotElem6 + matrixElem7 * rotElem7);
    currentMatrix[3] = matrixElem11 * rotElem2 + (matrixElem3 * rotElem0 + matrixElem7 * rotElem1);
    currentMatrix[7] = matrixElem11 * rotElem5 + (matrixElem3 * rotElem3 + matrixElem7 * rotElem4);
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | uVar21;
    uVar20 = *(uint *)(glContext + 0x50b0);
    if ((uVar21 & ~uVar20 & *(uint *)(glContext + 0x505c) & 0xfffffc) != 0) {
      secondMatrix = *(float **)(glContext + 0x4ff0);
      uVar21 = uVar21 & 0xff000003;
      secondMatrixElem4 = secondMatrix[4];
      secondMatrixElem0 = *secondMatrix;
      secondMatrixElem8 = secondMatrix[8];
      secondMatrixElem5 = secondMatrix[5];
      secondMatrixElem6 = secondMatrix[6];
      secondMatrixElem1 = secondMatrix[1];
      secondMatrixElem7 = secondMatrix[7];
      secondMatrixElem2 = secondMatrix[2];
      secondMatrixElem9 = secondMatrix[9];
      secondMatrix[8] = secondMatrixElem8 * rotElem8 + (secondMatrixElem0 * rotElem6 + secondMatrixElem4 * rotElem7);
      *secondMatrix = secondMatrixElem8 * rotElem2 + (secondMatrixElem0 * rotElem0 + secondMatrixElem4 * rotElem1);
      secondMatrix[4] = secondMatrixElem8 * rotElem5 + (secondMatrixElem0 * rotElem3 + secondMatrixElem4 * rotElem4);
      secondMatrixElem3 = secondMatrix[3];
      secondMatrixElem10 = secondMatrix[10];
      secondMatrix[9] = secondMatrixElem9 * rotElem8 + (secondMatrixElem1 * rotElem6 + secondMatrixElem5 * rotElem7);
      secondMatrix[1] = secondMatrixElem9 * rotElem2 + (secondMatrixElem1 * rotElem0 + secondMatrixElem5 * rotElem1);
      secondMatrix[5] = secondMatrixElem9 * rotElem5 + (secondMatrixElem1 * rotElem3 + secondMatrixElem5 * rotElem4);
      secondMatrixElem11 = secondMatrix[0xb];
      secondMatrix[10] = secondMatrixElem10 * rotElem8 + (secondMatrixElem2 * rotElem6 + secondMatrixElem6 * rotElem7);
      secondMatrix[2] = secondMatrixElem10 * rotElem2 + (secondMatrixElem2 * rotElem0 + secondMatrixElem6 * rotElem1);
      secondMatrix[6] = secondMatrixElem10 * rotElem5 + (secondMatrixElem2 * rotElem3 + secondMatrixElem6 * rotElem4);
      secondMatrix[0xb] = secondMatrixElem11 * rotElem8 + (secondMatrixElem3 * rotElem6 + secondMatrixElem7 * rotElem7);
      secondMatrix[3] = secondMatrixElem11 * rotElem2 + (secondMatrixElem3 * rotElem0 + secondMatrixElem7 * rotElem1);
      secondMatrix[7] = secondMatrixElem11 * rotElem5 + (secondMatrixElem3 * rotElem3 + secondMatrixElem7 * rotElem4);
      uVar20 = *(uint *)(glContext + 0x50b0);
    }
    *(uint *)(glContext + 0x50b0) = uVar20 | uVar21;
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return 0x24;
}

/* _glRotateZ_Comp @ 0x853dc (100 bytes) */
void _glRotateZ_Comp(undefined4 glContext,float forwardedFloatArg1,float fparam_2)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glRotateZ_ListExec_00110288,8);
  if (listRecord != (float *)0x0) {
    listRecord[1] = (float)fparam_2;
    *listRecord = (float)forwardedFloatArg1;
  }
  return;
}

/* _glRotateXYZ_Comp @ 0x85440 (292 bytes) */
void _glRotateXYZ_Comp(int glContext,double angle,float x,float y,float z)
{
  float unitAxisZ;
  float unitAxisX;
  float unitAxisY;
  float sinAngle;
  float cosAngle;
  float one;
  float fVar7;
  float xyOneMinusCos;
  float yzOneMinusCos;
  float *listRecord;
  double dVar11;
  double sinValue;
  
  one = *(float *)(glContext + 0x24);
  listRecord = (float *)_gleAddListItem(glContext,PTR__glRotateXYZ_ListExec_00110284,0x24);
  if (listRecord != (float *)0x0) {
    dVar11 = (double)FLOAT_00108e84;
    sinValue = _sin((double)(float)(angle * dVar11));
    sinAngle = (float)sinValue;
    dVar11 = _cos((double)(float)(angle * dVar11));
    cosAngle = (float)dVar11;
    dVar11 = _sqrt((double)(z * z + (x * x + (y * y))));
    fVar7 = one - cosAngle;
    dVar11 = (double)(one / (float)dVar11);
    unitAxisZ = (float)(z * dVar11);
    unitAxisX = (float)(x * dVar11);
    unitAxisY = (float)(y * dVar11);
    xyOneMinusCos = unitAxisX * unitAxisY * fVar7;
    yzOneMinusCos = unitAxisY * unitAxisZ * fVar7;
    fVar7 = unitAxisZ * unitAxisX * fVar7;
    listRecord[8] = cosAngle * (one - unitAxisZ * unitAxisZ) + unitAxisZ * unitAxisZ;
    *listRecord = cosAngle * (one - unitAxisX * unitAxisX) + unitAxisX * unitAxisX;
    listRecord[3] = xyOneMinusCos - unitAxisZ * sinAngle;
    listRecord[4] = cosAngle * (one - unitAxisY * unitAxisY) + unitAxisY * unitAxisY;
    listRecord[6] = fVar7 + unitAxisY * sinAngle;
    listRecord[7] = yzOneMinusCos - unitAxisX * sinAngle;
    listRecord[1] = xyOneMinusCos + unitAxisZ * sinAngle;
    listRecord[2] = fVar7 - unitAxisY * sinAngle;
    listRecord[5] = yzOneMinusCos + unitAxisX * sinAngle;
  }
  return;
}

/* _glRotateXYZ_Exec @ 0x85564 (824 bytes) */
void _glRotateXYZ_Exec(int glContext,double angle,float x,float y,float z)
{
  float unitAxisZ;
  float secondMatrixElem10;
  float secondMatrixElem0;
  float matrixElem11;
  float matrixElem1;
  float unitAxisX;
  float secondMatrixElem11;
  float secondMatrixElem8;
  float matrixElem7;
  float unitAxisY;
  float secondMatrixElem5;
  float matrixElem2;
  float sinAngle;
  float secondMatrixElem6;
  float matrixElem9;
  float cosAngle;
  float secondMatrixElem1;
  float matrixElem3;
  float one;
  float secondMatrixElem3;
  float secondMatrixElem4;
  float matrixElem6;
  float matrixElem4;
  float secondMatrixElem7;
  float matrixElem10;
  float matrixElem0;
  float secondMatrixElem2;
  float matrixElem8;
  float secondMatrixElem9;
  float matrixElem5;
  float fVar11;
  float rotElem8;
  float rotElem0;
  float rotElem4;
  float fVar15;
  float fVar16;
  float rotElem1;
  float rotElem7;
  float rotElem6;
  uint uVar20;
  uint uVar21;
  float *currentMatrix;
  float *secondMatrix;
  double dVar23;
  double sinValue;
  
  uVar21 = *(uint *)(glContext + 0x50a8);
  currentMatrix = *(float **)(glContext + 0x4fec);
  one = *(float *)(glContext + 0x24);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    dVar23 = (double)FLOAT_00108e84;
    sinValue = _sin((double)(float)(angle * dVar23));
    sinAngle = (float)sinValue;
    dVar23 = _cos((double)(float)(angle * dVar23));
    cosAngle = (float)dVar23;
    dVar23 = _sqrt((double)(z * z + (x * x + (y * y))));
    fVar11 = one - cosAngle;
    matrixElem4 = currentMatrix[4];
    matrixElem0 = *currentMatrix;
    matrixElem8 = currentMatrix[8];
    dVar23 = (double)(one / (float)dVar23);
    unitAxisZ = (float)(z * dVar23);
    unitAxisX = (float)(x * dVar23);
    unitAxisY = (float)(y * dVar23);
    fVar15 = unitAxisX * unitAxisY * fVar11;
    fVar16 = unitAxisY * unitAxisZ * fVar11;
    rotElem4 = cosAngle * (one - unitAxisY * unitAxisY) + unitAxisY * unitAxisY;
    rotElem7 = fVar16 - unitAxisX * sinAngle;
    fVar11 = unitAxisZ * unitAxisX * fVar11;
    rotElem1 = fVar15 + unitAxisZ * sinAngle;
    fVar15 = fVar15 - unitAxisZ * sinAngle;
    rotElem0 = cosAngle * (one - unitAxisX * unitAxisX) + unitAxisX * unitAxisX;
    rotElem6 = fVar11 + unitAxisY * sinAngle;
    matrixElem5 = currentMatrix[5];
    rotElem8 = cosAngle * (one - unitAxisZ * unitAxisZ) + unitAxisZ * unitAxisZ;
    matrixElem6 = currentMatrix[6];
    fVar11 = fVar11 - unitAxisY * sinAngle;
    fVar16 = fVar16 + unitAxisX * sinAngle;
    matrixElem1 = currentMatrix[1];
    matrixElem7 = currentMatrix[7];
    matrixElem2 = currentMatrix[2];
    matrixElem9 = currentMatrix[9];
    currentMatrix[8] = matrixElem8 * rotElem8 + (matrixElem0 * rotElem6 + matrixElem4 * rotElem7);
    *currentMatrix = matrixElem8 * fVar11 + (matrixElem0 * rotElem0 + matrixElem4 * rotElem1);
    currentMatrix[4] = matrixElem8 * fVar16 + (matrixElem0 * fVar15 + matrixElem4 * rotElem4);
    matrixElem3 = currentMatrix[3];
    matrixElem10 = currentMatrix[10];
    currentMatrix[9] = matrixElem9 * rotElem8 + (matrixElem1 * rotElem6 + matrixElem5 * rotElem7);
    currentMatrix[1] = matrixElem9 * fVar11 + (matrixElem1 * rotElem0 + matrixElem5 * rotElem1);
    currentMatrix[5] = matrixElem9 * fVar16 + (matrixElem1 * fVar15 + matrixElem5 * rotElem4);
    matrixElem11 = currentMatrix[0xb];
    currentMatrix[10] = matrixElem10 * rotElem8 + (matrixElem2 * rotElem6 + matrixElem6 * rotElem7);
    currentMatrix[2] = matrixElem10 * fVar11 + (matrixElem2 * rotElem0 + matrixElem6 * rotElem1);
    currentMatrix[6] = matrixElem10 * fVar16 + (matrixElem2 * fVar15 + matrixElem6 * rotElem4);
    currentMatrix[0xb] = matrixElem11 * rotElem8 + (matrixElem3 * rotElem6 + matrixElem7 * rotElem7);
    currentMatrix[3] = matrixElem11 * fVar11 + (matrixElem3 * rotElem0 + matrixElem7 * rotElem1);
    currentMatrix[7] = matrixElem11 * fVar16 + (matrixElem3 * fVar15 + matrixElem7 * rotElem4);
    uVar20 = *(uint *)(glContext + 0x50b0);
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | uVar21;
    if ((uVar21 & ~uVar20 & *(uint *)(glContext + 0x505c) & 0xfffffc) != 0) {
      secondMatrix = *(float **)(glContext + 0x4ff0);
      uVar21 = uVar21 & 0xff000003;
      secondMatrixElem4 = secondMatrix[4];
      secondMatrixElem0 = *secondMatrix;
      secondMatrixElem8 = secondMatrix[8];
      secondMatrixElem5 = secondMatrix[5];
      secondMatrixElem6 = secondMatrix[6];
      secondMatrixElem1 = secondMatrix[1];
      secondMatrixElem7 = secondMatrix[7];
      secondMatrixElem2 = secondMatrix[2];
      secondMatrixElem9 = secondMatrix[9];
      secondMatrix[8] = secondMatrixElem8 * rotElem8 + (secondMatrixElem0 * rotElem6 + secondMatrixElem4 * rotElem7);
      *secondMatrix = secondMatrixElem8 * fVar11 + (secondMatrixElem0 * rotElem0 + secondMatrixElem4 * rotElem1);
      secondMatrix[4] = secondMatrixElem8 * fVar16 + (secondMatrixElem0 * fVar15 + secondMatrixElem4 * rotElem4);
      secondMatrixElem3 = secondMatrix[3];
      secondMatrixElem10 = secondMatrix[10];
      secondMatrix[9] = secondMatrixElem9 * rotElem8 + (secondMatrixElem1 * rotElem6 + secondMatrixElem5 * rotElem7);
      secondMatrix[1] = secondMatrixElem9 * fVar11 + (secondMatrixElem1 * rotElem0 + secondMatrixElem5 * rotElem1);
      secondMatrix[5] = secondMatrixElem9 * fVar16 + (secondMatrixElem1 * fVar15 + secondMatrixElem5 * rotElem4);
      secondMatrixElem11 = secondMatrix[0xb];
      secondMatrix[10] = secondMatrixElem10 * rotElem8 + (secondMatrixElem2 * rotElem6 + secondMatrixElem6 * rotElem7);
      secondMatrix[2] = secondMatrixElem10 * fVar11 + (secondMatrixElem2 * rotElem0 + secondMatrixElem6 * rotElem1);
      secondMatrix[6] = secondMatrixElem10 * fVar16 + (secondMatrixElem2 * fVar15 + secondMatrixElem6 * rotElem4);
      secondMatrix[0xb] = secondMatrixElem11 * rotElem8 + (secondMatrixElem3 * rotElem6 + secondMatrixElem7 * rotElem7);
      secondMatrix[3] = secondMatrixElem11 * fVar11 + (secondMatrixElem3 * rotElem0 + secondMatrixElem7 * rotElem1);
      secondMatrix[7] = secondMatrixElem11 * fVar16 + (secondMatrixElem3 * fVar15 + secondMatrixElem7 * rotElem4);
      uVar20 = *(uint *)(glContext + 0x50b0);
    }
    *(uint *)(glContext + 0x50b0) = uVar20 | uVar21;
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glRotated_Comp @ 0x8589c (416 bytes) */
void _glRotated_Comp(int glContext,double angle,double x,double y,double z)
{
  double dVar1;
  double sinValue;
  double dVar2;
  
  dVar1 = (double)*(float *)(glContext + 0x20);
  if ((y == dVar1) && (z == dVar1)) {
    dVar2 = DOUBLE_00108db8;
    if (x < dVar1) {
      dVar2 = DOUBLE_00108db0;
    }
    sinValue = _sin(angle * dVar2);
    dVar2 = _cos(angle * dVar2);
    ((void (*)())_glRotateX_Comp)(glContext,(double)(float)sinValue,(double)(float)dVar2);
    return;
  }
  if ((x == dVar1) && (z == dVar1)) {
    dVar2 = DOUBLE_00108db8;
    if (y < dVar1) {
      dVar2 = DOUBLE_00108db0;
    }
    sinValue = _sin(angle * dVar2);
    dVar2 = _cos(angle * dVar2);
    ((void (*)())_glRotateY_Comp)(glContext,(double)(float)sinValue,(double)(float)dVar2);
    return;
  }
  if ((x == dVar1) && (y == dVar1)) {
    dVar2 = DOUBLE_00108db8;
    if (z < dVar1) {
      dVar2 = DOUBLE_00108db0;
    }
    sinValue = _sin(angle * dVar2);
    dVar2 = _cos(angle * dVar2);
    ((void (*)())_glRotateZ_Comp)(glContext,(double)(float)sinValue,(double)(float)dVar2);
    return;
  }
  ((void (*)())_glRotateXYZ_Comp)(glContext,(double)(float)angle,(double)(float)x,(double)(float)y,
                    (double)(float)z);
  return;
}

/* _glRotated_Exec @ 0x85a3c (416 bytes) */
void _glRotated_Exec(int glContext,double angle,double x,double y,double z)
{
  undefined4 in_LR;
  double dVar1;
  double sinValue;
  double dVar2;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  dVar1 = (double)*(float *)(glContext + 0x20);
  if ((y == dVar1) && (z == dVar1)) {
    dVar2 = DOUBLE_00108db8;
    if (x < dVar1) {
      dVar2 = DOUBLE_00108db0;
    }
    sinValue = _sin(angle * dVar2);
    dVar2 = _cos(angle * dVar2);
    ((void (*)())_glRotateX_Exec)(glContext,(double)(float)sinValue,(double)(float)dVar2,y,z,incomingFpr5,incomingFpr6,
                    incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((x == dVar1) && (z == dVar1)) {
    dVar2 = DOUBLE_00108db8;
    if (y < dVar1) {
      dVar2 = DOUBLE_00108db0;
    }
    sinValue = _sin(angle * dVar2);
    dVar2 = _cos(angle * dVar2);
    ((void (*)())_glRotateY_Exec)(glContext,(double)(float)sinValue,(double)(float)dVar2,y,z,incomingFpr5,incomingFpr6,
                    incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((x == dVar1) && (y == dVar1)) {
    dVar2 = DOUBLE_00108db8;
    if (z < dVar1) {
      dVar2 = DOUBLE_00108db0;
    }
    sinValue = _sin(angle * dVar2);
    dVar2 = _cos(angle * dVar2);
    ((void (*)())_glRotateZ_Exec)(glContext,(double)(float)sinValue,(double)(float)dVar2,y,z,incomingFpr5,incomingFpr6,
                    incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  ((void (*)())_glRotateXYZ_Exec)(glContext,(double)(float)angle,(double)(float)x,(double)(float)y,
                    (double)(float)z);
  return;
}

/* _glRotatef_CompExec @ 0x85bdc (536 bytes) */
void _glRotatef_CompExec(int glContext,double angle,double x,double y,double z)
{
  float fVar1;
  double sinValue;
  double cosValue;
  double fparam_3_00;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  fparam_3_00 = (double)*(float *)(glContext + 0x20);
  if ((y == fparam_3_00) && (z == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (x < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    sinValue = _sin((double)(float)(angle * (double)fVar1));
    cosValue = _cos((double)(float)(angle * (double)fVar1));
    ((void (*)())_glRotateX_Comp)(glContext,(double)(float)sinValue,(double)(float)cosValue);
    ((void (*)())_glRotateX_Exec)(glContext,(double)(float)sinValue,(double)(float)cosValue,fparam_3_00,z,incomingFpr5,
                    incomingFpr6,incomingFpr7,incomingFpr8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((x == fparam_3_00) && (z == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (y < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    sinValue = _sin((double)(float)(angle * (double)fVar1));
    cosValue = _cos((double)(float)(angle * (double)fVar1));
    ((void (*)())_glRotateY_Comp)(glContext,(double)(float)sinValue,(double)(float)cosValue);
    ((void (*)())_glRotateY_Exec)(glContext,(double)(float)sinValue,(double)(float)cosValue,fparam_3_00,z,incomingFpr5,
                    incomingFpr6,incomingFpr7,incomingFpr8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((x == fparam_3_00) && (y == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (z < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    sinValue = _sin((double)(float)(angle * (double)fVar1));
    cosValue = _cos((double)(float)(angle * (double)fVar1));
    ((void (*)())_glRotateZ_Comp)(glContext,(double)(float)sinValue,(double)(float)cosValue);
    ((void (*)())_glRotateZ_Exec)(glContext,(double)(float)sinValue,(double)(float)cosValue,fparam_3_00,z,incomingFpr5,
                    incomingFpr6,incomingFpr7,incomingFpr8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  ((void (*)())_glRotateXYZ_Comp)(glContext,angle,x,y,z);
  ((void (*)())_glRotateXYZ_Exec)(glContext,angle,x,y,z);
  return;
}

/* _glSampleCoverage_ListExec @ 0x85df4 (44 bytes) */
int _glSampleCoverage_ListExec(glContext, listRecord)
  undefined4 glContext;
  float *listRecord;
{
  ((void (*)())_glSampleCoverage_Exec)(glContext,listRecord,(uint)*(byte *)(listRecord + 1),(double)*listRecord);
  return 8;
}

/* _glSamplePass_ListExec @ 0x85e20 (40 bytes) */
int _glSamplePass_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glSamplePass_Exec)(glContext,*listRecord);
  return 4;
}

/* _glSampleCoverage_Comp @ 0x85e48 (92 bytes) */
float * _glSampleCoverage_Comp(undefined4 glContext,undefined4 valueShadow,undefined4 invert,float value)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glSampleCoverage_ListExec_00110298,8);
  if (listRecord != (float *)0x0) {
    *(undefined1 *)(listRecord + 1) = (undefined1)invert;
    *listRecord = (float)value;
  }
  return listRecord;
}

/* _glSamplePass_Comp @ 0x85ea4 (76 bytes) */
int _glSamplePass_Comp(glContext, pass)
  undefined4 glContext;
  undefined4 pass;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glSamplePass_ListExec_00110294,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = pass;
  }
  return listRecord;
}

/* _glSampleCoverage_Exec @ 0x85ef0 (32 bytes) */
void _glSampleCoverage_Exec(int glContext,undefined4 valueShadow,int invert,float value)
{
  *(float *)(glContext + 0x41ec) = (float)value;
  *(byte *)(glContext + 0x41f4) = (byte)((uint)-invert >> 0x1f);
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x20000000;
  return;
}

/* _glSamplePass_Exec @ 0x85f10 (4 bytes) */
void _glSamplePass_Exec()
{
  return;
}

/* _glSampleCoverage_CompExec @ 0x85f14 (72 bytes) */
void _glSampleCoverage_CompExec(undefined4 glContext,undefined4 valueShadow,undefined4 invert,float value)
{
  undefined4 r4AfterCall;
  
  ((float * (*)())_glSampleCoverage_Comp)(glContext,valueShadow,invert,value);
  ((void (*)())_glSampleCoverage_Exec)(glContext,r4AfterCall,invert,value);
  return;
}

/* _glSamplePass_CompExec @ 0x85f5c (56 bytes) */
void _glSamplePass_CompExec(glContext, pass)
  undefined4 glContext;
  undefined4 pass;
{
  ((int (*)())_glSamplePass_Comp)(glContext,pass);
  ((void (*)())_glSamplePass_Exec)(glContext,pass);
  return;
}

/* _glScaled_Comp @ 0x85f94 (128 bytes) */
float * _glScaled_Comp(undefined4 glContext,double x,double y,double z)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glScale_ListExec_0011029c,0xc);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)x;
    listRecord[1] = (float)y;
    listRecord[2] = (float)z;
  }
  return listRecord;
}

/* _glScaled_CompExec @ 0x86014 (96 bytes) */
void _glScaled_CompExec(undefined4 glContext,double x,double y,double z)
{
  ((float * (*)())_glScaled_Comp)(glContext,x,y,z);
  ((void (*)())_glScale_Exec)(glContext,(double)(float)x,(double)(float)y,(double)(float)z);
  return;
}

/* _glScissor_ListExec @ 0x86074 (56 bytes) */
undefined4 _glScissor_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glScissor_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3],forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                  forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 0x10;
}

/* _glScissor_Comp @ 0x860ac (100 bytes) */
int _glScissor_Comp(glContext, x, y, width, height)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 height;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glScissor_ListExec_001102a0,0x10);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[3] = height;
    *listRecord = x;
    listRecord[1] = y;
    listRecord[2] = width;
  }
  return listRecord;
}

/* _glScissor_CompExec @ 0x86110 (80 bytes) */
void _glScissor_CompExec(glContext, x, y, width, height)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 height;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glScissor_Comp)(glContext,x,y,width,height);
  ((void (*)())_glScissor_Exec)(glContext,x,y,width,height,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,
                  incomingFpr7,incomingFpr8);
  return;
}

/* _glSelectBuffer_Exec @ 0x86160 (100 bytes) */
void _glSelectBuffer_Exec(glContext, size, buffer)
  int glContext;
  int size;
  undefined4 buffer;
{
  undefined4 glErrorCode;
  
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4e1c) != 0x1c02)) {
    if (-1 < size) {
      *(int *)(glContext + 0x4e28) = size;
      *(undefined1 *)(glContext + 0x4fc8) = 0;
      *(undefined4 *)(glContext + 0x4e24) = buffer;
      *(undefined4 *)(glContext + 20000) = buffer;
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

/* _glInitNames_ListExec @ 0x861c4 (36 bytes) */
int _glInitNames_ListExec(glContext)
  undefined4 glContext;
{
  ((void (*)())_glInitNames_Exec)(glContext);
  return 0;
}

/* _glInitNames_Comp @ 0x861e8 (32 bytes) */
int _glInitNames_Comp(glContext)
  undefined4 glContext;
{
  undefined4 listRecord;
  
  listRecord = _gleAddListItem(glContext,PTR__glInitNames_ListExec_001102b0,0);
  return listRecord;
}

/* _glInitNames_Exec @ 0x86208 (68 bytes) */
void _glInitNames_Exec(glContext)
  int glContext;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (*(int *)(glContext + 0x4e1c) != 0x1c02) {
      return;
    }
    *(undefined1 *)(glContext + 0x4fc8) = 0;
    *(int *)(glContext + 0x4fbc) = glContext + 0x4e2c;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glInitNames_CompExec @ 0x8624c (48 bytes) */
void _glInitNames_CompExec(glContext)
  undefined4 glContext;
{
  ((int (*)())_glInitNames_Comp)(glContext);
  ((void (*)())_glInitNames_Exec)(glContext);
  return;
}

/* _glPushName_ListExec @ 0x8627c (40 bytes) */
int _glPushName_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glPushName_Exec)(glContext,*listRecord);
  return 4;
}

/* _glPushName_Comp @ 0x862a4 (76 bytes) */
int _glPushName_Comp(glContext, name)
  undefined4 glContext;
  undefined4 name;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glPushName_ListExec_001102a8,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = name;
  }
  return listRecord;
}

/* _glPushName_Exec @ 0x862f0 (108 bytes) */
void _glPushName_Exec(glContext, name)
  int glContext;
  undefined4 name;
{
  undefined4 glErrorCode;
  undefined4 *nameStackPointer;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (*(int *)(glContext + 0x4e1c) != 0x1c02) {
      return;
    }
    nameStackPointer = *(undefined4 **)(glContext + 0x4fbc);
    if (nameStackPointer < (undefined4 *)(glContext + 0x4fbcU)) {
      *nameStackPointer = name;
      *(undefined1 *)(glContext + 0x4fc8) = 0;
      *(undefined4 **)(glContext + 0x4fbc) = nameStackPointer + 1;
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x503;
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

/* _glPushName_CompExec @ 0x8635c (56 bytes) */
void _glPushName_CompExec(glContext, name)
  undefined4 glContext;
  undefined4 name;
{
  ((int (*)())_glPushName_Comp)(glContext,name);
  ((void (*)())_glPushName_Exec)(glContext,name);
  return;
}

/* _glPopName_ListExec @ 0x86394 (36 bytes) */
int _glPopName_ListExec(glContext)
  undefined4 glContext;
{
  ((void (*)())_glPopName_Exec)(glContext);
  return 0;
}

/* _glPopName_Comp @ 0x863b8 (32 bytes) */
int _glPopName_Comp(glContext)
  undefined4 glContext;
{
  undefined4 listRecord;
  
  listRecord = _gleAddListItem(glContext,PTR__glPopName_ListExec_001102a4,0);
  return listRecord;
}

/* _glPopName_Exec @ 0x863d8 (104 bytes) */
void _glPopName_Exec(glContext)
  int glContext;
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (*(int *)(glContext + 0x4e1c) != 0x1c02) {
      return;
    }
    if (*(int *)(glContext + 0x4fbc) != glContext + 0x4e2c) {
      *(undefined1 *)(glContext + 0x4fc8) = 0;
      *(int *)(glContext + 0x4fbc) = *(int *)(glContext + 0x4fbc) + -4;
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x504;
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

/* _glPopName_CompExec @ 0x86440 (48 bytes) */
void _glPopName_CompExec(glContext)
  undefined4 glContext;
{
  ((int (*)())_glPopName_Comp)(glContext);
  ((void (*)())_glPopName_Exec)(glContext);
  return;
}

/* _glShadeModel_ListExec @ 0x86470 (40 bytes) */
int _glShadeModel_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glShadeModel_Exec(glContext,*listRecord);
  return 4;
}

/* _glShadeModel_Comp @ 0x86498 (76 bytes) */
int _glShadeModel_Comp(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glShadeModel_ListExec_001102b4,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = mode;
  }
  return listRecord;
}

/* _glShadeModel_CompExec @ 0x864e4 (56 bytes) */
void _glShadeModel_CompExec(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  ((int (*)())_glShadeModel_Comp)(glContext,mode);
  _glShadeModel_Exec(glContext,mode);
  return;
}

/* _getIndexForGLSLSamplerType @ 0x8651c (108 bytes) */
int _getIndexForGLSLSamplerType(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  switch(param_1) {
  case 0x8b5d:
  case 0x8b61:
    uVar1 = 4;
    break;
  case 0x8b5e:
  case 0x8b62:
    uVar1 = 3;
    break;
  case 0x8b5f:
    uVar1 = 1;
    break;
  case 0x8b60:
    uVar1 = 0;
    break;
  case 0x8b63:
  case 0x8b64:
    uVar1 = 2;
  }
  return uVar1;
}

/* _updateShaderState @ 0x865a8 (660 bytes) */
void _updateShaderState(int glContext,int *param_2,uint param_3,int param_4,int param_5,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int loopIndex2;
  int loopIndex;
  
  if (param_2 == (int *)0x0) {
    *(undefined1 *)(glContext + 0x759c) = 1;
    *(undefined4 *)(glContext + 0x5434) = 0;
    *(undefined4 *)(glContext + 0x5438) = 0;
    if (param_3 != 0) {
      if (param_4 != 0) {
        _gleVPDisable(glContext);
      }
      if (param_5 != 0) {
        _gleFPDisable(glContext);
      }
    }
    if (param_3 != 1) {
      _gleUpdateDrawArraysFuncs(glContext);
    }
    iVar3 = glContext + 0x10000;
    loopIndex = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      do {
        *(undefined4 *)(iVar3 + -0x7788) = 0;
        loopIndex = loopIndex + 1;
        *(undefined4 *)(iVar3 + -0x7784) = 0;
        iVar3 = iVar3 + 0x2e0;
      } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
  }
  else {
    bVar1 = *(byte *)((int)param_2 + 0x1e);
    *(byte *)(glContext + 0x759c) = bVar1;
    if ((*(char *)*param_2 == '\0') || (*(char *)((int)param_2 + 0x1e) == '\0')) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    *(undefined4 *)(glContext + 0x5434) = uVar2;
    if ((*(char *)param_2[1] == '\0') || (*(char *)((int)param_2 + 0x1e) == '\0')) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    *(undefined4 *)(glContext + 0x5438) = uVar2;
    if (((*(int *)(glContext + 0x5434) == 0) || (param_3 == 0)) || (param_4 == 0)) {
      if (*(int *)(glContext + 0x5434) == 0) {
        _gleVPDisable(glContext);
      }
      else {
        ((double (*)())_gleVPEnable)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8
                    );
      }
    }
    else {
      ((void (*)())_gleVPChanged)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8)
      ;
    }
    if (((*(int *)(glContext + 0x5438) == 0) || (param_3 == 0)) || (param_5 == 0)) {
      if (*(int *)(glContext + 0x5438) == 0) {
        _gleFPDisable(glContext);
      }
      else {
        _gleFPEnable(glContext);
      }
    }
    else {
      _gleFPChanged(glContext);
    }
    if (bVar1 != param_3) {
      _gleUpdateDrawArraysFuncs(glContext);
    }
    if ((*(int *)(glContext + 0x5434) != 0) || (*(int *)(glContext + 0x5438) != 0)) {
      _gleUpdateInverseNeeds(glContext);
    }
    loopIndex2 = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      do {
        if (*(int *)(glContext + 0x5434) == 0) {
          *(undefined4 *)(loopIndex2 * 0x2e0 + glContext + 0x8878) = 0;
        }
        else {
          *(undefined4 *)(loopIndex2 * 0x2e0 + glContext + 0x8878) =
               *(undefined4 *)(loopIndex2 * 4 + *param_2 + 0x4e4);
        }
        if (*(int *)(glContext + 0x5438) == 0) {
          *(undefined4 *)(loopIndex2 * 0x2e0 + glContext + 0x887c) = 0;
        }
        else {
          *(undefined4 *)(loopIndex2 * 0x2e0 + glContext + 0x887c) =
               *(undefined4 *)(loopIndex2 * 4 + param_2[1] + 0x4e4);
        }
        loopIndex2 = loopIndex2 + 1;
      } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
  }
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
  return;
}

/* _glUseProgramObjectARB_Exec @ 0x8683c (1324 bytes) */
void _glUseProgramObjectARB_Exec(int glContext,int programObj,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool noPreviousProgram;
  undefined2 samplerTypeValue;
  undefined4 samplerUsedValue;
  undefined4 glErrorCode;
  uint unitTargetBits;
  int iVar6;
  int iVar7;
  int loopIndex;
  int iVar9;
  uint uVar10;
  undefined4 *dstCursor;
  short *srcCursor4;
  undefined2 *dstCursor2;
  undefined2 *srcCursor6;
  int *srcCursor;
  undefined4 *srcCursor7;
  short *srcCursor5;
  undefined2 *dstCursor3;
  int *srcCursor2;
  uint *srcCursor8;
  uint uVar20;
  uint uVar21;
  int currentProgram;
  int *newStageRecordSlots;
  int *oldStageRecordSlots;
  int *srcCursor3;
  int remaining;
  double extraout_f1;
  double extraout_f1_00;
  
  oldStageRecordSlots = (int *)0x0;
  newStageRecordSlots = (int *)0x0;
  uVar21 = 0;
  uVar20 = 1;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
      fparam_1 = extraout_f1;
    }
    currentProgram = *(int *)(glContext + 0x5430);
    noPreviousProgram = currentProgram == 0;
    if (!noPreviousProgram) {
      oldStageRecordSlots = (int *)(currentProgram + 0x20);
      uVar20 = (uint)*(byte *)(currentProgram + 0x3e);
      uVar21 = (uint)**(byte **)(currentProgram + 0x24);
    }
    if (programObj == 0) {
      *(undefined4 *)(glContext + 0x5430) = 0;
LAB_00086cd4:
      ((void (*)())_updateShaderState)(glContext,newStageRecordSlots,uVar20,uVar21,0,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                         forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      if ((!noPreviousProgram) && (iVar7 = *(int *)(currentProgram + 8) + -1, *(int *)(currentProgram + 8) = iVar7, iVar7 == 1))
      {
        _gleDeleteHashNameAndObject
                  (glContext,*(int *)(glContext + 0x5148) + 0x6018,*(undefined4 *)(currentProgram + 4));
      }
    }
    else {
      iVar7 = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x6018,programObj);
      if (iVar7 == 0) {
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        }
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x501;
        goto LAB_0008694c;
      }
      if ((*(int *)(iVar7 + 0x10) != 0x8b40) || (*(char *)(iVar7 + 0x3c) != '\x01')) {
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        }
        goto LAB_0008693c;
      }
      if (iVar7 != *(int *)(glContext + 0x5430)) {
        *(int *)(glContext + 0x5430) = iVar7;
        newStageRecordSlots = (int *)(iVar7 + 0x20);
        if ((**(char **)(iVar7 + 0x20) != '\0') || (**(char **)(iVar7 + 0x24) != '\0')) {
          if (noPreviousProgram) {
            loopIndex = 0;
            if (*(char *)(iVar7 + 0x3e) == '\0') {
              do {
                if (loopIndex == 0) {
                  iVar6 = *newStageRecordSlots;
                  remaining = 0;
                }
                else {
                  iVar6 = *(int *)(iVar7 + 0x24);
                  remaining = 0x10;
                }
                if (remaining != 0) {
                  dstCursor = (undefined4 *)(iVar6 + 0x2c);
                  dstCursor2 = (undefined2 *)(iVar6 + 0x6c);
                  iVar6 = glContext + 0x3530;
                  do {
                    uVar10 = 0;
                    if (*(int *)(iVar6 + 4) != 0) {
                      *dstCursor = 1;
                      uVar10 = *(uint *)(iVar6 + 4);
                    }
                    if ((uVar10 & 1) == 0) {
                      if ((uVar10 & 2) == 0) {
                        if ((uVar10 & 4) == 0) {
                          if ((uVar10 & 8) == 0) {
                            if ((uVar10 & 0x10) == 0) {
                              *dstCursor2 = 0;
                            }
                            else {
                              *dstCursor2 = 0x8b5d;
                            }
                          }
                          else {
                            *dstCursor2 = 0x8b5e;
                          }
                        }
                        else {
                          *dstCursor2 = 0x8b63;
                        }
                      }
                      else {
                        *dstCursor2 = 0x8b5f;
                      }
                    }
                    else {
                      *dstCursor2 = 0x8b60;
                    }
                    iVar6 = iVar6 + 0x7c;
                    dstCursor = dstCursor + 1;
                    dstCursor2 = dstCursor2 + 1;
                    remaining = remaining + -1;
                  } while (remaining != 0);
                }
                loopIndex = loopIndex + 1;
              } while (loopIndex < 2);
            }
            else {
              do {
                if (loopIndex == 0) {
                  iVar6 = *newStageRecordSlots;
                  remaining = 0;
                }
                else {
                  iVar6 = *(int *)(iVar7 + 0x24);
                  remaining = 0x10;
                }
                uVar10 = 0;
                if (remaining != 0) {
                  srcCursor3 = (int *)(iVar6 + 0x2c);
                  srcCursor4 = (short *)(iVar6 + 0x6c);
                  srcCursor8 = (uint *)(glContext + 0x3534);
                  do {
                    if (*srcCursor8 == 0) {
                      if (*srcCursor3 == 0) goto LAB_00086c28;
LAB_00086c90:
                      *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 1 << (uVar10 & 0x3f)
                      ;
                    }
                    else {
                      if (*srcCursor3 == 0) goto LAB_00086c90;
LAB_00086c28:
                      unitTargetBits = *srcCursor8;
                      if ((unitTargetBits & 1) == 0) {
                        if ((unitTargetBits & 2) != 0) {
                          bVar1 = *srcCursor4 == -0x74a1;
                          goto LAB_00086c8c;
                        }
                        if ((unitTargetBits & 4) != 0) {
                          bVar1 = *srcCursor4 == -0x749d;
                          goto LAB_00086c8c;
                        }
                        if ((unitTargetBits & 8) != 0) {
                          bVar1 = *srcCursor4 == -0x74a2;
                          goto LAB_00086c8c;
                        }
                        if ((unitTargetBits & 0x10) != 0) {
                          bVar1 = *srcCursor4 == -0x74a3;
                          goto LAB_00086c8c;
                        }
                      }
                      else {
                        bVar1 = *srcCursor4 == -0x74a0;
LAB_00086c8c:
                        if (!bVar1) goto LAB_00086c90;
                      }
                    }
                    uVar10 = uVar10 + 1;
                    srcCursor3 = srcCursor3 + 1;
                    srcCursor8 = srcCursor8 + 0x1f;
                    srcCursor4 = srcCursor4 + 1;
                    remaining = remaining + -1;
                  } while (remaining != 0);
                }
                loopIndex = loopIndex + 1;
              } while (loopIndex < 2);
            }
          }
          else {
            loopIndex = 0;
            if (*(char *)(iVar7 + 0x3e) == '\0') {
              do {
                if (loopIndex == 0) {
                  iVar9 = *oldStageRecordSlots;
                  iVar6 = *newStageRecordSlots;
                  remaining = 0;
                }
                else {
                  iVar9 = oldStageRecordSlots[1];
                  remaining = 0x10;
                  iVar6 = *(int *)(iVar7 + 0x24);
                }
                if (remaining != 0) {
                  dstCursor = (undefined4 *)(iVar6 + 0x2c);
                  srcCursor7 = (undefined4 *)(iVar9 + 0x2c);
                  dstCursor3 = (undefined2 *)(iVar6 + 0x6c);
                  srcCursor6 = (undefined2 *)(iVar9 + 0x6c);
                  do {
                    samplerUsedValue = *srcCursor7;
                    srcCursor7 = srcCursor7 + 1;
                    samplerTypeValue = *srcCursor6;
                    srcCursor6 = srcCursor6 + 1;
                    *dstCursor = samplerUsedValue;
                    dstCursor = dstCursor + 1;
                    *dstCursor3 = samplerTypeValue;
                    dstCursor3 = dstCursor3 + 1;
                    remaining = remaining + -1;
                  } while (remaining != 0);
                }
                loopIndex = loopIndex + 1;
              } while (loopIndex < 2);
            }
            else {
              do {
                if (loopIndex == 0) {
                  iVar9 = *oldStageRecordSlots;
                  iVar6 = *newStageRecordSlots;
                  remaining = 0;
                }
                else {
                  iVar9 = oldStageRecordSlots[1];
                  remaining = 0x10;
                  iVar6 = *(int *)(iVar7 + 0x24);
                }
                uVar10 = 0;
                if (remaining != 0) {
                  srcCursor2 = (int *)(iVar9 + 0x2c);
                  srcCursor = (int *)(iVar6 + 0x2c);
                  srcCursor4 = (short *)(iVar9 + 0x6c);
                  srcCursor5 = (short *)(iVar6 + 0x6c);
                  do {
                    iVar9 = *srcCursor;
                    srcCursor = srcCursor + 1;
                    iVar6 = *srcCursor2;
                    srcCursor2 = srcCursor2 + 1;
                    if ((iVar9 != iVar6) || ((iVar9 != 0 && (*srcCursor5 != *srcCursor4)))) {
                      *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 1 << (uVar10 & 0x3f)
                      ;
                    }
                    uVar10 = uVar10 + 1;
                    srcCursor5 = srcCursor5 + 1;
                    srcCursor4 = srcCursor4 + 1;
                    remaining = remaining + -1;
                  } while (remaining != 0);
                }
                loopIndex = loopIndex + 1;
              } while (loopIndex < 2);
            }
          }
        }
        *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + 1;
        fparam_1 = extraout_f1_00;
        goto LAB_00086cd4;
      }
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
  }
  else {
LAB_0008693c:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0008694c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glUseProgramObjectARB_Comp @ 0x86d68 (76 bytes) */
int _glUseProgramObjectARB_Comp(glContext, programObj)
  undefined4 glContext;
  undefined4 programObj;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glUseProgramObjectARB_ListExec_00110304,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = programObj;
  }
  return listRecord;
}

/* _glUseProgramObjectARB_CompExec @ 0x86db4 (56 bytes) */
void _glUseProgramObjectARB_CompExec(glContext, programObj)
  undefined4 glContext;
  undefined4 programObj;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glUseProgramObjectARB_Comp)(glContext,programObj);
  ((void (*)())_glUseProgramObjectARB_Exec)(glContext,programObj,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glUseProgramObjectARB_ListExec @ 0x86dec (40 bytes) */
undefined4 _glUseProgramObjectARB_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glUseProgramObjectARB_Exec)(glContext,*listRecord,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
             forwardedFloatArg8);
  return 4;
}

/* _glCreateShaderObjectARB_Exec @ 0x86e14 (420 bytes) */
int _glCreateShaderObjectARB_Exec(glContext, shaderType)
  int glContext;
  code *shaderType;
{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 glErrorCode;
  int iVar3;
  undefined4 *puVar4;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x502;
LAB_00086e94:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return 0;
  }
  if (shaderType == (code *)0x8b30) {
    iVar3 = 0x38;
  }
  else {
    iVar3 = 0x3c;
    if (shaderType != (code *)0x8b31) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0;
      }
      glErrorCode = 0x500;
      goto LAB_00086e94;
    }
  }
  puVar4 = (undefined4 *)_gleVecAlloc(iVar3 + 0xfU & 0xfffffff0);
  uVar2 = _gleGenHashNames(*(int *)(glContext + 0x5148) + 0x6018,1);
  puVar1 = PTR__gleFreeShaderObject_00112048;
  puVar4[2] = 2;
  puVar4[3] = puVar1;
  puVar4[4] = 0x8b48;
  puVar4[1] = uVar2;
  *puVar4 = 0;
  *(undefined1 *)(puVar4 + 5) = 0;
  puVar4[7] = 0;
  puVar4[6] = 0;
  puVar4[8] = shaderType;
  *(undefined1 *)((int)puVar4 + 0x25) = 0;
  puVar4[0xb] = 0;
  puVar4[10] = 0;
  *(undefined1 *)(puVar4 + 9) = 0;
  puVar4[0xc] = 0;
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
  }
  _ShInitialize();
  if (shaderType == (code *)0x8b30) {
    if (puVar4 == (undefined4 *)0xffffffcc) goto LAB_00086f70;
  }
  else {
    if ((shaderType != (code *)0x8b31) || (puVar4 == (undefined4 *)0xffffffcc)) goto LAB_00086f70;
    puVar4[0xe] = 0;
  }
  puVar4[0xd] = 0;
LAB_00086f70:
  _gleAddHashNameAndObject(glContext,*(int *)(glContext + 0x5148) + 0x6018,puVar4);
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
  }
  return uVar2;
}

/* _glCreateProgramObjectARB_Exec @ 0x86fb8 (484 bytes) */
int _glCreateProgramObjectARB_Exec(glContext)
  int glContext;
{
  int *rendererDispatch;
  undefined4 *rendererHandlePtr;
  int slotByteOffset;
  undefined *freeFunction;
  undefined4 programHandle;
  int programObject;
  undefined4 stageDataOrLinker;
  int vertexStageData;
  int stageData;
  int loopIndex;
  int rendererSlotCursor;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    programObject = _gleVecAlloc(0x50);
    _memset(programObject,0,0x50);
    programHandle = _gleGenHashNames(*(int *)(glContext + 0x5148) + 0x6018,1);
    freeFunction = PTR__gleFreeShaderObject_00112048;
    *(undefined4 *)(programObject + 8) = 2;
    *(undefined **)(programObject + 0xc) = freeFunction;
    *(undefined4 *)(programObject + 0x10) = 0x8b40;
    *(undefined1 *)(programObject + 0x14) = 0;
    *(undefined4 *)(programObject + 4) = programHandle;
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    stageDataOrLinker = _gleVecAlloc(0x520);
    *(undefined4 *)(programObject + 0x20) = stageDataOrLinker;
    _memset(stageDataOrLinker,0,0x520);
    stageDataOrLinker = _gleVecAlloc(0x520);
    *(undefined4 *)(programObject + 0x24) = stageDataOrLinker;
    loopIndex = 0;
    _memset(stageDataOrLinker,0,0x520);
    if (*(char *)(glContext + 0x85a4) != '\0') {
      rendererSlotCursor = glContext + 0x85a0;
      do {
        slotByteOffset = loopIndex * 4;
        loopIndex = loopIndex + 1;
        (**(code **)(*(int *)(rendererSlotCursor + 0x2e4) + 400))
                  (*(undefined4 *)(rendererSlotCursor + 0xc),*(int *)(programObject + 0x24) + slotByteOffset + 0x4e4,
                   *(int *)(programObject + 0x24) + 0x504);
        rendererDispatch = (int *)(rendererSlotCursor + 0x2e4);
        vertexStageData = *(int *)(programObject + 0x20);
        rendererHandlePtr = (undefined4 *)(rendererSlotCursor + 0xc);
        rendererSlotCursor = rendererSlotCursor + 0x2e0;
        (**(code **)(*rendererDispatch + 400))(*rendererHandlePtr,vertexStageData + slotByteOffset + 0x4e4,vertexStageData + 0x504);
      } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
    stageData = *(int *)(programObject + 0x20);
    *(undefined2 *)(stageData + 0x506) = 0;
    *(undefined2 *)(stageData + 0x504) = 0x8b31;
    stageData = *(int *)(programObject + 0x24);
    *(undefined2 *)(stageData + 0x506) = 1;
    *(undefined2 *)(stageData + 0x504) = 0x8b30;
    _ShInitialize();
    stageDataOrLinker = _ShConstructLinker(0);
    *(undefined4 *)(programObject + 0x40) = stageDataOrLinker;
    _gleAddHashNameAndObject(glContext,*(int *)(glContext + 0x5148) + 0x6018,programObject);
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  else {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    programHandle = 0;
  }
  return programHandle;
}

