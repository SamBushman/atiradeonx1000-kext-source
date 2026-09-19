#include "decls.h"

/* std__string__insert_97c150bc @ 0x97c150bc (72 bytes) */
int std__string__insert_97c150bc(this, param_1, param_2)
  unsigned char *this;
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
  unsigned char *this;
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
  unsigned char *param_2;
  int param_3;
  undefined4 param_4;
{
  int local_30 [6];
  
  _M_ibegin();
  param_3 = param_3 - local_30[0];
  std__string___M_check((ulong)local_30);
  replace(param_2,local_30[0],local_30[0],1,param_4);
  *(undefined4 *)(*(int *)param_2 + -4) = 0xffffffff;
  _M_ibegin();
  *param_1 = local_30[0] + param_3;
  return param_1;
}

/* std__string__erase_97c151f4 @ 0x97c151f4 (128 bytes) */
int std__string__erase_97c151f4(param_1, param_2, param_3)
  int *param_1;
  unsigned char *param_2;
  int param_3;
{
  _M_ibegin();
  replace(param_2,param_3,param_3 + 1,*(undefined4 *)param_2,*(undefined4 *)param_2);
  *(undefined4 *)(*(int *)param_2 + -4) = 0xffffffff;
  _M_ibegin();
  *param_1 = param_3;
  return param_1;
}

/* std__string__erase_97c15274 @ 0x97c15274 (132 bytes) */
int std__string__erase_97c15274(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  unsigned char *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  _M_ibegin();
  replace(param_2,param_3,param_4,*(undefined4 *)param_2,*(undefined4 *)param_2);
  *(undefined4 *)(*(int *)param_2 + -4) = 0xffffffff;
  _M_ibegin();
  *param_1 = param_3;
  return param_1;
}

/* std__string__replace_97c152f8 @ 0x97c152f8 (12 bytes) */
int std__string__replace_97c152f8(this, param_1, param_2, param_3)
  unsigned char *this;
  ulong param_1;
  ulong param_2;
  unsigned char *param_3;
{
  replace(this,param_1,param_2,*(char **)param_3,*(ulong *)(*(char **)param_3 + -0xc));
  return;
}

/* std__string__replace_97c15304 @ 0x97c15304 (136 bytes) */
int std__string__replace_97c15304(this, param_1, param_2, param_3, param_4, param_5)
  unsigned char *this;
  ulong param_1;
  ulong param_2;
  unsigned char *param_3;
  ulong param_4;
  ulong param_5;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)param_3;
  uVar2 = *(uint *)(iVar1 + -0xc);
  if (uVar2 < param_4) {
    std____throw_out_of_range("basic_string::replace");
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
  unsigned char *this;
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
  unsigned char *this;
  ulong param_1;
  ulong param_2;
  ulong param_3;
  int param_4;
{
  undefined3 in_register_0000001c;
  undefined4 local_30;
  undefined4 local_2c [4];
  
  std__string___M_check((ulong)&local_30);
  _M_fold((ulong)local_2c,(ulong)this);
  replace(this,local_30,local_2c[0],param_3,CONCAT31(in_register_0000001c,param_4));
  return;
}

/* std__string__replace_97c15454 @ 0x97c15454 (96 bytes) */
int std__string__replace_97c15454(this, param_2, param_3, param_4, param_5)
  unsigned char *this;
  int param_2;
  int param_3;
  char *param_4;
  ulong param_5;
{
  undefined4 local_30;
  
  _M_ibegin();
  replace(this,param_2 - local_30,param_3 - param_2,param_4,param_5);
  return;
}

/* std__string__replace_97c154b4 @ 0x97c154b4 (96 bytes) */
int std__string__replace_97c154b4(this, param_2, param_3, param_4)
  unsigned char *this;
  int param_2;
  int param_3;
  undefined4 *param_4;
{
  char *pcVar1;
  ulong uVar2;
  int local_30;
  
  pcVar1 = (char *)*param_4;
  uVar2 = *(ulong *)(pcVar1 + -0xc);
  _M_ibegin();
  replace(this,param_2 - local_30,param_3 - param_2,pcVar1,uVar2);
  return;
}

/* std__string__replace_97c15514 @ 0x97c15514 (80 bytes) */
int std__string__replace_97c15514(this, param_2, param_3, param_4)
  unsigned char *this;
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
  unsigned char *this;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
{
  int local_30;
  
  _M_ibegin();
  if (0x3ffffffcU - (*(int *)(*(int *)this + -0xc) - (param_3 - param_2)) <= param_4) {
    std____throw_length_error("basic_string::replace");
  }
  _M_mutate(this,param_2 - local_30,param_3 - param_2,param_4);
  if (param_4 != 0) {
    _memset((void *)(*(int *)this + (param_2 - local_30)),param_5,param_4);
  }
  return this;
}

/* std__string__replace_97c15618 @ 0x97c15618 (96 bytes) */
int std__string__replace_97c15618(this, param_2, param_3, param_4, param_5)
  unsigned char *this;
  int param_2;
  int param_3;
  char *param_4;
  int param_5;
{
  undefined4 local_30;
  
  _M_ibegin();
  replace(this,param_2 - local_30,param_3 - param_2,param_4,param_5 - (int)param_4);
  return;
}

/* std__string__replace_97c15678 @ 0x97c15678 (96 bytes) */
int std__string__replace_97c15678(this, param_2, param_3, param_4, param_5)
  unsigned char *this;
  int param_2;
  int param_3;
  char *param_4;
  int param_5;
{
  undefined4 local_30;
  
  _M_ibegin();
  replace(this,param_2 - local_30,param_3 - param_2,param_4,param_5 - (int)param_4);
  return;
}

/* std__string__replace_97c156d8 @ 0x97c156d8 (96 bytes) */
int std__string__replace_97c156d8(this, param_2, param_3, param_4, param_5)
  unsigned char *this;
  int param_2;
  int param_3;
  char *param_4;
  int param_5;
{
  undefined4 local_30;
  
  _M_ibegin();
  replace(this,param_2 - local_30,param_3 - param_2,param_4,param_5 - (int)param_4);
  return;
}

/* std__string___S_construct @ 0x97c15738 (140 bytes) */
int std__string___S_construct(param_1, param_2, param_3)
  ulong param_1;
  int param_2;
  unsigned char *param_3;
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
    puVar2 = (ulong *)_Rep::_S_create(param_1,param_3);
    puVar1 = puVar2 + 3;
    _memset(puVar1,CONCAT31(in_register_00000010,param_2),param_1);
    *puVar2 = param_1;
    *(undefined1 *)((int)puVar1 + param_1) = 0;
  }
  return puVar1;
}

