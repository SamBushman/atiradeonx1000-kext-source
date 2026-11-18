#include "decls.h"

/* _glTexCoord1sv_Comp @ 0x94bf8 (116 bytes) */
int _glTexCoord1sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord1_ListExec_001103c0,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58);
  }
  return listRecord;
}

/* _glTexCoord1sv_CompExec @ 0x94c6c (56 bytes) */
void _glTexCoord1sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord1sv_Comp)(glContext,v);
  _glTexCoord1sv_Exec(glContext,v);
  return;
}

/* _glTexCoord2s_Exec @ 0x94ca4 (100 bytes) */
void _glTexCoord2s_Exec(glContext, sCoord, t)
  int glContext;
  uint sCoord;
  uint t;
{
  double texCoordT;
  double texCoordS;
  
  texCoordS = (double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58;
  texCoordT = (double)CONCAT44(0x43300000,t ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x120) = (float)texCoordS;
  *(float *)(glContext + 0x124) = (float)texCoordT;
  return;
}

/* _glTexCoord2s_Comp @ 0x94d08 (144 bytes) */
int _glTexCoord2s_Comp(glContext, sCoord, t)
  undefined4 glContext;
  uint sCoord;
  uint t;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord2_ListExec_001103bc,8);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,t ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glTexCoord2s_CompExec @ 0x94d98 (64 bytes) */
void _glTexCoord2s_CompExec(glContext, sCoord, t)
  undefined4 glContext;
  undefined4 sCoord;
  undefined4 t;
{
  ((int (*)())_glTexCoord2s_Comp)(glContext,sCoord,t);
  ((void (*)())_glTexCoord2s_Exec)(glContext,sCoord,t);
  return;
}

/* _glTexCoord2sv_Exec @ 0x94dd8 (108 bytes) */
void _glTexCoord2sv_Exec(glContext, v)
  int glContext;
  short *v;
{
  double texCoordT;
  double texCoordS;
  
  texCoordS = (double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58;
  texCoordT = (double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58;
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x120) = (float)texCoordS;
  *(float *)(glContext + 0x124) = (float)texCoordT;
  return;
}

/* _glTexCoord2sv_Comp @ 0x94e44 (148 bytes) */
int _glTexCoord2sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord2_ListExec_001103bc,8);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glTexCoord2sv_CompExec @ 0x94ed8 (56 bytes) */
void _glTexCoord2sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord2sv_Comp)(glContext,v);
  ((void (*)())_glTexCoord2sv_Exec)(glContext,v);
  return;
}

/* _glTexCoord3s_Exec @ 0x94f10 (128 bytes) */
void _glTexCoord3s_Exec(glContext, sCoord, t, r)
  int glContext;
  uint sCoord;
  uint t;
  uint r;
{
  double texCoordS;
  double texCoordT;
  double texCoordR;
  
  texCoordS = (double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58;
  texCoordR = (double)CONCAT44(0x43300000,r ^ 0x80000000) - DOUBLE_00108d58;
  texCoordT = (double)CONCAT44(0x43300000,t ^ 0x80000000) - DOUBLE_00108d58;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x120) = (float)texCoordS;
  *(float *)(glContext + 0x128) = (float)texCoordR;
  *(float *)(glContext + 0x124) = (float)texCoordT;
  return;
}

/* _glTexCoord3s_Comp @ 0x94f90 (176 bytes) */
int _glTexCoord3s_Comp(glContext, sCoord, t, r)
  undefined4 glContext;
  uint sCoord;
  uint t;
  uint r;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord3_ListExec_001103b8,0xc);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,t ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,r ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glTexCoord3s_CompExec @ 0x95040 (72 bytes) */
void _glTexCoord3s_CompExec(glContext, sCoord, t, r)
  undefined4 glContext;
  undefined4 sCoord;
  undefined4 t;
  undefined4 r;
{
  ((int (*)())_glTexCoord3s_Comp)(glContext,sCoord,t,r);
  ((void (*)())_glTexCoord3s_Exec)(glContext,sCoord,t,r);
  return;
}

