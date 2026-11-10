#include "decls.h"

/* _glLoadTransposeMatrixd_CompExec @ 0x776e8 (56 bytes) */
void _glLoadTransposeMatrixd_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  _glLoadTransposeMatrixd_Comp(param_1,param_2);
  _glLoadTransposeMatrixd_Exec(param_1,param_2);
  return;
}

/* _glLoadTransposeMatrixf_ListExec @ 0x77720 (36 bytes) */
int _glLoadTransposeMatrixf_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glLoadTransposeMatrixf_Exec)(param_1,param_2);
  return 0x40;
}

/* _glLoadTransposeMatrixf_Comp @ 0x77744 (100 bytes) */
int _glLoadTransposeMatrixf_Comp(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _gleAddListItem(param_1,PTR__glLoadTransposeMatrixf_ListExec_001101fc,0x40);
  if (iVar2 != 0) {
    iVar1 = 0;
    iVar3 = 0x10;
    do {
      *(undefined4 *)(iVar1 + iVar2) = *(undefined4 *)(iVar1 + param_2);
      iVar1 = iVar1 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar2;
}

/* _glLoadTransposeMatrixf_Exec @ 0x777a8 (128 bytes) */
int _glLoadTransposeMatrixf_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    param_2 = _gleLoadTransposeMatrixf(param_2,*(undefined4 *)(param_1 + 0x4fec));
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | *(uint *)(param_1 + 0x50a8);
    *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) | *(uint *)(param_1 + 0x50a8);
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return param_2;
}

/* _glLoadTransposeMatrixf_CompExec @ 0x77828 (56 bytes) */
void _glLoadTransposeMatrixf_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glLoadTransposeMatrixf_Comp)(param_1,param_2);
  ((int (*)())_glLoadTransposeMatrixf_Exec)(param_1,param_2);
  return;
}

/* _glMatrixMode_CompExec @ 0x77860 (56 bytes) */
void _glMatrixMode_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  _glMatrixMode_Comp(param_1,param_2);
  _glMatrixMode_Exec(param_1,param_2);
  return;
}

/* _glMultMatrixd_ListExec @ 0x77898 (36 bytes) */
int _glMultMatrixd_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  _glMultMatrixd_Exec(param_1,param_2);
  return 0x80;
}

/* _glMultMatrixd_Comp @ 0x778bc (100 bytes) */
int _glMultMatrixd_Comp(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _gleAddListItem(param_1,PTR__glMultMatrixd_ListExec_00110220,0x80);
  if (iVar2 != 0) {
    iVar1 = 0;
    iVar3 = 0x10;
    do {
      *(undefined8 *)(iVar1 + iVar2) = *(undefined8 *)(iVar1 + param_2);
      iVar1 = iVar1 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar2;
}

/* _glMultMatrixd_CompExec @ 0x77920 (56 bytes) */
void _glMultMatrixd_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glMultMatrixd_Comp)(param_1,param_2);
  _glMultMatrixd_Exec(param_1,param_2);
  return;
}

/* _glMultMatrixf_ListExec @ 0x77958 (36 bytes) */
int _glMultMatrixf_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  _glMultMatrixf_Exec(param_1,param_2);
  return 0x40;
}

/* _glMultMatrixf_Comp @ 0x7797c (100 bytes) */
int _glMultMatrixf_Comp(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _gleAddListItem(param_1,PTR__glMultMatrixf_ListExec_0011021c,0x40);
  if (iVar2 != 0) {
    iVar1 = 0;
    iVar3 = 0x10;
    do {
      *(undefined4 *)(iVar1 + iVar2) = *(undefined4 *)(iVar1 + param_2);
      iVar1 = iVar1 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar2;
}

/* _glMultMatrixf_CompExec @ 0x779e0 (56 bytes) */
void _glMultMatrixf_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glMultMatrixf_Comp)(param_1,param_2);
  _glMultMatrixf_Exec(param_1,param_2);
  return;
}

/* _glMultTransposeMatrixd_ListExec @ 0x77a18 (36 bytes) */
int _glMultTransposeMatrixd_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glMultTransposeMatrixd_Exec)(param_1,param_2);
  return 0x80;
}

