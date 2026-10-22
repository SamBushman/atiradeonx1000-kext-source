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
int std__string___M_check(this, param_2, param_3)
  ulong this;
  int *param_2;
  uint param_3;
{
  int local_20 [4];
  
  if (*(uint *)(*param_2 + -0xc) < param_3) {
    std____throw_out_of_range("basic_string::_M_check");
  }
  __ZNKSs9_M_ibeginEv(local_20,param_2);
  *(uint *)this = local_20[0] + param_3;
  return this;
}

/* __ZNKSs7_M_foldEmm @ 0x97c13334 (100 bytes) */
int __ZNKSs7_M_foldEmm(this, param_2, param_3, param_4)
  ulong this;
  ulong param_2;
  int param_3;
  uint param_4;
{
  uint uVar1;
  int local_20 [4];
  
  uVar1 = *(int *)(*(int *)param_2 + -0xc) - param_3;
  if (uVar1 <= param_4) {
    param_4 = uVar1;
  }
  __ZNKSs9_M_ibeginEv(local_20,param_2);
  *(uint *)this = local_20[0] + param_3 + param_4;
  return this;
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
int __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIS_SsEES2_(this, str, param_3)
  char *this;
  int str;
  int param_3;
{
  return _memcpy(this,str,param_3 - str);
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
int __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIPKcSsEES4_(this, str, param_3)
  char *this;
  int str;
  int param_3;
{
  return _memcpy(this,str,param_3 - str);
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
int __ZNSs4_Rep10_M_disposeERKSaIcE(this, in_r4)
  unsigned char * this;
  uint in_r4;
{
  int atomicStore;
  unsigned char * paVar2;
  int iVar3;
  char in_RESERVE;
  byte in_cr0;
  
  paVar2 = this + 8;
  do {
    iVar3 = *(int *)paVar2;
    if (in_RESERVE != '\0') {
      atomicStore = storeWordConditionalIndexed(iVar3 + -1,0,paVar2);
      *(int *)paVar2 = atomicStore;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (0 < iVar3) {
    return;
  }
  return __ZNSs4_Rep10_M_destroyERKSaIcE(this,in_r4);
}

/* __ZNSs4_Rep15_M_set_sharableEv @ 0x97c13478 (12 bytes) */
int __ZNSs4_Rep15_M_set_sharableEv(this)
  void *this;
{
  *(undefined4 *)((int)this + 8) = 0;
  return;
}

/* __ZNSs9_M_mutateEmmm @ 0x97c13484 (260 bytes) */
int __ZNSs9_M_mutateEmmm(this, param_2, param_3, param_4)
  void *this;
  ulong param_2;
  ulong param_3;
  ulong param_4;
{
  int atomicStore;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  char in_RESERVE;
  byte in_cr0;
  unsigned char aaStack_40 [32];
  
  iVar4 = *(int *)this;
  iVar6 = iVar4 + param_2 + param_3;
  iVar7 = (*(int *)(iVar4 + -0xc) - param_2) - param_3;
  uVar8 = (*(int *)(iVar4 + -0xc) + param_4) - param_3;
  if (*(int *)(iVar4 + -4) < 1) {
    uVar2 = *(uint *)(iVar4 + -8);
    if (uVar8 <= uVar2) {
      if ((iVar7 != 0) && (param_3 != param_4)) {
        _memmove(iVar4 + param_2 + param_4,iVar6,iVar7);
        iVar4 = *(int *)this;
      }
      goto LAB_97c135b0;
    }
  }
  else {
    uVar2 = *(uint *)(iVar4 + -8);
  }
  uVar5 = uVar8;
  if (((uVar2 < uVar8) && (0xfe3 < uVar8)) && (uVar5 = uVar2 << 1, uVar2 << 1 < uVar8)) {
    uVar5 = uVar8;
  }
  iVar4 = __ZNSs4_Rep9_S_createEmRKSaIcE(uVar5,aaStack_40);
  iVar4 = iVar4 + 0xc;
  if (param_2 != 0) {
    _memcpy(iVar4,*(undefined4 *)this,param_2);
  }
  if (iVar7 != 0) {
    _memcpy(iVar4 + param_2 + param_4,iVar6,iVar7);
  }
  iVar6 = *(int *)this;
  piVar3 = (int *)(iVar6 + -4);
  do {
    iVar7 = *piVar3;
    if (in_RESERVE != '\0') {
      atomicStore = storeWordConditionalIndexed(iVar7 + -1,0,piVar3);
      *piVar3 = atomicStore;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar7 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(iVar6 + -0xc),(uint)aaStack_40);
  }
  *(int *)this = iVar4;
LAB_97c135b0:
  *(undefined4 *)(iVar4 + -4) = 0;
  *(uint *)(*(int *)this + -0xc) = uVar8;
  *(undefined1 *)(*(int *)this + uVar8) = 0;
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
  int iVar1;
  
  iVar1 = *(int *)this;
  if (0 < *(int *)(iVar1 + -4)) {
    ((int (*)())__ZNSs9_M_mutateEmmm)(this,0,0,0);
    iVar1 = *(int *)this;
  }
  *(undefined4 *)(iVar1 + -4) = 0xffffffff;
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
  int *piVar2;
  char in_RESERVE;
  byte in_cr0;
  
  piVar2 = (int *)((int)this + 8);
  do {
    if (in_RESERVE != '\0') {
      atomicStore = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = atomicStore;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  return (int)this + 0xc;
}

/* __ZNSsC4Ev @ 0x97c1368c (84 bytes) */
int __ZNSsC4Ev(this)
  void *this;
{
  char in_RESERVE;
  byte in_cr0;
  unsigned char aaStack_20 [28];
  
  do {
    if (in_RESERVE != '\0') {
      DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
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
  char *pcVar1;
  
  pcVar1 = (char *)std__string___S_construct(0,0,allocator);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,pcVar1,allocator);
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
  int *piVar2;
  char *pcVar3;
  char in_RESERVE;
  byte in_cr0;
  unsigned char aaStack_50 [32];
  unsigned char aaStack_30 [28];
  
  pcVar3 = *(char **)text;
  ((int (*)())__ZNKSs13get_allocatorEv)();
  if (*(int *)(pcVar3 + -4) < 0) {
    pcVar3 = (char *)__ZNSs4_Rep8_M_cloneERKSaIcEm(pcVar3 + -0xc,aaStack_50,0);
  }
  else {
    piVar2 = (int *)(pcVar3 + -4);
    do {
      if (in_RESERVE != '\0') {
        atomicStore = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
        *piVar2 = atomicStore;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
  }
  ((int (*)())__ZNKSs13get_allocatorEv)();
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,pcVar3,aaStack_30);
}

/* __ZNSs4_Rep7_M_grabERKSaIcES2_ @ 0x97c1373c (48 bytes) */
int __ZNSs4_Rep7_M_grabERKSaIcES2_(this, allocator1)
  unsigned char * this;
  unsigned char * allocator1;
{
  int atomicStore;
  unsigned char * paVar2;
  char in_RESERVE;
  byte in_cr0;
  
  if (*(int *)(this + 8) < 0) {
    paVar2 = (unsigned char *)__ZNSs4_Rep8_M_cloneERKSaIcEm(this,allocator1,0);
    return paVar2;
  }
  paVar2 = this + 8;
  do {
    if (in_RESERVE != '\0') {
      atomicStore = storeWordConditionalIndexed(*(int *)paVar2 + 1,0,paVar2);
      *(int *)paVar2 = atomicStore;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  return this + 0xc;
}

/* __ZNSsC4ERKSs @ 0x97c1376c (152 bytes) */
int __ZNSsC4ERKSs(this, text)
  void *this;
  unsigned char * text;
{
  int atomicStore;
  int *piVar2;
  char *pcVar3;
  char in_RESERVE;
  byte in_cr0;
  unsigned char aaStack_50 [32];
  unsigned char aaStack_30 [28];
  
  pcVar3 = *(char **)text;
  ((int (*)())__ZNKSs13get_allocatorEv)();
  if (*(int *)(pcVar3 + -4) < 0) {
    pcVar3 = (char *)__ZNSs4_Rep8_M_cloneERKSaIcEm(pcVar3 + -0xc,aaStack_50,0);
  }
  else {
    piVar2 = (int *)(pcVar3 + -4);
    do {
      if (in_RESERVE != '\0') {
        atomicStore = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
        *piVar2 = atomicStore;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
  }
  ((int (*)())__ZNKSs13get_allocatorEv)();
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,pcVar3,aaStack_30);
}

/* __ZNSsC2ERKSsmm @ 0x97c13808 (4 bytes) */
int __ZNSsC2ERKSsmm(this, text, param_3, param_4)
  void *this;
  unsigned char * text;
  ulong param_3;
  ulong param_4;
{
  return ((int (*)())__ZNSsC4ERKSsmm)(this,text,param_3,param_4);
}

/* __ZNSsC1ERKSsmm @ 0x97c1380c (4 bytes) */
int __ZNSsC1ERKSsmm(this, text, param_3, param_4)
  void *this;
  unsigned char * text;
  ulong param_3;
  ulong param_4;
{
  char *pcVar1;
  undefined4 uStack_50;
  undefined4 auStack_4c [3];
  unsigned char aaStack_40 [16];
  unsigned char aaStack_30 [24];
  
  ((int (*)())std__string___M_check)((ulong)&uStack_50,text,param_3);
  ((int (*)())__ZNKSs7_M_foldEmm)((ulong)auStack_4c,(ulong)text,param_3,param_4);
  pcVar1 = __ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag
                     (uStack_50,auStack_4c[0],aaStack_40,0);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,pcVar1,aaStack_30);
}

/* __ZNSsC4ERKSsmm @ 0x97c13810 (120 bytes) */
int __ZNSsC4ERKSsmm(this, text, param_3, param_4)
  void *this;
  unsigned char * text;
  ulong param_3;
  ulong param_4;
{
  char *pcVar1;
  undefined4 local_50;
  undefined4 local_4c [3];
  unsigned char aaStack_40 [16];
  unsigned char aaStack_30 [24];
  
  ((int (*)())std__string___M_check)((ulong)&local_50,text,param_3);
  ((int (*)())__ZNKSs7_M_foldEmm)((ulong)local_4c,(ulong)text,param_3,param_4);
  pcVar1 = __ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag
                     (local_50,local_4c[0],aaStack_40,0);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,pcVar1,aaStack_30);
}

/* __ZNSsC2ERKSsmmRKSaIcE @ 0x97c1388c (4 bytes) */
int __ZNSsC2ERKSsmmRKSaIcE(this, text, param_3, param_4, allocator)
  void *this;
  unsigned char * text;
  ulong param_3;
  ulong param_4;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4ERKSsmmRKSaIcE)(this,text,param_3,param_4,allocator);
}

/* __ZNSsC1ERKSsmmRKSaIcE @ 0x97c13890 (4 bytes) */
int __ZNSsC1ERKSsmmRKSaIcE(this, text, param_3, param_4, allocator)
  void *this;
  unsigned char * text;
  ulong param_3;
  ulong param_4;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4ERKSsmmRKSaIcE)(this,text,param_3,param_4,allocator);
}

/* __ZNSsC4ERKSsmmRKSaIcE @ 0x97c13894 (124 bytes) */
int __ZNSsC4ERKSsmmRKSaIcE(this, text, param_3, param_4, allocator)
  void *this;
  unsigned char * text;
  ulong param_3;
  ulong param_4;
  unsigned char * allocator;
{
  char *pcVar1;
  undefined4 local_30;
  undefined4 local_2c [4];
  
  ((int (*)())std__string___M_check)((ulong)&local_30,text,param_3);
  ((int (*)())__ZNKSs7_M_foldEmm)((ulong)local_2c,(ulong)text,param_3,param_4);
  pcVar1 = __ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag
                     (local_30,local_2c[0],allocator,0);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,pcVar1,allocator);
}

/* __ZNSsC2EPKcmRKSaIcE @ 0x97c13910 (4 bytes) */
int __ZNSsC2EPKcmRKSaIcE(this, str, param_3, allocator)
  void *this;
  char *str;
  ulong param_3;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4EPKcmRKSaIcE)(this,str,param_3,allocator);
}

/* __ZNSsC1EPKcmRKSaIcE @ 0x97c13914 (4 bytes) */
int __ZNSsC1EPKcmRKSaIcE(this, str, param_3, allocator)
  void *this;
  char *str;
  ulong param_3;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4EPKcmRKSaIcE)(this,str,param_3,allocator);
}

/* __ZNSsC4EPKcmRKSaIcE @ 0x97c13918 (80 bytes) */
int __ZNSsC4EPKcmRKSaIcE(this, str, param_3, allocator)
  void *this;
  char *str;
  ulong param_3;
  unsigned char * allocator;
{
  char *pcVar1;
  
  pcVar1 = __ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag
                     (str,str + param_3,allocator,0);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,pcVar1,allocator);
}

