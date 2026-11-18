#include "decls.h"

/* _glLoadTransposeMatrixd_CompExec @ 0x776e8 (56 bytes) */
void _glLoadTransposeMatrixd_CompExec(glContext, m)
  undefined4 glContext;
  undefined4 m;
{
  _glLoadTransposeMatrixd_Comp(glContext,m);
  _glLoadTransposeMatrixd_Exec(glContext,m);
  return;
}

/* _glLoadTransposeMatrixf_ListExec @ 0x77720 (36 bytes) */
int _glLoadTransposeMatrixf_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 listRecord;
{
  ((int (*)())_glLoadTransposeMatrixf_Exec)(glContext,listRecord);
  return 0x40;
}

/* _glLoadTransposeMatrixf_Comp @ 0x77744 (100 bytes) */
int _glLoadTransposeMatrixf_Comp(glContext, m)
  undefined4 glContext;
  int m;
{
  int byteOffset;
  int listRecord;
  int remaining;
  
  listRecord = _gleAddListItem(glContext,PTR__glLoadTransposeMatrixf_ListExec_001101fc,0x40);
  if (listRecord != 0) {
    byteOffset = 0;
    remaining = 0x10;
    do {
      *(undefined4 *)(byteOffset + listRecord) = *(undefined4 *)(byteOffset + m);
      byteOffset = byteOffset + 4;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return listRecord;
}

/* _glLoadTransposeMatrixf_Exec @ 0x777a8 (128 bytes) */
int _glLoadTransposeMatrixf_Exec(glContext, m)
  int glContext;
  undefined4 m;
{
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    m = _gleLoadTransposeMatrixf(m,*(undefined4 *)(glContext + 0x4fec));
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | *(uint *)(glContext + 0x50a8);
    *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | *(uint *)(glContext + 0x50a8);
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return m;
}

/* _glLoadTransposeMatrixf_CompExec @ 0x77828 (56 bytes) */
void _glLoadTransposeMatrixf_CompExec(glContext, m)
  undefined4 glContext;
  undefined4 m;
{
  ((int (*)())_glLoadTransposeMatrixf_Comp)(glContext,m);
  ((int (*)())_glLoadTransposeMatrixf_Exec)(glContext,m);
  return;
}

/* _glMatrixMode_CompExec @ 0x77860 (56 bytes) */
void _glMatrixMode_CompExec(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  _glMatrixMode_Comp(glContext,mode);
  _glMatrixMode_Exec(glContext,mode);
  return;
}

/* _glMultMatrixd_ListExec @ 0x77898 (36 bytes) */
int _glMultMatrixd_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 listRecord;
{
  _glMultMatrixd_Exec(glContext,listRecord);
  return 0x80;
}

/* _glMultMatrixd_Comp @ 0x778bc (100 bytes) */
int _glMultMatrixd_Comp(glContext, m)
  undefined4 glContext;
  int m;
{
  int byteOffset;
  int listRecord;
  int remaining;
  
  listRecord = _gleAddListItem(glContext,PTR__glMultMatrixd_ListExec_00110220,0x80);
  if (listRecord != 0) {
    byteOffset = 0;
    remaining = 0x10;
    do {
      *(undefined8 *)(byteOffset + listRecord) = *(undefined8 *)(byteOffset + m);
      byteOffset = byteOffset + 8;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return listRecord;
}

/* _glMultMatrixd_CompExec @ 0x77920 (56 bytes) */
void _glMultMatrixd_CompExec(glContext, m)
  undefined4 glContext;
  undefined4 m;
{
  ((int (*)())_glMultMatrixd_Comp)(glContext,m);
  _glMultMatrixd_Exec(glContext,m);
  return;
}

/* _glMultMatrixf_ListExec @ 0x77958 (36 bytes) */
int _glMultMatrixf_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 listRecord;
{
  _glMultMatrixf_Exec(glContext,listRecord);
  return 0x40;
}

/* _glMultMatrixf_Comp @ 0x7797c (100 bytes) */
int _glMultMatrixf_Comp(glContext, m)
  undefined4 glContext;
  int m;
{
  int byteOffset;
  int listRecord;
  int remaining;
  
  listRecord = _gleAddListItem(glContext,PTR__glMultMatrixf_ListExec_0011021c,0x40);
  if (listRecord != 0) {
    byteOffset = 0;
    remaining = 0x10;
    do {
      *(undefined4 *)(byteOffset + listRecord) = *(undefined4 *)(byteOffset + m);
      byteOffset = byteOffset + 4;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return listRecord;
}

/* _glMultMatrixf_CompExec @ 0x779e0 (56 bytes) */
void _glMultMatrixf_CompExec(glContext, m)
  undefined4 glContext;
  undefined4 m;
{
  ((int (*)())_glMultMatrixf_Comp)(glContext,m);
  _glMultMatrixf_Exec(glContext,m);
  return;
}

/* _glMultTransposeMatrixd_ListExec @ 0x77a18 (36 bytes) */
int _glMultTransposeMatrixd_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 listRecord;
{
  ((int (*)())_glMultTransposeMatrixd_Exec)(glContext,listRecord);
  return 0x80;
}

/* _glMultTransposeMatrixd_Comp @ 0x77a3c (100 bytes) */
int _glMultTransposeMatrixd_Comp(glContext, m)
  undefined4 glContext;
  int m;
{
  int byteOffset;
  int listRecord;
  int remaining;
  
  listRecord = _gleAddListItem(glContext,PTR__glMultTransposeMatrixd_ListExec_00110218,0x80);
  if (listRecord != 0) {
    byteOffset = 0;
    remaining = 0x10;
    do {
      *(undefined8 *)(byteOffset + listRecord) = *(undefined8 *)(byteOffset + m);
      byteOffset = byteOffset + 8;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return listRecord;
}

/* _glMultTransposeMatrixd_Exec @ 0x77aa0 (140 bytes) */
int _glMultTransposeMatrixd_Exec(glContext, m)
  int glContext;
  undefined4 m;
{
  int iVar1;
  undefined1 auStack_50 [72];
  
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    _gleMultTransposeMatrixd(*(undefined4 *)(glContext + 0x4fec),m,auStack_50);
    iVar1 = _gleCopyMatrix(auStack_50,*(undefined4 *)(glContext + 0x4fec));
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | *(uint *)(glContext + 0x50a8);
    *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | *(uint *)(glContext + 0x50a8);
  }
  else {
    iVar1 = glContext;
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return iVar1;
}

/* _glMultTransposeMatrixd_CompExec @ 0x77b2c (56 bytes) */
void _glMultTransposeMatrixd_CompExec(glContext, m)
  undefined4 glContext;
  undefined4 m;
{
  ((int (*)())_glMultTransposeMatrixd_Comp)(glContext,m);
  ((int (*)())_glMultTransposeMatrixd_Exec)(glContext,m);
  return;
}

/* _glMultTransposeMatrixf_ListExec @ 0x77b64 (36 bytes) */
int _glMultTransposeMatrixf_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 listRecord;
{
  ((int (*)())_glMultTransposeMatrixf_Exec)(glContext,listRecord);
  return 0x40;
}

/* _glMultTransposeMatrixf_Comp @ 0x77b88 (100 bytes) */
int _glMultTransposeMatrixf_Comp(glContext, m)
  undefined4 glContext;
  int m;
{
  int byteOffset;
  int listRecord;
  int remaining;
  
  listRecord = _gleAddListItem(glContext,PTR__glMultTransposeMatrixf_ListExec_00110214,0x40);
  if (listRecord != 0) {
    byteOffset = 0;
    remaining = 0x10;
    do {
      *(undefined4 *)(byteOffset + listRecord) = *(undefined4 *)(byteOffset + m);
      byteOffset = byteOffset + 4;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return listRecord;
}

/* _glMultTransposeMatrixf_Exec @ 0x77bec (140 bytes) */
int _glMultTransposeMatrixf_Exec(glContext, m)
  int glContext;
  undefined4 m;
{
  int iVar1;
  undefined1 auStack_50 [72];
  
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    _gleMultTransposeMatrixf(*(undefined4 *)(glContext + 0x4fec),m,auStack_50);
    iVar1 = _gleCopyMatrix(auStack_50,*(undefined4 *)(glContext + 0x4fec));
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | *(uint *)(glContext + 0x50a8);
    *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | *(uint *)(glContext + 0x50a8);
  }
  else {
    iVar1 = glContext;
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return iVar1;
}

/* _glMultTransposeMatrixf_CompExec @ 0x77c78 (56 bytes) */
void _glMultTransposeMatrixf_CompExec(glContext, m)
  undefined4 glContext;
  undefined4 m;
{
  ((int (*)())_glMultTransposeMatrixf_Comp)(glContext,m);
  ((int (*)())_glMultTransposeMatrixf_Exec)(glContext,m);
  return;
}

/* _glNormal3b_Comp @ 0x77cb0 (196 bytes) */
int _glNormal3b_Comp(glContext, nx, ny, nz)
  undefined4 glContext;
  uint nx;
  uint ny;
  uint nz;
{
  double intToDoubleBias;
  float channelScale;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glNormal_ListExec_00110224,0xc);
  channelScale = FLOAT_00108e98;
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,nx ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e98;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,ny ^ 0x80000000) - intToDoubleBias) * channelScale;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,nz ^ 0x80000000) - intToDoubleBias) * channelScale;
  }
  return listRecord;
}

/* _glNormal3b_Exec @ 0x77d74 (128 bytes) */
void _glNormal3b_Exec(glContext, nx, ny, nz)
  int glContext;
  uint nx;
  uint ny;
  uint nz;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,nx ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e98;
  fVar2 = (float)((double)CONCAT44(0x43300000,nz ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e98;
  *(float *)(glContext + 0x2b4) =
       (float)((double)CONCAT44(0x43300000,ny ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e98
  ;
  *(float *)(glContext + 0x2b0) = fVar1;
  *(float *)(glContext + 0x2b8) = fVar2;
  return;
}

/* _glNormal3b_CompExec @ 0x77df4 (72 bytes) */
void _glNormal3b_CompExec(glContext, nx, ny, nz)
  undefined4 glContext;
  undefined4 nx;
  undefined4 ny;
  undefined4 nz;
{
  ((int (*)())_glNormal3b_Comp)(glContext,nx,ny,nz);
  ((void (*)())_glNormal3b_Exec)(glContext,nx,ny,nz);
  return;
}

/* _glNormal3bv_Comp @ 0x77e3c (212 bytes) */
int _glNormal3bv_Comp(glContext, v)
  undefined4 glContext;
  char *v;
{
  double intToDoubleBias;
  float channelScale;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glNormal_ListExec_00110224,0xc);
  channelScale = FLOAT_00108e98;
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e98;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleBias) * channelScale;
  }
  return listRecord;
}

/* _glNormal3bv_Exec @ 0x77f10 (152 bytes) */
double _glNormal3bv_Exec(glContext, v)
  int glContext;
  char *v;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e98;
  fVar2 = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e98;
  *(float *)(glContext + 0x2b4) =
       (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(glContext + 0x2b0) = fVar1;
  *(float *)(glContext + 0x2b8) = fVar2;
  return;
}

/* _glNormal3bv_CompExec @ 0x77fa8 (56 bytes) */
void _glNormal3bv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glNormal3bv_Comp)(glContext,v);
  ((double (*)())_glNormal3bv_Exec)(glContext,v);
  return;
}

/* _glNormal3d_Comp @ 0x77fe0 (128 bytes) */
float * _glNormal3d_Comp(undefined4 glContext,double nx,double ny,double nz)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glNormal_ListExec_00110224,0xc);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)nx;
    listRecord[1] = (float)ny;
    listRecord[2] = (float)nz;
  }
  return listRecord;
}

