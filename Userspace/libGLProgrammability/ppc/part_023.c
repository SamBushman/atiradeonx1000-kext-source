#include "decls.h"

/* operator_delete @ 0x97c1734c (40 bytes) */
int operator_delete(param_1)
  void *param_1;
{
  if (param_1 != (void *)0x0) {
    _free(param_1);
  }
  return;
}

/* std__allocator_char___allocator @ 0x97c17374 (4 bytes) */
int std__allocator_char___allocator()
{
  return;
}

/* std__allocator_char___allocator_97c17378 @ 0x97c17378 (4 bytes) */
int std__allocator_char___allocator_97c17378()
{
  return;
}

/* std__allocator_char___allocator_97c1737c @ 0x97c1737c (4 bytes) */
int std__allocator_char___allocator_97c1737c()
{
  return;
}

/* std__allocator_char___allocator_97c17380 @ 0x97c17380 (4 bytes) */
int std__allocator_char___allocator_97c17380(param_1)
  unsigned char * param_1;
{
  return;
}

/* std__allocator_char___allocator_97c17384 @ 0x97c17384 (4 bytes) */
int std__allocator_char___allocator_97c17384(param_1)
  unsigned char * param_1;
{
  return;
}

/* std__allocator_char___allocator_97c17388 @ 0x97c17388 (4 bytes) */
int std__allocator_char___allocator_97c17388(param_1)
  unsigned char * param_1;
{
  return;
}

/* std__allocator_char____allocator @ 0x97c1738c (8 bytes) */
int std__allocator_char____allocator(this)
  unsigned char * this;
{
  ~allocator(this);
  return;
}

/* std__allocator_char____allocator_97c17394 @ 0x97c17394 (8 bytes) */
int std__allocator_char____allocator_97c17394(this)
  unsigned char * this;
{
  ~allocator(this);
  return;
}

/* std__allocator_char____allocator_97c1739c @ 0x97c1739c (4 bytes) */
int std__allocator_char____allocator_97c1739c(this)
  unsigned char * this;
{
  return;
}

/* std__allocator_char___address @ 0x97c173a0 (8 bytes) */
int std__allocator_char___address(this, param_1)
  unsigned char * this;
  char *param_1;
{
  return param_1;
}

/* std__allocator_char___address_97c173a8 @ 0x97c173a8 (8 bytes) */
int std__allocator_char___address_97c173a8(this, param_1)
  unsigned char * this;
  char *param_1;
{
  return param_1;
}

/* std__allocator_char___max_size @ 0x97c173b0 (8 bytes) */
int std__allocator_char___max_size()
{
  return 0xffffffff;
}

/* std____default_alloc_template_true_0____S_freelist_index @ 0x97c173b8 (16 bytes) */
int std____default_alloc_template_true_0____S_freelist_index(param_1)
  ulong param_1;
{
  return (param_1 + 7 >> 3) - 1;
}

/* std____default_alloc_template_true_0____Lock___Lock @ 0x97c173c8 (4 bytes) */
int std____default_alloc_template_true_0____Lock___Lock(this)
  unsigned char * this;
{
  _Lock(this);
  return;
}

/* std____default_alloc_template_true_0____Lock___Lock_97c173cc @ 0x97c173cc (4 bytes) */
int std____default_alloc_template_true_0____Lock___Lock_97c173cc(this)
  unsigned char * this;
{
  _Lock(this);
  return;
}

/* std____default_alloc_template_true_0____Lock___Lock_97c173d0 @ 0x97c173d0 (28 bytes) */
int std____default_alloc_template_true_0____Lock___Lock_97c173d0(this)
  unsigned char * this;
{
  _pthread_mutex_lock((pthread_mutex_t *)&_S_node_allocator_lock);
  return;
}

/* std____default_alloc_template_true_0____Lock____Lock @ 0x97c173ec (8 bytes) */
int std____default_alloc_template_true_0____Lock____Lock(this)
  unsigned char * this;
{
  ~_Lock(this);
  return;
}

/* std____default_alloc_template_true_0____Lock____Lock_97c173f4 @ 0x97c173f4 (8 bytes) */
int std____default_alloc_template_true_0____Lock____Lock_97c173f4(this)
  unsigned char * this;
{
  ~_Lock(this);
  return;
}

/* std____default_alloc_template_true_0____Lock____Lock_97c173fc @ 0x97c173fc (28 bytes) */
int std____default_alloc_template_true_0____Lock____Lock_97c173fc(this)
  unsigned char * this;
{
  _pthread_mutex_unlock((pthread_mutex_t *)&_S_node_allocator_lock);
  return;
}

/* std____default_alloc_template_true_0____S_round_up @ 0x97c17418 (12 bytes) */
int std____default_alloc_template_true_0____S_round_up(param_1)
  ulong param_1;
{
  return param_1 + 7 & 0xfffffff8;
}

