#include "decls.h"

/* _glWindowPos3dv_Comp @ 0xb1c58 (108 bytes) */
int _glWindowPos3dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glWindowPos3_ListExec_001104cc,0xc);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)*param_2;
    pfVar1[1] = (float)param_2[1];
    pfVar1[2] = (float)param_2[2];
  }
  return pfVar1;
}

/* _glWindowPos3dv_CompExec @ 0xb1cc4 (56 bytes) */
void _glWindowPos3dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glWindowPos3dv_Comp)(param_1,param_2);
  _glWindowPos3dv_Exec(param_1,param_2);
  return;
}

/* _glWindowPos2f_Exec @ 0xb1cfc (64 bytes) */
void _glWindowPos2f_Exec(int param_1,double fparam_1,double fparam_2)
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,fparam_1,fparam_2,(double)FLOAT_00108e50);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glWindowPos2f_Comp @ 0xb1d3c (100 bytes) */
float * _glWindowPos2f_Comp(undefined4 param_1,float fparam_1,float fparam_2)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glWindowPos2_ListExec_001104d0,8);
  if (pfVar1 != (float *)0x0) {
    pfVar1[1] = (float)fparam_2;
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _glWindowPos2f_CompExec @ 0xb1da0 (80 bytes) */
void _glWindowPos2f_CompExec(undefined4 param_1,double fparam_1,double fparam_2)
{
  ((float * (*)())_glWindowPos2f_Comp)(param_1,fparam_1,fparam_2);
  ((void (*)())_glWindowPos2f_Exec)(param_1,fparam_1,fparam_2);
  return;
}

/* _glWindowPos2fv_Exec @ 0xb1df0 (72 bytes) */
void _glWindowPos2fv_Exec(param_1, param_2)
  int param_1;
  float *param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,(double)*param_2,(double)param_2[1],(double)FLOAT_00108e50);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glWindowPos2fv_Comp @ 0xb1e38 (88 bytes) */
int _glWindowPos2fv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glWindowPos2_ListExec_001104d0,8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
  }
  return puVar1;
}

/* _glWindowPos2fv_CompExec @ 0xb1e90 (56 bytes) */
void _glWindowPos2fv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glWindowPos2fv_Comp)(param_1,param_2);
  ((void (*)())_glWindowPos2fv_Exec)(param_1,param_2);
  return;
}

/* _glWindowPos3f_Exec @ 0xb1ec8 (40 bytes) */
void _glWindowPos3f_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3)
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,fparam_1,fparam_2,fparam_3);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glWindowPos3f_Comp @ 0xb1ef0 (116 bytes) */
float * _glWindowPos3f_Comp(undefined4 param_1,float fparam_1,float fparam_2,float fparam_3)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glWindowPos3_ListExec_001104cc,0xc);
  if (pfVar1 != (float *)0x0) {
    pfVar1[2] = (float)fparam_3;
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
  }
  return pfVar1;
}

/* _glWindowPos3f_CompExec @ 0xb1f64 (96 bytes) */
void _glWindowPos3f_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  ((float * (*)())_glWindowPos3f_Comp)(param_1,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glWindowPos3f_Exec)(param_1,fparam_1,fparam_2,fparam_3);
  return;
}

/* _glWindowPos3fv_Exec @ 0xb1fc4 (52 bytes) */
void _glWindowPos3fv_Exec(param_1, param_2)
  int param_1;
  float *param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,(double)*param_2,(double)param_2[1],(double)param_2[2]);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glWindowPos3fv_Comp @ 0xb1ff8 (96 bytes) */
int _glWindowPos3fv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glWindowPos3_ListExec_001104cc,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    puVar1[2] = param_2[2];
  }
  return puVar1;
}

/* _glWindowPos3fv_CompExec @ 0xb2058 (56 bytes) */
void _glWindowPos3fv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glWindowPos3fv_Comp)(param_1,param_2);
  ((void (*)())_glWindowPos3fv_Exec)(param_1,param_2);
  return;
}

/* _glWindowPos2i_Exec @ 0xb2090 (148 bytes) */
void _glWindowPos2i_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50);
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos2i_Comp @ 0xb2124 (144 bytes) */
int _glWindowPos2i_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  uint param_3;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glWindowPos2_ListExec_001104d0,8);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glWindowPos2i_CompExec @ 0xb21b4 (64 bytes) */
void _glWindowPos2i_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glWindowPos2i_Comp)(param_1,param_2,param_3);
  ((void (*)())_glWindowPos2i_Exec)(param_1,param_2,param_3);
  return;
}

