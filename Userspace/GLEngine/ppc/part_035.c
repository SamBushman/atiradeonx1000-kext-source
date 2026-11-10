#include "decls.h"

/* _glWeightubvARB_Comp @ 0xab750 (200 bytes) */
int _glWeightubvARB_Comp(param_1, param_2, param_3)
  uint param_1;
  uint param_2;
  uint param_3;
{
  byte *pbVar1;
  float fVar2;
  int iVar3;
  
  if ((int)param_2 < 5) {
    param_1 = _gleAddListItem(param_1,PTR__glWeightARB_ListExec_0011045c,param_2 * 4 + 4);
    if ((float *)param_1 != (float *)0x0) {
      iVar3 = 0;
      *(uint *)param_1 = param_2;
      fVar2 = FLOAT_00108e78;
      if (0 < (int)param_2) {
        param_1 = param_1 + 4;
        do {
          pbVar1 = (byte *)(param_3 + iVar3);
          iVar3 = iVar3 + 1;
          *(float *)param_1 = (GH_U2F((unsigned int)((*pbVar1 | 0x4b000000))) - 8388608.0) * fVar2;
          param_1 = param_1 + 4;
          param_2 = param_2 - 1;
        } while (param_2 != 0);
      }
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return param_1;
}

/* _glWeightubvARB_CompExec @ 0xab818 (64 bytes) */
void _glWeightubvARB_CompExec(param_1, param_2, param_3)
  uint param_1;
  uint param_2;
  uint param_3;
{
  ((int (*)())_glWeightubvARB_Comp)(param_1,param_2,param_3);
  _glWeightubvARB_Exec(param_1,param_2,param_3);
  return;
}

/* _glWeightusvARB_Exec @ 0xab858 (176 bytes) */
double _glWeightusvARB_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  ushort *param_3;
{
  ushort uVar1;
  int iVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  
  fVar3 = FLOAT_00108e74;
  if (4 < param_2) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
      return;
    }
    return;
  }
  iVar5 = 0;
  if (0 < param_2) {
    pfVar4 = (float *)(param_1 + 0x2d0);
    iVar5 = param_2;
    do {
      uVar1 = *param_3;
      param_3 = param_3 + 1;
      *pfVar4 = (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * fVar3;
      pfVar4 = pfVar4 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar5 = param_2;
    if (3 < param_2) {
      return;
    }
  }
  do {
    iVar2 = iVar5 * 4;
    iVar5 = iVar5 + 1;
    *(undefined4 *)(iVar2 + param_1 + 0x2d0) = 0;
  } while (iVar5 < 4);
  return;
}

/* _glWeightusvARB_Comp @ 0xab908 (200 bytes) */
int _glWeightusvARB_Comp(param_1, param_2, param_3)
  uint param_1;
  uint param_2;
  uint param_3;
{
  ushort uVar1;
  float fVar2;
  
  if ((int)param_2 < 5) {
    param_1 = _gleAddListItem(param_1,PTR__glWeightARB_ListExec_0011045c,param_2 * 4 + 4);
    if (((float *)param_1 != (float *)0x0) &&
       (*(uint *)param_1 = param_2, fVar2 = FLOAT_00108e74, 0 < (int)param_2)) {
      param_1 = param_1 + 4;
      do {
        uVar1 = *(ushort *)param_3;
        param_3 = param_3 + 2;
        *(float *)param_1 = (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * fVar2;
        param_1 = param_1 + 4;
        param_2 = param_2 - 1;
      } while (param_2 != 0);
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return param_1;
}

/* _glWeightusvARB_CompExec @ 0xab9d0 (64 bytes) */
void _glWeightusvARB_CompExec(param_1, param_2, param_3)
  uint param_1;
  uint param_2;
  uint param_3;
{
  ((int (*)())_glWeightusvARB_Comp)(param_1,param_2,param_3);
  ((double (*)())_glWeightusvARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glWeightuivARB_Exec @ 0xaba10 (176 bytes) */
double _glWeightuivARB_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  int iVar1;
  double dVar2;
  float fVar3;
  undefined4 uVar4;
  float *pfVar5;
  int iVar6;
  
  fVar3 = FLOAT_00108e6c;
  dVar2 = DOUBLE_00108d70;
  if (4 < param_2) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
      return;
    }
    return;
  }
  iVar6 = 0;
  if (0 < param_2) {
    pfVar5 = (float *)(param_1 + 0x2d0);
    do {
      uVar4 = *param_3;
      iVar6 = iVar6 + 1;
      param_3 = param_3 + 1;
      *pfVar5 = (float)((double)CONCAT44(0x43300000,uVar4) - dVar2) * fVar3;
      pfVar5 = pfVar5 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    if (3 < iVar6) {
      return;
    }
  }
  do {
    iVar1 = iVar6 * 4;
    iVar6 = iVar6 + 1;
    *(undefined4 *)(iVar1 + param_1 + 0x2d0) = 0;
  } while (iVar6 < 4);
  return;
}

/* _glWeightuivARB_Comp @ 0xabac0 (200 bytes) */
int _glWeightuivARB_Comp(param_1, param_2, param_3)
  uint param_1;
  uint param_2;
  uint param_3;
{
  double dVar1;
  float fVar2;
  undefined4 uVar3;
  
  if ((int)param_2 < 5) {
    param_1 = _gleAddListItem(param_1,PTR__glWeightARB_ListExec_0011045c,param_2 * 4 + 4);
    if (((float *)param_1 != (float *)0x0) &&
       (*(uint *)param_1 = param_2, fVar2 = FLOAT_00108e6c, dVar1 = DOUBLE_00108d70,
       0 < (int)param_2)) {
      param_1 = param_1 + 4;
      do {
        uVar3 = *(undefined4 *)param_3;
        param_3 = param_3 + 4;
        *(float *)param_1 = (float)((double)CONCAT44(0x43300000,uVar3) - dVar1) * fVar2;
        param_1 = param_1 + 4;
        param_2 = param_2 - 1;
      } while (param_2 != 0);
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return param_1;
}

/* _glWeightuivARB_CompExec @ 0xabb88 (64 bytes) */
void _glWeightuivARB_CompExec(param_1, param_2, param_3)
  uint param_1;
  uint param_2;
  uint param_3;
{
  ((int (*)())_glWeightuivARB_Comp)(param_1,param_2,param_3);
  ((double (*)())_glWeightuivARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexBlendARB_Exec @ 0xabbc8 (104 bytes) */
void _glVertexBlendARB_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 - 1U < 4) {
    *(char *)(param_1 + 0x4660) = (char)param_2;
    _gleUpdateInverseNeeds(param_1);
    _gleSelectVertexSubmitFunc(param_1);
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x200000;
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexBlendARB_Comp @ 0xabc30 (76 bytes) */
int _glVertexBlendARB_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexBlendARB_ListExec_00110458,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glVertexBlendARB_CompExec @ 0xabc7c (56 bytes) */
void _glVertexBlendARB_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glVertexBlendARB_Comp)(param_1,param_2);
  ((void (*)())_glVertexBlendARB_Exec)(param_1,param_2);
  return;
}

/* _glVertexBlendARB_ListExec @ 0xabcb4 (40 bytes) */
int _glVertexBlendARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glVertexBlendARB_Exec)(param_1,*param_2);
  return 4;
}

/* _glBindVertexArrayEXT_Exec @ 0xabcdc (168 bytes) */
void _glBindVertexArrayEXT_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    return;
  }
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
    _gleBindVertexArray(param_1,param_2);
    return;
  }
  iVar1 = *(int *)(param_1 + 0x5148) + 0x8028;
  _pthread_mutex_lock(iVar1);
  _gleBindVertexArray(param_1,param_2);
  _pthread_mutex_unlock(iVar1);
  return;
}

/* _glBindVertexArrayEXT_Comp @ 0xabd84 (76 bytes) */
int _glBindVertexArrayEXT_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glBindVertexArrayEXT_ListExec_00110460,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glBindVertexArrayEXT_CompExec @ 0xabdd0 (56 bytes) */
void _glBindVertexArrayEXT_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glBindVertexArrayEXT_Comp)(param_1,param_2);
  ((void (*)())_glBindVertexArrayEXT_Exec)(param_1,param_2);
  return;
}

