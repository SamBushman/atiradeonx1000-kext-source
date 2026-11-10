#include "decls.h"

/* _glRects_Comp @ 0x849dc (132 bytes) */
int _glRects_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  
  _glBegin_Comp(param_1,9);
  _glVertex2s_Comp(param_1,param_2,param_3);
  _glVertex2s_Comp(param_1,param_4,param_3);
  _glVertex2s_Comp(param_1,param_4,param_5);
  _glVertex2s_Comp(param_1,param_2,param_5);
  uVar1 = _glEnd_Comp(param_1);
  return uVar1;
}

/* _glRects_Exec @ 0x84a60 (188 bytes) */
void _glRects_Exec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    return;
  }
  ((void (*)())_glBegin_Exec)(param_1,9,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  _glVertex2s_Exec(param_1,param_2,param_3);
  _glVertex2s_Exec(param_1,param_4,param_3);
  _glVertex2s_Exec(param_1,param_4,param_5);
  _glVertex2s_Exec(param_1,param_2,param_5);
  _glEnd_Exec(param_1);
  return;
}

/* _glRects_CompExec @ 0x84b1c (80 bytes) */
void _glRects_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glRects_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((void (*)())_glRects_Exec)(param_1,param_2,param_3,param_4,param_5,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7
                ,in_f8);
  return;
}

/* _glRectdv_Comp @ 0x84b6c (124 bytes) */
int _glRectdv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  double *param_2;
  double *param_3;
{
  undefined4 uVar1;
  
  _glBegin_Comp(param_1,9);
  ((float * (*)())_glVertex2d_Comp)(param_1,*param_2,param_2[1]);
  ((float * (*)())_glVertex2d_Comp)(param_1,*param_3,param_2[1]);
  ((float * (*)())_glVertex2d_Comp)(param_1,*param_3,param_3[1]);
  ((float * (*)())_glVertex2d_Comp)(param_1,*param_2,param_3[1]);
  uVar1 = _glEnd_Comp(param_1);
  return uVar1;
}

/* _glRectdv_Exec @ 0x84be8 (180 bytes) */
void _glRectdv_Exec(int param_1,double *param_2,double *param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    return;
  }
  ((void (*)())_glBegin_Exec)(param_1,9,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  ((void (*)())_glVertex2d_Exec)(param_1,*param_2,param_2[1]);
  ((void (*)())_glVertex2d_Exec)(param_1,*param_3,param_2[1]);
  ((void (*)())_glVertex2d_Exec)(param_1,*param_3,param_3[1]);
  ((void (*)())_glVertex2d_Exec)(param_1,*param_2,param_3[1]);
  _glEnd_Exec(param_1);
  return;
}

/* _glRectdv_CompExec @ 0x84c9c (64 bytes) */
void _glRectdv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glRectdv_Comp)(param_1,param_2,param_3);
  ((void (*)())_glRectdv_Exec)(param_1,param_2,param_3,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRectfv_Comp @ 0x84cdc (124 bytes) */
int _glRectfv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  float *param_3;
{
  undefined4 uVar1;
  
  _glBegin_Comp(param_1,9);
  ((float * (*)())_glVertex2f_Comp)(param_1,(double)*param_2,(double)param_2[1]);
  ((float * (*)())_glVertex2f_Comp)(param_1,(double)*param_3,(double)param_2[1]);
  ((float * (*)())_glVertex2f_Comp)(param_1,(double)*param_3,(double)param_3[1]);
  ((float * (*)())_glVertex2f_Comp)(param_1,(double)*param_2,(double)param_3[1]);
  uVar1 = _glEnd_Comp(param_1);
  return uVar1;
}

/* _glRectfv_Exec @ 0x84d58 (180 bytes) */
void _glRectfv_Exec(int param_1,undefined4 param_2,undefined4 param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    return;
  }
  ((void (*)())_glBegin_Exec)(param_1,9,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  _glVertex2f_Exec(param_1);
  _glVertex2f_Exec(param_1);
  _glVertex2f_Exec(param_1);
  _glVertex2f_Exec(param_1);
  _glEnd_Exec(param_1);
  return;
}

/* _glRectfv_CompExec @ 0x84e0c (64 bytes) */
void _glRectfv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glRectfv_Comp)(param_1,param_2,param_3);
  ((void (*)())_glRectfv_Exec)(param_1,param_2,param_3,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRectiv_Comp @ 0x84e4c (124 bytes) */
int _glRectiv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  
  _glBegin_Comp(param_1,9);
  _glVertex2i_Comp(param_1,*param_2,param_2[1]);
  _glVertex2i_Comp(param_1,*param_3,param_2[1]);
  _glVertex2i_Comp(param_1,*param_3,param_3[1]);
  _glVertex2i_Comp(param_1,*param_2,param_3[1]);
  uVar1 = _glEnd_Comp(param_1);
  return uVar1;
}

/* _glRectiv_Exec @ 0x84ec8 (180 bytes) */
void _glRectiv_Exec(int param_1,undefined4 *param_2,undefined4 *param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    return;
  }
  ((void (*)())_glBegin_Exec)(param_1,9,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  _glVertex2i_Exec(param_1,*param_2,param_2[1]);
  _glVertex2i_Exec(param_1,*param_3,param_2[1]);
  _glVertex2i_Exec(param_1,*param_3,param_3[1]);
  _glVertex2i_Exec(param_1,*param_2,param_3[1]);
  _glEnd_Exec(param_1);
  return;
}

