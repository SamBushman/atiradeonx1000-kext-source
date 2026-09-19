#include "decls.h"

/* TemporaryAllocator__TemporaryAllocator_97bb9e90 @ 0x97bb9e90 (4 bytes) */
int TemporaryAllocator__TemporaryAllocator_97bb9e90(this)
  unsigned char * this;
{
  TemporaryAllocator(this);
  return;
}

/* TemporaryAllocator__TemporaryAllocator_97bb9e94 @ 0x97bb9e94 (32 bytes) */
int TemporaryAllocator__TemporaryAllocator_97bb9e94(this)
  unsigned char * this;
{
  int iVar1;
  
  iVar1 = 0x19;
  do {
    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 100) = 0;
    this = this + 4;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

/* TemporaryAllocator___TemporaryAllocator @ 0x97bb9eb4 (8 bytes) */
int TemporaryAllocator___TemporaryAllocator(this)
  unsigned char * this;
{
  ~TemporaryAllocator(this);
  return;
}

/* TemporaryAllocator___TemporaryAllocator_97bb9ebc @ 0x97bb9ebc (8 bytes) */
int TemporaryAllocator___TemporaryAllocator_97bb9ebc(this)
  unsigned char * this;
{
  ~TemporaryAllocator(this);
  return;
}

/* TemporaryAllocator___TemporaryAllocator_97bb9ec4 @ 0x97bb9ec4 (72 bytes) */
int TemporaryAllocator___TemporaryAllocator_97bb9ec4(this)
  unsigned char * this;
{
  void *pvVar1;
  unsigned char * pTVar2;
  
  pTVar2 = this + 0x60;
  do {
    pvVar1 = *(void **)this;
    this = this + 4;
    if (pvVar1 != (void *)0x0) {
      _free(pvVar1);
    }
  } while (this <= pTVar2);
  return;
}

/* TemporaryAllocator__getTemporary @ 0x97bb9f0c (408 bytes) */
int TemporaryAllocator__getTemporary(this, param_1)
  unsigned char * this;
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  void *pvVar6;
  undefined2 in_register_00000010;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  iVar9 = CONCAT22(in_register_00000010,param_1);
  uVar10 = 0;
  iVar2 = 0;
  if ((iVar9 != 0x1404) && (iVar2 = 1, iVar9 != 0x1406)) {
    if ((iVar9 + 0x74b0U & 0xffff) < 0x15) {
      iVar2 = iVar9 + -0x8b4e;
    }
    else {
      iVar2 = 0x17;
      if ((iVar9 != 0x7ffe) && (iVar2 = 0x18, iVar9 != 0x7fff)) {
        return 0;
      }
    }
  }
  iVar2 = iVar2 * 4;
  iVar9 = 0;
  if (*(uint *)(this + iVar2 + 100) != 0) {
    piVar4 = *(int **)(this + iVar2);
    iVar3 = *piVar4;
    while (iVar3 != 0) {
      uVar10 = uVar10 + 1;
      iVar9 = uVar10 * 4;
      if (*(uint *)(this + iVar2 + 100) <= uVar10) break;
      piVar4 = piVar4 + 1;
      iVar3 = *piVar4;
    }
  }
  if (*(uint *)(this + iVar2 + 100) <= uVar10) {
    pvVar6 = _malloc(*(uint *)(this + iVar2 + 100) * 4 + 0x40);
    iVar3 = *(int *)(this + iVar2 + 100);
    iVar7 = 0;
    if (iVar3 != 0) {
      iVar8 = *(int *)(this + iVar2);
      do {
        iVar1 = iVar7 * 4;
        iVar7 = iVar7 + 1;
        *(undefined4 *)(iVar1 + (int)pvVar6) = *(undefined4 *)(iVar1 + iVar8);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    _memset((void *)(*(int *)(this + iVar2 + 100) * 4 + (int)pvVar6),0,0x40);
    if (*(void **)(this + iVar2) != (void *)0x0) {
      _free(*(void **)(this + iVar2));
    }
    *(void **)(this + iVar2) = pvVar6;
    uVar5 = *(int *)(this + iVar2 + 100) + 0x10;
    *(uint *)(this + iVar2 + 100) = uVar5;
    if (uVar10 < uVar5) {
      iVar3 = *(int *)(iVar9 + (int)pvVar6);
      while (iVar3 != 0) {
        uVar10 = uVar10 + 1;
        iVar9 = uVar10 * 4;
        if (uVar5 <= uVar10) break;
        iVar3 = *(int *)(iVar9 + *(int *)(this + iVar2));
      }
    }
  }
  *(undefined4 *)(iVar9 + *(int *)(this + iVar2)) = 1;
  return uVar10;
}

/* TemporaryAllocator__releaseTemporary @ 0x97bba0a4 (100 bytes) */
int TemporaryAllocator__releaseTemporary(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  uint param_2;
{
  int iVar1;
  undefined2 in_register_00000010;
  int iVar2;
  
  iVar2 = CONCAT22(in_register_00000010,param_1);
  iVar1 = 0;
  if ((iVar2 != 0x1404) && (iVar1 = 1, iVar2 != 0x1406)) {
    if ((iVar2 + 0x74b0U & 0xffff) < 0x15) {
      iVar1 = iVar2 + -0x8b4e;
    }
    else {
      iVar1 = 0x17;
      if (iVar2 != 0x7ffe) {
        if (iVar2 != 0x7fff) {
          return;
        }
        iVar1 = 0x18;
      }
    }
  }
  *(undefined4 *)(param_2 * 4 + *(int *)(this + iVar1 * 4)) = 0;
  return;
}

/* ParseSymbol__ClearName @ 0x97bba108 (72 bytes) */
int ParseSymbol__ClearName(this)
  unsigned char * this;
{
  if (*(void **)(this + 0x14) != (void *)0x0) {
    _free(*(void **)(this + 0x14));
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
  if (*(void **)(this + 0x18) != (void *)0x0) {
    _free(*(void **)(this + 0x18));
  }
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  return;
}

/* ParseSymbol__ParseSymbol @ 0x97bba194 (4 bytes) */
int ParseSymbol__ParseSymbol(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 8) = 0;
  *(undefined2 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x44) = 1;
  *(undefined2 *)(this + 0x30) = 0;
  *(undefined2 *)(this + 0x2e) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 4) = 0;
  return;
}

/* ParseSymbol__ParseSymbol_97bba198 @ 0x97bba198 (4 bytes) */
int ParseSymbol__ParseSymbol_97bba198(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 8) = 0;
  *(undefined2 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x44) = 1;
  *(undefined2 *)(this + 0x30) = 0;
  *(undefined2 *)(this + 0x2e) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 4) = 0;
  return;
}

/* ParseSymbol__ParseSymbol_97bba19c @ 0x97bba19c (124 bytes) */
int ParseSymbol__ParseSymbol_97bba19c(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 8) = 0;
  *(undefined2 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x44) = 1;
  *(undefined2 *)(this + 0x30) = 0;
  *(undefined2 *)(this + 0x2e) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 4) = 0;
  return;
}

/* ParseSymbol___ParseSymbol @ 0x97bba218 (8 bytes) */
int ParseSymbol___ParseSymbol(this)
  unsigned char * this;
{
  ~ParseSymbol(this);
  return;
}

/* ParseSymbol___ParseSymbol_97bba220 @ 0x97bba220 (8 bytes) */
int ParseSymbol___ParseSymbol_97bba220(this)
  unsigned char * this;
{
  ~ParseSymbol(this);
  return;
}

