#include "decls.h"

/* std__string__append_97c33dfc @ 0x97c33dfc (108 bytes) */
int std__string__append_97c33dfc(this, param_1, param_2)
  unsigned char * this;
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
int std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_erase( unsigned char
           *this, unsigned char *param_1)

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
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_erase)((unsigned char *)this);
      iVar4 = *(int *)(param_1 + 0x14);
      piVar2 = (int *)(iVar4 + -4);
      param_1 = *(unsigned char **)(param_1 + 8);
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
int std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux(this, param_2, param_3)
  unsigned char * this;
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
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter______gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter____)(local_30,*(undefined4 *)(this + 4),param_2,iVar1,0);
    if (local_30[0] != (undefined4 *)0x0) {
      uVar4 = *param_3;
      local_30[0][1] = param_3[1];
      *local_30[0] = uVar4;
    }
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter______gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter____)(local_30,param_2,*(undefined4 *)(this + 8),local_30[0] + 2,0);
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
int std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine________M_erase( unsigned char
           *this, unsigned char *param_1)

{
  unsigned char * p_Var1;
  
  while (param_1 != (unsigned char *)0x0) {
    ((int (*)())std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine________M_erase)((unsigned char *)this);
    p_Var1 = *(unsigned char **)(param_1 + 8);
    std____default_alloc_template_true_0___deallocate(param_1,0x18);
    param_1 = p_Var1;
  }
  return;
}

