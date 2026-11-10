#include "decls.h"

/* _glTexCoord1sv_Comp @ 0x94bf8 (116 bytes) */
int _glTexCoord1sv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glTexCoord1_ListExec_001103c0,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58);
  }
  return pfVar1;
}

/* _glTexCoord1sv_CompExec @ 0x94c6c (56 bytes) */
void _glTexCoord1sv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord1sv_Comp)(param_1,param_2);
  _glTexCoord1sv_Exec(param_1,param_2);
  return;
}

/* _glTexCoord2s_Exec @ 0x94ca4 (100 bytes) */
void _glTexCoord2s_Exec(param_1, param_2, param_3)
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

/* _glTexCoord2s_Comp @ 0x94d08 (144 bytes) */
int _glTexCoord2s_Comp(param_1, param_2, param_3)
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

/* _glTexCoord2s_CompExec @ 0x94d98 (64 bytes) */
void _glTexCoord2s_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glTexCoord2s_Comp)(param_1,param_2,param_3);
  ((void (*)())_glTexCoord2s_Exec)(param_1,param_2,param_3);
  return;
}

/* _glTexCoord2sv_Exec @ 0x94dd8 (108 bytes) */
void _glTexCoord2sv_Exec(param_1, param_2)
  int param_1;
  short *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58;
  dVar1 = (double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x120) = (float)dVar2;
  *(float *)(param_1 + 0x124) = (float)dVar1;
  return;
}

/* _glTexCoord2sv_Comp @ 0x94e44 (148 bytes) */
int _glTexCoord2sv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glTexCoord2_ListExec_001103bc,8);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glTexCoord2sv_CompExec @ 0x94ed8 (56 bytes) */
void _glTexCoord2sv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord2sv_Comp)(param_1,param_2);
  ((void (*)())_glTexCoord2sv_Exec)(param_1,param_2);
  return;
}

/* _glTexCoord3s_Exec @ 0x94f10 (128 bytes) */
void _glTexCoord3s_Exec(param_1, param_2, param_3, param_4)
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

/* _glTexCoord3s_Comp @ 0x94f90 (176 bytes) */
int _glTexCoord3s_Comp(param_1, param_2, param_3, param_4)
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

/* _glTexCoord3s_CompExec @ 0x95040 (72 bytes) */
void _glTexCoord3s_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glTexCoord3s_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glTexCoord3s_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glTexCoord3sv_Exec @ 0x95088 (140 bytes) */
void _glTexCoord3sv_Exec(param_1, param_2)
  int param_1;
  short *param_2;
{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar1 = (double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - DOUBLE_00108d58;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x120) = (float)dVar1;
  *(float *)(param_1 + 0x128) = (float)dVar3;
  *(float *)(param_1 + 0x124) = (float)dVar2;
  return;
}

/* _glTexCoord3sv_Comp @ 0x95114 (180 bytes) */
int _glTexCoord3sv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glTexCoord3_ListExec_001103b8,0xc);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glTexCoord3sv_CompExec @ 0x951c8 (56 bytes) */
void _glTexCoord3sv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord3sv_Comp)(param_1,param_2);
  ((void (*)())_glTexCoord3sv_Exec)(param_1,param_2);
  return;
}

/* _glTexCoord4s_Exec @ 0x95200 (144 bytes) */
void _glTexCoord4s_Exec(param_1, param_2, param_3, param_4, param_5)
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

/* _glTexCoord4s_Comp @ 0x95290 (208 bytes) */
int _glTexCoord4s_Comp(param_1, param_2, param_3, param_4, param_5)
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

/* _glTexCoord4s_CompExec @ 0x95360 (80 bytes) */
void _glTexCoord4s_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glTexCoord4s_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((void (*)())_glTexCoord4s_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glTexCoord4sv_Exec @ 0x953b0 (160 bytes) */
void _glTexCoord4sv_Exec(param_1, param_2)
  int param_1;
  short *param_2;
{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar1 = (double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - DOUBLE_00108d58;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  *(float *)(param_1 + 0x120) = (float)dVar1;
  *(float *)(param_1 + 0x124) = (float)dVar2;
  *(float *)(param_1 + 0x128) = (float)dVar3;
  *(float *)(param_1 + 300) = (float)dVar4;
  return;
}

/* _glTexCoord4sv_Comp @ 0x95450 (212 bytes) */
int _glTexCoord4sv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glTexCoord4_ListExec_001103b4,0x10);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1);
    pfVar2[3] = (float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glTexCoord4sv_CompExec @ 0x95524 (56 bytes) */
void _glTexCoord4sv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glTexCoord4sv_Comp)(param_1,param_2);
  ((void (*)())_glTexCoord4sv_Exec)(param_1,param_2);
  return;
}

