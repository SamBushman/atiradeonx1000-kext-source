#include "decls.h"

/* std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_insert @ 0x97c30ec8 (356 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_insert(param_1, param_2, param_3)
  unsigned char * param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  int iVar1;
  unsigned char * p_Var2;
  uint *puVar3;
  int in_r6;
  unsigned char * in_r7;
  uint uVar4;
  uint uVar5;
  uint local_30;
  uint local_2c [4];
  
  if ((in_r6 == *(int *)(param_2 + 4)) || (param_3 != (unsigned char *)0x0)) {
LAB_97c30f44:
    p_Var2 = (unsigned char *)TPoolAllocator__allocate(*(ulong *)param_2);
    if ((unsigned char *)(p_Var2 + 0x10) != (unsigned char *)0x0) {
      std__string__string((unsigned char *)(p_Var2 + 0x10),in_r7);
      *(undefined4 *)(p_Var2 + 0x18) = *(undefined4 *)(in_r7 + 8);
    }
    *(unsigned char **)(in_r6 + 8) = p_Var2;
    iVar1 = *(int *)(param_2 + 4);
    if (in_r6 != iVar1) {
      if (in_r6 == *(int *)(iVar1 + 8)) {
        *(unsigned char **)(iVar1 + 8) = p_Var2;
      }
      goto LAB_97c30fe4;
    }
    *(unsigned char **)(in_r6 + 4) = p_Var2;
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
    if (iVar1 < 0) goto LAB_97c30f44;
    p_Var2 = (unsigned char *)TPoolAllocator__allocate(*(ulong *)param_2);
    if ((unsigned char *)(p_Var2 + 0x10) != (unsigned char *)0x0) {
      std__string__string((unsigned char *)(p_Var2 + 0x10),in_r7);
      *(undefined4 *)(p_Var2 + 0x18) = *(undefined4 *)(in_r7 + 8);
    }
    *(unsigned char **)(in_r6 + 0xc) = p_Var2;
    iVar1 = *(int *)(param_2 + 4);
    if (in_r6 != *(int *)(iVar1 + 0xc)) goto LAB_97c30fe4;
  }
  *(unsigned char **)(iVar1 + 0xc) = p_Var2;
LAB_97c30fe4:
  *(int *)(p_Var2 + 4) = in_r6;
  *(undefined4 *)(p_Var2 + 0xc) = 0;
  *(undefined4 *)(p_Var2 + 8) = 0;
  ((int (*)())std___Rb_tree_rebalance)(p_Var2,(unsigned char **)(*(int *)(param_2 + 4) + 4));
  *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
  *(unsigned char **)param_1 = p_Var2;
  return param_1;
}

/* std__string___Rep___S_create_97c3102c @ 0x97c3102c (172 bytes) */
int std__string___Rep___S_create_97c3102c(param_1, param_2)
  ulong param_1;
  unsigned char * param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  
  if (0x3ffffffc < param_1) {
    std____throw_length_error("basic_string___S_create");
  }
  uVar1 = param_1 + 0x1d;
  if (uVar1 < 0x1001) {
    if (param_1 + 0xd < 0x81) goto LAB_97c310a4;
    uVar1 = 0x80 - (uVar1 & 0x7f) & 0x7f;
  }
  else {
    uVar1 = 0x1000 - (uVar1 & 0xfff) & 0xfff;
  }
  param_1 = param_1 + uVar1;
LAB_97c310a4:
  puVar2 = (undefined4 *)TPoolAllocator__allocate(*(ulong *)param_2);
  *puVar2 = 0;
  puVar2[1] = param_1;
  puVar2[2] = 0;
  return;
}

/* std___Rb_tree_base_iterator___M_decrement @ 0x97c310d8 (144 bytes) */
int std___Rb_tree_base_iterator___M_decrement(this)
  unsigned char * this;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)this;
  if ((*piVar3 == 0) && (*(int **)(piVar3[1] + 4) == piVar3)) {
    *(int *)this = piVar3[3];
    return;
  }
  iVar2 = piVar3[2];
  if (iVar2 == 0) {
    iVar2 = piVar3[1];
    if (piVar3 == *(int **)(iVar2 + 8)) {
      do {
        *(int *)this = iVar2;
        iVar2 = *(int *)(iVar2 + 4);
      } while (*(int *)this == *(int *)(iVar2 + 8));
    }
    *(int *)this = iVar2;
    return;
  }
  for (iVar1 = *(int *)(iVar2 + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
    iVar2 = iVar1;
  }
  *(int *)this = iVar2;
  return;
}

