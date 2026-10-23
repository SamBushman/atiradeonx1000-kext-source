#include "decls.h"

/* __ZdlPv @ 0x97c1734c (40 bytes) */
int __ZdlPv(param_1)
  void *param_1;
{
  undefined4 r3Out0;
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != (void *)0x0) {
    _free(param_1);
    uVar1 = r3Out0;
  }
  return uVar1;
}

/* __ZNSaIcEC2Ev @ 0x97c17374 (4 bytes) */
int __ZNSaIcEC2Ev()
{
  return;
}

/* __ZNSaIcEC1Ev @ 0x97c17378 (4 bytes) */
int __ZNSaIcEC1Ev()
{
  return;
}

/* __ZNSaIcEC4Ev @ 0x97c1737c (4 bytes) */
int __ZNSaIcEC4Ev()
{
  return;
}

/* __ZNSaIcEC2ERKS_ @ 0x97c17380 (4 bytes) */
int __ZNSaIcEC2ERKS_(this)
  unsigned char * this;
{
  return;
}

/* __ZNSaIcEC1ERKS_ @ 0x97c17384 (4 bytes) */
int __ZNSaIcEC1ERKS_(this)
  unsigned char * this;
{
  return;
}

/* __ZNSaIcEC4ERKS_ @ 0x97c17388 (4 bytes) */
int __ZNSaIcEC4ERKS_(this)
  unsigned char * this;
{
  return;
}

/* __ZNSaIcED2Ev @ 0x97c1738c (8 bytes) */
int __ZNSaIcED2Ev(this)
  void *this;
{
  return ((int (*)())__ZNSaIcED4Ev)(this);
}

/* __ZNSaIcED1Ev @ 0x97c17394 (8 bytes) */
int __ZNSaIcED1Ev(this)
  void *this;
{
  return ((int (*)())__ZNSaIcED4Ev)(this);
}

/* __ZNSaIcED4Ev @ 0x97c1739c (4 bytes) */
int __ZNSaIcED4Ev(this)
  void *this;
{
  return;
}

/* __ZNKSaIcE7addressERc @ 0x97c173a0 (8 bytes) */
int __ZNKSaIcE7addressERc(this, param_2)
  void *this;
  char *param_2;
{
  return param_2;
}

/* __ZNKSaIcE7addressERKc @ 0x97c173a8 (8 bytes) */
int __ZNKSaIcE7addressERKc(this, str)
  void *this;
  char *str;
{
  return str;
}