/* _glBindVertexArrayEXT_ListExec @ 0xabe08 (40 bytes) */
int _glBindVertexArrayEXT_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glBindVertexArrayEXT_Exec)(param_1,*param_2);
  return 4;
}

/* _glDeleteVertexArraysEXT_Exec @ 0xabe30 (272 bytes) */
void _glDeleteVertexArraysEXT_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (0 < param_2) {
        do {
          iVar2 = *param_3;
          param_3 = param_3 + 1;
          if (iVar2 != 0) {
            if (iVar2 == *(int *)(*(int *)(param_1 + 0x4a60) + 4)) {
              _gleBindVertexArray(param_1,0);
            }
            _gleDeleteHashNameAndObject(param_1,*(int *)(param_1 + 0x5148) + 0x5014,iVar2);
          }
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
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

/* _glGenVertexArraysEXT_Exec @ 0xabf40 (236 bytes) */
void _glGenVertexArraysEXT_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      iVar4 = *(int *)(param_1 + 0x5148);
      if (*(char *)(iVar4 + 0x8024) != '\0') {
        _pthread_mutex_lock(iVar4 + 0x8028);
        iVar4 = *(int *)(param_1 + 0x5148);
      }
      iVar4 = _gleGenHashNames(iVar4 + 0x5014,param_2);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (iVar4 == 0) {
        return;
      }
      iVar3 = 0;
      if (param_2 < 1) {
        return;
      }
      do {
        iVar2 = iVar3 + iVar4;
        iVar3 = iVar3 + 1;
        *param_3 = iVar2;
        param_3 = param_3 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
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

/* _glIsVertexArrayEXT_Exec @ 0xac02c (168 bytes) */
int _glIsVertexArrayEXT_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  bool bVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar1 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar1 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar1 + 0x8028);
      iVar1 = *(int *)(param_1 + 0x5148);
    }
    iVar1 = _gleLookupHashObject(iVar1 + 0x5014,param_2);
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
    bVar2 = iVar1 != 0;
  }
  else {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    bVar2 = false;
  }
  return bVar2;
}

