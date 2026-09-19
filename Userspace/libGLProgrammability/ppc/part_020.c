#include "decls.h"

/* std__string___M_leak @ 0x97c132b0 (20 bytes) */
int std__string___M_leak(this)
  unsigned char * this;
{
  if (*(int *)(*(int *)this + -4) < 0) {
    return;
  }
  ((int (*)())std__string___M_leak_hard)(this);
  return;
}

/* std__string___M_check @ 0x97c132c4 (112 bytes) */
int std__string___M_check(param_1)
  ulong param_1;
{
  int *in_r4;
  uint in_r5;
  int local_20;
  
  if (*(uint *)(*in_r4 + -0xc) < in_r5) {
    std____throw_out_of_range("basic_string___M_check");
  }
  std__string___M_ibegin();
  *(uint *)param_1 = local_20 + in_r5;
  return param_1;
}

/* std__string___M_fold @ 0x97c13334 (100 bytes) */
int std__string___M_fold(param_1, param_2)
  ulong param_1;
  ulong param_2;
{
  uint uVar1;
  int in_r5;
  uint in_r6;
  undefined4 local_20;
  
  uVar1 = *(int *)(*(int *)param_2 + -0xc) - in_r5;
  if (uVar1 <= in_r6) {
    in_r6 = uVar1;
  }
  std__string___M_ibegin();
  *(uint *)param_1 = local_20 + in_r5 + in_r6;
  return param_1;
}

/* std__string___S_copy_chars @ 0x97c13398 (36 bytes) */
int std__string___S_copy_chars(param_1, param_2, param_3)
  char *param_1;
  char *param_2;
  char *param_3;
{
  _memcpy(param_1,param_2,(int)param_3 - (int)param_2);
  return;
}

/* std__string___S_copy_chars_97c133bc @ 0x97c133bc (36 bytes) */
int std__string___S_copy_chars_97c133bc(param_1, param_2, param_3)
  void *param_1;
  void *param_2;
  int param_3;
{
  _memcpy(param_1,param_2,param_3 - (int)param_2);
  return;
}

/* std__string___S_copy_chars_97c133e0 @ 0x97c133e0 (36 bytes) */
int std__string___S_copy_chars_97c133e0(param_1, param_2, param_3)
  char *param_1;
  char *param_2;
  char *param_3;
{
  _memcpy(param_1,param_2,(int)param_3 - (int)param_2);
  return;
}

/* std__string___S_copy_chars_97c13404 @ 0x97c13404 (36 bytes) */
int std__string___S_copy_chars_97c13404(param_1, param_2, param_3)
  void *param_1;
  void *param_2;
  int param_3;
{
  _memcpy(param_1,param_2,param_3 - (int)param_2);
  return;
}

/* std__string___Rep___M_is_shared @ 0x97c13428 (24 bytes) */
int std__string___Rep___M_is_shared(this)
  unsigned char * this;
{
  if (0 < *(int *)(this + 8)) {
    return 1;
  }
  return 0;
}

/* std__string__capacity @ 0x97c13440 (12 bytes) */
int std__string__capacity(this)
  unsigned char * this;
{
  return *(undefined4 *)(*(int *)this + -8);
}

/* std__string__get_allocator @ 0x97c1344c (4 bytes) */
int std__string__get_allocator()
{
  return;
}

/* std__string___Rep___M_refdata @ 0x97c13450 (8 bytes) */
int std__string___Rep___M_refdata(this)
  unsigned char * this;
{
  return this + 0xc;
}

/* std__string___Rep___M_dispose @ 0x97c13458 (32 bytes) */
int std__string___Rep___M_dispose(param_1)
  unsigned char * param_1;
{
  int iVar1;
  unsigned char * paVar2;
  int iVar3;
  char in_RESERVE;
  byte in_cr0;
  
  paVar2 = param_1 + 8;
  do {
    iVar3 = *(int *)paVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,paVar2);
      *(int *)paVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (0 < iVar3) {
    return;
  }
  _M_destroy(param_1);
  return;
}

