#include "decls.h"

/* _glVertexAttrib1svARB_CompExec @ 0xad674 (64 bytes) */
void _glVertexAttrib1svARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  _glVertexAttrib1svARB_Comp(glContext,index,v);
  _glVertexAttrib1svARB_Exec(glContext,index,v);
  return;
}

/* _glVertexAttrib1svARB_ListExec @ 0xad6b4 (48 bytes) */
int _glVertexAttrib1svARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glVertexAttrib1svARB_Exec(glContext,*listRecord,listRecord + 1);
  return 6;
}

/* _glVertexAttrib1fvARB_Exec @ 0xad6e4 (144 bytes) */
double _glVertexAttrib1fvARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  float *v;
{
  float defaultZero;
  float defaultOne;
  int attribSlotBase;
  code *UNRECOVERED_JUMPTABLE;
  
  if (index < 0x10) {
    defaultZero = *(float *)(glContext + 0x20);
    defaultOne = *(float *)(glContext + 0x24);
    if (index != 0) {
      attribSlotBase = glContext + index * 0x10;
      *(float *)(attribSlotBase + 0x1a0) = *v;
      *(float *)(attribSlotBase + 0x1ac) = defaultOne;
      *(float *)(attribSlotBase + 0x1a8) = defaultZero;
      *(float *)(attribSlotBase + 0x1a4) = defaultZero;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*UNRECOVERED_JUMPTABLE)
              (glContext,0,v,(double)*v,(double)defaultZero,(double)defaultZero,(double)defaultOne);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib1fvARB_Comp @ 0xad774 (88 bytes) */
int _glVertexAttrib1fvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib1fvARB_ListExec_001104c0,8);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    listRecord[1] = *v;
  }
  return listRecord;
}

/* _glVertexAttrib1fvARB_CompExec @ 0xad7cc (64 bytes) */
void _glVertexAttrib1fvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib1fvARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib1fvARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib1fvARB_ListExec @ 0xad80c (48 bytes) */
int _glVertexAttrib1fvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib1fvARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 8;
}

/* _glVertexAttrib1dvARB_Exec @ 0xad83c (152 bytes) */
double _glVertexAttrib1dvARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  double *v;
{
  float defaultZero;
  int attribSlotBase;
  code *UNRECOVERED_JUMPTABLE;
  double xDouble;
  
  if (index < 0x10) {
    defaultZero = *(float *)(glContext + 0x20);
    if (index != 0) {
      xDouble = *v;
      attribSlotBase = glContext + index * 0x10;
      *(float *)(attribSlotBase + 0x1ac) = *(float *)(glContext + 0x24);
      *(float *)(attribSlotBase + 0x1a8) = defaultZero;
      *(float *)(attribSlotBase + 0x1a0) = (float)xDouble;
      *(float *)(attribSlotBase + 0x1a4) = defaultZero;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*UNRECOVERED_JUMPTABLE)
              (glContext,0,v,(double)(float)*v,(double)defaultZero,(double)defaultZero,
               (double)*(float *)(glContext + 0x24));
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib1dvARB_Comp @ 0xad8d4 (88 bytes) */
int _glVertexAttrib1dvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined8 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib1dvARB_ListExec_001104bc,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined8 *)(listRecord + 1) = *v;
  }
  return listRecord;
}

/* _glVertexAttrib1dvARB_CompExec @ 0xad92c (64 bytes) */
void _glVertexAttrib1dvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib1dvARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib1dvARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib1dvARB_ListExec @ 0xad96c (48 bytes) */
int _glVertexAttrib1dvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib1dvARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 0xc;
}

