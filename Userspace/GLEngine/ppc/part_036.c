#include "decls.h"

/* _glVertexAttrib1svARB_CompExec @ 0xad674 (64 bytes) */
int _glVertexAttrib1svARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  _glVertexAttrib1svARB_Comp(param_1,param_2,param_3);
  _glVertexAttrib1svARB_Exec(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib1svARB_ListExec @ 0xad6b4 (48 bytes) */
int _glVertexAttrib1svARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glVertexAttrib1svARB_Exec(param_1,*param_2,param_2 + 1);
  return 6;
}

/* _glVertexAttrib1fvARB_Exec @ 0xad6e4 (144 bytes) */
int _glVertexAttrib1fvARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  float *param_3;
{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 < 0x10) {
    fVar1 = *(float *)(param_1 + 0x20);
    uVar2 = *(undefined4 *)(param_1 + 0x24);
    if (param_2 != 0) {
      iVar3 = param_1 + param_2 * 0x10;
      *(float *)(iVar3 + 0x1a0) = *param_3;
      *(undefined4 *)(iVar3 + 0x1ac) = uVar2;
      *(float *)(iVar3 + 0x1a8) = fVar1;
      *(float *)(iVar3 + 0x1a4) = fVar1;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(double,double,double))UNRECOVERED_JUMPTABLE))((double)*param_3, (double)fVar1, (double)fVar1);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib1fvARB_Comp @ 0xad774 (88 bytes) */
int _glVertexAttrib1fvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib1fvARB_ListExec_001104c0,8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = *param_3;
  }
  return puVar1;
}

/* _glVertexAttrib1fvARB_CompExec @ 0xad7cc (64 bytes) */
int _glVertexAttrib1fvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib1fvARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glVertexAttrib1fvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib1fvARB_ListExec @ 0xad80c (48 bytes) */
int _glVertexAttrib1fvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glVertexAttrib1fvARB_Exec)(param_1,*param_2,param_2 + 1);
  return 8;
}

/* _glVertexAttrib1dvARB_Exec @ 0xad83c (152 bytes) */
int _glVertexAttrib1dvARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  double *param_3;
{
  float fVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  double dVar3;
  
  if (param_2 < 0x10) {
    fVar1 = *(float *)(param_1 + 0x20);
    if (param_2 != 0) {
      dVar3 = *param_3;
      iVar2 = param_1 + param_2 * 0x10;
      *(undefined4 *)(iVar2 + 0x1ac) = *(undefined4 *)(param_1 + 0x24);
      *(float *)(iVar2 + 0x1a8) = fVar1;
      *(float *)(iVar2 + 0x1a0) = (float)dVar3;
      *(float *)(iVar2 + 0x1a4) = fVar1;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(double,double,double))UNRECOVERED_JUMPTABLE))((double)GH_U2F((unsigned int)(*param_3)), (double)fVar1, (double)fVar1);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib1dvARB_Comp @ 0xad8d4 (88 bytes) */
int _glVertexAttrib1dvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined8 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib1dvARB_ListExec_001104bc,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined8 *)(puVar1 + 1) = *param_3;
  }
  return puVar1;
}

/* _glVertexAttrib1dvARB_CompExec @ 0xad92c (64 bytes) */
int _glVertexAttrib1dvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib1dvARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glVertexAttrib1dvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib1dvARB_ListExec @ 0xad96c (48 bytes) */
int _glVertexAttrib1dvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glVertexAttrib1dvARB_Exec)(param_1,*param_2,param_2 + 1);
  return 0xc;
}