/* _glMultiTexCoord1_ListExec @ 0x9555c (52 bytes) */
int _glMultiTexCoord1_ListExec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  iVar3 = param_1 + (*param_2 & 7) * 0x10;
  *(uint *)(iVar3 + 0x120) = param_2[1];
  *(undefined4 *)(iVar3 + 300) = uVar1;
  *(undefined4 *)(iVar3 + 0x128) = uVar2;
  *(undefined4 *)(iVar3 + 0x124) = uVar2;
  return 8;
}

/* _glMultiTexCoord2_ListExec @ 0x95590 (56 bytes) */
int _glMultiTexCoord2_ListExec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  uVar2 = param_2[2];
  iVar4 = param_1 + (*param_2 & 7) * 0x10;
  uVar3 = param_2[1];
  *(undefined4 *)(iVar4 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(uint *)(iVar4 + 0x120) = uVar3;
  *(uint *)(iVar4 + 0x124) = uVar2;
  *(undefined4 *)(iVar4 + 0x128) = uVar1;
  return 0xc;
}

/* _glMultiTexCoord3_ListExec @ 0x955c8 (72 bytes) */
int _glMultiTexCoord3_ListExec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = param_2[3];
  uVar2 = param_2[2];
  iVar4 = param_1 + (*param_2 & 7) * 0x10;
  uVar3 = *(undefined4 *)(param_1 + 0x24);
  *(uint *)(iVar4 + 0x120) = param_2[1];
  *(undefined4 *)(iVar4 + 300) = uVar3;
  *(uint *)(iVar4 + 0x124) = uVar2;
  *(uint *)(iVar4 + 0x128) = uVar1;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return 0x10;
}

/* _glMultiTexCoord4_ListExec @ 0x95610 (72 bytes) */
int _glMultiTexCoord4_ListExec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = param_2[4];
  uVar2 = param_2[2];
  iVar4 = param_1 + (*param_2 & 7) * 0x10;
  uVar3 = param_2[3];
  *(uint *)(iVar4 + 0x120) = param_2[1];
  *(uint *)(iVar4 + 300) = uVar1;
  *(uint *)(iVar4 + 0x124) = uVar2;
  *(uint *)(iVar4 + 0x128) = uVar3;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  return 0x14;
}

/* _glMultiTexCoord1d_Exec @ 0x95658 (44 bytes) */
void _glMultiTexCoord1d_Exec(int param_1,uint param_2,double fparam_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  iVar3 = param_1 + (param_2 & 7) * 0x10;
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  *(float *)(iVar3 + 0x120) = (float)fparam_1;
  *(undefined4 *)(iVar3 + 300) = uVar1;
  *(undefined4 *)(iVar3 + 0x128) = uVar2;
  *(undefined4 *)(iVar3 + 0x124) = uVar2;
  return;
}

/* _glMultiTexCoord1d_Comp @ 0x95684 (100 bytes) */
int * _glMultiTexCoord1d_Comp(undefined4 param_1,int param_2,double fparam_1)
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)fparam_1);
  }
  return piVar1;
}

/* _glMultiTexCoord1d_CompExec @ 0x956e8 (72 bytes) */
void _glMultiTexCoord1d_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1)
{
  ((int * (*)())_glMultiTexCoord1d_Comp)(param_1,param_2,fparam_1);
  ((void (*)())_glMultiTexCoord1d_Exec)(param_1,param_2,fparam_1);
  return;
}

