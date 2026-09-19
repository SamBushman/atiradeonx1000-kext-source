#include "decls.h"

/* std__allocator_wchar_t___allocator_97c177ac @ 0x97c177ac (4 bytes) */
int std__allocator_wchar_t___allocator_97c177ac(param_1)
  unsigned char *param_1;
{
  return;
}

/* std__allocator_wchar_t____allocator @ 0x97c177b0 (8 bytes) */
int std__allocator_wchar_t____allocator(this)
  allocator<wchar_t> *this;
{
  ~allocator(this);
  return;
}

/* std__allocator_wchar_t____allocator_97c177b8 @ 0x97c177b8 (8 bytes) */
int std__allocator_wchar_t____allocator_97c177b8(this)
  allocator<wchar_t> *this;
{
  ~allocator(this);
  return;
}

/* std__allocator_wchar_t____allocator_97c177c0 @ 0x97c177c0 (4 bytes) */
int std__allocator_wchar_t____allocator_97c177c0(this)
  allocator<wchar_t> *this;
{
  return;
}

/* std__allocator_wchar_t___address @ 0x97c177c4 (8 bytes) */
int std__allocator_wchar_t___address(this, param_1)
  allocator<wchar_t> *this;
  unsigned char *param_1;
{
  return param_1;
}

/* std__allocator_wchar_t___address_97c177cc @ 0x97c177cc (8 bytes) */
int std__allocator_wchar_t___address_97c177cc(this, param_1)
  allocator<wchar_t> *this;
  unsigned char *param_1;
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
      uVar1 = __default_alloc_template<true,0>::allocate((int)param_2 << 2);
    }
    else {
      std____throw_bad_alloc();
    }
  }
  return uVar1;
}

/* std__allocator_wchar_t___deallocate @ 0x97c17838 (12 bytes) */
int std__allocator_wchar_t___deallocate(this, param_1, param_2)
  allocator<wchar_t> *this;
  unsigned char *param_1;
  ulong param_2;
{
  __default_alloc_template<true,0>::deallocate(param_1,param_2 << 2);
  return;
}

/* std__allocator_wchar_t___construct @ 0x97c17844 (20 bytes) */
int std__allocator_wchar_t___construct(this, param_1, param_2)
  allocator<wchar_t> *this;
  unsigned char *param_1;
  unsigned char *param_2;
{
  if (param_1 == (unsigned char *)0x0) {
    return;
  }
  *(undefined4 *)param_1 = *(undefined4 *)param_2;
  return;
}

/* std__allocator_wchar_t___destroy @ 0x97c17858 (4 bytes) */
int std__allocator_wchar_t___destroy(param_1)
  unsigned char *param_1;
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
  operator_delete(param_1);
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
  unsigned char *this;
  unsigned char *param_1;
{
  *(int *)this = DAT_a7b7c014 + 8;
  std__string__string((unsigned char *)(this + 4),param_1);
  return;
}

/* std__logic_error__logic_error_97c17b68 @ 0x97c17b68 (4 bytes) */
int std__logic_error__logic_error_97c17b68(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  logic_error(this,param_1);
  return;
}

/* std__logic_error__logic_error_97c17b6c @ 0x97c17b6c (76 bytes) */
int std__logic_error__logic_error_97c17b6c(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  *(int *)this = DAT_a7b7c014 + 8;
  std__string__string((unsigned char *)(this + 4),param_1);
  return;
}

/* std__logic_error___logic_error @ 0x97c17bcc (8 bytes) */
int std__logic_error___logic_error(this)
  unsigned char *this;
{
  ~logic_error(this);
  return;
}

/* std__logic_error___logic_error_97c17bd4 @ 0x97c17bd4 (8 bytes) */
int std__logic_error___logic_error_97c17bd4(this)
  unsigned char *this;
{
  ~logic_error(this);
  return;
}

/* std__logic_error___logic_error_97c17bdc @ 0x97c17bdc (8 bytes) */
int std__logic_error___logic_error_97c17bdc(this)
  unsigned char *this;
{
  ~logic_error(this);
  return;
}

/* std__logic_error___logic_error_97c17be4 @ 0x97c17be4 (136 bytes) */
int std__logic_error___logic_error_97c17be4(this)
  unsigned char *this;
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
    operator_delete(this);
  }
  return;
}