/* _glTexCoord3sv_Exec @ 0x95088 (140 bytes) */
void _glTexCoord3sv_Exec(glContext, v)
  int glContext;
  short *v;
{
  double texCoordS;
  double texCoordT;
  double texCoordR;
  
  texCoordS = (double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58;
  texCoordR = (double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - DOUBLE_00108d58;
  texCoordT = (double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x120) = (float)texCoordS;
  *(float *)(glContext + 0x128) = (float)texCoordR;
  *(float *)(glContext + 0x124) = (float)texCoordT;
  return;
}

/* _glTexCoord3sv_Comp @ 0x95114 (180 bytes) */
int _glTexCoord3sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord3_ListExec_001103b8,0xc);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glTexCoord3sv_CompExec @ 0x951c8 (56 bytes) */
void _glTexCoord3sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord3sv_Comp)(glContext,v);
  ((void (*)())_glTexCoord3sv_Exec)(glContext,v);
  return;
}

/* _glTexCoord4s_Exec @ 0x95200 (144 bytes) */
void _glTexCoord4s_Exec(glContext, sCoord, t, r, q)
  int glContext;
  uint sCoord;
  uint t;
  uint r;
  uint q;
{
  double texCoordS;
  double texCoordT;
  double texCoordR;
  double texCoordQ;
  
  texCoordS = (double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58;
  texCoordQ = (double)CONCAT44(0x43300000,q ^ 0x80000000) - DOUBLE_00108d58;
  texCoordT = (double)CONCAT44(0x43300000,t ^ 0x80000000) - DOUBLE_00108d58;
  texCoordR = (double)CONCAT44(0x43300000,r ^ 0x80000000) - DOUBLE_00108d58;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  *(float *)(glContext + 0x120) = (float)texCoordS;
  *(float *)(glContext + 0x124) = (float)texCoordT;
  *(float *)(glContext + 0x128) = (float)texCoordR;
  *(float *)(glContext + 300) = (float)texCoordQ;
  return;
}

/* _glTexCoord4s_Comp @ 0x95290 (208 bytes) */
int _glTexCoord4s_Comp(glContext, sCoord, t, r, q)
  undefined4 glContext;
  uint sCoord;
  uint t;
  uint r;
  uint q;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord4_ListExec_001103b4,0x10);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,sCoord ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,t ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,r ^ 0x80000000) - intToDoubleBias);
    listRecord[3] = (float)((double)CONCAT44(0x43300000,q ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glTexCoord4s_CompExec @ 0x95360 (80 bytes) */
void _glTexCoord4s_CompExec(glContext, sCoord, t, r, q)
  undefined4 glContext;
  undefined4 sCoord;
  undefined4 t;
  undefined4 r;
  undefined4 q;
{
  ((int (*)())_glTexCoord4s_Comp)(glContext,sCoord,t,r,q);
  ((void (*)())_glTexCoord4s_Exec)(glContext,sCoord,t,r,q);
  return;
}

/* _glTexCoord4sv_Exec @ 0x953b0 (160 bytes) */
void _glTexCoord4sv_Exec(glContext, v)
  int glContext;
  short *v;
{
  double texCoordS;
  double texCoordT;
  double texCoordR;
  double texCoordQ;
  
  texCoordS = (double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58;
  texCoordQ = (double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) - DOUBLE_00108d58;
  texCoordT = (double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58;
  texCoordR = (double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - DOUBLE_00108d58;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  *(float *)(glContext + 0x120) = (float)texCoordS;
  *(float *)(glContext + 0x124) = (float)texCoordT;
  *(float *)(glContext + 0x128) = (float)texCoordR;
  *(float *)(glContext + 300) = (float)texCoordQ;
  return;
}

/* _glTexCoord4sv_Comp @ 0x95450 (212 bytes) */
int _glTexCoord4sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTexCoord4_ListExec_001103b4,0x10);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleBias);
    listRecord[3] = (float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glTexCoord4sv_CompExec @ 0x95524 (56 bytes) */
void _glTexCoord4sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glTexCoord4sv_Comp)(glContext,v);
  ((void (*)())_glTexCoord4sv_Exec)(glContext,v);
  return;
}

/* _glMultiTexCoord1_ListExec @ 0x9555c (52 bytes) */
int _glMultiTexCoord1_ListExec(glContext, listRecord)
  int glContext;
  uint *listRecord;
{
  undefined4 defaultTexCoordOne;
  undefined4 defaultTexCoordZero;
  int unitTexCoord;
  
  defaultTexCoordOne = *(undefined4 *)(glContext + 0x24);
  defaultTexCoordZero = *(undefined4 *)(glContext + 0x20);
  unitTexCoord = glContext + (*listRecord & 7) * 0x10;
  *(uint *)(unitTexCoord + 0x120) = listRecord[1];
  *(undefined4 *)(unitTexCoord + 300) = defaultTexCoordOne;
  *(undefined4 *)(unitTexCoord + 0x128) = defaultTexCoordZero;
  *(undefined4 *)(unitTexCoord + 0x124) = defaultTexCoordZero;
  return 8;
}

/* _glMultiTexCoord2_ListExec @ 0x95590 (56 bytes) */
int _glMultiTexCoord2_ListExec(glContext, listRecord)
  int glContext;
  uint *listRecord;
{
  undefined4 defaultTexCoordZero;
  uint texCoordT;
  uint texCoordS;
  int unitTexCoord;
  
  defaultTexCoordZero = *(undefined4 *)(glContext + 0x20);
  texCoordT = listRecord[2];
  unitTexCoord = glContext + (*listRecord & 7) * 0x10;
  texCoordS = listRecord[1];
  *(undefined4 *)(unitTexCoord + 300) = *(undefined4 *)(glContext + 0x24);
  *(uint *)(unitTexCoord + 0x120) = texCoordS;
  *(uint *)(unitTexCoord + 0x124) = texCoordT;
  *(undefined4 *)(unitTexCoord + 0x128) = defaultTexCoordZero;
  return 0xc;
}

/* _glMultiTexCoord3_ListExec @ 0x955c8 (72 bytes) */
int _glMultiTexCoord3_ListExec(glContext, listRecord)
  int glContext;
  uint *listRecord;
{
  uint texCoordR;
  uint texCoordT;
  undefined4 defaultTexCoordOne;
  int unitTexCoord;
  
  texCoordR = listRecord[3];
  texCoordT = listRecord[2];
  unitTexCoord = glContext + (*listRecord & 7) * 0x10;
  defaultTexCoordOne = *(undefined4 *)(glContext + 0x24);
  *(uint *)(unitTexCoord + 0x120) = listRecord[1];
  *(undefined4 *)(unitTexCoord + 300) = defaultTexCoordOne;
  *(uint *)(unitTexCoord + 0x124) = texCoordT;
  *(uint *)(unitTexCoord + 0x128) = texCoordR;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  return 0x10;
}

/* _glMultiTexCoord4_ListExec @ 0x95610 (72 bytes) */
int _glMultiTexCoord4_ListExec(glContext, listRecord)
  int glContext;
  uint *listRecord;
{
  uint texCoordQ;
  uint texCoordT;
  uint texCoordR;
  int unitTexCoord;
  
  texCoordQ = listRecord[4];
  texCoordT = listRecord[2];
  unitTexCoord = glContext + (*listRecord & 7) * 0x10;
  texCoordR = listRecord[3];
  *(uint *)(unitTexCoord + 0x120) = listRecord[1];
  *(uint *)(unitTexCoord + 300) = texCoordQ;
  *(uint *)(unitTexCoord + 0x124) = texCoordT;
  *(uint *)(unitTexCoord + 0x128) = texCoordR;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  return 0x14;
}

/* _glMultiTexCoord1d_Exec @ 0x95658 (44 bytes) */
void _glMultiTexCoord1d_Exec(int glContext,uint target,double sCoord)
{
  undefined4 defaultTexCoordOne;
  undefined4 defaultTexCoordZero;
  int unitTexCoord;
  
  defaultTexCoordOne = *(undefined4 *)(glContext + 0x24);
  unitTexCoord = glContext + (target & 7) * 0x10;
  defaultTexCoordZero = *(undefined4 *)(glContext + 0x20);
  *(float *)(unitTexCoord + 0x120) = (float)sCoord;
  *(undefined4 *)(unitTexCoord + 300) = defaultTexCoordOne;
  *(undefined4 *)(unitTexCoord + 0x128) = defaultTexCoordZero;
  *(undefined4 *)(unitTexCoord + 0x124) = defaultTexCoordZero;
  return;
}

/* _glMultiTexCoord1d_Comp @ 0x95684 (100 bytes) */
int * _glMultiTexCoord1d_Comp(undefined4 glContext,int target,double sCoord)
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)sCoord);
  }
  return listRecord;
}