/* _glRectiv_CompExec @ 0x84f7c (64 bytes) */
void _glRectiv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glRectiv_Comp)(param_1,param_2,param_3);
  ((void (*)())_glRectiv_Exec)(param_1,param_2,param_3,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRectsv_Comp @ 0x84fbc (124 bytes) */
int _glRectsv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  short *param_2;
  short *param_3;
{
  undefined4 uVar1;
  
  _glBegin_Comp(param_1,9);
  _glVertex2s_Comp(param_1,(int)*param_2,(int)param_2[1]);
  _glVertex2s_Comp(param_1,(int)*param_3,(int)param_2[1]);
  _glVertex2s_Comp(param_1,(int)*param_3,(int)param_3[1]);
  _glVertex2s_Comp(param_1,(int)*param_2,(int)param_3[1]);
  uVar1 = _glEnd_Comp(param_1);
  return uVar1;
}

/* _glRectsv_Exec @ 0x85038 (180 bytes) */
void _glRectsv_Exec(int param_1,short *param_2,short *param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    return;
  }
  ((void (*)())_glBegin_Exec)(param_1,9,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  _glVertex2s_Exec(param_1,(int)*param_2,(int)param_2[1]);
  _glVertex2s_Exec(param_1,(int)*param_3,(int)param_2[1]);
  _glVertex2s_Exec(param_1,(int)*param_3,(int)param_3[1]);
  _glVertex2s_Exec(param_1,(int)*param_2,(int)param_3[1]);
  _glEnd_Exec(param_1);
  return;
}

/* _glRectsv_CompExec @ 0x850ec (64 bytes) */
void _glRectsv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glRectsv_Comp)(param_1,param_2,param_3);
  ((void (*)())_glRectsv_Exec)(param_1,param_2,param_3,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glRotateZ_ListExec @ 0x8512c (44 bytes) */
undefined4 _glRotateZ_ListExec(undefined4 param_1,float *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  double in_stack_ffffffd0;
  double in_stack_ffffffd8;
  
  ((void (*)())_glRotateZ_Exec)(param_1,(double)*param_2,(double)param_2[1],fparam_3,fparam_4,fparam_5,fparam_6,
                  fparam_7,fparam_8,in_stack_ffffffb8,in_stack_ffffffc0,in_stack_ffffffc8,
                  in_stack_ffffffd0,in_stack_ffffffd8);
  return 8;
}

/* _glRotateXYZ_ListExec @ 0x85158 (644 bytes) */
undefined4 _glRotateXYZ_ListExec(int param_1,float *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float *pfVar19;
  uint uVar20;
  uint uVar21;
  
  pfVar19 = *(float **)(param_1 + 0x4fec);
  uVar21 = *(uint *)(param_1 + 0x50a8);
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    fVar1 = param_2[1];
    fVar2 = param_2[4];
    fVar3 = param_2[7];
    fVar4 = pfVar19[4];
    fVar5 = *param_2;
    fVar6 = param_2[3];
    fVar7 = param_2[6];
    fVar8 = pfVar19[5];
    fVar9 = *pfVar19;
    fVar10 = param_2[8];
    fVar11 = param_2[2];
    fVar12 = pfVar19[6];
    fVar13 = param_2[5];
    fVar14 = pfVar19[8];
    fVar15 = pfVar19[1];
    fVar16 = pfVar19[7];
    fVar17 = pfVar19[2];
    fVar18 = pfVar19[9];
    pfVar19[8] = fVar14 * fVar10 + (fVar9 * fVar7 + fVar4 * fVar3);
    *pfVar19 = fVar14 * fVar11 + (fVar9 * fVar5 + fVar4 * fVar1);
    pfVar19[4] = fVar14 * fVar13 + (fVar9 * fVar6 + fVar4 * fVar2);
    fVar4 = pfVar19[3];
    fVar9 = pfVar19[10];
    pfVar19[9] = fVar18 * fVar10 + (fVar15 * fVar7 + fVar8 * fVar3);
    pfVar19[1] = fVar18 * fVar11 + (fVar15 * fVar5 + fVar8 * fVar1);
    pfVar19[5] = fVar18 * fVar13 + (fVar15 * fVar6 + fVar8 * fVar2);
    fVar8 = pfVar19[0xb];
    pfVar19[10] = fVar9 * fVar10 + (fVar17 * fVar7 + fVar12 * fVar3);
    pfVar19[2] = fVar9 * fVar11 + (fVar17 * fVar5 + fVar12 * fVar1);
    pfVar19[6] = fVar9 * fVar13 + (fVar17 * fVar6 + fVar12 * fVar2);
    pfVar19[0xb] = fVar8 * fVar10 + (fVar4 * fVar7 + fVar16 * fVar3);
    pfVar19[3] = fVar8 * fVar11 + (fVar4 * fVar5 + fVar16 * fVar1);
    pfVar19[7] = fVar8 * fVar13 + (fVar4 * fVar6 + fVar16 * fVar2);
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | uVar21;
    uVar20 = *(uint *)(param_1 + 0x50b0);
    if ((uVar21 & ~uVar20 & *(uint *)(param_1 + 0x505c) & 0xfffffc) != 0) {
      pfVar19 = *(float **)(param_1 + 0x4ff0);
      uVar21 = uVar21 & 0xff000003;
      fVar4 = pfVar19[4];
      fVar8 = *pfVar19;
      fVar9 = pfVar19[8];
      fVar12 = pfVar19[5];
      fVar14 = pfVar19[6];
      fVar15 = pfVar19[1];
      fVar16 = pfVar19[7];
      fVar17 = pfVar19[2];
      fVar18 = pfVar19[9];
      pfVar19[8] = fVar9 * fVar10 + (fVar8 * fVar7 + fVar4 * fVar3);
      *pfVar19 = fVar9 * fVar11 + (fVar8 * fVar5 + fVar4 * fVar1);
      pfVar19[4] = fVar9 * fVar13 + (fVar8 * fVar6 + fVar4 * fVar2);
      fVar4 = pfVar19[3];
      fVar8 = pfVar19[10];
      pfVar19[9] = fVar18 * fVar10 + (fVar15 * fVar7 + fVar12 * fVar3);
      pfVar19[1] = fVar18 * fVar11 + (fVar15 * fVar5 + fVar12 * fVar1);
      pfVar19[5] = fVar18 * fVar13 + (fVar15 * fVar6 + fVar12 * fVar2);
      fVar9 = pfVar19[0xb];
      pfVar19[10] = fVar8 * fVar10 + (fVar17 * fVar7 + fVar14 * fVar3);
      pfVar19[2] = fVar8 * fVar11 + (fVar17 * fVar5 + fVar14 * fVar1);
      pfVar19[6] = fVar8 * fVar13 + (fVar17 * fVar6 + fVar14 * fVar2);
      pfVar19[0xb] = fVar9 * fVar10 + (fVar4 * fVar7 + fVar16 * fVar3);
      pfVar19[3] = fVar9 * fVar11 + (fVar4 * fVar5 + fVar16 * fVar1);
      pfVar19[7] = fVar9 * fVar13 + (fVar4 * fVar6 + fVar16 * fVar2);
      uVar20 = *(uint *)(param_1 + 0x50b0);
    }
    *(uint *)(param_1 + 0x50b0) = uVar20 | uVar21;
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return 0x24;
}

/* _glRotateZ_Comp @ 0x853dc (100 bytes) */
void _glRotateZ_Comp(undefined4 param_1,double fparam_1,double fparam_2)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glRotateZ_ListExec_00110288,8);
  if (pfVar1 != (float *)0x0) {
    pfVar1[1] = (float)fparam_2;
    *pfVar1 = (float)fparam_1;
  }
  return;
}

