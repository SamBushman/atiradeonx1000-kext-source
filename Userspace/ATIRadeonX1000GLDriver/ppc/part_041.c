#include "decls.h"

/* FUN_001315f8 @ 0x1315f8 (684 bytes) */
int FUN_001315f8(allocator, inst, newSource, registerCountRef, beforeInst, block)
  int allocator;
  int inst;
  undefined4 newSource;
  int *registerCountRef;
  undefined4 beforeInst;
  int block;
{
  int rowBitLimit;
  uint laneBitIndex;
  uint clearWordCount;
  int bitsetWordsLeft;
  undefined4 arena;
  int newInst;
  int loopIndex;
  uint *oldBitsetNextWord;
  uint bitWordOffset;
  int *newBitsetClearCursor;
  int bitsLeftInRow;
  int registerCountAfter;
  int *newBitsetWords;
  undefined4 rootRegister;
  undefined4 *allocation;
  uint oldBitCount;
  uint newBitCount;
  uint newBitsetWordCount;
  int newRegister;
  int blockCursor;
  int program;
  uint *oldBitset;
  
  program = *(int *)(*(int *)(allocator + 0x2c) + 0x6c4);
  newInst = IRInst__create(0x31,*(int *)(allocator + 0x2c));
  newRegister = *registerCountRef;
  *(undefined4 *)(newInst + 0x98) = *(undefined4 *)(inst + 0x98);
  *(int *)(newInst + 0x94) = newRegister;
  IRInst__setOperandSource(newInst,1,newSource,0,*(undefined4 *)(allocator + 0x2c));
  *(uint *)(newInst + 0x14) = *(uint *)(newInst + 0x14) & 0xffffffbf | 0x80000000;
  Block__insertInstBefore(block,beforeInst,newInst);
  IRInst__setExtraOperandSource(inst,newInst,0,*(undefined4 *)(allocator + 0x2c));
  ((int (*)())FUN_00137474)(allocator);
  *(undefined4 *)(*registerCountRef * 4 + *(int *)(program + 0x45c)) = 0;
  **(int **)(allocator + 0x18) = **(int **)(allocator + 0x18) + 1;
  *registerCountRef = *registerCountRef + 1;
  blockCursor = *(int *)(program + 900);
  *(int *)(program + 600) = *(int *)(program + 600) + 1;
  registerCountAfter = *registerCountRef;
  if (*(int *)(blockCursor + 8) != 0) {
    newBitsetWordCount = registerCountAfter * 4 + 0x1fU >> 5;
    do {
      oldBitset = *(uint **)(blockCursor + 0x104);
      oldBitCount = oldBitset[1];
      newBitCount = oldBitCount + 1;
      if (oldBitCount + 0x20 >> 5 == *oldBitset) {
        oldBitset[1] = newBitCount;
        for (; oldBitCount < newBitCount; oldBitCount = oldBitCount + 1) {
          bitWordOffset = oldBitCount >> 3 & 0x1ffffffc;
          *(uint *)((int)oldBitset + bitWordOffset + 8) =
               *(uint *)((int)oldBitset + bitWordOffset + 8) & ~(1 << (oldBitCount & 0x1f));
        }
      }
      else {
        arena = *(undefined4 *)(*(int *)(allocator + 0x2c) + 0x378);
        allocation = (undefined4 *)Arena__alloc(arena,newBitsetWordCount * 4 + 0xc);
        newBitsetWords = allocation + 1;
        *allocation = arena;
        allocation[1] = newBitsetWordCount;
        allocation[2] = registerCountAfter * 4;
        if (newBitsetWordCount != 0) {
          newBitsetClearCursor = newBitsetWords;
          clearWordCount = newBitsetWordCount;
          if (newBitsetWordCount == 0) {
            clearWordCount = 1;
          }
          do {
            newBitsetClearCursor[2] = 0;
            newBitsetClearCursor = newBitsetClearCursor + 1;
            clearWordCount = clearWordCount - 1;
          } while (clearWordCount != 0);
        }
        *(int **)(blockCursor + 0x104) = newBitsetWords;
        bitsetWordsLeft = *newBitsetWords;
        if (bitsetWordsLeft != 0) {
          if (bitsetWordsLeft == 0) {
            bitsetWordsLeft = 1;
          }
          do {
            oldBitsetNextWord = oldBitset + 2;
            oldBitset = oldBitset + 1;
            newBitsetWords[2] = newBitsetWords[2] | *oldBitsetNextWord;
            newBitsetWords = newBitsetWords + 1;
            bitsetWordsLeft = bitsetWordsLeft + -1;
          } while (bitsetWordsLeft != 0);
        }
      }
      blockCursor = *(int *)(blockCursor + 8);
    } while (*(int *)(blockCursor + 8) != 0);
    registerCountAfter = *registerCountRef;
  }
  if (0 < registerCountAfter) {
    loopIndex = 0;
    rowBitLimit = 4;
    do {
      laneBitIndex = loopIndex * 4;
      bitsLeftInRow = rowBitLimit + loopIndex * -4;
      do {
        if ((*(uint *)((laneBitIndex >> 3 & 0x1ffffffc) + *(int *)(block + 0x104) + 8) >>
             (laneBitIndex & 0x1f) & 1) != 0) {
          rootRegister = ((int (*)())FUN_00134bf0)(allocator,loopIndex,1);
          ((int (*)())FUN_00135334)(allocator,newRegister,rootRegister);
          registerCountAfter = *registerCountRef;
          break;
        }
        laneBitIndex = laneBitIndex + 1;
        bitsLeftInRow = bitsLeftInRow + -1;
      } while (bitsLeftInRow != 0);
      loopIndex = loopIndex + 1;
      rowBitLimit = rowBitLimit + 4;
    } while (loopIndex < registerCountAfter);
  }
  return;
}

/* FUN_001318a4 @ 0x1318a4 (300 bytes) */
int FUN_001318a4(allocator, nodeIndex, spillState)
  int allocator;
  uint nodeIndex;
  int spillState;
{
  uint nodeVectorCount;
  undefined4 *nodeRef;
  int spillSlot;
  int newSlotNumber;
  uint *nodeVector;
  
  nodeVector = *(uint **)(allocator + 4);
  if (nodeIndex < *nodeVector) {
    nodeVectorCount = nodeVector[1];
    if (nodeVectorCount <= nodeIndex) {
      _memset(nodeVectorCount * 4 + nodeVector[2],0,(nodeIndex - nodeVectorCount) * 4 + 4);
      nodeVector[1] = nodeIndex + 1;
    }
    nodeRef = (undefined4 *)(nodeIndex * 4 + nodeVector[2]);
  }
  else {
    nodeRef = (undefined4 *)Vector__elementRefGrow(nodeVector,nodeIndex);
  }
  spillSlot = ((int (*)())FUN_00134ab0)(*nodeRef);
  if (spillSlot == 0) {
    newSlotNumber = *(int *)(spillState + 0x138);
    spillSlot = FUN_00130f64(*(undefined4 *)(spillState + 0x130),newSlotNumber,*(undefined4 *)(allocator + 0x2c));
    nodeVector = *(uint **)(allocator + 4);
    if (nodeIndex < *nodeVector) {
      nodeVectorCount = nodeVector[1];
      if (nodeVectorCount <= nodeIndex) {
        _memset(nodeVectorCount * 4 + nodeVector[2],0,(nodeIndex - nodeVectorCount) * 4 + 4);
        nodeVector[1] = nodeIndex + 1;
      }
      nodeRef = (undefined4 *)(nodeIndex * 4 + nodeVector[2]);
    }
    else {
      nodeRef = (undefined4 *)Vector__elementRefGrow(nodeVector,nodeIndex);
    }
    ((int (*)())FUN_00134aa8)(*nodeRef,spillSlot);
    *(int *)(spillState + 0x138) = newSlotNumber + 1;
  }
  return spillSlot;
}

/* FUN_001319d0 @ 0x1319d0 (176 bytes) */
int FUN_001319d0(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint loopIndex;
  uint *puVar5;
  
  iVar3 = 0;
  if (0 < (int)param_2) {
    loopIndex = 0;
    do {
      puVar5 = *(uint **)(param_1 + 0x8c);
      if (param_2 < *puVar5) {
        uVar1 = puVar5[1];
        if (uVar1 <= param_2) {
          _memset(uVar1 * 4 + puVar5[2],0,(param_2 - uVar1) * 4 + 4);
          puVar5[1] = param_2 + 1;
        }
        piVar2 = (int *)(param_2 * 4 + puVar5[2]);
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(puVar5,param_2);
      }
      loopIndex = loopIndex + 1;
      iVar3 = iVar3 + *piVar2;
    } while (param_2 != loopIndex);
  }
  return iVar3;
}

/* FUN_00131a80 @ 0x131a80 (232 bytes) */
int FUN_00131a80(allocator)
  int allocator;
{
  undefined4 *allocation;
  int bitsLeft;
  undefined4 *slotRef;
  uint slotVectorCount;
  int usedSlotBitset;
  undefined4 arena;
  uint freeSlot;
  uint *slotVector;
  
  usedSlotBitset = *(int *)(allocator + 0x434);
  bitsLeft = *(int *)(usedSlotBitset + 4);
  if (bitsLeft == 0) {
LAB_00131ae0:
    freeSlot = 0xffffffff;
  }
  else {
    freeSlot = 0;
    if ((*(uint *)(usedSlotBitset + 8) & 1) != 0) {
      freeSlot = 0;
      do {
        freeSlot = freeSlot + 1;
        bitsLeft = bitsLeft + -1;
        if (bitsLeft == 0) goto LAB_00131ae0;
      } while ((*(uint *)((freeSlot >> 3 & 0x1ffffffc) + usedSlotBitset + 8) >> (freeSlot & 0x1f) & 1) != 0);
    }
  }
  usedSlotBitset = (freeSlot >> 3 & 0x1ffffffc) + usedSlotBitset;
  *(uint *)(usedSlotBitset + 8) = 1 << (freeSlot & 0x1f) | *(uint *)(usedSlotBitset + 8);
  slotVector = *(uint **)(allocator + 0x8c);
  if (slotVector == (uint *)0x0) {
    arena = *(undefined4 *)(*(int *)(allocator + 8) + 0x374);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    slotVector = allocation + 1;
    *allocation = arena;
    allocation[1] = 2;
    allocation[2] = 0;
    allocation[4] = arena;
    arena = Arena__alloc(arena,8);
    allocation[3] = arena;
    *(uint **)(allocator + 0x8c) = slotVector;
  }
  if (freeSlot < *slotVector) {
    slotVectorCount = slotVector[1];
    if (slotVectorCount <= freeSlot) {
      _memset((void *)(slotVectorCount * 4 + slotVector[2]),0,(freeSlot - slotVectorCount) * 4 + 4);
      slotVector[1] = freeSlot + 1;
    }
    slotRef = (undefined4 *)(freeSlot * 4 + slotVector[2]);
  }
  else {
    slotRef = (undefined4 *)Vector__elementRefGrow(slotVector,freeSlot);
  }
  *slotRef = 0;
  return freeSlot;
}

/* FUN_00131c10 @ 0x131c10 (100 bytes) */
int FUN_00131c10(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x438);
  if (iVar1 == 0) {
    uVar2 = ((int (*)())FUN_00131a80)(param_1);
    uVar3 = ((int (*)())FUN_001319d0)(param_1,uVar2);
    iVar1 = FUN_00130ec0(uVar2,uVar3,*(undefined4 *)(param_1 + 8));
    *(int *)(param_1 + 0x438) = iVar1;
  }
  return iVar1;
}

/* FUN_00131c74 @ 0x131c74 (148 bytes) */
int FUN_00131c74(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  
  *(undefined4 *)(param_2 + 300) = param_3;
  puVar4 = *(uint **)(param_1 + 0x8c);
  uVar3 = *(uint *)(param_2 + 0x130);
  if (uVar3 < *puVar4) {
    uVar1 = puVar4[1];
    if (uVar1 <= uVar3) {
      _memset(uVar1 * 4 + puVar4[2],0,(uVar3 - uVar1) * 4 + 4);
      puVar4[1] = uVar3 + 1;
    }
    puVar2 = (undefined4 *)(uVar3 * 4 + puVar4[2]);
  }
  else {
    puVar2 = (undefined4 *)Vector__elementRefGrow(puVar4,uVar3);
  }
  *puVar2 = param_3;
  return;
}

/* FUN_00131d08 @ 0x131d08 (1440 bytes) */
int FUN_00131d08(program, virtualRegCount, physicalRegCount, totalRegCount, virtualIdsAlreadyOffset)
  int program;
  undefined4 virtualRegCount;
  int physicalRegCount;
  undefined4 totalRegCount;
  int virtualIdsAlreadyOffset;
{
  int *instNextC;
  int *physicalSetCursor;
  int blockCursorC;
  int prefixPrevious;
  int classIndexCounter;
  int regClassB;
  int regKindFlagB;
  int nextBlockC;
  int wordCountdown;
  undefined4 *classNextVirtual;
  int *classBaseOffsets;
  int *virtualSetCursor;
  int *instAfter;
  int *inst;
  int virtualMapBase;
  int newRegByteOffset;
  int physicalSetA;
  int virtualSetA;
  int lastClassOffset;
  int physicalCountArray;
  int virtualCountArray;
  int classCount;
  int blockCursor;
  int newRegister;
  int nextBlock;
  int classOffset;
  int regClass;
  int regKindFlag;
  int blockCursorB;
  int compiler;
  undefined4 *allocation;
  undefined4 arena;
  int allocation2;
  int operandRecord;
  int loopIndex;
  int *instNextA;
  int *instNextB;
  int compilerB;
  int classArrayBytes;
  undefined4 logTrailingArg;
  int *backendTarget;
  undefined4 *zeroCursor;
  undefined4 *bitsetWordCursor;
  uint wordOrClassIndex;
  uint registerNumber;
  int *bitsetOrCursor;
  int compilerC;
  int nextBlockB;
  int classByteOffset;
  int *instC;
  
  classArrayBytes = *(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x14) << 2;
  allocation2 = Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x378),classArrayBytes);
  classArrayBytes = Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x378),classArrayBytes);
  arena = Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x378),
                       *(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x14) << 2);
  backendTarget = *(int **)(*(int *)(program + 8) + 0x30c);
  (**(code **)(*backendTarget + 0x134))(backendTarget,arena,*(int *)(program + 8));
  compilerC = *(int *)(program + 8);
  if (0 < *(int *)(*(int *)(compilerC + 0x30c) + 0x14)) {
    loopIndex = 0;
    classByteOffset = 0;
    do {
      arena = *(undefined4 *)(compilerC + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,0x20c);
      wordCountdown = 0x80;
      *allocation = arena;
      allocation[1] = 0x80;
      allocation[2] = 0x1000;
      bitsetWordCursor = allocation + 1;
      do {
        bitsetWordCursor[2] = 0;
        bitsetWordCursor = bitsetWordCursor + 1;
        wordCountdown = wordCountdown + -1;
      } while (wordCountdown != 0);
      *(undefined4 **)(allocation2 + classByteOffset) = allocation + 1;
      arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,0x20c);
      wordCountdown = 0x80;
      *allocation = arena;
      allocation[1] = 0x80;
      allocation[2] = 0x1000;
      bitsetWordCursor = allocation + 1;
      do {
        bitsetWordCursor[2] = 0;
        bitsetWordCursor = bitsetWordCursor + 1;
        wordCountdown = wordCountdown + -1;
      } while (wordCountdown != 0);
      *(undefined4 **)(classArrayBytes + classByteOffset) = allocation + 1;
      loopIndex = loopIndex + 1;
      compilerC = *(int *)(program + 8);
      classByteOffset = classByteOffset + 4;
    } while (loopIndex < *(int *)(*(int *)(compilerC + 0x30c) + 0x14));
  }
  nextBlockB = *(int *)(*(int *)(program + 900) + 8);
  blockCursor = *(int *)(program + 900);
  if (nextBlockB != 0) {
    do {
      nextBlockC = nextBlockB;
      instC = *(int **)(blockCursor + 0x98);
      instAfter = (int *)instC[2];
      if ((int *)instC[2] != (int *)0x0) {
        do {
          instNextA = instAfter;
          if (((instC[5] & 1U) != 0) && (instC[0x20] != 0)) {
            regKindFlagB = RegKind__flagBit0(instC[0x26]);
            if ((regKindFlagB == 0) ||
               (((instC[5] & 2U) != 0 ||
                (regKindFlagB = (**(code **)(*instC + 0x50))(instC), regKindFlagB != 0)))) {
LAB_00131f98:
              instNextA = (int *)instC[2];
            }
            else {
              regClassB = FUN_00130bfc(program,instC);
              registerNumber = instC[0x25];
              if ((instC[5] & 0x40U) == 0) {
                regClassB = regClassB * 4;
                wordOrClassIndex = registerNumber >> 3 & 0x1ffffffc;
                if ((*(uint *)(wordOrClassIndex + *(int *)(classArrayBytes + regClassB) + 8) >> (registerNumber & 0x1f) & 1) != 0)
                goto LAB_00131f98;
                virtualCountArray = *(int *)(*(int *)(program + 0x3c0) + 0x18);
                *(int *)(regClassB + virtualCountArray) = *(int *)(regClassB + virtualCountArray) + 1;
                regClassB = *(int *)(classArrayBytes + regClassB);
              }
              else {
                regClassB = regClassB * 4;
                wordOrClassIndex = registerNumber >> 3 & 0x1ffffffc;
                if ((*(uint *)(wordOrClassIndex + *(int *)(allocation2 + regClassB) + 8) >> (registerNumber & 0x1f) & 1) != 0)
                goto LAB_00131f98;
                physicalCountArray = *(int *)(*(int *)(program + 0x3c0) + 0x14);
                *(int *)(regClassB + physicalCountArray) = *(int *)(regClassB + physicalCountArray) + 1;
                regClassB = *(int *)(allocation2 + regClassB);
              }
              bitsetOrCursor = (int *)(1 << (registerNumber & 0x1f) | *(uint *)(wordOrClassIndex + regClassB + 8));
              *(int **)(wordOrClassIndex + regClassB + 8) = bitsetOrCursor;
              instNextA = (int *)instC[2];
            }
          }
          instAfter = (int *)instNextA[2];
          instC = instNextA;
        } while ((int *)instNextA[2] != (int *)0x0);
        nextBlockC = *(int *)(blockCursor + 8);
      }
      nextBlockB = *(int *)(nextBlockC + 8);
      blockCursor = nextBlockC;
    } while (*(int *)(nextBlockC + 8) != 0);
    compilerC = *(int *)(program + 8);
  }
  classCount = *(int *)(*(int *)(compilerC + 0x30c) + 0x14);
  lastClassOffset = classCount + -1;
  if (-1 < lastClassOffset) {
    lastClassOffset = lastClassOffset * 4;
    classIndexCounter = 0;
    physicalSetCursor = (int *)(allocation2 + lastClassOffset);
    virtualSetCursor = (int *)(classArrayBytes + lastClassOffset);
    do {
      virtualSetA = *virtualSetCursor;
      if (virtualSetA != 0) {
        Arena__free(*(undefined4 *)(virtualSetA + -4),virtualSetA + -4);
      }
      physicalSetA = *physicalSetCursor;
      if (physicalSetA != 0) {
        Arena__free(*(undefined4 *)(physicalSetA + -4),physicalSetA + -4);
      }
      classIndexCounter = classIndexCounter + 1;
      virtualSetCursor = virtualSetCursor + -1;
      physicalSetCursor = physicalSetCursor + -1;
    } while (classCount != classIndexCounter);
    compilerC = *(int *)(program + 8);
  }
  Arena__free(*(undefined4 *)(compilerC + 0x378),classArrayBytes);
  Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x378),allocation2);
  classArrayBytes = *(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x14) << 2;
  classBaseOffsets = (int *)Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x378),classArrayBytes);
  *classBaseOffsets = 0;
  compilerB = *(int *)(program + 8);
  if (1 < *(int *)(*(int *)(compilerB + 0x30c) + 0x14)) {
    wordOrClassIndex = 1;
    bitsetOrCursor = classBaseOffsets;
    do {
      classOffset = wordOrClassIndex * 4;
      prefixPrevious = *bitsetOrCursor;
      wordOrClassIndex = wordOrClassIndex + 1;
      bitsetOrCursor = bitsetOrCursor + 1;
      *bitsetOrCursor = prefixPrevious + *(int *)(classOffset + *(int *)(*(int *)(program + 0x3c0) + 0x14) + -4);
      compilerB = *(int *)(program + 8);
    } while ((int)wordOrClassIndex < *(int *)(*(int *)(compilerB + 0x30c) + 0x14));
  }
  classNextVirtual = (undefined4 *)Arena__alloc(*(undefined4 *)(compilerB + 0x378),classArrayBytes);
  compiler = *(int *)(program + 8);
  if (0 < *(int *)(*(int *)(compiler + 0x30c) + 0x14)) {
    bitsetOrCursor = (int *)0x0;
    wordOrClassIndex = 0;
    zeroCursor = classNextVirtual;
    do {
      *zeroCursor = 0;
      bitsetOrCursor = (int *)((int)bitsetOrCursor + 1);
      compiler = *(int *)(program + 8);
      zeroCursor = zeroCursor + 1;
    } while ((int)bitsetOrCursor < *(int *)(*(int *)(compiler + 0x30c) + 0x14));
  }
  nextBlock = *(int *)(*(int *)(program + 900) + 8);
  blockCursorC = *(int *)(program + 900);
  if (nextBlock != 0) {
    do {
      blockCursorB = nextBlock;
      instNextC = (int *)(*(int **)(blockCursorC + 0x98))[2];
      inst = *(int **)(blockCursorC + 0x98);
      if (instNextC != (int *)0x0) {
        do {
          instNextB = instNextC;
          if (((inst[5] & 1U) != 0) && (inst[0x20] != 0)) {
            regKindFlag = RegKind__flagBit0(inst[0x26]);
            if ((regKindFlag == 0) ||
               (((inst[5] & 2U) != 0 ||
                (regKindFlag = (**(code **)(*inst + 0x50))(inst), regKindFlag != 0)))) {
              instNextB = (int *)inst[2];
            }
            else {
              regClass = FUN_00130bfc(program,inst);
              if ((inst[5] & 0x40U) == 0) {
                if (virtualIdsAlreadyOffset == 0) {
                  newRegister = physicalRegCount + inst[0x25];
                }
                else {
                  newRegister = inst[0x25];
                }
                newRegByteOffset = newRegister * 4;
                *(undefined4 *)(*(int *)(program + 0x458) + newRegByteOffset) = 0xffffffff;
              }
              else {
                bitsetOrCursor = (int *)inst[0x25];
                virtualMapBase = *(int *)(program + 0x460);
                newRegister = (int)bitsetOrCursor * 4;
                if (*(int *)(newRegister + virtualMapBase) == -1) {
                  *(undefined4 *)(newRegister + virtualMapBase) = classNextVirtual[regClass];
                  classNextVirtual[regClass] = classNextVirtual[regClass] + 1;
                  virtualMapBase = *(int *)(program + 0x460);
                }
                newRegister = *(int *)(newRegister + virtualMapBase) + classBaseOffsets[regClass];
                newRegByteOffset = newRegister * 4;
                *(int **)(*(int *)(program + 0x458) + newRegByteOffset) = bitsetOrCursor;
              }
              operandRecord = IRInst__getOperandRecord(inst,0);
              *(int *)(operandRecord + 8) = newRegister;
              *(int *)(*(int *)(program + 0x45c) + newRegByteOffset) = regClass;
              instNextB = (int *)inst[2];
            }
          }
          instNextC = (int *)instNextB[2];
          inst = instNextB;
        } while ((int *)instNextB[2] != (int *)0x0);
        blockCursorB = *(int *)(blockCursorC + 8);
      }
      nextBlock = *(int *)(blockCursorB + 8);
      blockCursorC = blockCursorB;
    } while (*(int *)(blockCursorB + 8) != 0);
    compiler = *(int *)(program + 8);
  }
  logTrailingArg = 0;
  *(undefined4 *)(program + 0x34) = 4;
  Arena__free(*(undefined4 *)(compiler + 0x378),classBaseOffsets);
  return Compiler__logf(*(undefined4 *)(program + 8),
               "Register puVar7 : Repartition -> %d physical + %d virtual = %d regs\n",physicalRegCount,
               virtualRegCount,totalRegCount,wordOrClassIndex,logTrailingArg,bitsetOrCursor);
}

