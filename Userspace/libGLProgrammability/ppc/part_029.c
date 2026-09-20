#include "decls.h"

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc @ 0x97c33dfc (108 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(this, param_2, param_3)
  void *this;
  ulong param_2;
  int param_3;
{
  ulong uVar1;
  undefined3 in_register_00000014;
  int iVar2;
  
  iVar2 = *(int *)((int)this + 4);
  uVar1 = param_2 + *(int *)(iVar2 + -0xc);
  if (*(uint *)(iVar2 + -8) < uVar1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7reserveEm(this,uVar1);
    iVar2 = *(int *)((int)this + 4);
  }
  iVar2 = iVar2 + *(int *)(iVar2 + -0xc);
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7replaceEN9__gnu_cxx17__normal_iteratorIPcS3_EES7_mc)(this,iVar2,iVar2,param_2,CONCAT31(in_register_00000014,param_3));
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_erase @ 0x97c33e68 (128 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_erase( unsigned char
                *this, unsigned char *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte bVar5;
  undefined4 local_20 [4];
  
  bVar5 = (param_2 == (unsigned char *)0x0) << 1;
  if (param_2 != (unsigned char *)0x0) {
    do {
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_erase)(this,*(unsigned char **)(param_2 + 0xc));
      local_20[0] = *(undefined4 *)(param_2 + 0x10);
      iVar4 = *(int *)(param_2 + 0x14);
      piVar2 = (int *)(iVar4 + -4);
      param_2 = *(unsigned char **)(param_2 + 8);
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = iVar1;
          bVar5 = 2;
        }
      } while (!(bool)(bVar5 >> 1 & 1));
      if (iVar3 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(iVar4 + -0xc),local_20);
      }
    } while (param_2 != (unsigned char *)0x0);
  }
  return;
}

