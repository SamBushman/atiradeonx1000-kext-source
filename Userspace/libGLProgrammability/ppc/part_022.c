#include "decls.h"

/* __ZNKSs5rfindEcm @ 0x97c15b28 (92 bytes) */
int __ZNKSs5rfindEcm(this, param_2, param_3)
  void *this;
  int param_2;
  ulong param_3;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(*(int *)this + -0xc);
  if (iVar2 != 0) {
    uVar3 = iVar2 - 1;
    if (param_3 < uVar3) {
      uVar3 = param_3;
    }
    if (uVar3 != 0xffffffff) {
      do {
        if (*(char *)(*(int *)this + uVar3) == param_2) {
          return uVar3;
        }
        bVar1 = uVar3 != 0;
        uVar3 = uVar3 - 1;
      } while (bVar1);
    }
  }
  return 0xffffffff;
}

/* __ZNKSs13find_first_ofERKSsm @ 0x97c15b84 (12 bytes) */
int __ZNKSs13find_first_ofERKSsm(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  ulong param_3;
{
  ((int (*)())__ZNKSs13find_first_ofEPKcmm)(this,*(char **)param_2,param_3,*(ulong *)(*(char **)param_2 + -0xc));
  return;
}

/* __ZNKSs13find_first_ofEPKcmm @ 0x97c15b90 (152 bytes) */
int __ZNKSs13find_first_ofEPKcmm(this, param_2, param_3, param_4)
  void *this;
  char *param_2;
  ulong param_3;
  ulong param_4;
{
  int iVar1;
  void *pvVar2;
  
  if ((param_4 != 0) && (iVar1 = *(int *)this, param_3 < *(uint *)(iVar1 + -0xc))) {
    do {
      pvVar2 = _memchr(param_2,(int)*(char *)(iVar1 + param_3),param_4);
      if (pvVar2 != (void *)0x0) {
        return param_3;
      }
      param_3 = param_3 + 1;
      iVar1 = *(int *)this;
    } while (param_3 < *(uint *)(iVar1 + -0xc));
  }
  return 0xffffffff;
}

/* __ZNKSs13find_first_ofEPKcm @ 0x97c15c28 (72 bytes) */
int __ZNKSs13find_first_ofEPKcm(this, param_2, param_3)
  void *this;
  char *param_2;
  ulong param_3;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_2);
  ((int (*)())__ZNKSs13find_first_ofEPKcmm)(this,param_2,param_3,sVar1);
  return;
}

/* __ZNKSs13find_first_ofEcm @ 0x97c15c70 (4 bytes) */
int __ZNKSs13find_first_ofEcm(this, param_2, param_3)
  void *this;
  int param_2;
  ulong param_3;
{
  __ZNKSs4findEcm(this,param_2,param_3);
  return;
}

/* __ZNKSs12find_last_ofERKSsm @ 0x97c15c74 (12 bytes) */
int __ZNKSs12find_last_ofERKSsm(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  ulong param_3;
{
  ((int (*)())__ZNKSs12find_last_ofEPKcmm)(this,*(char **)param_2,param_3,*(ulong *)(*(char **)param_2 + -0xc));
  return;
}

/* __ZNKSs12find_last_ofEPKcmm @ 0x97c15c80 (144 bytes) */
int __ZNKSs12find_last_ofEPKcmm(this, param_2, param_3, param_4)
  void *this;
  char *param_2;
  ulong param_3;
  ulong param_4;
{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  
  iVar2 = *(int *)this;
  if ((*(int *)(iVar2 + -0xc) == 0) || (param_4 == 0)) {
LAB_97c15cf8:
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = *(int *)(iVar2 + -0xc) - 1;
    if (param_3 < uVar4) {
      uVar4 = param_3;
    }
    while (pvVar3 = _memchr(param_2,(int)*(char *)(iVar2 + uVar4),param_4), pvVar3 == (void *)0x0) {
      bVar1 = uVar4 == 0;
      uVar4 = uVar4 - 1;
      if (bVar1) goto LAB_97c15cf8;
      iVar2 = *(int *)this;
    }
  }
  return uVar4;
}

/* __ZNKSs12find_last_ofEPKcm @ 0x97c15d10 (72 bytes) */
int __ZNKSs12find_last_ofEPKcm(this, param_2, param_3)
  void *this;
  char *param_2;
  ulong param_3;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_2);
  ((int (*)())__ZNKSs12find_last_ofEPKcmm)(this,param_2,param_3,sVar1);
  return;
}

/* __ZNKSs12find_last_ofEcm @ 0x97c15d58 (4 bytes) */
int __ZNKSs12find_last_ofEcm(this, param_2, param_3)
  void *this;
  int param_2;
  ulong param_3;
{
  ((int (*)())__ZNKSs5rfindEcm)(this,param_2,param_3);
  return;
}

