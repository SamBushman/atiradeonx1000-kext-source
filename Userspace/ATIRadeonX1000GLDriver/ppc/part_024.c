#include "decls.h"

/* ContinueBlock__clone @ 0xebff8 (64 bytes) */
int ContinueBlock__clone(this)
  int this;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(*(int *)(this + 0xa8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x138);
  *allocation = arena;
  ContinueBlock__ctor_ebfb4(allocation + 1,this);
  return allocation + 1;
}

/* BreakBlock__ctor_ec070 @ 0xec070 (88 bytes) */
int BreakBlock__ctor_ec070(this, scope, scopeField0x12c, compiler)
  undefined4 *this;
  undefined4 scope;
  undefined4 scopeField0x12c;
  undefined4 compiler;
{
  Block__ctor_ea148(this,compiler);
  this[0x4b] = scope;
  this[0x4c] = scopeField0x12c;
  *this = &PTR_FUN_001e9e20;
  return;
}

/* BreakBlock__ctor_ec0c8 @ 0xec0c8 (88 bytes) */
int BreakBlock__ctor_ec0c8(this, scope, scopeField0x12c, compiler)
  undefined4 *this;
  undefined4 scope;
  undefined4 scopeField0x12c;
  undefined4 compiler;
{
  Block__ctor_ea148(this,compiler);
  this[0x4b] = scope;
  this[0x4c] = scopeField0x12c;
  *this = &PTR_FUN_001e9e20;
  return;
}

/* ContinueBlock__ctor_ec120 @ 0xec120 (88 bytes) */
int ContinueBlock__ctor_ec120(this, scope, scopeField0x12c, compiler)
  undefined4 *this;
  undefined4 scope;
  undefined4 scopeField0x12c;
  undefined4 compiler;
{
  Block__ctor_ea148(this,compiler);
  this[0x4b] = scope;
  this[0x4c] = scopeField0x12c;
  *this = &PTR_FUN_001e9e78;
  return;
}

/* ContinueBlock__ctor_ec178 @ 0xec178 (88 bytes) */
int ContinueBlock__ctor_ec178(this, scope, scopeField0x12c, compiler)
  undefined4 *this;
  undefined4 scope;
  undefined4 scopeField0x12c;
  undefined4 compiler;
{
  Block__ctor_ea148(this,compiler);
  this[0x4b] = scope;
  this[0x4c] = scopeField0x12c;
  *this = &PTR_FUN_001e9e78;
  return;
}

/* Program__ensureVRegType13 @ 0xec1d0 (20 bytes) */
int Program__ensureVRegType13(program)
  int program;
{
  undefined4 registerMap;
  int existingVReg;
  
  registerMap = *(undefined4 *)(program + 0x3ac);
  existingVReg = VRegPool__find(registerMap,0x13,0,0);
  if (existingVReg == 0) {
    VRegPool__create(registerMap,0x13,0,0);
    return;
  }
  return;
}

/* callTargetSlot25 @ 0xec1ec (28 bytes) */
int callTargetSlot25(program)
  int program;
{
  int *hardwareInfo;
  
  hardwareInfo = *(int **)(*(int *)(program + 8) + 0x30c);
                    
                    
  (**(code **)(*hardwareInfo + 100))(hardwareInfo,program);
  return;
}

/* Program__registerFileOfIlType @ 0xec208 (80 bytes) */
int Program__registerFileOfIlType(program, ilRegisterType)
  int program;
  int ilRegisterType;
{
  int registerFile;
  
  registerFile = *(int *)(ilRegisterType * 8 + *(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 4) + 4);
  if (registerFile == -1) {
    Compiler__fail(*(int *)(program + 8),0xf);
  }
  return registerFile;
}

/* Program__interpSlotOfIlType @ 0xec258 (36 bytes) */
int Program__interpSlotOfIlType(program, ilType)
  undefined4 program;
  int ilType;
{
  return *(undefined4 *)(PTR_DAT_001e8b5c + ilType * 4);
}

/* Program__lookupTable8b68 @ 0xec27c (36 bytes) */
int Program__lookupTable8b68(program, ilType)
  undefined4 program;
  int ilType;
{
  return *(undefined4 *)(PTR_DAT_001e8b68 + ilType * 4);
}

/* Program__laneKindOfInterpSlot @ 0xec2a0 (36 bytes) */
int Program__laneKindOfInterpSlot(program, interpSlot)
  undefined4 program;
  int interpSlot;
{
  return *(undefined4 *)(PTR_DAT_001e8b6c + interpSlot * 4);
}

/* Table__interpolatorKindToCode @ 0xec2c4 (36 bytes) */
int Table__interpolatorKindToCode(unusedArg1, kind)
  undefined4 unusedArg1;
  int kind;
{
  return *(undefined4 *)(PTR_DAT_001e8b60 + kind * 4);
}

/* Program__freeWorkArrays @ 0xec2e8 (136 bytes) */
int Program__freeWorkArrays(program)
  int program;
{
  if (*(int *)(program + PROG_workArray0) != 0) {
    Arena__free(*(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaA),*(int *)(program + PROG_workArray0));
    *(undefined4 *)(program + PROG_workArray0) = 0;
  }
  if (*(int *)(program + PROG_workArray1) != 0) {
    Arena__free(*(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaA),*(int *)(program + PROG_workArray1));
    *(undefined4 *)(program + PROG_workArray1) = 0;
  }
  if (*(int *)(program + PROG_workArray2) != 0) {
    Arena__free(*(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaA),*(int *)(program + PROG_workArray2));
    *(undefined4 *)(program + PROG_workArray2) = 0;
  }
  return;
}

/* Program__insertBlockBefore @ 0xec370 (60 bytes) */
int Program__insertBlockBefore(program, ref, node)
  undefined4 program;
  undefined4 ref;
  int node;
{
  DList__insertBefore(node,ref);
  *(undefined4 *)(node + 0xac) = program;
  return ((int (*)())Program__freeWorkArrays)(program);
}

/* Program__insertBlockAfter @ 0xec3ac (60 bytes) */
int Program__insertBlockAfter(program, ref, node)
  undefined4 program;
  undefined4 ref;
  int node;
{
  DList__insertAfter(node,ref);
  *(undefined4 *)(node + 0xac) = program;
  return ((int (*)())Program__freeWorkArrays)(program);
}

/* Program__prependBlock @ 0xec3e8 (68 bytes) */
int Program__prependBlock(program, node)
  int program;
  int node;
{
  DList__pushFront(program + 0x37c,node);
  ((int (*)())Program__freeWorkArrays)(program);
  *(int *)(node + 0xac) = program;
  return ((int (*)())Program__freeWorkArrays)(program);
}

/* Program__appendBlock @ 0xec42c (60 bytes) */
int Program__appendBlock(program, node)
  int program;
  int node;
{
  DList__pushBack(program + 0x37c,node);
  *(int *)(node + 0xac) = program;
  return ((int (*)())Program__freeWorkArrays)(program);
}

/* Program__storeDominatorOrder @ 0xec468 (136 bytes) */
int Program__storeDominatorOrder(program, sourceArray, elementCount)
  int program;
  int sourceArray;
  uint elementCount;
{
  undefined4 allocation;
  int loopCounter;
  uint loopIndex;
  
  if (*(int *)(program + 0x394) != 0) {
    Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x374),*(int *)(program + 0x394));
  }
  allocation = Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x374),elementCount * 4 + 4);
  loopIndex = 0;
  *(undefined4 *)(program + 0x394) = allocation;
  loopCounter = 0;
  do {
    loopIndex = loopIndex + 1;
    *(undefined4 *)(*(int *)(program + 0x394) + loopCounter) = *(undefined4 *)(sourceArray + loopCounter);
    loopCounter = loopCounter + 4;
  } while (loopIndex <= elementCount);
  return;
}

/* Program__getDominatorInfo @ 0xec4f0 (124 bytes) */
int Program__getDominatorInfo(program)
  int program;
{
  int dominatorInfo;
  undefined4 *allocation;
  undefined4 arenaB;
  undefined4 *domTree;
  
  dominatorInfo = *(int *)(program + 0x394);
  if (dominatorInfo == 0) {
    arenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
    allocation = (undefined4 *)Arena__alloc(arenaB,0x2c);
    *allocation = arenaB;
    domTree = allocation + 1;
    DominatorTree__ctor_f7cd8(domTree,program);
    DominatorTree__dfsNumber(domTree,*(undefined4 *)(program + 0x3a0));
    ((int (*)())Program__storeDominatorOrder)(program,allocation[7],allocation[8]);
    DominatorTree__free(domTree);
    if (domTree == (undefined4 *)0x0) {
      dominatorInfo = *(int *)(program + 0x394);
    }
    else {
      Arena__free(*allocation,allocation);
      dominatorInfo = *(int *)(program + 0x394);
    }
  }
  return dominatorInfo;
}

/* Program__getBlocksArray @ 0xec5b8 (160 bytes) */
int Program__getBlocksArray(program)
  int program;
{
  undefined4 allocation;
  int listCount;
  int byteOffset;
  int blocksArray;
  undefined4 blockEntry;
  undefined4 *domOrder;
  int loopIndex;
  
  blocksArray = *(int *)(program + 0x398);
  if (blocksArray == 0) {
    listCount = DList__count(program + 0x37c);
    allocation = Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x374),listCount * 4 + 4);
    *(undefined4 *)(program + 0x398) = allocation;
    domOrder = (undefined4 *)((int (*)())Program__getDominatorInfo)(program);
    **(undefined4 **)(program + 0x398) = *domOrder;
    if (0 < listCount) {
      domOrder = domOrder + listCount;
      loopIndex = 1;
      do {
        byteOffset = loopIndex * 4;
        loopIndex = loopIndex + 1;
        blockEntry = *domOrder;
        domOrder = domOrder + -1;
        *(undefined4 *)(byteOffset + *(int *)(program + 0x398)) = blockEntry;
      } while (loopIndex <= listCount);
    }
    blocksArray = *(int *)(program + 0x398);
  }
  return blocksArray;
}

/* Program__countInstructions @ 0xec658 (88 bytes) */
int Program__countInstructions(program)
  int program;
{
  int listCount;
  int nextBlockLink;
  int total;
  int block;
  
  total = 0;
  block = *(int *)(program + 900);
  nextBlockLink = *(int *)(block + 8);
  while (nextBlockLink != 0) {
    listCount = DList__count(block + 0x90);
    block = *(int *)(block + 8);
    total = total + listCount;
    nextBlockLink = *(int *)(block + 8);
  }
  return total;
}

/* Program__findBranchingBlock @ 0xec6b0 (120 bytes) */
int Program__findBranchingBlock(program)
  int program;
{
  int edgeCount;
  int nextBlockLink;
  int block;
  
  block = *(int *)(program + 900);
  nextBlockLink = *(int *)(block + 8);
  while( true ) {
    if (nextBlockLink == 0) {
      return 0;
    }
    edgeCount = Block__predecessorCount(block);
    if ((1 < edgeCount) || (edgeCount = Block__successorCount(block), 1 < edgeCount)) break;
    block = *(int *)(block + 8);
    nextBlockLink = *(int *)(block + 8);
  }
  return 1;
}

/* Program__splitMixedSourceKinds @ 0xec728 (444 bytes) */
int Program__splitMixedSourceKinds(program)
  int program;
{
  undefined4 sourceVReg;
  int sourceCursor2;
  int newTempIndex;
  int loopIndex3;
  int block;
  undefined4 inst;
  undefined4 tempVReg;
  int loopIndex;
  int sourceCursor;
  int loopIndex2;
  int iVar7;
  int iVar8;
  int candidateInst;
  int sourcesLeft;
  
  block = *(int *)(program + 900);
  for (iVar8 = *(int *)(*(int *)(program + 900) + 8); iVar8 != 0; iVar8 = *(int *)(iVar8 + 8)) {
    iVar7 = *(int *)(*(int *)(block + 0x98) + 8);
    candidateInst = *(int *)(block + 0x98);
    if (iVar7 != 0) {
      do {
        iVar8 = iVar7;
        if (((*(uint *)(candidateInst + 0x14) & 1) != 0) && (iVar7 = *(int *)(candidateInst + 0x84), 0 < iVar7)) {
          loopIndex = 0;
          loopIndex2 = 0;
          sourceCursor = candidateInst;
          sourcesLeft = iVar7;
          do {
            if (*(int *)(sourceCursor + 0xb0) - 2U < 3) {
              loopIndex2 = loopIndex2 + 1;
            }
            else if (*(int *)(sourceCursor + 0xb0) == 0xc) {
              loopIndex = loopIndex + 1;
            }
            sourceCursor = sourceCursor + 0x18;
            sourcesLeft = sourcesLeft + -1;
          } while (sourcesLeft != 0);
          if ((loopIndex2 != 0) && (loopIndex != 0)) {
            loopIndex3 = 0;
            sourceCursor2 = candidateInst;
            do {
              loopIndex3 = loopIndex3 + 1;
              if (((*(int *)(sourceCursor2 + 0xb0) - 2U < 3) && (loopIndex >= loopIndex2)) ||
                 ((*(int *)(sourceCursor2 + 0xb0) == 0xc && (loopIndex < loopIndex2)))) {
                inst = IRInst__create(0x31,*(undefined4 *)(program + 8));
                tempVReg = *(undefined4 *)(program + 0x3ac);
                sourceVReg = *(undefined4 *)(sourceCursor2 + 0xa4);
                newTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
                *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex;
                tempVReg = VRegPool__findOrCreate(tempVReg,0,newTempIndex,0);
                IRInst__setOperandRef(inst,0,tempVReg);
                IRInst__setOperandRef(inst,1,sourceVReg);
                Owner__replaceVectorEntry(sourceVReg,candidateInst,inst);
                IRInst__setOperandRef(candidateInst,loopIndex3,tempVReg);
                Block__insertInstBefore(*(undefined4 *)(candidateInst + 0x158),candidateInst,inst);
              }
              sourceCursor2 = sourceCursor2 + 0x18;
            } while (iVar7 != loopIndex3);
            iVar8 = *(int *)(candidateInst + 8);
          }
        }
        iVar7 = *(int *)(iVar8 + 8);
        candidateInst = iVar8;
      } while (*(int *)(iVar8 + 8) != 0);
      iVar8 = *(int *)(block + 8);
    }
    block = iVar8;
  }
  return;
}

/* Program__freezeVRegs @ 0xec8e4 (60 bytes) */
int Program__freezeVRegs(program)
  int program;
{
  VRegPool__destroyEntries(*(undefined4 *)(program + 0x3ac));
  *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 0x10;
  return;
}

/* FUN_000ec920 @ 0xec920 (240 bytes) */
int FUN_000ec920(program)
  int program;
{
  int oldFlags;
  int listCount;
  int successor;
  undefined4 *blocksArray;
  int blockIsEntryLike;
  uint loopIndex2;
  int loopCounter;
  int loopIndex;
  undefined4 *blockCursor;
  int *block;
  bool changed;
  
  blocksArray = (undefined4 *)((int (*)())Program__getBlocksArray)(program);
  do {
    changed = false;
    loopIndex = 1;
    blockCursor = blocksArray;
    while( true ) {
      blockCursor = blockCursor + 1;
      listCount = DList__count(program + 0x37c);
      if (listCount < loopIndex) break;
      block = (int *)*blockCursor;
      blockIsEntryLike = (**(code **)(*block + 0x20))(block);
      if (blockIsEntryLike == 0) {
        oldFlags = block[3];
        loopCounter = 0;
        for (loopIndex2 = 1; loopIndex2 <= *(uint *)(block[0x34] + 4); loopIndex2 = loopIndex2 + 1) {
          successor = *(int *)(*(int *)(block[0x34] + 8) + loopCounter);
          if (successor != 0) {
            block[3] = *(uint *)(successor + 0xc) & 3 | block[3];
          }
          loopCounter = loopCounter + 4;
        }
        changed = oldFlags != block[3];
      }
      loopIndex = loopIndex + 1;
    }
  } while (changed);
  return;
}

/* KhanVs__vslot17_isSimpleInst @ 0xeca10 (192 bytes) */
int KhanVs__vslot17_isSimpleInst(this, inst)
  undefined4 this;
  int *inst;
{
  int slotResult;
  uint excluded;
  
  slotResult = (**(code **)(*inst + 0x40))(inst,inst);
  if ((((slotResult != 0) || (slotResult = (**(code **)(*inst + 0x28))(inst), slotResult != 0)) ||
      (slotResult = (**(code **)(*inst + 0x60))(inst), slotResult != 0)) ||
     ((slotResult = (**(code **)(*inst + 0x5c))(inst), slotResult != 0 ||
      (excluded = 0, *(int *)(inst[0x22] + 8) == 0x84)))) {
    excluded = 1;
  }
  return excluded ^ 1;
}

/* KhanPs__vslot17_isSimpleInst @ 0xecad0 (192 bytes) */
int KhanPs__vslot17_isSimpleInst(this, inst)
  undefined4 this;
  int *inst;
{
  int slotResult;
  uint excluded;
  
  slotResult = (**(code **)(*inst + 0x40))(inst,inst);
  if ((((slotResult != 0) || (slotResult = (**(code **)(*inst + 0x28))(inst), slotResult != 0)) ||
      (slotResult = (**(code **)(*inst + 0x60))(inst), slotResult != 0)) ||
     ((slotResult = (**(code **)(*inst + 0x5c))(inst), slotResult != 0 ||
      (excluded = 0, *(int *)(inst[0x22] + 8) == 0x84)))) {
    excluded = 1;
  }
  return excluded ^ 1;
}

/* FUN_000ecb90 @ 0xecb90 (140 bytes) */
int FUN_000ecb90(inst, compiler)
  int inst;
  undefined4 compiler;
{
  int flagBitQuery;
  int foldableMov;
  undefined4 opcodeId;
  
  foldableMov = OpcodeTraits__flag1WithoutFlag7(compiler,inst);
  if (foldableMov == 0) {
    opcodeId = *(undefined4 *)(*(int *)(inst + 0x88) + 8);
    flagBitQuery = OpcodeTraits__flagBit2(opcodeId,compiler);
    if (((flagBitQuery == 0) || (flagBitQuery = OpcodeTraits__flagBit9(opcodeId,compiler), flagBitQuery != 0)) &&
       (flagBitQuery = OpcodeTraits__flagBit8(opcodeId,compiler), flagBitQuery == 0)) {
      return 0;
    }
  }
  return 1;
}

/* IRInst__isForwardable @ 0xecc1c (268 bytes) */
int IRInst__isForwardable(inst, selectWord, compiler)
  int *inst;
  undefined4 selectWord;
  int compiler;
{
  int queryResult;
  int hasSingleUse;
  int iVar1;
  
  queryResult = (**(code **)(*inst + 0x60))(inst,selectWord,compiler);
  if (queryResult != 0) {
    hasSingleUse = IRInst__hasSingleUse(inst,*(undefined4 *)(compiler + COMP_currentProgram));
    if (hasSingleUse == 0) {
      return 0;
    }
    iVar1 = IRInst__canFoldConstantCompare(inst,compiler);
    if (iVar1 == 0) {
      return 0;
    }
    inst = (int *)IRInst__getOperandSource(inst,1);
  }
  iVar1 = IRInst__hasSingleUse(inst,*(undefined4 *)(compiler + COMP_currentProgram));
  if ((((iVar1 != 0) &&
       (iVar1 = (**(code **)(**(int **)(compiler + COMP_target) + 0x44))
                          (*(int **)(compiler + COMP_target),inst), iVar1 != 0)) &&
      ((*(uint *)(inst[0x56] + 0xc) & 8) != 0)) &&
     ((iVar1 = SelectWord__areCompatible(selectWord,0x10203), iVar1 != 0 ||
      (iVar1 = ((int (*)())FUN_000ecb90)(inst,compiler), iVar1 != 0)))) {
    return 1;
  }
  return 0;
}

/* Program__insertMovAfter @ 0xecd28 (424 bytes) */
int Program__insertMovAfter(program, newSource, afterInst, destRegisterOffset, destRegister, sourceSelectWord)
  int program;
  int *newSource;
  int *afterInst;
  undefined4 destRegisterOffset;
  undefined4 destRegister;
  undefined4 sourceSelectWord;
{
  int *targetBlock;
  int isStoreLike;
  int isEntryLike;
  int operandRecord;
  int *nextInst;
  int *newMov;
  int sourceBlock;
  int *scanInst;
  int clearedSelect [2];
  
  newMov = (int *)IRMov__new_1084b8(0x31,*(undefined4 *)(program + 8));
  IRInst__setOperandSource(newMov,1,newSource,0,*(undefined4 *)(program + 8));
  IRInst__setHardwareRegisterAndAdd(newMov,program,destRegisterOffset,destRegister);
  (**(code **)(*newMov + 0x94))(newMov,afterInst,*(undefined4 *)(program + 8));
  SelectWord__clearReadComponents(clearedSelect,sourceSelectWord);
  newMov[0x27] = clearedSelect[0];
  operandRecord = IRInst__getOperandRecord(newMov,1);
  *(undefined4 *)(operandRecord + 0x10) = sourceSelectWord;
  sourceBlock = newSource[0x56];
  if (sourceBlock == afterInst[0x56]) {
    scanInst = *(int **)(sourceBlock + 0x98);
    for (nextInst = (int *)(*(int **)(sourceBlock + 0x98))[2]; nextInst != (int *)0x0;
        nextInst = (int *)nextInst[2]) {
      if ((scanInst[5] & 1U) != 0) {
        if (scanInst == afterInst) break;
        if (scanInst == newSource) goto LAB_000ece34;
      }
      scanInst = nextInst;
    }
  }
  else if ((*(uint *)(sourceBlock + 0xc) & 8) == 0) goto LAB_000ece34;
  afterInst = newSource;
LAB_000ece34:
  targetBlock = (int *)afterInst[0x56];
  isEntryLike = (**(code **)(*targetBlock + 0x2c))(targetBlock);
  if (isEntryLike != 0) {
    Block__prependInst(targetBlock[0x55],newMov);
    return;
  }
  isStoreLike = (**(code **)(*afterInst + 0x7c))(afterInst);
  if (isStoreLike != 0) {
    Block__insertAtStart(targetBlock,newMov);
    return;
  }
  return Block__insertInstAfter(targetBlock,afterInst,newMov);
}

