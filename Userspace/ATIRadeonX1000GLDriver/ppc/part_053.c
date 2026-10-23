#include "decls.h"

/* R520VMachineAssembler__vslot27_assembleLoopHeader @ 0x19d858 (1008 bytes) */
int R520VMachineAssembler__vslot27_assembleLoopHeader(this, node, block, param_4, param_5, compiler, param_7)
  int *this;
  int node;
  undefined4 block;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 compiler;
  undefined4 param_7;
{
  bool bVar1;
  uint loopStackEntry;
  uint condSwizzle;
  int branchInst;
  int iVar5;
  int *condValueInst;
  undefined4 operandVReg;
  uint uVar8;
  int a2;
  undefined4 a5;
  uint *loopStackSlot;
  int loopIndex;
  int *piVar11;
  
  piVar11 = *(int **)(node + 0xac);
  a5 = compiler;
  branchInst = Block__getBranchInst(node,node,block,param_4,param_5,compiler,param_7);
  if (*piVar11 != 0) goto LAB_0019dc0c;
  loopStackSlot = (uint *)0x0;
  condSwizzle = *(uint *)(this[0x25] + 4);
  loopStackEntry = condSwizzle - 1;
  if (loopStackEntry < condSwizzle) {
    loopStackSlot = (uint *)(loopStackEntry * 4 + *(int *)(this[0x25] + 8));
  }
  loopStackEntry = *loopStackSlot;
  iVar5 = IRInst__getOperandRecord(branchInst,1);
  condSwizzle = *(uint *)(iVar5 + 0x10);
  iVar5 = *(int *)(*(int *)(branchInst + 0x88) + 8);
  if (iVar5 == 0x8b) {
    if (*(int *)(branchInst + 300) != 0) goto LAB_0019dab0;
    condValueInst = IRInst__create(0x12,compiler);
    iVar5 = IRInst__getOperandRecord(condValueInst,1);
    uVar8 = *(uint *)(branchInst + 0xb8);
    *(uint *)(iVar5 + 0x10) = condSwizzle;
    IROperand__setModifierBits(condValueInst + 0x29,1,uVar8 & 1);
    operandVReg = IRInst__getOperandSource(branchInst,1);
    IRInst__setOperandSource(condValueInst,1,operandVReg,0,compiler);
    operandVReg = IRInst__getOperandSource(branchInst,2);
    IRInst__setOperandSource(condValueInst,2,operandVReg,0,compiler);
    IROperand__setModifierBits(condValueInst + 0x2f,1,1);
    iVar5 = R300VMachineAssembler__getOrAllocateScratchRegister(this,piVar11);
    condValueInst[0x25] = iVar5;
    condValueInst[0x26] = 0;
    (**(code **)(*condValueInst + 0x84))(condValueInst,loopStackEntry);
    Block__appendInst(node,condValueInst);
  }
  else if (iVar5 == 0x8c) {
    if (*(int *)(branchInst + 300) == 0) {
      condValueInst = (int *)IRInst__getOperandSource(branchInst,1);
    }
    else {
      condValueInst = IRInst__create(0x12,compiler);
      iVar5 = IRInst__getOperandRecord(condValueInst,1);
      uVar8 = *(uint *)(branchInst + 0xb8);
      *(uint *)(iVar5 + 0x10) = condSwizzle;
      IROperand__setModifierBits(condValueInst + 0x29,1,uVar8 & 1);
      operandVReg = IRInst__getOperandSource(branchInst,1);
      IRInst__setOperandSource(condValueInst,1,operandVReg,0,compiler);
      ((void (*)())IRInst__makeLiteralVec4Float)(condValueInst,piVar11,2,1.0,1.0,1.0,1.0);
      IROperand__setModifierBits(condValueInst + 0x2f,1,1);
      iVar5 = R300VMachineAssembler__getOrAllocateScratchRegister(this,piVar11);
      condValueInst[0x25] = iVar5;
      condValueInst[0x26] = 0;
      (**(code **)(*condValueInst + 0x84))(condValueInst,loopStackEntry);
      Block__appendInst(node,condValueInst);
    }
  }
  else {
LAB_0019dab0:
    condValueInst = (int *)0x0;
  }
  iVar5 = R520VMachineAssembler__getOrCreateConstantZeroInst(this);
  iVar5 = *(int *)(iVar5 + 0x94);
  piVar11 = IRInst__create(0x54,compiler);
  piVar11[0x26] = 0;
  piVar11[0x27] = 0x1010101;
  piVar11[0x25] = 0;
  IRInst__setOperandSource(piVar11,1,condValueInst,0,compiler);
  loopIndex = 0;
  do {
    (**(code **)(*piVar11 + 0x88))(piVar11,1,loopIndex,condSwizzle & 0xff);
    bVar1 = loopIndex != 3;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  loopIndex = 0;
  (**(code **)(*piVar11 + 0x84))(piVar11,loopStackEntry);
  Block__appendInst(node,piVar11);
  piVar11 = IRInst__create(0x3e,compiler);
  IRInst__setOperandSource(piVar11,1,condValueInst,0,compiler);
  do {
    a2 = loopIndex;
    uVar8 = condSwizzle & 0xff;
    /* dropped 2 args (found auditing #70 via ExtendIndirectCalls.java / ground-truth
     * disassembly): stock passes loopIndex and uVar8 here too, matching the identical-shape
     * call a few lines above (both loops dispatch the same vtable+0x88 method the same way -
     * r28, set once, holds this loop's masked byte for both). */
    (**(code **)(*piVar11 + 0x88))(piVar11,1,loopIndex,uVar8);
    bVar1 = loopIndex != 3;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  piVar11[0x25] = iVar5;
  loopStackEntry = loopStackEntry ^ 3;
  piVar11[0x27] = 0x1010100;
  piVar11[0x26] = 0;
  (**(code **)(*piVar11 + 0x84))
            (piVar11,(loopStackEntry - ((loopStackEntry - 1) + (uint)(loopStackEntry == 0))) + 2,a2,uVar8,compiler,a5,loopStackEntry - 1)
  ;
  Block__appendInst(node,piVar11);
  FUN_00193f20(branchInst);
  *(undefined4 *)(node + 0x130) = 0;
LAB_0019dc0c:
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  return Block__accept(*(undefined4 *)(node + 0x13c),param_5);
}

/* R520VMachineAssembler__vslot30_assembleBlockThenSlot40 @ 0x19dc48 (104 bytes) */
int R520VMachineAssembler__vslot30_assembleBlockThenSlot40(this, node, block)
  int *this;
  int node;
  undefined4 block;
{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*this + 0xa0);
  uVar1 = FUN_000e7d5c(*(undefined4 *)(node + 300));
                    
                    
  (*UNRECOVERED_JUMPTABLE)(this,uVar1);
  return;
}

/* R520VMachineAssembler__deleting_dtor @ 0x19dcb0 (156 bytes) */
int R520VMachineAssembler__deleting_dtor(this)
  undefined4 *this;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = this[0x26];
  *this = &PTR_FUN_001eb8d8;
  if (iVar2 != 0) {
    Arena__free(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = this[0x25];
  if (iVar2 != 0) {
    Arena__free(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  MachineAssembler__dtor_19b91c(this);
  if (this == (undefined4 *)0x0) {
    return;
  }
  iVar2 = this[-1];
  if ((*(int *)(iVar2 + 0x28) != 0) &&
     (puVar1 = *(undefined4 **)(iVar2 + 0x14), puVar1 == this + -1)) {
    _memset(puVar1,0,*(int *)(iVar2 + 8) - (int)puVar1);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 0x14);
  }
  return;
}

/* R520VMachineAssembler__init @ 0x19dd7c (180 bytes) */
int R520VMachineAssembler__init(this, program, allocatorArg, compiler)
  int this;
  undefined4 program;
  undefined4 allocatorArg;
  int compiler;
{
  undefined4 arenaAt378;
  undefined4 *vectorAlloc;
  undefined4 uVar2;
  
  R300VMachineAssembler__init(this,program,allocatorArg,compiler);
  *(undefined4 *)(this + 0x8c) = 0xffffffff;
  *(undefined4 *)(this + 0x90) = 0;
  arenaAt378 = *(undefined4 *)(compiler + COMP_arenaB);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  uVar2 = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = uVar2;
  *(undefined4 **)(this + 0x98) = vectorAlloc + 1;
  arenaAt378 = *(undefined4 *)(compiler + COMP_arenaB);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaAt378;
  uVar2 = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = uVar2;
  *(undefined4 **)(this + 0x94) = vectorAlloc + 1;
  return;
}

/* R520VMachineAssembler__create @ 0x19de50 (96 bytes) */
int R520VMachineAssembler__create(unusedThis, compiler)
  undefined4 unusedThis;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaB);
  allocation = (undefined4 *)Arena__alloc(arena,0xa0);
  *allocation = arena;
  allocation[1] = &PTR_FUN_001eb8d8;
  allocation[7] = 0;
  return allocation + 1;
}

/* MachineAssembler__dtor_19deb0 @ 0x19deb0 (120 bytes) */
int MachineAssembler__dtor_19deb0(this)
  undefined4 *this;
{
  int iVar1;
  
  iVar1 = this[0x26];
  *this = &PTR_FUN_001eb8d8;
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = this[0x25];
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  *this = &PTR_FUN_001eb808;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[2]);
  this[2] = 0;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[0x18]);
  this[0x11] = 0;
  *this = PTR_DAT_001e914c + 8;
  return;
}

/* MachineAssembler__dtor_19df54 @ 0x19df54 (120 bytes) */
int MachineAssembler__dtor_19df54(this)
  undefined4 *this;
{
  int iVar1;
  
  iVar1 = this[0x26];
  *this = &PTR_FUN_001eb8d8;
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = this[0x25];
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  *this = &PTR_FUN_001eb808;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[2]);
  this[2] = 0;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[0x18]);
  this[0x11] = 0;
  *this = PTR_DAT_001e914c + 8;
  return;
}

/* R520VMachineAssembler__vslot28_assembleIfEnd @ 0x19dff8 (292 bytes) */
int R520VMachineAssembler__vslot28_assembleIfEnd(this, node, block, compiler)
  int *this;
  int node;
  undefined4 block;
  undefined4 compiler;
{
  int operandRecord;
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = *(int **)(node + 0xac);
  Vector__removeAt(this[0x25],*(int *)(this[0x25] + 4) + -1);
  if (*piVar5 == 0) {
    piVar5 = (int *)0x0;
    uVar3 = *(uint *)(this[0x25] + 4);
    uVar2 = uVar3 - 1;
    if (uVar2 < uVar3) {
      piVar5 = (int *)(uVar2 * 4 + *(int *)(this[0x25] + 8));
    }
    iVar6 = *piVar5;
    FUN_000e2bf4(block,iVar6);
    if (iVar6 != 0) {
      iVar6 = IRInst__create(0x58,compiler);
      iVar4 = R520VMachineAssembler__getOrCreateConstantZeroInst(this);
      uVar1 = DAT_001b2d50;
      *(undefined4 *)(iVar6 + 0x94) = *(undefined4 *)(iVar4 + 0x94);
      *(undefined4 *)(iVar6 + 0x98) = 0;
      *(undefined4 *)(iVar6 + 0x9c) = uVar1;
      IRInst__setOperandSource(iVar6,1,iVar4,0,compiler);
      uVar1 = DAT_001b2d4c;
      operandRecord = IRInst__getOperandRecord(iVar6,1);
      *(undefined4 *)(operandRecord + 0x10) = uVar1;
      Block__prependInst(node,iVar6);
    }
  }
                    
                    
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  return;
}

