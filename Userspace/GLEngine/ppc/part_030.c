#include "decls.h"

/* _glMultiTexCoord3f_Comp @ 0x961a4 (128 bytes) */
int * _glMultiTexCoord3f_Comp(undefined4 param_1,int param_2,double fparam_1,double fparam_2,double fparam_3)
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (piVar1 != (int *)0x0) {
    piVar1[3] = (int)GH_F2U((float)fparam_3);
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)fparam_1);
    piVar1[2] = (int)GH_F2U((float)fparam_2);
  }
  return piVar1;
}

/* _glMultiTexCoord3f_CompExec @ 0x96224 (104 bytes) */
void _glMultiTexCoord3f_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3)
{
  ((int * (*)())_glMultiTexCoord3f_Comp)(param_1,param_2,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glMultiTexCoord3f_Exec)(param_1,param_2,fparam_1,fparam_2,fparam_3);
  return;
}

/* _glMultiTexCoord3fv_Exec @ 0x9628c (60 bytes) */
int _glMultiTexCoord3fv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = param_3[2];
  iVar4 = param_1 + (param_2 & 7) * 0x10;
  uVar2 = param_3[1];
  uVar3 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(iVar4 + 0x120) = *param_3;
  *(undefined4 *)(iVar4 + 300) = uVar3;
  *(undefined4 *)(iVar4 + 0x124) = uVar2;
  *(undefined4 *)(iVar4 + 0x128) = uVar1;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

/* _glMultiTexCoord3fv_Comp @ 0x962c8 (108 bytes) */
int _glMultiTexCoord3fv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = *param_3;
    piVar1[2] = param_3[1];
    piVar1[3] = param_3[2];
  }
  return piVar1;
}

/* _glMultiTexCoord3fv_CompExec @ 0x96334 (64 bytes) */
int _glMultiTexCoord3fv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord3fv_Comp)(param_1,param_2,param_3);
  ((int (*)())_glMultiTexCoord3fv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord4f_Exec @ 0x96374 (44 bytes) */
void _glMultiTexCoord4f_Exec(int param_1,uint param_2,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  int iVar1;
  
  iVar1 = param_1 + (param_2 & 7) * 0x10;
  *(float *)(iVar1 + 0x120) = (float)fparam_1;
  *(float *)(iVar1 + 300) = (float)fparam_4;
  *(float *)(iVar1 + 0x124) = (float)fparam_2;
  *(float *)(iVar1 + 0x128) = (float)fparam_3;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  return;
}

/* _glMultiTexCoord4f_Comp @ 0x963a0 (104 bytes) */
void _glMultiTexCoord4f_Comp(undefined4 param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (piVar1 != (int *)0x0) {
    piVar1[4] = (int)GH_F2U((float)fparam_4);
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)fparam_1);
    piVar1[2] = (int)GH_F2U((float)fparam_2);
    piVar1[3] = (int)GH_F2U((float)fparam_3);
  }
  FUN_00008b68();
  return;
}

/* _glMultiTexCoord4f_CompExec @ 0x96408 (104 bytes) */
void _glMultiTexCoord4f_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((void (*)())_glMultiTexCoord4f_Comp)(param_1,param_2,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glMultiTexCoord4f_Exec)(param_1,param_2,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glMultiTexCoord4fv_Comp @ 0x96470 (116 bytes) */
int _glMultiTexCoord4fv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = *param_3;
    piVar1[2] = param_3[1];
    piVar1[3] = param_3[2];
    piVar1[4] = param_3[3];
  }
  return piVar1;
}

/* _glMultiTexCoord4fv_CompExec @ 0x964e4 (64 bytes) */
int _glMultiTexCoord4fv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord4fv_Comp)(param_1,param_2,param_3);
  _glMultiTexCoord4fv_Exec(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord1i_Exec @ 0x96524 (92 bytes) */
int _glMultiTexCoord1i_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  
  iVar2 = param_1 + (param_2 & 7) * 0x10;
  dVar3 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(iVar2 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = uVar1;
  *(undefined4 *)(iVar2 + 0x124) = uVar1;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord1i_Comp @ 0x96580 (124 bytes) */
int _glMultiTexCoord1i_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  uint param_3;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58));
  }
  return piVar1;
}