/* HwLimits__buildInterferenceGraph @ 0x1322a8 (416 bytes) */
int HwLimits__buildInterferenceGraph(this, graph, fixedRegCount, regCount, useCoalesced, compiler)
  undefined4 this;
  undefined4 graph;
  int fixedRegCount;
  int regCount;
  int useCoalesced;
  int compiler;
{
  undefined4 arena;
  uint walkFlags;
  uint poppedReg;
  uint cursorFlags;
  uint regNode;
  uint bitScanIndex;
  uint wordByteOff5;
  uint topIndex;
  uint wordByteOff22;
  uint bitIndex;
  uint instFlags;
  uint liveWordCount;
  uint bitPos;
  uint worklistCount;
  int *groupHead;
  int *sourceInst;
  int *walkInst;
  int loopLeft4;
  int compCounter;
  int repReg2;
  int srcOperandRecord;
  int srcCount;
  int defWordAddr;
  int componentIdx;
  int operandRecord;
  int isVertexFetchResult;
  int src1Inst;
  int anyComponentLive;
  int noSourceResult;
  int byteLoopLeft;
  int srcIndex;
  int isMovResult;
  int isUndefinedResult;
  int isPhiResult;
  int repReg;
  int wordsLeft;
  int nextBlock;
  bool hasGroup;
  bool moreComponents;
  uint bitCount;
  int *bitsetWordPtr;
  uint bitIdx5;
  undefined4 *allocation;
  undefined4 *worklist;
  undefined4 *inWorklistAlloc;
  int compFlagResult;
  uint *stackEntry;
  int *liveWordPtr;
  undefined4 *inWorklistWords;
  int *cursorInst;
  int allocCtxOrBlock;
  int *liveWords;
  uint *worklistVecHeader;
  int rowIndex;
  undefined4 uVar18;
  undefined4 allocArena;
  int nextRow;
  uint wordOff;
  uint inWorklistWordCount;
  int containsResult;
  int innerIndexOrScratch;
  int excludedRegs0;
  undefined4 excludedRegs1;
  undefined4 excludedRegs2;
  undefined4 excludedRegs3;
  int swizzleComponentUse [2];
  
  allocCtxOrBlock = *(int *)(compiler + COMP_currentProgram);
  *(undefined4 *)(allocCtxOrBlock + 0x244) = 0;
  *(undefined4 *)(allocCtxOrBlock + 0x240) = 0;
  if (0 < fixedRegCount) {
    rowIndex = 0;
    while (rowIndex = rowIndex + 1, fixedRegCount != rowIndex) {
      if (0 < rowIndex) {
        innerIndexOrScratch = 0;
        do {
          nextRow = innerIndexOrScratch + 1;
          ((int (*)())FUN_00135334)(graph,rowIndex,innerIndexOrScratch);
          innerIndexOrScratch = nextRow;
        } while (rowIndex != nextRow);
      }
    }
  }
  bitCount = regCount * 4;
  arena = *(undefined4 *)(compiler + COMP_arenaB);
  liveWordCount = bitCount + 0x1f >> 5;
  allocation = (undefined4 *)Arena__alloc(arena,liveWordCount * 4 + 0xc);
  liveWords = allocation + 1;
  *allocation = arena;
  allocation[1] = liveWordCount;
  allocation[2] = bitCount;
  if (liveWordCount != 0) {
    bitsetWordPtr = liveWords;
    if (liveWordCount == 0) {
      liveWordCount = 1;
    }
    do {
      bitsetWordPtr[2] = 0;
      bitsetWordPtr = bitsetWordPtr + 1;
      liveWordCount = liveWordCount - 1;
    } while (liveWordCount != 0);
  }
  allocArena = *(undefined4 *)(compiler + COMP_arenaB);
  worklist = (undefined4 *)Arena__alloc(allocArena,0x18);
  worklistVecHeader = worklist + 1;
  *worklist = allocArena;
  worklist[1] = 2;
  worklist[2] = 0;
  worklist[4] = allocArena;
  uVar18 = Arena__alloc(allocArena,8);
  worklist[3] = uVar18;
  inWorklistWordCount = regCount + 0x1fU >> 5;
  inWorklistAlloc = (undefined4 *)Arena__alloc(allocArena,inWorklistWordCount * 4 + 0xc);
  inWorklistWords = inWorklistAlloc + 1;
  *inWorklistAlloc = allocArena;
  inWorklistAlloc[1] = inWorklistWordCount;
  inWorklistAlloc[2] = regCount;
  if (inWorklistWordCount != 0) {
    inWorklistAlloc = inWorklistWords;
    if (inWorklistWordCount == 0) {
      inWorklistWordCount = 1;
    }
    do {
      inWorklistAlloc[2] = 0;
      inWorklistAlloc = inWorklistAlloc + 1;
      inWorklistWordCount = inWorklistWordCount - 1;
    } while (inWorklistWordCount != 0);
  }
  worklist[5] = inWorklistWords;
  allocCtxOrBlock = *(int *)(allocCtxOrBlock + 900);
  nextBlock = *(int *)(allocCtxOrBlock + 8);
  do {
    if (nextBlock == 0) {
      if (liveWords != (int *)0x0) {
        Arena__free(*allocation,allocation);
      }
      return;
    }
    wordsLeft = *liveWords;
    if (wordsLeft != 0) {
      bitsetWordPtr = liveWords;
      innerIndexOrScratch = wordsLeft;
      if (wordsLeft == 0) {
        innerIndexOrScratch = 1;
      }
      do {
        bitsetWordPtr[2] = 0;
        bitsetWordPtr = bitsetWordPtr + 1;
        innerIndexOrScratch = innerIndexOrScratch + -1;
      } while (innerIndexOrScratch != 0);
    }
    if (useCoalesced == 0) {
      innerIndexOrScratch = *(int *)(allocCtxOrBlock + 0x104);
      if (wordsLeft != 0) {
        bitsetWordPtr = liveWords;
        if (wordsLeft == 0) {
          wordsLeft = 1;
        }
        do {
          liveWordPtr = (int *)(innerIndexOrScratch + 8);
          innerIndexOrScratch = innerIndexOrScratch + 4;
          bitsetWordPtr[2] = *liveWordPtr;
          bitsetWordPtr = bitsetWordPtr + 1;
          wordsLeft = wordsLeft + -1;
        } while (wordsLeft != 0);
      }
    }
    else if (0 < (int)bitCount) {
      bitScanIndex = 0;
      do {
        if ((*(uint *)((bitScanIndex >> 3 & 0x1ffffffc) + *(int *)(allocCtxOrBlock + 0x104) + 8) >> (bitScanIndex & 0x1f)
            & 1) != 0) {
          innerIndexOrScratch = ((int)bitScanIndex >> 2) + (uint)((int)bitScanIndex < 0 && (bitScanIndex & 3) != 0);
          repReg = ((int (*)())FUN_00134bf0)(graph,innerIndexOrScratch,1);
          bitIdx5 = bitScanIndex + innerIndexOrScratch * -4 + repReg * 4;
          wordOff = bitIdx5 >> 3 & 0x1ffffffc;
          *(uint *)((int)liveWords + wordOff + 8) =
               1 << (bitIdx5 & 0x1f) | *(uint *)((int)liveWords + wordOff + 8);
        }
        bitScanIndex = bitScanIndex + 1;
      } while (bitCount != bitScanIndex);
    }
    groupHead = *(int **)(allocCtxOrBlock + 0xa0);
    for (walkInst = (int *)(*(int **)(allocCtxOrBlock + 0xa0))[1]; walkInst != (int *)0x0;
        walkInst = (int *)walkInst[1]) {
      if ((groupHead == *(int **)(allocCtxOrBlock + 0x98)) || ((walkInst[5] & 4U) == 0)) {
        hasGroup = groupHead != (int *)0x0;
        walkInst = groupHead;
        if (hasGroup) {
          do {
            instFlags = walkInst[5];
            if ((instFlags & 1) != 0) {
              isPhiResult = (**(code **)(*walkInst + 0x7c))(walkInst);
              if (((isPhiResult == 0) && (walkInst[0x20] != 0)) &&
                 (isPhiResult = RegKind__flagBit0(walkInst[0x26]), isPhiResult != 0)) {
                instFlags = walkInst[5];
                if ((instFlags & 2) == 0) {
                  isUndefinedResult = (**(code **)(*walkInst + 0x50))(walkInst);
                  if (isUndefinedResult != 0) goto code_r0x00132adc;
                  excludedRegs0 = UNK_001affec;
                  excludedRegs1 = UNK_001afff0;
                  excludedRegs2 = UNK_001afff4;
                  excludedRegs3 = UNK_001afff8;
                  regNode = ((int (*)())FUN_00134bf0)(graph,walkInst[0x25],useCoalesced);
                  isMovResult = (**(code **)(*walkInst + 100))(walkInst);
                  if (isMovResult != 0) {
                    for (srcIndex = 1; innerIndexOrScratch = (**(code **)(*walkInst + 0x14))(walkInst),
                        srcIndex <= innerIndexOrScratch; srcIndex = srcIndex + 1) {
                      if ((((walkInst[srcIndex * 6 + 0x28] & 1U) != 0) ||
                          ((walkInst[srcIndex * 6 + 0x28] & 2U) != 0)) ||
                         (innerIndexOrScratch = IRInst__isSourceSelectIdentity(walkInst,srcIndex), innerIndexOrScratch == 0))
                      goto code_r0x001327f0;
                    }
                    if ((walkInst[0x48] == 0) && (walkInst[0x49] == 0)) {
                      if ((walkInst[0x20] != 0) &&
                         (((srcIndex = RegKind__flagBit0(walkInst[0x26]), srcIndex != 0 &&
                           ((walkInst[5] & 2U) == 0)) &&
                          (srcIndex = (**(code **)(*walkInst + 0x50))(walkInst), srcIndex == 0)))) {
                        byteLoopLeft = 4;
                        cursorInst = walkInst;
                        do {
                          if ((uint)(*(byte *)(cursorInst + 0x27) - 2) < 2) goto code_r0x001327f0;
                          cursorInst = (int *)((int)cursorInst + 1);
                          byteLoopLeft = byteLoopLeft + -1;
                        } while (byteLoopLeft != 0);
                      }
                      IRInst__getOperandRecord(walkInst,0);
                      noSourceResult = IRInst__operandKindClass(walkInst,0);
                      if (((noSourceResult == 0) && ((walkInst[5] & 2U) == 0)) &&
                         (((((walkInst[5] & 0x200U) == 0 &&
                            ((cursorInst = (int *)IRInst__getOperandSource(walkInst,1), cursorInst[0x20] != 0 &&
                             (noSourceResult = RegKind__flagBit0(cursorInst[0x26]), noSourceResult != 0)))) &&
                           ((cursorInst[5] & 2U) == 0)) &&
                          (noSourceResult = (**(code **)(*cursorInst + 0x50))(cursorInst), noSourceResult == 0)))) {
                        excludedRegs0 = ((int (*)())FUN_00134bf0)(graph,cursorInst[0x25],useCoalesced);
                      }
                    }
                  }
code_r0x001327f0:
                  anyComponentLive = FUN_0013097c(liveWords,regNode);
                  if (anyComponentLive == 0) {
                    if ((*(uint *)((regNode >> 3 & 0x1ffffffc) + worklist[5] + 8) >> (regNode & 0x1f) &
                        1) != 0) goto code_r0x00132adc;
                    worklistCount = worklist[2];
                    if (worklistCount < *worklistVecHeader) {
                      _memset((void *)(worklistCount * 4 + worklist[3]),0,4);
                      stackEntry = (uint *)(worklistCount * 4 + worklist[3]);
                      worklist[2] = worklistCount + 1;
                    }
                    else {
                      stackEntry = (uint *)Vector__elementRefGrow(worklistVecHeader,worklistCount);
                    }
                    *stackEntry = regNode;
                    instFlags = walkInst[5];
                  }
                  else {
                    nextBlock = 0;
                    if (0 < regCount) {
code_r0x00132828:
                      if ((((((walkInst[5] & 0x200U) == 0) ||
                            (cursorInst = (int *)IRInst__getOperandSource(walkInst,walkInst[0x21]),
                            cursorInst == (int *)0x0)) || (cursorInst[0x20] == 0)) ||
                          ((innerIndexOrScratch = RegKind__flagBit0(cursorInst[0x26]), innerIndexOrScratch == 0 ||
                           ((cursorInst[5] & 2U) != 0)))) ||
                         (innerIndexOrScratch = (**(code **)(*cursorInst + 0x50))(cursorInst), innerIndexOrScratch != 0)) {
                        innerIndexOrScratch = 0;
                        do {
                          nextRow = IRInst__getOperandRecord(walkInst,0);
                          if ((*(char *)(innerIndexOrScratch + nextRow + 0x10) != '\x01') &&
                             (nextRow = FUN_00130958(liveWords,nextBlock,innerIndexOrScratch), nextRow != 0)) {
                            nextRow = ((int (*)())FUN_00134bf0)(graph,nextBlock,useCoalesced);
                            containsResult = FUN_001303f4(nextRow,&excludedRegs0);
                            if (containsResult == 0) goto code_r0x00132970;
                          }
                          moreComponents = innerIndexOrScratch != 3;
                          innerIndexOrScratch = innerIndexOrScratch + 1;
                        } while (moreComponents);
                      }
                      else {
                        compCounter = 0;
                        innerIndexOrScratch = ((int (*)())FUN_00134bf0)(graph,cursorInst[0x25],useCoalesced);
                        do {
                          nextRow = FUN_00130958(liveWords,nextBlock,compCounter);
                          if (((nextRow != 0) &&
                              (nextRow = ((int (*)())FUN_00134bf0)(graph,nextBlock,useCoalesced), nextRow != excludedRegs0))
                             && ((innerIndexOrScratch != nextRow ||
                                 (compFlagResult = FUN_000f313c(walkInst,compCounter), compFlagResult != 0))))
                          goto code_r0x00132970;
                          moreComponents = compCounter != 3;
                          compCounter = compCounter + 1;
                        } while (moreComponents);
                      }
                      goto code_r0x00132990;
                    }
code_r0x0013299c:
                    if ((((*(int *)(walkInst[0x22] + 8) == 0x32) &&
                         (cursorInst = (int *)IRInst__getOperandSource(walkInst,1), cursorInst[0x20] != 0)) &&
                        (nextBlock = RegKind__flagBit0(cursorInst[0x26]), nextBlock != 0)) &&
                       (((cursorInst[5] & 2U) == 0 &&
                        (nextBlock = (**(code **)(*cursorInst + 0x50))(cursorInst), nextBlock == 0)))) {
                      src1Inst = IRInst__getOperandSource(walkInst,1);
                      uVar18 = ((int (*)())FUN_00134bf0)(graph,*(undefined4 *)(src1Inst + 0x94),useCoalesced);
                      ((int (*)())FUN_00135334)(graph,regNode,uVar18);
                    }
                    isVertexFetchResult = (**(code **)(*walkInst + 0x2c))(walkInst);
                    if (isVertexFetchResult == 0) goto code_r0x00132adc;
                    src1Inst = IRInst__getOperandSource(walkInst,1);
                    uVar18 = ((int (*)())FUN_00134bf0)(graph,*(undefined4 *)(src1Inst + 0x94),useCoalesced);
                    ((int (*)())FUN_00135334)(graph,regNode,uVar18);
                    instFlags = walkInst[5];
                  }
                }
              }
              else {
code_r0x00132adc:
                instFlags = walkInst[5];
              }
            }
            cursorInst = groupHead;
          } while (((int *)walkInst[2] != (int *)0x0) &&
                  (walkInst = (int *)walkInst[2], (instFlags & 4) != 0));
          do {
            cursorFlags = cursorInst[5];
            if ((cursorFlags & 1) != 0) {
              isPhiResult = (**(code **)(*cursorInst + 0x7c))(cursorInst);
              if (((isPhiResult == 0) && (cursorInst[0x20] != 0)) &&
                 (isPhiResult = RegKind__flagBit0(cursorInst[0x26]), isPhiResult != 0)) {
                cursorFlags = cursorInst[5];
                if ((cursorFlags & 2) != 0) goto code_r0x00132ca8;
                isUndefinedResult = (**(code **)(*cursorInst + 0x50))(cursorInst);
                if (isUndefinedResult == 0) {
                  innerIndexOrScratch = 0;
                  repReg = ((int (*)())FUN_00134bf0)(graph,cursorInst[0x25],useCoalesced);
                  bitPos = repReg << 2;
                  bitIndex = bitPos;
                  do {
                    operandRecord = IRInst__getOperandRecord(cursorInst,0);
                    if (*(char *)(innerIndexOrScratch + operandRecord + 0x10) != '\x01') {
                      wordByteOff5 = bitIndex >> 3 & 0x1ffffffc;
                      *(uint *)((int)liveWords + wordByteOff5 + 8) =
                           *(uint *)((int)liveWords + wordByteOff5 + 8) & ~(1 << (bitIndex & 0x1f));
                    }
                    moreComponents = innerIndexOrScratch != 3;
                    bitIndex = bitIndex + 1;
                    innerIndexOrScratch = innerIndexOrScratch + 1;
                  } while (moreComponents);
                  cursorFlags = cursorInst[5];
                  if ((cursorFlags & 0x200) == 0) goto code_r0x00132ca8;
                  sourceInst = (int *)IRInst__getOperandSource(cursorInst,cursorInst[0x21]);
                  if (((sourceInst != (int *)0x0) && (sourceInst[0x20] != 0)) &&
                     ((operandRecord = RegKind__flagBit0(sourceInst[0x26]), operandRecord != 0 &&
                      (((sourceInst[5] & 2U) == 0 &&
                       (operandRecord = (**(code **)(*sourceInst + 0x50))(sourceInst), operandRecord == 0)))))) {
                    componentIdx = 0;
                    do {
                      innerIndexOrScratch = IRInst__getOperandRecord(cursorInst,0);
                      if ((*(char *)(componentIdx + innerIndexOrScratch + 0x10) == '\x01') &&
                         (innerIndexOrScratch = ((int (*)())FUN_00138240)(sourceInst,componentIdx), innerIndexOrScratch != 0)) {
                        wordByteOff22 = bitPos >> 3 & 0x1ffffffc;
                        *(uint *)((int)liveWords + wordByteOff22 + 8) =
                             *(uint *)((int)liveWords + wordByteOff22 + 8) & ~(1 << (bitPos & 0x1f));
                      }
                      moreComponents = componentIdx != 3;
                      bitPos = bitPos + 1;
                      componentIdx = componentIdx + 1;
                    } while (moreComponents);
                  }
                }
              }
              cursorFlags = cursorInst[5];
            }
code_r0x00132ca8: ;
          } while (((int *)cursorInst[2] != (int *)0x0) &&
                  (cursorInst = (int *)cursorInst[2], (cursorFlags & 4) != 0));
        }
        while (walkInst = groupHead, worklist[2] != 0) {
          topIndex = worklist[2] - 1;
          stackEntry = (uint *)0x0;
          if (topIndex < (uint)worklist[2]) {
            stackEntry = (uint *)(topIndex * 4 + worklist[3]);
          }
          poppedReg = *stackEntry;
          Vector__removeAt(worklistVecHeader,worklist[2] - 1);
          defWordAddr = (poppedReg >> 3 & 0x1ffffffc) + worklist[5];
          *(uint *)(defWordAddr + 8) =
               (-2 << (poppedReg & 0x1f) | 0xfffffffeU >> 0x20 - (poppedReg & 0x1f)) &
               *(uint *)(defWordAddr + 8);
          if (0 < regCount) {
            componentIdx = 0;
            do {
              innerIndexOrScratch = FUN_0013097c(liveWords,componentIdx);
              if (innerIndexOrScratch != 0) {
                uVar18 = ((int (*)())FUN_00134bf0)(graph,componentIdx,useCoalesced);
                ((int (*)())FUN_00135334)(graph,poppedReg,uVar18);
              }
              componentIdx = componentIdx + 1;
            } while (regCount != componentIdx);
          }
        }
        while (hasGroup) {
          walkFlags = walkInst[5];
          if ((walkFlags & 1) != 0) {
            operandRecord = IRInst__getOperandRecord(walkInst,0);
            if (((((*(int *)(operandRecord + 0x10) != UNK_001affe8) &&
                  (*(int *)(walkInst[0x22] + 8) != 0x8e)) &&
                 (operandRecord = (**(code **)(*walkInst + 0x34))(walkInst), operandRecord == 0)) &&
                ((operandRecord = (**(code **)(*walkInst + 0x38))(walkInst), operandRecord == 0 &&
                 (operandRecord = (**(code **)(*walkInst + 0x60))(walkInst), operandRecord == 0)))) &&
               (operandRecord = (**(code **)(*walkInst + 0x5c))(walkInst), operandRecord == 0)) {
              walkFlags = walkInst[5];
              srcCount = walkInst[0x21];
              if ((walkFlags & 0x200) != 0) {
                srcCount = srcCount + -1;
              }
              if (0 < srcCount) {
                innerIndexOrScratch = 1;
                do {
                  cursorInst = (int *)IRInst__getOperandSource(walkInst,innerIndexOrScratch);
                  if (((cursorInst[0x20] != 0) && (nextRow = RegKind__flagBit0(cursorInst[0x26]), nextRow != 0))
                     && (((cursorInst[5] & 2U) == 0 &&
                         ((nextRow = (**(code **)(*cursorInst + 0x50))(cursorInst), nextRow == 0 &&
                          (nextRow = ((int (*)())FUN_00137e98)(walkInst,innerIndexOrScratch,walkInst), nextRow == 0)))))) {
                    srcOperandRecord = IRInst__getOperandRecord(walkInst,innerIndexOrScratch);
                    SelectWord__readMask(swizzleComponentUse,*(undefined4 *)(srcOperandRecord + 0x10));
                    excludedRegs0 = swizzleComponentUse[0];
                    repReg2 = ((int (*)())FUN_00134bf0)(graph,cursorInst[0x25],useCoalesced);
                    loopLeft4 = 4;
                    bitIndex = repReg2 << 2;
                    nextRow = 0;
                    do {
                      if (*(char *)((int)&excludedRegs0 + nextRow) != '\0') {
                        wordOff = bitIndex >> 3 & 0x1ffffffc;
                        *(uint *)((int)liveWords + wordOff + 8) =
                             1 << (bitIndex & 0x1f) | *(uint *)((int)liveWords + wordOff + 8);
                      }
                      nextRow = nextRow + 1;
                      bitIndex = bitIndex + 1;
                      loopLeft4 = loopLeft4 + -1;
                    } while (loopLeft4 != 0);
                  }
                  innerIndexOrScratch = innerIndexOrScratch + 1;
                } while (innerIndexOrScratch <= srcCount);
                walkFlags = walkInst[5];
              }
              if ((walkFlags & 0x200) == 0) goto code_r0x0013304c;
              cursorInst = (int *)IRInst__getOperandSource(walkInst,walkInst[0x21]);
              if ((((cursorInst != (int *)0x0) && (cursorInst[0x20] != 0)) &&
                  (srcCount = RegKind__flagBit0(cursorInst[0x26]), srcCount != 0)) &&
                 ((((cursorInst[5] & 2U) == 0 &&
                   (srcCount = (**(code **)(*cursorInst + 0x50))(cursorInst), srcCount == 0)) &&
                  (srcCount = ((int (*)())FUN_00137e98)(walkInst,walkInst[0x21],walkInst), srcCount == 0)))) {
                innerIndexOrScratch = 0;
                repReg = ((int (*)())FUN_00134bf0)(graph,cursorInst[0x25],useCoalesced);
                bitIndex = repReg << 2;
                do {
                  operandRecord = IRInst__getOperandRecord(walkInst,0);
                  if ((*(char *)(innerIndexOrScratch + operandRecord + 0x10) == '\x01') &&
                     (operandRecord = ((int (*)())FUN_00138240)(cursorInst,innerIndexOrScratch), operandRecord != 0)) {
                    wordOff = bitIndex >> 3 & 0x1ffffffc;
                    *(uint *)((int)liveWords + wordOff + 8) =
                         1 << (bitIndex & 0x1f) | *(uint *)((int)liveWords + wordOff + 8);
                  }
                  hasGroup = innerIndexOrScratch != 3;
                  bitIndex = bitIndex + 1;
                  innerIndexOrScratch = innerIndexOrScratch + 1;
                } while (hasGroup);
              }
            }
            walkFlags = walkInst[5];
          }
code_r0x0013304c:
          if ((int *)walkInst[2] == (int *)0x0) break;
          hasGroup = (walkFlags & 4) != 0;
          walkInst = (int *)walkInst[2];
        }
        walkInst = (int *)groupHead[1];
      }
      groupHead = walkInst;
    }
    allocCtxOrBlock = *(int *)(allocCtxOrBlock + 8);
    nextBlock = *(int *)(allocCtxOrBlock + 8);
  } while( true );
code_r0x00132970:
  ((int (*)())FUN_00135334)(graph,regNode,nextRow);
code_r0x00132990:
  nextBlock = nextBlock + 1;
  if (regCount == nextBlock) goto code_r0x0013299c;
  goto code_r0x00132828;
}

/* FUN_001330f4 @ 0x1330f4 (328 bytes) */
int FUN_001330f4(param_1, inst)
  undefined4 param_1;
  int *inst;
{
  int *operandVReg;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  do {
    operandVReg = (int *)IRInst__getOperandSource(inst,inst[0x21]);
    if (((operandVReg[0x20] != 0) && (iVar2 = RegKind__flagBit0(operandVReg[0x26]), iVar2 != 0)) &&
       ((operandVReg[5] & 2U) == 0)) {
      (**(code **)(*operandVReg + 0x50))(operandVReg);
    }
    uVar3 = ((int (*)())FUN_00134bf0)(param_1,inst[0x25],0);
    iVar2 = ((int (*)())FUN_00134bf0)(param_1,operandVReg[0x25],0);
    iVar4 = ((int (*)())FUN_0013555c)(param_1,iVar2,uVar3);
  } while (((((iVar4 != 0) && ((operandVReg[5] & 0x200U) != 0)) &&
            ((piVar5 = (int *)IRInst__getOperandSource(operandVReg,operandVReg[0x21]), piVar5[0x20] != 0 &&
             ((iVar4 = RegKind__flagBit0(piVar5[0x26]), iVar4 != 0 && ((piVar5[5] & 2U) == 0)))))) &&
           (iVar4 = (**(code **)(*piVar5 + 0x50))(piVar5), iVar4 == 0)) &&
          ((iVar4 = ((int (*)())FUN_00134bf0)(param_1,piVar5[0x25],0), iVar2 != iVar4 &&
           (inst = operandVReg, operandVReg != (int *)0x0))));
  return;
}

