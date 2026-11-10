#include "decls.h"

/* _glVertexAttrib4fvARB_CompExec @ 0xaf310 (64 bytes) */
void _glVertexAttrib4fvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  _glVertexAttrib4fvARB_Comp(param_1,param_2,param_3);
  _glVertexAttrib4fvARB_Exec(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib4fvARB_ListExec @ 0xaf350 (48 bytes) */
int _glVertexAttrib4fvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glVertexAttrib4fvARB_Exec(param_1,*param_2,param_2 + 1);
  return 0x14;
}

/* _glVertexAttrib4dvARB_Exec @ 0xaf380 (188 bytes) */
double _glVertexAttrib4dvARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  double *param_3;
{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 < 0x10) {
    if (param_2 != 0) {
      iVar1 = param_1 + param_2 * 0x10;
      *(float *)(iVar1 + 0x1a0) = (float)*param_3;
      *(float *)(iVar1 + 0x1a4) = (float)param_3[1];
      *(float *)(iVar1 + 0x1a8) = (float)param_3[2];
      *(float *)(iVar1 + 0x1ac) = (float)param_3[3];
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
              (param_1, param_2, param_3, (double)(float)*param_3, (double)(float)param_3[1], (double)(float)param_3[2], (double)(float)param_3[3]);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib4dvARB_Comp @ 0xaf43c (116 bytes) */
int _glVertexAttrib4dvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined8 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4dvARB_ListExec_00110498,0x24);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined8 *)(puVar1 + 1) = *param_3;
    *(undefined8 *)(puVar1 + 3) = param_3[1];
    *(undefined8 *)(puVar1 + 5) = param_3[2];
    *(undefined8 *)(puVar1 + 7) = param_3[3];
  }
  return puVar1;
}

/* _glVertexAttrib4dvARB_CompExec @ 0xaf4b0 (64 bytes) */
void _glVertexAttrib4dvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib4dvARB_Comp)(param_1,param_2,param_3);
  ((double (*)())_glVertexAttrib4dvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib4dvARB_ListExec @ 0xaf4f0 (48 bytes) */
int _glVertexAttrib4dvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((double (*)())_glVertexAttrib4dvARB_Exec)(param_1,*param_2,param_2 + 1);
  return 0x24;
}