/* _glMultTransposeMatrixd_Comp @ 0x77a3c (100 bytes) */
int _glMultTransposeMatrixd_Comp(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _gleAddListItem(param_1,PTR__glMultTransposeMatrixd_ListExec_00110218,0x80);
  if (iVar2 != 0) {
    iVar1 = 0;
    iVar3 = 0x10;
    do {
      *(undefined8 *)(iVar1 + iVar2) = *(undefined8 *)(iVar1 + param_2);
      iVar1 = iVar1 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar2;
}

/* _glMultTransposeMatrixd_Exec @ 0x77aa0 (140 bytes) */
int _glMultTransposeMatrixd_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined1 auStack_50 [72];
  
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    _gleMultTransposeMatrixd(*(undefined4 *)(param_1 + 0x4fec),param_2,auStack_50);
    iVar1 = _gleCopyMatrix(auStack_50,*(undefined4 *)(param_1 + 0x4fec));
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | *(uint *)(param_1 + 0x50a8);
    *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) | *(uint *)(param_1 + 0x50a8);
  }
  else {
    iVar1 = param_1;
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return iVar1;
}

/* _glMultTransposeMatrixd_CompExec @ 0x77b2c (56 bytes) */
void _glMultTransposeMatrixd_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glMultTransposeMatrixd_Comp)(param_1,param_2);
  ((int (*)())_glMultTransposeMatrixd_Exec)(param_1,param_2);
  return;
}

/* _glMultTransposeMatrixf_ListExec @ 0x77b64 (36 bytes) */
int _glMultTransposeMatrixf_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glMultTransposeMatrixf_Exec)(param_1,param_2);
  return 0x40;
}

/* _glMultTransposeMatrixf_Comp @ 0x77b88 (100 bytes) */
int _glMultTransposeMatrixf_Comp(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _gleAddListItem(param_1,PTR__glMultTransposeMatrixf_ListExec_00110214,0x40);
  if (iVar2 != 0) {
    iVar1 = 0;
    iVar3 = 0x10;
    do {
      *(undefined4 *)(iVar1 + iVar2) = *(undefined4 *)(iVar1 + param_2);
      iVar1 = iVar1 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar2;
}

/* _glMultTransposeMatrixf_Exec @ 0x77bec (140 bytes) */
int _glMultTransposeMatrixf_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined1 auStack_50 [72];
  
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    _gleMultTransposeMatrixf(*(undefined4 *)(param_1 + 0x4fec),param_2,auStack_50);
    iVar1 = _gleCopyMatrix(auStack_50,*(undefined4 *)(param_1 + 0x4fec));
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | *(uint *)(param_1 + 0x50a8);
    *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) | *(uint *)(param_1 + 0x50a8);
  }
  else {
    iVar1 = param_1;
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return iVar1;
}

/* _glMultTransposeMatrixf_CompExec @ 0x77c78 (56 bytes) */
void _glMultTransposeMatrixf_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glMultTransposeMatrixf_Comp)(param_1,param_2);
  ((int (*)())_glMultTransposeMatrixf_Exec)(param_1,param_2);
  return;
}

/* _glNormal3b_Comp @ 0x77cb0 (196 bytes) */
int _glNormal3b_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  float fVar2;
  float *pfVar3;
  
  pfVar3 = (float *)_gleAddListItem(param_1,PTR__glNormal_ListExec_00110224,0xc);
  fVar2 = FLOAT_00108e98;
  dVar1 = DOUBLE_00108d58;
  if (pfVar3 != (float *)0x0) {
    *pfVar3 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e98;
    pfVar3[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1) * fVar2;
    pfVar3[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1) * fVar2;
  }
  return pfVar3;
}

/* _glNormal3b_Exec @ 0x77d74 (128 bytes) */
void _glNormal3b_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e98;
  fVar2 = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e98;
  *(float *)(param_1 + 0x2b4) =
       (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e98
  ;
  *(float *)(param_1 + 0x2b0) = fVar1;
  *(float *)(param_1 + 0x2b8) = fVar2;
  return;
}