/* _glVertexAttrib1sARB_Exec @ 0xac0d4 (236 bytes) */
void _glVertexAttrib1sARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  float fVar1;
  int iVar2;
  code *pcVar3;
  double dVar4;
  
  if (param_2 < 0x10) {
    fVar1 = *(float *)(param_1 + 0x20);
    if (param_2 == 0) {
      pcVar3 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar3)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                       DOUBLE_00108d58),(double)fVar1,(double)fVar1);
    }
    else {
      iVar2 = param_1 + param_2 * 0x10;
      dVar4 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58;
      *(undefined4 *)(iVar2 + 0x1ac) = *(undefined4 *)(param_1 + 0x24);
      *(float *)(iVar2 + 0x1a8) = fVar1;
      *(float *)(iVar2 + 0x1a4) = fVar1;
      *(float *)(iVar2 + 0x1a0) = (float)dVar4;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib1sARB_Comp @ 0xac1c0 (84 bytes) */
int _glVertexAttrib1sARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib1svARB_ListExec_001104c4,6);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined2 *)(puVar1 + 1) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glVertexAttrib1sARB_CompExec @ 0xac214 (64 bytes) */
void _glVertexAttrib1sARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertexAttrib1sARB_Comp)(param_1,param_2,param_3);
  ((void (*)())_glVertexAttrib1sARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib1fARB_Exec @ 0xac254 (136 bytes) */
void _glVertexAttrib1fARB_Exec(int param_1,uint param_2,float fparam_1)
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
      *(float *)(iVar3 + 0x1a0) = (float)fparam_1;
      *(undefined4 *)(iVar3 + 0x1ac) = uVar2;
      *(float *)(iVar3 + 0x1a8) = fVar1;
      *(float *)(iVar3 + 0x1a4) = fVar1;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int,double,double,double))UNRECOVERED_JUMPTABLE))(param_1, param_2, fparam_1, (double)fVar1, (double)fVar1);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib1fARB_Comp @ 0xac2dc (92 bytes) */
