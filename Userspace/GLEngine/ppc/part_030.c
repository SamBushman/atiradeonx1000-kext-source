#include "decls.h"

/* _glMultiTexCoord3f_Comp @ 0x961a4 (128 bytes) */
int * _glMultiTexCoord3f_Comp(undefined4 glContext,int target,float sCoord,float t,float r)
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (listRecord != (int *)0x0) {
    listRecord[3] = (int)GH_F2U((float)r);
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)sCoord);
    listRecord[2] = (int)GH_F2U((float)t);
  }
  return listRecord;
}

/* _glMultiTexCoord3f_CompExec @ 0x96224 (104 bytes) */
void _glMultiTexCoord3f_CompExec(undefined4 glContext,undefined4 target,float sCoord,float t,float r)
{
  ((int * (*)())_glMultiTexCoord3f_Comp)(glContext,target,sCoord,t,r);
  ((void (*)())_glMultiTexCoord3f_Exec)(glContext,target,sCoord,t,r);
  return;
}

/* _glMultiTexCoord3fv_Exec @ 0x9628c (60 bytes) */
double _glMultiTexCoord3fv_Exec(glContext, target, v)
  int glContext;
  uint target;
  undefined4 *v;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = v[2];
  iVar4 = glContext + (target & 7) * 0x10;
  uVar2 = v[1];
  uVar3 = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(iVar4 + 0x120) = *v;
  *(undefined4 *)(iVar4 + 300) = uVar3;
  *(undefined4 *)(iVar4 + 0x124) = uVar2;
  *(undefined4 *)(iVar4 + 0x128) = uVar1;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  return;
}

/* _glMultiTexCoord3fv_Comp @ 0x962c8 (108 bytes) */
int _glMultiTexCoord3fv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  int *v;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = *v;
    listRecord[2] = v[1];
    listRecord[3] = v[2];
  }
  return listRecord;
}

/* _glMultiTexCoord3fv_CompExec @ 0x96334 (64 bytes) */
void _glMultiTexCoord3fv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord3fv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord3fv_Exec)(glContext,target,v);
  return;
}

/* _glMultiTexCoord4f_Exec @ 0x96374 (44 bytes) */
void _glMultiTexCoord4f_Exec(int glContext,uint target,float sCoord,float t,float r,float q)
{
  int iVar1;
  
  iVar1 = glContext + (target & 7) * 0x10;
  *(float *)(iVar1 + 0x120) = (float)sCoord;
  *(float *)(iVar1 + 300) = (float)q;
  *(float *)(iVar1 + 0x124) = (float)t;
  *(float *)(iVar1 + 0x128) = (float)r;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  return;
}

/* _glMultiTexCoord4f_Comp @ 0x963a0 (104 bytes) */
void _glMultiTexCoord4f_Comp(undefined4 glContext,int target,float sCoord,float t,float r,float q)
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (listRecord != (int *)0x0) {
    listRecord[4] = (int)GH_F2U((float)q);
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)sCoord);
    listRecord[2] = (int)GH_F2U((float)t);
    listRecord[3] = (int)GH_F2U((float)r);
  }
  return;
}

/* _glMultiTexCoord4f_CompExec @ 0x96408 (104 bytes) */
void _glMultiTexCoord4f_CompExec(undefined4 glContext,undefined4 target,float sCoord,float t,float r,float q)
{
  ((void (*)())_glMultiTexCoord4f_Comp)(glContext,target,sCoord,t,r,q);
  ((void (*)())_glMultiTexCoord4f_Exec)(glContext,target,sCoord,t,r,q);
  return;
}

/* _glMultiTexCoord4fv_Comp @ 0x96470 (116 bytes) */
int _glMultiTexCoord4fv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  int *v;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = *v;
    listRecord[2] = v[1];
    listRecord[3] = v[2];
    listRecord[4] = v[3];
  }
  return listRecord;
}

