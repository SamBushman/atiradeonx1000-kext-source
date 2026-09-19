#include "decls.h"

/* std__string__rbegin @ 0x97c13f18 (60 bytes) */
int std__string__rbegin(this)
  unsigned char * this;
{
  undefined4 local_20;
  
  end();
  *(undefined4 *)(this + 4) = local_20;
  return this;
}

/* std__string__rbegin_97c13f54 @ 0x97c13f54 (60 bytes) */
int std__string__rbegin_97c13f54(this)
  unsigned char * this;
{
  undefined4 local_20;
  
  end();
  *(undefined4 *)(this + 4) = local_20;
  return this;
}

/* std__string__rend @ 0x97c13f90 (60 bytes) */
int std__string__rend(this)
  unsigned char * this;
{
  undefined4 local_20;
  
  begin();
  *(undefined4 *)(this + 4) = local_20;
  return this;
}

/* std__string__rend_97c13fcc @ 0x97c13fcc (60 bytes) */
int std__string__rend_97c13fcc(this)
  unsigned char * this;
{
  undefined4 local_20;
  
  begin();
  *(undefined4 *)(this + 4) = local_20;
  return this;
}

/* std__string__length @ 0x97c14008 (12 bytes) */
int std__string__length(this)
  unsigned char * this;
{
  return *(undefined4 *)(*(int *)this + -0xc);
}

/* std__string__replace @ 0x97c14014 (316 bytes) */
int std__string__replace(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  ulong param_1;
  ulong param_2;
  char *param_3;
  ulong param_4;
{
  char *pcVar1;
  uint uVar2;
  int local_30;
  int local_2c;
  
  uVar2 = *(uint *)(*(int *)this + -0xc);
  if (uVar2 < param_1) {
    std____throw_out_of_range("basic_string__replace");
  }
  if (uVar2 - param_1 <= param_2) {
    param_2 = uVar2 - param_1;
  }
  if (0x3ffffffc - param_4 < uVar2 - param_2) {
    std____throw_length_error("basic_string__replace");
  }
  pcVar1 = *(char **)this;
  if (((*(int *)(pcVar1 + -4) < 1) && (pcVar1 <= param_3)) && (param_3 <= pcVar1 + uVar2)) {
    std__string___M_ibegin();
    std__string___M_ibegin();
    _M_replace_char_const__
              (this,local_30 + param_1,local_2c + param_1 + param_2,param_3,param_3 + param_4,0);
    return;
  }
  std__string___M_ibegin();
  std__string___M_ibegin();
  _M_replace_safe_char_const__
            (this,local_2c + param_1,local_30 + param_1 + param_2,param_3,param_3 + param_4);
  return;
}

/* std__string__replace_97c14150 @ 0x97c14150 (344 bytes) */
int std__string__replace_97c14150(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int local_30;
  int local_2c;
  int local_28;
  
  std__string___M_ibegin();
  param_5 = param_5 - param_4;
  uVar4 = *(uint *)(*(int *)this + -0xc);
  uVar2 = param_2 - local_30;
  if (uVar4 < uVar2) {
    std____throw_out_of_range("basic_string__replace");
  }
  uVar3 = param_3 - param_2;
  if (uVar4 - uVar2 <= (uint)(param_3 - param_2)) {
    uVar3 = uVar4 - uVar2;
  }
  if (0x3ffffffcU - param_5 < uVar4 - uVar3) {
    std____throw_length_error("basic_string__replace");
  }
  uVar1 = *(uint *)this;
  if (((*(int *)(uVar1 - 4) < 1) && (uVar1 <= param_4)) && (param_4 <= uVar1 + uVar4)) {
    std__string___M_ibegin();
    std__string___M_ibegin();
    _M_replace_char_const__
              (this,local_2c + uVar2,local_28 + uVar2 + uVar3,param_4,param_4 + param_5,0);
    return;
  }
  std__string___M_ibegin();
  std__string___M_ibegin();
  _M_replace_safe_char_const__
            (this,local_28 + uVar2,local_2c + uVar2 + uVar3,param_4,param_4 + param_5);
  return;
}

/* std__string__erase @ 0x97c142a8 (376 bytes) */
int std__string__erase(param_1, param_2)
  ulong param_1;
  ulong param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  std__string___M_check((ulong)&local_40);
  std__string___M_fold((ulong)&local_3c,param_1);
  uVar2 = *(uint *)param_1;
  std__string___M_ibegin();
  uVar5 = *(uint *)(*(int *)param_1 + -0xc);
  uVar3 = local_40 - local_38;
  if (uVar5 < uVar3) {
    std____throw_out_of_range("basic_string__replace");
  }
  uVar4 = local_3c - local_40;
  if (uVar5 - uVar3 <= (uint)(local_3c - local_40)) {
    uVar4 = uVar5 - uVar3;
  }
  if (0x3ffffffc < uVar5 - uVar4) {
    std____throw_length_error("basic_string__replace");
  }
  uVar1 = *(uint *)param_1;
  if (((*(int *)(uVar1 - 4) < 1) && (uVar1 <= uVar2)) && (uVar2 <= uVar1 + uVar5)) {
    std__string___M_ibegin();
    std__string___M_ibegin();
    _M_replace_char_const__
              ((unsigned char *)&local_3c,local_34 + uVar3,local_30 + uVar3 + uVar4,uVar2,uVar2,0);
    return;
  }
  std__string___M_ibegin();
  std__string___M_ibegin();
  _M_replace_safe_char_const__
            ((unsigned char *)&local_3c,local_30 + uVar3,local_34 + uVar3 + uVar4,uVar2,uVar2);
  return;
}