/* _glVertexAttrib2svARB_Exec @ 0xad99c (292 bytes) */
int _glVertexAttrib2svARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  short *param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar3;
  double dVar4;
  int iVar5;
  code *pcVar6;
  
  dVar4 = DOUBLE_00108d58;
  if (param_2 < 0x10) {
    uVar1 = *(undefined4 *)(param_1 + 0x20);
    uVar2 = *(undefined4 *)(param_1 + 0x24);
    if (param_2 == 0) {
      pcVar6 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar6 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*((int (*)(double,double))pcVar6))((double)(float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58), (double)(float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - DOUBLE_00108d58));
    }
    else {
      iVar5 = param_1 + param_2 * 0x10;
      *(float *)(iVar5 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58);
      sVar3 = param_3[1];
      *(undefined4 *)(iVar5 + 0x1ac) = uVar2;
      *(undefined4 *)(iVar5 + 0x1a8) = uVar1;
      *(float *)(iVar5 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) - dVar4);
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib2svARB_Comp @ 0xadac0 (96 bytes) */
int _glVertexAttrib2svARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined2 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib2svARB_ListExec_001104b8,8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined2 *)(puVar1 + 1) = *param_3;
    *(undefined2 *)((int)puVar1 + 6) = param_3[1];
  }
  return puVar1;
}

/* _glVertexAttrib2svARB_CompExec @ 0xadb20 (64 bytes) */
int _glVertexAttrib2svARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib2svARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glVertexAttrib2svARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib2svARB_ListExec @ 0xadb60 (48 bytes) */
int _glVertexAttrib2svARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glVertexAttrib2svARB_Exec)(param_1,*param_2,param_2 + 1);
  return 8;
}

/* _glVertexAttrib2fvARB_Exec @ 0xadb90 (148 bytes) */
int _glVertexAttrib2fvARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  float *param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  int iVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 < 0x10) {
    uVar1 = *(undefined4 *)(param_1 + 0x20);
    uVar2 = *(undefined4 *)(param_1 + 0x24);
    if (param_2 != 0) {
      iVar4 = param_1 + param_2 * 0x10;
      *(float *)(iVar4 + 0x1a0) = *param_3;
      fVar3 = param_3[1];
      *(undefined4 *)(iVar4 + 0x1ac) = uVar2;
      *(float *)(iVar4 + 0x1a4) = fVar3;
      *(undefined4 *)(iVar4 + 0x1a8) = uVar1;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(double,double))UNRECOVERED_JUMPTABLE))((double)*param_3, (double)param_3[1]);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib2fvARB_Comp @ 0xadc24 (96 bytes) */
int _glVertexAttrib2fvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib2fvARB_ListExec_001104b4,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = *param_3;
    puVar1[2] = param_3[1];
  }
  return puVar1;
}

/* _glVertexAttrib2fvARB_CompExec @ 0xadc84 (64 bytes) */
int _glVertexAttrib2fvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib2fvARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glVertexAttrib2fvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib2fvARB_ListExec @ 0xadcc4 (48 bytes) */
int _glVertexAttrib2fvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glVertexAttrib2fvARB_Exec)(param_1,*param_2,param_2 + 1);
  return 0xc;
}

/* _glVertexAttrib2dvARB_Exec @ 0xadcf4 (164 bytes) */
int _glVertexAttrib2dvARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  double *param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  double dVar4;
  
  if (param_2 < 0x10) {
    uVar1 = *(undefined4 *)(param_1 + 0x20);
    uVar2 = *(undefined4 *)(param_1 + 0x24);
    if (param_2 != 0) {
      iVar3 = param_1 + param_2 * 0x10;
      *(float *)(iVar3 + 0x1a0) = GH_U2F((unsigned int)(*param_3));
      dVar4 = param_3[1];
      *(undefined4 *)(iVar3 + 0x1ac) = uVar2;
      *(undefined4 *)(iVar3 + 0x1a8) = uVar1;
      *(float *)(iVar3 + 0x1a4) = (float)dVar4;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(double,double))UNRECOVERED_JUMPTABLE))((double)GH_U2F((unsigned int)(*param_3)), (double)GH_U2F((unsigned int)(param_3[1])));
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib2dvARB_Comp @ 0xadd98 (96 bytes) */
int _glVertexAttrib2dvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined8 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib2dvARB_ListExec_001104b0,0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined8 *)(puVar1 + 1) = *param_3;
    *(undefined8 *)(puVar1 + 3) = param_3[1];
  }
  return puVar1;
}

