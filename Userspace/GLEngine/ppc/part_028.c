#include "decls.h"

/* _glTexCoord3d_Exec @ 0x936a0 (48 bytes) */
void _glTexCoord3d_Exec(int glContext,double sCoord,double t,double r)
{
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  *(float *)(glContext + 0x120) = (float)sCoord;
  *(float *)(glContext + 0x124) = (float)t;
  *(float *)(glContext + 0x128) = (float)r;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  return;
}

/* _glTexCoord3d_Comp @ 0x936d0 (128 bytes) */
float * _glTexCoord3d_Comp(undefined4 glContext,double sCoord,double t,double r)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord3_ListExec_001103b8,0xc);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)sCoord;
    listRecord[1] = (float)t;
    listRecord[2] = (float)r;
  }
  return listRecord;
}

/* _glTexCoord3d_CompExec @ 0x93750 (96 bytes) */
void _glTexCoord3d_CompExec(undefined4 glContext,double sCoord,double t,double r)
{
  ((float * (*)())_glTexCoord3d_Comp)(glContext,sCoord,t,r);
  ((void (*)())_glTexCoord3d_Exec)(glContext,sCoord,t,r);
  return;
}

/* _glTexCoord3dv_Exec @ 0x937b0 (60 bytes) */
void _glTexCoord3dv_Exec(glContext, v)
  int glContext;
  double *v;
{
  double dVar1;
  double dVar2;
  
  dVar1 = *v;
  dVar2 = v[1];
  *(float *)(glContext + 0x128) = (float)v[2];
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  *(float *)(glContext + 0x120) = (float)dVar1;
  *(float *)(glContext + 0x124) = (float)dVar2;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  return;
}

/* _glTexCoord3dv_Comp @ 0x937ec (108 bytes) */
int _glTexCoord3dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord3_ListExec_001103b8,0xc);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*v;
    listRecord[1] = (float)v[1];
    listRecord[2] = (float)v[2];
  }
  return listRecord;
}

/* _glTexCoord3dv_CompExec @ 0x93858 (56 bytes) */
void _glTexCoord3dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord3dv_Comp)(glContext,v);
  ((void (*)())_glTexCoord3dv_Exec)(glContext,v);
  return;
}

/* _glTexCoord4d_Exec @ 0x93890 (48 bytes) */
void _glTexCoord4d_Exec(int glContext,double sCoord,double t,double r,double q)
{
  *(float *)(glContext + 0x120) = (float)sCoord;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  *(float *)(glContext + 0x124) = (float)t;
  *(float *)(glContext + 0x128) = (float)r;
  *(float *)(glContext + 300) = (float)q;
  return;
}

/* _glTexCoord4d_Comp @ 0x938c0 (108 bytes) */
void _glTexCoord4d_Comp(undefined4 glContext,double sCoord,double t,double r,double q)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord4_ListExec_001103b4,0x10);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)sCoord;
    listRecord[1] = (float)t;
    listRecord[2] = (float)r;
    listRecord[3] = (float)q;
  }
  return;
}

/* _glTexCoord4d_CompExec @ 0x9392c (96 bytes) */
void _glTexCoord4d_CompExec(undefined4 glContext,double sCoord,double t,double r,double q)
{
  ((void (*)())_glTexCoord4d_Comp)(glContext,sCoord,t,r,q);
  ((void (*)())_glTexCoord4d_Exec)(glContext,sCoord,t,r,q);
  return;
}

/* _glTexCoord4dv_Exec @ 0x9398c (64 bytes) */
void _glTexCoord4dv_Exec(glContext, v)
  int glContext;
  double *v;
{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar1 = *v;
  dVar3 = v[1];
  dVar2 = v[2];
  *(float *)(glContext + 300) = (float)v[3];
  *(float *)(glContext + 0x120) = (float)dVar1;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  *(float *)(glContext + 0x124) = (float)dVar3;
  *(float *)(glContext + 0x128) = (float)dVar2;
  return;
}

/* _glTexCoord4dv_Comp @ 0x939cc (120 bytes) */
int _glTexCoord4dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord4_ListExec_001103b4,0x10);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*v;
    listRecord[1] = (float)v[1];
    listRecord[2] = (float)v[2];
    listRecord[3] = (float)v[3];
  }
  return listRecord;
}