/* _glWindowPos2iv_Exec @ 0xb21f4 (156 bytes) */
void _glWindowPos2iv_Exec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50);
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos2iv_Comp @ 0xb2290 (148 bytes) */
int _glWindowPos2iv_Comp(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glWindowPos2_ListExec_001104d0,8);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glWindowPos2iv_CompExec @ 0xb2324 (56 bytes) */
void _glWindowPos2iv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glWindowPos2iv_Comp)(param_1,param_2);
  ((void (*)())_glWindowPos2iv_Exec)(param_1,param_2);
  return;
}

/* _glWindowPos3i_Exec @ 0xb235c (160 bytes) */
void _glWindowPos3i_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos3i_Comp @ 0xb23fc (176 bytes) */
int _glWindowPos3i_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glWindowPos3_ListExec_001104cc,0xc);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glWindowPos3i_CompExec @ 0xb24ac (72 bytes) */
void _glWindowPos3i_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glWindowPos3i_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glWindowPos3i_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glWindowPos3iv_Exec @ 0xb24f4 (172 bytes) */
void _glWindowPos3iv_Exec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos3iv_Comp @ 0xb25a0 (180 bytes) */
int _glWindowPos3iv_Comp(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glWindowPos3_ListExec_001104cc,0xc);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glWindowPos3iv_CompExec @ 0xb2654 (56 bytes) */
void _glWindowPos3iv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glWindowPos3iv_Comp)(param_1,param_2);
  ((void (*)())_glWindowPos3iv_Exec)(param_1,param_2);
  return;
}

/* _glWindowPos2s_Exec @ 0xb268c (148 bytes) */
void _glWindowPos2s_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50);
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos2s_Comp @ 0xb2720 (144 bytes) */
int _glWindowPos2s_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  uint param_3;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glWindowPos2_ListExec_001104d0,8);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glWindowPos2s_CompExec @ 0xb27b0 (64 bytes) */
void _glWindowPos2s_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glWindowPos2s_Comp)(param_1,param_2,param_3);
  ((void (*)())_glWindowPos2s_Exec)(param_1,param_2,param_3);
  return;
}

/* _glWindowPos2sv_Exec @ 0xb27f0 (156 bytes) */
void _glWindowPos2sv_Exec(param_1, param_2)
  int param_1;
  short *param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000)
                                            - DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50);
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos2sv_Comp @ 0xb288c (148 bytes) */
int _glWindowPos2sv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glWindowPos2_ListExec_001104d0,8);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glWindowPos2sv_CompExec @ 0xb2920 (56 bytes) */
void _glWindowPos2sv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glWindowPos2sv_Comp)(param_1,param_2);
  ((void (*)())_glWindowPos2sv_Exec)(param_1,param_2);
  return;
}

/* _glWindowPos3s_Exec @ 0xb2958 (160 bytes) */
void _glWindowPos3s_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos3s_Comp @ 0xb29f8 (176 bytes) */
int _glWindowPos3s_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glWindowPos3_ListExec_001104cc,0xc);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glWindowPos3s_CompExec @ 0xb2aa8 (72 bytes) */
void _glWindowPos3s_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glWindowPos3s_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glWindowPos3s_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glWindowPos3sv_Exec @ 0xb2af0 (172 bytes) */
void _glWindowPos3sv_Exec(param_1, param_2)
  int param_1;
  short *param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000)
                                            - DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos3sv_Comp @ 0xb2b9c (180 bytes) */
int _glWindowPos3sv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glWindowPos3_ListExec_001104cc,0xc);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glWindowPos3sv_CompExec @ 0xb2c50 (56 bytes) */
void _glWindowPos3sv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glWindowPos3sv_Comp)(param_1,param_2);
  ((void (*)())_glWindowPos3sv_Exec)(param_1,param_2);
  return;
}

