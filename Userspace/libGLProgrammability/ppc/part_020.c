#include "decls.h"

/* std__string__string_97c1380c @ 0x97c1380c (4 bytes) */
int std__string__string_97c1380c(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
  ulong param_3;
{
  char *pcVar1;
  undefined1 auStack_50 [4];
  undefined4 auStack_4c [3];
  undefined1 auStack_40 [16];
  allocator aaStack_30 [24];
  
  std__string___M_check((ulong)auStack_50);
  _M_fold((ulong)auStack_4c,(ulong)param_1);
  pcVar1 = _S_construct<__gnu_cxx::__normal_iterator<char*,std::string>>
                     (auStack_4c,auStack_4c[0],auStack_40,0);
  _Alloc_hider::_Alloc_hider((unsigned char *)this,pcVar1,aaStack_30);
  return;
}

/* std__string__string_97c13810 @ 0x97c13810 (120 bytes) */
int std__string__string_97c13810(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
  ulong param_3;
{
  char *pcVar1;
  undefined1 local_50 [4];
  undefined4 local_4c [3];
  undefined1 auStack_40 [16];
  allocator aaStack_30 [24];
  
  std__string___M_check((ulong)local_50);
  _M_fold((ulong)local_4c,(ulong)param_1);
  pcVar1 = _S_construct<__gnu_cxx::__normal_iterator<char*,std::string>>
                     (local_4c,local_4c[0],auStack_40,0);
  _Alloc_hider::_Alloc_hider((unsigned char *)this,pcVar1,aaStack_30);
  return;
}

/* std__string__string_97c1388c @ 0x97c1388c (4 bytes) */
int std__string__string_97c1388c(this, param_1, param_2, param_3, param_4)
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
  ulong param_3;
  unsigned char *param_4;
{
  string(this,param_1,param_2,param_3,param_4);
  return;
}

/* std__string__string_97c13890 @ 0x97c13890 (4 bytes) */
int std__string__string_97c13890(this, param_1, param_2, param_3, param_4)
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
  ulong param_3;
  unsigned char *param_4;
{
  string(this,param_1,param_2,param_3,param_4);
  return;
}

/* std__string__string_97c13894 @ 0x97c13894 (124 bytes) */
int std__string__string_97c13894(this, param_1, param_2, param_3, param_4)
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
  ulong param_3;
  unsigned char *param_4;
{
  char *pcVar1;
  undefined1 local_30 [4];
  undefined4 local_2c [4];
  
  std__string___M_check((ulong)local_30);
  _M_fold((ulong)local_2c,(ulong)param_1);
  pcVar1 = _S_construct<__gnu_cxx::__normal_iterator<char*,std::string>>
                     (local_2c,local_2c[0],param_4,0);
  _Alloc_hider::_Alloc_hider((unsigned char *)this,pcVar1,param_4);
  return;
}

/* std__string__string_97c13910 @ 0x97c13910 (4 bytes) */
int std__string__string_97c13910(this, param_1, param_2, param_3)
  unsigned char *this;
  char *param_1;
  ulong param_2;
  unsigned char *param_3;
{
  string(this,param_1,param_2,param_3);
  return;
}

/* std__string__string_97c13914 @ 0x97c13914 (4 bytes) */
int std__string__string_97c13914(this, param_1, param_2, param_3)
  unsigned char *this;
  char *param_1;
  ulong param_2;
  unsigned char *param_3;
{
  string(this,param_1,param_2,param_3);
  return;
}

/* std__string__string_97c13918 @ 0x97c13918 (80 bytes) */
int std__string__string_97c13918(this, param_1, param_2, param_3)
  unsigned char *this;
  char *param_1;
  ulong param_2;
  unsigned char *param_3;
{
  char *pcVar1;
  
  pcVar1 = _S_construct<char_const*>(this,param_1 + param_2,param_3,0);
  _Alloc_hider::_Alloc_hider((unsigned char *)this,pcVar1,param_3);
  return;
}

/* std__string__string_97c13968 @ 0x97c13968 (4 bytes) */
int std__string__string_97c13968(this, param_1, param_2)
  unsigned char *this;
  char *param_1;
  unsigned char *param_2;
{
  string *psVar1;
  char *pcVar2;
  
  if (param_1 == (char *)0x0) {
    pcVar2 = (char *)0xffffffff;
    psVar1 = this;
  }
  else {
    psVar1 = (unsigned char *)_strlen(param_1);
    pcVar2 = param_1 + (int)psVar1;
  }
  pcVar2 = _S_construct<char_const*>(psVar1,pcVar2,param_2,0);
  _Alloc_hider::_Alloc_hider((unsigned char *)this,pcVar2,param_2);
  return;
}

/* std__string__string_97c1396c @ 0x97c1396c (4 bytes) */
int std__string__string_97c1396c(this, param_1, param_2)
  unsigned char *this;
  char *param_1;
  unsigned char *param_2;
{
  string *psVar1;
  char *pcVar2;
  
  if (param_1 == (char *)0x0) {
    pcVar2 = (char *)0xffffffff;
    psVar1 = this;
  }
  else {
    psVar1 = (unsigned char *)_strlen(param_1);
    pcVar2 = param_1 + (int)psVar1;
  }
  pcVar2 = _S_construct<char_const*>(psVar1,pcVar2,param_2,0);
  _Alloc_hider::_Alloc_hider((unsigned char *)this,pcVar2,param_2);
  return;
}

/* std__string__string_97c13970 @ 0x97c13970 (104 bytes) */
int std__string__string_97c13970(this, param_1, param_2)
  unsigned char *this;
  char *param_1;
  unsigned char *param_2;
{
  string *psVar1;
  char *pcVar2;
  
  if (param_1 == (char *)0x0) {
    pcVar2 = (char *)0xffffffff;
    psVar1 = this;
  }
  else {
    psVar1 = (unsigned char *)_strlen(param_1);
    pcVar2 = param_1 + (int)psVar1;
  }
  pcVar2 = _S_construct<char_const*>(psVar1,pcVar2,param_2,0);
  _Alloc_hider::_Alloc_hider((unsigned char *)this,pcVar2,param_2);
  return;
}

/* std__string__string_97c139d8 @ 0x97c139d8 (4 bytes) */
int std__string__string_97c139d8(this, param_1, param_2, param_3)
  unsigned char *this;
  ulong param_1;
  int param_2;
  unsigned char *param_3;
{
  string(this,param_1,param_2,param_3);
  return;
}

/* std__string__string_97c139dc @ 0x97c139dc (4 bytes) */
int std__string__string_97c139dc(this, param_1, param_2, param_3)
  unsigned char *this;
  ulong param_1;
  int param_2;
  unsigned char *param_3;
{
  string(this,param_1,param_2,param_3);
  return;
}

/* std__string__string_97c139e0 @ 0x97c139e0 (76 bytes) */
int std__string__string_97c139e0(this, param_1, param_2, param_3)
  unsigned char *this;
  ulong param_1;
  int param_2;
  unsigned char *param_3;
{
  char *pcVar1;
  
  pcVar1 = (char *)std__string___S_construct(param_1,param_2,param_3);
  _Alloc_hider::_Alloc_hider((unsigned char *)this,pcVar1,param_3);
  return;
}

/* std__string___string @ 0x97c13a2c (8 bytes) */
int std__string___string(this)
  unsigned char *this;
{
  ~string(this);
  return;
}

/* std__string___string_97c13a34 @ 0x97c13a34 (8 bytes) */
int std__string___string_97c13a34(this)
  unsigned char *this;
{
  ~string(this);
  return;
}

/* std__string___string_97c13a3c @ 0x97c13a3c (92 bytes) */
int std__string___string_97c13a3c(this)
  unsigned char *this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  iVar4 = *(int *)this;
  get_allocator();
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
    _Rep::_M_destroy((unsigned char *)(iVar4 + -0xc));
  }
  return;
}

