#include "decls.h"

/* LoopInfo__setCounterPhi @ 0x12b35c (156 bytes) */
int LoopInfo__setCounterPhi(loopInfo, inst)
  undefined4 *loopInfo;
  undefined4 inst;
{
  bool notLastLane;
  int lane;
  undefined4 result;
  int operandRecord;
  
  lane = IRInst__countWrittenComponents(inst);
  result = 0;
  if (lane == 1) {
    loopInfo[0xd] = inst;
    loopInfo[0xe] = 0xffffffff;
    lane = 0;
    do {
      operandRecord = IRInst__getOperandRecord(inst,0);
      if (*(char *)(lane + operandRecord + 0x10) != '\x01') {
        loopInfo[0xe] = lane;
      }
      notLastLane = lane != 3;
      lane = lane + 1;
    } while (notLastLane);
    lane = IRInst__useCount(inst,loopInfo[0x10]);
    result = 1;
    if (lane != 2) {
      *loopInfo = 1;
    }
  }
  return result;
}

/* IRInst__swapCompareOperands @ 0x12b3f8 (272 bytes) */
int IRInst__swapCompareOperands(branchInst, inst, compiler)
  int branchInst;
  int inst;
  uint compiler;
{
  uint branchFlags;
  
  switch(*(undefined4 *)(branchInst + 300)) {
  case 0:
    IROperand__setModifierBits(inst + 0xa4,2,1);
    branchFlags = *(uint *)(inst + 0xb8);
    goto LAB_0012b4b0;
  case 1:
    IROperand__setModifierBits(inst + 0xa4,2,1);
    IROperand__setModifierBits(inst + 0xa4,1,*(uint *)(inst + 0xb8) & 1 ^ 1);
    break;
  case 2:
    IROperand__setModifierBits(inst + 0xa4,1,*(uint *)(inst + 0xb8) & 1 ^ 1);
    break;
  default:
    return;
  case 4:
    break;
  case 5:
    branchFlags = *(uint *)(inst + 0xb8);
LAB_0012b4b0:
    IROperand__setModifierBits(inst + 0xa4,1,branchFlags & 1 ^ 1);
    return;
  }
  IRInst__swapOperands(inst,2,3,compiler);
  return;
}

/* Program__removeUnreachableBlocks @ 0x12b520 (192 bytes) */
int Program__removeUnreachableBlocks(program)
  int program;
{
  int predecessorCount;
  int *nextBlockLink;
  bool removedAny;
  undefined4 *successorPredVector;
  int predecessorBlock;
  int blockPredecessorTotal;
  int entryBlock;
  uint loopIndex;
  int block;
  int nextBlock;
  undefined4 predVectorCopyCapacity;
  undefined4 predVectorCopyCount;
  undefined4 predVectorCopyData;
  undefined4 predVectorCopyArena;
  
  entryBlock = *(int *)(program + 0x3a0);
  do {
    nextBlock = *(int *)(*(int *)(program + 900) + 8);
    if (nextBlock == 0) {
      return;
    }
    removedAny = false;
    block = *(int *)(program + 900);
    do {
      if ((entryBlock != block) && (blockPredecessorTotal = Block__predecessorCount(block), blockPredecessorTotal == 0)) {
        blockPredecessorTotal = 0;
        for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(block + 0xd0) + 4); loopIndex = loopIndex + 1) {
          predecessorBlock = *(int *)(blockPredecessorTotal + *(int *)(*(int *)(block + 0xd0) + 8));
          if (predecessorBlock != 0) {
            successorPredVector = *(undefined4 **)(predecessorBlock + 0xd4);
            predVectorCopyArena = successorPredVector[3];
            predVectorCopyCapacity = *successorPredVector;
            predVectorCopyCount = successorPredVector[1];
            predVectorCopyData = successorPredVector[2];
            Vector__removeValue(&predVectorCopyCapacity,block);
            predecessorCount = Block__predecessorCount(predecessorBlock);
            if (predecessorCount == 0) {
              removedAny = true;
            }
            Arena__free(predVectorCopyArena,predVectorCopyData);
          }
          blockPredecessorTotal = blockPredecessorTotal + 4;
        }
        Block__detach(block);
      }
      nextBlockLink = (int *)(nextBlock + 8);
      block = nextBlock;
      nextBlock = *nextBlockLink;
    } while (*nextBlockLink != 0);
  } while (removedAny);
  return;
}

/* Block__bridgePredecessorToSuccessor @ 0x12b64c (92 bytes) */
int Block__bridgePredecessorToSuccessor(block)
  undefined4 block;
{
  int predecessor;
  int successor;
  
  predecessor = Block__getPredecessor(block,0);
  successor = Block__getSuccessor(block,0);
  *(undefined4 *)(*(int *)(predecessor + 0xd0) + 4) = 0;
  *(undefined4 *)(*(int *)(successor + 0xd4) + 4) = 0;
  return Block__connect(predecessor,successor);
}

/* LoopInfo__convertToHardwareLoop @ 0x12b6a8 (224 bytes) */
int LoopInfo__convertToHardwareLoop(loopInfo, boundOnRight, passThroughR5, passThroughR6, passThroughR7, passThroughR8, passThroughR9)
  int *loopInfo;
  int boundOnRight;
  undefined4 passThroughR5;
  undefined4 passThroughR6;
  undefined4 passThroughR7;
  undefined4 passThroughR8;
  undefined4 passThroughR9;
{
  int predecessorByteOffset;
  undefined4 staleArg4B;
  int footerBlockCursor;
  int bodyBlockCursor;
  int predecessorIndex;
  int keptSuccessor;
  undefined4 staleArg5;
  undefined4 arena;
  int predecessorEntry;
  int constRegister;
  int oldSource;
  int counterUseCount;
  undefined4 *newConstInst;
  undefined4 staleArg4A;
  int *callResult;
  undefined4 staleArg4C;
  undefined4 staleArg4D;
  undefined4 staleArg4E;
  undefined4 *constInst;
  uint predecessorNumber;
  undefined4 conversionResult;
  int inputBase;
  undefined8 predecessor;
  
  constRegister = Emitter__allocateConstantSlot(*(undefined4 *)(loopInfo[0x10] + 0x3ac),3,1,passThroughR6,passThroughR7,passThroughR8,passThroughR9);
  if (constRegister < 0) {
LAB_0012ba38:
    conversionResult = 0;
  }
  else {
    oldSource = IRInst__getOperandSource(loopInfo[0xf],1);
    *(int *)(*(int *)(loopInfo[0xf] + 0x158) + 0x138) =
         *(int *)(*(int *)(loopInfo[0xf] + 0x158) + 0x138) + -1;
    inputBase = *(int *)(loopInfo[0x10] + 0x478);
    counterUseCount = IRInst__useCount(oldSource,loopInfo[0x10]);
    *(int *)(oldSource + 0x160) = inputBase + counterUseCount + -1;
    oldSource = *(int *)(loopInfo[0x10] + 8);
    arena = *(undefined4 *)(oldSource + 0x374);
    newConstInst = (undefined4 *)Arena__alloc(arena,0x168);
    constInst = newConstInst + 1;
    *newConstInst = arena;
    IRLoadConst__ctor_109938(constInst,oldSource);
    Block__appendInst(*(undefined4 *)(loopInfo[0x10] + 0x3a0),constInst);
    newConstInst[0x26] = constRegister;
    newConstInst[0x27] = 4;
    *(byte *)(newConstInst + 0x58) = *(byte *)(newConstInst + 0x58) | 1;
    if (loopInfo[7] == 0) {
      newConstInst[8] = 5;
      newConstInst[9] = loopInfo[4];
      newConstInst[10] = loopInfo[5];
      newConstInst[0xb] = loopInfo[8];
      if (loopInfo[1] == 0) {
        newConstInst[0xc] = loopInfo[2];
      }
      else {
        newConstInst[0xc] = 0xffffffff;
      }
      newConstInst[0xd] = loopInfo[3];
    }
    else {
      if (loopInfo[1] == 0) goto LAB_0012ba38;
      newConstInst[8] = 3;
      newConstInst[9] = loopInfo[6];
    }
    staleArg5 = 0;
    IRInst__setOperandSource(loopInfo[0xf],1,constInst,0,oldSource);
    constRegister = Block__getPredecessor(loopInfo[10],0);
    if (boundOnRight == 0) {
      keptSuccessor = Block__getSuccessor(*(undefined4 *)(loopInfo[10] + 0x13c),0);
    }
    else {
      keptSuccessor = *(int *)(loopInfo[10] + 0x134);
      ((int (*)())Block__bridgePredecessorToSuccessor)(*(undefined4 *)(loopInfo[10] + 0x13c));
    }
    *(undefined4 *)(*(int *)(constRegister + 0xd0) + 4) = 0;
    *(undefined4 *)(*(int *)(keptSuccessor + 0xd4) + 4) = 0;
    Block__connect(constRegister,keptSuccessor);
    constRegister = Block__getSuccessor(loopInfo[9],0);
    predecessorIndex = 0;
    predecessorByteOffset = 0;
    for (predecessorNumber = 1; predecessorNumber <= *(uint *)(*(int *)(constRegister + 0xd4) + 4); predecessorNumber = predecessorNumber + 1) {
      predecessorEntry = *(int *)(*(int *)(*(int *)(constRegister + 0xd4) + 8) + predecessorByteOffset);
      if (predecessorEntry != 0) {
        if (predecessorEntry == loopInfo[9]) {
          Vector__removeAt(*(undefined4 *)(constRegister + 0xd4),predecessorIndex);
          break;
        }
        predecessorIndex = predecessorIndex + 1;
      }
      predecessorByteOffset = predecessorByteOffset + 4;
    }
    if (boundOnRight == 0) {
      bodyBlockCursor = Block__getPredecessor(loopInfo[9],0);
      Block__detach(loopInfo[9]);
      constRegister = loopInfo[10];
      staleArg4A = staleArg4D;
      if (bodyBlockCursor != constRegister) {
        do {
          Block__detach(bodyBlockCursor);
          predecessor = Block__getPredecessor(bodyBlockCursor,0);
          bodyBlockCursor = (int)((ulonglong)predecessor >> 0x20);
          staleArg4A = (undefined4)predecessor;
          constRegister = loopInfo[10];
        } while (constRegister != bodyBlockCursor);
      }
      footerBlockCursor = *(int *)(constRegister + 0x13c);
      if (constRegister != footerBlockCursor) {
        do {
          Block__detach(footerBlockCursor);
          predecessor = Block__getPredecessor(footerBlockCursor,0);
          footerBlockCursor = (int)((ulonglong)predecessor >> 0x20);
          staleArg4A = (undefined4)predecessor;
        } while (footerBlockCursor != loopInfo[10]);
      }
    }
    else {
      Block__detach(*(undefined4 *)(loopInfo[10] + 0x13c));
      staleArg4B = Block__getPredecessor(loopInfo[9],0);
      Block__detach(staleArg4B);
      Block__detach(loopInfo[9]);
      staleArg4A = staleArg4C;
    }
    if (*loopInfo == 0) {
      (**(code **)(*(int *)loopInfo[0xd] + 0xc))
                ((int *)loopInfo[0xd],0,*(undefined4 *)(loopInfo[0x10] + 8));
      predecessorNumber = loopInfo[0x10];
      constInst = *(undefined4 **)(predecessorNumber + 8);
      (**(code **)(*(int *)loopInfo[0xc] + 0xc))((int *)loopInfo[0xc],0);
      staleArg4A = staleArg4E;
    }
    callResult = (int *)Block__getBranchInst(loopInfo[10],staleArg4A,constInst,staleArg5,oldSource,passThroughR8,predecessorNumber);
    if (callResult != (int *)0x0) {
      (**(code **)(*callResult + 0xc))(callResult,0,*(undefined4 *)(loopInfo[0x10] + 8));
      *(undefined4 *)(loopInfo[10] + 0x130) = 0;
    }
    Block__detach(loopInfo[10]);
    conversionResult = 1;
  }
  return conversionResult;
}

/* LoopInfo__init @ 0x12ba58 (240 bytes) */
int LoopInfo__init(loopInfo, header)
  int loopInfo;
  int header;
{
  int inst;
  int nextOrSource;
  
  inst = Block__predecessorCount(header);
  if (((inst == 2) && (*(int *)(header + 0x13c) == 0)) && (0 < *(int *)(header + 0x138))) {
    *(int *)(loopInfo + 0x2c) = header;
    inst = *(int *)(header + 0x98);
    for (nextOrSource = *(int *)(*(int *)(header + 0x98) + 8); nextOrSource != 0; nextOrSource = *(int *)(nextOrSource + 8)) {
      if (((*(uint *)(inst + 0x14) & 1) != 0) && (*(int *)(*(int *)(inst + 0x88) + 8) == 0x81)) {
        nextOrSource = IRInst__getOperandSource(inst,1);
        if ((*(byte *)(nextOrSource + 0x15c) & 1) == 0) {
          return 0;
        }
        if (*(int *)(nextOrSource + 0x1c) != 3) {
          return 0;
        }
        nextOrSource = *(int *)(nextOrSource + 0x20);
        *(int *)(loopInfo + 0x20) = nextOrSource;
        if ((nextOrSource == 0xff) || (nextOrSource == 0xffff)) {
          *(int *)(loopInfo + 0x3c) = inst;
          return 1;
        }
        nextOrSource = *(int *)(inst + 8);
      }
      inst = nextOrSource;
    }
  }
  return 0;
}

/* Program__collapseIfRegion @ 0x12bb48 (296 bytes) */
int Program__collapseIfRegion(pass, block)
  int pass;
  int *block;
{
  int mergedSuccessor;
  int instQuery34c;
  int thenBlockMarked;
  int instQuery34b;
  int *inst;
  int branchInst;
  uint loopIndex;
  bool footerMarkNotSet;
  int *nextInstLink;
  int footerBlock;
  int successorByteOffset;
  int instQuery34;
  undefined4 *allocation;
  undefined4 staleArg4A;
  undefined4 staleArg4B;
  undefined4 staleArg5;
  int *mergedBlockArg;
  undefined4 staleArg6;
  undefined4 staleArg7;
  undefined4 staleArg8;
  code *a6;
  uint branchInstFlags;
  int headerWord37;
  undefined4 arena;
  int thenBlock;
  int elseBlock;
  int *mergedBlock;
  undefined8 branchInst2;
  
  a6 = *(code **)(*block + 0x24);
  (*a6)(block,block,staleArg5,staleArg6,staleArg7,staleArg8,a6);
  if ((block[3] & 0x400U) == 0) {
    thenBlock = block[0x4d];
    elseBlock = block[0x4e];
    branchInst2 = Block__getBranchInst(block,staleArg4A,staleArg5,staleArg6,staleArg7,staleArg8,a6);
    if (((((((int)((ulonglong)branchInst2 >> 0x20) != 0) &&
           (footerBlock = Block__getBranchInst(block,(int)branchInst2,staleArg5,staleArg6,staleArg7,staleArg8,a6),
           *(int *)(*(int *)(footerBlock + 0x88) + 8) == 0x8b)) &&
          (footerBlock = FUN_000e9294(block), footerBlock != 0)) &&
         ((footerBlock = block[0x4f], block[0x43] == 0 && (block[0x44] == 0)))) &&
        ((((block[3] & 0x10U) == 0 &&
          ((*(int *)(footerBlock + 0x10c) == 0 && (*(int *)(footerBlock + 0x110) == 0)))) &&
         ((*(uint *)(footerBlock + 0xc) & 0x10) == 0)))) &&
       ((((*(int *)(thenBlock + 0x10c) == 0 && (*(int *)(thenBlock + 0x110) == 0)) &&
         ((*(uint *)(thenBlock + 0xc) & 0x10) == 0)) &&
        (((*(int *)(elseBlock + 0x10c) == 0 && (*(int *)(elseBlock + 0x110) == 0)) &&
         ((*(uint *)(elseBlock + 0xc) & 0x10) == 0)))))) {
      headerWord37 = block[0x37];
      arena = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arena,0x130);
      *allocation = arena;
      mergedBlock = allocation + 1;
      Block__ctor_ea020(mergedBlock,*(undefined4 *)(pass + 8));
      Program__insertBlockBefore(pass,block,mergedBlock);
      mergedBlockArg = mergedBlock;
      Block__replaceRegionEdges(block,footerBlock,mergedBlock);
      branchInst = Block__getBranchInst(block,staleArg4B,mergedBlockArg,staleArg6,staleArg7,staleArg8,a6);
      block[0x4c] = 0;
      branchInstFlags = *(uint *)(branchInst + 0x14);
      *(undefined4 *)(branchInst + 0x80) = 1;
      *(undefined4 *)(branchInst + 0x94) = 0;
      *(undefined4 *)(branchInst + 0x98) = 0x35;
      *(undefined4 *)(branchInst + 0x9c) = 0;
      *(uint *)(branchInst + 0x14) = branchInstFlags | 0x80000;
      if (headerWord37 != 0) {
        *(uint *)(branchInst + 0x14) = branchInstFlags | 0x81000;
      }
      DList__unlink(branchInst);
      Block__appendInst(mergedBlock,branchInst);
      inst = (int *)block[0x26];
      for (nextInstLink = (int *)((int *)block[0x26])[2]; nextInstLink != (int *)0x0;
          nextInstLink = (int *)nextInstLink[2]) {
        instQuery34b = (**(code **)(*inst + 0x34))(inst);
        if ((instQuery34b == 0) && (instQuery34b = (**(code **)(*inst + 0x38))(inst), instQuery34b == 0)) {
          DList__unlink(inst);
          Block__insertInstBefore(mergedBlock,branchInst,inst);
        }
        inst = nextInstLink;
      }
      thenBlockMarked = *(int *)(thenBlock + 0xdc);
      inst = *(int **)(thenBlock + 0x98);
      for (nextInstLink = (int *)(*(int **)(thenBlock + 0x98))[2]; nextInstLink != (int *)0x0;
          nextInstLink = (int *)nextInstLink[2]) {
        instQuery34 = (**(code **)(*inst + 0x34))(inst);
        if ((instQuery34 == 0) && (instQuery34 = (**(code **)(*inst + 0x38))(inst), instQuery34 == 0)) {
          DList__unlink(inst);
          (**(code **)(*inst + 0x94))(inst,branchInst,*(undefined4 *)(pass + 8));
          (**(code **)(*inst + 0x84))(inst,2);
          Block__appendInst(mergedBlock,inst);
          if (thenBlockMarked != 0) {
            thenBlockMarked = 1;
            if ((inst[5] & 0x10000U) == 0) {
              thenBlockMarked = 0;
              inst[5] = inst[5] | 0x1000;
            }
          }
        }
        inst = nextInstLink;
      }
      inst = *(int **)(elseBlock + 0x98);
      for (nextInstLink = (int *)(*(int **)(elseBlock + 0x98))[2]; nextInstLink != (int *)0x0;
          nextInstLink = (int *)nextInstLink[2]) {
        instQuery34 = (**(code **)(*inst + 0x34))(inst);
        if ((instQuery34 == 0) && (instQuery34 = (**(code **)(*inst + 0x38))(inst), instQuery34 == 0)) {
          DList__unlink(inst);
          (**(code **)(*inst + 0x94))(inst,branchInst,*(undefined4 *)(pass + 8));
          (**(code **)(*inst + 0x84))(inst,3);
          Block__appendInst(mergedBlock,inst);
          if (thenBlockMarked != 0) {
            thenBlockMarked = 1;
            if ((inst[5] & 0x10000U) == 0) {
              thenBlockMarked = 0;
              inst[5] = inst[5] | 0x1000;
            }
          }
        }
        inst = nextInstLink;
      }
      footerMarkNotSet = *(int *)(footerBlock + 0xdc) == 0;
      inst = *(int **)(footerBlock + 0x98);
      for (nextInstLink = (int *)(*(int **)(footerBlock + 0x98))[2]; nextInstLink != (int *)0x0;
          nextInstLink = (int *)nextInstLink[2]) {
        instQuery34c = (**(code **)(*inst + 0x34))(inst);
        if ((instQuery34c == 0) && (instQuery34c = (**(code **)(*inst + 0x38))(inst), instQuery34c == 0)) {
          DList__unlink(inst);
          (**(code **)(*inst + 0x94))(inst,branchInst,*(undefined4 *)(pass + 8));
          Block__appendInst(mergedBlock,inst);
          if (!footerMarkNotSet) {
            if ((inst[5] & 0x10000U) == 0) {
              inst[5] = inst[5] | 0x1000;
              footerMarkNotSet = true;
            }
            else {
              footerMarkNotSet = false;
            }
          }
        }
        inst = nextInstLink;
      }
      if (!footerMarkNotSet) {
        successorByteOffset = 0;
        for (loopIndex = 1; loopIndex <= *(uint *)(allocation[0x35] + 4); loopIndex = loopIndex + 1) {
          mergedSuccessor = *(int *)(*(int *)(allocation[0x35] + 8) + successorByteOffset);
          if (mergedSuccessor != 0) {
            *(undefined4 *)(mergedSuccessor + 0xdc) = 1;
          }
          successorByteOffset = successorByteOffset + 4;
        }
      }
      Block__detach(block);
      Block__detach(thenBlock);
      Block__detach(elseBlock);
      Block__detach(footerBlock);
      block = mergedBlock;
    }
  }
  return block;
}

/* Program__hasKillTexture @ 0x12c0e4 (80 bytes) */
int Program__hasKillTexture(program)
  int program;
{
  int inst;
  int nextInst;
  
  inst = *(int *)(program + 0x98);
  nextInst = *(int *)(*(int *)(program + 0x98) + 8);
  while( true ) {
    if (nextInst == 0) {
      return 0;
    }
    if (((*(uint *)(inst + 0x14) & 1) != 0) && (*(int *)(*(int *)(inst + 0x88) + 8) == 0x77))
    break;
    inst = nextInst;
    nextInst = *(int *)(nextInst + 8);
  }
  return 1;
}

