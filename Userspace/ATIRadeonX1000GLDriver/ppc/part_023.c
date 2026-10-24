#include "decls.h"

/* Block__bypassAndDetach @ 0xe9730 (76 bytes) */
int Block__bypassAndDetach(block, predBlock, succBlock)
  int block;
  undefined4 predBlock;
  int succBlock;
{
  if (*(int *)(succBlock + 0xf0) == block) {
    *(undefined4 *)(succBlock + 0xf0) = *(undefined4 *)(block + 0xf0);
  }
  Block__bypass(block,predBlock,succBlock);
  Block__detach(block);
  return 1;
}

/* FUN_000e977c @ 0xe977c (404 bytes) */
int FUN_000e977c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint loopIndex;
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint loopIndex2;
  uint *puVar8;
  
  loopIndex2 = 0;
  puVar8 = *(uint **)(param_1 + 0xd0);
  iVar5 = 0;
  for (loopIndex = 1; loopIndex <= puVar8[1]; loopIndex = loopIndex + 1) {
    if (*(int *)(iVar5 + puVar8[2]) != 0) {
      if (param_2 == *(int *)(iVar5 + puVar8[2])) {
        if (loopIndex2 < *puVar8) {
          uVar4 = puVar8[1];
          if (uVar4 <= loopIndex2) {
            _memset(uVar4 * 4 + puVar8[2],0,(loopIndex2 - uVar4) * 4 + 4);
            puVar8[1] = loopIndex2 + 1;
          }
          piVar2 = (int *)(loopIndex2 * 4 + puVar8[2]);
        }
        else {
          piVar2 = (int *)Vector__elementRefGrow(puVar8,loopIndex2);
        }
        *piVar2 = param_3;
        break;
      }
      loopIndex2 = loopIndex2 + 1;
    }
    iVar5 = iVar5 + 4;
  }
  iVar5 = *(int *)(param_2 + 0xd4);
  iVar3 = 0;
  loopIndex = 1;
  iVar6 = 0;
  do {
    if (*(uint *)(iVar5 + 4) < loopIndex) {
LAB_000e9874:
      loopIndex = 1;
      iVar5 = 0;
      while( true ) {
        if (*(uint *)(*(int *)(param_3 + 0xd4) + 4) < loopIndex) {
          FUN_000e8d5c(param_3,param_1);
          return;
        }
        iVar3 = *(int *)(*(int *)(*(int *)(param_3 + 0xd4) + 8) + iVar5);
        if ((iVar3 != 0) && (param_1 == iVar3)) break;
        loopIndex = loopIndex + 1;
        iVar5 = iVar5 + 4;
      }
      return;
    }
    iVar1 = *(int *)(*(int *)(iVar5 + 8) + iVar6);
    if (iVar1 != 0) {
      if (param_1 == iVar1) {
        Vector__removeAt(iVar5,iVar3);
        goto LAB_000e9874;
      }
      iVar3 = iVar3 + 1;
    }
    loopIndex = loopIndex + 1;
    iVar6 = iVar6 + 4;
  } while( true );
}

/* FUN_000e9910 @ 0xe9910 (56 bytes) */
int FUN_000e9910(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())FUN_000e977c)(param_1,param_2,param_3);
  return Block__connect(param_4,param_2);
}

/* FUN_000e9948 @ 0xe9948 (404 bytes) */
int FUN_000e9948(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint loopIndex;
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint loopIndex2;
  uint *puVar8;
  
  loopIndex2 = 0;
  puVar8 = *(uint **)(param_1 + 0xd4);
  iVar5 = 0;
  for (loopIndex = 1; loopIndex <= puVar8[1]; loopIndex = loopIndex + 1) {
    if (*(int *)(iVar5 + puVar8[2]) != 0) {
      if (param_2 == *(int *)(iVar5 + puVar8[2])) {
        if (loopIndex2 < *puVar8) {
          uVar4 = puVar8[1];
          if (uVar4 <= loopIndex2) {
            _memset(uVar4 * 4 + puVar8[2],0,(loopIndex2 - uVar4) * 4 + 4);
            puVar8[1] = loopIndex2 + 1;
          }
          piVar2 = (int *)(loopIndex2 * 4 + puVar8[2]);
        }
        else {
          piVar2 = (int *)Vector__elementRefGrow(puVar8,loopIndex2);
        }
        *piVar2 = param_3;
        break;
      }
      loopIndex2 = loopIndex2 + 1;
    }
    iVar5 = iVar5 + 4;
  }
  iVar5 = *(int *)(param_2 + 0xd0);
  iVar3 = 0;
  loopIndex = 1;
  iVar6 = 0;
  do {
    if (*(uint *)(iVar5 + 4) < loopIndex) {
LAB_000e9a40:
      loopIndex = 1;
      iVar5 = 0;
      while( true ) {
        if (*(uint *)(*(int *)(param_3 + 0xd0) + 4) < loopIndex) {
          FUN_000e8dd4(param_3,param_1);
          return;
        }
        iVar3 = *(int *)(*(int *)(*(int *)(param_3 + 0xd0) + 8) + iVar5);
        if ((iVar3 != 0) && (param_1 == iVar3)) break;
        loopIndex = loopIndex + 1;
        iVar5 = iVar5 + 4;
      }
      return;
    }
    iVar1 = *(int *)(*(int *)(iVar5 + 8) + iVar6);
    if (iVar1 != 0) {
      if (param_1 == iVar1) {
        Vector__removeAt(iVar5,iVar3);
        goto LAB_000e9a40;
      }
      iVar3 = iVar3 + 1;
    }
    loopIndex = loopIndex + 1;
    iVar6 = iVar6 + 4;
  } while( true );
}