undefined4 * _glVertexAttrib1fARB_Comp(undefined4 param_1,undefined4 param_2,float fparam_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib1fvARB_ListExec_001104c0,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = (float)fparam_1;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glVertexAttrib1fARB_CompExec @ 0xac338 (72 bytes) */
void _glVertexAttrib1fARB_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1)
{
  ((undefined4 * (*)())_glVertexAttrib1fARB_Comp)(param_1,param_2,fparam_1);
  ((void (*)())_glVertexAttrib1fARB_Exec)(param_1,param_2,fparam_1);
  return;
}

/* _glVertexAttrib1dARB_Exec @ 0xac380 (144 bytes) */
void _glVertexAttrib1dARB_Exec(int param_1,uint param_2,double fparam_1)
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
      *(float *)(iVar3 + 0x1a0) = (float)fparam_1;
      *(undefined4 *)(iVar3 + 0x1ac) = uVar2;
      *(float *)(iVar3 + 0x1a8) = fVar1;
      *(float *)(iVar3 + 0x1a4) = fVar1;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int,double,double,double))UNRECOVERED_JUMPTABLE))(param_1, param_2, (double)(float)fparam_1, (double)fVar1, (double)fVar1);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib1dARB_Comp @ 0xac410 (92 bytes) */
undefined4 * _glVertexAttrib1dARB_Comp(undefined4 param_1,undefined4 param_2,double fparam_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib1dvARB_ListExec_001104bc,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *(double *)(puVar1 + 1) = fparam_1;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glVertexAttrib1dARB_CompExec @ 0xac46c (72 bytes) */
void _glVertexAttrib1dARB_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1)
{
  ((undefined4 * (*)())_glVertexAttrib1dARB_Comp)(param_1,param_2,fparam_1);
  ((void (*)())_glVertexAttrib1dARB_Exec)(param_1,param_2,fparam_1);
  return;
}

/* _glVertexAttrib2sARB_Exec @ 0xac4b4 (276 bytes) */
void _glVertexAttrib2sARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  undefined4 uVar1;
  undefined4 uVar2;
  double dVar3;
  int iVar4;
  code *pcVar5;
  
  dVar3 = DOUBLE_00108d58;
  if (param_2 < 0x10) {
    uVar1 = *(undefined4 *)(param_1 + 0x20);
    uVar2 = *(undefined4 *)(param_1 + 0x24);
    if (param_2 == 0) {
      pcVar5 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar5 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar5)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                       DOUBLE_00108d58),
                (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58)
               );
    }
    else {
      iVar4 = param_1 + param_2 * 0x10;
      *(float *)(iVar4 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
      *(undefined4 *)(iVar4 + 0x1ac) = uVar2;
      *(undefined4 *)(iVar4 + 0x1a8) = uVar1;
      *(float *)(iVar4 + 0x1a4) = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar3)
      ;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib2sARB_Comp @ 0xac5c8 (92 bytes) */
int _glVertexAttrib2sARB_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib2svARB_ListExec_001104b8,8);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined2 *)((int)puVar1 + 6) = (*(unsigned short *)((unsigned char *)&(param_4) + 2));
    *puVar1 = param_2;
    *(undefined2 *)(puVar1 + 1) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
  }
  return puVar1;
}

/* _glVertexAttrib2sARB_CompExec @ 0xac624 (72 bytes) */
void _glVertexAttrib2sARB_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glVertexAttrib2sARB_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glVertexAttrib2sARB_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glVertexAttrib2fARB_Exec @ 0xac66c (132 bytes) */
void _glVertexAttrib2fARB_Exec(int param_1,uint param_2,float fparam_1,float fparam_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 < 0x10) {
    uVar1 = *(undefined4 *)(param_1 + 0x20);
    uVar2 = *(undefined4 *)(param_1 + 0x24);
    if (param_2 != 0) {
      iVar3 = param_1 + param_2 * 0x10;
      *(float *)(iVar3 + 0x1a0) = (float)fparam_1;
      *(undefined4 *)(iVar3 + 0x1ac) = uVar2;
      *(float *)(iVar3 + 0x1a4) = (float)fparam_2;
      *(undefined4 *)(iVar3 + 0x1a8) = uVar1;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int))UNRECOVERED_JUMPTABLE))(param_1, param_2);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib2fARB_Comp @ 0xac6f0 (108 bytes) */