/* _glVertexAttrib2svARB_Exec @ 0xad99c (292 bytes) */
double _glVertexAttrib2svARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  short *v;
{
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar3;
  double intToDoubleBias;
  int iVar5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  code *pcVar6;
  
  intToDoubleBias = DOUBLE_00108d58;
  if (index < 0x10) {
    uVar1 = *(undefined4 *)(glContext + 0x20);
    uVar2 = *(undefined4 *)(glContext + 0x24);
    if (index == 0) {
      pcVar6 = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        pcVar6 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar6)(glContext,0,v,incomingR6,incomingR7,*(int *)(glContext + 0x4858),0x43300000,
                (double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                               DOUBLE_00108d58),
                (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                               DOUBLE_00108d58));
    }
    else {
      iVar5 = glContext + index * 0x10;
      *(float *)(iVar5 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58);
      sVar3 = v[1];
      *(undefined4 *)(iVar5 + 0x1ac) = uVar2;
      *(undefined4 *)(iVar5 + 0x1a8) = uVar1;
      *(float *)(iVar5 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) - intToDoubleBias);
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib2svARB_Comp @ 0xadac0 (96 bytes) */
int _glVertexAttrib2svARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined2 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib2svARB_ListExec_001104b8,8);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined2 *)(listRecord + 1) = *v;
    *(undefined2 *)((int)listRecord + 6) = v[1];
  }
  return listRecord;
}

/* _glVertexAttrib2svARB_CompExec @ 0xadb20 (64 bytes) */
void _glVertexAttrib2svARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib2svARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib2svARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib2svARB_ListExec @ 0xadb60 (48 bytes) */
int _glVertexAttrib2svARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib2svARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 8;
}

/* _glVertexAttrib2fvARB_Exec @ 0xadb90 (148 bytes) */
double _glVertexAttrib2fvARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  float *v;
{
  float defaultZero;
  float defaultOne;
  float yValue;
  int attribSlotBase;
  code *UNRECOVERED_JUMPTABLE;
  
  if (index < 0x10) {
    defaultZero = *(float *)(glContext + 0x20);
    defaultOne = *(float *)(glContext + 0x24);
    if (index != 0) {
      attribSlotBase = glContext + index * 0x10;
      *(float *)(attribSlotBase + 0x1a0) = *v;
      yValue = v[1];
      *(float *)(attribSlotBase + 0x1ac) = defaultOne;
      *(float *)(attribSlotBase + 0x1a4) = yValue;
      *(float *)(attribSlotBase + 0x1a8) = defaultZero;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*UNRECOVERED_JUMPTABLE)
              (glContext,0,v,(double)*v,(double)v[1],(double)defaultZero,(double)defaultOne);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib2fvARB_Comp @ 0xadc24 (96 bytes) */
int _glVertexAttrib2fvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib2fvARB_ListExec_001104b4,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    listRecord[1] = *v;
    listRecord[2] = v[1];
  }
  return listRecord;
}

/* _glVertexAttrib2fvARB_CompExec @ 0xadc84 (64 bytes) */
void _glVertexAttrib2fvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib2fvARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib2fvARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib2fvARB_ListExec @ 0xadcc4 (48 bytes) */
int _glVertexAttrib2fvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib2fvARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 0xc;
}

/* _glVertexAttrib2dvARB_Exec @ 0xadcf4 (164 bytes) */
double _glVertexAttrib2dvARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  double *v;
{
  float fVar1;
  float fVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  double dVar4;
  
  if (index < 0x10) {
    fVar1 = *(float *)(glContext + 0x20);
    fVar2 = *(float *)(glContext + 0x24);
    if (index != 0) {
      iVar3 = glContext + index * 0x10;
      *(float *)(iVar3 + 0x1a0) = (float)*v;
      dVar4 = v[1];
      *(float *)(iVar3 + 0x1ac) = fVar2;
      *(float *)(iVar3 + 0x1a8) = fVar1;
      *(float *)(iVar3 + 0x1a4) = (float)dVar4;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*UNRECOVERED_JUMPTABLE)
              (glContext,0,v,(double)(float)*v,(double)(float)v[1],(double)fVar1,
               (double)fVar2);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib2dvARB_Comp @ 0xadd98 (96 bytes) */
int _glVertexAttrib2dvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined8 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib2dvARB_ListExec_001104b0,0x14);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined8 *)(listRecord + 1) = *v;
    *(undefined8 *)(listRecord + 3) = v[1];
  }
  return listRecord;
}

