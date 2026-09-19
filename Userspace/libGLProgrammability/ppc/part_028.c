#include "decls.h"

/* TIntermSymbol___TIntermSymbol_97c328b8 @ 0x97c328b8 (148 bytes) */
int TIntermSymbol___TIntermSymbol_97c328b8(this)
  unsigned char *this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  iVar4 = *(int *)(this + 0x38);
  *(undefined ***)this = &PTR_getLine_a7b7d390;
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
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7d440;
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find @ 0x97c3294c (276 bytes) */
string * std::
         _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
         ::find(unsigned char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_r4;
  int in_r5;
  uint *puVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34 [2];
  
  iVar6 = *(int *)(in_r4 + 4);
  iVar1 = iVar6;
  if (*(int *)(iVar6 + 4) != 0) {
    pvVar5 = *(void **)(in_r5 + 4);
    iVar3 = *(int *)(iVar6 + 4);
    do {
      uVar7 = *(uint *)(*(int *)(iVar3 + 0x14) + -0xc);
      local_40 = uVar7;
      uVar8 = *(uint *)((int)pvVar5 + -0xc);
      local_3c = uVar8;
      puVar4 = &local_3c;
      if (uVar7 <= uVar8) {
        puVar4 = &local_40;
      }
      iVar2 = _memcmp(*(void **)(iVar3 + 0x14),pvVar5,*puVar4);
      if (iVar2 == 0) {
        iVar2 = uVar7 - uVar8;
      }
      if (iVar2 < 0) {
        iVar2 = *(int *)(iVar3 + 0xc);
      }
      else {
        iVar2 = *(int *)(iVar3 + 8);
        iVar1 = iVar3;
      }
      iVar3 = iVar2;
    } while (iVar2 != 0);
  }
  if (iVar1 != iVar6) {
    puVar4 = local_34;
    uVar7 = *(uint *)((int)*(void **)(in_r5 + 4) + -0xc);
    local_38 = uVar7;
    uVar8 = *(uint *)(*(int *)(iVar1 + 0x14) + -0xc);
    local_34[0] = uVar8;
    if (uVar7 <= uVar8) {
      puVar4 = &local_38;
    }
    iVar3 = _memcmp(*(void **)(in_r5 + 4),*(void **)(iVar1 + 0x14),*puVar4);
    if (iVar3 == 0) {
      iVar3 = uVar7 - uVar8;
    }
    if (-1 < iVar3) goto LAB_97c32a44;
  }
  iVar1 = iVar6;
LAB_97c32a44:
  *(int *)param_1 = iVar1;
  return param_1;
}