/* _glCombinerParameterfvNV_Exec @ 0xb2c88 (568 bytes) */
void _glCombinerParameterfvNV_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  float *param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x854e) {
      fVar1 = *param_3;
      if ((1.0 <= fVar1) &&
         (fVar1 <= (float)((double)CONCAT44(0x43300000,
                                            *(uint *)(*(int *)(param_1 + 0x468c) + 0x98) ^
                                            0x80000000) - DOUBLE_00108d58))) {
        *(int *)(param_1 + 0x41fc) = (int)fVar1;
        goto LAB_000b2eb0;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar6 = 0x501;
    }
    else {
      if (param_2 < 0x854f) {
        if (param_2 - 0x852a < 2) {
          fVar1 = *param_3;
          fVar2 = param_3[3];
          fVar3 = param_3[1];
          fVar4 = param_3[2];
          fVar5 = FLOAT_00108e50;
          if ((0.0 <= fVar1) && (fVar5 = fVar1, 1.0 < fVar1)) {
            fVar5 = FLOAT_00108e54;
          }
          fVar1 = FLOAT_00108e50;
          if ((0.0 <= fVar3) && (fVar1 = fVar3, 1.0 < fVar3)) {
            fVar1 = FLOAT_00108e54;
          }
          fVar3 = FLOAT_00108e50;
          if ((0.0 <= fVar4) && (fVar3 = fVar4, 1.0 < fVar4)) {
            fVar3 = FLOAT_00108e54;
          }
          fVar4 = FLOAT_00108e50;
          if ((0.0 <= fVar2) && (fVar4 = fVar2, 1.0 < fVar2)) {
            fVar4 = FLOAT_00108e54;
          }
          iVar7 = (param_2 - 0x852a) * 0x10 + param_1;
          *(float *)(iVar7 + 0x420c) = fVar4;
          *(float *)(iVar7 + 0x4200) = fVar5;
          *(float *)(iVar7 + 0x4204) = fVar1;
          *(float *)(iVar7 + 0x4208) = fVar3;
LAB_000b2eb0:
          *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x1000000;
          return;
        }
      }
      else if (param_2 == 0x854f) {
        *(bool *)(param_1 + 0x4620) = *param_3 != 0.0;
        goto LAB_000b2eb0;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar6 = 0x500;
    }
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar6 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar6;
  return;
}

/* _glCombinerStageParameterfvNV_Exec @ 0xb2ec0 (404 bytes) */
void _glCombinerStageParameterfvNV_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  float *param_4;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar7 = param_2 + -0x8550;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (((-1 < iVar7) && (iVar7 < *(int *)(*(int *)(param_1 + 0x468c) + 0x98))) &&
       (param_3 - 0x852aU < 2)) {
      fVar1 = *param_4;
      fVar2 = param_4[3];
      fVar3 = param_4[2];
      fVar4 = param_4[1];
      fVar5 = FLOAT_00108e50;
      if ((0.0 <= fVar1) && (fVar5 = fVar1, 1.0 < fVar1)) {
        fVar5 = FLOAT_00108e54;
      }
      fVar1 = FLOAT_00108e50;
      if ((0.0 <= fVar4) && (fVar1 = fVar4, 1.0 < fVar4)) {
        fVar1 = FLOAT_00108e54;
      }
      fVar4 = FLOAT_00108e50;
      if ((0.0 <= fVar3) && (fVar4 = fVar3, 1.0 < fVar3)) {
        fVar4 = FLOAT_00108e54;
      }
      fVar3 = FLOAT_00108e50;
      if ((0.0 <= fVar2) && (fVar3 = fVar2, 1.0 < fVar2)) {
        fVar3 = FLOAT_00108e54;
      }
      iVar7 = (iVar7 * 8 + (param_3 - 0x852aU)) * 0x10 + param_1;
      *(float *)(iVar7 + 0x428c) = fVar3;
      *(float *)(iVar7 + 0x4280) = fVar5;
      *(float *)(iVar7 + 0x4284) = fVar1;
      *(float *)(iVar7 + 0x4288) = fVar4;
      *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x1000000;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar6 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar6 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar6;
  return;
}

/* _glCombinerParameterfNV_Exec @ 0xb3054 (80 bytes) */
void _glCombinerParameterfNV_Exec(int param_1,int param_2,float fparam_1)
{
  float fStack00000020;
  
  fStack00000020 = (float)fparam_1;
  if (param_2 - 0x854eU < 2) {
    ((void (*)())_glCombinerParameterfvNV_Exec)(param_1,param_2,&STACKARG(0x20));
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x500;
  }
  return;
}

/* _glCombinerParameterivNV_Exec @ 0xb30a4 (592 bytes) */
void _glCombinerParameterivNV_Exec(int param_1,uint param_2,uint *param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x854e) {
      uVar8 = *param_3;
      if ((0 < (int)uVar8) && ((int)uVar8 <= *(int *)(*(int *)(param_1 + 0x468c) + 0x98))) {
        *(uint *)(param_1 + 0x41fc) = uVar8;
        goto LAB_000b32e4;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar6 = 0x501;
    }
    else {
      if (param_2 < 0x854f) {
        if (param_2 - 0x852a < 2) {
          fVar1 = (float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58);
          fVar2 = (float)((double)CONCAT44(0x43300000,param_3[1] ^ 0x80000000) - DOUBLE_00108d58);
          fVar3 = (float)((double)CONCAT44(0x43300000,param_3[2] ^ 0x80000000) - DOUBLE_00108d58);
          fVar4 = (float)((double)CONCAT44(0x43300000,param_3[3] ^ 0x80000000) - DOUBLE_00108d58);
          fVar5 = FLOAT_00108e50;
          if ((0.0 <= fVar1) && (fVar5 = fVar1, 1.0 < fVar1)) {
            fVar5 = FLOAT_00108e54;
          }
          fVar1 = FLOAT_00108e50;
          if ((0.0 <= fVar2) && (fVar1 = fVar2, 1.0 < fVar2)) {
            fVar1 = FLOAT_00108e54;
          }
          fVar2 = FLOAT_00108e50;
          if ((0.0 <= fVar3) && (fVar2 = fVar3, 1.0 < fVar3)) {
            fVar2 = FLOAT_00108e54;
          }
          fVar3 = FLOAT_00108e50;
          if ((0.0 <= fVar4) && (fVar3 = fVar4, 1.0 < fVar4)) {
            fVar3 = FLOAT_00108e54;
          }
          iVar7 = (param_2 - 0x852a) * 0x10 + param_1;
          *(float *)(iVar7 + 0x420c) = fVar3;
          *(float *)(iVar7 + 0x4200) = fVar5;
          *(float *)(iVar7 + 0x4204) = fVar1;
          *(float *)(iVar7 + 0x4208) = fVar2;
LAB_000b32e4:
          *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x1000000;
          return;
        }
      }
      else if (param_2 == 0x854f) {
        *(char *)(param_1 + 0x4620) = '\x01' - (*param_3 == 0);
        goto LAB_000b32e4;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar6 = 0x500;
    }
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar6 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar6;
  return;
}

/* _glCombinerParameteriNV_Exec @ 0xb32f4 (80 bytes) */
void _glCombinerParameteriNV_Exec(int param_1,int param_2,undefined4 param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10)
{
  undefined4 uStack00000020;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  
  if (param_2 - 0x854eU < 2) {
    uStack00000020 = param_3;
    ((void (*)())_glCombinerParameterivNV_Exec)(param_1,param_2,&STACKARG(0x20),fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
               fparam_6,fparam_7,fparam_8,in_stack_ffffffb8,in_stack_ffffffc0);
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x500;
  }
  return;
}

/* _glCombinerInputNV_Exec @ 0xb3344 (336 bytes) */
void _glCombinerInputNV_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
  int param_6;
  uint param_7;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_2 + -0x8550;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((-1 < iVar4) && (iVar4 < *(int *)(*(int *)(param_1 + 0x468c) + 0x98))) {
      bVar1 = param_3 == 0x1906;
      if (bVar1) {
        iVar3 = 0;
      }
      else {
        iVar3 = 1;
        if (param_3 != 0x1907) goto LAB_000b3378;
      }
      if (param_4 - 0x8523U < 4) {
        if (((param_5 < 0x84c0) ||
            (*(ushort *)(*(int *)(param_1 + 0x468c) + 0xb4) + 0x84c0 <= param_5)) &&
           (param_5 != 0xb60)) {
          if (param_5 < 0xb61) {
            if (param_5 == 0) goto LAB_000b33fc;
          }
          else if (param_5 - 0x852a < 6) goto LAB_000b33fc;
        }
        else {
LAB_000b33fc:
          if (param_6 - 0x8536U < 8) {
            if (param_7 == 0x1906) {
              bVar1 = param_5 == 0xb60;
joined_r0x000b3430:
              if (!bVar1) {
                iVar4 = (iVar4 * 0x10 + iVar3 * 6 + (param_4 - 0x8523U)) * 8 + param_1;
                *(short *)(iVar4 + 0x4222) = (short)param_7;
                *(short *)(iVar4 + 0x4220) = (short)param_5;
                *(short *)(iVar4 + 0x4224) = (short)param_6;
                *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x1000000;
                return;
              }
              goto LAB_000b3448;
            }
            if (param_7 < 0x1907) {
              if (param_7 == 0x1905) {
                bVar1 = param_3 == 0x1907;
                goto joined_r0x000b3430;
              }
            }
            else if (param_7 == 0x1907) goto joined_r0x000b3430;
          }
        }
      }
    }
LAB_000b3378:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x500;
  }
  else {
LAB_000b3448:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glCombinerOutputNV_Exec @ 0xb3494 (504 bytes) */
void _glCombinerOutputNV_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
  int param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_2 + -0x8550;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((-1 < iVar2) && (iVar4 = *(int *)(param_1 + 0x468c), iVar2 < *(int *)(iVar4 + 0x98))) {
      if (param_3 == 0x1906) {
        iVar3 = 0;
        if (((char)param_9 != '\0') || ((char)param_10 != '\0')) goto LAB_000b362c;
      }
      else {
        iVar3 = 1;
        if (param_3 != 0x1907) goto LAB_000b35d0;
      }
      if ((param_8 == 0) || (param_8 == 0x8541)) {
        if (param_7 == 0x853e) {
LAB_000b354c:
          if (((((0x84bf < param_4) && (param_4 < *(ushort *)(iVar4 + 0xb4) + 0x84c0)) ||
               (param_4 - 0x852c < 5)) &&
              (((0x84bf < param_5 && (param_5 < *(ushort *)(iVar4 + 0xb4) + 0x84c0)) ||
               (param_5 - 0x852c < 5)))) &&
             (((0x84bf < param_6 && (param_6 < *(ushort *)(iVar4 + 0xb4) + 0x84c0)) ||
              (param_6 - 0x852c < 5)))) {
            if (((param_6 != param_4) || (param_6 == 0x8530)) &&
               (((param_6 != param_5 || (param_6 == 0x8530)) &&
                ((param_4 != param_5 || (param_5 == 0x8530)))))) {
              iVar2 = iVar2 * 0x80 + iVar3 * 0x30 + param_1;
              *(undefined1 *)(iVar2 + 0x4242) = (undefined1)param_11;
              *(short *)(iVar2 + 0x4248) = (short)param_4;
              *(short *)(iVar2 + 0x424a) = (short)param_5;
              *(short *)(iVar2 + 0x424c) = (short)param_6;
              *(short *)(iVar2 + 0x4244) = (short)param_7;
              *(short *)(iVar2 + 0x4246) = (short)param_8;
              *(char *)(iVar2 + 0x4240) = (char)param_9;
              *(char *)(iVar2 + 0x4241) = (char)param_10;
              *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x1000000;
              return;
            }
            goto LAB_000b362c;
          }
        }
        else if (param_7 < 0x853f) {
          if (param_7 == 0) goto LAB_000b354c;
        }
        else if (param_7 < 0x8541) {
          if (param_8 != 0) goto LAB_000b362c;
          goto LAB_000b354c;
        }
      }
    }
LAB_000b35d0:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  else {
LAB_000b362c:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glFinalCombinerInputNV_Exec @ 0xb368c (336 bytes) */
void _glFinalCombinerInputNV_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
  uint param_5;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_2 - 0x8523;
  if (-1 < *(short *)(param_1 + 0x4a10)) goto LAB_000b37a0;
  if (6 < uVar3) goto LAB_000b36a8;
  if ((param_3 < 0x84c0) || (*(ushort *)(*(int *)(param_1 + 0x468c) + 0xb4) + 0x84c0 <= param_3)) {
    if (param_3 < 0x8530) {
      if (((0x8529 < param_3) || (param_3 == 0)) || (param_3 == 0xb60)) goto LAB_000b3714;
    }
    else if (param_3 - 0x8531 < 2) goto LAB_000b3714;
  }
  else {
LAB_000b3714:
    if (((3 < (int)uVar3) && (param_3 - 0x8531 < 2)) || ((uVar3 == 0 && (param_3 == 0x8532)))) {
LAB_000b37a0:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x502;
      goto LAB_000b36b8;
    }
    if (param_4 - 0x8536U < 2) {
      if (param_5 == 0x1906) {
        if (1 < param_3 - 0x8531) {
LAB_000b37b4:
          iVar2 = uVar3 * 8 + param_1;
          *(short *)(iVar2 + 0x4626) = (short)param_5;
          *(short *)(iVar2 + 0x4624) = (short)param_3;
          *(short *)(iVar2 + 0x4628) = (short)param_4;
          *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x1000000;
          return;
        }
        goto LAB_000b37a0;
      }
      if (param_5 < 0x1907) {
        if (param_5 == 0x1905) {
          if (uVar3 == 6) goto LAB_000b37b4;
          goto LAB_000b37a0;
        }
      }
      else if (param_5 == 0x1907) {
        if (uVar3 != 6) goto LAB_000b37b4;
        goto LAB_000b37a0;
      }
    }
  }
LAB_000b36a8:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x500;
LAB_000b36b8:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetCombinerStageParameterfvNV_Exec @ 0xb37dc (124 bytes) */
void _glGetCombinerStageParameterfvNV_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  
  iVar1 = param_2 + -0x8550;
  if (((-1 < iVar1) && (iVar1 < *(int *)(*(int *)(param_1 + 0x468c) + 0x98))) &&
     (param_3 - 0x852aU < 2)) {
    iVar1 = (iVar1 * 8 + (param_3 - 0x852aU)) * 0x10 + param_1;
    *param_4 = *(undefined4 *)(iVar1 + 0x4280);
    param_4[1] = *(undefined4 *)(iVar1 + 0x4284);
    param_4[2] = *(undefined4 *)(iVar1 + 0x4288);
    param_4[3] = *(undefined4 *)(iVar1 + 0x428c);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x500;
  return;
}

/* _glGetCombinerInputParameterfvNV_Exec @ 0xb3858 (292 bytes) */
void _glGetCombinerInputParameterfvNV_Exec(int param_1,int param_2,int param_3,int param_4,uint param_5,float *param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2 + -0x8550;
  uVar3 = param_4 - 0x8523;
  if ((-1 < iVar2) && (iVar2 < *(int *)(*(int *)(param_1 + 0x468c) + 0x98))) {
    if (param_3 == 0x1906) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
      if (param_3 != 0x1907) goto LAB_000b3964;
    }
    if (uVar3 < 4) {
      if (param_5 == 0x8543) {
        uVar3 = (uint)*(ushort *)((iVar2 * 0x10 + iVar1 * 6 + uVar3) * 8 + param_1 + 0x4224);
LAB_000b391c:
        *param_6 = GH_U2F((unsigned int)((uVar3 | 0x4b000000))) - 8388608.0;
        return;
      }
      if (param_5 < 0x8544) {
        if (param_5 == 0x8542) {
          uVar3 = (uint)*(ushort *)((iVar2 * 0x10 + iVar1 * 6 + uVar3) * 8 + param_1 + 0x4220);
          goto LAB_000b391c;
        }
      }
      else if (param_5 == 0x8544) {
        uVar3 = (uint)*(ushort *)((iVar2 * 0x10 + iVar1 * 6 + uVar3) * 8 + param_1 + 0x4222);
        goto LAB_000b391c;
      }
    }
  }
LAB_000b3964:
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x500;
    return;
  }
  return;
}

/* _glGetCombinerInputParameterivNV_Exec @ 0xb397c (260 bytes) */
void _glGetCombinerInputParameterivNV_Exec(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
  uint *param_6;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2 + -0x8550;
  uVar3 = param_4 - 0x8523;
  if ((-1 < iVar2) && (iVar2 < *(int *)(*(int *)(param_1 + 0x468c) + 0x98))) {
    if (param_3 == 0x1906) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
      if (param_3 != 0x1907) goto LAB_000b3a68;
    }
    if (uVar3 < 4) {
      if (param_5 == 0x8543) {
        uVar3 = (uint)*(ushort *)((iVar2 * 0x10 + iVar1 * 6 + uVar3) * 8 + param_1 + 0x4224);
LAB_000b3a40:
        *param_6 = uVar3;
        return;
      }
      if (param_5 < 0x8544) {
        if (param_5 == 0x8542) {
          uVar3 = (uint)*(ushort *)((iVar2 * 0x10 + iVar1 * 6 + uVar3) * 8 + param_1 + 0x4220);
          goto LAB_000b3a40;
        }
      }
      else if (param_5 == 0x8544) {
        uVar3 = (uint)*(ushort *)((iVar2 * 0x10 + iVar1 * 6 + uVar3) * 8 + param_1 + 0x4222);
        goto LAB_000b3a40;
      }
    }
  }
LAB_000b3a68:
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x500;
    return;
  }
  return;
}

