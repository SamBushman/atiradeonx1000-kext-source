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
int __ZNSs7replaceEmmPKcm(this, pos1, n1, str, pos2)
  void *this;
  ulong pos1;
  ulong n1;
  char *str;
  ulong pos2;
{
  char *data;
  uint uVar2;
  int local_30;
  int local_2c [4];
  
  uVar2 = *(uint *)(*(int *)this + -0xc);
  if (uVar2 < pos1) {
    std____throw_out_of_range("basic_string::replace");
  }
  if (uVar2 - pos1 <= n1) {
    n1 = uVar2 - pos1;
  }
  if (0x3ffffffc - pos2 < uVar2 - n1) {
    std____throw_length_error("basic_string::replace");
  }
  data = *(char **)this;
  if (((*(int *)(data + -4) < 1) && (data <= str)) && (str <= data + uVar2)) {
    __ZNKSs9_M_ibeginEv(local_2c,this);
    __ZNKSs9_M_ibeginEv(&local_30,this);
    __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
              (this,local_30 + pos1,(char *)(local_2c[0] + pos1 + n1),str,
               str + pos2,0);
  }
  else {
    __ZNKSs9_M_ibeginEv(&local_30,this);
    __ZNKSs9_M_ibeginEv(local_2c,this);
    __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
              (this,local_2c[0] + pos1,local_30 + pos1 + n1,str,str + pos2);
  }
  return;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S1_S1_ @ 0x97c14150 (344 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S1_S1_(this, i1, param_3, str1, str2)
  void *this;
  int i1;
  int param_3;
  char *str1;
  int str2;
{
  char *data;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int local_30;
  int local_2c;
  int local_28 [2];
  
  __ZNKSs9_M_ibeginEv(&local_30,this);
  iVar4 = str2 - (int)str1;
  uVar5 = *(uint *)(*(int *)this + -0xc);
  uVar2 = i1 - local_30;
  if (uVar5 < uVar2) {
    std____throw_out_of_range("basic_string::replace");
  }
  uVar3 = param_3 - i1;
  if (uVar5 - uVar2 <= (uint)(param_3 - i1)) {
    uVar3 = uVar5 - uVar2;
  }
  if (0x3ffffffcU - iVar4 < uVar5 - uVar3) {
    std____throw_length_error("basic_string::replace");
  }
  data = *(char **)this;
  if (((*(int *)(data + -4) < 1) && (data <= str1)) && (str1 <= data + uVar5)) {
    __ZNKSs9_M_ibeginEv(local_28,this);
    __ZNKSs9_M_ibeginEv(&local_2c,this);
    __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
              (this,local_2c + uVar2,(char *)(local_28[0] + uVar2 + uVar3),str1,str1 + iVar4,0
              );
  }
  else {
    __ZNKSs9_M_ibeginEv(&local_2c,this);
    __ZNKSs9_M_ibeginEv(local_28,this);
    __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
              (this,local_28[0] + uVar2,local_2c + uVar2 + uVar3,str1,str1 + iVar4);
  }
  return;
}

/* __ZNSs5eraseEmm @ 0x97c142a8 (376 bytes) */
int __ZNSs5eraseEmm(this, pos, n)
  ulong this;
  ulong pos;
  undefined4 n;
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
  
  std__string___M_check((ulong)&local_40,this,pos);
  __ZNKSs7_M_foldEmm((ulong)&local_3c,this,pos,n);
  pcVar2 = *(char **)this;
  __ZNKSs9_M_ibeginEv(&local_38,this);
  uVar5 = *(uint *)(*(int *)this + -0xc);
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
  pcVar1 = *(char **)this;
  if (((*(int *)(pcVar1 + -4) < 1) && (pcVar1 <= pcVar2)) && (pcVar2 <= pcVar1 + uVar5)) {
    __ZNKSs9_M_ibeginEv(local_30,this);
    __ZNKSs9_M_ibeginEv(&local_34,this);
    __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
              (this,local_34 + uVar3,(char *)(local_30[0] + uVar3 + uVar4),pcVar2,pcVar2,0);
  }
  else {
    __ZNKSs9_M_ibeginEv(&local_34,this);
    __ZNKSs9_M_ibeginEv(local_30,this);
    __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
              ((void *)this,local_30[0] + uVar3,local_34 + uVar3 + uVar4,pcVar2,pcVar2);
  }
  return;
}

/* __ZNSs6resizeEmc @ 0x97c14420 (448 bytes) */
int __ZNSs6resizeEmc(this, pos, c)
  void *this;
  ulong pos;
  int c;
{
  uint uVar1;
  char *data2;
  undefined3 in_register_00000014;
  char *data;
  uint uVar4;
  uint uVar5;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30 [5];
  
  if (0x3ffffffc < pos) {
    std____throw_length_error("basic_string::resize");
  }
  uVar1 = *(uint *)(*(int *)this + -0xc);
  if (uVar1 < pos) {
    ((int (*)())__ZNSs6appendEmc)(this,pos - uVar1,CONCAT31(in_register_00000014,c));
  }
  else if (pos < uVar1) {
    std__string___M_check((ulong)&local_40,this,pos);
    __ZNKSs7_M_foldEmm((ulong)&local_3c,(ulong)this,pos,0xffffffff);
    data = *(char **)this;
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
    data2 = *(char **)this;
    if (((*(int *)(data2 + -4) < 1) && (data2 <= data)) && (data <= data2 + uVar4)) {
      __ZNKSs9_M_ibeginEv(local_30,this);
      __ZNKSs9_M_ibeginEv(&local_34,this);
      __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag
                (this,local_34 + uVar1,(char *)(local_30[0] + uVar1 + uVar5),data,data,0);
    }
    else {
      __ZNKSs9_M_ibeginEv(&local_34,this);
      __ZNKSs9_M_ibeginEv(local_30,this);
      __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                (this,local_30[0] + uVar1,local_34 + uVar1 + uVar5,data,data);
    }
  }
  return;
}

/* __ZNSs6resizeEm @ 0x97c145e0 (8 bytes) */
int __ZNSs6resizeEm(this, pos)
  void *this;
  ulong pos;
{
  return ((int (*)())__ZNSs6resizeEmc)(this,pos,'\0');
}

/* __ZNSs7reserveEm @ 0x97c145e8 (204 bytes) */
int __ZNSs7reserveEm(this, pos)
  void *this;
  ulong pos;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  undefined4 uVar4;
  int data;
  char reservation;
  byte cr0Reg;
  unsigned char aaStack_20 [20];
  
  data = *(int *)this;
  if ((*(uint *)(data + -8) < pos) || (0 < *(int *)(data + -4))) {
    if (0x3ffffffc < pos) {
      std____throw_length_error("basic_string::reserve");
      data = *(int *)this;
    }
    if (pos < *(uint *)(data + -0xc)) {
      pos = *(uint *)(data + -0xc);
    }
    __ZNKSs13get_allocatorEv();
    uVar4 = __ZNSs4_Rep8_M_cloneERKSaIcEm
                      ((void *)(*(int *)this + -0xc),aaStack_20,
                       pos - *(int *)(*(int *)this + -0xc));
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
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(data + -0xc),(uint)aaStack_20);
    }
    *(undefined4 *)this = uVar4;
  }
  return;
}

