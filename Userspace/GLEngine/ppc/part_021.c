#include "decls.h"

/* _glOrtho_ListExec @ 0x793f0 (360 bytes) */
undefined4 _glOrtho_ListExec(int glContext,float *listRecord,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  float translateY;
  float translateX;
  float column0W;
  float translateZ;
  float scaleX;
  float scaleZ;
  float scaleY;
  float *currentMatrix;
  
  currentMatrix = *(float **)(glContext + 0x4fec);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    translateY = listRecord[4];
    translateX = listRecord[3];
    column0W = currentMatrix[3];
    translateZ = listRecord[5];
    scaleX = *listRecord;
    scaleZ = listRecord[2];
    scaleY = listRecord[1];
    currentMatrix[0xc] = currentMatrix[0xc] + (currentMatrix[8] * translateZ + (*currentMatrix * translateX + currentMatrix[4] * translateY));
    currentMatrix[3] = column0W * scaleX;
    currentMatrix[0xd] = currentMatrix[0xd] + (currentMatrix[9] * translateZ + (currentMatrix[1] * translateX + currentMatrix[5] * translateY));
    currentMatrix[0xe] = currentMatrix[0xe] + (currentMatrix[10] * translateZ + (currentMatrix[2] * translateX + currentMatrix[6] * translateY));
    currentMatrix[0xf] = currentMatrix[0xf] + (currentMatrix[0xb] * translateZ + (column0W * translateX + currentMatrix[7] * translateY));
    *currentMatrix = *currentMatrix * scaleX;
    currentMatrix[1] = currentMatrix[1] * scaleX;
    currentMatrix[2] = currentMatrix[2] * scaleX;
    currentMatrix[4] = currentMatrix[4] * scaleY;
    currentMatrix[5] = currentMatrix[5] * scaleY;
    currentMatrix[6] = currentMatrix[6] * scaleY;
    currentMatrix[7] = currentMatrix[7] * scaleY;
    currentMatrix[0xb] = currentMatrix[0xb] * scaleZ;
    currentMatrix[8] = currentMatrix[8] * scaleZ;
    currentMatrix[9] = currentMatrix[9] * scaleZ;
    currentMatrix[10] = currentMatrix[10] * scaleZ;
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | *(uint *)(glContext + 0x50a8);
    *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | *(uint *)(glContext + 0x50a8);
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return 0x18;
}

/* _glOrtho_Comp @ 0x79558 (364 bytes) */
int _glOrtho_Comp(int glContext,double left,double right,double bottom,double top,double zNear,double zFar,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *listRecord;
  double dVar6;
  double dVar7;
  double dVar8;
  
  fVar1 = (float)(right - left);
  fVar2 = (float)(zNear - zFar);
  fVar3 = (float)(top - bottom);
  fVar4 = fVar1;
  if (!(FLOAT_00108e50 <= fVar1)) {
    fVar4 = -fVar1;
  }
  if (!(fVar4 < FLOAT_00108e80)) {
    fVar4 = fVar3;
    if (!(FLOAT_00108e50 <= fVar3)) {
      fVar4 = -fVar3;
    }
    if (!(fVar4 < FLOAT_00108e80)) {
      fVar4 = fVar2;
      if (!(FLOAT_00108e50 <= fVar2)) {
        fVar4 = -fVar2;
      }
      if (!(fVar4 < FLOAT_00108e80)) {
        listRecord = (float *)_gleAddListItem(glContext,PTR__glOrtho_ListExec_00110230,0x18);
        if (listRecord == (float *)0x0) {
          return 0;
        }
        dVar6 = (double)(1.0 / fVar2);
        dVar8 = (double)(1.0 / fVar1);
        dVar7 = (double)(1.0 / fVar3);
        listRecord[5] = (float)((zFar + zNear) * dVar6);
        listRecord[4] = (float)(-(top + bottom) * dVar7);
        *listRecord = (float)(dVar8 + dVar8);
        listRecord[3] = (float)(-(right + left) * dVar8);
        listRecord[1] = (float)(dVar7 + dVar7);
        listRecord[2] = (float)(dVar6 + dVar6);
        return (int)listRecord;
      }
    }
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return glContext;
}

/* _glOrtho_CompExec @ 0x796c4 (120 bytes) */
void _glOrtho_CompExec(undefined4 glContext,double left,double right,double bottom,double top,double zNear,double zFar,double forwardedFloatArg7,double forwardedFloatArg8,double forwardedFloatArg9,double forwardedFloatArg10,double forwardedFloatArg11,double forwardedFloatArg12,double forwardedFloatArg13)
{
  double incomingStack_ffffff68;
  double incomingStack_ffffff70;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  double incomingStack_ffffff88;
  
  ((int (*)())_glOrtho_Comp)(glContext,left,right,bottom,top,zNear,zFar,forwardedFloatArg7,forwardedFloatArg8,
                incomingStack_ffffff68,incomingStack_ffffff70,incomingStack_ffffff78,incomingStack_ffffff80,
                incomingStack_ffffff88);
  ((void (*)())_glOrtho_Exec)(glContext,left,right,bottom,top,zNear,zFar,forwardedFloatArg7,forwardedFloatArg8,
                forwardedFloatArg9,forwardedFloatArg10,forwardedFloatArg11,forwardedFloatArg12,forwardedFloatArg13);
  return;
}

/* _glBindProgramARB_Comp @ 0x7973c (84 bytes) */
int _glBindProgramARB_Comp(glContext, target, program)
  undefined4 glContext;
  undefined4 target;
  undefined4 program;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glBindProgramARB_ListExec_00110240,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = program;
    *listRecord = target;
  }
  return listRecord;
}

/* _glBindProgramARB_CompExec @ 0x79790 (64 bytes) */
void _glBindProgramARB_CompExec(glContext, target, program)
  undefined4 glContext;
  undefined4 target;
  undefined4 program;
{
  ((int (*)())_glBindProgramARB_Comp)(glContext,target,program);
  _glBindProgramARB_Exec(glContext,target,program);
  return;
}

/* _glBindProgramARB_ListExec @ 0x797d0 (44 bytes) */
int _glBindProgramARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glBindProgramARB_Exec(glContext,*listRecord,listRecord[1]);
  return 8;
}

/* _glIsProgramARB_Exec @ 0x797fc (168 bytes) */
int _glIsProgramARB_Exec(glContext, program)
  int glContext;
  undefined4 program;
{
  int iVar1;
  bool bVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar1 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar1 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar1 + 0x8028);
      iVar1 = *(int *)(glContext + 0x5148);
    }
    iVar1 = _gleLookupHashObject(iVar1 + 0x4010,program);
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    bVar2 = iVar1 != 0;
  }
  else {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    bVar2 = false;
  }
  return bVar2;
}

/* _glProgramEnvParameter4dARB_Exec @ 0x798a4 (324 bytes) */
void _glProgramEnvParameter4dARB_Exec(int glContext,uint target,uint index,double x,double y,double z,double w,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  byte bVar1;
  uint uVar2;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (target == 0x8620) {
    iVar5 = 0;
    if (index < 0x100) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x800000;
LAB_00079938:
      *(uint *)(glContext + 0x31c) = uVar2;
      if (*(int *)(glContext + 0x5434) == 0) {
        bVar1 = *(byte *)(index + *(int *)(glContext + 0x5420) + 0x158);
      }
      else {
        bVar1 = *(byte *)(index + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x18c);
      }
      iVar6 = (bVar1 >> 3 & 0x1c) + glContext;
      iVar4 = *(int *)(glContext + 0x5424);
      *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(index + iVar4 + 0x158);
      iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
      *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar4 = *(int *)(iVar5 * 8 + glContext + 0x4668);
      iVar5 = iVar4 + index * 0x10;
      *(float *)(iVar4 + index * 0x10) = (float)x;
      *(float *)(iVar5 + 0xc) = (float)w;
      *(float *)(iVar5 + 4) = (float)y;
      *(float *)(iVar5 + 8) = (float)z;
      return;
    }
  }
  else {
    if (target < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (target != uVar2) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00079930;
    }
    iVar5 = 1;
    if (index < 0x80) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x2000000;
      goto LAB_00079938;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x501;
LAB_00079930:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glProgramEnvParameter4dvARB_Exec @ 0x799e8 (340 bytes) */
void _glProgramEnvParameter4dvARB_Exec(glContext, target, index, params)
  int glContext;
  uint target;
  uint index;
  double *params;
{
  byte bVar1;
  uint uVar2;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (target == 0x8620) {
    iVar5 = 0;
    if (index < 0x100) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x800000;
LAB_00079a7c:
      *(uint *)(glContext + 0x31c) = uVar2;
      if (*(int *)(glContext + 0x5434) == 0) {
        bVar1 = *(byte *)(index + *(int *)(glContext + 0x5420) + 0x158);
      }
      else {
        bVar1 = *(byte *)(index + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x18c);
      }
      iVar6 = (bVar1 >> 3 & 0x1c) + glContext;
      iVar4 = *(int *)(glContext + 0x5424);
      *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(index + iVar4 + 0x158);
      iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
      *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar5 = *(int *)(iVar5 * 8 + glContext + 0x4668);
      *(float *)(iVar5 + index * 0x10) = (float)*params;
      iVar5 = iVar5 + index * 0x10;
      *(float *)(iVar5 + 4) = (float)params[1];
      *(float *)(iVar5 + 8) = (float)params[2];
      *(float *)(iVar5 + 0xc) = (float)params[3];
      return;
    }
  }
  else {
    if (target < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (target != uVar2) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00079a74;
    }
    iVar5 = 1;
    if (index < 0x80) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x2000000;
      goto LAB_00079a7c;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x501;
LAB_00079a74:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glProgramEnvParameter4fARB_Exec @ 0x79b3c (308 bytes) */
void _glProgramEnvParameter4fARB_Exec(int glContext,uint target,uint index,float x,float y,float z,float w)
{
  byte bVar1;
  uint uVar2;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (target == 0x8620) {
    iVar5 = 0;
    if (index < 0x100) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x800000;
LAB_00079bd0:
      *(uint *)(glContext + 0x31c) = uVar2;
      if (*(int *)(glContext + 0x5434) == 0) {
        bVar1 = *(byte *)(index + *(int *)(glContext + 0x5420) + 0x158);
      }
      else {
        bVar1 = *(byte *)(index + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x18c);
      }
      iVar6 = (bVar1 >> 3 & 0x1c) + glContext;
      iVar4 = *(int *)(glContext + 0x5424);
      *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(index + iVar4 + 0x158);
      iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
      *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar4 = *(int *)(iVar5 * 8 + glContext + 0x4668);
      iVar5 = iVar4 + index * 0x10;
      *(float *)(iVar4 + index * 0x10) = (float)x;
      *(float *)(iVar5 + 0xc) = (float)w;
      *(float *)(iVar5 + 4) = (float)y;
      *(float *)(iVar5 + 8) = (float)z;
      return;
    }
  }
  else {
    if (target < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (target != uVar2) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00079bc8;
    }
    iVar5 = 1;
    if (index < 0x80) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x2000000;
      goto LAB_00079bd0;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x501;
LAB_00079bc8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glProgramEnvParameter4dARB_Comp @ 0x79c70 (124 bytes) */
void _glProgramEnvParameter4dARB_Comp(undefined4 glContext,undefined4 target,undefined4 index,double x,double y,double z,double w)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glProgramEnvParameter4fvARB_ListExec_0011023c,0x18);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
    listRecord[1] = index;
    listRecord[2] = (float)x;
    listRecord[3] = (float)y;
    listRecord[4] = (float)z;
    listRecord[5] = (float)w;
  }
  return;
}