/* std__string__resize @ 0x97c14420 (448 bytes) */
int std__string__resize(this, param_1, param_2)
  unsigned char * this;
  ulong param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  if (0x3ffffffc < param_1) {
    std____throw_length_error("basic_string__resize");
  }
  uVar1 = *(uint *)(*(int *)this + -0xc);
  if (uVar1 < param_1) {
    append(this,param_1 - uVar1,param_2);
  }
  else if (param_1 < uVar1) {
    std__string___M_check((ulong)&local_40);
    std__string___M_fold((ulong)&local_3c,(ulong)this);
    uVar1 = *(uint *)this;
    std__string___M_ibegin();
    uVar4 = *(uint *)(*(int *)this + -0xc);
    uVar3 = local_40 - local_38;
    if (uVar4 < uVar3) {
      std____throw_out_of_range("basic_string__replace");
    }
    uVar5 = local_3c - local_40;
    if (uVar4 - uVar3 <= (uint)(local_3c - local_40)) {
      uVar5 = uVar4 - uVar3;
    }
    if (0x3ffffffc < uVar4 - uVar5) {
      std____throw_length_error("basic_string__replace");
    }
    uVar2 = *(uint *)this;
    if (((*(int *)(uVar2 - 4) < 1) && (uVar2 <= uVar1)) && (uVar1 <= uVar2 + uVar4)) {
      std__string___M_ibegin();
      std__string___M_ibegin();
      _M_replace_char_const__
                ((unsigned char *)&local_3c,local_34 + uVar3,local_30 + uVar3 + uVar5,uVar1,uVar1,0);
      return;
    }
    std__string___M_ibegin();
    std__string___M_ibegin();
    _M_replace_safe_char_const__
              ((unsigned char *)&local_3c,local_30 + uVar3,local_34 + uVar3 + uVar5,uVar1,uVar1);
  }
  return;
}

/* std__string__resize_97c145e0 @ 0x97c145e0 (8 bytes) */
int std__string__resize_97c145e0(this, param_1)
  unsigned char * this;
  ulong param_1;
{
  resize(this,param_1,'\0');
  return;
}

/* std__string__reserve @ 0x97c145e8 (224 bytes) */
int std__string__reserve(this, param_1)
  unsigned char * this;
  ulong param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  unsigned char aaStack_20 [20];
  
  iVar5 = *(int *)this;
  if ((*(uint *)(iVar5 + -8) < param_1) || (0 < *(int *)(iVar5 + -4))) {
    if (0x3ffffffc < param_1) {
      std____throw_length_error("basic_string__reserve");
      iVar5 = *(int *)this;
    }
    if (param_1 < *(uint *)(iVar5 + -0xc)) {
      param_1 = *(uint *)(iVar5 + -0xc);
    }
    std__string__get_allocator();
    uVar4 = _Rep___M_clone((unsigned char *)(*(int *)this + -0xc),aaStack_20,
                           param_1 - *(int *)(*(int *)this + -0xc));
    iVar5 = *(int *)this;
    piVar2 = (int *)(iVar5 + -4);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 < 1) {
      _Rep___M_destroy((unsigned char *)(iVar5 + -0xc));
    }
    *(undefined4 *)this = uVar4;
  }
  return;
}

