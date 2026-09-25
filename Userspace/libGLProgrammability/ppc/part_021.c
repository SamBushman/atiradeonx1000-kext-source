#include "decls.h"

/* __ZNSs6rbeginEv @ 0x97c13f18 (60 bytes) */
int __ZNSs6rbeginEv(this, param_2)
  void *this;
  undefined4 param_2;
{
  undefined4 local_20 [5];
  
  __ZNSs3endEv(local_20,param_2);
  *(undefined4 *)((int)this + 4) = local_20[0];
  return this;
}

/* __ZNKSs6rbeginEv @ 0x97c13f54 (60 bytes) */
int __ZNKSs6rbeginEv(this, param_2)
  void *this;
  undefined4 param_2;
{
  undefined4 local_20 [5];
  
  __ZNKSs3endEv(local_20,param_2);
  *(undefined4 *)((int)this + 4) = local_20[0];
  return this;
}

/* __ZNSs4rendEv @ 0x97c13f90 (60 bytes) */
int __ZNSs4rendEv(this, param_2)
  void *this;
  undefined4 param_2;
{
  undefined4 local_20 [5];
  
  __ZNSs5beginEv(local_20,param_2);
  *(undefined4 *)((int)this + 4) = local_20[0];
  return this;
}

/* __ZNKSs4rendEv @ 0x97c13fcc (60 bytes) */
int __ZNKSs4rendEv(this, param_2)
  void *this;
  undefined4 param_2;
{
  undefined4 local_20 [5];
  
  __ZNKSs5beginEv(local_20,param_2);
  *(undefined4 *)((int)this + 4) = local_20[0];
  return this;
}

/* __ZNKSs6lengthEv @ 0x97c14008 (12 bytes) */
int __ZNKSs6lengthEv(this)
  void *this;
{
  return *(undefined4 *)(*(int *)this + -0xc);
}

