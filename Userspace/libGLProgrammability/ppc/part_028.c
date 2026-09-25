#include "decls.h"

/* TIntermOperator__promote @ 0x97c3239c (8 bytes) */
int TIntermOperator__promote(param_1)
  unsigned char * param_1;
{
  return 1;
}

/* TIntermBinary__setLeft @ 0x97c323a4 (8 bytes) */
int TIntermBinary__setLeft(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  *(unsigned char **)(this + 0x34) = param_2;
  return;
}

/* TIntermBinary__setRight @ 0x97c323ac (8 bytes) */
int TIntermBinary__setRight(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  *(unsigned char **)(this + 0x38) = param_2;
  return;
}

/* TIntermBinary__getLeft @ 0x97c323b4 (8 bytes) */
int TIntermBinary__getLeft(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x34);
}

/* TIntermBinary__getRight @ 0x97c323bc (8 bytes) */
int TIntermBinary__getRight(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x38);
}

/* TIntermBinary__getAsBinaryNode @ 0x97c323c4 (4 bytes) */
int TIntermBinary__getAsBinaryNode()
{
  return;
}

/* TIntermUnary__setOperand @ 0x97c323c8 (8 bytes) */
int TIntermUnary__setOperand(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  *(unsigned char **)(this + 0x34) = param_2;
  return;
}

/* TIntermUnary__getOperand @ 0x97c323d0 (8 bytes) */
int TIntermUnary__getOperand(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x34);
}

/* __ZN16TIntermAggregateD1Ev @ 0x97c323d8 (176 bytes) */
int __ZN16TIntermAggregateD1Ev(this)
  void *this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  unsigned char * this_00;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_20 [5];
  
  this_00 = *(unsigned char
              **)((int)this + 0x68);
  *(undefined ***)this = &PTR_getLine_a7b7d1b8;
  if (this_00 !=
      (unsigned char
       *)0x0) {
    ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____clear)(this_00);
    __ZdlPv(this_00);
  }
  iVar4 = *(int *)((int)this + 0x58);
  local_20[0] = *(undefined4 *)((int)this + 0x54);
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
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(iVar4 + -0xc),local_20);
  }
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* __ZN16TIntermAggregateD0Ev @ 0x97c32488 (176 bytes) */
int __ZN16TIntermAggregateD0Ev(this)
  void *this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  unsigned char * this_00;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_20 [5];
  
  this_00 = *(unsigned char
              **)((int)this + 0x68);
  *(undefined ***)this = &PTR_getLine_a7b7d1b8;
  if (this_00 !=
      (unsigned char
       *)0x0) {
    ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____clear)(this_00);
    __ZdlPv(this_00);
  }
  iVar4 = *(int *)((int)this + 0x58);
  local_20[0] = *(undefined4 *)((int)this + 0x54);
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
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(iVar4 + -0xc),local_20);
  }
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* TIntermAggregate__getAsAggregate @ 0x97c32538 (4 bytes) */
int TIntermAggregate__getAsAggregate()
{
  return;
}

/* TIntermAggregate__setOperator @ 0x97c3253c (8 bytes) */
int TIntermAggregate__setOperator(this, param_2)
  unsigned char * this;
  undefined4 param_2;
{
  *(undefined4 *)(this + 0x30) = param_2;
  return;
}

/* TIntermAggregate__getSequence @ 0x97c32544 (8 bytes) */
int TIntermAggregate__getSequence(this)
  unsigned char * this;
{
  return this + 0x34;
}

/* TIntermAggregate__setName @ 0x97c3254c (8 bytes) */
int TIntermAggregate__setName(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_(param_1 + 0x54,param_2);
  return;
}

/* TIntermAggregate__getName @ 0x97c32554 (8 bytes) */
int TIntermAggregate__getName(this)
  unsigned char * this;
{
  return this + 0x54;
}