/* __ZNKSs17find_first_not_ofERKSsm @ 0x97c15d5c (12 bytes) */
int __ZNKSs17find_first_not_ofERKSsm(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  ulong param_3;
{
  ((int (*)())__ZNKSs17find_first_not_ofEPKcmm)(this,*(char **)param_2,param_3,*(ulong *)(*(char **)param_2 + -0xc));
  return;
}

/* __ZNKSs17find_first_not_ofEPKcmm @ 0x97c15d68 (124 bytes) */
int __ZNKSs17find_first_not_ofEPKcmm(this, param_2, param_3, param_4)
  void *this;
  char *param_2;
  ulong param_3;
  ulong param_4;
{
  int iVar1;
  void *pvVar2;
  
  iVar1 = *(int *)this;
  if (param_3 < *(uint *)(iVar1 + -0xc)) {
    do {
      pvVar2 = _memchr(param_2,(int)*(char *)(iVar1 + param_3),param_4);
      if (pvVar2 == (void *)0x0) {
        return param_3;
      }
      iVar1 = *(int *)this;
      param_3 = param_3 + 1;
    } while (param_3 < *(uint *)(iVar1 + -0xc));
  }
  return 0xffffffff;
}

/* __ZNKSs17find_first_not_ofEPKcm @ 0x97c15de4 (72 bytes) */
int __ZNKSs17find_first_not_ofEPKcm(this, param_2, param_3)
  void *this;
  char *param_2;
  ulong param_3;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_2);
  ((int (*)())__ZNKSs17find_first_not_ofEPKcmm)(this,param_2,param_3,sVar1);
  return;
}

/* __ZNKSs17find_first_not_ofEcm @ 0x97c15e2c (68 bytes) */
int __ZNKSs17find_first_not_ofEcm(this, param_2, param_3)
  void *this;
  int param_2;
  ulong param_3;
{
  while( true ) {
    if (*(uint *)(*(int *)this + -0xc) <= param_3) {
      return 0xffffffff;
    }
    if (*(char *)(*(int *)this + param_3) != param_2) break;
    param_3 = param_3 + 1;
  }
  return param_3;
}

/* __ZNKSs16find_last_not_ofERKSsm @ 0x97c15e70 (12 bytes) */
int __ZNKSs16find_last_not_ofERKSsm(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  ulong param_3;
{
  ((int (*)())__ZNKSs16find_last_not_ofEPKcmm)(this,*(char **)param_2,param_3,*(ulong *)(*(char **)param_2 + -0xc));
  return;
}

/* __ZNKSs16find_last_not_ofEPKcmm @ 0x97c15e7c (136 bytes) */
int __ZNKSs16find_last_not_ofEPKcmm(this, param_2, param_3, param_4)
  void *this;
  char *param_2;
  ulong param_3;
  ulong param_4;
{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  
  iVar2 = *(int *)this;
  if (*(int *)(iVar2 + -0xc) == 0) {
LAB_97c15eec:
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = *(int *)(iVar2 + -0xc) - 1;
    if (param_3 < uVar4) {
      uVar4 = param_3;
    }
    while (pvVar3 = _memchr(param_2,(int)*(char *)(iVar2 + uVar4),param_4), pvVar3 != (void *)0x0) {
      bVar1 = uVar4 == 0;
      uVar4 = uVar4 - 1;
      if (bVar1) goto LAB_97c15eec;
      iVar2 = *(int *)this;
    }
  }
  return uVar4;
}

/* __ZNKSs16find_last_not_ofEPKcm @ 0x97c15f04 (72 bytes) */
int __ZNKSs16find_last_not_ofEPKcm(this, param_2, param_3)
  void *this;
  char *param_2;
  ulong param_3;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_2);
  ((int (*)())__ZNKSs16find_last_not_ofEPKcmm)(this,param_2,param_3,sVar1);
  return;
}

/* __ZNKSs16find_last_not_ofEcm @ 0x97c15f4c (84 bytes) */
int __ZNKSs16find_last_not_ofEcm(this, param_2, param_3)
  void *this;
  int param_2;
  ulong param_3;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(*(int *)this + -0xc);
  if (iVar2 != 0) {
    uVar3 = iVar2 - 1;
    if (param_3 < uVar3) {
      uVar3 = param_3;
    }
    do {
      if (*(char *)(*(int *)this + uVar3) != param_2) {
        return uVar3;
      }
      bVar1 = uVar3 != 0;
      uVar3 = uVar3 - 1;
    } while (bVar1);
  }
  return 0xffffffff;
}

/* std__string__substr @ 0x97c15fa0 (112 bytes) */
int std__string__substr(param_1, param_2, param_3, param_4)
  ulong param_1;
  ulong param_2;
  uint param_3;
  ulong param_4;
{
  if (*(uint *)(*(int *)param_2 + -0xc) < param_3) {
    std____throw_out_of_range("basic_string::substr");
  }
  __ZNSsC1ERKSsmm((void *)param_1,(unsigned char *)param_2,param_3,param_4);
  return param_1;
}

/* __ZNKSs7compareERKSs @ 0x97c16010 (96 bytes) */
int __ZNKSs7compareERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint local_20;
  uint local_1c [4];
  
  puVar2 = local_1c;
  uVar3 = *(uint *)((int)*(void **)this + -0xc);
  local_20 = uVar3;
  uVar4 = *(uint *)((int)*(void **)param_2 + -0xc);
  local_1c[0] = uVar4;
  if (uVar3 <= uVar4) {
    puVar2 = &local_20;
  }
  iVar1 = _memcmp(*(void **)this,*(void **)param_2,*puVar2);
  if (iVar1 == 0) {
    iVar1 = uVar3 - uVar4;
  }
  return iVar1;
}