/* __ZNSs7replaceEmmPKcm @ 0x97c14014 (316 bytes) */
int __ZNSs7replaceEmmPKcm(this, param_2, param_3, param_4, param_5)
  void *this;
  ulong param_2;
  ulong param_3;
  char *param_4;
  ulong param_5;
{
  char *pcVar1;
  uint uVar2;
  int local_30;
  int local_2c [4];
  
  uVar2 = *(uint *)(*(int *)this + -0xc);
  if (uVar2 < param_2) {
    std____throw_out_of_range("basic_string::replace");
  }
  if (uVar2 - param_2 <= param_3) {
    param_3 = uVar2 - param_2;
  }
  if (0x3ffffffc - param_5 < uVar2 - param_3) {
    std____throw_length_error("basic_string::replace");
  }
  pcVar1 = *(char **)this;
  if (((*(int *)(pcVar1 + -4) < 1) && (pcVar1 <= param_4)) && (param_4 <= pcVar1 + uVar2)) {
    __ZNKSs9_M_ibeginEv(local_2c,this);
    __ZNKSs9_M_ibeginEv(&local_30,this);
    __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
              (this,local_30 + param_2,(char *)(local_2c[0] + param_2 + param_3),param_4,
               param_4 + param_5);
  }
  else {
    __ZNKSs9_M_ibeginEv(&local_30,this);
    __ZNKSs9_M_ibeginEv(local_2c,this);
    __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
              (this,local_2c[0] + param_2,local_30 + param_2 + param_3,param_4,param_4 + param_5);
  }
  return;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S1_S1_ @ 0x97c14150 (344 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S1_S1_(this, param_2, param_3, param_4, param_5)
  void *this;
  int param_2;
  int param_3;
  char *param_4;
  int param_5;
{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int local_30;
  int local_2c;
  int local_28 [2];
  
  __ZNKSs9_M_ibeginEv(&local_30,this);
  iVar4 = param_5 - (int)param_4;
  uVar5 = *(uint *)(*(int *)this + -0xc);
  uVar2 = param_2 - local_30;
  if (uVar5 < uVar2) {
    std____throw_out_of_range("basic_string::replace");
  }
  uVar3 = param_3 - param_2;
  if (uVar5 - uVar2 <= (uint)(param_3 - param_2)) {
    uVar3 = uVar5 - uVar2;
  }
  if (0x3ffffffcU - iVar4 < uVar5 - uVar3) {
    std____throw_length_error("basic_string::replace");
  }
  pcVar1 = *(char **)this;
  if (((*(int *)(pcVar1 + -4) < 1) && (pcVar1 <= param_4)) && (param_4 <= pcVar1 + uVar5)) {
    __ZNKSs9_M_ibeginEv(local_28,this);
    __ZNKSs9_M_ibeginEv(&local_2c,this);
    __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
              (this,local_2c + uVar2,(char *)(local_28[0] + uVar2 + uVar3),param_4,param_4 + iVar4);
  }
  else {
    __ZNKSs9_M_ibeginEv(&local_2c,this);
    __ZNKSs9_M_ibeginEv(local_28,this);
    __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
              (this,local_28[0] + uVar2,local_2c + uVar2 + uVar3,param_4,param_4 + iVar4);
  }
  return;
}

/* __ZNSs5eraseEmm @ 0x97c142a8 (376 bytes) */
int __ZNSs5eraseEmm(param_1, param_2, param_3)
  ulong param_1;
  ulong param_2;
  undefined4 param_3;
{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30 [5];
  
  std__string___M_check((ulong)&local_40,param_1,param_2);
  __ZNKSs7_M_foldEmm((ulong)&local_3c,param_1,param_2,param_3);
  pcVar2 = *(char **)param_1;
  __ZNKSs9_M_ibeginEv(&local_38,param_1);
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
  pcVar1 = *(char **)param_1;
  if (((*(int *)(pcVar1 + -4) < 1) && (pcVar1 <= pcVar2)) && (pcVar2 <= pcVar1 + uVar5)) {
    __ZNKSs9_M_ibeginEv(local_30,param_1);
    __ZNKSs9_M_ibeginEv(&local_34,param_1);
    __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
              (param_1,local_34 + uVar3,(char *)(local_30[0] + uVar3 + uVar4),pcVar2,pcVar2);
  }
  else {
    __ZNKSs9_M_ibeginEv(&local_34,param_1);
    __ZNKSs9_M_ibeginEv(local_30,param_1);
    __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
              ((void *)param_1,local_30[0] + uVar3,local_34 + uVar3 + uVar4,pcVar2,pcVar2);
  }
  return;
}

/* __ZNSs6resizeEmc @ 0x97c14420 (448 bytes) */
int __ZNSs6resizeEmc(this, param_2, param_3)
  void *this;
  ulong param_2;
  int param_3;
{
  uint uVar1;
  char *pcVar2;
  undefined3 in_register_00000014;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30 [5];
  
  if (0x3ffffffc < param_2) {
    std____throw_length_error("basic_string::resize");
  }
  uVar1 = *(uint *)(*(int *)this + -0xc);
  if (uVar1 < param_2) {
    ((int (*)())__ZNSs6appendEmc)(this,param_2 - uVar1,CONCAT31(in_register_00000014,param_3));
  }
  else if (param_2 < uVar1) {
    std__string___M_check((ulong)&local_40,this,param_2);
    __ZNKSs7_M_foldEmm((ulong)&local_3c,(ulong)this,param_2,0xffffffff);
    pcVar3 = *(char **)this;
    __ZNKSs9_M_ibeginEv(&local_38,this);
    uVar4 = *(uint *)(*(int *)this + -0xc);
    uVar1 = local_40 - local_38;
    if (uVar4 < uVar1) {
      std____throw_out_of_range("basic_string::replace");
    }
    uVar5 = local_3c - local_40;
    if (uVar4 - uVar1 <= (uint)(local_3c - local_40)) {
      uVar5 = uVar4 - uVar1;
    }
    if (0x3ffffffc < uVar4 - uVar5) {
      std____throw_length_error("basic_string::replace");
    }
    pcVar2 = *(char **)this;
    if (((*(int *)(pcVar2 + -4) < 1) && (pcVar2 <= pcVar3)) && (pcVar3 <= pcVar2 + uVar4)) {
      __ZNKSs9_M_ibeginEv(local_30,this);
      __ZNKSs9_M_ibeginEv(&local_34,this);
      __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
                (this,local_34 + uVar1,(char *)(local_30[0] + uVar1 + uVar5),pcVar3,pcVar3);
    }
    else {
      __ZNKSs9_M_ibeginEv(&local_34,this);
      __ZNKSs9_M_ibeginEv(local_30,this);
      __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                (this,local_30[0] + uVar1,local_34 + uVar1 + uVar5,pcVar3,pcVar3);
    }
  }
  return;
}

/* __ZNSs6resizeEm @ 0x97c145e0 (8 bytes) */
int __ZNSs6resizeEm(this, param_2)
  void *this;
  ulong param_2;
{
  ((int (*)())__ZNSs6resizeEmc)(this,param_2,'\0');
  return;
}

/* __ZNSs7reserveEm @ 0x97c145e8 (204 bytes) */
int __ZNSs7reserveEm(this, param_2)
  void *this;
  ulong param_2;
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
  if ((*(uint *)(iVar5 + -8) < param_2) || (0 < *(int *)(iVar5 + -4))) {
    if (0x3ffffffc < param_2) {
      std____throw_length_error("basic_string::reserve");
      iVar5 = *(int *)this;
    }
    if (param_2 < *(uint *)(iVar5 + -0xc)) {
      param_2 = *(uint *)(iVar5 + -0xc);
    }
    __ZNKSs13get_allocatorEv();
    uVar4 = __ZNSs4_Rep8_M_cloneERKSaIcEm
                      ((void *)(*(int *)this + -0xc),aaStack_20,
                       param_2 - *(int *)(*(int *)this + -0xc));
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
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(iVar5 + -0xc));
    }
    *(undefined4 *)this = uVar4;
  }
  return;
}