/* std___Rb_tree_rebalance @ 0x97c31168 (328 bytes) */
int std___Rb_tree_rebalance(param_1, param_2)
  unsigned char * param_1;
  unsigned char ** param_2;
{
  int iVar1;
  unsigned char * p_Var2;
  unsigned char * p_Var3;
  unsigned char * p_Var4;
  
  *(undefined4 *)param_1 = 0;
  p_Var2 = *param_2;
  if (param_1 != p_Var2) {
    p_Var3 = *(unsigned char **)(param_1 + 4);
    iVar1 = *(int *)p_Var3;
    while (iVar1 == 0) {
      p_Var4 = *(unsigned char **)(p_Var3 + 4);
      p_Var2 = *(unsigned char **)(p_Var4 + 8);
      if (p_Var3 == p_Var2) {
        p_Var2 = *(unsigned char **)(p_Var4 + 0xc);
        if ((p_Var2 == (unsigned char *)0x0) || (*(int *)p_Var2 != 0)) {
          p_Var4 = param_1;
          p_Var2 = p_Var3;
          if (param_1 == *(unsigned char **)(p_Var3 + 0xc)) {
            ((int (*)())std___Rb_tree_rotate_left)(p_Var3,param_2);
            p_Var2 = *(unsigned char **)(p_Var3 + 4);
            p_Var4 = p_Var3;
          }
          p_Var3 = *(unsigned char **)(p_Var2 + 4);
          *(undefined4 *)p_Var2 = 1;
          *(undefined4 *)p_Var3 = 0;
          ((int (*)())std___Rb_tree_rotate_right)(p_Var3,param_2);
        }
        else {
LAB_97c31228:
          *(undefined4 *)p_Var3 = 1;
          *(undefined4 *)p_Var2 = 1;
          *(undefined4 *)p_Var4 = 0;
        }
      }
      else {
        if ((p_Var2 != (unsigned char *)0x0) && (*(int *)p_Var2 == 0)) goto LAB_97c31228;
        p_Var4 = param_1;
        p_Var2 = p_Var3;
        if (param_1 == *(unsigned char **)(p_Var3 + 8)) {
          ((int (*)())std___Rb_tree_rotate_right)(p_Var3,param_2);
          p_Var2 = *(unsigned char **)(p_Var3 + 4);
          p_Var4 = p_Var3;
        }
        p_Var3 = *(unsigned char **)(p_Var2 + 4);
        *(undefined4 *)p_Var2 = 1;
        *(undefined4 *)p_Var3 = 0;
        ((int (*)())std___Rb_tree_rotate_left)(p_Var3,param_2);
      }
      p_Var2 = *param_2;
      if (p_Var4 == p_Var2) break;
      p_Var3 = *(unsigned char **)(p_Var4 + 4);
      param_1 = p_Var4;
      iVar1 = *(int *)p_Var3;
    }
  }
  *(undefined4 *)p_Var2 = 1;
  return;
}

/* TType__getTypeName @ 0x97c312b0 (8 bytes) */
int TType__getTypeName(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x10);
}

/* TType___TType @ 0x97c312b8 (36 bytes) */
int TType___TType(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__TType_a7b7cf48;
  return;
}

/* TType___TType_97c312dc @ 0x97c312dc (36 bytes) */
int TType___TType_97c312dc(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__TType_a7b7cf48;
  return;
}

/* TType__isArray @ 0x97c31300 (12 bytes) */
int TType__isArray(this)
  unsigned char * this;
{
  return *(uint *)(this + 0x24) >> 9 & 1;
}

/* TType__getInstanceSize @ 0x97c3130c (40 bytes) */
int TType__getInstanceSize(this)
  unsigned char * this;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(this + 0x24);
  if ((uVar1 & 0x400) != 0) {
    iVar2 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
    return iVar2 * iVar2;
  }
  return (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
}

/* TType__isMatrix @ 0x97c31334 (12 bytes) */
int TType__isMatrix(this)
  unsigned char * this;
{
  return *(uint *)(this + 0x24) >> 10 & 1;
}

/* TType__isVector @ 0x97c31340 (40 bytes) */
int TType__isVector(this)
  unsigned char * this;
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x24);
  if ((int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18 < 2) {
    return 0;
  }
  if ((uVar1 & 0x400) != 0) {
    return 0;
  }
  return 1;
}

