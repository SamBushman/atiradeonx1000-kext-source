#include "decls.h"

/* std__string__rfind_97c15b28 @ 0x97c15b28 (92 bytes) */
int std__string__rfind_97c15b28(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  ulong param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(*(int *)this + -0xc);
  if (iVar2 != 0) {
    uVar3 = iVar2 - 1;
    if (param_2 < uVar3) {
      uVar3 = param_2;
    }
    if (uVar3 != 0xffffffff) {
      do {
        if (*(char *)(*(int *)this + uVar3) == param_1) {
          return uVar3;
        }
        bVar1 = uVar3 != 0;
        uVar3 = uVar3 - 1;
      } while (bVar1);
    }
  }
  return 0xffffffff;
}

/* std__string__find_first_of @ 0x97c15b84 (12 bytes) */
int std__string__find_first_of(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
{
  find_first_of(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0xc));
  return;
}

/* std__string__find_first_of_97c15b90 @ 0x97c15b90 (152 bytes) */
int std__string__find_first_of_97c15b90(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  ulong param_2;
  ulong param_3;
{
  int iVar1;
  void *pvVar2;
  
  if ((param_3 != 0) && (iVar1 = *(int *)this, param_2 < *(uint *)(iVar1 + -0xc))) {
    do {
      pvVar2 = _memchr(param_1,(int)*(char *)(iVar1 + param_2),param_3);
      if (pvVar2 != (void *)0x0) {
        return param_2;
      }
      param_2 = param_2 + 1;
      iVar1 = *(int *)this;
    } while (param_2 < *(uint *)(iVar1 + -0xc));
  }
  return 0xffffffff;
}

/* std__string__find_first_of_97c15c28 @ 0x97c15c28 (72 bytes) */
int std__string__find_first_of_97c15c28(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  ulong param_2;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_1);
  find_first_of(this,param_1,param_2,sVar1);
  return;
}