/* _glMultiTexCoord4fv_CompExec @ 0x964e4 (64 bytes) */
void _glMultiTexCoord4fv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord4fv_Comp)(glContext,target,v);
  _glMultiTexCoord4fv_Exec(glContext,target,v);
  return;
}

/* _glMultiTexCoord1i_Exec @ 0x96524 (92 bytes) */
void _glMultiTexCoord1i_Exec(glContext, target, sCoord)
  int glContext;
  uint target;
  uint sCoord;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  
  iVar2 = glContext + (target & 7) * 0x10;
  dVar3 = (double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(iVar2 + 300) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = uVar1;
  *(undefined4 *)(iVar2 + 0x124) = uVar1;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord1i_Comp @ 0x96580 (124 bytes) */
int _glMultiTexCoord1i_Comp(glContext, target, sCoord)
  undefined4 glContext;
  int target;
  uint sCoord;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58));
  }
  return listRecord;
}

/* _glMultiTexCoord1i_CompExec @ 0x965fc (64 bytes) */
void _glMultiTexCoord1i_CompExec(glContext, target, sCoord)
  undefined4 glContext;
  undefined4 target;
  undefined4 sCoord;
{
  ((int (*)())_glMultiTexCoord1i_Comp)(glContext,target,sCoord);
  ((void (*)())_glMultiTexCoord1i_Exec)(glContext,target,sCoord);
  return;
}

/* _glMultiTexCoord1iv_Exec @ 0x9663c (96 bytes) */
double _glMultiTexCoord1iv_Exec(glContext, target, v)
  int glContext;
  uint target;
  uint *v;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  
  iVar2 = glContext + (target & 7) * 0x10;
  dVar3 = (double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(iVar2 + 300) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = uVar1;
  *(undefined4 *)(iVar2 + 0x124) = uVar1;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord1iv_Comp @ 0x9669c (128 bytes) */
int _glMultiTexCoord1iv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  uint *v;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58));
  }
  return listRecord;
}

/* _glMultiTexCoord1iv_CompExec @ 0x9671c (64 bytes) */
void _glMultiTexCoord1iv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord1iv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord1iv_Exec)(glContext,target,v);
  return;
}

/* _glMultiTexCoord2i_Exec @ 0x9675c (112 bytes) */
void _glMultiTexCoord2i_Exec(glContext, target, sCoord, t)
  int glContext;
  uint target;
  uint sCoord;
  uint t;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  
  iVar2 = glContext + (target & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,t ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(iVar2 + 300) = uVar1;
  *(float *)(iVar2 + 0x124) = (float)dVar4;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord2i_Comp @ 0x967cc (156 bytes) */
int _glMultiTexCoord2i_Comp(glContext, target, sCoord, t)
  undefined4 glContext;
  int target;
  uint sCoord;
  uint t;
{
  double dVar1;
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58));
    listRecord[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,t ^ 0x80000000) - dVar1));
  }
  return listRecord;
}

/* _glMultiTexCoord2i_CompExec @ 0x96868 (72 bytes) */
void _glMultiTexCoord2i_CompExec(glContext, target, sCoord, t)
  undefined4 glContext;
  undefined4 target;
  undefined4 sCoord;
  undefined4 t;
{
  ((int (*)())_glMultiTexCoord2i_Comp)(glContext,target,sCoord,t);
  ((void (*)())_glMultiTexCoord2i_Exec)(glContext,target,sCoord,t);
  return;
}

/* _glMultiTexCoord2iv_Exec @ 0x968b0 (120 bytes) */
double _glMultiTexCoord2iv_Exec(glContext, target, v)
  int glContext;
  uint target;
  uint *v;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  
  iVar2 = glContext + (target & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(iVar2 + 300) = uVar1;
  *(float *)(iVar2 + 0x124) = (float)dVar4;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord2iv_Comp @ 0x96928 (160 bytes) */
int _glMultiTexCoord2iv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  uint *v;
{
  double dVar1;
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58));
    listRecord[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - dVar1));
  }
  return listRecord;
}

