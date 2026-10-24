#include "decls.h"

/* __ZNKSs5rfindEcm @ 0x97c15b28 (92 bytes) */
int __ZNKSs5rfindEcm(this, c, pos)
  void *this;
  int c;
  ulong pos;
{
  bool wasZero;
  int thisSize;
  uint i;
  
  thisSize = *(int *)(*(int *)this + -0xc);
  if (thisSize != 0) {
    i = thisSize - 1;
    if (pos < i) {
      i = pos;
    }
    if (i != 0xffffffff) {
      do {
        if (*(char *)(*(int *)this + i) == c) {
          return i;
        }
        wasZero = i != 0;
        i = i - 1;
      } while (wasZero);
    }
  }
  return 0xffffffff;
}

/* __ZNKSs13find_first_ofERKSsm @ 0x97c15b84 (12 bytes) */
int __ZNKSs13find_first_ofERKSsm(this, text, pos)
  void *this;
  unsigned char * text;
  ulong pos;
{
  return ((int (*)())__ZNKSs13find_first_ofEPKcmm)(this,*(char **)text,pos,*(ulong *)(*(char **)text + -0xc));
}

/* __ZNKSs13find_first_ofEPKcmm @ 0x97c15b90 (152 bytes) */
int __ZNKSs13find_first_ofEPKcmm(this, str, pos, n)
  void *this;
  char *str;
  ulong pos;
  ulong n;
{
  int data;
  void *memchrResult;
  
  if ((n != 0) && (data = *(int *)this, pos < *(uint *)(data + -0xc))) {
    do {
      memchrResult = _memchr(str,(int)*(char *)(data + pos),n);
      if (memchrResult != (void *)0x0) {
        return pos;
      }
      pos = pos + 1;
      data = *(int *)this;
    } while (pos < *(uint *)(data + -0xc));
  }
  return 0xffffffff;
}

/* __ZNKSs13find_first_ofEPKcm @ 0x97c15c28 (72 bytes) */
int __ZNKSs13find_first_ofEPKcm(this, str, pos)
  void *this;
  char *str;
  ulong pos;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNKSs13find_first_ofEPKcmm)(this,str,pos,length);
}

/* __ZNKSs13find_first_ofEcm @ 0x97c15c70 (4 bytes) */
int __ZNKSs13find_first_ofEcm(this, c, pos)
  void *this;
  int c;
  ulong pos;
{
  return __ZNKSs4findEcm(this,c,pos);
}

/* __ZNKSs12find_last_ofERKSsm @ 0x97c15c74 (12 bytes) */
int __ZNKSs12find_last_ofERKSsm(this, text, pos)
  void *this;
  unsigned char * text;
  ulong pos;
{
  return ((int (*)())__ZNKSs12find_last_ofEPKcmm)(this,*(char **)text,pos,*(ulong *)(*(char **)text + -0xc));
}

/* __ZNKSs12find_last_ofEPKcmm @ 0x97c15c80 (144 bytes) */
int __ZNKSs12find_last_ofEPKcmm(this, str, pos, n)
  void *this;
  char *str;
  ulong pos;
  ulong n;
{
  bool wasZero;
  int data;
  void *found;
  uint i;
  
  data = *(int *)this;
  if ((*(int *)(data + -0xc) == 0) || (n == 0)) {
LAB_97c15cf8:
    i = 0xffffffff;
  }
  else {
    i = *(int *)(data + -0xc) - 1;
    if (pos < i) {
      i = pos;
    }
    while (found = _memchr(str,(int)*(char *)(data + i),n), found == (void *)0x0) {
      wasZero = i == 0;
      i = i - 1;
      if (wasZero) goto LAB_97c15cf8;
      data = *(int *)this;
    }
  }
  return i;
}

/* __ZNKSs12find_last_ofEPKcm @ 0x97c15d10 (72 bytes) */
int __ZNKSs12find_last_ofEPKcm(this, str, pos)
  void *this;
  char *str;
  ulong pos;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNKSs12find_last_ofEPKcmm)(this,str,pos,length);
}

/* __ZNKSs12find_last_ofEcm @ 0x97c15d58 (4 bytes) */
int __ZNKSs12find_last_ofEcm(this, c, pos)
  void *this;
  int c;
  ulong pos;
{
  return ((int (*)())__ZNKSs5rfindEcm)(this,c,pos);
}

/* __ZNKSs17find_first_not_ofERKSsm @ 0x97c15d5c (12 bytes) */
int __ZNKSs17find_first_not_ofERKSsm(this, text, pos)
  void *this;
  unsigned char * text;
  ulong pos;
{
  return ((int (*)())__ZNKSs17find_first_not_ofEPKcmm)(this,*(char **)text,pos,*(ulong *)(*(char **)text + -0xc));
}

/* __ZNKSs17find_first_not_ofEPKcmm @ 0x97c15d68 (124 bytes) */
int __ZNKSs17find_first_not_ofEPKcmm(this, str, pos, n)
  void *this;
  char *str;
  ulong pos;
  ulong n;
{
  int data;
  void *memchrResult;
  
  data = *(int *)this;
  if (pos < *(uint *)(data + -0xc)) {
    do {
      memchrResult = _memchr(str,(int)*(char *)(data + pos),n);
      if (memchrResult == (void *)0x0) {
        return pos;
      }
      data = *(int *)this;
      pos = pos + 1;
    } while (pos < *(uint *)(data + -0xc));
  }
  return 0xffffffff;
}