/* _glTexCoord4dv_CompExec @ 0x93a44 (56 bytes) */
void _glTexCoord4dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord4dv_Comp)(glContext,v);
  ((void (*)())_glTexCoord4dv_Exec)(glContext,v);
  return;
}

/* _glTexCoord1f_Exec @ 0x93a7c (28 bytes) */
void _glTexCoord1f_Exec(int glContext,float sCoord)
{
  *(float *)(glContext + 0x120) = (float)sCoord;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(glContext + 0x124) = *(undefined4 *)(glContext + 0x20);
  return;
}

/* _glTexCoord1f_Comp @ 0x93a98 (84 bytes) */
float * _glTexCoord1f_Comp(undefined4 glContext,float sCoord)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord1_ListExec_001103c0,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)sCoord;
  }
  return listRecord;
}

/* _glTexCoord1f_CompExec @ 0x93aec (64 bytes) */
void _glTexCoord1f_CompExec(undefined4 glContext,float sCoord)
{
  ((float * (*)())_glTexCoord1f_Comp)(glContext,sCoord);
  ((void (*)())_glTexCoord1f_Exec)(glContext,sCoord);
  return;
}

/* _glTexCoord1fv_Exec @ 0x93b2c (32 bytes) */
void _glTexCoord1fv_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  *(undefined4 *)(glContext + 0x120) = *v;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(glContext + 0x124) = *(undefined4 *)(glContext + 0x20);
  return;
}

/* _glTexCoord1fv_Comp @ 0x93b4c (80 bytes) */
int _glTexCoord1fv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glTexCoord1_ListExec_001103c0,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *v;
  }
  return listRecord;
}

/* _glTexCoord1fv_CompExec @ 0x93b9c (56 bytes) */
void _glTexCoord1fv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord1fv_Comp)(glContext,v);
  ((void (*)())_glTexCoord1fv_Exec)(glContext,v);
  return;
}

/* _glTexCoord2f_CompExec @ 0x93bd4 (80 bytes) */
void _glTexCoord2f_CompExec(undefined4 glContext,float sCoord,float t)
{
  ((float * (*)())_glTexCoord2f_Comp)(glContext,sCoord,t);
  ((void (*)())_glTexCoord2f_Exec)(glContext,sCoord,t);
  return;
}

/* _glTexCoord2fv_Comp @ 0x93c24 (88 bytes) */
int _glTexCoord2fv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glTexCoord2_ListExec_001103bc,8);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *v;
    listRecord[1] = v[1];
  }
  return listRecord;
}

/* _glTexCoord2fv_CompExec @ 0x93c7c (56 bytes) */
void _glTexCoord2fv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord2fv_Comp)(glContext,v);
  _glTexCoord2fv_Exec(glContext,v);
  return;
}

/* _glTexCoord3f_Comp @ 0x93cb4 (116 bytes) */
float * _glTexCoord3f_Comp(undefined4 glContext,float sCoord,float t,float r)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord3_ListExec_001103b8,0xc);
  if (listRecord != (float *)0x0) {
    listRecord[2] = (float)r;
    *listRecord = (float)sCoord;
    listRecord[1] = (float)t;
  }
  return listRecord;
}

/* _glTexCoord3f_CompExec @ 0x93d28 (96 bytes) */
void _glTexCoord3f_CompExec(undefined4 glContext,float sCoord,float t,float r)
{
  ((float * (*)())_glTexCoord3f_Comp)(glContext,sCoord,t,r);
  ((void (*)())_glTexCoord3f_Exec)(glContext,sCoord,t,r);
  return;
}

/* _glTexCoord3fv_Exec @ 0x93d88 (48 bytes) */
void _glTexCoord3fv_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = v[2];
  uVar2 = *v;
  uVar3 = v[1];
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  *(undefined4 *)(glContext + 0x120) = uVar2;
  *(undefined4 *)(glContext + 0x124) = uVar3;
  *(undefined4 *)(glContext + 0x128) = uVar1;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  return;
}

/* _glTexCoord3fv_Comp @ 0x93db8 (96 bytes) */
int _glTexCoord3fv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glTexCoord3_ListExec_001103b8,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *v;
    listRecord[1] = v[1];
    listRecord[2] = v[2];
  }
  return listRecord;
}

/* _glTexCoord3fv_CompExec @ 0x93e18 (56 bytes) */
void _glTexCoord3fv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord3fv_Comp)(glContext,v);
  ((void (*)())_glTexCoord3fv_Exec)(glContext,v);
  return;
}