/* TIntermAggregate__setUserDefined @ 0x97c3255c (12 bytes) */
int TIntermAggregate__setUserDefined(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 0x5c) = 1;
  return;
}

/* TIntermAggregate__isUserDefined @ 0x97c32568 (8 bytes) */
int TIntermAggregate__isUserDefined(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x5c);
}

/* TIntermAggregate__getQualifier @ 0x97c32570 (8 bytes) */
int TIntermAggregate__getQualifier(this)
  unsigned char * this;
{
  return this + 0x44;
}

/* TIntermSelection__getCondition @ 0x97c32578 (8 bytes) */
int TIntermSelection__getCondition(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x30);
}

/* TIntermSelection__getTrueBlock @ 0x97c32580 (8 bytes) */
int TIntermSelection__getTrueBlock(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x34);
}

/* TIntermSelection__getFalseBlock @ 0x97c32588 (8 bytes) */
int TIntermSelection__getFalseBlock(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x38);
}

/* TIntermSelection__getAsSelectionNode @ 0x97c32590 (4 bytes) */
int TIntermSelection__getAsSelectionNode()
{
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____clear @ 0x97c32594 (96 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____clear( unsigned char
             *this)

{
  if (*(int *)(this + 8) != 0) {
    std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase(this,*(unsigned char **)(*(int *)(this + 4) + 4));
    *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
    *(undefined4 *)(*(int *)(this + 4) + 4) = 0;
    *(int *)(*(int *)(this + 4) + 0xc) = *(int *)(this + 4);
    *(undefined4 *)(this + 8) = 0;
  }
  return;
}

/* __ZN13TIntermBranchD1Ev @ 0x97c325f4 (36 bytes) */
int __ZN13TIntermBranchD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  return;
}

/* __ZN13TIntermBranchD0Ev @ 0x97c32618 (36 bytes) */
int __ZN13TIntermBranchD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  return;
}

/* __ZN11TIntermLoopD1Ev @ 0x97c3263c (36 bytes) */
int __ZN11TIntermLoopD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  return;
}

/* __ZN11TIntermLoopD0Ev @ 0x97c32660 (36 bytes) */
int __ZN11TIntermLoopD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  return;
}