/* FUN_000e9adc @ 0xe9adc (292 bytes) */
int FUN_000e9adc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  uint predecessorIndexResult;
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  
  uVar1 = FUN_000e7fe0(param_1,param_2);
  puVar4 = *(uint **)(param_1 + 0xd0);
  if (uVar1 < *puVar4) {
    uVar2 = puVar4[1];
    if (uVar2 <= uVar1) {
      _memset(uVar2 * 4 + puVar4[2],0,(uVar1 - uVar2) * 4 + 4);
      puVar4[1] = uVar1 + 1;
    }
    puVar3 = (undefined4 *)(uVar1 * 4 + puVar4[2]);
  }
  else {
    puVar3 = (undefined4 *)Vector__elementRefGrow(puVar4,uVar1);
  }
  *puVar3 = param_3;
  predecessorIndexResult = Block__predecessorIndex(param_2,param_1);
  puVar4 = *(uint **)(param_2 + 0xd4);
  if (predecessorIndexResult < *puVar4) {
    uVar2 = puVar4[1];
    if (uVar2 <= predecessorIndexResult) {
      _memset(uVar2 * 4 + puVar4[2],0,(predecessorIndexResult - uVar2) * 4 + 4);
      puVar4[1] = predecessorIndexResult + 1;
    }
    puVar3 = (undefined4 *)(predecessorIndexResult * 4 + puVar4[2]);
  }
  else {
    puVar3 = (undefined4 *)Vector__elementRefGrow(puVar4,predecessorIndexResult);
  }
  *puVar3 = param_3;
  FUN_000e8d5c(param_3,param_1);
  return FUN_000e8dd4(param_3,param_2);
}

/* Block__recordDefinition @ 0xe9c00 (200 bytes) */
int Block__recordDefinition(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int *piVar1;
  uint loopIndex;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  puVar3 = *(uint **)(param_1 + 0xc4);
  uVar4 = puVar3[1];
  if (0 < (int)uVar4) {
    loopIndex = 0;
    uVar5 = uVar4;
    do {
      piVar1 = (int *)0x0;
      if (loopIndex < uVar4) {
        piVar1 = (int *)(loopIndex * 4 + puVar3[2]);
      }
      if (param_2 == *piVar1) goto LAB_000e9ca8;
      loopIndex = loopIndex + 1;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  if (uVar4 < *puVar3) {
    _memset(uVar4 * 4 + puVar3[2],0,4);
    piVar1 = (int *)(uVar4 * 4 + puVar3[2]);
    puVar3[1] = uVar4 + 1;
  }
  else {
    piVar1 = (int *)Vector__elementRefGrow(puVar3,uVar4);
  }
  *piVar1 = param_2;
LAB_000e9ca8:
  return VReg__pushDefinition(param_2,*(undefined4 *)(param_1 + 0xb0),param_3);
}

/* FUN_000e9cc8 @ 0xe9cc8 (160 bytes) */
int FUN_000e9cc8(param_1)
  int param_1;
{
  byte bVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x144) == 0) {
    piVar2 = *(int **)(*(int *)(*(int *)(param_1 + 0x148) + 0xa4) + 0x18);
    if (*piVar2 == 0) {
      piVar2 = (int *)Vector__elementRefGrow(piVar2,0);
    }
    else {
      if (piVar2[1] == 0) {
        *(undefined4 *)piVar2[2] = 0;
        piVar2[1] = 1;
      }
      piVar2 = (int *)piVar2[2];
    }
    bVar1 = *(byte *)(*piVar2 + 0x15c);
    if ((((bVar1 & 1) != 0) && ((bVar1 & 2) != 0)) && ((bVar1 & 4) != 0)) {
      return 1;
    }
  }
  return 0;
}

/* Block__ctor_e9d68 @ 0xe9d68 (252 bytes) */
int Block__ctor_e9d68(this, param_2)
  undefined4 *this;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  this[1] = 0;
  this[2] = 0;
  uVar1 = *(undefined4 *)(param_2 + 0xc);
  *this = &PTR_FUN_001e9b08;
  this[3] = uVar1;
  DListNode__init(this + 0x24);
  iVar2 = *(int *)(param_2 + 0xa8);
  uVar1 = *(undefined4 *)(param_2 + 0xac);
  this[0x2a] = iVar2;
  this[0x2b] = uVar1;
  iVar4 = *(int *)(iVar2 + 0x32c);
  this[0x2c] = iVar4;
  *(int *)(iVar2 + 0x32c) = iVar4 + 1;
  uVar3 = *(undefined4 *)(param_2 + 0x110);
  uVar1 = *(undefined4 *)(param_2 + 0xc0);
  uVar5 = *(undefined4 *)(param_2 + 0xdc);
  uVar6 = *(undefined4 *)(param_2 + 0x10c);
  this[0x2e] = *(undefined4 *)(param_2 + 0xb8);
  this[0x30] = uVar1;
  this[0x37] = uVar5;
  this[0x3a] = 0x7fffffff;
  this[0x42] = 0;
  this[0x43] = uVar6;
  this[0x44] = uVar3;
  this[0x46] = 0xffffffff;
  this[0x39] = 0x7fffffff;
  this[0x3b] = 0;
  this[0x3c] = 0;
  this[0x3f] = 0;
  this[0x40] = 0;
  this[0x41] = 0;
  FUN_000e8a08(this);
  FUN_000e8938(this);
  uVar1 = FUN_000e8124(this[0x2b],extraout_r4,in_r5,in_r6,in_r7,uVar3,uVar5);
  this[0x2d] = uVar1;
  return;
}

/* Block__clone @ 0xe9e88 (64 bytes) */
int Block__clone(this)
  int this;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(*(int *)(this + 0xa8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x130);
  *allocation = arena;
  ((int (*)())Block__ctor_e9d68)(allocation + 1,this);
  return allocation + 1;
}