/* TType__setType @ 0x97c31368 (32 bytes) */
int TType__setType(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  undefined4 param_6;
{
  *(undefined4 *)(this + 4) = param_6;
  *(uint *)(this + 0x24) =
       (param_5 & 1) << 9 |
       (param_4 & 1) << 10 |
       (param_3 & 0xff) << 0xb | (param_2 & 0x3f) << 0x13 | *(uint *)(this + 0x24) & 0xfe0001ff;
  return;
}

/* TType__setType_97c31388 @ 0x97c31388 (40 bytes) */
int TType__setType_97c31388(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  uint param_2;
  uint param_3;
  uint param_4;
  int param_5;
{
  *(uint *)(this + 0x24) =
       (param_4 & 1) << 10 |
       (param_3 & 0xff) << 0xb | (param_2 & 0x3f) << 0x13 | *(uint *)(this + 0x24) & 0xfe0003ff;
  if (param_5 == 0) {
    return;
  }
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_5 + 8);
  return;
}

/* TType__setTypeName @ 0x97c313b0 (132 bytes) */
int TType__setTypeName(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  unsigned char * psVar1;
  ulong uVar2;
  unsigned char * this_00;
  char *pcVar3;
  undefined4 local_20 [4];
  
  *(undefined1 *)(*(int *)(param_1 + 4) + *(int *)(*(int *)(param_1 + 4) + -0xc)) = *DAT_a7b7b718;
  pcVar3 = *(char **)(param_1 + 4);
  uVar2 = GetGlobalPoolAllocator();
  this_00 = (unsigned char *)TPoolAllocator__allocate(uVar2);
  psVar1 = (unsigned char *)0x0;
  if (this_00 != (unsigned char *)0x0) {
    local_20[0] = GetGlobalPoolAllocator();
    std__string__string(this_00,pcVar3,(unsigned char *)local_20);
    psVar1 = this_00;
  }
  *(unsigned char **)(this + 0x10) = psVar1;
  return;
}

/* TType__setFieldName @ 0x97c31434 (132 bytes) */
int TType__setFieldName(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  unsigned char * psVar1;
  ulong uVar2;
  unsigned char * this_00;
  char *pcVar3;
  undefined4 local_20 [4];
  
  *(undefined1 *)(*(int *)(param_1 + 4) + *(int *)(*(int *)(param_1 + 4) + -0xc)) = *DAT_a7b7b718;
  pcVar3 = *(char **)(param_1 + 4);
  uVar2 = GetGlobalPoolAllocator();
  this_00 = (unsigned char *)TPoolAllocator__allocate(uVar2);
  psVar1 = (unsigned char *)0x0;
  if (this_00 != (unsigned char *)0x0) {
    local_20[0] = GetGlobalPoolAllocator();
    std__string__string(this_00,pcVar3,(unsigned char *)local_20);
    psVar1 = this_00;
  }
  *(unsigned char **)(this + 0xc) = psVar1;
  return;
}

/* TType__getFieldName @ 0x97c314b8 (8 bytes) */
int TType__getFieldName(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0xc);
}

/* TType__getBasicType @ 0x97c314c0 (12 bytes) */
int TType__getBasicType(this)
  unsigned char * this;
{
  return *(uint *)(this + 0x24) >> 0x13 & 0x3f;
}

/* TType__getQualifier @ 0x97c314cc (12 bytes) */
int TType__getQualifier(this)
  unsigned char * this;
{
  return *(uint *)(this + 0x24) >> 0x19;
}

/* TType__changeQualifier @ 0x97c314d8 (16 bytes) */
int TType__changeQualifier(this, param_2)
  unsigned char * this;
  int param_2;
{
  *(uint *)(this + 0x24) = param_2 << 0x19 | *(uint *)(this + 0x24) & 0x1ffffff;
  return;
}

/* TType__getNominalSize @ 0x97c314e8 (16 bytes) */
int TType__getNominalSize(this)
  unsigned char * this;
{
  return (int)(*(uint *)(this + 0x24) << 0xd | *(uint *)(this + 0x24) >> 0x13) >> 0x18;
}

/* std___Rb_tree_rotate_left @ 0x97c314f8 (92 bytes) */
int std___Rb_tree_rotate_left(param_1, param_2)
  unsigned char * param_1;
  unsigned char ** param_2;
{
  int iVar1;
  unsigned char * p_Var2;
  
  p_Var2 = *(unsigned char **)(param_1 + 0xc);
  iVar1 = *(int *)(p_Var2 + 8);
  *(int *)(param_1 + 0xc) = iVar1;
  if (iVar1 != 0) {
    *(unsigned char **)(iVar1 + 4) = param_1;
  }
  *(undefined4 *)(p_Var2 + 4) = *(undefined4 *)(param_1 + 4);
  if (param_1 == *param_2) {
    *param_2 = p_Var2;
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
    if (param_1 == *(unsigned char **)(iVar1 + 8)) {
      *(unsigned char **)(iVar1 + 8) = p_Var2;
    }
    else {
      *(unsigned char **)(iVar1 + 0xc) = p_Var2;
    }
  }
  *(unsigned char **)(param_1 + 4) = p_Var2;
  *(unsigned char **)(p_Var2 + 8) = param_1;
  return;
}