/* __ZNKSs7compareEmmRKSs @ 0x97c16070 (188 bytes) */
int __ZNKSs7compareEmmRKSs(this, param_2, param_3, param_4)
  void *this;
  ulong param_2;
  ulong param_3;
  unsigned char * param_4;
{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  ulong uStack00000020;
  uint local_30;
  uint local_2c;
  uint local_28 [5];
  
  iVar3 = *(int *)this;
  uVar5 = *(uint *)(iVar3 + -0xc);
  pvVar4 = *(void **)param_4;
  local_28[0] = *(uint *)((int)pvVar4 + -0xc);
  uStack00000020 = param_3;
  if (uVar5 < param_2) {
    std____throw_out_of_range("basic_string::compare");
    iVar3 = *(int *)this;
    pvVar4 = *(void **)param_4;
  }
  uVar1 = local_28[0];
  local_30 = uVar5 - param_2;
  puVar2 = &STACKARG(0x20);
  if (local_30 <= uStack00000020) {
    puVar2 = &local_30;
  }
  uVar5 = *puVar2;
  puVar2 = local_28;
  local_2c = uVar5;
  if (uVar5 <= local_28[0]) {
    puVar2 = &local_2c;
  }
  iVar3 = _memcmp((void *)(iVar3 + param_2),pvVar4,*puVar2);
  if (iVar3 == 0) {
    iVar3 = uVar5 - uVar1;
  }
  return iVar3;
}

/* __ZNKSs7compareEmmRKSsmm @ 0x97c1612c (240 bytes) */
int __ZNKSs7compareEmmRKSsmm(this, param_2, param_3, param_4, param_5, param_6)
  void *this;
  ulong param_2;
  ulong param_3;
  unsigned char * param_4;
  ulong param_5;
  ulong param_6;
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulong uStack00000020;
  ulong uStack0000002c;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24 [2];
  
  iVar2 = *(int *)this;
  uVar5 = *(uint *)(iVar2 + -0xc);
  iVar3 = *(int *)param_4;
  uVar4 = *(uint *)(iVar3 + -0xc);
  uStack00000020 = param_3;
  uStack0000002c = param_6;
  if ((uVar5 < param_2) || (uVar4 < param_5)) {
    std____throw_out_of_range("basic_string::compare");
    iVar2 = *(int *)this;
    iVar3 = *(int *)param_4;
  }
  local_30 = uVar5 - param_2;
  puVar1 = &STACKARG(0x20);
  if (local_30 <= uStack00000020) {
    puVar1 = &local_30;
  }
  local_2c = uVar4 - param_5;
  uVar4 = *puVar1;
  local_28 = uVar4;
  puVar1 = &STACKARG(0x2c);
  if (local_2c <= uStack0000002c) {
    puVar1 = &local_2c;
  }
  uVar5 = *puVar1;
  puVar1 = local_24;
  local_24[0] = uVar5;
  if (uVar4 <= uVar5) {
    puVar1 = &local_28;
  }
  iVar2 = _memcmp((void *)(iVar2 + param_2),(void *)(iVar3 + param_5),*puVar1);
  if (iVar2 == 0) {
    iVar2 = uVar4 - uVar5;
  }
  return iVar2;
}

/* __ZNKSs7compareEPKc @ 0x97c1621c (112 bytes) */
int __ZNKSs7compareEPKc(this, param_2)
  void *this;
  char *param_2;
{
  size_t sVar1;
  int iVar2;
  size_t *psVar3;
  void *pvVar4;
  uint uVar5;
  uint local_30;
  size_t local_2c [6];
  
  pvVar4 = *(void **)this;
  uVar5 = *(uint *)((int)pvVar4 + -0xc);
  local_30 = uVar5;
  sVar1 = _strlen(param_2);
  psVar3 = local_2c;
  local_2c[0] = sVar1;
  if (uVar5 <= sVar1) {
    psVar3 = &local_30;
  }
  iVar2 = _memcmp(pvVar4,param_2,*psVar3);
  if (iVar2 == 0) {
    iVar2 = uVar5 - sVar1;
  }
  return iVar2;
}

/* __ZNKSs7compareEmmPKc @ 0x97c1628c (188 bytes) */
int __ZNKSs7compareEmmPKc(this, param_2, param_3, param_4)
  void *this;
  ulong param_2;
  ulong param_3;
  char *param_4;
{
  uint *puVar1;
  size_t sVar2;
  size_t *psVar3;
  int iVar4;
  uint uVar5;
  ulong uStack00000020;
  uint local_30;
  uint local_2c;
  size_t local_28 [4];
  
  iVar4 = *(int *)this;
  uVar5 = *(uint *)(iVar4 + -0xc);
  uStack00000020 = param_3;
  if (uVar5 < param_2) {
    std____throw_out_of_range("basic_string::compare");
    iVar4 = *(int *)this;
  }
  sVar2 = _strlen(param_4);
  local_30 = uVar5 - param_2;
  local_28[0] = sVar2;
  puVar1 = &STACKARG(0x20);
  if (local_30 <= uStack00000020) {
    puVar1 = &local_30;
  }
  uVar5 = *puVar1;
  psVar3 = local_28;
  local_2c = uVar5;
  if (uVar5 <= sVar2) {
    psVar3 = &local_2c;
  }
  iVar4 = _memcmp((void *)(iVar4 + param_2),param_4,*psVar3);
  if (iVar4 == 0) {
    iVar4 = uVar5 - sVar2;
  }
  return iVar4;
}