/* R520VMachineAssembler__vslot31_assembleWithPredicateRestore @ 0x19e11c (508 bytes) */
int R520VMachineAssembler__vslot31_assembleWithPredicateRestore(this, node, block, compiler)
  int *this;
  int node;
  undefined4 block;
  undefined4 compiler;
{
  int *newInst;
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  
  piVar7 = *(int **)(node + 0xac);
  if (((0 < *(int *)(*(int *)(node + 300) + 0x138)) ||
      (*(int *)(*(int *)(node + 300) + 0x13c) != 0)) &&
     (Vector__removeAt(this[0x25],*(int *)(this[0x25] + 4) + -1), *piVar7 == 0)) {
    puVar4 = (undefined4 *)0x0;
    uVar2 = *(uint *)(this[0x25] + 4);
    uVar1 = uVar2 - 1;
    if (uVar1 < uVar2) {
      puVar4 = (undefined4 *)(uVar1 * 4 + *(int *)(this[0x25] + 8));
    }
    FUN_000e2bf4(block,*puVar4);
    iVar3 = this[0x26];
    uVar1 = *(uint *)(iVar3 + 4);
    if (0 < (int)uVar1) {
      uVar2 = uVar1 - 1;
      puVar4 = (undefined4 *)0x0;
      if (uVar2 < uVar1) {
        puVar4 = (undefined4 *)(uVar2 * 4 + *(int *)(iVar3 + 8));
      }
      uVar5 = *puVar4;
      Vector__removeAt(iVar3,uVar1 - 1);
      iVar3 = R520VMachineAssembler__getOrCreateConstantZeroInst(this);
      iVar6 = *(int *)(iVar3 + 0x94);
      newInst = (int *)IRInst__create(0x5a,compiler);
      iVar3 = DAT_001b2d50;
      newInst[0x25] = iVar6;
      newInst[0x26] = 0;
      newInst[0x27] = iVar3;
      IRInst__setOperandSource(newInst,1,uVar5,0,compiler);
      if ((3 < (int)uVar1) && (uVar2 = 0, (int)uVar1 < 8)) {
        uVar2 = uVar1 - 4;
      }
      (**(code **)(*newInst + 0x88))(newInst,1,0,uVar2);
      (**(code **)(*newInst + 0x88))(newInst,1,1,uVar2);
      (**(code **)(*newInst + 0x88))(newInst,1,2,uVar2);
      (**(code **)(*newInst + 0x88))(newInst,1,3,uVar2);
      Block__prependInst(node,newInst);
    }
  }
                    
                    
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  return;
}

/* R520VMachineAssembler__vslot25_assembleConditionalBlock @ 0x19e318 (840 bytes) */
int R520VMachineAssembler__vslot25_assembleConditionalBlock(this, node, block, compiler, extra2, extra3, extra4)
  int *this;
  int node;
  undefined4 block;
  undefined4 compiler;
  undefined4 extra2;
  undefined4 extra3;
  undefined4 extra4;
{
  undefined4 sourceDef;
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int loopIndex;
  int *a0;
  undefined4 uVar5;
  int operandRecord;
  undefined4 *puVar7;
  int *piVar8;
  code *pcVar9;
  uint *puVar10;
  bool bVar11;
  
  piVar8 = *(int **)(node + 0xac);
  a0 = (int *)Block__getBranchInst(node,node,block,compiler,extra2,extra3,extra4);
  if (*piVar8 != 0) goto LAB_0019e5d0;
  (**(code **)(*a0 + 0x14))(a0);
  piVar8 = (int *)0x0;
  uVar3 = *(uint *)(this[0x25] + 4);
  uVar2 = uVar3 - 1;
  if (uVar2 < uVar3) {
    piVar8 = (int *)(uVar2 * 4 + *(int *)(this[0x25] + 8));
  }
  loopIndex = a0[0x4b];
  bVar11 = *piVar8 == 0;
  if (loopIndex == 1) {
    if (bVar11) {
      uVar5 = 0x54;
    }
    else {
      uVar5 = 0x2d;
    }
  }
  else if (loopIndex < 2) {
    if (loopIndex == 0) {
      if (bVar11) {
        uVar5 = 0x53;
      }
      else {
        uVar5 = 0x2c;
      }
    }
    else {
LAB_0019e3d4:
      uVar5 = 0;
    }
  }
  else if (loopIndex == 2) {
    if (bVar11) {
      uVar5 = 0x55;
    }
    else {
      uVar5 = 0x2e;
    }
  }
  else {
    if (loopIndex != 3) goto LAB_0019e3d4;
    if (bVar11) {
      uVar5 = 0x56;
    }
    else {
      uVar5 = 0x2f;
    }
  }
  piVar8 = IRInst__create(uVar5,compiler);
  if (bVar11) {
    if (*(int *)(node + 0x144) == 0) {
      loopIndex = R520VMachineAssembler__getOrCreateConstantZeroInst(this);
      piVar8[0x25] = *(int *)(loopIndex + 0x94);
      piVar8[0x26] = 0;
      piVar8[0x27] = 0x1010100;
    }
    else {
      piVar8[0x26] = 0;
      piVar8[0x25] = 0;
      piVar8[0x27] = 0x1010101;
    }
    sourceDef = IRInst__getOperandSource(a0,1);
    IRInst__setOperandSource(piVar8,1,sourceDef,0,compiler);
  }
  else {
    loopIndex = R520VMachineAssembler__getOrCreateConstantZeroInst(this);
    piVar8[0x25] = *(int *)(loopIndex + 0x94);
    piVar8[0x26] = 0;
    piVar8[0x27] = 0x1010100;
    IRInst__setOperandSource(piVar8,1,loopIndex,0,compiler);
    loopIndex = IRInst__getOperandRecord(piVar8,1);
    *(undefined4 *)(loopIndex + 0x10) = 0x3030303;
    sourceDef = IRInst__getOperandSource(a0,1);
    IRInst__setOperandSource(piVar8,2,sourceDef,0,compiler);
  }
  loopIndex = 0;
  do {
    pcVar9 = *(code **)(*piVar8 + 0x88);
    if (bVar11) {
      uVar5 = 1;
    }
    else {
      uVar5 = 2;
    }
    operandRecord = IRInst__getOperandRecord(a0,1);
    (*pcVar9)(piVar8,uVar5,loopIndex,*(undefined1 *)(operandRecord + 0x13));
    bVar1 = loopIndex != 3;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  if ((a0[0x2e] & 1U) != 0) {
    if (bVar11) {
      loopIndex = 1;
    }
    else {
      loopIndex = 2;
    }
    IROperand__setModifierBits(piVar8 + loopIndex * 6 + 0x23,1,1);
  }
  Block__appendInst(node,piVar8);
  FUN_00193f20(a0);
  *(undefined4 *)(node + 0x130) = 0;
LAB_0019e5d0:
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  puVar10 = (uint *)this[0x25];
  uVar2 = puVar10[1];
  if (uVar2 < *puVar10) {
    _memset(uVar2 * 4 + puVar10[2],0,4);
    puVar7 = (undefined4 *)(uVar2 * 4 + puVar10[2]);
    puVar10[1] = uVar2 + 1;
  }
  else {
    puVar7 = (undefined4 *)Vector__elementRefGrow(puVar10,uVar2);
  }
  *puVar7 = 3;
  return;
}

/* R520VMachineAssembler__vslot6_setLoopStack @ 0x19e660 (128 bytes) */
int R520VMachineAssembler__vslot6_setLoopStack(this, enable)
  int this;
  undefined4 enable;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  R300VMachineAssembler__vslot6_setLoopStack(this,enable);
  puVar3 = *(uint **)(this + 0x94);
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset(uVar2 * 4 + puVar3[2],0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)Vector__elementRefGrow(puVar3,uVar2);
  }
  *puVar1 = 0;
  return;
}

/* R520VMachineAssembler__vslot24_assembleWithPredicateSet @ 0x19e6e0 (688 bytes) */
int R520VMachineAssembler__vslot24_assembleWithPredicateSet(this, node, block, compiler)
  int *this;
  int node;
  undefined4 block;
  undefined4 compiler;
{
  int operandRecord;
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar9;
  int iVar10;
  double fparam_1;
  
  piVar8 = *(int **)(node + 0xac);
  if ((0 < *(int *)(node + 0x138)) || (*(int *)(node + 0x13c) != 0)) {
    iVar3 = R520VMachineAssembler__getOrCreateConstantZeroInst(this);
    puVar9 = (uint *)this[0x25];
    uVar7 = *(undefined4 *)(iVar3 + 0x94);
    piVar6 = (int *)0x0;
    uVar2 = puVar9[1] - 1;
    if (uVar2 < puVar9[1]) {
      piVar6 = (int *)(uVar2 * 4 + puVar9[2]);
    }
    if (*piVar6 == 0) {
      if (*piVar8 == 0) {
        iVar3 = IRInst__create(0x53,compiler);
        uVar1 = DAT_001b2d50;
        fparam_1 = (double)FLOAT_001aa0d4;
        *(undefined4 *)(iVar3 + 0x94) = uVar7;
        *(undefined4 *)(iVar3 + 0x9c) = uVar1;
        *(undefined4 *)(iVar3 + 0x98) = 0;
        ((void (*)())IRInst__makeLiteralVec4Float)(iVar3,piVar8,1,fparam_1,fparam_1,fparam_1,fparam_1);
        *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffffb;
        Block__appendInst(node,iVar3);
        puVar9 = (uint *)this[0x25];
      }
    }
    else if (*piVar8 == 0) {
      iVar10 = *(int *)(this[0x26] + 4);
      if (2 < iVar10) {
        if (iVar10 < 7) {
          uVar7 = FUN_00130690(piVar8,0);
          iVar10 = iVar10 + -3;
        }
        else {
          uVar7 = 0;
          iVar10 = 0;
        }
      }
      iVar4 = FUN_001084b8(0x66,compiler);
      *(undefined4 *)(iVar4 + 0x9c) = DAT_001b2d54;
      *(undefined1 *)(iVar10 + iVar4 + 0x9c) = 0;
      *(undefined4 *)(iVar4 + 0x98) = 0;
      *(undefined4 *)(iVar4 + 0x94) = uVar7;
      IRInst__setOperandSource(iVar4,1,iVar3,0,compiler);
      uVar7 = DAT_001b2d4c;
      operandRecord = IRInst__getOperandRecord(iVar4,1);
      *(undefined4 *)(operandRecord + 0x10) = uVar7;
      *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) & 0xfffffffb;
      Block__appendInst(node,iVar4);
      puVar9 = (uint *)this[0x26];
      uVar2 = puVar9[1];
      if (uVar2 < *puVar9) {
        _memset(uVar2 * 4 + puVar9[2],0,4);
        piVar8 = (int *)(uVar2 * 4 + puVar9[2]);
        puVar9[1] = uVar2 + 1;
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar9,uVar2);
      }
      *piVar8 = iVar4;
      puVar9 = (uint *)this[0x25];
    }
    uVar2 = puVar9[1];
    if (uVar2 < *puVar9) {
      _memset(uVar2 * 4 + puVar9[2],0,4);
      puVar5 = (undefined4 *)(uVar2 * 4 + puVar9[2]);
      puVar9[1] = uVar2 + 1;
    }
    else {
      puVar5 = (undefined4 *)Vector__elementRefGrow(puVar9,uVar2);
    }
    *puVar5 = 3;
  }
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*this + 0x9c);
  uVar7 = FUN_000e7d5c(node);
                    
                    
  (*UNRECOVERED_JUMPTABLE)(this,uVar7,*(undefined4 *)(node + 0x134));
  return;
}