/* _glTexCoord4f_Exec @ 0x93e50 (32 bytes) */
void _glTexCoord4f_Exec(int glContext,float sCoord,float t,float r,float q)
{
  *(float *)(glContext + 0x120) = (float)sCoord;
  *(float *)(glContext + 0x124) = (float)t;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  *(float *)(glContext + 0x128) = (float)r;
  *(float *)(glContext + 300) = (float)q;
  return;
}

/* _glTexCoord4f_Comp @ 0x93e70 (92 bytes) */
void _glTexCoord4f_Comp(undefined4 glContext,float sCoord,float t,float r,float q)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord4_ListExec_001103b4,0x10);
  if (listRecord != (float *)0x0) {
    listRecord[3] = (float)q;
    *listRecord = (float)sCoord;
    listRecord[1] = (float)t;
    listRecord[2] = (float)r;
  }
  return;
}

/* _glTexCoord4f_CompExec @ 0x93ecc (96 bytes) */
void _glTexCoord4f_CompExec(undefined4 glContext,float sCoord,float t,float r,float q)
{
  ((void (*)())_glTexCoord4f_Comp)(glContext,sCoord,t,r,q);
  ((void (*)())_glTexCoord4f_Exec)(glContext,sCoord,t,r,q);
  return;
}

/* _glTexCoord4fv_Exec @ 0x93f2c (48 bytes) */
void _glTexCoord4fv_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = v[3];
  uVar2 = *v;
  uVar3 = v[1];
  uVar4 = v[2];
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  *(undefined4 *)(glContext + 0x120) = uVar2;
  *(undefined4 *)(glContext + 0x124) = uVar3;
  *(undefined4 *)(glContext + 0x128) = uVar4;
  *(undefined4 *)(glContext + 300) = uVar1;
  return;
}

/* _glTexCoord4fv_Comp @ 0x93f5c (104 bytes) */
int _glTexCoord4fv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glTexCoord4_ListExec_001103b4,0x10);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *v;
    listRecord[1] = v[1];
    listRecord[2] = v[2];
    listRecord[3] = v[3];
  }
  return listRecord;
}

/* _glTexCoord4fv_CompExec @ 0x93fc4 (56 bytes) */
void _glTexCoord4fv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord4fv_Comp)(glContext,v);
  ((void (*)())_glTexCoord4fv_Exec)(glContext,v);
  return;
}

/* _glTexCoord1i_Exec @ 0x93ffc (80 bytes) */
void _glTexCoord1i_Exec(glContext, sCoord)
  int glContext;
  uint sCoord;
{
  double dVar1;
  
  dVar1 = (double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(glContext + 0x124) = *(undefined4 *)(glContext + 0x20);
  *(float *)(glContext + 0x120) = (float)dVar1;
  return;
}

/* _glTexCoord1i_Comp @ 0x9404c (112 bytes) */
int _glTexCoord1i_Comp(glContext, sCoord)
  undefined4 glContext;
  uint sCoord;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord1_ListExec_001103c0,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58);
  }
  return listRecord;
}

/* _glTexCoord1i_CompExec @ 0x940bc (56 bytes) */
void _glTexCoord1i_CompExec(glContext, sCoord)
  undefined4 glContext;
  undefined4 sCoord;
{
  ((int (*)())_glTexCoord1i_Comp)(glContext,sCoord);
  ((void (*)())_glTexCoord1i_Exec)(glContext,sCoord);
  return;
}

/* _glTexCoord1iv_Exec @ 0x940f4 (84 bytes) */
void _glTexCoord1iv_Exec(glContext, v)
  int glContext;
  uint *v;
{
  double dVar1;
  
  dVar1 = (double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(glContext + 0x124) = *(undefined4 *)(glContext + 0x20);
  *(float *)(glContext + 0x120) = (float)dVar1;
  return;
}

/* _glTexCoord1iv_Comp @ 0x94148 (116 bytes) */
int _glTexCoord1iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord1_ListExec_001103c0,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58);
  }
  return listRecord;
}

/* _glTexCoord1iv_CompExec @ 0x941bc (56 bytes) */
void _glTexCoord1iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord1iv_Comp)(glContext,v);
  ((void (*)())_glTexCoord1iv_Exec)(glContext,v);
  return;
}