/* _glVertexAttrib2dvARB_CompExec @ 0xaddf8 (64 bytes) */
int _glVertexAttrib2dvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib2dvARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glVertexAttrib2dvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib2dvARB_ListExec @ 0xade38 (48 bytes) */
int _glVertexAttrib2dvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glVertexAttrib2dvARB_Exec)(param_1,*param_2,param_2 + 1);
  return 0x14;
}

/* _glVertexAttrib3svARB_Exec @ 0xade68 (340 bytes) */
int _glVertexAttrib3svARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  short *param_3;
{
  undefined4 uVar1;
  short sVar2;
  double dVar3;
  int iVar4;
  code *pcVar5;
  
  dVar3 = DOUBLE_00108d58;
  if (param_2 < 0x10) {
    uVar1 = *(undefined4 *)(param_1 + 0x24);
    if (param_2 == 0) {
      pcVar5 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar5 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*((int (*)(double,double,double))pcVar5))((double)(float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58), (double)(float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - DOUBLE_00108d58), (double)(float)((double)CONCAT44(0x43300000,(int)param_3[2] ^ 0x80000000) - DOUBLE_00108d58));
    }
    else {
      iVar4 = param_1 + param_2 * 0x10;
      *(float *)(iVar4 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(iVar4 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - dVar3);
      sVar2 = param_3[2];
      *(undefined4 *)(iVar4 + 0x1ac) = uVar1;
      *(float *)(iVar4 + 0x1a8) =
           (float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - dVar3);
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib3svARB_Comp @ 0xadfbc (108 bytes) */
int _glVertexAttrib3svARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined2 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib3svARB_ListExec_001104ac,10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined2 *)(puVar1 + 1) = *param_3;
    *(undefined2 *)((int)puVar1 + 6) = param_3[1];
    *(undefined2 *)(puVar1 + 2) = param_3[2];
  }
  return puVar1;
}

/* _glVertexAttrib3svARB_CompExec @ 0xae028 (64 bytes) */
int _glVertexAttrib3svARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib3svARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glVertexAttrib3svARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib3svARB_ListExec @ 0xae068 (48 bytes) */
int _glVertexAttrib3svARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glVertexAttrib3svARB_Exec)(param_1,*param_2,param_2 + 1);
  return 10;
}

/* _glVertexAttrib3fvARB_Exec @ 0xae098 (152 bytes) */
int _glVertexAttrib3fvARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  float *param_3;
{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 < 0x10) {
    uVar1 = *(undefined4 *)(param_1 + 0x24);
    if (param_2 != 0) {
      iVar3 = param_1 + param_2 * 0x10;
      *(float *)(iVar3 + 0x1a0) = *param_3;
      *(float *)(iVar3 + 0x1a4) = param_3[1];
      fVar2 = param_3[2];
      *(undefined4 *)(iVar3 + 0x1ac) = uVar1;
      *(float *)(iVar3 + 0x1a8) = fVar2;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(double,double,double))UNRECOVERED_JUMPTABLE))((double)*param_3, (double)param_3[1], (double)param_3[2]);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib3fvARB_Comp @ 0xae130 (108 bytes) */
int _glVertexAttrib3fvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib3fvARB_ListExec_001104a8,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = *param_3;
    puVar1[2] = param_3[1];
    puVar1[3] = param_3[2];
  }
  return puVar1;
}

/* _glVertexAttrib3fvARB_CompExec @ 0xae19c (64 bytes) */
int _glVertexAttrib3fvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib3fvARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glVertexAttrib3fvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib3fvARB_ListExec @ 0xae1dc (48 bytes) */
int _glVertexAttrib3fvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glVertexAttrib3fvARB_Exec)(param_1,*param_2,param_2 + 1);
  return 0x10;
}