/* _glNormal3d_CompExec @ 0x7807c (124 bytes) */
void _glNormal3d_CompExec(int glContext,double nx,double ny,double nz)
{
  ((float * (*)())_glNormal3d_Comp)(glContext,nx,ny,nz);
  *(float *)(glContext + 0x2b4) = (float)ny;
  *(float *)(glContext + 0x2b8) = (float)nz;
  *(float *)(glContext + 0x2b0) = (float)nx;
  return;
}

/* _glNormal3dv_Comp @ 0x780dc (108 bytes) */
int _glNormal3dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glNormal_ListExec_00110224,0xc);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*v;
    listRecord[1] = (float)v[1];
    listRecord[2] = (float)v[2];
  }
  return listRecord;
}

/* _glNormal3dv_Exec @ 0x78148 (40 bytes) */
double _glNormal3dv_Exec(glContext, v)
  int glContext;
  double *v;
{
  double dVar1;
  double dVar2;
  
  dVar1 = v[1];
  dVar2 = v[2];
  *(float *)(glContext + 0x2b0) = (float)*v;
  *(float *)(glContext + 0x2b4) = (float)dVar1;
  *(float *)(glContext + 0x2b8) = (float)dVar2;
  return;
}

/* _glNormal3dv_CompExec @ 0x78170 (56 bytes) */
void _glNormal3dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glNormal3dv_Comp)(glContext,v);
  ((double (*)())_glNormal3dv_Exec)(glContext,v);
  return;
}