/* Block__ctor_e9f00 @ 0xe9f00 (252 bytes) */
int Block__ctor_e9f00(this, param_2)
  undefined4 *this;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  this[1] = 0;
  this[2] = 0;
  uVar1 = *(undefined4 *)(param_2 + 0xc);
  *this = &PTR_FUN_001e9b08;
  this[3] = uVar1;
  DListNode__init(this + 0x24);
  iVar2 = *(int *)(param_2 + 0xa8);
  uVar1 = *(undefined4 *)(param_2 + 0xac);
  this[0x2a] = iVar2;
  this[0x2b] = uVar1;
  iVar4 = *(int *)(iVar2 + 0x32c);
  this[0x2c] = iVar4;
  *(int *)(iVar2 + 0x32c) = iVar4 + 1;
  uVar3 = *(undefined4 *)(param_2 + 0x110);
  uVar1 = *(undefined4 *)(param_2 + 0xc0);
  uVar5 = *(undefined4 *)(param_2 + 0xdc);
  uVar6 = *(undefined4 *)(param_2 + 0x10c);
  this[0x2e] = *(undefined4 *)(param_2 + 0xb8);
  this[0x30] = uVar1;
  this[0x37] = uVar5;
  this[0x3a] = 0x7fffffff;
  this[0x42] = 0;
  this[0x43] = uVar6;
  this[0x44] = uVar3;
  this[0x46] = 0xffffffff;
  this[0x39] = 0x7fffffff;
  this[0x3b] = 0;
  this[0x3c] = 0;
  this[0x3f] = 0;
  this[0x40] = 0;
  this[0x41] = 0;
  FUN_000e8a08(this);
  FUN_000e8938(this);
  uVar1 = FUN_000e8124(this[0x2b],extraout_r4,in_r5,in_r6,in_r7,uVar3,uVar5);
  this[0x2d] = uVar1;
  return;
}

/* Block__ctor_ea020 @ 0xea020 (260 bytes) */
int Block__ctor_ea020(this, compiler)
  undefined4 *this;
  int compiler;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 extraout_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar3;
  
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  *this = &PTR_FUN_001e9b08;
  DListNode__init(this + 0x24);
  this[0x2a] = compiler;
  this[0x2b] = 0;
  iVar3 = *(int *)(compiler + COMP_nextBlockId);
  this[0x2c] = iVar3;
  *(int *)(compiler + COMP_nextBlockId) = iVar3 + 1;
  this[0x3a] = 0x7fffffff;
  this[0x46] = 0xffffffff;
  this[0x4a] = 0;
  this[0x2e] = 0;
  this[0x30] = 0xffffffff;
  this[0x37] = 0;
  this[0x39] = 0x7fffffff;
  this[0x3b] = 0;
  this[0x3c] = 0;
  this[0x3f] = 0;
  this[0x40] = 0;
  this[0x41] = 0;
  this[0x42] = 0;
  this[0x43] = 0;
  this[0x44] = 0;
  this[0x45] = 0;
  FUN_000e8a08(this);
  FUN_000e8938(this);
  iVar3 = 0x20;
  puVar1 = this;
  do {
    puVar1[4] = 0;
    puVar1 = puVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar2 = FUN_000e8124(*(undefined4 *)(this[0x2a] + 0x6c4),extraout_r4,in_r5,in_r6,in_r7,in_r8,
                       0x20);
  this[0x2d] = uVar2;
  return;
}

/* Block__ctor_ea148 @ 0xea148 (260 bytes) */
int Block__ctor_ea148(this, compiler)
  undefined4 *this;
  int compiler;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 extraout_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar3;
  
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  *this = &PTR_FUN_001e9b08;
  DListNode__init(this + 0x24);
  this[0x2a] = compiler;
  this[0x2b] = 0;
  iVar3 = *(int *)(compiler + COMP_nextBlockId);
  this[0x2c] = iVar3;
  *(int *)(compiler + COMP_nextBlockId) = iVar3 + 1;
  this[0x3a] = 0x7fffffff;
  this[0x46] = 0xffffffff;
  this[0x4a] = 0;
  this[0x2e] = 0;
  this[0x30] = 0xffffffff;
  this[0x37] = 0;
  this[0x39] = 0x7fffffff;
  this[0x3b] = 0;
  this[0x3c] = 0;
  this[0x3f] = 0;
  this[0x40] = 0;
  this[0x41] = 0;
  this[0x42] = 0;
  this[0x43] = 0;
  this[0x44] = 0;
  this[0x45] = 0;
  FUN_000e8a08(this);
  FUN_000e8938(this);
  iVar3 = 0x20;
  puVar1 = this;
  do {
    puVar1[4] = 0;
    puVar1 = puVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar2 = FUN_000e8124(*(undefined4 *)(this[0x2a] + 0x6c4),extraout_r4,in_r5,in_r6,in_r7,in_r8,
                       0x20);
  this[0x2d] = uVar2;
  return;
}