/* _glVertexAttrib3dvARB_Exec @ 0xae20c (176 bytes) */
int _glVertexAttrib3dvARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  double *param_3;
{
  undefined4 uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  double dVar3;
  
  if (param_2 < 0x10) {
    uVar1 = *(undefined4 *)(param_1 + 0x24);
    if (param_2 != 0) {
      iVar2 = param_1 + param_2 * 0x10;
      *(float *)(iVar2 + 0x1a0) = GH_U2F((unsigned int)(*param_3));
      *(float *)(iVar2 + 0x1a4) = GH_U2F((unsigned int)(param_3[1]));
      dVar3 = param_3[2];
      *(undefined4 *)(iVar2 + 0x1ac) = uVar1;
      *(float *)(iVar2 + 0x1a8) = (float)dVar3;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(double,double,double))UNRECOVERED_JUMPTABLE))
              ((double)GH_U2F((unsigned int)(*param_3)), (double)GH_U2F((unsigned int)(param_3[1])), (double)GH_U2F((unsigned int)(param_3[2])));
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib3dvARB_Comp @ 0xae2bc (108 bytes) */
int _glVertexAttrib3dvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined8 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib3dvARB_ListExec_001104a4,0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined8 *)(puVar1 + 1) = *param_3;
    *(undefined8 *)(puVar1 + 3) = param_3[1];
    *(undefined8 *)(puVar1 + 5) = param_3[2];
  }
  return puVar1;
}

/* _glVertexAttrib3dvARB_CompExec @ 0xae328 (64 bytes) */
int _glVertexAttrib3dvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib3dvARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glVertexAttrib3dvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib3dvARB_ListExec @ 0xae368 (48 bytes) */
int _glVertexAttrib3dvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glVertexAttrib3dvARB_Exec)(param_1,*param_2,param_2 + 1);
  return 0x1c;
}

/* _glVertexAttrib4bvARB_Exec @ 0xae398 (420 bytes) */
int _glVertexAttrib4bvARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  char *param_3;
{
  double dVar1;
  int iVar2;
  code *pcVar3;
  
  dVar1 = DOUBLE_00108d58;
  if (param_2 < 0x10) {
    if (param_2 == 0) {
      pcVar3 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*((int (*)(double,double,double,double))pcVar3))((double)(float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58), (double)(float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - DOUBLE_00108d58), (double)(float)((double)CONCAT44(0x43300000,(int)param_3[2] ^ 0x80000000) - DOUBLE_00108d58), (double)(float)((double)CONCAT44(0x43300000,(int)param_3[3] ^ 0x80000000) - DOUBLE_00108d58));
    }
    else {
      iVar2 = param_1 + param_2 * 0x10;
      *(float *)(iVar2 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(iVar2 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - dVar1);
      *(float *)(iVar2 + 0x1a8) =
           (float)((double)CONCAT44(0x43300000,(int)param_3[2] ^ 0x80000000) - dVar1);
      *(float *)(iVar2 + 0x1ac) =
           (float)((double)CONCAT44(0x43300000,(int)param_3[3] ^ 0x80000000) - dVar1);
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4bvARB_Comp @ 0xae53c (116 bytes) */
int _glVertexAttrib4bvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined1 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4bvARB_ListExec_00110490,8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined1 *)(puVar1 + 1) = *param_3;
    *(undefined1 *)((int)puVar1 + 5) = param_3[1];
    *(undefined1 *)((int)puVar1 + 6) = param_3[2];
    *(undefined1 *)((int)puVar1 + 7) = param_3[3];
  }
  return puVar1;
}

/* _glVertexAttrib4bvARB_CompExec @ 0xae5b0 (64 bytes) */
int _glVertexAttrib4bvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib4bvARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glVertexAttrib4bvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib4bvARB_ListExec @ 0xae5f0 (48 bytes) */
int _glVertexAttrib4bvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glVertexAttrib4bvARB_Exec)(param_1,*param_2,param_2 + 1);
  return 8;
}