/* std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux @ 0x97c33ee8 (384 bytes) */
int std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux(this, param_2, param_3)
  undefined4 *this;
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
  
  puVar6 = (undefined4 *)this[2];
  if (puVar6 == (undefined4 *)this[3]) {
    iVar3 = 1;
    iVar1 = (int)puVar6 - this[1] >> 3;
    if (iVar1 != 0) {
      iVar3 = iVar1 << 1;
    }
    iVar1 = TPoolAllocator__allocate((unsigned char *)*this,iVar3 * 8);
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter______gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter____)(local_30,this[1],param_2,iVar1,0);
    if (local_30[0] != (undefined4 *)0x0) {
      uVar4 = *param_3;
      local_30[0][1] = param_3[1];
      *local_30[0] = uVar4;
    }
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter______gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter____)(local_30,param_2,this[2],local_30[0] + 2,0);
    for (iVar2 = this[1]; iVar2 != this[2]; iVar2 = iVar2 + 8) {
    }
    this[2] = local_30[0];
    this[3] = iVar1 + iVar3 * 8;
    this[1] = iVar1;
  }
  else {
    puVar8 = (undefined4 *)0x0;
    if (puVar6 != (undefined4 *)0x0) {
      puVar6[1] = puVar6[-1];
      *puVar6 = puVar6[-2];
      puVar8 = (undefined4 *)this[2];
    }
    this[2] = puVar8 + 2;
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
int std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine________M_erase( unsigned char
                *this, unsigned char *param_2)

{
  unsigned char * p_Var1;
  
  while (param_2 != (unsigned char *)0x0) {
    ((int (*)())std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine________M_erase)(this,*(unsigned char **)(param_2 + 0xc));
    p_Var1 = *(unsigned char **)(param_2 + 8);
    std____default_alloc_template_true_0___deallocate(param_2,0x18);
    param_2 = p_Var1;
  }
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7replaceEN9__gnu_cxx17__normal_iteratorIPcS3_EES7_mc @ 0x97c340c0 (160 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7replaceEN9__gnu_cxx17__normal_iteratorIPcS3_EES7_mc(this, param_2, param_3, param_4, param_5)
  void *this;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
{
  ulong uVar1;
  
  uVar1 = param_2 - *(int *)((int)this + 4);
  if (0x3ffffffcU - (*(int *)(*(int *)((int)this + 4) + -0xc) - (param_3 - param_2)) <= param_4) {
    std____throw_length_error("basic_string::replace");
  }
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE9_M_mutateEmmm(this,uVar1,param_3 - param_2,param_4)
  ;
  if (param_4 != 0) {
    _memset((void *)(*(int *)((int)this + 4) + uVar1),param_5,param_4);
  }
  return this;
}

/* std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter______gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter____ @ 0x97c34160 (92 bytes) */
int std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter______gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter____(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  int param_4;
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
  unsigned char * this;
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
int TType__copyType(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  unsigned char * pTVar9;
  undefined4 *puVar10;
  unsigned char * this_00;
  void *pvVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  uint uVar14;
  char *pcVar15;
  unsigned char * pTVar16;
  unsigned char * local_a0 [4];
  unsigned char * local_90;
  undefined4 local_80;
  unsigned char * local_70;
  undefined4 local_6c;
  undefined4 local_60 [4];
  undefined4 local_50 [4];
  undefined4 local_40 [7];
  
  uVar4 = *(uint *)(this + 0x24);
  uVar1 = (*(uint *)(param_2 + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(this + 0x24) = uVar1 | uVar4 & 0xfe07ffff;
  uVar2 = *(uint *)(param_2 + 0x24) & 0xfe000000;
  *(uint *)(this + 0x24) = uVar2 | uVar1 | uVar4 & 0x7ffff;
  uVar14 = *(uint *)(param_2 + 0x24) & 0x7f800;
  *(uint *)(this + 0x24) = uVar14 | uVar2 | uVar1 | uVar4 & 0x7ff;
  uVar3 = (*(uint *)(param_2 + 0x24) >> 10 & 1) << 10;
  *(uint *)(this + 0x24) = uVar3 | uVar14 | uVar2 | uVar1 | uVar4 & 0x3ff;
  *(uint *)(this + 0x24) =
       (*(uint *)(param_2 + 0x24) >> 9 & 1) << 9 | uVar3 | uVar14 | uVar2 | uVar1 | uVar4 & 0x1ff;
  iVar6 = *(int *)(param_2 + 8);
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_2 + 4);
  if (iVar6 == 0) {
    *(undefined4 *)(this + 8) = 0;
  }
  else {
    ((int (*)())std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_______find)(local_a0,param_3,this + 8);
    local_90 = *(unsigned char **)param_3;
    if (local_a0[0] == local_90) {
      pTVar9 = (unsigned char *)GetGlobalPoolAllocator();
      puVar10 = (undefined4 *)TPoolAllocator__allocate(pTVar9,0x10);
      puVar12 = (undefined4 *)0x0;
      if (puVar10 != (undefined4 *)0x0) {
        local_80 = GetGlobalPoolAllocator();
        puVar10[3] = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        *puVar10 = local_80;
        puVar12 = puVar10;
      }
      *(undefined4 **)(this + 8) = puVar12;
      for (uVar14 = 0; iVar6 = *(int *)(*(int *)(param_2 + 8) + 4),
          uVar14 < (uint)(*(int *)(*(int *)(param_2 + 8) + 8) - iVar6 >> 3); uVar14 = uVar14 + 1) {
        local_6c = *(undefined4 *)(iVar6 + uVar14 * 8 + 4);
        pTVar16 = *(unsigned char **)(*(int *)(*(int *)(param_2 + 8) + 4) + uVar14 * 8);
        pTVar9 = (unsigned char *)GetGlobalPoolAllocator();
        this_00 = (unsigned char *)TPoolAllocator__allocate(pTVar9,0x28);
        *(undefined ***)this_00 = &PTR___ZN5TTypeD1Ev_a7b7d590;
        ((int (*)())TType__copyType)(this_00,pTVar16,param_3);
        iVar6 = *(int *)(this + 8);
        puVar12 = *(undefined4 **)(iVar6 + 8);
        local_70 = this_00;
        if (puVar12 == *(undefined4 **)(iVar6 + 0xc)) {
          ((int (*)())std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux)(iVar6,puVar12,&local_70);
        }
        else {
          iVar7 = 0;
          if (puVar12 != (undefined4 *)0x0) {
            *puVar12 = this_00;
            puVar12[1] = local_6c;
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
  iVar6 = *(int *)(param_2 + 0xc);
  if (iVar6 != 0) {
    *(undefined1 *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba80;
    pcVar15 = *(char **)(iVar6 + 4);
    pTVar9 = (unsigned char *)GetGlobalPoolAllocator();
    pvVar11 = (void *)TPoolAllocator__allocate(pTVar9,8);
    pvVar5 = (void *)0x0;
    if (pvVar11 != (void *)0x0) {
      local_60[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (pvVar11,pcVar15,(unsigned char *)local_60);
      pvVar5 = pvVar11;
    }
    *(void **)(this + 0xc) = pvVar5;
  }
  *(undefined4 *)(this + 0x10) = 0;
  iVar6 = *(int *)(param_2 + 0x10);
  if (iVar6 != 0) {
    *(undefined1 *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba80;
    pcVar15 = *(char **)(iVar6 + 4);
    pTVar9 = (unsigned char *)GetGlobalPoolAllocator();
    pvVar11 = (void *)TPoolAllocator__allocate(pTVar9,8);
    pvVar5 = (void *)0x0;
    if (pvVar11 != (void *)0x0) {
      local_50[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (pvVar11,pcVar15,(unsigned char *)local_50);
      pvVar5 = pvVar11;
    }
    *(void **)(this + 0x10) = pvVar5;
  }
  *(undefined4 *)(this + 0x14) = 0;
  iVar6 = *(int *)(param_2 + 0x14);
  if (iVar6 != 0) {
    *(undefined1 *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *DAT_a7b7ba80;
    pcVar15 = *(char **)(iVar6 + 4);
    pTVar9 = (unsigned char *)GetGlobalPoolAllocator();
    pvVar11 = (void *)TPoolAllocator__allocate(pTVar9,8);
    pvVar5 = (void *)0x0;
    if (pvVar11 != (void *)0x0) {
      local_40[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (pvVar11,pcVar15,(unsigned char *)local_40);
      pvVar5 = pvVar11;
    }
    *(void **)(this + 0x14) = pvVar5;
  }
  uVar13 = *(undefined4 *)(param_2 + 0x1c);
  uVar8 = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x18) = uVar8;
  *(undefined4 *)(this + 0x1c) = uVar13;
  return;
}

/* __ZN7TSymbolD1Ev @ 0x97c34554 (36 bytes) */
int __ZN7TSymbolD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZN7TSymbolD1Ev_a7b7d568;
  return;
}

/* __ZN7TSymbolD0Ev @ 0x97c34578 (36 bytes) */
int __ZN7TSymbolD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZN7TSymbolD1Ev_a7b7d568;
  return;
}

/* TSymbol__getMangledName @ 0x97c3459c (8 bytes) */
int TSymbol__getMangledName(this)
  unsigned char * this;
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

/* __ZN9TVariableD1Ev @ 0x97c345b4 (52 bytes) */
int __ZN9TVariableD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZN7TSymbolD1Ev_a7b7d568;
  *(undefined ***)((int)this + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  return;
}

/* __ZN9TVariableD0Ev @ 0x97c345e8 (52 bytes) */
int __ZN9TVariableD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZN7TSymbolD1Ev_a7b7d568;
  *(undefined ***)((int)this + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d590;
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
  unsigned char * this;
{
  return this + 0x44;
}

/* std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_______find @ 0x97c34634 (108 bytes) */
int std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_______find(param_1, param_2, param_3)
  unsigned char ** param_1;
  undefined4 *param_2;
  uint *param_3;
{
  unsigned char * pTVar1;
  unsigned char * pTVar2;
  unsigned char * pTVar3;
  unsigned char * pTVar4;
  
  pTVar3 = (unsigned char *)*param_2;
  pTVar4 = pTVar3;
  if (*(unsigned char **)(pTVar3 + 4) != (unsigned char *)0x0) {
    pTVar1 = *(unsigned char **)(pTVar3 + 4);
    do {
      if (*(uint *)(pTVar1 + 0x10) < *param_3) {
        pTVar2 = *(unsigned char **)(pTVar1 + 0xc);
      }
      else {
        pTVar2 = *(unsigned char **)(pTVar1 + 8);
        pTVar4 = pTVar1;
      }
      pTVar1 = pTVar2;
    } while (pTVar2 != (unsigned char *)0x0);
  }
  if ((pTVar4 != pTVar3) && (*(uint *)(pTVar4 + 0x10) <= *param_3)) {
    *param_1 = pTVar4;
    return;
  }
  *param_1 = pTVar3;
  return;
}

/* std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux @ 0x97c346a0 (384 bytes) */
int std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux(this, param_2, param_3)
  undefined4 *this;
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
  
  puVar6 = (undefined4 *)this[2];
  if (puVar6 == (undefined4 *)this[3]) {
    iVar3 = 1;
    iVar1 = (int)puVar6 - this[1] >> 3;
    if (iVar1 != 0) {
      iVar3 = iVar1 << 1;
    }
    iVar1 = TPoolAllocator__allocate((unsigned char *)*this,iVar3 * 8);
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine______gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine____)(local_30,this[1],param_2,iVar1,0);
    if (local_30[0] != (undefined4 *)0x0) {
      uVar4 = *param_3;
      local_30[0][1] = param_3[1];
      *local_30[0] = uVar4;
    }
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine______gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine____)(local_30,param_2,this[2],local_30[0] + 2,0);
    for (iVar2 = this[1]; iVar2 != this[2]; iVar2 = iVar2 + 8) {
    }
    this[2] = local_30[0];
    this[3] = iVar1 + iVar3 * 8;
    this[1] = iVar1;
  }
  else {
    puVar8 = (undefined4 *)0x0;
    if (puVar6 != (undefined4 *)0x0) {
      puVar6[1] = puVar6[-1];
      *puVar6 = puVar6[-2];
      puVar8 = (undefined4 *)this[2];
    }
    this[2] = puVar8 + 2;
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
int std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine______gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine____(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  int param_4;
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

/* __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_ @ 0x97c3487c (64 bytes) */
int __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_(param_1, param_2, param_3)
  unsigned char * param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(param_1,param_2);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendERKS3_(param_1,param_3);
  return param_1;
}

/* std__vector_int_pool_allocator_int_____M_insert_aux @ 0x97c348bc (252 bytes) */
int std__vector_int_pool_allocator_int_____M_insert_aux(this, param_2, param_3)
  undefined4 *this;
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
  
  puVar3 = (undefined4 *)this[2];
  if (puVar3 == (undefined4 *)this[3]) {
    iVar4 = 1;
    iVar2 = (int)puVar3 - this[1] >> 2;
    if (iVar2 != 0) {
      iVar4 = iVar2 << 1;
    }
    pvVar5 = (void *)TPoolAllocator__allocate((unsigned char *)*this,iVar4 * 4);
    sVar8 = (int)param_2 - (int)this[1];
    _memmove(pvVar5,(void *)this[1],sVar8);
    if ((int)pvVar5 + sVar8 != 0) {
      *(undefined4 *)((int)pvVar5 + sVar8) = *param_3;
    }
    iVar2 = this[2];
    pvVar6 = (void *)((int)pvVar5 + sVar8 + 4);
    _memmove(pvVar6,param_2,iVar2 - (int)param_2);
    this[3] = (void *)((int)pvVar5 + iVar4 * 4);
    this[2] = (int)pvVar6 + (iVar2 - (int)param_2);
    this[1] = pvVar5;
  }
  else {
    iVar4 = 0;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = puVar3[-1];
      iVar4 = this[2];
    }
    this[2] = iVar4 + 4;
    uVar1 = (iVar4 + -4) - (int)param_2 & 0xfffffffc;
    uVar7 = *param_3;
    _memmove((void *)(iVar4 - uVar1),param_2,uVar1);
    *param_2 = uVar7;
  }
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____find @ 0x97c349b8 (288 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____find(param_1, param_2, param_3)
  unsigned char * param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
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
  
  iVar4 = *(int *)(param_2 + 4);
  iVar6 = iVar4;
  if (*(int *)(iVar4 + 4) != 0) {
    pvVar5 = *(void **)(param_3 + 4);
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
    uVar7 = *(uint *)((int)*(void **)(param_3 + 4) + -0xc);
    local_38 = uVar7;
    uVar8 = *(uint *)(*(int *)(iVar6 + 0x14) + -0xc);
    local_34[0] = uVar8;
    if (uVar7 <= uVar8) {
      puVar3 = &local_38;
    }
    iVar2 = _memcmp(*(void **)(param_3 + 4),*(void **)(iVar6 + 0x14),*puVar3);
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

/* __ZN13TShHandleBaseD1Ev @ 0x97c34ad8 (36 bytes) */
int __ZN13TShHandleBaseD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZN13TShHandleBaseD1Ev_a7b7d700;
  return;
}

/* __ZN13TShHandleBaseD0Ev @ 0x97c34afc (36 bytes) */
int __ZN13TShHandleBaseD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZN13TShHandleBaseD1Ev_a7b7d700;
  __ZdlPv(this);
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

/* __ZN9TCompilerD1Ev @ 0x97c34b34 (88 bytes) */
int __ZN9TCompilerD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZN9TCompilerD1Ev_a7b7d850;
  __ZN14TPoolAllocatorD1Ev((void *)((int)this + 0x10));
  *(undefined ***)this = &PTR___ZN13TShHandleBaseD1Ev_a7b7d898;
  return;
}

/* __ZN9TCompilerD0Ev @ 0x97c34b8c (92 bytes) */
int __ZN9TCompilerD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZN9TCompilerD1Ev_a7b7d850;
  __ZN14TPoolAllocatorD1Ev((void *)((int)this + 0x10));
  *(undefined ***)this = &PTR___ZN13TShHandleBaseD1Ev_a7b7d898;
  __ZdlPv(this);
  return;
}

/* TCompiler__getInfoSink @ 0x97c34be8 (8 bytes) */
int TCompiler__getInfoSink(this)
  unsigned char * this;
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
  unsigned char * this;
{
  return *(undefined4 *)(this + 0xc);
}

/* TCompiler__getStatsString @ 0x97c34c04 (8 bytes) */
int TCompiler__getStatsString()
{
  return 0;
}

/* TCompiler__getPPStreamString @ 0x97c34c0c (8 bytes) */
int TCompiler__getPPStreamString()
{
  return 0;
}

/* TCompiler__getShaderToProgramString @ 0x97c34c14 (8 bytes) */
int TCompiler__getShaderToProgramString()
{
  return 0;
}

/* TCompiler__getTableString @ 0x97c34c1c (8 bytes) */
int TCompiler__getTableString()
{
  return 0;
}

/* TCompiler__setOpimizationLevel @ 0x97c34c24 (4 bytes) */
int TCompiler__setOpimizationLevel()
{
  return;
}

/* TCompiler__setDebugOptions @ 0x97c34c28 (4 bytes) */
int TCompiler__setDebugOptions()
{
  return;
}

/* TCompiler__getNewCompilationAllocator @ 0x97c34c2c (60 bytes) */
int TCompiler__getNewCompilationAllocator(this)
  unsigned char * this;
{
  unsigned char * this_00;
  
  this_00 = (unsigned char *)(this + 0x10);
  TPoolAllocator__pop(this_00);
  TPoolAllocator__push(this_00);
  return this_00;
}

/* TPPStreamCompiler__setOpimizationLevel @ 0x97c34c68 (8 bytes) */
int TPPStreamCompiler__setOpimizationLevel(this, param_2)
  int this;
  undefined4 param_2;
{
  *(undefined4 *)(this + 0xc4) = param_2;
  return;
}

/* TPPStreamCompiler__setDebugOptions @ 0x97c34c70 (8 bytes) */
int TPPStreamCompiler__setDebugOptions(this, param_2)
  int this;
  undefined4 param_2;
{
  *(undefined4 *)(this + 0xc0) = param_2;
  return;
}

/* TPPStreamCompiler__getPPStream @ 0x97c34c78 (8 bytes) */
int TPPStreamCompiler__getPPStream(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x74);
}

/* __ZNSt12domain_errorD1Ev @ 0x97c34c80 (64 bytes) */
int __ZNSt12domain_errorD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt12domain_errorD1Ev_a7b7de00;
  __ZNSt11logic_errorD2Ev(this);
  return;
}

/* __ZNSt16invalid_argumentD1Ev @ 0x97c34cc0 (64 bytes) */
int __ZNSt16invalid_argumentD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt16invalid_argumentD1Ev_a7b7dde8;
  __ZNSt11logic_errorD2Ev(this);
  return;
}

/* __ZNSt12length_errorD1Ev @ 0x97c34d00 (64 bytes) */
int __ZNSt12length_errorD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt12length_errorD1Ev_a7b7ddd0;
  __ZNSt11logic_errorD2Ev(this);
  return;
}

/* __ZNSt12out_of_rangeD1Ev @ 0x97c34d40 (64 bytes) */
int __ZNSt12out_of_rangeD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt12out_of_rangeD1Ev_a7b7ddb8;
  __ZNSt11logic_errorD2Ev(this);
  return;
}

/* __ZNSt11range_errorD1Ev @ 0x97c34d80 (64 bytes) */
int __ZNSt11range_errorD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt11range_errorD1Ev_a7b7dda0;
  __ZNSt13runtime_errorD2Ev(this);
  return;
}

/* __ZNSt14overflow_errorD1Ev @ 0x97c34dc0 (64 bytes) */
int __ZNSt14overflow_errorD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt14overflow_errorD1Ev_a7b7dd88;
  __ZNSt13runtime_errorD2Ev(this);
  return;
}

/* __ZNSt15underflow_errorD1Ev @ 0x97c34e00 (64 bytes) */
int __ZNSt15underflow_errorD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt15underflow_errorD1Ev_a7b7dd70;
  __ZNSt13runtime_errorD2Ev(this);
  return;
}

/* __ZNSt12domain_errorD0Ev @ 0x97c34e40 (76 bytes) */
int __ZNSt12domain_errorD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt12domain_errorD1Ev_a7b7de00;
  __ZNSt11logic_errorD2Ev(this);
  __ZdlPv(this);
  return;
}

/* __ZNSt16invalid_argumentD0Ev @ 0x97c34e8c (76 bytes) */
int __ZNSt16invalid_argumentD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt16invalid_argumentD1Ev_a7b7dde8;
  __ZNSt11logic_errorD2Ev(this);
  __ZdlPv(this);
  return;
}

/* __ZNSt12length_errorD0Ev @ 0x97c34ed8 (76 bytes) */
int __ZNSt12length_errorD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt12length_errorD1Ev_a7b7ddd0;
  __ZNSt11logic_errorD2Ev(this);
  __ZdlPv(this);
  return;
}

/* __ZNSt12out_of_rangeD0Ev @ 0x97c34f24 (76 bytes) */
int __ZNSt12out_of_rangeD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt12out_of_rangeD1Ev_a7b7ddb8;
  __ZNSt11logic_errorD2Ev(this);
  __ZdlPv(this);
  return;
}

/* __ZNSt11range_errorD0Ev @ 0x97c34f70 (76 bytes) */
int __ZNSt11range_errorD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt11range_errorD1Ev_a7b7dda0;
  __ZNSt13runtime_errorD2Ev(this);
  __ZdlPv(this);
  return;
}

/* __ZNSt14overflow_errorD0Ev @ 0x97c34fbc (76 bytes) */
int __ZNSt14overflow_errorD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt14overflow_errorD1Ev_a7b7dd88;
  __ZNSt13runtime_errorD2Ev(this);
  __ZdlPv(this);
  return;
}

/* __ZNSt15underflow_errorD0Ev @ 0x97c35008 (76 bytes) */
int __ZNSt15underflow_errorD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt15underflow_errorD1Ev_a7b7dd70;
  __ZNSt13runtime_errorD2Ev(this);
  __ZdlPv(this);
  return;
}