/* FUN_000b3a84 @ 0xb3a84 (364 bytes) */
void FUN_000b3a84(int param_1,int param_2,int param_3,undefined4 param_4,float *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = param_2 + 0x7ab0;
  if ((-1 < iVar1) && (iVar1 < *(int *)(*(int *)(param_1 + 0x468c) + 0x98))) {
    if (param_3 == 0x1906) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
      if (param_3 != 0x1907) goto switchD_000b3af0_default;
    }
    switch(param_4) {
    case 0x8545:
      uVar2 = (uint)*(byte *)(iVar1 * 0x80 + iVar3 * 0x30 + param_1 + 0x4240);
      break;
    case 0x8546:
      uVar2 = (uint)*(byte *)(iVar1 * 0x80 + iVar3 * 0x30 + param_1 + 0x4241);
      break;
    case 0x8547:
      uVar2 = (uint)*(byte *)(iVar1 * 0x80 + iVar3 * 0x30 + param_1 + 0x4242);
      break;
    case 0x8548:
      uVar2 = (uint)*(ushort *)(iVar1 * 0x80 + iVar3 * 0x30 + param_1 + 0x4244);
      break;
    case 0x8549:
      uVar2 = (uint)*(ushort *)(iVar1 * 0x80 + iVar3 * 0x30 + param_1 + 0x4246);
      break;
    case 0x854a:
      uVar2 = (uint)*(ushort *)(iVar1 * 0x80 + iVar3 * 0x30 + param_1 + 0x4248);
      break;
    case 0x854b:
      uVar2 = (uint)*(ushort *)(iVar1 * 0x80 + iVar3 * 0x30 + param_1 + 0x424a);
      break;
    case 0x854c:
      uVar2 = (uint)*(ushort *)(iVar1 * 0x80 + iVar3 * 0x30 + param_1 + 0x424c);
      break;
    default:
      goto switchD_000b3af0_default;
    }
    *param_5 = GH_U2F((unsigned int)((uVar2 | 0x4b000000))) - 8388608.0;
    return;
  }