/* FUN_0013323c @ 0x13323c (3348 bytes) */
int FUN_0013323c(pass, copyState)
  int pass;
  undefined4 copyState;
{
  undefined4 *pendingTopRef;
  undefined4 *deferredTopRef;
  undefined4 *deferredSlotRef;
  undefined4 newSrcDef;
  undefined4 newSwizzle;
  undefined4 pendingSrcDef;
  uint wordsLeft;
  uint bitInWord;
  uint *bitsetData;
  uint *prevFlagsPtr;
  int blockQuery30;
  bool notLastLane;
  int bitsetWordsLeft;
  int bitsToClear;
  int registerIndex;
  int compilerAgain;
  int deferredByteOffset;
  uint bitsetWordCount;
  uint pendingCount;
  uint lastDeferredIndex;
  uint successorNumber;
  uint deferredCountSnapshot;
  uint operandFlags;
  uint pendingCountSnapshot;
  int successorOffset;
  int destRootB;
  int destKindClass;
  int laneCountdown;
  int operandNumber;
  int instQuery64;
  int destRootA;
  int srcRecord;
  int *newBitset;
  int *laneCursor;
  int *chainSource;
  int *firstUsableInst;
  int *nextInstInList;
  int *bitsetWordCursor;
  int *newCopyInst;
  int *deferredInst;
  int bitCount;
  int laneIndex;
  int srcRecordB;
  int srcRecordA;
  int destRoot;
  int blockIndex;
  int compiler;
  int bitsetBlock;
  undefined4 *allocation;
  undefined4 arena;
  uint *srcWordPtr;
  bool rootsDiffer;
  int roundCount;
  uint newBitCount;
  uint wordOffset;
  int blockArray;
  int *backend;
  int block;
  int rootOrQuery;
  int *srcDef;
  int *laneSourceDef;
  int srcKindFlag;
  int mergedRoot;
  int *instListHead;
  undefined4 *pendingSlotRef;
  uint instFlags;
  uint lastPendingIndex;
  uint clearStartBit;
  int changedFlag;
  bool needsFlagUpdate;
  int laneNumber;
  undefined4 pendingInst;
  int *prevInst;
  uint *operandFlagsCursor;
  undefined4 secondPass;
  int *inst;
  undefined4 laneMask;
  int *laneDefOut;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/uVar25) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_90_buf [0x10];
  #define vecCapacity (*(uint *)(local_90_buf + 0x00))
  #define vecCount (*(uint *)(local_90_buf + 0x04))
  #define vecData (*(int *)(local_90_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_90_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/uVar25) used with Vector__elementRefGrow - vec2Capacity/vec2Count/vec2Data/vec2Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_80_buf [0x10];
  #define vec2Capacity (*(uint *)(local_80_buf + 0x00))
  #define vec2Count (*(uint *)(local_80_buf + 0x04))
  #define vec2Data (*(int *)(local_80_buf + 0x08))
  #define vec2Arena (*(undefined4 *)(local_80_buf + 0x0c))
  undefined4 maskBuf;
  int swizzleWord;
  undefined4 newSwizzleWord;
  undefined4 maskTemp [6];
  
  vec2Arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vec2Count = 0;
  vec2Capacity = 2;
  vec2Data = Arena__alloc(vec2Arena,8);
  vecArena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  blockArray = FUN_000ee7a0(pass);
  roundCount = *(int *)(pass + 0x248);
  secondPass = 0;
  do {
    *(undefined4 *)(pass + 0x250) = 0;
    if (0 < roundCount) {
      ((int (*)())FUN_00135278)(copyState);
      ((int (*)())FUN_00134db0)(copyState);
      vecCount = 0;
    }
    compiler = *(int *)(pass + 8);
    *(int *)(compiler + 0x39c) = *(int *)(compiler + 0x39c) + 1;
    backend = *(int **)(*(int *)(pass + 8) + 0x30c);
    (**(code **)(*backend + 0x148))
              (backend,copyState,*(undefined4 *)(pass + 0x46c),*(undefined4 *)(pass + 0x464),
               secondPass,*(int *)(pass + 8),compiler);
    changedFlag = 0;
    for (blockIndex = 0; block = DList__count(pass + 0x37c), blockIndex < block; blockIndex = blockIndex + 1) {
      needsFlagUpdate = false;
      block = *(int *)(blockArray + blockIndex * 4);
      instListHead = *(int **)(block + 0x98);
      nextInstInList = (int *)instListHead[2];
      if (nextInstInList != (int *)0x0) {
        do {
          prevInst = instListHead;
          if (instListHead != (int *)0x0) {
            firstUsableInst = (int *)0x0;
            inst = instListHead;
            do {
              instFlags = inst[5];
              if ((instFlags & 1) == 0) goto LAB_001339e4;
              rootOrQuery = (**(code **)(*inst + 0x7c))(inst);
              if (rootOrQuery == 0) {
                if ((inst[5] & 0x10000U) == 0) {
                  if (firstUsableInst == (int *)0x0) {
                    firstUsableInst = inst;
                  }
                  if (needsFlagUpdate) {
                    needsFlagUpdate = false;
                    inst[5] = inst[5] | 0x1000;
                  }
                }
                if (((*(uint *)(*(int *)(*(int *)(pass + 8) + 0x30c) + 8) & 0x200) != 0) &&
                   (((((rootOrQuery = (**(code **)(*inst + 0x28))(inst), rootOrQuery != 0 ||
                       (rootOrQuery = (**(code **)(*inst + 0x68))(inst), rootOrQuery != 0)) &&
                      (srcDef = (int *)IRInst__getOperandSource(inst,1), srcDef[0x20] != 0)) &&
                     ((rootOrQuery = RegKind__flagBit0(srcDef[0x26]), rootOrQuery != 0 && ((srcDef[5] & 2U) == 0)))
                     ) && (rootOrQuery = (**(code **)(*srcDef + 0x50))(srcDef), rootOrQuery == 0)))) {
                  srcRecord = IRInst__getOperandRecord(inst,1);
                  SelectWord__readMask(&maskBuf,*(undefined4 *)(srcRecord + 0x10));
                  laneNumber = 0;
                  laneMask = maskBuf;
                  rootOrQuery = -1;
                  do {
                    mergedRoot = rootOrQuery;
                    if ((((*(char *)((int)&laneMask + laneNumber) != '\0') &&
                         (laneSourceDef = (int *)((int (*)())FUN_001382b8)(srcDef,laneNumber,&laneDefOut),
                         laneSourceDef != (int *)0x0)) &&
                        ((laneSourceDef[0x20] != 0 &&
                         (((srcKindFlag = RegKind__flagBit0(laneSourceDef[0x26]), srcKindFlag != 0 &&
                           ((laneSourceDef[5] & 2U) == 0)) &&
                          (srcKindFlag = (**(code **)(*laneSourceDef + 0x50))(laneSourceDef), srcKindFlag == 0)))))) &&
                       ((mergedRoot = ((int (*)())FUN_00134bf0)(copyState,laneSourceDef[0x25],changedFlag), pendingCountSnapshot = vecCount,
                        rootOrQuery != -1 && (rootsDiffer = rootOrQuery != mergedRoot, mergedRoot = rootOrQuery, rootsDiffer)))) {
                      if (vecCount < vecCapacity) {
                        rootOrQuery = vecCount * 4;
                        _memset(rootOrQuery + vecData,0,4);
                        vecCount = pendingCountSnapshot + 1;
                        pendingSlotRef = (undefined4 *)(rootOrQuery + vecData);
                      }
                      else {
                        pendingSlotRef = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
                      }
                      *pendingSlotRef = inst;
                      break;
                    }
                    rootsDiffer = laneNumber != 3;
                    laneNumber = laneNumber + 1;
                    rootOrQuery = mergedRoot;
                  } while (rootsDiffer);
                }
                if ((((inst[5] & 0x200U) != 0) &&
                    (srcDef = (int *)IRInst__getOperandSource(inst,inst[0x21]), (srcDef[5] & 1U) != 0))
                   && ((srcDef[0x20] != 0 &&
                       (((rootOrQuery = RegKind__flagBit0(srcDef[0x26]), rootOrQuery != 0 &&
                         ((srcDef[5] & 2U) == 0)) &&
                        (rootOrQuery = (**(code **)(*srcDef + 0x50))(srcDef), rootOrQuery == 0)))))) {
                  destRootA = ((int (*)())FUN_00134bf0)(copyState,inst[0x25],changedFlag);
                  laneNumber = ((int (*)())FUN_00134bf0)(copyState,srcDef[0x25],changedFlag);
                  if (destRootA != laneNumber) {
                    if (((inst[5] & 0x40U) == 0) || ((srcDef[5] & 0x40U) == 0)) {
                      if ((*(int *)(destRootA * 4 + *(int *)(pass + 0x45c)) ==
                           *(int *)(laneNumber * 4 + *(int *)(pass + 0x45c))) &&
                         (destRootA = ((int (*)())FUN_00135c20)(copyState,destRootA,laneNumber), destRootA != 0)) {
                        changedFlag = 1;
                        *(int *)(pass + 0x24c) = *(int *)(pass + 0x24c) + 1;
                      }
                      else {
                        *(int *)(pass + 0x250) = *(int *)(pass + 0x250) + 1;
                      }
                    }
                    else if ((*(uint *)(*(int *)(*(int *)(pass + 8) + 0x30c) + 8) & 0x200) == 0)
                    {
                      ((int (*)())FUN_001315f8)(copyState,inst,srcDef,pass + 0x464,instListHead,block);
                    }
                  }
                }
                instQuery64 = (**(code **)(*inst + 100))(inst);
                if (instQuery64 == 0) goto LAB_001339e0;
                operandFlagsCursor = (uint *)(inst + 0x2e);
                for (operandNumber = 1; laneNumber = (**(code **)(*inst + 0x14))(inst), operandNumber <= laneNumber;
                    operandNumber = operandNumber + 1) {
                  operandFlags = *operandFlagsCursor;
                  operandFlagsCursor = operandFlagsCursor + 6;
                  if ((((operandFlags & 1) != 0) || ((operandFlags & 2) != 0)) ||
                     (laneNumber = IRInst__isSourceSelectIdentity(inst,operandNumber), laneNumber == 0)) goto LAB_001339e0;
                }
                if ((inst[0x48] != 0) || (inst[0x49] != 0)) goto LAB_001339e0;
                if (((inst[0x20] != 0) &&
                    ((operandNumber = RegKind__flagBit0(inst[0x26]), operandNumber != 0 && ((inst[5] & 2U) == 0))))
                   && (operandNumber = (**(code **)(*inst + 0x50))(inst), operandNumber == 0)) {
                  laneCountdown = 4;
                  srcDef = inst;
                  do {
                    if ((uint)(*(byte *)(srcDef + 0x27) - 2) < 2) goto LAB_001339e0;
                    srcDef = (int *)((int)srcDef + 1);
                    laneCountdown = laneCountdown + -1;
                  } while (laneCountdown != 0);
                }
                IRInst__getOperandRecord(inst,0);
                destKindClass = IRInst__operandKindClass(inst,0);
                if (destKindClass != 0) goto LAB_001339e0;
                instFlags = inst[5];
                if ((((instFlags & 2) == 0) && ((instFlags & 0x200) == 0)) && (-1 < (int)instFlags)) {
                  srcDef = (int *)IRInst__getOperandSource(inst,1);
                  if (((srcDef[0x20] != 0) && (destKindClass = RegKind__flagBit0(srcDef[0x26]), destKindClass != 0)) &&
                     (((srcDef[5] & 2U) == 0 &&
                      (destKindClass = (**(code **)(*srcDef + 0x50))(srcDef), destKindClass == 0)))) {
                    destRootB = ((int (*)())FUN_00134bf0)(copyState,inst[0x25],changedFlag);
                    laneNumber = ((int (*)())FUN_00134bf0)(copyState,srcDef[0x25],changedFlag);
                    if (((0 < *(int *)(*(int *)(pass + 8) + 0x678)) &&
                        (*(int *)(destRootB * 4 + *(int *)(pass + 0x45c)) ==
                         *(int *)(laneNumber * 4 + *(int *)(pass + 0x45c)))) &&
                       (mergedRoot = ((int (*)())FUN_00135c20)(copyState,destRootB,laneNumber), deferredCountSnapshot = vec2Count, mergedRoot != 0)
                       ) {
                      *(int *)(pass + 0x254) = *(int *)(pass + 0x254) + 1;
                      if ((inst[5] & 0x1000U) != 0) {
                        if ((firstUsableInst == (int *)0x0) || (firstUsableInst == inst)) {
                          needsFlagUpdate = true;
                        }
                        else {
                          firstUsableInst[5] = firstUsableInst[5] | 0x1000;
                        }
                      }
                      if (((*(uint *)(*(int *)(*(int *)(pass + 8) + 0x30c) + 8) & 0x200) == 0) ||
                         ((inst[5] & 0x40000000U) == 0)) {
                        (**(code **)(*inst + 0xc))(inst,0);
                        instFlags = inst[5];
                        changedFlag = 1;
                      }
                      else {
                        if (vec2Count < vec2Capacity) {
                          deferredByteOffset = vec2Count * 4;
                          _memset(deferredByteOffset + vec2Data,0,4);
                          vec2Count = deferredCountSnapshot + 1;
                          deferredSlotRef = (undefined4 *)(deferredByteOffset + vec2Data);
                        }
                        else {
                          deferredSlotRef = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
                        }
                        *deferredSlotRef = inst;
                        changedFlag = 1;
                        instFlags = inst[5] | 0x80000000;
                        inst[5] = instFlags;
                      }
                      goto LAB_001339e4;
                    }
                    if ((*(int *)(pass + 0x46c) <= destRootB) &&
                       (*(int *)(destRootB * 4 + *(int *)(pass + 0x45c)) ==
                        *(int *)(laneNumber * 4 + *(int *)(pass + 0x45c)))) {
                      ((int (*)())FUN_00135684)(copyState,destRootB,laneNumber);
                    }
                  }
                  goto LAB_001339e0;
                }
              }
              else {
LAB_001339e0:
                instFlags = inst[5];
              }
LAB_001339e4:
              inst = (int *)inst[2];
            } while ((inst != (int *)0x0) && ((instFlags & 4) != 0));
            nextInstInList = (int *)instListHead[2];
          }
          do {
            instListHead = nextInstInList;
            prevFlagsPtr = (uint *)(prevInst + 5);
            nextInstInList = (int *)instListHead[2];
            if (nextInstInList == (int *)0x0) {
              if (needsFlagUpdate) {
                successorOffset = 0;
                laneDefOut = (int *)0x0;
                for (successorNumber = 1; successorNumber <= *(uint *)(*(int *)(block + 0xd0) + 4);
                    successorNumber = successorNumber + 1) {
                  laneDefOut = *(int **)(successorOffset + *(int *)(*(int *)(block + 0xd0) + 8));
                  if (laneDefOut != (int *)0x0) {
                    blockQuery30 = (**(code **)(*laneDefOut + 0x30))(laneDefOut);
                    if (blockQuery30 == 0) {
                      laneDefOut[0x37] = 1;
                    }
                    else {
                      *(undefined4 *)(laneDefOut[0x4b] + 0xdc) = 1;
                    }
                  }
                  successorOffset = successorOffset + 4;
                }
              }
              goto LAB_00133348;
            }
            prevInst = instListHead;
          } while ((*prevFlagsPtr & 4) != 0);
        } while( true );
      }
LAB_00133348: ;
    }
    roundCount = *(int *)(pass + 0x248) + 1;
    *(int *)(pass + 0x248) = roundCount;
    if (changedFlag == 0) {
      compilerAgain = *(int *)(pass + 8);
      needsFlagUpdate = false;
      goto LAB_00133af8;
    }
    registerIndex = 0;
    if (0 < *(int *)(pass + 0x464)) {
      do {
        ((int (*)())FUN_00134bf0)(copyState,registerIndex,1);
        registerIndex = registerIndex + 1;
      } while (registerIndex < *(int *)(pass + 0x464));
      roundCount = *(int *)(pass + 0x248);
    }
    compilerAgain = *(int *)(pass + 8);
    if (*(int *)(compilerAgain + 0x678) <= roundCount) break;
    secondPass = 1;
  } while( true );
  needsFlagUpdate = true;
LAB_00133af8:
  *(undefined4 *)(pass + 0x34) = 5;
  if ((*(uint *)(*(int *)(compilerAgain + 0x30c) + 8) & 0x200) != 0) {
LAB_00133bf0:
    if (vec2Count != 0) {
      lastDeferredIndex = vec2Count - 1;
      deferredTopRef = (undefined4 *)0x0;
      if (lastDeferredIndex < vec2Count) {
        deferredTopRef = (undefined4 *)(lastDeferredIndex * 4 + vec2Data);
      }
      deferredInst = (int *)*deferredTopRef;
      Vector__removeAt(&vec2Capacity,lastDeferredIndex);
      destRoot = ((int (*)())FUN_00134bf0)(copyState,deferredInst[0x25],0);
      chainSource = (int *)IRInst__getOperandSource(deferredInst,1);
      do {
        blockArray = (**(code **)(*chainSource + 0x50))(chainSource);
        if (blockArray != 0) {
LAB_00133bd0:
          (**(code **)(*deferredInst + 0xc))(deferredInst,0,*(undefined4 *)(pass + 8));
          break;
        }
        blockArray = ((int (*)())FUN_00134bf0)(copyState,chainSource[0x25],0);
        if ((chainSource[5] & 0x200U) == 0) {
          if (destRoot == blockArray) goto LAB_00133bd0;
          break;
        }
        chainSource = (int *)IRInst__getOperandSource(chainSource,chainSource[0x21]);
      } while (destRoot == blockArray);
      goto LAB_00133bf0;
    }
    if (vecCount != 0) {
      ((int (*)())FUN_00137694)(copyState,vecCount);
      pendingCount = vecCount;
      while (vecCount != 0) {
        lastPendingIndex = vecCount - 1;
        pendingTopRef = (undefined4 *)0x0;
        if (lastPendingIndex < vecCount) {
          pendingTopRef = (undefined4 *)(lastPendingIndex * 4 + vecData);
        }
        pendingInst = *pendingTopRef;
        Vector__removeAt(&vecCapacity,lastPendingIndex);
        *(int *)(pass + 600) = *(int *)(pass + 600) + 1;
        pendingSrcDef = IRInst__getOperandSource(pendingInst,1);
        newCopyInst = (int *)FUN_00130c8c(copyState,pendingInst,pendingSrcDef,pass + 0x464);
        srcRecordA = IRInst__getOperandRecord(pendingInst,1);
        FUN_000f366c(&swizzleWord,*(undefined4 *)(srcRecordA + 0x10));
        newCopyInst[0x27] = swizzleWord;
        FUN_000f370c(&newSwizzleWord,swizzleWord);
        newSwizzle = newSwizzleWord;
        srcRecordB = IRInst__getOperandRecord(newCopyInst,1);
        *(undefined4 *)(srcRecordB + 0x10) = newSwizzle;
        SelectWord__readMask(maskTemp,newSwizzle);
        laneMask = maskTemp[0];
        newSrcDef = IRInst__getOperandSource(newCopyInst,1);
        laneIndex = 0;
        laneCursor = newCopyInst;
        do {
          if ((*(char *)((int)&laneMask + laneIndex) != '\0') &&
             (blockArray = ((int (*)())FUN_001382b8)(newSrcDef,laneIndex,&laneDefOut), blockArray == 0)) {
            *(undefined1 *)(laneCursor + 0x27) = 1;
            (**(code **)(*newCopyInst + 0x88))(newCopyInst,1,laneIndex,4);
          }
          notLastLane = laneIndex != 3;
          laneCursor = (int *)((int)laneCursor + 1);
          laneIndex = laneIndex + 1;
        } while (notLastLane);
        IRInst__setOperandSource(pendingInst,1,newCopyInst,0,*(undefined4 *)(pass + 8));
      }
      backend = *(int **)(*(int *)(pass + 8) + 0x30c);
      (**(code **)(*backend + 0x14c))(backend,pass);
      bitsetBlock = *(int *)(pass + 900);
      bitCount = *(int *)(pass + 0x464) * 4;
      if (*(int *)(bitsetBlock + 8) != 0) {
        bitsetWordCount = bitCount + 0x1fU >> 5;
        do {
          bitsetData = *(uint **)(bitsetBlock + 0x104);
          newBitCount = pendingCount * 4 + bitsetData[1];
          if (newBitCount + 0x1f >> 5 == *bitsetData) {
            clearStartBit = newBitCount + pendingCount * -4;
            bitsetData[1] = newBitCount;
            if (clearStartBit < newBitCount) {
              bitsToClear = newBitCount - clearStartBit;
              if (newBitCount < clearStartBit + 1) {
                bitsToClear = 1;
              }
              do {
                wordOffset = clearStartBit >> 3 & 0x1ffffffc;
                bitInWord = clearStartBit & 0x1f;
                clearStartBit = clearStartBit + 1;
                *(uint *)((int)bitsetData + wordOffset + 8) =
                     *(uint *)((int)bitsetData + wordOffset + 8) & ~(1 << bitInWord);
                bitsToClear = bitsToClear + -1;
              } while (bitsToClear != 0);
            }
          }
          else {
            arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
            allocation = (undefined4 *)Arena__alloc(arena,bitsetWordCount * 4 + 0xc);
            newBitset = allocation + 1;
            *allocation = arena;
            allocation[1] = bitsetWordCount;
            allocation[2] = bitCount;
            if (bitsetWordCount != 0) {
              wordsLeft = bitsetWordCount;
              bitsetWordCursor = newBitset;
              if (bitsetWordCount == 0) {
                wordsLeft = 1;
              }
              do {
                wordsLeft = wordsLeft - 1;
                bitsetWordCursor[2] = 0;
                bitsetWordCursor = bitsetWordCursor + 1;
              } while (wordsLeft != 0);
            }
            *(int **)(bitsetBlock + 0x104) = newBitset;
            bitsetWordsLeft = *newBitset;
            if (bitsetWordsLeft != 0) {
              if (bitsetWordsLeft == 0) {
                bitsetWordsLeft = 1;
              }
              do {
                bitsetWordsLeft = bitsetWordsLeft + -1;
                srcWordPtr = bitsetData + 2;
                bitsetData = bitsetData + 1;
                newBitset[2] = newBitset[2] | *srcWordPtr;
                newBitset = newBitset + 1;
              } while (bitsetWordsLeft != 0);
            }
          }
          bitsetBlock = *(int *)(bitsetBlock + 8);
        } while (*(int *)(bitsetBlock + 8) != 0);
      }
      ((int (*)())FUN_00135278)(copyState);
      ((int (*)())FUN_00134db0)(copyState);
      backend = *(int **)(*(int *)(pass + 8) + 0x30c);
      (**(code **)(*backend + 0x148))
                (backend,copyState,*(undefined4 *)(pass + 0x46c),*(undefined4 *)(pass + 0x464),1,
                 *(int *)(pass + 8));
    }
  }
  if (needsFlagUpdate) {
    ((int (*)())FUN_00135278)(copyState);
    ((int (*)())FUN_00134db0)(copyState);
    backend = *(int **)(*(int *)(pass + 8) + 0x30c);
    (**(code **)(*backend + 0x148))
              (backend,copyState,*(undefined4 *)(pass + 0x46c),*(undefined4 *)(pass + 0x464),0,
               *(int *)(pass + 8));
  }
  Arena__free(vecArena,vecData);
  return Arena__free(vec2Arena,vec2Data);
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena
#undef vec2Capacity
#undef vec2Count
#undef vec2Data
#undef vec2Arena