/* __ZNKSs17find_first_not_ofEPKcm @ 0x97c15de4 (72 bytes) */
int __ZNKSs17find_first_not_ofEPKcm(this, str, pos)
  void *this;
  char *str;
  ulong pos;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNKSs17find_first_not_ofEPKcmm)(this,str,pos,length);
}

/* __ZNKSs17find_first_not_ofEcm @ 0x97c15e2c (68 bytes) */
int __ZNKSs17find_first_not_ofEcm(this, c, pos)
  void *this;
  int c;
  ulong pos;
{
  while( true ) {
    if (*(uint *)(*(int *)this + -0xc) <= pos) {
      return 0xffffffff;
    }
    if (*(char *)(*(int *)this + pos) != c) break;
    pos = pos + 1;
  }
  return pos;
}

/* __ZNKSs16find_last_not_ofERKSsm @ 0x97c15e70 (12 bytes) */
int __ZNKSs16find_last_not_ofERKSsm(this, text, pos)
  void *this;
  unsigned char * text;
  ulong pos;
{
  return ((int (*)())__ZNKSs16find_last_not_ofEPKcmm)(this,*(char **)text,pos,*(ulong *)(*(char **)text + -0xc));
}

/* __ZNKSs16find_last_not_ofEPKcmm @ 0x97c15e7c (136 bytes) */
int __ZNKSs16find_last_not_ofEPKcmm(this, str, pos, n)
  void *this;
  char *str;
  ulong pos;
  ulong n;
{
  bool wasZero;
  int data;
  void *found;
  uint i;
  
  data = *(int *)this;
  if (*(int *)(data + -0xc) == 0) {
LAB_97c15eec:
    i = 0xffffffff;
  }
  else {
    i = *(int *)(data + -0xc) - 1;
    if (pos < i) {
      i = pos;
    }
    while (found = _memchr(str,(int)*(char *)(data + i),n), found != (void *)0x0) {
      wasZero = i == 0;
      i = i - 1;
      if (wasZero) goto LAB_97c15eec;
      data = *(int *)this;
    }
  }
  return i;
}

/* __ZNKSs16find_last_not_ofEPKcm @ 0x97c15f04 (72 bytes) */
int __ZNKSs16find_last_not_ofEPKcm(this, str, pos)
  void *this;
  char *str;
  ulong pos;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNKSs16find_last_not_ofEPKcmm)(this,str,pos,length);
}

/* __ZNKSs16find_last_not_ofEcm @ 0x97c15f4c (84 bytes) */
int __ZNKSs16find_last_not_ofEcm(this, c, pos)
  void *this;
  int c;
  ulong pos;
{
  bool wasZero;
  int thisSize;
  uint i;
  
  thisSize = *(int *)(*(int *)this + -0xc);
  if (thisSize != 0) {
    i = thisSize - 1;
    if (pos < i) {
      i = pos;
    }
    do {
      if (*(char *)(*(int *)this + i) != c) {
        return i;
      }
      wasZero = i != 0;
      i = i - 1;
    } while (wasZero);
  }
  return 0xffffffff;
}

/* std__string__substr @ 0x97c15fa0 (112 bytes) */
int std__string__substr(retStr, str, pos, n)
  ulong retStr;
  ulong str;
  uint pos;
  ulong n;
{
  if (*(uint *)(*(int *)str + -0xc) < pos) {
    std____throw_out_of_range("basic_string::substr");
  }
  __ZNSsC1ERKSsmm((void *)retStr,(unsigned char *)str,pos,n);
  return retStr;
}

/* __ZNKSs7compareERKSs @ 0x97c16010 (96 bytes) */
int __ZNKSs7compareERKSs(this, str)
  void *this;
  unsigned char * str;
{
  int r;
  uint *minRef;
  uint thisSize;
  uint strSize;
  uint thisSizeCopy;
  uint strSizeCopy [4];
  
  minRef = strSizeCopy;
  thisSize = *(uint *)(*(int *)this + -0xc);
  thisSizeCopy = thisSize;
  strSize = *(uint *)(*(int *)str + -0xc);
  strSizeCopy[0] = strSize;
  if (thisSize <= strSize) {
    minRef = &thisSizeCopy;
  }
  r = _memcmp(*(int *)this,*(int *)str,*minRef);
  if (r == 0) {
    r = thisSize - strSize;
  }
  return r;
}