/* psnPackedLaneComponent @ 0x19e990 (108 bytes) */
int psnPackedLaneComponent(descriptor, lane)
  uint *descriptor;
  int lane;
{
  if ((*descriptor & 0x400000) != 0) {
    if (lane == 1) {
      return descriptor[1] >> 2 & 3;
    }
    if (lane < 2) {
      if (lane == 0) {
        return descriptor[1] & 3;
      }
    }
    else {
      if (lane == 2) {
        return descriptor[1] >> 4 & 3;
      }
      if (lane == 3) {
        return descriptor[1] >> 6 & 3;
      }
    }
  }
  return 1;
}

/* psnPackedLaneSource @ 0x19e9fc (168 bytes) */
int psnPackedLaneSource(descriptor, lane)
  uint *descriptor;
  int lane;
{
  if ((*descriptor & 0x400000) == 0) {
    if (lane == 1) {
      return 1;
    }
    if (lane < 2) {
      if (lane == 0) {
        return 0;
      }
    }
    else {
      if (lane == 2) {
        return 2;
      }
      if (lane == 3) {
        return 3;
      }
    }
  }
  else {
    if (lane == 1) {
      return descriptor[1] >> 4 & 7;
    }
    if (lane < 2) {
      if (lane == 0) {
        return descriptor[1] & 7;
      }
    }
    else {
      if (lane == 2) {
        return descriptor[1] >> 8 & 7;
      }
      if (lane == 3) {
        return descriptor[1] >> 0xc & 7;
      }
    }
  }
  return 0xffffffff;
}

/* psnPackedNegateMask @ 0x19eaa4 (32 bytes) */
int psnPackedNegateMask(descriptor, param_2, param_3, param_4, param_5, param_6, param_7)
  uint *descriptor;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if ((*descriptor & 0x400000) == 0) {
    return 0;
  }
  return descriptor[1] & 0x8888;
}

/* psnPackedLaneNegate @ 0x19eac4 (108 bytes) */
int psnPackedLaneNegate(descriptor, lane)
  uint *descriptor;
  int lane;
{
  if ((*descriptor & 0x400000) != 0) {
    if (lane == 1) {
      return descriptor[1] >> 7 & 1;
    }
    if (lane < 2) {
      if (lane == 0) {
        return descriptor[1] >> 3 & 1;
      }
    }
    else {
      if (lane == 2) {
        return descriptor[1] >> 0xb & 1;
      }
      if (lane == 3) {
        return descriptor[1] >> 0xf & 1;
      }
    }
  }
  return 0;
}

/* FUN_0019eb30 @ 0x19eb30 (172 bytes) */
int FUN_0019eb30(param_1)
  uint *param_1;
{
  uint uVar1;
  int loopIndex;
  int loopRemaining;
  
  if ((*param_1 & 0x400000) == 0) {
    return 0;
  }
  uVar1 = param_1[1];
  if (1 < (uVar1 & 3) - 2) {
    loopRemaining = 4;
    loopIndex = 0;
    do {
      while( true ) {
        do {
          while( true ) {
            loopIndex = loopIndex + 1;
            loopRemaining = loopRemaining + -1;
            if (loopRemaining == 0) {
              return 0;
            }
            if (loopIndex != 1) break;
            if ((uVar1 & 0xc) == 8) {
              return 1;
            }
            if ((uVar1 & 0xc) == 0xc) {
              return 1;
            }
          }
        } while (loopIndex < 2);
        if (loopIndex != 2) break;
        if ((uVar1 & 0x30) == 0x20) {
          return 1;
        }
        if ((uVar1 & 0x30) == 0x30) {
          return 1;
        }
      }
    } while ((loopIndex != 3) || (((uVar1 & 0xc0) != 0x80 && ((uVar1 & 0xc0) != 0xc0))));
  }
  return 1;
}

/* FUN_0019ebdc @ 0x19ebdc (172 bytes) */
int FUN_0019ebdc(param_1)
  uint *param_1;
{
  uint uVar1;
  int loopIndex;
  int loopRemaining;
  
  if ((*param_1 & 0x400000) == 0) {
    return 0;
  }
  uVar1 = param_1[1];
  if (1 < (uVar1 & 7) - 4) {
    loopRemaining = 4;
    loopIndex = 0;
    do {
      while( true ) {
        do {
          while( true ) {
            loopIndex = loopIndex + 1;
            loopRemaining = loopRemaining + -1;
            if (loopRemaining == 0) {
              return 0;
            }
            if (loopIndex != 1) break;
            if ((uVar1 & 0x70) == 0x40) {
              return 1;
            }
            if ((uVar1 & 0x70) == 0x50) {
              return 1;
            }
          }
        } while (loopIndex < 2);
        if (loopIndex != 2) break;
        if ((uVar1 & 0x700) == 0x400) {
          return 1;
        }
        if ((uVar1 & 0x700) == 0x500) {
          return 1;
        }
      }
    } while ((loopIndex != 3) ||
            (((undefined *)(uVar1 & 0x7000) != (undefined *)0x4000 &&
             ((undefined *)(uVar1 & 0x7000) != ((unsigned char *)0x00005000)))));
  }
  return 1;
}

/* ilSkipRelativeAddressWords @ 0x19ec88 (108 bytes) */
int ilSkipRelativeAddressWords(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int loopIndex;
  
  if (param_1 == 1) {
    param_3 = param_3 + 4;
  }
  else {
    loopIndex = 0;
    if (-1 < param_2) {
      do {
        loopIndex = loopIndex + 1;
        iVar1 = ((int (*)())ilSourceOperandWordCount)(param_3);
        param_3 = param_3 + iVar1 * 4;
      } while (loopIndex <= param_2);
    }
  }
  return param_3;
}

/* ilSourceOperandWordCount @ 0x19ecf4 (192 bytes) */
int ilSourceOperandWordCount(param_1)
  uint *param_1;
{
  uint uVar1;
  int iVar2;
  uint *loopIndex;
  uint loopIndex2;
  
  loopIndex = param_1 + 1;
  uVar1 = *param_1;
  if ((uVar1 & 0x400000) != 0) {
    loopIndex = param_1 + 2;
  }
  if ((uVar1 & 0x1800000) == 0) {
    loopIndex2 = 0;
    if ((uVar1 & 0x2000000) == 0) {
      uVar1 = *param_1;
    }
    else {
      do {
        loopIndex2 = loopIndex2 + 1;
        iVar2 = ((int (*)())ilSourceOperandWordCount)(loopIndex);
        uVar1 = *param_1;
        loopIndex = loopIndex + iVar2;
      } while (loopIndex2 < (uVar1 >> 0x19 & 1));
    }
    if ((uVar1 & 0x1800000) == 0) goto LAB_0019ed78;
  }
  loopIndex = (uint *)((int (*)())ilSkipRelativeAddressWords)(uVar1 >> 0x17 & 3,uVar1 >> 0x19 & 1,loopIndex);
  uVar1 = *param_1;
LAB_0019ed78:
  if ((uVar1 & 0x4000000) != 0) {
    loopIndex = loopIndex + 1;
  }
  return (int)loopIndex - (int)param_1 >> 2;
}

/* ilInstructionHeaderWordCount @ 0x19edb4 (84 bytes) */
int ilInstructionHeaderWordCount(param_1)
  uint *param_1;
{
  uint *puVar1;
  
  if ((short)*param_1 == 0x7d) {
    return 1;
  }
  puVar1 = param_1 + 1;
  if ((int)*param_1 < 0) {
    puVar1 = param_1 + 2;
  }
  if ((short)*param_1 == 0x17) {
    return (int)puVar1 - (int)param_1 >> 2;
  }
  if ((*param_1 & 0x40000000) != 0) {
    puVar1 = puVar1 + 1;
  }
  return (int)puVar1 - (int)param_1 >> 2;
}

/* ilDestinationOperandWordCount @ 0x19ee08 (108 bytes) */
int ilDestinationOperandWordCount(param_1)
  uint *param_1;
{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = param_1 + 1;
  uVar1 = *param_1;
  if ((uVar1 & 0x400000) != 0) {
    puVar2 = param_1 + 2;
  }
  if ((uVar1 & 0x1800000) != 0) {
    puVar2 = (uint *)((int (*)())ilSkipRelativeAddressWords)(uVar1 >> 0x17 & 3,uVar1 >> 0x19 & 1,puVar2);
    uVar1 = *param_1;
  }
  if ((uVar1 & 0x4000000) != 0) {
    puVar2 = puVar2 + 1;
  }
  return (int)puVar2 - (int)param_1 >> 2;
}

/* FUN_0019ee74 @ 0x19ee74 (184 bytes) */
int FUN_0019ee74(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 == '\x01') {
    *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) =
         *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) | 0x2000;
    piVar2 = *(int **)(param_2 + 0x310);
    *(int *)(param_2 + 0x30c) = piVar2[2];
                    
                    
    (**(code **)(*piVar2 + 8))(piVar2);
    return;
  }
  if (cVar1 != '\x02') {
    if (cVar1 != '\0') {
      return;
    }
    *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) = *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) | 1;
    piVar2 = *(int **)(param_2 + 0x310);
    *(int *)(param_2 + 0x30c) = piVar2[1];
                    
                    
    (**(code **)(*piVar2 + 0xc))(piVar2);
    return;
  }
  *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) = *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) | 0x4000
  ;
  piVar2 = *(int **)(param_2 + 0x310);
  *(int *)(param_2 + 0x30c) = piVar2[3];
                    
                    
  (**(code **)(*piVar2 + 0x10))(piVar2);
  return;
}

/* FudoPs__vslot96_installHardwareTables @ 0x19ef2c (32 bytes) */
int FudoPs__vslot96_installHardwareTables(this)
  int this;
{
  *(undefined **)(this + 0xc) = &DAT_001e6730;
  return;
}

/* R520MachineAssembler__vslot5_beginProgram @ 0x19ef50 (324 bytes) */
int R520MachineAssembler__vslot5_beginProgram(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_4 + 0x30c);
  uVar2 = FUN_000e14e4(param_4,0x963c,param_3);
  *(undefined4 *)(param_1 + 0xac) = uVar2;
  _memset(uVar2,0,0x963c);
  iVar3 = *(int *)(*(int *)(param_4 + 0x30c) + 0x40);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(int *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x60) = 1;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x80) = 1;
  *(undefined4 *)(param_1 + 0x84) = 1;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x98) = 1;
  *(undefined4 *)(param_1 + 0x94) = 1;
  **(undefined4 **)(param_1 + 0xa8) = 0;
  puVar1 = PTR_DAT_001e913c;
  *(int *)(*(int *)(param_1 + 0xa8) + 4) = iVar3 + 1;
  *(undefined4 *)(puVar1 + 0x2654) = 7;
  *(undefined4 *)(puVar1 + 0x10e4) = 0xd;
  *(undefined4 *)(puVar1 + 0x22d4) = 0xe;
  *(undefined4 *)(puVar1 + 0x229c) = 0xb;
  *(undefined4 *)(puVar1 + 0x2344) = 0xf;
  *(undefined4 *)(puVar1 + 0x230c) = 0xc;
  *(undefined4 *)(puVar1 + 0x261c) = 5;
  *(undefined4 *)(puVar1 + 0x1a4c) = 6;
  *(undefined4 *)(puVar1 + 0x10ac) = 0xc;
  return;
}