/* _glRotateXYZ_Comp @ 0x85440 (292 bytes) */
void _glRotateXYZ_Comp(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float *pfVar10;
  double dVar11;
  double dVar12;
  
  fVar6 = *(float *)(param_1 + 0x24);
  pfVar10 = (float *)_gleAddListItem(param_1,PTR__glRotateXYZ_ListExec_00110284,0x24);
  if (pfVar10 != (float *)0x0) {
    dVar11 = (double)FLOAT_00108e84;
    dVar12 = _sin((double)(float)(fparam_1 * dVar11));
    fVar4 = (float)dVar12;
    dVar11 = _cos((double)(float)(fparam_1 * dVar11));
    fVar5 = (float)dVar11;
    dVar11 = _sqrt((double)(float)(fparam_4 * fparam_4 +
                                  (double)(float)(fparam_2 * fparam_2 +
                                                 (double)(float)(fparam_3 * fparam_3))));
    fVar7 = fVar6 - fVar5;
    dVar11 = (double)(fVar6 / (float)dVar11);
    fVar1 = (float)(fparam_4 * dVar11);
    fVar2 = (float)(fparam_2 * dVar11);
    fVar3 = (float)(fparam_3 * dVar11);
    fVar8 = fVar2 * fVar3 * fVar7;
    fVar9 = fVar3 * fVar1 * fVar7;
    fVar7 = fVar1 * fVar2 * fVar7;
    pfVar10[8] = fVar5 * (fVar6 - fVar1 * fVar1) + fVar1 * fVar1;
    *pfVar10 = fVar5 * (fVar6 - fVar2 * fVar2) + fVar2 * fVar2;
    pfVar10[3] = fVar8 - fVar1 * fVar4;
    pfVar10[4] = fVar5 * (fVar6 - fVar3 * fVar3) + fVar3 * fVar3;
    pfVar10[6] = fVar7 + fVar3 * fVar4;
    pfVar10[7] = fVar9 - fVar2 * fVar4;
    pfVar10[1] = fVar8 + fVar1 * fVar4;
    pfVar10[2] = fVar7 - fVar3 * fVar4;
    pfVar10[5] = fVar9 + fVar2 * fVar4;
  }
  return;
}

/* _glRotateXYZ_Exec @ 0x85564 (824 bytes) */
void _glRotateXYZ_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  uint uVar20;
  uint uVar21;
  float *pfVar22;
  double dVar23;
  double dVar24;
  
  uVar21 = *(uint *)(param_1 + 0x50a8);
  pfVar22 = *(float **)(param_1 + 0x4fec);
  fVar6 = *(float *)(param_1 + 0x24);
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    dVar23 = (double)FLOAT_00108e84;
    dVar24 = _sin((double)(float)(fparam_1 * dVar23));
    fVar4 = (float)dVar24;
    dVar23 = _cos((double)(float)(fparam_1 * dVar23));
    fVar5 = (float)dVar23;
    dVar23 = _sqrt((double)(float)(fparam_4 * fparam_4 +
                                  (double)(float)(fparam_2 * fparam_2 +
                                                 (double)(float)(fparam_3 * fparam_3))));
    fVar11 = fVar6 - fVar5;
    fVar7 = pfVar22[4];
    fVar8 = *pfVar22;
    fVar9 = pfVar22[8];
    dVar23 = (double)(fVar6 / (float)dVar23);
    fVar1 = (float)(fparam_4 * dVar23);
    fVar2 = (float)(fparam_2 * dVar23);
    fVar3 = (float)(fparam_3 * dVar23);
    fVar15 = fVar2 * fVar3 * fVar11;
    fVar16 = fVar3 * fVar1 * fVar11;
    fVar14 = fVar5 * (fVar6 - fVar3 * fVar3) + fVar3 * fVar3;
    fVar18 = fVar16 - fVar2 * fVar4;
    fVar11 = fVar1 * fVar2 * fVar11;
    fVar17 = fVar15 + fVar1 * fVar4;
    fVar15 = fVar15 - fVar1 * fVar4;
    fVar13 = fVar5 * (fVar6 - fVar2 * fVar2) + fVar2 * fVar2;
    fVar19 = fVar11 + fVar3 * fVar4;
    fVar10 = pfVar22[5];
    fVar12 = fVar5 * (fVar6 - fVar1 * fVar1) + fVar1 * fVar1;
    fVar6 = pfVar22[6];
    fVar11 = fVar11 - fVar3 * fVar4;
    fVar16 = fVar16 + fVar2 * fVar4;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[7];
    fVar3 = pfVar22[2];
    fVar4 = pfVar22[9];
    pfVar22[8] = fVar9 * fVar12 + (fVar8 * fVar19 + fVar7 * fVar18);
    *pfVar22 = fVar9 * fVar11 + (fVar8 * fVar13 + fVar7 * fVar17);
    pfVar22[4] = fVar9 * fVar16 + (fVar8 * fVar15 + fVar7 * fVar14);
    fVar5 = pfVar22[3];
    fVar7 = pfVar22[10];
    pfVar22[9] = fVar4 * fVar12 + (fVar1 * fVar19 + fVar10 * fVar18);
    pfVar22[1] = fVar4 * fVar11 + (fVar1 * fVar13 + fVar10 * fVar17);
    pfVar22[5] = fVar4 * fVar16 + (fVar1 * fVar15 + fVar10 * fVar14);
    fVar1 = pfVar22[0xb];
    pfVar22[10] = fVar7 * fVar12 + (fVar3 * fVar19 + fVar6 * fVar18);
    pfVar22[2] = fVar7 * fVar11 + (fVar3 * fVar13 + fVar6 * fVar17);
    pfVar22[6] = fVar7 * fVar16 + (fVar3 * fVar15 + fVar6 * fVar14);
    pfVar22[0xb] = fVar1 * fVar12 + (fVar5 * fVar19 + fVar2 * fVar18);
    pfVar22[3] = fVar1 * fVar11 + (fVar5 * fVar13 + fVar2 * fVar17);
    pfVar22[7] = fVar1 * fVar16 + (fVar5 * fVar15 + fVar2 * fVar14);
    uVar20 = *(uint *)(param_1 + 0x50b0);
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | uVar21;
    if ((uVar21 & ~uVar20 & *(uint *)(param_1 + 0x505c) & 0xfffffc) != 0) {
      pfVar22 = *(float **)(param_1 + 0x4ff0);
      uVar21 = uVar21 & 0xff000003;
      fVar6 = pfVar22[4];
      fVar1 = *pfVar22;
      fVar2 = pfVar22[8];
      fVar3 = pfVar22[5];
      fVar4 = pfVar22[6];
      fVar5 = pfVar22[1];
      fVar7 = pfVar22[7];
      fVar8 = pfVar22[2];
      fVar9 = pfVar22[9];
      pfVar22[8] = fVar2 * fVar12 + (fVar1 * fVar19 + fVar6 * fVar18);
      *pfVar22 = fVar2 * fVar11 + (fVar1 * fVar13 + fVar6 * fVar17);
      pfVar22[4] = fVar2 * fVar16 + (fVar1 * fVar15 + fVar6 * fVar14);
      fVar6 = pfVar22[3];
      fVar1 = pfVar22[10];
      pfVar22[9] = fVar9 * fVar12 + (fVar5 * fVar19 + fVar3 * fVar18);
      pfVar22[1] = fVar9 * fVar11 + (fVar5 * fVar13 + fVar3 * fVar17);
      pfVar22[5] = fVar9 * fVar16 + (fVar5 * fVar15 + fVar3 * fVar14);
      fVar2 = pfVar22[0xb];
      pfVar22[10] = fVar1 * fVar12 + (fVar8 * fVar19 + fVar4 * fVar18);
      pfVar22[2] = fVar1 * fVar11 + (fVar8 * fVar13 + fVar4 * fVar17);
      pfVar22[6] = fVar1 * fVar16 + (fVar8 * fVar15 + fVar4 * fVar14);
      pfVar22[0xb] = fVar2 * fVar12 + (fVar6 * fVar19 + fVar7 * fVar18);
      pfVar22[3] = fVar2 * fVar11 + (fVar6 * fVar13 + fVar7 * fVar17);
      pfVar22[7] = fVar2 * fVar16 + (fVar6 * fVar15 + fVar7 * fVar14);
      uVar20 = *(uint *)(param_1 + 0x50b0);
    }
    *(uint *)(param_1 + 0x50b0) = uVar20 | uVar21;
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glRotated_Comp @ 0x8589c (416 bytes) */
void _glRotated_Comp(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  double dVar1;
  double dVar2;
  
  dVar1 = (double)*(float *)(param_1 + 0x20);
  if ((fparam_3 == dVar1) && (fparam_4 == dVar1)) {
    dVar2 = DOUBLE_00108db8;
    if (fparam_2 < dVar1) {
      dVar2 = DOUBLE_00108db0;
    }
    dVar1 = _sin(fparam_1 * dVar2);
    dVar2 = _cos(fparam_1 * dVar2);
    ((void (*)())_glRotateX_Comp)(param_1,(double)(float)dVar1,(double)(float)dVar2);
    return;
  }
  if ((fparam_2 == dVar1) && (fparam_4 == dVar1)) {
    dVar2 = DOUBLE_00108db8;
    if (fparam_3 < dVar1) {
      dVar2 = DOUBLE_00108db0;
    }
    dVar1 = _sin(fparam_1 * dVar2);
    dVar2 = _cos(fparam_1 * dVar2);
    ((void (*)())_glRotateY_Comp)(param_1,(double)(float)dVar1,(double)(float)dVar2);
    return;
  }
  if ((fparam_2 == dVar1) && (fparam_3 == dVar1)) {
    dVar2 = DOUBLE_00108db8;
    if (fparam_4 < dVar1) {
      dVar2 = DOUBLE_00108db0;
    }
    dVar1 = _sin(fparam_1 * dVar2);
    dVar2 = _cos(fparam_1 * dVar2);
    ((void (*)())_glRotateZ_Comp)(param_1,(double)(float)dVar1,(double)(float)dVar2);
    return;
  }
  ((void (*)())_glRotateXYZ_Comp)(param_1,(double)(float)fparam_1,(double)(float)fparam_2,(double)(float)fparam_3,
                    (double)(float)fparam_4);
  return;
}