/* std__string___Rep___M_set_sharable @ 0x97c13478 (12 bytes) */
int std__string___Rep___M_set_sharable(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 8) = 0;
  return;
}

/* std__string___M_mutate @ 0x97c13484 (340 bytes) */
int std__string___M_mutate(this, param_1, param_2, param_3)
  unsigned char * this;
  ulong param_1;
  ulong param_2;
  ulong param_3;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  void *pvVar8;
  size_t sVar9;
  uint uVar10;
  char in_RESERVE;
  byte in_cr0;
  unsigned char aaStack_40 [32];
  
  pvVar5 = *(void **)this;
  pvVar8 = (void *)((int)pvVar5 + param_2 + param_1);
  sVar9 = (*(int *)((int)pvVar5 + -0xc) - param_1) - param_2;
  uVar10 = (*(int *)((int)pvVar5 + -0xc) + param_3) - param_2;
  if (*(int *)((int)pvVar5 + -4) < 1) {
    uVar2 = *(uint *)((int)pvVar5 + -8);
    if (uVar10 <= uVar2) {
      if ((sVar9 != 0) && (param_2 != param_3)) {
        _memmove((void *)((int)pvVar5 + param_3 + param_1),pvVar8,sVar9);
        pvVar5 = *(void **)this;
      }
      goto LAB_97c135b0;
    }
  }
  else {
    uVar2 = *(uint *)((int)pvVar5 + -8);
  }
  uVar6 = uVar10;
  if (((uVar2 < uVar10) && (0xfe3 < uVar10)) && (uVar6 = uVar2 << 1, uVar2 << 1 < uVar10)) {
    uVar6 = uVar10;
  }
  iVar7 = _Rep___S_create(uVar6,aaStack_40);
  pvVar5 = (void *)(iVar7 + 0xc);
  if (param_1 != 0) {
    _memcpy(pvVar5,*(void **)this,param_1);
  }
  if (sVar9 != 0) {
    _memcpy((void *)((int)pvVar5 + param_3 + param_1),pvVar8,sVar9);
  }
  iVar7 = *(int *)this;
  piVar3 = (int *)(iVar7 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar4 < 1) {
    _Rep___M_destroy((unsigned char *)(iVar7 + -0xc));
  }
  *(void **)this = pvVar5;
LAB_97c135b0:
  *(undefined4 *)((int)pvVar5 + -4) = 0;
  *(uint *)(*(int *)this + -0xc) = uVar10;
  *(undefined1 *)(*(int *)this + uVar10) = 0;
  return;
}

/* std__string___Rep___M_set_leaked @ 0x97c135dc (12 bytes) */
int std__string___Rep___M_set_leaked(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 8) = 0xffffffff;
  return;
}

/* std__string___M_leak_hard @ 0x97c135e8 (84 bytes) */
int std__string___M_leak_hard(this)
  unsigned char * this;
{
  int iVar1;
  
  iVar1 = *(int *)this;
  if (0 < *(int *)(iVar1 + -4)) {
    _M_mutate(this,0,0,0);
    iVar1 = *(int *)this;
  }
  *(undefined4 *)(iVar1 + -4) = 0xffffffff;
  return;
}

/* std__string___S_empty_rep @ 0x97c1363c (28 bytes) */
int std__string___S_empty_rep()
{
  return &_S_empty_rep_storage;
}

/* std__string__string @ 0x97c13658 (4 bytes) */
int std__string__string(this)
  unsigned char * this;
{
  string(this);
  return;
}

/* std__string__string_97c1365c @ 0x97c1365c (4 bytes) */
int std__string__string_97c1365c(this)
  unsigned char * this;
{
  string(this);
  return;
}