/* _glTexCoord2i_Exec @ 0x941f4 (100 bytes) */
void _glTexCoord2i_Exec(glContext, sCoord, t)
  int glContext;
  uint sCoord;
  uint t;
{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58;
  dVar1 = (double)CONCAT44(0x43300000,t ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x120) = (float)dVar2;
  *(float *)(glContext + 0x124) = (float)dVar1;
  return;
}

/* _glTexCoord2i_Comp @ 0x94258 (144 bytes) */
int _glTexCoord2i_Comp(glContext, sCoord, t)
  undefined4 glContext;
  uint sCoord;
  uint t;
{
  double dVar1;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord2_ListExec_001103bc,8);
  dVar1 = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,t ^ 0x80000000) - dVar1);
  }
  return listRecord;
}

/* _glTexCoord2i_CompExec @ 0x942e8 (64 bytes) */
void _glTexCoord2i_CompExec(glContext, sCoord, t)
  undefined4 glContext;
  undefined4 sCoord;
  undefined4 t;
{
  ((int (*)())_glTexCoord2i_Comp)(glContext,sCoord,t);
  ((void (*)())_glTexCoord2i_Exec)(glContext,sCoord,t);
  return;
}

/* _glTexCoord2iv_Exec @ 0x94328 (108 bytes) */
void _glTexCoord2iv_Exec(glContext, v)
  int glContext;
  uint *v;
{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58;
  dVar1 = (double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x120) = (float)dVar2;
  *(float *)(glContext + 0x124) = (float)dVar1;
  return;
}

/* _glTexCoord2iv_Comp @ 0x94394 (148 bytes) */
int _glTexCoord2iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  double dVar1;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord2_ListExec_001103bc,8);
  dVar1 = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - dVar1);
  }
  return listRecord;
}

/* _glTexCoord2iv_CompExec @ 0x94428 (56 bytes) */
void _glTexCoord2iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord2iv_Comp)(glContext,v);
  ((void (*)())_glTexCoord2iv_Exec)(glContext,v);
  return;
}

/* _glTexCoord3i_Exec @ 0x94460 (128 bytes) */
void _glTexCoord3i_Exec(glContext, sCoord, t, r)
  int glContext;
  uint sCoord;
  uint t;
  uint r;
{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar1 = (double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,r ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,t ^ 0x80000000) - DOUBLE_00108d58;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x120) = (float)dVar1;
  *(float *)(glContext + 0x128) = (float)dVar3;
  *(float *)(glContext + 0x124) = (float)dVar2;
  return;
}

/* _glTexCoord3i_Comp @ 0x944e0 (176 bytes) */
int _glTexCoord3i_Comp(glContext, sCoord, t, r)
  undefined4 glContext;
  uint sCoord;
  uint t;
  uint r;
{
  double dVar1;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord3_ListExec_001103b8,0xc);
  dVar1 = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,t ^ 0x80000000) - dVar1);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,r ^ 0x80000000) - dVar1);
  }
  return listRecord;
}

/* _glTexCoord3i_CompExec @ 0x94590 (72 bytes) */
void _glTexCoord3i_CompExec(glContext, sCoord, t, r)
  undefined4 glContext;
  undefined4 sCoord;
  undefined4 t;
  undefined4 r;
{
  ((int (*)())_glTexCoord3i_Comp)(glContext,sCoord,t,r);
  ((void (*)())_glTexCoord3i_Exec)(glContext,sCoord,t,r);
  return;
}

/* _glTexCoord3iv_Exec @ 0x945d8 (140 bytes) */
void _glTexCoord3iv_Exec(glContext, v)
  int glContext;
  uint *v;
{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar1 = (double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x120) = (float)dVar1;
  *(float *)(glContext + 0x128) = (float)dVar3;
  *(float *)(glContext + 0x124) = (float)dVar2;
  return;
}

/* _glTexCoord3iv_Comp @ 0x94664 (180 bytes) */
int _glTexCoord3iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  double dVar1;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord3_ListExec_001103b8,0xc);
  dVar1 = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - dVar1);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - dVar1);
  }
  return listRecord;
}

/* _glTexCoord3iv_CompExec @ 0x94718 (56 bytes) */
void _glTexCoord3iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord3iv_Comp)(glContext,v);
  ((void (*)())_glTexCoord3iv_Exec)(glContext,v);
  return;
}