/* FUN_00133fe4 @ 0x133fe4 (140 bytes) */
int FUN_00133fe4(allocator)
  int allocator;
{
  int *foundPendingRef;
  undefined4 reloadModeA;
  undefined4 reloadModeB;
  undefined4 spillAddress;
  undefined4 spillSlotB;
  int *nextInstLink;
  int reloadSource;
  int pendingInst;
  int pendingCount;
  int instQuery78;
  int spillTempCount;
  undefined4 vectorData;
  undefined4 arena;
  int operandRecord;
  int *operandVReg;
  int loopIndex;
  undefined4 spillState;
  undefined4 *allocation;
  int regKindFlag;
  undefined4 *pendingSlotRef;
  undefined4 spillLocationA;
  undefined4 spillModeA;
  int nextBlock;
  uint loopIndex2;
  int *nextInstB;
  int program;
  uint *puVar11;
  int block;
  undefined4 operandSwizzle;
  uint pendingCountB;
  int sourceRegister;
  int *pendingElemRef;
  undefined4 insertedReload;
  int *inst;
  uint searchRemaining;
  
  program = *(int *)(*(int *)(allocator + 0x2c) + 0x6c4);
  spillState = ((int (*)())FUN_00131c10)(program);
  arena = *(undefined4 *)(*(int *)(allocator + 0x2c) + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  puVar11 = allocation + 1;
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  insertedReload = 0;
  block = *(int *)(program + 900);
  nextBlock = *(int *)(*(int *)(program + 900) + 8);
  do {
    if (nextBlock == 0) {
      pendingCount = allocation[2];
      if (0 < pendingCount) {
        insertedReload = 1;
      }
      if (pendingCount == 0) {
        spillTempCount = *(int *)(program + 0x454);
      }
      else {
        do {
          pendingElemRef = (int *)0x0;
          if (pendingCount - 1U < (uint)allocation[2]) {
            pendingElemRef = (int *)((pendingCount - 1U) * 4 + allocation[3]);
          }
          pendingInst = *pendingElemRef;
          Vector__removeAt(puVar11,allocation[2] - 1);
          spillLocationA = FUN_001308e0(pendingInst);
          FUN_00130abc(spillLocationA,allocator,*(undefined4 *)(allocator + 0x2c));
          spillSlotB = ((int (*)())FUN_001318a4)(allocator,*(undefined4 *)(pendingInst + 0x94),spillState);
          spillModeA = thunk_FUN_001307f8(pendingInst);
          FUN_001312f4(pendingInst,spillState,spillSlotB,spillModeA,*(undefined4 *)(allocator + 0x2c));
          spillTempCount = *(int *)(program + 0x454) + 1;
          *(int *)(program + 0x454) = spillTempCount;
          pendingCount = allocation[2];
        } while (pendingCount != 0);
      }
      ((int (*)())FUN_00131c74)(program,spillState,spillTempCount << 2);
      return insertedReload;
    }
    nextInstLink = (int *)(*(int **)(block + 0x98))[2];
    inst = *(int **)(block + 0x98);
    if (nextInstLink != (int *)0x0) {
      do {
        nextInstB = nextInstLink;
        if (((inst[5] & 1U) != 0) && (*(int *)(inst[0x22] + 8) != 0x8e)) {
          instQuery78 = (**(code **)(*inst + 0x78))(inst);
          if ((instQuery78 == 0) && (0 < inst[0x21])) {
            loopIndex = 1;
            do {
              operandVReg = (int *)IRInst__getOperandSource(inst,loopIndex);
              if ((((operandVReg[0x20] != 0) && (regKindFlag = RegKind__flagBit0(operandVReg[0x26]), regKindFlag != 0)) &&
                  ((operandVReg[5] & 2U) == 0)) &&
                 (regKindFlag = (**(code **)(*operandVReg + 0x50))(operandVReg), regKindFlag == 0)) {
                sourceRegister = operandVReg[0x25];
                regKindFlag = FUN_001309bc(allocator,sourceRegister);
                if (regKindFlag != 0) {
                  regKindFlag = *inst;
                  operandVReg[5] = operandVReg[5] | 0x8000000;
                  regKindFlag = (**(code **)(regKindFlag + 0x14))(inst);
                  if ((loopIndex <= regKindFlag) && (regKindFlag = FUN_00131008(1,inst,loopIndex), regKindFlag != 0)) {
                    FUN_00130abc(inst,allocator,*(undefined4 *)(allocator + 0x2c));
                    if (((operandVReg[5] & 0x20000000U) == 0) || ((operandVReg[6] & 1U) != 0)) {
                      regKindFlag = ((int (*)())FUN_001318a4)(allocator,sourceRegister,spillState);
                      reloadSource = FUN_00130a08(inst,*(undefined4 *)(regKindFlag + 0x13c));
                      if (reloadSource == 0) {
                        spillAddress = FUN_00130424(allocator);
                        operandRecord = IRInst__getOperandRecord(inst,loopIndex);
                        operandSwizzle = *(undefined4 *)(operandRecord + 0x10);
                        reloadModeA = FUN_00130904(inst);
                        reloadSource = FUN_001311cc(spillAddress,operandSwizzle,spillState,regKindFlag,reloadModeA,
                                              *(undefined4 *)(allocator + 0x2c));
                      }
                      IRInst__setOperandSource(inst,loopIndex,reloadSource,0,*(undefined4 *)(allocator + 0x2c));
                      pendingCountB = allocation[2];
                      if (0 < (int)pendingCountB) {
                        loopIndex2 = 0;
                        searchRemaining = pendingCountB;
                        do {
                          foundPendingRef = (int *)0x0;
                          if (loopIndex2 < pendingCountB) {
                            foundPendingRef = (int *)(loopIndex2 * 4 + allocation[3]);
                          }
                          if (operandVReg == (int *)*foundPendingRef) goto code_r0x001342f8;
                          loopIndex2 = loopIndex2 + 1;
                          searchRemaining = searchRemaining - 1;
                        } while (searchRemaining != 0);
                      }
                      if (pendingCountB < *puVar11) {
                        _memset((void *)(pendingCountB * 4 + allocation[3]),0,4);
                        allocation[2] = pendingCountB + 1;
                        pendingSlotRef = (undefined4 *)(pendingCountB * 4 + allocation[3]);
                      }
                      else {
                        pendingSlotRef = (undefined4 *)Vector__elementRefGrow(puVar11,pendingCountB);
                      }
                      *pendingSlotRef = operandVReg;
                    }
                    else {
                      insertedReload = 1;
                      reloadModeB = FUN_00130904(inst);
                      FUN_00130da0(allocator,inst,loopIndex,reloadModeB,*(undefined4 *)(allocator + 0x2c));
                    }
                  }
                }
              }
code_r0x001342f8:
              loopIndex = loopIndex + 1;
            } while (loopIndex <= inst[0x21]);
          }
          nextInstB = (int *)inst[2];
        }
        nextInstLink = (int *)nextInstB[2];
        inst = nextInstB;
      } while ((int *)nextInstB[2] != (int *)0x0);
      nextBlock = *(int *)(block + 8);
    }
    block = nextBlock;
    nextBlock = *(int *)(nextBlock + 8);
  } while( true );
}

/* FUN_00134400 @ 0x134400 (600 bytes) */
int FUN_00134400(allocator)
  int allocator;
{
  uint *nodeVectorB;
  int *nodeRefA;
  uint nodeVectorCountB;
  int instQuery50;
  int regKindFlag;
  int hasDestination;
  uint destRegisterB;
  uint destRegisterA;
  int *inst;
  int *nextInstLink;
  uint instFlags;
  int nextBlock;
  uint nodeVectorCountA;
  int *nextInstLinkB;
  undefined4 *nodeRefB;
  int block;
  uint *nodeVectorA;
  int *listHead;
  
  block = *(int *)(*(int *)(*(int *)(allocator + 0x2c) + 0x6c4) + 900);
  nextBlock = *(int *)(block + 8);
  do {
    if (nextBlock == 0) {
      return;
    }
    nextInstLink = (int *)(*(int **)(block + 0xa0))[1];
    listHead = *(int **)(block + 0xa0);
    if (nextInstLink != (int *)0x0) {
      do {
        nextInstLinkB = nextInstLink;
        if (((listHead == *(int **)(block + 0x98)) || ((nextInstLinkB[5] & 4U) == 0)) &&
           (inst = listHead, listHead != (int *)0x0)) {
          do {
            instFlags = inst[5];
            if ((instFlags & 1) != 0) {
              hasDestination = 0;
              if (inst[0x20] != 0) {
                regKindFlag = RegKind__flagBit0(inst[0x26]);
                if (((regKindFlag == 0) || ((inst[5] & 2U) != 0)) ||
                   ((regKindFlag = (**(code **)(*inst + 0x50))(inst), regKindFlag != 0 ||
                    ((inst[5] & 0x8000000U) == 0)))) {
                  hasDestination = inst[0x20];
                }
                else {
                  nodeVectorA = *(uint **)(allocator + 4);
                  destRegisterA = inst[0x25];
                  if (destRegisterA < *nodeVectorA) {
                    nodeVectorCountA = nodeVectorA[1];
                    if (nodeVectorCountA <= destRegisterA) {
                      _memset(nodeVectorCountA * 4 + nodeVectorA[2],0,(destRegisterA - nodeVectorCountA) * 4 + 4);
                      nodeVectorA[1] = destRegisterA + 1;
                    }
                    nodeRefA = (int *)(destRegisterA * 4 + nodeVectorA[2]);
                  }
                  else {
                    nodeRefA = (int *)Vector__elementRefGrow(nodeVectorA,destRegisterA);
                  }
                  *(undefined4 *)(*nodeRefA + 0x18) = 1;
                  hasDestination = inst[0x20];
                }
              }
              if ((hasDestination == 0) || (hasDestination = RegKind__flagBit0(inst[0x26]), hasDestination == 0)) {
LAB_001345fc:
                instFlags = inst[5];
              }
              else {
                instFlags = inst[5];
                if ((instFlags & 2) == 0) {
                  instQuery50 = (**(code **)(*inst + 0x50))(inst);
                  if (instQuery50 != 0) goto LAB_001345fc;
                  nodeVectorB = *(uint **)(allocator + 4);
                  destRegisterB = inst[0x25];
                  if (destRegisterB < *nodeVectorB) {
                    nodeVectorCountB = nodeVectorB[1];
                    if (nodeVectorCountB <= destRegisterB) {
                      _memset(nodeVectorCountB * 4 + nodeVectorB[2],0,(destRegisterB - nodeVectorCountB) * 4 + 4);
                      nodeVectorB[1] = destRegisterB + 1;
                    }
                    nodeRefB = (undefined4 *)(destRegisterB * 4 + nodeVectorB[2]);
                  }
                  else {
                    nodeRefB = (undefined4 *)Vector__elementRefGrow(nodeVectorB,destRegisterB);
                  }
                  ((int (*)())FUN_00134aa8)(*nodeRefB,inst[0x1f]);
                  instFlags = inst[5];
                }
              }
            }
          } while (((int *)inst[2] != (int *)0x0) && (inst = (int *)inst[2], (instFlags & 4) != 0)
                  );
          nextInstLinkB = (int *)listHead[1];
        }
        nextInstLink = (int *)nextInstLinkB[1];
        listHead = nextInstLinkB;
      } while ((int *)nextInstLinkB[1] != (int *)0x0);
      nextBlock = *(int *)(block + 8);
    }
    block = nextBlock;
    nextBlock = *(int *)(nextBlock + 8);
  } while( true );
}

/* FUN_00134658 @ 0x134658 (612 bytes) */
int FUN_00134658(pass)
  int pass;
{
  uint copyCountB;
  int *usageBitsetBData;
  int *usageBitsetAData;
  int *backendB;
  int spilledBitset;
  int usageBitsetACursor;
  int allocatorObj;
  int restoreWordCountB;
  int restoreWordCountA;
  int compilerB;
  int spilledBitCount;
  int bitsetByteSize;
  uint *savedBitsetARestoreCursor;
  uint *savedBitsetBCursor;
  uint *savedBitsetB;
  uint *restoreSrcWordB;
  uint *restoreSrcWordA;
  int allocationRound;
  int usageBitsetBSrc;
  int pass_color_graphResult;
  uint loopIndex;
  uint *usageBitsetBSrcWord;
  uint *savedBitsetACursor;
  uint *usageBitsetASrcWord;
  int physicalRegCountA;
  int physicalRegCountB;
  undefined4 *allocation;
  int loopIndex2;
  uint *savedBitsetA;
  int compiler;
  int *backend;
  undefined4 arena;
  uint clearCountA;
  uint copyCountA;
  uint bitsetWordCount;
  
  FUN_001314b8(pass);
  compiler = *(int *)(pass + 8);
  if (*(int *)(compiler + 0x3c4) == -1) {
    return;
  }
  *(undefined4 *)(pass + 0x454) = 0;
  *(undefined4 *)(pass + 0x438) = 0;
  *(uint *)(pass + 0x30) = *(uint *)(pass + 0x30) | 0x400;
  backend = *(int **)(compiler + 0x30c);
  physicalRegCountA = (**(code **)(*backend + 0x138))(backend,compiler);
  physicalRegCountB = (**(code **)(*backend + 0x140))(backend,compiler);
  compiler = (**(code **)(*backend + 0x13c))(backend,compiler);
  compiler = physicalRegCountA + physicalRegCountB + compiler;
  arena = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
  bitsetWordCount = compiler + 0x1fU >> 5;
  bitsetByteSize = bitsetWordCount * 4 + 0xc;
  allocation = (undefined4 *)Arena__alloc(arena,bitsetByteSize);
  savedBitsetA = allocation + 1;
  *allocation = arena;
  allocation[1] = bitsetWordCount;
  allocation[2] = compiler;
  if (bitsetWordCount == 0) {
    copyCountA = *savedBitsetA;
  }
  else {
    savedBitsetACursor = savedBitsetA;
    clearCountA = bitsetWordCount;
    if (bitsetWordCount == 0) {
      clearCountA = 1;
    }
    do {
      savedBitsetACursor[2] = 0;
      savedBitsetACursor = savedBitsetACursor + 1;
      clearCountA = clearCountA - 1;
      copyCountA = bitsetWordCount;
    } while (clearCountA != 0);
  }
  usageBitsetACursor = *(int *)(pass + 0x42c);
  if (copyCountA != 0) {
    savedBitsetACursor = savedBitsetA;
    if (copyCountA == 0) {
      copyCountA = 1;
    }
    do {
      usageBitsetASrcWord = (uint *)(usageBitsetACursor + 8);
      usageBitsetACursor = usageBitsetACursor + 4;
      savedBitsetACursor[2] = *usageBitsetASrcWord;
      savedBitsetACursor = savedBitsetACursor + 1;
      copyCountA = copyCountA - 1;
    } while (copyCountA != 0);
  }
  arena = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,bitsetByteSize);
  savedBitsetB = allocation + 1;
  *allocation = arena;
  allocation[1] = bitsetWordCount;
  allocation[2] = compiler;
  if (bitsetWordCount == 0) {
    bitsetWordCount = *savedBitsetB;
  }
  else {
    savedBitsetBCursor = savedBitsetB;
    copyCountB = bitsetWordCount;
    if (bitsetWordCount == 0) {
      copyCountB = 1;
    }
    do {
      savedBitsetBCursor[2] = 0;
      savedBitsetBCursor = savedBitsetBCursor + 1;
      copyCountB = copyCountB - 1;
    } while (copyCountB != 0);
  }
  usageBitsetBSrc = *(int *)(pass + 0x430);
  if (bitsetWordCount != 0) {
    savedBitsetBCursor = savedBitsetB;
    if (bitsetWordCount == 0) {
      bitsetWordCount = 1;
    }
    do {
      usageBitsetBSrcWord = (uint *)(usageBitsetBSrc + 8);
      usageBitsetBSrc = usageBitsetBSrc + 4;
      savedBitsetBCursor[2] = *usageBitsetBSrcWord;
      savedBitsetBCursor = savedBitsetBCursor + 1;
      bitsetWordCount = bitsetWordCount - 1;
    } while (bitsetWordCount != 0);
  }
  allocationRound = 0;
  do {
    arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x34);
    *allocation = arena;
    ((int (*)())FUN_0013719c)(allocation + 1,*(undefined4 *)(pass + 0x46c),*(undefined4 *)(pass + 0x464),
                 pass,*(undefined4 *)(pass + 8));
    *(undefined4 **)(pass + 0x3c0) = allocation + 1;
    ((int (*)())FUN_00131d08)(pass,*(undefined4 *)(pass + 0x468),*(undefined4 *)(pass + 0x46c),
                 *(undefined4 *)(pass + 0x464),allocationRound);
    if (allocationRound != 0) {
      ((int (*)())FUN_00134400)(*(undefined4 *)(pass + 0x3c0));
    }
    backendB = *(int **)(*(int *)(pass + 8) + 0x30c);
    (**(code **)(*backendB + 0x144))(backendB,*(undefined4 *)(pass + 0x464),pass);
    ((int (*)())FUN_0013323c)(pass,*(undefined4 *)(pass + 0x3c0));
    ((int (*)())FUN_00138080)(pass);
    if (allocationRound != 0) {
      ((int (*)())FUN_001378e8)(*(undefined4 *)(pass + 0x3c0),*(undefined4 *)(pass + 8));
    }
    pass_color_graphResult = ((int (*)())pass_color_graph)(*(undefined4 *)(pass + 0x3c0));
    if (pass_color_graphResult != 0) {
      spilledBitset = *(int *)(*(int *)(pass + 0x3c0) + 0x24);
      spilledBitCount = *(int *)(spilledBitset + 4);
      if (spilledBitCount == 0) {
code_r0x001348ac:
        compilerB = *(int *)(pass + 8);
      }
      else {
        loopIndex = 0;
        loopIndex2 = 0;
        do {
          if ((*(uint *)((loopIndex >> 3 & 0x1ffffffc) + spilledBitset + 8) >> (loopIndex & 0x1f) & 1) != 0) {
            loopIndex2 = loopIndex2 + 1;
          }
          loopIndex = loopIndex + 1;
          spilledBitCount = spilledBitCount + -1;
        } while (spilledBitCount != 0);
        if (loopIndex2 == 0) goto code_r0x001348ac;
        compilerB = *(int *)(pass + 8);
        if (*(int *)(pass + 0x264) < *(int *)(compilerB + 0x67c)) {
          *(int *)(pass + 0x264) = *(int *)(pass + 0x264) + 1;
          ((int (*)())FUN_00133fe4)(*(int *)(pass + 0x3c0));
          backendB = *(int **)(*(int *)(pass + 8) + 0x30c);
          (**(code **)(*backendB + 0x14c))(backendB,pass);
          usageBitsetAData = *(int **)(pass + 0x42c);
          restoreWordCountA = *usageBitsetAData;
          if (restoreWordCountA != 0) {
            savedBitsetARestoreCursor = savedBitsetA;
            if (restoreWordCountA == 0) {
              restoreWordCountA = 1;
            }
            do {
              restoreSrcWordA = savedBitsetARestoreCursor + 2;
              savedBitsetARestoreCursor = savedBitsetARestoreCursor + 1;
              usageBitsetAData[2] = *restoreSrcWordA;
              usageBitsetAData = usageBitsetAData + 1;
              restoreWordCountA = restoreWordCountA + -1;
            } while (restoreWordCountA != 0);
          }
          usageBitsetBData = *(int **)(pass + 0x430);
          restoreWordCountB = *usageBitsetBData;
          if (restoreWordCountB != 0) {
            savedBitsetBCursor = savedBitsetB;
            if (restoreWordCountB == 0) {
              restoreWordCountB = 1;
            }
            do {
              restoreSrcWordB = savedBitsetBCursor + 2;
              savedBitsetBCursor = savedBitsetBCursor + 1;
              usageBitsetBData[2] = *restoreSrcWordB;
              usageBitsetBData = usageBitsetBData + 1;
              restoreWordCountB = restoreWordCountB + -1;
            } while (restoreWordCountB != 0);
          }
          FUN_001314b8(pass);
          goto LAB_00134a58;
        }
      }
      Compiler__fail(compilerB,4);
    }
LAB_00134a58:
    allocatorObj = *(int *)(pass + 0x3c0);
    if (allocatorObj != 0) {
      ((int (*)())FUN_001357d4)(allocatorObj);
      Arena__free(*(undefined4 *)(allocatorObj + -4),allocatorObj + -4);
    }
    if (pass_color_graphResult == 0) {
      *(undefined4 *)(pass + 0x34) = 6;
      return;
    }
    allocationRound = 1;
  } while( true );
}

/* FUN_00134aa8 @ 0x134aa8 (8 bytes) */
int FUN_00134aa8(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}

/* FUN_00134ab0 @ 0x134ab0 (8 bytes) */
int FUN_00134ab0(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x14);
}

/* FUN_00134ab8 @ 0x134ab8 (100 bytes) */
int FUN_00134ab8(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    *param_3 = 0;
    *param_2 = 6;
    return;
  }
  *param_2 = 0;
  *param_3 = *(int *)(param_1 + 8);
  while( true ) {
    iVar1 = *param_2 + 7;
    if (*(int *)(param_1 + 4) <= iVar1) break;
    *param_2 = iVar1;
    *param_3 = *(int *)(*param_3 + 0x1c);
  }
  *param_2 = (*(int *)(param_1 + 4) - *param_2) + -1;
  return;
}

/* pairIndex @ 0x134b1c (60 bytes) */
int pairIndex(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_3;
  if (param_2 < param_3) {
    iVar1 = param_2;
  }
  if (param_3 < param_2) {
    param_3 = param_2;
  }
  uVar2 = param_3 * (param_3 + -1);
  return iVar1 + ((int)uVar2 >> 1) + (uint)((int)uVar2 < 0 && (uVar2 & 1) != 0);
}

/* InterferenceMatrix__setPair @ 0x134b58 (76 bytes) */
int InterferenceMatrix__setPair(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  uVar1 = ((int (*)())pairIndex)(param_1,param_2,param_3);
  iVar2 = (uVar1 >> 3 & 0x1ffffffc) + iVar2;
  *(uint *)(iVar2 + 8) = 1 << (uVar1 & 0x1f) | *(uint *)(iVar2 + 8);
  return;
}

/* InterferenceMatrix__testPair @ 0x134ba4 (76 bytes) */
int InterferenceMatrix__testPair(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint uVar1;
  
  uVar1 = ((int (*)())pairIndex)(param_1,param_2,param_3);
  return *(uint *)((uVar1 >> 3 & 0x1ffffffc) + *param_1 + 8) >> (uVar1 & 0x1f) & 1;
}

/* FUN_00134bf0 @ 0x134bf0 (40 bytes) */
int FUN_00134bf0(param_1, element, param_3)
  int param_1;
  int element;
  int param_3;
{
  undefined4 callResult;
  
  if (param_3 != 0) {
    callResult = disjointSetFindRoot(element,*(undefined4 *)(param_1 + 0x20));
    return callResult;
  }
  return *(undefined4 *)(element * 4 + *(int *)(param_1 + 0x20));
}

/* FUN_00134c18 @ 0x134c18 (188 bytes) */
int FUN_00134c18(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  bool bVar1;
  int callResult;
  int loopIndex;
  int iVar4;
  
  loopIndex = 0;
  iVar4 = *(int *)(param_1 + 8);
  do {
    callResult = ((int (*)())FUN_00134bf0)(param_3,*(undefined4 *)(loopIndex * 4 + iVar4),1);
    if (callResult == param_2) {
      *(undefined4 *)(loopIndex * 4 + iVar4) = *(undefined4 *)(iVar4 + *(int *)(param_1 + 4) * 4);
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
    }
    else if ((*(int *)(param_1 + 4) == (*(int *)(param_1 + 4) / 7) * 7) &&
            (*(int *)(iVar4 + 0x1c) != 0)) {
      iVar4 = *(int *)(iVar4 + 0x1c);
    }
    bVar1 = loopIndex != 6;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  return;
}

/* FUN_00134cd4 @ 0x134cd4 (20 bytes) */
int FUN_00134cd4(param_1, value, elementIndex)
  int param_1;
  undefined4 value;
  undefined4 elementIndex;
{
  return storeIndexedWord(value,elementIndex,*(undefined4 *)(param_1 + 0x20));
}

/* ColorGraph__countSameClassNeighbors @ 0x134ce8 (200 bytes) */
int ColorGraph__countSameClassNeighbors(nodeRecord, node, classArray, graph)
  int nodeRecord;
  int node;
  int classArray;
  int graph;
{
  int signBits;
  int remaining;
  int sameClassCount;
  int loopIndex;
  int chunk;
  
  if ((*(int *)(nodeRecord + 8) != 0) && (remaining = *(int *)(nodeRecord + 4), 0 < remaining)) {
    sameClassCount = 0;
    loopIndex = 0;
    signBits = 0;
    chunk = *(int *)(nodeRecord + 8);
    while( true ) {
      if (*(int *)(classArray + node * 4) ==
          *(int *)(classArray +
                  *(int *)(*(int *)(chunk + (loopIndex + ((loopIndex / 7 + (loopIndex >> 0x1f)) - signBits) * -7) *
                                            4) * 4 + *(int *)(graph + 0x20)) * 4)) {
        sameClassCount = sameClassCount + 1;
      }
      loopIndex = loopIndex + 1;
      remaining = remaining + -1;
      if (remaining == 0) break;
      signBits = loopIndex >> 0x1f;
      if (((0 < loopIndex) && (loopIndex == (loopIndex / 7) * 7)) && (*(int *)(chunk + 0x1c) != 0)) {
        chunk = *(int *)(chunk + 0x1c);
      }
    }
    return sameClassCount;
  }
  return 0;
}

/* FUN_00134db0 @ 0x134db0 (56 bytes) */
int FUN_00134db0(param_1)
  undefined4 *param_1;
{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  iVar1 = *piVar2;
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  do {
    piVar2[2] = 0;
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

/* FUN_00134de8 @ 0x134de8 (264 bytes) */
int FUN_00134de8(param_1, inst)
  int param_1;
  int *inst;
{
  int iVar1;
  
  if (inst[0x26] != 0xc) {
    iVar1 = (**(code **)(*inst + 0x50))(inst);
    if ((iVar1 != 0) || (iVar1 = IRInst__getOperandRecord(inst,0), *(int *)(iVar1 + 0x10) == DAT_001afffc)) {
      return 0;
    }
    if ((((inst[0x26] != 0x37) && (inst[0x20] != 0)) &&
        (iVar1 = RegKind__flagBit0(inst[0x26]), iVar1 != 0)) &&
       ((((inst[5] & 2U) == 0 && (iVar1 = (**(code **)(*inst + 0x50))(inst), iVar1 == 0))
        && (((*(uint *)(param_1 + 0x30) & 0x400) != 0 || ((inst[5] & 0x40U) == 0)))))) {
      return *(int *)(inst[0x25] * 4 + *(int *)(param_1 + 0x458));
    }
  }
  return inst[0x25];
}

/* FUN_00134ef4 @ 0x134ef4 (204 bytes) */
int FUN_00134ef4(param_1, param_2, param_3, compiler)
  int param_1;
  int *param_2;
  int *param_3;
  int compiler;
{
  undefined4 *allocation;
  int iVar2;
  undefined4 arena;
  
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  iVar2 = *param_2;
  *param_2 = iVar2 + 1;
  if (iVar2 + 1 == 7) {
    *param_2 = 0;
    iVar2 = *param_3;
    if (iVar2 == 0) {
      arena = *(undefined4 *)(compiler + COMP_arenaB);
      allocation = (undefined4 *)Arena__alloc(arena,0x24);
      *allocation = arena;
      *(undefined4 **)(param_1 + 8) = allocation + 1;
      allocation[8] = 0;
      *param_3 = *(int *)(param_1 + 8);
    }
    else {
      if (*(int *)(iVar2 + 0x1c) == 0) {
        arena = *(undefined4 *)(compiler + COMP_arenaB);
        allocation = (undefined4 *)Arena__alloc(arena,0x24);
        *allocation = arena;
        *(undefined4 **)(iVar2 + 0x1c) = allocation + 1;
        *(undefined4 *)(*(int *)(*param_3 + 0x1c) + 0x1c) = 0;
        iVar2 = *param_3;
      }
      *param_3 = *(int *)(iVar2 + 0x1c);
    }
  }
  return;
}

/* storeAfterLocate @ 0x134fc0 (80 bytes) */
int storeAfterLocate(param_1, param_2, param_3, param_4, compiler)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
  int *param_4;
  undefined4 compiler;
{
  ((int (*)())FUN_00134ef4)(param_1,param_3,param_4,compiler);
  *(undefined4 *)(*param_4 + *param_3 * 4) = param_2;
  return;
}

/* FUN_00135010 @ 0x135010 (128 bytes) */
int FUN_00135010(param_1)
  int param_1;
{
  int iVar1;
  
  while (iVar1 = *(int *)(param_1 + 8), iVar1 != 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0x1c);
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
    return;
  }
  return;
}

/* FUN_00135090 @ 0x135090 (128 bytes) */
int FUN_00135090(param_1)
  int param_1;
{
  int iVar1;
  
  while (iVar1 = *(int *)(param_1 + 8), iVar1 != 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0x1c);
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
    return;
  }
  return;
}

/* FUN_00135110 @ 0x135110 (148 bytes) */
int FUN_00135110(param_1, param_2, param_3, param_4, compiler)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  *(int *)(param_2 * 4 + *(int *)(param_4 + 0x20)) = param_2;
  arena = *(undefined4 *)(compiler + COMP_arenaB);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  param_1[4] = (int)(allocation + 1);
  return;
}

/* FUN_001351c4 @ 0x1351c4 (148 bytes) */
int FUN_001351c4(param_1, param_2, param_3, param_4, compiler)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  *(int *)(param_2 * 4 + *(int *)(param_4 + 0x20)) = param_2;
  arena = *(undefined4 *)(compiler + COMP_arenaB);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  arena = Arena__alloc(arena,8);
  allocation[3] = arena;
  param_1[4] = (int)(allocation + 1);
  return;
}

/* FUN_00135278 @ 0x135278 (188 bytes) */
int FUN_00135278(param_1)
  int param_1;
{
  uint uVar1;
  int *piVar2;
  uint loopIndex;
  uint *puVar4;
  
  if (0 < *(int *)(param_1 + 0xc)) {
    loopIndex = 0;
    do {
      puVar4 = *(uint **)(param_1 + 4);
      if (loopIndex < *puVar4) {
        uVar1 = puVar4[1];
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar4[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar4[1] = loopIndex + 1;
        }
        piVar2 = (int *)(loopIndex * 4 + puVar4[2]);
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(puVar4,loopIndex);
      }
      loopIndex = loopIndex + 1;
      *(undefined4 *)(*piVar2 + 4) = 0;
    } while ((int)loopIndex < *(int *)(param_1 + 0xc));
  }
  return;
}

/* FUN_00135334 @ 0x135334 (552 bytes) */
int FUN_00135334(graph, nodeA, nodeB)
  int graph;
  uint nodeA;
  uint nodeB;
{
  undefined4 *nodeBRef;
  int alreadyInterfere;
  uint nodeVectorCount;
  undefined4 *nodeARef;
  uint *nodeVector;
  undefined1 neighbourLocation [4];
  undefined1 neighbourLocationRest [28];
  
  if ((nodeA != nodeB) && (alreadyInterfere = ((int (*)())InterferenceMatrix__testPair)(graph,nodeA,nodeB), alreadyInterfere == 0)) {
    ((int (*)())InterferenceMatrix__setPair)(graph,nodeA,nodeB);
    nodeVector = *(uint **)(graph + 4);
    if (nodeA < *nodeVector) {
      nodeVectorCount = nodeVector[1];
      if (nodeVectorCount <= nodeA) {
        _memset(nodeVectorCount * 4 + nodeVector[2],0,(nodeA - nodeVectorCount) * 4 + 4);
        nodeVector[1] = nodeA + 1;
      }
      nodeARef = (undefined4 *)(nodeA * 4 + nodeVector[2]);
    }
    else {
      nodeARef = (undefined4 *)Vector__elementRefGrow(nodeVector,nodeA);
    }
    ((int (*)())FUN_00134ab8)(*nodeARef,neighbourLocation,neighbourLocationRest);
    nodeVector = *(uint **)(graph + 4);
    if (nodeA < *nodeVector) {
      nodeVectorCount = nodeVector[1];
      if (nodeVectorCount <= nodeA) {
        _memset(nodeVectorCount * 4 + nodeVector[2],0,(nodeA - nodeVectorCount) * 4 + 4);
        nodeVector[1] = nodeA + 1;
      }
      nodeARef = (undefined4 *)(nodeA * 4 + nodeVector[2]);
    }
    else {
      nodeARef = (undefined4 *)Vector__elementRefGrow(nodeVector,nodeA);
    }
    ((int (*)())storeAfterLocate)(*nodeARef,nodeB,neighbourLocation,neighbourLocationRest,*(undefined4 *)(graph + 0x2c));
    nodeVector = *(uint **)(graph + 4);
    if (nodeB < *nodeVector) {
      nodeVectorCount = nodeVector[1];
      if (nodeVectorCount <= nodeB) {
        _memset(nodeVectorCount * 4 + nodeVector[2],0,(nodeB - nodeVectorCount) * 4 + 4);
        nodeVector[1] = nodeB + 1;
      }
      nodeBRef = (undefined4 *)(nodeB * 4 + nodeVector[2]);
    }
    else {
      nodeBRef = (undefined4 *)Vector__elementRefGrow(nodeVector,nodeB);
    }
    ((int (*)())FUN_00134ab8)(*nodeBRef,neighbourLocation,neighbourLocationRest);
    nodeVector = *(uint **)(graph + 4);
    if (nodeB < *nodeVector) {
      nodeVectorCount = nodeVector[1];
      if (nodeVectorCount <= nodeB) {
        _memset(nodeVectorCount * 4 + nodeVector[2],0,(nodeB - nodeVectorCount) * 4 + 4);
        nodeVector[1] = nodeB + 1;
      }
      nodeBRef = (undefined4 *)(nodeB * 4 + nodeVector[2]);
    }
    else {
      nodeBRef = (undefined4 *)Vector__elementRefGrow(nodeVector,nodeB);
    }
    ((int (*)())storeAfterLocate)(*nodeBRef,nodeA,neighbourLocation,neighbourLocationRest,*(undefined4 *)(graph + 0x2c));
  }
  return;
}