/* std__string__clear @ 0x97c146cc (20 bytes) */
int std__string__clear(this)
  unsigned char * this;
{
  _M_mutate(this,0,*(ulong *)(*(int *)this + -0xc),0);
  return;
}

/* std__string__empty @ 0x97c146e0 (20 bytes) */
int std__string__empty(this)
  unsigned char * this;
{
  return *(int *)(*(int *)this + -0xc) == 0;
}

/* std__string__operator__ @ 0x97c146f4 (12 bytes) */
int std__string__operator__(this, param_1)
  unsigned char * this;
  ulong param_1;
{
  return *(int *)this + param_1;
}

/* std__string__operator___97c14700 @ 0x97c14700 (56 bytes) */
int std__string__operator___97c14700(this, param_1)
  unsigned char * this;
  ulong param_1;
{
  std__string___M_leak(this);
  return *(int *)this + param_1;
}

/* std__string__at @ 0x97c14738 (88 bytes) */
int std__string__at(this, param_1)
  unsigned char * this;
  ulong param_1;
{
  int iVar1;
  
  iVar1 = *(int *)this;
  if (*(uint *)(iVar1 + -0xc) <= param_1) {
    std____throw_out_of_range("basic_string__at");
    iVar1 = *(int *)this;
  }
  return iVar1 + param_1;
}

/* std__string__at_97c14790 @ 0x97c14790 (96 bytes) */
int std__string__at_97c14790(this, param_1)
  unsigned char * this;
  ulong param_1;
{
  if (*(uint *)(*(int *)this + -0xc) <= param_1) {
    std____throw_out_of_range("basic_string__at");
  }
  std__string___M_leak(this);
  return *(int *)this + param_1;
}

/* std__string__operator___97c147f0 @ 0x97c147f0 (4 bytes) */
int std__string__operator___97c147f0(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  append(this,param_1);
  return;
}

/* std__string__append @ 0x97c147f4 (64 bytes) */
int std__string__append(this, param_1)
  unsigned char * this;
  char *param_1;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_1);
  append(this,param_1,sVar1);
  return;
}

/* std__string__operator___97c14834 @ 0x97c14834 (64 bytes) */
int std__string__operator___97c14834(this, param_1)
  unsigned char * this;
  char *param_1;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_1);
  append(this,param_1,sVar1);
  return;
}

/* std__string__operator___97c14874 @ 0x97c14874 (12 bytes) */
int std__string__operator___97c14874(this, param_1)
  unsigned char * this;
  int param_1;
{
  append(this,1,param_1);
  return;
}

/* std__string__append_97c14880 @ 0x97c14880 (164 bytes) */
int std__string__append_97c14880(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  ulong uVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  uVar1 = *(int *)(*(int *)param_1 + -0xc) + *(int *)(*(int *)this + -0xc);
  if (*(uint *)(*(int *)this + -8) < uVar1) {
    reserve(this,uVar1);
  }
  std__string___M_iend();
  std__string___M_iend();
  std__string___M_ibegin();
  std__string___M_iend();
  _M_replace_safe___gnu_cxx____normal_iterator_char__std__string__
            (this,local_30,local_2c,local_28,local_24);
  return;
}