/* _glVertexAttrib2dvARB_CompExec @ 0xaddf8 (64 bytes) */
void _glVertexAttrib2dvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib2dvARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib2dvARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib2dvARB_ListExec @ 0xade38 (48 bytes) */
int _glVertexAttrib2dvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib2dvARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 0x14;
}

/* _glVertexAttrib3svARB_Exec @ 0xade68 (340 bytes) */
double _glVertexAttrib3svARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  short *v;
{
  undefined4 uVar1;
  short sVar2;
  double intToDoubleBias;
  int iVar4;
  undefined4 incomingR6;
  undefined4 incomingR7;
  code *pcVar5;
  
  intToDoubleBias = DOUBLE_00108d58;
  if (index < 0x10) {
    uVar1 = *(undefined4 *)(glContext + 0x24);
    if (index == 0) {
      pcVar5 = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        pcVar5 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar5)(glContext,0,v,incomingR6,incomingR7,*(int *)(glContext + 0x4858),
                (int)v[1] ^ 0x80000000U,
                (double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                               DOUBLE_00108d58),
                (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000U) -
                               DOUBLE_00108d58),
                (double)(float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) -
                               DOUBLE_00108d58));
    }
    else {
      iVar4 = glContext + index * 0x10;
      *(float *)(iVar4 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(iVar4 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleBias);
      sVar2 = v[2];
      *(undefined4 *)(iVar4 + 0x1ac) = uVar1;
      *(float *)(iVar4 + 0x1a8) =
           (float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - intToDoubleBias);
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib3svARB_Comp @ 0xadfbc (108 bytes) */
int _glVertexAttrib3svARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined2 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib3svARB_ListExec_001104ac,10);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined2 *)(listRecord + 1) = *v;
    *(undefined2 *)((int)listRecord + 6) = v[1];
    *(undefined2 *)(listRecord + 2) = v[2];
  }
  return listRecord;
}

/* _glVertexAttrib3svARB_CompExec @ 0xae028 (64 bytes) */
void _glVertexAttrib3svARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib3svARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib3svARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib3svARB_ListExec @ 0xae068 (48 bytes) */
int _glVertexAttrib3svARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib3svARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 10;
}

/* _glVertexAttrib3fvARB_Exec @ 0xae098 (152 bytes) */
double _glVertexAttrib3fvARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  float *v;
{
  float defaultOne;
  float zValue;
  int attribSlotBase;
  code *UNRECOVERED_JUMPTABLE;
  
  if (index < 0x10) {
    defaultOne = *(float *)(glContext + 0x24);
    if (index != 0) {
      attribSlotBase = glContext + index * 0x10;
      *(float *)(attribSlotBase + 0x1a0) = *v;
      *(float *)(attribSlotBase + 0x1a4) = v[1];
      zValue = v[2];
      *(float *)(attribSlotBase + 0x1ac) = defaultOne;
      *(float *)(attribSlotBase + 0x1a8) = zValue;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*UNRECOVERED_JUMPTABLE)
              (glContext,0,v,(double)*v,(double)v[1],(double)v[2],
               (double)defaultOne);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib3fvARB_Comp @ 0xae130 (108 bytes) */
int _glVertexAttrib3fvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib3fvARB_ListExec_001104a8,0x10);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    listRecord[1] = *v;
    listRecord[2] = v[1];
    listRecord[3] = v[2];
  }
  return listRecord;
}

/* _glVertexAttrib3fvARB_CompExec @ 0xae19c (64 bytes) */
void _glVertexAttrib3fvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib3fvARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib3fvARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib3fvARB_ListExec @ 0xae1dc (48 bytes) */
int _glVertexAttrib3fvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib3fvARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 0x10;
}