/* ParseSymbol___ParseSymbol_97bba228 @ 0x97bba228 (116 bytes) */
int ParseSymbol___ParseSymbol_97bba228(this)
  unsigned char * this;
{
  if (*(void **)(this + 0x14) != (void *)0x0) {
    _free(*(void **)(this + 0x14));
  }
  if (*(void **)(this + 0x18) != (void *)0x0) {
    _free(*(void **)(this + 0x18));
  }
  if ((*(int *)(this + 0x44) != 0) && (*(void **)this != (void *)0x0)) {
    _free(*(void **)this);
    return;
  }
  return;
}

/* ParseSymbol__ParseSymbol_97bba29c @ 0x97bba29c (4 bytes) */
int ParseSymbol__ParseSymbol_97bba29c(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
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
  
  uVar2 = *(undefined2 *)(param_1 + 0x2c);
  uVar11 = *(undefined4 *)(param_1 + 0x28);
  uVar14 = 0;
  uVar1 = *(undefined2 *)(param_1 + 0x2e);
  pTVar5 = *(unsigned char **)(param_1 + 0xc);
  *(undefined2 *)(this + 0x30) = *(undefined2 *)(param_1 + 0x30);
  *(undefined2 *)(this + 0x2c) = uVar2;
  *(undefined4 *)(this + 0x28) = uVar11;
  *(undefined4 *)(this + 0x44) = 1;
  *(undefined2 *)(this + 0x2e) = uVar1;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  ((int (*)())ParseSymbol__SetParseTreeType)(this,pTVar5);
  uVar11 = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x48) = uVar11;
  ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
  uVar11 = *(undefined4 *)(param_1 + 0x34);
  uVar10 = *(undefined4 *)(param_1 + 0x38);
  uVar13 = *(undefined4 *)(param_1 + 0x3c);
  uVar12 = *(undefined4 *)(param_1 + 0x60);
  uVar9 = *(undefined4 *)(param_1 + 0x5c);
  uVar8 = *(undefined4 *)(param_1 + 0x58);
  uVar7 = *(undefined4 *)(param_1 + 0x40);
  pcVar6 = *(char **)(param_1 + 0x14);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x34) = uVar11;
  *(undefined4 *)(this + 0x38) = uVar10;
  *(undefined4 *)(this + 0x3c) = uVar13;
  *(undefined4 *)(this + 0x60) = uVar12;
  *(undefined4 *)(this + 0x5c) = uVar9;
  *(undefined4 *)(this + 0x58) = uVar8;
  *(undefined4 *)(this + 0x40) = uVar7;
  SetName(this,pcVar6);
  *(undefined4 *)(this + 0x24) = 0;
  iVar3 = *(int *)(param_1 + 0x24);
  uVar11 = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x54) = uVar11;
  if (iVar3 != 0) {
    do {
      uVar4 = GetDirectIndex(param_1,uVar14);
      uVar14 = uVar14 + 1;
      AddDirectIndex(this,uVar4);
    } while (uVar14 < *(uint *)(param_1 + 0x24));
  }
  return;
}

/* ParseSymbol__ParseSymbol_97bba2a0 @ 0x97bba2a0 (4 bytes) */
int ParseSymbol__ParseSymbol_97bba2a0(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
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
  
  uVar2 = *(undefined2 *)(param_1 + 0x2c);
  uVar11 = *(undefined4 *)(param_1 + 0x28);
  uVar14 = 0;
  uVar1 = *(undefined2 *)(param_1 + 0x2e);
  pTVar5 = *(unsigned char **)(param_1 + 0xc);
  *(undefined2 *)(this + 0x30) = *(undefined2 *)(param_1 + 0x30);
  *(undefined2 *)(this + 0x2c) = uVar2;
  *(undefined4 *)(this + 0x28) = uVar11;
  *(undefined4 *)(this + 0x44) = 1;
  *(undefined2 *)(this + 0x2e) = uVar1;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  ((int (*)())ParseSymbol__SetParseTreeType)(this,pTVar5);
  uVar11 = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x48) = uVar11;
  ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
  uVar11 = *(undefined4 *)(param_1 + 0x34);
  uVar10 = *(undefined4 *)(param_1 + 0x38);
  uVar13 = *(undefined4 *)(param_1 + 0x3c);
  uVar12 = *(undefined4 *)(param_1 + 0x60);
  uVar9 = *(undefined4 *)(param_1 + 0x5c);
  uVar8 = *(undefined4 *)(param_1 + 0x58);
  uVar7 = *(undefined4 *)(param_1 + 0x40);
  pcVar6 = *(char **)(param_1 + 0x14);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x34) = uVar11;
  *(undefined4 *)(this + 0x38) = uVar10;
  *(undefined4 *)(this + 0x3c) = uVar13;
  *(undefined4 *)(this + 0x60) = uVar12;
  *(undefined4 *)(this + 0x5c) = uVar9;
  *(undefined4 *)(this + 0x58) = uVar8;
  *(undefined4 *)(this + 0x40) = uVar7;
  SetName(this,pcVar6);
  *(undefined4 *)(this + 0x24) = 0;
  iVar3 = *(int *)(param_1 + 0x24);
  uVar11 = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x54) = uVar11;
  if (iVar3 != 0) {
    do {
      uVar4 = GetDirectIndex(param_1,uVar14);
      uVar14 = uVar14 + 1;
      AddDirectIndex(this,uVar4);
    } while (uVar14 < *(uint *)(param_1 + 0x24));
  }
  return;
}

/* ParseSymbol__ParseSymbol_97bba2a4 @ 0x97bba2a4 (296 bytes) */
int ParseSymbol__ParseSymbol_97bba2a4(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
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
  
  uVar2 = *(undefined2 *)(param_1 + 0x2c);
  uVar11 = *(undefined4 *)(param_1 + 0x28);
  uVar14 = 0;
  uVar1 = *(undefined2 *)(param_1 + 0x2e);
  pTVar5 = *(unsigned char **)(param_1 + 0xc);
  *(undefined2 *)(this + 0x30) = *(undefined2 *)(param_1 + 0x30);
  *(undefined2 *)(this + 0x2c) = uVar2;
  *(undefined4 *)(this + 0x28) = uVar11;
  *(undefined4 *)(this + 0x44) = 1;
  *(undefined2 *)(this + 0x2e) = uVar1;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  ((int (*)())ParseSymbol__SetParseTreeType)(this,pTVar5);
  uVar11 = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x48) = uVar11;
  ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
  uVar11 = *(undefined4 *)(param_1 + 0x34);
  uVar10 = *(undefined4 *)(param_1 + 0x38);
  uVar13 = *(undefined4 *)(param_1 + 0x3c);
  uVar12 = *(undefined4 *)(param_1 + 0x60);
  uVar9 = *(undefined4 *)(param_1 + 0x5c);
  uVar8 = *(undefined4 *)(param_1 + 0x58);
  uVar7 = *(undefined4 *)(param_1 + 0x40);
  pcVar6 = *(char **)(param_1 + 0x14);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x34) = uVar11;
  *(undefined4 *)(this + 0x38) = uVar10;
  *(undefined4 *)(this + 0x3c) = uVar13;
  *(undefined4 *)(this + 0x60) = uVar12;
  *(undefined4 *)(this + 0x5c) = uVar9;
  *(undefined4 *)(this + 0x58) = uVar8;
  *(undefined4 *)(this + 0x40) = uVar7;
  SetName(this,pcVar6);
  *(undefined4 *)(this + 0x24) = 0;
  iVar3 = *(int *)(param_1 + 0x24);
  uVar11 = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x54) = uVar11;
  if (iVar3 != 0) {
    do {
      uVar4 = GetDirectIndex(param_1,uVar14);
      uVar14 = uVar14 + 1;
      AddDirectIndex(this,uVar4);
    } while (uVar14 < *(uint *)(param_1 + 0x24));
  }
  return;
}