/* __ZNKSs7compareEmmRKSs @ 0x97c16070 (188 bytes) */
int __ZNKSs7compareEmmRKSs(this, pos1, n1, str)
  void *this;
  ulong pos1;
  ulong n1;
  unsigned char * str;
{
  uint rsize;
  int r;
  unsigned int ghidra_home[8] = { this, pos1, n1, str, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint strSize;
  uint *minRef;
  int thisData;
  int strData;
  uint thisSize;
  uint thisSizeMinusPos1;
  uint rsizeCopy;
  uint strSizeCopy [5];
  
  thisData = *(int *)this;
  thisSize = *(uint *)(thisData + -0xc);
  strData = *(int *)str;
  strSizeCopy[0] = *(uint *)(strData + -0xc);
  (*(ulong *)((unsigned char *)ghidra_home + 8)) = n1;
  if (thisSize < pos1) {
    std____throw_out_of_range("basic_string::compare");
    thisData = *(int *)this;
    strData = *(int *)str;
  }
  strSize = strSizeCopy[0];
  thisSizeMinusPos1 = thisSize - pos1;
  minRef = &(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  if (thisSizeMinusPos1 <= (*(ulong *)((unsigned char *)ghidra_home + 8))) {
    minRef = &thisSizeMinusPos1;
  }
  rsize = *minRef;
  minRef = strSizeCopy;
  rsizeCopy = rsize;
  if (rsize <= strSizeCopy[0]) {
    minRef = &rsizeCopy;
  }
  r = _memcmp(thisData + pos1,strData,*minRef);
  if (r == 0) {
    r = rsize - strSize;
  }
  return r;
}

/* __ZNKSs7compareEmmRKSsmm @ 0x97c1612c (240 bytes) */
int __ZNKSs7compareEmmRKSsmm(this, pos1, n1, str, pos2, n2)
  void *this;
  ulong pos1;
  ulong n1;
  unsigned char * str;
  ulong pos2;
  ulong n2;
{
  uint rsize;
  uint osize;
  int r;
  unsigned int ghidra_home[8] = { this, pos1, n1, str, pos2, n2, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint *minRef;
  int thisData;
  int strData;
  uint strSize;
  uint thisSize;
  uint thisSizeMinusPos1;
  uint strSizeMinusPos2;
  uint rsizeCopy;
  uint osizeCopy [2];
  
  thisData = *(int *)this;
  thisSize = *(uint *)(thisData + -0xc);
  strData = *(int *)str;
  strSize = *(uint *)(strData + -0xc);
  (*(ulong *)((unsigned char *)ghidra_home + 8)) = n1;
  (*(ulong *)((unsigned char *)ghidra_home + 20)) = n2;
  if ((thisSize < pos1) || (strSize < pos2)) {
    std____throw_out_of_range("basic_string::compare");
    thisData = *(int *)this;
    strData = *(int *)str;
  }
  thisSizeMinusPos1 = thisSize - pos1;
  minRef = &(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  if (thisSizeMinusPos1 <= (*(ulong *)((unsigned char *)ghidra_home + 8))) {
    minRef = &thisSizeMinusPos1;
  }
  strSizeMinusPos2 = strSize - pos2;
  rsize = *minRef;
  rsizeCopy = rsize;
  minRef = &(*(unsigned int *)((unsigned char *)ghidra_home + 20));
  if (strSizeMinusPos2 <= (*(ulong *)((unsigned char *)ghidra_home + 20))) {
    minRef = &strSizeMinusPos2;
  }
  osize = *minRef;
  minRef = osizeCopy;
  osizeCopy[0] = osize;
  if (rsize <= osize) {
    minRef = &rsizeCopy;
  }
  r = _memcmp(thisData + pos1,strData + pos2,*minRef);
  if (r == 0) {
    r = rsize - osize;
  }
  return r;
}

/* __ZNKSs7compareEPKc @ 0x97c1621c (112 bytes) */
int __ZNKSs7compareEPKc(this, str)
  void *this;
  char *str;
{
  int thisData;
  uint strLen;
  uint *minRef;
  int r;
  uint thisSize;
  uint thisSizeCopy;
  uint strLenCopy [6];
  
  thisData = *(int *)this;
  thisSize = *(uint *)(thisData + -0xc);
  thisSizeCopy = thisSize;
  strLen = _strlen(str);
  minRef = strLenCopy;
  strLenCopy[0] = strLen;
  if (thisSize <= strLen) {
    minRef = &thisSizeCopy;
  }
  r = _memcmp(thisData,str,*minRef);
  if (r == 0) {
    r = thisSize - strLen;
  }
  return r;
}

/* __ZNKSs7compareEmmPKc @ 0x97c1628c (188 bytes) */
int __ZNKSs7compareEmmPKc(this, pos1, n1, str)
  void *this;
  ulong pos1;
  ulong n1;
  char *str;
{
  uint rsize;
  int r;
  unsigned int ghidra_home[8] = { this, pos1, n1, str, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint *minRef;
  uint strLen;
  int thisData;
  uint thisSize;
  uint thisSizeMinusPos1;
  uint rsizeCopy;
  uint strLenCopy [4];
  
  thisData = *(int *)this;
  thisSize = *(uint *)(thisData + -0xc);
  (*(ulong *)((unsigned char *)ghidra_home + 8)) = n1;
  if (thisSize < pos1) {
    std____throw_out_of_range("basic_string::compare");
    thisData = *(int *)this;
  }
  strLen = _strlen(str);
  thisSizeMinusPos1 = thisSize - pos1;
  strLenCopy[0] = strLen;
  minRef = &(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  if (thisSizeMinusPos1 <= (*(ulong *)((unsigned char *)ghidra_home + 8))) {
    minRef = &thisSizeMinusPos1;
  }
  rsize = *minRef;
  minRef = strLenCopy;
  rsizeCopy = rsize;
  if (rsize <= strLen) {
    minRef = &rsizeCopy;
  }
  r = _memcmp(thisData + pos1,str,*minRef);
  if (r == 0) {
    r = rsize - strLen;
  }
  return r;
}

/* __ZNKSs7compareEmmPKcm @ 0x97c16348 (220 bytes) */
int __ZNKSs7compareEmmPKcm(this, pos1, n1, str, pos2)
  void *this;
  ulong pos1;
  ulong n1;
  char *str;
  ulong pos2;
{
  uint osize;
  int r;
  unsigned int ghidra_home[8] = { this, pos1, n1, str, pos2, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint *minRef;
  int thisData;
  uint thisSize;
  uint rsize;
  uint strLenCopy;
  uint thisSizeMinusPos1;
  uint rsizeCopy;
  uint osizeCopy [3];
  
  thisData = *(int *)this;
  thisSize = *(uint *)(thisData + -0xc);
  (*(ulong *)((unsigned char *)ghidra_home + 8)) = n1;
  (*(ulong *)((unsigned char *)ghidra_home + 16)) = pos2;
  if (thisSize < pos1) {
    std____throw_out_of_range("basic_string::compare");
    thisData = *(int *)this;
  }
  strLenCopy = _strlen(str);
  minRef = &(*(unsigned int *)((unsigned char *)ghidra_home + 16));
  if (strLenCopy <= (*(ulong *)((unsigned char *)ghidra_home + 16))) {
    minRef = &strLenCopy;
  }
  thisSizeMinusPos1 = thisSize - pos1;
  osize = *minRef;
  osizeCopy[0] = osize;
  minRef = &(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  if (thisSizeMinusPos1 <= (*(ulong *)((unsigned char *)ghidra_home + 8))) {
    minRef = &thisSizeMinusPos1;
  }
  rsize = *minRef;
  minRef = osizeCopy;
  rsizeCopy = rsize;
  if (rsize <= osize) {
    minRef = &rsizeCopy;
  }
  r = _memcmp(thisData + pos1,str,*minRef);
  if (r == 0) {
    r = rsize - osize;
  }
  return r;
}

/* __ZNSs4_RepixEm @ 0x97c16424 (12 bytes) */
int __ZNSs4_RepixEm(rep, pos)
  void *rep;
  ulong pos;
{
  return (int)rep + pos + 0xc;
}

/* __ZNSs4_Rep9_S_createEmRKSaIcE @ 0x97c16430 (348 bytes) */
int __ZNSs4_Rep9_S_createEmRKSaIcE(capacity, alloc)
  ulong capacity;
  unsigned char * alloc;
{
  undefined *freeListBase;
  uint extraBytes;
  int getenvResult;
  undefined4 atomicStore;
  undefined *forceNewPtr;
  uint adjSize;
  undefined4 *rep;
  int freeListIndex;
  ulong allocSize;
  char reservation;
  byte cr0Reg;
  
  if (0x3ffffffc < capacity) {
    std____throw_length_error("basic_string::_S_create");
  }
  forceNewPtr = PTR__S_force_new_a7b7c0e8;
  adjSize = capacity + 0x1d;
  allocSize = capacity + 0xd;
  if (adjSize < 0x1001) {
    if (allocSize < 0x81) goto LAB_97c164a4;
    extraBytes = 0x80 - (adjSize & 0x7f) & 0x7f;
  }
  else {
    extraBytes = 0x1000 - (adjSize & 0xfff) & 0xfff;
  }
  capacity = capacity + extraBytes;
  allocSize = capacity + 0xd;
LAB_97c164a4:
  rep = (undefined4 *)0x0;
  if (allocSize != 0) {
    if (*(int *)PTR__S_force_new_a7b7c0e8 == 0) {
      getenvResult = _getenv("GLIBCPP_FORCE_NEW");
      if (getenvResult == 0) {
        do {
          if (reservation != '\0') {
            atomicStore = storeWordConditionalIndexed(*(int *)forceNewPtr + -1,0,forceNewPtr);
            *(undefined4 *)forceNewPtr = atomicStore;
            cr0Reg = 2;
          }
        } while (!(bool)(cr0Reg >> 1 & 1));
      }
      else {
        do {
          if (reservation != '\0') {
            atomicStore = storeWordConditionalIndexed(*(int *)forceNewPtr + 1,0,forceNewPtr);
            *(undefined4 *)forceNewPtr = atomicStore;
            cr0Reg = 2;
          }
        } while (!(bool)(cr0Reg >> 1 & 1));
      }
    }
    freeListBase = PTR__S_free_list_a7b7c0e4;
    if ((allocSize < 0x81) && (*(int *)PTR__S_force_new_a7b7c0e8 < 1)) {
      freeListIndex = (allocSize + 7 >> 1 & 0x7ffffffc) - 4;
      _pthread_mutex_lock(PTR__S_node_allocator_lock_a7b7c0e0);
      rep = *(undefined4 **)(freeListBase + freeListIndex);
      if (rep == (undefined4 *)0x0) {
        rep = (undefined4 *)
                 std____default_alloc_template_true_0____S_refill(allocSize + 7 & 0xfffffff8);
      }
      else {
        *(undefined4 *)(freeListBase + freeListIndex) = *rep;
      }
      if (rep == (undefined4 *)0x0) {
        std____throw_bad_alloc();
      }
      _pthread_mutex_unlock(PTR__S_node_allocator_lock_a7b7c0e0);
    }
    else {
      rep = ((int (*)())operator_new)(allocSize);
    }
  }
  rep[1] = capacity;
  *rep = 0;
  rep[2] = 0;
  return rep;
}

/* __ZNSs4_Rep10_M_destroyERKSaIcE @ 0x97c165cc (132 bytes) */
int __ZNSs4_Rep10_M_destroyERKSaIcE(rep, alloc)
  unsigned char * rep;
  uint alloc;
{
  undefined *lockPtr;
  undefined *freeList;
  int freeListIndex;
  
  freeList = PTR__S_free_list_a7b7c0e4;
  lockPtr = PTR__S_node_allocator_lock_a7b7c0e0;
  if ((*(int *)(rep + 4) + 0xdU < 0x81) && (*(int *)PTR__S_force_new_a7b7c0e8 < 1)) {
    freeListIndex = (*(int *)(rep + 4) + 0x14U >> 1 & 0x7ffffffc) - 4;
    _pthread_mutex_lock(PTR__S_node_allocator_lock_a7b7c0e0);
    *(undefined4 *)rep = *(undefined4 *)(freeList + freeListIndex);
    *(unsigned char **)(freeList + freeListIndex) = rep;
    _pthread_mutex_unlock(lockPtr);
  }
  else {
    __ZdlPv(rep);
  }
  return;
}

/* __ZNSs4_Rep8_M_cloneERKSaIcEm @ 0x97c16674 (148 bytes) */
int __ZNSs4_Rep8_M_cloneERKSaIcEm(rep, alloc, res)
  void *rep;
  unsigned char * alloc;
  ulong res;
{
  uint newLen;
  undefined4 *newRep;
  undefined4 copiedLength;
  uint newCapacity;
  
  newLen = *(int *)rep + res;
  newCapacity = newLen;
  if (((*(uint *)((int)rep + 4) < newLen) && (0xfe3 < newLen)) &&
     (newCapacity = *(uint *)((int)rep + 4) << 1, newCapacity < newLen)) {
    newCapacity = newLen;
  }
  newRep = (undefined4 *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(newCapacity,alloc);
  copiedLength = 0;
  if (*(int *)rep != 0) {
    _memcpy(newRep + 3,(int)rep + 0xc,*(int *)rep);
    copiedLength = *(undefined4 *)rep;
  }
  *newRep = copiedLength;
  return newRep + 3;
}

/* __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EPKS3_RKS6_ @ 0x97c16708 (140 bytes) */
int __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EPKS3_RKS6_(result, lhs, rhs)
  char *result;
  unsigned char * lhs;
  unsigned char * rhs;
{
  int lhsLen;
  undefined4 resultBegin;
  undefined4 resultEnd [5];
  
  lhsLen = _strlen(lhs);
  __ZNSsC4Ev(result);
  __ZNSs7reserveEm(result,lhsLen + *(int *)(*(int *)rhs + -0xc));
  __ZNKSs7_M_iendEv(&resultBegin,result);
  __ZNKSs7_M_iendEv(resultEnd,result);
  __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcS4_
            (result,resultBegin,resultEnd[0],lhs,lhs + lhsLen);
  __ZNSs6appendERKSs(result,rhs);
  return result;
}

/* __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ES3_RKS6_ @ 0x97c167c4 (84 bytes) */
int __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ES3_RKS6_(result, lhsChar, rhs)
  void *result;
  unsigned char * lhsChar;
  unsigned char * rhs;
{
  __ZNSsC4Ev(result);
  __ZNSs7reserveEm(result,*(int *)(*(int *)rhs + -0xc) + 1);
  __ZNSs6appendEmc(result,1,lhsChar);
  __ZNSs6appendERKSs(result,rhs);
  return result;
}

/* __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_ @ 0x97c16848 (44 bytes) */
int __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_(result, lhs, rhs)
  unsigned char * result;
  unsigned char * lhs;
  unsigned char * rhs;
{
  __ZNSsC1ERKSs(result,lhs);
  __ZNSs6appendERKSs(result,rhs);
  return result;
}

/* __ZN9__gnu_cxxeqIPcSsEEbRKNS_17__normal_iteratorIT_T0_EES7_ @ 0x97c168a4 (24 bytes) */
int __ZN9__gnu_cxxeqIPcSsEEbRKNS_17__normal_iteratorIT_T0_EES7_(lhs, rhs)
  unsigned char * lhs;
  unsigned char * rhs;
{
  return *(int *)lhs == *(int *)rhs;
}

/* __ZN9__gnu_cxxeqIPKcSsEEbRKNS_17__normal_iteratorIT_T0_EES8_ @ 0x97c168bc (24 bytes) */
int __ZN9__gnu_cxxeqIPKcSsEEbRKNS_17__normal_iteratorIT_T0_EES8_(lhs, rhs)
  unsigned char * lhs;
  unsigned char * rhs;
{
  return *(int *)lhs == *(int *)rhs;
}

/* __ZNSsC2IPcEET_S1_RKSaIcE @ 0x97c168d4 (4 bytes) */
int __ZNSsC2IPcEET_S1_RKSaIcE(this, str1, str2, allocator)
  void *this;
  char *str1;
  char *str2;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4IPcEET_S1_RKSaIcE)(this,str1,str2,allocator);
}

/* __ZNSsC1IPcEET_S1_RKSaIcE @ 0x97c168d8 (4 bytes) */
int __ZNSsC1IPcEET_S1_RKSaIcE(this, str1, str2, allocator)
  void *this;
  char *str1;
  char *str2;
  unsigned char * allocator;
{
  char *string___S_construct_char__Result;
  
  string___S_construct_char__Result = ((int (*)())std__string___S_construct_char__)(str1,str2,allocator,0);
  return __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,string___S_construct_char__Result,allocator);
}

/* __ZNSsC4IPcEET_S1_RKSaIcE @ 0x97c168dc (80 bytes) */
int __ZNSsC4IPcEET_S1_RKSaIcE(this, str1, str2, allocator)
  void *this;
  char *str1;
  char *str2;
  unsigned char * allocator;
{
  char *string___S_construct_char__Result;
  
  string___S_construct_char__Result = ((int (*)())std__string___S_construct_char__)(str1,str2,allocator,0);
  return __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,string___S_construct_char__Result,allocator);
}

/* __ZNSsC2IPKcEET_S2_RKSaIcE @ 0x97c1692c (4 bytes) */
int __ZNSsC2IPKcEET_S2_RKSaIcE(this, str1, str2, allocator)
  void *this;
  char *str1;
  char *str2;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4IPKcEET_S2_RKSaIcE)(this,str1,str2,allocator);
}

/* __ZNSsC1IPKcEET_S2_RKSaIcE @ 0x97c16930 (4 bytes) */
int __ZNSsC1IPKcEET_S2_RKSaIcE(this, str1, str2, allocator)
  void *this;
  char *str1;
  char *str2;
  unsigned char * allocator;
{
  char *newData;
  
  newData = ((int (*)())__ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag)(str1,str2,allocator,0);
  return __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,newData,allocator);
}

/* __ZNSsC4IPKcEET_S2_RKSaIcE @ 0x97c16934 (80 bytes) */
int __ZNSsC4IPKcEET_S2_RKSaIcE(this, str1, str2, allocator)
  void *this;
  char *str1;
  char *str2;
  unsigned char * allocator;
{
  char *newData;
  
  newData = ((int (*)())__ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag)(str1,str2,allocator,0);
  return __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,newData,allocator);
}

/* __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE @ 0x97c16984 (4 bytes) */
int __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE(this, first, last, allocator)
  void *this;
  undefined4 first;
  undefined4 last;
  undefined4 allocator;
{
  return ((int (*)())__ZNSsC4IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE)(this,first,last,allocator);
}

/* __ZNSsC1IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE @ 0x97c16988 (4 bytes) */
int __ZNSsC1IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE(this, first, last, allocator)
  void *this;
  undefined4 first;
  undefined4 last;
  unsigned char * allocator;
{
  char *newData;
  
  newData = ((int (*)())__ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag)(first,last,allocator,0);
  return __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,newData,allocator);
}