/* _glMultiTexCoord1i_CompExec @ 0x965fc (64 bytes) */
int _glMultiTexCoord1i_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord1i_Comp)(param_1,param_2,param_3);
  ((int (*)())_glMultiTexCoord1i_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord1iv_Exec @ 0x9663c (96 bytes) */
int _glMultiTexCoord1iv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  
  iVar2 = param_1 + (param_2 & 7) * 0x10;
  dVar3 = (double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(iVar2 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = uVar1;
  *(undefined4 *)(iVar2 + 0x124) = uVar1;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord1iv_Comp @ 0x9669c (128 bytes) */
int _glMultiTexCoord1iv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  uint *param_3;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58));
  }
  return piVar1;
}

/* _glMultiTexCoord1iv_CompExec @ 0x9671c (64 bytes) */
int _glMultiTexCoord1iv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord1iv_Comp)(param_1,param_2,param_3);
  ((int (*)())_glMultiTexCoord1iv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord2i_Exec @ 0x9675c (112 bytes) */
int _glMultiTexCoord2i_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  
  iVar2 = param_1 + (param_2 & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(iVar2 + 300) = uVar1;
  *(float *)(iVar2 + 0x124) = (float)dVar4;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord2i_Comp @ 0x967cc (156 bytes) */
int _glMultiTexCoord2i_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  int *piVar2;
  
  piVar2 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (piVar2 != (int *)0x0) {
    *piVar2 = param_2 + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    piVar2[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58));
    piVar2[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1));
  }
  return piVar2;
}

/* _glMultiTexCoord2i_CompExec @ 0x96868 (72 bytes) */
int _glMultiTexCoord2i_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glMultiTexCoord2i_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glMultiTexCoord2i_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glMultiTexCoord2iv_Exec @ 0x968b0 (120 bytes) */
int _glMultiTexCoord2iv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  
  iVar2 = param_1 + (param_2 & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,param_3[1] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(iVar2 + 300) = uVar1;
  *(float *)(iVar2 + 0x124) = (float)dVar4;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord2iv_Comp @ 0x96928 (160 bytes) */
int _glMultiTexCoord2iv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  uint *param_3;
{
  double dVar1;
  int *piVar2;
  
  piVar2 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (piVar2 != (int *)0x0) {
    *piVar2 = param_2 + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    piVar2[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58));
    piVar2[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_3[1] ^ 0x80000000) - dVar1));
  }
  return piVar2;
}

/* _glMultiTexCoord2iv_CompExec @ 0x969c8 (64 bytes) */
int _glMultiTexCoord2iv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord2iv_Comp)(param_1,param_2,param_3);
  ((int (*)())_glMultiTexCoord2iv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord3i_Exec @ 0x96a08 (140 bytes) */
int _glMultiTexCoord3i_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = param_1 + (param_2 & 7) * 0x10;
  dVar2 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(iVar1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(iVar1 + 0x120) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar4;
  *(float *)(iVar1 + 0x124) = (float)dVar3;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

/* _glMultiTexCoord3i_Comp @ 0x96a94 (188 bytes) */
int _glMultiTexCoord3i_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  double dVar1;
  int *piVar2;
  
  piVar2 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (piVar2 != (int *)0x0) {
    *piVar2 = param_2 + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    piVar2[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58));
    piVar2[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1));
    piVar2[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar1));
  }
  return piVar2;
}