/* std__string__find_first_of_97c15c70 @ 0x97c15c70 (4 bytes) */
int std__string__find_first_of_97c15c70(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  ulong param_2;
{
  find(this,param_1,param_2);
  return;
}

/* std__string__find_last_of @ 0x97c15c74 (12 bytes) */
int std__string__find_last_of(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
{
  find_last_of(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0xc));
  return;
}

/* std__string__find_last_of_97c15c80 @ 0x97c15c80 (144 bytes) */
int std__string__find_last_of_97c15c80(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  ulong param_2;
  ulong param_3;
{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  
  iVar2 = *(int *)this;
  if ((*(int *)(iVar2 + -0xc) == 0) || (param_3 == 0)) {
LAB_97c15cf8:
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = *(int *)(iVar2 + -0xc) - 1;
    if (param_2 < uVar4) {
      uVar4 = param_2;
    }
    while (pvVar3 = _memchr(param_1,(int)*(char *)(iVar2 + uVar4),param_3), pvVar3 == (void *)0x0) {
      bVar1 = uVar4 == 0;
      uVar4 = uVar4 - 1;
      if (bVar1) goto LAB_97c15cf8;
      iVar2 = *(int *)this;
    }
  }
  return uVar4;
}

/* std__string__find_last_of_97c15d10 @ 0x97c15d10 (72 bytes) */
int std__string__find_last_of_97c15d10(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  ulong param_2;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_1);
  find_last_of(this,param_1,param_2,sVar1);
  return;
}

/* std__string__find_last_of_97c15d58 @ 0x97c15d58 (4 bytes) */
int std__string__find_last_of_97c15d58(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  ulong param_2;
{
  rfind(this,param_1,param_2);
  return;
}

/* std__string__find_first_not_of @ 0x97c15d5c (12 bytes) */
int std__string__find_first_not_of(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
{
  find_first_not_of(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0xc));
  return;
}

/* std__string__find_first_not_of_97c15d68 @ 0x97c15d68 (124 bytes) */
int std__string__find_first_not_of_97c15d68(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  ulong param_2;
  ulong param_3;
{
  int iVar1;
  void *pvVar2;
  
  iVar1 = *(int *)this;
  if (param_2 < *(uint *)(iVar1 + -0xc)) {
    do {
      pvVar2 = _memchr(param_1,(int)*(char *)(iVar1 + param_2),param_3);
      if (pvVar2 == (void *)0x0) {
        return param_2;
      }
      iVar1 = *(int *)this;
      param_2 = param_2 + 1;
    } while (param_2 < *(uint *)(iVar1 + -0xc));
  }
  return 0xffffffff;
}

/* std__string__find_first_not_of_97c15de4 @ 0x97c15de4 (72 bytes) */
int std__string__find_first_not_of_97c15de4(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  ulong param_2;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_1);
  find_first_not_of(this,param_1,param_2,sVar1);
  return;
}

/* std__string__find_first_not_of_97c15e2c @ 0x97c15e2c (68 bytes) */
int std__string__find_first_not_of_97c15e2c(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  ulong param_2;
{
  while( true ) {
    if (*(uint *)(*(int *)this + -0xc) <= param_2) {
      return 0xffffffff;
    }
    if (*(char *)(*(int *)this + param_2) != param_1) break;
    param_2 = param_2 + 1;
  }
  return param_2;
}

/* std__string__find_last_not_of @ 0x97c15e70 (12 bytes) */
int std__string__find_last_not_of(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
{
  find_last_not_of(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0xc));
  return;
}

/* std__string__find_last_not_of_97c15e7c @ 0x97c15e7c (136 bytes) */
int std__string__find_last_not_of_97c15e7c(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  ulong param_2;
  ulong param_3;
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
    if (param_2 < uVar4) {
      uVar4 = param_2;
    }
    while (pvVar3 = _memchr(param_1,(int)*(char *)(iVar2 + uVar4),param_3), pvVar3 != (void *)0x0) {
      bVar1 = uVar4 == 0;
      uVar4 = uVar4 - 1;
      if (bVar1) goto LAB_97c15eec;
      iVar2 = *(int *)this;
    }
  }
  return uVar4;
}

/* std__string__find_last_not_of_97c15f04 @ 0x97c15f04 (72 bytes) */
int std__string__find_last_not_of_97c15f04(this, param_1, param_2)
  unsigned char * this;
  char *param_1;
  ulong param_2;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_1);
  find_last_not_of(this,param_1,param_2,sVar1);
  return;
}

/* std__string__find_last_not_of_97c15f4c @ 0x97c15f4c (84 bytes) */
int std__string__find_last_not_of_97c15f4c(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  ulong param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(*(int *)this + -0xc);
  if (iVar2 != 0) {
    uVar3 = iVar2 - 1;
    if (param_2 < uVar3) {
      uVar3 = param_2;
    }
    do {
      if (*(char *)(*(int *)this + uVar3) != param_1) {
        return uVar3;
      }
      bVar1 = uVar3 != 0;
      uVar3 = uVar3 - 1;
    } while (bVar1);
  }
  return 0xffffffff;
}

/* std__string__substr @ 0x97c15fa0 (112 bytes) */
int std__string__substr(param_1, param_2)
  ulong param_1;
  ulong param_2;
{
  uint in_r5;
  ulong in_r6;
  
  if (*(uint *)(*(int *)param_2 + -0xc) < in_r5) {
    std____throw_out_of_range("basic_string__substr");
  }
  string((unsigned char *)param_1,(unsigned char *)param_2,in_r5,in_r6);
  return param_1;
}

/* std__string__compare @ 0x97c16010 (96 bytes) */
int std__string__compare(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
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
  uVar4 = *(uint *)((int)*(void **)param_1 + -0xc);
  local_1c[0] = uVar4;
  if (uVar3 <= uVar4) {
    puVar2 = &local_20;
  }
  iVar1 = _memcmp(*(void **)this,*(void **)param_1,*puVar2);
  if (iVar1 == 0) {
    iVar1 = uVar3 - uVar4;
  }
  return iVar1;
}