/* _glRotated_Exec @ 0x85a3c (416 bytes) */
void _glRotated_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 in_LR;
  double dVar1;
  double dVar2;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  dVar1 = (double)*(float *)(param_1 + 0x20);
  if ((fparam_3 == dVar1) && (fparam_4 == dVar1)) {
    dVar2 = DOUBLE_00108db8;
    if (fparam_2 < dVar1) {
      dVar2 = DOUBLE_00108db0;
    }
    dVar1 = _sin(fparam_1 * dVar2);
    dVar2 = _cos(fparam_1 * dVar2);
    ((void (*)())_glRotateX_Exec)(param_1,(double)(float)dVar1,(double)(float)dVar2,fparam_3,fparam_4,in_f5,in_f6,
                    in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((fparam_2 == dVar1) && (fparam_4 == dVar1)) {
    dVar2 = DOUBLE_00108db8;
    if (fparam_3 < dVar1) {
      dVar2 = DOUBLE_00108db0;
    }
    dVar1 = _sin(fparam_1 * dVar2);
    dVar2 = _cos(fparam_1 * dVar2);
    ((void (*)())_glRotateY_Exec)(param_1,(double)(float)dVar1,(double)(float)dVar2,fparam_3,fparam_4,in_f5,in_f6,
                    in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((fparam_2 == dVar1) && (fparam_3 == dVar1)) {
    dVar2 = DOUBLE_00108db8;
    if (fparam_4 < dVar1) {
      dVar2 = DOUBLE_00108db0;
    }
    dVar1 = _sin(fparam_1 * dVar2);
    dVar2 = _cos(fparam_1 * dVar2);
    ((void (*)())_glRotateZ_Exec)(param_1,(double)(float)dVar1,(double)(float)dVar2,fparam_3,fparam_4,in_f5,in_f6,
                    in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  ((void (*)())_glRotateXYZ_Exec)(param_1,(double)(float)fparam_1,(double)(float)fparam_2,(double)(float)fparam_3,
                    (double)(float)fparam_4);
  return;
}

/* _glRotatef_CompExec @ 0x85bdc (536 bytes) */
void _glRotatef_CompExec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  float fVar1;
  double dVar2;
  double dVar3;
  double fparam_3_00;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  fparam_3_00 = (double)*(float *)(param_1 + 0x20);
  if ((fparam_3 == fparam_3_00) && (fparam_4 == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (fparam_2 < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    dVar2 = _sin((double)(float)(fparam_1 * (double)fVar1));
    dVar3 = _cos((double)(float)(fparam_1 * (double)fVar1));
    ((void (*)())_glRotateX_Comp)(param_1,(double)(float)dVar2,(double)(float)dVar3);
    ((void (*)())_glRotateX_Exec)(param_1,(double)(float)dVar2,(double)(float)dVar3,fparam_3_00,fparam_4,in_f5,
                    in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((fparam_2 == fparam_3_00) && (fparam_4 == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (fparam_3 < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    dVar2 = _sin((double)(float)(fparam_1 * (double)fVar1));
    dVar3 = _cos((double)(float)(fparam_1 * (double)fVar1));
    ((void (*)())_glRotateY_Comp)(param_1,(double)(float)dVar2,(double)(float)dVar3);
    ((void (*)())_glRotateY_Exec)(param_1,(double)(float)dVar2,(double)(float)dVar3,fparam_3_00,fparam_4,in_f5,
                    in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((fparam_2 == fparam_3_00) && (fparam_3 == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (fparam_4 < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    dVar2 = _sin((double)(float)(fparam_1 * (double)fVar1));
    dVar3 = _cos((double)(float)(fparam_1 * (double)fVar1));
    ((void (*)())_glRotateZ_Comp)(param_1,(double)(float)dVar2,(double)(float)dVar3);
    ((void (*)())_glRotateZ_Exec)(param_1,(double)(float)dVar2,(double)(float)dVar3,fparam_3_00,fparam_4,in_f5,
                    in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  ((void (*)())_glRotateXYZ_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glRotateXYZ_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glSampleCoverage_ListExec @ 0x85df4 (44 bytes) */
int _glSampleCoverage_ListExec(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_glSampleCoverage_Exec)(param_1,param_2,(uint)*(byte *)(param_2 + 1),(double)*param_2);
  return 8;
}

/* _glSamplePass_ListExec @ 0x85e20 (40 bytes) */
int _glSamplePass_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glSamplePass_Exec)(param_1,*param_2);
  return 4;
}

/* _glSampleCoverage_Comp @ 0x85e48 (92 bytes) */
float * _glSampleCoverage_Comp(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glSampleCoverage_ListExec_00110298,8);
  if (pfVar1 != (float *)0x0) {
    *(undefined1 *)(pfVar1 + 1) = (undefined1)param_3;
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _glSamplePass_Comp @ 0x85ea4 (76 bytes) */
int _glSamplePass_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glSamplePass_ListExec_00110294,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glSampleCoverage_Exec @ 0x85ef0 (32 bytes) */
void _glSampleCoverage_Exec(int param_1,undefined4 param_2,int param_3,float fparam_1)
{
  *(float *)(param_1 + 0x41ec) = (float)fparam_1;
  *(byte *)(param_1 + 0x41f4) = (byte)((uint)-param_3 >> 0x1f);
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x20000000;
  return;
}

/* _glSamplePass_Exec @ 0x85f10 (4 bytes) */
void _glSamplePass_Exec()
{
  return;
}

/* _glSampleCoverage_CompExec @ 0x85f14 (72 bytes) */
void _glSampleCoverage_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  undefined4 extraout_r4;
  
  ((float * (*)())_glSampleCoverage_Comp)(param_1,param_2,param_3,fparam_1);
  ((void (*)())_glSampleCoverage_Exec)(param_1,extraout_r4,param_3,fparam_1);
  return;
}

/* _glSamplePass_CompExec @ 0x85f5c (56 bytes) */
void _glSamplePass_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glSamplePass_Comp)(param_1,param_2);
  ((void (*)())_glSamplePass_Exec)(param_1,param_2);
  return;
}

/* _glScaled_Comp @ 0x85f94 (128 bytes) */
float * _glScaled_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glScale_ListExec_0011029c,0xc);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
  }
  return pfVar1;
}

/* _glScaled_CompExec @ 0x86014 (96 bytes) */
void _glScaled_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  ((float * (*)())_glScaled_Comp)(param_1,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glScale_Exec)(param_1,(double)(float)fparam_1,(double)(float)fparam_2,(double)(float)fparam_3);
  return;
}

/* _glScissor_ListExec @ 0x86074 (56 bytes) */
undefined4 _glScissor_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glScissor_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3],fparam_1,fparam_2,fparam_3,
                  fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return 0x10;
}

/* _glScissor_Comp @ 0x860ac (100 bytes) */
int _glScissor_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glScissor_ListExec_001102a0,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[3] = param_5;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
  }
  return puVar1;
}

/* _glScissor_CompExec @ 0x86110 (80 bytes) */
void _glScissor_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glScissor_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((void (*)())_glScissor_Exec)(param_1,param_2,param_3,param_4,param_5,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,
                  in_f7,in_f8);
  return;
}

/* _glSelectBuffer_Exec @ 0x86160 (100 bytes) */
void _glSelectBuffer_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4e1c) != 0x1c02)) {
    if (-1 < param_2) {
      *(int *)(param_1 + 0x4e28) = param_2;
      *(undefined1 *)(param_1 + 0x4fc8) = 0;
      *(undefined4 *)(param_1 + 0x4e24) = param_3;
      *(undefined4 *)(param_1 + 20000) = param_3;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glInitNames_ListExec @ 0x861c4 (36 bytes) */
int _glInitNames_ListExec(param_1)
  undefined4 param_1;
{
  ((void (*)())_glInitNames_Exec)(param_1);
  return 0;
}

/* _glInitNames_Comp @ 0x861e8 (32 bytes) */
int _glInitNames_Comp(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  
  uVar1 = _gleAddListItem(param_1,PTR__glInitNames_ListExec_001102b0,0);
  return uVar1;
}

/* _glInitNames_Exec @ 0x86208 (68 bytes) */
void _glInitNames_Exec(param_1)
  int param_1;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (*(int *)(param_1 + 0x4e1c) != 0x1c02) {
      return;
    }
    *(undefined1 *)(param_1 + 0x4fc8) = 0;
    *(int *)(param_1 + 0x4fbc) = param_1 + 0x4e2c;
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glInitNames_CompExec @ 0x8624c (48 bytes) */
void _glInitNames_CompExec(param_1)
  undefined4 param_1;
{
  ((int (*)())_glInitNames_Comp)(param_1);
  ((void (*)())_glInitNames_Exec)(param_1);
  return;
}

/* _glPushName_ListExec @ 0x8627c (40 bytes) */
int _glPushName_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glPushName_Exec)(param_1,*param_2);
  return 4;
}

/* _glPushName_Comp @ 0x862a4 (76 bytes) */
int _glPushName_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glPushName_ListExec_001102a8,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glPushName_Exec @ 0x862f0 (108 bytes) */
void _glPushName_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (*(int *)(param_1 + 0x4e1c) != 0x1c02) {
      return;
    }
    puVar2 = *(undefined4 **)(param_1 + 0x4fbc);
    if (puVar2 < (undefined4 *)(param_1 + 0x4fbcU)) {
      *puVar2 = param_2;
      *(undefined1 *)(param_1 + 0x4fc8) = 0;
      *(undefined4 **)(param_1 + 0x4fbc) = puVar2 + 1;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x503;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glPushName_CompExec @ 0x8635c (56 bytes) */
void _glPushName_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glPushName_Comp)(param_1,param_2);
  ((void (*)())_glPushName_Exec)(param_1,param_2);
  return;
}