/* std__string__operator_ @ 0x97c13a98 (4 bytes) */
int std__string__operator_(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  assign(this,param_1);
  return;
}

/* std__string__max_size @ 0x97c13a9c (12 bytes) */
int std__string__max_size()
{
  return 0x3ffffffc;
}

/* std__string__assign @ 0x97c13aa8 (252 bytes) */
int std__string__assign(this, param_1, param_2)
  unsigned char *this;
  char *param_1;
  ulong param_2;
{
  string *psVar1;
  undefined4 local_30;
  undefined4 local_2c;
  
  if (0x3ffffffc < param_2) {
    std____throw_length_error("basic_string::assign");
  }
  psVar1 = *(string **)this;
  if (((0 < *(int *)(psVar1 + -4)) || (param_1 < psVar1)) ||
     (psVar1 + *(int *)(psVar1 + -0xc) < param_1)) {
    _M_ibegin();
    _M_iend();
    psVar1 = _M_replace_safe<char_const*>(psVar1,local_30,local_2c,param_1,param_1 + param_2);
    return psVar1;
  }
  if ((uint)((int)param_1 - (int)psVar1) < param_2) {
    if ((unsigned char *)param_1 == psVar1) goto LAB_97c13b7c;
    _memmove(psVar1,param_1,param_2);
  }
  else {
    _memcpy(psVar1,param_1,param_2);
  }
  psVar1 = *(string **)this;
LAB_97c13b7c:
  *(ulong *)(psVar1 + -0xc) = param_2;
  *(undefined1 *)(*(int *)this + param_2) = 0;
  return this;
}

