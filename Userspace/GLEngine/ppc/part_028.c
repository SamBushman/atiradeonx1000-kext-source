#include "decls.h"

/* _glTexCoord3d_Exec @ 0x936a0 (48 bytes) */
void _glTexCoord3d_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3)
{
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  *(float *)(param_1 + 0x120) = (float)fparam_1;
  *(float *)(param_1 + 0x124) = (float)fparam_2;
  *(float *)(param_1 + 0x128) = (float)fparam_3;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  return;
}

/* _glTexCoord3d_Comp @ 0x936d0 (128 bytes) */
float * _glTexCoord3d_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord3_ListExec_001103b8,0xc);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
  }
  return pfVar1;
}

/* _glTexCoord3d_CompExec @ 0x93750 (96 bytes) */
void _glTexCoord3d_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  ((float * (*)())_glTexCoord3d_Comp)(param_1,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glTexCoord3d_Exec)(param_1,fparam_1,fparam_2,fparam_3);
  return;
}

/* _glTexCoord3dv_Exec @ 0x937b0 (60 bytes) */
int _glTexCoord3dv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar1 = *param_2;
  dVar2 = param_2[1];
  *(float *)(param_1 + 0x128) = (float)param_2[2];
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  *(float *)(param_1 + 0x120) = (float)dVar1;
  *(float *)(param_1 + 0x124) = (float)dVar2;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  return;
}

/* _glTexCoord3dv_Comp @ 0x937ec (108 bytes) */
int _glTexCoord3dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord3_ListExec_001103b8,0xc);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)*param_2;
    pfVar1[1] = (float)param_2[1];
    pfVar1[2] = (float)param_2[2];
  }
  return pfVar1;
}

/* _glTexCoord3dv_CompExec @ 0x93858 (56 bytes) */
int _glTexCoord3dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord3dv_Comp)(param_1,param_2);
  ((int (*)())_glTexCoord3dv_Exec)(param_1,param_2);
  return;
}

/* _glTexCoord4d_Exec @ 0x93890 (48 bytes) */
void _glTexCoord4d_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  *(float *)(param_1 + 0x120) = (float)fparam_1;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  *(float *)(param_1 + 0x124) = (float)fparam_2;
  *(float *)(param_1 + 0x128) = (float)fparam_3;
  *(float *)(param_1 + 300) = (float)fparam_4;
  return;
}

/* _glTexCoord4d_Comp @ 0x938c0 (108 bytes) */
void _glTexCoord4d_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord4_ListExec_001103b4,0x10);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
    pfVar1[3] = (float)fparam_4;
  }
  FUN_00008b68();
  return;
}

/* _glTexCoord4d_CompExec @ 0x9392c (96 bytes) */
void _glTexCoord4d_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((void (*)())_glTexCoord4d_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glTexCoord4d_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glTexCoord4dv_Exec @ 0x9398c (64 bytes) */
int _glTexCoord4dv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar1 = *param_2;
  dVar3 = param_2[1];
  dVar2 = param_2[2];
  *(float *)(param_1 + 300) = (float)param_2[3];
  *(float *)(param_1 + 0x120) = (float)dVar1;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  *(float *)(param_1 + 0x124) = (float)dVar3;
  *(float *)(param_1 + 0x128) = (float)dVar2;
  return;
}

/* _glTexCoord4dv_Comp @ 0x939cc (120 bytes) */
int _glTexCoord4dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord4_ListExec_001103b4,0x10);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)*param_2;
    pfVar1[1] = (float)param_2[1];
    pfVar1[2] = (float)param_2[2];
    pfVar1[3] = (float)param_2[3];
  }
  return pfVar1;
}

/* _glTexCoord4dv_CompExec @ 0x93a44 (56 bytes) */
int _glTexCoord4dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord4dv_Comp)(param_1,param_2);
  ((int (*)())_glTexCoord4dv_Exec)(param_1,param_2);
  return;
}

/* _glTexCoord1f_Exec @ 0x93a7c (28 bytes) */
void _glTexCoord1f_Exec(int param_1,float fparam_1)
{
  *(float *)(param_1 + 0x120) = (float)fparam_1;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x20);
  return;
}