/* __ZNKSs7compareEmmPKcm @ 0x97c16348 (220 bytes) */
int __ZNKSs7compareEmmPKcm(this, param_2, param_3, param_4, param_5)
  void *this;
  ulong param_2;
  ulong param_3;
  char *param_4;
  ulong param_5;
{
  size_t *psVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulong uStack00000020;
  ulong uStack00000028;
  size_t local_30;
  uint local_2c;
  uint local_28;
  uint local_24 [3];
  
  iVar3 = *(int *)this;
  uVar4 = *(uint *)(iVar3 + -0xc);
  uStack00000020 = param_3;
  uStack00000028 = param_5;
  if (uVar4 < param_2) {
    std____throw_out_of_range("basic_string::compare");
    iVar3 = *(int *)this;
  }
  local_30 = _strlen(param_4);
  psVar1 = &STACKARG(0x28);
  if (local_30 <= uStack00000028) {
    psVar1 = &local_30;
  }
  local_2c = uVar4 - param_2;
  uVar4 = *psVar1;
  local_24[0] = uVar4;
  puVar2 = &STACKARG(0x20);
  if (local_2c <= uStack00000020) {
    puVar2 = &local_2c;
  }
  uVar5 = *puVar2;
  puVar2 = local_24;
  local_28 = uVar5;
  if (uVar5 <= uVar4) {
    puVar2 = &local_28;
  }
  iVar3 = _memcmp((void *)(iVar3 + param_2),param_4,*puVar2);
  if (iVar3 == 0) {
    iVar3 = uVar5 - uVar4;
  }
  return iVar3;
}

/* __ZNSs4_RepixEm @ 0x97c16424 (12 bytes) */
int __ZNSs4_RepixEm(this, param_2)
  void *this;
  ulong param_2;
{
  return (int)this + param_2 + 0xc;
}

/* __ZNSs4_Rep9_S_createEmRKSaIcE @ 0x97c16430 (348 bytes) */
int __ZNSs4_Rep9_S_createEmRKSaIcE(param_1, param_2)
  ulong param_1;
  unsigned char * param_2;
{
  undefined4 uVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  ulong uVar7;
  char in_RESERVE;
  byte in_cr0;
  
  if (0x3ffffffc < param_1) {
    std____throw_length_error("basic_string::_S_create");
  }
  puVar2 = PTR__S_force_new_a7b7c0e8;
  uVar3 = param_1 + 0x1d;
  uVar7 = param_1 + 0xd;
  if (uVar3 < 0x1001) {
    if (uVar7 < 0x81) goto LAB_97c164a4;
    uVar3 = 0x80 - (uVar3 & 0x7f) & 0x7f;
  }
  else {
    uVar3 = 0x1000 - (uVar3 & 0xfff) & 0xfff;
  }
  param_1 = param_1 + uVar3;
  uVar7 = param_1 + 0xd;
LAB_97c164a4:
  puVar4 = (undefined4 *)0x0;
  if (uVar7 != 0) {
    if (*(int *)PTR__S_force_new_a7b7c0e8 == 0) {
      pcVar5 = _getenv("GLIBCPP_FORCE_NEW");
      if (pcVar5 == (char *)0x0) {
        do {
          if (in_RESERVE != '\0') {
            uVar1 = storeWordConditionalIndexed(*(int *)puVar2 + -1,0,puVar2);
            *(undefined4 *)puVar2 = uVar1;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
      }
      else {
        do {
          if (in_RESERVE != '\0') {
            uVar1 = storeWordConditionalIndexed(*(int *)puVar2 + 1,0,puVar2);
            *(undefined4 *)puVar2 = uVar1;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
      }
    }
    puVar2 = PTR__S_free_list_a7b7c0e4;
    if ((uVar7 < 0x81) && (*(int *)PTR__S_force_new_a7b7c0e8 < 1)) {
      iVar6 = (uVar7 + 7 >> 1 & 0x7ffffffc) - 4;
      _pthread_mutex_lock((pthread_mutex_t *)PTR__S_node_allocator_lock_a7b7c0e0);
      puVar4 = *(undefined4 **)(puVar2 + iVar6);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)
                 std____default_alloc_template_true_0____S_refill(uVar7 + 7 & 0xfffffff8);
      }
      else {
        *(undefined4 *)(puVar2 + iVar6) = *puVar4;
      }
      if (puVar4 == (undefined4 *)0x0) {
        std____throw_bad_alloc();
      }
      _pthread_mutex_unlock((pthread_mutex_t *)PTR__S_node_allocator_lock_a7b7c0e0);
    }
    else {
      puVar4 = ((int (*)())operator_new)(uVar7);
    }
  }
  puVar4[1] = param_1;
  *puVar4 = 0;
  puVar4[2] = 0;
  return puVar4;
}

/* __ZNSs4_Rep10_M_destroyERKSaIcE @ 0x97c165cc (132 bytes) */
int __ZNSs4_Rep10_M_destroyERKSaIcE(param_1)
  unsigned char * param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = PTR__S_free_list_a7b7c0e4;
  puVar1 = PTR__S_node_allocator_lock_a7b7c0e0;
  if ((*(int *)(param_1 + 4) + 0xdU < 0x81) && (*(int *)PTR__S_force_new_a7b7c0e8 < 1)) {
    iVar3 = (*(int *)(param_1 + 4) + 0x14U >> 1 & 0x7ffffffc) - 4;
    _pthread_mutex_lock((pthread_mutex_t *)PTR__S_node_allocator_lock_a7b7c0e0);
    *(undefined4 *)param_1 = *(undefined4 *)(puVar2 + iVar3);
    *(unsigned char **)(puVar2 + iVar3) = param_1;
    _pthread_mutex_unlock((pthread_mutex_t *)puVar1);
  }
  else {
    __ZdlPv(param_1);
  }
  return;
}

/* __ZNSs4_Rep8_M_cloneERKSaIcEm @ 0x97c16674 (148 bytes) */
int __ZNSs4_Rep8_M_cloneERKSaIcEm(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  ulong param_3;
{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar4;
  uint uVar3;
  
  uVar1 = *(int *)this + param_3;
  uVar3 = uVar1;
  if (((*(uint *)((int)this + 4) < uVar1) && (0xfe3 < uVar1)) &&
     (uVar3 = *(uint *)((int)this + 4) << 1, uVar3 < uVar1)) {
    uVar3 = uVar1;
  }
  puVar2 = (undefined4 *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(uVar3,param_2);
  uVar4 = 0;
  if (*(size_t *)this != 0) {
    _memcpy(puVar2 + 3,(void *)((int)this + 0xc),*(size_t *)this);
    uVar4 = *(undefined4 *)this;
  }
  *puVar2 = uVar4;
  return puVar2 + 3;
}

/* __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EPKS3_RKS6_ @ 0x97c16708 (140 bytes) */
int __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EPKS3_RKS6_(param_1, param_2, param_3)
  char *param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  size_t sVar1;
  undefined4 local_30;
  undefined4 local_2c [5];
  
  sVar1 = _strlen((char *)param_2);
  __ZNSsC4Ev(param_1);
  __ZNSs7reserveEm(param_1,sVar1 + *(int *)(*(int *)param_3 + -0xc));
  __ZNKSs7_M_iendEv(&local_30,param_1);
  __ZNKSs7_M_iendEv(local_2c,param_1);
  __ZNSs7replaceEN9__gnu_cxx17__normal_iteratorIPcSsEES2_PKcS4_
            (param_1,local_30,local_2c[0],param_2,param_2 + sVar1);
  __ZNSs6appendERKSs(param_1,param_3);
  return param_1;
}

/* __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ES3_RKS6_ @ 0x97c167c4 (84 bytes) */
int __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ES3_RKS6_(param_1, param_2, param_3)
  void *param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  __ZNSsC4Ev(param_1);
  __ZNSs7reserveEm(param_1,*(int *)(*(int *)param_3 + -0xc) + 1);
  __ZNSs6appendEmc(param_1,1,param_2);
  __ZNSs6appendERKSs(param_1,param_3);
  return param_1;
}

/* __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_ @ 0x97c16848 (44 bytes) */
int __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_(param_1, param_2, param_3)
  unsigned char * param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  __ZNSsC1ERKSs(param_1,param_2);
  __ZNSs6appendERKSs(param_1,param_3);
  return param_1;
}