/* std__string__assign_97c13ba4 @ 0x97c13ba4 (260 bytes) */
int std__string__assign_97c13ba4(this, param_1)
  unsigned char *this;
  char *param_1;
{
  size_t sVar1;
  string *psVar2;
  undefined4 local_30;
  undefined4 local_2c;
  
  sVar1 = _strlen(param_1);
  if (0x3ffffffc < sVar1) {
    std____throw_length_error("basic_string::assign");
  }
  psVar2 = *(string **)this;
  if (((0 < *(int *)(psVar2 + -4)) || (param_1 < psVar2)) ||
     (psVar2 + *(int *)(psVar2 + -0xc) < param_1)) {
    _M_ibegin();
    _M_iend();
    psVar2 = _M_replace_safe<char_const*>(psVar2,local_30,local_2c,param_1,param_1 + sVar1);
    return psVar2;
  }
  if ((uint)((int)param_1 - (int)psVar2) < sVar1) {
    if ((unsigned char *)param_1 == psVar2) goto LAB_97c13c80;
    _memmove(psVar2,param_1,sVar1);
  }
  else {
    _memcpy(psVar2,param_1,sVar1);
  }
  psVar2 = *(string **)this;
LAB_97c13c80:
  *(size_t *)(psVar2 + -0xc) = sVar1;
  *(undefined1 *)(*(int *)this + sVar1) = 0;
  return this;
}

/* std__string__operator__97c13ca8 @ 0x97c13ca8 (260 bytes) */
int std__string__operator__97c13ca8(this, param_1)
  unsigned char *this;
  char *param_1;
{
  size_t sVar1;
  string *psVar2;
  undefined4 local_30;
  undefined4 local_2c;
  
  sVar1 = _strlen(param_1);
  if (0x3ffffffc < sVar1) {
    std____throw_length_error("basic_string::assign");
  }
  psVar2 = *(string **)this;
  if (((0 < *(int *)(psVar2 + -4)) || (param_1 < psVar2)) ||
     (psVar2 + *(int *)(psVar2 + -0xc) < param_1)) {
    _M_ibegin();
    _M_iend();
    psVar2 = _M_replace_safe<char_const*>(psVar2,local_30,local_2c,param_1,param_1 + sVar1);
    return psVar2;
  }
  if ((uint)((int)param_1 - (int)psVar2) < sVar1) {
    if ((unsigned char *)param_1 == psVar2) goto LAB_97c13d84;
    _memmove(psVar2,param_1,sVar1);
  }
  else {
    _memcpy(psVar2,param_1,sVar1);
  }
  psVar2 = *(string **)this;
LAB_97c13d84:
  *(size_t *)(psVar2 + -0xc) = sVar1;
  *(undefined1 *)(*(int *)this + sVar1) = 0;
  return this;
}

/* std__string__assign_97c13dac @ 0x97c13dac (100 bytes) */
int std__string__assign_97c13dac(this, param_1, param_2)
  unsigned char *this;
  ulong param_1;
  int param_2;
{
  undefined3 in_register_00000014;
  undefined4 local_30;
  undefined4 local_2c;
  
  _M_ibegin();
  _M_iend();
  replace(this,local_30,local_2c,param_1,CONCAT31(in_register_00000014,param_2));
  return;
}