/* _glTexCoord1f_Comp @ 0x93a98 (84 bytes) */
float * _glTexCoord1f_Comp(undefined4 param_1,double fparam_1)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord1_ListExec_001103c0,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _glTexCoord1f_CompExec @ 0x93aec (64 bytes) */
void _glTexCoord1f_CompExec(undefined4 param_1,double fparam_1)
{
  ((float * (*)())_glTexCoord1f_Comp)(param_1,fparam_1);
  ((void (*)())_glTexCoord1f_Exec)(param_1,fparam_1);
  return;
}

/* _glTexCoord1fv_Exec @ 0x93b2c (32 bytes) */
int _glTexCoord1fv_Exec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 0x120) = *param_2;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x20);
  return;
}

/* _glTexCoord1fv_Comp @ 0x93b4c (80 bytes) */
int _glTexCoord1fv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glTexCoord1_ListExec_001103c0,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
  }
  return puVar1;
}

/* _glTexCoord1fv_CompExec @ 0x93b9c (56 bytes) */
int _glTexCoord1fv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord1fv_Comp)(param_1,param_2);
  ((int (*)())_glTexCoord1fv_Exec)(param_1,param_2);
  return;
}

/* _glTexCoord2f_CompExec @ 0x93bd4 (80 bytes) */
void _glTexCoord2f_CompExec(undefined4 param_1,double fparam_1,double fparam_2)
{
  ((float * (*)())_glTexCoord2f_Comp)(param_1,fparam_1,fparam_2);
  ((void (*)())_glTexCoord2f_Exec)(param_1,fparam_1,fparam_2);
  return;
}

/* _glTexCoord2fv_Comp @ 0x93c24 (88 bytes) */
int _glTexCoord2fv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glTexCoord2_ListExec_001103bc,8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
  }
  return puVar1;
}

/* _glTexCoord2fv_CompExec @ 0x93c7c (56 bytes) */
int _glTexCoord2fv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord2fv_Comp)(param_1,param_2);
  _glTexCoord2fv_Exec(param_1,param_2);
  return;
}

/* _glTexCoord3f_Comp @ 0x93cb4 (116 bytes) */
float * _glTexCoord3f_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord3_ListExec_001103b8,0xc);
  if (pfVar1 != (float *)0x0) {
    pfVar1[2] = (float)fparam_3;
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
  }
  return pfVar1;
}

/* _glTexCoord3f_CompExec @ 0x93d28 (96 bytes) */
void _glTexCoord3f_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  ((float * (*)())_glTexCoord3f_Comp)(param_1,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glTexCoord3f_Exec)(param_1,fparam_1,fparam_2,fparam_3);
  return;
}

/* _glTexCoord3fv_Exec @ 0x93d88 (48 bytes) */
int _glTexCoord3fv_Exec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = param_2[2];
  uVar2 = *param_2;
  uVar3 = param_2[1];
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  *(undefined4 *)(param_1 + 0x120) = uVar2;
  *(undefined4 *)(param_1 + 0x124) = uVar3;
  *(undefined4 *)(param_1 + 0x128) = uVar1;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  return;
}

/* _glTexCoord3fv_Comp @ 0x93db8 (96 bytes) */
int _glTexCoord3fv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glTexCoord3_ListExec_001103b8,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    puVar1[2] = param_2[2];
  }
  return puVar1;
}

/* _glTexCoord3fv_CompExec @ 0x93e18 (56 bytes) */
int _glTexCoord3fv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord3fv_Comp)(param_1,param_2);
  ((int (*)())_glTexCoord3fv_Exec)(param_1,param_2);
  return;
}

/* _glTexCoord4f_Exec @ 0x93e50 (32 bytes) */
void _glTexCoord4f_Exec(int param_1,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  *(float *)(param_1 + 0x120) = (float)fparam_1;
  *(float *)(param_1 + 0x124) = (float)fparam_2;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  *(float *)(param_1 + 0x128) = (float)fparam_3;
  *(float *)(param_1 + 300) = (float)fparam_4;
  return;
}

/* _glTexCoord4f_Comp @ 0x93e70 (92 bytes) */
void _glTexCoord4f_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord4_ListExec_001103b4,0x10);
  if (pfVar1 != (float *)0x0) {
    pfVar1[3] = (float)fparam_4;
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
  }
  FUN_00008b68();
  return;
}

