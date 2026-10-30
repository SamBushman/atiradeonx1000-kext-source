#include "decls.h"

/* R520VMachineAssembler__vslot27_assembleLoopHeader @ 0x19d858 (1008 bytes) */
int R520VMachineAssembler__vslot27_assembleLoopHeader(this, node, block, param_4, traversal, compiler, param_7)
  int *this;
  int node;
  undefined4 block;
  undefined4 param_4;
  undefined4 traversal;
  undefined4 compiler;
  undefined4 param_7;
{
  int *predicatedInst;
  int *predSetNEInst;
  uint selectByte;
  int zeroRegister;
  int zeroInst;
  int scratchRegister;
  int addSrcRecord;
  int branchOpcode;
  bool moreLanes;
  uint loopStackEntry;
  uint condSwizzle;
  int branchInst;
  int branchSrcRecord;
  int *condValueInst;
  undefined4 operandVReg;
  uint branchFlags;
  int a2;
  undefined4 a5;
  uint *loopStackSlot;
  int loopIndex;
  int *program;
  
  program = *(int **)(node + 0xac);
  a5 = compiler;
  branchInst = Block__getBranchInst(node,node,block,param_4,traversal,compiler,param_7);
  if (*program != 0) goto LAB_0019dc0c;
  loopStackSlot = (uint *)0x0;
  condSwizzle = *(uint *)(this[0x25] + 4);
  loopStackEntry = condSwizzle - 1;
  if (loopStackEntry < condSwizzle) {
    loopStackSlot = (uint *)(loopStackEntry * 4 + *(int *)(this[0x25] + 8));
  }
  loopStackEntry = *loopStackSlot;
  branchSrcRecord = IRInst__getOperandRecord(branchInst,1);
  condSwizzle = *(uint *)(branchSrcRecord + 0x10);
  branchOpcode = *(int *)(*(int *)(branchInst + 0x88) + 8);
  if (branchOpcode == 0x8b) {
    if (*(int *)(branchInst + 300) != 0) goto LAB_0019dab0;
    condValueInst = IRInst__create(0x12,compiler);
    addSrcRecord = IRInst__getOperandRecord(condValueInst,1);
    branchFlags = *(uint *)(branchInst + 0xb8);
    *(uint *)(addSrcRecord + 0x10) = condSwizzle;
    IROperand__setModifierBits(condValueInst + 0x29,1,branchFlags & 1);
    operandVReg = IRInst__getOperandSource(branchInst,1);
    IRInst__setOperandSource(condValueInst,1,operandVReg,0,compiler);
    operandVReg = IRInst__getOperandSource(branchInst,2);
    IRInst__setOperandSource(condValueInst,2,operandVReg,0,compiler);
    IROperand__setModifierBits(condValueInst + 0x2f,1,1);
    scratchRegister = R300VMachineAssembler__getOrAllocateScratchRegister(this,program);
    condValueInst[0x25] = scratchRegister;
    condValueInst[0x26] = 0;
    (**(code **)(*condValueInst + 0x84))(condValueInst,loopStackEntry);
    Block__appendInst(node,condValueInst);
  }
  else if (branchOpcode == 0x8c) {
    if (*(int *)(branchInst + 300) == 0) {
      condValueInst = (int *)IRInst__getOperandSource(branchInst,1);
    }
    else {
      condValueInst = IRInst__create(0x12,compiler);
      addSrcRecord = IRInst__getOperandRecord(condValueInst,1);
      branchFlags = *(uint *)(branchInst + 0xb8);
      *(uint *)(addSrcRecord + 0x10) = condSwizzle;
      IROperand__setModifierBits(condValueInst + 0x29,1,branchFlags & 1);
      operandVReg = IRInst__getOperandSource(branchInst,1);
      IRInst__setOperandSource(condValueInst,1,operandVReg,0,compiler);
      ((void (*)())IRInst__makeLiteralVec4Float)(condValueInst,program,2,1.0,1.0,1.0,1.0);
      IROperand__setModifierBits(condValueInst + 0x2f,1,1);
      scratchRegister = R300VMachineAssembler__getOrAllocateScratchRegister(this,program);
      condValueInst[0x25] = scratchRegister;
      condValueInst[0x26] = 0;
      (**(code **)(*condValueInst + 0x84))(condValueInst,loopStackEntry);
      Block__appendInst(node,condValueInst);
    }
  }
  else {
LAB_0019dab0:
    condValueInst = (int *)0x0;
  }
  zeroInst = R520VMachineAssembler__getOrCreateConstantZeroInst(this);
  zeroRegister = *(int *)(zeroInst + 0x94);
  predSetNEInst = IRInst__create(0x54,compiler);
  predSetNEInst[0x26] = 0;
  predSetNEInst[0x27] = 0x1010101;
  predSetNEInst[0x25] = 0;
  IRInst__setOperandSource(predSetNEInst,1,condValueInst,0,compiler);
  loopIndex = 0;
  do {
    (**(code **)(*predSetNEInst + 0x88))(predSetNEInst,1,loopIndex,condSwizzle & 0xff);
    moreLanes = loopIndex != 3;
    loopIndex = loopIndex + 1;
  } while (moreLanes);
  loopIndex = 0;
  (**(code **)(*predSetNEInst + 0x84))(predSetNEInst,loopStackEntry);
  Block__appendInst(node,predSetNEInst);
  predicatedInst = IRInst__create(0x3e,compiler);
  IRInst__setOperandSource(predicatedInst,1,condValueInst,0,compiler);
  do {
    a2 = loopIndex;
    selectByte = condSwizzle & 0xff;
    /* dropped 2 args (found auditing #70 via ExtendIndirectCalls.java / ground-truth
     * disassembly): stock passes loopIndex and selectByte here too, matching the identical-shape
     * call a few lines above (both loops dispatch the same vtable+0x88 method the same way -
     * r28, set once, holds this loop's masked byte for both). */
    (**(code **)(*predicatedInst + 0x88))(predicatedInst,1,loopIndex,selectByte);
    moreLanes = loopIndex != 3;
    loopIndex = loopIndex + 1;
  } while (moreLanes);
  predicatedInst[0x25] = zeroRegister;
  loopStackEntry = loopStackEntry ^ 3;
  predicatedInst[0x27] = 0x1010100;
  predicatedInst[0x26] = 0;
  (**(code **)(*predicatedInst + 0x84))
            (predicatedInst,(loopStackEntry - ((loopStackEntry - 1) + (uint)(loopStackEntry == 0))) + 2,a2,selectByte,compiler,a5,loopStackEntry - 1)
  ;
  Block__appendInst(node,predicatedInst);
  DListNode__unlinkAndDelete(branchInst);
  *(undefined4 *)(node + 0x130) = 0;
LAB_0019dc0c:
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  return Block__accept(*(undefined4 *)(node + 0x13c),traversal);
}