/* _glMultiTexCoord2iv_CompExec @ 0x969c8 (64 bytes) */
void _glMultiTexCoord2iv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord2iv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord2iv_Exec)(glContext,target,v);
  return;
}

/* _glMultiTexCoord3i_Exec @ 0x96a08 (140 bytes) */
void _glMultiTexCoord3i_Exec(glContext, target, sCoord, t, r)
  int glContext;
  uint target;
  uint sCoord;
  uint t;
  uint r;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = glContext + (target & 7) * 0x10;
  dVar2 = (double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,r ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,t ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(iVar1 + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(iVar1 + 0x120) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar4;
  *(float *)(iVar1 + 0x124) = (float)dVar3;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  return;
}

/* _glMultiTexCoord3i_Comp @ 0x96a94 (188 bytes) */
int _glMultiTexCoord3i_Comp(glContext, target, sCoord, t, r)
  undefined4 glContext;
  int target;
  uint sCoord;
  uint t;
  uint r;
{
  double dVar1;
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58));
    listRecord[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,t ^ 0x80000000) - dVar1));
    listRecord[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,r ^ 0x80000000) - dVar1));
  }
  return listRecord;
}

/* _glMultiTexCoord3i_CompExec @ 0x96b50 (80 bytes) */
void _glMultiTexCoord3i_CompExec(glContext, target, sCoord, t, r)
  undefined4 glContext;
  undefined4 target;
  undefined4 sCoord;
  undefined4 t;
  undefined4 r;
{
  ((int (*)())_glMultiTexCoord3i_Comp)(glContext,target,sCoord,t,r);
  ((void (*)())_glMultiTexCoord3i_Exec)(glContext,target,sCoord,t,r);
  return;
}

/* _glMultiTexCoord3iv_Exec @ 0x96ba0 (152 bytes) */
double _glMultiTexCoord3iv_Exec(glContext, target, v)
  int glContext;
  uint target;
  uint *v;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = glContext + (target & 7) * 0x10;
  dVar2 = (double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(iVar1 + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(iVar1 + 0x120) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar4;
  *(float *)(iVar1 + 0x124) = (float)dVar3;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  return;
}

/* _glMultiTexCoord3iv_Comp @ 0x96c38 (192 bytes) */
int _glMultiTexCoord3iv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  uint *v;
{
  double dVar1;
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58));
    listRecord[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - dVar1));
    listRecord[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - dVar1));
  }
  return listRecord;
}

/* _glMultiTexCoord3iv_CompExec @ 0x96cf8 (64 bytes) */
void _glMultiTexCoord3iv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord3iv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord3iv_Exec)(glContext,target,v);
  return;
}

/* _glMultiTexCoord4i_Exec @ 0x96d38 (156 bytes) */
void _glMultiTexCoord4i_Exec(glContext, target, sCoord, t, r, q)
  int glContext;
  uint target;
  uint sCoord;
  uint t;
  uint r;
  uint q;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = glContext + (target & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,q ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,t ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,r ^ 0x80000000) - DOUBLE_00108d58;
  *(float *)(iVar1 + 0x120) =
       (float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58);
  *(float *)(iVar1 + 0x124) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar3;
  *(float *)(iVar1 + 300) = (float)dVar4;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  return;
}

/* _glMultiTexCoord4i_Comp @ 0x96dd4 (220 bytes) */
int _glMultiTexCoord4i_Comp(glContext, target, sCoord, t, r, q)
  undefined4 glContext;
  int target;
  uint sCoord;
  uint t;
  uint r;
  uint q;
{
  double dVar1;
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58));
    listRecord[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,t ^ 0x80000000) - dVar1));
    listRecord[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,r ^ 0x80000000) - dVar1));
    listRecord[4] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,q ^ 0x80000000) - dVar1));
  }
  return listRecord;
}