/* std___Rb_tree_rotate_right @ 0x97c31554 (92 bytes) */
int std___Rb_tree_rotate_right(param_1, param_2)
  unsigned char * param_1;
  unsigned char ** param_2;
{
  int iVar1;
  unsigned char * p_Var2;
  
  p_Var2 = *(unsigned char **)(param_1 + 8);
  iVar1 = *(int *)(p_Var2 + 0xc);
  *(int *)(param_1 + 8) = iVar1;
  if (iVar1 != 0) {
    *(unsigned char **)(iVar1 + 4) = param_1;
  }
  *(undefined4 *)(p_Var2 + 4) = *(undefined4 *)(param_1 + 4);
  if (param_1 == *param_2) {
    *param_2 = p_Var2;
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
    if (param_1 == *(unsigned char **)(iVar1 + 0xc)) {
      *(unsigned char **)(iVar1 + 0xc) = p_Var2;
    }
    else {
      *(unsigned char **)(iVar1 + 8) = p_Var2;
    }
  }
  *(unsigned char **)(param_1 + 4) = p_Var2;
  *(unsigned char **)(p_Var2 + 0xc) = param_1;
  return;
}

/* std__string__assign_97c315b0 @ 0x97c315b0 (200 bytes) */
int std__string__assign_97c315b0(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  int local_30 [4];
  int local_20;
  
  iVar4 = *(int *)(param_1 + 4);
  if ((unsigned char *)(*(int *)(this + 4) + -0xc) != (unsigned char *)(iVar4 + -0xc)) {
    local_20 = *(int *)param_1;
    local_30[0] = *(int *)this;
    if ((*(int *)(iVar4 + -4) < 0) || (local_30[0] != local_20)) {
      iVar4 = std__string___Rep___M_clone((unsigned char *)(iVar4 + -0xc),(ulong)local_30);
    }
    else {
      piVar2 = (int *)(iVar4 + -4);
      do {
        if (in_RESERVE != '\0') {
          iVar5 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
          *piVar2 = iVar5;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
    }
    iVar5 = *(int *)(this + 4);
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
      std__string___Rep___M_destroy((unsigned char *)(iVar5 + -0xc));
    }
    *(int *)(this + 4) = iVar4;
  }
  return this;
}

/* std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux @ 0x97c31678 (252 bytes) */
int std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux(this, param_2, param_3)
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

/* std__vector_TIntermNode__pool_allocator_TIntermNode_____erase @ 0x97c31774 (96 bytes) */
int std__vector_TIntermNode__pool_allocator_TIntermNode_____erase(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  void *param_3;
{
  void *pvVar1;
  void *pvVar2;
  
  pvVar2 = *(void **)(param_2 + 8);
  pvVar1 = (void *)((int)param_3 + 4);
  if (pvVar1 != pvVar2) {
    _memmove(param_3,pvVar1,(int)pvVar2 - (int)pvVar1);
    pvVar2 = *(void **)(param_2 + 8);
  }
  *(int *)(param_2 + 8) = (int)pvVar2 + -4;
  *param_1 = param_3;
  return param_1;
}

/* std__vector_TIntermNode__pool_allocator_TIntermNode_____insert @ 0x97c317d4 (152 bytes) */
int std__vector_TIntermNode__pool_allocator_TIntermNode_____insert(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = *(undefined4 **)(param_2 + 8);
  iVar3 = *(int *)(param_2 + 4);
  iVar1 = (int)param_3 - iVar3;
  if ((puVar2 == *(undefined4 **)(param_2 + 0xc)) || (param_3 != puVar2)) {
    ((int (*)())std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux)(param_2,param_3,param_4);
    iVar3 = *(int *)(param_2 + 4);
  }
  else {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_4;
      iVar3 = *(int *)(param_2 + 4);
      puVar2 = *(undefined4 **)(param_2 + 8);
    }
    *(undefined4 **)(param_2 + 8) = puVar2 + 1;
  }
  *param_1 = iVar3 + (iVar1 >> 2) * 4;
  return param_1;
}

/* std__vector_TIntermNode__pool_allocator_TIntermNode______M_range_insert___gnu_cxx____normal_iterator_TIntermNode___std__vector_TIntermNode__pool_allocator_TIntermNode_____ @ 0x97c3186c (424 bytes) */
int std__vector_TIntermNode__pool_allocator_TIntermNode______M_range_insert___gnu_cxx____normal_iterator_TIntermNode___std__vector_TIntermNode__pool_allocator_TIntermNode_____(param_1, param_2, param_3, param_4)
  ulong *param_1;
  void *param_2;
  void *param_3;
  void *param_4;
{
  void *pvVar1;
  size_t sVar2;
  size_t sVar3;
  uint uVar4;
  void *pvVar5;
  uint uVar6;
  void *pvVar8;
  ulong uVar9;
  uint local_40;
  uint local_3c [5];
  uint *puVar7;
  
  if (param_3 != param_4) {
    sVar3 = (int)param_4 - (int)param_3;
    pvVar5 = (void *)param_1[2];
    local_3c[0] = (int)sVar3 >> 2;
    if ((uint)((int)(param_1[3] - (int)pvVar5) >> 2) < local_3c[0]) {
      puVar7 = local_3c;
      uVar4 = (int)((int)pvVar5 - param_1[1]) >> 2;
      local_40 = uVar4;
      if (local_3c[0] <= uVar4) {
        puVar7 = &local_40;
      }
      uVar6 = *puVar7;
      pvVar5 = (void *)TPoolAllocator__allocate(*param_1);
      sVar2 = (int)param_2 - (int)param_1[1];
      pvVar1 = (void *)((int)pvVar5 + sVar2);
      _memmove(pvVar5,(void *)param_1[1],sVar2);
      pvVar8 = (void *)((int)pvVar1 + sVar3);
      _memmove(pvVar1,param_3,sVar3);
      uVar9 = param_1[2];
      _memmove(pvVar8,param_2,uVar9 - (int)param_2);
      param_1[3] = (ulong)((int)pvVar5 + (uVar4 + uVar6) * 4);
      param_1[2] = (int)pvVar8 + (uVar9 - (int)param_2);
      param_1[1] = (ulong)pvVar5;
    }
    else {
      uVar4 = (int)pvVar5 - (int)param_2 >> 2;
      if (local_3c[0] < uVar4) {
        pvVar1 = (void *)((int)pvVar5 + local_3c[0] * -4);
        _memmove(pvVar5,pvVar1,(int)pvVar5 - (int)pvVar1);
        param_1[2] = param_1[2] + local_3c[0] * 4;
        uVar4 = (int)pvVar5 + (local_3c[0] * -4 - (int)param_2) & 0xfffffffc;
        _memmove((void *)((int)pvVar5 - uVar4),param_2,uVar4);
      }
      else {
        pvVar8 = (void *)((int)param_3 + uVar4 * 4);
        _memmove(pvVar5,pvVar8,(int)param_4 - (int)pvVar8);
        pvVar1 = (void *)(param_1[2] + (local_3c[0] - uVar4) * 4);
        param_1[2] = (ulong)pvVar1;
        _memmove(pvVar1,param_2,(int)pvVar5 - (int)param_2);
        sVar3 = (int)pvVar8 - (int)param_3;
        param_1[2] = param_1[2] + uVar4 * 4;
      }
      _memmove(param_2,param_3,sVar3);
    }
  }
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____operator_ @ 0x97c31a14 (280 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____operator_( unsigned char
            *this, unsigned char *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (this != (unsigned char
               *)param_1) {
    if (*(int *)(this + 8) != 0) {
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase)((unsigned char *)this);
      *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
      *(undefined4 *)(*(int *)(this + 4) + 4) = 0;
      *(int *)(*(int *)(this + 4) + 0xc) = *(int *)(this + 4);
      *(undefined4 *)(this + 8) = 0;
    }
    *(undefined4 *)(this + 8) = 0;
    if (*(unsigned char **)(*(int *)(param_1 + 4) + 4) == (unsigned char *)0x0) {
      *(undefined4 *)(*(int *)(this + 4) + 4) = 0;
      *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
      *(int *)(*(int *)(this + 4) + 0xc) = *(int *)(this + 4);
    }
    else {
      uVar3 = ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy)((unsigned char *)this,*(unsigned char **)(*(int *)(param_1 + 4) + 4));
      *(undefined4 *)(*(int *)(this + 4) + 4) = uVar3;
      iVar2 = *(int *)(*(int *)(this + 4) + 4);
      for (iVar1 = *(int *)(iVar2 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
        iVar2 = iVar1;
      }
      *(int *)(*(int *)(this + 4) + 8) = iVar2;
      iVar2 = *(int *)(*(int *)(this + 4) + 4);
      for (iVar1 = *(int *)(iVar2 + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
        iVar2 = iVar1;
      }
      *(int *)(*(int *)(this + 4) + 0xc) = iVar2;
      *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
    }
  }
  return this;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy @ 0x97c31b2c (280 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy( unsigned char
          *this, unsigned char *param_1, unsigned char *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  unsigned char * p_Var5;
  undefined4 *puVar6;
  
  puVar3 = (undefined4 *)TPoolAllocator__allocate(*(ulong *)this);
  if ((unsigned char *)(puVar3 + 4) != (unsigned char *)0x0) {
    std__string__string((unsigned char *)(puVar3 + 4),(unsigned char *)(param_1 + 0x10));
    std__string__string((unsigned char *)(puVar3 + 6),(unsigned char *)(param_1 + 0x18));
  }
  uVar2 = *(undefined4 *)param_1;
  puVar3[3] = 0;
  p_Var5 = *(unsigned char **)(param_1 + 0xc);
  *puVar3 = uVar2;
  puVar3[1] = param_2;
  puVar3[2] = 0;
  if (p_Var5 != (unsigned char *)0x0) {
    uVar2 = ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy)((unsigned char *)this,p_Var5);
    puVar3[3] = uVar2;
  }
  puVar1 = puVar3;
  for (puVar6 = *(undefined4 **)(param_1 + 8); puVar6 != (undefined4 *)0x0;
      puVar6 = (undefined4 *)puVar6[2]) {
    puVar4 = (undefined4 *)TPoolAllocator__allocate(*(ulong *)this);
    if ((unsigned char *)(puVar4 + 4) != (unsigned char *)0x0) {
      std__string__string((unsigned char *)(puVar4 + 4),(unsigned char *)(puVar6 + 4));
      std__string__string((unsigned char *)(puVar4 + 6),(unsigned char *)(puVar6 + 6));
    }
    puVar4[3] = 0;
    p_Var5 = (unsigned char *)puVar6[3];
    uVar2 = *puVar6;
    puVar4[2] = 0;
    *puVar4 = uVar2;
    puVar4[1] = puVar1;
    puVar1[2] = puVar4;
    if (p_Var5 != (unsigned char *)0x0) {
      uVar2 = ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy)((unsigned char *)this,p_Var5);
      puVar4[3] = uVar2;
    }
    puVar1 = puVar4;
  }
  return puVar3;
}

/* TType__setStructSize @ 0x97c31c44 (284 bytes) */
int TType__setStructSize(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  piVar3 = *(int **)(param_1 + 4);
  do {
    if (piVar3 == *(int **)(param_1 + 8)) {
      *(int *)(this + 0x18) = iVar2;
      return iVar2;
    }
    iVar1 = (**(code **)(*(int *)*piVar3 + 0x38))();
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*(int *)*piVar3 + 0x34))();
      if ((iVar1 != 0) || (iVar1 = (**(code **)(*(int *)*piVar3 + 0x3c))(), iVar1 != 0)) {
        iVar1 = (**(code **)(*(int *)*piVar3 + 0x30))();
        goto LAB_97c31d28;
      }
      if (*(int *)(*piVar3 + 8) != 0) {
        iVar1 = ((int (*)())TType__setStructSize)((unsigned char *)this);
        goto LAB_97c31d28;
      }
      iVar2 = iVar2 + 1;
    }
    else {
      if (((int *)*piVar3)[2] == 0) {
        iVar1 = (**(code **)(*(int *)*piVar3 + 0x30))();
      }
      else {
        iVar1 = ((int (*)())TType__setStructSize)((unsigned char *)this);
      }
      iVar1 = iVar1 * *(int *)(*piVar3 + 4);
LAB_97c31d28:
      iVar2 = iVar2 + iVar1;
    }
    piVar3 = piVar3 + 2;
  } while( true );
}

