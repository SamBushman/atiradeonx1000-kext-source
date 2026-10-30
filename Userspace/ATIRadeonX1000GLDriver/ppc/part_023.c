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

/* Block__splitOutgoingEdge @ 0xe977c (404 bytes) */
int Block__splitOutgoingEdge(block, successor, newBlock)
  int block;
  int successor;
  int newBlock;
{
  int loopCounterB;
  int loopCounter;
  uint loopIndex;
  int iVar1;
  int *successorSlot;
  int iVar3;
  uint uVar4;
  int successorPredecessors;
  int loopCounterC;
  uint loopIndex2;
  uint *successorVector;
  
  loopIndex2 = 0;
  successorVector = *(uint **)(block + 0xd0);
  loopCounterB = 0;
  for (loopIndex = 1; loopIndex <= successorVector[1]; loopIndex = loopIndex + 1) {
    if (*(int *)(loopCounterB + successorVector[2]) != 0) {
      if (successor == *(int *)(loopCounterB + successorVector[2])) {
        if (loopIndex2 < *successorVector) {
          uVar4 = successorVector[1];
          if (uVar4 <= loopIndex2) {
            _memset(uVar4 * 4 + successorVector[2],0,(loopIndex2 - uVar4) * 4 + 4);
            successorVector[1] = loopIndex2 + 1;
          }
          successorSlot = (int *)(loopIndex2 * 4 + successorVector[2]);
        }
        else {
          successorSlot = (int *)Vector__elementRefGrow(successorVector,loopIndex2);
        }
        *successorSlot = newBlock;
        break;
      }
      loopIndex2 = loopIndex2 + 1;
    }
    loopCounterB = loopCounterB + 4;
  }
  successorPredecessors = *(int *)(successor + 0xd4);
  loopCounter = 0;
  loopIndex = 1;
  loopCounterC = 0;
  do {
    if (*(uint *)(successorPredecessors + 4) < loopIndex) {
LAB_000e9874:
      loopIndex = 1;
      loopCounterB = 0;
      while( true ) {
        if (*(uint *)(*(int *)(newBlock + 0xd4) + 4) < loopIndex) {
          Block__appendPredecessor(newBlock,block);
          return;
        }
        iVar3 = *(int *)(*(int *)(*(int *)(newBlock + 0xd4) + 8) + loopCounterB);
        if ((iVar3 != 0) && (block == iVar3)) break;
        loopIndex = loopIndex + 1;
        loopCounterB = loopCounterB + 4;
      }
      return;
    }
    iVar1 = *(int *)(*(int *)(successorPredecessors + 8) + loopCounterC);
    if (iVar1 != 0) {
      if (block == iVar1) {
        Vector__removeAt(successorPredecessors,loopCounter);
        goto LAB_000e9874;
      }
      loopCounter = loopCounter + 1;
    }
    loopIndex = loopIndex + 1;
    loopCounterC = loopCounterC + 4;
  } while( true );
}

/* FUN_000e9910 @ 0xe9910 (56 bytes) */
int FUN_000e9910(param_1, toBlock, param_3, fromBlock)
  undefined4 param_1;
  undefined4 toBlock;
  undefined4 param_3;
  undefined4 fromBlock;
{
  ((int (*)())Block__splitOutgoingEdge)(param_1,toBlock,param_3);
  return Block__connect(fromBlock,toBlock);
}