/* std__string__string_97c32a60 @ 0x97c32a60 (4 bytes) */
int std__string__string_97c32a60(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
  ulong param_3;
{
  std__string__string(this,param_1,param_2,param_3);
  return;
}

/* std__string__string_97c32a64 @ 0x97c32a64 (180 bytes) */
int std__string__string_97c32a64(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
  ulong param_3;
{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 local_40 [11];
  
  iVar2 = *(int *)(param_1 + 4);
  if (*(uint *)(iVar2 + -0xc) < param_2) {
    std____throw_out_of_range("basic_string::_M_check");
    iVar2 = *(int *)(param_1 + 4);
  }
  uVar1 = *(int *)(iVar2 + -0xc) - param_2;
  if (uVar1 <= param_3) {
    param_3 = uVar1;
  }
  local_40[0] = GetGlobalPoolAllocator();
  pcVar3 = std__string___S_construct___gnu_cxx____normal_iterator_char__std__string__
                     (local_40[0],iVar2 + param_2 + param_3,local_40,0);
  uVar4 = GetGlobalPoolAllocator();
  *(undefined4 *)this = uVar4;
  *(char **)(this + 4) = pcVar3;
  return;
}

/* std__string__compare_97c32b18 @ 0x97c32b18 (112 bytes) */
int std__string__compare_97c32b18(this, param_1)
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
  
  pvVar4 = *(void **)(this + 4);
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

/* std__operator__97c32b88 @ 0x97c32b88 (340 bytes) */
int std__operator__97c32b88(param_1, param_2)
  char *param_1;
  unsigned char *param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  size_t sVar5;
  undefined4 uVar6;
  string *psVar7;
  char in_RESERVE;
  byte in_cr0;
  
  sVar5 = _strlen((char *)param_2);
  iVar2 = DAT_a7b7ba14;
  piVar3 = (int *)(DAT_a7b7ba14 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  uVar6 = GetGlobalPoolAllocator();
  *(undefined4 *)param_1 = uVar6;
  *(int *)(param_1 + 4) = iVar2 + 0xc;
  std__string__reserve((ulong)param_1);
  uVar4 = *(uint *)(*(int *)(param_1 + 4) + -0xc);
  if (0x3ffffffc - sVar5 < uVar4) {
    std____throw_length_error("basic_string::replace");
  }
  psVar7 = *(string **)(param_1 + 4);
  if (((*(int *)(psVar7 + -4) < 1) && (psVar7 <= param_2)) && (param_2 <= psVar7 + uVar4)) {
    std__string___M_replace_char_const__
              (uVar6,psVar7 + uVar4,psVar7 + uVar4,param_2,param_2 + sVar5,0);
  }
  else {
    std__string___M_replace_safe_char_const__
              (uVar6,psVar7 + uVar4,psVar7 + uVar4,param_2,param_2 + sVar5);
  }
  std__string__append((unsigned char *)param_1);
  return param_1;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound @ 0x97c32cdc (176 bytes) */
string * std::
         _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
         ::lower_bound(unsigned char *param_1)

{
  int iVar1;
  int in_r4;
  int in_r5;
  uint *puVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_40;
  uint local_3c [6];
  
  iVar4 = *(int *)(in_r4 + 4);
  if (*(int *)(iVar4 + 4) != 0) {
    pvVar3 = *(void **)(in_r5 + 4);
    iVar5 = *(int *)(iVar4 + 4);
    do {
      uVar6 = *(uint *)(*(int *)(iVar5 + 0x14) + -0xc);
      local_40 = uVar6;
      uVar7 = *(uint *)((int)pvVar3 + -0xc);
      local_3c[0] = uVar7;
      puVar2 = local_3c;
      if (uVar6 <= uVar7) {
        puVar2 = &local_40;
      }
      iVar1 = _memcmp(*(void **)(iVar5 + 0x14),pvVar3,*puVar2);
      if (iVar1 == 0) {
        iVar1 = uVar6 - uVar7;
      }
      if (iVar1 < 0) {
        iVar1 = *(int *)(iVar5 + 0xc);
      }
      else {
        iVar1 = *(int *)(iVar5 + 8);
        iVar4 = iVar5;
      }
      iVar5 = iVar1;
    } while (iVar1 != 0);
  }
  *(int *)param_1 = iVar4;
  return param_1;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____insert_unique @ 0x97c32d8c (568 bytes) */
_Rb_tree_node_base *
std::
_Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
::insert_unique(unsigned char *param_1,unsigned char *param_2,int *param_3,int param_4)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  void *pvVar4;
  uint uVar5;
  pair *ppVar6;
  pair *local_70 [4];
  pair *local_60 [4];
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34 [4];
  
  ppVar6 = (unsigned char *)*param_3;
  if (ppVar6 == *(pair **)(*(pair **)(param_2 + 4) + 8)) {
    if (*(int *)(param_2 + 8) != 0) {
      puVar2 = &local_4c;
      uVar3 = *(uint *)(*(int *)(param_4 + 4) + -0xc);
      local_50 = uVar3;
      uVar5 = *(uint *)(*(int *)(ppVar6 + 0x14) + -0xc);
      local_4c = uVar5;
      if (uVar3 <= uVar5) {
        puVar2 = &local_50;
      }
      iVar1 = _memcmp(*(void **)(param_4 + 4),*(void **)(ppVar6 + 0x14),*puVar2);
      if (iVar1 == 0) {
        iVar1 = uVar3 - uVar5;
      }
      if (iVar1 < 0) goto LAB_97c32f8c;
    }
  }
  else {
    if (ppVar6 != *(pair **)(param_2 + 4)) {
      local_70[0] = ppVar6;
      std___Rb_tree_base_iterator___M_decrement();
      ppVar6 = local_70;
      pvVar4 = *(void **)(param_4 + 4);
      puVar2 = &local_3c;
      uVar3 = *(uint *)(*(int *)(local_70[0] + 0x14) + -0xc);
      local_40 = uVar3;
      uVar5 = *(uint *)((int)pvVar4 + -0xc);
      local_3c = uVar5;
      if (uVar3 <= uVar5) {
        puVar2 = &local_40;
      }
      iVar1 = _memcmp(*(void **)(local_70[0] + 0x14),pvVar4,*puVar2);
      if (iVar1 == 0) {
        iVar1 = uVar3 - uVar5;
      }
      if (iVar1 < 0) {
        uVar5 = *(uint *)((int)pvVar4 + -0xc);
        puVar2 = local_34;
        local_38 = uVar5;
        uVar3 = *(uint *)(*(int *)(*param_3 + 0x14) + -0xc);
        local_34[0] = uVar3;
        if (uVar5 <= uVar3) {
          puVar2 = &local_38;
        }
        iVar1 = _memcmp(pvVar4,*(void **)(*param_3 + 0x14),*puVar2);
        if (iVar1 == 0) {
          iVar1 = uVar5 - uVar3;
        }
        if (iVar1 < 0) {
          if (*(int *)(ppVar6 + 0xc) != 0) {
            ppVar6 = (unsigned char *)*param_3;
            goto LAB_97c32f8c;
          }
          goto LAB_97c32f68;
        }
      }
      std::
      _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
      ::insert_unique((unsigned char *)local_60);
      local_70[0] = local_60[0];
      goto LAB_97c32fa8;
    }
    puVar2 = &local_44;
    uVar3 = *(uint *)(*(int *)(*(int *)(ppVar6 + 0xc) + 0x14) + -0xc);
    local_48 = uVar3;
    uVar5 = *(uint *)((int)*(void **)(param_4 + 4) + -0xc);
    local_44 = uVar5;
    if (uVar3 <= uVar5) {
      puVar2 = &local_48;
    }
    iVar1 = _memcmp(*(void **)(*(int *)(ppVar6 + 0xc) + 0x14),*(void **)(param_4 + 4),*puVar2);
    if (iVar1 == 0) {
      iVar1 = uVar3 - uVar5;
    }
    if (iVar1 < 0) {
LAB_97c32f68:
      ppVar6 = (unsigned char *)0x0;
LAB_97c32f8c:
      std::
      _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
      ::_M_insert(param_1,param_2,ppVar6);
      return param_1;
    }
  }
  std::
  _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
  ::insert_unique((unsigned char *)local_70);
LAB_97c32fa8:
  *(pair **)param_1 = local_70[0];
  return param_1;
}

/* std__string__append_97c32fc4 @ 0x97c32fc4 (112 bytes) */
int std__string__append_97c32fc4(this, param_1, param_2)
  unsigned char *this;
  char *param_1;
  ulong param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(this + 4);
  if (*(uint *)(iVar1 + -8) < param_2 + *(int *)(iVar1 + -0xc)) {
    std__string__reserve((ulong)this);
    iVar1 = *(int *)(this + 4);
  }
  iVar1 = iVar1 + *(int *)(iVar1 + -0xc);
  std__string___M_replace_safe_char_const__(this,iVar1,iVar1,param_1,param_1 + param_2);
  return;
}

/* std__string__append_97c33034 @ 0x97c33034 (116 bytes) */
int std__string__append_97c33034(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 4);
  iVar1 = *(int *)(param_1 + 4);
  if (*(uint *)(iVar2 + -8) < (uint)(*(int *)(iVar1 + -0xc) + *(int *)(iVar2 + -0xc))) {
    std__string__reserve((ulong)this);
    iVar1 = *(int *)(param_1 + 4);
    iVar2 = *(int *)(this + 4);
  }
  iVar2 = iVar2 + *(int *)(iVar2 + -0xc);
  std__string___M_replace_safe___gnu_cxx____normal_iterator_char__std__string__
            (this,iVar2,iVar2,iVar1,iVar1 + *(int *)(iVar1 + -0xc));
  return;
}

/* std__string___S_construct___gnu_cxx____normal_iterator_char__std__string___97c330a8 @ 0x97c330a8 (176 bytes) */
int std__string___S_construct___gnu_cxx____normal_iterator_char__std__string___97c330a8(param_1, param_2, param_3)
  void *param_1;
  void *param_2;
  unsigned char *param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  ulong *puVar4;
  ulong uVar5;
  ulong *puVar6;
  char in_RESERVE;
  byte in_cr0;
  
  if ((param_1 == param_2) &&
     (iVar3 = GetGlobalPoolAllocator(), iVar1 = DAT_a7b7ba14, *(int *)param_3 == iVar3)) {
    piVar2 = (int *)(DAT_a7b7ba14 + 8);
    do {
      if (in_RESERVE != '\0') {
        iVar3 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
        *piVar2 = iVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    return (char *)(iVar1 + 0xc);
  }
  uVar5 = (int)param_2 - (int)param_1;
  puVar4 = (ulong *)std__string___Rep___S_create(uVar5,param_3);
  puVar6 = puVar4 + 3;
  _memcpy(puVar6,param_1,uVar5);
  *puVar4 = uVar5;
  *(char *)((int)puVar6 + uVar5) = '\0';
  return (char *)puVar6;
}

/* std__string__reserve_97c33158 @ 0x97c33158 (216 bytes) */
int std__string__reserve_97c33158(this, param_1)
  unsigned char *this;
  ulong param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_20 [4];
  
  iVar4 = *(int *)(this + 4);
  if ((*(uint *)(iVar4 + -8) < param_1) || (0 < *(int *)(iVar4 + -4))) {
    if (0x3ffffffc < param_1) {
      std____throw_length_error("basic_string::reserve");
      iVar4 = *(int *)(this + 4);
    }
    local_20[0] = *(undefined4 *)this;
    uVar5 = std__string___Rep___M_clone((unsigned char *)(iVar4 + -0xc),(ulong)local_20);
    iVar4 = *(int *)(this + 4);
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
    *(undefined4 *)(this + 4) = uVar5;
  }
  return;
}

/* std__string___M_replace_safe_char_const___97c33230 @ 0x97c33230 (152 bytes) */
int std__string___M_replace_safe_char_const___97c33230(this, param_2, param_3, param_4, param_5)
  unsigned char *this;
  int param_2;
  int param_3;
  void *param_4;
  int param_5;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_5 - (int)param_4;
  if (0x3ffffffb < uVar2) {
    std____throw_length_error("basic_string::_M_replace");
  }
  iVar1 = *(int *)(this + 4);
  std__string___M_mutate((ulong)this,param_2 - iVar1,param_3 - param_2);
  if (uVar2 != 0) {
    _memcpy((void *)(*(int *)(this + 4) + (param_2 - iVar1)),param_4,uVar2);
  }
  return this;
}

/* std__string___M_replace_char_const___97c332c8 @ 0x97c332c8 (172 bytes) */
int std__string___M_replace_char_const___97c332c8(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  char *param_4;
  char *param_5;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  string *psVar4;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_50;
  int local_4c;
  undefined4 local_40 [4];
  undefined4 local_30;
  
  local_40[0] = GetGlobalPoolAllocator();
  std__string__string_char_const__((unsigned char *)&local_50,param_4,param_5,(unsigned char *)local_40);
  psVar4 = std__string___M_replace_safe___gnu_cxx____normal_iterator_char__std__string__
                     ((unsigned char *)&local_50,param_2,param_3,local_4c,
                      local_4c + *(int *)(local_4c + -0xc));
  piVar2 = (int *)(local_4c + -4);
  local_30 = local_50;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_4c + -0xc));
  }
  return psVar4;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_insert @ 0x97c33374 (356 bytes) */
_Rb_tree_node_base *
std::
_Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
::_M_insert(unsigned char *param_1,unsigned char *param_2,unsigned char *param_3)