/* TIntermNode__getLine @ 0x97c31d60 (8 bytes) */
int TIntermNode__getLine(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 4);
}

/* TIntermNode__setLine @ 0x97c31d68 (8 bytes) */
int TIntermNode__setLine(this, param_1)
  unsigned char * this;
  int param_1;
{
  *(int *)(this + 4) = param_1;
  return;
}

/* TIntermNode__getAsConstantUnion @ 0x97c31d70 (8 bytes) */
int TIntermNode__getAsConstantUnion()
{
  return 0;
}

/* TIntermNode__getAsAggregate @ 0x97c31d78 (8 bytes) */
int TIntermNode__getAsAggregate()
{
  return 0;
}

/* TIntermNode__getAsBinaryNode @ 0x97c31d80 (8 bytes) */
int TIntermNode__getAsBinaryNode()
{
  return 0;
}

/* TIntermNode__getAsSelectionNode @ 0x97c31d88 (8 bytes) */
int TIntermNode__getAsSelectionNode()
{
  return 0;
}

/* TIntermNode__getAsSymbolNode @ 0x97c31d90 (8 bytes) */
int TIntermNode__getAsSymbolNode()
{
  return 0;
}

/* TIntermTyped__getAsTyped @ 0x97c31d98 (4 bytes) */
int TIntermTyped__getAsTyped()
{
  return;
}