/* FUN_000eced0 @ 0xeced0 (140 bytes) */
int FUN_000eced0(program)
  int program;
{
  int prevBlock;
  int nextBlockLink;
  undefined4 *allocation;
  undefined4 arenaA;
  
  arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
  *allocation = arenaA;
  IRInst__ctor_10502c(allocation + 1,0x93,*(undefined4 *)(program + 8));
  *(undefined4 **)(program + 0x33c) = allocation + 1;
  allocation[0x27] = 0x2d;
  allocation[0x26] = 0;
  *(undefined4 *)(*(int *)(program + 0x33c) + 300) = 0;
  *(uint *)(*(int *)(program + 0x3a0) + 0xc) = *(uint *)(*(int *)(program + 0x3a0) + 0xc) | 8;
  Block__prependInst(*(undefined4 *)(program + 0x3a0),*(undefined4 *)(program + 0x33c));
  prevBlock = *(int *)(program + 900);
  for (nextBlockLink = *(int *)(*(int *)(program + 900) + 8); nextBlockLink != 0; nextBlockLink = *(int *)(nextBlockLink + 8)) {
    *(uint *)(prevBlock + 0xc) = *(uint *)(prevBlock + 0xc) | 8;
    prevBlock = nextBlockLink;
  }
  return;
}

/* Program__dtor_ecfac @ 0xecfac (312 bytes) */
int Program__dtor_ecfac(program)
  int program;
{
  int ownedObject;
  undefined *baseVtable;
  
  ownedObject = *(int *)(program + 0x430);
  if (ownedObject != 0) {
    Arena__free(*(undefined4 *)(ownedObject + -4),ownedObject + -4);
  }
  ownedObject = *(int *)(program + 0x42c);
  if (ownedObject != 0) {
    Arena__free(*(undefined4 *)(ownedObject + -4),ownedObject + -4);
  }
  ownedObject = *(int *)(program + 0x3c8);
  if (ownedObject != 0) {
    Arena__free(*(undefined4 *)(ownedObject + 0xc),*(undefined4 *)(ownedObject + 8));
    Arena__free(*(undefined4 *)(ownedObject + -4),ownedObject + -4);
  }
  ownedObject = *(int *)(program + 0x3c4);
  if (ownedObject != 0) {
    Arena__free(*(undefined4 *)(ownedObject + 0xc),*(undefined4 *)(ownedObject + 8));
    Arena__free(*(undefined4 *)(ownedObject + -4),ownedObject + -4);
  }
  ownedObject = *(int *)(program + 0x3ac);
  if (ownedObject != 0) {
    VRegPool__dtor_127470(ownedObject);
    Arena__free(*(undefined4 *)(ownedObject + -4),ownedObject + -4);
  }
  Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x374),*(undefined4 *)(program + 0x460));
  Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x374),*(undefined4 *)(program + 0x45c));
  Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x374),*(undefined4 *)(program + 0x458));
  Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x374),*(undefined4 *)(program + 0x394));
  Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x374),*(undefined4 *)(program + 0x398));
  Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x374),*(undefined4 *)(program + 0x39c));
  DListNode__clear((undefined4 *)(program + 0x37c));
  baseVtable = PTR_DAT_001e8b48 + 8;
  *(undefined4 *)(program + 0x37c) = baseVtable;
  *(undefined **)(program + 0x388) = baseVtable;
  return;
}

/* Program__dtor_ed124 @ 0xed124 (312 bytes) */
int Program__dtor_ed124(program)
  int program;
{
  int ownedObject;
  undefined *baseVtable;
  
  ownedObject = *(int *)(program + 0x430);
  if (ownedObject != 0) {
    Arena__free(*(undefined4 *)(ownedObject + -4),ownedObject + -4);
  }
  ownedObject = *(int *)(program + 0x42c);
  if (ownedObject != 0) {
    Arena__free(*(undefined4 *)(ownedObject + -4),ownedObject + -4);
  }
  ownedObject = *(int *)(program + 0x3c8);
  if (ownedObject != 0) {
    Arena__free(*(undefined4 *)(ownedObject + 0xc),*(undefined4 *)(ownedObject + 8));
    Arena__free(*(undefined4 *)(ownedObject + -4),ownedObject + -4);
  }
  ownedObject = *(int *)(program + 0x3c4);
  if (ownedObject != 0) {
    Arena__free(*(undefined4 *)(ownedObject + 0xc),*(undefined4 *)(ownedObject + 8));
    Arena__free(*(undefined4 *)(ownedObject + -4),ownedObject + -4);
  }
  ownedObject = *(int *)(program + 0x3ac);
  if (ownedObject != 0) {
    VRegPool__dtor_127470(ownedObject);
    Arena__free(*(undefined4 *)(ownedObject + -4),ownedObject + -4);
  }
  Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x374),*(undefined4 *)(program + 0x460));
  Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x374),*(undefined4 *)(program + 0x45c));
  Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x374),*(undefined4 *)(program + 0x458));
  Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x374),*(undefined4 *)(program + 0x394));
  Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x374),*(undefined4 *)(program + 0x398));
  Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x374),*(undefined4 *)(program + 0x39c));
  DListNode__clear((undefined4 *)(program + 0x37c));
  baseVtable = PTR_DAT_001e8b48 + 8;
  *(undefined4 *)(program + 0x37c) = baseVtable;
  *(undefined **)(program + 0x388) = baseVtable;
  return;
}

/* HwLimits__vslot43_prependDefaultMov @ 0xed29c (264 bytes) */
int HwLimits__vslot43_prependDefaultMov(this, inst, unusedArg3, compiler)
  undefined4 this;
  int inst;
  undefined4 unusedArg3;
  int compiler;
{
  int lanesLeft;
  int laneIndex;
  int destRecord;
  int inst2;
  int destRecord2;
  double staleFprArg1;
  undefined4 unwrittenLaneMask;
  undefined4 destSelectBytes [8];
  
  if (inst == 0) {
    Compiler__fail(compiler,0xf);
  }
  destRecord = IRInst__getOperandRecord(inst,0);
  if (*(int *)(destRecord + 0x10) != DAT_001aa800) {
    inst2 = IRInst__create(0x31,compiler);
    staleFprArg1 = (double)FLOAT_001aa0d4;
    ((void (*)())IRInst__makeLiteralVec4Float)(inst2,*(undefined4 *)(compiler + COMP_currentProgram),1,staleFprArg1,staleFprArg1,staleFprArg1,
                 (double)FLOAT_001aa0e8);
    IRInst__setOperandRef(inst2,0,*(undefined4 *)(inst + 0xa4));
    destRecord2 = IRInst__getOperandRecord(inst,0);
    laneIndex = 0;
    destSelectBytes[0] = *(undefined4 *)(destRecord2 + 0x10);
    lanesLeft = 4;
    do {
      *(byte *)((int)destSelectBytes + laneIndex + -4) =
           (byte)(-(uint)(*(byte *)((int)destSelectBytes + laneIndex) ^ 1) >> 0x1f);
      laneIndex = laneIndex + 1;
      lanesLeft = lanesLeft + -1;
    } while (lanesLeft != 0);
    *(undefined4 *)(inst2 + 0x9c) = unwrittenLaneMask;
    Block__prependInst(*(undefined4 *)(inst + 0x158),inst2);
    *(int *)(inst + 0x9c) = DAT_001aa800;
  }
  return;
}

/* IRInst__bindOperandRegisters @ 0xed63c (424 bytes) */
int IRInst__bindOperandRegisters(program, inst)
  int program;
  int inst;
{
  int *sourceVRegRemapped;
  int *sourceVReg;
  int operandRecord;
  int operandRecord2;
  int *destVReg;
  int operandCursor;
  int *destVRegRemapped;
  int sourceRegisterFile;
  int loopIndex;
  undefined4 newRegisterFile;
  code *remapFn;
  int newTempIndex;
  
  if (*(int *)(inst + 0x80) != 0) {
    destVReg = (int *)VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),*(undefined4 *)(inst + 0x98),
                                 *(undefined4 *)(inst + 0x94),0);
    remapFn = *(code **)(*destVReg + 0x28);
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    destVRegRemapped = (int *)(*remapFn)(destVReg,*(undefined4 *)(operandRecord2 + 0x10),program);
    if ((destVRegRemapped == (int *)0x0) || (destVReg == destVRegRemapped)) {
      VReg__appendUser(destVReg,inst);
      IRInst__setOperandRef(inst,0,destVReg);
    }
    else {
      VReg__appendUser(destVRegRemapped,inst);
      IRInst__setOperandRef(inst,0,destVRegRemapped);
      if ((*(uint *)(program + 0x30) & 0x4000) != 0) {
        Block__insertInstAfter(*(undefined4 *)(inst + 0x158),inst,destVReg[0xc]);
      }
    }
  }
  if (0 < *(int *)(inst + 0x84)) {
    loopIndex = 1;
    operandCursor = inst;
    do {
      sourceRegisterFile = *(int *)(operandCursor + 0xb0);
      if (sourceRegisterFile == 0x1c) {
        newTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex;
        newRegisterFile = *(undefined4 *)(operandCursor + 0xb0);
        operandRecord = IRInst__getOperandRecord(inst,loopIndex);
        *(int *)(operandRecord + 8) = newTempIndex;
        *(undefined4 *)(operandRecord + 0xc) = newRegisterFile;
        sourceRegisterFile = *(int *)(operandCursor + 0xb0);
      }
      sourceVReg = (int *)VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),sourceRegisterFile,
                                   *(undefined4 *)(operandCursor + 0xac),0);
      sourceVRegRemapped = (int *)(**(code **)(*sourceVReg + 0x28))(sourceVReg,DAT_001aa80c,program);
      if (sourceVRegRemapped != (int *)0x0) {
        sourceVReg = sourceVRegRemapped;
      }
      VReg__addUse(sourceVReg,loopIndex,inst);
      IRInst__setOperandRef(inst,loopIndex,sourceVReg);
      loopIndex = loopIndex + 1;
      operandCursor = operandCursor + 0x18;
    } while (loopIndex <= *(int *)(inst + 0x84));
  }
  return;
}

/* Program__beginPass @ 0xed7e4 (184 bytes) */
int Program__beginPass(program, param_2)
  int program;
  uint param_2;
{
  int iVar1;
  int iVar2;
  uint r4AfterCall;
  int loopCounter;
  int *a0;
  uint loopIndex;
  
  a0 = *(int **)(program + PROG_blockListHead);
  iVar1 = a0[2];
  while (iVar1 != 0) {
    (**(code **)(*a0 + 0x48))(a0,param_2);
    a0 = (int *)a0[2];
    param_2 = r4AfterCall;
    iVar1 = a0[2];
  }
  iVar1 = *(int *)(program + PROG_instructionVector);
  loopCounter = 0;
  for (loopIndex = 1; loopIndex <= *(uint *)(iVar1 + 4); loopIndex = loopIndex + 1) {
    iVar2 = *(int *)(*(int *)(iVar1 + 8) + loopCounter);
    if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
      IRInst__getOperandRecord(iVar2,0);
      iVar1 = *(int *)(program + PROG_instructionVector);
    }
    loopCounter = loopCounter + 4;
  }
  return 1;
}

/* FUN_000ed89c @ 0xed89c (852 bytes) */
int FUN_000ed89c(program)
  int program;
{
  undefined4 *projectionInst;
  int *memberCursor;
  int *groupNextLink;
  int *prevMember;
  int *nextGroup;
  int *nextMember;
  int *splitGroupList;
  int *groupCursor;
  int memberInst;
  int memberExtent;
  int memberInstRef;
  int sourceSelectWord;
  int isSelectableLoad;
  undefined4 arena;
  int operandRecord;
  bool noGroupsYet;
  int block;
  int *nextInst;
  int *followingInst;
  int nextBlock;
  undefined4 *allocation;
  undefined4 *newGroup;
  int memberSize;
  int memberOffset;
  int *inst;
  undefined4 destSelectWord;
  int *memberList;
  int loadKind;
  undefined4 groupSourceVReg;
  int *groupList;
  undefined4 virtualRegister;
  undefined4 arenaAt374;
  int group;
  int loadBaseKey;
  int loadOffset;
  int loadSize [6];
  
  block = *(int *)(program + 900);
  nextBlock = *(int *)(*(int *)(program + 900) + 8);
  do {
    if (nextBlock == 0) {
      return;
    }
    nextInst = (int *)(*(int **)(block + 0x98))[2];
    if (nextInst != (int *)0x0) {
      memberList = (int *)0x0;
      groupList = (int *)0x0;
      noGroupsYet = true;
      inst = *(int **)(block + 0x98);
      do {
        followingInst = nextInst;
        if ((inst[5] & 1U) != 0) {
          loadKind = inst[0x2c];
          isSelectableLoad = (**(code **)(*inst + 0x28))(inst);
          if (((isSelectableLoad == 0) || (isSelectableLoad = (**(code **)(*inst + 0x2c))(inst), isSelectableLoad == 0)) ||
             ((loadKind != 0x1f && (((loadKind != 0xd && (loadKind != 0xe)) && (loadKind != 0xf)))))) {
            followingInst = (int *)inst[2];
          }
          else {
            arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
            allocation = (undefined4 *)Arena__alloc(arena,0x18);
            *allocation = arena;
            allocation[5] = memberList;
            allocation[2] = inst;
            inst[0x4d] = 1;
            operandRecord = IRInst__getOperandRecord(inst,1);
            sourceSelectWord = *(int *)(operandRecord + 0x10);
            Vslot__outDefaults_0_0_4(inst,&loadBaseKey,&loadOffset,loadSize);
            allocation[3] = loadOffset;
            allocation[4] = loadSize[0];
            groupCursor = groupList;
            if (!noGroupsYet) {
              do {
                if (((*groupCursor == loadBaseKey) && (loadKind == groupCursor[1])) && (groupCursor[2] == sourceSelectWord)) {
                  if (loadOffset < groupCursor[5]) {
                    groupCursor[3] = (int)inst;
                    groupCursor[5] = loadOffset;
                  }
                  if (groupCursor[6] < loadOffset + loadSize[0]) {
                    groupCursor[6] = loadOffset + loadSize[0];
                  }
                  groupCursor[4] = groupCursor[4] + 1;
                  goto LAB_000eda98;
                }
                groupNextLink = groupCursor + 0xb;
                groupCursor = (int *)*groupNextLink;
              } while ((int *)*groupNextLink != (int *)0x0);
            }
            arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
            newGroup = (undefined4 *)Arena__alloc(arena,0x34);
            *newGroup = arena;
            groupCursor = newGroup + 1;
            noGroupsYet = groupCursor == (int *)0x0;
            newGroup[2] = loadKind;
            newGroup[1] = loadBaseKey;
            newGroup[3] = sourceSelectWord;
            newGroup[6] = loadOffset;
            newGroup[0xc] = groupList;
            newGroup[7] = loadOffset + loadSize[0];
            newGroup[5] = 1;
            newGroup[4] = inst;
            groupList = groupCursor;
LAB_000eda98:
            allocation[1] = groupCursor;
            followingInst = (int *)inst[2];
            memberList = allocation + 1;
          }
        }
        nextInst = (int *)followingInst[2];
        inst = followingInst;
      } while ((int *)followingInst[2] != (int *)0x0);
      if (!noGroupsYet) {
        do {
          virtualRegister = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0x22,0,0);
          splitGroupList = (int *)0x0;
          do {
            memberInstRef = groupList[3];
            nextGroup = (int *)groupList[0xb];
            groupList[7] = memberInstRef;
            groupList[0xb] = 0;
            groupSourceVReg = *(undefined4 *)(memberInstRef + 0x8c);
            operandRecord = IRInst__getOperandRecord(memberInstRef,0);
            destSelectWord = *(undefined4 *)(operandRecord + 0x10);
            IRInst__setOperandRef(groupList[7],0,virtualRegister);
            *(undefined4 *)(groupList[7] + 0x9c) = DAT_001aa800;
            VReg__appendUser(virtualRegister,groupList[7]);
            arenaAt374 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
            allocation = (undefined4 *)Arena__alloc(arenaAt374,0x168);
            *allocation = arenaAt374;
            projectionInst = allocation + 1;
            IRProjection__ctor_109e28(projectionInst,0x84,*(undefined4 *)(program + 8));
            IRInst__setOperandRef(projectionInst,0,groupSourceVReg);
            allocation[0x28] = destSelectWord;
            IRInst__setOperandRef(projectionInst,1,virtualRegister);
            VReg__appendUser(groupSourceVReg,projectionInst);
            VReg__addUse(virtualRegister,1,projectionInst);
            Block__insertInstAfter(block,groupList[7],projectionInst);
            *(undefined4 **)(groupList[7] + 0x138) = projectionInst;
            groupList[9] = groupList[5];
            groupList[8] = (int)projectionInst;
            groupList[10] = 0;
            *(undefined4 *)(groupList[7] + 0x13c) = 0;
            if (8 < groupList[6] - groupList[5]) {
              groupList[0xb] = (int)splitGroupList;
              groupList[5] = groupList[6] + 1;
              groupList[6] = 0;
              groupList[3] = 0;
              groupList[4] = 0;
              splitGroupList = groupList;
            }
            groupList = nextGroup;
          } while (nextGroup != (int *)0x0);
          prevMember = (int *)0x0;
          memberCursor = memberList;
          while (memberList = prevMember, memberCursor != (int *)0x0) {
            group = *memberCursor;
            nextMember = (int *)memberCursor[4];
            memberCursor[4] = 0;
            memberInst = memberCursor[1];
            memberOffset = memberCursor[2];
            memberSize = memberCursor[3];
            memberExtent = (memberOffset + memberSize) - *(int *)(group + 0x24);
            prevMember = memberList;
            if (memberInst == *(int *)(group + 0x1c)) {
              memberCursor = nextMember;
              if (*(int *)(group + 0x28) < memberExtent) {
                *(int *)(group + 0x28) = memberExtent;
                *(int *)(memberInst + 0x13c) = memberExtent;
              }
            }
            else if (memberExtent < 9) {
              if (*(int *)(group + 0x28) < memberExtent) {
                *(int *)(group + 0x28) = memberExtent;
                *(int *)(*(int *)(group + 0x1c) + 0x13c) = memberExtent;
                memberInst = memberCursor[1];
              }
              DList__unlink(memberInst);
              DList__insertAfter(memberCursor[1],*(undefined4 *)(group + 0x20));
              IRInst__appendSource(memberCursor[1],virtualRegister);
              VReg__addUse(virtualRegister,*(undefined4 *)(memberCursor[1] + 0x84),memberCursor[1]);
              memberCursor = nextMember;
            }
            else {
              if (memberOffset < *(int *)(group + 0x14)) {
                *(int *)(group + 0xc) = memberInst;
                *(int *)(group + 0x14) = memberCursor[2];
                memberOffset = memberCursor[2];
                memberSize = memberCursor[3];
              }
              if (*(int *)(group + 0x18) < memberOffset + memberSize) {
                *(int *)(group + 0x18) = memberOffset + memberSize;
              }
              *(int *)(group + 0x10) = *(int *)(group + 0x10) + 1;
              memberCursor[4] = (int)memberList;
              prevMember = memberCursor;
              memberCursor = nextMember;
            }
          }
          groupList = splitGroupList;
        } while (splitGroupList != (int *)0x0);
      }
      nextBlock = *(int *)(block + 8);
    }
    block = nextBlock;
    nextBlock = *(int *)(nextBlock + 8);
  } while( true );
}