/* _glPopName_ListExec @ 0x86394 (36 bytes) */
int _glPopName_ListExec(param_1)
  undefined4 param_1;
{
  ((void (*)())_glPopName_Exec)(param_1);
  return 0;
}

/* _glPopName_Comp @ 0x863b8 (32 bytes) */
int _glPopName_Comp(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  
  uVar1 = _gleAddListItem(param_1,PTR__glPopName_ListExec_001102a4,0);
  return uVar1;
}

/* _glPopName_Exec @ 0x863d8 (104 bytes) */
void _glPopName_Exec(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (*(int *)(param_1 + 0x4e1c) != 0x1c02) {
      return;
    }
    if (*(int *)(param_1 + 0x4fbc) != param_1 + 0x4e2c) {
      *(undefined1 *)(param_1 + 0x4fc8) = 0;
      *(int *)(param_1 + 0x4fbc) = *(int *)(param_1 + 0x4fbc) + -4;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x504;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glPopName_CompExec @ 0x86440 (48 bytes) */
void _glPopName_CompExec(param_1)
  undefined4 param_1;
{
  ((int (*)())_glPopName_Comp)(param_1);
  ((void (*)())_glPopName_Exec)(param_1);
  return;
}

/* _glShadeModel_ListExec @ 0x86470 (40 bytes) */
int _glShadeModel_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glShadeModel_Exec(param_1,*param_2);
  return 4;
}

/* _glShadeModel_Comp @ 0x86498 (76 bytes) */
int _glShadeModel_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glShadeModel_ListExec_001102b4,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glShadeModel_CompExec @ 0x864e4 (56 bytes) */
void _glShadeModel_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glShadeModel_Comp)(param_1,param_2);
  _glShadeModel_Exec(param_1,param_2);
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
void _updateShaderState(int param_1,int *param_2,uint param_3,int param_4,int param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == (int *)0x0) {
    *(undefined1 *)(param_1 + 0x759c) = 1;
    *(undefined4 *)(param_1 + 0x5434) = 0;
    *(undefined4 *)(param_1 + 0x5438) = 0;
    if (param_3 != 0) {
      if (param_4 != 0) {
        _gleVPDisable(param_1);
      }
      if (param_5 != 0) {
        _gleFPDisable(param_1);
      }
    }
    if (param_3 != 1) {
      _gleUpdateDrawArraysFuncs(param_1);
    }
    iVar3 = param_1 + 0x10000;
    iVar4 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      do {
        *(undefined4 *)(iVar3 + -0x7788) = 0;
        iVar4 = iVar4 + 1;
        *(undefined4 *)(iVar3 + -0x7784) = 0;
        iVar3 = iVar3 + 0x2e0;
      } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
  }
  else {
    bVar1 = *(byte *)((int)param_2 + 0x1e);
    *(byte *)(param_1 + 0x759c) = bVar1;
    if ((*(char *)*param_2 == '\0') || (*(char *)((int)param_2 + 0x1e) == '\0')) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    *(undefined4 *)(param_1 + 0x5434) = uVar2;
    if ((*(char *)param_2[1] == '\0') || (*(char *)((int)param_2 + 0x1e) == '\0')) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    *(undefined4 *)(param_1 + 0x5438) = uVar2;
    if (((*(int *)(param_1 + 0x5434) == 0) || (param_3 == 0)) || (param_4 == 0)) {
      if (*(int *)(param_1 + 0x5434) == 0) {
        _gleVPDisable(param_1);
      }
      else {
        ((double (*)())_gleVPEnable)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8
                    );
      }
    }
    else {
      ((void (*)())_gleVPChanged)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8)
      ;
    }
    if (((*(int *)(param_1 + 0x5438) == 0) || (param_3 == 0)) || (param_5 == 0)) {
      if (*(int *)(param_1 + 0x5438) == 0) {
        _gleFPDisable(param_1);
      }
      else {
        _gleFPEnable(param_1);
      }
    }
    else {
      _gleFPChanged(param_1);
    }
    if (bVar1 != param_3) {
      _gleUpdateDrawArraysFuncs(param_1);
    }
    if ((*(int *)(param_1 + 0x5434) != 0) || (*(int *)(param_1 + 0x5438) != 0)) {
      _gleUpdateInverseNeeds(param_1);
    }
    iVar3 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      do {
        if (*(int *)(param_1 + 0x5434) == 0) {
          *(undefined4 *)(iVar3 * 0x2e0 + param_1 + 0x8878) = 0;
        }
        else {
          *(undefined4 *)(iVar3 * 0x2e0 + param_1 + 0x8878) =
               *(undefined4 *)(iVar3 * 4 + *param_2 + 0x4e4);
        }
        if (*(int *)(param_1 + 0x5438) == 0) {
          *(undefined4 *)(iVar3 * 0x2e0 + param_1 + 0x887c) = 0;
        }
        else {
          *(undefined4 *)(iVar3 * 0x2e0 + param_1 + 0x887c) =
               *(undefined4 *)(iVar3 * 4 + param_2[1] + 0x4e4);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
  }
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
  return;
}

