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
int __ZNSs4_RepixEm(this, pos)
  void *this;
  ulong pos;
{
  return (int)this + pos + 0xc;
}

/* __ZNSs4_Rep9_S_createEmRKSaIcE @ 0x97c16430 (348 bytes) */
int __ZNSs4_Rep9_S_createEmRKSaIcE(this, param_2)
  ulong this;
  unsigned char * param_2;
{
  int getenvResult;
  undefined4 atomicStore;
  undefined *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  ulong uVar6;
  char reservation;
  byte cr0Reg;
  
  if (0x3ffffffc < this) {
    std____throw_length_error("basic_string::_S_create");
  }
  puVar2 = PTR__S_force_new_a7b7c0e8;
  uVar3 = this + 0x1d;
  uVar6 = this + 0xd;
  if (uVar3 < 0x1001) {
    if (uVar6 < 0x81) goto LAB_97c164a4;
    uVar3 = 0x80 - (uVar3 & 0x7f) & 0x7f;
  }
  else {
    uVar3 = 0x1000 - (uVar3 & 0xfff) & 0xfff;
  }
  this = this + uVar3;
  uVar6 = this + 0xd;
LAB_97c164a4:
  puVar4 = (undefined4 *)0x0;
  if (uVar6 != 0) {
    if (*(int *)PTR__S_force_new_a7b7c0e8 == 0) {
      getenvResult = _getenv("GLIBCPP_FORCE_NEW");
      if (getenvResult == 0) {
        do {
          if (reservation != '\0') {
            atomicStore = storeWordConditionalIndexed(*(int *)puVar2 + -1,0,puVar2);
            *(undefined4 *)puVar2 = atomicStore;
            cr0Reg = 2;
          }
        } while (!(bool)(cr0Reg >> 1 & 1));
      }
      else {
        do {
          if (reservation != '\0') {
            atomicStore = storeWordConditionalIndexed(*(int *)puVar2 + 1,0,puVar2);
            *(undefined4 *)puVar2 = atomicStore;
            cr0Reg = 2;
          }
        } while (!(bool)(cr0Reg >> 1 & 1));
      }
    }
    puVar2 = PTR__S_free_list_a7b7c0e4;
    if ((uVar6 < 0x81) && (*(int *)PTR__S_force_new_a7b7c0e8 < 1)) {
      iVar5 = (uVar6 + 7 >> 1 & 0x7ffffffc) - 4;
      _pthread_mutex_lock(PTR__S_node_allocator_lock_a7b7c0e0);
      puVar4 = *(undefined4 **)(puVar2 + iVar5);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)
                 std____default_alloc_template_true_0____S_refill(uVar6 + 7 & 0xfffffff8);
      }
      else {
        *(undefined4 *)(puVar2 + iVar5) = *puVar4;
      }
      if (puVar4 == (undefined4 *)0x0) {
        std____throw_bad_alloc();
      }
      _pthread_mutex_unlock(PTR__S_node_allocator_lock_a7b7c0e0);
    }
    else {
      puVar4 = ((int (*)())operator_new)(uVar6);
    }
  }
  puVar4[1] = this;
  *puVar4 = 0;
  puVar4[2] = 0;
  return puVar4;
}

/* __ZNSs4_Rep10_M_destroyERKSaIcE @ 0x97c165cc (132 bytes) */
int __ZNSs4_Rep10_M_destroyERKSaIcE(this, allocator)
  unsigned char * this;
  uint allocator;
{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = PTR__S_free_list_a7b7c0e4;
  puVar1 = PTR__S_node_allocator_lock_a7b7c0e0;
  if ((*(int *)(this + 4) + 0xdU < 0x81) && (*(int *)PTR__S_force_new_a7b7c0e8 < 1)) {
    iVar3 = (*(int *)(this + 4) + 0x14U >> 1 & 0x7ffffffc) - 4;
    _pthread_mutex_lock(PTR__S_node_allocator_lock_a7b7c0e0);
    *(undefined4 *)this = *(undefined4 *)(puVar2 + iVar3);
    *(unsigned char **)(puVar2 + iVar3) = this;
    _pthread_mutex_unlock(puVar1);
  }
  else {
    __ZdlPv(this);
  }
  return;
}