/* std____default_alloc_template_true_0___allocate @ 0x97c17424 (264 bytes) */
int std____default_alloc_template_true_0___allocate(param_1)
  ulong param_1;
{
  uint uVar1;
  char *pcVar2;
  undefined4 *puVar3;
  char in_RESERVE;
  byte in_cr0;
  unsigned char a_Stack_30 [28];
  
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
    _Lock___Lock(a_Stack_30);
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
    _Lock____Lock(a_Stack_30);
  }
  else {
    puVar3 = operator_new(param_1);
  }
  return puVar3;
}

/* std__allocator_char___allocate @ 0x97c17544 (272 bytes) */
int std__allocator_char___allocate(param_1, param_2)
  ulong param_1;
  void *param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  char *pcVar3;
  char in_RESERVE;
  byte bVar4;
  unsigned char a_Stack_30 [28];
  
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
      __default_alloc_template_true_0____Lock___Lock(a_Stack_30);
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
      __default_alloc_template_true_0____Lock____Lock(a_Stack_30);
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
  unsigned char a_Stack_30 [28];
  
  if ((param_2 < 0x81) && (_S_force_new < 1)) {
    uVar1 = param_2 + 7 >> 1 & 0x7ffffffc;
    _Lock___Lock(a_Stack_30);
    *(undefined4 *)param_1 = *(undefined4 *)(&DAT_a7b7bf90 + uVar1);
    *(void **)(&DAT_a7b7bf90 + uVar1) = param_1;
    _Lock____Lock(a_Stack_30);
  }
  else {
    ((int (*)())operator_delete)(param_1);
  }
  return;
}