/* FudoPs__vslot69_shouldFlattenIf @ 0x12c134 (424 bytes) */
int FudoPs__vslot69_shouldFlattenIf(this, ifHeader, optionSource, staleArg4, staleArg5, staleArg6, staleArg7)
  undefined4 this;
  int ifHeader;
  undefined4 optionSource;
  undefined4 staleArg4;
  undefined4 staleArg5;
  undefined4 staleArg6;
  undefined4 staleArg7;
{
  int elseNotFlattenable;
  int thenHasKillTexture;
  float thenArmCost;
  float elseCostScratch;
  float largerCost;
  int isIfRegion;
  uint listCount;
  uint listCount2;
  undefined4 armLimitKind;
  int elseBlock;
  int thenBlock;
  double intToDoubleBias;
  undefined8 optionResult;
  
  isIfRegion = FUN_000e9294(ifHeader);
  if (isIfRegion != 0) {
    thenBlock = *(int *)(ifHeader + 0x134);
    elseBlock = *(int *)(ifHeader + 0x138);
    thenHasKillTexture = ((int (*)())Program__hasKillTexture)(thenBlock);
    if ((thenHasKillTexture == 0) && (thenHasKillTexture = ((int (*)())Program__hasKillTexture)(elseBlock), thenHasKillTexture == 0)) {
      armLimitKind = 3;
      optionResult = FUN_000e0830(optionSource,0,3);
      if ((int)((ulonglong)optionResult >> 0x20) == 0) {
        if ((*(uint *)(ifHeader + 0xc) & 0x800) == 0) {
          optionResult = Block__hasInstWithQuery28(thenBlock,(int)optionResult,armLimitKind,staleArg4,staleArg5,staleArg6,staleArg7);
          if ((int)((ulonglong)optionResult >> 0x20) != 0) {
            return 0;
          }
          elseNotFlattenable = Block__hasInstWithQuery28(elseBlock,(int)optionResult,armLimitKind,staleArg4,staleArg5,staleArg6,staleArg7);
          if (elseNotFlattenable != 0) {
            return 0;
          }
          listCount = DList__count(thenBlock + 0x90);
          intToDoubleBias = DOUBLE_001aa1e0;
          elseCostScratch = FLOAT_001aa108;
          listCount2 = DList__count(elseBlock + 0x90);
          thenArmCost = (float)((double)CONCAT44(0x43300000,listCount ^ 0x80000000) - intToDoubleBias) - elseCostScratch;
        }
        else {
          listCount = DList__count(thenBlock + 0x90);
          intToDoubleBias = DOUBLE_001aa1e0;
          elseCostScratch = FLOAT_001aa108;
          listCount2 = DList__count(elseBlock + 0x90);
          thenArmCost = (float)((double)CONCAT44(0x43300000,listCount ^ 0x80000000) - intToDoubleBias) - elseCostScratch;
        }
        elseCostScratch = (float)((double)CONCAT44(0x43300000,listCount2 ^ 0x80000000) - intToDoubleBias) - elseCostScratch;
        largerCost = thenArmCost;
        if (thenArmCost - elseCostScratch < 0.0) {
          largerCost = elseCostScratch;
        }
        if (-(thenArmCost - elseCostScratch) < 0.0) {
          elseCostScratch = largerCost;
        }
        if (FLOAT_001aa1bc < elseCostScratch) {
          return 0;
        }
      }
      return 1;
    }
  }
  return 0;
}

