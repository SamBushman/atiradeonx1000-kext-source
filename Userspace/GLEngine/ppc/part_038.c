#include "decls.h"

/* _glWindowPos3dv_Comp @ 0xb1c58 (108 bytes) */
int _glWindowPos3dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glWindowPos3_ListExec_001104cc,0xc);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*v;
    listRecord[1] = (float)v[1];
    listRecord[2] = (float)v[2];
  }
  return listRecord;
}

/* _glWindowPos3dv_CompExec @ 0xb1cc4 (56 bytes) */
void _glWindowPos3dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glWindowPos3dv_Comp)(glContext,v);
  _glWindowPos3dv_Exec(glContext,v);
  return;
}

/* _glWindowPos2f_Exec @ 0xb1cfc (64 bytes) */
void _glWindowPos2f_Exec(int glContext,float x,float y)
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,x,y,(double)FLOAT_00108e50);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glWindowPos2f_Comp @ 0xb1d3c (100 bytes) */
float * _glWindowPos2f_Comp(undefined4 glContext,float x,float y)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glWindowPos2_ListExec_001104d0,8);
  if (listRecord != (float *)0x0) {
    listRecord[1] = (float)y;
    *listRecord = (float)x;
  }
  return listRecord;
}

/* _glWindowPos2f_CompExec @ 0xb1da0 (80 bytes) */
void _glWindowPos2f_CompExec(undefined4 glContext,float x,float y)
{
  ((float * (*)())_glWindowPos2f_Comp)(glContext,x,y);
  ((void (*)())_glWindowPos2f_Exec)(glContext,x,y);
  return;
}

/* _glWindowPos2fv_Exec @ 0xb1df0 (72 bytes) */
void _glWindowPos2fv_Exec(glContext, v)
  int glContext;
  float *v;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,(double)*v,(double)v[1],(double)FLOAT_00108e50);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glWindowPos2fv_Comp @ 0xb1e38 (88 bytes) */
int _glWindowPos2fv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glWindowPos2_ListExec_001104d0,8);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *v;
    listRecord[1] = v[1];
  }
  return listRecord;
}

/* _glWindowPos2fv_CompExec @ 0xb1e90 (56 bytes) */
void _glWindowPos2fv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glWindowPos2fv_Comp)(glContext,v);
  ((void (*)())_glWindowPos2fv_Exec)(glContext,v);
  return;
}

/* _glWindowPos3f_Exec @ 0xb1ec8 (40 bytes) */
void _glWindowPos3f_Exec(int glContext,float x,float y,double z)
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,x,y,z);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glWindowPos3f_Comp @ 0xb1ef0 (116 bytes) */
float * _glWindowPos3f_Comp(undefined4 glContext,float x,float y,float z)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glWindowPos3_ListExec_001104cc,0xc);
  if (listRecord != (float *)0x0) {
    listRecord[2] = (float)z;
    *listRecord = (float)x;
    listRecord[1] = (float)y;
  }
  return listRecord;
}

/* _glWindowPos3f_CompExec @ 0xb1f64 (96 bytes) */
void _glWindowPos3f_CompExec(undefined4 glContext,float x,float y,float z)
{
  ((float * (*)())_glWindowPos3f_Comp)(glContext,x,y,z);
  ((void (*)())_glWindowPos3f_Exec)(glContext,x,y,z);
  return;
}

/* _glWindowPos3fv_Exec @ 0xb1fc4 (52 bytes) */
void _glWindowPos3fv_Exec(glContext, v)
  int glContext;
  float *v;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,(double)*v,(double)v[1],(double)v[2]);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glWindowPos3fv_Comp @ 0xb1ff8 (96 bytes) */
int _glWindowPos3fv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glWindowPos3_ListExec_001104cc,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *v;
    listRecord[1] = v[1];
    listRecord[2] = v[2];
  }
  return listRecord;
}

/* _glWindowPos3fv_CompExec @ 0xb2058 (56 bytes) */
void _glWindowPos3fv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glWindowPos3fv_Comp)(glContext,v);
  ((void (*)())_glWindowPos3fv_Exec)(glContext,v);
  return;
}

/* _glWindowPos2i_Exec @ 0xb2090 (148 bytes) */
void _glWindowPos2i_Exec(glContext, x, y)
  int glContext;
  uint x;
  uint y;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50);
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos2i_Comp @ 0xb2124 (144 bytes) */
int _glWindowPos2i_Comp(glContext, x, y)
  undefined4 glContext;
  uint x;
  uint y;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glWindowPos2_ListExec_001104d0,8);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glWindowPos2i_CompExec @ 0xb21b4 (64 bytes) */
void _glWindowPos2i_CompExec(glContext, x, y)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
{
  ((int (*)())_glWindowPos2i_Comp)(glContext,x,y);
  ((void (*)())_glWindowPos2i_Exec)(glContext,x,y);
  return;
}

