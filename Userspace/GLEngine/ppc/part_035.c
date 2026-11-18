#include "decls.h"

/* _glWeightubvARB_Comp @ 0xab750 (200 bytes) */
int _glWeightubvARB_Comp(glContext, size, weights)
  uint glContext;
  uint size;
  uint weights;
{
  byte *pbVar1;
  float channelScale;
  int iVar3;
  
  if ((int)size < 5) {
    glContext = _gleAddListItem(glContext,PTR__glWeightARB_ListExec_0011045c,size * 4 + 4);
    if ((float *)glContext != (float *)0x0) {
      iVar3 = 0;
      *(uint *)glContext = size;
      channelScale = FLOAT_00108e78;
      if (0 < (int)size) {
        glContext = glContext + 4;
        do {
          pbVar1 = (byte *)(weights + iVar3);
          iVar3 = iVar3 + 1;
          *(float *)glContext = (GH_U2F((unsigned int)((*pbVar1 | 0x4b000000))) - 8388608.0) * channelScale;
          glContext = glContext + 4;
          size = size - 1;
        } while (size != 0);
      }
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return glContext;
}

/* _glWeightubvARB_CompExec @ 0xab818 (64 bytes) */
void _glWeightubvARB_CompExec(glContext, size, weights)
  uint glContext;
  uint size;
  uint weights;
{
  ((int (*)())_glWeightubvARB_Comp)(glContext,size,weights);
  _glWeightubvARB_Exec(glContext,size,weights);
  return;
}

/* _glWeightusvARB_Exec @ 0xab858 (176 bytes) */
double _glWeightusvARB_Exec(glContext, size, weights)
  int glContext;
  int size;
  ushort *weights;
{
  ushort uVar1;
  int iVar2;
  float channelScale;
  float *dstCursor;
  int iVar5;
  int remaining;
  
  channelScale = FLOAT_00108e74;
  if (4 < size) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
      return;
    }
    return;
  }
  iVar5 = 0;
  if (0 < size) {
    dstCursor = (float *)(glContext + 0x2d0);
    remaining = size;
    do {
      uVar1 = *weights;
      weights = weights + 1;
      *dstCursor = (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * channelScale;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
    iVar5 = size;
    if (3 < size) {
      return;
    }
  }
  do {
    iVar2 = iVar5 * 4;
    iVar5 = iVar5 + 1;
    *(undefined4 *)(iVar2 + glContext + 0x2d0) = 0;
  } while (iVar5 < 4);
  return;
}

/* _glWeightusvARB_Comp @ 0xab908 (200 bytes) */
int _glWeightusvARB_Comp(glContext, size, weights)
  uint glContext;
  uint size;
  uint weights;
{
  ushort uVar1;
  float fVar2;
  
  if ((int)size < 5) {
    glContext = _gleAddListItem(glContext,PTR__glWeightARB_ListExec_0011045c,size * 4 + 4);
    if (((float *)glContext != (float *)0x0) &&
       (*(uint *)glContext = size, fVar2 = FLOAT_00108e74, 0 < (int)size)) {
      glContext = glContext + 4;
      do {
        uVar1 = *(ushort *)weights;
        weights = weights + 2;
        *(float *)glContext = (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * fVar2;
        glContext = glContext + 4;
        size = size - 1;
      } while (size != 0);
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return glContext;
}

/* _glWeightusvARB_CompExec @ 0xab9d0 (64 bytes) */
void _glWeightusvARB_CompExec(glContext, size, weights)
  uint glContext;
  uint size;
  uint weights;
{
  ((int (*)())_glWeightusvARB_Comp)(glContext,size,weights);
  ((double (*)())_glWeightusvARB_Exec)(glContext,size,weights);
  return;
}

/* _glWeightuivARB_Exec @ 0xaba10 (176 bytes) */
double _glWeightuivARB_Exec(glContext, size, weights)
  int glContext;
  int size;
  undefined4 *weights;
{
  int iVar1;
  double intToDoubleBias;
  float channelScale;
  undefined4 uVar4;
  float *dstCursor;
  int loopIndex;
  
  channelScale = FLOAT_00108e6c;
  intToDoubleBias = DOUBLE_00108d70;
  if (4 < size) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
      return;
    }
    return;
  }
  loopIndex = 0;
  if (0 < size) {
    dstCursor = (float *)(glContext + 0x2d0);
    do {
      uVar4 = *weights;
      loopIndex = loopIndex + 1;
      weights = weights + 1;
      *dstCursor = (float)((double)CONCAT44(0x43300000,uVar4) - intToDoubleBias) * channelScale;
      dstCursor = dstCursor + 1;
      size = size + -1;
    } while (size != 0);
    if (3 < loopIndex) {
      return;
    }
  }
  do {
    iVar1 = loopIndex * 4;
    loopIndex = loopIndex + 1;
    *(undefined4 *)(iVar1 + glContext + 0x2d0) = 0;
  } while (loopIndex < 4);
  return;
}

/* _glWeightuivARB_Comp @ 0xabac0 (200 bytes) */
int _glWeightuivARB_Comp(glContext, size, weights)
  uint glContext;
  uint size;
  uint weights;
{
  double dVar1;
  float fVar2;
  undefined4 uVar3;
  
  if ((int)size < 5) {
    glContext = _gleAddListItem(glContext,PTR__glWeightARB_ListExec_0011045c,size * 4 + 4);
    if (((float *)glContext != (float *)0x0) &&
       (*(uint *)glContext = size, fVar2 = FLOAT_00108e6c, dVar1 = DOUBLE_00108d70,
       0 < (int)size)) {
      glContext = glContext + 4;
      do {
        uVar3 = *(undefined4 *)weights;
        weights = weights + 4;
        *(float *)glContext = (float)((double)CONCAT44(0x43300000,uVar3) - dVar1) * fVar2;
        glContext = glContext + 4;
        size = size - 1;
      } while (size != 0);
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return glContext;
}

/* _glWeightuivARB_CompExec @ 0xabb88 (64 bytes) */
void _glWeightuivARB_CompExec(glContext, size, weights)
  uint glContext;
  uint size;
  uint weights;
{
  ((int (*)())_glWeightuivARB_Comp)(glContext,size,weights);
  ((double (*)())_glWeightuivARB_Exec)(glContext,size,weights);
  return;
}

/* _glVertexBlendARB_Exec @ 0xabbc8 (104 bytes) */
void _glVertexBlendARB_Exec(glContext, count)
  int glContext;
  int count;
{
  if (count - 1U < 4) {
    *(char *)(glContext + 0x4660) = (char)count;
    _gleUpdateInverseNeeds(glContext);
    _gleSelectVertexSubmitFunc(glContext);
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x200000;
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexBlendARB_Comp @ 0xabc30 (76 bytes) */
int _glVertexBlendARB_Comp(glContext, count)
  undefined4 glContext;
  undefined4 count;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexBlendARB_ListExec_00110458,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = count;
  }
  return listRecord;
}

/* _glVertexBlendARB_CompExec @ 0xabc7c (56 bytes) */
void _glVertexBlendARB_CompExec(glContext, count)
  undefined4 glContext;
  undefined4 count;
{
  ((int (*)())_glVertexBlendARB_Comp)(glContext,count);
  ((void (*)())_glVertexBlendARB_Exec)(glContext,count);
  return;
}

/* _glVertexBlendARB_ListExec @ 0xabcb4 (40 bytes) */
int _glVertexBlendARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glVertexBlendARB_Exec)(glContext,*listRecord);
  return 4;
}

/* _glBindVertexArrayEXT_Exec @ 0xabcdc (168 bytes) */
void _glBindVertexArrayEXT_Exec(glContext, id)
  int glContext;
  undefined4 id;
{
  int iVar1;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    return;
  }
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
    _gleBindVertexArray(glContext,id);
    return;
  }
  iVar1 = *(int *)(glContext + 0x5148) + 0x8028;
  _pthread_mutex_lock(iVar1);
  _gleBindVertexArray(glContext,id);
  _pthread_mutex_unlock(iVar1);
  return;
}

/* _glBindVertexArrayEXT_Comp @ 0xabd84 (76 bytes) */
int _glBindVertexArrayEXT_Comp(glContext, id)
  undefined4 glContext;
  undefined4 id;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glBindVertexArrayEXT_ListExec_00110460,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = id;
  }
  return listRecord;
}