/* R520MachineAssembler__setRsColorFields @ 0x19f094 (56 bytes) */
int R520MachineAssembler__setRsColorFields(this, recordIndex, colorIndex, colorSource, destRegisterWord)
  int this;
  int recordIndex;
  undefined4 colorIndex;
  undefined4 colorSource;
  undefined4 destRegisterWord;
{
  int recordOffset;
  
  recordOffset = recordIndex * 0x48;
  *(undefined4 *)(*(int *)(this + 0xa8) + recordOffset) = 1;
  *(undefined1 *)(recordOffset + *(int *)(this + 0xa8) + 10) = (undefined1)colorIndex;
  *(undefined1 *)(recordOffset + *(int *)(this + 0xa8) + 0xb) = (undefined1)colorSource;
  *(undefined2 *)(recordOffset + *(int *)(this + 0xa8) + 6) = (*(unsigned short *)((unsigned char *)&(destRegisterWord) + 2));
  return;
}

/* R520MachineAssembler__setRsTexCoordFields @ 0x19f0cc (68 bytes) */
int R520MachineAssembler__setRsTexCoordFields(this, recordIndex, texCoordIndex, texCoordPresent, destRegisterWord, adjusted)
  int this;
  int recordIndex;
  undefined4 texCoordIndex;
  undefined4 texCoordPresent;
  undefined4 destRegisterWord;
  undefined4 adjusted;
{
  int recordOffset;
  
  recordOffset = recordIndex * 0x48;
  *(undefined4 *)(*(int *)(this + 0xa8) + recordOffset) = 1;
  *(undefined1 *)(recordOffset + *(int *)(this + 0xa8) + 8) = (undefined1)texCoordIndex;
  *(undefined1 *)(recordOffset + *(int *)(this + 0xa8) + 9) = (undefined1)texCoordPresent;
  *(undefined2 *)(recordOffset + *(int *)(this + 0xa8) + 4) = (*(unsigned short *)((unsigned char *)&(destRegisterWord) + 2));
  *(undefined1 *)(recordOffset + *(int *)(this + 0xa8) + 0xc) = (undefined1)adjusted;
  return;
}

/* R520MachineAssembler__clearCurrentRecord @ 0x19f110 (40 bytes) */
int R520MachineAssembler__clearCurrentRecord(this)
  int this;
{
  return _memset(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8),0,0x48);
}

/* R520MachineAssembler__initNopAluRecord @ 0x19f138 (168 bytes) */
int R520MachineAssembler__initNopAluRecord(this)
  int this;
{
  int record;
  int recordsBase;
  
  recordsBase = *(int *)(this + 0xa8);
  record = *(int *)(this + 0x60) * 0x48;
  *(undefined4 *)(record + recordsBase) = 3;
  record = record + recordsBase;
  *(undefined1 *)(record + 0x2a) = 0;
  *(undefined1 *)(record + 0x2b) = 0;
  *(undefined1 *)(record + 0x40) = 0;
  *(undefined2 *)(record + 0x1e) = 0x8000;
  *(uint *)(record + 0x24) = *(uint *)(record + 0x24) & 0x7f007f | 0x92009200;
  *(uint *)(record + 0x28) = *(uint *)(record + 0x28) & 0x7fffff | 0x92000000;
  *(undefined1 *)(record + 0x38) = 4;
  *(undefined2 *)(record + 0xe) = 0x8000;
  *(undefined2 *)(record + 0x10) = 0x8000;
  *(undefined2 *)(record + 0x12) = 0x8000;
  *(undefined2 *)(record + 0x1a) = 0x8000;
  *(undefined2 *)(record + 0x1c) = 0x8000;
  *(undefined1 *)(record + 0x2c) = 0;
  *(undefined1 *)(record + 0x31) = 0;
  *(undefined1 *)(record + 0x39) = 0;
  *(undefined1 *)(record + 0x3a) = 0;
  *(undefined1 *)(record + 0x3b) = 0;
  *(undefined1 *)(record + 0x36) = 4;
  *(undefined1 *)(record + 0x37) = 4;
  return;
}

/* R520MachineAssembler__vslot65_declareNodeRegisters @ 0x19f1e0 (28 bytes) */
int R520MachineAssembler__vslot65_declareNodeRegisters(this, node, compiler)
  undefined4 this;
  undefined4 node;
  undefined4 compiler;
{
  return FUN_000e2c78(node,this,compiler);
}

/* R520MachineAssembler__vslot59_selectForSrcpSwizzle @ 0x19f1fc (48 bytes) */
int R520MachineAssembler__vslot59_selectForSrcpSwizzle(this, sourceIndex, selectOut, packedSelectOut, swizzle)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  int packedSelectOut;
  uint swizzle;
{
  int byteOffset;
  
  byteOffset = sourceIndex * 4;
  *(undefined4 *)(byteOffset + selectOut) = 3;
  *(uint *)(byteOffset + packedSelectOut) =
       swizzle >> 0x18 | *(uint *)(byteOffset + packedSelectOut) | swizzle >> 0xd & 0x7f8 | swizzle >> 2 & 0x3fc0
  ;
  return;
}

/* R520MachineAssembler__vslot60_selectForSrcpComponent @ 0x19f22c (24 bytes) */
int R520MachineAssembler__vslot60_selectForSrcpComponent(this, sourceIndex, selectOut, packedSelectOut, componentIndex)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  int packedSelectOut;
  uint componentIndex;
{
  *(undefined4 *)(sourceIndex * 4 + selectOut) = 3;
  *(uint *)(sourceIndex * 4 + packedSelectOut) = (componentIndex & 0xff) << 9;
  return;
}

/* R520MachineAssembler__vslot61_selectForAlphaSource @ 0x19f244 (84 bytes) */
int R520MachineAssembler__vslot61_selectForAlphaSource(this, sourceIndex, selectOut, packedSelectOut, sourceNumber, swizzle)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  int packedSelectOut;
  undefined4 sourceNumber;
  uint swizzle;
{
  int byteOffset;
  
  byteOffset = sourceIndex * 4;
  *(undefined4 *)(byteOffset + selectOut) = sourceNumber;
  if (swizzle >> 0x18 == 3) {
    *(uint *)(byteOffset + packedSelectOut) = *(uint *)(byteOffset + packedSelectOut) | 3;
  }
  if ((swizzle >> 0x10 & 0xff) == 3) {
    *(uint *)(byteOffset + packedSelectOut) = *(uint *)(byteOffset + packedSelectOut) | 0x18;
  }
  if ((swizzle >> 8 & 0xff) != 3) {
    return;
  }
  *(uint *)(byteOffset + packedSelectOut) = *(uint *)(byteOffset + packedSelectOut) | 0xc0;
  return;
}

/* R520MachineAssembler__vslot62_selectForSourceSwizzle @ 0x19f298 (44 bytes) */
int R520MachineAssembler__vslot62_selectForSourceSwizzle(this, sourceIndex, selectOut, packedSelectOut, sourceNumber, swizzle)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  int packedSelectOut;
  undefined4 sourceNumber;
  uint swizzle;
{
  int byteOffset;
  
  byteOffset = sourceIndex * 4;
  *(undefined4 *)(byteOffset + selectOut) = sourceNumber;
  *(uint *)(byteOffset + packedSelectOut) =
       swizzle >> 0x18 | *(uint *)(byteOffset + packedSelectOut) | swizzle >> 0xd & 0x7f8 | swizzle >> 2 & 0x3fc0
  ;
  return;
}

/* R520MachineAssembler__vslot64_selectForColorComponent @ 0x19f2c4 (40 bytes) */
int R520MachineAssembler__vslot64_selectForColorComponent(this, sourceIndex, selectOut, packedSelectOut, sourceNumber, componentIndex)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  int packedSelectOut;
  undefined4 sourceNumber;
  uint componentIndex;
{
  int byteOffset;
  
  byteOffset = sourceIndex * 4;
  *(undefined4 *)(byteOffset + selectOut) = sourceNumber;
  if ((componentIndex & 0xff) == 3) {
    return;
  }
  *(uint *)(byteOffset + packedSelectOut) = (componentIndex & 0xff) << 9 | *(uint *)(byteOffset + packedSelectOut);
  return;
}

/* R520MachineAssembler__vslot63_selectForAlphaComponent @ 0x19f2ec (36 bytes) */
int R520MachineAssembler__vslot63_selectForAlphaComponent(this, sourceIndex, selectOut, packedSelectOut, sourceNumber, componentIndex)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  int packedSelectOut;
  undefined4 sourceNumber;
  undefined4 componentIndex;
{
  int byteOffset;
  
  byteOffset = sourceIndex * 4;
  *(undefined4 *)(byteOffset + selectOut) = sourceNumber;
  if ((char)componentIndex != '\x03') {
    return;
  }
  *(uint *)(byteOffset + packedSelectOut) = *(uint *)(byteOffset + packedSelectOut) | 0x600;
  return;
}

/* R520MachineAssembler__setAluSourceAddresses @ 0x19f310 (300 bytes) */
int R520MachineAssembler__setAluSourceAddresses(this, rgbSourceMask, rgbSourceAddress, alphaSourceMask, alphaSourceAddress)
  int this;
  int rgbSourceMask;
  int *rgbSourceAddress;
  int alphaSourceMask;
  int *alphaSourceAddress;
{
  bool notLastSource;
  uint loopIndex;
  undefined2 addressHalfword;
  
  loopIndex = 1;
  do {
    if ((rgbSourceMask >> (loopIndex & 0x3f) & 1U) != 0) {
      addressHalfword = (undefined2)rgbSourceAddress[1];
      if ((-1 < rgbSourceAddress[1]) && (loopIndex == 1)) {
        *(undefined2 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0xe) = addressHalfword;
      }
      if (-1 < rgbSourceAddress[1]) {
        if (loopIndex == 2) {
          *(undefined2 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x10) = addressHalfword
          ;
        }
        else if (loopIndex == 3) {
          *(undefined2 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x12) = addressHalfword
          ;
        }
      }
    }
    notLastSource = loopIndex != 3;
    loopIndex = loopIndex + 1;
    rgbSourceAddress = rgbSourceAddress + 1;
  } while (notLastSource);
  loopIndex = 1;
  do {
    if ((alphaSourceMask >> (loopIndex & 0x3f) & 1U) != 0) {
      addressHalfword = (undefined2)alphaSourceAddress[1];
      if ((-1 < alphaSourceAddress[1]) && (loopIndex == 1)) {
        *(undefined2 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x1a) = addressHalfword;
      }
      if (-1 < alphaSourceAddress[1]) {
        if (loopIndex == 2) {
          *(undefined2 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x1c) = addressHalfword
          ;
        }
        else if (loopIndex == 3) {
          *(undefined2 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x1e) = addressHalfword
          ;
        }
      }
    }
    notLastSource = loopIndex != 3;
    loopIndex = loopIndex + 1;
    alphaSourceAddress = alphaSourceAddress + 1;
  } while (notLastSource);
  return;
}

