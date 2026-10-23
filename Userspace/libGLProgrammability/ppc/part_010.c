#include "decls.h"

/* __ZN18TemporaryAllocatorC1Ev @ 0x97bb9e90 (4 bytes) */
int __ZN18TemporaryAllocatorC1Ev(this)
  void *this;
{
  return ((int (*)())__ZN18TemporaryAllocatorC4Ev)(this);
}

/* __ZN18TemporaryAllocatorC4Ev @ 0x97bb9e94 (32 bytes) */
int __ZN18TemporaryAllocatorC4Ev(this)
  void *this;
{
  int remaining;
  
  remaining = 0x19;
  do {
    *(undefined4 *)this = 0;
    *(undefined4 *)((int)this + 100) = 0;
    this = (void *)((int)this + 4);
    remaining = remaining + -1;
  } while (remaining != 0);
  return;
}

/* __ZN18TemporaryAllocatorD2Ev @ 0x97bb9eb4 (8 bytes) */
int __ZN18TemporaryAllocatorD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN18TemporaryAllocatorD4Ev)(this);
}

/* __ZN18TemporaryAllocatorD1Ev @ 0x97bb9ebc (8 bytes) */
int __ZN18TemporaryAllocatorD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN18TemporaryAllocatorD4Ev)(this);
}

/* __ZN18TemporaryAllocatorD4Ev @ 0x97bb9ec4 (72 bytes) */
int __ZN18TemporaryAllocatorD4Ev(this)
  void *this;
{
  int slotArray;
  int *lastSlot;
  
  lastSlot = (int *)((int)this + 0x60);
  do {
    slotArray = *(int *)this;
    this = (void *)((int)this + 4);
    if (slotArray != 0) {
      _free(slotArray);
    }
  } while (this <= lastSlot);
  return;
}

/* TemporaryAllocator__getTemporary @ 0x97bb9f0c (408 bytes) */
int TemporaryAllocator__getTemporary(this, glType)
  unsigned char * this;
  int glType;
{
  int classOffset;
  int byteOffset;
  int classIdx;
  int iVar3;
  int *slotPtr;
  uint newCapacity;
  int allocation;
  int copyIdx;
  int oldSlots;
  int slotOffset;
  uint loopIndex;
  
  loopIndex = 0;
  classIdx = 0;
  if ((glType != 0x1404) && (classIdx = 1, glType != 0x1406)) {
    if ((glType + 0x74b0U & 0xffff) < 0x15) {
      classIdx = glType + -0x8b4e;
    }
    else {
      classIdx = 0x17;
      if ((glType != 0x7ffe) && (classIdx = 0x18, glType != 0x7fff)) {
        return 0;
      }
    }
  }
  classOffset = classIdx * 4;
  slotOffset = 0;
  if (*(uint *)(this + classOffset + 100) != 0) {
    slotPtr = *(int **)(this + classOffset);
    iVar3 = *slotPtr;
    while (iVar3 != 0) {
      loopIndex = loopIndex + 1;
      slotOffset = loopIndex * 4;
      if (*(uint *)(this + classOffset + 100) <= loopIndex) break;
      slotPtr = slotPtr + 1;
      iVar3 = *slotPtr;
    }
  }
  if (*(uint *)(this + classOffset + 100) <= loopIndex) {
    allocation = _malloc(*(uint *)(this + classOffset + 100) * 4 + 0x40);
    iVar3 = *(int *)(this + classOffset + 100);
    copyIdx = 0;
    if (iVar3 != 0) {
      oldSlots = *(int *)(this + classOffset);
      do {
        byteOffset = copyIdx * 4;
        copyIdx = copyIdx + 1;
        *(undefined4 *)(byteOffset + allocation) = *(undefined4 *)(byteOffset + oldSlots);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    _memset(*(int *)(this + classOffset + 100) * 4 + allocation,0,0x40);
    if (*(int *)(this + classOffset) != 0) {
      _free(*(int *)(this + classOffset));
    }
    *(int *)(this + classOffset) = allocation;
    newCapacity = *(int *)(this + classOffset + 100) + 0x10;
    *(uint *)(this + classOffset + 100) = newCapacity;
    if (loopIndex < newCapacity) {
      iVar3 = *(int *)(slotOffset + allocation);
      while (iVar3 != 0) {
        loopIndex = loopIndex + 1;
        slotOffset = loopIndex * 4;
        if (newCapacity <= loopIndex) break;
        iVar3 = *(int *)(slotOffset + *(int *)(this + classOffset));
      }
    }
  }
  *(undefined4 *)(slotOffset + *(int *)(this + classOffset)) = 1;
  return loopIndex;
}

/* TemporaryAllocator__releaseTemporary @ 0x97bba0a4 (100 bytes) */
int TemporaryAllocator__releaseTemporary(this, glType, slotIdx)
  unsigned char * this;
  int glType;
  uint slotIdx;
{
  int classIdx;
  
  classIdx = 0;
  if ((glType != 0x1404) && (classIdx = 1, glType != 0x1406)) {
    if ((glType + 0x74b0U & 0xffff) < 0x15) {
      classIdx = glType + -0x8b4e;
    }
    else {
      classIdx = 0x17;
      if (glType != 0x7ffe) {
        if (glType != 0x7fff) {
          return;
        }
        classIdx = 0x18;
      }
    }
  }
  *(undefined4 *)(slotIdx * 4 + *(int *)(this + classIdx * 4)) = 0;
  return;
}

/* ParseSymbol__ClearName @ 0x97bba108 (72 bytes) */
int ParseSymbol__ClearName(this)
  unsigned char * this;
{
  if (*(int *)(this + 0x14) != 0) {
    _free(*(int *)(this + 0x14));
  }
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  return;
}

/* ParseSymbol__ClearDirectIndex @ 0x97bba150 (68 bytes) */
int ParseSymbol__ClearDirectIndex(this)
  unsigned char * this;
{
  if (*(int *)(this + 0x18) != 0) {
    _free(*(int *)(this + 0x18));
  }
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  return;
}

/* __ZN11ParseSymbolC2Ev @ 0x97bba194 (4 bytes) */
int __ZN11ParseSymbolC2Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined2 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x28) = 0xffffffff;
  *(undefined4 *)((int)this + 0x44) = 1;
  *(undefined2 *)((int)this + 0x30) = 0;
  *(undefined2 *)((int)this + 0x2e) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  return;
}

/* __ZN11ParseSymbolC1Ev @ 0x97bba198 (4 bytes) */
int __ZN11ParseSymbolC1Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined2 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x28) = 0xffffffff;
  *(undefined4 *)((int)this + 0x44) = 1;
  *(undefined2 *)((int)this + 0x30) = 0;
  *(undefined2 *)((int)this + 0x2e) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  return;
}

/* __ZN11ParseSymbolC4Ev @ 0x97bba19c (124 bytes) */
int __ZN11ParseSymbolC4Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined2 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x28) = 0xffffffff;
  *(undefined4 *)((int)this + 0x44) = 1;
  *(undefined2 *)((int)this + 0x30) = 0;
  *(undefined2 *)((int)this + 0x2e) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  return;
}

/* __ZN11ParseSymbolD2Ev @ 0x97bba218 (8 bytes) */
int __ZN11ParseSymbolD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN11ParseSymbolD4Ev)(this);
}

/* __ZN11ParseSymbolD1Ev @ 0x97bba220 (8 bytes) */
int __ZN11ParseSymbolD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN11ParseSymbolD4Ev)(this);
}

/* __ZN11ParseSymbolD4Ev @ 0x97bba228 (116 bytes) */
int __ZN11ParseSymbolD4Ev(this)
  void *this;
{
  if (*(int *)((int)this + 0x14) != 0) {
    _free(*(int *)((int)this + 0x14));
  }
  if (*(int *)((int)this + 0x18) != 0) {
    _free(*(int *)((int)this + 0x18));
  }
  if ((*(int *)((int)this + 0x44) != 0) && (*(int *)this != 0)) {
    _free(*(int *)this);
    return;
  }
  return;
}