/* __ZNSsC2EPKcRKSaIcE @ 0x97c13968 (4 bytes) */
int __ZNSsC2EPKcRKSaIcE(this, str, allocator)
  void *this;
  char *str;
  unsigned char * allocator;
{
  size_t length;
  char *pcVar2;
  
  if (str == (char *)0x0) {
    pcVar2 = (char *)0xffffffff;
  }
  else {
    length = _strlen(str);
    pcVar2 = str + length;
  }
  pcVar2 = __ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag
                     (str,pcVar2,allocator,0);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,pcVar2,allocator);
}

/* __ZNSsC1EPKcRKSaIcE @ 0x97c1396c (4 bytes) */
int __ZNSsC1EPKcRKSaIcE(this, str, allocator)
  void *this;
  char *str;
  unsigned char * allocator;
{
  size_t length;
  char *pcVar2;
  
  if (str == (char *)0x0) {
    pcVar2 = (char *)0xffffffff;
  }
  else {
    length = _strlen(str);
    pcVar2 = str + length;
  }
  pcVar2 = __ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag
                     (str,pcVar2,allocator,0);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,pcVar2,allocator);
}

/* __ZNSsC4EPKcRKSaIcE @ 0x97c13970 (104 bytes) */
int __ZNSsC4EPKcRKSaIcE(this, str, allocator)
  void *this;
  char *str;
  unsigned char * allocator;
{
  int length;
  char *pcVar2;
  
  if (str == (char *)0x0) {
    pcVar2 = (char *)0xffffffff;
  }
  else {
    length = _strlen(str);
    pcVar2 = str + length;
  }
  pcVar2 = __ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag
                     (str,pcVar2,allocator,0);
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,pcVar2,allocator);
}

