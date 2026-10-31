#include "decls.h"

/* TIntermOperator__promote @ 0x97c3239c (8 bytes) */
int TIntermOperator__promote(this)
  unsigned char * this;
{
  return 1;
}

/* TIntermBinary__setLeft @ 0x97c323a4 (8 bytes) */
int TIntermBinary__setLeft(this, intermTyped)
  unsigned char * this;
  unsigned char * intermTyped;
{
  *(unsigned char **)(this + 0x34) = intermTyped;
  return;
}

/* TIntermBinary__setRight @ 0x97c323ac (8 bytes) */
int TIntermBinary__setRight(this, intermTyped)
  unsigned char * this;
  unsigned char * intermTyped;
{
  *(unsigned char **)(this + 0x38) = intermTyped;
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
int TIntermUnary__setOperand(this, intermTyped)
  unsigned char * this;
  unsigned char * intermTyped;
{
  *(unsigned char **)(this + 0x34) = intermTyped;
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
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int nameData;
  unsigned char * symbolTable;
  char reservation;
  byte cr0Reg;
  undefined4 allocatorCopy [5];
  
  symbolTable = *(unsigned char
              **)((int)this + 0x68);
  *(undefined ***)this = &PTR_getLine_a7b7d1b8;
  if (symbolTable !=
      (unsigned char
       *)0x0) {
    ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____clear)(symbolTable);
    __ZdlPv(symbolTable);
  }
  nameData = *(int *)((int)this + 0x58);
  allocatorCopy[0] = *(undefined4 *)((int)this + 0x54);
  refCountPtr = (int *)(nameData + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(nameData + -0xc),allocatorCopy);
  }
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* __ZN16TIntermAggregateD0Ev @ 0x97c32488 (176 bytes) */
int __ZN16TIntermAggregateD0Ev(this)
  void *this;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int nameData;
  unsigned char * symbolTable;
  char reservation;
  byte cr0Reg;
  undefined4 allocatorCopy [5];
  
  symbolTable = *(unsigned char
              **)((int)this + 0x68);
  *(undefined ***)this = &PTR_getLine_a7b7d1b8;
  if (symbolTable !=
      (unsigned char
       *)0x0) {
    ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string_____clear)(symbolTable);
    __ZdlPv(symbolTable);
  }
  nameData = *(int *)((int)this + 0x58);
  allocatorCopy[0] = *(undefined4 *)((int)this + 0x54);
  refCountPtr = (int *)(nameData + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(nameData + -0xc),allocatorCopy);
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
int TIntermAggregate__setOperator(this, op)
  unsigned char * this;
  undefined4 op;
{
  *(undefined4 *)(this + 0x30) = op;
  return;
}

/* TIntermAggregate__getSequence @ 0x97c32544 (8 bytes) */
int TIntermAggregate__getSequence(this)
  unsigned char * this;
{
  return this + 0x34;
}