switchD_000b3af0_default:
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x500;
    return;
  }
  return;
}

/* FUN_000b3c14 @ 0xb3c14 (332 bytes) */
void FUN_000b3c14(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  uint *param_5;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_2 + 0x7ab0;
  if ((-1 < iVar2) && (iVar2 < *(int *)(*(int *)(param_1 + 0x468c) + 0x98))) {
    if (param_3 == 0x1906) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
      if (param_3 != 0x1907) goto switchD_000b3c80_default;
    }
    switch(param_4) {
    case 0x8545:
      uVar1 = (uint)*(byte *)(iVar2 * 0x80 + iVar3 * 0x30 + param_1 + 0x4240);
      break;
    case 0x8546:
      uVar1 = (uint)*(byte *)(iVar2 * 0x80 + iVar3 * 0x30 + param_1 + 0x4241);
      break;
    case 0x8547:
      uVar1 = (uint)*(byte *)(iVar2 * 0x80 + iVar3 * 0x30 + param_1 + 0x4242);
      break;
    case 0x8548:
      uVar1 = (uint)*(ushort *)(iVar2 * 0x80 + iVar3 * 0x30 + param_1 + 0x4244);
      break;
    case 0x8549:
      uVar1 = (uint)*(ushort *)(iVar2 * 0x80 + iVar3 * 0x30 + param_1 + 0x4246);
      break;
    case 0x854a:
      uVar1 = (uint)*(ushort *)(iVar2 * 0x80 + iVar3 * 0x30 + param_1 + 0x4248);
      break;
    case 0x854b:
      uVar1 = (uint)*(ushort *)(iVar2 * 0x80 + iVar3 * 0x30 + param_1 + 0x424a);
      break;
    case 0x854c:
      uVar1 = (uint)*(ushort *)(iVar2 * 0x80 + iVar3 * 0x30 + param_1 + 0x424c);
      break;
    default:
      goto switchD_000b3c80_default;
    }
    *param_5 = uVar1;
    return;
  }