/* __ZNSs4_Rep8_M_cloneERKSaIcEm @ 0x97c16674 (148 bytes) */
int __ZNSs4_Rep8_M_cloneERKSaIcEm(this, allocator, param_3)
  void *this;
  unsigned char * allocator;
  ulong param_3;
{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar4;
  uint uVar3;
  
  uVar1 = *(int *)this + param_3;
  uVar3 = uVar1;
  if (((*(uint *)((int)this + 4) < uVar1) && (0xfe3 < uVar1)) &&
     (uVar3 = *(uint *)((int)this + 4) << 1, uVar3 < uVar1)) {
    uVar3 = uVar1;
  }
  puVar2 = (undefined4 *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(uVar3,allocator);
  uVar4 = 0;
  if (*(int *)this != 0) {
    _memcpy(puVar2 + 3,(int)this + 0xc,*(int *)this);
    uVar4 = *(undefined4 *)this;
  }
  *puVar2 = uVar4;
  return puVar2 + 3;
}

/* __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EPKS3_RKS6_ @ 0x97c16708 (140 bytes) */
int __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EPKS3_RKS6_(this, str, text)
  char *this;
  unsigned char * str;
  unsigned char * text;
{
  int length;
  undefined4 local_30;
  undefined4 local_2c [5];
  
  length = _strlen(str);
  __ZNSsC4Ev(this);
  __ZNSs7reserveEm(this,length + *(int *)(*(int *)text + -0xc));
  __ZNKSs7_M_iendEv(&local_30,this);
  __ZNKSs7_M_iendEv(local_2c,this);
  __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcS4_
            (this,local_30,local_2c[0],str,str + length);
  __ZNSs6appendERKSs(this,text);
  return this;
}

/* __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ES3_RKS6_ @ 0x97c167c4 (84 bytes) */
int __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ES3_RKS6_(this, param_2, text)
  void *this;
  unsigned char * param_2;
  unsigned char * text;
{
  __ZNSsC4Ev(this);
  __ZNSs7reserveEm(this,*(int *)(*(int *)text + -0xc) + 1);
  __ZNSs6appendEmc(this,1,param_2);
  __ZNSs6appendERKSs(this,text);
  return this;
}

/* __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_ @ 0x97c16848 (44 bytes) */
int __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_(this, text1, text2)
  unsigned char * this;
  unsigned char * text1;
  unsigned char * text2;
{
  __ZNSsC1ERKSs(this,text1);
  __ZNSs6appendERKSs(this,text2);
  return this;
}

/* __ZN9__gnu_cxxeqIPcSsEEbRKNS_17__normal_iteratorIT_T0_EES7_ @ 0x97c168a4 (24 bytes) */
int __ZN9__gnu_cxxeqIPcSsEEbRKNS_17__normal_iteratorIT_T0_EES7_(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  return *(int *)this == *(int *)param_2;
}

/* __ZN9__gnu_cxxeqIPKcSsEEbRKNS_17__normal_iteratorIT_T0_EES8_ @ 0x97c168bc (24 bytes) */
int __ZN9__gnu_cxxeqIPKcSsEEbRKNS_17__normal_iteratorIT_T0_EES8_(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  return *(int *)this == *(int *)param_2;
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
  char *pcVar1;
  
  pcVar1 = ((int (*)())__ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag)(str1,str2,allocator,0);
  return __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,pcVar1,allocator);
}

/* __ZNSsC4IPKcEET_S2_RKSaIcE @ 0x97c16934 (80 bytes) */
int __ZNSsC4IPKcEET_S2_RKSaIcE(this, str1, str2, allocator)
  void *this;
  char *str1;
  char *str2;
  unsigned char * allocator;
{
  char *pcVar1;
  
  pcVar1 = ((int (*)())__ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag)(str1,str2,allocator,0);
  return __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,pcVar1,allocator);
}

/* __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE @ 0x97c16984 (4 bytes) */
int __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE(this, param_2, param_3, allocator)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 allocator;
{
  return ((int (*)())__ZNSsC4IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE)(this,param_2,param_3,allocator);
}

/* __ZNSsC1IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE @ 0x97c16988 (4 bytes) */
int __ZNSsC1IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE(this, param_2, param_3, allocator)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  unsigned char * allocator;
{
  char *pcVar1;
  
  pcVar1 = ((int (*)())__ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag)(param_2,param_3,allocator,0);
  return __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,pcVar1,allocator);
}

/* __ZNSsC4IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE @ 0x97c1698c (80 bytes) */
int __ZNSsC4IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE(this, param_2, param_3, allocator)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  unsigned char * allocator;
{
  char *pcVar1;
  
  pcVar1 = ((int (*)())__ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag)(param_2,param_3,allocator,0);
  return __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,pcVar1,allocator);
}