/* ParseSymbol__operator_ @ 0x97bba3cc (328 bytes) */
int ParseSymbol__operator_(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  unsigned char * pTVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  
  if (this != param_1) {
    uVar1 = *(undefined2 *)(param_1 + 0x30);
    uVar2 = *(undefined2 *)(param_1 + 0x2c);
    pcVar5 = *(char **)(param_1 + 0x14);
    *(undefined2 *)(this + 0x2e) = *(undefined2 *)(param_1 + 0x2e);
    *(undefined2 *)(this + 0x30) = uVar1;
    *(undefined2 *)(this + 0x2c) = uVar2;
    SetName(this,pcVar5);
    ClearDirectIndex(this);
    uVar14 = 0;
    if (*(int *)(param_1 + 0x24) != 0) {
      do {
        uVar4 = GetDirectIndex(param_1,uVar14);
        AddDirectIndex(this,uVar4);
        uVar14 = uVar14 + 1;
      } while (uVar14 < *(uint *)(param_1 + 0x24));
    }
    pTVar6 = *(unsigned char **)(param_1 + 0xc);
    *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
    ((int (*)())ParseSymbol__SetParseTreeType)(this,pTVar6);
    uVar3 = *(undefined4 *)(param_1 + 0x48);
    *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(this + 0x48) = uVar3;
    ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
    uVar3 = *(undefined4 *)(param_1 + 0x54);
    uVar11 = *(undefined4 *)(param_1 + 0x34);
    uVar13 = *(undefined4 *)(param_1 + 0x38);
    uVar12 = *(undefined4 *)(param_1 + 0x3c);
    uVar10 = *(undefined4 *)(param_1 + 0x60);
    uVar9 = *(undefined4 *)(param_1 + 0x5c);
    uVar8 = *(undefined4 *)(param_1 + 0x58);
    uVar7 = *(undefined4 *)(param_1 + 0x40);
    *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
    *(undefined4 *)(this + 0x34) = uVar11;
    *(undefined4 *)(this + 0x38) = uVar13;
    *(undefined4 *)(this + 0x3c) = uVar12;
    *(undefined4 *)(this + 0x60) = uVar10;
    *(undefined4 *)(this + 0x5c) = uVar9;
    *(undefined4 *)(this + 0x58) = uVar8;
    *(undefined4 *)(this + 0x40) = uVar7;
    *(undefined4 *)(this + 0x54) = uVar3;
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 0x50) = 0;
    *(undefined4 *)(this + 4) = 0;
    if ((*(void **)this != (void *)0x0) && (*(int *)(this + 0x44) != 0)) {
      _free(*(void **)this);
    }
    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 0x44) = 1;
  }
  return this;
}

/* operator___97bba514 @ 0x97bba514 (148 bytes) */
int operator___97bba514(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((((*(int *)(param_1 + 0x28) == -1) || (*(int *)(param_2 + 0x28) == -1)) ||
      ((*(int *)(param_1 + 0x28) == *(int *)(param_2 + 0x28) &&
       (*(int *)(param_1 + 0x48) == *(int *)(param_2 + 0x48))))) &&
     (((*(int *)(param_1 + 0x1c) == *(int *)(param_2 + 0x1c) &&
       (*(size_t *)(param_1 + 0x20) == *(size_t *)(param_2 + 0x20))) &&
      (iVar1 = _strncmp(*(char **)(param_1 + 0x14),*(char **)(param_2 + 0x14),
                        *(size_t *)(param_1 + 0x20)), iVar1 == 0)))) {
    uVar2 = 1;
  }
  return uVar2;
}

/* ParseSymbol__ResolveOpenGLType @ 0x97bba5a8 (616 bytes) */
int ParseSymbol__ResolveOpenGLType(this)
  unsigned char * this;
{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*(int **)(this + 0xc) == (int *)0x0) {
    return;
  }
  iVar5 = 0;
  iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x38))();
  if ((iVar3 != 0) && (*(int *)(this + 0x48) == 0)) {
    iVar5 = 1;
  }
  uVar2 = 0x7fff;
  *(int *)(this + 0x4c) = iVar5;
  if (iVar5 == 0) {
    uVar4 = (**(code **)(**(int **)(this + 0xc) + 0x20))();
    switch(uVar4) {
    default:
      goto switchD_97bba640_caseD_0;
    case 1:
      iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x34))();
      if (iVar3 == 0) {
        iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x2c))();
        if (iVar3 == 2) {
          uVar2 = 0x8b50;
        }
        else if (iVar3 < 3) {
          if (iVar3 != 1) {
            return;
          }
          uVar2 = 0x1406;
        }
        else {
          if (iVar3 != 3) {
            bVar1 = iVar3 == 4;
            uVar2 = 0x8b52;
            goto LAB_97bba7d4;
          }
          uVar2 = 0x8b51;
        }
      }
      else {
        iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x2c))();
        if (iVar3 == 3) {
          uVar2 = 0x8b5b;
        }
        else if (iVar3 < 4) {
          if (iVar3 != 2) {
            return;
          }
          uVar2 = 0x8b5a;
        }
        else {
          bVar1 = iVar3 == 4;
          uVar2 = 0x8b5c;
LAB_97bba7d4:
          if (!bVar1) {
            return;
          }
        }
      }
      break;
    case 2:
      iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x2c))();
      if (iVar3 == 2) {
        uVar2 = 0x8b53;
      }
      else if (iVar3 < 3) {
        if (iVar3 != 1) {
          return;
        }
        uVar2 = 0x1404;
      }
      else {
        if (iVar3 != 3) {
          bVar1 = iVar3 == 4;
          uVar2 = 0x8b55;
          goto LAB_97bba7d4;
        }
        uVar2 = 0x8b54;
      }
      break;
    case 3:
      iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x2c))();
      if (iVar3 == 2) {
        uVar2 = 0x8b57;
      }
      else if (iVar3 < 3) {
        if (iVar3 != 1) {
          return;
        }
        uVar2 = 0x8b56;
      }
      else {
        if (iVar3 != 3) {
          bVar1 = iVar3 == 4;
          uVar2 = 0x8b59;
          goto LAB_97bba7d4;
        }
        uVar2 = 0x8b58;
      }
      break;
    case 5:
      uVar2 = 0x8b5d;
      break;
    case 6:
      uVar2 = 0x8b5e;
      break;
    case 7:
      uVar2 = 0x8b5f;
      break;
    case 8:
      uVar2 = 0x8b60;
      break;
    case 9:
      uVar2 = 0x8b61;
      break;
    case 10:
      uVar2 = 0x8b62;
      break;
    case 0xb:
      uVar2 = 0x8b63;
      break;
    case 0xc:
      uVar2 = 0x8b64;
      break;
    case 0xe:
      uVar2 = 0x7ffe;
    }
  }
  *(undefined2 *)(this + 0x2c) = uVar2;
switchD_97bba640_caseD_0:
  return;
}

/* ParseSymbol__SetParseTreeType @ 0x97bba850 (120 bytes) */
int ParseSymbol__SetParseTreeType(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  int iVar2;
  
  *(unsigned char **)(this + 0xc) = param_1;
  if (param_1 != (unsigned char *)0x0) {
    iVar2 = (**(code **)(*(int *)param_1 + 0x38))(param_1);
    uVar1 = 1;
    if (iVar2 != 0) {
      uVar1 = *(undefined2 *)(param_1 + 6);
    }
    *(undefined2 *)(this + 0x2e) = uVar1;
    ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
    return;
  }
  return;
}