switchD_000b3c80_default:
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x500;
    return;
  }
  return;
}

/* _glGetFinalCombinerInputParameterfvNV_Exec @ 0xb3d80 (188 bytes) */
void _glGetFinalCombinerInputParameterfvNV_Exec(int param_1,int param_2,uint param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  uint uVar1;
  
  uVar1 = param_2 - 0x8523;
  if (6 < uVar1) goto LAB_000b3e24;
  if (param_3 == 0x8543) {
    uVar1 = (uint)*(ushort *)(uVar1 * 8 + param_1 + 0x4628);
  }
  else if (param_3 < 0x8544) {
    if (param_3 != 0x8542) {
LAB_000b3e24:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x500;
        return;
      }
      return;
    }
    uVar1 = (uint)*(ushort *)(uVar1 * 8 + param_1 + 0x4624);
  }
  else {
    if (param_3 != 0x8544) goto LAB_000b3e24;
    uVar1 = (uint)*(ushort *)(uVar1 * 8 + param_1 + 0x4626);
  }
  *param_4 = GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0;
  return;
}

/* _glGetFinalCombinerInputParameterivNV_Exec @ 0xb3e3c (156 bytes) */
void _glGetFinalCombinerInputParameterivNV_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  uint *param_4;
{
  uint uVar1;
  
  uVar1 = param_2 - 0x8523;
  if (6 < uVar1) goto LAB_000b3ec0;
  if (param_3 == 0x8543) {
    uVar1 = (uint)*(ushort *)(uVar1 * 8 + param_1 + 0x4628);
  }
  else if (param_3 < 0x8544) {
    if (param_3 != 0x8542) {
LAB_000b3ec0:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x500;
        return;
      }
      return;
    }
    uVar1 = (uint)*(ushort *)(uVar1 * 8 + param_1 + 0x4624);
  }
  else {
    if (param_3 != 0x8544) goto LAB_000b3ec0;
    uVar1 = (uint)*(ushort *)(uVar1 * 8 + param_1 + 0x4626);
  }
  *param_4 = uVar1;
  return;
}