/* _glMultiTexCoord4i_CompExec @ 0x96eb0 (88 bytes) */
void _glMultiTexCoord4i_CompExec(glContext, target, sCoord, t, r, q)
  undefined4 glContext;
  undefined4 target;
  undefined4 sCoord;
  undefined4 t;
  undefined4 r;
  undefined4 q;
{
  ((int (*)())_glMultiTexCoord4i_Comp)(glContext,target,sCoord,t,r,q);
  ((void (*)())_glMultiTexCoord4i_Exec)(glContext,target,sCoord,t,r,q);
  return;
}

/* _glMultiTexCoord4iv_Exec @ 0x96f08 (172 bytes) */
double _glMultiTexCoord4iv_Exec(glContext, target, v)
  int glContext;
  uint target;
  uint *v;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = glContext + (target & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,v[3] ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - DOUBLE_00108d58;
  *(float *)(iVar1 + 0x120) =
       (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58);
  *(float *)(iVar1 + 0x124) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar3;
  *(float *)(iVar1 + 300) = (float)dVar4;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  return;
}

/* _glMultiTexCoord4iv_Comp @ 0x96fb4 (224 bytes) */
int _glMultiTexCoord4iv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  uint *v;
{
  double dVar1;
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58));
    listRecord[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - dVar1));
    listRecord[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - dVar1));
    listRecord[4] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,v[3] ^ 0x80000000) - dVar1));
  }
  return listRecord;
}

/* _glMultiTexCoord4iv_CompExec @ 0x97094 (64 bytes) */
void _glMultiTexCoord4iv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord4iv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord4iv_Exec)(glContext,target,v);
  return;
}

/* _glMultiTexCoord1s_Exec @ 0x970d4 (92 bytes) */
void _glMultiTexCoord1s_Exec(glContext, target, sCoord)
  int glContext;
  uint target;
  uint sCoord;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  
  iVar2 = glContext + (target & 7) * 0x10;
  dVar3 = (double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(iVar2 + 300) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = uVar1;
  *(undefined4 *)(iVar2 + 0x124) = uVar1;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord1s_Comp @ 0x97130 (124 bytes) */
int _glMultiTexCoord1s_Comp(glContext, target, sCoord)
  undefined4 glContext;
  int target;
  uint sCoord;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58));
  }
  return listRecord;
}

/* _glMultiTexCoord1s_CompExec @ 0x971ac (64 bytes) */
void _glMultiTexCoord1s_CompExec(glContext, target, sCoord)
  undefined4 glContext;
  undefined4 target;
  undefined4 sCoord;
{
  ((int (*)())_glMultiTexCoord1s_Comp)(glContext,target,sCoord);
  ((void (*)())_glMultiTexCoord1s_Exec)(glContext,target,sCoord);
  return;
}

/* _glMultiTexCoord1sv_Exec @ 0x971ec (96 bytes) */
double _glMultiTexCoord1sv_Exec(glContext, target, v)
  int glContext;
  uint target;
  short *v;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  
  iVar2 = glContext + (target & 7) * 0x10;
  dVar3 = (double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(iVar2 + 300) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = uVar1;
  *(undefined4 *)(iVar2 + 0x124) = uVar1;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord1sv_Comp @ 0x9724c (128 bytes) */
int _glMultiTexCoord1sv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  short *v;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                            DOUBLE_00108d58));
  }
  return listRecord;
}

/* _glMultiTexCoord1sv_CompExec @ 0x972cc (64 bytes) */
void _glMultiTexCoord1sv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord1sv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord1sv_Exec)(glContext,target,v);
  return;
}

/* _glMultiTexCoord2s_Exec @ 0x9730c (112 bytes) */
void _glMultiTexCoord2s_Exec(glContext, target, sCoord, t)
  int glContext;
  uint target;
  uint sCoord;
  uint t;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  
  iVar2 = glContext + (target & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,t ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(iVar2 + 300) = uVar1;
  *(float *)(iVar2 + 0x124) = (float)dVar4;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord2s_Comp @ 0x9737c (156 bytes) */
int _glMultiTexCoord2s_Comp(glContext, target, sCoord, t)
  undefined4 glContext;
  int target;
  uint sCoord;
  uint t;
{
  double dVar1;
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58));
    listRecord[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,t ^ 0x80000000) - dVar1));
  }
  return listRecord;
}