/* _glMultiTexCoord1dv_Exec @ 0x95730 (48 bytes) */
double _glMultiTexCoord1dv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  double *param_3;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = *param_3;
  iVar2 = param_1 + (param_2 & 7) * 0x10;
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(iVar2 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  *(undefined4 *)(iVar2 + 0x128) = uVar1;
  *(undefined4 *)(iVar2 + 0x124) = uVar1;
  return;
}

/* _glMultiTexCoord1dv_Comp @ 0x95760 (96 bytes) */
int _glMultiTexCoord1dv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  double *param_3;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)*param_3);
  }
  return piVar1;
}

/* _glMultiTexCoord1dv_CompExec @ 0x957c0 (64 bytes) */
void _glMultiTexCoord1dv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord1dv_Comp)(param_1,param_2,param_3);
  ((double (*)())_glMultiTexCoord1dv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord2d_Exec @ 0x95800 (48 bytes) */
void _glMultiTexCoord2d_Exec(int param_1,uint param_2,double fparam_1,double fparam_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  iVar3 = param_1 + (param_2 & 7) * 0x10;
  *(float *)(iVar3 + 0x120) = (float)fparam_1;
  *(undefined4 *)(iVar3 + 300) = uVar1;
  *(float *)(iVar3 + 0x124) = (float)fparam_2;
  *(undefined4 *)(iVar3 + 0x128) = uVar2;
  return;
}

/* _glMultiTexCoord2d_Comp @ 0x95830 (120 bytes) */
int * _glMultiTexCoord2d_Comp(undefined4 param_1,int param_2,double fparam_1,double fparam_2)
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)fparam_1);
    piVar1[2] = (int)GH_F2U((float)fparam_2);
  }
  return piVar1;
}

/* _glMultiTexCoord2d_CompExec @ 0x958a8 (88 bytes) */
void _glMultiTexCoord2d_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2)
{
  ((int * (*)())_glMultiTexCoord2d_Comp)(param_1,param_2,fparam_1,fparam_2);
  ((void (*)())_glMultiTexCoord2d_Exec)(param_1,param_2,fparam_1,fparam_2);
  return;
}

/* _glMultiTexCoord2dv_Exec @ 0x95900 (56 bytes) */
double _glMultiTexCoord2dv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  double *param_3;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  
  dVar4 = param_3[1];
  dVar3 = *param_3;
  iVar2 = param_1 + (param_2 & 7) * 0x10;
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(iVar2 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  *(float *)(iVar2 + 0x124) = (float)dVar4;
  *(undefined4 *)(iVar2 + 0x128) = uVar1;
  return;
}

/* _glMultiTexCoord2dv_Comp @ 0x95938 (108 bytes) */
int _glMultiTexCoord2dv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  double *param_3;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)*param_3);
    piVar1[2] = (int)GH_F2U((float)param_3[1]);
  }
  return piVar1;
}

/* _glMultiTexCoord2dv_CompExec @ 0x959a4 (64 bytes) */
void _glMultiTexCoord2dv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord2dv_Comp)(param_1,param_2,param_3);
  ((double (*)())_glMultiTexCoord2dv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord3d_Exec @ 0x959e4 (60 bytes) */
void _glMultiTexCoord3d_Exec(int param_1,uint param_2,double fparam_1,double fparam_2,double fparam_3)
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  iVar2 = param_1 + (param_2 & 7) * 0x10;
  *(float *)(iVar2 + 0x120) = (float)fparam_1;
  *(undefined4 *)(iVar2 + 300) = uVar1;
  *(float *)(iVar2 + 0x124) = (float)fparam_2;
  *(float *)(iVar2 + 0x128) = (float)fparam_3;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

/* _glMultiTexCoord3d_Comp @ 0x95a20 (140 bytes) */
int * _glMultiTexCoord3d_Comp(undefined4 param_1,int param_2,double fparam_1,double fparam_2,double fparam_3)
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)fparam_1);
    piVar1[2] = (int)GH_F2U((float)fparam_2);
    piVar1[3] = (int)GH_F2U((float)fparam_3);
  }
  return piVar1;
}

/* _glMultiTexCoord3d_CompExec @ 0x95aac (104 bytes) */
void _glMultiTexCoord3d_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3)
{
  ((int * (*)())_glMultiTexCoord3d_Comp)(param_1,param_2,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glMultiTexCoord3d_Exec)(param_1,param_2,fparam_1,fparam_2,fparam_3);
  return;
}