/* _glWindowPos2iv_Exec @ 0xb21f4 (156 bytes) */
void _glWindowPos2iv_Exec(glContext, v)
  int glContext;
  uint *v;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50);
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos2iv_Comp @ 0xb2290 (148 bytes) */
int _glWindowPos2iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glWindowPos2_ListExec_001104d0,8);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glWindowPos2iv_CompExec @ 0xb2324 (56 bytes) */
void _glWindowPos2iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glWindowPos2iv_Comp)(glContext,v);
  ((void (*)())_glWindowPos2iv_Exec)(glContext,v);
  return;
}

/* _glWindowPos3i_Exec @ 0xb235c (160 bytes) */
void _glWindowPos3i_Exec(glContext, x, y, z)
  int glContext;
  uint x;
  uint y;
  uint z;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos3i_Comp @ 0xb23fc (176 bytes) */
int _glWindowPos3i_Comp(glContext, x, y, z)
  undefined4 glContext;
  uint x;
  uint y;
  uint z;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glWindowPos3_ListExec_001104cc,0xc);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glWindowPos3i_CompExec @ 0xb24ac (72 bytes) */
void _glWindowPos3i_CompExec(glContext, x, y, z)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 z;
{
  ((int (*)())_glWindowPos3i_Comp)(glContext,x,y,z);
  ((void (*)())_glWindowPos3i_Exec)(glContext,x,y,z);
  return;
}

/* _glWindowPos3iv_Exec @ 0xb24f4 (172 bytes) */
void _glWindowPos3iv_Exec(glContext, v)
  int glContext;
  uint *v;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos3iv_Comp @ 0xb25a0 (180 bytes) */
int _glWindowPos3iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glWindowPos3_ListExec_001104cc,0xc);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glWindowPos3iv_CompExec @ 0xb2654 (56 bytes) */
void _glWindowPos3iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glWindowPos3iv_Comp)(glContext,v);
  ((void (*)())_glWindowPos3iv_Exec)(glContext,v);
  return;
}

/* _glWindowPos2s_Exec @ 0xb268c (148 bytes) */
void _glWindowPos2s_Exec(glContext, x, y)
  int glContext;
  uint x;
  uint y;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50);
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos2s_Comp @ 0xb2720 (144 bytes) */
int _glWindowPos2s_Comp(glContext, x, y)
  undefined4 glContext;
  uint x;
  uint y;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glWindowPos2_ListExec_001104d0,8);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glWindowPos2s_CompExec @ 0xb27b0 (64 bytes) */
void _glWindowPos2s_CompExec(glContext, x, y)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
{
  ((int (*)())_glWindowPos2s_Comp)(glContext,x,y);
  ((void (*)())_glWindowPos2s_Exec)(glContext,x,y);
  return;
}

/* _glWindowPos2sv_Exec @ 0xb27f0 (156 bytes) */
void _glWindowPos2sv_Exec(glContext, v)
  int glContext;
  short *v;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000)
                                            - DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50);
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos2sv_Comp @ 0xb288c (148 bytes) */
int _glWindowPos2sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glWindowPos2_ListExec_001104d0,8);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glWindowPos2sv_CompExec @ 0xb2920 (56 bytes) */
void _glWindowPos2sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glWindowPos2sv_Comp)(glContext,v);
  ((void (*)())_glWindowPos2sv_Exec)(glContext,v);
  return;
}

/* _glWindowPos3s_Exec @ 0xb2958 (160 bytes) */
void _glWindowPos3s_Exec(glContext, x, y, z)
  int glContext;
  uint x;
  uint y;
  uint z;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos3s_Comp @ 0xb29f8 (176 bytes) */
int _glWindowPos3s_Comp(glContext, x, y, z)
  undefined4 glContext;
  uint x;
  uint y;
  uint z;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glWindowPos3_ListExec_001104cc,0xc);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glWindowPos3s_CompExec @ 0xb2aa8 (72 bytes) */
void _glWindowPos3s_CompExec(glContext, x, y, z)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 z;
{
  ((int (*)())_glWindowPos3s_Comp)(glContext,x,y,z);
  ((void (*)())_glWindowPos3s_Exec)(glContext,x,y,z);
  return;
}

/* _glWindowPos3sv_Exec @ 0xb2af0 (172 bytes) */
void _glWindowPos3sv_Exec(glContext, v)
  int glContext;
  short *v;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000)
                                            - DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glWindowPos3sv_Comp @ 0xb2b9c (180 bytes) */
int _glWindowPos3sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  double intToDoubleBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glWindowPos3_ListExec_001104cc,0xc);
  intToDoubleBias = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58);
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleBias);
    listRecord[2] = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleBias);
  }
  return listRecord;
}

/* _glWindowPos3sv_CompExec @ 0xb2c50 (56 bytes) */
void _glWindowPos3sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glWindowPos3sv_Comp)(glContext,v);
  ((void (*)())_glWindowPos3sv_Exec)(glContext,v);
  return;
}