/* std__string__replace_97c340c0 @ 0x97c340c0 (160 bytes) */
int std__string__replace_97c340c0(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
{
  ulong uVar1;
  
  uVar1 = param_2 - *(int *)(this + 4);
  if (0x3ffffffcU - (*(int *)(*(int *)(this + 4) + -0xc) - (param_3 - param_2)) <= param_4) {
    std____throw_length_error("basic_string__replace");
  }
  std__string___M_mutate((ulong)this,uVar1,param_3 - param_2);
  if (param_4 != 0) {
    _memset((void *)(*(int *)(this + 4) + uVar1),param_5,param_4);
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
int TType__copyType(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  unsigned char * psVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  ulong uVar9;
  undefined4 *puVar10;
  unsigned char * pTVar11;
  unsigned char * psVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  uint uVar15;
  char *pcVar16;
  unsigned char * pmVar17;
  unsigned char * local_a0 [4];
  unsigned char * local_90;
  undefined4 local_80;
  unsigned char * local_70;
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
    ((int (*)())std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_______find)(local_a0);
    local_90 = *(unsigned char **)param_2;
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
        pmVar17 = *(unsigned char **)(*(int *)(*(int *)(param_1 + 8) + 4) + uVar15 * 8);
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
    *(unsigned char **)(this + 0xc) = psVar5;
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
    *(unsigned char **)(this + 0x10) = psVar5;
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
    *(unsigned char **)(this + 0x14) = psVar5;
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
  unsigned char * this;
{
  *(undefined ***)this = &PTR__TSymbol_a7b7d568;
  return;
}

/* TSymbol___TSymbol_97c34578 @ 0x97c34578 (36 bytes) */
int TSymbol___TSymbol_97c34578(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__TSymbol_a7b7d568;
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

/* TVariable___TVariable @ 0x97c345b4 (52 bytes) */
int TVariable___TVariable(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__TSymbol_a7b7d568;
  *(undefined ***)(this + 0xc) = &PTR__TType_a7b7d590;
  return;
}

/* TVariable___TVariable_97c345e8 @ 0x97c345e8 (52 bytes) */
int TVariable___TVariable_97c345e8(this)
  unsigned char * this;
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
  unsigned char * this;
{
  return this + 0x44;
}

/* std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_______find @ 0x97c34634 (108 bytes) */
int std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_______find(param_1)
  unsigned char ** param_1;
{
  unsigned char * pTVar1;
  unsigned char * pTVar2;
  undefined4 *in_r4;
  unsigned char * pTVar3;
  unsigned char * pTVar4;
  uint *in_r5;
  
  pTVar3 = (unsigned char *)*in_r4;
  pTVar4 = pTVar3;
  if (*(unsigned char **)(pTVar3 + 4) != (unsigned char *)0x0) {
    pTVar1 = *(unsigned char **)(pTVar3 + 4);
    do {
      if (*(uint *)(pTVar1 + 0x10) < *in_r5) {
        pTVar2 = *(unsigned char **)(pTVar1 + 0xc);
      }
      else {
        pTVar2 = *(unsigned char **)(pTVar1 + 8);
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
int std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux(this, param_2, param_3)
  unsigned char * this;
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
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine______gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine____)(local_30,*(undefined4 *)(this + 4),param_2,iVar1,0);
    if (local_30[0] != (undefined4 *)0x0) {
      uVar4 = *param_3;
      local_30[0][1] = param_3[1];
      *local_30[0] = uVar4;
    }
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine______gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine____)(local_30,param_2,*(undefined4 *)(this + 8),local_30[0] + 2,0);
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

/* std__operator__97c3487c @ 0x97c3487c (64 bytes) */
int std__operator__97c3487c(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  std__string__string(param_1,param_2);
  std__string__append(param_1);
  return param_1;
}

/* std__vector_int_pool_allocator_int_____M_insert_aux @ 0x97c348bc (252 bytes) */
int std__vector_int_pool_allocator_int_____M_insert_aux(this, param_2, param_3)
  unsigned char * this;
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
int std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____find(param_1)
  unsigned char * param_1;
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
  unsigned char * this;
{
  *(undefined ***)this = &PTR__TShHandleBase_a7b7d700;
  return;
}

/* TShHandleBase___TShHandleBase_97c34afc @ 0x97c34afc (36 bytes) */
int TShHandleBase___TShHandleBase_97c34afc(this)
  unsigned char * this;
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
  unsigned char * this;
{
  *(undefined ***)this = &PTR__TCompiler_a7b7d850;
  TPoolAllocator___TPoolAllocator((unsigned char *)(this + 0x10));
  *(undefined ***)this = &PTR__TShHandleBase_a7b7d898;
  return;
}

/* TCompiler___TCompiler_97c34b8c @ 0x97c34b8c (92 bytes) */
int TCompiler___TCompiler_97c34b8c(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__TCompiler_a7b7d850;
  TPoolAllocator___TPoolAllocator((unsigned char *)(this + 0x10));
  *(undefined ***)this = &PTR__TShHandleBase_a7b7d898;
  operator_delete(this);
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
  TPoolAllocator__pop();
  TPoolAllocator__push();
  return this + 0x10;
}

/* TPPStreamCompiler__setOpimizationLevel @ 0x97c34c68 (8 bytes) */
int TPPStreamCompiler__setOpimizationLevel(this, param_2)
  unsigned char * this;
  undefined4 param_2;
{
  *(undefined4 *)(this + 0xc4) = param_2;
  return;
}

/* TPPStreamCompiler__setDebugOptions @ 0x97c34c70 (8 bytes) */
int TPPStreamCompiler__setDebugOptions(this, param_2)
  unsigned char * this;
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

/* std__domain_error___domain_error @ 0x97c34c80 (64 bytes) */
int std__domain_error___domain_error(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__domain_error_a7b7de00;
  std__logic_error___logic_error((unsigned char *)this);
  return;
}

/* std__invalid_argument___invalid_argument @ 0x97c34cc0 (64 bytes) */
int std__invalid_argument___invalid_argument(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__invalid_argument_a7b7dde8;
  std__logic_error___logic_error((unsigned char *)this);
  return;
}

/* std__length_error___length_error @ 0x97c34d00 (64 bytes) */
int std__length_error___length_error(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__length_error_a7b7ddd0;
  std__logic_error___logic_error((unsigned char *)this);
  return;
}

/* std__out_of_range___out_of_range @ 0x97c34d40 (64 bytes) */
int std__out_of_range___out_of_range(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__out_of_range_a7b7ddb8;
  std__logic_error___logic_error((unsigned char *)this);
  return;
}

/* std__range_error___range_error @ 0x97c34d80 (64 bytes) */
int std__range_error___range_error(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__range_error_a7b7dda0;
  std__runtime_error___runtime_error((unsigned char *)this);
  return;
}

/* std__overflow_error___overflow_error @ 0x97c34dc0 (64 bytes) */
int std__overflow_error___overflow_error(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__overflow_error_a7b7dd88;
  std__runtime_error___runtime_error((unsigned char *)this);
  return;
}

/* std__underflow_error___underflow_error @ 0x97c34e00 (64 bytes) */
int std__underflow_error___underflow_error(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__underflow_error_a7b7dd70;
  std__runtime_error___runtime_error((unsigned char *)this);
  return;
}

/* std__domain_error___domain_error_97c34e40 @ 0x97c34e40 (76 bytes) */
int std__domain_error___domain_error_97c34e40(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__domain_error_a7b7de00;
  std__logic_error___logic_error((unsigned char *)this);
  operator_delete(this);
  return;
}

/* std__invalid_argument___invalid_argument_97c34e8c @ 0x97c34e8c (76 bytes) */
int std__invalid_argument___invalid_argument_97c34e8c(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__invalid_argument_a7b7dde8;
  std__logic_error___logic_error((unsigned char *)this);
  operator_delete(this);
  return;
}

/* std__length_error___length_error_97c34ed8 @ 0x97c34ed8 (76 bytes) */
int std__length_error___length_error_97c34ed8(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__length_error_a7b7ddd0;
  std__logic_error___logic_error((unsigned char *)this);
  operator_delete(this);
  return;
}

/* std__out_of_range___out_of_range_97c34f24 @ 0x97c34f24 (76 bytes) */
int std__out_of_range___out_of_range_97c34f24(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__out_of_range_a7b7ddb8;
  std__logic_error___logic_error((unsigned char *)this);
  operator_delete(this);
  return;
}

/* std__range_error___range_error_97c34f70 @ 0x97c34f70 (76 bytes) */
int std__range_error___range_error_97c34f70(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__range_error_a7b7dda0;
  std__runtime_error___runtime_error((unsigned char *)this);
  operator_delete(this);
  return;
}

/* std__overflow_error___overflow_error_97c34fbc @ 0x97c34fbc (76 bytes) */
int std__overflow_error___overflow_error_97c34fbc(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__overflow_error_a7b7dd88;
  std__runtime_error___runtime_error((unsigned char *)this);
  operator_delete(this);
  return;
}

/* std__underflow_error___underflow_error_97c35008 @ 0x97c35008 (76 bytes) */
int std__underflow_error___underflow_error_97c35008(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__underflow_error_a7b7dd70;
  std__runtime_error___runtime_error((unsigned char *)this);
  operator_delete(this);
  return;
}