/* R520MachineAssembler__setAlphaOpcode @ 0x19f43c (828 bytes) */
int R520MachineAssembler__setAlphaOpcode(this, hardwareOpcode, irOpcode, irInst)
  int this;
  int hardwareOpcode;
  int irOpcode;
  int irInst;
{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 alphaOpcode;
  int iVar5;
  
  alphaOpcode = (undefined1)hardwareOpcode;
  if (hardwareOpcode != -1) goto LAB_0019f708;
  if (irOpcode == 0x34) {
LAB_0019f51c:
    alphaOpcode = 0;
    iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(undefined1 *)(iVar3 + 0x3b) = *(undefined1 *)(iVar3 + 0x3a);
    iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(undefined1 *)(iVar3 + 0x3e) = *(undefined1 *)(iVar3 + 0x3d);
    iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(undefined1 *)(iVar3 + 0x38) = *(undefined1 *)(iVar3 + 0x37);
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x37) = 6;
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x3d) = 0;
  }
  else {
    if (irOpcode < 0x35) {
      if (irOpcode == 0x13) {
LAB_0019f4fc:
        alphaOpcode = 0;
        *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x38) = 4;
        goto LAB_0019f708;
      }
      if (irOpcode < 0x14) {
        if (irOpcode == 0x12) goto LAB_0019f51c;
      }
      else {
        if (irOpcode == 0x25) {
LAB_0019f5f0:
          iVar5 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          alphaOpcode = *(undefined1 *)(iVar5 + 0x39);
          *(undefined1 *)(iVar5 + 0x39) = *(undefined1 *)(iVar5 + 0x3a);
          uVar1 = *(undefined1 *)(iVar5 + 0x3c);
          iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          uVar2 = *(undefined1 *)(iVar5 + 0x36);
          *(undefined1 *)(iVar3 + 0x3c) = *(undefined1 *)(iVar3 + 0x3d);
          iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(undefined1 *)(iVar3 + 0x36) = *(undefined1 *)(iVar3 + 0x37);
          iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(undefined1 *)(iVar3 + 0x3a) = *(undefined1 *)(iVar3 + 0x3b);
          iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(undefined1 *)(iVar3 + 0x3d) = *(undefined1 *)(iVar3 + 0x3e);
          iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(undefined1 *)(iVar3 + 0x37) = *(undefined1 *)(iVar3 + 0x38);
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x3b) = alphaOpcode
          ;
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x3e) = uVar1
          ;
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x38) = uVar2
          ;
          if (irOpcode == 0x9d) {
            alphaOpcode = 5;
          }
          else {
            alphaOpcode = 6;
          }
          goto LAB_0019f708;
        }
        if (irOpcode == 0x31) {
LAB_0019f5b4:
          alphaOpcode = 0;
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x37) = 6;
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x38) = 4;
          goto LAB_0019f708;
        }
      }
    }
    else {
      if (irOpcode == 0x8b) goto LAB_0019f51c;
      if (irOpcode < 0x8c) {
        if (irOpcode == 0x36) goto LAB_0019f4fc;
        if (irOpcode == 0x66) goto LAB_0019f5b4;
      }
      else {
        if (irOpcode == 0x9d) goto LAB_0019f5f0;
        if (irOpcode == 0xb4) {
          alphaOpcode = 0;
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x36) = 4;
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x37) = 4;
          goto LAB_0019f708;
        }
      }
    }
    alphaOpcode = 0xff;
  }
LAB_0019f708:
  *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x40) = alphaOpcode;
  if (*(int *)(irInst + 0x120) != 0) {
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x42) = 1;
  }
  iVar5 = *(int *)(this + 0x60);
  iVar3 = *(int *)(this + 0xa8);
  alphaOpcode = psnOutputScaleCode(*(undefined4 *)(irInst + 0x124));
  *(undefined1 *)(iVar5 * 0x48 + iVar3 + 0x41) = alphaOpcode;
  return;
}

/* R520MachineAssembler__vslot77_setRecordByteB @ 0x19f778 (44 bytes) */
int R520MachineAssembler__vslot77_setRecordByteB(this)
  int this;
{
  if (*(int *)(this + 0x60) <= *(int *)(this + 0x74) + 1) {
    return;
  }
  *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0xb) = 1;
  return;
}

/* R520MachineAssembler__writeHeaderRecord @ 0x19f7a4 (188 bytes) */
int R520MachineAssembler__writeHeaderRecord(this, highestConstant, pixelSize)
  int this;
  undefined4 highestConstant;
  undefined4 pixelSize;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int header;
  
  *(undefined2 *)(*(int *)(this + 0xa8) + 0x24) = (*(unsigned short *)((unsigned char *)&(highestConstant) + 2));
  header = *(int *)(this + 0xa8);
  *(int *)(header + 8) = *(int *)(this + 0x60) + -1;
  uVar1 = *(undefined4 *)(this + 0x9c);
  *(undefined1 *)(header + 0xd) = 6;
  *(char *)(header + 0xe) = (char)uVar1;
  *(undefined1 *)(header + 0xf) = 0;
  *(undefined2 *)(header + 0x10) = 0;
  *(undefined1 *)(header + 0xc) = 0;
  uVar1 = *(undefined4 *)(this + 0x74);
  uVar2 = *(undefined4 *)(this + 0x60);
  *(undefined2 *)(header + 0x14) = 1;
  *(undefined2 *)(header + 0x16) = 1;
  *(short *)(header + 0x12) = ((short)uVar2 - (short)uVar1) + -2;
  *(short *)(header + 0x18) = (short)*(undefined4 *)(this + 0x74);
  *(short *)(header + 0x1a) = (short)*(undefined4 *)(this + 0x68);
  *(short *)(header + 0x1c) = (short)*(undefined4 *)(this + 100);
  *(short *)(header + 0x1e) = (short)*(undefined4 *)(this + 100);
  uVar1 = *(undefined4 *)(this + 100);
  uVar2 = *(undefined4 *)(this + 0x60);
  uVar4 = *(undefined4 *)(this + 0x68);
  uVar3 = *(undefined4 *)(this + 0x74);
  *(undefined2 *)(header + 0x22) = (*(unsigned short *)((unsigned char *)&(pixelSize) + 2));
  *(short *)(header + 0x20) = ((((short)uVar2 - (short)uVar1) - (short)uVar4) - (short)uVar3) + -1;
  *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + -0x3e) = 1;
  return;
}

/* R520MachineAssembler__vslot9_getRecordWordsUsed @ 0x19f860 (32 bytes) */
int R520MachineAssembler__vslot9_getRecordWordsUsed(param_1, param_2)
  int param_1;
  int *param_2;
{
  *param_2 = *(int *)(param_1 + 0x60) * 0x48 >> 2;
  return;
}

/* R520MachineAssembler__vslot38_appendBranchRecord @ 0x19f880 (240 bytes) */
int R520MachineAssembler__vslot38_appendBranchRecord(this, condition, branchArg)
  int *this;
  int condition;
  undefined4 branchArg;
{
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  
  *(undefined4 *)(this[0x18] * 0x48 + this[0x2a]) = 5;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0xe) = 0;
  if (condition == 0) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x12) = 0x55;
  }
  else {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x12) = 0xaa;
  }
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x14) = 0;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x15) = 0;
  *(char *)(this[0x18] * 0x48 + this[0x2a] + 0x17) = (char)branchArg;
  (**(code **)(*this + 0x15c))(this,condition,branchArg,in_r6,in_r7,in_r8,*this);
  return this[0x18] + -1;
}

/* R520MachineAssembler__vslot80_setRecordByte9 @ 0x19f970 (28 bytes) */
int R520MachineAssembler__vslot80_setRecordByte9(this)
  int this;
{
  *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 9) = 1;
  return;
}

/* R520MachineAssembler__vslot55_tryEncodeImmediateLiteral @ 0x19f98c (204 bytes) */
int R520MachineAssembler__vslot55_tryEncodeImmediateLiteral(this, node, immediateOut, param_4, param_5, param_6, param_7, param_8)
  int this;
  int node;
  uint *immediateOut;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  float literalValue;
  uint loopIndex;
  int iVar3;
  int loopRemaining;
  int local_28;
  uint local_24 [7];
  
  if (*(int *)(node + 300) == 3) {
    loopIndex = 0;
    loopRemaining = 4;
    iVar3 = node;
    do {
      if ((((int)*(char *)(node + 0x15c) >> (loopIndex & 0x3f) & 1U) != 0) &&
         (*(int *)(iVar3 + 0x1c) == 2)) {
        literalValue = *(float *)(loopIndex * 0x18 + node + 0x20);
        break;
      }
      loopIndex = loopIndex + 1;
      iVar3 = iVar3 + 0x18;
      loopRemaining = loopRemaining + -1;
      literalValue = FLOAT_001aa0d4;
    } while (loopRemaining != 0);
    iVar3 = ((undefined4 (*)())FudoPs__encodeImmediateFloat)(*(undefined4 *)(this + 0xa4),node,&local_28,local_24,(double)literalValue);
    if (iVar3 != 0) {
      *immediateOut = local_24[0] | local_28 << 3 | 0x2000;
      return 1;
    }
  }
  return 0;
}

/* R520MachineAssembler__vslot67_selectForConstantLanes @ 0x19fa58 (300 bytes) */
int R520MachineAssembler__vslot67_selectForConstantLanes(this, sourceIndex, packedBase, inst, lane)
  undefined4 this;
  int sourceIndex;
  int packedBase;
  int inst;
  uint lane;
{
  float callResult;
  uint packedBits;
  uint laneSelector;
  int *a0;
  int operandRecord;
  uint *packedWord;
  int loopIndex;
  
  if (1 < *(int *)(inst + 0x84)) {
    packedWord = (uint *)(packedBase + sourceIndex * 4);
    loopIndex = 2;
    do {
      a0 = (int *)IRInst__getOperandSource(inst,loopIndex);
      if (((a0 != (int *)0x0) && (operandRecord = (**(code **)(*a0 + 0x48))(a0), operandRecord != 0)) &&
         ((lane & 0xff) < 4)) {
        operandRecord = IRInst__getOperandRecord(inst,loopIndex);
        laneSelector = (uint)*(byte *)((lane & 0xff) + operandRecord + 0x10);
        if (laneSelector < 4) {
          packedBits = *packedWord & 0xfffff1ff;
          callResult = GH_U2F((unsigned int)(a0[laneSelector * 6 + 8]));
          *packedWord = packedBits;
          if (callResult == 0.0) {
            *packedWord = packedBits | 0x800;
          }
          else if (callResult == 0.5) {
            *packedWord = packedBits | 0xa00;
          }
          else if (callResult == 1.0) {
            *packedWord = packedBits | 0xc00;
          }
        }
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex <= *(int *)(inst + 0x84));
  }
  return;
}

/* R520MachineAssembler__beginNextRecord @ 0x19fb84 (320 bytes) */
int R520MachineAssembler__beginNextRecord(this)
  int *this;
{
  int recordPtr;
  
  if (this[0x1d] == 0) {
    recordPtr = this[0x2a] + this[0x18] * 0x48;
    _memcpy(recordPtr + 0x48,recordPtr,0x48);
    _memset(this[0x18] * 0x48 + this[0x2a],0,0x48);
    this[0x18] = 2;
    this[0x1d] = 1;
    (**(code **)(*this + 0xc4))(this,1,0,0,0,0);
    (**(code **)(*this + 200))(this,1,0,0,0,0);
    (**(code **)(*this + 0xcc))(this,1,0xf);
    (**(code **)(*this + 0xd0))(this,1,0xf);
  }
  this[0x21] = 1;
  this[0x20] = 1;
  this[0x18] = this[0x18] + 1;
  return;
}

/* R520MachineAssembler__vslot4_finishProgram @ 0x19fccc (292 bytes) */
int R520MachineAssembler__vslot4_finishProgram(param_1)
  int *param_1;
{
  int callResult;
  int iVar2;
  
  iVar2 = 0;
  *(int *)(param_1[0x2b] + 0x93b8) = param_1[0x24];
  *(int *)(param_1[0x2b] + 0x9364) = *(int *)(*(int *)(param_1[3] + 0x6c4) + 0x7c) + 1;
  *(undefined4 *)(param_1[0x2b] + 0x9368) = *(undefined4 *)(*(int *)(param_1[3] + 0x6c4) + 0x84);
  callResult = FUN_0013061c(*(undefined4 *)(param_1[3] + 0x6c4),0);
  if (callResult != 0) {
    iVar2 = callResult + -1;
  }
  if ((*(int *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x48) != 3) ||
     (param_1[0x2d] == (param_1[0x18] - param_1[0x1d]) + -1)) {
    (**(code **)(*param_1 + 0xbc))(param_1);
    (**(code **)(*param_1 + 0xc0))(param_1);
    (**(code **)(*param_1 + 0x15c))(param_1);
  }
                    
                    
  (**(code **)(*param_1 + 0x144))(param_1,param_1[0x1e],iVar2);
  return;
}

/* R520MachineAssembler__vslot79_setTexCompareFlags @ 0x19fdf0 (316 bytes) */
int R520MachineAssembler__vslot79_setTexCompareFlags(this, textureClass, compareMode)
  int this;
  int textureClass;
  int compareMode;
{
  int recordsBase;
  int recordOffset;
  undefined1 modeValue;
  
  if (textureClass != 2) {
    if (textureClass != 3) {
      return;
    }
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 6) = 1;
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 8) = 1;
  }
  if (compareMode == DAT_001b2d68) {
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 5) = 1;
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 7) = 5;
    return;
  }
  if (compareMode == DAT_001b2d64) {
    modeValue = 2;
    recordsBase = *(int *)(this + 0xa8);
    recordOffset = *(int *)(this + 0x60) * 0x48;
  }
  else if (compareMode == DAT_001b2d60) {
    modeValue = 3;
    recordsBase = *(int *)(this + 0xa8);
    recordOffset = *(int *)(this + 0x60) * 0x48;
  }
  else if (compareMode == DAT_001b2d5c) {
    modeValue = 4;
    recordsBase = *(int *)(this + 0xa8);
    recordOffset = *(int *)(this + 0x60) * 0x48;
  }
  else {
    if (compareMode != DAT_001b2d58) {
      return;
    }
    modeValue = 5;
    recordsBase = *(int *)(this + 0xa8);
    recordOffset = *(int *)(this + 0x60) * 0x48;
  }
  *(undefined1 *)(recordOffset + recordsBase + 5) = modeValue;
  *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 7) = modeValue;
  return;
}