/* _glMultiTexCoord3i_CompExec @ 0x96b50 (80 bytes) */
int _glMultiTexCoord3i_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glMultiTexCoord3i_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glMultiTexCoord3i_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glMultiTexCoord3iv_Exec @ 0x96ba0 (152 bytes) */
int _glMultiTexCoord3iv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = param_1 + (param_2 & 7) * 0x10;
  dVar2 = (double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,param_3[2] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,param_3[1] ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(iVar1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(iVar1 + 0x120) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar4;
  *(float *)(iVar1 + 0x124) = (float)dVar3;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

/* _glMultiTexCoord3iv_Comp @ 0x96c38 (192 bytes) */
int _glMultiTexCoord3iv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  uint *param_3;
{
  double dVar1;
  int *piVar2;
  
  piVar2 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (piVar2 != (int *)0x0) {
    *piVar2 = param_2 + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    piVar2[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58));
    piVar2[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_3[1] ^ 0x80000000) - dVar1));
    piVar2[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_3[2] ^ 0x80000000) - dVar1));
  }
  return piVar2;
}

/* _glMultiTexCoord3iv_CompExec @ 0x96cf8 (64 bytes) */
int _glMultiTexCoord3iv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord3iv_Comp)(param_1,param_2,param_3);
  ((int (*)())_glMultiTexCoord3iv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord4i_Exec @ 0x96d38 (156 bytes) */
int _glMultiTexCoord4i_Exec(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = param_1 + (param_2 & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,param_6 ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_00108d58;
  *(float *)(iVar1 + 0x120) =
       (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
  *(float *)(iVar1 + 0x124) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar3;
  *(float *)(iVar1 + 300) = (float)dVar4;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  return;
}

/* _glMultiTexCoord4i_Comp @ 0x96dd4 (220 bytes) */
int _glMultiTexCoord4i_Comp(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
{
  double dVar1;
  int *piVar2;
  
  piVar2 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (piVar2 != (int *)0x0) {
    *piVar2 = param_2 + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    piVar2[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58));
    piVar2[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1));
    piVar2[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar1));
    piVar2[4] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_6 ^ 0x80000000) - dVar1));
  }
  return piVar2;
}

/* _glMultiTexCoord4i_CompExec @ 0x96eb0 (88 bytes) */
int _glMultiTexCoord4i_CompExec(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  ((int (*)())_glMultiTexCoord4i_Comp)(param_1,param_2,param_3,param_4,param_5,param_6);
  ((int (*)())_glMultiTexCoord4i_Exec)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* _glMultiTexCoord4iv_Exec @ 0x96f08 (172 bytes) */
int _glMultiTexCoord4iv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = param_1 + (param_2 & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,param_3[3] ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,param_3[1] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,param_3[2] ^ 0x80000000) - DOUBLE_00108d58;
  *(float *)(iVar1 + 0x120) =
       (float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58);
  *(float *)(iVar1 + 0x124) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar3;
  *(float *)(iVar1 + 300) = (float)dVar4;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  return;
}

/* _glMultiTexCoord4iv_Comp @ 0x96fb4 (224 bytes) */
int _glMultiTexCoord4iv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  uint *param_3;
{
  double dVar1;
  int *piVar2;
  
  piVar2 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (piVar2 != (int *)0x0) {
    *piVar2 = param_2 + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    piVar2[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58));
    piVar2[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_3[1] ^ 0x80000000) - dVar1));
    piVar2[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_3[2] ^ 0x80000000) - dVar1));
    piVar2[4] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_3[3] ^ 0x80000000) - dVar1));
  }
  return piVar2;
}

/* _glMultiTexCoord4iv_CompExec @ 0x97094 (64 bytes) */
int _glMultiTexCoord4iv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord4iv_Comp)(param_1,param_2,param_3);
  ((int (*)())_glMultiTexCoord4iv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord1s_Exec @ 0x970d4 (92 bytes) */
int _glMultiTexCoord1s_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  
  iVar2 = param_1 + (param_2 & 7) * 0x10;
  dVar3 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(iVar2 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = uVar1;
  *(undefined4 *)(iVar2 + 0x124) = uVar1;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord1s_Comp @ 0x97130 (124 bytes) */
int _glMultiTexCoord1s_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  uint param_3;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58));
  }
  return piVar1;
}