/* __ZN11ParseSymbolC2ERKS_ @ 0x97bba29c (4 bytes) */
int __ZN11ParseSymbolC2ERKS_(this, parseSymbol)
  void *this;
  unsigned char * parseSymbol;
{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint directIndex;
  unsigned char * pTVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  
  uVar2 = *(undefined2 *)(parseSymbol + 0x2c);
  uVar11 = *(undefined4 *)(parseSymbol + 0x28);
  uVar14 = 0;
  uVar1 = *(undefined2 *)(parseSymbol + 0x2e);
  pTVar5 = *(unsigned char **)(parseSymbol + 0xc);
  *(undefined2 *)((int)this + 0x30) = *(undefined2 *)(parseSymbol + 0x30);
  *(undefined2 *)((int)this + 0x2c) = uVar2;
  *(undefined4 *)((int)this + 0x28) = uVar11;
  *(undefined4 *)((int)this + 0x44) = 1;
  *(undefined2 *)((int)this + 0x2e) = uVar1;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  ((int (*)())ParseSymbol__SetParseTreeType)(this,pTVar5);
  uVar11 = *(undefined4 *)(parseSymbol + 0x48);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(parseSymbol + 0x10);
  *(undefined4 *)((int)this + 0x48) = uVar11;
  ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
  uVar11 = *(undefined4 *)(parseSymbol + 0x34);
  uVar10 = *(undefined4 *)(parseSymbol + 0x38);
  uVar13 = *(undefined4 *)(parseSymbol + 0x3c);
  uVar12 = *(undefined4 *)(parseSymbol + 0x60);
  uVar9 = *(undefined4 *)(parseSymbol + 0x5c);
  uVar8 = *(undefined4 *)(parseSymbol + 0x58);
  uVar7 = *(undefined4 *)(parseSymbol + 0x40);
  pcVar6 = *(char **)(parseSymbol + 0x14);
  *(undefined4 *)((int)this + 0x4c) = *(undefined4 *)(parseSymbol + 0x4c);
  *(undefined4 *)((int)this + 0x34) = uVar11;
  *(undefined4 *)((int)this + 0x38) = uVar10;
  *(undefined4 *)((int)this + 0x3c) = uVar13;
  *(undefined4 *)((int)this + 0x60) = uVar12;
  *(undefined4 *)((int)this + 0x5c) = uVar9;
  *(undefined4 *)((int)this + 0x58) = uVar8;
  *(undefined4 *)((int)this + 0x40) = uVar7;
  ((int (*)())ParseSymbol__SetName)(this,pcVar6);
  *(undefined4 *)((int)this + 0x24) = 0;
  iVar3 = *(int *)(parseSymbol + 0x24);
  uVar11 = *(undefined4 *)(parseSymbol + 0x54);
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x54) = uVar11;
  if (iVar3 != 0) {
    do {
      directIndex = ((int (*)())ParseSymbol__GetDirectIndex)(parseSymbol,uVar14);
      uVar14 = uVar14 + 1;
      ((int (*)())ParseSymbol__AddDirectIndex)(this,directIndex);
    } while (uVar14 < *(uint *)(parseSymbol + 0x24));
  }
  return;
}

/* __ZN11ParseSymbolC1ERKS_ @ 0x97bba2a0 (4 bytes) */
int __ZN11ParseSymbolC1ERKS_(this, parseSymbol)
  void *this;
  unsigned char * parseSymbol;
{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint directIndex;
  unsigned char * pTVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  
  uVar2 = *(undefined2 *)(parseSymbol + 0x2c);
  uVar11 = *(undefined4 *)(parseSymbol + 0x28);
  uVar14 = 0;
  uVar1 = *(undefined2 *)(parseSymbol + 0x2e);
  pTVar5 = *(unsigned char **)(parseSymbol + 0xc);
  *(undefined2 *)((int)this + 0x30) = *(undefined2 *)(parseSymbol + 0x30);
  *(undefined2 *)((int)this + 0x2c) = uVar2;
  *(undefined4 *)((int)this + 0x28) = uVar11;
  *(undefined4 *)((int)this + 0x44) = 1;
  *(undefined2 *)((int)this + 0x2e) = uVar1;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  ((int (*)())ParseSymbol__SetParseTreeType)(this,pTVar5);
  uVar11 = *(undefined4 *)(parseSymbol + 0x48);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(parseSymbol + 0x10);
  *(undefined4 *)((int)this + 0x48) = uVar11;
  ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
  uVar11 = *(undefined4 *)(parseSymbol + 0x34);
  uVar10 = *(undefined4 *)(parseSymbol + 0x38);
  uVar13 = *(undefined4 *)(parseSymbol + 0x3c);
  uVar12 = *(undefined4 *)(parseSymbol + 0x60);
  uVar9 = *(undefined4 *)(parseSymbol + 0x5c);
  uVar8 = *(undefined4 *)(parseSymbol + 0x58);
  uVar7 = *(undefined4 *)(parseSymbol + 0x40);
  pcVar6 = *(char **)(parseSymbol + 0x14);
  *(undefined4 *)((int)this + 0x4c) = *(undefined4 *)(parseSymbol + 0x4c);
  *(undefined4 *)((int)this + 0x34) = uVar11;
  *(undefined4 *)((int)this + 0x38) = uVar10;
  *(undefined4 *)((int)this + 0x3c) = uVar13;
  *(undefined4 *)((int)this + 0x60) = uVar12;
  *(undefined4 *)((int)this + 0x5c) = uVar9;
  *(undefined4 *)((int)this + 0x58) = uVar8;
  *(undefined4 *)((int)this + 0x40) = uVar7;
  ((int (*)())ParseSymbol__SetName)(this,pcVar6);
  *(undefined4 *)((int)this + 0x24) = 0;
  iVar3 = *(int *)(parseSymbol + 0x24);
  uVar11 = *(undefined4 *)(parseSymbol + 0x54);
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x54) = uVar11;
  if (iVar3 != 0) {
    do {
      directIndex = ((int (*)())ParseSymbol__GetDirectIndex)(parseSymbol,uVar14);
      uVar14 = uVar14 + 1;
      ((int (*)())ParseSymbol__AddDirectIndex)(this,directIndex);
    } while (uVar14 < *(uint *)(parseSymbol + 0x24));
  }
  return;
}

/* __ZN11ParseSymbolC4ERKS_ @ 0x97bba2a4 (296 bytes) */
int __ZN11ParseSymbolC4ERKS_(this, parseSymbol)
  void *this;
  unsigned char * parseSymbol;
{
  undefined2 arraySize;
  undefined2 openGLType;
  int directIndexCount;
  uint directIndex;
  unsigned char * parseTreeType;
  char *name;
  undefined4 field40;
  undefined4 field58;
  undefined4 field5c;
  undefined4 field38;
  undefined4 uVar11;
  undefined4 field60;
  undefined4 field3c;
  uint loopIdx;
  
  openGLType = *(undefined2 *)(parseSymbol + 0x2c);
  uVar11 = *(undefined4 *)(parseSymbol + 0x28);
  loopIdx = 0;
  arraySize = *(undefined2 *)(parseSymbol + 0x2e);
  parseTreeType = *(unsigned char **)(parseSymbol + 0xc);
  *(undefined2 *)((int)this + 0x30) = *(undefined2 *)(parseSymbol + 0x30);
  *(undefined2 *)((int)this + 0x2c) = openGLType;
  *(undefined4 *)((int)this + 0x28) = uVar11;
  *(undefined4 *)((int)this + 0x44) = 1;
  *(undefined2 *)((int)this + 0x2e) = arraySize;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  ((int (*)())ParseSymbol__SetParseTreeType)(this,parseTreeType);
  uVar11 = *(undefined4 *)(parseSymbol + 0x48);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(parseSymbol + 0x10);
  *(undefined4 *)((int)this + 0x48) = uVar11;
  ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
  uVar11 = *(undefined4 *)(parseSymbol + 0x34);
  field38 = *(undefined4 *)(parseSymbol + 0x38);
  field3c = *(undefined4 *)(parseSymbol + 0x3c);
  field60 = *(undefined4 *)(parseSymbol + 0x60);
  field5c = *(undefined4 *)(parseSymbol + 0x5c);
  field58 = *(undefined4 *)(parseSymbol + 0x58);
  field40 = *(undefined4 *)(parseSymbol + 0x40);
  name = *(char **)(parseSymbol + 0x14);
  *(undefined4 *)((int)this + 0x4c) = *(undefined4 *)(parseSymbol + 0x4c);
  *(undefined4 *)((int)this + 0x34) = uVar11;
  *(undefined4 *)((int)this + 0x38) = field38;
  *(undefined4 *)((int)this + 0x3c) = field3c;
  *(undefined4 *)((int)this + 0x60) = field60;
  *(undefined4 *)((int)this + 0x5c) = field5c;
  *(undefined4 *)((int)this + 0x58) = field58;
  *(undefined4 *)((int)this + 0x40) = field40;
  ((int (*)())ParseSymbol__SetName)(this,name);
  *(undefined4 *)((int)this + 0x24) = 0;
  directIndexCount = *(int *)(parseSymbol + 0x24);
  uVar11 = *(undefined4 *)(parseSymbol + 0x54);
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x54) = uVar11;
  if (directIndexCount != 0) {
    do {
      directIndex = ((int (*)())ParseSymbol__GetDirectIndex)(parseSymbol,loopIdx);
      loopIdx = loopIdx + 1;
      ((int (*)())ParseSymbol__AddDirectIndex)(this,directIndex);
    } while (loopIdx < *(uint *)(parseSymbol + 0x24));
  }
  return;
}