/* ParseSymbol__SetChunk @ 0x97bba8c8 (84 bytes) */
int ParseSymbol__SetChunk(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  if ((*(void **)this != (void *)0x0) && (*(int *)(this + 0x44) != 0)) {
    _free(*(void **)this);
  }
  *(unsigned char **)this = param_1;
  *(undefined4 *)(this + 0x44) = 1;
  return;
}

/* ParseSymbol__SetArrayPositionFromLastIndex @ 0x97bba91c (56 bytes) */
int ParseSymbol__SetArrayPositionFromLastIndex(this)
  unsigned char * this;
{
  undefined2 uVar1;
  
  uVar1 = GetDirectIndex(this,*(int *)(this + 0x24) - 1);
  *(undefined2 *)(this + 0x30) = uVar1;
  return;
}

/* ParseSymbol__CatName @ 0x97bba954 (208 bytes) */
int ParseSymbol__CatName(this, param_1)
  unsigned char * this;
  char *param_1;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  char *pcVar5;
  int iVar6;
  
  if (param_1 != (char *)0x0) {
    sVar4 = _strlen(param_1);
    pcVar5 = _malloc(sVar4 + *(int *)(this + 0x20) + 1);
    if (*(char **)(this + 0x14) != (char *)0x0) {
      _strncpy(pcVar5,*(char **)(this + 0x14),*(int *)(this + 0x20) + 1);
    }
    _strncpy(pcVar5 + *(int *)(this + 0x20),param_1,sVar4 + 1);
    *(size_t *)(this + 0x20) = *(int *)(this + 0x20) + sVar4;
    _free(*(void **)(this + 0x14));
    iVar2 = *(int *)(this + 0x20);
    iVar6 = 0;
    *(undefined4 *)(this + 0x1c) = 0;
    *(char **)(this + 0x14) = pcVar5;
    if (iVar2 != 0) {
      iVar3 = 0;
      do {
        pcVar1 = pcVar5 + iVar6;
        iVar6 = iVar6 + 1;
        iVar3 = iVar3 + *pcVar1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      *(int *)(this + 0x1c) = iVar3;
    }
  }
  return;
}