/* Block__splitIncomingEdge @ 0xe9948 (404 bytes) */
int Block__splitIncomingEdge(block, predecessor, newBlock)
  int block;
  int predecessor;
  int newBlock;
{
  int loopCounterB;
  int loopCounter;
  uint loopIndex;
  int iVar1;
  int *predecessorSlot;
  int iVar3;
  uint uVar4;
  int predecessorSuccessors;
  int loopCounterC;
  uint loopIndex2;
  uint *predecessorVector;
  
  loopIndex2 = 0;
  predecessorVector = *(uint **)(block + 0xd4);
  loopCounterB = 0;
  for (loopIndex = 1; loopIndex <= predecessorVector[1]; loopIndex = loopIndex + 1) {
    if (*(int *)(loopCounterB + predecessorVector[2]) != 0) {
      if (predecessor == *(int *)(loopCounterB + predecessorVector[2])) {
        if (loopIndex2 < *predecessorVector) {
          uVar4 = predecessorVector[1];
          if (uVar4 <= loopIndex2) {
            _memset(uVar4 * 4 + predecessorVector[2],0,(loopIndex2 - uVar4) * 4 + 4);
            predecessorVector[1] = loopIndex2 + 1;
          }
          predecessorSlot = (int *)(loopIndex2 * 4 + predecessorVector[2]);
        }
        else {
          predecessorSlot = (int *)Vector__elementRefGrow(predecessorVector,loopIndex2);
        }
        *predecessorSlot = newBlock;
        break;
      }
      loopIndex2 = loopIndex2 + 1;
    }
    loopCounterB = loopCounterB + 4;
  }
  predecessorSuccessors = *(int *)(predecessor + 0xd0);
  loopCounter = 0;
  loopIndex = 1;
  loopCounterC = 0;
  do {
    if (*(uint *)(predecessorSuccessors + 4) < loopIndex) {
LAB_000e9a40:
      loopIndex = 1;
      loopCounterB = 0;
      while( true ) {
        if (*(uint *)(*(int *)(newBlock + 0xd0) + 4) < loopIndex) {
          Block__appendSuccessor(newBlock,block);
          return;
        }
        iVar3 = *(int *)(*(int *)(*(int *)(newBlock + 0xd0) + 8) + loopCounterB);
        if ((iVar3 != 0) && (block == iVar3)) break;
        loopIndex = loopIndex + 1;
        loopCounterB = loopCounterB + 4;
      }
      return;
    }
    iVar1 = *(int *)(*(int *)(predecessorSuccessors + 8) + loopCounterC);
    if (iVar1 != 0) {
      if (block == iVar1) {
        Vector__removeAt(predecessorSuccessors,loopCounter);
        goto LAB_000e9a40;
      }
      loopCounter = loopCounter + 1;
    }
    loopIndex = loopIndex + 1;
    loopCounterC = loopCounterC + 4;
  } while( true );
}

/* Block__splitEdge @ 0xe9adc (292 bytes) */
int Block__splitEdge(fromBlock, toBlock, newBlock)
  int fromBlock;
  int toBlock;
  undefined4 newBlock;
{
  uint *predecessorVector;
  undefined4 *predecessorSlot;
  uint predecessorIndexResult;
  uint successorIndex;
  uint edgeVectorCount;
  undefined4 *successorSlot;
  uint *successorVector;
  
  successorIndex = FUN_000e7fe0(fromBlock,toBlock);
  successorVector = *(uint **)(fromBlock + 0xd0);
  if (successorIndex < *successorVector) {
    edgeVectorCount = successorVector[1];
    if (edgeVectorCount <= successorIndex) {
      _memset(edgeVectorCount * 4 + successorVector[2],0,(successorIndex - edgeVectorCount) * 4 + 4);
      successorVector[1] = successorIndex + 1;
    }
    successorSlot = (undefined4 *)(successorIndex * 4 + successorVector[2]);
  }
  else {
    successorSlot = (undefined4 *)Vector__elementRefGrow(successorVector,successorIndex);
  }
  *successorSlot = newBlock;
  predecessorIndexResult = Block__predecessorIndex(toBlock,fromBlock);
  predecessorVector = *(uint **)(toBlock + 0xd4);
  if (predecessorIndexResult < *predecessorVector) {
    edgeVectorCount = predecessorVector[1];
    if (edgeVectorCount <= predecessorIndexResult) {
      _memset(edgeVectorCount * 4 + predecessorVector[2],0,(predecessorIndexResult - edgeVectorCount) * 4 + 4);
      predecessorVector[1] = predecessorIndexResult + 1;
    }
    predecessorSlot = (undefined4 *)(predecessorIndexResult * 4 + predecessorVector[2]);
  }
  else {
    predecessorSlot = (undefined4 *)Vector__elementRefGrow(predecessorVector,predecessorIndexResult);
  }
  *predecessorSlot = newBlock;
  Block__appendPredecessor(newBlock,fromBlock);
  return Block__appendSuccessor(newBlock,toBlock);
}

/* Block__recordDefinition @ 0xe9c00 (200 bytes) */
int Block__recordDefinition(block, vreg, definition)
  int block;
  int vreg;
  undefined4 definition;
{
  int *vectorSlot;
  int *listEntry;
  uint loopIndex;
  uint *definitionList;
  uint definitionCount;
  uint entriesLeft;
  
  definitionList = *(uint **)(block + 0xc4);
  definitionCount = definitionList[1];
  if (0 < (int)definitionCount) {
    loopIndex = 0;
    entriesLeft = definitionCount;
    do {
      listEntry = (int *)0x0;
      if (loopIndex < definitionCount) {
        listEntry = (int *)(loopIndex * 4 + definitionList[2]);
      }
      if (vreg == *listEntry) goto LAB_000e9ca8;
      loopIndex = loopIndex + 1;
      entriesLeft = entriesLeft - 1;
    } while (entriesLeft != 0);
  }
  if (definitionCount < *definitionList) {
    _memset(definitionCount * 4 + definitionList[2],0,4);
    vectorSlot = (int *)(definitionCount * 4 + definitionList[2]);
    definitionList[1] = definitionCount + 1;
  }
  else {
    vectorSlot = (int *)Vector__elementRefGrow(definitionList,definitionCount);
  }
  *vectorSlot = vreg;
LAB_000e9ca8:
  return VReg__pushDefinition(vreg,*(undefined4 *)(block + 0xb0),definition);
}