/* Block__dtor_ea270 @ 0xea270 (260 bytes) */
int Block__dtor_ea270(this)
  undefined4 *this;
{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = this[0x35];
  *this = &PTR_FUN_001e9b08;
  if (iVar2 != 0) {
    Arena__free(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = this[0x34];
  if (iVar2 != 0) {
    Arena__free(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = this[0x3d];
  if (iVar2 != 0) {
    Arena__free(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = this[0x3e];
  if (iVar2 != 0) {
    Arena__free(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = this[0x31];
  if (iVar2 != 0) {
    Arena__free(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  DListNode__clear(this + 0x24);
  puVar1 = PTR_DAT_001e8b48 + 8;
  this[0x24] = puVar1;
  this[0x27] = puVar1;
  *this = puVar1;
  return;
}

/* AnyBlock__ctor_ea3c0 @ 0xea3c0 (136 bytes) */
int AnyBlock__ctor_ea3c0(this, compiler)
  undefined4 *this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  ((int (*)())Block__ctor_ea148)(this,compiler);
  *this = PTR_DAT_001e8b58 + 8;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  allocation[1] = 2;
  *allocation = arena;
  allocation[2] = 0;
  allocation[4] = arena;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  this[0x4b] = allocation + 1;
  return;
}

/* AnyBlock__ctor_ea478 @ 0xea478 (136 bytes) */
int AnyBlock__ctor_ea478(this, compiler)
  undefined4 *this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  ((int (*)())Block__ctor_ea148)(this,compiler);
  *this = PTR_DAT_001e8b58 + 8;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  allocation[1] = 2;
  *allocation = arena;
  allocation[2] = 0;
  allocation[4] = arena;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  this[0x4b] = allocation + 1;
  return;
}

/* IfHeader__ctor_ea530 @ 0xea530 (140 bytes) */
int IfHeader__ctor_ea530(this, compiler)
  undefined4 *this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  undefined4 *puVar3;
  
  ((int (*)())Block__ctor_ea148)(this,compiler);
  *this = &PTR_FUN_001e9cc0;
  this[0x50] = 0;
  this[0x52] = 1;
  this[0x4c] = 0;
  this[0x4d] = 0;
  this[0x4e] = 0;
  this[0x51] = 1;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x130);
  puVar3 = allocation + 1;
  *allocation = arena;
  ((int (*)())Block__ctor_ea020)(puVar3,compiler);
  this[0x4d] = puVar3;
  return Block__connect(this,puVar3);
}

/* IfHeader__ctor_ea600 @ 0xea600 (140 bytes) */
int IfHeader__ctor_ea600(this, compiler)
  undefined4 *this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  undefined4 *puVar3;
  
  ((int (*)())Block__ctor_ea148)(this,compiler);
  *this = &PTR_FUN_001e9cc0;
  this[0x50] = 0;
  this[0x52] = 1;
  this[0x4c] = 0;
  this[0x4d] = 0;
  this[0x4e] = 0;
  this[0x51] = 1;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x130);
  puVar3 = allocation + 1;
  *allocation = arena;
  ((int (*)())Block__ctor_ea020)(puVar3,compiler);
  this[0x4d] = puVar3;
  return Block__connect(this,puVar3);
}

/* IfHeader__ctor_ea6d0 @ 0xea6d0 (268 bytes) */
int IfHeader__ctor_ea6d0(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  ((int (*)())Block__ctor_ea148)(this,compiler);
  this[0x4c] = param_2;
  *this = &PTR_FUN_001e9cc0;
  this[0x50] = param_3;
  this[0x52] = 1;
  this[0x55] = 0;
  this[0x4d] = param_4;
  this[0x4e] = 0;
  this[0x51] = 1;
  this[0x54] = 0;
  if (param_4 == 0) {
    arena = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x130);
    *allocation = arena;
    ((int (*)())Block__ctor_ea020)(allocation + 1,compiler);
    this[0x4d] = allocation + 1;
  }
  Block__connect(this,this[0x4d]);
  Block__appendInst(this,this[0x4c]);
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  *allocation = arena;
  ((int (*)())Block__ctor_ea148)(allocation + 1,compiler);
  allocation[0x4c] = this;
  allocation[1] = &PTR_FUN_001e9d70;
  this[0x4f] = allocation + 1;
  return;
}

/* PostLoopFooter__ctor_ea828 @ 0xea828 (580 bytes) */
int PostLoopFooter__ctor_ea828(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int compiler;
{
  undefined4 arena;
  undefined4 *allocation;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  ((int (*)())Block__ctor_ea148)(this,compiler);
  this[0x50] = 0;
  *this = &PTR_FUN_001e9bb8;
  this[0x53] = param_3;
  this[0x4b] = 0;
  this[0x4d] = 0;
  this[0x4e] = 0;
  this[0x4f] = 0;
  this[0x51] = param_4;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  *allocation = arena;
  ((int (*)())Block__ctor_ea148)(allocation + 1,compiler);
  allocation[0x4c] = this;
  allocation[1] = &PTR_FUN_001e9c10;
  this[0x54] = allocation + 1;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  puVar6 = allocation + 1;
  *allocation = arena;
  ((int (*)())Block__ctor_ea148)(puVar6,compiler);
  allocation[0x4c] = this;
  *puVar6 = &PTR_FUN_001e9c68;
  this[0x55] = puVar6;
  Block__connect(this[0x54],this);
  if (param_4 == 0) {
    uVar5 = IRInst__create(0x81,compiler);
    this[0x52] = uVar5;
    iVar2 = IRInst__getOperandRecord(uVar5,0);
    *(undefined4 *)(iVar2 + 8) = param_2;
    *(undefined4 *)(iVar2 + 0xc) = 0x27;
    uVar5 = FUN_00127608(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3ac),4,param_2,0);
    IRInst__setOperandRef(this[0x52],1,uVar5);
  }
  else {
    arena = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    puVar6 = allocation + 1;
    *allocation = arena;
    IRInst__ctor_10502c(puVar6,0xfd,compiler);
    this[0x52] = puVar6;
    iVar2 = IRInst__getOperandRecord(puVar6,0);
    *(undefined4 *)(iVar2 + 8) = param_2;
    *(undefined4 *)(iVar2 + 0xc) = 0x27;
    iVar2 = FUN_00127608(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3ac),4,0,0);
    piVar3 = *(int **)(iVar2 + 0x18);
    if (*piVar3 == 0) {
      piVar3 = (int *)Vector__elementRefGrow(piVar3,0);
    }
    else {
      if (piVar3[1] == 0) {
        *(undefined4 *)piVar3[2] = 0;
        piVar3[1] = 1;
      }
      piVar3 = (int *)piVar3[2];
    }
    iVar4 = *piVar3;
    *(undefined4 *)(iVar4 + 0x20) = 0xffffffff;
    *(byte *)(iVar4 + 0x15c) = *(byte *)(iVar4 + 0x15c) | 1;
    *(undefined4 *)(iVar4 + 0x1c) = 3;
    IRInst__setOperandRef(this[0x52],1,iVar2);
    uVar5 = DAT_001aa7fc;
    iVar2 = IRInst__getOperandRecord(this[0x52],1);
    *(undefined4 *)(iVar2 + 0x10) = uVar5;
  }
  Block__appendInst(this,this[0x52]);
  return;
}

/* ExitBlock__ctor_eaae8 @ 0xeaae8 (68 bytes) */
int ExitBlock__ctor_eaae8(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())Block__ctor_ea148)(this,param_2);
  *this = &PTR_FUN_001e9ed0;
  return;
}