/* R520VMachineAssembler__vslot30_assembleBlockThenSlot40 @ 0x19dc48 (104 bytes) */
int R520VMachineAssembler__vslot30_assembleBlockThenSlot40(this, node, block)
  int *this;
  int node;
  undefined4 block;
{
  undefined4 nodeHandle;
  code *UNRECOVERED_JUMPTABLE;
  
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*this + 0xa0);
  nodeHandle = FUN_000e7d5c(*(undefined4 *)(node + 300));
                    
                    
  (*UNRECOVERED_JUMPTABLE)(this,nodeHandle);
  return;
}

/* R520VMachineAssembler__deleting_dtor @ 0x19dcb0 (156 bytes) */
int R520VMachineAssembler__deleting_dtor(this)
  undefined4 *this;
{
  int arenaHeader;
  int predKindStack;
  undefined4 *blockStart;
  int savedPredStack;
  
  savedPredStack = this[0x26];
  *this = &PTR_FUN_001eb8d8;
  if (savedPredStack != 0) {
    Arena__free(*(undefined4 *)(savedPredStack + 0xc),*(undefined4 *)(savedPredStack + 8));
    Arena__free(*(undefined4 *)(savedPredStack + -4),savedPredStack + -4);
  }
  predKindStack = this[0x25];
  if (predKindStack != 0) {
    Arena__free(*(undefined4 *)(predKindStack + 0xc),*(undefined4 *)(predKindStack + 8));
    Arena__free(*(undefined4 *)(predKindStack + -4),predKindStack + -4);
  }
  MachineAssembler__dtor_19b91c(this);
  if (this == (undefined4 *)0x0) {
    return;
  }
  arenaHeader = this[-1];
  if ((*(int *)(arenaHeader + 0x28) != 0) &&
     (blockStart = *(undefined4 **)(arenaHeader + 0x14), blockStart == this + -1)) {
    _memset(blockStart,0,*(int *)(arenaHeader + 8) - (int)blockStart);
    *(undefined4 *)(arenaHeader + 8) = *(undefined4 *)(arenaHeader + 0x14);
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
  undefined4 elementStorage;
  
  R300VMachineAssembler__init(this,program,allocatorArg,compiler);
  *(undefined4 *)(this + 0x8c) = 0xffffffff;
  *(undefined4 *)(this + 0x90) = 0;
  arenaAt378 = *(undefined4 *)(compiler + COMP_arenaB);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  elementStorage = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = elementStorage;
  *(undefined4 **)(this + 0x98) = vectorAlloc + 1;
  arenaAt378 = *(undefined4 *)(compiler + COMP_arenaB);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaAt378;
  elementStorage = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = elementStorage;
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
  int bufferA;
  int bufferB;
  
  bufferB = this[0x26];
  *this = &PTR_FUN_001eb8d8;
  if (bufferB != 0) {
    Arena__free(*(undefined4 *)(bufferB + 0xc),*(undefined4 *)(bufferB + 8));
    Arena__free(*(undefined4 *)(bufferB + -4),bufferB + -4);
  }
  bufferA = this[0x25];
  if (bufferA != 0) {
    Arena__free(*(undefined4 *)(bufferA + 0xc),*(undefined4 *)(bufferA + 8));
    Arena__free(*(undefined4 *)(bufferA + -4),bufferA + -4);
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
  int bufferA;
  int bufferB;
  
  bufferB = this[0x26];
  *this = &PTR_FUN_001eb8d8;
  if (bufferB != 0) {
    Arena__free(*(undefined4 *)(bufferB + 0xc),*(undefined4 *)(bufferB + 8));
    Arena__free(*(undefined4 *)(bufferB + -4),bufferB + -4);
  }
  bufferA = this[0x25];
  if (bufferA != 0) {
    Arena__free(*(undefined4 *)(bufferA + 0xc),*(undefined4 *)(bufferA + 8));
    Arena__free(*(undefined4 *)(bufferA + -4),bufferA + -4);
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
  undefined4 sourceSelect;
  int popInst;
  int *topKindSlot;
  int operandRecord;
  undefined4 destSelect;
  uint topKindIndex;
  uint predKindCount;
  int zeroInst;
  int *program;
  int topKind;
  
  program = *(int **)(node + 0xac);
  Vector__removeAt(this[0x25],*(int *)(this[0x25] + 4) + -1);
  if (*program == 0) {
    topKindSlot = (int *)0x0;
    predKindCount = *(uint *)(this[0x25] + 4);
    topKindIndex = predKindCount - 1;
    if (topKindIndex < predKindCount) {
      topKindSlot = (int *)(topKindIndex * 4 + *(int *)(this[0x25] + 8));
    }
    topKind = *topKindSlot;
    FUN_000e2bf4(block,topKind);
    if (topKind != 0) {
      popInst = IRInst__create(0x58,compiler);
      zeroInst = R520VMachineAssembler__getOrCreateConstantZeroInst(this);
      destSelect = DAT_001b2d50;
      *(undefined4 *)(popInst + 0x94) = *(undefined4 *)(zeroInst + 0x94);
      *(undefined4 *)(popInst + 0x98) = 0;
      *(undefined4 *)(popInst + 0x9c) = destSelect;
      IRInst__setOperandSource(popInst,1,zeroInst,0,compiler);
      sourceSelect = DAT_001b2d4c;
      operandRecord = IRInst__getOperandRecord(popInst,1);
      *(undefined4 *)(operandRecord + 0x10) = sourceSelect;
      Block__prependInst(node,popInst);
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
  int destSelect;
  int zeroInst;
  uint laneSelect;
  uint savedCount;
  undefined4 *savedTopSlot;
  int *newInst;
  uint topKindIndex;
  uint predKindCount;
  int savedPredStack;
  undefined4 *topKindSlot;
  undefined4 savedMovInst;
  int zeroRegister;
  int *program;
  
  program = *(int **)(node + 0xac);
  if (((0 < *(int *)(*(int *)(node + 300) + 0x138)) ||
      (*(int *)(*(int *)(node + 300) + 0x13c) != 0)) &&
     (Vector__removeAt(this[0x25],*(int *)(this[0x25] + 4) + -1), *program == 0)) {
    topKindSlot = (undefined4 *)0x0;
    predKindCount = *(uint *)(this[0x25] + 4);
    topKindIndex = predKindCount - 1;
    if (topKindIndex < predKindCount) {
      topKindSlot = (undefined4 *)(topKindIndex * 4 + *(int *)(this[0x25] + 8));
    }
    FUN_000e2bf4(block,*topKindSlot);
    savedPredStack = this[0x26];
    savedCount = *(uint *)(savedPredStack + 4);
    if (0 < (int)savedCount) {
      laneSelect = savedCount - 1;
      savedTopSlot = (undefined4 *)0x0;
      if (laneSelect < savedCount) {
        savedTopSlot = (undefined4 *)(laneSelect * 4 + *(int *)(savedPredStack + 8));
      }
      savedMovInst = *savedTopSlot;
      Vector__removeAt(savedPredStack,savedCount - 1);
      zeroInst = R520VMachineAssembler__getOrCreateConstantZeroInst(this);
      zeroRegister = *(int *)(zeroInst + 0x94);
      newInst = (int *)IRInst__create(0x5a,compiler);
      destSelect = DAT_001b2d50;
      newInst[0x25] = zeroRegister;
      newInst[0x26] = 0;
      newInst[0x27] = destSelect;
      IRInst__setOperandSource(newInst,1,savedMovInst,0,compiler);
      if ((3 < (int)savedCount) && (laneSelect = 0, (int)savedCount < 8)) {
        laneSelect = savedCount - 4;
      }
      (**(code **)(*newInst + 0x88))(newInst,1,0,laneSelect);
      (**(code **)(*newInst + 0x88))(newInst,1,1,laneSelect);
      (**(code **)(*newInst + 0x88))(newInst,1,2,laneSelect);
      (**(code **)(*newInst + 0x88))(newInst,1,3,laneSelect);
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
  undefined4 predSetOpcode;
  uint pushIndex;
  int *predSetInst;
  int *topKindSlot;
  undefined4 sourceDef;
  bool moreLanes;
  uint uVar2;
  uint predKindCount;
  int loopIndex;
  int *branchInst;
  undefined4 uVar5;
  int operandRecord;
  undefined4 *pushedSlot;
  int *program;
  code *setSourceSelect;
  uint *predKindStack;
  bool unpredicated;
  
  program = *(int **)(node + 0xac);
  branchInst = (int *)Block__getBranchInst(node,node,block,compiler,extra2,extra3,extra4);
  if (*program != 0) goto LAB_0019e5d0;
  (**(code **)(*branchInst + 0x14))(branchInst);
  topKindSlot = (int *)0x0;
  predKindCount = *(uint *)(this[0x25] + 4);
  uVar2 = predKindCount - 1;
  if (uVar2 < predKindCount) {
    topKindSlot = (int *)(uVar2 * 4 + *(int *)(this[0x25] + 8));
  }
  loopIndex = branchInst[0x4b];
  unpredicated = *topKindSlot == 0;
  if (loopIndex == 1) {
    if (unpredicated) {
      predSetOpcode = 0x54;
    }
    else {
      predSetOpcode = 0x2d;
    }
  }
  else if (loopIndex < 2) {
    if (loopIndex == 0) {
      if (unpredicated) {
        predSetOpcode = 0x53;
      }
      else {
        predSetOpcode = 0x2c;
      }
    }
    else {
LAB_0019e3d4:
      predSetOpcode = 0;
    }
  }
  else if (loopIndex == 2) {
    if (unpredicated) {
      predSetOpcode = 0x55;
    }
    else {
      predSetOpcode = 0x2e;
    }
  }
  else {
    if (loopIndex != 3) goto LAB_0019e3d4;
    if (unpredicated) {
      predSetOpcode = 0x56;
    }
    else {
      predSetOpcode = 0x2f;
    }
  }
  predSetInst = IRInst__create(predSetOpcode,compiler);
  if (unpredicated) {
    if (*(int *)(node + 0x144) == 0) {
      loopIndex = R520VMachineAssembler__getOrCreateConstantZeroInst(this);
      predSetInst[0x25] = *(int *)(loopIndex + 0x94);
      predSetInst[0x26] = 0;
      predSetInst[0x27] = 0x1010100;
    }
    else {
      predSetInst[0x26] = 0;
      predSetInst[0x25] = 0;
      predSetInst[0x27] = 0x1010101;
    }
    sourceDef = IRInst__getOperandSource(branchInst,1);
    IRInst__setOperandSource(predSetInst,1,sourceDef,0,compiler);
  }
  else {
    loopIndex = R520VMachineAssembler__getOrCreateConstantZeroInst(this);
    predSetInst[0x25] = *(int *)(loopIndex + 0x94);
    predSetInst[0x26] = 0;
    predSetInst[0x27] = 0x1010100;
    IRInst__setOperandSource(predSetInst,1,loopIndex,0,compiler);
    loopIndex = IRInst__getOperandRecord(predSetInst,1);
    *(undefined4 *)(loopIndex + 0x10) = 0x3030303;
    sourceDef = IRInst__getOperandSource(branchInst,1);
    IRInst__setOperandSource(predSetInst,2,sourceDef,0,compiler);
  }
  loopIndex = 0;
  do {
    setSourceSelect = *(code **)(*predSetInst + 0x88);
    if (unpredicated) {
      uVar5 = 1;
    }
    else {
      uVar5 = 2;
    }
    operandRecord = IRInst__getOperandRecord(branchInst,1);
    (*setSourceSelect)(predSetInst,uVar5,loopIndex,*(undefined1 *)(operandRecord + 0x13));
    moreLanes = loopIndex != 3;
    loopIndex = loopIndex + 1;
  } while (moreLanes);
  if ((branchInst[0x2e] & 1U) != 0) {
    if (unpredicated) {
      loopIndex = 1;
    }
    else {
      loopIndex = 2;
    }
    IROperand__setModifierBits(predSetInst + loopIndex * 6 + 0x23,1,1);
  }
  Block__appendInst(node,predSetInst);
  DListNode__unlinkAndDelete(branchInst);
  *(undefined4 *)(node + 0x130) = 0;
LAB_0019e5d0:
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  predKindStack = (uint *)this[0x25];
  pushIndex = predKindStack[1];
  if (pushIndex < *predKindStack) {
    _memset(pushIndex * 4 + predKindStack[2],0,4);
    pushedSlot = (undefined4 *)(pushIndex * 4 + predKindStack[2]);
    predKindStack[1] = pushIndex + 1;
  }
  else {
    pushedSlot = (undefined4 *)Vector__elementRefGrow(predKindStack,pushIndex);
  }
  *pushedSlot = 3;
  return;
}

/* R520VMachineAssembler__vslot6_setLoopStack @ 0x19e660 (128 bytes) */
int R520VMachineAssembler__vslot6_setLoopStack(this, enable)
  int this;
  undefined4 enable;
{
  undefined4 *pushedSlot;
  uint pushIndex;
  uint *predKindStack;
  
  R300VMachineAssembler__vslot6_setLoopStack(this,enable);
  predKindStack = *(uint **)(this + 0x94);
  pushIndex = predKindStack[1];
  if (pushIndex < *predKindStack) {
    _memset(pushIndex * 4 + predKindStack[2],0,4);
    pushedSlot = (undefined4 *)(pushIndex * 4 + predKindStack[2]);
    predKindStack[1] = pushIndex + 1;
  }
  else {
    pushedSlot = (undefined4 *)Vector__elementRefGrow(predKindStack,pushIndex);
  }
  *pushedSlot = 0;
  return;
}

/* R520VMachineAssembler__vslot24_assembleWithPredicateSet @ 0x19e6e0 (688 bytes) */
int R520VMachineAssembler__vslot24_assembleWithPredicateSet(this, node, block, compiler)
  int *this;
  int node;
  undefined4 block;
  undefined4 compiler;
{
  uint *savedPredStack;
  uint pushIndex;
  uint savedPushIndex;
  undefined4 nodeHandle;
  undefined4 sourceSelect;
  int predSetInst;
  int *savedSlot;
  int operandRecord;
  undefined4 destSelect;
  uint topKindIndex;
  int zeroInst;
  int saveMovInst;
  undefined4 *pushedSlot;
  int *topKindSlot;
  undefined4 destRegister;
  int *program;
  code *UNRECOVERED_JUMPTABLE;
  uint *predKindStack;
  int predSlot;
  double fparam_1;
  
  program = *(int **)(node + 0xac);
  if ((0 < *(int *)(node + 0x138)) || (*(int *)(node + 0x13c) != 0)) {
    zeroInst = R520VMachineAssembler__getOrCreateConstantZeroInst(this);
    predKindStack = (uint *)this[0x25];
    destRegister = *(undefined4 *)(zeroInst + 0x94);
    topKindSlot = (int *)0x0;
    topKindIndex = predKindStack[1] - 1;
    if (topKindIndex < predKindStack[1]) {
      topKindSlot = (int *)(topKindIndex * 4 + predKindStack[2]);
    }
    if (*topKindSlot == 0) {
      if (*program == 0) {
        predSetInst = IRInst__create(0x53,compiler);
        destSelect = DAT_001b2d50;
        fparam_1 = (double)FLOAT_001aa0d4;
        *(undefined4 *)(predSetInst + 0x94) = destRegister;
        *(undefined4 *)(predSetInst + 0x9c) = destSelect;
        *(undefined4 *)(predSetInst + 0x98) = 0;
        ((void (*)())IRInst__makeLiteralVec4Float)(predSetInst,program,1,fparam_1,fparam_1,fparam_1,fparam_1);
        *(uint *)(predSetInst + 0x14) = *(uint *)(predSetInst + 0x14) & 0xfffffffb;
        Block__appendInst(node,predSetInst);
        predKindStack = (uint *)this[0x25];
      }
    }
    else if (*program == 0) {
      predSlot = *(int *)(this[0x26] + 4);
      if (2 < predSlot) {
        if (predSlot < 7) {
          destRegister = FUN_00130690(program,0);
          predSlot = predSlot + -3;
        }
        else {
          destRegister = 0;
          predSlot = 0;
        }
      }
      saveMovInst = IRMov__new_1084b8(0x66,compiler);
      *(undefined4 *)(saveMovInst + 0x9c) = DAT_001b2d54;
      *(undefined1 *)(predSlot + saveMovInst + 0x9c) = 0;
      *(undefined4 *)(saveMovInst + 0x98) = 0;
      *(undefined4 *)(saveMovInst + 0x94) = destRegister;
      IRInst__setOperandSource(saveMovInst,1,zeroInst,0,compiler);
      sourceSelect = DAT_001b2d4c;
      operandRecord = IRInst__getOperandRecord(saveMovInst,1);
      *(undefined4 *)(operandRecord + 0x10) = sourceSelect;
      *(uint *)(saveMovInst + 0x14) = *(uint *)(saveMovInst + 0x14) & 0xfffffffb;
      Block__appendInst(node,saveMovInst);
      savedPredStack = (uint *)this[0x26];
      savedPushIndex = savedPredStack[1];
      if (savedPushIndex < *savedPredStack) {
        _memset(savedPushIndex * 4 + savedPredStack[2],0,4);
        savedSlot = (int *)(savedPushIndex * 4 + savedPredStack[2]);
        savedPredStack[1] = savedPushIndex + 1;
      }
      else {
        savedSlot = (int *)Vector__elementRefGrow(savedPredStack,savedPushIndex);
      }
      *savedSlot = saveMovInst;
      predKindStack = (uint *)this[0x25];
    }
    pushIndex = predKindStack[1];
    if (pushIndex < *predKindStack) {
      _memset(pushIndex * 4 + predKindStack[2],0,4);
      pushedSlot = (undefined4 *)(pushIndex * 4 + predKindStack[2]);
      predKindStack[1] = pushIndex + 1;
    }
    else {
      pushedSlot = (undefined4 *)Vector__elementRefGrow(predKindStack,pushIndex);
    }
    *pushedSlot = 3;
  }
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*this + 0x9c);
  nodeHandle = FUN_000e7d5c(node);
                    
                    
  (*UNRECOVERED_JUMPTABLE)(this,nodeHandle,*(undefined4 *)(node + 0x134));
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
int ilSkipRelativeAddressWords(addressMode, nestedCount, bytePtr)
  int addressMode;
  int nestedCount;
  int bytePtr;
{
  int nestedWordCount;
  int loopIndex;
  
  if (addressMode == 1) {
    bytePtr = bytePtr + 4;
  }
  else {
    loopIndex = 0;
    if (-1 < nestedCount) {
      do {
        loopIndex = loopIndex + 1;
        nestedWordCount = ((int (*)())ilSourceOperandWordCount)(bytePtr);
        bytePtr = bytePtr + nestedWordCount * 4;
      } while (loopIndex <= nestedCount);
    }
  }
  return bytePtr;
}

/* ilSourceOperandWordCount @ 0x19ecf4 (192 bytes) */
int ilSourceOperandWordCount(operandWords)
  uint *operandWords;
{
  uint header;
  int nestedWordCount;
  uint *loopPtr;
  uint loopIndex2;
  
  loopPtr = operandWords + 1;
  header = *operandWords;
  if ((header & 0x400000) != 0) {
    loopPtr = operandWords + 2;
  }
  if ((header & 0x1800000) == 0) {
    loopIndex2 = 0;
    if ((header & 0x2000000) == 0) {
      header = *operandWords;
    }
    else {
      do {
        loopIndex2 = loopIndex2 + 1;
        nestedWordCount = ((int (*)())ilSourceOperandWordCount)(loopPtr);
        header = *operandWords;
        loopPtr = loopPtr + nestedWordCount;
      } while (loopIndex2 < (header >> 0x19 & 1));
    }
    if ((header & 0x1800000) == 0) goto LAB_0019ed78;
  }
  loopPtr = (uint *)((int (*)())ilSkipRelativeAddressWords)(header >> 0x17 & 3,header >> 0x19 & 1,loopPtr);
  header = *operandWords;
LAB_0019ed78:
  if ((header & 0x4000000) != 0) {
    loopPtr = loopPtr + 1;
  }
  return (int)loopPtr - (int)operandWords >> 2;
}

/* ilInstructionHeaderWordCount @ 0x19edb4 (84 bytes) */
int ilInstructionHeaderWordCount(instructionWords)
  uint *instructionWords;
{
  uint *wordPtr;
  
  if ((short)*instructionWords == 0x7d) {
    return 1;
  }
  wordPtr = instructionWords + 1;
  if ((int)*instructionWords < 0) {
    wordPtr = instructionWords + 2;
  }
  if ((short)*instructionWords == 0x17) {
    return (int)wordPtr - (int)instructionWords >> 2;
  }
  if ((*instructionWords & 0x40000000) != 0) {
    wordPtr = wordPtr + 1;
  }
  return (int)wordPtr - (int)instructionWords >> 2;
}

/* ilDestinationOperandWordCount @ 0x19ee08 (108 bytes) */
int ilDestinationOperandWordCount(operandWords)
  uint *operandWords;
{
  uint header;
  uint *wordPtr;
  
  wordPtr = operandWords + 1;
  header = *operandWords;
  if ((header & 0x400000) != 0) {
    wordPtr = operandWords + 2;
  }
  if ((header & 0x1800000) != 0) {
    wordPtr = (uint *)((int (*)())ilSkipRelativeAddressWords)(header >> 0x17 & 3,header >> 0x19 & 1,wordPtr);
    header = *operandWords;
  }
  if ((header & 0x4000000) != 0) {
    wordPtr = wordPtr + 1;
  }
  return (int)wordPtr - (int)operandWords >> 2;
}

/* Compiler__selectLimitsForShaderKind @ 0x19ee74 (184 bytes) */
int Compiler__selectLimitsForShaderKind(programDesc, compiler)
  int programDesc;
  int compiler;
{
  char shaderKind;
  int *limitsSet;
  
  shaderKind = *(char *)(programDesc + 1);
  if (shaderKind == '\x01') {
    *(uint *)(*(int *)(compiler + 0x6c4) + 0x30) =
         *(uint *)(*(int *)(compiler + 0x6c4) + 0x30) | 0x2000;
    limitsSet = *(int **)(compiler + 0x310);
    *(int *)(compiler + 0x30c) = limitsSet[2];
                    
                    
    (**(code **)(*limitsSet + 8))(limitsSet);
    return;
  }
  if (shaderKind != '\x02') {
    if (shaderKind != '\0') {
      return;
    }
    *(uint *)(*(int *)(compiler + 0x6c4) + 0x30) = *(uint *)(*(int *)(compiler + 0x6c4) + 0x30) | 1;
    limitsSet = *(int **)(compiler + 0x310);
    *(int *)(compiler + 0x30c) = limitsSet[1];
                    
                    
    (**(code **)(*limitsSet + 0xc))(limitsSet);
    return;
  }
  *(uint *)(*(int *)(compiler + 0x6c4) + 0x30) = *(uint *)(*(int *)(compiler + 0x6c4) + 0x30) | 0x4000
  ;
  limitsSet = *(int **)(compiler + 0x310);
  *(int *)(compiler + 0x30c) = limitsSet[3];
                    
                    
  (**(code **)(*limitsSet + 0x10))(limitsSet);
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
int R520MachineAssembler__vslot5_beginProgram(this, programArg, allocArg, compiler)
  int this;
  undefined4 programArg;
  undefined4 allocArg;
  int compiler;
{
  undefined *opcodeTable;
  undefined4 recordBuffer;
  int registerLimit;
  
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(compiler + 0x30c);
  recordBuffer = FUN_000e14e4(compiler,0x963c,allocArg);
  *(undefined4 *)(this + 0xac) = recordBuffer;
  _memset(recordBuffer,0,0x963c);
  registerLimit = *(int *)(*(int *)(compiler + 0x30c) + 0x40);
  *(undefined4 *)(this + 0xa8) = *(undefined4 *)(this + 0xac);
  *(undefined4 *)(this + 0x10) = programArg;
  *(int *)(this + 0xc) = compiler;
  *(undefined4 *)(this + 0x60) = 1;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x80) = 1;
  *(undefined4 *)(this + 0x84) = 1;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xb4) = 0xffffffff;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0xb0) = 0xffffffff;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0x14) = allocArg;
  *(undefined4 *)(this + 0x98) = 1;
  *(undefined4 *)(this + 0x94) = 1;
  **(undefined4 **)(this + 0xa8) = 0;
  opcodeTable = PTR_DAT_001e913c;
  *(int *)(*(int *)(this + 0xa8) + 4) = registerLimit + 1;
  *(undefined4 *)(opcodeTable + 0x2654) = 7;
  *(undefined4 *)(opcodeTable + 0x10e4) = 0xd;
  *(undefined4 *)(opcodeTable + 0x22d4) = 0xe;
  *(undefined4 *)(opcodeTable + 0x229c) = 0xb;
  *(undefined4 *)(opcodeTable + 0x2344) = 0xf;
  *(undefined4 *)(opcodeTable + 0x230c) = 0xc;
  *(undefined4 *)(opcodeTable + 0x261c) = 5;
  *(undefined4 *)(opcodeTable + 0x1a4c) = 6;
  *(undefined4 *)(opcodeTable + 0x10ac) = 0xc;
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
  return ConstRecord__emitStores(node,this,compiler);
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
  int recordIndex;
  int recordTable;
  undefined1 savedByte3c;
  undefined1 savedByte36;
  int recordPtr;
  undefined1 alphaOpcode;
  int recordPtr2;
  
  alphaOpcode = (undefined1)hardwareOpcode;
  if (hardwareOpcode != -1) goto LAB_0019f708;
  if (irOpcode == 0x34) {
LAB_0019f51c:
    alphaOpcode = 0;
    recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(undefined1 *)(recordPtr + 0x3b) = *(undefined1 *)(recordPtr + 0x3a);
    recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(undefined1 *)(recordPtr + 0x3e) = *(undefined1 *)(recordPtr + 0x3d);
    recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(undefined1 *)(recordPtr + 0x38) = *(undefined1 *)(recordPtr + 0x37);
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
          recordPtr2 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          alphaOpcode = *(undefined1 *)(recordPtr2 + 0x39);
          *(undefined1 *)(recordPtr2 + 0x39) = *(undefined1 *)(recordPtr2 + 0x3a);
          savedByte3c = *(undefined1 *)(recordPtr2 + 0x3c);
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          savedByte36 = *(undefined1 *)(recordPtr2 + 0x36);
          *(undefined1 *)(recordPtr + 0x3c) = *(undefined1 *)(recordPtr + 0x3d);
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(undefined1 *)(recordPtr + 0x36) = *(undefined1 *)(recordPtr + 0x37);
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(undefined1 *)(recordPtr + 0x3a) = *(undefined1 *)(recordPtr + 0x3b);
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(undefined1 *)(recordPtr + 0x3d) = *(undefined1 *)(recordPtr + 0x3e);
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(undefined1 *)(recordPtr + 0x37) = *(undefined1 *)(recordPtr + 0x38);
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x3b) = alphaOpcode
          ;
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x3e) = savedByte3c
          ;
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x38) = savedByte36
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
  recordIndex = *(int *)(this + 0x60);
  recordTable = *(int *)(this + 0xa8);
  alphaOpcode = psnOutputScaleCode(*(undefined4 *)(irInst + 0x124));
  *(undefined1 *)(recordIndex * 0x48 + recordTable + 0x41) = alphaOpcode;
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
int R520MachineAssembler__vslot4_finishProgram(this)
  int *this;
{
  int callResult;
  int lastIndex;
  
  lastIndex = 0;
  *(int *)(this[0x2b] + 0x93b8) = this[0x24];
  *(int *)(this[0x2b] + 0x9364) = *(int *)(*(int *)(this[3] + 0x6c4) + 0x7c) + 1;
  *(undefined4 *)(this[0x2b] + 0x9368) = *(undefined4 *)(*(int *)(this[3] + 0x6c4) + 0x84);
  callResult = FUN_0013061c(*(undefined4 *)(this[3] + 0x6c4),0);
  if (callResult != 0) {
    lastIndex = callResult + -1;
  }
  if ((*(int *)(this[0x18] * 0x48 + this[0x2a] + -0x48) != 3) ||
     (this[0x2d] == (this[0x18] - this[0x1d]) + -1)) {
    (**(code **)(*this + 0xbc))(this);
    (**(code **)(*this + 0xc0))(this);
    (**(code **)(*this + 0x15c))(this);
  }
                    
                    
  (**(code **)(*this + 0x144))(this,this[0x1e],lastIndex);
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
  int recordIndex;
  int recordTable;
  undefined1 savedByte2d;
  uint wordTmp;
  undefined1 rgbOpcode;
  int recordPtr;
  uint savedWord24;
  int recordPtr2;
  
  rgbOpcode = (undefined1)hardwareOpcode;
  if (hardwareOpcode != -1) goto LAB_001a0654;
  if (irOpcode == 0x34) {
LAB_001a0260:
    rgbOpcode = 0;
    recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(undefined1 *)(recordPtr + 0x2c) = *(undefined1 *)(recordPtr + 0x2b);
    recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(undefined1 *)(recordPtr + 0x2f) = *(undefined1 *)(recordPtr + 0x2e);
    recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(uint *)(recordPtr + 0x28) =
         (*(uint *)(recordPtr + 0x24) & 0xe000) << 0x10 | *(uint *)(recordPtr + 0x28) & 0x1fffffff;
    recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(uint *)(recordPtr + 0x28) =
         (*(uint *)(recordPtr + 0x24) & 0x1c00) << 0x10 | *(uint *)(recordPtr + 0x28) & 0xe3ffffff;
    recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(uint *)(recordPtr + 0x28) =
         (*(uint *)(recordPtr + 0x24) & 0x380) << 0x10 | *(uint *)(recordPtr + 0x28) & 0xfc7fffff;
    recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(uint *)(recordPtr + 0x24) = *(uint *)(recordPtr + 0x24) & 0xffff1fff | 0xc000;
    recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(uint *)(recordPtr + 0x24) = *(uint *)(recordPtr + 0x24) & 0xffffe3ff | 0x1800;
    recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(uint *)(recordPtr + 0x24) = *(uint *)(recordPtr + 0x24) & 0xfffffc7f | 0x300;
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x2e) = 0;
  }
  else {
    if (irOpcode < 0x35) {
      if (irOpcode == 0x13) {
LAB_001a0200:
        rgbOpcode = 0;
        recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
        *(uint *)(recordPtr + 0x28) = *(uint *)(recordPtr + 0x28) & 0x1fffffff | 0x80000000;
        recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
        *(uint *)(recordPtr + 0x28) = *(uint *)(recordPtr + 0x28) & 0xe3ffffff | 0x10000000;
        recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
        *(uint *)(recordPtr + 0x28) = *(uint *)(recordPtr + 0x28) & 0xfc7fffff | 0x2000000;
        goto LAB_001a0654;
      }
      if (irOpcode < 0x14) {
        if (irOpcode == 0x12) goto LAB_001a0260;
      }
      else {
        if (irOpcode == 0x25) {
LAB_001a044c:
          recordPtr2 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          rgbOpcode = *(undefined1 *)(recordPtr2 + 0x2a);
          *(undefined1 *)(recordPtr2 + 0x2a) = *(undefined1 *)(recordPtr2 + 0x2b);
          savedWord24 = *(uint *)(recordPtr2 + 0x24);
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          savedByte2d = *(undefined1 *)(recordPtr2 + 0x2d);
          *(undefined1 *)(recordPtr + 0x2d) = *(undefined1 *)(recordPtr + 0x2e);
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          wordTmp = *(uint *)(recordPtr + 0x24);
          *(uint *)(recordPtr + 0x24) = (wordTmp & 0x1c00) << 0x10 | wordTmp & 0xe3ffffff;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          wordTmp = *(uint *)(recordPtr + 0x24);
          *(uint *)(recordPtr + 0x24) = (wordTmp & 0x380) << 0x10 | wordTmp & 0xfc7fffff;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          wordTmp = *(uint *)(recordPtr + 0x24);
          *(uint *)(recordPtr + 0x24) = (wordTmp & 0xe000) << 0x10 | wordTmp & 0x1fffffff;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(undefined1 *)(recordPtr + 0x2b) = *(undefined1 *)(recordPtr + 0x2c);
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(undefined1 *)(recordPtr + 0x2e) = *(undefined1 *)(recordPtr + 0x2f);
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x24) =
               *(uint *)(recordPtr + 0x28) >> 0x10 & 0xe000 | *(uint *)(recordPtr + 0x24) & 0xffff1fff;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x24) =
               *(uint *)(recordPtr + 0x28) >> 0x10 & 0x1c00 | *(uint *)(recordPtr + 0x24) & 0xffffe3ff;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x24) =
               *(uint *)(recordPtr + 0x28) >> 0x10 & 0x380 | *(uint *)(recordPtr + 0x24) & 0xfffffc7f;
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x2c) = rgbOpcode
          ;
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x2f) = savedByte2d
          ;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x28) = savedWord24 & 0xe0000000 | *(uint *)(recordPtr + 0x28) & 0x1fffffff;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x28) = savedWord24 & 0x1c000000 | *(uint *)(recordPtr + 0x28) & 0xe3ffffff;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x28) = savedWord24 & 0x3800000 | *(uint *)(recordPtr + 0x28) & 0xfc7fffff;
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
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x24) = *(uint *)(recordPtr + 0x24) & 0xffff1fff | 0xc000;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x24) = *(uint *)(recordPtr + 0x24) & 0xffffe3ff | 0x1800;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x24) = *(uint *)(recordPtr + 0x24) & 0xfffffc7f | 0x300;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x28) = *(uint *)(recordPtr + 0x28) & 0x1fffffff | 0x80000000;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x28) = *(uint *)(recordPtr + 0x28) & 0xe3ffffff | 0x10000000;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x28) = *(uint *)(recordPtr + 0x28) & 0xfc7fffff | 0x2000000;
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
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x24) = *(uint *)(recordPtr + 0x24) & 0xfc7fffff | 0x3000000;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x24) = *(uint *)(recordPtr + 0x24) & 0xffff1fff | 0xc000;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x24) = *(uint *)(recordPtr + 0x24) & 0xffffe3ff | 0x1800;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x28) = *(uint *)(recordPtr + 0x28) & 0x1fffffff | 0x80000000;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x28) = *(uint *)(recordPtr + 0x28) & 0xfc7fffff | 0x2000000;
          recordPtr = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
          *(uint *)(recordPtr + 0x28) = *(uint *)(recordPtr + 0x28) & 0xe3ffffff | 0x10000000;
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
  recordIndex = *(int *)(this + 0x60);
  recordTable = *(int *)(this + 0xa8);
  rgbOpcode = psnOutputScaleCode(*(undefined4 *)(irInst + 0x124));
  *(undefined1 *)(recordIndex * 0x48 + recordTable + 0x32) = rgbOpcode;
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
  byte *loopPtr2;
  int loopIndex;
  uint uVar9;
  
  if (1 < *(int *)(inst + 0x84)) {
    loopIndex = 2;
    packedWord = (uint *)(packedBase + sourceIndex * 4);
    (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = laneSelectors;
    do {
      a0 = (int *)IRInst__getOperandSource(inst,loopIndex);
      if ((a0 != (int *)0x0) && (operandRecord = (**(code **)(*a0 + 0x48))(a0), operandRecord != 0)) {
        loopPtr2 = (byte *)&(*(unsigned int *)((unsigned char *)ghidra_home + 16));
        uVar9 = 0;
        do {
          bVar2 = *loopPtr2;
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
          loopPtr2 = loopPtr2 + 1;
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
  undefined4 laneMask;
  int gotConstant;
  bool comparisonResult;
  int src1Kind;
  float src1Value;
  int src2Kind;
  float src2Value;
  
  laneMask = DAT_001b2d70;
  gotConstant = IRInst__getUniformSourceConstant(inst,1,DAT_001b2d70,&src1Kind);
  if ((((gotConstant == 0) || (src1Kind != 2)) ||
      (gotConstant = IRInst__getUniformSourceConstant(inst,2,laneMask,&src2Kind), gotConstant == 0)) || (src2Kind != 2)) {
    comparisonResult = false;
    *resultKnownOut = 0;
  }
  else {
    comparisonResult = false;
    switch(*(undefined4 *)(inst + 300)) {
    case 0:
      comparisonResult = src1Value == src2Value;
      break;
    case 1:
      comparisonResult = src1Value != src2Value;
      break;
    case 2:
      comparisonResult = src2Value < src1Value;
      break;
    case 3:
      comparisonResult = src2Value <= src1Value;
      break;
    case 4:
      comparisonResult = src1Value < src2Value;
      break;
    case 5:
      comparisonResult = src1Value <= src2Value;
    }
    *resultKnownOut = 1;
  }
  return comparisonResult;
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
int R520MachineAssembler__vslot26_assembleThenAppendRecord(this, node, block, compiler, unusedArg5, unusedArg6, unusedArg7)
  int *this;
  int node;
  undefined4 block;
  int compiler;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  undefined4 recordId;
  int inst;
  undefined4 sourceDef;
  bool flagPrevRecord;
  int branchKind;
  int iVar3;
  undefined4 registerIndex;
  undefined4 *elementRef;
  int a3;
  uint vectorFilledCount;
  undefined4 program;
  uint *vector;
  
  a3 = compiler;
  inst = Block__getBranchInst(node,node,block,compiler,unusedArg5,unusedArg6,unusedArg7);
  program = *(undefined4 *)(compiler + COMP_currentProgram);
  branchKind = *(int *)(inst + 300);
  sourceDef = IRInst__getOperandSource(inst,1);
  registerIndex = thunk_FUN_00134de8(program,sourceDef);
  iVar3 = this[0x18];
  (**(code **)(*this + 0x34))
            (this,block,*(undefined4 *)(node + 0xdc),a3,unusedArg5,unusedArg6,
             *(code **)(*this + 0x34));
  if ((*(int *)(node + 0xdc) == 0) || (flagPrevRecord = true, iVar3 != this[0x18])) {
    flagPrevRecord = false;
  }
  recordId = (**(code **)(*this + 0x98))(this,branchKind != 1,registerIndex,0);
  if (flagPrevRecord) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + -0x44) = 1;
  }
  vector = *(uint **)(this[4] + 0x24);
  vectorFilledCount = vector[1];
  if (vectorFilledCount < *vector) {
    _memset(vectorFilledCount * 4 + vector[2],0,4);
    elementRef = (undefined4 *)(vectorFilledCount * 4 + vector[2]);
    vector[1] = vectorFilledCount + 1;
  }
  else {
    elementRef = (undefined4 *)Vector__elementRefGrow(vector,vectorFilledCount);
  }
  *elementRef = recordId;
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
asm(".globl R520VMachineAssembler__vslot27_assembleLoopHeader");
asm(".set R520VMachineAssembler__vslot27_assembleLoopHeader, _R520VMachineAssembler__vslot27_assembleLoopHeader");
asm(".globl R520VMachineAssembler__vslot30_assembleBlockThenSlot40");
asm(".set R520VMachineAssembler__vslot30_assembleBlockThenSlot40, _R520VMachineAssembler__vslot30_assembleBlockThenSlot40");
asm(".globl R520VMachineAssembler__deleting_dtor");
asm(".set R520VMachineAssembler__deleting_dtor, _R520VMachineAssembler__deleting_dtor");
asm(".globl R520VMachineAssembler__init");
asm(".set R520VMachineAssembler__init, _R520VMachineAssembler__init");
asm(".globl R520VMachineAssembler__create");
asm(".set R520VMachineAssembler__create, _R520VMachineAssembler__create");
asm(".globl MachineAssembler__dtor_19df54");
asm(".set MachineAssembler__dtor_19df54, _MachineAssembler__dtor_19df54");
asm(".globl R520VMachineAssembler__vslot28_assembleIfEnd");
asm(".set R520VMachineAssembler__vslot28_assembleIfEnd, _R520VMachineAssembler__vslot28_assembleIfEnd");
asm(".globl R520VMachineAssembler__vslot31_assembleWithPredicateRestore");
asm(".set R520VMachineAssembler__vslot31_assembleWithPredicateRestore, _R520VMachineAssembler__vslot31_assembleWithPredicateRestore");
asm(".globl R520VMachineAssembler__vslot25_assembleConditionalBlock");
asm(".set R520VMachineAssembler__vslot25_assembleConditionalBlock, _R520VMachineAssembler__vslot25_assembleConditionalBlock");
asm(".globl R520VMachineAssembler__vslot6_setLoopStack");
asm(".set R520VMachineAssembler__vslot6_setLoopStack, _R520VMachineAssembler__vslot6_setLoopStack");
asm(".globl R520VMachineAssembler__vslot24_assembleWithPredicateSet");
asm(".set R520VMachineAssembler__vslot24_assembleWithPredicateSet, _R520VMachineAssembler__vslot24_assembleWithPredicateSet");
asm(".globl FUN_0019ef2c");
asm(".set FUN_0019ef2c, _FudoPs__vslot96_installHardwareTables");
asm(".globl R520MachineAssembler__vslot5_beginProgram");
asm(".set R520MachineAssembler__vslot5_beginProgram, _R520MachineAssembler__vslot5_beginProgram");
asm(".globl R520MachineAssembler__setRsColorFields");
asm(".set R520MachineAssembler__setRsColorFields, _R520MachineAssembler__setRsColorFields");
asm(".globl R520MachineAssembler__setRsTexCoordFields");
asm(".set R520MachineAssembler__setRsTexCoordFields, _R520MachineAssembler__setRsTexCoordFields");
asm(".globl R520MachineAssembler__clearCurrentRecord");
asm(".set R520MachineAssembler__clearCurrentRecord, _R520MachineAssembler__clearCurrentRecord");
asm(".globl R520MachineAssembler__initNopAluRecord");
asm(".set R520MachineAssembler__initNopAluRecord, _R520MachineAssembler__initNopAluRecord");
asm(".globl R520MachineAssembler__vslot65_declareNodeRegisters");
asm(".set R520MachineAssembler__vslot65_declareNodeRegisters, _R520MachineAssembler__vslot65_declareNodeRegisters");
asm(".globl R520MachineAssembler__vslot59_selectForSrcpSwizzle");
asm(".set R520MachineAssembler__vslot59_selectForSrcpSwizzle, _R520MachineAssembler__vslot59_selectForSrcpSwizzle");
asm(".globl R520MachineAssembler__vslot60_selectForSrcpComponent");
asm(".set R520MachineAssembler__vslot60_selectForSrcpComponent, _R520MachineAssembler__vslot60_selectForSrcpComponent");
asm(".globl R520MachineAssembler__vslot61_selectForAlphaSource");
asm(".set R520MachineAssembler__vslot61_selectForAlphaSource, _R520MachineAssembler__vslot61_selectForAlphaSource");
asm(".globl R520MachineAssembler__vslot62_selectForSourceSwizzle");
asm(".set R520MachineAssembler__vslot62_selectForSourceSwizzle, _R520MachineAssembler__vslot62_selectForSourceSwizzle");
asm(".globl R520MachineAssembler__vslot64_selectForColorComponent");
asm(".set R520MachineAssembler__vslot64_selectForColorComponent, _R520MachineAssembler__vslot64_selectForColorComponent");
asm(".globl R520MachineAssembler__vslot63_selectForAlphaComponent");
asm(".set R520MachineAssembler__vslot63_selectForAlphaComponent, _R520MachineAssembler__vslot63_selectForAlphaComponent");
asm(".globl R520MachineAssembler__setAluSourceAddresses");
asm(".set R520MachineAssembler__setAluSourceAddresses, _R520MachineAssembler__setAluSourceAddresses");
asm(".globl R520MachineAssembler__setAlphaOpcode");
asm(".set R520MachineAssembler__setAlphaOpcode, _R520MachineAssembler__setAlphaOpcode");
asm(".globl R520MachineAssembler__vslot77_setRecordByteB");
asm(".set R520MachineAssembler__vslot77_setRecordByteB, _R520MachineAssembler__vslot77_setRecordByteB");
asm(".globl R520MachineAssembler__writeHeaderRecord");
asm(".set R520MachineAssembler__writeHeaderRecord, _R520MachineAssembler__writeHeaderRecord");
asm(".globl R520MachineAssembler__vslot9_getRecordWordsUsed");
asm(".set R520MachineAssembler__vslot9_getRecordWordsUsed, _R520MachineAssembler__vslot9_getRecordWordsUsed");
asm(".globl R520MachineAssembler__vslot38_appendBranchRecord");
asm(".set R520MachineAssembler__vslot38_appendBranchRecord, _R520MachineAssembler__vslot38_appendBranchRecord");
asm(".globl R520MachineAssembler__vslot80_setRecordByte9");
asm(".set R520MachineAssembler__vslot80_setRecordByte9, _R520MachineAssembler__vslot80_setRecordByte9");
asm(".globl R520MachineAssembler__vslot55_tryEncodeImmediateLiteral");
asm(".set R520MachineAssembler__vslot55_tryEncodeImmediateLiteral, _R520MachineAssembler__vslot55_tryEncodeImmediateLiteral");
asm(".globl R520MachineAssembler__vslot67_selectForConstantLanes");
asm(".set R520MachineAssembler__vslot67_selectForConstantLanes, _R520MachineAssembler__vslot67_selectForConstantLanes");
asm(".globl R520MachineAssembler__beginNextRecord");
asm(".set R520MachineAssembler__beginNextRecord, _R520MachineAssembler__beginNextRecord");
asm(".globl R520MachineAssembler__vslot4_finishProgram");
asm(".set R520MachineAssembler__vslot4_finishProgram, _R520MachineAssembler__vslot4_finishProgram");
asm(".globl R520MachineAssembler__vslot79_setTexCompareFlags");
asm(".set R520MachineAssembler__vslot79_setTexCompareFlags, _R520MachineAssembler__vslot79_setTexCompareFlags");
asm(".globl R520MachineAssembler__vslot31_assembleChildrenAndMark");
asm(".set R520MachineAssembler__vslot31_assembleChildrenAndMark, _R520MachineAssembler__vslot31_assembleChildrenAndMark");
asm(".globl R520MachineAssembler__vslot24_assembleWithTarget");
asm(".set R520MachineAssembler__vslot24_assembleWithTarget, _R520MachineAssembler__vslot24_assembleWithTarget");
asm(".globl R520MachineAssembler__setRgbOpcode");
asm(".set R520MachineAssembler__setRgbOpcode, _R520MachineAssembler__setRgbOpcode");
asm(".globl R520MachineAssembler__vslot86_resolveSourceRegister");
asm(".set R520MachineAssembler__vslot86_resolveSourceRegister, _R520MachineAssembler__vslot86_resolveSourceRegister");
asm(".globl R520MachineAssembler__vslot53_selectBitsForLiteralFloat");
asm(".set R520MachineAssembler__vslot53_selectBitsForLiteralFloat, _R520MachineAssembler__vslot53_selectBitsForLiteralFloat");
asm(".globl R520MachineAssembler__vslot54_selectBitsForAlphaLiteral");
asm(".set R520MachineAssembler__vslot54_selectBitsForAlphaLiteral, _R520MachineAssembler__vslot54_selectBitsForAlphaLiteral");
asm(".globl R520MachineAssembler__vslot66_selectBitsForLiteralLanes");
asm(".set R520MachineAssembler__vslot66_selectBitsForLiteralLanes, _R520MachineAssembler__vslot66_selectBitsForLiteralLanes");
asm(".globl R520MachineAssembler__vslot71_setAluSourceSelectsAndModifiers");
asm(".set R520MachineAssembler__vslot71_setAluSourceSelectsAndModifiers, _R520MachineAssembler__vslot71_setAluSourceSelectsAndModifiers");
asm(".globl R520MachineAssembler__vslot29_patchBranchTarget");
asm(".set R520MachineAssembler__vslot29_patchBranchTarget, _R520MachineAssembler__vslot29_patchBranchTarget");
asm(".globl R520MachineAssembler__vslot26_assembleThenAppendRecord");
asm(".set R520MachineAssembler__vslot26_assembleThenAppendRecord, _R520MachineAssembler__vslot26_assembleThenAppendRecord");
asm(".globl R520MachineAssembler__create");
asm(".set R520MachineAssembler__create, _R520MachineAssembler__create");