/* __ZNKSaIcE8max_sizeEv @ 0x97c173b0 (8 bytes) */
int __ZNKSaIcE8max_sizeEv()
{
  return 0xffffffff;
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE17_S_freelist_indexEm @ 0x97c173b8 (16 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE17_S_freelist_indexEm(this)
  ulong this;
{
  return (this + 7 >> 3) - 1;
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE5_LockC2Ev @ 0x97c173c8 (4 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE5_LockC2Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev)(this);
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE5_LockC1Ev @ 0x97c173cc (4 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE5_LockC1Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev)(this);
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev @ 0x97c173d0 (28 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev(this)
  void *this;
{
  return _pthread_mutex_lock(&std____default_alloc_template_true_0____S_node_allocator_lock);
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE5_LockD2Ev @ 0x97c173ec (8 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE5_LockD2Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev)(this);
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE5_LockD1Ev @ 0x97c173f4 (8 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE5_LockD1Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev)(this);
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev @ 0x97c173fc (28 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev(this)
  void *this;
{
  return _pthread_mutex_unlock(&std____default_alloc_template_true_0____S_node_allocator_lock);
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE11_S_round_upEm @ 0x97c17418 (12 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE11_S_round_upEm(this)
  ulong this;
{
  return this + 7 & 0xfffffff8;
}

/* std____default_alloc_template_true_0___allocate @ 0x97c17424 (228 bytes) */
int std____default_alloc_template_true_0___allocate(n)
  ulong n;
{
  uint freeListOffset;
  int getenvResult;
  undefined4 *result;
  char reservation;
  byte cr0Reg;
  undefined1 lock [28];
  
  if (_S_force_new == 0) {
    getenvResult = _getenv("GLIBCPP_FORCE_NEW");
    if (getenvResult == 0) {
      do {
        if (reservation != '\0') {
          _S_force_new = storeWordConditionalIndexed(_S_force_new + -1,0,0xa7b7c00c);
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
    }
    else {
      do {
        if (reservation != '\0') {
          _S_force_new = storeWordConditionalIndexed(_S_force_new + 1,0,0xa7b7c00c);
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
    }
  }
  if ((n < 0x81) && (_S_force_new < 1)) {
    freeListOffset = n + 7 >> 1 & 0x7ffffffc;
    ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev)(lock);
    result = *(undefined4 **)(&DAT_a7b7bf90 + freeListOffset);
    if (result == (undefined4 *)0x0) {
      result = (undefined4 *)((int (*)())std____default_alloc_template_true_0____S_refill)(n + 7 & 0xfffffff8);
    }
    else {
      *(undefined4 *)(&DAT_a7b7bf90 + freeListOffset) = *result;
    }
    if (result == (undefined4 *)0x0) {
      std____throw_bad_alloc();
    }
    ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev)(lock);
  }
  else {
    result = operator_new(n);
  }
  return result;
}

/* std__allocator_char___allocate @ 0x97c17544 (236 bytes) */
int std__allocator_char___allocate(alloc, n)
  ulong alloc;
  void *n;
{
  uint freeListOffset;
  undefined4 *result;
  int getenvResult;
  char reservation;
  byte cr0Flags;
  undefined1 lock [28];
  
  cr0Flags = (n == (void *)0x0) << 1;
  result = (undefined4 *)0x0;
  if (n != (void *)0x0) {
    if (__default_alloc_template_true_0____S_force_new == 0) {
      getenvResult = _getenv("GLIBCPP_FORCE_NEW");
      if (getenvResult == 0) {
        do {
          if (reservation != '\0') {
            __default_alloc_template_true_0____S_force_new =
                 storeWordConditionalIndexed
                           (__default_alloc_template_true_0____S_force_new + -1,0,0xa7b7c00c);
            cr0Flags = 2;
          }
        } while (!(bool)(cr0Flags >> 1 & 1));
      }
      else {
        do {
          if (reservation != '\0') {
            __default_alloc_template_true_0____S_force_new =
                 storeWordConditionalIndexed
                           (__default_alloc_template_true_0____S_force_new + 1,0,0xa7b7c00c);
            cr0Flags = 2;
          }
        } while (!(bool)(cr0Flags >> 1 & 1));
      }
    }
    if ((n < (void *)0x81) && (__default_alloc_template_true_0____S_force_new < 1)) {
      freeListOffset = (int)n + 7U >> 1 & 0x7ffffffc;
      ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev)(lock);
      result = *(undefined4 **)(&DAT_a7b7bf90 + freeListOffset);
      if (result == (undefined4 *)0x0) {
        result = (undefined4 *)
                 __default_alloc_template_true_0____S_refill((int)n + 7U & 0xfffffff8);
      }
      else {
        *(undefined4 *)(&DAT_a7b7bf90 + freeListOffset) = *result;
      }
      if (result == (undefined4 *)0x0) {
        std____throw_bad_alloc();
      }
      ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev)(lock);
    }
    else {
      result = operator_new((ulong)n);
    }
  }
  return result;
}

/* std____default_alloc_template_true_0___deallocate @ 0x97c1766c (136 bytes) */
int std____default_alloc_template_true_0___deallocate(p, n)
  void *p;
  ulong n;
{
  uint freeListOffset;
  undefined1 lock [28];
  
  if ((n < 0x81) && (_S_force_new < 1)) {
    freeListOffset = n + 7 >> 1 & 0x7ffffffc;
    ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev)(lock);
    *(undefined4 *)p = *(undefined4 *)(&DAT_a7b7bf90 + freeListOffset);
    *(void **)(&DAT_a7b7bf90 + freeListOffset) = p;
    ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev)(lock);
  }
  else {
    ((int (*)())__ZdlPv)(p);
  }
  return;
}

/* std__allocator_char___deallocate @ 0x97c176f4 (140 bytes) */
int std__allocator_char___deallocate(alloc, p, n)
  unsigned char * alloc;
  char *p;
  ulong n;
{
  uint freeListOffset;
  undefined1 lock [28];
  
  if ((n < 0x81) && (__default_alloc_template_true_0____S_force_new < 1)) {
    freeListOffset = n + 7 >> 1 & 0x7ffffffc;
    ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev)(lock);
    *(undefined4 *)p = *(undefined4 *)(&DAT_a7b7bf90 + freeListOffset);
    *(char **)(&DAT_a7b7bf90 + freeListOffset) = p;
    ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev)(lock);
  }
  else {
    ((int (*)())__ZdlPv)(p);
  }
  return;
}

/* __ZNSaIcE9constructEPcRKc @ 0x97c17780 (20 bytes) */
int __ZNSaIcE9constructEPcRKc(this, param_2, str)
  void *this;
  char *param_2;
  char *str;
{
  if (param_2 == (char *)0x0) {
    return;
  }
  *param_2 = *str;
  return;
}

/* __ZNSaIcE7destroyEPc @ 0x97c17794 (4 bytes) */
int __ZNSaIcE7destroyEPc(this)
  char *this;
{
  return;
}

/* __ZNSaIwEC2Ev @ 0x97c17798 (4 bytes) */
int __ZNSaIwEC2Ev()
{
  return;
}

/* __ZNSaIwEC1Ev @ 0x97c1779c (4 bytes) */
int __ZNSaIwEC1Ev()
{
  return;
}

/* __ZNSaIwEC4Ev @ 0x97c177a0 (4 bytes) */
int __ZNSaIwEC4Ev()
{
  return;
}

/* __ZNSaIwEC2ERKS_ @ 0x97c177a4 (4 bytes) */
int __ZNSaIwEC2ERKS_(this)
  unsigned char * this;
{
  return;
}

/* __ZNSaIwEC1ERKS_ @ 0x97c177a8 (4 bytes) */
int __ZNSaIwEC1ERKS_(this)
  unsigned char * this;
{
  return;
}

/* __ZNSaIwEC4ERKS_ @ 0x97c177ac (4 bytes) */
int __ZNSaIwEC4ERKS_(this)
  unsigned char * this;
{
  return;
}

/* __ZNSaIwED2Ev @ 0x97c177b0 (8 bytes) */
int __ZNSaIwED2Ev(this)
  void *this;
{
  return ((int (*)())__ZNSaIwED4Ev)(this);
}

/* __ZNSaIwED1Ev @ 0x97c177b8 (8 bytes) */
int __ZNSaIwED1Ev(this)
  void *this;
{
  return ((int (*)())__ZNSaIwED4Ev)(this);
}

/* __ZNSaIwED4Ev @ 0x97c177c0 (4 bytes) */
int __ZNSaIwED4Ev(this)
  void *this;
{
  return;
}

/* __ZNKSaIwE7addressERw @ 0x97c177c4 (8 bytes) */
int __ZNKSaIwE7addressERw(this, wchar_t)
  void *this;
  unsigned char * wchar_t;
{
  return wchar_t;
}

/* __ZNKSaIwE7addressERKw @ 0x97c177cc (8 bytes) */
int __ZNKSaIwE7addressERKw(this, wchar_t)
  void *this;
  unsigned char * wchar_t;
{
  return wchar_t;
}

/* __ZNKSaIwE8max_sizeEv @ 0x97c177d4 (12 bytes) */
int __ZNKSaIwE8max_sizeEv()
{
  return 0x3fffffff;
}

/* std__allocator_wchar_t___allocate @ 0x97c177e0 (88 bytes) */
int std__allocator_wchar_t___allocate(alloc, n)
  ulong alloc;
  void *n;
{
  undefined4 result;
  
  result = 0;
  if (n != (void *)0x0) {
    if (n < (void *)0x40000000) {
      result = __default_alloc_template_true_0___allocate((int)n << 2);
    }
    else {
      std____throw_bad_alloc();
    }
  }
  return result;
}

/* __ZNSaIwE10deallocateEPwm @ 0x97c17838 (12 bytes) */
int __ZNSaIwE10deallocateEPwm(this, p, n)
  void *this;
  unsigned char * p;
  ulong n;
{
  return ((int (*)())std____default_alloc_template_true_0___deallocate)(p,n << 2);
}

/* __ZNSaIwE9constructEPwRKw @ 0x97c17844 (20 bytes) */
int __ZNSaIwE9constructEPwRKw(this, p, val)
  void *this;
  unsigned char * p;
  unsigned char * val;
{
  if (p == (unsigned char *)0x0) {
    return;
  }
  *(undefined4 *)p = *(undefined4 *)val;
  return;
}

/* __ZNSaIwE7destroyEPw @ 0x97c17858 (4 bytes) */
int __ZNSaIwE7destroyEPw(this)
  unsigned char * this;
{
  return;
}

/* std____default_alloc_template_true_0____S_refill @ 0x97c1785c (152 bytes) */
int std____default_alloc_template_true_0____S_refill(n)
  ulong n;
{
  int chunk;
  int i;
  undefined4 *currentObj;
  int nobjs [6];
  
  nobjs[0] = 0x14;
  chunk = ((int (*)())std____default_alloc_template_true_0____S_chunk_alloc)(n,nobjs);
  if (nobjs[0] != 1) {
    *(undefined4 **)(&DAT_a7b7bf90 + (n + 7 >> 1 & 0x7ffffffc)) =
         (undefined4 *)(chunk + n);
    currentObj = (undefined4 *)(chunk + n);
    for (i = 1; nobjs[0] + -1 != i; i = i + 1) {
      *currentObj = (undefined4 *)((int)currentObj + n);
      currentObj = (undefined4 *)((int)currentObj + n);
    }
    *currentObj = 0;
  }
  return chunk;
}

/* std____default_alloc_template_true_0____S_chunk_alloc @ 0x97c178f4 (368 bytes) */
int std____default_alloc_template_true_0____S_chunk_alloc(size, nobjs)
  ulong size;
  int *nobjs;
{
  undefined4 *freeListHead;
  uint freeListSlot;
  uint i;
  uint freeListOffset;
  uint bytesLeft;
  uint totalBytes;
  undefined4 *result;
  ulong bytesToGet;
  
LAB_97c1791c:
  do {
    result = _S_start_free;
    totalBytes = size * *nobjs;
    bytesLeft = _S_end_free - (int)_S_start_free;
    if (totalBytes <= bytesLeft) {
      _S_start_free = (undefined4 *)((int)_S_start_free + totalBytes);
      return result;
    }
    if (size <= bytesLeft) {
      *nobjs = bytesLeft / size;
      result = _S_start_free;
      _S_start_free = (undefined4 *)((int)_S_start_free + size * (bytesLeft / size));
      return result;
    }
    bytesToGet = totalBytes * 2 + ((_S_heap_size >> 4) + 7 & 0xfffffff8);
    if (bytesLeft != 0) {
      freeListOffset = bytesLeft + 7 >> 1 & 0x7ffffffc;
      *_S_start_free = *(undefined4 *)(&DAT_a7b7bf90 + freeListOffset);
      *(undefined4 **)(&DAT_a7b7bf90 + freeListOffset) = _S_start_free;
    }
    _S_start_free = operator_new(bytesToGet);
    i = size;
    if (_S_start_free == (undefined4 *)0x0) {
      for (; i < 0x81; i = i + 8) {
        freeListSlot = i + 7 >> 1 & 0x7ffffffc;
        freeListHead = *(undefined4 **)(&DAT_a7b7bf90 + freeListSlot);
        if (freeListHead != (undefined4 *)0x0) {
          _S_end_free = (int)freeListHead + i;
          *(undefined4 *)(&DAT_a7b7bf90 + freeListSlot) = *freeListHead;
          _S_start_free = freeListHead;
          goto LAB_97c1791c;
        }
      }
      _S_end_free = 0;
      _S_start_free = operator_new(bytesToGet);
    }
    _S_end_free = (int)_S_start_free + bytesToGet;
    _S_heap_size = _S_heap_size + bytesToGet;
  } while( true );
}

/* std____default_alloc_template_true_0___reallocate @ 0x97c17a64 (172 bytes) */
int std____default_alloc_template_true_0___reallocate(p, oldSz, newSz)
  void *p;
  ulong oldSz;
  ulong newSz;
{
  void *reallocated;
  void *result;
  
  if ((0x80 < oldSz) && (0x80 < newSz)) {
    reallocated = (void *)_realloc(p,newSz);
    return reallocated;
  }
  result = p;
  if ((oldSz + 7 & 0xfffffff8) != (newSz + 7 & 0xfffffff8)) {
    result = (void *)allocate(newSz);
    if (oldSz < newSz) {
      newSz = oldSz;
    }
    _memcpy(result,p,newSz);
    deallocate(p,oldSz);
  }
  return result;
}

/* __ZdaPv @ 0x97c17b10 (32 bytes) */
int __ZdaPv(param_1)
  void *param_1;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())__ZdlPv)(param_1);
  return uVar1;
}

/* operator_new__ @ 0x97c17b30 (20 bytes) */
int operator_new__(param_1)
  ulong param_1;
{
  void *allocation;
  
  allocation = operator_new(param_1);
  return allocation;
}

/* __ZNSt11logic_errorC2ERKSs @ 0x97c17b64 (4 bytes) */
int __ZNSt11logic_errorC2ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  *(int *)this = DAT_a7b7c014 + 8;
  return __ZNSsC1ERKSs((void *)((int)this + 4),text);
}