/* TIntermAggregate__setName @ 0x97c3254c (8 bytes) */
int TIntermAggregate__setName(this, text)
  unsigned char * this;
  unsigned char * text;
{
  return __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_(this + 0x54,text);
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
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int nameData;
  char reservation;
  byte cr0Reg;
  undefined4 allocatorCopy [6];
  
  nameData = *(int *)((int)this + 0x38);
  allocatorCopy[0] = *(undefined4 *)((int)this + 0x34);
  *(undefined ***)this = &PTR_getLine_a7b7d390;
  refCountPtr = (int *)(nameData + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(nameData + -0xc),allocatorCopy);
  }
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* __ZN13TIntermSymbolD0Ev @ 0x97c328b8 (148 bytes) */
int __ZN13TIntermSymbolD0Ev(this)
  void *this;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int nameData;
  char reservation;
  byte cr0Reg;
  undefined4 allocatorCopy [6];
  
  nameData = *(int *)((int)this + 0x38);
  allocatorCopy[0] = *(undefined4 *)((int)this + 0x34);
  *(undefined ***)this = &PTR_getLine_a7b7d390;
  refCountPtr = (int *)(nameData + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(nameData + -0xc),allocatorCopy);
  }
  *(undefined ***)this = &PTR_getLine_a7b7d400;
  *(undefined ***)((int)this + 8) = &PTR___ZN5TTypeD1Ev_a7b7d440;
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find @ 0x97c3294c (276 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find(result, tree, key)
  unsigned char * result;
  int tree;
  int key;
{
  uint candidateKeySize;
  uint finalKeySize;
  int nextNode;
  int finalCompareResult;
  int candidate;
  int compareResult;
  int node;
  uint *minSizeRef;
  void *keyChars;
  int header;
  uint nodeKeySize;
  uint keySize;
  uint minArgNodeSize;
  uint minArgKeySize;
  uint minArgFinalKeySize;
  uint minArgFinalNodeSize [2];
  
  header = *(int *)(tree + 4);
  candidate = header;
  if (*(int *)(header + 4) != 0) {
    keyChars = *(void **)(key + 4);
    node = *(int *)(header + 4);
    do {
      nodeKeySize = *(uint *)(*(int *)(node + 0x14) + -0xc);
      minArgNodeSize = nodeKeySize;
      keySize = *(uint *)((int)keyChars + -0xc);
      minArgKeySize = keySize;
      minSizeRef = &minArgKeySize;
      if (nodeKeySize <= keySize) {
        minSizeRef = &minArgNodeSize;
      }
      compareResult = _memcmp(*(void **)(node + 0x14),keyChars,*minSizeRef);
      if (compareResult == 0) {
        compareResult = nodeKeySize - keySize;
      }
      if (compareResult < 0) {
        nextNode = *(int *)(node + 0xc);
      }
      else {
        nextNode = *(int *)(node + 8);
        candidate = node;
      }
      node = nextNode;
    } while (nextNode != 0);
  }
  if (candidate != header) {
    minSizeRef = minArgFinalNodeSize;
    finalKeySize = *(uint *)((int)*(void **)(key + 4) + -0xc);
    minArgFinalKeySize = finalKeySize;
    candidateKeySize = *(uint *)(*(int *)(candidate + 0x14) + -0xc);
    minArgFinalNodeSize[0] = candidateKeySize;
    if (finalKeySize <= candidateKeySize) {
      minSizeRef = &minArgFinalKeySize;
    }
    finalCompareResult = _memcmp(*(void **)(key + 4),*(void **)(candidate + 0x14),*minSizeRef);
    if (finalCompareResult == 0) {
      finalCompareResult = finalKeySize - candidateKeySize;
    }
    if (-1 < finalCompareResult) goto storeResult;
  }
  candidate = header;
storeResult:
  *(int *)result = candidate;
  return result;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_mm @ 0x97c32a60 (4 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_mm(this, text, pos, n)
  void *this;
  unsigned char * text;
  ulong pos;
  ulong n;
{
  return ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4ERKS3_mm)(this,text,pos,n);
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4ERKS3_mm @ 0x97c32a64 (180 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4ERKS3_mm(this, str, pos, n)
  void *this;
  unsigned char * str;
  ulong pos;
  ulong n;
{
  uint remaining;
  int strData;
  char *data;
  undefined4 poolAllocator;
  undefined4 allocatorArg [11];
  
  strData = *(int *)(str + 4);
  if (*(uint *)(strData + -0xc) < pos) {
    std____throw_out_of_range("basic_string::_M_check");
    strData = *(int *)(str + 4);
  }
  remaining = *(int *)(strData + -0xc) - pos;
  if (remaining <= n) {
    n = remaining;
  }
  allocatorArg[0] = GetGlobalPoolAllocator();
  data = ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE12_S_constructIN9__gnu_cxx17__normal_iteratorIPcS3_EEEES7_T_S9_RKS2_St20forward_iterator_tag)(strData + pos,strData + pos + n,(unsigned char *)allocatorArg,0);
  poolAllocator = GetGlobalPoolAllocator();
  *(undefined4 *)this = poolAllocator;
  *(char **)((int)this + 4) = data;
  return;
}

/* __ZNKSbIcSt11char_traitsIcE14pool_allocatorIcEE7compareEPKc @ 0x97c32b18 (112 bytes) */
int __ZNKSbIcSt11char_traitsIcE14pool_allocatorIcEE7compareEPKc(this, str)
  void *this;
  char *str;
{
  size_t length;
  int cmpResult;
  size_t *minSizeRef;
  void *data;
  uint thisSize;
  uint minArgSize;
  size_t minArgLength [6];
  
  data = *(void **)((int)this + 4);
  thisSize = *(uint *)((int)data + -0xc);
  minArgSize = thisSize;
  length = _strlen(str);
  minSizeRef = minArgLength;
  minArgLength[0] = length;
  if (thisSize <= length) {
    minSizeRef = &minArgSize;
  }
  cmpResult = _memcmp(data,str,*minSizeRef);
  if (cmpResult == 0) {
    cmpResult = thisSize - length;
  }
  return cmpResult;
}

/* __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_EPKS4_RKS7_ @ 0x97c32b88 (340 bytes) */
int __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_EPKS4_RKS7_(this, str, text)
  char *this;
  unsigned char * str;
  unsigned char * text;
{
  int atomicStore;
  int emptyRepStorage;
  int *emptyRepRefcount;
  uint newSize;
  size_t length;
  undefined4 poolAllocator;
  unsigned char *data;
  char reservation;
  byte cr0Reg;
  
  length = _strlen((char *)str);
  emptyRepStorage = emptyStringRepPtr_a7b7ba14;
  emptyRepRefcount = (int *)(emptyStringRepPtr_a7b7ba14 + 8);
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefcount + 1,0,emptyRepRefcount);
      *emptyRepRefcount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  poolAllocator = GetGlobalPoolAllocator();
  *(undefined4 *)this = poolAllocator;
  *(int *)(this + 4) = emptyRepStorage + 0xc;
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7reserveEm)(this,length + *(int *)(*(int *)(text + 4) + -0xc));
  newSize = *(uint *)(*(int *)(this + 4) + -0xc);
  if (0x3ffffffc - length < newSize) {
    std____throw_length_error("basic_string::replace");
  }
  data = *(unsigned char **)(this + 4);
  if (((*(int *)(data + -4) < 1) && (data <= str)) && (str <= data + newSize)) {
    ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE10_M_replaceIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_St18input_iterator_tag)(this,data + newSize,(char *)(data + newSize),(char *)str,str + length);
  }
  else {
    ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_)(this,data + newSize,data + newSize,(char *)str,(char *)(str + length));
  }
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendERKS3_)(this,text);
  return this;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound @ 0x97c32cdc (176 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____lower_bound(result, tree, key)
  unsigned char * result;
  int tree;
  int key;
{
  int nextNode;
  int compareResult;
  uint *minSizeRef;
  void *keyChars;
  int lowerBound;
  int node;
  uint nodeKeySize;
  uint keySize;
  uint minArgNodeSize;
  uint minArgKeySize [6];
  
  lowerBound = *(int *)(tree + 4);
  if (*(int *)(lowerBound + 4) != 0) {
    keyChars = *(void **)(key + 4);
    node = *(int *)(lowerBound + 4);
    do {
      nodeKeySize = *(uint *)(*(int *)(node + 0x14) + -0xc);
      minArgNodeSize = nodeKeySize;
      keySize = *(uint *)((int)keyChars + -0xc);
      minArgKeySize[0] = keySize;
      minSizeRef = minArgKeySize;
      if (nodeKeySize <= keySize) {
        minSizeRef = &minArgNodeSize;
      }
      compareResult = _memcmp(*(void **)(node + 0x14),keyChars,*minSizeRef);
      if (compareResult == 0) {
        compareResult = nodeKeySize - keySize;
      }
      if (compareResult < 0) {
        nextNode = *(int *)(node + 0xc);
      }
      else {
        nextNode = *(int *)(node + 8);
        lowerBound = node;
      }
      node = nextNode;
    } while (nextNode != 0);
  }
  *(int *)result = lowerBound;
  return result;
}

/* __ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueESt17_Rb_tree_iteratorIS8_RS8_PS8_ERKS8_ @ 0x97c32d8c (568 bytes) */
int __ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueESt17_Rb_tree_iteratorIS8_RS8_PS8_ERKS8_(result, tree, position, value)
  unsigned char * result;
  unsigned char * tree;
  int *position;
  int value;
{
  int compareResult;
  uint *minSizeRef;
  uint sizeA;
  void *valueKeyChars;
  unsigned char * insertY;
  uint sizeB;
  unsigned char * insertX;
  unsigned char * iterSlot [4];
  unsigned char * nestedResult [4];
  uint minArgBeginA;
  uint minArgBeginB;
  uint minArgEndA;
  uint minArgEndB;
  uint minArgBeforeA;
  uint minArgBeforeB;
  uint minArgHintA;
  uint minArgHintB [4];
  
  insertY = *(unsigned char **)(tree + 4);
  insertX = (unsigned char *)*position;
  if (insertX == *(unsigned char **)(insertY + 8)) {
    if (*(int *)(tree + 8) != 0) {
      minSizeRef = &minArgBeginB;
      sizeA = *(uint *)(*(int *)(value + 4) + -0xc);
      minArgBeginA = sizeA;
      sizeB = *(uint *)(*(int *)(insertX + 0x14) + -0xc);
      minArgBeginB = sizeB;
      if (sizeA <= sizeB) {
        minSizeRef = &minArgBeginA;
      }
      compareResult = _memcmp(*(void **)(value + 4),*(void **)(insertX + 0x14),*minSizeRef);
      if (compareResult == 0) {
        compareResult = sizeA - sizeB;
      }
      insertY = insertX;
      if (compareResult < 0) goto callStd__Rb_tree_std_string_std_pair_std_string_const_TBehavior_std__Select1st_std_pair_std_string_const_TBehavior__std_less_std_string_pool_allocator_std_pair_std_string_const_TBehavior___M_insert;
    }
  }
  else {
    if (insertX != insertY) {
      iterSlot[0] = insertX;
      std___Rb_tree_base_iterator___M_decrement((unsigned char *)iterSlot);
      insertY = iterSlot[0];
      valueKeyChars = *(void **)(value + 4);
      minSizeRef = &minArgBeforeB;
      sizeA = *(uint *)(*(int *)(iterSlot[0] + 0x14) + -0xc);
      minArgBeforeA = sizeA;
      sizeB = *(uint *)((int)valueKeyChars + -0xc);
      minArgBeforeB = sizeB;
      if (sizeA <= sizeB) {
        minSizeRef = &minArgBeforeA;
      }
      compareResult = _memcmp(*(void **)(iterSlot[0] + 0x14),valueKeyChars,*minSizeRef);
      if (compareResult == 0) {
        compareResult = sizeA - sizeB;
      }
      if (compareResult < 0) {
        sizeB = *(uint *)((int)valueKeyChars + -0xc);
        minSizeRef = minArgHintB;
        minArgHintA = sizeB;
        sizeA = *(uint *)(*(int *)(*position + 0x14) + -0xc);
        minArgHintB[0] = sizeA;
        if (sizeB <= sizeA) {
          minSizeRef = &minArgHintA;
        }
        compareResult = _memcmp(valueKeyChars,*(void **)(*position + 0x14),*minSizeRef);
        if (compareResult == 0) {
          compareResult = sizeB - sizeA;
        }
        if (compareResult < 0) {
          if (*(int *)(insertY + 0xc) != 0) {
            insertX = (unsigned char *)*position;
            insertY = insertX;
            goto callStd__Rb_tree_std_string_std_pair_std_string_const_TBehavior_std__Select1st_std_pair_std_string_const_TBehavior__std_less_std_string_pool_allocator_std_pair_std_string_const_TBehavior___M_insert;
          }
          goto setInsertX;
        }
      }
      ((int (*)())__ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueERKS8_)((unsigned char *)nestedResult,tree,value);
      iterSlot[0] = nestedResult[0];
      goto storeResult;
    }
    minSizeRef = &minArgEndB;
    sizeA = *(uint *)(*(int *)(*(int *)(insertX + 0xc) + 0x14) + -0xc);
    minArgEndA = sizeA;
    sizeB = *(uint *)((int)*(void **)(value + 4) + -0xc);
    minArgEndB = sizeB;
    if (sizeA <= sizeB) {
      minSizeRef = &minArgEndA;
    }
    compareResult = _memcmp(*(void **)(*(int *)(insertX + 0xc) + 0x14),*(void **)(value + 4),*minSizeRef);
    if (compareResult == 0) {
      compareResult = sizeA - sizeB;
    }
    if (compareResult < 0) {
      insertY = *(unsigned char **)(insertY + 0xc);
setInsertX:
      insertX = (unsigned char *)0x0;
callStd__Rb_tree_std_string_std_pair_std_string_const_TBehavior_std__Select1st_std_pair_std_string_const_TBehavior__std_less_std_string_pool_allocator_std_pair_std_string_const_TBehavior___M_insert:
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_insert)(result,tree,insertX,insertY,value);
      return result;
    }
  }
  ((int (*)())__ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueERKS8_)((unsigned char *)iterSlot,tree,value);
storeResult:
  *(unsigned char **)result = iterSlot[0];
  return result;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm @ 0x97c32fc4 (112 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm(this, str, n)
  void *this;
  char *str;
  ulong n;
{
  ulong newSize;
  int data;
  
  data = *(int *)((int)this + 4);
  newSize = n + *(int *)(data + -0xc);
  if (*(uint *)(data + -8) < newSize) {
    ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7reserveEm)(this,newSize);
    data = *(int *)((int)this + 4);
  }
  data = data + *(int *)(data + -0xc);
  return ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_)(this,data,data,str,str + n);
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendERKS3_ @ 0x97c33034 (116 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendERKS3_(this, str)
  void *this;
  unsigned char * str;
{
  ulong newSize;
  int strData;
  int data;
  
  data = *(int *)((int)this + 4);
  strData = *(int *)(str + 4);
  newSize = *(int *)(strData + -0xc) + *(int *)(data + -0xc);
  if (*(uint *)(data + -8) < newSize) {
    ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7reserveEm)(this,newSize);
    strData = *(int *)(str + 4);
    data = *(int *)((int)this + 4);
  }
  data = data + *(int *)(data + -0xc);
  return ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcS3_EEEERS3_S8_S8_T_SA_)(this,data,data,strData,strData + *(int *)(strData + -0xc));
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE12_S_constructIN9__gnu_cxx17__normal_iteratorIPcS3_EEEES7_T_S9_RKS2_St20forward_iterator_tag @ 0x97c330a8 (176 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE12_S_constructIN9__gnu_cxx17__normal_iteratorIPcS3_EEEES7_T_S9_RKS2_St20forward_iterator_tag(first, last, alloc)
  void *first;
  void *last;
  unsigned char * alloc;
{
  int atomicStore;
  int emptyRepStorage;
  int *emptyRepRefcount;
  int poolAllocator;
  ulong *rep;
  ulong length;
  ulong *repData;
  char reservation;
  byte cr0Reg;
  
  if ((first == last) &&
     (poolAllocator = GetGlobalPoolAllocator(), emptyRepStorage = emptyStringRepPtr_a7b7ba14, *(int *)alloc == poolAllocator)) {
    emptyRepRefcount = (int *)(emptyStringRepPtr_a7b7ba14 + 8);
    do {
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(*emptyRepRefcount + 1,0,emptyRepRefcount);
        *emptyRepRefcount = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    return (char *)(emptyRepStorage + 0xc);
  }
  length = (int)last - (int)first;
  rep = (ulong *)__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep9_S_createEmRKS2_
                              (length,alloc);
  repData = rep + 3;
  _memcpy(repData,first,length);
  *rep = length;
  *(char *)((int)repData + length) = '\0';
  return (char *)repData;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7reserveEm @ 0x97c33158 (216 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7reserveEm(this, res)
  void *this;
  ulong res;
{
  int oldData;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int data;
  undefined4 clonedData;
  char reservation;
  byte cr0Reg;
  undefined4 allocatorCopy [4];
  
  data = *(int *)((int)this + 4);
  if ((*(uint *)(data + -8) < res) || (0 < *(int *)(data + -4))) {
    if (0x3ffffffc < res) {
      std____throw_length_error("basic_string::reserve");
      data = *(int *)((int)this + 4);
    }
    if (res < *(uint *)(data + -0xc)) {
      res = *(uint *)(data + -0xc);
    }
    allocatorCopy[0] = *(undefined4 *)this;
    clonedData = __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep8_M_cloneERKS2_m
                      ((void *)(data + -0xc),(unsigned char *)allocatorCopy,res - *(int *)(data + -0xc)
                      );
    oldData = *(int *)((int)this + 4);
    refCountPtr = (int *)(oldData + -4);
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(oldData + -0xc),(unsigned char *)allocatorCopy);
    }
    *(undefined4 *)((int)this + 4) = clonedData;
  }
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_ @ 0x97c33230 (152 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_(this, i1, i2, first, last)
  unsigned char * this;
  int i1;
  int i2;
  void *first;
  int last;
{
  int data;
  uint length;
  
  length = last - (int)first;
  if (0x3ffffffb < length) {
    std____throw_length_error("basic_string::_M_replace");
  }
  data = *(int *)(this + 4);
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE9_M_mutateEmmm)(this,i1 - data,i2 - i1,length);
  if (length != 0) {
    _memcpy((void *)(*(int *)(this + 4) + (i1 - data)),first,length);
  }
  return this;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE10_M_replaceIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_St18input_iterator_tag @ 0x97c332c8 (172 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE10_M_replaceIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_St18input_iterator_tag(this, i1, i2, first, last)
  void *this;
  undefined4 i1;
  char *i2;
  char *first;
  char *last;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  unsigned char *result;
  char reservation;
  byte cr0Reg;
  undefined4 tempAllocator;
  int tempData;
  undefined4 allocatorArg [4];
  undefined4 allocatorCopy [5];
  
  allocatorArg[0] = GetGlobalPoolAllocator();
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1IPKcEET_S7_RKS2_)(&tempAllocator,first,last,(unsigned char *)allocatorArg);
  result = ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcS3_EEEERS3_S8_S8_T_SA_)(this,i1,i2,tempData,tempData + *(int *)(tempData + -0xc));
  refCountPtr = (int *)(tempData + -4);
  allocatorCopy[0] = tempAllocator;
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(tempData + -0xc),allocatorCopy);
  }
  return result;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_insert @ 0x97c33374 (356 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_insert(result, tree, x, y, value)
  unsigned char * result;
  unsigned char * tree;
  unsigned char * x;
  int y;
  unsigned char * value;
{
  int compareResult;
  int header;
  unsigned char * newNode;
  uint *minSizeRef;
  uint yKeySize;
  uint valueKeySize;
  uint minArgValueSize;
  uint minArgYSize [4];
  
  if ((y == *(int *)(tree + 4)) || (x != (unsigned char *)0x0)) {
loopSetNewNode:
    newNode = (unsigned char *)TPoolAllocator__allocate(*(unsigned char **)tree,0x1c);
    if (newNode + 0x10 != (unsigned char *)0x0) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(newNode + 0x10,value);
      *(undefined4 *)(newNode + 0x18) = *(undefined4 *)(value + 8);
    }
    *(unsigned char **)(y + 8) = newNode;
    header = *(int *)(tree + 4);
    if (y != header) {
      if (y == *(int *)(header + 8)) {
        *(unsigned char **)(header + 8) = newNode;
      }
      goto storeNewNode;
    }
    *(unsigned char **)(y + 4) = newNode;
    header = *(int *)(tree + 4);
  }
  else {
    minSizeRef = minArgYSize;
    valueKeySize = *(uint *)(*(int *)(value + 4) + -0xc);
    minArgValueSize = valueKeySize;
    yKeySize = *(uint *)((int)*(void **)(y + 0x14) + -0xc);
    minArgYSize[0] = yKeySize;
    if (valueKeySize <= yKeySize) {
      minSizeRef = &minArgValueSize;
    }
    compareResult = _memcmp(*(void **)(value + 4),*(void **)(y + 0x14),*minSizeRef);
    if (compareResult == 0) {
      compareResult = valueKeySize - yKeySize;
    }
    if (compareResult < 0) goto loopSetNewNode;
    newNode = (unsigned char *)TPoolAllocator__allocate(*(unsigned char **)tree,0x1c);
    if (newNode + 0x10 != (unsigned char *)0x0) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(newNode + 0x10,value);
      *(undefined4 *)(newNode + 0x18) = *(undefined4 *)(value + 8);
    }
    *(unsigned char **)(y + 0xc) = newNode;
    header = *(int *)(tree + 4);
    if (y != *(int *)(header + 0xc)) goto storeNewNode;
  }
  *(unsigned char **)(header + 0xc) = newNode;
storeNewNode:
  *(int *)(newNode + 4) = y;
  *(undefined4 *)(newNode + 0xc) = 0;
  *(undefined4 *)(newNode + 8) = 0;
  std___Rb_tree_rebalance(newNode,(unsigned char **)(*(int *)(tree + 4) + 4));
  *(int *)(tree + 8) = *(int *)(tree + 8) + 1;
  *(unsigned char **)result = newNode;
  return result;
}

/* __ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueERKS8_ @ 0x97c334d8 (388 bytes) */
int __ZNSt8_Rb_treeISbIcSt11char_traitsIcE14pool_allocatorIcEESt4pairIKS4_9TBehaviorESt10_Select1stIS8_ESt4lessIS4_ES2_IS8_EE13insert_uniqueERKS8_(result, tree, value)
  unsigned char * result;
  unsigned char * tree;
  int value;
{
  uint valueKeySize2;
  uint jKeySize;
  int jNode;
  int compareResult;
  int comp;
  int finalCompareResult;
  uint *minSizeRef;
  void *keyChars;
  int header;
  int y;
  int x;
  uint valueKeySize;
  uint nodeKeySize;
  int j [4];
  int insertResultLeft [4];
  int insertResultRight [4];
  uint minArg1A;
  uint minArg1B;
  uint minArg2A;
  uint minArg2B;
  
  header = *(int *)(tree + 4);
  comp = 1;
  y = header;
  if (*(int *)(header + 4) != 0) {
    keyChars = *(void **)(value + 4);
    x = *(int *)(header + 4);
    do {
      y = x;
      valueKeySize = *(uint *)((int)keyChars + -0xc);
      minArg1A = valueKeySize;
      nodeKeySize = *(uint *)(*(int *)(y + 0x14) + -0xc);
      minArg1B = nodeKeySize;
      minSizeRef = &minArg1B;
      if (valueKeySize <= nodeKeySize) {
        minSizeRef = &minArg1A;
      }
      compareResult = _memcmp(keyChars,*(void **)(y + 0x14),*minSizeRef);
      if (compareResult == 0) {
        compareResult = valueKeySize - nodeKeySize;
      }
      comp = -(compareResult >> 0x1f);
      if (comp == 0) {
        x = *(int *)(y + 0xc);
      }
      else {
        x = *(int *)(y + 8);
      }
    } while (x != 0);
  }
  j[0] = y;
  if (comp != 0) {
    insertResultLeft[0] = *(int *)(header + 8);
    if (y == insertResultLeft[0]) {
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_insert)((unsigned char *)insertResultRight,tree,(unsigned char *)0x0,y,value);
      goto storeResult;
    }
    std___Rb_tree_base_iterator___M_decrement((unsigned char *)j);
  }
  jNode = j[0];
  minSizeRef = &minArg2B;
  jKeySize = *(uint *)(*(int *)(j[0] + 0x14) + -0xc);
  minArg2A = jKeySize;
  valueKeySize2 = *(uint *)((int)*(void **)(value + 4) + -0xc);
  minArg2B = valueKeySize2;
  if (jKeySize <= valueKeySize2) {
    minSizeRef = &minArg2A;
  }
  finalCompareResult = _memcmp(*(void **)(j[0] + 0x14),*(void **)(value + 4),*minSizeRef);
  if (finalCompareResult == 0) {
    finalCompareResult = jKeySize - valueKeySize2;
  }
  if (-1 < finalCompareResult) {
    *(int *)result = jNode;
    *(undefined4 *)(result + 4) = 0;
    return result;
  }
  ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_insert)((unsigned char *)insertResultLeft,tree,(unsigned char *)0x0,y,value);
  insertResultRight[0] = insertResultLeft[0];