/* __ZN16TIntermSelectionD1Ev @ 0x97c32684 (52 bytes) */
int __ZN16TIntermSelectionD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* __ZN16TIntermSelectionD0Ev @ 0x97c326b8 (52 bytes) */
int __ZN16TIntermSelectionD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* __ZN12TIntermUnaryD1Ev @ 0x97c326ec (52 bytes) */
int __ZN12TIntermUnaryD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* __ZN12TIntermUnaryD0Ev @ 0x97c32720 (52 bytes) */
int __ZN12TIntermUnaryD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* __ZN13TIntermBinaryD1Ev @ 0x97c32754 (52 bytes) */
int __ZN13TIntermBinaryD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* __ZN13TIntermBinaryD0Ev @ 0x97c32788 (52 bytes) */
int __ZN13TIntermBinaryD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* __ZN20TIntermConstantUnionD1Ev @ 0x97c327bc (52 bytes) */
int __ZN20TIntermConstantUnionD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* __ZN20TIntermConstantUnionD0Ev @ 0x97c327f0 (52 bytes) */
int __ZN20TIntermConstantUnionD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* __ZN13TIntermSymbolD1Ev @ 0x97c32824 (148 bytes) */
int __ZN13TIntermSymbolD1Ev(this)
  void *this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_20 [6];
  
  iVar4 = *(int *)((int)this + 0x38);
  local_20[0] = *(undefined4 *)((int)this + 0x34);
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
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(iVar4 + -0xc),local_20);
  }
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* __ZN13TIntermSymbolD0Ev @ 0x97c328b8 (148 bytes) */
int __ZN13TIntermSymbolD0Ev(this)
  void *this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_20 [6];
  
  iVar4 = *(int *)((int)this + 0x38);
  local_20[0] = *(undefined4 *)((int)this + 0x34);
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
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(iVar4 + -0xc),local_20);
  }
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find @ 0x97c3294c (276 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find(param_1, param_2, param_3)
  unsigned char * param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34 [2];
  
  iVar6 = *(int *)(param_2 + 4);
  iVar1 = iVar6;
  if (*(int *)(iVar6 + 4) != 0) {
    pvVar5 = *(void **)(param_3 + 4);
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
    uVar7 = *(uint *)((int)*(void **)(param_3 + 4) + -0xc);
    local_38 = uVar7;
    uVar8 = *(uint *)(*(int *)(iVar1 + 0x14) + -0xc);
    local_34[0] = uVar8;
    if (uVar7 <= uVar8) {
      puVar4 = &local_38;
    }
    iVar3 = _memcmp(*(void **)(param_3 + 4),*(void **)(iVar1 + 0x14),*puVar4);
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

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_mm @ 0x97c32a60 (4 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_mm(this, param_2, param_3, param_4)
  void *this;
  unsigned char * param_2;
  ulong param_3;
  ulong param_4;
{
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4ERKS3_mm)(this,param_2,param_3,param_4);
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4ERKS3_mm @ 0x97c32a64 (180 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4ERKS3_mm(this, param_2, param_3, param_4)
  void *this;
  unsigned char * param_2;
  ulong param_3;
  ulong param_4;
{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 local_40 [11];
  
  iVar2 = *(int *)(param_2 + 4);
  if (*(uint *)(iVar2 + -0xc) < param_3) {
    std____throw_out_of_range("basic_string::_M_check");
    iVar2 = *(int *)(param_2 + 4);
  }
  uVar1 = *(int *)(iVar2 + -0xc) - param_3;
  if (uVar1 <= param_4) {
    param_4 = uVar1;
  }
  local_40[0] = GetGlobalPoolAllocator();
  pcVar3 = ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE12_S_constructIN9__gnu_cxx17__normal_iteratorIPcS3_EEEES7_T_S9_RKS2_St20forward_iterator_tag)(iVar2 + param_3,iVar2 + param_3 + param_4,(unsigned char *)local_40,0);
  uVar4 = GetGlobalPoolAllocator();
  *(undefined4 *)this = uVar4;
  *(char **)((int)this + 4) = pcVar3;
  return;
}

/* __ZNKSbIcSt11char_traitsIcE14pool_allocatorIcEE7compareEPKc @ 0x97c32b18 (112 bytes) */
int __ZNKSbIcSt11char_traitsIcE14pool_allocatorIcEE7compareEPKc(this, param_2)
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
  
  pvVar4 = *(void **)((int)this + 4);
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

/* __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_EPKS4_RKS7_ @ 0x97c32b88 (340 bytes) */
int __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_EPKS4_RKS7_(param_1, param_2, param_3)
  char *param_1;
  unsigned char * param_2;
  unsigned char * param_3;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  size_t sVar5;
  undefined4 uVar6;
  unsigned char * psVar7;
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
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7reserveEm)(param_1,sVar5 + *(int *)(*(int *)(param_3 + 4) + -0xc));
  uVar4 = *(uint *)(*(int *)(param_1 + 4) + -0xc);
  if (0x3ffffffc - sVar5 < uVar4) {
    std____throw_length_error("basic_string::replace");
  }
  psVar7 = *(unsigned char **)(param_1 + 4);
  if (((*(int *)(psVar7 + -4) < 1) && (psVar7 <= param_2)) && (param_2 <= psVar7 + uVar4)) {
    ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE10_M_replaceIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_St18input_iterator_tag)(param_1,psVar7 + uVar4,(char *)(psVar7 + uVar4),(char *)param_2,param_2 + sVar5);
  }
  else {
    ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_)(param_1,psVar7 + uVar4,psVar7 + uVar4,(char *)param_2,(char *)(param_2 + sVar5));
  }
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendERKS3_)(param_1,param_3);
  return param_1;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound @ 0x97c32cdc (176 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound(param_1, param_2, param_3)
  unsigned char * param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  uint *puVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_40;
  uint local_3c [6];
  
  iVar4 = *(int *)(param_2 + 4);
  if (*(int *)(iVar4 + 4) != 0) {
    pvVar3 = *(void **)(param_3 + 4);
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

/* __ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueESt17_Rb_tree_iteratorIS8_RS8_PS8_ERKS8_ @ 0x97c32d8c (568 bytes) */
int __ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueESt17_Rb_tree_iteratorIS8_RS8_PS8_ERKS8_(param_1, param_2, param_3, param_4)
  unsigned char * param_1;
  unsigned char * param_2;
  int *param_3;
  int param_4;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  void *pvVar4;
  unsigned char * ppVar5;
  uint uVar6;
  unsigned char * ppVar7;
  unsigned char * local_70 [4];
  unsigned char * local_60 [4];
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34 [4];
  
  ppVar5 = *(unsigned char **)(param_2 + 4);
  ppVar7 = (unsigned char *)*param_3;
  if (ppVar7 == *(unsigned char **)(ppVar5 + 8)) {
    if (*(int *)(param_2 + 8) != 0) {
      puVar2 = &local_4c;
      uVar3 = *(uint *)(*(int *)(param_4 + 4) + -0xc);
      local_50 = uVar3;
      uVar6 = *(uint *)(*(int *)(ppVar7 + 0x14) + -0xc);
      local_4c = uVar6;
      if (uVar3 <= uVar6) {
        puVar2 = &local_50;
      }
      iVar1 = _memcmp(*(void **)(param_4 + 4),*(void **)(ppVar7 + 0x14),*puVar2);
      if (iVar1 == 0) {
        iVar1 = uVar3 - uVar6;
      }
      ppVar5 = ppVar7;
      if (iVar1 < 0) goto LAB_97c32f8c;
    }
  }
  else {
    if (ppVar7 != ppVar5) {
      local_70[0] = ppVar7;
      std___Rb_tree_base_iterator___M_decrement((unsigned char *)local_70);
      ppVar5 = local_70;
      pvVar4 = *(void **)(param_4 + 4);
      puVar2 = &local_3c;
      uVar3 = *(uint *)(*(int *)(local_70[0] + 0x14) + -0xc);
      local_40 = uVar3;
      uVar6 = *(uint *)((int)pvVar4 + -0xc);
      local_3c = uVar6;
      if (uVar3 <= uVar6) {
        puVar2 = &local_40;
      }
      iVar1 = _memcmp(*(void **)(local_70[0] + 0x14),pvVar4,*puVar2);
      if (iVar1 == 0) {
        iVar1 = uVar3 - uVar6;
      }
      if (iVar1 < 0) {
        uVar6 = *(uint *)((int)pvVar4 + -0xc);
        puVar2 = local_34;
        local_38 = uVar6;
        uVar3 = *(uint *)(*(int *)(*param_3 + 0x14) + -0xc);
        local_34[0] = uVar3;
        if (uVar6 <= uVar3) {
          puVar2 = &local_38;
        }
        iVar1 = _memcmp(pvVar4,*(void **)(*param_3 + 0x14),*puVar2);
        if (iVar1 == 0) {
          iVar1 = uVar6 - uVar3;
        }
        if (iVar1 < 0) {
          if (*(int *)(ppVar5 + 0xc) != 0) {
            ppVar7 = (unsigned char *)*param_3;
            ppVar5 = ppVar7;
            goto LAB_97c32f8c;
          }
          goto LAB_97c32f68;
        }
      }
      ((int (*)())__ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueERKS8_)((unsigned char *)local_60,param_2,param_4);
      local_70[0] = local_60[0];
      goto LAB_97c32fa8;
    }
    puVar2 = &local_44;
    uVar3 = *(uint *)(*(int *)(*(int *)(ppVar7 + 0xc) + 0x14) + -0xc);
    local_48 = uVar3;
    uVar6 = *(uint *)((int)*(void **)(param_4 + 4) + -0xc);
    local_44 = uVar6;
    if (uVar3 <= uVar6) {
      puVar2 = &local_48;
    }
    iVar1 = _memcmp(*(void **)(*(int *)(ppVar7 + 0xc) + 0x14),*(void **)(param_4 + 4),*puVar2);
    if (iVar1 == 0) {
      iVar1 = uVar3 - uVar6;
    }
    if (iVar1 < 0) {
      ppVar5 = *(unsigned char **)(ppVar5 + 0xc);
LAB_97c32f68:
      ppVar7 = (unsigned char *)0x0;
LAB_97c32f8c:
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_insert)(param_1,param_2,ppVar7,ppVar5,param_4);
      return param_1;
    }
  }
  ((int (*)())__ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueERKS8_)((unsigned char *)local_70,param_2,param_4);
LAB_97c32fa8:
  *(unsigned char **)param_1 = local_70[0];
  return param_1;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm @ 0x97c32fc4 (112 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm(this, param_2, param_3)
  void *this;
  char *param_2;
  ulong param_3;
{
  ulong uVar1;
  int iVar2;
  
  iVar2 = *(int *)((int)this + 4);
  uVar1 = param_3 + *(int *)(iVar2 + -0xc);
  if (*(uint *)(iVar2 + -8) < uVar1) {
    ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7reserveEm)(this,uVar1);
    iVar2 = *(int *)((int)this + 4);
  }
  iVar2 = iVar2 + *(int *)(iVar2 + -0xc);
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_)(this,iVar2,iVar2,param_2,param_2 + param_3);
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendERKS3_ @ 0x97c33034 (116 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendERKS3_(this, param_2)
  void *this;
  unsigned char * param_2;
{
  ulong uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)((int)this + 4);
  iVar2 = *(int *)(param_2 + 4);
  uVar1 = *(int *)(iVar2 + -0xc) + *(int *)(iVar3 + -0xc);
  if (*(uint *)(iVar3 + -8) < uVar1) {
    ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7reserveEm)(this,uVar1);
    iVar2 = *(int *)(param_2 + 4);
    iVar3 = *(int *)((int)this + 4);
  }
  iVar3 = iVar3 + *(int *)(iVar3 + -0xc);
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcS3_EEEERS3_S8_S8_T_SA_)(this,iVar3,iVar3,iVar2,iVar2 + *(int *)(iVar2 + -0xc));
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE12_S_constructIN9__gnu_cxx17__normal_iteratorIPcS3_EEEES7_T_S9_RKS2_St20forward_iterator_tag @ 0x97c330a8 (176 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE12_S_constructIN9__gnu_cxx17__normal_iteratorIPcS3_EEEES7_T_S9_RKS2_St20forward_iterator_tag(param_1, param_2, param_3)
  void *param_1;
  void *param_2;
  unsigned char * param_3;
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
  puVar4 = (ulong *)__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep9_S_createEmRKS2_
                              (uVar5,param_3);
  puVar6 = puVar4 + 3;
  _memcpy(puVar6,param_1,uVar5);
  *puVar4 = uVar5;
  *(char *)((int)puVar6 + uVar5) = '\0';
  return (char *)puVar6;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7reserveEm @ 0x97c33158 (216 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7reserveEm(this, param_2)
  void *this;
  ulong param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_20 [4];
  
  iVar4 = *(int *)((int)this + 4);
  if ((*(uint *)(iVar4 + -8) < param_2) || (0 < *(int *)(iVar4 + -4))) {
    if (0x3ffffffc < param_2) {
      std____throw_length_error("basic_string::reserve");
      iVar4 = *(int *)((int)this + 4);
    }
    if (param_2 < *(uint *)(iVar4 + -0xc)) {
      param_2 = *(uint *)(iVar4 + -0xc);
    }
    local_20[0] = *(undefined4 *)this;
    uVar5 = __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep8_M_cloneERKS2_m
                      ((void *)(iVar4 + -0xc),(unsigned char *)local_20,param_2 - *(int *)(iVar4 + -0xc)
                      );
    iVar4 = *(int *)((int)this + 4);
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
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(iVar4 + -0xc),(unsigned char *)local_20);
    }
    *(undefined4 *)((int)this + 4) = uVar5;
  }
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_ @ 0x97c33230 (152 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
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
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE9_M_mutateEmmm)(this,param_2 - iVar1,param_3 - param_2,uVar2);
  if (uVar2 != 0) {
    _memcpy((void *)(*(int *)(this + 4) + (param_2 - iVar1)),param_4,uVar2);
  }
  return this;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE10_M_replaceIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_St18input_iterator_tag @ 0x97c332c8 (172 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE10_M_replaceIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_St18input_iterator_tag(param_1, param_2, param_3, param_4, param_5)
  void *param_1;
  undefined4 param_2;
  char *param_3;
  char *param_4;
  char *param_5;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  unsigned char * psVar4;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_50;
  int local_4c;
  undefined4 local_40 [4];
  undefined4 local_30 [5];
  
  local_40[0] = GetGlobalPoolAllocator();
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1IPKcEET_S7_RKS2_)(&local_50,param_4,param_5,(unsigned char *)local_40);
  psVar4 = ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcS3_EEEERS3_S8_S8_T_SA_)(param_1,param_2,param_3,local_4c,local_4c + *(int *)(local_4c + -0xc));
  piVar2 = (int *)(local_4c + -4);
  local_30[0] = local_50;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_4c + -0xc),local_30);
  }
  return psVar4;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_insert @ 0x97c33374 (356 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_insert(param_1, param_2, param_3, param_4, param_5)
  unsigned char * param_1;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
  unsigned char * param_5;
{
  int iVar1;
  unsigned char * p_Var2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint local_30;
  uint local_2c [4];
  
  if ((param_4 == *(int *)(param_2 + 4)) || (param_3 != (unsigned char *)0x0)) {
LAB_97c333f0:
    p_Var2 = (unsigned char *)TPoolAllocator__allocate(*(unsigned char **)param_2,0x1c);
    if (p_Var2 + 0x10 != (unsigned char *)0x0) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(p_Var2 + 0x10,param_5);
      *(undefined4 *)(p_Var2 + 0x18) = *(undefined4 *)(param_5 + 8);
    }
    *(unsigned char **)(param_4 + 8) = p_Var2;
    iVar1 = *(int *)(param_2 + 4);
    if (param_4 != iVar1) {
      if (param_4 == *(int *)(iVar1 + 8)) {
        *(unsigned char **)(iVar1 + 8) = p_Var2;
      }
      goto LAB_97c33490;
    }
    *(unsigned char **)(param_4 + 4) = p_Var2;
    iVar1 = *(int *)(param_2 + 4);
  }
  else {
    puVar3 = local_2c;
    uVar5 = *(uint *)(*(int *)(param_5 + 4) + -0xc);
    local_30 = uVar5;
    uVar4 = *(uint *)((int)*(void **)(param_4 + 0x14) + -0xc);
    local_2c[0] = uVar4;
    if (uVar5 <= uVar4) {
      puVar3 = &local_30;
    }
    iVar1 = _memcmp(*(void **)(param_5 + 4),*(void **)(param_4 + 0x14),*puVar3);
    if (iVar1 == 0) {
      iVar1 = uVar5 - uVar4;
    }
    if (iVar1 < 0) goto LAB_97c333f0;
    p_Var2 = (unsigned char *)TPoolAllocator__allocate(*(unsigned char **)param_2,0x1c);
    if (p_Var2 + 0x10 != (unsigned char *)0x0) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(p_Var2 + 0x10,param_5);
      *(undefined4 *)(p_Var2 + 0x18) = *(undefined4 *)(param_5 + 8);
    }
    *(unsigned char **)(param_4 + 0xc) = p_Var2;
    iVar1 = *(int *)(param_2 + 4);
    if (param_4 != *(int *)(iVar1 + 0xc)) goto LAB_97c33490;
  }
  *(unsigned char **)(iVar1 + 0xc) = p_Var2;