{
  int iVar1;
  _Rb_tree_node_base *p_Var2;
  uint *puVar3;
  int in_r6;
  string *in_r7;
  uint uVar4;
  uint uVar5;
  uint local_30;
  uint local_2c [4];
  
  if ((in_r6 == *(int *)(param_2 + 4)) || (param_3 != (unsigned char *)0x0)) {
LAB_97c333f0:
    p_Var2 = (unsigned char *)TPoolAllocator__allocate(*(ulong *)param_2);
    if ((unsigned char *)(p_Var2 + 0x10) != (unsigned char *)0x0) {
      std__string__string((unsigned char *)(p_Var2 + 0x10),in_r7);
      *(undefined4 *)(p_Var2 + 0x18) = *(undefined4 *)(in_r7 + 8);
    }
    *(_Rb_tree_node_base **)(in_r6 + 8) = p_Var2;
    iVar1 = *(int *)(param_2 + 4);
    if (in_r6 != iVar1) {
      if (in_r6 == *(int *)(iVar1 + 8)) {
        *(_Rb_tree_node_base **)(iVar1 + 8) = p_Var2;
      }
      goto LAB_97c33490;
    }
    *(_Rb_tree_node_base **)(in_r6 + 4) = p_Var2;
    iVar1 = *(int *)(param_2 + 4);
  }
  else {
    puVar3 = local_2c;
    uVar5 = *(uint *)(*(int *)(in_r7 + 4) + -0xc);
    local_30 = uVar5;
    uVar4 = *(uint *)((int)*(void **)(in_r6 + 0x14) + -0xc);
    local_2c[0] = uVar4;
    if (uVar5 <= uVar4) {
      puVar3 = &local_30;
    }
    iVar1 = _memcmp(*(void **)(in_r7 + 4),*(void **)(in_r6 + 0x14),*puVar3);
    if (iVar1 == 0) {
      iVar1 = uVar5 - uVar4;
    }
    if (iVar1 < 0) goto LAB_97c333f0;
    p_Var2 = (unsigned char *)TPoolAllocator__allocate(*(ulong *)param_2);
    if ((unsigned char *)(p_Var2 + 0x10) != (unsigned char *)0x0) {
      std__string__string((unsigned char *)(p_Var2 + 0x10),in_r7);
      *(undefined4 *)(p_Var2 + 0x18) = *(undefined4 *)(in_r7 + 8);
    }
    *(_Rb_tree_node_base **)(in_r6 + 0xc) = p_Var2;
    iVar1 = *(int *)(param_2 + 4);
    if (in_r6 != *(int *)(iVar1 + 0xc)) goto LAB_97c33490;
  }
  *(_Rb_tree_node_base **)(iVar1 + 0xc) = p_Var2;
LAB_97c33490:
  *(int *)(p_Var2 + 4) = in_r6;
  *(undefined4 *)(p_Var2 + 0xc) = 0;
  *(undefined4 *)(p_Var2 + 8) = 0;
  std___Rb_tree_rebalance(p_Var2,(_Rb_tree_node_base **)(*(int *)(param_2 + 4) + 4));
  *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
  *(_Rb_tree_node_base **)param_1 = p_Var2;
  return param_1;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____insert_unique_97c334d8 @ 0x97c334d8 (388 bytes) */
pair * std::
       _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
       ::insert_unique(unsigned char *param_1)

{
  int iVar1;
  _Rb_tree_node_base *in_r4;
  int in_r5;
  uint *puVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int local_60 [4];
  int local_50 [4];
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  
  iVar4 = *(int *)(in_r4 + 4);
  iVar1 = 1;
  iVar5 = iVar4;
  if (*(int *)(iVar4 + 4) != 0) {
    pvVar3 = *(void **)(in_r5 + 4);
    iVar6 = *(int *)(iVar4 + 4);
    do {
      iVar5 = iVar6;
      uVar7 = *(uint *)((int)pvVar3 + -0xc);
      local_40 = uVar7;
      uVar8 = *(uint *)(*(int *)(iVar5 + 0x14) + -0xc);
      local_3c = uVar8;
      puVar2 = &local_3c;
      if (uVar7 <= uVar8) {
        puVar2 = &local_40;
      }
      iVar1 = _memcmp(pvVar3,*(void **)(iVar5 + 0x14),*puVar2);
      if (iVar1 == 0) {
        iVar1 = uVar7 - uVar8;
      }
      iVar1 = -(iVar1 >> 0x1f);
      if (iVar1 == 0) {
        iVar6 = *(int *)(iVar5 + 0xc);
      }
      else {
        iVar6 = *(int *)(iVar5 + 8);
      }
    } while (iVar6 != 0);
  }
  if (iVar1 != 0) {
    local_60[0] = *(int *)(iVar4 + 8);
    if (iVar5 == local_60[0]) {
      std::
      _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
      ::_M_insert((unsigned char *)local_50,in_r4,(unsigned char *)0x0);
      goto LAB_97c3362c;
    }
    std___Rb_tree_base_iterator___M_decrement();
  }
  puVar2 = &local_34;
  uVar7 = *(uint *)(*(int *)(iVar5 + 0x14) + -0xc);
  local_38 = uVar7;
  uVar8 = *(uint *)((int)*(void **)(in_r5 + 4) + -0xc);
  local_34 = uVar8;
  if (uVar7 <= uVar8) {
    puVar2 = &local_38;
  }
  iVar1 = _memcmp(*(void **)(iVar5 + 0x14),*(void **)(in_r5 + 4),*puVar2);
  if (iVar1 == 0) {
    iVar1 = uVar7 - uVar8;
  }
  if (-1 < iVar1) {
    *(int *)param_1 = iVar5;
    *(undefined4 *)(param_1 + 4) = 0;
    return param_1;
  }
  std::
  _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
  ::_M_insert((unsigned char *)local_60,in_r4,(unsigned char *)0x0);
  local_50[0] = local_60[0];
LAB_97c3362c:
  *(int *)param_1 = local_50[0];
  *(undefined4 *)(param_1 + 4) = 1;
  return param_1;
}

/* std__string___M_replace_safe___gnu_cxx____normal_iterator_char__std__string___97c3365c @ 0x97c3365c (152 bytes) */
int std__string___M_replace_safe___gnu_cxx____normal_iterator_char__std__string___97c3365c(this, param_2, param_3, param_4, param_5)
  unsigned char *this;
  int param_2;
  int param_3;
  void *param_4;
  int param_5;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_5 - (int)param_4;
  if (0x3ffffffb < uVar2) {
    std____throw_length_error("basic_string::_M_replace");
  }
  iVar1 = *(int *)(this + 4);
  std__string___M_mutate((ulong)this,param_2 - iVar1,param_3 - param_2);
  if (uVar2 != 0) {
    _memcpy((void *)(*(int *)(this + 4) + (param_2 - iVar1)),param_4,uVar2);
  }
  return this;
}

/* std__string___M_mutate_97c336f4 @ 0x97c336f4 (344 bytes) */
int std__string___M_mutate_97c336f4(this, param_1, param_2, param_3)
  unsigned char *this;
  ulong param_1;
  ulong param_2;
  ulong param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  int iVar6;
  void *pvVar7;
  size_t sVar8;
  uint uVar9;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_40 [8];
  
  pvVar4 = *(void **)(this + 4);
  pvVar7 = (void *)((int)pvVar4 + param_2 + param_1);
  sVar8 = (*(int *)((int)pvVar4 + -0xc) - param_1) - param_2;
  uVar9 = (*(int *)((int)pvVar4 + -0xc) + param_3) - param_2;
  if ((*(int *)((int)pvVar4 + -4) < 1) && (uVar9 <= *(uint *)((int)pvVar4 + -8))) {
    if ((sVar8 != 0) && (param_2 != param_3)) {
      _memmove((void *)((int)pvVar4 + param_3 + param_1),pvVar7,sVar8);
      pvVar4 = *(void **)(this + 4);
    }
  }
  else {
    local_40[0] = *(undefined4 *)this;
    uVar5 = uVar9;
    if ((*(uint *)((int)pvVar4 + -8) < uVar9) &&
       ((0xfe3 < uVar9 && (uVar5 = *(uint *)((int)pvVar4 + -8) << 1, uVar5 < uVar9)))) {
      uVar5 = uVar9;
    }
    iVar6 = std__string___Rep___S_create(uVar5,(unsigned char *)local_40);
    pvVar4 = (void *)(iVar6 + 0xc);
    if (param_1 != 0) {
      _memcpy(pvVar4,*(void **)(this + 4),param_1);
    }
    if (sVar8 != 0) {
      _memcpy((void *)((int)pvVar4 + param_3 + param_1),pvVar7,sVar8);
    }
    iVar6 = *(int *)(this + 4);
    piVar2 = (int *)(iVar6 + -4);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(iVar6 + -0xc));
    }
    *(void **)(this + 4) = pvVar4;
  }
  *(undefined4 *)((int)pvVar4 + -4) = 0;
  *(uint *)(*(int *)(this + 4) + -0xc) = uVar9;
  *(undefined1 *)(*(int *)(this + 4) + uVar9) = 0;
  return;
}