/* __ZNSs5clearEv @ 0x97c146cc (20 bytes) */
int __ZNSs5clearEv(this)
  void *this;
{
  __ZNSs9_M_mutateEmmm(this,0,*(ulong *)(*(int *)this + -0xc),0);
  return;
}

/* __ZNKSs5emptyEv @ 0x97c146e0 (20 bytes) */
int __ZNKSs5emptyEv(this)
  void *this;
{
  return *(int *)(*(int *)this + -0xc) == 0;
}

/* __ZNKSsixEm @ 0x97c146f4 (12 bytes) */
int __ZNKSsixEm(this, param_2)
  void *this;
  ulong param_2;
{
  return *(int *)this + param_2;
}

/* __ZNSsixEm @ 0x97c14700 (56 bytes) */
int __ZNSsixEm(this, param_2)
  void *this;
  ulong param_2;
{
  __ZNSs7_M_leakEv(this);
  return *(int *)this + param_2;
}

/* __ZNKSs2atEm @ 0x97c14738 (88 bytes) */
int __ZNKSs2atEm(this, param_2)
  void *this;
  ulong param_2;
{
  int iVar1;
  
  iVar1 = *(int *)this;
  if (*(uint *)(iVar1 + -0xc) <= param_2) {
    std____throw_out_of_range("basic_string::at");
    iVar1 = *(int *)this;
  }
  return iVar1 + param_2;
}

/* __ZNSs2atEm @ 0x97c14790 (96 bytes) */
int __ZNSs2atEm(this, param_2)
  void *this;
  ulong param_2;
{
  if (*(uint *)(*(int *)this + -0xc) <= param_2) {
    std____throw_out_of_range("basic_string::at");
  }
  __ZNSs7_M_leakEv(this);
  return *(int *)this + param_2;
}

/* __ZNSspLERKSs @ 0x97c147f0 (4 bytes) */
int __ZNSspLERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ((int (*)())__ZNSs6appendERKSs)(this,param_2);
  return;
}

/* __ZNSs6appendEPKc @ 0x97c147f4 (64 bytes) */
int __ZNSs6appendEPKc(this, param_2)
  void *this;
  char *param_2;
{
  ulong uVar1;
  
  uVar1 = _strlen(param_2);
  ((int (*)())__ZNSs6appendEPKcm)(this,param_2,uVar1);
  return;
}

/* __ZNSspLEPKc @ 0x97c14834 (64 bytes) */
int __ZNSspLEPKc(this, param_2)
  void *this;
  char *param_2;
{
  ulong uVar1;
  
  uVar1 = _strlen(param_2);
  ((int (*)())__ZNSs6appendEPKcm)(this,param_2,uVar1);
  return;
}

/* __ZNSspLEc @ 0x97c14874 (12 bytes) */
int __ZNSspLEc(this, param_2)
  void *this;
  int param_2;
{
  undefined3 in_register_00000010;
  
  ((int (*)())__ZNSs6appendEmc)(this,1,CONCAT31(in_register_00000010,param_2));
  return;
}

/* __ZNSs6appendERKSs @ 0x97c14880 (164 bytes) */
int __ZNSs6appendERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ulong uVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24 [4];
  
  uVar1 = *(int *)(*(int *)param_2 + -0xc) + *(int *)(*(int *)this + -0xc);
  if (*(uint *)(*(int *)this + -8) < uVar1) {
    ((int (*)())__ZNSs7reserveEm)(this,uVar1);
  }
  __ZNKSs7_M_iendEv(&local_30,this);
  __ZNKSs7_M_iendEv(&local_2c,this);
  __ZNKSs9_M_ibeginEv(&local_28,param_2);
  __ZNKSs7_M_iendEv(local_24,param_2);
  __ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_
            (this,local_30,local_2c,local_28,local_24[0]);
  return;
}

/* __ZNSs6appendERKSsmm @ 0x97c14924 (216 bytes) */
int __ZNSs6appendERKSsmm(this, param_2, param_3, param_4)
  void *this;
  unsigned char * param_2;
  ulong param_3;
  ulong param_4;
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
  local_30[0] = *(int *)(*(int *)param_2 + -0xc) - param_3;
  if (local_30[0] <= param_4) {
    puVar2 = local_30;
  }
  uVar1 = *puVar2 + *(int *)(*(int *)this + -0xc);
  uStack00000024 = param_4;
  if (*(uint *)(*(int *)this + -8) < uVar1) {
    ((int (*)())__ZNSs7reserveEm)(this,uVar1);
  }
  __ZNKSs7_M_iendEv(&local_40,this);
  __ZNKSs7_M_iendEv(&local_3c,this);
  std__string___M_check((ulong)&local_38,param_2,param_3);
  __ZNKSs7_M_foldEmm((ulong)&local_34,(ulong)param_2,param_3,uStack00000024);
  __ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_
            (this,local_40,local_3c,local_38,local_34);
  return;
}