/* _glVertexAttrib3dvARB_Exec @ 0xae20c (176 bytes) */
double _glVertexAttrib3dvARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  double *v;
{
  float fVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  double dVar3;
  
  if (index < 0x10) {
    fVar1 = *(float *)(glContext + 0x24);
    if (index != 0) {
      iVar2 = glContext + index * 0x10;
      *(float *)(iVar2 + 0x1a0) = (float)*v;
      *(float *)(iVar2 + 0x1a4) = (float)v[1];
      dVar3 = v[2];
      *(float *)(iVar2 + 0x1ac) = fVar1;
      *(float *)(iVar2 + 0x1a8) = (float)dVar3;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*UNRECOVERED_JUMPTABLE)
              (glContext,0,v,(double)(float)*v,(double)(float)v[1],
               (double)(float)v[2],(double)fVar1);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib3dvARB_Comp @ 0xae2bc (108 bytes) */
int _glVertexAttrib3dvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined8 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib3dvARB_ListExec_001104a4,0x1c);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined8 *)(listRecord + 1) = *v;
    *(undefined8 *)(listRecord + 3) = v[1];
    *(undefined8 *)(listRecord + 5) = v[2];
  }
  return listRecord;
}

/* _glVertexAttrib3dvARB_CompExec @ 0xae328 (64 bytes) */
void _glVertexAttrib3dvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib3dvARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib3dvARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib3dvARB_ListExec @ 0xae368 (48 bytes) */
int _glVertexAttrib3dvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib3dvARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 0x1c;
}

/* _glVertexAttrib4bvARB_Exec @ 0xae398 (420 bytes) */
double _glVertexAttrib4bvARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  char *v;
{
  double intToDoubleBias;
  int iVar2;
  undefined4 incomingR6;
  undefined4 incomingR7;
  code *pcVar3;
  
  intToDoubleBias = DOUBLE_00108d58;
  if (index < 0x10) {
    if (index == 0) {
      pcVar3 = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar3)(glContext,0,v,incomingR6,incomingR7,*(int *)(glContext + 0x4858),
                (int)v[2] ^ 0x80000000U,0x43300000,
                (double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                               DOUBLE_00108d58),
                (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                               DOUBLE_00108d58),
                (double)(float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000U) -
                               DOUBLE_00108d58),
                (double)(float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) -
                               DOUBLE_00108d58));
    }
    else {
      iVar2 = glContext + index * 0x10;
      *(float *)(iVar2 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(iVar2 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleBias);
      *(float *)(iVar2 + 0x1a8) =
           (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleBias);
      *(float *)(iVar2 + 0x1ac) =
           (float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) - intToDoubleBias);
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4bvARB_Comp @ 0xae53c (116 bytes) */
int _glVertexAttrib4bvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined1 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4bvARB_ListExec_00110490,8);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined1 *)(listRecord + 1) = *v;
    *(undefined1 *)((int)listRecord + 5) = v[1];
    *(undefined1 *)((int)listRecord + 6) = v[2];
    *(undefined1 *)((int)listRecord + 7) = v[3];
  }
  return listRecord;
}

/* _glVertexAttrib4bvARB_CompExec @ 0xae5b0 (64 bytes) */
void _glVertexAttrib4bvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib4bvARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib4bvARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib4bvARB_ListExec @ 0xae5f0 (48 bytes) */
int _glVertexAttrib4bvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib4bvARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 8;
}