/* std__string__compare_97c16070 @ 0x97c16070 (188 bytes) */
int std__string__compare_97c16070(this, param_1, param_2, param_3)
  unsigned char * this;
  ulong param_1;
  ulong param_2;
  unsigned char * param_3;
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
  pvVar4 = *(void **)param_3;
  local_28[0] = *(uint *)((int)pvVar4 + -0xc);
  uStack00000020 = param_2;
  if (uVar5 < param_1) {
    std____throw_out_of_range("basic_string__compare");
    iVar3 = *(int *)this;
    pvVar4 = *(void **)param_3;
  }
  uVar1 = local_28[0];
  local_30 = uVar5 - param_1;
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
  iVar3 = _memcmp((void *)(iVar3 + param_1),pvVar4,*puVar2);
  if (iVar3 == 0) {
    iVar3 = uVar5 - uVar1;
  }
  return iVar3;
}

/* std__string__compare_97c1612c @ 0x97c1612c (240 bytes) */
int std__string__compare_97c1612c(this, param_1, param_2, param_3, param_4, param_5)
  unsigned char * this;
  ulong param_1;
  ulong param_2;
  unsigned char * param_3;
  ulong param_4;
  ulong param_5;
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
  iVar3 = *(int *)param_3;
  uVar4 = *(uint *)(iVar3 + -0xc);
  uStack00000020 = param_2;
  uStack0000002c = param_5;
  if ((uVar5 < param_1) || (uVar4 < param_4)) {
    std____throw_out_of_range("basic_string__compare");
    iVar2 = *(int *)this;
    iVar3 = *(int *)param_3;
  }
  local_30 = uVar5 - param_1;
  puVar1 = &STACKARG(0x20);
  if (local_30 <= uStack00000020) {
    puVar1 = &local_30;
  }
  local_2c = uVar4 - param_4;
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
  iVar2 = _memcmp((void *)(iVar2 + param_1),(void *)(iVar3 + param_4),*puVar1);
  if (iVar2 == 0) {
    iVar2 = uVar4 - uVar5;
  }
  return iVar2;
}

/* std__string__compare_97c1621c @ 0x97c1621c (112 bytes) */
int std__string__compare_97c1621c(this, param_1)
  unsigned char * this;
  char *param_1;
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
  sVar1 = _strlen(param_1);
  psVar3 = local_2c;
  local_2c[0] = sVar1;
  if (uVar5 <= sVar1) {
    psVar3 = &local_30;
  }
  iVar2 = _memcmp(pvVar4,param_1,*psVar3);
  if (iVar2 == 0) {
    iVar2 = uVar5 - sVar1;
  }
  return iVar2;
}

/* std__string__compare_97c1628c @ 0x97c1628c (188 bytes) */
int std__string__compare_97c1628c(this, param_1, param_2, param_3)
  unsigned char * this;
  ulong param_1;
  ulong param_2;
  char *param_3;
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
  uStack00000020 = param_2;
  if (uVar5 < param_1) {
    std____throw_out_of_range("basic_string__compare");
    iVar4 = *(int *)this;
  }
  sVar2 = _strlen(param_3);
  local_30 = uVar5 - param_1;
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
  iVar4 = _memcmp((void *)(iVar4 + param_1),param_3,*psVar3);
  if (iVar4 == 0) {
    iVar4 = uVar5 - sVar2;
  }
  return iVar4;
}

/* std__string__compare_97c16348 @ 0x97c16348 (220 bytes) */
int std__string__compare_97c16348(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  ulong param_1;
  ulong param_2;
  char *param_3;
  ulong param_4;
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
  uStack00000020 = param_2;
  uStack00000028 = param_4;
  if (uVar4 < param_1) {
    std____throw_out_of_range("basic_string__compare");
    iVar3 = *(int *)this;
  }
  local_30 = _strlen(param_3);
  psVar1 = &STACKARG(0x28);
  if (local_30 <= uStack00000028) {
    psVar1 = &local_30;
  }
  local_2c = uVar4 - param_1;
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
  iVar3 = _memcmp((void *)(iVar3 + param_1),param_3,*puVar2);
  if (iVar3 == 0) {
    iVar3 = uVar5 - uVar4;
  }
  return iVar3;
}