/* _glProgramEnvParameter4dvARB_Comp @ 0x79cec (136 bytes) */
int _glProgramEnvParameter4dvARB_Comp(glContext, target, index, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 index;
  double *params;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glProgramEnvParameter4fvARB_ListExec_0011023c,0x18);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
    listRecord[1] = index;
    listRecord[2] = (float)*params;
    listRecord[3] = (float)params[1];
    listRecord[4] = (float)params[2];
    listRecord[5] = (float)params[3];
  }
  return listRecord;
}

/* _glProgramEnvParameter4fARB_Comp @ 0x79d74 (108 bytes) */
void _glProgramEnvParameter4fARB_Comp(undefined4 glContext,undefined4 target,undefined4 index,float x,float y,float z,float w)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glProgramEnvParameter4fvARB_ListExec_0011023c,0x18);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[5] = (float)w;
    *listRecord = target;
    listRecord[1] = index;
    listRecord[2] = (float)x;
    listRecord[3] = (float)y;
    listRecord[4] = (float)z;
  }
  return;
}

/* _glProgramEnvParameter4fvARB_Comp @ 0x79de0 (120 bytes) */
int _glProgramEnvParameter4fvARB_Comp(glContext, target, index, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 index;
  undefined4 *params;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glProgramEnvParameter4fvARB_ListExec_0011023c,0x18);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
    listRecord[1] = index;
    listRecord[2] = *params;
    listRecord[3] = params[1];
    listRecord[4] = params[2];
    listRecord[5] = params[3];
  }
  return listRecord;
}

/* _glProgramEnvParameter4dARB_CompExec @ 0x79e58 (112 bytes) */
void _glProgramEnvParameter4dARB_CompExec(undefined4 glContext,undefined4 target,undefined4 index,double x,double y,double z,double w)
{
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glProgramEnvParameter4dARB_Comp)(glContext,target,index,x,y,z,w);
  ((void (*)())_glProgramEnvParameter4dARB_Exec)(glContext,target,index,x,y,z,w,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
  return;
}

/* _glProgramEnvParameter4dvARB_CompExec @ 0x79ec8 (72 bytes) */
void _glProgramEnvParameter4dvARB_CompExec(glContext, target, index, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 index;
  undefined4 params;
{
  ((int (*)())_glProgramEnvParameter4dvARB_Comp)(glContext,target,index,params);
  ((void (*)())_glProgramEnvParameter4dvARB_Exec)(glContext,target,index,params);
  return;
}

/* _glProgramEnvParameter4fARB_CompExec @ 0x79f10 (112 bytes) */
void _glProgramEnvParameter4fARB_CompExec(undefined4 glContext,undefined4 target,undefined4 index,float x,float y,float z,float w)
{
  ((void (*)())_glProgramEnvParameter4fARB_Comp)(glContext,target,index,x,y,z,w);
  ((void (*)())_glProgramEnvParameter4fARB_Exec)(glContext,target,index,x,y,z,w);
  return;
}

/* _glProgramEnvParameter4fvARB_CompExec @ 0x79f80 (72 bytes) */
void _glProgramEnvParameter4fvARB_CompExec(glContext, target, index, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 index;
  undefined4 params;
{
  ((int (*)())_glProgramEnvParameter4fvARB_Comp)(glContext,target,index,params);
  _glProgramEnvParameter4fvARB_Exec(glContext,target,index,params);
  return;
}

/* _glProgramEnvParameter4fvARB_ListExec @ 0x79fc8 (52 bytes) */
int _glProgramEnvParameter4fvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glProgramEnvParameter4fvARB_Exec(glContext,*listRecord,listRecord[1],listRecord + 2);
  return 0x18;
}

/* _glProgramLocalParameter4dARB_Exec @ 0x79ffc (344 bytes) */
void _glProgramLocalParameter4dARB_Exec(int glContext,uint target,uint index,double x,double y,double z,double w,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  byte bVar1;
  uint uVar2;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (target == 0x8620) {
    iVar5 = 0;
    if (index < 0x100) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x400000;
LAB_0007a090:
      *(uint *)(glContext + 0x31c) = uVar2;
      if (*(int *)(glContext + 0x5434) == 0) {
        bVar1 = *(byte *)(index + *(int *)(glContext + 0x5420) + 0x58);
      }
      else {
        bVar1 = *(byte *)(index + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x8c);
      }
      iVar6 = (bVar1 >> 3 & 0x1c) + glContext;
      iVar4 = *(int *)(glContext + 0x5424);
      *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(index + iVar4 + 0x58);
      iVar6 = iVar5 * 4 + glContext;
      iVar5 = (bVar1 >> 3 & 0x1c) + glContext;
      iVar4 = *(int *)(iVar6 + 0x5420);
      *(uint *)(iVar5 + 0x348) = *(uint *)(iVar5 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar4 = *(int *)(iVar4 + 0x4e0);
      iVar5 = iVar4 + index * 0x10;
      *(float *)(iVar4 + index * 0x10) = (float)x;
      *(float *)(iVar5 + 0xc) = (float)w;
      *(float *)(iVar5 + 4) = (float)y;
      *(float *)(iVar5 + 8) = (float)z;
      _gleModifyPluginPipelineProgram(glContext,*(int *)(iVar6 + 0x5420) + 0x10,2);
      return;
    }
  }
  else {
    if (target < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (target != uVar2) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_0007a088;
    }
    iVar5 = 1;
    if (index < 0x80) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x1000000;
      goto LAB_0007a090;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x501;
LAB_0007a088:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glProgramLocalParameter4dvARB_Exec @ 0x7a154 (360 bytes) */
void _glProgramLocalParameter4dvARB_Exec(glContext, target, index, params)
  int glContext;
  uint target;
  uint index;
  double *params;
{
  byte bVar1;
  uint uVar2;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (target == 0x8620) {
    iVar5 = 0;
    if (index < 0x100) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x400000;
LAB_0007a1e8:
      *(uint *)(glContext + 0x31c) = uVar2;
      if (*(int *)(glContext + 0x5434) == 0) {
        bVar1 = *(byte *)(index + *(int *)(glContext + 0x5420) + 0x58);
      }
      else {
        bVar1 = *(byte *)(index + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x8c);
      }
      iVar7 = (bVar1 >> 3 & 0x1c) + glContext;
      iVar4 = *(int *)(glContext + 0x5424);
      iVar6 = iVar5 * 4 + glContext;
      *(uint *)(iVar7 + 0x324) = *(uint *)(iVar7 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(index + iVar4 + 0x58);
      iVar5 = (bVar1 >> 3 & 0x1c) + glContext;
      *(uint *)(iVar5 + 0x348) = *(uint *)(iVar5 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar5 = *(int *)(*(int *)(iVar6 + 0x5420) + 0x4e0);
      *(float *)(iVar5 + index * 0x10) = (float)*params;
      iVar5 = iVar5 + index * 0x10;
      *(float *)(iVar5 + 4) = (float)params[1];
      *(float *)(iVar5 + 8) = (float)params[2];
      *(float *)(iVar5 + 0xc) = (float)params[3];
      _gleModifyPluginPipelineProgram(glContext,*(int *)(iVar6 + 0x5420) + 0x10,2);
      return;
    }
  }
  else {
    if (target < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (target != uVar2) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_0007a1e0;
    }
    iVar5 = 1;
    if (index < 0x80) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x1000000;
      goto LAB_0007a1e8;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x501;
LAB_0007a1e0:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glProgramLocalParameter4dARB_Comp @ 0x7a2bc (124 bytes) */
void _glProgramLocalParameter4dARB_Comp(undefined4 glContext,undefined4 target,undefined4 index,double x,double y,double z,double w)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glProgramLocalParameter4fvARB_ListExec_00110238,0x18);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
    listRecord[1] = index;
    listRecord[2] = (float)x;
    listRecord[3] = (float)y;
    listRecord[4] = (float)z;
    listRecord[5] = (float)w;
  }
  return;
}

/* _glProgramLocalParameter4dvARB_Comp @ 0x7a338 (136 bytes) */
int _glProgramLocalParameter4dvARB_Comp(glContext, target, index, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 index;
  double *params;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glProgramLocalParameter4fvARB_ListExec_00110238,0x18);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
    listRecord[1] = index;
    listRecord[2] = (float)*params;
    listRecord[3] = (float)params[1];
    listRecord[4] = (float)params[2];
    listRecord[5] = (float)params[3];
  }
  return listRecord;
}

/* _glProgramLocalParameter4fARB_Comp @ 0x7a3c0 (108 bytes) */
void _glProgramLocalParameter4fARB_Comp(undefined4 glContext,undefined4 target,undefined4 index,float x,float y,float z,float w)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glProgramLocalParameter4fvARB_ListExec_00110238,0x18);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[5] = (float)w;
    *listRecord = target;
    listRecord[1] = index;
    listRecord[2] = (float)x;
    listRecord[3] = (float)y;
    listRecord[4] = (float)z;
  }
  return;
}

/* _glProgramLocalParameter4fvARB_Comp @ 0x7a42c (120 bytes) */
int _glProgramLocalParameter4fvARB_Comp(glContext, target, index, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 index;
  undefined4 *params;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glProgramLocalParameter4fvARB_ListExec_00110238,0x18);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
    listRecord[1] = index;
    listRecord[2] = *params;
    listRecord[3] = params[1];
    listRecord[4] = params[2];
    listRecord[5] = params[3];
  }
  return listRecord;
}

/* _glProgramLocalParameter4dARB_CompExec @ 0x7a4a4 (112 bytes) */
void _glProgramLocalParameter4dARB_CompExec(undefined4 glContext,undefined4 target,undefined4 index,double x,double y,double z,double w)
{
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glProgramLocalParameter4dARB_Comp)(glContext,target,index,x,y,z,w);
  ((void (*)())_glProgramLocalParameter4dARB_Exec)(glContext,target,index,x,y,z,w,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
  return;
}

