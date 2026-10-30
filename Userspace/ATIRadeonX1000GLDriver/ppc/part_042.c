#include "decls.h"

/* FUN_0013922c @ 0x13922c (104 bytes) */
int FUN_0013922c(orderVec)
  int orderVec;
{
  uint topIndex;
  int loopIndex;
  int *topSlot;
  int countdown;
  undefined4 orderKey;
  
  topSlot = (int *)0x0;
  topIndex = *(uint *)(orderVec + 4) - 1;
  if (topIndex < *(uint *)(orderVec + 4)) {
    topSlot = (int *)(topIndex * 4 + *(int *)(orderVec + 8));
  }
  orderKey = *topSlot;
  if ((char)orderKey == '\0') {
    return orderKey;
  }
  loopIndex = 0;
  countdown = 4;
  do {
    if (*(char *)((int)&orderKey + loopIndex) != -1) {
      return (int)*(char *)((int)&orderKey + loopIndex);
    }
    loopIndex = loopIndex + 1;
    countdown = countdown + -1;
  } while (countdown != 0);
  return 0;
}

/* FUN_00139294 @ 0x139294 (176 bytes) */
int FUN_00139294(block, stopBlock)
  int *block;
  int *stopBlock;
{
  int isIfHeader;
  int isIfFooter;
  undefined4 result;
  
  if (block[0x2e] == 0) {
    do {
      while( true ) {
        block = (int *)block[0x3c];
        if ((block == stopBlock) || (block[0x2e] != 0)) goto LAB_0013932c;
        isIfFooter = (**(code **)(*block + 0x28))(block);
        if (isIfFooter == 0) break;
        block = (int *)Block__getPredecessor(block[0x4b],0);
      }
      isIfHeader = (**(code **)(*block + 0x24))(block);
    } while (isIfHeader == 0);
    result = 1;
  }
  else {
LAB_0013932c:
    result = 0;
  }
  return result;
}

/* IRInst__isOpcodeInSet139344 @ 0x139344 (80 bytes) */
int IRInst__isOpcodeInSet139344(param_1)
  int param_1;
{
  switch(*(undefined4 *)(*(int *)(param_1 + 0x88) + 8)) {
  case 0x69:
  case 0x6b:
  case 0x75:
  case 0x76:
  case 0x9e:
  case 0x9f:
  case 0xa0:
  case 0xa1:
  case 0xaf:
    return 1;
  default:
    return 0;
  }
}

/* Program__moveInterpFetchesOutOfIfs @ 0x1394b0 (496 bytes) */
int Program__moveInterpFetchesOutOfIfs(param_1)
  int param_1;
{
  int instListNext;
  int *walkBlock;
  int vcall24Result;
  int vcall4cResult;
  int isPostLoopFooter;
  int isLoopHeader;
  int isIfFooter;
  int isIfHeader;
  int *operandVReg;
  int *nextListBlock;
  int *nextBlock;
  int *hoistTargetBlock;
  int *block;
  int *entryBlock;
  int isOpcodeInSet139344Result;
  int nextInst;
  int inst;
  
  entryBlock = *(int **)(param_1 + 0x3a0);
  nextListBlock = (int *)(*(int **)(param_1 + 900))[2];
  if (nextListBlock != (int *)0x0) {
    hoistTargetBlock = (int *)0x0;
    block = *(int **)(param_1 + 900);
    do {
      nextBlock = nextListBlock;
      instListNext = *(int *)(block[0x26] + 8);
      inst = block[0x26];
      if (instListNext != 0) {
        do {
          nextInst = instListNext;
          isOpcodeInSet139344Result = ((int (*)())IRInst__isOpcodeInSet139344)(inst);
          if (isOpcodeInSet139344Result != 0) {
            operandVReg = (int *)IRInst__getOperandSource(inst,1);
            vcall4cResult = (**(code **)(*operandVReg + 0x4c))(operandVReg);
            walkBlock = block;
            if (vcall4cResult != 0) {
              while (walkBlock != entryBlock) {
                isIfHeader = (**(code **)(*walkBlock + 0x24))(walkBlock);
                if (isIfHeader != 0) {
                  if (hoistTargetBlock == (int *)0x0) {
                    Block__hasMultipleSuccessors(entryBlock);
                    hoistTargetBlock = (int *)Block__getSuccessor(entryBlock,0);
                    vcall24Result = (**(code **)(*hoistTargetBlock + 0x24))(hoistTargetBlock);
                    if (vcall24Result == 0) {
                      (**(code **)(*hoistTargetBlock + 0x2c))(hoistTargetBlock);
                    }
                  }
                  IRInst__unlinkAndClearFlag0(inst);
                  *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) | 1;
                  Block__appendInst(hoistTargetBlock,inst);
                  break;
                }
                isIfFooter = (**(code **)(*walkBlock + 0x28))(walkBlock);
                if (isIfFooter == 0) {
                  isLoopHeader = (**(code **)(*walkBlock + 0x2c))(walkBlock);
                  if (isLoopHeader == 0) {
                    isPostLoopFooter = (**(code **)(*walkBlock + 0x34))(walkBlock);
                    if (isPostLoopFooter != 0) {
                      walkBlock = (int *)Block__findSimplePredecessor(walkBlock[0x4b]);
                    }
                    goto LAB_00139654;
                  }
                  walkBlock = (int *)Block__findSimplePredecessor(walkBlock);
                }
                else {
                  walkBlock = (int *)Block__getPredecessor(walkBlock[0x4b],0);
LAB_00139654:
                  walkBlock = (int *)walkBlock[0x3c];
                }
              }
            }
          }
          instListNext = *(int *)(nextInst + 8);
          inst = nextInst;
        } while (instListNext != 0);
        nextBlock = (int *)block[2];
      }
      nextListBlock = (int *)nextBlock[2];
      block = nextBlock;
    } while ((int *)nextBlock[2] != (int *)0x0);
  }
  return;
}

/* IRInst__markOpcode13After12 @ 0x1396a0 (48 bytes) */
int IRInst__markOpcode13After12(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) != 0x13) {
    return;
  }
  if (*(int *)(*(int *)(param_2 + 0x88) + 8) == 0x12) {
    return;
  }
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x20000;
  return;
}

/* FUN_001396d0 @ 0x1396d0 (360 bytes) */
int FUN_001396d0(compiler, inst, operandIndex, program)
  int compiler;
  int *inst;
  int operandIndex;
  int program;
{
  int vcall14Result;
  int sourceDef;
  int operandRecord;
  int vcall5cResult;
  int operandVReg;
  uint sourceLaneMask;
  undefined4 maskedDestSelect;
  uint sourceLaneMaskOut;
  uint laneMaskSelect [4];
  
  vcall5cResult = (**(code **)(*inst + 0x5c))(inst,inst,operandIndex,program);
  if (vcall5cResult == 0) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    SelectWord__selectWhereMasked(&maskedDestSelect,*(undefined4 *)(operandRecord + 0x10),inst[3]);
    vcall14Result = (**(code **)(*inst + 0x14))(inst);
    sourceLaneMask = 0x1010101;
    if (operandIndex <= vcall14Result) {
      IRInst__computeSourceLaneMask(&sourceLaneMaskOut,inst,operandIndex,program,maskedDestSelect);
      sourceLaneMask = sourceLaneMaskOut;
    }
    SelectWord__selectWhereMasked(laneMaskSelect,0,sourceLaneMask);
    sourceDef = IRInst__getOperandSource(inst,operandIndex);
    if ((sourceDef != 0) &&
       (((*(int *)(sourceDef + 0x98) == 2 || (*(int *)(sourceDef + 0x98) == 0xc)) &&
        (operandVReg = (**(code **)(**(int **)(compiler + 0x30c) + 0xec))
                           (*(int **)(compiler + 0x30c),inst,operandIndex,
                            laneMaskSelect[0] << 0x18 | (laneMaskSelect[0] >> 8 & 0xff) << 0x10 |
                            (laneMaskSelect[0] >> 0x10 & 0xff) << 8 | laneMaskSelect[0] >> 0x18,
                            *(undefined4 *)(program + 8)), operandVReg != 0)))) {
      operandVReg = IRInst__getOperandSource(inst,operandIndex);
      if (sourceDef == operandVReg) {
        return 1;
      }
      *(uint *)(operandVReg + 0xc) = sourceLaneMask | *(uint *)(operandVReg + 0xc);
      return 1;
    }
  }
  return 0;
}

/* IRInst__sourceIsSplatConstant @ 0x139838 (124 bytes) */
undefined4 IRInst__sourceIsSplatConstant(undefined4 inst,undefined4 srcIndex,double fparam_1)
{
  int operandRecord;
  int iVar1;
  undefined4 uVar2;
  int local_48;
  float local_44;
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  iVar1 = IRInst__getUniformSourceConstant(inst,srcIndex,*(undefined4 *)(operandRecord + 0x10),&local_48);
  if (((iVar1 == 0) || ((double)local_44 != fparam_1)) || (uVar2 = 1, local_48 != 2)) {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_001398b4 @ 0x1398b4 (964 bytes) */
int FUN_001398b4(inst, param_2, param_3, program)
  int inst;
  undefined4 param_2;
  undefined4 param_3;
  int program;
{
  int producerOperand;
  int producerOpcodeInfo;
  int sourceIsSplatConstantResult;
  undefined4 opcodeInfo;
  int sourceDef;
  int operandRecord2;
  int sourceIsSplatConstantResult2;
  int operandVReg;
  int operandRecord;
  int operandVReg2;
  int callResult;
  undefined4 uVar6;
  undefined4 operandSelect;
  undefined4 producerOperandIndex;
  undefined4 composedSelect;
  undefined4 composedSelectFirst;
  undefined4 composedSelectSecond [6];
  
  if (*(int *)(*(int *)(inst + 0x88) + 8) != 0x29) {
    return 0;
  }
  sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(inst,1,(double)FLOAT_001aa0d4);
  if (sourceIsSplatConstantResult == 0) {
    return 0;
  }
  operandVReg = IRInst__getOperandSource(inst,2);
  producerOpcodeInfo = *(int *)(operandVReg + 0x88);
  if ((*(int *)(producerOpcodeInfo + 8) == 0x24) && ((*(uint *)(operandVReg + 0x14) & 0x200) == 0)) {
    sourceIsSplatConstantResult2 = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(operandVReg,2,(double)FLOAT_001aa0d4);
    if ((sourceIsSplatConstantResult2 == 0) ||
       (((sourceIsSplatConstantResult2 = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(operandVReg,3,(double)FLOAT_001aa0e8), sourceIsSplatConstantResult2 == 0 ||
         ((*(uint *)(operandVReg + 0xb8) & 1) != 0)) || ((*(uint *)(operandVReg + 0xb8) & 2) != 0)))) {
      producerOpcodeInfo = *(int *)(operandVReg + 0x88);
      goto LAB_00139c2c;
    }
  }
  else {
LAB_00139c2c:
    if ((*(int *)(producerOpcodeInfo + 8) == 0x28) && ((*(uint *)(operandVReg + 0x14) & 0x200) == 0)) {
      sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(operandVReg,2,(double)FLOAT_001aa0d4);
      if ((sourceIsSplatConstantResult != 0) &&
         (((*(uint *)(operandVReg + 0xb8) & 1) == 0 && ((*(uint *)(operandVReg + 0xb8) & 2) != 0)))) {
        producerOperandIndex = 1;
        uVar6 = 0x27;
        goto LAB_00139978;
      }
      producerOpcodeInfo = *(int *)(operandVReg + 0x88);
    }
    if ((*(int *)(producerOpcodeInfo + 8) == 0x28) && ((*(uint *)(operandVReg + 0x14) & 0x200) == 0)) {
      sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(operandVReg,1,(double)FLOAT_001aa0d4);
      if ((sourceIsSplatConstantResult != 0) &&
         (((*(uint *)(operandVReg + 0xd0) & 1) == 0 && ((*(uint *)(operandVReg + 0xd0) & 2) == 0)))) {
        producerOperandIndex = 2;
        uVar6 = 0x29;
        goto LAB_00139978;
      }
      producerOpcodeInfo = *(int *)(operandVReg + 0x88);
    }
    if (*(int *)(producerOpcodeInfo + 8) != 0x25) {
      return 0;
    }
    if ((*(uint *)(operandVReg + 0x14) & 0x200) != 0) {
      return 0;
    }
    sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(operandVReg,2,(double)FLOAT_001aa0d4);
    if (sourceIsSplatConstantResult == 0) {
      return 0;
    }
    sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(operandVReg,3,(double)FLOAT_001aa0e8);
    if (sourceIsSplatConstantResult == 0) {
      return 0;
    }
    if ((*(uint *)(operandVReg + 0xb8) & 1) != 0) {
      return 0;
    }
    if ((*(uint *)(operandVReg + 0xb8) & 2) != 0) {
      return 0;
    }
  }
  producerOperandIndex = 1;
  uVar6 = 0x29;
LAB_00139978:
  producerOperand = IRInst__getOperandSource(operandVReg,producerOperandIndex);
  if (((((*(int *)(*(int *)(producerOperand + 0x88) + 8) == 0x12) && ((*(uint *)(producerOperand + 0x14) & 0x200) == 0))
       && ((*(uint *)(producerOperand + 0xb8) & 1) == 0)) &&
      (((*(uint *)(producerOperand + 0xb8) & 2) == 0 && ((*(uint *)(producerOperand + 0xd0) & 1) != 0)))) &&
     ((*(uint *)(producerOperand + 0xd0) & 2) == 0)) {
    operandRecord = IRInst__getOperandRecord(inst,2);
    operandSelect = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(operandVReg,producerOperandIndex);
    SelectWord__compose(&composedSelect,*(undefined4 *)(operandRecord + 0x10),operandSelect);
    operandRecord = IRInst__getOperandRecord(producerOperand,1);
    SelectWord__compose(&composedSelectFirst,*(undefined4 *)(operandRecord + 0x10),composedSelect);
    operandRecord = IRInst__getOperandRecord(producerOperand,2);
    SelectWord__compose(composedSelectSecond,*(undefined4 *)(operandRecord + 0x10),composedSelect);
    sourceDef = IRInst__getOperandSource(producerOperand,1);
    IRInst__setOperandSource(inst,1,sourceDef,0,*(undefined4 *)(program + 8));
    operandVReg2 = IRInst__getOperandSource(producerOperand,2);
    callResult = IRInst__hasSingleUse(operandVReg,program);
    if ((callResult == 0) || (producerOperand = IRInst__hasSingleUse(producerOperand,program), producerOperand == 0)) {
      if (*(int *)(program + 0x478) < *(int *)(sourceDef + 0x160)) {
        *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
      }
      else {
        *(int *)(sourceDef + 0x160) = *(int *)(program + 0x478) + 1;
      }
      if (*(int *)(program + 0x478) < *(int *)(operandVReg2 + 0x160)) {
        *(int *)(operandVReg2 + 0x160) = *(int *)(operandVReg2 + 0x160) + 1;
      }
      else {
        *(int *)(operandVReg2 + 0x160) = *(int *)(program + 0x478) + 1;
      }
    }
    IRInst__setOperandSource(inst,2,operandVReg2,0,*(undefined4 *)(program + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0x10) = composedSelectFirst;
    operandRecord2 = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord2 + 0x10) = composedSelectSecond[0];
    opcodeInfo = Opcode__getInfo(uVar6);
    *(undefined4 *)(inst + 0x88) = opcodeInfo;
    IRInst__dropCounterAndDeleteIfUnused(operandVReg,*(undefined4 *)(program + 8));
  }
  return 0;
}

/* FUN_00139c78 @ 0x139c78 (200 bytes) */
int FUN_00139c78(inst, parentInst, orderKey, program)
  int inst;
  int parentInst;
  undefined4 orderKey;
  int program;
{
  int vcall70Result;
  int callResult;
  int *target;
  
  if (((*(uint *)(inst + 0x14) & 1) != 0) &&
     ((parentInst == 0 || ((*(uint *)(parentInst + 0x14) & 1) != 0)))) {
    callResult = ((int (*)())FUN_001398b4)(inst,parentInst,orderKey,program);
    if (callResult != 0) {
      *(int *)(inst + 0x150) = *(int *)(program + 0x474) + -1;
    }
    target = *(int **)(*(int *)(program + 8) + 0x30c);
    vcall70Result = (**(code **)(*target + 0x70))(target,parentInst,orderKey,inst,program);
    if (vcall70Result != 0) {
      *(int *)(inst + 0x150) = *(int *)(program + 0x474) + -1;
    }
    FUN_001486e8(inst,program);
    return;
  }
  return;
}

/* FUN_00139d40 @ 0x139d40 (524 bytes) */
int FUN_00139d40(program)
  int program;
{
  int *stackPushSlot;
  int *stackTopSlot;
  int coneInst;
  uint countBefore;
  int slotByteOffsetB;
  int vcall30Result;
  int slotByteOffset;
  int block;
  int *nextBlockInst;
  int *blockInstNext;
  int nextBlock;
  undefined4 *rootPushSlot;
  int callResult;
  uint stackTopIndex;
  int *blockInst;
  int loopIndex;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_48_buf [0x10];
  #define vecCapacity (*(uint *)(local_48_buf + 0x00))
  #define vecCount (*(uint *)(local_48_buf + 0x04))
  #define vecData (*(int *)(local_48_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_48_buf + 0x0c))
  
  vecArena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  *(int *)(program + 0x474) = *(int *)(program + 0x474) + 1;
  block = *(int *)(program + 900);
  for (nextBlock = *(int *)(*(int *)(program + 900) + 8); nextBlock != 0; nextBlock = *(int *)(nextBlock + 8)) {
    nextBlockInst = (int *)(*(int **)(block + 0x98))[2];
    blockInst = *(int **)(block + 0x98);
    if (nextBlockInst != (int *)0x0) {
      do {
        blockInstNext = nextBlockInst;
        if ((blockInst[5] & 1U) != 0) {
          vcall30Result = (**(code **)(*blockInst + 0x30))(blockInst);
          countBefore = vecCount;
          if ((vcall30Result != 0) && (*(int *)(program + 0x474) != blockInst[0x54])) {
            blockInst[0x54] = *(int *)(program + 0x474);
            if (vecCount < vecCapacity) {
              slotByteOffsetB = vecCount * 4;
              _memset(slotByteOffsetB + vecData,0,4);
              vecCount = countBefore + 1;
              rootPushSlot = (undefined4 *)(slotByteOffsetB + vecData);
            }
            else {
              rootPushSlot = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *rootPushSlot = blockInst;
            do {
              stackTopIndex = vecCount - 1;
              stackTopSlot = (int *)0x0;
              if (stackTopIndex < vecCount) {
                stackTopSlot = (int *)(stackTopIndex * 4 + vecData);
              }
              coneInst = *stackTopSlot;
              Vector__removeAt(&vecCapacity,stackTopIndex);
              if (0 < *(int *)(coneInst + 0x84)) {
                loopIndex = 1;
                do {
                  callResult = IRInst__getOperandSource(coneInst,loopIndex);
                  countBefore = vecCount;
                  *(uint *)(callResult + 0x14) = *(uint *)(callResult + 0x14) | 0x2000;
                  if ((callResult != 0) && (*(int *)(program + 0x474) != *(int *)(callResult + 0x150))) {
                    *(int *)(callResult + 0x150) = *(int *)(program + 0x474);
                    if (vecCount < vecCapacity) {
                      slotByteOffset = vecCount * 4;
                      _memset(slotByteOffset + vecData,0,4);
                      vecCount = countBefore + 1;
                      stackPushSlot = (int *)(slotByteOffset + vecData);
                    }
                    else {
                      stackPushSlot = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
                    }
                    *stackPushSlot = callResult;
                  }
                  loopIndex = loopIndex + 1;
                } while (loopIndex <= *(int *)(coneInst + 0x84));
              }
            } while (vecCount != 0);
          }
          blockInstNext = (int *)blockInst[2];
        }
        nextBlockInst = (int *)blockInstNext[2];
        blockInst = blockInstNext;
      } while ((int *)blockInstNext[2] != (int *)0x0);
      nextBlock = *(int *)(block + 8);
    }
    block = nextBlock;
  }
  return Arena__free(vecArena,vecData);
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* Block__scanBranchConeForFetchAndInterp @ 0x139f84 (700 bytes) */
int Block__scanBranchConeForFetchAndInterp(block, vector, coneStamp)
  int *block;
  uint *vector;
  int coneStamp;
{
  int *elseNextInst;
  int *elseBlockInst;
  int *thenBlockInst;
  int ifHeaderCheck;
  int coneInst;
  int vcall28ResultB;
  int vcall4cResult;
  int vcall28Result;
  int vcall40Result;
  int *operandVReg;
  int loopIndex;
  byte coneHasInterpLoad;
  byte coneHasFetch;
  int *thenNextInst;
  int *elseNextInstB;
  int elseBlock;
  undefined4 branchInst;
  undefined4 *stackPushSlot;
  int *stackTopSlot;
  int thenBlock;
  undefined4 extraout_r4;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  int iVar10;
  uint stackCount;
  
  iVar10 = coneStamp;
  vcall40Result = (**(code **)(*block + 0x40))(block,vector,coneStamp);
  if (vcall40Result != 0) {
    return;
  }
  branchInst = Block__getBranchInst(block,extraout_r4,iVar10,in_r6,in_r7,in_r8,in_r9);
  stackCount = vector[1];
  if (stackCount < *vector) {
    _memset(stackCount * 4 + vector[2],0,4);
    stackPushSlot = (undefined4 *)(stackCount * 4 + vector[2]);
    vector[1] = stackCount + 1;
  }
  else {
    stackPushSlot = (undefined4 *)Vector__elementRefGrow(vector,stackCount);
  }
  *stackPushSlot = branchInst;
  coneHasInterpLoad = 0;
  stackCount = vector[1];
  coneHasFetch = 0;
  do {
    stackTopSlot = (int *)0x0;
    if (stackCount - 1 < vector[1]) {
      stackTopSlot = (int *)((stackCount - 1) * 4 + vector[2]);
    }
    coneInst = *stackTopSlot;
    Vector__removeAt(vector,vector[1] - 1);
    if (0 < *(int *)(coneInst + 0x84)) {
      loopIndex = 1;
      do {
        operandVReg = (int *)IRInst__getOperandSource(coneInst,loopIndex);
        if (operandVReg != (int *)0x0) {
          vcall28Result = (**(code **)(*operandVReg + 0x28))(operandVReg);
          if (vcall28Result == 0) {
            vcall4cResult = (**(code **)(*operandVReg + 0x4c))(operandVReg);
            if (vcall4cResult != 0) {
              coneHasInterpLoad = 1;
            }
          }
          else {
            coneHasFetch = 1;
          }
          if ((bool)(coneHasFetch & coneHasInterpLoad)) {
            thenBlock = block[0x4d];
            elseBlock = block[0x4e];
            ifHeaderCheck = FUN_000e9294(block);
            if (ifHeaderCheck == 0) goto LAB_0013a198;
            thenBlockInst = *(int **)(thenBlock + 0x98);
            thenNextInst = (int *)(*(int **)(thenBlock + 0x98))[2];
            goto joined_r0x0013a104;
          }
          if (coneStamp != operandVReg[0x54]) {
            operandVReg[0x54] = coneStamp;
            stackCount = vector[1];
            if (stackCount < *vector) {
              _memset(stackCount * 4 + vector[2],0,4);
              stackPushSlot = (undefined4 *)(stackCount * 4 + vector[2]);
              vector[1] = stackCount + 1;
            }
            else {
              stackPushSlot = (undefined4 *)Vector__elementRefGrow(vector,stackCount);
            }
            *stackPushSlot = operandVReg;
          }
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= *(int *)(coneInst + 0x84));
    }
    stackCount = vector[1];
  } while (stackCount != 0);
LAB_0013a220:
  block[3] = block[3] | 0x400;
  return;
joined_r0x0013a104:
  if (thenNextInst == (int *)0x0) goto LAB_0013a148;
  if ((thenBlockInst[5] & 1U) != 0) {
    vcall28ResultB = (**(code **)(*thenBlockInst + 0x28))(thenBlockInst);
    if (vcall28ResultB != 0) goto LAB_0013a220;
    thenNextInst = (int *)thenBlockInst[2];
  }
  thenBlockInst = thenNextInst;
  thenNextInst = (int *)thenNextInst[2];
  goto joined_r0x0013a104;
LAB_0013a148:
  elseBlockInst = *(int **)(elseBlock + 0x98);
  elseNextInst = (int *)elseBlockInst[2];
  do {
    elseNextInstB = elseNextInst;
    if (elseNextInstB == (int *)0x0) {
LAB_0013a198:
      block[3] = block[3] | 0x800;
      return;
    }
    if ((elseBlockInst[5] & 1U) != 0) {
      vcall28ResultB = (**(code **)(*elseBlockInst + 0x28))(elseBlockInst);
      if (vcall28ResultB != 0) goto LAB_0013a220;
      elseNextInstB = (int *)elseBlockInst[2];
    }
    elseNextInst = (int *)elseNextInstB[2];
    elseBlockInst = elseNextInstB;
  } while( true );
}

/* FUN_0013a240 @ 0x13a240 (332 bytes) */
int FUN_0013a240(vector)
  uint *vector;
{
  int *pushSlot;
  uint orderCount;
  int countdown;
  char nextOperandIndex;
  uint topIndex;
  int *topSlot;
  char *keyByteCursor;
  int orderKey;
  undefined4 orderKeyBytes;
  
  topSlot = (int *)0x0;
  topIndex = vector[1] - 1;
  if (topIndex < vector[1]) {
    topSlot = (int *)(topIndex * 4 + vector[2]);
  }
  orderKey = *topSlot;
  Vector__removeAt(vector,vector[1] - 1);
  orderKeyBytes = orderKey;
  orderKey = orderKeyBytes;
  (*(unsigned char *)((unsigned char *)&(orderKeyBytes) + 3)) = (char)orderKey;
  orderKeyBytes = orderKey;
  if ((char)orderKeyBytes == '\0') {
    orderCount = vector[1];
    orderKey = orderKey + 1;
    if (orderCount < *vector) {
      _memset(orderCount * 4 + vector[2],0,4);
      pushSlot = (int *)(orderCount * 4 + vector[2]);
      vector[1] = orderCount + 1;
    }
    else {
      pushSlot = (int *)Vector__elementRefGrow(vector,orderCount);
    }
    *pushSlot = orderKey;
  }
  else {
    keyByteCursor = (char *)&orderKeyBytes;
    countdown = 4;
    do {
      if (*keyByteCursor != -1) {
        nextOperandIndex = keyByteCursor[1];
        *keyByteCursor = -1;
        orderKey = orderKeyBytes;
        orderCount = vector[1];
        if (orderCount < *vector) {
          _memset(orderCount * 4 + vector[2],0,4);
          pushSlot = (int *)(orderCount * 4 + vector[2]);
          vector[1] = orderCount + 1;
        }
        else {
          pushSlot = (int *)Vector__elementRefGrow(vector,orderCount);
        }
        *pushSlot = orderKey;
        return (int)nextOperandIndex;
      }
      keyByteCursor = keyByteCursor + 1;
      countdown = countdown + -1;
    } while (countdown != 0);
    orderKey = 0;
  }
  return orderKey;
}

/* FUN_0013a38c @ 0x13a38c (696 bytes) */
int FUN_0013a38c(inst, vector, program)
  int inst;
  uint *vector;
  undefined4 program;
{
  undefined4 sourceDef;
  undefined1 orderByteB;
  undefined1 orderByteA;
  bool swapped;
  int loopIndex;
  undefined4 *pushSlot;
  undefined4 orderKeyToPush;
  int loopIndexB;
  int useCountA;
  int *useCountCursor;
  int operandCount;
  uint vectorCount;
  int pairsRemaining;
  undefined4 orderKey;
  int useCounts [12];
  
  if (inst == 0) {
    return 1;
  }
  operandCount = *(int *)(inst + 0x84);
  orderKey = 0xffffffff;
  if (operandCount == 1) {
    vectorCount = vector[1];
    orderKey = 0x1ffffff;
    if (vectorCount < *vector) {
      _memset(vectorCount * 4 + vector[2],0,4);
      pushSlot = (undefined4 *)(vectorCount * 4 + vector[2]);
      vector[1] = vectorCount + 1;
    }
    else {
      pushSlot = (undefined4 *)Vector__elementRefGrow(vector,vectorCount);
    }
    *pushSlot = 0x1ffffff;
    return 1;
  }
  if (4 < operandCount) {
    vectorCount = vector[1];
    if (vectorCount < *vector) {
      _memset(vectorCount * 4 + vector[2],0,4);
      pushSlot = (undefined4 *)(vectorCount * 4 + vector[2]);
      vector[1] = vectorCount + 1;
    }
    else {
      pushSlot = (undefined4 *)Vector__elementRefGrow(vector,vectorCount);
    }
    *pushSlot = 1;
    return 1;
  }
  sourceDef = IRInst__getOperandSource(inst,1);
  useCounts[0] = IRInst__useCount(sourceDef,program);
  sourceDef = IRInst__getOperandSource(inst,2);
  useCounts[1] = IRInst__useCount(sourceDef,program);
  if (operandCount == 2) {
    if (useCounts[0] < useCounts[1]) {
      (*(unsigned int *)((unsigned char *)&(orderKey) + 1)) = CONCAT12(2,(*(unsigned short *)((unsigned char *)&(orderKey) + 2)));
      orderKey = CONCAT13(1,(*(unsigned int *)((unsigned char *)&(orderKey) + 1)));
    }
    else {
      (*(unsigned int *)((unsigned char *)&(orderKey) + 1)) = CONCAT12(1,(*(unsigned short *)((unsigned char *)&(orderKey) + 2)));
      orderKey = CONCAT13(2,(*(unsigned int *)((unsigned char *)&(orderKey) + 1)));
    }
    goto LAB_0013a5cc;
  }
  sourceDef = IRInst__getOperandSource(inst,3);
  useCounts[2] = IRInst__useCount(sourceDef,program);
  if (operandCount == 4) {
    sourceDef = IRInst__getOperandSource(inst,4);
    useCounts[3] = IRInst__useCount(sourceDef,program);
LAB_0013a528:
    loopIndex = 0;
    pairsRemaining = operandCount;
    do {
      *(char *)((int)useCounts + loopIndex + -4) = (char)(loopIndex + 1);
      pairsRemaining = pairsRemaining + -1;
      loopIndex = loopIndex + 1;
    } while (pairsRemaining != 0);
  }
  else if (0 < operandCount) goto LAB_0013a528;
  do {
    swapped = false;
    loopIndexB = 0;
    loopIndex = 0;
    useCountCursor = useCounts;
    pairsRemaining = operandCount;
    if (operandCount + -1 < 0) {
      pairsRemaining = 1;
    }
    while (pairsRemaining = pairsRemaining + -1, pairsRemaining != 0) {
      useCountA = *useCountCursor;
      if (useCountCursor[1] < useCountA) {
        orderByteA = *(undefined1 *)((int)useCounts + loopIndexB + -4);
        orderByteB = *(undefined1 *)((int)useCounts + loopIndex + -3);
        *useCountCursor = useCountCursor[1];
        *(undefined1 *)((int)useCounts + loopIndexB + -4) = orderByteB;
        swapped = true;
        useCountCursor[1] = useCountA;
        *(undefined1 *)((int)useCounts + loopIndex + -3) = orderByteA;
      }
      loopIndexB = loopIndexB + 1;
      loopIndex = loopIndex + 1;
      useCountCursor = useCountCursor + 1;
    }
  } while (swapped);
LAB_0013a5cc:
  orderKeyToPush = orderKey;
  vectorCount = vector[1];
  if (vectorCount < *vector) {
    _memset(vectorCount * 4 + vector[2],0,4);
    pushSlot = (undefined4 *)(vectorCount * 4 + vector[2]);
    vector[1] = vectorCount + 1;
  }
  else {
    pushSlot = (undefined4 *)Vector__elementRefGrow(vector,vectorCount);
  }
  *pushSlot = orderKeyToPush;
  return (int)(*(unsigned char *)((unsigned char *)&(orderKey) + 0));
}

/* FUN_0013a644 @ 0x13a644 (304 bytes) */
int FUN_0013a644(inst)
  int inst;
{
  uint usedComponent;
  bool moreComponents;
  uint userCount;
  undefined4 *userSlot;
  int operandRecord;
  int operandCount;
  uint usedComponentMask;
  uint loopIndex;
  int operandIdx;
  uint *usersVec;
  int *user;
  
  usedComponentMask = 0;
  usersVec = *(uint **)(inst + 0x10);
  userCount = usersVec[1];
  if (userCount != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *usersVec) {
        if (userCount <= loopIndex) {
          _memset(userCount * 4 + usersVec[2],0,(loopIndex - userCount) * 4 + 4);
          usersVec[1] = loopIndex + 1;
        }
        userSlot = (undefined4 *)(loopIndex * 4 + usersVec[2]);
      }
      else {
        userSlot = (undefined4 *)Vector__elementRefGrow(usersVec,loopIndex);
      }
      loopIndex = loopIndex + 1;
      user = (int *)*userSlot;
      for (operandIdx = 1; operandCount = (**(code **)(*user + 0x14))(user), operandIdx <= operandCount;
          operandIdx = operandIdx + 1) {
        operandCount = IRInst__getOperandSource(user,operandIdx);
        if (inst == operandCount) {
          operandCount = 0;
          do {
            operandRecord = IRInst__getOperandRecord(user,operandIdx);
            usedComponent = (uint)*(byte *)(operandCount + operandRecord + 0x10);
            if (usedComponent != 4) {
              usedComponentMask = usedComponentMask | 1 << (usedComponent & 0x3f);
            }
            moreComponents = operandCount != 3;
            operandCount = operandCount + 1;
          } while (moreComponents);
        }
      }
      usersVec = *(uint **)(inst + 0x10);
      userCount = usersVec[1];
    } while (loopIndex < userCount);
  }
  return usedComponentMask;
}

/* FUN_0013a774 @ 0x13a774 (304 bytes) */
int FUN_0013a774(inst, laneMask, clearLength)
  int *inst;
  uint laneMask;
  uint clearLength;
{
  uint usedComponent;
  undefined8 operandRecord;
  undefined8 sourceDef;
  bool moreComponents;
  uint userCount;
  int operandCount;
  uint extraout_r4;
  undefined4 a1;
  uint extraout_r4_00;
  uint loopIndex;
  uint remainingMask;
  undefined4 user;
  uint *usersVec;
  int operandIndex;
  undefined8 uVar9;
  
  usersVec = (uint *)inst[4];
  userCount = usersVec[1];
  remainingMask = laneMask;
  if (userCount != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *usersVec) {
        if (userCount <= loopIndex) {
          clearLength = (loopIndex - userCount) * 4 + 4;
          _memset(userCount * 4 + usersVec[2],0,clearLength);
          usersVec[1] = loopIndex + 1;
          laneMask = extraout_r4;
        }
        uVar9 = CONCAT44(loopIndex * 4 + usersVec[2],laneMask);
      }
      else {
        uVar9 = Vector__elementRefGrow(usersVec,loopIndex);
      }
      a1 = (undefined4)uVar9;
      user = *(undefined4 *)((ulonglong)uVar9 >> 0x20);
      for (operandIndex = 1; operandCount = (**(code **)(*inst + 0x14))(inst,a1,clearLength), operandIndex <= operandCount;
          operandIndex = operandIndex + 1) {
        sourceDef = IRInst__getOperandSource(user,operandIndex);
        a1 = (undefined4)sourceDef;
        if (inst == (int *)((ulonglong)sourceDef >> 0x20)) {
          operandCount = 0;
          do {
            operandRecord = IRInst__getOperandRecord(user,operandIndex);
            a1 = (undefined4)operandRecord;
            usedComponent = (uint)*(byte *)(operandCount + (int)((ulonglong)operandRecord >> 0x20) + 0x10);
            if ((usedComponent != 4) && (remainingMask = remainingMask & ~(1 << (usedComponent & 0x3f)), remainingMask == 0)) {
              return 0;
            }
            moreComponents = operandCount != 3;
            operandCount = operandCount + 1;
          } while (moreComponents);
        }
      }
      usersVec = (uint *)inst[4];
      loopIndex = loopIndex + 1;
      userCount = usersVec[1];
      laneMask = extraout_r4_00;
    } while (loopIndex < userCount);
  }
  return remainingMask;
}

/* FUN_0013a8a4 @ 0x13a8a4 (2372 bytes) */
int FUN_0013a8a4(pass)
  uint pass;
{
  bool moreComponentsB;
  bool laneByteZero;
  bool chainFailed;
  uint candidateMask;
  uint savedLaneWord;
  uint laneTagB;
  uint laneTag;
  uint foldMask;
  int *nextInst;
  int *targetInfo;
  int *sourceInst;
  int chainDestRecord;
  int componentIdxB;
  int sourceId;
  int operandRecordB;
  int laneTagValue;
  int nextBlockB;
  int laneEntryPtr;
  int sourceInstB;
  int laneIndex;
  int destOperandRecord;
  int srcDestRecord;
  int operandRecordA;
  int predicateResult;
  int laneFillIndex;
  int opcodeDesc;
  int destRecord;
  int flagResult;
  int operandIndex;
  int opcodeKind;
  bool moreComponents;
  bool sawRemappedComponent;
  byte laneTagByte;
  bool sawComponent3;
  uint usableMask;
  int blockCursor;
  int *lookaheadInst;
  int *chainInst;
  int laneTable;
  int operandLimit;
  int operandRecord;
  undefined4 staleArg5;
  undefined4 staleArg6;
  int laneEntryAddr;
  uint requiredLaneMask;
  uint componentIndex;
  int nextBlock;
  undefined4 compiler;
  uint operandComponent;
  code *setComponentFn;
  int laneCountdown;
  int *inst;
  undefined4 laneWord;
  uint maskedSelectWord;
  int currentBlock;
  int blockListObject;
  uint laneWordInsert1;
  uint laneWordInsert2;
  uint laneWordInsert3;
  uint laneWordInsert4;
  uint laneWordInsert5;
  uint laneWordInsert6;
  uint laneWordInsert7;
  uint laneWordInsert8;
  uint laneWordInsert9;
  uint laneWordInsert10;
  uint laneWordInsert11;
  uint laneWordInsert12;
  uint laneWordInsert13;
  uint laneWordInsert14;
  uint laneWordInsert15;
  uint laneWordInsert16;
  
  blockListObject = pass + 0x37c;
  laneTable = FUN_00193e74(*(undefined4 *)(*(int *)(pass + 8) + 0x378),
                       *(int *)(*(int *)(pass + 8) + 0x324) << 2,1);
  blockCursor = *(int *)(blockListObject + 8);
  laneWordInsert1 = 0;
  laneWordInsert2 = 0;
  laneWordInsert3 = 0;
  laneWordInsert4 = 0;
  laneWordInsert5 = 0;
  laneWordInsert6 = 0;
  laneWordInsert7 = 0;
  laneWordInsert8 = 0;
  laneWordInsert9 = 0;
  laneWordInsert10 = 0;
  laneWordInsert11 = 0;
  laneWordInsert12 = 0;
  laneWordInsert13 = 0;
  laneWordInsert14 = 0;
  laneWordInsert15 = 0;
  laneWordInsert16 = 0;
  nextBlock = *(int *)(blockCursor + 8);
  currentBlock = blockCursor;
  if (*(int *)(blockCursor + 8) != 0) {
    do {
      blockCursor = nextBlock;
      lookaheadInst = (int *)(*(int **)(currentBlock + 0x98))[2];
      inst = *(int **)(currentBlock + 0x98);
      if (lookaheadInst != (int *)0x0) {
        do {
          nextInst = lookaheadInst;
          if ((inst[5] & 1U) != 0) {
            opcodeKind = *(int *)(inst[0x22] + 8);
            for (operandIndex = 1; operandLimit = (**(code **)(*inst + 0x14))(inst), operandIndex <= operandLimit;
                operandIndex = operandIndex + 1) {
              sourceInst = (int *)IRInst__getOperandSource(inst,operandIndex);
              laneWord = *(uint *)(laneTable + sourceInst[0x53] * 4);
              if (opcodeKind == 0x8e) {
LAB_0013a9dc:
                laneFillIndex = 0;
                laneCountdown = 4;
                do {
                  *(byte *)((int)&laneWord + laneFillIndex) =
                       (byte)laneFillIndex & 0x3f | *(byte *)((int)&laneWord + laneFillIndex) & 0xc0 | 0x80;
                  laneFillIndex = laneFillIndex + 1;
                  laneCountdown = laneCountdown + -1;
                } while (laneCountdown != 0);
LAB_0013ae00:
                *(uint *)(laneTable + sourceInst[0x53] * 4) = laneWord;
              }
              else {
                compiler = *(undefined4 *)(pass + 8);
                predicateResult = (**(code **)(*sourceInst + 0x24))(sourceInst);
                if (((predicateResult == 0) || (predicateResult = OpcodeTraits__instFlagBit2(compiler,sourceInst), predicateResult != 0)) ||
                   ((sourceInst[5] & 0x400000U) != 0)) goto LAB_0013a9dc;
                sawComponent3 = false;
                sawRemappedComponent = false;
                usableMask = 0xf;
                requiredLaneMask = 0;
                componentIndex = 0;
                do {
                  operandRecordA = IRInst__getOperandRecord(inst,operandIndex);
                  operandComponent = (uint)*(byte *)(componentIndex + operandRecordA + 0x10);
                  srcDestRecord = IRInst__getOperandRecord(sourceInst,0);
                  if (*(char *)(componentIndex + srcDestRecord + 0x10) != '\x01') {
                    usableMask = usableMask & ~(1 << (componentIndex & 0x3f));
                  }
                  if (operandComponent != 4) {
                    if (operandComponent == 3) {
                      laneWordInsert1 = laneWord << 0x18 | laneWordInsert1 & 0xffffff;
                      if (((int)laneWordInsert1 < 0) &&
                         (laneWordInsert2 = laneWord << 0x18 | laneWordInsert2 & 0xffffff, (laneWord & 0x3f) != 3)
                         ) {
                        usableMask = usableMask & 0xfffffff7;
                        sawComponent3 = true;
                        laneWordInsert3 = laneWord << 0x18 | laneWordInsert3 & 0xffffff;
                        requiredLaneMask = requiredLaneMask | 1 << (laneWord & 0x3f);
                      }
                      else {
                        usableMask = usableMask & 0xfffffff7;
                        sawComponent3 = true;
                        laneWordInsert4 = (laneWord & 0xc0) << 0x18 | laneWordInsert4 & 0xffffff | 0x3000000;
                        laneWord = CONCAT31((*(unsigned int *)((unsigned char *)&(laneWord) + 0)),(char)(laneWordInsert4 >> 0x18));
                      }
                    }
                    else {
                      laneWordInsert5 = laneWord << 0x18 | laneWordInsert5 & 0xffffff;
                      if (((int)laneWordInsert5 < 0) &&
                         (laneWordInsert6 = laneWord << 0x18 | laneWordInsert6 & 0xffffff,
                         operandComponent == (laneWord & 0x3f))) {
                        usableMask = 0;
                        laneWordInsert7 = (laneWord & 0xc0) << 0x18 | laneWordInsert7 & 0xffffff | 0x3000000;
                        laneWord = CONCAT31((*(unsigned int *)((unsigned char *)&(laneWord) + 0)),(char)(laneWordInsert7 >> 0x18));
                        laneWordInsert8 = (operandComponent & 0x3f) << 0x18 |
                                   (*(byte *)((int)&laneWord + operandComponent) & 0xc0) << 0x18 |
                                   laneWordInsert8 & 0xffffff;
                        *(char *)((int)&laneWord + operandComponent) = (char)(laneWordInsert8 >> 0x18);
                      }
                      else {
                        usableMask = usableMask & ~(1 << (operandComponent & 0x3f));
                        sawRemappedComponent = true;
                        laneWordInsert9 = (operandComponent & 0x3f) << 0x18 |
                                   (*(byte *)((int)&laneWord + operandComponent) & 0xc0) << 0x18 |
                                   laneWordInsert9 & 0xffffff;
                        *(char *)((int)&laneWord + operandComponent) = (char)(laneWordInsert9 >> 0x18);
                      }
                    }
                    *(byte *)((int)&laneWord + operandComponent) = *(byte *)((int)&laneWord + operandComponent) | 0x80;
                  }
                  moreComponents = componentIndex != 3;
                  componentIndex = componentIndex + 1;
                } while (moreComponents);
                if (((((usableMask != 0) && (sawRemappedComponent)) && (sawComponent3)) &&
                    ((candidateMask = usableMask, requiredLaneMask == 0 || (candidateMask = requiredLaneMask, (usableMask & requiredLaneMask) != 0)))) &&
                   (foldMask = ((int (*)())FUN_0013a774)(sourceInst,candidateMask,pass), foldMask != 0)) {
                  destOperandRecord = IRInst__getOperandRecord(sourceInst,0);
                  if (*(char *)(destOperandRecord + 0x13) == '\x01') {
                    if ((sourceInst[5] & 0x200U) != 0) {
                      chainInst = (int *)IRInst__getOperandSource(sourceInst,sourceInst[0x21]);
                      chainFailed = false;
                      for (; chainInst != (int *)0x0; chainInst = (int *)IRInst__getOperandSource(chainInst,chainInst[0x21])
                          ) {
                        destOperandRecord = IRInst__getOperandRecord(chainInst,0);
                        if (*(char *)(destOperandRecord + 0x13) == '\x01') {
                          foldMask = ((int (*)())FUN_0013a774)(chainInst,foldMask,pass);
                          chainFailed = foldMask == 0;
                        }
                        else {
                          predicateResult = (**(code **)(*chainInst + 0x24))(chainInst);
                          if ((predicateResult == 0) ||
                             (predicateResult = OpcodeTraits__instFlagBit2(*(undefined4 *)(pass + 8),chainInst),
                             predicateResult != 0)) goto LAB_0013ae10;
                        }
                        if (chainFailed) goto LAB_0013ae10;
                        if ((chainInst[5] & 0x200U) == 0) break;
                      }
                    }
                    if ((foldMask & 1) == 0) {
                      if ((foldMask & 2) == 0) {
                        laneIndex = 2;
                        laneTagValue = 2;
                      }
                      else {
                        laneIndex = 1;
                        laneTagValue = 1;
                      }
                    }
                    else {
                      laneIndex = 0;
                      laneTagValue = 0;
                    }
                    operandRecord = IRInst__getOperandRecord(sourceInst,0);
                    if ((*(char *)(operandRecord + 0x13) == '\x01') && ((sourceInst[5] & 0x200U) != 0)) {
                      for (operandRecord = IRInst__getOperandSource(sourceInst,sourceInst[0x21]); operandRecord != 0;
                          operandRecord = IRInst__getOperandSource(operandRecord,*(undefined4 *)(operandRecord + 0x84))) {
                        laneEntryAddr = laneTable + *(int *)(operandRecord + 0x14c) * 4;
                        laneWordInsert10 = laneTagValue << 0x18 |
                                   (*(byte *)(laneEntryAddr + 3) & 0xc0) << 0x18 | laneWordInsert10 & 0xffffff;
                        *(char *)(laneEntryAddr + 3) = (char)(laneWordInsert10 >> 0x18);
                        laneEntryAddr = laneTable + *(int *)(operandRecord + 0x14c) * 4;
                        laneWordInsert11 = (uint)*(byte *)(laneEntryAddr + 3) << 0x18 | laneWordInsert11 & 0xffffff |
                                   0x80000000;
                        *(char *)(laneEntryAddr + 3) = (char)(laneWordInsert11 >> 0x18);
                        laneEntryAddr = laneTable + *(int *)(operandRecord + 0x14c) * 4;
                        laneWordInsert12 = (uint)*(byte *)(laneEntryAddr + laneIndex) << 0x18 | laneWordInsert12 & 0xffffff |
                                   0x80000000;
                        *(char *)(laneEntryAddr + laneIndex) = (char)(laneWordInsert12 >> 0x18);
                        chainDestRecord = IRInst__getOperandRecord(operandRecord,0);
                        if ((*(char *)(chainDestRecord + 0x13) != '\x01') ||
                           ((*(uint *)(operandRecord + 0x14) & 0x200) == 0)) break;
                      }
                    }
                    laneWordInsert13 = laneTagValue << 0x18 | (laneWord & 0xc0) << 0x18 | laneWordInsert13 & 0xffffff;
                    laneWord = CONCAT31((*(unsigned int *)((unsigned char *)&(laneWord) + 0)),(char)(laneWordInsert13 >> 0x18));
                  }
                  goto LAB_0013ae00;
                }
              }
LAB_0013ae10: ;
            }
            nextInst = (int *)inst[2];
          }
          lookaheadInst = (int *)nextInst[2];
          inst = nextInst;
        } while ((int *)nextInst[2] != (int *)0x0);
        blockCursor = *(int *)(currentBlock + 8);
      }
      nextBlock = *(int *)(blockCursor + 8);
      currentBlock = blockCursor;
    } while (*(int *)(blockCursor + 8) != 0);
    blockCursor = *(int *)(blockListObject + 8);
  }
  nextBlock = *(int *)(blockCursor + 8);
  while (nextBlockB = nextBlock, nextBlockB != 0) {
    inst = *(int **)(blockCursor + 0x98);
    lookaheadInst = (int *)inst[2];
    if ((int *)inst[2] != (int *)0x0) {
      do {
        nextInst = lookaheadInst;
        if ((inst[5] & 1U) != 0) {
          flagResult = (**(code **)(*inst + 0x24))(inst);
          if ((flagResult != 0) &&
             (flagResult = OpcodeTraits__instFlagBit2(*(undefined4 *)(pass + 8),inst), flagResult == 0)) {
            laneTag = (uint)*(byte *)(inst[0x53] * 4 + laneTable + 3);
            laneWordInsert14 = laneTag << 0x18 | laneWordInsert14 & 0xffffff;
            if ((int)laneWordInsert14 < 0) {
              laneWordInsert15 = laneTag << 0x18 | laneWordInsert15 & 0xffffff;
              laneTag = laneTag & 0x3f;
              IRInst__getOperandRecord(inst,0);
              if (laneTag != 3) {
                destRecord = IRInst__getOperandRecord(inst,0);
                SelectWord__selectWhereMasked(&maskedSelectWord,*(undefined4 *)(destRecord + 0x10),inst[3]);
                laneWord = maskedSelectWord;
                savedLaneWord = laneWord;
                (*(unsigned char *)((unsigned char *)&(laneWord) + 3)) = (char)maskedSelectWord;
                laneByteZero = (char)laneWord == '\0';
                laneWord = savedLaneWord;
                if (laneByteZero) {
                  (*(unsigned int *)((unsigned char *)&(laneWord) + 0)) = (undefined3)(maskedSelectWord >> 8);
                  laneWord = CONCAT31((*(unsigned int *)((unsigned char *)&(laneWord) + 0)),1);
                  *(undefined1 *)((int)&laneWord + laneTag) = 0;
                  opcodeDesc = inst[0x22];
                  *(undefined1 *)((int)inst + 0xf) = 0;
                  *(undefined1 *)((int)inst + laneTag + 0xc) = 1;
                  flagResult = OpcodeTraits__flagBit7(*(undefined4 *)(opcodeDesc + 8),*(undefined4 *)(pass + 8));
                  if (flagResult == 0) {
                    for (operandIndex = 1; operandLimit = (**(code **)(*inst + 0x14))(inst),
                        operandIndex <= operandLimit; operandIndex = operandIndex + 1) {
                      sourceInstB = IRInst__getOperandSource(inst,operandIndex);
                      operandRecordB = IRInst__getOperandRecord(inst,operandIndex);
                      if (*(char *)(laneTag + operandRecordB + 0x10) != '\x04') {
                        IRInst__getOperandRecord(inst,operandIndex);
                        IRInst__getOperandRecord(inst,operandIndex);
                      }
                      setComponentFn = *(code **)(*inst + 0x88);
                      operandRecordB = IRInst__getOperandRecord(inst,operandIndex);
                      (*setComponentFn)(inst,operandIndex,laneTag,*(undefined1 *)(operandRecordB + 0x13));
                      (**(code **)(*inst + 0x88))
                                (inst,operandIndex,3,4,staleArg5,staleArg6,*(code **)(*inst + 0x88));
                      if (*(int *)(sourceInstB + 0x98) == 0x33) {
                        (**(code **)(*inst + 0x88))(inst,operandIndex,laneTag,laneTag);
                        *(undefined1 *)(sourceInstB + laneTag + 0x9c) = 0;
                        *(undefined1 *)(sourceInstB + laneTag + 0xc) = 1;
                      }
                    }
                  }
                  targetInfo = *(int **)(*(int *)(pass + 8) + 0x30c);
                  flagResult = (**(code **)(*targetInfo + 0x7c))(targetInfo,inst);
                  if (flagResult != 0) {
                    inst[0x27] = laneWord;
                  }
                }
              }
            }
          }
          for (operandIndex = 1; operandLimit = (**(code **)(*inst + 0x14))(inst), operandIndex <= operandLimit;
              operandIndex = operandIndex + 1) {
            sourceInst = (int *)IRInst__getOperandSource(inst,operandIndex);
            sourceId = sourceInst[0x53];
            predicateResult = (**(code **)(*sourceInst + 0x24))(sourceInst);
            if (predicateResult != 0) {
              laneEntryPtr = laneTable + sourceId * 4;
              laneTagByte = *(byte *)(laneEntryPtr + 3);
              if (((int)((uint)laneTagByte << 0x18) < 0) && ((laneTagByte & 0x3f) != 3)) {
                componentIdxB = 0;
                do {
                  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
                  if (*(char *)(componentIdxB + operandRecord + 0x10) == '\x03') {
                    laneTagB = (uint)*(byte *)(laneEntryPtr + 3);
                    laneWordInsert16 = laneTagB << 0x18 | laneWordInsert16 & 0xffffff;
                    (**(code **)(*inst + 0x88))
                              (inst,operandIndex,componentIdxB,laneTagB & 0x3f,staleArg5,staleArg6,
                               *(code **)(*inst + 0x88));
                  }
                  moreComponentsB = componentIdxB != 3;
                  componentIdxB = componentIdxB + 1;
                } while (moreComponentsB);
              }
            }
          }
          nextInst = (int *)inst[2];
        }
        lookaheadInst = (int *)nextInst[2];
        inst = nextInst;
      } while ((int *)nextInst[2] != (int *)0x0);
      nextBlockB = *(int *)(blockCursor + 8);
    }
    blockCursor = nextBlockB;
    nextBlock = *(int *)(nextBlockB + 8);
  }
  return Arena__free(*(undefined4 *)(*(int *)(pass + 8) + 0x378),laneTable);
}

/* FUN_0013b1e8 @ 0x13b1e8 (520 bytes) */
int FUN_0013b1e8(producer, program)
  int producer;
  int program;
{
  int *userBlock;
  int successorCount;
  int userInst;
  int userBlockDepth;
  bool noCommonYet;
  int operandCursor;
  uint userCount;
  int *elementPtr;
  int operandVReg;
  int iVar6;
  int *commonBlock;
  uint loopIndex;
  int *nextCommonBlock;
  uint *userVec;
  int operandIdx;
  
  commonBlock = (int *)0x0;
  for (loopIndex = 0; iVar6 = IRInst__useCount(producer,program), (int)loopIndex < iVar6; loopIndex = loopIndex + 1) {
    userVec = *(uint **)(producer + 0x10);
    if (loopIndex < *userVec) {
      userCount = userVec[1];
      if (userCount <= loopIndex) {
        _memset(userCount * 4 + userVec[2],0,(loopIndex - userCount) * 4 + 4);
        userVec[1] = loopIndex + 1;
      }
      elementPtr = (int *)(loopIndex * 4 + userVec[2]);
    }
    else {
      elementPtr = (int *)Vector__elementRefGrow(userVec,loopIndex);
    }
    userInst = *elementPtr;
    userBlock = *(int **)(userInst + 0x158);
    if ((userBlock[3] & 0x40U) != 0) goto LAB_0013b3c4;
    if (*(int *)(*(int *)(userInst + 0x88) + 8) == 0x8e) {
      operandCursor = 0;
      do {
        operandIdx = operandCursor;
        if (*(int *)(userInst + 0x84) <= operandIdx) goto LAB_0013b2d8;
        operandVReg = IRInst__getOperandSource(userInst,operandIdx + 1);
        operandCursor = operandIdx + 1;
      } while (producer != operandVReg);
      userBlock = (int *)Block__getPredecessor(userBlock,operandIdx);
    }
LAB_0013b2d8:
    iVar6 = (**(code **)(*userBlock + 0x24))(userBlock);
    if ((iVar6 != 0) && (userBlock = (int *)Block__getPredecessor(userBlock,0), userBlock == (int *)0x0))
    goto LAB_0013b3c4;
    noCommonYet = commonBlock == (int *)0x0;
    nextCommonBlock = userBlock;
    if ((!noCommonYet) && (nextCommonBlock = commonBlock, commonBlock != userBlock)) {
      do {
        userBlockDepth = userBlock[0x2f];
        iVar6 = commonBlock[0x2f];
        if (iVar6 < userBlockDepth) {
          userBlock = (int *)userBlock[0x3c];
LAB_0013b318:
          if (userBlock == (int *)0x0) goto LAB_0013b3c4;
          noCommonYet = commonBlock == (int *)0x0;
        }
        else if (userBlockDepth < iVar6) {
          commonBlock = (int *)commonBlock[0x3c];
          noCommonYet = commonBlock == (int *)0x0;
        }
        else if (userBlockDepth == iVar6) {
          userBlock = (int *)userBlock[0x3c];
          commonBlock = (int *)commonBlock[0x3c];
          goto LAB_0013b318;
        }
        nextCommonBlock = userBlock;
      } while ((!noCommonYet) && (nextCommonBlock = commonBlock, commonBlock != userBlock));
    }
    commonBlock = nextCommonBlock;
  }
  successorCount = Block__successorCount(commonBlock);
  if (((1 < successorCount) && (commonBlock = (int *)Block__getPredecessor(commonBlock,0), commonBlock == *(int **)(producer + 0x158))
      ) || (successorCount = ((int (*)())FUN_00139294)(commonBlock,*(undefined4 *)(program + 0x3a0)), successorCount == 0)) {
LAB_0013b3c4:
    commonBlock = (int *)0x0;
  }
  return commonBlock;
}

/* Program__hoistFetchInsts @ 0x13b3f0 (172 bytes) */
int Program__hoistFetchInsts(program)
  int program;
{
  uint useIndex;
  uint userCount;
  uint worklistCount;
  uint hoistedCount;
  uint userCountB;
  undefined4 *newBlock;
  undefined4 *newBlockAllocB;
  int *homeBlock;
  int operandIndex;
  int vcall50Result;
  int hoistedInst;
  int succByteOffset;
  int vcall14Result;
  int inst;
  int blockReachable;
  int vcall2cResult;
  int vcall34Result;
  int vcall28Result;
  int vcall24Result;
  int predecessorCountResult;
  int operandSource;
  undefined4 vectorData;
  undefined4 arena;
  undefined4 *vectorAlloc;
  uint loopIndex3;
  undefined *blockVtable;
  int *otherPred;
  int nextInst;
  int nextBlock;
  undefined4 *allocation;
  int hoistTarget;
  int vcall24ResultB;
  int *piVar8;
  undefined4 *newBlockAlloc;
  undefined4 *puVar10;
  uint worklistIndex;
  int *piVar12;
  uint loopIndex;
  uint *hoistedVec;
  int entryBlock;
  uint nextWorklistIndex;
  uint *worklistVec;
  int loopIndex2;
  int *loopExit;
  int *piVar20;
  undefined4 operandSourceB;
  int *piVar22;
  int block;
  uint blockFlags;
  uint *puVar25;
  
  block = *(int *)(program + 0x3a8);
  while ((block != 0 && (predecessorCountResult = Block__predecessorCount(block), predecessorCountResult != 0))) {
    *(uint *)(block + 0xc) = *(uint *)(block + 0xc) | 0x40;
    block = *(int *)(block + 0xf0);
  }
  entryBlock = *(int *)(program + 0x3a0);
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  hoistedVec = allocation + 1;
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  block = *(int *)(program + 900);
  for (nextBlock = *(int *)(*(int *)(program + 900) + 8); nextBlock != 0; nextBlock = *(int *)(nextBlock + 8)) {
    if (block != entryBlock) {
      blockReachable = ((int (*)())FUN_00139294)(block,entryBlock);
      if (blockReachable != 0) {
        inst = *(int *)(block + 0x98);
        for (nextInst = *(int *)(*(int *)(block + 0x98) + 8); nextInst != 0; nextInst = *(int *)(nextInst + 8))
        {
          loopIndex2 = 0;
          if ((*(uint *)(inst + 0x14) & 1) != 0) {
            while (loopIndex2 < *(int *)(inst + 0x84)) {
              loopIndex2 = loopIndex2 + 1;
              operandSource = IRInst__getOperandSource(inst,loopIndex2);
              hoistTarget = ((int (*)())IRInst__isOpcodeInSet139344)(operandSource);
              if ((((hoistTarget != 0) && (*(int *)(*(int *)(operandSource + 0x158) + 0xb8) == 0)) &&
                  (hoistTarget = ((int (*)())FUN_0013b1e8)(operandSource,program), hoistTarget != 0)) &&
                 (hoistTarget != *(int *)(operandSource + 0x158))) {
                piVar8 = *(int **)(hoistTarget + 0xf0);
                while ((piVar8 != (int *)0x0 &&
                       (vcall24ResultB = (**(code **)(*piVar8 + 0x24))(piVar8), vcall24ResultB == 0))) {
                  blockFlags = piVar8[3];
                  if ((blockFlags & 0x40) != 0) goto LAB_0013b588;
                  piVar8 = (int *)piVar8[0x3c];
                }
                blockFlags = piVar8[3];
LAB_0013b588:
                if ((blockFlags & 0x800) == 0) {
                  hoistedCount = allocation[2];
                  if (hoistedCount < *hoistedVec) {
                    _memset((void *)(hoistedCount * 4 + allocation[3]),0,4);
                    piVar8 = (int *)(hoistedCount * 4 + allocation[3]);
                    allocation[2] = hoistedCount + 1;
                  }
                  else {
                    piVar8 = (int *)Vector__elementRefGrow(hoistedVec,hoistedCount);
                  }
                  *piVar8 = operandSource;
                  IRInst__unlinkAndClearFlag0(operandSource);
                  *(uint *)(operandSource + 0x14) = *(uint *)(operandSource + 0x14) | 1;
                  Block__prependInst(hoistTarget,operandSource);
                }
              }
            }
            nextInst = *(int *)(inst + 8);
          }
          inst = nextInst;
        }
      }
      nextBlock = *(int *)(block + 8);
    }
    block = nextBlock;
  }
  hoistedCount = allocation[2];
  if (hoistedCount == 0) {
    return;
  }
  loopIndex = 0;
code_r0x0013b658:
  if (loopIndex < *hoistedVec) {
    if (hoistedCount <= loopIndex) {
      _memset((void *)(hoistedCount * 4 + allocation[3]),0,(loopIndex - hoistedCount) * 4 + 4);
      allocation[2] = loopIndex + 1;
    }
    piVar8 = (int *)(loopIndex * 4 + allocation[3]);
  }
  else {
    piVar8 = (int *)Vector__elementRefGrow(hoistedVec,loopIndex);
  }
  hoistedInst = *piVar8;
  homeBlock = *(int **)(hoistedInst + 0x158);
  if (homeBlock == (int *)0x0) {
    piVar20 = (int *)0x0;
    piVar12 = (int *)0x0;
  }
  else {
    piVar12 = (int *)0x0;
    piVar22 = homeBlock;
    do {
      vcall14Result = (**(code **)(*piVar22 + 0x14))(piVar22);
      if (vcall14Result != 0) goto code_r0x0013ba08;
      vcall24Result = (**(code **)(*piVar22 + 0x24))(piVar22);
      piVar20 = piVar22;
      if (vcall24Result != 0) break;
      vcall28Result = (**(code **)(*piVar22 + 0x28))(piVar22);
      if (vcall28Result == 0) {
        vcall34Result = (**(code **)(*piVar22 + 0x34))(piVar22);
        if (vcall34Result == 0) {
          vcall2cResult = (**(code **)(*piVar22 + 0x2c))(piVar22);
          if (vcall2cResult == 0) {
            piVar20 = (int *)Block__getPredecessor(piVar22,0);
          }
          else {
            piVar20 = (int *)Block__findSimplePredecessor(piVar22);
          }
        }
        else {
          piVar22 = (int *)piVar22[0x4b];
          piVar20 = (int *)Block__findSimplePredecessor(piVar22);
        }
      }
      else {
        piVar22 = (int *)piVar22[0x4b];
        piVar20 = (int *)Block__getPredecessor(piVar22,0);
      }
      piVar12 = piVar22;
      piVar22 = piVar20;
    } while (piVar20 != (int *)0x0);
  }
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  newBlockAlloc = (undefined4 *)Arena__alloc(arena,0x134);
  *newBlockAlloc = arena;
  piVar22 = newBlockAlloc + 1;
  AnyBlock__ctor_ea3c0(piVar22,*(undefined4 *)(program + 8));
  if (piVar12 == (int *)piVar20[0x4e]) {
    piVar20[0x4e] = (int)piVar22;
  }
  Program__insertBlockBefore(program,piVar12,piVar22);
  Block__splitOutgoingEdge(piVar20,piVar12,piVar22);
  Block__connect(piVar22,piVar12);
  loopExit = (int *)piVar20[0x4f];
  piVar20 = homeBlock;
  piVar12 = homeBlock;
  do {
    vcall28Result = (**(code **)(*piVar12 + 0x28))(piVar12);
    if ((vcall28Result != 0) && (piVar12 == loopExit)) {
      succByteOffset = 0;
      for (loopIndex3 = 1; loopIndex3 <= *(uint *)(piVar12[0x35] + 4); loopIndex3 = loopIndex3 + 1) {
        otherPred = *(int **)(*(int *)(piVar12[0x35] + 8) + succByteOffset);
        if ((otherPred != (int *)0x0) && (piVar20 != otherPred)) goto code_r0x0013b8e4;
        succByteOffset = succByteOffset + 4;
      }
      otherPred = (int *)0x0;
code_r0x0013b8e4:
      vcall14Result = (**(code **)(*otherPred + 0x18))(otherPred);
      if (vcall14Result == 0) break;
    }
    vcall24Result = (**(code **)(*piVar12 + 0x24))(piVar12);
    piVar20 = piVar12;
    if (vcall24Result != 0) {
      piVar20 = (int *)Block__getSuccessor(piVar12[0x4f],0);
    }
    vcall14Result = (**(code **)(*piVar20 + 0x2c))(piVar20);
    if (vcall14Result != 0) {
      piVar20 = (int *)piVar20[0x55];
    }
    otherPred = (int *)Block__getSuccessor(piVar20,0);
    piVar20 = piVar12;
    piVar12 = otherPred;
  } while( true );
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  newBlockAllocB = (undefined4 *)Arena__alloc(arena,0x134);
  *newBlockAllocB = arena;
  newBlock = newBlockAllocB + 1;
  Block__ctor_ea148(newBlock,*(undefined4 *)(program + 8));
  blockVtable = PTR_DAT_001e9134;
  newBlockAllocB[0x4c] = piVar22;
  newBlockAllocB[1] = blockVtable + 8;
  Program__insertBlockAfter(program,otherPred,newBlock);
  Block__splitIncomingEdge(piVar12,otherPred,newBlock);
  Block__connect(otherPred,newBlock);
code_r0x0013ba08:
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
  worklistVec = vectorAlloc + 1;
  *vectorAlloc = arena;
  vectorAlloc[1] = 2;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arena;
  vectorData = Arena__alloc(arena,8);
  vectorAlloc[3] = vectorData;
  operandSourceB = IRInst__getOperandSource(hoistedInst,1);
  worklistCount = vectorAlloc[2];
  if (worklistCount < (uint)vectorAlloc[1]) {
    _memset((void *)(worklistCount * 4 + vectorAlloc[3]),0,4);
    puVar10 = (undefined4 *)(worklistCount * 4 + vectorAlloc[3]);
    vectorAlloc[2] = worklistCount + 1;
  }
  else {
    puVar10 = (undefined4 *)Vector__elementRefGrow(worklistVec,worklistCount);
  }
  *puVar10 = operandSourceB;
  worklistCount = vectorAlloc[2];
  if (worklistCount != 0) {
    worklistIndex = 0;
    do {
      if (worklistIndex < *worklistVec) {
        if (worklistCount <= worklistIndex) {
          _memset((void *)(worklistCount * 4 + vectorAlloc[3]),0,(worklistIndex - worklistCount) * 4 + 4);
          vectorAlloc[2] = worklistIndex + 1;
        }
        puVar10 = (undefined4 *)(worklistIndex * 4 + vectorAlloc[3]);
      }
      else {
        puVar10 = (undefined4 *)Vector__elementRefGrow(worklistVec,worklistIndex);
      }
      nextWorklistIndex = worklistIndex + 1;
      piVar20 = (int *)*puVar10;
      if ((int *)piVar20[0x56] != piVar22) {
        if (worklistIndex == 0) {
          puVar25 = (uint *)piVar22[0x4b];
          userCount = puVar25[1];
          if (userCount < *puVar25) {
            _memset((void *)(userCount * 4 + puVar25[2]),0,4);
            puVar10 = (undefined4 *)(userCount * 4 + puVar25[2]);
            puVar25[1] = userCount + 1;
          }
          else {
            puVar10 = (undefined4 *)Vector__elementRefGrow(puVar25,userCount);
          }
          *puVar10 = piVar20;
        }
        if ((((piVar20[5] & 8U) == 0) && (*(int *)(piVar20[0x22] + 8) != 0x8e)) &&
           (piVar20[0x56] != *(int *)(program + 0x3a0))) {
          useIndex = 0;
          vcall50Result = (**(code **)(*piVar20 + 0x50))(piVar20);
          if (vcall50Result == 0) {
            for (; vcall50Result = IRInst__useCount(piVar20,program), (int)useIndex < vcall50Result; useIndex = useIndex + 1
                ) {
              puVar25 = (uint *)piVar20[4];
              if (useIndex < *puVar25) {
                userCountB = puVar25[1];
                if (userCountB <= useIndex) {
                  _memset((void *)(userCountB * 4 + puVar25[2]),0,(useIndex - userCountB) * 4 + 4);
                  puVar25[1] = useIndex + 1;
                }
                piVar12 = (int *)(useIndex * 4 + puVar25[2]);
              }
              else {
                piVar12 = (int *)Vector__elementRefGrow(puVar25,useIndex);
              }
              if ((piVar22 != *(int **)(*piVar12 + 0x158)) &&
                 (homeBlock != *(int **)(*piVar12 + 0x158))) goto code_r0x0013bd34;
            }
            IRInst__unlinkAndClearFlag0(piVar20);
            piVar20[5] = piVar20[5] | 1;
            Block__prependInst(piVar22,piVar20);
            for (operandIndex = 1; vcall14Result = (**(code **)(*piVar20 + 0x14))(piVar20), operandIndex < vcall14Result;
                operandIndex = operandIndex + 1) {
              operandSourceB = IRInst__getOperandSource(piVar20,operandIndex);
              worklistCount = vectorAlloc[2];
              if (worklistCount < *worklistVec) {
                _memset((void *)(worklistCount * 4 + vectorAlloc[3]),0,4);
                puVar10 = (undefined4 *)(worklistCount * 4 + vectorAlloc[3]);
                vectorAlloc[2] = worklistCount + 1;
              }
              else {
                puVar10 = (undefined4 *)Vector__elementRefGrow(worklistVec,worklistCount);
              }
              *puVar10 = operandSourceB;
            }
          }
        }
      }
code_r0x0013bd34:
      worklistCount = vectorAlloc[2];
      worklistIndex = nextWorklistIndex;
    } while (nextWorklistIndex < worklistCount);
  }
  hoistedCount = allocation[2];
  loopIndex = loopIndex + 1;
  if (hoistedCount <= loopIndex) {
    return;
  }
  goto code_r0x0013b658;
}

/* Program__eliminateDeadInstsAndRecountUses @ 0x13bd68 (1124 bytes) */
int Program__eliminateDeadInstsAndRecountUses(program, verifyCounts)
  int program;
  int verifyCounts;
{
  int statsSlot;
  int *lookaheadInst;
  int *topElementPtr;
  int liveRoot;
  int block;
  int instByteOffset;
  int clampedUseCount;
  int nextInstCursor;
  uint countBefore;
  int slotByteOffset;
  int operandSource;
  int loopIndex;
  bool skipVerify;
  int instVector;
  int nextInstScan;
  int nextBlock;
  int *curNext;
  int savedUseCounts;
  int *elementPtr;
  uint topIndex;
  int compiler;
  int instScan;
  int epochIndex;
  uint loopIndex2;
  undefined4 consistent;
  int *inst;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_54_buf [0x10];
  #define vecCapacity (*(uint *)(local_54_buf + 0x00))
  #define vecCount (*(uint *)(local_54_buf + 0x04))
  #define vecData (*(int *)(local_54_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_54_buf + 0x0c))
  
  skipVerify = verifyCounts == 0;
  epochIndex = *(int *)(program + 0x2ac);
  compiler = *(int *)(program + PROG_compiler);
  *(int *)(program + 0x2ac) = epochIndex + 1;
  instVector = *(int *)(compiler + 0x324);
  if (skipVerify) {
    savedUseCounts = 0;
  }
  else {
    savedUseCounts = Arena__alloc(*(undefined4 *)(compiler + 0x378),instVector << 2);
    block = *(int *)(program + PROG_blockListHead);
    for (nextBlock = *(int *)(*(int *)(program + PROG_blockListHead) + 8); nextBlock != 0; nextBlock = *(int *)(nextBlock + 8)) {
      nextInstScan = *(int *)(*(int *)(block + 0x98) + 8);
      instScan = *(int *)(block + 0x98);
      if (nextInstScan != 0) {
        do {
          nextInstCursor = nextInstScan;
          if ((*(uint *)(instScan + 0x14) & 1) != 0) {
            clampedUseCount = *(int *)(instScan + 0x160) - *(int *)(program + PROG_useEpoch);
            if (clampedUseCount < 0) {
              clampedUseCount = 0;
            }
            *(int *)(*(int *)(instScan + 0x14c) * 4 + savedUseCounts) = clampedUseCount;
            nextInstCursor = *(int *)(instScan + 8);
          }
          nextInstScan = *(int *)(nextInstCursor + 8);
          instScan = nextInstCursor;
        } while (*(int *)(nextInstCursor + 8) != 0);
        nextBlock = *(int *)(block + 8);
      }
      block = nextBlock;
    }
    compiler = *(int *)(program + PROG_compiler);
  }
  instByteOffset = 0;
  *(int *)(program + PROG_visitStamp) = *(int *)(program + PROG_visitStamp) + 1;
  *(int *)(program + PROG_useEpoch) = instVector * 4 + *(int *)(program + PROG_useEpoch);
  vecArena = *(undefined4 *)(compiler + 0x378);
  vecCapacity = 2;
  vecCount = 0;
  vecData = Arena__alloc(vecArena,8);
  instVector = *(int *)(program + PROG_instructionVector);
  for (loopIndex2 = 1; loopIndex2 <= *(uint *)(instVector + 4); loopIndex2 = loopIndex2 + 1) {
    liveRoot = *(int *)(*(int *)(instVector + 8) + instByteOffset);
    if ((*(uint *)(liveRoot + 0x14) & 1) != 0) {
      instVector = IRInst__getOperandRecord(liveRoot,0);
      countBefore = vecCount;
      if ((*(int *)(instVector + 0x10) != DAT_001b0014) &&
         (*(int *)(program + PROG_visitStamp) != *(int *)(liveRoot + 0x150))) {
        *(int *)(liveRoot + 0x150) = *(int *)(program + PROG_visitStamp);
        if (vecCount < vecCapacity) {
          instVector = vecCount * 4;
          _memset(instVector + vecData,0,4);
          vecCount = countBefore + 1;
          elementPtr = (int *)(instVector + vecData);
        }
        else {
          elementPtr = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
        }
        *elementPtr = liveRoot;
        do {
          topIndex = vecCount - 1;
          topElementPtr = (int *)0x0;
          if (topIndex < vecCount) {
            topElementPtr = (int *)(topIndex * 4 + vecData);
          }
          instVector = *topElementPtr;
          Vector__removeAt(&vecCapacity,topIndex);
          if (0 < *(int *)(instVector + 0x84)) {
            loopIndex = 1;
            do {
              operandSource = IRInst__getOperandSource(instVector,loopIndex);
              countBefore = vecCount;
              if (operandSource != 0) {
                if (*(int *)(program + PROG_useEpoch) < *(int *)(operandSource + 0x160)) {
                  *(int *)(operandSource + 0x160) = *(int *)(operandSource + 0x160) + 1;
                }
                else {
                  *(int *)(operandSource + 0x160) = *(int *)(program + PROG_useEpoch) + 1;
                }
                if (*(int *)(program + PROG_visitStamp) != *(int *)(operandSource + 0x150)) {
                  *(int *)(operandSource + 0x150) = *(int *)(program + PROG_visitStamp);
                  if (vecCount < vecCapacity) {
                    slotByteOffset = vecCount * 4;
                    _memset(slotByteOffset + vecData,0,4);
                    vecCount = countBefore + 1;
                    elementPtr = (int *)(slotByteOffset + vecData);
                  }
                  else {
                    elementPtr = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
                  }
                  *elementPtr = operandSource;
                }
              }
              loopIndex = loopIndex + 1;
            } while (loopIndex <= *(int *)(instVector + 0x84));
          }
        } while (vecCount != 0);
      }
      instVector = *(int *)(program + PROG_instructionVector);
    }
    instByteOffset = instByteOffset + 4;
  }
  instVector = *(int *)(*(int *)(program + PROG_blockListHead) + 8);
  if (instVector == 0) {
    consistent = 1;
  }
  else {
    consistent = 1;
    statsSlot = epochIndex * 4 + program;
    block = *(int *)(program + PROG_blockListHead);
    do {
      nextBlock = instVector;
      lookaheadInst = (int *)(*(int **)(block + 0x98))[2];
      inst = *(int **)(block + 0x98);
      if (lookaheadInst != (int *)0x0) {
        do {
          curNext = lookaheadInst;
          if ((inst[5] & 1U) != 0) {
            instVector = (**(code **)(*inst + 0x34))(inst);
            if ((instVector == 0) && (instVector = (**(code **)(*inst + 0x38))(inst), instVector == 0)) {
              if ((!skipVerify) && (instVector = (**(code **)(*inst + 0x48))(inst), instVector == 0)) {
                instVector = inst[0x58] - *(int *)(program + PROG_useEpoch);
                if (instVector < 0) {
                  instVector = 0;
                }
                if (*(int *)(inst[0x53] * 4 + savedUseCounts) != instVector) {
                  consistent = 0;
                }
              }
              if (((*(int *)(program + PROG_visitStamp) != inst[0x54]) && ((inst[5] & 8U) == 0)) &&
                 ((inst[5] & 0x10U) == 0)) {
                (**(code **)(*inst + 0x10))(inst,*(undefined4 *)(program + PROG_compiler));
                if ((inst[0x26] != 2) && (inst[0x26] != 0x33)) {
                  *(int *)(statsSlot + 0x2b0) = *(int *)(statsSlot + 0x2b0) + 1;
                  curNext = (int *)inst[2];
                  goto LAB_0013c188;
                }
              }
            }
            curNext = (int *)inst[2];
          }
LAB_0013c188:
          lookaheadInst = (int *)curNext[2];
          inst = curNext;
        } while ((int *)curNext[2] != (int *)0x0);
        nextBlock = *(int *)(block + 8);
      }
      instVector = *(int *)(nextBlock + 8);
      block = nextBlock;
    } while (*(int *)(nextBlock + 8) != 0);
  }
  if (!skipVerify) {
    Arena__free(*(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB),savedUseCounts);
  }
  Arena__free(vecArena,vecData);
  return consistent;
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* FUN_0013c210 @ 0x13c210 (964 bytes) */
int FUN_0013c210(program)
  int program;
{
  undefined4 firstOperandIndex;
  int *stackTopSlotC;
  undefined4 *stackTopSlotB;
  undefined4 *stackTopSlot;
  undefined4 *orderPushSlot;
  int stackTopInst;
  int rootVec;
  int slotByteOffset;
  int sourceDef;
  bool descending;
  int isOptionEnabledResult;
  undefined4 *stackPushSlot;
  int *stackPushSlotB;
  int callResult;
  undefined4 popKey;
  uint stackTopIndex;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  int rootByteOffset;
  uint loopIndex;
  undefined4 keyAtTop;
  uint countBefore;
  int local_58;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_54_buf [0x10];
  #define vecCapacity (*(uint *)(local_54_buf + 0x00))
  #define vecCount (*(uint *)(local_54_buf + 0x04))
  #define vecData (*(int *)(local_54_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_54_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vec2Capacity/vec2Count/vec2Data/vec2Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_44_buf [0x10];
  #define vec2Capacity (*(uint *)(local_44_buf + 0x00))
  #define vec2Count (*(uint *)(local_44_buf + 0x04))
  #define vec2Data (*(int *)(local_44_buf + 0x08))
  #define vec2Arena (*(undefined4 *)(local_44_buf + 0x0c))
  
  isOptionEnabledResult = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x1c);
  if ((((isOptionEnabledResult == 0) && (isOptionEnabledResult = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x1d), isOptionEnabledResult == 0)) &&
      (isOptionEnabledResult = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x39), isOptionEnabledResult == 0)) &&
     (isOptionEnabledResult = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x1b), isOptionEnabledResult == 0)) {
    Compiler__logf(*(undefined4 *)(program + 8),
                 "Special : all peephole flags off -> bypass Rewrite()\n",in_r5,in_r6,in_r7,in_r8,
                 in_r9,in_r10);
  }
  *(int *)(program + 0x474) = *(int *)(program + 0x474) + 1;
  vecArena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  vec2Arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vec2Capacity = 2;
  vec2Count = 0;
  vec2Data = Arena__alloc(vec2Arena,8);
  rootVec = *(int *)(program + 0x3c4);
  loopIndex = 1;
  rootByteOffset = 0;
  do {
    countBefore = vecCount;
    if (*(uint *)(rootVec + 4) < loopIndex) {
      Arena__free(vec2Arena,vec2Data);
      Arena__free(vecArena,vecData);
      return;
    }
    local_58 = *(int *)(*(int *)(rootVec + 8) + rootByteOffset);
    if ((*(uint *)(local_58 + 0x14) & 1) != 0) {
      if (vecCount < vecCapacity) {
        slotByteOffset = vecCount * 4;
        _memset(slotByteOffset + vecData,0,4);
        vecCount = countBefore + 1;
        stackPushSlot = (undefined4 *)(slotByteOffset + vecData);
      }
      else {
        stackPushSlot = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
      }
      countBefore = vec2Count;
      *stackPushSlot = 0;
      if (vec2Count < vec2Capacity) {
        slotByteOffset = vec2Count * 4;
        _memset(slotByteOffset + vec2Data,0,4);
        vec2Count = countBefore + 1;
        orderPushSlot = (undefined4 *)(slotByteOffset + vec2Data);
      }
      else {
        orderPushSlot = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
      }
      *orderPushSlot = 0;
      descending = true;
      countBefore = vecCount;
      while (countBefore != 0) {
        if (descending) {
          if ((local_58 == 0) || (*(int *)(program + 0x474) == *(int *)(local_58 + 0x150))) {
            descending = false;
          }
          else {
            *(int *)(local_58 + 0x150) = *(int *)(program + 0x474);
            sourceDef = IRInst__getOperandSource(local_58,1);
            countBefore = vecCount;
            if (sourceDef == 0) {
              stackTopSlot = (undefined4 *)0x0;
              if (vecCount - 1 < vecCount) {
                stackTopSlot = (undefined4 *)((vecCount - 1) * 4 + vecData);
              }
              keyAtTop = *stackTopSlot;
LAB_0013c528:
              popKey = ((int (*)())FUN_0013922c)(&vec2Capacity);
              ((int (*)())FUN_00139c78)(local_58,keyAtTop,popKey,program);
              goto LAB_0013c540;
            }
            if (vecCount < vecCapacity) {
              slotByteOffset = vecCount * 4;
              _memset(slotByteOffset + vecData,0,4);
              vecCount = countBefore + 1;
              stackPushSlotB = (int *)(slotByteOffset + vecData);
            }
            else {
              stackPushSlotB = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *stackPushSlotB = local_58;
            firstOperandIndex = ((int (*)())FUN_0013a38c)(local_58,&vec2Capacity,program);
LAB_0013c54c:
            local_58 = IRInst__getOperandSource(local_58,firstOperandIndex);
            descending = true;
            countBefore = vecCount;
          }
        }
        else {
          stackTopIndex = countBefore - 1;
          stackTopSlotC = (int *)0x0;
          if (stackTopIndex < countBefore) {
            stackTopSlotC = (int *)(stackTopIndex * 4 + vecData);
          }
          stackTopInst = *stackTopSlotC;
          if (stackTopInst != 0) {
            if (local_58 != 0) {
              callResult = LaneStack__topFitsLaneCount(&vec2Capacity,*(undefined4 *)(stackTopInst + 0x84));
              countBefore = vecCount;
              if (callResult == 0) {
                firstOperandIndex = ((int (*)())FUN_0013a240)(&vec2Capacity);
                local_58 = stackTopInst;
                goto LAB_0013c54c;
              }
            }
            Vector__removeAt(&vecCapacity,countBefore - 1);
            Vector__removeAt(&vec2Capacity,vec2Count - 1);
            stackTopSlotB = (undefined4 *)0x0;
            if (vecCount - 1 < vecCount) {
              stackTopSlotB = (undefined4 *)((vecCount - 1) * 4 + vecData);
            }
            keyAtTop = *stackTopSlotB;
            local_58 = stackTopInst;
            goto LAB_0013c528;
          }
          Vector__removeAt(&vecCapacity,stackTopIndex);
          Vector__removeAt(&vec2Capacity,vec2Count - 1);
          local_58 = stackTopInst;
LAB_0013c540:
          descending = false;
          countBefore = vecCount;
        }
      }
      rootVec = *(int *)(program + 0x3c4);
    }
    loopIndex = loopIndex + 1;
    rootByteOffset = rootByteOffset + 4;
  } while( true );
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena
#undef vec2Capacity
#undef vec2Count
#undef vec2Data
#undef vec2Arena

/* Program__scanUsevectorChains @ 0x13c60c (1084 bytes) */
int Program__scanUsevectorChains(program)
  int program;
{
  uint countBefore;
  int slotByteOffsetB;
  int movAndShiftUsevectorEnabled;
  int slotByteOffset;
  bool descending;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int instByteOffset;
  uint loopIndex;
  int iVar11;
  int currentInst;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_54_buf [0x10];
  #define vecCapacity (*(uint *)(local_54_buf + 0x00))
  #define vecCount (*(uint *)(local_54_buf + 0x04))
  #define vecData (*(int *)(local_54_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_54_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vec2Capacity/vec2Count/vec2Data/vec2Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_44_buf [0x10];
  #define vec2Capacity (*(uint *)(local_44_buf + 0x00))
  #define vec2Count (*(uint *)(local_44_buf + 0x04))
  #define vec2Data (*(int *)(local_44_buf + 0x08))
  #define vec2Arena (*(undefined4 *)(local_44_buf + 0x0c))
  
  *(int *)(program + PROG_visitStamp) = *(int *)(program + PROG_visitStamp) + 1;
  vecArena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  vec2Arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
  vec2Capacity = 2;
  vec2Count = 0;
  vec2Data = Arena__alloc(vec2Arena,8);
  iVar8 = *(int *)(program + PROG_instructionVector);
  loopIndex = 1;
  instByteOffset = 0;
LAB_0013c9f4:
  countBefore = vecCount;
  if (*(uint *)(iVar8 + 4) < loopIndex) {
    Arena__free(vec2Arena,vec2Data);
    Arena__free(vecArena,vecData);
    return;
  }
  currentInst = *(int *)(instByteOffset + *(int *)(iVar8 + 8));
  if ((*(uint *)(currentInst + 0x14) & 1) != 0) {
    if (vecCount < vecCapacity) {
      slotByteOffsetB = vecCount * 4;
      _memset(slotByteOffsetB + vecData,0,4);
      vecCount = countBefore + 1;
      puVar4 = (undefined4 *)(slotByteOffsetB + vecData);
    }
    else {
      puVar4 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
    }
    countBefore = vec2Count;
    *puVar4 = 0;
    if (vec2Count < vec2Capacity) {
      slotByteOffsetB = vec2Count * 4;
      _memset(slotByteOffsetB + vec2Data,0,4);
      vec2Count = countBefore + 1;
      puVar4 = (undefined4 *)(slotByteOffsetB + vec2Data);
    }
    else {
      puVar4 = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
    }
    *puVar4 = 0;
    descending = true;
    countBefore = vecCount;
LAB_0013c9e0:
    do {
      if (countBefore == 0) goto code_r0x0013c9e8;
      if (descending) {
        if (currentInst != 0) {
          movAndShiftUsevectorEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x14);
          if (movAndShiftUsevectorEnabled != 0) {
            currentInst = FUN_00147f54(currentInst,*(undefined4 *)(program + PROG_compiler));
          }
          countBefore = vecCount;
          if (*(int *)(program + PROG_visitStamp) != *(int *)(currentInst + 0x150)) {
            *(int *)(currentInst + 0x150) = *(int *)(program + PROG_visitStamp);
            iVar8 = IRInst__getOperandSource(currentInst,1);
            countBefore = vecCount;
            if (iVar8 == 0) goto LAB_0013c8f0;
            if (vecCount < vecCapacity) {
              slotByteOffsetB = vecCount * 4;
              _memset(slotByteOffsetB + vecData,0,4);
              vecCount = countBefore + 1;
              piVar5 = (int *)(slotByteOffsetB + vecData);
            }
            else {
              piVar5 = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            countBefore = vec2Count;
            *piVar5 = currentInst;
            if (vec2Count < vec2Capacity) {
              slotByteOffsetB = vec2Count * 4;
              _memset(slotByteOffsetB + vec2Data,0,4);
              vec2Count = countBefore + 1;
              puVar4 = (undefined4 *)(slotByteOffsetB + vec2Data);
            }
            else {
              puVar4 = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
            }
            *puVar4 = 1;
            currentInst = IRInst__getOperandSource(currentInst,1);
LAB_0013c9c8:
            descending = true;
            countBefore = vecCount;
            goto LAB_0013c9e0;
          }
        }
        descending = false;
        goto LAB_0013c9e0;
      }
      uVar7 = countBefore - 1;
      piVar5 = (int *)0x0;
      if (uVar7 < countBefore) {
        piVar5 = (int *)(uVar7 * 4 + vecData);
      }
      iVar8 = *piVar5;
      if (iVar8 == 0) {
        Vector__removeAt(&vecCapacity,uVar7);
        Vector__removeAt(&vec2Capacity,vec2Count - 1);
        currentInst = iVar8;
      }
      else {
        if (currentInst != 0) {
          piVar5 = (int *)0x0;
          uVar6 = vec2Count - 1;
          if (uVar6 < vec2Count) {
            piVar5 = (int *)(uVar6 * 4 + vec2Data);
          }
          if (*piVar5 != *(int *)(iVar8 + 0x84)) {
            piVar5 = (int *)0x0;
            if (uVar6 < vec2Count) {
              piVar5 = (int *)(uVar6 * 4 + vec2Data);
            }
            iVar11 = *piVar5;
            Vector__removeAt(&vec2Capacity,uVar6);
            countBefore = vec2Count;
            if (vec2Count < vec2Capacity) {
              slotByteOffset = vec2Count * 4;
              _memset(slotByteOffset + vec2Data,0,4);
              vec2Count = countBefore + 1;
              piVar5 = (int *)(slotByteOffset + vec2Data);
            }
            else {
              piVar5 = (int *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
            }
            *piVar5 = iVar11 + 1;
            currentInst = IRInst__getOperandSource(iVar8,iVar11 + 1);
            goto LAB_0013c9c8;
          }
        }
        Vector__removeAt(&vecCapacity,uVar7);
        Vector__removeAt(&vec2Capacity,vec2Count - 1);
        currentInst = iVar8;
LAB_0013c8f0:
        puVar4 = (undefined4 *)0x0;
        if (vecCount - 1 < vecCount) {
          puVar4 = (undefined4 *)((vecCount - 1) * 4 + vecData);
        }
        puVar3 = (undefined4 *)0x0;
        if (vec2Count - 1 < vec2Count) {
          puVar3 = (undefined4 *)((vec2Count - 1) * 4 + vec2Data);
        }
        Program__finishUsevectorChain(currentInst,*puVar4,*puVar3,program);
      }
      descending = false;
      countBefore = vecCount;
    } while( true );
  }
  goto LAB_0013c9ec;
code_r0x0013c9e8:
  iVar8 = *(int *)(program + PROG_instructionVector);
LAB_0013c9ec:
  loopIndex = loopIndex + 1;
  instByteOffset = instByteOffset + 4;
  goto LAB_0013c9f4;
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena
#undef vec2Capacity
#undef vec2Count
#undef vec2Data
#undef vec2Arena

/* FUN_0013ca84 @ 0x13ca84 (112 bytes) */
int FUN_0013ca84(inst)
  int *inst;
{
  undefined4 sourceDef;
  undefined4 uVar1;
  int vcall7cResult;
  
  if (*(int *)(inst[0x22] + 8) == 0x8e) {
    vcall7cResult = (**(code **)(*inst + 0x7c))(inst);
    uVar1 = *(undefined4 *)(vcall7cResult + 300);
  }
  else {
    uVar1 = 0;
    if ((inst[5] & 0x200U) != 0) {
      sourceDef = IRInst__getOperandSource(inst,inst[0x21]);
      return sourceDef;
    }
  }
  return uVar1;
}

/* IfHeader__convertInnerIfToCmov @ 0x13caf4 (1644 bytes) */
int IfHeader__convertInnerIfToCmov(block, program, compiler)
  int *block;
  undefined4 program;
  uint compiler;
{
  bool swapCompareOperands;
  int phiCount;
  int *joinInstB;
  int *nextJoinInst;
  int joinBlock;
  int operandKindClassResult;
  int countdown;
  undefined8 predecessor;
  int listCount;
  undefined8 isStatic;
  int *operandVReg;
  int elseMovableCount;
  int *nextInst;
  int *scanInst;
  int iVar3;
  int isNotAmong3Result;
  int iVar4;
  int iVar5;
  int isNotAmong3Result2;
  undefined4 predecessorBlock;
  undefined4 operandVReg2;
  undefined4 operandVReg3;
  uint uVar9;
  int in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int *in_r9;
  undefined4 compareSelectWord;
  int iVar11;
  int operandRecord;
  int elseBlock;
  uint thenBlock;
  int *joinInst;
  int thenMovableCount;
  bool thenSourcesMovable;
  undefined8 uVar18;
  
  uVar9 = compiler;
  iVar3 = FUN_000e9294(block);
  if (iVar3 != 0) {
    isStatic = (**(code **)(*block + 0x40))(block);
    if ((int)((ulonglong)isStatic >> 0x20) == 0) {
      uVar18 = Block__getBranchInst(block,(int)isStatic,uVar9,in_r6,in_r7,in_r8,in_r9);
      if ((*(int *)(*(int *)((int)((ulonglong)uVar18 >> 0x20) + 0x88) + 8) == 0x8b) ||
         (iVar3 = Block__getBranchInst(block,(int)uVar18,uVar9,in_r6,in_r7,in_r8,in_r9),
         *(int *)(*(int *)(iVar3 + 0x88) + 8) == 0x8c)) {
        joinBlock = block[0x4f];
        thenBlock = block[0x4d];
        elseBlock = block[0x4e];
        joinInst = *(int **)(joinBlock + 0x98);
        nextInst = (int *)joinInst[2];
        if (nextInst == (int *)0x0) {
          phiCount = 0;
          elseMovableCount = 0;
          thenMovableCount = 2;
        }
        else {
          phiCount = 0;
          thenMovableCount = 0;
          elseMovableCount = 0;
          do {
            scanInst = nextInst;
            in_r9 = (int *)(joinInst[5] & 1);
            if (in_r9 != (int *)0x0) {
              iVar5 = (**(code **)(*joinInst + 0x34))(joinInst);
              if (((iVar5 == 0) && (iVar5 = (**(code **)(*joinInst + 0x38))(joinInst), iVar5 == 0)) &&
                 (*(int *)(joinInst[0x22] + 8) == 0x8e)) {
                operandVReg = (int *)IRInst__getOperandSource(joinInst,1);
                phiCount = phiCount + 1;
                if ((thenBlock == operandVReg[0x56]) &&
                   (iVar5 = (**(code **)(*operandVReg + 100))(operandVReg), iVar5 != 0)) {
                  for (iVar5 = 1; iVar4 = (**(code **)(*operandVReg + 0x14))(operandVReg), iVar5 <= iVar4;
                      iVar5 = iVar5 + 1) {
                    if ((((operandVReg[iVar5 * 6 + 0x28] & 1U) != 0) ||
                        (in_r9 = (int *)(operandVReg[iVar5 * 6 + 0x28] & 2), in_r9 != (int *)0x0)) ||
                       (iVar4 = IRInst__isSourceSelectIdentity(operandVReg,iVar5), iVar4 == 0)) goto LAB_0013cd68;
                  }
                  if ((operandVReg[0x48] != 0) || (operandVReg[0x49] != 0)) goto LAB_0013cd68;
                  if ((operandVReg[0x20] != 0) &&
                     (((iVar5 = RegKind__flagBit0(operandVReg[0x26]), iVar5 != 0 && ((operandVReg[5] & 2U) == 0))
                      && (iVar5 = (**(code **)(*operandVReg + 0x50))(operandVReg), iVar5 == 0)))) {
                    countdown = 4;
                    in_r9 = operandVReg;
                    do {
                      if ((uint)(*(byte *)(in_r9 + 0x27) - 2) < 2) goto LAB_0013cd68;
                      in_r9 = (int *)((int)in_r9 + 1);
                      countdown = countdown + -1;
                    } while (countdown != 0);
                  }
                  IRInst__getOperandRecord(operandVReg,0);
                  iVar5 = IRInst__operandKindClass(operandVReg,0);
                  if (((iVar5 != 0) || ((operandVReg[5] & 2U) != 0)) ||
                     ((in_r9 = (int *)(operandVReg[5] & 0x200), in_r9 != (int *)0x0 ||
                      (*(int *)(operandVReg[4] + 4) != 1)))) goto LAB_0013cd68;
                  thenMovableCount = thenMovableCount + 1;
                  thenSourcesMovable = true;
                }
                else {
LAB_0013cd68:
                  uVar9 = thenBlock;
                  in_r6 = elseBlock;
                  iVar5 = Node__isNotAmong3(operandVReg,block,thenBlock,elseBlock);
                  thenSourcesMovable = iVar5 != 0;
                }
                operandVReg = (int *)IRInst__getOperandSource(joinInst,2);
                if ((elseBlock == operandVReg[0x56]) &&
                   (iVar5 = (**(code **)(*operandVReg + 100))(operandVReg), iVar5 != 0)) {
                  for (iVar5 = 1; iVar4 = (**(code **)(*operandVReg + 0x14))(operandVReg), iVar5 <= iVar4;
                      iVar5 = iVar5 + 1) {
                    if ((((operandVReg[iVar5 * 6 + 0x28] & 1U) != 0) ||
                        (in_r9 = (int *)(operandVReg[iVar5 * 6 + 0x28] & 2), in_r9 != (int *)0x0)) ||
                       (iVar4 = IRInst__isSourceSelectIdentity(operandVReg,iVar5), iVar4 == 0)) goto LAB_0013cee8;
                  }
                  if ((operandVReg[0x48] != 0) || (operandVReg[0x49] != 0)) goto LAB_0013cee8;
                  if (((operandVReg[0x20] != 0) &&
                      ((iVar5 = RegKind__flagBit0(operandVReg[0x26]), iVar5 != 0 && ((operandVReg[5] & 2U) == 0))))
                     && (iVar5 = (**(code **)(*operandVReg + 0x50))(operandVReg), iVar5 == 0)) {
                    countdown = 4;
                    in_r9 = operandVReg;
                    do {
                      if ((uint)(*(byte *)(in_r9 + 0x27) - 2) < 2) goto LAB_0013cee8;
                      in_r9 = (int *)((int)in_r9 + 1);
                      countdown = countdown + -1;
                    } while (countdown != 0);
                  }
                  IRInst__getOperandRecord(operandVReg,0);
                  operandKindClassResult = IRInst__operandKindClass(operandVReg,0);
                  if ((((operandKindClassResult != 0) || ((operandVReg[5] & 2U) != 0)) ||
                      (in_r9 = (int *)(operandVReg[5] & 0x200), in_r9 != (int *)0x0)) ||
                     (*(int *)(operandVReg[4] + 4) != 1)) goto LAB_0013cee8;
                  elseMovableCount = elseMovableCount + 1;
                }
                else {
LAB_0013cee8:
                  uVar9 = thenBlock;
                  in_r6 = elseBlock;
                  isNotAmong3Result2 = Node__isNotAmong3(operandVReg,block,thenBlock,elseBlock);
                  if (isNotAmong3Result2 == 0) {
                    return;
                  }
                }
                if (!thenSourcesMovable) {
                  return;
                }
              }
              scanInst = (int *)joinInst[2];
            }
            nextInst = (int *)scanInst[2];
            joinInst = scanInst;
          } while ((int *)scanInst[2] != (int *)0x0);
          thenMovableCount = thenMovableCount + 2;
        }
        listCount = DList__count(thenBlock + 0x90);
        if (((thenMovableCount == listCount) && (thenMovableCount = DList__count(elseBlock + 0x90), thenMovableCount == elseMovableCount + 2)) &&
           (phiCount != 0)) {
          predecessor = Block__getPredecessor(block,0);
          predecessorBlock = (undefined4)((ulonglong)predecessor >> 0x20);
          iVar11 = Block__getBranchInst(block,(int)predecessor,uVar9,in_r6,in_r7,in_r8,in_r9);
          compareSelectWord = 0;
          if (*(int *)(*(int *)(iVar11 + 0x88) + 8) == 0x8c) {
            operandRecord = IRInst__getOperandRecord(iVar11,1);
            compareSelectWord = *(undefined4 *)(operandRecord + 0x10);
            Program__removeInst(program,iVar11);
            swapCompareOperands = *(int *)(iVar11 + 300) != 7;
            iVar11 = IRInst__getOperandSource(iVar11,1);
          }
          else {
            swapCompareOperands = false;
            IRInst__convertCompareToBinaryAlu(iVar11,compiler);
            Block__appendInst(predecessorBlock,iVar11);
          }
          joinInstB = *(int **)(joinBlock + 0x98);
          for (nextJoinInst = (int *)joinInstB[2]; nextJoinInst != (int *)0x0; nextJoinInst = (int *)nextJoinInst[2]) {
            iVar3 = (**(code **)(*joinInstB + 0x34))(joinInstB);
            if ((iVar3 == 0) && (iVar3 = (**(code **)(*joinInstB + 0x38))(joinInstB), iVar3 == 0)) {
              if (*(int *)(joinInstB[0x22] + 8) == 0x8e) {
                operandVReg2 = IRInst__getOperandSource(joinInstB,1);
                operandVReg3 = IRInst__getOperandSource(joinInstB,2);
                isNotAmong3Result = Node__isNotAmong3(operandVReg2,block,thenBlock,elseBlock);
                if (isNotAmong3Result == 0) {
                  DList__unlink(operandVReg2);
                  Block__appendInst(predecessorBlock,operandVReg2);
                }
                isNotAmong3Result = Node__isNotAmong3(operandVReg3,block,thenBlock,elseBlock);
                if (isNotAmong3Result == 0) {
                  DList__unlink(operandVReg3);
                  Block__appendInst(predecessorBlock,operandVReg3);
                }
                IRInst__foldConstantFactor(joinInstB,iVar11,compareSelectWord,compiler);
                if ((*(int *)(joinInstB[0x22] + 8) != 0x31) && (swapCompareOperands)) {
                  IRInst__swapOperands(joinInstB,2,3,compiler);
                }
                Block__appendInst(predecessorBlock,joinInstB);
              }
              else {
                DList__unlink(joinInstB);
                Block__appendInst(predecessorBlock,joinInstB);
              }
            }
            joinInstB = nextJoinInst;
          }
        }
      }
    }
  }
  return;
}

/* pass_rewrite @ 0x13d160 (376 bytes) */
int pass_rewrite(program)
  int program;
{
  int vcall24Result;
  int *piVar1;
  int iVar2;
  int isOptionEnabledResult;
  int *piVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  isOptionEnabledResult = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x13);
  if (isOptionEnabledResult != 0) {
    isOptionEnabledResult = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x17);
    if (isOptionEnabledResult != 0) {
      Program__foldUselessPhis(program);
    }
    ((int (*)())Program__scanUsevectorChains)(program);
    local_1c = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
    local_24 = 0;
    local_28 = 2;
    local_20 = Arena__alloc(local_1c,8);
    piVar3 = *(int **)(program + PROG_blockListHead);
    iVar2 = piVar3[2];
    while (iVar2 != 0) {
      vcall24Result = (**(code **)(*piVar3 + 0x24))(piVar3);
      if (vcall24Result != 0) {
        iVar2 = *(int *)(program + PROG_visitStamp) + 1;
        *(int *)(program + PROG_visitStamp) = iVar2;
        ((int (*)())Block__scanBranchConeForFetchAndInterp)(piVar3,&local_28,iVar2);
      }
      piVar3 = (int *)piVar3[2];
      iVar2 = piVar3[2];
    }
    iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x18);
    if (((iVar2 != 0) && (iVar2 = FUN_000e0830(*(undefined4 *)(program + PROG_compiler),0,3), iVar2 == 0)) &&
       ((*(uint *)(*(int *)(*(int *)(program + PROG_compiler) + COMP_target) + 8) & 0x20000) == 0)) {
      ((int (*)())Program__moveInterpFetchesOutOfIfs)(program);
      ((int (*)())Program__hoistFetchInsts)(program);
    }
    Arena__free(local_1c,local_20);
  }
  piVar3 = *(int **)(*(int *)(program + PROG_compiler) + COMP_target);
  (**(code **)(*piVar3 + 0x110))(piVar3,program);
  *(uint *)(program + PROG_flags) = *(uint *)(program + PROG_flags) & 0xffffff7f;
  isOptionEnabledResult = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x19);
  if (isOptionEnabledResult != 0) {
    piVar3 = *(int **)(program + PROG_blockListHead);
    for (piVar1 = (int *)(*(int **)(program + PROG_blockListHead))[2]; piVar1 != (int *)0x0;
        piVar1 = (int *)piVar1[2]) {
      vcall24Result = (**(code **)(*piVar3 + 0x24))(piVar3);
      if (vcall24Result != 0) {
        ((int (*)())IfHeader__convertInnerIfToCmov)(piVar3,program,*(undefined4 *)(program + PROG_compiler));
      }
      piVar3 = piVar1;
    }
  }
  isOptionEnabledResult = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x37);
  if (isOptionEnabledResult != 0) {
    Program__packPsInputs(program);
  }
  ((int (*)())FUN_0013c210)(program);
  ((int (*)())Program__eliminateDeadInstsAndRecountUses)(program,0);
  Program__beginPass(program,(int)"rewrite");
  isOptionEnabledResult = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x1f);
  if (isOptionEnabledResult != 0) {
    pass_loop_trans(program);
  }
  return;
}

/* FUN_0013d3b8 @ 0x13d3b8 (1128 bytes) */
int FUN_0013d3b8(program)
  int program;
{
  int writtenCount;
  int operandIndex;
  int selectIsFullMask;
  int splitRgbAlphaEnabled;
  int predicateResult;
  int loopIndex;
  int operandClone;
  int vcall5cResult;
  int operandLimit;
  int cloneDestRecord;
  int cloneResult3;
  undefined4 cloneVregIdB;
  int *componentSelectTable;
  int *vcall7cResult;
  int cloneResult;
  int splitIntoScalarEnabled;
  undefined4 sourceDef;
  int operandRecord;
  int operandRecord2;
  int *operandVReg;
  bool moreComponents;
  int block;
  int *lookaheadInst;
  int *nextInst;
  int nextBlock;
  int cloneResult2;
  undefined4 cloneVregId;
  uint operandSelect;
  int *inst;
  
  block = *(int *)(program + 900);
  for (nextBlock = *(int *)(*(int *)(program + 900) + 8); nextBlock != 0; nextBlock = *(int *)(nextBlock + 8)) {
    lookaheadInst = (int *)(*(int **)(block + 0x98))[2];
    inst = *(int **)(block + 0x98);
    if (lookaheadInst != (int *)0x0) {
      do {
        nextInst = lookaheadInst;
        if ((inst[5] & 1U) != 0) {
          vcall7cResult = (int *)(**(code **)(*inst + 0x7c))(inst);
          if ((((vcall7cResult != (int *)0x0) && (vcall7cResult[0x20] != 0)) &&
              (predicateResult = RegKind__flagBit0(vcall7cResult[0x26]), predicateResult != 0)) &&
             ((((vcall7cResult[5] & 2U) == 0 && (predicateResult = (**(code **)(*vcall7cResult + 0x50))(vcall7cResult), predicateResult == 0)
               ) && ((vcall7cResult[5] & 0x40U) == 0)))) {
            cloneResult = IRInst__clone(vcall7cResult,*(undefined4 *)(program + 8),0);
            *(undefined4 *)(cloneResult + 0x94) = *(undefined4 *)(cloneResult + 0x14c);
            *(undefined4 *)(cloneResult + 0x9c) = 0x10101;
            Block__insertInstBefore(block,vcall7cResult,cloneResult);
            cloneResult3 = IRInst__clone(vcall7cResult,*(undefined4 *)(program + 8),0);
            *(undefined4 *)(cloneResult3 + 0x94) = *(undefined4 *)(cloneResult3 + 0x14c);
            *(undefined4 *)(cloneResult3 + 0x9c) = 0x1000101;
            Block__insertInstBefore(block,vcall7cResult,cloneResult3);
            cloneResult2 = IRInst__clone(vcall7cResult,*(undefined4 *)(program + 8),0);
            *(undefined4 *)(cloneResult2 + 0x9c) = 0x1010001;
            *(undefined4 *)(cloneResult2 + 0x94) = *(undefined4 *)(cloneResult2 + 0x14c);
            Block__insertInstBefore(block,vcall7cResult,cloneResult2);
            vcall7cResult[0x27] = 0x1010100;
            *(undefined4 *)(cloneResult + 300) = 0;
            *(int *)(cloneResult3 + 300) = cloneResult;
            *(int *)(cloneResult2 + 300) = cloneResult3;
            vcall7cResult[0x4b] = cloneResult2;
          }
          predicateResult = (**(code **)(*inst + 0x24))(inst);
          if (((predicateResult != 0) && (inst[0x20] != 0)) &&
             ((predicateResult = RegKind__flagBit0(inst[0x26]), predicateResult != 0 &&
              ((((inst[5] & 2U) == 0 &&
                (predicateResult = (**(code **)(*inst + 0x50))(inst), predicateResult == 0)) &&
               (predicateResult = OpcodeTraits__getField34(*(undefined4 *)(inst[0x22] + 8),*(undefined4 *)(program + 8)
                                    ), predicateResult == 0)))))) {
            splitIntoScalarEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x32);
            if (splitIntoScalarEnabled == 0) {
              splitRgbAlphaEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x30);
              if (splitRgbAlphaEnabled != 0) {
                operandRecord2 = IRInst__getOperandRecord(inst,0);
                operandSelect = *(uint *)(operandRecord2 + 0x10);
                selectIsFullMask = FUN_000f2e18(operandSelect);
                if (selectIsFullMask == 0) {
                  cloneResult = IRInst__clone(inst,*(undefined4 *)(program + 8),0);
                  *(uint *)(cloneResult + 0x9c) = operandSelect & 0xffffff00 | 1;
                  cloneVregId = *(undefined4 *)(cloneResult + 0x14c);
                  cloneDestRecord = IRInst__getOperandRecord(cloneResult,0);
                  *(undefined4 *)(cloneDestRecord + 8) = cloneVregId;
                  inst[0x27] = 0x1010100;
                  IRInst__setExtraOperandSource(inst,cloneResult,0,*(undefined4 *)(program + 8));
                  Block__insertInstBefore(block,inst,cloneResult);
                  for (operandIndex = 1; operandLimit = (**(code **)(*inst + 0x14))(inst), operandIndex <= operandLimit;
                      operandIndex = operandIndex + 1) {
                    operandVReg = (int *)IRInst__getOperandSource(inst,operandIndex);
                    vcall5cResult = (**(code **)(*operandVReg + 0x5c))(operandVReg);
                    if (vcall5cResult != 0) {
                      operandClone = IRInst__clone(operandVReg,*(undefined4 *)(program + 8),0);
                      cloneVregIdB = *(undefined4 *)(operandClone + 0x14c);
                      operandRecord = IRInst__getOperandRecord(operandClone,0);
                      *(undefined4 *)(operandRecord + 8) = cloneVregIdB;
                      Block__insertInstAfter(operandVReg[0x56],operandVReg,operandClone);
                      IRInst__setOperandSource(inst,operandIndex,operandClone,0,*(undefined4 *)(program + 8));
                    }
                  }
                }
              }
            }
            else {
              writtenCount = IRInst__countWrittenComponents(inst);
              if (1 < writtenCount) {
                loopIndex = 0;
                componentSelectTable = (int *)PTR_DAT_001e8b64;
                do {
                  operandRecord = IRInst__getOperandRecord(inst,0);
                  if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
                    if (writtenCount < 2) {
                      inst[0x27] = *componentSelectTable;
                      IRInst__clearSourceSelectsOfUnwrittenComponents(inst);
                    }
                    else {
                      cloneResult2 = IRInst__clone(inst,*(undefined4 *)(program + 8),0);
                      *(int *)(cloneResult2 + 0x9c) = *componentSelectTable;
                      Block__insertInstBefore(block,inst,cloneResult2);
                      if ((inst[5] & 0x200U) != 0) {
                        sourceDef = IRInst__getOperandSource(inst,inst[0x21]);
                        IRInst__setExtraOperandSource(cloneResult2,sourceDef,0,*(undefined4 *)(program + 8));
                      }
                      IRInst__setExtraOperandSource(inst,cloneResult2,0,*(undefined4 *)(program + 8));
                    }
                    writtenCount = writtenCount + -1;
                  }
                  moreComponents = loopIndex != 3;
                  componentSelectTable = componentSelectTable + 1;
                  loopIndex = loopIndex + 1;
                } while (moreComponents);
              }
            }
          }
          nextInst = (int *)inst[2];
        }
        lookaheadInst = (int *)nextInst[2];
        inst = nextInst;
      } while ((int *)nextInst[2] != (int *)0x0);
      nextBlock = *(int *)(block + 8);
    }
    block = nextBlock;
  }
  return;
}

/* FUN_0013d820 @ 0x13d820 (540 bytes) */
int FUN_0013d820(inst, param_2)
  int *inst;
  int param_2;
{
  int vcall64Result;
  int operandRecord;
  bool moreComponents;
  char cVar2;
  uint uVar3;
  int iVar4;
  int *callResult;
  int *operandVReg;
  undefined4 uVar7;
  int loopIndex;
  undefined4 operandSelectB;
  undefined4 operandSelect;
  int local_40 [7];
  
  uVar7 = *(undefined4 *)(param_2 + 8);
  vcall64Result = (**(code **)(*inst + 100))(inst,param_2);
  if ((vcall64Result != 0) && ((inst[5] & 0x200U) != 0)) {
    callResult = (int *)IRInst__getOperandSource(inst,1);
    operandVReg = (int *)IRInst__getOperandSource(inst,inst[0x21]);
    iVar4 = (**(code **)(*callResult + 0x48))(callResult);
    if ((iVar4 != 0) && (iVar4 = (**(code **)(*operandVReg + 0x2c))(operandVReg), iVar4 != 0)) {
      operandRecord = IRInst__getOperandRecord(operandVReg,0);
      operandSelectB = *(undefined4 *)(operandRecord + 0x10);
      loopIndex = 0;
      operandRecord = IRInst__getOperandRecord(inst,0);
      operandSelect = *(undefined4 *)(operandRecord + 0x10);
      local_40[0] = operandVReg[0x50];
      do {
        cVar2 = *(char *)((int)local_40 + loopIndex + -4);
        if (cVar2 == '\0') {
          if (*(char *)((int)&operandSelectB + loopIndex) != '\0') {
            return;
          }
          operandRecord = IRInst__getOperandRecord(inst,1);
          uVar3 = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
          if (((int)*(char *)(callResult + 0x57) >> (uVar3 & 0x3f) & 1U) == 0) {
            return;
          }
          if (callResult[uVar3 * 6 + 7] != 2) {
            return;
          }
          if ((GH_U2F((unsigned int)(callResult[uVar3 * 6 + 8])) != 0.0) || (*(char *)((int)local_40 + loopIndex) != '\x05'))
          {
            if (GH_U2F((unsigned int)(callResult[uVar3 * 6 + 8])) != 1.0) {
              return;
            }
            if (*(char *)((int)local_40 + loopIndex) != '\x03') {
              return;
            }
          }
        }
        else if (cVar2 != '\x01') {
          return;
        }
        moreComponents = loopIndex != 3;
        loopIndex = loopIndex + 1;
      } while (moreComponents);
      IRInst__setOperandSource(inst,1,operandVReg,0,uVar7);
      inst[0x27] = 0;
      operandRecord = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord + 0x10) = 0x10203;
      IRInst__setOperandSource(inst,inst[0x21],0,0,*(undefined4 *)(param_2 + 8));
      inst[0x21] = inst[0x21] + -1;
      inst[5] = inst[5] & 0xfffffdff;
    }
  }
  return;
}

/* FUN_0013da3c @ 0x13da3c (760 bytes) */
int FUN_0013da3c(program)
  int program;
{
  bool replacesWriteMask;
  bool moreComponents;
  bool byte1IsZero;
  bool byte2IsZero;
  bool lowByteIsZero;
  int poppedInstB;
  int operandIndexB;
  int cloneOperandCount;
  int identitySelectD;
  int savedUsers;
  int matchedDef;
  int destOperandRecordC;
  int candidateDef;
  int predicateResultD;
  int destSelectWord;
  int nextBlockB;
  int vcall48Result;
  int blockCursor;
  int isProjectionOf2a;
  int rootCursor;
  int identitySelectC;
  int operandLimitB;
  int fixedSelectWord;
  int cloneSource;
  int lastOperandRecordB;
  int defRoot;
  int lastOperandIndexB;
  int destOperandRecordB;
  int predicateResultC;
  int nextBlock;
  int byteOffsetD;
  int resolvedRoot;
  int destOperandRecord;
  int byteOffsetC;
  int chainInst;
  int selectRecord;
  int lastOperandRecord;
  int lastOperandIndex;
  int candidateRoot;
  int operandIndex;
  int mergeTarget;
  int maskedSelectWord;
  int predicateResultB;
  int hasSpecialSource;
  int identitySelectB;
  int componentIndex;
  int predicateResult;
  int byteOffsetB;
  int sourceIndex;
  int identitySelect;
  int successorBlock;
  int unionFindParents;
  int vcall30Result;
  int operandCount;
  int pushedInst;
  int block;
  int idArrayBytes;
  int byteOffset;
  int *growSlotPtr;
  int *workInst;
  int *operandSourceInst;
  int *sourceInst;
  int *lookaheadInst;
  int *topElementPtr;
  int *userElementPtr;
  int *producerInst;
  int *defInst;
  undefined4 firstOperandSource;
  undefined4 lastOperandSource;
  undefined4 selectWordConst;
  undefined4 *selectConstPtr;
  undefined4 *pushSlot;
  uint oldWriteMask;
  uint userIndex;
  uint operandReadMask;
  uint uncoveredMask;
  uint defWriteMask;
  uint mergedMask;
  uint userCount;
  uint operandSelectWord;
  uint savedScratchWord;
  uint vecCountBefore;
  uint topIndex;
  uint instOrdinal;
  undefined4 *allocation;
  undefined4 vectorData;
  undefined4 arena;
  int flagBit8Result;
  int cloneResult;
  int instFlagBit2Result;
  int isProjectionOfClass26or3a;
  int softilGenAttribShdrEnabled;
  int operandRecord4;
  int operandRecord3;
  int operandRecord2;
  int sourceDef;
  int operandRecord;
  int operandRecord5;
  int *operandVReg;
  bool highByteIsZero;
  uint maskedWriteMask;
  uint option4eEnabled;
  int *elementPtr;
  int matchingDefMap;
  undefined4 *topSlot;
  int disjointSetFindRootResult;
  int hasDefaultSelects;
  int operandLimit;
  int prevRoot;
  int instVector;
  int *nextInst;
  int prevMergeTarget;
  int instByteOffset;
  int candidateInst;
  undefined4 poppedInst;
  int *inst;
  uint *userList;
  uint queuedCount;
  int scanInst;
  uint *userListRef;
  int operandSelectBytes;
  uint coveredMask;
  undefined4 selectReadMaskBytes;
  undefined4 maskedWriteMaskBytes;
  int currentInst;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/uVar19) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_b4_buf [0x10];
  #define vecCapacity (*(uint *)(local_b4_buf + 0x00))
  #define vecCount (*(uint *)(local_b4_buf + 0x04))
  #define vecData (*(int *)(local_b4_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_b4_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/uVar19) used with Vector__elementRefGrow - vec2Capacity/vec2Count/vec2Data/vec2Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_a4_buf [0x10];
  #define vec2Capacity (*(undefined4 *)(local_a4_buf + 0x00))
  #define vec2Count (*(uint *)(local_a4_buf + 0x04))
  #define vec2Data (*(int *)(local_a4_buf + 0x08))
  #define vec2Arena (*(undefined4 *)(local_a4_buf + 0x0c))
  undefined4 destWriteMask;
  uint operandReadMaskOutA;
  uint chainedWriteMask;
  undefined4 mergedSelectWord;
  uint operandWriteMask;
  int destSelectWordB;
  uint operandSelectOutA;
  uint operandSelectOutB;
  int projSelectWord;
  uint operandReadMaskOutB;
  int maskedSelectOut;
  undefined4 selectReadMask;
  int blockListObject;
  undefined *globalsBase;
  
  option4eEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x4e);
  if (option4eEnabled == 0) {
    softilGenAttribShdrEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x4f);
    if (softilGenAttribShdrEnabled == 0) goto LAB_0013dcf0;
    vec2Arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
    instByteOffset = 0;
    vec2Capacity = 2;
    vec2Count = option4eEnabled;
    vec2Data = Arena__alloc(vec2Arena,8);
    instVector = *(int *)(program + PROG_instructionVector);
    currentInst = 0;
    for (instOrdinal = 1; queuedCount = vec2Count, instOrdinal <= *(uint *)(instVector + 4); instOrdinal = instOrdinal + 1) {
      candidateInst = *(int *)(instByteOffset + *(int *)(instVector + 8));
      currentInst = candidateInst;
      if (((*(uint *)(candidateInst + 0x14) & 1) != 0) && (*(int *)(candidateInst + 0x98) == 6)) {
        if (vec2Count < vec2Capacity) {
          byteOffset = vec2Count * 4;
          _memset(byteOffset + vec2Data,0,4);
          vec2Count = queuedCount + 1;
          elementPtr = (int *)(byteOffset + vec2Data);
        }
        else {
          elementPtr = (int *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
        }
        *elementPtr = candidateInst;
        *(uint *)(currentInst + 0x14) = *(uint *)(currentInst + 0x14) & 0xfffffff7;
        *(uint *)(currentInst + 0x14) = *(uint *)(currentInst + 0x14) & 0xffffffef;
        instVector = *(int *)(program + PROG_instructionVector);
      }
      instByteOffset = instByteOffset + 4;
    }
    while (vec2Count != 0) {
      topIndex = vec2Count - 1;
      topSlot = (undefined4 *)0x0;
      if (topIndex < vec2Count) {
        topSlot = (undefined4 *)(topIndex * 4 + vec2Data);
      }
      poppedInst = *topSlot;
      Vector__removeAt(&vec2Capacity,topIndex);
      Program__removeInst(program,poppedInst);
    }
  }
  else {
    vec2Arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
    vec2Capacity = 2;
    instByteOffset = 0;
    vec2Count = 0;
    vec2Data = Arena__alloc(vec2Arena,8);
    instVector = *(int *)(program + PROG_instructionVector);
    currentInst = 0;
    for (instOrdinal = 1; queuedCount = vec2Count, instOrdinal <= *(uint *)(instVector + 4); instOrdinal = instOrdinal + 1) {
      candidateInst = *(int *)(instByteOffset + *(int *)(instVector + 8));
      currentInst = candidateInst;
      if (((*(uint *)(candidateInst + 0x14) & 1) != 0) && (*(int *)(candidateInst + 0x98) != 6)) {
        if (vec2Count < vec2Capacity) {
          byteOffset = vec2Count * 4;
          _memset(byteOffset + vec2Data,0,4);
          vec2Count = queuedCount + 1;
          elementPtr = (int *)(byteOffset + vec2Data);
        }
        else {
          elementPtr = (int *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
        }
        *elementPtr = candidateInst;
        *(uint *)(currentInst + 0x14) = *(uint *)(currentInst + 0x14) & 0xfffffff7;
        *(uint *)(currentInst + 0x14) = *(uint *)(currentInst + 0x14) & 0xffffffef;
        instVector = *(int *)(program + PROG_instructionVector);
      }
      instByteOffset = instByteOffset + 4;
    }
    while (vec2Count != 0) {
      topIndex = vec2Count - 1;
      topSlot = (undefined4 *)0x0;
      if (topIndex < vec2Count) {
        topSlot = (undefined4 *)(topIndex * 4 + vec2Data);
      }
      poppedInst = *topSlot;
      Vector__removeAt(&vec2Capacity,topIndex);
      Program__removeInst(program,poppedInst);
    }
  }
  Arena__free(vec2Arena,vec2Data);
LAB_0013dcf0:
  vecArena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  idArrayBytes = *(int *)(*(int *)(program + PROG_compiler) + COMP_nextInstId) << 2;
  unionFindParents = Arena__alloc(*(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB),idArrayBytes);
  matchingDefMap = Arena__alloc(*(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB),idArrayBytes);
  blockListObject = program + 0x37c;
  block = *(int *)(program + PROG_blockListHead);
  for (blockCursor = *(int *)(*(int *)(program + PROG_blockListHead) + 8); blockCursor != 0; blockCursor = *(int *)(blockCursor + 8)) {
    inst = *(int **)(block + 0x98);
    lookaheadInst = (int *)inst[2];
    if ((int *)inst[2] != (int *)0x0) {
      do {
        nextInst = lookaheadInst;
        if ((inst[5] & 1U) != 0) {
          *(int *)(inst[0x53] * 4 + unionFindParents) = inst[0x53];
          *(undefined4 *)(matchingDefMap + inst[0x53] * 4) = 0;
          vcall48Result = (**(code **)(*inst + 0x48))(inst);
          if (vcall48Result != 0) {
            inst[0x27] = DAT_001b0008;
          }
          inst[3] = 0;
          ((int (*)())FUN_0013d820)(inst,program);
          arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
          allocation = (undefined4 *)Arena__alloc(arena,0x14);
          *allocation = arena;
          allocation[1] = 2;
          allocation[2] = 0;
          allocation[4] = arena;
          vectorData = Arena__alloc(arena,8);
          allocation[3] = vectorData;
          nextInst = (int *)inst[2];
          inst[4] = (int)(allocation + 1);
        }
        lookaheadInst = (int *)nextInst[2];
        inst = nextInst;
      } while ((int *)nextInst[2] != (int *)0x0);
      blockCursor = *(int *)(block + 8);
    }
    block = blockCursor;
  }
  instVector = *(int *)(program + PROG_instructionVector);
  instByteOffset = 0;
  currentInst = 0;
  for (instOrdinal = 1; instOrdinal <= *(uint *)(instVector + 4); instOrdinal = instOrdinal + 1) {
    scanInst = *(int *)(instByteOffset + *(int *)(instVector + 8));
    currentInst = scanInst;
    if ((*(uint *)(scanInst + 0x14) & 1) != 0) {
      operandRecord2 = IRInst__getOperandRecord(scanInst,0);
      WriteMask__fromSelectWord(&destWriteMask,*(undefined4 *)(operandRecord2 + 0x10));
      queuedCount = vecCount;
      pushedInst = currentInst;
      *(undefined4 *)(scanInst + 0xc) = destWriteMask;
      if (vecCount < vecCapacity) {
        byteOffsetD = vecCount * 4;
        _memset(byteOffsetD + vecData,0,4);
        vecCount = queuedCount + 1;
        elementPtr = (int *)(byteOffsetD + vecData);
      }
      else {
        elementPtr = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
      }
      *elementPtr = pushedInst;
      instVector = *(int *)(program + PROG_instructionVector);
    }
    instByteOffset = instByteOffset + 4;
  }
  do {
    do {
      if (vecCount == 0) {
        block = *(int *)(blockListObject + 8);
        nextBlockB = *(int *)(block + 8);
        if (*(int *)(block + 8) != 0) {
          do {
            nextBlock = nextBlockB;
            lookaheadInst = (int *)(*(int **)(block + 0x98))[2];
            inst = *(int **)(block + 0x98);
            if (lookaheadInst != (int *)0x0) {
              do {
                nextInst = lookaheadInst;
                if ((inst[5] & 1U) != 0) {
                  operandRecord3 = IRInst__getOperandRecord(inst,0);
                  SelectWord__selectWhereMasked(&destSelectWordB,*(undefined4 *)(operandRecord3 + 0x10),inst[3]);
                  destSelectWord = destSelectWordB;
                  if (((((inst[0x20] != 0) && (predicateResultC = RegKind__flagBit0(inst[0x26]), predicateResultC != 0)
                        ) && (((inst[5] & 2U) == 0 &&
                              (predicateResultC = (**(code **)(*inst + 0x50))(inst), predicateResultC == 0)))) ||
                      ((predicateResultC = RegKind__flagBit7(inst[0x26]), predicateResultC != 0 ||
                       (predicateResultC = RegKind__flagBit8(inst[0x26]), predicateResultC != 0)))) &&
                     ((lookaheadInst = *(int **)(*(int *)(program + PROG_compiler) + COMP_target),
                      predicateResultC = (**(code **)(*lookaheadInst + 0x7c))(lookaheadInst,inst), predicateResultC != 0 &&
                      (destOperandRecordB = IRInst__getOperandRecord(inst,0), destSelectWord != *(int *)(destOperandRecordB + 0x10))))) {
                    inst[0x27] = destSelectWord;
                  }
                  if (inst[3] != 0) {
                    lastOperandIndexB = inst[0x21];
                    if ((inst[5] & 0x200U) != 0) {
                      lastOperandIndexB = lastOperandIndexB + -1;
                    }
                    hasDefaultSelects = (**(code **)(*inst + 0x60))(inst);
                    if (hasDefaultSelects != 0) {
                      if (0 < lastOperandIndexB) {
                        operandIndex = 1;
                        do {
                          vec2Capacity = DAT_001b0020;
                          operandLimit = (**(code **)(*inst + 0x14))(inst);
                          if (operandIndex <= operandLimit) {
                            IRInst__computeSourceLaneMask(&operandSelectOutA,inst,operandIndex,program,destSelectWord);
                            identitySelectB = DAT_001b0000;
                            vec2Capacity = operandSelectOutA;
                            savedScratchWord = vec2Capacity;
                            (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 3)) = (char)operandSelectOutA;
                            (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 2)) = (char)(operandSelectOutA >> 8);
                            (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 1)) = (char)(operandSelectOutA >> 0x10);
                            (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 0)) = (char)(operandSelectOutA >> 0x18);
                            lowByteIsZero = (char)vec2Capacity == '\0';
                            byte2IsZero = (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 2)) == '\0';
                            byte1IsZero = (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 1)) == '\0';
                            highByteIsZero = (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 0)) == '\0';
                            vec2Capacity = savedScratchWord;
                            if (((lowByteIsZero && byte2IsZero) && byte1IsZero) && highByteIsZero) {
                              if (operandIndex == 0) {
                                inst[0x27] = DAT_001b0000;
                              }
                              else {
                                operandRecord = IRInst__getOperandRecord(inst,operandIndex);
                                *(int *)(operandRecord + 0x10) = identitySelectB;
                              }
                            }
                          }
                          operandIndex = operandIndex + 1;
                        } while (operandIndex <= lastOperandIndexB);
                      }
                      IRInst__removeDefaultSelectOperands(inst,*(undefined4 *)(program + PROG_compiler));
                      lastOperandIndexB = inst[0x21];
                      if ((inst[5] & 0x200U) != 0) {
                        lastOperandIndexB = lastOperandIndexB + -1;
                      }
                    }
                    if (0 < lastOperandIndexB) {
                      operandIndex = 1;
                      do {
                        operandSelectWord = DAT_001b0020;
                        sourceInst = (int *)IRInst__getOperandSource(inst,operandIndex);
                        operandLimit = (**(code **)(*inst + 0x14))(inst);
                        if (operandIndex <= operandLimit) {
                          IRInst__computeSourceLaneMask(&operandSelectOutB,inst,operandIndex,program,destSelectWord);
                          operandSelectWord = operandSelectOutB;
                        }
                        hasSpecialSource = ((int (*)())FUN_001396d0)(*(undefined4 *)(program + PROG_compiler),inst,operandIndex,program);
                        operandReadMask = DAT_001b0020;
                        if (hasSpecialSource == 0) {
                          operandLimit = (**(code **)(*inst + 0x14))(inst);
                          if (operandIndex <= operandLimit) {
                            IRInst__computeSourceReadMask(&operandReadMaskOutB,inst,operandIndex,inst[3],program);
                            operandReadMask = operandReadMaskOutB;
                          }
                          if (sourceInst != (int *)0x0) {
                            if (((((sourceInst[0x20] != 0) &&
                                  (predicateResultB = RegKind__flagBit0(sourceInst[0x26]), predicateResultB != 0)) &&
                                 ((sourceInst[5] & 2U) == 0)) &&
                                (predicateResultB = (**(code **)(*sourceInst + 0x50))(sourceInst), predicateResultB == 0)) ||
                               ((predicateResultB = RegKind__flagBit7(sourceInst[0x26]), predicateResultB != 0 ||
                                (predicateResultB = RegKind__flagBit8(sourceInst[0x26]), predicateResultB != 0)))) {
                              while( true ) {
                                maskedWriteMask = operandReadMask & sourceInst[3];
                                (*(unsigned char *)((unsigned char *)&(maskedWriteMaskBytes) + 3)) = (char)maskedWriteMask;
                                (*(unsigned char *)((unsigned char *)&(maskedWriteMaskBytes) + 2)) = (char)(maskedWriteMask >> 8);
                                (*(unsigned char *)((unsigned char *)&(maskedWriteMaskBytes) + 1)) = (char)(maskedWriteMask >> 0x10);
                                (*(unsigned char *)((unsigned char *)&(maskedWriteMaskBytes) + 0)) = (char)(maskedWriteMask >> 0x18);
                                maskedWriteMaskBytes = maskedWriteMask;
                                if ((((char)maskedWriteMaskBytes != '\0' || (*(unsigned char *)((unsigned char *)&(maskedWriteMaskBytes) + 2)) != '\0') ||
                                    (*(unsigned char *)((unsigned char *)&(maskedWriteMaskBytes) + 1)) != '\0') || (*(unsigned char *)((unsigned char *)&(maskedWriteMaskBytes) + 0)) != '\0') break;
                                sourceInst = (int *)((int (*)())FUN_0013ca84)(sourceInst);
                              }
                              IRInst__setOperandSource(inst,operandIndex,sourceInst,0,*(undefined4 *)(program + PROG_compiler));
                              operandRecord5 = IRInst__getOperandRecord(inst,operandIndex);
                              SelectWord__maskUnused(&maskedSelectOut,*(undefined4 *)(operandRecord5 + 0x10),operandSelectWord);
                              maskedSelectWord = maskedSelectOut;
                              operandRecord = IRInst__getOperandRecord(inst,operandIndex);
                              if (*(int *)(operandRecord + 0x10) != DAT_001b0000) {
                                userList = (uint *)sourceInst[4];
                                userCount = userList[1];
                                if (userCount < *userList) {
                                  _memset(userCount * 4 + userList[2],0,4);
                                  pushSlot = (undefined4 *)(userCount * 4 + userList[2]);
                                  userList[1] = userCount + 1;
                                }
                                else {
                                  pushSlot = (undefined4 *)Vector__elementRefGrow(userList,userCount);
                                }
                                *pushSlot = inst;
                              }
                              ((int (*)())IRInst__markOpcode13After12)(sourceInst,inst);
                              goto code_r0x0013e80c;
                            }
                            userList = (uint *)sourceInst[4];
                            userCount = userList[1];
                            if (userCount < *userList) {
                              _memset(userCount * 4 + userList[2],0,4);
                              pushSlot = (undefined4 *)(userCount * 4 + userList[2]);
                              userList[1] = userCount + 1;
                            }
                            else {
                              pushSlot = (undefined4 *)Vector__elementRefGrow(userList,userCount);
                            }
                            *pushSlot = inst;
                          }
                        }
                        else {
                          isProjectionOfClass26or3a = IRInst__isProjectionOfClass26or3a(inst);
                          selectWordConst = DAT_001b0004;
                          if (isProjectionOfClass26or3a != 0) {
                            selectWordConst = DAT_001b001c;
                          }
                          instFlagBit2Result = OpcodeTraits__instFlagBit2(*(undefined4 *)(program + PROG_compiler),inst);
                          if (instFlagBit2Result != 0) {
                            if (operandIndex == 1) {
                              selectConstPtr = &UNK_001b0018;
                            }
                            else {
                              selectConstPtr = &DAT_001b001c;
                            }
                            selectWordConst = *selectConstPtr;
                          }
                          SelectWord__maskUnused(&projSelectWord,selectWordConst,operandSelectWord);
                          maskedSelectWord = projSelectWord;
                          sourceDef = IRInst__getOperandSource(inst,operandIndex);
                          userList = *(uint **)(sourceDef + 0x10);
                          if (userList == (uint *)0x0) {
                            arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
                            allocation = (undefined4 *)Arena__alloc(arena,0x14);
                            userList = allocation + 1;
                            *allocation = arena;
                            allocation[1] = 2;
                            allocation[2] = 0;
                            allocation[4] = arena;
                            vectorData = Arena__alloc(arena,8);
                            allocation[3] = vectorData;
                            *(uint **)(sourceDef + 0x10) = userList;
                          }
                          userCount = userList[1];
                          if (userCount < *userList) {
                            _memset(userCount * 4 + userList[2],0,4);
                            pushSlot = (undefined4 *)(userCount * 4 + userList[2]);
                            userList[1] = userCount + 1;
                          }
                          else {
                            pushSlot = (undefined4 *)Vector__elementRefGrow(userList,userCount);
                          }
                          *pushSlot = inst;
code_r0x0013e80c:
                          operandRecord = IRInst__getOperandRecord(inst,operandIndex);
                          if (maskedSelectWord != *(int *)(operandRecord + 0x10)) {
                            if (operandIndex == 0) {
                              inst[0x27] = maskedSelectWord;
                            }
                            else {
                              operandRecord = IRInst__getOperandRecord(inst,operandIndex);
                              *(int *)(operandRecord + 0x10) = maskedSelectWord;
                            }
                          }
                        }
                        operandIndex = operandIndex + 1;
                      } while (operandIndex <= lastOperandIndexB);
                    }
                  }
                  if ((((inst[0x20] == 0) || (predicateResultD = RegKind__flagBit0(inst[0x26]), predicateResultD == 0))
                      || (((inst[5] & 2U) != 0 ||
                          (predicateResultD = (**(code **)(*inst + 0x50))(inst), predicateResultD != 0)))) &&
                     ((predicateResultD = RegKind__flagBit7(inst[0x26]), predicateResultD == 0 &&
                      (predicateResultD = RegKind__flagBit8(inst[0x26]), predicateResultD == 0)))) {
                    nextInst = (int *)inst[2];
                  }
                  else {
                    candidateDef = 0;
                    if (inst[3] != 0) {
                      candidateDef = ((int (*)())FUN_0013ca84)(inst);
                    }
                    defRoot = disjointSetFindRoot(inst[0x53],unionFindParents);
                    while ((candidateDef != 0 &&
                           ((candidateRoot = disjointSetFindRoot(*(undefined4 *)(candidateDef + 0x14c),unionFindParents),
                            defRoot != candidateRoot || (candidateRoot = FUN_000f497c(candidateDef,inst), candidateRoot == 0)
                            )))) {
                      candidateDef = ((int (*)())FUN_0013ca84)(candidateDef);
                    }
                    *(int *)(matchingDefMap + inst[0x53] * 4) = candidateDef;
                    nextInst = (int *)inst[2];
                  }
                }
                lookaheadInst = (int *)nextInst[2];
                inst = nextInst;
              } while ((int *)nextInst[2] != (int *)0x0);
              nextBlock = *(int *)(block + 8);
            }
            nextBlockB = *(int *)(nextBlock + 8);
            block = nextBlock;
          } while (*(int *)(nextBlock + 8) != 0);
          block = *(int *)(blockListObject + 8);
        }
        nextBlockB = *(int *)(block + 8);
        while (successorBlock = nextBlockB, successorBlock != 0) {
          lookaheadInst = (int *)(*(int **)(block + 0x98))[2];
          inst = *(int **)(block + 0x98);
          if (lookaheadInst != (int *)0x0) {
            do {
              nextInst = lookaheadInst;
              if ((inst[5] & 1U) != 0) {
                if (((((inst[0x20] != 0) && (predicateResultD = RegKind__flagBit0(inst[0x26]), predicateResultD != 0))
                     && ((inst[5] & 2U) == 0)) &&
                    (predicateResultD = (**(code **)(*inst + 0x50))(inst), predicateResultD == 0)) ||
                   ((predicateResultD = RegKind__flagBit7(inst[0x26]), predicateResultD != 0 ||
                    (predicateResultD = RegKind__flagBit8(inst[0x26]), predicateResultD != 0)))) {
                  destOperandRecordC = IRInst__getOperandRecord(inst,0);
                  if (*(int *)(destOperandRecordC + 0x10) != DAT_001b0014) {
                    IRInst__canonicalizeCommutativeOperands(inst,*(undefined4 *)(program + PROG_compiler));
                  }
                  if ((inst[5] & 0x200U) != 0) {
                    matchedDef = *(int *)(matchingDefMap + inst[0x53] * 4);
                    if (matchedDef == 0) {
                      IRInst__setOperandSource(inst,inst[0x21],0,0,*(undefined4 *)(program + PROG_compiler));
                      inst[0x21] = inst[0x21] + -1;
                      inst[5] = inst[5] & 0xfffffdff;
                    }
                    else {
                      IRInst__setExtraOperandSource(inst,matchedDef,0,*(undefined4 *)(program + PROG_compiler));
                      identitySelect = DAT_001b0000;
                      if (inst[0x21] == 0) {
                        inst[0x27] = DAT_001b0000;
                      }
                      else {
                        lastOperandRecordB = IRInst__getOperandRecord(inst,inst[0x21]);
                        *(int *)(lastOperandRecordB + 0x10) = identitySelect;
                      }
                      userList = *(uint **)(matchedDef + 0x10);
                      userCount = userList[1];
                      if (userCount < *userList) {
                        _memset(userCount * 4 + userList[2],0,4);
                        pushSlot = (undefined4 *)(userCount * 4 + userList[2]);
                        userList[1] = userCount + 1;
                      }
                      else {
                        pushSlot = (undefined4 *)Vector__elementRefGrow(userList,userCount);
                      }
                      *pushSlot = inst;
                      *(uint *)(matchedDef + 0x14) = *(uint *)(matchedDef + 0x14) | 0x400000;
                    }
                  }
                  if (((inst[0x48] != 0) || (inst[0x49] != 0)) &&
                     (((inst[5] & 0x200U) != 0 &&
                      (lookaheadInst = *(int **)(*(int *)(program + PROG_compiler) + COMP_target),
                      predicateResultD = (**(code **)(*lookaheadInst + 0x7c))(lookaheadInst,inst), predicateResultD == 0)))) {
                    cloneResult = IRInst__clone(inst,*(undefined4 *)(program + PROG_compiler),0);
                    arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
                    allocation = (undefined4 *)Arena__alloc(arena,0x14);
                    *allocation = arena;
                    allocation[1] = 2;
                    allocation[2] = 0;
                    allocation[4] = arena;
                    vectorData = Arena__alloc(arena,8);
                    allocation[3] = vectorData;
                    *(undefined4 **)(cloneResult + 0x10) = allocation + 1;
                    Block__insertInstBefore(block,inst,cloneResult);
                    savedUsers = inst[4];
                    DList__unlink(inst);
                    IRInst__reinitAsMov(inst,0x31,*(undefined4 *)(program + PROG_compiler));
                    inst[4] = savedUsers;
                    inst[0x25] = inst[0x53];
                    inst[0x26] = 0;
                    IRInst__setOperandSource(inst,1,cloneResult,0,*(undefined4 *)(program + PROG_compiler));
                    lastOperandSource = IRInst__getOperandSource(cloneResult,*(undefined4 *)(cloneResult + 0x84));
                    IRInst__setExtraOperandSource(inst,lastOperandSource,0,*(undefined4 *)(program + PROG_compiler));
                    identitySelectD = DAT_001b0000;
                    if (inst[0x21] == 0) {
                      inst[0x27] = DAT_001b0000;
                    }
                    else {
                      lastOperandRecordB = IRInst__getOperandRecord(inst,inst[0x21]);
                      *(int *)(lastOperandRecordB + 0x10) = identitySelectD;
                    }
                    userList = *(uint **)(cloneResult + 0x10);
                    userCount = userList[1];
                    if (userCount < *userList) {
                      _memset(userCount * 4 + userList[2],0,4);
                      pushSlot = (undefined4 *)(userCount * 4 + userList[2]);
                      userList[1] = userCount + 1;
                    }
                    else {
                      pushSlot = (undefined4 *)Vector__elementRefGrow(userList,userCount);
                    }
                    *pushSlot = inst;
                    IRInst__setOperandSource(cloneResult,*(undefined4 *)(cloneResult + 0x84),0,0,
                                 *(undefined4 *)(program + PROG_compiler));
                    cloneOperandCount = *(int *)(cloneResult + 0x84) + -1;
                    *(int *)(cloneResult + 0x84) = cloneOperandCount;
                    *(uint *)(cloneResult + 0x14) = *(uint *)(cloneResult + 0x14) & 0xfffffdff;
                    *(int *)(cloneResult + 0x160) =
                         *(int *)(*(int *)(*(int *)(program + PROG_compiler) + COMP_currentProgram) + 0x478) + 1;
                    if (0 < cloneOperandCount) {
                      operandIndexB = 1;
                      do {
                        cloneSource = IRInst__getOperandSource(cloneResult,operandIndexB);
                        userCount = (*(uint **)(cloneSource + 0x10))[1];
                        if (userCount != 0) {
                          userIndex = 0;
                          userList = *(uint **)(cloneSource + 0x10);
                          do {
                            if (userIndex < *userList) {
                              userListRef = userList;
                              if (userCount <= userIndex) {
                                _memset(userCount * 4 + userList[2],0,(userIndex - userCount) * 4 + 4);
                                userList[1] = userIndex + 1;
                                userListRef = *(uint **)(cloneSource + 0x10);
                              }
                              userElementPtr = (int *)(userIndex * 4 + userList[2]);
                            }
                            else {
                              userElementPtr = (int *)Vector__elementRefGrow(userList,userIndex);
                              userListRef = *(uint **)(cloneSource + 0x10);
                            }
                            if (inst == (int *)*userElementPtr) {
                              Vector__removeAt(userListRef,userIndex);
                              userList = *(uint **)(cloneSource + 0x10);
                              userCount = userList[1];
                              if (userCount < *userList) {
                                _memset(userCount * 4 + userList[2],0,4);
                                userElementPtr = (int *)(userCount * 4 + userList[2]);
                                userList[1] = userCount + 1;
                              }
                              else {
                                userElementPtr = (int *)Vector__elementRefGrow(userList,userCount);
                              }
                              *userElementPtr = cloneResult;
                              break;
                            }
                            userCount = userListRef[1];
                            userIndex = userIndex + 1;
                            userList = userListRef;
                          } while (userIndex < userCount);
                        }
                        operandIndexB = operandIndexB + 1;
                      } while (operandIndexB <= *(int *)(cloneResult + 0x84));
                    }
                    Block__insertInstAfter(block,cloneResult,inst);
                  }
                }
                nextInst = (int *)inst[2];
              }
              lookaheadInst = (int *)nextInst[2];
              inst = nextInst;
            } while ((int *)nextInst[2] != (int *)0x0);
            successorBlock = *(int *)(block + 8);
          }
          block = successorBlock;
          nextBlockB = *(int *)(successorBlock + 8);
        }
        instVector = *(int *)(program + PROG_instructionVector);
        instByteOffset = 0;
        *(int *)(program + PROG_visitStamp) = *(int *)(program + PROG_visitStamp) + 1;
        currentInst = 0;
        for (instOrdinal = 1; queuedCount = vecCount, instOrdinal <= *(uint *)(instVector + 4); instOrdinal = instOrdinal + 1) {
          candidateInst = *(int *)(*(int *)(instVector + 8) + instByteOffset);
          currentInst = candidateInst;
          if ((*(uint *)(candidateInst + 0x14) & 1) != 0) {
            if (vecCount < vecCapacity) {
              byteOffset = vecCount * 4;
              _memset(byteOffset + vecData,0,4);
              vecCount = queuedCount + 1;
              elementPtr = (int *)(byteOffset + vecData);
            }
            else {
              elementPtr = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *elementPtr = candidateInst;
            instVector = *(int *)(program + PROG_instructionVector);
          }
          instByteOffset = instByteOffset + 4;
        }
        do {
          do {
            if (vecCount == 0) {
              *(uint *)(program + PROG_flags) = *(uint *)(program + PROG_flags) | 0x20000;
              Program__beginPass(program,"reduce");
              *(uint *)(program + PROG_flags) = *(uint *)(program + PROG_flags) | 0x80;
              Arena__free(vecArena,vecData);
              return;
            }
            topIndex = vecCount - 1;
            topElementPtr = (int *)0x0;
            if (topIndex < vecCount) {
              topElementPtr = (int *)(topIndex * 4 + vecData);
            }
            poppedInstB = *topElementPtr;
            Vector__removeAt(&vecCapacity,topIndex);
            operandCount = *(int *)(poppedInstB + 0x84);
            *(undefined4 *)(poppedInstB + 0x150) = *(undefined4 *)(program + PROG_visitStamp);
            if ((*(uint *)(poppedInstB + 0x14) & 0x200) != 0) {
              operandCount = operandCount + -1;
            }
          } while (operandCount < 1);
          sourceIndex = 1;
          do {
            operandSourceInst = (int *)IRInst__getOperandSource(poppedInstB,sourceIndex);
            vecCountBefore = vecCount;
            if (operandSourceInst != (int *)0x0) {
              if (*(int *)(program + PROG_visitStamp) != operandSourceInst[0x54]) {
                if (vecCount < vecCapacity) {
                  byteOffsetB = vecCount * 4;
                  _memset(byteOffsetB + vecData,0,4);
                  vecCount = vecCountBefore + 1;
                  pushSlot = (undefined4 *)(byteOffsetB + vecData);
                }
                else {
                  pushSlot = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
                }
                *pushSlot = operandSourceInst;
              }
              if (((((operandSourceInst[0x20] != 0) && (predicateResult = RegKind__flagBit0(operandSourceInst[0x26]), predicateResult != 0)) &&
                   ((operandSourceInst[5] & 2U) == 0)) &&
                  (predicateResult = (**(code **)(*operandSourceInst + 0x50))(operandSourceInst), predicateResult == 0)) ||
                 ((predicateResult = RegKind__flagBit7(operandSourceInst[0x26]), predicateResult != 0 ||
                  (predicateResult = RegKind__flagBit8(operandSourceInst[0x26]), predicateResult != 0)))) {
                operandRecord4 = IRInst__getOperandRecord(poppedInstB,sourceIndex);
                SelectWord__readMask(&selectReadMask,*(undefined4 *)(operandRecord4 + 0x10));
                componentIndex = 0;
                selectReadMaskBytes = selectReadMask;
                defInst = operandSourceInst;
code_r0x0013f320:
                do {
                  predicateResultC = RegKind__flagBit6(defInst[0x26]);
                  vecCountBefore = vecCount;
                  if (predicateResultC == 0) {
                    if (*(int *)(program + PROG_visitStamp) != defInst[0x54]) {
                      if (vecCount < vecCapacity) {
                        byteOffsetD = vecCount * 4;
                        _memset(byteOffsetD + vecData,0,4);
                        pushSlot = (undefined4 *)(byteOffsetD + vecData);
                        vecCount = vecCountBefore + 1;
                      }
                      else {
                        pushSlot = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
                      }
                      *pushSlot = defInst;
                    }
                    vec2Capacity = defInst[3];
                    if ((*(char *)((int)&selectReadMaskBytes + componentIndex) != '\0') &&
                       (*(char *)((int)&vec2Capacity + componentIndex) == '\0')) {
                      lastOperandIndex = defInst[0x21];
                      destOperandRecordB = IRInst__getOperandRecord(defInst,lastOperandIndex);
                      operandSelectBytes = *(int *)(destOperandRecordB + 0x10);
                      if (*(char *)((int)&operandSelectBytes + componentIndex) == '\x04') {
                        *(char *)((int)&operandSelectBytes + componentIndex) = (char)componentIndex;
                        fixedSelectWord = operandSelectBytes;
                        if (lastOperandIndex == 0) {
                          defInst[0x27] = operandSelectBytes;
                        }
                        else {
                          lastOperandRecord = IRInst__getOperandRecord(defInst,lastOperandIndex);
                          *(int *)(lastOperandRecord + 0x10) = fixedSelectWord;
                        }
                        defInst = (int *)IRInst__getOperandSource(defInst,defInst[0x21]);
                        if (defInst != (int *)0x0) goto code_r0x0013f320;
                      }
                    }
                  }
                  moreComponents = componentIndex != 3;
                  componentIndex = componentIndex + 1;
                  defInst = operandSourceInst;
                } while (moreComponents);
              }
            }
            sourceIndex = sourceIndex + 1;
          } while (sourceIndex <= operandCount);
        } while( true );
      }
      topIndex = vecCount - 1;
      topSlot = (undefined4 *)0x0;
      if (topIndex < vecCount) {
        topSlot = (undefined4 *)(topIndex * 4 + vecData);
      }
      workInst = (int *)*topSlot;
      Vector__removeAt(&vecCapacity,topIndex);
      vcall30Result = (**(code **)(*workInst + 0x30))(workInst);
      if (((vcall30Result != 0) && (-1 < workInst[0x4d])) &&
         (*(int *)(workInst[0x4d] * 0xc + *(int *)(program + 0x78) + 4) - 10U < 2)) {
        firstOperandSource = IRInst__getOperandSource(workInst,1);
        producerInst = (int *)IRInst__findLaneDefinition(firstOperandSource,3,&currentInst);
        if ((producerInst != (int *)0x0) && (vcall30Result = (**(code **)(*producerInst + 0x50))(), vcall30Result != 0)) {
          (**(code **)(*workInst + 0x88))(workInst,1,3,4);
        }
      }
      if ((workInst[5] & 0x200U) == 0) {
        operandCount = workInst[0x21];
      }
      else {
        operandCount = workInst[0x21] + -1;
      }
    } while (operandCount < 1);
    operandIndexB = 1;
    globalsBase = &UNK_001ada48;
    do {
      operandVReg = (int *)IRInst__getOperandSource(workInst,operandIndexB);
      if (operandVReg != (int *)0x0) {
        if ((((operandVReg[0x20] == 0) || (predicateResultC = RegKind__flagBit0(operandVReg[0x26]), predicateResultC == 0)) ||
            (((operandVReg[5] & 2U) != 0 ||
             (predicateResultC = (**(code **)(*operandVReg + 0x50))(operandVReg), predicateResultC != 0)))) &&
           (predicateResultC = RegKind__flagBit7(operandVReg[0x26]), predicateResultC == 0)) {
          flagBit8Result = RegKind__flagBit8(operandVReg[0x26]);
          replacesWriteMask = false;
          if (flagBit8Result != 0) goto code_r0x0013e0ac;
        }
        else {
code_r0x0013e0ac:
          replacesWriteMask = true;
        }
        vec2Capacity = *(uint *)(globalsBase + 0x25d8);
        operandLimitB = (**(code **)(*workInst + 0x14))(workInst);
        if (operandIndexB <= operandLimitB) {
          IRInst__computeSourceReadMask(&operandReadMaskOutA,workInst,operandIndexB,workInst[3],program);
          vec2Capacity = operandReadMaskOutA;
        }
        identitySelectC = DAT_001b0000;
        if ((((char)vec2Capacity == '\0' && (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 2)) == '\0') && (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 1)) == '\0') &&
            (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 0)) == '\0') {
          if (operandIndexB == 0) {
            workInst[0x27] = DAT_001b0000;
          }
          else {
            selectRecord = IRInst__getOperandRecord(workInst,operandIndexB);
            *(int *)(selectRecord + 0x10) = identitySelectC;
          }
        }
        replacesWriteMask = !replacesWriteMask;
        if (replacesWriteMask) {
          vec2Capacity = 0x1000000;
        }
        rootCursor = -1;
        while (vec2Capacity != 0) {
          if (*(int *)(operandVReg[0x22] + 8) == 0x8e) {
            chainInst = (**(code **)(*operandVReg + 0x7c))(operandVReg);
            mergedMask = vec2Capacity;
            if (chainInst == 0) {
              mergeTarget = 0;
            }
            else {
              prevRoot = rootCursor;
              prevMergeTarget = 0;
              do {
                disjointSetFindRootResult = disjointSetFindRoot(*(undefined4 *)(chainInst + 0x14c),unionFindParents);
                destOperandRecordB = IRInst__getOperandRecord(chainInst,0);
                WriteMask__fromSelectWord(&chainedWriteMask,*(undefined4 *)(destOperandRecordB + 0x10));
                if ((prevRoot == disjointSetFindRootResult) ||
                   (rootCursor = prevRoot, mergeTarget = prevMergeTarget, (chainedWriteMask & mergedMask) != 0)) {
                  mergedMask = mergedMask | chainedWriteMask;
                  rootCursor = disjointSetFindRootResult;
                  if ((-1 < prevRoot) && (rootCursor = prevRoot, prevRoot != disjointSetFindRootResult)) {
                    storeIndexedWord(prevRoot,disjointSetFindRootResult,unionFindParents);
                  }
                  mergeTarget = chainInst;
                  if (prevMergeTarget != 0) {
                    *(undefined4 *)(chainInst + 0xc) = 0;
                    *(int *)(chainInst + 0x9c) = DAT_001b0014;
                    mergeTarget = prevMergeTarget;
                  }
                }
                chainInst = *(int *)(chainInst + 300);
                prevRoot = rootCursor;
                prevMergeTarget = mergeTarget;
              } while (chainInst != 0);
            }
            queuedCount = vecCount;
            if (*(uint *)(mergeTarget + 0xc) != mergedMask) {
              if (vecCount < vecCapacity) {
                byteOffsetC = vecCount * 4;
                _memset(byteOffsetC + vecData,0,4);
                vecCount = queuedCount + 1;
                growSlotPtr = (int *)(byteOffsetC + vecData);
              }
              else {
                growSlotPtr = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
              }
              *growSlotPtr = mergeTarget;
              *(uint *)(mergeTarget + 0xc) = mergedMask;
              SelectWord__selectWhereMasked(&mergedSelectWord,DAT_001b0008,mergedMask);
              *(undefined4 *)(mergeTarget + 0x9c) = mergedSelectWord;
            }
            vec2Capacity = 0;
          }
          else {
            destOperandRecord = IRInst__getOperandRecord(operandVReg,0);
            WriteMask__fromSelectWord(&operandWriteMask,*(undefined4 *)(destOperandRecord + 0x10));
            defWriteMask = operandWriteMask;
            if (((replacesWriteMask) || (resolvedRoot = rootCursor, (operandWriteMask & vec2Capacity) != 0)) &&
               (resolvedRoot = disjointSetFindRoot(operandVReg[0x53],unionFindParents), -1 < rootCursor)) {
              storeIndexedWord(rootCursor,resolvedRoot,unionFindParents);
              resolvedRoot = rootCursor;
            }
            queuedCount = vecCount;
            oldWriteMask = operandVReg[3];
            if (replacesWriteMask) {
              operandVReg[3] = defWriteMask;
            }
            else {
              operandVReg[3] = defWriteMask & vec2Capacity | oldWriteMask;
            }
            if (oldWriteMask != operandVReg[3]) {
              if (vecCount < vecCapacity) {
                byteOffsetD = vecCount * 4;
                _memset(byteOffsetD + vecData,0,4);
                vecCount = queuedCount + 1;
                pushSlot = (undefined4 *)(byteOffsetD + vecData);
              }
              else {
                pushSlot = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
              }
              *pushSlot = operandVReg;
            }
            if (replacesWriteMask) break;
            isProjectionOf2a = IRInst__isProjectionOfOpcode2a(operandVReg);
            if (isProjectionOf2a == 0) {
              coveredMask = defWriteMask & vec2Capacity;
              uncoveredMask = (vec2Capacity << 0x18 | (vec2Capacity >> 8 & 0xff) << 0x10 |
                       (vec2Capacity >> 0x10 & 0xff) << 8 | vec2Capacity >> 0x18) -
                      (coveredMask << 0x18 | (coveredMask >> 8 & 0xff) << 0x10 |
                       (coveredMask >> 0x10 & 0xff) << 8 | coveredMask >> 0x18);
              vec2Capacity = uncoveredMask * 0x1000000 | (uncoveredMask & 0xff00) << 8 | uncoveredMask >> 8 & 0xff00 |
                         uncoveredMask >> 0x18;
            }
            rootCursor = resolvedRoot;
            if (vec2Capacity != 0) {
              operandVReg = (int *)IRInst__getOperandSource(operandVReg,operandVReg[0x21]);
            }
          }
        }
      }
      operandIndexB = operandIndexB + 1;
    } while (operandIndexB <= operandCount);
  } while( true );
}
#undef vec2Capacity
#undef vec2Count
#undef vec2Data
#undef vec2Arena
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* FUN_0013f3d4 @ 0x13f3d4 (2148 bytes) */
int FUN_0013f3d4(inst, program)
  int *inst;
  int program;
{
  int destSelectWord;
  uint *sourceUsersVec;
  undefined4 *userSlot;
  int *sourceUserEntry;
  int *user;
  undefined4 arena;
  int extraSelectSaved;
  int userByteOffset;
  int instVtable;
  uint userCount;
  int *partner;
  int vcall64Result;
  int loopIndex3;
  bool moreComponents;
  undefined4 sourceDef4;
  int sourceDef3;
  int operandRecord2;
  int sourceDef2;
  int sourceDef;
  int operandRecord;
  uint loopIndex;
  bool extraSelectChanged;
  char instSelectByte;
  uint instFlags;
  int *usersVecHeader;
  undefined4 *firstUserSlot;
  int otherSource;
  int iVar7;
  int otherOperandIndex;
  int *newInst;
  uint userCountCopy;
  int *operandVReg;
  char partnerSelectByte;
  int loopIndexB;
  undefined4 matchedOperandIndex;
  uint loopIndex2;
  bool partnerFlag400000Clear;
  code *setLaneSelectFn;
  uint uVar18;
  uint *partnerUsersVec;
  int countdown;
  undefined4 operandSelect;
  int extraSelectWord [2];
  int mergedDestSelectOut [2];
  
  instFlags = inst[5];
  if ((instFlags & 0x200) == 0) {
    if ((instFlags & 0x400000) == 0) {
      return true;
    }
    usersVecHeader = (int *)inst[4];
    if (usersVecHeader[1] != 1) {
      return false;
    }
    if (*usersVecHeader == 0) {
      firstUserSlot = (undefined4 *)Vector__elementRefGrow(usersVecHeader,0);
    }
    else {
      firstUserSlot = (undefined4 *)usersVecHeader[2];
    }
    partner = (int *)*firstUserSlot;
    instFlags = partner[5];
    if ((instFlags & 0x200) != 0) {
      IRInst__getOperandSource(partner,partner[0x21]);
      instFlags = partner[5];
    }
    partnerFlag400000Clear = (instFlags & 0x400000) == 0;
  }
  else {
    if ((instFlags & 0x400000) != 0) {
      return false;
    }
    partnerFlag400000Clear = true;
    partner = (int *)IRInst__getOperandSource(inst,inst[0x21]);
  }
  vcall64Result = (**(code **)(*partner + 100))(partner);
  if (vcall64Result != 0) {
    otherSource = IRInst__getOperandSource(inst,1);
    sourceDef2 = IRInst__getOperandSource(inst,2);
    sourceDef3 = IRInst__getOperandSource(partner,1);
    if (otherSource == sourceDef3) {
      matchedOperandIndex = 2;
      otherOperandIndex = 1;
      otherSource = sourceDef2;
    }
    else {
      if (sourceDef2 != sourceDef3) {
        return false;
      }
      matchedOperandIndex = 1;
      otherOperandIndex = 2;
    }
    if ((inst[0x48] == partner[0x48]) && (inst[0x49] == partner[0x49])) {
      if ((((uint)inst[otherOperandIndex * 6 + 0x28] >> 1 & 1) == ((uint)partner[0x2e] >> 1 & 1)) &&
         ((inst[otherOperandIndex * 6 + 0x28] & 1U) == (partner[0x2e] & 1U))) {
        operandRecord2 = IRInst__getOperandRecord(inst,0);
        destSelectWord = *(int *)(operandRecord2 + 0x10);
        operandRecord2 = IRInst__getOperandRecord(partner,0);
        loopIndexB = 0;
        operandSelect = *(undefined4 *)(operandRecord2 + 0x10);
        countdown = 4;
        do {
          if ((*(char *)((int)&destSelectWord + loopIndexB) != '\x01') &&
             (*(char *)((int)extraSelectWord + loopIndexB + -4) != '\x01')) {
            return false;
          }
          loopIndexB = loopIndexB + 1;
          countdown = countdown + -1;
        } while (countdown != 0);
        loopIndexB = 0;
        SelectWord__mergeWrittenLanes(mergedDestSelectOut,destSelectWord,*(undefined4 *)(operandRecord2 + 0x10));
        inst[0x27] = mergedDestSelectOut[0];
        destSelectWord = mergedDestSelectOut[0];
        newInst = (int *)((int (*)())IRInst__createWithConstantOperands)(2,mergedDestSelectOut[0],otherSource,program,*(undefined4 *)(program + 8),
                                     (double)FLOAT_001aa0d4);
        do {
          if (*(char *)((int)&destSelectWord + loopIndexB) == '\0') {
            operandRecord = IRInst__getOperandRecord(partner,1);
            partnerSelectByte = *(char *)(loopIndexB + operandRecord + 0x10);
            if (partnerSelectByte == '\x04') {
              setLaneSelectFn = *(code **)(*newInst + 0x88);
              operandRecord = IRInst__getOperandRecord(inst,matchedOperandIndex);
              (*setLaneSelectFn)(newInst,1,loopIndexB,*(undefined1 *)(loopIndexB + operandRecord + 0x10));
            }
            else {
              (**(code **)(*newInst + 0x88))(newInst,2,loopIndexB,loopIndexB);
            }
            operandRecord = IRInst__getOperandRecord(inst,otherOperandIndex);
            instSelectByte = *(char *)(loopIndexB + operandRecord + 0x10);
            if (instSelectByte == '\x04') {
              instVtable = *inst;
            }
            else {
              instVtable = *inst;
              partnerSelectByte = instSelectByte;
            }
            (**(code **)(instVtable + 0x88))(inst,otherOperandIndex,loopIndexB,partnerSelectByte);
            (**(code **)(*inst + 0x88))(inst,matchedOperandIndex,loopIndexB,loopIndexB);
          }
          moreComponents = loopIndexB != 3;
          loopIndexB = loopIndexB + 1;
        } while (moreComponents);
        IRInst__setOperandSource(inst,matchedOperandIndex,newInst,1,*(undefined4 *)(program + 8));
        Block__insertInstBefore(inst[0x56],inst,newInst);
        if (((inst[5] & 0x200U) == 0) || ((partner[5] & 0x200U) != 0)) {
          if (((inst[5] & 0x200U) == 0) || ((partner[5] & 0x200U) == 0)) {
            partnerUsersVec = (uint *)partner[4];
            userCount = partnerUsersVec[1];
            uVar18 = userCount - 1;
            if (-1 < (int)uVar18) {
              userByteOffset = uVar18 * 4;
              loopIndex2 = 0;
              do {
                if (uVar18 < *partnerUsersVec) {
                  userCountCopy = partnerUsersVec[1];
                  if (userCountCopy <= uVar18) {
                    _memset(userCountCopy * 4 + partnerUsersVec[2],0,(uVar18 - userCountCopy) * 4 + 4);
                    partnerUsersVec[1] = uVar18 + 1;
                  }
                  userSlot = (undefined4 *)(userByteOffset + partnerUsersVec[2]);
                }
                else {
                  userSlot = (undefined4 *)Vector__elementRefGrow(partnerUsersVec,uVar18);
                }
                user = (int *)*userSlot;
                for (iVar7 = 1; otherOperandIndex = (**(code **)(*user + 0x14))(user), iVar7 <= otherOperandIndex;
                    iVar7 = iVar7 + 1) {
                  operandVReg = (int *)IRInst__getOperandSource(user,iVar7);
                  if (partner == operandVReg) {
                    IRInst__setOperandSource(user,iVar7,inst,1,*(undefined4 *)(program + 8));
                    goto LAB_0013fad0;
                  }
                }
                if (((user[5] & 0x200U) != 0) &&
                   (operandVReg = (int *)IRInst__getOperandSource(user,user[0x21]), partner == operandVReg)) {
                  IRInst__setExtraOperandSource(user,inst,1,*(undefined4 *)(program + 8));
                }
LAB_0013fad0:
                loopIndex2 = loopIndex2 + 1;
                uVar18 = uVar18 - 1;
                userByteOffset = userByteOffset + -4;
                if (loopIndex2 == userCount) break;
                partnerUsersVec = (uint *)partner[4];
              } while( true );
            }
            arena = *(undefined4 *)(program + 8);
            sourceDef = IRInst__getOperandSource(partner,partner[0x21]);
            sourceUsersVec = *(uint **)(sourceDef + 0x10);
            userCount = sourceUsersVec[1];
            if (0 < (int)userCount) {
              loopIndex = 0;
              do {
                if (loopIndex < *sourceUsersVec) {
                  if (userCount <= loopIndex) {
                    _memset(userCount * 4 + sourceUsersVec[2],0,(loopIndex - userCount) * 4 + 4);
                    sourceUsersVec[1] = loopIndex + 1;
                  }
                  sourceUserEntry = (int *)(loopIndex * 4 + sourceUsersVec[2]);
                }
                else {
                  sourceUserEntry = (int *)Vector__elementRefGrow(sourceUsersVec,loopIndex);
                }
                if (partner == (int *)*sourceUserEntry) {
                  Vector__removeAt(sourceUsersVec,loopIndex);
                  sourceDef = IRInst__getOperandSource(partner,partner[0x21]);
                  *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
                  break;
                }
                userCount = sourceUsersVec[1];
                loopIndex = loopIndex + 1;
              } while ((int)loopIndex < (int)userCount);
            }
            IRInst__setOperandSource(partner,partner[0x21],0,1,arena);
            partner[0x21] = partner[0x21] + -1;
            partner[5] = partner[5] & 0xfffffdff;
          }
          else {
            loopIndex3 = 0;
            operandRecord = IRInst__getOperandRecord(inst,inst[0x21]);
            extraSelectWord[0] = *(int *)(operandRecord + 0x10);
            do {
              operandRecord = IRInst__getOperandRecord(inst,0);
              if (*(char *)(loopIndex3 + operandRecord + 0x10) != '\x01') {
                *(undefined1 *)((int)extraSelectWord + loopIndex3) = 4;
              }
              moreComponents = loopIndex3 != 3;
              loopIndex3 = loopIndex3 + 1;
            } while (moreComponents);
            arena = *(undefined4 *)(program + 8);
            sourceDef = IRInst__getOperandSource(inst,inst[0x21]);
            sourceUsersVec = *(uint **)(sourceDef + 0x10);
            userCount = sourceUsersVec[1];
            if (0 < (int)userCount) {
              loopIndex = 0;
              do {
                if (loopIndex < *sourceUsersVec) {
                  if (userCount <= loopIndex) {
                    _memset(userCount * 4 + sourceUsersVec[2],0,(loopIndex - userCount) * 4 + 4);
                    sourceUsersVec[1] = loopIndex + 1;
                  }
                  sourceUserEntry = (int *)(loopIndex * 4 + sourceUsersVec[2]);
                }
                else {
                  sourceUserEntry = (int *)Vector__elementRefGrow(sourceUsersVec,loopIndex);
                }
                if (inst == (int *)*sourceUserEntry) {
                  Vector__removeAt(sourceUsersVec,loopIndex);
                  sourceDef = IRInst__getOperandSource(inst,inst[0x21]);
                  *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
                  break;
                }
                userCount = sourceUsersVec[1];
                loopIndex = loopIndex + 1;
              } while ((int)loopIndex < (int)userCount);
            }
            IRInst__setOperandSource(inst,inst[0x21],0,1,arena);
            extraSelectChanged = extraSelectWord[0] != DAT_001b0000;
            inst[0x21] = inst[0x21] + -1;
            inst[5] = inst[5] & 0xfffffdff;
            if (extraSelectChanged) {
              sourceDef4 = IRInst__getOperandSource(partner,partner[0x21]);
              IRInst__setExtraOperandSource(inst,sourceDef4,1,*(undefined4 *)(program + 8));
              extraSelectSaved = extraSelectWord[0];
              if (inst[0x21] == 0) {
                inst[0x27] = extraSelectWord[0];
              }
              else {
                operandRecord2 = IRInst__getOperandRecord(inst,inst[0x21]);
                *(int *)(operandRecord2 + 0x10) = extraSelectSaved;
              }
            }
          }
        }
        else {
          arena = *(undefined4 *)(program + 8);
          sourceDef = IRInst__getOperandSource(inst,inst[0x21]);
          sourceUsersVec = *(uint **)(sourceDef + 0x10);
          userCount = sourceUsersVec[1];
          if (0 < (int)userCount) {
            loopIndex = 0;
            do {
              if (loopIndex < *sourceUsersVec) {
                if (userCount <= loopIndex) {
                  _memset(userCount * 4 + sourceUsersVec[2],0,(loopIndex - userCount) * 4 + 4);
                  sourceUsersVec[1] = loopIndex + 1;
                }
                sourceUserEntry = (int *)(loopIndex * 4 + sourceUsersVec[2]);
              }
              else {
                sourceUserEntry = (int *)Vector__elementRefGrow(sourceUsersVec,loopIndex);
              }
              if (inst == (int *)*sourceUserEntry) {
                Vector__removeAt(sourceUsersVec,loopIndex);
                sourceDef = IRInst__getOperandSource(inst,inst[0x21]);
                *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
                break;
              }
              userCount = sourceUsersVec[1];
              loopIndex = loopIndex + 1;
            } while ((int)loopIndex < (int)userCount);
          }
          IRInst__setOperandSource(inst,inst[0x21],0,1,arena);
          inst[0x21] = inst[0x21] + -1;
          inst[5] = inst[5] & 0xfffffdff;
        }
        if (*(int *)(partner[4] + 4) == 0) {
          (**(code **)(*partner + 0xc))(partner,1,*(undefined4 *)(program + 8));
        }
        if (partnerFlag400000Clear == false) {
          inst[5] = inst[5] | 0x400000;
          return false;
        }
        return partnerFlag400000Clear;
      }
    }
  }
  return false;
}

/* FUN_0013fc38 @ 0x13fc38 (4516 bytes) */
int FUN_0013fc38(pass)
  int pass;
{
  int *unsharedAWrapper;
  undefined4 arenaAt378;
  undefined4 storedSelectSecond;
  undefined4 storedSelectFirst;
  undefined4 vectorData2;
  int nextBlock;
  int operandRecord2;
  int firstInst;
  int maskByteOffset;
  int existingCandidate;
  int destSelect;
  int destRecord;
  int *secondInstUser;
  int *secondInst;
  int *firstCandidateSlot;
  int *blockInst;
  int *userSlotPtrB;
  int *cloneInst;
  int *laterSlotPtr;
  int *firstSlotPtr;
  int *nextBlockInst;
  int *userInstB;
  uint candidateCountScan;
  uint userCountI;
  uint userCountH;
  uint firstCompactLane;
  uint userCountG;
  uint laneIdxF;
  uint userCountF;
  uint laneIdxE;
  uint laneIdxD;
  uint freeLaneMask;
  uint pairScanIdx;
  uint pushCountB;
  uint pushCount;
  uint remappedComponent;
  uint userCountB;
  uint userTopIndexB;
  uint userTopIndex;
  uint maskA;
  uint candidateIdx;
  uint nextFreeLane;
  int userByteOffsetB;
  int userByteOffset;
  int operandIdxB;
  int cloneOperandIdx;
  int cloneDestRecord;
  int cloneOperandRecord;
  int lastOperandRecordB;
  int lastOperandRecord;
  int lastOperandIdx;
  int sourceDef;
  int destRecordC;
  int lanesLeft;
  int destRecordB;
  int predicateResult;
  int isWrappedSecond;
  int isWrappedFirst;
  int nextByteOffset;
  int operandIdx;
  int canMergeResult;
  uint *firstInstUsers;
  uint *secondInstUsers;
  uint *userVec;
  undefined4 *elementPtr;
  int secondMaskLaneCount;
  int userSource;
  int userOperandCountB;
  int laneIdxC;
  int userOperandCount;
  int rewrittenLaneCount;
  int cloneField;
  int srcModeSecond2;
  uint secondCandidateMask;
  undefined4 candidateMask;
  undefined4 vectorData;
  undefined4 arena;
  undefined4 zeroArg;
  bool pastLastCandidate;
  uint loopIndexD;
  uint loopIndexB;
  int loopIndex;
  bool moreComponents;
  int operandRecord3;
  undefined4 *vectorAlloc2;
  int *operandVReg3;
  char destSelectLastByte;
  bool sameSrc1Src2;
  bool sameSrc2Src2;
  int splitRgbAlphaEnabled;
  undefined4 *allocation;
  undefined4 *vectorAlloc;
  uint *maskElementPtr;
  undefined4 *laneMapPtr;
  int operandCount;
  int userOperandIdxB;
  int userOperandIdx;
  int operandRecordE;
  int operandRecordD;
  int operandRecordC;
  int operandCountC;
  int sourceDefB;
  int operandCountB;
  int regKindWord;
  int srcModeFirst1;
  int firstMaskLaneCount;
  int sourceDef2;
  int *unsharedBSource;
  int *operandVReg;
  int *operandVReg2;
  uint candidateCountB;
  undefined4 *userSlotPtr;
  bool sameSrc1Src1;
  int srcModeSecond1;
  bool sameSrc2Src1;
  int srcModeFirst2;
  uint chosenLane;
  int currentBlock;
  uint nextCandidateIndex;
  uint *candidateVecHeader;
  uint candidateCount;
  int *unsharedBWrapper;
  undefined4 operandSelect;
  uint secondCandidateIndex;
  undefined4 sourceToCompactLane;
  uint compactToSourceLane;
  undefined4 destSelectWord;
  undefined4 operandSelectWord;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/uVar34) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_78_buf [0x10];
  #define vecCapacity (*(uint *)(local_78_buf + 0x00))
  #define vecCount (*(uint *)(local_78_buf + 0x04))
  #define vecData (*(int *)(local_78_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_78_buf + 0x0c))
  undefined4 scratchVecCapacity;
  undefined4 scratchVecCount;
  undefined4 scratchVecData;
  undefined4 scratchVecArena;
  undefined4 foldedSelectFirst;
  undefined4 foldedSelectSecond [3];
  
  splitRgbAlphaEnabled = Compiler__isOptionEnabled(*(undefined4 *)(pass + 8),0x30);
  arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  candidateVecHeader = allocation + 1;
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
  *vectorAlloc = arena;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arena;
  vectorAlloc[2] = 0;
  vectorData = Arena__alloc(arena,8);
  vectorAlloc[3] = vectorData;
  vecArena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  scratchVecArena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  scratchVecCount = 0;
  scratchVecCapacity = 2;
  scratchVecData = Arena__alloc(scratchVecArena,8);
  currentBlock = *(int *)(pass + 900);
  nextBlock = *(int *)(currentBlock + 8);
  do {
    if (nextBlock == 0) {
      Arena__free(scratchVecArena,scratchVecData);
      Arena__free(vecArena,vecData);
      return;
    }
    allocation[2] = 0;
    vectorAlloc[2] = 0;
    scratchVecCount = 0;
    vecCount = 0;
    blockInst = *(int **)(currentBlock + 0x98);
    for (nextBlockInst = (int *)(*(int **)(currentBlock + 0x98))[2]; nextBlockInst != (int *)0x0;
        nextBlockInst = (int *)nextBlockInst[2]) {
      if ((blockInst[5] & 1U) != 0) {
        destRecord = IRInst__getOperandRecord(blockInst,0);
        destSelect = *(int *)(destRecord + 0x10);
        if (((*(int *)(blockInst[0x22] + 8) == 0x12) &&
            (canMergeResult = ((int (*)())FUN_0013f3d4)(blockInst,pass), canMergeResult != 0)) && (destSelect != 0x1010101)) {
          if (splitRgbAlphaEnabled == 0) {
            if (destSelect != 0) goto LAB_0013fe30;
          }
          else if ((destSelect != 0x1010100) && (destSelect != 1)) {
LAB_0013fe30:
            candidateCountScan = allocation[2];
            candidateIdx = 0;
            if (candidateCountScan != 0) {
              do {
                if (candidateIdx < *candidateVecHeader) {
                  if (candidateCountScan <= candidateIdx) {
                    _memset(candidateCountScan * 4 + allocation[3],0,(candidateIdx - candidateCountScan) * 4 + 4);
                    allocation[2] = candidateIdx + 1;
                  }
                  firstSlotPtr = (int *)(candidateIdx * 4 + allocation[3]);
                }
                else {
                  firstSlotPtr = (int *)Vector__elementRefGrow(candidateVecHeader,candidateIdx);
                }
                existingCandidate = *firstSlotPtr;
                for (operandIdx = 1; operandCount = (**(code **)(*blockInst + 0x14))(blockInst), operandIdx <= operandCount;
                    operandIdx = operandIdx + 1) {
                  sourceDef2 = IRInst__getOperandSource(blockInst,operandIdx);
                  if (existingCandidate == sourceDef2) {
                    pushCount = allocation[2];
                    if (pushCount < *candidateVecHeader) {
                      _memset(pushCount * 4 + allocation[3],0,4);
                      allocation[2] = pushCount + 1;
                      elementPtr = (undefined4 *)(pushCount * 4 + allocation[3]);
                    }
                    else {
                      elementPtr = (undefined4 *)Vector__elementRefGrow(candidateVecHeader,pushCount);
                    }
                    *elementPtr = 0;
                    if (vecCount < vecCapacity) {
                      maskByteOffset = vecCount * 4;
                      *(undefined4 *)(maskByteOffset + vecData) = 0;
                      vecCount = vecCount + 1;
                      elementPtr = (undefined4 *)(maskByteOffset + vecData);
                    }
                    else {
                      elementPtr = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
                    }
                    *elementPtr = 0;
                    goto LAB_0013ff84;
                  }
                }
                candidateCountScan = allocation[2];
                candidateIdx = candidateIdx + 1;
              } while (candidateIdx < candidateCountScan);
            }
LAB_0013ff84:
            candidateMask = ((int (*)())FUN_0013a644)(blockInst);
            pushCountB = allocation[2];
            if (pushCountB < *candidateVecHeader) {
              _memset(pushCountB * 4 + allocation[3],0,4);
              allocation[2] = pushCountB + 1;
              laterSlotPtr = (int *)(pushCountB * 4 + allocation[3]);
            }
            else {
              laterSlotPtr = (int *)Vector__elementRefGrow(candidateVecHeader,pushCountB);
            }
            *laterSlotPtr = (int)blockInst;
            if (vecCount < vecCapacity) {
              maskByteOffset = vecCount * 4;
              vecCount = vecCount + 1;
              *(undefined4 *)(maskByteOffset + vecData) = 0;
              elementPtr = (undefined4 *)(maskByteOffset + vecData);
            }
            else {
              elementPtr = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *elementPtr = candidateMask;
            nextBlockInst = (int *)blockInst[2];
            goto LAB_00140024;
          }
        }
        nextBlockInst = (int *)blockInst[2];
      }
LAB_00140024:
      blockInst = nextBlockInst;
    }
    if (allocation[2] != 0) {
      pairScanIdx = 0;
      do {
        if (pairScanIdx < vecCapacity) {
          if (vecCount <= pairScanIdx) {
            _memset(vecCount * 4 + vecData,0,(pairScanIdx - vecCount) * 4 + 4);
            vecCount = pairScanIdx + 1;
          }
          maskElementPtr = (uint *)(pairScanIdx * 4 + vecData);
        }
        else {
          maskElementPtr = (uint *)Vector__elementRefGrow(&vecCapacity,pairScanIdx);
        }
        maskA = *maskElementPtr;
        if (pairScanIdx < *candidateVecHeader) {
          candidateCount = allocation[2];
          if (candidateCount <= pairScanIdx) {
            _memset(candidateCount * 4 + allocation[3],0,(pairScanIdx - candidateCount) * 4 + 4);
            allocation[2] = pairScanIdx + 1;
            candidateCount = pairScanIdx + 1;
          }
          firstCandidateSlot = (int *)(pairScanIdx * 4 + allocation[3]);
        }
        else {
          firstCandidateSlot = (int *)Vector__elementRefGrow(candidateVecHeader,pairScanIdx);
          candidateCount = allocation[2];
        }
        nextCandidateIndex = pairScanIdx + 1;
        firstInst = *firstCandidateSlot;
        if ((firstInst != 0) && (nextCandidateIndex < candidateCount)) {
          nextByteOffset = nextCandidateIndex * 4;
          pairScanIdx = pairScanIdx + 2;
LAB_00140128:
          secondCandidateIndex = pairScanIdx - 1;
          if (secondCandidateIndex < *candidateVecHeader) {
            if (candidateCount <= secondCandidateIndex) {
              _memset(candidateCount * 4 + allocation[3],0,(secondCandidateIndex - candidateCount) * 4 + 4);
              allocation[2] = pairScanIdx;
            }
            elementPtr = (undefined4 *)(nextByteOffset + allocation[3]);
          }
          else {
            elementPtr = (undefined4 *)Vector__elementRefGrow(candidateVecHeader,secondCandidateIndex);
          }
          secondInst = (int *)*elementPtr;
          if (secondInst == (int *)0x0) goto LAB_00140d38;
          if (secondCandidateIndex < vecCapacity) {
            if (vecCount <= secondCandidateIndex) {
              _memset(vecCount * 4 + vecData,0,(secondCandidateIndex - vecCount) * 4 + 4);
              vecCount = pairScanIdx;
            }
            maskElementPtr = (uint *)(nextByteOffset + vecData);
          }
          else {
            maskElementPtr = (uint *)Vector__elementRefGrow(&vecCapacity,secondCandidateIndex);
          }
          secondCandidateMask = *maskElementPtr;
          firstMaskLaneCount = Mask__countSetBits4(maskA);
          secondMaskLaneCount = Mask__countSetBits4(secondCandidateMask);
          if (4 < firstMaskLaneCount + secondMaskLaneCount) goto LAB_00140dc4;
          operandVReg3 = (int *)IRInst__getOperandSource(firstInst,1);
          unsharedAWrapper = (int *)IRInst__getOperandSource(firstInst,2);
          operandVReg = (int *)IRInst__getOperandSource(secondInst,1);
          operandVReg2 = (int *)IRInst__getOperandSource(secondInst,2);
          srcModeFirst1 = (*(uint *)(firstInst + 0xb8) >> 1 & 1) + (*(uint *)(firstInst + 0xb8) & 1) * 2;
          srcModeSecond1 = ((uint)secondInst[0x2e] >> 1 & 1) + (secondInst[0x2e] & 1U) * 2;
          srcModeFirst2 = (*(uint *)(firstInst + 0xd0) >> 1 & 1) + (*(uint *)(firstInst + 0xd0) & 1) * 2;
          srcModeSecond2 = ((uint)secondInst[0x34] >> 1 & 1) + (secondInst[0x34] & 1U) * 2;
          if ((operandVReg3 != operandVReg) || (sameSrc1Src1 = true, srcModeFirst1 != srcModeSecond1)) {
            sameSrc1Src1 = false;
          }
          if ((operandVReg3 != operandVReg2) || (sameSrc1Src2 = true, srcModeFirst1 != srcModeSecond2)) {
            sameSrc1Src2 = false;
          }
          if ((unsharedAWrapper != operandVReg) || (sameSrc2Src1 = true, srcModeFirst2 != srcModeSecond1)) {
            sameSrc2Src1 = false;
          }
          if ((unsharedAWrapper != operandVReg2) || (sameSrc2Src2 = true, srcModeFirst2 != srcModeSecond2)) {
            sameSrc2Src2 = false;
          }
          unsharedBWrapper = operandVReg2;
          if ((((!sameSrc1Src1) && (unsharedBWrapper = operandVReg, !sameSrc1Src2)) &&
              (unsharedAWrapper = operandVReg3, unsharedBWrapper = operandVReg2, !sameSrc2Src1)) && (unsharedBWrapper = operandVReg, !sameSrc2Src2))
          goto LAB_00140dc4;
          isWrappedFirst = (**(code **)(*unsharedAWrapper + 0x60))(unsharedAWrapper);
          if (isWrappedFirst != 0) {
            unsharedAWrapper = (int *)IRInst__getOperandSource(unsharedAWrapper,1);
          }
          isWrappedSecond = (**(code **)(*unsharedBWrapper + 0x60))(unsharedBWrapper);
          if (isWrappedSecond == 0) {
            unsharedBSource = unsharedBWrapper;
            unsharedBWrapper = (int *)0x0;
          }
          else {
            unsharedBSource = (int *)IRInst__getOperandSource(unsharedBWrapper,1);
          }
          predicateResult = (**(code **)(*unsharedAWrapper + 0x48))(unsharedAWrapper);
          if ((((predicateResult == 0) && (predicateResult = (**(code **)(*unsharedBSource + 0x48))(unsharedBSource), predicateResult == 0)) &&
              ((predicateResult = (**(code **)(*unsharedAWrapper + 0x80))(unsharedAWrapper), predicateResult == 0 &&
               (predicateResult = (**(code **)(*unsharedBSource + 0x80))(unsharedBSource), predicateResult == 0)))) ||
             (predicateResult = IRInst__noUseBetween(firstInst,secondInst), predicateResult == 0)) goto LAB_00140d38;
          if (secondCandidateIndex < *candidateVecHeader) {
            candidateCountB = allocation[2];
            if (candidateCountB <= secondCandidateIndex) {
              _memset(candidateCountB * 4 + allocation[3],0,(secondCandidateIndex - candidateCountB) * 4 + 4);
              allocation[2] = pairScanIdx;
            }
            elementPtr = (undefined4 *)(secondCandidateIndex * 4 + allocation[3]);
          }
          else {
            elementPtr = (undefined4 *)Vector__elementRefGrow(candidateVecHeader,secondCandidateIndex);
          }
          *elementPtr = 0;
          IRInst__setExtraOperandSource(secondInst,firstInst,1,*(undefined4 *)(pass + 8));
          DList__unlink(secondInst);
          Block__insertInstAfter(*(undefined4 *)(firstInst + 0x158),firstInst,secondInst);
          if (unsharedBWrapper != (int *)0x0) {
            DList__unlink(unsharedBWrapper);
            Block__insertInstAfter(*(undefined4 *)(firstInst + 0x158),firstInst,unsharedBWrapper);
          }
          freeLaneMask = ~(maskA | secondCandidateMask) & 0xf;
          compactToSourceLane = 0x10203;
          sourceToCompactLane = 0x10203;
          destRecordB = IRInst__getOperandRecord(secondInst,0);
          destSelectWord = *(int *)(destRecordB + 0x10);
          destSelectLastByte = (char)destSelectWord;
          if ((maskA & secondCandidateMask) == 0) {
            *(int *)(pass + 0x278) = *(int *)(pass + 0x278) + 1;
            IRInst__setExtraOperandSource(secondInst,firstInst,1,*(undefined4 *)(pass + 8));
            operandRecord2 = IRInst__getOperandRecord(secondInst,secondInst[0x21]);
            *(undefined4 *)(operandRecord2 + 0x10) = 0x4040404;
            laneIdxD = 0;
            do {
              if (((int)maskA >> (laneIdxD & 0x3f) & 1U) != 0) {
                (**(code **)(*secondInst + 0x88))(secondInst,secondInst[0x21],laneIdxD,laneIdxD);
              }
              moreComponents = laneIdxD != 3;
              laneIdxD = laneIdxD + 1;
            } while (moreComponents);
          }
          else {
            nextFreeLane = 0;
            loopIndexD = 0;
            laneMapPtr = &sourceToCompactLane;
            *(int *)(pass + 0x278) = *(int *)(pass + 0x278) + 1;
            zeroArg = 0;
            do {
              if ((((int)(maskA & secondCandidateMask) >> (loopIndexD & 0x3f) & 1U) != 0) && ((int)nextFreeLane < 4)) {
                chosenLane = nextFreeLane;
                if (((int)freeLaneMask >> (nextFreeLane & 0x3f) & 1U) == 0) {
                  lanesLeft = 4 - nextFreeLane;
                  do {
                    nextFreeLane = nextFreeLane + 1;
                    lanesLeft = lanesLeft + -1;
                    if (lanesLeft == 0) goto LAB_001405bc;
                    chosenLane = nextFreeLane;
                  } while (((int)freeLaneMask >> (nextFreeLane & 0x3f) & 1U) == 0);
                }
                *(char *)(loopIndexD + (int)laneMapPtr) = (char)chosenLane;
                nextFreeLane = chosenLane + 1;
                *(undefined1 *)((int)&destSelectWord + loopIndexD) = 1;
                *(char *)((int)&compactToSourceLane + chosenLane) = (char)loopIndexD;
                *(undefined1 *)((int)&destSelectWord + chosenLane) = 0;
              }
LAB_001405bc:
              moreComponents = loopIndexD != 3;
              loopIndexD = loopIndexD + 1;
            } while (moreComponents);
            secondInst[0x27] = destSelectWord;
            destRecordC = IRInst__getOperandRecord(secondInst,secondInst[0x21]);
            *(undefined4 *)(destRecordC + 0x10) = 0x4040404;
            laneIdxE = 0;
            do {
              if (((int)maskA >> (laneIdxE & 0x3f) & 1U) != 0) {
                (**(code **)(*secondInst + 0x88))
                          (secondInst,secondInst[0x21],*(undefined1 *)((int)&sourceToCompactLane + laneIdxE),
                           *(undefined1 *)((int)&sourceToCompactLane + laneIdxE));
              }
              moreComponents = laneIdxE != 3;
              laneIdxE = laneIdxE + 1;
            } while (moreComponents);
            if ((destSelectLastByte == '\0') || ((char)destSelectWord != '\0')) {
              cloneInst = (int *)0x0;
            }
            else {
              laneMapPtr = *(undefined4 **)(pass + 8);
              sourceDef = IRInst__getOperandSource(secondInst,secondInst[0x21]);
              userVec = *(uint **)(sourceDef + 0x10);
              userCountF = userVec[1];
              if (0 < (int)userCountF) {
                loopIndexD = 0;
                do {
                  if (loopIndexD < *userVec) {
                    if (userCountF <= loopIndexD) {
                      _memset(userCountF * 4 + userVec[2],0,(loopIndexD - userCountF) * 4 + 4);
                      userVec[1] = loopIndexD + 1;
                    }
                    userSlotPtrB = (int *)(loopIndexD * 4 + userVec[2]);
                  }
                  else {
                    userSlotPtrB = (int *)Vector__elementRefGrow(userVec,loopIndexD);
                  }
                  if ((int *)*userSlotPtrB == secondInst) {
                    Vector__removeAt(userVec,loopIndexD);
                    sourceDef = IRInst__getOperandSource(secondInst,secondInst[0x21]);
                    *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
                    break;
                  }
                  userCountF = userVec[1];
                  loopIndexD = loopIndexD + 1;
                } while ((int)loopIndexD < (int)userCountF);
              }
              IRInst__setOperandSource(secondInst,secondInst[0x21],0,1,laneMapPtr);
              lastOperandIdx = secondInst[0x21];
              secondInst[0x21] = lastOperandIdx + -1;
              secondInst[5] = secondInst[5] & 0xfffffdff;
              lastOperandRecord = IRInst__getOperandRecord(secondInst,lastOperandIdx + -1);
              operandSelect = *(undefined4 *)(lastOperandRecord + 0x10);
              cloneInst = (int *)IRInst__clone(secondInst,*(undefined4 *)(pass + 8),0);
              arenaAt378 = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
              vectorAlloc2 = (undefined4 *)Arena__alloc(arenaAt378,0x14);
              vectorAlloc2[1] = 2;
              *vectorAlloc2 = arenaAt378;
              vectorAlloc2[2] = 0;
              vectorAlloc2[4] = arenaAt378;
              vectorData2 = Arena__alloc(arenaAt378,8);
              vectorAlloc2[3] = vectorData2;
              cloneInst[4] = (int)(vectorAlloc2 + 1);
              cloneInst[0x58] = *(int *)(*(int *)(*(int *)(pass + 8) + 0x6c4) + 0x478);
              IRInst__setExtraOperandSource(secondInst,firstInst,1,*(undefined4 *)(pass + 8));
              lastOperandRecordB = IRInst__getOperandRecord(secondInst,secondInst[0x21]);
              *(undefined4 *)(lastOperandRecordB + 0x10) = operandSelect;
              *(undefined1 *)((int)secondInst + 0x9f) = 1;
              cloneInst[0x27] = 0x1010100;
              Block__insertInstAfter(secondInst[0x56],secondInst,cloneInst);
              IRInst__setExtraOperandSource(cloneInst,secondInst,1,*(undefined4 *)(pass + 8));
              cloneOperandRecord = IRInst__getOperandRecord(cloneInst,cloneInst[0x21]);
              *(undefined4 *)(cloneOperandRecord + 0x10) = 0x4040404;
              laneIdxF = 0;
              do {
                if ((((int)secondCandidateMask >> (laneIdxF & 0x3f) & 1U) != 0) && (laneIdxF != 3)) {
                  (**(code **)(*cloneInst + 0x88))(cloneInst,cloneInst[0x21],laneIdxF,laneIdxF);
                }
                if ((((int)maskA >> (laneIdxF & 0x3f) & 1U) != 0) &&
                   (destSelectLastByte = *(char *)((int)&sourceToCompactLane + laneIdxF), destSelectLastByte != '\x03')) {
                  (**(code **)(*cloneInst + 0x88))(cloneInst,cloneInst[0x21],destSelectLastByte,destSelectLastByte);
                }
                moreComponents = laneIdxF != 3;
                laneIdxF = laneIdxF + 1;
              } while (moreComponents);
              cloneField = cloneInst[0x53];
              regKindWord = secondInst[0x26];
              cloneDestRecord = IRInst__getOperandRecord(cloneInst,0);
              *(int *)(cloneDestRecord + 0xc) = regKindWord;
              *(int *)(cloneDestRecord + 8) = cloneField;
              for (cloneOperandIdx = 1; operandCountB = (**(code **)(*cloneInst + 0x14))(cloneInst), cloneOperandIdx <= operandCountB;
                  cloneOperandIdx = cloneOperandIdx + 1) {
                sourceDefB = IRInst__getOperandSource(cloneInst,cloneOperandIdx);
                userVec = *(uint **)(sourceDefB + 0x10);
                userCountG = userVec[1];
                if (userCountG < *userVec) {
                  _memset(userCountG * 4 + userVec[2],0,4);
                  userSlotPtr = (undefined4 *)(userCountG * 4 + userVec[2]);
                  userVec[1] = userCountG + 1;
                }
                else {
                  userSlotPtr = (undefined4 *)Vector__elementRefGrow(userVec,userCountG);
                }
                *userSlotPtr = cloneInst;
              }
            }
            firstCompactLane = compactToSourceLane & 0xff;
            for (operandIdxB = 1; operandCountC = (**(code **)(*secondInst + 0x14))(secondInst), operandIdxB <= operandCountC;
                operandIdxB = operandIdxB + 1) {
              operandRecordC = IRInst__getOperandRecord(secondInst,operandIdxB);
              rewrittenLaneCount = 0;
              loopIndex = 0;
              operandSelectWord = *(undefined4 *)(operandRecordC + 0x10);
              do {
                if (*(char *)((int)&destSelectWord + loopIndex) == '\0') {
                  if ((cloneInst == (int *)0x0) || (loopIndex != 3)) {
                    rewrittenLaneCount = rewrittenLaneCount + 1;
                    (**(code **)(*secondInst + 0x88))
                              (secondInst,operandIdxB,loopIndex,
                               (uint)*(byte *)((int)&operandSelectWord +
                                              (uint)*(byte *)((int)&compactToSourceLane + loopIndex)),laneMapPtr,
                               zeroArg,(int)&sourceToCompactLane + (uint)*(byte *)((int)&compactToSourceLane + loopIndex));
                  }
                  else {
                    (**(code **)(*secondInst + 0x88))(secondInst,operandIdxB,3,4);
                    (**(code **)(*cloneInst + 0x88))
                              (cloneInst,operandIdxB,3,*(undefined1 *)((int)&operandSelectWord + firstCompactLane));
                  }
                }
                else {
                  (**(code **)(*secondInst + 0x88))(secondInst,operandIdxB,loopIndex,4);
                  if (cloneInst != (int *)0x0) {
                    (**(code **)(*cloneInst + 0x88))(cloneInst,operandIdxB,loopIndex,4);
                  }
                }
                moreComponents = loopIndex != 3;
                loopIndex = loopIndex + 1;
              } while (moreComponents);
              if (rewrittenLaneCount == 1) {
                IRInst__foldMovSourceSelect(&foldedSelectFirst,secondInst,operandIdxB,pass);
                storedSelectFirst = foldedSelectFirst;
                operandRecordD = IRInst__getOperandRecord(secondInst,operandIdxB);
                *(undefined4 *)(operandRecordD + 0x10) = storedSelectFirst;
              }
              if (cloneInst != (int *)0x0) {
                IRInst__foldMovSourceSelect(foldedSelectSecond,cloneInst,operandIdxB,pass);
                storedSelectSecond = foldedSelectSecond[0];
                operandRecordE = IRInst__getOperandRecord(cloneInst,operandIdxB);
                *(undefined4 *)(operandRecordE + 0x10) = storedSelectSecond;
              }
            }
            secondInstUsers = (uint *)secondInst[4];
            userCountH = secondInstUsers[1];
            userTopIndex = userCountH - 1;
            if (-1 < (int)userTopIndex) {
              userByteOffset = userTopIndex * 4;
              loopIndexB = 0;
              do {
                if (userTopIndex < *secondInstUsers) {
                  userCountB = secondInstUsers[1];
                  if (userCountB <= userTopIndex) {
                    _memset(userCountB * 4 + secondInstUsers[2],0,(userTopIndex - userCountB) * 4 + 4);
                    secondInstUsers[1] = userTopIndex + 1;
                  }
                  elementPtr = (undefined4 *)(userByteOffset + secondInstUsers[2]);
                }
                else {
                  elementPtr = (undefined4 *)Vector__elementRefGrow(secondInstUsers,userTopIndex);
                }
                userInstB = (int *)*elementPtr;
                userOperandIdx = 1;
LAB_00140c04:
                userOperandCount = (**(code **)(*userInstB + 0x14))(userInstB);
                if (userOperandIdx <= userOperandCount) {
                  operandVReg = (int *)IRInst__getOperandSource(userInstB,userOperandIdx);
                  if (operandVReg != secondInst) goto LAB_00140c00;
                  if (cloneInst != (int *)0x0) {
                    IRInst__setOperandSource(userInstB,userOperandIdx,cloneInst,1,*(undefined4 *)(pass + 8));
                  }
                  laneIdxC = 0;
                  do {
                    operandRecord3 = IRInst__getOperandRecord(userInstB,userOperandIdx);
                    remappedComponent = (uint)*(byte *)(laneIdxC + operandRecord3 + 0x10);
                    if (remappedComponent != 4) {
                      (**(code **)(*userInstB + 0x88))
                                (userInstB,userOperandIdx,laneIdxC,*(undefined1 *)((int)&sourceToCompactLane + remappedComponent));
                    }
                    moreComponents = laneIdxC != 3;
                    laneIdxC = laneIdxC + 1;
                  } while (moreComponents);
                }
                loopIndexB = loopIndexB + 1;
                userTopIndex = userTopIndex - 1;
                userByteOffset = userByteOffset + -4;
                if (userCountH == loopIndexB) break;
                secondInstUsers = (uint *)secondInst[4];
              } while( true );
            }
            firstInstUsers = *(uint **)(firstInst + 0x10);
            userCountI = firstInstUsers[1];
            userTopIndexB = userCountI - 1;
            if (-1 < (int)userTopIndexB) {
              userByteOffsetB = userTopIndexB * 4;
              loopIndexB = 0;
              do {
                if (userTopIndexB < *firstInstUsers) {
                  userCountB = firstInstUsers[1];
                  if (userCountB <= userTopIndexB) {
                    _memset(userCountB * 4 + firstInstUsers[2],0,(userTopIndexB - userCountB) * 4 + 4);
                    firstInstUsers[1] = userTopIndexB + 1;
                  }
                  elementPtr = (undefined4 *)(userByteOffsetB + firstInstUsers[2]);
                }
                else {
                  elementPtr = (undefined4 *)Vector__elementRefGrow(firstInstUsers,userTopIndexB);
                }
                secondInstUser = (int *)*elementPtr;
                for (userOperandIdxB = 1; userOperandCountB = (**(code **)(*secondInstUser + 0x14))(secondInstUser), userOperandIdxB <= userOperandCountB;
                    userOperandIdxB = userOperandIdxB + 1) {
                  userSource = IRInst__getOperandSource(secondInstUser,userOperandIdxB);
                  if (firstInst == userSource) {
                    if (cloneInst != (int *)0x0) {
                      IRInst__setOperandSource(secondInstUser,userOperandIdxB,cloneInst,1,*(undefined4 *)(pass + 8));
                    }
                    break;
                  }
                }
                loopIndexB = loopIndexB + 1;
                userTopIndexB = userTopIndexB - 1;
                userByteOffsetB = userByteOffsetB + -4;
                if (userCountI == loopIndexB) break;
                firstInstUsers = *(uint **)(firstInst + 0x10);
              } while( true );
            }
          }
LAB_00140d38:
          candidateCount = allocation[2];
        }
LAB_00140d3c:
        pairScanIdx = nextCandidateIndex;
      } while (nextCandidateIndex < candidateCount);
    }
    currentBlock = *(int *)(currentBlock + 8);
    nextBlock = *(int *)(currentBlock + 8);
  } while( true );
LAB_00140dc4:
  candidateCount = allocation[2];
  nextByteOffset = nextByteOffset + 4;
  pastLastCandidate = candidateCount <= pairScanIdx;
  pairScanIdx = pairScanIdx + 1;
  if (pastLastCandidate) goto LAB_00140d3c;
  goto LAB_00140128;
LAB_00140c00:
  userOperandIdx = userOperandIdx + 1;
  goto LAB_00140c04;
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* FUN_00140e5c @ 0x140e5c (20 bytes) */
int FUN_00140e5c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

/* FUN_00140e70 @ 0x140e70 (12 bytes) */
int FUN_00140e70(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  *param_1 = *(undefined4 *)(param_3 + 0xc);
  return;
}

/* FUN_00140e7c @ 0x140e7c (456 bytes) */
int FUN_00140e7c(param_1, param_2, param_3)
  undefined4 *param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  
  if ((((((*(int *)(param_2[0x22] + 8) == *(int *)(param_3[0x22] + 8)) &&
         (iVar1 = OpcodeTraits__flag1WithoutFlag7(*param_1,param_2), iVar1 != 0)) &&
        (iVar1 = (**(code **)(*param_2 + 100))(param_2), iVar1 == 0)) &&
       ((param_2[0x20] != 0 && (iVar1 = RegKind__flagBit0(param_2[0x26]), iVar1 != 0)))) &&
      (((param_2[5] & 2U) == 0 &&
       ((iVar1 = (**(code **)(*param_2 + 0x50))(param_2), iVar1 == 0 && (param_3[0x20] != 0)))))) &&
     ((iVar1 = RegKind__flagBit0(param_3[0x26]), iVar1 != 0 &&
      (((((param_3[5] & 2U) == 0 && (iVar1 = (**(code **)(*param_3 + 0x50))(param_3), iVar1 == 0))
        && (param_2[0x48] == param_3[0x48])) && (param_2[0x49] == param_3[0x49])))))) {
    iVar1 = param_2[0x21];
    if ((param_2[5] & 0x200U) != 0) {
      iVar1 = iVar1 + -1;
    }
    if (iVar1 < 1) {
      return 1;
    }
    if (((param_3[0x2e] & 1U) == (param_2[0x2e] & 1U)) &&
       (iVar2 = 1, ((uint)param_2[0x2e] >> 1 & 1) == ((uint)param_3[0x2e] >> 1 & 1))) {
      do {
        iVar2 = iVar2 + 1;
        if (iVar1 < iVar2) {
          return 1;
        }
      } while (((param_3[iVar2 * 6 + 0x28] & 1U) == (param_2[iVar2 * 6 + 0x28] & 1U)) &&
              (((uint)param_3[iVar2 * 6 + 0x28] >> 1 & 1) ==
               ((uint)param_2[iVar2 * 6 + 0x28] >> 1 & 1)));
    }
  }
  return 0;
}

/* FUN_00141044 @ 0x141044 (76 bytes) */
int FUN_00141044(param_1, param_2, inst)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 inst;
{
  int operandRecord;
  undefined4 local_18 [3];
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  WriteMask__fromSelectWord(local_18,*(undefined4 *)(operandRecord + 0x10));
  *param_1 = local_18[0];
  return param_1;
}

/* FUN_00141090 @ 0x141090 (112 bytes) */
int FUN_00141090(param_1, param_2, inst)
  uint *param_1;
  undefined4 param_2;
  undefined4 inst;
{
  uint local_28;
  uint local_24 [4];
  
  ((int (*)())FUN_00140e70)(&local_28,param_2,inst);
  ((int (*)())FUN_00141044)(local_24,param_2,inst);
  local_24[0] = ~local_24[0];
  *param_1 = local_28 &
             (local_24[0] << 0x18 | (local_24[0] & 0xff00) << 8 | local_24[0] >> 8 & 0xff00 |
             local_24[0] >> 0x18);
  return param_1;
}

/* FUN_00141100 @ 0x141100 (220 bytes) */
int FUN_00141100(param_1, inst, param_3, inst2, param_5)
  undefined4 param_1;
  int inst;
  int param_3;
  undefined4 inst2;
  int param_5;
{
  int operandRecord;
  int sourceDef;
  int operandVReg;
  int iVar3;
  int loopIndex;
  undefined4 operandSelect;
  undefined4 local_44 [8];
  
  ((int (*)())FUN_00140e7c)(param_1,inst,inst2);
  iVar3 = *(int *)(inst + 0x84);
  if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
    iVar3 = iVar3 + -1;
  }
  if (0 < iVar3) {
    loopIndex = 1;
    do {
      sourceDef = IRInst__getOperandSource(inst,loopIndex);
      operandVReg = IRInst__getOperandSource(inst2,loopIndex);
      if (sourceDef != operandVReg) {
        return 0;
      }
      operandRecord = IRInst__getOperandRecord(inst,loopIndex);
      operandSelect = *(undefined4 *)(operandRecord + 0x10);
      operandRecord = IRInst__getOperandRecord(inst2,loopIndex);
      local_44[0] = *(undefined4 *)(operandRecord + 0x10);
      if (*(char *)((int)local_44 + param_3 + -4) != *(char *)((int)local_44 + param_5)) {
        return 0;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex <= iVar3);
  }
  return 1;
}

/* FUN_001411dc @ 0x1411dc (636 bytes) */
int FUN_001411dc(pass, inst, inst2, laneMap)
  undefined4 *pass;
  int inst;
  int inst2;
  undefined4 laneMap;
{
  int operandIdx;
  undefined4 operandSelect;
  int operandRecordB;
  int operandRecord;
  int loopIndexB;
  int countdownB;
  int countdown;
  int loopIndex;
  unsigned int ghidra_home[8] = { pass, inst, inst2, laneMap, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool sameInst;
  undefined4 selectWordToStore;
  int normalOperandCount;
  byte *laneMapCursor;
  byte *laneMapBase;
  int lastOperandIndex;
  int nextOperandIdx;
  int countdownC;
  undefined4 operandSelectB;
  undefined4 instWriteMask;
  undefined4 inst2WriteMask;
  undefined4 operandSelectScratch;
  undefined4 instOperandSelect;
  undefined4 newDestSelect [7];
  
  sameInst = inst == inst2;
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = laneMap;
  OpcodeTraits__flag1WithoutFlag7(*pass,inst);
  OpcodeTraits__flag1WithoutFlag7(*pass,inst2);
  operandRecord = IRInst__getOperandRecord(inst,0);
  newDestSelect[0] = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst2,0);
  operandSelectB = *(undefined4 *)(operandRecord + 0x10);
  if (sameInst) {
    newDestSelect[0] = DAT_001b0044;
  }
  laneMapBase = (byte *)&(*(unsigned int *)((unsigned char *)ghidra_home + 12));
  countdown = 4;
  loopIndex = 0;
  laneMapCursor = laneMapBase;
  do {
    if (*(char *)((int)&operandSelectB + loopIndex) != '\x01') {
      *(char *)((int)newDestSelect + (uint)*laneMapCursor) = *(char *)((int)&operandSelectB + loopIndex);
    }
    loopIndex = loopIndex + 1;
    laneMapCursor = laneMapCursor + 1;
    countdown = countdown + -1;
  } while (countdown != 0);
  *(undefined4 *)(inst + 0x9c) = newDestSelect[0];
  lastOperandIndex = *(int *)(inst2 + 0x84);
  normalOperandCount = lastOperandIndex;
  if ((*(uint *)(inst2 + 0x14) & 0x200) != 0) {
    operandRecord = IRInst__getOperandRecord(inst,lastOperandIndex);
    operandSelectScratch = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(inst2,lastOperandIndex);
    operandSelect = *(undefined4 *)(operandRecord + 0x10);
    if (sameInst) {
      operandSelectScratch = DAT_001b0038;
    }
    loopIndex = 0;
    countdownB = 4;
    laneMapCursor = laneMapBase;
    do {
      if (*(char *)((int)newDestSelect + loopIndex + -4) != '\x04') {
        *(byte *)((int)&operandSelectScratch + (uint)*laneMapCursor) = *laneMapCursor;
      }
      selectWordToStore = operandSelectScratch;
      loopIndex = loopIndex + 1;
      laneMapCursor = laneMapCursor + 1;
      countdownB = countdownB + -1;
    } while (countdownB != 0);
    normalOperandCount = lastOperandIndex + -1;
    lastOperandIndex = IRInst__getOperandRecord(inst,lastOperandIndex);
    *(undefined4 *)(lastOperandIndex + 0x10) = selectWordToStore;
  }
  if (0 < normalOperandCount) {
    operandIdx = 1;
    do {
      operandRecordB = IRInst__getOperandRecord(inst,operandIdx);
      instOperandSelect = *(undefined4 *)(operandRecordB + 0x10);
      operandRecordB = IRInst__getOperandRecord(inst2,operandIdx);
      operandSelectScratch = *(undefined4 *)(operandRecordB + 0x10);
      if (sameInst) {
        instOperandSelect = DAT_001b0038;
      }
      loopIndexB = 0;
      countdownC = 4;
      laneMapCursor = laneMapBase;
      do {
        if (*(char *)((int)&operandSelectB + loopIndexB) != '\x01') {
          *(undefined1 *)((int)newDestSelect + (*laneMapCursor - 4)) = *(undefined1 *)((int)&operandSelectScratch + loopIndexB);
        }
        selectWordToStore = instOperandSelect;
        loopIndexB = loopIndexB + 1;
        laneMapCursor = laneMapCursor + 1;
        countdownC = countdownC + -1;
      } while (countdownC != 0);
      nextOperandIdx = operandIdx + 1;
      operandIdx = IRInst__getOperandRecord(inst,operandIdx);
      *(undefined4 *)(operandIdx + 0x10) = selectWordToStore;
      operandIdx = nextOperandIdx;
    } while (nextOperandIdx <= normalOperandCount);
  }
  inst2WriteMask = *(undefined4 *)(inst2 + 0xc);
  instWriteMask = *(undefined4 *)(inst + 0xc);
  if (sameInst) {
    instWriteMask = DAT_001b0040;
  }
  countdown = 4;
  loopIndex = 0;
  do {
    if (*(char *)((int)&inst2WriteMask + loopIndex) != '\0') {
      *(undefined1 *)((int)&instWriteMask + (uint)*laneMapBase) = 1;
    }
    loopIndex = loopIndex + 1;
    laneMapBase = laneMapBase + 1;
    countdown = countdown + -1;
  } while (countdown != 0);
  *(undefined4 *)(inst + 0xc) = instWriteMask;
  return;
}

/* FUN_00141458 @ 0x141458 (332 bytes) */
int FUN_00141458(param_1, inst, param_3, param_4)
  undefined4 *param_1;
  int inst;
  int param_3;
  int param_4;
{
  int operandRecord3;
  int operandRecord2;
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int operandRecord;
  int iVar6;
  int iVar7;
  undefined4 operandSelect;
  undefined4 local_44 [8];
  
  OpcodeTraits__flag1WithoutFlag7(*param_1,inst);
  operandRecord2 = IRInst__getOperandRecord(inst,0);
  operandSelect = *(undefined4 *)(operandRecord2 + 0x10);
  uVar3 = *(uint *)(inst + 0x14);
  uVar1 = *(undefined1 *)((int)local_44 + param_3 + -4);
  *(undefined1 *)((int)local_44 + param_3 + -4) = *(undefined1 *)((int)local_44 + param_4 + -4);
  *(undefined1 *)((int)local_44 + param_4 + -4) = uVar1;
  iVar6 = *(int *)(inst + 0x84);
  *(undefined4 *)(inst + 0x9c) = operandSelect;
  iVar4 = iVar6;
  if ((uVar3 & 0x200) != 0) {
    operandRecord2 = IRInst__getOperandRecord(inst,iVar6);
    local_44[0] = *(undefined4 *)(operandRecord2 + 0x10);
    uVar1 = *(undefined1 *)((int)local_44 + param_3);
    *(undefined1 *)((int)local_44 + param_3) = *(undefined1 *)((int)local_44 + param_4);
    *(undefined1 *)((int)local_44 + param_4) = uVar1;
    if (*(char *)((int)local_44 + param_3) != '\x04') {
      *(char *)((int)local_44 + param_3) = (char)param_3;
    }
    if (*(char *)((int)local_44 + param_4) != '\x04') {
      *(char *)((int)local_44 + param_4) = (char)param_4;
    }
    uVar2 = local_44[0];
    iVar4 = iVar6 + -1;
    operandRecord3 = IRInst__getOperandRecord(inst,iVar6);
    *(undefined4 *)(operandRecord3 + 0x10) = uVar2;
  }
  if (0 < iVar4) {
    iVar6 = 1;
    do {
      operandRecord = IRInst__getOperandRecord(inst,iVar6);
      iVar7 = iVar6 + 1;
      local_44[0] = *(undefined4 *)(operandRecord + 0x10);
      uVar1 = *(undefined1 *)((int)local_44 + param_3);
      *(undefined1 *)((int)local_44 + param_3) = *(undefined1 *)((int)local_44 + param_4);
      *(undefined1 *)((int)local_44 + param_4) = uVar1;
      uVar2 = local_44[0];
      operandRecord3 = IRInst__getOperandRecord(inst,iVar6);
      *(undefined4 *)(operandRecord3 + 0x10) = uVar2;
      iVar6 = iVar7;
    } while (iVar7 <= iVar4);
  }
  uVar1 = *(undefined1 *)(inst + param_3 + 0xc);
  *(undefined1 *)(inst + param_3 + 0xc) = *(undefined1 *)(inst + param_4 + 0xc);
  *(undefined1 *)(inst + param_4 + 0xc) = uVar1;
  return;
}

/* FUN_001415a4 @ 0x1415a4 (272 bytes) */
int FUN_001415a4(param_1, param_2, newSource)
  undefined4 *param_1;
  int *param_2;
  undefined4 newSource;
{
  int loopIndex;
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  while (piVar1 = (int *)param_2[4], piVar1[1] != 0) {
    if (*piVar1 == 0) {
      piVar1 = (int *)Vector__elementRefGrow(piVar1,0);
    }
    else {
      piVar1 = (int *)piVar1[2];
    }
    iVar2 = *piVar1;
    iVar3 = *(int *)(iVar2 + 0x84);
    iVar4 = iVar3;
    if ((*(uint *)(iVar2 + 0x14) & 0x200) != 0) {
      iVar4 = iVar3 + -1;
      piVar1 = (int *)IRInst__getOperandSource(iVar2,iVar3);
      if (param_2 == piVar1) {
        IRInst__setExtraOperandSource(iVar2,newSource,1,*param_1);
      }
    }
    if (0 < iVar4) {
      loopIndex = 1;
      do {
        piVar1 = (int *)IRInst__getOperandSource(iVar2,loopIndex);
        if (param_2 == piVar1) {
          IRInst__setOperandSource(iVar2,loopIndex,newSource,1,*param_1);
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= iVar4);
    }
  }
  *(int *)(param_1[1] + 0x1b4) = *(int *)(param_1[1] + 0x1b4) + 1;
                    
                    
  (**(code **)(*param_2 + 0xc))(param_2,1,*param_1);
  return;
}

/* FUN_001416b4 @ 0x1416b4 (508 bytes) */
int FUN_001416b4(param_1, inst, inst2, param_4)
  undefined4 param_1;
  int inst;
  int inst2;
  int param_4;
{
  int isBeforeOrSameResultB;
  int isBeforeOrSameResult;
  int operandIndex;
  int sourceDef;
  int loopIndex;
  int iVar1;
  int operandVReg;
  undefined4 operandVReg2;
  uint vectorFilledCount;
  int *piVar5;
  int iVar6;
  uint loopIndex2;
  uint *puVar8;
  
  isBeforeOrSameResult = Inst__isBeforeOrSame(inst,inst2);
  if (isBeforeOrSameResult == 0) {
    isBeforeOrSameResult = Inst__isBeforeOrSame(inst2,inst);
    if (isBeforeOrSameResult == 0) {
      return 0;
    }
    iVar6 = *(int *)(inst + 0x84);
    iVar1 = iVar6;
    if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
      iVar1 = iVar6 + -1;
      sourceDef = IRInst__getOperandSource(inst,iVar6);
      if ((param_4 != 0) && (inst2 == sourceDef)) {
        return 0;
      }
    }
    if (0 < iVar1) {
      loopIndex = 1;
      do {
        operandVReg = IRInst__getOperandSource(inst,loopIndex);
        if (inst2 == operandVReg) {
          return 0;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= iVar1);
    }
    puVar8 = *(uint **)(inst2 + 0x10);
    vectorFilledCount = puVar8[1];
    if (vectorFilledCount != 0) {
      loopIndex2 = 0;
      do {
        if (loopIndex2 < *puVar8) {
          if (vectorFilledCount <= loopIndex2) {
            _memset(vectorFilledCount * 4 + puVar8[2],0,(loopIndex2 - vectorFilledCount) * 4 + 4);
            puVar8[1] = loopIndex2 + 1;
          }
          piVar5 = (int *)(loopIndex2 * 4 + puVar8[2]);
        }
        else {
          piVar5 = (int *)Vector__elementRefGrow(puVar8,loopIndex2);
        }
        if ((*piVar5 != 0) && (iVar1 = Inst__isBeforeOrSame(inst,*piVar5), iVar1 == 0)) {
          return 0;
        }
        puVar8 = *(uint **)(inst2 + 0x10);
        loopIndex2 = loopIndex2 + 1;
        vectorFilledCount = puVar8[1];
      } while (loopIndex2 < vectorFilledCount);
    }
  }
  else {
    iVar6 = *(int *)(inst2 + 0x84);
    iVar1 = iVar6;
    if ((*(uint *)(inst2 + 0x14) & 0x200) != 0) {
      iVar1 = iVar6 + -1;
      sourceDef = IRInst__getOperandSource(inst2,iVar6);
      if ((param_4 != 0) && (inst == sourceDef)) {
        return 0;
      }
    }
    if (0 < iVar1) {
      loopIndex = 1;
      do {
        operandVReg = IRInst__getOperandSource(inst2,loopIndex);
        if (inst == operandVReg) {
          return 0;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= iVar1);
    }
    if (0 < *(int *)(inst2 + 0x84)) {
      operandIndex = 1;
      do {
        operandVReg2 = IRInst__getOperandSource(inst2,operandIndex);
        isBeforeOrSameResultB = Inst__isBeforeOrSame(operandVReg2,inst);
        if (isBeforeOrSameResultB == 0) {
          return 0;
        }
        operandIndex = operandIndex + 1;
      } while (operandIndex <= *(int *)(inst2 + 0x84));
    }
  }
  return 1;
}

/* PostPack__canPairInEitherOrder @ 0x1418b0 (128 bytes) */
int PostPack__canPairInEitherOrder(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  int callResult;
  undefined4 uVar2;
  
  callResult = ((int (*)())FUN_001416b4)(param_1,param_2,param_3,0);
  if (callResult == 0) {
    callResult = ((int (*)())FUN_001416b4)(param_1,param_3,param_2,0);
    uVar2 = 0;
    if (callResult != 0) {
      uVar2 = 1;
      *param_4 = 1;
    }
  }
  else {
    uVar2 = 1;
    *param_4 = 0;
  }
  return uVar2;
}

/* FUN_00141930 @ 0x141930 (3700 bytes) */
int FUN_00141930(packState, inst, inst2, resultList)
  int packState;
  int *inst;
  int *inst2;
  int *resultList;
{
  int *newEntry;
  int *scanEntry2;
  byte *entryComponentPtr;
  byte *componentCmpPtr;
  byte *componentSortPtr;
  byte *sourceScanPtrB;
  byte *sourceScanPtr;
  byte *sourceSlotPtr;
  int resultCount;
  int entryData;
  int operandCursor;
  int firstResult;
  int resultCountB;
  uint grownCapacity;
  uint newSize;
  uint otherComponentB;
  uint grownCapacityB;
  uint entryCount;
  uint laneIndex;
  int *laneEntryPtrB;
  int *laneEntryPtr;
  int *resultPtr;
  int copyOffset;
  int vcall60ResultB;
  int vcall60Result;
  uint loopIndexG;
  uint loopIndexF;
  uint loopIndexE;
  int countdownF;
  int countdownE;
  int countdownD;
  int loopIndexD;
  int loopIndexC;
  int countdownC;
  int countdownB;
  int loopIndexB;
  int countdown;
  byte loopIndex;
  bool moreComponentsB;
  bool isLast;
  bool moreComponents;
  int operandRecord;
  int operandRecord2;
  int *operandVReg;
  int *operandVReg2;
  int *operandVReg3;
  bool sourceAPlaced;
  bool sourceBPlaced;
  byte candidateComponent;
  int *entrySlotPtr;
  int *scanEntry;
  int entryDataB;
  uint componentValue;
  undefined4 allocation;
  int copyDest;
  int byteOffsetC;
  int *laneSourceCursor;
  int *laneEntryCursorD;
  int copySrcOffset;
  int copyDestB;
  int byteOffsetE;
  int copySrc;
  byte *componentPtr;
  int *tableSource;
  byte *componentScanPtr;
  int *sourceCursorA;
  int *recordClearCursor;
  int *sourcePtrC;
  int *candidateSource;
  int *componentClearCursor;
  int *sourcePtrB;
  byte *sourceSortPtr;
  byte entryComponent;
  byte *sourceCmpPtr;
  uint newSizeB;
  uint component2;
  uint otherComponent;
  int byteOffsetF;
  undefined4 *arenaPtr;
  int operandIdx;
  int copyDestC;
  int copyDestD;
  undefined4 operandSelect;
  int entryRecord [4];
  byte entrySources [16];
  byte entryComponents [4];
  undefined4 entryPad1;
  undefined4 entryPad2;
  
  ((int (*)())FUN_00140e7c)(packState,inst,inst2);
  if (resultList != (int *)0x0) {
    countdownE = 5;
    *resultList = 0;
    resultPtr = resultList;
    do {
      resultPtr = resultPtr + 1;
      *resultPtr = 0;
      countdownE = countdownE + -1;
    } while (countdownE != 0);
  }
  operandIdx = inst[0x21];
  if ((inst[5] & 0x200U) == 0) goto LAB_001420b4;
  if ((inst2[5] & 0x200U) != 0) {
    operandVReg2 = (int *)IRInst__getOperandSource(inst,operandIdx);
    operandVReg = (int *)IRInst__getOperandSource(inst2,inst2[0x21]);
    if (((operandVReg2 != operandVReg) && (inst2 != operandVReg2)) && (inst != operandVReg)) {
      vcall60Result = (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
      if ((vcall60Result != 0) || (vcall60Result = (**(code **)(*operandVReg + 0x60))(operandVReg), vcall60Result != 0)) {
        return 0;
      }
      countdown = 4;
      loopIndex = 0;
      componentPtr = entryComponents;
      laneEntryPtrB = entryRecord;
      do {
        *componentPtr = loopIndex;
        componentPtr = componentPtr + 1;
        *laneEntryPtrB = 0;
        loopIndex = loopIndex + 1;
        laneEntryPtrB[4] = 0;
        laneEntryPtrB = laneEntryPtrB + 1;
        countdown = countdown + -1;
      } while (countdown != 0);
      operandRecord = IRInst__getOperandRecord(inst,operandIdx);
      laneIndex = 0;
      operandSelect = *(undefined4 *)(operandRecord + 0x10);
      laneEntryPtrB = entryRecord;
      componentPtr = entryComponents;
      do {
        if (*(char *)((int)entryRecord + (laneIndex - 4)) != '\x04') {
          sourceCursorA = (int *)laneEntryPtrB[4];
          if (operandVReg2 == sourceCursorA) {
            if (laneIndex == *componentPtr) {
              *laneEntryPtrB = 1;
            }
            else {
LAB_00141ae0:
              if (*laneEntryPtrB != 0) {
LAB_00141b90:
                sourceAPlaced = false;
                goto LAB_00141b94;
              }
              sourceSortPtr = entrySources;
              laneEntryPtrB[4] = (int)operandVReg2;
              component2 = (uint)*componentPtr;
              *laneEntryPtrB = 1;
              *componentPtr = (byte)laneIndex;
              sourceCmpPtr = sourceSortPtr;
              componentScanPtr = entryComponents;
              do {
                if ((sourceCursorA == *(int **)sourceCmpPtr) && (component2 == *componentScanPtr)) goto LAB_00141a9c;
                sourceCmpPtr = sourceCmpPtr + 4;
                componentScanPtr = componentScanPtr + 1;
              } while (entryComponents != sourceCmpPtr);
              countdown = 4;
              loopIndexE = 0;
              componentCmpPtr = entryComponents;
              while( true ) {
                tableSource = *(int **)sourceSortPtr;
                if (tableSource == (int *)0x0) break;
                otherComponent = (uint)*componentCmpPtr;
                if ((loopIndexE != otherComponent) &&
                   ((sourceCursorA[0x53] < tableSource[0x53] ||
                    ((tableSource[0x53] == sourceCursorA[0x53] && (component2 < otherComponent)))))) {
                  *(int **)sourceSortPtr = sourceCursorA;
                  *componentCmpPtr = (byte)component2;
                  component2 = otherComponent;
                  sourceCursorA = tableSource;
                }
                loopIndexE = loopIndexE + 1;
                sourceSortPtr = sourceSortPtr + 4;
                componentCmpPtr = componentCmpPtr + 1;
                countdown = countdown + -1;
                if (countdown == 0) goto LAB_00141b90;
              }
              entryComponents[loopIndexE] = (byte)component2;
              *(int **)(entrySources + loopIndexE * 4) = sourceCursorA;
            }
          }
          else {
            if (sourceCursorA != (int *)0x0) goto LAB_00141ae0;
            laneEntryPtrB[4] = (int)operandVReg2;
            *laneEntryPtrB = 1;
            *componentPtr = (byte)laneIndex;
          }
        }
LAB_00141a9c:
        moreComponents = laneIndex != 3;
        laneEntryPtrB = laneEntryPtrB + 1;
        componentPtr = componentPtr + 1;
        laneIndex = laneIndex + 1;
      } while (moreComponents);
      sourceAPlaced = true;
LAB_00141b94:
      operandRecord = IRInst__getOperandRecord(inst2,operandIdx);
      laneIndex = 0;
      operandSelect = *(undefined4 *)(operandRecord + 0x10);
      laneEntryPtr = entryRecord;
      componentPtr = entryComponents;
      do {
        if (*(char *)((int)entryRecord + (laneIndex - 4)) != '\x04') {
          laneSourceCursor = (int *)laneEntryPtr[4];
          if (operandVReg == laneSourceCursor) {
            if (*componentPtr == laneIndex) {
              entryRecord[laneIndex] = 1;
            }
            else {
LAB_00141bd8:
              if (*laneEntryPtr != 0) {
LAB_00141d00:
                sourceBPlaced = false;
                goto LAB_00141d04;
              }
              component2 = (uint)*componentPtr;
              sourceSortPtr = entrySources;
              *laneEntryPtr = 1;
              laneEntryPtr[4] = (int)operandVReg;
              *componentPtr = (byte)laneIndex;
              sourceCmpPtr = sourceSortPtr;
              componentScanPtr = entryComponents;
              do {
                if ((laneSourceCursor == *(int **)sourceCmpPtr) && (component2 == *componentScanPtr)) goto LAB_00141c78;
                sourceCmpPtr = sourceCmpPtr + 4;
                componentScanPtr = componentScanPtr + 1;
              } while (entryComponents != sourceCmpPtr);
              countdown = 4;
              loopIndexE = 0;
              componentCmpPtr = entryComponents;
              while( true ) {
                sourcePtrB = *(int **)sourceSortPtr;
                if (sourcePtrB == (int *)0x0) break;
                otherComponent = (uint)*componentCmpPtr;
                if ((loopIndexE != otherComponent) &&
                   ((laneSourceCursor[0x53] < sourcePtrB[0x53] ||
                    ((sourcePtrB[0x53] == laneSourceCursor[0x53] && (component2 < otherComponent)))))) {
                  *(int **)sourceSortPtr = laneSourceCursor;
                  *componentCmpPtr = (byte)component2;
                  component2 = otherComponent;
                  laneSourceCursor = sourcePtrB;
                }
                loopIndexE = loopIndexE + 1;
                sourceSortPtr = sourceSortPtr + 4;
                componentCmpPtr = componentCmpPtr + 1;
                countdown = countdown + -1;
                if (countdown == 0) goto LAB_00141d00;
              }
              entryComponents[loopIndexE] = (byte)component2;
              *(int **)(entrySources + loopIndexE * 4) = laneSourceCursor;
            }
          }
          else {
            if (laneSourceCursor != (int *)0x0) goto LAB_00141bd8;
            laneEntryPtr[4] = (int)operandVReg;
            *laneEntryPtr = 1;
            *componentPtr = (byte)laneIndex;
          }
        }
LAB_00141c78:
        moreComponentsB = laneIndex != 3;
        laneEntryPtr = laneEntryPtr + 1;
        componentPtr = componentPtr + 1;
        laneIndex = laneIndex + 1;
      } while (moreComponentsB);
      sourceBPlaced = true;
LAB_00141d04:
      if (!sourceAPlaced) {
        return 0;
      }
      if (!sourceBPlaced) {
        return 0;
      }
      arenaPtr = (undefined4 *)(packState + 0xc);
      entryCount = *(uint *)(packState + 0x10);
      if (entryCount != 0) {
        entryDataB = *(int *)(packState + 0x18);
        loopIndexE = 0;
        newSize = entryCount;
        do {
          if (newSize <= loopIndexE) {
            newSize = loopIndexE + 1;
            if (*(uint *)(packState + 0x14) < newSize) {
              grownCapacity = (*(uint *)(packState + 0x14) << 4) / 10;
              *(uint *)(packState + 0x14) = grownCapacity;
              if (grownCapacity < newSize) {
                *(uint *)(packState + 0x14) = newSize;
              }
              allocation = Arena__alloc(*arenaPtr,*(int *)(packState + 0x14) * 0x2c);
              *(undefined4 *)(packState + 0x18) = allocation;
              if (*(int *)(packState + 0x10) != 0) {
                loopIndexG = 0;
                byteOffsetF = 0;
                do {
                  copySrcOffset = byteOffsetF + entryDataB;
                  loopIndexG = loopIndexG + 1;
                  copyDest = byteOffsetF + *(int *)(packState + 0x18);
                  byteOffsetF = byteOffsetF + 0x2c;
                  _memcpy(copyDest,copySrcOffset,0x2c);
                } while (loopIndexG < *(uint *)(packState + 0x10));
              }
              Arena__free(*arenaPtr,entryDataB);
              entryDataB = *(int *)(packState + 0x18);
            }
            *(uint *)(packState + 0x10) = newSize;
          }
          entrySlotPtr = (int *)(loopIndexE * 0x2c + entryDataB);
          if (entrySlotPtr[9] != 0) {
            loopIndexD = 0;
            sourceSlotPtr = entrySources;
            do {
              if (*(int *)sourceSlotPtr != 0) {
                countdownC = 4;
                loopIndexB = 0;
                scanEntry = entrySlotPtr;
                while ((*(int *)sourceSlotPtr != scanEntry[4] ||
                       (entryComponents[loopIndexD] != *(byte *)((int)entrySlotPtr + loopIndexB + 0x20)))) {
                  loopIndexB = loopIndexB + 1;
                  scanEntry = scanEntry + 1;
                  countdownC = countdownC + -1;
                  if (countdownC == 0) goto LAB_00142744;
                }
                if ((loopIndexB == -1) ||
                   ((*(int *)(sourceSlotPtr + -0x10) != 0 && ((loopIndexB != loopIndexD || (entrySlotPtr[loopIndexB] == 0)))))
                   ) break;
              }
              isLast = loopIndexD == 3;
              sourceSlotPtr = sourceSlotPtr + 4;
              loopIndexD = loopIndexD + 1;
              if (isLast) goto LAB_00142098;
            } while( true );
          }
LAB_00142744:
          loopIndexE = loopIndexE + 1;
          if (entryCount == loopIndexE) goto LAB_00141e9c;
          newSize = *(uint *)(packState + 0x10);
        } while( true );
      }
      entryDataB = *(int *)(packState + 0x18);
      goto LAB_00141fd8;
    }
  }
  goto LAB_001420b0;
LAB_00141e9c:
  loopIndexF = 0;
  byteOffsetF = 0;
  do {
    if (*(uint *)(packState + 0x10) <= loopIndexF) {
      newSizeB = loopIndexF + 1;
      if (*(uint *)(packState + 0x14) < newSizeB) {
        grownCapacity = (*(uint *)(packState + 0x14) << 4) / 10;
        *(uint *)(packState + 0x14) = grownCapacity;
        if (grownCapacity < newSizeB) {
          *(uint *)(packState + 0x14) = newSizeB;
        }
        allocation = Arena__alloc(*arenaPtr,*(int *)(packState + 0x14) * 0x2c);
        *(undefined4 *)(packState + 0x18) = allocation;
        if (*(int *)(packState + 0x10) != 0) {
          loopIndexG = 0;
          copyOffset = 0;
          do {
            loopIndexG = loopIndexG + 1;
            _memcpy(copyOffset + *(int *)(packState + 0x18),copyOffset + entryDataB,0x2c);
            copyOffset = copyOffset + 0x2c;
          } while (loopIndexG < *(uint *)(packState + 0x10));
        }
        Arena__free(*arenaPtr,entryDataB);
        entryDataB = *(int *)(packState + 0x18);
      }
      *(uint *)(packState + 0x10) = newSizeB;
    }
    entrySlotPtr = (int *)(byteOffsetF + entryDataB);
    countdownB = 4;
    componentPtr = entryComponents;
    entryComponentPtr = (byte *)(entrySlotPtr + 8);
    scanEntry = entrySlotPtr;
    laneEntryPtrB = entryRecord;
    while ((*scanEntry == *laneEntryPtrB && (scanEntry[4] == laneEntryPtrB[4]))) {
      entryComponent = *entryComponentPtr;
      entryComponentPtr = entryComponentPtr + 1;
      candidateComponent = *componentPtr;
      componentPtr = componentPtr + 1;
      if (entryComponent != candidateComponent) break;
      scanEntry = scanEntry + 1;
      laneEntryPtrB = laneEntryPtrB + 1;
      countdownB = countdownB + -1;
      if (countdownB == 0) goto LAB_00142098;
    }
    loopIndexF = loopIndexF + 1;
    byteOffsetF = byteOffsetF + 0x2c;
  } while (entryCount != loopIndexF);
  if (*(uint *)(packState + 0x10) <= entryCount) {
LAB_00141fd8:
    newSize = entryCount + 1;
    if (*(uint *)(packState + 0x14) < newSize) {
      grownCapacityB = (*(uint *)(packState + 0x14) << 4) / 10;
      *(uint *)(packState + 0x14) = grownCapacityB;
      if (grownCapacityB < newSize) {
        *(uint *)(packState + 0x14) = newSize;
      }
      allocation = Arena__alloc(*arenaPtr,*(int *)(packState + 0x14) * 0x2c);
      *(undefined4 *)(packState + 0x18) = allocation;
      if (*(int *)(packState + 0x10) != 0) {
        loopIndexE = 0;
        byteOffsetF = 0;
        do {
          loopIndexE = loopIndexE + 1;
          _memcpy(byteOffsetF + *(int *)(packState + 0x18),byteOffsetF + entryDataB,0x2c);
          byteOffsetF = byteOffsetF + 0x2c;
        } while (loopIndexE < *(uint *)(packState + 0x10));
      }
      Arena__free(*arenaPtr,entryDataB);
      entryDataB = *(int *)(packState + 0x18);
    }
    *(uint *)(packState + 0x10) = newSize;
  }
  entrySlotPtr = (int *)(entryCount * 0x2c + entryDataB);
  entryPad1 = 0;
  entryPad2 = 0;
  _memcpy(entrySlotPtr,entryRecord,0x2c);
LAB_00142098:
  resultCountB = *resultList;
  resultList[operandIdx + 1] = (int)entrySlotPtr;
  *resultList = resultCountB + 1;
LAB_001420b0:
  operandIdx = operandIdx + -1;
LAB_001420b4:
  if (operandIdx < 1) {
LAB_001426c8:
    countdownE = 5;
    do {
      firstResult = resultList[1];
      if (firstResult != 0) {
        *(int *)(firstResult + 0x28) = *(int *)(firstResult + 0x28) + 1;
      }
      resultList = resultList + 1;
      countdownE = countdownE + -1;
    } while (countdownE != 0);
    return 1;
  }
  operandCursor = 1;
  resultPtr = resultList;
LAB_001420c4:
  operandVReg = (int *)IRInst__getOperandSource(inst,operandCursor);
  operandVReg3 = (int *)IRInst__getOperandSource(inst2,operandCursor);
  if (operandVReg != operandVReg3) {
    vcall60ResultB = (**(code **)(*operandVReg + 0x60))(operandVReg);
    if (vcall60ResultB != 0) {
      return 0;
    }
    vcall60ResultB = (**(code **)(*operandVReg3 + 0x60))(operandVReg3);
    if (vcall60ResultB != 0) {
      return 0;
    }
    countdownD = 4;
    loopIndex = 0;
    componentPtr = entryComponents;
    componentClearCursor = entryRecord;
    do {
      *componentPtr = loopIndex;
      componentPtr = componentPtr + 1;
      *componentClearCursor = 0;
      loopIndex = loopIndex + 1;
      componentClearCursor[4] = 0;
      componentClearCursor = componentClearCursor + 1;
      countdownD = countdownD + -1;
    } while (countdownD != 0);
    operandRecord2 = IRInst__getOperandRecord(inst,operandCursor);
    loopIndexB = 0;
    operandSelect = *(undefined4 *)(operandRecord2 + 0x10);
    do {
      componentValue = (uint)*(byte *)((int)entryRecord + loopIndexB + -4);
      if (componentValue != 4) {
        sourceScanPtrB = entrySources;
        componentSortPtr = entryComponents;
        countdownD = 4;
        sourceScanPtr = sourceScanPtrB;
        sourceCmpPtr = componentSortPtr;
        do {
          if ((operandVReg == *(int **)sourceScanPtr) && (componentValue == *sourceCmpPtr)) goto LAB_001421bc;
          sourceScanPtr = sourceScanPtr + 4;
          sourceCmpPtr = sourceCmpPtr + 1;
          countdownD = countdownD + -1;
        } while (countdownD != 0);
        countdownD = 4;
        loopIndexF = 0;
        candidateSource = operandVReg;
        while( true ) {
          tableSource = *(int **)sourceScanPtrB;
          if (tableSource == (int *)0x0) break;
          otherComponentB = (uint)*componentSortPtr;
          if ((loopIndexF != otherComponentB) &&
             ((candidateSource[0x53] < tableSource[0x53] ||
              ((tableSource[0x53] == candidateSource[0x53] && (componentValue < otherComponentB)))))) {
            *(int **)sourceScanPtrB = candidateSource;
            *componentSortPtr = (byte)componentValue;
            componentValue = otherComponentB;
            candidateSource = tableSource;
          }
          loopIndexF = loopIndexF + 1;
          sourceScanPtrB = sourceScanPtrB + 4;
          componentSortPtr = componentSortPtr + 1;
          countdownD = countdownD + -1;
          if (countdownD == 0) {
            sourceAPlaced = false;
            goto LAB_0014225c;
          }
        }
        entryComponents[loopIndexF] = (byte)componentValue;
        *(int **)(entrySources + loopIndexF * 4) = candidateSource;
      }
LAB_001421bc:
      moreComponents = loopIndexB != 3;
      loopIndexB = loopIndexB + 1;
    } while (moreComponents);
    sourceAPlaced = true;
LAB_0014225c:
    operandRecord2 = IRInst__getOperandRecord(inst2,operandCursor);
    loopIndexB = 0;
    operandSelect = *(undefined4 *)(operandRecord2 + 0x10);
    do {
      componentValue = (uint)*(byte *)((int)entryRecord + loopIndexB + -4);
      if (componentValue != 4) {
        sourceScanPtrB = entrySources;
        componentSortPtr = entryComponents;
        countdownD = 4;
        sourceScanPtr = sourceScanPtrB;
        sourceCmpPtr = componentSortPtr;
        do {
          if ((operandVReg3 == *(int **)sourceScanPtr) && (componentValue == *sourceCmpPtr)) goto LAB_001422b0;
          sourceScanPtr = sourceScanPtr + 4;
          sourceCmpPtr = sourceCmpPtr + 1;
          countdownD = countdownD + -1;
        } while (countdownD != 0);
        countdownD = 4;
        loopIndexF = 0;
        scanEntry2 = operandVReg3;
        while( true ) {
          sourcePtrC = *(int **)sourceScanPtrB;
          if (sourcePtrC == (int *)0x0) break;
          otherComponentB = (uint)*componentSortPtr;
          if ((loopIndexF != otherComponentB) &&
             ((scanEntry2[0x53] < sourcePtrC[0x53] || ((sourcePtrC[0x53] == scanEntry2[0x53] && (componentValue < otherComponentB)))
              ))) {
            *(int **)sourceScanPtrB = scanEntry2;
            *componentSortPtr = (byte)componentValue;
            componentValue = otherComponentB;
            scanEntry2 = sourcePtrC;
          }
          loopIndexF = loopIndexF + 1;
          sourceScanPtrB = sourceScanPtrB + 4;
          componentSortPtr = componentSortPtr + 1;
          countdownD = countdownD + -1;
          if (countdownD == 0) {
            sourceBPlaced = false;
            goto LAB_00142338;
          }
        }
        entryComponents[loopIndexF] = (byte)componentValue;
        *(int **)(entrySources + loopIndexF * 4) = scanEntry2;
      }
LAB_001422b0:
      moreComponentsB = loopIndexB != 3;
      loopIndexB = loopIndexB + 1;
    } while (moreComponentsB);
    sourceBPlaced = true;
LAB_00142338:
    if (!sourceAPlaced) {
      return 0;
    }
    if (!sourceBPlaced) {
      return 0;
    }
    arenaPtr = (undefined4 *)(packState + 0xc);
    entryCount = *(uint *)(packState + 0x10);
    if (entryCount != 0) {
      entryData = *(int *)(packState + 0x18);
      loopIndexE = 0;
      newSize = entryCount;
      do {
        if (newSize <= loopIndexE) {
          newSize = loopIndexE + 1;
          if (*(uint *)(packState + 0x14) < newSize) {
            grownCapacity = (*(uint *)(packState + 0x14) << 4) / 10;
            *(uint *)(packState + 0x14) = grownCapacity;
            if (grownCapacity < newSize) {
              *(uint *)(packState + 0x14) = newSize;
            }
            allocation = Arena__alloc(*arenaPtr,*(int *)(packState + 0x14) * 0x2c);
            *(undefined4 *)(packState + 0x18) = allocation;
            if (*(int *)(packState + 0x10) != 0) {
              loopIndexG = 0;
              copyOffset = 0;
              do {
                loopIndexG = loopIndexG + 1;
                _memcpy(*(int *)(packState + 0x18) + copyOffset,entryData + copyOffset,0x2c);
                copyOffset = copyOffset + 0x2c;
              } while (loopIndexG < *(uint *)(packState + 0x10));
            }
            Arena__free(*arenaPtr,entryData);
            entryData = *(int *)(packState + 0x18);
          }
          *(uint *)(packState + 0x10) = newSize;
        }
        newEntry = (int *)(loopIndexE * 0x2c + entryData);
        if (newEntry[9] != 0) {
          loopIndexB = 0;
          sourceSlotPtr = entrySources;
          do {
            if (*(int *)sourceSlotPtr != 0) {
              countdownF = 4;
              loopIndexC = 0;
              laneEntryCursorD = newEntry;
              while ((*(int *)sourceSlotPtr != laneEntryCursorD[4] ||
                     (entryComponents[loopIndexB] != *(byte *)((int)newEntry + loopIndexC + 0x20)))) {
                loopIndexC = loopIndexC + 1;
                laneEntryCursorD = laneEntryCursorD + 1;
                countdownF = countdownF + -1;
                if (countdownF == 0) goto LAB_00142780;
              }
              if ((loopIndexC == -1) ||
                 ((*(int *)(sourceSlotPtr + -0x10) != 0 && ((loopIndexC != loopIndexB || (newEntry[loopIndexC] == 0))))))
              break;
            }
            isLast = loopIndexB == 3;
            sourceSlotPtr = sourceSlotPtr + 4;
            loopIndexB = loopIndexB + 1;
            if (isLast) goto LAB_001426a8;
          } while( true );
        }
LAB_00142780:
        loopIndexE = loopIndexE + 1;
        if (entryCount == loopIndexE) goto LAB_001424ac;
        newSize = *(uint *)(packState + 0x10);
      } while( true );
    }
    entryData = *(int *)(packState + 0x18);
    goto LAB_001425e8;
  }
  goto LAB_001426b8;
LAB_001424ac:
  loopIndexF = 0;
  byteOffsetC = 0;
  do {
    if (*(uint *)(packState + 0x10) <= loopIndexF) {
      newSizeB = loopIndexF + 1;
      if (*(uint *)(packState + 0x14) < newSizeB) {
        grownCapacity = (*(uint *)(packState + 0x14) << 4) / 10;
        *(uint *)(packState + 0x14) = grownCapacity;
        if (grownCapacity < newSizeB) {
          *(uint *)(packState + 0x14) = newSizeB;
        }
        allocation = Arena__alloc(*arenaPtr,*(int *)(packState + 0x14) * 0x2c);
        *(undefined4 *)(packState + 0x18) = allocation;
        if (*(int *)(packState + 0x10) != 0) {
          loopIndexG = 0;
          byteOffsetE = 0;
          do {
            copySrc = byteOffsetE + entryData;
            loopIndexG = loopIndexG + 1;
            copyDestC = byteOffsetE + *(int *)(packState + 0x18);
            byteOffsetE = byteOffsetE + 0x2c;
            _memcpy(copyDestC,copySrc,0x2c);
          } while (loopIndexG < *(uint *)(packState + 0x10));
        }
        Arena__free(*arenaPtr,entryData);
        entryData = *(int *)(packState + 0x18);
      }
      *(uint *)(packState + 0x10) = newSizeB;
    }
    newEntry = (int *)(byteOffsetC + entryData);
    countdownC = 4;
    componentPtr = entryComponents;
    entryComponentPtr = (byte *)(newEntry + 8);
    laneEntryCursorD = newEntry;
    recordClearCursor = entryRecord;
    while ((*laneEntryCursorD == *recordClearCursor && (laneEntryCursorD[4] == recordClearCursor[4]))) {
      entryComponent = *entryComponentPtr;
      entryComponentPtr = entryComponentPtr + 1;
      candidateComponent = *componentPtr;
      componentPtr = componentPtr + 1;
      if (entryComponent != candidateComponent) break;
      laneEntryCursorD = laneEntryCursorD + 1;
      recordClearCursor = recordClearCursor + 1;
      countdownC = countdownC + -1;
      if (countdownC == 0) goto LAB_001426a8;
    }
    loopIndexF = loopIndexF + 1;
    byteOffsetC = byteOffsetC + 0x2c;
  } while (entryCount != loopIndexF);
  if (*(uint *)(packState + 0x10) <= entryCount) {
LAB_001425e8:
    newSize = entryCount + 1;
    if (*(uint *)(packState + 0x14) < newSize) {
      grownCapacityB = (*(uint *)(packState + 0x14) << 4) / 10;
      *(uint *)(packState + 0x14) = grownCapacityB;
      if (grownCapacityB < newSize) {
        *(uint *)(packState + 0x14) = newSize;
      }
      allocation = Arena__alloc(*arenaPtr,*(int *)(packState + 0x14) * 0x2c);
      *(undefined4 *)(packState + 0x18) = allocation;
      if (*(int *)(packState + 0x10) != 0) {
        loopIndexE = 0;
        copyOffset = 0;
        do {
          copyDestD = entryData + copyOffset;
          loopIndexE = loopIndexE + 1;
          copyDestB = *(int *)(packState + 0x18) + copyOffset;
          copyOffset = copyOffset + 0x2c;
          _memcpy(copyDestB,copyDestD,0x2c);
        } while (loopIndexE < *(uint *)(packState + 0x10));
      }
      Arena__free(*arenaPtr,entryData);
      entryData = *(int *)(packState + 0x18);
    }
    *(uint *)(packState + 0x10) = newSize;
  }
  entryPad1 = 0;
  newEntry = (int *)(entryCount * 0x2c + entryData);
  entryPad2 = 0;
  _memcpy(newEntry,entryRecord,0x2c);
LAB_001426a8:
  resultCount = *resultList;
  resultPtr[2] = (int)newEntry;
  *resultList = resultCount + 1;
LAB_001426b8:
  operandCursor = operandCursor + 1;
  resultPtr = resultPtr + 1;
  if (operandIdx < operandCursor) goto LAB_001426c8;
  goto LAB_001420c4;
}

/* FUN_001427a4 @ 0x1427a4 (464 bytes) */
int FUN_001427a4(param_1, param_2, inst)
  uint *param_1;
  undefined4 param_2;
  int *inst;
{
  int vcall5cResult;
  undefined4 *puVar2;
  int *piVar3;
  uint vectorFilledCount;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  uint loopIndex;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c [3];
  
  if ((*(int *)(inst[0x22] + 8) == 0x8e) ||
     (vcall5cResult = (**(code **)(*inst + 0x5c))(inst), vcall5cResult != 0)) {
    ((int (*)())FUN_00141044)(&local_38,param_2,inst);
    *param_1 = local_38;
  }
  else {
    puVar6 = (uint *)inst[4];
    vectorFilledCount = puVar6[1];
    uVar5 = DAT_001b0040;
    if (vectorFilledCount != 0) {
      loopIndex = 0;
      do {
        if (loopIndex < *puVar6) {
          if (vectorFilledCount <= loopIndex) {
            _memset(vectorFilledCount * 4 + puVar6[2],0,(loopIndex - vectorFilledCount) * 4 + 4);
            puVar6[1] = loopIndex + 1;
          }
          puVar2 = (undefined4 *)(loopIndex * 4 + puVar6[2]);
        }
        else {
          puVar2 = (undefined4 *)Vector__elementRefGrow(puVar6,loopIndex);
        }
        loopIndex = loopIndex + 1;
        piVar7 = (int *)*puVar2;
        if (piVar7 != (int *)0x0) {
          if ((*(int *)(piVar7[0x22] + 8) == 0x8e) ||
             (vcall5cResult = (**(code **)(*piVar7 + 0x5c))(piVar7), vcall5cResult != 0)) {
            ((int (*)())FUN_00141044)(&local_34,param_2,piVar7);
            uVar5 = uVar5 | local_34;
          }
          piVar3 = (int *)0x0;
          if ((piVar7[5] & 0x200U) != 0) {
            piVar3 = (int *)IRInst__getOperandSource(piVar7,piVar7[0x21]);
          }
          if (piVar3 == inst) {
            ((int (*)())FUN_00141090)(&local_30,param_2,piVar7);
            uVar5 = uVar5 | local_30;
          }
        }
        puVar6 = (uint *)inst[4];
        vectorFilledCount = puVar6[1];
      } while (loopIndex < vectorFilledCount);
    }
    ((int (*)())FUN_00141044)(local_2c,param_2,inst);
    *param_1 = uVar5 & local_2c[0];
  }
  return param_1;
}

/* FUN_00142974 @ 0x142974 (1532 bytes) */
int FUN_00142974(pass, inst, fromLane, toLane)
  int *pass;
  int *inst;
  int fromLane;
  int toLane;
{
  undefined4 laneMaskWord;
  uint userCountCopy;
  undefined4 *pushSlot;
  int *topSlot;
  int *user;
  int *earlierSlot;
  uint *pendingUserVec;
  uint topIndex;
  int pendingUserByteOffset;
  int earlierUser;
  int pendingInst;
  uint countBefore;
  uint userCount;
  int *userSlot;
  undefined4 *userSlotB;
  int *extraSourceOfUser;
  uint userIndexPlus1;
  int userByteOffset;
  int flag1WithoutFlag7Result;
  int iVar8;
  uint loopIndex2;
  uint loopIndex;
  uint *userVec;
  uint *userVecCopy;
  undefined4 result;
  undefined4 pendingUsedLanes;
  undefined4 pendingUserWriteMask;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_6c_buf [0x10];
  #define vecCapacity (*(uint *)(local_6c_buf + 0x00))
  #define vecCount (*(uint *)(local_6c_buf + 0x04))
  #define vecData (*(int *)(local_6c_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_6c_buf + 0x0c))
  undefined1 neededMaskDiscard [4];
  undefined4 userWriteMaskOut;
  undefined4 pendingNeededMaskOut;
  undefined4 pendingUsedLanesOut;
  undefined4 pendingUserWriteMaskOut [4];
  
  ((int (*)())FUN_001427a4)(neededMaskDiscard,pass,inst);
  if (fromLane == toLane) {
    return 1;
  }
  if ((*(int *)(inst[0x22] + 8) == 0x8e) ||
     (vecCount = (**(code **)(*inst + 0x5c))(inst), vecCount != 0)) {
    return 0;
  }
  vecArena = *(undefined4 *)(*pass + 0x378);
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  userVec = (uint *)inst[4];
  if (userVec[1] != 0) {
    loopIndex = 0;
    userIndexPlus1 = 1;
    userByteOffset = 0;
    do {
      loopIndex2 = 0;
      do {
        if (loopIndex2 < loopIndex) {
          if (loopIndex < *userVec) {
            userCount = userVec[1];
            userVecCopy = userVec;
            if (userCount <= loopIndex) {
              _memset(userCount * 4 + userVec[2],0,(loopIndex - userCount) * 4 + 4);
              userVec[1] = userIndexPlus1;
              userVecCopy = (uint *)inst[4];
            }
            userSlot = (int *)(userByteOffset + userVec[2]);
          }
          else {
            userSlot = (int *)Vector__elementRefGrow(userVec,loopIndex);
            userVecCopy = (uint *)inst[4];
          }
          earlierUser = *userSlot;
          if (loopIndex2 < *userVecCopy) {
            userCountCopy = userVecCopy[1];
            userVec = userVecCopy;
            if (userCountCopy <= loopIndex2) {
              _memset(userCountCopy * 4 + userVecCopy[2],0,(loopIndex2 - userCountCopy) * 4 + 4);
              userVecCopy[1] = loopIndex2 + 1;
              userVec = (uint *)inst[4];
            }
            earlierSlot = (int *)(loopIndex2 * 4 + userVecCopy[2]);
          }
          else {
            earlierSlot = (int *)Vector__elementRefGrow(userVecCopy,loopIndex2);
            userVec = (uint *)inst[4];
          }
          if (earlierUser == *earlierSlot) break;
        }
        if (loopIndex == loopIndex2) {
          if (loopIndex < *userVec) {
            userCount = userVec[1];
            if (userCount <= loopIndex) {
              _memset(userCount * 4 + userVec[2],0,(loopIndex - userCount) * 4 + 4);
              userVec[1] = userIndexPlus1;
            }
            userSlotB = (undefined4 *)(userByteOffset + userVec[2]);
          }
          else {
            userSlotB = (undefined4 *)Vector__elementRefGrow(userVec,loopIndex);
          }
          user = (int *)*userSlotB;
          if (user != (int *)0x0) {
            if ((*(int *)(user[0x22] + 8) == 0x8e) ||
               (earlierUser = (**(code **)(*user + 0x5c))(user), earlierUser != 0)) {
              ((int (*)())FUN_00141044)(&userWriteMaskOut,pass,user);
              laneMaskWord = userWriteMaskOut;
              if (*(char *)((int)&laneMaskWord + fromLane) != '\0') goto LAB_00142f88;
            }
            extraSourceOfUser = (int *)0x0;
            if ((user[5] & 0x200U) != 0) {
              extraSourceOfUser = (int *)IRInst__getOperandSource(user,user[0x21]);
            }
            countBefore = vecCount;
            if (extraSourceOfUser == inst) {
              if (vecCount < vecCapacity) {
                earlierUser = vecCount * 4;
                _memset(earlierUser + vecData,0,4);
                vecCount = countBefore + 1;
                pushSlot = (undefined4 *)(earlierUser + vecData);
              }
              else {
                pushSlot = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
              }
              *pushSlot = user;
              userVec = (uint *)inst[4];
              goto LAB_00142c3c;
            }
          }
          userVec = (uint *)inst[4];
        }
LAB_00142c3c:
        loopIndex2 = loopIndex2 + 1;
      } while (loopIndex2 <= loopIndex);
      loopIndex = loopIndex + 1;
      userIndexPlus1 = userIndexPlus1 + 1;
      userByteOffset = userByteOffset + 4;
    } while (loopIndex < userVec[1]);
  }
  while (vecCount != 0) {
    topIndex = vecCount - 1;
    topSlot = (int *)0x0;
    if (topIndex < vecCount) {
      topSlot = (int *)(topIndex * 4 + vecData);
    }
    pendingInst = *topSlot;
    Vector__removeAt(&vecCapacity,topIndex);
    ((int (*)())FUN_001427a4)(&pendingNeededMaskOut,pass,pendingInst);
    laneMaskWord = pendingNeededMaskOut;
    ((int (*)())FUN_00141090)(&pendingUsedLanesOut,pass,pendingInst);
    pendingUsedLanes = pendingUsedLanesOut;
    if (*(char *)((int)&pendingUsedLanes + fromLane) != '\0') {
      flag1WithoutFlag7Result = OpcodeTraits__flag1WithoutFlag7(*pass,pendingInst);
      if (((flag1WithoutFlag7Result == 0) || (*(char *)((int)&pendingUsedLanes + toLane) != '\0')) ||
         (*(char *)((int)&laneMaskWord + toLane) != '\0')) goto LAB_00142f88;
      pendingUserVec = *(uint **)(pendingInst + 0x10);
      if (pendingUserVec[1] != 0) {
        loopIndex = 0;
        userIndexPlus1 = 1;
        pendingUserByteOffset = 0;
        do {
          loopIndex2 = 0;
          do {
            if (loopIndex2 < loopIndex) {
              if (loopIndex < *pendingUserVec) {
                userCount = pendingUserVec[1];
                userVecCopy = pendingUserVec;
                if (userCount <= loopIndex) {
                  _memset(userCount * 4 + pendingUserVec[2],0,(loopIndex - userCount) * 4 + 4);
                  pendingUserVec[1] = userIndexPlus1;
                  userVecCopy = *(uint **)(pendingInst + 0x10);
                }
                userSlot = (int *)(pendingUserByteOffset + pendingUserVec[2]);
              }
              else {
                userSlot = (int *)Vector__elementRefGrow(pendingUserVec,loopIndex);
                userVecCopy = *(uint **)(pendingInst + 0x10);
              }
              iVar8 = *userSlot;
              if (loopIndex2 < *userVecCopy) {
                userCountCopy = userVecCopy[1];
                pendingUserVec = userVecCopy;
                if (userCountCopy <= loopIndex2) {
                  _memset(userCountCopy * 4 + userVecCopy[2],0,(loopIndex2 - userCountCopy) * 4 + 4);
                  userVecCopy[1] = loopIndex2 + 1;
                  pendingUserVec = *(uint **)(pendingInst + 0x10);
                }
                earlierSlot = (int *)(loopIndex2 * 4 + userVecCopy[2]);
              }
              else {
                earlierSlot = (int *)Vector__elementRefGrow(userVecCopy,loopIndex2);
                pendingUserVec = *(uint **)(pendingInst + 0x10);
              }
              if (iVar8 == *earlierSlot) break;
            }
            if (loopIndex == loopIndex2) {
              if (loopIndex < *pendingUserVec) {
                userCount = pendingUserVec[1];
                if (userCount <= loopIndex) {
                  _memset(userCount * 4 + pendingUserVec[2],0,(loopIndex - userCount) * 4 + 4);
                  pendingUserVec[1] = userIndexPlus1;
                }
                userSlotB = (undefined4 *)(pendingUserByteOffset + pendingUserVec[2]);
              }
              else {
                userSlotB = (undefined4 *)Vector__elementRefGrow(pendingUserVec,loopIndex);
              }
              user = (int *)*userSlotB;
              if (user != (int *)0x0) {
                if ((*(int *)(user[0x22] + 8) == 0x8e) ||
                   (iVar8 = (**(code **)(*user + 0x5c))(user), iVar8 != 0)) {
                  ((int (*)())FUN_00141044)(pendingUserWriteMaskOut,pass,user);
                  pendingUserWriteMask = pendingUserWriteMaskOut[0];
                  if (*(char *)((int)&pendingUserWriteMask + fromLane) != '\0') goto LAB_00142f88;
                }
                iVar8 = 0;
                if ((user[5] & 0x200U) != 0) {
                  iVar8 = IRInst__getOperandSource(user,user[0x21]);
                }
                countBefore = vecCount;
                if (iVar8 == pendingInst) {
                  if (vecCount < vecCapacity) {
                    iVar8 = vecCount * 4;
                    _memset(iVar8 + vecData,0,4);
                    vecCount = countBefore + 1;
                    pushSlot = (undefined4 *)(iVar8 + vecData);
                  }
                  else {
                    pushSlot = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
                  }
                  *pushSlot = user;
                  pendingUserVec = *(uint **)(pendingInst + 0x10);
                  goto LAB_00142f38;
                }
              }
              pendingUserVec = *(uint **)(pendingInst + 0x10);
            }
LAB_00142f38:
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 <= loopIndex);
          loopIndex = loopIndex + 1;
          userIndexPlus1 = userIndexPlus1 + 1;
          pendingUserByteOffset = pendingUserByteOffset + 4;
        } while (loopIndex < pendingUserVec[1]);
      }
    }
  }
  result = 1;
LAB_00142f8c:
  Arena__free(vecArena,vecData);
  return result;
LAB_00142f88:
  result = 0;
  goto LAB_00142f8c;
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* FUN_00142fdc @ 0x142fdc (1672 bytes) */
int FUN_00142fdc(packCtx, inst, inst2, laneMapA, laneMapB)
  undefined4 packCtx;
  int inst;
  int inst2;
  byte *laneMapA;
  byte *laneMapB;
{
  int extraSrcOfInst2;
  int loopIndexB;
  int countdown;
  int loopIndex;
  bool isLast;
  bool moreComponents;
  undefined4 identityLaneMap;
  int extraSrcOfInst;
  int iVar4;
  int *laneOwnerPtr;
  uint invertedNeeded;
  byte *laneMapPtr;
  byte laneComponent;
  int iVar9;
  byte local_b8 [4];
  uint freeComponentsA;
  uint invertedNeededSwappedB;
  uint invertedNeededSwappedA;
  uint neededMaskA;
  undefined4 usedLanesA;
  uint neededMaskB;
  undefined4 usedLanesB;
  undefined4 laneWritten;
  undefined4 laneOccupied;
  uint freeComponentsB;
  int local_8c [5];
  uint writeMaskA;
  undefined1 auStack_74 [4];
  uint neededMaskAOut;
  undefined4 usedLanesAOut;
  uint writeMaskB;
  undefined1 auStack_64 [4];
  uint neededMaskBOut;
  undefined4 local_5c [4];
  
  ((int (*)())FUN_00141044)(&writeMaskA,packCtx,inst);
  ((int (*)())FUN_00140e70)(auStack_74,packCtx,inst);
  ((int (*)())FUN_001427a4)(&neededMaskAOut,packCtx,inst);
  neededMaskA = neededMaskAOut;
  ((int (*)())FUN_00141090)(&usedLanesAOut,packCtx,inst);
  usedLanesA = usedLanesAOut;
  ((int (*)())FUN_00141044)(&writeMaskB,packCtx,inst2);
  ((int (*)())FUN_00140e70)(auStack_64,packCtx,inst2);
  ((int (*)())FUN_001427a4)(&neededMaskBOut,packCtx,inst2);
  neededMaskB = neededMaskBOut;
  ((int (*)())FUN_00141090)(local_5c,packCtx,inst2);
  identityLaneMap = DAT_001b003c;
  extraSrcOfInst = 0;
  *(undefined4 *)laneMapA = DAT_001b003c;
  *(undefined4 *)laneMapB = identityLaneMap;
  laneOccupied = DAT_001b0040;
  usedLanesB = local_5c[0];
  laneWritten = DAT_001b0040;
  if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
    extraSrcOfInst = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
  }
  if (extraSrcOfInst != inst2) {
    loopIndex = 0;
    iVar9 = 4;
    laneOwnerPtr = local_8c;
    do {
      if (*(char *)((int)&usedLanesA + loopIndex) != '\0') {
        *(undefined1 *)((int)&laneWritten + loopIndex) = 0;
        *(undefined1 *)((int)&laneOccupied + loopIndex) = 1;
        *laneOwnerPtr = inst;
        local_b8[loopIndex] = (byte)loopIndex;
      }
      loopIndex = loopIndex + 1;
      laneOwnerPtr = laneOwnerPtr + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  extraSrcOfInst2 = 0;
  if ((*(uint *)(inst2 + 0x14) & 0x200) != 0) {
    extraSrcOfInst2 = IRInst__getOperandSource(inst2,*(undefined4 *)(inst2 + 0x84));
  }
  if (extraSrcOfInst2 != inst) {
    loopIndex = 0;
    laneOwnerPtr = local_8c;
    do {
      if (*(char *)((int)&usedLanesB + loopIndex) != '\0') {
        if (*(char *)((int)&laneOccupied + loopIndex) == '\0') {
          *(undefined1 *)((int)&laneWritten + loopIndex) = 0;
          *(undefined1 *)((int)&laneOccupied + loopIndex) = 1;
          *laneOwnerPtr = inst2;
          local_b8[loopIndex] = (byte)loopIndex;
        }
        else {
          iVar9 = 0;
          if ((*(uint *)(inst2 + 0x14) & 0x200) != 0) {
            iVar9 = IRInst__getOperandSource(inst2,*(undefined4 *)(inst2 + 0x84));
          }
          iVar4 = 0;
          if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
            iVar4 = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
          }
          if (iVar9 != iVar4) {
            return 0;
          }
        }
      }
      moreComponents = loopIndex != 3;
      laneOwnerPtr = laneOwnerPtr + 1;
      loopIndex = loopIndex + 1;
    } while (moreComponents);
  }
  loopIndex = 0;
  laneOwnerPtr = local_8c;
  laneMapPtr = laneMapA;
  do {
    if (*(char *)((int)&neededMaskA + loopIndex) != '\0') {
      iVar9 = 0;
      laneComponent = (byte)loopIndex;
      if (*(char *)((int)&laneOccupied + loopIndex) == '\0') {
        *laneOwnerPtr = inst;
        *laneMapPtr = laneComponent;
        *(undefined1 *)((int)&laneWritten + loopIndex) = 1;
        *(undefined1 *)((int)&laneOccupied + loopIndex) = 1;
        local_b8[loopIndex] = laneComponent;
      }
      else {
        while ((*(char *)((int)&laneOccupied + iVar9) != '\0' ||
               (iVar4 = ((int (*)())FUN_00142974)(packCtx,inst,loopIndex,iVar9), iVar4 == 0))) {
          isLast = iVar9 == 3;
          iVar9 = iVar9 + 1;
          if (isLast) {
            return 0;
          }
        }
        *(undefined1 *)((int)&laneOccupied + iVar9) = 1;
        local_8c[iVar9] = inst;
        *(undefined1 *)((int)&laneWritten + iVar9) = 1;
        *laneMapPtr = (byte)iVar9;
        local_b8[iVar9] = laneComponent;
      }
    }
    moreComponents = loopIndex != 3;
    laneOwnerPtr = laneOwnerPtr + 1;
    laneMapPtr = laneMapPtr + 1;
    loopIndex = loopIndex + 1;
  } while (moreComponents);
  extraSrcOfInst2 = 0;
  if ((*(uint *)(inst2 + 0x14) & 0x200) != 0) {
    extraSrcOfInst2 = IRInst__getOperandSource(inst2,*(undefined4 *)(inst2 + 0x84));
  }
  if (extraSrcOfInst2 == inst) {
    iVar9 = 4;
    loopIndex = 0;
    laneMapPtr = laneMapB;
    do {
      if (*(char *)((int)&usedLanesB + loopIndex) != '\0') {
        *laneMapPtr = laneMapA[loopIndex];
      }
      loopIndex = loopIndex + 1;
      laneMapPtr = laneMapPtr + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  loopIndex = 0;
  laneOwnerPtr = local_8c;
  laneMapPtr = laneMapB;
  do {
    if (*(char *)((int)&neededMaskB + loopIndex) != '\0') {
      laneComponent = (byte)loopIndex;
      if (*(char *)((int)&laneOccupied + loopIndex) == '\0') {
        *(undefined1 *)((int)&laneWritten + loopIndex) = 1;
        *laneOwnerPtr = inst2;
        *laneMapPtr = laneComponent;
        *(undefined1 *)((int)&laneOccupied + loopIndex) = 1;
        local_b8[loopIndex] = laneComponent;
      }
      else if ((*(char *)((int)&laneWritten + loopIndex) == '\0') ||
              (iVar9 = ((int (*)())FUN_00141100)(packCtx,*laneOwnerPtr,(uint)local_b8[loopIndex],inst2,loopIndex), iVar9 == 0
              )) {
        iVar9 = 0;
        while ((*(char *)((int)&laneOccupied + iVar9) != '\0' ||
               (iVar4 = ((int (*)())FUN_00142974)(packCtx,inst2,loopIndex,iVar9), iVar4 == 0))) {
          isLast = iVar9 == 3;
          iVar9 = iVar9 + 1;
          if (isLast) {
            return 0;
          }
        }
        *(undefined1 *)((int)&laneOccupied + iVar9) = 1;
        local_8c[iVar9] = inst2;
        *(undefined1 *)((int)&laneWritten + iVar9) = 1;
        *laneMapPtr = (byte)iVar9;
        local_b8[iVar9] = laneComponent;
      }
    }
    moreComponents = loopIndex != 3;
    laneOwnerPtr = laneOwnerPtr + 1;
    laneMapPtr = laneMapPtr + 1;
    loopIndex = loopIndex + 1;
  } while (moreComponents);
  extraSrcOfInst = 0;
  if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
    extraSrcOfInst = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
  }
  if (extraSrcOfInst == inst2) {
    countdown = 4;
    loopIndex = 0;
    laneMapPtr = laneMapA;
    do {
      if (*(char *)((int)&usedLanesA + loopIndex) != '\0') {
        *laneMapPtr = laneMapB[loopIndex];
      }
      loopIndex = loopIndex + 1;
      laneMapPtr = laneMapPtr + 1;
      countdown = countdown + -1;
    } while (countdown != 0);
  }
  loopIndex = 0;
  invertedNeeded = ~neededMaskA;
  do {
    invertedNeededSwappedA = invertedNeeded << 0x18 | (invertedNeeded & 0xff00) << 8 | invertedNeeded >> 8 & 0xff00 | invertedNeeded >> 0x18;
    freeComponentsA = writeMaskA & invertedNeededSwappedA;
    if (*(char *)((int)&freeComponentsA + loopIndex) != '\0') {
      loopIndexB = 0;
      do {
        if ((*(char *)((int)&laneWritten + loopIndexB) != '\0') &&
           (iVar4 = ((int (*)())FUN_00141100)(packCtx,local_8c[loopIndexB],(uint)local_b8[loopIndexB],inst,loopIndex),
           iVar4 != 0)) {
          *laneMapA = (byte)loopIndexB;
          goto LAB_001434fc;
        }
        moreComponents = loopIndexB != 3;
        loopIndexB = loopIndexB + 1;
      } while (moreComponents);
      loopIndexB = 0;
      iVar4 = 4;
      while (*(char *)((int)&laneOccupied + loopIndexB) != '\0') {
        loopIndexB = loopIndexB + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          return 0;
        }
      }
      *(undefined1 *)((int)&laneOccupied + loopIndexB) = 1;
      local_8c[loopIndexB] = inst;
      *(undefined1 *)((int)&laneWritten + loopIndexB) = 1;
      *laneMapA = (byte)loopIndexB;
      local_b8[loopIndexB] = (byte)loopIndex;
    }
LAB_001434fc:
    moreComponents = loopIndex != 3;
    laneMapA = laneMapA + 1;
    loopIndex = loopIndex + 1;
  } while (moreComponents);
  loopIndex = 0;
  invertedNeeded = ~neededMaskB;
  do {
    invertedNeededSwappedB = invertedNeeded << 0x18 | (invertedNeeded & 0xff00) << 8 | invertedNeeded >> 8 & 0xff00 | invertedNeeded >> 0x18;
    freeComponentsB = writeMaskB & invertedNeededSwappedB;
    if (*(char *)((int)local_8c + loopIndex + -4) != '\0') {
      loopIndexB = 0;
      do {
        if ((*(char *)((int)&laneWritten + loopIndexB) != '\0') &&
           (iVar4 = ((int (*)())FUN_00141100)(packCtx,local_8c[loopIndexB],(uint)local_b8[loopIndexB],inst2,loopIndex),
           iVar4 != 0)) {
          *laneMapB = (byte)loopIndexB;
          goto LAB_001435e4;
        }
        moreComponents = loopIndexB != 3;
        loopIndexB = loopIndexB + 1;
      } while (moreComponents);
      loopIndexB = 0;
      iVar4 = 4;
      while (*(char *)((int)&laneOccupied + loopIndexB) != '\0') {
        loopIndexB = loopIndexB + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          return 0;
        }
      }
      *(undefined1 *)((int)&laneOccupied + loopIndexB) = 1;
      local_8c[loopIndexB] = inst2;
      *(undefined1 *)((int)&laneWritten + loopIndexB) = 1;
      *laneMapB = (byte)loopIndexB;
      local_b8[loopIndexB] = (byte)loopIndex;
    }
LAB_001435e4:
    isLast = loopIndex == 3;
    laneMapB = laneMapB + 1;
    loopIndex = loopIndex + 1;
    if (isLast) {
      return 1;
    }
  } while( true );
}

/* FUN_00143664 @ 0x143664 (80 bytes) */
int FUN_00143664(param_1, inst, inst2, param_4, param_5)
  undefined4 param_1;
  undefined4 inst;
  undefined4 inst2;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 callResult;
  
  ((int (*)())FUN_00140e7c)(param_1,inst,inst2);
  callResult = ((int (*)())FUN_00142fdc)(param_1,inst,inst2,param_4,param_5);
  return callResult;
}

/* PostPack__buildCandidate @ 0x1436b4 (168 bytes) */
int PostPack__buildCandidate(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  int iVar1;
  
  *param_4 = param_2;
  param_4[1] = param_3;
  iVar1 = ((int (*)())FUN_00140e7c)(param_1,param_2,param_3);
  if ((((iVar1 != 0) &&
       (iVar1 = ((int (*)())FUN_00143664)(param_1,param_2,param_3,param_4 + 2,param_4 + 3), iVar1 != 0)) &&
      (iVar1 = ((int (*)())PostPack__canPairInEitherOrder)(param_1,param_2,param_3,param_4 + 4), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_00141930)(param_1,param_2,param_3,param_4 + 5), iVar1 != 0)) {
    return 1;
  }
  return 0;
}

/* FUN_0014375c @ 0x14375c (1672 bytes) */
int FUN_0014375c(pass, rootInst, rootRemap)
  int *pass;
  undefined4 rootInst;
  int rootRemap;
{
  int *workSlot;
  int *userSlot;
  int *remapTopSlot;
  int *workTopSlot;
  int laneSelectBytes;
  uint workCountSaved;
  int userRemap;
  int workPushOffset;
  int userExtraSource;
  int remapPushOffset;
  int user;
  uint remapCountSaved;
  uint userCountCopy;
  uint nextUserIndex;
  uint remapTopIndex;
  uint workTopIndex;
  uint remapCount;
  int userByteOffset;
  int currentRemap;
  int currentInst;
  int rootRemapCopy;
  int operandRecord;
  uint loopIndexB;
  int countdown;
  unsigned int ghidra_home[8] = { pass, rootInst, rootRemap, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool moreComponents;
  byte remapLane;
  int remappedSelectWord;
  uint userCount;
  undefined4 *rootWorkSlot;
  int *remapSlot;
  int operandSource;
  uint workCount;
  int loopIndex;
  byte *remapBytePtr;
  int rootWorkOffset;
  int userLastOperand;
  uint earlierUserIndex;
  uint userIndex;
  int rootRemapOffset;
  uint *userVec;
  uint *userVecCopy;
  int earlierUser;
  int operandIndex;
  uint remapLaneWide;
  undefined4 userWriteMask;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_70_buf [0x10];
  #define vecCapacity (*(uint *)(local_70_buf + 0x00))
  #define vecCount (*(uint *)(local_70_buf + 0x04))
  #define vecData (*(int *)(local_70_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_70_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vec2Capacity/vec2Count/vec2Data/vec2Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_60_buf [0x10];
  #define vec2Capacity (*(uint *)(local_60_buf + 0x00))
  #define vec2Count (*(uint *)(local_60_buf + 0x04))
  #define vec2Data (*(int *)(local_60_buf + 0x08))
  #define vec2Arena (*(undefined4 *)(local_60_buf + 0x0c))
  undefined4 userWriteMaskOut [2];
  
  vecArena = *(undefined4 *)(*pass + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  (*(int *)((unsigned char *)ghidra_home + 8)) = rootRemap;
  vecData = Arena__alloc(vecArena,8);
  vec2Arena = *(undefined4 *)(*pass + 0x378);
  vec2Count = 0;
  vec2Capacity = 2;
  vec2Data = Arena__alloc(vec2Arena,8);
  workCount = vecCount;
  if (vecCount < vecCapacity) {
    rootWorkOffset = vecCount * 4;
    _memset(rootWorkOffset + vecData,0,4);
    vecCount = workCount + 1;
    rootWorkSlot = (undefined4 *)(rootWorkOffset + vecData);
  }
  else {
    rootWorkSlot = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
  }
  remapCount = vec2Count;
  rootRemapCopy = (*(int *)((unsigned char *)ghidra_home + 8));
  *rootWorkSlot = rootInst;
  if (vec2Count < vec2Capacity) {
    rootRemapOffset = vec2Count * 4;
    _memset(rootRemapOffset + vec2Data,0,4);
    vec2Count = remapCount + 1;
    remapSlot = (int *)(rootRemapOffset + vec2Data);
  }
  else {
    remapSlot = (int *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
  }
  *remapSlot = rootRemapCopy;
  do {
    do {
      do {
        if (vecCount == 0) {
          Arena__free(vec2Arena,vec2Data);
          Arena__free(vecArena,vecData);
          return;
        }
        workTopIndex = vecCount - 1;
        workTopSlot = (int *)0x0;
        if (workTopIndex < vecCount) {
          workTopSlot = (int *)(workTopIndex * 4 + vecData);
        }
        currentInst = *workTopSlot;
        Vector__removeAt(&vecCapacity,workTopIndex);
        remapTopSlot = (int *)0x0;
        remapTopIndex = vec2Count - 1;
        if (remapTopIndex < vec2Count) {
          remapTopSlot = (int *)(remapTopIndex * 4 + vec2Data);
        }
        currentRemap = *remapTopSlot;
        Vector__removeAt(&vec2Capacity,remapTopIndex);
        (*(int *)((unsigned char *)ghidra_home + 8)) = currentRemap;
      } while (currentRemap == DAT_001b003c);
      userVec = *(uint **)(currentInst + 0x10);
      if (userVec[1] != 0) {
        userIndex = 0;
        nextUserIndex = 1;
        userByteOffset = 0;
        do {
          earlierUserIndex = 0;
          do {
            if (earlierUserIndex < userIndex) {
              if (userIndex < *userVec) {
                userCount = userVec[1];
                userVecCopy = userVec;
                if (userCount <= userIndex) {
                  _memset(userCount * 4 + userVec[2],0,(userIndex - userCount) * 4 + 4);
                  userVec[1] = nextUserIndex;
                  userVecCopy = *(uint **)(currentInst + 0x10);
                }
                userSlot = (int *)(userByteOffset + userVec[2]);
              }
              else {
                userSlot = (int *)Vector__elementRefGrow(userVec,userIndex);
                userVecCopy = *(uint **)(currentInst + 0x10);
              }
              earlierUser = *userSlot;
              if (earlierUserIndex < *userVecCopy) {
                userCountCopy = userVecCopy[1];
                userVec = userVecCopy;
                if (userCountCopy <= earlierUserIndex) {
                  _memset(userCountCopy * 4 + userVecCopy[2],0,(earlierUserIndex - userCountCopy) * 4 + 4);
                  userVecCopy[1] = earlierUserIndex + 1;
                  userVec = *(uint **)(currentInst + 0x10);
                }
                userSlot = (int *)(earlierUserIndex * 4 + userVecCopy[2]);
              }
              else {
                userSlot = (int *)Vector__elementRefGrow(userVecCopy,earlierUserIndex);
                userVec = *(uint **)(currentInst + 0x10);
              }
              if (earlierUser == *userSlot) break;
            }
            if (userIndex == earlierUserIndex) {
              if (userIndex < *userVec) {
                userCount = userVec[1];
                if (userCount <= userIndex) {
                  _memset(userCount * 4 + userVec[2],0,(userIndex - userCount) * 4 + 4);
                  userVec[1] = nextUserIndex;
                }
                userSlot = (int *)(userByteOffset + userVec[2]);
              }
              else {
                userSlot = (int *)Vector__elementRefGrow(userVec,userIndex);
              }
              user = *userSlot;
              if (user != 0) {
                userLastOperand = *(int *)(user + 0x84);
                if ((*(uint *)(user + 0x14) & 0x200) != 0) {
                  userLastOperand = userLastOperand + -1;
                }
                if (0 < userLastOperand) {
                  operandIndex = 1;
                  do {
                    operandSource = IRInst__getOperandSource(user,operandIndex);
                    if (currentInst == operandSource) {
                      operandRecord = IRInst__getOperandRecord(user,operandIndex);
                      loopIndex = 0;
                      laneSelectBytes = *(int *)(operandRecord + 0x10);
                      countdown = 4;
                      do {
                        if (*(byte *)((int)&laneSelectBytes + loopIndex) != 4) {
                          *(undefined1 *)((int)&laneSelectBytes + loopIndex) =
                               *(undefined1 *)
                                ((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 8)) + (uint)*(byte *)((int)&laneSelectBytes + loopIndex));
                        }
                        remappedSelectWord = laneSelectBytes;
                        loopIndex = loopIndex + 1;
                        countdown = countdown + -1;
                      } while (countdown != 0);
                      operandRecord = IRInst__getOperandRecord(user,operandIndex);
                      *(int *)(operandRecord + 0x10) = remappedSelectWord;
                    }
                    operandIndex = operandIndex + 1;
                  } while (operandIndex <= userLastOperand);
                }
              }
              userVec = *(uint **)(currentInst + 0x10);
            }
            earlierUserIndex = earlierUserIndex + 1;
          } while (earlierUserIndex <= userIndex);
          userIndex = userIndex + 1;
          nextUserIndex = nextUserIndex + 1;
          userByteOffset = userByteOffset + 4;
        } while (userIndex < userVec[1]);
      }
    } while (userVec[1] == 0);
    userIndex = 0;
    nextUserIndex = 1;
    userByteOffset = 0;
    do {
      earlierUserIndex = 0;
      do {
        if (earlierUserIndex < userIndex) {
          if (userIndex < *userVec) {
            userCount = userVec[1];
            userVecCopy = userVec;
            if (userCount <= userIndex) {
              _memset(userCount * 4 + userVec[2],0,(userIndex - userCount) * 4 + 4);
              userVec[1] = nextUserIndex;
              userVecCopy = *(uint **)(currentInst + 0x10);
            }
            userSlot = (int *)(userByteOffset + userVec[2]);
          }
          else {
            userSlot = (int *)Vector__elementRefGrow(userVec,userIndex);
            userVecCopy = *(uint **)(currentInst + 0x10);
          }
          earlierUser = *userSlot;
          if (earlierUserIndex < *userVecCopy) {
            userCountCopy = userVecCopy[1];
            userVec = userVecCopy;
            if (userCountCopy <= earlierUserIndex) {
              _memset(userCountCopy * 4 + userVecCopy[2],0,(earlierUserIndex - userCountCopy) * 4 + 4);
              userVecCopy[1] = earlierUserIndex + 1;
              userVec = *(uint **)(currentInst + 0x10);
            }
            userSlot = (int *)(earlierUserIndex * 4 + userVecCopy[2]);
          }
          else {
            userSlot = (int *)Vector__elementRefGrow(userVecCopy,earlierUserIndex);
            userVec = *(uint **)(currentInst + 0x10);
          }
          if (earlierUser == *userSlot) break;
        }
        if (userIndex == earlierUserIndex) {
          if (userIndex < *userVec) {
            userCount = userVec[1];
            if (userCount <= userIndex) {
              _memset(userCount * 4 + userVec[2],0,(userIndex - userCount) * 4 + 4);
              userVec[1] = nextUserIndex;
            }
            userSlot = (int *)(userByteOffset + userVec[2]);
          }
          else {
            userSlot = (int *)Vector__elementRefGrow(userVec,userIndex);
          }
          user = *userSlot;
          if (user != 0) {
            userExtraSource = 0;
            if ((*(uint *)(user + 0x14) & 0x200) != 0) {
              userExtraSource = IRInst__getOperandSource(user,*(undefined4 *)(user + 0x84));
            }
            if (userExtraSource == currentInst) {
              laneSelectBytes = DAT_001b003c;
              ((int (*)())FUN_00141090)(userWriteMaskOut,pass,user);
              loopIndexB = 0;
              remapBytePtr = (byte *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
              userWriteMask = userWriteMaskOut[0];
              do {
                if (*(char *)((int)&userWriteMask + loopIndexB) != '\0') {
                  remapLane = *remapBytePtr;
                  remapLaneWide = (uint)remapLane;
                  if (remapLaneWide != loopIndexB) {
                    ((int (*)())FUN_00141458)(pass,user,loopIndexB,remapLaneWide);
                    *(byte *)((int)&laneSelectBytes + loopIndexB) = remapLane;
                    *(char *)((int)&laneSelectBytes + remapLaneWide) = (char)loopIndexB;
                  }
                }
                workCountSaved = vecCount;
                moreComponents = loopIndexB != 3;
                remapBytePtr = remapBytePtr + 1;
                loopIndexB = loopIndexB + 1;
              } while (moreComponents);
              if (vecCount < vecCapacity) {
                workPushOffset = vecCount * 4;
                _memset(workPushOffset + vecData,0,4);
                vecCount = workCountSaved + 1;
                workSlot = (int *)(workPushOffset + vecData);
              }
              else {
                workSlot = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
              }
              remapCountSaved = vec2Count;
              userRemap = laneSelectBytes;
              *workSlot = user;
              if (vec2Count < vec2Capacity) {
                remapPushOffset = vec2Count * 4;
                _memset(remapPushOffset + vec2Data,0,4);
                vec2Count = remapCountSaved + 1;
                remapSlot = (int *)(remapPushOffset + vec2Data);
              }
              else {
                remapSlot = (int *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
              }
              *remapSlot = userRemap;
              userVec = *(uint **)(currentInst + 0x10);
              goto LAB_00143da4;
            }
          }
          userVec = *(uint **)(currentInst + 0x10);
        }
LAB_00143da4:
        earlierUserIndex = earlierUserIndex + 1;
      } while (earlierUserIndex <= userIndex);
      userIndex = userIndex + 1;
      nextUserIndex = nextUserIndex + 1;
      userByteOffset = userByteOffset + 4;
    } while (userIndex < userVec[1]);
  } while( true );
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena
#undef vec2Capacity
#undef vec2Count
#undef vec2Data
#undef vec2Arena

/* FUN_00143e40 @ 0x143e40 (676 bytes) */
int FUN_00143e40(pass, pair)
  undefined4 *pass;
  int *pair;
{
  int score;
  int loopIndex3;
  int countdown;
  int splitRgbAlphaEnabled;
  int firstInst;
  int userInst;
  uint userCount;
  int *elementPtr;
  int *entryPtr;
  int entry;
  int secondInst;
  uint loopIndex;
  uint loopIndex2;
  uint *userVec;
  int writeMaskFirst;
  int local_24 [2];
  
  entryPtr = pair + 5;
  firstInst = *pair;
  secondInst = pair[1];
  if (pair[4] != 0) {
    firstInst = pair[1];
    secondInst = *pair;
  }
  splitRgbAlphaEnabled = Compiler__isOptionEnabled(*pass,0x30);
  if ((splitRgbAlphaEnabled == 0) ||
     ((((int (*)())FUN_00141044)(&writeMaskFirst,pass,firstInst), writeMaskFirst != 1 &&
      (((int (*)())FUN_00141044)(local_24,pass,secondInst), local_24[0] != 1)))) {
    userVec = *(uint **)(firstInst + 0x10);
    userCount = userVec[1];
    if (userCount != 0) {
      loopIndex = 0;
      do {
        if (loopIndex < *userVec) {
          if (userCount <= loopIndex) {
            _memset(userCount * 4 + userVec[2],0,(loopIndex - userCount) * 4 + 4);
            userVec[1] = loopIndex + 1;
          }
          elementPtr = (int *)(loopIndex * 4 + userVec[2]);
        }
        else {
          elementPtr = (int *)Vector__elementRefGrow(userVec,loopIndex);
        }
        userInst = *elementPtr;
        if ((userInst != 0) &&
           ((*(int *)(*(int *)(userInst + 0x88) + 8) == 0x8e ||
            (((secondInst != userInst && ((*(uint *)(userInst + 0x14) & 0x200) != 0)) &&
             (userInst = IRInst__getOperandSource(userInst,*(undefined4 *)(userInst + 0x84)), firstInst == userInst)))))) {
          userVec = *(uint **)(secondInst + 0x10);
          userCount = userVec[1];
          if (userCount != 0) {
            loopIndex2 = 0;
            do {
              if (loopIndex2 < *userVec) {
                if (userCount <= loopIndex2) {
                  _memset(userCount * 4 + userVec[2],0,(loopIndex2 - userCount) * 4 + 4);
                  userVec[1] = loopIndex2 + 1;
                }
                elementPtr = (int *)(loopIndex2 * 4 + userVec[2]);
              }
              else {
                elementPtr = (int *)Vector__elementRefGrow(userVec,loopIndex2);
              }
              userInst = *elementPtr;
              if ((userInst != 0) &&
                 ((*(int *)(*(int *)(userInst + 0x88) + 8) == 0x8e ||
                  (((firstInst != userInst && ((*(uint *)(userInst + 0x14) & 0x200) != 0)) &&
                   (userInst = IRInst__getOperandSource(userInst,*(undefined4 *)(userInst + 0x84)), secondInst == userInst))))))
              goto LAB_001440cc;
              userVec = *(uint **)(secondInst + 0x10);
              loopIndex2 = loopIndex2 + 1;
              userCount = userVec[1];
            } while (loopIndex2 < userCount);
          }
        }
        userVec = *(uint **)(firstInst + 0x10);
        loopIndex = loopIndex + 1;
        userCount = userVec[1];
      } while (loopIndex < userCount);
    }
    countdown = 5;
    loopIndex3 = 0;
    score = 0;
    do {
      entry = entryPtr[1];
      if ((entry != 0) && (*(int *)(entry + 0x24) == 0)) {
        loopIndex3 = loopIndex3 + 1;
        if (score == 0) {
          entry = *(int *)(entry + 0x28);
        }
        else {
          entry = *(int *)(entry + 0x28);
          if (score <= entry) goto LAB_001440b0;
        }
        score = entry;
      }
LAB_001440b0:
      entryPtr = entryPtr + 1;
      countdown = countdown + -1;
    } while (countdown != 0);
    score = loopIndex3 * -3000 + 1000 + score * 0xfa;
  }
  else {
LAB_001440cc:
    score = -1;
  }
  return score;
}

/* FUN_001440e4 @ 0x1440e4 (4680 bytes) */
int FUN_001440e4(pass, inst, inst2, groupSlotCursor)
  undefined4 *pass;
  int inst;
  int inst2;
  int groupSlotCursor;
{
  int *laneSourceCursor;
  int *latestSourceBlock;
  int candidateSource;
  int insertBefore;
  int loopIndex6;
  int callResult2;
  int countdown7;
  int firstUsedLaneF;
  int thirdSource;
  int scanIdx2;
  int sourceDef2;
  int operandRecord5;
  int loopIndex5;
  int countdown6;
  int laneSource;
  int countdown11;
  int newCombinedInst;
  int blockContext;
  int vcall2cResult;
  int vcall1cResult;
  int instOpcode;
  int isBeforeOrSameResult;
  int swapTemp;
  uint distinctCountIfThird;
  uint loopIndex8;
  int firstUsedLaneC;
  int sourceDef3;
  int countdown9;
  int firstUsedLaneA;
  int firstUsedLaneB;
  int loopIndex7;
  int countdown8;
  int scanIdx1;
  int newInstSecond;
  int secondSource;
  int sourceDef;
  int operandRecord4;
  int countdown5;
  int groupCombinedInst;
  int newInstFirstB;
  int newInstFirst;
  int firstSource;
  int scanIdx0;
  int countdown4;
  int firstUsedLaneD;
  int loopIndex3;
  int countdown3;
  int operandRecord3;
  int countdown2;
  int operandRecord2;
  int callResult;
  int loopIndex2;
  int countdown;
  int loopIndex;
  int operandRecord;
  bool noThirdSource;
  bool isLast;
  bool moreComponents;
  bool noFourthSource;
  byte laneSelectByte;
  char operandComponent;
  undefined4 defaultSelectWord;
  undefined4 selectWordToStore;
  undefined4 selectWordToStoreB;
  int laneSourceInst;
  undefined1 laneSelectCopy;
  undefined1 matchedSlotIndex;
  byte *laneSelectScan;
  undefined4 *blockSlotPtr;
  undefined4 *laneSlotCursor;
  int firstUsedLaneE;
  uint distinctSourceCount;
  undefined4 *laneSelectCursor;
  undefined4 compilerForBlock;
  undefined4 extraSelectWord;
  int *insertBlock;
  int loopIndex4;
  undefined4 *laneGroup;
  int countdownK;
  undefined4 selectScratch0;
  undefined4 selectScratch1;
  undefined4 selectScratch2;
  undefined4 selectScratch3;
  undefined4 selectScratch4;
  undefined4 selectScratch5 [4];
  undefined4 selectScratch9;
  undefined4 remappedSelect [2];
  undefined4 writeMaskOutA;
  undefined4 writeMaskOutB;
  undefined4 writeMaskOutC;
  undefined4 writeMaskOutD;
  undefined4 writeMaskOutE;
  undefined4 writeMaskOutF;
  undefined4 writeMaskOutG;
  int fourthSource;
  int operandSourceB;
  int operandSource;
  undefined *constTableBaseA;
  undefined4 *scratchBase;
  undefined *constTableBaseB;
  undefined4 *scratchPtrCC;
  undefined4 *scratchPtrC4;
  undefined4 *scratchPtrC4Plus1;
  undefined4 *scratchPtrC4Plus2;
  undefined4 *scratchPtrC4Plus3;
  undefined4 *scratchPtrB4;
  undefined4 *scratchPtrD4;
  
  scratchPtrC4Plus1 = selectScratch5 + 1;
  scratchPtrC4Plus2 = selectScratch5 + 2;
  scratchPtrC4Plus3 = selectScratch5 + 3;
  scratchPtrB4 = &selectScratch9;
  scratchPtrD4 = &selectScratch1;
  loopIndex4 = 0;
LAB_00144144:
  laneGroup = *(undefined4 **)(groupSlotCursor + 4);
  if (laneGroup != (undefined4 *)0x0) {
    groupCombinedInst = laneGroup[9];
    scratchBase = &selectScratch0;
    if (groupCombinedInst == 0) {
      countdown5 = 4;
      scanIdx0 = 0;
      laneSlotCursor = laneGroup;
      do {
        if (laneSlotCursor[4] != 0) {
          distinctSourceCount = 1;
          firstSource = laneGroup[scanIdx0 + 4];
          goto LAB_001441e0;
        }
        scanIdx0 = scanIdx0 + 1;
        laneSlotCursor = laneSlotCursor + 1;
        countdown5 = countdown5 + -1;
      } while (countdown5 != 0);
      distinctSourceCount = 0;
      firstSource = 0;
LAB_001441e0:
      countdown6 = 4;
      scanIdx1 = 0;
      laneSlotCursor = laneGroup;
      do {
        if ((firstSource != laneSlotCursor[4]) && (laneSlotCursor[4] != 0)) {
          distinctSourceCount = distinctSourceCount + 1;
          secondSource = laneGroup[scanIdx1 + 4];
          goto LAB_00144214;
        }
        scanIdx1 = scanIdx1 + 1;
        laneSlotCursor = laneSlotCursor + 1;
        countdown6 = countdown6 + -1;
      } while (countdown6 != 0);
      secondSource = 0;
LAB_00144214:
      countdown7 = 4;
      scanIdx2 = 0;
      laneSlotCursor = laneGroup;
      do {
        laneSource = laneSlotCursor[4];
        if (((firstSource != laneSource) && (secondSource != laneSource)) && (laneSource != 0)) {
          distinctCountIfThird = distinctSourceCount + 1;
          thirdSource = laneGroup[scanIdx2 + 4];
          noThirdSource = thirdSource == 0;
          if (noThirdSource) goto LAB_00144258;
          distinctSourceCount = distinctSourceCount + 2;
          countdown7 = 4;
          laneSourceCursor = laneGroup + 4;
          laneSlotCursor = laneGroup;
          goto LAB_001442d4;
        }
        scanIdx2 = scanIdx2 + 1;
        laneSlotCursor = laneSlotCursor + 1;
        countdown7 = countdown7 + -1;
      } while (countdown7 != 0);
      noThirdSource = true;
      thirdSource = 0;
      fourthSource = 0;
      noFourthSource = noThirdSource;
      goto LAB_00144264;
    }
    goto LAB_0014516c;
  }
  goto LAB_001452d4;
  while( true ) {
    laneSourceCursor = laneSourceCursor + 1;
    laneSlotCursor = laneSlotCursor + 1;
    countdown7 = countdown7 + -1;
    if (countdown7 == 0) break;
LAB_001442d4:
    laneSource = laneSlotCursor[4];
    if (((firstSource != laneSource) && (secondSource != laneSource)) && ((laneSource != thirdSource && (laneSource != 0)))) {
      fourthSource = *laneSourceCursor;
      noFourthSource = fourthSource == 0;
      if (noFourthSource) goto LAB_00144264;
      loopIndex8 = 0;
      countdown7 = 4;
      laneSourceCursor = laneGroup + 4;
      laneSelectScan = (byte *)(laneGroup + 8);
      goto LAB_00144334;
    }
  }
LAB_00144258:
  fourthSource = 0;
  distinctSourceCount = distinctCountIfThird;
  noFourthSource = true;
  goto LAB_00144264;
  while( true ) {
    loopIndex8 = loopIndex8 + 1;
    laneSourceCursor = laneSourceCursor + 1;
    countdown7 = countdown7 + -1;
    if (countdown7 == 0) break;
LAB_00144334:
    laneSelectByte = *laneSelectScan;
    laneSelectScan = laneSelectScan + 1;
    if (loopIndex8 == laneSelectByte) {
      candidateSource = *laneSourceCursor;
      if (candidateSource != fourthSource) {
        if (candidateSource == thirdSource) {
          noThirdSource = fourthSource == 0;
          swapTemp = secondSource;
          thirdSource = fourthSource;
        }
        else {
          swapTemp = fourthSource;
          if ((secondSource != candidateSource) && (swapTemp = secondSource, firstSource == candidateSource)) {
            firstSource = fourthSource;
          }
        }
        secondSource = swapTemp;
        noFourthSource = candidateSource == 0;
        fourthSource = candidateSource;
      }
      break;
    }
  }
LAB_00144264:
  insertBefore = *(int *)(firstSource + 8);
  latestSourceBlock = *(int **)(insertBefore + 0x158);
  isBeforeOrSameResult = Inst__isBeforeOrSame(insertBefore,secondSource);
  if (isBeforeOrSameResult != 0) {
    insertBefore = *(int *)(secondSource + 8);
    latestSourceBlock = *(int **)(insertBefore + 0x158);
  }
  if (!noThirdSource) {
    isBeforeOrSameResult = Inst__isBeforeOrSame(insertBefore,thirdSource);
    if (isBeforeOrSameResult != 0) {
      insertBefore = *(int *)(thirdSource + 8);
      latestSourceBlock = *(int **)(insertBefore + 0x158);
    }
    if ((!noFourthSource) && (isBeforeOrSameResult = Inst__isBeforeOrSame(insertBefore,fourthSource), isBeforeOrSameResult != 0)) {
      insertBefore = *(int *)(fourthSource + 8);
      latestSourceBlock = *(int **)(insertBefore + 0x158);
    }
  }
  Inst__isBeforeOrSame(firstSource,insertBefore);
  Inst__isBeforeOrSame(secondSource,insertBefore);
  if (!noThirdSource) {
    Inst__isBeforeOrSame(thirdSource,insertBefore);
  }
  if (!noFourthSource) {
    Inst__isBeforeOrSame(fourthSource,insertBefore);
  }
  instOpcode = *(int *)(*(int *)(insertBefore + 0x88) + 8);
  while (instOpcode == 0x8e) {
    insertBefore = *(int *)(insertBefore + 8);
    instOpcode = *(int *)(*(int *)(insertBefore + 0x88) + 8);
  }
  vcall1cResult = (**(code **)(*latestSourceBlock + 0x1c))(latestSourceBlock);
  if (vcall1cResult != 0) {
    blockSlotPtr = (undefined4 *)0x0;
    if (*(int *)(latestSourceBlock[0x34] + 4) != 0) {
      blockSlotPtr = *(undefined4 **)(latestSourceBlock[0x34] + 8);
    }
    latestSourceBlock = (int *)*blockSlotPtr;
    insertBefore = FUN_000e83bc(latestSourceBlock);
  }
  vcall2cResult = (**(code **)(*latestSourceBlock + 0x2c))(latestSourceBlock);
  insertBlock = latestSourceBlock;
  if (vcall2cResult != 0) {
    blockSlotPtr = (undefined4 *)0x0;
    if (*(int *)(latestSourceBlock[0x34] + 4) != 0) {
      blockSlotPtr = *(undefined4 **)(latestSourceBlock[0x34] + 8);
    }
    insertBlock = (int *)*blockSlotPtr;
    callResult2 = Block__isAncestorOf(insertBlock,latestSourceBlock[0x54]);
    if (callResult2 == 0) {
      blockSlotPtr = (undefined4 *)0x0;
      if (1 < *(uint *)(latestSourceBlock[0x34] + 4)) {
        blockSlotPtr = (undefined4 *)(*(int *)(latestSourceBlock[0x34] + 8) + 4);
      }
      insertBlock = (int *)*blockSlotPtr;
    }
    insertBefore = FUN_000e83bc(insertBlock);
  }
  defaultSelectWord = DAT_001b0044;
  blockContext = insertBlock[0x2b];
  compilerForBlock = *(undefined4 *)(blockContext + 8);
  if (distinctSourceCount == 2) {
    loopIndex5 = 0;
    selectScratch5[0] = DAT_001b0038;
    selectScratch4 = DAT_001b0038;
    constTableBaseB = &DAT_001b40f0;
    countdown2 = 4;
    constTableBaseA = &DAT_001b40f0;
    selectScratch1 = DAT_001b0044;
    scratchBase = &selectScratch0;
    laneSlotCursor = laneGroup;
    do {
      if (firstSource == laneSlotCursor[4]) {
        *(undefined1 *)((int)&selectScratch1 + (uint)*(byte *)((int)laneGroup + loopIndex5 + 0x20)) = 0;
        laneSelectByte = *(byte *)((int)laneGroup + loopIndex5 + 0x20);
        *(byte *)((int)&selectScratch4 + (uint)laneSelectByte) = laneSelectByte;
      }
      loopIndex5 = loopIndex5 + 1;
      laneSlotCursor = laneSlotCursor + 1;
      countdown2 = countdown2 + -1;
    } while (countdown2 != 0);
    loopIndex5 = 0;
    countdown2 = 4;
    do {
      if (*(char *)((int)&selectScratch1 + loopIndex5) == '\x01') {
        *(char *)((int)selectScratch5 + loopIndex5) = (char)loopIndex5;
        *(undefined1 *)((int)&selectScratch1 + loopIndex5) = 0;
        break;
      }
      loopIndex5 = loopIndex5 + 1;
      countdown2 = countdown2 + -1;
    } while (countdown2 != 0);
    newInstFirst = ((int (*)())IRInst__createWithConstantOperands)(2,defaultSelectWord,firstSource,blockContext,compilerForBlock,(double)FLOAT_001aa0d4);
    *(undefined4 *)(newInstFirst + 0x160) = *(undefined4 *)(blockContext + 0x478);
    operandRecord5 = IRInst__getOperandRecord(newInstFirst,0);
    WriteMask__fromSelectWord(&writeMaskOutA,*(undefined4 *)(operandRecord5 + 0x10));
    selectWordToStore = selectScratch4;
    *(undefined4 *)(newInstFirst + 0xc) = writeMaskOutA;
    operandRecord5 = IRInst__getOperandRecord(newInstFirst,1);
    selectWordToStoreB = selectScratch5[0];
    *(undefined4 *)(operandRecord5 + 0x10) = selectWordToStore;
    operandRecord5 = IRInst__getOperandRecord(newInstFirst,2);
    loopIndex2 = 0;
    selectScratch5[0] = *(undefined4 *)(constTableBaseB + -0x40ac);
    selectScratch1 = *(undefined4 *)(constTableBaseA + -0x40b8);
    *(undefined4 *)(operandRecord5 + 0x10) = selectWordToStoreB;
    countdown6 = 4;
    laneSlotCursor = laneGroup;
    do {
      if (secondSource == laneSlotCursor[4]) {
        *(undefined1 *)((int)scratchBase + *(byte *)((int)laneGroup + loopIndex2 + 0x20) + 0x14) = 0;
        laneSelectByte = *(byte *)((int)laneGroup + loopIndex2 + 0x20);
        *(byte *)((int)scratchBase + laneSelectByte + 0x10) = laneSelectByte;
      }
      loopIndex2 = loopIndex2 + 1;
      laneSlotCursor = laneSlotCursor + 1;
      countdown6 = countdown6 + -1;
    } while (countdown6 != 0);
    scratchPtrC4 = selectScratch5;
    countdown2 = 4;
    loopIndex5 = 0;
    do {
      if (*(char *)(loopIndex5 + (int)scratchPtrC4) == '\x01') {
        *(char *)((int)scratchBase + loopIndex5 + 4) = (char)loopIndex5;
        *(undefined1 *)((int)scratchBase + loopIndex5 + 0x14) = 0;
        break;
      }
      loopIndex5 = loopIndex5 + 1;
      countdown2 = countdown2 + -1;
    } while (countdown2 != 0);
    selectScratch4 = selectScratch1;
    callResult = ((int (*)())IRInst__createWithConstantOperands)(2,selectScratch5[0],secondSource,blockContext,compilerForBlock,(double)FLOAT_001aa0d4);
    *(undefined4 *)(callResult + 0x160) = *(undefined4 *)(blockContext + 0x478);
    operandRecord4 = IRInst__getOperandRecord(callResult,0);
    WriteMask__fromSelectWord(&writeMaskOutB,*(undefined4 *)(operandRecord4 + 0x10));
    selectWordToStoreB = selectScratch4;
    *(undefined4 *)(callResult + 0xc) = writeMaskOutB;
    operandRecord4 = IRInst__getOperandRecord(callResult,1);
    selectWordToStore = selectScratch1;
    *(undefined4 *)(operandRecord4 + 0x10) = selectWordToStoreB;
    operandRecord4 = IRInst__getOperandRecord(callResult,2);
    firstUsedLaneA = 0;
    *(undefined4 *)(operandRecord4 + 0x10) = selectWordToStore;
    newCombinedInst = IRInst__create(0x12,compilerForBlock);
    *(undefined4 *)(newCombinedInst + 0x120) = 0;
    *(undefined4 *)(newCombinedInst + 0x98) = 0;
    *(undefined4 *)(newCombinedInst + 0x124) = 0;
    *(undefined4 *)(newCombinedInst + 0x94) = *(undefined4 *)(newCombinedInst + 0x14c);
    sourceDef = IRInst__getOperandSource(newInstFirst,1);
    operandRecord5 = IRInst__getOperandRecord(newInstFirst,2);
    selectScratch1 = *(undefined4 *)(operandRecord5 + 0x10);
    countdown6 = 4;
    do {
      if (*(char *)((int)&selectScratch1 + firstUsedLaneA) != '\x04') goto LAB_0014488c;
      firstUsedLaneA = firstUsedLaneA + 1;
      countdown6 = countdown6 + -1;
    } while (countdown6 != 0);
    firstUsedLaneA = -1;
LAB_0014488c:
    sourceDef2 = IRInst__getOperandSource(callResult,1);
    operandRecord3 = IRInst__getOperandRecord(callResult,2);
    firstUsedLaneC = 0;
    selectScratch4 = *(undefined4 *)(operandRecord3 + 0x10);
    countdown3 = 4;
    do {
      if (*(char *)((int)&selectScratch4 + firstUsedLaneC) != '\x04') goto LAB_001448d8;
      firstUsedLaneC = firstUsedLaneC + 1;
      countdown3 = countdown3 + -1;
    } while (countdown3 != 0);
    firstUsedLaneC = -1;
LAB_001448d8:
    loopIndex3 = 0;
    selectScratch5[0] = *(undefined4 *)(constTableBaseB + -0x40ac);
    laneSelectCursor = laneGroup + 8;
    selectScratch2 = *(undefined4 *)(constTableBaseA + -0x40b8);
    countdown = 4;
    laneSlotCursor = laneGroup;
    selectScratch3 = selectScratch2;
    do {
      if (sourceDef == laneSlotCursor[4]) {
        *(undefined1 *)(loopIndex3 + (int)scratchPtrC4) = 0;
        scratchPtrCC = &selectScratch3;
        *(undefined1 *)((int)&selectScratch2 + loopIndex3) = *(undefined1 *)laneSelectCursor;
        *(char *)(loopIndex3 + (int)&selectScratch3) = (char)firstUsedLaneC;
      }
      else if (sourceDef2 == laneSlotCursor[4]) {
        *(char *)((int)&selectScratch2 + loopIndex3) = (char)firstUsedLaneA;
        *(undefined1 *)(loopIndex3 + (int)scratchPtrC4) = 0;
        scratchPtrCC = &selectScratch3;
        *(undefined1 *)(loopIndex3 + (int)&selectScratch3) = *(undefined1 *)laneSelectCursor;
      }
      loopIndex3 = loopIndex3 + 1;
      laneSelectCursor = (undefined4 *)((int)laneSelectCursor + 1);
      laneSlotCursor = laneSlotCursor + 1;
      countdown = countdown + -1;
    } while (countdown != 0);
    *(undefined4 *)(newCombinedInst + 0x9c) = selectScratch5[0];
    IRInst__setOperandSource(newCombinedInst,1,newInstFirst,1,compilerForBlock);
    IROperand__setModifierBits(newCombinedInst + 0xa4,1,0);
    IROperand__setModifierBits(newCombinedInst + 0xa4,2,0);
    selectWordToStore = selectScratch2;
    operandRecord4 = IRInst__getOperandRecord(newCombinedInst,1);
    *(undefined4 *)(operandRecord4 + 0x10) = selectWordToStore;
    IRInst__setOperandSource(newCombinedInst,2,callResult,1,compilerForBlock);
    IROperand__setModifierBits(newCombinedInst + 0xbc,1,0);
    IROperand__setModifierBits(newCombinedInst + 0xbc,2,0);
    selectWordToStore = selectScratch3;
    operandRecord4 = IRInst__getOperandRecord(newCombinedInst,2);
    *(undefined4 *)(operandRecord4 + 0x10) = selectWordToStore;
    operandRecord4 = IRInst__getOperandRecord(newCombinedInst,0);
    WriteMask__fromSelectWord(&writeMaskOutC,*(undefined4 *)(operandRecord4 + 0x10));
    *(undefined4 *)(newCombinedInst + 0xc) = writeMaskOutC;
    Block__insertInstBefore(insertBlock,insertBefore,newInstFirst);
  }
  else {
    if (distinctSourceCount < 2) {
      scratchBase = &selectScratch0;
      goto LAB_0014514c;
    }
    scratchBase = &selectScratch0;
    if (4 < distinctSourceCount) goto LAB_0014514c;
    constTableBaseB = &DAT_001b40f0;
    loopIndex2 = 0;
    constTableBaseA = &DAT_001b40f0;
    countdown8 = 4;
    selectScratch5[0] = DAT_001b0038;
    selectScratch3 = DAT_001b0044;
    selectScratch2 = DAT_001b0038;
    laneSlotCursor = laneGroup;
    do {
      if (firstSource == laneSlotCursor[4]) {
        *(undefined1 *)((int)&selectScratch3 + (uint)*(byte *)((int)laneGroup + loopIndex2 + 0x20)) = 0;
        laneSelectByte = *(byte *)((int)laneGroup + loopIndex2 + 0x20);
        *(byte *)((int)&selectScratch2 + (uint)laneSelectByte) = laneSelectByte;
      }
      loopIndex2 = loopIndex2 + 1;
      laneSlotCursor = laneSlotCursor + 1;
      countdown8 = countdown8 + -1;
    } while (countdown8 != 0);
    scratchPtrCC = &selectScratch3;
    countdown8 = 4;
    loopIndex2 = 0;
    do {
      if (*(char *)(loopIndex2 + (int)scratchPtrCC) == '\x01') {
        *(char *)((int)selectScratch5 + loopIndex2) = (char)loopIndex2;
        *(undefined1 *)((int)&selectScratch3 + loopIndex2) = 0;
        break;
      }
      loopIndex2 = loopIndex2 + 1;
      countdown8 = countdown8 + -1;
    } while (countdown8 != 0);
    newInstFirstB = ((int (*)())IRInst__createWithConstantOperands)(2,defaultSelectWord,firstSource,blockContext,compilerForBlock,(double)FLOAT_001aa0e8);
    *(undefined4 *)(newInstFirstB + 0x160) = *(undefined4 *)(blockContext + 0x478);
    operandRecord2 = IRInst__getOperandRecord(newInstFirstB,0);
    WriteMask__fromSelectWord(&writeMaskOutD,*(undefined4 *)(operandRecord2 + 0x10));
    selectWordToStore = selectScratch2;
    *(undefined4 *)(newInstFirstB + 0xc) = writeMaskOutD;
    operandRecord2 = IRInst__getOperandRecord(newInstFirstB,1);
    selectWordToStoreB = selectScratch5[0];
    *(undefined4 *)(operandRecord2 + 0x10) = selectWordToStore;
    operandRecord2 = IRInst__getOperandRecord(newInstFirstB,2);
    selectScratch2 = *(undefined4 *)(constTableBaseA + -0x40b8);
    loopIndex7 = 0;
    selectScratch5[0] = *(undefined4 *)(constTableBaseB + -0x40ac);
    *(undefined4 *)(operandRecord2 + 0x10) = selectWordToStoreB;
    countdown2 = 4;
    laneSlotCursor = laneGroup;
    do {
      if (secondSource == laneSlotCursor[4]) {
        *(undefined1 *)((int)scratchBase + *(byte *)((int)laneGroup + loopIndex7 + 0x20) + 0x14) = 0;
        laneSelectByte = *(byte *)((int)laneGroup + loopIndex7 + 0x20);
        *(byte *)((int)scratchBase + laneSelectByte + 8) = laneSelectByte;
      }
      loopIndex7 = loopIndex7 + 1;
      laneSlotCursor = laneSlotCursor + 1;
      countdown2 = countdown2 + -1;
    } while (countdown2 != 0);
    scratchPtrC4 = selectScratch5;
    countdown8 = 4;
    loopIndex2 = 0;
    do {
      if (*(char *)(loopIndex2 + (int)scratchPtrC4) == '\x01') {
        *(char *)((int)scratchBase + loopIndex2 + 0xc) = (char)loopIndex2;
        *(undefined1 *)((int)scratchBase + loopIndex2 + 0x14) = 0;
        break;
      }
      loopIndex2 = loopIndex2 + 1;
      countdown8 = countdown8 + -1;
    } while (countdown8 != 0);
    loopIndex2 = 0;
    countdown8 = 4;
    do {
      if (*(char *)(loopIndex2 + (int)scratchPtrC4) == '\x01') {
        *(char *)((int)scratchBase + loopIndex2 + 0x10) = (char)loopIndex2;
        *(undefined1 *)((int)scratchBase + loopIndex2 + 0x14) = 0;
        break;
      }
      loopIndex2 = loopIndex2 + 1;
      countdown8 = countdown8 + -1;
    } while (countdown8 != 0);
    selectScratch3 = selectScratch2;
    selectScratch4 = selectScratch2;
    newInstSecond = ((int (*)())IRInst__createWithConstantOperands)(3,selectScratch5[0],secondSource,blockContext,compilerForBlock,(double)FLOAT_001aa0e8);
    *(undefined4 *)(newInstSecond + 0x160) = *(undefined4 *)(blockContext + 0x478);
    operandRecord2 = IRInst__getOperandRecord(newInstSecond,0);
    WriteMask__fromSelectWord(&writeMaskOutE,*(undefined4 *)(operandRecord2 + 0x10));
    selectWordToStore = selectScratch2;
    *(undefined4 *)(newInstSecond + 0xc) = writeMaskOutE;
    operandRecord2 = IRInst__getOperandRecord(newInstSecond,1);
    selectWordToStoreB = selectScratch3;
    *(undefined4 *)(operandRecord2 + 0x10) = selectWordToStore;
    operandRecord2 = IRInst__getOperandRecord(newInstSecond,2);
    selectWordToStore = selectScratch4;
    *(undefined4 *)(operandRecord2 + 0x10) = selectWordToStoreB;
    operandRecord2 = IRInst__getOperandRecord(newInstSecond,3);
    loopIndex7 = 0;
    selectScratch4 = *(undefined4 *)(constTableBaseB + -0x40ac);
    selectScratch2 = *(undefined4 *)(constTableBaseA + -0x40b8);
    *(undefined4 *)(operandRecord2 + 0x10) = selectWordToStore;
    countdown2 = 4;
    selectScratch3 = selectScratch2;
    laneSlotCursor = laneGroup;
    do {
      if (thirdSource == laneSlotCursor[4]) {
        *(undefined1 *)((int)scratchBase + *(byte *)((int)laneGroup + loopIndex7 + 0x20) + 0x10) = 0;
        laneSelectByte = *(byte *)((int)laneGroup + loopIndex7 + 0x20);
        *(byte *)((int)scratchBase + laneSelectByte + 0xc) = laneSelectByte;
      }
      loopIndex7 = loopIndex7 + 1;
      laneSlotCursor = laneSlotCursor + 1;
      countdown2 = countdown2 + -1;
    } while (countdown2 != 0);
    loopIndex2 = 0;
    countdown8 = 4;
    do {
      if (*(char *)((int)&selectScratch4 + loopIndex2) == '\x01') {
        *(char *)((int)scratchBase + loopIndex2 + 8) = (char)loopIndex2;
        *(undefined1 *)((int)scratchBase + loopIndex2 + 0x10) = 0;
        break;
      }
      loopIndex2 = loopIndex2 + 1;
      countdown8 = countdown8 + -1;
    } while (countdown8 != 0);
    callResult = ((int (*)())IRInst__createWithConstantOperands)(2,selectScratch4,thirdSource,blockContext,compilerForBlock,(double)FLOAT_001aa0d4);
    *(undefined4 *)(callResult + 0x160) = *(undefined4 *)(blockContext + 0x478);
    firstUsedLaneB = 0;
    operandRecord5 = IRInst__getOperandRecord(callResult,0);
    WriteMask__fromSelectWord(&writeMaskOutF,*(undefined4 *)(operandRecord5 + 0x10));
    selectWordToStoreB = selectScratch3;
    *(undefined4 *)(callResult + 0xc) = writeMaskOutF;
    operandRecord5 = IRInst__getOperandRecord(callResult,1);
    selectWordToStore = selectScratch2;
    *(undefined4 *)(operandRecord5 + 0x10) = selectWordToStoreB;
    operandRecord5 = IRInst__getOperandRecord(callResult,2);
    *(undefined4 *)(operandRecord5 + 0x10) = selectWordToStore;
    newCombinedInst = IRInst__create(0x14,compilerForBlock);
    *(undefined4 *)(newCombinedInst + 0x120) = 0;
    *(undefined4 *)(newCombinedInst + 0x98) = 0;
    *(undefined4 *)(newCombinedInst + 0x124) = 0;
    *(undefined4 *)(newCombinedInst + 0x94) = *(undefined4 *)(newCombinedInst + 0x14c);
    operandSource = IRInst__getOperandSource(newInstFirstB,1);
    operandRecord5 = IRInst__getOperandRecord(newInstFirstB,2);
    selectScratch2 = *(undefined4 *)(operandRecord5 + 0x10);
    countdown6 = 4;
    do {
      if (*(char *)((int)&selectScratch2 + firstUsedLaneB) != '\x04') goto LAB_00144dd8;
      firstUsedLaneB = firstUsedLaneB + 1;
      countdown6 = countdown6 + -1;
    } while (countdown6 != 0);
    firstUsedLaneB = -1;
LAB_00144dd8:
    operandSourceB = IRInst__getOperandSource(newInstSecond,1);
    operandRecord5 = IRInst__getOperandRecord(newInstSecond,2);
    selectScratch3 = *(undefined4 *)(operandRecord5 + 0x10);
    firstUsedLaneD = 0;
    operandRecord5 = IRInst__getOperandRecord(newInstSecond,3);
    selectScratch4 = *(undefined4 *)(operandRecord5 + 0x10);
    countdown6 = 4;
    do {
      if (*(char *)(firstUsedLaneD + (int)scratchPtrCC) != '\x04') goto LAB_00144e38;
      firstUsedLaneD = firstUsedLaneD + 1;
      countdown6 = countdown6 + -1;
    } while (countdown6 != 0);
    firstUsedLaneD = -1;
LAB_00144e38:
    firstUsedLaneF = 0;
    countdown9 = 4;
    do {
      if (*(char *)((int)&selectScratch4 + firstUsedLaneF) != '\x04') goto LAB_00144e5c;
      firstUsedLaneF = firstUsedLaneF + 1;
      countdown9 = countdown9 + -1;
    } while (countdown9 != 0);
    firstUsedLaneF = -1;
LAB_00144e5c:
    sourceDef3 = IRInst__getOperandSource(callResult,1);
    operandRecord = IRInst__getOperandRecord(callResult,2);
    firstUsedLaneE = 0;
    selectScratch5[0] = *(undefined4 *)(operandRecord + 0x10);
    countdown = 4;
    do {
      if (*(char *)(firstUsedLaneE + (int)scratchPtrC4) != '\x04') goto LAB_00144ea8;
      firstUsedLaneE = firstUsedLaneE + 1;
      countdown = countdown + -1;
    } while (countdown != 0);
    firstUsedLaneE = -1;
LAB_00144ea8:
    selectScratch1 = *(undefined4 *)(constTableBaseA + -0x40b8);
    laneSelectCursor = laneGroup + 8;
    selectScratch5[1] = *(undefined4 *)(constTableBaseB + -0x40ac);
    countdownK = 4;
    loopIndex = 0;
    laneSlotCursor = laneGroup;
    do {
      laneSourceInst = laneSlotCursor[4];
      if (operandSource == laneSourceInst) {
        *(undefined1 *)(loopIndex + (int)scratchPtrC4Plus1) = 0;
        laneSelectCopy = *(undefined1 *)laneSelectCursor;
        *(char *)(loopIndex + (int)scratchPtrC4Plus3) = (char)firstUsedLaneD;
        *(undefined1 *)(loopIndex + (int)scratchPtrC4Plus2) = laneSelectCopy;
        *(char *)(loopIndex + (int)scratchPtrB4) = (char)firstUsedLaneE;
      }
      else if (operandSourceB == laneSourceInst) {
        *(undefined1 *)(loopIndex + (int)scratchPtrC4Plus1) = 0;
        *(char *)(loopIndex + (int)scratchPtrC4Plus2) = (char)firstUsedLaneB;
        laneSelectCopy = *(undefined1 *)laneSelectCursor;
        *(char *)(loopIndex + (int)scratchPtrB4) = (char)firstUsedLaneE;
        *(undefined1 *)(loopIndex + (int)scratchPtrC4Plus3) = laneSelectCopy;
      }
      else if (sourceDef3 == laneSourceInst) {
        *(undefined1 *)(loopIndex + (int)scratchPtrC4Plus1) = 0;
        *(char *)(loopIndex + (int)scratchPtrC4Plus2) = (char)firstUsedLaneB;
        *(char *)(loopIndex + (int)scratchPtrC4Plus3) = (char)firstUsedLaneF;
        *(undefined1 *)(loopIndex + (int)scratchPtrB4) = *(undefined1 *)laneSelectCursor;
      }
      else if ((!noFourthSource) && (fourthSource == laneSourceInst)) {
        *(char *)(loopIndex + (int)scratchPtrD4) = (char)loopIndex;
      }
      loopIndex = loopIndex + 1;
      laneSelectCursor = (undefined4 *)((int)laneSelectCursor + 1);
      laneSlotCursor = laneSlotCursor + 1;
      countdownK = countdownK + -1;
    } while (countdownK != 0);
    *(undefined4 *)(newCombinedInst + 0x9c) = selectScratch5[1];
    selectScratch5[2] = selectScratch1;
    selectScratch5[3] = selectScratch1;
    selectScratch9 = selectScratch1;
    IRInst__setOperandSource(newCombinedInst,1,newInstFirstB,1,compilerForBlock);
    IROperand__setModifierBits(newCombinedInst + 0xa4,1,0);
    IROperand__setModifierBits(newCombinedInst + 0xa4,2,0);
    selectWordToStore = selectScratch5[2];
    operandRecord5 = IRInst__getOperandRecord(newCombinedInst,1);
    *(undefined4 *)(operandRecord5 + 0x10) = selectWordToStore;
    IRInst__setOperandSource(newCombinedInst,2,newInstSecond,1,compilerForBlock);
    IROperand__setModifierBits(newCombinedInst + 0xbc,1,0);
    IROperand__setModifierBits(newCombinedInst + 0xbc,2,0);
    selectWordToStore = selectScratch5[3];
    operandRecord5 = IRInst__getOperandRecord(newCombinedInst,2);
    *(undefined4 *)(operandRecord5 + 0x10) = selectWordToStore;
    IRInst__setOperandSource(newCombinedInst,3,callResult,1,compilerForBlock);
    IROperand__setModifierBits(newCombinedInst + 0xd4,1,0);
    IROperand__setModifierBits(newCombinedInst + 0xd4,2,0);
    selectWordToStore = selectScratch9;
    operandRecord5 = IRInst__getOperandRecord(newCombinedInst,3);
    *(undefined4 *)(operandRecord5 + 0x10) = selectWordToStore;
    if (noFourthSource) {
      operandRecord5 = IRInst__getOperandRecord(newCombinedInst,0);
      WriteMask__fromSelectWord(&writeMaskOutG,*(undefined4 *)(operandRecord5 + 0x10));
      *(undefined4 *)(newCombinedInst + 0xc) = writeMaskOutG;
    }
    else {
      IRInst__setExtraOperandSource(newCombinedInst,fourthSource,1,compilerForBlock);
      extraSelectWord = selectScratch1;
      operandRecord5 = IRInst__getOperandRecord(newCombinedInst,4);
      selectWordToStore = DAT_001b0048;
      *(undefined4 *)(operandRecord5 + 0x10) = extraSelectWord;
      *(undefined4 *)(newCombinedInst + 0xc) = selectWordToStore;
    }
    Block__insertInstBefore(insertBlock,insertBefore,newInstFirstB);
    Block__insertInstBefore(insertBlock,insertBefore,newInstSecond);
  }
  Block__insertInstBefore(insertBlock,insertBefore,callResult);
  Block__insertInstBefore(insertBlock,insertBefore,newCombinedInst);
  laneGroup[9] = newCombinedInst;
LAB_0014514c:
  countdown4 = 4;
  laneSlotCursor = laneGroup;
  do {
    *laneSlotCursor = 1;
    laneSlotCursor = laneSlotCursor + 1;
    countdown4 = countdown4 + -1;
  } while (countdown4 != 0);
  groupCombinedInst = laneGroup[9];
LAB_0014516c:
  operandRecord4 = IRInst__getOperandRecord(inst,loopIndex4);
  loopIndex5 = 0;
  remappedSelect[0] = *(undefined4 *)(operandRecord4 + 0x10);
  do {
    operandComponent = *(char *)((int)remappedSelect + loopIndex5);
    if (operandComponent != '\x04') {
      sourceDef = IRInst__getOperandSource(inst,loopIndex4);
      countdown11 = 4;
      loopIndex6 = 0;
      laneSlotCursor = laneGroup;
      do {
        if ((sourceDef == laneSlotCursor[4]) && (operandComponent == *(char *)((int)laneGroup + loopIndex6 + 0x20))) {
          matchedSlotIndex = (undefined1)loopIndex6;
          goto LAB_001451cc;
        }
        loopIndex6 = loopIndex6 + 1;
        laneSlotCursor = laneSlotCursor + 1;
        countdown11 = countdown11 + -1;
      } while (countdown11 != 0);
      matchedSlotIndex = 0xff;
LAB_001451cc:
      *(undefined1 *)((int)remappedSelect + loopIndex5) = matchedSlotIndex;
    }
    selectWordToStore = remappedSelect[0];
    moreComponents = loopIndex5 != 3;
    loopIndex5 = loopIndex5 + 1;
  } while (moreComponents);
  operandRecord4 = IRInst__getOperandRecord(inst,loopIndex4);
  *(undefined4 *)(operandRecord4 + 0x10) = selectWordToStore;
  if ((*(int *)(inst + 0x84) == loopIndex4) && ((*(uint *)(inst + 0x14) & 0x200) != 0)) {
    IRInst__setExtraOperandSource(inst,groupCombinedInst,1,*pass);
  }
  else {
    IRInst__setOperandSource(inst,loopIndex4,groupCombinedInst,1,*pass);
  }
  operandRecord4 = IRInst__getOperandRecord(inst2,loopIndex4);
  loopIndex5 = 0;
  selectScratch0 = *(undefined4 *)(operandRecord4 + 0x10);
  do {
    operandComponent = *(char *)(loopIndex5 + (int)scratchBase);
    if (operandComponent != '\x04') {
      sourceDef = IRInst__getOperandSource(inst2,loopIndex4);
      countdown11 = 4;
      loopIndex6 = 0;
      laneSlotCursor = laneGroup;
      do {
        if ((sourceDef == laneSlotCursor[4]) && (operandComponent == *(char *)((int)laneGroup + loopIndex6 + 0x20))) {
          matchedSlotIndex = (undefined1)loopIndex6;
          goto LAB_00145280;
        }
        loopIndex6 = loopIndex6 + 1;
        laneSlotCursor = laneSlotCursor + 1;
        countdown11 = countdown11 + -1;
      } while (countdown11 != 0);
      matchedSlotIndex = 0xff;
LAB_00145280:
      *(undefined1 *)(loopIndex5 + (int)scratchBase) = matchedSlotIndex;
    }
    selectWordToStore = selectScratch0;
    moreComponents = loopIndex5 != 3;
    loopIndex5 = loopIndex5 + 1;
  } while (moreComponents);
  operandRecord4 = IRInst__getOperandRecord(inst2,loopIndex4);
  *(undefined4 *)(operandRecord4 + 0x10) = selectWordToStore;
  if ((*(int *)(inst2 + 0x84) == loopIndex4) && ((*(uint *)(inst2 + 0x14) & 0x200) != 0)) {
    IRInst__setExtraOperandSource(inst2,groupCombinedInst,1,*pass);
  }
  else {
    IRInst__setOperandSource(inst2,loopIndex4,groupCombinedInst,1,*pass);
  }
LAB_001452d4:
  isLast = loopIndex4 == 4;
  groupSlotCursor = groupSlotCursor + 4;
  loopIndex4 = loopIndex4 + 1;
  if (isLast) {
    return;
  }
  goto LAB_00144144;
}

/* FUN_0014532c @ 0x14532c (836 bytes) */
int FUN_0014532c(pass, pair)
  undefined4 *pass;
  int *pair;
{
  int sourceDef;
  uint userCount;
  int *elementPtr;
  int secondExtraSource;
  undefined4 compiler;
  int secondSelect;
  int firstSelect;
  uint loopIndex;
  int firstExtraSource;
  uint *userVec;
  int secondInst;
  int firstInst;
  
  secondSelect = pair[3];
  firstSelect = pair[2];
  secondInst = pair[1];
  firstInst = *pair;
  if (pair[4] != 0) {
    secondSelect = pair[2];
    firstSelect = pair[3];
    secondInst = *pair;
    firstInst = pair[1];
  }
  pass[2] = pass[2] + 1;
  if (0 < pair[5]) {
    ((int (*)())FUN_001440e4)(pass,firstInst,secondInst,pair + 5);
  }
  firstExtraSource = 0;
  if ((*(uint *)(firstInst + 0x14) & 0x200) != 0) {
    firstExtraSource = IRInst__getOperandSource(firstInst,*(undefined4 *)(firstInst + 0x84));
  }
  if (secondInst == firstExtraSource) {
    compiler = *pass;
    sourceDef = IRInst__getOperandSource(firstInst,*(undefined4 *)(firstInst + 0x84));
    userVec = *(uint **)(sourceDef + 0x10);
    userCount = userVec[1];
    if (0 < (int)userCount) {
      loopIndex = 0;
      do {
        if (loopIndex < *userVec) {
          if (userCount <= loopIndex) {
            _memset(userCount * 4 + userVec[2],0,(loopIndex - userCount) * 4 + 4);
            userVec[1] = loopIndex + 1;
          }
          elementPtr = (int *)(loopIndex * 4 + userVec[2]);
        }
        else {
          elementPtr = (int *)Vector__elementRefGrow(userVec,loopIndex);
        }
        if (firstInst == *elementPtr) {
          Vector__removeAt(userVec,loopIndex);
          sourceDef = IRInst__getOperandSource(firstInst,*(undefined4 *)(firstInst + 0x84));
          *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
          break;
        }
        userCount = userVec[1];
        loopIndex = loopIndex + 1;
      } while ((int)loopIndex < (int)userCount);
    }
    firstExtraSource = 0;
    IRInst__setOperandSource(firstInst,*(undefined4 *)(firstInst + 0x84),0,1,compiler);
    *(int *)(firstInst + 0x84) = *(int *)(firstInst + 0x84) + -1;
    *(uint *)(firstInst + 0x14) = *(uint *)(firstInst + 0x14) & 0xfffffdff;
  }
  secondExtraSource = 0;
  if ((*(uint *)(secondInst + 0x14) & 0x200) != 0) {
    secondExtraSource = IRInst__getOperandSource(secondInst,*(undefined4 *)(secondInst + 0x84));
  }
  if (firstInst == secondExtraSource) {
    compiler = *pass;
    sourceDef = IRInst__getOperandSource(secondInst,*(undefined4 *)(secondInst + 0x84));
    userVec = *(uint **)(sourceDef + 0x10);
    userCount = userVec[1];
    if (0 < (int)userCount) {
      loopIndex = 0;
      do {
        if (loopIndex < *userVec) {
          if (userCount <= loopIndex) {
            _memset(userCount * 4 + userVec[2],0,(loopIndex - userCount) * 4 + 4);
            userVec[1] = loopIndex + 1;
          }
          elementPtr = (int *)(loopIndex * 4 + userVec[2]);
        }
        else {
          elementPtr = (int *)Vector__elementRefGrow(userVec,loopIndex);
        }
        if (secondInst == *elementPtr) {
          Vector__removeAt(userVec,loopIndex);
          sourceDef = IRInst__getOperandSource(secondInst,*(undefined4 *)(secondInst + 0x84));
          *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
          break;
        }
        userCount = userVec[1];
        loopIndex = loopIndex + 1;
      } while ((int)loopIndex < (int)userCount);
    }
    IRInst__setOperandSource(secondInst,*(undefined4 *)(secondInst + 0x84),0,1,compiler);
    *(int *)(secondInst + 0x84) = *(int *)(secondInst + 0x84) + -1;
    *(uint *)(secondInst + 0x14) = *(uint *)(secondInst + 0x14) & 0xfffffdff;
  }
  else if ((secondExtraSource != 0) && (firstExtraSource != secondExtraSource)) {
    IRInst__setExtraOperandSource(firstInst,secondExtraSource,1,*pass);
    IRInst__getOperandRecord(firstInst,*(undefined4 *)(firstInst + 0x84));
  }
  ((int (*)())FUN_0014375c)(pass,firstInst,firstSelect);
  ((int (*)())FUN_0014375c)(pass,secondInst,secondSelect);
  ((int (*)())FUN_001411dc)(pass,firstInst,firstInst,firstSelect);
  ((int (*)())FUN_001411dc)(pass,firstInst,secondInst,secondSelect);
  return ((int (*)())FUN_001415a4)(pass,secondInst,firstInst);
}

/* pass_post_pack_insts @ 0x145670 (3828 bytes) */
int pass_post_pack_insts(param_1)
  int *param_1;
{
  uint lastScanIndex;
  uint minCapacityB;
  uint grownCapacityC;
  uint curCount;
  uint copyIndexG;
  uint scanIndex;
  uint newVecSizeC;
  uint minCapacity;
  uint keptCountB;
  uint scoreIndex;
  uint copyIndexE;
  uint grownCapacityB;
  uint keptCount;
  uint nextPairIndex;
  uint copyIndexD;
  uint grownCapacity;
  uint recordCount;
  uint newVecSizeB;
  uint copyIndexC;
  uint lastIndex;
  uint bestIndex;
  uint copyIndexB;
  uint copyIndex;
  uint vecCapacity;
  int grownDataD;
  int copyDestB;
  int copyOffsetG;
  int replacedInst;
  int copyOffsetF;
  int resultElement;
  int oldData;
  int scoreOffset;
  int candidateTotal;
  int copyOffsetE;
  int candidateRecord;
  int candidateOffset;
  int copySourceB;
  int grownDataC;
  int packable;
  int copyOffsetD;
  int vecData;
  int lastOffset;
  int copyOffsetC;
  int bestOffset;
  int grownDataB;
  int candidateScore;
  int scanData;
  int laneCountdown;
  int nextInst;
  int nextBlock;
  int candInstA;
  int copyDest;
  int copySource;
  int buildResult;
  int copyOffsetB;
  int grownData;
  int resultData;
  int copyOffset;
  int bestScore;
  int lookaheadInst;
  bool candidateLimitHit;
  int allocation3;
  int allocation;
  int operandRecord;
  bool atScanStart;
  int iVar2;
  uint laneIndex;
  int nextInstB;
  int iVar5;
  int iVar6;
  int flag1WithoutFlag7Result;
  int block;
  int iVar8;
  undefined4 arenaAt378;
  uint candidateCount;
  uint vecSize;
  int *bestCandidate;
  uint newVecSize;
  uint recordIndex;
  uint uVar15;
  uint uVar16;
  int candidateByteOffset;
  int inst;
  uint copyIndexF;
  uint uVar20;
  int instA;
  int *arenaPtr;
  undefined4 packedWriteMask;
  undefined4 local_64 [3];
  undefined4 packResult;
  int replacementInst;
  
  block = *(int *)(param_1[1] + 900);
  for (nextBlock = *(int *)(*(int *)(param_1[1] + 900) + 8); nextBlock != 0; nextBlock = *(int *)(nextBlock + 8)) {
    lookaheadInst = *(int *)(*(int *)(block + 0x98) + 8);
    inst = *(int *)(block + 0x98);
    if (lookaheadInst != 0) {
      do {
        nextInst = lookaheadInst;
        if ((*(uint *)(inst + 0x14) & 1) != 0) {
          ((int (*)())FUN_00141044)(&packResult,param_1,inst);
          packedWriteMask = packResult;
          if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
            operandRecord = IRInst__getOperandRecord(inst,*(undefined4 *)(inst + 0x84));
            laneIndex = 0;
            local_64[0] = *(undefined4 *)(operandRecord + 0x10);
            laneCountdown = 4;
            do {
              if (*(byte *)((int)local_64 + laneIndex) == laneIndex) {
                *(undefined1 *)((int)local_64 + (laneIndex - 4)) = 1;
              }
              laneIndex = laneIndex + 1;
              laneCountdown = laneCountdown + -1;
            } while (laneCountdown != 0);
          }
          nextInst = *(int *)(inst + 8);
          *(undefined4 *)(inst + 0xc) = packedWriteMask;
        }
        lookaheadInst = *(int *)(nextInst + 8);
        inst = nextInst;
      } while (*(int *)(nextInst + 8) != 0);
      nextBlock = *(int *)(block + 8);
    }
    block = nextBlock;
  }
  arenaAt378 = *(undefined4 *)(*param_1 + 0x378);
  vecData = Arena__alloc(arenaAt378,0x2c0);
  iVar2 = param_1[1];
  iVar6 = *(int *)(*(int *)(iVar2 + 900) + 8);
  if (iVar6 != 0) {
    candidateCount = 0;
    candidateTotal = 0;
    vecCapacity = 0x10;
    vecSize = 0;
    iVar2 = *(int *)(iVar2 + 900);
    do {
      iVar5 = iVar6;
      iVar6 = *(int *)(*(int *)(iVar2 + 0x98) + 8);
      instA = *(int *)(iVar2 + 0x98);
      if (iVar6 != 0) {
        do {
          iVar5 = iVar6;
          if ((*(uint *)(instA + 0x14) & 1) != 0) {
            flag1WithoutFlag7Result = OpcodeTraits__flag1WithoutFlag7(*(undefined4 *)(param_1[1] + 8),instA);
            if (flag1WithoutFlag7Result != 0) {
              atScanStart = true;
              iVar6 = *(int *)(param_1[1] + 900);
              for (iVar5 = *(int *)(*(int *)(param_1[1] + 900) + 8); iVar5 != 0;
                  iVar5 = *(int *)(iVar5 + 8)) {
                iVar8 = *(int *)(*(int *)(iVar6 + 0x98) + 8);
                if (iVar8 != 0) {
                  candidateByteOffset = candidateCount * 0x2c;
                  iVar5 = *(int *)(iVar6 + 0x98);
                  do {
                    nextInstB = iVar8;
                    if ((*(uint *)(iVar5 + 0x14) & 1) != 0) {
                      if (atScanStart) {
                        nextInstB = *(int *)(instA + 8);
                        atScanStart = false;
                        iVar6 = iVar2;
                      }
                      else {
                        packable = OpcodeTraits__flag1WithoutFlag7(*(undefined4 *)(param_1[1] + 8),iVar5);
                        if (packable == 0) {
                          nextInstB = *(int *)(iVar5 + 8);
                        }
                        else {
                          candidateLimitHit = 0x3ff < candidateTotal;
                          candidateTotal = candidateTotal + 1;
                          if (candidateLimitHit) goto LAB_00146530;
                          newVecSize = vecSize;
                          grownDataC = vecData;
                          if ((vecSize <= candidateCount) && (newVecSize = candidateCount + 1, vecCapacity < newVecSize)) {
                            vecCapacity = (vecCapacity << 4) / 10;
                            if (vecCapacity < newVecSize) {
                              vecCapacity = newVecSize;
                            }
                            grownDataC = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
                            if (vecSize != 0) {
                              copyIndexF = 0;
                              copyOffsetB = 0;
                              do {
                                copyIndexF = copyIndexF + 1;
                                _memcpy(grownDataC + copyOffsetB,vecData + copyOffsetB,0x2c);
                                copyOffsetB = copyOffsetB + 0x2c;
                              } while (vecSize != copyIndexF);
                            }
                            Arena__free(arenaAt378,vecData);
                          }
                          buildResult = ((int (*)())PostPack__buildCandidate)(param_1,instA,iVar5,grownDataC + candidateByteOffset);
                          vecSize = newVecSize;
                          vecData = grownDataC;
                          if (buildResult == 0) {
                            nextInstB = *(int *)(iVar5 + 8);
                            atScanStart = false;
                          }
                          else {
                            nextInstB = *(int *)(iVar5 + 8);
                            candidateCount = candidateCount + 1;
                            candidateByteOffset = candidateByteOffset + 0x2c;
                            atScanStart = false;
                          }
                        }
                      }
                    }
                    iVar8 = *(int *)(nextInstB + 8);
                    iVar5 = nextInstB;
                  } while (*(int *)(nextInstB + 8) != 0);
                  iVar5 = *(int *)(iVar6 + 8);
                }
                iVar6 = iVar5;
              }
            }
            iVar5 = *(int *)(instA + 8);
          }
          iVar6 = *(int *)(iVar5 + 8);
          instA = iVar5;
        } while (*(int *)(iVar5 + 8) != 0);
        iVar5 = *(int *)(iVar2 + 8);
      }
      iVar6 = *(int *)(iVar5 + 8);
      iVar2 = iVar5;
    } while (*(int *)(iVar5 + 8) != 0);
LAB_00146530:
    do {
      if ((int)candidateCount < 1) goto LAB_00146538;
      bestIndex = 0xffffffff;
      bestScore = 0;
      scoreOffset = 0;
      scoreIndex = 0;
      scanData = vecData;
      do {
        newVecSizeB = vecSize;
        vecData = scanData;
        if ((vecSize <= scoreIndex) && (newVecSizeB = scoreIndex + 1, vecCapacity < newVecSizeB)) {
          vecCapacity = (vecCapacity << 4) / 10;
          if (vecCapacity < newVecSizeB) {
            vecCapacity = newVecSizeB;
          }
          vecData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
          if (vecSize != 0) {
            copyIndexG = 0;
            copyOffsetG = 0;
            do {
              copyIndexG = copyIndexG + 1;
              _memcpy(vecData + copyOffsetG,scanData + copyOffsetG,0x2c);
              copyOffsetG = copyOffsetG + 0x2c;
            } while (vecSize != copyIndexG);
          }
          Arena__free(arenaAt378,scanData);
        }
        candidateScore = ((int (*)())FUN_00143e40)(param_1,vecData + scoreOffset);
        if ((bestIndex == 0xffffffff) || (bestScore < candidateScore)) {
          bestIndex = scoreIndex;
          bestScore = candidateScore;
        }
        scoreIndex = scoreIndex + 1;
        scoreOffset = scoreOffset + 0x2c;
      } while (((int)scoreIndex < (int)candidateCount) && (vecSize = newVecSizeB, scanData = vecData, scoreIndex != 0x80));
      if ((bestIndex == 0xffffffff) || (bestScore < 0)) goto LAB_00146538;
      vecSize = newVecSizeB;
      if ((newVecSizeB <= bestIndex) && (vecSize = bestIndex + 1, vecCapacity < vecSize)) {
        vecCapacity = (vecCapacity << 4) / 10;
        if (vecCapacity < vecSize) {
          vecCapacity = vecSize;
        }
        grownDataB = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
        if (newVecSizeB != 0) {
          copyIndexF = 0;
          copyOffset = 0;
          do {
            copyIndexF = copyIndexF + 1;
            _memcpy(grownDataB + copyOffset,vecData + copyOffset,0x2c);
            copyOffset = copyOffset + 0x2c;
          } while (copyIndexF != newVecSizeB);
        }
        Arena__free(arenaAt378,vecData);
        vecData = grownDataB;
      }
      bestOffset = bestIndex * 0x2c;
      bestCandidate = (int *)(vecData + bestOffset);
      ((int (*)())FUN_0014532c)(param_1,bestCandidate);
      if (0x17 < param_1[2]) goto LAB_00146538;
      arenaPtr = param_1 + 3;
      keptCountB = 0;
      recordCount = param_1[4];
      if (recordCount != 0) {
        recordIndex = 0;
        curCount = recordCount;
        keptCount = keptCountB;
        while( true ) {
          if (curCount <= recordIndex) {
            minCapacity = recordIndex + 1;
            if ((uint)param_1[5] < minCapacity) {
              grownCapacityC = (uint)(param_1[5] << 4) / 10;
              param_1[5] = grownCapacityC;
              if (grownCapacityC < minCapacity) {
                param_1[5] = minCapacity;
              }
              oldData = param_1[6];
              allocation = Arena__alloc(*arenaPtr,param_1[5] * 0x2c);
              param_1[6] = allocation;
              if (param_1[4] != 0) {
                copyIndexG = 0;
                copyOffset = 0;
                do {
                  copySource = oldData + copyOffset;
                  copyIndexG = copyIndexG + 1;
                  copyDestB = param_1[6] + copyOffset;
                  copyOffset = copyOffset + 0x2c;
                  _memcpy(copyDestB,copySource,0x2c);
                } while (copyIndexG < (uint)param_1[4]);
              }
              Arena__free(*arenaPtr,oldData);
            }
            param_1[4] = minCapacity;
          }
          resultData = param_1[6];
          resultElement = recordIndex * 0x2c + resultData;
          keptCountB = keptCount;
          if ((*(int *)(resultElement + 0x24) != 0) && (keptCountB = keptCount + 1, keptCount < recordIndex)) {
            if ((uint)param_1[4] <= keptCount) {
              if ((uint)param_1[5] < keptCountB) {
                grownCapacityC = (uint)(param_1[5] << 4) / 10;
                param_1[5] = grownCapacityC;
                if (grownCapacityC < keptCountB) {
                  param_1[5] = keptCountB;
                }
                allocation3 = Arena__alloc(*arenaPtr,param_1[5] * 0x2c);
                param_1[6] = allocation3;
                if (param_1[4] != 0) {
                  copyIndexG = 0;
                  copyOffsetG = 0;
                  do {
                    copySourceB = resultData + copyOffsetG;
                    copyIndexG = copyIndexG + 1;
                    copyDest = param_1[6] + copyOffsetG;
                    copyOffsetG = copyOffsetG + 0x2c;
                    _memcpy(copyDest,copySourceB,0x2c);
                  } while (copyIndexG < (uint)param_1[4]);
                }
                Arena__free(*arenaPtr,resultData);
                resultData = param_1[6];
              }
              param_1[4] = keptCountB;
            }
            _memcpy(keptCount * 0x2c + resultData,resultElement,0x2c);
          }
          recordIndex = recordIndex + 1;
          if (recordCount == recordIndex) break;
          curCount = param_1[4];
          keptCount = keptCountB;
        }
      }
      if ((uint)param_1[5] < keptCountB) {
        grownCapacity = (uint)(param_1[5] << 4) / 10;
        param_1[5] = grownCapacity;
        if (grownCapacity < keptCountB) {
          param_1[5] = keptCountB;
        }
        oldData = param_1[6];
        allocation = Arena__alloc(*arenaPtr,param_1[5] * 0x2c);
        param_1[6] = allocation;
        if (param_1[4] != 0) {
          copyIndexD = 0;
          copyOffset = 0;
          do {
            copySource = oldData + copyOffset;
            copyIndexD = copyIndexD + 1;
            copyDestB = param_1[6] + copyOffset;
            copyOffset = copyOffset + 0x2c;
            _memcpy(copyDestB,copySource,0x2c);
          } while (copyIndexD < (uint)param_1[4]);
        }
        Arena__free(*arenaPtr,oldData);
      }
      param_1[4] = keptCountB;
      if (keptCountB != 0) {
        uVar15 = 0;
        do {
          minCapacityB = uVar15 + 1;
          if ((uint)param_1[4] <= uVar15) {
            if ((uint)param_1[5] < minCapacityB) {
              grownCapacityB = (uint)(param_1[5] << 4) / 10;
              param_1[5] = grownCapacityB;
              if (grownCapacityB < minCapacityB) {
                param_1[5] = minCapacityB;
              }
              oldData = param_1[6];
              allocation = Arena__alloc(*arenaPtr,param_1[5] * 0x2c);
              param_1[6] = allocation;
              if (param_1[4] != 0) {
                copyIndexE = 0;
                copyOffset = 0;
                do {
                  copySource = oldData + copyOffset;
                  copyIndexE = copyIndexE + 1;
                  copyDestB = param_1[6] + copyOffset;
                  copyOffset = copyOffset + 0x2c;
                  _memcpy(copyDestB,copySource,0x2c);
                } while (copyIndexE < (uint)param_1[4]);
              }
              Arena__free(*arenaPtr,oldData);
            }
            param_1[4] = minCapacityB;
          }
          *(undefined4 *)(uVar15 * 0x2c + param_1[6] + 0x28) = 0;
          uVar15 = minCapacityB;
        } while (minCapacityB < keptCountB);
      }
      newVecSizeC = vecSize;
      grownData = vecData;
      if ((vecSize <= bestIndex) && (newVecSizeC = bestIndex + 1, vecCapacity < newVecSizeC)) {
        vecCapacity = (vecCapacity << 4) / 10;
        if (vecCapacity < newVecSizeC) {
          vecCapacity = newVecSizeC;
        }
        grownData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
        if (vecSize != 0) {
          copyIndexD = 0;
          copyOffsetF = 0;
          do {
            copyIndexD = copyIndexD + 1;
            _memcpy(grownData + copyOffsetF,vecData + copyOffsetF,0x2c);
            copyOffsetF = copyOffsetF + 0x2c;
          } while (copyIndexD != vecSize);
        }
        Arena__free(arenaAt378,vecData);
        bestCandidate = (int *)(grownData + bestOffset);
      }
      replacementInst = *bestCandidate;
      vecSize = newVecSizeC;
      vecData = grownData;
      if ((newVecSizeC <= bestIndex) && (vecSize = bestIndex + 1, vecCapacity < vecSize)) {
        vecCapacity = (vecCapacity << 4) / 10;
        if (vecCapacity < vecSize) {
          vecCapacity = vecSize;
        }
        vecData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
        if (newVecSizeC != 0) {
          copyIndexD = 0;
          copyOffsetF = 0;
          do {
            copyIndexD = copyIndexD + 1;
            _memcpy(vecData + copyOffsetF,grownData + copyOffsetF,0x2c);
            copyOffsetF = copyOffsetF + 0x2c;
          } while (copyIndexD != newVecSizeC);
        }
        Arena__free(arenaAt378,grownData);
        bestCandidate = (int *)(vecData + bestOffset);
      }
      replacedInst = bestCandidate[1];
      newVecSizeC = vecSize;
      grownData = vecData;
      if ((vecSize <= bestIndex) && (newVecSizeC = bestIndex + 1, vecCapacity < newVecSizeC)) {
        vecCapacity = (vecCapacity << 4) / 10;
        if (vecCapacity < newVecSizeC) {
          vecCapacity = newVecSizeC;
        }
        grownData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
        if (vecSize != 0) {
          copyIndexD = 0;
          copyOffsetG = 0;
          do {
            copyIndexD = copyIndexD + 1;
            _memcpy(copyOffsetG + grownData,copyOffsetG + vecData,0x2c);
            copyOffsetG = copyOffsetG + 0x2c;
          } while (copyIndexD != vecSize);
        }
        Arena__free(arenaAt378,vecData);
        bestCandidate = (int *)(grownData + bestOffset);
      }
      if (bestCandidate[4] != 0) {
        vecSize = newVecSizeC;
        vecData = grownData;
        if ((newVecSizeC <= bestIndex) && (vecSize = bestIndex + 1, vecCapacity < vecSize)) {
          vecCapacity = (vecCapacity << 4) / 10;
          if (vecCapacity < vecSize) {
            vecCapacity = vecSize;
          }
          vecData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
          if (newVecSizeC != 0) {
            copyIndexD = 0;
            copyOffsetF = 0;
            do {
              copyIndexD = copyIndexD + 1;
              _memcpy(copyOffsetF + vecData,copyOffsetF + grownData,0x2c);
              copyOffsetF = copyOffsetF + 0x2c;
            } while (copyIndexD != newVecSizeC);
          }
          Arena__free(arenaAt378,grownData);
          bestCandidate = (int *)(vecData + bestOffset);
        }
        replacementInst = bestCandidate[1];
        newVecSizeC = vecSize;
        grownData = vecData;
        if ((vecSize <= bestIndex) && (newVecSizeC = bestIndex + 1, vecCapacity < newVecSizeC)) {
          vecCapacity = (vecCapacity << 4) / 10;
          if (vecCapacity < newVecSizeC) {
            vecCapacity = newVecSizeC;
          }
          grownData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
          if (vecSize != 0) {
            copyIndexD = 0;
            copyOffsetF = 0;
            do {
              copyIndexD = copyIndexD + 1;
              _memcpy(copyOffsetF + grownData,copyOffsetF + vecData,0x2c);
              copyOffsetF = copyOffsetF + 0x2c;
            } while (copyIndexD != vecSize);
          }
          Arena__free(arenaAt378,vecData);
          bestCandidate = (int *)(grownData + bestOffset);
        }
        replacedInst = *bestCandidate;
      }
      newVecSizeB = newVecSizeC;
      grownDataD = grownData;
      if ((newVecSizeC <= bestIndex) && (newVecSizeB = bestIndex + 1, vecCapacity < newVecSizeB)) {
        vecCapacity = (vecCapacity << 4) / 10;
        if (vecCapacity < newVecSizeB) {
          vecCapacity = newVecSizeB;
        }
        grownDataD = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
        if (newVecSizeC != 0) {
          copyIndexB = 0;
          copyOffsetD = 0;
          do {
            copyIndexB = copyIndexB + 1;
            _memcpy(copyOffsetD + grownDataD,copyOffsetD + grownData,0x2c);
            copyOffsetD = copyOffsetD + 0x2c;
          } while (copyIndexB != newVecSizeC);
        }
        Arena__free(arenaAt378,grownData);
        bestCandidate = (int *)(grownDataD + bestOffset);
      }
      lastIndex = candidateCount - 1;
      vecSize = newVecSizeB;
      vecData = grownDataD;
      if ((newVecSizeB <= lastIndex) && (vecSize = candidateCount, vecCapacity < candidateCount)) {
        vecCapacity = (vecCapacity << 4) / 10;
        if (vecCapacity < candidateCount) {
          vecCapacity = candidateCount;
        }
        vecData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
        if (newVecSizeB != 0) {
          copyIndex = 0;
          copyOffsetC = 0;
          do {
            copyIndex = copyIndex + 1;
            _memcpy(copyOffsetC + vecData,copyOffsetC + grownDataD,0x2c);
            copyOffsetC = copyOffsetC + 0x2c;
          } while (copyIndex != newVecSizeB);
        }
        Arena__free(arenaAt378,grownDataD);
      }
      lastOffset = lastIndex * 0x2c;
      _memcpy(bestCandidate,lastOffset + vecData,0x2c);
      if ((int)lastIndex < 1) goto LAB_00146538;
      scanIndex = 0;
      nextPairIndex = 1;
      do {
        candidateCount = vecSize;
        grownData = vecData;
        if ((vecSize <= scanIndex) && (candidateCount = nextPairIndex, vecCapacity < nextPairIndex)) {
          vecCapacity = (vecCapacity << 4) / 10;
          if (vecCapacity < nextPairIndex) {
            vecCapacity = nextPairIndex;
          }
          grownData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
          if (vecSize != 0) {
            copyIndexG = 0;
            copyOffsetG = 0;
            do {
              copyIndexG = copyIndexG + 1;
              _memcpy(grownData + copyOffsetG,vecData + copyOffsetG,0x2c);
              copyOffsetG = copyOffsetG + 0x2c;
            } while (copyIndexG != vecSize);
          }
          Arena__free(arenaAt378,vecData);
        }
        candidateOffset = scanIndex * 0x2c;
        candidateRecord = grownData + candidateOffset;
        candInstA = *(int *)(grownData + candidateOffset);
        uVar20 = candidateCount;
        grownDataD = grownData;
        if ((candidateCount <= scanIndex) && (uVar20 = nextPairIndex, vecCapacity < nextPairIndex)) {
          vecCapacity = (vecCapacity << 4) / 10;
          if (vecCapacity < nextPairIndex) {
            vecCapacity = nextPairIndex;
          }
          grownDataD = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
          if (candidateCount != 0) {
            copyIndexB = 0;
            copyOffsetD = 0;
            do {
              copyIndexB = copyIndexB + 1;
              _memcpy(grownDataD + copyOffsetD,grownData + copyOffsetD,0x2c);
              copyOffsetD = copyOffsetD + 0x2c;
            } while (copyIndexB != candidateCount);
          }
          Arena__free(arenaAt378,grownData);
          candidateRecord = grownDataD + candidateOffset;
        }
        if (replacedInst == candInstA) {
          candInstA = replacementInst;
        }
        iVar2 = *(int *)(candidateRecord + 4);
        if (replacedInst == *(int *)(candidateRecord + 4)) {
          iVar2 = replacementInst;
        }
        vecSize = uVar20;
        vecData = grownDataD;
        if (candInstA == iVar2) {
LAB_001463fc:
          lastScanIndex = scanIndex - 1;
          nextPairIndex = nextPairIndex - 1;
          uVar16 = vecSize;
          iVar2 = vecData;
          if ((vecSize <= scanIndex) && (uVar16 = scanIndex + 1, vecCapacity < uVar16)) {
            vecCapacity = (vecCapacity << 4) / 10;
            if (vecCapacity < uVar16) {
              vecCapacity = uVar16;
            }
            iVar2 = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
            if (vecSize != 0) {
              copyIndex = 0;
              copyOffsetG = 0;
              do {
                copyIndex = copyIndex + 1;
                _memcpy(iVar2 + copyOffsetG,vecData + copyOffsetG,0x2c);
                copyOffsetG = copyOffsetG + 0x2c;
              } while (copyIndex != vecSize);
            }
            Arena__free(arenaAt378,vecData);
            candidateRecord = iVar2 + candidateOffset;
          }
          candidateCount = lastIndex - 1;
          lastOffset = lastOffset + -0x2c;
          vecSize = uVar16;
          vecData = iVar2;
          if ((uVar16 <= candidateCount) && (vecSize = lastIndex, vecCapacity < lastIndex)) {
            vecCapacity = (vecCapacity << 4) / 10;
            if (vecCapacity < lastIndex) {
              vecCapacity = lastIndex;
            }
            vecData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
            if (uVar16 != 0) {
              copyIndexC = 0;
              copyOffsetG = 0;
              do {
                copyIndexC = copyIndexC + 1;
                _memcpy(vecData + copyOffsetG,iVar2 + copyOffsetG,0x2c);
                copyOffsetG = copyOffsetG + 0x2c;
              } while (copyIndexC != uVar16);
            }
            Arena__free(arenaAt378,iVar2);
          }
          _memcpy(candidateRecord,lastOffset + vecData,0x2c);
        }
        else {
          if ((uVar20 <= scanIndex) && (vecSize = nextPairIndex, vecCapacity < nextPairIndex)) {
            vecCapacity = (vecCapacity << 4) / 10;
            if (vecCapacity < nextPairIndex) {
              vecCapacity = nextPairIndex;
            }
            vecData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
            if (uVar20 != 0) {
              copyIndex = 0;
              copyOffsetE = 0;
              do {
                copyIndex = copyIndex + 1;
                _memcpy(vecData + copyOffsetE,grownDataD + copyOffsetE,0x2c);
                copyOffsetE = copyOffsetE + 0x2c;
              } while (copyIndex != uVar20);
            }
            Arena__free(arenaAt378,grownDataD);
            candidateRecord = vecData + candidateOffset;
          }
          iVar2 = ((int (*)())PostPack__buildCandidate)(param_1,candInstA,iVar2,candidateRecord);
          candidateCount = lastIndex;
          lastScanIndex = scanIndex;
          if (iVar2 == 0) goto LAB_001463fc;
        }
        scanIndex = lastScanIndex + 1;
        nextPairIndex = nextPairIndex + 1;
        lastIndex = candidateCount;
      } while ((int)scanIndex < (int)candidateCount);
    } while( true );
  }
LAB_0014653c:
  Program__beginPass(iVar2,(int)"post_pack_insts");
  Arena__free(arenaAt378,vecData);
  return;
LAB_00146538:
  iVar2 = param_1[1];
  goto LAB_0014653c;
}

/* FUN_0014657c @ 0x14657c (92 bytes) */
int FUN_0014657c(param_1)
  int param_1;
{
  int local_38 [3];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_38[0] = *(int *)(param_1 + 8);
  local_2c = *(undefined4 *)(local_38[0] + 0x378);
  local_28 = 0;
  local_24 = 0x10;
  local_20 = Arena__alloc(local_2c,0x2c0);
  ((int (*)())FUN_00140e5c)(local_38,param_1);
  ((int (*)())pass_post_pack_insts)(local_38);
  return Arena__free(local_2c,local_20);
}

/* IRInst__getOperandSourceOrDefault @ 0x146610 (20 bytes) */
int IRInst__getOperandSourceOrDefault(inst, operandIndex, param_3)
  int inst;
  undefined4 operandIndex;
  undefined4 param_3;
{
  undefined4 callResult;
  
  if (inst != 0) {
    callResult = IRInst__getOperandSource(inst,operandIndex);
    return callResult;
  }
  return param_3;
}

/* FUN_00146624 @ 0x146624 (76 bytes) */
int FUN_00146624(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  unsigned int ghidra_home[8] = { param_1, param_2, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  char *pcVar2;
  int countdown;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 0)) = param_1;
  countdown = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  pcVar1 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  pcVar2 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 0));
  while ((*pcVar1 != '\x01' || (*pcVar2 == '\x04'))) {
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
    countdown = countdown + -1;
    if (countdown == 0) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00146670 @ 0x146670 (132 bytes) */
int FUN_00146670(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  int param_3;
  int param_4;
{
  code *UNRECOVERED_JUMPTABLE;
  int vcall5cResult;
  int *piVar2;
  undefined4 uVar3;
  
  vcall5cResult = (**(code **)(*param_2 + 0x5c))(param_2,param_2,param_3,param_4);
  if ((vcall5cResult == 0) && (param_3 == 0)) {
    piVar2 = *(int **)(param_4 + 0x30c);
    UNRECOVERED_JUMPTABLE = *(code **)(*piVar2 + 0x100);
  }
  else {
    piVar2 = *(int **)(param_4 + 0x30c);
    UNRECOVERED_JUMPTABLE = *(code **)(*piVar2 + 0x108);
  }
                    
                    
  uVar3 = (*UNRECOVERED_JUMPTABLE)(piVar2,param_1);
  return uVar3;
}

/* IRInst__getOperandSourceThroughMix @ 0x1466f4 (104 bytes) */
int IRInst__getOperandSourceThroughMix(inst, operandIndex)
  undefined4 inst;
  undefined4 operandIndex;
{
  int *operandVReg;
  int vcall60Result;
  
  operandVReg = (int *)IRInst__getOperandSource(inst,operandIndex);
  vcall60Result = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (vcall60Result != 0) {
    operandVReg = (int *)IRInst__getOperandSource(operandVReg,1);
    return operandVReg;
  }
  return operandVReg;
}

/* FUN_0014675c @ 0x14675c (44 bytes) */
int FUN_0014675c(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((*(int *)(param_1 + 0x120) == *(int *)(param_2 + 0x120)) &&
     (*(int *)(param_1 + 0x124) == *(int *)(param_2 + 0x124))) {
    return 1;
  }
  return 0;
}

/* FUN_00146788 @ 0x146788 (96 bytes) */
int FUN_00146788(obj, program)
  int obj;
  undefined4 program;
{
  int callResult;
  undefined4 uVar2;
  
  callResult = IRInst__hasSingleUse(obj,program);
  if ((((callResult == 0) || (*(int *)(obj + 0x120) != 0)) || (*(int *)(obj + 0x124) != 0)) ||
     (uVar2 = 1, (*(uint *)(obj + 0x14) & 0x200) != 0)) {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_001467e8 @ 0x1467e8 (128 bytes) */
int FUN_001467e8(param_1, param_2)
  int param_1;
  int param_2;
{
  int vcall24Result;
  int isOpcodeInSet139344Result;
  int *piVar2;
  int *piVar3;
  
  isOpcodeInSet139344Result = ((int (*)())IRInst__isOpcodeInSet139344)(param_1);
  if (isOpcodeInSet139344Result != 0) {
    piVar2 = *(int **)(param_2 + 0x3a0);
    for (piVar3 = *(int **)(param_1 + 0x158); piVar2 != piVar3; piVar3 = (int *)piVar3[0x3c]) {
      vcall24Result = (**(code **)(*piVar3 + 0x24))(piVar3);
      if (vcall24Result != 0) {
        return 0;
      }
    }
  }
  return 1;
}

/* FUN_00146868 @ 0x146868 (228 bytes) */
int FUN_00146868(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  undefined4 param_3;
{
  int vcall1cResult;
  int *piVar1;
  int vcall34Result;
  
  piVar1 = (int *)param_2[0x56];
  if (piVar1 == (int *)param_1[0x56]) {
    do {
      param_2 = (int *)param_2[1];
      vcall34Result = (**(code **)(*param_2 + 0x34))(param_2);
      if (vcall34Result != 0) {
        return 0;
      }
    } while (param_2 != param_1);
  }
  else {
    vcall1cResult = (**(code **)(*piVar1 + 0x1c))(piVar1);
    if (vcall1cResult != 0) {
      return 0;
    }
    FUN_000ec4f0(param_3);
    piVar1 = *(int **)(param_2[0x56] + 0xf0);
    if (piVar1 != (int *)param_1[0x56]) {
      do {
        vcall1cResult = (**(code **)(*piVar1 + 0x1c))(piVar1);
        if (vcall1cResult != 0) {
          return 0;
        }
        piVar1 = (int *)piVar1[0x3c];
      } while (piVar1 != (int *)param_1[0x56]);
    }
  }
  return 1;
}