/* _glMultiTexCoord2s_CompExec @ 0x97418 (72 bytes) */
void _glMultiTexCoord2s_CompExec(glContext, target, sCoord, t)
  undefined4 glContext;
  undefined4 target;
  undefined4 sCoord;
  undefined4 t;
{
  ((int (*)())_glMultiTexCoord2s_Comp)(glContext,target,sCoord,t);
  ((void (*)())_glMultiTexCoord2s_Exec)(glContext,target,sCoord,t);
  return;
}

/* _glMultiTexCoord2sv_Exec @ 0x97460 (120 bytes) */
double _glMultiTexCoord2sv_Exec(glContext, target, v)
  int glContext;
  uint target;
  short *v;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  
  iVar2 = glContext + (target & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58;
  uVar1 = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(iVar2 + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(iVar2 + 300) = uVar1;
  *(float *)(iVar2 + 0x124) = (float)dVar4;
  *(float *)(iVar2 + 0x120) = (float)dVar3;
  return;
}

/* _glMultiTexCoord2sv_Comp @ 0x974d8 (160 bytes) */
int _glMultiTexCoord2sv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  short *v;
{
  double dVar1;
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                            DOUBLE_00108d58));
    listRecord[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - dVar1));
  }
  return listRecord;
}

/* _glMultiTexCoord2sv_CompExec @ 0x97578 (64 bytes) */
void _glMultiTexCoord2sv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord2sv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord2sv_Exec)(glContext,target,v);
  return;
}

/* _glMultiTexCoord3s_Exec @ 0x975b8 (140 bytes) */
void _glMultiTexCoord3s_Exec(glContext, target, sCoord, t, r)
  int glContext;
  uint target;
  uint sCoord;
  uint t;
  uint r;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = glContext + (target & 7) * 0x10;
  dVar2 = (double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,r ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,t ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(iVar1 + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(iVar1 + 0x120) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar4;
  *(float *)(iVar1 + 0x124) = (float)dVar3;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  return;
}

/* _glMultiTexCoord3s_Comp @ 0x97644 (188 bytes) */
int _glMultiTexCoord3s_Comp(glContext, target, sCoord, t, r)
  undefined4 glContext;
  int target;
  uint sCoord;
  uint t;
  uint r;
{
  double dVar1;
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58));
    listRecord[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,t ^ 0x80000000) - dVar1));
    listRecord[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,r ^ 0x80000000) - dVar1));
  }
  return listRecord;
}

/* _glMultiTexCoord3s_CompExec @ 0x97700 (80 bytes) */
void _glMultiTexCoord3s_CompExec(glContext, target, sCoord, t, r)
  undefined4 glContext;
  undefined4 target;
  undefined4 sCoord;
  undefined4 t;
  undefined4 r;
{
  ((int (*)())_glMultiTexCoord3s_Comp)(glContext,target,sCoord,t,r);
  ((void (*)())_glMultiTexCoord3s_Exec)(glContext,target,sCoord,t,r);
  return;
}

/* _glMultiTexCoord3sv_Exec @ 0x97750 (152 bytes) */
double _glMultiTexCoord3sv_Exec(glContext, target, v)
  int glContext;
  uint target;
  short *v;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = glContext + (target & 7) * 0x10;
  dVar2 = (double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(iVar1 + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(iVar1 + 0x120) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar4;
  *(float *)(iVar1 + 0x124) = (float)dVar3;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  return;
}

/* _glMultiTexCoord3sv_Comp @ 0x977e8 (192 bytes) */
int _glMultiTexCoord3sv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  short *v;
{
  double dVar1;
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                            DOUBLE_00108d58));
    listRecord[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - dVar1));
    listRecord[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - dVar1));
  }
  return listRecord;
}