/* std__string__append_97c14924 @ 0x97c14924 (216 bytes) */
int std__string__append_97c14924(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
  ulong param_3;
{
  ulong uVar1;
  uint *puVar2;
  ulong uStack00000024;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30 [6];
  
  puVar2 = &STACKARG(0x24);
  local_30[0] = *(int *)(*(int *)param_1 + -0xc) - param_2;
  if (local_30[0] <= param_3) {
    puVar2 = local_30;
  }
  uVar1 = *puVar2 + *(int *)(*(int *)this + -0xc);
  uStack00000024 = param_3;
  if (*(uint *)(*(int *)this + -8) < uVar1) {
    reserve(this,uVar1);
  }
  std__string___M_iend();
  std__string___M_iend();
  std__string___M_check((ulong)&local_38);
  std__string___M_fold((ulong)&local_34,(ulong)param_1);
  _M_replace_safe___gnu_cxx____normal_iterator_char__std__string__
            ((unsigned char *)&local_34,local_40,local_3c,local_38,local_34);
  return;
}

/* std__string__append_97c149fc @ 0x97c149fc (132 bytes) */
int std__string__append_97c149fc(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  ulong param_2;
{
  ulong uVar1;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar1 = param_2 + *(int *)(*(int *)this + -0xc);
  if (*(uint *)(*(int *)this + -8) < uVar1) {
    reserve(this,uVar1);
  }
  std__string___M_iend();
  std__string___M_iend();
  _M_replace_safe_char_const__(this,local_30,local_2c,param_1,param_1 + param_2);
  return;
}

/* std__string__append_97c14a80 @ 0x97c14a80 (128 bytes) */
int std__string__append_97c14a80(this, param_1, param_2)
  unsigned char * this;
  ulong param_1;
  int param_2;
{
  ulong uVar1;
  undefined3 in_register_00000014;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar1 = param_1 + *(int *)(*(int *)this + -0xc);
  if (*(uint *)(*(int *)this + -8) < uVar1) {
    reserve(this,uVar1);
  }
  std__string___M_iend();
  std__string___M_iend();
  replace(this,local_30,local_2c,param_1,CONCAT31(in_register_00000014,param_2));
  return;
}

/* std__string__push_back @ 0x97c14b00 (96 bytes) */
int std__string__push_back(this, param_1)
  unsigned char * this;
  int param_1;
{
  undefined3 in_register_00000010;
  undefined4 local_30;
  undefined4 local_2c;
  
  std__string___M_iend();
  std__string___M_iend();
  replace(this,local_30,local_2c,1,CONCAT31(in_register_00000010,param_1));
  return;
}

/* std__string__assign_97c14b60 @ 0x97c14b60 (180 bytes) */
int std__string__assign_97c14b60(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  unsigned char aaStack_40 [44];
  
  if (*(int *)this + -0xc != *(int *)param_1 + -0xc) {
    std__string__get_allocator();
    iVar5 = *(int *)param_1;
    std__string__get_allocator();
    uVar4 = _Rep___M_grab((unsigned char *)(iVar5 + -0xc),aaStack_40);
    iVar5 = *(int *)this;
    piVar2 = (int *)(iVar5 + -4);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 < 1) {
      _Rep___M_destroy((unsigned char *)(iVar5 + -0xc));
    }
    *(undefined4 *)this = uVar4;
  }
  return this;
}

/* std__string__assign_97c14c18 @ 0x97c14c18 (120 bytes) */
int std__string__assign_97c14c18(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
  ulong param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)param_1;
  uVar2 = *(uint *)(iVar1 + -0xc);
  if (uVar2 < param_2) {
    std____throw_out_of_range("basic_string__assign");
    iVar1 = *(int *)param_1;
  }
  uVar2 = uVar2 - param_2;
  if (uVar2 <= param_3) {
    param_3 = uVar2;
  }
  assign(this,(char *)(iVar1 + param_2),param_3);
  return;
}

/* std__string__insert @ 0x97c14c90 (16 bytes) */
int std__string__insert(this, param_2, param_3, param_4)
  unsigned char * this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  replace(this,param_2,param_2,param_3,param_4);
  return;
}

/* std__string__insert_97c14ca0 @ 0x97c14ca0 (332 bytes) */
int std__string__insert_97c14ca0(this, param_1, param_2, param_3)
  unsigned char * this;
  ulong param_1;
  char *param_2;
  ulong param_3;
{
  char *pcVar1;
  char *pcVar2;
  size_t sVar3;
  uint uVar4;
  char *pcVar5;
  int local_30;
  int local_2c;
  
  uVar4 = *(uint *)(*(int *)this + -0xc);
  if (uVar4 < param_1) {
    std____throw_out_of_range("basic_string__insert");
  }
  if (0x3ffffffc - param_3 < uVar4) {
    std____throw_length_error("basic_string__insert");
  }
  pcVar2 = *(char **)this;
  if (((*(int *)(pcVar2 + -4) < 1) && (pcVar2 <= param_2)) && (param_2 <= pcVar2 + uVar4)) {
    _M_mutate(this,param_1,0,param_3);
    pcVar1 = param_2 + (*(int *)this - (int)pcVar2);
    pcVar5 = (char *)(*(int *)this + param_1);
    pcVar2 = pcVar1;
    if ((pcVar5 < pcVar1 + param_3) && (pcVar2 = pcVar1 + param_3, pcVar1 < pcVar5)) {
      sVar3 = (int)pcVar5 - (int)pcVar1;
      _memcpy(pcVar5,pcVar1,sVar3);
      pcVar2 = pcVar5 + param_3;
      pcVar5 = pcVar5 + sVar3;
      param_3 = param_3 - sVar3;
    }
    _memcpy(pcVar5,pcVar2,param_3);
  }
  else {
    std__string___M_ibegin();
    std__string___M_ibegin();
    this = _M_replace_safe_char_const__
                     (this,local_2c + param_1,local_30 + param_1,param_2,param_2 + param_3);
  }
  return this;
}