/* std__string___Alloc_hider___Alloc_hider @ 0x97c13660 (4 bytes) */
int std__string___Alloc_hider___Alloc_hider(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  unsigned char * param_2;
{
  _Alloc_hider(this,param_1,param_2);
  return;
}

/* std__string___Alloc_hider___Alloc_hider_97c13664 @ 0x97c13664 (4 bytes) */
int std__string___Alloc_hider___Alloc_hider_97c13664(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  unsigned char * param_2;
{
  _Alloc_hider(this,param_1,param_2);
  return;
}

/* std__string___Alloc_hider___Alloc_hider_97c13668 @ 0x97c13668 (8 bytes) */
int std__string___Alloc_hider___Alloc_hider_97c13668(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  unsigned char * param_2;
{
  *(char **)this = param_1;
  return;
}

/* std__string___Rep___M_refcopy @ 0x97c13670 (28 bytes) */
int std__string___Rep___M_refcopy(this)
  unsigned char * this;
{
  int iVar1;
  unsigned char * p_Var2;
  char in_RESERVE;
  byte in_cr0;
  
  p_Var2 = this + 8;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*(int *)p_Var2 + 1,0,p_Var2);
      *(int *)p_Var2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  return this + 0xc;
}

/* std__string__string_97c1368c @ 0x97c1368c (84 bytes) */
int std__string__string_97c1368c(this)
  unsigned char * this;
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
  _Alloc_hider___Alloc_hider((unsigned char *)this,&DAT_a7b7bf90,aaStack_20);
  return;
}

/* std__string__string_97c136e0 @ 0x97c136e0 (4 bytes) */
int std__string__string_97c136e0(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  string(this,param_1);
  return;
}

/* std__string__string_97c136e4 @ 0x97c136e4 (4 bytes) */
int std__string__string_97c136e4(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  string(this,param_1);
  return;
}

/* std__string__string_97c136e8 @ 0x97c136e8 (76 bytes) */
int std__string__string_97c136e8(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  char *pcVar1;
  
  pcVar1 = (char *)std__string___S_construct(0,'\0',param_1);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar1,param_1);
  return;
}

/* std__string__string_97c13734 @ 0x97c13734 (4 bytes) */
int std__string__string_97c13734(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  string(this,param_1);
  return;
}

/* std__string__string_97c13738 @ 0x97c13738 (4 bytes) */
int std__string__string_97c13738(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  char in_RESERVE;
  byte in_cr0;
  unsigned char aaStack_50 [32];
  unsigned char aaStack_30 [28];
  
  pcVar3 = *(char **)param_1;
  ((int (*)())std__string__get_allocator)();
  if (*(int *)(pcVar3 + -4) < 0) {
    pcVar3 = (char *)_Rep___M_clone((unsigned char *)(pcVar3 + -0xc),aaStack_50,0);
  }
  else {
    piVar2 = (int *)(pcVar3 + -4);
    do {
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
  }
  ((int (*)())std__string__get_allocator)();
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar3,aaStack_30);
  return;
}

/* std__string___Rep___M_grab @ 0x97c1373c (48 bytes) */
int std__string___Rep___M_grab(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  int iVar1;
  unsigned char * paVar2;
  char in_RESERVE;
  byte in_cr0;
  
  if (*(int *)(param_1 + 8) < 0) {
    paVar2 = (unsigned char *)_M_clone((unsigned char *)param_1,param_2,0);
    return paVar2;
  }
  paVar2 = param_1 + 8;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*(int *)paVar2 + 1,0,paVar2);
      *(int *)paVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  return param_1 + 0xc;
}

/* std__string__string_97c1376c @ 0x97c1376c (152 bytes) */
int std__string__string_97c1376c(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  char in_RESERVE;
  byte in_cr0;
  unsigned char aaStack_50 [32];
  unsigned char aaStack_30 [28];
  
  pcVar3 = *(char **)param_1;
  ((int (*)())std__string__get_allocator)();
  if (*(int *)(pcVar3 + -4) < 0) {
    pcVar3 = (char *)_Rep___M_clone((unsigned char *)(pcVar3 + -0xc),aaStack_50,0);
  }
  else {
    piVar2 = (int *)(pcVar3 + -4);
    do {
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
  }
  ((int (*)())std__string__get_allocator)();
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar3,aaStack_30);
  return;
}

