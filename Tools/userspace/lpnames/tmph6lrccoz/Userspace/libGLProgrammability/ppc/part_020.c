#include "decls.h"

/* __ZNSs7_M_leakEv @ 0x97c132b0 (20 bytes) */
int __ZNSs7_M_leakEv(this)
  void *this;
{
  if (*(int *)(*(int *)this + -4) < 0) {
    return;
  }
  return ((int (*)())std__string___M_leak_hard)(this);
}

/* std__string___M_check @ 0x97c132c4 (112 bytes) */
int std__string___M_check(result, self, pos)
  ulong result;
  int *self;
  uint pos;
{
  int ibeginIter [4];
  
  if (*(uint *)(*self + -0xc) < pos) {
    std____throw_out_of_range("basic_string::_M_check");
  }
  __ZNKSs9_M_ibeginEv(ibeginIter,self);
  *(uint *)result = ibeginIter[0] + pos;
  return result;
}

/* __ZNKSs7_M_foldEmm @ 0x97c13334 (100 bytes) */
int __ZNKSs7_M_foldEmm(result, self, pos, n)
  ulong result;
  ulong self;
  int pos;
  uint n;
{
  uint remaining;
  int ibeginIter [4];
  
  remaining = *(int *)(*(int *)self + -0xc) - pos;
  if (remaining <= n) {
    n = remaining;
  }
  __ZNKSs9_M_ibeginEv(ibeginIter,self);
  *(uint *)result = ibeginIter[0] + pos + n;
  return result;
}

/* __ZNSs13_S_copy_charsEPcS_S_ @ 0x97c13398 (36 bytes) */
int __ZNSs13_S_copy_charsEPcS_S_(this, str1, str2)
  char *this;
  char *str1;
  char *str2;
{
  return _memcpy(this,str1,(int)str2 - (int)str1);
}

/* __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIS_SsEES2_ @ 0x97c133bc (36 bytes) */
int __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIS_SsEES2_(this, str, i1)
  char *this;
  int str;
  int i1;
{
  return _memcpy(this,str,i1 - str);
}

/* __ZNSs13_S_copy_charsEPcPKcS1_ @ 0x97c133e0 (36 bytes) */
int __ZNSs13_S_copy_charsEPcPKcS1_(this, str1, str2)
  char *this;
  char *str1;
  char *str2;
{
  return _memcpy(this,str1,(int)str2 - (int)str1);
}

/* __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIPKcSsEES4_ @ 0x97c13404 (36 bytes) */
int __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIPKcSsEES4_(this, str, i1)
  char *this;
  int str;
  int i1;
{
  return _memcpy(this,str,i1 - str);
}

/* __ZNKSs4_Rep12_M_is_sharedEv @ 0x97c13428 (24 bytes) */
int __ZNKSs4_Rep12_M_is_sharedEv(this)
  void *this;
{
  if (0 < *(int *)((int)this + 8)) {
    return 1;
  }
  return 0;
}

/* __ZNKSs8capacityEv @ 0x97c13440 (12 bytes) */
int __ZNKSs8capacityEv(this)
  void *this;
{
  return *(undefined4 *)(*(int *)this + -8);
}

/* __ZNKSs13get_allocatorEv @ 0x97c1344c (4 bytes) */
int __ZNKSs13get_allocatorEv()
{
  return;
}

/* __ZNSs4_Rep10_M_refdataEv @ 0x97c13450 (8 bytes) */
int __ZNSs4_Rep10_M_refdataEv(this)
  void *this;
{
  return (int)this + 0xc;
}