/* _glMultiTexCoord1d_CompExec @ 0x956e8 (72 bytes) */
void _glMultiTexCoord1d_CompExec(undefined4 glContext,undefined4 target,double sCoord)
{
  ((int * (*)())_glMultiTexCoord1d_Comp)(glContext,target,sCoord);
  ((void (*)())_glMultiTexCoord1d_Exec)(glContext,target,sCoord);
  return;
}

/* _glMultiTexCoord1dv_Exec @ 0x95730 (48 bytes) */
double _glMultiTexCoord1dv_Exec(glContext, target, v)
  int glContext;
  uint target;
  double *v;
{
  undefined4 defaultTexCoordZero;
  int unitTexCoord;
  double texCoordS;
  
  texCoordS = *v;
  unitTexCoord = glContext + (target & 7) * 0x10;
  defaultTexCoordZero = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(unitTexCoord + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(unitTexCoord + 0x120) = (float)texCoordS;
  *(undefined4 *)(unitTexCoord + 0x128) = defaultTexCoordZero;
  *(undefined4 *)(unitTexCoord + 0x124) = defaultTexCoordZero;
  return;
}

/* _glMultiTexCoord1dv_Comp @ 0x95760 (96 bytes) */
int _glMultiTexCoord1dv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  double *v;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)*v);
  }
  return listRecord;
}