/* _glBindVertexArrayEXT_CompExec @ 0xabdd0 (56 bytes) */
void _glBindVertexArrayEXT_CompExec(glContext, id)
  undefined4 glContext;
  undefined4 id;
{
  ((int (*)())_glBindVertexArrayEXT_Comp)(glContext,id);
  ((void (*)())_glBindVertexArrayEXT_Exec)(glContext,id);
  return;
}

/* _glBindVertexArrayEXT_ListExec @ 0xabe08 (40 bytes) */
int _glBindVertexArrayEXT_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glBindVertexArrayEXT_Exec)(glContext,*listRecord);
  return 4;
}

/* _glDeleteVertexArraysEXT_Exec @ 0xabe30 (272 bytes) */
void _glDeleteVertexArraysEXT_Exec(glContext, n, ids)
  int glContext;
  int n;
  int *ids;
{
  undefined4 glErrorCode;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (0 < n) {
        do {
          iVar2 = *ids;
          ids = ids + 1;
          if (iVar2 != 0) {
            if (iVar2 == *(int *)(*(int *)(glContext + 0x4a60) + 4)) {
              _gleBindVertexArray(glContext,0);
            }
            _gleDeleteHashNameAndObject(glContext,*(int *)(glContext + 0x5148) + 0x5014,iVar2);
          }
          n = n + -1;
        } while (n != 0);
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
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

/* _glGenVertexArraysEXT_Exec @ 0xabf40 (236 bytes) */
void _glGenVertexArraysEXT_Exec(glContext, n, ids)
  int glContext;
  int n;
  int *ids;
{
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      iVar4 = *(int *)(glContext + 0x5148);
      if (*(char *)(iVar4 + 0x8024) != '\0') {
        _pthread_mutex_lock(iVar4 + 0x8028);
        iVar4 = *(int *)(glContext + 0x5148);
      }
      iVar4 = _gleGenHashNames(iVar4 + 0x5014,n);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
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

/* _glIsVertexArrayEXT_Exec @ 0xac02c (168 bytes) */
int _glIsVertexArrayEXT_Exec(glContext, id)
  int glContext;
  undefined4 id;
{
  int iVar1;
  bool bVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar1 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar1 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar1 + 0x8028);
      iVar1 = *(int *)(glContext + 0x5148);
    }
    iVar1 = _gleLookupHashObject(iVar1 + 0x5014,id);
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

/* _glVertexAttrib1sARB_Exec @ 0xac0d4 (236 bytes) */
void _glVertexAttrib1sARB_Exec(glContext, index, x)
  int glContext;
  uint index;
  uint x;
{
  float fVar1;
  int iVar2;
  code *pcVar3;
  double dVar4;
  
  if (index < 0x10) {
    fVar1 = *(float *)(glContext + 0x20);
    if (index == 0) {
      pcVar3 = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar3)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                       DOUBLE_00108d58),(double)fVar1,(double)fVar1,
                (double)*(float *)(glContext + 0x24));
    }
    else {
      iVar2 = glContext + index * 0x10;
      dVar4 = (double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58;
      *(float *)(iVar2 + 0x1ac) = *(float *)(glContext + 0x24);
      *(float *)(iVar2 + 0x1a8) = fVar1;
      *(float *)(iVar2 + 0x1a4) = fVar1;
      *(float *)(iVar2 + 0x1a0) = (float)dVar4;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib1sARB_Comp @ 0xac1c0 (84 bytes) */
int _glVertexAttrib1sARB_Comp(glContext, index, x)
  undefined4 glContext;
  undefined4 index;
  undefined4 x;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib1svARB_ListExec_001104c4,6);
  if (listRecord != (undefined4 *)0x0) {
    *(undefined2 *)(listRecord + 1) = (*(unsigned short *)((unsigned char *)&(x) + 2));
    *listRecord = index;
  }
  return listRecord;
}

/* _glVertexAttrib1sARB_CompExec @ 0xac214 (64 bytes) */
void _glVertexAttrib1sARB_CompExec(glContext, index, x)
  undefined4 glContext;
  undefined4 index;
  undefined4 x;
{
  ((int (*)())_glVertexAttrib1sARB_Comp)(glContext,index,x);
  ((void (*)())_glVertexAttrib1sARB_Exec)(glContext,index,x);
  return;
}

/* _glVertexAttrib1fARB_Exec @ 0xac254 (136 bytes) */
void _glVertexAttrib1fARB_Exec(int glContext,uint index,float x)
{
  float fVar1;
  float fVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (index < 0x10) {
    fVar1 = *(float *)(glContext + 0x20);
    fVar2 = *(float *)(glContext + 0x24);
    if (index != 0) {
      iVar3 = glContext + index * 0x10;
      *(float *)(iVar3 + 0x1a0) = (float)x;
      *(float *)(iVar3 + 0x1ac) = fVar2;
      *(float *)(iVar3 + 0x1a8) = fVar1;
      *(float *)(iVar3 + 0x1a4) = fVar1;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*UNRECOVERED_JUMPTABLE)(glContext,0,x,(double)fVar1,(double)fVar1,(double)fVar2);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib1fARB_Comp @ 0xac2dc (92 bytes) */
undefined4 * _glVertexAttrib1fARB_Comp(undefined4 glContext,undefined4 index,float x)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib1fvARB_ListExec_001104c0,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = (float)x;
    *listRecord = index;
  }
  return listRecord;
}

/* _glVertexAttrib1fARB_CompExec @ 0xac338 (72 bytes) */
void _glVertexAttrib1fARB_CompExec(undefined4 glContext,undefined4 index,float x)
{
  ((undefined4 * (*)())_glVertexAttrib1fARB_Comp)(glContext,index,x);
  ((void (*)())_glVertexAttrib1fARB_Exec)(glContext,index,x);
  return;
}

/* _glVertexAttrib1dARB_Exec @ 0xac380 (144 bytes) */
void _glVertexAttrib1dARB_Exec(int glContext,uint index,double x)
{
  float fVar1;
  float fVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (index < 0x10) {
    fVar1 = *(float *)(glContext + 0x20);
    fVar2 = *(float *)(glContext + 0x24);
    if (index != 0) {
      iVar3 = glContext + index * 0x10;
      *(float *)(iVar3 + 0x1a0) = (float)x;
      *(float *)(iVar3 + 0x1ac) = fVar2;
      *(float *)(iVar3 + 0x1a8) = fVar1;
      *(float *)(iVar3 + 0x1a4) = fVar1;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*UNRECOVERED_JUMPTABLE)
              (glContext,0,(double)(float)x,(double)fVar1,(double)fVar1,(double)fVar2);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib1dARB_Comp @ 0xac410 (92 bytes) */
undefined4 * _glVertexAttrib1dARB_Comp(undefined4 glContext,undefined4 index,double x)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib1dvARB_ListExec_001104bc,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *(double *)(listRecord + 1) = x;
    *listRecord = index;
  }
  return listRecord;
}

/* _glVertexAttrib1dARB_CompExec @ 0xac46c (72 bytes) */
void _glVertexAttrib1dARB_CompExec(undefined4 glContext,undefined4 index,double x)
{
  ((undefined4 * (*)())_glVertexAttrib1dARB_Comp)(glContext,index,x);
  ((void (*)())_glVertexAttrib1dARB_Exec)(glContext,index,x);
  return;
}

/* _glVertexAttrib2sARB_Exec @ 0xac4b4 (276 bytes) */
void _glVertexAttrib2sARB_Exec(glContext, index, x, y)
  int glContext;
  uint index;
  uint x;
  uint y;
{
  float fVar1;
  float fVar2;
  double intToDoubleBias;
  int iVar4;
  code *pcVar5;
  
  intToDoubleBias = DOUBLE_00108d58;
  if (index < 0x10) {
    fVar1 = *(float *)(glContext + 0x20);
    fVar2 = *(float *)(glContext + 0x24);
    if (index == 0) {
      pcVar5 = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        pcVar5 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar5)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                       DOUBLE_00108d58),
                (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58)
                ,(double)fVar1,(double)fVar2);
    }
    else {
      iVar4 = glContext + index * 0x10;
      *(float *)(iVar4 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(iVar4 + 0x1ac) = fVar2;
      *(float *)(iVar4 + 0x1a8) = fVar1;
      *(float *)(iVar4 + 0x1a4) = (float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - intToDoubleBias)
      ;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib2sARB_Comp @ 0xac5c8 (92 bytes) */
int _glVertexAttrib2sARB_Comp(glContext, index, x, y)
  undefined4 glContext;
  undefined4 index;
  undefined4 x;
  undefined4 y;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib2svARB_ListExec_001104b8,8);
  if (listRecord != (undefined4 *)0x0) {
    *(undefined2 *)((int)listRecord + 6) = (*(unsigned short *)((unsigned char *)&(y) + 2));
    *listRecord = index;
    *(undefined2 *)(listRecord + 1) = (*(unsigned short *)((unsigned char *)&(x) + 2));
  }
  return listRecord;
}