/* ParseSymbol__operator_ @ 0x97bba3cc (328 bytes) */
int ParseSymbol__operator_(this, parseSymbol)
  unsigned char * this;
  unsigned char * parseSymbol;
{
  undefined2 field30;
  undefined2 openGLType;
  undefined4 uVar3;
  uint directIndex;
  char *name;
  unsigned char * parseTreeType;
  undefined4 field40;
  undefined4 field58;
  undefined4 field5c;
  undefined4 field60;
  undefined4 field34;
  undefined4 field3c;
  undefined4 field38;
  uint loopIdx;
  
  if (this != parseSymbol) {
    field30 = *(undefined2 *)(parseSymbol + 0x30);
    openGLType = *(undefined2 *)(parseSymbol + 0x2c);
    name = *(char **)(parseSymbol + 0x14);
    *(undefined2 *)(this + 0x2e) = *(undefined2 *)(parseSymbol + 0x2e);
    *(undefined2 *)(this + 0x30) = field30;
    *(undefined2 *)(this + 0x2c) = openGLType;
    SetName(this,name);
    ClearDirectIndex(this);
    loopIdx = 0;
    if (*(int *)(parseSymbol + 0x24) != 0) {
      do {
        directIndex = GetDirectIndex(parseSymbol,loopIdx);
        AddDirectIndex(this,directIndex);
        loopIdx = loopIdx + 1;
      } while (loopIdx < *(uint *)(parseSymbol + 0x24));
    }
    parseTreeType = *(unsigned char **)(parseSymbol + 0xc);
    *(undefined4 *)(this + 0x28) = *(undefined4 *)(parseSymbol + 0x28);
    ((int (*)())ParseSymbol__SetParseTreeType)(this,parseTreeType);
    uVar3 = *(undefined4 *)(parseSymbol + 0x48);
    *(undefined4 *)(this + 0x10) = *(undefined4 *)(parseSymbol + 0x10);
    *(undefined4 *)(this + 0x48) = uVar3;
    ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
    uVar3 = *(undefined4 *)(parseSymbol + 0x54);
    field34 = *(undefined4 *)(parseSymbol + 0x34);
    field38 = *(undefined4 *)(parseSymbol + 0x38);
    field3c = *(undefined4 *)(parseSymbol + 0x3c);
    field60 = *(undefined4 *)(parseSymbol + 0x60);
    field5c = *(undefined4 *)(parseSymbol + 0x5c);
    field58 = *(undefined4 *)(parseSymbol + 0x58);
    field40 = *(undefined4 *)(parseSymbol + 0x40);
    *(undefined4 *)(this + 0x4c) = *(undefined4 *)(parseSymbol + 0x4c);
    *(undefined4 *)(this + 0x34) = field34;
    *(undefined4 *)(this + 0x38) = field38;
    *(undefined4 *)(this + 0x3c) = field3c;
    *(undefined4 *)(this + 0x60) = field60;
    *(undefined4 *)(this + 0x5c) = field5c;
    *(undefined4 *)(this + 0x58) = field58;
    *(undefined4 *)(this + 0x40) = field40;
    *(undefined4 *)(this + 0x54) = uVar3;
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 0x50) = 0;
    *(undefined4 *)(this + 4) = 0;
    if ((*(int *)this != 0) && (*(int *)(this + 0x44) != 0)) {
      _free(*(int *)this);
    }
    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 0x44) = 1;
  }
  return this;
}

/* __ZeqRK11ParseSymbolS1_ @ 0x97bba514 (148 bytes) */
int __ZeqRK11ParseSymbolS1_(parseSymbol1, parseSymbol2)
  unsigned char * parseSymbol1;
  unsigned char * parseSymbol2;
{
  int nameCmp;
  undefined4 equal;
  
  equal = 0;
  if ((((*(int *)(parseSymbol1 + 0x28) == -1) || (*(int *)(parseSymbol2 + 0x28) == -1)) ||
      ((*(int *)(parseSymbol1 + 0x28) == *(int *)(parseSymbol2 + 0x28) &&
       (*(int *)(parseSymbol1 + 0x48) == *(int *)(parseSymbol2 + 0x48))))) &&
     (((*(int *)(parseSymbol1 + 0x1c) == *(int *)(parseSymbol2 + 0x1c) &&
       (*(int *)(parseSymbol1 + 0x20) == *(int *)(parseSymbol2 + 0x20))) &&
      (nameCmp = _strncmp(*(undefined4 *)(parseSymbol1 + 0x14),*(undefined4 *)(parseSymbol2 + 0x14),
                        *(int *)(parseSymbol1 + 0x20)), nameCmp == 0)))) {
    equal = 1;
  }
  return equal;
}

/* ParseSymbol__ResolveOpenGLType @ 0x97bba5a8 (616 bytes) */
int ParseSymbol__ResolveOpenGLType(this)
  unsigned char * this;
{
  bool sizeIsFour;
  undefined2 glType;
  int *parseTreeType;
  int iVar3;
  uint basicType;
  undefined4 a1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int isArrayOfStruct;
  
  parseTreeType = *(int **)(this + 0xc);
  if (parseTreeType == (int *)0x0) {
    return;
  }
  isArrayOfStruct = 0;
  iVar3 = (**(code **)(*parseTreeType + 0x38))(parseTreeType);
  if ((iVar3 != 0) && (*(int *)(this + 0x48) == 0)) {
    isArrayOfStruct = 1;
  }
  glType = 0x7fff;
  *(int *)(this + 0x4c) = isArrayOfStruct;
  if (isArrayOfStruct == 0) {
    basicType = (**(code **)(**(int **)(this + 0xc) + 0x20))(*(int **)(this + 0xc));
    if (0xf < basicType) {
      return;
    }
    switch(basicType) {
    default:
      goto switchD_97bba640_caseD_0;
    case 1:
      iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x34))
                        (*(int **)(this + 0xc),a1,in_r5,in_r6,in_r7,in_r8,basicType * 4);
      if (iVar3 == 0) {
        iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x2c))(*(int **)(this + 0xc));
        if (iVar3 == 2) {
          glType = 0x8b50;
        }
        else if (iVar3 < 3) {
          if (iVar3 != 1) {
            return;
          }
          glType = 0x1406;
        }
        else {
          if (iVar3 != 3) {
            sizeIsFour = iVar3 == 4;
            glType = 0x8b52;
            goto LAB_97bba7d4;
          }
          glType = 0x8b51;
        }
      }
      else {
        iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x2c))(*(int **)(this + 0xc));
        if (iVar3 == 3) {
          glType = 0x8b5b;
        }
        else if (iVar3 < 4) {
          if (iVar3 != 2) {
            return;
          }
          glType = 0x8b5a;
        }
        else {
          sizeIsFour = iVar3 == 4;
          glType = 0x8b5c;
LAB_97bba7d4:
          if (!sizeIsFour) {
            return;
          }
        }
      }
      break;
    case 2:
      iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x2c))(*(int **)(this + 0xc));
      if (iVar3 == 2) {
        glType = 0x8b53;
      }
      else if (iVar3 < 3) {
        if (iVar3 != 1) {
          return;
        }
        glType = 0x1404;
      }
      else {
        if (iVar3 != 3) {
          sizeIsFour = iVar3 == 4;
          glType = 0x8b55;
          goto LAB_97bba7d4;
        }
        glType = 0x8b54;
      }
      break;
    case 3:
      iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x2c))(*(int **)(this + 0xc));
      if (iVar3 == 2) {
        glType = 0x8b57;
      }
      else if (iVar3 < 3) {
        if (iVar3 != 1) {
          return;
        }
        glType = 0x8b56;
      }
      else {
        if (iVar3 != 3) {
          sizeIsFour = iVar3 == 4;
          glType = 0x8b59;
          goto LAB_97bba7d4;
        }
        glType = 0x8b58;
      }
      break;
    case 5:
      glType = 0x8b5d;
      break;
    case 6:
      glType = 0x8b5e;
      break;
    case 7:
      glType = 0x8b5f;
      break;
    case 8:
      glType = 0x8b60;
      break;
    case 9:
      glType = 0x8b61;
      break;
    case 10:
      glType = 0x8b62;
      break;
    case 0xb:
      glType = 0x8b63;
      break;
    case 0xc:
      glType = 0x8b64;
      break;
    case 0xe:
      glType = 0x7ffe;
    }
  }
  *(undefined2 *)(this + 0x2c) = glType;
switchD_97bba640_caseD_0:
  return;
}