storeResult:
  *(int *)result = insertResultRight[0];
  *(undefined4 *)(result + 4) = 1;
  return result;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcS3_EEEERS3_S8_S8_T_SA_ @ 0x97c3365c (152 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIN9__gnu_cxx17__normal_iteratorIPcS3_EEEERS3_S8_S8_T_SA_(this, i1, i2, first, last)
  unsigned char * this;
  int i1;
  int i2;
  void *first;
  int last;
{
  int data;
  uint length;
  
  length = last - (int)first;
  if (0x3ffffffb < length) {
    std____throw_length_error("basic_string::_M_replace");
  }
  data = *(int *)(this + 4);
  ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE9_M_mutateEmmm)(this,i1 - data,i2 - i1,length);
  if (length != 0) {
    _memcpy((void *)(*(int *)(this + 4) + (i1 - data)),first,length);
  }
  return this;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE9_M_mutateEmmm @ 0x97c336f4 (344 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE9_M_mutateEmmm(this, pos, len1, len2)
  void *this;
  ulong pos;
  ulong len1;
  ulong len2;
{
  int oldData;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  void *data;
  uint newCapacity;
  int newRep;
  void *tailSrc;
  size_t tailBytes;
  uint newSize;
  char reservation;
  byte cr0Reg;
  undefined4 allocatorCopy [8];
  
  data = *(void **)((int)this + 4);
  tailSrc = (void *)((int)data + len1 + pos);
  tailBytes = (*(int *)((int)data + -0xc) - pos) - len1;
  newSize = (*(int *)((int)data + -0xc) + len2) - len1;
  if ((*(int *)((int)data + -4) < 1) && (newSize <= *(uint *)((int)data + -8))) {
    if ((tailBytes != 0) && (len1 != len2)) {
      _memmove((void *)((int)data + len2 + pos),tailSrc,tailBytes);
      data = *(void **)((int)this + 4);
    }
  }
  else {
    allocatorCopy[0] = *(undefined4 *)this;
    newCapacity = newSize;
    if ((*(uint *)((int)data + -8) < newSize) &&
       ((0xfe3 < newSize && (newCapacity = *(uint *)((int)data + -8) << 1, newCapacity < newSize)))) {
      newCapacity = newSize;
    }
    newRep = __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep9_S_createEmRKS2_
                      (newCapacity,(unsigned char *)allocatorCopy);
    data = (void *)(newRep + 0xc);
    if (pos != 0) {
      _memcpy(data,*(void **)((int)this + 4),pos);
    }
    if (tailBytes != 0) {
      _memcpy((void *)((int)data + len2 + pos),tailSrc,tailBytes);
    }
    oldData = *(int *)((int)this + 4);
    refCountPtr = (int *)(oldData + -4);
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(oldData + -0xc),allocatorCopy);
    }
    *(void **)((int)this + 4) = data;
  }
  *(undefined4 *)((int)data + -4) = 0;
  *(uint *)(*(int *)((int)this + 4) + -0xc) = newSize;
  *(undefined1 *)(*(int *)((int)this + 4) + newSize) = 0;
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1IPKcEET_S7_RKS2_ @ 0x97c3384c (4 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1IPKcEET_S7_RKS2_(this, str1, str2, pool_allocator)
  void *this;
  char *str1;
  char *str2;
  unsigned char * pool_allocator;
{
  return ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4IPKcEET_S7_RKS2_)(this,str1,str2,pool_allocator);
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4IPKcEET_S7_RKS2_ @ 0x97c33850 (76 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC4IPKcEET_S7_RKS2_(this, first, last, alloc)
  void *this;
  char *first;
  char *last;
  unsigned char * alloc;
{
  undefined4 allocatorArg;
  char *data;
  
  data = __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE12_S_constructIPKcEEPcT_S8_RKS2_St20forward_iterator_tag
                     (first,last,alloc,0);
  allocatorArg = *(undefined4 *)alloc;
  *(char **)((int)this + 4) = data;
  *(undefined4 *)this = allocatorArg;
  return;
}

/* std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState_____M_insert_aux @ 0x97c3389c (640 bytes) */
int std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState_____M_insert_aux( unsigned char
                   *this,undefined4 *position,undefined4 *x)

{
  undefined4 *srcCursor;
  undefined4 *newStartAlloc;
  int elemsToMove;
  int oldCapacity;
  int freeListIndex;
  undefined *freeListBase;
  undefined4 *finish;
  undefined4 atomicStore;
  undefined *forceNewFlagPtr;
  int oldSize;
  int len;
  undefined4 xWord0;
  undefined4 movedWord;
  char *getenvResult;
  void *oldStartPtr;
  int oldStart;
  undefined4 xWord1;
  undefined4 *copyDest;
  uint lenBytes;
  char reservation;
  byte cr0Flags;
  undefined4 *newFinish [2];
  undefined4 *newStart;
  void *destroyCursor;
  
  forceNewFlagPtr = PTR__S_force_new_a7b7c0e8;
  finish = *(undefined4 **)(this + 4);
  if (finish == *(undefined4 **)(this + 8)) {
    oldStart = *(int *)this;
    len = 1;
    oldSize = (int)finish - oldStart >> 3;
    cr0Flags = (oldSize == 0) << 1;
    if (oldSize != 0) {
      len = oldSize << 1;
    }
    newStartAlloc = (undefined4 *)0x0;
    lenBytes = 0;
    if (len != 0) {
      lenBytes = len * 8;
      if (*(int *)PTR__S_force_new_a7b7c0e8 == 0) {
        getenvResult = _getenv("GLIBCPP_FORCE_NEW");
        if (getenvResult == (char *)0x0) {
          do {
            if (reservation != '\0') {
              atomicStore = storeWordConditionalIndexed(*(int *)forceNewFlagPtr + -1,0,forceNewFlagPtr);
              *(undefined4 *)forceNewFlagPtr = atomicStore;
              cr0Flags = 2;
            }
          } while (!(bool)(cr0Flags >> 1 & 1));
        }
        else {
          do {
            if (reservation != '\0') {
              atomicStore = storeWordConditionalIndexed(*(int *)forceNewFlagPtr + 1,0,forceNewFlagPtr);
              *(undefined4 *)forceNewFlagPtr = atomicStore;
              cr0Flags = 2;
            }
          } while (!(bool)(cr0Flags >> 1 & 1));
        }
      }
      freeListBase = PTR__S_free_list_a7b7c0e4;
      if ((lenBytes < 0x81) && (*(int *)PTR__S_force_new_a7b7c0e8 < 1)) {
        freeListIndex = (lenBytes + 7 >> 1 & 0x7ffffffc) - 4;
        _pthread_mutex_lock((pthread_mutex_t *)PTR__S_node_allocator_lock_a7b7c0e0);
        newStartAlloc = *(undefined4 **)(freeListBase + freeListIndex);
        if (newStartAlloc == (undefined4 *)0x0) {
          newStartAlloc = (undefined4 *)std____default_alloc_template_true_0____S_refill(lenBytes);
        }
        else {
          *(undefined4 *)(freeListBase + freeListIndex) = *newStartAlloc;
        }
        if (newStartAlloc == (undefined4 *)0x0) {
          std____throw_bad_alloc();
        }
        _pthread_mutex_unlock((pthread_mutex_t *)PTR__S_node_allocator_lock_a7b7c0e0);
      }
      else {
        newStartAlloc = operator_new(lenBytes);
      }
      oldStart = *(int *)this;
    }
    newStart = newStartAlloc;
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState______gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState____)(newFinish,oldStart,position,newStartAlloc);
    if (newFinish[0] != (undefined4 *)0x0) {
      xWord0 = *x;
      newFinish[0][1] = x[1];
      *newFinish[0] = xWord0;
    }
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState______gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState____)(newFinish,position,*(undefined4 *)(this + 4),newFinish[0] + 2);
    oldStartPtr = *(void **)this;
    for (destroyCursor = oldStartPtr; destroyCursor != *(void **)(this + 4); destroyCursor = (void *)((int)destroyCursor + 8)
        ) {
    }
    oldCapacity = *(int *)(this + 8) - (int)oldStartPtr >> 3;
    if (oldCapacity != 0) {
      std____default_alloc_template_true_0___deallocate(oldStartPtr,oldCapacity << 3);
    }
    *(undefined4 **)(this + 4) = newFinish[0];
    *(undefined4 **)this = newStart;
    *(uint *)(this + 8) = (int)newStart + lenBytes;
  }
  else {
    copyDest = (undefined4 *)0x0;
    if (finish != (undefined4 *)0x0) {
      finish[1] = finish[-1];
      *finish = finish[-2];
      copyDest = *(undefined4 **)(this + 4);
    }
    *(undefined4 **)(this + 4) = copyDest + 2;
    xWord1 = x[1];
    elemsToMove = (int)(copyDest + -2) - (int)position >> 3;
    xWord0 = *x;
    srcCursor = copyDest + -2;
    if (0 < elemsToMove) {
      do {
        movedWord = srcCursor[-1];
        copyDest[-2] = srcCursor[-2];
        copyDest[-1] = movedWord;
        elemsToMove = elemsToMove + -1;
        copyDest = copyDest + -2;
        srcCursor = srcCursor + -2;
      } while (elemsToMove != 0);
    }
    position[1] = xWord1;
    *position = xWord0;
  }
  return;
}

/* std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState______gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState____ @ 0x97c33b1c (92 bytes) */
int std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState______gnu_cxx____normal_iterator_TPoolAllocator__tAllocState__std__vector_TPoolAllocator__tAllocState_std__allocator_TPoolAllocator__tAllocState____(resultSlot, first, last, result)
  int *resultSlot;
  undefined4 *first;
  undefined4 *last;
  int result;
{
  undefined4 elemWord0;
  undefined4 *dest;
  int nextDest;
  
  *resultSlot = result;
  if (first != last) {
    do {
      dest = (undefined4 *)*resultSlot;
      nextDest = 0;
      if (dest != (undefined4 *)0x0) {
        elemWord0 = *first;
        dest[1] = first[1];
        *dest = elemWord0;
        nextDest = *resultSlot;
      }
      first = first + 2;
      *resultSlot = nextDest + 8;
    } while (first != last);
    return;
  }
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase @ 0x97c33b78 (128 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase( unsigned char
                *this, unsigned char *node)

{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int keyData;
  char reservation;
  byte cr0Flags;
  undefined4 allocatorCopy [4];
  
  cr0Flags = (node == (unsigned char *)0x0) << 1;
  if (node != (unsigned char *)0x0) {
    do {
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior______M_erase)(this,*(unsigned char **)(node + 0xc));
      allocatorCopy[0] = *(undefined4 *)(node + 0x10);
      keyData = *(int *)(node + 0x14);
      refCountPtr = (int *)(keyData + -4);
      node = *(unsigned char **)(node + 8);
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
                  ((unsigned char *)(keyData + -0xc),allocatorCopy);
      }
    } while (node != (unsigned char *)0x0);
  }
  return;
}

/* std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux @ 0x97c33bf8 (516 bytes) */
int std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux(this, position, symbolTableLevel)
  unsigned char * this;
  undefined4 *position;
  undefined4 *symbolTableLevel;
{
  uint moveBytes;
  void *backStart;
  int finishCursor;
  int oldCapacity;
  int freeListIndex;
  undefined *freeListBase;
  undefined4 *finish;
  int oldFinish;
  undefined4 atomicStore;
  undefined *forceNewFlagPtr;
  int oldSize;
  undefined4 *newStart;
  int len;
  char *getenvResult;
  void *oldStart;
  uint lenBytes;
  undefined4 xValue;
  size_t frontBytes;
  char reservation;
  byte cr0Flags;
  
  forceNewFlagPtr = PTR__S_force_new_a7b7c0e8;
  finish = *(undefined4 **)(this + 4);
  if (finish == *(undefined4 **)(this + 8)) {
    oldStart = *(void **)this;
    len = 1;
    oldSize = (int)finish - (int)oldStart >> 2;
    cr0Flags = (oldSize == 0) << 1;
    if (oldSize != 0) {
      len = oldSize << 1;
    }
    newStart = (undefined4 *)0x0;
    lenBytes = 0;
    if (len != 0) {
      lenBytes = len * 4;
      if (*(int *)PTR__S_force_new_a7b7c0e8 == 0) {
        getenvResult = _getenv("GLIBCPP_FORCE_NEW");
        if (getenvResult == (char *)0x0) {
          do {
            if (reservation != '\0') {
              atomicStore = storeWordConditionalIndexed(*(int *)forceNewFlagPtr + -1,0,forceNewFlagPtr);
              *(undefined4 *)forceNewFlagPtr = atomicStore;
              cr0Flags = 2;
            }
          } while (!(bool)(cr0Flags >> 1 & 1));
        }
        else {
          do {
            if (reservation != '\0') {
              atomicStore = storeWordConditionalIndexed(*(int *)forceNewFlagPtr + 1,0,forceNewFlagPtr);
              *(undefined4 *)forceNewFlagPtr = atomicStore;
              cr0Flags = 2;
            }
          } while (!(bool)(cr0Flags >> 1 & 1));
        }
      }
      freeListBase = PTR__S_free_list_a7b7c0e4;
      if ((lenBytes < 0x81) && (*(int *)PTR__S_force_new_a7b7c0e8 < 1)) {
        freeListIndex = (lenBytes + 7 >> 1 & 0x7ffffffc) - 4;
        _pthread_mutex_lock((pthread_mutex_t *)PTR__S_node_allocator_lock_a7b7c0e0);
        newStart = *(undefined4 **)(freeListBase + freeListIndex);
        if (newStart == (undefined4 *)0x0) {
          newStart = (undefined4 *)
                   std____default_alloc_template_true_0____S_refill(lenBytes + 7 & 0xfffffff8);
        }
        else {
          *(undefined4 *)(freeListBase + freeListIndex) = *newStart;
        }
        if (newStart == (undefined4 *)0x0) {
          std____throw_bad_alloc();
        }
        _pthread_mutex_unlock((pthread_mutex_t *)PTR__S_node_allocator_lock_a7b7c0e0);
      }
      else {
        newStart = operator_new(lenBytes);
      }
      oldStart = *(void **)this;
    }
    frontBytes = (int)position - (int)oldStart;
    _memmove(newStart,oldStart,frontBytes);
    if ((int)newStart + frontBytes != 0) {
      *(undefined4 *)((int)newStart + frontBytes) = *symbolTableLevel;
    }
    oldFinish = *(int *)(this + 4);
    backStart = (void *)((int)newStart + frontBytes + 4);
    _memmove(backStart,position,oldFinish - (int)position);
    oldCapacity = *(int *)(this + 8) - (int)*(void **)this >> 2;
    if (oldCapacity != 0) {
      std____default_alloc_template_true_0___deallocate(*(void **)this,oldCapacity << 2);
    }
    *(int *)(this + 4) = (int)backStart + (oldFinish - (int)position);
    *(undefined4 **)this = newStart;
    *(uint *)(this + 8) = (int)newStart + lenBytes;
  }
  else {
    finishCursor = 0;
    if (finish != (undefined4 *)0x0) {
      *finish = finish[-1];
      finishCursor = *(int *)(this + 4);
    }
    *(int *)(this + 4) = finishCursor + 4;
    moveBytes = (finishCursor + -4) - (int)position & 0xfffffffc;
    xValue = *symbolTableLevel;
    _memmove((void *)(finishCursor - moveBytes),position,moveBytes);
    *position = xValue;
  }
  return;
}