/* __ZNSs5clearEv @ 0x97c146cc (20 bytes) */
int __ZNSs5clearEv(this)
  void *this;
{
  return __ZNSs9_M_mutateEmmm(this,0,*(ulong *)(*(int *)this + -0xc),0);
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
int __ZNKSs2atEm(this, pos)
  void *this;
  ulong pos;
{
  int data;
  
  data = *(int *)this;
  if (*(uint *)(data + -0xc) <= pos) {
    std____throw_out_of_range("basic_string::at");
    data = *(int *)this;
  }
  return data + pos;
}

/* __ZNSs2atEm @ 0x97c14790 (96 bytes) */
int __ZNSs2atEm(this, pos)
  void *this;
  ulong pos;
{
  if (*(uint *)(*(int *)this + -0xc) <= pos) {
    std____throw_out_of_range("basic_string::at");
  }
  __ZNSs7_M_leakEv(this);
  return *(int *)this + pos;
}

/* __ZNSspLERKSs @ 0x97c147f0 (4 bytes) */
int __ZNSspLERKSs(this, text)
  void *this;
  unsigned char * text;
{
  return ((int (*)())__ZNSs6appendERKSs)(this,text);
}

/* __ZNSs6appendEPKc @ 0x97c147f4 (64 bytes) */
int __ZNSs6appendEPKc(this, str)
  void *this;
  char *str;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNSs6appendEPKcm)(this,str,length);
}