/* std__string___Rep__operator__ @ 0x97c16424 (12 bytes) */
int std__string___Rep__operator__(this, param_1)
  unsigned char * this;
  ulong param_1;
{
  return this + param_1 + 0xc;
}

/* std__string___Rep___S_create @ 0x97c16430 (384 bytes) */
int std__string___Rep___S_create(param_1, param_2)
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
    std____throw_length_error("basic_string___S_create");
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
  return;
}

/* std__string___Rep___M_destroy @ 0x97c165cc (152 bytes) */
int std__string___Rep___M_destroy(param_1)
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
    operator_delete(param_1);
  }
  return;
}

/* std__string___Rep___M_clone @ 0x97c16674 (148 bytes) */
int std__string___Rep___M_clone(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  ulong param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar4;
  uint uVar3;
  
  uVar1 = *(int *)this + param_2;
  uVar3 = uVar1;
  if (((*(uint *)(this + 4) < uVar1) && (0xfe3 < uVar1)) &&
     (uVar3 = *(uint *)(this + 4) << 1, uVar3 < uVar1)) {
    uVar3 = uVar1;
  }
  puVar2 = (undefined4 *)_S_create(uVar3,param_1);
  uVar4 = 0;
  if (*(size_t *)this != 0) {
    _memcpy(puVar2 + 3,this + 0xc,*(size_t *)this);
    uVar4 = *(undefined4 *)this;
  }
  *puVar2 = uVar4;
  return puVar2 + 3;
}

/* std__operator_ @ 0x97c16708 (164 bytes) */
int std__operator_(param_1, param_2)
  char *param_1;
  unsigned char * param_2;
{
  size_t sVar1;
  unsigned char * in_r5;
  undefined4 local_30;
  undefined4 local_2c;
  
  sVar1 = _strlen((char *)param_2);
  string__string((unsigned char *)param_1);
  string__reserve((unsigned char *)param_1,sVar1 + *(int *)(*(int *)in_r5 + -0xc));
  string___M_iend();
  string___M_iend();
  string__replace((unsigned char *)param_1,local_30,local_2c,param_2,param_2 + sVar1);
  string__append((unsigned char *)param_1,in_r5);
  return param_1;
}

/* std__operator__97c167c4 @ 0x97c167c4 (108 bytes) */
int std__operator__97c167c4(param_1, param_2)
  int param_1;
  unsigned char * param_2;
{
  undefined3 in_register_0000000c;
  unsigned char * this;
  unsigned char * in_r5;
  
  this = (unsigned char *)CONCAT31(in_register_0000000c,param_1);
  string__string(this);
  string__reserve(this,*(int *)(*(int *)in_r5 + -0xc) + 1);
  string__append(this,1,(char)param_2);
  string__append(this,in_r5);
  return this;
}

/* std__operator__97c16848 @ 0x97c16848 (68 bytes) */
int std__operator__97c16848(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  unsigned char * in_r5;
  
  string__string(param_1,param_2);
  string__append(param_1,in_r5);
  return param_1;
}

/* __gnu_cxx__operator__ @ 0x97c168a4 (24 bytes) */
int __gnu_cxx__operator__(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  return *(int *)param_1 == *(int *)param_2;
}

/* __gnu_cxx__operator___97c168bc @ 0x97c168bc (24 bytes) */
int __gnu_cxx__operator___97c168bc(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  return *(int *)param_1 == *(int *)param_2;
}

