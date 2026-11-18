#include "decls.h"

/* _glVertex4f_CompExec @ 0xa2370 (96 bytes) */
void _glVertex4f_CompExec(undefined4 glContext,float x,float y,float z,float w)
{
  ((void (*)())_glVertex4f_Comp)(glContext,x,y,z,w);
  _glVertex4f_Exec(glContext);
  return;
}

/* _glVertex4fv_Comp @ 0xa23d0 (104 bytes) */
int _glVertex4fv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertex4_ListExec_00110410,0x10);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *v;
    listRecord[1] = v[1];
    listRecord[2] = v[2];
    listRecord[3] = v[3];
  }
  return listRecord;
}

/* _glVertex4fv_CompExec @ 0xa2438 (56 bytes) */
void _glVertex4fv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glVertex4fv_Comp)(glContext,v);
  _glVertex4fv_Exec(glContext,v);
  return;
}

/* _glVertex2i_Comp @ 0xa2470 (144 bytes) */
int _glVertex2i_Comp(glContext, x, y)
  undefined4 glContext;
  uint x;
  uint y;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex2_ListExec_00110418,8);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glVertex2i_CompExec @ 0xa2500 (64 bytes) */
void _glVertex2i_CompExec(glContext, x, y)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
{
  ((int (*)())_glVertex2i_Comp)(glContext,x,y);
  _glVertex2i_Exec(glContext,x,y);
  return;
}

/* _glVertex2iv_Exec @ 0xa2540 (152 bytes) */
void _glVertex2iv_Exec(glContext, v)
  int glContext;
  uint *v;
{
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  code *pcVar1;
  
  pcVar1 = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    pcVar1 = *(code **)(glContext + 0x28);
  }
  (*pcVar1)(glContext,v,incomingR5,incomingR6,incomingR7,*(int *)(glContext + 0x4858),0x43300000,
            (double)(float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58),
            (double)*(float *)(glContext + 0x20),(double)*(float *)(glContext + 0x24));
  return;
}

/* _glVertex2iv_Comp @ 0xa25d8 (148 bytes) */
int _glVertex2iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex2_ListExec_00110418,8);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glVertex2iv_CompExec @ 0xa266c (56 bytes) */
void _glVertex2iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glVertex2iv_Comp)(glContext,v);
  ((void (*)())_glVertex2iv_Exec)(glContext,v);
  return;
}

/* _glVertex3i_Exec @ 0xa26a4 (160 bytes) */
void _glVertex3i_Exec(glContext, x, y, z)
  int glContext;
  uint x;
  uint y;
  uint z;
{
  undefined4 incomingR7;
  code *vertexFunc;
  
  vertexFunc = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    vertexFunc = *(code **)(glContext + 0x28);
  }
  (*vertexFunc)(glContext,x,y,z,incomingR7,*(int *)(glContext + 0x4858),z ^ 0x80000000,
            (double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - DOUBLE_00108d58),
            (double)*(float *)(glContext + 0x24));
  return;
}

/* _glVertex3i_Comp @ 0xa2744 (176 bytes) */
int _glVertex3i_Comp(glContext, x, y, z)
  undefined4 glContext;
  uint x;
  uint y;
  uint z;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex3_ListExec_00110414,0xc);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glVertex3i_CompExec @ 0xa27f4 (72 bytes) */
void _glVertex3i_CompExec(glContext, x, y, z)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 z;
{
  ((int (*)())_glVertex3i_Comp)(glContext,x,y,z);
  ((void (*)())_glVertex3i_Exec)(glContext,x,y,z);
  return;
}

/* _glVertex3iv_Exec @ 0xa283c (172 bytes) */
void _glVertex3iv_Exec(glContext, v)
  int glContext;
  uint *v;
{
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  code *pcVar1;
  
  pcVar1 = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    pcVar1 = *(code **)(glContext + 0x28);
  }
  (*pcVar1)(glContext,v,incomingR5,incomingR6,incomingR7,*(int *)(glContext + 0x4858),v[1] ^ 0x80000000,
            (double)(float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - DOUBLE_00108d58),
            (double)*(float *)(glContext + 0x24));
  return;
}

/* _glVertex3iv_Comp @ 0xa28e8 (180 bytes) */
int _glVertex3iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex3_ListExec_00110414,0xc);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glVertex3iv_CompExec @ 0xa299c (56 bytes) */
void _glVertex3iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glVertex3iv_Comp)(glContext,v);
  ((void (*)())_glVertex3iv_Exec)(glContext,v);
  return;
}

/* _glVertex4i_Exec @ 0xa29d4 (172 bytes) */
void _glVertex4i_Exec(glContext, x, y, z, w)
  int glContext;
  uint x;
  uint y;
  uint z;
  uint w;
{
  code *pcVar1;
  
  pcVar1 = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    pcVar1 = *(code **)(glContext + 0x28);
  }
  (*pcVar1)(glContext,x,y,z,w,*(int *)(glContext + 0x4858),z ^ 0x80000000,
            (double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,w ^ 0x80000000) - DOUBLE_00108d58));
  return;
}

/* _glVertex4i_Comp @ 0xa2a80 (208 bytes) */
int _glVertex4i_Comp(glContext, x, y, z, w)
  undefined4 glContext;
  uint x;
  uint y;
  uint z;
  uint w;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex4_ListExec_00110410,0x10);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - intToDoubleBias);
    listRecord[3] = (float)((double)CONCAT44(0x43300000,w ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glVertex4i_CompExec @ 0xa2b50 (80 bytes) */
void _glVertex4i_CompExec(glContext, x, y, z, w)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 z;
  undefined4 w;
{
  ((int (*)())_glVertex4i_Comp)(glContext,x,y,z,w);
  ((void (*)())_glVertex4i_Exec)(glContext,x,y,z,w);
  return;
}

/* _glVertex4iv_Exec @ 0xa2ba0 (188 bytes) */
void _glVertex4iv_Exec(glContext, v)
  int glContext;
  uint *v;
{
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  code *vertexFunc;
  
  vertexFunc = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    vertexFunc = *(code **)(glContext + 0x28);
  }
  (*vertexFunc)(glContext,v,incomingR5,incomingR6,incomingR7,*(int *)(glContext + 0x4858),v[2] ^ 0x80000000,
            (double)(float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,v[3] ^ 0x80000000) - DOUBLE_00108d58))
  ;
  return;
}

/* _glVertex4iv_Comp @ 0xa2c5c (212 bytes) */
int _glVertex4iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex4_ListExec_00110410,0x10);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - intToDoubleBias);
    listRecord[3] = (float)((double)CONCAT44(0x43300000,v[3] ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glVertex4iv_CompExec @ 0xa2d30 (56 bytes) */
void _glVertex4iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glVertex4iv_Comp)(glContext,v);
  ((void (*)())_glVertex4iv_Exec)(glContext,v);
  return;
}

/* _glVertex2s_Exec @ 0xa2d68 (144 bytes) */
void _glVertex2s_Exec(glContext, x, y)
  int glContext;
  uint x;
  uint y;
{
  code *vertexFunc;
  
  vertexFunc = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    vertexFunc = *(code **)(glContext + 0x28);
  }
  (*vertexFunc)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                   DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58),
            (double)*(float *)(glContext + 0x20),(double)*(float *)(glContext + 0x24));
  return;
}

/* _glVertex2s_Comp @ 0xa2df8 (144 bytes) */
int _glVertex2s_Comp(glContext, x, y)
  undefined4 glContext;
  uint x;
  uint y;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex2_ListExec_00110418,8);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glVertex2s_CompExec @ 0xa2e88 (64 bytes) */
void _glVertex2s_CompExec(glContext, x, y)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
{
  ((int (*)())_glVertex2s_Comp)(glContext,x,y);
  ((void (*)())_glVertex2s_Exec)(glContext,x,y);
  return;
}

/* _glVertex2sv_Exec @ 0xa2ec8 (152 bytes) */
void _glVertex2sv_Exec(glContext, v)
  int glContext;
  short *v;
{
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  code *pcVar1;
  
  pcVar1 = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    pcVar1 = *(code **)(glContext + 0x28);
  }
  (*pcVar1)(glContext,v,incomingR5,incomingR6,incomingR7,*(int *)(glContext + 0x4858),0x43300000,
            (double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                           DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                           DOUBLE_00108d58),(double)*(float *)(glContext + 0x20),
            (double)*(float *)(glContext + 0x24));
  return;
}

/* _glVertex2sv_Comp @ 0xa2f60 (148 bytes) */
int _glVertex2sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex2_ListExec_00110418,8);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glVertex2sv_CompExec @ 0xa2ff4 (56 bytes) */
void _glVertex2sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glVertex2sv_Comp)(glContext,v);
  ((void (*)())_glVertex2sv_Exec)(glContext,v);
  return;
}

/* _glVertex3s_Exec @ 0xa302c (160 bytes) */
void _glVertex3s_Exec(glContext, x, y, z)
  int glContext;
  uint x;
  uint y;
  uint z;
{
  undefined4 incomingR7;
  code *pcVar1;
  
  pcVar1 = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    pcVar1 = *(code **)(glContext + 0x28);
  }
  (*pcVar1)(glContext,x,y,z,incomingR7,*(int *)(glContext + 0x4858),z ^ 0x80000000,
            (double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - DOUBLE_00108d58),
            (double)*(float *)(glContext + 0x24));
  return;
}

/* _glVertex3s_Comp @ 0xa30cc (176 bytes) */
int _glVertex3s_Comp(glContext, x, y, z)
  undefined4 glContext;
  uint x;
  uint y;
  uint z;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex3_ListExec_00110414,0xc);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glVertex3s_CompExec @ 0xa317c (72 bytes) */
void _glVertex3s_CompExec(glContext, x, y, z)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 z;
{
  ((int (*)())_glVertex3s_Comp)(glContext,x,y,z);
  ((void (*)())_glVertex3s_Exec)(glContext,x,y,z);
  return;
}

/* _glVertex3sv_Exec @ 0xa31c4 (172 bytes) */
void _glVertex3sv_Exec(glContext, v)
  int glContext;
  short *v;
{
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  code *vertexFunc;
  
  vertexFunc = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    vertexFunc = *(code **)(glContext + 0x28);
  }
  (*vertexFunc)(glContext,v,incomingR5,incomingR6,incomingR7,*(int *)(glContext + 0x4858),
            (int)v[1] ^ 0x80000000U,
            (double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                           DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000U) -
                           DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) -
                           DOUBLE_00108d58),(double)*(float *)(glContext + 0x24));
  return;
}

/* _glVertex3sv_Comp @ 0xa3270 (180 bytes) */
int _glVertex3sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex3_ListExec_00110414,0xc);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glVertex3sv_CompExec @ 0xa3324 (56 bytes) */
void _glVertex3sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glVertex3sv_Comp)(glContext,v);
  ((void (*)())_glVertex3sv_Exec)(glContext,v);
  return;
}

/* _glVertex4s_Exec @ 0xa335c (172 bytes) */
void _glVertex4s_Exec(glContext, x, y, z, w)
  int glContext;
  uint x;
  uint y;
  uint z;
  uint w;
{
  code *pcVar1;
  
  pcVar1 = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    pcVar1 = *(code **)(glContext + 0x28);
  }
  (*pcVar1)(glContext,x,y,z,w,*(int *)(glContext + 0x4858),z ^ 0x80000000,
            (double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,w ^ 0x80000000) - DOUBLE_00108d58));
  return;
}

/* _glVertex4s_Comp @ 0xa3408 (208 bytes) */
int _glVertex4s_Comp(glContext, x, y, z, w)
  undefined4 glContext;
  uint x;
  uint y;
  uint z;
  uint w;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex4_ListExec_00110410,0x10);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - intToDoubleBias);
    listRecord[3] = (float)((double)CONCAT44(0x43300000,w ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glVertex4s_CompExec @ 0xa34d8 (80 bytes) */
void _glVertex4s_CompExec(glContext, x, y, z, w)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 z;
  undefined4 w;
{
  ((int (*)())_glVertex4s_Comp)(glContext,x,y,z,w);
  ((void (*)())_glVertex4s_Exec)(glContext,x,y,z,w);
  return;
}

/* _glVertex4sv_Exec @ 0xa3528 (188 bytes) */
void _glVertex4sv_Exec(glContext, v)
  int glContext;
  short *v;
{
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  code *pcVar1;
  
  pcVar1 = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    pcVar1 = *(code **)(glContext + 0x28);
  }
  (*pcVar1)(glContext,v,incomingR5,incomingR6,incomingR7,*(int *)(glContext + 0x4858),
            (int)v[2] ^ 0x80000000U,
            (double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                           DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                           DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000U) -
                           DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) -
                           DOUBLE_00108d58));
  return;
}

/* _glVertex4sv_Comp @ 0xa35e4 (212 bytes) */
int _glVertex4sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex4_ListExec_00110410,0x10);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleBias);
    listRecord[3] = (float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glVertex4sv_CompExec @ 0xa36b8 (56 bytes) */
void _glVertex4sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glVertex4sv_Comp)(glContext,v);
  ((void (*)())_glVertex4sv_Exec)(glContext,v);
  return;
}