/* __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE @ 0x97c169dc (4 bytes) */
int __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE(this, param_2, param_3, allocator)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 allocator;
{
  return ((int (*)())__ZNSsC4IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE)(this,param_2,param_3,allocator);
}

/* __ZNSsC1IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE @ 0x97c169e0 (4 bytes) */
int __ZNSsC1IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE(this, param_2, param_3, allocator)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  unsigned char * allocator;
{
  char *string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__Result;
  
  string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__Result = ((int (*)())std__string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__)(param_2,param_3,allocator,0);
  return __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__Result,allocator);
}

/* __ZNSsC4IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE @ 0x97c169e4 (80 bytes) */
int __ZNSsC4IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE(this, param_2, param_3, allocator)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  unsigned char * allocator;
{
  char *string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__Result;
  
  string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__Result = ((int (*)())std__string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__)(param_2,param_3,allocator,0);
  return __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__Result,allocator);
}

/* std__string___M_replace___gnu_cxx____normal_iterator_char__std__string__ @ 0x97c16a34 (108 bytes) */
int std__string___M_replace___gnu_cxx____normal_iterator_char__std__string__(this, param_2, param_3, param_4, param_5)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  unsigned char * psVar1;
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined4 local_30;
  undefined4 local_2c [6];
  
  ((int (*)())__ZNSsC1IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE)(auStack_50,param_4,param_5,auStack_40);
  __ZNKSs9_M_ibeginEv(&local_30,auStack_50);
  __ZNKSs7_M_iendEv(local_2c,auStack_50);
  psVar1 = ((int (*)())__ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_)(this,param_2,param_3,local_30,local_2c[0]);
  __ZNSsD4Ev(auStack_50);
  return psVar1;
}

/* std__string___M_replace___gnu_cxx____normal_iterator_char_const__std__string__ @ 0x97c16ae4 (108 bytes) */
int std__string___M_replace___gnu_cxx____normal_iterator_char_const__std__string__(this, param_2, param_3, param_4, param_5)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  unsigned char * psVar1;
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined4 local_30;
  undefined4 local_2c [6];
  
  ((int (*)())__ZNSsC1IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE)(auStack_50,param_4,param_5,auStack_40);
  __ZNKSs9_M_ibeginEv(&local_30,auStack_50);
  __ZNKSs7_M_iendEv(local_2c,auStack_50);
  psVar1 = ((int (*)())__ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_)(this,param_2,param_3,local_30,local_2c[0]);
  __ZNSsD4Ev(auStack_50);
  return psVar1;
}

/* std__string___M_replace_char__ @ 0x97c16b94 (108 bytes) */
int std__string___M_replace_char__(this, param_2, param_3, str1, str2)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  char *str1;
  char *str2;
{
  unsigned char * psVar1;
  undefined1 auStack_50 [16];
  unsigned char aaStack_40 [16];
  undefined4 local_30;
  undefined4 local_2c [6];
  
  ((int (*)())__ZNSsC1IPcEET_S1_RKSaIcE)(auStack_50,str1,str2,aaStack_40);
  __ZNKSs9_M_ibeginEv(&local_30,auStack_50);
  __ZNKSs7_M_iendEv(local_2c,auStack_50);
  psVar1 = ((int (*)())__ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_)(this,param_2,param_3,local_30,local_2c[0]);
  __ZNSsD4Ev(auStack_50);
  return psVar1;
}

/* __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag @ 0x97c16c44 (108 bytes) */
int __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag(this, param_2, i1, str1, str2, input_iterator_tag)
  void *this;
  undefined4 param_2;
  char *i1;
  char *str1;
  char *str2;
  uint input_iterator_tag;
{
  unsigned char * psVar1;
  undefined1 auStack_50 [16];
  unsigned char aaStack_40 [16];
  undefined4 local_30;
  undefined4 local_2c [6];
  
  ((int (*)())__ZNSsC1IPKcEET_S2_RKSaIcE)(auStack_50,str1,str2,aaStack_40);
  __ZNKSs9_M_ibeginEv(&local_30,auStack_50);
  __ZNKSs7_M_iendEv(local_2c,auStack_50);
  psVar1 = ((int (*)())__ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_)(this,param_2,i1,local_30,local_2c[0]);
  __ZNSsD4Ev(auStack_50);
  return psVar1;
}