/* _glVertexAttrib2sARB_CompExec @ 0xac624 (72 bytes) */
void _glVertexAttrib2sARB_CompExec(glContext, index, x, y)
  undefined4 glContext;
  undefined4 index;
  undefined4 x;
  undefined4 y;
{
  ((int (*)())_glVertexAttrib2sARB_Comp)(glContext,index,x,y);
  ((void (*)())_glVertexAttrib2sARB_Exec)(glContext,index,x,y);
  return;
}

/* _glVertexAttrib2fARB_Exec @ 0xac66c (132 bytes) */
void _glVertexAttrib2fARB_Exec(int glContext,uint index,float x,float y)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (index < 0x10) {
    uVar1 = *(undefined4 *)(glContext + 0x20);
    uVar2 = *(undefined4 *)(glContext + 0x24);
    if (index != 0) {
      iVar3 = glContext + index * 0x10;
      *(float *)(iVar3 + 0x1a0) = (float)x;
      *(undefined4 *)(iVar3 + 0x1ac) = uVar2;
      *(float *)(iVar3 + 0x1a4) = (float)y;
      *(undefined4 *)(iVar3 + 0x1a8) = uVar1;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int))UNRECOVERED_JUMPTABLE))(glContext, index);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib2fARB_Comp @ 0xac6f0 (108 bytes) */