/* Program__ctor_edd98 @ 0xedd98 (1216 bytes) */
int Program__ctor_edd98(program, compiler)
  undefined4 *program;
  undefined4 compiler;
{
  int clearCount4;
  int hwTableClearCount;
  int tableClearCount;
  int clearCount1;
  undefined4 *hwRegisterTableAlloc;
  undefined4 *tableData;
  undefined4 vectorData;
  undefined4 *allocation;
  undefined4 *zeroCursor;
  undefined4 *registerTableAlloc;
  undefined4 arenaA;
  int clearCount0;
  
  program[2] = compiler;
  *program = 0;
  program[0xc] = 0;
  program[0x1f] = 0xffffffff;
  program[0x20] = 0xffffffff;
  program[0x21] = 0;
  program[0x22] = 0;
  program[0x23] = 0;
  program[0x24] = 0;
  program[0x25] = 0;
  program[0x26] = 0;
  program[0x27] = 0;
  program[0x28] = 0;
  program[0x29] = 0;
  program[0x2a] = 0;
  program[0x2b] = 0;
  program[0x2c] = 0;
  program[0x2d] = 0;
  program[0x2e] = 0;
  program[0x2f] = 0;
  program[0x30] = 0;
  program[0x31] = 0;
  program[0x32] = 0;
  program[0x33] = 0;
  program[0x34] = 0;
  program[0x35] = 0;
  program[0x36] = 0;
  program[0x37] = 0;
  program[0x38] = 0;
  program[0x39] = 0;
  program[0x3a] = 0;
  program[0x3b] = 0;
  program[0x3c] = 0;
  program[0x3d] = 0;
  program[0x3e] = 0;
  program[0x3f] = 0;
  program[0x40] = 0;
  program[0x41] = 0;
  program[0x42] = 0;
  program[0x43] = 0;
  program[0x44] = 0;
  program[0x45] = 0;
  program[0x46] = 0;
  program[0x47] = 0;
  program[0x48] = 0;
  program[0x49] = 0;
  program[0x4a] = 0;
  program[0x4b] = 0;
  program[0x4c] = 0;
  program[0x4d] = 0;
  program[0x4e] = 0;
  program[0x4f] = 0;
  program[0x50] = 0;
  program[0x51] = 0;
  program[0x52] = 0;
  program[0x53] = 0;
  program[0x54] = 0;
  program[0x55] = 0;
  program[0x56] = 0;
  program[0x57] = 0;
  program[0x58] = 0;
  program[0x59] = 0;
  program[0x5a] = 0;
  program[0x5b] = 0;
  program[0x5c] = 0;
  program[0x5d] = 0;
  program[0x5e] = 0;
  program[0x5f] = 0;
  program[0x60] = 0;
  program[0x61] = 0;
  program[0x62] = 0;
  program[99] = 0;
  program[100] = 0;
  program[0x65] = 0;
  program[0x66] = 0;
  program[0x67] = 0;
  program[0x68] = 0;
  program[0x69] = 0;
  program[0x6a] = 0;
  program[0x6b] = 0;
  program[0x6c] = 0;
  program[0x6d] = 0;
  program[0x6e] = 0;
  program[0x6f] = 0;
  program[0x70] = 0;
  program[0x71] = 0;
  program[0x72] = 0;
  program[0x73] = 0;
  program[0x74] = 0;
  program[0x75] = 0;
  program[0x76] = 0;
  program[0x77] = 0;
  program[0x78] = 0;
  program[0x79] = 0;
  program[0x7a] = 0;
  program[0x7b] = 0;
  program[0x7c] = 0;
  program[0x7d] = 0;
  program[0x7e] = 0;
  program[0x7f] = 0;
  program[0x80] = 0;
  program[0x81] = 0;
  program[0x82] = 0;
  program[0x83] = 0;
  program[0x84] = 0;
  program[0x85] = 0;
  program[0x86] = 0;
  program[0x87] = 0;
  program[0x88] = 0;
  program[0x89] = 0;
  program[0x8a] = 0;
  program[0x8b] = 0;
  program[0x8c] = 0;
  program[0x8d] = 0;
  program[0x8e] = 0;
  program[0x8f] = 0;
  program[0x90] = 0;
  program[0x91] = 0;
  program[0x92] = 0;
  program[0x93] = 0;
  program[0x94] = 0;
  program[0x95] = 0;
  program[0x96] = 0;
  program[0x97] = 0;
  program[0x98] = 0;
  program[0x99] = 0;
  program[0x9a] = 0;
  program[0x9b] = 0;
  program[0x9c] = 0;
  program[0x9d] = 0;
  program[0x9e] = 0;
  program[0x9f] = 0;
  program[0xa0] = 0;
  program[0xa1] = 0;
  program[0xa2] = 0;
  program[0xa3] = 0;
  program[0xa4] = 0;
  program[0xa5] = 0;
  program[0xa6] = 0;
  program[0xa7] = 0;
  program[0xa8] = 0;
  program[0xa9] = 0;
  program[0xaa] = 0;
  program[0xab] = 0;
  program[0xcc] = 0;
  program[0xce] = 0;
  program[0xcf] = 0;
  program[0xd1] = 0;
  program[0xd2] = 0;
  program[0xd3] = 0;
  program[0xd4] = 0;
  program[0xd6] = 0;
  program[0xd7] = 0;
  program[0xd8] = 0;
  program[0xd9] = 0;
  program[0xda] = 0;
  program[0xdd] = 0;
  DListNode__init(program + 0xdf);
  clearCount0 = 0x10;
  program[0xfa] = 0x7fffffff;
  program[0xfe] = 1;
  program[0xf6] = 0x7fffffff;
  program[0x10a] = 0xffffffff;
  program[0x11f] = 0;
  program[0xe5] = 0;
  program[0xe6] = 0;
  program[0xe7] = 0;
  program[0xe9] = 0;
  program[0xed] = 0;
  program[0xf0] = 0;
  program[0xf3] = 0;
  program[0xf5] = 0;
  program[0xf7] = 0xffffffff;
  program[0xf8] = 0;
  program[0xf9] = 0;
  program[0xfb] = 0xffffffff;
  program[0xfc] = 0;
  program[0x11d] = 0;
  program[0x11e] = 0;
  zeroCursor = program;
  do {
    zeroCursor[0xe] = 0;
    zeroCursor = zeroCursor + 1;
    clearCount0 = clearCount0 + -1;
  } while (clearCount0 != 0);
  clearCount1 = 0x20;
  zeroCursor = program;
  do {
    zeroCursor[0xac] = 0;
    zeroCursor = zeroCursor + 1;
    clearCount1 = clearCount1 + -1;
  } while (clearCount1 != 0);
  arenaA = *(undefined4 *)(program[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x6c);
  *allocation = arenaA;
  Object__setWord0(allocation + 1,program[2]);
  program[0xeb] = allocation + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  registerTableAlloc = (undefined4 *)Arena__alloc(arenaA,0x20c);
  registerTableAlloc[1] = 0x80;
  tableClearCount = 0x80;
  *registerTableAlloc = arenaA;
  registerTableAlloc[2] = 0x1000;
  tableData = registerTableAlloc + 1;
  do {
    tableData[2] = 0;
    tableData = tableData + 1;
    tableClearCount = tableClearCount + -1;
  } while (tableClearCount != 0);
  program[0xec] = registerTableAlloc + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  hwRegisterTableAlloc = (undefined4 *)Arena__alloc(arenaA,0x8c);
  hwRegisterTableAlloc[1] = 0x20;
  *hwRegisterTableAlloc = arenaA;
  hwRegisterTableAlloc[2] = 0x400;
  hwTableClearCount = 0x20;
  tableData = hwRegisterTableAlloc + 1;
  do {
    tableData[2] = 0;
    tableData = tableData + 1;
    hwTableClearCount = hwTableClearCount + -1;
  } while (hwTableClearCount != 0);
  program[0xef] = hwRegisterTableAlloc + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x14);
  *allocation = arenaA;
  allocation[1] = 2;
  allocation[4] = arenaA;
  allocation[2] = 0;
  vectorData = Arena__alloc(arenaA,8);
  allocation[3] = vectorData;
  program[0xf1] = allocation + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x14);
  *allocation = arenaA;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arenaA;
  vectorData = Arena__alloc(arenaA,8);
  allocation[3] = vectorData;
  clearCount4 = 4;
  program[0xf2] = allocation + 1;
  zeroCursor = program;
  do {
    zeroCursor[4] = 0;
    zeroCursor[8] = 0;
    zeroCursor = zeroCursor + 1;
    clearCount4 = clearCount4 + -1;
  } while (clearCount4 != 0);
  program[0xde] = 0;
  return;
}

/* Program__ctor_ee29c @ 0xee29c (1216 bytes) */
int Program__ctor_ee29c(program, compiler)
  undefined4 *program;
  undefined4 compiler;
{
  int clearCount4;
  int hwTableClearCount;
  int tableClearCount;
  int clearCount1;
  undefined4 *hwRegisterTableAlloc;
  undefined4 *tableData;
  undefined4 vectorData;
  undefined4 *allocation;
  undefined4 *zeroCursor;
  undefined4 *registerTableAlloc;
  undefined4 arenaA;
  int clearCount0;
  
  program[2] = compiler;
  *program = 0;
  program[0xc] = 0;
  program[0x1f] = 0xffffffff;
  program[0x20] = 0xffffffff;
  program[0x21] = 0;
  program[0x22] = 0;
  program[0x23] = 0;
  program[0x24] = 0;
  program[0x25] = 0;
  program[0x26] = 0;
  program[0x27] = 0;
  program[0x28] = 0;
  program[0x29] = 0;
  program[0x2a] = 0;
  program[0x2b] = 0;
  program[0x2c] = 0;
  program[0x2d] = 0;
  program[0x2e] = 0;
  program[0x2f] = 0;
  program[0x30] = 0;
  program[0x31] = 0;
  program[0x32] = 0;
  program[0x33] = 0;
  program[0x34] = 0;
  program[0x35] = 0;
  program[0x36] = 0;
  program[0x37] = 0;
  program[0x38] = 0;
  program[0x39] = 0;
  program[0x3a] = 0;
  program[0x3b] = 0;
  program[0x3c] = 0;
  program[0x3d] = 0;
  program[0x3e] = 0;
  program[0x3f] = 0;
  program[0x40] = 0;
  program[0x41] = 0;
  program[0x42] = 0;
  program[0x43] = 0;
  program[0x44] = 0;
  program[0x45] = 0;
  program[0x46] = 0;
  program[0x47] = 0;
  program[0x48] = 0;
  program[0x49] = 0;
  program[0x4a] = 0;
  program[0x4b] = 0;
  program[0x4c] = 0;
  program[0x4d] = 0;
  program[0x4e] = 0;
  program[0x4f] = 0;
  program[0x50] = 0;
  program[0x51] = 0;
  program[0x52] = 0;
  program[0x53] = 0;
  program[0x54] = 0;
  program[0x55] = 0;
  program[0x56] = 0;
  program[0x57] = 0;
  program[0x58] = 0;
  program[0x59] = 0;
  program[0x5a] = 0;
  program[0x5b] = 0;
  program[0x5c] = 0;
  program[0x5d] = 0;
  program[0x5e] = 0;
  program[0x5f] = 0;
  program[0x60] = 0;
  program[0x61] = 0;
  program[0x62] = 0;
  program[99] = 0;
  program[100] = 0;
  program[0x65] = 0;
  program[0x66] = 0;
  program[0x67] = 0;
  program[0x68] = 0;
  program[0x69] = 0;
  program[0x6a] = 0;
  program[0x6b] = 0;
  program[0x6c] = 0;
  program[0x6d] = 0;
  program[0x6e] = 0;
  program[0x6f] = 0;
  program[0x70] = 0;
  program[0x71] = 0;
  program[0x72] = 0;
  program[0x73] = 0;
  program[0x74] = 0;
  program[0x75] = 0;
  program[0x76] = 0;
  program[0x77] = 0;
  program[0x78] = 0;
  program[0x79] = 0;
  program[0x7a] = 0;
  program[0x7b] = 0;
  program[0x7c] = 0;
  program[0x7d] = 0;
  program[0x7e] = 0;
  program[0x7f] = 0;
  program[0x80] = 0;
  program[0x81] = 0;
  program[0x82] = 0;
  program[0x83] = 0;
  program[0x84] = 0;
  program[0x85] = 0;
  program[0x86] = 0;
  program[0x87] = 0;
  program[0x88] = 0;
  program[0x89] = 0;
  program[0x8a] = 0;
  program[0x8b] = 0;
  program[0x8c] = 0;
  program[0x8d] = 0;
  program[0x8e] = 0;
  program[0x8f] = 0;
  program[0x90] = 0;
  program[0x91] = 0;
  program[0x92] = 0;
  program[0x93] = 0;
  program[0x94] = 0;
  program[0x95] = 0;
  program[0x96] = 0;
  program[0x97] = 0;
  program[0x98] = 0;
  program[0x99] = 0;
  program[0x9a] = 0;
  program[0x9b] = 0;
  program[0x9c] = 0;
  program[0x9d] = 0;
  program[0x9e] = 0;
  program[0x9f] = 0;
  program[0xa0] = 0;
  program[0xa1] = 0;
  program[0xa2] = 0;
  program[0xa3] = 0;
  program[0xa4] = 0;
  program[0xa5] = 0;
  program[0xa6] = 0;
  program[0xa7] = 0;
  program[0xa8] = 0;
  program[0xa9] = 0;
  program[0xaa] = 0;
  program[0xab] = 0;
  program[0xcc] = 0;
  program[0xce] = 0;
  program[0xcf] = 0;
  program[0xd1] = 0;
  program[0xd2] = 0;
  program[0xd3] = 0;
  program[0xd4] = 0;
  program[0xd6] = 0;
  program[0xd7] = 0;
  program[0xd8] = 0;
  program[0xd9] = 0;
  program[0xda] = 0;
  program[0xdd] = 0;
  DListNode__init(program + 0xdf);
  clearCount0 = 0x10;
  program[0xfa] = 0x7fffffff;
  program[0xfe] = 1;
  program[0xf6] = 0x7fffffff;
  program[0x10a] = 0xffffffff;
  program[0x11f] = 0;
  program[0xe5] = 0;
  program[0xe6] = 0;
  program[0xe7] = 0;
  program[0xe9] = 0;
  program[0xed] = 0;
  program[0xf0] = 0;
  program[0xf3] = 0;
  program[0xf5] = 0;
  program[0xf7] = 0xffffffff;
  program[0xf8] = 0;
  program[0xf9] = 0;
  program[0xfb] = 0xffffffff;
  program[0xfc] = 0;
  program[0x11d] = 0;
  program[0x11e] = 0;
  zeroCursor = program;
  do {
    zeroCursor[0xe] = 0;
    zeroCursor = zeroCursor + 1;
    clearCount0 = clearCount0 + -1;
  } while (clearCount0 != 0);
  clearCount1 = 0x20;
  zeroCursor = program;
  do {
    zeroCursor[0xac] = 0;
    zeroCursor = zeroCursor + 1;
    clearCount1 = clearCount1 + -1;
  } while (clearCount1 != 0);
  arenaA = *(undefined4 *)(program[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x6c);
  *allocation = arenaA;
  Object__setWord0(allocation + 1,program[2]);
  program[0xeb] = allocation + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  registerTableAlloc = (undefined4 *)Arena__alloc(arenaA,0x20c);
  registerTableAlloc[1] = 0x80;
  tableClearCount = 0x80;
  *registerTableAlloc = arenaA;
  registerTableAlloc[2] = 0x1000;
  tableData = registerTableAlloc + 1;
  do {
    tableData[2] = 0;
    tableData = tableData + 1;
    tableClearCount = tableClearCount + -1;
  } while (tableClearCount != 0);
  program[0xec] = registerTableAlloc + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  hwRegisterTableAlloc = (undefined4 *)Arena__alloc(arenaA,0x8c);
  hwRegisterTableAlloc[1] = 0x20;
  *hwRegisterTableAlloc = arenaA;
  hwRegisterTableAlloc[2] = 0x400;
  hwTableClearCount = 0x20;
  tableData = hwRegisterTableAlloc + 1;
  do {
    tableData[2] = 0;
    tableData = tableData + 1;
    hwTableClearCount = hwTableClearCount + -1;
  } while (hwTableClearCount != 0);
  program[0xef] = hwRegisterTableAlloc + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x14);
  *allocation = arenaA;
  allocation[1] = 2;
  allocation[4] = arenaA;
  allocation[2] = 0;
  vectorData = Arena__alloc(arenaA,8);
  allocation[3] = vectorData;
  program[0xf1] = allocation + 1;
  arenaA = *(undefined4 *)(program[2] + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x14);
  *allocation = arenaA;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arenaA;
  vectorData = Arena__alloc(arenaA,8);
  allocation[3] = vectorData;
  clearCount4 = 4;
  program[0xf2] = allocation + 1;
  zeroCursor = program;
  do {
    zeroCursor[4] = 0;
    zeroCursor[8] = 0;
    zeroCursor = zeroCursor + 1;
    clearCount4 = clearCount4 + -1;
  } while (clearCount4 != 0);
  program[0xde] = 0;
  return;
}

/* Program__buildBlockArrayByKey @ 0xee7a0 (144 bytes) */
int Program__buildBlockArrayByKey(program)
  int program;
{
  uint bucketRemaining;
  int *bucketSlot;
  int writeIndex;
  int blockArray;
  int compiler2;
  int block;
  undefined4 *allocation;
  undefined4 vectorData;
  undefined4 arena;
  int listCount;
  int loopIndex2;
  int compiler;
  undefined4 *bucketTop;
  int *bucketSlotInit;
  int loopIndex;
  int nextBlock;
  uint bucketCount;
  undefined4 poppedBlock;
  uint *bucketVector;
  int bucket;
  int writeByteOffset;
  int bucketVectors [69];
  
  compiler = *(int *)(program + 8);
  if (-1 < *(int *)(*(int *)(compiler + 0x30c) + 0x4c)) {
    loopIndex2 = 0;
    bucketSlotInit = bucketVectors;
    do {
      arena = *(undefined4 *)(compiler + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,0x14);
      *allocation = arena;
      allocation[1] = 2;
      allocation[4] = arena;
      allocation[2] = 0;
      vectorData = Arena__alloc(arena,8);
      allocation[3] = vectorData;
      loopIndex2 = loopIndex2 + 1;
      *bucketSlotInit = (int)(allocation + 1);
      bucketSlotInit = bucketSlotInit + 1;
      compiler = *(int *)(program + 8);
    } while (loopIndex2 <= *(int *)(*(int *)(compiler + 0x30c) + 0x4c));
  }
  block = *(int *)(program + 900);
  nextBlock = *(int *)(block + 8);
  while (nextBlock != 0) {
    bucketVector = (uint *)bucketVectors[*(int *)(block + 0xb8)];
    bucketCount = bucketVector[1];
    if (bucketCount < *bucketVector) {
      _memset((void *)(bucketCount * 4 + bucketVector[2]),0,4);
      bucketSlot = (int *)(bucketCount * 4 + bucketVector[2]);
      bucketVector[1] = bucketCount + 1;
    }
    else {
      bucketSlot = (int *)Vector__elementRefGrow(bucketVector,bucketCount);
    }
    *bucketSlot = block;
    block = *(int *)(block + 8);
    nextBlock = *(int *)(block + 8);
  }
  listCount = DList__count(program + 0x37c);
  writeIndex = listCount + -1;
  arena = Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x374),listCount * 4 + 4);
  compiler2 = *(int *)(program + 8);
  *(undefined4 *)(program + 0x39c) = arena;
  if (-1 < *(int *)(*(int *)(compiler2 + 0x30c) + 0x4c)) {
    loopIndex = 0;
    do {
      writeByteOffset = writeIndex << 2;
      bucket = bucketVectors[loopIndex];
      bucketRemaining = *(uint *)(bucket + 4);
      if (bucketRemaining != 0) {
        do {
          blockArray = *(int *)(program + 0x39c);
          bucketTop = (undefined4 *)0x0;
          if (bucketRemaining - 1 < bucketRemaining) {
            bucketTop = (undefined4 *)((bucketRemaining - 1) * 4 + *(int *)(bucket + 8));
          }
          poppedBlock = *bucketTop;
          writeIndex = writeIndex + -1;
          Vector__removeAt(bucket,bucketRemaining - 1);
          *(undefined4 *)(writeByteOffset + blockArray) = poppedBlock;
          bucketRemaining = *(uint *)(bucket + 4);
          writeByteOffset = writeByteOffset + -4;
        } while (bucketRemaining != 0);
        compiler2 = *(int *)(program + 8);
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex <= *(int *)(*(int *)(compiler2 + 0x30c) + 0x4c));
  }
  return *(undefined4 *)(program + 0x39c);
}

/* Program__addInst @ 0xee9ac (120 bytes) */
int Program__addInst(program, inst)
  int program;
  undefined4 inst;
{
  undefined4 *elementRef;
  uint count;
  uint *vectorHeader;
  
  vectorHeader = *(uint **)(program + PROG_instructionVector);
  count = vectorHeader[1];
  if (count < *vectorHeader) {
    _memset(count * 4 + vectorHeader[2],0,4);
    elementRef = (undefined4 *)(count * 4 + vectorHeader[2]);
    vectorHeader[1] = count + 1;
  }
  else {
    elementRef = (undefined4 *)Vector__elementRefGrow(vectorHeader,count);
  }
  *elementRef = inst;
  return;
}

/* Program__pinInputRegisters @ 0xeea24 (556 bytes) */
int Program__pinInputRegisters(program)
  int program;
{
  int registerNumber;
  int inputVReg;
  int hwRegisterBias;
  int userInst;
  int *a0;
  int hwBaseRegister;
  undefined4 registerFile5;
  int loopCounter;
  uint loopIndex;
  undefined4 registerMap;
  
  if (((*(uint *)(program + 0x30) & 1) != 0) &&
     (a0 = *(int **)(*(int *)(program + 8) + 0x30c), hwBaseRegister = (**(code **)(*a0 + 0xe4))(a0),
     *(int *)(program + 0x3d4) != 0)) {
    if ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x2000) == 0) {
      hwRegisterBias = hwBaseRegister;
      if ((*(int *)(program + 0x3e4) != 0) && (hwRegisterBias = *(int *)(program + 0x3ec), hwRegisterBias <= hwBaseRegister)) {
        hwRegisterBias = hwBaseRegister + 1;
      }
      registerNumber = *(int *)(program + 0x3d8);
      *(int *)(program + 0x3e0) = hwRegisterBias - registerNumber;
      if (registerNumber < *(int *)(program + 0x3dc)) {
        do {
          registerMap = *(undefined4 *)(program + 0x3ac);
          registerFile5 = ((int (*)())Program__registerFileOfIlType)(program,5);
          inputVReg = VRegPool__find(registerMap,registerFile5,registerNumber,0);
          if (inputVReg != 0) {
            loopCounter = 0;
            for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(inputVReg + 0x18) + 4); loopIndex = loopIndex + 1) {
              userInst = *(int *)(loopCounter + *(int *)(*(int *)(inputVReg + 0x18) + 8));
              if ((*(uint *)(userInst + 0x14) & 1) != 0) {
                *(uint *)(userInst + 0x14) = *(uint *)(userInst + 0x14) | 0x10;
                ((int (*)())Program__addInst)(program,userInst);
              }
              loopCounter = loopCounter + 4;
            }
            *(int *)(inputVReg + 0x10) = registerNumber + *(int *)(program + 0x3e0);
            *(uint *)(inputVReg + 0x24) = *(uint *)(inputVReg + 0x24) | 2;
            Program__markHwRegUsed(program,registerNumber + *(int *)(program + 0x3e0));
            RegAlloc__clearBit430(program,registerNumber + *(int *)(program + 0x3e0));
          }
          registerNumber = registerNumber + 1;
        } while (registerNumber < *(int *)(program + 0x3dc));
      }
    }
    else {
      registerNumber = *(int *)(program + 0x3d8);
      if (registerNumber < *(int *)(program + 0x3dc)) {
        do {
          registerMap = *(undefined4 *)(program + 0x3ac);
          registerFile5 = ((int (*)())Program__registerFileOfIlType)(program,5);
          inputVReg = VRegPool__find(registerMap,registerFile5,registerNumber,0);
          if (inputVReg != 0) {
            loopCounter = 0;
            for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(inputVReg + 0x18) + 4); loopIndex = loopIndex + 1) {
              userInst = *(int *)(loopCounter + *(int *)(*(int *)(inputVReg + 0x18) + 8));
              if ((*(uint *)(userInst + 0x14) & 1) != 0) {
                *(uint *)(userInst + 0x14) = *(uint *)(userInst + 0x14) | 0x10;
                ((int (*)())Program__addInst)(program,userInst);
              }
              loopCounter = loopCounter + 4;
            }
          }
          registerNumber = registerNumber + 1;
        } while (registerNumber < *(int *)(program + 0x3dc));
      }
    }
  }
  return;
}