/* __ZNSs4_Rep10_M_disposeERKSaIcE @ 0x97c13458 (32 bytes) */
int __ZNSs4_Rep10_M_disposeERKSaIcE(this, alloc)
  unsigned char * this;
  uint alloc;
{
  int atomicStore;
  unsigned char * refCountPtr;
  int oldRefCount;
  char reservation;
  byte cr0Reg;
  
  refCountPtr = this + 8;
  do {
    oldRefCount = *(int *)refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *(int *)refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (0 < oldRefCount) {
    return;
  }
  return __ZNSs4_Rep10_M_destroyERKSaIcE(this,alloc);
}

/* __ZNSs4_Rep15_M_set_sharableEv @ 0x97c13478 (12 bytes) */
int __ZNSs4_Rep15_M_set_sharableEv(this)
  void *this;
{
  *(undefined4 *)((int)this + 8) = 0;
  return;
}

/* __ZNSs9_M_mutateEmmm @ 0x97c13484 (260 bytes) */
int __ZNSs9_M_mutateEmmm(this, pos, n, n2)
  void *this;
  ulong pos;
  ulong n;
  ulong n2;
{
  int data;
  int oldRefCount;
  int atomicStore;
  uint repCapacity;
  int *refCountPtr;
  int curData;
  uint newCapacity;
  int tailSrc;
  int tailLen;
  uint newSize;
  char reservation;
  byte cr0Reg;
  unsigned char allocatorTmp [32];
  
  curData = *(int *)this;
  tailSrc = curData + pos + n;
  tailLen = (*(int *)(curData + -0xc) - pos) - n;
  newSize = (*(int *)(curData + -0xc) + n2) - n;
  if (*(int *)(curData + -4) < 1) {
    repCapacity = *(uint *)(curData + -8);
    if (newSize <= repCapacity) {
      if ((tailLen != 0) && (n != n2)) {
        _memmove(curData + pos + n2,tailSrc,tailLen);
        curData = *(int *)this;
      }
      goto LAB_97c135b0;
    }
  }
  else {
    repCapacity = *(uint *)(curData + -8);
  }
  newCapacity = newSize;
  if (((repCapacity < newSize) && (0xfe3 < newSize)) && (newCapacity = repCapacity << 1, repCapacity << 1 < newSize)) {
    newCapacity = newSize;
  }
  curData = __ZNSs4_Rep9_S_createEmRKSaIcE(newCapacity,allocatorTmp);
  curData = curData + 0xc;
  if (pos != 0) {
    _memcpy(curData,*(undefined4 *)this,pos);
  }
  if (tailLen != 0) {
    _memcpy(curData + pos + n2,tailSrc,tailLen);
  }
  data = *(int *)this;
  refCountPtr = (int *)(data + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(data + -0xc),(uint)allocatorTmp);
  }
  *(int *)this = curData;
LAB_97c135b0:
  *(undefined4 *)(curData + -4) = 0;
  *(uint *)(*(int *)this + -0xc) = newSize;
  *(undefined1 *)(*(int *)this + newSize) = 0;
  return;
}

/* __ZNSs4_Rep13_M_set_leakedEv @ 0x97c135dc (12 bytes) */
int __ZNSs4_Rep13_M_set_leakedEv(this)
  void *this;
{
  *(undefined4 *)((int)this + 8) = 0xffffffff;
  return;
}

/* std__string___M_leak_hard @ 0x97c135e8 (84 bytes) */
int std__string___M_leak_hard(this)
  unsigned char * this;
{
  int data;
  
  data = *(int *)this;
  if (0 < *(int *)(data + -4)) {
    ((int (*)())__ZNSs9_M_mutateEmmm)(this,0,0,0);
    data = *(int *)this;
  }
  *(undefined4 *)(data + -4) = 0xffffffff;
  return;
}

/* __ZNSs12_S_empty_repEv @ 0x97c1363c (28 bytes) */
int __ZNSs12_S_empty_repEv()
{
  return &std__string___S_empty_rep_storage;
}

/* __ZNSsC2Ev @ 0x97c13658 (4 bytes) */
int __ZNSsC2Ev(this)
  void *this;
{
  return ((int (*)())__ZNSsC4Ev)(this);
}

/* __ZNSsC1Ev @ 0x97c1365c (4 bytes) */
int __ZNSsC1Ev(this)
  void *this;
{
  return ((int (*)())__ZNSsC4Ev)(this);
}

/* __ZNSs12_Alloc_hiderC2EPcRKSaIcE @ 0x97c13660 (4 bytes) */
int __ZNSs12_Alloc_hiderC2EPcRKSaIcE(this, str, allocator)
  void *this;
  char *str;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,str,allocator);
}

/* __ZNSs12_Alloc_hiderC1EPcRKSaIcE @ 0x97c13664 (4 bytes) */
int __ZNSs12_Alloc_hiderC1EPcRKSaIcE(this, str, allocator)
  void *this;
  char *str;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,str,allocator);
}

/* __ZNSs12_Alloc_hiderC4EPcRKSaIcE @ 0x97c13668 (8 bytes) */
int __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this, str, allocator)
  void *this;
  char *str;
  unsigned char * allocator;
{
  *(char **)this = str;
  return;
}