/* FUN_0013555c @ 0x13555c (296 bytes) */
int FUN_0013555c(graph, targetNode, sourceNodeIndex)
  int graph;
  int targetNode;
  uint sourceNodeIndex;
{
  bool blockFull;
  uint nodeVectorCount;
  int *sourceNodeRef;
  undefined4 addedEdge;
  int callResult;
  int alreadyInterfere;
  int sourceNode;
  int loopIndex;
  int neighbourBlock;
  int slotInBlock;
  uint *nodeVector;
  
  nodeVector = *(uint **)(graph + 4);
  if (sourceNodeIndex < *nodeVector) {
    nodeVectorCount = nodeVector[1];
    if (nodeVectorCount <= sourceNodeIndex) {
      _memset(nodeVectorCount * 4 + nodeVector[2],0,(sourceNodeIndex - nodeVectorCount) * 4 + 4);
      nodeVector[1] = sourceNodeIndex + 1;
    }
    sourceNodeRef = (int *)(sourceNodeIndex * 4 + nodeVector[2]);
  }
  else {
    sourceNodeRef = (int *)Vector__elementRefGrow(nodeVector,sourceNodeIndex);
  }
  sourceNode = *sourceNodeRef;
  addedEdge = 0;
  neighbourBlock = *(int *)(sourceNode + 8);
  if (0 < *(int *)(sourceNode + 4)) {
    slotInBlock = -1;
    loopIndex = 0;
    addedEdge = 0;
    do {
      blockFull = slotInBlock == 6;
      slotInBlock = slotInBlock + 1;
      if (blockFull) {
        neighbourBlock = *(int *)(neighbourBlock + 0x1c);
        slotInBlock = 0;
      }
      callResult = ((int (*)())FUN_00134bf0)(graph,*(undefined4 *)(neighbourBlock + slotInBlock * 4),1);
      if ((callResult != targetNode) && (alreadyInterfere = ((int (*)())InterferenceMatrix__testPair)(graph,targetNode,callResult), alreadyInterfere == 0)) {
        addedEdge = 1;
        ((int (*)())FUN_00135334)(graph,targetNode,callResult);
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < *(int *)(sourceNode + 4));
  }
  return addedEdge;
}

/* FUN_00135684 @ 0x135684 (336 bytes) */
int FUN_00135684(graph, nodeA, nodeB)
  int graph;
  uint nodeA;
  uint nodeB;
{
  uint *nodeAList;
  uint listCount;
  uint nodeVectorCountB;
  uint nodeVectorCountA;
  int *nodeARef;
  undefined4 *listSlotRef;
  undefined4 *nodeBRef;
  uint *nodeVectorHeader;
  uint *nodeVectorAlias;
  
  nodeVectorHeader = *(uint **)(graph + 4);
  if (nodeA < *nodeVectorHeader) {
    nodeVectorCountA = nodeVectorHeader[1];
    nodeVectorAlias = nodeVectorHeader;
    if (nodeVectorCountA <= nodeA) {
      _memset(nodeVectorCountA * 4 + nodeVectorHeader[2],0,(nodeA - nodeVectorCountA) * 4 + 4);
      nodeVectorHeader[1] = nodeA + 1;
      nodeVectorAlias = *(uint **)(graph + 4);
    }
    nodeARef = (int *)(nodeA * 4 + nodeVectorHeader[2]);
  }
  else {
    nodeARef = (int *)Vector__elementRefGrow(nodeVectorHeader,nodeA);
    nodeVectorAlias = *(uint **)(graph + 4);
  }
  nodeAList = *(uint **)(*nodeARef + 0x10);
  if (nodeB < *nodeVectorAlias) {
    nodeVectorCountB = nodeVectorAlias[1];
    if (nodeVectorCountB <= nodeB) {
      _memset(nodeVectorCountB * 4 + nodeVectorAlias[2],0,(nodeB - nodeVectorCountB) * 4 + 4);
      nodeVectorAlias[1] = nodeB + 1;
    }
    nodeBRef = (undefined4 *)(nodeB * 4 + nodeVectorAlias[2]);
  }
  else {
    nodeBRef = (undefined4 *)Vector__elementRefGrow(nodeVectorAlias,nodeB);
  }
  listCount = nodeAList[1];
  if (listCount < *nodeAList) {
    _memset(listCount * 4 + nodeAList[2],0,4);
    listSlotRef = (undefined4 *)(listCount * 4 + nodeAList[2]);
    nodeAList[1] = listCount + 1;
  }
  else {
    listSlotRef = (undefined4 *)Vector__elementRefGrow(nodeAList,listCount);
  }
  *listSlotRef = *nodeBRef;
  return;
}

/* FUN_001357d4 @ 0x1357d4 (300 bytes) */
int FUN_001357d4(param_1)
  int param_1;
{
  uint uVar1;
  int *piVar2;
  uint loopIndex;
  uint *puVar4;
  int iVar5;
  
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x14));
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x18));
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x10));
  if (0 < *(int *)(param_1 + 0xc)) {
    loopIndex = 0;
    do {
      puVar4 = *(uint **)(param_1 + 4);
      if (loopIndex < *puVar4) {
        uVar1 = puVar4[1];
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar4[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar4[1] = loopIndex + 1;
        }
        piVar2 = (int *)(loopIndex * 4 + puVar4[2]);
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(puVar4,loopIndex);
      }
      loopIndex = loopIndex + 1;
      iVar5 = *piVar2;
      if (iVar5 != 0) {
        ((int (*)())FUN_00135090)(iVar5);
        Arena__free(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
      }
    } while ((int)loopIndex < *(int *)(param_1 + 0xc));
  }
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 != 0) {
    Arena__free(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8));
    Arena__free(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
  }
  return Arena__free(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x20));
}

/* FUN_00135900 @ 0x135900 (300 bytes) */
int FUN_00135900(param_1)
  int param_1;
{
  uint uVar1;
  int *piVar2;
  uint loopIndex;
  uint *puVar4;
  int iVar5;
  
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x14));
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x18));
  Arena__free(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x10));
  if (0 < *(int *)(param_1 + 0xc)) {
    loopIndex = 0;
    do {
      puVar4 = *(uint **)(param_1 + 4);
      if (loopIndex < *puVar4) {
        uVar1 = puVar4[1];
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar4[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar4[1] = loopIndex + 1;
        }
        piVar2 = (int *)(loopIndex * 4 + puVar4[2]);
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(puVar4,loopIndex);
      }
      loopIndex = loopIndex + 1;
      iVar5 = *piVar2;
      if (iVar5 != 0) {
        ((int (*)())FUN_00135090)(iVar5);
        Arena__free(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
      }
    } while ((int)loopIndex < *(int *)(param_1 + 0xc));
  }
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 != 0) {
    Arena__free(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8));
    Arena__free(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
  }
  return Arena__free(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x20));
}