/* _glUseProgramObjectARB_Exec @ 0x8683c (1324 bytes) */
void _glUseProgramObjectARB_Exec(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  bool bVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  short *psVar12;
  undefined2 *puVar13;
  int *piVar14;
  undefined4 *puVar15;
  short *psVar16;
  undefined2 *puVar17;
  int *piVar18;
  uint *puVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int *piVar23;
  int *piVar24;
  int iVar25;
  double extraout_f1;
  double extraout_f1_00;
  
  piVar24 = (int *)0x0;
  piVar23 = (int *)0x0;
  uVar21 = 0;
  uVar20 = 1;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_lock(*(int *)(param_1 + 0x5148) + 0x8028);
      fparam_1 = extraout_f1;
    }
    iVar22 = *(int *)(param_1 + 0x5430);
    bVar2 = iVar22 == 0;
    if (!bVar2) {
      piVar24 = (int *)(iVar22 + 0x20);
      uVar20 = (uint)*(byte *)(iVar22 + 0x3e);
      uVar21 = (uint)**(byte **)(iVar22 + 0x24);
    }
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x5430) = 0;
LAB_00086cd4:
      ((void (*)())_updateShaderState)(param_1,piVar23,uVar20,uVar21,0,fparam_1,fparam_2,fparam_3,fparam_4,
                         fparam_5,fparam_6,fparam_7,fparam_8);
      if ((!bVar2) && (iVar7 = *(int *)(iVar22 + 8) + -1, *(int *)(iVar22 + 8) = iVar7, iVar7 == 1))
      {
        _gleDeleteHashNameAndObject
                  (param_1,*(int *)(param_1 + 0x5148) + 0x6018,*(undefined4 *)(iVar22 + 4));
      }
    }
    else {
      iVar7 = _gleLookupHashObject(*(int *)(param_1 + 0x5148) + 0x6018,param_2);
      if (iVar7 == 0) {
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
        }
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar4 = 0x501;
        goto LAB_0008694c;
      }
      if ((*(int *)(iVar7 + 0x10) != 0x8b40) || (*(char *)(iVar7 + 0x3c) != '\x01')) {
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
        }
        goto LAB_0008693c;
      }
      if (iVar7 != *(int *)(param_1 + 0x5430)) {
        *(int *)(param_1 + 0x5430) = iVar7;
        piVar23 = (int *)(iVar7 + 0x20);
        if ((**(char **)(iVar7 + 0x20) != '\0') || (**(char **)(iVar7 + 0x24) != '\0')) {
          if (bVar2) {
            iVar8 = 0;
            if (*(char *)(iVar7 + 0x3e) == '\0') {
              do {
                if (iVar8 == 0) {
                  iVar6 = *piVar23;
                  iVar25 = 0;
                }
                else {
                  iVar6 = *(int *)(iVar7 + 0x24);
                  iVar25 = 0x10;
                }
                if (iVar25 != 0) {
                  puVar11 = (undefined4 *)(iVar6 + 0x2c);
                  puVar13 = (undefined2 *)(iVar6 + 0x6c);
                  iVar6 = param_1 + 0x3530;
                  do {
                    uVar10 = 0;
                    if (*(int *)(iVar6 + 4) != 0) {
                      *puVar11 = 1;
                      uVar10 = *(uint *)(iVar6 + 4);
                    }
                    if ((uVar10 & 1) == 0) {
                      if ((uVar10 & 2) == 0) {
                        if ((uVar10 & 4) == 0) {
                          if ((uVar10 & 8) == 0) {
                            if ((uVar10 & 0x10) == 0) {
                              *puVar13 = 0;
                            }
                            else {
                              *puVar13 = 0x8b5d;
                            }
                          }
                          else {
                            *puVar13 = 0x8b5e;
                          }
                        }
                        else {
                          *puVar13 = 0x8b63;
                        }
                      }
                      else {
                        *puVar13 = 0x8b5f;
                      }
                    }
                    else {
                      *puVar13 = 0x8b60;
                    }
                    iVar6 = iVar6 + 0x7c;
                    puVar11 = puVar11 + 1;
                    puVar13 = puVar13 + 1;
                    iVar25 = iVar25 + -1;
                  } while (iVar25 != 0);
                }
                iVar8 = iVar8 + 1;
              } while (iVar8 < 2);
            }
            else {
              do {
                if (iVar8 == 0) {
                  iVar6 = *piVar23;
                  iVar25 = 0;
                }
                else {
                  iVar6 = *(int *)(iVar7 + 0x24);
                  iVar25 = 0x10;
                }
                uVar10 = 0;
                if (iVar25 != 0) {
                  piVar24 = (int *)(iVar6 + 0x2c);
                  psVar12 = (short *)(iVar6 + 0x6c);
                  puVar19 = (uint *)(param_1 + 0x3534);
                  do {
                    if (*puVar19 == 0) {
                      if (*piVar24 == 0) goto LAB_00086c28;
LAB_00086c90:
                      *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 1 << (uVar10 & 0x3f)
                      ;
                    }
                    else {
                      if (*piVar24 == 0) goto LAB_00086c90;
LAB_00086c28:
                      uVar5 = *puVar19;
                      if ((uVar5 & 1) == 0) {
                        if ((uVar5 & 2) != 0) {
                          bVar1 = *psVar12 == -0x74a1;
                          goto LAB_00086c8c;
                        }
                        if ((uVar5 & 4) != 0) {
                          bVar1 = *psVar12 == -0x749d;
                          goto LAB_00086c8c;
                        }
                        if ((uVar5 & 8) != 0) {
                          bVar1 = *psVar12 == -0x74a2;
                          goto LAB_00086c8c;
                        }
                        if ((uVar5 & 0x10) != 0) {
                          bVar1 = *psVar12 == -0x74a3;
                          goto LAB_00086c8c;
                        }
                      }
                      else {
                        bVar1 = *psVar12 == -0x74a0;
LAB_00086c8c:
                        if (!bVar1) goto LAB_00086c90;
                      }
                    }
                    uVar10 = uVar10 + 1;
                    piVar24 = piVar24 + 1;
                    puVar19 = puVar19 + 0x1f;
                    psVar12 = psVar12 + 1;
                    iVar25 = iVar25 + -1;
                  } while (iVar25 != 0);
                }
                iVar8 = iVar8 + 1;
              } while (iVar8 < 2);
            }
          }
          else {
            iVar8 = 0;
            if (*(char *)(iVar7 + 0x3e) == '\0') {
              do {
                if (iVar8 == 0) {
                  iVar9 = *piVar24;
                  iVar6 = *piVar23;
                  iVar25 = 0;
                }
                else {
                  iVar9 = piVar24[1];
                  iVar25 = 0x10;
                  iVar6 = *(int *)(iVar7 + 0x24);
                }
                if (iVar25 != 0) {
                  puVar11 = (undefined4 *)(iVar6 + 0x2c);
                  puVar15 = (undefined4 *)(iVar9 + 0x2c);
                  puVar17 = (undefined2 *)(iVar6 + 0x6c);
                  puVar13 = (undefined2 *)(iVar9 + 0x6c);
                  do {
                    uVar4 = *puVar15;
                    puVar15 = puVar15 + 1;
                    uVar3 = *puVar13;
                    puVar13 = puVar13 + 1;
                    *puVar11 = uVar4;
                    puVar11 = puVar11 + 1;
                    *puVar17 = uVar3;
                    puVar17 = puVar17 + 1;
                    iVar25 = iVar25 + -1;
                  } while (iVar25 != 0);
                }
                iVar8 = iVar8 + 1;
              } while (iVar8 < 2);
            }
            else {
              do {
                if (iVar8 == 0) {
                  iVar9 = *piVar24;
                  iVar6 = *piVar23;
                  iVar25 = 0;
                }
                else {
                  iVar9 = piVar24[1];
                  iVar25 = 0x10;
                  iVar6 = *(int *)(iVar7 + 0x24);
                }
                uVar10 = 0;
                if (iVar25 != 0) {
                  piVar18 = (int *)(iVar9 + 0x2c);
                  piVar14 = (int *)(iVar6 + 0x2c);
                  psVar12 = (short *)(iVar9 + 0x6c);
                  psVar16 = (short *)(iVar6 + 0x6c);
                  do {
                    iVar9 = *piVar14;
                    piVar14 = piVar14 + 1;
                    iVar6 = *piVar18;
                    piVar18 = piVar18 + 1;
                    if ((iVar9 != iVar6) || ((iVar9 != 0 && (*psVar16 != *psVar12)))) {
                      *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 1 << (uVar10 & 0x3f)
                      ;
                    }
                    uVar10 = uVar10 + 1;
                    psVar16 = psVar16 + 1;
                    psVar12 = psVar12 + 1;
                    iVar25 = iVar25 + -1;
                  } while (iVar25 != 0);
                }
                iVar8 = iVar8 + 1;
              } while (iVar8 < 2);
            }
          }
        }
        *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + 1;
        fparam_1 = extraout_f1_00;
        goto LAB_00086cd4;
      }
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      return;
    }
  }
  else {
LAB_0008693c:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar4 = 0x502;
LAB_0008694c:
    *(undefined4 *)(param_1 + 0x7574) = uVar4;
  }
  return;
}