/* _glMultiTexCoord1s_CompExec @ 0x971ac (64 bytes) */
int _glMultiTexCoord1s_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord1s_Comp)(param_1,param_2,param_3);
  ((int (*)())_glMultiTexCoord1s_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord1sv_Exec @ 0x971ec (96 bytes) */
int _glMultiTexCoord1sv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  short *param_3;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  
  iVar2 = param_1 + (param_2 & 7) * 0x10;
  dVar3 = (double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(iVar2 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = uVar1;
  *(undefined4 *)(iVar2 + 0x124) = uVar1;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord1sv_Comp @ 0x9724c (128 bytes) */
int _glMultiTexCoord1sv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  short *param_3;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x84c0;
    piVar1[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) -
                            DOUBLE_00108d58));
  }
  return piVar1;
}

/* _glMultiTexCoord1sv_CompExec @ 0x972cc (64 bytes) */
int _glMultiTexCoord1sv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord1sv_Comp)(param_1,param_2,param_3);
  ((int (*)())_glMultiTexCoord1sv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord2s_Exec @ 0x9730c (112 bytes) */
int _glMultiTexCoord2s_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  
  iVar2 = param_1 + (param_2 & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(iVar2 + 300) = uVar1;
  *(float *)(iVar2 + 0x124) = (float)dVar4;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord2s_Comp @ 0x9737c (156 bytes) */
int _glMultiTexCoord2s_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  int *piVar2;
  
  piVar2 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (piVar2 != (int *)0x0) {
    *piVar2 = param_2 + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    piVar2[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58));
    piVar2[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1));
  }
  return piVar2;
}

/* _glMultiTexCoord2s_CompExec @ 0x97418 (72 bytes) */
int _glMultiTexCoord2s_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glMultiTexCoord2s_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glMultiTexCoord2s_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glMultiTexCoord2sv_Exec @ 0x97460 (120 bytes) */
int _glMultiTexCoord2sv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  short *param_3;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  
  iVar2 = param_1 + (param_2 & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(iVar2 + 300) = uVar1;
  *(float *)(iVar2 + 0x124) = (float)dVar4;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord2sv_Comp @ 0x974d8 (160 bytes) */
int _glMultiTexCoord2sv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  short *param_3;
{
  double dVar1;
  int *piVar2;
  
  piVar2 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (piVar2 != (int *)0x0) {
    *piVar2 = param_2 + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    piVar2[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) -
                            DOUBLE_00108d58));
    piVar2[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - dVar1));
  }
  return piVar2;
}

/* _glMultiTexCoord2sv_CompExec @ 0x97578 (64 bytes) */
int _glMultiTexCoord2sv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord2sv_Comp)(param_1,param_2,param_3);
  ((int (*)())_glMultiTexCoord2sv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord3s_Exec @ 0x975b8 (140 bytes) */
int _glMultiTexCoord3s_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = param_1 + (param_2 & 7) * 0x10;
  dVar2 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(iVar1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(iVar1 + 0x120) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar4;
  *(float *)(iVar1 + 0x124) = (float)dVar3;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

/* _glMultiTexCoord3s_Comp @ 0x97644 (188 bytes) */
int _glMultiTexCoord3s_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  double dVar1;
  int *piVar2;
  
  piVar2 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (piVar2 != (int *)0x0) {
    *piVar2 = param_2 + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    piVar2[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58));
    piVar2[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1));
    piVar2[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar1));
  }
  return piVar2;
}