/* __ZNSs6appendEPKcm @ 0x97c149fc (132 bytes) */
int __ZNSs6appendEPKcm(this, param_2, param_3)
  void *this;
  char *param_2;
  ulong param_3;
{
  ulong uVar1;
  undefined4 local_30;
  undefined4 local_2c [6];
  
  uVar1 = param_3 + *(int *)(*(int *)this + -0xc);
  if (*(uint *)(*(int *)this + -8) < uVar1) {
    ((int (*)())__ZNSs7reserveEm)(this,uVar1);
  }
  __ZNKSs7_M_iendEv(&local_30,this);
  __ZNKSs7_M_iendEv(local_2c,this);
  __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
            (this,local_30,local_2c[0],param_2,param_2 + param_3);
  return;
}

/* __ZNSs6appendEmc @ 0x97c14a80 (128 bytes) */
int __ZNSs6appendEmc(this, param_2, param_3)
  void *this;
  ulong param_2;
  undefined4 param_3;
{
  ulong uVar1;
  undefined4 local_30;
  undefined4 local_2c [6];
  
  uVar1 = param_2 + *(int *)(*(int *)this + -0xc);
  if (*(uint *)(*(int *)this + -8) < uVar1) {
    ((int (*)())__ZNSs7reserveEm)(this,uVar1);
  }
  __ZNKSs7_M_iendEv(&local_30,this);
  __ZNKSs7_M_iendEv(local_2c,this);
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,local_30,local_2c[0],param_2,param_3);
  return;
}

/* std__string__push_back @ 0x97c14b00 (96 bytes) */
int std__string__push_back(this, param_2)
  unsigned char * this;
  undefined4 param_2;
{
  undefined4 local_30;
  undefined4 local_2c [6];
  
  __ZNKSs7_M_iendEv(&local_30,this);
  __ZNKSs7_M_iendEv(local_2c,this);
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,local_30,local_2c[0],1,param_2);
  return;
}

/* __ZNSs6assignERKSs @ 0x97c14b60 (104 bytes) */
int __ZNSs6assignERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  unsigned char aaStack_40 [44];
  
  if (*(int *)this + -0xc != *(int *)param_2 + -0xc) {
    __ZNKSs13get_allocatorEv();
    iVar5 = *(int *)param_2;
    __ZNKSs13get_allocatorEv();
    uVar4 = __ZNSs4_Rep7_M_grabERKSaIcES2_((unsigned char *)(iVar5 + -0xc),aaStack_40);
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
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(iVar5 + -0xc));
    }
    *(undefined4 *)this = uVar4;
  }
  return this;
}

/* __ZNSs6assignERKSsmm @ 0x97c14c18 (120 bytes) */
int __ZNSs6assignERKSsmm(this, param_2, param_3, param_4)
  void *this;
  unsigned char * param_2;
  ulong param_3;
  ulong param_4;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)param_2;
  uVar2 = *(uint *)(iVar1 + -0xc);
  if (uVar2 < param_3) {
    std____throw_out_of_range("basic_string::assign");
    iVar1 = *(int *)param_2;
  }
  uVar2 = uVar2 - param_3;
  if (uVar2 <= param_4) {
    param_4 = uVar2;
  }
  __ZNSs6assignEPKcm(this,(char *)(iVar1 + param_3),param_4);
  return;
}

/* __ZNSs6insertEN9__gnu_cxx17__normal_iteratorIPcSsEEmc @ 0x97c14c90 (16 bytes) */
int __ZNSs6insertEN9__gnu_cxx17__normal_iteratorIPcSsEEmc(this, param_2, param_3, param_4)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,param_2,param_2,param_3,param_4);
  return;
}

/* __ZNSs6insertEmPKcm @ 0x97c14ca0 (332 bytes) */
int __ZNSs6insertEmPKcm(this, param_2, param_3, param_4)
  void *this;
  ulong param_2;
  char *param_3;
  ulong param_4;
{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int local_30;
  int local_2c [4];
  
  uVar4 = *(uint *)(*(int *)this + -0xc);
  if (uVar4 < param_2) {
    std____throw_out_of_range("basic_string::insert");
  }
  if (0x3ffffffc - param_4 < uVar4) {
    std____throw_length_error("basic_string::insert");
  }
  pcVar2 = *(char **)this;
  if (((*(int *)(pcVar2 + -4) < 1) && (pcVar2 <= param_3)) && (param_3 <= pcVar2 + uVar4)) {
    __ZNSs9_M_mutateEmmm(this,param_2,0,param_4);
    pcVar1 = param_3 + (*(int *)this - (int)pcVar2);
    pcVar5 = (char *)(*(int *)this + param_2);
    pcVar2 = pcVar1;
    if ((pcVar5 < pcVar1 + param_4) && (pcVar2 = pcVar1 + param_4, pcVar1 < pcVar5)) {
      iVar3 = (int)pcVar5 - (int)pcVar1;
      _memcpy(pcVar5,pcVar1,iVar3);
      pcVar2 = pcVar5 + param_4;
      pcVar5 = pcVar5 + iVar3;
      param_4 = param_4 - iVar3;
    }
    _memcpy(pcVar5,pcVar2,param_4);
  }
  else {
    __ZNKSs9_M_ibeginEv(&local_30,this);
    __ZNKSs9_M_ibeginEv(local_2c,this);
    this = __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                     (this,local_2c[0] + param_2,local_30 + param_2,param_3,param_3 + param_4);
  }
  return this;
}