/* _glNormal3b_CompExec @ 0x77df4 (72 bytes) */
void _glNormal3b_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glNormal3b_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glNormal3b_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glNormal3bv_Comp @ 0x77e3c (212 bytes) */
int _glNormal3bv_Comp(param_1, param_2)
  undefined4 param_1;
  char *param_2;
{
  double dVar1;
  float fVar2;
  float *pfVar3;
  
  pfVar3 = (float *)_gleAddListItem(param_1,PTR__glNormal_ListExec_00110224,0xc);
  fVar2 = FLOAT_00108e98;
  dVar1 = DOUBLE_00108d58;
  if (pfVar3 != (float *)0x0) {
    *pfVar3 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e98;
    pfVar3[1] = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
    pfVar3[2] = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1) * fVar2;
  }
  return pfVar3;
}

/* _glNormal3bv_Exec @ 0x77f10 (152 bytes) */
double _glNormal3bv_Exec(param_1, param_2)
  int param_1;
  char *param_2;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e98;
  fVar2 = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e98;
  *(float *)(param_1 + 0x2b4) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(param_1 + 0x2b0) = fVar1;
  *(float *)(param_1 + 0x2b8) = fVar2;
  return;
}

/* _glNormal3bv_CompExec @ 0x77fa8 (56 bytes) */
void _glNormal3bv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glNormal3bv_Comp)(param_1,param_2);
  ((double (*)())_glNormal3bv_Exec)(param_1,param_2);
  return;
}

/* _glNormal3d_Comp @ 0x77fe0 (128 bytes) */
float * _glNormal3d_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glNormal_ListExec_00110224,0xc);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
  }
  return pfVar1;
}

/* _glNormal3d_CompExec @ 0x7807c (124 bytes) */
void _glNormal3d_CompExec(int param_1,double fparam_1,double fparam_2,double fparam_3)
{
  ((float * (*)())_glNormal3d_Comp)(param_1,fparam_1,fparam_2,fparam_3);
  *(float *)(param_1 + 0x2b4) = (float)fparam_2;
  *(float *)(param_1 + 0x2b8) = (float)fparam_3;
  *(float *)(param_1 + 0x2b0) = (float)fparam_1;
  return;
}

/* _glNormal3dv_Comp @ 0x780dc (108 bytes) */
int _glNormal3dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glNormal_ListExec_00110224,0xc);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)*param_2;
    pfVar1[1] = (float)param_2[1];
    pfVar1[2] = (float)param_2[2];
  }
  return pfVar1;
}

/* _glNormal3dv_Exec @ 0x78148 (40 bytes) */
double _glNormal3dv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar1 = param_2[1];
  dVar2 = param_2[2];
  *(float *)(param_1 + 0x2b0) = (float)*param_2;
  *(float *)(param_1 + 0x2b4) = (float)dVar1;
  *(float *)(param_1 + 0x2b8) = (float)dVar2;
  return;
}

/* _glNormal3dv_CompExec @ 0x78170 (56 bytes) */
void _glNormal3dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glNormal3dv_Comp)(param_1,param_2);
  ((double (*)())_glNormal3dv_Exec)(param_1,param_2);
  return;
}

/* _glNormal3fv_Comp @ 0x781a8 (96 bytes) */
int _glNormal3fv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glNormal_ListExec_00110224,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    puVar1[2] = param_2[2];
  }
  return puVar1;
}

/* _glNormal3fv_Exec @ 0x78208 (28 bytes) */
double _glNormal3fv_Exec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  *(undefined4 *)(param_1 + 0x2b0) = *param_2;
  *(undefined4 *)(param_1 + 0x2b4) = uVar1;
  *(undefined4 *)(param_1 + 0x2b8) = uVar2;
  return;
}

/* _glNormal3fv_CompExec @ 0x78224 (56 bytes) */
void _glNormal3fv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glNormal3fv_Comp)(param_1,param_2);
  ((double (*)())_glNormal3fv_Exec)(param_1,param_2);
  return;
}

/* _glNormal3i_Comp @ 0x7825c (208 bytes) */
void _glNormal3i_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  double dVar2;
  float *pfVar3;
  
  pfVar3 = (float *)_gleAddListItem(param_1,PTR__glNormal_ListExec_00110224,0xc);
  dVar2 = DOUBLE_00108d88;
  dVar1 = DOUBLE_00108d58;
  if (pfVar3 != (float *)0x0) {
    *pfVar3 = (float)((double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                     DOUBLE_00108d58) * DOUBLE_00108d88);
    pfVar3[1] = (float)((double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1) *
                       dVar2);
    pfVar3[2] = (float)((double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1) *
                       dVar2);
  }
  return;
}