/* _glMultiTexCoord3s_CompExec @ 0x97700 (80 bytes) */
int _glMultiTexCoord3s_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glMultiTexCoord3s_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glMultiTexCoord3s_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glMultiTexCoord3sv_Exec @ 0x97750 (152 bytes) */
int _glMultiTexCoord3sv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  short *param_3;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = param_1 + (param_2 & 7) * 0x10;
  dVar2 = (double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,(int)param_3[2] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(iVar1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(iVar1 + 0x120) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar4;
  *(float *)(iVar1 + 0x124) = (float)dVar3;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

/* _glMultiTexCoord3sv_Comp @ 0x977e8 (192 bytes) */
int _glMultiTexCoord3sv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  short *param_3;
{
  double dVar1;
  int *piVar2;
  
  piVar2 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (piVar2 != (int *)0x0) {
    *piVar2 = param_2 + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    piVar2[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) -
                            DOUBLE_00108d58));
    piVar2[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - dVar1));
    piVar2[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)param_3[2] ^ 0x80000000) - dVar1));
  }
  return piVar2;
}

/* _glMultiTexCoord3sv_CompExec @ 0x978a8 (64 bytes) */
int _glMultiTexCoord3sv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord3sv_Comp)(param_1,param_2,param_3);
  ((int (*)())_glMultiTexCoord3sv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMultiTexCoord4s_Exec @ 0x978e8 (156 bytes) */
int _glMultiTexCoord4s_Exec(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = param_1 + (param_2 & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,param_6 ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_00108d58;
  *(float *)(iVar1 + 0x120) =
       (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
  *(float *)(iVar1 + 0x124) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar3;
  *(float *)(iVar1 + 300) = (float)dVar4;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  return;
}

/* _glMultiTexCoord4s_Comp @ 0x97984 (220 bytes) */
int _glMultiTexCoord4s_Comp(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
{
  double dVar1;
  int *piVar2;
  
  piVar2 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (piVar2 != (int *)0x0) {
    *piVar2 = param_2 + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    piVar2[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58));
    piVar2[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1));
    piVar2[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar1));
    piVar2[4] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,param_6 ^ 0x80000000) - dVar1));
  }
  return piVar2;
}

/* _glMultiTexCoord4s_CompExec @ 0x97a60 (88 bytes) */
int _glMultiTexCoord4s_CompExec(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  ((int (*)())_glMultiTexCoord4s_Comp)(param_1,param_2,param_3,param_4,param_5,param_6);
  ((int (*)())_glMultiTexCoord4s_Exec)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* _glMultiTexCoord4sv_Exec @ 0x97ab8 (172 bytes) */
int _glMultiTexCoord4sv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  short *param_3;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = param_1 + (param_2 & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,(int)param_3[3] ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,(int)param_3[2] ^ 0x80000000) - DOUBLE_00108d58;
  *(float *)(iVar1 + 0x120) =
       (float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58);
  *(float *)(iVar1 + 0x124) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar3;
  *(float *)(iVar1 + 300) = (float)dVar4;
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
  return;
}

/* _glMultiTexCoord4sv_Comp @ 0x97b64 (224 bytes) */
int _glMultiTexCoord4sv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  short *param_3;
{
  double dVar1;
  int *piVar2;
  
  piVar2 = (int *)_gleAddListItem(param_1,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (piVar2 != (int *)0x0) {
    *piVar2 = param_2 + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    piVar2[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) -
                            DOUBLE_00108d58));
    piVar2[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - dVar1));
    piVar2[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)param_3[2] ^ 0x80000000) - dVar1));
    piVar2[4] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)param_3[3] ^ 0x80000000) - dVar1));
  }
  return piVar2;
}

/* _glMultiTexCoord4sv_CompExec @ 0x97c44 (64 bytes) */
int _glMultiTexCoord4sv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glMultiTexCoord4sv_Comp)(param_1,param_2,param_3);
  ((int (*)())_glMultiTexCoord4sv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glCopyTexSubImage1D_ListExec @ 0x97c84 (64 bytes) */
undefined4 _glCopyTexSubImage1D_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glCopyTexSubImage1D_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],fparam_1,
             fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return 0x18;
}

/* _glCopyTexSubImage1D_Comp @ 0x97cc4 (116 bytes) */
int _glCopyTexSubImage1D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glCopyTexSubImage1D_ListExec_001103cc,0x18);
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