/* __ZNSsC4IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE @ 0x97c1698c (80 bytes) */
int __ZNSsC4IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE(this, first, last, allocator)
  void *this;
  undefined4 first;
  undefined4 last;
  unsigned char * allocator;
{
  char *newData;
  
  newData = ((int (*)())__ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag)(first,last,allocator,0);
  return __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,newData,allocator);
}

/* __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE @ 0x97c169dc (4 bytes) */
int __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE(this, first, last, allocator)
  void *this;
  undefined4 first;
  undefined4 last;
  undefined4 allocator;
{
  return ((int (*)())__ZNSsC4IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE)(this,first,last,allocator);
}

/* __ZNSsC1IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE @ 0x97c169e0 (4 bytes) */
int __ZNSsC1IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE(this, first, last, allocator)
  void *this;
  undefined4 first;
  undefined4 last;
  unsigned char * allocator;
{
  char *string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__Result;
  
  string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__Result = ((int (*)())std__string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__)(first,last,allocator,0);
  return __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__Result,allocator);
}

/* __ZNSsC4IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE @ 0x97c169e4 (80 bytes) */
int __ZNSsC4IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE(this, first, last, allocator)
  void *this;
  undefined4 first;
  undefined4 last;
  unsigned char * allocator;
{
  char *string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__Result;
  
  string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__Result = ((int (*)())std__string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__)(first,last,allocator,0);
  return __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__Result,allocator);
}