/* std__allocator_char___deallocate @ 0x97c176f4 (140 bytes) */
int std__allocator_char___deallocate(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  ulong param_2;
{
  uint uVar1;
  unsigned char a_Stack_30 [28];
  
  if ((param_2 < 0x81) && (__default_alloc_template_true_0____S_force_new < 1)) {
    uVar1 = param_2 + 7 >> 1 & 0x7ffffffc;
    __default_alloc_template_true_0____Lock___Lock(a_Stack_30);
    *(undefined4 *)param_1 = *(undefined4 *)(&DAT_a7b7bf90 + uVar1);
    *(char **)(&DAT_a7b7bf90 + uVar1) = param_1;
    __default_alloc_template_true_0____Lock____Lock(a_Stack_30);
  }
  else {
    ((int (*)())operator_delete)(param_1);
  }
  return;
}

/* std__allocator_char___construct @ 0x97c17780 (20 bytes) */
int std__allocator_char___construct(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  char *param_2;
{
  if (param_1 == (char *)0x0) {
    return;
  }
  *param_1 = *param_2;
  return;
}

/* std__allocator_char___destroy @ 0x97c17794 (4 bytes) */
int std__allocator_char___destroy(param_1)
  char *param_1;
{
  return;
}

/* std__allocator_wchar_t___allocator @ 0x97c17798 (4 bytes) */
int std__allocator_wchar_t___allocator()
{
  return;
}

/* std__allocator_wchar_t___allocator_97c1779c @ 0x97c1779c (4 bytes) */
int std__allocator_wchar_t___allocator_97c1779c()
{
  return;
}

/* std__allocator_wchar_t___allocator_97c177a0 @ 0x97c177a0 (4 bytes) */
int std__allocator_wchar_t___allocator_97c177a0()
{
  return;
}

/* std__allocator_wchar_t___allocator_97c177a4 @ 0x97c177a4 (4 bytes) */
int std__allocator_wchar_t___allocator_97c177a4(param_1)
  unsigned char * param_1;
{
  return;
}

/* std__allocator_wchar_t___allocator_97c177a8 @ 0x97c177a8 (4 bytes) */
int std__allocator_wchar_t___allocator_97c177a8(param_1)
  unsigned char * param_1;
{
  return;
}

/* std__allocator_wchar_t___allocator_97c177ac @ 0x97c177ac (4 bytes) */
int std__allocator_wchar_t___allocator_97c177ac(param_1)
  unsigned char * param_1;
{
  return;
}

/* std__allocator_wchar_t____allocator @ 0x97c177b0 (8 bytes) */
int std__allocator_wchar_t____allocator(this)
  unsigned char * this;
{
  ~allocator(this);
  return;
}

/* std__allocator_wchar_t____allocator_97c177b8 @ 0x97c177b8 (8 bytes) */
int std__allocator_wchar_t____allocator_97c177b8(this)
  unsigned char * this;
{
  ~allocator(this);
  return;
}

/* std__allocator_wchar_t____allocator_97c177c0 @ 0x97c177c0 (4 bytes) */
int std__allocator_wchar_t____allocator_97c177c0(this)
  unsigned char * this;
{
  return;
}

/* std__allocator_wchar_t___address @ 0x97c177c4 (8 bytes) */
int std__allocator_wchar_t___address(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  return param_1;
}

/* std__allocator_wchar_t___address_97c177cc @ 0x97c177cc (8 bytes) */
int std__allocator_wchar_t___address_97c177cc(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  return param_1;
}

/* std__allocator_wchar_t___max_size @ 0x97c177d4 (12 bytes) */
int std__allocator_wchar_t___max_size()
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

/* std__allocator_wchar_t___deallocate @ 0x97c17838 (12 bytes) */
int std__allocator_wchar_t___deallocate(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
{
  __default_alloc_template_true_0___deallocate(param_1,param_2 << 2);
  return;
}

/* std__allocator_wchar_t___construct @ 0x97c17844 (20 bytes) */
int std__allocator_wchar_t___construct(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
{
  if (param_1 == (unsigned char *)0x0) {
    return;
  }
  *(undefined4 *)param_1 = *(undefined4 *)param_2;
  return;
}

/* std__allocator_wchar_t___destroy @ 0x97c17858 (4 bytes) */
int std__allocator_wchar_t___destroy(param_1)
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
  return;
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

/* operator_delete__ @ 0x97c17b10 (32 bytes) */
int operator_delete__(param_1)
  void *param_1;
{
  ((int (*)())operator_delete)(param_1);
  return;
}

/* operator_new__ @ 0x97c17b30 (36 bytes) */
int operator_new__(param_1)
  ulong param_1;
{
  void *pvVar1;
  
  pvVar1 = operator_new(param_1);
  return pvVar1;
}

/* std__logic_error__logic_error @ 0x97c17b64 (4 bytes) */
int std__logic_error__logic_error(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  *(int *)this = DAT_a7b7c014 + 8;
  std__string__string((unsigned char *)(this + 4),param_1);
  return;
}

/* std__logic_error__logic_error_97c17b68 @ 0x97c17b68 (4 bytes) */
int std__logic_error__logic_error_97c17b68(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  logic_error(this,param_1);
  return;
}

/* std__logic_error__logic_error_97c17b6c @ 0x97c17b6c (76 bytes) */
int std__logic_error__logic_error_97c17b6c(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  *(int *)this = DAT_a7b7c014 + 8;
  std__string__string((unsigned char *)(this + 4),param_1);
  return;
}

/* std__logic_error___logic_error @ 0x97c17bcc (8 bytes) */
int std__logic_error___logic_error(this)
  unsigned char * this;
{
  ~logic_error(this);
  return;
}

/* std__logic_error___logic_error_97c17bd4 @ 0x97c17bd4 (8 bytes) */
int std__logic_error___logic_error_97c17bd4(this)
  unsigned char * this;
{
  ~logic_error(this);
  return;
}

/* std__logic_error___logic_error_97c17bdc @ 0x97c17bdc (8 bytes) */
int std__logic_error___logic_error_97c17bdc(this)
  unsigned char * this;
{
  ~logic_error(this);
  return;
}

/* std__logic_error___logic_error_97c17be4 @ 0x97c17be4 (136 bytes) */
int std__logic_error___logic_error_97c17be4(this)
  unsigned char * this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint in_r4;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  iVar4 = *(int *)(this + 4);
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
    std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
  }
  std__exception___exception((unsigned char *)this);
  if ((in_r4 & 1) != 0) {
    ((int (*)())operator_delete)(this);
  }
  return;
}

/* std__logic_error__what @ 0x97c17c6c (48 bytes) */
int std__logic_error__what(this)
  unsigned char * this;
{
  *(undefined *)(*(int *)(this + 4) + *(int *)(*(int *)(this + 4) + -0xc)) =
       *PTR__S_terminal_a7b7c0b8;
  return *(undefined4 *)(this + 4);
}

/* std__domain_error__domain_error @ 0x97c17c9c (4 bytes) */
int std__domain_error__domain_error(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  domain_error(this,param_1);
  return;
}

/* std__domain_error__domain_error_97c17ca0 @ 0x97c17ca0 (4 bytes) */
int std__domain_error__domain_error_97c17ca0(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  domain_error(this,param_1);
  return;
}

/* std__domain_error__domain_error_97c17ca4 @ 0x97c17ca4 (68 bytes) */
int std__domain_error__domain_error_97c17ca4(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  logic_error__logic_error((unsigned char *)this,param_1);
  *(undefined ***)this = &PTR__domain_error_a7b7ded8;
  return;
}

/* std__invalid_argument__invalid_argument @ 0x97c17ce8 (4 bytes) */
int std__invalid_argument__invalid_argument(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  invalid_argument(this,param_1);
  return;
}