/* _glMultiTexCoord3dv_Exec @ 0x95b14 (72 bytes) */
double _glMultiTexCoord3dv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  double *param_3;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar3 = param_3[2];
  dVar2 = *param_3;
  iVar1 = param_1 + (param_2 & 7) * 0x10;
  dVar4 = param_3[1];
  *(undefined4 *)(iVar1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(iVar1 + 0x120) = (float)dVar2;
  *(float *)(iVar1 + 0x124) = (float)dVar4;
  *(float *)(iVar1 + 0x128) = (float)dVar3;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

/* _glMultiTexCoord3dv_Comp @ 0x95b5c (120 bytes) */
int _glMultiTexCoord3dv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  double *param_3;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)*param_3);
    piVar1[2] = (int)GH_F2U((float)param_3[1]);
    piVar1[3] = (int)GH_F2U((float)param_3[2]);
  }
  return piVar1;
}

/* _glMultiTexCoord3dv_CompExec @ 0x95bd4 (64 bytes) */
void _glMultiTexCoord3dv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord3dv_Comp)(param_1,param_2,param_3);
  ((double (*)())_glMultiTexCoord3dv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord4d_Exec @ 0x95c14 (60 bytes) */
void _glMultiTexCoord4d_Exec(int param_1,uint param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  int iVar1;
  
  iVar1 = param_1 + (param_2 & 7) * 0x10;
  *(float *)(iVar1 + 0x120) = (float)fparam_1;
  *(float *)(iVar1 + 0x124) = (float)fparam_2;
  *(float *)(iVar1 + 0x128) = (float)fparam_3;
  *(float *)(iVar1 + 300) = (float)fparam_4;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  return;
}

/* _glMultiTexCoord4d_Comp @ 0x95c50 (120 bytes) */
void _glMultiTexCoord4d_Comp(undefined4 param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)fparam_1);
    piVar1[2] = (int)GH_F2U((float)fparam_2);
    piVar1[3] = (int)GH_F2U((float)fparam_3);
    piVar1[4] = (int)GH_F2U((float)fparam_4);
  }
  FUN_00008b68();
  return;
}

/* _glMultiTexCoord4d_CompExec @ 0x95cc8 (104 bytes) */
void _glMultiTexCoord4d_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((void (*)())_glMultiTexCoord4d_Comp)(param_1,param_2,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glMultiTexCoord4d_Exec)(param_1,param_2,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glMultiTexCoord4dv_Exec @ 0x95d30 (76 bytes) */
double _glMultiTexCoord4dv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  double *param_3;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar2 = *param_3;
  iVar1 = param_1 + (param_2 & 7) * 0x10;
  dVar4 = param_3[1];
  dVar3 = param_3[2];
  *(float *)(iVar1 + 300) = (float)param_3[3];
  *(float *)(iVar1 + 0x120) = (float)dVar2;
  *(float *)(iVar1 + 0x124) = (float)dVar4;
  *(float *)(iVar1 + 0x128) = (float)dVar3;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  return;
}

/* _glMultiTexCoord4dv_Comp @ 0x95d7c (132 bytes) */
int _glMultiTexCoord4dv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  double *param_3;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)*param_3);
    piVar1[2] = (int)GH_F2U((float)param_3[1]);
    piVar1[3] = (int)GH_F2U((float)param_3[2]);
    piVar1[4] = (int)GH_F2U((float)param_3[3]);
  }
  return piVar1;
}