/* _glProgramLocalParameter4dvARB_CompExec @ 0x7a514 (72 bytes) */
void _glProgramLocalParameter4dvARB_CompExec(glContext, target, index, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 index;
  undefined4 params;
{
  ((int (*)())_glProgramLocalParameter4dvARB_Comp)(glContext,target,index,params);
  ((void (*)())_glProgramLocalParameter4dvARB_Exec)(glContext,target,index,params);
  return;
}

/* _glProgramLocalParameter4fARB_CompExec @ 0x7a55c (112 bytes) */
void _glProgramLocalParameter4fARB_CompExec(undefined4 glContext,undefined4 target,undefined4 index,float x,float y,float z,float w)
{
  ((void (*)())_glProgramLocalParameter4fARB_Comp)(glContext,target,index,x,y,z,w);
  ((void (*)())_glProgramLocalParameter4fARB_Exec)(glContext,target,index,x,y,z,w);
  return;
}

/* _glProgramLocalParameter4fvARB_CompExec @ 0x7a5cc (72 bytes) */
void _glProgramLocalParameter4fvARB_CompExec(glContext, target, index, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 index;
  undefined4 params;
{
  ((int (*)())_glProgramLocalParameter4fvARB_Comp)(glContext,target,index,params);
  _glProgramLocalParameter4fvARB_Exec(glContext,target,index,params);
  return;
}

/* _glProgramLocalParameter4fvARB_ListExec @ 0x7a614 (52 bytes) */
int _glProgramLocalParameter4fvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glProgramLocalParameter4fvARB_Exec(glContext,*listRecord,listRecord[1],listRecord + 2);
  return 0x18;
}

/* _glProgramStringARB_ListExec @ 0x7a648 (68 bytes) */
int _glProgramStringARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glProgramStringARB_Exec(glContext,*listRecord,listRecord[1],listRecord[2],listRecord + 3);
  return listRecord[2] + 0xc;
}

/* _glProgramStringARB_Comp @ 0x7a68c (164 bytes) */
int _glProgramStringARB_Comp(glContext, target, format, len, string)
  undefined4 glContext;
  undefined4 target;
  undefined4 format;
  int len;
  undefined4 string;
{
  uint uVar1;
  int remaining;
  undefined1 *dstCursor;
  undefined4 *listRecord;
  undefined4 uVar5;
  
  uVar1 = len + 3U & 0xfffffffc;
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glProgramStringARB_ListExec_00110234,uVar1 + 0xc);
  uVar5 = 0;
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
    listRecord[1] = format;
    listRecord[2] = uVar1;
    uVar5 = _memcpy(listRecord + 3,string,len);
    if (len <= (int)uVar1) {
      remaining = (uVar1 + 1) - len;
      dstCursor = (undefined1 *)((int)listRecord + len + 0xc);
      do {
        *dstCursor = 0x20;
        dstCursor = dstCursor + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
  }
  return uVar5;
}

/* _glProgramStringARB_CompExec @ 0x7a730 (80 bytes) */
void _glProgramStringARB_CompExec(glContext, target, format, len, string)
  undefined4 glContext;
  undefined4 target;
  undefined4 format;
  undefined4 len;
  undefined4 string;
{
  ((int (*)())_glProgramStringARB_Comp)(glContext,target,format,len,string);
  _glProgramStringARB_Exec(glContext,target,format,len,string);
  return;
}

/* _glGetProgramStringARB_Exec @ 0x7a780 (196 bytes) */
void _glGetProgramStringARB_Exec(glContext, target, pname, string)
  int glContext;
  uint target;
  int pname;
  int string;
{
  undefined4 glErrorCode;
  uint uVar2;
  int iVar3;
  int remaining;
  int iVar4;
  int iVar5;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (pname == 0x8628) {
      if (target == 0x8620) {
        iVar3 = 0;
LAB_0007a80c:
        iVar5 = 0;
        iVar4 = *(int *)(iVar3 * 4 + glContext + 0x5420);
        remaining = *(int *)(iVar4 + 0x18);
        iVar4 = *(int *)(iVar4 + 0x14);
        if (remaining != 0) {
          do {
            *(undefined1 *)(string + iVar5) = *(undefined1 *)(iVar4 + iVar5);
            iVar5 = iVar5 + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
          return;
        }
        return;
      }
      if (target < 0x8621) {
        uVar2 = 0x8200;
      }
      else {
        uVar2 = 0x8804;
      }
      if (target == uVar2) {
        iVar3 = 1;
        goto LAB_0007a80c;
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

/* _glGetProgramEnvParameterdvARB_Exec @ 0x7a844 (212 bytes) */
void _glGetProgramEnvParameterdvARB_Exec(glContext, target, index, params)
  int glContext;
  uint target;
  uint index;
  double *params;
{
  bool bVar1;
  undefined4 glErrorCode;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8620) {
      bVar1 = 0xff < index;
      iVar4 = 0;
    }
    else {
      if (target < 0x8621) {
        uVar3 = 0x8200;
      }
      else {
        uVar3 = 0x8804;
      }
      if (target != uVar3) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0007a8b8;
      }
      bVar1 = 0x7f < index;
      iVar4 = 1;
    }
    if (!bVar1) {
      iVar4 = *(int *)(iVar4 * 8 + glContext + 0x4668);
      iVar5 = iVar4 + index * 0x10;
      *params = (double)*(float *)(iVar4 + index * 0x10);
      params[1] = (double)*(float *)(iVar5 + 4);
      params[2] = (double)*(float *)(iVar5 + 8);
      params[3] = (double)*(float *)(iVar5 + 0xc);
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
LAB_0007a8b8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetProgramEnvParameterfvARB_Exec @ 0x7a918 (212 bytes) */
void _glGetProgramEnvParameterfvARB_Exec(glContext, target, index, params)
  int glContext;
  uint target;
  uint index;
  undefined4 *params;
{
  bool bVar1;
  undefined4 glErrorCode;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8620) {
      bVar1 = 0xff < index;
      iVar4 = 0;
    }
    else {
      if (target < 0x8621) {
        uVar3 = 0x8200;
      }
      else {
        uVar3 = 0x8804;
      }
      if (target != uVar3) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0007a98c;
      }
      bVar1 = 0x7f < index;
      iVar4 = 1;
    }
    if (!bVar1) {
      iVar4 = *(int *)(iVar4 * 8 + glContext + 0x4668);
      iVar5 = iVar4 + index * 0x10;
      *params = *(undefined4 *)(iVar4 + index * 0x10);
      params[1] = *(undefined4 *)(iVar5 + 4);
      params[2] = *(undefined4 *)(iVar5 + 8);
      params[3] = *(undefined4 *)(iVar5 + 0xc);
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
LAB_0007a98c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetProgramLocalParameterdvARB_Exec @ 0x7a9ec (216 bytes) */
void _glGetProgramLocalParameterdvARB_Exec(glContext, target, index, params)
  int glContext;
  uint target;
  uint index;
  double *params;
{
  bool bVar1;
  undefined4 glErrorCode;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8620) {
      bVar1 = 0xff < index;
      iVar4 = 0;
    }
    else {
      if (target < 0x8621) {
        uVar3 = 0x8200;
      }
      else {
        uVar3 = 0x8804;
      }
      if (target != uVar3) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0007aa60;
      }
      bVar1 = 0x7f < index;
      iVar4 = 1;
    }
    if (!bVar1) {
      iVar4 = *(int *)(*(int *)(iVar4 * 4 + glContext + 0x5420) + 0x4e0);
      iVar5 = iVar4 + index * 0x10;
      *params = (double)*(float *)(iVar4 + index * 0x10);
      params[1] = (double)*(float *)(iVar5 + 4);
      params[2] = (double)*(float *)(iVar5 + 8);
      params[3] = (double)*(float *)(iVar5 + 0xc);
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
LAB_0007aa60:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetProgramLocalParameterfvARB_Exec @ 0x7aac4 (216 bytes) */
void _glGetProgramLocalParameterfvARB_Exec(glContext, target, index, params)
  int glContext;
  uint target;
  uint index;
  undefined4 *params;
{
  bool bVar1;
  undefined4 glErrorCode;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8620) {
      bVar1 = 0xff < index;
      iVar4 = 0;
    }
    else {
      if (target < 0x8621) {
        uVar3 = 0x8200;
      }
      else {
        uVar3 = 0x8804;
      }
      if (target != uVar3) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0007ab38;
      }
      bVar1 = 0x7f < index;
      iVar4 = 1;
    }
    if (!bVar1) {
      iVar4 = *(int *)(*(int *)(iVar4 * 4 + glContext + 0x5420) + 0x4e0);
      iVar5 = iVar4 + index * 0x10;
      *params = *(undefined4 *)(iVar4 + index * 0x10);
      params[1] = *(undefined4 *)(iVar5 + 4);
      params[2] = *(undefined4 *)(iVar5 + 8);
      params[3] = *(undefined4 *)(iVar5 + 0xc);
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
LAB_0007ab38:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glPixelMapfv_ListExec @ 0x7ab9c (68 bytes) */
int _glPixelMapfv_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glPixelMapfv_Exec)(glContext,*listRecord,listRecord[1],listRecord + 2);
  return listRecord[1] * 4 + 8;
}

/* _glPixelMapfv_Comp @ 0x7abe0 (236 bytes) */
int _glPixelMapfv_Comp(glContext, map, mapsize, values)
  int glContext;
  undefined4 map;
  int mapsize;
  uint values;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(glContext + 0x4a6c);
  if (iVar3 == 0) {
    iVar2 = mapsize << 2;
  }
  else {
    iVar2 = mapsize * 4;
    if ((*(int *)(iVar3 + 0x38) < (int)(iVar2 + values)) || ((values & 3) != 0)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return (undefined4 *)glContext;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x502;
      return (undefined4 *)glContext;
    }
    if (*(int *)(iVar3 + 0x40) != 0) {
      _gleSynchronizePluginBuffer(glContext,iVar3 + 0x10);
    }
    values = values + *(int *)(iVar3 + 0x30);
  }
  puVar1 = (undefined4 *)_gleAddListItem(glContext,PTR__glPixelMapfv_ListExec_0011024c,iVar2 + 8);
  if (puVar1 != (undefined4 *)0x0) {
    iVar3 = 0;
    *puVar1 = map;
    puVar1[1] = mapsize;
    puVar1 = puVar1 + 2;
    if (0 < mapsize) {
      do {
        puVar1[iVar3] = *(undefined4 *)(values + iVar3 * 4);
        mapsize = mapsize + -1;
        iVar3 = iVar3 + 1;
      } while (mapsize != 0);
    }
  }
  return puVar1;
}

/* _glPixelMapfv_Exec @ 0x7accc (1760 bytes) */
void _glPixelMapfv_Exec(glContext, map, mapsize, values)
  int glContext;
  undefined4 map;
  uint mapsize;
  uint values;
{
  int byteOffset;
  float floatZero;
  float floatOne;
  undefined4 glErrorCode;
  float mapValue;
  uint mapsizeMinusOne;
  int pixelUnpackBuffer;
  int loopIndex;
  int mapStorage;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
LAB_0007ad34:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0007b32c;
  }
  mapsizeMinusOne = mapsize - 1;
  if (mapsizeMinusOne < 0x100) {
    pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
    if (pixelUnpackBuffer != 0) {
      if ((*(int *)(pixelUnpackBuffer + 0x38) < (int)(mapsize * 4 + values)) || ((values & 3) != 0))
      goto LAB_0007ad34;
      if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
      }
      values = values + *(int *)(pixelUnpackBuffer + 0x30);
    }
    switch(map) {
    case 0xc70:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007b07c;
      if (*(undefined **)(glContext + 0x3248) != PTR__gle_default_pix_map_i_00112044) {
        _free(*(undefined **)(glContext + 0x3248));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3248) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3270) = mapsize;
        if (0 < (int)mapsize) {
          do {
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(int *)(byteOffset + *(int *)(glContext + 0x3248)) = (int)*(float *)(byteOffset + values);
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc71:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007b07c;
      if (*(undefined **)(glContext + 0x326c) != PTR__gle_default_pix_map_i_00112044) {
        _free(*(undefined **)(glContext + 0x326c));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x326c) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3274) = mapsize;
        if (0 < (int)mapsize) {
          do {
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(int *)(byteOffset + *(int *)(glContext + 0x326c)) = (int)*(float *)(byteOffset + values);
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc72:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007b07c;
      if (*(undefined **)(glContext + 0x324c) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x324c));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x324c) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3278) = mapsize;
        floatOne = FLOAT_00108e54;
        floatZero = FLOAT_00108e50;
        if (0 < (int)mapsize) {
          do {
            mapValue = *(float *)(values + loopIndex * 4);
            if (mapValue < floatZero) {
              mapValue = 0.0;
            }
            else if (floatOne < mapValue) {
              mapValue = 1.0;
            }
            *(float *)(loopIndex * 4 + *(int *)(glContext + 0x324c)) = mapValue;
            loopIndex = loopIndex + 1;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc73:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007b07c;
      if (*(undefined **)(glContext + 0x3250) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3250));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3250) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x327c) = mapsize;
        floatOne = FLOAT_00108e54;
        floatZero = FLOAT_00108e50;
        if (0 < (int)mapsize) {
          do {
            mapValue = *(float *)(values + loopIndex * 4);
            if (mapValue < floatZero) {
              mapValue = 0.0;
            }
            else if (floatOne < mapValue) {
              mapValue = 1.0;
            }
            *(float *)(loopIndex * 4 + *(int *)(glContext + 0x3250)) = mapValue;
            loopIndex = loopIndex + 1;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc74:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007b07c;
      if (*(undefined **)(glContext + 0x3254) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3254));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3254) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3280) = mapsize;
        floatOne = FLOAT_00108e54;
        floatZero = FLOAT_00108e50;
        if (0 < (int)mapsize) {
          do {
            mapValue = *(float *)(values + loopIndex * 4);
            if (mapValue < floatZero) {
              mapValue = 0.0;
            }
            else if (floatOne < mapValue) {
              mapValue = 1.0;
            }
            *(float *)(loopIndex * 4 + *(int *)(glContext + 0x3254)) = mapValue;
            loopIndex = loopIndex + 1;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc75:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007b07c;
      if (*(undefined **)(glContext + 0x3258) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3258));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3258) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3284) = mapsize;
        floatOne = FLOAT_00108e54;
        floatZero = FLOAT_00108e50;
        if (0 < (int)mapsize) {
          do {
            mapValue = *(float *)(values + loopIndex * 4);
            if (mapValue < floatZero) {
              mapValue = 0.0;
            }
            else if (floatOne < mapValue) {
              mapValue = 1.0;
            }
            *(float *)(loopIndex * 4 + *(int *)(glContext + 0x3258)) = mapValue;
            loopIndex = loopIndex + 1;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc76:
      if (*(undefined **)(glContext + 0x325c) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x325c));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x325c) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3288) = mapsize;
        floatOne = FLOAT_00108e54;
        floatZero = FLOAT_00108e50;
        if (0 < (int)mapsize) {
          do {
            mapValue = *(float *)(values + loopIndex * 4);
            if (mapValue < floatZero) {
              mapValue = 0.0;
            }
            else if (floatOne < mapValue) {
              mapValue = 1.0;
            }
            *(float *)(loopIndex * 4 + *(int *)(glContext + 0x325c)) = mapValue;
            loopIndex = loopIndex + 1;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc77:
      if (*(undefined **)(glContext + 0x3260) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3260));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3260) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x328c) = mapsize;
        floatOne = FLOAT_00108e54;
        floatZero = FLOAT_00108e50;
        if (0 < (int)mapsize) {
          do {
            mapValue = *(float *)(values + loopIndex * 4);
            if (mapValue < floatZero) {
              mapValue = 0.0;
            }
            else if (floatOne < mapValue) {
              mapValue = 1.0;
            }
            *(float *)(loopIndex * 4 + *(int *)(glContext + 0x3260)) = mapValue;
            loopIndex = loopIndex + 1;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc78:
      if (*(undefined **)(glContext + 0x3264) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3264));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3264) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3290) = mapsize;
        floatOne = FLOAT_00108e54;
        floatZero = FLOAT_00108e50;
        if (0 < (int)mapsize) {
          do {
            mapValue = *(float *)(values + loopIndex * 4);
            if (mapValue < floatZero) {
              mapValue = 0.0;
            }
            else if (floatOne < mapValue) {
              mapValue = 1.0;
            }
            *(float *)(loopIndex * 4 + *(int *)(glContext + 0x3264)) = mapValue;
            loopIndex = loopIndex + 1;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    case 0xc79:
      if (*(undefined **)(glContext + 0x3268) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3268));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3268) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3294) = mapsize;
        floatOne = FLOAT_00108e54;
        floatZero = FLOAT_00108e50;
        if (0 < (int)mapsize) {
          do {
            mapValue = *(float *)(values + loopIndex * 4);
            if (mapValue < floatZero) {
              mapValue = 0.0;
            }
            else if (floatOne < mapValue) {
              mapValue = 1.0;
            }
            *(float *)(loopIndex * 4 + *(int *)(glContext + 0x3268)) = mapValue;
            loopIndex = loopIndex + 1;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007b3b4;
      }
      break;
    default:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x500;
      }