/* __ZNSsC2EmcRKSaIcE @ 0x97c139d8 (4 bytes) */
int __ZNSsC2EmcRKSaIcE(this, param_2, param_3, allocator)
  void *this;
  ulong param_2;
  int param_3;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4EmcRKSaIcE)(this,param_2,param_3,allocator);
}

/* __ZNSsC1EmcRKSaIcE @ 0x97c139dc (4 bytes) */
int __ZNSsC1EmcRKSaIcE(this, param_2, param_3, allocator)
  void *this;
  ulong param_2;
  int param_3;
  unsigned char * allocator;
{
  return ((int (*)())__ZNSsC4EmcRKSaIcE)(this,param_2,param_3,allocator);
}

/* __ZNSsC4EmcRKSaIcE @ 0x97c139e0 (76 bytes) */
int __ZNSsC4EmcRKSaIcE(this, param_2, param_3, allocator)
  void *this;
  ulong param_2;
  int param_3;
  unsigned char * allocator;
{
  char *pcVar1;
  undefined3 in_register_00000014;
  
  pcVar1 = (char *)std__string___S_construct(param_2,CONCAT31(in_register_00000014,param_3),allocator)
  ;
  return ((int (*)())__ZNSs12_Alloc_hiderC4EPcRKSaIcE)(this,pcVar1,allocator);
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
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  undefined1 auStack_20 [20];
  
  iVar4 = *(int *)this;
  ((int (*)())__ZNKSs13get_allocatorEv)();
  piVar2 = (int *)(iVar4 + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      atomicStore = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = atomicStore;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(iVar4 + -0xc),(uint)auStack_20);
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
int __ZNSs6assignEPKcm(this, str, param_3)
  void *this;
  char *str;
  ulong param_3;
{
  char *pcVar1;
  unsigned char * psVar2;
  undefined4 local_30;
  undefined4 local_2c [6];
  
  if (0x3ffffffc < param_3) {
    std____throw_length_error("basic_string::assign");
  }
  pcVar1 = *(char **)this;
  if (((0 < *(int *)(pcVar1 + -4)) || (str < pcVar1)) ||
     (pcVar1 + *(int *)(pcVar1 + -0xc) < str)) {
    __ZNKSs9_M_ibeginEv(&local_30,this);
    __ZNKSs7_M_iendEv(local_2c,this);
    psVar2 = __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                       (this,local_30,local_2c[0],str,str + param_3);
    return psVar2;
  }
  if ((uint)((int)str - (int)pcVar1) < param_3) {
    if (str == pcVar1) goto LAB_97c13b7c;
    _memmove(pcVar1,str,param_3);
  }
  else {
    _memcpy(pcVar1,str,param_3);
  }
  pcVar1 = *(char **)this;
LAB_97c13b7c:
  *(ulong *)(pcVar1 + -0xc) = param_3;
  *(undefined1 *)(*(int *)this + param_3) = 0;
  return this;
}

/* __ZNSs6assignEPKc @ 0x97c13ba4 (260 bytes) */
int __ZNSs6assignEPKc(this, str)
  void *this;
  char *str;
{
  uint length;
  char *pcVar2;
  unsigned char * psVar3;
  undefined4 local_30;
  undefined4 local_2c [6];
  
  length = _strlen(str);
  if (0x3ffffffc < length) {
    std____throw_length_error("basic_string::assign");
  }
  pcVar2 = *(char **)this;
  if (((0 < *(int *)(pcVar2 + -4)) || (str < pcVar2)) ||
     (pcVar2 + *(int *)(pcVar2 + -0xc) < str)) {
    __ZNKSs9_M_ibeginEv(&local_30,this);
    __ZNKSs7_M_iendEv(local_2c,this);
    psVar3 = __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                       (this,local_30,local_2c[0],str,str + length);
    return psVar3;
  }
  if ((uint)((int)str - (int)pcVar2) < length) {
    if (str == pcVar2) goto LAB_97c13c80;
    _memmove(pcVar2,str,length);
  }
  else {
    _memcpy(pcVar2,str,length);
  }
  pcVar2 = *(char **)this;
LAB_97c13c80:
  *(uint *)(pcVar2 + -0xc) = length;
  *(undefined1 *)(*(int *)this + length) = 0;
  return this;
}

/* __ZNSsaSEPKc @ 0x97c13ca8 (260 bytes) */
int __ZNSsaSEPKc(this, str)
  void *this;
  char *str;
{
  uint length;
  char *pcVar2;
  unsigned char * psVar3;
  undefined4 local_30;
  undefined4 local_2c [6];
  
  length = _strlen(str);
  if (0x3ffffffc < length) {
    std____throw_length_error("basic_string::assign");
  }
  pcVar2 = *(char **)this;
  if (((0 < *(int *)(pcVar2 + -4)) || (str < pcVar2)) ||
     (pcVar2 + *(int *)(pcVar2 + -0xc) < str)) {
    __ZNKSs9_M_ibeginEv(&local_30,this);
    __ZNKSs7_M_iendEv(local_2c,this);
    psVar3 = __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                       (this,local_30,local_2c[0],str,str + length);
    return psVar3;
  }
  if ((uint)((int)str - (int)pcVar2) < length) {
    if (str == pcVar2) goto LAB_97c13d84;
    _memmove(pcVar2,str,length);
  }
  else {
    _memcpy(pcVar2,str,length);
  }
  pcVar2 = *(char **)this;
LAB_97c13d84:
  *(uint *)(pcVar2 + -0xc) = length;
  *(undefined1 *)(*(int *)this + length) = 0;
  return this;
}

/* __ZNSs6assignEmc @ 0x97c13dac (100 bytes) */
int __ZNSs6assignEmc(this, param_2, param_3)
  void *this;
  ulong param_2;
  undefined4 param_3;
{
  undefined4 local_30;
  undefined4 local_2c [5];
  
  __ZNKSs9_M_ibeginEv(&local_30,this);
  __ZNKSs7_M_iendEv(local_2c,this);
  return __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc
            (this,local_30,local_2c[0],param_2,param_3);
}

/* __ZNSsaSEc @ 0x97c13e10 (96 bytes) */
int __ZNSsaSEc(this, param_2)
  void *this;
  undefined4 param_2;
{
  undefined4 local_30;
  undefined4 local_2c [6];
  
  __ZNKSs9_M_ibeginEv(&local_30,this);
  __ZNKSs7_M_iendEv(local_2c,this);
  return __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc(this,local_30,local_2c[0],1,param_2);
}

/* __ZNSs5beginEv @ 0x97c13e70 (64 bytes) */
int __ZNSs5beginEv(this, param_2)
  undefined4 *this;
  undefined4 *param_2;
{
  ((int (*)())__ZNSs7_M_leakEv)(param_2);
  *this = *param_2;
  return this;
}

/* __ZNKSs5beginEv @ 0x97c13eb0 (12 bytes) */
int __ZNKSs5beginEv(this, param_2)
  undefined4 *this;
  undefined4 *param_2;
{
  *this = *param_2;
  return;
}

/* __ZNSs3endEv @ 0x97c13ebc (72 bytes) */
int __ZNSs3endEv(this, param_2)
  int *this;
  int *param_2;
{
  ((int (*)())__ZNSs7_M_leakEv)(param_2);
  *this = *param_2 + *(int *)(*param_2 + -0xc);
  return this;
}

/* __ZNKSs3endEv @ 0x97c13f04 (20 bytes) */
int __ZNKSs3endEv(this, param_2)
  int *this;
  int *param_2;
{
  *this = *param_2 + *(int *)(*param_2 + -0xc);
  return;
}