/* std__string__insert_97c14dec @ 0x97c14dec (388 bytes) */
int std__string__insert_97c14dec(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  ulong param_1;
  unsigned char * param_2;
  ulong param_3;
  ulong param_4;
{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  size_t sVar5;
  uint uVar6;
  uint uVar7;
  void *pvVar8;
  int local_30;
  int local_2c;
  
  iVar3 = *(int *)param_2;
  uVar6 = *(uint *)(iVar3 + -0xc);
  if (uVar6 < param_3) {
    std____throw_out_of_range("basic_string__insert");
    iVar3 = *(int *)param_2;
  }
  uVar6 = uVar6 - param_3;
  if (uVar6 <= param_4) {
    param_4 = uVar6;
  }
  uVar6 = iVar3 + param_3;
  uVar7 = *(uint *)(*(int *)this + -0xc);
  if (uVar7 < param_1) {
    std____throw_out_of_range("basic_string__insert");
  }
  if (0x3ffffffc - param_4 < uVar7) {
    std____throw_length_error("basic_string__insert");
  }
  uVar4 = *(uint *)this;
  if (((*(int *)(uVar4 - 4) < 1) && (uVar4 <= uVar6)) && (uVar6 <= uVar4 + uVar7)) {
    _M_mutate(this,param_1,0,param_4);
    pvVar1 = (void *)(*(int *)this + (uVar6 - uVar4));
    pvVar8 = (void *)(*(int *)this + param_1);
    pvVar2 = pvVar1;
    if ((pvVar8 < (void *)((int)pvVar1 + param_4)) &&
       (pvVar2 = (void *)((int)pvVar1 + param_4), pvVar1 < pvVar8)) {
      sVar5 = (int)pvVar8 - (int)pvVar1;
      _memcpy(pvVar8,pvVar1,sVar5);
      pvVar2 = (void *)((int)pvVar8 + param_4);
      pvVar8 = (void *)((int)pvVar8 + sVar5);
      param_4 = param_4 - sVar5;
    }
    _memcpy(pvVar8,pvVar2,param_4);
  }
  else {
    std__string___M_ibegin();
    std__string___M_ibegin();
    this = _M_replace_safe_char_const__
                     (this,local_2c + param_1,local_30 + param_1,uVar6,uVar6 + param_4);
  }
  return this;
}

/* std__string__insert_97c14f70 @ 0x97c14f70 (332 bytes) */
int std__string__insert_97c14f70(this, param_1, param_2)
  unsigned char * this;
  ulong param_1;
  unsigned char * param_2;
{
  void *pvVar1;
  void *pvVar2;
  size_t sVar3;
  uint uVar4;
  uint uVar5;
  size_t sVar6;
  uint uVar7;
  void *pvVar8;
  int local_30;
  int local_2c;
  
  uVar4 = *(uint *)param_2;
  uVar7 = *(uint *)(*(int *)this + -0xc);
  sVar3 = *(ulong *)(uVar4 - 0xc);
  if (uVar7 < param_1) {
    std____throw_out_of_range("basic_string__insert");
  }
  if (0x3ffffffc - sVar3 < uVar7) {
    std____throw_length_error("basic_string__insert");
  }
  uVar5 = *(uint *)this;
  if (((*(int *)(uVar5 - 4) < 1) && (uVar5 <= uVar4)) && (uVar4 <= uVar5 + uVar7)) {
    _M_mutate(this,param_1,0,sVar3);
    pvVar1 = (void *)(*(int *)this + (uVar4 - uVar5));
    pvVar8 = (void *)(*(int *)this + param_1);
    pvVar2 = pvVar1;
    if ((pvVar8 < (void *)((int)pvVar1 + sVar3)) &&
       (pvVar2 = (void *)((int)pvVar1 + sVar3), pvVar1 < pvVar8)) {
      sVar6 = (int)pvVar8 - (int)pvVar1;
      _memcpy(pvVar8,pvVar1,sVar6);
      pvVar2 = (void *)((int)pvVar8 + sVar3);
      pvVar8 = (void *)((int)pvVar8 + sVar6);
      sVar3 = sVar3 - sVar6;
    }
    _memcpy(pvVar8,pvVar2,sVar3);
  }
  else {
    std__string___M_ibegin();
    std__string___M_ibegin();
    this = _M_replace_safe_char_const__
                     (this,local_2c + param_1,local_30 + param_1,uVar4,uVar4 + sVar3);
  }
  return this;
}

/* std__string__insert_97c150bc @ 0x97c150bc (72 bytes) */
int std__string__insert_97c150bc(this, param_1, param_2)
  unsigned char * this;
  ulong param_1;
  char *param_2;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_2);
  insert(this,param_1,param_2,sVar1);
  return;
}