/* _glTexCoord4i_Exec @ 0x94750 (144 bytes) */
void _glTexCoord4i_Exec(glContext, sCoord, t, r, q)
  int glContext;
  uint sCoord;
  uint t;
  uint r;
  uint q;
{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar1 = (double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,q ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,t ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,r ^ 0x80000000) - DOUBLE_00108d58;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  *(float *)(glContext + 0x120) = (float)dVar1;
  *(float *)(glContext + 0x124) = (float)dVar2;
  *(float *)(glContext + 0x128) = (float)dVar3;
  *(float *)(glContext + 300) = (float)dVar4;
  return;
}

/* _glTexCoord4i_Comp @ 0x947e0 (208 bytes) */
int _glTexCoord4i_Comp(glContext, sCoord, t, r, q)
  undefined4 glContext;
  uint sCoord;
  uint t;
  uint r;
  uint q;
{
  double dVar1;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord4_ListExec_001103b4,0x10);
  dVar1 = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,t ^ 0x80000000) - dVar1);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,r ^ 0x80000000) - dVar1);
    listRecord[3] = (float)((double)CONCAT44(0x43300000,q ^ 0x80000000) - dVar1);
  }
  return listRecord;
}

/* _glTexCoord4i_CompExec @ 0x948b0 (80 bytes) */
void _glTexCoord4i_CompExec(glContext, sCoord, t, r, q)
  undefined4 glContext;
  undefined4 sCoord;
  undefined4 t;
  undefined4 r;
  undefined4 q;
{
  ((int (*)())_glTexCoord4i_Comp)(glContext,sCoord,t,r,q);
  ((void (*)())_glTexCoord4i_Exec)(glContext,sCoord,t,r,q);
  return;
}

/* _glTexCoord4iv_Exec @ 0x94900 (160 bytes) */
void _glTexCoord4iv_Exec(glContext, v)
  int glContext;
  uint *v;
{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar1 = (double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,v[3] ^ 0x80000000) - DOUBLE_00108d58;
  dVar2 = (double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58;
  dVar3 = (double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - DOUBLE_00108d58;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  *(float *)(glContext + 0x120) = (float)dVar1;
  *(float *)(glContext + 0x124) = (float)dVar2;
  *(float *)(glContext + 0x128) = (float)dVar3;
  *(float *)(glContext + 300) = (float)dVar4;
  return;
}

/* _glTexCoord4iv_Comp @ 0x949a0 (212 bytes) */
int _glTexCoord4iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  double dVar1;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord4_ListExec_001103b4,0x10);
  dVar1 = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - dVar1);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - dVar1);
    listRecord[3] = (float)((double)CONCAT44(0x43300000,v[3] ^ 0x80000000) - dVar1);
  }
  return listRecord;
}

/* _glTexCoord4iv_CompExec @ 0x94a74 (56 bytes) */
void _glTexCoord4iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord4iv_Comp)(glContext,v);
  ((void (*)())_glTexCoord4iv_Exec)(glContext,v);
  return;
}

/* _glTexCoord1s_Exec @ 0x94aac (80 bytes) */
void _glTexCoord1s_Exec(glContext, sCoord)
  int glContext;
  uint sCoord;
{
  double dVar1;
  
  dVar1 = (double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(glContext + 0x124) = *(undefined4 *)(glContext + 0x20);
  *(float *)(glContext + 0x120) = (float)dVar1;
  return;
}

/* _glTexCoord1s_Comp @ 0x94afc (112 bytes) */
int _glTexCoord1s_Comp(glContext, sCoord)
  undefined4 glContext;
  uint sCoord;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord1_ListExec_001103c0,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58);
  }
  return listRecord;
}

/* _glTexCoord1s_CompExec @ 0x94b6c (56 bytes) */
void _glTexCoord1s_CompExec(glContext, sCoord)
  undefined4 glContext;
  undefined4 sCoord;
{
  ((int (*)())_glTexCoord1s_Comp)(glContext,sCoord);
  ((void (*)())_glTexCoord1s_Exec)(glContext,sCoord);
  return;
}

/* _glTexCoord1sv_Exec @ 0x94ba4 (84 bytes) */
void _glTexCoord1sv_Exec(glContext, v)
  int glContext;
  short *v;
{
  double dVar1;
  
  dVar1 = (double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(glContext + 0x124) = *(undefined4 *)(glContext + 0x20);
  *(float *)(glContext + 0x120) = (float)dVar1;
  return;
}