/* _glVertexAttrib4svARB_Exec @ 0xae620 (388 bytes) */
double _glVertexAttrib4svARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  short *v;
{
  double intToDoubleBias;
  int iVar2;
  undefined4 incomingR6;
  undefined4 incomingR7;
  code *pcVar3;
  
  intToDoubleBias = DOUBLE_00108d58;
  if (index < 0x10) {
    if (index == 0) {
      pcVar3 = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar3)(glContext,0,v,incomingR6,incomingR7,*(int *)(glContext + 0x4858),
                (int)v[2] ^ 0x80000000U,
                (double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                               DOUBLE_00108d58),
                (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                               DOUBLE_00108d58),
                (double)(float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000U) -
                               DOUBLE_00108d58),
                (double)(float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) -
                               DOUBLE_00108d58));
    }
    else {
      iVar2 = glContext + index * 0x10;
      *(float *)(iVar2 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(iVar2 + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleBias);
      *(float *)(iVar2 + 0x1a8) =
           (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleBias);
      *(float *)(iVar2 + 0x1ac) =
           (float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) - intToDoubleBias);
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4svARB_Comp @ 0xae7a4 (116 bytes) */
int _glVertexAttrib4svARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined2 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4svARB_ListExec_001104a0,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined2 *)(listRecord + 1) = *v;
    *(undefined2 *)((int)listRecord + 6) = v[1];
    *(undefined2 *)(listRecord + 2) = v[2];
    *(undefined2 *)((int)listRecord + 10) = v[3];
  }
  return listRecord;
}

/* _glVertexAttrib4svARB_CompExec @ 0xae818 (64 bytes) */
void _glVertexAttrib4svARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib4svARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib4svARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib4svARB_ListExec @ 0xae858 (48 bytes) */
int _glVertexAttrib4svARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib4svARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 0xc;
}

/* _glVertexAttrib4ivARB_Exec @ 0xae888 (388 bytes) */
double _glVertexAttrib4ivARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  uint *v;
{
  double intToDoubleBias;
  int attribSlotBase;
  undefined4 incomingR6;
  undefined4 incomingR7;
  code *vertexFunc;
  
  intToDoubleBias = DOUBLE_00108d58;
  if (index < 0x10) {
    if (index == 0) {
      vertexFunc = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        vertexFunc = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*vertexFunc)(glContext,0,v,incomingR6,incomingR7,*(int *)(glContext + 0x4858),v[2] ^ 0x80000000,
                (double)(float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58
                               ),
                (double)(float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) -
                               DOUBLE_00108d58),
                (double)(float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) -
                               DOUBLE_00108d58),
                (double)(float)((double)CONCAT44(0x43300000,v[3] ^ 0x80000000) -
                               DOUBLE_00108d58));
    }
    else {
      attribSlotBase = glContext + index * 0x10;
      *(float *)(attribSlotBase + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(attribSlotBase + 0x1a4) =
           (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - intToDoubleBias);
      *(float *)(attribSlotBase + 0x1a8) =
           (float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - intToDoubleBias);
      *(float *)(attribSlotBase + 0x1ac) =
           (float)((double)CONCAT44(0x43300000,v[3] ^ 0x80000000) - intToDoubleBias);
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4ivARB_Comp @ 0xaea0c (116 bytes) */
int _glVertexAttrib4ivARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4ivARB_ListExec_0011048c,0x14);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    listRecord[1] = *v;
    listRecord[2] = v[1];
    listRecord[3] = v[2];
    listRecord[4] = v[3];
  }
  return listRecord;
}

/* _glVertexAttrib4ivARB_CompExec @ 0xaea80 (64 bytes) */
void _glVertexAttrib4ivARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib4ivARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib4ivARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib4ivARB_ListExec @ 0xaeac0 (48 bytes) */
int _glVertexAttrib4ivARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib4ivARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 0x14;
}