/* Program__emitDepthExportScale @ 0xeec50 (1072 bytes) */
int Program__emitDepthExportScale(program, unusedArg2)
  int program;
  undefined4 unusedArg2;
{
  undefined4 mulResultReg;
  undefined4 finalResultReg;
  undefined4 identitySelect;
  int exportInst;
  undefined4 parentBlock;
  undefined4 registerMap;
  undefined4 sourceSelectWord;
  undefined4 allComponentsSelect;
  int operandRecord4;
  int operandRecord3;
  int newInst;
  int operandRecord2;
  int newInst2;
  int operandRecord;
  int *nextInst;
  int inst;
  int madTempIndex;
  undefined4 madResultReg;
  int mulTempIndex;
  int finalTempIndex;
  int isInsertable;
  undefined4 *allocation;
  undefined4 arenaA;
  undefined4 sourceSelectWord2;
  undefined4 *newExport;
  int *candidate;
  double zeroFloat;
  
  if (*(int *)(program + 0x3e4) != 0) {
    candidate = *(int **)(*(int *)(program + 0x3a0) + 0x98);
    for (nextInst = (int *)candidate[2]; nextInst != (int *)0x0; nextInst = (int *)nextInst[2]) {
      if ((candidate[5] & 1U) != 0) {
        isInsertable = (**(code **)(*candidate + 0x4c))(candidate);
        if (isInsertable != 0) {
          if ((((*(int *)(program + 0x3e4) != 0) && (candidate[0x51] == *(int *)(program + 0x3f4))) &&
              (*(int *)(program + 1000) <= candidate[0x52])) &&
             (candidate[0x52] < *(int *)(program + 0x3ec))) {
            candidate[5] = candidate[5] | 0x10;
            ((int (*)())Program__addInst)(program,candidate);
            nextInst = (int *)candidate[2];
            goto LAB_000eed14;
          }
        }
        nextInst = (int *)candidate[2];
      }
LAB_000eed14:
      candidate = nextInst;
    }
    *(int *)(program + 0x3f0) = -*(int *)(program + 1000);
  }
  if ((*(int *)(program + 0x348) == 0) && (*(int *)(program + 0x350) == 0)) {
    exportInst = *(int *)(program + 0x34c);
    if (exportInst != 0) goto LAB_000eee08;
    arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
    allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
    *allocation = arenaA;
    newExport = allocation + 1;
    IRExport__ctor_108918(newExport,*(undefined4 *)(program + 8));
    *(undefined4 **)(program + 0x348) = newExport;
    operandRecord4 = IRInst__getOperandRecord(newExport,0);
    allComponentsSelect = DAT_001aa800;
    zeroFloat = (double)FLOAT_001aa0d4;
    *(undefined4 *)(operandRecord4 + 0xc) = 9;
    *(undefined4 *)(operandRecord4 + 8) = 0;
    allocation[0x28] = allComponentsSelect;
    ((void (*)())IRInst__makeLiteralVec4Float)(newExport,program,1,zeroFloat,zeroFloat,zeroFloat,zeroFloat);
    Program__appendInst(program,newExport,*(undefined4 *)(program + 0x3a8));
  }
  exportInst = *(int *)(program + 0x34c);
  if (exportInst == 0) {
    return;
  }
LAB_000eee08:
  if ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x4000) == 0) {
    return;
  }
  inst = IRInst__create(0x17,*(undefined4 *)(program + 8));
  IRInst__setOperandRef(inst,1,*(undefined4 *)(exportInst + 0xa4));
  operandRecord = IRInst__getOperandRecord(exportInst,1);
  zeroFloat = (double)FLOAT_001aa0d4;
  sourceSelectWord = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst,1);
  *(undefined4 *)(operandRecord + 0x10) = sourceSelectWord;
  ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,2,0.5000000596046448,zeroFloat,zeroFloat,zeroFloat);
  registerMap = *(undefined4 *)(program + 0x3ac);
  madTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(program + 8) + 0x3ac) = madTempIndex;
  madResultReg = VRegPool__findOrCreate(registerMap,0,madTempIndex,0);
  IRInst__setOperandRef(inst,0,madResultReg);
  allComponentsSelect = DAT_001aa800;
  *(undefined4 *)(inst + 0x120) = 1;
  *(undefined4 *)(inst + 0x9c) = allComponentsSelect;
  newInst2 = IRInst__create(0x13,*(undefined4 *)(program + 8));
  IRInst__setOperandRef(newInst2,1,*(undefined4 *)(exportInst + 0xa4));
  operandRecord2 = IRInst__getOperandRecord(exportInst,1);
  sourceSelectWord2 = *(undefined4 *)(operandRecord2 + 0x10);
  operandRecord2 = IRInst__getOperandRecord(newInst2,1);
  *(undefined4 *)(operandRecord2 + 0x10) = sourceSelectWord2;
  ((void (*)())IRInst__makeLiteralVec4Float)(newInst2,program,2,0.9999999403953552,zeroFloat,zeroFloat,zeroFloat);
  mulResultReg = *(undefined4 *)(program + 0x3ac);
  mulTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(program + 8) + 0x3ac) = mulTempIndex;
  mulResultReg = VRegPool__findOrCreate(mulResultReg,0,mulTempIndex,0);
  IRInst__setOperandRef(newInst2,0,mulResultReg);
  *(undefined4 *)(newInst2 + 0x120) = 1;
  *(undefined4 *)(newInst2 + 0x9c) = allComponentsSelect;
  newInst = IRInst__create(0x14,*(undefined4 *)(program + 8));
  IRInst__setOperandRef(newInst,1,madResultReg);
  identitySelect = DAT_001aa810;
  operandRecord3 = IRInst__getOperandRecord(newInst,1);
  *(undefined4 *)(operandRecord3 + 0x10) = identitySelect;
  ((void (*)())IRInst__makeLiteralVec4Float)(newInst,program,2,0.9999999403953552,zeroFloat,zeroFloat,zeroFloat);
  IRInst__setOperandRef(newInst,3,mulResultReg);
  operandRecord3 = IRInst__getOperandRecord(newInst,3);
  *(undefined4 *)(operandRecord3 + 0x10) = identitySelect;
  finalResultReg = *(undefined4 *)(program + 0x3ac);
  finalTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(program + 8) + 0x3ac) = finalTempIndex;
  finalResultReg = VRegPool__findOrCreate(finalResultReg,0,finalTempIndex,0);
  IRInst__setOperandRef(newInst,0,finalResultReg);
  *(undefined4 *)(newInst + 0x120) = 0;
  *(undefined4 *)(newInst + 0x9c) = allComponentsSelect;
  IRInst__setOperandRef(exportInst,1,finalResultReg);
  parentBlock = *(undefined4 *)(exportInst + 0x158);
  Block__insertInstBefore(parentBlock,exportInst,newInst);
  Block__insertInstBefore(parentBlock,newInst,newInst2);
  Block__insertInstBefore(parentBlock,newInst2,inst);
  return;
}

/* FUN_000eee4c @ 0xeee4c (492 bytes) */
int FUN_000eee4c(program)
  int program;
{
  int *subVReg;
  int resultVReg;
  int hwRegIndex;
  int destKind;
  int isPixelShaderHw;
  int *insertAfterInst;
  int *hwDescription;
  int newSourceIndex;
  int regInfo;
  undefined4 arenaA;
  int operandRecord2;
  int operandRecord;
  int block;
  int *nextInst;
  int nextBlock;
  int *followingInst;
  undefined4 *allocation;
  int iVar6;
  int *hwDescriptionObj;
  int supportsProjection;
  int *projection;
  undefined4 tempVReg;
  code *createSubReg;
  int resultVRegCopy;
  int *inst;
  
  block = *(int *)(program + 900);
  nextBlock = *(int *)(*(int *)(program + 900) + 8);
  do {
    if (nextBlock == 0) {
      return;
    }
    nextInst = (int *)(*(int **)(block + 0x98))[2];
    inst = *(int **)(block + 0x98);
    if (nextInst != (int *)0x0) {
      do {
        followingInst = nextInst;
        if ((inst[5] & 1U) != 0) {
          hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
          isPixelShaderHw = (**(code **)(*hwDescription + 0xcc))(hwDescription);
          if (isPixelShaderHw == 0) {
            if (*(int *)(inst[0x22] + 8) == 0x77) {
              tempVReg = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0x30,0,0);
              IRInst__setOperandRef(inst,0,tempVReg);
              inst[5] = inst[5] | 0x10;
              VReg__appendUser(tempVReg,inst);
              ((int (*)())Program__addInst)(program,inst);
            }
          }
          else if ((((inst[5] & 2U) != 0) && (isPixelShaderHw = RegKind__vectorWidthKind(inst[0x26]), isPixelShaderHw == 9))
                  && (isPixelShaderHw = VRegPool__find(*(undefined4 *)(program + 0x3ac),0x21,0,0), isPixelShaderHw != 0))
          {
            IRInst__appendSource(inst,isPixelShaderHw);
          }
          destKind = inst[0x26];
          if (destKind == 0x2a) {
            hwRegIndex = *(int *)(program + 1000);
            insertAfterInst = inst;
            if (hwRegIndex < *(int *)(program + 0x3ec)) {
              do {
                subVReg = (int *)VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),
                                             *(undefined4 *)(program + 0x3f4),hwRegIndex,0);
                arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
                allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
                *allocation = arenaA;
                projection = allocation + 1;
                IRProjection__ctor_109e28(projection,0x84,*(undefined4 *)(program + 8));
                allocation[0x4b] = hwRegIndex;
                createSubReg = *(code **)(*subVReg + 0x28);
                operandRecord = IRInst__getOperandRecord(inst,0);
                iVar6 = (*createSubReg)(subVReg,*(undefined4 *)(operandRecord + 0x10),program);
                hwDescriptionObj = *(int **)(*(int *)(program + 8) + 0x30c);
                supportsProjection = (**(code **)(*hwDescriptionObj + 0xd8))(hwDescriptionObj);
                if (supportsProjection != 0) {
                  *(int *)(iVar6 + 0x10) = hwRegIndex;
                  *(uint *)(iVar6 + 0x24) = *(uint *)(iVar6 + 0x24) | 2;
                  Program__markHwRegUsed(program,hwRegIndex);
                  RegAlloc__clearBit430(program,hwRegIndex);
                }
                resultVRegCopy = inst[0x23];
                IRInst__setOperandRef(projection,0,iVar6);
                hwRegIndex = hwRegIndex + 1;
                operandRecord2 = IRInst__getOperandRecord(inst,0);
                allocation[0x28] = *(undefined4 *)(operandRecord2 + 0x10);
                VReg__appendUser(iVar6,projection);
                IRInst__setOperandRef(projection,1,resultVRegCopy);
                VReg__addUse(resultVRegCopy,1,projection);
                IRInst__appendSource(projection,iVar6);
                VReg__addUse(iVar6,2,projection);
                Block__insertInstAfter(block,insertAfterInst,projection);
                regInfo = (**(code **)(*subVReg + 0x2c))(subVReg);
                *(undefined4 *)(regInfo + 0x144) = 1;
                insertAfterInst = projection;
              } while (hwRegIndex < *(int *)(program + 0x3ec));
              followingInst = (int *)allocation[3];
            }
            else {
LAB_000ef1c8:
              followingInst = (int *)inst[2];
            }
          }
          else {
            if ((inst[0x21] == 0) || ((destKind != 0x3b && (destKind != 0x2c)))) {
              if ((inst[0x20] == 0) ||
                 ((destKind = IRInst__writesAllLanes(inst), destKind == 0 ||
                  (destKind = (**(code **)(*inst + 0x4c))(inst), destKind != 0))))
              goto LAB_000ef1c8;
              resultVReg = inst[0x23];
              IRInst__appendSource(inst,resultVReg);
            }
            else {
              resultVReg = inst[0x23];
              newSourceIndex = inst[0x21] + 1;
              inst[0x21] = newSourceIndex;
              IRInst__setOperandRef(inst,newSourceIndex,resultVReg);
            }
            VReg__addUse(resultVReg,inst[0x21],inst);
            followingInst = (int *)inst[2];
          }
        }
        nextInst = (int *)followingInst[2];
        inst = followingInst;
      } while ((int *)followingInst[2] != (int *)0x0);
      nextBlock = *(int *)(block + 8);
    }
    block = nextBlock;
    nextBlock = *(int *)(nextBlock + 8);
  } while( true );
}

/* Program__splitExports @ 0xef204 (660 bytes) */
int Program__splitExports(program)
  int program;
{
  int *exportInst2;
  int *exportInst;
  int *nextInst2;
  int *laneSelectPtr;
  int isFullSelect;
  int isExport2;
  int cloneResult;
  int splitIntoScalarExportsEnabled;
  int splitRgbAlphaExportsEnabled;
  int operandRecord2;
  int operandRecord;
  bool notLastLane;
  int *nextInst;
  int *hwDescription;
  int hwOpcodeTable;
  int isExport;
  int cloneResult2;
  int loopCounter;
  uint destSelectWord;
  
  hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  hwOpcodeTable = (**(code **)(*hwDescription + 0x16c))(hwDescription);
  splitRgbAlphaExportsEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x31);
  if (splitRgbAlphaExportsEnabled == 0) {
    splitIntoScalarExportsEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x33);
    if (splitIntoScalarExportsEnabled != 0) {
      exportInst = *(int **)(*(int *)(program + 0x3a8) + 0x98);
      for (nextInst = (int *)exportInst[2]; nextInst != (int *)0x0; nextInst = (int *)nextInst[2]) {
        if ((exportInst[5] & 1U) != 0) {
          isExport = (**(code **)(*exportInst + 0x68))(exportInst);
          if ((((isExport != 0) && (exportInst[0x26] != 7)) &&
              (*(int *)(*(int *)(exportInst[0x22] + 8) * 0x38 + hwOpcodeTable + 0x34) == 0)) &&
             (isExport = IRInst__countWrittenComponents(exportInst), 1 < isExport)) {
            loopCounter = 0;
            laneSelectPtr = (int *)PTR_DAT_001e8b64;
            do {
              operandRecord2 = IRInst__getOperandRecord(exportInst,0);
              if (*(char *)(loopCounter + operandRecord2 + 0x10) != '\x01') {
                if (isExport < 2) {
                  exportInst[0x27] = *laneSelectPtr;
                }
                else {
                  cloneResult2 = IRInst__clone(exportInst,*(undefined4 *)(program + 8),0);
                  *(int *)(cloneResult2 + 0x9c) = *laneSelectPtr;
                  Block__insertInstBefore(*(undefined4 *)(program + 0x3a8),exportInst,cloneResult2);
                  ((int (*)())Program__addInst)(program,cloneResult2);
                }
                isExport = isExport + -1;
              }
              notLastLane = loopCounter != 3;
              laneSelectPtr = laneSelectPtr + 1;
              loopCounter = loopCounter + 1;
            } while (notLastLane);
          }
          nextInst = (int *)exportInst[2];
        }
        exportInst = nextInst;
      }
    }
  }
  else {
    exportInst2 = *(int **)(*(int *)(program + 0x3a8) + 0x98);
    for (nextInst2 = (int *)exportInst2[2]; nextInst2 != (int *)0x0; nextInst2 = (int *)nextInst2[2]) {
      if ((exportInst2[5] & 1U) != 0) {
        isExport2 = (**(code **)(*exportInst2 + 0x68))(exportInst2);
        if (((isExport2 != 0) && (isExport2 = exportInst2[0x26], isExport2 != 6)) &&
           ((isExport2 != 7 &&
            ((isExport2 != 0x2c && (*(int *)(*(int *)(exportInst2[0x22] + 8) * 0x38 + hwOpcodeTable + 0x34) == 0)))))
           ) {
          operandRecord = IRInst__getOperandRecord(exportInst2,0);
          destSelectWord = *(uint *)(operandRecord + 0x10);
          isFullSelect = SelectWord__hasNonzeroLaneBytes(destSelectWord);
          if (isFullSelect == 0) {
            cloneResult = IRInst__clone(exportInst2,*(undefined4 *)(program + 8),0);
            *(uint *)(cloneResult + 0x9c) = destSelectWord & 0xffffff00 | 1;
            exportInst2[0x27] = 0x1010100;
            Block__insertInstBefore(*(undefined4 *)(program + 0x3a8),exportInst2,cloneResult);
            ((int (*)())Program__addInst)(program,cloneResult);
            nextInst2 = (int *)exportInst2[2];
            goto LAB_000ef344;
          }
        }
        nextInst2 = (int *)exportInst2[2];
      }
LAB_000ef344:
      exportInst2 = nextInst2;
    }
  }
  return;
}

/* Program__initAndTranslate @ 0xef498 (860 bytes) */
int Program__initAndTranslate(program, ilReader)
  int program;
  undefined4 ilReader;
{
  int programInstVector;
  int blockNextLink;
  int compiler;
  int *blockCursor;
  int *bitsetData;
  int hwCountSlot13c;
  int bitsetWordsLeft;
  int hwCountSlot140;
  int tableSize;
  int bitsetWords;
  int bitsetBytes;
  int hwCountSlot138;
  undefined4 shaderKind;
  undefined4 registerTable;
  uint loopIndex;
  int *wordCursor;
  int shaderKind2;
  int loopCounter;
  undefined4 *allocation;
  undefined4 *tableAlloc;
  char *r4AfterCall;
  undefined4 r4AfterCall2;
  char *blockLabel;
  int programInst;
  int *hwDescription;
  undefined4 arenaA;
  uint wordsLeft;
  uint bitsetWordCount;
  
  compiler = *(int *)(program + 8);
  hwDescription = *(int **)(compiler + 0x30c);
  hwCountSlot138 = (**(code **)(*hwDescription + 0x138))(hwDescription,compiler);
  hwCountSlot140 = (**(code **)(*hwDescription + 0x140))(hwDescription,compiler);
  compiler = (**(code **)(*hwDescription + 0x13c))(hwDescription,compiler);
  compiler = hwCountSlot138 + hwCountSlot140 + compiler;
  arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  bitsetWordCount = compiler + 0x1fU >> 5;
  bitsetBytes = bitsetWordCount * 4 + 0xc;
  allocation = (undefined4 *)Arena__alloc(arenaA,bitsetBytes);
  bitsetData = allocation + 1;
  *allocation = arenaA;
  allocation[1] = bitsetWordCount;
  allocation[2] = compiler;
  if (bitsetWordCount != 0) {
    wordCursor = bitsetData;
    wordsLeft = bitsetWordCount;
    if (bitsetWordCount == 0) {
      wordsLeft = 1;
    }
    do {
      wordCursor[2] = 0;
      wordCursor = wordCursor + 1;
      wordsLeft = wordsLeft - 1;
    } while (wordsLeft != 0);
  }
  *(int **)(program + 0x42c) = bitsetData;
  bitsetWordsLeft = *bitsetData;
  if (bitsetWordsLeft != 0) {
    if (bitsetWordsLeft == 0) {
      bitsetWordsLeft = 1;
    }
    do {
      bitsetData[2] = -1;
      bitsetData = bitsetData + 1;
      bitsetWordsLeft = bitsetWordsLeft + -1;
    } while (bitsetWordsLeft != 0);
  }
  arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,bitsetBytes);
  bitsetData = allocation + 1;
  *allocation = arenaA;
  allocation[1] = bitsetWordCount;
  allocation[2] = compiler;
  if (bitsetWordCount != 0) {
    wordCursor = bitsetData;
    if (bitsetWordCount == 0) {
      bitsetWordCount = 1;
    }
    do {
      wordCursor[2] = 0;
      wordCursor = wordCursor + 1;
      bitsetWordCount = bitsetWordCount - 1;
    } while (bitsetWordCount != 0);
  }
  *(int **)(program + 0x430) = bitsetData;
  bitsetWords = *bitsetData;
  if (bitsetWords != 0) {
    if (bitsetWords == 0) {
      bitsetWords = 1;
    }
    do {
      bitsetData[2] = -1;
      bitsetData = bitsetData + 1;
      bitsetWords = bitsetWords + -1;
    } while (bitsetWords != 0);
  }
  arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  tableAlloc = (undefined4 *)Arena__alloc(arenaA,0x8c);
  tableAlloc[1] = 0x20;
  tableSize = 0x20;
  *tableAlloc = arenaA;
  tableAlloc[2] = 0x400;
  allocation = tableAlloc + 1;
  do {
    allocation[2] = 0;
    allocation = allocation + 1;
    tableSize = tableSize + -1;
  } while (tableSize != 0);
  *(undefined4 **)(program + 0x434) = tableAlloc + 1;
  *(undefined4 *)(program + 0x43c) = 0;
  hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  hwCountSlot138 = (**(code **)(*hwDescription + 0x138))(hwDescription,*(int *)(program + 8));
  *(int *)(program + 0x448) = hwCountSlot138;
  *(int *)(program + 0x440) = hwCountSlot138;
  hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  hwCountSlot140 = (**(code **)(*hwDescription + 0x140))(hwDescription,*(int *)(program + 8));
  hwCountSlot138 = hwCountSlot138 + hwCountSlot140;
  *(int *)(program + 0x44c) = hwCountSlot138;
  *(int *)(program + 0x444) = hwCountSlot138;
  hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  hwCountSlot13c = (**(code **)(*hwDescription + 0x13c))(hwDescription,*(int *)(program + 8));
  *(int *)(program + 0x450) = hwCountSlot138 + hwCountSlot13c;
  registerTable = Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x374),
                       *(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x50) * 0xc);
  *(undefined4 *)(program + 0x78) = registerTable;
  arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x134);
  *allocation = arenaA;
  allocation = allocation + 1;
  EntryBlock__ctor_eab70(allocation,*(undefined4 *)(program + 8));
  *(undefined4 **)(program + 0x3a0) = allocation;
  ((int (*)())Program__prependBlock)(program,allocation);
  arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x130);
  *allocation = arenaA;
  allocation = allocation + 1;
  ExitBlock__ctor_eaae8(allocation,*(undefined4 *)(program + 8));
  *(undefined4 **)(program + 0x3a8) = allocation;
  ((int (*)())Program__appendBlock)(program,allocation);
  VRegInfo__new_127994(*(undefined4 *)(program + 0x3ac),*(uint *)(program + 0x30) & 1);
  hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  (**(code **)(*hwDescription + 0x10))(hwDescription,*(int *)(program + 8));
  Program__translateILStream(program,ilReader);
  if ((*(uint *)(program + 0x30) & 1) == 0) {
    if ((*(uint *)(program + 0x30) & 0x2000) == 0) {
      shaderKind = 2;
      shaderKind2 = 2;
    }
    else {
      shaderKind = 1;
      shaderKind2 = 1;
    }
  }
  else {
    shaderKind = 0;
    shaderKind2 = 0;
  }
  hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  (**(code **)(*hwDescription + 0x14))(hwDescription,shaderKind,*(int *)(program + 8));
  if (shaderKind2 == 1) {
    ((int (*)())Program__emitDepthExportScale)(program,r4AfterCall2);
  }
  else if ((shaderKind2 == 2) || (shaderKind2 == 0)) {
    hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
    (**(code **)(*hwDescription + 0xac))(hwDescription,*(undefined4 *)(program + 0x358),program,*(int *)(program + 8));
  }
  ((int (*)())Program__splitExports)(program);
  Program__predicatePendingIfs(program);
  ((int (*)())FUN_000eee4c)(program);
  ((int (*)())Program__pinInputRegisters)(program);
  Liveness__allocLiveTable(program);
  blockLabel = "non_local_set";
  blockCursor = *(int **)(program + 900);
  blockNextLink = blockCursor[2];
  while (blockNextLink != 0) {
    (**(code **)(*blockCursor + 0x48))(blockCursor,blockLabel);
    blockCursor = (int *)blockCursor[2];
    blockLabel = r4AfterCall;
    blockNextLink = blockCursor[2];
  }
  programInstVector = *(int *)(program + 0x3c4);
  loopCounter = 0;
  for (loopIndex = 1; loopIndex <= *(uint *)(programInstVector + 4); loopIndex = loopIndex + 1) {
    programInst = *(int *)(*(int *)(programInstVector + 8) + loopCounter);
    if ((*(uint *)(programInst + 0x14) & 1) != 0) {
      IRInst__getOperandRecord(programInst,0);
      programInstVector = *(int *)(program + 0x3c4);
    }
    loopCounter = loopCounter + 4;
  }
  return 1;
}