/* ExitBlock__ctor_eab2c @ 0xeab2c (68 bytes) */
int ExitBlock__ctor_eab2c(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())Block__ctor_ea148)(this,param_2);
  *this = &PTR_FUN_001e9ed0;
  return;
}

/* EntryBlock__ctor_eab70 @ 0xeab70 (76 bytes) */
int EntryBlock__ctor_eab70(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())Block__ctor_ea148)(this,param_2);
  this[0x4b] = this[0x32];
  *this = &PTR_FUN_001e9f28;
  return;
}

/* EntryBlock__ctor_eabbc @ 0xeabbc (76 bytes) */
int EntryBlock__ctor_eabbc(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())Block__ctor_ea148)(this,param_2);
  this[0x4b] = this[0x32];
  *this = &PTR_FUN_001e9f28;
  return;
}

/* BreakOrContinueBlock__ctor_eac08 @ 0xeac08 (88 bytes) */
int BreakOrContinueBlock__ctor_eac08(this, param_2)
  undefined4 *this;
  int param_2;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())Block__ctor_e9f00)(this,param_2);
  uVar2 = *(undefined4 *)(param_2 + 300);
  puVar1 = PTR_DAT_001e8b54 + 8;
  this[0x4c] = *(undefined4 *)(param_2 + 0x130);
  *this = puVar1;
  this[0x4b] = uVar2;
  return;
}

/* BreakOrContinueBlock__ctor_eac60 @ 0xeac60 (88 bytes) */
int BreakOrContinueBlock__ctor_eac60(this, param_2)
  undefined4 *this;
  int param_2;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())Block__ctor_e9f00)(this,param_2);
  uVar2 = *(undefined4 *)(param_2 + 300);
  puVar1 = PTR_DAT_001e8b54 + 8;
  this[0x4c] = *(undefined4 *)(param_2 + 0x130);
  *this = puVar1;
  this[0x4b] = uVar2;
  return;
}

/* PostLoopFooter__ctor_eacb8 @ 0xeacb8 (80 bytes) */
int PostLoopFooter__ctor_eacb8(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())Block__ctor_e9f00)(this,param_2);
  this[3] = this[3] | 0x20;
  *this = &PTR_FUN_001e9c68;
  return;
}

/* PostLoopFooter__clone @ 0xead08 (64 bytes) */
int PostLoopFooter__clone(this)
  int this;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(*(int *)(this + 0xa8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  *allocation = arena;
  ((int (*)())PostLoopFooter__ctor_eacb8)(allocation + 1,this);
  return allocation + 1;
}

/* PostLoopFooter__ctor_ead80 @ 0xead80 (80 bytes) */
int PostLoopFooter__ctor_ead80(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())Block__ctor_e9f00)(this,param_2);
  this[3] = this[3] | 0x20;
  *this = &PTR_FUN_001e9c68;
  return;
}

/* LoopFooter__ctor_eadd0 @ 0xeadd0 (80 bytes) */
int LoopFooter__ctor_eadd0(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())Block__ctor_e9f00)(this,param_2);
  this[3] = this[3] | 0x20;
  *this = &PTR_FUN_001e9c10;
  return;
}

/* LoopFooter__clone @ 0xeae20 (64 bytes) */
int LoopFooter__clone(this)
  int this;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(*(int *)(this + 0xa8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  *allocation = arena;
  ((int (*)())LoopFooter__ctor_eadd0)(allocation + 1,this);
  return allocation + 1;
}

/* LoopFooter__ctor_eae98 @ 0xeae98 (80 bytes) */
int LoopFooter__ctor_eae98(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())Block__ctor_e9f00)(this,param_2);
  this[3] = this[3] | 0x20;
  *this = &PTR_FUN_001e9c10;
  return;
}

/* LoopHeader__ctor_eaee8 @ 0xeaee8 (132 bytes) */
int LoopHeader__ctor_eaee8(this, param_2)
  undefined4 *this;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  ((int (*)())Block__ctor_e9f00)(this,param_2);
  uVar1 = *(undefined4 *)(param_2 + 0x144);
  uVar4 = *(undefined4 *)(param_2 + 300);
  uVar6 = *(undefined4 *)(param_2 + 0x134);
  uVar5 = *(undefined4 *)(param_2 + 0x138);
  uVar3 = *(undefined4 *)(param_2 + 0x13c);
  uVar2 = *(undefined4 *)(param_2 + 0x140);
  this[3] = this[3] | 0x20;
  *this = &PTR_FUN_001e9bb8;
  this[0x4b] = uVar4;
  this[0x4d] = uVar6;
  this[0x4e] = uVar5;
  this[0x4f] = uVar3;
  this[0x50] = uVar2;
  this[0x51] = uVar1;
  return;
}