LAB_0007b3b4:
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200000;
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x505;
  }
  else {
LAB_0007b07c:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
LAB_0007b32c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glPixelMapfv_CompExec @ 0x7b3d4 (72 bytes) */
void _glPixelMapfv_CompExec(glContext, map, mapsize, values)
  undefined4 glContext;
  undefined4 map;
  undefined4 mapsize;
  undefined4 values;
{
  ((int (*)())_glPixelMapfv_Comp)(glContext,map,mapsize,values);
  ((void (*)())_glPixelMapfv_Exec)(glContext,map,mapsize,values);
  return;
}

/* _glPixelMapuiv_ListExec @ 0x7b41c (68 bytes) */
int _glPixelMapuiv_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glPixelMapuiv_Exec)(glContext,*listRecord,listRecord[1],listRecord + 2);
  return listRecord[1] * 4 + 8;
}

/* _glPixelMapuiv_Comp @ 0x7b460 (236 bytes) */
int _glPixelMapuiv_Comp(glContext, map, mapsize, values)
  int glContext;
  undefined4 map;
  int mapsize;
  uint values;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(glContext + 0x4a6c);
  if (iVar3 == 0) {
    iVar2 = mapsize << 2;
  }
  else {
    iVar2 = mapsize * 4;
    if ((*(int *)(iVar3 + 0x38) < (int)(iVar2 + values)) || ((values & 3) != 0)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return (undefined4 *)glContext;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x502;
      return (undefined4 *)glContext;
    }
    if (*(int *)(iVar3 + 0x40) != 0) {
      _gleSynchronizePluginBuffer(glContext,iVar3 + 0x10);
    }
    values = values + *(int *)(iVar3 + 0x30);
  }
  puVar1 = (undefined4 *)_gleAddListItem(glContext,PTR__glPixelMapuiv_ListExec_00110248,iVar2 + 8);
  if (puVar1 != (undefined4 *)0x0) {
    iVar3 = 0;
    *puVar1 = map;
    puVar1[1] = mapsize;
    puVar1 = puVar1 + 2;
    if (0 < mapsize) {
      do {
        puVar1[iVar3] = *(undefined4 *)(values + iVar3 * 4);
        mapsize = mapsize + -1;
        iVar3 = iVar3 + 1;
      } while (mapsize != 0);
    }
  }
  return puVar1;
}

/* _glPixelMapuiv_Exec @ 0x7b54c (1640 bytes) */
void _glPixelMapuiv_Exec(glContext, map, mapsize, values)
  int glContext;
  undefined4 map;
  uint mapsize;
  uint values;
{
  int byteOffset;
  double dVar2;
  double channelScale;
  undefined4 glErrorCode;
  uint mapsizeMinusOne;
  int pixelUnpackBuffer;
  int loopIndex;
  int mapStorage;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
LAB_0007b5b4:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0007bb40;
  }
  mapsizeMinusOne = mapsize - 1;
  if (mapsizeMinusOne < 0x100) {
    pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
    if (pixelUnpackBuffer != 0) {
      if ((*(int *)(pixelUnpackBuffer + 0x38) < (int)(mapsize * 4 + values)) || ((values & 3) != 0))
      goto LAB_0007b5b4;
      if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
      }
      values = values + *(int *)(pixelUnpackBuffer + 0x30);
    }
    switch(map) {
    case 0xc70:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007b8c0;
      if (*(undefined **)(glContext + 0x3248) != PTR__gle_default_pix_map_i_00112044) {
        _free(*(undefined **)(glContext + 0x3248));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3248) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3270) = mapsize;
        if (0 < (int)mapsize) {
          do {
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(undefined4 *)(byteOffset + *(int *)(glContext + 0x3248)) = *(undefined4 *)(byteOffset + values);
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc71:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007b8c0;
      if (*(undefined **)(glContext + 0x326c) != PTR__gle_default_pix_map_i_00112044) {
        _free(*(undefined **)(glContext + 0x326c));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x326c) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3274) = mapsize;
        if (0 < (int)mapsize) {
          do {
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(undefined4 *)(byteOffset + *(int *)(glContext + 0x326c)) = *(undefined4 *)(byteOffset + values);
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc72:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007b8c0;
      if (*(undefined **)(glContext + 0x324c) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x324c));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x324c) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3278) = mapsize;
        channelScale = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)mapsize) {
          do {
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x324c)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(byteOffset + values)) - dVar2)
                        * channelScale);
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc73:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007b8c0;
      if (*(undefined **)(glContext + 0x3250) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3250));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3250) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x327c) = mapsize;
        channelScale = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)mapsize) {
          do {
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x3250)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(byteOffset + values)) - dVar2)
                        * channelScale);
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc74:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007b8c0;
      if (*(undefined **)(glContext + 0x3254) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3254));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3254) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3280) = mapsize;
        channelScale = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)mapsize) {
          do {
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x3254)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(byteOffset + values)) - dVar2)
                        * channelScale);
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc75:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007b8c0;
      if (*(undefined **)(glContext + 0x3258) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3258));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3258) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3284) = mapsize;
        channelScale = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)mapsize) {
          do {
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x3258)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(byteOffset + values)) - dVar2)
                        * channelScale);
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc76:
      if (*(undefined **)(glContext + 0x325c) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x325c));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x325c) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3288) = mapsize;
        channelScale = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)mapsize) {
          do {
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x325c)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(byteOffset + values)) - dVar2)
                        * channelScale);
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc77:
      if (*(undefined **)(glContext + 0x3260) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3260));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3260) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x328c) = mapsize;
        channelScale = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)mapsize) {
          do {
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x3260)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(byteOffset + values)) - dVar2)
                        * channelScale);
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc78:
      if (*(undefined **)(glContext + 0x3264) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3264));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3264) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3290) = mapsize;
        channelScale = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)mapsize) {
          do {
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x3264)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(byteOffset + values)) - dVar2)
                        * channelScale);
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    case 0xc79:
      if (*(undefined **)(glContext + 0x3268) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3268));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3268) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3294) = mapsize;
        channelScale = DOUBLE_00108da0;
        dVar2 = DOUBLE_00108d70;
        if (0 < (int)mapsize) {
          do {
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x3268)) =
                 (float)((double)(float)((double)CONCAT44(0x43300000,
                                                          *(undefined4 *)(byteOffset + values)) - dVar2)
                        * channelScale);
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007bbbc;
      }
      break;
    default:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x500;
      }