/* _glVertexAttrib4ubvARB_Exec @ 0xaeaf0 (384 bytes) */
double _glVertexAttrib4ubvARB_Exec(int glContext,uint index,byte *v,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4)
{
  int iVar1;
  undefined4 incomingR6;
  code *pcVar2;
  
  if (index < 0x10) {
    if (index == 0) {
      iVar1 = *(int *)(glContext + 0x4858);
      pcVar2 = *(code **)(glContext + 0x4884);
      if (iVar1 == *(int *)(glContext + 0x485c)) {
        pcVar2 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar2)(glContext,0,v,incomingR6,iVar1,iVar1,(uint)v[2],v[1] | 0x4b000000,
                (double)(GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0),
                (double)(GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0),
                (double)(GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0),
                (double)(GH_U2F((unsigned int)((v[3] | 0x4b000000))) - 8388608.0));
    }
    else {
      iVar1 = glContext + index * 0x10;
      *(float *)(iVar1 + 0x1a0) = GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0;
      *(float *)(iVar1 + 0x1a4) = GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0;
      *(float *)(iVar1 + 0x1a8) = GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0;
      *(float *)(iVar1 + 0x1ac) = GH_U2F((unsigned int)((v[3] | 0x4b000000))) - 8388608.0;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4ubvARB_Comp @ 0xaec70 (116 bytes) */
int _glVertexAttrib4ubvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined1 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4ubvARB_ListExec_00110488,8);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined1 *)(listRecord + 1) = *v;
    *(undefined1 *)((int)listRecord + 5) = v[1];
    *(undefined1 *)((int)listRecord + 6) = v[2];
    *(undefined1 *)((int)listRecord + 7) = v[3];
  }
  return listRecord;
}

/* _glVertexAttrib4ubvARB_CompExec @ 0xaece4 (64 bytes) */
void _glVertexAttrib4ubvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  
  ((int (*)())_glVertexAttrib4ubvARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib4ubvARB_Exec)(glContext,index,v,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4);
  return;
}

/* _glVertexAttrib4ubvARB_ListExec @ 0xaed24 (48 bytes) */
undefined4 _glVertexAttrib4ubvARB_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4)
{
  ((double (*)())_glVertexAttrib4ubvARB_Exec)(glContext,*listRecord,listRecord + 1,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4);
  return 8;
}

/* _glVertexAttrib4usvARB_Exec @ 0xaed54 (384 bytes) */
double _glVertexAttrib4usvARB_Exec(int glContext,uint index,ushort *v,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4)
{
  int iVar1;
  undefined4 incomingR6;
  code *pcVar2;
  
  if (index < 0x10) {
    if (index == 0) {
      iVar1 = *(int *)(glContext + 0x4858);
      pcVar2 = *(code **)(glContext + 0x4884);
      if (iVar1 == *(int *)(glContext + 0x485c)) {
        pcVar2 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar2)(glContext,0,v,incomingR6,iVar1,iVar1,(uint)v[2],v[1] | 0x4b000000,
                (double)(GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0),
                (double)(GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0),
                (double)(GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0),
                (double)(GH_U2F((unsigned int)((v[3] | 0x4b000000))) - 8388608.0));
    }
    else {
      iVar1 = glContext + index * 0x10;
      *(float *)(iVar1 + 0x1a0) = GH_U2F((unsigned int)((*v | 0x4b000000))) - 8388608.0;
      *(float *)(iVar1 + 0x1a4) = GH_U2F((unsigned int)((v[1] | 0x4b000000))) - 8388608.0;
      *(float *)(iVar1 + 0x1a8) = GH_U2F((unsigned int)((v[2] | 0x4b000000))) - 8388608.0;
      *(float *)(iVar1 + 0x1ac) = GH_U2F((unsigned int)((v[3] | 0x4b000000))) - 8388608.0;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4usvARB_Comp @ 0xaeed4 (116 bytes) */
int _glVertexAttrib4usvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined2 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4usvARB_ListExec_00110484,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined2 *)(listRecord + 1) = *v;
    *(undefined2 *)((int)listRecord + 6) = v[1];
    *(undefined2 *)(listRecord + 2) = v[2];
    *(undefined2 *)((int)listRecord + 10) = v[3];
  }
  return listRecord;
}

/* _glVertexAttrib4usvARB_CompExec @ 0xaef48 (64 bytes) */
void _glVertexAttrib4usvARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  
  ((int (*)())_glVertexAttrib4usvARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib4usvARB_Exec)(glContext,index,v,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4);
  return;
}