/* _glCombinerParameterfvNV_Exec @ 0xb2c88 (568 bytes) */
void _glCombinerParameterfvNV_Exec(glContext, pname, params)
  int glContext;
  uint pname;
  float *params;
{
  float fVar1;
  float floatZero;
  float fVar2;
  float fVar3;
  float floatZero2;
  float fVar4;
  float floatZero3;
  float fVar5;
  float floatZero4;
  undefined4 glErrorCode;
  int iVar7;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (pname == 0x854e) {
      fVar1 = *params;
      if ((!(fVar1 < 1.0)) &&
         (!((float)((double)CONCAT44(0x43300000,
                                     *(uint *)(*(int *)(glContext + 0x468c) + 0x98) ^ 0x80000000) -
                   DOUBLE_00108d58) < fVar1))) {
        *(int *)(glContext + 0x41fc) = (int)fVar1;
        goto LAB_000b2eb0;
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
    }
    else {
      if (pname < 0x854f) {
        if (pname - 0x852a < 2) {
          fVar1 = *params;
          fVar2 = params[3];
          fVar3 = params[1];
          fVar4 = params[2];
          floatZero4 = FLOAT_00108e50;
          if ((!(fVar1 < 0.0)) && (fVar5 = fVar1, 1.0 < fVar1)) {
            fVar5 = FLOAT_00108e54;
          }
          floatZero = FLOAT_00108e50;
          if ((!(fVar3 < 0.0)) && (fVar1 = fVar3, 1.0 < fVar3)) {
            fVar1 = FLOAT_00108e54;
          }
          floatZero2 = FLOAT_00108e50;
          if ((!(fVar4 < 0.0)) && (fVar3 = fVar4, 1.0 < fVar4)) {
            fVar3 = FLOAT_00108e54;
          }
          floatZero3 = FLOAT_00108e50;
          if ((!(fVar2 < 0.0)) && (fVar4 = fVar2, 1.0 < fVar2)) {
            fVar4 = FLOAT_00108e54;
          }
          iVar7 = (pname - 0x852a) * 0x10 + glContext;
          *(float *)(iVar7 + 0x420c) = fVar4;
          *(float *)(iVar7 + 0x4200) = fVar5;
          *(float *)(iVar7 + 0x4204) = fVar1;
          *(float *)(iVar7 + 0x4208) = fVar3;
LAB_000b2eb0:
          *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x1000000;
          return;
        }
      }
      else if (pname == 0x854f) {
        *(bool *)(glContext + 0x4620) = *params != 0.0;
        goto LAB_000b2eb0;
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
    }
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

/* _glCombinerStageParameterfvNV_Exec @ 0xb2ec0 (404 bytes) */
void _glCombinerStageParameterfvNV_Exec(glContext, stage, pname, params)
  int glContext;
  int stage;
  int pname;
  float *params;
{
  float fVar1;
  float floatZero;
  float fVar2;
  float fVar3;
  float floatZero2;
  float fVar4;
  float floatZero3;
  float fVar5;
  float floatZero4;
  undefined4 glErrorCode;
  int iVar7;
  
  iVar7 = stage + -0x8550;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (((-1 < iVar7) && (iVar7 < *(int *)(*(int *)(glContext + 0x468c) + 0x98))) &&
       (pname - 0x852aU < 2)) {
      fVar1 = *params;
      fVar2 = params[3];
      fVar3 = params[2];
      fVar4 = params[1];
      floatZero4 = FLOAT_00108e50;
      if ((!(fVar1 < 0.0)) && (fVar5 = fVar1, 1.0 < fVar1)) {
        fVar5 = FLOAT_00108e54;
      }
      floatZero = FLOAT_00108e50;
      if ((!(fVar4 < 0.0)) && (fVar1 = fVar4, 1.0 < fVar4)) {
        fVar1 = FLOAT_00108e54;
      }
      floatZero3 = FLOAT_00108e50;
      if ((!(fVar3 < 0.0)) && (fVar4 = fVar3, 1.0 < fVar3)) {
        fVar4 = FLOAT_00108e54;
      }
      floatZero2 = FLOAT_00108e50;
      if ((!(fVar2 < 0.0)) && (fVar3 = fVar2, 1.0 < fVar2)) {
        fVar3 = FLOAT_00108e54;
      }
      iVar7 = (iVar7 * 8 + (pname - 0x852aU)) * 0x10 + glContext;
      *(float *)(iVar7 + 0x428c) = fVar3;
      *(float *)(iVar7 + 0x4280) = fVar5;
      *(float *)(iVar7 + 0x4284) = fVar1;
      *(float *)(iVar7 + 0x4288) = fVar4;
      *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x1000000;
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

/* _glCombinerParameterfNV_Exec @ 0xb3054 (80 bytes) */
void _glCombinerParameterfNV_Exec(int glContext,int pname,float param)
{
  float fStack00000020;
  
  fStack00000020 = (float)param;
  if (pname - 0x854eU < 2) {
    ((void (*)())_glCombinerParameterfvNV_Exec)(glContext,pname,&STACKARG(0x20));
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x500;
  }
  return;
}

/* _glCombinerParameterivNV_Exec @ 0xb30a4 (592 bytes) */
void _glCombinerParameterivNV_Exec(int glContext,uint pname,uint *params,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  float fVar1;
  float floatZero;
  float fVar2;
  float floatZero2;
  float fVar3;
  float floatZero3;
  float fVar4;
  float fVar5;
  float floatZero4;
  undefined4 glErrorCode;
  int iVar7;
  uint uVar8;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (pname == 0x854e) {
      uVar8 = *params;
      if ((0 < (int)uVar8) && ((int)uVar8 <= *(int *)(*(int *)(glContext + 0x468c) + 0x98))) {
        *(uint *)(glContext + 0x41fc) = uVar8;
        goto LAB_000b32e4;
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
    }
    else {
      if (pname < 0x854f) {
        if (pname - 0x852a < 2) {
          fVar1 = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
          fVar2 = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - DOUBLE_00108d58);
          fVar3 = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - DOUBLE_00108d58);
          fVar4 = (float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - DOUBLE_00108d58);
          floatZero4 = FLOAT_00108e50;
          if ((!(fVar1 < 0.0)) && (fVar5 = fVar1, 1.0 < fVar1)) {
            fVar5 = FLOAT_00108e54;
          }
          floatZero = FLOAT_00108e50;
          if ((!(fVar2 < 0.0)) && (fVar1 = fVar2, 1.0 < fVar2)) {
            fVar1 = FLOAT_00108e54;
          }
          floatZero2 = FLOAT_00108e50;
          if ((!(fVar3 < 0.0)) && (fVar2 = fVar3, 1.0 < fVar3)) {
            fVar2 = FLOAT_00108e54;
          }
          floatZero3 = FLOAT_00108e50;
          if ((!(fVar4 < 0.0)) && (fVar3 = fVar4, 1.0 < fVar4)) {
            fVar3 = FLOAT_00108e54;
          }
          iVar7 = (pname - 0x852a) * 0x10 + glContext;
          *(float *)(iVar7 + 0x420c) = fVar3;
          *(float *)(iVar7 + 0x4200) = fVar5;
          *(float *)(iVar7 + 0x4204) = fVar1;
          *(float *)(iVar7 + 0x4208) = fVar2;
LAB_000b32e4:
          *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x1000000;
          return;
        }
      }
      else if (pname == 0x854f) {
        *(char *)(glContext + 0x4620) = '\x01' - (*params == 0);
        goto LAB_000b32e4;
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
    }
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

/* _glCombinerParameteriNV_Exec @ 0xb32f4 (80 bytes) */
void _glCombinerParameteriNV_Exec(int glContext,int pname,undefined4 param,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  undefined4 uStack00000020;
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  
  if (pname - 0x854eU < 2) {
    uStack00000020 = param;
    ((void (*)())_glCombinerParameterivNV_Exec)(glContext,pname,&STACKARG(0x20),forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,
               forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffffb8,incomingStack_ffffffc0);
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x500;
  }
  return;
}

/* _glCombinerInputNV_Exec @ 0xb3344 (336 bytes) */
void _glCombinerInputNV_Exec(glContext, stage, portion, variable, input, mapping, componentUsage)
  int glContext;
  int stage;
  int portion;
  int variable;
  uint input;
  int mapping;
  uint componentUsage;
{
  bool bVar1;
  undefined4 glErrorCode;
  int iVar3;
  int iVar4;
  
  iVar4 = stage + -0x8550;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((-1 < iVar4) && (iVar4 < *(int *)(*(int *)(glContext + 0x468c) + 0x98))) {
      bVar1 = portion == 0x1906;
      if (bVar1) {
        iVar3 = 0;
      }
      else {
        iVar3 = 1;
        if (portion != 0x1907) goto LAB_000b3378;
      }
      if (variable - 0x8523U < 4) {
        if (((input < 0x84c0) ||
            (*(ushort *)(*(int *)(glContext + 0x468c) + 0xb4) + 0x84c0 <= input)) &&
           (input != 0xb60)) {
          if (input < 0xb61) {
            if (input == 0) goto LAB_000b33fc;
          }
          else if (input - 0x852a < 6) goto LAB_000b33fc;
        }
        else {
LAB_000b33fc:
          if (mapping - 0x8536U < 8) {
            if (componentUsage == 0x1906) {
              bVar1 = input == 0xb60;
joined_r0x000b3430:
              if (!bVar1) {
                iVar4 = (iVar4 * 0x10 + iVar3 * 6 + (variable - 0x8523U)) * 8 + glContext;
                *(short *)(iVar4 + 0x4222) = (short)componentUsage;
                *(short *)(iVar4 + 0x4220) = (short)input;
                *(short *)(iVar4 + 0x4224) = (short)mapping;
                *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x1000000;
                return;
              }
              goto LAB_000b3448;
            }
            if (componentUsage < 0x1907) {
              if (componentUsage == 0x1905) {
                bVar1 = portion == 0x1907;
                goto joined_r0x000b3430;
              }
            }
            else if (componentUsage == 0x1907) goto joined_r0x000b3430;
          }
        }
      }
    }
LAB_000b3378:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
LAB_000b3448:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCombinerOutputNV_Exec @ 0xb3494 (504 bytes) */
void _glCombinerOutputNV_Exec(glContext, stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum)
  int glContext;
  int stage;
  int portion;
  uint abOutput;
  uint cdOutput;
  uint sumOutput;
  uint scale;
  int bias;
  undefined4 abDotProduct;
  undefined4 cdDotProduct;
  undefined4 muxSum;
{
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = stage + -0x8550;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((-1 < iVar2) && (iVar4 = *(int *)(glContext + 0x468c), iVar2 < *(int *)(iVar4 + 0x98))) {
      if (portion == 0x1906) {
        iVar3 = 0;
        if (((char)abDotProduct != '\0') || ((char)cdDotProduct != '\0')) goto LAB_000b362c;
      }
      else {
        iVar3 = 1;
        if (portion != 0x1907) goto LAB_000b35d0;
      }
      if ((bias == 0) || (bias == 0x8541)) {
        if (scale == 0x853e) {
LAB_000b354c:
          if (((((0x84bf < abOutput) && (abOutput < *(ushort *)(iVar4 + 0xb4) + 0x84c0)) ||
               (abOutput - 0x852c < 5)) &&
              (((0x84bf < cdOutput && (cdOutput < *(ushort *)(iVar4 + 0xb4) + 0x84c0)) ||
               (cdOutput - 0x852c < 5)))) &&
             (((0x84bf < sumOutput && (sumOutput < *(ushort *)(iVar4 + 0xb4) + 0x84c0)) ||
              (sumOutput - 0x852c < 5)))) {
            if (((sumOutput != abOutput) || (sumOutput == 0x8530)) &&
               (((sumOutput != cdOutput || (sumOutput == 0x8530)) &&
                ((abOutput != cdOutput || (cdOutput == 0x8530)))))) {
              iVar2 = iVar2 * 0x80 + iVar3 * 0x30 + glContext;
              *(undefined1 *)(iVar2 + 0x4242) = (undefined1)muxSum;
              *(short *)(iVar2 + 0x4248) = (short)abOutput;
              *(short *)(iVar2 + 0x424a) = (short)cdOutput;
              *(short *)(iVar2 + 0x424c) = (short)sumOutput;
              *(short *)(iVar2 + 0x4244) = (short)scale;
              *(short *)(iVar2 + 0x4246) = (short)bias;
              *(char *)(iVar2 + 0x4240) = (char)abDotProduct;
              *(char *)(iVar2 + 0x4241) = (char)cdDotProduct;
              *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x1000000;
              return;
            }
            goto LAB_000b362c;
          }
        }
        else if (scale < 0x853f) {
          if (scale == 0) goto LAB_000b354c;
        }
        else if (scale < 0x8541) {
          if (bias != 0) goto LAB_000b362c;
          goto LAB_000b354c;
        }
      }
    }
LAB_000b35d0:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
LAB_000b362c:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glFinalCombinerInputNV_Exec @ 0xb368c (336 bytes) */
void _glFinalCombinerInputNV_Exec(glContext, variable, input, mapping, componentUsage)
  int glContext;
  int variable;
  uint input;
  int mapping;
  uint componentUsage;
{
  undefined4 glErrorCode;
  int iVar2;
  uint uVar3;
  
  uVar3 = variable - 0x8523;
  if (-1 < *(short *)(glContext + 0x4a10)) goto LAB_000b37a0;
  if (6 < uVar3) goto LAB_000b36a8;
  if ((input < 0x84c0) || (*(ushort *)(*(int *)(glContext + 0x468c) + 0xb4) + 0x84c0 <= input)) {
    if (input < 0x8530) {
      if (((0x8529 < input) || (input == 0)) || (input == 0xb60)) goto LAB_000b3714;
    }
    else if (input - 0x8531 < 2) goto LAB_000b3714;
  }
  else {
LAB_000b3714:
    if (((3 < (int)uVar3) && (input - 0x8531 < 2)) || ((uVar3 == 0 && (input == 0x8532)))) {
LAB_000b37a0:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x502;
      goto LAB_000b36b8;
    }
    if (mapping - 0x8536U < 2) {
      if (componentUsage == 0x1906) {
        if (1 < input - 0x8531) {
LAB_000b37b4:
          iVar2 = uVar3 * 8 + glContext;
          *(short *)(iVar2 + 0x4626) = (short)componentUsage;
          *(short *)(iVar2 + 0x4624) = (short)input;
          *(short *)(iVar2 + 0x4628) = (short)mapping;
          *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 0x1000000;
          return;
        }
        goto LAB_000b37a0;
      }
      if (componentUsage < 0x1907) {
        if (componentUsage == 0x1905) {
          if (uVar3 == 6) goto LAB_000b37b4;
          goto LAB_000b37a0;
        }
      }
      else if (componentUsage == 0x1907) {
        if (uVar3 != 6) goto LAB_000b37b4;
        goto LAB_000b37a0;
      }
    }
  }
LAB_000b36a8:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_000b36b8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetCombinerStageParameterfvNV_Exec @ 0xb37dc (124 bytes) */
void _glGetCombinerStageParameterfvNV_Exec(glContext, stage, pname, params, unusedArg5, unusedArg6, unusedArg7)
  int glContext;
  int stage;
  int pname;
  undefined4 *params;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  int combinerIndexThenConstantRecord;
  
  combinerIndexThenConstantRecord = stage + -0x8550;
  if (((-1 < combinerIndexThenConstantRecord) && (combinerIndexThenConstantRecord < *(int *)(*(int *)(glContext + 0x468c) + 0x98))) &&
     (pname - 0x852aU < 2)) {
    combinerIndexThenConstantRecord = (combinerIndexThenConstantRecord * 8 + (pname - 0x852aU)) * 0x10 + glContext;
    *params = *(undefined4 *)(combinerIndexThenConstantRecord + 0x4280);
    params[1] = *(undefined4 *)(combinerIndexThenConstantRecord + 0x4284);
    params[2] = *(undefined4 *)(combinerIndexThenConstantRecord + 0x4288);
    params[3] = *(undefined4 *)(combinerIndexThenConstantRecord + 0x428c);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x500;
  return;
}

/* _glGetCombinerInputParameterfvNV_Exec @ 0xb3858 (292 bytes) */
void _glGetCombinerInputParameterfvNV_Exec(int glContext,int stage,int portion,int variable,uint pname,float *params,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int portionIndex;
  int stageIndex;
  uint variableIndexThenFieldValue;
  
  stageIndex = stage + -0x8550;
  variableIndexThenFieldValue = variable - 0x8523;
  if ((-1 < stageIndex) && (stageIndex < *(int *)(*(int *)(glContext + 0x468c) + 0x98))) {
    if (portion == 0x1906) {
      portionIndex = 0;
    }
    else {
      portionIndex = 1;
      if (portion != 0x1907) goto LAB_000b3964;
    }
    if (variableIndexThenFieldValue < 4) {
      if (pname == 0x8543) {
        variableIndexThenFieldValue = (uint)*(ushort *)((stageIndex * 0x10 + portionIndex * 6 + variableIndexThenFieldValue) * 8 + glContext + 0x4224);
LAB_000b391c:
        *params = GH_U2F((unsigned int)((variableIndexThenFieldValue | 0x4b000000))) - 8388608.0;
        return;
      }
      if (pname < 0x8544) {
        if (pname == 0x8542) {
          variableIndexThenFieldValue = (uint)*(ushort *)((stageIndex * 0x10 + portionIndex * 6 + variableIndexThenFieldValue) * 8 + glContext + 0x4220);
          goto LAB_000b391c;
        }
      }
      else if (pname == 0x8544) {
        variableIndexThenFieldValue = (uint)*(ushort *)((stageIndex * 0x10 + portionIndex * 6 + variableIndexThenFieldValue) * 8 + glContext + 0x4222);
        goto LAB_000b391c;
      }
    }
  }
LAB_000b3964:
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x500;
    return;
  }
  return;
}

/* _glGetCombinerInputParameterivNV_Exec @ 0xb397c (260 bytes) */
void _glGetCombinerInputParameterivNV_Exec(glContext, stage, portion, variable, pname, params)
  int glContext;
  int stage;
  int portion;
  int variable;
  uint pname;
  uint *params;
{
  int portionIndex;
  int combinerIndex;
  uint variableIndexThenQueryValue;
  
  combinerIndex = stage + -0x8550;
  variableIndexThenQueryValue = variable - 0x8523;
  if ((-1 < combinerIndex) && (combinerIndex < *(int *)(*(int *)(glContext + 0x468c) + 0x98))) {
    if (portion == 0x1906) {
      portionIndex = 0;
    }
    else {
      portionIndex = 1;
      if (portion != 0x1907) goto LAB_000b3a68;
    }
    if (variableIndexThenQueryValue < 4) {
      if (pname == 0x8543) {
        variableIndexThenQueryValue = (uint)*(ushort *)((combinerIndex * 0x10 + portionIndex * 6 + variableIndexThenQueryValue) * 8 + glContext + 0x4224);
LAB_000b3a40:
        *params = variableIndexThenQueryValue;
        return;
      }
      if (pname < 0x8544) {
        if (pname == 0x8542) {
          variableIndexThenQueryValue = (uint)*(ushort *)((combinerIndex * 0x10 + portionIndex * 6 + variableIndexThenQueryValue) * 8 + glContext + 0x4220);
          goto LAB_000b3a40;
        }
      }
      else if (pname == 0x8544) {
        variableIndexThenQueryValue = (uint)*(ushort *)((combinerIndex * 0x10 + portionIndex * 6 + variableIndexThenQueryValue) * 8 + glContext + 0x4222);
        goto LAB_000b3a40;
      }
    }
  }
LAB_000b3a68:
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x500;
    return;
  }
  return;
}

/* _glGetCombinerOutputParameterfvNV_Exec_body @ 0xb3a84 (364 bytes) */
void _glGetCombinerOutputParameterfvNV_Exec_body(int glContext,int param_2,int param_3,undefined4 param_4,float *param_5,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = param_2 + 0x7ab0;
  if ((-1 < iVar1) && (iVar1 < *(int *)(*(int *)(glContext + 0x468c) + 0x98))) {
    if (param_3 == 0x1906) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
      if (param_3 != 0x1907) goto switchD_000b3af0_default;
    }
    switch(param_4) {
    case 0x8545:
      uVar2 = (uint)*(byte *)(iVar1 * 0x80 + iVar3 * 0x30 + glContext + 0x4240);
      break;
    case 0x8546:
      uVar2 = (uint)*(byte *)(iVar1 * 0x80 + iVar3 * 0x30 + glContext + 0x4241);
      break;
    case 0x8547:
      uVar2 = (uint)*(byte *)(iVar1 * 0x80 + iVar3 * 0x30 + glContext + 0x4242);
      break;
    case 0x8548:
      uVar2 = (uint)*(ushort *)(iVar1 * 0x80 + iVar3 * 0x30 + glContext + 0x4244);
      break;
    case 0x8549:
      uVar2 = (uint)*(ushort *)(iVar1 * 0x80 + iVar3 * 0x30 + glContext + 0x4246);
      break;
    case 0x854a:
      uVar2 = (uint)*(ushort *)(iVar1 * 0x80 + iVar3 * 0x30 + glContext + 0x4248);
      break;
    case 0x854b:
      uVar2 = (uint)*(ushort *)(iVar1 * 0x80 + iVar3 * 0x30 + glContext + 0x424a);
      break;
    case 0x854c:
      uVar2 = (uint)*(ushort *)(iVar1 * 0x80 + iVar3 * 0x30 + glContext + 0x424c);
      break;
    default:
      goto switchD_000b3af0_default;
    }
    *param_5 = GH_U2F((unsigned int)((uVar2 | 0x4b000000))) - 8388608.0;
    return;
  }
switchD_000b3af0_default:
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x500;
    return;
  }
  return;
}

/* _glGetCombinerOutputParameterivNV_Exec_body @ 0xb3c14 (332 bytes) */
void _glGetCombinerOutputParameterivNV_Exec_body(glContext, param_2, param_3, param_4, param_5)
  int glContext;
  int param_2;
  int param_3;
  undefined4 param_4;
  uint *param_5;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_2 + 0x7ab0;
  if ((-1 < iVar2) && (iVar2 < *(int *)(*(int *)(glContext + 0x468c) + 0x98))) {
    if (param_3 == 0x1906) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
      if (param_3 != 0x1907) goto switchD_000b3c80_default;
    }
    switch(param_4) {
    case 0x8545:
      uVar1 = (uint)*(byte *)(iVar2 * 0x80 + iVar3 * 0x30 + glContext + 0x4240);
      break;
    case 0x8546:
      uVar1 = (uint)*(byte *)(iVar2 * 0x80 + iVar3 * 0x30 + glContext + 0x4241);
      break;
    case 0x8547:
      uVar1 = (uint)*(byte *)(iVar2 * 0x80 + iVar3 * 0x30 + glContext + 0x4242);
      break;
    case 0x8548:
      uVar1 = (uint)*(ushort *)(iVar2 * 0x80 + iVar3 * 0x30 + glContext + 0x4244);
      break;
    case 0x8549:
      uVar1 = (uint)*(ushort *)(iVar2 * 0x80 + iVar3 * 0x30 + glContext + 0x4246);
      break;
    case 0x854a:
      uVar1 = (uint)*(ushort *)(iVar2 * 0x80 + iVar3 * 0x30 + glContext + 0x4248);
      break;
    case 0x854b:
      uVar1 = (uint)*(ushort *)(iVar2 * 0x80 + iVar3 * 0x30 + glContext + 0x424a);
      break;
    case 0x854c:
      uVar1 = (uint)*(ushort *)(iVar2 * 0x80 + iVar3 * 0x30 + glContext + 0x424c);
      break;
    default:
      goto switchD_000b3c80_default;
    }
    *param_5 = uVar1;
    return;
  }
switchD_000b3c80_default:
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x500;
    return;
  }
  return;
}

/* _glGetFinalCombinerInputParameterfvNV_Exec @ 0xb3d80 (188 bytes) */
void _glGetFinalCombinerInputParameterfvNV_Exec(int glContext,int variable,uint pname,float *params,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  uint uVar1;
  
  uVar1 = variable - 0x8523;
  if (6 < uVar1) goto LAB_000b3e24;
  if (pname == 0x8543) {
    uVar1 = (uint)*(ushort *)(uVar1 * 8 + glContext + 0x4628);
  }
  else if (pname < 0x8544) {
    if (pname != 0x8542) {
LAB_000b3e24:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x500;
        return;
      }
      return;
    }
    uVar1 = (uint)*(ushort *)(uVar1 * 8 + glContext + 0x4624);
  }
  else {
    if (pname != 0x8544) goto LAB_000b3e24;
    uVar1 = (uint)*(ushort *)(uVar1 * 8 + glContext + 0x4626);
  }
  *params = GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0;
  return;
}

/* _glGetFinalCombinerInputParameterivNV_Exec @ 0xb3e3c (156 bytes) */
void _glGetFinalCombinerInputParameterivNV_Exec(glContext, variable, pname, params)
  int glContext;
  int variable;
  uint pname;
  uint *params;
{
  uint variableIndexThenValue;
  
  variableIndexThenValue = variable - 0x8523;
  if (6 < variableIndexThenValue) goto LAB_000b3ec0;
  if (pname == 0x8543) {
    variableIndexThenValue = (uint)*(ushort *)(variableIndexThenValue * 8 + glContext + 0x4628);
  }
  else if (pname < 0x8544) {
    if (pname != 0x8542) {
LAB_000b3ec0:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x500;
        return;
      }
      return;
    }
    variableIndexThenValue = (uint)*(ushort *)(variableIndexThenValue * 8 + glContext + 0x4624);
  }
  else {
    if (pname != 0x8544) goto LAB_000b3ec0;
    variableIndexThenValue = (uint)*(ushort *)(variableIndexThenValue * 8 + glContext + 0x4626);
  }
  *params = variableIndexThenValue;
  return;
}