/* std__string__string_char_const___97c3384c @ 0x97c3384c (4 bytes) */
int std__string__string_char_const___97c3384c(this, param_1, param_2, param_3)
  unsigned char *this;
  char *param_1;
  char *param_2;
  unsigned char *param_3;
{
  std__string__string_char_const__(this,param_1,param_2,param_3);
  return;
}

/* std__string__string_char_const___97c33850 @ 0x97c33850 (76 bytes) */
int std__string__string_char_const___97c33850(this, param_1, param_2, param_3)
  unsigned char *this;
  char *param_1;
  char *param_2;
  unsigned char *param_3;
{
  undefined4 uVar1;
  char *pcVar2;
  
  pcVar2 = std__string___S_construct_char_const__(this,param_2,param_3,0);
  uVar1 = *(undefined4 *)param_3;
  *(char **)(this + 4) = pcVar2;
  *(undefined4 *)this = uVar1;
  return;
}

/* std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState_____M_insert_aux @ 0x97c3389c (640 bytes) */
int std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState_____M_insert_aux(tAllocState, this, param_2, param_3)
  vector<TPoolAllocator::tAllocState;
  std::allocator<TPoolAllocator::tAllocState>> *this;
  undefined4 *param_2;
  undefined4 *param_3;
{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  void *pvVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  uint uVar12;
  char in_RESERVE;
  byte bVar13;
  undefined4 *local_40 [2];
  undefined4 *local_38;
  void *local_34;
  
  puVar1 = PTR__S_force_new_a7b7c0e8;
  puVar9 = *(undefined4 **)(this + 4);
  if (puVar9 == *(undefined4 **)(this + 8)) {
    iVar8 = *(int *)this;
    iVar3 = 1;
    iVar2 = (int)puVar9 - iVar8 >> 3;
    bVar13 = (iVar2 == 0) << 1;
    if (iVar2 != 0) {
      iVar3 = iVar2 << 1;
    }
    puVar9 = (undefined4 *)0x0;
    uVar12 = 0;
    if (iVar3 != 0) {
      uVar12 = iVar3 * 8;
      if (*(int *)PTR__S_force_new_a7b7c0e8 == 0) {
        pcVar6 = _getenv("GLIBCPP_FORCE_NEW");
        if (pcVar6 == (char *)0x0) {
          do {
            if (in_RESERVE != '\0') {
              uVar4 = storeWordConditionalIndexed(*(int *)puVar1 + -1,0,puVar1);
              *(undefined4 *)puVar1 = uVar4;
              bVar13 = 2;
            }
          } while (!(bool)(bVar13 >> 1 & 1));
        }
        else {
          do {
            if (in_RESERVE != '\0') {
              uVar4 = storeWordConditionalIndexed(*(int *)puVar1 + 1,0,puVar1);
              *(undefined4 *)puVar1 = uVar4;
              bVar13 = 2;
            }
          } while (!(bool)(bVar13 >> 1 & 1));
        }
      }
      puVar1 = PTR__S_free_list_a7b7c0e4;
      if ((uVar12 < 0x81) && (*(int *)PTR__S_force_new_a7b7c0e8 < 1)) {
        iVar3 = (uVar12 + 7 >> 1 & 0x7ffffffc) - 4;
        _pthread_mutex_lock((pthread_mutex_t *)PTR__S_node_allocator_lock_a7b7c0e0);
        puVar9 = *(undefined4 **)(puVar1 + iVar3);
        if (puVar9 == (undefined4 *)0x0) {
          puVar9 = (undefined4 *)std____default_alloc_template_true_0____S_refill(uVar12);
        }
        else {
          *(undefined4 *)(puVar1 + iVar3) = *puVar9;
        }
        if (puVar9 == (undefined4 *)0x0) {
          std____throw_bad_alloc();
        }
        _pthread_mutex_unlock((pthread_mutex_t *)PTR__S_node_allocator_lock_a7b7c0e0);
      }
      else {
        puVar9 = operator_new(uVar12);
      }
      iVar8 = *(int *)this;
    }
    local_38 = puVar9;
    std::
    __uninitialized_copy_aux<__gnu_cxx::__normal_iterator<TPoolAllocator::tAllocState*,std::vector<TPoolAllocator::tAllocState,std::allocator<TPoolAllocator::tAllocState>>>,__gnu_cxx::__normal_iterator<TPoolAllocator::tAllocState*,std::vector<TPoolAllocator::tAllocState,std::allocator<TPoolAllocator::tAllocState>>>>
              (local_40,iVar8,param_2,puVar9,0);
    if (local_40[0] != (undefined4 *)0x0) {
      uVar4 = *param_3;
      local_40[0][1] = param_3[1];
      *local_40[0] = uVar4;
    }
    std::
    __uninitialized_copy_aux<__gnu_cxx::__normal_iterator<TPoolAllocator::tAllocState*,std::vector<TPoolAllocator::tAllocState,std::allocator<TPoolAllocator::tAllocState>>>,__gnu_cxx::__normal_iterator<TPoolAllocator::tAllocState*,std::vector<TPoolAllocator::tAllocState,std::allocator<TPoolAllocator::tAllocState>>>>
              (local_40,param_2,*(undefined4 *)(this + 4),local_40[0] + 2,0);
    pvVar7 = *(void **)this;
    for (local_34 = pvVar7; local_34 != *(void **)(this + 4); local_34 = (void *)((int)local_34 + 8)
        ) {
    }
    iVar3 = *(int *)(this + 8) - (int)pvVar7 >> 3;
    if (iVar3 != 0) {
      std____default_alloc_template_true_0___deallocate(pvVar7,iVar3 << 3);
    }
    *(undefined4 **)(this + 4) = local_40[0];
    *(undefined4 **)this = local_38;
    *(uint *)(this + 8) = (int)local_38 + uVar12;
  }
  else {
    puVar11 = (undefined4 *)0x0;
    if (puVar9 != (undefined4 *)0x0) {
      puVar9[1] = puVar9[-1];
      *puVar9 = puVar9[-2];
      puVar11 = *(undefined4 **)(this + 4);
    }
    *(undefined4 **)(this + 4) = puVar11 + 2;
    uVar10 = param_3[1];
    iVar3 = (int)(puVar11 + -2) - (int)param_2 >> 3;
    uVar4 = *param_3;
    puVar9 = puVar11 + -2;
    if (0 < iVar3) {
      do {
        uVar5 = puVar9[-1];
        puVar11[-2] = puVar9[-2];
        puVar11[-1] = uVar5;
        iVar3 = iVar3 + -1;
        puVar11 = puVar11 + -2;
        puVar9 = puVar9 + -2;
      } while (iVar3 != 0);
    }
    param_2[1] = uVar10;
    *param_2 = uVar4;
  }
  return;
}

/* std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState______gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState____ @ 0x97c33b1c (92 bytes) */
void std::
     __uninitialized_copy_aux<__gnu_cxx::__normal_iterator<TPoolAllocator::tAllocState*,std::vector<TPoolAllocator::tAllocState,std::allocator<TPoolAllocator::tAllocState>>>,__gnu_cxx::__normal_iterator<TPoolAllocator::tAllocState*,std::vector<TPoolAllocator::tAllocState,std::allocator<TPoolAllocator::tAllocState>>>>
               (int *param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *param_1 = param_4;
  if (param_2 != param_3) {
    do {
      puVar2 = (undefined4 *)*param_1;
      iVar3 = 0;
      if (puVar2 != (undefined4 *)0x0) {
        uVar1 = *param_2;
        puVar2[1] = param_2[1];
        *puVar2 = uVar1;
        iVar3 = *param_1;
      }
      param_2 = param_2 + 2;
      *param_1 = iVar3 + 8;
    } while (param_2 != param_3);
    return;
  }
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase @ 0x97c33b78 (128 bytes) */
void 
std::
_Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
::_M_erase(_Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
           *this,unsigned char *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte bVar5;
  
  bVar5 = (param_1 == (unsigned char *)0x0) << 1;
  if (param_1 != (unsigned char *)0x0) {
    do {
      std::
      _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
      ::_M_erase((unsigned char *)this);
      iVar4 = *(int *)(param_1 + 0x14);
      piVar2 = (int *)(iVar4 + -4);
      param_1 = *(_Rb_tree_node **)(param_1 + 8);
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = iVar1;
          bVar5 = 2;
        }
      } while (!(bool)(bVar5 >> 1 & 1));
      if (iVar3 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
      }
    } while (param_1 != (unsigned char *)0x0);
  }
  return;
}