/* ParseSymbol__SetName @ 0x97bbaa24 (156 bytes) */
int ParseSymbol__SetName(this, param_1)
  unsigned char * this;
  char *param_1;
{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  
  ClearName(this);
  if ((param_1 != (char *)0x0) && (sVar2 = _strlen(param_1), 0 < (int)sVar2)) {
    *(size_t *)(this + 0x20) = sVar2;
    pcVar3 = _malloc(sVar2 + 1);
    *(char **)(this + 0x14) = pcVar3;
    _strncpy(pcVar3,param_1,*(int *)(this + 0x20) + 1);
    iVar1 = *(int *)(this + 0x20);
    iVar4 = 0;
    if (iVar1 != 0) {
      do {
        pcVar3 = (char *)(*(int *)(this + 0x14) + iVar4);
        iVar4 = iVar4 + 1;
        *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + (int)*pcVar3;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}

/* ParseSymbol__RemoveNameBackToChar @ 0x97bbaac0 (132 bytes) */
int ParseSymbol__RemoveNameBackToChar(this, param_1)
  unsigned char * this;
  int param_1;
{
  char *pcVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(this + 0x20);
  bVar2 = false;
  if (-1 < iVar3) {
    do {
      if ((int)*(char *)(*(int *)(this + 0x14) + iVar3) == CONCAT31(in_register_00000010,param_1)) {
        bVar2 = true;
      }
      *(undefined1 *)(*(int *)(this + 0x14) + iVar3) = 0;
      iVar3 = iVar3 + -1;
    } while ((-1 < iVar3) && (!bVar2));
  }
  iVar3 = iVar3 + 1;
  iVar4 = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(int *)(this + 0x20) = iVar3;
  if (0 < iVar3) {
    do {
      pcVar1 = (char *)(*(int *)(this + 0x14) + iVar4);
      iVar4 = iVar4 + 1;
      *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + (int)*pcVar1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    return;
  }
  return;
}

/* ParseSymbol__ChangeArrayNameForArrayIndex @ 0x97bbab44 (424 bytes) */
int ParseSymbol__ChangeArrayNameForArrayIndex(param_1, param_2)
  uint param_1;
  uint param_2;
{
  char cVar1;
  uint uVar2;
  size_t sVar3;
  char *pcVar4;
  void *pvVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char acStack_30 [28];
  
  _sprintf(acStack_30,"%u");
  sVar3 = _strlen(acStack_30);
  iVar9 = 0;
  pcVar4 = _malloc(*(int *)(param_1 + 0x20) + sVar3 + 1);
  uVar2 = 0;
  iVar8 = 0;
  if (param_2 != 0xffffffff) {
    pcVar6 = *(char **)(param_1 + 0x14);
    cVar1 = *pcVar6;
    while (cVar1 != '\0') {
      if (cVar1 == '[') {
        uVar2 = uVar2 + 1;
      }
      pcVar4[iVar9] = cVar1;
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + 1;
      if (param_2 + 1 <= uVar2) break;
      cVar1 = pcVar6[iVar8];
    }
  }
  pcVar4[iVar9] = '\0';
  _strcat(pcVar4,acStack_30);
  cVar1 = pcVar4[iVar9];
  while (cVar1 != '\0') {
    iVar9 = iVar9 + 1;
    cVar1 = pcVar4[iVar9];
  }
  iVar7 = *(int *)(param_1 + 0x14);
  cVar1 = *(char *)(iVar7 + iVar8);
  while ((cVar1 != '\0' && (cVar1 != ']'))) {
    iVar8 = iVar8 + 1;
    cVar1 = *(char *)(iVar7 + iVar8);
  }
  cVar1 = *(char *)(iVar7 + iVar8);
  while (cVar1 != '\0') {
    pcVar4[iVar9] = cVar1;
    iVar8 = iVar8 + 1;
    iVar9 = iVar9 + 1;
    cVar1 = *(char *)(iVar7 + iVar8);
  }
  pvVar5 = *(void **)(param_1 + 0x14);
  pcVar4[iVar9] = *(char *)(iVar7 + iVar8);
  if (pvVar5 != (void *)0x0) {
    _free(pvVar5);
  }
  *(int *)(param_1 + 0x20) = iVar9;
  iVar8 = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(char **)(param_1 + 0x14) = pcVar4;
  for (; iVar9 != 0; iVar9 = iVar9 + -1) {
    pcVar6 = pcVar4 + iVar8;
    iVar8 = iVar8 + 1;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + (int)*pcVar6;
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
  RemoveNameBackToChar(this,'[');
  return;
}

/* ParseSymbol__TrimNameToBase @ 0x97bbad10 (156 bytes) */
int ParseSymbol__TrimNameToBase(this)
  unsigned char * this;
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  pcVar2 = *(char **)(this + 0x14);
  iVar3 = 0;
  cVar1 = *pcVar2;
  if ((cVar1 != '\0') && (cVar1 != '[')) {
    while (cVar1 != '.') {
      iVar3 = iVar3 + 1;
      cVar1 = pcVar2[iVar3];
      if ((cVar1 == '\0') || (cVar1 == '[')) break;
    }
  }
  pcVar2[iVar3] = '\0';
  *(int *)(this + 0x20) = iVar3;
  iVar4 = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  if (iVar3 < 1) {
    return;
  }
  do {
    pcVar2 = (char *)(*(int *)(this + 0x14) + iVar4);
    iVar4 = iVar4 + 1;
    *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + (int)*pcVar2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* ParseSymbol__AddDirectIndex @ 0x97bbadac (196 bytes) */
int ParseSymbol__AddDirectIndex(this, param_1)
  unsigned char * this;
  uint param_1;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  void *pvVar4;
  uint uVar5;
  
  uVar2 = *(uint *)(this + 0x24);
  if ((uVar2 & 3) == 0) {
    pvVar3 = _malloc(uVar2 * 4 + 0x10);
    _memset(pvVar3,0,*(int *)(this + 0x24) * 4 + 0x10);
    uVar2 = *(uint *)(this + 0x24);
    uVar5 = 0;
    if (uVar2 == 0) {
      pvVar4 = *(void **)(this + 0x18);
    }
    else {
      pvVar4 = *(void **)(this + 0x18);
      do {
        iVar1 = uVar5 * 4;
        uVar5 = uVar5 + 1;
        *(undefined4 *)(iVar1 + (int)pvVar3) = *(undefined4 *)(iVar1 + (int)pvVar4);
      } while (uVar5 < uVar2);
    }
    if (pvVar4 != (void *)0x0) {
      _free(pvVar4);
      uVar2 = *(uint *)(this + 0x24);
    }
    *(void **)(this + 0x18) = pvVar3;
  }
  *(uint *)(uVar2 * 4 + *(int *)(this + 0x18)) = param_1;
  *(int *)(this + 0x24) = *(int *)(this + 0x24) + 1;
  return;
}

/* ParseSymbol__PopDirectIndex @ 0x97bbae70 (64 bytes) */
int ParseSymbol__PopDirectIndex(this)
  unsigned char * this;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(this + 0x24);
  uVar2 = 0;
  *(int *)(this + 0x24) = iVar1 + -1;
  if (iVar1 + -1 != 0) {
    do {
      iVar1 = uVar2 * 4;
      uVar2 = uVar2 + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 0x18)) =
           *(undefined4 *)(iVar1 + *(int *)(this + 0x18) + 4);
    } while (uVar2 < *(uint *)(this + 0x24));
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
int ParseSymbol__GetDirectIndex(this, param_1)
  unsigned char * this;
  uint param_1;
{
  return *(undefined4 *)(param_1 * 4 + *(int *)(this + 0x18));
}

/* ParseSymbol__GetString @ 0x97bbaed0 (724 bytes) */
int ParseSymbol__GetString(this, param_1)
  unsigned char * this;
  int param_1;
{
  byte bVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined3 in_register_00000010;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  uint uVar7;
  
  iVar4 = CONCAT31(in_register_00000010,param_1);
  pcVar6 = (char *)0x0;
  pcVar2 = _malloc(*(int *)(this + 0x20) + 0x200);
  if (pcVar2 == (char *)0x0) {
    return (char *)0x0;
  }
  *pcVar2 = '\0';
  pbVar5 = *(byte **)this;
  if (pbVar5 == (byte *)0x0) {
LAB_97bbb054:
    if (pcVar6 != (char *)0x0) {
      _sprintf(pcVar2,DAT_a7b7bbbc,pcVar2,pcVar6,*(undefined4 *)(this + 0x14),
               *(undefined4 *)(this + 0x28));
      _free(pcVar6);
      goto LAB_97bbb0a4;
    }
  }
  else {
    bVar1 = *pbVar5;
    if (bVar1 == 2) {
      if (iVar4 != 0) {
        _sprintf(pcVar2,_symbolUtilString);
        pbVar5 = *(byte **)this;
      }
      pcVar6 = (char *)PrintAttribute(*(undefined4 *)(pbVar5 + 0xc),*(undefined4 *)(pbVar5 + 0x10));
      goto LAB_97bbb054;
    }
    if (2 < bVar1) {
      if (bVar1 == 3) {
        if (iVar4 != 0) {
          _sprintf(pcVar2,DAT_a7b7bba8);
          pbVar5 = *(byte **)this;
        }
        pcVar6 = (char *)PrintParam(*(undefined4 *)(pbVar5 + 0xc),*(undefined4 *)(pbVar5 + 0x10));
      }
      else {
        if (bVar1 != 4) goto LAB_97bbb038;
        if (iVar4 != 0) {
          _sprintf(pcVar2,DAT_a7b7bbac);
          pbVar5 = *(byte **)this;
        }
        pcVar6 = (char *)PrintOutput(*(undefined4 *)(pbVar5 + 0xc),*(undefined4 *)(pbVar5 + 0x10));
      }
      goto LAB_97bbb054;
    }
    if (bVar1 != 0) {
LAB_97bbb038:
      pcVar6 = _malloc(0x20);
      _strcpy(pcVar6,DAT_a7b7bbb8);
      goto LAB_97bbb054;
    }
    pcVar6 = DAT_a7b7bbb4;
    if (iVar4 != 0) {
      pcVar6 = DAT_a7b7bbb0;
    }
    _sprintf(pcVar2,pcVar6,(uint)*(ushort *)(pbVar5 + 0x12));
  }
  _sprintf(pcVar2,DAT_a7b7bbc0,pcVar2,*(undefined4 *)(this + 0x14),*(undefined4 *)(this + 0x28));
LAB_97bbb0a4:
  uVar3 = GetGLStringForType(*(ushort *)(this + 0x2c));
  _sprintf(pcVar2,DAT_a7b7bbc4,pcVar2,uVar3);
  if (1 < *(short *)(this + 0x2e)) {
    _sprintf(pcVar2,DAT_a7b7bbc8,pcVar2,(int)*(short *)(this + 0x30));
  }
  pcVar6 = _malloc(0x40);
  *pcVar6 = '\0';
  uVar7 = 0;
  if (*(int *)(this + 0x24) != 0) {
    do {
      if (uVar7 == 0) {
        _sprintf(pcVar6,DAT_a7b7bbd0);
      }
      else {
        _sprintf(pcVar6,DAT_a7b7bbcc,pcVar6);
      }
      uVar3 = GetDirectIndex(this,uVar7);
      _sprintf(pcVar6,DAT_a7b7bbd4,pcVar6,uVar3);
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(this + 0x24));
  }
  _sprintf(pcVar2,DAT_a7b7bbd8,pcVar2,pcVar6);
  _free(pcVar6);
  return pcVar2;
}

/* ParseOperand__ClearDirectIndex @ 0x97bbb1a4 (68 bytes) */
int ParseOperand__ClearDirectIndex(this)
  unsigned char * this;
{
  if (*(void **)(this + 0x1c) != (void *)0x0) {
    _free(*(void **)(this + 0x1c));
  }
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  return;
}

/* ParseOperand__ParseOperand @ 0x97bbb1e8 (4 bytes) */
int ParseOperand__ParseOperand(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined2 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  return;
}

/* ParseOperand__ParseOperand_97bbb1ec @ 0x97bbb1ec (4 bytes) */
int ParseOperand__ParseOperand_97bbb1ec(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined2 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  return;
}

/* ParseOperand__ParseOperand_97bbb1f0 @ 0x97bbb1f0 (56 bytes) */
int ParseOperand__ParseOperand_97bbb1f0(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined2 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  return;
}

/* ParseOperand__ParseOperand_97bbb228 @ 0x97bbb228 (4 bytes) */
int ParseOperand__ParseOperand_97bbb228(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uchar uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  uVar7 = 0;
  *(undefined4 *)(this + 0x20) = 0;
  iVar2 = *(int *)(param_1 + 0x20);
  uVar1 = *(undefined2 *)(param_1 + 0x18);
  uVar3 = *(undefined4 *)(param_1 + 4);
  uVar6 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar3;
  *(undefined2 *)(this + 0x18) = uVar1;
  *(undefined4 *)(this + 0x24) = uVar6;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  if (iVar2 != 0) {
    do {
      uVar4 = GetDirectIndex(param_1,uVar7);
      AddDirectIndex(this,uVar4);
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 0x20));
  }
  uVar7 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    do {
      uVar5 = ParseOperand__GetSwizzle(param_1,uVar7);
      ((int (*)())ParseOperand__AddSwizzle)(this,uVar5);
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 0x14));
  }
  uVar3 = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x28) = uVar3;
  return;
}

