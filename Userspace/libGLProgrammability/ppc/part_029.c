#include "decls.h"

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc @ 0x97c33dfc (108 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(this, n, c)
  void *this;
  ulong n;
  undefined4 c;
{
  ulong newSize;
  int data;
  
  data = *(int *)((int)this + 4);
  newSize = n + *(int *)(data + -0xc);
  if (*(uint *)(data + -8) < newSize) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7reserveEm(this,newSize);
    data = *(int *)((int)this + 4);
  }
  data = data + *(int *)(data + -0xc);
  return ((int (*)())__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7replaceEN9__gnu_cxx17__normal_iteratorIPcS3_EES7_mc)(this,data,data,n,c);
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_erase @ 0x97c33e68 (128 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_erase( unsigned char
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
      ((int (*)())std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_erase)(this,*(unsigned char **)(node + 0xc));
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

/* std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux @ 0x97c33ee8 (384 bytes) */
int std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux(this, position, newParameter)
  unsigned char * this;
  undefined4 *position;
  undefined4 *newParameter;
{
  int elemsToMove;
  undefined4 *finish;
  int allocation;
  int oldSize;
  int destroyCursor;
  int len;
  undefined4 xWord0;
  undefined4 movedWord;
  undefined4 *srcCursor;
  undefined4 xWord1;
  undefined4 *copyDest;
  undefined4 *newFinish [5];
  
  finish = *(undefined4 **)(this + 8);
  if (finish == *(undefined4 **)(this + 0xc)) {
    len = 1;
    oldSize = (int)finish - *(int *)(this + 4) >> 3;
    if (oldSize != 0) {
      len = oldSize << 1;
    }
    allocation = TPoolAllocator__allocate(*(unsigned char **)this,len * 8);
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter______gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter____)(newFinish,*(undefined4 *)(this + 4),position,allocation);
    if (newFinish[0] != (undefined4 *)0x0) {
      xWord0 = *newParameter;
      newFinish[0][1] = newParameter[1];
      *newFinish[0] = xWord0;
    }
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter______gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter____)(newFinish,position,*(undefined4 *)(this + 8),newFinish[0] + 2);
    for (destroyCursor = *(int *)(this + 4); destroyCursor != *(int *)(this + 8); destroyCursor = destroyCursor + 8) {
    }
    *(undefined4 **)(this + 8) = newFinish[0];
    *(int *)(this + 0xc) = allocation + len * 8;
    *(int *)(this + 4) = allocation;
  }
  else {
    copyDest = (undefined4 *)0x0;
    if (finish != (undefined4 *)0x0) {
      finish[1] = finish[-1];
      *finish = finish[-2];
      copyDest = *(undefined4 **)(this + 8);
    }
    *(undefined4 **)(this + 8) = copyDest + 2;
    xWord1 = newParameter[1];
    elemsToMove = (int)(copyDest + -2) - (int)position >> 3;
    xWord0 = *newParameter;
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

/* std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine________M_erase @ 0x97c34068 (88 bytes) */
int std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine________M_erase( unsigned char
                *this, unsigned char *node)

{
  unsigned char * leftChild;
  
  while (node != (unsigned char *)0x0) {
    ((int (*)())std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine________M_erase)(this,*(unsigned char **)(node + 0xc));
    leftChild = *(unsigned char **)(node + 8);
    std____default_alloc_template_true_0___deallocate(node,0x18);
    node = leftChild;
  }
  return;
}

/* __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7replaceEN9__gnu_cxx17__normal_iteratorIPcS3_EES7_mc @ 0x97c340c0 (160 bytes) */
int __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE7replaceEN9__gnu_cxx17__normal_iteratorIPcS3_EES7_mc(this, i1, i2, n, c)
  void *this;
  int i1;
  int i2;
  uint n;
  int c;
{
  ulong offset;
  
  offset = i1 - *(int *)((int)this + 4);
  if (0x3ffffffcU - (*(int *)(*(int *)((int)this + 4) + -0xc) - (i2 - i1)) <= n) {
    std____throw_length_error("basic_string::replace");
  }
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE9_M_mutateEmmm(this,offset,i2 - i1,n)
  ;
  if (n != 0) {
    _memset((void *)(*(int *)((int)this + 4) + offset),c,n);
  }
  return this;
}

/* std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter______gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter____ @ 0x97c34160 (92 bytes) */
int std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter______gnu_cxx____normal_iterator_TParameter__std__vector_TParameter_pool_allocator_TParameter____(resultSlot, first, last, result)
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

/* std___Rb_tree_base_iterator___M_increment @ 0x97c341bc (120 bytes) */
int std___Rb_tree_base_iterator___M_increment(this)
  unsigned char * this;
{
  int parent;
  int leftmost;
  int right;
  int node;
  
  node = *(int *)this;
  right = *(int *)(node + 0xc);
  if (right != 0) {
    *(int *)this = right;
    if (*(int *)(right + 8) != 0) {
      do {
        leftmost = *(int *)(*(int *)this + 8);
        *(int *)this = leftmost;
      } while (*(int *)(leftmost + 8) != 0);
      return;
    }
    return;
  }
  parent = *(int *)(node + 4);
  if (node == *(int *)(parent + 0xc)) {
    do {
      *(int *)this = parent;
      parent = *(int *)(parent + 4);
      node = *(int *)this;
    } while (node == *(int *)(parent + 0xc));
  }
  if (*(int *)(node + 0xc) != parent) {
    *(int *)this = parent;
    return;
  }
  return;
}

/* TType__copyType @ 0x97c34234 (800 bytes) */
int TType__copyType(this, copyOf, remapper)
  unsigned char * this;
  unsigned char * copyOf;
  unsigned char * remapper;
{
  undefined4 *memberFinish;
  int srcMangled;
  int srcTypeName;
  int srcFieldName;
  int finishCursor;
  int srcMembers;
  uint memberIndex;
  uint srcBasicTypeBits;
  uint srcQualifierBits;
  uint srcIsMatrixBit;
  uint dstTypeBits;
  void *newString;
  int srcStructure;
  undefined4 srcStructureSize;
  unsigned char * poolAllocator;
  undefined4 *newTypeList;
  unsigned char * newFieldType;
  unsigned char * newStructure;
  void *stringAlloc;
  undefined4 *typeListOrNull;
  undefined4 srcWord1c;
  uint srcNominalSizeBits;
  char *srcChars;
  unsigned char * srcFieldType;
  unsigned char * findResult [4];
  unsigned char * remapperEnd;
  undefined4 listAllocator;
  unsigned char * typeLineType;
  undefined4 typeLineLine;
  undefined4 fieldNameAllocSlot [4];
  undefined4 typeNameAllocSlot [4];
  undefined4 mangledAllocSlot [7];
  
  dstTypeBits = *(uint *)(this + 0x24);
  srcBasicTypeBits = (*(uint *)(copyOf + 0x24) >> 0x13 & 0x3f) << 0x13;
  *(uint *)(this + 0x24) = srcBasicTypeBits | dstTypeBits & 0xfe07ffff;
  srcQualifierBits = *(uint *)(copyOf + 0x24) & 0xfe000000;
  *(uint *)(this + 0x24) = srcQualifierBits | srcBasicTypeBits | dstTypeBits & 0x7ffff;
  srcNominalSizeBits = *(uint *)(copyOf + 0x24) & 0x7f800;
  *(uint *)(this + 0x24) = srcNominalSizeBits | srcQualifierBits | srcBasicTypeBits | dstTypeBits & 0x7ff;
  srcIsMatrixBit = (*(uint *)(copyOf + 0x24) >> 10 & 1) << 10;
  *(uint *)(this + 0x24) = srcIsMatrixBit | srcNominalSizeBits | srcQualifierBits | srcBasicTypeBits | dstTypeBits & 0x3ff;
  *(uint *)(this + 0x24) =
       (*(uint *)(copyOf + 0x24) >> 9 & 1) << 9 | srcIsMatrixBit | srcNominalSizeBits | srcQualifierBits | srcBasicTypeBits | dstTypeBits & 0x1ff;
  srcStructure = *(int *)(copyOf + 8);
  *(undefined4 *)(this + 4) = *(undefined4 *)(copyOf + 4);
  if (srcStructure == 0) {
    *(undefined4 *)(this + 8) = 0;
  }
  else {
    ((int (*)())std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_______find)(findResult,remapper,this + 8);
    remapperEnd = *(unsigned char **)remapper;
    if (findResult[0] == remapperEnd) {
      poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
      newTypeList = (undefined4 *)TPoolAllocator__allocate(poolAllocator,0x10);
      typeListOrNull = (undefined4 *)0x0;
      if (newTypeList != (undefined4 *)0x0) {
        listAllocator = GetGlobalPoolAllocator();
        newTypeList[3] = 0;
        newTypeList[1] = 0;
        newTypeList[2] = 0;
        *newTypeList = listAllocator;
        typeListOrNull = newTypeList;
      }
      *(undefined4 **)(this + 8) = typeListOrNull;
      for (memberIndex = 0; srcMembers = *(int *)(*(int *)(copyOf + 8) + 4),
          memberIndex < (uint)(*(int *)(*(int *)(copyOf + 8) + 8) - srcMembers >> 3); memberIndex = memberIndex + 1) {
        typeLineLine = *(undefined4 *)(srcMembers + memberIndex * 8 + 4);
        srcFieldType = *(unsigned char **)(*(int *)(*(int *)(copyOf + 8) + 4) + memberIndex * 8);
        poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
        newFieldType = (unsigned char *)TPoolAllocator__allocate(poolAllocator,0x28);
        *(undefined ***)newFieldType = &PTR___ZN5TTypeD1Ev_a7b7d590;
        ((int (*)())TType__copyType)(newFieldType,srcFieldType,remapper);
        newStructure = *(unsigned char **)(this + 8);
        memberFinish = *(undefined4 **)(newStructure + 8);
        typeLineType = newFieldType;
        if (memberFinish == *(undefined4 **)(newStructure + 0xc)) {
          ((int (*)())std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux)(newStructure,memberFinish,&typeLineType)
          ;
        }
        else {
          finishCursor = 0;
          if (memberFinish != (undefined4 *)0x0) {
            *memberFinish = newFieldType;
            memberFinish[1] = typeLineLine;
            finishCursor = *(int *)(newStructure + 8);
          }
          *(int *)(newStructure + 8) = finishCursor + 8;
        }
      }
    }
    else {
      *(undefined4 *)(this + 8) = *(undefined4 *)(findResult[0] + 0x14);
    }
  }
  *(undefined4 *)(this + 0xc) = 0;
  srcFieldName = *(int *)(copyOf + 0xc);
  if (srcFieldName != 0) {
    *(undefined1 *)(*(int *)(srcFieldName + 4) + *(int *)(*(int *)(srcFieldName + 4) + -0xc)) = *DAT_a7b7ba80;
    srcChars = *(char **)(srcFieldName + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    stringAlloc = (void *)TPoolAllocator__allocate(poolAllocator,8);
    newString = (void *)0x0;
    if (stringAlloc != (void *)0x0) {
      fieldNameAllocSlot[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (stringAlloc,srcChars,(unsigned char *)fieldNameAllocSlot);
      newString = stringAlloc;
    }
    *(void **)(this + 0xc) = newString;
  }
  *(undefined4 *)(this + 0x10) = 0;
  srcTypeName = *(int *)(copyOf + 0x10);
  if (srcTypeName != 0) {
    *(undefined1 *)(*(int *)(srcTypeName + 4) + *(int *)(*(int *)(srcTypeName + 4) + -0xc)) = *DAT_a7b7ba80;
    srcChars = *(char **)(srcTypeName + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    stringAlloc = (void *)TPoolAllocator__allocate(poolAllocator,8);
    newString = (void *)0x0;
    if (stringAlloc != (void *)0x0) {
      typeNameAllocSlot[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (stringAlloc,srcChars,(unsigned char *)typeNameAllocSlot);
      newString = stringAlloc;
    }
    *(void **)(this + 0x10) = newString;
  }
  *(undefined4 *)(this + 0x14) = 0;
  srcMangled = *(int *)(copyOf + 0x14);
  if (srcMangled != 0) {
    *(undefined1 *)(*(int *)(srcMangled + 4) + *(int *)(*(int *)(srcMangled + 4) + -0xc)) = *DAT_a7b7ba80;
    srcChars = *(char **)(srcMangled + 4);
    poolAllocator = (unsigned char *)GetGlobalPoolAllocator();
    stringAlloc = (void *)TPoolAllocator__allocate(poolAllocator,8);
    newString = (void *)0x0;
    if (stringAlloc != (void *)0x0) {
      mangledAllocSlot[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (stringAlloc,srcChars,(unsigned char *)mangledAllocSlot);
      newString = stringAlloc;
    }
    *(void **)(this + 0x14) = newString;
  }
  srcWord1c = *(undefined4 *)(copyOf + 0x1c);
  srcStructureSize = *(undefined4 *)(copyOf + 0x18);
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x18) = srcStructureSize;
  *(undefined4 *)(this + 0x1c) = srcWord1c;
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
int std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_______find(this, tree, key)
  unsigned char ** this;
  undefined4 *tree;
  uint *key;
{
  unsigned char *node;
  unsigned char *nextNode;
  unsigned char *header;
  unsigned char *candidate;
  
  header = (unsigned char *)*tree;
  candidate = header;
  if (*(unsigned char **)(header + 4) != (unsigned char *)0x0) {
    node = *(unsigned char **)(header + 4);
    do {
      if (*(uint *)(node + 0x10) < *key) {
        nextNode = *(unsigned char **)(node + 0xc);
      }
      else {
        nextNode = *(unsigned char **)(node + 8);
        candidate = node;
      }
      node = nextNode;
    } while (nextNode != (unsigned char *)0x0);
  }
  if ((candidate != header) && (*(uint *)(candidate + 0x10) <= *key)) {
    *this = candidate;
    return;
  }
  *this = header;
  return;
}

/* std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux @ 0x97c346a0 (384 bytes) */
int std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux(this, position, typeLine)
  unsigned char * this;
  undefined4 *position;
  undefined4 *typeLine;
{
  int elemsToMove;
  undefined4 *finish;
  int allocation;
  int oldSize;
  int destroyCursor;
  int len;
  undefined4 xWord0;
  undefined4 movedWord;
  undefined4 *srcCursor;
  undefined4 xWord1;
  undefined4 *copyDest;
  undefined4 *newFinish [5];
  
  finish = *(undefined4 **)(this + 8);
  if (finish == *(undefined4 **)(this + 0xc)) {
    len = 1;
    oldSize = (int)finish - *(int *)(this + 4) >> 3;
    if (oldSize != 0) {
      len = oldSize << 1;
    }
    allocation = TPoolAllocator__allocate(*(unsigned char **)this,len * 8);
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine______gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine____)(newFinish,*(undefined4 *)(this + 4),position,allocation);
    if (newFinish[0] != (undefined4 *)0x0) {
      xWord0 = *typeLine;
      newFinish[0][1] = typeLine[1];
      *newFinish[0] = xWord0;
    }
    ((int (*)())std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine______gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine____)(newFinish,position,*(undefined4 *)(this + 8),newFinish[0] + 2);
    for (destroyCursor = *(int *)(this + 4); destroyCursor != *(int *)(this + 8); destroyCursor = destroyCursor + 8) {
    }
    *(undefined4 **)(this + 8) = newFinish[0];
    *(int *)(this + 0xc) = allocation + len * 8;
    *(int *)(this + 4) = allocation;
  }
  else {
    copyDest = (undefined4 *)0x0;
    if (finish != (undefined4 *)0x0) {
      finish[1] = finish[-1];
      *finish = finish[-2];
      copyDest = *(undefined4 **)(this + 8);
    }
    *(undefined4 **)(this + 8) = copyDest + 2;
    xWord1 = typeLine[1];
    elemsToMove = (int)(copyDest + -2) - (int)position >> 3;
    xWord0 = *typeLine;
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

/* std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine______gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine____ @ 0x97c34820 (92 bytes) */
int std____uninitialized_copy_aux___gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine______gnu_cxx____normal_iterator_TTypeLine__std__vector_TTypeLine_pool_allocator_TTypeLine____(resultSlot, first, last, result)
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

/* __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_ @ 0x97c3487c (64 bytes) */
int __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_(this, text1, text2)
  unsigned char * this;
  unsigned char * text1;
  unsigned char * text2;
{
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(this,text1);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendERKS3_(this,text2);
  return this;
}

/* std__vector_int_pool_allocator_int_____M_insert_aux @ 0x97c348bc (252 bytes) */
int std__vector_int_pool_allocator_int_____M_insert_aux(this, position, intValue)
  unsigned char * this;
  undefined4 *position;
  undefined4 *intValue;
{
  int finishCursor;
  int oldFinish;
  uint moveBytes;
  int oldSize;
  undefined4 *finish;
  int len;
  void *newStart;
  void *backStart;
  undefined4 xValue;
  size_t frontBytes;
  
  finish = *(undefined4 **)(this + 8);
  if (finish == *(undefined4 **)(this + 0xc)) {
    len = 1;
    oldSize = (int)finish - *(int *)(this + 4) >> 2;
    if (oldSize != 0) {
      len = oldSize << 1;
    }
    newStart = (void *)TPoolAllocator__allocate(*(unsigned char **)this,len * 4);
    frontBytes = (int)position - (int)*(void **)(this + 4);
    _memmove(newStart,*(void **)(this + 4),frontBytes);
    if ((int)newStart + frontBytes != 0) {
      *(undefined4 *)((int)newStart + frontBytes) = *intValue;
    }
    oldFinish = *(int *)(this + 8);
    backStart = (void *)((int)newStart + frontBytes + 4);
    _memmove(backStart,position,oldFinish - (int)position);
    *(void **)(this + 0xc) = (void *)((int)newStart + len * 4);
    *(int *)(this + 8) = (int)backStart + (oldFinish - (int)position);
    *(void **)(this + 4) = newStart;
  }
  else {
    finishCursor = 0;
    if (finish != (undefined4 *)0x0) {
      *finish = finish[-1];
      finishCursor = *(int *)(this + 8);
    }
    *(int *)(this + 8) = finishCursor + 4;
    moveBytes = (finishCursor + -4) - (int)position & 0xfffffffc;
    xValue = *intValue;
    _memmove((void *)(finishCursor - moveBytes),position,moveBytes);
    *position = xValue;
  }
  return;
}

/* std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____find @ 0x97c349b8 (288 bytes) */
int std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____find(this, tree, key)
  unsigned char * this;
  int tree;
  int key;
{
  uint candidateKeySize;
  uint finalKeySize;
  int nextNode;
  int finalCompareResult;
  int compareResult;
  int node;
  uint *minSizeRef;
  int header;
  void *keyChars;
  int candidate;
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
    if (-1 < finalCompareResult) {
      *(int *)this = candidate;
      return this;
    }
  }
  *(int *)this = header;
  return this;
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
  return __ZdlPv(this);
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
  return __ZdlPv(this);
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
int TCompiler__setOpimizationLevel(this)
  undefined4 this;
{
  return;
}

/* TCompiler__setDebugOptions @ 0x97c34c28 (4 bytes) */
int TCompiler__setDebugOptions(this)
  undefined4 this;
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
int TPPStreamCompiler__setOpimizationLevel(this, optimizationLevel)
  unsigned char * this;
  undefined4 optimizationLevel;
{
  *(undefined4 *)(this + 0xc4) = optimizationLevel;
  return;
}

/* TPPStreamCompiler__setDebugOptions @ 0x97c34c70 (8 bytes) */
int TPPStreamCompiler__setDebugOptions(this, debugOptions)
  unsigned char * this;
  undefined4 debugOptions;
{
  *(undefined4 *)(this + 0xc0) = debugOptions;
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
  return __ZNSt11logic_errorD2Ev(this);
}

/* __ZNSt16invalid_argumentD1Ev @ 0x97c34cc0 (64 bytes) */
int __ZNSt16invalid_argumentD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt16invalid_argumentD1Ev_a7b7dde8;
  return __ZNSt11logic_errorD2Ev(this);
}

/* __ZNSt12length_errorD1Ev @ 0x97c34d00 (64 bytes) */
int __ZNSt12length_errorD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt12length_errorD1Ev_a7b7ddd0;
  return __ZNSt11logic_errorD2Ev(this);
}

/* __ZNSt12out_of_rangeD1Ev @ 0x97c34d40 (64 bytes) */
int __ZNSt12out_of_rangeD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt12out_of_rangeD1Ev_a7b7ddb8;
  return __ZNSt11logic_errorD2Ev(this);
}

/* __ZNSt11range_errorD1Ev @ 0x97c34d80 (64 bytes) */
int __ZNSt11range_errorD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt11range_errorD1Ev_a7b7dda0;
  return __ZNSt13runtime_errorD2Ev(this);
}

/* __ZNSt14overflow_errorD1Ev @ 0x97c34dc0 (64 bytes) */
int __ZNSt14overflow_errorD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt14overflow_errorD1Ev_a7b7dd88;
  return __ZNSt13runtime_errorD2Ev(this);
}

/* __ZNSt15underflow_errorD1Ev @ 0x97c34e00 (64 bytes) */
int __ZNSt15underflow_errorD1Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt15underflow_errorD1Ev_a7b7dd70;
  return __ZNSt13runtime_errorD2Ev(this);
}

/* __ZNSt12domain_errorD0Ev @ 0x97c34e40 (76 bytes) */
int __ZNSt12domain_errorD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt12domain_errorD1Ev_a7b7de00;
  __ZNSt11logic_errorD2Ev(this);
  return __ZdlPv(this);
}

/* __ZNSt16invalid_argumentD0Ev @ 0x97c34e8c (76 bytes) */
int __ZNSt16invalid_argumentD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt16invalid_argumentD1Ev_a7b7dde8;
  __ZNSt11logic_errorD2Ev(this);
  return __ZdlPv(this);
}

/* __ZNSt12length_errorD0Ev @ 0x97c34ed8 (76 bytes) */
int __ZNSt12length_errorD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt12length_errorD1Ev_a7b7ddd0;
  __ZNSt11logic_errorD2Ev(this);
  return __ZdlPv(this);
}

/* __ZNSt12out_of_rangeD0Ev @ 0x97c34f24 (76 bytes) */
int __ZNSt12out_of_rangeD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt12out_of_rangeD1Ev_a7b7ddb8;
  __ZNSt11logic_errorD2Ev(this);
  return __ZdlPv(this);
}

/* __ZNSt11range_errorD0Ev @ 0x97c34f70 (76 bytes) */
int __ZNSt11range_errorD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt11range_errorD1Ev_a7b7dda0;
  __ZNSt13runtime_errorD2Ev(this);
  return __ZdlPv(this);
}

/* __ZNSt14overflow_errorD0Ev @ 0x97c34fbc (76 bytes) */
int __ZNSt14overflow_errorD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt14overflow_errorD1Ev_a7b7dd88;
  __ZNSt13runtime_errorD2Ev(this);
  return __ZdlPv(this);
}

/* __ZNSt15underflow_errorD0Ev @ 0x97c35008 (76 bytes) */
int __ZNSt15underflow_errorD0Ev(this)
  void *this;
{
  *(undefined ***)this = &PTR___ZNSt15underflow_errorD1Ev_a7b7dd70;
  __ZNSt13runtime_errorD2Ev(this);
  return __ZdlPv(this);
}