/* LoopHeader__clone @ 0xeaf6c (64 bytes) */
int LoopHeader__clone(this)
  int this;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(*(int *)(this + 0xa8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x15c);
  *allocation = arena;
  ((int (*)())LoopHeader__ctor_eaee8)(allocation + 1,this);
  return allocation + 1;
}

/* LoopHeader__ctor_eafe4 @ 0xeafe4 (132 bytes) */
int LoopHeader__ctor_eafe4(this, param_2)
  undefined4 *this;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  ((int (*)())Block__ctor_e9f00)(this,param_2);
  uVar1 = *(undefined4 *)(param_2 + 0x144);
  uVar4 = *(undefined4 *)(param_2 + 300);
  uVar6 = *(undefined4 *)(param_2 + 0x134);
  uVar5 = *(undefined4 *)(param_2 + 0x138);
  uVar3 = *(undefined4 *)(param_2 + 0x13c);
  uVar2 = *(undefined4 *)(param_2 + 0x140);
  this[3] = this[3] | 0x20;
  *this = &PTR_FUN_001e9bb8;
  this[0x4b] = uVar4;
  this[0x4d] = uVar6;
  this[0x4e] = uVar5;
  this[0x4f] = uVar3;
  this[0x50] = uVar2;
  this[0x51] = uVar1;
  return;
}

/* IfFooter__ctor_eb068 @ 0xeb068 (68 bytes) */
int IfFooter__ctor_eb068(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())Block__ctor_e9f00)(this,param_2);
  *this = &PTR_FUN_001e9d70;
  return;
}

/* IfFooter__clone @ 0xeb0ac (64 bytes) */
int IfFooter__clone(this)
  int this;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(*(int *)(this + 0xa8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  *allocation = arena;
  ((int (*)())IfFooter__ctor_eb068)(allocation + 1,this);
  return allocation + 1;
}

/* IfFooter__ctor_eb124 @ 0xeb124 (68 bytes) */
int IfFooter__ctor_eb124(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())Block__ctor_e9f00)(this,param_2);
  *this = &PTR_FUN_001e9d70;
  return;
}

/* IfHeader__ctor_eb168 @ 0xeb168 (104 bytes) */
int IfHeader__ctor_eb168(this, param_2)
  undefined4 *this;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  ((int (*)())Block__ctor_e9f00)(this,param_2);
  uVar2 = *(undefined4 *)(param_2 + 0x148);
  uVar1 = *(undefined4 *)(param_2 + 0x144);
  this[0x55] = 0;
  *this = &PTR_FUN_001e9cc0;
  this[0x51] = uVar1;
  this[0x52] = uVar2;
  this[0x53] = 0;
  this[0x54] = 0;
  return;
}

/* IfHeader__clone @ 0xeb1d0 (64 bytes) */
int IfHeader__clone(this)
  int this;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(*(int *)(this + 0xa8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x15c);
  *allocation = arena;
  ((int (*)())IfHeader__ctor_eb168)(allocation + 1,this);
  return allocation + 1;
}

/* IfHeader__ctor_eb248 @ 0xeb248 (104 bytes) */
int IfHeader__ctor_eb248(this, param_2)
  undefined4 *this;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  ((int (*)())Block__ctor_e9f00)(this,param_2);
  uVar2 = *(undefined4 *)(param_2 + 0x148);
  uVar1 = *(undefined4 *)(param_2 + 0x144);
  this[0x55] = 0;
  *this = &PTR_FUN_001e9cc0;
  this[0x51] = uVar1;
  this[0x52] = uVar2;
  this[0x53] = 0;
  this[0x54] = 0;
  return;
}

/* FuncEndBlock__ctor_eb2b0 @ 0xeb2b0 (80 bytes) */
int FuncEndBlock__ctor_eb2b0(this, param_2)
  undefined4 *this;
  int param_2;
{
  ((int (*)())Block__ctor_e9f00)(this,param_2);
  this[0x4b] = *(undefined4 *)(param_2 + 300);
  *this = &PTR_FUN_001e9b60;
  return;
}