/* __ZNSspLEPKc @ 0x97c14834 (64 bytes) */
int __ZNSspLEPKc(this, str)
  void *this;
  char *str;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNSs6appendEPKcm)(this,str,length);
}

/* __ZNSspLEc @ 0x97c14874 (12 bytes) */
int __ZNSspLEc(this, param_2)
  void *this;
  int param_2;
{
  undefined3 in_register_00000010;
  
  return ((int (*)())__ZNSs6appendEmc)(this,1,CONCAT31(in_register_00000010,param_2));
}

/* __ZNSs6appendERKSs @ 0x97c14880 (164 bytes) */
int __ZNSs6appendERKSs(this, text)
  void *this;
  unsigned char * text;
{
  ulong uVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24 [4];
  
  uVar1 = *(int *)(*(int *)text + -0xc) + *(int *)(*(int *)this + -0xc);
  if (*(uint *)(*(int *)this + -8) < uVar1) {
    ((int (*)())__ZNSs7reserveEm)(this,uVar1);
  }
  __ZNKSs7_M_iendEv(&local_30,this);
  __ZNKSs7_M_iendEv(&local_2c,this);
  __ZNKSs9_M_ibeginEv(&local_28,text);
  __ZNKSs7_M_iendEv(local_24,text);
  return __ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_
            (this,local_30,local_2c,local_28,local_24[0]);
}

/* __ZNSs6appendERKSsmm @ 0x97c14924 (216 bytes) */
int __ZNSs6appendERKSsmm(this, text, pos, n)
  void *this;
  unsigned char * text;
  ulong pos;
  ulong n;
{
  unsigned int ghidra_home[8] = { this, text, pos, n, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  ulong uVar1;
  uint *puVar2;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30 [6];
  
  puVar2 = &(*(unsigned int *)((unsigned char *)ghidra_home + 12));
  local_30[0] = *(int *)(*(int *)text + -0xc) - pos;
  if (local_30[0] <= n) {
    puVar2 = local_30;
  }
  uVar1 = *puVar2 + *(int *)(*(int *)this + -0xc);
  (*(ulong *)((unsigned char *)ghidra_home + 12)) = n;
  if (*(uint *)(*(int *)this + -8) < uVar1) {
    ((int (*)())__ZNSs7reserveEm)(this,uVar1);
  }
  __ZNKSs7_M_iendEv(&local_40,this);
  __ZNKSs7_M_iendEv(&local_3c,this);
  std__string___M_check((ulong)&local_38,text,pos);
  __ZNKSs7_M_foldEmm((ulong)&local_34,(ulong)text,pos,(*(ulong *)((unsigned char *)ghidra_home + 12)));
  return __ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_
            (this,local_40,local_3c,local_38,local_34);
}

/* __ZNSs6appendEPKcm @ 0x97c149fc (132 bytes) */
int __ZNSs6appendEPKcm(this, str, pos)
  void *this;
  char *str;
  ulong pos;
{
  ulong uVar1;
  undefined4 local_30;
  undefined4 local_2c [6];
  
  uVar1 = pos + *(int *)(*(int *)this + -0xc);
  if (*(uint *)(*(int *)this + -8) < uVar1) {
    ((int (*)())__ZNSs7reserveEm)(this,uVar1);
  }
  __ZNKSs7_M_iendEv(&local_30,this);
  __ZNKSs7_M_iendEv(local_2c,this);
  return __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
            (this,local_30,local_2c[0],str,str + pos);
}

/* __ZNSs6appendEmc @ 0x97c14a80 (128 bytes) */
int __ZNSs6appendEmc(this, pos, c)
  void *this;
  ulong pos;
  undefined4 c;
{
  ulong uVar1;
  undefined4 local_30;
  undefined4 local_2c [6];
  
  uVar1 = pos + *(int *)(*(int *)this + -0xc);
  if (*(uint *)(*(int *)this + -8) < uVar1) {
    ((int (*)())__ZNSs7reserveEm)(this,uVar1);
  }
  __ZNKSs7_M_iendEv(&local_30,this);
  __ZNKSs7_M_iendEv(local_2c,this);
  return ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,local_30,local_2c[0],pos,c);
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
  return ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,local_30,local_2c[0],1,param_2);
}