/* __ZNSs6insertEmRKSsmm @ 0x97c14dec (388 bytes) */
int __ZNSs6insertEmRKSsmm(this, param_2, param_3, param_4, param_5)
  void *this;
  ulong param_2;
  unsigned char * param_3;
  ulong param_4;
  ulong param_5;
{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  int local_30;
  int local_2c [3];
  
  iVar2 = *(int *)param_3;
  uVar4 = *(uint *)(iVar2 + -0xc);
  if (uVar4 < param_4) {
    std____throw_out_of_range("basic_string::insert");
    iVar2 = *(int *)param_3;
  }
  uVar4 = uVar4 - param_4;
  if (uVar4 <= param_5) {
    param_5 = uVar4;
  }
  pcVar1 = (char *)(iVar2 + param_4);
  uVar4 = *(uint *)(*(int *)this + -0xc);
  if (uVar4 < param_2) {
    std____throw_out_of_range("basic_string::insert");
  }
  if (0x3ffffffc - param_5 < uVar4) {
    std____throw_length_error("basic_string::insert");
  }
  pcVar3 = *(char **)this;
  if (((*(int *)(pcVar3 + -4) < 1) && (pcVar3 <= pcVar1)) && (pcVar1 <= pcVar3 + uVar4)) {
    __ZNSs9_M_mutateEmmm(this,param_2,0,param_5);
    pcVar1 = pcVar1 + (*(int *)this - (int)pcVar3);
    pcVar5 = (char *)(*(int *)this + param_2);
    pcVar3 = pcVar1;
    if ((pcVar5 < pcVar1 + param_5) && (pcVar3 = pcVar1 + param_5, pcVar1 < pcVar5)) {
      iVar2 = (int)pcVar5 - (int)pcVar1;
      _memcpy(pcVar5,pcVar1,iVar2);
      pcVar3 = pcVar5 + param_5;
      pcVar5 = pcVar5 + iVar2;
      param_5 = param_5 - iVar2;
    }
    _memcpy(pcVar5,pcVar3,param_5);
  }
  else {
    __ZNKSs9_M_ibeginEv(&local_30,this);
    __ZNKSs9_M_ibeginEv(local_2c,this);
    this = __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                     (this,local_2c[0] + param_2,local_30 + param_2,pcVar1,pcVar1 + param_5);
  }
  return this;
}

/* __ZNSs6insertEmRKSs @ 0x97c14f70 (332 bytes) */
int __ZNSs6insertEmRKSs(this, param_2, param_3)
  void *this;
  ulong param_2;
  unsigned char * param_3;
{
  ulong uVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  int local_30;
  int local_2c [4];
  
  pcVar2 = *(char **)param_3;
  uVar5 = *(uint *)(*(int *)this + -0xc);
  uVar1 = *(ulong *)(pcVar2 + -0xc);
  if (uVar5 < param_2) {
    std____throw_out_of_range("basic_string::insert");
  }
  if (0x3ffffffc - uVar1 < uVar5) {
    std____throw_length_error("basic_string::insert");
  }
  pcVar3 = *(char **)this;
  if (((*(int *)(pcVar3 + -4) < 1) && (pcVar3 <= pcVar2)) && (pcVar2 <= pcVar3 + uVar5)) {
    __ZNSs9_M_mutateEmmm(this,param_2,0,uVar1);
    pcVar2 = pcVar2 + (*(int *)this - (int)pcVar3);
    pcVar6 = (char *)(*(int *)this + param_2);
    pcVar3 = pcVar2;
    if ((pcVar6 < pcVar2 + uVar1) && (pcVar3 = pcVar2 + uVar1, pcVar2 < pcVar6)) {
      iVar4 = (int)pcVar6 - (int)pcVar2;
      _memcpy(pcVar6,pcVar2,iVar4);
      pcVar3 = pcVar6 + uVar1;
      pcVar6 = pcVar6 + iVar4;
      uVar1 = uVar1 - iVar4;
    }
    _memcpy(pcVar6,pcVar3,uVar1);
  }
  else {
    __ZNKSs9_M_ibeginEv(&local_30,this);
    __ZNKSs9_M_ibeginEv(local_2c,this);
    this = __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                     (this,local_2c[0] + param_2,local_30 + param_2,pcVar2,pcVar2 + uVar1);
  }
  return this;
}

/* __ZNSs6insertEmPKc @ 0x97c150bc (72 bytes) */
int __ZNSs6insertEmPKc(this, param_2, param_3)
  void *this;
  ulong param_2;
  char *param_3;
{
  ulong uVar1;
  
  uVar1 = _strlen(param_3);
  ((int (*)())__ZNSs6insertEmPKcm)(this,param_2,param_3,uVar1);
  return;
}