/* std__logic_error__what @ 0x97c17c6c (48 bytes) */
int std__logic_error__what(this)
  unsigned char *this;
{
  *(undefined *)(*(int *)(this + 4) + *(int *)(*(int *)(this + 4) + -0xc)) =
       *PTR__S_terminal_a7b7c0b8;
  return *(undefined4 *)(this + 4);
}

/* std__domain_error__domain_error @ 0x97c17c9c (4 bytes) */
int std__domain_error__domain_error(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  domain_error(this,param_1);
  return;
}

/* std__domain_error__domain_error_97c17ca0 @ 0x97c17ca0 (4 bytes) */
int std__domain_error__domain_error_97c17ca0(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  domain_error(this,param_1);
  return;
}

/* std__domain_error__domain_error_97c17ca4 @ 0x97c17ca4 (68 bytes) */
int std__domain_error__domain_error_97c17ca4(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  logic_error::logic_error((unsigned char *)this,param_1);
  *(undefined ***)this = &PTR__domain_error_a7b7ded8;
  return;
}

/* std__invalid_argument__invalid_argument @ 0x97c17ce8 (4 bytes) */
int std__invalid_argument__invalid_argument(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  invalid_argument(this,param_1);
  return;
}

/* std__invalid_argument__invalid_argument_97c17cec @ 0x97c17cec (4 bytes) */
int std__invalid_argument__invalid_argument_97c17cec(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  invalid_argument(this,param_1);
  return;
}

/* std__invalid_argument__invalid_argument_97c17cf0 @ 0x97c17cf0 (68 bytes) */
int std__invalid_argument__invalid_argument_97c17cf0(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  logic_error::logic_error((unsigned char *)this,param_1);
  *(undefined ***)this = &PTR__invalid_argument_a7b7dec0;
  return;
}

/* std__length_error__length_error @ 0x97c17d34 (4 bytes) */
int std__length_error__length_error(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  length_error(this,param_1);
  return;
}

/* std__length_error__length_error_97c17d38 @ 0x97c17d38 (4 bytes) */
int std__length_error__length_error_97c17d38(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  length_error(this,param_1);
  return;
}

/* std__length_error__length_error_97c17d3c @ 0x97c17d3c (68 bytes) */
int std__length_error__length_error_97c17d3c(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  logic_error::logic_error((unsigned char *)this,param_1);
  *(undefined ***)this = &PTR__length_error_a7b7dea8;
  return;
}

/* std__out_of_range__out_of_range @ 0x97c17d80 (4 bytes) */
int std__out_of_range__out_of_range(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  out_of_range(this,param_1);
  return;
}

/* std__out_of_range__out_of_range_97c17d84 @ 0x97c17d84 (4 bytes) */
int std__out_of_range__out_of_range_97c17d84(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  out_of_range(this,param_1);
  return;
}

/* std__out_of_range__out_of_range_97c17d88 @ 0x97c17d88 (68 bytes) */
int std__out_of_range__out_of_range_97c17d88(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  logic_error::logic_error((unsigned char *)this,param_1);
  *(undefined ***)this = &PTR__out_of_range_a7b7de90;
  return;
}

/* std__runtime_error__runtime_error @ 0x97c17dcc (4 bytes) */
int std__runtime_error__runtime_error(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  *(int *)this = DAT_a7b7c010 + 8;
  std__string__string((unsigned char *)(this + 4),param_1);
  return;
}

/* std__runtime_error__runtime_error_97c17dd0 @ 0x97c17dd0 (4 bytes) */
int std__runtime_error__runtime_error_97c17dd0(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  runtime_error(this,param_1);
  return;
}

/* std__runtime_error__runtime_error_97c17dd4 @ 0x97c17dd4 (76 bytes) */
int std__runtime_error__runtime_error_97c17dd4(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  *(int *)this = DAT_a7b7c010 + 8;
  std__string__string((unsigned char *)(this + 4),param_1);
  return;
}

/* std__runtime_error___runtime_error @ 0x97c17e34 (8 bytes) */
int std__runtime_error___runtime_error(this)
  unsigned char *this;
{
  ~runtime_error(this);
  return;
}

/* std__runtime_error___runtime_error_97c17e3c @ 0x97c17e3c (8 bytes) */
int std__runtime_error___runtime_error_97c17e3c(this)
  unsigned char *this;
{
  ~runtime_error(this);
  return;
}

/* std__runtime_error___runtime_error_97c17e44 @ 0x97c17e44 (8 bytes) */
int std__runtime_error___runtime_error_97c17e44(this)
  unsigned char *this;
{
  ~runtime_error(this);
  return;
}