/* __ZN9__gnu_cxxeqIPcSsEEbRKNS_17__normal_iteratorIT_T0_EES7_ @ 0x97c168a4 (24 bytes) */
int __ZN9__gnu_cxxeqIPcSsEEbRKNS_17__normal_iteratorIT_T0_EES7_(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  return *(int *)param_1 == *(int *)param_2;
}

/* __ZN9__gnu_cxxeqIPKcSsEEbRKNS_17__normal_iteratorIT_T0_EES8_ @ 0x97c168bc (24 bytes) */
int __ZN9__gnu_cxxeqIPKcSsEEbRKNS_17__normal_iteratorIT_T0_EES8_(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  return *(int *)param_1 == *(int *)param_2;
}

/* __ZNSsC2IPcEET_S1_RKSaIcE @ 0x97c168d4 (4 bytes) */
int __ZNSsC2IPcEET_S1_RKSaIcE(this, param_2, param_3, param_4)
  void *this;
  char *param_2;
  char *param_3;
  unsigned char * param_4;
{
  ((int (*)())__ZNSsC4IPcEET_S1_RKSaIcE)(this,param_2,param_3,param_4);
  return;
}

/* __ZNSsC1IPcEET_S1_RKSaIcE @ 0x97c168d8 (4 bytes) */
int __ZNSsC1IPcEET_S1_RKSaIcE(this, param_2, param_3, param_4)
  void *this;
  char *param_2;
  char *param_3;
  unsigned char * param_4;
{
  char *pcVar1;
  
  pcVar1 = ((int (*)())std__string___S_construct_char__)(param_2,param_3,param_4,0);
  __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,pcVar1,param_4);
  return;
}

/* __ZNSsC4IPcEET_S1_RKSaIcE @ 0x97c168dc (80 bytes) */
int __ZNSsC4IPcEET_S1_RKSaIcE(this, param_2, param_3, param_4)
  void *this;
  char *param_2;
  char *param_3;
  unsigned char * param_4;
{
  char *pcVar1;
  
  pcVar1 = ((int (*)())std__string___S_construct_char__)(param_2,param_3,param_4,0);
  __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,pcVar1,param_4);
  return;
}