/* __ZNSs6assignERKSs @ 0x97c14b60 (104 bytes) */
int __ZNSs6assignERKSs(this, text)
  void *this;
  unsigned char * text;
{
  int data;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  undefined4 uVar4;
  int iVar5;
  char reservation;
  byte cr0Reg;
  unsigned char aaStack_40 [44];
  
  if (*(int *)this + -0xc != *(int *)text + -0xc) {
    __ZNKSs13get_allocatorEv();
    iVar5 = *(int *)text;
    __ZNKSs13get_allocatorEv();
    uVar4 = __ZNSs4_Rep7_M_grabERKSaIcES2_((unsigned char *)(iVar5 + -0xc),aaStack_40);
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
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(data + -0xc));
    }
    *(undefined4 *)this = uVar4;
  }
  return this;
}

/* __ZNSs6assignERKSsmm @ 0x97c14c18 (120 bytes) */
int __ZNSs6assignERKSsmm(this, text, pos, n)
  void *this;
  unsigned char * text;
  ulong pos;
  ulong n;
{
  uint repLength;
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)text;
  repLength = *(uint *)(iVar1 + -0xc);
  if (repLength < pos) {
    std____throw_out_of_range("basic_string::assign");
    iVar1 = *(int *)text;
  }
  uVar2 = repLength - pos;
  if (uVar2 <= n) {
    n = uVar2;
  }
  return __ZNSs6assignEPKcm(this,(char *)(iVar1 + pos),n);
}

/* __ZNSs6insertEN9__gnu_cxx17__normal_iteratorIPcSsEEmc @ 0x97c14c90 (16 bytes) */
int __ZNSs6insertEN9__gnu_cxx17__normal_iteratorIPcSsEEmc(this, __normal_iterator, param_3, pos1)
  void *this;
  undefined4 __normal_iterator;
  undefined4 param_3;
  undefined4 pos1;
{
  return ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,__normal_iterator,__normal_iterator,param_3,pos1);
}

/* __ZNSs6insertEmPKcm @ 0x97c14ca0 (332 bytes) */
int __ZNSs6insertEmPKcm(this, pos1, str, n1)
  void *this;
  ulong pos1;
  char *str;
  ulong n1;
{
  char *data;
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int local_30;
  int local_2c [4];
  
  uVar4 = *(uint *)(*(int *)this + -0xc);
  if (uVar4 < pos1) {
    std____throw_out_of_range("basic_string::insert");
  }
  if (0x3ffffffc - n1 < uVar4) {
    std____throw_length_error("basic_string::insert");
  }
  data = *(char **)this;
  if (((*(int *)(data + -4) < 1) && (data <= str)) && (str <= data + uVar4)) {
    __ZNSs9_M_mutateEmmm(this,pos1,0,n1);
    pcVar1 = str + (*(int *)this - (int)data);
    pcVar5 = (char *)(*(int *)this + pos1);
    pcVar2 = pcVar1;
    if ((pcVar5 < pcVar1 + n1) && (pcVar2 = pcVar1 + n1, pcVar1 < pcVar5)) {
      iVar3 = (int)pcVar5 - (int)pcVar1;
      _memcpy(pcVar5,pcVar1,iVar3);
      pcVar2 = pcVar5 + n1;
      pcVar5 = pcVar5 + iVar3;
      n1 = n1 - iVar3;
    }
    _memcpy(pcVar5,pcVar2,n1);
  }
  else {
    __ZNKSs9_M_ibeginEv(&local_30,this);
    __ZNKSs9_M_ibeginEv(local_2c,this);
    this = __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                     (this,local_2c[0] + pos1,local_30 + pos1,str,str + n1);
  }
  return this;
}