undefined4 * _glVertexAttrib2fARB_Comp(undefined4 param_1,undefined4 param_2,float fparam_1,float fparam_2)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib2fvARB_ListExec_001104b4,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = (float)fparam_2;
    *puVar1 = param_2;
    puVar1[1] = (float)fparam_1;
  }
  return puVar1;
}

/* _glVertexAttrib2fARB_CompExec @ 0xac75c (88 bytes) */
void _glVertexAttrib2fARB_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2)
{
  ((undefined4 * (*)())_glVertexAttrib2fARB_Comp)(param_1,param_2,fparam_1,fparam_2);
  ((void (*)())_glVertexAttrib2fARB_Exec)(param_1,param_2,fparam_1,fparam_2);
  return;
}

/* _glVertexAttrib2dARB_Exec @ 0xac7b4 (148 bytes) */
void _glVertexAttrib2dARB_Exec(int param_1,uint param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 < 0x10) {
    uVar1 = *(undefined4 *)(param_1 + 0x20);
    uVar2 = *(undefined4 *)(param_1 + 0x24);
    if (param_2 != 0) {
      iVar3 = param_1 + param_2 * 0x10;
      *(float *)(iVar3 + 0x1a0) = (float)fparam_1;
      *(undefined4 *)(iVar3 + 0x1ac) = uVar2;
      *(float *)(iVar3 + 0x1a4) = (float)fparam_2;
      *(undefined4 *)(iVar3 + 0x1a8) = uVar1;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int,double,double))UNRECOVERED_JUMPTABLE))(param_1, param_2, (double)(float)fparam_1, (double)(float)fparam_2);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib2dARB_Comp @ 0xac848 (108 bytes) */
undefined4 * _glVertexAttrib2dARB_Comp(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib2dvARB_ListExec_001104b0,0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *(double *)(puVar1 + 3) = fparam_2;
    *puVar1 = param_2;
    *(double *)(puVar1 + 1) = fparam_1;
  }
  return puVar1;
}

/* _glVertexAttrib2dARB_CompExec @ 0xac8b4 (88 bytes) */
void _glVertexAttrib2dARB_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2)
{
  undefined4 in_LR;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((undefined4 * (*)())_glVertexAttrib2dARB_Comp)(param_1,param_2,fparam_1,fparam_2);
  ((void (*)())_glVertexAttrib2dARB_Exec)(param_1,param_2,fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
  return;
}

/* _glVertexAttrib3sARB_Exec @ 0xac90c (316 bytes) */
void _glVertexAttrib3sARB_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  undefined4 uVar1;
  double dVar2;
  int iVar3;
  code *pcVar4;
  
  dVar2 = DOUBLE_00108d58;
  if (param_2 < 0x10) {
    uVar1 = *(undefined4 *)(param_1 + 0x24);
    if (param_2 == 0) {
      pcVar4 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar4 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar4)(param_1,0,param_3,param_4,param_5,*(int *)(param_1 + 0x4858),param_5 ^ 0x80000000,
                (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58)
                ,(double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58
                                ),
                (double)(float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_00108d58)
               );
    }
    else {
      iVar3 = param_1 + param_2 * 0x10;
      *(float *)(iVar3 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(iVar3 + 0x1a4) = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar2)
      ;
      *(undefined4 *)(iVar3 + 0x1ac) = uVar1;
      *(float *)(iVar3 + 0x1a8) = (float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar2)
      ;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib3sARB_Comp @ 0xaca48 (104 bytes) */
int _glVertexAttrib3sARB_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib3svARB_ListExec_001104ac,10);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined2 *)(puVar1 + 1) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
    *puVar1 = param_2;
    *(undefined2 *)(puVar1 + 2) = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
    *(undefined2 *)((int)puVar1 + 6) = (*(unsigned short *)((unsigned char *)&(param_4) + 2));
  }
  return puVar1;
}