/* __ZNSsC2IPKcEET_S2_RKSaIcE @ 0x97c1692c (4 bytes) */
int __ZNSsC2IPKcEET_S2_RKSaIcE(this, param_2, param_3, param_4)
  void *this;
  char *param_2;
  char *param_3;
  unsigned char * param_4;
{
  ((int (*)())__ZNSsC4IPKcEET_S2_RKSaIcE)(this,param_2,param_3,param_4);
  return;
}

/* __ZNSsC1IPKcEET_S2_RKSaIcE @ 0x97c16930 (4 bytes) */
int __ZNSsC1IPKcEET_S2_RKSaIcE(this, param_2, param_3, param_4)
  void *this;
  char *param_2;
  char *param_3;
  unsigned char * param_4;
{
  char *pcVar1;
  
  pcVar1 = ((int (*)())__ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag)(param_2,param_3,param_4,0);
  __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,pcVar1,param_4);
  return;
}

/* __ZNSsC4IPKcEET_S2_RKSaIcE @ 0x97c16934 (80 bytes) */
int __ZNSsC4IPKcEET_S2_RKSaIcE(this, param_2, param_3, param_4)
  void *this;
  char *param_2;
  char *param_3;
  unsigned char * param_4;
{
  char *pcVar1;
  
  pcVar1 = ((int (*)())__ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag)(param_2,param_3,param_4,0);
  __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,pcVar1,param_4);
  return;
}

/* __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE @ 0x97c16984 (4 bytes) */
int __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE(this, param_2, param_3, param_4)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())__ZNSsC4IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE)(this,param_2,param_3,param_4);
  return;
}

/* __ZNSsC1IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE @ 0x97c16988 (4 bytes) */
int __ZNSsC1IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE(this, param_2, param_3, param_4)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  unsigned char * param_4;
{
  char *pcVar1;
  
  pcVar1 = ((int (*)())__ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag)(param_2,param_3,param_4,0);
  __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,pcVar1,param_4);
  return;
}

/* __ZNSsC4IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE @ 0x97c1698c (80 bytes) */
int __ZNSsC4IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE(this, param_2, param_3, param_4)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  unsigned char * param_4;
{
  char *pcVar1;
  
  pcVar1 = ((int (*)())__ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag)(param_2,param_3,param_4,0);
  __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,pcVar1,param_4);
  return;
}

/* __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE @ 0x97c169dc (4 bytes) */
int __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE(this, param_2, param_3, param_4)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())__ZNSsC4IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE)(this,param_2,param_3,param_4);
  return;
}

/* __ZNSsC1IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE @ 0x97c169e0 (4 bytes) */
int __ZNSsC1IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE(this, param_2, param_3, param_4)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  unsigned char * param_4;
{
  char *pcVar1;
  
  pcVar1 = ((int (*)())std__string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__)(param_2,param_3,param_4,0);
  __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,pcVar1,param_4);
  return;
}

/* __ZNSsC4IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE @ 0x97c169e4 (80 bytes) */
int __ZNSsC4IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE(this, param_2, param_3, param_4)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  unsigned char * param_4;
{
  char *pcVar1;
  
  pcVar1 = ((int (*)())std__string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__)(param_2,param_3,param_4,0);
  __ZNSs12_Alloc_hiderC4EPcRKSaIcE(this,pcVar1,param_4);
  return;
}

/* std__string___M_replace___gnu_cxx____normal_iterator_char__std__string__ @ 0x97c16a34 (108 bytes) */
int std__string___M_replace___gnu_cxx____normal_iterator_char__std__string__(param_1, param_2, param_3, param_4, param_5)
  void *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  unsigned char * psVar1;
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined4 local_30;
  undefined4 local_2c [6];
  
  ((int (*)())__ZNSsC1IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE)(auStack_50,param_4,param_5,auStack_40);
  __ZNKSs9_M_ibeginEv(&local_30,auStack_50);
  __ZNKSs7_M_iendEv(local_2c,auStack_50);
  psVar1 = ((int (*)())__ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_)(param_1,param_2,param_3,local_30,local_2c[0]);
  __ZNSsD4Ev(auStack_50);
  return psVar1;
}

/* std__string___M_replace___gnu_cxx____normal_iterator_char_const__std__string__ @ 0x97c16ae4 (108 bytes) */
int std__string___M_replace___gnu_cxx____normal_iterator_char_const__std__string__(param_1, param_2, param_3, param_4, param_5)
  void *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  unsigned char * psVar1;
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined4 local_30;
  undefined4 local_2c [6];
  
  ((int (*)())__ZNSsC1IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE)(auStack_50,param_4,param_5,auStack_40);
  __ZNKSs9_M_ibeginEv(&local_30,auStack_50);
  __ZNKSs7_M_iendEv(local_2c,auStack_50);
  psVar1 = ((int (*)())__ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_)(param_1,param_2,param_3,local_30,local_2c[0]);
  __ZNSsD4Ev(auStack_50);
  return psVar1;
}

