#include "decls.h"

/* _glVertexAttrib4fvARB_CompExec @ 0xaf310 (64 bytes) */
void _glVertexAttrib4fvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  _glVertexAttrib4fvARB_Comp(glContext,index,v);
  _glVertexAttrib4fvARB_Exec(glContext,index,v);
  return;
}

/* _glVertexAttrib4fvARB_ListExec @ 0xaf350 (48 bytes) */
int _glVertexAttrib4fvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glVertexAttrib4fvARB_Exec(glContext,*listRecord,listRecord + 1);
  return 0x14;
}

/* _glVertexAttrib4dvARB_Exec @ 0xaf380 (188 bytes) */
double _glVertexAttrib4dvARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  double *v;
{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (index < 0x10) {
    if (index != 0) {
      iVar1 = glContext + index * 0x10;
      *(float *)(iVar1 + 0x1a0) = (float)*v;
      *(float *)(iVar1 + 0x1a4) = (float)v[1];
      *(float *)(iVar1 + 0x1a8) = (float)v[2];
      *(float *)(iVar1 + 0x1ac) = (float)v[3];
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
              (glContext, index, v, (double)(float)*v, (double)(float)v[1], (double)(float)v[2], (double)(float)v[3]);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib4dvARB_Comp @ 0xaf43c (116 bytes) */
int _glVertexAttrib4dvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined8 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4dvARB_ListExec_00110498,0x24);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined8 *)(listRecord + 1) = *v;
    *(undefined8 *)(listRecord + 3) = v[1];
    *(undefined8 *)(listRecord + 5) = v[2];
    *(undefined8 *)(listRecord + 7) = v[3];
  }
  return listRecord;
}

/* _glVertexAttrib4dvARB_CompExec @ 0xaf4b0 (64 bytes) */
void _glVertexAttrib4dvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib4dvARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib4dvARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib4dvARB_ListExec @ 0xaf4f0 (48 bytes) */
int _glVertexAttrib4dvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib4dvARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 0x24;
}