/* ParseSymbol__SetParseTreeType @ 0x97bba850 (120 bytes) */
int ParseSymbol__SetParseTreeType(this, type)
  unsigned char * this;
  unsigned char * type;
{
  undefined2 arraySize;
  int typeIsArray;
  
  *(unsigned char **)(this + 0xc) = type;
  if (type != (unsigned char *)0x0) {
    typeIsArray = (**(code **)(*(int *)type + 0x38))(type);
    arraySize = 1;
    if (typeIsArray != 0) {
      arraySize = *(undefined2 *)(type + 6);
    }
    *(undefined2 *)(this + 0x2e) = arraySize;
    ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
    return;
  }
  return;
}

/* ParseSymbol__SetChunk @ 0x97bba8c8 (84 bytes) */
int ParseSymbol__SetChunk(this, _PPStreamChunk)
  unsigned char * this;
  unsigned char * _PPStreamChunk;
{
  if ((*(int *)this != 0) && (*(int *)(this + 0x44) != 0)) {
    _free(*(int *)this);
  }
  *(unsigned char **)this = _PPStreamChunk;
  *(undefined4 *)(this + 0x44) = 1;
  return;
}

/* ParseSymbol__SetArrayPositionFromLastIndex @ 0x97bba91c (56 bytes) */
int ParseSymbol__SetArrayPositionFromLastIndex(this)
  unsigned char * this;
{
  undefined2 directIndex;
  
  directIndex = GetDirectIndex(this,*(int *)(this + 0x24) - 1);
  *(undefined2 *)(this + 0x30) = directIndex;
  return;
}

/* ParseSymbol__CatName @ 0x97bba954 (208 bytes) */
int ParseSymbol__CatName(this, str)
  unsigned char * this;
  char *str;
{
  int length;
  char *chPtr;
  int hashSum;
  int nameLen;
  char *allocation;
  int charIdx;
  
  if (str != (char *)0x0) {
    length = _strlen(str);
    allocation = (char *)_malloc(length + *(int *)(this + 0x20) + 1);
    if (*(char **)(this + 0x14) != (char *)0x0) {
      _strncpy(allocation,*(char **)(this + 0x14),*(int *)(this + 0x20) + 1);
    }
    _strncpy(allocation + *(int *)(this + 0x20),str,length + 1);
    *(int *)(this + 0x20) = *(int *)(this + 0x20) + length;
    _free(*(undefined4 *)(this + 0x14));
    nameLen = *(int *)(this + 0x20);
    charIdx = 0;
    *(undefined4 *)(this + 0x1c) = 0;
    *(char **)(this + 0x14) = allocation;
    if (nameLen != 0) {
      hashSum = 0;
      do {
        chPtr = allocation + charIdx;
        charIdx = charIdx + 1;
        hashSum = hashSum + *chPtr;
        nameLen = nameLen + -1;
      } while (nameLen != 0);
      *(int *)(this + 0x1c) = hashSum;
    }
  }
  return;
}

/* ParseSymbol__SetName @ 0x97bbaa24 (156 bytes) */
int ParseSymbol__SetName(this, str)
  unsigned char * this;
  char *str;
{
  char *allocation;
  int nameLen;
  char *chPtr;
  int charIdx;
  
  ClearName(this);
  if ((str != (char *)0x0) && (nameLen = _strlen(str), 0 < nameLen)) {
    *(int *)(this + 0x20) = nameLen;
    allocation = (char *)_malloc(nameLen + 1);
    *(char **)(this + 0x14) = allocation;
    _strncpy(allocation,str,*(int *)(this + 0x20) + 1);
    nameLen = *(int *)(this + 0x20);
    charIdx = 0;
    if (nameLen != 0) {
      do {
        chPtr = (char *)(*(int *)(this + 0x14) + charIdx);
        charIdx = charIdx + 1;
        *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + (int)*chPtr;
        nameLen = nameLen + -1;
      } while (nameLen != 0);
    }
  }
  return;
}

/* ParseSymbol__RemoveNameBackToChar @ 0x97bbaac0 (132 bytes) */
int ParseSymbol__RemoveNameBackToChar(this, stopChar)
  unsigned char * this;
  int stopChar;
{
  char *chPtr;
  bool found;
  int iVar3;
  int charIdx;
  
  iVar3 = *(int *)(this + 0x20);
  found = false;
  if (-1 < iVar3) {
    do {
      if (*(char *)(*(int *)(this + 0x14) + iVar3) == stopChar) {
        found = true;
      }
      *(undefined1 *)(*(int *)(this + 0x14) + iVar3) = 0;
      iVar3 = iVar3 + -1;
    } while ((-1 < iVar3) && (!found));
  }
  iVar3 = iVar3 + 1;
  charIdx = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(int *)(this + 0x20) = iVar3;
  if (0 < iVar3) {
    do {
      chPtr = (char *)(*(int *)(this + 0x14) + charIdx);
      charIdx = charIdx + 1;
      *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + (int)*chPtr;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    return;
  }
  return;
}

/* ParseSymbol__ChangeArrayNameForArrayIndex @ 0x97bbab44 (424 bytes) */
int ParseSymbol__ChangeArrayNameForArrayIndex(this, bracketLevel, newIndex)
  uint this;
  uint bracketLevel;
  int newIndex;
{
  int copyIndex;
  int length;
  char ch;
  uint loopIndex;
  int hashIdx;
  int allocation;
  int oldNameToFree;
  char *pcVar6;
  int oldName;
  int outPos;
  char indexText [28];
  
  _sprintf(indexText,"%u",newIndex);
  length = _strlen(indexText);
  outPos = 0;
  allocation = _malloc(*(int *)(this + 0x20) + length + 1);
  loopIndex = 0;
  copyIndex = 0;
  if (bracketLevel != 0xffffffff) {
    pcVar6 = *(char **)(this + 0x14);
    ch = *pcVar6;
    while (ch != '\0') {
      if (ch == '[') {
        loopIndex = loopIndex + 1;
      }
      *(char *)(allocation + outPos) = ch;
      copyIndex = copyIndex + 1;
      outPos = outPos + 1;
      if (bracketLevel + 1 <= loopIndex) break;
      ch = pcVar6[copyIndex];
    }
  }
  *(undefined1 *)(allocation + outPos) = 0;
  _strcat(allocation,indexText);
  ch = *(char *)(allocation + outPos);
  while (ch != '\0') {
    outPos = outPos + 1;
    ch = *(char *)(allocation + outPos);
  }
  oldName = *(int *)(this + 0x14);
  ch = *(char *)(oldName + copyIndex);
  while ((ch != '\0' && (ch != ']'))) {
    copyIndex = copyIndex + 1;
    ch = *(char *)(oldName + copyIndex);
  }
  ch = *(char *)(oldName + copyIndex);
  while (ch != '\0') {
    *(char *)(allocation + outPos) = ch;
    copyIndex = copyIndex + 1;
    outPos = outPos + 1;
    ch = *(char *)(oldName + copyIndex);
  }
  oldNameToFree = *(int *)(this + 0x14);
  *(undefined1 *)(allocation + outPos) = *(undefined1 *)(oldName + copyIndex);
  if (oldNameToFree != 0) {
    _free(oldNameToFree);
  }
  *(int *)(this + 0x20) = outPos;
  hashIdx = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(int *)(this + 0x14) = allocation;
  for (; outPos != 0; outPos = outPos + -1) {
    pcVar6 = (char *)(allocation + hashIdx);
    hashIdx = hashIdx + 1;
    *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + (int)*pcVar6;
  }
  return;
}

/* ParseSymbol__RemoveArrayIndex @ 0x97bbacec (36 bytes) */
int ParseSymbol__RemoveArrayIndex(this)
  unsigned char * this;
{
  if (*(char *)(*(int *)(this + 0x14) + *(int *)(this + 0x20) + -1) != ']') {
    return;
  }
  return RemoveNameBackToChar(this,0x5b);
}

/* ParseSymbol__TrimNameToBase @ 0x97bbad10 (156 bytes) */
int ParseSymbol__TrimNameToBase(this)
  unsigned char * this;
{
  char ch;
  char *name;
  int nameLen;
  int hashIdx;
  
  name = *(char **)(this + 0x14);
  nameLen = 0;
  ch = *name;
  if ((ch != '\0') && (ch != '[')) {
    while (ch != '.') {
      nameLen = nameLen + 1;
      ch = name[nameLen];
      if ((ch == '\0') || (ch == '[')) break;
    }
  }
  name[nameLen] = '\0';
  *(int *)(this + 0x20) = nameLen;
  hashIdx = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  if (nameLen < 1) {
    return;
  }
  do {
    name = (char *)(*(int *)(this + 0x14) + hashIdx);
    hashIdx = hashIdx + 1;
    *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + (int)*name;
    nameLen = nameLen + -1;
  } while (nameLen != 0);
  return;
}

/* ParseSymbol__AddDirectIndex @ 0x97bbadac (196 bytes) */
int ParseSymbol__AddDirectIndex(this, directIndex)
  unsigned char * this;
  uint directIndex;
{
  int byteOffset;
  uint count;
  int allocation;
  int oldArray;
  uint loopIndex;
  
  count = *(uint *)(this + 0x24);
  if ((count & 3) == 0) {
    allocation = _malloc(count * 4 + 0x10);
    _memset(allocation,0,*(int *)(this + 0x24) * 4 + 0x10);
    count = *(uint *)(this + 0x24);
    loopIndex = 0;
    if (count == 0) {
      oldArray = *(int *)(this + 0x18);
    }
    else {
      oldArray = *(int *)(this + 0x18);
      do {
        byteOffset = loopIndex * 4;
        loopIndex = loopIndex + 1;
        *(undefined4 *)(byteOffset + allocation) = *(undefined4 *)(byteOffset + oldArray);
      } while (loopIndex < count);
    }
    if (oldArray != 0) {
      _free(oldArray);
      count = *(uint *)(this + 0x24);
    }
    *(int *)(this + 0x18) = allocation;
  }
  *(uint *)(count * 4 + *(int *)(this + 0x18)) = directIndex;
  *(int *)(this + 0x24) = *(int *)(this + 0x24) + 1;
  return;
}

/* ParseSymbol__PopDirectIndex @ 0x97bbae70 (64 bytes) */
int ParseSymbol__PopDirectIndex(this)
  unsigned char * this;
{
  int iVar1;
  uint loopIndex;
  
  iVar1 = *(int *)(this + 0x24);
  loopIndex = 0;
  *(int *)(this + 0x24) = iVar1 + -1;
  if (iVar1 + -1 != 0) {
    do {
      iVar1 = loopIndex * 4;
      loopIndex = loopIndex + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 0x18)) =
           *(undefined4 *)(iVar1 + *(int *)(this + 0x18) + 4);
    } while (loopIndex < *(uint *)(this + 0x24));
    return;
  }
  return;
}