/* R520MachineAssembler__vslot31_assembleChildrenAndMark @ 0x19ff2c (176 bytes) */
int R520MachineAssembler__vslot31_assembleChildrenAndMark(this, node, block)
  int *this;
  int node;
  undefined4 block;
{
  int child;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint loopIndex;
  int childByteOffset;
  int recordIndexBefore;
  
  recordIndexBefore = this[0x18];
  (**(code **)(*this + 0x34))
            (this,block,*(undefined4 *)(node + 0xdc),in_r6,in_r7,in_r8,
             *(code **)(*this + 0x34));
  if ((*(int *)(node + 0xdc) != 0) && (recordIndexBefore == this[0x18])) {
    recordIndexBefore = *(int *)(node + 0xd0);
    childByteOffset = 0;
    for (loopIndex = 1; loopIndex <= *(uint *)(recordIndexBefore + 4); loopIndex = loopIndex + 1) {
      child = *(int *)(childByteOffset + *(int *)(recordIndexBefore + 8));
      if (child != 0) {
        *(undefined4 *)(child + 0xdc) = 1;
      }
      childByteOffset = childByteOffset + 4;
    }
  }
  return;
}

/* R520MachineAssembler__vslot24_assembleWithTarget @ 0x19ffdc (216 bytes) */
int R520MachineAssembler__vslot24_assembleWithTarget(this, node, block)
  int *this;
  int node;
  undefined4 block;
{
  bool emittedNothing;
  undefined4 uVar2;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int recordIndexBefore;
  code *pcVar4;
  
  recordIndexBefore = this[0x18];
  (**(code **)(*this + 0x34))
            (this,block,*(undefined4 *)(node + 0xdc),in_r6,in_r7,in_r8,
             *(code **)(*this + 0x34));
  if ((*(int *)(node + 0xdc) == 0) || (emittedNothing = true, recordIndexBefore != this[0x18])) {
    emittedNothing = false;
  }
  pcVar4 = *(code **)(*this + 0x9c);
  uVar2 = FUN_000e7d5c(node);
  (*pcVar4)(this,uVar2,*(undefined4 *)(node + 0x134));
  if (emittedNothing) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + -0x44) = 1;
  }
  if (*(int *)(node + 0x134) != 0) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + -0x3a) = 3;
  }
  return;
}

/* R520MachineAssembler__setRgbOpcode @ 0x1a00b4 (1552 bytes) */
int R520MachineAssembler__setRgbOpcode(this, hardwareOpcode, irOpcode, irInst)
  int this;
  int hardwareOpcode;
  int irOpcode;
  int irInst;
{
  undefined1 uVar1;
  uint uVar2;
  undefined1 rgbOpcode;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  rgbOpcode = (undefined1)hardwareOpcode;
  if (hardwareOpcode != -1) goto LAB_001a0654;
  if (irOpcode == 0x34) {
LAB_001a0260:
    rgbOpcode = 0;
    iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(undefined1 *)(iVar4 + 0x2c) = *(undefined1 *)(iVar4 + 0x2b);
    iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(undefined1 *)(iVar4 + 0x2f) = *(undefined1 *)(iVar4 + 0x2e);
    iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(uint *)(iVar4 + 0x28) =
         (*(uint *)(iVar4 + 0x24) & 0xe000) << 0x10 | *(uint *)(iVar4 + 0x28) & 0x1fffffff;
    iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(uint *)(iVar4 + 0x28) =
         (*(uint *)(iVar4 + 0x24) & 0x1c00) << 0x10 | *(uint *)(iVar4 + 0x28) & 0xe3ffffff;
    iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(uint *)(iVar4 + 0x28) =
         (*(uint *)(iVar4 + 0x24) & 0x380) << 0x10 | *(uint *)(iVar4 + 0x28) & 0xfc7fffff;
    iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffff1fff | 0xc000;
    iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffffe3ff | 0x1800;
    iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xfffffc7f | 0x300;
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x2e) = 0;
  }
  else {
    if (irOpcode < 0x35) {
      if (irOpcode == 0x13) {
LAB_001a0200:
        rgbOpcode = 0;
        iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
        *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0x1fffffff | 0x80000000;
        iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
        *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xe3ffffff | 0x10000000;
        iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
        *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xfc7fffff | 0x2000000;
        goto LAB_001a0654;
      }
      if (irOpcode < 0x14) {
        if (irOpcode == 0x12) goto LAB_001a0260;
      }
      else {
        if (irOpcode == 0x25) {
LAB_001a044c:
          iVar6 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          rgbOpcode = *(undefined1 *)(iVar6 + 0x2a);
          *(undefined1 *)(iVar6 + 0x2a) = *(undefined1 *)(iVar6 + 0x2b);
          uVar5 = *(uint *)(iVar6 + 0x24);
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          uVar1 = *(undefined1 *)(iVar6 + 0x2d);
          *(undefined1 *)(iVar4 + 0x2d) = *(undefined1 *)(iVar4 + 0x2e);
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          uVar2 = *(uint *)(iVar4 + 0x24);
          *(uint *)(iVar4 + 0x24) = (uVar2 & 0x1c00) << 0x10 | uVar2 & 0xe3ffffff;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          uVar2 = *(uint *)(iVar4 + 0x24);
          *(uint *)(iVar4 + 0x24) = (uVar2 & 0x380) << 0x10 | uVar2 & 0xfc7fffff;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          uVar2 = *(uint *)(iVar4 + 0x24);
          *(uint *)(iVar4 + 0x24) = (uVar2 & 0xe000) << 0x10 | uVar2 & 0x1fffffff;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(undefined1 *)(iVar4 + 0x2b) = *(undefined1 *)(iVar4 + 0x2c);
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(undefined1 *)(iVar4 + 0x2e) = *(undefined1 *)(iVar4 + 0x2f);
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x24) =
               *(uint *)(iVar4 + 0x28) >> 0x10 & 0xe000 | *(uint *)(iVar4 + 0x24) & 0xffff1fff;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x24) =
               *(uint *)(iVar4 + 0x28) >> 0x10 & 0x1c00 | *(uint *)(iVar4 + 0x24) & 0xffffe3ff;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x24) =
               *(uint *)(iVar4 + 0x28) >> 0x10 & 0x380 | *(uint *)(iVar4 + 0x24) & 0xfffffc7f;
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x2c) = rgbOpcode
          ;
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x2f) = uVar1
          ;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x28) = uVar5 & 0xe0000000 | *(uint *)(iVar4 + 0x28) & 0x1fffffff;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x28) = uVar5 & 0x1c000000 | *(uint *)(iVar4 + 0x28) & 0xe3ffffff;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x28) = uVar5 & 0x3800000 | *(uint *)(iVar4 + 0x28) & 0xfc7fffff;
          if (irOpcode == 0x9d) {
            rgbOpcode = 7;
          }
          else {
            rgbOpcode = 8;
          }
          goto LAB_001a0654;
        }
        if (irOpcode == 0x31) {
LAB_001a0390:
          rgbOpcode = 0;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffff1fff | 0xc000;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffffe3ff | 0x1800;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xfffffc7f | 0x300;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0x1fffffff | 0x80000000;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xe3ffffff | 0x10000000;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xfc7fffff | 0x2000000;
          goto LAB_001a0654;
        }
      }
    }
    else {
      if (irOpcode == 0x8b) goto LAB_001a0260;
      if (irOpcode < 0x8c) {
        if (irOpcode == 0x36) goto LAB_001a0200;
        if (irOpcode == 0x66) goto LAB_001a0390;
      }
      else {
        if (irOpcode == 0x9d) goto LAB_001a044c;
        if (irOpcode == 0xb4) {
          *(undefined4 *)(this + 0x9c) = 1;
          rgbOpcode = 0;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xfc7fffff | 0x3000000;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffff1fff | 0xc000;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffffe3ff | 0x1800;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0x1fffffff | 0x80000000;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xfc7fffff | 0x2000000;
          iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xe3ffffff | 0x10000000;
          goto LAB_001a0654;
        }
      }
    }
    rgbOpcode = 0xff;
  }
LAB_001a0654:
  *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x31) = rgbOpcode;
  if (*(int *)(irInst + 0x120) != 0) {
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x33) = 1;
  }
  iVar6 = *(int *)(this + 0x60);
  iVar4 = *(int *)(this + 0xa8);
  rgbOpcode = psnOutputScaleCode(*(undefined4 *)(irInst + 0x124));
  *(undefined1 *)(iVar6 * 0x48 + iVar4 + 0x32) = rgbOpcode;
  return;
}

/* R520MachineAssembler__vslot86_resolveSourceRegister @ 0x1a06c4 (252 bytes) */
int R520MachineAssembler__vslot86_resolveSourceRegister(this, inst, sourceIndex, compiler)
  undefined4 this;
  undefined4 inst;
  undefined4 sourceIndex;
  int compiler;
{
  int *callResult;
  int iVar2;
  uint registerWord;
  
  callResult = (int *)IRInst__getOperandSource(inst,sourceIndex);
  if (((((callResult[0x20] == 0) || (iVar2 = RegKind__flagBit0(callResult[0x26]), iVar2 == 0)) ||
       ((callResult[5] & 2U) != 0)) || (iVar2 = (**(code **)(*callResult + 0x50))(callResult), iVar2 != 0)) &&
     (iVar2 = (**(code **)(*callResult + 0x50))(callResult), iVar2 == 0)) {
    registerWord = 0;
    if (callResult[0x26] == 0x29) {
      iVar2 = IRInst__getDefiningField128(inst,sourceIndex);
      registerWord = iVar2 + *(int *)(*(int *)(compiler + COMP_currentProgram) + 0x3f0) | 0x4000;
    }
    return registerWord;
  }
  registerWord = thunk_FUN_00134de8(*(undefined4 *)(compiler + COMP_currentProgram),callResult);
  return registerWord;
}