/* _glVertexAttrib4NbvARB_Exec @ 0xaf520 (484 bytes) */
double _glVertexAttrib4NbvARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  char *v;
{
  double dVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 in_r6;
  undefined4 in_r7;
  code *pcVar5;
  
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  dVar1 = DOUBLE_00108d58;
  if (index < 0x10) {
    if (index == 0) {
      pcVar5 = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        pcVar5 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar5)(glContext,0,v,in_r6,in_r7,*(int *)(glContext + 0x4858),&DAT_0010f52c,0x43300000,
                (double)((float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e60 + FLOAT_00108e64),
                (double)((float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e60 + FLOAT_00108e64),
                (double)((float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e60 + FLOAT_00108e64),
                (double)((float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e60 + FLOAT_00108e64));
    }
    else {
      iVar4 = glContext + index * 0x10;
      *(float *)(iVar4 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
           FLOAT_00108e60 + FLOAT_00108e64;
      *(float *)(iVar4 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - dVar1) * fVar2 +
           fVar3;
      *(float *)(iVar4 + 0x1a8) =
           (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - dVar1) * fVar2 +
           fVar3;
      *(float *)(iVar4 + 0x1ac) =
           (float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) - dVar1) * fVar2 +
           fVar3;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4NbvARB_Comp @ 0xaf704 (116 bytes) */
int _glVertexAttrib4NbvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined1 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4NbvARB_ListExec_0011047c,8);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined1 *)(listRecord + 1) = *v;
    *(undefined1 *)((int)listRecord + 5) = v[1];
    *(undefined1 *)((int)listRecord + 6) = v[2];
    *(undefined1 *)((int)listRecord + 7) = v[3];
  }
  return listRecord;
}

/* _glVertexAttrib4NbvARB_CompExec @ 0xaf778 (64 bytes) */
void _glVertexAttrib4NbvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib4NbvARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib4NbvARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib4NbvARB_ListExec @ 0xaf7b8 (48 bytes) */
int _glVertexAttrib4NbvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib4NbvARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 8;
}

/* _glVertexAttrib4NsvARB_Exec @ 0xaf7e8 (452 bytes) */
double _glVertexAttrib4NsvARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  short *v;
{
  double dVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 in_r6;
  undefined4 in_r7;
  code *pcVar5;
  
  fVar3 = FLOAT_00108e74;
  fVar2 = FLOAT_00108e70;
  dVar1 = DOUBLE_00108d58;
  if (index < 0x10) {
    if (index == 0) {
      pcVar5 = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        pcVar5 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar5)(glContext,0,v,in_r6,in_r7,*(int *)(glContext + 0x4858),&DAT_0010f7f4,
                (double)((float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e70 + FLOAT_00108e74),
                (double)((float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e70 + FLOAT_00108e74),
                (double)((float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e70 + FLOAT_00108e74),
                (double)((float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e70 + FLOAT_00108e74));
    }
    else {
      iVar4 = glContext + index * 0x10;
      *(float *)(iVar4 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
           FLOAT_00108e70 + FLOAT_00108e74;
      *(float *)(iVar4 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - dVar1) * fVar2 +
           fVar3;
      *(float *)(iVar4 + 0x1a8) =
           (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - dVar1) * fVar2 +
           fVar3;
      *(float *)(iVar4 + 0x1ac) =
           (float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) - dVar1) * fVar2 +
           fVar3;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4NsvARB_Comp @ 0xaf9ac (116 bytes) */
int _glVertexAttrib4NsvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined2 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4NsvARB_ListExec_00110478,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined2 *)(listRecord + 1) = *v;
    *(undefined2 *)((int)listRecord + 6) = v[1];
    *(undefined2 *)(listRecord + 2) = v[2];
    *(undefined2 *)((int)listRecord + 10) = v[3];
  }
  return listRecord;
}

/* _glVertexAttrib4NsvARB_CompExec @ 0xafa20 (64 bytes) */
void _glVertexAttrib4NsvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib4NsvARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib4NsvARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib4NsvARB_ListExec @ 0xafa60 (48 bytes) */
int _glVertexAttrib4NsvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib4NsvARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 0xc;
}

/* _glVertexAttrib4NivARB_Exec @ 0xafa90 (452 bytes) */
double _glVertexAttrib4NivARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  uint *v;
{
  double dVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 in_r6;
  undefined4 in_r7;
  code *pcVar5;
  
  fVar3 = FLOAT_00108e6c;
  fVar2 = FLOAT_00108e68;
  dVar1 = DOUBLE_00108d58;
  if (index < 0x10) {
    if (index == 0) {
      pcVar5 = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        pcVar5 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar5)(glContext,0,v,in_r6,in_r7,*(int *)(glContext + 0x4858),v[2] ^ 0x80000000,
                (double)((float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e68 + FLOAT_00108e6c),
                (double)((float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e68 + FLOAT_00108e6c),
                (double)((float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e68 + FLOAT_00108e6c),
                (double)((float)((double)CONCAT44(0x43300000,v[3] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e68 + FLOAT_00108e6c));
    }
    else {
      iVar4 = glContext + index * 0x10;
      *(float *)(iVar4 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58) *
           FLOAT_00108e68 + FLOAT_00108e6c;
      *(float *)(iVar4 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - dVar1) * fVar2 + fVar3;
      *(float *)(iVar4 + 0x1a8) =
           (float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - dVar1) * fVar2 + fVar3;
      *(float *)(iVar4 + 0x1ac) =
           (float)((double)CONCAT44(0x43300000,v[3] ^ 0x80000000) - dVar1) * fVar2 + fVar3;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4NivARB_Comp @ 0xafc54 (116 bytes) */
int _glVertexAttrib4NivARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4NivARB_ListExec_00110474,0x14);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    listRecord[1] = *v;
    listRecord[2] = v[1];
    listRecord[3] = v[2];
    listRecord[4] = v[3];
  }
  return listRecord;
}

/* _glVertexAttrib4NivARB_CompExec @ 0xafcc8 (64 bytes) */
void _glVertexAttrib4NivARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib4NivARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib4NivARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib4NivARB_ListExec @ 0xafd08 (48 bytes) */
int _glVertexAttrib4NivARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib4NivARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 0x14;
}

/* _glVertexAttrib4NubvARB_Exec @ 0xafd38 (432 bytes) */
double _glVertexAttrib4NubvARB_Exec(int glContext,uint index,byte *v,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4)
{
  float fVar1;
  undefined4 in_r6;
  int iVar2;
  code *pcVar3;
  
  fVar1 = FLOAT_00108e78;
  if (index < 0x10) {
    if (index == 0) {
      iVar2 = *(int *)(glContext + 0x4858);
      pcVar3 = *(code **)(glContext + 0x4884);
      if (iVar2 == *(int *)(glContext + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar3)(glContext,0,v,in_r6,iVar2,iVar2,(uint)v[2],v[1] | 0x4b000000,
                (double)((GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0) * FLOAT_00108e78),
                (double)((GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78),
                (double)((GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78),
                (double)((GH_U2F((unsigned int)((v[3] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78));
    }
    else {
      iVar2 = glContext + index * 0x10;
      *(float *)(iVar2 + 0x1a0) = (GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
      *(float *)(iVar2 + 0x1a4) = (GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0) * fVar1;
      *(float *)(iVar2 + 0x1a8) = (GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0) * fVar1;
      *(float *)(iVar2 + 0x1ac) = (GH_U2F((unsigned int)((v[3] | 0x4b000000))) - 8388608.0) * fVar1;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4NubvARB_Comp @ 0xafee8 (116 bytes) */
int _glVertexAttrib4NubvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined1 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4NubvARB_ListExec_00110494,8);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined1 *)(listRecord + 1) = *v;
    *(undefined1 *)((int)listRecord + 5) = v[1];
    *(undefined1 *)((int)listRecord + 6) = v[2];
    *(undefined1 *)((int)listRecord + 7) = v[3];
  }
  return listRecord;
}

/* _glVertexAttrib4NubvARB_CompExec @ 0xaff5c (64 bytes) */
void _glVertexAttrib4NubvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  
  ((int (*)())_glVertexAttrib4NubvARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib4NubvARB_Exec)(glContext,index,v,fparam_1,in_f2,in_f3,in_f4);
  return;
}

/* _glVertexAttrib4NubvARB_ListExec @ 0xaff9c (48 bytes) */
undefined4 _glVertexAttrib4NubvARB_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4)
{
  ((double (*)())_glVertexAttrib4NubvARB_Exec)(glContext,*listRecord,listRecord + 1,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4);
  return 8;
}

/* _glVertexAttrib4NusvARB_Exec @ 0xaffcc (432 bytes) */
double _glVertexAttrib4NusvARB_Exec(int glContext,uint index,ushort *v,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4)
{
  float fVar1;
  undefined4 in_r6;
  int iVar2;
  code *pcVar3;
  
  fVar1 = FLOAT_00108e74;
  if (index < 0x10) {
    if (index == 0) {
      iVar2 = *(int *)(glContext + 0x4858);
      pcVar3 = *(code **)(glContext + 0x4884);
      if (iVar2 == *(int *)(glContext + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar3)(glContext,0,v,in_r6,iVar2,iVar2,(uint)v[2],v[1] | 0x4b000000,
                (double)((GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0) * FLOAT_00108e74),
                (double)((GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74),
                (double)((GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74),
                (double)((GH_U2F((unsigned int)((v[3] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74));
    }
    else {
      iVar2 = glContext + index * 0x10;
      *(float *)(iVar2 + 0x1a0) = (GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
      *(float *)(iVar2 + 0x1a4) = (GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0) * fVar1;
      *(float *)(iVar2 + 0x1a8) = (GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0) * fVar1;
      *(float *)(iVar2 + 0x1ac) = (GH_U2F((unsigned int)((v[3] | 0x4b000000))) - 8388608.0) * fVar1;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4NusvARB_Comp @ 0xb017c (116 bytes) */
int _glVertexAttrib4NusvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined2 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4NusvARB_ListExec_00110470,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined2 *)(listRecord + 1) = *v;
    *(undefined2 *)((int)listRecord + 6) = v[1];
    *(undefined2 *)(listRecord + 2) = v[2];
    *(undefined2 *)((int)listRecord + 10) = v[3];
  }
  return listRecord;
}

/* _glVertexAttrib4NusvARB_CompExec @ 0xb01f0 (64 bytes) */
void _glVertexAttrib4NusvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  
  ((int (*)())_glVertexAttrib4NusvARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib4NusvARB_Exec)(glContext,index,v,fparam_1,in_f2,in_f3,in_f4);
  return;
}

/* _glVertexAttrib4NusvARB_ListExec @ 0xb0230 (48 bytes) */
undefined4 _glVertexAttrib4NusvARB_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4)
{
  ((double (*)())_glVertexAttrib4NusvARB_Exec)(glContext,*listRecord,listRecord + 1,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4);
  return 0xc;
}

/* _glVertexAttrib4NuivARB_Exec @ 0xb0260 (404 bytes) */
double _glVertexAttrib4NuivARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  undefined4 *v;
{
  double dVar1;
  float fVar2;
  int iVar3;
  undefined4 in_r6;
  undefined4 in_r7;
  code *pcVar4;
  
  fVar2 = FLOAT_00108e6c;
  dVar1 = DOUBLE_00108d70;
  if (index < 0x10) {
    if (index == 0) {
      pcVar4 = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        pcVar4 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar4)(glContext,0,v,in_r6,in_r7,*(int *)(glContext + 0x4858),v[1],
                (double)((float)((double)CONCAT44(0x43300000,*v) - DOUBLE_00108d70) *
                        FLOAT_00108e6c),
                (double)((float)((double)CONCAT44(0x43300000,v[1]) - DOUBLE_00108d70) *
                        FLOAT_00108e6c),
                (double)((float)((double)CONCAT44(0x43300000,v[2]) - DOUBLE_00108d70) *
                        FLOAT_00108e6c),
                (double)((float)((double)CONCAT44(0x43300000,v[3]) - DOUBLE_00108d70) *
                        FLOAT_00108e6c));
    }
    else {
      iVar3 = glContext + index * 0x10;
      *(float *)(iVar3 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,*v) - DOUBLE_00108d70) * FLOAT_00108e6c;
      *(float *)(iVar3 + 0x1a4) = (float)((double)CONCAT44(0x43300000,v[1]) - dVar1) * fVar2;
      *(float *)(iVar3 + 0x1a8) = (float)((double)CONCAT44(0x43300000,v[2]) - dVar1) * fVar2;
      *(float *)(iVar3 + 0x1ac) = (float)((double)CONCAT44(0x43300000,v[3]) - dVar1) * fVar2;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4NuivARB_Comp @ 0xb03f4 (116 bytes) */
int _glVertexAttrib4NuivARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4NuivARB_ListExec_0011046c,0x14)
  ;
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    listRecord[1] = *v;
    listRecord[2] = v[1];
    listRecord[3] = v[2];
    listRecord[4] = v[3];
  }
  return listRecord;
}

/* _glVertexAttrib4NuivARB_CompExec @ 0xb0468 (64 bytes) */
void _glVertexAttrib4NuivARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib4NuivARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib4NuivARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib4NuivARB_ListExec @ 0xb04a8 (48 bytes) */
int _glVertexAttrib4NuivARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib4NuivARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 0x14;
}

/* _glEnableVertexAttribArrayARB_Exec @ 0xb04d8 (236 bytes) */
void _glEnableVertexAttribArrayARB_Exec(glContext, index)
  int glContext;
  uint index;
{
  undefined4 glErrorCode;
  int clientState;
  uint uVar3;
  longlong lVar4;
  
  clientState = *(int *)(glContext + 0x4a60);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (index < 0x10) {
      lVar4 = ___ashldi3(1,0,index);
      uVar3 = (uint)((ulonglong)lVar4 >> 0x20);
      *(uint *)(clientState + 0x330) = *(uint *)(clientState + 0x330) | uVar3;
      *(uint *)(clientState + 0x334) = *(uint *)(clientState + 0x334) | (uint)lVar4;
      *(undefined4 *)(glContext + 0x488c) = 0;
      *(undefined4 *)(glContext + 0x4890) = 0;
      *(uint *)(clientState + 0x350) = *(uint *)(clientState + 0x350) | uVar3;
      *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | (uint)lVar4;
      if (((*(int *)(clientState + 0x344) == 0) && (*(int *)(clientState + 0x358) == 0)) &&
         (*(int *)(glContext + 0x49a0) == 0)) {
        return;
      }
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
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

/* _glDisableVertexAttribArrayARB_Exec @ 0xb05c4 (244 bytes) */
void _glDisableVertexAttribArrayARB_Exec(glContext, index)
  int glContext;
  uint index;
{
  undefined4 glErrorCode;
  int clientState;
  uint uVar3;
  longlong lVar4;
  
  clientState = *(int *)(glContext + 0x4a60);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (index < 0x10) {
      lVar4 = ___ashldi3(1,0,index);
      uVar3 = (uint)((ulonglong)lVar4 >> 0x20);
      *(uint *)(clientState + 0x330) = *(uint *)(clientState + 0x330) & ~uVar3;
      *(uint *)(clientState + 0x334) = *(uint *)(clientState + 0x334) & ~(uint)lVar4;
      *(undefined4 *)(glContext + 0x488c) = 0;
      *(undefined4 *)(glContext + 0x4890) = 0;
      *(uint *)(clientState + 0x350) = *(uint *)(clientState + 0x350) | uVar3;
      *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | (uint)lVar4;
      if (((*(int *)(clientState + 0x344) == 0) && (*(int *)(clientState + 0x358) == 0)) &&
         (*(int *)(glContext + 0x49a0) == 0)) {
        return;
      }
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
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

/* _glEnableVertexAttribARB_Exec @ 0xb06b8 (264 bytes) */
void _glEnableVertexAttribARB_Exec(glContext, param_2, param_3)
  int glContext;
  uint param_2;
  int param_3;
{
  undefined4 glErrorCode;
  int mapData;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (param_2 < 0x10) {
      if (param_3 == 0x8a00) {
        mapData = _gleGetMapData(glContext);
        *(uint *)(glContext + 0x74d8) = *(uint *)(glContext + 0x74d8) | 1 << (param_2 & 0x3f);
        *(char *)(param_2 + glContext + 0x7524) =
             (char)((unsigned char *)0x9da8)[param_2 + mapData]<< 2;
        return;
      }
      if (param_3 == 0x8a01) {
        mapData = _gleGetMapData(glContext);
        *(uint *)(glContext + 0x74dc) = *(uint *)(glContext + 0x74dc) | 1 << (param_2 & 0x3f);
        *(char *)(param_2 + glContext + 0x7564) = *(char *)(param_2 + mapData + 0x9db8) << 2;
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
      glErrorCode = 0x501;
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

/* _glEnableVertexAttribARB_Comp @ 0xb07c0 (84 bytes) */
int _glEnableVertexAttribARB_Comp(glContext, param_2, param_3)
  undefined4 glContext;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glEnableVertexAttribARB_ListExec_00110468,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = param_3;
    *listRecord = param_2;
  }
  return listRecord;
}

/* _glEnableVertexAttribARB_CompExec @ 0xb0814 (64 bytes) */
void _glEnableVertexAttribARB_CompExec(glContext, forwardedArg2, forwardedArg3)
  undefined4 glContext;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
{
  ((int (*)())_glEnableVertexAttribARB_Comp)(glContext,forwardedArg2,forwardedArg3);
  ((void (*)())_glEnableVertexAttribARB_Exec)(glContext,forwardedArg2,forwardedArg3);
  return;
}

/* _glEnableVertexAttribARB_ListExec @ 0xb0854 (44 bytes) */
int _glEnableVertexAttribARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glEnableVertexAttribARB_Exec)(glContext,*listRecord,listRecord[1]);
  return 8;
}

/* _glDisableVertexAttribARB_Exec @ 0xb0880 (192 bytes) */
void _glDisableVertexAttribARB_Exec(glContext, param_2, param_3)
  int glContext;
  uint param_2;
  int param_3;
{
  undefined4 glErrorCode;
  uint uVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (param_2 < 0x10) {
      if (param_3 == 0x8a00) {
        uVar2 = *(uint *)(glContext + 0x74d8);
        *(undefined1 *)(param_2 + glContext + 0x7524) = 0;
        *(uint *)(glContext + 0x74d8) =
             uVar2 & (-2 << (param_2 & 0x1f) | 0xfffffffeU >> 0x20 - (param_2 & 0x1f));
        return;
      }
      if (param_3 == 0x8a01) {
        uVar2 = *(uint *)(glContext + 0x74dc);
        *(undefined1 *)(param_2 + glContext + 0x7564) = 0;
        *(uint *)(glContext + 0x74dc) =
             uVar2 & (-2 << (param_2 & 0x1f) | 0xfffffffeU >> 0x20 - (param_2 & 0x1f));
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
      glErrorCode = 0x501;
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

/* _glDisableVertexAttribARB_Comp @ 0xb0940 (84 bytes) */
int _glDisableVertexAttribARB_Comp(glContext, param_2, param_3)
  undefined4 glContext;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glDisableVertexAttribARB_ListExec_00110464,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = param_3;
    *listRecord = param_2;
  }
  return listRecord;
}

/* _glDisableVertexAttribARB_CompExec @ 0xb0994 (64 bytes) */
void _glDisableVertexAttribARB_CompExec(glContext, forwardedArg2, forwardedArg3)
  undefined4 glContext;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
{
  ((int (*)())_glDisableVertexAttribARB_Comp)(glContext,forwardedArg2,forwardedArg3);
  ((void (*)())_glDisableVertexAttribARB_Exec)(glContext,forwardedArg2,forwardedArg3);
  return;
}

/* _glDisableVertexAttribARB_ListExec @ 0xb09d4 (44 bytes) */
int _glDisableVertexAttribARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glDisableVertexAttribARB_Exec)(glContext,*listRecord,listRecord[1]);
  return 8;
}

/* _glIsVertexAttribEnabledARB_Exec @ 0xb0a00 (160 bytes) */
int _glIsVertexAttribEnabledARB_Exec(glContext, param_2, param_3)
  int glContext;
  uint param_2;
  int param_3;
{
  undefined4 glErrorCode;
  uint uVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (param_2 < 0x10) {
      if (param_3 == 0x8a00) {
        uVar2 = *(uint *)(glContext + 0x74d8);
      }
      else {
        if (param_3 != 0x8a01) {
          if (*(int *)(glContext + 0x7574) != 0) {
            return false;
          }
          glErrorCode = 0x500;
          goto LAB_000b0a94;
        }
        uVar2 = *(uint *)(glContext + 0x74dc);
      }
      return (uVar2 & 1 << (param_2 & 0x3f)) != 0;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return false;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return false;
    }
    glErrorCode = 0x502;
  }
LAB_000b0a94:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return false;
}

/* _glGetVertexAttribdvARB_Exec @ 0xb0aa0 (1104 bytes) */
void _glGetVertexAttribdvARB_Exec(glContext, index, pname, params)
  int glContext;
  uint index;
  uint pname;
  double *params;
{
  unsigned char cVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  uint uVar4;
  float *srcCursor;
  uint *srcCursor2;
  int iVar7;
  int remaining;
  double *pdVar8;
  int iVar9;
  int remaining2;
  int clientState;
  int mapData;
  double dVar10;
  double dVar11;
  longlong lVar12;
  uint uStack_1c;
  
  if (0xf < index) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_000b0ed8;
  }
  if (pname == 0x8a02) {
    mapData = _gleGetMapData(glContext);
    cVar1 = ((unsigned char *)0x9da8)[index + mapData];
LAB_000b0dcc:
    uStack_1c = (uint)(byte)cVar1;
  }
  else {
    if (pname < 0x8a03) {
      dVar11 = DOUBLE_00108d58;
      if (pname == 0x8624) {
        dVar10 = (double)CONCAT44(0x43300000,
                                  *(uint *)(index * 0x18 + *(int *)(glContext + 0x4a60) + 0x1b4) ^
                                  0x80000000);
        goto LAB_000b0de4;
      }
      if (pname < 0x8625) {
        if (pname == 0x8622) {
          clientState = *(int *)(glContext + 0x4a60);
          lVar12 = ___ashldi3(1,0,index);
          uVar3 = 0x3ff00000;
          if ((*(uint *)(clientState + 0x330) & (uint)((ulonglong)lVar12 >> 0x20)) == 0 &&
              (*(uint *)(clientState + 0x334) & (uint)lVar12) == 0) {
            uVar3 = 0;
          }
          *(undefined4 *)params = uVar3;
          *(undefined4 *)((int)params + 4) = 0;
          return;
        }
        if (pname == 0x8623) {
          uStack_1c = (uint)*(short *)(index * 0x18 + *(int *)(glContext + 0x4a60) + 0x1ba);
LAB_000b0cc8:
          uStack_1c = uStack_1c ^ 0x80000000;
          dVar10 = (double)CONCAT44(0x43300000,uStack_1c);
          goto LAB_000b0de4;
        }
      }
      else {
        if (pname == 0x8626) {
          if (index != 0) {
            remaining2 = 4;
            srcCursor = (float *)(glContext + index * 0x10 + 0x1a0);
            do {
              fVar2 = *srcCursor;
              srcCursor = srcCursor + 1;
              *params = (double)fVar2;
              params = params + 1;
              remaining2 = remaining2 + -1;
            } while (remaining2 != 0);
            return;
          }
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x502;
          goto LAB_000b0ed8;
        }
        if (pname < 0x8626) {
          uStack_1c = *(ushort *)(index * 0x18 + *(int *)(glContext + 0x4a60) + 0x1b8) & 0xffff7fff;
          goto LAB_000b0cc8;
        }
        if (pname == 0x886a) {
          uVar3 = 0x3ff00000;
          if (-1 < *(short *)(index * 0x18 + *(int *)(glContext + 0x4a60) + 0x1b8)) {
            uVar3 = 0;
          }
          *(undefined4 *)params = uVar3;
          *(undefined4 *)((int)params + 4) = 0;
          return;
        }
      }
LAB_000b0ec8:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
LAB_000b0ed8:
      *(undefined4 *)(glContext + 0x7574) = glErrorCode;
      return;
    }
    if (pname == 0x8a06) {
      mapData = _gleGetMapData(glContext);
      cVar1 = *(code *)(index + mapData + 0x9db8);
      goto LAB_000b0dcc;
    }
    if (0x8a06 < pname) {
      if (pname == 0x8a08) {
        mapData = _gleGetMapData(glContext);
        dVar10 = DOUBLE_00108d58;
        srcCursor2 = (uint *)(mapData + index * 0x660 + 0x37a8);
        pdVar8 = params + 1;
        do {
          uVar4 = *srcCursor2;
          srcCursor2 = srcCursor2 + 1;
          *params = (double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - dVar10;
          params = params + 1;
        } while (params <= pdVar8);
        return;
      }
      if (pname < 0x8a08) {
        iVar9 = _gleGetMapData(glContext);
        iVar7 = index * 0x660 + iVar9;
        srcCursor = (float *)(iVar7 + 0x37c8);
        for (iVar9 = *(int *)(iVar7 + 0x37a8) * *(int *)(iVar7 + 0x37ac) *
                     (uint)*(byte *)(index + iVar9 + 0x9db8); iVar9 != 0; iVar9 = iVar9 + -1) {
          fVar2 = *srcCursor;
          srcCursor = srcCursor + 1;
          *params = (double)fVar2;
          params = params + 1;
        }
        return;
      }
      if (pname == 0x8a09) {
        mapData = _gleGetMapData(glContext);
        remaining = 4;
        srcCursor = (float *)(mapData + index * 0x660 + 0x37b0);
        do {
          fVar2 = *srcCursor;
          srcCursor = srcCursor + 1;
          *params = (double)fVar2;
          params = params + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
        return;
      }
      goto LAB_000b0ec8;
    }
    if (pname != 0x8a04) {
      if (pname < 0x8a05) {
        iVar9 = _gleGetMapData(glContext);
        iVar7 = index * 0xb0 + iVar9;
        srcCursor = (float *)(iVar7 + 0x2cb8);
        for (iVar9 = *(int *)(iVar7 + 0x2ca8) *
                     (uint)(byte)((unsigned char *)0x9da8)[index + iVar9]; iVar9 != 0;
            iVar9 = iVar9 + -1) {
          fVar2 = *srcCursor;
          srcCursor = srcCursor + 1;
          *params = (double)fVar2;
          params = params + 1;
        }
        return;
      }
      mapData = _gleGetMapData(glContext);
      pdVar8 = params + 1;
      srcCursor = (float *)(mapData + index * 0xb0 + 0x2cac);
      do {
        fVar2 = *srcCursor;
        srcCursor = srcCursor + 1;
        *params = (double)fVar2;
        params = params + 1;
      } while (params <= pdVar8);
      return;
    }
    mapData = _gleGetMapData(glContext);
    uStack_1c = *(uint *)(index * 0xb0 + mapData + 0x2ca8);
  }
  dVar10 = (double)CONCAT44(0x43300000,uStack_1c);
  dVar11 = DOUBLE_00108d70;
LAB_000b0de4:
  *params = dVar10 - dVar11;
  return;
}

/* _glGetVertexAttribfvARB_Exec @ 0xb0ef0 (1116 bytes) */
void _glGetVertexAttribfvARB_Exec(glContext, index, pname, params)
  int glContext;
  uint index;
  uint pname;
  float *params;
{
  unsigned char cVar1;
  undefined4 glErrorCode;
  float fVar3;
  uint loopIndex;
  int iVar5;
  int remaining;
  int iVar6;
  int clientState;
  int mapData;
  int iVar7;
  int remaining3;
  int remaining2;
  double dVar8;
  double dVar9;
  longlong lVar10;
  uint uStack_2c;
  
  if (0xf < index) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_000b1334;
  }
  if (pname == 0x8a02) {
    mapData = _gleGetMapData(glContext);
    cVar1 = ((unsigned char *)0x9da8)[index + mapData];
LAB_000b1220:
    *params = GH_U2F((unsigned int)(((byte)cVar1 | 0x4b000000))) - 8388608.0;
  }
  else {
    if (pname < 0x8a03) {
      dVar9 = DOUBLE_00108d58;
      if (pname != 0x8624) {
        if (pname < 0x8625) {
          if (pname == 0x8622) {
            clientState = *(int *)(glContext + 0x4a60);
            lVar10 = ___ashldi3(1,0,index);
            fVar3 = 1.0;
            if ((*(uint *)(clientState + 0x330) & (uint)((ulonglong)lVar10 >> 0x20)) == 0 &&
                (*(uint *)(clientState + 0x334) & (uint)lVar10) == 0) {
              fVar3 = 0.0;
            }
            *params = fVar3;
            return;
          }
          if (pname == 0x8623) {
            uStack_2c = (uint)*(short *)(index * 0x18 + *(int *)(glContext + 0x4a60) + 0x1ba);
LAB_000b110c:
            uStack_2c = uStack_2c ^ 0x80000000;
            dVar8 = (double)CONCAT44(0x43300000,uStack_2c);
            goto LAB_000b11cc;
          }
        }
        else {
          if (pname == 0x8626) {
            if (index != 0) {
              remaining2 = 4;
              iVar6 = 0;
              do {
                *(undefined4 *)(iVar6 + (int)params) =
                     *(undefined4 *)(iVar6 + glContext + index * 0x10 + 0x1a0);
                iVar6 = iVar6 + 4;
                remaining2 = remaining2 + -1;
              } while (remaining2 != 0);
              return;
            }
            if (*(int *)(glContext + 0x7574) != 0) {
              return;
            }
            glErrorCode = 0x502;
            goto LAB_000b1334;
          }
          if (pname < 0x8626) {
            uStack_2c = *(ushort *)(index * 0x18 + *(int *)(glContext + 0x4a60) + 0x1b8) &
                        0xffff7fff;
            goto LAB_000b110c;
          }
          if (pname == 0x886a) {
            fVar3 = 1.0;
            if (-1 < *(short *)(index * 0x18 + *(int *)(glContext + 0x4a60) + 0x1b8)) {
              fVar3 = 0.0;
            }
            *params = fVar3;
            return;
          }
        }
LAB_000b1324:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
LAB_000b1334:
        *(undefined4 *)(glContext + 0x7574) = glErrorCode;
        return;
      }
      dVar8 = (double)CONCAT44(0x43300000,
                               *(uint *)(index * 0x18 + *(int *)(glContext + 0x4a60) + 0x1b4) ^
                               0x80000000);
    }
    else {
      if (pname == 0x8a06) {
        mapData = _gleGetMapData(glContext);
        cVar1 = *(code *)(index + mapData + 0x9db8);
        goto LAB_000b1220;
      }
      if (0x8a06 < pname) {
        if (pname == 0x8a08) {
          mapData = _gleGetMapData(glContext);
          dVar8 = DOUBLE_00108d58;
          loopIndex = 0;
          iVar7 = 0;
          do {
            loopIndex = loopIndex + 1;
            *(float *)(iVar7 + (int)params) =
                 (float)((double)CONCAT44(0x43300000,
                                          *(uint *)(iVar7 + mapData + index * 0x660 + 0x37a8) ^
                                          0x80000000) - dVar8);
            iVar7 = iVar7 + 4;
          } while (loopIndex < 2);
          return;
        }
        if (pname < 0x8a08) {
          mapData = _gleGetMapData(glContext);
          iVar5 = index * 0x660 + mapData;
          remaining3 = *(int *)(iVar5 + 0x37a8) * *(int *)(iVar5 + 0x37ac) *
                  (uint)*(byte *)(index + mapData + 0x9db8);
          iVar6 = 0;
          for (; remaining3 != 0; remaining3 = remaining3 + -1) {
            params[iVar6] = *(float *)(iVar5 + 0x37c8 + iVar6 * 4);
            iVar6 = iVar6 + 1;
          }
          return;
        }
        if (pname == 0x8a09) {
          mapData = _gleGetMapData(glContext);
          remaining = 4;
          iVar7 = 0;
          do {
            *(undefined4 *)(iVar7 + (int)params) =
                 *(undefined4 *)(iVar7 + mapData + index * 0x660 + 0x37b0);
            iVar7 = iVar7 + 4;
            remaining = remaining + -1;
          } while (remaining != 0);
          return;
        }
        goto LAB_000b1324;
      }
      if (pname != 0x8a04) {
        if (pname < 0x8a05) {
          mapData = _gleGetMapData(glContext);
          iVar5 = index * 0xb0 + mapData;
          remaining3 = *(int *)(iVar5 + 0x2ca8) *
                  (uint)(byte)((unsigned char *)0x9da8)[index + mapData];
          iVar6 = 0;
          for (; remaining3 != 0; remaining3 = remaining3 + -1) {
            params[iVar6] = *(float *)(iVar5 + 0x2cb8 + iVar6 * 4);
            iVar6 = iVar6 + 1;
          }
          return;
        }
        mapData = _gleGetMapData(glContext);
        loopIndex = 0;
        iVar7 = 0;
        do {
          loopIndex = loopIndex + 1;
          *(undefined4 *)(iVar7 + (int)params) =
               *(undefined4 *)(iVar7 + mapData + index * 0xb0 + 0x2cac);
          iVar7 = iVar7 + 4;
        } while (loopIndex < 2);
        return;
      }
      mapData = _gleGetMapData(glContext);
      dVar8 = (double)CONCAT44(0x43300000,*(undefined4 *)(index * 0xb0 + mapData + 0x2ca8));
      dVar9 = DOUBLE_00108d70;
    }
LAB_000b11cc:
    *params = (float)(dVar8 - dVar9);
  }
  return;
}

/* _glGetVertexAttribivARB_Exec @ 0xb134c (1040 bytes) */
void _glGetVertexAttribivARB_Exec(glContext, index, pname, params)
  int glContext;
  uint index;
  uint pname;
  uint *params;
{
  undefined4 glErrorCode;
  uint uVar2;
  uint loopIndex;
  int iVar3;
  int remaining;
  int iVar4;
  int clientState;
  int mapData;
  int iVar5;
  int remaining3;
  int remaining2;
  longlong lVar6;
  
  if (index < 0x10) {
    if (pname == 0x8a02) {
      mapData = _gleGetMapData(glContext);
      uVar2 = (uint)(byte)((unsigned char *)0x9da8)[index + mapData];
    }
    else {
      if (pname < 0x8a03) {
        if (pname == 0x8625) {
          uVar2 = *(ushort *)(index * 0x18 + *(int *)(glContext + 0x4a60) + 0x1b8) & 0xffff7fff;
          goto LAB_000b1560;
        }
        if (pname < 0x8626) {
          if (pname == 0x8623) {
            uVar2 = (uint)*(short *)(index * 0x18 + *(int *)(glContext + 0x4a60) + 0x1ba);
LAB_000b1560:
            *params = uVar2;
            return;
          }
          if (0x8623 < pname) {
            uVar2 = *(uint *)(index * 0x18 + *(int *)(glContext + 0x4a60) + 0x1b4);
            goto LAB_000b1560;
          }
          if (pname == 0x8622) {
            clientState = *(int *)(glContext + 0x4a60);
            lVar6 = ___ashldi3(1,0,index);
            uVar2 = 0;
            if ((*(uint *)(clientState + 0x330) & (uint)((ulonglong)lVar6 >> 0x20)) != 0 ||
                (*(uint *)(clientState + 0x334) & (uint)lVar6) != 0) {
              uVar2 = 1;
            }
            goto LAB_000b165c;
          }
        }
        else {
          if (pname == 0x886a) {
            uVar2 = (uint)(int)*(short *)(index * 0x18 + *(int *)(glContext + 0x4a60) + 0x1b8) >>
                    0x1f;
            goto LAB_000b1560;
          }
          if (pname < 0x886b) {
            if (pname == 0x8626) {
              if (index != 0) {
                remaining2 = 4;
                iVar4 = 0;
                do {
                  *(int *)(iVar4 + (int)params) =
                       (int)*(float *)(iVar4 + glContext + index * 0x10 + 0x1a0);
                  iVar4 = iVar4 + 4;
                  remaining2 = remaining2 + -1;
                } while (remaining2 != 0);
                return;
              }
              if (*(int *)(glContext + 0x7574) != 0) {
                return;
              }
              glErrorCode = 0x502;
              goto LAB_000b1744;
            }
          }
          else if (pname == 0x889f) {
            uVar2 = 0;
            iVar4 = *(int *)(index * 4 + *(int *)(glContext + 0x4a60) + 0x3a0);
            if (iVar4 != 0) {
              uVar2 = *(uint *)(iVar4 + 4);
            }
            goto LAB_000b165c;
          }
        }
LAB_000b1734:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_000b1744;
      }
      if (pname == 0x8a06) {
        mapData = _gleGetMapData(glContext);
        uVar2 = (uint)*(byte *)(index + mapData + 0x9db8);
      }
      else {
        if (0x8a06 < pname) {
          if (pname == 0x8a08) {
            mapData = _gleGetMapData(glContext);
            loopIndex = 0;
            iVar5 = 0;
            do {
              loopIndex = loopIndex + 1;
              *(undefined4 *)(iVar5 + (int)params) =
                   *(undefined4 *)(iVar5 + mapData + index * 0x660 + 0x37a8);
              iVar5 = iVar5 + 4;
            } while (loopIndex < 2);
            return;
          }
          if (pname < 0x8a08) {
            mapData = _gleGetMapData(glContext);
            iVar3 = index * 0x660 + mapData;
            remaining3 = *(int *)(iVar3 + 0x37a8) * *(int *)(iVar3 + 0x37ac) *
                    (uint)*(byte *)(index + mapData + 0x9db8);
            iVar4 = 0;
            for (; remaining3 != 0; remaining3 = remaining3 + -1) {
              params[iVar4] = (int)*(float *)(iVar4 * 4 + iVar3 + 0x37c8);
              iVar4 = iVar4 + 1;
            }
            return;
          }
          if (pname == 0x8a09) {
            mapData = _gleGetMapData(glContext);
            remaining = 4;
            iVar5 = 0;
            do {
              *(int *)(iVar5 + (int)params) =
                   (int)*(float *)(iVar5 + mapData + index * 0x660 + 0x37b0);
              iVar5 = iVar5 + 4;
              remaining = remaining + -1;
            } while (remaining != 0);
            return;
          }
          goto LAB_000b1734;
        }
        if (pname != 0x8a04) {
          if (pname < 0x8a05) {
            mapData = _gleGetMapData(glContext);
            iVar3 = index * 0xb0 + mapData;
            remaining3 = *(int *)(iVar3 + 0x2ca8) *
                    (uint)(byte)((unsigned char *)0x9da8)[index + mapData];
            iVar4 = 0;
            for (; remaining3 != 0; remaining3 = remaining3 + -1) {
              params[iVar4] = (int)*(float *)(iVar4 * 4 + iVar3 + 0x2cb8);
              iVar4 = iVar4 + 1;
            }
            return;
          }
          mapData = _gleGetMapData(glContext);
          loopIndex = 0;
          iVar5 = 0;
          do {
            loopIndex = loopIndex + 1;
            *(int *)(iVar5 + (int)params) =
                 (int)*(float *)(iVar5 + mapData + index * 0xb0 + 0x2cac);
            iVar5 = iVar5 + 4;
          } while (loopIndex < 2);
          return;
        }
        mapData = _gleGetMapData(glContext);
        uVar2 = *(uint *)(index * 0xb0 + mapData + 0x2ca8);
      }
    }
LAB_000b165c:
    *params = uVar2;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
LAB_000b1744:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glGetVertexAttribPointervARB_Exec @ 0xb175c (92 bytes) */
void _glGetVertexAttribPointervARB_Exec(glContext, index, pname, pointer)
  int glContext;
  uint index;
  int pname;
  undefined4 *pointer;
{
  undefined4 glErrorCode;
  
  if (index < 0x10) {
    if (pname == 0x8645) {
      *pointer = *(undefined4 *)(index * 0x18 + *(int *)(glContext + 0x4a60) + 0x1b0);
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
    glErrorCode = 0x501;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glViewport_ListExec @ 0xb17b8 (56 bytes) */
undefined4 _glViewport_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glViewport_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3],forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                   forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 0x10;
}

/* _glViewport_Comp @ 0xb17f0 (100 bytes) */
int _glViewport_Comp(glContext, x, y, width, height)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 height;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glViewport_ListExec_001104c8,0x10);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[3] = height;
    *listRecord = x;
    listRecord[1] = y;
    listRecord[2] = width;
  }
  return listRecord;
}

/* _glViewport_CompExec @ 0xb1854 (80 bytes) */
void _glViewport_CompExec(glContext, x, y, width, height)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 height;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glViewport_Comp)(glContext,x,y,width,height);
  ((void (*)())_glViewport_Exec)(glContext,x,y,width,height,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,
                   in_f7,in_f8);
  return;
}

/* _glWindowPos2_ListExec @ 0xb18a4 (68 bytes) */
int _glWindowPos2_ListExec(glContext, listRecord)
  undefined4 glContext;
  float *listRecord;
{
  ((double (*)())_gleSetWindowPos)(glContext,(double)*listRecord,(double)listRecord[1],(double)FLOAT_00108e50);
  return 8;
}

/* _glWindowPos3_ListExec @ 0xb18e8 (48 bytes) */
int _glWindowPos3_ListExec(glContext, listRecord)
  undefined4 glContext;
  float *listRecord;
{
  ((double (*)())_gleSetWindowPos)(glContext,(double)*listRecord,(double)listRecord[1],(double)listRecord[2]);
  return 0xc;
}

/* _glWindowPos2d_Exec @ 0xb1918 (72 bytes) */
void _glWindowPos2d_Exec(int glContext,double x,double y)
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,(double)(float)x,(double)(float)y,(double)FLOAT_00108e50)
    ;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glWindowPos2d_Comp @ 0xb1960 (108 bytes) */
float * _glWindowPos2d_Comp(undefined4 glContext,double x,double y)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glWindowPos2_ListExec_001104d0,8);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)x;
    listRecord[1] = (float)y;
  }
  return listRecord;
}

/* _glWindowPos2d_CompExec @ 0xb19cc (80 bytes) */
void _glWindowPos2d_CompExec(undefined4 glContext,double x,double y)
{
  ((float * (*)())_glWindowPos2d_Comp)(glContext,x,y);
  ((void (*)())_glWindowPos2d_Exec)(glContext,x,y);
  return;
}

/* _glWindowPos2dv_Exec @ 0xb1a1c (80 bytes) */
void _glWindowPos2dv_Exec(glContext, v)
  int glContext;
  double *v;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,(double)(float)*v,(double)(float)v[1],
                     (double)FLOAT_00108e50);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glWindowPos2dv_Comp @ 0xb1a6c (96 bytes) */
int _glWindowPos2dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glWindowPos2_ListExec_001104d0,8);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*v;
    listRecord[1] = (float)v[1];
  }
  return listRecord;
}

/* _glWindowPos2dv_CompExec @ 0xb1acc (56 bytes) */
void _glWindowPos2dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glWindowPos2dv_Comp)(glContext,v);
  ((void (*)())_glWindowPos2dv_Exec)(glContext,v);
  return;
}

/* _glWindowPos3d_Exec @ 0xb1b04 (52 bytes) */
void _glWindowPos3d_Exec(int glContext,double x,double y,double z)
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,(double)(float)x,(double)(float)y,(double)(float)z
                    );
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glWindowPos3d_Comp @ 0xb1b38 (128 bytes) */
float * _glWindowPos3d_Comp(undefined4 glContext,double x,double y,double z)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glWindowPos3_ListExec_001104cc,0xc);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)x;
    listRecord[1] = (float)y;
    listRecord[2] = (float)z;
  }
  return listRecord;
}

/* _glWindowPos3d_CompExec @ 0xb1bb8 (96 bytes) */
void _glWindowPos3d_CompExec(undefined4 glContext,double x,double y,double z)
{
  ((float * (*)())_glWindowPos3d_Comp)(glContext,x,y,z);
  ((void (*)())_glWindowPos3d_Exec)(glContext,x,y,z);
  return;
}

/* _glWindowPos3dv_Exec @ 0xb1c18 (64 bytes) */
void _glWindowPos3dv_Exec(glContext, v)
  int glContext;
  double *v;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(glContext,(double)(float)*v,(double)(float)v[1],
                     (double)(float)v[2]);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