LAB_0007bbbc:
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200000;
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x505;
  }
  else {
LAB_0007b8c0:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
LAB_0007bb40:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glPixelMapuiv_CompExec @ 0x7bbdc (72 bytes) */
void _glPixelMapuiv_CompExec(glContext, map, mapsize, values)
  undefined4 glContext;
  undefined4 map;
  undefined4 mapsize;
  undefined4 values;
{
  ((int (*)())_glPixelMapuiv_Comp)(glContext,map,mapsize,values);
  ((void (*)())_glPixelMapuiv_Exec)(glContext,map,mapsize,values);
  return;
}

/* _glPixelMapusv_ListExec @ 0x7bc24 (76 bytes) */
int _glPixelMapusv_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glPixelMapusv_Exec)(glContext,*listRecord,listRecord[1],listRecord + 2);
  return (listRecord[1] + (listRecord[1] & 1)) * 2 + 8;
}

/* _glPixelMapusv_Comp @ 0x7bc70 (240 bytes) */
int _glPixelMapusv_Comp(glContext, map, mapsize, values)
  int glContext;
  undefined4 map;
  uint mapsize;
  uint values;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(glContext + 0x4a6c);
  if (iVar3 != 0) {
    if ((*(int *)(iVar3 + 0x38) < (int)(mapsize * 2 + values)) || ((values & 1) != 0)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return (undefined4 *)glContext;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x502;
      return (undefined4 *)glContext;
    }
    if (*(int *)(iVar3 + 0x40) != 0) {
      _gleSynchronizePluginBuffer(glContext,iVar3 + 0x10);
    }
    values = values + *(int *)(iVar3 + 0x30);
  }
  puVar2 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glPixelMapusv_ListExec_00110244,
                           (mapsize + (mapsize & 1)) * 2 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    iVar3 = 0;
    *puVar2 = map;
    puVar2[1] = mapsize;
    puVar2 = puVar2 + 2;
    if (0 < (int)mapsize) {
      do {
        iVar1 = iVar3 * 2;
        iVar3 = iVar3 + 1;
        *(undefined2 *)((int)puVar2 + iVar1) = *(undefined2 *)(values + iVar1);
        mapsize = mapsize - 1;
      } while (mapsize != 0);
    }
  }
  return puVar2;
}

/* _glPixelMapusv_Exec @ 0x7bd60 (1688 bytes) */
void _glPixelMapusv_Exec(glContext, map, mapsize, values)
  int glContext;
  undefined4 map;
  uint mapsize;
  ushort *values;
{
  ushort mapValue;
  int byteOffset;
  float channelScale;
  undefined4 glErrorCode;
  uint mapsizeMinusOne;
  int pixelUnpackBuffer;
  int loopIndex;
  int mapStorage;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
LAB_0007bdc8:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0007c380;
  }
  mapsizeMinusOne = mapsize - 1;
  if (mapsizeMinusOne < 0x100) {
    pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
    if (pixelUnpackBuffer != 0) {
      if ((*(int *)(pixelUnpackBuffer + 0x38) < (int)(values + mapsize)) || (((uint)values & 1) != 0))
      goto LAB_0007bdc8;
      if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
      }
      values = (ushort *)((int)values + *(int *)(pixelUnpackBuffer + 0x30));
    }
    switch(map) {
    case 0xc70:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007c0f0;
      if (*(undefined **)(glContext + 0x3248) != PTR__gle_default_pix_map_i_00112044) {
        _free(*(undefined **)(glContext + 0x3248));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3248) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3270) = mapsize;
        if (0 < (int)mapsize) {
          do {
            mapValue = *values;
            byteOffset = loopIndex * 4;
            values = values + 1;
            loopIndex = loopIndex + 1;
            *(uint *)(byteOffset + *(int *)(glContext + 0x3248)) = (uint)mapValue;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc71:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007c0f0;
      if (*(undefined **)(glContext + 0x326c) != PTR__gle_default_pix_map_i_00112044) {
        _free(*(undefined **)(glContext + 0x326c));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x326c) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3274) = mapsize;
        if (0 < (int)mapsize) {
          do {
            mapValue = *values;
            byteOffset = loopIndex * 4;
            values = values + 1;
            loopIndex = loopIndex + 1;
            *(uint *)(byteOffset + *(int *)(glContext + 0x326c)) = (uint)mapValue;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc72:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007c0f0;
      if (*(undefined **)(glContext + 0x324c) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x324c));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x324c) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3278) = mapsize;
        channelScale = FLOAT_00108e74;
        if (0 < (int)mapsize) {
          do {
            mapValue = *values;
            values = values + 1;
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x324c)) =
                 (GH_U2F((unsigned int)((mapValue | 0x4b000000))) - 8388608.0) * channelScale;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc73:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007c0f0;
      if (*(undefined **)(glContext + 0x3250) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3250));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3250) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x327c) = mapsize;
        channelScale = FLOAT_00108e74;
        if (0 < (int)mapsize) {
          do {
            mapValue = *values;
            values = values + 1;
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x3250)) =
                 (GH_U2F((unsigned int)((mapValue | 0x4b000000))) - 8388608.0) * channelScale;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc74:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007c0f0;
      if (*(undefined **)(glContext + 0x3254) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3254));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3254) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3280) = mapsize;
        channelScale = FLOAT_00108e74;
        if (0 < (int)mapsize) {
          do {
            mapValue = *values;
            values = values + 1;
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x3254)) =
                 (GH_U2F((unsigned int)((mapValue | 0x4b000000))) - 8388608.0) * channelScale;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc75:
      if ((mapsize & mapsizeMinusOne) != 0) goto LAB_0007c0f0;
      if (*(undefined **)(glContext + 0x3258) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3258));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3258) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3284) = mapsize;
        channelScale = FLOAT_00108e74;
        if (0 < (int)mapsize) {
          do {
            mapValue = *values;
            values = values + 1;
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x3258)) =
                 (GH_U2F((unsigned int)((mapValue | 0x4b000000))) - 8388608.0) * channelScale;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc76:
      if (*(undefined **)(glContext + 0x325c) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x325c));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x325c) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3288) = mapsize;
        channelScale = FLOAT_00108e74;
        if (0 < (int)mapsize) {
          do {
            mapValue = *values;
            values = values + 1;
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x325c)) =
                 (GH_U2F((unsigned int)((mapValue | 0x4b000000))) - 8388608.0) * channelScale;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc77:
      if (*(undefined **)(glContext + 0x3260) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3260));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3260) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x328c) = mapsize;
        channelScale = FLOAT_00108e74;
        if (0 < (int)mapsize) {
          do {
            mapValue = *values;
            values = values + 1;
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x3260)) =
                 (GH_U2F((unsigned int)((mapValue | 0x4b000000))) - 8388608.0) * channelScale;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc78:
      if (*(undefined **)(glContext + 0x3264) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3264));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3264) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3290) = mapsize;
        channelScale = FLOAT_00108e74;
        if (0 < (int)mapsize) {
          do {
            mapValue = *values;
            values = values + 1;
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x3264)) =
                 (GH_U2F((unsigned int)((mapValue | 0x4b000000))) - 8388608.0) * channelScale;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007c400;
      }
      break;
    case 0xc79:
      if (*(undefined **)(glContext + 0x3268) != PTR__gle_default_pix_map_f_00112040) {
        _free(*(undefined **)(glContext + 0x3268));
      }
      mapStorage = _malloc(mapsize << 2);
      *(int *)(glContext + 0x3268) = mapStorage;
      if (mapStorage != 0) {
        loopIndex = 0;
        *(uint *)(glContext + 0x3294) = mapsize;
        channelScale = FLOAT_00108e74;
        if (0 < (int)mapsize) {
          do {
            mapValue = *values;
            values = values + 1;
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(float *)(byteOffset + *(int *)(glContext + 0x3268)) =
                 (GH_U2F((unsigned int)((mapValue | 0x4b000000))) - 8388608.0) * channelScale;
            mapsize = mapsize - 1;
          } while (mapsize != 0);
        }
        goto LAB_0007c400;
      }
      break;
    default:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x500;
      }