/* _glNormal3fv_Comp @ 0x781a8 (96 bytes) */
int _glNormal3fv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glNormal_ListExec_00110224,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *v;
    listRecord[1] = v[1];
    listRecord[2] = v[2];
  }
  return listRecord;
}

/* _glNormal3fv_Exec @ 0x78208 (28 bytes) */
double _glNormal3fv_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = v[1];
  uVar2 = v[2];
  *(undefined4 *)(glContext + 0x2b0) = *v;
  *(undefined4 *)(glContext + 0x2b4) = uVar1;
  *(undefined4 *)(glContext + 0x2b8) = uVar2;
  return;
}

/* _glNormal3fv_CompExec @ 0x78224 (56 bytes) */
void _glNormal3fv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glNormal3fv_Comp)(glContext,v);
  ((double (*)())_glNormal3fv_Exec)(glContext,v);
  return;
}

/* _glNormal3i_Comp @ 0x7825c (208 bytes) */
void _glNormal3i_Comp(glContext, nx, ny, nz)
  undefined4 glContext;
  uint nx;
  uint ny;
  uint nz;
{
  double intToDoubleBias;
  double dVar2;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glNormal_ListExec_00110224,0xc);
  dVar2 = DOUBLE_00108d88;
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)(float)((double)CONCAT44(0x43300000,nx ^ 0x80000000) -
                                     DOUBLE_00108d58) * DOUBLE_00108d88);
    listRecord[1] = (float)((double)(float)((double)CONCAT44(0x43300000,ny ^ 0x80000000) - intToDoubleBias) *
                       dVar2);
    listRecord[2] = (float)((double)(float)((double)CONCAT44(0x43300000,nz ^ 0x80000000) - intToDoubleBias) *
                       dVar2);
  }
  return;
}