/* TIntermTyped__setType @ 0x97c31d9c (152 bytes) */
int TIntermTyped__setType(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  uVar6 = *(undefined4 *)(param_1 + 8);
  uVar10 = *(undefined4 *)(param_1 + 0xc);
  uVar12 = *(undefined4 *)(param_1 + 0x10);
  uVar11 = *(undefined4 *)(param_1 + 0x14);
  uVar9 = *(undefined4 *)(param_1 + 0x18);
  uVar8 = *(undefined4 *)(param_1 + 0x1c);
  uVar7 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x10) = uVar6;
  *(undefined4 *)(this + 0x14) = uVar10;
  *(undefined4 *)(this + 0x18) = uVar12;
  *(undefined4 *)(this + 0x1c) = uVar11;
  *(undefined4 *)(this + 0x20) = uVar9;
  *(undefined4 *)(this + 0x24) = uVar8;
  *(undefined4 *)(this + 0x28) = uVar7;
  uVar5 = *(uint *)(this + 0x2c);
  uVar2 = *(uint *)(param_1 + 0x24) & 0xfe000000;
  *(uint *)(this + 0x2c) = uVar2 | uVar5 & 0x1ffffff;
  uVar3 = (*(uint *)(param_1 + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(this + 0x2c) = uVar3 | uVar2 | uVar5 & 0x7ffff;
  uVar1 = *(uint *)(param_1 + 0x24) & 0x7f800;
  *(uint *)(this + 0x2c) = uVar1 | uVar3 | uVar2 | uVar5 & 0x7ff;
  uVar4 = (*(uint *)(param_1 + 0x24) >> 10 & 1) << 10;
  *(uint *)(this + 0x2c) = uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x3ff;
  *(uint *)(this + 0x2c) =
       (*(uint *)(param_1 + 0x24) >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x1ff;
  return;
}

/* TIntermTyped__getType @ 0x97c31e34 (192 bytes) */
int TIntermTyped__getType()
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *in_r3;
  int in_r4;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  uVar12 = *(undefined4 *)(in_r4 + 0x28);
  uVar11 = *(undefined4 *)(in_r4 + 0x10);
  uVar10 = *(undefined4 *)(in_r4 + 0x14);
  uVar9 = *(undefined4 *)(in_r4 + 0x18);
  uVar8 = *(undefined4 *)(in_r4 + 0x1c);
  uVar7 = *(undefined4 *)(in_r4 + 0x20);
  uVar6 = *(undefined4 *)(in_r4 + 0x24);
  in_r3[1] = *(undefined4 *)(in_r4 + 0xc);
  in_r3[2] = uVar11;
  in_r3[3] = uVar10;
  in_r3[4] = uVar9;
  in_r3[5] = uVar8;
  in_r3[6] = uVar7;
  in_r3[7] = uVar6;
  in_r3[8] = uVar12;
  *in_r3 = &PTR__TType_a7b7cff8;
  uVar5 = in_r3[9];
  uVar2 = *(uint *)(in_r4 + 0x2c) & 0xfe000000;
  in_r3[9] = uVar2 | uVar5 & 0x1ffffff;
  uVar3 = (*(uint *)(in_r4 + 0x2c) >> 0x13 & 0x3f) << 0x13;
  in_r3[9] = uVar3 | uVar2 | uVar5 & 0x7ffff;
  uVar1 = *(uint *)(in_r4 + 0x2c) & 0x7f800;
  in_r3[9] = uVar1 | uVar3 | uVar2 | uVar5 & 0x7ff;
  uVar4 = (*(uint *)(in_r4 + 0x2c) >> 10 & 1) << 10;
  in_r3[9] = uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x3ff;
  in_r3[9] = (*(uint *)(in_r4 + 0x2c) >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar5 & 0x1ff
  ;
  return;
}

/* TIntermTyped__getTypePointer @ 0x97c31ef4 (8 bytes) */
int TIntermTyped__getTypePointer(this)
  unsigned char * this;
{
  return this + 8;
}

/* TIntermTyped__getBasicType @ 0x97c31efc (12 bytes) */
int TIntermTyped__getBasicType(this)
  unsigned char * this;
{
  return *(uint *)(this + 0x2c) >> 0x13 & 0x3f;
}

/* TIntermTyped__getQualifier @ 0x97c31f08 (12 bytes) */
int TIntermTyped__getQualifier(this)
  unsigned char * this;
{
  return *(uint *)(this + 0x2c) >> 0x19;
}

/* TIntermTyped__getNominalSize @ 0x97c31f14 (16 bytes) */
int TIntermTyped__getNominalSize(this)
  unsigned char * this;
{
  return (int)(*(uint *)(this + 0x2c) << 0xd | *(uint *)(this + 0x2c) >> 0x13) >> 0x18;
}

/* TIntermTyped__getSize @ 0x97c31f24 (40 bytes) */
int TIntermTyped__getSize(this)
  unsigned char * this;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(this + 0x2c);
  if ((uVar1 & 0x400) != 0) {
    iVar2 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
    return iVar2 * iVar2;
  }
  return (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
}

/* TIntermTyped__isMatrix @ 0x97c31f4c (12 bytes) */
int TIntermTyped__isMatrix(this)
  unsigned char * this;
{
  return *(uint *)(this + 0x2c) >> 10 & 1;
}

/* TIntermTyped__isArray @ 0x97c31f58 (12 bytes) */
int TIntermTyped__isArray(this)
  unsigned char * this;
{
  return *(uint *)(this + 0x2c) >> 9 & 1;
}

/* TIntermTyped__isVector @ 0x97c31f64 (40 bytes) */
int TIntermTyped__isVector(this)
  unsigned char * this;
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x2c);
  if ((int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18 < 2) {
    return 0;
  }
  if ((uVar1 & 0x400) != 0) {
    return 0;
  }
  return 1;
}

/* TIntermTyped___TIntermTyped @ 0x97c31f8c (52 bytes) */
int TIntermTyped___TIntermTyped(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d040;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7cff8;
  return;
}

/* TIntermTyped___TIntermTyped_97c31fc0 @ 0x97c31fc0 (52 bytes) */
int TIntermTyped___TIntermTyped_97c31fc0(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d040;
  *(undefined ***)(this + 8) = &PTR__TType_a7b7cff8;
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase @ 0x97c31ff4 (192 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase( unsigned char
           *this, unsigned char *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  unsigned char * p_Var5;
  char in_RESERVE;
  byte bVar6;
  
  bVar6 = (param_1 == (unsigned char *)0x0) << 1;
  if (param_1 != (unsigned char *)0x0) {
    do {
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase)((unsigned char *)this);
      iVar4 = *(int *)(param_1 + 0x1c);
      piVar2 = (int *)(iVar4 + -4);
      p_Var5 = *(unsigned char **)(param_1 + 8);
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = iVar1;
          bVar6 = 2;
        }
      } while (!(bool)(bVar6 >> 1 & 1));
      if (iVar3 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
      }
      iVar4 = *(int *)(param_1 + 0x14);
      piVar2 = (int *)(iVar4 + -4);
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = iVar1;
          bVar6 = 2;
        }
      } while (!(bool)(bVar6 >> 1 & 1));
      if (iVar3 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
      }
      param_1 = p_Var5;
    } while (p_Var5 != (unsigned char *)0x0);
  }
  return;
}