/* std__string___M_replace___gnu_cxx____normal_iterator_char__std__string__ @ 0x97c16a34 (108 bytes) */
int std__string___M_replace___gnu_cxx____normal_iterator_char__std__string__(this, i1, i2, k1, k2)
  void *this;
  undefined4 i1;
  undefined4 i2;
  undefined4 k1;
  undefined4 k2;
{
  unsigned char * result;
  undefined1 tmpStr [16];
  undefined1 tmpAlloc [16];
  undefined4 tmpBegin;
  undefined4 tmpEnd [6];
  
  ((int (*)())__ZNSsC1IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE)(tmpStr,k1,k2,tmpAlloc);
  __ZNKSs9_M_ibeginEv(&tmpBegin,tmpStr);
  __ZNKSs7_M_iendEv(tmpEnd,tmpStr);
  result = ((int (*)())__ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_)(this,i1,i2,tmpBegin,tmpEnd[0]);
  __ZNSsD4Ev(tmpStr);
  return result;
}

/* std__string___M_replace___gnu_cxx____normal_iterator_char_const__std__string__ @ 0x97c16ae4 (108 bytes) */
int std__string___M_replace___gnu_cxx____normal_iterator_char_const__std__string__(this, i1, i2, k1, k2)
  void *this;
  undefined4 i1;
  undefined4 i2;
  undefined4 k1;
  undefined4 k2;
{
  unsigned char * result;
  undefined1 tmpStr [16];
  undefined1 tmpAlloc [16];
  undefined4 tmpBegin;
  undefined4 tmpEnd [6];
  
  ((int (*)())__ZNSsC1IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE)(tmpStr,k1,k2,tmpAlloc);
  __ZNKSs9_M_ibeginEv(&tmpBegin,tmpStr);
  __ZNKSs7_M_iendEv(tmpEnd,tmpStr);
  result = ((int (*)())__ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_)(this,i1,i2,tmpBegin,tmpEnd[0]);
  __ZNSsD4Ev(tmpStr);
  return result;
}