/* _glUseProgramObjectARB_Comp @ 0x86d68 (76 bytes) */
int _glUseProgramObjectARB_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glUseProgramObjectARB_ListExec_00110304,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glUseProgramObjectARB_CompExec @ 0x86db4 (56 bytes) */
void _glUseProgramObjectARB_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glUseProgramObjectARB_Comp)(param_1,param_2);
  ((void (*)())_glUseProgramObjectARB_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glUseProgramObjectARB_ListExec @ 0x86dec (40 bytes) */
undefined4 _glUseProgramObjectARB_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glUseProgramObjectARB_Exec)(param_1,*param_2,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
             fparam_8);
  return 4;
}

/* _glCreateShaderObjectARB_Exec @ 0x86e14 (420 bytes) */
int _glCreateShaderObjectARB_Exec(param_1, param_2)
  int param_1;
  code *param_2;
{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar2 = 0x502;
LAB_00086e94:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
    return 0;
  }
  if (param_2 == (code *)0x8b30) {
    iVar3 = 0x38;
  }
  else {
    iVar3 = 0x3c;
    if (param_2 != (code *)0x8b31) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return 0;
      }
      uVar2 = 0x500;
      goto LAB_00086e94;
    }
  }
  puVar4 = (undefined4 *)_gleVecAlloc(iVar3 + 0xfU & 0xfffffff0);
  uVar2 = _gleGenHashNames(*(int *)(param_1 + 0x5148) + 0x6018,1);
  puVar1 = PTR__gleFreeShaderObject_00112048;
  puVar4[2] = 2;
  puVar4[3] = puVar1;
  puVar4[4] = 0x8b48;
  puVar4[1] = uVar2;
  *puVar4 = 0;
  *(undefined1 *)(puVar4 + 5) = 0;
  puVar4[7] = 0;
  puVar4[6] = 0;
  puVar4[8] = param_2;
  *(undefined1 *)((int)puVar4 + 0x25) = 0;
  puVar4[0xb] = 0;
  puVar4[10] = 0;
  *(undefined1 *)(puVar4 + 9) = 0;
  puVar4[0xc] = 0;
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_lock(*(int *)(param_1 + 0x5148) + 0x8028);
  }
  _ShInitialize();
  if (param_2 == (code *)0x8b30) {
    if (puVar4 == (undefined4 *)0xffffffcc) goto LAB_00086f70;
  }
  else {
    if ((param_2 != (code *)0x8b31) || (puVar4 == (undefined4 *)0xffffffcc)) goto LAB_00086f70;
    puVar4[0xe] = 0;
  }
  puVar4[0xd] = 0;