/* _glNormal3i_Exec @ 0x7832c (144 bytes) */
void _glNormal3i_Exec(int glContext,uint nx,uint ny,uint nz,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)(float)((double)CONCAT44(0x43300000,nz ^ 0x80000000) - DOUBLE_00108d58) *
          DOUBLE_00108d88;
  dVar1 = (double)(float)((double)CONCAT44(0x43300000,nx ^ 0x80000000) - DOUBLE_00108d58) *
          DOUBLE_00108d88;
  *(float *)(glContext + 0x2b4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,ny ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  *(float *)(glContext + 0x2b8) = (float)dVar2;
  *(float *)(glContext + 0x2b0) = (float)dVar1;
  return;
}

/* _glNormal3i_CompExec @ 0x783bc (72 bytes) */
void _glNormal3i_CompExec(undefined4 glContext,undefined4 nx,undefined4 ny,undefined4 nz,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  double incomingStack_ffffffa8;
  double incomingStack_ffffffb0;
  double incomingStack_ffffffb8;
  
  ((void (*)())_glNormal3i_Exec)(glContext,nx,ny,nz,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,
                   forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffffa8,incomingStack_ffffffb0,incomingStack_ffffffb8)
  ;
  ((void (*)())_glNormal3i_Comp)(glContext,nx,ny,nz);
  return;
}

