#include "decls.h"

/* std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_insert @ 0x97c30ec8 (356 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_insert(this, _Rb_tree_node_base1, _Rb_tree_node_base2, pair, text)
  unsigned char * this;
  unsigned char * _Rb_tree_node_base1;
  unsigned char * _Rb_tree_node_base2;
  int pair;
  unsigned char * text;
{
  int iVar1;
  unsigned char * p_Var2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint local_30;
  uint local_2c [4];
  
  if ((pair == *(int *)(_Rb_tree_node_base1 + 4)) || (_Rb_tree_node_base2 != (unsigned char *)0x0)) {
LAB_97c30f44:
    p_Var2 = (unsigned char *)TPoolAllocator__allocate(*(unsigned char **)_Rb_tree_node_base1,0x1c);
    if (p_Var2 + 0x10 != (unsigned char *)0x0) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(p_Var2 + 0x10,text);
      *(undefined4 *)(p_Var2 + 0x18) = *(undefined4 *)(text + 8);
    }
    *(unsigned char **)(pair + 8) = p_Var2;
    iVar1 = *(int *)(_Rb_tree_node_base1 + 4);
    if (pair != iVar1) {
      if (pair == *(int *)(iVar1 + 8)) {
        *(unsigned char **)(iVar1 + 8) = p_Var2;
      }
      goto LAB_97c30fe4;
    }
    *(unsigned char **)(pair + 4) = p_Var2;
    iVar1 = *(int *)(_Rb_tree_node_base1 + 4);
  }
  else {
    puVar3 = local_2c;
    uVar5 = *(uint *)(*(int *)(text + 4) + -0xc);
    local_30 = uVar5;
    uVar4 = *(uint *)((int)*(void **)(pair + 0x14) + -0xc);
    local_2c[0] = uVar4;
    if (uVar5 <= uVar4) {
      puVar3 = &local_30;
    }
    iVar1 = _memcmp(*(void **)(text + 4),*(void **)(pair + 0x14),*puVar3);
    if (iVar1 == 0) {
      iVar1 = uVar5 - uVar4;
    }
    if (iVar1 < 0) goto LAB_97c30f44;
    p_Var2 = (unsigned char *)TPoolAllocator__allocate(*(unsigned char **)_Rb_tree_node_base1,0x1c);
    if (p_Var2 + 0x10 != (unsigned char *)0x0) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(p_Var2 + 0x10,text);
      *(undefined4 *)(p_Var2 + 0x18) = *(undefined4 *)(text + 8);
    }
    *(unsigned char **)(pair + 0xc) = p_Var2;
    iVar1 = *(int *)(_Rb_tree_node_base1 + 4);
    if (pair != *(int *)(iVar1 + 0xc)) goto LAB_97c30fe4;
  }
  *(unsigned char **)(iVar1 + 0xc) = p_Var2;
LAB_97c30fe4:
  *(int *)(p_Var2 + 4) = pair;
  *(undefined4 *)(p_Var2 + 0xc) = 0;
  *(undefined4 *)(p_Var2 + 8) = 0;
  ((int (*)())std___Rb_tree_rebalance)(p_Var2,(unsigned char **)(*(int *)(_Rb_tree_node_base1 + 4) + 4));
  *(int *)(_Rb_tree_node_base1 + 8) = *(int *)(_Rb_tree_node_base1 + 8) + 1;
  *(unsigned char **)this = p_Var2;
  return this;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep9_S_createEmRKS2_ @ 0x97c3102c (172 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep9_S_createEmRKS2_(this, param_2)
  ulong this;
  unsigned char * param_2;
{
  uint uVar1;
  undefined4 *allocation;
  ulong uVar3;
  
  if (0x3ffffffc < this) {
    std____throw_length_error("basic_string::_S_create");
  }
  uVar1 = this + 0x1d;
  uVar3 = this + 0xd;
  if (uVar1 < 0x1001) {
    if (uVar3 < 0x81) goto LAB_97c310a4;
    uVar1 = 0x80 - (uVar1 & 0x7f) & 0x7f;
  }
  else {
    uVar1 = 0x1000 - (uVar1 & 0xfff) & 0xfff;
  }
  this = this + uVar1;
  uVar3 = this + 0xd;
LAB_97c310a4:
  allocation = (undefined4 *)TPoolAllocator__allocate(*(unsigned char **)param_2,uVar3);
  *allocation = 0;
  allocation[1] = this;
  allocation[2] = 0;
  return allocation;
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
int std___Rb_tree_rebalance(_Rb_tree_node_base1, _Rb_tree_node_base2)
  unsigned char * _Rb_tree_node_base1;
  unsigned char ** _Rb_tree_node_base2;
{
  int iVar1;
  unsigned char * p_Var2;
  unsigned char * p_Var3;
  unsigned char * p_Var4;
  
  *(undefined4 *)_Rb_tree_node_base1 = 0;
  p_Var2 = *_Rb_tree_node_base2;
  if (_Rb_tree_node_base1 != p_Var2) {
    p_Var3 = *(unsigned char **)(_Rb_tree_node_base1 + 4);
    iVar1 = *(int *)p_Var3;
    while (iVar1 == 0) {
      p_Var4 = *(unsigned char **)(p_Var3 + 4);
      p_Var2 = *(unsigned char **)(p_Var4 + 8);
      if (p_Var3 == p_Var2) {
        p_Var2 = *(unsigned char **)(p_Var4 + 0xc);
        if ((p_Var2 == (unsigned char *)0x0) || (*(int *)p_Var2 != 0)) {
          p_Var4 = _Rb_tree_node_base1;
          p_Var2 = p_Var3;
          if (_Rb_tree_node_base1 == *(unsigned char **)(p_Var3 + 0xc)) {
            ((int (*)())std___Rb_tree_rotate_left)(p_Var3,_Rb_tree_node_base2);
            p_Var2 = *(unsigned char **)(p_Var3 + 4);
            p_Var4 = p_Var3;
          }
          p_Var3 = *(unsigned char **)(p_Var2 + 4);
          *(undefined4 *)p_Var2 = 1;
          *(undefined4 *)p_Var3 = 0;
          ((int (*)())std___Rb_tree_rotate_right)(p_Var3,_Rb_tree_node_base2);
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
        p_Var4 = _Rb_tree_node_base1;
        p_Var2 = p_Var3;
        if (_Rb_tree_node_base1 == *(unsigned char **)(p_Var3 + 8)) {
          ((int (*)())std___Rb_tree_rotate_right)(p_Var3,_Rb_tree_node_base2);
          p_Var2 = *(unsigned char **)(p_Var3 + 4);
          p_Var4 = p_Var3;
        }
        p_Var3 = *(unsigned char **)(p_Var2 + 4);
        *(undefined4 *)p_Var2 = 1;
        *(undefined4 *)p_Var3 = 0;
        ((int (*)())std___Rb_tree_rotate_left)(p_Var3,_Rb_tree_node_base2);
      }
      p_Var2 = *_Rb_tree_node_base2;
      if (p_Var4 == p_Var2) break;
      p_Var3 = *(unsigned char **)(p_Var4 + 4);
      _Rb_tree_node_base1 = p_Var4;
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

/* __ZN5TTypeD1Ev @ 0x97c312b8 (36 bytes) */
int __ZN5TTypeD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZN5TTypeD1Ev_a7b7cf48;
  return;
}