/* R520MachineAssembler__vslot53_selectBitsForLiteralFloat @ 0x1a07c0 (304 bytes) */
int R520MachineAssembler__vslot53_selectBitsForLiteralFloat(this, sourceIndex, param_3, selectBase, inst)
  undefined4 this;
  int sourceIndex;
  undefined4 param_3;
  int selectBase;
  undefined4 inst;
{
  bool lastLane;
  float literalValue;
  float zeroLiteral;
  float halfLiteral;
  uint laneSelector;
  int operandVReg;
  int operandRecord;
  int loopIndex;
  uint *selectWord;
  uint bitShift;
  
  operandVReg = IRInst__getOperandSource(inst,sourceIndex);
  halfLiteral = FLOAT_001aa10c;
  zeroLiteral = FLOAT_001aa0d4;
  selectWord = (uint *)(selectBase + sourceIndex * 4);
  loopIndex = 0;
  bitShift = 0;
  do {
    operandRecord = IRInst__getOperandRecord(inst,sourceIndex);
    laneSelector = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
    if (laneSelector < 4) {
      literalValue = *(float *)(laneSelector * 0x18 + operandVReg + 0x20);
      if (literalValue == zeroLiteral) {
LAB_001a08b4:
        *selectWord = 4 << (bitShift & 0x3f) | *selectWord;
      }
      else if (literalValue == halfLiteral) {
        *selectWord = 5 << (bitShift & 0x3f) | *selectWord;
      }
      else if (literalValue == 1.0) {
        *selectWord = 6 << (bitShift & 0x3f) | *selectWord;
      }
    }
    else {
      if (laneSelector != 6) goto LAB_001a08b4;
      *selectWord = 6 << (bitShift & 0x3f) | *selectWord;
    }
    lastLane = loopIndex == 2;
    bitShift = bitShift + 3;
    loopIndex = loopIndex + 1;
    if (lastLane) {
      return;
    }
  } while( true );
}

/* R520MachineAssembler__vslot54_selectBitsForAlphaLiteral @ 0x1a08f0 (224 bytes) */
int R520MachineAssembler__vslot54_selectBitsForAlphaLiteral(this, sourceIndex, selectOut, selectBase, inst)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  int selectBase;
  undefined4 inst;
{
  float literalValue;
  int byteOffset;
  uint laneSelector;
  int operandVReg;
  int operandRecord;
  
  operandVReg = IRInst__getOperandSource(inst,sourceIndex);
  byteOffset = sourceIndex * 4;
  *(undefined4 *)(byteOffset + selectOut) = 0;
  operandRecord = IRInst__getOperandRecord(inst,sourceIndex);
  laneSelector = (uint)*(byte *)(operandRecord + 0x13);
  if (laneSelector < 4) {
    literalValue = *(float *)(laneSelector * 0x18 + operandVReg + 0x20);
    if (literalValue == FLOAT_001aa0d4) {
LAB_001a09b0:
      *(uint *)(byteOffset + selectBase) = *(uint *)(byteOffset + selectBase) | 0x800;
      return;
    }
    if (literalValue == FLOAT_001aa10c) {
      *(uint *)(byteOffset + selectBase) = *(uint *)(byteOffset + selectBase) | 0xa00;
      return;
    }
    if (literalValue != FLOAT_001aa0e8) {
      return;
    }
  }
  else if (laneSelector != 6) goto LAB_001a09b0;
  *(uint *)(byteOffset + selectBase) = *(uint *)(byteOffset + selectBase) | 0xc00;
  return;
}

/* R520MachineAssembler__vslot66_selectBitsForLiteralLanes @ 0x1a09d0 (364 bytes) */
int R520MachineAssembler__vslot66_selectBitsForLiteralLanes(this, sourceIndex, packedBase, inst, laneSelectors)
  undefined4 this;
  int sourceIndex;
  int packedBase;
  int inst;
  undefined4 laneSelectors;
{
  unsigned int ghidra_home[8] = { this, sourceIndex, packedBase, inst, laneSelectors, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool bVar1;
  byte bVar2;
  float callResult;
  uint uVar4;
  int *a0;
  int operandRecord;
  uint *packedWord;
  byte *loopIndex2;
  int loopIndex;
  uint uVar9;
  
  if (1 < *(int *)(inst + 0x84)) {
    loopIndex = 2;
    packedWord = (uint *)(packedBase + sourceIndex * 4);
    (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = laneSelectors;
    do {
      a0 = (int *)IRInst__getOperandSource(inst,loopIndex);
      if ((a0 != (int *)0x0) && (operandRecord = (**(code **)(*a0 + 0x48))(a0), operandRecord != 0)) {
        loopIndex2 = (byte *)&(*(unsigned int *)((unsigned char *)ghidra_home + 16));
        uVar9 = 0;
        do {
          bVar2 = *loopIndex2;
          if (bVar2 < 4) {
            operandRecord = IRInst__getOperandRecord(inst,loopIndex);
            uVar4 = (uint)*(byte *)((uint)bVar2 + operandRecord + 0x10);
            if (uVar4 < 4) {
              callResult = GH_U2F((unsigned int)(a0[uVar4 * 6 + 8]));
              if (callResult == 0.0) {
                *packedWord = *packedWord & ~(7 << (uVar9 & 0x3f)) | 4 << (uVar9 & 0x3f);
              }
              else if (callResult == 0.5) {
                *packedWord = *packedWord & ~(7 << (uVar9 & 0x3f)) | 5 << (uVar9 & 0x3f);
              }
              else if (callResult == 1.0) {
                *packedWord = *packedWord & ~(7 << (uVar9 & 0x3f)) | 6 << (uVar9 & 0x3f);
              }
            }
          }
          bVar1 = uVar9 != 6;
          loopIndex2 = loopIndex2 + 1;
          uVar9 = uVar9 + 3;
        } while (bVar1);
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex <= *(int *)(inst + 0x84));
  }
  return;
}

/* R520MachineAssembler__vslot71_setAluSourceSelectsAndModifiers @ 0x1a0b3c (1192 bytes) */
int R520MachineAssembler__vslot71_setAluSourceSelectsAndModifiers(this, irInst, writeRgb, rgbSelects, rgbPacked, writeAlpha, alphaSelects, alphaPacked)
  int this;
  int *irInst;
  int writeRgb;
  int rgbSelects;
  int rgbPacked;
  int writeAlpha;
  int alphaSelects;
  int alphaPacked;
{
  bool writeRgbFlag;
  bool writeAlphaFlag;
  int iVar3;
  int sourceCount;
  undefined1 modifierBits;
  int loopIndex;
  
  sourceCount = (**(code **)(*irInst + 0x14))
                    (irInst,irInst,writeRgb,rgbSelects,rgbPacked,writeAlpha,alphaSelects,alphaPacked);
  if (*(int *)(irInst[0x22] + 8) == 0xb4) {
    sourceCount = 3;
  }
  else if (sourceCount < 1) {
    return;
  }
  writeRgbFlag = writeRgb != 0;
  writeAlphaFlag = writeAlpha != 0;
  do {
    if (writeRgbFlag) {
      *(char *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x2a) =
           (char)*(undefined4 *)(rgbSelects + 4);
      loopIndex = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
      *(uint *)(loopIndex + 0x24) = *(int *)(rgbPacked + 4) << 0x1d | *(uint *)(loopIndex + 0x24) & 0x1fffffff
      ;
      loopIndex = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
      *(uint *)(loopIndex + 0x24) =
           (*(uint *)(rgbPacked + 4) & 0x38) << 0x17 | *(uint *)(loopIndex + 0x24) & 0xe3ffffff;
      loopIndex = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
      *(uint *)(loopIndex + 0x24) =
           (*(uint *)(rgbPacked + 4) & 0x1c0) << 0x11 | *(uint *)(loopIndex + 0x24) & 0xfc7fffff;
    }
    if (writeAlphaFlag) {
      *(char *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x39) =
           (char)*(undefined4 *)(alphaSelects + 4);
      *(byte *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x36) =
           (byte)(*(uint *)(alphaPacked + 4) >> 9) & 7;
    }
    loopIndex = 1;
    while( true ) {
      iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
      *(byte *)(iVar3 + 0x2a) = *(byte *)(iVar3 + 0x2a) | 0x80;
      iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
      *(byte *)(iVar3 + 0x39) = *(byte *)(iVar3 + 0x39) | 0x80;
      iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
      *(byte *)(iVar3 + 0x2b) = *(byte *)(iVar3 + 0x2b) | 0x80;
      iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
      *(byte *)(iVar3 + 0x3a) = *(byte *)(iVar3 + 0x3a) | 0x80;
      iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
      *(byte *)(iVar3 + 0x2c) = *(byte *)(iVar3 + 0x2c) | 0x80;
      iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
      *(byte *)(iVar3 + 0x3b) = *(byte *)(iVar3 + 0x3b) | 0x80;
      modifierBits = packSourceModifier(irInst[loopIndex * 6 + 0x28] & 1,(uint)irInst[loopIndex * 6 + 0x28] >> 1 & 1);
      if (writeAlphaFlag) {
        if (loopIndex == 1) {
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x3c) = modifierBits
          ;
        }
        else if (loopIndex == 2) {
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x3d) = modifierBits
          ;
        }
        else if (loopIndex == 3) {
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x3e) = modifierBits
          ;
        }
      }
      if (writeRgbFlag) {
        if (loopIndex == 1) {
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x2d) = modifierBits
          ;
        }
        else if (loopIndex == 2) {
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x2e) = modifierBits
          ;
        }
        else if (loopIndex == 3) {
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x2f) = modifierBits
          ;
        }
      }
      loopIndex = loopIndex + 1;
      if (sourceCount < loopIndex) {
        return;
      }
      if (loopIndex == 1) break;
      if (loopIndex == 2) {
        if (writeRgbFlag) {
          *(char *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x2b) =
               (char)*(undefined4 *)(rgbSelects + 8);
          iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar3 + 0x24) =
               (*(uint *)(rgbPacked + 8) & 7) << 0xd | *(uint *)(iVar3 + 0x24) & 0xffff1fff;
          iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar3 + 0x24) =
               (*(uint *)(rgbPacked + 8) & 0x38) << 7 | *(uint *)(iVar3 + 0x24) & 0xffffe3ff;
          iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar3 + 0x24) =
               (*(uint *)(rgbPacked + 8) & 0x1c0) << 1 | *(uint *)(iVar3 + 0x24) & 0xfffffc7f;
        }
        if (writeAlphaFlag) {
          *(char *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x3a) =
               (char)*(undefined4 *)(alphaSelects + 8);
          *(byte *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x37) =
               (byte)(*(uint *)(alphaPacked + 8) >> 9) & 7;
        }
      }
      else if (loopIndex == 3) {
        if (writeRgbFlag) {
          *(char *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x2c) =
               (char)*(undefined4 *)(rgbSelects + 0xc);
          iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar3 + 0x28) =
               *(int *)(rgbPacked + 0xc) << 0x1d | *(uint *)(iVar3 + 0x28) & 0x1fffffff;
          iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar3 + 0x28) =
               (*(uint *)(rgbPacked + 0xc) & 0x38) << 0x17 | *(uint *)(iVar3 + 0x28) & 0xe3ffffff;
          iVar3 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(iVar3 + 0x28) =
               (*(uint *)(rgbPacked + 0xc) & 0x1c0) << 0x11 | *(uint *)(iVar3 + 0x28) & 0xfc7fffff;
        }
        if (writeAlphaFlag) {
          *(char *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x3b) =
               (char)*(undefined4 *)(alphaSelects + 0xc);
          *(byte *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x38) =
               (byte)(*(uint *)(alphaPacked + 0xc) >> 9) & 7;
        }
      }
    }
  } while( true );
}