/* __ZNSt11logic_errorC1ERKSs @ 0x97c17b68 (4 bytes) */
int __ZNSt11logic_errorC1ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt11logic_errorC4ERKSs)(this,text);
}

/* __ZNSt11logic_errorC4ERKSs @ 0x97c17b6c (56 bytes) */
int __ZNSt11logic_errorC4ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  *(int *)this = DAT_a7b7c014 + 8;
  return __ZNSsC1ERKSs((void *)((int)this + 4),text);
}

/* __ZNSt11logic_errorD2Ev @ 0x97c17bcc (8 bytes) */
int __ZNSt11logic_errorD2Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt11logic_errorD4Ev)(this,0);
}

/* __ZNSt11logic_errorD1Ev @ 0x97c17bd4 (8 bytes) */
int __ZNSt11logic_errorD1Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt11logic_errorD4Ev)(this,2);
}

/* __ZNSt11logic_errorD0Ev @ 0x97c17bdc (8 bytes) */
int __ZNSt11logic_errorD0Ev(this)
  void *this;
{
  return ((int (*)())__ZNSt11logic_errorD4Ev)(this,3);
}

/* __ZNSt11logic_errorD4Ev @ 0x97c17be4 (136 bytes) */
int __ZNSt11logic_errorD4Ev(this, param_2)
  void *this;
  uint param_2;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int iVar4;
  char reservation;
  byte cr0Reg;
  undefined1 auStack_20 [20];
  
  iVar4 = *(int *)((int)this + 4);
  *(int *)this = DAT_a7b7c014 + 8;
  refCountPtr = (int *)(iVar4 + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(iVar4 + -0xc),auStack_20);
  }
  __ZNSt9exceptionD2Ev(this);
  if ((param_2 & 1) != 0) {
    ((int (*)())__ZdlPv)(this);
  }
  return;
}