/* ParseSymbol__RemoveDirectIndex @ 0x97bbaeb0 (16 bytes) */
int ParseSymbol__RemoveDirectIndex(this)
  unsigned char * this;
{
  *(int *)(this + 0x24) = *(int *)(this + 0x24) + -1;
  return;
}

/* ParseSymbol__GetDirectIndex @ 0x97bbaec0 (16 bytes) */
int ParseSymbol__GetDirectIndex(this, index)
  unsigned char * this;
  uint index;
{
  return *(undefined4 *)(index * 4 + *(int *)(this + 0x18));
}

/* ParseSymbol__GetString @ 0x97bbaed0 (724 bytes) */
int ParseSymbol__GetString(this, verbose)
  unsigned char * this;
  int verbose;
{
  undefined4 directIndex;
  char *allocation;
  byte chunkKind;
  char *result;
  undefined4 gLStringForType;
  char *format;
  byte *chunk;
  int chunkText;
  uint loopIndex;
  
  chunkText = 0;
  result = (char *)_malloc(*(int *)(this + 0x20) + 0x200);
  if (result == (char *)0x0) {
    return (char *)0x0;
  }
  *result = '\0';
  chunk = *(byte **)this;
  if (chunk == (byte *)0x0) {
LAB_97bbb054:
    if (chunkText != 0) {
      _sprintf(result,DAT_a7b7bbbc,result,chunkText,*(undefined4 *)(this + 0x14),*(undefined4 *)(this + 0x28));
      _free(chunkText);
      goto LAB_97bbb0a4;
    }
  }
  else {
    chunkKind = *chunk;
    if (chunkKind == 2) {
      if (verbose != 0) {
        _sprintf(result,_symbolUtilString);
        chunk = *(byte **)this;
      }
      chunkText = PrintAttribute(*(undefined4 *)(chunk + 0xc),*(undefined4 *)(chunk + 0x10));
      goto LAB_97bbb054;
    }
    if (2 < chunkKind) {
      if (chunkKind == 3) {
        if (verbose != 0) {
          _sprintf(result,DAT_a7b7bba8);
          chunk = *(byte **)this;
        }
        chunkText = PrintParam(*(undefined4 *)(chunk + 0xc),*(undefined4 *)(chunk + 0x10));
      }
      else {
        if (chunkKind != 4) goto LAB_97bbb038;
        if (verbose != 0) {
          _sprintf(result,DAT_a7b7bbac);
          chunk = *(byte **)this;
        }
        chunkText = PrintOutput(*(undefined4 *)(chunk + 0xc),*(undefined4 *)(chunk + 0x10));
      }
      goto LAB_97bbb054;
    }
    if (chunkKind != 0) {
LAB_97bbb038:
      chunkText = _malloc(0x20);
      _strcpy(chunkText,DAT_a7b7bbb8);
      goto LAB_97bbb054;
    }
    format = DAT_a7b7bbb4;
    if (verbose != 0) {
      format = DAT_a7b7bbb0;
    }
    _sprintf(result,format,(uint)*(ushort *)(chunk + 0x12));
  }
  _sprintf(result,DAT_a7b7bbc0,result,*(undefined4 *)(this + 0x14),*(undefined4 *)(this + 0x28));
LAB_97bbb0a4:
  gLStringForType = GetGLStringForType((uint)*(ushort *)(this + 0x2c));
  _sprintf(result,DAT_a7b7bbc4,result,gLStringForType);
  if (1 < *(short *)(this + 0x2e)) {
    _sprintf(result,DAT_a7b7bbc8,(int)result,(int)*(short *)(this + 0x30),(int)*(short *)(this + 0x2e));
  }
  allocation = (char *)_malloc(0x40);
  *allocation = '\0';
  loopIndex = 0;
  if (*(int *)(this + 0x24) != 0) {
    do {
      if (loopIndex == 0) {
        _sprintf(allocation,DAT_a7b7bbd0);
      }
      else {
        _sprintf(allocation,DAT_a7b7bbcc,allocation);
      }
      directIndex = GetDirectIndex(this,loopIndex);
      _sprintf(allocation,DAT_a7b7bbd4,allocation,directIndex);
      loopIndex = loopIndex + 1;
    } while (loopIndex < *(uint *)(this + 0x24));
  }
  _sprintf(result,DAT_a7b7bbd8,result,allocation);
  _free(allocation);
  return result;
}

/* ParseOperand__ClearDirectIndex @ 0x97bbb1a4 (68 bytes) */
int ParseOperand__ClearDirectIndex(this)
  unsigned char * this;
{
  if (*(int *)(this + 0x1c) != 0) {
    _free(*(int *)(this + 0x1c));
  }
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  return;
}

/* __ZN12ParseOperandC2Ev @ 0x97bbb1e8 (4 bytes) */
int __ZN12ParseOperandC2Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined2 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  return;
}

/* __ZN12ParseOperandC1Ev @ 0x97bbb1ec (4 bytes) */
int __ZN12ParseOperandC1Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined2 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  return;
}

/* __ZN12ParseOperandC4Ev @ 0x97bbb1f0 (56 bytes) */
int __ZN12ParseOperandC4Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined2 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  return;
}

/* __ZN12ParseOperandC2ERKS_ @ 0x97bbb228 (4 bytes) */
int __ZN12ParseOperandC2ERKS_(this, parseOperand)
  void *this;
  unsigned char * parseOperand;
{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint directIndex;
  uchar swizzle;
  undefined4 uVar6;
  uint loopIndex;
  
  loopIndex = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  iVar2 = *(int *)(parseOperand + 0x20);
  uVar1 = *(undefined2 *)(parseOperand + 0x18);
  uVar3 = *(undefined4 *)(parseOperand + 4);
  uVar6 = *(undefined4 *)(parseOperand + 0x24);
  *(undefined4 *)this = *(undefined4 *)parseOperand;
  *(undefined4 *)((int)this + 4) = uVar3;
  *(undefined2 *)((int)this + 0x18) = uVar1;
  *(undefined4 *)((int)this + 0x24) = uVar6;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  if (iVar2 != 0) {
    do {
      directIndex = ((int (*)())ParseOperand__GetDirectIndex)(parseOperand,loopIndex);
      ((int (*)())ParseOperand__AddDirectIndex)(this,directIndex);
      loopIndex = loopIndex + 1;
    } while (loopIndex < *(uint *)(parseOperand + 0x20));
  }
  loopIndex = 0;
  if (*(int *)(parseOperand + 0x14) != 0) {
    do {
      swizzle = ParseOperand__GetSwizzle(parseOperand,loopIndex);
      ((int (*)())ParseOperand__AddSwizzle)(this,swizzle);
      loopIndex = loopIndex + 1;
    } while (loopIndex < *(uint *)(parseOperand + 0x14));
  }
  uVar3 = *(undefined4 *)(parseOperand + 0x28);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(parseOperand + 0x2c);
  *(undefined4 *)((int)this + 0x28) = uVar3;
  return;
}