/* FUN_00135a2c @ 0x135a2c (500 bytes) */
int FUN_00135a2c(targetNode, mergedNodeIndex, graph)
  int *targetNode;
  uint mergedNodeIndex;
  int graph;
{
  int neighbourBlock;
  int mergedNodeRecordB;
  bool blockFull;
  uint nodeVectorCount;
  int *mergedNodeRef;
  undefined4 neighbourRoot;
  int callResult;
  int mergedNodeRecord;
  int neighbourBlockCursor;
  int loopIndex;
  int lastNeighbourBlock;
  int slotInBlock;
  uint *nodeVector;
  undefined1 neighbourLocation [4];
  undefined1 neighbourLocationRest [28];
  
  nodeVector = *(uint **)(graph + 4);
  if (mergedNodeIndex < *nodeVector) {
    nodeVectorCount = nodeVector[1];
    if (nodeVectorCount <= mergedNodeIndex) {
      _memset(nodeVectorCount * 4 + nodeVector[2],0,(mergedNodeIndex - nodeVectorCount) * 4 + 4);
      nodeVector[1] = mergedNodeIndex + 1;
    }
    mergedNodeRef = (int *)(mergedNodeIndex * 4 + nodeVector[2]);
  }
  else {
    mergedNodeRef = (int *)Vector__elementRefGrow(nodeVector,mergedNodeIndex);
  }
  mergedNodeRecord = *mergedNodeRef;
  neighbourBlockCursor = targetNode[2];
  if (targetNode[2] == 0) {
    targetNode[2] = *(int *)(mergedNodeRecord + 8);
  }
  else {
    do {
      lastNeighbourBlock = neighbourBlockCursor;
      neighbourBlockCursor = *(int *)(lastNeighbourBlock + 0x1c);
    } while (neighbourBlockCursor != 0);
    *(undefined4 *)(lastNeighbourBlock + 0x1c) = *(undefined4 *)(mergedNodeRecord + 8);
  }
  ((int (*)())FUN_00134ab8)(targetNode,neighbourLocation,neighbourLocationRest);
  nodeVector = *(uint **)(graph + 4);
  if (mergedNodeIndex < *nodeVector) {
    nodeVectorCount = nodeVector[1];
    if (nodeVectorCount <= mergedNodeIndex) {
      _memset(nodeVectorCount * 4 + nodeVector[2],0,(mergedNodeIndex - nodeVectorCount) * 4 + 4);
      nodeVector[1] = mergedNodeIndex + 1;
    }
    mergedNodeRef = (int *)(mergedNodeIndex * 4 + nodeVector[2]);
  }
  else {
    mergedNodeRef = (int *)Vector__elementRefGrow(nodeVector,mergedNodeIndex);
  }
  mergedNodeRecordB = *mergedNodeRef;
  neighbourBlock = *(int *)(mergedNodeRecordB + 8);
  if (0 < *(int *)(mergedNodeRecordB + 4)) {
    slotInBlock = -1;
    loopIndex = 0;
    do {
      blockFull = slotInBlock == 6;
      slotInBlock = slotInBlock + 1;
      if (blockFull) {
        neighbourBlock = *(int *)(neighbourBlock + 0x1c);
        slotInBlock = 0;
      }
      neighbourRoot = ((int (*)())FUN_00134bf0)(graph,*(undefined4 *)(neighbourBlock + slotInBlock * 4),1);
      callResult = ((int (*)())InterferenceMatrix__testPair)(graph,*(undefined4 *)(*targetNode * 4 + *(int *)(graph + 0x20)),neighbourRoot);
      if (callResult == 0) {
        ((int (*)())storeAfterLocate)(targetNode,neighbourRoot,neighbourLocation,neighbourLocationRest,*(undefined4 *)(graph + 0x2c));
        ((int (*)())InterferenceMatrix__setPair)(graph,*(undefined4 *)(*targetNode * 4 + *(int *)(graph + 0x20)),neighbourRoot);
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < *(int *)(mergedNodeRecordB + 4));
  }
  *(undefined4 *)(mergedNodeRecord + 8) = 0;
  *(undefined4 *)(mergedNodeRecord + 4) = 0;
  return;
}

/* FUN_00135c20 @ 0x135c20 (260 bytes) */
int FUN_00135c20(graph, elementIndex, nodeB)
  int graph;
  uint elementIndex;
  uint nodeB;
{
  undefined4 merged;
  int callResult;
  uint nodeVectorCount;
  undefined4 *lowerNodeRef;
  uint lowerNode;
  uint *nodeVector;
  
  merged = 1;
  if (elementIndex != nodeB) {
    callResult = ((int (*)())InterferenceMatrix__testPair)(graph,nodeB,elementIndex);
    merged = 0;
    if (callResult == 0) {
      lowerNode = elementIndex;
      if ((int)nodeB < (int)elementIndex) {
        lowerNode = nodeB;
      }
      if ((int)elementIndex < (int)nodeB) {
        elementIndex = nodeB;
      }
      nodeVector = *(uint **)(graph + 4);
      if (lowerNode < *nodeVector) {
        nodeVectorCount = nodeVector[1];
        if (nodeVectorCount <= lowerNode) {
          _memset(nodeVectorCount * 4 + nodeVector[2],0,(lowerNode - nodeVectorCount) * 4 + 4);
          nodeVector[1] = lowerNode + 1;
        }
        lowerNodeRef = (undefined4 *)(lowerNode * 4 + nodeVector[2]);
      }
      else {
        lowerNodeRef = (undefined4 *)Vector__elementRefGrow(nodeVector,lowerNode);
      }
      ((int (*)())FUN_00135a2c)(*lowerNodeRef,elementIndex,graph);
      ((int (*)())FUN_00134cd4)(graph,lowerNode,elementIndex);
      merged = 1;
    }
  }
  return merged;
}

/* ColorGraph__removeNodeUpdateDegrees @ 0x135d24 (652 bytes) */
int ColorGraph__removeNodeUpdateDegrees(graph, node, workList, colorLimit, registerClass)
  int graph;
  uint node;
  uint *workList;
  int colorLimit;
  int registerClass;
{
  bool slotWrapped;
  int neighborByteOffset;
  uint neighbor;
  int *elementRef;
  uint countOrScratch;
  int loopIndex;
  int nodeRecord;
  int chunk;
  int slotInChunk;
  uint *vectorHeader;
  
  vectorHeader = *(uint **)(graph + 4);
  if (node < *vectorHeader) {
    neighbor = vectorHeader[1];
    if (neighbor <= node) {
      _memset(neighbor * 4 + vectorHeader[2],0,(node - neighbor) * 4 + 4);
      vectorHeader[1] = node + 1;
    }
    elementRef = (int *)(node * 4 + vectorHeader[2]);
  }
  else {
    elementRef = (int *)Vector__elementRefGrow(vectorHeader,node);
  }
  nodeRecord = *elementRef;
  chunk = *(int *)(nodeRecord + 8);
  if (0 < *(int *)(nodeRecord + 4)) {
    slotInChunk = -1;
    loopIndex = 0;
    do {
      slotWrapped = slotInChunk == 6;
      slotInChunk = slotInChunk + 1;
      if (slotWrapped) {
        chunk = *(int *)(chunk + 0x1c);
        slotInChunk = 0;
      }
      vectorHeader = *(uint **)(graph + 4);
      neighbor = *(uint *)(chunk + slotInChunk * 4);
      if (neighbor < *vectorHeader) {
        countOrScratch = vectorHeader[1];
        if (countOrScratch <= neighbor) {
          _memset(countOrScratch * 4 + vectorHeader[2],0,(neighbor - countOrScratch) * 4 + 4);
          vectorHeader[1] = neighbor + 1;
        }
        elementRef = (int *)(neighbor * 4 + vectorHeader[2]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vectorHeader,neighbor);
      }
      if ((0 < *(int *)(*elementRef + 0xc)) &&
         (neighborByteOffset = neighbor * 4, *(int *)(neighborByteOffset + *(int *)(*(int *)(graph + 0x28) + 0x45c)) == registerClass
         )) {
        vectorHeader = *(uint **)(graph + 4);
        if (neighbor < *vectorHeader) {
          countOrScratch = vectorHeader[1];
          if (countOrScratch <= neighbor) {
            _memset(countOrScratch * 4 + vectorHeader[2],0,(neighbor - countOrScratch) * 4 + 4);
            vectorHeader[1] = neighbor + 1;
          }
          elementRef = (int *)(neighborByteOffset + vectorHeader[2]);
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(vectorHeader,neighbor);
        }
        *(int *)(*elementRef + 0xc) = *(int *)(*elementRef + 0xc) + -1;
        vectorHeader = *(uint **)(graph + 4);
        if (neighbor < *vectorHeader) {
          countOrScratch = vectorHeader[1];
          if (countOrScratch <= neighbor) {
            _memset(countOrScratch * 4 + vectorHeader[2],0,(neighbor - countOrScratch) * 4 + 4);
            vectorHeader[1] = neighbor + 1;
          }
          elementRef = (int *)(neighborByteOffset + vectorHeader[2]);
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(vectorHeader,neighbor);
        }
        if (*(int *)(*elementRef + 0xc) == colorLimit + -1) {
          countOrScratch = workList[1];
          if (countOrScratch < *workList) {
            _memset(countOrScratch * 4 + workList[2],0,4);
            vectorHeader = (uint *)(countOrScratch * 4 + workList[2]);
            workList[1] = countOrScratch + 1;
          }
          else {
            vectorHeader = (uint *)Vector__elementRefGrow(workList,countOrScratch);
          }
          *vectorHeader = neighbor;
        }
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < *(int *)(nodeRecord + 4));
  }
  return;
}

/* pass_color_graph @ 0x135fb0 (516 bytes) */
int pass_color_graph(colorGraph)
  int colorGraph;
{
  undefined4 *allocation;
  bool slotWrapped;
  int neighborByteOffset;
  int classIndexOrNodeCount;
  int programOrClassOffset;
  uint nodeOrCount;
  int *simplifiedStacks;
  int colorLimit;
  int maxColorUsed;
  int hwRegsPerClass;
  int lowDegreeWorklists;
  int usedColorBits;
  int *classNodeCount;
  undefined4 *puVar12;
  int *elementRef;
  int *neighborElementRef;
  int programOrNodeRecord;
  uint colorOrNextId;
  int neighborScanIndex;
  int neighborCount;
  int slotInChunk;
  int registerClassCount;
  undefined4 *bitsetData;
  int *simplifiedStackSlot;
  uint nextIdOrAffinityIndex;
  int *workSlot;
  int byteOffset;
  uint nodeIdOrBitsetWords;
  undefined4 arenaOrScratch;
  uint *vectorHeader;
  uint *elementDest;
  int chunkOrBitsetOrCount;
  int uncolorableCount;
  
  simplifiedStacks = *(int **)(colorGraph + 0x24);
  classIndexOrNodeCount = *simplifiedStacks;
  if (classIndexOrNodeCount != 0) {
    if (classIndexOrNodeCount == 0) {
      classIndexOrNodeCount = 1;
    }
    do {
      simplifiedStacks[2] = 0;
      simplifiedStacks = simplifiedStacks + 1;
      classIndexOrNodeCount = classIndexOrNodeCount + -1;
    } while (classIndexOrNodeCount != 0);
  }
  registerClassCount = *(int *)(*(int *)(*(int *)(colorGraph + 0x2c) + 0x30c) + 0x14);
  classIndexOrNodeCount = registerClassCount << 2;
  colorLimit = Arena__alloc(*(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378),classIndexOrNodeCount);
  maxColorUsed = Arena__alloc(*(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378),classIndexOrNodeCount);
  hwRegsPerClass = Arena__alloc(*(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378),classIndexOrNodeCount);
  simplifiedStacks = *(int **)(*(int *)(colorGraph + 0x2c) + 0x30c);
  (**(code **)(*simplifiedStacks + 0x130))(simplifiedStacks,hwRegsPerClass,*(int *)(colorGraph + 0x2c));
  lowDegreeWorklists = Arena__alloc(*(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378),classIndexOrNodeCount);
  simplifiedStacks = (int *)Arena__alloc(*(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378),classIndexOrNodeCount);
  usedColorBits = Arena__alloc(*(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378),classIndexOrNodeCount);
  classNodeCount = (int *)Arena__alloc(*(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378),classIndexOrNodeCount);
  if (registerClassCount >= 1) {
    classIndexOrNodeCount = 0;
    byteOffset = 0;
    do {
      programOrClassOffset = *(int *)(byteOffset + *(int *)(colorGraph + 0x14));
      if (programOrClassOffset < 1) {
        programOrClassOffset = 1;
      }
      *(int *)(colorLimit + byteOffset) = programOrClassOffset;
      arenaOrScratch = *(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378);
      allocation = (undefined4 *)Arena__alloc(arenaOrScratch,0x14);
      *allocation = arenaOrScratch;
      allocation[1] = 2;
      allocation[4] = arenaOrScratch;
      allocation[2] = 0;
      arenaOrScratch = Arena__alloc(arenaOrScratch,8);
      allocation[3] = arenaOrScratch;
      *(undefined4 **)(lowDegreeWorklists + byteOffset) = allocation + 1;
      arenaOrScratch = *(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378);
      allocation = (undefined4 *)Arena__alloc(arenaOrScratch,0x14);
      *allocation = arenaOrScratch;
      allocation[1] = 2;
      allocation[2] = 0;
      allocation[4] = arenaOrScratch;
      arenaOrScratch = Arena__alloc(arenaOrScratch,8);
      allocation[3] = arenaOrScratch;
      *(undefined4 **)((int)simplifiedStacks + byteOffset) = allocation + 1;
      programOrClassOffset = *(int *)(byteOffset + hwRegsPerClass);
      arenaOrScratch = *(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378);
      nodeIdOrBitsetWords = programOrClassOffset + 0x1fU >> 5;
      allocation = (undefined4 *)Arena__alloc(arenaOrScratch,nodeIdOrBitsetWords * 4 + 0xc);
      bitsetData = allocation + 1;
      *allocation = arenaOrScratch;
      allocation[1] = nodeIdOrBitsetWords;
      allocation[2] = programOrClassOffset;
      if (nodeIdOrBitsetWords != 0) {
        puVar12 = bitsetData;
        if (nodeIdOrBitsetWords == 0) {
          nodeIdOrBitsetWords = 1;
        }
        do {
          puVar12[2] = 0;
          puVar12 = puVar12 + 1;
          nodeIdOrBitsetWords = nodeIdOrBitsetWords - 1;
        } while (nodeIdOrBitsetWords != 0);
      }
      classIndexOrNodeCount = classIndexOrNodeCount + 1;
      *(undefined4 **)(usedColorBits + byteOffset) = bitsetData;
      *(undefined4 *)((int)classNodeCount + byteOffset) = 0;
      *(undefined4 *)(maxColorUsed + byteOffset) = 0;
      byteOffset = byteOffset + 4;
    } while (registerClassCount != classIndexOrNodeCount);
  }
  nodeIdOrBitsetWords = *(uint *)(colorGraph + 8);
  if (0 < (int)nodeIdOrBitsetWords) {
    classIndexOrNodeCount = 0;
    do {
      byteOffset = classIndexOrNodeCount * 4;
      classIndexOrNodeCount = classIndexOrNodeCount + 1;
      programOrClassOffset = *(int *)(*(int *)(colorGraph + 0x28) + 0x458);
      *(int *)(byteOffset + programOrClassOffset) =
           *(int *)(byteOffset + programOrClassOffset) -
           *(int *)(*(int *)(byteOffset + *(int *)(*(int *)(colorGraph + 0x28) + 0x45c)) * 4 +
                   *(int *)(colorGraph + 0x10));
      nodeIdOrBitsetWords = *(uint *)(colorGraph + 8);
    } while (classIndexOrNodeCount < (int)nodeIdOrBitsetWords);
  }
  classIndexOrNodeCount = *(int *)(colorGraph + 0xc);
  if ((int)nodeIdOrBitsetWords < classIndexOrNodeCount) {
    nextIdOrAffinityIndex = nodeIdOrBitsetWords + 1;
    programOrClassOffset = *(int *)(colorGraph + 0x28);
    byteOffset = nodeIdOrBitsetWords << 2;
    nodeOrCount = nextIdOrAffinityIndex;
    do {
      colorOrNextId = nodeOrCount;
      if (nodeIdOrBitsetWords == *(uint *)(byteOffset + *(int *)(colorGraph + 0x20))) {
        classIndexOrNodeCount = *(int *)(byteOffset + *(int *)(programOrClassOffset + 0x45c));
        classNodeCount[classIndexOrNodeCount] = classNodeCount[classIndexOrNodeCount] + 1;
        vectorHeader = *(uint **)(colorGraph + 4);
        if (nodeIdOrBitsetWords < *vectorHeader) {
          nodeOrCount = vectorHeader[1];
          elementDest = vectorHeader;
          if (nodeOrCount <= nodeIdOrBitsetWords) {
            _memset(nodeOrCount * 4 + vectorHeader[2],0,(nodeIdOrBitsetWords - nodeOrCount) * 4 + 4);
            vectorHeader[1] = nextIdOrAffinityIndex;
            elementDest = *(uint **)(colorGraph + 4);
          }
          elementRef = (int *)(byteOffset + vectorHeader[2]);
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(vectorHeader,nodeIdOrBitsetWords);
          elementDest = *(uint **)(colorGraph + 4);
        }
        classIndexOrNodeCount = *elementRef;
        if (nodeIdOrBitsetWords < *elementDest) {
          nodeOrCount = elementDest[1];
          if (nodeOrCount <= nodeIdOrBitsetWords) {
            _memset(nodeOrCount * 4 + elementDest[2],0,(nodeIdOrBitsetWords - nodeOrCount) * 4 + 4);
            elementDest[1] = nextIdOrAffinityIndex;
          }
          puVar12 = (undefined4 *)(byteOffset + elementDest[2]);
        }
        else {
          puVar12 = (undefined4 *)Vector__elementRefGrow(elementDest,nodeIdOrBitsetWords);
        }
        arenaOrScratch = ((int (*)())ColorGraph__countSameClassNeighbors)(*puVar12,nodeIdOrBitsetWords,*(undefined4 *)(*(int *)(colorGraph + 0x28) + 0x45c),
                              colorGraph);
        *(undefined4 *)(classIndexOrNodeCount + 0xc) = arenaOrScratch;
        vectorHeader = *(uint **)(colorGraph + 4);
        if (nodeIdOrBitsetWords < *vectorHeader) {
          nodeOrCount = vectorHeader[1];
          if (nodeOrCount <= nodeIdOrBitsetWords) {
            _memset(nodeOrCount * 4 + vectorHeader[2],0,(nodeIdOrBitsetWords - nodeOrCount) * 4 + 4);
            vectorHeader[1] = nextIdOrAffinityIndex;
          }
          elementRef = (int *)(byteOffset + vectorHeader[2]);
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(vectorHeader,nodeIdOrBitsetWords);
        }
        if (*(int *)(*elementRef + 0xc) == 0) {
          vectorHeader = (uint *)simplifiedStacks[*(int *)(byteOffset + *(int *)(*(int *)(colorGraph + 0x28) + 0x45c))];
          nodeOrCount = vectorHeader[1];
          if (nodeOrCount < *vectorHeader) {
code_r0x001364b4:
            _memset(nodeOrCount * 4 + vectorHeader[2],0,4);
            elementDest = (uint *)(nodeOrCount * 4 + vectorHeader[2]);
            vectorHeader[1] = nodeOrCount + 1;
          }
          else {
code_r0x001364e0:
            elementDest = (uint *)Vector__elementRefGrow(vectorHeader,nodeOrCount);
          }
          *elementDest = nodeIdOrBitsetWords;
          programOrClassOffset = *(int *)(colorGraph + 0x28);
          classIndexOrNodeCount = *(int *)(colorGraph + 0xc);
        }
        else {
          vectorHeader = *(uint **)(colorGraph + 4);
          if (nodeIdOrBitsetWords < *vectorHeader) {
            nodeOrCount = vectorHeader[1];
            if (nodeOrCount <= nodeIdOrBitsetWords) {
              _memset(nodeOrCount * 4 + vectorHeader[2],0,(nodeIdOrBitsetWords - nodeOrCount) * 4 + 4);
              vectorHeader[1] = nextIdOrAffinityIndex;
            }
            elementRef = (int *)(byteOffset + vectorHeader[2]);
          }
          else {
            elementRef = (int *)Vector__elementRefGrow(vectorHeader,nodeIdOrBitsetWords);
          }
          programOrClassOffset = *(int *)(colorGraph + 0x28);
          classIndexOrNodeCount = *(int *)(byteOffset + *(int *)(programOrClassOffset + 0x45c)) * 4;
          if (*(int *)(*elementRef + 0xc) < *(int *)(colorLimit + classIndexOrNodeCount)) {
            vectorHeader = *(uint **)(lowDegreeWorklists + classIndexOrNodeCount);
            nodeOrCount = vectorHeader[1];
            if (nodeOrCount < *vectorHeader) goto code_r0x001364b4;
            goto code_r0x001364e0;
          }
          classIndexOrNodeCount = *(int *)(colorGraph + 0xc);
        }
      }
      nextIdOrAffinityIndex = nextIdOrAffinityIndex + 1;
      byteOffset = byteOffset + 4;
      if (classIndexOrNodeCount <= (int)colorOrNextId) goto code_r0x0013651c;
      nodeOrCount = colorOrNextId + 1;
      nodeIdOrBitsetWords = colorOrNextId;
    } while( true );
  }
  programOrClassOffset = *(int *)(colorGraph + 0x28);
code_r0x0013651c:
  *(undefined4 *)(programOrClassOffset + 0x25c) = 0;
  if (registerClassCount < 1) {
    uncolorableCount = 0;
  }
  else {
    classIndexOrNodeCount = 0;
    byteOffset = 0;
    uncolorableCount = 0;
    elementRef = classNodeCount;
    simplifiedStackSlot = simplifiedStacks;
code_r0x001367c0:
    while (*(int *)(*(int *)((int)simplifiedStacks + byteOffset) + 4) != *(int *)((int)classNodeCount + byteOffset)) {
      workSlot = (int *)(lowDegreeWorklists + byteOffset);
      *(int *)(*(int *)(colorGraph + 0x28) + 0x25c) = *(int *)(*(int *)(colorGraph + 0x28) + 0x25c) + 1;
      programOrClassOffset = *(int *)(lowDegreeWorklists + byteOffset);
      nodeIdOrBitsetWords = *(uint *)(programOrClassOffset + 4);
      while (nodeIdOrBitsetWords != 0) {
        vectorHeader = (uint *)0x0;
        if (nodeIdOrBitsetWords - 1 < nodeIdOrBitsetWords) {
          vectorHeader = (uint *)((nodeIdOrBitsetWords - 1) * 4 + *(int *)(programOrClassOffset + 8));
        }
        nodeOrCount = *vectorHeader;
        Vector__removeAt(programOrClassOffset,nodeIdOrBitsetWords - 1);
        vectorHeader = *(uint **)(colorGraph + 4);
        if (nodeOrCount < *vectorHeader) {
          nodeIdOrBitsetWords = vectorHeader[1];
          if (nodeIdOrBitsetWords <= nodeOrCount) {
            _memset(nodeIdOrBitsetWords * 4 + vectorHeader[2],0,(nodeOrCount - nodeIdOrBitsetWords) * 4 + 4);
            vectorHeader[1] = nodeOrCount + 1;
          }
          neighborElementRef = (int *)(nodeOrCount * 4 + vectorHeader[2]);
        }
        else {
          neighborElementRef = (int *)Vector__elementRefGrow(vectorHeader,nodeOrCount);
        }
        *(undefined4 *)(*neighborElementRef + 0xc) = 0;
        vectorHeader = (uint *)*simplifiedStackSlot;
        nodeIdOrBitsetWords = vectorHeader[1];
        if (nodeIdOrBitsetWords < *vectorHeader) {
          _memset(nodeIdOrBitsetWords * 4 + vectorHeader[2],0,4);
          elementDest = (uint *)(nodeIdOrBitsetWords * 4 + vectorHeader[2]);
          vectorHeader[1] = nodeIdOrBitsetWords + 1;
        }
        else {
          elementDest = (uint *)Vector__elementRefGrow(vectorHeader,nodeIdOrBitsetWords);
        }
        *elementDest = nodeOrCount;
        ((int (*)())ColorGraph__removeNodeUpdateDegrees)(colorGraph,nodeOrCount,*workSlot,*(undefined4 *)(colorLimit + byteOffset),classIndexOrNodeCount);
        programOrClassOffset = *workSlot;
        nodeIdOrBitsetWords = *(uint *)(programOrClassOffset + 4);
      }
      if (*(int *)(*simplifiedStackSlot + 4) != *elementRef) {
        *(int *)(colorLimit + byteOffset) = *(int *)(colorLimit + byteOffset) + 1;
        nodeIdOrBitsetWords = *(uint *)(colorGraph + 8);
        programOrClassOffset = *(int *)(colorGraph + 0xc);
        if ((int)nodeIdOrBitsetWords < programOrClassOffset) {
          programOrNodeRecord = nodeIdOrBitsetWords << 2;
          do {
            if ((nodeIdOrBitsetWords == *(uint *)(programOrNodeRecord + *(int *)(colorGraph + 0x20))) &&
               (classIndexOrNodeCount == *(int *)(programOrNodeRecord + *(int *)(*(int *)(colorGraph + 0x28) + 0x45c)))) {
              vectorHeader = *(uint **)(colorGraph + 4);
              if (nodeIdOrBitsetWords < *vectorHeader) {
                nodeOrCount = vectorHeader[1];
                if (nodeOrCount <= nodeIdOrBitsetWords) {
                  _memset(nodeOrCount * 4 + vectorHeader[2],0,(nodeIdOrBitsetWords - nodeOrCount) * 4 + 4);
                  vectorHeader[1] = nodeIdOrBitsetWords + 1;
                }
                neighborElementRef = (int *)(programOrNodeRecord + vectorHeader[2]);
              }
              else {
                neighborElementRef = (int *)Vector__elementRefGrow(vectorHeader,nodeIdOrBitsetWords);
              }
              if (*(int *)(*neighborElementRef + 0xc) == *(int *)(colorLimit + byteOffset) + -1) {
                vectorHeader = (uint *)*workSlot;
                nodeOrCount = vectorHeader[1];
                if (nodeOrCount < *vectorHeader) {
                  _memset(nodeOrCount * 4 + vectorHeader[2],0,4);
                  elementDest = (uint *)(nodeOrCount * 4 + vectorHeader[2]);
                  vectorHeader[1] = nodeOrCount + 1;
                }
                else {
                  elementDest = (uint *)Vector__elementRefGrow(vectorHeader,nodeOrCount);
                }
                *elementDest = nodeIdOrBitsetWords;
                programOrClassOffset = *(int *)(colorGraph + 0xc);
              }
              else {
                programOrClassOffset = *(int *)(colorGraph + 0xc);
              }
            }
            nodeIdOrBitsetWords = nodeIdOrBitsetWords + 1;
            programOrNodeRecord = programOrNodeRecord + 4;
          } while ((int)nodeIdOrBitsetWords < programOrClassOffset);
        }
      }
    }
    programOrClassOffset = *(int *)(lowDegreeWorklists + byteOffset);
    if (programOrClassOffset != 0) {
      Arena__free(*(undefined4 *)(programOrClassOffset + 0xc),*(undefined4 *)(programOrClassOffset + 8));
      Arena__free(*(undefined4 *)(programOrClassOffset + -4),programOrClassOffset + -4);
    }
    *(undefined4 *)(*(int *)(colorGraph + 0x28) + 0x260) = 0;
    while (*(int *)(*simplifiedStackSlot + 4) != 0) {
      elementRef = *(int **)(byteOffset + usedColorBits);
      workSlot = (int *)(byteOffset + usedColorBits);
      programOrClassOffset = *elementRef;
      if (programOrClassOffset != 0) {
        if (programOrClassOffset == 0) {
          programOrClassOffset = 1;
        }
        do {
          elementRef[2] = 0;
          elementRef = elementRef + 1;
          programOrClassOffset = programOrClassOffset + -1;
        } while (programOrClassOffset != 0);
      }
      programOrNodeRecord = *(int *)(colorGraph + 0x28);
      programOrClassOffset = classIndexOrNodeCount * 4;
      chunkOrBitsetOrCount = *(int *)(programOrClassOffset + programOrNodeRecord + 0x43c);
      if (chunkOrBitsetOrCount < *(int *)(programOrClassOffset + programOrNodeRecord + 0x448)) {
        do {
          programOrNodeRecord = Program__isHwRegAllowed(programOrNodeRecord,chunkOrBitsetOrCount);
          if (programOrNodeRecord == 0) {
            nodeIdOrBitsetWords = chunkOrBitsetOrCount - *(int *)(programOrClassOffset + *(int *)(colorGraph + 0x28) + 0x43c);
            programOrNodeRecord = (nodeIdOrBitsetWords >> 3 & 0x1ffffffc) + *workSlot;
            *(uint *)(programOrNodeRecord + 8) = 1 << (nodeIdOrBitsetWords & 0x1f) | *(uint *)(programOrNodeRecord + 8);
          }
          programOrNodeRecord = *(int *)(colorGraph + 0x28);
          chunkOrBitsetOrCount = chunkOrBitsetOrCount + 1;
        } while (chunkOrBitsetOrCount < *(int *)(programOrClassOffset + programOrNodeRecord + 0x448));
      }
      programOrNodeRecord = *simplifiedStackSlot;
      vectorHeader = (uint *)0x0;
      nodeIdOrBitsetWords = *(uint *)(programOrNodeRecord + 4);
      if (nodeIdOrBitsetWords - 1 < nodeIdOrBitsetWords) {
        vectorHeader = (uint *)((nodeIdOrBitsetWords - 1) * 4 + *(int *)(programOrNodeRecord + 8));
      }
      nodeOrCount = *vectorHeader;
      Vector__removeAt(programOrNodeRecord,nodeIdOrBitsetWords - 1);
      vectorHeader = *(uint **)(colorGraph + 4);
      if (nodeOrCount < *vectorHeader) {
        nodeIdOrBitsetWords = vectorHeader[1];
        if (nodeIdOrBitsetWords <= nodeOrCount) {
          _memset(nodeIdOrBitsetWords * 4 + vectorHeader[2],0,(nodeOrCount - nodeIdOrBitsetWords) * 4 + 4);
          vectorHeader[1] = nodeOrCount + 1;
        }
        elementRef = (int *)(nodeOrCount * 4 + vectorHeader[2]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vectorHeader,nodeOrCount);
      }
      programOrNodeRecord = *elementRef;
      neighborCount = *(int *)(programOrNodeRecord + 4);
      chunkOrBitsetOrCount = *(int *)(programOrNodeRecord + 8);
      if (0 < neighborCount) {
        slotInChunk = -1;
        neighborScanIndex = 0;
        do {
          slotWrapped = slotInChunk == 6;
          slotInChunk = slotInChunk + 1;
          if (slotWrapped) {
            chunkOrBitsetOrCount = *(int *)(chunkOrBitsetOrCount + 0x1c);
            slotInChunk = 0;
          }
          neighborByteOffset = *(int *)(chunkOrBitsetOrCount + slotInChunk * 4) * 4;
          if ((classIndexOrNodeCount == *(int *)(*(int *)(*(int *)(colorGraph + 0x28) + 0x45c) + neighborByteOffset)) &&
             (nodeIdOrBitsetWords = *(uint *)(neighborByteOffset + *(int *)(*(int *)(colorGraph + 0x28) + 0x458)),
             -1 < (int)nodeIdOrBitsetWords)) {
            neighborCount = (nodeIdOrBitsetWords >> 3 & 0x1ffffffc) + *workSlot;
            *(uint *)(neighborCount + 8) = 1 << (nodeIdOrBitsetWords & 0x1f) | *(uint *)(neighborCount + 8);
            neighborCount = *(int *)(programOrNodeRecord + 4);
          }
          neighborScanIndex = neighborScanIndex + 1;
        } while (neighborScanIndex < neighborCount);
      }
      vectorHeader = *(uint **)(colorGraph + 4);
      if (nodeOrCount < *vectorHeader) {
        nodeIdOrBitsetWords = vectorHeader[1];
        if (nodeIdOrBitsetWords <= nodeOrCount) {
          _memset(nodeIdOrBitsetWords * 4 + vectorHeader[2],0,(nodeOrCount - nodeIdOrBitsetWords) * 4 + 4);
          vectorHeader[1] = nodeOrCount + 1;
        }
        elementRef = (int *)(nodeOrCount * 4 + vectorHeader[2]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vectorHeader,nodeOrCount);
      }
      nodeIdOrBitsetWords = *(uint *)(*(int *)(*elementRef + 0x10) + 4);
      if (0 < (int)nodeIdOrBitsetWords) {
        programOrNodeRecord = nodeOrCount * 4;
        nextIdOrAffinityIndex = 0;
        do {
          vectorHeader = *(uint **)(colorGraph + 4);
          if (nodeOrCount < *vectorHeader) {
            colorOrNextId = vectorHeader[1];
            if (colorOrNextId <= nodeOrCount) {
              _memset(colorOrNextId * 4 + vectorHeader[2],0,(nodeOrCount - colorOrNextId) * 4 + 4);
              vectorHeader[1] = nodeOrCount + 1;
            }
            elementRef = (int *)(programOrNodeRecord + vectorHeader[2]);
          }
          else {
            elementRef = (int *)Vector__elementRefGrow(vectorHeader,nodeOrCount);
          }
          vectorHeader = *(uint **)(*elementRef + 0x10);
          if (nextIdOrAffinityIndex < *vectorHeader) {
            colorOrNextId = vectorHeader[1];
            if (colorOrNextId <= nextIdOrAffinityIndex) {
              _memset(colorOrNextId * 4 + vectorHeader[2],0,(nextIdOrAffinityIndex - colorOrNextId) * 4 + 4);
              vectorHeader[1] = nextIdOrAffinityIndex + 1;
            }
            puVar12 = (undefined4 *)(nextIdOrAffinityIndex * 4 + vectorHeader[2]);
          }
          else {
            puVar12 = (undefined4 *)Vector__elementRefGrow(vectorHeader,nextIdOrAffinityIndex);
          }
          chunkOrBitsetOrCount = *(int *)(colorGraph + 0x28);
          colorOrNextId = *(uint *)(*(int *)*puVar12 * 4 + *(int *)(chunkOrBitsetOrCount + 0x458));
          if ((-1 < (int)colorOrNextId) &&
             ((*(uint *)((colorOrNextId >> 3 & 0x1ffffffc) + *workSlot + 8) >> (colorOrNextId & 0x1f) & 1) == 0)) {
            *(int *)(chunkOrBitsetOrCount + 0x260) = *(int *)(chunkOrBitsetOrCount + 0x260) + 1;
            if (*(int *)(maxColorUsed + byteOffset) < (int)(colorOrNextId + 1)) {
              *(uint *)(maxColorUsed + byteOffset) = colorOrNextId + 1;
            }
            goto code_r0x00136cac;
          }
          nextIdOrAffinityIndex = nextIdOrAffinityIndex + 1;
        } while (nodeIdOrBitsetWords != nextIdOrAffinityIndex);
      }
      chunkOrBitsetOrCount = *workSlot;
      programOrNodeRecord = *(int *)(chunkOrBitsetOrCount + 4);
      if (programOrNodeRecord == 0) {
code_r0x00136bb8:
        programOrClassOffset = *(int *)(colorGraph + 0x2c);
        if ((*(uint *)(*(int *)(programOrClassOffset + 0x30c) + 8) & 0x8000) == 0) {
code_r0x00136be0:
          Compiler__fail(programOrClassOffset,4);
        }
        else {
          programOrClassOffset = Compiler__isOptionEnabled(programOrClassOffset,0x48);
          if (programOrClassOffset == 0) {
            programOrClassOffset = *(int *)(colorGraph + 0x2c);
            goto code_r0x00136be0;
          }
          vectorHeader = *(uint **)(colorGraph + 4);
          uncolorableCount = uncolorableCount + 1;
          if (nodeOrCount < *vectorHeader) {
            nodeIdOrBitsetWords = vectorHeader[1];
            if (nodeIdOrBitsetWords <= nodeOrCount) {
              _memset(nodeIdOrBitsetWords * 4 + vectorHeader[2],0,(nodeOrCount - nodeIdOrBitsetWords) * 4 + 4);
              vectorHeader[1] = nodeOrCount + 1;
            }
            elementRef = (int *)(nodeOrCount * 4 + vectorHeader[2]);
          }
          else {
            elementRef = (int *)Vector__elementRefGrow(vectorHeader,nodeOrCount);
          }
          if (*(int *)(*elementRef + 0x18) == 0) {
            programOrClassOffset = (nodeOrCount >> 3 & 0x1ffffffc) + *(int *)(colorGraph + 0x24);
            *(uint *)(programOrClassOffset + 8) = 1 << (nodeOrCount & 0x1f) | *(uint *)(programOrClassOffset + 8);
          }
        }
      }
      else {
        if ((*(uint *)(chunkOrBitsetOrCount + 8) & 1) == 0) {
          colorOrNextId = 0;
          chunkOrBitsetOrCount = 1;
        }
        else {
          colorOrNextId = 0;
          do {
            nodeIdOrBitsetWords = colorOrNextId;
            colorOrNextId = nodeIdOrBitsetWords + 1;
            programOrNodeRecord = programOrNodeRecord + -1;
            if (programOrNodeRecord == 0) goto code_r0x00136bb8;
          } while ((*(uint *)((colorOrNextId >> 3 & 0x1ffffffc) + chunkOrBitsetOrCount + 8) >> (colorOrNextId & 0x1f) & 1) != 0)
          ;
          if (colorOrNextId == 0xffffffff) goto code_r0x00136bb8;
          chunkOrBitsetOrCount = nodeIdOrBitsetWords + 2;
        }
        programOrNodeRecord = nodeOrCount << 2;
        if (*(int *)(maxColorUsed + byteOffset) < chunkOrBitsetOrCount) {
          *(int *)(maxColorUsed + byteOffset) = chunkOrBitsetOrCount;
        }
code_r0x00136cac:
        *(uint *)(programOrNodeRecord + *(int *)(*(int *)(colorGraph + 0x28) + 0x458)) = colorOrNextId;
        Program__markHwRegUsed(*(int *)(colorGraph + 0x28),
                     colorOrNextId + *(int *)(programOrClassOffset + *(int *)(colorGraph + 0x28) + 0x43c));
      }
    }
    programOrClassOffset = *(int *)((int)simplifiedStacks + byteOffset);
    if (programOrClassOffset != 0) {
      Arena__free(*(undefined4 *)(programOrClassOffset + 0xc),*(undefined4 *)(programOrClassOffset + 8));
      Arena__free(*(undefined4 *)(programOrClassOffset + -4),programOrClassOffset + -4);
    }
    programOrClassOffset = *(int *)(usedColorBits + byteOffset);
    if (programOrClassOffset != 0) {
      Arena__free(*(undefined4 *)(programOrClassOffset + -4),programOrClassOffset + -4);
    }
    classIndexOrNodeCount = classIndexOrNodeCount + 1;
    byteOffset = byteOffset + 4;
    if (registerClassCount != classIndexOrNodeCount) {
      simplifiedStackSlot = (int *)((int)simplifiedStacks + byteOffset);
      elementRef = (int *)((int)classNodeCount + byteOffset);
      goto code_r0x001367c0;
    }
  }
  *(undefined4 *)(*(int *)(colorGraph + 0x28) + 0x470) = *(undefined4 *)(colorGraph + 0xc);
  classIndexOrNodeCount = *(int *)(colorGraph + 8);
  registerClassCount = *(int *)(colorGraph + 0xc);
  if (classIndexOrNodeCount < registerClassCount) {
    byteOffset = classIndexOrNodeCount << 2;
    do {
      classIndexOrNodeCount = classIndexOrNodeCount + 1;
      registerClassCount = *(int *)(*(int *)(colorGraph + 0x28) + 0x458);
      *(undefined4 *)(registerClassCount + byteOffset) =
           *(undefined4 *)(*(int *)(*(int *)(colorGraph + 0x20) + byteOffset) * 4 + registerClassCount);
      byteOffset = byteOffset + 4;
      registerClassCount = *(int *)(colorGraph + 0xc);
    } while (classIndexOrNodeCount < registerClassCount);
  }
  if (0 < registerClassCount) {
    classIndexOrNodeCount = 0;
    do {
      registerClassCount = classIndexOrNodeCount * 4;
      classIndexOrNodeCount = classIndexOrNodeCount + 1;
      byteOffset = *(int *)(*(int *)(colorGraph + 0x28) + 0x458);
      *(int *)(registerClassCount + byteOffset) =
           *(int *)(registerClassCount + byteOffset) +
           *(int *)(*(int *)(*(int *)(*(int *)(colorGraph + 0x28) + 0x45c) + registerClassCount) * 4 +
                   *(int *)(colorGraph + 0x10));
    } while (classIndexOrNodeCount < *(int *)(colorGraph + 0xc));
  }
  Program__beginPass(*(undefined4 *)(colorGraph + 0x28),(int)"color_graph");
  Arena__free(*(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378),classNodeCount);
  Arena__free(*(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378),usedColorBits);
  Arena__free(*(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378),simplifiedStacks);
  Arena__free(*(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378),lowDegreeWorklists);
  Arena__free(*(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378),hwRegsPerClass);
  Arena__free(*(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378),maxColorUsed);
  Arena__free(*(undefined4 *)(*(int *)(colorGraph + 0x2c) + 0x378),colorLimit);
  return 0 < uncolorableCount;
}

/* FUN_00136ec4 @ 0x136ec4 (152 bytes) */
int FUN_00136ec4(this, ownerArg, nodeCount, ownerArg4, compiler)
  int *this;
  int ownerArg;
  int nodeCount;
  int ownerArg4;
  int compiler;
{
  uint edgeBitsetWordCount;
  uint nodePairProduct;
  undefined4 *tableAlloc;
  undefined4 *edgeBitsetWords;
  undefined4 *tableWordCursor;
  int classByteOffset;
  int compilerObj;
  int classArrayB;
  int wordCountdown;
  int edgeBitCount;
  int nodeCountNow;
  undefined4 *allocation;
  int allocation2;
  int loopIndex2;
  int loopIndex;
  int iVar1;
  undefined4 *bitsetClearCursor;
  undefined4 *nodeSlotRef;
  int classArrayBytes;
  uint *nodeVector;
  undefined4 arena;
  uint nodeVectorCount;
  
  this[2] = ownerArg;
  this[10] = ownerArg4;
  *this = 0;
  this[3] = nodeCount;
  this[0xb] = compiler;
  if (nodeCount != 0) {
    allocation2 = Arena__alloc(*(undefined4 *)(compiler + COMP_arenaB),nodeCount << 2);
    this[8] = allocation2;
    arena = *(undefined4 *)(this[0xb] + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    *allocation = arena;
    allocation[1] = 2;
    allocation[2] = 0;
    allocation[4] = arena;
    arena = Arena__alloc(arena,8);
    allocation[3] = arena;
    loopIndex2 = 0;
    nodeCountNow = this[3];
    this[1] = (int)(allocation + 1);
    if (0 < nodeCountNow) {
      do {
        nodeVector = (uint *)this[1];
        arena = *(undefined4 *)(this[0xb] + 0x378);
        allocation = (undefined4 *)Arena__alloc(arena,0x28);
        *allocation = arena;
        ((int (*)())FUN_001351c4)(allocation + 1,loopIndex2,0,this,this[0xb]);
        nodeVectorCount = nodeVector[1];
        if (nodeVectorCount < *nodeVector) {
          _memset((void *)(nodeVectorCount * 4 + nodeVector[2]),0,4);
          nodeSlotRef = (undefined4 *)(nodeVectorCount * 4 + nodeVector[2]);
          nodeVector[1] = nodeVectorCount + 1;
        }
        else {
          nodeSlotRef = (undefined4 *)Vector__elementRefGrow(nodeVector,nodeVectorCount);
        }
        *nodeSlotRef = allocation + 1;
        loopIndex2 = loopIndex2 + 1;
        nodeCountNow = this[3];
      } while (loopIndex2 < nodeCountNow);
    }
    arena = *(undefined4 *)(this[0xb] + 0x378);
    nodePairProduct = nodeCountNow * nodeCountNow - nodeCountNow;
    edgeBitCount = ((int)nodePairProduct >> 1) + (uint)((int)nodePairProduct < 0 && (nodePairProduct & 1) != 0);
    edgeBitsetWordCount = edgeBitCount + 0x1fU >> 5;
    allocation = (undefined4 *)Arena__alloc(arena,edgeBitsetWordCount * 4 + 0xc);
    edgeBitsetWords = allocation + 1;
    *allocation = arena;
    allocation[1] = edgeBitsetWordCount;
    allocation[2] = edgeBitCount;
    if (edgeBitsetWordCount != 0) {
      bitsetClearCursor = edgeBitsetWords;
      if (edgeBitsetWordCount == 0) {
        edgeBitsetWordCount = 1;
      }
      do {
        bitsetClearCursor[2] = 0;
        bitsetClearCursor = bitsetClearCursor + 1;
        edgeBitsetWordCount = edgeBitsetWordCount - 1;
      } while (edgeBitsetWordCount != 0);
    }
    *this = (int)edgeBitsetWords;
    iVar1 = *(int *)(*(int *)(this[0xb] + 0x30c) + 0x14) << 2;
    classArrayBytes = Arena__alloc(*(undefined4 *)(this[0xb] + 0x378),iVar1);
    this[4] = classArrayBytes;
    (**(code **)(**(int **)(this[0xb] + 0x30c) + 0x134))(*(int **)(this[0xb] + 0x30c),classArrayBytes);
    classArrayB = Arena__alloc(*(undefined4 *)(this[0xb] + 0x378),iVar1);
    this[6] = classArrayB;
    allocation2 = Arena__alloc(*(undefined4 *)(this[0xb] + 0x378),iVar1);
    compilerObj = this[0xb];
    this[5] = allocation2;
    if (0 < *(int *)(*(int *)(compilerObj + 0x30c) + 0x14)) {
      loopIndex = 0;
      do {
        classByteOffset = loopIndex * 4;
        loopIndex = loopIndex + 1;
        *(undefined4 *)(this[6] + classByteOffset) = 0;
        *(undefined4 *)(this[5] + classByteOffset) = 0;
        compilerObj = this[0xb];
      } while (loopIndex < *(int *)(*(int *)(compilerObj + 0x30c) + 0x14));
    }
    arena = *(undefined4 *)(compilerObj + 0x378);
    tableAlloc = (undefined4 *)Arena__alloc(arena,0x20c);
    tableAlloc[1] = 0x80;
    wordCountdown = 0x80;
    *tableAlloc = arena;
    tableAlloc[2] = 0x1000;
    tableWordCursor = tableAlloc + 1;
    do {
      tableWordCursor[2] = 0;
      tableWordCursor = tableWordCursor + 1;
      wordCountdown = wordCountdown + -1;
    } while (wordCountdown != 0);
    this[9] = (int)(tableAlloc + 1);
  }
  return;
}

/* FUN_0013719c @ 0x13719c (152 bytes) */
int FUN_0013719c(this, ownerArg, nodeCount, ownerArg4, compiler)
  int *this;
  int ownerArg;
  int nodeCount;
  int ownerArg4;
  int compiler;
{
  uint edgeBitsetWordCount;
  uint nodePairProduct;
  undefined4 *tableAlloc;
  undefined4 *edgeBitsetWords;
  undefined4 *tableWordCursor;
  int classByteOffset;
  int compilerObj;
  int classArrayB;
  int wordCountdown;
  int edgeBitCount;
  int nodeCountNow;
  undefined4 *allocation;
  int allocation2;
  int loopIndex2;
  int loopIndex;
  int iVar1;
  undefined4 *bitsetClearCursor;
  undefined4 *nodeSlotRef;
  int classArrayBytes;
  uint *nodeVector;
  undefined4 arena;
  uint nodeVectorCount;
  
  this[2] = ownerArg;
  this[10] = ownerArg4;
  *this = 0;
  this[3] = nodeCount;
  this[0xb] = compiler;
  if (nodeCount != 0) {
    allocation2 = Arena__alloc(*(undefined4 *)(compiler + COMP_arenaB),nodeCount << 2);
    this[8] = allocation2;
    arena = *(undefined4 *)(this[0xb] + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    *allocation = arena;
    allocation[1] = 2;
    allocation[2] = 0;
    allocation[4] = arena;
    arena = Arena__alloc(arena,8);
    allocation[3] = arena;
    loopIndex2 = 0;
    nodeCountNow = this[3];
    this[1] = (int)(allocation + 1);
    if (0 < nodeCountNow) {
      do {
        nodeVector = (uint *)this[1];
        arena = *(undefined4 *)(this[0xb] + 0x378);
        allocation = (undefined4 *)Arena__alloc(arena,0x28);
        *allocation = arena;
        ((int (*)())FUN_001351c4)(allocation + 1,loopIndex2,0,this,this[0xb]);
        nodeVectorCount = nodeVector[1];
        if (nodeVectorCount < *nodeVector) {
          _memset((void *)(nodeVectorCount * 4 + nodeVector[2]),0,4);
          nodeSlotRef = (undefined4 *)(nodeVectorCount * 4 + nodeVector[2]);
          nodeVector[1] = nodeVectorCount + 1;
        }
        else {
          nodeSlotRef = (undefined4 *)Vector__elementRefGrow(nodeVector,nodeVectorCount);
        }
        *nodeSlotRef = allocation + 1;
        loopIndex2 = loopIndex2 + 1;
        nodeCountNow = this[3];
      } while (loopIndex2 < nodeCountNow);
    }
    arena = *(undefined4 *)(this[0xb] + 0x378);
    nodePairProduct = nodeCountNow * nodeCountNow - nodeCountNow;
    edgeBitCount = ((int)nodePairProduct >> 1) + (uint)((int)nodePairProduct < 0 && (nodePairProduct & 1) != 0);
    edgeBitsetWordCount = edgeBitCount + 0x1fU >> 5;
    allocation = (undefined4 *)Arena__alloc(arena,edgeBitsetWordCount * 4 + 0xc);
    edgeBitsetWords = allocation + 1;
    *allocation = arena;
    allocation[1] = edgeBitsetWordCount;
    allocation[2] = edgeBitCount;
    if (edgeBitsetWordCount != 0) {
      bitsetClearCursor = edgeBitsetWords;
      if (edgeBitsetWordCount == 0) {
        edgeBitsetWordCount = 1;
      }
      do {
        bitsetClearCursor[2] = 0;
        bitsetClearCursor = bitsetClearCursor + 1;
        edgeBitsetWordCount = edgeBitsetWordCount - 1;
      } while (edgeBitsetWordCount != 0);
    }
    *this = (int)edgeBitsetWords;
    iVar1 = *(int *)(*(int *)(this[0xb] + 0x30c) + 0x14) << 2;
    classArrayBytes = Arena__alloc(*(undefined4 *)(this[0xb] + 0x378),iVar1);
    this[4] = classArrayBytes;
    (**(code **)(**(int **)(this[0xb] + 0x30c) + 0x134))(*(int **)(this[0xb] + 0x30c),classArrayBytes);
    classArrayB = Arena__alloc(*(undefined4 *)(this[0xb] + 0x378),iVar1);
    this[6] = classArrayB;
    allocation2 = Arena__alloc(*(undefined4 *)(this[0xb] + 0x378),iVar1);
    compilerObj = this[0xb];
    this[5] = allocation2;
    if (0 < *(int *)(*(int *)(compilerObj + 0x30c) + 0x14)) {
      loopIndex = 0;
      do {
        classByteOffset = loopIndex * 4;
        loopIndex = loopIndex + 1;
        *(undefined4 *)(this[6] + classByteOffset) = 0;
        *(undefined4 *)(this[5] + classByteOffset) = 0;
        compilerObj = this[0xb];
      } while (loopIndex < *(int *)(*(int *)(compilerObj + 0x30c) + 0x14));
    }
    arena = *(undefined4 *)(compilerObj + 0x378);
    tableAlloc = (undefined4 *)Arena__alloc(arena,0x20c);
    tableAlloc[1] = 0x80;
    wordCountdown = 0x80;
    *tableAlloc = arena;
    tableAlloc[2] = 0x1000;
    tableWordCursor = tableAlloc + 1;
    do {
      tableWordCursor[2] = 0;
      tableWordCursor = tableWordCursor + 1;
      wordCountdown = wordCountdown + -1;
    } while (wordCountdown != 0);
    this[9] = (int)(tableAlloc + 1);
  }
  return;
}

/* FUN_00137474 @ 0x137474 (428 bytes) */
int FUN_00137474(this)
  int *this;
{
  int oldNodeArray;
  int copyByteOffset;
  int newBitsetWordAddr;
  int copyCountdown;
  int newNodeArray;
  int edgeBitCount;
  uint nodeVectorCount;
  uint edgeWordCount;
  undefined4 *allocation;
  uint loopIndex;
  uint nodePairProduct;
  undefined4 *bitsetClearCursor;
  int *nodeSlotRef;
  int newNodeCount;
  int nodeCountNow;
  undefined4 *newEdgeBitset;
  uint pairWordOffset;
  int oldNodeCount;
  int oldEdgeBitset;
  undefined4 arena;
  uint *nodeVector;
  
  oldNodeCount = this[3];
  newNodeCount = oldNodeCount + 1;
  oldEdgeBitset = *this;
  this[3] = newNodeCount;
  arena = *(undefined4 *)(this[0xb] + 0x378);
  nodePairProduct = newNodeCount * newNodeCount - newNodeCount;
  edgeBitCount = ((int)nodePairProduct >> 1) + (uint)((int)nodePairProduct < 0 && (nodePairProduct & 1) != 0);
  edgeWordCount = edgeBitCount + 0x1fU >> 5;
  allocation = (undefined4 *)Arena__alloc(arena,edgeWordCount * 4 + 0xc);
  newEdgeBitset = allocation + 1;
  *allocation = arena;
  allocation[1] = edgeWordCount;
  allocation[2] = edgeBitCount;
  if (edgeWordCount != 0) {
    bitsetClearCursor = newEdgeBitset;
    if (edgeWordCount == 0) {
      edgeWordCount = 1;
    }
    do {
      bitsetClearCursor[2] = 0;
      bitsetClearCursor = bitsetClearCursor + 1;
      edgeWordCount = edgeWordCount - 1;
    } while (edgeWordCount != 0);
  }
  nodeCountNow = this[3];
  *this = (int)newEdgeBitset;
  if (0 < (edgeBitCount - nodeCountNow) + 1) {
    loopIndex = 0;
    do {
      pairWordOffset = loopIndex >> 3 & 0x1ffffffc;
      if ((*(uint *)(pairWordOffset + oldEdgeBitset + 8) >> (loopIndex & 0x1f) & 1) != 0) {
        newBitsetWordAddr = pairWordOffset + *this;
        *(uint *)(newBitsetWordAddr + 8) = 1 << (loopIndex & 0x1f) | *(uint *)(newBitsetWordAddr + 8);
        nodeCountNow = this[3];
      }
      loopIndex = loopIndex + 1;
    } while ((int)loopIndex < (edgeBitCount - nodeCountNow) + 1);
  }
  if (oldEdgeBitset != 0) {
    Arena__free(*(undefined4 *)(oldEdgeBitset + -4),oldEdgeBitset + -4);
    nodeCountNow = this[3];
  }
  oldNodeArray = this[8];
  newNodeArray = Arena__alloc(*(undefined4 *)(this[0xb] + 0x378),nodeCountNow << 2);
  this[8] = newNodeArray;
  if (0 < oldNodeCount) {
    copyByteOffset = 0;
    copyCountdown = oldNodeCount;
    do {
      *(undefined4 *)(copyByteOffset + this[8]) = *(undefined4 *)(oldNodeArray + copyByteOffset);
      copyByteOffset = copyByteOffset + 4;
      copyCountdown = copyCountdown + -1;
    } while (copyCountdown != 0);
  }
  Arena__free(*(undefined4 *)(this[0xb] + 0x378),oldNodeArray);
  nodeVector = (uint *)this[1];
  arena = *(undefined4 *)(this[0xb] + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x28);
  *allocation = arena;
  ((int (*)())FUN_001351c4)(allocation + 1,oldNodeCount,0,this,this[0xb]);
  nodeVectorCount = nodeVector[1];
  if (nodeVectorCount < *nodeVector) {
    _memset((void *)(nodeVectorCount * 4 + nodeVector[2]),0,4);
    nodeSlotRef = (int *)(nodeVectorCount * 4 + nodeVector[2]);
    nodeVector[1] = nodeVectorCount + 1;
  }
  else {
    nodeSlotRef = (int *)Vector__elementRefGrow(nodeVector,nodeVectorCount);
  }
  *nodeSlotRef = (int)(allocation + 1);
  return;
}

/* FUN_00137694 @ 0x137694 (456 bytes) */
int FUN_00137694(this, extraNodeCount)
  int *this;
  int extraNodeCount;
{
  uint nodeVectorCount;
  uint pairBitIndex;
  uint edgeWordCount;
  int oldNodeArray;
  int copyCountdown;
  int newNodeArray;
  int rowNode;
  int edgeBitCount;
  undefined4 *allocation;
  int loopIndex;
  int newBitsetWordAddr;
  undefined4 *bitsetClearCursor;
  int *nodeSlotRef;
  int newNodeCount;
  undefined4 *newEdgeBitset;
  uint pairWordOffset;
  int oldEdgeBitset;
  int oldNodeCount;
  undefined4 arena;
  uint *nodeVector;
  uint nodePairProduct;
  int copyByteOffset;
  
  oldNodeCount = this[3];
  newNodeCount = oldNodeCount + extraNodeCount;
  oldEdgeBitset = *this;
  this[3] = newNodeCount;
  arena = *(undefined4 *)(this[0xb] + 0x378);
  nodePairProduct = newNodeCount * newNodeCount - newNodeCount;
  edgeBitCount = ((int)nodePairProduct >> 1) + (uint)((int)nodePairProduct < 0 && (nodePairProduct & 1) != 0);
  edgeWordCount = edgeBitCount + 0x1fU >> 5;
  allocation = (undefined4 *)Arena__alloc(arena,edgeWordCount * 4 + 0xc);
  newEdgeBitset = allocation + 1;
  *allocation = arena;
  allocation[1] = edgeWordCount;
  allocation[2] = edgeBitCount;
  if (edgeWordCount != 0) {
    bitsetClearCursor = newEdgeBitset;
    if (edgeWordCount == 0) {
      edgeWordCount = 1;
    }
    do {
      bitsetClearCursor[2] = 0;
      bitsetClearCursor = bitsetClearCursor + 1;
      edgeWordCount = edgeWordCount - 1;
    } while (edgeWordCount != 0);
  }
  *this = (int)newEdgeBitset;
  if (0 < oldNodeCount) {
    rowNode = 0;
    while (rowNode = rowNode + 1, oldNodeCount != rowNode) {
      if (0 < rowNode) {
        loopIndex = 0;
        do {
          pairBitIndex = ((int (*)())pairIndex)(this,loopIndex,rowNode);
          pairWordOffset = pairBitIndex >> 3 & 0x1ffffffc;
          if ((*(uint *)(pairWordOffset + oldEdgeBitset + 8) >> (pairBitIndex & 0x1f) & 1) != 0) {
            newBitsetWordAddr = pairWordOffset + *this;
            *(uint *)(newBitsetWordAddr + 8) = 1 << (pairBitIndex & 0x1f) | *(uint *)(newBitsetWordAddr + 8);
          }
          loopIndex = loopIndex + 1;
        } while (rowNode != loopIndex);
      }
    }
  }
  oldNodeArray = this[8];
  newNodeArray = Arena__alloc(*(undefined4 *)(this[0xb] + 0x378),this[3] << 2);
  this[8] = newNodeArray;
  if (0 < oldNodeCount) {
    copyByteOffset = 0;
    copyCountdown = oldNodeCount;
    do {
      *(undefined4 *)(copyByteOffset + this[8]) = *(undefined4 *)(oldNodeArray + copyByteOffset);
      copyByteOffset = copyByteOffset + 4;
      copyCountdown = copyCountdown + -1;
    } while (copyCountdown != 0);
  }
  Arena__free(*(undefined4 *)(this[0xb] + 0x378),oldNodeArray);
  if (oldNodeCount < this[3]) {
    do {
      nodeVector = (uint *)this[1];
      arena = *(undefined4 *)(this[0xb] + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,0x28);
      *allocation = arena;
      ((int (*)())FUN_001351c4)(allocation + 1,oldNodeCount,0,this,this[0xb]);
      nodeVectorCount = nodeVector[1];
      if (nodeVectorCount < *nodeVector) {
        _memset((void *)(nodeVectorCount * 4 + nodeVector[2]),0,4);
        nodeSlotRef = (int *)(nodeVectorCount * 4 + nodeVector[2]);
        nodeVector[1] = nodeVectorCount + 1;
      }
      else {
        nodeSlotRef = (int *)Vector__elementRefGrow(nodeVector,nodeVectorCount);
      }
      *nodeSlotRef = (int)(allocation + 1);
      oldNodeCount = oldNodeCount + 1;
    } while (oldNodeCount < this[3]);
  }
  return;
}

/* FUN_001378e8 @ 0x1378e8 (1420 bytes) */
int FUN_001378e8(regInfoOwner, pass)
  int regInfoOwner;
  int pass;
{
  uint regInfoCount;
  int operandNumberB;
  int useWeight;
  int operandNumberA;
  int instQuery40;
  uint sourceRegister;
  uint destRegister;
  int *regInfoRef;
  int *inst;
  int loopDepthWeight;
  int sourceDef;
  int *operandVReg;
  int *nextInstLink;
  uint instFlags;
  int copySource;
  uint clearedFlags;
  int *operandCursor;
  int iVar6;
  int nextBlock;
  int block;
  int *instListHead;
  uint *regInfoVector;
  
  block = *(int *)(*(int *)(pass + 0x6c4) + 900);
  nextBlock = *(int *)(block + 8);
  do {
    if (nextBlock == 0) {
      return;
    }
    nextInstLink = (int *)(*(int **)(block + 0xa0))[1];
    instListHead = *(int **)(block + 0xa0);
    if (nextInstLink != (int *)0x0) {
      do {
        operandCursor = nextInstLink;
        if (((instListHead == *(int **)(block + 0x98)) || ((operandCursor[5] & 4U) == 0)) &&
           (loopDepthWeight = *(int *)(block + 0xb8), instListHead != (int *)0x0)) {
          inst = instListHead;
          do {
            instFlags = inst[5];
            if ((instFlags & 1) != 0) {
              copySource = (**(code **)(*inst + 0x7c))(inst);
              if (copySource == 0) {
                if (((inst[0x20] != 0) && (copySource = RegKind__flagBit0(inst[0x26]), copySource != 0)) &&
                   (((inst[5] & 2U) == 0 &&
                    (copySource = (**(code **)(*inst + 0x50))(inst), copySource == 0)))) {
                  destRegister = inst[0x25];
                  instQuery40 = (**(code **)(*inst + 0x40))(inst);
                  if ((instQuery40 == 0) && (instQuery40 = (**(code **)(*inst + 0x28))(inst), instQuery40 == 0)) {
                    inst[5] = inst[5] | 0x20000000;
                    operandCursor = inst;
                    for (operandNumberA = 1; iVar6 = (**(code **)(*inst + 0x14))(inst), operandNumberA <= iVar6;
                        operandNumberA = operandNumberA + 1) {
                      if ((operandNumberA < 1) || (iVar6 = IRInst__getOperandSource(inst,operandNumberA), iVar6 == 0)) {
                        iVar6 = operandCursor[0x2c];
                      }
                      else {
                        sourceDef = IRInst__getOperandSource(inst,operandNumberA);
                        iVar6 = *(int *)(sourceDef + 0x98);
                      }
                      iVar6 = RegKind__flagBit6(iVar6);
                      if (iVar6 == 0) {
LAB_00137af8:
                        clearedFlags = inst[5] & 0xdfffffff;
                        inst[5] = clearedFlags;
                        goto LAB_00137b2c;
                      }
                      IRInst__getOperandRecord(inst,operandNumberA);
                      operandCursor = operandCursor + 6;
                      iVar6 = IRInst__operandKindClass(inst,operandNumberA);
                      if (iVar6 != 0) goto LAB_00137af8;
                    }
                    clearedFlags = inst[5];
                  }
                  else {
                    regInfoVector = *(uint **)(regInfoOwner + 4);
                    if (destRegister < *regInfoVector) {
                      regInfoCount = regInfoVector[1];
                      if (regInfoCount <= destRegister) {
                        _memset(regInfoCount * 4 + regInfoVector[2],0,(destRegister - regInfoCount) * 4 + 4);
                        regInfoVector[1] = destRegister + 1;
                      }
                      regInfoRef = (int *)(destRegister * 4 + regInfoVector[2]);
                    }
                    else {
                      regInfoRef = (int *)Vector__elementRefGrow(regInfoVector,destRegister);
                    }
                    *(undefined4 *)(*regInfoRef + 0x20) = 0;
                    clearedFlags = inst[5];
                  }
LAB_00137b2c:
                  if ((clearedFlags & 0x20000000) != 0) {
                    regInfoVector = *(uint **)(regInfoOwner + 4);
                    if (destRegister < *regInfoVector) {
                      regInfoCount = regInfoVector[1];
                      if (regInfoCount <= destRegister) {
                        _memset(regInfoCount * 4 + regInfoVector[2],0,(destRegister - regInfoCount) * 4 + 4);
                        regInfoVector[1] = destRegister + 1;
                      }
                      regInfoRef = (int *)(destRegister * 4 + regInfoVector[2]);
                    }
                    else {
                      regInfoRef = (int *)Vector__elementRefGrow(regInfoVector,destRegister);
                    }
                    *(undefined4 *)(*regInfoRef + 0x20) = 1;
                  }
                  regInfoVector = *(uint **)(regInfoOwner + 4);
                  if (destRegister < *regInfoVector) {
                    regInfoCount = regInfoVector[1];
                    if (regInfoCount <= destRegister) {
                      _memset(regInfoCount * 4 + regInfoVector[2],0,(destRegister - regInfoCount) * 4 + 4);
                      regInfoVector[1] = destRegister + 1;
                    }
                    regInfoRef = (int *)(destRegister * 4 + regInfoVector[2]);
                  }
                  else {
                    regInfoRef = (int *)Vector__elementRefGrow(regInfoVector,destRegister);
                  }
                  if (*(int *)(*regInfoRef + 0x18) == 0) {
                    useWeight = 0;
                    if (((inst[5] & 0x20000000U) == 0) &&
                       (useWeight = loopDepthWeight * 100, (inst[5] & 0x40U) != 0)) {
                      useWeight = 0x7fffffff;
                    }
                    regInfoVector = *(uint **)(regInfoOwner + 4);
                    if (destRegister < *regInfoVector) {
                      regInfoCount = regInfoVector[1];
                      if (regInfoCount <= destRegister) {
                        _memset(regInfoCount * 4 + regInfoVector[2],0,(destRegister - regInfoCount) * 4 + 4);
                        regInfoVector[1] = destRegister + 1;
                      }
                      regInfoRef = (int *)(destRegister * 4 + regInfoVector[2]);
                    }
                    else {
                      regInfoRef = (int *)Vector__elementRefGrow(regInfoVector,destRegister);
                    }
                    *(int *)(*regInfoRef + 0x1c) = useWeight + *(int *)(*regInfoRef + 0x1c);
                  }
                }
                for (operandNumberB = 1; iVar6 = (**(code **)(*inst + 0x14))(inst), operandNumberB <= iVar6;
                    operandNumberB = operandNumberB + 1) {
                  operandVReg = (int *)IRInst__getOperandSource(inst,operandNumberB);
                  sourceRegister = operandVReg[0x25];
                  if ((((operandVReg[0x20] != 0) && (iVar6 = RegKind__flagBit0(operandVReg[0x26]), iVar6 != 0)) &&
                      ((operandVReg[5] & 2U) == 0)) &&
                     (iVar6 = (**(code **)(*operandVReg + 0x50))(operandVReg), iVar6 == 0)) {
                    regInfoVector = *(uint **)(regInfoOwner + 4);
                    if (sourceRegister < *regInfoVector) {
                      regInfoCount = regInfoVector[1];
                      if (regInfoCount <= sourceRegister) {
                        _memset(regInfoCount * 4 + regInfoVector[2],0,(sourceRegister - regInfoCount) * 4 + 4);
                        regInfoVector[1] = sourceRegister + 1;
                      }
                      regInfoRef = (int *)(sourceRegister * 4 + regInfoVector[2]);
                    }
                    else {
                      regInfoRef = (int *)Vector__elementRefGrow(regInfoVector,sourceRegister);
                    }
                    if (*(int *)(*regInfoRef + 0x18) == 0) {
                      regInfoVector = *(uint **)(regInfoOwner + 4);
                      if (sourceRegister < *regInfoVector) {
                        regInfoCount = regInfoVector[1];
                        if (regInfoCount <= sourceRegister) {
                          _memset(regInfoCount * 4 + regInfoVector[2],0,(sourceRegister - regInfoCount) * 4 + 4);
                          regInfoVector[1] = sourceRegister + 1;
                        }
                        regInfoRef = (int *)(sourceRegister * 4 + regInfoVector[2]);
                      }
                      else {
                        regInfoRef = (int *)Vector__elementRefGrow(regInfoVector,sourceRegister);
                      }
                      *(int *)(*regInfoRef + 0x1c) = loopDepthWeight + *(int *)(*regInfoRef + 0x1c);
                    }
                  }
                }
              }
              instFlags = inst[5];
            }
            inst = (int *)inst[2];
          } while ((inst != (int *)0x0) && ((instFlags & 4) != 0));
          operandCursor = (int *)instListHead[1];
        }
        nextInstLink = (int *)operandCursor[1];
        instListHead = operandCursor;
      } while ((int *)operandCursor[1] != (int *)0x0);
      nextBlock = *(int *)(block + 8);
    }
    block = nextBlock;
    nextBlock = *(int *)(nextBlock + 8);
  } while( true );
}

/* BitSet__testRegisterLane @ 0x137e74 (36 bytes) */
int BitSet__testRegisterLane(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = param_2 * 4 + param_3;
  return *(uint *)((uVar1 >> 3 & 0x1ffffffc) + param_1 + 8) >> (uVar1 & 0x1f) & 1;
}

/* FUN_00137e98 @ 0x137e98 (124 bytes) */
int FUN_00137e98(inst, operandIndex, param_3)
  undefined4 inst;
  undefined4 operandIndex;
  uint param_3;
{
  uint uVar1;
  uint operandVReg;
  
  operandVReg = IRInst__getOperandSource(inst,operandIndex);
  uVar1 = param_3;
  while( true ) {
    if (uVar1 == 0) {
      return 0;
    }
    if (((*(uint *)(param_3 + 0x14) & 1) != 0) && (param_3 == operandVReg)) break;
    param_3 = *(uint *)(param_3 + 4);
    uVar1 = *(uint *)(param_3 + 0x14) & 4;
    if (param_3 == 0) {
      return 0;
    }
  }
  return 1;
}

/* FUN_00137f14 @ 0x137f14 (364 bytes) */
int FUN_00137f14(liveness, inst, liveBits)
  int liveness;
  int *inst;
  int liveBits;
{
  int copyLiveOutWordAddr;
  uint copySourceRegisterId;
  int copySourceVReg;
  int instQuery78;
  int defBitWordAddr;
  int operandCountdown;
  int liveOutWordAddr;
  int *operandSlotCursor;
  uint sourceRegisterId;
  uint bitWordOffset;
  int sourceVReg;
  
  operandCountdown = inst[0x21];
  if (0 < operandCountdown) {
    operandSlotCursor = inst + operandCountdown * 6 + 0x23;
    do {
      sourceVReg = *operandSlotCursor;
      sourceRegisterId = *(uint *)(sourceVReg + 0x1c);
      if ((int)sourceRegisterId < 0) {
        if (*(int *)(sourceVReg + 4) == 0x2c) {
          *(undefined4 *)(liveness + 0x3b4) = 1;
          *(uint *)(sourceVReg + 0x24) = *(uint *)(sourceVReg + 0x24) | 1;
        }
      }
      else {
        bitWordOffset = sourceRegisterId >> 3 & 0x1ffffffc;
        if ((*(uint *)(bitWordOffset + liveBits + 8) >> (sourceRegisterId & 0x1f) & 1) == 0) {
          liveOutWordAddr = bitWordOffset + *(int *)(liveness + 0x3b0);
          *(uint *)(liveOutWordAddr + 8) = 1 << (sourceRegisterId & 0x1f) | *(uint *)(liveOutWordAddr + 8);
          *(uint *)(sourceVReg + 0x24) = *(uint *)(sourceVReg + 0x24) | 1;
        }
      }
      operandSlotCursor = operandSlotCursor + -6;
      operandCountdown = operandCountdown + -1;
    } while (operandCountdown != 0);
  }
  if (((0 < inst[0x20]) && ((inst[5] & 2U) == 0)) &&
     (sourceRegisterId = *(uint *)(inst[0x23] + 0x1c), -1 < (int)sourceRegisterId)) {
    defBitWordAddr = (sourceRegisterId >> 3 & 0x1ffffffc) + liveBits;
    *(uint *)(defBitWordAddr + 8) = 1 << (sourceRegisterId & 0x1f) | *(uint *)(defBitWordAddr + 8);
  }
  instQuery78 = (**(code **)(*inst + 0x78))(inst);
  if (instQuery78 != 0) {
    copySourceVReg = inst[0x29];
    copySourceRegisterId = *(uint *)(copySourceVReg + 0x1c);
    if (-1 < (int)copySourceRegisterId) {
      copyLiveOutWordAddr = (copySourceRegisterId >> 3 & 0x1ffffffc) + *(int *)(liveness + 0x3b0);
      *(uint *)(copyLiveOutWordAddr + 8) = 1 << (copySourceRegisterId & 0x1f) | *(uint *)(copyLiveOutWordAddr + 8);
      *(uint *)(copySourceVReg + 0x24) = *(uint *)(copySourceVReg + 0x24) | 1;
    }
  }
  return;
}

/* FUN_00138080 @ 0x138080 (176 bytes) */
int FUN_00138080(param_1)
  int param_1;
{
  int listCount;
  int *piVar1;
  int iVar2;
  int loopIndex;
  int iVar4;
  
  loopIndex = 1;
  piVar1 = (int *)Program__getBlocksArray(param_1);
  while( true ) {
    piVar1 = piVar1 + 1;
    listCount = DList__count(param_1 + 0x37c);
    if (listCount < loopIndex) break;
    iVar4 = *piVar1;
    iVar2 = *(int *)(iVar4 + 0x108);
    if (iVar2 != 0) {
      Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
    }
    iVar2 = *(int *)(iVar4 + 0x100);
    *(undefined4 *)(iVar4 + 0x108) = 0;
    if (iVar2 != 0) {
      Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
    }
    iVar2 = *(int *)(iVar4 + 0x104);
    *(undefined4 *)(iVar4 + 0x100) = 0;
    if (iVar2 != 0) {
      Arena__free(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
    }
    *(undefined4 *)(iVar4 + 0x104) = 0;
    loopIndex = loopIndex + 1;
  }
  return;
}

/* FUN_00138130 @ 0x138130 (272 bytes) */
int FUN_00138130(liveness)
  int liveness;
{
  int block;
  int inst;
  int *tableWordCursor;
  int nextInstLink;
  undefined4 *allocation;
  int clearCountdown;
  int *liveTable;
  undefined4 arena;
  int initCountdown;
  
  arena = *(undefined4 *)(*(int *)(liveness + 8) + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x20c);
  liveTable = allocation + 1;
  allocation[1] = 0x80;
  initCountdown = 0x80;
  *allocation = arena;
  allocation[2] = 0x1000;
  clearCountdown = 0x80;
  tableWordCursor = liveTable;
  do {
    tableWordCursor[2] = 0;
    tableWordCursor = tableWordCursor + 1;
    initCountdown = initCountdown + -1;
  } while (initCountdown != 0);
  block = *(int *)(liveness + 900);
  if (*(int *)(block + 8) != 0) {
    while( true ) {
      if (clearCountdown != 0) {
        tableWordCursor = liveTable;
        if (clearCountdown == 0) {
          clearCountdown = 1;
        }
        do {
          tableWordCursor[2] = 0;
          tableWordCursor = tableWordCursor + 1;
          clearCountdown = clearCountdown + -1;
        } while (clearCountdown != 0);
      }
      inst = *(int *)(block + 0x98);
      for (nextInstLink = *(int *)(*(int *)(block + 0x98) + 8); nextInstLink != 0; nextInstLink = *(int *)(nextInstLink + 8)) {
        if ((*(uint *)(inst + 0x14) & 1) != 0) {
          ((int (*)())FUN_00137f14)(liveness,inst,liveTable);
          nextInstLink = *(int *)(inst + 8);
        }
        inst = nextInstLink;
      }
      block = *(int *)(block + 8);
      if (*(int *)(block + 8) == 0) break;
      clearCountdown = *liveTable;
    }
  }
  return;
}

/* FUN_00138240 @ 0x138240 (120 bytes) */
int FUN_00138240(inst, param_2)
  int inst;
  int param_2;
{
  int operandRecord;
  
  do {
    operandRecord = IRInst__getOperandRecord(inst,0);
    if (*(char *)(param_2 + operandRecord + 0x10) == '\0') {
      return 1;
    }
  } while (((*(uint *)(inst + 0x14) & 0x200) != 0) &&
          (inst = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84)), inst != 0));
  return 0;
}

/* FUN_001382b8 @ 0x1382b8 (216 bytes) */
int FUN_001382b8(inst, param_2, param_3)
  int *inst;
  uint param_2;
  uint *param_3;
{
  int operandRecord;
  int iVar1;
  uint uVar2;
  
  *param_3 = param_2;
LAB_001382d4:
  do {
    uVar2 = *param_3;
    operandRecord = IRInst__getOperandRecord(inst,0);
    if (*(char *)(uVar2 + operandRecord + 0x10) == '\0') {
      if ((inst[5] & 1U) != 0) {
        return inst;
      }
      iVar1 = (**(code **)(*inst + 100))(inst);
      if (iVar1 == 0) goto LAB_001382d4;
      uVar2 = *param_3;
      operandRecord = IRInst__getOperandRecord(inst,1);
      *param_3 = (uint)*(byte *)(uVar2 + operandRecord + 0x10);
      inst = (int *)IRInst__getOperandSource(inst,1);
    }
    else {
      if ((inst[5] & 0x200U) == 0) {
        return (int *)0x0;
      }
      inst = (int *)IRInst__getOperandSource(inst,inst[0x21]);
    }
    if (inst == (int *)0x0) {
      return (int *)0x0;
    }
  } while( true );
}

/* FUN_00138390 @ 0x138390 (772 bytes) */
int FUN_00138390(block, usedBits)
  int block;
  int usedBits;
{
  int *nextInstAdvance;
  int childLane;
  int childQuery60;
  int subBlock;
  int defLane;
  bool moreChildLanes;
  uint defBitIndex;
  uint usedBitIndex;
  int defBitWordAddr;
  int childBitWordAddr;
  int operandRecord2;
  int operandRecord;
  int *operandVReg;
  uint loopIndex;
  uint *prevFlagsPtr;
  bool moreDefLanes;
  uint instFlags;
  uint childBitIndex;
  int *nextInstLink;
  int usedBitWordAddr;
  int operandCount;
  int laneCountdown;
  int *listHead;
  int operandNumber;
  int *inst;
  undefined4 laneMaskWord;
  int *childInst;
  undefined4 laneMaskOut [5];
  
  listHead = *(int **)(*(int *)(block + 300) + 0x98);
  nextInstLink = (int *)listHead[2];
  if (nextInstLink == (int *)0x0) {
    return;
  }
  do {
    inst = listHead;
    if (listHead != (int *)0x0) {
      do {
        instFlags = inst[5];
        if ((instFlags & 1) != 0) {
          for (operandNumber = 1; operandCount = (**(code **)(*inst + 0x14))(inst), operandNumber <= operandCount;
              operandNumber = operandNumber + 1) {
            operandVReg = (int *)IRInst__getOperandSource(inst,operandNumber);
            if ((((operandVReg[0x20] != 0) && (operandCount = RegKind__flagBit0(operandVReg[0x26]), operandCount != 0)) &&
                ((operandVReg[5] & 2U) == 0)) &&
               (operandCount = (**(code **)(*operandVReg + 0x50))(operandVReg), operandCount == 0)) {
              operandRecord = IRInst__getOperandRecord(inst,operandNumber);
              SelectWord__readMask(laneMaskOut,*(undefined4 *)(operandRecord + 0x10));
              operandCount = 0;
              laneMaskWord = laneMaskOut[0];
              laneCountdown = 4;
              do {
                if (*(char *)((int)&laneMaskWord + operandCount) != '\0') {
                  usedBitIndex = operandVReg[0x25] * 4 + operandCount;
                  usedBitWordAddr = (usedBitIndex >> 3 & 0x1ffffffc) + usedBits;
                  *(uint *)(usedBitWordAddr + 8) = 1 << (usedBitIndex & 0x1f) | *(uint *)(usedBitWordAddr + 8);
                }
                operandCount = operandCount + 1;
                laneCountdown = laneCountdown + -1;
              } while (laneCountdown != 0);
            }
          }
          if (((inst[0x20] != 0) && (operandNumber = RegKind__flagBit0(inst[0x26]), operandNumber != 0)) &&
             (((inst[5] & 2U) == 0 &&
              (operandNumber = (**(code **)(*inst + 0x50))(inst), operandNumber == 0)))) {
            defLane = 0;
            do {
              operandRecord = IRInst__getOperandRecord(inst,0);
              if (*(char *)(defLane + operandRecord + 0x10) != '\x01') {
                defBitIndex = inst[0x25] * 4 + defLane;
                defBitWordAddr = (defBitIndex >> 3 & 0x1ffffffc) + usedBits;
                *(uint *)(defBitWordAddr + 8) = 1 << (defBitIndex & 0x1f) | *(uint *)(defBitWordAddr + 8);
              }
              moreDefLanes = defLane != 3;
              defLane = defLane + 1;
            } while (moreDefLanes);
          }
          subBlock = *(int *)(block + 300);
          operandCount = 0;
          childInst = (int *)0x0;
          for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(subBlock + 300) + 4); loopIndex = loopIndex + 1) {
            childInst = *(int **)(operandCount + *(int *)(*(int *)(subBlock + 300) + 8));
            if ((childInst[5] & 1U) != 0) {
              childQuery60 = (**(code **)(*childInst + 0x60))(childInst);
              if (childQuery60 == 0) {
                childLane = 0;
                do {
                  operandRecord2 = IRInst__getOperandRecord(inst,0);
                  if (*(char *)(childLane + operandRecord2 + 0x10) != '\x01') {
                    childBitIndex = childInst[0x25] * 4 + childLane;
                    childBitWordAddr = (childBitIndex >> 3 & 0x1ffffffc) + usedBits;
                    *(uint *)(childBitWordAddr + 8) = 1 << (childBitIndex & 0x1f) | *(uint *)(childBitWordAddr + 8);
                  }
                  moreChildLanes = childLane != 3;
                  childLane = childLane + 1;
                } while (moreChildLanes);
              }
              subBlock = *(int *)(block + 300);
            }
            operandCount = operandCount + 4;
          }
          instFlags = inst[5];
        }
        inst = (int *)inst[2];
      } while ((inst != (int *)0x0) && ((instFlags & 4) != 0));
      nextInstLink = (int *)listHead[2];
    }
    do {
      nextInstAdvance = nextInstLink;
      prevFlagsPtr = (uint *)(listHead + 5);
      nextInstLink = (int *)nextInstAdvance[2];
      if (nextInstLink == (int *)0x0) {
        return;
      }
      listHead = nextInstAdvance;
    } while ((*prevFlagsPtr & 4) != 0);
  } while( true );
}

/* HwLimits__computeBlockLiveness @ 0x138694 (2336 bytes) */
int HwLimits__computeBlockLiveness(this, regCount, program, compiler)
  undefined4 this;
  int regCount;
  int program;
  int compiler;
{
  undefined4 *allocation;
  uint bitIndex;
  uint instFlags;
  uint newLiveIn;
  uint successorOrdinal;
  undefined4 *bitsetWords;
  uint *flagsPtr;
  int *nextInst;
  int *lastSourceInst;
  int *walkInst;
  int *scanInst;
  int *headInst;
  int successorBlock;
  int srcOperandRecord;
  int liveInWordPtr;
  int successorByteOffset;
  int fillWordsLeft;
  int blockSlot8Result;
  int blockCountNow;
  int blockOrdinal;
  int unionWordsLeft;
  int succLiveInWordPtr;
  int defWordCursor;
  int copyWordsLeft;
  int defWordPtr;
  int operandRecord;
  int sourceRegId;
  int componentIndex;
  int sourceFoldedResult;
  int sourceCount;
  int predicateResult;
  int isPhiResult;
  int blockSlot6Result;
  bool moreComponents;
  bool blockLiveInChanged;
  bool liveInChangedAny;
  uint *srcWord;
  bool bitsetHasWords;
  bool isFirstSuccessor;
  int *bitsetWordPtr;
  int blockArray;
  int *sourceInst;
  int callResult;
  int alreadyDefined;
  int *srcWordPtr;
  int blockCount;
  undefined4 *puVar11;
  undefined4 *blockListCursor;
  uint bitsetWordCount;
  int sourceIndex;
  int componentNo;
  int blockIndex;
  int bitsetAllocBytes;
  int bitCount;
  undefined4 arena;
  int *block;
  uint zeroWordsLeft;
  undefined4 usedComponents;
  int local_64;
  undefined4 swizzleComponentUse [3];
  
  bitCount = regCount * 4;
  blockIndex = 1;
  *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 0x1000;
  blockArray = FUN_000ec4f0(program);
  bitsetWordCount = bitCount + 0x1fU >> 5;
  bitsetHasWords = bitsetWordCount != 0;
  bitsetAllocBytes = bitsetWordCount * 4 + 0xc;
  while( true ) {
    blockCount = DList__count(program + 0x37c);
    if (blockCount < blockIndex) {
      puVar11 = (undefined4 *)Program__getBlocksArray(program);
      do {
        liveInChangedAny = false;
        blockOrdinal = 1;
        blockListCursor = puVar11;
        while( true ) {
          blockListCursor = blockListCursor + 1;
          blockCountNow = DList__count(program + 0x37c);
          if (blockCountNow < blockOrdinal) break;
          block = (int *)*blockListCursor;
          blockSlot8Result = (**(code **)(*block + 0x20))(block);
          if (blockSlot8Result == 0) {
            bitsetWordPtr = (int *)block[0x41];
            fillWordsLeft = *bitsetWordPtr;
            if (fillWordsLeft != 0) {
              if (fillWordsLeft == 0) {
                fillWordsLeft = 1;
              }
              do {
                bitsetWordPtr[2] = 0;
                bitsetWordPtr = bitsetWordPtr + 1;
                fillWordsLeft = fillWordsLeft + -1;
              } while (fillWordsLeft != 0);
            }
            isFirstSuccessor = true;
            successorByteOffset = 0;
            local_64 = 0;
            for (successorOrdinal = 1; successorOrdinal <= *(uint *)(block[0x34] + 4); successorOrdinal = successorOrdinal + 1) {
              successorBlock = *(int *)(*(int *)(block[0x34] + 8) + successorByteOffset);
              if (successorBlock != 0) {
                if (isFirstSuccessor) {
                  bitsetWordPtr = (int *)block[0x41];
                  succLiveInWordPtr = *(int *)(successorBlock + 0x100);
                  copyWordsLeft = *bitsetWordPtr;
                  if (copyWordsLeft != 0) {
                    if (copyWordsLeft == 0) {
                      copyWordsLeft = 1;
                    }
                    do {
                      srcWordPtr = (int *)(succLiveInWordPtr + 8);
                      succLiveInWordPtr = succLiveInWordPtr + 4;
                      bitsetWordPtr[2] = *srcWordPtr;
                      bitsetWordPtr = bitsetWordPtr + 1;
                      copyWordsLeft = copyWordsLeft + -1;
                    } while (copyWordsLeft != 0);
                  }
                }
                else {
                  bitsetWordPtr = (int *)block[0x41];
                  succLiveInWordPtr = *(int *)(successorBlock + 0x100);
                  copyWordsLeft = *bitsetWordPtr;
                  if (copyWordsLeft != 0) {
                    if (copyWordsLeft == 0) {
                      copyWordsLeft = 1;
                    }
                    do {
                      srcWord = (uint *)(succLiveInWordPtr + 8);
                      succLiveInWordPtr = succLiveInWordPtr + 4;
                      bitsetWordPtr[2] = bitsetWordPtr[2] | *srcWord;
                      bitsetWordPtr = bitsetWordPtr + 1;
                      copyWordsLeft = copyWordsLeft + -1;
                    } while (copyWordsLeft != 0);
                  }
                }
                isFirstSuccessor = false;
              }
              successorByteOffset = successorByteOffset + 4;
            }
            bitsetWordPtr = (int *)block[0x41];
            blockLiveInChanged = false;
            defWordCursor = block[0x42];
            unionWordsLeft = *bitsetWordPtr;
            liveInWordPtr = block[0x40];
            if (unionWordsLeft != 0) {
              blockLiveInChanged = false;
              if (unionWordsLeft == 0) {
                unionWordsLeft = 1;
              }
              do {
                newLiveIn = bitsetWordPtr[2] & ~*(uint *)(defWordCursor + 8) | *(uint *)(liveInWordPtr + 8);
                if (*(uint *)(liveInWordPtr + 8) != newLiveIn) {
                  *(uint *)(liveInWordPtr + 8) = newLiveIn;
                  blockLiveInChanged = true;
                }
                bitsetWordPtr = bitsetWordPtr + 1;
                defWordCursor = defWordCursor + 4;
                liveInWordPtr = liveInWordPtr + 4;
                unionWordsLeft = unionWordsLeft + -1;
              } while (unionWordsLeft != 0);
            }
            liveInChangedAny = blockLiveInChanged || liveInChangedAny;
          }
          blockOrdinal = blockOrdinal + 1;
        }
      } while (liveInChangedAny);
      return;
    }
    arena = *(undefined4 *)(compiler + COMP_arenaB);
    block = *(int **)(blockArray + blockIndex * 4);
    allocation = (undefined4 *)Arena__alloc(arena,bitsetAllocBytes);
    bitsetWords = allocation + 1;
    *allocation = arena;
    allocation[1] = bitsetWordCount;
    allocation[2] = bitCount;
    if (bitsetHasWords) {
      puVar11 = bitsetWords;
      zeroWordsLeft = bitsetWordCount;
      if (bitsetWordCount == 0) {
        zeroWordsLeft = 1;
      }
      do {
        puVar11[2] = 0;
        puVar11 = puVar11 + 1;
        zeroWordsLeft = zeroWordsLeft - 1;
      } while (zeroWordsLeft != 0);
    }
    block[0x41] = (int)bitsetWords;
    arena = *(undefined4 *)(compiler + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arena,bitsetAllocBytes);
    bitsetWords = allocation + 1;
    *allocation = arena;
    allocation[1] = bitsetWordCount;
    allocation[2] = bitCount;
    if (bitsetHasWords) {
      puVar11 = bitsetWords;
      zeroWordsLeft = bitsetWordCount;
      if (bitsetWordCount == 0) {
        zeroWordsLeft = 1;
      }
      do {
        puVar11[2] = 0;
        puVar11 = puVar11 + 1;
        zeroWordsLeft = zeroWordsLeft - 1;
      } while (zeroWordsLeft != 0);
    }
    block[0x40] = (int)bitsetWords;
    arena = *(undefined4 *)(compiler + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arena,bitsetAllocBytes);
    bitsetWords = allocation + 1;
    *allocation = arena;
    allocation[1] = bitsetWordCount;
    allocation[2] = bitCount;
    if (bitsetHasWords) {
      puVar11 = bitsetWords;
      zeroWordsLeft = bitsetWordCount;
      if (bitsetWordCount == 0) {
        zeroWordsLeft = 1;
      }
      do {
        puVar11[2] = 0;
        puVar11 = puVar11 + 1;
        zeroWordsLeft = zeroWordsLeft - 1;
      } while (zeroWordsLeft != 0);
    }
    headInst = (int *)block[0x26];
    block[0x42] = (int)bitsetWords;
    if (headInst[2] != 0) break;
LAB_00138d5c:
    blockSlot6Result = (**(code **)(*block + 0x18))(block);
    if (blockSlot6Result != 0) {
      ((int (*)())FUN_00138390)(block,block[0x40]);
    }
    blockIndex = blockIndex + 1;
  }
  do {
    isPhiResult = (**(code **)(*headInst + 0x7c))(headInst);
    walkInst = headInst;
    if (isPhiResult == 0) {
      do {
        instFlags = walkInst[5];
        if (((instFlags & 1) != 0) && (*(int *)(walkInst[0x22] + 8) != 0x8e)) {
          predicateResult = (**(code **)(*walkInst + 0x34))(walkInst);
          if ((predicateResult == 0) &&
             (((predicateResult = (**(code **)(*walkInst + 0x38))(walkInst), predicateResult == 0 &&
               (predicateResult = (**(code **)(*walkInst + 0x60))(walkInst), predicateResult == 0)) &&
              (predicateResult = (**(code **)(*walkInst + 0x5c))(walkInst), predicateResult == 0)))) {
            instFlags = walkInst[5];
            sourceCount = walkInst[0x21];
            if ((instFlags & 0x200) != 0) {
              sourceCount = sourceCount + -1;
            }
            if (0 < sourceCount) {
              sourceIndex = 1;
              do {
                sourceInst = (int *)IRInst__getOperandSource(walkInst,sourceIndex);
                if (((sourceInst[0x20] != 0) && (callResult = RegKind__flagBit0(sourceInst[0x26]), callResult != 0)) &&
                   (((sourceInst[5] & 2U) == 0 &&
                    ((callResult = (**(code **)(*sourceInst + 0x50))(sourceInst), callResult == 0 &&
                     (callResult = ((int (*)())FUN_00137e98)(walkInst,sourceIndex,walkInst), callResult == 0)))))) {
                  srcOperandRecord = IRInst__getOperandRecord(walkInst,sourceIndex);
                  componentNo = 0;
                  SelectWord__readMask(swizzleComponentUse,*(undefined4 *)(srcOperandRecord + 0x10));
                  usedComponents = swizzleComponentUse[0];
                  callResult = sourceInst[0x25];
                  bitIndex = callResult << 2;
                  do {
                    if ((*(char *)((int)&usedComponents + componentNo) != '\0') &&
                       (alreadyDefined = ((int (*)())BitSet__testRegisterLane)(block[0x42],callResult,componentNo), alreadyDefined == 0)) {
                      alreadyDefined = (bitIndex >> 3 & 0x1ffffffc) + block[0x40];
                      *(uint *)(alreadyDefined + 8) = 1 << (bitIndex & 0x1f) | *(uint *)(alreadyDefined + 8);
                    }
                    moreComponents = componentNo != 3;
                    bitIndex = bitIndex + 1;
                    componentNo = componentNo + 1;
                  } while (moreComponents);
                }
                sourceIndex = sourceIndex + 1;
              } while (sourceIndex <= sourceCount);
              instFlags = walkInst[5];
            }
            if ((instFlags & 0x200) == 0) goto LAB_00138af0;
            sourceInst = (int *)IRInst__getOperandSource(walkInst,walkInst[0x21]);
            if ((((sourceInst[0x20] != 0) && (sourceCount = RegKind__flagBit0(sourceInst[0x26]), sourceCount != 0)) &&
                ((sourceInst[5] & 2U) == 0)) &&
               (sourceCount = (**(code **)(*sourceInst + 0x50))(sourceInst), sourceCount == 0)) {
              sourceRegId = sourceInst[0x25];
              sourceFoldedResult = ((int (*)())FUN_00137e98)(walkInst,walkInst[0x21],walkInst);
              if (sourceFoldedResult == 0) {
                bitIndex = sourceRegId << 2;
                componentIndex = 0;
                do {
                  callResult = IRInst__getOperandRecord(walkInst,0);
                  if (((*(char *)(componentIndex + callResult + 0x10) == '\x01') &&
                      (callResult = ((int (*)())BitSet__testRegisterLane)(block[0x42],sourceRegId,componentIndex), callResult == 0)) &&
                     (callResult = ((int (*)())FUN_00138240)(sourceInst,componentIndex), callResult != 0)) {
                    callResult = (bitIndex >> 3 & 0x1ffffffc) + block[0x40];
                    *(uint *)(callResult + 8) = 1 << (bitIndex & 0x1f) | *(uint *)(callResult + 8);
                  }
                  moreComponents = componentIndex != 3;
                  bitIndex = bitIndex + 1;
                  componentIndex = componentIndex + 1;
                } while (moreComponents);
              }
            }
          }
          instFlags = walkInst[5];
        }
LAB_00138af0:
        scanInst = headInst;
      } while (((int *)walkInst[2] != (int *)0x0) && (walkInst = (int *)walkInst[2], (instFlags & 4) != 0));
      do {
        instFlags = scanInst[5];
        if (((instFlags & 1) != 0) && (*(int *)(scanInst[0x22] + 8) != 0x8e)) {
          predicateResult = (**(code **)(*scanInst + 0x34))(scanInst);
          if ((((predicateResult == 0) && (predicateResult = (**(code **)(*scanInst + 0x38))(scanInst), predicateResult == 0)) &&
              (predicateResult = (**(code **)(*scanInst + 0x60))(scanInst), predicateResult == 0)) &&
             (predicateResult = (**(code **)(*scanInst + 0x5c))(scanInst), predicateResult == 0)) {
            if ((scanInst[0x20] == 0) || (predicateResult = RegKind__flagBit0(scanInst[0x26]), predicateResult == 0)) {
LAB_00138c50:
              instFlags = scanInst[5];
            }
            else {
              instFlags = scanInst[5];
              if ((instFlags & 2) == 0) {
                predicateResult = (**(code **)(*scanInst + 0x50))(scanInst);
                if (predicateResult == 0) {
                  predicateResult = 0;
                  do {
                    operandRecord = IRInst__getOperandRecord(scanInst,0);
                    if (*(char *)(predicateResult + operandRecord + 0x10) != '\x01') {
                      bitIndex = scanInst[0x25] * 4 + predicateResult;
                      defWordPtr = (bitIndex >> 3 & 0x1ffffffc) + block[0x42];
                      *(uint *)(defWordPtr + 8) = 1 << (bitIndex & 0x1f) | *(uint *)(defWordPtr + 8);
                    }
                    moreComponents = predicateResult != 3;
                    predicateResult = predicateResult + 1;
                  } while (moreComponents);
                }
                goto LAB_00138c50;
              }
            }
            if ((instFlags & 0x200) == 0) goto LAB_00138d24;
            lastSourceInst = (int *)IRInst__getOperandSource(scanInst,scanInst[0x21]);
            if (((lastSourceInst[0x20] != 0) && (predicateResult = RegKind__flagBit0(lastSourceInst[0x26]), predicateResult != 0)) &&
               (((lastSourceInst[5] & 2U) == 0 &&
                (predicateResult = (**(code **)(*lastSourceInst + 0x50))(lastSourceInst), predicateResult == 0)))) {
              componentIndex = 0;
              do {
                operandRecord = IRInst__getOperandRecord(scanInst,0);
                if ((*(char *)(componentIndex + operandRecord + 0x10) == '\x01') &&
                   (operandRecord = ((int (*)())FUN_00138240)(lastSourceInst,componentIndex), operandRecord != 0)) {
                  bitIndex = scanInst[0x25] * 4 + componentIndex;
                  defWordPtr = (bitIndex >> 3 & 0x1ffffffc) + block[0x42];
                  *(uint *)(defWordPtr + 8) = 1 << (bitIndex & 0x1f) | *(uint *)(defWordPtr + 8);
                }
                moreComponents = componentIndex != 3;
                componentIndex = componentIndex + 1;
              } while (moreComponents);
            }
          }
          instFlags = scanInst[5];
        }
LAB_00138d24: ;
      } while (((int *)scanInst[2] != (int *)0x0) && (scanInst = (int *)scanInst[2], (instFlags & 4) != 0));
    }
    nextInst = (int *)headInst[2];
    scanInst = headInst;
    do {
      headInst = nextInst;
      flagsPtr = (uint *)(scanInst + 5);
      if ((int *)headInst[2] == (int *)0x0) goto LAB_00138d5c;
      nextInst = (int *)headInst[2];
      scanInst = headInst;
    } while ((*flagsPtr & 4) != 0);
  } while( true );
}

/* Program__finishUsevectorChain @ 0x138fb4 (84 bytes) */
int Program__finishUsevectorChain(inst, param_2, param_3, param_4)
  undefined4 inst;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  int *a0;
  
  a0 = *(int **)(*(int *)(param_4 + 8) + 0x30c);
  (**(code **)(*a0 + 0x6c))(a0,inst,param_4,param_4);
  return FUN_0014846c(inst,param_4);
}