/* std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux @ 0x97c33bf8 (516 bytes) */
int std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux(vector<TSymbolTableLevel*,std::allocator<TSymbolTableLevel*>> *this,undefined4 *param_2,
          undefined4 *param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  char *pcVar5;
  void *pvVar6;
  uint uVar7;
  undefined4 uVar8;
  size_t sVar9;
  char in_RESERVE;
  byte bVar10;
  
  puVar1 = PTR__S_force_new_a7b7c0e8;
  puVar3 = *(undefined4 **)(this + 4);
  if (puVar3 == *(undefined4 **)(this + 8)) {
    pvVar6 = *(void **)this;
    iVar4 = 1;
    iVar2 = (int)puVar3 - (int)pvVar6 >> 2;
    bVar10 = (iVar2 == 0) << 1;
    if (iVar2 != 0) {
      iVar4 = iVar2 << 1;
    }
    puVar3 = (undefined4 *)0x0;
    uVar7 = 0;
    if (iVar4 != 0) {
      uVar7 = iVar4 * 4;
      if (*(int *)PTR__S_force_new_a7b7c0e8 == 0) {
        pcVar5 = _getenv("GLIBCPP_FORCE_NEW");
        if (pcVar5 == (char *)0x0) {
          do {
            if (in_RESERVE != '\0') {
              uVar8 = storeWordConditionalIndexed(*(int *)puVar1 + -1,0,puVar1);
              *(undefined4 *)puVar1 = uVar8;
              bVar10 = 2;
            }
          } while (!(bool)(bVar10 >> 1 & 1));
        }
        else {
          do {
            if (in_RESERVE != '\0') {
              uVar8 = storeWordConditionalIndexed(*(int *)puVar1 + 1,0,puVar1);
              *(undefined4 *)puVar1 = uVar8;
              bVar10 = 2;
            }
          } while (!(bool)(bVar10 >> 1 & 1));
        }
      }
      puVar1 = PTR__S_free_list_a7b7c0e4;
      if ((uVar7 < 0x81) && (*(int *)PTR__S_force_new_a7b7c0e8 < 1)) {
        iVar4 = (uVar7 + 7 >> 1 & 0x7ffffffc) - 4;
        _pthread_mutex_lock((pthread_mutex_t *)PTR__S_node_allocator_lock_a7b7c0e0);
        puVar3 = *(undefined4 **)(puVar1 + iVar4);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)
                   std____default_alloc_template_true_0____S_refill(uVar7 + 7 & 0xfffffff8);
        }
        else {
          *(undefined4 *)(puVar1 + iVar4) = *puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) {
          std____throw_bad_alloc();
        }
        _pthread_mutex_unlock((pthread_mutex_t *)PTR__S_node_allocator_lock_a7b7c0e0);
      }
      else {
        puVar3 = operator_new(uVar7);
      }
      pvVar6 = *(void **)this;
    }
    sVar9 = (int)param_2 - (int)pvVar6;
    _memmove(puVar3,pvVar6,sVar9);
    if ((int)puVar3 + sVar9 != 0) {
      *(undefined4 *)((int)puVar3 + sVar9) = *param_3;
    }
    iVar2 = *(int *)(this + 4);
    pvVar6 = (void *)((int)puVar3 + sVar9 + 4);
    _memmove(pvVar6,param_2,iVar2 - (int)param_2);
    iVar4 = *(int *)(this + 8) - (int)*(void **)this >> 2;
    if (iVar4 != 0) {
      std____default_alloc_template_true_0___deallocate(*(void **)this,iVar4 << 2);
    }
    *(int *)(this + 4) = (int)pvVar6 + (iVar2 - (int)param_2);
    *(undefined4 **)this = puVar3;
    *(uint *)(this + 8) = (int)puVar3 + uVar7;
  }
  else {
    iVar4 = 0;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = puVar3[-1];
      iVar4 = *(int *)(this + 4);
    }
    *(int *)(this + 4) = iVar4 + 4;
    uVar7 = (iVar4 + -4) - (int)param_2 & 0xfffffffc;
    uVar8 = *param_3;
    _memmove((void *)(iVar4 - uVar7),param_2,uVar7);
    *param_2 = uVar8;
  }
  return;
}

/* std__string__append_97c33dfc @ 0x97c33dfc (108 bytes) */
int std__string__append_97c33dfc(this, param_1, param_2)
  unsigned char *this;
  ulong param_1;
  int param_2;
{
  undefined3 in_register_00000014;
  int iVar1;
  
  iVar1 = *(int *)(this + 4);
  if (*(uint *)(iVar1 + -8) < param_1 + *(int *)(iVar1 + -0xc)) {
    std__string__reserve((ulong)this);
    iVar1 = *(int *)(this + 4);
  }
  iVar1 = iVar1 + *(int *)(iVar1 + -0xc);
  std__string__replace(this,iVar1,iVar1,param_1,CONCAT31(in_register_00000014,param_2));
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_erase @ 0x97c33e68 (128 bytes) */
void 
std::
_Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
::_M_erase(_Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
           *this,unsigned char *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte bVar5;
  
  bVar5 = (param_1 == (unsigned char *)0x0) << 1;
  if (param_1 != (unsigned char *)0x0) {
    do {
      std::
      _Rb_tree<std::string,std::pair<std::string_const,TSymbol*>,std::_Select1st<std::pair<std::string_const,TSymbol*>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TSymbol*>>>
      ::_M_erase((unsigned char *)this);
      iVar4 = *(int *)(param_1 + 0x14);
      piVar2 = (int *)(iVar4 + -4);
      param_1 = *(_Rb_tree_node **)(param_1 + 8);
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = iVar1;
          bVar5 = 2;
        }
      } while (!(bool)(bVar5 >> 1 & 1));
      if (iVar3 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
      }
    } while (param_1 != (unsigned char *)0x0);
  }
  return;
}

/* std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux @ 0x97c33ee8 (384 bytes) */
int std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux(TParameter, this, param_2, param_3)
  vector<TParameter;
  pool_allocator<TParameter>> *this;
  undefined4 *param_2;
  undefined4 *param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *local_30 [5];
  
  puVar6 = *(undefined4 **)(this + 8);
  if (puVar6 == *(undefined4 **)(this + 0xc)) {
    iVar3 = 1;
    iVar1 = (int)puVar6 - *(int *)(this + 4) >> 3;
    if (iVar1 != 0) {
      iVar3 = iVar1 << 1;
    }
    iVar1 = TPoolAllocator__allocate(*(ulong *)this);
    std::
    __uninitialized_copy_aux<__gnu_cxx::__normal_iterator<TParameter*,std::vector<TParameter,pool_allocator<TParameter>>>,__gnu_cxx::__normal_iterator<TParameter*,std::vector<TParameter,pool_allocator<TParameter>>>>
              (local_30,*(undefined4 *)(this + 4),param_2,iVar1,0);
    if (local_30[0] != (undefined4 *)0x0) {
      uVar4 = *param_3;
      local_30[0][1] = param_3[1];
      *local_30[0] = uVar4;
    }
    std::
    __uninitialized_copy_aux<__gnu_cxx::__normal_iterator<TParameter*,std::vector<TParameter,pool_allocator<TParameter>>>,__gnu_cxx::__normal_iterator<TParameter*,std::vector<TParameter,pool_allocator<TParameter>>>>
              (local_30,param_2,*(undefined4 *)(this + 8),local_30[0] + 2,0);
    for (iVar2 = *(int *)(this + 4); iVar2 != *(int *)(this + 8); iVar2 = iVar2 + 8) {
    }
    *(undefined4 **)(this + 8) = local_30[0];
    *(int *)(this + 0xc) = iVar1 + iVar3 * 8;
    *(int *)(this + 4) = iVar1;
  }
  else {
    puVar8 = (undefined4 *)0x0;
    if (puVar6 != (undefined4 *)0x0) {
      puVar6[1] = puVar6[-1];
      *puVar6 = puVar6[-2];
      puVar8 = *(undefined4 **)(this + 8);
    }
    *(undefined4 **)(this + 8) = puVar8 + 2;
    uVar7 = param_3[1];
    iVar3 = (int)(puVar8 + -2) - (int)param_2 >> 3;
    uVar4 = *param_3;
    puVar6 = puVar8 + -2;
    if (0 < iVar3) {
      do {
        uVar5 = puVar6[-1];
        puVar8[-2] = puVar6[-2];
        puVar8[-1] = uVar5;
        iVar3 = iVar3 + -1;
        puVar8 = puVar8 + -2;
        puVar6 = puVar6 + -2;
      } while (iVar3 != 0);
    }
    param_2[1] = uVar7;
    *param_2 = uVar4;
  }
  return;
}