/* _glVertexAttrib4svARB_Exec @ 0xae620 (388 bytes) */
int _glVertexAttrib4svARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  short *param_3;
{
  double dVar1;
  int iVar2;
  code *pcVar3;
  
  dVar1 = DOUBLE_00108d58;
  if (param_2 < 0x10) {
    if (param_2 == 0) {
      pcVar3 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*((int (*)(double,double,double,double))pcVar3))((double)(float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58), (double)(float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - DOUBLE_00108d58), (double)(float)((double)CONCAT44(0x43300000,(int)param_3[2] ^ 0x80000000) - DOUBLE_00108d58), (double)(float)((double)CONCAT44(0x43300000,(int)param_3[3] ^ 0x80000000) - DOUBLE_00108d58));
    }
    else {
      iVar2 = param_1 + param_2 * 0x10;
      *(float *)(iVar2 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(iVar2 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - dVar1);
      *(float *)(iVar2 + 0x1a8) =
           (float)((double)CONCAT44(0x43300000,(int)param_3[2] ^ 0x80000000) - dVar1);
      *(float *)(iVar2 + 0x1ac) =
           (float)((double)CONCAT44(0x43300000,(int)param_3[3] ^ 0x80000000) - dVar1);
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4svARB_Comp @ 0xae7a4 (116 bytes) */
int _glVertexAttrib4svARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined2 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4svARB_ListExec_001104a0,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined2 *)(puVar1 + 1) = *param_3;
    *(undefined2 *)((int)puVar1 + 6) = param_3[1];
    *(undefined2 *)(puVar1 + 2) = param_3[2];
    *(undefined2 *)((int)puVar1 + 10) = param_3[3];
  }
  return puVar1;
}

/* _glVertexAttrib4svARB_CompExec @ 0xae818 (64 bytes) */
int _glVertexAttrib4svARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib4svARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glVertexAttrib4svARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib4svARB_ListExec @ 0xae858 (48 bytes) */
int _glVertexAttrib4svARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glVertexAttrib4svARB_Exec)(param_1,*param_2,param_2 + 1);
  return 0xc;
}

/* _glVertexAttrib4ivARB_Exec @ 0xae888 (388 bytes) */
int _glVertexAttrib4ivARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  double dVar1;
  int iVar2;
  code *pcVar3;
  
  dVar1 = DOUBLE_00108d58;
  if (param_2 < 0x10) {
    if (param_2 == 0) {
      pcVar3 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*((int (*)(double,double,double,double))pcVar3))((double)(float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58 ), (double)(float)((double)CONCAT44(0x43300000,param_3[1] ^ 0x80000000) - DOUBLE_00108d58), (double)(float)((double)CONCAT44(0x43300000,param_3[2] ^ 0x80000000) - DOUBLE_00108d58), (double)(float)((double)CONCAT44(0x43300000,param_3[3] ^ 0x80000000) - DOUBLE_00108d58));
    }
    else {
      iVar2 = param_1 + param_2 * 0x10;
      *(float *)(iVar2 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(iVar2 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,param_3[1] ^ 0x80000000) - dVar1);
      *(float *)(iVar2 + 0x1a8) =
           (float)((double)CONCAT44(0x43300000,param_3[2] ^ 0x80000000) - dVar1);
      *(float *)(iVar2 + 0x1ac) =
           (float)((double)CONCAT44(0x43300000,param_3[3] ^ 0x80000000) - dVar1);
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4ivARB_Comp @ 0xaea0c (116 bytes) */
int _glVertexAttrib4ivARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4ivARB_ListExec_0011048c,0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = *param_3;
    puVar1[2] = param_3[1];
    puVar1[3] = param_3[2];
    puVar1[4] = param_3[3];
  }
  return puVar1;
}

/* _glVertexAttrib4ivARB_CompExec @ 0xaea80 (64 bytes) */
int _glVertexAttrib4ivARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib4ivARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glVertexAttrib4ivARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib4ivARB_ListExec @ 0xaeac0 (48 bytes) */
int _glVertexAttrib4ivARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glVertexAttrib4ivARB_Exec)(param_1,*param_2,param_2 + 1);
  return 0x14;
}