/* __ZNSs4_Rep10_M_refcopyEv @ 0x97c13670 (28 bytes) */
int __ZNSs4_Rep10_M_refcopyEv(this)
  void *this;
{
  int atomicStore;
  int *refCountPtr;
  char reservation;
  byte cr0Reg;
  
  refCountPtr = (int *)((int)this + 8);
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*refCountPtr + 1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  return (int)this + 0xc;
}

/* __ZNSsC4Ev @ 0x97c1368c (84 bytes) */
int __ZNSsC4Ev(this)
  void *this;
{
  char reservation;
  byte cr0Reg;
  unsigned char aaStack_20 [28];
  
  do {
    if (reservation != '\0') {
      DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,&DAT_a7b7bf90,aaStack_20);
}

/* __ZNSsC2ERKSaIcE @ 0x97c136e0 (4 bytes) */
int __ZNSsC2ERKSaIcE(this, allocator)
  void *this;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4ERKSaIcE)(this,allocator);
}

/* __ZNSsC1ERKSaIcE @ 0x97c136e4 (4 bytes) */
int __ZNSsC1ERKSaIcE(this, allocator)
  void *this;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4ERKSaIcE)(this,allocator);
}

/* __ZNSsC4ERKSaIcE @ 0x97c136e8 (76 bytes) */
int __ZNSsC4ERKSaIcE(this, allocator)
  void *this;
  unsigned char * allocator;
{
  char *emptyData;
  
  emptyData = (char *)std__string___S_construct(0,0,allocator);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,emptyData,allocator);
}

/* __ZNSsC2ERKSs @ 0x97c13734 (4 bytes) */
int __ZNSsC2ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSsC4ERKSs)(this,text);
}

/* __ZNSsC1ERKSs @ 0x97c13738 (4 bytes) */
int __ZNSsC1ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  int atomicStore;
  int *refCountPtr;
  char *data;
  char reservation;
  byte cr0Reg;
  unsigned char cloneAlloc [32];
  unsigned char hiderAlloc [28];
  
  data = *(char **)text;
  ((int (*)())__ZNKSs13get_allocatorEv)();
  if (*(int *)(data + -4) < 0) {
    data = (char *)__ZNSs4_Rep8_M_cloneERKSaIcEm(data + -0xc,cloneAlloc,0);
  }
  else {
    refCountPtr = (int *)(data + -4);
    do {
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(*refCountPtr + 1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
  }
  ((int (*)())__ZNKSs13get_allocatorEv)();
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,data,hiderAlloc);
}

/* __ZNSs4_Rep7_M_grabERKSaIcES2_ @ 0x97c1373c (48 bytes) */
int __ZNSs4_Rep7_M_grabERKSaIcES2_(this, allocator1)
  unsigned char * this;
  unsigned char * allocator1;
{
  unsigned char * refCountPtr;
  int atomicStore;
  unsigned char * cloned;
  char reservation;
  byte cr0Reg;
  
  if (*(int *)(this + 8) < 0) {
    cloned = (unsigned char *)__ZNSs4_Rep8_M_cloneERKSaIcEm(this,allocator1,0);
    return cloned;
  }
  refCountPtr = this + 8;
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*(int *)refCountPtr + 1,0,refCountPtr);
      *(int *)refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  return this + 0xc;
}

/* __ZNSsC4ERKSs @ 0x97c1376c (152 bytes) */
int __ZNSsC4ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  int atomicStore;
  int *refCountPtr;
  char *data;
  char reservation;
  byte cr0Reg;
  unsigned char cloneAlloc [32];
  unsigned char hiderAlloc [28];
  
  data = *(char **)text;
  ((int (*)())__ZNKSs13get_allocatorEv)();
  if (*(int *)(data + -4) < 0) {
    data = (char *)__ZNSs4_Rep8_M_cloneERKSaIcEm(data + -0xc,cloneAlloc,0);
  }
  else {
    refCountPtr = (int *)(data + -4);
    do {
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(*refCountPtr + 1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
  }
  ((int (*)())__ZNKSs13get_allocatorEv)();
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,data,hiderAlloc);
}

/* __ZNSsC2ERKSsmm @ 0x97c13808 (4 bytes) */
int __ZNSsC2ERKSsmm(this, text, pos, n)
  void *this;
  unsigned char * text;
  ulong pos;
  ulong n;
{
  return ((int (*)())__ZNSsC4ERKSsmm)(this,text,pos,n);
}