/* _glVertexAttrib3sARB_CompExec @ 0xacab0 (80 bytes) */
void _glVertexAttrib3sARB_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glVertexAttrib3sARB_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((void (*)())_glVertexAttrib3sARB_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glVertexAttrib3fARB_Exec @ 0xacb00 (128 bytes) */
void _glVertexAttrib3fARB_Exec(int param_1,uint param_2,float fparam_1,float fparam_2,float fparam_3)
{
  undefined4 uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 < 0x10) {
    uVar1 = *(undefined4 *)(param_1 + 0x24);
    if (param_2 != 0) {
      iVar2 = param_1 + param_2 * 0x10;
      *(float *)(iVar2 + 0x1a0) = (float)fparam_1;
      *(undefined4 *)(iVar2 + 0x1ac) = uVar1;
      *(float *)(iVar2 + 0x1a4) = (float)fparam_2;
      *(float *)(iVar2 + 0x1a8) = (float)fparam_3;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int))UNRECOVERED_JUMPTABLE))(param_1, param_2);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib3fARB_Comp @ 0xacb80 (128 bytes) */
undefined4 * _glVertexAttrib3fARB_Comp(undefined4 param_1,undefined4 param_2,float fparam_1,float fparam_2,float fparam_3)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib3fvARB_ListExec_001104a8,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = (float)fparam_1;
    *puVar1 = param_2;
    puVar1[3] = (float)fparam_3;
    puVar1[2] = (float)fparam_2;
  }
  return puVar1;
}

/* _glVertexAttrib3fARB_CompExec @ 0xacc00 (104 bytes) */
void _glVertexAttrib3fARB_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3)
{
  ((undefined4 * (*)())_glVertexAttrib3fARB_Comp)(param_1,param_2,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glVertexAttrib3fARB_Exec)(param_1,param_2,fparam_1,fparam_2,fparam_3);
  return;
}

/* _glVertexAttrib3dARB_Exec @ 0xacc68 (152 bytes) */
void _glVertexAttrib3dARB_Exec(int param_1,uint param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  undefined4 uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 < 0x10) {
    uVar1 = *(undefined4 *)(param_1 + 0x24);
    if (param_2 != 0) {
      iVar2 = param_1 + param_2 * 0x10;
      *(float *)(iVar2 + 0x1a0) = (float)fparam_1;
      *(undefined4 *)(iVar2 + 0x1ac) = uVar1;
      *(float *)(iVar2 + 0x1a4) = (float)fparam_2;
      *(float *)(iVar2 + 0x1a8) = (float)fparam_3;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int,double,double,double))UNRECOVERED_JUMPTABLE))
              (param_1, param_2, (double)(float)fparam_1, (double)(float)fparam_2, (double)(float)fparam_3);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib3dARB_Comp @ 0xacd00 (128 bytes) */
undefined4 * _glVertexAttrib3dARB_Comp(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib3dvARB_ListExec_001104a4,0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *(double *)(puVar1 + 1) = fparam_1;
    *puVar1 = param_2;
    *(double *)(puVar1 + 5) = fparam_3;
    *(double *)(puVar1 + 3) = fparam_2;
  }
  return puVar1;
}