/* std__string___M_replace_char__ @ 0x97c16b94 (108 bytes) */
int std__string___M_replace_char__(this, i1, i2, k1, k2)
  void *this;
  undefined4 i1;
  undefined4 i2;
  char *k1;
  char *k2;
{
  unsigned char * result;
  undefined1 tmpStr [16];
  unsigned char tmpAlloc [16];
  undefined4 tmpBegin;
  undefined4 tmpEnd [6];
  
  ((int (*)())__ZNSsC1IPcEET_S1_RKSaIcE)(tmpStr,k1,k2,tmpAlloc);
  __ZNKSs9_M_ibeginEv(&tmpBegin,tmpStr);
  __ZNKSs7_M_iendEv(tmpEnd,tmpStr);
  result = ((int (*)())__ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_)(this,i1,i2,tmpBegin,tmpEnd[0]);
  __ZNSsD4Ev(tmpStr);
  return result;
}

/* __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag @ 0x97c16c44 (108 bytes) */
int __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag(this, i1, i2, k1, k2, input_iterator_tag)
  void *this;
  undefined4 i1;
  char *i2;
  char *k1;
  char *k2;
  uint input_iterator_tag;
{
  unsigned char * result;
  undefined1 tmpStr [16];
  unsigned char tmpAlloc [16];
  undefined4 tmpBegin;
  undefined4 tmpEnd [6];
  
  ((int (*)())__ZNSsC1IPKcEET_S2_RKSaIcE)(tmpStr,k1,k2,tmpAlloc);
  __ZNKSs9_M_ibeginEv(&tmpBegin,tmpStr);
  __ZNKSs7_M_iendEv(tmpEnd,tmpStr);
  result = ((int (*)())__ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_)(this,i1,i2,tmpBegin,tmpEnd[0]);
  __ZNSsD4Ev(tmpStr);
  return result;
}