/* _glNormal3iv_Comp @ 0x78404 (212 bytes) */
int _glNormal3iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  double intToDoubleBias;
  double channelScale;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glNormal_ListExec_00110224,0xc);
  channelScale = DOUBLE_00108d88;
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)(float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) -
                                     DOUBLE_00108d58) * DOUBLE_00108d88);
    listRecord[1] = (float)((double)(float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - intToDoubleBias
                                       ) * channelScale);
    listRecord[2] = (float)((double)(float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - intToDoubleBias
                                       ) * channelScale);
  }
  return listRecord;
}

/* _glNormal3iv_Exec @ 0x784d8 (156 bytes) */
double _glNormal3iv_Exec(int glContext,uint *v,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)(float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - DOUBLE_00108d58) *
          DOUBLE_00108d88;
  dVar1 = (double)(float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58) *
          DOUBLE_00108d88;
  *(float *)(glContext + 0x2b4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) -
                              DOUBLE_00108d58) * DOUBLE_00108d88);
  *(float *)(glContext + 0x2b8) = (float)dVar2;
  *(float *)(glContext + 0x2b0) = (float)dVar1;
  return;
}

/* _glNormal3iv_CompExec @ 0x78574 (56 bytes) */
void _glNormal3iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  unsigned int ghidra_home[8] = { glContext, v, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glNormal3iv_Comp)(glContext,v);
  ((double (*)())_glNormal3iv_Exec)(glContext,v,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                    (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)));
  return;
}

/* _glNormal3s_Comp @ 0x785ac (196 bytes) */
int _glNormal3s_Comp(glContext, nx, ny, nz)
  undefined4 glContext;
  uint nx;
  uint ny;
  uint nz;
{
  double intToDoubleBias;
  float channelScale;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glNormal_ListExec_00110224,0xc);
  channelScale = FLOAT_00108e9c;
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,nx ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e9c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,ny ^ 0x80000000) - intToDoubleBias) * channelScale;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,nz ^ 0x80000000) - intToDoubleBias) * channelScale;
  }
  return listRecord;
}

/* _glNormal3s_Exec @ 0x78670 (128 bytes) */
void _glNormal3s_Exec(glContext, nx, ny, nz)
  int glContext;
  uint nx;
  uint ny;
  uint nz;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,nx ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e9c;
  fVar2 = (float)((double)CONCAT44(0x43300000,nz ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e9c;
  *(float *)(glContext + 0x2b4) =
       (float)((double)CONCAT44(0x43300000,ny ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e9c
  ;
  *(float *)(glContext + 0x2b0) = fVar1;
  *(float *)(glContext + 0x2b8) = fVar2;
  return;
}

/* _glNormal3s_CompExec @ 0x786f0 (72 bytes) */
void _glNormal3s_CompExec(glContext, nx, ny, nz)
  undefined4 glContext;
  undefined4 nx;
  undefined4 ny;
  undefined4 nz;
{
  ((int (*)())_glNormal3s_Comp)(glContext,nx,ny,nz);
  ((void (*)())_glNormal3s_Exec)(glContext,nx,ny,nz);
  return;
}

/* _glNormal3sv_Comp @ 0x78738 (200 bytes) */
int _glNormal3sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  double intToDoubleBias;
  float channelScale;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glNormal_ListExec_00110224,0xc);
  channelScale = FLOAT_00108e9c;
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e9c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleBias) * channelScale;
  }
  return listRecord;
}

/* _glNormal3sv_Exec @ 0x78800 (140 bytes) */
double _glNormal3sv_Exec(glContext, v)
  int glContext;
  short *v;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e9c;
  fVar2 = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e9c;
  *(float *)(glContext + 0x2b4) =
       (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(glContext + 0x2b0) = fVar1;
  *(float *)(glContext + 0x2b8) = fVar2;
  return;
}

/* _glNormal3sv_CompExec @ 0x7888c (56 bytes) */
void _glNormal3sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glNormal3sv_Comp)(glContext,v);
  ((double (*)())_glNormal3sv_Exec)(glContext,v);
  return;
}