/* __ZNSs6insertEmRKSsmm @ 0x97c14dec (388 bytes) */
int __ZNSs6insertEmRKSsmm(this, pos1, text, n1, pos2)
  void *this;
  ulong pos1;
  unsigned char * text;
  ulong n1;
  ulong pos2;
{
  uint repLength;
  char *data;
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  int local_30;
  int local_2c [3];
  
  iVar2 = *(int *)text;
  repLength = *(uint *)(iVar2 + -0xc);
  if (repLength < n1) {
    std____throw_out_of_range("basic_string::insert");
    iVar2 = *(int *)text;
  }
  uVar4 = repLength - n1;
  if (uVar4 <= pos2) {
    pos2 = uVar4;
  }
  pcVar1 = (char *)(iVar2 + n1);
  uVar4 = *(uint *)(*(int *)this + -0xc);
  if (uVar4 < pos1) {
    std____throw_out_of_range("basic_string::insert");
  }
  if (0x3ffffffc - pos2 < uVar4) {
    std____throw_length_error("basic_string::insert");
  }
  data = *(char **)this;
  if (((*(int *)(data + -4) < 1) && (data <= pcVar1)) && (pcVar1 <= data + uVar4)) {
    __ZNSs9_M_mutateEmmm(this,pos1,0,pos2);
    pcVar1 = pcVar1 + (*(int *)this - (int)data);
    pcVar5 = (char *)(*(int *)this + pos1);
    pcVar3 = pcVar1;
    if ((pcVar5 < pcVar1 + pos2) && (pcVar3 = pcVar1 + pos2, pcVar1 < pcVar5)) {
      iVar2 = (int)pcVar5 - (int)pcVar1;
      _memcpy(pcVar5,pcVar1,iVar2);
      pcVar3 = pcVar5 + pos2;
      pcVar5 = pcVar5 + iVar2;
      pos2 = pos2 - iVar2;
    }
    _memcpy(pcVar5,pcVar3,pos2);
  }
  else {
    __ZNKSs9_M_ibeginEv(&local_30,this);
    __ZNKSs9_M_ibeginEv(local_2c,this);
    this = __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_
                     (this,local_2c[0] + pos1,local_30 + pos1,pcVar1,pcVar1 + pos2);
  }
  return this;
}

/* __ZNSs6insertEmRKSs @ 0x97c14f70 (332 bytes) */
int __ZNSs6insertEmRKSs(this, pos1, text)
  void *this;
  ulong pos1;
  unsigned char * text;
{
  char *data;
  ulong uVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  int local_30;
  int local_2c [4];
  
  pcVar2 = *(char **)text;
  uVar5 = *(uint *)(*(int *)this + -0xc);
  uVar1 = *(ulong *)(pcVar2 + -0xc);
  if (uVar5 < pos1) {
    std____throw_out_of_range("basic_string::insert");
  }
  if (0x3ffffffc - uVar1 < uVar5) {
    std____throw_length_error("basic_string::insert");
  }
  data = *(char **)this;
  if (((*(int *)(data + -4) < 1) && (data <= pcVar2)) && (pcVar2 <= data + uVar5)) {
    __ZNSs9_M_mutateEmmm(this,pos1,0,uVar1);
    pcVar2 = pcVar2 + (*(int *)this - (int)data);
    pcVar6 = (char *)(*(int *)this + pos1);
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
                     (this,local_2c[0] + pos1,local_30 + pos1,pcVar2,pcVar2 + uVar1);
  }
  return this;
}

/* __ZNSs6insertEmPKc @ 0x97c150bc (72 bytes) */
int __ZNSs6insertEmPKc(this, pos1, str)
  void *this;
  ulong pos1;
  char *str;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNSs6insertEmPKcm)(this,pos1,str,length);
}

/* __ZNSs6insertEmmc @ 0x97c15104 (92 bytes) */
int __ZNSs6insertEmmc(this, pos1, n1, c)
  void *this;
  ulong pos1;
  ulong n1;
  undefined4 c;
{
  undefined4 local_30 [7];
  
  std__string___M_check((ulong)local_30,this,pos1);
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,local_30[0],local_30[0],n1,c);
  return this;
}

/* __ZNSs6insertEN9__gnu_cxx17__normal_iteratorIPcSsEEc @ 0x97c15160 (148 bytes) */
int __ZNSs6insertEN9__gnu_cxx17__normal_iteratorIPcSsEEc(this, i1, param_3, c)
  int *this;
  int *i1;
  int param_3;
  undefined4 c;
{
  int iVar1;
  int local_30 [6];
  
  __ZNKSs9_M_ibeginEv(local_30,i1);
  iVar1 = param_3 - local_30[0];
  std__string___M_check((ulong)local_30,i1,iVar1);
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(i1,local_30[0],local_30[0],1,c);
  *(undefined4 *)(*i1 + -4) = 0xffffffff;
  __ZNKSs9_M_ibeginEv(local_30,i1);
  *this = local_30[0] + iVar1;
  return this;
}