/* __ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_ @ 0x97c16cf4 (168 bytes) */
int __ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_(this, i1, i2, k1, k2)
  void *this;
  int i1;
  int i2;
  int k1;
  int k2;
{
  uint dnew;
  int ibegin [5];
  
  dnew = k2 - k1;
  if (0x3ffffffb < dnew) {
    std____throw_length_error("basic_string::_M_replace");
  }
  __ZNKSs9_M_ibeginEv(ibegin,this);
  __ZNSs9_M_mutateEmmm(this,i1 - ibegin[0],i2 - i1,dnew);
  if (dnew != 0) {
    __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIS_SsEES2_
              ((char *)(*(int *)this + (i1 - ibegin[0])),k1,k2);
  }
  return this;
}

/* std__string___M_replace_safe___gnu_cxx____normal_iterator_char_const__std__string__ @ 0x97c16d9c (168 bytes) */
int std__string___M_replace_safe___gnu_cxx____normal_iterator_char_const__std__string__(this, i1, i2, k1, k2)
  unsigned char * this;
  int i1;
  int i2;
  int k1;
  int k2;
{
  uint dnew;
  int ibegin [5];
  
  dnew = k2 - k1;
  if (0x3ffffffb < dnew) {
    std____throw_length_error("basic_string::_M_replace");
  }
  __ZNKSs9_M_ibeginEv(ibegin,this);
  __ZNSs9_M_mutateEmmm(this,i1 - ibegin[0],i2 - i1,dnew);
  if (dnew != 0) {
    __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIPKcSsEES4_
              ((char *)(*(int *)this + (i1 - ibegin[0])),k1,k2);
  }
  return this;
}

/* std__string___M_replace_safe_char__ @ 0x97c16e44 (164 bytes) */
int std__string___M_replace_safe_char__(this, i1, i2, k1, k2)
  unsigned char * this;
  int i1;
  int i2;
  int k1;
  int k2;
{
  uint dnew;
  int ibegin [6];
  
  dnew = k2 - k1;
  if (0x3ffffffb < dnew) {
    std____throw_length_error("basic_string::_M_replace");
  }
  __ZNKSs9_M_ibeginEv(ibegin,this);
  __ZNSs9_M_mutateEmmm(this,i1 - ibegin[0],i2 - i1,dnew);
  if (dnew != 0) {
    _memcpy(*(int *)this + (i1 - ibegin[0]),k1,dnew);
  }
  return this;
}

/* __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_ @ 0x97c16ee8 (164 bytes) */
int __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_(this, i1, i2, k1, k2)
  void *this;
  int i1;
  int i2;
  char *k1;
  char *k2;
{
  uint dnew;
  int ibegin [6];
  
  dnew = (int)k2 - (int)k1;
  if (0x3ffffffb < dnew) {
    std____throw_length_error("basic_string::_M_replace");
  }
  __ZNKSs9_M_ibeginEv(ibegin,this);
  __ZNSs9_M_mutateEmmm(this,i1 - ibegin[0],i2 - i1,dnew);
  if (dnew != 0) {
    _memcpy(*(int *)this + (i1 - ibegin[0]),k1,dnew);
  }
  return this;
}