/* _glGenQueries_Exec @ 0x788c4 (176 bytes) */
void _glGenQueries_Exec(glContext, n, ids)
  int glContext;
  int n;
  int *ids;
{
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x7444) == 0)) {
    if (-1 < n) {
      iVar4 = _gleGenHashNames(glContext + 0x6440,n);
      if (iVar4 == 0) {
        return;
      }
      iVar3 = 0;
      if (n < 1) {
        return;
      }
      do {
        iVar2 = iVar3 + iVar4;
        iVar3 = iVar3 + 1;
        *ids = iVar2;
        ids = ids + 1;
        n = n + -1;
      } while (n != 0);
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

/* _glDeleteQueries_Exec @ 0x78974 (164 bytes) */
void _glDeleteQueries_Exec(glContext, n, ids)
  int glContext;
  int n;
  undefined4 *ids;
{
  undefined4 uVar1;
  undefined4 glErrorCode;
  
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x7444) == 0)) {
    if (-1 < n) {
      if (n < 1) {
        return;
      }
      do {
        uVar1 = *ids;
        ids = ids + 1;
        _gleDeleteHashNameAndObject(glContext,glContext + 0x6440,uVar1);
        n = n + -1;
      } while (n != 0);
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

/* _glBeginQuery_Exec @ 0x78a18 (792 bytes) */
void _glBeginQuery_Exec(glContext, target, id)
  int glContext;
  int target;
  int id;
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int iVar7;
  int matrixFuncDirty;
  int iVar8;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  double fparam_1;
  double extraout_f1_00;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  if (((-1 < *(short *)(glContext + 0x4a10)) || (*(int *)(glContext + 0x7444) != 0)) || (id == 0))
  {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00078cc8;
  }
  if (target != 0x8914) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_00078cc8;
  }
  iVar8 = id;
  iVar5 = _gleLookupHashObject(glContext + 0x6440,id);
  fparam_1 = extraout_f1;
  if (iVar5 == 0) {
    iVar5 = _gleCreateQueryObject(glContext,id);
    iVar8 = iVar5;
    fparam_1 = (double)_gleAddHashNameAndObject(glContext,glContext + 0x6440,iVar5);
  }
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1_00;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00078cf8;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,iVar8,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
               incomingFpr6,incomingFpr7,incomingFpr8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00078bc4:
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
      goto LAB_00078bc4;
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
         ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((dispatchFlags & 4) == 0) {
          dispatchFlags = dispatchFlags & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
        if (*(char *)(glContext + 0x759d) == '\0') {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x506;
LAB_00078cc8:
          *(undefined4 *)(glContext + 0x7574) = glErrorCode;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
    loopIndex = 0;
    do {
      loopIndex = loopIndex + 1;
      *dirtyFlagWords = 0;
      dirtyFlagWords = dirtyFlagWords + 1;
    } while (loopIndex < 0x13);
  }
LAB_00078cf8:
  (**(code **)(glContext + 0x4700))
            (*(undefined4 *)(glContext + 0x4688),
             *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar5 + 0x10));
  *(int *)(glContext + 0x7444) = iVar5;
  return;
}

/* _glEndQuery_Exec @ 0x78d30 (728 bytes) */
void _glEndQuery_Exec(int glContext,int target,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
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
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  
  if ((-1 < *(short *)(glContext + 0x4a10)) || (*(int *)(glContext + 0x7444) == 0)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00078f98;
  }
  if (target != 0x8914) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_00078f98;
  }
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00078fc8;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00078e94:
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
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_00078e94;
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
         ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((dispatchFlags & 4) == 0) {
          dispatchFlags = dispatchFlags & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
        if (*(char *)(glContext + 0x759d) == '\0') {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x506;
LAB_00078f98:
          *(undefined4 *)(glContext + 0x7574) = glErrorCode;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
    loopIndex = 0;
    do {
      loopIndex = loopIndex + 1;
      *dirtyFlagWords = 0;
      dirtyFlagWords = dirtyFlagWords + 1;
    } while (loopIndex < 0x13);
  }
LAB_00078fc8:
  (**(code **)(glContext + 0x4704))
            (*(undefined4 *)(glContext + 0x4688),
             *(undefined4 *)
              ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x7444) + 0x10));
  *(undefined4 *)(glContext + 0x7444) = 0;
  return;
}

