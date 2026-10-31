#include "decls.h"

/* std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_insert @ 0x97c30ec8 (356 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_insert(resultIter, tree, hintX, parentNode, value)
  unsigned char * resultIter;
  unsigned char * tree;
  unsigned char * hintX;
  int parentNode;
  unsigned char * value;
{
  int keyCompare;
  int headerNode;
  unsigned char * newNode;
  uint *minLengthPtr;
  uint nodeKeyLength;
  uint keyLength;
  uint keyLengthCopy;
  uint nodeKeyLengthCopy [4];
  
  if ((parentNode == *(int *)(tree + 4)) || (hintX != (unsigned char *)0x0)) {
loopSetNewNode:
    newNode = (unsigned char *)TPoolAllocator__allocate(*(unsigned char **)tree,0x1c);
    if (newNode + 0x10 != (unsigned char *)0x0) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(newNode + 0x10,value);
      *(undefined4 *)(newNode + 0x18) = *(undefined4 *)(value + 8);
    }
    *(unsigned char **)(parentNode + 8) = newNode;
    headerNode = *(int *)(tree + 4);
    if (parentNode != headerNode) {
      if (parentNode == *(int *)(headerNode + 8)) {
        *(unsigned char **)(headerNode + 8) = newNode;
      }
      goto storeNewNode;
    }
    *(unsigned char **)(parentNode + 4) = newNode;
    headerNode = *(int *)(tree + 4);
  }
  else {
    minLengthPtr = nodeKeyLengthCopy;
    keyLength = *(uint *)(*(int *)(value + 4) + -0xc);
    keyLengthCopy = keyLength;
    nodeKeyLength = *(uint *)((int)*(void **)(parentNode + 0x14) + -0xc);
    nodeKeyLengthCopy[0] = nodeKeyLength;
    if (keyLength <= nodeKeyLength) {
      minLengthPtr = &keyLengthCopy;
    }
    keyCompare = _memcmp(*(void **)(value + 4),*(void **)(parentNode + 0x14),*minLengthPtr);
    if (keyCompare == 0) {
      keyCompare = keyLength - nodeKeyLength;
    }
    if (keyCompare < 0) goto loopSetNewNode;
    newNode = (unsigned char *)TPoolAllocator__allocate(*(unsigned char **)tree,0x1c);
    if (newNode + 0x10 != (unsigned char *)0x0) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(newNode + 0x10,value);
      *(undefined4 *)(newNode + 0x18) = *(undefined4 *)(value + 8);
    }
    *(unsigned char **)(parentNode + 0xc) = newNode;
    headerNode = *(int *)(tree + 4);
    if (parentNode != *(int *)(headerNode + 0xc)) goto storeNewNode;
  }
  *(unsigned char **)(headerNode + 0xc) = newNode;
storeNewNode:
  *(int *)(newNode + 4) = parentNode;
  *(undefined4 *)(newNode + 0xc) = 0;
  *(undefined4 *)(newNode + 8) = 0;
  ((int (*)())std___Rb_tree_rebalance)(newNode,(unsigned char **)(*(int *)(tree + 4) + 4));
  *(int *)(tree + 8) = *(int *)(tree + 8) + 1;
  *(unsigned char **)resultIter = newNode;
  return resultIter;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep9_S_createEmRKS2_ @ 0x97c3102c (172 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep9_S_createEmRKS2_(capacity, alloc)
  ulong capacity;
  unsigned char * alloc;
{
  uint padding;
  uint sizeEstimate;
  undefined4 *allocation;
  ulong allocSize;
  
  if (0x3ffffffc < capacity) {
    std____throw_length_error("basic_string::_S_create");
  }
  sizeEstimate = capacity + 0x1d;
  allocSize = capacity + 0xd;
  if (sizeEstimate < 0x1001) {
    if (allocSize < 0x81) goto setAllocation;
    padding = 0x80 - (sizeEstimate & 0x7f) & 0x7f;
  }
  else {
    padding = 0x1000 - (sizeEstimate & 0xfff) & 0xfff;
  }
  capacity = capacity + padding;
  allocSize = capacity + 0xd;
setAllocation:
  allocation = (undefined4 *)TPoolAllocator__allocate(*(unsigned char **)alloc,allocSize);
  *allocation = 0;
  allocation[1] = capacity;
  allocation[2] = 0;
  return allocation;
}

/* std___Rb_tree_base_iterator___M_decrement @ 0x97c310d8 (144 bytes) */
int std___Rb_tree_base_iterator___M_decrement(this)
  unsigned char * this;
{
  int parentNode;
  int rightChild;
  int predecessor;
  int *node;
  
  node = *(int **)this;
  if ((*node == 0) && (*(int **)(node[1] + 4) == node)) {
    *(int *)this = node[3];
    return;
  }
  predecessor = node[2];
  if (predecessor == 0) {
    parentNode = node[1];
    if (node == *(int **)(parentNode + 8)) {
      do {
        *(int *)this = parentNode;
        parentNode = *(int *)(parentNode + 4);
      } while (*(int *)this == *(int *)(parentNode + 8));
    }
    *(int *)this = parentNode;
    return;
  }
  for (rightChild = *(int *)(predecessor + 0xc); rightChild != 0; rightChild = *(int *)(rightChild + 0xc)) {
    predecessor = rightChild;
  }
  *(int *)this = predecessor;
  return;
}