/* __ZNSsC1ERKSsmm @ 0x97c1380c (4 bytes) */
int __ZNSsC1ERKSsmm(this, text, pos, n)
  void *this;
  unsigned char * text;
  ulong pos;
  ulong n;
{
  char *newData;
  undefined4 posIter;
  undefined4 endIter [3];
  unsigned char ctorAlloc [16];
  unsigned char hiderAlloc [24];
  
  ((int (*)())std__string___M_check)((ulong)&posIter,text,pos);
  ((int (*)())__ZNKSs7_M_foldEmm)((ulong)endIter,(ulong)text,pos,n);
  newData = __ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag
                     (posIter,endIter[0],ctorAlloc,0);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,newData,hiderAlloc);
}

/* __ZNSsC4ERKSsmm @ 0x97c13810 (120 bytes) */
int __ZNSsC4ERKSsmm(this, text, pos, n)
  void *this;
  unsigned char * text;
  ulong pos;
  ulong n;
{
  char *newData;
  undefined4 posIter;
  undefined4 endIter [3];
  unsigned char ctorAlloc [16];
  unsigned char hiderAlloc [24];
  
  ((int (*)())std__string___M_check)((ulong)&posIter,text,pos);
  ((int (*)())__ZNKSs7_M_foldEmm)((ulong)endIter,(ulong)text,pos,n);
  newData = __ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag
                     (posIter,endIter[0],ctorAlloc,0);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,newData,hiderAlloc);
}

/* __ZNSsC2ERKSsmmRKSaIcE @ 0x97c1388c (4 bytes) */
int __ZNSsC2ERKSsmmRKSaIcE(this, text, pos, n, allocator)
  void *this;
  unsigned char * text;
  ulong pos;
  ulong n;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4ERKSsmmRKSaIcE)(this,text,pos,n,allocator);
}

/* __ZNSsC1ERKSsmmRKSaIcE @ 0x97c13890 (4 bytes) */
int __ZNSsC1ERKSsmmRKSaIcE(this, text, pos, n, allocator)
  void *this;
  unsigned char * text;
  ulong pos;
  ulong n;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4ERKSsmmRKSaIcE)(this,text,pos,n,allocator);
}

/* __ZNSsC4ERKSsmmRKSaIcE @ 0x97c13894 (124 bytes) */
int __ZNSsC4ERKSsmmRKSaIcE(this, text, pos, n, allocator)
  void *this;
  unsigned char * text;
  ulong pos;
  ulong n;
  unsigned char * allocator;
{
  char *newData;
  undefined4 posIter;
  undefined4 endIter [4];
  
  ((int (*)())std__string___M_check)((ulong)&posIter,text,pos);
  ((int (*)())__ZNKSs7_M_foldEmm)((ulong)endIter,(ulong)text,pos,n);
  newData = __ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag
                     (posIter,endIter[0],allocator,0);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,newData,allocator);
}

/* __ZNSsC2EPKcmRKSaIcE @ 0x97c13910 (4 bytes) */
int __ZNSsC2EPKcmRKSaIcE(this, str, n, allocator)
  void *this;
  char *str;
  ulong n;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4EPKcmRKSaIcE)(this,str,n,allocator);
}

/* __ZNSsC1EPKcmRKSaIcE @ 0x97c13914 (4 bytes) */
int __ZNSsC1EPKcmRKSaIcE(this, str, n, allocator)
  void *this;
  char *str;
  ulong n;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4EPKcmRKSaIcE)(this,str,n,allocator);
}

/* __ZNSsC4EPKcmRKSaIcE @ 0x97c13918 (80 bytes) */
int __ZNSsC4EPKcmRKSaIcE(this, str, n, allocator)
  void *this;
  char *str;
  ulong n;
  unsigned char * allocator;
{
  char *newData;
  
  newData = __ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag
                     (str,str + n,allocator,0);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,newData,allocator);
}

/* __ZNSsC2EPKcRKSaIcE @ 0x97c13968 (4 bytes) */
int __ZNSsC2EPKcRKSaIcE(this, str, allocator)
  void *this;
  char *str;
  unsigned char * allocator;
{
  char *newData;
  size_t length;
  char *endPtr;
  
  if (str == (char *)0x0) {
    endPtr = (char *)0xffffffff;
  }
  else {
    length = _strlen(str);
    endPtr = str + length;
  }
  newData = __ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag
                     (str,endPtr,allocator,0);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,newData,allocator);
}