/* FUN_000e9cc8 @ 0xe9cc8 (160 bytes) */
int FUN_000e9cc8(block)
  int block;
{
  byte laneFlags;
  int *firstDefSlot;
  
  if (*(int *)(block + 0x144) == 0) {
    firstDefSlot = *(int **)(*(int *)(*(int *)(block + 0x148) + 0xa4) + 0x18);
    if (*firstDefSlot == 0) {
      firstDefSlot = (int *)Vector__elementRefGrow(firstDefSlot,0);
    }
    else {
      if (firstDefSlot[1] == 0) {
        *(undefined4 *)firstDefSlot[2] = 0;
        firstDefSlot[1] = 1;
      }
      firstDefSlot = (int *)firstDefSlot[2];
    }
    laneFlags = *(byte *)(*firstDefSlot + 0x15c);
    if ((((laneFlags & 1) != 0) && ((laneFlags & 2) != 0)) && ((laneFlags & 4) != 0)) {
      return 1;
    }
  }
  return 0;
}

/* Block__ctor_e9d68 @ 0xe9d68 (252 bytes) */
int Block__ctor_e9d68(this, owner)
  undefined4 *this;
  int owner;
{
  undefined4 bitSetIndex;
  undefined4 ownerField0xc0;
  undefined4 ownerField0xac;
  undefined4 ownerField0xc;
  int compiler;
  undefined4 r4AfterCall;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 ownerField0x110;
  int blockSerial;
  undefined4 ownerField0xdc;
  undefined4 ownerField0x10c;
  
  this[1] = 0;
  this[2] = 0;
  ownerField0xc = *(undefined4 *)(owner + 0xc);
  *this = &PTR_FUN_001e9b08;
  this[3] = ownerField0xc;
  DListNode__init(this + 0x24);
  compiler = *(int *)(owner + 0xa8);
  ownerField0xac = *(undefined4 *)(owner + 0xac);
  this[0x2a] = compiler;
  this[0x2b] = ownerField0xac;
  blockSerial = *(int *)(compiler + 0x32c);
  this[0x2c] = blockSerial;
  *(int *)(compiler + 0x32c) = blockSerial + 1;
  ownerField0x110 = *(undefined4 *)(owner + 0x110);
  ownerField0xc0 = *(undefined4 *)(owner + 0xc0);
  ownerField0xdc = *(undefined4 *)(owner + 0xdc);
  ownerField0x10c = *(undefined4 *)(owner + 0x10c);
  this[0x2e] = *(undefined4 *)(owner + 0xb8);
  this[0x30] = ownerField0xc0;
  this[0x37] = ownerField0xdc;
  this[0x3a] = 0x7fffffff;
  this[0x42] = 0;
  this[0x43] = ownerField0x10c;
  this[0x44] = ownerField0x110;
  this[0x46] = 0xffffffff;
  this[0x39] = 0x7fffffff;
  this[0x3b] = 0;
  this[0x3c] = 0;
  this[0x3f] = 0;
  this[0x40] = 0;
  this[0x41] = 0;
  FUN_000e8a08(this);
  Block__createEntryExitInsts(this);
  bitSetIndex = Program__allocateBitSetIndex(this[0x2b],r4AfterCall,staleArgR5,staleArgR6,staleArgR7,ownerField0x110,ownerField0xdc);
  this[0x2d] = bitSetIndex;
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
int Block__ctor_e9f00(this, owner)
  undefined4 *this;
  int owner;
{
  undefined4 bitSetIndex;
  undefined4 ownerField0xc0;
  undefined4 ownerField0xac;
  undefined4 ownerField0xc;
  int compiler;
  undefined4 r4AfterCall;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 ownerField0x110;
  int blockSerial;
  undefined4 ownerField0xdc;
  undefined4 ownerField0x10c;
  
  this[1] = 0;
  this[2] = 0;
  ownerField0xc = *(undefined4 *)(owner + 0xc);
  *this = &PTR_FUN_001e9b08;
  this[3] = ownerField0xc;
  DListNode__init(this + 0x24);
  compiler = *(int *)(owner + 0xa8);
  ownerField0xac = *(undefined4 *)(owner + 0xac);
  this[0x2a] = compiler;
  this[0x2b] = ownerField0xac;
  blockSerial = *(int *)(compiler + 0x32c);
  this[0x2c] = blockSerial;
  *(int *)(compiler + 0x32c) = blockSerial + 1;
  ownerField0x110 = *(undefined4 *)(owner + 0x110);
  ownerField0xc0 = *(undefined4 *)(owner + 0xc0);
  ownerField0xdc = *(undefined4 *)(owner + 0xdc);
  ownerField0x10c = *(undefined4 *)(owner + 0x10c);
  this[0x2e] = *(undefined4 *)(owner + 0xb8);
  this[0x30] = ownerField0xc0;
  this[0x37] = ownerField0xdc;
  this[0x3a] = 0x7fffffff;
  this[0x42] = 0;
  this[0x43] = ownerField0x10c;
  this[0x44] = ownerField0x110;
  this[0x46] = 0xffffffff;
  this[0x39] = 0x7fffffff;
  this[0x3b] = 0;
  this[0x3c] = 0;
  this[0x3f] = 0;
  this[0x40] = 0;
  this[0x41] = 0;
  FUN_000e8a08(this);
  Block__createEntryExitInsts(this);
  bitSetIndex = Program__allocateBitSetIndex(this[0x2b],r4AfterCall,staleArgR5,staleArgR6,staleArgR7,ownerField0x110,ownerField0xdc);
  this[0x2d] = bitSetIndex;
  return;
}

/* Block__ctor_ea020 @ 0xea020 (260 bytes) */
int Block__ctor_ea020(this, compiler)
  undefined4 *this;
  int compiler;
{
  int loopCounter;
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 r4AfterCall;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
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
  Block__createEntryExitInsts(this);
  loopCounter = 0x20;
  puVar1 = this;
  do {
    puVar1[4] = 0;
    puVar1 = puVar1 + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  uVar2 = Program__allocateBitSetIndex(*(undefined4 *)(this[0x2a] + 0x6c4),r4AfterCall,staleArgR5,staleArgR6,staleArgR7,staleArgR8,
                       0x20);
  this[0x2d] = uVar2;
  return;
}

/* Block__ctor_ea148 @ 0xea148 (260 bytes) */
int Block__ctor_ea148(this, compiler)
  undefined4 *this;
  int compiler;
{
  int loopCounter;
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 r4AfterCall;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
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
  Block__createEntryExitInsts(this);
  loopCounter = 0x20;
  puVar1 = this;
  do {
    puVar1[4] = 0;
    puVar1 = puVar1 + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  uVar2 = Program__allocateBitSetIndex(*(undefined4 *)(this[0x2a] + 0x6c4),r4AfterCall,staleArgR5,staleArgR6,staleArgR7,staleArgR8,
                       0x20);
  this[0x2d] = uVar2;
  return;
}

/* Block__dtor_ea270 @ 0xea270 (260 bytes) */
int Block__dtor_ea270(this)
  undefined4 *this;
{
  undefined *baseVtable;
  int vectorHeader;
  
  vectorHeader = this[0x35];
  *this = &PTR_FUN_001e9b08;
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = this[0x34];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = this[0x3d];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = this[0x3e];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = this[0x31];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  DListNode__clear(this + 0x24);
  baseVtable = PTR_DAT_001e8b48 + 8;
  this[0x24] = baseVtable;
  this[0x27] = baseVtable;
  *this = baseVtable;
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
int PostLoopFooter__ctor_ea828(this, registerIndex, enclosingLoopHeader, argR6, compiler)
  undefined4 *this;
  undefined4 registerIndex;
  undefined4 enclosingLoopHeader;
  int argR6;
  int compiler;
{
  undefined4 *instObject;
  int operandRecord3;
  int newVReg;
  int operandRecord2;
  undefined4 constantSelectWord;
  undefined4 virtualRegister;
  undefined4 newInst;
  undefined4 *allocation;
  int operandRecord;
  int *definitionVector;
  int definitionInst;
  undefined4 arenaA;
  undefined4 *blockObject;
  
  ((int (*)())Block__ctor_ea148)(this,compiler);
  this[0x50] = 0;
  *this = &PTR_FUN_001e9bb8;
  this[0x53] = enclosingLoopHeader;
  this[0x4b] = 0;
  this[0x4d] = 0;
  this[0x4e] = 0;
  this[0x4f] = 0;
  this[0x51] = argR6;
  arenaA = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x134);
  *allocation = arenaA;
  ((int (*)())Block__ctor_ea148)(allocation + 1,compiler);
  allocation[0x4c] = this;
  allocation[1] = &PTR_FUN_001e9c10;
  this[0x54] = allocation + 1;
  arenaA = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arenaA,0x134);
  blockObject = allocation + 1;
  *allocation = arenaA;
  ((int (*)())Block__ctor_ea148)(blockObject,compiler);
  allocation[0x4c] = this;
  *blockObject = &PTR_FUN_001e9c68;
  this[0x55] = blockObject;
  Block__connect(this[0x54],this);
  if (argR6 == 0) {
    newInst = IRInst__create(0x81,compiler);
    this[0x52] = newInst;
    operandRecord = IRInst__getOperandRecord(newInst,0);
    *(undefined4 *)(operandRecord + 8) = registerIndex;
    *(undefined4 *)(operandRecord + 0xc) = 0x27;
    virtualRegister = FUN_00127608(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3ac),4,registerIndex,0);
    IRInst__setOperandRef(this[0x52],1,virtualRegister);
  }
  else {
    arenaA = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
    instObject = allocation + 1;
    *allocation = arenaA;
    IRInst__ctor_10502c(instObject,0xfd,compiler);
    this[0x52] = instObject;
    operandRecord2 = IRInst__getOperandRecord(instObject,0);
    *(undefined4 *)(operandRecord2 + 8) = registerIndex;
    *(undefined4 *)(operandRecord2 + 0xc) = 0x27;
    newVReg = FUN_00127608(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3ac),4,0,0);
    definitionVector = *(int **)(newVReg + 0x18);
    if (*definitionVector == 0) {
      definitionVector = (int *)Vector__elementRefGrow(definitionVector,0);
    }
    else {
      if (definitionVector[1] == 0) {
        *(undefined4 *)definitionVector[2] = 0;
        definitionVector[1] = 1;
      }
      definitionVector = (int *)definitionVector[2];
    }
    definitionInst = *definitionVector;
    *(undefined4 *)(definitionInst + 0x20) = 0xffffffff;
    *(byte *)(definitionInst + 0x15c) = *(byte *)(definitionInst + 0x15c) | 1;
    *(undefined4 *)(definitionInst + 0x1c) = 3;
    IRInst__setOperandRef(this[0x52],1,newVReg);
    constantSelectWord = DAT_001aa7fc;
    operandRecord3 = IRInst__getOperandRecord(this[0x52],1);
    *(undefined4 *)(operandRecord3 + 0x10) = constantSelectWord;
  }
  Block__appendInst(this,this[0x52]);
  return;
}