/* std__string__operator__97c13e10 @ 0x97c13e10 (96 bytes) */
int std__string__operator__97c13e10(this, param_1)
  unsigned char *this;
  int param_1;
{
  undefined3 in_register_00000010;
  undefined4 local_30;
  undefined4 local_2c;
  
  _M_ibegin();
  _M_iend();
  replace(this,local_30,local_2c,1,CONCAT31(in_register_00000010,param_1));
  return;
}

/* std__string__begin @ 0x97c13e70 (64 bytes) */
int std__string__begin()
{
  undefined4 *in_r3;
  string *in_r4;
  
  _M_leak(in_r4);
  *in_r3 = *(undefined4 *)in_r4;
  return in_r3;
}

/* std__string__begin_97c13eb0 @ 0x97c13eb0 (12 bytes) */
int std__string__begin_97c13eb0()
{
  undefined4 *in_r3;
  undefined4 *in_r4;
  
  *in_r3 = *in_r4;
  return;
}

/* std__string__end @ 0x97c13ebc (72 bytes) */
int std__string__end()
{
  int *in_r3;
  string *in_r4;
  
  _M_leak(in_r4);
  *in_r3 = *(int *)in_r4 + *(int *)(*(int *)in_r4 + -0xc);
  return in_r3;
}

/* std__string__end_97c13f04 @ 0x97c13f04 (20 bytes) */
int std__string__end_97c13f04()
{
  int *in_r3;
  int *in_r4;
  
  *in_r3 = *in_r4 + *(int *)(*in_r4 + -0xc);
  return;
}

/* std__string__rbegin @ 0x97c13f18 (60 bytes) */
int std__string__rbegin(this)
  unsigned char *this;
{
  undefined4 local_20;
  
  end();
  *(undefined4 *)(this + 4) = local_20;
  return this;
}

/* std__string__rbegin_97c13f54 @ 0x97c13f54 (60 bytes) */
int std__string__rbegin_97c13f54(this)
  unsigned char *this;
{
  undefined4 local_20;
  
  end();
  *(undefined4 *)(this + 4) = local_20;
  return this;
}

/* std__string__rend @ 0x97c13f90 (60 bytes) */
int std__string__rend(this)
  unsigned char *this;
{
  undefined4 local_20;
  
  begin();
  *(undefined4 *)(this + 4) = local_20;
  return this;
}

/* std__string__rend_97c13fcc @ 0x97c13fcc (60 bytes) */
int std__string__rend_97c13fcc(this)
  unsigned char *this;
{
  undefined4 local_20;
  
  begin();
  *(undefined4 *)(this + 4) = local_20;
  return this;
}

/* std__string__length @ 0x97c14008 (12 bytes) */
int std__string__length(this)
  unsigned char *this;
{
  return *(undefined4 *)(*(int *)this + -0xc);
}

/* std__string__replace @ 0x97c14014 (316 bytes) */
int std__string__replace(this, param_1, param_2, param_3, param_4)
  unsigned char *this;
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
    std____throw_out_of_range("basic_string::replace");
  }
  if (uVar2 - param_1 <= param_2) {
    param_2 = uVar2 - param_1;
  }
  if (0x3ffffffc - param_4 < uVar2 - param_2) {
    std____throw_length_error("basic_string::replace");
  }
  pcVar1 = *(char **)this;
  if (((*(int *)(pcVar1 + -4) < 1) && (pcVar1 <= param_3)) && (param_3 <= pcVar1 + uVar2)) {
    _M_ibegin();
    _M_ibegin();
    _M_replace<char_const*>
              (this,local_30 + param_1,local_2c + param_1 + param_2,param_3,param_3 + param_4,0);
    return;
  }
  _M_ibegin();
  _M_ibegin();
  _M_replace_safe<char_const*>
            (this,local_2c + param_1,local_30 + param_1 + param_2,param_3,param_3 + param_4);
  return;
}