/* __ZNSs5eraseEN9__gnu_cxx17__normal_iteratorIPcSsEE @ 0x97c151f4 (128 bytes) */
int __ZNSs5eraseEN9__gnu_cxx17__normal_iteratorIPcSsEE(this, i1, param_3)
  int *this;
  int *i1;
  int param_3;
{
  int iVar1;
  int local_30 [7];
  
  __ZNKSs9_M_ibeginEv(local_30,i1);
  iVar1 = param_3 - local_30[0];
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S1_S1_)(i1,param_3,param_3 + 1,*i1,*i1);
  *(undefined4 *)(*i1 + -4) = 0xffffffff;
  __ZNKSs9_M_ibeginEv(local_30,i1);
  *this = local_30[0] + iVar1;
  return this;
}

/* __ZNSs5eraseEN9__gnu_cxx17__normal_iteratorIPcSsEES2_ @ 0x97c15274 (132 bytes) */
int __ZNSs5eraseEN9__gnu_cxx17__normal_iteratorIPcSsEES2_(this, i1, param_3, param_4)
  int *this;
  int *i1;
  int param_3;
  undefined4 param_4;
{
  int iVar1;
  int local_30 [6];
  
  __ZNKSs9_M_ibeginEv(local_30,i1);
  iVar1 = param_3 - local_30[0];
  ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S1_S1_)(i1,param_3,param_4,*i1,*i1);
  *(undefined4 *)(*i1 + -4) = 0xffffffff;
  __ZNKSs9_M_ibeginEv(local_30,i1);
  *this = local_30[0] + iVar1;
  return this;
}

/* __ZNSs7replaceEmmRKSs @ 0x97c152f8 (12 bytes) */
int __ZNSs7replaceEmmRKSs(this, pos1, n1, text)
  void *this;
  ulong pos1;
  ulong n1;
  unsigned char * text;
{
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,pos1,n1,*(char **)text,*(ulong *)(*(char **)text + -0xc))
  ;
  return;
}

/* __ZNSs7replaceEmmRKSsmm @ 0x97c15304 (136 bytes) */
int __ZNSs7replaceEmmRKSsmm(this, pos1, n1, text, pos2, n2)
  void *this;
  ulong pos1;
  ulong n1;
  unsigned char * text;
  ulong pos2;
  ulong n2;
{
  uint repLength;
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)text;
  repLength = *(uint *)(iVar1 + -0xc);
  if (repLength < pos2) {
    std____throw_out_of_range("basic_string::replace");
    iVar1 = *(int *)text;
  }
  uVar2 = repLength - pos2;
  if (uVar2 <= n2) {
    n2 = uVar2;
  }
  return ((int (*)())__ZNSs7replaceEmmPKcm)(this,pos1,n1,(char *)(iVar1 + pos2),n2);
}

/* __ZNSs7replaceEmmPKc @ 0x97c1538c (80 bytes) */
int __ZNSs7replaceEmmPKc(this, pos1, n1, str)
  void *this;
  ulong pos1;
  ulong n1;
  char *str;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNSs7replaceEmmPKcm)(this,pos1,n1,str,length);
}