/* __ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag @ 0x97c16f8c (152 bytes) */
int __ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag(beg, end, alloc, allocator)
  int beg;
  int end;
  unsigned char * alloc;
  undefined4 allocator;
{
  ulong *data;
  ulong *rep;
  ulong dnew;
  char reservation;
  byte cr0Reg;
  
  if (beg == end) {
    do {
      if (reservation != '\0') {
        DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    data = (ulong *)&DAT_a7b7bf90;
  }
  else {
    dnew = end - beg;
    rep = (ulong *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(dnew,alloc);
    data = rep + 3;
    __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIS_SsEES2_((char *)data,beg,end)
    ;
    *rep = dnew;
    *(undefined1 *)((int)data + dnew) = 0;
  }
  return (char *)data;
}

/* std__string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__ @ 0x97c17024 (152 bytes) */
int std__string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__(beg, end, alloc, allocator)
  int beg;
  int end;
  unsigned char * alloc;
  undefined4 allocator;
{
  ulong *data;
  ulong *rep;
  ulong dnew;
  char reservation;
  byte cr0Reg;
  
  if (beg == end) {
    do {
      if (reservation != '\0') {
        DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    data = (ulong *)&DAT_a7b7bf90;
  }
  else {
    dnew = end - beg;
    rep = (ulong *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(dnew,alloc);
    data = rep + 3;
    __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIPKcSsEES4_
              ((char *)data,beg,end);
    *rep = dnew;
    *(undefined1 *)((int)data + dnew) = 0;
  }
  return (char *)data;
}

/* std__string___S_construct_char__ @ 0x97c170bc (176 bytes) */
int std__string___S_construct_char__(beg, end, alloc, allocator)
  char *beg;
  char *end;
  unsigned char * alloc;
  undefined4 allocator;
{
  ulong *data;
  ulong *rep;
  ulong dnew;
  char reservation;
  byte cr0Reg;
  
  if (beg == end) {
    do {
      if (reservation != '\0') {
        DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    data = (ulong *)&DAT_a7b7bf90;
  }
  else {
    if (beg == (char *)0x0) {
      std____throw_logic_error("attempt to create string with null pointer");
    }
    dnew = (int)end - (int)beg;
    rep = (ulong *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(dnew,alloc);
    data = rep + 3;
    _memcpy(data,beg,dnew);
    *rep = dnew;
    *(char *)((int)data + dnew) = '\0';
  }
  return (char *)data;
}

/* __ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag @ 0x97c1716c (176 bytes) */
int __ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag(beg, end, alloc, allocator)
  char *beg;
  char *end;
  unsigned char * alloc;
  undefined4 allocator;
{
  ulong *data;
  ulong *rep;
  ulong dnew;
  char reservation;
  byte cr0Reg;
  
  if (beg == end) {
    do {
      if (reservation != '\0') {
        DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    data = (ulong *)&DAT_a7b7bf90;
  }
  else {
    if (beg == (char *)0x0) {
      std____throw_logic_error("attempt to create string with null pointer");
    }
    dnew = (int)end - (int)beg;
    rep = (ulong *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(dnew,alloc);
    data = rep + 3;
    _memcpy(data,beg,dnew);
    *rep = dnew;
    *(char *)((int)data + dnew) = '\0';
  }
  return (char *)data;
}

/* __ZSt13__destroy_auxIPSsEvT_S1_12__false_type @ 0x97c1721c (76 bytes) */
int __ZSt13__destroy_auxIPSsEvT_S1_12__false_type(first, last, falseType)
  unsigned char * first;
  unsigned char * last;
  undefined4 falseType;
{
  unsigned char * lastResult;
  
  lastResult = first;
  for (; first != last; first = first + 4) {
    lastResult = (unsigned char *)__ZNSsD4Ev(first);
  }
  return lastResult;
}

/* operator_new @ 0x97c17268 (144 bytes) */
int operator_new(sz)
  ulong sz;
{
  undefined *badAllocDtor;
  undefined *badAllocTypeinfo;
  void *allocation;
  code *newHandler;
  undefined4 *badAlloc;
  
  if (sz == 0) {
    sz = 1;
  }
  allocation = (void *)_malloc(sz);
  while( true ) {
    if (allocation != (void *)0x0) {
      return allocation;
    }
    newHandler = (code *)__keymgr_get_per_thread_data(2);
    if (newHandler == (code *)0x0) break;
    (*newHandler)(newHandler);
    allocation = (void *)_malloc(sz);
  }
  badAlloc = (undefined4 *)___cxa_allocate_exception(4);
  badAllocTypeinfo = PTR_typeinfo_a7b7c174;
  badAllocDtor = PTR___ZNSt9bad_allocD1Ev_a7b7c170;
  *badAlloc = PTR_vtable_a7b7c178 + 8;
                    
  ___cxa_throw(badAlloc,badAllocTypeinfo,badAllocDtor);
}

/* ___cxa_pure_virtual @ 0x97c1731c (48 bytes) */
int ___cxa_pure_virtual()
{
  void *terminateResult;
  
  _write(2,"pure virtual method called\n",0x1b);
  terminateResult = (void *)std__terminate();
  if (terminateResult != (void *)0x0) {
    _free(terminateResult);
  }
  return;
}