/* ExitBlock__ctor_eaae8 @ 0xeaae8 (68 bytes) */
int ExitBlock__ctor_eaae8(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())Block__ctor_ea148)(this,compiler);
  *this = &PTR_FUN_001e9ed0;
  return;
}

/* ExitBlock__ctor_eab2c @ 0xeab2c (68 bytes) */
int ExitBlock__ctor_eab2c(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())Block__ctor_ea148)(this,compiler);
  *this = &PTR_FUN_001e9ed0;
  return;
}

/* EntryBlock__ctor_eab70 @ 0xeab70 (76 bytes) */
int EntryBlock__ctor_eab70(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())Block__ctor_ea148)(this,compiler);
  this[0x4b] = this[0x32];
  *this = &PTR_FUN_001e9f28;
  return;
}

/* EntryBlock__ctor_eabbc @ 0xeabbc (76 bytes) */
int EntryBlock__ctor_eabbc(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())Block__ctor_ea148)(this,compiler);
  this[0x4b] = this[0x32];
  *this = &PTR_FUN_001e9f28;
  return;
}

/* BreakOrContinueBlock__ctor_eac08 @ 0xeac08 (88 bytes) */
int BreakOrContinueBlock__ctor_eac08(this, source)
  undefined4 *this;
  int source;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())Block__ctor_e9f00)(this,source);
  uVar2 = *(undefined4 *)(source + 300);
  puVar1 = PTR_DAT_001e8b54 + 8;
  this[0x4c] = *(undefined4 *)(source + 0x130);
  *this = puVar1;
  this[0x4b] = uVar2;
  return;
}