LAB_0007c400:
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200000;
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x505;
  }
  else {
LAB_0007c0f0:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
LAB_0007c380:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glPixelMapusv_CompExec @ 0x7c420 (72 bytes) */
void _glPixelMapusv_CompExec(glContext, map, mapsize, values)
  undefined4 glContext;
  undefined4 map;
  undefined4 mapsize;
  undefined4 values;
{
  ((int (*)())_glPixelMapusv_Comp)(glContext,map,mapsize,values);
  ((void (*)())_glPixelMapusv_Exec)(glContext,map,mapsize,values);
  return;
}

/* _glGetPixelMapfv_Exec @ 0x7c468 (932 bytes) */
void _glGetPixelMapfv_Exec(glContext, map, values)
  int glContext;
  undefined4 map;
  uint values;
{
  double dVar1;
  int mapSize;
  int byteOffset;
  undefined4 glErrorCode;
  int pixelPackBuffer;
  int loopIndex;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    pixelPackBuffer = *(int *)(glContext + 0x4a68);
    if (pixelPackBuffer != 0) {
      switch(map) {
      case 0xc70:
        mapSize = *(int *)(glContext + 0x3270);
        break;
      case 0xc71:
        mapSize = *(int *)(glContext + 0x3274);
        break;
      case 0xc72:
        mapSize = *(int *)(glContext + 0x3278);
        break;
      case 0xc73:
        mapSize = *(int *)(glContext + 0x327c);
        break;
      case 0xc74:
        mapSize = *(int *)(glContext + 0x3280);
        break;
      case 0xc75:
        mapSize = *(int *)(glContext + 0x3284);
        break;
      case 0xc76:
        mapSize = *(int *)(glContext + 0x3288);
        break;
      case 0xc77:
        mapSize = *(int *)(glContext + 0x328c);
        break;
      case 0xc78:
        mapSize = *(int *)(glContext + 0x3290);
        break;
      case 0xc79:
        mapSize = *(int *)(glContext + 0x3294);
        break;
      default:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0007c580;
      }
      if ((*(int *)(pixelPackBuffer + 0x38) < (int)(mapSize * 4 + values)) || ((values & 3) != 0))
      goto LAB_0007c570;
      if (*(int *)(pixelPackBuffer + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,pixelPackBuffer + 0x10);
      }
      values = values + *(int *)(pixelPackBuffer + 0x30);
    }
    dVar1 = DOUBLE_00108d58;
    switch(map) {
    case 0xc70:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3270)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(float *)(byteOffset + values) =
               (float)((double)CONCAT44(0x43300000,
                                        *(uint *)(byteOffset + *(int *)(glContext + 0x3248)) ^ 0x80000000)
                      - dVar1);
        } while (loopIndex < *(int *)(glContext + 0x3270));
      }
      break;
    case 0xc71:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3274)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(float *)(byteOffset + values) =
               (float)((double)CONCAT44(0x43300000,
                                        *(uint *)(byteOffset + *(int *)(glContext + 0x326c)) ^ 0x80000000)
                      - dVar1);
        } while (loopIndex < *(int *)(glContext + 0x3274));
      }
      break;
    case 0xc72:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3278)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(undefined4 *)(byteOffset + values) = *(undefined4 *)(byteOffset + *(int *)(glContext + 0x324c));
        } while (loopIndex < *(int *)(glContext + 0x3278));
      }
      break;
    case 0xc73:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x327c)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(undefined4 *)(byteOffset + values) = *(undefined4 *)(byteOffset + *(int *)(glContext + 0x3250));
        } while (loopIndex < *(int *)(glContext + 0x327c));
      }
      break;
    case 0xc74:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3280)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(undefined4 *)(byteOffset + values) = *(undefined4 *)(byteOffset + *(int *)(glContext + 0x3254));
        } while (loopIndex < *(int *)(glContext + 0x3280));
      }
      break;
    case 0xc75:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3284)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(undefined4 *)(byteOffset + values) = *(undefined4 *)(byteOffset + *(int *)(glContext + 0x3258));
        } while (loopIndex < *(int *)(glContext + 0x3284));
      }
      break;
    case 0xc76:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3288)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(undefined4 *)(byteOffset + values) = *(undefined4 *)(byteOffset + *(int *)(glContext + 0x325c));
        } while (loopIndex < *(int *)(glContext + 0x3288));
      }
      break;
    case 0xc77:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x328c)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(undefined4 *)(byteOffset + values) = *(undefined4 *)(byteOffset + *(int *)(glContext + 0x3260));
        } while (loopIndex < *(int *)(glContext + 0x328c));
      }
      break;
    case 0xc78:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3290)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(undefined4 *)(byteOffset + values) = *(undefined4 *)(byteOffset + *(int *)(glContext + 0x3264));
        } while (loopIndex < *(int *)(glContext + 0x3290));
      }
      break;
    case 0xc79:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3294)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(undefined4 *)(byteOffset + values) = *(undefined4 *)(byteOffset + *(int *)(glContext + 0x3268));
        } while (loopIndex < *(int *)(glContext + 0x3294));
      }
    }
  }
  else {
LAB_0007c570:
    if (*(int *)(glContext + 0x7574) == 0) {
      glErrorCode = 0x502;
LAB_0007c580:
      *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    }
  }
  return;
}

/* _glGetPixelMapuiv_Exec @ 0x7c85c (1436 bytes) */
void _glGetPixelMapuiv_Exec(glContext, map, values)
  int glContext;
  undefined4 map;
  uint values;
{
  double twoPow31;
  double uint32MaxAsDouble;
  int iVar3;
  int byteOffset;
  undefined4 glErrorCode;
  uint uVar5;
  int iVar6;
  int loopIndex;
  double dVar7;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar6 = *(int *)(glContext + 0x4a68);
    if (iVar6 != 0) {
      switch(map) {
      case 0xc70:
        iVar3 = *(int *)(glContext + 0x3270);
        break;
      case 0xc71:
        iVar3 = *(int *)(glContext + 0x3274);
        break;
      case 0xc72:
        iVar3 = *(int *)(glContext + 0x3278);
        break;
      case 0xc73:
        iVar3 = *(int *)(glContext + 0x327c);
        break;
      case 0xc74:
        iVar3 = *(int *)(glContext + 0x3280);
        break;
      case 0xc75:
        iVar3 = *(int *)(glContext + 0x3284);
        break;
      case 0xc76:
        iVar3 = *(int *)(glContext + 0x3288);
        break;
      case 0xc77:
        iVar3 = *(int *)(glContext + 0x328c);
        break;
      case 0xc78:
        iVar3 = *(int *)(glContext + 0x3290);
        break;
      case 0xc79:
        iVar3 = *(int *)(glContext + 0x3294);
        break;
      default:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0007c974;
      }
      if ((*(int *)(iVar6 + 0x38) < (int)(iVar3 * 4 + values)) || ((values & 3) != 0))
      goto LAB_0007c964;
      if (*(int *)(iVar6 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,iVar6 + 0x10);
      }
      values = values + *(int *)(iVar6 + 0x30);
    }
    uint32MaxAsDouble = DOUBLE_00108da8;
    twoPow31 = DOUBLE_00108d80;
    switch(map) {
    case 0xc70:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3270)) {
        do {
          iVar3 = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(undefined4 *)(iVar3 + values) = *(undefined4 *)(iVar3 + *(int *)(glContext + 0x3248));
        } while (loopIndex < *(int *)(glContext + 0x3270));
      }
      break;
    case 0xc71:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3274)) {
        do {
          iVar3 = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(undefined4 *)(iVar3 + values) = *(undefined4 *)(iVar3 + *(int *)(glContext + 0x326c));
        } while (loopIndex < *(int *)(glContext + 0x3274));
      }
      break;
    case 0xc72:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3278)) {
        byteOffset = 0;
        do {
          dVar7 = (double)*(float *)(byteOffset + *(int *)(glContext + 0x324c)) * uint32MaxAsDouble;
          if (twoPow31 <= dVar7) {
            uVar5 = (int)(dVar7 - twoPow31) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(byteOffset + values) = uVar5;
          loopIndex = loopIndex + 1;
          byteOffset = byteOffset + 4;
        } while (loopIndex < *(int *)(glContext + 0x3278));
      }
      break;
    case 0xc73:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x327c)) {
        byteOffset = 0;
        do {
          dVar7 = (double)*(float *)(byteOffset + *(int *)(glContext + 0x3250)) * uint32MaxAsDouble;
          if (twoPow31 <= dVar7) {
            uVar5 = (int)(dVar7 - twoPow31) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(byteOffset + values) = uVar5;
          loopIndex = loopIndex + 1;
          byteOffset = byteOffset + 4;
        } while (loopIndex < *(int *)(glContext + 0x327c));
      }
      break;
    case 0xc74:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3280)) {
        byteOffset = 0;
        do {
          dVar7 = (double)*(float *)(byteOffset + *(int *)(glContext + 0x3254)) * uint32MaxAsDouble;
          if (twoPow31 <= dVar7) {
            uVar5 = (int)(dVar7 - twoPow31) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(byteOffset + values) = uVar5;
          loopIndex = loopIndex + 1;
          byteOffset = byteOffset + 4;
        } while (loopIndex < *(int *)(glContext + 0x3280));
      }
      break;
    case 0xc75:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3284)) {
        byteOffset = 0;
        do {
          dVar7 = (double)*(float *)(byteOffset + *(int *)(glContext + 0x3258)) * uint32MaxAsDouble;
          if (twoPow31 <= dVar7) {
            uVar5 = (int)(dVar7 - twoPow31) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(byteOffset + values) = uVar5;
          loopIndex = loopIndex + 1;
          byteOffset = byteOffset + 4;
        } while (loopIndex < *(int *)(glContext + 0x3284));
      }
      break;
    case 0xc76:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3288)) {
        byteOffset = 0;
        do {
          dVar7 = (double)*(float *)(byteOffset + *(int *)(glContext + 0x325c)) * uint32MaxAsDouble;
          if (twoPow31 <= dVar7) {
            uVar5 = (int)(dVar7 - twoPow31) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(byteOffset + values) = uVar5;
          loopIndex = loopIndex + 1;
          byteOffset = byteOffset + 4;
        } while (loopIndex < *(int *)(glContext + 0x3288));
      }
      break;
    case 0xc77:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x328c)) {
        byteOffset = 0;
        do {
          dVar7 = (double)*(float *)(byteOffset + *(int *)(glContext + 0x3260)) * uint32MaxAsDouble;
          if (twoPow31 <= dVar7) {
            uVar5 = (int)(dVar7 - twoPow31) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(byteOffset + values) = uVar5;
          loopIndex = loopIndex + 1;
          byteOffset = byteOffset + 4;
        } while (loopIndex < *(int *)(glContext + 0x328c));
      }
      break;
    case 0xc78:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3290)) {
        byteOffset = 0;
        do {
          dVar7 = (double)*(float *)(byteOffset + *(int *)(glContext + 0x3264)) * uint32MaxAsDouble;
          if (twoPow31 <= dVar7) {
            uVar5 = (int)(dVar7 - twoPow31) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(byteOffset + values) = uVar5;
          loopIndex = loopIndex + 1;
          byteOffset = byteOffset + 4;
        } while (loopIndex < *(int *)(glContext + 0x3290));
      }
      break;
    case 0xc79:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3294)) {
        byteOffset = 0;
        do {
          dVar7 = (double)*(float *)(byteOffset + *(int *)(glContext + 0x3268)) * uint32MaxAsDouble;
          if (twoPow31 <= dVar7) {
            uVar5 = (int)(dVar7 - twoPow31) ^ 0x80000000;
          }
          else {
            uVar5 = (uint)(int)dVar7;
          }
          *(uint *)(byteOffset + values) = uVar5;
          loopIndex = loopIndex + 1;
          byteOffset = byteOffset + 4;
        } while (loopIndex < *(int *)(glContext + 0x3294));
      }
    }
  }
  else {
LAB_0007c964:
    if (*(int *)(glContext + 0x7574) == 0) {
      glErrorCode = 0x502;
LAB_0007c974:
      *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    }
  }
  return;
}