/* __ZNSs7replaceEmmmc @ 0x97c153dc (120 bytes) */
int __ZNSs7replaceEmmmc(this, pos1, n1, pos2, c)
  void *this;
  ulong pos1;
  ulong n1;
  ulong pos2;
  undefined4 c;
{
  undefined4 local_30;
  undefined4 local_2c [4];
  
  std__string___M_check((ulong)&local_30,this,pos1);
  __ZNKSs7_M_foldEmm((ulong)local_2c,(ulong)this,pos1,n1);
  return ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc)(this,local_30,local_2c[0],pos2,c);
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcm @ 0x97c15454 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcm(this, i1, param_3, str, charPtr)
  void *this;
  int i1;
  int param_3;
  char *str;
  ulong charPtr;
{
  int local_30 [5];
  
  __ZNKSs9_M_ibeginEv(local_30,this);
  return ((int (*)())__ZNSs7replaceEmmPKcm)(this,i1 - local_30[0],param_3 - i1,str,charPtr);
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_RKSs @ 0x97c154b4 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_RKSs(this, i1, param_3, text)
  void *this;
  int i1;
  int param_3;
  undefined4 *text;
{
  char *pcVar1;
  ulong repLength;
  int local_30 [5];
  
  pcVar1 = (char *)*text;
  repLength = *(ulong *)(pcVar1 + -0xc);
  __ZNKSs9_M_ibeginEv(local_30,this);
  return ((int (*)())__ZNSs7replaceEmmPKcm)(this,i1 - local_30[0],param_3 - i1,pcVar1,repLength);
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKc @ 0x97c15514 (80 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKc(this, i1, param_3, str)
  void *this;
  undefined4 i1;
  undefined4 param_3;
  undefined4 str;
{
  undefined4 length;
  
  length = _strlen(str);
  return ((int (*)())__ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcm)(this,i1,param_3,str,length);
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc @ 0x97c15564 (180 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_mc(this, i1, param_3, param_4, pos1)
  void *this;
  int i1;
  int param_3;
  uint param_4;
  undefined4 pos1;
{
  int local_30 [6];
  
  __ZNKSs9_M_ibeginEv(local_30,this);
  if (0x3ffffffcU - (*(int *)(*(int *)this + -0xc) - (param_3 - i1)) <= param_4) {
    std____throw_length_error("basic_string::replace");
  }
  __ZNSs9_M_mutateEmmm(this,i1 - local_30[0],param_3 - i1,param_4);
  if (param_4 != 0) {
    _memset(*(int *)this + (i1 - local_30[0]),pos1,param_4);
  }
  return this;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcS4_ @ 0x97c15618 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcS4_(this, i1, param_3, str1, str2)
  void *this;
  int i1;
  int param_3;
  char *str1;
  int str2;
{
  int local_30 [5];
  
  __ZNKSs9_M_ibeginEv(local_30,this);
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,i1 - local_30[0],param_3 - i1,str1,str2 - (int)str1)
  ;
  return;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S2_S2_ @ 0x97c15678 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_S2_S2_(this, i1, param_3, str, param_5)
  void *this;
  int i1;
  int param_3;
  char *str;
  int param_5;
{
  int local_30 [5];
  
  __ZNKSs9_M_ibeginEv(local_30,this);
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,i1 - local_30[0],param_3 - i1,str,param_5 - (int)str)
  ;
  return;
}

/* __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_NS0_IPKcSsEES5_ @ 0x97c156d8 (96 bytes) */
int __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_NS0_IPKcSsEES5_(this, i1, param_3, str, param_5)
  void *this;
  int i1;
  int param_3;
  char *str;
  int param_5;
{
  int local_30 [5];
  
  __ZNKSs9_M_ibeginEv(local_30,this);
  ((int (*)())__ZNSs7replaceEmmPKcm)(this,i1 - local_30[0],param_3 - i1,str,param_5 - (int)str)
  ;
  return;
}

/* std__string___S_construct @ 0x97c15738 (140 bytes) */
int std__string___S_construct(this, param_2, param_3)
  ulong this;
  undefined4 param_2;
  unsigned char * param_3;
{
  ulong *puVar1;
  ulong *puVar2;
  char reservation;
  
  if (this == 0) {
    if (reservation != '\0') {
      DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
    }
    puVar1 = (ulong *)&DAT_a7b7bf90;
  }
  else {
    puVar2 = (ulong *)__ZNSs4_Rep9_S_createEmRKSaIcE(this,param_3);
    puVar1 = puVar2 + 3;
    _memset(puVar1,param_2,this);
    *puVar2 = this;
    *(undefined1 *)((int)puVar1 + this) = 0;
  }
  return puVar1;
}

/* std__string__copy @ 0x97c157c4 (132 bytes) */
int std__string__copy(this, str, param_3, param_4)
  unsigned char * this;
  char *str;
  ulong param_3;
  ulong param_4;
{
  uint uVar1;
  int data;
  
  data = *(int *)this;
  if (*(uint *)(data + -0xc) < param_4) {
    std____throw_out_of_range("basic_string::copy");
    data = *(int *)this;
  }
  uVar1 = *(int *)(data + -0xc) - param_4;
  if (uVar1 < param_3) {
    param_3 = uVar1;
  }
  _memcpy(str,data + param_4,param_3);
  return param_3;
}

/* __ZNSs4swapERSs @ 0x97c15848 (140 bytes) */
int __ZNSs4swapERSs(this, text)
  void *this;
  unsigned char * text;
{
  undefined4 data;
  
  if (*(int *)(*(int *)this + -4) < 0) {
    *(undefined4 *)(*(int *)this + -4) = 0;
  }
  if (*(int *)(*(int *)text + -4) < 0) {
    *(undefined4 *)(*(int *)text + -4) = 0;
  }
  __ZNKSs13get_allocatorEv();
  __ZNKSs13get_allocatorEv();
  data = *(undefined4 *)this;
  *(undefined4 *)this = *(undefined4 *)text;
  *(undefined4 *)text = data;
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
int __ZNKSs4findEPKcmm(this, str, pos, n)
  void *this;
  char *str;
  ulong pos;
  ulong n;
{
  uint uVar1;
  int compareResult;
  uint uVar3;
  int iVar4;
  
  uVar1 = pos + n;
  uVar3 = *(uint *)(*(int *)this + -0xc);
  if (uVar1 <= uVar3) {
    iVar4 = pos + *(int *)this;
    do {
      compareResult = _memcmp(iVar4,str,n);
      if (compareResult == 0) {
        return pos;
      }
      uVar1 = uVar1 + 1;
      pos = pos + 1;
      iVar4 = iVar4 + 1;
    } while (uVar1 <= uVar3);
  }
  return 0xffffffff;
}

/* __ZNKSs4findERKSsm @ 0x97c1598c (12 bytes) */
int __ZNKSs4findERKSsm(this, text, pos)
  void *this;
  unsigned char * text;
  ulong pos;
{
  return ((int (*)())__ZNKSs4findEPKcmm)(this,*(char **)text,pos,*(ulong *)(*(char **)text + -0xc));
}

/* __ZNKSs4findEPKcm @ 0x97c15998 (72 bytes) */
int __ZNKSs4findEPKcm(this, str, pos)
  void *this;
  char *str;
  ulong pos;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNKSs4findEPKcmm)(this,str,pos,length);
}

/* __ZNKSs4findEcm @ 0x97c159e0 (96 bytes) */
int __ZNKSs4findEcm(this, c, pos)
  void *this;
  int c;
  ulong pos;
{
  void *memchrResult;
  int iVar2;
  int data;
  char cStack0000001c;
  
  iVar2 = -1;
  data = *(int *)this;
  if ((pos < *(uint *)(data + -0xc)) &&
     (cStack0000001c = c,
     memchrResult = _memchr((void *)(data + pos),(int)c,*(uint *)(data + -0xc) - pos),
     memchrResult != (void *)0x0)) {
    iVar2 = (int)memchrResult - data;
  }
  return iVar2;
}

/* __ZNKSs5rfindERKSsm @ 0x97c15a40 (12 bytes) */
int __ZNKSs5rfindERKSsm(this, text, pos)
  void *this;
  unsigned char * text;
  ulong pos;
{
  return ((int (*)())__ZNKSs5rfindEPKcmm)(this,*(char **)text,pos,*(ulong *)(*(char **)text + -0xc));
}

/* __ZNKSs5rfindEPKcmm @ 0x97c15a4c (148 bytes) */
int __ZNKSs5rfindEPKcmm(this, str, pos, n)
  void *this;
  char *str;
  ulong pos;
  ulong n;
{
  unsigned int ghidra_home[8] = { this, str, pos, n, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint local_30 [7];
  
  iVar4 = *(int *)this;
  local_30[0] = *(uint *)(iVar4 + -0xc);
  if (n <= local_30[0]) {
    local_30[0] = local_30[0] - n;
    puVar2 = &(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    if (local_30[0] <= pos) {
      puVar2 = local_30;
    }
    (*(uint *)((unsigned char *)ghidra_home + 8)) = *puVar2;
    do {
      uVar1 = (*(uint *)((unsigned char *)ghidra_home + 8));
      iVar3 = _memcmp(iVar4 + (*(uint *)((unsigned char *)ghidra_home + 8)),str,n);
      if (iVar3 == 0) {
        return uVar1;
      }
      (*(uint *)((unsigned char *)ghidra_home + 8)) = uVar1 - 1;
    } while ((*(uint *)((unsigned char *)ghidra_home + 8)) != 0xffffffff);
  }
  return 0xffffffff;
}

/* __ZNKSs5rfindEPKcm @ 0x97c15ae0 (72 bytes) */
int __ZNKSs5rfindEPKcm(this, str, pos)
  void *this;
  char *str;
  ulong pos;
{
  ulong length;
  
  length = _strlen(str);
  return ((int (*)())__ZNKSs5rfindEPKcmm)(this,str,pos,length);
}