/* __ZNSsC1EPKcRKSaIcE @ 0x97c1396c (4 bytes) */
int __ZNSsC1EPKcRKSaIcE(this, str, allocator)
  void *this;
  char *str;
  unsigned char * allocator;
{
  char *newData;
  size_t length;
  char *endPtr;
  
  if (str == (char *)0x0) {
    endPtr = (char *)0xffffffff;
  }
  else {
    length = _strlen(str);
    endPtr = str + length;
  }
  newData = __ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag
                     (str,endPtr,allocator,0);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,newData,allocator);
}

/* __ZNSsC4EPKcRKSaIcE @ 0x97c13970 (104 bytes) */
int __ZNSsC4EPKcRKSaIcE(this, str, allocator)
  void *this;
  char *str;
  unsigned char * allocator;
{
  char *newData;
  int length;
  char *endPtr;
  
  if (str == (char *)0x0) {
    endPtr = (char *)0xffffffff;
  }
  else {
    length = _strlen(str);
    endPtr = str + length;
  }
  newData = __ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag
                     (str,endPtr,allocator,0);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,newData,allocator);
}

/* __ZNSsC2EmcRKSaIcE @ 0x97c139d8 (4 bytes) */
int __ZNSsC2EmcRKSaIcE(this, n, c, allocator)
  void *this;
  ulong n;
  int c;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4EmcRKSaIcE)(this,n,c,allocator);
}

/* __ZNSsC1EmcRKSaIcE @ 0x97c139dc (4 bytes) */
int __ZNSsC1EmcRKSaIcE(this, n, c, allocator)
  void *this;
  ulong n;
  int c;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4EmcRKSaIcE)(this,n,c,allocator);
}

/* __ZNSsC4EmcRKSaIcE @ 0x97c139e0 (76 bytes) */
int __ZNSsC4EmcRKSaIcE(this, n, c, allocator)
  void *this;
  ulong n;
  int c;
  unsigned char * allocator;
{
  char *newData;
  undefined3 cHigh24;
  
  newData = (char *)std__string___S_construct(n,CONCAT31(cHigh24,c),allocator)
  ;
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,newData,allocator);
}

/* __ZNSsD2Ev @ 0x97c13a2c (8 bytes) */
int __ZNSsD2Ev(this)
  void *this;
{
  return ((int (*)())__ZNSsD4Ev)(this);
}

/* __ZNSsD1Ev @ 0x97c13a34 (8 bytes) */
int __ZNSsD1Ev(this)
  void *this;
{
  return ((int (*)())__ZNSsD4Ev)(this);
}

/* __ZNSsD4Ev @ 0x97c13a3c (92 bytes) */
int __ZNSsD4Ev(this)
  void *this;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int data;
  char reservation;
  byte cr0Reg;
  undefined1 auStack_20 [20];
  
  data = *(int *)this;
  ((int (*)())__ZNKSs13get_allocatorEv)();
  refCountPtr = (int *)(data + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(data + -0xc),(uint)auStack_20);
  }
  return;
}

/* __ZNSsaSERKSs @ 0x97c13a98 (4 bytes) */
int __ZNSsaSERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return __ZNSs6assignERKSs(this,text);
}

/* __ZNKSs8max_sizeEv @ 0x97c13a9c (12 bytes) */
int __ZNKSs8max_sizeEv()
{
  return 0x3ffffffc;
}

/* __ZNSs6assignEPKcm @ 0x97c13aa8 (252 bytes) */
int __ZNSs6assignEPKcm(this, str, n)
  void *this;
  char *str;
  ulong n;
{
  char *data;
  unsigned char * result;
  undefined4 ibeginIter;
  undefined4 iendIter [6];
  
  if (0x3ffffffc < n) {
    std____throw_length_error("basic_string::assign");
  }
  data = *(char **)this;
  if (((0 < *(int *)(data + -4)) || (str < data)) ||
     (data + *(int *)(data + -0xc) < str)) {
    __ZNKSs9_M_ibeginEv(&ibeginIter,this);
    __ZNKSs7_M_iendEv(iendIter,this);
    result = __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                       (this,ibeginIter,iendIter[0],str,str + n);
    return result;
  }
  if ((uint)((int)str - (int)data) < n) {
    if (str == data) goto LAB_97c13b7c;
    _memmove(data,str,n);
  }
  else {
    _memcpy(data,str,n);
  }
  data = *(char **)this;
LAB_97c13b7c:
  *(ulong *)(data + -0xc) = n;
  *(undefined1 *)(*(int *)this + n) = 0;
  return this;
}