/* std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine________M_erase @ 0x97c34068 (88 bytes) */
void 
std::
_Rb_tree<TVector<TTypeLine>*,std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>,std::_Select1st<std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>>,std::less<TVector<TTypeLine>*>,std::allocator<std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>>>
::_M_erase(_Rb_tree<TVector<TTypeLine>*,std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>,std::_Select1st<std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>>,std::less<TVector<TTypeLine>*>,std::allocator<std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>>>
           *this,unsigned char *param_1)

{
  _Rb_tree_node *p_Var1;
  
  while (param_1 != (unsigned char *)0x0) {
    std::
    _Rb_tree<TVector<TTypeLine>*,std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>,std::_Select1st<std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>>,std::less<TVector<TTypeLine>*>,std::allocator<std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>>>
    ::_M_erase((unsigned char *)this);
    p_Var1 = *(_Rb_tree_node **)(param_1 + 8);
    std____default_alloc_template_true_0___deallocate(param_1,0x18);
    param_1 = p_Var1;
  }
  return;
}

/* std__string__replace_97c340c0 @ 0x97c340c0 (160 bytes) */
int std__string__replace_97c340c0(this, param_2, param_3, param_4, param_5)
  unsigned char *this;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
{
  ulong uVar1;
  
  uVar1 = param_2 - *(int *)(this + 4);
  if (0x3ffffffcU - (*(int *)(*(int *)(this + 4) + -0xc) - (param_3 - param_2)) <= param_4) {
    std____throw_length_error("basic_string::replace");
  }
  std__string___M_mutate((ulong)this,uVar1,param_3 - param_2);
  if (param_4 != 0) {
    _memset((void *)(*(int *)(this + 4) + uVar1),param_5,param_4);
  }
  return this;
}

/* std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter______gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter____ @ 0x97c34160 (92 bytes) */
void std::
     __uninitialized_copy_aux<__gnu_cxx::__normal_iterator<TParameter*,std::vector<TParameter,pool_allocator<TParameter>>>,__gnu_cxx::__normal_iterator<TParameter*,std::vector<TParameter,pool_allocator<TParameter>>>>
               (int *param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *param_1 = param_4;
  if (param_2 != param_3) {
    do {
      puVar2 = (undefined4 *)*param_1;
      iVar3 = 0;
      if (puVar2 != (undefined4 *)0x0) {
        uVar1 = *param_2;
        puVar2[1] = param_2[1];
        *puVar2 = uVar1;
        iVar3 = *param_1;
      }
      param_2 = param_2 + 2;
      *param_1 = iVar3 + 8;
    } while (param_2 != param_3);
    return;
  }
  return;
}

/* std___Rb_tree_base_iterator___M_increment @ 0x97c341bc (120 bytes) */
int std___Rb_tree_base_iterator___M_increment(this)
  unsigned char *this;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)this;
  iVar1 = *(int *)(iVar2 + 0xc);
  if (iVar1 != 0) {
    *(int *)this = iVar1;
    if (*(int *)(iVar1 + 8) != 0) {
      do {
        iVar1 = *(int *)(*(int *)this + 8);
        *(int *)this = iVar1;
      } while (*(int *)(iVar1 + 8) != 0);
      return;
    }
    return;
  }
  iVar1 = *(int *)(iVar2 + 4);
  if (iVar2 == *(int *)(iVar1 + 0xc)) {
    do {
      *(int *)this = iVar1;
      iVar1 = *(int *)(iVar1 + 4);
      iVar2 = *(int *)this;
    } while (iVar2 == *(int *)(iVar1 + 0xc));
  }
  if (*(int *)(iVar2 + 0xc) != iVar1) {
    *(int *)this = iVar1;
    return;
  }
  return;
}