/* Program__appendToVector3c8 @ 0xef8f8 (120 bytes) */
int Program__appendToVector3c8(program, value)
  int program;
  undefined4 value;
{
  undefined4 *vectorSlot;
  uint vectorSize;
  uint *instVector3c8;
  
  instVector3c8 = *(uint **)(program + 0x3c8);
  vectorSize = instVector3c8[1];
  if (vectorSize < *instVector3c8) {
    _memset(vectorSize * 4 + instVector3c8[2],0,4);
    vectorSlot = (undefined4 *)(vectorSize * 4 + instVector3c8[2]);
    instVector3c8[1] = vectorSize + 1;
  }
  else {
    vectorSlot = (undefined4 *)Vector__elementRefGrow(instVector3c8,vectorSize);
  }
  *vectorSlot = value;
  return;
}

/* Program__removeInst @ 0xef970 (220 bytes) */
int Program__removeInst(program, inst)
  int program;
  int inst;
{
  uint count;
  int *elementRef;
  uint index;
  uint nextIndex;
  uint *vectorHeader;
  uint *vectorHeaderAlias;
  
  vectorHeader = *(uint **)(program + PROG_instructionVector);
  count = vectorHeader[1];
  if (count != 0) {
    index = 0;
    do {
      if (index < *vectorHeader) {
        vectorHeaderAlias = vectorHeader;
        if (count <= index) {
          _memset(count * 4 + vectorHeader[2],0,(index - count) * 4 + 4);
          vectorHeader[1] = index + 1;
          vectorHeaderAlias = *(uint **)(program + PROG_instructionVector);
        }
        elementRef = (int *)(index * 4 + vectorHeader[2]);
        vectorHeader = vectorHeaderAlias;
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vectorHeader,index);
        vectorHeader = *(uint **)(program + PROG_instructionVector);
      }
      nextIndex = index + 1;
      if (*elementRef == inst) {
        Vector__removeAt(vectorHeader,index);
        vectorHeader = *(uint **)(program + PROG_instructionVector);
      }
      count = vectorHeader[1];
      index = nextIndex;
    } while (nextIndex < count);
  }
  return;
}

/* Program__orderBlocksByDfs @ 0xefa4c (164 bytes) */
int Program__orderBlocksByDfs(program)
  int program;
{
  int block;
  int postOrderRemaining;
  int successorByteOffset;
  int hasSuccessors;
  undefined4 *postOrderSlot;
  undefined4 *walkTopEntry;
  int *dfsStackSlot;
  uint postOrderCount;
  undefined4 postOrderBlock;
  undefined4 finishedBlock;
  undefined4 entryBlock;
  undefined4 vectorData;
  uint loopIndex;
  bool allSuccessorsVisited;
  int *dfsStackTop;
  undefined4 *allocation;
  undefined4 *vectorAlloc;
  undefined4 *entryPushSlot;
  int blockCursor;
  uint *postOrder;
  int successor;
  uint *dfsStack;
  undefined4 arenaB;
  uint dfsStackCount;
  uint dfsStackCountPush;
  int previousBlock;
  
  arenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  allocation = (undefined4 *)Arena__alloc(arenaB,0x14);
  dfsStack = allocation + 1;
  *allocation = arenaB;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arenaB;
  vectorData = Arena__alloc(arenaB,8);
  allocation[3] = vectorData;
  arenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaB,0x14);
  postOrder = vectorAlloc + 1;
  *vectorAlloc = arenaB;
  vectorAlloc[1] = 2;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaB;
  vectorData = Arena__alloc(arenaB,8);
  vectorAlloc[3] = vectorData;
  previousBlock = *(int *)(program + 900);
  for (blockCursor = *(int *)(*(int *)(program + 900) + 8); blockCursor != 0; blockCursor = *(int *)(blockCursor + 8)) {
    *(undefined4 *)(previousBlock + 0x118) = 0;
    previousBlock = blockCursor;
  }
  dfsStackCount = allocation[2];
  entryBlock = *(undefined4 *)(program + 0x3a0);
  if (dfsStackCount < *dfsStack) {
    _memset((void *)(dfsStackCount * 4 + allocation[3]),0,4);
    entryPushSlot = (undefined4 *)(dfsStackCount * 4 + allocation[3]);
    allocation[2] = dfsStackCount + 1;
  }
  else {
    entryPushSlot = (undefined4 *)Vector__elementRefGrow(dfsStack,dfsStackCount);
  }
  *entryPushSlot = entryBlock;
  *(undefined4 *)(*(int *)(program + 0x3a0) + 0x118) = 1;
code_r0x000efd60:
  dfsStackCount = allocation[2];
  if (dfsStackCount == 0) {
    DList__initSentinel(program + 0x37c);
    postOrderRemaining = vectorAlloc[2];
    while (postOrderRemaining != 0) {
      allocation = (undefined4 *)0x0;
      if (postOrderRemaining - 1U < (uint)vectorAlloc[2]) {
        allocation = (undefined4 *)((postOrderRemaining - 1U) * 4 + vectorAlloc[3]);
      }
      finishedBlock = *allocation;
      Vector__removeAt(postOrder,vectorAlloc[2] - 1);
      DList__pushBack(program + 0x37c,finishedBlock);
      ((int (*)())Program__freeWorkArrays)(program);
      postOrderRemaining = vectorAlloc[2];
    }
    return;
  }
  dfsStackTop = (int *)0x0;
  if (dfsStackCount - 1 < dfsStackCount) {
    dfsStackTop = (int *)((dfsStackCount - 1) * 4 + allocation[3]);
  }
  block = *dfsStackTop;
  Vector__removeAt(dfsStack,dfsStackCount - 1);
  dfsStackCount = allocation[2];
  if (dfsStackCount < *dfsStack) {
    _memset((void *)(dfsStackCount * 4 + allocation[3]),0,4);
    dfsStackSlot = (int *)(dfsStackCount * 4 + allocation[3]);
    allocation[2] = dfsStackCount + 1;
  }
  else {
    dfsStackSlot = (int *)Vector__elementRefGrow(dfsStack,dfsStackCount);
  }
  *dfsStackSlot = block;
  hasSuccessors = Block__hasSuccessors(block);
  if (hasSuccessors != 0) goto code_r0x000efc2c;
  goto code_r0x000efce4;
code_r0x000efc2c:
  allSuccessorsVisited = true;
  successorByteOffset = 0;
  for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(block + 0xd0) + 4); loopIndex = loopIndex + 1) {
    successor = *(int *)(successorByteOffset + *(int *)(*(int *)(block + 0xd0) + 8));
    if ((successor != 0) && (*(int *)(successor + 0x118) == 0)) {
      dfsStackCountPush = allocation[2];
      if (dfsStackCountPush < *dfsStack) {
        _memset((void *)(dfsStackCountPush * 4 + allocation[3]),0,4);
        dfsStackSlot = (int *)(dfsStackCountPush * 4 + allocation[3]);
        allocation[2] = dfsStackCountPush + 1;
      }
      else {
        dfsStackSlot = (int *)Vector__elementRefGrow(dfsStack,dfsStackCountPush);
      }
      *dfsStackSlot = successor;
      allSuccessorsVisited = false;
      *(undefined4 *)(successor + 0x118) = 1;
    }
    successorByteOffset = successorByteOffset + 4;
  }
  if (allSuccessorsVisited) {
code_r0x000efce4:
    dfsStackCount = allocation[2];
    walkTopEntry = (undefined4 *)0x0;
    if (dfsStackCount - 1 < dfsStackCount) {
      walkTopEntry = (undefined4 *)((dfsStackCount - 1) * 4 + allocation[3]);
    }
    postOrderBlock = *walkTopEntry;
    Vector__removeAt(dfsStack,dfsStackCount - 1);
    postOrderCount = vectorAlloc[2];
    if (postOrderCount < *postOrder) {
      _memset((void *)(postOrderCount * 4 + vectorAlloc[3]),0,4);
      postOrderSlot = (undefined4 *)(postOrderCount * 4 + vectorAlloc[3]);
      vectorAlloc[2] = postOrderCount + 1;
    }
    else {
      postOrderSlot = (undefined4 *)Vector__elementRefGrow(postOrder,postOrderCount);
    }
    *postOrderSlot = postOrderBlock;
  }
  goto code_r0x000efd60;
}

/* Program__insertExitMarkerAndFlagBlocks @ 0xefde4 (536 bytes) */
int Program__insertExitMarkerAndFlagBlocks(program, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int program;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  int *queueFront;
  int queuedBlock;
  int isSpecialInst;
  int blockCursor;
  int loopCounter;
  undefined4 *allocation;
  undefined4 vectorData;
  undefined4 arena;
  uint loopIndex;
  int *nextInst;
  undefined4 *markerObject;
  undefined4 *queueSlot;
  int *inst;
  int markerInstRef;
  uint blockFlags;
  int markerBlock;
  uint *queue;
  undefined4 childBlock;
  uint queueCount;
  
  if (((*(uint *)(program + 0x30) & 1) == 0) && ((*(uint *)(program + 0x30) & 0x2000) != 0)) {
    arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
    markerObject = (undefined4 *)Arena__alloc(arena,0x168);
    *markerObject = arena;
    markerObject = markerObject + 1;
    IRInst__ctor_10502c(markerObject,0x95,*(undefined4 *)(program + 8));
  }
  else {
    arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
    markerObject = (undefined4 *)Arena__alloc(arena,0x168);
    *markerObject = arena;
    markerObject = markerObject + 1;
    IRInst__ctor_10502c(markerObject,0x96,*(undefined4 *)(program + 8));
  }
  *(undefined4 **)(program + 0x33c) = markerObject;
  markerInstRef = *(int *)(program + 0x33c);
  *(undefined4 *)(markerInstRef + 0x98) = 0x2d;
  *(undefined4 *)(markerInstRef + 0x94) = 0;
  *(undefined4 *)(*(int *)(program + 0x33c) + 300) = 0;
  blockCursor = *(int *)(program + 0x3a8);
  *(uint *)(blockCursor + 0xc) = *(uint *)(blockCursor + 0xc) | 8;
  do {
    markerBlock = blockCursor;
    blockCursor = *(int *)(markerBlock + 0xf0);
    if (blockCursor == 0) goto LAB_000eff14;
    *(uint *)(markerBlock + 0xc) = *(uint *)(markerBlock + 0xc) | 8;
    blockFlags = *(uint *)(blockCursor + 0xc);
  } while ((((blockFlags & 2) == 0) && ((blockFlags & 1) == 0)) && ((blockFlags & 4) == 0));
  if (*(int *)(*(int *)(markerBlock + 0xd4) + 4) == 1) {
    *(uint *)(blockCursor + 0xc) = blockFlags | 8;
    markerBlock = blockCursor;
  }
LAB_000eff14:
  inst = *(int **)(markerBlock + 0x98);
  nextInst = (int *)(*(int **)(markerBlock + 0x98))[2];
  do {
    if (nextInst == (int *)0x0) {
LAB_000eff98:
      *(uint *)(markerBlock + 0xc) = *(uint *)(markerBlock + 0xc) | 8;
      if (*(int *)(program + 0x344) != 0) {
        (**(code **)(**(int **)(program + 0x33c) + 0x94))
                  (*(int **)(program + 0x33c),*(int *)(program + 0x344),*(undefined4 *)(program + 8)
                  );
      }
      arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,0x14);
      queue = allocation + 1;
      *allocation = arena;
      allocation[1] = 2;
      allocation[4] = arena;
      allocation[2] = 0;
      vectorData = Arena__alloc(arena,8);
      loopCounter = 0;
      allocation[3] = vectorData;
      for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(markerBlock + 0xf4) + 4); loopIndex = loopIndex + 1) {
        childBlock = *(undefined4 *)(*(int *)(*(int *)(markerBlock + 0xf4) + 8) + loopCounter);
        queueCount = allocation[2];
        if (queueCount < *queue) {
          _memset((void *)(queueCount * 4 + allocation[3]),0,4);
          queueSlot = (undefined4 *)(queueCount * 4 + allocation[3]);
          allocation[2] = queueCount + 1;
        }
        else {
          queueSlot = (undefined4 *)Vector__elementRefGrow(queue,queueCount);
        }
        loopCounter = loopCounter + 4;
        *queueSlot = childBlock;
      }
      while (allocation[2] != 0) {
        if (*queue == 0) {
          queueFront = (int *)Vector__elementRefGrow(queue,0);
        }
        else {
          queueFront = (int *)allocation[3];
        }
        queuedBlock = *queueFront;
        Vector__removeAt(queue,0);
        loopCounter = 0;
        *(uint *)(queuedBlock + 0xc) = *(uint *)(queuedBlock + 0xc) | 8;
        for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(queuedBlock + 0xf4) + 4); loopIndex = loopIndex + 1) {
          childBlock = *(undefined4 *)(*(int *)(*(int *)(queuedBlock + 0xf4) + 8) + loopCounter);
          queueCount = allocation[2];
          if (queueCount < *queue) {
            _memset((void *)(queueCount * 4 + allocation[3]),0,4);
            queueSlot = (undefined4 *)(queueCount * 4 + allocation[3]);
            allocation[2] = queueCount + 1;
          }
          else {
            queueSlot = (undefined4 *)Vector__elementRefGrow(queue,queueCount);
          }
          loopCounter = loopCounter + 4;
          *queueSlot = childBlock;
        }
      }
      return;
    }
    if ((inst[5] & 1U) != 0) {
      isSpecialInst = (**(code **)(*inst + 0x7c))(inst);
      if ((isSpecialInst == 0) && (isSpecialInst = (**(code **)(*inst + 0x34))(inst), isSpecialInst == 0)) {
        Block__insertInstBefore(markerBlock,inst,*(undefined4 *)(program + 0x33c));
        goto LAB_000eff98;
      }
      nextInst = (int *)inst[2];
    }
    inst = nextInst;
    nextInst = (int *)nextInst[2];
  } while( true );
}

/* FUN_000f019c @ 0xf019c (292 bytes) */
int FUN_000f019c(program)
  int program;
{
  uint chainLength;
  uint chainAppendIndex;
  undefined4 vectorData;
  int sourceDef;
  int *operandVReg;
  uint loopIndex;
  int chainElementKind;
  uint excessCount;
  uint instCount;
  undefined4 *allocation;
  int removedElementKind;
  undefined4 *keepSlot;
  int *vectorSlot;
  int outputInst;
  uint *instVector;
  uint *instVectorRefreshed;
  int *keepInst;
  undefined4 arenaB;
  
  if (((*(uint *)(program + 0x30) & 0x4000) != 0) && ((*(uint *)(program + 0x30) & 0x80000) == 0)) {
    instCount = (*(uint **)(program + 0x3c4))[1];
    if (instCount == 0) {
      outputInst = 0;
    }
    else {
      loopIndex = 0;
      outputInst = 0;
      instVector = *(uint **)(program + 0x3c4);
      do {
        if (loopIndex < *instVector) {
          instVectorRefreshed = instVector;
          if (instCount <= loopIndex) {
            _memset(instCount * 4 + instVector[2],0,(loopIndex - instCount) * 4 + 4);
            instVector[1] = loopIndex + 1;
            instVectorRefreshed = *(uint **)(program + 0x3c4);
          }
          vectorSlot = (int *)(loopIndex * 4 + instVector[2]);
        }
        else {
          vectorSlot = (int *)Vector__elementRefGrow(instVector,loopIndex);
          instVectorRefreshed = *(uint **)(program + 0x3c4);
        }
        loopIndex = loopIndex + 1;
        if (*(int *)(*vectorSlot + 0x98) == 0x2c) {
          outputInst = *vectorSlot;
        }
        instCount = instVectorRefreshed[1];
        instVector = instVectorRefreshed;
      } while (loopIndex < instCount);
    }
    arenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
    allocation = (undefined4 *)Arena__alloc(arenaB,0x14);
    *allocation = arenaB;
    allocation[1] = 2;
    allocation[2] = 0;
    allocation[4] = arenaB;
    vectorData = Arena__alloc(arenaB,8);
    allocation[3] = vectorData;
    sourceDef = IRInst__getOperandSource(outputInst,1);
    while (*(int *)(sourceDef + 0x84) != 0) {
      chainElementKind = *(int *)(*(int *)(sourceDef + 0x88) + 8);
      if ((chainElementKind == 0xf7) || (chainElementKind == 0x107)) {
        chainAppendIndex = allocation[2];
        if (chainAppendIndex < (uint)allocation[1]) {
          _memset(chainAppendIndex * 4 + allocation[3],0,4);
          allocation[2] = chainAppendIndex + 1;
          vectorSlot = (int *)(chainAppendIndex * 4 + allocation[3]);
        }
        else {
          vectorSlot = (int *)Vector__elementRefGrow(allocation + 1,chainAppendIndex);
        }
        *vectorSlot = sourceDef;
        sourceDef = IRInst__getOperandSource(sourceDef,1);
      }
      else if (chainElementKind == 0xf9) {
        sourceDef = IRInst__getOperandSource(sourceDef,2);
      }
      else {
        if (chainElementKind == 0x8e) {
          return;
        }
        sourceDef = IRInst__getOperandSource(sourceDef,1);
      }
    }
    chainLength = allocation[2];
    if (*(int *)(program + 0x3f8) < (int)chainLength) {
      excessCount = chainLength - *(int *)(program + 0x3f8);
      keepSlot = (undefined4 *)0x0;
      if (excessCount < chainLength) {
        keepSlot = (undefined4 *)(excessCount * 4 + allocation[3]);
      }
      keepInst = (int *)*keepSlot;
      operandVReg = (int *)IRInst__getOperandSource(outputInst,1);
      while (keepInst != operandVReg) {
        removedElementKind = *(int *)(operandVReg[0x22] + 8);
        if (((removedElementKind == 0xf7) || (removedElementKind == 0x107)) || (removedElementKind != 0xf9)) {
          (**(code **)(*operandVReg + 0xc))(operandVReg,0,*(undefined4 *)(program + 8));
          operandVReg = (int *)IRInst__getOperandSource(operandVReg,1);
        }
        else {
          (**(code **)(*operandVReg + 0xc))(operandVReg,0,*(undefined4 *)(program + 8));
          operandVReg = (int *)IRInst__getOperandSource(operandVReg,2);
        }
      }
      IRInst__setOperandSource(outputInst,1,keepInst,0,*(undefined4 *)(program + 8));
      IRInst__setOperandSourceRaw(outputInst,2,keepInst,*(undefined4 *)(program + 8));
      return;
    }
  }
  return;
}

/* IRInst__tryFoldOutputScale @ 0xf04d4 (724 bytes) */
int IRInst__tryFoldOutputScale(program, inst)
  int program;
  int *inst;
{
  int *hwDescription;
  int canApplyScale;
  int isOutputScale;
  int scaleExponent;
  int sourceIndex;
  int loopCounter;
  int operandRecord2;
  int operandRecord;
  int *operandVReg;
  bool notLastLane;
  bool allLanesFoldable;
  int isCopyLike;
  int sourceCount;
  int *selectBytePtr;
  float scaleValue;
  uint scaleLane;
  uint sourceLane;
  
  isCopyLike = (**(code **)(*inst + 0x68))(inst,inst);
  if ((isCopyLike == 0) && (isCopyLike = (**(code **)(*inst + 100))(inst), isCopyLike != 0)) {
    for (sourceIndex = 1; sourceCount = (**(code **)(*inst + 0x14))(inst), sourceIndex <= sourceCount;
        sourceIndex = sourceIndex + 1) {
      if ((((inst[sourceIndex * 6 + 0x28] & 1U) != 0) || ((inst[sourceIndex * 6 + 0x28] & 2U) != 0)) ||
         (sourceCount = IRInst__isSourceSelectIdentity(inst,sourceIndex), sourceCount == 0)) goto LAB_000f0628;
    }
    if ((inst[0x48] == 0) && (inst[0x49] == 0)) {
      if (((inst[0x20] != 0) &&
          ((sourceIndex = RegKind__flagBit0(inst[0x26]), sourceIndex != 0 && ((inst[5] & 2U) == 0)))) &&
         (sourceIndex = (**(code **)(*inst + 0x50))(inst), sourceIndex == 0)) {
        loopCounter = 4;
        selectBytePtr = inst;
        do {
          if ((uint)(*(byte *)(selectBytePtr + 0x27) - 2) < 2) goto LAB_000f0628;
          selectBytePtr = (int *)((int)selectBytePtr + 1);
          loopCounter = loopCounter + -1;
        } while (loopCounter != 0);
      }
      IRInst__getOperandRecord(inst,0);
      IRInst__operandKindClass(inst,0);
    }
  }
LAB_000f0628:
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  loopCounter = 0;
  scaleLane = 0xffffffff;
  allLanesFoldable = true;
  scaleValue = 0.0;
  (**(code **)(*operandVReg + 0x48))(operandVReg);
  do {
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    if (*(char *)(loopCounter + operandRecord2 + 0x10) != '\x01') {
      isOutputScale = IRInst__getOperandRecord(inst,1);
      sourceLane = (uint)*(byte *)(loopCounter + isOutputScale + 0x10);
      if ((((int)*(char *)(operandVReg + 0x57) >> (sourceLane & 0x3f) & 1U) == 0) ||
         (isOutputScale = ((undefined4 (*)())isOutputScaleValue)((double)GH_U2F((unsigned int)(operandVReg[sourceLane * 6 + 8]))), isOutputScale == 0)) {
        allLanesFoldable = false;
      }
      else if (scaleLane == 0xffffffff) {
        scaleValue = GH_U2F((unsigned int)(operandVReg[sourceLane * 6 + 8]));
        scaleLane = sourceLane;
      }
      else if (scaleValue != GH_U2F((unsigned int)(operandVReg[sourceLane * 6 + 8]))) {
        return 0;
      }
    }
    notLastLane = loopCounter != 3;
    loopCounter = loopCounter + 1;
  } while (notLastLane);
  if (allLanesFoldable) {
    scaleExponent = ((int (*)())outputScaleExponent)((double)GH_U2F((unsigned int)(operandVReg[scaleLane * 6 + 8])));
    hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
    canApplyScale = (**(code **)(*hwDescription + 0xfc))(hwDescription,scaleExponent,inst);
    if (canApplyScale != 0) {
      ((void (*)())IRInst__makeLiteralVec4Float)(inst,*(undefined4 *)(*(int *)(program + 8) + 0x6c4),1,1.0,1.0,1.0,1.0);
      inst[0x49] = scaleExponent;
      operandRecord = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord + 0x10) = 0x10203;
      return 1;
    }
  }
  return 0;
}