/* __ZN12ParseOperandC1ERKS_ @ 0x97bbb22c (4 bytes) */
int __ZN12ParseOperandC1ERKS_(this, parseOperand)
  void *this;
  unsigned char * parseOperand;
{
  return ((int (*)())__ZN12ParseOperandC4ERKS_)(this,parseOperand);
}

/* __ZN12ParseOperandC4ERKS_ @ 0x97bbb230 (232 bytes) */
int __ZN12ParseOperandC4ERKS_(this, parseOperand)
  void *this;
  unsigned char * parseOperand;
{
  undefined2 field18;
  int directIndexCount;
  undefined4 uVar3;
  uint directIndex;
  uchar swizzle;
  undefined4 field24;
  uint loopIndex;
  
  loopIndex = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  directIndexCount = *(int *)(parseOperand + 0x20);
  field18 = *(undefined2 *)(parseOperand + 0x18);
  uVar3 = *(undefined4 *)(parseOperand + 4);
  field24 = *(undefined4 *)(parseOperand + 0x24);
  *(undefined4 *)this = *(undefined4 *)parseOperand;
  *(undefined4 *)((int)this + 4) = uVar3;
  *(undefined2 *)((int)this + 0x18) = field18;
  *(undefined4 *)((int)this + 0x24) = field24;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  if (directIndexCount != 0) {
    do {
      directIndex = ((int (*)())ParseOperand__GetDirectIndex)(parseOperand,loopIndex);
      ((int (*)())ParseOperand__AddDirectIndex)(this,directIndex);
      loopIndex = loopIndex + 1;
    } while (loopIndex < *(uint *)(parseOperand + 0x20));
  }
  loopIndex = 0;
  if (*(int *)(parseOperand + 0x14) != 0) {
    do {
      swizzle = ParseOperand__GetSwizzle(parseOperand,loopIndex);
      ((int (*)())ParseOperand__AddSwizzle)(this,swizzle);
      loopIndex = loopIndex + 1;
    } while (loopIndex < *(uint *)(parseOperand + 0x14));
  }
  uVar3 = *(undefined4 *)(parseOperand + 0x28);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(parseOperand + 0x2c);
  *(undefined4 *)((int)this + 0x28) = uVar3;
  return;
}

/* __ZN12ParseOperandD2Ev @ 0x97bbb318 (8 bytes) */
int __ZN12ParseOperandD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN12ParseOperandD4Ev)(this);
}

/* __ZN12ParseOperandD1Ev @ 0x97bbb320 (8 bytes) */
int __ZN12ParseOperandD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN12ParseOperandD4Ev)(this);
}

/* __ZN12ParseOperandD4Ev @ 0x97bbb328 (232 bytes) */
int __ZN12ParseOperandD4Ev(this)
  void *this;
{
  void *this_00;
  
  this_00 = *(void **)this;
  if (this_00 == (void *)0x0) goto LAB_97bbb3cc;
  if ((*(int *)((int)this_00 + 0x3c) == 0) ||
     (ParseOperand__temporaryAllocator == (unsigned char *)0x0)) {
    if ((*(int *)((int)this_00 + 0x58) != 0) &&
       (ParseOperand__addressTempAllocator != (unsigned char *)0x0)) {
      AddressTempAllocator__releaseTemporary
                (ParseOperand__addressTempAllocator,*(undefined4 *)((int)this_00 + 0x28));
      goto LAB_97bbb3a4;
    }
  }
  else {
    ((int (*)())TemporaryAllocator__releaseTemporary)(ParseOperand__temporaryAllocator,(uint)*(ushort *)((int)this_00 + 0x2c),
               *(uint *)((int)this_00 + 0x28));
LAB_97bbb3a4:
    this_00 = *(void **)this;
  }
  if ((*(int *)((int)this_00 + 0x50) == 0) && (this_00 != (void *)0x0)) {
    ((int (*)())__ZN11ParseSymbolD1Ev)(this_00);
    __ZdlPv(this_00);
  }
LAB_97bbb3cc:
  if (*(int *)((int)this + 0x1c) != 0) {
    _free(*(int *)((int)this + 0x1c));
  }
  if (*(int *)((int)this + 0x10) != 0) {
    _free(*(int *)((int)this + 0x10));
    return;
  }
  return;
}

/* ParseOperand__operator_ @ 0x97bbb410 (220 bytes) */
int ParseOperand__operator_(this, parseOperand)
  unsigned char * this;
  unsigned char * parseOperand;
{
  undefined2 field18;
  undefined4 uVar2;
  uint directIndex;
  uchar swizzle;
  undefined4 field24;
  uint loopIndex;
  
  if (this != parseOperand) {
    uVar2 = *(undefined4 *)(parseOperand + 4);
    field18 = *(undefined2 *)(parseOperand + 0x18);
    field24 = *(undefined4 *)(parseOperand + 0x24);
    *(undefined4 *)this = *(undefined4 *)parseOperand;
    *(undefined4 *)(this + 4) = uVar2;
    *(undefined2 *)(this + 0x18) = field18;
    *(undefined4 *)(this + 0x24) = field24;
    ClearDirectIndex(this);
    loopIndex = 0;
    if (*(int *)(parseOperand + 0x20) != 0) {
      do {
        directIndex = GetDirectIndex(parseOperand,loopIndex);
        AddDirectIndex(this,directIndex);
        loopIndex = loopIndex + 1;
      } while (loopIndex < *(uint *)(parseOperand + 0x20));
    }
    loopIndex = 0;
    if (*(int *)(parseOperand + 0x14) != 0) {
      do {
        swizzle = ParseOperand__GetSwizzle(parseOperand,loopIndex);
        ((int (*)())ParseOperand__AddSwizzle)(this,swizzle);
        loopIndex = loopIndex + 1;
      } while (loopIndex < *(uint *)(parseOperand + 0x14));
    }
    uVar2 = *(undefined4 *)(parseOperand + 0x28);
    *(undefined4 *)(this + 0x2c) = *(undefined4 *)(parseOperand + 0x2c);
    *(undefined4 *)(this + 0x28) = uVar2;
  }
  return this;
}