/* _glGetPixelMapusv_Exec @ 0x7ce48 (1136 bytes) */
void _glGetPixelMapusv_Exec(glContext, map, values)
  int glContext;
  undefined4 map;
  undefined2 *values;
{
  float float65535;
  int mapSize;
  int byteOffset;
  undefined4 glErrorCode;
  int pixelPackBuffer;
  int loopIndex;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    pixelPackBuffer = *(int *)(glContext + 0x4a68);
    if (pixelPackBuffer != 0) {
      switch(map) {
      case 0xc70:
        mapSize = *(int *)(glContext + 0x3270);
        break;
      case 0xc71:
        mapSize = *(int *)(glContext + 0x3274);
        break;
      case 0xc72:
        mapSize = *(int *)(glContext + 0x3278);
        break;
      case 0xc73:
        mapSize = *(int *)(glContext + 0x327c);
        break;
      case 0xc74:
        mapSize = *(int *)(glContext + 0x3280);
        break;
      case 0xc75:
        mapSize = *(int *)(glContext + 0x3284);
        break;
      case 0xc76:
        mapSize = *(int *)(glContext + 0x3288);
        break;
      case 0xc77:
        mapSize = *(int *)(glContext + 0x328c);
        break;
      case 0xc78:
        mapSize = *(int *)(glContext + 0x3290);
        break;
      case 0xc79:
        mapSize = *(int *)(glContext + 0x3294);
        break;
      default:
        goto switchD_0007cea8_default;
      }
      if ((*(int *)(pixelPackBuffer + 0x38) < (int)(values + mapSize)) || (((uint)values & 1) != 0))
      goto LAB_0007cf38;
      if (*(int *)(pixelPackBuffer + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,pixelPackBuffer + 0x10);
      }
      values = (undefined2 *)((int)values + *(int *)(pixelPackBuffer + 0x30));
    }
    float65535 = FLOAT_00108ea0;
    switch(map) {
    case 0xc70:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3270)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *values = *(undefined2 *)(byteOffset + *(int *)(glContext + 0x3248) + 2);
          values = values + 1;
        } while (loopIndex < *(int *)(glContext + 0x3270));
      }
      break;
    case 0xc71:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3274)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *values = *(undefined2 *)(byteOffset + *(int *)(glContext + 0x326c) + 2);
          values = values + 1;
        } while (loopIndex < *(int *)(glContext + 0x3274));
      }
      break;
    case 0xc72:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3278)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *values = (short)(int)(*(float *)(byteOffset + *(int *)(glContext + 0x324c)) * float65535);
          values = values + 1;
        } while (loopIndex < *(int *)(glContext + 0x3278));
      }
      break;
    case 0xc73:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x327c)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *values = (short)(int)(*(float *)(byteOffset + *(int *)(glContext + 0x3250)) * float65535);
          values = values + 1;
        } while (loopIndex < *(int *)(glContext + 0x327c));
      }
      break;
    case 0xc74:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3280)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *values = (short)(int)(*(float *)(byteOffset + *(int *)(glContext + 0x3254)) * float65535);
          values = values + 1;
        } while (loopIndex < *(int *)(glContext + 0x3280));
      }
      break;
    case 0xc75:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3284)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *values = (short)(int)(*(float *)(byteOffset + *(int *)(glContext + 0x3258)) * float65535);
          values = values + 1;
        } while (loopIndex < *(int *)(glContext + 0x3284));
      }
      break;
    case 0xc76:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3288)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *values = (short)(int)(*(float *)(byteOffset + *(int *)(glContext + 0x325c)) * float65535);
          values = values + 1;
        } while (loopIndex < *(int *)(glContext + 0x3288));
      }
      break;
    case 0xc77:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x328c)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *values = (short)(int)(*(float *)(byteOffset + *(int *)(glContext + 0x3260)) * float65535);
          values = values + 1;
        } while (loopIndex < *(int *)(glContext + 0x328c));
      }
      break;
    case 0xc78:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3290)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *values = (short)(int)(*(float *)(byteOffset + *(int *)(glContext + 0x3264)) * float65535);
          values = values + 1;
        } while (loopIndex < *(int *)(glContext + 0x3290));
      }
      break;
    case 0xc79:
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3294)) {
        do {
          byteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *values = (short)(int)(*(float *)(byteOffset + *(int *)(glContext + 0x3268)) * float65535);
          values = values + 1;
        } while (loopIndex < *(int *)(glContext + 0x3294));
      }
      break;
    default:
switchD_0007cea8_default:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_0007d2f0;
    }
  }
  else {
LAB_0007cf38:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0007d2f0:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glPixelStoref_Exec @ 0x7d308 (1156 bytes) */
void _glPixelStoref_Exec(int glContext,uint pname,float param)
{
  undefined4 glErrorCode;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(glContext + 0x7574) = 0x502;
    return;
  }
  if (pname == 0xd02) {
    if (!(param < (double)FLOAT_00108e50)) {
      *(int *)(glContext + 0x31b0) = (int)(param + (double)FLOAT_00108e90);
      goto LAB_0007d77c;
    }
LAB_0007d734:
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_0007d77c;
    glErrorCode = 0x501;
  }
  else {
    if (pname < 0xd03) {
      if (pname == 0xcf3) {
        if (!(param < (double)FLOAT_00108e50)) {
          *(int *)(glContext + 0x31d4) = (int)(param + (double)FLOAT_00108e90);
          goto LAB_0007d77c;
        }
      }
      else if (pname < 0xcf4) {
        if (pname == 0xcf1) {
          *(bool *)(glContext + 0x31e5) = param != (double)FLOAT_00108e50;
          goto LAB_0007d77c;
        }
        if (pname < 0xcf2) {
          if (pname == 0xcf0) {
            *(bool *)(glContext + 0x31e4) = param != (double)FLOAT_00108e50;
            goto LAB_0007d77c;
          }
          goto LAB_0007d768;
        }
        if (!(param < (double)FLOAT_00108e50)) {
          *(int *)(glContext + 0x31cc) = (int)(param + (double)FLOAT_00108e90);
          goto LAB_0007d77c;
        }
      }
      else if (pname == 0xcf5) {
        if ((((param == (double)FLOAT_00108e54) || (param == (double)FLOAT_00108ea4)) ||
            (param == (double)FLOAT_00108ea8)) || (param == (double)FLOAT_00108eac)) {
          *(int *)(glContext + 0x31e0) = (int)(param + (double)FLOAT_00108e90);
          goto LAB_0007d77c;
        }
      }
      else if (pname < 0xcf5) {
        if (!(param < (double)FLOAT_00108e50)) {
          *(int *)(glContext + 0x31d8) = (int)(param + (double)FLOAT_00108e90);
          goto LAB_0007d77c;
        }
      }
      else if (pname == 0xd00) {
        if (!(param < (double)FLOAT_00108e50)) {
          *(bool *)(glContext + 0x31c8) = param != (double)FLOAT_00108e50;
          goto LAB_0007d77c;
        }
      }
      else {
        if (pname != 0xd01) goto LAB_0007d768;
        if (!(param < (double)FLOAT_00108e50)) {
          *(bool *)(glContext + 0x31c9) = param != (double)FLOAT_00108e50;
          goto LAB_0007d77c;
        }
      }
      goto LAB_0007d734;
    }
    if (pname == 0x806b) {
      if (!(param < (double)FLOAT_00108e50)) {
        *(int *)(glContext + 0x31c0) = (int)(param + (double)FLOAT_00108e90);
        goto LAB_0007d77c;
      }
      goto LAB_0007d734;
    }
    if (0x806b < pname) {
      if (pname == 0x806d) {
        if (!(param < (double)FLOAT_00108e50)) {
          *(int *)(glContext + 0x31dc) = (int)(param + (double)FLOAT_00108e90);
          goto LAB_0007d77c;
        }
      }
      else if (pname < 0x806d) {
        if (!(param < (double)FLOAT_00108e50)) {
          *(int *)(0x31b4 + glContext) = (int)(param + (double)FLOAT_00108e90);
          goto LAB_0007d77c;
        }
      }
      else {
        if (pname != 0x806e) {
          if (pname == 0x85b2) {
            *(bool *)(glContext + 0x31e6) = param != (double)FLOAT_00108e50;
            goto LAB_0007d77c;
          }
          goto LAB_0007d768;
        }
        if (!(param < (double)FLOAT_00108e50)) {
          *(int *)(glContext + 0x31d0) = (int)(param + (double)FLOAT_00108e90);
          goto LAB_0007d77c;
        }
      }
      goto LAB_0007d734;
    }
    if (pname == 0xd04) {
      if (!(param < (double)FLOAT_00108e50)) {
        *(int *)(glContext + 0x31bc) = (int)(param + (double)FLOAT_00108e90);
        goto LAB_0007d77c;
      }
      goto LAB_0007d734;
    }
    if (pname < 0xd04) {
      if (!(param < (double)FLOAT_00108e50)) {
        *(int *)(glContext + 0x31b8) = (int)(param + (double)FLOAT_00108e90);
        goto LAB_0007d77c;
      }
      goto LAB_0007d734;
    }
    if (pname == 0xd05) {
      if (((param == (double)FLOAT_00108e54) || (param == (double)FLOAT_00108ea4)) ||
         ((param == (double)FLOAT_00108ea8 || (param == (double)FLOAT_00108eac)))) {
        *(int *)(glContext + 0x31c4) = (int)(param + (double)FLOAT_00108e90);
        goto LAB_0007d77c;
      }
      goto LAB_0007d734;
    }
LAB_0007d768:
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_0007d77c;
    glErrorCode = 0x500;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_0007d77c:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200000;
  return;
}

/* _glPixelTransferf_ListExec @ 0x7d78c (44 bytes) */
int _glPixelTransferf_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glPixelTransferf_Exec)(glContext,*listRecord,(double)GH_U2F((unsigned int)(listRecord[1])));
  return 8;
}

/* _glPixelTransferf_Comp @ 0x7d7b8 (92 bytes) */
undefined4 * _glPixelTransferf_Comp(undefined4 glContext,undefined4 pname,float param)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glPixelTransferf_ListExec_00110254,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = (float)param;
    *listRecord = pname;
  }
  return listRecord;
}