/* FUN_000f07a8 @ 0xf07a8 (464 bytes) */
int FUN_000f07a8(pass, afterInst, inst)
  int pass;
  undefined4 afterInst;
  int *inst;
{
  int composedSelectCopy;
  int movSourceForwardable;
  int selectIsIdentityOperand;
  int sourceCount;
  int sourceVtable0x7cResult;
  int constantsEncodable;
  int sourceIsConstant;
  int selectIsIdentity;
  int vtable0x64Result;
  int pushedUnwrittenSelectB;
  int consumerForwardable;
  int moveSourceNeedsClone;
  int moveSourceForwardable;
  int vtable0x68Result;
  uint consumerStackCount;
  uint maskStackCount;
  undefined4 *identityCursor;
  undefined4 *consumerStackTop;
  int *hwDescriptionObj;
  int *selectBytePtr;
  int *maskStackSlot;
  int *consumer;
  int *moveSource;
  int lastSourceIndex;
  int destKindClass;
  int sourceIndexB;
  int lanesLeft;
  int poppedSelectWord;
  int pushedSelectWord;
  int sourceIndex;
  int laneIndex;
  int destRegisterOffset;
  undefined4 pushedSource;
  undefined4 vectorData;
  undefined4 arenaB;
  int operandRecord3;
  int operandRecord4;
  int operandRecord;
  int operandRecord2;
  int *operandVReg;
  bool allSourcesForwardable;
  uint initialCapacity;
  int *hwDescription;
  int hwBlocksForwarding;
  undefined4 *allocation;
  undefined4 *vectorAlloc;
  undefined4 *consumerStackSlot;
  int pushedUnwrittenSelect;
  int consumerVtable0x7cResult;
  int destRegister;
  uint *consumerStack;
  uint *maskStack;
  uint consumerStackCountInit;
  int *maskStackTop;
  int vtable0x50Result;
  undefined4 moveSourceSelect;
  int moveSelect;
  int writtenLanesSelect;
  int unwrittenLanesSelect;
  undefined4 consumerDestMask;
  undefined1 consumerDestMaskView [4];
  undefined4 unitConstQuad [7];
  int clearedReadSelect;
  int composedSelect;
  undefined4 moveDestMask;
  int maskedSelect [6];
  
  hwDescription = *(int **)(*(int *)(pass + 8) + 0x30c);
  hwBlocksForwarding = (**(code **)(*hwDescription + 0xb8))(hwDescription,afterInst,inst);
  if ((((hwBlocksForwarding == 0) && ((inst[5] & 8U) == 0)) &&
      (hwBlocksForwarding = (**(code **)(*inst + 0x18))(inst), hwBlocksForwarding < 2)) &&
     (hwBlocksForwarding = (**(code **)(*inst + 0x14))(inst), hwBlocksForwarding != 0)) {
    moveSource = (int *)IRInst__getOperandSource(inst,1);
    vtable0x68Result = (**(code **)(*inst + 0x68))(inst);
    if (((vtable0x68Result != 0) || (vtable0x68Result = (**(code **)(*inst + 100))(inst), vtable0x68Result != 0)) &&
       (((inst[0x2e] & 1U) == 0 && ((inst[0x2e] & 2U) == 0)))) {
      operandRecord = IRInst__getOperandRecord(inst,1);
      moveSourceSelect = *(undefined4 *)(operandRecord + 0x10);
      operandRecord = IRInst__getOperandRecord(inst,0);
      WriteMask__fromSelectWord(&moveDestMask,*(undefined4 *)(operandRecord + 0x10));
      SelectWord__maskUnused(maskedSelect,moveSourceSelect,moveDestMask);
      moveSelect = maskedSelect[0];
      moveSourceForwardable = ((int (*)())IRInst__isForwardable)(moveSource,maskedSelect[0],*(undefined4 *)(pass + 8));
      if (moveSourceForwardable != 0) {
        moveSourceNeedsClone = (**(code **)(*moveSource + 0x60))(moveSource);
        if (moveSourceNeedsClone != 0) {
          moveSource = (int *)IRInst__foldCompareResultIntoCopy(moveSource,*(undefined4 *)(pass + 8));
          IRInst__setOperandSource(inst,1,moveSource,0,*(undefined4 *)(pass + 8));
        }
        destRegisterOffset = inst[0x26];
        arenaB = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
        destRegister = inst[0x25];
        allocation = (undefined4 *)Arena__alloc(arenaB,0x14);
        consumerStack = allocation + 1;
        *allocation = arenaB;
        allocation[1] = 2;
        allocation[4] = arenaB;
        allocation[2] = 0;
        vectorData = Arena__alloc(arenaB,8);
        allocation[3] = vectorData;
        arenaB = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
        vectorAlloc = (undefined4 *)Arena__alloc(arenaB,0x14);
        maskStack = vectorAlloc + 1;
        *vectorAlloc = arenaB;
        vectorAlloc[1] = 2;
        vectorAlloc[2] = 0;
        vectorAlloc[4] = arenaB;
        vectorData = Arena__alloc(arenaB,8);
        initialCapacity = allocation[1];
        consumerStackCountInit = allocation[2];
        vectorAlloc[3] = vectorData;
        if (consumerStackCountInit < initialCapacity) {
          _memset(consumerStackCountInit * 4 + allocation[3],0,4);
          allocation[2] = consumerStackCountInit + 1;
          consumerStackSlot = (undefined4 *)(consumerStackCountInit * 4 + allocation[3]);
        }
        else {
          consumerStackSlot = (undefined4 *)Vector__elementRefGrow(consumerStack,consumerStackCountInit);
        }
        pushedSelectWord = moveSelect;
        *consumerStackSlot = moveSource;
        maskStackCount = vectorAlloc[2];
        if (maskStackCount < *maskStack) {
          _memset(maskStackCount * 4 + vectorAlloc[3],0,4);
          consumer = (int *)(maskStackCount * 4 + vectorAlloc[3]);
          vectorAlloc[2] = maskStackCount + 1;
        }
        else {
          consumer = (int *)Vector__elementRefGrow(maskStack,maskStackCount);
        }
        *consumer = pushedSelectWord;
        *(int *)(pass + 0x474) = *(int *)(pass + 0x474) + 1;
code_r0x000f1384:
        do {
          while( true ) {
            do {
              do {
                consumerStackCount = allocation[2];
                if (consumerStackCount == 0) {
                  (**(code **)(*inst + 0xc))(inst,0,*(undefined4 *)(pass + 8));
                  if (consumerStack != (uint *)0x0) {
                    Arena__free(allocation[4],allocation[3]);
                    Arena__free(*allocation,allocation);
                  }
                  if (maskStack == (uint *)0x0) {
                    return;
                  }
                  Arena__free(vectorAlloc[4],vectorAlloc[3]);
                  Arena__free(*vectorAlloc,vectorAlloc);
                  return;
                }
                consumerStackTop = (undefined4 *)0x0;
                if (consumerStackCount - 1 < consumerStackCount) {
                  consumerStackTop = (undefined4 *)((consumerStackCount - 1) * 4 + allocation[3]);
                }
                consumer = (int *)*consumerStackTop;
                Vector__removeAt(consumerStack,consumerStackCount - 1);
                maskStackCount = vectorAlloc[2];
                maskStackTop = (int *)0x0;
                if (maskStackCount - 1 < maskStackCount) {
                  maskStackTop = (int *)((maskStackCount - 1) * 4 + vectorAlloc[3]);
                }
                poppedSelectWord = *maskStackTop;
                Vector__removeAt(maskStack,maskStackCount - 1);
                moveSelect = poppedSelectWord;
                poppedSelectWord = ((int (*)())IRInst__isForwardable)(consumer,poppedSelectWord,*(undefined4 *)(pass + 8));
                if ((poppedSelectWord != 0) && (poppedSelectWord = (**(code **)(*consumer + 0x60))(consumer), poppedSelectWord != 0))
                {
                  consumer = (int *)IRInst__foldCompareResultIntoCopy(consumer,*(undefined4 *)(pass + 8));
                }
              } while ((*(int *)(pass + 0x474) == consumer[0x54]) &&
                      (*(int *)(consumer[0x22] + 8) == 0x8e));
              consumer[0x54] = *(int *)(pass + 0x474);
              vtable0x50Result = (**(code **)(*consumer + 0x50))(consumer);
            } while (vtable0x50Result != 0);
            unwrittenLanesSelect = moveSelect;
            writtenLanesSelect = moveSelect;
            operandRecord2 = IRInst__getOperandRecord(consumer,0);
            laneIndex = 0;
            consumerDestMask = *(undefined4 *)(operandRecord2 + 0x10);
            lanesLeft = 4;
            do {
              if (*(byte *)((int)&moveSelect + laneIndex) != 4) {
                if (consumerDestMaskView[*(byte *)((int)&moveSelect + laneIndex) - 4] == '\x01') {
                  *(undefined1 *)((int)&writtenLanesSelect + laneIndex) = 4;
                }
                else {
                  *(undefined1 *)((int)&unwrittenLanesSelect + laneIndex) = 4;
                }
              }
              pushedUnwrittenSelect = unwrittenLanesSelect;
              laneIndex = laneIndex + 1;
              lanesLeft = lanesLeft + -1;
            } while (lanesLeft != 0);
            if (writtenLanesSelect != 0x4040404) break;
            if (((consumer[5] & 0x200U) != 0) && (unwrittenLanesSelect != 0x4040404)) {
              maskStackCount = vectorAlloc[2];
              if (maskStackCount < *maskStack) {
                _memset(maskStackCount * 4 + vectorAlloc[3],0,4);
                vectorAlloc[2] = maskStackCount + 1;
                maskStackSlot = (int *)(maskStackCount * 4 + vectorAlloc[3]);
              }
              else {
                maskStackSlot = (int *)Vector__elementRefGrow(maskStack,maskStackCount);
              }
              *maskStackSlot = pushedUnwrittenSelect;
              pushedSource = IRInst__getOperandSource(consumer,consumer[0x21]);
              consumerStackCount = allocation[2];
              if (consumerStackCount < *consumerStack) {
                _memset(consumerStackCount * 4 + allocation[3],0,4);
                allocation[2] = consumerStackCount + 1;
                consumerStackSlot = (undefined4 *)(consumerStackCount * 4 + allocation[3]);
              }
              else {
                consumerStackSlot = (undefined4 *)Vector__elementRefGrow(consumerStack,consumerStackCount);
              }
              *consumerStackSlot = pushedSource;
            }
          }
          consumerForwardable = ((int (*)())IRInst__isForwardable)(consumer,writtenLanesSelect,*(undefined4 *)(pass + 8));
          if (consumerForwardable != 0) {
            consumerVtable0x7cResult = (**(code **)(*consumer + 0x7c))(consumer);
            pushedUnwrittenSelectB = unwrittenLanesSelect;
            if (consumerVtable0x7cResult == 0) {
              if (((consumer[5] & 0x200U) != 0) && (unwrittenLanesSelect != 0x4040404)) {
                maskStackCount = vectorAlloc[2];
                if (maskStackCount < *maskStack) {
                  _memset(maskStackCount * 4 + vectorAlloc[3],0,4);
                  vectorAlloc[2] = maskStackCount + 1;
                  maskStackSlot = (int *)(maskStackCount * 4 + vectorAlloc[3]);
                }
                else {
                  maskStackSlot = (int *)Vector__elementRefGrow(maskStack,maskStackCount);
                }
                *maskStackSlot = pushedUnwrittenSelectB;
                pushedSource = IRInst__getOperandSource(consumer,consumer[0x21]);
                consumerStackCount = allocation[2];
                if (consumerStackCount < *consumerStack) {
                  _memset(consumerStackCount * 4 + allocation[3],0,4);
                  allocation[2] = consumerStackCount + 1;
                  consumerStackSlot = (undefined4 *)(consumerStackCount * 4 + allocation[3]);
                }
                else {
                  consumerStackSlot = (undefined4 *)Vector__elementRefGrow(consumerStack,consumerStackCount);
                }
                *consumerStackSlot = pushedSource;
                IRInst__setOperandSource(consumer,consumer[0x21],0,0,*(undefined4 *)(pass + 8));
                consumer[0x21] = consumer[0x21] + -1;
                consumer[5] = consumer[5] & 0xfffffdff;
              }
              vtable0x64Result = (**(code **)(*consumer + 100))(consumer);
              if (vtable0x64Result != 0) {
                for (sourceIndexB = 1; sourceCount = (**(code **)(*consumer + 0x14))(consumer), sourceIndexB <= sourceCount;
                    sourceIndexB = sourceIndexB + 1) {
                  if ((((consumer[sourceIndexB * 6 + 0x28] & 1U) != 0) ||
                      ((consumer[sourceIndexB * 6 + 0x28] & 2U) != 0)) ||
                     (selectIsIdentityOperand = IRInst__isSourceSelectIdentity(consumer,sourceIndexB), selectIsIdentityOperand == 0)) goto code_r0x000f101c;
                }
                if ((consumer[0x48] == 0) && (consumer[0x49] == 0)) {
                  if (((consumer[0x20] != 0) &&
                      ((sourceIndexB = RegKind__flagBit0(consumer[0x26]), sourceIndexB != 0 && ((consumer[5] & 2U) == 0))
                      )) && (sourceIndexB = (**(code **)(*consumer + 0x50))(consumer), sourceIndexB == 0)) {
                    lanesLeft = 4;
                    selectBytePtr = consumer;
                    do {
                      if ((uint)(*(byte *)(selectBytePtr + 0x27) - 2) < 2) goto code_r0x000f101c;
                      selectBytePtr = (int *)((int)selectBytePtr + 1);
                      lanesLeft = lanesLeft + -1;
                    } while (lanesLeft != 0);
                  }
                  IRInst__getOperandRecord(consumer,0);
                  destKindClass = IRInst__operandKindClass(consumer,0);
                  if ((destKindClass == 0) && ((consumer[5] & 2U) == 0)) {
                    pushedSource = IRInst__getOperandSource(consumer,1);
                    movSourceForwardable = ((int (*)())IRInst__isForwardable)(pushedSource,writtenLanesSelect,*(undefined4 *)(pass + 8));
                    pushedSelectWord = writtenLanesSelect;
                    if (movSourceForwardable != 0) {
                      maskStackCount = vectorAlloc[2];
                      if (maskStackCount < *maskStack) {
                        _memset(maskStackCount * 4 + vectorAlloc[3],0,4);
                        vectorAlloc[2] = maskStackCount + 1;
                        maskStackSlot = (int *)(maskStackCount * 4 + vectorAlloc[3]);
                      }
                      else {
                        maskStackSlot = (int *)Vector__elementRefGrow(maskStack,maskStackCount);
                      }
                      *maskStackSlot = pushedSelectWord;
                      pushedSource = IRInst__getOperandSource(consumer,1);
                      consumerStackCount = allocation[2];
                      if (consumerStackCount < *consumerStack) {
                        _memset(consumerStackCount * 4 + allocation[3],0,4);
                        allocation[2] = consumerStackCount + 1;
                        consumerStackSlot = (undefined4 *)(consumerStackCount * 4 + allocation[3]);
                      }
                      else {
                        consumerStackSlot = (undefined4 *)Vector__elementRefGrow(consumerStack,consumerStackCount);
                      }
                      *consumerStackSlot = pushedSource;
                      goto code_r0x000f1140;
                    }
                  }
                }
              }
code_r0x000f101c:
              IRInst__setHardwareRegisterAndAdd(consumer,pass,destRegisterOffset,destRegister);
              (**(code **)(*consumer + 0x94))(consumer,afterInst,*(undefined4 *)(pass + 8));
              SelectWord__clearReadComponents(&clearedReadSelect,writtenLanesSelect);
              consumer[0x27] = clearedReadSelect;
              selectIsIdentity = SelectWord__areCompatible(writtenLanesSelect,0x10203);
              if ((selectIsIdentity == 0) &&
                 (selectIsIdentity = OpcodeTraits__flag1WithoutFlag7(*(undefined4 *)(pass + 8),consumer), selectIsIdentity != 0)) {
                for (sourceIndexB = 1; sourceCount = (**(code **)(*consumer + 0x14))(consumer), sourceIndexB <= sourceCount;
                    sourceIndexB = sourceIndexB + 1) {
                  operandRecord3 = IRInst__getOperandRecord(consumer,sourceIndexB);
                  ((int (*)())SelectWord__compose)(&composedSelect,*(undefined4 *)(operandRecord3 + 0x10),writtenLanesSelect);
                  composedSelectCopy = composedSelect;
                  if (sourceIndexB == 0) {
                    consumer[0x27] = composedSelect;
                  }
                  else {
                    operandRecord4 = IRInst__getOperandRecord(consumer,sourceIndexB);
                    *(int *)(operandRecord4 + 0x10) = composedSelectCopy;
                  }
                }
              }
              vtable0x64Result = (**(code **)(*consumer + 100))(consumer);
              if (vtable0x64Result != 0) {
                for (sourceIndexB = 1; sourceCount = (**(code **)(*consumer + 0x14))(consumer), sourceIndexB <= sourceCount;
                    sourceIndexB = sourceIndexB + 1) {
                  if ((((consumer[sourceIndexB * 6 + 0x28] & 1U) != 0) ||
                      ((consumer[sourceIndexB * 6 + 0x28] & 2U) != 0)) ||
                     (selectIsIdentityOperand = IRInst__isSourceSelectIdentity(consumer,sourceIndexB), selectIsIdentityOperand == 0)) goto code_r0x000f1384;
                }
                if ((consumer[0x48] == 0) && (consumer[0x49] == 0)) {
                  if (((consumer[0x20] != 0) &&
                      ((sourceIndexB = RegKind__flagBit0(consumer[0x26]), sourceIndexB != 0 && ((consumer[5] & 2U) == 0))
                      )) && (sourceIndexB = (**(code **)(*consumer + 0x50))(consumer), sourceIndexB == 0)) {
                    lanesLeft = 4;
                    selectBytePtr = consumer;
                    do {
                      if ((uint)(*(byte *)(selectBytePtr + 0x27) - 2) < 2) goto code_r0x000f1384;
                      selectBytePtr = (int *)((int)selectBytePtr + 1);
                      lanesLeft = lanesLeft + -1;
                    } while (lanesLeft != 0);
                  }
                  IRInst__getOperandRecord(consumer,0);
                  destKindClass = IRInst__operandKindClass(consumer,0);
                  if (destKindClass == 0) {
                    operandVReg = (int *)IRInst__getOperandSource(consumer,1);
                    sourceIsConstant = (**(code **)(*operandVReg + 0x48))();
                    if (sourceIsConstant != 0) {
                      lanesLeft = 4;
                      identityCursor = unitConstQuad;
                      do {
                        *identityCursor = 0x7ffffffe;
                        identityCursor = identityCursor + 1;
                        lanesLeft = lanesLeft + -1;
                      } while (lanesLeft != 0);
                      unitConstQuad[0] = 0x3f800000;
                      unitConstQuad[3] = 0x3f800000;
                      unitConstQuad[2] = 0x3f800000;
                      unitConstQuad[1] = 0x3f800000;
                      hwDescriptionObj = *(int **)(*(int *)(pass + 8) + 0x30c);
                      constantsEncodable = (**(code **)(*hwDescriptionObj + 0xe8))(hwDescriptionObj,unitConstQuad,consumerDestMaskView,0x10203);
                      if (constantsEncodable != 0) {
                        ((int (*)())IRInst__tryFoldOutputScale)(pass,consumer);
                      }
                    }
                  }
                }
              }
            }
            else {
              lastSourceIndex = consumer[0x21];
              if (0 < lastSourceIndex) {
                sourceIndex = 1;
                allSourcesForwardable = true;
                do {
                  operandVReg = (int *)IRInst__getOperandSource(consumer,sourceIndex);
                  sourceVtable0x7cResult = (**(code **)(*operandVReg + 0x7c))();
                  if ((sourceVtable0x7cResult != 0) ||
                     (sourceVtable0x7cResult = ((int (*)())IRInst__isForwardable)(operandVReg,writtenLanesSelect,*(undefined4 *)(pass + 8)),
                     sourceVtable0x7cResult == 0)) {
                    allSourcesForwardable = false;
                  }
                  lastSourceIndex = consumer[0x21];
                  sourceIndex = sourceIndex + 1;
                } while (sourceIndex <= lastSourceIndex);
                if (!allSourcesForwardable) goto code_r0x000f0d0c;
              }
              sourceIndex = 1;
              if (0 < lastSourceIndex) {
                do {
                  pushedSelectWord = moveSelect;
                  maskStackCount = vectorAlloc[2];
                  if (maskStackCount < *maskStack) {
                    _memset(maskStackCount * 4 + vectorAlloc[3],0,4);
                    vectorAlloc[2] = maskStackCount + 1;
                    maskStackSlot = (int *)(maskStackCount * 4 + vectorAlloc[3]);
                  }
                  else {
                    maskStackSlot = (int *)Vector__elementRefGrow(maskStack,maskStackCount);
                  }
                  *maskStackSlot = pushedSelectWord;
                  pushedSource = IRInst__getOperandSource(consumer,sourceIndex);
                  consumerStackCount = allocation[2];
                  if (consumerStackCount < *consumerStack) {
                    _memset(consumerStackCount * 4 + allocation[3],0,4);
                    allocation[2] = consumerStackCount + 1;
                    consumerStackSlot = (undefined4 *)(consumerStackCount * 4 + allocation[3]);
                  }
                  else {
                    consumerStackSlot = (undefined4 *)Vector__elementRefGrow(consumerStack,consumerStackCount);
                  }
                  *consumerStackSlot = pushedSource;
                  sourceIndex = sourceIndex + 1;
                } while (sourceIndex <= consumer[0x21]);
              }
code_r0x000f1140:
              (**(code **)(*consumer + 0xc))(consumer,0,*(undefined4 *)(pass + 8));
            }
            goto code_r0x000f1384;
          }
code_r0x000f0d0c:
          ((int (*)())Program__insertMovAfter)(pass,consumer,afterInst,destRegisterOffset,destRegister,moveSelect);
        } while( true );
      }
    }
  }
  return (**(code **)(*inst + 0x94))(inst,afterInst,*(undefined4 *)(pass + 8));
}