/* _glCombinerParameterfvNV_Comp @ 0xb3ed8 (140 bytes) */
int _glCombinerParameterfvNV_Comp(glContext, pname, params)
  undefined4 glContext;
  int pname;
  int *params;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glCombinerParameterfvNV_ListExec_001104f0,0x14);
  if (listRecord != (int *)0x0) {
    *listRecord = pname;
    if (pname - 0x852aU < 2) {
      listRecord[1] = *params;
      listRecord[2] = params[1];
      listRecord[3] = params[2];
      listRecord[4] = params[3];
    }
    else {
      listRecord[1] = *params;
    }
  }
  return listRecord;
}

/* _glCombinerStageParameterfvNV_Comp @ 0xb3f64 (148 bytes) */
int _glCombinerStageParameterfvNV_Comp(glContext, stage, pname, params)
  undefined4 glContext;
  undefined4 stage;
  int pname;
  undefined4 *params;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glCombinerStageParameterfvNV_ListExec_001104ec,0x18);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = stage;
    listRecord[1] = pname;
    if (pname - 0x852aU < 2) {
      listRecord[2] = *params;
      listRecord[3] = params[1];
      listRecord[4] = params[2];
      listRecord[5] = params[3];
    }
    else {
      listRecord[2] = *params;
    }
  }
  return listRecord;
}