/* _glPixelTransferf_Exec @ 0x7d814 (1740 bytes) */
void _glPixelTransferf_Exec(int glContext,uint pname,float param)
{
  undefined4 glErrorCode;
  uint nonDefaultFlags;
  uint transferBit;
  float defaultValue;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0007de90;
  }
  if (pname == 0x8022) {
    *(float *)(glContext + 0x33a4) = (float)param;
    defaultValue = (double)FLOAT_00108e50;
    transferBit = 0x40000000;
  }
  else {
    if (0x8022 < pname) {
      if (pname == 0x870f) {
        *(float *)(glContext + 0x3224) = (float)param;
        defaultValue = (double)FLOAT_00108e54;
        transferBit = 4;
      }
      else {
        if (pname < 0x8710) {
          if (pname == 0x80b7) {
            *(float *)(glContext + 0x3374) = (float)param;
            defaultValue = (double)FLOAT_00108e54;
            transferBit = 0x80000;
          }
          else if (pname < 0x80b8) {
            if (pname == 0x80b4) {
              *(float *)(glContext + 0x335c) = (float)param;
              defaultValue = (double)FLOAT_00108e54;
              transferBit = 0x10000;
            }
            else if (pname < 0x80b5) {
              if (pname != 0x8023) goto LAB_0007de80;
              *(float *)(glContext + 0x33ac) = (float)param;
              defaultValue = (double)FLOAT_00108e50;
              transferBit = 0x80000000;
            }
            else if (pname == 0x80b5) {
              *(float *)(glContext + 0x336c) = (float)param;
              defaultValue = (double)FLOAT_00108e54;
              transferBit = 0x20000;
            }
            else {
              if (pname != 0x80b6) goto LAB_0007de80;
              *(float *)(glContext + 0x3364) = (float)param;
              defaultValue = (double)FLOAT_00108e54;
              transferBit = 0x40000;
            }
          }
          else if (pname == 0x80ba) {
            *(float *)(glContext + 0x3370) = (float)param;
            defaultValue = (double)FLOAT_00108e50;
            transferBit = 0x400000;
          }
          else if (pname < 0x80bb) {
            if (pname == 0x80b8) {
              *(float *)(glContext + 0x3360) = (float)param;
              defaultValue = (double)FLOAT_00108e50;
              transferBit = 0x100000;
            }
            else {
              if (pname != 0x80b9) goto LAB_0007de80;
              *(float *)(glContext + 0x3368) = (float)param;
              defaultValue = (double)FLOAT_00108e50;
              transferBit = 0x200000;
            }
          }
          else {
            if (pname != 0x80bb) {
              if (pname == 0x870e) {
                *(float *)(glContext + 0x321c) = (float)param;
                defaultValue = (double)FLOAT_00108e54;
                transferBit = 1;
                goto LAB_0007deb8;
              }
              goto LAB_0007de80;
            }
            *(float *)(glContext + 0x3378) = (float)param;
            defaultValue = (double)FLOAT_00108e50;
            transferBit = 0x800000;
          }
          goto LAB_0007de98;
        }
        if (pname == 0x8714) {
          *(float *)(glContext + 0x3218) = (float)param;
          defaultValue = (double)FLOAT_00108e50;
          transferBit = 2;
        }
        else if (pname < 0x8715) {
          if (pname == 0x8711) {
            *(float *)(glContext + 0x3234) = (float)param;
            defaultValue = (double)FLOAT_00108e54;
            transferBit = 0x40;
          }
          else if (pname < 0x8711) {
            *(float *)(glContext + 0x322c) = (float)param;
            defaultValue = (double)FLOAT_00108e54;
            transferBit = 0x10;
          }
          else if (pname == 0x8712) {
            *(float *)(glContext + 0x323c) = (float)param;
            defaultValue = (double)FLOAT_00108e54;
            transferBit = 0x100;
          }
          else {
            if (pname != 0x8713) goto LAB_0007de80;
            *(float *)(glContext + 0x3244) = (float)param;
            defaultValue = (double)FLOAT_00108e54;
            transferBit = 0x400;
          }
        }
        else if (pname == 0x8717) {
          *(float *)(glContext + 0x3230) = (float)param;
          defaultValue = (double)FLOAT_00108e50;
          transferBit = 0x80;
        }
        else if (pname < 0x8718) {
          if (pname == 0x8715) {
            *(float *)(glContext + 0x3220) = (float)param;
            defaultValue = (double)FLOAT_00108e50;
            transferBit = 8;
          }
          else {
            if (pname != 0x8716) goto LAB_0007de80;
            *(float *)(glContext + 0x3228) = (float)param;
            defaultValue = (double)FLOAT_00108e50;
            transferBit = 0x20;
          }
        }
        else if (pname == 0x8718) {
          *(float *)(glContext + 0x3238) = (float)param;
          defaultValue = (double)FLOAT_00108e50;
          transferBit = 0x200;
        }
        else {
          if (pname != 0x8719) goto LAB_0007de80;
          *(float *)(glContext + 0x3240) = (float)param;
          defaultValue = (double)FLOAT_00108e50;
          transferBit = 0x800;
        }
      }
LAB_0007deb8:
      nonDefaultFlags = *(uint *)(glContext + 0x3418) & ~transferBit;
      if (param != (double)defaultValue) {
        nonDefaultFlags = nonDefaultFlags | transferBit;
      }
      *(uint *)(glContext + 0x3418) = nonDefaultFlags;
      goto LAB_0007ded0;
    }
    if (pname == 0xd1b) {
      *(float *)(glContext + 0x31f8) = (float)param;
      defaultValue = (double)FLOAT_00108e50;
      transferBit = 0x400;
    }
    else if (pname < 0xd1c) {
      if (pname == 0xd14) {
        *(float *)(glContext + 0x31ec) = (float)param;
        defaultValue = (double)FLOAT_00108e54;
        transferBit = 0x10;
      }
      else if (pname < 0xd15) {
        if (pname == 0xd11) {
          defaultValue = (double)FLOAT_00108e50;
          transferBit = 2;
        }
        else if (pname < 0xd12) {
          if (pname != 0xd10) {
LAB_0007de80:
            if (*(int *)(glContext + 0x7574) != 0) {
              return;
            }
            glErrorCode = 0x500;
LAB_0007de90:
            *(undefined4 *)(glContext + 0x7574) = glErrorCode;
            return;
          }
          defaultValue = (double)FLOAT_00108e50;
          transferBit = 1;
        }
        else if (pname == 0xd12) {
          defaultValue = (double)FLOAT_00108e50;
          transferBit = 4;
          *(int *)(glContext + 0x3214) = (int)(param + (double)FLOAT_00108e90);
        }
        else {
          if (pname != 0xd13) goto LAB_0007de80;
          defaultValue = (double)FLOAT_00108e50;
          transferBit = 8;
          *(int *)(glContext + 0x3210) = (int)(param + (double)FLOAT_00108e90);
        }
      }
      else if (pname == 0xd18) {
        *(float *)(glContext + 0x31f4) = (float)param;
        defaultValue = (double)FLOAT_00108e54;
        transferBit = 0x20;
      }
      else if (pname < 0xd19) {
        if (pname != 0xd15) goto LAB_0007de80;
        *(float *)(glContext + 0x31e8) = (float)param;
        defaultValue = (double)FLOAT_00108e50;
        transferBit = 0x100;
      }
      else if (pname == 0xd19) {
        *(float *)(glContext + 0x31f0) = (float)param;
        defaultValue = (double)FLOAT_00108e50;
        transferBit = 0x200;
      }
      else {
        if (pname != 0xd1a) goto LAB_0007de80;
        *(float *)(glContext + 0x31fc) = (float)param;
        defaultValue = (double)FLOAT_00108e54;
        transferBit = 0x40;
      }
    }
    else if (pname == 0x801c) {
      *(float *)(glContext + 0x3390) = (float)param;
      defaultValue = (double)FLOAT_00108e54;
      transferBit = 0x1000000;
    }
    else if (pname < 0x801d) {
      if (pname == 0xd1d) {
        *(float *)(glContext + 0x3200) = (float)param;
        defaultValue = (double)FLOAT_00108e50;
        transferBit = 0x800;
      }
      else if (pname < 0xd1d) {
        *(float *)(glContext + 0x3204) = (float)param;
        defaultValue = (double)FLOAT_00108e54;
        transferBit = 0x80;
      }
      else if (pname == 0xd1e) {
        *(float *)(glContext + 0x320c) = (float)param;
        defaultValue = (double)FLOAT_00108e54;
        transferBit = 0x1000;
      }
      else {
        if (pname != 0xd1f) goto LAB_0007de80;
        *(float *)(glContext + 0x3208) = (float)param;
        defaultValue = (double)FLOAT_00108e50;
        transferBit = 0x2000;
      }
    }
    else if (pname == 0x801f) {
      *(float *)(glContext + 0x33a8) = (float)param;
      defaultValue = (double)FLOAT_00108e54;
      transferBit = 0x8000000;
    }
    else if (pname < 0x8020) {
      if (pname == 0x801d) {
        *(float *)(glContext + 0x33a0) = (float)param;
        defaultValue = (double)FLOAT_00108e54;
        transferBit = 0x2000000;
      }
      else {
        if (pname != 0x801e) goto LAB_0007de80;
        *(float *)(glContext + 0x3398) = (float)param;
        defaultValue = (double)FLOAT_00108e54;
        transferBit = 0x4000000;
      }
    }
    else if (pname == 0x8020) {
      *(float *)(glContext + 0x3394) = (float)param;
      defaultValue = (double)FLOAT_00108e50;
      transferBit = 0x10000000;
    }
    else {
      if (pname != 0x8021) goto LAB_0007de80;
      *(float *)(glContext + 0x339c) = (float)param;
      defaultValue = (double)FLOAT_00108e50;
      transferBit = 0x20000000;
    }
  }
LAB_0007de98:
  nonDefaultFlags = *(uint *)(glContext + 0x3414) & ~transferBit;
  if (param != (double)defaultValue) {
    nonDefaultFlags = nonDefaultFlags | transferBit;
  }
  *(uint *)(glContext + 0x3414) = nonDefaultFlags;
LAB_0007ded0:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200000;
  return;
}

/* _glPixelTransferf_CompExec @ 0x7dee0 (72 bytes) */
void _glPixelTransferf_CompExec(undefined4 glContext,undefined4 pname,float param)
{
  ((undefined4 * (*)())_glPixelTransferf_Comp)(glContext,pname,param);
  ((void (*)())_glPixelTransferf_Exec)(glContext,pname,param);
  return;
}

/* _glPixelTransferi_ListExec @ 0x7df28 (44 bytes) */
int _glPixelTransferi_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glPixelTransferi_Exec(glContext,*listRecord,listRecord[1]);
  return 8;
}

/* _glPixelTransferi_Comp @ 0x7df54 (84 bytes) */
int _glPixelTransferi_Comp(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glPixelTransferi_ListExec_00110250,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = param;
    *listRecord = pname;
  }
  return listRecord;
}