/* _glVertexAttrib4ubvARB_Exec @ 0xaeaf0 (384 bytes) */
double _glVertexAttrib4ubvARB_Exec(int param_1,uint param_2,byte *param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  int iVar1;
  code *pcVar2;
  
  if (param_2 < 0x10) {
    if (param_2 == 0) {
      pcVar2 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar2 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      fparam_1 = (double)(*((double (*)(double,double,double,double))pcVar2))((double)(GH_U2F((unsigned int)((*param_3 | 0x4b000000))) - 8388608.0), (double)(GH_U2F((unsigned int)((param_3[1] | 0x4b000000))) - 8388608.0), (double)(GH_U2F((unsigned int)((param_3[2] | 0x4b000000))) - 8388608.0), (double)(GH_U2F((unsigned int)((param_3[3] | 0x4b000000))) - 8388608.0));
    }
    else {
      iVar1 = param_1 + param_2 * 0x10;
      *(float *)(iVar1 + 0x1a0) = GH_U2F((unsigned int)((*param_3 | 0x4b000000))) - 8388608.0;
      *(float *)(iVar1 + 0x1a4) = GH_U2F((unsigned int)((param_3[1] | 0x4b000000))) - 8388608.0;
      *(float *)(iVar1 + 0x1a8) = GH_U2F((unsigned int)((param_3[2] | 0x4b000000))) - 8388608.0;
      *(float *)(iVar1 + 0x1ac) = GH_U2F((unsigned int)((param_3[3] | 0x4b000000))) - 8388608.0;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return fparam_1;
}

/* _glVertexAttrib4ubvARB_Comp @ 0xaec70 (116 bytes) */
int _glVertexAttrib4ubvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined1 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4ubvARB_ListExec_00110488,8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined1 *)(puVar1 + 1) = *param_3;
    *(undefined1 *)((int)puVar1 + 5) = param_3[1];
    *(undefined1 *)((int)puVar1 + 6) = param_3[2];
    *(undefined1 *)((int)puVar1 + 7) = param_3[3];
  }
  return puVar1;
}

/* _glVertexAttrib4ubvARB_CompExec @ 0xaece4 (64 bytes) */
int _glVertexAttrib4ubvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  
  ((int (*)())_glVertexAttrib4ubvARB_Comp)(param_1,param_2,param_3);
  ((double (*)())_glVertexAttrib4ubvARB_Exec)(param_1,param_2,param_3,fparam_1,in_f2,in_f3,in_f4);
  return;
}

/* _glVertexAttrib4ubvARB_ListExec @ 0xaed24 (48 bytes) */
undefined4 _glVertexAttrib4ubvARB_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((double (*)())_glVertexAttrib4ubvARB_Exec)(param_1,*param_2,param_2 + 1,fparam_1,fparam_2,fparam_3,fparam_4);
  return 8;
}

/* _glVertexAttrib4usvARB_Exec @ 0xaed54 (384 bytes) */
double _glVertexAttrib4usvARB_Exec(int param_1,uint param_2,ushort *param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  int iVar1;
  code *pcVar2;
  
  if (param_2 < 0x10) {
    if (param_2 == 0) {
      pcVar2 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar2 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      fparam_1 = (double)(*((double (*)(double,double,double,double))pcVar2))((double)(GH_U2F((unsigned int)((*param_3 | 0x4b000000))) - 8388608.0), (double)(GH_U2F((unsigned int)((param_3[1] | 0x4b000000))) - 8388608.0), (double)(GH_U2F((unsigned int)((param_3[2] | 0x4b000000))) - 8388608.0), (double)(GH_U2F((unsigned int)((param_3[3] | 0x4b000000))) - 8388608.0));
    }
    else {
      iVar1 = param_1 + param_2 * 0x10;
      *(float *)(iVar1 + 0x1a0) = GH_U2F((unsigned int)((*param_3 | 0x4b000000))) - 8388608.0;
      *(float *)(iVar1 + 0x1a4) = GH_U2F((unsigned int)((param_3[1] | 0x4b000000))) - 8388608.0;
      *(float *)(iVar1 + 0x1a8) = GH_U2F((unsigned int)((param_3[2] | 0x4b000000))) - 8388608.0;
      *(float *)(iVar1 + 0x1ac) = GH_U2F((unsigned int)((param_3[3] | 0x4b000000))) - 8388608.0;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return fparam_1;
}

/* _glVertexAttrib4usvARB_Comp @ 0xaeed4 (116 bytes) */
int _glVertexAttrib4usvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined2 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4usvARB_ListExec_00110484,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined2 *)(puVar1 + 1) = *param_3;
    *(undefined2 *)((int)puVar1 + 6) = param_3[1];
    *(undefined2 *)(puVar1 + 2) = param_3[2];
    *(undefined2 *)((int)puVar1 + 10) = param_3[3];
  }
  return puVar1;
}