/* FUN_00139008 @ 0x139008 (44 bytes) */
int FUN_00139008(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 4;
  iVar3 = 0;
  uVar2 = 0;
  do {
    uVar1 = uVar2 & 0x3f;
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + (param_1 >> uVar1 & 1U);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return iVar3;
}

/* FUN_00139034 @ 0x139034 (40 bytes) */
int FUN_00139034(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x158);
  if (((iVar1 != param_3) && (iVar1 != param_4)) && (iVar1 != param_2)) {
    return 1;
  }
  return 0;
}

/* FUN_0013905c @ 0x13905c (308 bytes) */
int FUN_0013905c(param_1, inst)
  int *param_1;
  int *inst;
{
  int *operandVReg;
  int iVar2;
  int *operandVReg2;
  
  (**(code **)(*inst + 0x14))(inst,inst);
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  while (iVar2 = (**(code **)(*operandVReg + 0x60))(operandVReg), iVar2 != 0) {
    operandVReg = (int *)IRInst__getOperandSource(operandVReg,1);
  }
  operandVReg2 = (int *)IRInst__getOperandSource(inst,2);
  while (iVar2 = (**(code **)(*operandVReg2 + 0x60))(operandVReg2), iVar2 != 0) {
    operandVReg2 = (int *)IRInst__getOperandSource(operandVReg2,1);
  }
  while( true ) {
    do {
      inst = (int *)inst[1];
      iVar2 = (**(code **)(*inst + 0x60))(inst);
    } while (iVar2 != 0);
    if (param_1 == inst) break;
    if (((inst == operandVReg) || (inst == operandVReg2)) ||
       (iVar2 = (**(code **)(*inst + 0x34))(inst), iVar2 != 0)) {
      return 0;
    }
  }
  return 1;
}