/* FuncEndBlock__clone @ 0xeb300 (64 bytes) */
int FuncEndBlock__clone(this)
  int this;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(*(int *)(this + 0xa8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  *allocation = arena;
  ((int (*)())FuncEndBlock__ctor_eb2b0)(allocation + 1,this);
  return allocation + 1;
}

/* FuncEndBlock__ctor_eb378 @ 0xeb378 (80 bytes) */
int FuncEndBlock__ctor_eb378(this, param_2)
  undefined4 *this;
  int param_2;
{
  ((int (*)())Block__ctor_e9f00)(this,param_2);
  this[0x4b] = *(undefined4 *)(param_2 + 300);
  *this = &PTR_FUN_001e9b60;
  return;
}

/* PostLoopFooter__ctor_eb3c8 @ 0xeb3c8 (580 bytes) */
int PostLoopFooter__ctor_eb3c8(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int compiler;
{
  undefined4 arena;
  undefined4 *allocation;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  ((int (*)())Block__ctor_ea148)(this,compiler);
  this[0x50] = 0;
  *this = &PTR_FUN_001e9bb8;
  this[0x53] = param_3;
  this[0x4b] = 0;
  this[0x4d] = 0;
  this[0x4e] = 0;
  this[0x4f] = 0;
  this[0x51] = param_4;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  *allocation = arena;
  ((int (*)())Block__ctor_ea148)(allocation + 1,compiler);
  allocation[0x4c] = this;
  allocation[1] = &PTR_FUN_001e9c10;
  this[0x54] = allocation + 1;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  puVar6 = allocation + 1;
  *allocation = arena;
  ((int (*)())Block__ctor_ea148)(puVar6,compiler);
  allocation[0x4c] = this;
  *puVar6 = &PTR_FUN_001e9c68;
  this[0x55] = puVar6;
  Block__connect(this[0x54],this);
  if (param_4 == 0) {
    uVar5 = IRInst__create(0x81,compiler);
    this[0x52] = uVar5;
    iVar2 = IRInst__getOperandRecord(uVar5,0);
    *(undefined4 *)(iVar2 + 8) = param_2;
    *(undefined4 *)(iVar2 + 0xc) = 0x27;
    uVar5 = FUN_00127608(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3ac),4,param_2,0);
    IRInst__setOperandRef(this[0x52],1,uVar5);
  }
  else {
    arena = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    puVar6 = allocation + 1;
    *allocation = arena;
    IRInst__ctor_10502c(puVar6,0xfd,compiler);
    this[0x52] = puVar6;
    iVar2 = IRInst__getOperandRecord(puVar6,0);
    *(undefined4 *)(iVar2 + 8) = param_2;
    *(undefined4 *)(iVar2 + 0xc) = 0x27;
    iVar2 = FUN_00127608(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3ac),4,0,0);
    piVar3 = *(int **)(iVar2 + 0x18);
    if (*piVar3 == 0) {
      piVar3 = (int *)Vector__elementRefGrow(piVar3,0);
    }
    else {
      if (piVar3[1] == 0) {
        *(undefined4 *)piVar3[2] = 0;
        piVar3[1] = 1;
      }
      piVar3 = (int *)piVar3[2];
    }
    iVar4 = *piVar3;
    *(undefined4 *)(iVar4 + 0x20) = 0xffffffff;
    *(byte *)(iVar4 + 0x15c) = *(byte *)(iVar4 + 0x15c) | 1;
    *(undefined4 *)(iVar4 + 0x1c) = 3;
    IRInst__setOperandRef(this[0x52],1,iVar2);
    uVar5 = DAT_001aa7fc;
    iVar2 = IRInst__getOperandRecord(this[0x52],1);
    *(undefined4 *)(iVar2 + 0x10) = uVar5;
  }
  Block__appendInst(this,this[0x52]);
  return;
}

/* IfHeader__ctor_eb688 @ 0xeb688 (268 bytes) */
int IfHeader__ctor_eb688(this, param_2, param_3, param_4, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  ((int (*)())Block__ctor_ea148)(this,compiler);
  this[0x4c] = param_2;
  *this = &PTR_FUN_001e9cc0;
  this[0x50] = param_3;
  this[0x52] = 1;
  this[0x55] = 0;
  this[0x4d] = param_4;
  this[0x4e] = 0;
  this[0x51] = 1;
  this[0x54] = 0;
  if (param_4 == 0) {
    arena = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x130);
    *allocation = arena;
    ((int (*)())Block__ctor_ea020)(allocation + 1,compiler);
    this[0x4d] = allocation + 1;
  }
  Block__connect(this,this[0x4d]);
  Block__appendInst(this,this[0x4c]);
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  *allocation = arena;
  ((int (*)())Block__ctor_ea148)(allocation + 1,compiler);
  allocation[0x4c] = this;
  allocation[1] = &PTR_FUN_001e9d70;
  this[0x4f] = allocation + 1;
  return;
}

/* IfFooterStatic__ctor_eb7e0 @ 0xeb7e0 (68 bytes) */
int IfFooterStatic__ctor_eb7e0(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())IfFooter__ctor_eb124)(this,param_2);
  *this = &PTR_FUN_001e9dc8;
  return;
}

/* IfFooterStatic__ctor_eb824 @ 0xeb824 (68 bytes) */
int IfFooterStatic__ctor_eb824(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())IfFooter__ctor_eb124)(this,param_2);
  *this = &PTR_FUN_001e9dc8;
  return;
}

/* IfFooterStatic__clone @ 0xeb868 (64 bytes) */
int IfFooterStatic__clone(this)
  int this;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(*(int *)(this + 0xa8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  *allocation = arena;
  ((int (*)())IfFooterStatic__ctor_eb824)(allocation + 1,this);
  return allocation + 1;
}

/* IfHeaderStatic__ctor_eb8e0 @ 0xeb8e0 (68 bytes) */
int IfHeaderStatic__ctor_eb8e0(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())IfHeader__ctor_eb248)(this,param_2);
  *this = &PTR_FUN_001e9d18;
  return;
}

/* IfHeaderStatic__ctor_eb924 @ 0xeb924 (68 bytes) */
int IfHeaderStatic__ctor_eb924(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())IfHeader__ctor_eb248)(this,param_2);
  *this = &PTR_FUN_001e9d18;
  return;
}

/* IfHeaderStatic__clone @ 0xeb968 (64 bytes) */
int IfHeaderStatic__clone(this)
  int this;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(*(int *)(this + 0xa8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x15c);
  *allocation = arena;
  ((int (*)())IfHeaderStatic__ctor_eb924)(allocation + 1,this);
  return allocation + 1;
}

/* IfHeaderStatic__ctor_eb9e0 @ 0xeb9e0 (168 bytes) */
int IfHeaderStatic__ctor_eb9e0(this, param_2, param_3, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  ((int (*)())IfHeader__ctor_ea600)(this,compiler);
  this[0x4c] = param_2;
  *this = &PTR_FUN_001e9d18;
  Block__appendInst(this,param_2);
  this[0x50] = param_3;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  *allocation = arena;
  ((int (*)())Block__ctor_ea148)(allocation + 1,compiler);
  allocation[0x4c] = this;
  allocation[1] = &PTR_FUN_001e9dc8;
  this[0x4f] = allocation + 1;
  return;
}