/* _glElementPointerAPPLE_Exec @ 0xa36f0 (528 bytes) */
void _glElementPointerAPPLE_Exec(glContext, type, pointer)
  int glContext;
  uint type;
  int pointer;
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 glErrorCode;
  int clientState;
  int iVar4;
  int iVar5;
  int loopIndex;
  undefined4 *dstCursor;
  undefined4 *srcCursor;
  undefined4 *dstCursor2;
  int iVar8;
  
  clientState = *(int *)(glContext + 0x4a60);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (*(int *)(clientState + 0xd8) != pointer) {
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
    }
    *(int *)(clientState + 0xd8) = pointer;
    iVar8 = *(int *)(clientState + 0x35c);
    iVar5 = *(int *)(clientState + 0x37c);
    *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
    *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x800000;
    if (iVar8 != iVar5) {
      if ((iVar5 != 0) &&
         (iVar4 = *(int *)(iVar5 + 8) + -1, *(int *)(iVar5 + 8) = iVar4, iVar4 == 0)) {
        _gleFreeBufferObject(glContext,iVar5);
      }
      if (iVar8 == 0) {
        loopIndex = 0;
        *(undefined4 *)(clientState + 0x338) = *(undefined4 *)(clientState + 0x338);
        *(uint *)(clientState + 0x33c) = *(uint *)(clientState + 0x33c) & 0xff7fffff;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          dstCursor = (undefined4 *)(clientState + 0x3fc);
          do {
            *dstCursor = 0;
            loopIndex = loopIndex + 1;
            dstCursor = dstCursor + 0x23;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      else {
        *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
        *(undefined4 *)(clientState + 0x338) = *(undefined4 *)(clientState + 0x338);
        *(uint *)(clientState + 0x33c) = *(uint *)(clientState + 0x33c) | 0x800000;
        loopIndex = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          dstCursor2 = (undefined4 *)(clientState + 0x3fc);
          srcCursor = (undefined4 *)(iVar8 + 0x10);
          do {
            uVar2 = *srcCursor;
            loopIndex = loopIndex + 1;
            srcCursor = srcCursor + 1;
            *dstCursor2 = uVar2;
            dstCursor2 = dstCursor2 + 0x23;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      *(int *)(clientState + 0x37c) = iVar8;
      *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
      *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x10;
    }
    if (iVar8 != 0) {
      pointer = pointer + *(int *)(iVar8 + 0x30);
    }
    *(int *)(glContext + 0x4914) = pointer;
    if (*(uint *)(clientState + 0xec) == (type & 0xf)) {
      return;
    }
    if (type != 0x1403) {
      if (type < 0x1404) {
        bVar1 = type == 0x1401;
      }
      else {
        bVar1 = type == 0x1405;
      }
      if (!bVar1) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_000a38b8;
      }
    }
    *(uint *)(clientState + 0xec) = type & 0xf;
    *(undefined1 *)(clientState + 0xe4) = 1;
    *(short *)(clientState + 0xe0) = (short)type;
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
    *(undefined4 *)(glContext + 0x4894) = 0;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_000a38b8:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glNormalPointer_Exec @ 0xa3900 (708 bytes) */
void _glNormalPointer_Exec(glContext, type, stride, pointer)
  int glContext;
  code *type;
  int stride;
  int pointer;
{
  undefined4 uVar1;
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  int loopIndex;
  undefined4 *dstCursor;
  undefined4 *srcCursor;
  int clientState;
  undefined4 *dstCursor2;
  uint uVar7;
  int iVar8;
  
  clientState = *(int *)(glContext + 0x4a60);
  uVar7 = stride << 7 | (uint)type & 0xf;
  if (*(short *)(glContext + 0x4a10) < 0) {
    *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
    *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x20000;
    if (*(int *)(clientState + 0x48) != pointer) {
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
    }
    *(int *)(clientState + 0x48) = pointer;
    iVar8 = *(int *)(clientState + 0x358);
    iVar3 = *(int *)(clientState + 0x364);
    if (iVar8 != iVar3) {
      if ((iVar3 != 0) &&
         (iVar2 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar2, iVar2 == 0)) {
        _gleFreeBufferObject(glContext,iVar3);
      }
      if (iVar8 == 0) {
        loopIndex = 0;
        *(undefined4 *)(clientState + 0x338) = *(undefined4 *)(clientState + 0x338);
        *(uint *)(clientState + 0x33c) = *(uint *)(clientState + 0x33c) & 0xfffdffff;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          dstCursor = (undefined4 *)(clientState + 0x3e4);
          do {
            *dstCursor = 0;
            loopIndex = loopIndex + 1;
            dstCursor = dstCursor + 0x23;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      else {
        *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
        *(undefined4 *)(clientState + 0x338) = *(undefined4 *)(clientState + 0x338);
        *(uint *)(clientState + 0x33c) = *(uint *)(clientState + 0x33c) | 0x20000;
        loopIndex = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          dstCursor2 = (undefined4 *)(clientState + 0x3e4);
          srcCursor = (undefined4 *)(iVar8 + 0x10);
          do {
            uVar1 = *srcCursor;
            loopIndex = loopIndex + 1;
            srcCursor = srcCursor + 1;
            *dstCursor2 = uVar1;
            dstCursor2 = dstCursor2 + 0x23;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      *(int *)(clientState + 0x364) = iVar8;
      *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
      *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x10;
    }
    if (iVar8 != 0) {
      pointer = pointer + *(int *)(iVar8 + 0x30);
    }
    *(int *)(glContext + 0x48fc) = pointer;
    if (*(uint *)(clientState + 0x5c) == uVar7) {
      return;
    }
    if (-1 < stride) {
      switch((int)type) {
      case 0x1400:
        iVar3 = 1;
        type = (code *)0x9400;
        break;
      default:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_000a3b64;
      case 0x1402:
        iVar3 = 2;
        type = (code *)0x9402;
        break;
      case 0x1404:
        type = (code *)0x9404;
      case 0x1406:
        iVar3 = 4;
        break;
      case 0x140a:
        iVar3 = 8;
      }
      *(short *)(clientState + 0x50) = (short)type;
      *(char *)(clientState + 0x54) = (char)iVar3;
      if (stride < 1) {
        stride = iVar3 * 3;
      }
      *(uint *)(clientState + 0x5c) = uVar7;
      *(int *)(clientState + 0x4c) = stride;
      *(undefined4 *)(glContext + 0x488c) = 0;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
      *(undefined4 *)(glContext + 0x4890) = 0;
      *(undefined4 *)(glContext + 0x4894) = 0;
      if (*(int *)(glContext + 0x5408) != 0) {
        return;
      }
      uVar7 = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & uVar7 | *(uint *)(glContext + 0x4684) & ~uVar7) + 0xc) =
           PTR__glArrayElement_Exec_00110454;
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
LAB_000a3b64:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glSecondaryColorPointer_Exec @ 0xa3bf0 (720 bytes) */
void _glSecondaryColorPointer_Exec(glContext, size, type, stride, pointer)
  int glContext;
  uint size;
  uint type;
  int stride;
  int pointer;
{
  undefined4 uVar1;
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  int loopIndex;
  undefined4 *dstCursor;
  undefined4 *srcCursor;
  int clientState;
  undefined4 *dstCursor2;
  uint uVar7;
  int iVar8;
  
  clientState = *(int *)(glContext + 0x4a60);
  uVar7 = stride << 7 | type & 0xf | (size & 3) << 4;
  if (*(short *)(glContext + 0x4a10) < 0) {
    *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
    *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x100000;
    if (*(int *)(clientState + 0x90) != pointer) {
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
    }
    *(int *)(clientState + 0x90) = pointer;
    iVar8 = *(int *)(clientState + 0x358);
    iVar3 = *(int *)(clientState + 0x370);
    if (iVar8 != iVar3) {
      if ((iVar3 != 0) &&
         (iVar2 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar2, iVar2 == 0)) {
        _gleFreeBufferObject(glContext,iVar3);
      }
      if (iVar8 == 0) {
        loopIndex = 0;
        *(undefined4 *)(clientState + 0x338) = *(undefined4 *)(clientState + 0x338);
        *(uint *)(clientState + 0x33c) = *(uint *)(clientState + 0x33c) & 0xffefffff;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          dstCursor = (undefined4 *)(clientState + 0x3f0);
          do {
            *dstCursor = 0;
            loopIndex = loopIndex + 1;
            dstCursor = dstCursor + 0x23;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      else {
        *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
        *(undefined4 *)(clientState + 0x338) = *(undefined4 *)(clientState + 0x338);
        *(uint *)(clientState + 0x33c) = *(uint *)(clientState + 0x33c) | 0x100000;
        loopIndex = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          dstCursor2 = (undefined4 *)(clientState + 0x3f0);
          srcCursor = (undefined4 *)(iVar8 + 0x10);
          do {
            uVar1 = *srcCursor;
            loopIndex = loopIndex + 1;
            srcCursor = srcCursor + 1;
            *dstCursor2 = uVar1;
            dstCursor2 = dstCursor2 + 0x23;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      *(int *)(clientState + 0x370) = iVar8;
      *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
      *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x10;
    }
    if (iVar8 != 0) {
      pointer = pointer + *(int *)(iVar8 + 0x30);
    }
    *(int *)(glContext + 0x4908) = pointer;
    if (*(uint *)(clientState + 0xa4) == uVar7) {
      return;
    }
    if ((size == 3) && (-1 < stride)) {
      switch(type) {
      case 0x1400:
      case 0x1401:
        type = type | 0x8000;
        iVar3 = 1;
        break;
      case 0x1402:
      case 0x1403:
        type = type | 0x8000;
        iVar3 = 2;
        break;
      case 0x1404:
      case 0x1405:
        type = type | 0x8000;
      case 0x1406:
        iVar3 = 4;
        break;
      default:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_000a3e5c;
      case 0x140a:
        iVar3 = 8;
      }
      *(short *)(clientState + 0x98) = (short)type;
      *(char *)(clientState + 0x9c) = (char)iVar3;
      *(undefined2 *)(clientState + 0x9a) = 3;
      if (stride < 1) {
        stride = iVar3 * 3;
      }
      *(uint *)(clientState + 0xa4) = uVar7;
      *(int *)(clientState + 0x94) = stride;
      *(undefined4 *)(glContext + 0x488c) = 0;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
      *(undefined4 *)(glContext + 0x4890) = 0;
      *(undefined4 *)(glContext + 0x4894) = 0;
      if (*(int *)(glContext + 0x5408) != 0) {
        return;
      }
      uVar7 = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & uVar7 | *(uint *)(glContext + 0x4684) & ~uVar7) + 0xc) =
           PTR__glArrayElement_Exec_00110454;
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
LAB_000a3e5c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glFogCoordPointer_Exec @ 0xa3eec (648 bytes) */
void _glFogCoordPointer_Exec(glContext, type, stride, pointer)
  int glContext;
  uint type;
  int stride;
  int pointer;
{
  undefined4 pluginBufferHandle;
  undefined4 glErrorCode;
  int bufferRefCount;
  int previousBuffer;
  int elementSize;
  int loopIndex;
  undefined4 *dstCursor;
  undefined4 *srcCursor;
  int clientState;
  undefined4 *dstCursor2;
  uint strideTypeKey;
  uint dispatchSlotMask;
  int boundBuffer;
  
  clientState = *(int *)(glContext + 0x4a60);
  strideTypeKey = stride << 7 | type & 0xf;
  if (*(short *)(glContext + 0x4a10) < 0) {
    *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
    *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x80000;
    if (*(int *)(clientState + 0x78) != pointer) {
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
    }
    *(int *)(clientState + 0x78) = pointer;
    boundBuffer = *(int *)(clientState + 0x358);
    previousBuffer = *(int *)(clientState + 0x36c);
    if (boundBuffer != previousBuffer) {
      if ((previousBuffer != 0) &&
         (bufferRefCount = *(int *)(previousBuffer + 8) + -1, *(int *)(previousBuffer + 8) = bufferRefCount, bufferRefCount == 0)) {
        _gleFreeBufferObject(glContext,previousBuffer);
      }
      if (boundBuffer == 0) {
        loopIndex = 0;
        *(undefined4 *)(clientState + 0x338) = *(undefined4 *)(clientState + 0x338);
        *(uint *)(clientState + 0x33c) = *(uint *)(clientState + 0x33c) & 0xfff7ffff;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          dstCursor = (undefined4 *)(clientState + 0x3ec);
          do {
            *dstCursor = 0;
            loopIndex = loopIndex + 1;
            dstCursor = dstCursor + 0x23;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      else {
        *(int *)(boundBuffer + 8) = *(int *)(boundBuffer + 8) + 1;
        *(undefined4 *)(clientState + 0x338) = *(undefined4 *)(clientState + 0x338);
        *(uint *)(clientState + 0x33c) = *(uint *)(clientState + 0x33c) | 0x80000;
        loopIndex = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          dstCursor2 = (undefined4 *)(clientState + 0x3ec);
          srcCursor = (undefined4 *)(boundBuffer + 0x10);
          do {
            pluginBufferHandle = *srcCursor;
            loopIndex = loopIndex + 1;
            srcCursor = srcCursor + 1;
            *dstCursor2 = pluginBufferHandle;
            dstCursor2 = dstCursor2 + 0x23;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      *(int *)(clientState + 0x36c) = boundBuffer;
      *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
      *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x10;
    }
    if (boundBuffer != 0) {
      pointer = pointer + *(int *)(boundBuffer + 0x30);
    }
    *(int *)(glContext + 0x4904) = pointer;
    if (*(uint *)(clientState + 0x8c) == strideTypeKey) {
      return;
    }
    if (-1 < stride) {
      if (type == 0x1406) {
        elementSize = 4;
      }
      else {
        if (type != 0x140a) {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x500;
          goto LAB_000a40e8;
        }
        elementSize = 8;
      }
      *(short *)(clientState + 0x80) = (short)type;
      *(char *)(clientState + 0x84) = (char)elementSize;
      if (stride < 1) {
        stride = elementSize;
      }
      *(uint *)(clientState + 0x8c) = strideTypeKey;
      *(int *)(clientState + 0x7c) = stride;
      *(undefined4 *)(glContext + 0x488c) = 0;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
      *(undefined4 *)(glContext + 0x4890) = 0;
      *(undefined4 *)(glContext + 0x4894) = 0;
      if (*(int *)(glContext + 0x5408) != 0) {
        return;
      }
      dispatchSlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & dispatchSlotMask | *(uint *)(glContext + 0x4684) & ~dispatchSlotMask) + 0xc) =
           PTR__glArrayElement_Exec_00110454;
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
LAB_000a40e8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glWeightPointerARB_Exec @ 0xa4174 (724 bytes) */
void _glWeightPointerARB_Exec(glContext, size, type, stride, pointer)
  int glContext;
  uint size;
  uint type;
  int stride;
  int pointer;
{
  undefined4 uVar1;
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  int loopIndex;
  undefined4 *dstCursor;
  undefined4 *srcCursor;
  int clientState;
  undefined4 *dstCursor2;
  uint uVar7;
  int iVar8;
  
  clientState = *(int *)(glContext + 0x4a60);
  uVar7 = stride << 7 | type & 0xf | (size & 3) << 4;
  if (*(short *)(glContext + 0x4a10) < 0) {
    *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
    *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x200000;
    if (*(int *)(clientState + 0xa8) != pointer) {
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
    }
    *(int *)(clientState + 0xa8) = pointer;
    iVar8 = *(int *)(clientState + 0x358);
    iVar3 = *(int *)(clientState + 0x374);
    if (iVar8 != iVar3) {
      if ((iVar3 != 0) &&
         (iVar2 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar2, iVar2 == 0)) {
        _gleFreeBufferObject(glContext,iVar3);
      }
      if (iVar8 == 0) {
        loopIndex = 0;
        *(undefined4 *)(clientState + 0x338) = *(undefined4 *)(clientState + 0x338);
        *(uint *)(clientState + 0x33c) = *(uint *)(clientState + 0x33c) & 0xffdfffff;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          dstCursor = (undefined4 *)(clientState + 0x3f4);
          do {
            *dstCursor = 0;
            loopIndex = loopIndex + 1;
            dstCursor = dstCursor + 0x23;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      else {
        *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
        *(undefined4 *)(clientState + 0x338) = *(undefined4 *)(clientState + 0x338);
        *(uint *)(clientState + 0x33c) = *(uint *)(clientState + 0x33c) | 0x200000;
        loopIndex = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          dstCursor2 = (undefined4 *)(clientState + 0x3f4);
          srcCursor = (undefined4 *)(iVar8 + 0x10);
          do {
            uVar1 = *srcCursor;
            loopIndex = loopIndex + 1;
            srcCursor = srcCursor + 1;
            *dstCursor2 = uVar1;
            dstCursor2 = dstCursor2 + 0x23;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      *(int *)(clientState + 0x374) = iVar8;
      *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
      *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x10;
    }
    if (iVar8 != 0) {
      pointer = pointer + *(int *)(iVar8 + 0x30);
    }
    *(int *)(glContext + 0x490c) = pointer;
    if (*(uint *)(clientState + 0xbc) == uVar7) {
      return;
    }
    if ((size - 1 < 4) && (-1 < stride)) {
      switch(type) {
      case 0x1400:
      case 0x1401:
        type = type | 0x8000;
        iVar3 = 1;
        break;
      case 0x1402:
      case 0x1403:
        type = type | 0x8000;
        iVar3 = 2;
        break;
      case 0x1404:
      case 0x1405:
        type = type | 0x8000;
      case 0x1406:
        iVar3 = 4;
        break;
      default:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_000a43e4;
      case 0x140a:
        iVar3 = 8;
      }
      *(short *)(clientState + 0xb0) = (short)type;
      *(char *)(clientState + 0xb4) = (char)iVar3;
      *(short *)(clientState + 0xb2) = (short)size;
      if (stride < 1) {
        stride = size * iVar3;
      }
      *(uint *)(clientState + 0xbc) = uVar7;
      *(int *)(clientState + 0xac) = stride;
      *(undefined4 *)(glContext + 0x488c) = 0;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
      *(undefined4 *)(glContext + 0x4890) = 0;
      *(undefined4 *)(glContext + 0x4894) = 0;
      if (*(int *)(glContext + 0x5408) != 0) {
        return;
      }
      uVar7 = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & uVar7 | *(uint *)(glContext + 0x4684) & ~uVar7) + 0xc) =
           PTR__glArrayElement_Exec_00110454;
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
LAB_000a43e4:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glEdgeFlagPointer_Exec @ 0xa4474 (564 bytes) */
void _glEdgeFlagPointer_Exec(glContext, stride, pointer)
  int glContext;
  int stride;
  int pointer;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 glErrorCode;
  int clientState;
  int iVar4;
  int iVar5;
  int loopIndex;
  undefined4 *dstCursor;
  undefined4 *srcCursor;
  undefined4 *dstCursor2;
  int iVar8;
  
  clientState = *(int *)(glContext + 0x4a60);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < stride) {
      *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
      *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x400000;
      if (*(int *)(clientState + 0xc0) != pointer) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
      }
      *(int *)(clientState + 0xc0) = pointer;
      iVar8 = *(int *)(clientState + 0x358);
      iVar5 = *(int *)(clientState + 0x378);
      if (iVar8 != iVar5) {
        if ((iVar5 != 0) &&
           (iVar4 = *(int *)(iVar5 + 8) + -1, *(int *)(iVar5 + 8) = iVar4, iVar4 == 0)) {
          _gleFreeBufferObject(glContext,iVar5);
        }
        if (iVar8 == 0) {
          loopIndex = 0;
          *(undefined4 *)(clientState + 0x338) = *(undefined4 *)(clientState + 0x338);
          *(uint *)(clientState + 0x33c) = *(uint *)(clientState + 0x33c) & 0xffbfffff;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            dstCursor = (undefined4 *)(clientState + 0x3f8);
            do {
              *dstCursor = 0;
              loopIndex = loopIndex + 1;
              dstCursor = dstCursor + 0x23;
            } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
        else {
          *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
          *(undefined4 *)(clientState + 0x338) = *(undefined4 *)(clientState + 0x338);
          *(uint *)(clientState + 0x33c) = *(uint *)(clientState + 0x33c) | 0x400000;
          loopIndex = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            dstCursor2 = (undefined4 *)(clientState + 0x3f8);
            srcCursor = (undefined4 *)(iVar8 + 0x10);
            do {
              uVar2 = *srcCursor;
              loopIndex = loopIndex + 1;
              srcCursor = srcCursor + 1;
              *dstCursor2 = uVar2;
              dstCursor2 = dstCursor2 + 0x23;
            } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
        *(int *)(clientState + 0x378) = iVar8;
        *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
        *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x10;
      }
      if (iVar8 != 0) {
        pointer = pointer + *(int *)(iVar8 + 0x30);
      }
      *(int *)(glContext + 0x4910) = pointer;
      if (stride < 1) {
        stride = 1;
      }
      if (stride == *(int *)(clientState + 0xc4)) {
        return;
      }
      *(int *)(clientState + 0xc4) = stride;
      *(undefined4 *)(glContext + 0x488c) = 0;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
      *(undefined4 *)(glContext + 0x4890) = 0;
      *(undefined4 *)(glContext + 0x4894) = 0;
      if (*(int *)(glContext + 0x5408) != 0) {
        return;
      }
      uVar1 = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc) == 0);
      *(undefined **)
       ((*(uint *)(glContext + 0x4680) & uVar1 | *(uint *)(glContext + 0x4684) & ~uVar1) + 0xc) =
           PTR__glArrayElement_Exec_00110454;
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

/* _glVertexAttribPointerARB_Exec @ 0xa46a8 (892 bytes) */
void _glVertexAttribPointerARB_Exec(glContext, index, size, type, normalized, stride, pointer)
  int glContext;
  uint index;
  uint size;
  uint type;
  uint normalized;
  int stride;
  int pointer;
{
  int slotByteOffset;
  undefined4 copiedWord;
  undefined4 savedWord350;
  undefined4 glErrorCode;
  ushort typeFlags;
  uint attribBit;
  uint savedWord354;
  int attribRecord;
  int newRefCount;
  int oldBufferObject;
  int loopIndex;
  undefined4 *dstCursor;
  undefined4 *srcCursor;
  int iVar9;
  int clientState;
  undefined4 *dstCursor2;
  uint packedFormat;
  uint selectMask;
  int slot;
  int newBufferObject;
  int attribArrayBase;
  
  clientState = *(int *)(glContext + 0x4a60);
  packedFormat = stride << 7 | type & 0xf | (size & 3) << 4 | (normalized & 1) << 6;
  attribArrayBase = clientState + 0x10;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_000a49a4:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  slot = index + 0x10;
  if (((0xf < index) || (3 < size - 1)) || (stride < 0)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_000a49a4;
  }
  attribBit = 1 << (index & 0x3f);
  *(uint *)(clientState + 0x350) = *(uint *)(clientState + 0x350) | attribBit;
  *(undefined4 *)(clientState + 0x354) = *(undefined4 *)(clientState + 0x354);
  attribRecord = attribArrayBase + slot * 0x18;
  if (*(int *)(attribRecord + 0x20) != pointer) {
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
  }
  slotByteOffset = slot * 4;
  *(int *)(attribRecord + 0x20) = pointer;
  oldBufferObject = *(int *)(slotByteOffset + attribArrayBase + 0x350);
  newBufferObject = *(int *)(clientState + 0x358);
  if (newBufferObject != oldBufferObject) {
    if ((oldBufferObject != 0) && (newRefCount = *(int *)(oldBufferObject + 8) + -1, *(int *)(oldBufferObject + 8) = newRefCount, newRefCount == 0))
    {
      _gleFreeBufferObject(glContext,oldBufferObject);
    }
    if (newBufferObject == 0) {
      *(uint *)(clientState + 0x338) = *(uint *)(clientState + 0x338) & ~attribBit;
      *(undefined4 *)(clientState + 0x33c) = *(undefined4 *)(clientState + 0x33c);
      loopIndex = 0;
      if (*(char *)(glContext + 0x85a4) != '\0') {
        dstCursor = (undefined4 *)(slot * 4 + attribArrayBase + 0x3d0);
        do {
          *dstCursor = 0;
          loopIndex = loopIndex + 1;
          dstCursor = dstCursor + 0x23;
        } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
      }
    }
    else {
      *(int *)(newBufferObject + 8) = *(int *)(newBufferObject + 8) + 1;
      *(uint *)(clientState + 0x338) = *(uint *)(clientState + 0x338) | attribBit;
      *(undefined4 *)(clientState + 0x33c) = *(undefined4 *)(clientState + 0x33c);
      loopIndex = 0;
      if (*(char *)(glContext + 0x85a4) != '\0') {
        srcCursor = (undefined4 *)(newBufferObject + 0x10);
        dstCursor2 = (undefined4 *)(slot * 4 + attribArrayBase + 0x3d0);
        do {
          copiedWord = *srcCursor;
          loopIndex = loopIndex + 1;
          srcCursor = srcCursor + 1;
          *dstCursor2 = copiedWord;
          dstCursor2 = dstCursor2 + 0x23;
        } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
      }
    }
    savedWord350 = *(undefined4 *)(clientState + 0x350);
    savedWord354 = *(uint *)(clientState + 0x354);
    *(int *)(slotByteOffset + attribArrayBase + 0x350) = newBufferObject;
    *(undefined4 *)(clientState + 0x350) = savedWord350;
    *(uint *)(clientState + 0x354) = savedWord354 | 0x10;
  }
  if (newBufferObject != 0) {
    pointer = pointer + *(int *)(newBufferObject + 0x30);
  }
  *(int *)(slotByteOffset + glContext + 0x48f8) = pointer;
  if (*(uint *)(attribRecord + 0x34) == packedFormat) {
    return;
  }
  switch(type) {
  case 0x1400:
  case 0x1401:
    iVar9 = 1;
    break;
  case 0x1402:
  case 0x1403:
    iVar9 = 2;
    break;
  case 0x1404:
  case 0x1405:
    iVar9 = 4;
    break;
  case 0x1406:
    iVar9 = 4;
    goto LAB_000a4974;
  default:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_000a49a4;
  case 0x140a:
    iVar9 = 8;
LAB_000a4974:
    normalized = 0;
  }
  *(char *)(attribRecord + 0x2c) = (char)iVar9;
  typeFlags = (ushort)type;
  if (normalized != 0) {
    typeFlags = typeFlags | 0x8000;
  }
  *(ushort *)(attribRecord + 0x28) = typeFlags;
  *(short *)(attribRecord + 0x2a) = (short)size;
  if (stride < 1) {
    stride = size * iVar9;
  }
  *(uint *)(attribRecord + 0x34) = packedFormat;
  *(int *)(attribRecord + 0x24) = stride;
  *(undefined4 *)(glContext + 0x488c) = 0;
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
  *(undefined4 *)(glContext + 0x4890) = 0;
  *(undefined4 *)(glContext + 0x4894) = 0;
  if (*(int *)(glContext + 0x5408) == 0) {
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0xc) =
         PTR__glArrayElement_Exec_00110454;
  }
  return;
}

/* _glIndexPointer_Exec @ 0xa4a50 (308 bytes) */
void _glIndexPointer_Exec(glContext, type, stride, pointer)
  int glContext;
  undefined4 type;
  int stride;
  undefined4 pointer;
{
  undefined4 uVar1;
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < stride) {
      switch(type) {
      case 0x1401:
        uVar1 = 1;
        break;
      case 0x1402:
        uVar1 = 2;
        break;
      default:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_000a4b28;
      case 0x1404:
      case 0x1406:
        uVar1 = 4;
        break;
      case 0x140a:
        uVar1 = 8;
      }
      *(undefined4 *)(glContext + 0x48e0) = pointer;
      *(short *)(glContext + 0x48e8) = (short)type;
      if (stride < 1) {
        *(undefined4 *)(glContext + 0x48e4) = uVar1;
      }
      else {
        *(int *)(glContext + 0x48e4) = stride;
      }
      iVar3 = *(int *)(glContext + 0x48f4);
      iVar4 = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
      if (iVar4 == iVar3) {
        return;
      }
      if ((iVar3 != 0) &&
         (iVar2 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar2, iVar2 == 0)) {
        _gleFreeBufferObject(glContext,iVar3);
      }
      if (iVar4 != 0) {
        *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 1;
      }
      *(int *)(glContext + 0x48f4) = iVar4;
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
LAB_000a4b28:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glInterleavedArrays_Exec @ 0xa4bac (1236 bytes) */
void _glInterleavedArrays_Exec(glContext, format, stride, pointer)
  int glContext;
  undefined4 format;
  int stride;
  int pointer;
{
  bool hasTexCoord;
  bool hasColor;
  bool hasNormal;
  int vertexStride;
  undefined4 vertexSize;
  int normalOffset;
  int colorOffset;
  undefined4 texCoordSize;
  undefined4 glErrorCode;
  undefined4 colorSize;
  undefined4 colorType;
  int vertexOffset;
  
  hasTexCoord = false;
  hasColor = false;
  hasNormal = false;
  colorType = 0x1406;
  texCoordSize = 0;
  colorSize = 0;
  colorOffset = 0;
  normalOffset = 0;
  vertexOffset = 0;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_000a4f70:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  switch(format) {
  case 0x2a20:
    vertexStride = _gleTypeSize(glContext,0x1406);
    vertexStride = vertexStride << 1;
    break;
  case 0x2a21:
    vertexStride = _gleTypeSize(glContext,0x1406);
    vertexStride = vertexStride * 3;
    goto LAB_000a4ef0;
  case 0x2a22:
    hasColor = true;
    vertexOffset = _gleTypeSize(glContext,0x1401);
    vertexOffset = vertexOffset * 4;
    vertexStride = _gleTypeSize(glContext,0x1406);
    colorSize = 4;
    colorType = 0x1401;
    vertexStride = vertexOffset + vertexStride * 2;
    break;
  case 0x2a23:
    vertexOffset = _gleTypeSize(glContext,0x1401);
    vertexOffset = vertexOffset << 2;
    vertexStride = _gleTypeSize(glContext,0x1406);
    goto LAB_000a4df4;
  case 0x2a24:
    vertexOffset = _gleTypeSize(glContext,0x1406);
    vertexOffset = vertexOffset * 3;
    goto LAB_000a4e38;
  case 0x2a25:
    hasNormal = true;
    vertexOffset = _gleTypeSize(glContext,0x1406);
    vertexOffset = vertexOffset * 3;
    vertexStride = _gleTypeSize(glContext,0x1406);
    goto LAB_000a4d80;
  case 0x2a26:
    normalOffset = _gleTypeSize(glContext,0x1406);
    normalOffset = normalOffset * 4;
    vertexOffset = _gleTypeSize(glContext,0x1406);
    vertexOffset = normalOffset + vertexOffset * 3;
    vertexStride = _gleTypeSize(glContext,0x1406);
    goto LAB_000a4ee0;
  case 0x2a27:
    hasTexCoord = true;
    vertexOffset = _gleTypeSize(glContext,0x1406);
    vertexOffset = vertexOffset << 1;
    vertexStride = _gleTypeSize(glContext,0x1406);
    texCoordSize = 2;
LAB_000a4d80:
    vertexStride = vertexOffset + vertexStride * 3;
    goto LAB_000a4ef0;
  case 0x2a28:
    vertexOffset = _gleTypeSize(glContext,0x1406);
    vertexOffset = vertexOffset * 4;
    vertexStride = _gleTypeSize(glContext,0x1406);
    vertexStride = vertexOffset + vertexStride * 4;
    goto LAB_000a4f58;
  case 0x2a29:
    hasTexCoord = true;
    colorOffset = _gleTypeSize(glContext,0x1406);
    colorOffset = colorOffset * 2;
    vertexOffset = _gleTypeSize(glContext,0x1401);
    vertexOffset = colorOffset + vertexOffset * 4;
    vertexStride = _gleTypeSize(glContext,0x1406);
    texCoordSize = 2;
LAB_000a4df4:
    hasColor = true;
    vertexStride = vertexOffset + vertexStride * 3;
    colorSize = 4;
    colorType = 0x1401;
LAB_000a4ef0:
    vertexSize = 3;
    goto LAB_000a4f78;
  case 0x2a2a:
    hasTexCoord = true;
    colorOffset = _gleTypeSize(glContext,0x1406);
    colorOffset = colorOffset * 2;
    vertexOffset = _gleTypeSize(glContext,0x1406);
    texCoordSize = 2;
    vertexOffset = colorOffset + vertexOffset * 3;
LAB_000a4e38:
    hasColor = true;
    vertexStride = _gleTypeSize(glContext,0x1406);
    vertexStride = vertexOffset + vertexStride * 3;
    colorSize = 3;
    colorType = 0x1406;
    goto LAB_000a4ef0;
  case 0x2a2b:
    hasTexCoord = true;
    normalOffset = _gleTypeSize(glContext,0x1406);
    normalOffset = normalOffset * 2;
    vertexOffset = _gleTypeSize(glContext,0x1406);
    texCoordSize = 2;
    vertexOffset = normalOffset + vertexOffset * 3;
    vertexStride = _gleTypeSize(glContext,0x1406);
    vertexStride = vertexOffset + vertexStride * 3;
    goto LAB_000a4eec;
  case 0x2a2c:
    hasTexCoord = true;
    colorOffset = _gleTypeSize(glContext,0x1406);
    colorOffset = colorOffset * 2;
    normalOffset = _gleTypeSize(glContext,0x1406);
    normalOffset = colorOffset + normalOffset * 4;
    vertexOffset = _gleTypeSize(glContext,0x1406);
    texCoordSize = 2;
    vertexOffset = normalOffset + vertexOffset * 3;
    vertexStride = _gleTypeSize(glContext,0x1406);
LAB_000a4ee0:
    hasColor = true;
    vertexStride = vertexOffset + vertexStride * 3;
    colorSize = 4;
LAB_000a4eec:
    colorType = 0x1406;
    hasNormal = true;
    goto LAB_000a4ef0;
  case 0x2a2d:
    colorOffset = _gleTypeSize(glContext,0x1406);
    colorOffset = colorOffset * 4;
    normalOffset = _gleTypeSize(glContext,0x1406);
    normalOffset = colorOffset + normalOffset * 4;
    vertexOffset = _gleTypeSize(glContext,0x1406);
    vertexOffset = normalOffset + vertexOffset * 3;
    vertexStride = _gleTypeSize(glContext,0x1406);
    hasColor = true;
    vertexStride = vertexOffset + vertexStride * 4;
    colorSize = 4;
    hasNormal = true;
LAB_000a4f58:
    colorType = 0x1406;
    texCoordSize = 4;
    hasTexCoord = true;
    vertexSize = 4;
    goto LAB_000a4f78;
  default:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_000a4f70;
  }
  vertexSize = 2;
LAB_000a4f78:
  if (stride == 0) {
    stride = vertexStride;
  }
  _glDisableClientState_Exec(glContext,0x8079);
  _glDisableClientState_Exec(glContext,0x8077);
  if (hasTexCoord) {
    _glEnableClientState_Exec(glContext,0x8078);
    _glTexCoordPointer_Exec(glContext,texCoordSize,0x1406,stride,pointer);
  }
  else {
    _glDisableClientState_Exec(glContext,0x8078);
  }
  if (hasColor) {
    _glEnableClientState_Exec(glContext,0x8076);
    _glColorPointer_Exec(glContext,colorSize,colorType,stride,pointer + colorOffset);
  }
  else {
    _glDisableClientState_Exec(glContext,0x8076);
  }
  if (hasNormal) {
    _glEnableClientState_Exec(glContext,0x8075);
    ((void (*)())_glNormalPointer_Exec)(glContext,0x1406,stride,pointer + normalOffset);
  }
  else {
    _glDisableClientState_Exec(glContext,0x8075);
  }
  _glEnableClientState_Exec(glContext,0x8074);
  _glVertexPointer_Exec(glContext,vertexSize,0x1406,stride,pointer + vertexOffset);
  return;
}

/* _glArrayElement_ListExec @ 0xa50b8 (772 bytes) */
int _glArrayElement_ListExec(glContext, listRecord)
  int glContext;
  char *listRecord;
{
  float *secondaryColorBluePtr;
  byte normalSize;
  byte secondaryColorSize;
  char edgeFlagValue;
  char positionSize;
  float fVar4;
  float positionW;
  undefined4 missingComponentFill;
  float positionZ;
  int texCoordCurrent;
  int texUnitIndex;
  byte *srcCursor;
  code *vertexFunc;
  float *attribDataCursor;
  uint uVar12;
  uint texCoordSize;
  uint colorSize;
  int remaining;
  
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    goto LAB_000a53a0;
  }
  normalSize = listRecord[1];
  attribDataCursor = (float *)(listRecord + 0x24);
  if (normalSize != 0) {
    *(undefined4 *)(glContext + 0x2b0) = *(undefined4 *)(listRecord + 0x24);
    *(undefined4 *)(glContext + 0x2b4) = *(undefined4 *)(listRecord + 0x28);
    attribDataCursor = (float *)((int)attribDataCursor + (uint)normalSize);
    *(undefined4 *)(glContext + 0x2b8) = *(undefined4 *)(listRecord + 0x2c);
  }
  colorSize = (uint)(byte)listRecord[2];
  if (colorSize != 0) {
    *(float *)(glContext + 0x2a0) = *attribDataCursor;
    *(float *)(glContext + 0x2a4) = attribDataCursor[1];
    *(float *)(glContext + 0x2a8) = attribDataCursor[2];
    if (colorSize == 0x10) {
      *(float *)(glContext + 0x2ac) = attribDataCursor[3];
    }
    else {
      *(undefined4 *)(glContext + 0x2ac) = 0x3f800000;
    }
    if (*(char *)(glContext + 0x4df8) != '\0') {
      (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
    }
    attribDataCursor = (float *)((int)attribDataCursor + colorSize);
  }
  if ((byte)listRecord[3] != 0) {
    fVar4 = *attribDataCursor;
    attribDataCursor = (float *)((int)attribDataCursor + (uint)(byte)listRecord[3]);
    *(float *)(glContext + 0x2cc) = fVar4;
  }
  secondaryColorSize = listRecord[4];
  if (secondaryColorSize != 0) {
    *(float *)(glContext + 0x2c0) = *attribDataCursor;
    *(float *)(glContext + 0x2c4) = attribDataCursor[1];
    secondaryColorBluePtr = attribDataCursor + 2;
    attribDataCursor = (float *)((int)attribDataCursor + (uint)secondaryColorSize);
    *(float *)(glContext + 0x2c8) = *secondaryColorBluePtr;
  }
  uVar12 = (uint)(byte)listRecord[5];
  if (uVar12 != 0) {
    if (uVar12 == 0x10) {
      fVar4 = attribDataCursor[3];
LAB_000a51f4:
      *(float *)(glContext + 0x2dc) = fVar4;
      *(float *)(glContext + 0x2d8) = attribDataCursor[2];
LAB_000a5218:
      *(float *)(glContext + 0x2d4) = attribDataCursor[1];
    }
    else {
      if (uVar12 == 0xc) {
        fVar4 = *(float *)(glContext + 0x20);
        goto LAB_000a51f4;
      }
      if (uVar12 == 8) {
        *(undefined4 *)(glContext + 0x2d8) = *(undefined4 *)(glContext + 0x20);
        *(undefined4 *)(glContext + 0x2dc) = *(undefined4 *)(glContext + 0x20);
        goto LAB_000a5218;
      }
      missingComponentFill = *(undefined4 *)(glContext + 0x20);
      *(undefined4 *)(glContext + 0x2d4) = missingComponentFill;
      *(undefined4 *)(glContext + 0x2dc) = missingComponentFill;
      *(undefined4 *)(glContext + 0x2d8) = missingComponentFill;
    }
    fVar4 = *attribDataCursor;
    attribDataCursor = (float *)((int)attribDataCursor + uVar12);
    *(float *)(glContext + 0x2d0) = fVar4;
  }
  if ((byte)listRecord[6] != 0) {
    edgeFlagValue = *(char *)attribDataCursor;
    attribDataCursor = (float *)((int)attribDataCursor + (uint)(byte)listRecord[6]);
    *(char *)(glContext + 0x2ec) = edgeFlagValue;
  }
  texUnitIndex = 0;
  remaining = 8;
  srcCursor = (byte *)(listRecord + 8);
  do {
    texCoordSize = (uint)*srcCursor;
    srcCursor = srcCursor + 1;
    if (texCoordSize != 0) {
      if (texCoordSize == 0x10) {
        *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
        fVar4 = attribDataCursor[3];
LAB_000a52c4:
        texCoordCurrent = texUnitIndex * 0x10 + glContext;
        *(float *)(texCoordCurrent + 300) = fVar4;
        fVar4 = attribDataCursor[2];
LAB_000a52cc:
        *(float *)(texCoordCurrent + 0x128) = fVar4;
        fVar4 = attribDataCursor[1];
      }
      else {
        if (texCoordSize == 0xc) {
          fVar4 = *(float *)(glContext + 0x24);
          *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
          goto LAB_000a52c4;
        }
        if (texCoordSize == 8) {
          texCoordCurrent = texUnitIndex * 0x10 + glContext;
          *(undefined4 *)(texCoordCurrent + 300) = *(undefined4 *)(glContext + 0x24);
          fVar4 = *(float *)(glContext + 0x20);
          goto LAB_000a52cc;
        }
        texCoordCurrent = texUnitIndex * 0x10 + glContext;
        *(undefined4 *)(texCoordCurrent + 300) = *(undefined4 *)(glContext + 0x24);
        *(undefined4 *)(texCoordCurrent + 0x128) = *(undefined4 *)(glContext + 0x20);
        fVar4 = *(float *)(glContext + 0x20);
      }
      *(float *)(texCoordCurrent + 0x124) = fVar4;
      fVar4 = *attribDataCursor;
      attribDataCursor = (float *)((int)attribDataCursor + texCoordSize);
      *(float *)(texUnitIndex * 0x10 + glContext + 0x120) = fVar4;
    }
    texUnitIndex = texUnitIndex + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  positionSize = *listRecord;
  if (positionSize == '\0') goto LAB_000a53a0;
  vertexFunc = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    vertexFunc = (code *)PTR__gleFlushAndSubmit_00112050;
  }
  if (positionSize == '\x10') {
    positionW = attribDataCursor[3];
LAB_000a537c:
    positionZ = attribDataCursor[2];
  }
  else {
    if (positionSize == '\f') {
      positionW = *(float *)(glContext + 0x24);
      goto LAB_000a537c;
    }
    positionW = *(float *)(glContext + 0x24);
    positionZ = *(float *)(glContext + 0x20);
  }
  (*((int (*)(int,double,double,double,double))vertexFunc))(glContext, (double)*attribDataCursor, (double)attribDataCursor[1], (double)positionZ, (double)positionW);
LAB_000a53a0:
  return *(int *)(listRecord + 0x20) + 0x24;
}

/* _glArrayElement_Comp @ 0xa53bc (340 bytes) */
int _glArrayElement_Comp(glContext, i)
  int glContext;
  undefined4 i;
{
  undefined1 uVar1;
  uint uVar2;
  undefined1 *srcCursor;
  uint uVar4;
  undefined1 *dstCursor2;
  undefined4 uVar6;
  int clientState;
  code *pcVar8;
  int iVar9;
  int remaining;
  int iVar10;
  int *dstCursor;
  short *srcCursor2;
  undefined1 *puVar13;
  longlong lVar14;
  undefined4 local_b0;
  undefined1 auStack_34 [4];
  
  clientState = *(int *)(glContext + 0x4a60);
  if (*(int *)(glContext + 0x48dc) != 0x14ff) {
    *(undefined4 *)(glContext + 0x48dc) = 0x14ff;
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x48d8) = 0;
    *(undefined4 *)(glContext + 0x4978) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  uVar2 = *(uint *)(clientState + 0x330);
  uVar4 = *(uint *)(clientState + 0x334);
  dstCursor = &local_b0;
  srcCursor2 = (short *)(clientState + 0x3a);
  iVar9 = 0;
  iVar10 = 0x10;
  do {
    lVar14 = ___ashldi3(0,1,iVar10);
    if ((uVar2 & (uint)((ulonglong)lVar14 >> 0x20)) == 0 && (uVar4 & 0xff7fffff & (uint)lVar14) == 0
       ) {
      *dstCursor = 0;
    }
    else {
      iVar9 = iVar9 + *srcCursor2 * 4;
      *dstCursor = *srcCursor2 * 4;
    }
    dstCursor = dstCursor + 1;
    iVar10 = iVar10 + 1;
    srcCursor2 = srcCursor2 + 0xc;
  } while ((int)dstCursor <= (int)auStack_34);
  dstCursor2 = (undefined1 *)_gleAddListItem(glContext,PTR__glArrayElement_ListExec_00110450,iVar9 + 0x24)
  ;
  uVar6 = 0;
  if (dstCursor2 != (undefined1 *)0x0) {
    *(int *)(dstCursor2 + 0x20) = iVar9;
    remaining = 0x20;
    srcCursor = (undefined1 *)((int)&local_b0 + 3);
    puVar13 = dstCursor2 + 0x24;
    do {
      uVar1 = *srcCursor;
      srcCursor = srcCursor + 4;
      *dstCursor2 = uVar1;
      dstCursor2 = dstCursor2 + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
    pcVar8 = *(code **)(glContext + 0x488c);
    if (pcVar8 == (code *)0x0) {
      pcVar8 = (code *)_gleGetVertexToListFunc(glContext);
      *(code **)(glContext + 0x488c) = pcVar8;
    }
    uVar6 = (*pcVar8)(glContext,clientState + 0x30,puVar13,i);
  }
  return uVar6;
}

/* _glArrayElement_NoopExec @ 0xa5510 (668 bytes) */
void _glArrayElement_NoopExec(int glContext,undefined4 forwardedArg2,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double fparam_9,double forwardedFloatArg10,double forwardedFloatArg11,double forwardedFloatArg12,double forwardedFloatArg13)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  undefined4 in_LR;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000a5774;
  }
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') {
LAB_000a5758:
    if (*(char *)(glContext + 0x759d) != '\0') {
      ((void (*)())_glArrayElement_Exec)(glContext,forwardedArg2,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                 forwardedFloatArg8,(double)CONCAT44(in_LR,(*(unsigned int *)((unsigned char *)&(fparam_9) + 4))),forwardedFloatArg10,forwardedFloatArg11,forwardedFloatArg12,
                 forwardedFloatArg13);
      return;
    }
  }
  else {
    framebufferObject = *(int *)(glContext + 0x744c);
    dirtyFlagWords = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a5644:
      dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        iVar5 = *srcCursor;
        srcCursor = srcCursor + 1;
        if (iVar5 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
      if ((dirtyWord3ThenMasked & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000a5644;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
    }
    else {
      dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
    }
    if (bVar1) {
      stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (stateClean) goto LAB_000a5758;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000a573c:
      remaining = 0x13;
      do {
        *dirtyFlagWords = 0;
        dirtyFlagWords = dirtyFlagWords + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      goto LAB_000a5758;
    }
    dispatchFlags = (**(code **)(glContext + 0x4788))
                      (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
    if ((((dispatchFlags & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((dispatchFlags & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (dispatchFlags & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_000a573c;
    if ((dispatchFlags & 4) == 0) {
      dispatchFlags = dispatchFlags & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000a573c;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x506;
LAB_000a5774:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glArrayElement_Exec @ 0xa57ac (3652 bytes) */
void _glArrayElement_Exec(int glContext,int i,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  bool pendingMaskEmpty;
  bool attribMaskEmpty;
  ushort texCoordSize;
  ushort vertexType;
  ushort vertexSize;
  ushort attribType;
  ushort attribSize;
  ushort weightType;
  ushort secondaryColorType;
  ushort colorType;
  ushort normalType;
  ushort texCoordType;
  int clientState;
  int texTarget;
  int attribPtr;
  int texCoordPtr;
  uint texUnitBit;
  uint attribIndex;
  code *UNRECOVERED_JUMPTABLE;
  uint emptySlotMask;
  uint enabledArrayMask;
  uint enabledAttribMaskCopy;
  uint attribBit;
  uint loopIndex;
  int texCoordArray;
  int vertexPtr;
  int attribArray;
  int weightPtr;
  int fogCoordPtr;
  int secondaryColorPtr;
  int colorPtr;
  int normalPtr;
  uint pendingTexUnitMask;
  uint enabledAttribMask;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  double incomingStack_ffffffb0;
  double incomingStack_ffffffb8;
  
  clientState = *(int *)(glContext + 0x4a60);
  texCoordArray = clientState + 0x10;
  if ((((*(char *)(glContext + 0x7580) != '\0') || (*(char *)(glContext + 0x4664) != '\0')) ||
      (*(char *)(glContext + 0x30aa) == '\0')) || (*(char *)(glContext + 0x30ab) == '\0')) {
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4894);
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      *(undefined4 *)(glContext + 0x48dc) = 0x14ff;
      UNRECOVERED_JUMPTABLE = (code *)_gleGetVertexElemFunc(glContext);
      *(code **)(glContext + 0x4894) = UNRECOVERED_JUMPTABLE;
      if (*(int *)(glContext + 0x5408) == 0) {
        emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc) == 0);
        *(code **)((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) +
                  0xc) = UNRECOVERED_JUMPTABLE;
      }
    }
                    
                    
    (*UNRECOVERED_JUMPTABLE)(glContext,i);
    return;
  }
  *(undefined4 *)(glContext + 0x4894) = 0;
  enabledArrayMask = *(uint *)(clientState + 0x334);
  if ((enabledArrayMask & 0x400000) != 0) {
    forwardedFloatArg1 = (double)_glEdgeFlag_Exec(glContext,(uint)*(byte *)(*(int *)(clientState + 0xc0) +
                                                               i * *(int *)(clientState + 0xc4)));
  }
  pendingTexUnitMask = enabledArrayMask & 0xff000000;
  pendingMaskEmpty = pendingTexUnitMask == 0;
  if (!pendingMaskEmpty) {
    loopIndex = 0;
    do {
      texUnitBit = 0x1000000 << (loopIndex & 0x3f);
      if ((pendingTexUnitMask & texUnitBit) != 0) {
        texCoordSize = *(ushort *)(texCoordArray + 0xea);
        pendingTexUnitMask = pendingTexUnitMask & ~texUnitBit;
        texTarget = loopIndex + 0x84c0;
        texCoordPtr = *(int *)(texCoordArray + 0xe0) + i * *(int *)(texCoordArray + 0xe4);
        if (texCoordSize == 2) {
          texCoordType = *(ushort *)(texCoordArray + 0xe8);
          if (texCoordType == 0x1404) {
            forwardedFloatArg1 = (double)_glMultiTexCoord2iv_Exec(glContext,texTarget,texCoordPtr);
          }
          else if (texCoordType < 0x1405) {
            pendingMaskEmpty = pendingTexUnitMask == 0;
            if (texCoordType != 0x1402) goto LAB_000a5ab8;
            forwardedFloatArg1 = (double)_glMultiTexCoord2sv_Exec(glContext,texTarget,texCoordPtr);
          }
          else if (texCoordType == 0x1406) {
            forwardedFloatArg1 = (double)_glMultiTexCoord2fv_Exec(glContext,texTarget,texCoordPtr);
          }
          else {
            pendingMaskEmpty = pendingTexUnitMask == 0;
            if (texCoordType != 0x140a) goto LAB_000a5ab8;
            forwardedFloatArg1 = (double)_glMultiTexCoord2dv_Exec(glContext,texTarget,texCoordPtr);
          }
        }
        else if (texCoordSize < 3) {
          pendingMaskEmpty = pendingTexUnitMask == 0;
          if (texCoordSize != 1) goto LAB_000a5ab8;
          texCoordType = *(ushort *)(texCoordArray + 0xe8);
          if (texCoordType == 0x1404) {
            forwardedFloatArg1 = (double)_glMultiTexCoord1iv_Exec(glContext,texTarget,texCoordPtr);
          }
          else if (texCoordType < 0x1405) {
            pendingMaskEmpty = pendingTexUnitMask == 0;
            if (texCoordType != 0x1402) goto LAB_000a5ab8;
            forwardedFloatArg1 = (double)_glMultiTexCoord1sv_Exec(glContext,texTarget,texCoordPtr);
          }
          else if (texCoordType == 0x1406) {
            forwardedFloatArg1 = (double)_glMultiTexCoord1fv_Exec(glContext,texTarget,texCoordPtr);
          }
          else {
            pendingMaskEmpty = pendingTexUnitMask == 0;
            if (texCoordType != 0x140a) goto LAB_000a5ab8;
            forwardedFloatArg1 = (double)_glMultiTexCoord1dv_Exec(glContext,texTarget,texCoordPtr);
          }
        }
        else if (texCoordSize == 3) {
          texCoordType = *(ushort *)(texCoordArray + 0xe8);
          if (texCoordType == 0x1404) {
            forwardedFloatArg1 = (double)_glMultiTexCoord3iv_Exec(glContext,texTarget,texCoordPtr);
          }
          else if (texCoordType < 0x1405) {
            pendingMaskEmpty = pendingTexUnitMask == 0;
            if (texCoordType != 0x1402) goto LAB_000a5ab8;
            forwardedFloatArg1 = (double)_glMultiTexCoord3sv_Exec(glContext,texTarget,texCoordPtr);
          }
          else if (texCoordType == 0x1406) {
            forwardedFloatArg1 = (double)_glMultiTexCoord3fv_Exec(glContext,texTarget,texCoordPtr);
          }
          else {
            pendingMaskEmpty = pendingTexUnitMask == 0;
            if (texCoordType != 0x140a) goto LAB_000a5ab8;
            forwardedFloatArg1 = (double)_glMultiTexCoord3dv_Exec(glContext,texTarget,texCoordPtr);
          }
        }
        else {
          pendingMaskEmpty = pendingTexUnitMask == 0;
          if (texCoordSize != 4) goto LAB_000a5ab8;
          texCoordType = *(ushort *)(texCoordArray + 0xe8);
          if (texCoordType == 0x1404) {
            forwardedFloatArg1 = (double)_glMultiTexCoord4iv_Exec(glContext,texTarget,texCoordPtr);
          }
          else if (texCoordType < 0x1405) {
            pendingMaskEmpty = pendingTexUnitMask == 0;
            if (texCoordType != 0x1402) goto LAB_000a5ab8;
            forwardedFloatArg1 = (double)_glMultiTexCoord4sv_Exec(glContext,texTarget,texCoordPtr);
          }
          else if (texCoordType == 0x1406) {
            forwardedFloatArg1 = (double)_glMultiTexCoord4fv_Exec(glContext,texTarget,texCoordPtr);
          }
          else {
            pendingMaskEmpty = pendingTexUnitMask == 0;
            if (texCoordType != 0x140a) goto LAB_000a5ab8;
            forwardedFloatArg1 = (double)_glMultiTexCoord4dv_Exec(glContext,texTarget,texCoordPtr);
          }
        }
        pendingMaskEmpty = pendingTexUnitMask == 0;
      }
LAB_000a5ab8:
      loopIndex = loopIndex + 1;
      texCoordArray = texCoordArray + 0x18;
    } while ((!pendingMaskEmpty) && ((int)loopIndex < 8));
  }
  if ((enabledArrayMask & 0x20000) != 0) {
    normalType = *(ushort *)(clientState + 0x50);
    normalPtr = *(int *)(clientState + 0x48) + i * *(int *)(clientState + 0x4c);
    if (normalType == 0x9400) {
      forwardedFloatArg1 = (double)_glNormal3bv_Exec(glContext,normalPtr);
    }
    else if (normalType < 0x9401) {
      if (normalType == 0x1406) {
        forwardedFloatArg1 = (double)_glNormal3fv_Exec(glContext,normalPtr);
      }
      else if (normalType == 0x140a) {
        forwardedFloatArg1 = (double)_glNormal3dv_Exec(glContext,normalPtr);
      }
    }
    else if (normalType == 0x9402) {
      forwardedFloatArg1 = (double)_glNormal3sv_Exec(glContext,normalPtr);
    }
    else if (normalType == 0x9404) {
      forwardedFloatArg1 = (double)((double (*)())_glNormal3iv_Exec)(glContext,normalPtr,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                                           forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffff98,
                                           incomingStack_ffffffa0,incomingStack_ffffffa8);
    }
  }
  if ((enabledArrayMask & 0x40000) != 0) {
    colorPtr = *(int *)(clientState + 0x60) + i * *(int *)(clientState + 100);
    if (*(short *)(clientState + 0x6a) == 3) {
      colorType = *(ushort *)(clientState + 0x68);
      if (colorType == 0x9401) {
        forwardedFloatArg1 = (double)_glColor3ubv_Exec(glContext,colorPtr);
      }
      else if (colorType < 0x9402) {
        if (colorType == 0x140a) {
          forwardedFloatArg1 = (double)_glColor3dv_Exec(glContext,colorPtr);
        }
        else if (colorType < 0x140b) {
          if (colorType == 0x1406) {
            if (*(char *)(glContext + 0x4df8) == '\0') {
              forwardedFloatArg1 = (double)_glColor3fv_NoColorMat_Exec(glContext,colorPtr);
            }
            else {
              forwardedFloatArg1 = (double)_glColor3fv_ColorMat_Exec(glContext,colorPtr);
            }
          }
        }
        else if (colorType == 0x9400) {
          forwardedFloatArg1 = (double)_glColor3bv_Exec(glContext,colorPtr);
        }
      }
      else if (colorType == 0x9403) {
        forwardedFloatArg1 = (double)((double (*)())_glColor3usv_Exec)(glContext,colorPtr,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                                             forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffff98,
                                             incomingStack_ffffffa0,incomingStack_ffffffa8,incomingStack_ffffffb0,
                                             incomingStack_ffffffb8);
      }
      else if (colorType < 0x9403) {
        forwardedFloatArg1 = (double)_glColor3sv_Exec(glContext,colorPtr);
      }
      else if (colorType == 0x9404) {
        forwardedFloatArg1 = (double)_glColor3iv_Exec(glContext,colorPtr);
      }
      else if (colorType == 0x9405) {
        forwardedFloatArg1 = (double)_glColor3uiv_Exec(glContext,colorPtr);
      }
    }
    else if (*(short *)(clientState + 0x6a) == 4) {
      colorType = *(ushort *)(clientState + 0x68);
      if (colorType == 0x9401) {
        forwardedFloatArg1 = (double)_glColor4ubv_Exec(glContext,colorPtr);
      }
      else if (colorType < 0x9402) {
        if (colorType == 0x140a) {
          forwardedFloatArg1 = (double)_glColor4dv_Exec(glContext,colorPtr);
        }
        else if (colorType < 0x140b) {
          if (colorType == 0x1406) {
            if (*(char *)(glContext + 0x4df8) == '\0') {
              forwardedFloatArg1 = (double)_glColor4fv_NoColorMat_Exec(glContext,colorPtr);
            }
            else {
              forwardedFloatArg1 = (double)_glColor4fv_ColorMat_Exec(glContext,colorPtr);
            }
          }
        }
        else if (colorType == 0x9400) {
          forwardedFloatArg1 = (double)_glColor4bv_Exec(glContext,colorPtr);
        }
      }
      else if (colorType == 0x9403) {
        forwardedFloatArg1 = (double)((double (*)())_glColor4usv_Exec)(glContext,colorPtr,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                                             forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffff98,
                                             incomingStack_ffffffa0,incomingStack_ffffffa8,incomingStack_ffffffb0,
                                             incomingStack_ffffffb8);
      }
      else if (colorType < 0x9403) {
        forwardedFloatArg1 = (double)_glColor4sv_Exec(glContext,colorPtr);
      }
      else if (colorType == 0x9404) {
        forwardedFloatArg1 = (double)_glColor4iv_Exec(glContext,colorPtr);
      }
      else if (colorType == 0x9405) {
        forwardedFloatArg1 = (double)_glColor4uiv_Exec(glContext,colorPtr);
      }
    }
  }
  if ((enabledArrayMask & 0x100000) != 0) {
    secondaryColorType = *(ushort *)(clientState + 0x98);
    secondaryColorPtr = *(int *)(clientState + 0x90) + i * *(int *)(clientState + 0x94);
    if (secondaryColorType == 0x9401) {
      forwardedFloatArg1 = (double)_glSecondaryColor3ubv_Exec(glContext,secondaryColorPtr);
    }
    else if (secondaryColorType < 0x9402) {
      if (secondaryColorType == 0x140a) {
        forwardedFloatArg1 = (double)_glSecondaryColor3dv_Exec(glContext,secondaryColorPtr);
      }
      else if (secondaryColorType < 0x140b) {
        if (secondaryColorType == 0x1406) {
          forwardedFloatArg1 = (double)_glSecondaryColor3fv_Exec(glContext,secondaryColorPtr);
        }
      }
      else if (secondaryColorType == 0x9400) {
        forwardedFloatArg1 = (double)_glSecondaryColor3bv_Exec(glContext,secondaryColorPtr);
      }
    }
    else if (secondaryColorType == 0x9403) {
      forwardedFloatArg1 = (double)_glSecondaryColor3usv_Exec(glContext,secondaryColorPtr);
    }
    else if (secondaryColorType < 0x9403) {
      forwardedFloatArg1 = (double)_glSecondaryColor3sv_Exec(glContext,secondaryColorPtr);
    }
    else if (secondaryColorType == 0x9404) {
      forwardedFloatArg1 = (double)_glSecondaryColor3iv_Exec(glContext,secondaryColorPtr);
    }
    else if (secondaryColorType == 0x9405) {
      forwardedFloatArg1 = (double)_glSecondaryColor3uiv_Exec(glContext,secondaryColorPtr);
    }
  }
  if ((enabledArrayMask & 0x80000) != 0) {
    fogCoordPtr = *(int *)(clientState + 0x78) + i * *(int *)(clientState + 0x7c);
    if (*(short *)(clientState + 0x80) == 0x1406) {
      forwardedFloatArg1 = (double)_glFogCoordfv_Exec(glContext,fogCoordPtr);
    }
    else if (*(short *)(clientState + 0x80) == 0x140a) {
      forwardedFloatArg1 = (double)_glFogCoorddv_Exec(glContext,fogCoordPtr);
    }
  }
  if ((enabledArrayMask & 0x200000) != 0) {
    weightType = *(ushort *)(clientState + 0xb0);
    weightPtr = *(int *)(clientState + 0xa8) + i * *(int *)(clientState + 0xac);
    if (weightType == 0x9401) {
      forwardedFloatArg1 = (double)_glWeightubvARB_Exec(glContext,(int)*(short *)(clientState + 0xb2),weightPtr);
    }
    else if (weightType < 0x9402) {
      if (weightType == 0x140a) {
        forwardedFloatArg1 = (double)_glWeightdvARB_Exec(glContext,(int)*(short *)(clientState + 0xb2),weightPtr);
      }
      else if (weightType < 0x140b) {
        if (weightType == 0x1406) {
          forwardedFloatArg1 = (double)_glWeightfvARB_Exec(glContext,(int)*(short *)(clientState + 0xb2),weightPtr);
        }
      }
      else if (weightType == 0x9400) {
        forwardedFloatArg1 = (double)_glWeightbvARB_Exec(glContext,(int)*(short *)(clientState + 0xb2),weightPtr);
      }
    }
    else if (weightType == 0x9403) {
      forwardedFloatArg1 = (double)_glWeightusvARB_Exec(glContext,(int)*(short *)(clientState + 0xb2),weightPtr);
    }
    else if (weightType < 0x9403) {
      forwardedFloatArg1 = (double)_glWeightsvARB_Exec(glContext,(int)*(short *)(clientState + 0xb2),weightPtr);
    }
    else if (weightType == 0x9404) {
      forwardedFloatArg1 = (double)_glWeightivARB_Exec(glContext,(int)*(short *)(clientState + 0xb2),weightPtr);
    }
    else if (weightType == 0x9405) {
      forwardedFloatArg1 = (double)_glWeightuivARB_Exec(glContext,(int)*(short *)(clientState + 0xb2),weightPtr);
    }
  }
  enabledAttribMask = *(uint *)(clientState + 0x330);
  if (enabledAttribMask != 0) {
    attribMaskEmpty = enabledAttribMask == 0;
    attribIndex = 0xf;
    enabledAttribMaskCopy = 0;
    if (!attribMaskEmpty) {
      attribArray = clientState + 0x178;
      do {
        attribBit = 1 << (attribIndex & 0x3f);
        if ((enabledAttribMask & attribBit) == 0) goto LAB_000a638c;
        enabledAttribMask = enabledAttribMask & ~attribBit;
        attribSize = *(ushort *)(attribArray + 0x1aa);
        attribPtr = *(int *)(attribArray + 0x1a0) + i * *(int *)(attribArray + 0x1a4);
        if (attribSize == 2) {
          attribType = *(ushort *)(attribArray + 0x1a8);
          if (attribType == 0x1406) {
            forwardedFloatArg1 = (double)_glVertexAttrib2fvARB_Exec(glContext,attribIndex,attribPtr);
            goto LAB_000a6388;
          }
          if (attribType < 0x1407) {
            attribMaskEmpty = enabledAttribMask == 0;
            if (attribType == 0x1402) {
              forwardedFloatArg1 = (double)_glVertexAttrib2svARB_Exec(glContext,attribIndex,attribPtr);
              goto LAB_000a6388;
            }
          }
          else {
            attribMaskEmpty = enabledAttribMask == 0;
            if (attribType == 0x140a) {
              forwardedFloatArg1 = (double)_glVertexAttrib2dvARB_Exec(glContext,attribIndex,attribPtr);
              goto LAB_000a6388;
            }
          }
        }
        else {
          if (attribSize < 3) {
            attribMaskEmpty = enabledAttribMask == 0;
            if (attribSize != 1) goto LAB_000a638c;
            attribType = *(ushort *)(attribArray + 0x1a8);
            if (attribType != 0x1406) {
              if (attribType < 0x1407) {
                attribMaskEmpty = enabledAttribMask == 0;
                if (attribType == 0x1402) {
                  forwardedFloatArg1 = (double)_glVertexAttrib1svARB_Exec(glContext,attribIndex,attribPtr);
                  goto LAB_000a6388;
                }
              }
              else {
                attribMaskEmpty = enabledAttribMask == 0;
                if (attribType == 0x140a) {
                  forwardedFloatArg1 = (double)_glVertexAttrib1dvARB_Exec(glContext,attribIndex,attribPtr);
                  goto LAB_000a6388;
                }
              }
              goto LAB_000a638c;
            }
            forwardedFloatArg1 = (double)_glVertexAttrib1fvARB_Exec(glContext,attribIndex,attribPtr);
          }
          else if (attribSize == 3) {
            attribType = *(ushort *)(attribArray + 0x1a8);
            if (attribType != 0x1406) {
              if (attribType < 0x1407) {
                attribMaskEmpty = enabledAttribMask == 0;
                if (attribType == 0x1402) {
                  forwardedFloatArg1 = (double)_glVertexAttrib3svARB_Exec(glContext,attribIndex,attribPtr);
                  goto LAB_000a6388;
                }
              }
              else {
                attribMaskEmpty = enabledAttribMask == 0;
                if (attribType == 0x140a) {
                  forwardedFloatArg1 = (double)_glVertexAttrib3dvARB_Exec(glContext,attribIndex,attribPtr);
                  goto LAB_000a6388;
                }
              }
              goto LAB_000a638c;
            }
            forwardedFloatArg1 = (double)_glVertexAttrib3fvARB_Exec(glContext,attribIndex,attribPtr);
          }
          else {
            attribMaskEmpty = enabledAttribMask == 0;
            if (attribSize != 4) goto LAB_000a638c;
            attribType = *(ushort *)(attribArray + 0x1a8);
            if (attribType == 0x1406) {
              forwardedFloatArg1 = (double)_glVertexAttrib4fvARB_Exec(glContext,attribIndex,attribPtr);
            }
            else if (attribType < 0x1407) {
              if (attribType == 0x1402) {
                forwardedFloatArg1 = (double)_glVertexAttrib4svARB_Exec(glContext,attribIndex,attribPtr);
              }
              else if (attribType < 0x1403) {
                if (attribType == 0x1400) {
                  forwardedFloatArg1 = (double)_glVertexAttrib4bvARB_Exec(glContext,attribIndex,attribPtr);
                }
                else {
                  if (attribType != 0x1401) goto LAB_000a638c;
                  forwardedFloatArg1 = (double)((double (*)())_glVertexAttrib4ubvARB_Exec)(glContext,attribIndex,attribPtr,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                                                forwardedFloatArg4);
                }
              }
              else if (attribType == 0x1404) {
                forwardedFloatArg1 = (double)_glVertexAttrib4ivARB_Exec(glContext,attribIndex,attribPtr);
              }
              else if (attribType < 0x1405) {
                forwardedFloatArg1 = (double)((double (*)())_glVertexAttrib4usvARB_Exec)(glContext,attribIndex,attribPtr,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                                              forwardedFloatArg4);
              }
              else {
                forwardedFloatArg1 = (double)_glVertexAttrib4uivARB_Exec(glContext,attribIndex,attribPtr);
              }
            }
            else if (attribType == 0x9402) {
              forwardedFloatArg1 = (double)_glVertexAttrib4NsvARB_Exec(glContext,attribIndex,attribPtr);
            }
            else if (attribType < 0x9403) {
              if (attribType == 0x9400) {
                forwardedFloatArg1 = (double)_glVertexAttrib4NbvARB_Exec(glContext,attribIndex,attribPtr);
              }
              else if (attribType < 0x9401) {
                attribMaskEmpty = enabledAttribMask == 0;
                if (attribType != 0x140a) goto LAB_000a638c;
                forwardedFloatArg1 = (double)_glVertexAttrib4dvARB_Exec(glContext,attribIndex,attribPtr);
              }
              else {
                forwardedFloatArg1 = (double)((double (*)())_glVertexAttrib4NubvARB_Exec)(glContext,attribIndex,attribPtr,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                                              forwardedFloatArg4);
              }
            }
            else if (attribType == 0x9404) {
              forwardedFloatArg1 = (double)_glVertexAttrib4NivARB_Exec(glContext,attribIndex,attribPtr);
            }
            else if (attribType < 0x9404) {
              forwardedFloatArg1 = (double)((double (*)())_glVertexAttrib4NusvARB_Exec)(glContext,attribIndex,attribPtr,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4)
              ;
            }
            else {
              attribMaskEmpty = enabledAttribMask == 0;
              if (attribType != 0x9405) goto LAB_000a638c;
              forwardedFloatArg1 = (double)_glVertexAttrib4NuivARB_Exec(glContext,attribIndex,attribPtr);
            }
          }
LAB_000a6388:
          attribMaskEmpty = enabledAttribMask == 0;
        }
LAB_000a638c:
        attribIndex = attribIndex - 1;
        attribArray = attribArray + -0x18;
      } while ((!attribMaskEmpty) && (-1 < (int)attribIndex));
      enabledAttribMaskCopy = *(uint *)(clientState + 0x330);
    }
    if ((enabledAttribMaskCopy & 1) != 0) {
      return;
    }
  }
  if ((enabledArrayMask & 0x10000) != 0) {
    vertexSize = *(ushort *)(clientState + 0x3a);
    vertexPtr = *(int *)(clientState + 0x30) + i * *(int *)(clientState + 0x34);
    if (vertexSize == 3) {
      vertexType = *(ushort *)(clientState + 0x38);
      if (vertexType == 0x1404) {
        ((void (*)())_glVertex3iv_Exec)(glContext,vertexPtr);
        return;
      }
      if (vertexType < 0x1405) {
        if (vertexType == 0x1402) {
          ((void (*)())_glVertex3sv_Exec)(glContext,vertexPtr);
          return;
        }
      }
      else {
        if (vertexType == 0x1406) {
          _glVertex3fv_Exec(glContext,vertexPtr);
          return;
        }
        if (vertexType == 0x140a) {
          _glVertex3dv_Exec(glContext,vertexPtr);
          return;
        }
      }
    }
    else if (vertexSize < 4) {
      if (vertexSize == 2) {
        vertexType = *(ushort *)(clientState + 0x38);
        if (vertexType == 0x1404) {
          ((void (*)())_glVertex2iv_Exec)(glContext,vertexPtr);
          return;
        }
        if (vertexType < 0x1405) {
          if (vertexType == 0x1402) {
            ((void (*)())_glVertex2sv_Exec)(glContext,vertexPtr);
            return;
          }
        }
        else {
          if (vertexType == 0x1406) {
            _glVertex2fv_Exec(glContext,vertexPtr);
            return;
          }
          if (vertexType == 0x140a) {
            _glVertex2dv_Exec(glContext,vertexPtr);
            return;
          }
        }
      }
    }
    else if (vertexSize == 4) {
      vertexType = *(ushort *)(clientState + 0x38);
      if (vertexType == 0x1404) {
        ((void (*)())_glVertex4iv_Exec)(glContext,vertexPtr);
        return;
      }
      if (vertexType < 0x1405) {
        if (vertexType == 0x1402) {
          ((void (*)())_glVertex4sv_Exec)(glContext,vertexPtr);
          return;
        }
      }
      else {
        if (vertexType == 0x1406) {
          _glVertex4fv_Exec(glContext,vertexPtr);
          return;
        }
        if (vertexType == 0x140a) {
          _glVertex4dv_Exec(glContext,vertexPtr);
          return;
        }
      }
    }
  }
  return;
}

/* _glArrayElement_CompExec @ 0xa65f0 (56 bytes) */
void _glArrayElement_CompExec(glContext, i)
  undefined4 glContext;
  undefined4 i;
{
  unsigned int ghidra_home[8] = { glContext, i, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glArrayElement_Comp)(glContext,i);
  ((void (*)())_glArrayElement_Exec)(glContext,i,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
             (*(double *)((unsigned char *)ghidra_home + 8)),(*(double *)((unsigned char *)ghidra_home + 16)));
  return;
}

/* _gleForcePushMaterial @ 0xa6628 (204 bytes) */
void _gleForcePushMaterial(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  puVar2 = *(undefined8 **)(param_1 + 0x4dd8);
  puVar3 = *(undefined8 **)(param_2 * 4 + param_1 + 0x4dd0);
  if (puVar2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)_gleVecAlloc(0x240);
    *(float *)((int)puVar2 + 500) = -*(float *)(param_1 + 0x24);
  }
  else {
    *(undefined4 *)(param_1 + 0x4dd8) = *(undefined4 *)((int)puVar2 + 0x23c);
  }
  *puVar2 = *puVar3;
  puVar2[1] = puVar3[1];
  puVar2[2] = puVar3[2];
  puVar2[3] = puVar3[3];
  puVar2[4] = puVar3[4];
  puVar2[5] = puVar3[5];
  puVar2[6] = puVar3[6];
  uVar4 = puVar3[7];
  *(undefined4 *)(puVar2 + 0x47) = 0;
  puVar2[7] = uVar4;
  uVar1 = *(undefined4 *)(puVar3 + 8);
  *(undefined4 *)(puVar2 + 0x3c) = 0;
  *(undefined8 **)(puVar3 + 0x47) = puVar2;
  *(undefined4 *)(puVar2 + 8) = uVar1;
  *(undefined8 **)((int)puVar2 + 0x23c) = puVar3;
  *(undefined8 **)(param_2 * 4 + param_1 + 0x4dd0) = puVar2;
  *(undefined4 *)((int)puVar2 + 0x234) = 0x1f000000;
  return;
}

/* _glDrawArraysOrElements_ListExec @ 0xa66f4 (1740 bytes) */
int _glDrawArraysOrElements_ListExec(int glContext,uint *listRecord,undefined4 param_3,undefined4 param_4,uint param_5,undefined4 param_6,undefined4 unusedArg7,undefined4 unusedArg8,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  undefined4 uVar2;
  undefined4 glErrorCode;
  uint uVar3;
  char cVar6;
  int *srcCursor;
  uint *puVar5;
  int iVar7;
  int framebufferObject;
  int iVar8;
  int matrixFuncDirty2;
  int remaining;
  int loopIndex;
  int framebufferObject2;
  uint uVar9;
  uint dispatchFlags;
  uint dirtyWord3ThenMasked;
  uint uVar10;
  undefined4 clientState;
  int iVar12;
  int matrixFuncDirty;
  int remaining2;
  int loopIndex2;
  int *dirtyFlagWords;
  uint uVar14;
  uint elementBytes;
  uint count;
  double fparam_1_00;
  double extraout_f1;
  double extraout_f1_00;
  
  uVar14 = listRecord[5];
  count = listRecord[6];
  elementBytes = listRecord[7];
  if ((*(char *)(glContext + 0x759c) == '\0') || (-1 < *(short *)(glContext + 0x4a10))) {
LAB_000a6788:
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_000a6da4;
    glErrorCode = 0x502;
  }
  else if (uVar14 < 10) {
    if (-1 < (int)count) {
      if ((*(char *)(glContext + 0x4664) != '\0') &&
         (*(int *)(*(int *)(glContext + 0x5420) + 0x4cc) == 0)) goto LAB_000a6788;
      if ((count == 0) || ((*(char *)(listRecord + 8) == '\0' && (*(char *)(listRecord + 0xc) == '\0'))))
      goto LAB_000a6da4;
      cVar6 = *(char *)(glContext + 0x7580);
      if ((cVar6 != '\0') && ((*listRecord & 3) == 2)) {
        fparam_1 = (double)_gleCreateDrawArraysOrElementsVertexObject(glContext,listRecord);
        cVar6 = *(char *)(glContext + 0x7580);
      }
      if ((cVar6 == '\0') || ((*listRecord & 3) == 0)) {
LAB_000a6acc:
        matrixFuncDirty = *(int *)(glContext + 0x50ac);
        if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
          _gleUpdateMatrixFunc(glContext);
          fparam_1 = extraout_f1_00;
        }
        if (*(char *)(glContext + 0x4691) != '\0') {
          framebufferObject2 = *(int *)(glContext + 0x744c);
          dirtyFlagWords = (int *)(glContext + 0x310);
          cVar6 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
          if ((framebufferObject2 != 0) && (*(int *)(framebufferObject2 + 0xec) != 0)) {
            ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject2 + 0x10,param_3,param_4,param_5,param_6,matrixFuncDirty,fparam_1,forwardedFloatArg2
                       ,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
            *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
          }
          if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a6bbc:
            dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
          }
          else {
            loopIndex2 = 0;
            srcCursor = (int *)(glContext + 0x324);
            do {
              iVar8 = *srcCursor;
              srcCursor = srcCursor + 1;
              if (iVar8 != 0) {
                *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
                break;
              }
              loopIndex2 = loopIndex2 + 1;
            } while (loopIndex2 < 9);
            dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
            if ((dirtyWord3ThenMasked & 0x15555) != 0) {
              if (*(char *)(glContext + 0x2e54) != '\0') {
                _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
              }
              if (*(char *)(glContext + 0x3094) != '\0') {
                _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
              }
              goto LAB_000a6bbc;
            }
          }
          bVar1 = cVar6 == '\0';
          if (bVar1) {
            dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
          }
          else {
            dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
          }
          if (bVar1) {
            stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
                    *(int *)(glContext + 800) == 0;
          }
          else {
            stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
                     (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
                    *(int *)(glContext + 800) == 0;
          }
          if (!stateClean) {
            if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
              dispatchFlags = (**(code **)(glContext + 0x4788))
                                (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
              if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
                  ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
                 ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
                if ((dispatchFlags & 4) == 0) {
                  dispatchFlags = dispatchFlags & 0xfffffffe;
                  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
                }
                _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
                if (*(char *)(glContext + 0x759d) == '\0') goto LAB_000a6ca8;
              }
            }
            else {
              _gleSwitchToNonRevertRenderer(glContext);
            }
            remaining2 = 0x13;
            do {
              *dirtyFlagWords = 0;
              dirtyFlagWords = dirtyFlagWords + 1;
              remaining2 = remaining2 + -1;
            } while (remaining2 != 0);
          }
        }
        uVar9 = 0;
        if (*(char *)(glContext + 0x7580) == '\0') {
          uVar10 = 0;
          puVar5 = listRecord + 10;
          do {
            uVar3 = *(uint *)(glContext + 0x514c) >> (uVar10 & 0x3f);
            if ((uVar3 & 1) == 0) {
              if (uVar3 == 0) break;
            }
            else if (*(char *)puVar5 == '\x10') {
              uVar9 = 3;
            }
            else if (*(char *)puVar5 == '\f') {
              uVar9 = uVar9 | 1;
            }
            uVar10 = uVar10 + 1;
            puVar5 = (uint *)((int)puVar5 + 1);
          } while( true );
        }
        *(uint **)(glContext + 0x48f0) = listRecord + 0x10;
        *(uint **)(glContext + 0x48ec) = listRecord + 5;
        uVar2 = _gleGetVertexArrayFunc(glContext);
        _gleDrawArraysOrElements_Core
                  (glContext,uVar14,0,count,uVar9,-(uint)*(byte *)((int)listRecord + 0x22) >> 0x1f,0,
                   uVar2);
        *(undefined4 *)(glContext + 0x48ec) = 0;
        uVar14 = *listRecord;
      }
      else {
        clientState = *(undefined4 *)(glContext + 0x4a60);
        param_3 = _gleGetEnabled(glContext,0x851d);
        _gleSetCurrentVertexObject(glContext,listRecord[1]);
        uVar2 = 1;
        iVar12 = 0;
        fparam_1_00 = (double)_gleSetClientEnableFlag(glContext,0x851d,1);
        matrixFuncDirty2 = *(int *)(glContext + 0x50ac);
        if (matrixFuncDirty2 != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
          _gleUpdateMatrixFunc(glContext);
          fparam_1_00 = extraout_f1;
        }
        if (*(char *)(glContext + 0x4691) != '\0') {
          framebufferObject = *(int *)(glContext + 0x744c);
          dirtyFlagWords = (int *)(glContext + 0x310);
          cVar6 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
          if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
            ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar2,param_4,param_5,param_6,matrixFuncDirty2,fparam_1_00,forwardedFloatArg2
                       ,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
            *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
          }
          if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a6938:
            dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
          }
          else {
            loopIndex = 0;
            srcCursor = (int *)(glContext + 0x324);
            do {
              iVar7 = *srcCursor;
              srcCursor = srcCursor + 1;
              if (iVar7 != 0) {
                *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
                break;
              }
              loopIndex = loopIndex + 1;
            } while (loopIndex < 9);
            dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
            if ((dirtyWord3ThenMasked & 0x15555) != 0) {
              if (*(char *)(glContext + 0x2e54) != '\0') {
                _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
              }
              if (*(char *)(glContext + 0x3094) != '\0') {
                _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
              }
              goto LAB_000a6938;
            }
          }
          bVar1 = cVar6 == '\0';
          if (bVar1) {
            dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
          }
          else {
            dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
          }
          if (bVar1) {
            stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
                    *(int *)(glContext + 800) == 0;
          }
          else {
            stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
                     (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
                    *(int *)(glContext + 800) == 0;
          }
          if (stateClean) goto LAB_000a6a4c;
          if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
            _gleSwitchToNonRevertRenderer(glContext);
LAB_000a6a30:
            remaining = 0x13;
            do {
              *dirtyFlagWords = 0;
              dirtyFlagWords = dirtyFlagWords + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
            goto LAB_000a6a4c;
          }
          dispatchFlags = (**(code **)(glContext + 0x4788))
                            (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
          if ((((dispatchFlags & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
              ((dispatchFlags & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
             ((dispatchFlags & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0'))) goto LAB_000a6a30;
          if ((dispatchFlags & 4) == 0) {
            dispatchFlags = dispatchFlags & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
          if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000a6a30;
LAB_000a6ca8:
          if (*(int *)(glContext + 0x7574) != 0) goto LAB_000a6da4;
          glErrorCode = 0x506;
          goto LAB_000a6748;
        }
LAB_000a6a4c:
        if (*(char *)(glContext + 0x7580) != '\0') {
          param_4 = 0;
          param_6 = 0x14ff;
          param_5 = count;
          iVar12 = _gleExecuteVertexArrayRange(glContext,0,uVar14,0,count,0x14ff,0);
        }
        _gleSetCurrentVertexObject(glContext,clientState);
        fparam_1 = (double)_gleSetClientEnableFlag(glContext,0x851d,param_3);
        if (iVar12 == 0) goto LAB_000a6acc;
        uVar14 = *listRecord;
      }
      if ((uVar14 & 4) != 0) {
        _gleDrawArraysSyncState(glContext,listRecord + 5);
      }
      goto LAB_000a6da4;
    }
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_000a6da4;
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_000a6da4;
    glErrorCode = 0x500;
  }
LAB_000a6748:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_000a6da4:
  return count * elementBytes + 0x40;
}

/* _gleDrawArraysOrElements_Comp @ 0xa6dc0 (392 bytes) */
int _gleDrawArraysOrElements_Comp(glContext, param_2, param_3, param_4)
  int glContext;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  unsigned char cVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  code *pcVar5;
  int clientState;
  code *dstCursor;
  int iVar8;
  int iVar9;
  int remaining;
  int *dstCursor2;
  short *srcCursor;
  code *pcVar12;
  longlong lVar13;
  undefined4 local_c0;
  undefined1 auStack_44 [12];
  
  clientState = *(int *)(glContext + 0x4a60);
  uVar3 = *(uint *)(clientState + 0x330);
  pcVar5 = *(code **)(clientState + 0x334);
  uVar2 = (uint)pcVar5 & 0xff7fffff;
  if ((0 < param_4) &&
     (pcVar5 = (code *)((uint)pcVar5 & 0x10000), (uVar3 & 1) != 0 || pcVar5 != (code *)0x0)) {
    dstCursor2 = &local_c0;
    srcCursor = (short *)(clientState + 0x3a);
    iVar8 = 0;
    iVar9 = 0x10;
    do {
      lVar13 = ___ashldi3(0,1,iVar9);
      if ((uVar3 & (uint)((ulonglong)lVar13 >> 0x20)) == 0 && (uVar2 & (uint)lVar13) == 0) {
        *dstCursor2 = 0;
      }
      else {
        iVar8 = iVar8 + *srcCursor * 4;
        *dstCursor2 = *srcCursor * 4;
      }
      dstCursor2 = dstCursor2 + 1;
      iVar9 = iVar9 + 1;
      srcCursor = srcCursor + 0xc;
    } while ((int)dstCursor2 <= (int)auStack_44);
    pcVar5 = (code *)_gleAddListItem(glContext,PTR__glDrawArraysOrElements_ListExec_0011044c,
                                     param_4 * iVar8 + 0x40);
    if (pcVar5 != (code *)0x0) {
      *(undefined4 *)(pcVar5 + 0x14) = param_2;
      *(undefined4 *)(pcVar5 + 4) = 0;
      dstCursor = pcVar5 + 0x20;
      *(undefined4 *)pcVar5 = 0;
      remaining = 0x20;
      *(int *)(pcVar5 + 0x1c) = iVar8;
      *(int *)(pcVar5 + 8) = param_4 * iVar8;
      pcVar4 = (code *)((int)&local_c0 + 3);
      *(int *)(pcVar5 + 0x18) = param_4;
      pcVar12 = pcVar5 + 0x40;
      do {
        cVar1 = *(char *)pcVar4;
        pcVar4 = pcVar4 + 4;
        *(char *)dstCursor = cVar1;
        dstCursor = dstCursor + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      pcVar4 = *(code **)(glContext + 0x488c);
      if (*(code **)(glContext + 0x488c) == (code *)0x0) {
        pcVar5 = (code *)_gleGetVertexToListFunc(glContext);
        *(code **)(glContext + 0x488c) = pcVar5;
        pcVar4 = pcVar5;
      }
      iVar8 = param_4 + param_3;
      for (; param_3 < iVar8; param_3 = param_3 + 1) {
        pcVar12 = (code *)(*pcVar4)(glContext,clientState + 0x30,pcVar12,param_3);
        pcVar5 = pcVar12;
      }
    }
  }
  return pcVar5;
}

/* _gleDrawArraysOrElements_Exec @ 0xa6f48 (2712 bytes) */
void _gleDrawArraysOrElements_Exec(int glContext,int *mode,int *first,int *count,undefined4 forwardedArg5,int param_6,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  uint uVar4;
  int *srcCursor;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  uint dispatchFlags2;
  uint dirtyWord3ThenMasked2;
  int iVar10;
  int framebufferObject;
  uint uVar11;
  uint dispatchFlags;
  uint dirtyWord3ThenMasked;
  uint uVar12;
  int iVar13;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  int *dirtyFlagWords;
  int *pendingChangeWords;
  short *srcCursor2;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double extraout_f1_03;
  double extraout_f1_04;
  double extraout_f1_05;
  double extraout_f1_06;
  longlong lVar16;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
LAB_000a6fd8:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000a78b8;
  }
  if ((int *)((int)((unsigned char *)0x8) + 2) <= mode) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_000a78b8;
  }
  if ((int)count < 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_000a78b8;
  }
  uVar9 = (uint)*(byte *)(glContext + 0x4664);
  if ((uVar9 != 0) && (*(int *)(*(int *)(glContext + 0x5420) + 0x4cc) == 0)) goto LAB_000a6fd8;
  if ((*(uint *)(param_6 + 800) & 1) == 0 && (*(uint *)(param_6 + 0x324) & 0x10000) == 0) {
    return;
  }
  if (count == (int *)0x0) {
    return;
  }
  piVar8 = *(int **)(glContext + 0x4988);
  piVar6 = first;
  piVar7 = count;
  if (((piVar8 == (int *)0x0) && (*(char *)(glContext + 0x7580) != '\0')) &&
     (((((*(char *)(glContext + 0x465c) != '\0' ||
         ((*(short *)(param_6 + 0x332) == -0x7a42 || (*(short *)(param_6 + 0x332) == -0x7a41)))) &&
        (*(int *)(param_6 + 0x338) != 0)) && (*(int *)(param_6 + 0x334) != 0)) ||
      ((*(uint *)(param_6 + 800) == (*(uint *)(param_6 + 0x328) & *(uint *)(param_6 + 800)) &&
       (*(uint *)(param_6 + 0x324) == (*(uint *)(param_6 + 0x32c) & *(uint *)(param_6 + 0x324)))))))
     ) {
    if (*(int *)(param_6 + 0x340) != 0 || *(int *)(param_6 + 0x344) != 0) {
      uVar11 = *(uint *)(param_6 + 0x340);
      uVar12 = *(uint *)(param_6 + 0x344);
      *(undefined4 *)(param_6 + 0x340) = 0;
      *(undefined4 *)(param_6 + 0x344) = 0;
      loopIndex = 0;
      if (*(char *)(glContext + 0x85a4) != '\0') {
        iVar10 = param_6 + 0x450;
        do {
          loopIndex = loopIndex + 1;
          *(uint *)(iVar10 + 4) = *(uint *)(iVar10 + 4) | uVar11;
          *(uint *)(iVar10 + 8) = *(uint *)(iVar10 + 8) | uVar12;
          iVar10 = iVar10 + 0x8c;
        } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
      }
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
    }
    matrixFuncDirty = *(int *)(glContext + 0x50ac);
    if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      pendingChangeWords = (int *)(glContext + 0x310);
      cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,piVar6,piVar7,piVar8,uVar9,matrixFuncDirty,fparam_1,forwardedFloatArg2,
                   forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        fparam_1 = fparam_1;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a7208:
        dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
      }
      else {
        loopIndex = 0;
        srcCursor = (int *)(glContext + 0x324);
        do {
          iVar10 = *srcCursor;
          srcCursor = srcCursor + 1;
          if (iVar10 != 0) {
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
            break;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex < 9);
        dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
        if ((dirtyWord3ThenMasked & 0x15555) != 0) {
          if (*(char *)(glContext + 0x2e54) != '\0') {
            piVar6 = (int *)0x0;
            fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
          }
          if (*(char *)(glContext + 0x3094) != '\0') {
            piVar6 = (int *)((int)((unsigned char *)0x0) + 1);
            fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
          }
          goto LAB_000a7208;
        }
      }
      bVar1 = cVar2 == '\0';
      if (bVar1) {
        dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
      }
      else {
        dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
      }
      if (bVar1) {
        stateClean = ((*pendingChangeWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      else {
        stateClean = (((*pendingChangeWords == 0 && *(int *)(glContext + 0x314) == 0) &&
                 (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
                *(int *)(glContext + 800) == 0;
      }
      if (!stateClean) {
        if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
          dispatchFlags = (**(code **)(glContext + 0x4788))
                             (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,pendingChangeWords);
          if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
              ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
             (fparam_1 = extraout_f1_01, (dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0')
             )) {
            if ((dispatchFlags & 4) == 0) {
              dispatchFlags = dispatchFlags & 0xfffffffe;
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
            }
            fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
            if (*(char *)(glContext + 0x759d) == '\0') goto LAB_000a78a8;
          }
        }
        else {
          fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
        }
        remaining = 0x13;
        piVar6 = pendingChangeWords;
        do {
          *piVar6 = 0;
          piVar6 = piVar6 + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
    }
    if (*(char *)(glContext + 0x7580) != '\0') {
      uVar9 = *(uint *)(glContext + 0x48dc);
      piVar6 = mode;
      piVar7 = first;
      piVar8 = count;
      iVar13 = _gleExecuteVertexArrayRange
                         (glContext,forwardedArg5,mode,first,count,uVar9,
                          *(undefined4 *)(glContext + 0x48d8));
      fparam_1 = extraout_f1_02;
      if (iVar13 != 0) {
        return;
      }
    }
LAB_000a76cc:
    matrixFuncDirty = *(int *)(glContext + 0x50ac);
    if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      fparam_1 = extraout_f1_06;
    }
    if (*(char *)(glContext + 0x4691) == '\0') goto LAB_000a78e4;
    framebufferObject = *(int *)(glContext + 0x744c);
    dirtyFlagWords = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,piVar6,piVar7,piVar8,uVar9,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a77bc:
      dirtyWord3ThenMasked2 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      piVar6 = (int *)(glContext + 0x324);
      do {
        iVar10 = *piVar6;
        piVar6 = piVar6 + 1;
        if (iVar10 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      dirtyWord3ThenMasked2 = *(uint *)(glContext + 0x31c);
      if ((dirtyWord3ThenMasked2 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000a77bc;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      dirtyWord3ThenMasked2 = dirtyWord3ThenMasked2 & 0x17000000;
    }
    else {
      dirtyWord3ThenMasked2 = dirtyWord3ThenMasked2 & 0x17ffffff;
    }
    if (bVar1) {
      stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked2 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked2 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (stateClean) goto LAB_000a78e4;
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dispatchFlags2 = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
      if ((((dispatchFlags2 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((dispatchFlags2 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((dispatchFlags2 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((dispatchFlags2 & 4) == 0) {
          dispatchFlags2 = dispatchFlags2 & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,dispatchFlags2);
        if (*(char *)(glContext + 0x759d) == '\0') goto LAB_000a78a8;
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
    remaining = 0x13;
    do {
      *dirtyFlagWords = 0;
      dirtyFlagWords = dirtyFlagWords + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
LAB_000a78e4:
    uVar9 = 0;
    if (*(char *)(glContext + 0x7580) != '\0') {
LAB_000a796c:
      iVar13 = *(int *)(glContext + 0x4890);
      if (iVar13 == 0) {
        iVar13 = _gleGetVertexArrayFunc(glContext);
        *(int *)(glContext + 0x4890) = iVar13;
      }
      *(int **)(glContext + 0x4a14) = count;
      _gleDrawArraysOrElements_Core
                (glContext,mode,first,count,uVar9,*(uint *)(param_6 + 0x324) >> 0x12 & 1,
                 param_6 + 0x20,iVar13);
      *(undefined4 *)(glContext + 0x4a14) = 0;
      return;
    }
    uVar11 = *(uint *)(glContext + 0x514c);
    uVar12 = 0;
    srcCursor2 = (short *)(param_6 + 0xea);
    do {
      uVar4 = uVar11 >> (uVar12 & 0x3f);
      if ((uVar4 & 1) == 0) {
        if (uVar4 == 0) goto LAB_000a796c;
      }
      else {
        lVar16 = ___ashldi3(0,0x1000000,uVar12);
        if ((*(uint *)(param_6 + 800) & (uint)((ulonglong)lVar16 >> 0x20)) != 0 ||
            (*(uint *)(param_6 + 0x324) & (uint)lVar16) != 0) {
          if (*srcCursor2 == 4) {
            uVar9 = 3;
          }
          else if (*srcCursor2 == 3) {
            uVar9 = uVar9 | 1;
          }
        }
      }
      uVar12 = uVar12 + 1;
      srcCursor2 = srcCursor2 + 0xc;
    } while( true );
  }
  if (((((int)piVar8 < 1) || (*(char *)(glContext + 0x30aa) != '\0')) ||
      ((uVar9 != 0 || ((*(int *)(glContext + 0x5434) != 0 || (*(char *)(glContext + 0x4661) != '\0')))))
      ) || ((*(char *)(glContext + 0x4fea) != '\0' ||
            ((*(int *)(glContext + 0x4e1c) != 0x1c00 ||
             ((*(uint *)(glContext + 0x514c) & 0xfffffffc) != 0)))))) goto LAB_000a76cc;
  if (*(char *)(glContext + 0x7580) == '\0') {
    if (((((*(char *)(glContext + 0x4e18) == '\0') && (*(char *)(glContext + 0x4fe2) != '\0')) &&
         ((*(char *)(glContext + 0x316a) == '\0' ||
          ((*(short *)(glContext + 0x3166) == -0x7bae &&
           ((*(uint *)PTR__gle_processor_0011204c & 0x10) != 0)))))) &&
        ((*(char *)(glContext + 0x34da) == '\0' ||
         (*(char *)(*(int *)(glContext + 0x468c) + 0x78) != '\0')))) &&
       ((*(int *)(glContext + 0x34f4) == 0x1d01 && ((*(uint *)(glContext + 0x514c) & 0xfffffffe) == 0)))
       ) goto LAB_000a7454;
    goto LAB_000a76cc;
  }
  if (*(char *)(glContext + 0x53e6) != '\0') goto LAB_000a76cc;
LAB_000a7454:
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1_03;
  }
  if (*(char *)(glContext + 0x4691) == '\0') {
LAB_000a7658:
    if (*(ushort *)(glContext + 0x4992) == (ushort)*(byte *)(glContext + 0x7580)) {
      uVar12 = *(uint *)(glContext + 0x497c);
      uVar11 = *(uint *)(glContext + 0x4980);
      if ((uVar12 & uVar11) != 0) goto LAB_000a7678;
    }
    else {
LAB_000a7678:
      fparam_1 = (double)_gleCompileVertexArray(glContext);
      uVar12 = *(uint *)(glContext + 0x497c);
      uVar11 = *(uint *)(glContext + 0x4980);
    }
    if ((uVar12 & uVar11) == 0) {
      _gleExecuteVertexArray
                (glContext,mode,first,count,*(undefined4 *)(glContext + 0x48dc),
                 *(undefined4 *)(glContext + 0x4978));
      return;
    }
    goto LAB_000a76cc;
  }
  framebufferObject = *(int *)(glContext + 0x744c);
  pendingChangeWords = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,piVar6,piVar7,piVar8,uVar9,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
    fparam_1 = fparam_1;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a7544:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      iVar10 = *srcCursor;
      srcCursor = srcCursor + 1;
      if (iVar10 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        piVar6 = (int *)0x0;
        fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        piVar6 = (int *)((int)((unsigned char *)0x0) + 1);
        fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_000a7544;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (bVar1) {
    stateClean = ((*pendingChangeWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*pendingChangeWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (stateClean) goto LAB_000a7658;
  if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
    fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000a763c:
    remaining = 0x13;
    piVar6 = pendingChangeWords;
    do {
      *piVar6 = 0;
      piVar6 = piVar6 + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
    goto LAB_000a7658;
  }
  dispatchFlags = (**(code **)(glContext + 0x4788))
                     (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,pendingChangeWords);
  if ((((dispatchFlags & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
      ((dispatchFlags & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
     (fparam_1 = extraout_f1_05, (dispatchFlags & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
  goto LAB_000a763c;
  if ((dispatchFlags & 4) == 0) {
    dispatchFlags = dispatchFlags & 0xfffffffe;
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
  }
  fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
  if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000a763c;
LAB_000a78a8:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x506;
LAB_000a78b8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _gleDrawArraysOrElements_VBO_Exec @ 0xa79e0 (1772 bytes) */
void _gleDrawArraysOrElements_VBO_Exec(int glContext,int *mode,int *first,int *count,int *param_5,int arrayStateRecord,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool rendererInfoByte79Zero;
  bool stateClean;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  uint remainingMask;
  int *srcCursor;
  int *dstCursor;
  int *srcCursor2;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int vertexArrayFunc;
  int remaining;
  int loopIndex;
  int rendererRecord;
  int dirtyWord;
  int framebufferObject;
  uint uVar11;
  uint consumedDirtyLo;
  uint dispatchFlags;
  uint dirtyWord3ThenMasked;
  uint consumedDirtyHi;
  uint enabledArrayMask;
  int dirtyWordSecondPath;
  int vertexArrayRangeResult;
  int matrixFuncDirty;
  int remaining2;
  int loopIndex2;
  int *pendingChangeWords;
  uint arrayIndex;
  short *srcCursor3;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double extraout_f1_03;
  longlong arrayDirtyBit;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
LAB_000a7a68:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000a7f7c;
  }
  if ((int *)((int)((unsigned char *)0x8) + 2) <= mode) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_000a7f7c;
  }
  if ((int)count < 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_000a7f7c;
  }
  if ((*(char *)(glContext + 0x4664) != '\0') && (*(int *)(*(int *)(glContext + 0x5420) + 0x4cc) == 0))
  goto LAB_000a7a68;
  if ((*(uint *)(arrayStateRecord + 800) & 1) == 0 && (*(uint *)(arrayStateRecord + 0x324) & 0x10000) == 0) {
    return;
  }
  if (count == (int *)0x0) {
    return;
  }
  dstCursor = first;
  piVar7 = count;
  piVar8 = param_5;
  iVar9 = arrayStateRecord;
  if ((*(uint *)(arrayStateRecord + 800) == (*(uint *)(arrayStateRecord + 0x328) & *(uint *)(arrayStateRecord + 800))) &&
     (*(uint *)(arrayStateRecord + 0x324) == (*(uint *)(arrayStateRecord + 0x32c) & *(uint *)(arrayStateRecord + 0x324)))) {
    if (*(int *)(arrayStateRecord + 0x340) != 0 || *(int *)(arrayStateRecord + 0x344) != 0) {
      consumedDirtyLo = *(uint *)(arrayStateRecord + 0x340);
      consumedDirtyHi = *(uint *)(arrayStateRecord + 0x344);
      *(undefined4 *)(arrayStateRecord + 0x340) = 0;
      *(undefined4 *)(arrayStateRecord + 0x344) = 0;
      loopIndex2 = 0;
      if (*(char *)(glContext + 0x85a4) != '\0') {
        rendererRecord = arrayStateRecord + 0x450;
        do {
          loopIndex2 = loopIndex2 + 1;
          *(uint *)(rendererRecord + 4) = *(uint *)(rendererRecord + 4) | consumedDirtyLo;
          *(uint *)(rendererRecord + 8) = *(uint *)(rendererRecord + 8) | consumedDirtyHi;
          rendererRecord = rendererRecord + 0x8c;
        } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
      }
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
    }
    matrixFuncDirty = *(int *)(glContext + 0x50ac);
    if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(glContext + 0x4691) == '\0') {
LAB_000a7d5c:
      if (*(char *)(glContext + 0x7580) != '\0') {
        iVar9 = *(int *)(glContext + 0x48dc);
        dstCursor = mode;
        piVar7 = first;
        piVar8 = count;
        vertexArrayRangeResult = _gleExecuteVertexArrayRange
                           (glContext,param_5,mode,first,count,iVar9,
                            *(undefined4 *)(glContext + 0x48d8));
        fparam_1 = extraout_f1_02;
        if (vertexArrayRangeResult != 0) {
          return;
        }
      }
      goto LAB_000a7d90;
    }
    framebufferObject = *(int *)(glContext + 0x744c);
    pendingChangeWords = (int *)(glContext + 0x310);
    rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,dstCursor,piVar7,piVar8,iVar9,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a7c38:
      dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex2 = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        dirtyWord = *srcCursor;
        srcCursor = srcCursor + 1;
        if (dirtyWord != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex2 = loopIndex2 + 1;
      } while (loopIndex2 < 9);
      dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
      if ((dirtyWord3ThenMasked & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          dstCursor = (int *)0x0;
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          dstCursor = (int *)((int)((unsigned char *)0x0) + 1);
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000a7c38;
      }
    }
    rendererInfoByte79Zero = rendererInfoByte79 == '\0';
    if (rendererInfoByte79Zero) {
      dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
    }
    else {
      dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
    }
    if (rendererInfoByte79Zero) {
      stateClean = ((*pendingChangeWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      stateClean = (((*pendingChangeWords == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (stateClean) goto LAB_000a7d5c;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000a7d40:
      remaining2 = 0x13;
      dstCursor = pendingChangeWords;
      do {
        *dstCursor = 0;
        dstCursor = dstCursor + 1;
        remaining2 = remaining2 + -1;
      } while (remaining2 != 0);
      goto LAB_000a7d5c;
    }
    dispatchFlags = (**(code **)(glContext + 0x4788))
                       (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,pendingChangeWords);
    if ((((dispatchFlags & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((dispatchFlags & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (dispatchFlags & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_000a7d40;
    if ((dispatchFlags & 4) == 0) {
      dispatchFlags = dispatchFlags & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000a7d40;
LAB_000a7f6c:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x506;
LAB_000a7f7c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
LAB_000a7d90:
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1_03;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_000a7fa8;
  framebufferObject = *(int *)(glContext + 0x744c);
  pendingChangeWords = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,dstCursor,piVar7,piVar8,iVar9,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a7e80:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor2 = (int *)(glContext + 0x324);
    do {
      dirtyWordSecondPath = *srcCursor2;
      srcCursor2 = srcCursor2 + 1;
      if (dirtyWordSecondPath != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_000a7e80;
    }
  }
  rendererInfoByte79Zero = rendererInfoByte79 == '\0';
  if (rendererInfoByte79Zero) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (rendererInfoByte79Zero) {
    stateClean = ((*pendingChangeWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*pendingChangeWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (stateClean) goto LAB_000a7fa8;
  if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
    dispatchFlags = (**(code **)(glContext + 0x4788))
                       (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,pendingChangeWords);
    if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
        ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
       ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
      if ((dispatchFlags & 4) == 0) {
        dispatchFlags = dispatchFlags & 0xfffffffe;
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
      }
      _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
      if (*(char *)(glContext + 0x759d) == '\0') goto LAB_000a7f6c;
    }
  }
  else {
    _gleSwitchToNonRevertRenderer(glContext);
  }
  remaining = 0x13;
  do {
    *pendingChangeWords = 0;
    pendingChangeWords = pendingChangeWords + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
LAB_000a7fa8:
  uVar11 = 0;
  if (*(char *)(glContext + 0x7580) != '\0') {
LAB_000a8030:
    vertexArrayFunc = *(int *)(glContext + 0x4890);
    if (vertexArrayFunc == 0) {
      vertexArrayFunc = _gleGetVertexArrayFunc(glContext);
      *(int *)(glContext + 0x4890) = vertexArrayFunc;
    }
    *(int **)(glContext + 0x4a14) = count;
    _gleDrawArraysOrElements_Core
              (glContext,mode,first,count,uVar11,*(uint *)(arrayStateRecord + 0x324) >> 0x12 & 1,
               arrayStateRecord + 0x20,vertexArrayFunc);
    *(undefined4 *)(glContext + 0x4a14) = 0;
    if (*(int *)(arrayStateRecord + 0x328) != 0 || *(int *)(arrayStateRecord + 0x32c) != 0) {
      return;
    }
    _gleUpdateDrawArraysFuncs(glContext);
    return;
  }
  enabledArrayMask = *(uint *)(glContext + 0x514c);
  arrayIndex = 0;
  srcCursor3 = (short *)(arrayStateRecord + 0xea);
  do {
    remainingMask = enabledArrayMask >> (arrayIndex & 0x3f);
    if ((remainingMask & 1) == 0) {
      if (remainingMask == 0) goto LAB_000a8030;
    }
    else {
      arrayDirtyBit = ___ashldi3(0,0x1000000,arrayIndex);
      if ((*(uint *)(arrayStateRecord + 800) & (uint)((ulonglong)arrayDirtyBit >> 0x20)) != 0 ||
          (*(uint *)(arrayStateRecord + 0x324) & (uint)arrayDirtyBit) != 0) {
        if (*srcCursor3 == 4) {
          uVar11 = 3;
        }
        else if (*srcCursor3 == 3) {
          uVar11 = uVar11 | 1;
        }
      }
    }
    arrayIndex = arrayIndex + 1;
    srcCursor3 = srcCursor3 + 0xc;
  } while( true );
}

/* _gleDrawArraysOrElements_CVA_Exec @ 0xa80cc (1152 bytes) */
void _gleDrawArraysOrElements_CVA_Exec(int glContext,uint mode,undefined4 first,int count,undefined4 param_5,int param_6,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int iVar4;
  int *srcCursor;
  uint uVar6;
  int framebufferObject;
  undefined4 uVar8;
  int matrixFuncDirty;
  int iVar10;
  int remaining;
  int loopIndex;
  uint uVar11;
  uint dispatchFlags;
  uint dirtyWord3ThenMasked;
  int *dirtyFlagWords;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
LAB_000a815c:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000a8388;
  }
  if (9 < mode) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_000a8388;
  }
  if (count < 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_000a8388;
  }
  if ((*(char *)(glContext + 0x4664) != '\0') && (*(int *)(*(int *)(glContext + 0x5420) + 0x4cc) == 0))
  goto LAB_000a815c;
  if ((*(uint *)(param_6 + 800) & 1) == 0 && (*(uint *)(param_6 + 0x324) & 0x10000) == 0) {
    return;
  }
  if (count == 0) {
    return;
  }
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  uVar3 = first;
  iVar10 = count;
  uVar8 = param_5;
  iVar4 = param_6;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    dirtyFlagWords = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar3,iVar10,uVar8,iVar4,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a828c:
      dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        iVar4 = *srcCursor;
        srcCursor = srcCursor + 1;
        if (iVar4 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
      if ((dirtyWord3ThenMasked & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000a828c;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
    }
    else {
      dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
    }
    if (bVar1) {
      stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (!stateClean) {
      if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
        dispatchFlags = (**(code **)(glContext + 0x4788))
                           (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
        if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0')))
        {
          if ((dispatchFlags & 4) == 0) {
            dispatchFlags = dispatchFlags & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
          if (*(char *)(glContext + 0x759d) == '\0') {
            if (*(int *)(glContext + 0x7574) != 0) {
              return;
            }
            glErrorCode = 0x506;
LAB_000a8388:
            *(undefined4 *)(glContext + 0x7574) = glErrorCode;
            return;
          }
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
      }
      remaining = 0x13;
      do {
        *dirtyFlagWords = 0;
        dirtyFlagWords = dirtyFlagWords + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
  }
  if (((((*(int *)(glContext + 0x4988) < 1) || (*(char *)(glContext + 0x30aa) != '\0')) ||
       ((*(char *)(glContext + 0x4664) != '\0' ||
        ((*(int *)(glContext + 0x5434) != 0 || (*(char *)(glContext + 0x4661) != '\0')))))) ||
      (*(char *)(glContext + 0x4fea) != '\0')) ||
     ((*(int *)(glContext + 0x4e1c) != 0x1c00 || ((*(uint *)(glContext + 0x514c) & 0xfffffffc) != 0))))
  goto LAB_000a850c;
  if (*(byte *)(glContext + 0x7580) == 0) {
    if (((((*(char *)(glContext + 0x4e18) != '\0') || (*(char *)(glContext + 0x4fe2) == '\0')) ||
         ((*(char *)(glContext + 0x316a) != '\0' &&
          ((*(short *)(glContext + 0x3166) != -0x7bae ||
           ((*(uint *)PTR__gle_processor_0011204c & 0x10) == 0)))))) ||
        ((*(char *)(glContext + 0x34da) != '\0' &&
         (*(char *)(*(int *)(glContext + 0x468c) + 0x78) == '\0')))) ||
       ((*(int *)(glContext + 0x34f4) != 0x1d01 || ((*(uint *)(glContext + 0x514c) & 0xfffffffe) != 0)))
       ) goto LAB_000a850c;
  }
  else if (*(char *)(glContext + 0x53e6) != '\0') goto LAB_000a850c;
  if (*(ushort *)(glContext + 0x4992) == (ushort)*(byte *)(glContext + 0x7580)) {
    uVar6 = *(uint *)(glContext + 0x497c);
    uVar11 = *(uint *)(glContext + 0x4980);
    if ((uVar6 & uVar11) != 0) goto LAB_000a84c8;
  }
  else {
LAB_000a84c8:
    fparam_1 = (double)_gleCompileVertexArray(glContext);
    uVar6 = *(uint *)(glContext + 0x497c);
    uVar11 = *(uint *)(glContext + 0x4980);
  }
  if ((uVar6 & uVar11) == 0) {
    _gleExecuteVertexArray
              (glContext,mode,first,count,*(undefined4 *)(glContext + 0x48dc),
               *(undefined4 *)(glContext + 0x4978));
    return;
  }
LAB_000a850c:
  ((void (*)())_gleDrawArraysOrElements_IMM_Exec)(glContext,mode,first,count,param_5,param_6,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
             forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

/* _glDrawArrays_Comp @ 0xa854c (48 bytes) */
int _glDrawArrays_Comp(glContext, mode, first, count)
  int glContext;
  undefined4 mode;
  undefined4 first;
  undefined4 count;
{
  undefined4 drawArraysOrElementsResult;
  
  if (*(int *)(glContext + 0x48dc) != 0x14ff) {
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x48dc) = 0x14ff;
    *(undefined4 *)(glContext + 0x48d8) = 0;
    *(undefined4 *)(glContext + 0x4978) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  drawArraysOrElementsResult = ((int (*)())_gleDrawArraysOrElements_Comp)(glContext,mode,first,count);
  return drawArraysOrElementsResult;
}

/* _glDrawArrays_STD_Exec @ 0xa85ec (56 bytes) */
void _glDrawArrays_STD_Exec(int glContext,undefined4 forwardedArg2,undefined4 forwardedArg3,undefined4 forwardedArg4,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  if (*(int *)(glContext + 0x48dc) != 0x14ff) {
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x48dc) = 0x14ff;
    *(undefined4 *)(glContext + 0x48d8) = 0;
    *(undefined4 *)(glContext + 0x4978) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  ((void (*)())_gleDrawArraysOrElements_Exec)(glContext,forwardedArg2,forwardedArg3,forwardedArg4,0,*(int *)(glContext + 0x4a60) + 0x10,forwardedFloatArg1,forwardedFloatArg2,
             forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