/* __ZNSs6assignEPKc @ 0x97c13ba4 (260 bytes) */
int __ZNSs6assignEPKc(this, str)
  void *this;
  char *str;
{
  uint length;
  char *data;
  unsigned char * result;
  undefined4 ibeginIter;
  undefined4 iendIter [6];
  
  length = _strlen(str);
  if (0x3ffffffc < length) {
    std____throw_length_error("basic_string::assign");
  }
  data = *(char **)this;
  if (((0 < *(int *)(data + -4)) || (str < data)) ||
     (data + *(int *)(data + -0xc) < str)) {
    __ZNKSs9_M_ibeginEv(&ibeginIter,this);
    __ZNKSs7_M_iendEv(iendIter,this);
    result = __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                       (this,ibeginIter,iendIter[0],str,str + length);
    return result;
  }
  if ((uint)((int)str - (int)data) < length) {
    if (str == data) goto LAB_97c13c80;
    _memmove(data,str,length);
  }
  else {
    _memcpy(data,str,length);
  }
  data = *(char **)this;
LAB_97c13c80:
  *(uint *)(data + -0xc) = length;
  *(undefined1 *)(*(int *)this + length) = 0;
  return this;
}

/* __ZNSsaSEPKc @ 0x97c13ca8 (260 bytes) */
int __ZNSsaSEPKc(this, str)
  void *this;
  char *str;
{
  uint length;
  char *data;
  unsigned char * result;
  undefined4 ibeginIter;
  undefined4 iendIter [6];
  
  length = _strlen(str);
  if (0x3ffffffc < length) {
    std____throw_length_error("basic_string::assign");
  }
  data = *(char **)this;
  if (((0 < *(int *)(data + -4)) || (str < data)) ||
     (data + *(int *)(data + -0xc) < str)) {
    __ZNKSs9_M_ibeginEv(&ibeginIter,this);
    __ZNKSs7_M_iendEv(iendIter,this);
    result = __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                       (this,ibeginIter,iendIter[0],str,str + length);
    return result;
  }
  if ((uint)((int)str - (int)data) < length) {
    if (str == data) goto LAB_97c13d84;
    _memmove(data,str,length);
  }
  else {
    _memcpy(data,str,length);
  }
  data = *(char **)this;
LAB_97c13d84:
  *(uint *)(data + -0xc) = length;
  *(undefined1 *)(*(int *)this + length) = 0;
  return this;
}

/* __ZNSs6assignEmc @ 0x97c13dac (100 bytes) */
int __ZNSs6assignEmc(this, n, c)
  void *this;
  ulong n;
  undefined4 c;
{
  undefined4 ibeginIter;
  undefined4 iendIter [5];
  
  __ZNKSs9_M_ibeginEv(&ibeginIter,this);
  __ZNKSs7_M_iendEv(iendIter,this);
  return __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc
            (this,ibeginIter,iendIter[0],n,c);
}

/* __ZNSsaSEc @ 0x97c13e10 (96 bytes) */
int __ZNSsaSEc(this, c)
  void *this;
  undefined4 c;
{
  undefined4 ibeginIter;
  undefined4 iendIter [6];
  
  __ZNKSs9_M_ibeginEv(&ibeginIter,this);
  __ZNKSs7_M_iendEv(iendIter,this);
  return __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc(this,ibeginIter,iendIter[0],1,c);
}

/* __ZNSs5beginEv @ 0x97c13e70 (64 bytes) */
int __ZNSs5beginEv(result, self)
  undefined4 *result;
  undefined4 *self;
{
  ((int (*)())__ZNSs7_M_leakEv)(self);
  *result = *self;
  return result;
}

/* __ZNKSs5beginEv @ 0x97c13eb0 (12 bytes) */
int __ZNKSs5beginEv(result, self)
  undefined4 *result;
  undefined4 *self;
{
  *result = *self;
  return;
}

/* __ZNSs3endEv @ 0x97c13ebc (72 bytes) */
int __ZNSs3endEv(result, self)
  int *result;
  int *self;
{
  ((int (*)())__ZNSs7_M_leakEv)(self);
  *result = *self + *(int *)(*self + -0xc);
  return result;
}

/* __ZNKSs3endEv @ 0x97c13f04 (20 bytes) */
int __ZNKSs3endEv(result, self)
  int *result;
  int *self;
{
  *result = *self + *(int *)(*self + -0xc);
  return;
}