/* _glMultiTexCoord1dv_CompExec @ 0x957c0 (64 bytes) */
void _glMultiTexCoord1dv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord1dv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord1dv_Exec)(glContext,target,v);
  return;
}

/* _glMultiTexCoord2d_Exec @ 0x95800 (48 bytes) */
void _glMultiTexCoord2d_Exec(int glContext,uint target,double sCoord,double t)
{
  undefined4 defaultTexCoordOne;
  undefined4 defaultTexCoordZero;
  int unitTexCoord;
  
  defaultTexCoordOne = *(undefined4 *)(glContext + 0x24);
  defaultTexCoordZero = *(undefined4 *)(glContext + 0x20);
  unitTexCoord = glContext + (target & 7) * 0x10;
  *(float *)(unitTexCoord + 0x120) = (float)sCoord;
  *(undefined4 *)(unitTexCoord + 300) = defaultTexCoordOne;
  *(float *)(unitTexCoord + 0x124) = (float)t;
  *(undefined4 *)(unitTexCoord + 0x128) = defaultTexCoordZero;
  return;
}

/* _glMultiTexCoord2d_Comp @ 0x95830 (120 bytes) */
int * _glMultiTexCoord2d_Comp(undefined4 glContext,int target,double sCoord,double t)
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)sCoord);
    listRecord[2] = (int)GH_F2U((float)t);
  }
  return listRecord;
}

/* _glMultiTexCoord2d_CompExec @ 0x958a8 (88 bytes) */
void _glMultiTexCoord2d_CompExec(undefined4 glContext,undefined4 target,double sCoord,double t)
{
  ((int * (*)())_glMultiTexCoord2d_Comp)(glContext,target,sCoord,t);
  ((void (*)())_glMultiTexCoord2d_Exec)(glContext,target,sCoord,t);
  return;
}

/* _glMultiTexCoord2dv_Exec @ 0x95900 (56 bytes) */
double _glMultiTexCoord2dv_Exec(glContext, target, v)
  int glContext;
  uint target;
  double *v;
{
  undefined4 defaultTexCoordZero;
  int unitTexCoord;
  double texCoordS;
  double texCoordT;
  
  texCoordT = v[1];
  texCoordS = *v;
  unitTexCoord = glContext + (target & 7) * 0x10;
  defaultTexCoordZero = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(unitTexCoord + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(unitTexCoord + 0x120) = (float)texCoordS;
  *(float *)(unitTexCoord + 0x124) = (float)texCoordT;
  *(undefined4 *)(unitTexCoord + 0x128) = defaultTexCoordZero;
  return;
}

/* _glMultiTexCoord2dv_Comp @ 0x95938 (108 bytes) */
int _glMultiTexCoord2dv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  double *v;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)*v);
    listRecord[2] = (int)GH_F2U((float)v[1]);
  }
  return listRecord;
}