/* TType__copyType @ 0x97c34234 (800 bytes) */
int TType__copyType(this, param_1, param_2)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  string *psVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  ulong uVar9;
  undefined4 *puVar10;
  TType *pTVar11;
  string *psVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  uint uVar15;
  char *pcVar16;
  map *pmVar17;
  TVector *local_a0 [4];
  TVector *local_90;
  undefined4 local_80;
  TType *local_70;
  undefined4 local_6c;
  undefined4 local_60 [4];
  undefined4 local_50 [4];
  undefined4 local_40 [7];
  
  uVar4 = *(uint *)(this + 0x24);
  uVar1 = (*(uint *)(param_1 + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(this + 0x24) = uVar1 | uVar4 & 0xfe07ffff;
  uVar2 = *(uint *)(param_1 + 0x24) & 0xfe000000;
  *(uint *)(this + 0x24) = uVar2 | uVar1 | uVar4 & 0x7ffff;
  uVar15 = *(uint *)(param_1 + 0x24) & 0x7f800;
  *(uint *)(this + 0x24) = uVar15 | uVar2 | uVar1 | uVar4 & 0x7ff;
  uVar3 = (*(uint *)(param_1 + 0x24) >> 10 & 1) << 10;
  *(uint *)(this + 0x24) = uVar3 | uVar15 | uVar2 | uVar1 | uVar4 & 0x3ff;
  *(uint *)(this + 0x24) =
       (*(uint *)(param_1 + 0x24) >> 9 & 1) << 9 | uVar3 | uVar15 | uVar2 | uVar1 | uVar4 & 0x1ff;
  iVar6 = *(int *)(param_1 + 8);
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  if (iVar6 == 0) {
    *(undefined4 *)(this + 8) = 0;
  }
  else {
    std::
    _Rb_tree<TVector<TTypeLine>*,std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>,std::_Select1st<std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>>,std::less<TVector<TTypeLine>*>,std::allocator<std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>>>
    ::find(local_a0);
    local_90 = *(TVector **)param_2;
    if (local_a0[0] == local_90) {
      uVar9 = GetGlobalPoolAllocator();
      puVar10 = (undefined4 *)TPoolAllocator__allocate(uVar9);
      puVar13 = (undefined4 *)0x0;
      if (puVar10 != (undefined4 *)0x0) {
        local_80 = GetGlobalPoolAllocator();
        puVar10[3] = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        *puVar10 = local_80;
        puVar13 = puVar10;
      }
      *(undefined4 **)(this + 8) = puVar13;
      for (uVar15 = 0; iVar6 = *(int *)(*(int *)(param_1 + 8) + 4),
          uVar15 < (uint)(*(int *)(*(int *)(param_1 + 8) + 8) - iVar6 >> 3); uVar15 = uVar15 + 1) {
        local_6c = *(undefined4 *)(iVar6 + uVar15 * 8 + 4);
        pmVar17 = *(map **)(*(int *)(*(int *)(param_1 + 8) + 4) + uVar15 * 8);
        uVar9 = GetGlobalPoolAllocator();
        pTVar11 = (unsigned char *)TPoolAllocator__allocate(uVar9);
        *(undefined ***)pTVar11 = &PTR__TType_a7b7d590;
        ((int (*)())TType__copyType)(pTVar11,pmVar17);
        iVar6 = *(int *)(this + 8);
        puVar13 = *(undefined4 **)(iVar6 + 8);
        local_70 = pTVar11;
        if (puVar13 == *(undefined4 **)(iVar6 + 0xc)) {
          ((int (*)())std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux)(iVar6,puVar13,&local_70);
        }
        else {
          iVar7 = 0;
          if (puVar13 != (undefined4 *)0x0) {
            *puVar13 = pTVar11;
            puVar13[1] = local_6c;
            iVar7 = *(int *)(iVar6 + 8);
          }
          *(int *)(iVar6 + 8) = iVar7 + 8;
        }
      }
    }
    else {
      *(undefined4 *)(this + 8) = *(undefined4 *)(local_a0[0] + 0x14);
    }
  }
  *(undefined4 *)(this + 0xc) = 0;
  iVar6 = *(int *)(param_1 + 0xc);
  if (iVar6 != 0) {
    *(undefined1 *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba80;
    pcVar16 = *(char **)(iVar6 + 4);
    uVar9 = GetGlobalPoolAllocator();
    psVar12 = (unsigned char *)TPoolAllocator__allocate(uVar9);
    psVar5 = (unsigned char *)0x0;
    if (psVar12 != (unsigned char *)0x0) {
      local_60[0] = GetGlobalPoolAllocator();
      std__string__string(psVar12,pcVar16,(unsigned char *)local_60);
      psVar5 = psVar12;
    }
    *(string **)(this + 0xc) = psVar5;
  }
  *(undefined4 *)(this + 0x10) = 0;
  iVar6 = *(int *)(param_1 + 0x10);
  if (iVar6 != 0) {
    *(undefined1 *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba80;
    pcVar16 = *(char **)(iVar6 + 4);
    uVar9 = GetGlobalPoolAllocator();
    psVar12 = (unsigned char *)TPoolAllocator__allocate(uVar9);
    psVar5 = (unsigned char *)0x0;
    if (psVar12 != (unsigned char *)0x0) {
      local_50[0] = GetGlobalPoolAllocator();
      std__string__string(psVar12,pcVar16,(unsigned char *)local_50);
      psVar5 = psVar12;
    }
    *(string **)(this + 0x10) = psVar5;
  }
  *(undefined4 *)(this + 0x14) = 0;
  iVar6 = *(int *)(param_1 + 0x14);
  if (iVar6 != 0) {
    *(undefined1 *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba80;
    pcVar16 = *(char **)(iVar6 + 4);
    uVar9 = GetGlobalPoolAllocator();
    psVar12 = (unsigned char *)TPoolAllocator__allocate(uVar9);
    psVar5 = (unsigned char *)0x0;
    if (psVar12 != (unsigned char *)0x0) {
      local_40[0] = GetGlobalPoolAllocator();
      std__string__string(psVar12,pcVar16,(unsigned char *)local_40);
      psVar5 = psVar12;
    }
    *(string **)(this + 0x14) = psVar5;
  }
  uVar14 = *(undefined4 *)(param_1 + 0x1c);
  uVar8 = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x18) = uVar8;
  *(undefined4 *)(this + 0x1c) = uVar14;
  return;
}

/* TSymbol___TSymbol @ 0x97c34554 (36 bytes) */
int TSymbol___TSymbol(this)
  unsigned char *this;
{
  *(undefined ***)this = &PTR__TSymbol_a7b7d568;
  return;
}

/* TSymbol___TSymbol_97c34578 @ 0x97c34578 (36 bytes) */
int TSymbol___TSymbol_97c34578(this)
  unsigned char *this;
{
  *(undefined ***)this = &PTR__TSymbol_a7b7d568;
  return;
}

/* TSymbol__getMangledName @ 0x97c3459c (8 bytes) */
int TSymbol__getMangledName(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 4);
}

/* TSymbol__isFunction @ 0x97c345a4 (8 bytes) */
int TSymbol__isFunction()
{
  return 0;
}

/* TSymbol__isVariable @ 0x97c345ac (8 bytes) */
int TSymbol__isVariable()
{
  return 0;
}

/* TVariable___TVariable @ 0x97c345b4 (52 bytes) */
int TVariable___TVariable(this)
  unsigned char *this;
{
  *(undefined ***)this = &PTR__TSymbol_a7b7d568;
  *(undefined ***)(this + 0xc) = &PTR__TType_a7b7d590;
  return;
}

/* TVariable___TVariable_97c345e8 @ 0x97c345e8 (52 bytes) */
int TVariable___TVariable_97c345e8(this)
  unsigned char *this;
{
  *(undefined ***)this = &PTR__TSymbol_a7b7d568;
  *(undefined ***)(this + 0xc) = &PTR__TType_a7b7d590;
  return;
}

/* TVariable__isVariable @ 0x97c3461c (8 bytes) */
int TVariable__isVariable()
{
  return 1;
}

/* TFunction__isFunction @ 0x97c34624 (8 bytes) */
int TFunction__isFunction()
{
  return 1;
}

/* TFunction__getMangledName @ 0x97c3462c (8 bytes) */
int TFunction__getMangledName(this)
  unsigned char *this;
{
  return this + 0x44;
}

/* std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_______find @ 0x97c34634 (108 bytes) */
void std::
     _Rb_tree<TVector<TTypeLine>*,std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>,std::_Select1st<std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>>,std::less<TVector<TTypeLine>*>,std::allocator<std::pair<TVector<TTypeLine>*const,TVector<TTypeLine>*>>>
     ::find(TVector **param_1)

{
  TVector *pTVar1;
  TVector *pTVar2;
  undefined4 *in_r4;
  TVector *pTVar3;
  TVector *pTVar4;
  uint *in_r5;
  
  pTVar3 = (unsigned char *)*in_r4;
  pTVar4 = pTVar3;
  if (*(TVector **)(pTVar3 + 4) != (unsigned char *)0x0) {
    pTVar1 = *(TVector **)(pTVar3 + 4);
    do {
      if (*(uint *)(pTVar1 + 0x10) < *in_r5) {
        pTVar2 = *(TVector **)(pTVar1 + 0xc);
      }
      else {
        pTVar2 = *(TVector **)(pTVar1 + 8);
        pTVar4 = pTVar1;
      }
      pTVar1 = pTVar2;
    } while (pTVar2 != (unsigned char *)0x0);
  }
  if ((pTVar4 != pTVar3) && (*(uint *)(pTVar4 + 0x10) <= *in_r5)) {
    *param_1 = pTVar4;
    return;
  }
  *param_1 = pTVar3;
  return;
}

/* std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux @ 0x97c346a0 (384 bytes) */
int std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux(TTypeLine, this, param_2, param_3)
  vector<TTypeLine;
  pool_allocator<TTypeLine>> *this;
  undefined4 *param_2;
  undefined4 *param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *local_30 [5];
  
  puVar6 = *(undefined4 **)(this + 8);
  if (puVar6 == *(undefined4 **)(this + 0xc)) {
    iVar3 = 1;
    iVar1 = (int)puVar6 - *(int *)(this + 4) >> 3;
    if (iVar1 != 0) {
      iVar3 = iVar1 << 1;
    }
    iVar1 = TPoolAllocator__allocate(*(ulong *)this);
    std::
    __uninitialized_copy_aux<__gnu_cxx::__normal_iterator<TTypeLine*,std::vector<TTypeLine,pool_allocator<TTypeLine>>>,__gnu_cxx::__normal_iterator<TTypeLine*,std::vector<TTypeLine,pool_allocator<TTypeLine>>>>
              (local_30,*(undefined4 *)(this + 4),param_2,iVar1,0);
    if (local_30[0] != (undefined4 *)0x0) {
      uVar4 = *param_3;
      local_30[0][1] = param_3[1];
      *local_30[0] = uVar4;
    }
    std::
    __uninitialized_copy_aux<__gnu_cxx::__normal_iterator<TTypeLine*,std::vector<TTypeLine,pool_allocator<TTypeLine>>>,__gnu_cxx::__normal_iterator<TTypeLine*,std::vector<TTypeLine,pool_allocator<TTypeLine>>>>
              (local_30,param_2,*(undefined4 *)(this + 8),local_30[0] + 2,0);
    for (iVar2 = *(int *)(this + 4); iVar2 != *(int *)(this + 8); iVar2 = iVar2 + 8) {
    }
    *(undefined4 **)(this + 8) = local_30[0];
    *(int *)(this + 0xc) = iVar1 + iVar3 * 8;
    *(int *)(this + 4) = iVar1;
  }
  else {
    puVar8 = (undefined4 *)0x0;
    if (puVar6 != (undefined4 *)0x0) {
      puVar6[1] = puVar6[-1];
      *puVar6 = puVar6[-2];
      puVar8 = *(undefined4 **)(this + 8);
    }
    *(undefined4 **)(this + 8) = puVar8 + 2;
    uVar7 = param_3[1];
    iVar3 = (int)(puVar8 + -2) - (int)param_2 >> 3;
    uVar4 = *param_3;
    puVar6 = puVar8 + -2;
    if (0 < iVar3) {
      do {
        uVar5 = puVar6[-1];
        puVar8[-2] = puVar6[-2];
        puVar8[-1] = uVar5;
        iVar3 = iVar3 + -1;
        puVar8 = puVar8 + -2;
        puVar6 = puVar6 + -2;
      } while (iVar3 != 0);
    }
    param_2[1] = uVar7;
    *param_2 = uVar4;
  }
  return;
}

/* std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine______gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine____ @ 0x97c34820 (92 bytes) */
void std::
     __uninitialized_copy_aux<__gnu_cxx::__normal_iterator<TTypeLine*,std::vector<TTypeLine,pool_allocator<TTypeLine>>>,__gnu_cxx::__normal_iterator<TTypeLine*,std::vector<TTypeLine,pool_allocator<TTypeLine>>>>
               (int *param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *param_1 = param_4;
  if (param_2 != param_3) {
    do {
      puVar2 = (undefined4 *)*param_1;
      iVar3 = 0;
      if (puVar2 != (undefined4 *)0x0) {
        uVar1 = *param_2;
        puVar2[1] = param_2[1];
        *puVar2 = uVar1;
        iVar3 = *param_1;
      }
      param_2 = param_2 + 2;
      *param_1 = iVar3 + 8;
    } while (param_2 != param_3);
    return;
  }
  return;
}

/* std__operator__97c3487c @ 0x97c3487c (64 bytes) */
int std__operator__97c3487c(param_1, param_2)
  unsigned char *param_1;
  unsigned char *param_2;
{
  std__string__string(param_1,param_2);
  std__string__append(param_1);
  return param_1;
}

/* std__vector_int_pool_allocator_int_____M_insert_aux @ 0x97c348bc (252 bytes) */
int std__vector_int_pool_allocator_int_____M_insert_aux(int, this, param_2, param_3)
  vector<int;
  pool_allocator<int>> *this;
  undefined4 *param_2;
  undefined4 *param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  void *pvVar6;
  undefined4 uVar7;
  size_t sVar8;
  
  puVar3 = *(undefined4 **)(this + 8);
  if (puVar3 == *(undefined4 **)(this + 0xc)) {
    iVar4 = 1;
    iVar2 = (int)puVar3 - *(int *)(this + 4) >> 2;
    if (iVar2 != 0) {
      iVar4 = iVar2 << 1;
    }
    pvVar5 = (void *)TPoolAllocator__allocate(*(ulong *)this);
    sVar8 = (int)param_2 - (int)*(void **)(this + 4);
    _memmove(pvVar5,*(void **)(this + 4),sVar8);
    if ((int)pvVar5 + sVar8 != 0) {
      *(undefined4 *)((int)pvVar5 + sVar8) = *param_3;
    }
    iVar2 = *(int *)(this + 8);
    pvVar6 = (void *)((int)pvVar5 + sVar8 + 4);
    _memmove(pvVar6,param_2,iVar2 - (int)param_2);
    *(void **)(this + 0xc) = (void *)((int)pvVar5 + iVar4 * 4);
    *(int *)(this + 8) = (int)pvVar6 + (iVar2 - (int)param_2);
    *(void **)(this + 4) = pvVar5;
  }
  else {
    iVar4 = 0;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = puVar3[-1];
      iVar4 = *(int *)(this + 8);
    }
    *(int *)(this + 8) = iVar4 + 4;
    uVar1 = (iVar4 + -4) - (int)param_2 & 0xfffffffc;
    uVar7 = *param_3;
    _memmove((void *)(iVar4 - uVar1),param_2,uVar1);
    *param_2 = uVar7;
  }
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____find @ 0x97c349b8 (288 bytes) */
string * std::
         _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
         ::find(unsigned char *param_1)