/* std__string__copy @ 0x97c157c4 (132 bytes) */
int std__string__copy(this, param_1, param_2, param_3)
  unsigned char *this;
  char *param_1;
  ulong param_2;
  ulong param_3;
{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)this;
  if (*(uint *)(iVar2 + -0xc) < param_3) {
    std____throw_out_of_range("basic_string::copy");
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
  unsigned char *this;
  unsigned char *param_1;
{
  undefined4 uVar1;
  
  if (*(int *)(*(int *)this + -4) < 0) {
    *(undefined4 *)(*(int *)this + -4) = 0;
  }
  if (*(int *)(*(int *)param_1 + -4) < 0) {
    *(undefined4 *)(*(int *)param_1 + -4) = 0;
  }
  get_allocator();
  get_allocator();
  uVar1 = *(undefined4 *)this;
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)param_1 = uVar1;
  return;
}

/* std__string__c_str @ 0x97c158d4 (48 bytes) */
int std__string__c_str(this)
  unsigned char *this;
{
  *(undefined1 *)(*(int *)this + *(int *)(*(int *)this + -0xc)) = _Rep::_S_terminal;
  return *(undefined4 *)this;
}

/* std__string__data @ 0x97c15904 (8 bytes) */
int std__string__data(this)
  unsigned char *this;
{
  return *(undefined4 *)this;
}

/* std__string__find @ 0x97c1590c (128 bytes) */
int std__string__find(this, param_1, param_2, param_3)
  unsigned char *this;
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
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
{
  find(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0xc));
  return;
}

/* std__string__find_97c15998 @ 0x97c15998 (72 bytes) */
int std__string__find_97c15998(this, param_1, param_2)
  unsigned char *this;
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
  unsigned char *this;
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
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
{
  rfind(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0xc));
  return;
}

/* std__string__rfind_97c15a4c @ 0x97c15a4c (148 bytes) */
int std__string__rfind_97c15a4c(this, param_1, param_2, param_3)
  unsigned char *this;
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
  unsigned char *this;
  char *param_1;
  ulong param_2;
{
  size_t sVar1;
  
  sVar1 = _strlen(param_1);
  rfind(this,param_1,param_2,sVar1);
  return;
}

/* std__string__rfind_97c15b28 @ 0x97c15b28 (92 bytes) */
int std__string__rfind_97c15b28(this, param_1, param_2)
  unsigned char *this;
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
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
{
  find_first_of(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0xc));
  return;
}

/* std__string__find_first_of_97c15b90 @ 0x97c15b90 (152 bytes) */
int std__string__find_first_of_97c15b90(this, param_1, param_2, param_3)
  unsigned char *this;
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
  unsigned char *this;
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
  unsigned char *this;
  int param_1;
  ulong param_2;
{
  find(this,param_1,param_2);
  return;
}

/* std__string__find_last_of @ 0x97c15c74 (12 bytes) */
int std__string__find_last_of(this, param_1, param_2)
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
{
  find_last_of(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0xc));
  return;
}