/* __ZNSs6insertEmmc @ 0x97c15104 (92 bytes) */
int __ZNSs6insertEmmc(this, param_2, param_3, param_4)
  void *this;
  ulong param_2;
  ulong param_3;
  undefined4 param_4;
{
  undefined4 local_30 [7];
  
  std__string___M_check((ulong)local_30,this,param_2);
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,local_30[0],local_30[0],param_3,param_4);
  return this;
}

/* __ZNSs6insertEN9__gnu_cxx17__normal_iteratorIPcSsEEc @ 0x97c15160 (148 bytes) */
int __ZNSs6insertEN9__gnu_cxx17__normal_iteratorIPcSsEEc(param_1, param_2, param_3, param_4)
  int *param_1;
  int *param_2;
  int param_3;
  undefined4 param_4;
{
  int iVar1;
  int local_30 [6];
  
  __ZNKSs9_M_ibeginEv(local_30,param_2);
  iVar1 = param_3 - local_30[0];
  std__string___M_check((ulong)local_30,param_2,iVar1);
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(param_2,local_30[0],local_30[0],1,param_4);
  *(undefined4 *)(*param_2 + -4) = 0xffffffff;
  __ZNKSs9_M_ibeginEv(local_30,param_2);
  *param_1 = local_30[0] + iVar1;
  return param_1;
}

/* __ZNSs5eraseEN9__gnu_cxx17__normal_iteratorIPcSsEE @ 0x97c151f4 (128 bytes) */
int __ZNSs5eraseEN9__gnu_cxx17__normal_iteratorIPcSsEE(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int local_30 [7];
  
  __ZNKSs9_M_ibeginEv(local_30,param_2);
  iVar1 = param_3 - local_30[0];
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S1_S1_)(param_2,param_3,param_3 + 1,*param_2,*param_2);
  *(undefined4 *)(*param_2 + -4) = 0xffffffff;
  __ZNKSs9_M_ibeginEv(local_30,param_2);
  *param_1 = local_30[0] + iVar1;
  return param_1;
}

/* __ZNSs5eraseEN9__gnu_cxx17__normal_iteratorIPcSsEES2_ @ 0x97c15274 (132 bytes) */
int __ZNSs5eraseEN9__gnu_cxx17__normal_iteratorIPcSsEES2_(param_1, param_2, param_3, param_4)
  int *param_1;
  int *param_2;
  int param_3;
  undefined4 param_4;
{
  int iVar1;
  int local_30 [6];
  
  __ZNKSs9_M_ibeginEv(local_30,param_2);
  iVar1 = param_3 - local_30[0];
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S1_S1_)(param_2,param_3,param_4,*param_2,*param_2);
  *(undefined4 *)(*param_2 + -4) = 0xffffffff;
  __ZNKSs9_M_ibeginEv(local_30,param_2);
  *param_1 = local_30[0] + iVar1;
  return param_1;
}

/* __ZNSs7replaceEmmRKSs @ 0x97c152f8 (12 bytes) */
int __ZNSs7replaceEmmRKSs(this, param_2, param_3, param_4)
  void *this;
  ulong param_2;
  ulong param_3;
  unsigned char * param_4;
{
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,param_2,param_3,*(char **)param_4,*(ulong *)(*(char **)param_4 + -0xc))
  ;
  return;
}

/* __ZNSs7replaceEmmRKSsmm @ 0x97c15304 (136 bytes) */
int __ZNSs7replaceEmmRKSsmm(this, param_2, param_3, param_4, param_5, param_6)
  void *this;
  ulong param_2;
  ulong param_3;
  unsigned char * param_4;
  ulong param_5;
  ulong param_6;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)param_4;
  uVar2 = *(uint *)(iVar1 + -0xc);
  if (uVar2 < param_5) {
    std____throw_out_of_range("basic_string::replace");
    iVar1 = *(int *)param_4;
  }
  uVar2 = uVar2 - param_5;
  if (uVar2 <= param_6) {
    param_6 = uVar2;
  }
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,param_2,param_3,(char *)(iVar1 + param_5),param_6);
  return;
}

/* __ZNSs7replaceEmmPKc @ 0x97c1538c (80 bytes) */
int __ZNSs7replaceEmmPKc(this, param_2, param_3, param_4)
  void *this;
  ulong param_2;
  ulong param_3;
  char *param_4;
{
  ulong uVar1;
  
  uVar1 = _strlen(param_4);
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,param_2,param_3,param_4,uVar1);
  return;
}