/* _glVertexAttrib4NbvARB_Exec @ 0xaf520 (484 bytes) */
double _glVertexAttrib4NbvARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  char *param_3;
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
  if (param_2 < 0x10) {
    if (param_2 == 0) {
      pcVar5 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar5 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar5)(param_1,0,param_3,in_r6,in_r7,*(int *)(param_1 + 0x4858),&DAT_0010f52c,0x43300000,
                (double)((float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e60 + FLOAT_00108e64),
                (double)((float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e60 + FLOAT_00108e64),
                (double)((float)((double)CONCAT44(0x43300000,(int)param_3[2] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e60 + FLOAT_00108e64),
                (double)((float)((double)CONCAT44(0x43300000,(int)param_3[3] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e60 + FLOAT_00108e64));
    }
    else {
      iVar4 = param_1 + param_2 * 0x10;
      *(float *)(iVar4 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58) *
           FLOAT_00108e60 + FLOAT_00108e64;
      *(float *)(iVar4 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - dVar1) * fVar2 +
           fVar3;
      *(float *)(iVar4 + 0x1a8) =
           (float)((double)CONCAT44(0x43300000,(int)param_3[2] ^ 0x80000000) - dVar1) * fVar2 +
           fVar3;
      *(float *)(iVar4 + 0x1ac) =
           (float)((double)CONCAT44(0x43300000,(int)param_3[3] ^ 0x80000000) - dVar1) * fVar2 +
           fVar3;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4NbvARB_Comp @ 0xaf704 (116 bytes) */
int _glVertexAttrib4NbvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined1 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4NbvARB_ListExec_0011047c,8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined1 *)(puVar1 + 1) = *param_3;
    *(undefined1 *)((int)puVar1 + 5) = param_3[1];
    *(undefined1 *)((int)puVar1 + 6) = param_3[2];
    *(undefined1 *)((int)puVar1 + 7) = param_3[3];
  }
  return puVar1;
}

/* _glVertexAttrib4NbvARB_CompExec @ 0xaf778 (64 bytes) */
void _glVertexAttrib4NbvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib4NbvARB_Comp)(param_1,param_2,param_3);
  ((double (*)())_glVertexAttrib4NbvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib4NbvARB_ListExec @ 0xaf7b8 (48 bytes) */
int _glVertexAttrib4NbvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((double (*)())_glVertexAttrib4NbvARB_Exec)(param_1,*param_2,param_2 + 1);
  return 8;
}

/* _glVertexAttrib4NsvARB_Exec @ 0xaf7e8 (452 bytes) */
double _glVertexAttrib4NsvARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  short *param_3;
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
  if (param_2 < 0x10) {
    if (param_2 == 0) {
      pcVar5 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar5 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar5)(param_1,0,param_3,in_r6,in_r7,*(int *)(param_1 + 0x4858),&DAT_0010f7f4,
                (double)((float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e70 + FLOAT_00108e74),
                (double)((float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e70 + FLOAT_00108e74),
                (double)((float)((double)CONCAT44(0x43300000,(int)param_3[2] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e70 + FLOAT_00108e74),
                (double)((float)((double)CONCAT44(0x43300000,(int)param_3[3] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e70 + FLOAT_00108e74));
    }
    else {
      iVar4 = param_1 + param_2 * 0x10;
      *(float *)(iVar4 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58) *
           FLOAT_00108e70 + FLOAT_00108e74;
      *(float *)(iVar4 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - dVar1) * fVar2 +
           fVar3;
      *(float *)(iVar4 + 0x1a8) =
           (float)((double)CONCAT44(0x43300000,(int)param_3[2] ^ 0x80000000) - dVar1) * fVar2 +
           fVar3;
      *(float *)(iVar4 + 0x1ac) =
           (float)((double)CONCAT44(0x43300000,(int)param_3[3] ^ 0x80000000) - dVar1) * fVar2 +
           fVar3;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4NsvARB_Comp @ 0xaf9ac (116 bytes) */
int _glVertexAttrib4NsvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined2 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4NsvARB_ListExec_00110478,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined2 *)(puVar1 + 1) = *param_3;
    *(undefined2 *)((int)puVar1 + 6) = param_3[1];
    *(undefined2 *)(puVar1 + 2) = param_3[2];
    *(undefined2 *)((int)puVar1 + 10) = param_3[3];
  }
  return puVar1;
}

/* _glVertexAttrib4NsvARB_CompExec @ 0xafa20 (64 bytes) */
void _glVertexAttrib4NsvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib4NsvARB_Comp)(param_1,param_2,param_3);
  ((double (*)())_glVertexAttrib4NsvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib4NsvARB_ListExec @ 0xafa60 (48 bytes) */
int _glVertexAttrib4NsvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((double (*)())_glVertexAttrib4NsvARB_Exec)(param_1,*param_2,param_2 + 1);
  return 0xc;
}

/* _glVertexAttrib4NivARB_Exec @ 0xafa90 (452 bytes) */
double _glVertexAttrib4NivARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
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
  if (param_2 < 0x10) {
    if (param_2 == 0) {
      pcVar5 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar5 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar5)(param_1,0,param_3,in_r6,in_r7,*(int *)(param_1 + 0x4858),param_3[2] ^ 0x80000000,
                (double)((float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e68 + FLOAT_00108e6c),
                (double)((float)((double)CONCAT44(0x43300000,param_3[1] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e68 + FLOAT_00108e6c),
                (double)((float)((double)CONCAT44(0x43300000,param_3[2] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e68 + FLOAT_00108e6c),
                (double)((float)((double)CONCAT44(0x43300000,param_3[3] ^ 0x80000000) -
                                DOUBLE_00108d58) * FLOAT_00108e68 + FLOAT_00108e6c));
    }
    else {
      iVar4 = param_1 + param_2 * 0x10;
      *(float *)(iVar4 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58) *
           FLOAT_00108e68 + FLOAT_00108e6c;
      *(float *)(iVar4 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,param_3[1] ^ 0x80000000) - dVar1) * fVar2 + fVar3;
      *(float *)(iVar4 + 0x1a8) =
           (float)((double)CONCAT44(0x43300000,param_3[2] ^ 0x80000000) - dVar1) * fVar2 + fVar3;
      *(float *)(iVar4 + 0x1ac) =
           (float)((double)CONCAT44(0x43300000,param_3[3] ^ 0x80000000) - dVar1) * fVar2 + fVar3;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4NivARB_Comp @ 0xafc54 (116 bytes) */
int _glVertexAttrib4NivARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4NivARB_ListExec_00110474,0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = *param_3;
    puVar1[2] = param_3[1];
    puVar1[3] = param_3[2];
    puVar1[4] = param_3[3];
  }
  return puVar1;
}

/* _glVertexAttrib4NivARB_CompExec @ 0xafcc8 (64 bytes) */
void _glVertexAttrib4NivARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib4NivARB_Comp)(param_1,param_2,param_3);
  ((double (*)())_glVertexAttrib4NivARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib4NivARB_ListExec @ 0xafd08 (48 bytes) */
int _glVertexAttrib4NivARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((double (*)())_glVertexAttrib4NivARB_Exec)(param_1,*param_2,param_2 + 1);
  return 0x14;
}

/* _glVertexAttrib4NubvARB_Exec @ 0xafd38 (432 bytes) */
double _glVertexAttrib4NubvARB_Exec(int param_1,uint param_2,byte *param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  float fVar1;
  undefined4 in_r6;
  int iVar2;
  code *pcVar3;
  
  fVar1 = FLOAT_00108e78;
  if (param_2 < 0x10) {
    if (param_2 == 0) {
      iVar2 = *(int *)(param_1 + 0x4858);
      pcVar3 = *(code **)(param_1 + 0x4884);
      if (iVar2 == *(int *)(param_1 + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar3)(param_1,0,param_3,in_r6,iVar2,iVar2,(uint)param_3[2],param_3[1] | 0x4b000000,
                (double)((GH_U2F((unsigned int)((*param_3 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78),
                (double)((GH_U2F((unsigned int)((param_3[1] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78),
                (double)((GH_U2F((unsigned int)((param_3[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78),
                (double)((GH_U2F((unsigned int)((param_3[3] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78));
    }
    else {
      iVar2 = param_1 + param_2 * 0x10;
      *(float *)(iVar2 + 0x1a0) = (GH_U2F((unsigned int)((*param_3 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
      *(float *)(iVar2 + 0x1a4) = (GH_U2F((unsigned int)((param_3[1] | 0x4b000000))) - 8388608.0) * fVar1;
      *(float *)(iVar2 + 0x1a8) = (GH_U2F((unsigned int)((param_3[2] | 0x4b000000))) - 8388608.0) * fVar1;
      *(float *)(iVar2 + 0x1ac) = (GH_U2F((unsigned int)((param_3[3] | 0x4b000000))) - 8388608.0) * fVar1;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4NubvARB_Comp @ 0xafee8 (116 bytes) */
int _glVertexAttrib4NubvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined1 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4NubvARB_ListExec_00110494,8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined1 *)(puVar1 + 1) = *param_3;
    *(undefined1 *)((int)puVar1 + 5) = param_3[1];
    *(undefined1 *)((int)puVar1 + 6) = param_3[2];
    *(undefined1 *)((int)puVar1 + 7) = param_3[3];
  }
  return puVar1;
}

/* _glVertexAttrib4NubvARB_CompExec @ 0xaff5c (64 bytes) */
void _glVertexAttrib4NubvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  
  ((int (*)())_glVertexAttrib4NubvARB_Comp)(param_1,param_2,param_3);
  ((double (*)())_glVertexAttrib4NubvARB_Exec)(param_1,param_2,param_3,fparam_1,in_f2,in_f3,in_f4);
  return;
}

/* _glVertexAttrib4NubvARB_ListExec @ 0xaff9c (48 bytes) */
undefined4 _glVertexAttrib4NubvARB_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((double (*)())_glVertexAttrib4NubvARB_Exec)(param_1,*param_2,param_2 + 1,fparam_1,fparam_2,fparam_3,fparam_4);
  return 8;
}

/* _glVertexAttrib4NusvARB_Exec @ 0xaffcc (432 bytes) */
double _glVertexAttrib4NusvARB_Exec(int param_1,uint param_2,ushort *param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  float fVar1;
  undefined4 in_r6;
  int iVar2;
  code *pcVar3;
  
  fVar1 = FLOAT_00108e74;
  if (param_2 < 0x10) {
    if (param_2 == 0) {
      iVar2 = *(int *)(param_1 + 0x4858);
      pcVar3 = *(code **)(param_1 + 0x4884);
      if (iVar2 == *(int *)(param_1 + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar3)(param_1,0,param_3,in_r6,iVar2,iVar2,(uint)param_3[2],param_3[1] | 0x4b000000,
                (double)((GH_U2F((unsigned int)((*param_3 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74),
                (double)((GH_U2F((unsigned int)((param_3[1] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74),
                (double)((GH_U2F((unsigned int)((param_3[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74),
                (double)((GH_U2F((unsigned int)((param_3[3] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74));
    }
    else {
      iVar2 = param_1 + param_2 * 0x10;
      *(float *)(iVar2 + 0x1a0) = (GH_U2F((unsigned int)((*param_3 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
      *(float *)(iVar2 + 0x1a4) = (GH_U2F((unsigned int)((param_3[1] | 0x4b000000))) - 8388608.0) * fVar1;
      *(float *)(iVar2 + 0x1a8) = (GH_U2F((unsigned int)((param_3[2] | 0x4b000000))) - 8388608.0) * fVar1;
      *(float *)(iVar2 + 0x1ac) = (GH_U2F((unsigned int)((param_3[3] | 0x4b000000))) - 8388608.0) * fVar1;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4NusvARB_Comp @ 0xb017c (116 bytes) */
int _glVertexAttrib4NusvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined2 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4NusvARB_ListExec_00110470,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined2 *)(puVar1 + 1) = *param_3;
    *(undefined2 *)((int)puVar1 + 6) = param_3[1];
    *(undefined2 *)(puVar1 + 2) = param_3[2];
    *(undefined2 *)((int)puVar1 + 10) = param_3[3];
  }
  return puVar1;
}

/* _glVertexAttrib4NusvARB_CompExec @ 0xb01f0 (64 bytes) */
void _glVertexAttrib4NusvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  
  ((int (*)())_glVertexAttrib4NusvARB_Comp)(param_1,param_2,param_3);
  ((double (*)())_glVertexAttrib4NusvARB_Exec)(param_1,param_2,param_3,fparam_1,in_f2,in_f3,in_f4);
  return;
}

/* _glVertexAttrib4NusvARB_ListExec @ 0xb0230 (48 bytes) */
undefined4 _glVertexAttrib4NusvARB_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((double (*)())_glVertexAttrib4NusvARB_Exec)(param_1,*param_2,param_2 + 1,fparam_1,fparam_2,fparam_3,fparam_4);
  return 0xc;
}

/* _glVertexAttrib4NuivARB_Exec @ 0xb0260 (404 bytes) */
double _glVertexAttrib4NuivARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 *param_3;
{
  double dVar1;
  float fVar2;
  int iVar3;
  undefined4 in_r6;
  undefined4 in_r7;
  code *pcVar4;
  
  fVar2 = FLOAT_00108e6c;
  dVar1 = DOUBLE_00108d70;
  if (param_2 < 0x10) {
    if (param_2 == 0) {
      pcVar4 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar4 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar4)(param_1,0,param_3,in_r6,in_r7,*(int *)(param_1 + 0x4858),param_3[1],
                (double)((float)((double)CONCAT44(0x43300000,*param_3) - DOUBLE_00108d70) *
                        FLOAT_00108e6c),
                (double)((float)((double)CONCAT44(0x43300000,param_3[1]) - DOUBLE_00108d70) *
                        FLOAT_00108e6c),
                (double)((float)((double)CONCAT44(0x43300000,param_3[2]) - DOUBLE_00108d70) *
                        FLOAT_00108e6c),
                (double)((float)((double)CONCAT44(0x43300000,param_3[3]) - DOUBLE_00108d70) *
                        FLOAT_00108e6c));
    }
    else {
      iVar3 = param_1 + param_2 * 0x10;
      *(float *)(iVar3 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,*param_3) - DOUBLE_00108d70) * FLOAT_00108e6c;
      *(float *)(iVar3 + 0x1a4) = (float)((double)CONCAT44(0x43300000,param_3[1]) - dVar1) * fVar2;
      *(float *)(iVar3 + 0x1a8) = (float)((double)CONCAT44(0x43300000,param_3[2]) - dVar1) * fVar2;
      *(float *)(iVar3 + 0x1ac) = (float)((double)CONCAT44(0x43300000,param_3[3]) - dVar1) * fVar2;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4NuivARB_Comp @ 0xb03f4 (116 bytes) */
int _glVertexAttrib4NuivARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4NuivARB_ListExec_0011046c,0x14)
  ;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = *param_3;
    puVar1[2] = param_3[1];
    puVar1[3] = param_3[2];
    puVar1[4] = param_3[3];
  }
  return puVar1;
}

/* _glVertexAttrib4NuivARB_CompExec @ 0xb0468 (64 bytes) */
void _glVertexAttrib4NuivARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib4NuivARB_Comp)(param_1,param_2,param_3);
  ((double (*)())_glVertexAttrib4NuivARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib4NuivARB_ListExec @ 0xb04a8 (48 bytes) */
int _glVertexAttrib4NuivARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((double (*)())_glVertexAttrib4NuivARB_Exec)(param_1,*param_2,param_2 + 1);
  return 0x14;
}

/* _glEnableVertexAttribArrayARB_Exec @ 0xb04d8 (236 bytes) */
void _glEnableVertexAttribArrayARB_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  
  iVar2 = *(int *)(param_1 + 0x4a60);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 < 0x10) {
      lVar4 = ___ashldi3(1,0,param_2);
      uVar3 = (uint)((ulonglong)lVar4 >> 0x20);
      *(uint *)(iVar2 + 0x330) = *(uint *)(iVar2 + 0x330) | uVar3;
      *(uint *)(iVar2 + 0x334) = *(uint *)(iVar2 + 0x334) | (uint)lVar4;
      *(undefined4 *)(param_1 + 0x488c) = 0;
      *(undefined4 *)(param_1 + 0x4890) = 0;
      *(uint *)(iVar2 + 0x350) = *(uint *)(iVar2 + 0x350) | uVar3;
      *(uint *)(iVar2 + 0x354) = *(uint *)(iVar2 + 0x354) | (uint)lVar4;
      if (((*(int *)(iVar2 + 0x344) == 0) && (*(int *)(iVar2 + 0x358) == 0)) &&
         (*(int *)(param_1 + 0x49a0) == 0)) {
        return;
      }
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glDisableVertexAttribArrayARB_Exec @ 0xb05c4 (244 bytes) */
void _glDisableVertexAttribArrayARB_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  
  iVar2 = *(int *)(param_1 + 0x4a60);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 < 0x10) {
      lVar4 = ___ashldi3(1,0,param_2);
      uVar3 = (uint)((ulonglong)lVar4 >> 0x20);
      *(uint *)(iVar2 + 0x330) = *(uint *)(iVar2 + 0x330) & ~uVar3;
      *(uint *)(iVar2 + 0x334) = *(uint *)(iVar2 + 0x334) & ~(uint)lVar4;
      *(undefined4 *)(param_1 + 0x488c) = 0;
      *(undefined4 *)(param_1 + 0x4890) = 0;
      *(uint *)(iVar2 + 0x350) = *(uint *)(iVar2 + 0x350) | uVar3;
      *(uint *)(iVar2 + 0x354) = *(uint *)(iVar2 + 0x354) | (uint)lVar4;
      if (((*(int *)(iVar2 + 0x344) == 0) && (*(int *)(iVar2 + 0x358) == 0)) &&
         (*(int *)(param_1 + 0x49a0) == 0)) {
        return;
      }
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glEnableVertexAttribARB_Exec @ 0xb06b8 (264 bytes) */
void _glEnableVertexAttribARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 < 0x10) {
      if (param_3 == 0x8a00) {
        iVar2 = _gleGetMapData(param_1);
        *(uint *)(param_1 + 0x74d8) = *(uint *)(param_1 + 0x74d8) | 1 << (param_2 & 0x3f);
        *(char *)(param_2 + param_1 + 0x7524) =
             (char)((code **)_gleSelectVertexAddMaterialFunc)[param_2 + iVar2] << 2;
        return;
      }
      if (param_3 == 0x8a01) {
        iVar2 = _gleGetMapData(param_1);
        *(uint *)(param_1 + 0x74dc) = *(uint *)(param_1 + 0x74dc) | 1 << (param_2 & 0x3f);
        *(char *)(param_2 + param_1 + 0x7564) = *(char *)(param_2 + iVar2 + 0x9db8) << 2;
        return;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
    }
    else {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
    }
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glEnableVertexAttribARB_Comp @ 0xb07c0 (84 bytes) */
int _glEnableVertexAttribARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glEnableVertexAttribARB_ListExec_00110468,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glEnableVertexAttribARB_CompExec @ 0xb0814 (64 bytes) */
void _glEnableVertexAttribARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glEnableVertexAttribARB_Comp)(param_1,param_2,param_3);
  ((void (*)())_glEnableVertexAttribARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glEnableVertexAttribARB_ListExec @ 0xb0854 (44 bytes) */
int _glEnableVertexAttribARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glEnableVertexAttribARB_Exec)(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glDisableVertexAttribARB_Exec @ 0xb0880 (192 bytes) */
void _glDisableVertexAttribARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined4 uVar1;
  uint uVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 < 0x10) {
      if (param_3 == 0x8a00) {
        uVar2 = *(uint *)(param_1 + 0x74d8);
        *(undefined1 *)(param_2 + param_1 + 0x7524) = 0;
        *(uint *)(param_1 + 0x74d8) =
             uVar2 & (-2 << (param_2 & 0x1f) | 0xfffffffeU >> 0x20 - (param_2 & 0x1f));
        return;
      }
      if (param_3 == 0x8a01) {
        uVar2 = *(uint *)(param_1 + 0x74dc);
        *(undefined1 *)(param_2 + param_1 + 0x7564) = 0;
        *(uint *)(param_1 + 0x74dc) =
             uVar2 & (-2 << (param_2 & 0x1f) | 0xfffffffeU >> 0x20 - (param_2 & 0x1f));
        return;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
    }
    else {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
    }
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glDisableVertexAttribARB_Comp @ 0xb0940 (84 bytes) */
int _glDisableVertexAttribARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glDisableVertexAttribARB_ListExec_00110464,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glDisableVertexAttribARB_CompExec @ 0xb0994 (64 bytes) */
void _glDisableVertexAttribARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glDisableVertexAttribARB_Comp)(param_1,param_2,param_3);
  ((void (*)())_glDisableVertexAttribARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glDisableVertexAttribARB_ListExec @ 0xb09d4 (44 bytes) */
int _glDisableVertexAttribARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glDisableVertexAttribARB_Exec)(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glIsVertexAttribEnabledARB_Exec @ 0xb0a00 (160 bytes) */
int _glIsVertexAttribEnabledARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined4 uVar1;
  uint uVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 < 0x10) {
      if (param_3 == 0x8a00) {
        uVar2 = *(uint *)(param_1 + 0x74d8);
      }
      else {
        if (param_3 != 0x8a01) {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return false;
          }
          uVar1 = 0x500;
          goto LAB_000b0a94;
        }
        uVar2 = *(uint *)(param_1 + 0x74dc);
      }
      return (uVar2 & 1 << (param_2 & 0x3f)) != 0;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return false;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return false;
    }
    uVar1 = 0x502;
  }
LAB_000b0a94:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return false;
}

/* _glGetVertexAttribdvARB_Exec @ 0xb0aa0 (1104 bytes) */
void _glGetVertexAttribdvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  double *param_4;
{
  unsigned char cVar1;
  float fVar2;
  undefined4 uVar3;
  uint uVar4;
  float *pfVar5;
  uint *puVar6;
  int iVar7;
  double *pdVar8;
  int iVar9;
  double dVar10;
  double dVar11;
  longlong lVar12;
  uint uStack_1c;
  
  if (0xf < param_2) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
    goto LAB_000b0ed8;
  }
  if (param_3 == 0x8a02) {
    iVar9 = _gleGetMapData(param_1);
    cVar1 = ((code **)_gleSelectVertexAddMaterialFunc)[param_2 + iVar9];
LAB_000b0dcc:
    uStack_1c = (uint)(byte)cVar1;
  }
  else {
    if (param_3 < 0x8a03) {
      dVar11 = DOUBLE_00108d58;
      if (param_3 == 0x8624) {
        dVar10 = (double)CONCAT44(0x43300000,
                                  *(uint *)(param_2 * 0x18 + *(int *)(param_1 + 0x4a60) + 0x1b4) ^
                                  0x80000000);
        goto LAB_000b0de4;
      }
      if (param_3 < 0x8625) {
        if (param_3 == 0x8622) {
          iVar9 = *(int *)(param_1 + 0x4a60);
          lVar12 = ___ashldi3(1,0,param_2);
          uVar3 = 0x3ff00000;
          if ((*(uint *)(iVar9 + 0x330) & (uint)((ulonglong)lVar12 >> 0x20)) == 0 &&
              (*(uint *)(iVar9 + 0x334) & (uint)lVar12) == 0) {
            uVar3 = 0;
          }
          *(undefined4 *)param_4 = uVar3;
          *(undefined4 *)((int)param_4 + 4) = 0;
          return;
        }
        if (param_3 == 0x8623) {
          uStack_1c = (uint)*(short *)(param_2 * 0x18 + *(int *)(param_1 + 0x4a60) + 0x1ba);
LAB_000b0cc8:
          uStack_1c = uStack_1c ^ 0x80000000;
          dVar10 = (double)CONCAT44(0x43300000,uStack_1c);
          goto LAB_000b0de4;
        }
      }
      else {
        if (param_3 == 0x8626) {
          if (param_2 != 0) {
            iVar9 = 4;
            pfVar5 = (float *)(param_1 + param_2 * 0x10 + 0x1a0);
            do {
              fVar2 = *pfVar5;
              pfVar5 = pfVar5 + 1;
              *param_4 = (double)fVar2;
              param_4 = param_4 + 1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
            return;
          }
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x502;
          goto LAB_000b0ed8;
        }
        if (param_3 < 0x8626) {
          uStack_1c = *(ushort *)(param_2 * 0x18 + *(int *)(param_1 + 0x4a60) + 0x1b8) & 0xffff7fff;
          goto LAB_000b0cc8;
        }
        if (param_3 == 0x886a) {
          uVar3 = 0x3ff00000;
          if (-1 < *(short *)(param_2 * 0x18 + *(int *)(param_1 + 0x4a60) + 0x1b8)) {
            uVar3 = 0;
          }
          *(undefined4 *)param_4 = uVar3;
          *(undefined4 *)((int)param_4 + 4) = 0;
          return;
        }
      }
LAB_000b0ec8:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
LAB_000b0ed8:
      *(undefined4 *)(param_1 + 0x7574) = uVar3;
      return;
    }
    if (param_3 == 0x8a06) {
      iVar9 = _gleGetMapData(param_1);
      cVar1 = *(code *)(param_2 + iVar9 + 0x9db8);
      goto LAB_000b0dcc;
    }
    if (0x8a06 < param_3) {
      if (param_3 == 0x8a08) {
        iVar9 = _gleGetMapData(param_1);
        dVar10 = DOUBLE_00108d58;
        puVar6 = (uint *)(iVar9 + param_2 * 0x660 + 0x37a8);
        pdVar8 = param_4 + 1;
        do {
          uVar4 = *puVar6;
          puVar6 = puVar6 + 1;
          *param_4 = (double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - dVar10;
          param_4 = param_4 + 1;
        } while (param_4 <= pdVar8);
        return;
      }
      if (param_3 < 0x8a08) {
        iVar9 = _gleGetMapData(param_1);
        iVar7 = param_2 * 0x660 + iVar9;
        pfVar5 = (float *)(iVar7 + 0x37c8);
        for (iVar9 = *(int *)(iVar7 + 0x37a8) * *(int *)(iVar7 + 0x37ac) *
                     (uint)*(byte *)(param_2 + iVar9 + 0x9db8); iVar9 != 0; iVar9 = iVar9 + -1) {
          fVar2 = *pfVar5;
          pfVar5 = pfVar5 + 1;
          *param_4 = (double)fVar2;
          param_4 = param_4 + 1;
        }
        return;
      }
      if (param_3 == 0x8a09) {
        iVar9 = _gleGetMapData(param_1);
        iVar7 = 4;
        pfVar5 = (float *)(iVar9 + param_2 * 0x660 + 0x37b0);
        do {
          fVar2 = *pfVar5;
          pfVar5 = pfVar5 + 1;
          *param_4 = (double)fVar2;
          param_4 = param_4 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        return;
      }
      goto LAB_000b0ec8;
    }
    if (param_3 != 0x8a04) {
      if (param_3 < 0x8a05) {
        iVar9 = _gleGetMapData(param_1);
        iVar7 = param_2 * 0xb0 + iVar9;
        pfVar5 = (float *)(iVar7 + 0x2cb8);
        for (iVar9 = *(int *)(iVar7 + 0x2ca8) *
                     (uint)(byte)((code **)_gleSelectVertexAddMaterialFunc)[param_2 + iVar9]; iVar9 != 0;
            iVar9 = iVar9 + -1) {
          fVar2 = *pfVar5;
          pfVar5 = pfVar5 + 1;
          *param_4 = (double)fVar2;
          param_4 = param_4 + 1;
        }
        return;
      }
      iVar9 = _gleGetMapData(param_1);
      pdVar8 = param_4 + 1;
      pfVar5 = (float *)(iVar9 + param_2 * 0xb0 + 0x2cac);
      do {
        fVar2 = *pfVar5;
        pfVar5 = pfVar5 + 1;
        *param_4 = (double)fVar2;
        param_4 = param_4 + 1;
      } while (param_4 <= pdVar8);
      return;
    }
    iVar9 = _gleGetMapData(param_1);
    uStack_1c = *(uint *)(param_2 * 0xb0 + iVar9 + 0x2ca8);
  }
  dVar10 = (double)CONCAT44(0x43300000,uStack_1c);
  dVar11 = DOUBLE_00108d70;
LAB_000b0de4:
  *param_4 = dVar10 - dVar11;
  return;
}

/* _glGetVertexAttribfvARB_Exec @ 0xb0ef0 (1116 bytes) */
void _glGetVertexAttribfvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  float *param_4;
{
  unsigned char cVar1;
  undefined4 uVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  double dVar9;
  longlong lVar10;
  uint uStack_2c;
  
  if (0xf < param_2) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
    goto LAB_000b1334;
  }
  if (param_3 == 0x8a02) {
    iVar6 = _gleGetMapData(param_1);
    cVar1 = ((code **)_gleSelectVertexAddMaterialFunc)[param_2 + iVar6];
LAB_000b1220:
    *param_4 = GH_U2F((unsigned int)(((byte)cVar1 | 0x4b000000))) - 8388608.0;
  }
  else {
    if (param_3 < 0x8a03) {
      dVar9 = DOUBLE_00108d58;
      if (param_3 != 0x8624) {
        if (param_3 < 0x8625) {
          if (param_3 == 0x8622) {
            iVar6 = *(int *)(param_1 + 0x4a60);
            lVar10 = ___ashldi3(1,0,param_2);
            fVar3 = 1.0;
            if ((*(uint *)(iVar6 + 0x330) & (uint)((ulonglong)lVar10 >> 0x20)) == 0 &&
                (*(uint *)(iVar6 + 0x334) & (uint)lVar10) == 0) {
              fVar3 = 0.0;
            }
            *param_4 = fVar3;
            return;
          }
          if (param_3 == 0x8623) {
            uStack_2c = (uint)*(short *)(param_2 * 0x18 + *(int *)(param_1 + 0x4a60) + 0x1ba);
LAB_000b110c:
            uStack_2c = uStack_2c ^ 0x80000000;
            dVar8 = (double)CONCAT44(0x43300000,uStack_2c);
            goto LAB_000b11cc;
          }
        }
        else {
          if (param_3 == 0x8626) {
            if (param_2 != 0) {
              iVar7 = 4;
              iVar6 = 0;
              do {
                *(undefined4 *)(iVar6 + (int)param_4) =
                     *(undefined4 *)(iVar6 + param_1 + param_2 * 0x10 + 0x1a0);
                iVar6 = iVar6 + 4;
                iVar7 = iVar7 + -1;
              } while (iVar7 != 0);
              return;
            }
            if (*(int *)(param_1 + 0x7574) != 0) {
              return;
            }
            uVar2 = 0x502;
            goto LAB_000b1334;
          }
          if (param_3 < 0x8626) {
            uStack_2c = *(ushort *)(param_2 * 0x18 + *(int *)(param_1 + 0x4a60) + 0x1b8) &
                        0xffff7fff;
            goto LAB_000b110c;
          }
          if (param_3 == 0x886a) {
            fVar3 = 1.0;
            if (-1 < *(short *)(param_2 * 0x18 + *(int *)(param_1 + 0x4a60) + 0x1b8)) {
              fVar3 = 0.0;
            }
            *param_4 = fVar3;
            return;
          }
        }
LAB_000b1324:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar2 = 0x500;
LAB_000b1334:
        *(undefined4 *)(param_1 + 0x7574) = uVar2;
        return;
      }
      dVar8 = (double)CONCAT44(0x43300000,
                               *(uint *)(param_2 * 0x18 + *(int *)(param_1 + 0x4a60) + 0x1b4) ^
                               0x80000000);
    }
    else {
      if (param_3 == 0x8a06) {
        iVar6 = _gleGetMapData(param_1);
        cVar1 = *(code *)(param_2 + iVar6 + 0x9db8);
        goto LAB_000b1220;
      }
      if (0x8a06 < param_3) {
        if (param_3 == 0x8a08) {
          iVar6 = _gleGetMapData(param_1);
          dVar8 = DOUBLE_00108d58;
          uVar4 = 0;
          iVar7 = 0;
          do {
            uVar4 = uVar4 + 1;
            *(float *)(iVar7 + (int)param_4) =
                 (float)((double)CONCAT44(0x43300000,
                                          *(uint *)(iVar7 + iVar6 + param_2 * 0x660 + 0x37a8) ^
                                          0x80000000) - dVar8);
            iVar7 = iVar7 + 4;
          } while (uVar4 < 2);
          return;
        }
        if (param_3 < 0x8a08) {
          iVar6 = _gleGetMapData(param_1);
          iVar5 = param_2 * 0x660 + iVar6;
          iVar7 = *(int *)(iVar5 + 0x37a8) * *(int *)(iVar5 + 0x37ac) *
                  (uint)*(byte *)(param_2 + iVar6 + 0x9db8);
          iVar6 = 0;
          for (; iVar7 != 0; iVar7 = iVar7 + -1) {
            param_4[iVar6] = *(float *)(iVar5 + 0x37c8 + iVar6 * 4);
            iVar6 = iVar6 + 1;
          }
          return;
        }
        if (param_3 == 0x8a09) {
          iVar6 = _gleGetMapData(param_1);
          iVar5 = 4;
          iVar7 = 0;
          do {
            *(undefined4 *)(iVar7 + (int)param_4) =
                 *(undefined4 *)(iVar7 + iVar6 + param_2 * 0x660 + 0x37b0);
            iVar7 = iVar7 + 4;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          return;
        }
        goto LAB_000b1324;
      }
      if (param_3 != 0x8a04) {
        if (param_3 < 0x8a05) {
          iVar6 = _gleGetMapData(param_1);
          iVar5 = param_2 * 0xb0 + iVar6;
          iVar7 = *(int *)(iVar5 + 0x2ca8) *
                  (uint)(byte)((code **)_gleSelectVertexAddMaterialFunc)[param_2 + iVar6];
          iVar6 = 0;
          for (; iVar7 != 0; iVar7 = iVar7 + -1) {
            param_4[iVar6] = *(float *)(iVar5 + 0x2cb8 + iVar6 * 4);
            iVar6 = iVar6 + 1;
          }
          return;
        }
        iVar6 = _gleGetMapData(param_1);
        uVar4 = 0;
        iVar7 = 0;
        do {
          uVar4 = uVar4 + 1;
          *(undefined4 *)(iVar7 + (int)param_4) =
               *(undefined4 *)(iVar7 + iVar6 + param_2 * 0xb0 + 0x2cac);
          iVar7 = iVar7 + 4;
        } while (uVar4 < 2);
        return;
      }
      iVar6 = _gleGetMapData(param_1);
      dVar8 = (double)CONCAT44(0x43300000,*(undefined4 *)(param_2 * 0xb0 + iVar6 + 0x2ca8));
      dVar9 = DOUBLE_00108d70;
    }
LAB_000b11cc:
    *param_4 = (float)(dVar8 - dVar9);
  }
  return;
}

/* _glGetVertexAttribivARB_Exec @ 0xb134c (1040 bytes) */
void _glGetVertexAttribivARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  
  if (param_2 < 0x10) {
    if (param_3 == 0x8a02) {
      iVar4 = _gleGetMapData(param_1);
      uVar2 = (uint)(byte)((code **)_gleSelectVertexAddMaterialFunc)[param_2 + iVar4];
    }
    else {
      if (param_3 < 0x8a03) {
        if (param_3 == 0x8625) {
          uVar2 = *(ushort *)(param_2 * 0x18 + *(int *)(param_1 + 0x4a60) + 0x1b8) & 0xffff7fff;
          goto LAB_000b1560;
        }
        if (param_3 < 0x8626) {
          if (param_3 == 0x8623) {
            uVar2 = (uint)*(short *)(param_2 * 0x18 + *(int *)(param_1 + 0x4a60) + 0x1ba);
LAB_000b1560:
            *param_4 = uVar2;
            return;
          }
          if (0x8623 < param_3) {
            uVar2 = *(uint *)(param_2 * 0x18 + *(int *)(param_1 + 0x4a60) + 0x1b4);
            goto LAB_000b1560;
          }
          if (param_3 == 0x8622) {
            iVar4 = *(int *)(param_1 + 0x4a60);
            lVar6 = ___ashldi3(1,0,param_2);
            uVar2 = 0;
            if ((*(uint *)(iVar4 + 0x330) & (uint)((ulonglong)lVar6 >> 0x20)) != 0 ||
                (*(uint *)(iVar4 + 0x334) & (uint)lVar6) != 0) {
              uVar2 = 1;
            }
            goto LAB_000b165c;
          }
        }
        else {
          if (param_3 == 0x886a) {
            uVar2 = (uint)(int)*(short *)(param_2 * 0x18 + *(int *)(param_1 + 0x4a60) + 0x1b8) >>
                    0x1f;
            goto LAB_000b1560;
          }
          if (param_3 < 0x886b) {
            if (param_3 == 0x8626) {
              if (param_2 != 0) {
                iVar5 = 4;
                iVar4 = 0;
                do {
                  *(int *)(iVar4 + (int)param_4) =
                       (int)GH_F2U(*(float *)(iVar4 + param_1 + param_2 * 0x10 + 0x1a0));
                  iVar4 = iVar4 + 4;
                  iVar5 = iVar5 + -1;
                } while (iVar5 != 0);
                return;
              }
              if (*(int *)(param_1 + 0x7574) != 0) {
                return;
              }
              uVar1 = 0x502;
              goto LAB_000b1744;
            }
          }
          else if (param_3 == 0x889f) {
            uVar2 = 0;
            iVar4 = *(int *)(param_2 * 4 + *(int *)(param_1 + 0x4a60) + 0x3a0);
            if (iVar4 != 0) {
              uVar2 = *(uint *)(iVar4 + 4);
            }
            goto LAB_000b165c;
          }
        }
LAB_000b1734:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x500;
        goto LAB_000b1744;
      }
      if (param_3 == 0x8a06) {
        iVar4 = _gleGetMapData(param_1);
        uVar2 = (uint)*(byte *)(param_2 + iVar4 + 0x9db8);
      }
      else {
        if (0x8a06 < param_3) {
          if (param_3 == 0x8a08) {
            iVar4 = _gleGetMapData(param_1);
            uVar2 = 0;
            iVar5 = 0;
            do {
              uVar2 = uVar2 + 1;
              *(undefined4 *)(iVar5 + (int)param_4) =
                   *(undefined4 *)(iVar5 + iVar4 + param_2 * 0x660 + 0x37a8);
              iVar5 = iVar5 + 4;
            } while (uVar2 < 2);
            return;
          }
          if (param_3 < 0x8a08) {
            iVar4 = _gleGetMapData(param_1);
            iVar3 = param_2 * 0x660 + iVar4;
            iVar5 = *(int *)(iVar3 + 0x37a8) * *(int *)(iVar3 + 0x37ac) *
                    (uint)*(byte *)(param_2 + iVar4 + 0x9db8);
            iVar4 = 0;
            for (; iVar5 != 0; iVar5 = iVar5 + -1) {
              param_4[iVar4] = (int)GH_F2U(*(float *)(iVar4 * 4 + iVar3 + 0x37c8));
              iVar4 = iVar4 + 1;
            }
            return;
          }
          if (param_3 == 0x8a09) {
            iVar4 = _gleGetMapData(param_1);
            iVar3 = 4;
            iVar5 = 0;
            do {
              *(int *)(iVar5 + (int)param_4) =
                   (int)GH_F2U(*(float *)(iVar5 + iVar4 + param_2 * 0x660 + 0x37b0));
              iVar5 = iVar5 + 4;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
            return;
          }
          goto LAB_000b1734;
        }
        if (param_3 != 0x8a04) {
          if (param_3 < 0x8a05) {
            iVar4 = _gleGetMapData(param_1);
            iVar3 = param_2 * 0xb0 + iVar4;
            iVar5 = *(int *)(iVar3 + 0x2ca8) *
                    (uint)(byte)((code **)_gleSelectVertexAddMaterialFunc)[param_2 + iVar4];
            iVar4 = 0;
            for (; iVar5 != 0; iVar5 = iVar5 + -1) {
              param_4[iVar4] = (int)GH_F2U(*(float *)(iVar4 * 4 + iVar3 + 0x2cb8));
              iVar4 = iVar4 + 1;
            }
            return;
          }
          iVar4 = _gleGetMapData(param_1);
          uVar2 = 0;
          iVar5 = 0;
          do {
            uVar2 = uVar2 + 1;
            *(int *)(iVar5 + (int)param_4) =
                 (int)GH_F2U(*(float *)(iVar5 + iVar4 + param_2 * 0xb0 + 0x2cac));
            iVar5 = iVar5 + 4;
          } while (uVar2 < 2);
          return;
        }
        iVar4 = _gleGetMapData(param_1);
        uVar2 = *(uint *)(param_2 * 0xb0 + iVar4 + 0x2ca8);
      }
    }
LAB_000b165c:
    *param_4 = uVar2;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
LAB_000b1744:
    *(undefined4 *)(param_1 + 0x7574) = uVar1;
  }
  return;
}

/* _glGetVertexAttribPointervARB_Exec @ 0xb175c (92 bytes) */
void _glGetVertexAttribPointervARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  
  if (param_2 < 0x10) {
    if (param_3 == 0x8645) {
      *param_4 = *(undefined4 *)(param_2 * 0x18 + *(int *)(param_1 + 0x4a60) + 0x1b0);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glViewport_ListExec @ 0xb17b8 (56 bytes) */
undefined4 _glViewport_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glViewport_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3],fparam_1,fparam_2,fparam_3,
                   fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return 0x10;
}

/* _glViewport_Comp @ 0xb17f0 (100 bytes) */
int _glViewport_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glViewport_ListExec_001104c8,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[3] = param_5;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
  }
  return puVar1;
}

/* _glViewport_CompExec @ 0xb1854 (80 bytes) */
void _glViewport_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glViewport_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((void (*)())_glViewport_Exec)(param_1,param_2,param_3,param_4,param_5,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,
                   in_f7,in_f8);
  return;
}

/* _glWindowPos2_ListExec @ 0xb18a4 (68 bytes) */
int _glWindowPos2_ListExec(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((double (*)())_gleSetWindowPos)(param_1,(double)*param_2,(double)param_2[1],(double)FLOAT_00108e50);
  return 8;
}

/* _glWindowPos3_ListExec @ 0xb18e8 (48 bytes) */
int _glWindowPos3_ListExec(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((double (*)())_gleSetWindowPos)(param_1,(double)*param_2,(double)param_2[1],(double)param_2[2]);
  return 0xc;
}

/* _glWindowPos2d_Exec @ 0xb1918 (72 bytes) */
void _glWindowPos2d_Exec(int param_1,double fparam_1,double fparam_2)
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,(double)(float)fparam_1,(double)(float)fparam_2,(double)FLOAT_00108e50)
    ;
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glWindowPos2d_Comp @ 0xb1960 (108 bytes) */
float * _glWindowPos2d_Comp(undefined4 param_1,double fparam_1,double fparam_2)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glWindowPos2_ListExec_001104d0,8);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
  }
  return pfVar1;
}

/* _glWindowPos2d_CompExec @ 0xb19cc (80 bytes) */
void _glWindowPos2d_CompExec(undefined4 param_1,double fparam_1,double fparam_2)
{
  ((float * (*)())_glWindowPos2d_Comp)(param_1,fparam_1,fparam_2);
  ((void (*)())_glWindowPos2d_Exec)(param_1,fparam_1,fparam_2);
  return;
}

/* _glWindowPos2dv_Exec @ 0xb1a1c (80 bytes) */
void _glWindowPos2dv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,(double)(float)*param_2,(double)(float)param_2[1],
                     (double)FLOAT_00108e50);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glWindowPos2dv_Comp @ 0xb1a6c (96 bytes) */
int _glWindowPos2dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glWindowPos2_ListExec_001104d0,8);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)*param_2;
    pfVar1[1] = (float)param_2[1];
  }
  return pfVar1;
}

/* _glWindowPos2dv_CompExec @ 0xb1acc (56 bytes) */
void _glWindowPos2dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glWindowPos2dv_Comp)(param_1,param_2);
  ((void (*)())_glWindowPos2dv_Exec)(param_1,param_2);
  return;
}

/* _glWindowPos3d_Exec @ 0xb1b04 (52 bytes) */
void _glWindowPos3d_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3)
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,(double)(float)fparam_1,(double)(float)fparam_2,(double)(float)fparam_3
                    );
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glWindowPos3d_Comp @ 0xb1b38 (128 bytes) */
float * _glWindowPos3d_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glWindowPos3_ListExec_001104cc,0xc);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
  }
  return pfVar1;
}

/* _glWindowPos3d_CompExec @ 0xb1bb8 (96 bytes) */
void _glWindowPos3d_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  ((float * (*)())_glWindowPos3d_Comp)(param_1,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glWindowPos3d_Exec)(param_1,fparam_1,fparam_2,fparam_3);
  return;
}

/* _glWindowPos3dv_Exec @ 0xb1c18 (64 bytes) */
void _glWindowPos3dv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    ((double (*)())_gleSetWindowPos)(param_1,(double)(float)*param_2,(double)(float)param_2[1],
                     (double)(float)param_2[2]);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