undefined4 * _glVertexAttrib2fARB_Comp(undefined4 glContext,undefined4 index,float x,float y)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib2fvARB_ListExec_001104b4,0xc);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[2] = (float)y;
    *listRecord = index;
    listRecord[1] = (float)x;
  }
  return listRecord;
}

/* _glVertexAttrib2fARB_CompExec @ 0xac75c (88 bytes) */
void _glVertexAttrib2fARB_CompExec(undefined4 glContext,undefined4 index,float x,float y)
{
  ((undefined4 * (*)())_glVertexAttrib2fARB_Comp)(glContext,index,x,y);
  ((void (*)())_glVertexAttrib2fARB_Exec)(glContext,index,x,y);
  return;
}

/* _glVertexAttrib2dARB_Exec @ 0xac7b4 (148 bytes) */
void _glVertexAttrib2dARB_Exec(int glContext,uint index,double x,double y,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float fVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (index < 0x10) {
    fVar1 = *(float *)(glContext + 0x20);
    fVar2 = *(float *)(glContext + 0x24);
    if (index != 0) {
      iVar3 = glContext + index * 0x10;
      *(float *)(iVar3 + 0x1a0) = (float)x;
      *(float *)(iVar3 + 0x1ac) = fVar2;
      *(float *)(iVar3 + 0x1a4) = (float)y;
      *(float *)(iVar3 + 0x1a8) = fVar1;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*UNRECOVERED_JUMPTABLE)
              (glContext,0,(double)(float)x,(double)(float)y,(double)fVar1,(double)fVar2
              );
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib2dARB_Comp @ 0xac848 (108 bytes) */
undefined4 * _glVertexAttrib2dARB_Comp(undefined4 glContext,undefined4 index,double x,double y)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib2dvARB_ListExec_001104b0,0x14);
  if (listRecord != (undefined4 *)0x0) {
    *(double *)(listRecord + 3) = y;
    *listRecord = index;
    *(double *)(listRecord + 1) = x;
  }
  return listRecord;
}