/* std__string__replace_97c14150 @ 0x97c14150 (344 bytes) */
int std__string__replace_97c14150(this, param_2, param_3, param_4, param_5)
  unsigned char *this;
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
  
  _M_ibegin();
  param_5 = param_5 - param_4;
  uVar4 = *(uint *)(*(int *)this + -0xc);
  uVar2 = param_2 - local_30;
  if (uVar4 < uVar2) {
    std____throw_out_of_range("basic_string::replace");
  }
  uVar3 = param_3 - param_2;
  if (uVar4 - uVar2 <= (uint)(param_3 - param_2)) {
    uVar3 = uVar4 - uVar2;
  }
  if (0x3ffffffcU - param_5 < uVar4 - uVar3) {
    std____throw_length_error("basic_string::replace");
  }
  uVar1 = *(uint *)this;
  if (((*(int *)(uVar1 - 4) < 1) && (uVar1 <= param_4)) && (param_4 <= uVar1 + uVar4)) {
    _M_ibegin();
    _M_ibegin();
    _M_replace<char_const*>
              (this,local_2c + uVar2,local_28 + uVar2 + uVar3,param_4,param_4 + param_5,0);
    return;
  }
  _M_ibegin();
  _M_ibegin();
  _M_replace_safe<char_const*>
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
  _M_fold((ulong)&local_3c,param_1);
  uVar2 = *(uint *)param_1;
  _M_ibegin();
  uVar5 = *(uint *)(*(int *)param_1 + -0xc);
  uVar3 = local_40 - local_38;
  if (uVar5 < uVar3) {
    std____throw_out_of_range("basic_string::replace");
  }
  uVar4 = local_3c - local_40;
  if (uVar5 - uVar3 <= (uint)(local_3c - local_40)) {
    uVar4 = uVar5 - uVar3;
  }
  if (0x3ffffffc < uVar5 - uVar4) {
    std____throw_length_error("basic_string::replace");
  }
  uVar1 = *(uint *)param_1;
  if (((*(int *)(uVar1 - 4) < 1) && (uVar1 <= uVar2)) && (uVar2 <= uVar1 + uVar5)) {
    _M_ibegin();
    _M_ibegin();
    _M_replace<char_const*>
              ((unsigned char *)&local_3c,local_34 + uVar3,local_30 + uVar3 + uVar4,uVar2,uVar2,0);
    return;
  }
  _M_ibegin();
  _M_ibegin();
  _M_replace_safe<char_const*>
            ((unsigned char *)&local_3c,local_30 + uVar3,local_34 + uVar3 + uVar4,uVar2,uVar2);
  return;
}

/* std__string__resize @ 0x97c14420 (448 bytes) */
int std__string__resize(this, param_1, param_2)
  unsigned char *this;
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
    std____throw_length_error("basic_string::resize");
  }
  uVar1 = *(uint *)(*(int *)this + -0xc);
  if (uVar1 < param_1) {
    append(this,param_1 - uVar1,param_2);
  }
  else if (param_1 < uVar1) {
    std__string___M_check((ulong)&local_40);
    _M_fold((ulong)&local_3c,(ulong)this);
    uVar1 = *(uint *)this;
    _M_ibegin();
    uVar4 = *(uint *)(*(int *)this + -0xc);
    uVar3 = local_40 - local_38;
    if (uVar4 < uVar3) {
      std____throw_out_of_range("basic_string::replace");
    }
    uVar5 = local_3c - local_40;
    if (uVar4 - uVar3 <= (uint)(local_3c - local_40)) {
      uVar5 = uVar4 - uVar3;
    }
    if (0x3ffffffc < uVar4 - uVar5) {
      std____throw_length_error("basic_string::replace");
    }
    uVar2 = *(uint *)this;
    if (((*(int *)(uVar2 - 4) < 1) && (uVar2 <= uVar1)) && (uVar1 <= uVar2 + uVar4)) {
      _M_ibegin();
      _M_ibegin();
      _M_replace<char_const*>
                ((unsigned char *)&local_3c,local_34 + uVar3,local_30 + uVar3 + uVar5,uVar1,uVar1,0);
      return;
    }
    _M_ibegin();
    _M_ibegin();
    _M_replace_safe<char_const*>
              ((unsigned char *)&local_3c,local_30 + uVar3,local_34 + uVar3 + uVar5,uVar1,uVar1);
  }
  return;
}

/* std__string__resize_97c145e0 @ 0x97c145e0 (8 bytes) */
int std__string__resize_97c145e0(this, param_1)
  unsigned char *this;
  ulong param_1;
{
  resize(this,param_1,'\0');
  return;
}