/* Program__isTrivialBranchRegion @ 0x12c2dc (244 bytes) */
int Program__isTrivialBranchRegion(program, block)
  int program;
  int block;
{
  int vtableQueryResult;
  int branchInst;
  int listCount;
  int successor;
  int successorBlock;
  int successorInstCount;
  int *successor2;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined8 successor3;
  
  if ((0 < *(int *)(block + 0x138)) || (*(int *)(block + 0x13c) != 0)) {
    successor = Block__getSuccessor(block,0);
    listCount = DList__count(successor + 0x90);
    if (listCount < 3) {
      successor2 = (int *)Block__getSuccessor(successor,0);
      successorInstCount = (**(code **)(*successor2 + 0x24))(successor2);
      if (successorInstCount != 0) {
        successor3 = Block__getSuccessor(successor,0);
        successorBlock = (int)((ulonglong)successor3 >> 0x20);
        branchInst = Block__getBranchInst(successorBlock,(int)successor3,in_r5,in_r6,in_r7,in_r8,in_r9);
        if ((((*(uint *)(program + 0x30) & 8) == 0) && (*(int *)(branchInst + 0x84) == 2)) &&
           (*(int *)(branchInst + 0xa4) == *(int *)(branchInst + 0xbc))) {
          successor2 = (int *)Block__getSuccessor(*(undefined4 *)(successorBlock + 0x134),0);
          vtableQueryResult = (**(code **)(*successor2 + 0x38))(successor2);
          if (vtableQueryResult != 0) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* Program__rebaseInstRegisters @ 0x12c3d0 (460 bytes) */
int Program__rebaseInstRegisters(inst, registerBase, program)
  int *inst;
  int registerBase;
  int program;
{
  undefined4 registerFileKind;
  undefined4 rebasedDestRef;
  int *newDestVReg;
  int operandKindClass;
  int instQuery18;
  int definingField128;
  int definingField1282;
  int operandRecord;
  undefined4 vregList;
  int operandCountLimit;
  int *operandSlotCursor;
  code *destRebaseFn;
  int operandNumber;
  undefined4 vregListB;
  
  operandNumber = 1;
  operandSlotCursor = inst;
  do {
    operandCountLimit = (**(code **)(*inst + 0x14))(inst);
    if (operandCountLimit < operandNumber) {
      instQuery18 = (**(code **)(*inst + 0x18))(inst);
      if ((instQuery18 == 1) && (instQuery18 = IRInst__operandKindClass(inst,0), instQuery18 == 1)) {
        vregListB = *(undefined4 *)(program + 0x3ac);
        definingField128 = IRInst__getDefiningField128(inst,0);
        newDestVReg = (int *)VRegPool__findOrCreate(vregListB,0x24,definingField128 + registerBase,0);
        destRebaseFn = *(code **)(*newDestVReg + 0x28);
        operandRecord = IRInst__getOperandRecord(inst,0);
        rebasedDestRef = (*destRebaseFn)(newDestVReg,*(undefined4 *)(operandRecord + 0x10),program);
        IRInst__setOperandRef(inst,0,rebasedDestRef);
        if ((inst[5] & 2U) == 0) {
          inst[5] = inst[5] & 0xffffffef;
          Program__removeInst(program,inst);
          return;
        }
      }
      return;
    }
    operandKindClass = IRInst__operandKindClass(inst,operandNumber);
    if (operandKindClass == 1) {
      definingField1282 = IRInst__getDefiningField128(inst,operandNumber);
      if (operandSlotCursor[0x2c] == 0x28) {
        vregList = *(undefined4 *)(program + 0x3ac);
        registerFileKind = 2;
      }
      else {
        if (operandSlotCursor[0x2c] != 0x29) goto LAB_0012c498;
        if ((*(uint *)(program + 0x30) & 1) == 0) {
          if ((*(uint *)(program + 0x30) & 0x2000) == 0) goto LAB_0012c498;
          vregList = *(undefined4 *)(program + 0x3ac);
          registerFileKind = 0x24;
        }
        else {
          registerFileKind = Program__registerFileOfIlType(program,5);
          vregList = *(undefined4 *)(program + 0x3ac);
        }
      }
      registerFileKind = VRegPool__findOrCreate(vregList,registerFileKind,registerBase + definingField1282,0);
      IRInst__setOperandRef(inst,operandNumber,registerFileKind);
    }
LAB_0012c498:
    operandNumber = operandNumber + 1;
    operandSlotCursor = operandSlotCursor + 6;
  } while( true );
}

/* LoopInfo__matchCounterInit @ 0x12c59c (548 bytes) */
int LoopInfo__matchCounterInit(loopInfo, inst)
  int loopInfo;
  int *inst;
{
  int *operandVReg;
  uint lane;
  int index;
  int sourceCount;
  int *byteCursor;
  undefined4 operandSwizzleBytes [6];
  
  index = (**(code **)(*inst + 100))(inst,inst);
  if (index != 0) {
    for (index = 1; sourceCount = (**(code **)(*inst + 0x14))(inst), index <= sourceCount;
        index = index + 1) {
      if ((inst[index * 6 + 0x28] & 1U) != 0) {
        return 0;
      }
      if ((inst[index * 6 + 0x28] & 2U) != 0) {
        return 0;
      }
      sourceCount = IRInst__isSourceSelectIdentity(inst,index);
      if (sourceCount == 0) {
        return 0;
      }
    }
    if ((inst[0x48] == 0) && (inst[0x49] == 0)) {
      if ((inst[0x20] != 0) &&
         (((index = RegKind__flagBit0(inst[0x26]), index != 0 && ((inst[5] & 2U) == 0)) &&
          (index = (**(code **)(*inst + 0x50))(inst), index == 0)))) {
        index = 4;
        byteCursor = inst;
        do {
          if ((uint)(*(byte *)(byteCursor + 0x27) - 2) < 2) {
            return 0;
          }
          byteCursor = (int *)((int)byteCursor + 1);
          index = index + -1;
        } while (index != 0);
      }
      IRInst__getOperandRecord(inst,0);
      index = IRInst__operandKindClass(inst,0);
      if (((index == 0) && ((inst[5] & 2U) == 0)) && ((inst[5] & 0x200U) == 0)) {
        operandVReg = (int *)IRInst__getOperandSource(inst,1);
        index = (**(code **)(*operandVReg + 0x48))(operandVReg);
        if (index != 0) {
          index = IRInst__getOperandRecord(inst,1);
          operandSwizzleBytes[0] = *(undefined4 *)(index + 0x10);
          lane = (uint)*(byte *)((int)operandSwizzleBytes + *(int *)(loopInfo + 0x38));
          if (((int)*(char *)(operandVReg + 0x57) >> (lane & 0x3f) & 1U) == 0) {
            *(undefined4 *)(loopInfo + 4) = 0;
            *(uint *)(loopInfo + 0xc) = lane;
            *(int *)(loopInfo + 8) = operandVReg[0x25];
            return 1;
          }
          if ((operandVReg[lane * 6 + 7] == 2) && (GH_U2F((unsigned int)(operandVReg[lane * 6 + 8])) == 0.0)) {
            *(undefined4 *)(loopInfo + 4) = 1;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* LoopInfo__matchCounterStep @ 0x12c7c0 (328 bytes) */
int LoopInfo__matchCounterStep(loopInfo, inst)
  undefined4 *loopInfo;
  int inst;
{
  int loopIndex2;
  bool moreLanes;
  uint lane;
  int operandRecord;
  int *stepOperand;
  int counterLane;
  int useCountOrSource;
  int loopIndex;
  undefined4 operandSwizzleBytes [8];
  
  if (*(int *)(*(int *)(inst + 0x88) + 8) == 0x12) {
    loopIndex2 = 0;
    counterLane = -1;
    loopIndex = 0;
    do {
      operandRecord = IRInst__getOperandRecord(inst,0);
      if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
        counterLane = loopInfo[0xe];
        loopIndex2 = loopIndex2 + 1;
        if (counterLane != loopIndex) {
          return 0;
        }
        if (1 < loopIndex2) {
          return 0;
        }
      }
      moreLanes = loopIndex != 3;
      loopIndex = loopIndex + 1;
    } while (moreLanes);
    useCountOrSource = IRInst__useCount(inst,loopInfo[0x10]);
    if (1 < useCountOrSource) {
      *loopInfo = 1;
    }
    useCountOrSource = IRInst__getOperandSource(loopInfo[0xd],1);
    if (inst == useCountOrSource) {
      stepOperand = (int *)IRInst__getOperandSource(useCountOrSource,2);
      useCountOrSource = (**(code **)(*stepOperand + 0x48))(stepOperand);
      if (useCountOrSource != 0) {
        useCountOrSource = IRInst__getOperandRecord(inst,2);
        operandSwizzleBytes[0] = *(undefined4 *)(useCountOrSource + 0x10);
        lane = (uint)*(byte *)((int)operandSwizzleBytes + counterLane);
        if (((((int)*(char *)(stepOperand + 0x57) >> (lane & 0x3f) & 1U) != 0) && (stepOperand[lane * 6 + 7] == 2))
           && (GH_U2F((unsigned int)(stepOperand[lane * 6 + 8])) == 1.0)) {
          return 1;
        }
      }
    }
  }
  return 0;
}

/* LoopInfo__matchExit @ 0x12c908 (952 bytes) */
int LoopInfo__matchExit(loopInfo, inst, branchHeader, outBoundOnRight)
  int loopInfo;
  int inst;
  int branchHeader;
  int *outBoundOnRight;
{
  int exitBlockQuery38;
  int *counterOperand;
  int *boundOperand;
  undefined4 innerCompare;
  int footerSuccessorIsSimple;
  int exitSuccessorQuery38;
  int elseIsSimple;
  int thenBlock;
  int innerRecord2;
  int innerRecord1;
  int testOperandRecord;
  int compareUseCount;
  int rightQuery48;
  int leftQuery48;
  int boundOperandRecord;
  int exitCompareCondition;
  int boundQuery48;
  int counterSource;
  int compareCondition;
  undefined4 successor2;
  int *successor;
  byte boundLaneSwizzle;
  float constantBound;
  int compareOpcode;
  undefined4 vregList;
  int *operandVReg;
  int *boundDefinition;
  int *staleOutFlagRef;
  int callResult;
  uint lane;
  int elseBlock;
  undefined4 swizzleWord;
  int constVectorWord;
  byte laneSwizzleBytes [8];
  longlong boundAsInt64;
  
  *outBoundOnRight = 0;
  if (inst == 0) {
    return 0;
  }
  compareOpcode = *(int *)(*(int *)(inst + 0x88) + 8);
  if (compareOpcode == 0x8b) {
    staleOutFlagRef = outBoundOnRight;
    counterSource = IRInst__getOperandSource(inst,1);
    if (counterSource != *(int *)(loopInfo + 0x34)) {
      return 0;
    }
    boundDefinition = (int *)IRInst__getOperandSource(inst,2);
    boundQuery48 = (**(code **)(*boundDefinition + 0x48))(boundDefinition);
    if (boundQuery48 == 0) {
      return 0;
    }
    exitCompareCondition = IRInst__getCompareCondition(inst);
    if (exitCompareCondition != 3) {
      return 0;
    }
    boundOperandRecord = IRInst__getOperandRecord(inst,2);
    swizzleWord = *(undefined4 *)(boundOperandRecord + 0x10);
    boundLaneSwizzle = *(byte *)((int)&swizzleWord + *(int *)(loopInfo + 0x38));
    lane = (uint)boundLaneSwizzle;
    *(uint *)(loopInfo + 0x14) = lane;
    if (boundDefinition[0x26] == 0x33) {
      constVectorWord = boundDefinition[lane * 6 + 8];
      vregList = *(undefined4 *)(*(int *)(loopInfo + 0x40) + 0x3ac);
      laneSwizzleBytes[0] = 4;
      laneSwizzleBytes[1] = 4;
      laneSwizzleBytes[2] = 4;
      laneSwizzleBytes[3] = 4;
      laneSwizzleBytes[lane] = boundLaneSwizzle;
      boundDefinition = (int *)RegisterMap__findConstVector(vregList,&constVectorWord,laneSwizzleBytes,staleOutFlagRef);
      *(uint *)(loopInfo + 0x14) = (uint)laneSwizzleBytes[*(int *)(loopInfo + 0x14)];
      if (boundDefinition == (int *)0x0) {
        return 0;
      }
    }
    *(int *)(loopInfo + 0x10) = boundDefinition[0x25];
  }
  else {
    if (compareOpcode != 0x8c) {
      return 0;
    }
    innerCompare = IRInst__getOperandSource(inst,1);
    operandVReg = (int *)IRInst__getOperandSource(innerCompare,1);
    counterOperand = (int *)IRInst__getOperandSource(innerCompare,2);
    leftQuery48 = (**(code **)(*operandVReg + 0x48))(operandVReg);
    boundOperand = operandVReg;
    if (leftQuery48 == 0) {
      rightQuery48 = (**(code **)(*counterOperand + 0x48))(counterOperand);
      if (rightQuery48 == 0) {
        return 0;
      }
      *outBoundOnRight = 1;
      boundOperand = counterOperand;
      counterOperand = operandVReg;
    }
    if (counterOperand != *(int **)(loopInfo + 0x34)) {
      return 0;
    }
    compareUseCount = IRInst__useCount(innerCompare,*(undefined4 *)(loopInfo + 0x40));
    if (compareUseCount != 1) {
      return 0;
    }
    compareCondition = IRInst__getCompareCondition(innerCompare);
    if (*outBoundOnRight == 0) {
      if (compareCondition != 2) {
        return 0;
      }
    }
    else if (compareCondition != 3) {
      return 0;
    }
    *(undefined4 *)(loopInfo + 0x1c) = 0;
    if ((*(byte *)(boundOperand + 0x57) & 1) == 0) {
      *(int *)(loopInfo + 0x10) = boundOperand[0x25];
      testOperandRecord = IRInst__getOperandRecord(inst,1);
      swizzleWord = *(undefined4 *)(testOperandRecord + 0x10);
      *(uint *)(loopInfo + 0x14) = (uint)*(byte *)((int)&swizzleWord + *(int *)(loopInfo + 0x38));
      if (*outBoundOnRight == 0) {
        innerRecord1 = IRInst__getOperandRecord(innerCompare,1);
        swizzleWord = *(undefined4 *)(innerRecord1 + 0x10);
      }
      else {
        innerRecord2 = IRInst__getOperandRecord(innerCompare,2);
        swizzleWord = *(undefined4 *)(innerRecord2 + 0x10);
      }
      *(uint *)(loopInfo + 0x14) = (uint)*(byte *)((int)&swizzleWord + *(int *)(loopInfo + 0x14));
    }
    else {
      constantBound = GH_U2F((unsigned int)(boundOperand[8]));
      *(undefined4 *)(loopInfo + 0x1c) = 1;
      boundAsInt64 = (longlong)(int)constantBound;
      *(int *)(loopInfo + 0x18) = (int)constantBound;
    }
  }
  thenBlock = *(int *)(branchHeader + 0x134);
  elseBlock = *(int *)(branchHeader + 0x138);
  if (*outBoundOnRight == 0) {
    callResult = DList__count(thenBlock + 0x90);
    if ((callResult < 3) && (elseBlock = DList__count(elseBlock + 0x90), elseBlock < 3)) {
      successor = (int *)Block__getSuccessor(thenBlock,0);
      exitBlockQuery38 = (**(code **)(*successor + 0x38))(successor);
      if (exitBlockQuery38 != 0) {
        successor2 = Block__getSuccessor(thenBlock,0);
        *(undefined4 *)(loopInfo + 0x24) = successor2;
LAB_0012cc9c:
        *(int *)(loopInfo + 0x28) = branchHeader;
        return 1;
      }
    }
  }
  else {
    elseIsSimple = Block__isSimple(elseBlock);
    if ((elseIsSimple != 0) && (elseIsSimple = DList__count(elseBlock + 0x90), elseIsSimple < 3)) {
      successor = (int *)Block__getSuccessor(elseBlock,0);
      *(int **)(loopInfo + 0x24) = successor;
      exitSuccessorQuery38 = (**(code **)(*successor + 0x38))(successor);
      if (exitSuccessorQuery38 != 0) {
        successor2 = Block__getSuccessor(*(undefined4 *)(branchHeader + 0x13c),0);
        footerSuccessorIsSimple = Block__isSimple(successor2);
        if ((footerSuccessorIsSimple != 0) &&
           (footerSuccessorIsSimple = Block__getSuccessor(successor2,0), footerSuccessorIsSimple == *(int *)(*(int *)(loopInfo + 0x2c) + 0x150)))
        goto LAB_0012cc9c;
      }
    }
  }
  return 0;
}

/* pass_loop_trans @ 0x12ccc0 (740 bytes) */
int pass_loop_trans(program)
  int program;
{
  int *footerCursor;
  int *staleFooterArg;
  undefined4 staleArg4;
  undefined4 counterStepSource;
  bool changed;
  int nextInst;
  int phiInst;
  int counterInitMatched;
  undefined4 counterInitSource;
  int *exitCandidateBlock;
  undefined4 staleArg4A;
  undefined4 staleArg4B;
  int *exitBlock;
  int *boundOnRightPtr;
  undefined4 staleArg7;
  undefined4 staleArg8;
  undefined4 staleArg9;
  int *nextBlockLink;
  int *nextBlock;
  int *block;
  int boundOnRight;
  int loopInfo [12];
  undefined4 loopInfoCounterInit;
  int loopInfoProgram;
  
  nextBlockLink = (int *)(*(int **)(program + PROG_blockListHead))[2];
  if (nextBlockLink != (int *)0x0) {
    changed = false;
    block = *(int **)(program + PROG_blockListHead);
    loopInfoProgram = program;
    do {
      nextBlock = nextBlockLink;
      phiInst = (**(code **)(*block + 0x2c))(block);
      if ((phiInst != 0) && (phiInst = ((int (*)())LoopInfo__init)(loopInfo,block), phiInst != 0)) {
        loopInfo[0] = 0;
        phiInst = block[0x26];
        for (nextInst = *(int *)(block[0x26] + 8); nextInst != 0; nextInst = *(int *)(nextInst + 8)) {
          if ((*(int *)(*(int *)(phiInst + 0x88) + 8) == 0x8e) &&
             (counterInitMatched = ((int (*)())LoopInfo__setCounterPhi)(loopInfo,phiInst), counterInitMatched != 0)) {
            counterInitSource = IRInst__getOperandSource(phiInst,2);
            counterInitMatched = ((int (*)())LoopInfo__matchCounterInit)(loopInfo,counterInitSource);
            if (counterInitMatched != 0) {
              counterStepSource = IRInst__getOperandSource(phiInst,1);
              phiInst = ((int (*)())LoopInfo__matchCounterStep)(loopInfo,counterStepSource);
              if (phiInst != 0) {
                loopInfoCounterInit = counterStepSource;
                exitCandidateBlock = (int *)Block__getSuccessor(block,0);
                phiInst = (**(code **)(*exitCandidateBlock + 0x24))(exitCandidateBlock);
                staleArg4 = staleArg4A;
                staleFooterArg = exitBlock;
                if (phiInst == 0) {
                  phiInst = Block__isSimple(exitCandidateBlock);
                  if (phiInst != 0) {
                    phiInst = DList__count(exitCandidateBlock + 0x24);
                    if ((phiInst < 3) || (phiInst = DList__count(exitCandidateBlock + 0x24), phiInst == 3)) {
                      exitCandidateBlock = (int *)Block__getSuccessor(exitCandidateBlock,0);
                      phiInst = (**(code **)(*exitCandidateBlock + 0x24))(exitCandidateBlock);
                      staleArg4 = staleArg4B;
                      staleFooterArg = exitBlock;
                      if (phiInst != 0) goto LAB_0012ce40;
                    }
                  }
                }
                else {
LAB_0012ce40:
                  exitBlock = exitCandidateBlock;
                  staleArg4 = Block__getBranchInst(exitBlock,staleArg4,staleFooterArg,boundOnRightPtr,staleArg7,staleArg8,staleArg9);
                  footerCursor = (int *)exitBlock[0x4f];
                  boundOnRightPtr = &boundOnRight;
                  boundOnRight = 0;
                  phiInst = ((int (*)())LoopInfo__matchExit)(loopInfo,staleArg4,exitBlock,boundOnRightPtr);
                  if (phiInst != 0) {
                    if ((boundOnRight == 0) && (exitCandidateBlock = (int *)block[0x54], footerCursor != exitCandidateBlock)) {
                      phiInst = 0;
                      do {
                        counterInitMatched = (**(code **)(*footerCursor + 0x2c))(footerCursor);
                        if (counterInitMatched == 0) {
                          counterInitMatched = (**(code **)(*footerCursor + 0x30))(footerCursor);
                          if (counterInitMatched == 0) {
                            if (phiInst == 0) {
                              (**(code **)(*footerCursor + 0x38))(footerCursor);
                            }
                          }
                          else {
                            phiInst = phiInst + -1;
                          }
                        }
                        else {
                          phiInst = phiInst + 1;
                        }
                        footerCursor = (int *)footerCursor[2];
                      } while (exitCandidateBlock != footerCursor);
                    }
                    phiInst = ((int (*)())LoopInfo__convertToHardwareLoop)(loopInfo,boundOnRight,exitBlock,boundOnRightPtr,staleArg7,staleArg8,staleArg9);
                    changed = changed || phiInst != 0;
                    if (phiInst != 0) {
                      Program__beginPass(program,(int)"loop_trans");
                    }
                  }
                }
              }
            }
          }
          phiInst = nextInst;
        }
      }
      nextBlockLink = (int *)nextBlock[2];
      block = nextBlock;
    } while (nextBlockLink != (int *)0x0);
    if (changed) {
      Program__freeWorkArrays(program);
      Program__eliminateDeadInstsAndRecountUses(program,0);
      return 1;
    }
  }
  return 0;
}

/* Program__removeDeadRegion @ 0x12cfa4 (820 bytes) */
int Program__removeDeadRegion(program, headerBlock, deadRegionEntry, footerBlock)
  int program;
  int *headerBlock;
  undefined4 deadRegionEntry;
  int *footerBlock;
{
  int deadBlock;
  uint successorNumber;
  uint lastWorkIndex;
  int successorByteOffset;
  int operandNumber;
  undefined4 *workSlotRefB;
  int *footerPhi;
  int *nextInstLinkB;
  int *operandSlotCursor;
  int *footerInst;
  int *successorBlock;
  int *deadInst;
  uint workCountAfterCheck;
  int *workTopRef;
  int *nextInstLinkA;
  undefined4 *workSlotRefA;
  int instQuery34;
  int operandCountOrSuccessors;
  uint workCountSnapshot;
  int workByteOffset;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_54_buf [0x10];
  #define vecCapacity (*(uint *)(local_54_buf + 0x00))
  #define vecCount (*(uint *)(local_54_buf + 0x04))
  #define vecData (*(int *)(local_54_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_54_buf + 0x0c))
  
  vecArena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  workCountSnapshot = vecCount;
  if (vecCount < vecCapacity) {
    workByteOffset = vecCount * 4;
    _memset(vecData + workByteOffset,0,4);
    vecCount = workCountSnapshot + 1;
    workSlotRefA = (undefined4 *)(workByteOffset + vecData);
  }
  else {
    workSlotRefA = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
  }
  *workSlotRefA = deadRegionEntry;
  while (vecCount != 0) {
    lastWorkIndex = vecCount - 1;
    workTopRef = (int *)0x0;
    if (lastWorkIndex < vecCount) {
      workTopRef = (int *)(lastWorkIndex * 4 + vecData);
    }
    deadBlock = *workTopRef;
    Vector__removeAt(&vecCapacity,lastWorkIndex);
    deadInst = *(int **)(deadBlock + 0x98);
    for (nextInstLinkA = (int *)deadInst[2]; nextInstLinkA != (int *)0x0; nextInstLinkA = (int *)nextInstLinkA[2]) {
      if ((deadInst[5] & 1U) != 0) {
        instQuery34 = (**(code **)(*deadInst + 0x34))(deadInst);
        if ((instQuery34 == 0) && (instQuery34 = (**(code **)(*deadInst + 0x38))(deadInst), instQuery34 == 0)) {
          if (*(int *)(deadInst[0x22] + 8) != 0x8e) {
            operandSlotCursor = deadInst;
            for (operandNumber = 1; operandCountOrSuccessors = (**(code **)(*deadInst + 0x14))(deadInst), operandNumber <= operandCountOrSuccessors;
                operandNumber = operandNumber + 1) {
              Owner__removeVectorEntry(operandSlotCursor[0x29],deadInst);
              operandSlotCursor = operandSlotCursor + 6;
            }
          }
          (**(code **)(*deadInst + 0xc))(deadInst,0,*(undefined4 *)(program + 8));
        }
        nextInstLinkA = (int *)deadInst[2];
      }
      deadInst = nextInstLinkA;
    }
    successorByteOffset = 0;
    for (successorNumber = 1; operandCountOrSuccessors = *(int *)(deadBlock + 0xd0), successorNumber <= *(uint *)(operandCountOrSuccessors + 4); successorNumber = successorNumber + 1
        ) {
      successorBlock = *(int **)(*(int *)(operandCountOrSuccessors + 8) + successorByteOffset);
      if ((((successorBlock != (int *)0x0) && (successorBlock != footerBlock)) && (successorBlock != headerBlock)) &&
         (((operandCountOrSuccessors = (**(code **)(*successorBlock + 0x38))(successorBlock), operandCountOrSuccessors == 0 &&
           (operandCountOrSuccessors = (**(code **)(*successorBlock + 0x3c))(successorBlock), operandCountOrSuccessors == 0)) &&
          (operandCountOrSuccessors = DList__count(successorBlock + 0x24), workCountAfterCheck = vecCount, 2 < operandCountOrSuccessors)))) {
        if (vecCount < vecCapacity) {
          operandCountOrSuccessors = vecCount * 4;
          _memset(operandCountOrSuccessors + vecData,0,4);
          vecCount = workCountAfterCheck + 1;
          workSlotRefB = (undefined4 *)(operandCountOrSuccessors + vecData);
        }
        else {
          workSlotRefB = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
        }
        *workSlotRefB = successorBlock;
      }
      successorByteOffset = successorByteOffset + 4;
    }
  }
  vecCount = 0;
  footerInst = (int *)footerBlock[0x26];
  for (nextInstLinkB = (int *)((int *)footerBlock[0x26])[2]; nextInstLinkB != (int *)0x0; nextInstLinkB = (int *)nextInstLinkB[2]) {
    if ((footerInst[5] & 1U) != 0) {
      footerPhi = (int *)(**(code **)(*footerInst + 0x7c))(footerInst);
      if (footerPhi != (int *)0x0) {
        (**(code **)(*footerPhi + 0xc))(footerPhi,0,*(undefined4 *)(program + 8));
      }
      nextInstLinkB = (int *)footerInst[2];
    }
    footerInst = nextInstLinkB;
  }
  DList__count(footerBlock + 0x24);
  return Arena__free(vecArena,vecData);
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* pass_flatten_ifs @ 0x12d2f0 (1988 bytes) */
int pass_flatten_ifs(flattenPass)
  int flattenPass;
{
  undefined8 predElementRefPair;
  int walkSuccessor;
  int inputBase;
  int laneCountdown;
  int thenBlock;
  undefined4 compilerArg;
  undefined4 defaultSelectSwizzle;
  int walkBlock;
  int instQuery38;
  int instQuery34b;
  int conditionHasNoUses;
  int instQuery34;
  int selectSource3Record;
  int selectSource2Record;
  int selectSource1Record;
  int phiSlotOffset;
  int phiSource2Record;
  int phiSource1Record;
  int laneByteIndex;
  int phiDestRecord;
  int conditionDefOpcode;
  int operandNumber;
  int compiler;
  int *trailingInstCursor;
  int *branchInst;
  int *thenBlockVectorAtD4;
  int *predecessorVector;
  int *elseBlockVectorAtd4;
  int *thenEndBlockVectorAtd0;
  int *elseEndBlockVectorAtd0;
  int *blockAfterIfVectorAtd4;
  int *blockBeforeIfVectorAtd0;
  int *ifHeaderVectorAtd4;
  int compareCondition;
  int isOperandConstZero;
  undefined4 operandRecord2;
  int operandRecord3;
  int operandRecord;
  int *operandVReg;
  bool changedAny;
  int *phiInst;
  int *nextInst;
  undefined4 savedConditionSwizzle;
  int blockQuery28;
  int targetCanFlatten;
  uint conditionNegate;
  int *conditionSource;
  undefined4 phiSource1;
  undefined4 phiSource2;
  undefined4 staleArg4b;
  uint staleArg6;
  undefined4 staleArg7;
  undefined4 staleArg8;
  int blockBeforeIfCopy;
  code *releaseFn;
  undefined4 staleArg4;
  uint conditionAbs;
  undefined4 phiSource2Swizzle;
  int ifHeader;
  undefined4 phiSource1Swizzle;
  int *insertAfterInst;
  int blockAfterIf;
  int *block;
  int elseBlock;
  int thenEndBlock;
  int *nextBlock;
  uint *footerPredVector;
  uint *footerPredVectorAlias;
  int elseEndBlock;
  undefined8 canFlattenResult;
  undefined1 canFlattenOut [4];
  undefined4 conditionSwizzle;
  int destMaskWord [2];
  int blockBeforeIf;
  int *blockInstSentinel;
  
  block = *(int **)(flattenPass + 900);
  nextBlock = (int *)block[2];
  if (nextBlock != (int *)0x0) {
    changedAny = false;
    do {
      blockQuery28 = (**(code **)(*block + 0x28))(block);
      if ((blockQuery28 != 0) && (blockQuery28 = (**(code **)(*block + 0x40))(block), blockQuery28 == 0)) {
        compiler = *(int *)(flattenPass + 8);
        if (*(int *)(compiler + 0x6a8) <= *(int *)(*(int *)(compiler + 0x6c4) + 0x15c)) break;
        ifHeader = block[0x4b];
        targetCanFlatten = (**(code **)(**(int **)(compiler + 0x30c) + 0x114))(*(int **)(compiler + 0x30c),ifHeader);
        if (targetCanFlatten == 0) break;
        canFlattenResult = IfHeader__canFlatten(ifHeader,canFlattenOut);
        if ((int)((ulonglong)canFlattenResult >> 0x20) != 0) break;
        footerPredVector = (uint *)block[0x35];
        thenBlock = *(int *)(ifHeader + 0x134);
        elseBlock = *(int *)(ifHeader + 0x138);
        if (*footerPredVector == 0) {
          canFlattenResult = Vector__elementRefGrow(footerPredVector,0);
          footerPredVectorAlias = (uint *)block[0x35];
        }
        else {
          footerPredVectorAlias = footerPredVector;
          if (footerPredVector[1] == 0) {
            *(undefined4 *)footerPredVector[2] = 0;
            footerPredVector[1] = 1;
            footerPredVectorAlias = (uint *)block[0x35];
          }
          canFlattenResult = CONCAT44(footerPredVector[2],(int)canFlattenResult);
        }
        staleArg4 = (undefined4)canFlattenResult;
        thenEndBlock = *(int *)((ulonglong)canFlattenResult >> 0x20);
        if (*footerPredVectorAlias < 2) {
          predElementRefPair = Vector__elementRefGrow(footerPredVectorAlias,1);
        }
        else {
          conditionNegate = footerPredVectorAlias[1];
          if (conditionNegate < 2) {
            compiler = (1 - conditionNegate) * 4 + 4;
            _memset(conditionNegate * 4 + footerPredVectorAlias[2],0,compiler);
            footerPredVectorAlias[1] = 2;
            staleArg4 = staleArg4b;
          }
          predElementRefPair = CONCAT44(footerPredVectorAlias[2] + 4,staleArg4);
        }
        ifHeaderVectorAtd4 = *(int **)(ifHeader + 0xd4);
        elseEndBlock = *(int *)((ulonglong)predElementRefPair >> 0x20);
        if (*ifHeaderVectorAtd4 == 0) {
          predElementRefPair = Vector__elementRefGrow(ifHeaderVectorAtd4,0);
        }
        else {
          if (ifHeaderVectorAtd4[1] == 0) {
            *(undefined4 *)ifHeaderVectorAtd4[2] = 0;
            ifHeaderVectorAtd4[1] = 1;
          }
          predElementRefPair = CONCAT44(ifHeaderVectorAtd4[2],(int)predElementRefPair);
        }
        blockBeforeIf = *(int *)((ulonglong)predElementRefPair >> 0x20);
        predecessorVector = (int *)block[0x34];
        if (*predecessorVector == 0) {
          predElementRefPair = Vector__elementRefGrow(predecessorVector,0);
        }
        else {
          if (predecessorVector[1] == 0) {
            *(undefined4 *)predecessorVector[2] = 0;
            predecessorVector[1] = 1;
          }
          predElementRefPair = CONCAT44(predecessorVector[2],(int)predElementRefPair);
        }
        blockAfterIf = *(int *)((ulonglong)predElementRefPair >> 0x20);
        blockBeforeIfVectorAtd0 = *(int **)(blockBeforeIf + 0xd0);
        blockBeforeIfCopy = blockBeforeIf;
        if (*blockBeforeIfVectorAtd0 == 0) {
          predElementRefPair = Vector__elementRefGrow(blockBeforeIfVectorAtd0,0);
        }
        else {
          if (blockBeforeIfVectorAtd0[1] == 0) {
            *(undefined4 *)blockBeforeIfVectorAtd0[2] = 0;
            blockBeforeIfVectorAtd0[1] = 1;
          }
          predElementRefPair = CONCAT44(blockBeforeIfVectorAtd0[2],(int)predElementRefPair);
        }
        *(int *)((ulonglong)predElementRefPair >> 0x20) = thenBlock;
        thenBlockVectorAtD4 = *(int **)(thenBlock + 0xd4);
        if (*thenBlockVectorAtD4 == 0) {
          predElementRefPair = Vector__elementRefGrow(thenBlockVectorAtD4,0);
        }
        else {
          if (thenBlockVectorAtD4[1] == 0) {
            *(undefined4 *)thenBlockVectorAtD4[2] = 0;
            thenBlockVectorAtD4[1] = 1;
          }
          predElementRefPair = CONCAT44(thenBlockVectorAtD4[2],(int)predElementRefPair);
        }
        *(int *)((ulonglong)predElementRefPair >> 0x20) = blockBeforeIf;
        blockAfterIfVectorAtd4 = *(int **)(blockAfterIf + 0xd4);
        if (*blockAfterIfVectorAtd4 == 0) {
          predElementRefPair = Vector__elementRefGrow(blockAfterIfVectorAtd4,0);
        }
        else {
          if (blockAfterIfVectorAtd4[1] == 0) {
            *(undefined4 *)blockAfterIfVectorAtd4[2] = 0;
            blockAfterIfVectorAtd4[1] = 1;
          }
          predElementRefPair = CONCAT44(blockAfterIfVectorAtd4[2],(int)predElementRefPair);
        }
        *(int *)((ulonglong)predElementRefPair >> 0x20) = elseEndBlock;
        elseEndBlockVectorAtd0 = *(int **)(elseEndBlock + 0xd0);
        if (*elseEndBlockVectorAtd0 == 0) {
          predElementRefPair = Vector__elementRefGrow(elseEndBlockVectorAtd0,0);
        }
        else {
          if (elseEndBlockVectorAtd0[1] == 0) {
            *(undefined4 *)elseEndBlockVectorAtd0[2] = 0;
            elseEndBlockVectorAtd0[1] = 1;
          }
          predElementRefPair = CONCAT44(elseEndBlockVectorAtd0[2],(int)predElementRefPair);
        }
        *(int *)((ulonglong)predElementRefPair >> 0x20) = blockAfterIf;
        thenEndBlockVectorAtd0 = *(int **)(thenEndBlock + 0xd0);
        if (*thenEndBlockVectorAtd0 == 0) {
          predElementRefPair = Vector__elementRefGrow(thenEndBlockVectorAtd0,0);
        }
        else {
          if (thenEndBlockVectorAtd0[1] == 0) {
            *(undefined4 *)thenEndBlockVectorAtd0[2] = 0;
            thenEndBlockVectorAtd0[1] = 1;
          }
          predElementRefPair = CONCAT44(thenEndBlockVectorAtd0[2],(int)predElementRefPair);
        }
        *(int *)((ulonglong)predElementRefPair >> 0x20) = elseBlock;
        elseBlockVectorAtd4 = *(int **)(elseBlock + 0xd4);
        if (*elseBlockVectorAtd4 == 0) {
          predElementRefPair = Vector__elementRefGrow(elseBlockVectorAtd4,0);
        }
        else {
          if (elseBlockVectorAtd4[1] == 0) {
            *(undefined4 *)elseBlockVectorAtd4[2] = 0;
            elseBlockVectorAtd4[1] = 1;
          }
          predElementRefPair = CONCAT44(elseBlockVectorAtd4[2],(int)predElementRefPair);
        }
        *(int *)((ulonglong)predElementRefPair >> 0x20) = thenEndBlock;
        *(int *)(thenBlock + 0xf0) = blockBeforeIf;
        *(int *)(elseBlock + 0xf0) = thenEndBlock;
        *(int *)(blockAfterIf + 0xf0) = elseEndBlock;
        branchInst = (int *)Block__getBranchInst(ifHeader,(int)predElementRefPair,compiler,staleArg6,staleArg7,staleArg8,blockBeforeIfCopy);
        if (*(int *)(branchInst[0x22] + 8) == 0x8b) {
          isOperandConstZero = IRInst__isOperandConstZero(branchInst,2);
          if (isOperandConstZero == 0) {
            isOperandConstZero = IRInst__isOperandConstZero(branchInst,1);
            if (isOperandConstZero == 0) {
              conditionSource = IRInst__create(0x12,*(undefined4 *)(flattenPass + 8));
              conditionSource[0x26] = 0;
              conditionSource[0x25] = conditionSource[0x53];
              operandRecord2 = IRInst__getOperandRecord(branchInst,1);
              IRInst__getOrCreateOperandRecord(conditionSource,1,operandRecord2,*(undefined4 *)(flattenPass + 8));
              operandRecord2 = IRInst__getOperandRecord(branchInst,2);
              staleArg6 = *(uint *)(flattenPass + 8);
              IRInst__getOrCreateOperandRecord(conditionSource,2,operandRecord2,staleArg6);
              IROperand__setModifierBits(conditionSource + 0x2f,1,branchInst[0x34] & 1U ^ 1);
              Block__prependInst(blockAfterIf,conditionSource);
              IRInst__addToUseLists(conditionSource,flattenPass);
              defaultSelectSwizzle = 0x10203;
              for (operandNumber = 1; thenBlock = (**(code **)(*conditionSource + 0x14))(conditionSource), operandNumber <= thenBlock;
                  operandNumber = operandNumber + 1) {
                operandVReg = (int *)IRInst__getOperandSource(conditionSource,operandNumber);
                thenBlock = (**(code **)(*operandVReg + 0x5c))(operandVReg);
                if (thenBlock != 0) {
                  DList__unlink(operandVReg);
                  Block__insertInstBefore(blockAfterIf,conditionSource,operandVReg);
                }
              }
              conditionNegate = 0;
              conditionAbs = 0;
              insertAfterInst = conditionSource;
            }
            else {
              insertAfterInst = *(int **)(blockAfterIf + 200);
              conditionSource = (int *)IRInst__getOperandSource(branchInst,2);
              operandRecord = IRInst__getOperandRecord(branchInst,2);
              defaultSelectSwizzle = *(undefined4 *)(operandRecord + 0x10);
              conditionNegate = branchInst[0x34] & 1;
              conditionAbs = (uint)branchInst[0x34] >> 1 & 1;
              compareCondition = IRInst__getCompareCondition(branchInst);
              IRInst__setCompareCondition(branchInst,*(undefined4 *)(PTR_DAT_001e90f8 + compareCondition * 4));
            }
          }
          else {
            insertAfterInst = *(int **)(blockAfterIf + 200);
            conditionSource = (int *)IRInst__getOperandSource(branchInst,1);
            operandRecord = IRInst__getOperandRecord(branchInst,1);
            defaultSelectSwizzle = *(undefined4 *)(operandRecord + 0x10);
            conditionNegate = branchInst[0x2e] & 1;
            conditionAbs = (uint)branchInst[0x2e] >> 1 & 1;
          }
        }
        else {
          insertAfterInst = *(int **)(blockAfterIf + 200);
          conditionSource = (int *)IRInst__getOperandSource(branchInst,1);
          operandRecord3 = IRInst__getOperandRecord(branchInst,1);
          conditionDefOpcode = *(int *)(conditionSource[0x22] + 8);
          defaultSelectSwizzle = *(undefined4 *)(operandRecord3 + 0x10);
          conditionNegate = branchInst[0x2e] & 1U ^ 1;
          if ((((conditionDefOpcode == 0x27) || (conditionDefOpcode == 0x29)) || (conditionDefOpcode == 0x2a)) ||
             (conditionAbs = 1, conditionDefOpcode == 0x28)) {
            conditionAbs = 0;
          }
        }
        blockInstSentinel = block + 0x24;
        phiInst = (int *)block[0x26];
        for (nextInst = (int *)((int *)block[0x26])[2]; nextInst != (int *)0x0;
            nextInst = (int *)nextInst[2]) {
          if (*(int *)(phiInst[0x22] + 8) == 0x8e) {
            phiDestRecord = IRInst__getOperandRecord(phiInst,0);
            destMaskWord[0] = *(int *)(phiDestRecord + 0x10);
            phiSource1 = IRInst__getOperandSource(phiInst,1);
            phiSource2 = IRInst__getOperandSource(phiInst,2);
            laneCountdown = 4;
            laneByteIndex = 0;
            conditionSwizzle = defaultSelectSwizzle;
            do {
              if (*(char *)((int)destMaskWord + laneByteIndex) == '\x01') {
                *(undefined1 *)((int)destMaskWord + laneByteIndex + -4) = 4;
              }
              laneByteIndex = laneByteIndex + 1;
              laneCountdown = laneCountdown + -1;
            } while (laneCountdown != 0);
            phiSource1Record = IRInst__getOperandRecord(phiInst,1);
            phiSource1Swizzle = *(undefined4 *)(phiSource1Record + 0x10);
            phiSource2Record = IRInst__getOperandRecord(phiInst,2);
            phiSource2Swizzle = *(undefined4 *)(phiSource2Record + 0x10);
            phiSlotOffset = phiInst[0x58] - *(int *)(flattenPass + 0x478);
            if (phiSlotOffset < 0) {
              phiSlotOffset = 0;
            }
            elseBlock = phiInst[4];
            IRInst__detachWhenTracking(phiInst,flattenPass);
            DList__unlink(phiInst);
            IRInst__reinitAsTrinary(phiInst,0x25,*(undefined4 *)(flattenPass + 8));
            Block__insertInstAfter(blockAfterIf,insertAfterInst,phiInst);
            inputBase = *(int *)(flattenPass + 0x478);
            phiInst[4] = elseBlock;
            phiInst[0x58] = phiSlotOffset + inputBase;
            phiInst[0x25] = phiInst[0x53];
            phiInst[0x26] = 0;
            phiInst[0x27] = destMaskWord[0];
            IRInst__setOperandSource(phiInst,1,conditionSource,*(uint *)(flattenPass + 0x30) >> 7 & 1,
                         *(undefined4 *)(flattenPass + 8));
            savedConditionSwizzle = conditionSwizzle;
            selectSource1Record = IRInst__getOperandRecord(phiInst,1);
            *(undefined4 *)(selectSource1Record + 0x10) = savedConditionSwizzle;
            IROperand__setModifierBits(phiInst + 0x29,1,conditionNegate);
            IROperand__setModifierBits(phiInst + 0x29,2,conditionAbs);
            IRInst__setOperandSource(phiInst,2,phiSource1,*(uint *)(flattenPass + 0x30) >> 7 & 1,
                         *(undefined4 *)(flattenPass + 8));
            selectSource2Record = IRInst__getOperandRecord(phiInst,2);
            *(undefined4 *)(selectSource2Record + 0x10) = phiSource1Swizzle;
            staleArg7 = *(undefined4 *)(flattenPass + 8);
            staleArg6 = *(uint *)(flattenPass + 0x30) >> 7 & 1;
            IRInst__setOperandSource(phiInst,3,phiSource2,staleArg6,staleArg7);
            selectSource3Record = IRInst__getOperandRecord(phiInst,3);
            *(undefined4 *)(selectSource3Record + 0x10) = phiSource2Swizzle;
            insertAfterInst = phiInst;
            if (*(int *)(branchInst[0x22] + 8) == 0x8b) {
              ((int (*)())IRInst__swapCompareOperands)(branchInst,phiInst,*(undefined4 *)(flattenPass + 8));
            }
          }
          else {
            instQuery34 = (**(code **)(*phiInst + 0x34))(phiInst);
            if (instQuery34 == 0) break;
          }
          phiInst = nextInst;
        }
        Program__removeInst(flattenPass,branchInst);
        branchInst[5] = branchInst[5] & 0xffffffef;
        releaseFn = *(code **)(*branchInst + 0xc);
        compilerArg = *(undefined4 *)(flattenPass + 8);
        (*releaseFn)(branchInst,*(uint *)(flattenPass + 0x30) >> 7 & 1);
        conditionHasNoUses = IRInst__hasNoUses(conditionSource,flattenPass,compilerArg,staleArg6,staleArg7,staleArg8,releaseFn);
        if (conditionHasNoUses != 0) {
          (**(code **)(*conditionSource + 0xc))
                    (conditionSource,*(uint *)(flattenPass + 0x30) >> 7 & 1,*(undefined4 *)(flattenPass + 8));
        }
        *(undefined4 *)(ifHeader + 0x130) = 0;
        if ((*(int *)(ifHeader + 0x144) != 0) && (*(int *)(ifHeader + 0x140) != 0)) {
          *(undefined4 *)(*(int *)(ifHeader + 0x140) + 0x144) = 1;
        }
        Block__detach(ifHeader);
        trailingInstCursor = (int *)blockInstSentinel[2];
        for (conditionSource = (int *)((int *)blockInstSentinel[2])[2]; conditionSource != (int *)0x0;
            conditionSource = (int *)conditionSource[2]) {
          instQuery34b = (**(code **)(*trailingInstCursor + 0x34))(trailingInstCursor);
          if (instQuery34b == 0) {
            instQuery38 = (**(code **)(*trailingInstCursor + 0x38))(trailingInstCursor);
            if (instQuery38 != 0) break;
            DList__unlink(trailingInstCursor);
            Block__insertInstAfter(blockAfterIf,insertAfterInst,trailingInstCursor);
            insertAfterInst = trailingInstCursor;
          }
          trailingInstCursor = conditionSource;
        }
        Block__detach(block);
        walkBlock = blockBeforeIf;
        do {
          changedAny = true;
          walkSuccessor = Block__findSimpleSuccessor(walkBlock);
          if (((blockAfterIf != walkSuccessor) && (changedAny = false, walkSuccessor == 0)) ||
             (walkSuccessor = Program__mergeBlockWithSuccessor(flattenPass,walkBlock,walkSuccessor), walkSuccessor == 0)) {
            walkBlock = *(int *)(walkBlock + 8);
          }
        } while ((!changedAny) && (walkBlock != blockAfterIf));
        changedAny = true;
        nextBlock = *(int **)(blockBeforeIf + 8);
      }
      block = nextBlock;
      nextBlock = (int *)block[2];
    } while (nextBlock != (int *)0x0);
    if (changedAny) {
      Program__freeWorkArrays(flattenPass);
      Program__beginPass(flattenPass,(int)"flatten_ifs");
      Program__eliminateDeadInstsAndRecountUses(flattenPass,0);
    }
  }
  return;
}

/* FudoPs__flattenIfs @ 0x12dcf0 (88 bytes) */
int FudoPs__flattenIfs(this, flattenPass)
  undefined4 this;
  int flattenPass;
{
  int callResult;
  
  callResult = FUN_000e0830(*(undefined4 *)(flattenPass + 8),0,0);
  if (callResult == 0) {
    ((int (*)())pass_flatten_ifs)(flattenPass);
    return;
  }
  return;
}

/* Program__detachRegion @ 0x12dd58 (512 bytes) */
int Program__detachRegion(program, currentBlock, regionEnd)
  int program;
  int *currentBlock;
  int regionEnd;
{
  int successor;
  int predecessor;
  int successorByteOffset;
  int successorBlock;
  int *workSlotRef;
  undefined4 *workFirstRef;
  int extraArg;
  undefined4 staleArg6;
  undefined4 staleArg7;
  undefined4 staleArg8;
  uint visitStampOrCount;
  uint loopIndex;
  undefined8 branchHeaderQuery;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_44_buf [0x10];
  #define vecCapacity (*(uint *)(local_44_buf + 0x00))
  #define vecCount (*(uint *)(local_44_buf + 0x04))
  #define vecData (*(undefined4 * *)(local_44_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_44_buf + 0x0c))
  
  visitStampOrCount = *(uint *)(program + 8);
  *(int *)(program + 0x474) = *(int *)(program + 0x474) + 1;
  vecArena = *(undefined4 *)(visitStampOrCount + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  extraArg = regionEnd;
  vecData = (undefined4 *)Arena__alloc(vecArena,8);
  predecessor = Block__getPredecessor(currentBlock,0);
  Vector__removeValue(*(undefined4 *)(predecessor + 0xd0),currentBlock);
  successor = Block__getSuccessor(regionEnd,0);
  Vector__removeValue(*(undefined4 *)(successor + 0xd4),regionEnd);
  Block__connect(predecessor,successor);
  while( true ) {
    successorByteOffset = 0;
    for (loopIndex = 1; loopIndex <= *(uint *)(currentBlock[0x34] + 4); loopIndex = loopIndex + 1) {
      successorBlock = *(int *)(*(int *)(currentBlock[0x34] + 8) + successorByteOffset);
      if (((successorBlock != 0) && (visitStampOrCount = *(uint *)(program + 0x474), visitStampOrCount != *(uint *)(successorBlock + 0x118)))
         && (regionEnd != successorBlock)) {
        *(uint *)(successorBlock + 0x118) = visitStampOrCount;
        if (vecCount < vecCapacity) {
          visitStampOrCount = vecCount + 1;
          vecData[vecCount] = 0;
          workSlotRef = vecData + vecCount;
          vecCount = visitStampOrCount;
        }
        else {
          workSlotRef = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
        }
        *workSlotRef = successorBlock;
      }
      successorByteOffset = successorByteOffset + 4;
    }
    branchHeaderQuery = (**(code **)(*currentBlock + 0x24))(currentBlock);
    if (((int)((ulonglong)branchHeaderQuery >> 0x20) != 0) &&
       (workSlotRef = (int *)Block__getBranchInst(currentBlock,(int)branchHeaderQuery,extraArg,staleArg6,staleArg7,staleArg8,visitStampOrCount),
       workSlotRef != (int *)0x0)) {
      Program__removeInst(program,workSlotRef);
      extraArg = *(int *)(program + 8);
      (**(code **)(*workSlotRef + 0xc))(workSlotRef,*(uint *)(program + 0x30) >> 7 & 1,extraArg);
      currentBlock[0x4c] = 0;
    }
    Block__detach(currentBlock);
    if (vecCount == 0) break;
    workFirstRef = vecData;
    if (vecCapacity == 0) {
      workFirstRef = (undefined4 *)Vector__elementRefGrow(&vecCapacity,0);
    }
    currentBlock = (int *)*workFirstRef;
    if ((currentBlock == (int *)0x0) || (successorByteOffset = Vector__removeValue(&vecCapacity,currentBlock), successorByteOffset == 0)) break;
  }
  Block__detach(regionEnd);
  return Arena__free(vecArena,vecData);
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* Program__foldConstantIfRegion @ 0x12df90 (1216 bytes) */
int Program__foldConstantIfRegion(program, ifHeader, ifFooter, outSurvivingEntry, outSurvivingExit)
  int program;
  int *ifHeader;
  dword *ifFooter;
  int *outSurvivingEntry;
  int *outSurvivingExit;
{
  int conditionValue;
  int successorByteOffset;
  int blockQuery38b;
  int headerPredecessor;
  uint successorNumber;
  uint lastWorkIndex;
  int footerSuccessor;
  int workStackByteOffsetB;
  int firstPredOfSuccessor;
  int blockQuery38;
  int *footerSuccPredVector;
  int *exitSuccVector;
  int *headerPredSuccVector;
  int *entrySuccPredVector;
  uint workStackCountB;
  undefined4 *workStackSlotRef;
  undefined4 *predSlotRef;
  undefined4 *workStackTopRef;
  int *deadSuccPredVector;
  uint predecessorIndex;
  uint predVectorCount;
  int *deadBlockSuccessor;
  int *staleOutEntry;
  int workStackByteOffset;
  int survivingEntry;
  undefined4 staleArg4;
  uint workStackCountSnapshot;
  undefined4 staleArg4b;
  undefined4 staleArg4c;
  dword *staleArg5;
  int *staleArg7;
  undefined4 staleArg8;
  int compiler;
  int deadArmEntry;
  uint *predVectorOfSurvivor;
  int *deadBlock;
  undefined8 slotRefPair;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_64_buf [0x10];
  #define vecCapacity (*(uint *)(local_64_buf + 0x00))
  #define vecCount (*(uint *)(local_64_buf + 0x04))
  #define vecData (*(int *)(local_64_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_64_buf + 0x0c))
  
  if (ifHeader[0x53] == 1) {
    deadArmEntry = ifHeader[0x4e];
  }
  else {
    deadArmEntry = ifHeader[0x4d];
  }
  compiler = *(int *)(program + PROG_compiler);
  *(int *)(program + PROG_visitStamp) = *(int *)(program + PROG_visitStamp) + 1;
  vecArena = *(undefined4 *)(compiler + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  staleArg5 = ifFooter;
  staleOutEntry = outSurvivingEntry;
  staleArg7 = outSurvivingExit;
  vecData = Arena__alloc(vecArena,8);
  workStackCountSnapshot = vecCount;
  if (vecCount < vecCapacity) {
    workStackByteOffset = vecCount * 4;
    staleArg5 = ((unsigned char *)0x4);
    _memset(vecData + workStackByteOffset,0,4);
    vecCount = workStackCountSnapshot + 1;
    slotRefPair = CONCAT44(workStackByteOffset + vecData,staleArg4);
  }
  else {
    slotRefPair = Vector__elementRefGrow(&vecCapacity,vecCount);
  }
  staleArg4c = (undefined4)slotRefPair;
  *(int *)((ulonglong)slotRefPair >> 0x20) = deadArmEntry;
  *(undefined4 *)(deadArmEntry + 0x118) = *(undefined4 *)(program + PROG_visitStamp);
  while (vecCount != 0) {
    lastWorkIndex = vecCount - 1;
    workStackTopRef = (undefined4 *)0x0;
    if (lastWorkIndex < vecCount) {
      workStackTopRef = (undefined4 *)(lastWorkIndex * 4 + vecData);
    }
    deadBlock = (int *)*workStackTopRef;
    Vector__removeAt(&vecCapacity,lastWorkIndex);
    blockQuery38b = (**(code **)(*deadBlock + 0x38))(deadBlock);
    if ((blockQuery38b == 0) && (blockQuery38b = (**(code **)(*deadBlock + 0x3c))(deadBlock), blockQuery38b == 0)) {
      successorByteOffset = 0;
      for (successorNumber = 1; successorNumber <= *(uint *)(deadBlock[0x34] + 4); successorNumber = successorNumber + 1) {
        deadBlockSuccessor = *(int **)(successorByteOffset + *(int *)(deadBlock[0x34] + 8));
        if ((((deadBlockSuccessor != (int *)0x0) && (*(int *)(program + PROG_visitStamp) != deadBlockSuccessor[0x46])) &&
            ((dword *)deadBlockSuccessor != ifFooter)) && (deadBlockSuccessor != ifHeader)) {
          blockQuery38 = (**(code **)(*deadBlockSuccessor + 0x38))(deadBlockSuccessor);
          if ((blockQuery38 != 0) || (blockQuery38 = (**(code **)(*deadBlockSuccessor + 0x3c))(deadBlockSuccessor), blockQuery38 != 0)) {
            deadSuccPredVector = (int *)deadBlockSuccessor[0x34];
            if (*deadSuccPredVector == 0) {
              deadSuccPredVector = (int *)Vector__elementRefGrow(deadSuccPredVector,0);
            }
            else {
              if (deadSuccPredVector[1] == 0) {
                *(undefined4 *)deadSuccPredVector[2] = 0;
                deadSuccPredVector[1] = 1;
              }
              deadSuccPredVector = (int *)deadSuccPredVector[2];
            }
            firstPredOfSuccessor = *deadSuccPredVector;
            predecessorIndex = Block__predecessorIndex(firstPredOfSuccessor,deadBlockSuccessor);
            predVectorOfSurvivor = *(uint **)(firstPredOfSuccessor + 0xd4);
            if (predecessorIndex < *predVectorOfSurvivor) {
              predVectorCount = predVectorOfSurvivor[1];
              if (predVectorCount <= predecessorIndex) {
                staleArg5 = (dword *)((predecessorIndex - predVectorCount) * 4 + 4);
                _memset(predVectorCount * 4 + predVectorOfSurvivor[2],0,staleArg5);
                predVectorOfSurvivor[1] = predecessorIndex + 1;
              }
              predSlotRef = (undefined4 *)(predecessorIndex * 4 + predVectorOfSurvivor[2]);
            }
            else {
              predSlotRef = (undefined4 *)Vector__elementRefGrow(predVectorOfSurvivor,predecessorIndex);
            }
            *predSlotRef = 0;
          }
          workStackCountB = vecCount;
          deadBlockSuccessor[0x46] = *(int *)(program + PROG_visitStamp);
          if (vecCount < vecCapacity) {
            workStackByteOffsetB = vecCount * 4;
            staleArg5 = ((unsigned char *)0x4);
            _memset(workStackByteOffsetB + vecData,0,4);
            vecCount = workStackCountB + 1;
            workStackSlotRef = (undefined4 *)(workStackByteOffsetB + vecData);
          }
          else {
            workStackSlotRef = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
          }
          *workStackSlotRef = deadBlockSuccessor;
        }
        successorByteOffset = successorByteOffset + 4;
      }
    }
    DList__count(deadBlock + 0x24);
    Block__detach(deadBlock);
    staleArg4c = staleArg4b;
  }
  staleOutEntry = (int *)Block__getBranchInst(ifHeader,staleArg4c,staleArg5,staleOutEntry,staleArg7,staleArg8,compiler);
  ifHeader[0x4c] = 0;
  Program__removeInst(program,staleOutEntry);
  (**(code **)(*staleOutEntry + 0xc))(staleOutEntry,0,*(undefined4 *)(program + PROG_compiler));
  DList__count(ifHeader + 0x24);
  headerPredecessor = Block__findSimplePredecessor(ifHeader);
  footerSuccessor = Block__findSimpleSuccessor(ifFooter);
  conditionValue = ifHeader[0x53];
  survivingEntry = Block__getSuccessor(ifHeader,(uint)(conditionValue != 1));
  *outSurvivingEntry = survivingEntry;
  entrySuccPredVector = *(int **)(survivingEntry + 0xd4);
  if (*entrySuccPredVector == 0) {
    entrySuccPredVector = (int *)Vector__elementRefGrow(entrySuccPredVector,0);
  }
  else {
    if (entrySuccPredVector[1] == 0) {
      *(undefined4 *)entrySuccPredVector[2] = 0;
      entrySuccPredVector[1] = 1;
    }
    entrySuccPredVector = (int *)entrySuccPredVector[2];
  }
  *entrySuccPredVector = headerPredecessor;
  headerPredSuccVector = *(int **)(headerPredecessor + 0xd0);
  if (*headerPredSuccVector == 0) {
    headerPredSuccVector = (int *)Vector__elementRefGrow(headerPredSuccVector,0);
  }
  else {
    if (headerPredSuccVector[1] == 0) {
      *(undefined4 *)headerPredSuccVector[2] = 0;
      headerPredSuccVector[1] = 1;
    }
    headerPredSuccVector = (int *)headerPredSuccVector[2];
  }
  *headerPredSuccVector = *outSurvivingEntry;
  conditionValue = Block__getPredecessor(ifFooter,(uint)(conditionValue != 1));
  *outSurvivingExit = conditionValue;
  exitSuccVector = *(int **)(conditionValue + 0xd0);
  if (*exitSuccVector == 0) {
    exitSuccVector = (int *)Vector__elementRefGrow(exitSuccVector,0);
  }
  else {
    if (exitSuccVector[1] == 0) {
      *(undefined4 *)exitSuccVector[2] = 0;
      exitSuccVector[1] = 1;
    }
    exitSuccVector = (int *)exitSuccVector[2];
  }
  *exitSuccVector = footerSuccessor;
  footerSuccPredVector = *(int **)(footerSuccessor + 0xd4);
  if (*footerSuccPredVector == 0) {
    footerSuccPredVector = (int *)Vector__elementRefGrow(footerSuccPredVector,0);
  }
  else {
    if (footerSuccPredVector[1] == 0) {
      *(undefined4 *)footerSuccPredVector[2] = 0;
      footerSuccPredVector[1] = 1;
    }
    footerSuccPredVector = (int *)footerSuccPredVector[2];
  }
  *footerSuccPredVector = *outSurvivingExit;
  Block__detach(ifHeader);
  Block__detach(ifFooter);
  Program__freeWorkArrays(program);
  return Arena__free(vecArena,vecData);
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* Program__getOrCreateLandingBlock @ 0x12e488 (172 bytes) */
int Program__getOrCreateLandingBlock(program, block)
  int program;
  int block;
{
  undefined4 *successor;
  int successorInstCount;
  undefined4 *allocation;
  undefined4 *landingBlock;
  undefined4 arena;
  
  successor = (undefined4 *)Block__getSuccessor(block,0);
  successorInstCount = DList__count(successor + 0x24);
  if ((2 < successorInstCount) || (successorInstCount = Block__isSimple(successor), landingBlock = successor, successorInstCount == 0)) {
    arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
    allocation = (undefined4 *)Arena__alloc(arena,0x130);
    *allocation = arena;
    landingBlock = allocation + 1;
    Block__ctor_ea020(landingBlock,*(undefined4 *)(program + 8));
    allocation[0x2f] = *(undefined4 *)(block + 0xb8);
    Program__insertBlockAfter(program,block,landingBlock);
    Block__splitOutgoingEdge(block,successor,landingBlock);
    Block__connect(landingBlock,successor);
  }
  return landingBlock;
}

/* IfFooter__ctor_12e56c @ 0x12e56c (660 bytes) */
int IfFooter__ctor_12e56c(conditionRegister, loopBlock, compiler)
  undefined4 conditionRegister;
  int *loopBlock;
  int compiler;
{
  undefined4 headerChainBlock;
  undefined4 loopExitTarget;
  undefined4 arena;
  int operandRecord;
  undefined4 arenaAt3742;
  undefined *vtable;
  int blockQuery30;
  undefined4 *allocation;
  undefined4 *ifFooterAlloc;
  undefined4 program;
  undefined4 *branchInst;
  int loopHeader;
  undefined4 *preHeaderBlock;
  undefined4 *breakBlock;
  undefined4 *thenBlock;
  undefined4 headerWordB8;
  undefined4 *ifHeader;
  undefined4 swizzleTableWord;
  undefined4 arenaAt374;
  undefined4 *ifFooter;
  
  blockQuery30 = (**(code **)(*loopBlock + 0x30))(loopBlock,loopBlock,compiler);
  if (blockQuery30 != 0) {
    arena = *(undefined4 *)(compiler + COMP_arenaA);
    loopHeader = loopBlock[0x4b];
    program = *(undefined4 *)(compiler + COMP_currentProgram);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    branchInst = allocation + 1;
    *allocation = arena;
    IRInst__ctor_10502c(branchInst,0x8c,compiler);
    allocation[0x4c] = 6;
    operandRecord = IRInst__getOperandRecord(branchInst,1);
    vtable = PTR_DAT_001e8b8c;
    *(undefined4 *)(operandRecord + 0xc) = 0;
    swizzleTableWord = *(undefined4 *)vtable;
    *(undefined4 *)(operandRecord + 8) = conditionRegister;
    operandRecord = IRInst__getOperandRecord(branchInst,1);
    *(undefined4 *)(operandRecord + 0x10) = swizzleTableWord;
    headerWordB8 = *(undefined4 *)(loopHeader + 0xb8);
    loopExitTarget = Block__getSuccessor(loopHeader,0);
    arenaAt374 = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arenaAt374,0x130);
    preHeaderBlock = allocation + 1;
    *allocation = arenaAt374;
    Block__ctor_ea020(preHeaderBlock,compiler);
    allocation[0x2f] = headerWordB8;
    Program__insertBlockAfter(program,loopHeader,preHeaderBlock);
    Block__splitOutgoingEdge(loopHeader,loopExitTarget,preHeaderBlock);
    headerChainBlock = Block__findRegionHeader(loopHeader);
    arenaAt374 = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arenaAt374,0x130);
    thenBlock = allocation + 1;
    *allocation = arenaAt374;
    Block__ctor_ea020(thenBlock,compiler);
    arenaAt374 = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arenaAt374,0x138);
    breakBlock = allocation + 1;
    *allocation = arenaAt374;
    BreakBlock__ctor_ec0c8(breakBlock,loopHeader,1,compiler);
    arenaAt374 = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arenaAt374,0x15c);
    ifHeader = allocation + 1;
    *allocation = arenaAt374;
    IfHeader__ctor_ea6d0(ifHeader,branchInst,headerChainBlock,thenBlock,compiler);
    arenaAt3742 = *(undefined4 *)(compiler + COMP_arenaA);
    ifFooterAlloc = (undefined4 *)Arena__alloc(arenaAt3742,0x134);
    ifFooter = ifFooterAlloc + 1;
    *ifFooterAlloc = arenaAt3742;
    Block__ctor_ea148(ifFooter,compiler);
    ifFooterAlloc[0x4c] = ifHeader;
    *ifFooter = PTR_DAT_001e9130 + 8;
    allocation[0x4e] = thenBlock;
    allocation[0x4f] = breakBlock;
    allocation[0x50] = ifFooter;
    Program__insertBlockAfter(program,preHeaderBlock,ifHeader);
    Program__insertBlockAfter(program,ifHeader,thenBlock);
    Program__insertBlockAfter(program,thenBlock,breakBlock);
    Program__insertBlockAfter(program,breakBlock,ifFooter);
    Block__connect(preHeaderBlock,ifHeader);
    Block__connect(ifHeader,thenBlock);
    Block__connect(ifHeader,breakBlock);
    Block__connect(thenBlock,ifFooter);
    Block__connect(breakBlock,*(undefined4 *)(loopHeader + 0x154));
    Block__connect(ifFooter,loopExitTarget);
    IRInst__bindOperandRegisters(program,branchInst);
    return;
  }
  return;
}

/* Program__splitCriticalEdges @ 0x12e8c0 (304 bytes) */
int Program__splitCriticalEdges(program, block, lastBlock)
  int program;
  int *block;
  int *lastBlock;
{
  undefined4 *newPredecessorBlock;
  int blockQuery24;
  int blockQuery28;
  undefined4 predecessor;
  int *successorBlock;
  int blockNeedsSplit;
  undefined4 successor;
  undefined4 *allocation;
  undefined4 arena;
  undefined4 *newSuccessorBlock;
  
  successorBlock = block;
  do {
    if (successorBlock == lastBlock) {
      return;
    }
    successorBlock = (int *)Block__getSuccessor(block,0);
    blockNeedsSplit = Program__mergeBlockWithSuccessor(program,block,successorBlock);
    if (blockNeedsSplit == 0) {
      block = (int *)block[2];
    }
    blockQuery28 = (**(code **)(*block + 0x28))(block);
    if (((blockQuery28 != 0) || (blockQuery28 = (**(code **)(*block + 0x34))(block), blockQuery28 != 0)) &&
       (blockQuery28 = Block__findSimpleSuccessor(block), blockQuery28 == 0)) {
      successor = Block__getSuccessor(block,0);
      arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arena,0x130);
      *allocation = arena;
      newSuccessorBlock = allocation + 1;
      Block__ctor_ea020(newSuccessorBlock,*(undefined4 *)(program + 8));
      allocation[0x2f] = block[0x2e];
      Program__insertBlockAfter(program,block,newSuccessorBlock);
      Block__splitEdge(block,successor,newSuccessorBlock);
    }
    blockQuery24 = (**(code **)(*block + 0x24))(block);
    if (((blockQuery24 != 0) || (blockQuery24 = (**(code **)(*block + 0x2c))(block), blockQuery24 != 0)) &&
       (blockQuery24 = Block__findSimplePredecessor(block), blockQuery24 == 0)) {
      predecessor = Block__getPredecessor(block,0);
      arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arena,0x130);
      *allocation = arena;
      newPredecessorBlock = allocation + 1;
      Block__ctor_ea020(newPredecessorBlock,*(undefined4 *)(program + 8));
      allocation[0x2f] = block[0x2e];
      Program__insertBlockBefore(program,block,newPredecessorBlock);
      Block__splitEdge(predecessor,block,newPredecessorBlock);
    }
  } while (block != lastBlock);
  return;
}

/* Program__predicatePendingIfs @ 0x12eacc (1428 bytes) */
int Program__predicatePendingIfs(program)
  int program;
{
  int pendingEntry;
  int *visitedElemRef;
  int *pendingTopRef;
  uint isOrdinaryEntry;
  undefined4 *newSplitBlock;
  undefined4 ifFooterBlock;
  int movDestOperand;
  int chainLastBlock;
  int chainBlock;
  int pendingVector;
  int blockQuery24;
  int blockQuery28;
  undefined4 swizzleTableWord;
  undefined4 predecessorBlock;
  undefined4 successorBlock;
  undefined4 vectorData;
  undefined4 arena;
  int isSimple;
  undefined4 newInst2;
  undefined4 predecessor2;
  undefined4 *predecessor;
  int operandRecord;
  int newInst;
  int operandRecord3;
  int operandRecord2;
  undefined4 arenaAt374;
  undefined4 arenaAt3742;
  undefined4 arenaAt3743;
  undefined4 *blockAlloc2;
  undefined4 *blockAlloc;
  undefined4 *instAlloc;
  bool foundInChain;
  undefined *swizzleTablePtr;
  int *successorCursor;
  undefined4 *allocation;
  int splitResult;
  int conditionKey;
  undefined4 headerWordB8;
  undefined4 *armEntryBlock;
  undefined4 *armBlock;
  undefined4 *ifHeaderAlloc;
  uint pendingCount;
  int *blockCursor;
  undefined4 movSource;
  int *lastBlock;
  undefined4 chainHeadKey;
  undefined4 chainSecondKey;
  undefined4 predicateRegister;
  undefined4 *branchInst;
  undefined4 containerBlock;
  undefined4 chainKey;
  undefined4 *ifHeader;
  uint visitedCount;
  int newVRegA;
  int newVRegB;
  undefined4 zeroMovInst;
  uint loopIndex;
  double fparam_1;
  
  if (*(int *)(*(int *)(program + 0x414) + 4) == 0) {
    return;
  }
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  newVRegA = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(program + 8) + 0x3ac) = newVRegA;
  zeroMovInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
  operandRecord3 = IRInst__getOperandRecord(zeroMovInst,0);
  *(int *)(operandRecord3 + 8) = newVRegA;
  fparam_1 = (double)FLOAT_001aa0d4;
  *(undefined4 *)(operandRecord3 + 0xc) = 0;
  ((void (*)())IRInst__makeLiteralVec4Float)(zeroMovInst,program,1,fparam_1,fparam_1,fparam_1,fparam_1);
  Program__appendInst(program,zeroMovInst,*(undefined4 *)(program + 0x3a0));
  newVRegB = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(program + 8) + 0x3ac) = newVRegB;
  newInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
  operandRecord2 = IRInst__getOperandRecord(newInst,0);
  *(undefined4 *)(operandRecord2 + 0xc) = 0;
  *(int *)(operandRecord2 + 8) = newVRegB;
  IRInst__setIntConstantOperand4(newInst,program,1,0xffffffff,0xffffffff,0xffffffff,0xffffffff);
  Program__appendInst(program,newInst,*(undefined4 *)(program + 0x3a0));
  do {
    pendingVector = *(int *)(program + 0x414);
    pendingCount = *(uint *)(pendingVector + 4);
    if (pendingCount == 0) {
      blockCursor = *(int **)(program + 0x3a0);
      lastBlock = *(int **)(program + 0x3a8);
      successorCursor = blockCursor;
      do {
        if (successorCursor == lastBlock) {
          return;
        }
        successorCursor = (int *)Block__getSuccessor(blockCursor,0);
        splitResult = Program__mergeBlockWithSuccessor(program,blockCursor,successorCursor);
        if (splitResult == 0) {
          blockCursor = (int *)blockCursor[2];
        }
        blockQuery28 = (**(code **)(*blockCursor + 0x28))(blockCursor);
        if (((blockQuery28 != 0) || (blockQuery28 = (**(code **)(*blockCursor + 0x34))(blockCursor), blockQuery28 != 0)) &&
           (blockQuery28 = Block__findSimpleSuccessor(blockCursor), blockQuery28 == 0)) {
          successorBlock = Block__getSuccessor(blockCursor,0);
          arenaAt374 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
          allocation = (undefined4 *)Arena__alloc(arenaAt374,0x130);
          *allocation = arenaAt374;
          newSplitBlock = allocation + 1;
          Block__ctor_ea020(newSplitBlock,*(undefined4 *)(program + 8));
          allocation[0x2f] = blockCursor[0x2e];
          Program__insertBlockAfter(program,blockCursor,newSplitBlock);
          Block__splitEdge(blockCursor,successorBlock,newSplitBlock);
        }
        blockQuery24 = (**(code **)(*blockCursor + 0x24))(blockCursor);
        if (((blockQuery24 != 0) || (blockQuery24 = (**(code **)(*blockCursor + 0x2c))(blockCursor), blockQuery24 != 0)) &&
           (blockQuery24 = Block__findSimplePredecessor(blockCursor), blockQuery24 == 0)) {
          predecessorBlock = Block__getPredecessor(blockCursor,0);
          arenaAt374 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
          allocation = (undefined4 *)Arena__alloc(arenaAt374,0x130);
          *allocation = arenaAt374;
          newSplitBlock = allocation + 1;
          Block__ctor_ea020(newSplitBlock,*(undefined4 *)(program + 8));
          allocation[0x2f] = blockCursor[0x2e];
          Program__insertBlockBefore(program,blockCursor,newSplitBlock);
          Block__splitEdge(predecessorBlock,blockCursor,newSplitBlock);
        }
      } while (blockCursor != lastBlock);
      return;
    }
    pendingTopRef = (int *)0x0;
    if (pendingCount - 1 < pendingCount) {
      pendingTopRef = (int *)((pendingCount - 1) * 4 + *(int *)(pendingVector + 8));
    }
    pendingEntry = *pendingTopRef;
    Vector__removeAt(pendingVector,pendingCount - 1);
    containerBlock = *(undefined4 *)(pendingEntry + 0x158);
    chainBlock = Block__findRegionHeader(containerBlock);
    chainKey = *(undefined4 *)(chainBlock + 0x13c);
    isOrdinaryEntry = (uint)(*(int *)(*(int *)(pendingEntry + 0x88) + 8) != 0xf8);
    if (isOrdinaryEntry == 0) {
      chainHeadKey = *(undefined4 *)(pendingEntry + 300);
      chainSecondKey = 0;
      conditionKey = Block__findLoopEntryPredecessor(chainHeadKey,chainKey);
LAB_0012ed5c:
      predicateRegister = 0;
      if (conditionKey != 0) {
        predicateRegister = Program__emitMovFromField8c(zeroMovInst,conditionKey,program);
      }
    }
    else {
      do {
        chainBlock = Block__findRegionHeader(chainBlock);
      } while (*(int *)(chainBlock + 0x150) == 0);
      visitedCount = allocation[2];
      loopIndex = 0;
      if (visitedCount != 0) {
        do {
          if (loopIndex < (uint)allocation[1]) {
            if (visitedCount <= loopIndex) {
              _memset(visitedCount * 4 + allocation[3],0,(loopIndex - visitedCount) * 4 + 4);
              allocation[2] = loopIndex + 1;
            }
            visitedElemRef = (int *)(loopIndex * 4 + allocation[3]);
          }
          else {
            visitedElemRef = (int *)Vector__elementRefGrow(allocation + 1,loopIndex);
          }
          if (*visitedElemRef == chainBlock) {
            foundInChain = true;
            goto LAB_0012ed24;
          }
          visitedCount = allocation[2];
          loopIndex = loopIndex + 1;
        } while (loopIndex < visitedCount);
      }
      foundInChain = false;
LAB_0012ed24:
      conditionKey = *(int *)(chainBlock + 0x134);
      chainSecondKey = *(undefined4 *)(chainBlock + 0x13c);
      chainHeadKey = 0xffffffff;
      if (!foundInChain) goto LAB_0012ed5c;
      chainLastBlock = Block__getFirstRealInst(containerBlock);
      predicateRegister = *(undefined4 *)(chainLastBlock + 0x94);
    }
    newInst2 = IRInst__create(0x31,*(undefined4 *)(program + 8));
    movDestOperand = IRInst__getOperandRecord(newInst2,0);
    movSource = *(undefined4 *)(newInst + 0x8c);
    *(undefined4 *)(movDestOperand + 0xc) = 0;
    *(undefined4 *)(movDestOperand + 8) = predicateRegister;
    IRInst__setOperandRef(newInst2,1,movSource);
    IRInst__bindOperandRegisters(program,newInst2);
    Block__insertInstAfter(containerBlock,pendingEntry,newInst2);
    DList__unlink(pendingEntry);
    while( true ) {
      while( true ) {
        chainKey = ((int (*)())Program__getOrCreateLandingBlock)(program,chainKey);
        movDestOperand = Block__getSuccessor(chainKey,0);
        pendingEntry = Block__walkToLoopFooter(isOrdinaryEntry,chainHeadKey,movDestOperand,chainSecondKey);
        chainKey = Block__findRegionHeader(movDestOperand);
        if (movDestOperand != pendingEntry) break;
        ((int (*)())IfFooter__ctor_12e56c)(predicateRegister,movDestOperand,*(undefined4 *)(program + 8));
        chainKey = Block__footerTargetOrSelf(movDestOperand);
      }
      if (pendingEntry == 0) break;
      arenaAt3742 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      instAlloc = (undefined4 *)Arena__alloc(arenaAt3742,0x168);
      *instAlloc = arenaAt3742;
      branchInst = instAlloc + 1;
      IRInst__ctor_10502c(branchInst,0x8c,*(undefined4 *)(program + 8));
      instAlloc[0x4c] = 6;
      operandRecord = IRInst__getOperandRecord(branchInst,1);
      swizzleTablePtr = PTR_DAT_001e8b8c;
      *(undefined4 *)(operandRecord + 0xc) = 0;
      swizzleTableWord = *(undefined4 *)swizzleTablePtr;
      *(undefined4 *)(operandRecord + 8) = predicateRegister;
      operandRecord = IRInst__getOperandRecord(branchInst,1);
      *(undefined4 *)(operandRecord + 0x10) = swizzleTableWord;
      predecessor2 = Block__getPredecessor(pendingEntry,0);
      predecessor = (undefined4 *)Block__getPredecessor(movDestOperand,0);
      arenaAt3743 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      headerWordB8 = *(undefined4 *)(movDestOperand + 0xb8);
      ifHeaderAlloc = (undefined4 *)Arena__alloc(arenaAt3743,0x15c);
      *ifHeaderAlloc = arenaAt3743;
      ifHeader = ifHeaderAlloc + 1;
      IfHeader__ctor_ea6d0(ifHeader,branchInst,chainKey,movDestOperand,*(undefined4 *)(program + 8));
      isSimple = Block__isSimple(predecessor);
      armEntryBlock = predecessor;
      if (isSimple == 0) {
        arenaAt374 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        blockAlloc = (undefined4 *)Arena__alloc(arenaAt374,0x130);
        *blockAlloc = arenaAt374;
        armEntryBlock = blockAlloc + 1;
        Block__ctor_ea020(armEntryBlock,*(undefined4 *)(program + 8));
        Block__splitOutgoingEdge(predecessor,movDestOperand,armEntryBlock);
        Block__splitIncomingEdge(ifHeader,movDestOperand,armEntryBlock);
        Program__insertBlockAfter(program,predecessor,armEntryBlock);
      }
      Program__insertBlockAfter(program,armEntryBlock,ifHeader);
      arenaAt374 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      blockAlloc2 = (undefined4 *)Arena__alloc(arenaAt374,0x130);
      *blockAlloc2 = arenaAt374;
      armBlock = blockAlloc2 + 1;
      Block__ctor_ea020(armBlock,*(undefined4 *)(program + 8));
      ifHeaderAlloc[0x4f] = armBlock;
      Program__insertBlockAfter(program,predecessor2,armBlock);
      ifFooterBlock = ifHeaderAlloc[0x50];
      Program__insertBlockAfter(program,armBlock,ifFooterBlock);
      Block__setField0xb8AndChildren(ifHeader,headerWordB8);
      Block__connect(ifHeader,armBlock);
      Block__splitOutgoingEdge(armEntryBlock,movDestOperand,ifHeader);
      Block__connect(armBlock,ifFooterBlock);
      Block__splitOutgoingEdge(predecessor2,pendingEntry,ifFooterBlock);
      Block__connect(ifFooterBlock,pendingEntry);
      IRInst__bindOperandRegisters(program,branchInst);
      ((int (*)())IfFooter__ctor_12e56c)(predicateRegister,pendingEntry,*(undefined4 *)(program + 8));
      chainKey = Block__footerTargetOrSelf(pendingEntry);
    }
  } while( true );
}

/* Program__unrollLoop @ 0x12f0f8 (3356 bytes) */
int Program__unrollLoop(pass, loopStack, block, lastBlockRef, newBlockOut, blockCounter)
  int pass;
  int loopStack;
  int block;
  int *lastBlockRef;
  int *newBlockOut;
  int *blockCounter;
{
  int *nextExitInst;
  int *clonedBlockObj;
  int *origBlock;
  int *bodyBlock;
  int *instCursor;
  int instIter;
  int nextFixBlock;
  int rewireCursor;
  int prevCopyEnd;
  uint targetCloneIndex;
  uint instLinkedFlag;
  uint cloneFilledCountE;
  int rewireBlockCursor;
  int nextOrigBlock;
  int origBlockCursor;
  int savedLoopFooter;
  uint cloneFilledCountD;
  uint cloneFilledCountC;
  int *rewiredCloneRef;
  int *srcInst;
  undefined4 *cloneSlotRefD;
  undefined4 *cloneSlotRefC;
  undefined4 *cloneSlotRefB;
  uint successorCloneIndex;
  uint successorIndex;
  int blockAt134;
  int blockQuery30;
  int blockQuery2c;
  int blockQuery28;
  int blockQuery24;
  int successorSlot;
  int clonedBlock;
  int loopEndBlock;
  int instListHead;
  int operandCount;
  int loopFooterBlock;
  int instQuery3c;
  int fixupBlock;
  int nextBodyBlock;
  int loopStepArg;
  int needsOffsetFix;
  int nextInst;
  int operandNumber;
  int instQuery34b;
  bool moreBlocksB;
  int successorOffset;
  int extraBranchArg;
  int instQuery38;
  undefined4 fromClone;
  int *exitInst;
  int *bodyInst;
  int *blockVectorAt154;
  int *blockVectorAt150;
  undefined4 vectorData;
  undefined4 arena;
  int cloneResult;
  int isLoopHeader;
  bool moreBlocksA;
  bool hasBody;
  int successorBlock;
  int blockArg;
  int unrollEnabled;
  int unrollCount;
  int loopStart;
  int loopStep;
  int cannotUnroll;
  int findSimplePredecessorResult;
  int isLoopHeaderBlock;
  undefined4 *allocation;
  int needsOffsetFixClone;
  int *nextInstRef;
  uint cloneFilledCountA;
  uint cloneFilledCountB;
  undefined4 *cloneSlotRefA;
  int *clonedBlockRef;
  int *counterRefArg;
  uint cloneCapacity;
  uint lastCloneIndex;
  int instQuery34;
  int blockOrdinal;
  uint cloneIndex;
  int bodyBlockCursor;
  undefined4 compiler;
  int *instNext;
  uint *cloneVector;
  undefined8 isIfHeader;
  int iStack0000001c;
  int iteration;
  int counterValue;
  undefined4 exitBlock;
  
  counterRefArg = blockCounter;
  iStack0000001c = loopStack;
  unrollEnabled = Compiler__isOptionEnabled(*(undefined4 *)(pass + 8),2);
  if ((((unrollEnabled != 0) && (unrollEnabled = FUN_000e9cc8(block), unrollEnabled != 0)) &&
      (*(int *)(block + 0x138) < 1)) && (*(int *)(block + 0x13c) == 0)) {
    unrollCount = FUN_000e8c7c(block);
    loopStart = FUN_000e8c14(block);
    loopStep = FUN_000e8bac(block);
    compiler = *(undefined4 *)(pass + 8);
    loopStepArg = loopStep;
    blockArg = block;
    cannotUnroll = Loop__unrollExceedsLimits(compiler,unrollCount,loopStart,loopStep,block);
    if (cannotUnroll == 0) {
      Compiler__noteUnrollCount(compiler,unrollCount);
      *(int *)(pass + 0x98) = *(int *)(pass + 0x98) + 1;
      findSimplePredecessorResult = Block__findSimplePredecessor(block);
      exitBlock = *(undefined4 *)(block + 8);
      loopEndBlock = *lastBlockRef;
      if (unrollCount == 0) {
        while (block != loopEndBlock) {
          nextBodyBlock = *(int *)(loopEndBlock + 4);
          bodyInst = *(int **)(loopEndBlock + 0x98);
          for (instNext = (int *)(*(int **)(loopEndBlock + 0x98))[2]; instNext != (int *)0x0;
              instNext = (int *)instNext[2]) {
            if ((bodyInst[5] & 1U) != 0) {
              instQuery34b = (**(code **)(*bodyInst + 0x34))(bodyInst);
              if ((instQuery34b == 0) && (instQuery34b = (**(code **)(*bodyInst + 0x38))(bodyInst), instQuery34b == 0)) {
                operandNumber = 1;
                instCursor = bodyInst;
                while( true ) {
                  operandCount = (**(code **)(*bodyInst + 0x14))(bodyInst);
                  if (operandCount < operandNumber) break;
                  operandNumber = operandNumber + 1;
                  Owner__removeVectorEntry(instCursor[0x29],bodyInst);
                  instCursor = instCursor + 6;
                }
                (**(code **)(*bodyInst + 0xc))(bodyInst,0,*(undefined4 *)(pass + 8));
                instNext = (int *)bodyInst[2];
              }
              else {
                instNext = (int *)bodyInst[2];
              }
            }
            bodyInst = instNext;
          }
          Block__detach(loopEndBlock);
          loopEndBlock = nextBodyBlock;
        }
        *lastBlockRef = findSimplePredecessorResult;
        exitBlock = *(undefined4 *)(block + 8);
      }
      else {
        if ((1 < unrollCount) && (block != loopEndBlock)) {
          blockOrdinal = 0;
          bodyBlockCursor = block;
          do {
            bodyBlockCursor = *(int *)(bodyBlockCursor + 8);
            *(int *)(bodyBlockCursor + 0xc0) = blockOrdinal;
            blockOrdinal = blockOrdinal + 1;
          } while (loopEndBlock != bodyBlockCursor);
        }
        hasBody = block != loopEndBlock;
        savedLoopFooter = *(int *)(block + 0x14c);
        bodyBlockCursor = block;
        moreBlocksA = hasBody;
        while (moreBlocksA) {
          bodyBlock = *(int **)(bodyBlockCursor + 8);
          bodyBlock[0x2e] = bodyBlock[0x2e] + -1;
          isLoopHeaderBlock = (**(code **)(*bodyBlock + 0x2c))(bodyBlock);
          if ((isLoopHeaderBlock != 0) && (block == bodyBlock[0x53])) {
            bodyBlock[0x53] = savedLoopFooter;
          }
          bodyBlockCursor = *(int *)(bodyBlockCursor + 8);
          moreBlocksA = loopEndBlock != bodyBlockCursor;
        }
        arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
        allocation = (undefined4 *)Arena__alloc(arena,0x14);
        cloneVector = allocation + 1;
        allocation[1] = 2;
        *allocation = arena;
        allocation[2] = 0;
        allocation[4] = arena;
        vectorData = Arena__alloc(arena,8);
        allocation[3] = vectorData;
        if (1 < unrollCount) {
          iteration = 1;
          prevCopyEnd = loopEndBlock;
          counterValue = loopStart;
          do {
            counterValue = counterValue + loopStep;
            if (hasBody) {
              origBlockCursor = block;
              cloneIndex = 0;
              do {
                lastCloneIndex = cloneIndex;
                origBlock = *(int **)(origBlockCursor + 8);
                clonedBlock = (**(code **)(*origBlock + 8))(origBlock);
                if (lastCloneIndex < *cloneVector) {
                  cloneFilledCountE = allocation[2];
                  if (cloneFilledCountE <= lastCloneIndex) {
                    _memset(cloneFilledCountE * 4 + allocation[3],0,(lastCloneIndex - cloneFilledCountE) * 4 + 4);
                    allocation[2] = lastCloneIndex + 1;
                  }
                  clonedBlockRef = (int *)(lastCloneIndex * 4 + allocation[3]);
                }
                else {
                  clonedBlockRef = (int *)Vector__elementRefGrow(cloneVector,lastCloneIndex);
                }
                *clonedBlockRef = clonedBlock;
                srcInst = (int *)origBlock[0x26];
                for (nextInstRef = (int *)((int *)origBlock[0x26])[2]; nextInstRef != (int *)0x0;
                    nextInstRef = (int *)nextInstRef[2]) {
                  instLinkedFlag = srcInst[5] & 1;
                  if (instLinkedFlag != 0) {
                    instQuery34 = (**(code **)(*srcInst + 0x34))(srcInst);
                    if (instQuery34 == 0) {
                      instQuery38 = (**(code **)(*srcInst + 0x38))(srcInst);
                      if (instQuery38 != 0) break;
                      extraBranchArg = 0;
                      cloneResult = IRInst__clone(srcInst,*(undefined4 *)(pass + 8),0);
                      if ((*(int *)(block + 0x134) == 0) &&
                         (needsOffsetFixClone = IRInst__hasOperandKindClass1(cloneResult), needsOffsetFixClone != 0)) {
                        extraBranchArg = pass;
                        ((int (*)())Program__rebaseInstRegisters)(cloneResult,counterValue,pass);
                      }
                      if ((*(uint *)(cloneResult + 0x14) & 0x10) != 0) {
                        Program__addInst(pass,cloneResult);
                      }
                      isIfHeader = (**(code **)(*origBlock + 0x24))(origBlock);
                      if (((int)((ulonglong)isIfHeader >> 0x20) != 0) &&
                         (nextInstRef = (int *)Block__getBranchInst(origBlock,(int)isIfHeader,extraBranchArg,loopStepArg,blockArg,
                                                        counterRefArg,instLinkedFlag), srcInst == nextInstRef)) {
                        *(int *)(clonedBlock + 0x130) = cloneResult;
                      }
                      isLoopHeader = (**(code **)(*origBlock + 0x2c))(origBlock);
                      if ((isLoopHeader != 0) && (srcInst == (int *)origBlock[0x52])) {
                        *(int *)(clonedBlock + 0x148) = cloneResult;
                      }
                      Program__appendInst(pass,cloneResult,clonedBlock);
                      nextInstRef = (int *)srcInst[2];
                    }
                    else {
                      nextInstRef = (int *)srcInst[2];
                    }
                  }
                  srcInst = nextInstRef;
                }
                Program__insertBlockAfter(pass,*lastBlockRef,clonedBlock);
                *lastBlockRef = clonedBlock;
                origBlockCursor = *(int *)(origBlockCursor + 8);
                cloneIndex = lastCloneIndex + 1;
              } while (loopEndBlock != origBlockCursor);
            }
            else {
              lastCloneIndex = 0xffffffff;
            }
            nextOrigBlock = *(int *)(block + 8);
            if (0 < (int)lastCloneIndex) {
              cloneIndex = 0;
              successorSlot = 1;
              do {
                if (cloneIndex < *cloneVector) {
                  cloneFilledCountA = allocation[2];
                  if (cloneFilledCountA <= cloneIndex) {
                    _memset(cloneFilledCountA * 4 + allocation[3],0,(cloneIndex - cloneFilledCountA) * 4 + 4);
                    allocation[2] = successorSlot;
                  }
                }
                else {
                  Vector__elementRefGrow(cloneVector,cloneIndex);
                }
                successorOffset = 0;
                for (successorIndex = 1; successorIndex <= *(uint *)(*(int *)(nextOrigBlock + 0xd0) + 4);
                    successorIndex = successorIndex + 1) {
                  successorBlock = *(int *)(successorOffset + *(int *)(*(int *)(nextOrigBlock + 0xd0) + 8));
                  if (successorBlock != 0) {
                    cloneCapacity = *cloneVector;
                    if (cloneIndex < cloneCapacity) {
                      cloneFilledCountB = allocation[2];
                      if (cloneFilledCountB <= cloneIndex) {
                        _memset(cloneFilledCountB * 4 + allocation[3],0,(cloneIndex - cloneFilledCountB) * 4 + 4);
                        cloneCapacity = *cloneVector;
                        allocation[2] = successorSlot;
                      }
                      cloneSlotRefA = (undefined4 *)(cloneIndex * 4 + allocation[3]);
                    }
                    else {
                      cloneSlotRefA = (undefined4 *)Vector__elementRefGrow(cloneVector,cloneIndex);
                      cloneCapacity = *cloneVector;
                    }
                    fromClone = *cloneSlotRefA;
                    successorCloneIndex = *(uint *)(successorBlock + 0xc0);
                    if (successorCloneIndex < cloneCapacity) {
                      cloneFilledCountC = allocation[2];
                      if (cloneFilledCountC <= successorCloneIndex) {
                        _memset(cloneFilledCountC * 4 + allocation[3],0,(successorCloneIndex - cloneFilledCountC) * 4 + 4);
                        allocation[2] = successorCloneIndex + 1;
                      }
                      cloneSlotRefB = (undefined4 *)(successorCloneIndex * 4 + allocation[3]);
                    }
                    else {
                      cloneSlotRefB = (undefined4 *)Vector__elementRefGrow(cloneVector,successorCloneIndex);
                    }
                    Block__connect(fromClone,*cloneSlotRefB);
                  }
                  successorOffset = successorOffset + 4;
                }
                cloneIndex = cloneIndex + 1;
                nextOrigBlock = *(int *)(nextOrigBlock + 8);
                successorSlot = successorSlot + 1;
              } while (lastCloneIndex != cloneIndex);
            }
            if (*cloneVector == 0) {
              cloneSlotRefC = (undefined4 *)Vector__elementRefGrow(cloneVector,0);
            }
            else {
              if (allocation[2] == 0) {
                *(undefined4 *)allocation[3] = 0;
                allocation[2] = 1;
              }
              cloneSlotRefC = (undefined4 *)allocation[3];
            }
            Block__connect(prevCopyEnd,*cloneSlotRefC);
            rewireCursor = block;
            moreBlocksB = hasBody;
            while (moreBlocksB) {
              rewireBlockCursor = *(int *)(rewireCursor + 8);
              targetCloneIndex = *(uint *)(rewireBlockCursor + 0xc0);
              if (targetCloneIndex < *cloneVector) {
                cloneFilledCountD = allocation[2];
                if (cloneFilledCountD <= targetCloneIndex) {
                  _memset(cloneFilledCountD * 4 + allocation[3],0,(targetCloneIndex - cloneFilledCountD) * 4 + 4);
                  allocation[2] = targetCloneIndex + 1;
                }
                cloneSlotRefD = (undefined4 *)(targetCloneIndex * 4 + allocation[3]);
              }
              else {
                cloneSlotRefD = (undefined4 *)Vector__elementRefGrow(cloneVector,targetCloneIndex);
              }
              clonedBlockObj = (int *)*cloneSlotRefD;
              blockQuery24 = (**(code **)(*clonedBlockObj + 0x24))(clonedBlockObj);
              if (blockQuery24 == 0) {
                blockQuery28 = (**(code **)(*clonedBlockObj + 0x28))(clonedBlockObj);
                if (blockQuery28 == 0) {
                  blockQuery2c = (**(code **)(*clonedBlockObj + 0x2c))(clonedBlockObj);
                  if (blockQuery2c == 0) {
                    blockQuery30 = (**(code **)(*clonedBlockObj + 0x30))(clonedBlockObj);
                    if (((blockQuery30 != 0) ||
                        (blockQuery30 = (**(code **)(*clonedBlockObj + 0x34))(clonedBlockObj), blockQuery30 != 0)) ||
                       (blockQuery30 = (**(code **)(*clonedBlockObj + 0x38))(clonedBlockObj), blockQuery30 != 0))
                    goto LAB_0012fafc;
                    (**(code **)(*clonedBlockObj + 0x3c))(clonedBlockObj);
                  }
                  else {
                    targetCloneIndex = *(uint *)(*(int *)(rewireBlockCursor + 0x150) + 0xc0);
                    if (targetCloneIndex < *cloneVector) {
                      cloneFilledCountD = allocation[2];
                      if (cloneFilledCountD <= targetCloneIndex) {
                        _memset(cloneFilledCountD * 4 + allocation[3],0,(targetCloneIndex - cloneFilledCountD) * 4 + 4);
                        allocation[2] = targetCloneIndex + 1;
                      }
                      rewiredCloneRef = (int *)(targetCloneIndex * 4 + allocation[3]);
                    }
                    else {
                      rewiredCloneRef = (int *)Vector__elementRefGrow(cloneVector,targetCloneIndex);
                    }
                    rewireBlockCursor = *(int *)(rewireBlockCursor + 0x154);
                    clonedBlockObj[0x54] = *rewiredCloneRef;
                    targetCloneIndex = *(uint *)(rewireBlockCursor + 0xc0);
                    if (targetCloneIndex < *cloneVector) {
                      cloneFilledCountD = allocation[2];
                      if (cloneFilledCountD <= targetCloneIndex) {
                        _memset(cloneFilledCountD * 4 + allocation[3],0,(targetCloneIndex - cloneFilledCountD) * 4 + 4);
                        allocation[2] = targetCloneIndex + 1;
                      }
                      rewiredCloneRef = (int *)(targetCloneIndex * 4 + allocation[3]);
                    }
                    else {
                      rewiredCloneRef = (int *)Vector__elementRefGrow(cloneVector,targetCloneIndex);
                    }
                    clonedBlockObj[0x55] = *rewiredCloneRef;
                  }
                }
                else {
LAB_0012fafc:
                  targetCloneIndex = *(uint *)(*(int *)(rewireBlockCursor + 300) + 0xc0);
                  if (targetCloneIndex < *cloneVector) {
                    cloneFilledCountD = allocation[2];
                    if (cloneFilledCountD <= targetCloneIndex) {
                      _memset(cloneFilledCountD * 4 + allocation[3],0,(targetCloneIndex - cloneFilledCountD) * 4 + 4);
                      allocation[2] = targetCloneIndex + 1;
                    }
                    rewiredCloneRef = (int *)(targetCloneIndex * 4 + allocation[3]);
                  }
                  else {
                    rewiredCloneRef = (int *)Vector__elementRefGrow(cloneVector,targetCloneIndex);
                  }
                  clonedBlockObj[0x4b] = *rewiredCloneRef;
                }
              }
              else {
                targetCloneIndex = *(uint *)(*(int *)(rewireBlockCursor + 0x13c) + 0xc0);
                if (targetCloneIndex < *cloneVector) {
                  cloneFilledCountD = allocation[2];
                  if (cloneFilledCountD <= targetCloneIndex) {
                    _memset(cloneFilledCountD * 4 + allocation[3],0,(targetCloneIndex - cloneFilledCountD) * 4 + 4);
                    allocation[2] = targetCloneIndex + 1;
                  }
                  rewiredCloneRef = (int *)(targetCloneIndex * 4 + allocation[3]);
                }
                else {
                  rewiredCloneRef = (int *)Vector__elementRefGrow(cloneVector,targetCloneIndex);
                }
                blockAt134 = *(int *)(rewireBlockCursor + 0x134);
                clonedBlockObj[0x4f] = *rewiredCloneRef;
                targetCloneIndex = *(uint *)(blockAt134 + 0xc0);
                if (targetCloneIndex < *cloneVector) {
                  cloneFilledCountD = allocation[2];
                  if (cloneFilledCountD <= targetCloneIndex) {
                    _memset(cloneFilledCountD * 4 + allocation[3],0,(targetCloneIndex - cloneFilledCountD) * 4 + 4);
                    allocation[2] = targetCloneIndex + 1;
                  }
                  rewiredCloneRef = (int *)(targetCloneIndex * 4 + allocation[3]);
                }
                else {
                  rewiredCloneRef = (int *)Vector__elementRefGrow(cloneVector,targetCloneIndex);
                }
                rewireBlockCursor = *(int *)(rewireBlockCursor + 0x138);
                clonedBlockObj[0x4d] = *rewiredCloneRef;
                targetCloneIndex = *(uint *)(rewireBlockCursor + 0xc0);
                if (targetCloneIndex < *cloneVector) {
                  cloneFilledCountD = allocation[2];
                  if (cloneFilledCountD <= targetCloneIndex) {
                    _memset(cloneFilledCountD * 4 + allocation[3],0,(targetCloneIndex - cloneFilledCountD) * 4 + 4);
                    allocation[2] = targetCloneIndex + 1;
                  }
                  rewiredCloneRef = (int *)(targetCloneIndex * 4 + allocation[3]);
                }
                else {
                  rewiredCloneRef = (int *)Vector__elementRefGrow(cloneVector,targetCloneIndex);
                }
                clonedBlockObj[0x4e] = *rewiredCloneRef;
              }
              rewireCursor = *(int *)(rewireCursor + 8);
              moreBlocksB = loopEndBlock != rewireCursor;
            }
            iteration = iteration + 1;
            prevCopyEnd = *lastBlockRef;
          } while (unrollCount != iteration);
        }
        fixupBlock = block;
        if (*(int *)(block + 0x134) == 0) {
          while (hasBody) {
            nextFixBlock = *(int *)(fixupBlock + 8);
            nextInst = *(int *)(*(int *)(nextFixBlock + 0x98) + 8);
            instListHead = *(int *)(nextFixBlock + 0x98);
            if (nextInst != 0) {
              do {
                instIter = nextInst;
                if ((*(uint *)(instListHead + 0x14) & 1) != 0) {
                  needsOffsetFix = IRInst__hasOperandKindClass1(instListHead);
                  if (needsOffsetFix == 0) {
                    instIter = *(int *)(instListHead + 8);
                  }
                  else {
                    ((int (*)())Program__rebaseInstRegisters)(instListHead,loopStart,pass);
                    instIter = *(int *)(instListHead + 8);
                  }
                }
                nextInst = *(int *)(instIter + 8);
                instListHead = instIter;
              } while (*(int *)(instIter + 8) != 0);
              nextFixBlock = *(int *)(fixupBlock + 8);
            }
            hasBody = loopEndBlock != nextFixBlock;
            fixupBlock = nextFixBlock;
          }
        }
      }
      Vector__removeAt(iStack0000001c,*(int *)(iStack0000001c + 4) + -1);
      *blockCounter = *blockCounter + -1;
      exitInst = *(int **)(block + 0x98);
      nextExitInst = (int *)(*(int **)(block + 0x98))[2];
      do {
        if (nextExitInst == (int *)0x0) {
          Block__bypass(block,findSimplePredecessorResult,exitBlock);
          if (unrollCount == 0) {
            Block__successorCount(findSimplePredecessorResult);
          }
          else {
            Block__successorCount(findSimplePredecessorResult);
            Block__predecessorCount(exitBlock);
          }
          blockVectorAt150 = *(int **)(block + 0x150);
          if (blockVectorAt150 != (int *)0x0) {
            (**(code **)(*blockVectorAt150 + 4))(blockVectorAt150);
          }
          blockVectorAt154 = *(int **)(block + 0x154);
          if (blockVectorAt154 != (int *)0x0) {
            (**(code **)(*blockVectorAt154 + 4))(blockVectorAt154);
          }
          Block__detach(block);
          arena = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
          allocation = (undefined4 *)Arena__alloc(arena,0x130);
          *allocation = arena;
          Block__ctor_ea020(allocation + 1,*(undefined4 *)(pass + 8));
          *newBlockOut = (int)(allocation + 1);
          allocation[0x2f] = *blockCounter;
          Program__insertBlockAfter(pass,*lastBlockRef,*newBlockOut);
          Block__connect(*lastBlockRef,*newBlockOut);
          ((int (*)())Program__splitCriticalEdges)(pass,findSimplePredecessorResult,*lastBlockRef);
          *lastBlockRef = *newBlockOut;
          return 1;
        }
        if ((exitInst[5] & 1U) != 0) {
          instQuery3c = (**(code **)(*exitInst + 0x3c))(exitInst);
          if (instQuery3c == 0) {
            if (*(int *)(exitInst[0x22] + 4) == 3) {
              if (*(int *)(block + 0x134) == 0) goto LAB_0012fc9c;
              Owner__removeVectorEntry(exitInst[0x29],exitInst);
              DList__unlink(exitInst);
              loopFooterBlock = *(int *)(block + 0x14c);
              IRInst__setOperandRef(exitInst,1,*(undefined4 *)(*(int *)(loopFooterBlock + 0x148) + 0x8c));
              IRInst__bindOperandRegisters(pass,exitInst);
              Block__appendInst(loopFooterBlock,exitInst);
              nextExitInst = (int *)exitInst[2];
            }
            else {
              nextExitInst = (int *)exitInst[2];
            }
          }
          else {
LAB_0012fc9c:
            Owner__removeVectorEntry(exitInst[0x29],exitInst);
            (**(code **)(*exitInst + 0xc))(exitInst,0,*(undefined4 *)(pass + 8));
            nextExitInst = (int *)exitInst[2];
          }
        }
        exitInst = nextExitInst;
        nextExitInst = (int *)nextExitInst[2];
      } while( true );
    }
  }
  return 0;
}

/* Program__isRegionTrivial @ 0x12fe8c (476 bytes) */
int Program__isRegionTrivial(program, startBlock, boundaryBlock)
  int program;
  int *startBlock;
  int boundaryBlock;
{
  int successor;
  int blockInstCount;
  int *elementRef;
  undefined4 *firstEntry;
  uint loopIndex;
  undefined4 result;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_44_buf [0x10];
  #define vecCapacity (*(uint *)(local_44_buf + 0x00))
  #define vecCount (*(uint *)(local_44_buf + 0x04))
  #define vecData (*(undefined4 * *)(local_44_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_44_buf + 0x0c))
  
  blockInstCount = DList__count(boundaryBlock + 0x90);
  if (2 < blockInstCount) {
    return 0;
  }
  *(int *)(program + PROG_visitStamp) = *(int *)(program + PROG_visitStamp) + 1;
  vecArena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
  vecCount = 0;
  vecCapacity = 2;
  vecData = (undefined4 *)Arena__alloc(vecArena,8);
  do {
    blockInstCount = (**(code **)(*startBlock + 0x24))(startBlock);
    if (blockInstCount == 0) {
      blockInstCount = DList__count(startBlock + 0x24);
      if (((2 < blockInstCount) || (blockInstCount = (**(code **)(*startBlock + 0x38))(startBlock), blockInstCount != 0)) ||
         (blockInstCount = (**(code **)(*startBlock + 0x3c))(startBlock), blockInstCount != 0)) goto LAB_00130080;
    }
    else {
      blockInstCount = DList__count(startBlock + 0x24);
      if (3 < blockInstCount) {
LAB_00130080:
        result = 0;
        goto code_r0x0013008c;
      }
    }
    blockInstCount = 0;
    for (loopIndex = 1; loopIndex <= *(uint *)(startBlock[0x34] + 4); loopIndex = loopIndex + 1) {
      successor = *(int *)(*(int *)(startBlock[0x34] + 8) + blockInstCount);
      if (((successor != 0) && (*(int *)(program + PROG_visitStamp) != *(int *)(successor + 0x118))) &&
         (boundaryBlock != successor)) {
        *(int *)(successor + 0x118) = *(int *)(program + PROG_visitStamp);
        if (vecCount < vecCapacity) {
          vecData[vecCount] = 0;
          elementRef = vecData + vecCount;
          vecCount = vecCount + 1;
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
        }
        *elementRef = successor;
      }
      blockInstCount = blockInstCount + 4;
    }
    if (vecCount == 0) {
LAB_00130088:
      result = 1;
code_r0x0013008c:
      Arena__free(vecArena,vecData);
      return result;
    }
    firstEntry = vecData;
    if (vecCapacity == 0) {
      firstEntry = (undefined4 *)Vector__elementRefGrow(&vecCapacity,0);
    }
    startBlock = (int *)*firstEntry;
    if ((startBlock == (int *)0x0) || (blockInstCount = Vector__removeValue(&vecCapacity,startBlock), blockInstCount == 0))
    goto LAB_00130088;
  } while( true );
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* pass_remove_empty_graphs @ 0x1300b0 (836 bytes) */
int pass_remove_empty_graphs(program)
  int program;
{
  bool changed;
  int testResult;
  int *nextBlock;
  int *predecessorBlock;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  code *in_r9;
  int joinBlock;
  int elseBlock;
  int thenBlock;
  int *successorOrNextBlock;
  int *block;
  undefined8 regionResult;
  
  while( true ) {
    successorOrNextBlock = (int *)(*(int **)(program + PROG_blockListHead))[2];
    if (successorOrNextBlock == (int *)0x0) break;
    changed = false;
    block = *(int **)(program + PROG_blockListHead);
    do {
      nextBlock = successorOrNextBlock;
      testResult = (**(code **)(*block + 0x24))(block);
      if (testResult == 0) {
        testResult = Block__isSimple(block);
        if ((((testResult != 0) && (testResult = DList__count(block + 0x24), testResult < 3)) &&
            (testResult = Block__predecessorCount(block), testResult == 1)) &&
           (testResult = Block__successorCount(block), testResult == 1)) {
          predecessorBlock = (int *)Block__getPredecessor(block,0);
          successorOrNextBlock = (int *)Block__getSuccessor(block,0);
          testResult = Block__isSimple(predecessorBlock);
          if (((testResult != 0) || (testResult = (**(code **)(*predecessorBlock + 0x1c))(predecessorBlock), testResult != 0)) &&
             ((testResult = Block__isSimple(successorOrNextBlock), testResult != 0 ||
              (testResult = (**(code **)(*successorOrNextBlock + 0x20))(successorOrNextBlock), testResult != 0)))) {
            Block__bypassAndDetach(block,predecessorBlock,successorOrNextBlock);
            goto LAB_0013037c;
          }
        }
      }
      else {
        joinBlock = block[0x4f];
        thenBlock = block[0x4d];
        elseBlock = block[0x4e];
        testResult = joinBlock;
        regionResult = ((int (*)())Program__isRegionTrivial)(program,block,joinBlock);
        if ((int)((ulonglong)regionResult >> 0x20) == 0) {
          testResult = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x21);
          if (((testResult != 0) && (testResult = Block__hasMultipleSuccessors(thenBlock), testResult == 0)) &&
             ((testResult = Block__getSuccessor(thenBlock,0), testResult == joinBlock &&
              ((testResult = DList__count(thenBlock + 0x90), testResult < 3 &&
               (testResult = DList__count(elseBlock + 0x90), 2 < testResult)))))) {
            IfHeader__swapArms(program,block);
            nextBlock = (int *)block[0x4d];
            changed = true;
          }
        }
        else {
          successorOrNextBlock = (int *)Block__getBranchInst(block,(int)regionResult,testResult,in_r6,in_r7,in_r8,in_r9);
          if (successorOrNextBlock != (int *)0x0) {
            Program__removeInst(program,successorOrNextBlock);
            successorOrNextBlock[5] = successorOrNextBlock[5] & 0xffffffef;
            in_r9 = *(code **)(*successorOrNextBlock + 0xc);
            (*in_r9)(successorOrNextBlock,*(uint *)(program + PROG_flags) >> 7 & 1,*(undefined4 *)(program + PROG_compiler),in_r6,
                     in_r7,in_r8,in_r9);
            block[0x4c] = 0;
          }
          block[3] = block[3] | 0x100;
          nextBlock = (int *)Block__getPredecessor(block,0);
          testResult = block[0x3c];
          Vector__removeValue(nextBlock[0x34],block);
          successorOrNextBlock = (int *)Block__findSimpleSuccessor(joinBlock);
          Vector__removeValue(successorOrNextBlock[0x35],joinBlock);
          Block__connect(nextBlock,successorOrNextBlock);
          successorOrNextBlock[0x3c] = testResult;
          ((int (*)())Program__detachRegion)(program,block,joinBlock);
          (**(code **)(*nextBlock + 0x48))(nextBlock);
          (**(code **)(*successorOrNextBlock + 0x48))(successorOrNextBlock);
          testResult = Program__mergeBlockWithSuccessor(program,nextBlock,successorOrNextBlock);
          if (testResult == 0) {
LAB_0013037c:
            changed = true;
            nextBlock = successorOrNextBlock;
          }
          else {
            nextBlock = (int *)Block__getSuccessor(nextBlock,0);
            changed = true;
          }
        }
      }
      successorOrNextBlock = (int *)nextBlock[2];
      block = nextBlock;
    } while ((int *)nextBlock[2] != (int *)0x0);
    if (!changed) break;
    *(undefined4 *)(program + PROG_workArray0) = 0;
    *(undefined4 *)(program + PROG_workArray1) = 0;
    *(undefined4 *)(program + PROG_workArray2) = 0;
    testResult = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x11);
    if (testResult != 0) {
      Program__eliminateDeadInstsAndRecountUses(program,0);
    }
  }
  return Program__beginPass(program,(int)"remove_empty_graphs");
}

/* Array4__contains @ 0x1303f4 (48 bytes) */
int Array4__contains(value, table)
  int value;
  int table;
{
  int byteOffset;
  int remaining;
  
  byteOffset = 0;
  remaining = 4;
  do {
    if (*(int *)(byteOffset + table) == value) {
      return 1;
    }
    byteOffset = byteOffset + 4;
    remaining = remaining + -1;
  } while (remaining != 0);
  return 0;
}

/* RegAlloc__nextTempId @ 0x130424 (32 bytes) */
int RegAlloc__nextTempId(allocator)
  int allocator;
{
  int tempId;
  
  tempId = *(int *)(*(int *)(allocator + 0x2c) + 0x3c4) + 1;
  *(int *)(*(int *)(allocator + 0x2c) + 0x3c4) = tempId;
  return tempId + *(int *)(allocator + 8);
}

/* Program__markHwRegUsed @ 0x130444 (52 bytes) */
int Program__markHwRegUsed(program, hwReg)
  int program;
  uint hwReg;
{
  int bitsetWord;
  
  bitsetWord = (hwReg >> 3 & 0x1ffffffc) + *(int *)(program + 0x42c);
  *(uint *)(bitsetWord + 8) =
       (-2 << (hwReg & 0x1f) | 0xfffffffeU >> 0x20 - (hwReg & 0x1f)) & *(uint *)(bitsetWord + 8);
  *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 0x8000;
  return;
}

/* RegAlloc__testBit42c @ 0x130478 (44 bytes) */
int RegAlloc__testBit42c(allocator, bitIndex)
  int allocator;
  uint bitIndex;
{
  if ((*(uint *)((bitIndex >> 3 & 0x1ffffffc) + *(int *)(allocator + 0x42c) + 8) >> (bitIndex & 0x1f) &
      1) != 0) {
    return 1;
  }
  return 0;
}

/* RegAlloc__countUnassignedHwRegs @ 0x1304a4 (200 bytes) */
int RegAlloc__countUnassignedHwRegs(allocator)
  int allocator;
{
  int isPhysicalOrAssigned;
  int loopIndex;
  int physicalRegCountA;
  int physicalRegCountB;
  int compilerThenTotal;
  int *backend;
  int virtualRegCount;
  
  virtualRegCount = 0;
  compilerThenTotal = *(int *)(allocator + 8);
  backend = *(int **)(compilerThenTotal + 0x30c);
  physicalRegCountA = (**(code **)(*backend + 0x138))(backend,compilerThenTotal);
  physicalRegCountB = (**(code **)(*backend + 0x140))(backend,compilerThenTotal);
  compilerThenTotal = (**(code **)(*backend + 0x13c))(backend,compilerThenTotal);
  compilerThenTotal = physicalRegCountA + physicalRegCountB + compilerThenTotal;
  if (0 < compilerThenTotal) {
    loopIndex = 0;
    do {
      isPhysicalOrAssigned = ((int (*)())RegAlloc__testBit42c)(allocator,loopIndex);
      if (isPhysicalOrAssigned == 0) {
        virtualRegCount = virtualRegCount + 1;
      }
      loopIndex = loopIndex + 1;
    } while (compilerThenTotal != loopIndex);
  }
  return virtualRegCount;
}

/* BitSet__setBit42c @ 0x13056c (40 bytes) */
int BitSet__setBit42c(allocator, bitIndex)
  int allocator;
  uint bitIndex;
{
  int wordRef;
  
  wordRef = (bitIndex >> 3 & 0x1ffffffc) + *(int *)(allocator + 0x42c);
  *(uint *)(wordRef + 8) = 1 << (bitIndex & 0x1f) | *(uint *)(wordRef + 8);
  return;
}

/* RegAlloc__highestUnassignedInClass @ 0x130594 (136 bytes) */
int RegAlloc__highestUnassignedInClass(allocator, classNumber)
  int allocator;
  int classNumber;
{
  int registerNumber;
  int classEnd;
  int callResult;
  int classTableAddr;
  int highestUnassigned;
  int classStart;
  
  classTableAddr = classNumber * 4 + allocator;
  highestUnassigned = -1;
  classEnd = *(int *)(classTableAddr + 0x448);
  classStart = *(int *)(classTableAddr + 0x43c);
  registerNumber = classStart;
  if (classStart < classEnd) {
    do {
      callResult = ((int (*)())RegAlloc__testBit42c)(allocator,registerNumber);
      if ((callResult == 0) && (highestUnassigned < registerNumber)) {
        highestUnassigned = registerNumber;
      }
      registerNumber = registerNumber + 1;
    } while (classEnd != registerNumber);
    if (-1 < highestUnassigned) {
      highestUnassigned = highestUnassigned - classStart;
    }
  }
  return highestUnassigned;
}

/* RegAlloc__countUnassignedInClass @ 0x13061c (116 bytes) */
int RegAlloc__countUnassignedInClass(allocator, classNumber)
  int allocator;
  int classNumber;
{
  int classEnd;
  int callResult;
  int classTableAddrThenReg;
  int unassignedCount;
  
  classTableAddrThenReg = classNumber * 4 + allocator;
  unassignedCount = 0;
  classEnd = *(int *)(classTableAddrThenReg + 0x448);
  classTableAddrThenReg = *(int *)(classTableAddrThenReg + 0x43c);
  if (classTableAddrThenReg < classEnd) {
    do {
      callResult = ((int (*)())RegAlloc__testBit42c)(allocator,classTableAddrThenReg);
      if (callResult == 0) {
        unassignedCount = unassignedCount + 1;
      }
      classTableAddrThenReg = classTableAddrThenReg + 1;
    } while (classTableAddrThenReg != classEnd);
  }
  return unassignedCount;
}

/* RegAlloc__allocateFirstFreeInClass @ 0x130690 (152 bytes) */
int RegAlloc__allocateFirstFreeInClass(program, classNumber)
  int program;
  int classNumber;
{
  int newEntryIndex;
  int hwRegister;
  int callResult;
  
  hwRegister = ((int (*)())RegAlloc__countUnassignedInClass)(program,classNumber);
  if (classNumber == 1) {
    hwRegister = hwRegister + 0x20;
  }
  callResult = ((int (*)())RegAlloc__testBit42c)(program,hwRegister);
  if (callResult == 0) {
    Compiler__fail(*(undefined4 *)(program + 8),4);
  }
  ((int (*)())Program__markHwRegUsed)(program,hwRegister);
  *(int *)(*(int *)(program + 0x470) * 4 + *(int *)(program + 0x458)) = hwRegister;
  *(int *)(*(int *)(program + 0x470) * 4 + *(int *)(program + 0x45c)) = classNumber;
  newEntryIndex = *(int *)(program + 0x470);
  *(int *)(program + 0x470) = newEntryIndex + 1;
  return newEntryIndex;
}

/* IRInst__chainLast @ 0x130728 (164 bytes) */
int IRInst__chainLast(inst)
  int *inst;
{
  int instQuery28;
  int *nextInst;
  uint instFlags;
  int instQuery34;
  
  instQuery34 = (**(code **)(*inst + 0x34))(inst);
  if (instQuery34 == 0) {
    instQuery28 = (**(code **)(*inst + 0x28))(inst);
    nextInst = inst;
    if (instQuery28 == 0) {
      do {
        inst = nextInst;
        nextInst = (int *)inst[1];
      } while ((((int *)inst[1])[5] & 4U) != 0);
    }
    else {
      instFlags = inst[5];
      while ((instFlags & 0x1000) == 0) {
        inst = (int *)inst[1];
        instFlags = inst[5];
      }
    }
  }
  return inst;
}

/* IRInst__chainLastOfPredecessor @ 0x1307cc (44 bytes) */
int IRInst__chainLastOfPredecessor(inst)
  undefined4 inst;
{
  int chainNode;
  undefined4 callResult;
  
  chainNode = ((int (*)())IRInst__chainLast)(inst);
  callResult = ((int (*)())IRInst__chainLast)(*(undefined4 *)(chainNode + 4));
  return callResult;
}

/* IRInst__advanceToChainEnd @ 0x1307f8 (228 bytes) */
int IRInst__advanceToChainEnd(inst)
  int *inst;
{
  uint nextHasMarkBit;
  int instQuery74;
  int instQuery28;
  int *previousInst;
  int *cursorInst;
  int instQuery38;
  uint instFlags;
  
  instQuery38 = (**(code **)(*inst + 0x38))(inst);
  if (instQuery38 == 0) {
    instQuery28 = (**(code **)(*inst + 0x28))(inst);
    if (instQuery28 == 0) {
      instFlags = inst[5];
      while ((instFlags & 4) != 0) {
        inst = (int *)inst[2];
        instFlags = inst[5];
      }
    }
    else {
      instQuery74 = (**(code **)(*inst + 0x74))(inst);
      if (instQuery74 == 0) {
        nextHasMarkBit = (**(code **)(*inst + 0x78))(inst);
        cursorInst = inst;
        while (previousInst = cursorInst, nextHasMarkBit == 0) {
          cursorInst = (int *)previousInst[2];
          nextHasMarkBit = cursorInst[5] & 0x1000;
          inst = previousInst;
        }
      }
    }
  }
  return inst;
}

/* IRInst__chainEndNext @ 0x1308e0 (36 bytes) */
int IRInst__chainEndNext(pendingInst)
  undefined4 pendingInst;
{
  int chainEnd;
  
  chainEnd = ((int (*)())IRInst__advanceToChainEnd)(pendingInst);
  return *(undefined4 *)(chainEnd + 8);
}

/* IRInst__chainEndSkippingFlag4000000 @ 0x130904 (64 bytes) */
int IRInst__chainEndSkippingFlag4000000(inst)
  undefined4 inst;
{
  int chainNode;
  undefined4 callResult;
  
  chainNode = ((int (*)())IRInst__chainLastOfPredecessor)(inst);
  if ((*(uint *)(chainNode + 0x14) & 0x4000000) != 0) {
    chainNode = ((int (*)())IRInst__chainLastOfPredecessor)(inst);
  }
  callResult = ((int (*)())IRInst__advanceToChainEnd)(chainNode);
  return callResult;
}

/* Record__field98IsBelow2 @ 0x130944 (20 bytes) */
int Record__field98IsBelow2(record)
  int record;
{
  return *(uint *)(record + 0x98) < 2;
}

/* BitSet__testRegisterLane_130958 @ 0x130958 (36 bytes) */
int BitSet__testRegisterLane_130958(bitSet, registerIndex, lane)
  int bitSet;
  int registerIndex;
  int lane;
{
  uint bitIndex;
  
  bitIndex = registerIndex * 4 + lane;
  return *(uint *)((bitIndex >> 3 & 0x1ffffffc) + bitSet + 8) >> (bitIndex & 0x1f) & 1;
}

/* BitSet__testAnyLane @ 0x13097c (64 bytes) */
int BitSet__testAnyLane(liveWords, registerIndex)
  int liveWords;
  int registerIndex;
{
  uint bitIndex;
  int remainingLanes;
  
  bitIndex = registerIndex << 2;
  remainingLanes = 4;
  do {
    if ((*(uint *)((bitIndex >> 3 & 0x1ffffffc) + liveWords + 8) >> (bitIndex & 0x1f) & 1) != 0) {
      return 1;
    }
    bitIndex = bitIndex + 1;
    remainingLanes = remainingLanes + -1;
  } while (remainingLanes != 0);
  return 0;
}

/* RegAlloc__testBit24 @ 0x1309bc (32 bytes) */
int RegAlloc__testBit24(allocator, sourceRegister)
  int allocator;
  uint sourceRegister;
{
  return *(uint *)((sourceRegister >> 3 & 0x1ffffffc) + *(int *)(allocator + 0x24) + 8) >> (sourceRegister & 0x1f) &
         1;
}

/* Program__isHwRegAllowed @ 0x1309dc (44 bytes) */
int Program__isHwRegAllowed(program, hwReg)
  int program;
  uint hwReg;
{
  if ((*(uint *)((hwReg >> 3 & 0x1ffffffc) + *(int *)(program + 0x430) + 8) >> (hwReg & 0x1f) &
      1) != 0) {
    return 1;
  }
  return 0;
}

/* IRInst__findChainNodeById @ 0x130a08 (112 bytes) */
int IRInst__findChainNodeById(inst, targetId)
  undefined4 inst;
  int targetId;
{
  int chainEnd;
  int query74;
  int *cursorInst;
  
  chainEnd = ((int (*)())IRInst__chainLast)(inst);
  cursorInst = *(int **)(chainEnd + 4);
  while( true ) {
    query74 = (**(code **)(*cursorInst + 0x74))(cursorInst);
    if (query74 == 0) {
      return (int *)0x0;
    }
    if (*(int *)(cursorInst[0x30] + 0x13c) == targetId) break;
    cursorInst = (int *)cursorInst[1];
  }
  return cursorInst;
}

/* IRInst__findSameClassNode @ 0x130a78 (68 bytes) */
int IRInst__findSameClassNode(cursorInst, referenceInst)
  uint cursorInst;
  int referenceInst;
{
  uint *nodeFlags;
  uint continueFlag;
  
  continueFlag = cursorInst;
  while( true ) {
    if (continueFlag == 0) {
      return 0;
    }
    nodeFlags = (uint *)(cursorInst + 0x14);
    if (((*nodeFlags & 1) != 0) && (*(int *)(cursorInst + 0x14c) == *(int *)(referenceInst + 0x14c))) break;
    cursorInst = *(uint *)(cursorInst + 8);
    continueFlag = *nodeFlags & 4;
    if (cursorInst == 0) {
      return 0;
    }
  }
  return cursorInst;
}

/* RegAlloc__markReloadModifiers @ 0x130abc (280 bytes) */
int RegAlloc__markReloadModifiers(spillInfo, allocator, markFlag)
  undefined4 spillInfo;
  uint allocator;
  uint markFlag;
{
  undefined8 sourceCheckResult;
  int *operandModifierPtr;
  int operandNumber;
  undefined4 sourceDef;
  uint instFlags;
  int *spilledInst;
  int *reloadInst;
  int instQuery24;
  undefined4 staleArg4;
  int operandCountLimit;
  undefined4 staleArg4A;
  undefined4 staleArg4B;
  undefined4 staleArg4C;
  int *instCursor;
  int *cursorOrBlockFlag;
  undefined8 reloadPair;
  
  spilledInst = (int *)((int (*)())IRInst__chainLastOfPredecessor)(spillInfo);
  reloadPair = ((int (*)())IRInst__chainLast)(spillInfo);
  reloadInst = (int *)((ulonglong)reloadPair >> 0x20);
  instQuery24 = (**(code **)(*spilledInst + 0x24))(spilledInst,(int)reloadPair,markFlag);
  if (((instQuery24 != 0) && ((spilledInst[5] & 0x4000000U) == 0)) &&
     (instCursor = reloadInst, staleArg4 = staleArg4A, cursorOrBlockFlag = reloadInst, (reloadInst[5] & 0x1000U) == 0)) {
    do {
      if (cursorOrBlockFlag == (int *)0x0) {
        return;
      }
      instFlags = instCursor[5];
      if ((instFlags & 1) != 0) {
        operandModifierPtr = instCursor + 0x29;
        for (operandNumber = 1; operandCountLimit = (**(code **)(*instCursor + 0x14))(instCursor,staleArg4,markFlag), operandNumber <= operandCountLimit;
            operandNumber = operandNumber + 1) {
          sourceDef = IRInst__getOperandSource(instCursor,operandNumber);
          sourceCheckResult = ((int (*)())IRInst__findSameClassNode)(spilledInst,sourceDef);
          staleArg4 = (undefined4)sourceCheckResult;
          if ((int)((ulonglong)sourceCheckResult >> 0x20) != 0) {
            markFlag = 1;
            reloadInst[5] = reloadInst[5] | 0x10000000;
            IROperand__setModifierBits(operandModifierPtr,4,1);
            staleArg4 = staleArg4B;
          }
          operandModifierPtr = operandModifierPtr + 6;
        }
        instFlags = instCursor[5];
        staleArg4 = staleArg4C;
      }
      instCursor = (int *)instCursor[2];
      cursorOrBlockFlag = (int *)(instFlags & 4);
    } while (instCursor != (int *)0x0);
  }
  return;
}

/* RegAlloc__clearBit430 @ 0x130bd4 (40 bytes) */
int RegAlloc__clearBit430(allocator, bitIndex)
  int allocator;
  uint bitIndex;
{
  int wordRef;
  
  wordRef = (bitIndex >> 3 & 0x1ffffffc) + *(int *)(allocator + 0x430);
  *(uint *)(wordRef + 8) =
       (-2 << (bitIndex & 0x1f) | 0xfffffffeU >> 0x20 - (bitIndex & 0x1f)) & *(uint *)(wordRef + 8);
  return;
}

/* RegAlloc__classOfInst @ 0x130bfc (144 bytes) */
int RegAlloc__classOfInst(allocator, inst)
  int allocator;
  int inst;
{
  int classCount;
  int classNumber;
  
  classCount = *(int *)(*(int *)(*(int *)(allocator + 8) + 0x30c) + 0x14);
  if (*(int *)(inst + 0x98) != 0) {
    if (*(int *)(inst + 0x98) == 1) {
      return 1;
    }
    return -1;
  }
  if ((*(uint *)(inst + 0x14) & 0x40) == 0) {
    return 0;
  }
  if (0 < classCount) {
    classNumber = 0;
    do {
      if ((*(int *)(allocator + 0x43c) <= *(int *)(inst + 0x94)) &&
         (*(int *)(inst + 0x94) < *(int *)(allocator + 0x448))) {
        return classNumber;
      }
      classNumber = classNumber + 1;
      allocator = allocator + 4;
      classCount = classCount + -1;
    } while (classCount != 0);
  }
  return -1;
}

/* RegAlloc__emitSpillReload @ 0x130c8c (276 bytes) */
int RegAlloc__emitSpillReload(allocator, spillRecord, newSource, registerCountRef)
  int allocator;
  undefined4 spillRecord;
  int newSource;
  int *registerCountRef;
{
  undefined4 anchorInstWord4;
  undefined4 sourceRegKind;
  int anchorInst;
  int callResult;
  int *backend;
  int backendQuery150;
  int program;
  
  anchorInst = ((int (*)())IRInst__chainLast)(spillRecord);
  program = *(int *)(*(int *)(allocator + 0x2c) + 0x6c4);
  callResult = IRInst__create(0x31,*(int *)(allocator + 0x2c));
  sourceRegKind = *(undefined4 *)(newSource + 0x98);
  *(int *)(callResult + 0x94) = *registerCountRef;
  *(undefined4 *)(callResult + 0x98) = sourceRegKind;
  IRInst__setOperandSource(callResult,1,newSource,0,*(undefined4 *)(allocator + 0x2c));
  anchorInstWord4 = *(undefined4 *)(anchorInst + 4);
  *(uint *)(callResult + 0x14) = *(uint *)(callResult + 0x14) & 0xffffffbf | 0x80000000;
  backend = *(int **)(*(int *)(allocator + 0x2c) + 0x30c);
  backendQuery150 = (**(code **)(*backend + 0x150))(backend,anchorInstWord4);
  if (backendQuery150 != 0) {
    *(uint *)(callResult + 0x14) = *(uint *)(callResult + 0x14) | 0x1000;
  }
  Block__insertInstBefore(*(undefined4 *)(anchorInst + 0x158),anchorInst,callResult);
  *(undefined4 *)(*registerCountRef * 4 + *(int *)(program + 0x45c)) = 0;
  *(undefined4 *)(*registerCountRef * 4 + *(int *)(program + 0x458)) = 0xffffffff;
  **(int **)(allocator + 0x18) = **(int **)(allocator + 0x18) + 1;
  *registerCountRef = *registerCountRef + 1;
  return callResult;
}

/* RegAlloc__cloneSourceDefAfter @ 0x130da0 (200 bytes) */
int RegAlloc__cloneSourceDefAfter(allocator, inst, operandIndex, afterInst, compiler)
  undefined4 allocator;
  int inst;
  undefined4 operandIndex;
  int afterInst;
  undefined4 compiler;
{
  undefined4 sourceDef;
  undefined4 newTempId;
  int callResult;
  
  sourceDef = IRInst__getOperandSource(inst,operandIndex);
  callResult = IRInst__clone(sourceDef,compiler,0);
  if ((*(uint *)(inst + 0x14) & 0x40) == 0) {
    newTempId = ((int (*)())RegAlloc__nextTempId)(allocator);
    *(undefined4 *)(callResult + 0x98) = 0;
    *(undefined4 *)(callResult + 0x94) = newTempId;
  }
  Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,callResult);
  *(uint *)(callResult + 0x14) = *(uint *)(callResult + 0x14) | 0x8000000;
  IRInst__setOperandSource(inst,operandIndex,callResult,0,compiler);
  *(uint *)(inst + 0x18) = *(uint *)(inst + 0x18) | 1;
  *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) & 0xffffeffb | 0x8000000;
  return callResult;
}

/* IRInst__isQuery28OrOpcode93 @ 0x130e68 (88 bytes) */
int IRInst__isQuery28OrOpcode93(inst)
  int *inst;
{
  int query28;
  undefined4 result;
  
  query28 = (**(code **)(*inst + 0x28))(inst);
  if ((query28 != 0) || (result = 0, *(int *)(inst[0x22] + 8) == 0x93)) {
    result = 1;
  }
  return result;
}

/* Program__appendLoadFa @ 0x130ec0 (72 bytes) */
int Program__appendLoadFa(baseHandle, derivedHandle, compiler)
  undefined4 baseHandle;
  undefined4 derivedHandle;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  undefined4 *loadInst;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  loadInst = allocation + 1;
  *allocation = arena;
  IRLoad__ctor_109a80(loadInst,0xfa,compiler);
  allocation[0x4d] = baseHandle;
  allocation[0x27] = 0x3b;
  allocation[0x4e] = derivedHandle;
  allocation[0x26] = baseHandle;
  Block__appendInst(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3a0),loadInst);
  return loadInst;
}

/* Program__prependLoad79 @ 0x130f64 (72 bytes) */
int Program__prependLoad79(param_1, newSlotNumber, compiler)
  undefined4 param_1;
  undefined4 newSlotNumber;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  undefined4 *loadInst;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  loadInst = allocation + 1;
  *allocation = arena;
  IRLoad__ctor_109a80(loadInst,0x79,compiler);
  allocation[0x4d] = param_1;
  allocation[0x27] = 0x3c;
  allocation[0x50] = newSlotNumber;
  allocation[0x26] = newSlotNumber;
  Block__prependInst(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3a0),loadInst);
  return loadInst;
}