/* _glVertexAttrib2dARB_CompExec @ 0xac8b4 (88 bytes) */
void _glVertexAttrib2dARB_CompExec(undefined4 glContext,undefined4 index,double x,double y)
{
  undefined4 in_LR;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((undefined4 * (*)())_glVertexAttrib2dARB_Comp)(glContext,index,x,y);
  ((void (*)())_glVertexAttrib2dARB_Exec)(glContext,index,x,y,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
  return;
}

/* _glVertexAttrib3sARB_Exec @ 0xac90c (316 bytes) */
void _glVertexAttrib3sARB_Exec(glContext, index, x, y, z)
  int glContext;
  uint index;
  uint x;
  uint y;
  uint z;
{
  undefined4 uVar1;
  double intToDoubleBias;
  int iVar3;
  code *pcVar4;
  
  intToDoubleBias = DOUBLE_00108d58;
  if (index < 0x10) {
    uVar1 = *(undefined4 *)(glContext + 0x24);
    if (index == 0) {
      pcVar4 = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        pcVar4 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar4)(glContext,0,x,y,z,*(int *)(glContext + 0x4858),z ^ 0x80000000,
                (double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58)
                ,(double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58
                                ),
                (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - DOUBLE_00108d58)
               );
    }
    else {
      iVar3 = glContext + index * 0x10;
      *(float *)(iVar3 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(iVar3 + 0x1a4) = (float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - intToDoubleBias)
      ;
      *(undefined4 *)(iVar3 + 0x1ac) = uVar1;
      *(float *)(iVar3 + 0x1a8) = (float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - intToDoubleBias)
      ;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib3sARB_Comp @ 0xaca48 (104 bytes) */
int _glVertexAttrib3sARB_Comp(glContext, index, x, y, z)
  undefined4 glContext;
  undefined4 index;
  undefined4 x;
  undefined4 y;
  undefined4 z;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib3svARB_ListExec_001104ac,10);
  if (listRecord != (undefined4 *)0x0) {
    *(undefined2 *)(listRecord + 1) = (*(unsigned short *)((unsigned char *)&(x) + 2));
    *listRecord = index;
    *(undefined2 *)(listRecord + 2) = (*(unsigned short *)((unsigned char *)&(z) + 2));
    *(undefined2 *)((int)listRecord + 6) = (*(unsigned short *)((unsigned char *)&(y) + 2));
  }
  return listRecord;
}

/* _glVertexAttrib3sARB_CompExec @ 0xacab0 (80 bytes) */
void _glVertexAttrib3sARB_CompExec(glContext, index, x, y, z)
  undefined4 glContext;
  undefined4 index;
  undefined4 x;
  undefined4 y;
  undefined4 z;
{
  ((int (*)())_glVertexAttrib3sARB_Comp)(glContext,index,x,y,z);
  ((void (*)())_glVertexAttrib3sARB_Exec)(glContext,index,x,y,z);
  return;
}

/* _glVertexAttrib3fARB_Exec @ 0xacb00 (128 bytes) */
void _glVertexAttrib3fARB_Exec(int glContext,uint index,float x,float y,float z)
{
  undefined4 uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (index < 0x10) {
    uVar1 = *(undefined4 *)(glContext + 0x24);
    if (index != 0) {
      iVar2 = glContext + index * 0x10;
      *(float *)(iVar2 + 0x1a0) = (float)x;
      *(undefined4 *)(iVar2 + 0x1ac) = uVar1;
      *(float *)(iVar2 + 0x1a4) = (float)y;
      *(float *)(iVar2 + 0x1a8) = (float)z;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int))UNRECOVERED_JUMPTABLE))(glContext, index);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib3fARB_Comp @ 0xacb80 (128 bytes) */
undefined4 * _glVertexAttrib3fARB_Comp(undefined4 glContext,undefined4 index,float x,float y,float z)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib3fvARB_ListExec_001104a8,0x10);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = (float)x;
    *listRecord = index;
    listRecord[3] = (float)z;
    listRecord[2] = (float)y;
  }
  return listRecord;
}