/* BreakOrContinueBlock__ctor_eac60 @ 0xeac60 (88 bytes) */
int BreakOrContinueBlock__ctor_eac60(this, source)
  undefined4 *this;
  int source;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())Block__ctor_e9f00)(this,source);
  uVar2 = *(undefined4 *)(source + 300);
  puVar1 = PTR_DAT_001e8b54 + 8;
  this[0x4c] = *(undefined4 *)(source + 0x130);
  *this = puVar1;
  this[0x4b] = uVar2;
  return;
}

/* PostLoopFooter__ctor_eacb8 @ 0xeacb8 (80 bytes) */
int PostLoopFooter__ctor_eacb8(this, source)
  undefined4 *this;
  undefined4 source;
{
  ((int (*)())Block__ctor_e9f00)(this,source);
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
int PostLoopFooter__ctor_ead80(this, source)
  undefined4 *this;
  undefined4 source;
{
  ((int (*)())Block__ctor_e9f00)(this,source);
  this[3] = this[3] | 0x20;
  *this = &PTR_FUN_001e9c68;
  return;
}

/* LoopFooter__ctor_eadd0 @ 0xeadd0 (80 bytes) */
int LoopFooter__ctor_eadd0(this, source)
  undefined4 *this;
  undefined4 source;
{
  ((int (*)())Block__ctor_e9f00)(this,source);
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
int LoopFooter__ctor_eae98(this, source)
  undefined4 *this;
  undefined4 source;
{
  ((int (*)())Block__ctor_e9f00)(this,source);
  this[3] = this[3] | 0x20;
  *this = &PTR_FUN_001e9c10;
  return;
}

/* LoopHeader__ctor_eaee8 @ 0xeaee8 (132 bytes) */
int LoopHeader__ctor_eaee8(this, source)
  undefined4 *this;
  int source;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  ((int (*)())Block__ctor_e9f00)(this,source);
  uVar1 = *(undefined4 *)(source + 0x144);
  uVar4 = *(undefined4 *)(source + 300);
  uVar6 = *(undefined4 *)(source + 0x134);
  uVar5 = *(undefined4 *)(source + 0x138);
  uVar3 = *(undefined4 *)(source + 0x13c);
  uVar2 = *(undefined4 *)(source + 0x140);
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
int LoopHeader__ctor_eafe4(this, source)
  undefined4 *this;
  int source;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  ((int (*)())Block__ctor_e9f00)(this,source);
  uVar1 = *(undefined4 *)(source + 0x144);
  uVar4 = *(undefined4 *)(source + 300);
  uVar6 = *(undefined4 *)(source + 0x134);
  uVar5 = *(undefined4 *)(source + 0x138);
  uVar3 = *(undefined4 *)(source + 0x13c);
  uVar2 = *(undefined4 *)(source + 0x140);
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
int IfFooter__ctor_eb068(this, source)
  undefined4 *this;
  undefined4 source;
{
  ((int (*)())Block__ctor_e9f00)(this,source);
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
int IfFooter__ctor_eb124(this, source)
  undefined4 *this;
  undefined4 source;
{
  ((int (*)())Block__ctor_e9f00)(this,source);
  *this = &PTR_FUN_001e9d70;
  return;
}

/* IfHeader__ctor_eb168 @ 0xeb168 (104 bytes) */
int IfHeader__ctor_eb168(this, source)
  undefined4 *this;
  int source;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  ((int (*)())Block__ctor_e9f00)(this,source);
  uVar2 = *(undefined4 *)(source + 0x148);
  uVar1 = *(undefined4 *)(source + 0x144);
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
int IfHeader__ctor_eb248(this, source)
  undefined4 *this;
  int source;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  ((int (*)())Block__ctor_e9f00)(this,source);
  uVar2 = *(undefined4 *)(source + 0x148);
  uVar1 = *(undefined4 *)(source + 0x144);
  this[0x55] = 0;
  *this = &PTR_FUN_001e9cc0;
  this[0x51] = uVar1;
  this[0x52] = uVar2;
  this[0x53] = 0;
  this[0x54] = 0;
  return;
}

/* FuncEndBlock__ctor_eb2b0 @ 0xeb2b0 (80 bytes) */
int FuncEndBlock__ctor_eb2b0(this, source)
  undefined4 *this;
  int source;
{
  ((int (*)())Block__ctor_e9f00)(this,source);
  this[0x4b] = *(undefined4 *)(source + 300);
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
int FuncEndBlock__ctor_eb378(this, source)
  undefined4 *this;
  int source;
{
  ((int (*)())Block__ctor_e9f00)(this,source);
  this[0x4b] = *(undefined4 *)(source + 300);
  *this = &PTR_FUN_001e9b60;
  return;
}

/* PostLoopFooter__ctor_eb3c8 @ 0xeb3c8 (580 bytes) */
int PostLoopFooter__ctor_eb3c8(this, registerIndex, loopHeader, useFooterInst, compiler)
  undefined4 *this;
  undefined4 registerIndex;
  undefined4 loopHeader;
  int useFooterInst;
  int compiler;
{
  undefined4 *footerInst;
  undefined4 constantSelectWord;
  undefined4 virtualRegisterB;
  int virtualRegister;
  undefined4 arena;
  undefined4 *allocation;
  int operandRecord;
  int *definitionVector;
  int definitionInst;
  undefined4 exitInst;
  undefined4 *secondSideBlock;
  
  ((int (*)())Block__ctor_ea148)(this,compiler);
  this[0x50] = 0;
  *this = &PTR_FUN_001e9bb8;
  this[0x53] = loopHeader;
  this[0x4b] = 0;
  this[0x4d] = 0;
  this[0x4e] = 0;
  this[0x4f] = 0;
  this[0x51] = useFooterInst;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  *allocation = arena;
  ((int (*)())Block__ctor_ea148)(allocation + 1,compiler);
  allocation[0x4c] = this;
  allocation[1] = &PTR_FUN_001e9c10;
  this[0x54] = allocation + 1;
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x134);
  secondSideBlock = allocation + 1;
  *allocation = arena;
  ((int (*)())Block__ctor_ea148)(secondSideBlock,compiler);
  allocation[0x4c] = this;
  *secondSideBlock = &PTR_FUN_001e9c68;
  this[0x55] = secondSideBlock;
  Block__connect(this[0x54],this);
  if (useFooterInst == 0) {
    exitInst = IRInst__create(0x81,compiler);
    this[0x52] = exitInst;
    operandRecord = IRInst__getOperandRecord(exitInst,0);
    *(undefined4 *)(operandRecord + 8) = registerIndex;
    *(undefined4 *)(operandRecord + 0xc) = 0x27;
    virtualRegisterB = FUN_00127608(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3ac),4,registerIndex,0);
    IRInst__setOperandRef(this[0x52],1,virtualRegisterB);
  }
  else {
    arena = *(undefined4 *)(compiler + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    footerInst = allocation + 1;
    *allocation = arena;
    IRInst__ctor_10502c(footerInst,0xfd,compiler);
    this[0x52] = footerInst;
    operandRecord = IRInst__getOperandRecord(footerInst,0);
    *(undefined4 *)(operandRecord + 8) = registerIndex;
    *(undefined4 *)(operandRecord + 0xc) = 0x27;
    virtualRegister = FUN_00127608(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3ac),4,0,0);
    definitionVector = *(int **)(virtualRegister + 0x18);
    if (*definitionVector == 0) {
      definitionVector = (int *)Vector__elementRefGrow(definitionVector,0);
    }
    else {
      if (definitionVector[1] == 0) {
        *(undefined4 *)definitionVector[2] = 0;
        definitionVector[1] = 1;
      }
      definitionVector = (int *)definitionVector[2];
    }
    definitionInst = *definitionVector;
    *(undefined4 *)(definitionInst + 0x20) = 0xffffffff;
    *(byte *)(definitionInst + 0x15c) = *(byte *)(definitionInst + 0x15c) | 1;
    *(undefined4 *)(definitionInst + 0x1c) = 3;
    IRInst__setOperandRef(this[0x52],1,virtualRegister);
    constantSelectWord = DAT_001aa7fc;
    operandRecord = IRInst__getOperandRecord(this[0x52],1);
    *(undefined4 *)(operandRecord + 0x10) = constantSelectWord;
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
int IfFooterStatic__ctor_eb7e0(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())IfFooter__ctor_eb124)(this,compiler);
  *this = &PTR_FUN_001e9dc8;
  return;
}

/* IfFooterStatic__ctor_eb824 @ 0xeb824 (68 bytes) */
int IfFooterStatic__ctor_eb824(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())IfFooter__ctor_eb124)(this,compiler);
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
int IfHeaderStatic__ctor_eb8e0(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())IfHeader__ctor_eb248)(this,compiler);
  *this = &PTR_FUN_001e9d18;
  return;
}