/* std__string__insert_97c15104 @ 0x97c15104 (92 bytes) */
int std__string__insert_97c15104(this, param_1, param_2, param_3)
  unsigned char * this;
  ulong param_1;
  ulong param_2;
  int param_3;
{
  undefined3 in_register_00000018;
  undefined4 local_30 [7];
  
  std__string___M_check((ulong)local_30);
  replace(this,local_30[0],local_30[0],param_2,CONCAT31(in_register_00000018,param_3));
  return this;
}

/* std__string__insert_97c15160 @ 0x97c15160 (148 bytes) */
int std__string__insert_97c15160(param_1, param_2, param_3, param_4)
  int *param_1;
  unsigned char * param_2;
  int param_3;
  undefined4 param_4;
{
  int local_30 [6];
  
  std__string___M_ibegin();
  param_3 = param_3 - local_30[0];
  std__string___M_check((ulong)local_30);
  replace(param_2,local_30[0],local_30[0],1,param_4);
  *(undefined4 *)(*(int *)param_2 + -4) = 0xffffffff;
  std__string___M_ibegin();
  *param_1 = local_30[0] + param_3;
  return param_1;
}

/* std__string__erase_97c151f4 @ 0x97c151f4 (128 bytes) */
int std__string__erase_97c151f4(param_1, param_2, param_3)
  int *param_1;
  unsigned char * param_2;
  int param_3;
{
  std__string___M_ibegin();
  replace(param_2,param_3,param_3 + 1,*(undefined4 *)param_2,*(undefined4 *)param_2);
  *(undefined4 *)(*(int *)param_2 + -4) = 0xffffffff;
  std__string___M_ibegin();
  *param_1 = param_3;
  return param_1;
}

/* std__string__erase_97c15274 @ 0x97c15274 (132 bytes) */
int std__string__erase_97c15274(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  unsigned char * param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  std__string___M_ibegin();
  replace(param_2,param_3,param_4,*(undefined4 *)param_2,*(undefined4 *)param_2);
  *(undefined4 *)(*(int *)param_2 + -4) = 0xffffffff;
  std__string___M_ibegin();
  *param_1 = param_3;
  return param_1;
}

/* std__string__replace_97c152f8 @ 0x97c152f8 (12 bytes) */
int std__string__replace_97c152f8(this, param_1, param_2, param_3)
  unsigned char * this;
  ulong param_1;
  ulong param_2;
  unsigned char * param_3;
{
  replace(this,param_1,param_2,*(char **)param_3,*(ulong *)(*(char **)param_3 + -0xc));
  return;
}

/* std__string__replace_97c15304 @ 0x97c15304 (136 bytes) */
int std__string__replace_97c15304(this, param_1, param_2, param_3, param_4, param_5)
  unsigned char * this;
  ulong param_1;
  ulong param_2;
  unsigned char * param_3;
  ulong param_4;
  ulong param_5;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)param_3;
  uVar2 = *(uint *)(iVar1 + -0xc);
  if (uVar2 < param_4) {
    std____throw_out_of_range("basic_string__replace");
    iVar1 = *(int *)param_3;
  }
  uVar2 = uVar2 - param_4;
  if (uVar2 <= param_5) {
    param_5 = uVar2;
  }
  replace(this,param_1,param_2,(char *)(iVar1 + param_4),param_5);
  return;
}

/* std__string__replace_97c1538c @ 0x97c1538c (80 bytes) */
int std__string__replace_97c1538c(this, param_1, param_2, param_3)
  unsigned char * this;
  ulong param_1;
  ulong param_2;
  char *param_3;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_3);
  replace(this,param_1,param_2,param_3,sVar1);
  return;
}