/* __ZeqRK12ParseOperandS1_ @ 0x97bbb4ec (328 bytes) */
int __ZeqRK12ParseOperandS1_(parseOperand1, parseOperand2)
  unsigned char * parseOperand1;
  unsigned char * parseOperand2;
{
  int directIndex2;
  int isMatrix2;
  int directIndex;
  int isMatrix;
  int swizzle2;
  int swizzle;
  int baseSize;
  int baseSize2;
  uint loopIndex;
  
  if ((*(int *)parseOperand1 == *(int *)parseOperand2) && (*(int *)(parseOperand1 + 4) == *(int *)(parseOperand2 + 4))) {
    baseSize = ((int (*)())ParseOperand__GetBaseSize)(parseOperand1);
    baseSize2 = ((int (*)())ParseOperand__GetBaseSize)(parseOperand2);
    if (baseSize == baseSize2) {
      isMatrix = ((int (*)())ParseOperand__IsMatrix)(parseOperand1);
      isMatrix2 = ((int (*)())ParseOperand__IsMatrix)(parseOperand2);
      if ((((isMatrix == isMatrix2) && (*(int *)(parseOperand1 + 0x28) == *(int *)(parseOperand2 + 0x28))) &&
          (*(int *)(parseOperand1 + 0x2c) == *(int *)(parseOperand2 + 0x2c))) &&
         (*(int *)(parseOperand1 + 0x20) == *(int *)(parseOperand2 + 0x20))) {
        loopIndex = 0;
        if (*(int *)(parseOperand1 + 0x20) != 0) {
          do {
            directIndex = ((int (*)())ParseOperand__GetDirectIndex)(parseOperand1,loopIndex);
            directIndex2 = ((int (*)())ParseOperand__GetDirectIndex)(parseOperand2,loopIndex);
            if (directIndex != directIndex2) {
              return 0;
            }
            loopIndex = 0;
            if (*(int *)(parseOperand2 + 0x14) != 0) {
              do {
                swizzle = ParseOperand__GetSwizzle(parseOperand1,loopIndex);
                swizzle2 = ParseOperand__GetSwizzle(parseOperand2,loopIndex);
                if (swizzle != swizzle2) {
                  return 0;
                }
                loopIndex = loopIndex + 1;
              } while (loopIndex < *(uint *)(parseOperand2 + 0x14));
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex < *(uint *)(parseOperand2 + 0x20));
        }
        return 1;
      }
    }
  }
  return 0;
}

/* ParseOperand__Clear @ 0x97bbb634 (88 bytes) */
int ParseOperand__Clear(this)
  unsigned char * this;
{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined2 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  ClearDirectIndex(this);
  ParseOperand__ClearSwizzles(this);
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  return;
}

/* ParseOperand__AddDirectIndex @ 0x97bbb68c (196 bytes) */
int ParseOperand__AddDirectIndex(this, directIndex)
  unsigned char * this;
  uint directIndex;
{
  int byteOffset;
  uint count;
  int allocation;
  int oldArray;
  uint loopIndex;
  
  count = *(uint *)(this + 0x20);
  if ((count & 3) == 0) {
    allocation = _malloc(count * 4 + 0x10);
    _memset(allocation,0,*(int *)(this + 0x20) * 4 + 0x10);
    count = *(uint *)(this + 0x20);
    loopIndex = 0;
    if (count == 0) {
      oldArray = *(int *)(this + 0x1c);
    }
    else {
      oldArray = *(int *)(this + 0x1c);
      do {
        byteOffset = loopIndex * 4;
        loopIndex = loopIndex + 1;
        *(undefined4 *)(byteOffset + allocation) = *(undefined4 *)(byteOffset + oldArray);
      } while (loopIndex < count);
    }
    if (oldArray != 0) {
      _free(oldArray);
      count = *(uint *)(this + 0x20);
    }
    *(int *)(this + 0x1c) = allocation;
  }
  *(uint *)(count * 4 + *(int *)(this + 0x1c)) = directIndex;
  *(int *)(this + 0x20) = *(int *)(this + 0x20) + 1;
  return;
}

/* ParseOperand__PopDirectIndex @ 0x97bbb750 (64 bytes) */
int ParseOperand__PopDirectIndex(this)
  unsigned char * this;
{
  int iVar1;
  uint loopIndex;
  
  iVar1 = *(int *)(this + 0x20);
  loopIndex = 0;
  *(int *)(this + 0x20) = iVar1 + -1;
  if (iVar1 + -1 != 0) {
    do {
      iVar1 = loopIndex * 4;
      loopIndex = loopIndex + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 0x1c)) =
           *(undefined4 *)(iVar1 + *(int *)(this + 0x1c) + 4);
    } while (loopIndex < *(uint *)(this + 0x20));
    return;
  }
  return;
}

/* ParseOperand__RemoveDirectIndex @ 0x97bbb790 (16 bytes) */
int ParseOperand__RemoveDirectIndex(this)
  unsigned char * this;
{
  *(int *)(this + 0x20) = *(int *)(this + 0x20) + -1;
  return;
}

/* ParseOperand__GetDirectIndex @ 0x97bbb7a0 (16 bytes) */
int ParseOperand__GetDirectIndex(this, index)
  unsigned char * this;
  uint index;
{
  return *(undefined4 *)(index * 4 + *(int *)(this + 0x1c));
}

/* ParseOperand__GetAsDestVar @ 0x97bbb7b0 (716 bytes) */
int ParseOperand__GetAsDestVar(destDesc, operand, markWord1)
  uint *destDesc;
  unsigned char * operand;
  int markWord1;
{
  uint isMatrix;
  int isMatrix2;
  uint loopIndex;
  short scalerWidthForType;
  int directIndex;
  int swizzle;
  short columnOffset;
  uint uVar1;
  int classBits;
  short regOffset;
  uint directStart;
  uint directIdx;
  
  *destDesc = 0;
  destDesc[1] = 0;
  regOffset = 0;
  directStart = 0;
  scalerWidthForType = GetScalerWidthForType((uint)*(ushort *)(*(int *)operand + 0x2c));
  *destDesc = (scalerWidthForType + -1) * 0x400 & 0xc00U | *destDesc & 0xfffff04f | 0x6c;
  isMatrix = ((int (*)())ParseOperand__IsMatrix)(operand);
  *destDesc = (isMatrix & 1) << 0xc | *destDesc & 0xffffefff;
  isMatrix2 = ((int (*)())ParseOperand__IsMatrix)(operand);
  columnOffset = 0;
  if (isMatrix2 == 0) {
LAB_97bbb868:
    regOffset = columnOffset;
    uVar1 = *(uint *)(operand + 0x20);
  }
  else {
    uVar1 = 0;
    if (*(int *)(operand + 0x20) != 0) {
      columnOffset = GetDirectIndex(operand,0);
      directStart = 1;
      *destDesc = *destDesc & 0xffffefff;
      goto LAB_97bbb868;
    }
  }
  if (directStart == uVar1) {
    if (*(int *)(operand + 0x14) == 0) {
      uVar1 = *destDesc;
      directStart = uVar1 >> 10 & 3;
      if (directStart == 1) {
LAB_97bbb950:
        uVar1 = uVar1 | 0x4000;
        *destDesc = uVar1;
      }
      else if (directStart != 0) {
        if (directStart != 2) {
          if (directStart != 3) goto LAB_97bbba00;
          uVar1 = uVar1 | 0x10000;
          *destDesc = uVar1;
        }
        uVar1 = uVar1 | 0x8000;
        *destDesc = uVar1;
        goto LAB_97bbb950;
      }
      *destDesc = uVar1 | 0x2000;
    }
    else {
      loopIndex = 0;
      if (*(int *)(operand + 0x14) != 0) {
        do {
          swizzle = ParseOperand__GetSwizzle(operand,loopIndex);
          if (swizzle == 1) {
            directStart = (loopIndex & 3) << 6 | *destDesc & 0xffffff3f | 0x4000;
LAB_97bbb900:
            *destDesc = directStart;
          }
          else {
            if (1 < swizzle) {
              if (swizzle == 2) {
                directStart = (loopIndex & 3) << 4 | *destDesc & 0xffffffcf | 0x8000;
              }
              else {
                if (swizzle != 3) goto LAB_97bbb904;
                directStart = (loopIndex & 3) << 2 | *destDesc & 0xfffffff3 | 0x10000;
              }
              goto LAB_97bbb900;
            }
            if (swizzle == 0) {
              directStart = (loopIndex & 3) << 8 | *destDesc & 0xfffffcff | 0x2000;
              goto LAB_97bbb900;
            }
          }
LAB_97bbb904:
          loopIndex = loopIndex + 1;
        } while (loopIndex < *(uint *)(operand + 0x14));
      }
    }
  }
  else {
    directIdx = directStart;
    if (directStart < uVar1) {
      do {
        directIndex = GetDirectIndex(operand,directIdx);
        if (directIndex == 1) {
          uVar1 = (directIdx - directStart) * 0x40 & 0xc0 | *destDesc & 0xffffff3f | 0x4000;
LAB_97bbb9ec:
          *destDesc = uVar1;
          uVar1 = *(uint *)(operand + 0x20);
        }
        else {
          if (directIndex == 0) {
            uVar1 = (directIdx - directStart) * 0x100 & 0x300 | *destDesc & 0xfffffcff | 0x2000;
            goto LAB_97bbb9ec;
          }
          if (directIndex == 2) {
            uVar1 = (directIdx - directStart) * 0x10 & 0x30 | *destDesc & 0xffffffcf | 0x8000;
            goto LAB_97bbb9ec;
          }
          if (directIndex == 3) {
            uVar1 = (directIdx - directStart) * 4 & 0xc | *destDesc & 0xfffffff3 | 0x10000;
            goto LAB_97bbb9ec;
          }
        }
        directIdx = directIdx + 1;
      } while (directIdx < uVar1);
    }
  }
LAB_97bbba00:
  if (*(char *)**(undefined4 **)operand == '\0') {
    uVar1 = *destDesc;
    classBits = 1;
  }
  else {
    if (*(char *)**(undefined4 **)operand != '\x04') goto LAB_97bbba4c;
    uVar1 = *destDesc;
    classBits = 3;
  }
  *destDesc = classBits << 0x11 | uVar1 & 0xfff1ffff;
  *(short *)((int)destDesc + 6) = *(short *)(**(int **)operand + 0x12) + regOffset;
LAB_97bbba4c:
  if (markWord1 != 0) {
    destDesc[1] = destDesc[1] & 0x800fffff | 0x80000000;
  }
  return destDesc;
}