/* IfHeaderStatic__ctor_eb924 @ 0xeb924 (68 bytes) */
int IfHeaderStatic__ctor_eb924(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())IfHeader__ctor_eb248)(this,compiler);
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
int IfHeaderStatic__ctor_eb9e0(this, inst, param_3, compiler)
  undefined4 *this;
  undefined4 inst;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  ((int (*)())IfHeader__ctor_ea600)(this,compiler);
  this[0x4c] = inst;
  *this = &PTR_FUN_001e9d18;
  Block__appendInst(this,inst);
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
int IfHeaderStatic__ctor_ebac8(this, inst, param_3, compiler)
  undefined4 *this;
  undefined4 inst;
  undefined4 param_3;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  ((int (*)())IfHeader__ctor_ea600)(this,compiler);
  this[0x4c] = inst;
  *this = &PTR_FUN_001e9d18;
  Block__appendInst(this,inst);
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
  undefined *baseVtable;
  int vectorHeader;
  
  vectorHeader = this[0x35];
  *this = &PTR_FUN_001e9b08;
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = this[0x34];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = this[0x3d];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = this[0x3e];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = this[0x31];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  DListNode__clear(this + 0x24);
  baseVtable = PTR_DAT_001e8b48 + 8;
  this[0x24] = baseVtable;
  this[0x27] = baseVtable;
  *this = baseVtable;
  return;
}