/* __ZN5TTypeD0Ev @ 0x97c312dc (36 bytes) */
int __ZN5TTypeD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZN5TTypeD1Ev_a7b7cf48;
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

/* __ZN5TType7setTypeE10TBasicTypeibbi @ 0x97c31368 (32 bytes) */
int __ZN5TType7setTypeE10TBasicTypeibbi(this, basicType, nominalSize, matrixFlag, arrayFlag, arraySizeArg)
  void *this;
  uint basicType;
  uint nominalSize;
  uint matrixFlag;
  uint arrayFlag;
  undefined4 arraySizeArg;
{
  *(undefined4 *)((int)this + 4) = arraySizeArg;
  *(uint *)((int)this + 0x24) =
       (arrayFlag & 1) << 9 |
       (matrixFlag & 1) << 10 |
       (nominalSize & 0xff) << 0xb | (basicType & 0x3f) << 0x13 | *(uint *)((int)this + 0x24) & 0xfe0001ff
  ;
  return;
}

/* __ZN5TType7setTypeE10TBasicTypeibPS_ @ 0x97c31388 (40 bytes) */
int __ZN5TType7setTypeE10TBasicTypeibPS_(this, basicType, param_3, param_4, type)
  void *this;
  uint basicType;
  uint param_3;
  uint param_4;
  int type;
{
  *(uint *)((int)this + 0x24) =
       (param_4 & 1) << 10 |
       (param_3 & 0xff) << 0xb | (basicType & 0x3f) << 0x13 | *(uint *)((int)this + 0x24) & 0xfe0003ff
  ;
  if (type == 0) {
    return;
  }
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(type + 8);
  return;
}