/* std__string__string_char__ @ 0x97c168d4 (4 bytes) */
int std__string__string_char__(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  char *param_2;
  unsigned char * param_3;
{
  string_char__(this,param_1,param_2,param_3);
  return;
}

/* std__string__string_char___97c168d8 @ 0x97c168d8 (4 bytes) */
int std__string__string_char___97c168d8(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  char *param_2;
  unsigned char * param_3;
{
  char *pcVar1;
  
  pcVar1 = _S_construct_char__(this,param_2,param_3,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar1,param_3);
  return;
}

/* std__string__string_char___97c168dc @ 0x97c168dc (80 bytes) */
int std__string__string_char___97c168dc(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  char *param_2;
  unsigned char * param_3;
{
  char *pcVar1;
  
  pcVar1 = _S_construct_char__(this,param_2,param_3,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar1,param_3);
  return;
}

/* std__string__string_char_const__ @ 0x97c1692c (4 bytes) */
int std__string__string_char_const__(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  char *param_2;
  unsigned char * param_3;
{
  string_char_const__(this,param_1,param_2,param_3);
  return;
}

/* std__string__string_char_const___97c16930 @ 0x97c16930 (4 bytes) */
int std__string__string_char_const___97c16930(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  char *param_2;
  unsigned char * param_3;
{
  char *pcVar1;
  
  pcVar1 = _S_construct_char_const__(this,param_2,param_3,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar1,param_3);
  return;
}

/* std__string__string_char_const___97c16934 @ 0x97c16934 (80 bytes) */
int std__string__string_char_const___97c16934(this, param_1, param_2, param_3)
  unsigned char * this;
  char *param_1;
  char *param_2;
  unsigned char * param_3;
{
  char *pcVar1;
  
  pcVar1 = _S_construct_char_const__(this,param_2,param_3,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar1,param_3);
  return;
}

/* std__string__string___gnu_cxx____normal_iterator_char__std__string__ @ 0x97c16984 (4 bytes) */
int std__string__string___gnu_cxx____normal_iterator_char__std__string__()
{
  string___gnu_cxx____normal_iterator_char__std__string__();
  return;
}

/* std__string__string___gnu_cxx____normal_iterator_char__std__string___97c16988 @ 0x97c16988 (4 bytes) */
int std__string__string___gnu_cxx____normal_iterator_char__std__string___97c16988(this, param_2, param_3, param_4)
  unsigned char * this;
  undefined4 param_2;
  undefined4 param_3;
  unsigned char * param_4;
{
  char *pcVar1;
  
  pcVar1 = _S_construct___gnu_cxx____normal_iterator_char__std__string__(this,param_3,param_4,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar1,param_4);
  return;
}

/* std__string__string___gnu_cxx____normal_iterator_char__std__string___97c1698c @ 0x97c1698c (80 bytes) */
int std__string__string___gnu_cxx____normal_iterator_char__std__string___97c1698c(this, param_2, param_3, param_4)
  unsigned char * this;
  undefined4 param_2;
  undefined4 param_3;
  unsigned char * param_4;
{
  char *pcVar1;
  
  pcVar1 = _S_construct___gnu_cxx____normal_iterator_char__std__string__(this,param_3,param_4,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar1,param_4);
  return;
}

/* std__string__string___gnu_cxx____normal_iterator_char_const__std__string__ @ 0x97c169dc (4 bytes) */
int std__string__string___gnu_cxx____normal_iterator_char_const__std__string__()
{
  string___gnu_cxx____normal_iterator_char_const__std__string__();
  return;
}

/* std__string__string___gnu_cxx____normal_iterator_char_const__std__string___97c169e0 @ 0x97c169e0 (4 bytes) */
int std__string__string___gnu_cxx____normal_iterator_char_const__std__string___97c169e0(this, param_2, param_3, param_4)
  unsigned char * this;
  undefined4 param_2;
  undefined4 param_3;
  unsigned char * param_4;
{
  char *pcVar1;
  
  pcVar1 = _S_construct___gnu_cxx____normal_iterator_char_const__std__string__
                     (this,param_3,param_4,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar1,param_4);
  return;
}

/* std__string__string___gnu_cxx____normal_iterator_char_const__std__string___97c169e4 @ 0x97c169e4 (80 bytes) */
int std__string__string___gnu_cxx____normal_iterator_char_const__std__string___97c169e4(this, param_2, param_3, param_4)
  unsigned char * this;
  undefined4 param_2;
  undefined4 param_3;
  unsigned char * param_4;
{
  char *pcVar1;
  
  pcVar1 = _S_construct___gnu_cxx____normal_iterator_char_const__std__string__
                     (this,param_3,param_4,0);
  _Alloc_hider___Alloc_hider((unsigned char *)this,pcVar1,param_4);
  return;
}

/* std__string___M_replace___gnu_cxx____normal_iterator_char__std__string__ @ 0x97c16a34 (148 bytes) */
int std__string___M_replace___gnu_cxx____normal_iterator_char__std__string__(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  unsigned char * psVar1;
  unsigned char asStack_50 [16];
  undefined1 auStack_40 [16];
  undefined4 local_30;
  undefined4 local_2c;
  
  string___gnu_cxx____normal_iterator_char__std__string__(asStack_50,param_4,param_5,auStack_40);
  std__string___M_ibegin();
  std__string___M_iend();
  psVar1 = _M_replace_safe___gnu_cxx____normal_iterator_char__std__string__
                     (asStack_50,param_2,param_3,local_30,local_2c);
  ~string(asStack_50);
  return psVar1;
}

/* std__string___M_replace___gnu_cxx____normal_iterator_char_const__std__string__ @ 0x97c16ae4 (148 bytes) */
int std__string___M_replace___gnu_cxx____normal_iterator_char_const__std__string__(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  unsigned char * psVar1;
  unsigned char asStack_50 [16];
  undefined1 auStack_40 [16];
  undefined4 local_30;
  undefined4 local_2c;
  
  string___gnu_cxx____normal_iterator_char_const__std__string__
            (asStack_50,param_4,param_5,auStack_40);
  std__string___M_ibegin();
  std__string___M_iend();
  psVar1 = _M_replace_safe___gnu_cxx____normal_iterator_char__std__string__
                     (asStack_50,param_2,param_3,local_30,local_2c);
  ~string(asStack_50);
  return psVar1;
}

/* std__string___M_replace_char__ @ 0x97c16b94 (148 bytes) */
int std__string___M_replace_char__(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  char *param_4;
  char *param_5;
{
  unsigned char * psVar1;
  unsigned char asStack_50 [16];
  unsigned char aaStack_40 [16];
  undefined4 local_30;
  undefined4 local_2c;
  
  string_char__(asStack_50,param_4,param_5,aaStack_40);
  std__string___M_ibegin();
  std__string___M_iend();
  psVar1 = _M_replace_safe___gnu_cxx____normal_iterator_char__std__string__
                     (asStack_50,param_2,param_3,local_30,local_2c);
  ~string(asStack_50);
  return psVar1;
}

/* std__string___M_replace_char_const__ @ 0x97c16c44 (148 bytes) */
int std__string___M_replace_char_const__(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  char *param_4;
  char *param_5;
{
  unsigned char * psVar1;
  unsigned char asStack_50 [16];
  unsigned char aaStack_40 [16];
  undefined4 local_30;
  undefined4 local_2c;
  
  string_char_const__(asStack_50,param_4,param_5,aaStack_40);
  std__string___M_ibegin();
  std__string___M_iend();
  psVar1 = _M_replace_safe___gnu_cxx____normal_iterator_char__std__string__
                     (asStack_50,param_2,param_3,local_30,local_2c);
  ~string(asStack_50);
  return psVar1;
}

/* std__string___M_replace_safe___gnu_cxx____normal_iterator_char__std__string__ @ 0x97c16cf4 (168 bytes) */
int std__string___M_replace_safe___gnu_cxx____normal_iterator_char__std__string__(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  int local_30;
  
  uVar1 = param_5 - param_4;
  if (0x3ffffffb < uVar1) {
    std____throw_length_error("basic_string___M_replace");
  }
  std__string___M_ibegin();
  _M_mutate(this,param_2 - local_30,param_3 - param_2,uVar1);
  if (uVar1 != 0) {
    _S_copy_chars(*(int *)this + (param_2 - local_30),param_4,param_5);
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
  int local_30;
  
  uVar1 = param_5 - param_4;
  if (0x3ffffffb < uVar1) {
    std____throw_length_error("basic_string___M_replace");
  }
  std__string___M_ibegin();
  _M_mutate(this,param_2 - local_30,param_3 - param_2,uVar1);
  if (uVar1 != 0) {
    _S_copy_chars(*(int *)this + (param_2 - local_30),param_4,param_5);
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
  int local_30;
  
  uVar1 = param_5 - (int)param_4;
  if (0x3ffffffb < uVar1) {
    std____throw_length_error("basic_string___M_replace");
  }
  std__string___M_ibegin();
  _M_mutate(this,param_2 - local_30,param_3 - param_2,uVar1);
  if (uVar1 != 0) {
    _memcpy((void *)(*(int *)this + (param_2 - local_30)),param_4,uVar1);
  }
  return this;
}

/* std__string___M_replace_safe_char_const__ @ 0x97c16ee8 (164 bytes) */
int std__string___M_replace_safe_char_const__(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int param_3;
  void *param_4;
  int param_5;
{
  uint uVar1;
  int local_30;
  
  uVar1 = param_5 - (int)param_4;
  if (0x3ffffffb < uVar1) {
    std____throw_length_error("basic_string___M_replace");
  }
  std__string___M_ibegin();
  _M_mutate(this,param_2 - local_30,param_3 - param_2,uVar1);
  if (uVar1 != 0) {
    _memcpy((void *)(*(int *)this + (param_2 - local_30)),param_4,uVar1);
  }
  return this;
}

/* std__string___S_construct___gnu_cxx____normal_iterator_char__std__string__ @ 0x97c16f8c (152 bytes) */
int std__string___S_construct___gnu_cxx____normal_iterator_char__std__string__(param_1, param_2, param_3)
  int param_1;
  int param_2;
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
    uVar3 = param_2 - param_1;
    puVar2 = (ulong *)_Rep___S_create(uVar3,param_3);
    puVar1 = puVar2 + 3;
    _S_copy_chars(puVar1,param_1,param_2);
    *puVar2 = uVar3;
    *(char *)((int)puVar1 + uVar3) = '\0';
  }
  return (char *)puVar1;
}

/* std__string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__ @ 0x97c17024 (152 bytes) */
int std__string___S_construct___gnu_cxx____normal_iterator_char_const__std__string__(param_1, param_2, param_3)
  int param_1;
  int param_2;
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
    uVar3 = param_2 - param_1;
    puVar2 = (ulong *)_Rep___S_create(uVar3,param_3);
    puVar1 = puVar2 + 3;
    _S_copy_chars(puVar1,param_1,param_2);
    *puVar2 = uVar3;
    *(char *)((int)puVar1 + uVar3) = '\0';
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
    puVar2 = (ulong *)_Rep___S_create(uVar3,param_3);
    puVar1 = puVar2 + 3;
    _memcpy(puVar1,param_1,uVar3);
    *puVar2 = uVar3;
    *(char *)((int)puVar1 + uVar3) = '\0';
  }
  return (char *)puVar1;
}

/* std__string___S_construct_char_const__ @ 0x97c1716c (176 bytes) */
int std__string___S_construct_char_const__(param_1, param_2, param_3)
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
    puVar2 = (ulong *)_Rep___S_create(uVar3,param_3);
    puVar1 = puVar2 + 3;
    _memcpy(puVar1,param_1,uVar3);
    *puVar2 = uVar3;
    *(char *)((int)puVar1 + uVar3) = '\0';
  }
  return (char *)puVar1;
}

/* std____destroy_aux_std__string__ @ 0x97c1721c (76 bytes) */
int std____destroy_aux_std__string__(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    string___string(param_1);
  }
  return;
}

/* operator_new @ 0x97c17268 (164 bytes) */
int operator_new(param_1)
  ulong param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  void *pvVar3;
  code *pcVar4;
  undefined4 *puVar5;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  pvVar3 = _malloc(param_1);
  while( true ) {
    if (pvVar3 != (void *)0x0) {
      return pvVar3;
    }
    pcVar4 = (code *)__keymgr_get_per_thread_data(2);
    if (pcVar4 == (code *)0x0) break;
    (*pcVar4)();
    pvVar3 = _malloc(param_1);
  }
  puVar5 = (undefined4 *)___cxa_allocate_exception(4);
  puVar2 = PTR_typeinfo_a7b7c174;
  puVar1 = PTR__bad_alloc_a7b7c170;
  *puVar5 = PTR_vtable_a7b7c178 + 8;
                    
  ___cxa_throw(puVar5,puVar2,puVar1);
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