LAB_97c33490:
  *(int *)(p_Var2 + 4) = param_4;
  *(undefined4 *)(p_Var2 + 0xc) = 0;
  *(undefined4 *)(p_Var2 + 8) = 0;
  std___Rb_tree_rebalance(p_Var2,(unsigned char **)(*(int *)(param_2 + 4) + 4));
  *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
  *(unsigned char **)param_1 = p_Var2;
  return param_1;
}

/* __ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueERKS8_ @ 0x97c334d8 (388 bytes) */
int __ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueERKS8_(param_1, param_2, param_3)
  unsigned char * param_1;
  unsigned char * param_2;
  int param_3;
{
  int iVar1;
  uint *puVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int local_70 [4];
  int local_60 [4];
  int local_50 [4];
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  
  iVar4 = *(int *)(param_2 + 4);
  iVar1 = 1;
  iVar5 = iVar4;
  if (*(int *)(iVar4 + 4) != 0) {
    pvVar3 = *(void **)(param_3 + 4);
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
  local_70[0] = iVar5;
  if (iVar1 != 0) {
    local_60[0] = *(int *)(iVar4 + 8);
    if (iVar5 == local_60[0]) {
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_insert)((unsigned char *)local_50,param_2,(unsigned char *)0x0,iVar5,param_3);
      goto LAB_97c3362c;
    }
    std___Rb_tree_base_iterator___M_decrement((unsigned char *)local_70);
  }
  iVar1 = local_70[0];
  puVar2 = &local_34;
  uVar7 = *(uint *)(*(int *)(local_70[0] + 0x14) + -0xc);
  local_38 = uVar7;
  uVar8 = *(uint *)((int)*(void **)(param_3 + 4) + -0xc);
  local_34 = uVar8;
  if (uVar7 <= uVar8) {
    puVar2 = &local_38;
  }
  iVar4 = _memcmp(*(void **)(local_70[0] + 0x14),*(void **)(param_3 + 4),*puVar2);
  if (iVar4 == 0) {
    iVar4 = uVar7 - uVar8;
  }
  if (-1 < iVar4) {
    *(int *)param_1 = iVar1;
    *(undefined4 *)(param_1 + 4) = 0;
    return param_1;
  }
  ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_insert)((unsigned char *)local_60,param_2,(unsigned char *)0x0,iVar5,param_3);
  local_50[0] = local_60[0];