/* TIntermNode__getAsTyped @ 0x97c320b4 (8 bytes) */
int TIntermNode__getAsTyped()
{
  return 0;
}

/* TIntermNode___TIntermNode @ 0x97c320bc (36 bytes) */
int TIntermNode___TIntermNode(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d040;
  return;
}

/* TIntermNode___TIntermNode_97c320e0 @ 0x97c320e0 (36 bytes) */
int TIntermNode___TIntermNode_97c320e0(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d040;
  return;
}

/* getQualifierString @ 0x97c32104 (280 bytes) */
int getQualifierString(param_1)
  undefined4 param_1;
{
  switch(param_1) {
  case 0:
    return "Temporary";
  case 1:
    return "Global";
  case 2:
  case 0xc:
    return "const";
  case 3:
    return "attribute";
  case 4:
  case 5:
    return "varying";
  case 6:
    return "uniform";
  case 7:
    return "input";
  case 8:
    return "output";
  case 9:
    return "in";
  case 10:
    return "out";
  case 0xb:
    return "inout";
  case 0xd:
    return "Position";
  case 0xe:
    return "PointSize";
  case 0xf:
    return "ClipVertex";
  case 0x10:
    return "Face";
  case 0x11:
    return "FragCoord";
  case 0x12:
    return "FragColor";
  case 0x13:
    return "FragDepth";
  default:
    return "unknown qualifier";
  }
}