/* _glMultiTexCoord2dv_CompExec @ 0x959a4 (64 bytes) */
void _glMultiTexCoord2dv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord2dv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord2dv_Exec)(glContext,target,v);
  return;
}

/* _glMultiTexCoord3d_Exec @ 0x959e4 (60 bytes) */
void _glMultiTexCoord3d_Exec(int glContext,uint target,double sCoord,double t,double r)
{
  undefined4 defaultTexCoordOne;
  int unitTexCoord;
  
  defaultTexCoordOne = *(undefined4 *)(glContext + 0x24);
  unitTexCoord = glContext + (target & 7) * 0x10;
  *(float *)(unitTexCoord + 0x120) = (float)sCoord;
  *(undefined4 *)(unitTexCoord + 300) = defaultTexCoordOne;
  *(float *)(unitTexCoord + 0x124) = (float)t;
  *(float *)(unitTexCoord + 0x128) = (float)r;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  return;
}

/* _glMultiTexCoord3d_Comp @ 0x95a20 (140 bytes) */
int * _glMultiTexCoord3d_Comp(undefined4 glContext,int target,double sCoord,double t,double r)
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)sCoord);
    listRecord[2] = (int)GH_F2U((float)t);
    listRecord[3] = (int)GH_F2U((float)r);
  }
  return listRecord;
}

/* _glMultiTexCoord3d_CompExec @ 0x95aac (104 bytes) */
void _glMultiTexCoord3d_CompExec(undefined4 glContext,undefined4 target,double sCoord,double t,double r)
{
  ((int * (*)())_glMultiTexCoord3d_Comp)(glContext,target,sCoord,t,r);
  ((void (*)())_glMultiTexCoord3d_Exec)(glContext,target,sCoord,t,r);
  return;
}

/* _glMultiTexCoord3dv_Exec @ 0x95b14 (72 bytes) */
double _glMultiTexCoord3dv_Exec(glContext, target, v)
  int glContext;
  uint target;
  double *v;
{
  int unitTexCoord;
  double texCoordS;
  double texCoordR;
  double texCoordT;
  
  texCoordR = v[2];
  texCoordS = *v;
  unitTexCoord = glContext + (target & 7) * 0x10;
  texCoordT = v[1];
  *(undefined4 *)(unitTexCoord + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(unitTexCoord + 0x120) = (float)texCoordS;
  *(float *)(unitTexCoord + 0x124) = (float)texCoordT;
  *(float *)(unitTexCoord + 0x128) = (float)texCoordR;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  return;
}

/* _glMultiTexCoord3dv_Comp @ 0x95b5c (120 bytes) */
int _glMultiTexCoord3dv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  double *v;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord3_ListExec_001103a8,0x10);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)*v);
    listRecord[2] = (int)GH_F2U((float)v[1]);
    listRecord[3] = (int)GH_F2U((float)v[2]);
  }
  return listRecord;
}

/* _glMultiTexCoord3dv_CompExec @ 0x95bd4 (64 bytes) */
void _glMultiTexCoord3dv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord3dv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord3dv_Exec)(glContext,target,v);
  return;
}

/* _glMultiTexCoord4d_Exec @ 0x95c14 (60 bytes) */
void _glMultiTexCoord4d_Exec(int glContext,uint target,double sCoord,double t,double r,double q)
{
  int unitTexCoord;
  
  unitTexCoord = glContext + (target & 7) * 0x10;
  *(float *)(unitTexCoord + 0x120) = (float)sCoord;
  *(float *)(unitTexCoord + 0x124) = (float)t;
  *(float *)(unitTexCoord + 0x128) = (float)r;
  *(float *)(unitTexCoord + 300) = (float)q;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  return;
}

/* _glMultiTexCoord4d_Comp @ 0x95c50 (120 bytes) */
void _glMultiTexCoord4d_Comp(undefined4 glContext,int target,double sCoord,double t,double r,double q)
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)sCoord);
    listRecord[2] = (int)GH_F2U((float)t);
    listRecord[3] = (int)GH_F2U((float)r);
    listRecord[4] = (int)GH_F2U((float)q);
  }
  return;
}