/* _glVertexAttrib3fARB_CompExec @ 0xacc00 (104 bytes) */
void _glVertexAttrib3fARB_CompExec(undefined4 glContext,undefined4 index,float x,float y,float z)
{
  ((undefined4 * (*)())_glVertexAttrib3fARB_Comp)(glContext,index,x,y,z);
  ((void (*)())_glVertexAttrib3fARB_Exec)(glContext,index,x,y,z);
  return;
}

/* _glVertexAttrib3dARB_Exec @ 0xacc68 (152 bytes) */
void _glVertexAttrib3dARB_Exec(int glContext,uint index,double x,double y,double z,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (index < 0x10) {
    fVar1 = *(float *)(glContext + 0x24);
    if (index != 0) {
      iVar2 = glContext + index * 0x10;
      *(float *)(iVar2 + 0x1a0) = (float)x;
      *(float *)(iVar2 + 0x1ac) = fVar1;
      *(float *)(iVar2 + 0x1a4) = (float)y;
      *(float *)(iVar2 + 0x1a8) = (float)z;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*UNRECOVERED_JUMPTABLE)
              (glContext,0,(double)(float)x,(double)(float)y,(double)(float)z,
               (double)fVar1);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib3dARB_Comp @ 0xacd00 (128 bytes) */
undefined4 * _glVertexAttrib3dARB_Comp(undefined4 glContext,undefined4 index,double x,double y,double z)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib3dvARB_ListExec_001104a4,0x1c);
  if (listRecord != (undefined4 *)0x0) {
    *(double *)(listRecord + 1) = x;
    *listRecord = index;
    *(double *)(listRecord + 5) = z;
    *(double *)(listRecord + 3) = y;
  }
  return listRecord;
}