/* RegAlloc__laneDependsOnChain @ 0x131008 (452 bytes) */
int RegAlloc__laneDependsOnChain(maxDistance, inst, operandIndex)
  int maxDistance;
  int *inst;
  undefined4 operandIndex;
{
  int laneDependsOnChain;
  int blockQuery24;
  int operandRecord;
  bool atLastLane;
  int laneIndex;
  undefined4 operandVReg;
  undefined4 laneDefinition;
  int *chainInst;
  int instQuery34;
  int loopIndex;
  undefined4 laneMaskWord;
  undefined1 laneDefOut [12];
  undefined4 laneMaskOut [5];
  
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  SelectWord__readMask(laneMaskOut,*(undefined4 *)(operandRecord + 0x10));
  laneMaskWord = laneMaskOut[0];
  operandVReg = IRInst__getOperandSource(inst,operandIndex);
  laneIndex = 0;
  do {
    if ((laneDefOut[laneIndex + -4] != '\0') &&
       (laneDefinition = IRInst__findLaneDefinition(operandVReg,laneIndex,laneDefOut), -1 < maxDistance)) {
      loopIndex = 0;
      chainInst = inst;
      do {
        do {
          do {
            chainInst = (int *)((int (*)())IRInst__chainLastOfPredecessor)(chainInst);
          } while ((chainInst[5] & 0x4000000U) != 0);
          instQuery34 = (**(code **)(*chainInst + 0x34))(chainInst);
        } while ((((instQuery34 != 0) || (instQuery34 = (**(code **)(*chainInst + 0x68))(chainInst), instQuery34 != 0)) ||
                 (*(int *)(chainInst[0x22] + 8) == 0x8e)) ||
                ((instQuery34 = (**(code **)(*chainInst + 0x74))(chainInst), instQuery34 != 0 ||
                 (instQuery34 = (**(code **)(*chainInst + 0x78))(chainInst), instQuery34 != 0))));
        loopIndex = loopIndex + 1;
        blockQuery24 = (**(code **)(*(int *)inst[0x56] + 0x24))((int *)inst[0x56]);
        if ((blockQuery24 == 0) &&
           ((blockQuery24 = (**(code **)(*(int *)inst[0x56] + 0x2c))((int *)inst[0x56]), blockQuery24 == 0
            && (chainInst[0x56] != inst[0x56])))) {
          return 1;
        }
        laneDependsOnChain = ((int (*)())IRInst__findSameClassNode)(chainInst,laneDefinition);
        if (laneDependsOnChain != 0) {
          return 0;
        }
      } while (loopIndex <= maxDistance);
    }
    atLastLane = laneIndex == 3;
    laneIndex = laneIndex + 1;
    if (atLastLane) {
      return 1;
    }
  } while( true );
}