LAB_00086f70:
  _gleAddHashNameAndObject(param_1,*(int *)(param_1 + 0x5148) + 0x6018,puVar4);
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
  }
  return uVar2;
}

/* _glCreateProgramObjectARB_Exec @ 0x86fb8 (484 bytes) */
int _glCreateProgramObjectARB_Exec(param_1)
  int param_1;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar6 = _gleVecAlloc(0x50);
    _memset(iVar6,0,0x50);
    uVar5 = _gleGenHashNames(*(int *)(param_1 + 0x5148) + 0x6018,1);
    puVar4 = PTR__gleFreeShaderObject_00112048;
    *(undefined4 *)(iVar6 + 8) = 2;
    *(undefined **)(iVar6 + 0xc) = puVar4;
    *(undefined4 *)(iVar6 + 0x10) = 0x8b40;
    *(undefined1 *)(iVar6 + 0x14) = 0;
    *(undefined4 *)(iVar6 + 4) = uVar5;
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_lock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
    uVar7 = _gleVecAlloc(0x520);
    *(undefined4 *)(iVar6 + 0x20) = uVar7;
    _memset(uVar7,0,0x520);
    uVar7 = _gleVecAlloc(0x520);
    *(undefined4 *)(iVar6 + 0x24) = uVar7;
    iVar9 = 0;
    _memset(uVar7,0,0x520);
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      iVar10 = param_1 + 0x85a0;
      do {
        iVar3 = iVar9 * 4;
        iVar9 = iVar9 + 1;
        (**(code **)(*(int *)(iVar10 + 0x2e4) + 400))
                  (*(undefined4 *)(iVar10 + 0xc),*(int *)(iVar6 + 0x24) + iVar3 + 0x4e4,
                   *(int *)(iVar6 + 0x24) + 0x504);
        piVar1 = (int *)(iVar10 + 0x2e4);
        iVar8 = *(int *)(iVar6 + 0x20);
        puVar2 = (undefined4 *)(iVar10 + 0xc);
        iVar10 = iVar10 + 0x2e0;
        (**(code **)(*piVar1 + 400))(*puVar2,iVar8 + iVar3 + 0x4e4,iVar8 + 0x504);
      } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
    iVar9 = *(int *)(iVar6 + 0x20);
    *(undefined2 *)(iVar9 + 0x506) = 0;
    *(undefined2 *)(iVar9 + 0x504) = 0x8b31;
    iVar9 = *(int *)(iVar6 + 0x24);
    *(undefined2 *)(iVar9 + 0x506) = 1;
    *(undefined2 *)(iVar9 + 0x504) = 0x8b30;
    _ShInitialize();
    uVar7 = _ShConstructLinker(0);
    *(undefined4 *)(iVar6 + 0x40) = uVar7;
    _gleAddHashNameAndObject(param_1,*(int *)(param_1 + 0x5148) + 0x6018,iVar6);
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  else {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    uVar5 = 0;
  }
  return uVar5;
}