/* _glVertexAttrib3dARB_CompExec @ 0xacd80 (104 bytes) */
void _glVertexAttrib3dARB_CompExec(undefined4 glContext,undefined4 index,double x,double y,double z)
{
  undefined4 in_LR;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((undefined4 * (*)())_glVertexAttrib3dARB_Comp)(glContext,index,x,y,z);
  ((void (*)())_glVertexAttrib3dARB_Exec)(glContext,index,x,y,z,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
  return;
}

/* _glVertexAttrib4sARB_Exec @ 0xacde8 (360 bytes) */
void _glVertexAttrib4sARB_Exec(glContext, index, x, y, z, w)
  int glContext;
  uint index;
  uint x;
  uint y;
  uint z;
  uint w;
{
  double intToDoubleBias;
  int iVar2;
  code *pcVar3;
  
  intToDoubleBias = DOUBLE_00108d58;
  if (index < 0x10) {
    if (index == 0) {
      pcVar3 = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar3)(glContext,0,x,y,z,*(int *)(glContext + 0x4858),z ^ 0x80000000,
                (double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58)
                ,(double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58
                                ),
                (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - DOUBLE_00108d58)
                ,(double)(float)((double)CONCAT44(0x43300000,w ^ 0x80000000) - DOUBLE_00108d58
                                ));
    }
    else {
      iVar2 = glContext + index * 0x10;
      *(float *)(iVar2 + 0x1a0) =
           (float)((double)CONCAT44(0x43300000,x ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(iVar2 + 0x1a4) = (float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - intToDoubleBias)
      ;
      *(float *)(iVar2 + 0x1a8) = (float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - intToDoubleBias)
      ;
      *(float *)(iVar2 + 0x1ac) = (float)((double)CONCAT44(0x43300000,w ^ 0x80000000) - intToDoubleBias)
      ;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4sARB_Comp @ 0xacf50 (112 bytes) */
int _glVertexAttrib4sARB_Comp(glContext, index, x, y, z, w)
  undefined4 glContext;
  undefined4 index;
  undefined4 x;
  undefined4 y;
  undefined4 z;
  undefined4 w;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4svARB_ListExec_001104a0,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *(undefined2 *)(listRecord + 1) = (*(unsigned short *)((unsigned char *)&(x) + 2));
    *listRecord = index;
    *(undefined2 *)((int)listRecord + 10) = (*(unsigned short *)((unsigned char *)&(w) + 2));
    *(undefined2 *)((int)listRecord + 6) = (*(unsigned short *)((unsigned char *)&(y) + 2));
    *(undefined2 *)(listRecord + 2) = (*(unsigned short *)((unsigned char *)&(z) + 2));
  }
  return listRecord;
}

/* _glVertexAttrib4sARB_CompExec @ 0xacfc0 (88 bytes) */
void _glVertexAttrib4sARB_CompExec(glContext, index, x, y, z, w)
  undefined4 glContext;
  undefined4 index;
  undefined4 x;
  undefined4 y;
  undefined4 z;
  undefined4 w;
{
  ((int (*)())_glVertexAttrib4sARB_Comp)(glContext,index,x,y,z,w);
  ((void (*)())_glVertexAttrib4sARB_Exec)(glContext,index,x,y,z,w);
  return;
}

/* _glVertexAttrib4fARB_Exec @ 0xad018 (124 bytes) */
void _glVertexAttrib4fARB_Exec(int glContext,uint index,float x,float y,float z,float w)
{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (index < 0x10) {
    if (index != 0) {
      iVar1 = glContext + index * 0x10;
      *(float *)(iVar1 + 0x1a0) = (float)x;
      *(float *)(iVar1 + 0x1ac) = (float)w;
      *(float *)(iVar1 + 0x1a4) = (float)y;
      *(float *)(iVar1 + 0x1a8) = (float)z;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int))UNRECOVERED_JUMPTABLE))(glContext, index);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib4fARB_Comp @ 0xad094 (104 bytes) */
void _glVertexAttrib4fARB_Comp(undefined4 glContext,undefined4 index,float x,float y,float z,float w)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4fvARB_ListExec_0011049c,0x14);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = (float)x;
    *listRecord = index;
    listRecord[4] = (float)w;
    listRecord[2] = (float)y;
    listRecord[3] = (float)z;
  }
  return;
}

/* _glVertexAttrib4fARB_CompExec @ 0xad0fc (104 bytes) */
void _glVertexAttrib4fARB_CompExec(undefined4 glContext,undefined4 index,float x,float y,float z,float w)
{
  ((void (*)())_glVertexAttrib4fARB_Comp)(glContext,index,x,y,z,w);
  ((void (*)())_glVertexAttrib4fARB_Exec)(glContext,index,x,y,z,w);
  return;
}