/* _glMultiTexCoord4d_CompExec @ 0x95cc8 (104 bytes) */
void _glMultiTexCoord4d_CompExec(undefined4 glContext,undefined4 target,double sCoord,double t,double r,double q)
{
  ((void (*)())_glMultiTexCoord4d_Comp)(glContext,target,sCoord,t,r,q);
  ((void (*)())_glMultiTexCoord4d_Exec)(glContext,target,sCoord,t,r,q);
  return;
}

/* _glMultiTexCoord4dv_Exec @ 0x95d30 (76 bytes) */
double _glMultiTexCoord4dv_Exec(glContext, target, v)
  int glContext;
  uint target;
  double *v;
{
  int unitTexCoord;
  double texCoordS;
  double texCoordR;
  double texCoordT;
  
  texCoordS = *v;
  unitTexCoord = glContext + (target & 7) * 0x10;
  texCoordT = v[1];
  texCoordR = v[2];
  *(float *)(unitTexCoord + 300) = (float)v[3];
  *(float *)(unitTexCoord + 0x120) = (float)texCoordS;
  *(float *)(unitTexCoord + 0x124) = (float)texCoordT;
  *(float *)(unitTexCoord + 0x128) = (float)texCoordR;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  return;
}

/* _glMultiTexCoord4dv_Comp @ 0x95d7c (132 bytes) */
int _glMultiTexCoord4dv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  double *v;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord4_ListExec_001103a4,0x14);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)*v);
    listRecord[2] = (int)GH_F2U((float)v[1]);
    listRecord[3] = (int)GH_F2U((float)v[2]);
    listRecord[4] = (int)GH_F2U((float)v[3]);
  }
  return listRecord;
}

/* _glMultiTexCoord4dv_CompExec @ 0x95e00 (64 bytes) */
void _glMultiTexCoord4dv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord4dv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord4dv_Exec)(glContext,target,v);
  return;
}

/* _glMultiTexCoord1f_Exec @ 0x95e40 (40 bytes) */
void _glMultiTexCoord1f_Exec(int glContext,uint target,float sCoord)
{
  undefined4 defaultTexCoordOne;
  undefined4 defaultTexCoordZero;
  int unitTexCoord;
  
  defaultTexCoordOne = *(undefined4 *)(glContext + 0x24);
  defaultTexCoordZero = *(undefined4 *)(glContext + 0x20);
  unitTexCoord = glContext + (target & 7) * 0x10;
  *(float *)(unitTexCoord + 0x120) = (float)sCoord;
  *(undefined4 *)(unitTexCoord + 300) = defaultTexCoordOne;
  *(undefined4 *)(unitTexCoord + 0x128) = defaultTexCoordZero;
  *(undefined4 *)(unitTexCoord + 0x124) = defaultTexCoordZero;
  return;
}

/* _glMultiTexCoord1f_Comp @ 0x95e68 (96 bytes) */
int * _glMultiTexCoord1f_Comp(undefined4 glContext,int target,float sCoord)
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (listRecord != (int *)0x0) {
    listRecord[1] = (int)GH_F2U((float)sCoord);
    *listRecord = target + -0x84c0;
  }
  return listRecord;
}

/* _glMultiTexCoord1f_CompExec @ 0x95ec8 (72 bytes) */
void _glMultiTexCoord1f_CompExec(undefined4 glContext,undefined4 target,float sCoord)
{
  ((int * (*)())_glMultiTexCoord1f_Comp)(glContext,target,sCoord);
  ((void (*)())_glMultiTexCoord1f_Exec)(glContext,target,sCoord);
  return;
}

/* _glMultiTexCoord1fv_Exec @ 0x95f10 (44 bytes) */
double _glMultiTexCoord1fv_Exec(glContext, target, v)
  int glContext;
  uint target;
  undefined4 *v;
{
  undefined4 defaultTexCoordOne;
  undefined4 defaultTexCoordZero;
  int unitTexCoord;
  
  defaultTexCoordOne = *(undefined4 *)(glContext + 0x24);
  unitTexCoord = glContext + (target & 7) * 0x10;
  defaultTexCoordZero = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(unitTexCoord + 0x120) = *v;
  *(undefined4 *)(unitTexCoord + 300) = defaultTexCoordOne;
  *(undefined4 *)(unitTexCoord + 0x128) = defaultTexCoordZero;
  *(undefined4 *)(unitTexCoord + 0x124) = defaultTexCoordZero;
  return;
}