/* _glIsQuery_Exec @ 0x79008 (76 bytes) */
int _glIsQuery_Exec(glContext, id)
  int glContext;
  undefined4 id;
{
  undefined4 uVar1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    uVar1 = _gleIsHashName(glContext + 0x6440,id);
  }
  else {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* _glBeginQuery_Comp @ 0x79054 (84 bytes) */
int _glBeginQuery_Comp(glContext, target, id)
  undefined4 glContext;
  undefined4 target;
  undefined4 id;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glBeginQuery_ListExec_0011022c,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = id;
    *listRecord = target;
  }
  return listRecord;
}

/* _glEndQuery_Comp @ 0x790a8 (76 bytes) */
int _glEndQuery_Comp(glContext, target)
  undefined4 glContext;
  undefined4 target;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glEndQuery_ListExec_00110228,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
  }
  return listRecord;
}

/* _glBeginQuery_CompExec @ 0x790f4 (64 bytes) */
void _glBeginQuery_CompExec(glContext, target, id)
  undefined4 glContext;
  undefined4 target;
  undefined4 id;
{
  ((int (*)())_glBeginQuery_Comp)(glContext,target,id);
  ((void (*)())_glBeginQuery_Exec)(glContext,target,id);
  return;
}

/* _glEndQuery_CompExec @ 0x79134 (56 bytes) */
void _glEndQuery_CompExec(glContext, target)
  undefined4 glContext;
  undefined4 target;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glEndQuery_Comp)(glContext,target);
  ((void (*)())_glEndQuery_Exec)(glContext,target,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glBeginQuery_ListExec @ 0x7916c (44 bytes) */
int _glBeginQuery_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glBeginQuery_Exec)(glContext,*listRecord,listRecord[1]);
  return 8;
}

/* _glEndQuery_ListExec @ 0x79198 (40 bytes) */
undefined4 _glEndQuery_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glEndQuery_Exec)(glContext,*listRecord,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                   forwardedFloatArg8);
  return 4;
}

/* _glGetQueryiv_Exec @ 0x791c0 (152 bytes) */
void _glGetQueryiv_Exec(glContext, target, pname, params)
  int glContext;
  int target;
  int pname;
  undefined4 *params;
{
  undefined4 uVar1;
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8914) {
      if (pname == 0x8864) {
        uVar1 = *(undefined4 *)(*(int *)(glContext + 0x468c) + 0xa8);
LAB_00079248:
        *params = uVar1;
        return;
      }
      if (pname == 0x8865) {
        if (*(int *)(glContext + 0x7444) == 0) {
          *params = 0;
          return;
        }
        uVar1 = *(undefined4 *)(*(int *)(glContext + 0x7444) + 4);
        goto LAB_00079248;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
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

/* _glGetQueryObjectiv_Exec @ 0x79258 (204 bytes) */
void _glGetQueryObjectiv_Exec(glContext, id, pname, params)
  int glContext;
  undefined4 id;
  int pname;
  undefined4 params;
{
  undefined4 glErrorCode;
  int hashObject;
  
  if (((*(short *)(glContext + 0x4a10) < 0) &&
      (hashObject = _gleLookupHashObject(glContext + 0x6440,id), hashObject != 0)) &&
     (*(int *)(glContext + 0x7444) != hashObject)) {
    if (pname - 0x8866U < 2) {
                    
                    
      (**(code **)(glContext + 0x4810))
                (*(undefined4 *)(glContext + 0x4688),
                 *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + hashObject + 0x10),pname,
                 params);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
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

/* _glGetQueryObjectuiv_Exec @ 0x79324 (204 bytes) */
void _glGetQueryObjectuiv_Exec(glContext, id, pname, params)
  int glContext;
  undefined4 id;
  int pname;
  undefined4 params;
{
  undefined4 glErrorCode;
  int hashObject;
  
  if (((*(short *)(glContext + 0x4a10) < 0) &&
      (hashObject = _gleLookupHashObject(glContext + 0x6440,id), hashObject != 0)) &&
     (*(int *)(glContext + 0x7444) != hashObject)) {
    if (pname - 0x8866U < 2) {
                    
                    
      (**(code **)(glContext + 0x4810))
                (*(undefined4 *)(glContext + 0x4688),
                 *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + hashObject + 0x10),pname,
                 params);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
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