/* Block__deleting_dtor @ 0xebd00 (312 bytes) */
int Block__deleting_dtor(this)
  undefined4 *this;
{
  undefined *baseVtable;
  undefined4 *arenaBlockStart;
  int vectorHeader;
  
  vectorHeader = this[0x35];
  *this = &PTR_FUN_001e9b08;
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = this[0x34];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = this[0x3d];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = this[0x3e];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = this[0x31];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  DListNode__clear(this + 0x24);
  baseVtable = PTR_DAT_001e8b48 + 8;
  this[0x27] = baseVtable;
  *this = baseVtable;
  this[0x24] = baseVtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  vectorHeader = this[-1];
  if ((*(int *)(vectorHeader + 0x28) != 0) &&
     (arenaBlockStart = *(undefined4 **)(vectorHeader + 0x14), arenaBlockStart == this + -1)) {
    _memset(arenaBlockStart,0,*(int *)(vectorHeader + 8) - (int)arenaBlockStart);
    *(undefined4 *)(vectorHeader + 8) = *(undefined4 *)(vectorHeader + 0x14);
  }
  return;
}

/* BreakBlock__ctor_ebe70 @ 0xebe70 (68 bytes) */
int BreakBlock__ctor_ebe70(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())BreakOrContinueBlock__ctor_eac60)(this,compiler);
  *this = &PTR_FUN_001e9e20;
  return;
}