/* std__string__string_97c13808 @ 0x97c13808 (4 bytes) */
int std__string__string_97c13808(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
  ulong param_3;
{
  string(this,param_1,param_2,param_3);
  return;
}

/* std__string__string_97c1380c @ 0x97c1380c (4 bytes) */
int std__string__string_97c1380c(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
  ulong param_3;
{
  char *pcVar1;
  undefined1 auStack_50 [4];
  undefined4 auStack_4c [3];
  undefined1 auStack_40 [16];
  unsigned char aaStack_30 [24];
  
  ((int (*)())std__string___M_check)((ulong)auStack_50);
  ((int (*)())std__string___M_fold)((ulong)auStack_4c,(ulong)param_1);
  pcVar1 = _S_construct___gnu_cxx____normal_iterator_char__std__string__
                     (auStack_4c,auStack_4c[0],auStack_40,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar1,aaStack_30);
  return;
}

/* std__string__string_97c13810 @ 0x97c13810 (120 bytes) */
int std__string__string_97c13810(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
  ulong param_3;
{
  char *pcVar1;
  undefined1 local_50 [4];
  undefined4 local_4c [3];
  undefined1 auStack_40 [16];
  unsigned char aaStack_30 [24];
  
  ((int (*)())std__string___M_check)((ulong)local_50);
  ((int (*)())std__string___M_fold)((ulong)local_4c,(ulong)param_1);
  pcVar1 = _S_construct___gnu_cxx____normal_iterator_char__std__string__
                     (local_4c,local_4c[0],auStack_40,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar1,aaStack_30);
  return;
}

/* std__string__string_97c1388c @ 0x97c1388c (4 bytes) */
int std__string__string_97c1388c(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
  ulong param_3;
  unsigned char * param_4;
{
  string(this,param_1,param_2,param_3,param_4);
  return;
}

/* std__string__string_97c13890 @ 0x97c13890 (4 bytes) */
int std__string__string_97c13890(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
  ulong param_3;
  unsigned char * param_4;
{
  string(this,param_1,param_2,param_3,param_4);
  return;
}

/* std__string__string_97c13894 @ 0x97c13894 (124 bytes) */
int std__string__string_97c13894(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
  ulong param_3;
  unsigned char * param_4;
{
  char *pcVar1;
  undefined1 local_30 [4];
  undefined4 local_2c [4];
  
  ((int (*)())std__string___M_check)((ulong)local_30);
  ((int (*)())std__string___M_fold)((ulong)local_2c,(ulong)param_1);
  pcVar1 = _S_construct___gnu_cxx____normal_iterator_char__std__string__
                     (local_2c,local_2c[0],param_4,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar1,param_4);
  return;
}

/* std__string__string_97c13910 @ 0x97c13910 (4 bytes) */
int std__string__string_97c13910(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  ulong param_2;
  unsigned char * param_3;
{
  string(this,param_1,param_2,param_3);
  return;
}

/* std__string__string_97c13914 @ 0x97c13914 (4 bytes) */
int std__string__string_97c13914(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  ulong param_2;
  unsigned char * param_3;
{
  string(this,param_1,param_2,param_3);
  return;
}

/* std__string__string_97c13918 @ 0x97c13918 (80 bytes) */
int std__string__string_97c13918(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  ulong param_2;
  unsigned char * param_3;
{
  char *pcVar1;
  
  pcVar1 = _S_construct_char_const__(this,param_1 + param_2,param_3,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar1,param_3);
  return;
}

/* std__string__string_97c13968 @ 0x97c13968 (4 bytes) */
int std__string__string_97c13968(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  unsigned char * param_2;
{
  unsigned char * psVar1;
  char *pcVar2;
  
  if (param_1 == (char *)0x0) {
    pcVar2 = (char *)0xffffffff;
    psVar1 = this;
  }
  else {
    psVar1 = (unsigned char *)_strlen(param_1);
    pcVar2 = param_1 + (int)psVar1;
  }
  pcVar2 = _S_construct_char_const__(psVar1,pcVar2,param_2,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar2,param_2);
  return;
}

/* std__string__string_97c1396c @ 0x97c1396c (4 bytes) */
int std__string__string_97c1396c(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  unsigned char * param_2;
{
  unsigned char * psVar1;
  char *pcVar2;
  
  if (param_1 == (char *)0x0) {
    pcVar2 = (char *)0xffffffff;
    psVar1 = this;
  }
  else {
    psVar1 = (unsigned char *)_strlen(param_1);
    pcVar2 = param_1 + (int)psVar1;
  }
  pcVar2 = _S_construct_char_const__(psVar1,pcVar2,param_2,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar2,param_2);
  return;
}

/* std__string__string_97c13970 @ 0x97c13970 (104 bytes) */
int std__string__string_97c13970(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  unsigned char * param_2;
{
  unsigned char * psVar1;
  char *pcVar2;
  
  if (param_1 == (char *)0x0) {
    pcVar2 = (char *)0xffffffff;
    psVar1 = this;
  }
  else {
    psVar1 = (unsigned char *)_strlen(param_1);
    pcVar2 = param_1 + (int)psVar1;
  }
  pcVar2 = _S_construct_char_const__(psVar1,pcVar2,param_2,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar2,param_2);
  return;
}

/* std__string__string_97c139d8 @ 0x97c139d8 (4 bytes) */
int std__string__string_97c139d8(this, param_1, param_2, param_3)
  unsigned char * this;
  ulong param_1;
  int param_2;
  unsigned char * param_3;
{
  string(this,param_1,param_2,param_3);
  return;
}

/* std__string__string_97c139dc @ 0x97c139dc (4 bytes) */
int std__string__string_97c139dc(this, param_1, param_2, param_3)
  unsigned char * this;
  ulong param_1;
  int param_2;
  unsigned char * param_3;
{
  string(this,param_1,param_2,param_3);
  return;
}

/* std__string__string_97c139e0 @ 0x97c139e0 (76 bytes) */
int std__string__string_97c139e0(this, param_1, param_2, param_3)
  unsigned char * this;
  ulong param_1;
  int param_2;
  unsigned char * param_3;
{
  char *pcVar1;
  
  pcVar1 = (char *)std__string___S_construct(param_1,param_2,param_3);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar1,param_3);
  return;
}

/* std__string___string @ 0x97c13a2c (8 bytes) */
int std__string___string(this)
  unsigned char * this;
{
  ~string(this);
  return;
}

/* std__string___string_97c13a34 @ 0x97c13a34 (8 bytes) */
int std__string___string_97c13a34(this)
  unsigned char * this;
{
  ~string(this);
  return;
}

/* std__string___string_97c13a3c @ 0x97c13a3c (92 bytes) */
int std__string___string_97c13a3c(this)
  unsigned char * this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  iVar4 = *(int *)this;
  ((int (*)())std__string__get_allocator)();
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
    _Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
  }
  return;
}

/* std__string__operator_ @ 0x97c13a98 (4 bytes) */
int std__string__operator_(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
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
  unsigned char * this;
  char *param_1;
  ulong param_2;
{
  unsigned char * psVar1;
  undefined4 local_30;
  undefined4 local_2c;
  
  if (0x3ffffffc < param_2) {
    std____throw_length_error("basic_string__assign");
  }
  psVar1 = *(unsigned char **)this;
  if (((0 < *(int *)(psVar1 + -4)) || (param_1 < psVar1)) ||
     (psVar1 + *(int *)(psVar1 + -0xc) < param_1)) {
    std__string___M_ibegin();
    std__string___M_iend();
    psVar1 = _M_replace_safe_char_const__(psVar1,local_30,local_2c,param_1,param_1 + param_2);
    return psVar1;
  }
  if ((uint)((int)param_1 - (int)psVar1) < param_2) {
    if ((unsigned char *)param_1 == psVar1) goto LAB_97c13b7c;
    _memmove(psVar1,param_1,param_2);
  }
  else {
    _memcpy(psVar1,param_1,param_2);
  }
  psVar1 = *(unsigned char **)this;
LAB_97c13b7c:
  *(ulong *)(psVar1 + -0xc) = param_2;
  *(undefined1 *)(*(int *)this + param_2) = 0;
  return this;
}

/* std__string__assign_97c13ba4 @ 0x97c13ba4 (260 bytes) */
int std__string__assign_97c13ba4(this, param_1)
  unsigned char * this;
  char *param_1;
{
  size_t sVar1;
  unsigned char * psVar2;
  undefined4 local_30;
  undefined4 local_2c;
  
  sVar1 = _strlen(param_1);
  if (0x3ffffffc < sVar1) {
    std____throw_length_error("basic_string__assign");
  }
  psVar2 = *(unsigned char **)this;
  if (((0 < *(int *)(psVar2 + -4)) || (param_1 < psVar2)) ||
     (psVar2 + *(int *)(psVar2 + -0xc) < param_1)) {
    std__string___M_ibegin();
    std__string___M_iend();
    psVar2 = _M_replace_safe_char_const__(psVar2,local_30,local_2c,param_1,param_1 + sVar1);
    return psVar2;
  }
  if ((uint)((int)param_1 - (int)psVar2) < sVar1) {
    if ((unsigned char *)param_1 == psVar2) goto LAB_97c13c80;
    _memmove(psVar2,param_1,sVar1);
  }
  else {
    _memcpy(psVar2,param_1,sVar1);
  }
  psVar2 = *(unsigned char **)this;
LAB_97c13c80:
  *(size_t *)(psVar2 + -0xc) = sVar1;
  *(undefined1 *)(*(int *)this + sVar1) = 0;
  return this;
}

/* std__string__operator__97c13ca8 @ 0x97c13ca8 (260 bytes) */
int std__string__operator__97c13ca8(this, param_1)
  unsigned char * this;
  char *param_1;
{
  size_t sVar1;
  unsigned char * psVar2;
  undefined4 local_30;
  undefined4 local_2c;
  
  sVar1 = _strlen(param_1);
  if (0x3ffffffc < sVar1) {
    std____throw_length_error("basic_string__assign");
  }
  psVar2 = *(unsigned char **)this;
  if (((0 < *(int *)(psVar2 + -4)) || (param_1 < psVar2)) ||
     (psVar2 + *(int *)(psVar2 + -0xc) < param_1)) {
    std__string___M_ibegin();
    std__string___M_iend();
    psVar2 = _M_replace_safe_char_const__(psVar2,local_30,local_2c,param_1,param_1 + sVar1);
    return psVar2;
  }
  if ((uint)((int)param_1 - (int)psVar2) < sVar1) {
    if ((unsigned char *)param_1 == psVar2) goto LAB_97c13d84;
    _memmove(psVar2,param_1,sVar1);
  }
  else {
    _memcpy(psVar2,param_1,sVar1);
  }
  psVar2 = *(unsigned char **)this;
LAB_97c13d84:
  *(size_t *)(psVar2 + -0xc) = sVar1;
  *(undefined1 *)(*(int *)this + sVar1) = 0;
  return this;
}

/* std__string__assign_97c13dac @ 0x97c13dac (100 bytes) */
int std__string__assign_97c13dac(this, param_1, param_2)
  unsigned char * this;
  ulong param_1;
  int param_2;
{
  undefined3 in_register_00000014;
  undefined4 local_30;
  undefined4 local_2c;
  
  std__string___M_ibegin();
  std__string___M_iend();
  replace(this,local_30,local_2c,param_1,CONCAT31(in_register_00000014,param_2));
  return;
}

/* std__string__operator__97c13e10 @ 0x97c13e10 (96 bytes) */
int std__string__operator__97c13e10(this, param_1)
  unsigned char * this;
  int param_1;
{
  undefined3 in_register_00000010;
  undefined4 local_30;
  undefined4 local_2c;
  
  std__string___M_ibegin();
  std__string___M_iend();
  replace(this,local_30,local_2c,1,CONCAT31(in_register_00000010,param_1));
  return;
}

/* std__string__begin @ 0x97c13e70 (64 bytes) */
int std__string__begin()
{
  undefined4 *in_r3;
  unsigned char * in_r4;
  
  ((int (*)())std__string___M_leak)(in_r4);
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
  unsigned char * in_r4;
  
  ((int (*)())std__string___M_leak)(in_r4);
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