/* std__string__find_last_of_97c15c80 @ 0x97c15c80 (144 bytes) */
int std__string__find_last_of_97c15c80(this, param_1, param_2, param_3)
  unsigned char *this;
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
  unsigned char *this;
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
  unsigned char *this;
  int param_1;
  ulong param_2;
{
  rfind(this,param_1,param_2);
  return;
}

/* std__string__find_first_not_of @ 0x97c15d5c (12 bytes) */
int std__string__find_first_not_of(this, param_1, param_2)
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
{
  find_first_not_of(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0xc));
  return;
}

/* std__string__find_first_not_of_97c15d68 @ 0x97c15d68 (124 bytes) */
int std__string__find_first_not_of_97c15d68(this, param_1, param_2, param_3)
  unsigned char *this;
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
  unsigned char *this;
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
  unsigned char *this;
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
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
{
  find_last_not_of(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0xc));
  return;
}

/* std__string__find_last_not_of_97c15e7c @ 0x97c15e7c (136 bytes) */
int std__string__find_last_not_of_97c15e7c(this, param_1, param_2, param_3)
  unsigned char *this;
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
  unsigned char *this;
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
  unsigned char *this;
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
    std____throw_out_of_range("basic_string::substr");
  }
  string((unsigned char *)param_1,(unsigned char *)param_2,in_r5,in_r6);
  return param_1;
}

/* std__string__compare @ 0x97c16010 (96 bytes) */
int std__string__compare(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
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
  unsigned char *this;
  ulong param_1;
  ulong param_2;
  unsigned char *param_3;
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
    std____throw_out_of_range("basic_string::compare");
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
  unsigned char *this;
  ulong param_1;
  ulong param_2;
  unsigned char *param_3;
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
    std____throw_out_of_range("basic_string::compare");
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
  unsigned char *this;
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
  unsigned char *this;
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
    std____throw_out_of_range("basic_string::compare");
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
  unsigned char *this;
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
    std____throw_out_of_range("basic_string::compare");
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
  unsigned char *this;
  ulong param_1;
{
  return this + param_1 + 0xc;
}

/* std__string___Rep___S_create @ 0x97c16430 (384 bytes) */
int std__string___Rep___S_create(param_1, param_2)
  ulong param_1;
  unsigned char *param_2;
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
      puVar4 = operator_new(uVar7);
    }
  }
  puVar4[1] = param_1;
  *puVar4 = 0;
  puVar4[2] = 0;
  return;
}

/* std__string___Rep___M_destroy @ 0x97c165cc (152 bytes) */
int std__string___Rep___M_destroy(param_1)
  unsigned char *param_1;
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
    *(allocator **)(puVar2 + iVar3) = param_1;
    _pthread_mutex_unlock((pthread_mutex_t *)puVar1);
  }
  else {
    operator_delete(param_1);
  }
  return;
}

/* std__string___Rep___M_clone @ 0x97c16674 (148 bytes) */
int std__string___Rep___M_clone(this, param_1, param_2)
  unsigned char *this;
  unsigned char *param_1;
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
  unsigned char *param_2;
{
  size_t sVar1;
  string *in_r5;
  undefined4 local_30;
  undefined4 local_2c;
  
  sVar1 = _strlen((char *)param_2);
  string::string((unsigned char *)param_1);
  string::reserve((unsigned char *)param_1,sVar1 + *(int *)(*(int *)in_r5 + -0xc));
  string::_M_iend();
  string::_M_iend();
  string::replace((unsigned char *)param_1,local_30,local_2c,param_2,param_2 + sVar1);
  string::append((unsigned char *)param_1,in_r5);
  return param_1;
}

/* std__operator__97c167c4 @ 0x97c167c4 (108 bytes) */
int std__operator__97c167c4(param_1, param_2)
  int param_1;
  unsigned char *param_2;
{
  undefined3 in_register_0000000c;
  string *this;
  string *in_r5;
  
  this = (unsigned char *)CONCAT31(in_register_0000000c,param_1);
  string::string(this);
  string::reserve(this,*(int *)(*(int *)in_r5 + -0xc) + 1);
  string::append(this,1,(char)param_2);
  string::append(this,in_r5);
  return this;
}

/* std__operator__97c16848 @ 0x97c16848 (68 bytes) */
int std__operator__97c16848(param_1, param_2)
  unsigned char *param_1;
  unsigned char *param_2;
{
  string *in_r5;
  
  string::string(param_1,param_2);
  string::append(param_1,in_r5);
  return param_1;
}

/* __gnu_cxx__operator__ @ 0x97c168a4 (24 bytes) */
int __gnu_cxx__operator__(param_1, param_2)
  unsigned char *param_1;
  unsigned char *param_2;
{
  return *(int *)param_1 == *(int *)param_2;
}