/* _glVertexAttrib3dARB_CompExec @ 0xacd80 (104 bytes) */
void _glVertexAttrib3dARB_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3)
{
  undefined4 in_LR;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((undefined4 * (*)())_glVertexAttrib3dARB_Comp)(param_1,param_2,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glVertexAttrib3dARB_Exec)(param_1,param_2,fparam_1,fparam_2,fparam_3,in_f4,in_f5,in_f6,in_f7,in_f8,
             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
  return;
}

/* _glVertexAttrib4sARB_Exec @ 0xacde8 (360 bytes) */
void _glVertexAttrib4sARB_Exec(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
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
      (*pcVar3)(param_1,0,param_3,param_4,param_5,*(int *)(param_1 + 0x4858),param_5 ^ 0x80000000,
                (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58)
                ,(double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58
                                ),
                (double)(float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_00108d58)
                ,(double)(float)((double)CONCAT44(0x43300000,param_6 ^ 0x80000000) - DOUBLE_00108d58
                                ));
    }
    else {
      iVar2 = param_1 + param_2 * 0x10;
      *(float *)(iVar2 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(iVar2 + 0x1a4) = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1)
      ;
      *(float *)(iVar2 + 0x1a8) = (float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar1)
      ;
      *(float *)(iVar2 + 0x1ac) = (float)((double)CONCAT44(0x43300000,param_6 ^ 0x80000000) - dVar1)
      ;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4sARB_Comp @ 0xacf50 (112 bytes) */
int _glVertexAttrib4sARB_Comp(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4svARB_ListExec_001104a0,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined2 *)(puVar1 + 1) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
    *puVar1 = param_2;
    *(undefined2 *)((int)puVar1 + 10) = (*(unsigned short *)((unsigned char *)&(param_6) + 2));
    *(undefined2 *)((int)puVar1 + 6) = (*(unsigned short *)((unsigned char *)&(param_4) + 2));
    *(undefined2 *)(puVar1 + 2) = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
  }
  return puVar1;
}

/* _glVertexAttrib4sARB_CompExec @ 0xacfc0 (88 bytes) */
void _glVertexAttrib4sARB_CompExec(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  ((int (*)())_glVertexAttrib4sARB_Comp)(param_1,param_2,param_3,param_4,param_5,param_6);
  ((void (*)())_glVertexAttrib4sARB_Exec)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* _glVertexAttrib4fARB_Exec @ 0xad018 (124 bytes) */
void _glVertexAttrib4fARB_Exec(int param_1,uint param_2,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 < 0x10) {
    if (param_2 != 0) {
      iVar1 = param_1 + param_2 * 0x10;
      *(float *)(iVar1 + 0x1a0) = (float)fparam_1;
      *(float *)(iVar1 + 0x1ac) = (float)fparam_4;
      *(float *)(iVar1 + 0x1a4) = (float)fparam_2;
      *(float *)(iVar1 + 0x1a8) = (float)fparam_3;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int))UNRECOVERED_JUMPTABLE))(param_1, param_2);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib4fARB_Comp @ 0xad094 (104 bytes) */
void _glVertexAttrib4fARB_Comp(undefined4 param_1,undefined4 param_2,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4fvARB_ListExec_0011049c,0x14);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = (float)fparam_1;
    *puVar1 = param_2;
    puVar1[4] = (float)fparam_4;
    puVar1[2] = (float)fparam_2;
    puVar1[3] = (float)fparam_3;
  }
  FUN_00008b68();
  return;
}