/* _glNormal3i_Exec @ 0x7832c (144 bytes) */
void _glNormal3i_Exec(int param_1,uint param_2,uint param_3,uint param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58) *
          DOUBLE_00108d88;
  dVar1 = (double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          DOUBLE_00108d88;
  *(float *)(param_1 + 0x2b4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  *(float *)(param_1 + 0x2b8) = (float)dVar2;
  *(float *)(param_1 + 0x2b0) = (float)dVar1;
  return;
}

/* _glNormal3i_CompExec @ 0x783bc (72 bytes) */
void _glNormal3i_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
{
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  
  ((void (*)())_glNormal3i_Exec)(param_1,param_2,param_3,param_4,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                   fparam_6,fparam_7,fparam_8,in_stack_ffffffa8,in_stack_ffffffb0,in_stack_ffffffb8)
  ;
  ((void (*)())_glNormal3i_Comp)(param_1,param_2,param_3,param_4);
  return;
}

/* _glNormal3iv_Comp @ 0x78404 (212 bytes) */
int _glNormal3iv_Comp(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  double dVar1;
  double dVar2;
  float *pfVar3;
  
  pfVar3 = (float *)_gleAddListItem(param_1,PTR__glNormal_ListExec_00110224,0xc);
  dVar2 = DOUBLE_00108d88;
  dVar1 = DOUBLE_00108d58;
  if (pfVar3 != (float *)0x0) {
    *pfVar3 = (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) -
                                     DOUBLE_00108d58) * DOUBLE_00108d88);
    pfVar3[1] = (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1
                                       ) * dVar2);
    pfVar3[2] = (float)((double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - dVar1
                                       ) * dVar2);
  }
  return pfVar3;
}

/* _glNormal3iv_Exec @ 0x784d8 (156 bytes) */
double _glNormal3iv_Exec(int param_1,uint *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - DOUBLE_00108d58) *
          DOUBLE_00108d88;
  dVar1 = (double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          DOUBLE_00108d88;
  *(float *)(param_1 + 0x2b4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) -
                              DOUBLE_00108d58) * DOUBLE_00108d88);
  *(float *)(param_1 + 0x2b8) = (float)dVar2;
  *(float *)(param_1 + 0x2b0) = (float)dVar1;
  return;
}

/* _glNormal3iv_CompExec @ 0x78574 (56 bytes) */
void _glNormal3iv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  unsigned int ghidra_home[8] = { param_1, param_2, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glNormal3iv_Comp)(param_1,param_2);
  ((double (*)())_glNormal3iv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                    (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)));
  return;
}

/* _glNormal3s_Comp @ 0x785ac (196 bytes) */
int _glNormal3s_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  float fVar2;
  float *pfVar3;
  
  pfVar3 = (float *)_gleAddListItem(param_1,PTR__glNormal_ListExec_00110224,0xc);
  fVar2 = FLOAT_00108e9c;
  dVar1 = DOUBLE_00108d58;
  if (pfVar3 != (float *)0x0) {
    *pfVar3 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e9c;
    pfVar3[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1) * fVar2;
    pfVar3[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1) * fVar2;
  }
  return pfVar3;
}

/* _glNormal3s_Exec @ 0x78670 (128 bytes) */
void _glNormal3s_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e9c;
  fVar2 = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e9c;
  *(float *)(param_1 + 0x2b4) =
       (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e9c
  ;
  *(float *)(param_1 + 0x2b0) = fVar1;
  *(float *)(param_1 + 0x2b8) = fVar2;
  return;
}

/* _glNormal3s_CompExec @ 0x786f0 (72 bytes) */
void _glNormal3s_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glNormal3s_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glNormal3s_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glNormal3sv_Comp @ 0x78738 (200 bytes) */
int _glNormal3sv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  double dVar1;
  float fVar2;
  float *pfVar3;
  
  pfVar3 = (float *)_gleAddListItem(param_1,PTR__glNormal_ListExec_00110224,0xc);
  fVar2 = FLOAT_00108e9c;
  dVar1 = DOUBLE_00108d58;
  if (pfVar3 != (float *)0x0) {
    *pfVar3 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e9c;
    pfVar3[1] = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
    pfVar3[2] = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1) * fVar2;
  }
  return pfVar3;
}