/* ParseOperand__ParseOperand_97bbb22c @ 0x97bbb22c (4 bytes) */
int ParseOperand__ParseOperand_97bbb22c(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  ParseOperand(this,param_1);
  return;
}

/* ParseOperand__ParseOperand_97bbb230 @ 0x97bbb230 (232 bytes) */
int ParseOperand__ParseOperand_97bbb230(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uchar uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  uVar7 = 0;
  *(undefined4 *)(this + 0x20) = 0;
  iVar2 = *(int *)(param_1 + 0x20);
  uVar1 = *(undefined2 *)(param_1 + 0x18);
  uVar3 = *(undefined4 *)(param_1 + 4);
  uVar6 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar3;
  *(undefined2 *)(this + 0x18) = uVar1;
  *(undefined4 *)(this + 0x24) = uVar6;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  if (iVar2 != 0) {
    do {
      uVar4 = GetDirectIndex(param_1,uVar7);
      AddDirectIndex(this,uVar4);
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 0x20));
  }
  uVar7 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    do {
      uVar5 = ParseOperand__GetSwizzle(param_1,uVar7);
      ((int (*)())ParseOperand__AddSwizzle)(this,uVar5);
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 0x14));
  }
  uVar3 = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x28) = uVar3;
  return;
}

/* ParseOperand___ParseOperand @ 0x97bbb318 (8 bytes) */
int ParseOperand___ParseOperand(this)
  unsigned char * this;
{
  ~ParseOperand(this);
  return;
}

/* ParseOperand___ParseOperand_97bbb320 @ 0x97bbb320 (8 bytes) */
int ParseOperand___ParseOperand_97bbb320(this)
  unsigned char * this;
{
  ~ParseOperand(this);
  return;
}

/* ParseOperand___ParseOperand_97bbb328 @ 0x97bbb328 (232 bytes) */
int ParseOperand___ParseOperand_97bbb328(this)
  unsigned char * this;
{
  unsigned char * this_00;
  
  this_00 = *(unsigned char **)this;
  if (this_00 == (unsigned char *)0x0) goto LAB_97bbb3cc;
  if ((*(int *)(this_00 + 0x3c) == 0) || (temporaryAllocator == (unsigned char *)0x0)) {
    if ((*(int *)(this_00 + 0x58) != 0) && (addressTempAllocator != (unsigned char *)0x0)) {
      AddressTempAllocator__releaseTemporary(addressTempAllocator,*(uint *)(this_00 + 0x28));
      goto LAB_97bbb3a4;
    }
  }
  else {
    ((int (*)())TemporaryAllocator__releaseTemporary)(temporaryAllocator,*(ushort *)(this_00 + 0x2c),*(uint *)(this_00 + 0x28));
LAB_97bbb3a4:
    this_00 = *(unsigned char **)this;
  }
  if ((*(int *)(this_00 + 0x50) == 0) && (this_00 != (unsigned char *)0x0)) {
    ((int (*)())ParseSymbol___ParseSymbol)(this_00);
    operator_delete(this_00);
  }
LAB_97bbb3cc:
  if (*(void **)(this + 0x1c) != (void *)0x0) {
    _free(*(void **)(this + 0x1c));
  }
  if (*(void **)(this + 0x10) != (void *)0x0) {
    _free(*(void **)(this + 0x10));
    return;
  }
  return;
}

/* ParseOperand__operator_ @ 0x97bbb410 (220 bytes) */
int ParseOperand__operator_(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uchar uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if (this != param_1) {
    uVar2 = *(undefined4 *)(param_1 + 4);
    uVar1 = *(undefined2 *)(param_1 + 0x18);
    uVar5 = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)this = *(undefined4 *)param_1;
    *(undefined4 *)(this + 4) = uVar2;
    *(undefined2 *)(this + 0x18) = uVar1;
    *(undefined4 *)(this + 0x24) = uVar5;
    ClearDirectIndex(this);
    uVar6 = 0;
    if (*(int *)(param_1 + 0x20) != 0) {
      do {
        uVar3 = GetDirectIndex(param_1,uVar6);
        AddDirectIndex(this,uVar3);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(param_1 + 0x20));
    }
    uVar6 = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      do {
        uVar4 = ParseOperand__GetSwizzle(param_1,uVar6);
        ((int (*)())ParseOperand__AddSwizzle)(this,uVar4);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(param_1 + 0x14));
    }
    uVar2 = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(this + 0x28) = uVar2;
  }
  return this;
}