/* __ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_ @ 0x97c16cf4 (168 bytes) */
int __ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_(this, param_2, param_3, str, param_5)
  void *this;
  int param_2;
  int param_3;
  int str;
  int param_5;
{
  uint uVar1;
  int local_30 [5];
  
  uVar1 = param_5 - str;
  if (0x3ffffffb < uVar1) {
    std____throw_length_error("basic_string::_M_replace");
  }
  __ZNKSs9_M_ibeginEv(local_30,this);
  __ZNSs9_M_mutateEmmm(this,param_2 - local_30[0],param_3 - param_2,uVar1);
  if (uVar1 != 0) {
    __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIS_SsEES2_
              ((char *)(*(int *)this + (param_2 - local_30[0])),str,param_5);
  }
  return this;
}

/* std__string___M_replace_safe___gnu_cxx____normal_iterator_char_const__std__string__ @ 0x97c16d9c (168 bytes) */
int std__string___M_replace_safe___gnu_cxx____normal_iterator_char_const__std__string__(this, param_2, param_3, str, param_5)
  unsigned char * this;
  int param_2;
  int param_3;
  int str;
  int param_5;
{
  uint uVar1;
  int local_30 [5];
  
  uVar1 = param_5 - str;
  if (0x3ffffffb < uVar1) {
    std____throw_length_error("basic_string::_M_replace");
  }
  __ZNKSs9_M_ibeginEv(local_30,this);
  __ZNSs9_M_mutateEmmm(this,param_2 - local_30[0],param_3 - param_2,uVar1);
  if (uVar1 != 0) {
    __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIPKcSsEES4_
              ((char *)(*(int *)this + (param_2 - local_30[0])),str,param_5);
  }
  return this;
}

/* std__string___M_replace_safe_char__ @ 0x97c16e44 (164 bytes) */
int std__string___M_replace_safe_char__(this, param_2, param_3, str1, str2)
  unsigned char * this;
  int param_2;
  int param_3;
  int str1;
  int str2;
{
  uint uVar1;
  int local_30 [6];
  
  uVar1 = str2 - str1;
  if (0x3ffffffb < uVar1) {
    std____throw_length_error("basic_string::_M_replace");
  }
  __ZNKSs9_M_ibeginEv(local_30,this);
  __ZNSs9_M_mutateEmmm(this,param_2 - local_30[0],param_3 - param_2,uVar1);
  if (uVar1 != 0) {
    _memcpy(*(int *)this + (param_2 - local_30[0]),str1,uVar1);
  }
  return this;
}

/* __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_ @ 0x97c16ee8 (164 bytes) */
int __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_(this, param_2, i1, str1, str2)
  void *this;
  int param_2;
  int i1;
  char *str1;
  char *str2;
{
  uint uVar1;
  int local_30 [6];
  
  uVar1 = (int)str2 - (int)str1;
  if (0x3ffffffb < uVar1) {
    std____throw_length_error("basic_string::_M_replace");
  }
  __ZNKSs9_M_ibeginEv(local_30,this);
  __ZNSs9_M_mutateEmmm(this,param_2 - local_30[0],i1 - param_2,uVar1);
  if (uVar1 != 0) {
    _memcpy(*(int *)this + (param_2 - local_30[0]),str1,uVar1);
  }
  return this;
}