{
  int iVar1;
  int iVar2;
  int in_r4;
  int in_r5;
  uint *puVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34 [2];
  
  iVar4 = *(int *)(in_r4 + 4);
  iVar6 = iVar4;
  if (*(int *)(iVar4 + 4) != 0) {
    pvVar5 = *(void **)(in_r5 + 4);
    iVar2 = *(int *)(iVar4 + 4);
    do {
      uVar7 = *(uint *)(*(int *)(iVar2 + 0x14) + -0xc);
      local_40 = uVar7;
      uVar8 = *(uint *)((int)pvVar5 + -0xc);
      local_3c = uVar8;
      puVar3 = &local_3c;
      if (uVar7 <= uVar8) {
        puVar3 = &local_40;
      }
      iVar1 = _memcmp(*(void **)(iVar2 + 0x14),pvVar5,*puVar3);
      if (iVar1 == 0) {
        iVar1 = uVar7 - uVar8;
      }
      if (iVar1 < 0) {
        iVar1 = *(int *)(iVar2 + 0xc);
      }
      else {
        iVar1 = *(int *)(iVar2 + 8);
        iVar6 = iVar2;
      }
      iVar2 = iVar1;
    } while (iVar1 != 0);
  }
  if (iVar6 != iVar4) {
    puVar3 = local_34;
    uVar7 = *(uint *)((int)*(void **)(in_r5 + 4) + -0xc);
    local_38 = uVar7;
    uVar8 = *(uint *)(*(int *)(iVar6 + 0x14) + -0xc);
    local_34[0] = uVar8;
    if (uVar7 <= uVar8) {
      puVar3 = &local_38;
    }
    iVar2 = _memcmp(*(void **)(in_r5 + 4),*(void **)(iVar6 + 0x14),*puVar3);
    if (iVar2 == 0) {
      iVar2 = uVar7 - uVar8;
    }
    if (-1 < iVar2) {
      *(int *)param_1 = iVar6;
      return param_1;
    }
  }
  *(int *)param_1 = iVar4;
  return param_1;
}

/* TShHandleBase___TShHandleBase @ 0x97c34ad8 (36 bytes) */
int TShHandleBase___TShHandleBase(this)
  unsigned char *this;
{
  *(undefined ***)this = &PTR__TShHandleBase_a7b7d700;
  return;
}

/* TShHandleBase___TShHandleBase_97c34afc @ 0x97c34afc (36 bytes) */
int TShHandleBase___TShHandleBase_97c34afc(this)
  unsigned char *this;
{
  *(undefined ***)this = &PTR__TShHandleBase_a7b7d700;
  operator_delete(this);
  return;
}

/* TShHandleBase__getAsCompiler @ 0x97c34b20 (8 bytes) */
int TShHandleBase__getAsCompiler()
{
  return 0;
}

/* TShHandleBase__getAsLinker @ 0x97c34b28 (8 bytes) */
int TShHandleBase__getAsLinker()
{
  return 0;
}

/* TGenericLinker__getAsLinker @ 0x97c34b30 (4 bytes) */
int TGenericLinker__getAsLinker()
{
  return;
}

/* TCompiler___TCompiler @ 0x97c34b34 (88 bytes) */
int TCompiler___TCompiler(this)
  unsigned char *this;
{
  *(undefined ***)this = &PTR__TCompiler_a7b7d850;
  TPoolAllocator___TPoolAllocator((unsigned char *)(this + 0x10));
  *(undefined ***)this = &PTR__TShHandleBase_a7b7d898;
  return;
}

/* TCompiler___TCompiler_97c34b8c @ 0x97c34b8c (92 bytes) */
int TCompiler___TCompiler_97c34b8c(this)
  unsigned char *this;
{
  *(undefined ***)this = &PTR__TCompiler_a7b7d850;
  TPoolAllocator___TPoolAllocator((unsigned char *)(this + 0x10));
  *(undefined ***)this = &PTR__TShHandleBase_a7b7d898;
  operator_delete(this);
  return;
}

/* TCompiler__getInfoSink @ 0x97c34be8 (8 bytes) */
int TCompiler__getInfoSink(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 4);
}

/* TCompiler__getPPStream @ 0x97c34bf0 (8 bytes) */
int TCompiler__getPPStream()
{
  return 0;
}

/* TCompiler__getAsCompiler @ 0x97c34bf8 (4 bytes) */
int TCompiler__getAsCompiler()
{
  return;
}

/* TCompiler__linkable @ 0x97c34bfc (8 bytes) */
int TCompiler__linkable(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0xc);
}

/* TCompiler__getStatsString @ 0x97c34c04 (8 bytes) */
int TCompiler__getStatsString()
{
  return 0;
}