/* std__string__reserve @ 0x97c145e8 (224 bytes) */
int std__string__reserve(this, param_1)
  unsigned char *this;
  ulong param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  allocator aaStack_20 [20];
  
  iVar5 = *(int *)this;
  if ((*(uint *)(iVar5 + -8) < param_1) || (0 < *(int *)(iVar5 + -4))) {
    if (0x3ffffffc < param_1) {
      std____throw_length_error("basic_string::reserve");
      iVar5 = *(int *)this;
    }
    if (param_1 < *(uint *)(iVar5 + -0xc)) {
      param_1 = *(uint *)(iVar5 + -0xc);
    }
    get_allocator();
    uVar4 = _Rep::_M_clone((unsigned char *)(*(int *)this + -0xc),aaStack_20,
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
      _Rep::_M_destroy((unsigned char *)(iVar5 + -0xc));
    }
    *(undefined4 *)this = uVar4;
  }
  return;
}

/* std__string__clear @ 0x97c146cc (20 bytes) */
int std__string__clear(this)
  unsigned char *this;
{
  _M_mutate(this,0,*(ulong *)(*(int *)this + -0xc),0);
  return;
}

/* std__string__empty @ 0x97c146e0 (20 bytes) */
int std__string__empty(this)
  unsigned char *this;
{
  return *(int *)(*(int *)this + -0xc) == 0;
}

/* std__string__operator__ @ 0x97c146f4 (12 bytes) */
int std__string__operator__(this, param_1)
  unsigned char *this;
  ulong param_1;
{
  return *(int *)this + param_1;
}

/* std__string__operator___97c14700 @ 0x97c14700 (56 bytes) */
int std__string__operator___97c14700(this, param_1)
  unsigned char *this;
  ulong param_1;
{
  _M_leak(this);
  return *(int *)this + param_1;
}

/* std__string__at @ 0x97c14738 (88 bytes) */
int std__string__at(this, param_1)
  unsigned char *this;
  ulong param_1;
{
  int iVar1;
  
  iVar1 = *(int *)this;
  if (*(uint *)(iVar1 + -0xc) <= param_1) {
    std____throw_out_of_range("basic_string::at");
    iVar1 = *(int *)this;
  }
  return iVar1 + param_1;
}

/* std__string__at_97c14790 @ 0x97c14790 (96 bytes) */
int std__string__at_97c14790(this, param_1)
  unsigned char *this;
  ulong param_1;
{
  if (*(uint *)(*(int *)this + -0xc) <= param_1) {
    std____throw_out_of_range("basic_string::at");
  }
  _M_leak(this);
  return *(int *)this + param_1;
}

/* std__string__operator___97c147f0 @ 0x97c147f0 (4 bytes) */
int std__string__operator___97c147f0(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  append(this,param_1);
  return;
}

/* std__string__append @ 0x97c147f4 (64 bytes) */
int std__string__append(this, param_1)
  unsigned char *this;
  char *param_1;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_1);
  append(this,param_1,sVar1);
  return;
}

/* std__string__operator___97c14834 @ 0x97c14834 (64 bytes) */
int std__string__operator___97c14834(this, param_1)
  unsigned char *this;
  char *param_1;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_1);
  append(this,param_1,sVar1);
  return;
}

/* std__string__operator___97c14874 @ 0x97c14874 (12 bytes) */
int std__string__operator___97c14874(this, param_1)
  unsigned char *this;
  int param_1;
{
  append(this,1,param_1);
  return;
}

/* std__string__append_97c14880 @ 0x97c14880 (164 bytes) */
int std__string__append_97c14880(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
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
  _M_iend();
  _M_iend();
  _M_ibegin();
  _M_iend();
  _M_replace_safe<__gnu_cxx::__normal_iterator<char*,std::string>>
            (this,local_30,local_2c,local_28,local_24);
  return;
}

/* std__string__append_97c14924 @ 0x97c14924 (216 bytes) */
int std__string__append_97c14924(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
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
  _M_iend();
  _M_iend();
  std__string___M_check((ulong)&local_38);
  _M_fold((ulong)&local_34,(ulong)param_1);
  _M_replace_safe<__gnu_cxx::__normal_iterator<char*,std::string>>
            ((unsigned char *)&local_34,local_40,local_3c,local_38,local_34);
  return;
}