/* __ZNSs7replaceEmmmc @ 0x97c153dc (120 bytes) */
int __ZNSs7replaceEmmmc(this, param_2, param_3, param_4, param_5)
  void *this;
  ulong param_2;
  ulong param_3;
  ulong param_4;
  undefined4 param_5;
{
  undefined4 local_30;
  undefined4 local_2c [4];
  
  std__string___M_check((ulong)&local_30,this,param_2);
  __ZNKSs7_M_foldEmm((ulong)local_2c,(ulong)this,param_2,param_3);
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,local_30,local_2c[0],param_4,param_5);
  return;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcm @ 0x97c15454 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcm(this, param_2, param_3, param_4, param_5)
  void *this;
  int param_2;
  int param_3;
  char *param_4;
  ulong param_5;
{
  int local_30 [5];
  
  __ZNKSs9_M_ibeginEv(local_30,this);
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,param_2 - local_30[0],param_3 - param_2,param_4,param_5);
  return;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_RKSs @ 0x97c154b4 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_RKSs(this, param_2, param_3, param_4)
  void *this;
  int param_2;
  int param_3;
  undefined4 *param_4;
{
  char *pcVar1;
  ulong uVar2;
  int local_30 [5];
  
  pcVar1 = (char *)*param_4;
  uVar2 = *(ulong *)(pcVar1 + -0xc);
  __ZNKSs9_M_ibeginEv(local_30,this);
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,param_2 - local_30[0],param_3 - param_2,pcVar1,uVar2);
  return;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKc @ 0x97c15514 (80 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKc(this, param_2, param_3, param_4)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  uVar1 = _strlen(param_4);
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcm)(this,param_2,param_3,param_4,uVar1);
  return;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc @ 0x97c15564 (180 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc(this, param_2, param_3, param_4, param_5)
  void *this;
  int param_2;
  int param_3;
  uint param_4;
  undefined4 param_5;
{
  int local_30 [6];
  
  __ZNKSs9_M_ibeginEv(local_30,this);
  if (0x3ffffffcU - (*(int *)(*(int *)this + -0xc) - (param_3 - param_2)) <= param_4) {
    std____throw_length_error("basic_string::replace");
  }
  __ZNSs9_M_mutateEmmm(this,param_2 - local_30[0],param_3 - param_2,param_4);
  if (param_4 != 0) {
    _memset(*(int *)this + (param_2 - local_30[0]),param_5,param_4);
  }
  return this;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcS4_ @ 0x97c15618 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcS4_(this, param_2, param_3, param_4, param_5)
  void *this;
  int param_2;
  int param_3;
  char *param_4;
  int param_5;
{
  int local_30 [5];
  
  __ZNKSs9_M_ibeginEv(local_30,this);
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,param_2 - local_30[0],param_3 - param_2,param_4,param_5 - (int)param_4)
  ;
  return;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S2_S2_ @ 0x97c15678 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S2_S2_(this, param_2, param_3, param_4, param_5)
  void *this;
  int param_2;
  int param_3;
  char *param_4;
  int param_5;
{
  int local_30 [5];
  
  __ZNKSs9_M_ibeginEv(local_30,this);
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,param_2 - local_30[0],param_3 - param_2,param_4,param_5 - (int)param_4)
  ;
  return;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_NS0_IPKcSsEES5_ @ 0x97c156d8 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_NS0_IPKcSsEES5_(this, param_2, param_3, param_4, param_5)
  void *this;
  int param_2;
  int param_3;
  char *param_4;
  int param_5;
{
  int local_30 [5];
  
  __ZNKSs9_M_ibeginEv(local_30,this);
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,param_2 - local_30[0],param_3 - param_2,param_4,param_5 - (int)param_4)
  ;
  return;
}

/* std__string___S_construct @ 0x97c15738 (140 bytes) */
int std__string___S_construct(param_1, param_2, param_3)
  ulong param_1;
  undefined4 param_2;
  unsigned char * param_3;
{
  ulong *puVar1;
  ulong *puVar2;
  char in_RESERVE;
  
  if (param_1 == 0) {
    if (in_RESERVE != '\0') {
      DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
    }
    puVar1 = (ulong *)&DAT_a7b7bf90;
  }
  else {
    puVar2 = (ulong *)__ZNSs4_Rep9_S_createEmRKSaIcE(param_1,param_3);
    puVar1 = puVar2 + 3;
    _memset(puVar1,param_2,param_1);
    *puVar2 = param_1;
    *(undefined1 *)((int)puVar1 + param_1) = 0;
  }
  return puVar1;
}

/* std__string__copy @ 0x97c157c4 (132 bytes) */
int std__string__copy(this, param_2, param_3, param_4)
  unsigned char * this;
  char *param_2;
  ulong param_3;
  ulong param_4;
{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)this;
  if (*(uint *)(iVar2 + -0xc) < param_4) {
    std____throw_out_of_range("basic_string::copy");
    iVar2 = *(int *)this;
  }
  uVar1 = *(int *)(iVar2 + -0xc) - param_4;
  if (uVar1 < param_3) {
    param_3 = uVar1;
  }
  _memcpy(param_2,iVar2 + param_4,param_3);
  return param_3;
}