/* _glMultiTexCoord3sv_CompExec @ 0x978a8 (64 bytes) */
void _glMultiTexCoord3sv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord3sv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord3sv_Exec)(glContext,target,v);
  return;
}

/* _glMultiTexCoord4s_Exec @ 0x978e8 (156 bytes) */
void _glMultiTexCoord4s_Exec(glContext, target, sCoord, t, r, q)
  int glContext;
  uint target;
  uint sCoord;
  uint t;
  uint r;
  uint q;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = glContext + (target & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,q ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,t ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,r ^ 0x80000000) - DOUBLE_00108d58;
  *(float *)(iVar1 + 0x120) =
       (float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58);
  *(float *)(iVar1 + 0x124) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar3;
  *(float *)(iVar1 + 300) = (float)dVar4;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  return;
}

/* _glMultiTexCoord4s_Comp @ 0x97984 (220 bytes) */
int _glMultiTexCoord4s_Comp(glContext, target, sCoord, t, r, q)
  undefined4 glContext;
  int target;
  uint sCoord;
  uint t;
  uint r;
  uint q;
{
  double dVar1;
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58));
    listRecord[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,t ^ 0x80000000) - dVar1));
    listRecord[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,r ^ 0x80000000) - dVar1));
    listRecord[4] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,q ^ 0x80000000) - dVar1));
  }
  return listRecord;
}

/* _glMultiTexCoord4s_CompExec @ 0x97a60 (88 bytes) */
void _glMultiTexCoord4s_CompExec(glContext, target, sCoord, t, r, q)
  undefined4 glContext;
  undefined4 target;
  undefined4 sCoord;
  undefined4 t;
  undefined4 r;
  undefined4 q;
{
  ((int (*)())_glMultiTexCoord4s_Comp)(glContext,target,sCoord,t,r,q);
  ((void (*)())_glMultiTexCoord4s_Exec)(glContext,target,sCoord,t,r,q);
  return;
}

/* _glMultiTexCoord4sv_Exec @ 0x97ab8 (172 bytes) */
double _glMultiTexCoord4sv_Exec(glContext, target, v)
  int glContext;
  uint target;
  short *v;
{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  iVar1 = glContext + (target & 7) * 0x10;
  dVar4 = (double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - DOUBLE_00108d58;
  *(float *)(iVar1 + 0x120) =
       (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58);
  *(float *)(iVar1 + 0x124) = (float)dVar2;
  *(float *)(iVar1 + 0x128) = (float)dVar3;
  *(float *)(iVar1 + 300) = (float)dVar4;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  return;
}

/* _glMultiTexCoord4sv_Comp @ 0x97b64 (224 bytes) */
int _glMultiTexCoord4sv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  short *v;
{
  double dVar1;
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    dVar1 = DOUBLE_00108d58;
    listRecord[1] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                            DOUBLE_00108d58));
    listRecord[2] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - dVar1));
    listRecord[3] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - dVar1));
    listRecord[4] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) - dVar1));
  }
  return listRecord;
}

/* _glMultiTexCoord4sv_CompExec @ 0x97c44 (64 bytes) */
void _glMultiTexCoord4sv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord4sv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord4sv_Exec)(glContext,target,v);
  return;
}

/* _glCopyTexSubImage1D_ListExec @ 0x97c84 (64 bytes) */
undefined4 _glCopyTexSubImage1D_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glCopyTexSubImage1D_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3],listRecord[4],listRecord[5],forwardedFloatArg1,
             forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 0x18;
}

/* _glCopyTexSubImage1D_Comp @ 0x97cc4 (116 bytes) */
int _glCopyTexSubImage1D_Comp(glContext, target, level, xoffset, x, y, width)
  undefined4 glContext;
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 x;
  undefined4 y;
  undefined4 width;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glCopyTexSubImage1D_ListExec_001103cc,0x18);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[5] = width;
    *listRecord = target;
    listRecord[1] = level;
    listRecord[2] = xoffset;
    listRecord[3] = x;
    listRecord[4] = y;
  }
  return listRecord;
}