/* FUN_000f14f8 @ 0xf14f8 (132 bytes) */
int FUN_000f14f8(program, inst, inst2)
  int program;
  int *inst;
  int *inst2;
{
  undefined4 chainSelectWord;
  uint secondPassFlag;
  int foldedCount;
  int moveSourceSelect;
  int isStoreLike;
  int sourceBlock;
  int composedSelectWord;
  int placementInstRef;
  undefined4 hwRegisterFile;
  undefined4 destSelectWord;
  undefined4 placementInst;
  int allocPlacementEnabled;
  int operandRecord4;
  int operandRecord2;
  int operandRecord;
  int operandRecord3;
  int *operandVReg2;
  bool singleFold;
  code *UNRECOVERED_JUMPTABLE;
  uint instFlags;
  undefined4 *allocation;
  int block;
  int *moveSource;
  int hwFoldRejects;
  int *operandVReg;
  int *newMov;
  int sourceCheckResult;
  int *newMov2;
  undefined4 compiler;
  int vtable;
  undefined4 destSelectWord2;
  undefined4 arenaA;
  int chainMarkedSelect;
  int firstMarkedSelect;
  int nextMarkedSelect;
  int destMarkedSelect;
  int composedMarkedSelect [3];
  
  arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
  *allocation = arenaA;
  IRInst__ctor_10502c(allocation + 1,0x93,*(undefined4 *)(program + 8));
  *(undefined4 **)(program + 0x340) = allocation + 1;
  allocation[0x27] = 0x2e;
  allocation[0x26] = 0;
  *(undefined4 *)(*(int *)(program + 0x340) + 300) = 0;
  allocPlacementEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x23);
  if (allocPlacementEnabled == 0) {
    if (((*(uint *)(program + 0x30) & 1) != 0) && (inst != (int *)0x0)) {
      Block__prependInst(inst[0x56],*(undefined4 *)(program + 0x340));
      (**(code **)(*inst + 0x94))
                (inst,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
      if (inst2 != (int *)0x0) {
        *(undefined4 *)(*(int *)(program + 0x340) + 300) = 1;
        compiler = *(undefined4 *)(program + 8);
        UNRECOVERED_JUMPTABLE = *(code **)(*inst2 + 0x94);
        placementInst = *(undefined4 *)(program + 0x340);
        inst = inst2;
        goto LAB_000f1940;
      }
    }
  }
  else if (((*(uint *)(program + 0x30) & 1) != 0) && (inst != (int *)0x0)) {
    block = inst[0x56];
    if (inst2 == (int *)0x0) {
      moveSource = (int *)IRInst__getOperandSource(inst,1);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      moveSourceSelect = *(int *)(operandRecord2 + 0x10);
      hwFoldRejects = (**(code **)(**(int **)(*(int *)(program + 8) + 0x30c) + 0xb8))();
      if (((hwFoldRejects == 0) && (hwFoldRejects = (**(code **)(*moveSource + 0x7c))(moveSource), hwFoldRejects == 0)) &&
         ((((hwFoldRejects = OpcodeTraits__flag1WithoutFlag7(*(undefined4 *)(program + 8),moveSource), hwFoldRejects != 0 &&
            ((hwFoldRejects = moveSource[0x58] - *(int *)(program + 0x478), hwFoldRejects < 0 || (hwFoldRejects < 2)))) &&
           (hwFoldRejects = (**(code **)(*moveSource + 0x28))(moveSource), hwFoldRejects == 0)) &&
          ((moveSource[0x21] != 0 && (moveSourceSelect == DAT_001aa804)))))) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        destSelectWord = *(undefined4 *)(operandRecord + 0x10);
        ((int (*)())Program__removeInst)(program,inst);
        (**(code **)(*inst + 0xc))(inst,0,*(undefined4 *)(program + 8));
        sourceBlock = moveSource[0x56];
        IRInst__setHardwareRegisterAndAdd(moveSource,program,6,0);
        (**(code **)(*moveSource + 0x94))
                  (moveSource,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
        operandRecord = IRInst__getOperandRecord(moveSource,0);
        SelectWord__markEqualLanes(&firstMarkedSelect,destSelectWord,*(undefined4 *)(operandRecord + 0x10));
        instFlags = moveSource[5];
        block = firstMarkedSelect;
        do {
          if ((instFlags & 0x200) == 0) {
code_r0x000e76c4:
            placementInstRef = *(int *)(program + 0x340);
            DList__insertAfter(placementInstRef,*(undefined4 *)(sourceBlock + 200));
            *(int *)(placementInstRef + 0x158) = sourceBlock;
            return;
          }
          operandVReg = (int *)IRInst__getOperandSource(moveSource,moveSource[0x21]);
          IRInst__setOperandSource(moveSource,moveSource[0x21],0,0,*(undefined4 *)(program + 8));
          vtable = *operandVReg;
          moveSource[0x21] = moveSource[0x21] + -1;
          moveSource[5] = moveSource[5] & 0xfffffdff;
          vtable = (**(code **)(vtable + 0x7c))(operandVReg);
          if ((((vtable != 0) ||
               (vtable = OpcodeTraits__flag1WithoutFlag7(*(undefined4 *)(program + 8),operandVReg), vtable == 0)) ||
              ((vtable = operandVReg[0x58] - *(int *)(program + 0x478), -1 < vtable && (1 < vtable)))) ||
             (((sourceBlock != operandVReg[0x56] ||
               (vtable = (**(code **)(*operandVReg + 0x28))(operandVReg), vtable != 0)) || (operandVReg[0x21] == 0)
              ))) {
            newMov = (int *)IRMov__new_1084b8(0x31,*(undefined4 *)(program + 8));
            IRInst__setOperandSource(newMov,1,operandVReg,0,*(undefined4 *)(program + 8));
            (**(code **)(*newMov + 0x94))
                      (newMov,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
            IRInst__setHardwareRegisterAndAdd(newMov,program,6,0);
            newMov[0x27] = block;
            Block__insertInstBefore(sourceBlock,moveSource,newMov);
            goto code_r0x000e76c4;
          }
          (**(code **)(*operandVReg + 0x94))
                    (operandVReg,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
          IRInst__setHardwareRegisterAndAdd(operandVReg,program,6,0);
          operandRecord3 = IRInst__getOperandRecord(operandVReg,0);
          SelectWord__markEqualLanes(&nextMarkedSelect,block,*(undefined4 *)(operandRecord3 + 0x10));
          instFlags = operandVReg[5];
          moveSource = operandVReg;
          block = nextMarkedSelect;
        } while( true );
      }
      Block__insertAtStart(block,*(undefined4 *)(program + 0x340));
      compiler = *(undefined4 *)(program + 8);
      UNRECOVERED_JUMPTABLE = *(code **)(*inst + 0x94);
      placementInst = *(undefined4 *)(program + 0x340);
    }
    else {
      *(undefined4 *)(*(int *)(program + 0x340) + 300) = 1;
      moveSource = (int *)IRInst__getOperandSource(inst,1);
      operandVReg = (int *)IRInst__getOperandSource(inst2,1);
      if ((((moveSource[0x56] == operandVReg[0x56]) &&
           (isStoreLike = (**(code **)(*moveSource + 0x7c))(moveSource), isStoreLike == 0)) &&
          (isStoreLike = (**(code **)(*operandVReg + 0x7c))(operandVReg), isStoreLike == 0)) &&
         ((moveSource[0x21] != 0 && (operandVReg[0x21] != 0)))) {
        secondPassFlag = (uint)(1 < *(int *)(program + 0x478));
        if (((((int)(moveSource[0x58] - secondPassFlag) < 0) || (moveSource[0x58] == secondPassFlag)) &&
            (((isStoreLike = operandVReg[0x58] - *(int *)(program + 0x478), isStoreLike < 0 || (isStoreLike < 2)) &&
             (isStoreLike = (**(code **)(*moveSource + 0x28))(moveSource), isStoreLike == 0)))) &&
           (isStoreLike = (**(code **)(*operandVReg + 0x28))(operandVReg), isStoreLike == 0)) {
          sourceBlock = moveSource[0x56];
          operandRecord = IRInst__getOperandRecord(inst,0);
          destSelectWord2 = *(undefined4 *)(operandRecord + 0x10);
          hwRegisterFile = 6;
          operandRecord = IRInst__getOperandRecord(inst2,0);
          chainSelectWord = *(undefined4 *)(operandRecord + 0x10);
          ((int (*)())Program__removeInst)(program,inst2);
          foldedCount = 0;
          ((int (*)())Program__removeInst)(program,inst);
          (**(code **)(*inst + 0xc))(inst,0,*(undefined4 *)(program + 8));
          (**(code **)(*inst2 + 0xc))(inst2,0,*(undefined4 *)(program + 8));
          Block__prependInst(sourceBlock,*(undefined4 *)(program + 0x340));
          operandRecord = IRInst__getOperandRecord(moveSource,0);
          SelectWord__markEqualLanes(&destMarkedSelect,destSelectWord2,*(undefined4 *)(operandRecord + 0x10));
          do {
            (**(code **)(*moveSource + 0x94))
                      (moveSource,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
            IRInst__setHardwareRegisterAndAdd(moveSource,program,hwRegisterFile,0);
            instFlags = moveSource[5];
            composedSelectWord = destMarkedSelect;
            while ((instFlags & 0x200) != 0) {
              operandVReg2 = (int *)IRInst__getOperandSource(moveSource,moveSource[0x21]);
              sourceCheckResult = (**(code **)(*operandVReg2 + 0x7c))();
              if ((((sourceCheckResult != 0) ||
                   (sourceCheckResult = OpcodeTraits__flag1WithoutFlag7(*(undefined4 *)(program + 8),operandVReg2), sourceCheckResult == 0)) ||
                  ((sourceCheckResult = operandVReg2[0x58] - *(int *)(program + 0x478), -1 < sourceCheckResult && (1 < sourceCheckResult))))
                 || (((sourceBlock != operandVReg2[0x56] ||
                      (sourceCheckResult = (**(code **)(*operandVReg2 + 0x28))(operandVReg2), sourceCheckResult != 0)) ||
                     (operandVReg2[0x21] == 0)))) {
                newMov2 = (int *)IRMov__new_1084b8(0x31,*(undefined4 *)(program + 8));
                IRInst__setOperandSource(newMov2,1,operandVReg2,0,*(undefined4 *)(program + 8));
                IRInst__setHardwareRegisterAndAdd(newMov2,program,hwRegisterFile,0);
                (**(code **)(*newMov2 + 0x94))
                          (newMov2,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
                newMov2[0x27] = composedSelectWord;
                Block__insertInstBefore(sourceBlock,moveSource,newMov2);
                break;
              }
              (**(code **)(*operandVReg2 + 0x94))
                        (operandVReg2,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
              IRInst__setHardwareRegisterAndAdd(operandVReg2,program,hwRegisterFile,0);
              operandRecord4 = IRInst__getOperandRecord(operandVReg2,0);
              SelectWord__markEqualLanes(composedMarkedSelect,composedSelectWord,*(undefined4 *)(operandRecord4 + 0x10));
              composedSelectWord = composedMarkedSelect[0];
              moveSource = operandVReg2;
              instFlags = operandVReg2[5];
            }
            block = IRInst__getOperandRecord(operandVReg,0);
            hwRegisterFile = 7;
            SelectWord__markEqualLanes(&chainMarkedSelect,chainSelectWord,*(undefined4 *)(block + 0x10));
            singleFold = foldedCount == 1;
            foldedCount = foldedCount + 1;
            destMarkedSelect = chainMarkedSelect;
            moveSource = operandVReg;
            if (singleFold) {
              return;
            }
          } while( true );
        }
      }
      Block__insertAtStart(block,*(undefined4 *)(program + 0x340));
      (**(code **)(*inst + 0x94))
                (inst,*(undefined4 *)(program + 0x340),*(undefined4 *)(program + 8));
      compiler = *(undefined4 *)(program + 8);
      UNRECOVERED_JUMPTABLE = *(code **)(*inst2 + 0x94);
      placementInst = *(undefined4 *)(program + 0x340);
      inst = inst2;
    }
LAB_000f1940:
                    
                    
    (*UNRECOVERED_JUMPTABLE)(inst,placementInst,compiler);
    return;
  }
  return;
}

/* FUN_000f1d7c @ 0xf1d7c (3008 bytes) */
int FUN_000f1d7c(pass, afterInst, inst)
  int pass;
  undefined4 afterInst;
  dword *inst;
{
  int consumerVtable0x7cResult;
  int scannedSourceDef;
  int thirdSourceDef;
  int slotByteOffset;
  int fixupMov;
  int lastSourceIndex;
  int nodeIsProjection;
  int lastWalkIndex;
  int pushedSourceIndex;
  int nodeOpcodeInSet;
  int nodeVtable0x7cResult;
  uint fixupIndexCountB;
  uint fixupInstCount;
  uint unusedMask;
  uint fixupIndexCount;
  uint walkIndexTopIndex;
  uint maskedUse;
  uint readMask;
  uint fixupIndexTopIndex;
  uint fixupInstTopIndex;
  uint walkIndexCount;
  uint walkInstCount;
  undefined4 *fixupIndexSlotB;
  undefined4 *fixupInstSlot;
  undefined4 *walkInstTop;
  undefined4 *fixupInstTop;
  undefined4 *walkIndexSlotB;
  int *fixupIndexSlot;
  int *walkIndexTop;
  int *walkIndexSlot;
  int *fixupIndexTop;
  int fixupIndexByteOffset;
  int fixupInstByteOffset;
  int walkIndexByteOffset;
  int walkInstByteOffset;
  bool hasNode;
  int sourceDef;
  int operandRecord;
  int *operandVReg;
  int loopIndex;
  bool walking;
  undefined4 *walkInstSlot;
  int *node;
  int fixupOperandIndex;
  int operandVtable0x50Result;
  int consumerIsProjection;
  undefined4 predecessor;
  undefined4 a1;
  dword *a2;
  uint nodeDestMask;
  dword argR6;
  undefined4 argR7;
  undefined4 staleArgR8;
  uint walkInstTopIndex;
  dword destRegister;
  dword *destRegisterOffset;
  int *fixupConsumer;
  char maskedUseByte3;
  char maskedUseByte2;
  char maskedUseByte1;
  char maskedUseByte0;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_88_buf [0x10];
  #define vecCapacity (*(uint *)(local_88_buf + 0x00))
  #define vecCount (*(uint *)(local_88_buf + 0x04))
  #define vecData (*(int *)(local_88_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_88_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vec2Capacity/vec2Count/vec2Data/vec2Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_78_buf [0x10];
  #define vec2Capacity (*(uint *)(local_78_buf + 0x00))
  #define vec2Count (*(uint *)(local_78_buf + 0x04))
  #define vec2Data (*(int *)(local_78_buf + 0x08))
  #define vec2Arena (*(undefined4 *)(local_78_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vec3Capacity/vec3Count/vec3Data/vec3Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_68_buf [0x10];
  #define vec3Capacity (*(uint *)(local_68_buf + 0x00))
  #define vec3Count (*(uint *)(local_68_buf + 0x04))
  #define vec3Data (*(int *)(local_68_buf + 0x08))
  #define vec3Arena (*(undefined4 *)(local_68_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vec4Capacity/vec4Count/vec4Data/vec4Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_58_buf [0x10];
  #define vec4Capacity (*(uint *)(local_58_buf + 0x00))
  #define vec4Count (*(uint *)(local_58_buf + 0x04))
  #define vec4Data (*(int *)(local_58_buf + 0x08))
  #define vec4Arena (*(undefined4 *)(local_58_buf + 0x0c))
  int nodeDestMaskTemp;
  uint visitedNodeDestMask;
  uint instDestMask;
  undefined4 fixupMovSelect;
  dword instSelectOut [2];
  
  *(int *)(pass + 0x474) = *(int *)(pass + 0x474) + 1;
  vec4Arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vec4Count = 0;
  vec4Capacity = 2;
  destRegisterOffset = (dword *)inst[0x26];
  destRegister = inst[0x25];
  a2 = inst;
  vec4Data = Arena__alloc(vec4Arena,8);
  vecArena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  vec2Arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vec2Count = 0;
  vec2Capacity = 2;
  vec2Data = Arena__alloc(vec2Arena,8);
  vec3Arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vec3Count = 0;
  vec3Capacity = 2;
  vec3Data = Arena__alloc(vec3Arena,8);
  walkInstCount = vec4Count;
  if (vec4Count < vec4Capacity) {
    walkInstByteOffset = vec4Count * 4;
    a2 = ((unsigned char *)0x4);
    _memset(walkInstByteOffset + vec4Data,0,4);
    vec4Count = walkInstCount + 1;
    walkInstSlot = (undefined4 *)(walkInstByteOffset + vec4Data);
  }
  else {
    walkInstSlot = (undefined4 *)Vector__elementRefGrow(&vec4Capacity,vec4Count);
  }
  walkIndexCount = vecCount;
  *walkInstSlot = inst;
  if (vecCount < vecCapacity) {
    walkIndexByteOffset = vecCount * 4;
    a2 = ((unsigned char *)0x4);
    _memset(walkIndexByteOffset + vecData,0,4);
    vecCount = walkIndexCount + 1;
    walkIndexSlotB = (undefined4 *)(walkIndexByteOffset + vecData);
  }
  else {
    walkIndexSlotB = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
  }
  *walkIndexSlotB = 1;
  node = (int *)IRInst__getOperandSource(inst,1);
  walking = true;
  walkInstCount = vec4Count;
LAB_000f26b0:
  do {
    while( true ) {
      if (walkInstCount == 0) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        WriteMask__fromSelectWord(&instDestMask,*(undefined4 *)(operandRecord + 0x10));
        while (vec2Count != 0) {
          fixupInstTopIndex = vec2Count - 1;
          fixupInstTop = (undefined4 *)0x0;
          if (fixupInstTopIndex < vec2Count) {
            fixupInstTop = (undefined4 *)(fixupInstTopIndex * 4 + vec2Data);
          }
          fixupConsumer = (int *)*fixupInstTop;
          Vector__removeAt(&vec2Capacity,fixupInstTopIndex);
          fixupIndexTop = (int *)0x0;
          fixupIndexTopIndex = vec3Count - 1;
          if (fixupIndexTopIndex < vec3Count) {
            fixupIndexTop = (int *)(fixupIndexTopIndex * 4 + vec3Data);
          }
          fixupOperandIndex = *fixupIndexTop;
          Vector__removeAt(&vec3Capacity,fixupIndexTopIndex);
          operandVReg = (int *)IRInst__getOperandSource(fixupConsumer,fixupOperandIndex);
          if (((dword *)operandVReg[0x26] != destRegisterOffset) &&
             (operandVtable0x50Result = (**(code **)(*operandVReg + 0x50))(operandVReg), operandVtable0x50Result == 0)) {
            readMask = operandVReg[3];
            fixupMov = IRMov__new_1084b8(0x31,*(undefined4 *)(pass + 8));
            IRInst__setOperandSource(fixupMov,1,operandVReg,0,*(undefined4 *)(pass + 8));
            IRInst__setHardwareRegisterAndAdd(fixupMov,pass,destRegisterOffset,destRegister);
            SelectWord__selectWhereMasked(&fixupMovSelect,0,instDestMask & readMask);
            *(undefined4 *)(fixupMov + 0x9c) = fixupMovSelect;
            IRInst__maskUnusedLanesOfOperand(fixupMov,1,pass);
            consumerIsProjection = IRInst__isProjectionOfOpcode2a(fixupConsumer);
            if (consumerIsProjection == 0) {
              consumerVtable0x7cResult = (**(code **)(*fixupConsumer + 0x7c))(fixupConsumer);
              if (consumerVtable0x7cResult == 0) {
                IRInst__setOperandSource(fixupConsumer,fixupOperandIndex,fixupMov,0,*(undefined4 *)(pass + 8));
                Block__insertInstBefore(fixupConsumer[0x56],fixupConsumer,fixupMov);
              }
              else {
                IRInst__setOperandSource(fixupConsumer,fixupOperandIndex,fixupMov,0,*(undefined4 *)(pass + 8));
                predecessor = Block__getPredecessor(fixupConsumer[0x56],fixupOperandIndex + -1);
                Block__appendInst(predecessor,fixupMov);
              }
            }
            else {
              IRInst__setExtraOperandSource(fixupConsumer,fixupMov,0,*(undefined4 *)(pass + 8));
              Block__insertInstAfter(operandVReg[0x56],operandVReg,fixupMov);
            }
          }
        }
        sourceDef = IRInst__getOperandSource(inst,1);
        maskedUse = instDestMask & *(uint *)(sourceDef + 0xc);
        SelectWord__selectWhereMasked(instSelectOut,0,maskedUse);
        inst[0x27] = instSelectOut[0];
        IRInst__maskUnusedLanesOfOperand(inst,1,pass);
        maskedUseByte0 = (char)maskedUse;
        maskedUseByte1 = (char)(maskedUse >> 8);
        maskedUseByte2 = (char)(maskedUse >> 0x10);
        maskedUseByte3 = (char)(maskedUse >> 0x18);
        if (((maskedUseByte0 == '\0' && maskedUseByte1 == '\0') && maskedUseByte2 == '\0') && maskedUseByte3 == '\0') {
          (**(code **)(*inst + 0xc))(inst,0,*(undefined4 *)(pass + 8));
        }
        else {
          ((int (*)())FUN_000f07a8)(pass,afterInst,inst);
        }
        Arena__free(vec3Arena,vec3Data);
        Arena__free(vec2Arena,vec2Data);
        Arena__free(vecArena,vecData);
        Arena__free(vec4Arena,vec4Data);
        return;
      }
      if (!walking) break;
      if (node == (int *)0x0) {
        node = (int *)0x0;
        walking = false;
      }
      else if (*(int *)(pass + 0x474) == node[0x54]) {
LAB_000f26a4:
        walking = false;
      }
      else {
        node[0x54] = *(int *)(pass + 0x474);
        operandRecord = IRInst__getOperandRecord(node,0);
        WriteMask__fromSelectWord(&nodeDestMaskTemp,*(undefined4 *)(operandRecord + 0x10));
        node[3] = nodeDestMaskTemp;
        nodeVtable0x7cResult = (**(code **)(*node + 0x7c))
                          (node,a1,a2,argR6,argR7,staleArgR8,*(code **)(*node + 0x7c));
        walkInstCount = vec4Count;
        if (nodeVtable0x7cResult == 0) {
          nodeOpcodeInSet = IRInst__opcodeIsInSet(node);
          walkInstCount = vec4Count;
          if (nodeOpcodeInSet == 0) {
            if ((node[5] & 0x200U) == 0) goto LAB_000f26a4;
            if (vec4Count < vec4Capacity) {
              walkInstByteOffset = vec4Count * 4;
              a2 = ((unsigned char *)0x4);
              _memset(walkInstByteOffset + vec4Data,0,4);
              vec4Count = walkInstCount + 1;
              walkInstSlot = (undefined4 *)(walkInstByteOffset + vec4Data);
            }
            else {
              walkInstSlot = (undefined4 *)Vector__elementRefGrow(&vec4Capacity,vec4Count);
            }
            walkIndexCount = vecCount;
            *walkInstSlot = node;
            pushedSourceIndex = node[0x21];
            if (vecCount < vecCapacity) {
              slotByteOffset = vecCount * 4;
              a2 = ((unsigned char *)0x4);
              _memset(slotByteOffset + vecData,0,4);
              vecCount = walkIndexCount + 1;
              walkIndexSlot = (int *)(slotByteOffset + vecData);
            }
            else {
              walkIndexSlot = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *walkIndexSlot = pushedSourceIndex;
            node = (int *)IRInst__getOperandSource(node,node[0x21]);
          }
          else {
            if (vec4Count < vec4Capacity) {
              walkInstByteOffset = vec4Count * 4;
              a2 = ((unsigned char *)0x4);
              _memset(walkInstByteOffset + vec4Data,0,4);
              vec4Count = walkInstCount + 1;
              walkInstSlot = (undefined4 *)(walkInstByteOffset + vec4Data);
            }
            else {
              walkInstSlot = (undefined4 *)Vector__elementRefGrow(&vec4Capacity,vec4Count);
            }
            walkIndexCount = vecCount;
            *walkInstSlot = node;
            if (vecCount < vecCapacity) {
              walkIndexByteOffset = vecCount * 4;
              a2 = ((unsigned char *)0x4);
              _memset(walkIndexByteOffset + vecData,0,4);
              vecCount = walkIndexCount + 1;
              walkIndexSlotB = (undefined4 *)(walkIndexByteOffset + vecData);
            }
            else {
              walkIndexSlotB = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *walkIndexSlotB = 2;
            node = (int *)IRInst__getOperandSource(node,2);
          }
        }
        else {
          if (vec4Count < vec4Capacity) {
            walkInstByteOffset = vec4Count * 4;
            a2 = ((unsigned char *)0x4);
            _memset(walkInstByteOffset + vec4Data,0,4);
            vec4Count = walkInstCount + 1;
            walkInstSlot = (undefined4 *)(walkInstByteOffset + vec4Data);
          }
          else {
            walkInstSlot = (undefined4 *)Vector__elementRefGrow(&vec4Capacity,vec4Count);
          }
          walkIndexCount = vecCount;
          *walkInstSlot = node;
          if (vecCount < vecCapacity) {
            walkIndexByteOffset = vecCount * 4;
            a2 = ((unsigned char *)0x4);
            _memset(walkIndexByteOffset + vecData,0,4);
            vecCount = walkIndexCount + 1;
            walkIndexSlotB = (undefined4 *)(walkIndexByteOffset + vecData);
          }
          else {
            walkIndexSlotB = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
          }
          *walkIndexSlotB = 1;
          node = (int *)IRInst__getOperandSource(node,1);
        }
LAB_000f2690:
        walking = true;
        walkInstCount = vec4Count;
      }
    }
    walkInstTopIndex = walkInstCount - 1;
    walkInstTop = (undefined4 *)0x0;
    if (walkInstTopIndex < walkInstCount) {
      walkInstTop = (undefined4 *)(walkInstTopIndex * 4 + vec4Data);
    }
    hasNode = node != (int *)0x0;
    node = (int *)*walkInstTop;
    if (hasNode) {
      walkIndexTop = (int *)0x0;
      walkIndexTopIndex = vecCount - 1;
      if (walkIndexTopIndex < vecCount) {
        walkIndexTop = (int *)(walkIndexTopIndex * 4 + vecData);
      }
      if (*walkIndexTop != node[0x21]) {
        walkIndexTop = (int *)0x0;
        if (walkIndexTopIndex < vecCount) {
          walkIndexTop = (int *)(walkIndexTopIndex * 4 + vecData);
        }
        lastWalkIndex = *walkIndexTop;
        Vector__removeAt(&vecCapacity,walkIndexTopIndex);
        walkIndexCount = vecCount;
        if (vecCount < vecCapacity) {
          slotByteOffset = vecCount * 4;
          a2 = ((unsigned char *)0x4);
          _memset(slotByteOffset + vecData,0,4);
          vecCount = walkIndexCount + 1;
          walkIndexSlot = (int *)(slotByteOffset + vecData);
        }
        else {
          walkIndexSlot = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
        }
        *walkIndexSlot = lastWalkIndex + 1;
        node = (int *)IRInst__getOperandSource(node,lastWalkIndex + 1);
        goto LAB_000f2690;
      }
    }
    Vector__removeAt(&vec4Capacity,walkInstTopIndex);
    Vector__removeAt(&vecCapacity,vecCount - 1);
    operandRecord = IRInst__getOperandRecord(node,0);
    WriteMask__fromSelectWord(&visitedNodeDestMask,*(undefined4 *)(operandRecord + 0x10));
    nodeDestMask = visitedNodeDestMask;
    nodeIsProjection = IRInst__isProjectionOfOpcode2a(node);
    if (nodeIsProjection == 0) {
      nodeVtable0x7cResult = (**(code **)(*node + 0x7c))(node);
      if (nodeVtable0x7cResult == 0) {
        nodeOpcodeInSet = IRInst__opcodeIsInSet(node);
        if (nodeOpcodeInSet != 0) {
          sourceDef = IRInst__getOperandSource(node,2);
          thirdSourceDef = IRInst__getOperandSource(node,3);
          unusedMask = ~*(uint *)(sourceDef + 0xc);
          if ((nodeDestMask & (unusedMask << 0x18 | (unusedMask & 0xff00) << 8 | unusedMask >> 8 & 0xff00 | unusedMask >> 0x18)
              ) == 0) {
            unusedMask = ~*(uint *)(thirdSourceDef + 0xc);
            if ((nodeDestMask & (unusedMask << 0x18 | (unusedMask & 0xff00) << 8 | unusedMask >> 8 & 0xff00 |
                         unusedMask >> 0x18)) == 0) goto LAB_000f25ac;
            IRInst__reduceTernaryToBinary(node,3,*(undefined4 *)(pass + 8));
          }
          else {
            IRInst__reduceTernaryToBinary(node,2,*(undefined4 *)(pass + 8));
          }
          a2 = destRegisterOffset;
          argR6 = destRegister;
          IRInst__setHardwareRegisterAndAdd(node,pass,destRegisterOffset,destRegister);
          fixupInstCount = vec2Count;
          if (vec2Count < vec2Capacity) {
            fixupInstByteOffset = vec2Count * 4;
            a2 = ((unsigned char *)0x4);
            _memset(fixupInstByteOffset + vec2Data,0,4);
            vec2Count = fixupInstCount + 1;
            fixupInstSlot = (undefined4 *)(fixupInstByteOffset + vec2Data);
          }
          else {
            fixupInstSlot = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
          }
          fixupIndexCountB = vec3Count;
          *fixupInstSlot = node;
          if (vec3Count < vec3Capacity) {
            fixupIndexByteOffset = vec3Count * 4;
            a2 = ((unsigned char *)0x4);
            _memset(fixupIndexByteOffset + vec3Data,0,4);
            vec3Count = fixupIndexCountB + 1;
            fixupIndexSlotB = (undefined4 *)(fixupIndexByteOffset + vec3Data);
          }
          else {
            fixupIndexSlotB = (undefined4 *)Vector__elementRefGrow(&vec3Capacity,vec3Count);
          }
          *fixupIndexSlotB = 3;
          node[3] = 0;
        }
LAB_000f25ac:
        if ((node[5] & 0x200U) != 0) {
          sourceDef = IRInst__getOperandSource(node,node[0x21]);
          node[3] = nodeDestMask | *(uint *)(sourceDef + 0xc);
          if ((dword *)*(undefined1 **)(sourceDef + 0x98) == destRegisterOffset) {
            a2 = (dword *)0x0;
            argR6 = 0;
            argR7 = *(undefined4 *)(pass + 8);
            IRInst__setOperandSource(node,node[0x21],0,0,argR7);
            node[0x21] = node[0x21] + -1;
            node[5] = node[5] & 0xfffffdff;
          }
        }
      }
      else {
        loopIndex = 1;
        if (0 < node[0x21]) {
          do {
            scannedSourceDef = IRInst__getOperandSource(node,loopIndex);
            unusedMask = ~*(uint *)(scannedSourceDef + 0xc);
            if ((nodeDestMask & (unusedMask << 0x18 | (unusedMask & 0xff00) << 8 | unusedMask >> 8 & 0xff00 |
                         unusedMask >> 0x18)) != 0) {
              a2 = destRegisterOffset;
              argR6 = destRegister;
              IRInst__setHardwareRegisterAndAdd(node,pass,destRegisterOffset,destRegister);
              node[3] = 0;
              if (0 < node[0x21]) {
                loopIndex = 1;
                do {
                  scannedSourceDef = IRInst__getOperandSource(node,loopIndex);
                  fixupInstCount = vec2Count;
                  if ((nodeDestMask & *(uint *)(scannedSourceDef + 0xc)) != 0) {
                    if (vec2Count < vec2Capacity) {
                      slotByteOffset = vec2Count * 4;
                      a2 = ((unsigned char *)0x4);
                      _memset(slotByteOffset + vec2Data,0,4);
                      vec2Count = fixupInstCount + 1;
                      fixupInstSlot = (undefined4 *)(slotByteOffset + vec2Data);
                    }
                    else {
                      fixupInstSlot = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
                    }
                    fixupIndexCountB = vec3Count;
                    *fixupInstSlot = node;
                    if (vec3Count < vec3Capacity) {
                      slotByteOffset = vec3Count * 4;
                      a2 = ((unsigned char *)0x4);
                      _memset(slotByteOffset + vec3Data,0,4);
                      vec3Count = fixupIndexCountB + 1;
                      fixupIndexSlot = (int *)(slotByteOffset + vec3Data);
                    }
                    else {
                      fixupIndexSlot = (int *)Vector__elementRefGrow(&vec3Capacity,vec3Count);
                    }
                    *fixupIndexSlot = loopIndex;
                  }
                  loopIndex = loopIndex + 1;
                } while (loopIndex <= node[0x21]);
              }
              break;
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex <= node[0x21]);
        }
      }
LAB_000f260c:
      walking = false;
      walkInstCount = vec4Count;
      goto LAB_000f26b0;
    }
    a2 = destRegisterOffset;
    argR6 = destRegister;
    IRInst__setHardwareRegisterAndAdd(node,pass,destRegisterOffset,destRegister);
    sourceDef = IRInst__getOperandSource(node,node[0x21]);
    fixupInstCount = vec2Count;
    node[3] = 0;
    if ((nodeDestMask & *(uint *)(sourceDef + 0xc)) == 0) goto LAB_000f260c;
    if (vec2Count < vec2Capacity) {
      fixupInstByteOffset = vec2Count * 4;
      a2 = ((unsigned char *)0x4);
      _memset(fixupInstByteOffset + vec2Data,0,4);
      vec2Count = fixupInstCount + 1;
      fixupInstSlot = (undefined4 *)(fixupInstByteOffset + vec2Data);
    }
    else {
      fixupInstSlot = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
    }
    fixupIndexCount = vec3Count;
    *fixupInstSlot = node;
    lastSourceIndex = node[0x21];
    if (vec3Count < vec3Capacity) {
      slotByteOffset = vec3Count * 4;
      a2 = ((unsigned char *)0x4);
      _memset(slotByteOffset + vec3Data,0,4);
      vec3Count = fixupIndexCount + 1;
      fixupIndexSlot = (int *)(slotByteOffset + vec3Data);
    }
    else {
      fixupIndexSlot = (int *)Vector__elementRefGrow(&vec3Capacity,vec3Count);
    }
    *fixupIndexSlot = lastSourceIndex;
    walking = false;
    walkInstCount = vec4Count;
  } while( true );
}
#undef vec4Capacity
#undef vec4Count
#undef vec4Data
#undef vec4Arena
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena
#undef vec2Capacity
#undef vec2Count
#undef vec2Data
#undef vec2Arena
#undef vec3Capacity
#undef vec3Count
#undef vec3Data
#undef vec3Arena

/* pass_assign_slots @ 0xf29f4 (488 bytes) */
int pass_assign_slots(program)
  int program;
{
  int *instCursorB;
  int *lastKind6Inst;
  int *lastKind7Inst;
  int *nextInstCursor;
  int *instCursor;
  int markerFlag;
  int isStore2;
  int isStore;
  int loopIndex;
  int *hwDescription;
  int isExportHardware;
  undefined4 r4AfterCall;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  int hwVtable;
  int *lastKind7Prev;
  int *lastKind6Prev;
  int *nextInstB;
  int *loopInst;
  
  Program__callBackendFinish(program);
  ((int (*)())Program__beginPass)(program,(int)"assign_slots");
  hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  hwVtable = *hwDescription;
  isExportHardware = (**(code **)(hwVtable + 0xd8))(hwDescription);
  if (isExportHardware == 0) {
    ((int (*)())FUN_000eced0)(program);
    instCursor = *(int **)(*(int *)(program + 0x3a8) + 0x98);
    for (loopInst = (int *)instCursor[2]; loopInst != (int *)0x0; loopInst = (int *)loopInst[2]) {
      isStore = (**(code **)(*instCursor + 0x68))(instCursor);
      if (isStore != 0) {
        if (instCursor[0x51] == 0) {
          ((int (*)())FUN_000f07a8)(program,*(undefined4 *)(program + 0x33c),instCursor);
        }
        else {
          ((int (*)())FUN_000f1d7c)(program,*(undefined4 *)(program + 0x33c),instCursor);
        }
      }
      instCursor = loopInst;
    }
  }
  else {
    ((int (*)())FUN_000ec920)(program);
    ((int (*)())Program__insertExitMarkerAndFlagBlocks)(program,r4AfterCall,staleArgR5,staleArgR6,staleArgR7,staleArgR8,hwVtable);
    instCursorB = *(int **)(*(int *)(program + 0x3a8) + 0x98);
    nextInstCursor = (int *)instCursorB[2];
    if (nextInstCursor == (int *)0x0) {
      lastKind6Inst = (int *)0x0;
      lastKind7Inst = (int *)0x0;
      loopIndex = 0;
    }
    else {
      loopIndex = 0;
      lastKind7Prev = (int *)0x0;
      lastKind6Prev = (int *)0x0;
      do {
        nextInstB = nextInstCursor;
        isStore2 = (**(code **)(*instCursorB + 0x68))(instCursorB);
        lastKind7Inst = lastKind7Prev;
        lastKind6Inst = lastKind6Prev;
        if (((isStore2 != 0) && (lastKind6Inst = instCursorB, instCursorB[0x4f] != 6)) &&
           (lastKind7Inst = instCursorB, lastKind6Inst = lastKind6Prev, instCursorB[0x4f] != 7)) {
          loopIndex = loopIndex + 1;
          ((int (*)())FUN_000f07a8)(program,*(undefined4 *)(program + 0x33c),instCursorB);
          lastKind7Inst = lastKind7Prev;
        }
        nextInstCursor = (int *)nextInstB[2];
        lastKind7Prev = lastKind7Inst;
        lastKind6Prev = lastKind6Inst;
        instCursorB = nextInstB;
      } while (nextInstCursor != (int *)0x0);
    }
    markerFlag = 0;
    if (loopIndex != 0) {
      markerFlag = loopIndex + -1;
    }
    *(int *)(*(int *)(program + 0x33c) + 300) = markerFlag;
    if (lastKind6Inst != (int *)0x0) {
      ((int (*)())FUN_000f14f8)(program,lastKind6Inst,lastKind7Inst);
    }
  }
  *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 0x800;
  ((int (*)())callTargetSlot25)(program);
  return ((int (*)())Program__beginPass)(program,(int)"mark_io");
}

/* SelectWord__compose @ 0xf2bdc (128 bytes) */
int SelectWord__compose(outSelect, innerSelect, outerSelect)
  uint *outSelect;
  undefined4 innerSelect;
  uint outerSelect;
{
  unsigned int ghidra_home[8] = { outSelect, innerSelect, outerSelect, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = innerSelect;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = outerSelect;
  (*(byte *)((unsigned char *)ghidra_home + 10)) = (byte)(outerSelect >> 8);
  (*(byte *)((unsigned char *)ghidra_home + 9)) = (byte)(outerSelect >> 0x10);
  (*(byte *)((unsigned char *)ghidra_home + 8)) = (byte)(outerSelect >> 0x18);
  *outSelect = (uint)(*(byte *)((unsigned char *)ghidra_home + 8)) << 0x18 | (uint)(*(byte *)((unsigned char *)ghidra_home + 9)) << 0x10 | (uint)(*(byte *)((unsigned char *)ghidra_home + 10)) << 8
             | outerSelect & 0xff;
  if ((*(byte *)((unsigned char *)ghidra_home + 8)) < 4) {
    *(undefined1 *)outSelect = *(undefined1 *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 4)) + (uint)(*(byte *)((unsigned char *)ghidra_home + 8)));
  }
  if ((*(byte *)((unsigned char *)ghidra_home + 9)) < 4) {
    *(undefined1 *)((int)outSelect + 1) =
         *(undefined1 *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 4)) + (uint)(*(byte *)((unsigned char *)ghidra_home + 9)));
  }
  if ((*(byte *)((unsigned char *)ghidra_home + 10)) < 4) {
    *(undefined1 *)((int)outSelect + 2) =
         *(undefined1 *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 4)) + (uint)(*(byte *)((unsigned char *)ghidra_home + 10)));
  }
  if (3 < (outerSelect & 0xff)) {
    return;
  }
  *(undefined1 *)((int)outSelect + 3) = *(undefined1 *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 4)) + (outerSelect & 0xff));
  return;
}