/* _glTexCoord4f_CompExec @ 0x93ecc (96 bytes) */
void _glTexCoord4f_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((void (*)())_glTexCoord4f_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glTexCoord4f_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glTexCoord4fv_Exec @ 0x93f2c (48 bytes) */
int _glTexCoord4fv_Exec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = param_2[3];
  uVar2 = *param_2;
  uVar3 = param_2[1];
  uVar4 = param_2[2];
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  *(undefined4 *)(param_1 + 0x120) = uVar2;
  *(undefined4 *)(param_1 + 0x124) = uVar3;
  *(undefined4 *)(param_1 + 0x128) = uVar4;
  *(undefined4 *)(param_1 + 300) = uVar1;
  return;
}

/* _glTexCoord4fv_Comp @ 0x93f5c (104 bytes) */
int _glTexCoord4fv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glTexCoord4_ListExec_001103b4,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    puVar1[2] = param_2[2];
    puVar1[3] = param_2[3];
  }
  return puVar1;
}

/* _glTexCoord4fv_CompExec @ 0x93fc4 (56 bytes) */
int _glTexCoord4fv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord4fv_Comp)(param_1,param_2);
  ((int (*)())_glTexCoord4fv_Exec)(param_1,param_2);
  return;
}

/* _glTexCoord1i_Exec @ 0x93ffc (80 bytes) */
int _glTexCoord1i_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  double dVar1;
  
  dVar1 = (double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x20);
  *(float *)(param_1 + 0x120) = (float)dVar1;
  return;
}

/* _glTexCoord1i_Comp @ 0x9404c (112 bytes) */
int _glTexCoord1i_Comp(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord1_ListExec_001103c0,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
  }
  return pfVar1;
}

/* _glTexCoord1i_CompExec @ 0x940bc (56 bytes) */
int _glTexCoord1i_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord1i_Comp)(param_1,param_2);
  ((int (*)())_glTexCoord1i_Exec)(param_1,param_2);
  return;
}

/* _glTexCoord1iv_Exec @ 0x940f4 (84 bytes) */
int _glTexCoord1iv_Exec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  
  dVar1 = (double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x20);
  *(float *)(param_1 + 0x120) = (float)dVar1;
  return;
}

/* _glTexCoord1iv_Comp @ 0x94148 (116 bytes) */
int _glTexCoord1iv_Comp(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord1_ListExec_001103c0,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58);
  }
  return pfVar1;
}

/* _glTexCoord1iv_CompExec @ 0x941bc (56 bytes) */
int _glTexCoord1iv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord1iv_Comp)(param_1,param_2);
  ((int (*)())_glTexCoord1iv_Exec)(param_1,param_2);
  return;
}

/* _glTexCoord2i_Exec @ 0x941f4 (100 bytes) */
int _glTexCoord2i_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58;
  dVar1 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x120) = (float)dVar2;
  *(float *)(param_1 + 0x124) = (float)dVar1;
  return;
}

/* _glTexCoord2i_Comp @ 0x94258 (144 bytes) */
int _glTexCoord2i_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  uint param_3;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glTexCoord2_ListExec_001103bc,8);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glTexCoord2i_CompExec @ 0x942e8 (64 bytes) */
int _glTexCoord2i_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glTexCoord2i_Comp)(param_1,param_2,param_3);
  ((int (*)())_glTexCoord2i_Exec)(param_1,param_2,param_3);
  return;
}

/* _glTexCoord2iv_Exec @ 0x94328 (108 bytes) */
int _glTexCoord2iv_Exec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58;
  dVar1 = (double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x120) = (float)dVar2;
  *(float *)(param_1 + 0x124) = (float)dVar1;
  return;
}

/* _glTexCoord2iv_Comp @ 0x94394 (148 bytes) */
int _glTexCoord2iv_Comp(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glTexCoord2_ListExec_001103bc,8);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glTexCoord2iv_CompExec @ 0x94428 (56 bytes) */
int _glTexCoord2iv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord2iv_Comp)(param_1,param_2);
  ((int (*)())_glTexCoord2iv_Exec)(param_1,param_2);
  return;
}