/* BreakBlock__ctor_ebeb4 @ 0xebeb4 (68 bytes) */
int BreakBlock__ctor_ebeb4(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())BreakOrContinueBlock__ctor_eac60)(this,compiler);
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
int ContinueBlock__ctor_ebf70(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())BreakOrContinueBlock__ctor_eac60)(this,compiler);
  *this = &PTR_FUN_001e9e78;
  return;
}

/* ContinueBlock__ctor_ebfb4 @ 0xebfb4 (68 bytes) */
int ContinueBlock__ctor_ebfb4(this, compiler)
  undefined4 *this;
  undefined4 compiler;
{
  ((int (*)())BreakOrContinueBlock__ctor_eac60)(this,compiler);
  *this = &PTR_FUN_001e9e78;
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl Block__clone");
asm(".set Block__clone, _Block__clone");
asm(".globl PostLoopFooter__clone");
asm(".set PostLoopFooter__clone, _PostLoopFooter__clone");
asm(".globl LoopFooter__clone");
asm(".set LoopFooter__clone, _LoopFooter__clone");
asm(".globl LoopHeader__clone");
asm(".set LoopHeader__clone, _LoopHeader__clone");
asm(".globl IfFooter__clone");
asm(".set IfFooter__clone, _IfFooter__clone");
asm(".globl IfHeader__clone");
asm(".set IfHeader__clone, _IfHeader__clone");
asm(".globl FuncEndBlock__clone");
asm(".set FuncEndBlock__clone, _FuncEndBlock__clone");
asm(".globl IfFooterStatic__clone");
asm(".set IfFooterStatic__clone, _IfFooterStatic__clone");
asm(".globl IfHeaderStatic__clone");
asm(".set IfHeaderStatic__clone, _IfHeaderStatic__clone");
asm(".globl Block__dtor");
asm(".set Block__dtor, _Block__dtor");
asm(".globl Block__deleting_dtor");
asm(".set Block__deleting_dtor, _Block__deleting_dtor");
asm(".globl BreakBlock__clone");
asm(".set BreakBlock__clone, _BreakBlock__clone");