/* ParseOperand__GetAsSourceVar @ 0x97bbba7c (676 bytes) */
int ParseOperand__GetAsSourceVar(srcDesc, operand, markWord1)
  uint *srcDesc;
  unsigned char * operand;
  int markWord1;
{
  int logicalSize;
  int isMatrix;
  uint loopIndex;
  uint swizzle;
  byte chunkKind;
  uint uVar2;
  ushort scalerWidth;
  int iVar3;
  uint uVar5;
  ushort matrixWidth;
  uint oldWord0;
  int directLeft;
  short regOffset;
  
  *srcDesc = 0;
  srcDesc[1] = 0;
  uVar5 = 0;
  regOffset = 0;
  scalerWidth = GetScalerWidthForType((uint)*(ushort *)(*(int *)operand + 0x2c));
  loopIndex = 0;
  *srcDesc = *srcDesc & 0xff85ffff | 0xd8000;
  uVar2 = *(uint *)(operand + 0x14);
  if (uVar2 != 0) {
    do {
      if (loopIndex == 1) {
        swizzle = ParseOperand__GetSwizzle(operand,1);
        uVar2 = (swizzle & 3) << 0x13 | *srcDesc & 0xffe7ffff;
LAB_97bbbb6c:
        *srcDesc = uVar2;
        uVar2 = *(uint *)(operand + 0x14);
      }
      else {
        if (loopIndex == 0) {
          swizzle = ParseOperand__GetSwizzle(operand,0);
          uVar2 = (swizzle & 3) << 0x15 | *srcDesc & 0xff9fffff;
          goto LAB_97bbbb6c;
        }
        if (loopIndex == 2) {
          swizzle = ParseOperand__GetSwizzle(operand,2);
          uVar2 = (swizzle & 3) << 0x11 | *srcDesc & 0xfff9ffff;
          goto LAB_97bbbb6c;
        }
        if (loopIndex == 3) {
          swizzle = ParseOperand__GetSwizzle(operand,3);
          uVar2 = (swizzle & 3) << 0xf | *srcDesc & 0xfffe7fff;
          goto LAB_97bbbb6c;
        }
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < uVar2);
  }
  isMatrix = ((int (*)())ParseOperand__IsMatrix)(operand);
  matrixWidth = 1;
  if (isMatrix != 0) {
    matrixWidth = scalerWidth;
  }
  if (scalerWidth == 1) {
    iVar3 = *(int *)(operand + 0x20);
    if (iVar3 == 0) {
      uVar2 = *srcDesc >> 0x15 & 3;
      *srcDesc = uVar2 << 0x13 | uVar2 << 0x11 | uVar2 << 0xf | *srcDesc & 0xffe07fff;
      goto LAB_97bbbbc4;
    }
  }
  else {
LAB_97bbbbc4:
    iVar3 = *(int *)(operand + 0x20);
  }
  directLeft = iVar3;
  if (iVar3 != 0) {
    while( true ) {
      if (matrixWidth < 2) {
        if (1 < scalerWidth) {
          scalerWidth = 1;
        }
      }
      else {
        matrixWidth = 1;
      }
      uVar2 = GetDirectIndex(operand,iVar3 - directLeft);
      if (scalerWidth < 2) {
        *srcDesc = (uVar2 & 3) << 0x15 |
                   (uVar2 & 3) << 0x13 |
                   (uVar2 & 3) << 0x11 | (uVar2 & 3) << 0xf | *srcDesc & 0xff807fff;
        uVar2 = uVar5;
      }
      regOffset = (short)uVar2;
      if (directLeft + -1 == 0) break;
      iVar3 = *(int *)(operand + 0x20);
      uVar5 = uVar2;
      directLeft = directLeft + -1;
    }
  }
  chunkKind = *(byte *)**(undefined4 **)operand;
  if (chunkKind == 2) {
    uVar5 = *srcDesc & 0xfc7fffff;
  }
  else {
    if (chunkKind < 3) {
      if (chunkKind != 0) goto LAB_97bbbcb0;
      uVar5 = *srcDesc;
      iVar3 = 1;
    }
    else if (chunkKind == 3) {
      uVar5 = *srcDesc;
      iVar3 = 2;
    }
    else {
      if (chunkKind != 4) goto LAB_97bbbcb0;
      uVar5 = *srcDesc;
      iVar3 = 3;
    }
    uVar5 = iVar3 << 0x17 | uVar5 & 0xfc7fffff;
  }
  *srcDesc = uVar5;
  *(short *)((int)srcDesc + 6) = *(short *)(**(int **)operand + 0x12) + regOffset;
LAB_97bbbcb0:
  *srcDesc = (uint)(matrixWidth != 1) * 0x4000 | *srcDesc & 0xffffbfff;
  logicalSize = ((int (*)())ParseOperand__GetLogicalSize)(operand);
  oldWord0 = *srcDesc;
  uVar5 = (logicalSize + -1) * 0x1000 & 0x3000;
  *srcDesc = uVar5 | oldWord0 & 0xffffcfff;
  uVar2 = (*(uint *)(operand + 0x28) & 1) << 0x1b;
  *srcDesc = uVar2 | uVar5 | oldWord0 & 0xf7ffcfff;
  if (markWord1 != 0) {
    *srcDesc = uVar2 | uVar5 | oldWord0 & 0x87ffcfff | 0x80000000;
    *(undefined1 *)((int)srcDesc + 3) = 0;
  }
  return srcDesc;
}

/* ParseOperand__IsMatrix @ 0x97bbbd20 (52 bytes) */
int ParseOperand__IsMatrix(this)
  unsigned char * this;
{
  ushort glType;
  
  if (*(int *)this == 0) {
    glType = *(ushort *)(this + 0x18);
  }
  else {
    glType = *(ushort *)(*(int *)this + 0x2c);
  }
  return glType - 0x8b5a < 3;
}

/* ParseOperand__GetBaseSize @ 0x97bbbd54 (76 bytes) */
int ParseOperand__GetBaseSize(this)
  unsigned char * this;
{
  int iVar1;
  
  if (*(int *)this == 0) {
    iVar1 = *(int *)(this + 0x24);
  }
  else {
    iVar1 = *(int *)(this + 0x14);
    if (iVar1 == 0) {
      iVar1 = GetScalerWidthForType((uint)*(ushort *)(*(int *)this + 0x2c));
    }
  }
  return iVar1;
}

/* ParseOperand__GetLogicalSize @ 0x97bbbda0 (132 bytes) */
int ParseOperand__GetLogicalSize(this)
  unsigned char * this;
{
  undefined4 result;
  int isMatrix;
  uint directIndexCount;
  
  if (*(int *)this == 0) {
    result = 1;
    if (*(int *)(this + 0x20) == 0) {
      result = ((int (*)())ParseOperand__GetBaseSize)(this);
    }
  }
  else {
    directIndexCount = *(uint *)(this + 0x20);
    if (((directIndexCount == 1) && (isMatrix = ((int (*)())ParseOperand__IsMatrix)(this), isMatrix == 0)) || (1 < directIndexCount)) {
      result = 1;
    }
    else {
      result = ((int (*)())ParseOperand__GetBaseSize)(this);
    }
  }
  return result;
}

/* ParseOperand__isWriteable @ 0x97bbbe24 (132 bytes) */
int ParseOperand__isWriteable(this)
  unsigned char * this;
{
  undefined4 uVar1;
  int *a0;
  
  uVar1 = 0;
  if (*(int *)this != 0) {
    a0 = *(int **)(*(int *)this + 0xc);
    uVar1 = (**(code **)(*a0 + 0x24))(a0);
    switch(uVar1) {
    case 0:
    case 1:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x12:
    case 0x13:
      uVar1 = 1;
      break;
    default:
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ParseOperand__AddSwizzle @ 0x97bbbef8 (184 bytes) */
int ParseOperand__AddSwizzle(this, swizzle)
  unsigned char * this;
  int swizzle;
{
  uint count;
  int allocation;
  uint copyIdx;
  int oldArray;
  
  count = *(uint *)(this + 0x14);
  if ((count & 3) == 0) {
    allocation = _malloc(count + 4);
    _memset(allocation,0,*(int *)(this + 0x14) + 4);
    count = *(uint *)(this + 0x14);
    copyIdx = 0;
    if (count == 0) {
      oldArray = *(int *)(this + 0x10);
    }
    else {
      oldArray = *(int *)(this + 0x10);
      do {
        *(undefined1 *)(allocation + copyIdx) = *(undefined1 *)(oldArray + copyIdx);
        copyIdx = copyIdx + 1 & 0xff;
      } while (copyIdx < count);
    }
    if (oldArray != 0) {
      _free(oldArray);
      count = *(uint *)(this + 0x14);
    }
    *(int *)(this + 0x10) = allocation;
  }
  *(uchar *)(*(int *)(this + 0x10) + count) = swizzle;
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
  return;
}

/* ParseOperand__RemoveSwizzle @ 0x97bbbfb0 (16 bytes) */
int ParseOperand__RemoveSwizzle(this)
  unsigned char * this;
{
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + -1;
  return;
}