/* IfHeaderStatic__ctor_ebac8 @ 0xebac8 (168 bytes) */
int IfHeaderStatic__ctor_ebac8(this, param_2, param_3, compiler)
  undefined4 *this;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  ((int (*)())IfHeader__ctor_ea600)(this,compiler);
  this[0x4c] = param_2;
  *this = &PTR_FUN_001e9d18;
  Block__appendInst(this,param_2);
  this[0x50] = param_3;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  *allocation = arena;
  ((int (*)())Block__ctor_ea148)(allocation + 1,compiler);
  allocation[0x4c] = this;
  allocation[1] = &PTR_FUN_001e9dc8;
  this[0x4f] = allocation + 1;
  return;
}

/* Block__dtor @ 0xebbb0 (260 bytes) */
int Block__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = this[0x35];
  *this = &PTR_FUN_001e9b08;
  if (iVar2 != 0) {
    Arena__free(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = this[0x34];
  if (iVar2 != 0) {
    Arena__free(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = this[0x3d];
  if (iVar2 != 0) {
    Arena__free(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = this[0x3e];
  if (iVar2 != 0) {
    Arena__free(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = this[0x31];
  if (iVar2 != 0) {
    Arena__free(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  DListNode__clear(this + 0x24);
  puVar1 = PTR_DAT_001e8b48 + 8;
  this[0x24] = puVar1;
  this[0x27] = puVar1;
  *this = puVar1;
  return;
}

/* Block__deleting_dtor @ 0xebd00 (312 bytes) */
int Block__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = this[0x35];
  *this = &PTR_FUN_001e9b08;
  if (iVar3 != 0) {
    Arena__free(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
    Arena__free(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
  }
  iVar3 = this[0x34];
  if (iVar3 != 0) {
    Arena__free(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
    Arena__free(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
  }
  iVar3 = this[0x3d];
  if (iVar3 != 0) {
    Arena__free(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
    Arena__free(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
  }
  iVar3 = this[0x3e];
  if (iVar3 != 0) {
    Arena__free(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
    Arena__free(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
  }
  iVar3 = this[0x31];
  if (iVar3 != 0) {
    Arena__free(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
    Arena__free(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
  }
  DListNode__clear(this + 0x24);
  puVar1 = PTR_DAT_001e8b48 + 8;
  this[0x27] = puVar1;
  *this = puVar1;
  this[0x24] = puVar1;
  if (this == (undefined4 *)0x0) {
    return;
  }
  iVar3 = this[-1];
  if ((*(int *)(iVar3 + 0x28) != 0) &&
     (puVar2 = *(undefined4 **)(iVar3 + 0x14), puVar2 == this + -1)) {
    _memset(puVar2,0,*(int *)(iVar3 + 8) - (int)puVar2);
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0x14);
  }
  return;
}

/* BreakBlock__ctor_ebe70 @ 0xebe70 (68 bytes) */
int BreakBlock__ctor_ebe70(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())BreakOrContinueBlock__ctor_eac60)(this,param_2);
  *this = &PTR_FUN_001e9e20;
  return;
}

/* BreakBlock__ctor_ebeb4 @ 0xebeb4 (68 bytes) */
int BreakBlock__ctor_ebeb4(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())BreakOrContinueBlock__ctor_eac60)(this,param_2);
  *this = &PTR_FUN_001e9e20;
  return;
}

/* BreakBlock__clone @ 0xebef8 (64 bytes) */
int BreakBlock__clone(this)
  int this;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(*(int *)(this + 0xa8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x138);
  *allocation = arena;
  ((int (*)())BreakBlock__ctor_ebeb4)(allocation + 1,this);
  return allocation + 1;
}

/* ContinueBlock__ctor_ebf70 @ 0xebf70 (68 bytes) */
int ContinueBlock__ctor_ebf70(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())BreakOrContinueBlock__ctor_eac60)(this,param_2);
  *this = &PTR_FUN_001e9e78;
  return;
}

/* ContinueBlock__ctor_ebfb4 @ 0xebfb4 (68 bytes) */
int ContinueBlock__ctor_ebfb4(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  ((int (*)())BreakOrContinueBlock__ctor_eac60)(this,param_2);
  *this = &PTR_FUN_001e9e78;
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_000e9e88");
asm(".set FUN_000e9e88, _Block__clone");
asm(".globl FUN_000ead08");
asm(".set FUN_000ead08, _PostLoopFooter__clone");
asm(".globl FUN_000eae20");
asm(".set FUN_000eae20, _LoopFooter__clone");
asm(".globl FUN_000eaf6c");
asm(".set FUN_000eaf6c, _LoopHeader__clone");
asm(".globl FUN_000eb0ac");
asm(".set FUN_000eb0ac, _IfFooter__clone");
asm(".globl FUN_000eb1d0");
asm(".set FUN_000eb1d0, _IfHeader__clone");
asm(".globl FUN_000eb300");
asm(".set FUN_000eb300, _FuncEndBlock__clone");
asm(".globl FUN_000eb868");
asm(".set FUN_000eb868, _IfFooterStatic__clone");
asm(".globl FUN_000eb968");
asm(".set FUN_000eb968, _IfHeaderStatic__clone");
asm(".globl FUN_000ebbb0");
asm(".set FUN_000ebbb0, _Block__dtor");
asm(".globl FUN_000ebd00");
asm(".set FUN_000ebd00, _Block__deleting_dtor");
asm(".globl FUN_000ebef8");
asm(".set FUN_000ebef8, _BreakBlock__clone");