/* evaluateConstantComparison @ 0x1a0fe4 (356 bytes) */
int evaluateConstantComparison(inst, resultKnownOut)
  int inst;
  undefined4 *resultKnownOut;
{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  int local_48;
  float local_44;
  int local_30;
  float local_2c;
  
  uVar1 = DAT_001b2d70;
  iVar2 = IRInst__getUniformSourceConstant(inst,1,DAT_001b2d70,&local_48);
  if ((((iVar2 == 0) || (local_48 != 2)) ||
      (iVar2 = IRInst__getUniformSourceConstant(inst,2,uVar1,&local_30), iVar2 == 0)) || (local_30 != 2)) {
    bVar3 = false;
    *resultKnownOut = 0;
  }
  else {
    bVar3 = false;
    switch(*(undefined4 *)(inst + 300)) {
    case 0:
      bVar3 = local_44 == local_2c;
      break;
    case 1:
      bVar3 = local_44 != local_2c;
      break;
    case 2:
      bVar3 = local_2c < local_44;
      break;
    case 3:
      bVar3 = local_2c <= local_44;
      break;
    case 4:
      bVar3 = local_44 < local_2c;
      break;
    case 5:
      bVar3 = local_44 <= local_2c;
    }
    *resultKnownOut = 1;
  }
  return bVar3;
}

/* R520MachineAssembler__vslot29_patchBranchTarget @ 0x1a1160 (144 bytes) */
int R520MachineAssembler__vslot29_patchBranchTarget(this)
  int this;
{
  int stackVector;
  uint stackCount;
  int *piVar3;
  int popped;
  
  piVar3 = (int *)0x0;
  stackVector = *(int *)(*(int *)(this + 0x10) + 0x24);
  stackCount = *(uint *)(stackVector + 4);
  if (stackCount - 1 < stackCount) {
    piVar3 = (int *)((stackCount - 1) * 4 + *(int *)(stackVector + 8));
  }
  popped = *piVar3;
  Vector__removeAt(stackVector,stackCount - 1);
  *(short *)(popped * 0x48 + *(int *)(this + 0xa8) + 0xc) =
       ((short)*(undefined4 *)(this + 0x60) - (short)*(undefined4 *)(this + 0x74)) + -1;
  *(int *)(this + 0xb4) = (*(int *)(this + 0x60) - *(int *)(this + 0x74)) + -1;
  return;
}

/* R520MachineAssembler__vslot26_assembleThenAppendRecord @ 0x1a11f0 (328 bytes) */
int R520MachineAssembler__vslot26_assembleThenAppendRecord(this, node, block, compiler, param_5, param_6, param_7)
  int *this;
  int node;
  undefined4 block;
  int compiler;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 sourceDef;
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int a3;
  uint uVar6;
  undefined4 uVar7;
  uint *puVar8;
  
  a3 = compiler;
  iVar3 = Block__getBranchInst(node,node,block,compiler,param_5,param_6,param_7);
  uVar7 = *(undefined4 *)(compiler + COMP_currentProgram);
  iVar2 = *(int *)(iVar3 + 300);
  sourceDef = IRInst__getOperandSource(iVar3,1);
  uVar4 = thunk_FUN_00134de8(uVar7,sourceDef);
  iVar3 = this[0x18];
  (**(code **)(*this + 0x34))
            (this,block,*(undefined4 *)(node + 0xdc),a3,param_5,param_6,
             *(code **)(*this + 0x34));
  if ((*(int *)(node + 0xdc) == 0) || (bVar1 = true, iVar3 != this[0x18])) {
    bVar1 = false;
  }
  uVar4 = (**(code **)(*this + 0x98))(this,iVar2 != 1,uVar4,0);
  if (bVar1) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + -0x44) = 1;
  }
  puVar8 = *(uint **)(this[4] + 0x24);
  uVar6 = puVar8[1];
  if (uVar6 < *puVar8) {
    _memset(uVar6 * 4 + puVar8[2],0,4);
    puVar5 = (undefined4 *)(uVar6 * 4 + puVar8[2]);
    puVar8[1] = uVar6 + 1;
  }
  else {
    puVar5 = (undefined4 *)Vector__elementRefGrow(puVar8,uVar6);
  }
  *puVar5 = uVar4;
  return;
}

/* R520MachineAssembler__create @ 0x1a1338 (96 bytes) */
int R520MachineAssembler__create(unusedThis, compiler)
  undefined4 unusedThis;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaB);
  allocation = (undefined4 *)Arena__alloc(arena,((unsigned char *)0x000010c4U));
  *allocation = arena;
  allocation[1] = &PTR_FUN_001eb9a8;
  allocation[7] = 0;
  return allocation + 1;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_0019d858");
asm(".set FUN_0019d858, _R520VMachineAssembler__vslot27_assembleLoopHeader");
asm(".globl FUN_0019dc48");
asm(".set FUN_0019dc48, _R520VMachineAssembler__vslot30_assembleBlockThenSlot40");
asm(".globl FUN_0019dcb0");
asm(".set FUN_0019dcb0, _R520VMachineAssembler__deleting_dtor");
asm(".globl FUN_0019dd7c");
asm(".set FUN_0019dd7c, _R520VMachineAssembler__init");
asm(".globl FUN_0019de50");
asm(".set FUN_0019de50, _R520VMachineAssembler__create");
asm(".globl FUN_0019df54");
asm(".set FUN_0019df54, _MachineAssembler__dtor_19df54");
asm(".globl FUN_0019dff8");
asm(".set FUN_0019dff8, _R520VMachineAssembler__vslot28_assembleIfEnd");
asm(".globl FUN_0019e11c");
asm(".set FUN_0019e11c, _R520VMachineAssembler__vslot31_assembleWithPredicateRestore");
asm(".globl FUN_0019e318");
asm(".set FUN_0019e318, _R520VMachineAssembler__vslot25_assembleConditionalBlock");
asm(".globl FUN_0019e660");
asm(".set FUN_0019e660, _R520VMachineAssembler__vslot6_setLoopStack");
asm(".globl FUN_0019e6e0");
asm(".set FUN_0019e6e0, _R520VMachineAssembler__vslot24_assembleWithPredicateSet");
asm(".globl FUN_0019ef2c");
asm(".set FUN_0019ef2c, _FudoPs__vslot96_installHardwareTables");
asm(".globl FUN_0019ef50");
asm(".set FUN_0019ef50, _R520MachineAssembler__vslot5_beginProgram");
asm(".globl FUN_0019f094");
asm(".set FUN_0019f094, _R520MachineAssembler__setRsColorFields");
asm(".globl FUN_0019f0cc");
asm(".set FUN_0019f0cc, _R520MachineAssembler__setRsTexCoordFields");
asm(".globl FUN_0019f110");
asm(".set FUN_0019f110, _R520MachineAssembler__clearCurrentRecord");
asm(".globl FUN_0019f138");
asm(".set FUN_0019f138, _R520MachineAssembler__initNopAluRecord");
asm(".globl FUN_0019f1e0");
asm(".set FUN_0019f1e0, _R520MachineAssembler__vslot65_declareNodeRegisters");
asm(".globl FUN_0019f1fc");
asm(".set FUN_0019f1fc, _R520MachineAssembler__vslot59_selectForSrcpSwizzle");
asm(".globl FUN_0019f22c");
asm(".set FUN_0019f22c, _R520MachineAssembler__vslot60_selectForSrcpComponent");
asm(".globl FUN_0019f244");
asm(".set FUN_0019f244, _R520MachineAssembler__vslot61_selectForAlphaSource");
asm(".globl FUN_0019f298");
asm(".set FUN_0019f298, _R520MachineAssembler__vslot62_selectForSourceSwizzle");
asm(".globl FUN_0019f2c4");
asm(".set FUN_0019f2c4, _R520MachineAssembler__vslot64_selectForColorComponent");
asm(".globl FUN_0019f2ec");
asm(".set FUN_0019f2ec, _R520MachineAssembler__vslot63_selectForAlphaComponent");
asm(".globl FUN_0019f310");
asm(".set FUN_0019f310, _R520MachineAssembler__setAluSourceAddresses");
asm(".globl FUN_0019f43c");
asm(".set FUN_0019f43c, _R520MachineAssembler__setAlphaOpcode");
asm(".globl FUN_0019f778");
asm(".set FUN_0019f778, _R520MachineAssembler__vslot77_setRecordByteB");
asm(".globl FUN_0019f7a4");
asm(".set FUN_0019f7a4, _R520MachineAssembler__writeHeaderRecord");
asm(".globl FUN_0019f860");
asm(".set FUN_0019f860, _R520MachineAssembler__vslot9_getRecordWordsUsed");
asm(".globl FUN_0019f880");
asm(".set FUN_0019f880, _R520MachineAssembler__vslot38_appendBranchRecord");
asm(".globl FUN_0019f970");
asm(".set FUN_0019f970, _R520MachineAssembler__vslot80_setRecordByte9");
asm(".globl FUN_0019f98c");
asm(".set FUN_0019f98c, _R520MachineAssembler__vslot55_tryEncodeImmediateLiteral");
asm(".globl FUN_0019fa58");
asm(".set FUN_0019fa58, _R520MachineAssembler__vslot67_selectForConstantLanes");
asm(".globl FUN_0019fb84");
asm(".set FUN_0019fb84, _R520MachineAssembler__beginNextRecord");
asm(".globl FUN_0019fccc");
asm(".set FUN_0019fccc, _R520MachineAssembler__vslot4_finishProgram");
asm(".globl FUN_0019fdf0");
asm(".set FUN_0019fdf0, _R520MachineAssembler__vslot79_setTexCompareFlags");
asm(".globl FUN_0019ff2c");
asm(".set FUN_0019ff2c, _R520MachineAssembler__vslot31_assembleChildrenAndMark");
asm(".globl FUN_0019ffdc");
asm(".set FUN_0019ffdc, _R520MachineAssembler__vslot24_assembleWithTarget");
asm(".globl FUN_001a00b4");
asm(".set FUN_001a00b4, _R520MachineAssembler__setRgbOpcode");
asm(".globl FUN_001a06c4");
asm(".set FUN_001a06c4, _R520MachineAssembler__vslot86_resolveSourceRegister");
asm(".globl FUN_001a07c0");
asm(".set FUN_001a07c0, _R520MachineAssembler__vslot53_selectBitsForLiteralFloat");
asm(".globl FUN_001a08f0");
asm(".set FUN_001a08f0, _R520MachineAssembler__vslot54_selectBitsForAlphaLiteral");
asm(".globl FUN_001a09d0");
asm(".set FUN_001a09d0, _R520MachineAssembler__vslot66_selectBitsForLiteralLanes");
asm(".globl FUN_001a0b3c");
asm(".set FUN_001a0b3c, _R520MachineAssembler__vslot71_setAluSourceSelectsAndModifiers");
asm(".globl FUN_001a1160");
asm(".set FUN_001a1160, _R520MachineAssembler__vslot29_patchBranchTarget");
asm(".globl FUN_001a11f0");
asm(".set FUN_001a11f0, _R520MachineAssembler__vslot26_assembleThenAppendRecord");
asm(".globl FUN_001a1338");
asm(".set FUN_001a1338, _R520MachineAssembler__create");