/* _glNormal3sv_Exec @ 0x78800 (140 bytes) */
double _glNormal3sv_Exec(param_1, param_2)
  int param_1;
  short *param_2;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e9c;
  fVar2 = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e9c;
  *(float *)(param_1 + 0x2b4) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(param_1 + 0x2b0) = fVar1;
  *(float *)(param_1 + 0x2b8) = fVar2;
  return;
}

/* _glNormal3sv_CompExec @ 0x7888c (56 bytes) */
void _glNormal3sv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glNormal3sv_Comp)(param_1,param_2);
  ((double (*)())_glNormal3sv_Exec)(param_1,param_2);
  return;
}

/* _glGenQueries_Exec @ 0x788c4 (176 bytes) */
void _glGenQueries_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x7444) == 0)) {
    if (-1 < param_2) {
      iVar4 = _gleGenHashNames(param_1 + 0x6440,param_2);
      if (iVar4 == 0) {
        return;
      }
      iVar3 = 0;
      if (param_2 < 1) {
        return;
      }
      do {
        iVar2 = iVar3 + iVar4;
        iVar3 = iVar3 + 1;
        *param_3 = iVar2;
        param_3 = param_3 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
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

/* _glDeleteQueries_Exec @ 0x78974 (164 bytes) */
void _glDeleteQueries_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x7444) == 0)) {
    if (-1 < param_2) {
      if (param_2 < 1) {
        return;
      }
      do {
        uVar1 = *param_3;
        param_3 = param_3 + 1;
        _gleDeleteHashNameAndObject(param_1,param_1 + 0x6440,uVar1);
        param_2 = param_2 + -1;
      } while (param_2 != 0);
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

/* _glBeginQuery_Exec @ 0x78a18 (792 bytes) */
void _glBeginQuery_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  double extraout_f1;
  double fparam_1;
  double extraout_f1_00;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  if (((-1 < *(short *)(param_1 + 0x4a10)) || (*(int *)(param_1 + 0x7444) != 0)) || (param_3 == 0))
  {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00078cc8;
  }
  if (param_2 != 0x8914) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
    goto LAB_00078cc8;
  }
  iVar8 = param_3;
  iVar5 = _gleLookupHashObject(param_1 + 0x6440,param_3);
  fparam_1 = extraout_f1;
  if (iVar5 == 0) {
    iVar5 = _gleCreateQueryObject(param_1,param_3);
    iVar8 = iVar5;
    fparam_1 = (double)_gleAddHashNameAndObject(param_1,param_1 + 0x6440,iVar5);
  }
  iVar7 = *(int *)(param_1 + 0x50ac);
  if (iVar7 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1_00;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_00078cf8;
  iVar6 = *(int *)(param_1 + 0x744c);
  piVar10 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar6 != 0) && (*(int *)(iVar6 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar6 + 0x10,iVar8,in_r6,in_r7,in_r8,iVar7,fparam_1,in_f2,in_f3,in_f4,in_f5,
               in_f6,in_f7,in_f8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00078bc4:
    uVar9 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar8 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar7 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar7 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 9);
    uVar9 = *(uint *)(param_1 + 0x31c);
    if ((uVar9 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_00078bc4;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar9 = uVar9 & 0x17000000;
  }
  else {
    uVar9 = uVar9 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar10 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar9 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar10 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar9 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar9 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar10);
      if ((((uVar9 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar9 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar9 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar9 & 4) == 0) {
          uVar9 = uVar9 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar9);
        if (*(char *)(param_1 + 0x759d) == '\0') {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x506;
LAB_00078cc8:
          *(undefined4 *)(param_1 + 0x7574) = uVar3;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
    iVar8 = 0;
    do {
      iVar8 = iVar8 + 1;
      *piVar10 = 0;
      piVar10 = piVar10 + 1;
    } while (iVar8 < 0x13);
  }
LAB_00078cf8:
  (**(code **)(param_1 + 0x4700))
            (*(undefined4 *)(param_1 + 0x4688),
             *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar5 + 0x10));
  *(int *)(param_1 + 0x7444) = iVar5;
  return;
}

/* _glEndQuery_Exec @ 0x78d30 (728 bytes) */
void _glEndQuery_Exec(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if ((-1 < *(short *)(param_1 + 0x4a10)) || (*(int *)(param_1 + 0x7444) == 0)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00078f98;
  }
  if (param_2 != 0x8914) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
    goto LAB_00078f98;
  }
  iVar6 = *(int *)(param_1 + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_00078fc8;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00078e94:
    uVar7 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar6 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    uVar7 = *(uint *)(param_1 + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_00078e94;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar7 = uVar7 & 0x17000000;
  }
  else {
    uVar7 = uVar7 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar7 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar7);
        if (*(char *)(param_1 + 0x759d) == '\0') {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x506;
LAB_00078f98:
          *(undefined4 *)(param_1 + 0x7574) = uVar3;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
    iVar6 = 0;
    do {
      iVar6 = iVar6 + 1;
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
    } while (iVar6 < 0x13);
  }
LAB_00078fc8:
  (**(code **)(param_1 + 0x4704))
            (*(undefined4 *)(param_1 + 0x4688),
             *(undefined4 *)
              ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x7444) + 0x10));
  *(undefined4 *)(param_1 + 0x7444) = 0;
  return;
}

/* _glIsQuery_Exec @ 0x79008 (76 bytes) */
int _glIsQuery_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    uVar1 = _gleIsHashName(param_1 + 0x6440,param_2);
  }
  else {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* _glBeginQuery_Comp @ 0x79054 (84 bytes) */
int _glBeginQuery_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glBeginQuery_ListExec_0011022c,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glEndQuery_Comp @ 0x790a8 (76 bytes) */
int _glEndQuery_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glEndQuery_ListExec_00110228,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glBeginQuery_CompExec @ 0x790f4 (64 bytes) */
void _glBeginQuery_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glBeginQuery_Comp)(param_1,param_2,param_3);
  ((void (*)())_glBeginQuery_Exec)(param_1,param_2,param_3);
  return;
}