/* _glVertexAttrib4dARB_Exec @ 0xad164 (156 bytes) */
void _glVertexAttrib4dARB_Exec(int glContext,uint index,double x,double y,double z,double w,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (index < 0x10) {
    if (index != 0) {
      iVar1 = glContext + index * 0x10;
      *(float *)(iVar1 + 0x1a0) = (float)x;
      *(float *)(iVar1 + 0x1a4) = (float)y;
      *(float *)(iVar1 + 0x1a8) = (float)z;
      *(float *)(iVar1 + 0x1ac) = (float)w;
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
    if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
      UNRECOVERED_JUMPTABLE = (code *)PTR__gleFlushAndSubmit_00112050;
    }
                    
                    
    (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
              (glContext, index, (double)(float)x, (double)(float)y, (double)(float)z, (double)(float)w);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glVertexAttrib4dARB_Comp @ 0xad200 (104 bytes) */
void _glVertexAttrib4dARB_Comp(undefined4 glContext,undefined4 index,double x,double y,double z,double w)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4dvARB_ListExec_00110498,0x24);
  if (listRecord != (undefined4 *)0x0) {
    *(double *)(listRecord + 1) = x;
    *listRecord = index;
    *(double *)(listRecord + 7) = w;
    *(double *)(listRecord + 3) = y;
    *(double *)(listRecord + 5) = z;
  }
  return;
}

/* _glVertexAttrib4dARB_CompExec @ 0xad268 (104 bytes) */
void _glVertexAttrib4dARB_CompExec(undefined4 glContext,undefined4 index,double x,double y,double z,double w)
{
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glVertexAttrib4dARB_Comp)(glContext,index,x,y,z,w);
  ((void (*)())_glVertexAttrib4dARB_Exec)(glContext,index,x,y,z,w,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
  return;
}

/* _glVertexAttrib4NubARB_Exec @ 0xad2d0 (400 bytes) */
void _glVertexAttrib4NubARB_Exec(int glContext,uint index,uint x,uint y,uint z,uint w,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4)
{
  float channelScale;
  int iVar2;
  code *pcVar3;
  
  channelScale = FLOAT_00108e78;
  if (index < 0x10) {
    if (index == 0) {
      pcVar3 = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar3)(glContext,0,x,y,z,*(int *)(glContext + 0x4858),z | 0x4b000000,
                (double)((GH_U2F((unsigned int)((x | 0x4b000000))) - 8388608.0) * FLOAT_00108e78),
                (double)((GH_U2F((unsigned int)((y | 0x4b000000))) - 8388608.0) * FLOAT_00108e78),
                (double)((GH_U2F((unsigned int)((z | 0x4b000000))) - 8388608.0) * FLOAT_00108e78),
                (double)((GH_U2F((unsigned int)((w | 0x4b000000))) - 8388608.0) * FLOAT_00108e78));
    }
    else {
      iVar2 = glContext + index * 0x10;
      *(float *)(iVar2 + 0x1a0) = (GH_U2F((unsigned int)((x | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
      *(float *)(iVar2 + 0x1a4) = (GH_U2F((unsigned int)((y | 0x4b000000))) - 8388608.0) * channelScale;
      *(float *)(iVar2 + 0x1a8) = (GH_U2F((unsigned int)((z | 0x4b000000))) - 8388608.0) * channelScale;
      *(float *)(iVar2 + 0x1ac) = (GH_U2F((unsigned int)((w | 0x4b000000))) - 8388608.0) * channelScale;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib4NubARB_Comp @ 0xad460 (112 bytes) */
int _glVertexAttrib4NubARB_Comp(glContext, index, x, y, z, w)
  undefined4 glContext;
  undefined4 index;
  undefined4 x;
  undefined4 y;
  undefined4 z;
  undefined4 w;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib4NubvARB_ListExec_00110494,8);
  if (listRecord != (undefined4 *)0x0) {
    *(undefined1 *)(listRecord + 1) = (undefined1)x;
    *listRecord = index;
    *(undefined1 *)((int)listRecord + 7) = (undefined1)w;
    *(undefined1 *)((int)listRecord + 5) = (undefined1)y;
    *(undefined1 *)((int)listRecord + 6) = (undefined1)z;
  }
  return listRecord;
}

/* _glVertexAttrib4NubARB_CompExec @ 0xad4d0 (88 bytes) */
void _glVertexAttrib4NubARB_CompExec(glContext, index, x, y, z, w)
  undefined4 glContext;
  undefined4 index;
  undefined4 x;
  undefined4 y;
  undefined4 z;
  undefined4 w;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  
  ((int (*)())_glVertexAttrib4NubARB_Comp)(glContext,index,x,y,z,w);
  ((void (*)())_glVertexAttrib4NubARB_Exec)(glContext,index,x,y,z,w,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4);
  return;
}

/* _glVertexAttrib1svARB_Exec @ 0xad528 (244 bytes) */
double _glVertexAttrib1svARB_Exec(glContext, index, v)
  int glContext;
  uint index;
  short *v;
{
  float fVar1;
  int iVar2;
  code *pcVar3;
  double dVar4;
  
  if (index < 0x10) {
    fVar1 = *(float *)(glContext + 0x20);
    if (index == 0) {
      pcVar3 = *(code **)(glContext + 0x4884);
      if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
        pcVar3 = (code *)PTR__gleFlushAndSubmit_00112050;
      }
      (*pcVar3)(glContext,(double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                                       DOUBLE_00108d58),(double)fVar1,(double)fVar1,
                (double)*(float *)(glContext + 0x24));
    }
    else {
      iVar2 = glContext + index * 0x10;
      dVar4 = (double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58;
      *(float *)(iVar2 + 0x1ac) = *(float *)(glContext + 0x24);
      *(float *)(iVar2 + 0x1a8) = fVar1;
      *(float *)(iVar2 + 0x1a4) = fVar1;
      *(float *)(iVar2 + 0x1a0) = (float)dVar4;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return;
}

/* _glVertexAttrib1svARB_Comp @ 0xad61c (88 bytes) */
int _glVertexAttrib1svARB_Comp(glContext, index, v)
  undefined4 glContext;
  undefined4 index;
  undefined2 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glVertexAttrib1svARB_ListExec_001104c4,6);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = index;
    *(undefined2 *)(listRecord + 1) = *v;
  }
  return listRecord;
}