/* operator___97bbb4ec @ 0x97bbb4ec (328 bytes) */
int operator___97bbb4ec(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((*(int *)param_1 == *(int *)param_2) && (*(int *)(param_1 + 4) == *(int *)(param_2 + 4))) {
    iVar1 = ((int (*)())ParseOperand__GetBaseSize)(param_1);
    iVar2 = ((int (*)())ParseOperand__GetBaseSize)(param_2);
    if (iVar1 == iVar2) {
      iVar1 = ((int (*)())ParseOperand__IsMatrix)(param_1);
      iVar2 = ((int (*)())ParseOperand__IsMatrix)(param_2);
      if ((((iVar1 == iVar2) && (*(int *)(param_1 + 0x28) == *(int *)(param_2 + 0x28))) &&
          (*(int *)(param_1 + 0x2c) == *(int *)(param_2 + 0x2c))) &&
         (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) {
        uVar3 = 0;
        if (*(int *)(param_1 + 0x20) != 0) {
          do {
            iVar1 = ((int (*)())ParseOperand__GetDirectIndex)(param_1,uVar3);
            iVar2 = ((int (*)())ParseOperand__GetDirectIndex)(param_2,uVar3);
            if (iVar1 != iVar2) {
              return 0;
            }
            uVar3 = 0;
            if (*(int *)(param_2 + 0x14) != 0) {
              do {
                iVar1 = ParseOperand__GetSwizzle(param_1,uVar3);
                iVar2 = ParseOperand__GetSwizzle(param_2,uVar3);
                if (iVar1 != iVar2) {
                  return 0;
                }
                uVar3 = uVar3 + 1;
              } while (uVar3 < *(uint *)(param_2 + 0x14));
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < *(uint *)(param_2 + 0x20));
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
int ParseOperand__AddDirectIndex(this, param_1)
  unsigned char * this;
  uint param_1;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  void *pvVar4;
  uint uVar5;
  
  uVar2 = *(uint *)(this + 0x20);
  if ((uVar2 & 3) == 0) {
    pvVar3 = _malloc(uVar2 * 4 + 0x10);
    _memset(pvVar3,0,*(int *)(this + 0x20) * 4 + 0x10);
    uVar2 = *(uint *)(this + 0x20);
    uVar5 = 0;
    if (uVar2 == 0) {
      pvVar4 = *(void **)(this + 0x1c);
    }
    else {
      pvVar4 = *(void **)(this + 0x1c);
      do {
        iVar1 = uVar5 * 4;
        uVar5 = uVar5 + 1;
        *(undefined4 *)(iVar1 + (int)pvVar3) = *(undefined4 *)(iVar1 + (int)pvVar4);
      } while (uVar5 < uVar2);
    }
    if (pvVar4 != (void *)0x0) {
      _free(pvVar4);
      uVar2 = *(uint *)(this + 0x20);
    }
    *(void **)(this + 0x1c) = pvVar3;
  }
  *(uint *)(uVar2 * 4 + *(int *)(this + 0x1c)) = param_1;
  *(int *)(this + 0x20) = *(int *)(this + 0x20) + 1;
  return;
}

/* ParseOperand__PopDirectIndex @ 0x97bbb750 (64 bytes) */
int ParseOperand__PopDirectIndex(this)
  unsigned char * this;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(this + 0x20);
  uVar2 = 0;
  *(int *)(this + 0x20) = iVar1 + -1;
  if (iVar1 + -1 != 0) {
    do {
      iVar1 = uVar2 * 4;
      uVar2 = uVar2 + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 0x1c)) =
           *(undefined4 *)(iVar1 + *(int *)(this + 0x1c) + 4);
    } while (uVar2 < *(uint *)(this + 0x20));
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
int ParseOperand__GetDirectIndex(this, param_1)
  unsigned char * this;
  uint param_1;
{
  return *(undefined4 *)(param_1 * 4 + *(int *)(this + 0x1c));
}

/* ParseOperand__GetAsDestVar @ 0x97bbb7b0 (716 bytes) */
int ParseOperand__GetAsDestVar(param_1)
  int param_1;
{
  undefined3 in_register_0000000c;
  uint *puVar1;
  short sVar4;
  uint uVar2;
  int iVar3;
  unsigned char * in_r4;
  int in_r5;
  short sVar5;
  uint uVar6;
  uint uVar7;
  
  puVar1 = (uint *)CONCAT31(in_register_0000000c,param_1);
  *puVar1 = 0;
  puVar1[1] = 0;
  sVar5 = 0;
  uVar6 = 0;
  sVar4 = GetScalerWidthForType(*(ushort *)(*(int *)in_r4 + 0x2c));
  *puVar1 = (sVar4 + -1) * 0x400 & 0xc00U | *puVar1 & 0xfffff04f | 0x6c;
  uVar2 = ((int (*)())ParseOperand__IsMatrix)(in_r4);
  *puVar1 = (uVar2 & 1) << 0xc | *puVar1 & 0xffffefff;
  iVar3 = ((int (*)())ParseOperand__IsMatrix)(in_r4);
  sVar4 = 0;
  if (iVar3 == 0) {
LAB_97bbb868:
    sVar5 = sVar4;
    uVar2 = *(uint *)(in_r4 + 0x20);
  }
  else {
    uVar2 = 0;
    if (*(int *)(in_r4 + 0x20) != 0) {
      sVar4 = GetDirectIndex(in_r4,0);
      uVar6 = 1;
      *puVar1 = *puVar1 & 0xffffefff;
      goto LAB_97bbb868;
    }
  }
  if (uVar6 == uVar2) {
    if (*(int *)(in_r4 + 0x14) == 0) {
      uVar2 = *puVar1;
      uVar6 = uVar2 >> 10 & 3;
      if (uVar6 == 1) {
LAB_97bbb950:
        uVar2 = uVar2 | 0x4000;
        *puVar1 = uVar2;
      }
      else if (uVar6 != 0) {
        if (uVar6 != 2) {
          if (uVar6 != 3) goto LAB_97bbba00;
          uVar2 = uVar2 | 0x10000;
          *puVar1 = uVar2;
        }
        uVar2 = uVar2 | 0x8000;
        *puVar1 = uVar2;
        goto LAB_97bbb950;
      }
      *puVar1 = uVar2 | 0x2000;
    }
    else {
      uVar2 = 0;
      if (*(int *)(in_r4 + 0x14) != 0) {
        do {
          iVar3 = ParseOperand__GetSwizzle(in_r4,uVar2);
          if (iVar3 == 1) {
            uVar6 = (uVar2 & 3) << 6 | *puVar1 & 0xffffff3f | 0x4000;
LAB_97bbb900:
            *puVar1 = uVar6;
          }
          else {
            if (1 < iVar3) {
              if (iVar3 == 2) {
                uVar6 = (uVar2 & 3) << 4 | *puVar1 & 0xffffffcf | 0x8000;
              }
              else {
                if (iVar3 != 3) goto LAB_97bbb904;
                uVar6 = (uVar2 & 3) << 2 | *puVar1 & 0xfffffff3 | 0x10000;
              }
              goto LAB_97bbb900;
            }
            if (iVar3 == 0) {
              uVar6 = (uVar2 & 3) << 8 | *puVar1 & 0xfffffcff | 0x2000;
              goto LAB_97bbb900;
            }
          }
LAB_97bbb904:
          uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint *)(in_r4 + 0x14));
      }
    }
  }
  else {
    uVar7 = uVar6;
    if (uVar6 < uVar2) {
      do {
        iVar3 = GetDirectIndex(in_r4,uVar7);
        if (iVar3 == 1) {
          uVar2 = (uVar7 - uVar6) * 0x40 & 0xc0 | *puVar1 & 0xffffff3f | 0x4000;
LAB_97bbb9ec:
          *puVar1 = uVar2;
          uVar2 = *(uint *)(in_r4 + 0x20);
        }
        else {
          if (iVar3 == 0) {
            uVar2 = (uVar7 - uVar6) * 0x100 & 0x300 | *puVar1 & 0xfffffcff | 0x2000;
            goto LAB_97bbb9ec;
          }
          if (iVar3 == 2) {
            uVar2 = (uVar7 - uVar6) * 0x10 & 0x30 | *puVar1 & 0xffffffcf | 0x8000;
            goto LAB_97bbb9ec;
          }
          if (iVar3 == 3) {
            uVar2 = (uVar7 - uVar6) * 4 & 0xc | *puVar1 & 0xfffffff3 | 0x10000;
            goto LAB_97bbb9ec;
          }
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar2);
    }
  }
LAB_97bbba00:
  if (*(char *)**(undefined4 **)in_r4 == '\0') {
    uVar2 = *puVar1;
    iVar3 = 1;
  }
  else {
    if (*(char *)**(undefined4 **)in_r4 != '\x04') goto LAB_97bbba4c;
    uVar2 = *puVar1;
    iVar3 = 3;
  }
  *puVar1 = iVar3 << 0x11 | uVar2 & 0xfff1ffff;
  *(short *)((int)puVar1 + 6) = *(short *)(**(int **)in_r4 + 0x12) + sVar5;
LAB_97bbba4c:
  if (in_r5 != 0) {
    puVar1[1] = puVar1[1] & 0x800fffff | 0x80000000;
  }
  return puVar1;
}

/* ParseOperand__GetAsSourceVar @ 0x97bbba7c (676 bytes) */
int ParseOperand__GetAsSourceVar(param_1)
  int param_1;
{
  byte bVar1;
  uint uVar2;
  undefined3 in_register_0000000c;
  uint *puVar3;
  ushort uVar5;
  int iVar4;
  unsigned char * in_r4;
  int in_r5;
  uint uVar6;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  short sVar7;
  
  puVar3 = (uint *)CONCAT31(in_register_0000000c,param_1);
  *puVar3 = 0;
  puVar3[1] = 0;
  uVar6 = 0;
  sVar7 = 0;
  uVar5 = GetScalerWidthForType(*(ushort *)(*(int *)in_r4 + 0x2c));
  uVar9 = 0;
  *puVar3 = *puVar3 & 0xff85ffff | 0xd8000;
  uVar2 = *(uint *)(in_r4 + 0x14);
  if (uVar2 != 0) {
    do {
      if (uVar9 == 1) {
        uVar2 = ParseOperand__GetSwizzle(in_r4,1);
        uVar2 = (uVar2 & 3) << 0x13 | *puVar3 & 0xffe7ffff;
LAB_97bbbb6c:
        *puVar3 = uVar2;
        uVar2 = *(uint *)(in_r4 + 0x14);
      }
      else {
        if (uVar9 == 0) {
          uVar2 = ParseOperand__GetSwizzle(in_r4,0);
          uVar2 = (uVar2 & 3) << 0x15 | *puVar3 & 0xff9fffff;
          goto LAB_97bbbb6c;
        }
        if (uVar9 == 2) {
          uVar2 = ParseOperand__GetSwizzle(in_r4,2);
          uVar2 = (uVar2 & 3) << 0x11 | *puVar3 & 0xfff9ffff;
          goto LAB_97bbbb6c;
        }
        if (uVar9 == 3) {
          uVar2 = ParseOperand__GetSwizzle(in_r4,3);
          uVar2 = (uVar2 & 3) << 0xf | *puVar3 & 0xfffe7fff;
          goto LAB_97bbbb6c;
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar2);
  }
  iVar4 = ((int (*)())ParseOperand__IsMatrix)(in_r4);
  uVar8 = 1;
  if (iVar4 != 0) {
    uVar8 = uVar5;
  }
  if (uVar5 == 1) {
    iVar4 = *(int *)(in_r4 + 0x20);
    if (iVar4 == 0) {
      uVar2 = *puVar3 >> 0x15 & 3;
      *puVar3 = uVar2 << 0x13 | uVar2 << 0x11 | uVar2 << 0xf | *puVar3 & 0xffe07fff;
      goto LAB_97bbbbc4;
    }
  }
  else {
LAB_97bbbbc4:
    iVar4 = *(int *)(in_r4 + 0x20);
  }
  iVar10 = iVar4;
  if (iVar4 != 0) {
    while( true ) {
      if (uVar8 < 2) {
        if (1 < uVar5) {
          uVar5 = 1;
        }
      }
      else {
        uVar8 = 1;
      }
      uVar2 = GetDirectIndex(in_r4,iVar4 - iVar10);
      if (uVar5 < 2) {
        *puVar3 = (uVar2 & 3) << 0x15 |
                  (uVar2 & 3) << 0x13 |
                  (uVar2 & 3) << 0x11 | (uVar2 & 3) << 0xf | *puVar3 & 0xff807fff;
        uVar2 = uVar6;
      }
      sVar7 = (short)uVar2;
      if (iVar10 + -1 == 0) break;
      iVar4 = *(int *)(in_r4 + 0x20);
      uVar6 = uVar2;
      iVar10 = iVar10 + -1;
    }
  }
  bVar1 = *(byte *)**(undefined4 **)in_r4;
  if (bVar1 == 2) {
    uVar6 = *puVar3 & 0xfc7fffff;
  }
  else {
    if (bVar1 < 3) {
      if (bVar1 != 0) goto LAB_97bbbcb0;
      uVar6 = *puVar3;
      iVar4 = 1;
    }
    else if (bVar1 == 3) {
      uVar6 = *puVar3;
      iVar4 = 2;
    }
    else {
      if (bVar1 != 4) goto LAB_97bbbcb0;
      uVar6 = *puVar3;
      iVar4 = 3;
    }
    uVar6 = iVar4 << 0x17 | uVar6 & 0xfc7fffff;
  }
  *puVar3 = uVar6;
  *(short *)((int)puVar3 + 6) = *(short *)(**(int **)in_r4 + 0x12) + sVar7;
LAB_97bbbcb0:
  *puVar3 = (uint)(uVar8 != 1) * 0x4000 | *puVar3 & 0xffffbfff;
  iVar4 = ((int (*)())ParseOperand__GetLogicalSize)(in_r4);
  uVar9 = *puVar3;
  uVar6 = (iVar4 + -1) * 0x1000 & 0x3000;
  *puVar3 = uVar6 | uVar9 & 0xffffcfff;
  uVar2 = (*(uint *)(in_r4 + 0x28) & 1) << 0x1b;
  *puVar3 = uVar2 | uVar6 | uVar9 & 0xf7ffcfff;
  if (in_r5 != 0) {
    *puVar3 = uVar2 | uVar6 | uVar9 & 0x87ffcfff | 0x80000000;
    *(undefined1 *)((int)puVar3 + 3) = 0;
  }
  return puVar3;
}

/* ParseOperand__IsMatrix @ 0x97bbbd20 (52 bytes) */
int ParseOperand__IsMatrix(this)
  unsigned char * this;
{
  ushort uVar1;
  
  if (*(int *)this == 0) {
    uVar1 = *(ushort *)(this + 0x18);
  }
  else {
    uVar1 = *(ushort *)(*(int *)this + 0x2c);
  }
  return uVar1 - 0x8b5a < 3;
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
      iVar1 = GetScalerWidthForType(*(ushort *)(*(int *)this + 0x2c));
    }
  }
  return iVar1;
}

/* ParseOperand__GetLogicalSize @ 0x97bbbda0 (132 bytes) */
int ParseOperand__GetLogicalSize(this)
  unsigned char * this;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)this == 0) {
    uVar1 = 1;
    if (*(int *)(this + 0x20) == 0) {
      uVar1 = ((int (*)())ParseOperand__GetBaseSize)(this);
    }
  }
  else {
    uVar3 = *(uint *)(this + 0x20);
    if (((uVar3 == 1) && (iVar2 = ((int (*)())ParseOperand__IsMatrix)(this), iVar2 == 0)) || (1 < uVar3)) {
      uVar1 = 1;
    }
    else {
      uVar1 = ((int (*)())ParseOperand__GetBaseSize)(this);
    }
  }
  return uVar1;
}

/* ParseOperand__isWriteable @ 0x97bbbe24 (132 bytes) */
int ParseOperand__isWriteable(this)
  unsigned char * this;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)this != 0) {
    uVar1 = (**(code **)(**(int **)(*(int *)this + 0xc) + 0x24))();
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
int ParseOperand__AddSwizzle(this, param_1)
  unsigned char * this;
  int param_1;
{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  void *pvVar4;
  
  uVar1 = *(uint *)(this + 0x14);
  if ((uVar1 & 3) == 0) {
    pvVar2 = _malloc(uVar1 + 4);
    _memset(pvVar2,0,*(int *)(this + 0x14) + 4);
    uVar1 = *(uint *)(this + 0x14);
    uVar3 = 0;
    if (uVar1 == 0) {
      pvVar4 = *(void **)(this + 0x10);
    }
    else {
      pvVar4 = *(void **)(this + 0x10);
      do {
        *(undefined1 *)((int)pvVar2 + uVar3) = *(undefined1 *)((int)pvVar4 + uVar3);
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < uVar1);
    }
    if (pvVar4 != (void *)0x0) {
      _free(pvVar4);
      uVar1 = *(uint *)(this + 0x14);
    }
    *(void **)(this + 0x10) = pvVar2;
  }
  *(uchar *)(*(int *)(this + 0x10) + uVar1) = param_1;
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