/* _glEndQuery_CompExec @ 0x79134 (56 bytes) */
void _glEndQuery_CompExec(param_1, param_2)
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
  
  ((int (*)())_glEndQuery_Comp)(param_1,param_2);
  ((void (*)())_glEndQuery_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glBeginQuery_ListExec @ 0x7916c (44 bytes) */
int _glBeginQuery_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glBeginQuery_Exec)(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glEndQuery_ListExec @ 0x79198 (40 bytes) */
undefined4 _glEndQuery_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glEndQuery_Exec)(param_1,*param_2,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                   fparam_8);
  return 4;
}

/* _glGetQueryiv_Exec @ 0x791c0 (152 bytes) */
void _glGetQueryiv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8914) {
      if (param_3 == 0x8864) {
        uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x468c) + 0xa8);
LAB_00079248:
        *param_4 = uVar1;
        return;
      }
      if (param_3 == 0x8865) {
        if (*(int *)(param_1 + 0x7444) == 0) {
          *param_4 = 0;
          return;
        }
        uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x7444) + 4);
        goto LAB_00079248;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
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

/* _glGetQueryObjectiv_Exec @ 0x79258 (204 bytes) */
void _glGetQueryObjectiv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  int iVar2;
  
  if (((*(short *)(param_1 + 0x4a10) < 0) &&
      (iVar2 = _gleLookupHashObject(param_1 + 0x6440,param_2), iVar2 != 0)) &&
     (*(int *)(param_1 + 0x7444) != iVar2)) {
    if (param_3 - 0x8866U < 2) {
                    
                    
      (**(code **)(param_1 + 0x4810))
                (*(undefined4 *)(param_1 + 0x4688),
                 *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar2 + 0x10),param_3,
                 param_4);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
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

/* _glGetQueryObjectuiv_Exec @ 0x79324 (204 bytes) */
void _glGetQueryObjectuiv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  int iVar2;
  
  if (((*(short *)(param_1 + 0x4a10) < 0) &&
      (iVar2 = _gleLookupHashObject(param_1 + 0x6440,param_2), iVar2 != 0)) &&
     (*(int *)(param_1 + 0x7444) != iVar2)) {
    if (param_3 - 0x8866U < 2) {
                    
                    
      (**(code **)(param_1 + 0x4810))
                (*(undefined4 *)(param_1 + 0x4688),
                 *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar2 + 0x10),param_3,
                 param_4);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
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