/* std__string___M_replace_char__ @ 0x97c16b94 (108 bytes) */
int std__string___M_replace_char__(param_1, param_2, param_3, param_4, param_5)
  void *param_1;
  undefined4 param_2;
  undefined4 param_3;
  char *param_4;
  char *param_5;
{
  unsigned char * psVar1;
  undefined1 auStack_50 [16];
  unsigned char aaStack_40 [16];
  undefined4 local_30;
  undefined4 local_2c [6];
  
  ((int (*)())__ZNSsC1IPcEET_S1_RKSaIcE)(auStack_50,param_4,param_5,aaStack_40);
  __ZNKSs9_M_ibeginEv(&local_30,auStack_50);
  __ZNKSs7_M_iendEv(local_2c,auStack_50);
  psVar1 = ((int (*)())__ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_)(param_1,param_2,param_3,local_30,local_2c[0]);
  __ZNSsD4Ev(auStack_50);
  return psVar1;
}

/* __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag @ 0x97c16c44 (108 bytes) */
int __ZNSs10_M_replaceIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_St18input_iterator_tag(param_1, param_2, param_3, param_4, param_5)
  void *param_1;
  undefined4 param_2;
  char *param_3;
  char *param_4;
  char *param_5;
{
  unsigned char * psVar1;
  undefined1 auStack_50 [16];
  unsigned char aaStack_40 [16];
  undefined4 local_30;
  undefined4 local_2c [6];
  
  ((int (*)())__ZNSsC1IPKcEET_S2_RKSaIcE)(auStack_50,param_4,param_5,aaStack_40);
  __ZNKSs9_M_ibeginEv(&local_30,auStack_50);
  __ZNKSs7_M_iendEv(local_2c,auStack_50);
  psVar1 = ((int (*)())__ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_)(param_1,param_2,param_3,local_30,local_2c[0]);
  __ZNSsD4Ev(auStack_50);
  return psVar1;
}

/* __ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_ @ 0x97c16cf4 (168 bytes) */
int __ZNSs15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcSsEEEERSsS3_S3_T_S5_(this, param_2, param_3, param_4, param_5)
  void *this;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  int local_30 [5];
  
  uVar1 = param_5 - param_4;
  if (0x3ffffffb < uVar1) {
    std____throw_length_error("basic_string::_M_replace");
  }
  __ZNKSs9_M_ibeginEv(local_30,this);
  __ZNSs9_M_mutateEmmm(this,param_2 - local_30[0],param_3 - param_2,uVar1);
  if (uVar1 != 0) {
    __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIS_SsEES2_
              ((char *)(*(int *)this + (param_2 - local_30[0])),param_4,param_5);
  }
  return this;
}

/* std__string___M_replace_safe___gnu_cxx____normal_iterator_char_const__std__string__ @ 0x97c16d9c (168 bytes) */
int std__string___M_replace_safe___gnu_cxx____normal_iterator_char_const__std__string__(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  int local_30 [5];
  
  uVar1 = param_5 - param_4;
  if (0x3ffffffb < uVar1) {
    std____throw_length_error("basic_string::_M_replace");
  }
  __ZNKSs9_M_ibeginEv(local_30,this);
  __ZNSs9_M_mutateEmmm(this,param_2 - local_30[0],param_3 - param_2,uVar1);
  if (uVar1 != 0) {
    __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIPKcSsEES4_
              ((char *)(*(int *)this + (param_2 - local_30[0])),param_4,param_5);
  }
  return this;
}