/* TType__getBasicString @ 0x97c3226c (220 bytes) */
int TType__getBasicString(param_1)
  undefined4 param_1;
{
  switch(param_1) {
  case 0:
    return "void";
  case 1:
    return "float";
  case 2:
    return "int";
  case 3:
    return "bool";
  default:
    return "unknown type";
  case 5:
    return "sampler1D";
  case 6:
    return "sampler2D";
  case 7:
    return "sampler3D";
  case 8:
    return "samplerCube";
  case 9:
    return "sampler1DShadow";
  case 10:
    return "sampler2DShadow";
  case 0xb:
    return "sampler2DRect";
  case 0xc:
    return "sampler2DRectShadow";
  case 0xe:
    return "structure";
  }
}

/* TIntermSymbol__getId @ 0x97c32384 (8 bytes) */
int TIntermSymbol__getId(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x30);
}

/* TIntermSymbol__getSymbol @ 0x97c3238c (8 bytes) */
int TIntermSymbol__getSymbol(this)
  unsigned char * this;
{
  return this + 0x34;
}

/* TIntermSymbol__getAsSymbolNode @ 0x97c32394 (4 bytes) */
int TIntermSymbol__getAsSymbolNode()
{
  return;
}

/* TIntermConstantUnion__getAsConstantUnion @ 0x97c32398 (4 bytes) */
int TIntermConstantUnion__getAsConstantUnion()
{
  return;
}