/* __ZNSs4swapERSs @ 0x97c15848 (140 bytes) */
int __ZNSs4swapERSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  undefined4 uVar1;
  
  if (*(int *)(*(int *)this + -4) < 0) {
    *(undefined4 *)(*(int *)this + -4) = 0;
  }
  if (*(int *)(*(int *)param_2 + -4) < 0) {
    *(undefined4 *)(*(int *)param_2 + -4) = 0;
  }
  __ZNKSs13get_allocatorEv();
  __ZNKSs13get_allocatorEv();
  uVar1 = *(undefined4 *)this;
  *(undefined4 *)this = *(undefined4 *)param_2;
  *(undefined4 *)param_2 = uVar1;
  return;
}

/* __ZNKSs5c_strEv @ 0x97c158d4 (48 bytes) */
int __ZNKSs5c_strEv(this)
  void *this;
{
  *(undefined1 *)(*(int *)this + *(int *)(*(int *)this + -0xc)) = std__string___Rep___S_terminal;
  return *(undefined4 *)this;
}

/* __ZNKSs4dataEv @ 0x97c15904 (8 bytes) */
int __ZNKSs4dataEv(this)
  void *this;
{
  return *(undefined4 *)this;
}

/* __ZNKSs4findEPKcmm @ 0x97c1590c (128 bytes) */
int __ZNKSs4findEPKcmm(this, param_2, param_3, param_4)
  void *this;
  char *param_2;
  ulong param_3;
  ulong param_4;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = param_3 + param_4;
  uVar3 = *(uint *)(*(int *)this + -0xc);
  if (uVar1 <= uVar3) {
    iVar4 = param_3 + *(int *)this;
    do {
      iVar2 = _memcmp(iVar4,param_2,param_4);
      if (iVar2 == 0) {
        return param_3;
      }
      uVar1 = uVar1 + 1;
      param_3 = param_3 + 1;
      iVar4 = iVar4 + 1;
    } while (uVar1 <= uVar3);
  }
  return 0xffffffff;
}

/* __ZNKSs4findERKSsm @ 0x97c1598c (12 bytes) */
int __ZNKSs4findERKSsm(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  ulong param_3;
{
  ((int (*)())__ZNKSs4findEPKcmm)(this,*(char **)param_2,param_3,*(ulong *)(*(char **)param_2 + -0xc));
  return;
}

/* __ZNKSs4findEPKcm @ 0x97c15998 (72 bytes) */
int __ZNKSs4findEPKcm(this, param_2, param_3)
  void *this;
  char *param_2;
  ulong param_3;
{
  ulong uVar1;
  
  uVar1 = _strlen(param_2);
  ((int (*)())__ZNKSs4findEPKcmm)(this,param_2,param_3,uVar1);
  return;
}

/* __ZNKSs4findEcm @ 0x97c159e0 (96 bytes) */
int __ZNKSs4findEcm(this, param_2, param_3)
  void *this;
  int param_2;
  ulong param_3;
{
  void *pvVar1;
  int iVar2;
  int iVar3;
  char cStack0000001c;
  
  iVar2 = -1;
  iVar3 = *(int *)this;
  if ((param_3 < *(uint *)(iVar3 + -0xc)) &&
     (cStack0000001c = param_2,
     pvVar1 = _memchr((void *)(iVar3 + param_3),(int)param_2,*(uint *)(iVar3 + -0xc) - param_3),
     pvVar1 != (void *)0x0)) {
    iVar2 = (int)pvVar1 - iVar3;
  }
  return iVar2;
}

/* __ZNKSs5rfindERKSsm @ 0x97c15a40 (12 bytes) */
int __ZNKSs5rfindERKSsm(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  ulong param_3;
{
  ((int (*)())__ZNKSs5rfindEPKcmm)(this,*(char **)param_2,param_3,*(ulong *)(*(char **)param_2 + -0xc));
  return;
}

/* __ZNKSs5rfindEPKcmm @ 0x97c15a4c (148 bytes) */
int __ZNKSs5rfindEPKcmm(this, param_2, param_3, param_4)
  void *this;
  char *param_2;
  ulong param_3;
  ulong param_4;
{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uStack00000020;
  uint local_30 [7];
  
  iVar4 = *(int *)this;
  local_30[0] = *(uint *)(iVar4 + -0xc);
  if (param_4 <= local_30[0]) {
    local_30[0] = local_30[0] - param_4;
    puVar2 = &STACKARG(0x20);
    if (local_30[0] <= param_3) {
      puVar2 = local_30;
    }
    uStack00000020 = *puVar2;
    do {
      uVar1 = uStack00000020;
      iVar3 = _memcmp(iVar4 + uStack00000020,param_2,param_4);
      if (iVar3 == 0) {
        return uVar1;
      }
      uStack00000020 = uVar1 - 1;
    } while (uStack00000020 != 0xffffffff);
  }
  return 0xffffffff;
}

/* __ZNKSs5rfindEPKcm @ 0x97c15ae0 (72 bytes) */
int __ZNKSs5rfindEPKcm(this, param_2, param_3)
  void *this;
  char *param_2;
  ulong param_3;
{
  ulong uVar1;
  
  uVar1 = _strlen(param_2);
  ((int (*)())__ZNKSs5rfindEPKcmm)(this,param_2,param_3,uVar1);
  return;
}