/* _glCombinerParameterfvNV_Comp @ 0xb3ed8 (140 bytes) */
int _glCombinerParameterfvNV_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glCombinerParameterfvNV_ListExec_001104f0,0x14);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2;
    if (param_2 - 0x852aU < 2) {
      piVar1[1] = *param_3;
      piVar1[2] = param_3[1];
      piVar1[3] = param_3[2];
      piVar1[4] = param_3[3];
    }
    else {
      piVar1[1] = *param_3;
    }
  }
  return piVar1;
}

/* _glCombinerStageParameterfvNV_Comp @ 0xb3f64 (148 bytes) */
int _glCombinerStageParameterfvNV_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glCombinerStageParameterfvNV_ListExec_001104ec,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    if (param_3 - 0x852aU < 2) {
      puVar1[2] = *param_4;
      puVar1[3] = param_4[1];
      puVar1[4] = param_4[2];
      puVar1[5] = param_4[3];
    }
    else {
      puVar1[2] = *param_4;
    }
  }
  return puVar1;
}

/* _glCombinerParameterfNV_Comp @ 0xb3ff8 (92 bytes) */
undefined4 * _glCombinerParameterfNV_Comp(undefined4 param_1,undefined4 param_2,float fparam_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glCombinerParameterfNV_ListExec_001104e8,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = (float)fparam_1;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glCombinerParameterivNV_Comp @ 0xb4054 (140 bytes) */
int _glCombinerParameterivNV_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glCombinerParameterivNV_ListExec_001104e4,0x14);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2;
    if (param_2 - 0x852aU < 2) {
      piVar1[1] = *param_3;
      piVar1[2] = param_3[1];
      piVar1[3] = param_3[2];
      piVar1[4] = param_3[3];
    }
    else {
      piVar1[1] = *param_3;
    }
  }
  return piVar1;
}

/* _glCombinerParameteriNV_Comp @ 0xb40e0 (84 bytes) */
int _glCombinerParameteriNV_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glCombinerParameteriNV_ListExec_001104e0,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glCombinerInputNV_Comp @ 0xb4134 (116 bytes) */
int _glCombinerInputNV_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glCombinerInputNV_ListExec_001104dc,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[5] = param_7;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = param_5;
    puVar1[4] = param_6;
  }
  return puVar1;
}

/* _glCombinerOutputNV_Comp @ 0xb41a8 (148 bytes) */
int _glCombinerOutputNV_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  uint param_9;
  uint param_10;
  uint param_11;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glCombinerOutputNV_ListExec_001104d8,0x28);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[9] = param_11 & 0xff;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = param_5;
    puVar1[4] = param_6;
    puVar1[5] = param_7;
    puVar1[6] = param_8;
    puVar1[7] = param_9 & 0xff;
    puVar1[8] = param_10 & 0xff;
  }
  return puVar1;
}