LAB_97c3362c:
  *(int *)param_1 = local_50[0];
  *(undefined4 *)(param_1 + 4) = 1;
  return param_1;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcS3_EEEERS3_S8_S8_T_SA_ @ 0x97c3365c (152 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcS3_EEEERS3_S8_S8_T_SA_(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
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
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE9_M_mutateEmmm)(this,param_2 - iVar1,param_3 - param_2,uVar2);
  if (uVar2 != 0) {
    _memcpy((void *)(*(int *)(this + 4) + (param_2 - iVar1)),param_4,uVar2);
  }
  return this;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE9_M_mutateEmmm @ 0x97c336f4 (344 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE9_M_mutateEmmm(this, param_2, param_3, param_4)
  void *this;
  ulong param_2;
  ulong param_3;
  ulong param_4;
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
  
  pvVar4 = *(void **)((int)this + 4);
  pvVar7 = (void *)((int)pvVar4 + param_3 + param_2);
  sVar8 = (*(int *)((int)pvVar4 + -0xc) - param_2) - param_3;
  uVar9 = (*(int *)((int)pvVar4 + -0xc) + param_4) - param_3;
  if ((*(int *)((int)pvVar4 + -4) < 1) && (uVar9 <= *(uint *)((int)pvVar4 + -8))) {
    if ((sVar8 != 0) && (param_3 != param_4)) {
      _memmove((void *)((int)pvVar4 + param_4 + param_2),pvVar7,sVar8);
      pvVar4 = *(void **)((int)this + 4);
    }
  }
  else {
    local_40[0] = *(undefined4 *)this;
    uVar5 = uVar9;
    if ((*(uint *)((int)pvVar4 + -8) < uVar9) &&
       ((0xfe3 < uVar9 && (uVar5 = *(uint *)((int)pvVar4 + -8) << 1, uVar5 < uVar9)))) {
      uVar5 = uVar9;
    }
    iVar6 = __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep9_S_createEmRKS2_
                      (uVar5,(unsigned char *)local_40);
    pvVar4 = (void *)(iVar6 + 0xc);
    if (param_2 != 0) {
      _memcpy(pvVar4,*(void **)((int)this + 4),param_2);
    }
    if (sVar8 != 0) {
      _memcpy((void *)((int)pvVar4 + param_4 + param_2),pvVar7,sVar8);
    }
    iVar6 = *(int *)((int)this + 4);
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
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(iVar6 + -0xc),local_40);
    }
    *(void **)((int)this + 4) = pvVar4;
  }
  *(undefined4 *)((int)pvVar4 + -4) = 0;
  *(uint *)(*(int *)((int)this + 4) + -0xc) = uVar9;
  *(undefined1 *)(*(int *)((int)this + 4) + uVar9) = 0;
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1IPKcEET_S7_RKS2_ @ 0x97c3384c (4 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1IPKcEET_S7_RKS2_(this, param_2, param_3, param_4)
  void *this;
  char *param_2;
  char *param_3;
  unsigned char * param_4;
{
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4IPKcEET_S7_RKS2_)(this,param_2,param_3,param_4);
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4IPKcEET_S7_RKS2_ @ 0x97c33850 (76 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4IPKcEET_S7_RKS2_(this, param_2, param_3, param_4)
  void *this;
  char *param_2;
  char *param_3;
  unsigned char * param_4;
{
  undefined4 uVar1;
  char *pcVar2;
  
  pcVar2 = __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE12_S_constructIPKcEEPcT_S8_RKS2_St20forward_iterator_tag
                     (param_2,param_3,param_4,0);
  uVar1 = *(undefined4 *)param_4;
  *(char **)((int)this + 4) = pcVar2;
  *(undefined4 *)this = uVar1;
  return;
}

/* std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState_____M_insert_aux @ 0x97c3389c (640 bytes) */
int std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState_____M_insert_aux( unsigned char
                   *this,undefined4 *param_2,undefined4 *param_3)

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
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState______gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState____)(local_40,iVar8,param_2,puVar9);
    if (local_40[0] != (undefined4 *)0x0) {
      uVar4 = *param_3;
      local_40[0][1] = param_3[1];
      *local_40[0] = uVar4;
    }
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState______gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState____)(local_40,param_2,*(undefined4 *)(this + 4),local_40[0] + 2);
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
int std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState______gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState____(param_1, param_2, param_3, param_4)
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

/* std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase @ 0x97c33b78 (128 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase( unsigned char
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
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase)(this,*(unsigned char **)(param_2 + 0xc));
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

/* std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux @ 0x97c33bf8 (516 bytes) */
int std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux(this, param_2, param_3)
  unsigned char * this;
  undefined4 *param_2;
  undefined4 *param_3;
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