/* _glTexCoord3i_Exec @ 0x94460 (128 bytes) */
int _glTexCoord3i_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar1 = (double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x120) = (float)dVar1;
  *(float *)(param_1 + 0x128) = (float)dVar3;
  *(float *)(param_1 + 0x124) = (float)dVar2;
  return;
}

/* _glTexCoord3i_Comp @ 0x944e0 (176 bytes) */
int _glTexCoord3i_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glTexCoord3_ListExec_001103b8,0xc);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glTexCoord3i_CompExec @ 0x94590 (72 bytes) */
int _glTexCoord3i_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glTexCoord3i_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glTexCoord3i_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glTexCoord3iv_Exec @ 0x945d8 (140 bytes) */
int _glTexCoord3iv_Exec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar1 = (double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - DOUBLE_00108d58;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x120) = (float)dVar1;
  *(float *)(param_1 + 0x128) = (float)dVar3;
  *(float *)(param_1 + 0x124) = (float)dVar2;
  return;
}

/* _glTexCoord3iv_Comp @ 0x94664 (180 bytes) */
int _glTexCoord3iv_Comp(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glTexCoord3_ListExec_001103b8,0xc);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glTexCoord3iv_CompExec @ 0x94718 (56 bytes) */
int _glTexCoord3iv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord3iv_Comp)(param_1,param_2);
  ((int (*)())_glTexCoord3iv_Exec)(param_1,param_2);
  return;
}

/* _glTexCoord4i_Exec @ 0x94750 (144 bytes) */
int _glTexCoord4i_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar1 = (double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  *(float *)(param_1 + 0x120) = (float)dVar1;
  *(float *)(param_1 + 0x124) = (float)dVar2;
  *(float *)(param_1 + 0x128) = (float)dVar3;
  *(float *)(param_1 + 300) = (float)dVar4;
  return;
}

/* _glTexCoord4i_Comp @ 0x947e0 (208 bytes) */
int _glTexCoord4i_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glTexCoord4_ListExec_001103b4,0x10);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1);
    pfVar2[3] = (float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glTexCoord4i_CompExec @ 0x948b0 (80 bytes) */
int _glTexCoord4i_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glTexCoord4i_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glTexCoord4i_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glTexCoord4iv_Exec @ 0x94900 (160 bytes) */
int _glTexCoord4iv_Exec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar1 = (double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,param_2[3] ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - DOUBLE_00108d58;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  *(float *)(param_1 + 0x120) = (float)dVar1;
  *(float *)(param_1 + 0x124) = (float)dVar2;
  *(float *)(param_1 + 0x128) = (float)dVar3;
  *(float *)(param_1 + 300) = (float)dVar4;
  return;
}

/* _glTexCoord4iv_Comp @ 0x949a0 (212 bytes) */
int _glTexCoord4iv_Comp(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glTexCoord4_ListExec_001103b4,0x10);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - dVar1);
    pfVar2[3] = (float)((double)CONCAT44(0x43300000,param_2[3] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glTexCoord4iv_CompExec @ 0x94a74 (56 bytes) */
int _glTexCoord4iv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord4iv_Comp)(param_1,param_2);
  ((int (*)())_glTexCoord4iv_Exec)(param_1,param_2);
  return;
}

/* _glTexCoord1s_Exec @ 0x94aac (80 bytes) */
int _glTexCoord1s_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  double dVar1;
  
  dVar1 = (double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x20);
  *(float *)(param_1 + 0x120) = (float)dVar1;
  return;
}

/* _glTexCoord1s_Comp @ 0x94afc (112 bytes) */
int _glTexCoord1s_Comp(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord1_ListExec_001103c0,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
  }
  return pfVar1;
}

/* _glTexCoord1s_CompExec @ 0x94b6c (56 bytes) */
int _glTexCoord1s_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord1s_Comp)(param_1,param_2);
  ((int (*)())_glTexCoord1s_Exec)(param_1,param_2);
  return;
}

/* _glTexCoord1sv_Exec @ 0x94ba4 (84 bytes) */
int _glTexCoord1sv_Exec(param_1, param_2)
  int param_1;
  short *param_2;
{
  double dVar1;
  
  dVar1 = (double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x20);
  *(float *)(param_1 + 0x120) = (float)dVar1;
  return;
}

