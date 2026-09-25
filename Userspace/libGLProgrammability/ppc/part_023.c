#include "decls.h"

/* __ZdlPv @ 0x97c1734c (40 bytes) */
int __ZdlPv(param_1)
  void *param_1;
{
  undefined4 extraout_r3;
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != (void *)0x0) {
    _free(param_1);
    uVar1 = extraout_r3;
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
int __ZNSaIcEC2ERKS_(param_1)
  unsigned char * param_1;
{
  return;
}

/* __ZNSaIcEC1ERKS_ @ 0x97c17384 (4 bytes) */
int __ZNSaIcEC1ERKS_(param_1)
  unsigned char * param_1;
{
  return;
}

/* __ZNSaIcEC4ERKS_ @ 0x97c17388 (4 bytes) */
int __ZNSaIcEC4ERKS_(param_1)
  unsigned char * param_1;
{
  return;
}

/* __ZNSaIcED2Ev @ 0x97c1738c (8 bytes) */
int __ZNSaIcED2Ev(this)
  void *this;
{
  ((int (*)())__ZNSaIcED4Ev)(this);
  return;
}

/* __ZNSaIcED1Ev @ 0x97c17394 (8 bytes) */
int __ZNSaIcED1Ev(this)
  void *this;
{
  ((int (*)())__ZNSaIcED4Ev)(this);
  return;
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
int __ZNKSaIcE7addressERKc(this, param_2)
  void *this;
  char *param_2;
{
  return param_2;
}

/* __ZNKSaIcE8max_sizeEv @ 0x97c173b0 (8 bytes) */
int __ZNKSaIcE8max_sizeEv()
{
  return 0xffffffff;
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE17_S_freelist_indexEm @ 0x97c173b8 (16 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE17_S_freelist_indexEm(param_1)
  ulong param_1;
{
  return (param_1 + 7 >> 3) - 1;
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE5_LockC2Ev @ 0x97c173c8 (4 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE5_LockC2Ev(this)
  void *this;
{
  ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev)(this);
  return;
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE5_LockC1Ev @ 0x97c173cc (4 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE5_LockC1Ev(this)
  void *this;
{
  ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev)(this);
  return;
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev @ 0x97c173d0 (28 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev(this)
  void *this;
{
  _pthread_mutex_lock((pthread_mutex_t *)
                      &std____default_alloc_template_true_0____S_node_allocator_lock);
  return;
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE5_LockD2Ev @ 0x97c173ec (8 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE5_LockD2Ev(this)
  void *this;
{
  ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev)(this);
  return;
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE5_LockD1Ev @ 0x97c173f4 (8 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE5_LockD1Ev(this)
  void *this;
{
  ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev)(this);
  return;
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev @ 0x97c173fc (28 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev(this)
  void *this;
{
  _pthread_mutex_unlock
            ((pthread_mutex_t *)&std____default_alloc_template_true_0____S_node_allocator_lock);
  return;
}

/* __ZNSt24__default_alloc_templateILb1ELi0EE11_S_round_upEm @ 0x97c17418 (12 bytes) */
int __ZNSt24__default_alloc_templateILb1ELi0EE11_S_round_upEm(param_1)
  ulong param_1;
{
  return param_1 + 7 & 0xfffffff8;
}

/* std____default_alloc_template_true_0___allocate @ 0x97c17424 (228 bytes) */
int std____default_alloc_template_true_0___allocate(param_1)
  ulong param_1;
{
  uint uVar1;
  char *pcVar2;
  undefined4 *puVar3;
  char in_RESERVE;
  byte in_cr0;
  undefined1 auStack_30 [28];
  
  if (_S_force_new == 0) {
    pcVar2 = _getenv("GLIBCPP_FORCE_NEW");
    if (pcVar2 == (char *)0x0) {
      do {
        if (in_RESERVE != '\0') {
          _S_force_new = storeWordConditionalIndexed(_S_force_new + -1,0,0xa7b7c00c);
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
    }
    else {
      do {
        if (in_RESERVE != '\0') {
          _S_force_new = storeWordConditionalIndexed(_S_force_new + 1,0,0xa7b7c00c);
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
    }
  }
  if ((param_1 < 0x81) && (_S_force_new < 1)) {
    uVar1 = param_1 + 7 >> 1 & 0x7ffffffc;
    ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev)(auStack_30);
    puVar3 = *(undefined4 **)(&DAT_a7b7bf90 + uVar1);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)((int (*)())std____default_alloc_template_true_0____S_refill)(param_1 + 7 & 0xfffffff8);
    }
    else {
      *(undefined4 *)(&DAT_a7b7bf90 + uVar1) = *puVar3;
    }
    if (puVar3 == (undefined4 *)0x0) {
      std____throw_bad_alloc();
    }
    ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev)(auStack_30);
  }
  else {
    puVar3 = operator_new(param_1);
  }
  return puVar3;
}

/* std__allocator_char___allocate @ 0x97c17544 (236 bytes) */
int std__allocator_char___allocate(param_1, param_2)
  ulong param_1;
  void *param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  char *pcVar3;
  char in_RESERVE;
  byte bVar4;
  undefined1 auStack_30 [28];
  
  bVar4 = (param_2 == (void *)0x0) << 1;
  puVar2 = (undefined4 *)0x0;
  if (param_2 != (void *)0x0) {
    if (__default_alloc_template_true_0____S_force_new == 0) {
      pcVar3 = _getenv("GLIBCPP_FORCE_NEW");
      if (pcVar3 == (char *)0x0) {
        do {
          if (in_RESERVE != '\0') {
            __default_alloc_template_true_0____S_force_new =
                 storeWordConditionalIndexed
                           (__default_alloc_template_true_0____S_force_new + -1,0,0xa7b7c00c);
            bVar4 = 2;
          }
        } while (!(bool)(bVar4 >> 1 & 1));
      }
      else {
        do {
          if (in_RESERVE != '\0') {
            __default_alloc_template_true_0____S_force_new =
                 storeWordConditionalIndexed
                           (__default_alloc_template_true_0____S_force_new + 1,0,0xa7b7c00c);
            bVar4 = 2;
          }
        } while (!(bool)(bVar4 >> 1 & 1));
      }
    }
    if ((param_2 < (void *)0x81) && (__default_alloc_template_true_0____S_force_new < 1)) {
      uVar1 = (int)param_2 + 7U >> 1 & 0x7ffffffc;
      ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev)(auStack_30);
      puVar2 = *(undefined4 **)(&DAT_a7b7bf90 + uVar1);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)
                 __default_alloc_template_true_0____S_refill((int)param_2 + 7U & 0xfffffff8);
      }
      else {
        *(undefined4 *)(&DAT_a7b7bf90 + uVar1) = *puVar2;
      }
      if (puVar2 == (undefined4 *)0x0) {
        std____throw_bad_alloc();
      }
      ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev)(auStack_30);
    }
    else {
      puVar2 = operator_new((ulong)param_2);
    }
  }
  return puVar2;
}

/* std____default_alloc_template_true_0___deallocate @ 0x97c1766c (136 bytes) */
int std____default_alloc_template_true_0___deallocate(param_1, param_2)
  void *param_1;
  ulong param_2;
{
  uint uVar1;
  undefined1 auStack_30 [28];
  
  if ((param_2 < 0x81) && (_S_force_new < 1)) {
    uVar1 = param_2 + 7 >> 1 & 0x7ffffffc;
    ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev)(auStack_30);
    *(undefined4 *)param_1 = *(undefined4 *)(&DAT_a7b7bf90 + uVar1);
    *(void **)(&DAT_a7b7bf90 + uVar1) = param_1;
    ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev)(auStack_30);
  }
  else {
    ((int (*)())__ZdlPv)(param_1);
  }
  return;
}

/* std__allocator_char___deallocate @ 0x97c176f4 (140 bytes) */
int std__allocator_char___deallocate(this, param_2, param_3)
  unsigned char * this;
  char *param_2;
  ulong param_3;
{
  uint uVar1;
  undefined1 auStack_30 [28];
  
  if ((param_3 < 0x81) && (__default_alloc_template_true_0____S_force_new < 1)) {
    uVar1 = param_3 + 7 >> 1 & 0x7ffffffc;
    ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockC4Ev)(auStack_30);
    *(undefined4 *)param_2 = *(undefined4 *)(&DAT_a7b7bf90 + uVar1);
    *(char **)(&DAT_a7b7bf90 + uVar1) = param_2;
    ((int (*)())__ZNSt24__default_alloc_templateILb1ELi0EE5_LockD4Ev)(auStack_30);
  }
  else {
    ((int (*)())__ZdlPv)(param_2);
  }
  return;
}

/* __ZNSaIcE9constructEPcRKc @ 0x97c17780 (20 bytes) */
int __ZNSaIcE9constructEPcRKc(this, param_2, param_3)
  void *this;
  char *param_2;
  char *param_3;
{
  if (param_2 == (char *)0x0) {
    return;
  }
  *param_2 = *param_3;
  return;
}

/* __ZNSaIcE7destroyEPc @ 0x97c17794 (4 bytes) */
int __ZNSaIcE7destroyEPc(param_1)
  char *param_1;
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
int __ZNSaIwEC2ERKS_(param_1)
  unsigned char * param_1;
{
  return;
}

/* __ZNSaIwEC1ERKS_ @ 0x97c177a8 (4 bytes) */
int __ZNSaIwEC1ERKS_(param_1)
  unsigned char * param_1;
{
  return;
}

/* __ZNSaIwEC4ERKS_ @ 0x97c177ac (4 bytes) */
int __ZNSaIwEC4ERKS_(param_1)
  unsigned char * param_1;
{
  return;
}

/* __ZNSaIwED2Ev @ 0x97c177b0 (8 bytes) */
int __ZNSaIwED2Ev(this)
  void *this;
{
  ((int (*)())__ZNSaIwED4Ev)(this);
  return;
}

/* __ZNSaIwED1Ev @ 0x97c177b8 (8 bytes) */
int __ZNSaIwED1Ev(this)
  void *this;
{
  ((int (*)())__ZNSaIwED4Ev)(this);
  return;
}

/* __ZNSaIwED4Ev @ 0x97c177c0 (4 bytes) */
int __ZNSaIwED4Ev(this)
  void *this;
{
  return;
}

/* __ZNKSaIwE7addressERw @ 0x97c177c4 (8 bytes) */
int __ZNKSaIwE7addressERw(this, param_2)
  void *this;
  unsigned char * param_2;
{
  return param_2;
}

/* __ZNKSaIwE7addressERKw @ 0x97c177cc (8 bytes) */
int __ZNKSaIwE7addressERKw(this, param_2)
  void *this;
  unsigned char * param_2;
{
  return param_2;
}

/* __ZNKSaIwE8max_sizeEv @ 0x97c177d4 (12 bytes) */
int __ZNKSaIwE8max_sizeEv()
{
  return 0x3fffffff;
}

/* std__allocator_wchar_t___allocate @ 0x97c177e0 (88 bytes) */
int std__allocator_wchar_t___allocate(param_1, param_2)
  ulong param_1;
  void *param_2;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 != (void *)0x0) {
    if (param_2 < (void *)0x40000000) {
      uVar1 = __default_alloc_template_true_0___allocate((int)param_2 << 2);
    }
    else {
      std____throw_bad_alloc();
    }
  }
  return uVar1;
}

/* __ZNSaIwE10deallocateEPwm @ 0x97c17838 (12 bytes) */
int __ZNSaIwE10deallocateEPwm(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  ulong param_3;
{
  ((int (*)())std____default_alloc_template_true_0___deallocate)(param_2,param_3 << 2);
  return;
}

/* __ZNSaIwE9constructEPwRKw @ 0x97c17844 (20 bytes) */
int __ZNSaIwE9constructEPwRKw(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  unsigned char * param_3;
{
  if (param_2 == (unsigned char *)0x0) {
    return;
  }
  *(undefined4 *)param_2 = *(undefined4 *)param_3;
  return;
}

/* __ZNSaIwE7destroyEPw @ 0x97c17858 (4 bytes) */
int __ZNSaIwE7destroyEPw(param_1)
  unsigned char * param_1;
{
  return;
}

/* std____default_alloc_template_true_0____S_refill @ 0x97c1785c (152 bytes) */
int std____default_alloc_template_true_0____S_refill(param_1)
  ulong param_1;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_20 [6];
  
  local_20[0] = 0x14;
  iVar1 = ((int (*)())std____default_alloc_template_true_0____S_chunk_alloc)(param_1,local_20);
  if (local_20[0] != 1) {
    *(undefined4 **)(&DAT_a7b7bf90 + (param_1 + 7 >> 1 & 0x7ffffffc)) =
         (undefined4 *)(iVar1 + param_1);
    puVar3 = (undefined4 *)(iVar1 + param_1);
    for (iVar2 = 1; local_20[0] + -1 != iVar2; iVar2 = iVar2 + 1) {
      *puVar3 = (undefined4 *)((int)puVar3 + param_1);
      puVar3 = (undefined4 *)((int)puVar3 + param_1);
    }
    *puVar3 = 0;
  }
  return iVar1;
}

/* std____default_alloc_template_true_0____S_chunk_alloc @ 0x97c178f4 (368 bytes) */
int std____default_alloc_template_true_0____S_chunk_alloc(param_1, param_2)
  ulong param_1;
  int *param_2;
{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  ulong uVar4;
  
LAB_97c1791c:
  do {
    puVar3 = _S_start_free;
    uVar2 = param_1 * *param_2;
    uVar1 = _S_end_free - (int)_S_start_free;
    if (uVar2 <= uVar1) {
      _S_start_free = (undefined4 *)((int)_S_start_free + uVar2);
      return puVar3;
    }
    if (param_1 <= uVar1) {
      *param_2 = uVar1 / param_1;
      puVar3 = _S_start_free;
      _S_start_free = (undefined4 *)((int)_S_start_free + param_1 * (uVar1 / param_1));
      return puVar3;
    }
    uVar4 = uVar2 * 2 + ((_S_heap_size >> 4) + 7 & 0xfffffff8);
    if (uVar1 != 0) {
      uVar1 = uVar1 + 7 >> 1 & 0x7ffffffc;
      *_S_start_free = *(undefined4 *)(&DAT_a7b7bf90 + uVar1);
      *(undefined4 **)(&DAT_a7b7bf90 + uVar1) = _S_start_free;
    }
    _S_start_free = operator_new(uVar4);
    uVar1 = param_1;
    if (_S_start_free == (undefined4 *)0x0) {
      for (; uVar1 < 0x81; uVar1 = uVar1 + 8) {
        uVar2 = uVar1 + 7 >> 1 & 0x7ffffffc;
        puVar3 = *(undefined4 **)(&DAT_a7b7bf90 + uVar2);
        if (puVar3 != (undefined4 *)0x0) {
          _S_end_free = (int)puVar3 + uVar1;
          *(undefined4 *)(&DAT_a7b7bf90 + uVar2) = *puVar3;
          _S_start_free = puVar3;
          goto LAB_97c1791c;
        }
      }
      _S_end_free = 0;
      _S_start_free = operator_new(uVar4);
    }
    _S_end_free = (int)_S_start_free + uVar4;
    _S_heap_size = _S_heap_size + uVar4;
  } while( true );
}

/* std____default_alloc_template_true_0___reallocate @ 0x97c17a64 (172 bytes) */
int std____default_alloc_template_true_0___reallocate(param_1, param_2, param_3)
  void *param_1;
  ulong param_2;
  ulong param_3;
{
  void *pvVar1;
  
  if ((0x80 < param_2) && (0x80 < param_3)) {
    pvVar1 = _realloc(param_1,param_3);
    return pvVar1;
  }
  pvVar1 = param_1;
  if ((param_2 + 7 & 0xfffffff8) != (param_3 + 7 & 0xfffffff8)) {
    pvVar1 = (void *)allocate(param_3);
    if (param_2 < param_3) {
      param_3 = param_2;
    }
    _memcpy(pvVar1,param_1,param_3);
    deallocate(param_1,param_2);
  }
  return pvVar1;
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
  void *pvVar1;
  
  pvVar1 = operator_new(param_1);
  return pvVar1;
}

/* __ZNSt11logic_errorC2ERKSs @ 0x97c17b64 (4 bytes) */
int __ZNSt11logic_errorC2ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  *(int *)this = DAT_a7b7c014 + 8;
  __ZNSsC1ERKSs((void *)((int)this + 4),param_2);
  return;
}

/* __ZNSt11logic_errorC1ERKSs @ 0x97c17b68 (4 bytes) */
int __ZNSt11logic_errorC1ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt11logic_errorC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt11logic_errorC4ERKSs @ 0x97c17b6c (56 bytes) */
int __ZNSt11logic_errorC4ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  *(int *)this = DAT_a7b7c014 + 8;
  __ZNSsC1ERKSs((void *)((int)this + 4),param_2);
  return;
}

/* __ZNSt11logic_errorD2Ev @ 0x97c17bcc (8 bytes) */
int __ZNSt11logic_errorD2Ev(this)
  void *this;
{
  ((int (*)())__ZNSt11logic_errorD4Ev)(this);
  return;
}

/* __ZNSt11logic_errorD1Ev @ 0x97c17bd4 (8 bytes) */
int __ZNSt11logic_errorD1Ev(this)
  void *this;
{
  ((int (*)())__ZNSt11logic_errorD4Ev)(this);
  return;
}

/* __ZNSt11logic_errorD0Ev @ 0x97c17bdc (8 bytes) */
int __ZNSt11logic_errorD0Ev(this)
  void *this;
{
  ((int (*)())__ZNSt11logic_errorD4Ev)(this);
  return;
}

/* __ZNSt11logic_errorD4Ev @ 0x97c17be4 (136 bytes) */
int __ZNSt11logic_errorD4Ev(this)
  void *this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint in_r4;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  iVar4 = *(int *)((int)this + 4);
  *(int *)this = DAT_a7b7c014 + 8;
  piVar2 = (int *)(iVar4 + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(iVar4 + -0xc));
  }
  __ZNSt9exceptionD2Ev(this);
  if ((in_r4 & 1) != 0) {
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
int __ZNSt12domain_errorC2ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt12domain_errorC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt12domain_errorC1ERKSs @ 0x97c17ca0 (4 bytes) */
int __ZNSt12domain_errorC1ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt12domain_errorC4ERKSs)(this,param_2);
  return;
}

/* __ZNSt12domain_errorC4ERKSs @ 0x97c17ca4 (68 bytes) */
int __ZNSt12domain_errorC4ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSt11logic_errorC2ERKSs)(this,param_2);
  *(undefined ***)this = &PTR___ZNSt12domain_errorD1Ev_a7b7ded8;
  return;
}

/* __ZNSt16invalid_argumentC2ERKSs @ 0x97c17ce8 (4 bytes) */
int __ZNSt16invalid_argumentC2ERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  __ZNSt16invalid_argumentC4ERKSs(this,param_2);
  return;
}