/* std__string___M_replace_safe_char__ @ 0x97c16e44 (164 bytes) */
int std__string___M_replace_safe_char__(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int param_3;
  void *param_4;
  int param_5;
{
  uint uVar1;
  int local_30 [6];
  
  uVar1 = param_5 - (int)param_4;
  if (0x3ffffffb < uVar1) {
    std____throw_length_error("basic_string::_M_replace");
  }
  __ZNKSs9_M_ibeginEv(local_30,this);
  __ZNSs9_M_mutateEmmm(this,param_2 - local_30[0],param_3 - param_2,uVar1);
  if (uVar1 != 0) {
    _memcpy((void *)(*(int *)this + (param_2 - local_30[0])),param_4,uVar1);
  }
  return this;
}

/* __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_ @ 0x97c16ee8 (164 bytes) */
int __ZNSs15_M_replace_safeIPKcEERSsN9__gnu_cxx17__normal_iteratorIPcSsEES6_T_S7_(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int param_3;
  void *param_4;
  int param_5;
{
  uint uVar1;
  int local_30 [6];
  
  uVar1 = param_5 - (int)param_4;
  if (0x3ffffffb < uVar1) {
    std____throw_length_error("basic_string::_M_replace");
  }
  __ZNKSs9_M_ibeginEv(local_30,this);
  __ZNSs9_M_mutateEmmm(this,param_2 - local_30[0],param_3 - param_2,uVar1);
  if (uVar1 != 0) {
    _memcpy((void *)(*(int *)this + (param_2 - local_30[0])),param_4,uVar1);
  }
  return this;
}

/* __ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag @ 0x97c16f8c (152 bytes) */
int __ZNSs12_S_constructIN9__gnu_cxx17__normal_iteratorIPcSsEEEES2_T_S4_RKSaIcESt20forward_iterator_tag(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  unsigned char * param_3;
  undefined4 param_4;
{
  ulong *puVar1;
  ulong *puVar2;
  ulong uVar3;
  char in_RESERVE;
  byte in_cr0;
  
  if (param_1 == param_2) {
    do {
      if (in_RESERVE != '\0') {
        DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    puVar1 = (ulong *)&DAT_a7b7bf90;
  }
  else {
    uVar3 = param_2 - param_1;
    puVar2 = (ulong *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(uVar3,param_3);
    puVar1 = puVar2 + 3;
    __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIS_SsEES2_((char *)puVar1,param_1,param_2)
    ;
    *puVar2 = uVar3;
    *(undefined1 *)((int)puVar1 + uVar3) = 0;
  }
  return (char *)puVar1;
}

/* std__string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__ @ 0x97c17024 (152 bytes) */
int std__string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  unsigned char * param_3;
  undefined4 param_4;
{
  ulong *puVar1;
  ulong *puVar2;
  ulong uVar3;
  char in_RESERVE;
  byte in_cr0;
  
  if (param_1 == param_2) {
    do {
      if (in_RESERVE != '\0') {
        DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    puVar1 = (ulong *)&DAT_a7b7bf90;
  }
  else {
    uVar3 = param_2 - param_1;
    puVar2 = (ulong *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(uVar3,param_3);
    puVar1 = puVar2 + 3;
    __ZNSs13_S_copy_charsEPcN9__gnu_cxx17__normal_iteratorIPKcSsEES4_
              ((char *)puVar1,param_1,param_2);
    *puVar2 = uVar3;
    *(undefined1 *)((int)puVar1 + uVar3) = 0;
  }
  return (char *)puVar1;
}

/* std__string___S_construct_char__ @ 0x97c170bc (176 bytes) */
int std__string___S_construct_char__(param_1, param_2, param_3)
  void *param_1;
  void *param_2;
  unsigned char * param_3;
{
  ulong *puVar1;
  ulong *puVar2;
  ulong uVar3;
  char in_RESERVE;
  byte in_cr0;
  
  if (param_1 == param_2) {
    do {
      if (in_RESERVE != '\0') {
        DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    puVar1 = (ulong *)&DAT_a7b7bf90;
  }
  else {
    if (param_1 == (void *)0x0) {
      std____throw_logic_error("attempt to create string with null pointer");
    }
    uVar3 = (int)param_2 - (int)param_1;
    puVar2 = (ulong *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(uVar3,param_3);
    puVar1 = puVar2 + 3;
    _memcpy(puVar1,param_1,uVar3);
    *puVar2 = uVar3;
    *(char *)((int)puVar1 + uVar3) = '\0';
  }
  return (char *)puVar1;
}

/* __ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag @ 0x97c1716c (176 bytes) */
int __ZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tag(param_1, param_2, param_3)
  void *param_1;
  void *param_2;
  unsigned char * param_3;
{
  ulong *puVar1;
  ulong *puVar2;
  ulong uVar3;
  char in_RESERVE;
  byte in_cr0;
  
  if (param_1 == param_2) {
    do {
      if (in_RESERVE != '\0') {
        DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    puVar1 = (ulong *)&DAT_a7b7bf90;
  }
  else {
    if (param_1 == (void *)0x0) {
      std____throw_logic_error("attempt to create string with null pointer");
    }
    uVar3 = (int)param_2 - (int)param_1;
    puVar2 = (ulong *)((int (*)())__ZNSs4_Rep9_S_createEmRKSaIcE)(uVar3,param_3);
    puVar1 = puVar2 + 3;
    _memcpy(puVar1,param_1,uVar3);
    *puVar2 = uVar3;
    *(char *)((int)puVar1 + uVar3) = '\0';
  }
  return (char *)puVar1;
}

/* __ZSt13__destroy_auxIPSsEvT_S1_12__false_type @ 0x97c1721c (76 bytes) */
int __ZSt13__destroy_auxIPSsEvT_S1_12__false_type(param_1, param_2, param_3)
  unsigned char * param_1;
  unsigned char * param_2;
  undefined4 param_3;
{
  unsigned char * psVar1;
  
  psVar1 = param_1;
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    psVar1 = (unsigned char *)__ZNSsD4Ev(param_1);
  }
  return psVar1;
}

/* operator_new @ 0x97c17268 (144 bytes) */
int operator_new(param_1)
  ulong param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  void *pvVar3;
  code *a0;
  undefined4 *puVar4;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  pvVar3 = _malloc(param_1);
  while( true ) {
    if (pvVar3 != (void *)0x0) {
      return pvVar3;
    }
    a0 = (code *)__keymgr_get_per_thread_data(2);
    if (a0 == (code *)0x0) break;
    (*a0)(a0);
    pvVar3 = _malloc(param_1);
  }
  puVar4 = (undefined4 *)___cxa_allocate_exception(4);
  puVar2 = PTR_typeinfo_a7b7c174;
  puVar1 = PTR___ZNSt9bad_allocD1Ev_a7b7c170;
  *puVar4 = PTR_vtable_a7b7c178 + 8;
                    
  ___cxa_throw(puVar4,puVar2,puVar1);
}

/* ___cxa_pure_virtual @ 0x97c1731c (48 bytes) */
int ___cxa_pure_virtual()
{
  void *pvVar1;
  
  _write(2,"pure virtual method called\n",0x1b);
  pvVar1 = (void *)std__terminate();
  if (pvVar1 != (void *)0x0) {
    _free(pvVar1);
  }
  return;
}