/* Program__insertMemLoadFbAfter @ 0x1311cc (88 bytes) */
int Program__insertMemLoadFbAfter(destRegister, operandSwizzle, newSource, offsetSource, afterInst, compiler)
  undefined4 destRegister;
  undefined4 operandSwizzle;
  undefined4 newSource;
  undefined4 offsetSource;
  int afterInst;
  int compiler;
{
  undefined4 offsetSwizzleConstant;
  undefined4 baseSwizzleConstant;
  undefined4 arena;
  undefined4 *allocation;
  int operandRecord;
  undefined4 writeMaskConstant;
  undefined4 *loadInst;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  loadInst = allocation + 1;
  *allocation = arena;
  IRMemLoad__ctor_107980(loadInst,0xfb,compiler);
  writeMaskConstant = UNK_001affe4;
  allocation[0x27] = 0;
  allocation[0x28] = writeMaskConstant;
  allocation[0x26] = destRegister;
  IRInst__setOperandSource(loadInst,1,newSource,0,compiler);
  baseSwizzleConstant = UNK_001affe0;
  operandRecord = IRInst__getOperandRecord(loadInst,1);
  *(undefined4 *)(operandRecord + 0x10) = baseSwizzleConstant;
  IRInst__setOperandSource(loadInst,2,offsetSource,0,compiler);
  offsetSwizzleConstant = UNK_001affdc;
  operandRecord = IRInst__getOperandRecord(loadInst,2);
  *(undefined4 *)(operandRecord + 0x10) = offsetSwizzleConstant;
  Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,loadInst);
  allocation[6] = allocation[6] | 0x8001000;
  return loadInst;
}