/* _glCombinerParameterfNV_Comp @ 0xb3ff8 (92 bytes) */
undefined4 * _glCombinerParameterfNV_Comp(undefined4 glContext,undefined4 pname,float param)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glCombinerParameterfNV_ListExec_001104e8,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = (float)param;
    *listRecord = pname;
  }
  return listRecord;
}

/* _glCombinerParameterivNV_Comp @ 0xb4054 (140 bytes) */
int _glCombinerParameterivNV_Comp(glContext, pname, params)
  undefined4 glContext;
  int pname;
  int *params;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glCombinerParameterivNV_ListExec_001104e4,0x14);
  if (listRecord != (int *)0x0) {
    *listRecord = pname;
    if (pname - 0x852aU < 2) {
      listRecord[1] = *params;
      listRecord[2] = params[1];
      listRecord[3] = params[2];
      listRecord[4] = params[3];
    }
    else {
      listRecord[1] = *params;
    }
  }
  return listRecord;
}

/* _glCombinerParameteriNV_Comp @ 0xb40e0 (84 bytes) */
int _glCombinerParameteriNV_Comp(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glCombinerParameteriNV_ListExec_001104e0,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = param;
    *listRecord = pname;
  }
  return listRecord;
}

/* _glCombinerInputNV_Comp @ 0xb4134 (116 bytes) */
int _glCombinerInputNV_Comp(glContext, stage, portion, variable, input, mapping, componentUsage)
  undefined4 glContext;
  undefined4 stage;
  undefined4 portion;
  undefined4 variable;
  undefined4 input;
  undefined4 mapping;
  undefined4 componentUsage;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glCombinerInputNV_ListExec_001104dc,0x18);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[5] = componentUsage;
    *listRecord = stage;
    listRecord[1] = portion;
    listRecord[2] = variable;
    listRecord[3] = input;
    listRecord[4] = mapping;
  }
  return listRecord;
}

/* _glCombinerOutputNV_Comp @ 0xb41a8 (148 bytes) */
int _glCombinerOutputNV_Comp(glContext, stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum)
  undefined4 glContext;
  undefined4 stage;
  undefined4 portion;
  undefined4 abOutput;
  undefined4 cdOutput;
  undefined4 sumOutput;
  undefined4 scale;
  undefined4 bias;
  uint abDotProduct;
  uint cdDotProduct;
  uint muxSum;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glCombinerOutputNV_ListExec_001104d8,0x28);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[9] = muxSum & 0xff;
    *listRecord = stage;
    listRecord[1] = portion;
    listRecord[2] = abOutput;
    listRecord[3] = cdOutput;
    listRecord[4] = sumOutput;
    listRecord[5] = scale;
    listRecord[6] = bias;
    listRecord[7] = abDotProduct & 0xff;
    listRecord[8] = cdDotProduct & 0xff;
  }
  return listRecord;
}