/* std___Rb_tree_rebalance @ 0x97c31168 (328 bytes) */
int std___Rb_tree_rebalance(x, root)
  unsigned char * x;
  unsigned char ** root;
{
  unsigned char *rotateTop;
  unsigned char *pivot;
  unsigned char *grandparentChild;
  int parentColor;
  unsigned char *rootNode;
  unsigned char *parentNode;
  unsigned char *nextX;
  
  *(undefined4 *)x = 0;
  rootNode = *root;
  if (x != rootNode) {
    parentNode = *(unsigned char **)(x + 4);
    parentColor = *(int *)parentNode;
    while (parentColor == 0) {
      nextX = *(unsigned char **)(parentNode + 4);
      grandparentChild = *(unsigned char **)(nextX + 8);
      if (parentNode == grandparentChild) {
        grandparentChild = *(unsigned char **)(nextX + 0xc);
        if ((grandparentChild == (unsigned char *)0x0) || (*(int *)grandparentChild != 0)) {
          nextX = x;
          pivot = parentNode;
          if (x == *(unsigned char **)(parentNode + 0xc)) {
            ((int (*)())std___Rb_tree_rotate_left)(parentNode,root);
            pivot = *(unsigned char **)(parentNode + 4);
            nextX = parentNode;
          }
          rotateTop = *(unsigned char **)(pivot + 4);
          *(undefined4 *)pivot = 1;
          *(undefined4 *)rotateTop = 0;
          ((int (*)())std___Rb_tree_rotate_right)(rotateTop,root);
        }
        else {
loopStoreParentNode:
          *(undefined4 *)parentNode = 1;
          *(undefined4 *)grandparentChild = 1;
          *(undefined4 *)nextX = 0;
        }
      }
      else {
        if ((grandparentChild != (unsigned char *)0x0) && (*(int *)grandparentChild == 0)) goto loopStoreParentNode;
        nextX = x;
        pivot = parentNode;
        if (x == *(unsigned char **)(parentNode + 8)) {
          ((int (*)())std___Rb_tree_rotate_right)(parentNode,root);
          pivot = *(unsigned char **)(parentNode + 4);
          nextX = parentNode;
        }
        rotateTop = *(unsigned char **)(pivot + 4);
        *(undefined4 *)pivot = 1;
        *(undefined4 *)rotateTop = 0;
        ((int (*)())std___Rb_tree_rotate_left)(rotateTop,root);
      }
      rootNode = *root;
      if (nextX == rootNode) break;
      parentNode = *(unsigned char **)(nextX + 4);
      x = nextX;
      parentColor = *(int *)parentNode;
    }
  }
  *(undefined4 *)rootNode = 1;
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
  uint typeBits;
  int nominalSize;
  
  typeBits = *(uint *)(this + 0x24);
  if ((typeBits & 0x400) != 0) {
    nominalSize = (int)(typeBits << 0xd | typeBits >> 0x13) >> 0x18;
    return nominalSize * nominalSize;
  }
  return (int)(typeBits << 0xd | typeBits >> 0x13) >> 0x18;
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
  uint typeBits;
  
  typeBits = *(uint *)(this + 0x24);
  if ((int)(typeBits << 0xd | typeBits >> 0x13) >> 0x18 < 2) {
    return 0;
  }
  if ((typeBits & 0x400) != 0) {
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
int __ZN5TType7setTypeE10TBasicTypeibPS_(this, basicType, nominalSize, matrixFlag, type)
  void *this;
  uint basicType;
  uint nominalSize;
  uint matrixFlag;
  int type;
{
  *(uint *)((int)this + 0x24) =
       (matrixFlag & 1) << 10 |
       (nominalSize & 0xff) << 0xb | (basicType & 0x3f) << 0x13 | *(uint *)((int)this + 0x24) & 0xfe0003ff
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
  void *fieldName;
  unsigned char * globalPool;
  void *stringObject;
  char *textData;
  undefined4 allocRef [4];
  
  *(undefined1 *)(*(int *)(text + 4) + *(int *)(*(int *)(text + 4) + -0xc)) = *DAT_a7b7b718;
  textData = *(char **)(text + 4);
  globalPool = (unsigned char *)GetGlobalPoolAllocator();
  stringObject = (void *)TPoolAllocator__allocate(globalPool,8);
  fieldName = (void *)0x0;
  if (stringObject != (void *)0x0) {
    allocRef[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(stringObject,textData,(unsigned char *)allocRef);
    fieldName = stringObject;
  }
  *(void **)(this + 0xc) = fieldName;
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
int std___Rb_tree_rotate_left(x, root)
  unsigned char * x;
  unsigned char ** root;
{
  int xParent;
  int innerSubtree;
  unsigned char * y;
  
  y = *(unsigned char **)(x + 0xc);
  innerSubtree = *(int *)(y + 8);
  *(int *)(x + 0xc) = innerSubtree;
  if (innerSubtree != 0) {
    *(unsigned char **)(innerSubtree + 4) = x;
  }
  *(undefined4 *)(y + 4) = *(undefined4 *)(x + 4);
  if (x == *root) {
    *root = y;
  }
  else {
    xParent = *(int *)(x + 4);
    if (x == *(unsigned char **)(xParent + 8)) {
      *(unsigned char **)(xParent + 8) = y;
    }
    else {
      *(unsigned char **)(xParent + 0xc) = y;
    }
  }
  *(unsigned char **)(x + 4) = y;
  *(unsigned char **)(y + 8) = x;
  return;
}

/* std___Rb_tree_rotate_right @ 0x97c31554 (92 bytes) */
int std___Rb_tree_rotate_right(x, root)
  unsigned char * x;
  unsigned char ** root;
{
  int xParent;
  int innerSubtree;
  unsigned char * y;
  
  y = *(unsigned char **)(x + 8);
  innerSubtree = *(int *)(y + 0xc);
  *(int *)(x + 8) = innerSubtree;
  if (innerSubtree != 0) {
    *(unsigned char **)(innerSubtree + 4) = x;
  }
  *(undefined4 *)(y + 4) = *(undefined4 *)(x + 4);
  if (x == *root) {
    *root = y;
  }
  else {
    xParent = *(int *)(x + 4);
    if (x == *(unsigned char **)(xParent + 0xc)) {
      *(unsigned char **)(xParent + 0xc) = y;
    }
    else {
      *(unsigned char **)(xParent + 8) = y;
    }
  }
  *(unsigned char **)(x + 4) = y;
  *(unsigned char **)(y + 0xc) = x;
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
  int *srcRefCountPtr;
  int oldRefCount;
  int adoptedData;
  int oldData;
  char reservation;
  byte cr0Reg;
  int thisAlloc [4];
  int srcPool;
  
  adoptedData = *(int *)(text + 4);
  if ((void *)(*(int *)((int)this + 4) + -0xc) != (void *)(adoptedData + -0xc)) {
    srcPool = *(int *)text;
    thisAlloc[0] = *(int *)this;
    if ((*(int *)(adoptedData + -4) < 0) || (thisAlloc[0] != srcPool)) {
      adoptedData = __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep8_M_cloneERKS2_m
                        ((void *)(adoptedData + -0xc),(unsigned char *)thisAlloc,0);
    }
    else {
      srcRefCountPtr = (int *)(adoptedData + -4);
      do {
        if (reservation != '\0') {
          atomicStore = storeWordConditionalIndexed(*srcRefCountPtr + 1,0,srcRefCountPtr);
          *srcRefCountPtr = atomicStore;
          cr0Reg = 2;
        }
      } while (!(bool)(cr0Reg >> 1 & 1));
    }
    oldData = *(int *)((int)this + 4);
    refCountPtr = (int *)(oldData + -4);
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
                ((unsigned char *)(oldData + -0xc),(unsigned char *)thisAlloc);
    }
    *(int *)((int)this + 4) = adoptedData;
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
              *this, unsigned char *source)

{
  int rightmostNode;
  int rightChild;
  int leftChild;
  int leftmostNode;
  undefined4 copiedRoot;
  
  if (this != (unsigned char
               *)source) {
    if (*(int *)(this + 8) != 0) {
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase)(this,*(unsigned char **)(*(int *)(this + 4) + 4));
      *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
      *(undefined4 *)(*(int *)(this + 4) + 4) = 0;
      *(int *)(*(int *)(this + 4) + 0xc) = *(int *)(this + 4);
      *(undefined4 *)(this + 8) = 0;
    }
    *(undefined4 *)(this + 8) = 0;
    if (*(unsigned char **)(*(int *)(source + 4) + 4) == (unsigned char *)0x0) {
      *(undefined4 *)(*(int *)(this + 4) + 4) = 0;
      *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
      *(int *)(*(int *)(this + 4) + 0xc) = *(int *)(this + 4);
    }
    else {
      copiedRoot = ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy)(this,*(unsigned char **)(*(int *)(source + 4) + 4),
                        *(unsigned char **)(this + 4));
      *(undefined4 *)(*(int *)(this + 4) + 4) = copiedRoot;
      leftmostNode = *(int *)(*(int *)(this + 4) + 4);
      for (leftChild = *(int *)(leftmostNode + 8); leftChild != 0; leftChild = *(int *)(leftChild + 8)) {
        leftmostNode = leftChild;
      }
      *(int *)(*(int *)(this + 4) + 8) = leftmostNode;
      rightmostNode = *(int *)(*(int *)(this + 4) + 4);
      for (rightChild = *(int *)(rightmostNode + 0xc); rightChild != 0; rightChild = *(int *)(rightChild + 0xc)) {
        rightmostNode = rightChild;
      }
      *(int *)(*(int *)(this + 4) + 0xc) = rightmostNode;
      *(undefined4 *)(this + 8) = *(undefined4 *)(source + 8);
    }
  }
  return this;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy @ 0x97c31b2c (280 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy( unsigned char
          *this, unsigned char *srcRoot, unsigned char *parentNode)

{
  undefined4 copiedSubtree;
  undefined4 nodeColor;
  unsigned char * newRoot;
  unsigned char * newNode;
  unsigned char * prevNode;
  unsigned char * srcRight;
  undefined4 *srcNode;
  
  newRoot = (unsigned char *)TPoolAllocator__allocate(*(unsigned char **)this,0x20);
  if (newRoot + 0x10 != (unsigned char *)0x0) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(newRoot + 0x10,(unsigned char *)(srcRoot + 0x10))
    ;
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(newRoot + 0x18,(unsigned char *)(srcRoot + 0x18))
    ;
  }
  nodeColor = *(undefined4 *)srcRoot;
  *(undefined4 *)(newRoot + 0xc) = 0;
  prevNode = *(unsigned char **)(srcRoot + 0xc);
  *(undefined4 *)newRoot = nodeColor;
  *(unsigned char **)(newRoot + 4) = parentNode;
  *(undefined4 *)(newRoot + 8) = 0;
  if (prevNode != (unsigned char *)0x0) {
    copiedSubtree = ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy)(this,prevNode,newRoot);
    *(undefined4 *)(newRoot + 0xc) = copiedSubtree;
  }
  prevNode = newRoot;
  for (srcNode = *(undefined4 **)(srcRoot + 8); srcNode != (undefined4 *)0x0;
      srcNode = (undefined4 *)srcNode[2]) {
    newNode = (unsigned char *)TPoolAllocator__allocate(*(unsigned char **)this,0x20);
    if (newNode + 0x10 != (unsigned char *)0x0) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(newNode + 0x10,(unsigned char *)(srcNode + 4));
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(newNode + 0x18,(unsigned char *)(srcNode + 6));
    }
    *(undefined4 *)(newNode + 0xc) = 0;
    srcRight = (unsigned char *)srcNode[3];
    nodeColor = *srcNode;
    *(undefined4 *)(newNode + 8) = 0;
    *(undefined4 *)newNode = nodeColor;
    *(unsigned char **)(newNode + 4) = prevNode;
    *(unsigned char **)(prevNode + 8) = newNode;
    if (srcRight != (unsigned char *)0x0) {
      copiedSubtree = ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_copy)(this,srcRight,newNode);
      *(undefined4 *)(newNode + 0xc) = copiedSubtree;
    }
    prevNode = newNode;
  }
  return newRoot;
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
        goto setTotalSize;
      }
      if (*(unsigned char **)(*entry + 8) != (unsigned char *)0x0) {
        memberSize = ((int (*)())TType__setStructSize)(this,*(unsigned char **)(*entry + 8));
        goto setTotalSize;
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
setTotalSize:
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
int TIntermNode__setLine(this, line)
  unsigned char * this;
  int line;
{
  *(int *)(this + 4) = line;
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
  uint typeBits;
  int nominalSize;
  
  typeBits = *(uint *)(this + 0x2c);
  if ((typeBits & 0x400) != 0) {
    nominalSize = (int)(typeBits << 0xd | typeBits >> 0x13) >> 0x18;
    return nominalSize * nominalSize;
  }
  return (int)(typeBits << 0xd | typeBits >> 0x13) >> 0x18;
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
  uint typeBits;
  
  typeBits = *(uint *)(this + 0x2c);
  if ((int)(typeBits << 0xd | typeBits >> 0x13) >> 0x18 < 2) {
    return 0;
  }
  if ((typeBits & 0x400) != 0) {
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
                *this, unsigned char *node)

{
  int firstData;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int secondData;
  unsigned char * leftChild;
  char reservation;
  byte cr0Flags;
  undefined4 secondAlloc [4];
  undefined4 firstAlloc [5];
  
  cr0Flags = (node == (unsigned char *)0x0) << 1;
  if (node != (unsigned char *)0x0) {
    do {
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_std__string__std___Select1st_std__pair_std__string_const_std__string___std__less_std__string__pool_allocator_std__pair_std__string_const_std__string______M_erase)(this,*(unsigned char **)(node + 0xc));
      secondAlloc[0] = *(undefined4 *)(node + 0x18);
      secondData = *(int *)(node + 0x1c);
      refCountPtr = (int *)(secondData + -4);
      leftChild = *(unsigned char **)(node + 8);
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
                  ((unsigned char *)(secondData + -0xc),secondAlloc);
      }
      firstData = *(int *)(node + 0x14);
      firstAlloc[0] = *(undefined4 *)(node + 0x10);
      refCountPtr = (int *)(firstData + -4);
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
                  ((unsigned char *)(firstData + -0xc),firstAlloc);
      }
      node = leftChild;
    } while (leftChild != (unsigned char *)0x0);
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