/* RegAlloc__emitSpillStore @ 0x1312f4 (228 bytes) */
int RegAlloc__emitSpillStore(inst, newSource, addressSource, ref, compiler)
  int inst;
  int newSource;
  undefined4 addressSource;
  int ref;
  int compiler;
{
  undefined4 insertAfterWord;
  undefined4 addressSwizzleConstant;
  undefined4 arena;
  bool moreLanes;
  int operandRecord;
  int operandRecord2;
  undefined4 *allocation;
  int laneIndex;
  undefined4 spillDestRegister;
  undefined4 *storeInst;
  undefined4 writtenLaneMask [4];
  undefined4 local_38;
  undefined4 storeWriteMask [3];
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  writtenLaneMask[0] = *(undefined4 *)(operandRecord + 0x10);
  if (((*(uint *)(inst + 0x14) & 0x200) != 0) &&
     (operandRecord = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84)), operandRecord != 0)) {
    laneIndex = 0;
    do {
      operandRecord2 = IRInst__getOperandRecord(inst,0);
      if ((*(char *)(laneIndex + operandRecord2 + 0x10) == '\x01') &&
         (operandRecord2 = IRInst__laneWrittenInChain(operandRecord,laneIndex), operandRecord2 != 0)) {
        *(undefined1 *)((int)writtenLaneMask + laneIndex) = 0;
      }
      moreLanes = laneIndex != 3;
      laneIndex = laneIndex + 1;
    } while (moreLanes);
  }
  FUN_000f370c(&local_38,writtenLaneMask[0]);
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  storeInst = allocation + 1;
  *allocation = arena;
  IRMemStore__ctor_1071fc(storeInst,0xfc,compiler);
  spillDestRegister = *(undefined4 *)(newSource + 0x94);
  allocation[0x27] = 0x3b;
  allocation[0x26] = spillDestRegister;
  WriteMask__fromUsedLanes(storeWriteMask,local_38);
  allocation[0x28] = storeWriteMask[0];
  IRInst__setOperandSource(storeInst,1,inst,0,compiler);
  operandRecord = IRInst__getOperandRecord(storeInst,1);
  *(undefined4 *)(operandRecord + 0x10) = local_38;
  IRInst__setOperandSource(storeInst,2,addressSource,0,compiler);
  addressSwizzleConstant = UNK_001affdc;
  operandRecord = IRInst__getOperandRecord(storeInst,2);
  *(undefined4 *)(operandRecord + 0x10) = addressSwizzleConstant;
  IRInst__setOperandSource(storeInst,3,newSource,0,compiler);
  insertAfterWord = *(undefined4 *)(ref + 0x158);
  allocation[6] = allocation[6] | 0x1000;
  DList__insertAfter(storeInst,ref);
  allocation[0x57] = insertAfterWord;
  return;
}