/* __ZNKSt11logic_error4whatEv @ 0x97c17c6c (48 bytes) */
int __ZNKSt11logic_error4whatEv(this)
  void *this;
{
  *(undefined *)(*(int *)((int)this + 4) + *(int *)(*(int *)((int)this + 4) + -0xc)) =
       *PTR__S_terminal_a7b7c0b8;
  return *(undefined4 *)((int)this + 4);
}

/* __ZNSt12domain_errorC2ERKSs @ 0x97c17c9c (4 bytes) */
int __ZNSt12domain_errorC2ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt12domain_errorC4ERKSs)(this,text);
}

/* __ZNSt12domain_errorC1ERKSs @ 0x97c17ca0 (4 bytes) */
int __ZNSt12domain_errorC1ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSt12domain_errorC4ERKSs)(this,text);
}

/* __ZNSt12domain_errorC4ERKSs @ 0x97c17ca4 (68 bytes) */
int __ZNSt12domain_errorC4ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  ((int (*)())__ZNSt11logic_errorC2ERKSs)(this,text);
  *(undefined ***)this = &PTR___ZNSt12domain_errorD1Ev_a7b7ded8;
  return;
}

/* __ZNSt16invalid_argumentC2ERKSs @ 0x97c17ce8 (4 bytes) */
int __ZNSt16invalid_argumentC2ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return __ZNSt16invalid_argumentC4ERKSs(this,text);
}