/* SelectWord__isSplat @ 0xf2c5c (80 bytes) */
int SelectWord__isSplat(selectWord)
  undefined4 selectWord;
{
  unsigned int ghidra_home[8] = { selectWord, 0, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char laneByte;
  char *laneCursor;
  char splatLane;
  char nextSplatLane;
  int loopCounter;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 0)) = selectWord;
  loopCounter = 4;
  laneCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 0));
  splatLane = '\x04';
  while (((laneByte = *laneCursor, nextSplatLane = splatLane, laneByte == '\x04' || (nextSplatLane = laneByte, splatLane == '\x04')) ||
         (nextSplatLane = splatLane, laneByte == splatLane))) {
    laneCursor = laneCursor + 1;
    loopCounter = loopCounter + -1;
    splatLane = nextSplatLane;
    if (loopCounter == 0) {
      return 1;
    }
  }
  return 0;
}

/* SelectWord__firstUsedComponent @ 0xf2cac (92 bytes) */
int SelectWord__firstUsedComponent(selectWord)
  undefined4 selectWord;
{
  unsigned int ghidra_home[8] = { selectWord, 0, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *laneCursor;
  int loopCounter;
  int loopCounterB;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 0)) = selectWord;
  ((int (*)())SelectWord__isSplat)(selectWord);
  loopCounterB = 4;
  loopCounter = 0;
  laneCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 0));
  do {
    if (*laneCursor != '\x04') {
      return (uint)*(byte *)((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 0)) + loopCounter);
    }
    loopCounter = loopCounter + 1;
    laneCursor = laneCursor + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  return 0xffffffff;
}

/* Lane__isValid @ 0xf2d08 (16 bytes) */
int Lane__isValid(selectByte)
  uint selectByte;
{
  return selectByte < 4;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl ContinueBlock__clone");
asm(".set ContinueBlock__clone, _ContinueBlock__clone");
asm(".globl FUN_000eca10");
asm(".set FUN_000eca10, _KhanVs__vslot17_isSimpleInst");
asm(".globl FUN_000ecad0");
asm(".set FUN_000ecad0, _KhanPs__vslot17_isSimpleInst");
asm(".globl FUN_000ed29c");
asm(".set FUN_000ed29c, _HwLimits__vslot43_prependDefaultMov");