/* RegAlloc__initRegisterTables @ 0x1314b8 (320 bytes) */
int RegAlloc__initRegisterTables(allocator)
  int allocator;
{
  int fillByteOffset;
  int fillIndex;
  int tableBytes;
  int tableEntryCount;
  int physicalRegCountA;
  int virtualRegCount;
  int physicalRegCountB;
  undefined4 allocation;
  int compilerThenTotal;
  int *backend;
  
  *(int *)(allocator + 0x468) = *(int *)(*(int *)(allocator + 8) + 0x3c4) + 1;
  virtualRegCount = ((int (*)())RegAlloc__countUnassignedHwRegs)(allocator);
  compilerThenTotal = *(int *)(allocator + 8);
  *(int *)(allocator + 0x46c) = virtualRegCount;
  *(int *)(allocator + 0x464) = virtualRegCount + *(int *)(allocator + 0x468);
  backend = *(int **)(compilerThenTotal + 0x30c);
  physicalRegCountA = (**(code **)(*backend + 0x138))(backend,compilerThenTotal);
  physicalRegCountB = (**(code **)(*backend + 0x140))(backend,compilerThenTotal);
  compilerThenTotal = (**(code **)(*backend + 0x13c))(backend,compilerThenTotal);
  compilerThenTotal = physicalRegCountA + physicalRegCountB + compilerThenTotal;
  tableEntryCount = *(int *)(allocator + 0x464);
  if (*(int *)(allocator + 0x464) <= compilerThenTotal) {
    tableEntryCount = compilerThenTotal;
  }
  if (tableEntryCount < 0x1000) {
    tableEntryCount = 0x1000;
  }
  tableBytes = tableEntryCount << 2;
  allocation = Arena__alloc(*(undefined4 *)(*(int *)(allocator + 8) + 0x374),tableBytes);
  *(undefined4 *)(allocator + 0x458) = allocation;
  allocation = Arena__alloc(*(undefined4 *)(*(int *)(allocator + 8) + 0x374),tableBytes);
  *(undefined4 *)(allocator + 0x45c) = allocation;
  allocation = Arena__alloc(*(undefined4 *)(*(int *)(allocator + 8) + 0x374),tableBytes);
  *(undefined4 *)(allocator + 0x460) = allocation;
  if (0 < tableEntryCount) {
    fillIndex = 0;
    do {
      fillByteOffset = fillIndex * 4;
      fillIndex = fillIndex + 1;
      *(undefined4 *)(fillByteOffset + *(int *)(allocator + 0x460)) = 0xffffffff;
      tableEntryCount = tableEntryCount + -1;
    } while (tableEntryCount != 0);
  }
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_0012c134");
asm(".set FUN_0012c134, _FudoPs__vslot69_shouldFlattenIf");
asm(".globl FudoPs__flattenIfs");
asm(".set FudoPs__flattenIfs, _FudoPs__flattenIfs");

/* issue #75 (follow-up #3): Ghidra recognized this as a THUNK - a pure trampoline stub that
 * just branches straight to the real function below, no different behavior or arguments - but
 * decls.h declares "thunk_FUN_xxx" as its own separate extern function that nothing in this
 * corpus ever DEFINES a body for. The stock ld apparently tolerated the resulting undefined
 * reference (never actually called in a way that mattered, or silently resolved some other
 * way); ld64 leaves it a real unresolved lazy symbol, crashing the moment this call path is
 * first taken. Real fix: alias the thunk name directly onto the real function, so calling
 * "thunk_FUN_xxx" IS calling FUN_xxx - which is exactly what the original binary's trampoline
 * did. */
asm(".globl _thunk_FUN_001307f8");
asm(".set _thunk_FUN_001307f8, _IRInst__advanceToChainEnd");