/* std__string__append_97c149fc @ 0x97c149fc (132 bytes) */
int std__string__append_97c149fc(this, param_1, param_2)
  unsigned char *this;
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
  _M_iend();
  _M_iend();
  _M_replace_safe<char_const*>(this,local_30,local_2c,param_1,param_1 + param_2);
  return;
}

/* std__string__append_97c14a80 @ 0x97c14a80 (128 bytes) */
int std__string__append_97c14a80(this, param_1, param_2)
  unsigned char *this;
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
  _M_iend();
  _M_iend();
  replace(this,local_30,local_2c,param_1,CONCAT31(in_register_00000014,param_2));
  return;
}

/* std__string__push_back @ 0x97c14b00 (96 bytes) */
int std__string__push_back(this, param_1)
  unsigned char *this;
  int param_1;
{
  undefined3 in_register_00000010;
  undefined4 local_30;
  undefined4 local_2c;
  
  _M_iend();
  _M_iend();
  replace(this,local_30,local_2c,1,CONCAT31(in_register_00000010,param_1));
  return;
}

/* std__string__assign_97c14b60 @ 0x97c14b60 (180 bytes) */
int std__string__assign_97c14b60(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  allocator aaStack_40 [44];
  
  if (*(int *)this + -0xc != *(int *)param_1 + -0xc) {
    get_allocator();
    iVar5 = *(int *)param_1;
    get_allocator();
    uVar4 = _Rep::_M_grab((unsigned char *)(iVar5 + -0xc),aaStack_40);
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
      _Rep::_M_destroy((unsigned char *)(iVar5 + -0xc));
    }
    *(undefined4 *)this = uVar4;
  }
  return this;
}

/* std__string__assign_97c14c18 @ 0x97c14c18 (120 bytes) */
int std__string__assign_97c14c18(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
  ulong param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)param_1;
  uVar2 = *(uint *)(iVar1 + -0xc);
  if (uVar2 < param_2) {
    std____throw_out_of_range("basic_string::assign");
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
  unsigned char *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  replace(this,param_2,param_2,param_3,param_4);
  return;
}

/* std__string__insert_97c14ca0 @ 0x97c14ca0 (332 bytes) */
int std__string__insert_97c14ca0(this, param_1, param_2, param_3)
  unsigned char *this;
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
    std____throw_out_of_range("basic_string::insert");
  }
  if (0x3ffffffc - param_3 < uVar4) {
    std____throw_length_error("basic_string::insert");
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
    _M_ibegin();
    _M_ibegin();
    this = _M_replace_safe<char_const*>
                     (this,local_2c + param_1,local_30 + param_1,param_2,param_2 + param_3);
  }
  return this;
}

/* std__string__insert_97c14dec @ 0x97c14dec (388 bytes) */
int std__string__insert_97c14dec(this, param_1, param_2, param_3, param_4)
  unsigned char *this;
  ulong param_1;
  unsigned char *param_2;
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
    std____throw_out_of_range("basic_string::insert");
    iVar3 = *(int *)param_2;
  }
  uVar6 = uVar6 - param_3;
  if (uVar6 <= param_4) {
    param_4 = uVar6;
  }
  uVar6 = iVar3 + param_3;
  uVar7 = *(uint *)(*(int *)this + -0xc);
  if (uVar7 < param_1) {
    std____throw_out_of_range("basic_string::insert");
  }
  if (0x3ffffffc - param_4 < uVar7) {
    std____throw_length_error("basic_string::insert");
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
    _M_ibegin();
    _M_ibegin();
    this = _M_replace_safe<char_const*>
                     (this,local_2c + param_1,local_30 + param_1,uVar6,uVar6 + param_4);
  }
  return this;
}

/* std__string__insert_97c14f70 @ 0x97c14f70 (332 bytes) */
int std__string__insert_97c14f70(this, param_1, param_2)
  unsigned char *this;
  ulong param_1;
  unsigned char *param_2;
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
    std____throw_out_of_range("basic_string::insert");
  }
  if (0x3ffffffc - sVar3 < uVar7) {
    std____throw_length_error("basic_string::insert");
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
    _M_ibegin();
    _M_ibegin();
    this = _M_replace_safe<char_const*>
                     (this,local_2c + param_1,local_30 + param_1,uVar4,uVar4 + sVar3);
  }
  return this;
}