/* std__string__replace_97c153dc @ 0x97c153dc (120 bytes) */
int std__string__replace_97c153dc(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  ulong param_1;
  ulong param_2;
  ulong param_3;
  int param_4;
{
  undefined3 in_register_0000001c;
  undefined4 local_30;
  undefined4 local_2c [4];
  
  std__string___M_check((ulong)&local_30);
  std__string___M_fold((ulong)local_2c,(ulong)this);
  replace(this,local_30,local_2c[0],param_3,CONCAT31(in_register_0000001c,param_4));
  return;
}

/* std__string__replace_97c15454 @ 0x97c15454 (96 bytes) */
int std__string__replace_97c15454(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int param_3;
  char *param_4;
  ulong param_5;
{
  undefined4 local_30;
  
  std__string___M_ibegin();
  replace(this,param_2 - local_30,param_3 - param_2,param_4,param_5);
  return;
}

/* std__string__replace_97c154b4 @ 0x97c154b4 (96 bytes) */
int std__string__replace_97c154b4(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  int param_3;
  undefined4 *param_4;
{
  char *pcVar1;
  ulong uVar2;
  int local_30;
  
  pcVar1 = (char *)*param_4;
  uVar2 = *(ulong *)(pcVar1 + -0xc);
  std__string___M_ibegin();
  replace(this,param_2 - local_30,param_3 - param_2,pcVar1,uVar2);
  return;
}

/* std__string__replace_97c15514 @ 0x97c15514 (80 bytes) */
int std__string__replace_97c15514(this, param_2, param_3, param_4)
  unsigned char * this;
  undefined4 param_2;
  undefined4 param_3;
  char *param_4;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_4);
  replace(this,param_2,param_3,param_4,sVar1);
  return;
}

/* std__string__replace_97c15564 @ 0x97c15564 (180 bytes) */
int std__string__replace_97c15564(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
{
  int local_30;
  
  std__string___M_ibegin();
  if (0x3ffffffcU - (*(int *)(*(int *)this + -0xc) - (param_3 - param_2)) <= param_4) {
    std____throw_length_error("basic_string__replace");
  }
  _M_mutate(this,param_2 - local_30,param_3 - param_2,param_4);
  if (param_4 != 0) {
    _memset((void *)(*(int *)this + (param_2 - local_30)),param_5,param_4);
  }
  return this;
}

/* std__string__replace_97c15618 @ 0x97c15618 (96 bytes) */
int std__string__replace_97c15618(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int param_3;
  char *param_4;
  int param_5;
{
  undefined4 local_30;
  
  std__string___M_ibegin();
  replace(this,param_2 - local_30,param_3 - param_2,param_4,param_5 - (int)param_4);
  return;
}

/* std__string__replace_97c15678 @ 0x97c15678 (96 bytes) */
int std__string__replace_97c15678(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int param_3;
  char *param_4;
  int param_5;
{
  undefined4 local_30;
  
  std__string___M_ibegin();
  replace(this,param_2 - local_30,param_3 - param_2,param_4,param_5 - (int)param_4);
  return;
}

/* std__string__replace_97c156d8 @ 0x97c156d8 (96 bytes) */
int std__string__replace_97c156d8(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int param_3;
  char *param_4;
  int param_5;
{
  undefined4 local_30;
  
  std__string___M_ibegin();
  replace(this,param_2 - local_30,param_3 - param_2,param_4,param_5 - (int)param_4);
  return;
}

/* std__string___S_construct @ 0x97c15738 (140 bytes) */
int std__string___S_construct(param_1, param_2, param_3)
  ulong param_1;
  int param_2;
  unsigned char * param_3;
{
  ulong *puVar1;
  ulong *puVar2;
  undefined3 in_register_00000010;
  char in_RESERVE;
  
  if (param_1 == 0) {
    if (in_RESERVE != '\0') {
      DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
    }
    puVar1 = (ulong *)&DAT_a7b7bf90;
  }
  else {
    puVar2 = (ulong *)_Rep___S_create(param_1,param_3);
    puVar1 = puVar2 + 3;
    _memset(puVar1,CONCAT31(in_register_00000010,param_2),param_1);
    *puVar2 = param_1;
    *(undefined1 *)((int)puVar1 + param_1) = 0;
  }
  return puVar1;
}

/* std__string__copy @ 0x97c157c4 (132 bytes) */
int std__string__copy(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  ulong param_2;
  ulong param_3;
{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)this;
  if (*(uint *)(iVar2 + -0xc) < param_3) {
    std____throw_out_of_range("basic_string__copy");
    iVar2 = *(int *)this;
  }
  uVar1 = *(int *)(iVar2 + -0xc) - param_3;
  if (uVar1 < param_2) {
    param_2 = uVar1;
  }
  _memcpy(param_1,(void *)(iVar2 + param_3),param_2);
  return param_2;
}

/* std__string__swap @ 0x97c15848 (140 bytes) */
int std__string__swap(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined4 uVar1;
  
  if (*(int *)(*(int *)this + -4) < 0) {
    *(undefined4 *)(*(int *)this + -4) = 0;
  }
  if (*(int *)(*(int *)param_1 + -4) < 0) {
    *(undefined4 *)(*(int *)param_1 + -4) = 0;
  }
  std__string__get_allocator();
  std__string__get_allocator();
  uVar1 = *(undefined4 *)this;
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)param_1 = uVar1;
  return;
}

/* std__string__c_str @ 0x97c158d4 (48 bytes) */
int std__string__c_str(this)
  unsigned char * this;
{
  *(undefined1 *)(*(int *)this + *(int *)(*(int *)this + -0xc)) = _Rep___S_terminal;
  return *(undefined4 *)this;
}

/* std__string__data @ 0x97c15904 (8 bytes) */
int std__string__data(this)
  unsigned char * this;
{
  return *(undefined4 *)this;
}

/* std__string__find @ 0x97c1590c (128 bytes) */
int std__string__find(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  ulong param_2;
  ulong param_3;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  
  uVar1 = param_2 + param_3;
  uVar3 = *(uint *)(*(int *)this + -0xc);
  if (uVar1 <= uVar3) {
    pvVar4 = (void *)(param_2 + *(int *)this);
    do {
      iVar2 = _memcmp(pvVar4,param_1,param_3);
      if (iVar2 == 0) {
        return param_2;
      }
      uVar1 = uVar1 + 1;
      param_2 = param_2 + 1;
      pvVar4 = (void *)((int)pvVar4 + 1);
    } while (uVar1 <= uVar3);
  }
  return 0xffffffff;
}

/* std__string__find_97c1598c @ 0x97c1598c (12 bytes) */
int std__string__find_97c1598c(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
{
  find(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0xc));
  return;
}

/* std__string__find_97c15998 @ 0x97c15998 (72 bytes) */
int std__string__find_97c15998(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  ulong param_2;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_1);
  find(this,param_1,param_2,sVar1);
  return;
}

/* std__string__find_97c159e0 @ 0x97c159e0 (96 bytes) */
int std__string__find_97c159e0(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  ulong param_2;
{
  void *pvVar1;
  int iVar2;
  int iVar3;
  char cStack0000001c;
  
  iVar2 = -1;
  iVar3 = *(int *)this;
  if ((param_2 < *(uint *)(iVar3 + -0xc)) &&
     (cStack0000001c = param_1,
     pvVar1 = _memchr((void *)(iVar3 + param_2),(int)param_1,*(uint *)(iVar3 + -0xc) - param_2),
     pvVar1 != (void *)0x0)) {
    iVar2 = (int)pvVar1 - iVar3;
  }
  return iVar2;
}

/* std__string__rfind @ 0x97c15a40 (12 bytes) */
int std__string__rfind(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
{
  rfind(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0xc));
  return;
}

/* std__string__rfind_97c15a4c @ 0x97c15a4c (148 bytes) */
int std__string__rfind_97c15a4c(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  ulong param_2;
  ulong param_3;
{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uStack00000020;
  uint local_30 [7];
  
  iVar4 = *(int *)this;
  local_30[0] = *(uint *)(iVar4 + -0xc);
  if (param_3 <= local_30[0]) {
    local_30[0] = local_30[0] - param_3;
    puVar2 = &STACKARG(0x20);
    if (local_30[0] <= param_2) {
      puVar2 = local_30;
    }
    uStack00000020 = *puVar2;
    do {
      uVar1 = uStack00000020;
      iVar3 = _memcmp((void *)(iVar4 + uStack00000020),param_1,param_3);
      if (iVar3 == 0) {
        return uVar1;
      }
      uStack00000020 = uVar1 - 1;
    } while (uStack00000020 != 0xffffffff);
  }
  return 0xffffffff;
}

/* std__string__rfind_97c15ae0 @ 0x97c15ae0 (72 bytes) */
int std__string__rfind_97c15ae0(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  ulong param_2;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_1);
  rfind(this,param_1,param_2,sVar1);
  return;
}