/* _glMultiTexCoord1fv_Comp @ 0x95f3c (92 bytes) */
int _glMultiTexCoord1fv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  int *v;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord1_ListExec_001103b0,8);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = *v;
  }
  return listRecord;
}

/* _glMultiTexCoord1fv_CompExec @ 0x95f98 (64 bytes) */
void _glMultiTexCoord1fv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord1fv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord1fv_Exec)(glContext,target,v);
  return;
}

/* _glMultiTexCoord2f_Comp @ 0x95fd8 (112 bytes) */
int * _glMultiTexCoord2f_Comp(undefined4 glContext,int target,float sCoord,float t)
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (listRecord != (int *)0x0) {
    listRecord[2] = (int)GH_F2U((float)t);
    *listRecord = target + -0x84c0;
    listRecord[1] = (int)GH_F2U((float)sCoord);
  }
  return listRecord;
}

/* _glMultiTexCoord2f_CompExec @ 0x96048 (88 bytes) */
void _glMultiTexCoord2f_CompExec(undefined4 glContext,undefined4 target,float sCoord,float t)
{
  ((int * (*)())_glMultiTexCoord2f_Comp)(glContext,target,sCoord,t);
  ((void (*)())_glMultiTexCoord2f_Exec)(glContext,target,sCoord,t);
  return;
}

/* _glMultiTexCoord2fv_Exec @ 0x960a0 (48 bytes) */
double _glMultiTexCoord2fv_Exec(glContext, target, v)
  int glContext;
  uint target;
  undefined4 *v;
{
  undefined4 texCoordT;
  undefined4 defaultTexCoordOne;
  undefined4 defaultTexCoordZero;
  int unitTexCoord;
  
  texCoordT = v[1];
  defaultTexCoordOne = *(undefined4 *)(glContext + 0x24);
  unitTexCoord = glContext + (target & 7) * 0x10;
  defaultTexCoordZero = *(undefined4 *)(glContext + 0x20);
  *(undefined4 *)(unitTexCoord + 0x120) = *v;
  *(undefined4 *)(unitTexCoord + 300) = defaultTexCoordOne;
  *(undefined4 *)(unitTexCoord + 0x124) = texCoordT;
  *(undefined4 *)(unitTexCoord + 0x128) = defaultTexCoordZero;
  return;
}

/* _glMultiTexCoord2fv_Comp @ 0x960d0 (100 bytes) */
int _glMultiTexCoord2fv_Comp(glContext, target, v)
  undefined4 glContext;
  int target;
  int *v;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glMultiTexCoord2_ListExec_001103ac,0xc);
  if (listRecord != (int *)0x0) {
    *listRecord = target + -0x84c0;
    listRecord[1] = *v;
    listRecord[2] = v[1];
  }
  return listRecord;
}

/* _glMultiTexCoord2fv_CompExec @ 0x96134 (64 bytes) */
void _glMultiTexCoord2fv_CompExec(glContext, target, v)
  undefined4 glContext;
  undefined4 target;
  undefined4 v;
{
  ((int (*)())_glMultiTexCoord2fv_Comp)(glContext,target,v);
  ((double (*)())_glMultiTexCoord2fv_Exec)(glContext,target,v);
  return;
}

/* _glMultiTexCoord3f_Exec @ 0x96174 (48 bytes) */
void _glMultiTexCoord3f_Exec(int glContext,uint target,float sCoord,float t,float r)
{
  undefined4 defaultTexCoordOne;
  int unitTexCoord;
  
  defaultTexCoordOne = *(undefined4 *)(glContext + 0x24);
  unitTexCoord = glContext + (target & 7) * 0x10;
  *(float *)(unitTexCoord + 0x120) = (float)sCoord;
  *(undefined4 *)(unitTexCoord + 300) = defaultTexCoordOne;
  *(float *)(unitTexCoord + 0x124) = (float)t;
  *(float *)(unitTexCoord + 0x128) = (float)r;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  return;
}