/* _glVertexAttrib4usvARB_ListExec @ 0xaef88 (48 bytes) */
undefined4 _glVertexAttrib4usvARB_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4)
{
  ((double (*)())_glVertexAttrib4usvARB_Exec)(glContext,*listRecord,listRecord + 1,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4);
  return 0xc;
}

/* _glVertexAttrib4uivARB_Exec @ 0xaefb8 (356 bytes) */
double _glVertexAttrib4uivARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  undefined4 *v;
{
  double intToDoubleBias;
  int attribSlotBase;
  undefined4 incomingR6;
  undefined4 incomingR7;
  code *vertexFunc;
  
  intToDoubleBias = DOUBLE_00108d70;
  if (index < 0x10) {
    if (index == 0) {
      vertexFunc = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        vertexFunc = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*vertexFunc)(glContext,0,v,incomingR6,incomingR7,*(int *)(glContext + 0x4858),v[1],
                (double)(float)((double)CONCAT44(0x43300000,*v) - DOUBLE_00108d70),
                (double)(float)((double)CONCAT44(0x43300000,v[1]) - DOUBLE_00108d70),
                (double)(float)((double)CONCAT44(0x43300000,v[2]) - DOUBLE_00108d70),
                (double)(float)((double)CONCAT44(0x43300000,v[3]) - DOUBLE_00108d70));
    }
    else {
      attribSlotBase = glContext + index * 0x10;
      *(float *)(attribSlotBase + 0x1a0) = (float)((double)CONCAT44(0x43300000,*v) - DOUBLE_00108d70);
      *(float *)(attribSlotBase + 0x1a4) = (float)((double)CONCAT44(0x43300000,v[1]) - intToDoubleBias);
      *(float *)(attribSlotBase + 0x1a8) = (float)((double)CONCAT44(0x43300000,v[2]) - intToDoubleBias);
      *(float *)(attribSlotBase + 0x1ac) = (float)((double)CONCAT44(0x43300000,v[3]) - intToDoubleBias);
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4uivARB_Comp @ 0xaf11c (116 bytes) */
int _glVertexAttrib4uivARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4uivARB_ListExec_00110480,0x14);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    listRecord[1] = *v;
    listRecord[2] = v[1];
    listRecord[3] = v[2];
    listRecord[4] = v[3];
  }
  return listRecord;
}

/* _glVertexAttrib4uivARB_CompExec @ 0xaf190 (64 bytes) */
void _glVertexAttrib4uivARB_CompExec(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 v;
{
  ((int (*)())_glVertexAttrib4uivARB_Comp)(glContext,index,v);
  ((double (*)())_glVertexAttrib4uivARB_Exec)(glContext,index,v);
  return;
}

/* _glVertexAttrib4uivARB_ListExec @ 0xaf1d0 (48 bytes) */
int _glVertexAttrib4uivARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((double (*)())_glVertexAttrib4uivARB_Exec)(glContext,*listRecord,listRecord + 1);
  return 0x14;
}

/* _glVertexAttrib4fvARB_Exec @ 0xaf200 (156 bytes) */
double _glVertexAttrib4fvARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  float *v;
{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (index < 0x10) {
    if (index != 0) {
      iVar1 = glContext + index * 0x10;
      *(float *)(iVar1 + 0x1a0) = *v;
      *(float *)(iVar1 + 0x1a4) = v[1];
      *(float *)(iVar1 + 0x1a8) = v[2];
      *(float *)(iVar1 + 0x1ac) = v[3];
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
              (glContext, index, v, (double)*v, (double)v[1], (double)v[2], (double)v[3]);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib4fvARB_Comp @ 0xaf29c (116 bytes) */
int _glVertexAttrib4fvARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4fvARB_ListExec_0011049c,0x14);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    listRecord[1] = *v;
    listRecord[2] = v[1];
    listRecord[3] = v[2];
    listRecord[4] = v[3];
  }
  return listRecord;
}