/* _glMultiTexCoord4dv_CompExec @ 0x95e00 (64 bytes) */
void _glMultiTexCoord4dv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord4dv_Comp)(param_1,param_2,param_3);
  ((double (*)())_glMultiTexCoord4dv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord1f_Exec @ 0x95e40 (40 bytes) */
void _glMultiTexCoord1f_Exec(int param_1,uint param_2,float fparam_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  iVar3 = param_1 + (param_2 & 7) * 0x10;
  *(float *)(iVar3 + 0x120) = (float)fparam_1;
  *(undefined4 *)(iVar3 + 300) = uVar1;
  *(undefined4 *)(iVar3 + 0x128) = uVar2;
  *(undefined4 *)(iVar3 + 0x124) = uVar2;
  return;
}

/* _glMultiTexCoord1f_Comp @ 0x95e68 (96 bytes) */
int * _glMultiTexCoord1f_Comp(undefined4 param_1,int param_2,double fparam_1)
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (piVar1 != (int *)0x0) {
    piVar1[1] = (int)GH_F2U((float)fparam_1);
    *piVar1 = param_2 + -0x84c0;
  }
  return piVar1;
}

/* _glMultiTexCoord1f_CompExec @ 0x95ec8 (72 bytes) */
void _glMultiTexCoord1f_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1)
{
  ((int * (*)())_glMultiTexCoord1f_Comp)(param_1,param_2,fparam_1);
  ((void (*)())_glMultiTexCoord1f_Exec)(param_1,param_2,fparam_1);
  return;
}

/* _glMultiTexCoord1fv_Exec @ 0x95f10 (44 bytes) */
double _glMultiTexCoord1fv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  iVar3 = param_1 + (param_2 & 7) * 0x10;
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(iVar3 + 0x120) = *param_3;
  *(undefined4 *)(iVar3 + 300) = uVar1;
  *(undefined4 *)(iVar3 + 0x128) = uVar2;
  *(undefined4 *)(iVar3 + 0x124) = uVar2;
  return;
}

/* _glMultiTexCoord1fv_Comp @ 0x95f3c (92 bytes) */
int _glMultiTexCoord1fv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = *param_3;
  }
  return piVar1;
}

/* _glMultiTexCoord1fv_CompExec @ 0x95f98 (64 bytes) */
void _glMultiTexCoord1fv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord1fv_Comp)(param_1,param_2,param_3);
  ((double (*)())_glMultiTexCoord1fv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord2f_Comp @ 0x95fd8 (112 bytes) */
int * _glMultiTexCoord2f_Comp(undefined4 param_1,int param_2,double fparam_1,double fparam_2)
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (piVar1 != (int *)0x0) {
    piVar1[2] = (int)GH_F2U((float)fparam_2);
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)fparam_1);
  }
  return piVar1;
}

/* _glMultiTexCoord2f_CompExec @ 0x96048 (88 bytes) */
void _glMultiTexCoord2f_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2)
{
  ((int * (*)())_glMultiTexCoord2f_Comp)(param_1,param_2,fparam_1,fparam_2);
  ((void (*)())_glMultiTexCoord2f_Exec)(param_1,param_2,fparam_1,fparam_2);
  return;
}

/* _glMultiTexCoord2fv_Exec @ 0x960a0 (48 bytes) */
double _glMultiTexCoord2fv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = param_3[1];
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  iVar4 = param_1 + (param_2 & 7) * 0x10;
  uVar3 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(iVar4 + 0x120) = *param_3;
  *(undefined4 *)(iVar4 + 300) = uVar2;
  *(undefined4 *)(iVar4 + 0x124) = uVar1;
  *(undefined4 *)(iVar4 + 0x128) = uVar3;
  return;
}

/* _glMultiTexCoord2fv_Comp @ 0x960d0 (100 bytes) */
int _glMultiTexCoord2fv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = *param_3;
    piVar1[2] = param_3[1];
  }
  return piVar1;
}

/* _glMultiTexCoord2fv_CompExec @ 0x96134 (64 bytes) */
void _glMultiTexCoord2fv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord2fv_Comp)(param_1,param_2,param_3);
  ((double (*)())_glMultiTexCoord2fv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord3f_Exec @ 0x96174 (48 bytes) */
void _glMultiTexCoord3f_Exec(int param_1,uint param_2,float fparam_1,float fparam_2,float fparam_3)
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  iVar2 = param_1 + (param_2 & 7) * 0x10;
  *(float *)(iVar2 + 0x120) = (float)fparam_1;
  *(undefined4 *)(iVar2 + 300) = uVar1;
  *(float *)(iVar2 + 0x124) = (float)fparam_2;
  *(float *)(iVar2 + 0x128) = (float)fparam_3;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