/* _glVertexAttrib4usvARB_CompExec @ 0xaef48 (64 bytes) */
int _glVertexAttrib4usvARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  
  ((int (*)())_glVertexAttrib4usvARB_Comp)(param_1,param_2,param_3);
  ((double (*)())_glVertexAttrib4usvARB_Exec)(param_1,param_2,param_3,fparam_1,in_f2,in_f3,in_f4);
  return;
}

/* _glVertexAttrib4usvARB_ListExec @ 0xaef88 (48 bytes) */
undefined4 _glVertexAttrib4usvARB_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((double (*)())_glVertexAttrib4usvARB_Exec)(param_1,*param_2,param_2 + 1,fparam_1,fparam_2,fparam_3,fparam_4);
  return 0xc;
}

/* _glVertexAttrib4uivARB_Exec @ 0xaefb8 (356 bytes) */
int _glVertexAttrib4uivARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 *param_3;
{
  double dVar1;
  int iVar2;
  code *pcVar3;
  
  dVar1 = DOUBLE_00108d70;
  if (param_2 < 0x10) {
    if (param_2 == 0) {
      pcVar3 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*((int (*)(double,double,double,double))pcVar3))((double)(float)((double)CONCAT44(0x43300000,*param_3) - DOUBLE_00108d70), (double)(float)((double)CONCAT44(0x43300000,param_3[1]) - DOUBLE_00108d70), (double)(float)((double)CONCAT44(0x43300000,param_3[2]) - DOUBLE_00108d70), (double)(float)((double)CONCAT44(0x43300000,param_3[3]) - DOUBLE_00108d70));
    }
    else {
      iVar2 = param_1 + param_2 * 0x10;
      *(float *)(iVar2 + 0x1a0) = (float)((double)CONCAT44(0x43300000,*param_3) - DOUBLE_00108d70);
      *(float *)(iVar2 + 0x1a4) = (float)((double)CONCAT44(0x43300000,param_3[1]) - dVar1);
      *(float *)(iVar2 + 0x1a8) = (float)((double)CONCAT44(0x43300000,param_3[2]) - dVar1);
      *(float *)(iVar2 + 0x1ac) = (float)((double)CONCAT44(0x43300000,param_3[3]) - dVar1);
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4uivARB_Comp @ 0xaf11c (116 bytes) */
int _glVertexAttrib4uivARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4uivARB_ListExec_00110480,0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = *param_3;
    puVar1[2] = param_3[1];
    puVar1[3] = param_3[2];
    puVar1[4] = param_3[3];
  }
  return puVar1;
}

/* _glVertexAttrib4uivARB_CompExec @ 0xaf190 (64 bytes) */
int _glVertexAttrib4uivARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib4uivARB_Comp)(param_1,param_2,param_3);
  ((int (*)())_glVertexAttrib4uivARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib4uivARB_ListExec @ 0xaf1d0 (48 bytes) */
int _glVertexAttrib4uivARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glVertexAttrib4uivARB_Exec)(param_1,*param_2,param_2 + 1);
  return 0x14;
}

/* _glVertexAttrib4fvARB_Exec @ 0xaf200 (156 bytes) */
int _glVertexAttrib4fvARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  float *param_3;
{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 < 0x10) {
    if (param_2 != 0) {
      iVar1 = param_1 + param_2 * 0x10;
      *(float *)(iVar1 + 0x1a0) = *param_3;
      *(float *)(iVar1 + 0x1a4) = param_3[1];
      *(float *)(iVar1 + 0x1a8) = param_3[2];
      *(float *)(iVar1 + 0x1ac) = param_3[3];
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(double,double,double,double))UNRECOVERED_JUMPTABLE))
              ((double)*param_3, (double)param_3[1], (double)param_3[2], (double)param_3[3]);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib4fvARB_Comp @ 0xaf29c (116 bytes) */
int _glVertexAttrib4fvARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4fvARB_ListExec_0011049c,0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = *param_3;
    puVar1[2] = param_3[1];
    puVar1[3] = param_3[2];
    puVar1[4] = param_3[3];
  }
  return puVar1;
}