/* __ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag @ 0x97c16f8c (152 bytes) */
int __ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag(this, param_2, param_3, allocator)
  int this;
  int param_2;
  unsigned char * param_3;
  undefined4 allocator;
{
  ulong *puVar1;
  ulong *puVar2;
  ulong uVar3;
  char reservation;
  byte cr0Reg;
  
  if (this == param_2) {
    do {
      if (reservation != '\0') {
        DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    puVar1 = (ulong *)&DAT_a7b7bf90;
  }
  else {
    uVar3 = param_2 - this;
    puVar2 = (ulong *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(uVar3,param_3);
    puVar1 = puVar2 + 3;
    __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIS_SsEES2_((char *)puVar1,this,param_2)
    ;
    *puVar2 = uVar3;
    *(undefined1 *)((int)puVar1 + uVar3) = 0;
  }
  return (char *)puVar1;
}

/* std__string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__ @ 0x97c17024 (152 bytes) */
int std__string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__(this, param_2, param_3, allocator)
  int this;
  int param_2;
  unsigned char * param_3;
  undefined4 allocator;
{
  ulong *puVar1;
  ulong *puVar2;
  ulong uVar3;
  char reservation;
  byte cr0Reg;
  
  if (this == param_2) {
    do {
      if (reservation != '\0') {
        DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    puVar1 = (ulong *)&DAT_a7b7bf90;
  }
  else {
    uVar3 = param_2 - this;
    puVar2 = (ulong *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(uVar3,param_3);
    puVar1 = puVar2 + 3;
    __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIPKcSsEES4_
              ((char *)puVar1,this,param_2);
    *puVar2 = uVar3;
    *(undefined1 *)((int)puVar1 + uVar3) = 0;
  }
  return (char *)puVar1;
}

/* std__string___S_construct_char__ @ 0x97c170bc (176 bytes) */
int std__string___S_construct_char__(this, str1, str2, allocator)
  char *this;
  char *str1;
  unsigned char * str2;
  undefined4 allocator;
{
  ulong *puVar1;
  ulong *puVar2;
  ulong uVar3;
  char reservation;
  byte cr0Reg;
  
  if (this == str1) {
    do {
      if (reservation != '\0') {
        DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    puVar1 = (ulong *)&DAT_a7b7bf90;
  }
  else {
    if (this == (char *)0x0) {
      std____throw_logic_error("attempt to create string with null pointer");
    }
    uVar3 = (int)str1 - (int)this;
    puVar2 = (ulong *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(uVar3,str2);
    puVar1 = puVar2 + 3;
    _memcpy(puVar1,this,uVar3);
    *puVar2 = uVar3;
    *(char *)((int)puVar1 + uVar3) = '\0';
  }
  return (char *)puVar1;
}

/* __ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag @ 0x97c1716c (176 bytes) */
int __ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag(this, str1, str2, allocator)
  char *this;
  char *str1;
  unsigned char * str2;
  undefined4 allocator;
{
  ulong *puVar1;
  ulong *puVar2;
  ulong uVar3;
  char reservation;
  byte cr0Reg;
  
  if (this == str1) {
    do {
      if (reservation != '\0') {
        DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    puVar1 = (ulong *)&DAT_a7b7bf90;
  }
  else {
    if (this == (char *)0x0) {
      std____throw_logic_error("attempt to create string with null pointer");
    }
    uVar3 = (int)str1 - (int)this;
    puVar2 = (ulong *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(uVar3,str2);
    puVar1 = puVar2 + 3;
    _memcpy(puVar1,this,uVar3);
    *puVar2 = uVar3;
    *(char *)((int)puVar1 + uVar3) = '\0';
  }
  return (char *)puVar1;
}

/* __ZSt13__destroy_auxIPSsEvT_S1_12__false_type @ 0x97c1721c (76 bytes) */
int __ZSt13__destroy_auxIPSsEvT_S1_12__false_type(this, text1, text2)
  unsigned char * this;
  unsigned char * text1;
  undefined4 text2;
{
  unsigned char * psVar1;
  
  psVar1 = this;
  for (; this != text1; this = this + 4) {
    psVar1 = (unsigned char *)__ZNSsD4Ev(this);
  }
  return psVar1;
}

/* operator_new @ 0x97c17268 (144 bytes) */
int operator_new(param_1)
  ulong param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  void *allocation;
  code *r3In0;
  undefined4 *puVar4;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  allocation = (void *)_malloc(param_1);
  while( true ) {
    if (allocation != (void *)0x0) {
      return allocation;
    }
    r3In0 = (code *)__keymgr_get_per_thread_data(2);
    if (r3In0 == (code *)0x0) break;
    (*r3In0)(r3In0);
    allocation = (void *)_malloc(param_1);
  }
  puVar4 = (undefined4 *)___cxa_allocate_exception(4);
  puVar2 = PTR_typeinfo_a7b7c174;
  puVar1 = PTR___ZNSt9bad_allocD1Ev_a7b7c170;
  *puVar4 = PTR_vtable_a7b7c178 + 8;
                    
  ___cxa_throw(puVar4,puVar2,puVar1);
}

/* ___cxa_pure_virtual @ 0x97c1731c (48 bytes) */
int ___cxa_pure_virtual()
{
  void *pvVar1;
  
  _write(2,"pure virtual method called\n",0x1b);
  pvVar1 = (void *)std__terminate();
  if (pvVar1 != (void *)0x0) {
    _free(pvVar1);
  }
  return;
}