/* std__runtime_error___runtime_error_97c17e4c @ 0x97c17e4c (136 bytes) */
int std__runtime_error___runtime_error_97c17e4c(this)
  unsigned char *this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint in_r4;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  iVar4 = *(int *)(this + 4);
  *(int *)this = DAT_a7b7c010 + 8;
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
    operator_delete(this);
  }
  return;
}

/* std__runtime_error__what @ 0x97c17ed4 (48 bytes) */
int std__runtime_error__what(this)
  unsigned char *this;
{
  *(undefined *)(*(int *)(this + 4) + *(int *)(*(int *)(this + 4) + -0xc)) =
       *PTR__S_terminal_a7b7c0b8;
  return *(undefined4 *)(this + 4);
}

/* std__range_error__range_error @ 0x97c17f04 (4 bytes) */
int std__range_error__range_error(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  range_error(this,param_1);
  return;
}

/* std__range_error__range_error_97c17f08 @ 0x97c17f08 (4 bytes) */
int std__range_error__range_error_97c17f08(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  range_error(this,param_1);
  return;
}

/* std__range_error__range_error_97c17f0c @ 0x97c17f0c (68 bytes) */
int std__range_error__range_error_97c17f0c(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  runtime_error::runtime_error((unsigned char *)this,param_1);
  *(undefined ***)this = &PTR__range_error_a7b7de78;
  return;
}

/* std__overflow_error__overflow_error @ 0x97c17f50 (4 bytes) */
int std__overflow_error__overflow_error(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  overflow_error(this,param_1);
  return;
}

/* std__overflow_error__overflow_error_97c17f54 @ 0x97c17f54 (4 bytes) */
int std__overflow_error__overflow_error_97c17f54(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  overflow_error(this,param_1);
  return;
}

/* std__overflow_error__overflow_error_97c17f58 @ 0x97c17f58 (68 bytes) */
int std__overflow_error__overflow_error_97c17f58(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  runtime_error::runtime_error((unsigned char *)this,param_1);
  *(undefined ***)this = &PTR__overflow_error_a7b7de60;
  return;
}

/* std__underflow_error__underflow_error @ 0x97c17f9c (4 bytes) */
int std__underflow_error__underflow_error(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  underflow_error(this,param_1);
  return;
}

/* std__underflow_error__underflow_error_97c17fa0 @ 0x97c17fa0 (4 bytes) */
int std__underflow_error__underflow_error_97c17fa0(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  underflow_error(this,param_1);
  return;
}

/* std__underflow_error__underflow_error_97c17fa4 @ 0x97c17fa4 (68 bytes) */
int std__underflow_error__underflow_error_97c17fa4(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  runtime_error::runtime_error((unsigned char *)this,param_1);
  *(undefined ***)this = &PTR__underflow_error_a7b7de48;
  return;
}

/* std__type_info___type_info @ 0x97c17fe8 (8 bytes) */
int std__type_info___type_info(this)
  unsigned char *this;
{
  ~type_info(this);
  return;
}

/* std__type_info___type_info_97c17ff0 @ 0x97c17ff0 (8 bytes) */
int std__type_info___type_info_97c17ff0(this)
  unsigned char *this;
{
  ~type_info(this);
  return;
}

/* std__type_info___type_info_97c17ff8 @ 0x97c17ff8 (8 bytes) */
int std__type_info___type_info_97c17ff8(this)
  unsigned char *this;
{
  ~type_info(this);
  return;
}

/* std__type_info___type_info_97c18000 @ 0x97c18000 (44 bytes) */
int std__type_info___type_info_97c18000(this)
  unsigned char *this;
{
  uint in_r4;
  
  *(int *)this = DAT_a7b7c02c + 8;
  if ((in_r4 & 1) == 0) {
    return;
  }
  operator_delete(this);
  return;
}

/* std__bad_cast___bad_cast @ 0x97c1802c (8 bytes) */
int std__bad_cast___bad_cast(this)
  unsigned char *this;
{
  ~bad_cast(this);
  return;
}

/* std__bad_cast___bad_cast_97c18034 @ 0x97c18034 (8 bytes) */
int std__bad_cast___bad_cast_97c18034(this)
  unsigned char *this;
{
  ~bad_cast(this);
  return;
}

/* std__bad_cast___bad_cast_97c1803c @ 0x97c1803c (8 bytes) */
int std__bad_cast___bad_cast_97c1803c(this)
  unsigned char *this;
{
  ~bad_cast(this);
  return;
}