/* TType__setTypeName @ 0x97c313b0 (132 bytes) */
int TType__setTypeName(this, name)
  unsigned char * this;
  unsigned char * name;
{
  void *typeName;
  unsigned char * globalAllocator;
  void *stringMem;
  char *chars;
  undefined4 poolAllocArg [4];
  
  *(undefined1 *)(*(int *)(name + 4) + *(int *)(*(int *)(name + 4) + -0xc)) = *DAT_a7b7b718;
  chars = *(char **)(name + 4);
  globalAllocator = (unsigned char *)GetGlobalPoolAllocator();
  stringMem = (void *)TPoolAllocator__allocate(globalAllocator,8);
  typeName = (void *)0x0;
  if (stringMem != (void *)0x0) {
    poolAllocArg[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(stringMem,chars,(unsigned char *)poolAllocArg);
    typeName = stringMem;
  }
  *(void **)(this + 0x10) = typeName;
  return;
}

/* TType__setFieldName @ 0x97c31434 (132 bytes) */
int TType__setFieldName(this, text)
  unsigned char * this;
  unsigned char * text;
{
  void *pvVar1;
  unsigned char * this_00;
  void *this_01;
  char *pcVar2;
  undefined4 local_20 [4];
  
  *(undefined1 *)(*(int *)(text + 4) + *(int *)(*(int *)(text + 4) + -0xc)) = *DAT_a7b7b718;
  pcVar2 = *(char **)(text + 4);
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  this_01 = (void *)TPoolAllocator__allocate(this_00,8);
  pvVar1 = (void *)0x0;
  if (this_01 != (void *)0x0) {
    local_20[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(this_01,pcVar2,(unsigned char *)local_20);
    pvVar1 = this_01;
  }
  *(void **)(this + 0xc) = pvVar1;
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
int TType__changeQualifier(this, qualifier)
  unsigned char * this;
  int qualifier;
{
  *(uint *)(this + 0x24) = qualifier << 0x19 | *(uint *)(this + 0x24) & 0x1ffffff;
  return;
}

/* TType__getNominalSize @ 0x97c314e8 (16 bytes) */
int TType__getNominalSize(this)
  unsigned char * this;
{
  return (int)(*(uint *)(this + 0x24) << 0xd | *(uint *)(this + 0x24) >> 0x13) >> 0x18;
}

/* std___Rb_tree_rotate_left @ 0x97c314f8 (92 bytes) */
int std___Rb_tree_rotate_left(_Rb_tree_node_base1, _Rb_tree_node_base2)
  unsigned char * _Rb_tree_node_base1;
  unsigned char ** _Rb_tree_node_base2;
{
  int iVar1;
  unsigned char * p_Var2;
  
  p_Var2 = *(unsigned char **)(_Rb_tree_node_base1 + 0xc);
  iVar1 = *(int *)(p_Var2 + 8);
  *(int *)(_Rb_tree_node_base1 + 0xc) = iVar1;
  if (iVar1 != 0) {
    *(unsigned char **)(iVar1 + 4) = _Rb_tree_node_base1;
  }
  *(undefined4 *)(p_Var2 + 4) = *(undefined4 *)(_Rb_tree_node_base1 + 4);
  if (_Rb_tree_node_base1 == *_Rb_tree_node_base2) {
    *_Rb_tree_node_base2 = p_Var2;
  }
  else {
    iVar1 = *(int *)(_Rb_tree_node_base1 + 4);
    if (_Rb_tree_node_base1 == *(unsigned char **)(iVar1 + 8)) {
      *(unsigned char **)(iVar1 + 8) = p_Var2;
    }
    else {
      *(unsigned char **)(iVar1 + 0xc) = p_Var2;
    }
  }
  *(unsigned char **)(_Rb_tree_node_base1 + 4) = p_Var2;
  *(unsigned char **)(p_Var2 + 8) = _Rb_tree_node_base1;
  return;
}

/* std___Rb_tree_rotate_right @ 0x97c31554 (92 bytes) */
int std___Rb_tree_rotate_right(_Rb_tree_node_base1, _Rb_tree_node_base2)
  unsigned char * _Rb_tree_node_base1;
  unsigned char ** _Rb_tree_node_base2;
{
  int iVar1;
  unsigned char * p_Var2;
  
  p_Var2 = *(unsigned char **)(_Rb_tree_node_base1 + 8);
  iVar1 = *(int *)(p_Var2 + 0xc);
  *(int *)(_Rb_tree_node_base1 + 8) = iVar1;
  if (iVar1 != 0) {
    *(unsigned char **)(iVar1 + 4) = _Rb_tree_node_base1;
  }
  *(undefined4 *)(p_Var2 + 4) = *(undefined4 *)(_Rb_tree_node_base1 + 4);
  if (_Rb_tree_node_base1 == *_Rb_tree_node_base2) {
    *_Rb_tree_node_base2 = p_Var2;
  }
  else {
    iVar1 = *(int *)(_Rb_tree_node_base1 + 4);
    if (_Rb_tree_node_base1 == *(unsigned char **)(iVar1 + 0xc)) {
      *(unsigned char **)(iVar1 + 0xc) = p_Var2;
    }
    else {
      *(unsigned char **)(iVar1 + 8) = p_Var2;
    }
  }
  *(unsigned char **)(_Rb_tree_node_base1 + 4) = p_Var2;
  *(unsigned char **)(p_Var2 + 0xc) = _Rb_tree_node_base1;
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_ @ 0x97c315b0 (200 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_(this, text)
  void *this;
  unsigned char * text;
{
  int *refCountPtr;
  int atomicStore;
  int atomicStore2;
  int *piVar2;
  int oldRefCount;
  int iVar4;
  int iVar5;
  char reservation;
  byte cr0Reg;
  int local_30 [4];
  int local_20;
  
  iVar4 = *(int *)(text + 4);
  if ((void *)(*(int *)((int)this + 4) + -0xc) != (void *)(iVar4 + -0xc)) {
    local_20 = *(int *)text;
    local_30[0] = *(int *)this;
    if ((*(int *)(iVar4 + -4) < 0) || (local_30[0] != local_20)) {
      iVar4 = __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep8_M_cloneERKS2_m
                        ((void *)(iVar4 + -0xc),(unsigned char *)local_30,0);
    }
    else {
      piVar2 = (int *)(iVar4 + -4);
      do {
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
          *piVar2 = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
    }
    iVar5 = *(int *)((int)this + 4);
    refCountPtr = (int *)(iVar5 + -4);
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore2 = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore2;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(iVar5 + -0xc),(unsigned char *)local_30);
    }
    *(int *)((int)this + 4) = iVar4;
  }
  return this;
}

/* std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux @ 0x97c31678 (252 bytes) */
int std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux(this, position, x)
  unsigned char * this;
  undefined4 *position;
  undefined4 *x;
{
  int finishAfterCopy;
  int oldFinish;
  uint tailBytes;
  int oldSize;
  undefined4 *finish;
  int newLen;
  void *newStart;
  void *newFinish;
  undefined4 xCopy;
  size_t prefixBytes;
  
  finish = *(undefined4 **)(this + 8);
  if (finish == *(undefined4 **)(this + 0xc)) {
    newLen = 1;
    oldSize = (int)finish - *(int *)(this + 4) >> 2;
    if (oldSize != 0) {
      newLen = oldSize << 1;
    }
    newStart = (void *)TPoolAllocator__allocate(*(unsigned char **)this,newLen * 4);
    prefixBytes = (int)position - (int)*(void **)(this + 4);
    _memmove(newStart,*(void **)(this + 4),prefixBytes);
    if ((int)newStart + prefixBytes != 0) {
      *(undefined4 *)((int)newStart + prefixBytes) = *x;
    }
    oldFinish = *(int *)(this + 8);
    newFinish = (void *)((int)newStart + prefixBytes + 4);
    _memmove(newFinish,position,oldFinish - (int)position);
    *(void **)(this + 0xc) = (void *)((int)newStart + newLen * 4);
    *(int *)(this + 8) = (int)newFinish + (oldFinish - (int)position);
    *(void **)(this + 4) = newStart;
  }
  else {
    finishAfterCopy = 0;
    if (finish != (undefined4 *)0x0) {
      *finish = finish[-1];
      finishAfterCopy = *(int *)(this + 8);
    }
    *(int *)(this + 8) = finishAfterCopy + 4;
    tailBytes = (finishAfterCopy + -4) - (int)position & 0xfffffffc;
    xCopy = *x;
    _memmove((void *)(finishAfterCopy - tailBytes),position,tailBytes);
    *position = xCopy;
  }
  return;
}

/* std__vector_TIntermNode__pool_allocator_TIntermNode_____erase @ 0x97c31774 (96 bytes) */
int std__vector_TIntermNode__pool_allocator_TIntermNode_____erase(retIter, vec, position)
  undefined4 *retIter;
  int vec;
  void *position;
{
  void *next;
  void *finish;
  
  finish = *(void **)(vec + 8);
  next = (void *)((int)position + 4);
  if (next != finish) {
    _memmove(position,next,(int)finish - (int)next);
    finish = *(void **)(vec + 8);
  }
  *(int *)(vec + 8) = (int)finish + -4;
  *retIter = position;
  return retIter;
}

/* std__vector_TIntermNode__pool_allocator_TIntermNode_____insert @ 0x97c317d4 (152 bytes) */
int std__vector_TIntermNode__pool_allocator_TIntermNode_____insert(retIter, vec, position, x)
  int *retIter;
  unsigned char * vec;
  undefined4 *position;
  undefined4 *x;
{
  int offsetBytes;
  undefined4 *finish;
  int start;
  
  finish = *(undefined4 **)(vec + 8);
  start = *(int *)(vec + 4);
  offsetBytes = (int)position - start;
  if ((finish == *(undefined4 **)(vec + 0xc)) || (position != finish)) {
    ((int (*)())std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux)(vec,position,x);
    start = *(int *)(vec + 4);
  }
  else {
    if (position != (undefined4 *)0x0) {
      *position = *x;
      start = *(int *)(vec + 4);
      finish = *(undefined4 **)(vec + 8);
    }
    *(undefined4 **)(vec + 8) = finish + 1;
  }
  *retIter = start + (offsetBytes >> 2) * 4;
  return retIter;
}

/* std__vector_TIntermNode__pool_allocator_TIntermNode______M_range_insert___gnu_cxx____normal_iterator_TIntermNode___std__vector_TIntermNode__pool_allocator_TIntermNode_____ @ 0x97c3186c (424 bytes) */
int std__vector_TIntermNode__pool_allocator_TIntermNode______M_range_insert___gnu_cxx____normal_iterator_TIntermNode___std__vector_TIntermNode__pool_allocator_TIntermNode_____(vec, position, first, last)
  undefined4 *vec;
  void *position;
  void *first;
  void *last;
{
  void *splitPoint;
  uint moveBytes;
  void *newFinish;
  void *tailSrc;
  void *newStart;
  ulong newBytes;
  undefined4 *result;
  void *newInsertPoint;
  size_t prefixBytes;
  size_t rangeBytes;
  uint elemsAfter;
  void *oldFinish;
  uint *minRef;
  void *newTailDst;
  int finishAtCopy;
  uint oldSize;
  uint n [5];
  
  result = vec;
  if (first != last) {
    rangeBytes = (int)last - (int)first;
    oldFinish = (void *)vec[2];
    n[0] = (int)rangeBytes >> 2;
    if ((uint)(vec[3] - (int)oldFinish >> 2) < n[0]) {
      minRef = n;
      oldSize = (int)oldFinish - vec[1] >> 2;
      if (n[0] <= oldSize) {
        minRef = &oldSize;
      }
      newBytes = (oldSize + *minRef) * 4;
      newStart = (void *)TPoolAllocator__allocate((unsigned char *)*vec,newBytes);
      prefixBytes = (int)position - (int)vec[1];
      newInsertPoint = (void *)((int)newStart + prefixBytes);
      _memmove(newStart,(void *)vec[1],prefixBytes);
      newTailDst = (void *)((int)newInsertPoint + rangeBytes);
      _memmove(newInsertPoint,first,rangeBytes);
      finishAtCopy = vec[2];
      result = _memmove(newTailDst,position,finishAtCopy - (int)position);
      vec[3] = (void *)((int)newStart + newBytes);
      vec[2] = (int)newTailDst + (finishAtCopy - (int)position);
      vec[1] = newStart;
    }
    else {
      elemsAfter = (int)oldFinish - (int)position >> 2;
      if (n[0] < elemsAfter) {
        tailSrc = (void *)((int)oldFinish + n[0] * -4);
        _memmove(oldFinish,tailSrc,(int)oldFinish - (int)tailSrc);
        vec[2] = vec[2] + n[0] * 4;
        moveBytes = (int)oldFinish + (n[0] * -4 - (int)position) & 0xfffffffc;
        _memmove((void *)((int)oldFinish - moveBytes),position,moveBytes);
      }
      else {
        splitPoint = (void *)((int)first + elemsAfter * 4);
        _memmove(oldFinish,splitPoint,(int)last - (int)splitPoint);
        newFinish = (void *)(vec[2] + (n[0] - elemsAfter) * 4);
        vec[2] = newFinish;
        _memmove(newFinish,position,(int)oldFinish - (int)position);
        rangeBytes = (int)splitPoint - (int)first;
        vec[2] = vec[2] + elemsAfter * 4;
      }
      result = _memmove(position,first,rangeBytes);
    }
  }
  return result;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____operator_ @ 0x97c31a14 (280 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____operator_( unsigned char
              *this, unsigned char *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 _Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copyResult;
  
  if (this != (unsigned char
               *)param_2) {
    if (*(int *)(this + 8) != 0) {
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase)(this,*(unsigned char **)(*(int *)(this + 4) + 4));
      *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
      *(undefined4 *)(*(int *)(this + 4) + 4) = 0;
      *(int *)(*(int *)(this + 4) + 0xc) = *(int *)(this + 4);
      *(undefined4 *)(this + 8) = 0;
    }
    *(undefined4 *)(this + 8) = 0;
    if (*(unsigned char **)(*(int *)(param_2 + 4) + 4) == (unsigned char *)0x0) {
      *(undefined4 *)(*(int *)(this + 4) + 4) = 0;
      *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
      *(int *)(*(int *)(this + 4) + 0xc) = *(int *)(this + 4);
    }
    else {
      _Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copyResult = ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy)(this,*(unsigned char **)(*(int *)(param_2 + 4) + 4),
                        *(unsigned char **)(this + 4));
      *(undefined4 *)(*(int *)(this + 4) + 4) = _Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copyResult;
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
      *(undefined4 *)(this + 8) = *(undefined4 *)(param_2 + 8);
    }
  }
  return this;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy @ 0x97c31b2c (280 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy( unsigned char
          *this, unsigned char *param_2, unsigned char *param_3)

{
  undefined4 _Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copyResult;
  undefined4 uVar1;
  unsigned char * p_Var2;
  unsigned char * p_Var3;
  unsigned char * p_Var4;
  unsigned char * p_Var5;
  undefined4 *puVar6;
  
  p_Var2 = (unsigned char *)TPoolAllocator__allocate(*(unsigned char **)this,0x20);
  if (p_Var2 + 0x10 != (unsigned char *)0x0) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(p_Var2 + 0x10,(unsigned char *)(param_2 + 0x10))
    ;
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(p_Var2 + 0x18,(unsigned char *)(param_2 + 0x18))
    ;
  }
  uVar1 = *(undefined4 *)param_2;
  *(undefined4 *)(p_Var2 + 0xc) = 0;
  p_Var4 = *(unsigned char **)(param_2 + 0xc);
  *(undefined4 *)p_Var2 = uVar1;
  *(unsigned char **)(p_Var2 + 4) = param_3;
  *(undefined4 *)(p_Var2 + 8) = 0;
  if (p_Var4 != (unsigned char *)0x0) {
    _Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copyResult = ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy)(this,p_Var4,p_Var2);
    *(undefined4 *)(p_Var2 + 0xc) = _Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copyResult;
  }
  p_Var4 = p_Var2;
  for (puVar6 = *(undefined4 **)(param_2 + 8); puVar6 != (undefined4 *)0x0;
      puVar6 = (undefined4 *)puVar6[2]) {
    p_Var3 = (unsigned char *)TPoolAllocator__allocate(*(unsigned char **)this,0x20);
    if (p_Var3 + 0x10 != (unsigned char *)0x0) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(p_Var3 + 0x10,(unsigned char *)(puVar6 + 4));
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(p_Var3 + 0x18,(unsigned char *)(puVar6 + 6));
    }
    *(undefined4 *)(p_Var3 + 0xc) = 0;
    p_Var5 = (unsigned char *)puVar6[3];
    uVar1 = *puVar6;
    *(undefined4 *)(p_Var3 + 8) = 0;
    *(undefined4 *)p_Var3 = uVar1;
    *(unsigned char **)(p_Var3 + 4) = p_Var4;
    *(unsigned char **)(p_Var4 + 8) = p_Var3;
    if (p_Var5 != (unsigned char *)0x0) {
      _Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copyResult = ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy)(this,p_Var5,p_Var3);
      *(undefined4 *)(p_Var3 + 0xc) = _Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copyResult;
    }
    p_Var4 = p_Var3;
  }
  return p_Var2;
}

/* TType__setStructSize @ 0x97c31c44 (284 bytes) */
int TType__setStructSize(this, fields)
  unsigned char * this;
  unsigned char * fields;
{
  int memberSize;
  int *memberType;
  int totalSize;
  int *entry;
  
  totalSize = 0;
  entry = *(int **)(fields + 4);
  do {
    if (entry == *(int **)(fields + 8)) {
      *(int *)(this + 0x18) = totalSize;
      return totalSize;
    }
    memberSize = (**(code **)(*(int *)*entry + 0x38))((int *)*entry);
    if (memberSize == 0) {
      memberSize = (**(code **)(*(int *)*entry + 0x34))((int *)*entry);
      if ((memberSize != 0) ||
         (memberSize = (**(code **)(*(int *)*entry + 0x3c))((int *)*entry), memberSize != 0)) {
        memberSize = (**(code **)(*(int *)*entry + 0x30))((int *)*entry);
        goto LAB_97c31d28;
      }
      if (*(unsigned char **)(*entry + 8) != (unsigned char *)0x0) {
        memberSize = ((int (*)())TType__setStructSize)(this,*(unsigned char **)(*entry + 8));
        goto LAB_97c31d28;
      }
      totalSize = totalSize + 1;
    }
    else {
      memberType = (int *)*entry;
      if ((unsigned char *)memberType[2] == (unsigned char *)0x0) {
        memberSize = (**(code **)(*memberType + 0x30))(memberType);
      }
      else {
        memberSize = ((int (*)())TType__setStructSize)(this,(unsigned char *)memberType[2]);
      }
      memberSize = memberSize * *(int *)(*entry + 4);
LAB_97c31d28:
      totalSize = totalSize + memberSize;
    }
    entry = entry + 2;
  } while( true );
}

/* TIntermNode__getLine @ 0x97c31d60 (8 bytes) */
int TIntermNode__getLine(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 4);
}

/* TIntermNode__setLine @ 0x97c31d68 (8 bytes) */
int TIntermNode__setLine(this, param_2)
  unsigned char * this;
  int param_2;
{
  *(int *)(this + 4) = param_2;
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
int TIntermTyped__setType(this, srcType)
  unsigned char * this;
  unsigned char * srcType;
{
  uint nominalSizeBits;
  uint qualifierBits;
  uint basicTypeBits;
  uint matrixBit;
  uint oldBits;
  undefined4 structure;
  undefined4 word20;
  undefined4 word1c;
  undefined4 structureSize;
  undefined4 fieldName;
  undefined4 word14;
  undefined4 typeName;
  
  structure = *(undefined4 *)(srcType + 8);
  fieldName = *(undefined4 *)(srcType + 0xc);
  typeName = *(undefined4 *)(srcType + 0x10);
  word14 = *(undefined4 *)(srcType + 0x14);
  structureSize = *(undefined4 *)(srcType + 0x18);
  word1c = *(undefined4 *)(srcType + 0x1c);
  word20 = *(undefined4 *)(srcType + 0x20);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(srcType + 4);
  *(undefined4 *)(this + 0x10) = structure;
  *(undefined4 *)(this + 0x14) = fieldName;
  *(undefined4 *)(this + 0x18) = typeName;
  *(undefined4 *)(this + 0x1c) = word14;
  *(undefined4 *)(this + 0x20) = structureSize;
  *(undefined4 *)(this + 0x24) = word1c;
  *(undefined4 *)(this + 0x28) = word20;
  oldBits = *(uint *)(this + 0x2c);
  qualifierBits = *(uint *)(srcType + 0x24) & 0xfe000000;
  *(uint *)(this + 0x2c) = qualifierBits | oldBits & 0x1ffffff;
  basicTypeBits = (*(uint *)(srcType + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(this + 0x2c) = basicTypeBits | qualifierBits | oldBits & 0x7ffff;
  nominalSizeBits = *(uint *)(srcType + 0x24) & 0x7f800;
  *(uint *)(this + 0x2c) = nominalSizeBits | basicTypeBits | qualifierBits | oldBits & 0x7ff;
  matrixBit = (*(uint *)(srcType + 0x24) >> 10 & 1) << 10;
  *(uint *)(this + 0x2c) = matrixBit | nominalSizeBits | basicTypeBits | qualifierBits | oldBits & 0x3ff;
  *(uint *)(this + 0x2c) =
       (*(uint *)(srcType + 0x24) >> 9 & 1) << 9 | matrixBit | nominalSizeBits | basicTypeBits | qualifierBits | oldBits & 0x1ff;
  return;
}

/* TIntermTyped__getType @ 0x97c31e34 (192 bytes) */
int TIntermTyped__getType(retType, node)
  undefined4 *retType;
  int node;
{
  uint nominalSizeBits;
  uint qualifierBits;
  uint basicTypeBits;
  uint matrixBit;
  uint oldBits;
  undefined4 word1c;
  undefined4 structureSize;
  undefined4 word14;
  undefined4 typeName;
  undefined4 fieldName;
  undefined4 structure;
  undefined4 word20;
  
  word20 = *(undefined4 *)(node + 0x28);
  structure = *(undefined4 *)(node + 0x10);
  fieldName = *(undefined4 *)(node + 0x14);
  typeName = *(undefined4 *)(node + 0x18);
  word14 = *(undefined4 *)(node + 0x1c);
  structureSize = *(undefined4 *)(node + 0x20);
  word1c = *(undefined4 *)(node + 0x24);
  retType[1] = *(undefined4 *)(node + 0xc);
  retType[2] = structure;
  retType[3] = fieldName;
  retType[4] = typeName;
  retType[5] = word14;
  retType[6] = structureSize;
  retType[7] = word1c;
  retType[8] = word20;
  *retType = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  oldBits = retType[9];
  qualifierBits = *(uint *)(node + 0x2c) & 0xfe000000;
  retType[9] = qualifierBits | oldBits & 0x1ffffff;
  basicTypeBits = (*(uint *)(node + 0x2c) >> 0x13 & 0x3f) << 0x13;
  retType[9] = basicTypeBits | qualifierBits | oldBits & 0x7ffff;
  nominalSizeBits = *(uint *)(node + 0x2c) & 0x7f800;
  retType[9] = nominalSizeBits | basicTypeBits | qualifierBits | oldBits & 0x7ff;
  matrixBit = (*(uint *)(node + 0x2c) >> 10 & 1) << 10;
  retType[9] = matrixBit | nominalSizeBits | basicTypeBits | qualifierBits | oldBits & 0x3ff;
  retType[9] = (*(uint *)(node + 0x2c) >> 9 & 1) << 9 |
               matrixBit | nominalSizeBits | basicTypeBits | qualifierBits | oldBits & 0x1ff;
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

/* __ZN12TIntermTypedD1Ev @ 0x97c31f8c (52 bytes) */
int __ZN12TIntermTypedD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d040;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  return;
}

/* __ZN12TIntermTypedD0Ev @ 0x97c31fc0 (52 bytes) */
int __ZN12TIntermTypedD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d040;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase @ 0x97c31ff4 (192 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase( unsigned char
                *this, unsigned char *param_2)

{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int iVar4;
  unsigned char * p_Var5;
  char reservation;
  byte cr0Flags;
  undefined4 local_40 [4];
  undefined4 local_30 [5];
  
  cr0Flags = (param_2 == (unsigned char *)0x0) << 1;
  if (param_2 != (unsigned char *)0x0) {
    do {
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase)(this,*(unsigned char **)(param_2 + 0xc));
      local_40[0] = *(undefined4 *)(param_2 + 0x18);
      iVar4 = *(int *)(param_2 + 0x1c);
      refCountPtr = (int *)(iVar4 + -4);
      p_Var5 = *(unsigned char **)(param_2 + 8);
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      if (oldRefCount < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(iVar4 + -0xc),local_40);
      }
      iVar4 = *(int *)(param_2 + 0x14);
      local_30[0] = *(undefined4 *)(param_2 + 0x10);
      refCountPtr = (int *)(iVar4 + -4);
      do {
        oldRefCount = *refCountPtr;
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
          *refCountPtr = atomicStore;
          cr0Flags = 2;
        }
      } while (!(bool)(cr0Flags >> 1 & 1));
      if (oldRefCount < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(iVar4 + -0xc),local_30);
      }
      param_2 = p_Var5;
    } while (p_Var5 != (unsigned char *)0x0);
  }
  return;
}

/* TIntermNode__getAsTyped @ 0x97c320b4 (8 bytes) */
int TIntermNode__getAsTyped()
{
  return 0;
}

/* __ZN11TIntermNodeD1Ev @ 0x97c320bc (36 bytes) */
int __ZN11TIntermNodeD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d040;
  return;
}

/* __ZN11TIntermNodeD0Ev @ 0x97c320e0 (36 bytes) */
int __ZN11TIntermNodeD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR_getLine_a7b7d040;
  return;
}

/* getQualifierString @ 0x97c32104 (280 bytes) */
int getQualifierString(qualifier)
  undefined4 qualifier;
{
  switch(qualifier) {
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
int TType__getBasicString(this)
  undefined4 this;
{
  switch(this) {
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