/* FUN_00139190 @ 0x139190 (156 bytes) */
int FUN_00139190(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 local_28;
  
  uVar1 = *(uint *)(param_1 + 4) - 1;
  piVar2 = (int *)0x0;
  if (uVar1 < *(uint *)(param_1 + 4)) {
    piVar2 = (int *)(uVar1 * 4 + *(int *)(param_1 + 8));
  }
  local_28 = *piVar2;
  if ((char)local_28 == '\0') {
    return local_28 == param_2;
  }
  if (param_2 < 5) {
    iVar4 = 0;
    if (param_2 < 1) goto LAB_00139218;
  }
  else {
    param_2 = 4;
  }
  iVar3 = 0;
  iVar4 = 0;
  do {
    if (*(char *)((int)&local_28 + iVar3) != -1) {
      iVar4 = iVar4 + 1;
    }
    iVar3 = iVar3 + 1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
LAB_00139218:
  return iVar4 < 2;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_001322a8");
asm(".set FUN_001322a8, _HwLimits__buildInterferenceGraph");
asm(".globl FUN_00138694");
asm(".set FUN_00138694, _HwLimits__computeBlockLiveness");

/* issue #75 (follow-up #3): Ghidra recognized this as a THUNK - a pure trampoline stub that
 * just branches straight to the real function below, no different behavior or arguments - but
 * decls.h declares "thunk_FUN_xxx" as its own separate extern function that nothing in this
 * corpus ever DEFINES a body for. The stock ld apparently tolerated the resulting undefined
 * reference (never actually called in a way that mattered, or silently resolved some other
 * way); ld64 leaves it a real unresolved lazy symbol, crashing the moment this call path is
 * first taken. Real fix: alias the thunk name directly onto the real function, so calling
 * "thunk_FUN_xxx" IS calling FUN_xxx - which is exactly what the original binary's trampoline
 * did. */
asm(".globl _thunk_FUN_00134de8");
asm(".set _thunk_FUN_00134de8, _FUN_00134de8");