/* _glVertexAttrib4fARB_CompExec @ 0xad0fc (104 bytes) */
void _glVertexAttrib4fARB_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((void (*)())_glVertexAttrib4fARB_Comp)(param_1,param_2,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glVertexAttrib4fARB_Exec)(param_1,param_2,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glVertexAttrib4dARB_Exec @ 0xad164 (156 bytes) */
void _glVertexAttrib4dARB_Exec(int param_1,uint param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 < 0x10) {
    if (param_2 != 0) {
      iVar1 = param_1 + param_2 * 0x10;
      *(float *)(iVar1 + 0x1a0) = (float)fparam_1;
      *(float *)(iVar1 + 0x1a4) = (float)fparam_2;
      *(float *)(iVar1 + 0x1a8) = (float)fparam_3;
      *(float *)(iVar1 + 0x1ac) = (float)fparam_4;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
    if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
              (param_1, param_2, (double)(float)fparam_1, (double)(float)fparam_2, (double)(float)fparam_3, (double)(float)fparam_4);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib4dARB_Comp @ 0xad200 (104 bytes) */
void _glVertexAttrib4dARB_Comp(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4dvARB_ListExec_00110498,0x24);
  if (puVar1 != (undefined4 *)0x0) {
    *(double *)(puVar1 + 1) = fparam_1;
    *puVar1 = param_2;
    *(double *)(puVar1 + 7) = fparam_4;
    *(double *)(puVar1 + 3) = fparam_2;
    *(double *)(puVar1 + 5) = fparam_3;
  }
  FUN_00008b68();
  return;
}

/* _glVertexAttrib4dARB_CompExec @ 0xad268 (104 bytes) */
void _glVertexAttrib4dARB_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glVertexAttrib4dARB_Comp)(param_1,param_2,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glVertexAttrib4dARB_Exec)(param_1,param_2,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
  return;
}

/* _glVertexAttrib4NubARB_Exec @ 0xad2d0 (400 bytes) */
void _glVertexAttrib4NubARB_Exec(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  float fVar1;
  int iVar2;
  code *pcVar3;
  
  fVar1 = FLOAT_00108e78;
  if (param_2 < 0x10) {
    if (param_2 == 0) {
      pcVar3 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar3)(param_1,0,param_3,param_4,param_5,*(int *)(param_1 + 0x4858),param_5 | 0x4b000000,
                (double)((GH_U2F((unsigned int)((param_3 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78),
                (double)((GH_U2F((unsigned int)((param_4 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78),
                (double)((GH_U2F((unsigned int)((param_5 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78),
                (double)((GH_U2F((unsigned int)((param_6 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78));
    }
    else {
      iVar2 = param_1 + param_2 * 0x10;
      *(float *)(iVar2 + 0x1a0) = (GH_U2F((unsigned int)((param_3 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
      *(float *)(iVar2 + 0x1a4) = (GH_U2F((unsigned int)((param_4 | 0x4b000000))) - 8388608.0) * fVar1;
      *(float *)(iVar2 + 0x1a8) = (GH_U2F((unsigned int)((param_5 | 0x4b000000))) - 8388608.0) * fVar1;
      *(float *)(iVar2 + 0x1ac) = (GH_U2F((unsigned int)((param_6 | 0x4b000000))) - 8388608.0) * fVar1;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4NubARB_Comp @ 0xad460 (112 bytes) */
int _glVertexAttrib4NubARB_Comp(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib4NubvARB_ListExec_00110494,8);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined1 *)(puVar1 + 1) = (undefined1)param_3;
    *puVar1 = param_2;
    *(undefined1 *)((int)puVar1 + 7) = (undefined1)param_6;
    *(undefined1 *)((int)puVar1 + 5) = (undefined1)param_4;
    *(undefined1 *)((int)puVar1 + 6) = (undefined1)param_5;
  }
  return puVar1;
}

/* _glVertexAttrib4NubARB_CompExec @ 0xad4d0 (88 bytes) */
void _glVertexAttrib4NubARB_CompExec(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  
  ((int (*)())_glVertexAttrib4NubARB_Comp)(param_1,param_2,param_3,param_4,param_5,param_6);
  ((void (*)())_glVertexAttrib4NubARB_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,in_f2,in_f3,in_f4);
  return;
}

/* _glVertexAttrib1svARB_Exec @ 0xad528 (244 bytes) */
double _glVertexAttrib1svARB_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  short *param_3;
{
  float fVar1;
  int iVar2;
  code *pcVar3;
  double dVar4;
  
  if (param_2 < 0x10) {
    fVar1 = *(float *)(param_1 + 0x20);
    if (param_2 == 0) {
      pcVar3 = *(code **)(param_1 + 0x4884);
      if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar3)(param_1,(double)(float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) -
                                       DOUBLE_00108d58),(double)fVar1,(double)fVar1);
    }
    else {
      iVar2 = param_1 + param_2 * 0x10;
      dVar4 = (double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - DOUBLE_00108d58;
      *(undefined4 *)(iVar2 + 0x1ac) = *(undefined4 *)(param_1 + 0x24);
      *(float *)(iVar2 + 0x1a8) = fVar1;
      *(float *)(iVar2 + 0x1a4) = fVar1;
      *(float *)(iVar2 + 0x1a0) = (float)dVar4;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib1svARB_Comp @ 0xad61c (88 bytes) */
int _glVertexAttrib1svARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined2 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertexAttrib1svARB_ListExec_001104c4,6);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined2 *)(puVar1 + 1) = *param_3;
  }
  return puVar1;
}

