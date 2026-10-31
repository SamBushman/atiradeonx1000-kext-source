#include "decls.h"

/* Inst__allUsesCounted @ 0x14694c (80 bytes) */
int Inst__allUsesCounted(inst, program, requireAllUses)
  int inst;
  undefined4 program;
  int requireAllUses;
{
  int useCountResult;
  
  if ((requireAllUses != 0) &&
     (useCountResult = IRInst__useCount(inst,program), useCountResult != *(int *)(*(int *)(inst + 0x10) + 4))) {
    return 0;
  }
  return 1;
}

/* Use__negationParityEqual @ 0x14699c (368 bytes) */
int Use__negationParityEqual(useA, useB)
  int *useA;
  int *useB;
{
  int sourceDef2;
  int sourceDef;
  int signOtherOperandA;
  int signOtherOperandB;
  int signUseOperandA;
  int signUseOperandB;
  uint vectorFilledCount;
  uint vectorFilledCount2;
  int signSource2A;
  int signSource2B;
  int signSource1A;
  int signSource1B;
  
  signSource1A = -1;
  sourceDef = IRInst__getOperandSource(*useA,useA[1]);
  if ((*(uint *)(sourceDef + 0xb8) & 1) == 0) {
    signSource1A = 1;
  }
  sourceDef = IRInst__getOperandSource(*useA,useA[1]);
  signSource2A = -1;
  if ((*(uint *)(sourceDef + 0xd0) & 1) == 0) {
    signSource2A = 1;
  }
  vectorFilledCount = useA[1];
  signUseOperandA = -1;
  if ((*(uint *)(vectorFilledCount * 0x18 + *useA + 0xa0) & 1) == 0) {
    signUseOperandA = 1;
  }
  signOtherOperandA = -1;
  if ((*(uint *)((vectorFilledCount + (((int)vectorFilledCount >> 1) + (uint)((int)vectorFilledCount < 0 && (vectorFilledCount & 1) != 0)) * -2) *
                 0x18 + *useA + 0xb8) & 1) == 0) {
    signOtherOperandA = 1;
  }
  sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
  signSource1B = -1;
  if ((*(uint *)(sourceDef2 + 0xb8) & 1) == 0) {
    signSource1B = 1;
  }
  sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
  signSource2B = -1;
  if ((*(uint *)(sourceDef2 + 0xd0) & 1) == 0) {
    signSource2B = 1;
  }
  vectorFilledCount2 = useB[1];
  signUseOperandB = -1;
  if ((*(uint *)(vectorFilledCount2 * 0x18 + *useB + 0xa0) & 1) == 0) {
    signUseOperandB = 1;
  }
  signOtherOperandB = -1;
  if ((*(uint *)((vectorFilledCount2 + (((int)vectorFilledCount2 >> 1) + (uint)((int)vectorFilledCount2 < 0 && (vectorFilledCount2 & 1) != 0)) * -2) *
                 0x18 + *useB + 0xb8) & 1) == 0) {
    signOtherOperandB = 1;
  }
  return signOtherOperandA * signUseOperandA * signSource1A * signSource2A == signOtherOperandB * signUseOperandB * signSource1B * signSource2B;
}

/* Inst__findDeepestChain @ 0x146b0c (460 bytes) */
int Inst__findDeepestChain(inst, depth, chainOpcode, pass, outDeepestInst, outDeepestDepth)
  int inst;
  int depth;
  int chainOpcode;
  undefined4 pass;
  int *outDeepestInst;
  int *outDeepestDepth;
{
  int sourceDef;
  int secondDepth;
  int operandVReg;
  int checkResult;
  int firstDepth;
  int nextDepth;
  
  nextDepth = depth + 1;
  sourceDef = IRInst__getOperandSource(inst,1);
  operandVReg = IRInst__getOperandSource(inst,2);
  if ((nextDepth == 1) && (chainOpcode == 0x14)) {
    chainOpcode = 0x13;
  }
  firstDepth = nextDepth;
  if (sourceDef != operandVReg) {
    if ((((*(int *)(*(int *)(sourceDef + 0x88) + 8) == chainOpcode) &&
         (checkResult = Inst__isPlainSingleUse(sourceDef,pass), checkResult != 0)) &&
        ((*(uint *)(inst + 0xb8) & 1) == 0)) &&
       ((((*(uint *)(inst + 0xb8) & 2) == 0 && (checkResult = IRInst__getDefiningField128(inst,1), checkResult == 0)) &&
        (*(int *)(inst + 0x158) == *(int *)(sourceDef + 0x158))))) {
      firstDepth = ((int (*)())Inst__findDeepestChain)(sourceDef,nextDepth,chainOpcode,pass,outDeepestInst,outDeepestDepth);
    }
    secondDepth = nextDepth;
    if (((*(int *)(*(int *)(operandVReg + 0x88) + 8) == chainOpcode) &&
        (checkResult = Inst__isPlainSingleUse(operandVReg,pass), checkResult != 0)) &&
       (((*(uint *)(inst + 0xd0) & 1) == 0 &&
        ((((*(uint *)(inst + 0xd0) & 2) == 0 && (checkResult = IRInst__getDefiningField128(inst,2), checkResult == 0)) &&
         (*(int *)(inst + 0x158) == *(int *)(operandVReg + 0x158))))))) {
      secondDepth = ((int (*)())Inst__findDeepestChain)(operandVReg,nextDepth,chainOpcode,pass,outDeepestInst,outDeepestDepth);
    }
    if ((nextDepth != firstDepth) || (nextDepth != secondDepth)) {
      if (firstDepth < secondDepth) {
        *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) | 0x4000;
        return secondDepth;
      }
      goto storeInst;
    }
  }
  if (nextDepth <= *outDeepestDepth) {
    return *outDeepestDepth;
  }
  *outDeepestInst = inst;
  *outDeepestDepth = nextDepth;
storeInst:
  *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) & 0xffffbfff;
  return firstDepth;
}

/* Use__sourceIsPlainSingleUse @ 0x146cd8 (264 bytes) */
int Use__sourceIsPlainSingleUse(use, program, staleArg3, staleArg4, staleArg5, staleArg6, staleArg7)
  int *use;
  undefined4 program;
  undefined4 staleArg3;
  undefined4 staleArg4;
  undefined4 staleArg5;
  undefined4 staleArg6;
  undefined4 staleArg7;
{
  uint sourceHasResultModifier;
  int operandVReg;
  int useCheck;
  uint sourceIsReusable;
  uint useIndexReg;
  
  operandVReg = IRInst__getOperandSource(*use,use[1]);
  if (((*(uint *)(operandVReg + 0x14) & 0x200) == 0) &&
     ((useCheck = IRInst__hasSingleUse(operandVReg,program), useCheck != 0 ||
      (useCheck = IRInst__hasNoUses(operandVReg,program,staleArg3,staleArg4,staleArg5,staleArg6,staleArg7), useCheck != 0)))) {
    sourceIsReusable = 1;
  }
  else {
    sourceIsReusable = 0;
  }
  useIndexReg = use[1];
  if (*(int *)(*(int *)(operandVReg + 0x88) + 8) == 0x12) {
    if ((*(int *)(operandVReg + 0x120) != 0) || (sourceHasResultModifier = 0, *(int *)(operandVReg + 0x124) != 0)) {
      sourceHasResultModifier = 1;
    }
  }
  else {
    sourceHasResultModifier = *(uint *)(operandVReg + 0x120);
  }
  return (sourceHasResultModifier ^ 1) &
         (*(uint *)((useIndexReg + (((int)useIndexReg >> 1) + (uint)((int)useIndexReg < 0 && (useIndexReg & 1) != 0)) * -2)
                    * 0x18 + *use + 0xb8) >> 1 & 1 ^ 1) &
         (*(uint *)(useIndexReg * 0x18 + *use + 0xa0) >> 1 & 1 ^ 1) & sourceIsReusable;
}

/* Inst__opcodeOrSourcesDiffer @ 0x146de0 (252 bytes) */
int Inst__opcodeOrSourcesDiffer(inst, inst2)
  int *inst;
  int *inst2;
{
  int vcall14Result;
  int vcall5cResult;
  int callResult;
  int operandVReg;
  int loopIndex;
  
  vcall5cResult = (**(code **)(*inst + 0x5c))(inst,inst2);
  if ((vcall5cResult != 0) && (vcall5cResult = (**(code **)(*inst2 + 0x5c))(inst2), vcall5cResult != 0)) {
    vcall14Result = (**(code **)(*inst + 0x14))(inst);
    if (*(int *)(inst[0x22] + 8) != *(int *)(inst2[0x22] + 8)) {
      return 1;
    }
    (**(code **)(*inst2 + 0x14))(inst2);
    if (0 < vcall14Result) {
      loopIndex = 1;
      do {
        callResult = IRInst__getOperandSource(inst,loopIndex);
        operandVReg = IRInst__getOperandSource(inst2,loopIndex);
        if (callResult != operandVReg) {
          return 1;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= vcall14Result);
    }
  }
  return 0;
}

/* Inst__sameOpcodeAndSources @ 0x146edc (304 bytes) */
int Inst__sameOpcodeAndSources(inst, inst2)
  int *inst;
  int *inst2;
{
  int vcall14Result;
  int sourceDef2;
  int sourceDef;
  int vcall5cResult;
  int vcall14ResultB;
  
  vcall5cResult = (**(code **)(*inst + 0x5c))(inst,inst2);
  if (((vcall5cResult != 0) && (vcall5cResult = (**(code **)(*inst2 + 0x5c))(inst2), vcall5cResult != 0)) &&
     (*(int *)(inst[0x22] + 8) == *(int *)(inst2[0x22] + 8))) {
    vcall14Result = (**(code **)(*inst + 0x14))(inst);
    vcall14ResultB = (**(code **)(*inst2 + 0x14))(inst2);
    if (vcall14Result == vcall14ResultB) {
      sourceDef = IRInst__getOperandSource(inst,1);
      sourceDef2 = IRInst__getOperandSource(inst2,1);
      if (sourceDef == sourceDef2) {
        vcall14Result = (**(code **)(*inst + 0x14))(inst);
        if (vcall14Result == 2) {
          sourceDef = IRInst__getOperandSource(inst,2);
          sourceDef2 = IRInst__getOperandSource(inst2,2);
          if (sourceDef != sourceDef2) {
            return 0;
          }
        }
        return 1;
      }
    }
  }
  return 0;
}

/* Inst__sameOrEquivalentSource @ 0x14700c (56 bytes) */
int Inst__sameOrEquivalentSource(sourceA, sourceB)
  int sourceA;
  int sourceB;
{
  int callResult;
  
  if ((sourceA != sourceB) && (callResult = ((int (*)())Inst__sameOpcodeAndSources)(sourceA,sourceB), callResult == 0)) {
    return 0;
  }
  return 1;
}

/* Inst__sourcesRelated @ 0x147044 (152 bytes) */
int Inst__sourcesRelated(sourceA, sourceB)
  int *sourceA;
  int *sourceB;
{
  undefined4 related;
  undefined4 callResult;
  int vcall5cResult;
  
  related = 1;
  if (sourceA != sourceB) {
    vcall5cResult = (**(code **)(*sourceA + 0x5c))(sourceA);
    if ((vcall5cResult != 0) && (vcall5cResult = (**(code **)(*sourceB + 0x5c))(sourceB), vcall5cResult != 0)) {
      callResult = ((int (*)())Inst__sameOpcodeAndSources)(sourceA,sourceB);
      return callResult;
    }
    related = 0;
  }
  return related;
}

/* Inst__canFuseAddMul @ 0x1470dc (348 bytes) */
int Inst__canFuseAddMul(inst, program, requireSingleUse)
  int inst;
  undefined4 program;
  int requireSingleUse;
{
  bool firstOperandFusable;
  bool secondOperandFusable;
  undefined4 canFuse;
  int operandVReg;
  int operandVReg2;
  int sourceLanesAllWrittenResult;
  int operandOpcode;
  
  canFuse = 0;
  if (*(int *)(*(int *)(inst + 0x88) + 8) == 0x12) {
    operandVReg = IRInst__getOperandSource(inst,1);
    operandVReg2 = IRInst__getOperandSource(inst,2);
    operandOpcode = *(int *)(*(int *)(operandVReg2 + 0x88) + 8);
    if (((((*(int *)(*(int *)(operandVReg + 0x88) + 8) == 0x13) && ((*(uint *)(inst + 0xb8) & 2) == 0))
         && (sourceLanesAllWrittenResult = IRInst__sourceLanesAllWritten(inst,1), sourceLanesAllWrittenResult != 0)) &&
        ((*(int *)(operandVReg + 0x120) == 0 && (*(int *)(operandVReg + 0x124) == 0)))) &&
       ((requireSingleUse == 0 || (operandVReg = IRInst__hasSingleUse(operandVReg,program), operandVReg != 0)))) {
      firstOperandFusable = true;
    }
    else {
      firstOperandFusable = false;
    }
    if ((((operandOpcode == 0x13) && ((*(uint *)(inst + 0xd0) & 2) == 0)) &&
        ((operandVReg = IRInst__sourceLanesAllWritten(inst,2), operandVReg != 0 &&
         ((*(int *)(operandVReg2 + 0x120) == 0 && (*(int *)(operandVReg2 + 0x124) == 0)))))) &&
       ((requireSingleUse == 0 || (operandVReg = IRInst__hasSingleUse(operandVReg2,program), operandVReg != 0)))) {
      secondOperandFusable = true;
    }
    else {
      secondOperandFusable = false;
    }
    if ((firstOperandFusable) || (canFuse = 0, secondOperandFusable)) {
      canFuse = 1;
    }
  }
  return canFuse;
}

/* Inst__constantLanesAllowFusion @ 0x147238 (352 bytes) */
int Inst__constantLanesAllowFusion(inst)
  int *inst;
{
  bool moreComponents;
  undefined4 operandIndex;
  int operandRecord2;
  bool sawNonZeroLane;
  int operandRecord;
  int *a0;
  int operandCountOrCheck;
  undefined4 result;
  int loopIndex;
  uint sourceLane;
  
  if (*(int *)(inst[0x22] + 8) == 0x12) {
    loopIndex = 0;
    do {
      operandRecord = IRInst__getOperandRecord(inst,0);
      if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
        sawNonZeroLane = false;
        for (operandRecord = 1; operandCountOrCheck = (**(code **)(*inst + 0x14))(inst), operandRecord <= operandCountOrCheck;
            operandRecord = operandRecord + 1) {
          operandRecord2 = IRInst__getOperandRecord(inst,operandRecord);
          sourceLane = (uint)*(byte *)(loopIndex + operandRecord2 + 0x10);
          a0 = (int *)IRInst__getOperandSource(inst,operandRecord);
          operandCountOrCheck = (**(code **)(*a0 + 0x60))(a0);
          if (operandCountOrCheck != 0) {
            operandIndex = IRInst__firstOperandWithSelectNot4(a0,sourceLane);
            operandCountOrCheck = IRInst__getOperandRecord(a0,operandIndex);
            sourceLane = (uint)*(byte *)(sourceLane + operandCountOrCheck + 0x10);
            a0 = (int *)IRInst__getOperandSource(a0,operandIndex);
          }
          if ((((int)*(char *)(a0 + 0x57) >> (sourceLane & 0x3f) & 1U) == 0) ||
             (GH_U2F((unsigned int)(a0[sourceLane * 6 + 8])) != 0.0)) {
            if (sawNonZeroLane) goto setResult;
            sawNonZeroLane = true;
          }
        }
      }
      moreComponents = loopIndex != 3;
      loopIndex = loopIndex + 1;
    } while (moreComponents);
    result = 1;
  }
  else {
setResult:
    result = 0;
  }
  return result;
}

/* IRInst__isOpcodeInSet147398 @ 0x147398 (120 bytes) */
int IRInst__isOpcodeInSet147398(inst)
  int inst;
{
  int callResult;
  
  callResult = ((int (*)())Inst__constantLanesAllowFusion)(inst);
  if (callResult != 0) {
LAB_001474b4:
    return 1;
  }
  switch(*(undefined4 *)(*(int *)(inst + 0x88) + 8)) {
  case 0x13:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x31:
  case 0x3e:
  case 0x3f:
  case 0x40:
    goto LAB_001474b4;
  default:
    return 0;
  }
}

/* Inst__hoistToOperandBlock @ 0x1474c8 (572 bytes) */
int Inst__hoistToOperandBlock(ctx, inst, scheduleCtx)
  undefined4 ctx;
  int *inst;
  uint scheduleCtx;
{
  int operandSource;
  int vcall2cResult;
  int vcall68Result;
  int operandCount2;
  int operandCount;
  int operandIndex3;
  int operandIndex2;
  int afterInst;
  int operandIndex;
  int *blockWalkNext;
  int *blockWalkCur;
  int nextInstLink;
  int retR4;
  int operandIndexReg;
  int *a0;
  int nextInstCursor;
  int **operandBlockCursor;
  int operandByteOffset;
  int *block;
  undefined8 operandVReg;
  int operandBlockPad;
  int *operandBlocks [11];
  
  if ((*(int *)(inst[0x22] + 8) != 0x8e) &&
     (vcall68Result = (**(code **)(*inst + 0x68))(inst,inst,scheduleCtx), vcall68Result == 0)) {
    operandCount = inst[0x21];
    if ((operandCount != 0) && ((inst[5] & 8U) == 0)) {
      a0 = (int *)inst[0x56];
      operandIndexReg = retR4;
      if (0 < operandCount) {
        operandIndex2 = 1;
        operandBlockCursor = operandBlocks;
        do {
          operandVReg = IRInst__getOperandSource(inst,operandIndex2);
          operandIndexReg = (int)operandVReg;
          operandIndex2 = operandIndex2 + 1;
          *operandBlockCursor = *(int **)((int)((ulonglong)operandVReg >> 0x20) + 0x158);
          operandBlockCursor = operandBlockCursor + 1;
          operandCount = inst[0x21];
        } while (operandIndex2 <= operandCount);
      }
      blockWalkNext = a0;
      block = a0;
      do {
        blockWalkCur = blockWalkNext;
        if (0 < operandCount) {
          operandIndexReg = 1;
          if (blockWalkCur == operandBlocks[0]) {
            operandByteOffset = 4;
          }
          else {
            do {
              operandIndexReg = operandIndexReg + 1;
              if (operandCount < operandIndexReg) goto setBlock;
              operandByteOffset = operandIndexReg * 4;
            } while (blockWalkCur != (int *)(&operandBlockPad)[operandIndexReg]);
          }
          a0 = *(int **)((int)&operandBlockPad + operandByteOffset);
          operandIndex3 = operandIndexReg;
          if (operandIndexReg != 0) goto setVcall2cResult;
        }
setBlock:
        block = blockWalkCur;
      } while ((blockWalkCur != (int *)0x0) &&
              (blockWalkNext = (int *)blockWalkCur[0x3c], (int *)blockWalkCur[0x3c] != (int *)0x0));
      operandIndex3 = 0;
setVcall2cResult:
      vcall2cResult = (**(code **)(*a0 + 0x2c))(a0,operandIndexReg,scheduleCtx);
      if (vcall2cResult != 0) {
        IRInst__unlinkAndClearFlag0(inst);
        inst[5] = inst[5] | 1;
        Block__prependInst(block,inst);
        return;
      }
      IRInst__getOperandSource(inst,operandIndex3);
      nextInstLink = *(int *)(a0[0x28] + 4);
      if (nextInstLink != 0) {
        operandCount2 = inst[0x21];
        afterInst = a0[0x28];
        do {
          nextInstCursor = nextInstLink;
          if (0 < operandCount2) {
            operandIndex = 1;
            do {
              operandSource = IRInst__getOperandSource(inst,operandIndex);
              if ((operandSource == afterInst) || (*(int *)(*(int *)(afterInst + 0x88) + 8) == 0x8e)) {
                IRInst__unlinkAndClearFlag0(inst);
                inst[5] = inst[5] | 1;
                Block__insertInstAfter(a0,afterInst,inst);
                return;
              }
              operandCount2 = inst[0x21];
              operandIndex = operandIndex + 1;
            } while (operandIndex <= operandCount2);
          }
          nextInstLink = *(int *)(nextInstCursor + 4);
          afterInst = nextInstCursor;
        } while (nextInstLink != 0);
      }
    }
  }
  return;
}

/* Inst__deleteMergedSources @ 0x147704 (756 bytes) */
int Inst__deleteMergedSources(inst, inst2, inst3, pass)
  undefined4 inst;
  int inst2;
  int inst3;
  int pass;
{
  int vcall48Result;
  int vcall64Result;
  int sourceOpcode;
  int opcodeInfo;
  int *operandVReg;
  int *operandVReg2;
  int a3;
  undefined4 staleArg7;
  undefined4 staleArg8;
  int distinctSourceCount;
  int loopIndex;
  int *sourceCursor;
  int *a0;
  bool firstTwoSourcesEqual;
  int distinctSources [6];
  
  a3 = pass;
  distinctSources[1] = IRInst__getOperandSource(inst,1);
  distinctSources[0] = distinctSources[1];
  if (inst2 != 0) {
    distinctSources[1] = IRInst__getOperandSource(inst2,1);
  }
  firstTwoSourcesEqual = distinctSources[1] == distinctSources[0];
  distinctSourceCount = -(uint)firstTwoSourcesEqual + 2;
  distinctSources[2] = distinctSources[0];
  if (inst3 != 0) {
    distinctSources[2] = IRInst__getOperandSource(inst3,1);
  }
  if (distinctSources[2] != distinctSources[1]) {
    if (distinctSourceCount == 1) {
      distinctSources[1] = distinctSources[2];
      goto setLoopIndex;
    }
    if (distinctSources[2] != distinctSources[0]) {
      distinctSourceCount = -(uint)firstTwoSourcesEqual + 3;
    }
  }
  if (distinctSourceCount < 1) {
    return;
  }
setLoopIndex:
  loopIndex = 0;
  sourceCursor = distinctSources;
  do {
    a0 = (int *)*sourceCursor;
    if (a0 != (int *)0x0) {
      sourceOpcode = *(int *)(a0[0x22] + 8);
      while ((sourceOpcode != 0x3a && (sourceOpcode != 0x3b))) {
        vcall64Result = (**(code **)(*a0 + 100))(a0);
        if (vcall64Result == 0) {
          opcodeInfo = a0[0x22];
          sourceOpcode = *(int *)(opcodeInfo + 8);
          if (sourceOpcode == 0x13) {
            operandVReg = (int *)IRInst__getOperandSource(a0,1);
            operandVReg2 = (int *)IRInst__getOperandSource(a0,2);
            vcall48Result = (**(code **)(*operandVReg + 0x48))(operandVReg);
            if (vcall48Result == 0) {
              IRInst__dropCounterAndDeleteIfUnused(operandVReg2,*(undefined4 *)(pass + 8));
            }
            else {
              IRInst__dropCounterAndDeleteIfUnused(operandVReg,*(undefined4 *)(pass + 8));
              operandVReg = operandVReg2;
            }
            (**(code **)(*a0 + 0xc))(a0,0,*(undefined4 *)(pass + 8));
            goto checkOperandVReg;
          }
          if ((sourceOpcode == 0x12) || (sourceOpcode == 0x9b)) {
            operandVReg = (int *)IRInst__getOperandSource(a0,1);
            (**(code **)(*a0 + 0xc))(a0,0,*(undefined4 *)(pass + 8));
            IRInst__dropCounterAndDeleteIfUnused(operandVReg,*(undefined4 *)(pass + 8));
            goto checkOperandVReg;
          }
        }
        else {
          operandVReg = (int *)IRInst__getOperandSource(a0,1);
          (**(code **)(*a0 + 0xc))
                    (a0,0,*(undefined4 *)(pass + 8),a3,staleArg7,staleArg8,*(code **)(*a0 + 0xc));
checkOperandVReg:
          if (operandVReg == (int *)0x0) goto setLoopIndex2;
          opcodeInfo = operandVReg[0x22];
          a0 = operandVReg;
        }
        sourceOpcode = *(int *)(opcodeInfo + 8);
      }
      if (((a0[5] & 0x200U) != 0) &&
         (operandVReg = (int *)IRInst__getOperandSource(a0,a0[0x21]), operandVReg != (int *)0x0)) {
        if (((operandVReg[5] & 0x200U) != 0) &&
           (operandVReg2 = (int *)IRInst__getOperandSource(operandVReg,operandVReg[0x21]), operandVReg2 != (int *)0x0)) {
          (**(code **)(*operandVReg2 + 0xc))(operandVReg2,0,*(undefined4 *)(pass + 8));
        }
        (**(code **)(*operandVReg + 0xc))(operandVReg,0,*(undefined4 *)(pass + 8));
      }
      (**(code **)(*a0 + 0xc))(a0,0,*(undefined4 *)(pass + 8));
    }
setLoopIndex2:
    loopIndex = loopIndex + 1;
    sourceCursor = sourceCursor + 1;
    if (distinctSourceCount == loopIndex) {
      return;
    }
  } while( true );
}

/* Inst__foldOutputScaleChain @ 0x1479f8 (404 bytes) */
int Inst__foldOutputScaleChain(inst, program)
  int inst;
  int program;
{
  int inst1;
  int hasSingleUse;
  bool firstScaleOk;
  bool secondScaleOk;
  int resultScaleCode;
  int *operandVReg;
  int *target;
  int vcall24Result;
  int saturate;
  int resultScaleCode2;
  
  firstScaleOk = true;
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  resultScaleCode2 = *(int *)(inst + 0x124);
  saturate = *(int *)(inst + 0x120);
  secondScaleOk = true;
  while( true ) {
    vcall24Result = (**(code **)(*operandVReg + 0x24))(operandVReg);
    if (vcall24Result == 0) {
      return;
    }
    hasSingleUse = IRInst__hasSingleUse(operandVReg,program);
    if (hasSingleUse == 0) break;
    if (operandVReg[0x48] != 0) {
      firstScaleOk = false;
    }
    target = *(int **)(*(int *)(program + 8) + 0x30c);
    inst1 = (**(code **)(*target + 0xfc))(target,resultScaleCode2 + operandVReg[0x49],operandVReg);
    if (inst1 == 0) {
      secondScaleOk = false;
    }
    if ((operandVReg[5] & 0x200U) == 0) {
      if (((resultScaleCode2 == 0) || ((firstScaleOk && (secondScaleOk)))) && (inst1 = IRInst__getOperandSource(inst,1), inst1 != 0)) {
        do {
          resultScaleCode = *(int *)(inst1 + 0x124);
          if (resultScaleCode2 != 0) {
            *(int *)(program + 0x170) = *(int *)(program + 0x170) + 1;
            *(int *)(inst1 + 0x124) = resultScaleCode2 + resultScaleCode;
            *(undefined4 *)(inst + 0x124) = 0;
          }
          if (((saturate != 0) && ((*(uint *)(inst + 0xb8) & 1) == 0)) &&
             ((*(uint *)(inst + 0xb8) & 2) == 0)) {
            *(int *)(program + 0x170) = *(int *)(program + 0x170) + 1;
            *(undefined4 *)(inst1 + 0x120) = 1;
            *(undefined4 *)(inst + 0x120) = 0;
          }
        } while (((*(uint *)(inst1 + 0x14) & 0x200) != 0) &&
                (inst1 = IRInst__getOperandSource(inst1,*(undefined4 *)(inst1 + 0x84)), inst1 != 0));
      }
      return;
    }
    operandVReg = (int *)IRInst__getOperandSource(operandVReg,operandVReg[0x21]);
  }
  return;
}

/* Inst__trySwapOperandSources @ 0x147b8c (968 bytes) */
int Inst__trySwapOperandSources(inst, operandIndex, inst2, operandIndex2, pass, commit, outChanged)
  int inst;
  int operandIndex;
  int inst2;
  int operandIndex2;
  int pass;
  int commit;
  undefined4 *outChanged;
{
  int operandKindClassResult;
  int vcall10cResult;
  int vcall5cResult;
  int *inst1;
  int definingField1282;
  int definingField128;
  int *operandVReg;
  int *callResult;
  int *callResult2;
  int vcall5cResultB;
  int callResult3;
  int *target;
  int operandKindClassResultB;
  uint modifiersB;
  uint modifiersA;
  undefined4 hookOutSelect [8];
  
  callResult = (int *)IRInst__getOperandSource(inst,operandIndex);
  callResult2 = (int *)IRInst__getOperandSource(inst2,operandIndex2);
  if (callResult != callResult2) {
    vcall5cResult = (**(code **)(*callResult + 0x5c))(callResult);
    if ((vcall5cResult == 0) || (vcall5cResult = (**(code **)(*callResult2 + 0x5c))(callResult2), vcall5cResult == 0)) {
      vcall5cResult = (**(code **)(*callResult + 0x5c))(callResult);
      if ((vcall5cResult == 0) || (vcall5cResult = (**(code **)(*callResult2 + 0x5c))(callResult2), vcall5cResult != 0)) {
        vcall5cResultB = (**(code **)(*callResult + 0x5c))(callResult);
        if ((vcall5cResultB == 0) && (vcall5cResultB = (**(code **)(*callResult2 + 0x5c))(callResult2), vcall5cResultB != 0)) {
          target = *(int **)(*(int *)(pass + 8) + 0x30c);
          vcall10cResult = (**(code **)(*target + 0x10c))
                            (target,inst,operandIndex,callResult,pass,commit,0,hookOutSelect);
          if (vcall10cResult == 0) {
            return 0;
          }
          callResult3 = ((int (*)())Inst__sameOpcodeAndSources)(callResult2,hookOutSelect[0]);
          if (callResult3 == 0) {
            return 0;
          }
          *outChanged = 1;
        }
        else {
          inst1 = callResult;
          if ((callResult[5] & 0x200U) == 0) {
            if ((callResult2[5] & 0x200U) == 0) {
              return 0;
            }
            operandVReg = (int *)IRInst__getOperandSource(callResult2,callResult2[0x21]);
            if (callResult != operandVReg) {
              return 0;
            }
            callResult3 = IRInst__sourceLanesAllWritten_f485c(inst2,operandIndex2);
            if (callResult3 == 0) {
              return 0;
            }
            if (commit != 0) {
              IRInst__setOperandSource(inst,operandIndex,callResult2,0,*(undefined4 *)(pass + 8));
              if (*(int *)(pass + 0x478) < callResult2[0x58]) {
                callResult2[0x58] = callResult2[0x58] + 1;
              }
              else {
                callResult2[0x58] = *(int *)(pass + 0x478) + 1;
              }
              callResult[0x58] = callResult[0x58] + -1;
            }
          }
          else {
            do {
              if ((inst1[5] & 0x200U) == 0) {
                return 0;
              }
              inst1 = (int *)IRInst__getOperandSource(inst1,inst1[0x21]);
            } while ((callResult2 != inst1) || (vcall5cResultB = IRInst__sourceLanesAllWritten_f485c(inst,operandIndex), vcall5cResultB == 0));
            if (commit != 0) {
              IRInst__setOperandSource(inst2,operandIndex2,callResult,0,*(undefined4 *)(pass + 8));
              if (*(int *)(pass + 0x478) < callResult[0x58]) {
                callResult[0x58] = callResult[0x58] + 1;
              }
              else {
                callResult[0x58] = *(int *)(pass + 0x478) + 1;
              }
              callResult2[0x58] = callResult2[0x58] + -1;
            }
          }
        }
        goto checkCallResult;
      }
      target = *(int **)(*(int *)(pass + 8) + 0x30c);
      vcall10cResult = (**(code **)(*target + 0x10c))
                        (target,inst2,operandIndex2,callResult2,pass,commit,0,hookOutSelect);
      if (vcall10cResult == 0) {
        return 0;
      }
      callResult3 = ((int (*)())Inst__sameOpcodeAndSources)(callResult,hookOutSelect[0]);
    }
    else {
      callResult3 = ((int (*)())Inst__sameOpcodeAndSources)(callResult,callResult2);
    }
    if (callResult3 == 0) {
      return 0;
    }
  }
checkCallResult:
  if ((callResult[0x48] == callResult2[0x48]) && (callResult[0x49] == callResult2[0x49])) {
    modifiersA = *(uint *)(operandIndex * 0x18 + inst + 0xa0);
    modifiersB = *(uint *)(operandIndex2 * 0x18 + inst2 + 0xa0);
    if (((modifiersA & 1) == (modifiersB & 1)) && ((modifiersA >> 1 & 1) == (modifiersB >> 1 & 1))) {
      operandKindClassResult = IRInst__operandKindClass(inst,operandIndex);
      operandKindClassResultB = IRInst__operandKindClass(inst2,operandIndex2);
      if (operandKindClassResult == operandKindClassResultB) {
        definingField128 = IRInst__getDefiningField128(inst,operandIndex);
        definingField1282 = IRInst__getDefiningField128(inst2,operandIndex2);
        if (definingField128 == definingField1282) {
          return 1;
        }
      }
    }
  }
  return 0;
}

/* Inst__foldOutputScaleIntoConstants @ 0x147f54 (980 bytes) */
int Inst__foldOutputScaleIntoConstants(inst, compiler)
  int *inst;
  int compiler;
{
  int vcallfcResult;
  int useStamp;
  int opcodeKind;
  int operandSelect;
  bool isLast;
  int resultScaleCode;
  int program;
  int operandIndex;
  int uniformSourceConstant;
  int uniformSourceConstant2;
  undefined4 sourceDef3;
  int sourceDef2;
  int operandRecord3;
  int sourceDef;
  int operandRecord2;
  int useCount;
  int loopIndex;
  bool hasLastOperand;
  int sourceMatchResult;
  uint instFlags;
  int scaleResult;
  int operandRecord;
  uint keptOperandModifiers;
  int saturate;
  int afterInst;
  int usersVec;
  int operandSelectB;
  int destRegisterOffset;
  undefined4 operandSelectC;
  int destRegister;
  int keptOperandVreg;
  uint negateFlag;
  undefined4 literalOperandIndex;
  int foldMode;
  int keptOperandVregHi;
  double literalValue;
  int scaleFrame [5];
  undefined1 constantRecord [4];
  float uniformConstantValue;
  undefined4 lastOperandRecord;
  undefined4 lastOperandSource;
  undefined4 lastOperandTail;
  uint hasLastOperandFlag;
  
  scaleFrame[0] = 0;
  opcodeKind = *(int *)(inst[0x22] + 8);
  resultScaleCode = inst[0x49];
  if (opcodeKind == 0x13) {
    loopIndex = 1;
    while( true ) {
      operandRecord3 = IRInst__getOperandRecord(inst,0);
      uniformSourceConstant = IRInst__getUniformSourceConstant(inst,loopIndex,*(undefined4 *)(operandRecord3 + 0x10),constantRecord);
      if (uniformSourceConstant != 0) break;
      isLast = loopIndex == 2;
      loopIndex = loopIndex + 1;
      if (isLast) {
        return inst;
      }
    }
    scaleResult = ((undefined4 (*)())tryOutputScaleExponent)(uniformSourceConstant,scaleFrame,(double)uniformConstantValue);
    if (scaleResult == 0) {
      return inst;
    }
    scaleFrame[0] = resultScaleCode + scaleFrame[0];
    if (loopIndex == 1) {
      foldMode = 2;
      literalOperandIndex = 0xffffffff;
      operandIndex = 2;
    }
    else {
      foldMode = 2;
      literalOperandIndex = 0xffffffff;
      operandIndex = 1;
    }
  }
  else if (opcodeKind == 0x14) {
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    uniformSourceConstant2 = IRInst__getUniformSourceConstant(inst,3,*(undefined4 *)(operandRecord2 + 0x10),constantRecord);
    if (uniformSourceConstant2 == 0) {
      return inst;
    }
    if ((uniformConstantValue != FLOAT_001aa114) && (uniformConstantValue != FLOAT_001aa0e8)) {
      return inst;
    }
    scaleFrame[4] = 0x40000000;
    scaleFrame[1] = 0x40000000;
    scaleFrame[2] = 0x40000000;
    scaleFrame[3] = 0x40000000;
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    sourceMatchResult = IRInst__sourceMatchesConstant(inst,1,*(undefined4 *)(operandRecord2 + 0x10),scaleFrame + 1);
    if (sourceMatchResult == 0) {
      operandRecord2 = IRInst__getOperandRecord(inst,0);
      sourceMatchResult = IRInst__sourceMatchesConstant(inst,2,*(undefined4 *)(operandRecord2 + 0x10),scaleFrame + 1);
      if (sourceMatchResult == 0) {
        return inst;
      }
      scaleFrame[0] = resultScaleCode + 1;
      foldMode = 3;
      literalOperandIndex = 2;
      operandIndex = 1;
    }
    else {
      scaleFrame[0] = resultScaleCode + 1;
      foldMode = 3;
      literalOperandIndex = 1;
      operandIndex = 2;
    }
  }
  else {
    if (opcodeKind != 0x12) {
      return inst;
    }
    sourceDef = IRInst__getOperandSource(inst,1);
    sourceDef2 = IRInst__getOperandSource(inst,2);
    if (sourceDef != sourceDef2) {
      return inst;
    }
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    operandSelect = *(int *)(operandRecord2 + 0x10);
    operandRecord2 = IRInst__getOperandRecord(inst,2);
    if (operandSelect != *(int *)(operandRecord2 + 0x10)) {
      return inst;
    }
    if ((inst[0x2e] & 1U) != (inst[0x34] & 1U)) {
      return inst;
    }
    if (((uint)inst[0x2e] >> 1 & 1) != ((uint)inst[0x34] >> 1 & 1)) {
      return inst;
    }
    scaleFrame[0] = resultScaleCode + 1;
    foldMode = 1;
    literalOperandIndex = 0xffffffff;
    operandIndex = 1;
  }
  vcallfcResult = (**(code **)(**(int **)(compiler + COMP_target) + 0xfc))
                    (*(int **)(compiler + COMP_target),scaleFrame[0],inst);
  if (vcallfcResult != 0) {
    program = *(int *)(compiler + COMP_currentProgram);
    *(int *)(program + 0x158) = *(int *)(program + 0x158) + 1;
    if (foldMode == 2) {
      negateFlag = (uint)(uniformConstantValue < FLOAT_001aa0d4) ^ inst[operandIndex * 6 + 0x28] & 1U;
    }
    else {
      if (foldMode == 3) {
        literalValue = (double)FLOAT_001aa0e8;
        inst[0x49] = scaleFrame[0];
        ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,literalOperandIndex,literalValue,literalValue,literalValue,literalValue);
        literalValue = (double)FLOAT_001aa10c;
        ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,3,literalValue,literalValue,literalValue,literalValue);
        IROperand__setModifierBits(inst + 0x35,1,(uint)(uniformConstantValue < FLOAT_001aa0d4));
        return inst;
      }
      if (foldMode == 1) {
        negateFlag = inst[operandIndex * 6 + 0x28] & 1;
      }
      else {
        negateFlag = 0;
      }
    }
    afterInst = inst[1];
    usersVec = inst[4];
    useCount = IRInst__useCount(inst,program);
    instFlags = inst[5];
    destRegisterOffset = inst[0x26];
    destRegister = inst[0x25];
    operandRecord = IRInst__getOperandRecord(inst,0);
    operandSelectB = *(int *)(operandRecord + 0x10);
    saturate = inst[0x48];
    sourceDef3 = IRInst__getOperandSource(inst,operandIndex);
    keptOperandVreg = inst[operandIndex * 6 + 0x25];
    keptOperandVregHi = inst[operandIndex * 6 + 0x26];
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    operandSelectC = *(undefined4 *)(operandRecord + 0x10);
    hasLastOperand = (inst[5] & 0x200U) != 0;
    keptOperandModifiers = inst[operandIndex * 6 + 0x28];
    lastOperandTail = 0;
    lastOperandRecord = 0;
    lastOperandSource = 0;
    hasLastOperandFlag = 0;
    if (hasLastOperand) {
      IRInst__readLastOperand(inst,&lastOperandRecord);
    }
    hasLastOperandFlag = (uint)hasLastOperand;
    (**(code **)(*inst + 0xc))(inst,1,compiler);
    IRInst__reinitAsMov(inst,0x31,compiler);
    if ((instFlags & 2) != 0) {
      inst[5] = inst[5] | 2;
    }
    inst[4] = usersVec;
    useStamp = *(int *)(program + 0x478);
    inst[0x25] = destRegister;
    inst[0x26] = destRegisterOffset;
    inst[0x58] = useCount + useStamp;
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(int *)(operandRecord2 + 0xc) = keptOperandVregHi;
    *(int *)(operandRecord2 + 8) = keptOperandVreg;
    inst[0x27] = operandSelectB;
    IRInst__setOperandSource(inst,1,sourceDef3,1,compiler);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0x10) = operandSelectC;
    IROperand__setModifierBits(inst + 0x29,2,keptOperandModifiers >> 1 & 1);
    IROperand__setModifierBits(inst + 0x29,1,negateFlag);
    inst[0x48] = saturate;
    inst[0x49] = scaleFrame[0];
    if (hasLastOperandFlag != 0) {
      IRInst__setLastOperandFromRecord(inst,&lastOperandRecord,1,compiler);
    }
    Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,inst);
  }
  return inst;
}

/* Inst__forwardSelectToProducer_0014846c @ 0x14846c (636 bytes) */
int Inst__forwardSelectToProducer_0014846c(inst, pass)
  int *inst;
  int pass;
{
  int loopIndex2;
  int destRegisterOffset;
  int destRegister;
  uint vectorFilledCount;
  int operandRecord2;
  int operandRecord;
  undefined4 rewrittenSelect;
  uint selectWordWork;
  int optionEnabled;
  int *operandVReg;
  undefined4 *candidateSlot;
  int producerCheck;
  uint operandSelectB;
  int countdown;
  int laneCountdown;
  uint loopIndex;
  uint *vector;
  int *inst1;
  undefined4 operandSelect;
  undefined4 selectScratch [8];
  
  if ((inst[5] & 2U) != 0) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    selectWordWork = *(uint *)(operandRecord + 0x10);
    optionEnabled = SelectWord__hasNonzeroLaneBytes(selectWordWork);
    if ((optionEnabled != 0) && (optionEnabled = Compiler__isOptionEnabled(*(undefined4 *)(pass + 8),0x31), optionEnabled != 0)) {
      destRegisterOffset = inst[0x26];
      destRegister = inst[0x25];
      operandVReg = (int *)IRInst__getOperandSource(inst,1);
      for (laneCountdown = 4;
          ((producerCheck = (**(code **)(*operandVReg + 0x30))(operandVReg), producerCheck == 0 &&
           (producerCheck = (**(code **)(*operandVReg + 0x40))(operandVReg), producerCheck == 0)) && (laneCountdown != 0));
          laneCountdown = laneCountdown + -1) {
        vector = (uint *)operandVReg[4];
        loopIndex = 0;
        vectorFilledCount = vector[1];
        if (0 < (int)vectorFilledCount) {
          do {
            if (loopIndex < *vector) {
              if (vectorFilledCount <= loopIndex) {
                _memset(vectorFilledCount * 4 + vector[2],0,(loopIndex - vectorFilledCount) * 4 + 4);
                vector[1] = loopIndex + 1;
              }
              candidateSlot = (undefined4 *)(loopIndex * 4 + vector[2]);
            }
            else {
              candidateSlot = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
            }
            inst1 = (int *)*candidateSlot;
            if (((inst != inst1) && (destRegisterOffset == inst1[0x26])) && (destRegister == inst1[0x25])) {
              *(int *)(pass + 0x168) = *(int *)(pass + 0x168) + 1;
              operandRecord = IRInst__getOperandRecord(inst1,0);
              operandSelectB = *(uint *)(operandRecord + 0x10);
              selectWordWork = (selectWordWork << 0x18 | (selectWordWork >> 8 & 0xff) << 0x10 | (selectWordWork >> 0x10 & 0xff) << 8 |
                      selectWordWork >> 0x18) &
                      (operandSelectB << 0x18 | (operandSelectB >> 8 & 0xff) << 0x10 | (operandSelectB >> 0x10 & 0xff) << 8 |
                      operandSelectB >> 0x18);
              inst[0x27] =
                   selectWordWork << 0x18 | (selectWordWork & 0xff00) << 8 | selectWordWork >> 8 & 0xff00 | selectWordWork >> 0x18;
              operandRecord = IRInst__getOperandRecord(inst,1);
              operandSelect = *(undefined4 *)(operandRecord + 0x10);
              operandRecord2 = IRInst__getOperandRecord(inst1,1);
              loopIndex2 = 0;
              selectScratch[0] = *(undefined4 *)(operandRecord2 + 0x10);
              countdown = 4;
              do {
                if (*(char *)((int)selectScratch + loopIndex2 + -4) == '\x04') {
                  *(undefined1 *)((int)selectScratch + loopIndex2 + -4) =
                       *(undefined1 *)((int)selectScratch + loopIndex2);
                }
                rewrittenSelect = operandSelect;
                loopIndex2 = loopIndex2 + 1;
                countdown = countdown + -1;
              } while (countdown != 0);
              operandRecord = IRInst__getOperandRecord(inst,1);
              *(undefined4 *)(operandRecord + 0x10) = rewrittenSelect;
              (**(code **)(*inst1 + 0xc))(inst1,1,*(undefined4 *)(pass + 8));
              return;
            }
            vector = (uint *)operandVReg[4];
            loopIndex = loopIndex + 1;
            vectorFilledCount = vector[1];
          } while ((int)loopIndex < (int)vectorFilledCount);
        }
        if ((operandVReg[5] & 0x200U) == 0) {
          return;
        }
        operandVReg = (int *)IRInst__getOperandSource(operandVReg,operandVReg[0x21]);
      }
    }
  }
  return;
}

/* Inst__forwardSelectToProducer_001486e8 @ 0x1486e8 (664 bytes) */
int Inst__forwardSelectToProducer_001486e8(inst, pass)
  int *inst;
  int pass;
{
  int countdown;
  int loopIndex2;
  int destRegister;
  uint vectorFilledCount;
  int operandRecord2;
  int operandRecord;
  undefined4 rewrittenSelect;
  uint selectWordWork;
  int optionEnabled;
  int *operandVReg;
  undefined4 *candidateSlot;
  int *operandSource;
  int producerCheck;
  uint operandSelectB;
  int laneCountdown;
  int destRegisterOffset;
  uint loopIndex;
  uint *vector;
  int *inst1;
  undefined4 operandSelect;
  undefined4 selectScratch [8];
  
  if ((inst[5] & 2U) != 0) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    selectWordWork = *(uint *)(operandRecord + 0x10);
    optionEnabled = SelectWord__hasNonzeroLaneBytes(selectWordWork);
    if ((optionEnabled != 0) && (optionEnabled = Compiler__isOptionEnabled(*(undefined4 *)(pass + 8),0x31), optionEnabled != 0)) {
      destRegisterOffset = inst[0x26];
      destRegister = inst[0x25];
      operandVReg = (int *)IRInst__getOperandSource(inst,1);
      for (laneCountdown = 4;
          ((producerCheck = (**(code **)(*operandVReg + 0x30))(operandVReg), producerCheck == 0 &&
           (producerCheck = (**(code **)(*operandVReg + 0x40))(operandVReg), producerCheck == 0)) && (laneCountdown != 0));
          laneCountdown = laneCountdown + -1) {
        vector = *(uint **)(pass + 0x3c4);
        loopIndex = 0;
        vectorFilledCount = vector[1];
        if (0 < (int)vectorFilledCount) {
          do {
            if (loopIndex < *vector) {
              if (vectorFilledCount <= loopIndex) {
                _memset(vectorFilledCount * 4 + vector[2],0,(loopIndex - vectorFilledCount) * 4 + 4);
                vector[1] = loopIndex + 1;
              }
              candidateSlot = (undefined4 *)(loopIndex * 4 + vector[2]);
            }
            else {
              candidateSlot = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
            }
            inst1 = (int *)*candidateSlot;
            if (((inst != inst1) && (destRegisterOffset == inst1[0x26])) &&
               ((destRegister == inst1[0x25] &&
                (operandSource = (int *)IRInst__getOperandSource(inst1,1), operandVReg == operandSource)))) {
              *(int *)(pass + 0x168) = *(int *)(pass + 0x168) + 1;
              operandRecord = IRInst__getOperandRecord(inst1,0);
              operandSelectB = *(uint *)(operandRecord + 0x10);
              selectWordWork = (selectWordWork << 0x18 | (selectWordWork >> 8 & 0xff) << 0x10 | (selectWordWork >> 0x10 & 0xff) << 8 |
                      selectWordWork >> 0x18) &
                      (operandSelectB << 0x18 | (operandSelectB >> 8 & 0xff) << 0x10 | (operandSelectB >> 0x10 & 0xff) << 8 |
                      operandSelectB >> 0x18);
              inst[0x27] =
                   selectWordWork << 0x18 | (selectWordWork & 0xff00) << 8 | selectWordWork >> 8 & 0xff00 | selectWordWork >> 0x18;
              operandRecord = IRInst__getOperandRecord(inst,1);
              operandSelect = *(undefined4 *)(operandRecord + 0x10);
              operandRecord2 = IRInst__getOperandRecord(inst1,1);
              loopIndex2 = 0;
              selectScratch[0] = *(undefined4 *)(operandRecord2 + 0x10);
              countdown = 4;
              do {
                if (*(char *)((int)selectScratch + loopIndex2 + -4) == '\x04') {
                  *(undefined1 *)((int)selectScratch + loopIndex2 + -4) =
                       *(undefined1 *)((int)selectScratch + loopIndex2);
                }
                rewrittenSelect = operandSelect;
                loopIndex2 = loopIndex2 + 1;
                countdown = countdown + -1;
              } while (countdown != 0);
              operandRecord = IRInst__getOperandRecord(inst,1);
              *(undefined4 *)(operandRecord + 0x10) = rewrittenSelect;
              (**(code **)(*inst1 + 0xc))(inst1,0,*(undefined4 *)(pass + 8));
              operandVReg[0x58] = operandVReg[0x58] + -1;
              return;
            }
            vector = *(uint **)(pass + 0x3c4);
            loopIndex = loopIndex + 1;
            vectorFilledCount = vector[1];
          } while ((int)loopIndex < (int)vectorFilledCount);
        }
        if ((operandVReg[5] & 0x200U) == 0) {
          return;
        }
        operandVReg = (int *)IRInst__getOperandSource(operandVReg,operandVReg[0x21]);
      }
    }
  }
  return;
}

/* Inst__cloneSplatProducer_00148980 @ 0x148980 (1036 bytes) */
int Inst__cloneSplatProducer_00148980(inst, program)
  int inst;
  int program;
{
  undefined4 operandSelect;
  int isSplatResult;
  int loopIndex2;
  int operandIndex2;
  int operandIndex;
  int hasSingleUse;
  int splitRgbAlphaEnabled;
  int operandRecord4;
  int operandRecord2;
  int operandRecord3;
  int *operandVReg2;
  int loopIndex;
  bool moreComponents;
  int vcall24Result;
  int targetCallResult;
  int checkResult;
  int *operandVReg;
  int *cloneOrOriginalInst;
  int operandRecord;
  int operandVReg3;
  int *target;
  undefined4 staleArg6;
  undefined4 compilerCtx;
  undefined4 staleArg8;
  code *a6;
  int passStamp;
  int newPassStamp;
  int selectWordOrNewTarget;
  int newTargetField;
  undefined4 rewrittenSelectWord;
  int cloneOrOperandCount;
  undefined4 savedField14c;
  undefined4 laneBytesOut [4];
  int composedSelectOut [5];
  
  splitRgbAlphaEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x30);
  if ((((splitRgbAlphaEnabled != 0) && ((*(uint *)(inst + 0xb8) & 1) == 0)) &&
      ((*(uint *)(inst + 0xb8) & 2) == 0)) && ((*(uint *)(inst + 0x14) & 0x200) == 0)) {
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    selectWordOrNewTarget = *(int *)(operandRecord2 + 0x10);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    operandSelect = *(undefined4 *)(operandRecord2 + 0x10);
    isSplatResult = SelectWord__isSplat(operandSelect);
    if (isSplatResult != 0) {
      operandVReg = (int *)IRInst__getOperandSource(inst,1);
      vcall24Result = OpcodeTraits__getField34(*(undefined4 *)(operandVReg[0x22] + 8),*(undefined4 *)(program + 8));
      if (((vcall24Result == 0) && (vcall24Result = (**(code **)(*operandVReg + 0x24))(operandVReg), vcall24Result != 0)) &&
         ((operandVReg[5] & 0x200U) == 0)) {
        operandRecord2 = IRInst__getOperandRecord(operandVReg,0);
        checkResult = SelectWord__isSingleComponentConstant(*(undefined4 *)(operandRecord2 + 0x10));
        if ((checkResult == 0) && (checkResult = Inst__noIfHeaderBetweenBlocks(operandVReg,program), checkResult != 0)) {
          passStamp = *(int *)(program + 0x478);
          *(int *)(program + 0x174) = *(int *)(program + 0x174) + 1;
          hasSingleUse = IRInst__hasSingleUse(operandVReg,program);
          cloneOrOriginalInst = operandVReg;
          if (hasSingleUse == 0) {
            newPassStamp = passStamp + 1;
            cloneOrOriginalInst = (int *)IRInst__clone(operandVReg,*(undefined4 *)(program + 8),0);
            Block__insertInstAfter(operandVReg[0x56],operandVReg,cloneOrOriginalInst);
            cloneOrOperandCount = cloneOrOriginalInst[0x53];
            operandVReg[0x58] = operandVReg[0x58] + -1;
            cloneOrOriginalInst[0x58] = newPassStamp;
            operandRecord2 = IRInst__getOperandRecord(cloneOrOriginalInst,0);
            *(int *)(operandRecord2 + 8) = cloneOrOperandCount;
            for (operandIndex = 1; cloneOrOperandCount = (**(code **)(*cloneOrOriginalInst + 0x14))(cloneOrOriginalInst), operandIndex <= cloneOrOperandCount;
                operandIndex = operandIndex + 1) {
              operandVReg2 = (int *)IRInst__getOperandSource(cloneOrOriginalInst,operandIndex);
              cloneOrOperandCount = (**(code **)(*operandVReg2 + 0x5c))(operandVReg2);
              if (cloneOrOperandCount == 0) {
                if (passStamp < operandVReg2[0x58]) {
                  operandVReg2[0x58] = operandVReg2[0x58] + 1;
                }
                else {
                  operandVReg2[0x58] = newPassStamp;
                }
              }
              else {
                cloneOrOperandCount = IRInst__clone(operandVReg2,*(undefined4 *)(program + 8),0);
                savedField14c = *(undefined4 *)(cloneOrOperandCount + 0x14c);
                operandRecord = IRInst__getOperandRecord(cloneOrOperandCount,0);
                *(undefined4 *)(operandRecord + 8) = savedField14c;
                *(int *)(cloneOrOperandCount + 0x160) = newPassStamp;
                compilerCtx = *(undefined4 *)(program + 8);
                staleArg6 = 0;
                IRInst__setOperandSource(cloneOrOriginalInst,operandIndex,cloneOrOperandCount,0,compilerCtx);
                Block__insertInstBefore(operandVReg2[0x56],operandVReg2,cloneOrOperandCount);
                if (0 < *(int *)(cloneOrOperandCount + 0x84)) {
                  loopIndex = 1;
                  do {
                    operandVReg3 = IRInst__getOperandSource(cloneOrOperandCount,loopIndex);
                    if (passStamp < *(int *)(operandVReg3 + 0x160)) {
                      *(int *)(operandVReg3 + 0x160) = *(int *)(operandVReg3 + 0x160) + 1;
                    }
                    else {
                      *(int *)(operandVReg3 + 0x160) = newPassStamp;
                    }
                    loopIndex = loopIndex + 1;
                  } while (loopIndex <= *(int *)(cloneOrOperandCount + 0x84));
                }
              }
            }
          }
          cloneOrOriginalInst[0x27] = selectWordOrNewTarget;
          for (operandIndex2 = 1; selectWordOrNewTarget = (**(code **)(*cloneOrOriginalInst + 0x14))(cloneOrOriginalInst), operandIndex2 <= selectWordOrNewTarget;
              operandIndex2 = operandIndex2 + 1) {
            operandRecord3 = IRInst__getOperandRecord(operandVReg,operandIndex2);
            SelectWord__compose(composedSelectOut,*(undefined4 *)(operandRecord3 + 0x10),operandSelect);
            selectWordOrNewTarget = composedSelectOut[0];
            if (operandIndex2 == 0) {
              cloneOrOriginalInst[0x27] = composedSelectOut[0];
            }
            else {
              operandRecord4 = IRInst__getOperandRecord(cloneOrOriginalInst,operandIndex2);
              *(int *)(operandRecord4 + 0x10) = selectWordOrNewTarget;
            }
          }
          hasSingleUse = IRInst__hasSingleUse(inst,program);
          if (hasSingleUse != 0) {
            if (*(int *)(inst + 0x120) != 0) {
              cloneOrOriginalInst[0x48] = 1;
              *(undefined4 *)(inst + 0x120) = 0;
            }
            target = *(int **)(*(int *)(program + 8) + 0x30c);
            newTargetField = *(int *)(inst + 0x124) + operandVReg[0x49];
            a6 = *(code **)(*target + 0xfc);
            targetCallResult = (*a6)(target,newTargetField,inst,staleArg6,compilerCtx,staleArg8,a6);
            if (targetCallResult != 0) {
              cloneOrOriginalInst[0x49] = newTargetField;
              *(undefined4 *)(inst + 0x124) = 0;
            }
          }
          loopIndex2 = 0;
          laneBytesOut[0] = 0x4040404;
          do {
            operandRecord3 = IRInst__getOperandRecord(inst,0);
            if (*(char *)(loopIndex2 + operandRecord3 + 0x10) != '\x01') {
              *(undefined1 *)((int)laneBytesOut + loopIndex2) = *(undefined1 *)((int)&DAT_001b004c + loopIndex2);
            }
            rewrittenSelectWord = laneBytesOut[0];
            moreComponents = loopIndex2 != 3;
            loopIndex2 = loopIndex2 + 1;
          } while (moreComponents);
          operandRecord2 = IRInst__getOperandRecord(inst,1);
          *(undefined4 *)(operandRecord2 + 0x10) = rewrittenSelectWord;
          IRInst__setOperandSource(inst,1,cloneOrOriginalInst,0,*(undefined4 *)(program + 8));
          return;
        }
      }
    }
  }
  return;
}

/* Inst__mergeLaneProducers_00148d8c @ 0x148d8c (1872 bytes) */
int Inst__mergeLaneProducers_00148d8c(inst, program)
  int *inst;
  int program;
{
  int loopIndex2;
  int vcall24Result;
  int loopIndexC;
  int loopIndexB;
  int loopIndex;
  int sourceIsSplatConstantResult;
  int hasSingleUse;
  int sourceIsSplatConstantResult2;
  int operandRecord2;
  int operandRecord;
  bool moreComponents;
  char laneSelectByte;
  byte laneSourceLane;
  uint operandNegateBit;
  int checkResult;
  int *operandVReg;
  int producerCheck;
  int operandCountResult;
  int countdown;
  int isOpcodeInSet147398Result;
  int *inst1;
  uint operandAbsBit;
  int *operandModifierCursor;
  int producerOpcode;
  int *operandRecord1;
  undefined4 operandSelectC;
  undefined4 operandSelectB;
  undefined4 operandSelect;
  int *laneProducerInsts [7];
  
  operandRecord = IRInst__getOperandRecord(inst,1);
  operandSelectC = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst,0);
  operandSelectB = *(undefined4 *)(operandRecord + 0x10);
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  if (((inst[0x2e] & 1U) != 0) || ((inst[0x2e] & 2U) != 0)) {
    loopIndex = 0;
    laneProducerInsts[0] = (int *)0x0;
    laneProducerInsts[1] = (int *)0x0;
    laneProducerInsts[2] = (int *)0x0;
    laneProducerInsts[3] = (int *)0x0;
    do {
      if (*(char *)((int)&operandSelectB + loopIndex) == '\0') {
        producerCheck = (**(code **)(*operandVReg + 0x24))(operandVReg);
        if ((((producerCheck == 0) || (producerCheck = IRInst__hasSingleUse(operandVReg,program), producerCheck == 0)) ||
            (operandVReg[0x48] != 0)) || (producerCheck = ((int (*)())IRInst__isOpcodeInSet147398)(operandVReg), producerCheck == 0)) {
          return 0;
        }
        operandRecord2 = IRInst__getOperandRecord(operandVReg,0);
        laneSourceLane = *(byte *)((int)&operandSelectC + loopIndex);
        operandSelect = *(undefined4 *)(operandRecord2 + 0x10);
        laneSelectByte = *(char *)((int)&operandSelect + (uint)laneSourceLane);
        inst1 = operandVReg;
        while (laneSelectByte == '\x01') {
          inst1 = (int *)IRInst__getOperandSource(inst1,inst1[0x21]);
          vcall24Result = (**(code **)(*inst1 + 0x24))(inst1);
          if (vcall24Result == 0) {
            return 0;
          }
          hasSingleUse = IRInst__hasSingleUse(inst1,program);
          if (hasSingleUse == 0) {
            return 0;
          }
          if (inst1[0x48] != 0) {
            return 0;
          }
          isOpcodeInSet147398Result = ((int (*)())IRInst__isOpcodeInSet147398)(inst1);
          if (isOpcodeInSet147398Result == 0) {
            return 0;
          }
          operandRecord2 = IRInst__getOperandRecord(inst1,0);
          operandSelect = *(undefined4 *)(operandRecord2 + 0x10);
          laneSelectByte = *(char *)((int)&operandSelect + (uint)laneSourceLane);
        }
        if (loopIndex < 1) {
loopStoreLaneProducerInsts:
          laneProducerInsts[loopIndex] = inst1;
        }
        else if (laneProducerInsts[0] != inst1) {
          loopIndexC = 0;
          countdown = loopIndex;
          do {
            loopIndexC = loopIndexC + 1;
            countdown = countdown + -1;
            if (countdown == 0) goto loopStoreLaneProducerInsts;
          } while (laneProducerInsts[loopIndexC] != inst1);
        }
      }
      moreComponents = loopIndex != 3;
      loopIndex = loopIndex + 1;
    } while (moreComponents);
    loopIndex2 = 0;
    operandNegateBit = inst[0x2e] & 1;
    operandAbsBit = (uint)inst[0x2e] >> 1 & 1;
    do {
      if ((*(char *)((int)&operandSelectB + loopIndex2) == '\0') &&
         (inst1 = laneProducerInsts[loopIndex2], inst1 != (int *)0x0)) {
        *(int *)(program + 0x16c) = *(int *)(program + 0x16c) + 1;
        producerOpcode = *(int *)(inst1[0x22] + 8);
        operandCountResult = (**(code **)(*inst1 + 0x14))(inst1);
        if (operandCountResult == 1) {
          if (operandAbsBit == 0) {
loopCheckOperandNegateBit:
            if (operandNegateBit != 0) {
              if ((inst1[0x2e] & 1U) == 0) {
                sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(inst1,1,0.0);
                if (sourceIsSplatConstantResult == 0) {
                  IROperand__setModifierBits(inst1 + 0x29,1,1);
                }
              }
              else {
                IROperand__setModifierBits(inst1 + 0x29,1,0);
              }
            }
          }
          else {
            if ((operandNegateBit != 0) || (operandCountResult = IRInst__operandIsNonNegativeFloatConst(inst1,1), operandCountResult == 0)) {
              IROperand__setModifierBits(inst1 + 0x29,2,1);
              if (operandNegateBit != 0) {
                sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(inst1,1,0.0);
                if (sourceIsSplatConstantResult == 0) {
                  IROperand__setModifierBits(inst1 + 0x29,1,1);
                }
                goto setMoreComponents;
              }
            }
            IROperand__setModifierBits(inst1 + 0x29,1,0);
          }
        }
        else if (producerOpcode == 0x13) {
          if (operandAbsBit == 0) goto loopCheckOperandNegateBit;
          IROperand__setModifierBits(inst1 + 0x29,2,1);
          IROperand__setModifierBits(inst1 + 0x2f,2,1);
          if (operandNegateBit == 0) {
loopCallIROperand_setModifierBits:
            IROperand__setModifierBits(inst1 + 0x29,1,0);
          }
          else {
            sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(inst1,1,0.0);
            if (sourceIsSplatConstantResult == 0) {
              IROperand__setModifierBits(inst1 + 0x29,1,1);
            }
          }
          IROperand__setModifierBits(inst1 + 0x2f,1,0);
        }
        else if (producerOpcode == 0x12) {
          if (operandAbsBit == 0) {
            if (operandNegateBit != 0) {
              if ((inst1[0x2e] & 1U) == 0) {
                sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(inst1,1,0.0);
                if (sourceIsSplatConstantResult == 0) {
                  IROperand__setModifierBits(inst1 + 0x29,1,1);
                }
              }
              else {
                IROperand__setModifierBits(inst1 + 0x29,1,0);
              }
              if ((inst1[0x34] & 1U) == 0) {
                sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(inst1,2,0.0);
                if (sourceIsSplatConstantResult == 0) {
                  IROperand__setModifierBits(inst1 + 0x2f,1,1);
                }
              }
              else {
                IROperand__setModifierBits(inst1 + 0x2f,1,0);
              }
            }
          }
          else {
            IROperand__setModifierBits(inst1 + 0x29,2,1);
            IROperand__setModifierBits(inst1 + 0x2f,2,1);
            if (operandNegateBit == 0) goto loopCallIROperand_setModifierBits;
            sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(inst1,1,0.0);
            if (sourceIsSplatConstantResult == 0) {
              IROperand__setModifierBits(inst1 + 0x29,1,1);
            }
            sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(inst1,2,0.0);
            if (sourceIsSplatConstantResult == 0) {
              IROperand__setModifierBits(inst1 + 0x2f,1,1);
            }
          }
        }
        else if (producerOpcode - 0x24U < 3) {
          loopIndexB = 2;
          operandModifierCursor = inst1 + 0x2c;
          operandRecord1 = inst1 + 0x2f;
          do {
            if (operandAbsBit == 0) {
              if (operandNegateBit != 0) {
                if ((operandModifierCursor[8] & 1U) != 0) goto callIROperand_setModifierBits;
                sourceIsSplatConstantResult2 = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(inst1,loopIndexB,0.0);
                if (sourceIsSplatConstantResult2 == 0) {
                  IROperand__setModifierBits(operandModifierCursor + 3,1,1);
                }
              }
            }
            else {
              IROperand__setModifierBits(operandRecord1,2,1);
              if (operandNegateBit == 0) {
callIROperand_setModifierBits:
                IROperand__setModifierBits(operandRecord1,1,0);
              }
              else {
                sourceIsSplatConstantResult2 = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(inst1,loopIndexB,0.0);
                if (sourceIsSplatConstantResult2 == 0) {
                  IROperand__setModifierBits(operandRecord1,1,1);
                }
              }
            }
            moreComponents = loopIndexB != 3;
            operandRecord1 = operandRecord1 + 6;
            operandModifierCursor = operandModifierCursor + 6;
            loopIndexB = loopIndexB + 1;
          } while (moreComponents);
        }
      }
setMoreComponents:
      moreComponents = loopIndex2 != 3;
      loopIndex2 = loopIndex2 + 1;
    } while (moreComponents);
    *(int *)(program + 0x16c) = *(int *)(program + 0x16c) + 1;
    IROperand__setModifierBits(inst + 0x29,2,0);
    IROperand__setModifierBits(inst + 0x29,1,0);
  }
  checkResult = SelectWord__isSingleComponentConstant(operandSelectB);
  if (((((checkResult == 0) || (checkResult = IRInst__isSourceSelectIdentity(inst,1), checkResult == 0)) &&
       (checkResult = SelectWord__isSplat(operandSelectC), checkResult != 0)) &&
      (((char)operandSelectC == '\x04' && (checkResult = IRInst__hasSingleUse(operandVReg,program), checkResult != 0)))) &&
     ((checkResult = OpcodeTraits__flagBit6(*(undefined4 *)(operandVReg[0x22] + 8),*(undefined4 *)(program + 8)),
      checkResult != 0 && (checkResult = OpcodeTraits__flag1WithoutFlag7(*(undefined4 *)(program + 8),operandVReg), checkResult != 0)))) {
    *(int *)(program + 0x16c) = *(int *)(program + 0x16c) + 1;
    operandRecord = IRInst__getOperandRecord(inst,0);
    operandVReg[0x27] = *(int *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord + 0x10) = 0x10203;
    loopIndex = 0;
    do {
      if (*(char *)((int)&operandSelectB + loopIndex) == '\x01') {
        (**(code **)(*inst + 0x88))(inst,1,loopIndex,4);
      }
      moreComponents = loopIndex != 3;
      loopIndex = loopIndex + 1;
    } while (moreComponents);
  }
  return 1;
}

/* Inst__foldChainedDest_001494dc @ 0x1494dc (2168 bytes) */
int Inst__foldChainedDest_001494dc(inst, program, changedOut)
  int *inst;
  int program;
  undefined4 *changedOut;
{
  int operandKindClassResult;
  int vcall64ResultB;
  int vcall64Result;
  int countdownC;
  int loopIndex;
  int countdownB;
  int countdown;
  int *inst1;
  int operandIndex;
  int newSource;
  undefined4 firstWrittenComponentResult2;
  int firstWrittenComponentResult;
  int flagBit0Result;
  int *sourceDef;
  int operandRecord3;
  int operandRecord;
  int operandRecord2;
  char selectByteD;
  int operandSelectWord;
  int flagBitResultE;
  int predicateResultD;
  int vcall64ResultD;
  int predicateResultC;
  int operandIdxA;
  int operandSelectWordB;
  int operandIdxB;
  int operandCountA;
  int *a0;
  undefined4 selectWordA;
  undefined4 selectWordB;
  int operandCountChain;
  int operandRecordSrc;
  int operandCountSource;
  int identityResult;
  int instField3;
  int *instFlagMask;
  int *laneByteCursorB;
  int *laneByteCursorA;
  int *newSource2;
  undefined4 operandSelect;
  int destSelectSaved;
  undefined4 newSelect;
  int *lastOperandBuf0;
  int *lastOperandSourceSave;
  int chainDestSelect;
  int *lastOperandBuf2;
  int usedLanesOut [3];
  
  flagBit0Result = RegKind__flagBit0(inst[0x26]);
  if (flagBit0Result != 0) {
    vcall64Result = (**(code **)(*inst + 100))(inst);
    if (vcall64Result != 0) {
      for (operandIdxA = 1; operandCountA = (**(code **)(*inst + 0x14))(inst), operandIdxA <= operandCountA;
          operandIdxA = operandIdxA + 1) {
        if ((((inst[operandIdxA * 6 + 0x28] & 1U) != 0) || ((inst[operandIdxA * 6 + 0x28] & 2U) != 0)) ||
           (operandCountA = IRInst__isSourceSelectIdentity(inst,operandIdxA), operandCountA == 0)) goto setVcall64ResultD;
      }
      if ((inst[0x48] == 0) && (inst[0x49] == 0)) {
        if (((inst[0x20] != 0) &&
            ((operandIdxA = RegKind__flagBit0(inst[0x26]), operandIdxA != 0 && ((inst[5] & 2U) == 0)))) &&
           (operandIdxA = (**(code **)(*inst + 0x50))(inst), operandIdxA == 0)) {
          countdown = 4;
          laneByteCursorA = inst;
          do {
            if ((uint)(*(byte *)(laneByteCursorA + 0x27) - 2) < 2) goto setVcall64ResultD;
            laneByteCursorA = (int *)((int)laneByteCursorA + 1);
            countdown = countdown + -1;
          } while (countdown != 0);
        }
        IRInst__getOperandRecord(inst,0);
        predicateResultC = IRInst__operandKindClass(inst,0);
        if (predicateResultC == 0) {
          instFlagMask = (int *)(inst[5] & 2);
          if ((instFlagMask == (int *)0x0) && ((inst[5] & 0x200U) != 0)) {
            lastOperandBuf0 = instFlagMask;
            lastOperandSourceSave = instFlagMask;
            lastOperandBuf2 = instFlagMask;
            IRInst__readLastOperand(inst,&lastOperandBuf0);
            inst1 = lastOperandSourceSave;
            a0 = (int *)IRInst__getOperandSource(inst,1);
            if ((-1 < a0[5]) &&
               (((((a0[5] & 0x200U) == 0 && (predicateResultC = (**(code **)(*a0 + 0x24))(a0), predicateResultC != 0)) &&
                 (predicateResultC = IRInst__hasSingleUse(a0,program), predicateResultC != 0)) &&
                (predicateResultC = OpcodeTraits__flagBit9(*(undefined4 *)(a0[0x22] + 8),*(undefined4 *)(program + 8)),
                predicateResultC == 0)))) {
              operandRecord2 = IRInst__getOperandRecord(inst,0);
              destSelectSaved = *(int *)(operandRecord2 + 0x10);
              operandSelectWord = chainDestSelect;
              newSource2 = inst1;
loopCallIRInst_replaceBodyKeepLinks:
              IRInst__replaceBodyKeepLinks(inst,a0,program);
              vcall64ResultB = (**(code **)(*a0 + 100))(a0);
              if (vcall64ResultB != 0) {
                for (operandIdxB = 1; operandCountChain = (**(code **)(*a0 + 0x14))(a0), operandIdxB <= operandCountChain;
                    operandIdxB = operandIdxB + 1) {
                  if ((((a0[operandIdxB * 6 + 0x28] & 1U) != 0) || ((a0[operandIdxB * 6 + 0x28] & 2U) != 0)) ||
                     (identityResult = IRInst__isSourceSelectIdentity(a0,operandIdxB), identityResult == 0)) goto checkNewSource2;
                }
                if ((a0[0x48] == 0) && (a0[0x49] == 0)) {
                  if ((a0[0x20] != 0) &&
                     (((operandIdxB = RegKind__flagBit0(a0[0x26]), operandIdxB != 0 && ((a0[5] & 2U) == 0)) &&
                      (operandIdxB = (**(code **)(*a0 + 0x50))(a0), operandIdxB == 0)))) {
                    countdownB = 4;
                    inst1 = a0;
                    do {
                      if ((uint)(*(byte *)(inst1 + 0x27) - 2) < 2) goto checkNewSource2;
                      inst1 = (int *)((int)inst1 + 1);
                      countdownB = countdownB + -1;
                    } while (countdownB != 0);
                  }
                  IRInst__getOperandRecord(a0,0);
                  operandKindClassResult = IRInst__operandKindClass(a0,0);
                  if (((operandKindClassResult == 0) && ((a0[5] & 2U) == 0)) &&
                     (((a0[5] & 0x200U) == 0 &&
                      (inst1 = (int *)IRInst__getOperandSource(a0,1), inst1 == newSource2)))) {
                    operandRecord3 = IRInst__getOperandRecord(inst1,0);
                    loopIndex = 0;
                    operandSelect = *(undefined4 *)(operandRecord3 + 0x10);
                    countdownC = 4;
                    do {
                      if (*(char *)((int)&operandSelect + loopIndex) != '\x01') {
                        *(char *)((int)&destSelectSaved + loopIndex) = *(char *)((int)&operandSelect + loopIndex);
                      }
                      loopIndex = loopIndex + 1;
                      countdownC = countdownC + -1;
                    } while (countdownC != 0);
                    newSource2 = (int *)0x0;
                    inst1[0x58] = inst1[0x58] + -1;
                    if ((inst1[5] & 0x200U) != 0) {
                      newSource2 = (int *)IRInst__getOperandSource(inst1,inst1[0x21]);
                    }
                    newSelect = 0x4040404;
                    countdownC = 4;
                    loopIndex = 0;
                    do {
                      if (*(char *)((int)&destSelectSaved + loopIndex) != '\x01') {
                        *(undefined1 *)((int)&newSelect + loopIndex) =
                             *(undefined1 *)((int)&DAT_001b004c + loopIndex);
                      }
                      selectWordA = newSelect;
                      loopIndex = loopIndex + 1;
                      countdownC = countdownC + -1;
                    } while (countdownC != 0);
                    operandRecord = IRInst__getOperandRecord(inst,1);
                    *(undefined4 *)(operandRecord + 0x10) = selectWordA;
                  }
                }
              }
checkNewSource2:
              if (newSource2 != (int *)0x0) {
                IRInst__setExtraOperandSource(inst,newSource2,0,*(undefined4 *)(program + 8));
                if (inst[0x21] == 0) {
                  inst[0x27] = operandSelectWord;
                }
                else {
                  operandRecord = IRInst__getOperandRecord(inst,inst[0x21]);
                  *(int *)(operandRecord + 0x10) = operandSelectWord;
                }
              }
              inst[0x27] = destSelectSaved;
              *changedOut = 0;
              return 1;
            }
            if (((((a0[0x20] != 0) && (predicateResultC = RegKind__flagBit0(a0[0x26]), predicateResultC != 0)) &&
                 (((a0[5] & 2U) == 0 &&
                  ((predicateResultC = (**(code **)(*a0 + 0x50))(a0), predicateResultC == 0 &&
                   (predicateResultC = IRInst__hasSingleUse(a0,program), predicateResultC != 0)))))) && (-1 < inst1[5])) &&
               (((((inst1[5] & 0x200U) == 0 &&
                  (predicateResultC = (**(code **)(*inst1 + 0x24))(inst1), predicateResultC != 0)) &&
                 (predicateResultC = IRInst__hasSingleUse(inst1,program), predicateResultC != 0)) &&
                (predicateResultC = OpcodeTraits__flagBit9(*(undefined4 *)(inst1[0x22] + 8),*(undefined4 *)(program + 8)
                                     ), predicateResultC == 0)))) {
              WriteMask__fromUsedLanes(usedLanesOut,chainDestSelect);
              destSelectSaved = usedLanesOut[0];
              operandRecord2 = IRInst__getOperandRecord(inst,1);
              operandSelectWord = *(int *)(operandRecord2 + 0x10);
              newSource2 = a0;
              a0 = inst1;
              goto loopCallIRInst_replaceBodyKeepLinks;
            }
          }
        }
      }
    }
setVcall64ResultD:
    vcall64ResultD = (**(code **)(*inst + 100))(inst);
    if (((vcall64ResultD != 0) && (inst[0x48] == 0)) &&
       ((inst[0x49] == 0 && (((inst[0x2e] & 1U) == 0 && ((inst[0x2e] & 2U) == 0)))))) {
      if ((inst[0x20] != 0) &&
         (((vcall64ResultD = RegKind__flagBit0(inst[0x26]), vcall64ResultD != 0 && ((inst[5] & 2U) == 0)) &&
          (vcall64ResultD = (**(code **)(*inst + 0x50))(inst), vcall64ResultD == 0)))) {
        countdown = 4;
        laneByteCursorB = inst;
        do {
          if ((uint)(*(byte *)(laneByteCursorB + 0x27) - 2) < 2) {
            return 0;
          }
          laneByteCursorB = (int *)((int)laneByteCursorB + 1);
          countdown = countdown + -1;
        } while (countdown != 0);
      }
      IRInst__getOperandRecord(inst,0);
      predicateResultD = IRInst__operandKindClass(inst,0);
      if (predicateResultD == 0) {
        sourceDef = (int *)IRInst__getOperandSource(inst,1);
        if ((((-1 < sourceDef[5]) && ((sourceDef[5] & 0x200U) == 0)) &&
            ((predicateResultD = (**(code **)(*sourceDef + 0x24))(sourceDef), predicateResultD != 0 &&
             ((predicateResultD = IRInst__hasSingleUse(sourceDef,program), predicateResultD != 0 &&
              (predicateResultD = OpcodeTraits__flagBit9(*(undefined4 *)(sourceDef[0x22] + 8),*(undefined4 *)(program + 8)),
              predicateResultD == 0)))))) &&
           ((predicateResultD = IRInst__destIsSingleComponent(inst), predicateResultD != 0 && (predicateResultD = IRInst__destIsSingleComponent(sourceDef), predicateResultD != 0)
            ))) {
          flagBitResultE = OpcodeTraits__flagBit7(*(undefined4 *)(sourceDef[0x22] + 8),*(undefined4 *)(program + 8));
          if ((flagBitResultE == 0) &&
             (flagBitResultE = OpcodeTraits__flagBit8(*(undefined4 *)(sourceDef[0x22] + 8),*(undefined4 *)(program + 8)),
             flagBitResultE == 0)) {
            operandRecord2 = IRInst__getOperandRecord(sourceDef,0);
            firstWrittenComponentResult = SelectWord__firstWrittenComponent(*(undefined4 *)(operandRecord2 + 0x10));
            operandRecord = IRInst__getOperandRecord(inst,0);
            firstWrittenComponentResult2 = SelectWord__firstWrittenComponent(*(undefined4 *)(operandRecord + 0x10));
            for (operandIndex = 1; operandCountSource = (**(code **)(*sourceDef + 0x14))(sourceDef), operandIndex <= operandCountSource;
                operandIndex = operandIndex + 1) {
              operandRecord3 = IRInst__getOperandRecord(sourceDef,operandIndex);
              selectByteD = *(char *)(firstWrittenComponentResult + operandRecord3 + 0x10);
              operandRecordSrc = IRInst__getOperandRecord(sourceDef,operandIndex);
              *(undefined4 *)(operandRecordSrc + 0x10) = 0x4040404;
              if (selectByteD != '\x04') {
                (**(code **)(*sourceDef + 0x88))(sourceDef,operandIndex,firstWrittenComponentResult2,selectByteD);
              }
            }
          }
          newSource = 0;
          selectWordB = 0x10203;
          if ((inst[5] & 0x200U) != 0) {
            newSource = IRInst__getOperandSource(inst,inst[0x21]);
            operandRecord = IRInst__getOperandRecord(inst,inst[0x21]);
            selectWordB = *(undefined4 *)(operandRecord + 0x10);
          }
          operandRecord = IRInst__getOperandRecord(inst,0);
          operandSelectWordB = *(int *)(operandRecord + 0x10);
          instField3 = inst[3];
          IRInst__replaceBodyKeepLinks(inst,sourceDef,program);
          inst[0x27] = operandSelectWordB;
          inst[3] = instField3;
          if (newSource != 0) {
            IRInst__setExtraOperandSource(inst,newSource,0,*(undefined4 *)(program + 8));
            operandRecord2 = IRInst__getOperandRecord(inst,inst[0x21]);
            *(undefined4 *)(operandRecord2 + 0x10) = selectWordB;
          }
          *changedOut = 0;
          return 1;
        }
      }
    }
  }
  return 0;
}

/* Inst__operandModifiersAndSelectMatch @ 0x149d54 (144 bytes) */
int Inst__operandModifiersAndSelectMatch(inst, inst2, operandIndex)
  int inst;
  int inst2;
  int operandIndex;
{
  int operandRecord;
  int operandBase;
  uint modifiersA;
  uint modifiersB;
  int operandSelect;
  
  operandBase = operandIndex * 0x18 + 0x80;
  modifiersA = *(uint *)(inst + operandBase + 0x20);
  modifiersB = *(uint *)(inst2 + operandBase + 0x20);
  if (((modifiersA & 1) == (modifiersB & 1)) && ((modifiersA >> 1 & 1) == (modifiersB >> 1 & 1))) {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    operandSelect = *(int *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(inst2,operandIndex);
    if (operandSelect == *(int *)(operandRecord + 0x10)) {
      return 1;
    }
  }
  return 0;
}

/* Inst__tryComposeSelectWithProducer_00149de4 @ 0x149de4 (2740 bytes) */
int Inst__tryComposeSelectWithProducer_00149de4(inst, operandIndex8, inst2, composeSelectPtr, compiler)
  int *inst;
  int operandIndex8;
  int *inst2;
  undefined4 *composeSelectPtr;
  int compiler;
{
  int vcall60Result;
  int vcall58Result;
  uint negateFlag;
  undefined4 set2;
  undefined4 set;
  int operandIndex7;
  int operandIndex6;
  int operandIndex5;
  int operandIndex3;
  undefined4 sourceDef4;
  int operandRecord;
  int sourceDef2;
  int useCount;
  int operandRecord3;
  int sourceDef;
  int operandRecord2;
  int sourceDef5;
  int sourceDef3;
  int operandRecord4;
  int *operandVReg2;
  int *operandVReg;
  bool moreComponents;
  byte componentUnused;
  char selectByteC;
  int staleArg5;
  int instLastOperandIdx;
  int operandCountInst2;
  int singleUseCheck;
  int targetLegalResult;
  int targetCheckResult;
  int instLastOperandIdxB;
  int byteOffsetP;
  int chainOperandCount;
  int countdownM;
  int *producerCopy;
  int *chainProducerCopy;
  int *producerCopyB;
  int loopIndex;
  int constByteOffset;
  int operandIndex;
  undefined4 selectWordStored;
  undefined4 staleArg8;
  int operandIndex2;
  uint absFlag;
  int program;
  code *targetCheckFn;
  code *instAddSourceFn;
  uint componentByte;
  int operandIndex4;
  int *target;
  double scaleConstant;
  undefined4 composedSelect;
  undefined4 selectScratch [3];
  undefined4 composeOut [5];
  
  (**(code **)(*inst2 + 100))(inst2,operandIndex8,inst2,composeSelectPtr,compiler);
  (**(code **)(*inst + 0x60))(inst);
  vcall58Result = (**(code **)(*inst + 0x58))(inst);
  if (vcall58Result == 0) {
    operandRecord2 = IRInst__getOperandRecord(inst,operandIndex8);
    composedSelect = *(undefined4 *)(operandRecord2 + 0x10);
    SelectWord__compose(composeOut,*composeSelectPtr,composedSelect);
    target = *(int **)(compiler + COMP_target);
    composedSelect = composeOut[0];
    targetCheckFn = *(code **)(*target + 0x104);
    staleArg5 = IRInst__getOperandSource(inst2,1);
    /* dropped 5th arg (found auditing #70 via ExtendIndirectCalls.java / ground-truth
     * disassembly): stock passes the just-computed staleArg5 (inst2 source 1) in r7 too. */
    targetCheckResult = (*targetCheckFn)(target,inst,operandIndex8,&composedSelect,staleArg5);
    if (targetCheckResult != 0) {
      operandVReg = (int *)IRInst__getOperandSource(inst2,1);
      operandVReg2 = (int *)IRInst__getOperandSource(inst,operandIndex8);
      vcall60Result = (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
      if ((vcall60Result == 0) || ((inst2[0x2e] & 1U) == 0)) {
        program = *(int *)(compiler + COMP_currentProgram);
        vcall60Result = (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
        if (vcall60Result == 0) {
          negateFlag = inst2[0x2e] & 1;
          if ((inst[operandIndex8 * 6 + 0x28] & 2U) == 0) {
            absFlag = -(uint)(inst2[0x2e] & 2U) >> 0x1f;
          }
          else {
            absFlag = 1;
            negateFlag = 0;
          }
          negateFlag = inst[operandIndex8 * 6 + 0x28] & 1U ^ negateFlag;
          targetLegalResult = (**(code **)(**(int **)(compiler + COMP_target) + 0x11c))
                            (*(int **)(compiler + COMP_target),inst,operandIndex8,operandVReg,absFlag,negateFlag,
                             compiler);
          if (targetLegalResult == 0) {
            return 0;
          }
          *(int *)(program + 0x17c) = *(int *)(program + 0x17c) + 1;
          singleUseCheck = (**(code **)(*operandVReg + 0x5c))(operandVReg);
          if ((singleUseCheck == 0) || (singleUseCheck = IRInst__hasSingleUse(inst2,program), singleUseCheck != 0)) {
            producerCopy = operandVReg;
            if (*(int *)(program + 0x478) < operandVReg[0x58]) {
              operandVReg[0x58] = operandVReg[0x58] + 1;
            }
            else {
              operandVReg[0x58] = *(int *)(program + 0x478) + 1;
            }
          }
          else {
            producerCopy = (int *)IRInst__clone(operandVReg,compiler,0);
            producerCopy[0x26] = 0x31;
            producerCopy[0x25] = producerCopy[0x53];
            Block__insertInstAfter(operandVReg[0x56],operandVReg,producerCopy);
            producerCopy[0x58] = *(int *)(program + 0x478) + 1;
            sourceDef = IRInst__getOperandSource(producerCopy,1);
            if (*(int *)(program + 0x478) < *(int *)(sourceDef + 0x160)) {
              *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
            }
            else {
              *(int *)(sourceDef + 0x160) = *(int *)(program + 0x478) + 1;
            }
            if (1 < producerCopy[0x21]) {
              sourceDef = IRInst__getOperandSource(producerCopy,2);
              if (*(int *)(program + 0x478) < *(int *)(sourceDef + 0x160)) {
                *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
              }
              else {
                *(int *)(sourceDef + 0x160) = *(int *)(program + 0x478) + 1;
              }
            }
          }
          IRInst__setOperandSource(inst,operandIndex8,producerCopy,0,compiler);
          operandCountInst2 = (**(code **)(*inst2 + 0x14))(inst2);
          if ((inst2[5] & 0x200U) != 0) {
            operandCountInst2 = operandCountInst2 + 1;
          }
          countdownM = inst2[0x21];
          if (operandCountInst2 < countdownM) {
            if ((inst2[5] & 0x200U) != 0) {
              countdownM = countdownM + -1;
            }
            operandIndex5 = (**(code **)(*inst2 + 0x14))(inst2);
            while (operandIndex5 = operandIndex5 + 1, operandIndex5 <= countdownM) {
              sourceDef2 = IRInst__getOperandSource(inst2,operandIndex5);
              if (*(int *)(program + 0x478) < *(int *)(sourceDef2 + 0x160)) {
                *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
              }
              else {
                *(int *)(sourceDef2 + 0x160) = *(int *)(program + 0x478) + 1;
              }
              instAddSourceFn = *(code **)(*inst + 0x94);
              sourceDef4 = IRInst__getOperandSource(inst2,operandIndex5);
              (*instAddSourceFn)(inst,sourceDef4,compiler);
            }
          }
          selectWordStored = composedSelect;
          operandRecord2 = IRInst__getOperandRecord(inst,operandIndex8);
          *(undefined4 *)(operandRecord2 + 0x10) = selectWordStored;
          IROperand__setModifierBits(inst + operandIndex8 * 6 + 0x23,2,absFlag);
          IROperand__setModifierBits(inst + operandIndex8 * 6 + 0x23,1,negateFlag);
        }
        else {
          *(int *)(program + 0x17c) = *(int *)(program + 0x17c) + 1;
          vcall60Result = (**(code **)(*operandVReg + 0x60))(operandVReg);
          if (vcall60Result == 0) {
            operandRecord3 = IRInst__getOperandRecord(inst2,1);
            loopIndex = 0;
            selectScratch[0] = *(undefined4 *)(operandRecord3 + 0x10);
            do {
              operandRecord3 = IRInst__getOperandRecord(operandVReg2,1);
              componentByte = (uint)*(byte *)(loopIndex + operandRecord3 + 0x10);
              if (componentByte != 4) {
                (**(code **)(*operandVReg2 + 0x88))
                          (operandVReg2,1,loopIndex,(uint)*(byte *)((int)selectScratch + componentByte),staleArg5,staleArg8,
                           (int)selectScratch + (componentByte - 4));
                IRInst__getOperandRecord(inst2,0);
              }
              moreComponents = loopIndex != 3;
              loopIndex = loopIndex + 1;
            } while (moreComponents);
            singleUseCheck = (**(code **)(*operandVReg + 0x5c))(operandVReg);
            if ((singleUseCheck == 0) || (singleUseCheck = IRInst__hasSingleUse(inst2,program), singleUseCheck != 0)) {
              producerCopyB = operandVReg;
              if (*(int *)(program + 0x478) < operandVReg[0x58]) {
                operandVReg[0x58] = operandVReg[0x58] + 1;
              }
              else {
                operandVReg[0x58] = *(int *)(program + 0x478) + 1;
              }
            }
            else {
              producerCopyB = (int *)IRInst__clone(operandVReg,compiler,0);
              producerCopyB[0x26] = 0x31;
              producerCopyB[0x25] = producerCopyB[0x53];
              Block__insertInstAfter(operandVReg[0x56],operandVReg,producerCopyB);
              producerCopyB[0x58] = *(int *)(program + 0x478) + 1;
              sourceDef = IRInst__getOperandSource(producerCopyB,1);
              if (*(int *)(program + 0x478) < *(int *)(sourceDef + 0x160)) {
                *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
              }
              else {
                *(int *)(sourceDef + 0x160) = *(int *)(program + 0x478) + 1;
              }
              if (1 < producerCopyB[0x21]) {
                sourceDef = IRInst__getOperandSource(producerCopyB,2);
                if (*(int *)(program + 0x478) < *(int *)(sourceDef + 0x160)) {
                  *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
                }
                else {
                  *(int *)(sourceDef + 0x160) = *(int *)(program + 0x478) + 1;
                }
              }
            }
            IRInst__setOperandSource(operandVReg2,1,producerCopyB,0,compiler);
            if (((inst[operandIndex8 * 6 + 0x28] & 2U) != 0) || (set = 0, (inst2[0x2e] & 2U) != 0)
               ) {
              set = 1;
            }
            IROperand__setModifierBits(inst + operandIndex8 * 6 + 0x23,2,set);
            sourceDef4 = IRInst__getOperandSource(operandVReg2,1);
            if ((inst[5] & 0x200U) == 0) {
              instLastOperandIdx = inst[0x21];
            }
            else {
              instLastOperandIdx = inst[0x21] + -1;
            }
            operandIndex6 = (**(code **)(*inst + 0x14))(inst);
            do {
              operandIndex6 = operandIndex6 + 1;
              if (instLastOperandIdx < operandIndex6) goto callIRInst_dropCounterAndDeleteIfUnused;
              operandVReg = (int *)IRInst__getOperandSource(inst,operandIndex6);
            } while (inst2 != operandVReg);
            IRInst__setOperandSource(inst,operandIndex6,sourceDef4,0,compiler);
          }
          else {
            useCount = IRInst__useCount(operandVReg2,program);
            chainProducerCopy = operandVReg2;
            if (1 < useCount) {
              chainProducerCopy = (int *)IRInst__clone(operandVReg2,compiler,0);
              chainProducerCopy[0x26] = 0x36;
              chainProducerCopy[0x25] = chainProducerCopy[0x53];
              Block__insertInstBefore(inst[0x56],inst,chainProducerCopy);
              staleArg5 = compiler;
              IRInst__setOperandSource(inst,operandIndex8,chainProducerCopy,0,compiler);
              chainOperandCount = chainProducerCopy[0x21];
              operandVReg2[0x58] = operandVReg2[0x58] + -1;
              chainProducerCopy[0x58] = *(int *)(program + 0x478) + 1;
              if (0 < chainOperandCount) {
                operandIndex7 = 1;
                do {
                  sourceDef2 = IRInst__getOperandSource(chainProducerCopy,operandIndex7);
                  if (*(int *)(program + 0x478) < *(int *)(sourceDef2 + 0x160)) {
                    *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
                  }
                  else {
                    *(int *)(sourceDef2 + 0x160) = *(int *)(program + 0x478) + 1;
                  }
                  operandIndex7 = operandIndex7 + 1;
                } while (operandIndex7 <= chainProducerCopy[0x21]);
              }
            }
            loopIndex = 0;
            byteOffsetP = 0;
            do {
              operandRecord = IRInst__getOperandRecord(chainProducerCopy,1);
              componentByte = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
              operandRecord = IRInst__getOperandRecord(inst2,1);
              componentUnused = *(byte *)(componentByte + operandRecord + 0x10);
              operandRecord = IRInst__getOperandRecord(operandVReg,1);
              if (componentByte != 4) {
                if (*(char *)((uint)componentUnused + operandRecord + 0x10) == '\x04') {
                  (**(code **)(*chainProducerCopy + 0x88))
                            (chainProducerCopy,1,loopIndex,4,staleArg5,staleArg8,*(code **)(*chainProducerCopy + 0x88));
                  if (1 < operandVReg[0x21]) {
                    operandIndex2 = 2;
                    constByteOffset = 0x30;
                    do {
                      operandRecord4 = IRInst__getOperandRecord(operandVReg,operandIndex2);
                      selectByteC = *(char *)(loopIndex + operandRecord4 + 0x10);
                      if (selectByteC != '\x04') {
                        sourceDef3 = IRInst__getOperandSource(operandVReg,operandIndex2);
                        operandIndex4 = chainProducerCopy[0x21];
                        scaleConstant = (double)*(float *)(constByteOffset + sourceDef3 + 0x20);
                        if (1 < operandIndex4) {
                          operandIndex = 2;
                          do {
                            sourceDef5 = IRInst__getOperandSource(chainProducerCopy,operandIndex);
                            if (scaleConstant == (double)*(float *)(byteOffsetP + sourceDef5 + 0x20)) {
                              (**(code **)(*chainProducerCopy + 0x88))(chainProducerCopy,operandIndex,loopIndex,selectByteC);
                              goto setOperandIndex2;
                            }
                            operandIndex4 = chainProducerCopy[0x21];
                            operandIndex = operandIndex + 1;
                          } while (operandIndex <= operandIndex4);
                        }
                        operandIndex4 = operandIndex4 + 1;
                        chainProducerCopy[0x21] = operandIndex4;
                        ((void (*)())IRInst__makeLiteralVec4Float)(chainProducerCopy,program,operandIndex4,scaleConstant,scaleConstant,scaleConstant,scaleConstant);
                        operandRecord4 = IRInst__getOperandRecord(chainProducerCopy,operandIndex4);
                        *(undefined4 *)(operandRecord4 + 0x10) = 0x4040404;
                        (**(code **)(*chainProducerCopy + 0x88))(chainProducerCopy,operandIndex4,loopIndex,selectByteC);
                        sourceDef3 = IRInst__getOperandSource(chainProducerCopy,operandIndex4);
                        if (*(int *)(program + 0x478) < *(int *)(sourceDef3 + 0x160)) {
                          *(int *)(sourceDef3 + 0x160) = *(int *)(sourceDef3 + 0x160) + 1;
                        }
                        else {
                          *(int *)(sourceDef3 + 0x160) = *(int *)(program + 0x478) + 1;
                        }
                      }
setOperandIndex2:
                      operandIndex2 = operandIndex2 + 1;
                      constByteOffset = constByteOffset + 0x18;
                    } while (operandIndex2 <= operandVReg[0x21]);
                  }
                }
                else {
                  (**(code **)(*chainProducerCopy + 0x88))(chainProducerCopy,1,loopIndex);
                }
              }
              moreComponents = loopIndex != 3;
              byteOffsetP = byteOffsetP + 0x18;
              loopIndex = loopIndex + 1;
            } while (moreComponents);
            sourceDef = IRInst__getOperandSource(operandVReg,1);
            IRInst__setOperandSource(chainProducerCopy,1,sourceDef,0,compiler);
            if (*(int *)(program + 0x478) < *(int *)(sourceDef + 0x160)) {
              *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
            }
            else {
              *(int *)(sourceDef + 0x160) = *(int *)(program + 0x478) + 1;
            }
            if (((inst[operandIndex8 * 6 + 0x28] & 2U) != 0) || (set2 = 0, (inst2[0x2e] & 2U) != 0)
               ) {
              set2 = 1;
            }
            IROperand__setModifierBits(inst + operandIndex8 * 6 + 0x23,2,set2);
            if ((inst[5] & 0x200U) == 0) {
              instLastOperandIdxB = inst[0x21];
            }
            else {
              instLastOperandIdxB = inst[0x21] + -1;
            }
            operandIndex3 = (**(code **)(*inst + 0x14))(inst);
            do {
              operandIndex3 = operandIndex3 + 1;
              if (instLastOperandIdxB < operandIndex3) goto callIRInst_dropCounterAndDeleteIfUnused;
              operandVReg = (int *)IRInst__getOperandSource(inst,operandIndex3);
            } while (inst2 != operandVReg);
            IRInst__setOperandSource(inst,operandIndex3,sourceDef,0,compiler);
          }
        }
callIRInst_dropCounterAndDeleteIfUnused:
        IRInst__dropCounterAndDeleteIfUnused(inst2,compiler);
        return 1;
      }
    }
  }
  return 0;
}

/* Inst__extraSelectCoversDest @ 0x14a898 (128 bytes) */
int Inst__extraSelectCoversDest(inst, inst2)
  int inst;
  undefined4 inst2;
{
  bool isLast;
  int operandRecord;
  int loopIndex;
  undefined4 selectScratch [6];
  
  loopIndex = 0;
  operandRecord = IRInst__getOperandRecord(inst,*(undefined4 *)(inst + 0x84));
  selectScratch[0] = *(undefined4 *)(operandRecord + 0x10);
  while ((operandRecord = IRInst__getOperandRecord(inst2,0), *(char *)(loopIndex + operandRecord + 0x10) == '\x01' ||
         (*(char *)((int)selectScratch + loopIndex) != '\x04'))) {
    isLast = loopIndex == 3;
    loopIndex = loopIndex + 1;
    if (isLast) {
      return 1;
    }
  }
  return 0;
}

/* Inst__swizzleTextureFetchOutput @ 0x14a918 (708 bytes) */
int Inst__swizzleTextureFetchOutput(inst, operandIndex, program)
  int *inst;
  int operandIndex;
  int program;
{
  int loopIndex;
  int beforeInst;
  int isIdentity;
  int operandRecord;
  int operandRecord2;
  uint targetFlags;
  int *selectBytePtr;
  int *lastOperandSource;
  int producerCheck;
  int selectWordValue;
  int consumerCheck;
  int isOptionEnabledResult;
  int *operandVReg;
  undefined4 inst1;
  int countdown;
  int selectWordAndLastOperand [2];
  int *lastOperandSourceOut;
  undefined4 lastOperandRecordTail;
  int composedSelectOut [4];
  
  targetFlags = *(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8);
  if ((((targetFlags & 0x800) != 0) && ((targetFlags & 0x1000) != 0)) &&
     (isOptionEnabledResult = Compiler__isOptionEnabled(*(int *)(program + 8),0x38), isOptionEnabledResult != 0)) {
    operandVReg = (int *)IRInst__getOperandSource(inst,operandIndex);
    operandRecord2 = IRInst__getOperandRecord(inst,operandIndex);
    selectWordAndLastOperand[0] = *(int *)(operandRecord2 + 0x10);
    producerCheck = (**(code **)(*operandVReg + 0x30))(operandVReg);
    if (((producerCheck != 0) && (producerCheck = IRInst__hasSingleUse(operandVReg,program), producerCheck != 0)) &&
       ((operandVReg[5] & 0x200U) == 0)) {
      isIdentity = SelectWord__isIdentity(selectWordAndLastOperand[0]);
      if (isIdentity == 0) {
        SelectWord__compose(composedSelectOut,operandVReg[0x50],selectWordAndLastOperand[0]);
        loopIndex = 0;
        selectWordAndLastOperand[0] = composedSelectOut[0];
        operandVReg[0x50] = composedSelectOut[0];
        countdown = 4;
        selectBytePtr = operandVReg + 0x27;
        do {
          if (*(char *)((int)selectWordAndLastOperand + loopIndex) == '\x04') {
            *(undefined1 *)selectBytePtr = 1;
          }
          else {
            *(undefined1 *)selectBytePtr = 0;
            *(char *)((int)selectWordAndLastOperand + loopIndex) = (char)loopIndex;
          }
          loopIndex = loopIndex + 1;
          selectBytePtr = (int *)((int)selectBytePtr + 1);
          countdown = countdown + -1;
        } while (countdown != 0);
      }
      lastOperandRecordTail = 0;
      selectWordAndLastOperand[1] = 0;
      lastOperandSourceOut = (int *)0x0;
      if ((inst[5] & 0x200U) != 0) {
        IRInst__readLastOperand(inst,selectWordAndLastOperand + 1);
      }
      lastOperandSource = lastOperandSourceOut;
      consumerCheck = (**(code **)(*inst + 100))(inst);
      if (((consumerCheck == 0) ||
          (((lastOperandSource != (int *)0x0 &&
            ((consumerCheck = (**(code **)(*lastOperandSource + 0x30))(lastOperandSource), consumerCheck == 0 ||
             (consumerCheck = ((int (*)())Inst__extraSelectCoversDest)(inst,lastOperandSource), consumerCheck == 0)))) ||
           ((inst[operandIndex * 6 + 0x28] & 1U) != 0)))) ||
         (((((inst[operandIndex * 6 + 0x28] & 2U) != 0 || (inst[0x48] != 0)) ||
           (inst[0x49] != 0)) || (consumerCheck = IRInst__hasSingleUse(inst,program), consumerCheck == 0)))) {
        operandRecord = IRInst__getOperandRecord(inst,operandIndex);
        selectWordValue = selectWordAndLastOperand[0];
        if (*(int *)(operandRecord + 0x10) != selectWordAndLastOperand[0]) {
          if (operandIndex == 0) {
            inst[0x27] = selectWordAndLastOperand[0];
            return 1;
          }
          operandRecord = IRInst__getOperandRecord(inst,operandIndex);
          *(int *)(operandRecord + 0x10) = selectWordValue;
          return 1;
        }
      }
      else {
        beforeInst = inst[2];
        DList__unlink(operandVReg);
        DList__unlink(inst);
        inst1 = IRInst__cloneInto(operandVReg,inst,*(undefined4 *)(program + 8),1);
        Block__insertInstBefore(*(undefined4 *)(beforeInst + 0x158),beforeInst,inst1);
        if (lastOperandSource != (int *)0x0) {
          IRInst__setLastOperandFromRecord(inst1,selectWordAndLastOperand + 1,0,*(undefined4 *)(program + 8));
        }
      }
      return 1;
    }
  }
  return 0;
}

/* Inst__tryCopyPropagate @ 0x14abdc (220 bytes) */
int Inst__tryCopyPropagate(inst, program, foldStatus)
  int *inst;
  undefined4 program;
  undefined4 foldStatus;
{
  int changedResult;
  int isMovResult;
  int isMixResult;
  undefined4 fetchSwizzleResult;
  undefined4 result;
  
  isMixResult = (**(code **)(*inst + 0x60))(inst,program,foldStatus);
  if (isMixResult != 0) {
    inst = (int *)IRInst__getOperandSource(inst,1);
  }
  isMovResult = (**(code **)(*inst + 100))(inst);
  result = 0;
  if (isMovResult != 0) {
    ((int (*)())Inst__foldOutputScaleChain)(inst,program);
    ((int (*)())Inst__mergeLaneProducers_00148d8c)(inst,program);
    ((int (*)())Inst__cloneSplatProducer_00148980)(inst,program);
    fetchSwizzleResult = ((int (*)())Inst__swizzleTextureFetchOutput)(inst,1,program);
    changedResult = ((int (*)())Inst__foldChainedDest_001494dc)(inst,program,foldStatus);
    result = 1;
    if (changedResult == 0) {
      result = fetchSwizzleResult;
    }
  }
  return result;
}

/* Inst__collapseMulSplatByDotOnes @ 0x14acb8 (852 bytes) */
int Inst__collapseMulSplatByDotOnes(inst, program)
  int *inst;
  int program;
{
  int dotOperandBase;
  int vectorSelect;
  int splatSelect;
  int dotSaturate;
  int prevNode;
  int lanesLeft;
  int extraSource;
  int onesSourceIndex;
  uint splatLane;
  int isSplat;
  int lanesWritten;
  int hasSingleUse;
  undefined4 sourceDef5;
  int operandRecord3;
  int operandRecord4;
  int sourceDef4;
  int sourceDef3;
  int sourceDef2;
  int operandRecord2;
  int sourceDef;
  int operandRecord;
  int sourceOpcode;
  uint vectorSourceModifiers;
  int isOnesConstant;
  int vectorSourceIndex;
  int laneScanIndex;
  undefined4 laneCheckMask;
  int destSelect;
  uint dotSourceIndex;
  undefined4 compiler;
  int destRegister;
  int scalarSourceIndex;
  undefined4 scalarSelectWord;
  undefined4 savedCounters0;
  undefined4 savedCounters1;
  undefined4 savedCounters2;
  undefined4 onesLane0;
  undefined4 onesLane1;
  undefined4 onesLane2;
  undefined4 onesLane3;
  
  compiler = *(undefined4 *)(program + 8);
  if (inst == (int *)0x0) {
    return 0;
  }
  if (*(int *)(inst[0x22] + 8) != 0x13) {
    return 0;
  }
  if (inst[0x48] != 0) {
    return 0;
  }
  if (inst[0x49] != 0) {
    return 0;
  }
  sourceDef2 = IRInst__getOperandSource(inst,1);
  sourceDef3 = IRInst__getOperandSource(inst,2);
  sourceOpcode = *(int *)(*(int *)(sourceDef2 + 0x88) + 8);
  if ((((sourceOpcode == 0x1c) || (sourceOpcode == 0x1d)) && (*(int *)(sourceDef2 + 0x120) == 0)) &&
     (lanesWritten = IRInst__sourceLanesAllWritten(inst,1), lanesWritten != 0)) {
    operandRecord = IRInst__getOperandRecord(inst,2);
    isSplat = SelectWord__isSplat(*(undefined4 *)(operandRecord + 0x10));
    if (isSplat != 0) {
      hasSingleUse = IRInst__hasSingleUse(sourceDef2,program);
      dotSourceIndex = 1;
      if (hasSingleUse != 0) goto setSourceDef;
    }
  }
  sourceOpcode = *(int *)(*(int *)(sourceDef3 + 0x88) + 8);
  if ((sourceOpcode != 0x1c) && (sourceOpcode != 0x1d)) {
    return 0;
  }
  if (*(int *)(sourceDef3 + 0x120) != 0) {
    return 0;
  }
  lanesWritten = IRInst__sourceLanesAllWritten(inst,2);
  if (lanesWritten == 0) {
    return 0;
  }
  operandRecord = IRInst__getOperandRecord(inst,1);
  isSplat = SelectWord__isSplat(*(undefined4 *)(operandRecord + 0x10));
  if (isSplat == 0) {
    return 0;
  }
  hasSingleUse = IRInst__hasSingleUse(sourceDef3,program);
  if (hasSingleUse == 0) {
    return 0;
  }
  dotSourceIndex = 2;
setSourceDef:
  sourceDef = IRInst__getOperandSource(inst,dotSourceIndex);
  laneCheckMask = DAT_001b0170;
  onesLane3 = 0x3f800000;
  onesLane0 = 0x3f800000;
  onesLane1 = 0x3f800000;
  onesLane2 = 0x3f800000;
  isOnesConstant = IRInst__sourceMatchesConstant(sourceDef,1,DAT_001b0170,&onesLane0);
  if (isOnesConstant == 0) {
    isOnesConstant = IRInst__sourceMatchesConstant(sourceDef,2,laneCheckMask,&onesLane0);
    if (isOnesConstant == 0) {
      return 0;
    }
    vectorSourceIndex = 1;
    onesSourceIndex = 2;
  }
  else {
    vectorSourceIndex = 2;
    onesSourceIndex = 1;
  }
  vectorSourceModifiers = *(uint *)(vectorSourceIndex * 0x18 + sourceDef + 0xa0);
  if (((vectorSourceModifiers & 1) == 0) && ((vectorSourceModifiers & 2) == 0)) {
    *(int *)(program + 0x1f0) = *(int *)(program + 0x1f0) + 1;
    sourceDef4 = IRInst__getOperandSource(sourceDef,onesSourceIndex);
    scalarSourceIndex = ((int)-(dotSourceIndex ^ 1) >> 0x1f) + 2;
    *(int *)(sourceDef4 + 0x160) = *(int *)(sourceDef4 + 0x160) + -1;
    sourceDef5 = IRInst__getOperandSource(inst,scalarSourceIndex);
    operandRecord4 = IRInst__getOperandRecord(inst,0);
    destSelect = *(int *)(operandRecord4 + 0x10);
    operandRecord2 = IRInst__getOperandRecord(inst,scalarSourceIndex);
    laneScanIndex = 0;
    scalarSelectWord = *(undefined4 *)(operandRecord2 + 0x10);
    lanesLeft = 4;
    do {
      splatLane = (uint)*(byte *)((int)&scalarSelectWord + laneScanIndex);
      if (splatLane != 4) goto setExtraSource;
      laneScanIndex = laneScanIndex + 1;
      lanesLeft = lanesLeft + -1;
    } while (lanesLeft != 0);
    splatLane = 0xffffffff;
setExtraSource:
    extraSource = 0;
    if ((inst[5] & 0x200U) != 0) {
      extraSource = IRInst__getOperandSource(inst,inst[0x21]);
    }
    savedCounters0 = 0;
    savedCounters1 = 0;
    savedCounters2 = 0;
    IRInst__saveCounters(inst,&savedCounters0,0xffffffff);
    destRegister = inst[0x53];
    prevNode = inst[1];
    DList__unlink(inst);
    IRInst__reinitAsBinary(inst,*(undefined4 *)(*(int *)(sourceDef + 0x88) + 8),*(undefined4 *)(program + 8));
    IRInst__restoreCounters(inst,&savedCounters0);
    Block__insertInstAfter(*(undefined4 *)(prevNode + 0x158),prevNode,inst);
    dotSaturate = *(int *)(sourceDef + 0x120);
    inst[0x49] = *(int *)(sourceDef + 0x124);
    inst[0x48] = dotSaturate;
    inst[0x25] = destRegister;
    inst[0x26] = 0;
    inst[0x27] = destSelect;
    inst[0x53] = destRegister;
    IRInst__setOperandSource(inst,onesSourceIndex,sourceDef5,0,compiler);
    splatSelect = *(int *)(PTR_DAT_001e8b8c + splatLane * 4);
    if (onesSourceIndex == 0) {
      inst[0x27] = splatSelect;
    }
    else {
      operandRecord3 = IRInst__getOperandRecord(inst,onesSourceIndex);
      *(int *)(operandRecord3 + 0x10) = splatSelect;
    }
    if (*(int *)(inst[0x22] + 8) == 0x1c) {
      (**(code **)(*inst + 0x88))(inst,onesSourceIndex,3,4);
    }
    sourceDef2 = IRInst__getOperandSource(sourceDef,vectorSourceIndex);
    IRInst__setOperandSource(inst,vectorSourceIndex,sourceDef2,0,compiler);
    operandRecord2 = IRInst__getOperandRecord(sourceDef,vectorSourceIndex);
    vectorSelect = *(int *)(operandRecord2 + 0x10);
    if (vectorSourceIndex == 0) {
      inst[0x27] = vectorSelect;
    }
    else {
      operandRecord3 = IRInst__getOperandRecord(inst,vectorSourceIndex);
      *(int *)(operandRecord3 + 0x10) = vectorSelect;
    }
    dotOperandBase = sourceDef + vectorSourceIndex * 0x18 + 0x80;
    IROperand__setModifierBits(inst + vectorSourceIndex * 6 + 0x23,1,*(uint *)(dotOperandBase + 0x20) & 1);
    IROperand__setModifierBits(inst + vectorSourceIndex * 6 + 0x23,2,*(uint *)(dotOperandBase + 0x20) >> 1 & 1);
    if (extraSource != 0) {
      IRInst__setExtraOperandSource(inst,extraSource,0,compiler);
    }
    if (*(int *)(program + 0x478) < *(int *)(sourceDef2 + 0x160)) {
      *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
    }
    else {
      *(int *)(sourceDef2 + 0x160) = *(int *)(program + 0x478) + 1;
    }
    IRInst__dropCounterAndDeleteIfUnused(sourceDef,compiler);
  }
  return 0;
}

/* Inst__collapseAddIntoMadMulAddend @ 0x14b150 (1696 bytes) */
int Inst__collapseAddIntoMadMulAddend(inst, program)
  int inst;
  int program;
{
  undefined4 outerSrc3SelectOut;
  undefined4 rebuiltSrc3Select;
  undefined4 rebuiltSrc2Select;
  undefined4 rebuiltSrc1Select;
  undefined4 mulDestSelect;
  int depthBase2;
  int lanesLeft;
  int mulExtraSource;
  int instExtraSource;
  int mulPrevNode;
  int lane;
  int checkResult;
  int depthBase;
  int prevNode;
  int hasSingleUse;
  undefined4 operandRecord3;
  undefined4 operandRecord4;
  int operandRecord2;
  int sourceDef3;
  int sourceDef;
  int sourceDef2;
  undefined1 selectByte;
  char srcSelectByte;
  uint selectComponent;
  int reassocOk;
  int instDepthAboveBase;
  int lanesWritten;
  int mulInst;
  int lanesAllWritten;
  undefined4 operandVReg;
  undefined4 operandVReg2;
  undefined4 instSaturate;
  undefined4 operandRecord;
  uint outerSrc3Flags;
  undefined4 mulSaturate;
  undefined4 mulResultScale;
  undefined4 mulDestRegisterOffset;
  undefined4 instResultScale;
  int src2Opcode;
  undefined4 instDestRegisterOffset;
  undefined4 instDestSelect;
  int src1Opcode;
  undefined4 madOperandIndex;
  undefined4 otherOperandIndex;
  undefined4 madOperandSelect;
  undefined4 mulSrc1Select;
  undefined4 mulSrc2Select;
  undefined4 outerSrc3Select;
  undefined4 otherOperandSelect;
  undefined4 newSelect3;
  undefined4 newSelect1;
  undefined4 newSelect2;
  undefined4 outerSrc3NewSelect;
  undefined4 mulSrc2Record;
  undefined4 mulSrc2Record1;
  undefined4 mulSrc2Record5;
  undefined4 instMadRecord;
  undefined4 instMadRecord1;
  undefined4 instMadRecord5;
  undefined4 instOtherRecord;
  undefined4 instOtherRecord1;
  undefined4 instOtherRecord5;
  undefined4 mulSrc1Record;
  undefined4 mulSrc1Record1;
  undefined4 mulSrc1Record5;
  int mulDepthAboveBase;
  int outerMad;
  int otherAddend;
  undefined4 *instMadRecordPtr;
  undefined4 *instOtherRecordPtr;
  undefined4 *mulSrc1RecordPtr;
  undefined4 *mulSrc2RecordPtr;
  
  if ((*(int *)(*(int *)(inst + 0x88) + 8) == 0x12) && (*(int *)(inst + 0x120) == 0)) {
    sourceDef2 = IRInst__getOperandSource(inst,1);
    sourceDef = IRInst__getOperandSource(inst,2);
    src1Opcode = *(int *)(*(int *)(sourceDef2 + 0x88) + 8);
    src2Opcode = *(int *)(*(int *)(sourceDef + 0x88) + 8);
    sourceDef3 = IRInst__getOperandSource(sourceDef2,3);
    mulInst = IRInst__getOperandSource(sourceDef,3);
    if (((((*(uint *)(inst + 0xb8) & 1) == 0) &&
         ((((*(uint *)(inst + 0xb8) & 2) == 0 && (lanesAllWritten = IRInst__sourceLanesAllWritten(inst,1), lanesAllWritten != 0))
          && (src1Opcode == 0x14)))) &&
        ((((checkResult = IRInst__hasSingleUse(sourceDef2,program), checkResult != 0 && (*(int *)(sourceDef2 + 0x120) == 0)) &&
          (*(int *)(sourceDef2 + 0x124) == 0)) &&
         (((*(uint *)(sourceDef2 + 0xe8) & 2) == 0 && (checkResult = IRInst__sourceLanesAllWritten(sourceDef2,3), checkResult != 0))))))
       && ((*(int *)(*(int *)(sourceDef3 + 0x88) + 8) == 0x13 &&
           (((checkResult = IRInst__hasSingleUse(sourceDef3,program), checkResult != 0 && (*(int *)(sourceDef3 + 0x120) == 0))
            && (*(int *)(sourceDef3 + 0x124) == *(int *)(inst + 0x124))))))) {
      madOperandIndex = 1;
      otherOperandIndex = 2;
      mulInst = sourceDef3;
      outerMad = sourceDef2;
      otherAddend = sourceDef;
    }
    else {
      if ((*(uint *)(inst + 0xd0) & 1) != 0) {
        return 0;
      }
      if ((*(uint *)(inst + 0xd0) & 2) != 0) {
        return 0;
      }
      lanesWritten = IRInst__sourceLanesAllWritten(inst,2);
      if (lanesWritten == 0) {
        return 0;
      }
      if (src2Opcode != 0x14) {
        return 0;
      }
      hasSingleUse = IRInst__hasSingleUse(sourceDef,program);
      if (hasSingleUse == 0) {
        return 0;
      }
      if (*(int *)(sourceDef + 0x120) != 0) {
        return 0;
      }
      if (*(int *)(sourceDef + 0x124) != 0) {
        return 0;
      }
      if ((*(uint *)(sourceDef + 0xe8) & 2) != 0) {
        return 0;
      }
      lanesWritten = IRInst__sourceLanesAllWritten(sourceDef,3);
      if (lanesWritten == 0) {
        return 0;
      }
      if (*(int *)(*(int *)(mulInst + 0x88) + 8) != 0x13) {
        return 0;
      }
      hasSingleUse = IRInst__hasSingleUse(mulInst,program);
      if (hasSingleUse == 0) {
        return 0;
      }
      if (*(int *)(mulInst + 0x120) != 0) {
        return 0;
      }
      if (*(int *)(mulInst + 0x124) != *(int *)(inst + 0x124)) {
        return 0;
      }
      madOperandIndex = 2;
      otherOperandIndex = 1;
      outerMad = sourceDef;
      otherAddend = sourceDef2;
    }
    reassocOk = Inst__isBeforeOrSame(otherAddend,mulInst);
    if (reassocOk != 0) {
      *(int *)(program + 0x1dc) = *(int *)(program + 0x1dc) + 1;
      mulDepthAboveBase = *(int *)(mulInst + 0x160) - *(int *)(program + 0x478);
      if (mulDepthAboveBase < 0) {
        mulDepthAboveBase = 0;
      }
      mulSaturate = *(undefined4 *)(mulInst + 0x120);
      mulExtraSource = 0;
      mulResultScale = *(undefined4 *)(mulInst + 0x124);
      IRInst__getOperandRecord(mulInst,0);
      if ((*(uint *)(mulInst + 0x14) & 0x200) != 0) {
        mulExtraSource = IRInst__getOperandSource(mulInst,*(undefined4 *)(mulInst + 0x84));
      }
      mulDestRegisterOffset = *(undefined4 *)(mulInst + 0x98);
      operandVReg = IRInst__getOperandSource(mulInst,1);
      operandVReg2 = IRInst__getOperandSource(mulInst,2);
      mulSrc2Record5 = 0;
      mulSrc1Record = 0;
      mulSrc1Record1 = 0;
      mulSrc1Record5 = 0;
      mulSrc2Record = 0;
      mulSrc2Record1 = 0;
      operandRecord4 = IRInst__getOperandRecord(mulInst,1);
      mulSrc1RecordPtr = &mulSrc1Record;
      IROperand__copyFrom(mulSrc1RecordPtr,operandRecord4);
      operandRecord4 = IRInst__getOperandRecord(mulInst,2);
      mulSrc2RecordPtr = &mulSrc2Record;
      IROperand__copyFrom(mulSrc2RecordPtr,operandRecord4);
      instDepthAboveBase = *(int *)(inst + 0x160) - *(int *)(program + 0x478);
      outerSrc3Flags = *(uint *)(outerMad + 0xe8);
      if (instDepthAboveBase < 0) {
        instDepthAboveBase = 0;
      }
      instSaturate = *(undefined4 *)(inst + 0x120);
      instExtraSource = 0;
      instResultScale = *(undefined4 *)(inst + 0x124);
      operandRecord2 = IRInst__getOperandRecord(inst,0);
      instDestSelect = *(undefined4 *)(operandRecord2 + 0x10);
      if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
        instExtraSource = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
      }
      instOtherRecord5 = 0;
      instMadRecord = 0;
      instMadRecord1 = 0;
      instMadRecord5 = 0;
      instOtherRecord = 0;
      instOtherRecord1 = 0;
      instDestRegisterOffset = *(undefined4 *)(inst + 0x98);
      operandRecord = IRInst__getOperandRecord(inst,madOperandIndex);
      instMadRecordPtr = &instMadRecord;
      IROperand__copyFrom(instMadRecordPtr,operandRecord);
      operandRecord = IRInst__getOperandRecord(inst,otherOperandIndex);
      instOtherRecordPtr = &instOtherRecord;
      IROperand__copyFrom(instOtherRecordPtr,operandRecord);
      outerSrc3NewSelect = DAT_001b0050;
      newSelect3 = DAT_001b0050;
      newSelect1 = DAT_001b0050;
      newSelect2 = DAT_001b0050;
      operandRecord2 = IRInst__getOperandRecord(mulInst,1);
      mulSrc1Select = *(undefined4 *)(operandRecord2 + 0x10);
      operandRecord2 = IRInst__getOperandRecord(mulInst,2);
      mulSrc2Select = *(undefined4 *)(operandRecord2 + 0x10);
      operandRecord2 = IRInst__getOperandRecord(outerMad,3);
      outerSrc3Select = *(undefined4 *)(operandRecord2 + 0x10);
      operandRecord2 = IRInst__getOperandRecord(inst,otherOperandIndex);
      otherOperandSelect = *(undefined4 *)(operandRecord2 + 0x10);
      operandRecord2 = IRInst__getOperandRecord(inst,madOperandIndex);
      lane = 0;
      madOperandSelect = *(undefined4 *)(operandRecord2 + 0x10);
      lanesLeft = 4;
      do {
        srcSelectByte = *(char *)((int)&otherOperandSelect + lane);
        if (srcSelectByte != '\x04') {
          selectComponent = (uint)*(byte *)((int)&madOperandSelect + lane);
          *(byte *)((int)&outerSrc3NewSelect + selectComponent) = *(byte *)((int)&madOperandSelect + lane);
          *(char *)((int)&newSelect3 + selectComponent) = srcSelectByte;
          selectByte = *(undefined1 *)((int)&mulSrc1Select + (uint)*(byte *)((int)&outerSrc3Select + selectComponent));
          *(undefined1 *)((int)&newSelect2 + selectComponent) =
               *(undefined1 *)((int)&mulSrc2Select + (uint)*(byte *)((int)&outerSrc3Select + selectComponent));
          *(undefined1 *)((int)&newSelect1 + selectComponent) = selectByte;
        }
        lane = lane + 1;
        lanesLeft = lanesLeft + -1;
      } while (lanesLeft != 0);
      operandRecord2 = IRInst__getOperandRecord(outerMad,0);
      mulPrevNode = *(int *)(mulInst + 4);
      mulDestSelect = *(undefined4 *)(operandRecord2 + 0x10);
      DList__unlink(mulInst);
      IRInst__reinitAsTrinary(mulInst,0x14,*(undefined4 *)(program + 8));
      Block__insertInstAfter(*(undefined4 *)(mulPrevNode + 0x158),mulPrevNode,mulInst);
      *(undefined4 *)(mulInst + 0x120) = mulSaturate;
      *(undefined4 *)(mulInst + 0x124) = mulResultScale;
      *(undefined4 *)(mulInst + 0x9c) = mulDestSelect;
      depthBase2 = *(int *)(program + 0x478);
      *(undefined4 *)(mulInst + 0x98) = mulDestRegisterOffset;
      *(int *)(mulInst + 0x160) = mulDepthAboveBase + depthBase2;
      *(undefined4 *)(mulInst + 0x94) = *(undefined4 *)(mulInst + 0x14c);
      IRInst__setOperandSource(mulInst,1,operandVReg,0,*(undefined4 *)(program + 8));
      operandRecord3 = IRInst__getOperandRecord(mulInst,1);
      IROperand__copyFrom(operandRecord3,mulSrc1RecordPtr);
      rebuiltSrc1Select = newSelect1;
      operandRecord2 = IRInst__getOperandRecord(mulInst,1);
      *(undefined4 *)(operandRecord2 + 0x10) = rebuiltSrc1Select;
      IRInst__setOperandSource(mulInst,2,operandVReg2,0,*(undefined4 *)(program + 8));
      operandRecord3 = IRInst__getOperandRecord(mulInst,2);
      IROperand__copyFrom(operandRecord3,mulSrc2RecordPtr);
      rebuiltSrc2Select = newSelect2;
      operandRecord2 = IRInst__getOperandRecord(mulInst,2);
      *(undefined4 *)(operandRecord2 + 0x10) = rebuiltSrc2Select;
      IRInst__setOperandSource(mulInst,3,otherAddend,0,*(undefined4 *)(program + 8));
      operandRecord3 = IRInst__getOperandRecord(mulInst,3);
      IROperand__copyFrom(operandRecord3,instOtherRecordPtr);
      rebuiltSrc3Select = newSelect3;
      operandRecord2 = IRInst__getOperandRecord(mulInst,3);
      *(undefined4 *)(operandRecord2 + 0x10) = rebuiltSrc3Select;
      if ((outerSrc3Flags & 1) != 0) {
        IROperand__setModifierBits(mulInst + 0xd4,1,(*(uint *)(mulInst + 0xe8) ^ 1) & 1);
      }
      outerSrc3SelectOut = outerSrc3NewSelect;
      operandRecord2 = IRInst__getOperandRecord(outerMad,3);
      *(undefined4 *)(operandRecord2 + 0x10) = outerSrc3SelectOut;
      if (mulExtraSource != 0) {
        IRInst__setExtraOperandSource(mulInst,mulExtraSource,0,*(undefined4 *)(program + 8));
      }
      prevNode = *(int *)(inst + 4);
      DList__unlink(inst);
      IRInst__reinitAsMov(inst,0x31,*(undefined4 *)(program + 8));
      Block__insertInstAfter(*(undefined4 *)(prevNode + 0x158),prevNode,inst);
      *(undefined4 *)(inst + 0x120) = instSaturate;
      *(undefined4 *)(inst + 0x124) = instResultScale;
      *(undefined4 *)(inst + 0x9c) = instDestSelect;
      depthBase = *(int *)(program + 0x478);
      *(undefined4 *)(inst + 0x98) = instDestRegisterOffset;
      *(int *)(inst + 0x160) = instDepthAboveBase + depthBase;
      *(undefined4 *)(inst + 0x94) = *(undefined4 *)(inst + 0x14c);
      IRInst__setOperandSource(inst,1,outerMad,0,*(undefined4 *)(program + 8));
      operandRecord3 = IRInst__getOperandRecord(inst,1);
      IROperand__copyFrom(operandRecord3,instMadRecordPtr);
      if (instExtraSource != 0) {
        IRInst__setExtraOperandSource(inst,instExtraSource,0,*(undefined4 *)(program + 8));
      }
      return 1;
    }
  }
  return 0;
}

/* Inst__collapseAddOfMulToMad @ 0x14b82c (952 bytes) */
int Inst__collapseAddOfMulToMad(inst, program, skipUseLists, requireSingleUse)
  int inst;
  int program;
  int skipUseLists;
  int requireSingleUse;
{
  undefined4 addendIndex;
  int depthBase;
  int prevNode;
  int srcLoopIndex;
  int mulSourceIndex;
  int newSrc2;
  int newSrc1;
  int addend;
  int checkResult2;
  int mulInst;
  undefined4 operandRecord2;
  int sourceDef2;
  int operandRecord5;
  int operandRecord3;
  int sourceDef;
  bool hasExtraSource;
  bool trackUses;
  uint mulOperandFlags;
  int canFuse;
  int depthAboveBase;
  int checkResult;
  undefined4 result;
  int operandRecord4;
  undefined4 operandVReg;
  undefined4 operandRecord;
  undefined4 mulSrc2Select;
  undefined4 useList;
  undefined4 allocatedRegister;
  undefined4 destRegisterOffset;
  undefined4 saturate;
  undefined4 resultScale;
  undefined4 destSelect;
  undefined4 mulUseSelect;
  int source2Opcode;
  undefined4 mulSrc1Select;
  undefined4 mulSrc1Record;
  undefined4 mulSrc1Record1;
  undefined4 mulSrc1Record5;
  undefined4 mulSrc2Record;
  undefined4 mulSrc2Record1;
  undefined4 mulSrc2Record5;
  undefined4 addendRecord;
  undefined4 addendRecord1;
  undefined4 addendRecord5;
  undefined4 composedSelect1;
  undefined4 composedSelect2;
  undefined4 mulSrc2Def;
  int extraSource;
  undefined4 extraSelect;
  undefined4 *mulSrc2RecordPtr;
  undefined4 *addendRecordPtr;
  
  canFuse = ((int (*)())Inst__canFuseAddMul)(inst,program,requireSingleUse);
  if (canFuse == 0) {
loopSetResult:
    result = 0;
  }
  else {
    mulInst = IRInst__getOperandSource(inst,1);
    sourceDef = IRInst__getOperandSource(inst,2);
    source2Opcode = *(int *)(*(int *)(sourceDef + 0x88) + 8);
    if (((((*(int *)(*(int *)(mulInst + 0x88) + 8) == 0x13) && ((*(uint *)(inst + 0xb8) & 2) == 0))
         && (checkResult = IRInst__sourceLanesAllWritten(inst,1), checkResult != 0)) &&
        ((*(int *)(mulInst + 0x120) == 0 && (*(int *)(mulInst + 0x124) == 0)))) &&
       ((requireSingleUse == 0 || (checkResult = IRInst__hasSingleUse(mulInst,program), checkResult != 0)))) {
      mulSourceIndex = 1;
      addendIndex = 2;
      addend = sourceDef;
    }
    else {
      if ((((source2Opcode != 0x13) || ((*(uint *)(inst + 0xd0) & 2) != 0)) ||
          ((checkResult2 = IRInst__sourceLanesAllWritten(inst,2), checkResult2 == 0 ||
           ((*(int *)(sourceDef + 0x120) != 0 || (*(int *)(sourceDef + 0x124) != 0)))))) ||
         ((requireSingleUse != 0 && (checkResult2 = IRInst__hasSingleUse(sourceDef,program), checkResult2 == 0)))) goto loopSetResult;
      mulSourceIndex = 2;
      addendIndex = 1;
      addend = mulInst;
      mulInst = sourceDef;
    }
    *(int *)(program + 0x1d4) = *(int *)(program + 0x1d4) + 1;
    depthAboveBase = *(int *)(inst + 0x160) - *(int *)(program + 0x478);
    if (depthAboveBase < 0) {
      depthAboveBase = 0;
    }
    useList = *(undefined4 *)(inst + 0x10);
    allocatedRegister = *(undefined4 *)(inst + 0x14c);
    destRegisterOffset = *(undefined4 *)(inst + 0x98);
    saturate = *(undefined4 *)(inst + 0x120);
    resultScale = *(undefined4 *)(inst + 0x124);
    operandRecord4 = IRInst__getOperandRecord(inst,0);
    destSelect = *(undefined4 *)(operandRecord4 + 0x10);
    extraSource = 0;
    if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
      extraSource = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
    }
    hasExtraSource = extraSource != 0;
    extraSelect = DAT_001b004c;
    if (hasExtraSource) {
      operandRecord4 = IRInst__getOperandRecord(inst,*(undefined4 *)(inst + 0x84));
      extraSelect = *(undefined4 *)(operandRecord4 + 0x10);
    }
    operandRecord4 = IRInst__getOperandRecord(inst,mulSourceIndex);
    mulUseSelect = *(undefined4 *)(operandRecord4 + 0x10);
    mulOperandFlags = *(uint *)(mulSourceIndex * 0x18 + inst + 0xa0);
    operandVReg = IRInst__getOperandSource(mulInst,1);
    mulSrc2Def = IRInst__getOperandSource(mulInst,2);
    operandRecord5 = IRInst__getOperandRecord(mulInst,1);
    mulSrc1Select = *(undefined4 *)(operandRecord5 + 0x10);
    operandRecord5 = IRInst__getOperandRecord(mulInst,2);
    mulSrc2Select = *(undefined4 *)(operandRecord5 + 0x10);
    addendRecord5 = 0;
    mulSrc1Record = 0;
    mulSrc1Record1 = 0;
    mulSrc1Record5 = 0;
    mulSrc2Record = 0;
    mulSrc2Record1 = 0;
    mulSrc2Record5 = 0;
    addendRecord = 0;
    addendRecord1 = 0;
    operandRecord = IRInst__getOperandRecord(mulInst,1);
    IROperand__copyFrom(&mulSrc1Record,operandRecord);
    operandRecord = IRInst__getOperandRecord(mulInst,2);
    mulSrc2RecordPtr = &mulSrc2Record;
    IROperand__copyFrom(mulSrc2RecordPtr,operandRecord);
    operandRecord2 = IRInst__getOperandRecord(inst,addendIndex);
    addendRecordPtr = &addendRecord;
    IROperand__copyFrom(addendRecordPtr,operandRecord2);
    if (0 < *(int *)(inst + 0x84)) {
      srcLoopIndex = 1;
      do {
        sourceDef2 = IRInst__getOperandSource(inst,srcLoopIndex);
        *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + -1;
        if (skipUseLists != 0) {
          sourceDef2 = IRInst__getOperandSource(inst,srcLoopIndex);
          Vector__removeValue(*(undefined4 *)(sourceDef2 + 0x10),inst);
        }
        srcLoopIndex = srcLoopIndex + 1;
      } while (srcLoopIndex <= *(int *)(inst + 0x84));
    }
    prevNode = *(int *)(inst + 4);
    DList__unlink(inst);
    IRInst__reinitAsTrinary(inst,0x14,*(undefined4 *)(program + 8));
    trackUses = skipUseLists == 0;
    Block__insertInstAfter(*(undefined4 *)(prevNode + 0x158),prevNode,inst);
    depthBase = *(int *)(program + 0x478);
    *(undefined4 *)(inst + 0x10) = useList;
    *(undefined4 *)(inst + 0x120) = saturate;
    *(int *)(inst + 0x160) = depthAboveBase + depthBase;
    *(undefined4 *)(inst + 0x124) = resultScale;
    *(undefined4 *)(inst + 0x9c) = destSelect;
    *(undefined4 *)(inst + 0x94) = allocatedRegister;
    *(undefined4 *)(inst + 0x98) = destRegisterOffset;
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    IROperand__copyModifiersAndSelect(operandRecord2,&mulSrc1Record);
    newSrc1 = IRInst__cloneIfPresub(operandVReg,program,skipUseLists);
    IRInst__setOperandSource(inst,1,newSrc1,skipUseLists,*(undefined4 *)(program + 8));
    if (trackUses) {
      if (*(int *)(program + 0x478) < *(int *)(newSrc1 + 0x160)) {
        *(int *)(newSrc1 + 0x160) = *(int *)(newSrc1 + 0x160) + 1;
      }
      else {
        *(int *)(newSrc1 + 0x160) = *(int *)(program + 0x478) + 1;
      }
    }
    SelectWord__compose(&composedSelect1,mulSrc1Select,mulUseSelect);
    operandRecord3 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord3 + 0x10) = composedSelect1;
    if ((mulOperandFlags & 1) != 0) {
      IROperand__setModifierBits(inst + 0xa4,1,(*(uint *)(inst + 0xb8) ^ 1) & 1);
    }
    operandRecord2 = IRInst__getOperandRecord(inst,2);
    IROperand__copyModifiersAndSelect(operandRecord2,mulSrc2RecordPtr);
    newSrc2 = IRInst__cloneIfPresub(mulSrc2Def,program,skipUseLists);
    IRInst__setOperandSource(inst,2,newSrc2,skipUseLists,*(undefined4 *)(program + 8));
    if (trackUses) {
      if (*(int *)(program + 0x478) < *(int *)(newSrc2 + 0x160)) {
        *(int *)(newSrc2 + 0x160) = *(int *)(newSrc2 + 0x160) + 1;
      }
      else {
        *(int *)(newSrc2 + 0x160) = *(int *)(program + 0x478) + 1;
      }
    }
    SelectWord__compose(&composedSelect2,mulSrc2Select,mulUseSelect);
    operandRecord3 = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord3 + 0x10) = composedSelect2;
    operandRecord2 = IRInst__getOperandRecord(inst,3);
    IROperand__copyModifiersAndSelect(operandRecord2,addendRecordPtr);
    IRInst__setOperandSource(inst,3,addend,skipUseLists,*(undefined4 *)(program + 8));
    if (trackUses) {
      if (*(int *)(program + 0x478) < *(int *)(addend + 0x160)) {
        *(int *)(addend + 0x160) = *(int *)(addend + 0x160) + 1;
      }
      else {
        *(int *)(addend + 0x160) = *(int *)(program + 0x478) + 1;
      }
    }
    if (hasExtraSource) {
      IRInst__setExtraOperandSource(inst,extraSource,skipUseLists,*(undefined4 *)(program + 8));
      operandRecord3 = IRInst__getOperandRecord(inst,*(undefined4 *)(inst + 0x84));
      *(undefined4 *)(operandRecord3 + 0x10) = extraSelect;
      if (trackUses) {
        if (*(int *)(program + 0x478) < *(int *)(extraSource + 0x160)) {
          *(int *)(extraSource + 0x160) = *(int *)(extraSource + 0x160) + 1;
        }
        else {
          *(int *)(extraSource + 0x160) = *(int *)(program + 0x478) + 1;
        }
      }
    }
    IRInst__deleteIfUnused(mulInst,*(undefined4 *)(program + 8),skipUseLists);
    result = 1;
  }
  return result;
}

/* Inst__collapseMulOfAddWithUnitConstant @ 0x14bdbc (1912 bytes) */
int Inst__collapseMulOfAddWithUnitConstant(inst, program)
  int inst;
  int program;
{
  uint callArgScratch2;
  undefined4 destRegisterOffset;
  uint src3Negate;
  uint callArgScratch;
  uint addOtherFlags;
  uint mulOperandFlags;
  int src1Set;
  int clonedRegister2;
  int addOtherIndex;
  int depthBase;
  int otherSrcIndex;
  int hwResult;
  int clonedRegister;
  int src3Set;
  int compilerCopy;
  int presubTest;
  int srcLoopIndex2;
  int srcLoopIndex;
  int presubFlag;
  int presubSource2;
  int sourceCount2;
  int presubSource1;
  int sourceCount1;
  int noDistEnabled;
  int sourceDef;
  int operandRecord;
  int operandRecord4;
  int operandRecord3;
  int operandRecord2;
  bool allUnit;
  float constantLane;
  uint addOperandFlags;
  uint selectedComponent;
  int recordOffset;
  int operandVReg;
  int addSrcIndex;
  int madOperandBase;
  int *madSrc1Def;
  void *inst2;
  int madOperand2Base;
  int *madSrc3Def;
  undefined4 a1;
  int laneIndex;
  undefined4 instResultScale;
  undefined4 otherSelect;
  uint unitSign;
  int mulSrcIndex;
  undefined4 mulOperandSelect;
  uint a2;
  uint instFlags;
  int compiler;
  int lanesLeft;
  undefined4 instDestSelect;
  undefined4 mulOperandSelectWord;
  undefined4 addSrcSelectWord;
  undefined4 addDestSelectWord;
  undefined4 lastOperandRecord;
  int lastOperandSource;
  undefined4 lastOperandRecord5;
  undefined4 composedSelect;
  uint addOtherAbs;
  uint addOperandNegate;
  uint otherOperandAbs;
  uint otherOperandNegate;
  int *mulOtherSource;
  undefined4 instSaturate;
  int useCount;
  int *insertAfter;
  undefined4 composedSelectCopy;
  int otherOperandOffset;
  int recordFlagsBase;
  
  compiler = *(int *)(program + 8);
  noDistEnabled = Compiler__isOptionEnabled(compiler,0x2a);
  if (((noDistEnabled == 0) && (inst != 0)) && (*(int *)(*(int *)(inst + 0x88) + 8) == 0x13)) {
    operandRecord3 = IRInst__getOperandRecord(inst,0);
    mulSrcIndex = 1;
    instDestSelect = *(undefined4 *)(operandRecord3 + 0x10);
    recordOffset = 0x98;
    do {
      operandVReg = IRInst__getOperandSource(inst,mulSrcIndex);
      if (((*(int *)(*(int *)(operandVReg + 0x88) + 8) == 0x12) && (*(int *)(operandVReg + 0x120) == 0)) &&
         ((*(int *)(operandVReg + 0x124) == 0 &&
          (((*(uint *)(inst + recordOffset + 0x20) & 2) == 0 && ((*(uint *)(operandVReg + 0x14) & 0x200) == 0)
           ))))) {
        operandRecord4 = IRInst__getOperandRecord(inst,mulSrcIndex);
        mulOperandSelectWord = *(undefined4 *)(operandRecord4 + 0x10);
        addSrcIndex = 1;
        recordFlagsBase = inst + recordOffset;
        do {
          operandRecord = IRInst__getOperandRecord(operandVReg,addSrcIndex);
          addSrcSelectWord = *(undefined4 *)(operandRecord + 0x10);
          unitSign = 0;
          operandRecord = IRInst__getOperandRecord(operandVReg,0);
          addDestSelectWord = *(undefined4 *)(operandRecord + 0x10);
          sourceDef = IRInst__getOperandSource(operandVReg,addSrcIndex);
          lanesLeft = 4;
          allUnit = true;
          laneIndex = 0;
          do {
            if (*(char *)((int)&instDestSelect + laneIndex) != '\0') goto setLaneIndex;
            selectedComponent = (uint)*(byte *)((int)&addSrcSelectWord + (uint)*(byte *)((int)&mulOperandSelectWord + laneIndex));
            if ((*(char *)((int)&addDestSelectWord + (uint)*(byte *)((int)&mulOperandSelectWord + laneIndex)) == '\0') &&
               (((int)*(char *)(sourceDef + 0x15c) >> (selectedComponent & 0x3f) & 1U) != 0)) {
              constantLane = *(float *)(selectedComponent * 0x18 + sourceDef + 0x20);
              if (constantLane == -1.0) {
                if (0 < (int)unitSign) goto setAllUnit;
                unitSign = 0xffffffff;
              }
              else {
                if ((constantLane != 1.0) || ((int)unitSign < 0)) goto setAllUnit;
                unitSign = 1;
              }
            }
            else {
setAllUnit:
              allUnit = false;
            }
setLaneIndex:
            laneIndex = laneIndex + 1;
            lanesLeft = lanesLeft + -1;
          } while (lanesLeft != 0);
          if ((allUnit) &&
             ((hwResult = (**(code **)(**(int **)(compiler + 0x30c) + 0x88))(*(int **)(compiler + 0x30c)),
              hwResult != 0 || ((*(uint *)(addSrcIndex * 0x18 + sourceDef + 0xa0) & 2) == 0)))) {
            insertAfter = *(int **)(inst + 4);
            useCount = IRInst__useCount(inst,program);
            instSaturate = *(undefined4 *)(inst + 0x120);
            otherSrcIndex = (mulSrcIndex == 1) + 1;
            instResultScale = *(undefined4 *)(inst + 0x124);
            mulOtherSource = (int *)IRInst__getOperandSource(inst,otherSrcIndex);
            operandRecord = IRInst__getOperandRecord(inst,otherSrcIndex);
            otherSelect = *(undefined4 *)(operandRecord + 0x10);
            otherOperandOffset = otherSrcIndex * 0x18 + 0x80;
            mulOperandFlags = *(uint *)(inst + otherOperandOffset + 0x20);
            otherOperandNegate = mulOperandFlags & 1;
            otherOperandAbs = mulOperandFlags >> 1 & 1;
            operandRecord = IRInst__getOperandRecord(inst,mulSrcIndex);
            mulOperandSelect = *(undefined4 *)(operandRecord + 0x10);
            addOtherIndex = (addSrcIndex == 1) + 1;
            addOperandNegate = *(uint *)(recordFlagsBase + 0x20) & 1;
            madSrc1Def = (int *)IRInst__getOperandSource(operandVReg,addOtherIndex);
            operandRecord = IRInst__getOperandRecord(operandVReg,addOtherIndex);
            addOtherFlags = *(uint *)(addOtherIndex * 0x18 + operandVReg + 0xa0);
            addOtherAbs = addOtherFlags >> 1 & 1;
            SelectWord__compose(&composedSelect,*(undefined4 *)(operandRecord + 0x10),mulOperandSelect);
            instFlags = *(uint *)(inst + 0x14);
            addOperandFlags = *(uint *)(addSrcIndex * 0x18 + operandVReg + 0xa0);
            lastOperandRecord5 = 0;
            lastOperandRecord = 0;
            lastOperandSource = 0;
            composedSelectCopy = composedSelect;
            if ((instFlags & 0x200) != 0) {
              IRInst__readLastOperand(inst,&lastOperandRecord);
              instFlags = *(uint *)(inst + 0x14);
            }
            destRegisterOffset = *(undefined4 *)(inst + 0x98);
            inst2 = IRInst__create(0x14,*(undefined4 *)(program + 8));
            if ((instFlags & 2) != 0) {
              *(uint *)((int)inst2 + 0x14) = *(uint *)((int)inst2 + 0x14) | 2;
            }
            *(undefined4 *)((int)inst2 + 0xc) = *(undefined4 *)(inst + 0xc);
            *(undefined4 *)((int)inst2 + 0x94) = *(undefined4 *)((int)inst2 + 0x14c);
            *(undefined4 *)((int)inst2 + 0x98) = destRegisterOffset;
            *(undefined4 *)((int)inst2 + 0x120) = instSaturate;
            *(undefined4 *)((int)inst2 + 0x9c) = instDestSelect;
            *(undefined4 *)((int)inst2 + 0x124) = instResultScale;
            IRInst__setOperandSource(inst2,otherSrcIndex,mulOtherSource,0,compiler);
            operandRecord = IRInst__getOperandRecord(inst2,otherSrcIndex);
            *(undefined4 *)(operandRecord + 0x10) = otherSelect;
            madOperandBase = (int)inst2 + otherOperandOffset + 0xc;
            IROperand__setModifierBits(madOperandBase,2,otherOperandAbs);
            IROperand__setModifierBits(madOperandBase,1,otherOperandNegate);
            depthBase = *(int *)(program + 0x478);
            presubTest = (**(code **)(*madSrc1Def + 0x5c))(madSrc1Def);
            if (presubTest != 0) {
              madSrc1Def = (int *)IRInst__clone(madSrc1Def,*(undefined4 *)(program + 8),0);
              clonedRegister2 = madSrc1Def[0x53];
              operandRecord = IRInst__getOperandRecord(madSrc1Def,0);
              *(int *)(operandRecord + 8) = clonedRegister2;
              madSrc1Def[0x58] = depthBase;
            }
            a2 = addOperandNegate ^ addOtherFlags & 1;
            callArgScratch = addOtherAbs;
            callArgScratch2 = a2;
            compilerCopy = compiler;
            src1Set = IRInst__setOperandSourceIfLegal(inst2,mulSrcIndex,madSrc1Def,addOtherAbs,a2,compiler);
            operandRecord2 = IRInst__getOperandRecord(inst2,mulSrcIndex);
            *(undefined4 *)(operandRecord2 + 0x10) = composedSelectCopy;
            madOperand2Base = (int)inst2 + recordOffset + 0xc;
            IROperand__setModifierBits(madOperand2Base,2,addOtherAbs);
            IROperand__setModifierBits(madOperand2Base,1,a2);
            madSrc3Def = mulOtherSource;
            presubTest = (**(code **)(*mulOtherSource + 0x5c))(mulOtherSource,a1,a2,callArgScratch,callArgScratch2,compilerCopy,mulOtherSource);
            if (presubTest != 0) {
              madSrc3Def = (int *)IRInst__clone(mulOtherSource,*(undefined4 *)(program + 8),0);
              clonedRegister = madSrc3Def[0x53];
              operandRecord = IRInst__getOperandRecord(madSrc3Def,0);
              *(int *)(operandRecord + 8) = clonedRegister;
              madSrc3Def[0x58] = depthBase;
            }
            src3Negate = otherOperandNegate ^ addOperandNegate ^ addOperandFlags & 1 ^ unitSign >> 0x1f;
            src3Set = IRInst__setOperandSourceIfLegal(inst2,3,madSrc3Def,otherOperandAbs,src3Negate,compiler);
            operandRecord2 = IRInst__getOperandRecord(inst2,3);
            *(undefined4 *)(operandRecord2 + 0x10) = otherSelect;
            IROperand__setModifierBits((int)inst2 + 0xd4,2,otherOperandAbs);
            IROperand__setModifierBits((int)inst2 + 0xd4,1,src3Negate);
            if (lastOperandSource != 0) {
              IRInst__setLastOperandFromRecord(inst2,&lastOperandRecord,0,compiler);
            }
            *(int *)((int)inst2 + 0x160) = useCount + *(int *)(program + 0x478);
            if (src3Set != 0 && src1Set != 0) {
              *(int *)(program + 0x1d0) = *(int *)(program + 0x1d0) + 1;
              presubFlag = (**(code **)(*madSrc1Def + 0x5c))(madSrc1Def);
              if (presubFlag != 0) {
                for (srcLoopIndex = 1; sourceCount1 = (**(code **)(*madSrc1Def + 0x14))(madSrc1Def), srcLoopIndex <= sourceCount1;
                    srcLoopIndex = srcLoopIndex + 1) {
                  presubSource1 = IRInst__getOperandSource(madSrc1Def,srcLoopIndex);
                  if (depthBase < *(int *)(presubSource1 + 0x160)) {
                    *(int *)(presubSource1 + 0x160) = *(int *)(presubSource1 + 0x160) + 1;
                  }
                  else {
                    *(int *)(presubSource1 + 0x160) = depthBase + 1;
                  }
                }
                Block__insertInstAfter(insertAfter[0x56],insertAfter,madSrc1Def);
                insertAfter = madSrc1Def;
              }
              if (*(int *)(program + 0x478) < madSrc1Def[0x58]) {
                madSrc1Def[0x58] = madSrc1Def[0x58] + 1;
              }
              else {
                madSrc1Def[0x58] = *(int *)(program + 0x478) + 1;
              }
              presubFlag = (**(code **)(*madSrc3Def + 0x5c))(madSrc3Def);
              if (presubFlag != 0) {
                for (srcLoopIndex2 = 1; sourceCount2 = (**(code **)(*madSrc3Def + 0x14))(madSrc3Def), srcLoopIndex2 <= sourceCount2;
                    srcLoopIndex2 = srcLoopIndex2 + 1) {
                  presubSource2 = IRInst__getOperandSource(madSrc3Def,srcLoopIndex2);
                  if (depthBase < *(int *)(presubSource2 + 0x160)) {
                    *(int *)(presubSource2 + 0x160) = *(int *)(presubSource2 + 0x160) + 1;
                  }
                  else {
                    *(int *)(presubSource2 + 0x160) = depthBase + 1;
                  }
                }
                Block__insertInstAfter(insertAfter[0x56],insertAfter,madSrc3Def);
                insertAfter = madSrc3Def;
              }
              if (*(int *)(program + 0x478) < madSrc3Def[0x58]) {
                madSrc3Def[0x58] = madSrc3Def[0x58] + 1;
              }
              else {
                madSrc3Def[0x58] = *(int *)(program + 0x478) + 1;
              }
              DList__unlink(inst);
              _memcpy(inst,inst2,0x164);
              Block__insertInstAfter(insertAfter[0x56],insertAfter,inst);
              IRInst__dropCounterAndDeleteIfUnused(operandVReg,compiler);
              return 1;
            }
          }
          allUnit = addSrcIndex != 2;
          addSrcIndex = addSrcIndex + 1;
        } while (allUnit);
      }
      allUnit = mulSrcIndex != 2;
      recordOffset = recordOffset + 0x18;
      mulSrcIndex = mulSrcIndex + 1;
    } while (allUnit);
  }
  return 0;
}

/* Inst__combineOperandSelects @ 0x14c534 (208 bytes) */
int Inst__combineOperandSelects(outSelect, inst, operandIndex, inst2, operandIndex2)
  undefined4 *outSelect;
  undefined4 inst;
  undefined4 operandIndex;
  undefined4 inst2;
  undefined4 operandIndex2;
{
  bool moreComponents;
  int operandRecord;
  int loopIndex;
  int loopIndex2;
  undefined4 selectScratch [9];
  
  loopIndex = 0;
  loopIndex2 = 0;
  *outSelect = DAT_001b0050;
  do {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    selectScratch[0] = *(undefined4 *)(operandRecord + 0x10);
    if (*(char *)((int)selectScratch + loopIndex2) != '\x04') {
      *(char *)((int)outSelect + loopIndex) = *(char *)((int)selectScratch + loopIndex2);
      loopIndex = loopIndex + 1;
    }
    moreComponents = loopIndex2 != 3;
    loopIndex2 = loopIndex2 + 1;
  } while (moreComponents);
  loopIndex2 = 0;
  do {
    operandRecord = IRInst__getOperandRecord(inst2,operandIndex2);
    selectScratch[0] = *(undefined4 *)(operandRecord + 0x10);
    if ((loopIndex < 4) && (*(char *)((int)selectScratch + loopIndex2) != '\x04')) {
      *(char *)((int)outSelect + loopIndex) = *(char *)((int)selectScratch + loopIndex2);
      loopIndex = loopIndex + 1;
    }
    moreComponents = loopIndex2 != 3;
    loopIndex2 = loopIndex2 + 1;
  } while (moreComponents);
  return outSelect;
}

/* Inst__matchOperandPairs @ 0x14c604 (972 bytes) */
int Inst__matchOperandPairs(inst, otherInst, pass, outSelectA, outSelectB, outMatched)
  undefined4 inst;
  undefined4 otherInst;
  int pass;
  undefined4 *outSelectA;
  undefined4 *outSelectB;
  int *outMatched;
{
  int callResult;
  int callResult4;
  int callResult2;
  int callResult3;
  undefined4 operandVReg;
  undefined4 operandMaskA;
  undefined4 operandMaskB [3];
  undefined4 selInst1Other1;
  undefined4 selInst2Other2;
  undefined4 selOther1Inst1;
  undefined4 selOther2Inst2;
  undefined4 selInst1Other2;
  undefined4 selInst2Other1;
  undefined4 selOther1Inst2;
  undefined4 selOther2Inst1 [4];
  
  operandMaskB[0] = 0;
  operandMaskA = 0;
  callResult = ((int (*)())Inst__trySwapOperandSources)(inst,1,otherInst,1,pass,0,&operandMaskA);
  callResult4 = ((int (*)())Inst__trySwapOperandSources)(inst,1,otherInst,2,pass,0,&operandMaskA);
  callResult2 = ((int (*)())Inst__trySwapOperandSources)(inst,2,otherInst,2,pass,0,operandMaskB);
  callResult3 = ((int (*)())Inst__trySwapOperandSources)(inst,2,otherInst,1,pass,0,operandMaskB);
  if ((callResult == 0) || (callResult2 == 0)) {
    if (callResult4 == 0) {
      return 0;
    }
    if (callResult3 == 0) {
      return 0;
    }
    if (callResult == 0) {
      ((int (*)())Inst__combineOperandSelects)(&selInst1Other2,inst,1,otherInst,2);
      *outSelectA = selInst1Other2;
      ((int (*)())Inst__combineOperandSelects)(&selInst2Other1,inst,2,otherInst,1);
      *outSelectB = selInst2Other1;
      operandVReg = IRInst__getOperandSource(inst,1);
      callResult4 = Target__acceptsSelect(outSelectA,operandVReg,operandMaskA,*(undefined4 *)(pass + 8));
      if (callResult4 == 0) {
loopCallInst_combineOperandSelects:
        ((int (*)())Inst__combineOperandSelects)(&selOther1Inst2,otherInst,1,inst,2);
        *outSelectA = selOther1Inst2;
        ((int (*)())Inst__combineOperandSelects)(selOther2Inst1,otherInst,2,inst,1);
        *outSelectB = selOther2Inst1[0];
        operandVReg = IRInst__getOperandSource(inst,1);
        callResult4 = Target__acceptsSelect(outSelectA,operandVReg,operandMaskA,*(undefined4 *)(pass + 8));
        if (callResult4 == 0) {
          return 0;
        }
        operandVReg = IRInst__getOperandSource(inst,2);
        callResult4 = Target__acceptsSelect(outSelectB,operandVReg,operandMaskB[0],*(undefined4 *)(pass + 8));
        if (callResult4 == 0) {
          return 0;
        }
      }
      else {
        operandVReg = IRInst__getOperandSource(inst,2);
        callResult4 = Target__acceptsSelect(outSelectB,operandVReg,operandMaskB[0],*(undefined4 *)(pass + 8));
        if (callResult4 == 0) goto loopCallInst_combineOperandSelects;
      }
      ((int (*)())Inst__trySwapOperandSources)(inst,1,otherInst,2,pass,1,&operandMaskA);
      ((int (*)())Inst__trySwapOperandSources)(inst,2,otherInst,1,pass,1,operandMaskB);
      goto storeOutMatched;
    }
  }
  ((int (*)())Inst__combineOperandSelects)(&selInst1Other1,inst,1,otherInst,1);
  *outSelectA = selInst1Other1;
  ((int (*)())Inst__combineOperandSelects)(&selInst2Other2,inst,2,otherInst,2);
  *outSelectB = selInst2Other2;
  operandVReg = IRInst__getOperandSource(inst,1);
  callResult4 = Target__acceptsSelect(outSelectA,operandVReg,operandMaskA,*(undefined4 *)(pass + 8));
  if (callResult4 == 0) {
loopCallInst_combineOperandSelects2:
    ((int (*)())Inst__combineOperandSelects)(&selOther1Inst1,otherInst,1,inst,1);
    *outSelectA = selOther1Inst1;
    ((int (*)())Inst__combineOperandSelects)(&selOther2Inst2,otherInst,2,inst,2);
    *outSelectB = selOther2Inst2;
    operandVReg = IRInst__getOperandSource(inst,1);
    callResult4 = Target__acceptsSelect(outSelectA,operandVReg,operandMaskA,*(undefined4 *)(pass + 8));
    if (callResult4 == 0) {
      return 0;
    }
    operandVReg = IRInst__getOperandSource(inst,2);
    callResult4 = Target__acceptsSelect(outSelectB,operandVReg,operandMaskB[0],*(undefined4 *)(pass + 8));
    if (callResult4 == 0) {
      return 0;
    }
  }
  else {
    operandVReg = IRInst__getOperandSource(inst,2);
    callResult4 = Target__acceptsSelect(outSelectB,operandVReg,operandMaskB[0],*(undefined4 *)(pass + 8));
    if (callResult4 == 0) goto loopCallInst_combineOperandSelects2;
  }
  ((int (*)())Inst__trySwapOperandSources)(inst,1,otherInst,1,pass,1,&operandMaskA);
  ((int (*)())Inst__trySwapOperandSources)(inst,2,otherInst,2,pass,1,operandMaskB);
storeOutMatched:
  *outMatched = callResult;
  return 1;
}

/* Inst__mergeSelectsFrom @ 0x14c9d0 (284 bytes) */
int Inst__mergeSelectsFrom(inst, inst2)
  int *inst;
  undefined4 inst2;
{
  int vcall14Result;
  int operandRecord;
  int vcall5cResult;
  undefined4 operandSelect;
  int mergedLanesOut;
  undefined4 fillUnusedOutA;
  undefined4 fillUnusedOutB [4];
  
  vcall5cResult = (**(code **)(*inst + 0x5c))(inst,inst2);
  if (vcall5cResult != 0) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    operandSelect = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(inst2,0);
    SelectWord__mergeWrittenLanes(&mergedLanesOut,operandSelect,*(undefined4 *)(operandRecord + 0x10));
    inst[0x27] = mergedLanesOut;
    operandRecord = IRInst__getOperandRecord(inst,1);
    operandSelect = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(inst2,1);
    SelectWord__fillUnusedLanes(&fillUnusedOutA,operandSelect,*(undefined4 *)(operandRecord + 0x10));
    operandRecord = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord + 0x10) = fillUnusedOutA;
    vcall14Result = (**(code **)(*inst + 0x14))(inst);
    if (vcall14Result == 2) {
      operandRecord = IRInst__getOperandRecord(inst,2);
      operandSelect = *(undefined4 *)(operandRecord + 0x10);
      operandRecord = IRInst__getOperandRecord(inst2,2);
      SelectWord__fillUnusedLanes(fillUnusedOutB,operandSelect,*(undefined4 *)(operandRecord + 0x10));
      operandRecord = IRInst__getOperandRecord(inst,2);
      *(undefined4 *)(operandRecord + 0x10) = fillUnusedOutB[0];
    }
  }
  return;
}

/* Inst__collapseMadOfMulToDot2Add @ 0x14caec (988 bytes) */
int Inst__collapseMadOfMulToDot2Add(inst, program)
  int *inst;
  int program;
{
  int prevNode;
  int saturate;
  int canMerge;
  int addendOpcode;
  int operandRecord;
  int sourceCapacity;
  int operandVReg;
  void *inst2;
  undefined4 operandVReg2;
  undefined4 operandVReg3;
  int writeMaskWord;
  undefined4 dotSelect1;
  undefined4 dotSelect2;
  int matchScratch [9];
  undefined4 lastOperandRecordTail;
  
  if ((((inst != (int *)0x0) && (*(int *)(inst[0x22] + 8) == 0x14)) &&
      ((uint)*(byte *)(inst + 3) + (uint)*(byte *)((int)inst + 0xd) +
       (uint)*(byte *)((int)inst + 0xe) + (uint)*(byte *)((int)inst + 0xf) == 1)) &&
     (((inst[0x3a] & 1U) == 0 && ((inst[0x3a] & 2U) == 0)))) {
    sourceCapacity = (**(code **)(*inst + 0x14))(inst);
    if ((inst[5] & 0x200U) != 0) {
      sourceCapacity = sourceCapacity + 1;
    }
    if (inst[0x21] <= sourceCapacity) {
      operandVReg = IRInst__getOperandSource(inst,3);
      addendOpcode = *(int *)(*(int *)(operandVReg + 0x88) + 8);
      if (((addendOpcode == 0x13) || (addendOpcode == 0x36)) &&
         (((uint)*(byte *)(operandVReg + 0xc) + (uint)*(byte *)(operandVReg + 0xd) +
           (uint)*(byte *)(operandVReg + 0xe) + (uint)*(byte *)(operandVReg + 0xf) == 1 &&
          (((*(int *)(operandVReg + 0x120) == 0 &&
            (matchScratch[0] = *(int *)(operandVReg + 0x124), matchScratch[0] == 0)) &&
           (canMerge = ((int (*)())Inst__matchOperandPairs)(inst,operandVReg,program,&dotSelect1,&dotSelect2,matchScratch), canMerge != 0))))
         )) {
        *(int *)(program + 0x1e0) = *(int *)(program + 0x1e0) + 1;
        inst2 = IRInst__create(0x1e,*(undefined4 *)(program + 8));
        operandRecord = IRInst__getOperandRecord(inst2,1);
        *(undefined4 *)(operandRecord + 0x10) = dotSelect1;
        operandRecord = IRInst__getOperandRecord(inst2,2);
        *(undefined4 *)(operandRecord + 0x10) = dotSelect2;
        if (matchScratch[0] == 0) {
          operandVReg2 = IRInst__getOperandSource(inst,1);
          operandVReg3 = IRInst__getOperandSource(operandVReg,2);
          ((int (*)())Inst__mergeSelectsFrom)(operandVReg2,operandVReg3);
          operandVReg2 = IRInst__getOperandSource(inst,2);
          operandVReg3 = IRInst__getOperandSource(operandVReg,1);
          ((int (*)())Inst__mergeSelectsFrom)(operandVReg2,operandVReg3);
        }
        else {
          operandVReg2 = IRInst__getOperandSource(inst,1);
          operandVReg3 = IRInst__getOperandSource(operandVReg,1);
          ((int (*)())Inst__mergeSelectsFrom)(operandVReg2,operandVReg3);
          operandVReg2 = IRInst__getOperandSource(inst,2);
          operandVReg3 = IRInst__getOperandSource(operandVReg,2);
          ((int (*)())Inst__mergeSelectsFrom)(operandVReg2,operandVReg3);
        }
        operandVReg2 = IRInst__getOperandSource(inst,1);
        IRInst__setOperandSource(inst2,1,operandVReg2,0,*(undefined4 *)(program + 8));
        operandVReg2 = IRInst__getOperandSource(inst,2);
        IRInst__setOperandSource(inst2,2,operandVReg2,0,*(undefined4 *)(program + 8));
        IROperand__setModifierBits((int)inst2 + 0xa4,1,inst[0x2e] & 1);
        IROperand__setModifierBits((int)inst2 + 0xbc,1,inst[0x34] & 1);
        IROperand__setModifierBits((int)inst2 + 0xa4,2,(uint)inst[0x2e] >> 1 & 1);
        IROperand__setModifierBits((int)inst2 + 0xbc,2,(uint)inst[0x34] >> 1 & 1);
        ((void (*)())IRInst__makeLiteralVec4Float)(inst2,program,3,0.0,0.0,0.0,0.0);
        *(int *)((int)inst2 + 0x98) = inst[0x26];
        *(undefined4 *)((int)inst2 + 0x94) = *(undefined4 *)((int)inst2 + 0x14c);
        matchScratch[1] = 0;
        matchScratch[2] = 0;
        matchScratch[3] = 0;
        IRInst__saveCounters(inst,matchScratch + 1,0xffffffff);
        IRInst__restoreCounters(inst2,matchScratch + 1);
        operandRecord = IRInst__getOperandRecord(inst,0);
        *(undefined4 *)((int)inst2 + 0x9c) = *(undefined4 *)(operandRecord + 0x10);
        if ((inst[5] & 0x200U) != 0) {
          lastOperandRecordTail = 0;
          matchScratch[4] = 0;
          matchScratch[5] = 0;
          IRInst__readLastOperand(inst,matchScratch + 4);
          IRInst__setLastOperandFromRecord(inst2,matchScratch + 4,0,*(undefined4 *)(program + 8));
        }
        saturate = inst[0x48];
        writeMaskWord = inst[3];
        *(int *)((int)inst2 + 0x124) = inst[0x49];
        *(int *)((int)inst2 + 0x120) = saturate;
        *(int *)((int)inst2 + 0xc) = writeMaskWord;
        prevNode = inst[1];
        DList__unlink(inst);
        _memcpy(inst,inst2,0x164);
        Block__insertInstAfter(*(undefined4 *)(prevNode + 0x158),prevNode,inst);
        IRInst__dropCounterAndDeleteIfUnused(operandVReg,*(undefined4 *)(program + 8));
        return 1;
      }
    }
  }
  return 0;
}

/* Inst__collapseMadWithDot2AddToDot3 @ 0x14cec8 (940 bytes) */
int Inst__collapseMadWithDot2AddToDot3(inst, program)
  int inst;
  int program;
{
  int uniformSourceConstant;
  undefined4 sourceDef2;
  undefined4 sourceDef;
  int operandRecord;
  int dot2AddInst;
  int prevNode;
  undefined4 saturate;
  undefined4 writeMaskWord;
  int inst2;
  undefined4 dotSelect1;
  undefined4 dotSelect2;
  int matchScratch [5];
  float uniformConstValue;
  
  if (((((inst != 0) && (*(int *)(*(int *)(inst + 0x88) + 8) == 0x14)) &&
       ((uint)*(byte *)(inst + 0xc) + (uint)*(byte *)(inst + 0xd) +
        (uint)*(byte *)(inst + 0xe) + (uint)*(byte *)(inst + 0xf) == 1)) &&
      ((((*(uint *)(inst + 0xe8) & 1) == 0 && ((*(uint *)(inst + 0xe8) & 2) == 0)) &&
       ((dot2AddInst = IRInst__getOperandSource(inst,3), *(int *)(*(int *)(dot2AddInst + 0x88) + 8) == 0x1e &&
        (((uint)*(byte *)(dot2AddInst + 0xc) + (uint)*(byte *)(dot2AddInst + 0xd) + (uint)*(byte *)(dot2AddInst + 0xe)
          + (uint)*(byte *)(dot2AddInst + 0xf) == 1 && (*(int *)(dot2AddInst + 0x120) == 0)))))))) &&
     (inst2 = *(int *)(dot2AddInst + 0x124), inst2 == 0)) {
    operandRecord = IRInst__getOperandRecord(dot2AddInst,0);
    uniformSourceConstant = IRInst__getUniformSourceConstant(dot2AddInst,3,*(undefined4 *)(operandRecord + 0x10),matchScratch + 4);
    if ((((uniformSourceConstant != 0) && (uniformConstValue == FLOAT_001aa0d4)) && (matchScratch[4] == 2)) &&
       (matchScratch[0] = inst2,
       inst2 = ((int (*)())Inst__matchOperandPairs)(inst,dot2AddInst,program,&dotSelect1,&dotSelect2,matchScratch), inst2 != 0)) {
      inst2 = IRInst__create(0x1c,*(undefined4 *)(program + 8));
      operandRecord = IRInst__getOperandRecord(inst2,1);
      *(undefined4 *)(operandRecord + 0x10) = dotSelect1;
      operandRecord = IRInst__getOperandRecord(inst2,2);
      *(undefined4 *)(operandRecord + 0x10) = dotSelect2;
      if (matchScratch[0] == 0) {
        sourceDef = IRInst__getOperandSource(inst,1);
        sourceDef2 = IRInst__getOperandSource(dot2AddInst,2);
        ((int (*)())Inst__mergeSelectsFrom)(sourceDef,sourceDef2);
        sourceDef = IRInst__getOperandSource(inst,2);
        sourceDef2 = IRInst__getOperandSource(dot2AddInst,1);
        ((int (*)())Inst__mergeSelectsFrom)(sourceDef,sourceDef2);
      }
      else {
        sourceDef = IRInst__getOperandSource(inst,1);
        sourceDef2 = IRInst__getOperandSource(dot2AddInst,1);
        ((int (*)())Inst__mergeSelectsFrom)(sourceDef,sourceDef2);
        sourceDef = IRInst__getOperandSource(inst,2);
        sourceDef2 = IRInst__getOperandSource(dot2AddInst,2);
        ((int (*)())Inst__mergeSelectsFrom)(sourceDef,sourceDef2);
      }
      sourceDef = IRInst__getOperandSource(inst,1);
      IRInst__setOperandSource(inst2,1,sourceDef,0,*(undefined4 *)(program + 8));
      sourceDef = IRInst__getOperandSource(inst,2);
      IRInst__setOperandSource(inst2,2,sourceDef,0,*(undefined4 *)(program + 8));
      IROperand__setModifierBits(inst2 + 0xa4,1,*(uint *)(inst + 0xb8) & 1);
      IROperand__setModifierBits(inst2 + 0xbc,1,*(uint *)(inst + 0xd0) & 1);
      IROperand__setModifierBits(inst2 + 0xa4,2,*(uint *)(inst + 0xb8) >> 1 & 1);
      IROperand__setModifierBits(inst2 + 0xbc,2,*(uint *)(inst + 0xd0) >> 1 & 1);
      *(undefined4 *)(inst2 + 0x98) = *(undefined4 *)(inst + 0x98);
      *(undefined4 *)(inst2 + 0x94) = *(undefined4 *)(inst2 + 0x14c);
      matchScratch[3] = 0;
      matchScratch[1] = 0;
      matchScratch[2] = 0;
      IRInst__saveCounters(inst,matchScratch + 1,0xffffffff);
      IRInst__restoreCounters(inst2,matchScratch + 1);
      *(undefined4 *)(inst2 + 0x158) = *(undefined4 *)(inst + 0x158);
      operandRecord = IRInst__getOperandRecord(inst,0);
      *(undefined4 *)(inst2 + 0x9c) = *(undefined4 *)(operandRecord + 0x10);
      if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
        sourceDef = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
        IRInst__setExtraOperandSource(inst2,sourceDef,0,*(undefined4 *)(program + 8));
      }
      saturate = *(undefined4 *)(inst + 0x120);
      writeMaskWord = *(undefined4 *)(inst + 0xc);
      *(undefined4 *)(inst2 + 0x124) = *(undefined4 *)(inst + 0x124);
      *(undefined4 *)(inst2 + 0x120) = saturate;
      *(undefined4 *)(inst2 + 0xc) = writeMaskWord;
      prevNode = *(int *)(inst + 4);
      DList__unlink(inst);
      _memcpy(inst,inst2,0x164);
      Block__insertInstAfter(*(undefined4 *)(prevNode + 0x158),prevNode,inst);
      IRInst__dropCounterAndDeleteIfUnused(dot2AddInst,*(undefined4 *)(program + 8));
      return 1;
    }
  }
  return 0;
}

/* Inst__collapseDot3VectorTimesScaledVector @ 0x14d274 (1312 bytes) */
int Inst__collapseDot3VectorTimesScaledVector(inst, program)
  int inst;
  int program;
{
  int splatComponentVV;
  int sameValue2;
  int splatComponentS;
  int identityResult;
  int sameValue;
  undefined4 splatSelectS;
  undefined4 splatSelectV;
  int isSourceSelectIdentity2;
  int isSourceSelectIdentity;
  undefined4 sourceDef2;
  int operandRecord3;
  int operandRecord2;
  int operandRecord;
  int sourceDef;
  uint origFlags;
  int opcodeInfo;
  int dotLeft;
  int operandVReg;
  undefined4 destRegister;
  int identityResult2;
  int useCount;
  int depthBase;
  undefined4 operandVReg2;
  undefined4 destRegisterOffset;
  undefined4 saturate;
  undefined4 resultScale;
  int extraSource;
  int prevNode;
  undefined4 destSelect;
  
  if (*(int *)(*(int *)(inst + 0x88) + 8) != 0x1c) {
    return 0;
  }
  if ((*(uint *)(inst + 0xb8) & 1) != 0) {
    return 0;
  }
  if ((*(uint *)(inst + 0xb8) & 2) != 0) {
    return 0;
  }
  if ((*(uint *)(inst + 0xd0) & 1) != 0) {
    return 0;
  }
  if ((*(uint *)(inst + 0xd0) & 2) != 0) {
    return 0;
  }
  isSourceSelectIdentity2 = IRInst__isSourceSelectIdentity(inst,1);
  if (isSourceSelectIdentity2 == 0) {
    return 0;
  }
  isSourceSelectIdentity2 = IRInst__isSourceSelectIdentity(inst,2);
  if (isSourceSelectIdentity2 == 0) {
    return 0;
  }
  dotLeft = IRInst__getOperandSource(inst,1);
  operandVReg = IRInst__getOperandSource(inst,2);
  opcodeInfo = *(int *)(operandVReg + 0x88);
  if ((((*(int *)(opcodeInfo + 8) == 0x13) && (*(int *)(operandVReg + 0x120) == 0)) &&
      (*(int *)(operandVReg + 0x124) == 0)) &&
     ((((*(uint *)(operandVReg + 0x14) & 0x200) == 0 && ((*(uint *)(operandVReg + 0xb8) & 1) == 0)) &&
      (((*(uint *)(operandVReg + 0xb8) & 2) == 0 &&
       (((*(uint *)(operandVReg + 0xd0) & 1) == 0 && ((*(uint *)(operandVReg + 0xd0) & 2) == 0)))))))) {
    isSourceSelectIdentity = IRInst__isSourceSelectIdentity(operandVReg,1);
    if (isSourceSelectIdentity != 0) {
      sourceDef2 = IRInst__getOperandSource(operandVReg,1);
      sameValue = ((int (*)())Inst__sourcesRelated)(dotLeft,sourceDef2);
      if (sameValue != 0) {
        sourceDef = IRInst__getOperandSource(operandVReg,2);
        goto checkSourceDef;
      }
    }
    opcodeInfo = *(int *)(operandVReg + 0x88);
  }
  if ((((((*(int *)(opcodeInfo + 8) == 0x13) && (*(int *)(operandVReg + 0x120) == 0)) &&
        (*(int *)(operandVReg + 0x124) == 0)) &&
       (((*(uint *)(operandVReg + 0x14) & 0x200) == 0 && ((*(uint *)(operandVReg + 0xb8) & 1) == 0)))) &&
      (((*(uint *)(operandVReg + 0xb8) & 2) == 0 &&
       (((*(uint *)(operandVReg + 0xd0) & 1) == 0 && ((*(uint *)(operandVReg + 0xd0) & 2) == 0)))))) &&
     (identityResult = IRInst__isSourceSelectIdentity(operandVReg,1), identityResult != 0)) {
    sourceDef2 = IRInst__getOperandSource(operandVReg,2);
    sameValue = ((int (*)())Inst__sourcesRelated)(dotLeft,sourceDef2);
    if (sameValue != 0) {
      sourceDef = IRInst__getOperandSource(operandVReg,1);
      goto checkSourceDef;
    }
  }
  opcodeInfo = *(int *)(dotLeft + 0x88);
  if (((((*(int *)(opcodeInfo + 8) == 0x13) && (*(int *)(dotLeft + 0x120) == 0)) &&
       (*(int *)(dotLeft + 0x124) == 0)) &&
      (((*(uint *)(dotLeft + 0x14) & 0x200) == 0 && ((*(uint *)(dotLeft + 0xb8) & 1) == 0)))) &&
     (((*(uint *)(dotLeft + 0xb8) & 2) == 0 &&
      (((*(uint *)(dotLeft + 0xd0) & 1) == 0 && ((*(uint *)(dotLeft + 0xd0) & 2) == 0)))))) {
    isSourceSelectIdentity = IRInst__isSourceSelectIdentity(dotLeft,1);
    if (isSourceSelectIdentity != 0) {
      sourceDef2 = IRInst__getOperandSource(dotLeft,1);
      sameValue = ((int (*)())Inst__sourcesRelated)(operandVReg,sourceDef2);
      if (sameValue != 0) {
        sourceDef = IRInst__getOperandSource(dotLeft,2);
        dotLeft = operandVReg;
        goto checkSourceDef;
      }
    }
    opcodeInfo = *(int *)(dotLeft + 0x88);
  }
  if (*(int *)(opcodeInfo + 8) != 0x13) {
    return 0;
  }
  if (*(int *)(dotLeft + 0x120) != 0) {
    return 0;
  }
  if (*(int *)(dotLeft + 0x124) != 0) {
    return 0;
  }
  if ((*(uint *)(dotLeft + 0x14) & 0x200) != 0) {
    return 0;
  }
  if ((*(uint *)(dotLeft + 0xb8) & 1) != 0) {
    return 0;
  }
  if ((*(uint *)(dotLeft + 0xb8) & 2) != 0) {
    return 0;
  }
  if ((*(uint *)(dotLeft + 0xd0) & 1) != 0) {
    return 0;
  }
  if ((*(uint *)(dotLeft + 0xd0) & 2) != 0) {
    return 0;
  }
  isSourceSelectIdentity = IRInst__isSourceSelectIdentity(dotLeft,1);
  if (isSourceSelectIdentity == 0) {
    return 0;
  }
  sourceDef2 = IRInst__getOperandSource(dotLeft,2);
  sameValue = ((int (*)())Inst__sourcesRelated)(operandVReg,sourceDef2);
  if (sameValue == 0) {
    return 0;
  }
  sourceDef = IRInst__getOperandSource(dotLeft,1);
  dotLeft = operandVReg;
checkSourceDef:
  if ((((*(int *)(sourceDef + 0x120) == 0) && (*(int *)(sourceDef + 0x124) == 0)) &&
      ((*(uint *)(sourceDef + 0xb8) & 1) == 0)) &&
     ((((((*(uint *)(sourceDef + 0xb8) & 2) == 0 && ((*(uint *)(sourceDef + 0x14) & 0x200) == 0)) &&
        ((operandVReg = IRInst__getOperandSource(sourceDef,1), *(int *)(*(int *)(operandVReg + 0x88) + 8) == 0x1c ||
         ((*(int *)(operandVReg + 0x120) == 0 && (*(int *)(operandVReg + 0x124) == 0)))))) &&
       ((*(uint *)(operandVReg + 0xb8) & 1) == 0)) &&
      ((((((*(uint *)(operandVReg + 0xb8) & 2) == 0 && ((*(uint *)(operandVReg + 0xd0) & 1) == 0)) &&
         ((*(uint *)(operandVReg + 0xd0) & 2) == 0)) &&
        ((identityResult2 = IRInst__isSourceSelectIdentity(operandVReg,1), identityResult2 != 0 && (identityResult2 = IRInst__isSourceSelectIdentity(operandVReg,2), identityResult2 != 0)))
        ) && ((*(uint *)(operandVReg + 0x14) & 0x200) == 0)))))) {
    sourceDef2 = IRInst__getOperandSource(operandVReg,1);
    sameValue2 = ((int (*)())Inst__sourcesRelated)(dotLeft,sourceDef2);
    if (sameValue2 != 0) {
      sourceDef2 = IRInst__getOperandSource(operandVReg,2);
      dotLeft = ((int (*)())Inst__sourcesRelated)(dotLeft,sourceDef2);
      if (dotLeft != 0) {
        operandRecord = IRInst__getOperandRecord(sourceDef,0);
        extraSource = 0;
        splatComponentS = SelectWord__splatComponent(*(undefined4 *)(operandRecord + 0x10));
        operandRecord2 = IRInst__getOperandRecord(operandVReg,0);
        splatComponentVV = SelectWord__splatComponent(*(undefined4 *)(operandRecord2 + 0x10));
        origFlags = *(uint *)(inst + 0x14);
        destRegister = *(undefined4 *)(inst + 0x94);
        destRegisterOffset = *(undefined4 *)(inst + 0x98);
        useCount = IRInst__useCount(inst,program);
        saturate = *(undefined4 *)(inst + 0x120);
        resultScale = *(undefined4 *)(inst + 0x124);
        operandRecord3 = IRInst__getOperandRecord(inst,0);
        destSelect = *(undefined4 *)(operandRecord3 + 0x10);
        if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
          extraSource = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
        }
        operandVReg2 = IRInst__getOperandSource(inst,1);
        IRInst__dropCounterAndDeleteIfUnused(operandVReg2,*(undefined4 *)(program + 8));
        operandVReg2 = IRInst__getOperandSource(inst,2);
        IRInst__dropCounterAndDeleteIfUnused(operandVReg2,*(undefined4 *)(program + 8));
        prevNode = *(int *)(inst + 4);
        DList__unlink(inst);
        IRInst__reinitAsBinary(inst,0x13,*(undefined4 *)(program + 8));
        *(undefined4 *)(inst + 0x9c) = destSelect;
        depthBase = *(int *)(program + 0x478);
        *(undefined4 *)(inst + 0x94) = destRegister;
        *(undefined4 *)(inst + 0x98) = destRegisterOffset;
        *(int *)(inst + 0x160) = useCount + depthBase;
        *(undefined4 *)(inst + 0x120) = saturate;
        *(undefined4 *)(inst + 0x124) = resultScale;
        if ((origFlags & 2) != 0) {
          *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) | 2;
        }
        if (extraSource != 0) {
          IRInst__setExtraOperandSource(inst,extraSource,0,*(undefined4 *)(program + 8));
          if (*(int *)(program + 0x478) < *(int *)(extraSource + 0x160)) {
            *(int *)(extraSource + 0x160) = *(int *)(extraSource + 0x160) + 1;
          }
          else {
            *(int *)(extraSource + 0x160) = *(int *)(program + 0x478) + 1;
          }
        }
        Block__insertInstAfter(*(undefined4 *)(prevNode + 0x158),prevNode,inst);
        IRInst__setOperandSource(inst,1,operandVReg,0,*(undefined4 *)(program + 8));
        splatSelectV = *(undefined4 *)(PTR_DAT_001e8b8c + splatComponentVV * 4);
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord2 + 0x10) = splatSelectV;
        if (*(int *)(program + 0x478) < *(int *)(operandVReg + 0x160)) {
          *(int *)(operandVReg + 0x160) = *(int *)(operandVReg + 0x160) + 1;
        }
        else {
          *(int *)(operandVReg + 0x160) = *(int *)(program + 0x478) + 1;
        }
        IRInst__setOperandSource(inst,2,sourceDef,0,*(undefined4 *)(program + 8));
        splatSelectS = *(undefined4 *)(PTR_DAT_001e8b8c + splatComponentS * 4);
        operandRecord = IRInst__getOperandRecord(inst,2);
        *(undefined4 *)(operandRecord + 0x10) = splatSelectS;
        if (*(int *)(program + 0x478) < *(int *)(sourceDef + 0x160)) {
          *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
        }
        else {
          *(int *)(sourceDef + 0x160) = *(int *)(program + 0x478) + 1;
        }
        IRInst__clearSourceSelectsOfUnwrittenComponents(inst);
        return 1;
      }
    }
  }
  return 0;
}

/* Inst__collapseThreeComponentSumToDot3 @ 0x14d8f8 (2240 bytes) */
int Inst__collapseThreeComponentSumToDot3(node, pass)
  int node;
  int pass;
{
  undefined4 destRegisterOffset;
  undefined4 destRegister;
  int depthBase;
  int isPresub;
  undefined4 finalSelect;
  int src1Temp;
  int hasSingleUse;
  undefined4 sourceDef2;
  undefined4 sourceDef6;
  undefined4 sourceDef3;
  int *sourceDef7;
  int sourceDef;
  int sourceDef5;
  int operandRecord2;
  int sourceDef4;
  int operandRecord;
  byte innerMask0;
  byte innerMask1;
  byte innerMask2;
  undefined1 innerSel1;
  undefined1 innerSel2;
  undefined1 outerSel;
  uint nodeFlags;
  int sameValue;
  undefined4 outerIndex;
  undefined4 nodeDestSelect;
  int splatComponent;
  int *hwLimits;
  int selectAccepted;
  int useCount;
  uint negateFlag;
  undefined4 saturate;
  int extraSource;
  undefined4 innerDestSelect;
  undefined4 resultScale;
  undefined4 innerSrcDestSelect;
  undefined4 outerSelectWord;
  undefined4 innerSrc2SelectWord;
  undefined4 innerSrc1SelectWord;
  undefined4 packedSelect;
  undefined4 mergedDest1;
  undefined4 mergedDest2;
  undefined4 mergedWriteMask;
  undefined4 mergedUnusedSelect [4];
  
  if (*(int *)(*(int *)(node + 0x88) + 8) != 0x12) {
    return 0;
  }
  extraSource = 0;
  if ((*(uint *)(node + 0x14) & 0x200) != 0) {
    extraSource = IRInst__getOperandSource(node,*(undefined4 *)(node + 0x84));
  }
  sourceDef = IRInst__getOperandSource(node,1);
  if (*(int *)(*(int *)(sourceDef + 0x88) + 8) == 0x12) {
    sourceDef2 = IRInst__getOperandSource(node,1);
    hasSingleUse = IRInst__hasSingleUse(sourceDef2,pass);
    if ((hasSingleUse != 0) &&
       ((uint)*(byte *)(node + 0xc) + (uint)*(byte *)(node + 0xd) +
        (uint)*(byte *)(node + 0xe) + (uint)*(byte *)(node + 0xf) == 1)) {
      sourceDef = IRInst__getOperandSource(node,1);
      innerMask0 = *(byte *)(sourceDef + 0xc);
      sourceDef = IRInst__getOperandSource(node,1);
      innerMask1 = *(byte *)(sourceDef + 0xd);
      sourceDef = IRInst__getOperandSource(node,1);
      innerMask2 = *(byte *)(sourceDef + 0xe);
      sourceDef = IRInst__getOperandSource(node,1);
      if ((uint)innerMask0 + (uint)innerMask1 + (uint)innerMask2 + (uint)*(byte *)(sourceDef + 0xf) == 1) {
        sourceDef2 = IRInst__getOperandSource(node,1);
        sourceDef2 = IRInst__getOperandSource(sourceDef2,1);
        sourceDef3 = IRInst__getOperandSource(node,2);
        sameValue = ((int (*)())Inst__sourcesRelated)(sourceDef2,sourceDef3);
        if (sameValue != 0) {
          sourceDef2 = IRInst__getOperandSource(node,1);
          sourceDef2 = IRInst__getOperandSource(sourceDef2,2);
          sourceDef3 = IRInst__getOperandSource(node,2);
          sameValue = ((int (*)())Inst__sourcesRelated)(sourceDef2,sourceDef3);
          if (((((sameValue != 0) &&
                (src1Temp = IRInst__getOperandSource(node,1), (*(uint *)(src1Temp + 0xb8) & 2) == 0)) &&
               (src1Temp = IRInst__getOperandSource(node,1), (*(uint *)(src1Temp + 0xd0) & 2) == 0)) &&
              ((src1Temp = IRInst__getOperandSource(node,1), *(int *)(src1Temp + 0x120) == 0 &&
               (src1Temp = IRInst__getOperandSource(node,1), *(int *)(src1Temp + 0x124) == 0)))) &&
             (((*(uint *)(node + 0xd0) & 2) == 0 &&
              (src1Temp = IRInst__getOperandSource(node,1),
              (*(uint *)(src1Temp + 0xb8) & 1) == (*(uint *)(node + 0xd0) & 1))))) {
            sourceDef = IRInst__getOperandSource(node,1);
            negateFlag = *(uint *)(sourceDef + 0xd0) & 1;
            if (negateFlag == (*(uint *)(node + 0xd0) & 1)) {
              sourceDef = IRInst__getOperandSource(node,1);
              outerIndex = 2;
              goto setOperandRecord;
            }
          }
        }
      }
    }
  }
  sourceDef = IRInst__getOperandSource(node,2);
  if (*(int *)(*(int *)(sourceDef + 0x88) + 8) != 0x12) {
    return 0;
  }
  sourceDef2 = IRInst__getOperandSource(node,2);
  hasSingleUse = IRInst__hasSingleUse(sourceDef2,pass);
  if (hasSingleUse == 0) {
    return 0;
  }
  if ((uint)*(byte *)(node + 0xc) + (uint)*(byte *)(node + 0xd) +
      (uint)*(byte *)(node + 0xe) + (uint)*(byte *)(node + 0xf) != 1) {
    return 0;
  }
  sourceDef = IRInst__getOperandSource(node,2);
  innerMask0 = *(byte *)(sourceDef + 0xc);
  sourceDef = IRInst__getOperandSource(node,2);
  innerMask1 = *(byte *)(sourceDef + 0xd);
  sourceDef = IRInst__getOperandSource(node,2);
  innerMask2 = *(byte *)(sourceDef + 0xe);
  sourceDef = IRInst__getOperandSource(node,2);
  if ((uint)innerMask0 + (uint)innerMask1 + (uint)innerMask2 + (uint)*(byte *)(sourceDef + 0xf) != 1) {
    return 0;
  }
  sourceDef2 = IRInst__getOperandSource(node,2);
  sourceDef2 = IRInst__getOperandSource(sourceDef2,1);
  sourceDef3 = IRInst__getOperandSource(node,1);
  sameValue = ((int (*)())Inst__sourcesRelated)(sourceDef2,sourceDef3);
  if (sameValue == 0) {
    return 0;
  }
  sourceDef2 = IRInst__getOperandSource(node,2);
  sourceDef2 = IRInst__getOperandSource(sourceDef2,2);
  sourceDef3 = IRInst__getOperandSource(node,1);
  sameValue = ((int (*)())Inst__sourcesRelated)(sourceDef2,sourceDef3);
  if (sameValue == 0) {
    return 0;
  }
  sourceDef = IRInst__getOperandSource(node,2);
  if ((*(uint *)(sourceDef + 0xb8) & 2) != 0) {
    return 0;
  }
  sourceDef = IRInst__getOperandSource(node,2);
  if ((*(uint *)(sourceDef + 0xd0) & 2) != 0) {
    return 0;
  }
  sourceDef = IRInst__getOperandSource(node,2);
  if (*(int *)(sourceDef + 0x120) != 0) {
    return 0;
  }
  sourceDef = IRInst__getOperandSource(node,2);
  if (*(int *)(sourceDef + 0x124) != 0) {
    return 0;
  }
  if ((*(uint *)(node + 0xb8) & 2) != 0) {
    return 0;
  }
  sourceDef = IRInst__getOperandSource(node,2);
  if ((*(uint *)(sourceDef + 0xb8) & 1) != (*(uint *)(node + 0xb8) & 1)) {
    return 0;
  }
  sourceDef = IRInst__getOperandSource(node,2);
  negateFlag = *(uint *)(sourceDef + 0xd0) & 1;
  if (negateFlag != (*(uint *)(node + 0xb8) & 1)) {
    return 0;
  }
  sourceDef = IRInst__getOperandSource(node,2);
  outerIndex = 1;
setOperandRecord:
  operandRecord = IRInst__getOperandRecord(sourceDef,0);
  innerDestSelect = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(node,0);
  nodeDestSelect = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(sourceDef,1);
  innerSrc1SelectWord = *(undefined4 *)(operandRecord + 0x10);
  splatComponent = SelectWord__splatComponent(innerDestSelect);
  innerSel1 = *(undefined1 *)((int)&innerSrc1SelectWord + splatComponent);
  operandRecord = IRInst__getOperandRecord(sourceDef,2);
  innerSrc2SelectWord = *(undefined4 *)(operandRecord + 0x10);
  splatComponent = SelectWord__splatComponent(innerDestSelect);
  innerSel2 = *(undefined1 *)((int)&innerSrc2SelectWord + splatComponent);
  operandRecord = IRInst__getOperandRecord(node,outerIndex);
  outerSelectWord = *(undefined4 *)(operandRecord + 0x10);
  splatComponent = SelectWord__splatComponent(nodeDestSelect);
  outerSel = *(undefined1 *)((int)&outerSelectWord + splatComponent);
  packedSelect = CONCAT13(innerSel1,CONCAT12(innerSel2,4));
  (*(unsigned short *)((unsigned char *)&(packedSelect) + 2)) = CONCAT11(outerSel,4);
  sourceDef7 = (int *)IRInst__getOperandSource(sourceDef,1);
  isPresub = (**(code **)(*sourceDef7 + 0x5c))(sourceDef7);
  hwLimits = *(int **)(*(int *)(pass + 8) + 0x30c);
  selectAccepted = (**(code **)(*hwLimits + 0x108))(hwLimits,&packedSelect);
  if (selectAccepted == 0) {
    (*(unsigned short *)((unsigned char *)&(packedSelect) + 2)) = CONCAT11(innerSel2,(undefined1)packedSelect);
    packedSelect = CONCAT22(CONCAT11(innerSel1,outerSel),(*(unsigned short *)((unsigned char *)&(packedSelect) + 2)));
  }
  hwLimits = *(int **)(*(int *)(pass + 8) + 0x30c);
  selectAccepted = (**(code **)(*hwLimits + 0x108))(hwLimits,&packedSelect);
  if (selectAccepted == 0) {
    (*(unsigned short *)((unsigned char *)&(packedSelect) + 2)) = CONCAT11(innerSel1,(undefined1)packedSelect);
    packedSelect = CONCAT22(CONCAT11(outerSel,innerSel2),(*(unsigned short *)((unsigned char *)&(packedSelect) + 2)));
  }
  hwLimits = *(int **)(*(int *)(pass + 8) + 0x30c);
  selectAccepted = (**(code **)(*hwLimits + 0x108))(hwLimits,&packedSelect);
  if (selectAccepted == 0) {
    (*(unsigned short *)((unsigned char *)&(packedSelect) + 2)) = CONCAT11(innerSel2,(undefined1)packedSelect);
    packedSelect = CONCAT22(CONCAT11(outerSel,innerSel1),(*(unsigned short *)((unsigned char *)&(packedSelect) + 2)));
  }
  hwLimits = *(int **)(*(int *)(pass + 8) + 0x30c);
  selectAccepted = (**(code **)(*hwLimits + 0x108))(hwLimits,&packedSelect);
  if (selectAccepted == 0) {
    (*(unsigned short *)((unsigned char *)&(packedSelect) + 2)) = CONCAT11(innerSel1,(undefined1)packedSelect);
    packedSelect = CONCAT22(CONCAT11(innerSel2,outerSel),(*(unsigned short *)((unsigned char *)&(packedSelect) + 2)));
  }
  hwLimits = *(int **)(*(int *)(pass + 8) + 0x30c);
  selectAccepted = (**(code **)(*hwLimits + 0x108))(hwLimits,&packedSelect);
  if (selectAccepted == 0) {
    (*(unsigned short *)((unsigned char *)&(packedSelect) + 2)) = CONCAT11(outerSel,(undefined1)packedSelect);
    packedSelect = CONCAT22(CONCAT11(innerSel2,innerSel1),(*(unsigned short *)((unsigned char *)&(packedSelect) + 2)));
  }
  if ((isPresub != 0) &&
     (hwLimits = *(int **)(*(int *)(pass + 8) + 0x30c),
     selectAccepted = (**(code **)(*hwLimits + 0x108))(hwLimits,&packedSelect), selectAccepted == 0)) {
    return 0;
  }
  hwLimits = *(int **)(*(int *)(pass + 8) + 0x30c);
  selectAccepted = (**(code **)(*hwLimits + 0x108))(hwLimits,&packedSelect);
  if (selectAccepted == 0) {
    hwLimits = *(int **)(*(int *)(pass + 8) + 0x30c);
    selectAccepted = (**(code **)(*hwLimits + 0x100))(hwLimits,&packedSelect);
    if (selectAccepted == 0) {
      (*(unsigned short *)((unsigned char *)&(packedSelect) + 2)) = CONCAT11(innerSel2,(undefined1)packedSelect);
      packedSelect = CONCAT22(CONCAT11(innerSel1,outerSel),(*(unsigned short *)((unsigned char *)&(packedSelect) + 2)));
    }
    hwLimits = *(int **)(*(int *)(pass + 8) + 0x30c);
    selectAccepted = (**(code **)(*hwLimits + 0x100))(hwLimits,&packedSelect);
    if (selectAccepted == 0) {
      (*(unsigned short *)((unsigned char *)&(packedSelect) + 2)) = CONCAT11(innerSel1,(undefined1)packedSelect);
      packedSelect = CONCAT22(CONCAT11(outerSel,innerSel2),(*(unsigned short *)((unsigned char *)&(packedSelect) + 2)));
    }
    hwLimits = *(int **)(*(int *)(pass + 8) + 0x30c);
    selectAccepted = (**(code **)(*hwLimits + 0x100))(hwLimits,&packedSelect);
    if (selectAccepted == 0) {
      (*(unsigned short *)((unsigned char *)&(packedSelect) + 2)) = CONCAT11(innerSel2,(undefined1)packedSelect);
      packedSelect = CONCAT22(CONCAT11(outerSel,innerSel1),(*(unsigned short *)((unsigned char *)&(packedSelect) + 2)));
    }
    hwLimits = *(int **)(*(int *)(pass + 8) + 0x30c);
    selectAccepted = (**(code **)(*hwLimits + 0x100))(hwLimits,&packedSelect);
    if (selectAccepted == 0) {
      (*(unsigned short *)((unsigned char *)&(packedSelect) + 2)) = CONCAT11(innerSel1,(undefined1)packedSelect);
      packedSelect = CONCAT22(CONCAT11(innerSel2,outerSel),(*(unsigned short *)((unsigned char *)&(packedSelect) + 2)));
    }
    hwLimits = *(int **)(*(int *)(pass + 8) + 0x30c);
    selectAccepted = (**(code **)(*hwLimits + 0x100))(hwLimits,&packedSelect);
    if (selectAccepted == 0) {
      (*(unsigned short *)((unsigned char *)&(packedSelect) + 2)) = CONCAT11(outerSel,(undefined1)packedSelect);
      packedSelect = CONCAT22(CONCAT11(innerSel2,innerSel1),(*(unsigned short *)((unsigned char *)&(packedSelect) + 2)));
    }
    hwLimits = *(int **)(*(int *)(pass + 8) + 0x30c);
    selectAccepted = (**(code **)(*hwLimits + 0x100))(hwLimits,&packedSelect);
    if (selectAccepted == 0) {
      return 0;
    }
  }
  sourceDef4 = IRInst__getOperandSource(sourceDef,1);
  if (isPresub != 0) {
    operandRecord = IRInst__getOperandRecord(sourceDef4,0);
    innerSrcDestSelect = *(undefined4 *)(operandRecord + 0x10);
    sourceDef6 = IRInst__getOperandSource(sourceDef,2);
    operandRecord = IRInst__getOperandRecord(sourceDef6,0);
    SelectWord__mergeWrittenLanes(&mergedDest1,innerSrcDestSelect,*(undefined4 *)(operandRecord + 0x10));
    sourceDef6 = IRInst__getOperandSource(node,outerIndex);
    operandRecord = IRInst__getOperandRecord(sourceDef6,0);
    SelectWord__mergeWrittenLanes(&mergedDest2,mergedDest1,*(undefined4 *)(operandRecord + 0x10));
    *(undefined4 *)(sourceDef4 + 0x9c) = mergedDest2;
    WriteMask__fromSelectWord(&mergedWriteMask,mergedDest2);
    SelectWord__maskUnused(mergedUnusedSelect,0x10203,mergedWriteMask);
    operandRecord = IRInst__getOperandRecord(sourceDef4,1);
    *(undefined4 *)(operandRecord + 0x10) = mergedUnusedSelect[0];
    operandRecord = IRInst__getOperandRecord(sourceDef4,2);
    *(undefined4 *)(operandRecord + 0x10) = mergedUnusedSelect[0];
  }
  nodeFlags = *(uint *)(node + 0x14);
  destRegister = *(undefined4 *)(node + 0x94);
  destRegisterOffset = *(undefined4 *)(node + 0x98);
  useCount = IRInst__useCount(node,pass);
  saturate = *(undefined4 *)(node + 0x120);
  resultScale = *(undefined4 *)(node + 0x124);
  sourceDef2 = IRInst__getOperandSource(node,outerIndex);
  IRInst__dropCounterAndDeleteIfUnused(sourceDef2,*(undefined4 *)(pass + 8));
  DList__unlink(node);
  IRInst__reinitAsBinary(node,0x1c,*(undefined4 *)(pass + 8));
  *(undefined4 *)(node + 0x9c) = nodeDestSelect;
  depthBase = *(int *)(pass + 0x478);
  *(undefined4 *)(node + 0x94) = destRegister;
  *(undefined4 *)(node + 0x98) = destRegisterOffset;
  *(int *)(node + 0x160) = useCount + depthBase;
  *(undefined4 *)(node + 0x120) = saturate;
  *(undefined4 *)(node + 0x124) = resultScale;
  if ((nodeFlags & 2) != 0) {
    *(uint *)(node + 0x14) = *(uint *)(node + 0x14) | 2;
  }
  if (extraSource != 0) {
    IRInst__setExtraOperandSource(node,extraSource,0,*(undefined4 *)(pass + 8));
    if (*(int *)(pass + 0x478) < *(int *)(extraSource + 0x160)) {
      *(int *)(extraSource + 0x160) = *(int *)(extraSource + 0x160) + 1;
    }
    else {
      *(int *)(extraSource + 0x160) = *(int *)(pass + 0x478) + 1;
    }
  }
  Block__insertInstAfter(*(undefined4 *)(sourceDef + 0x158),sourceDef,node);
  IRInst__setOperandSource(node,1,sourceDef4,0,*(undefined4 *)(pass + 8));
  IROperand__setModifierBits(node + 0xa4,1,negateFlag);
  finalSelect = packedSelect;
  operandRecord2 = IRInst__getOperandRecord(node,1);
  *(undefined4 *)(operandRecord2 + 0x10) = finalSelect;
  sourceDef5 = IRInst__getOperandSource(sourceDef,1);
  if (*(int *)(pass + 0x478) < *(int *)(sourceDef5 + 0x160)) {
    *(int *)(sourceDef5 + 0x160) = *(int *)(sourceDef5 + 0x160) + 1;
  }
  else {
    *(int *)(sourceDef5 + 0x160) = *(int *)(pass + 0x478) + 1;
  }
  ((void (*)())IRInst__makeLiteralVec4Float)(node,pass,2,1.0,1.0,1.0,1.0);
  IRInst__dropCounterAndDeleteIfUnused(sourceDef,*(undefined4 *)(pass + 8));
  return 1;
}

/* Inst__replaceDuplicateInst @ 0x14e2dc (1032 bytes) */
int Inst__replaceDuplicateInst(inst, inst2, pass)
  int *inst;
  int *inst2;
  int pass;
{
  int inst1;
  int operandIndex;
  int sourceDef;
  int sourceDef3;
  int sourceDef2;
  int operandRecord;
  int *operandVReg;
  int userByteOffset;
  int operandIndex2;
  uint vectorFilledCount;
  int *userSlot;
  uint loopIndex2;
  uint vectorFilledCount2;
  uint userIndexDown;
  int loopIndex;
  int operandSelect;
  uint *vector;
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  operandSelect = *(int *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst2,0);
  if ((((operandSelect == *(int *)(operandRecord + 0x10)) && (inst[0x48] == inst2[0x48])) &&
      (inst[0x49] == inst2[0x49])) && (inst[0x21] == inst2[0x21])) {
    operandIndex = (**(code **)(*inst + 0x14))(inst);
    operandIndex = operandIndex + 1;
    if (operandIndex <= inst[0x21]) {
      do {
        sourceDef = IRInst__getOperandSource(inst,operandIndex);
        sourceDef3 = IRInst__getOperandSource(inst2,operandIndex);
        if (sourceDef != sourceDef3) {
          return;
        }
        operandIndex = operandIndex + 1;
      } while (operandIndex <= inst[0x21]);
    }
    sourceDef2 = IRInst__getOperandSource(inst,1);
    sourceDef = IRInst__getOperandSource(inst2,1);
    if (sourceDef2 == sourceDef) {
      sourceDef2 = IRInst__getOperandSource(inst,2);
      sourceDef = IRInst__getOperandSource(inst2,2);
      if (sourceDef2 == sourceDef) {
        operandRecord = IRInst__getOperandRecord(inst,1);
        operandSelect = *(int *)(operandRecord + 0x10);
        operandRecord = IRInst__getOperandRecord(inst2,1);
        if (operandSelect == *(int *)(operandRecord + 0x10)) {
          operandRecord = IRInst__getOperandRecord(inst,2);
          operandSelect = *(int *)(operandRecord + 0x10);
          operandRecord = IRInst__getOperandRecord(inst2,2);
          if (operandSelect == *(int *)(operandRecord + 0x10)) {
            if ((inst[0x2e] & 1U) == (inst2[0x2e] & 1U)) {
              if ((((inst[0x34] & 1U) == (inst2[0x34] & 1U)) &&
                  (((uint)inst[0x2e] >> 1 & 1) == ((uint)inst2[0x2e] >> 1 & 1))) &&
                 (((uint)inst[0x34] >> 1 & 1) == ((uint)inst2[0x34] >> 1 & 1)))
              goto setVector;
            }
          }
        }
      }
    }
    sourceDef2 = IRInst__getOperandSource(inst,1);
    sourceDef = IRInst__getOperandSource(inst2,2);
    if (sourceDef2 == sourceDef) {
      sourceDef2 = IRInst__getOperandSource(inst,2);
      sourceDef = IRInst__getOperandSource(inst2,1);
      if (sourceDef2 == sourceDef) {
        operandRecord = IRInst__getOperandRecord(inst,1);
        operandSelect = *(int *)(operandRecord + 0x10);
        operandRecord = IRInst__getOperandRecord(inst2,2);
        if (operandSelect == *(int *)(operandRecord + 0x10)) {
          operandRecord = IRInst__getOperandRecord(inst,2);
          operandSelect = *(int *)(operandRecord + 0x10);
          operandRecord = IRInst__getOperandRecord(inst2,1);
          if (operandSelect == *(int *)(operandRecord + 0x10)) {
            if ((inst[0x2e] & 1U) == (inst2[0x34] & 1U)) {
              if ((((inst[0x34] & 1U) == (inst2[0x2e] & 1U)) &&
                  (((uint)inst[0x2e] >> 1 & 1) == ((uint)inst2[0x34] >> 1 & 1))) &&
                 (((uint)inst[0x34] >> 1 & 1) == ((uint)inst2[0x2e] >> 1 & 1))) {
setVector:
                vector = (uint *)inst2[4];
                vectorFilledCount2 = vector[1];
                userIndexDown = vectorFilledCount2 - 1;
                if ((int)userIndexDown < 0) {
LAB_0014e690:
                  (**(code **)(*inst2 + 0xc))(inst2,1,*(undefined4 *)(pass + 8));
                  ((int (*)())Inst__hoistToOperandBlock)(pass,inst,pass);
                  return;
                }
                userByteOffset = userIndexDown * 4;
                loopIndex2 = 0;
                do {
                  if (userIndexDown < *vector) {
                    vectorFilledCount = vector[1];
                    if (vectorFilledCount <= userIndexDown) {
                      _memset(vectorFilledCount * 4 + vector[2],0,(userIndexDown - vectorFilledCount) * 4 + 4);
                      vector[1] = userIndexDown + 1;
                    }
                    userSlot = (int *)(userByteOffset + vector[2]);
                  }
                  else {
                    userSlot = (int *)Vector__elementRefGrow(vector,userIndexDown);
                  }
                  inst1 = *userSlot;
                  operandIndex2 = *(int *)(inst1 + 0x84);
                  if ((*(uint *)(inst1 + 0x14) & 0x200) == 0) {
loopCheckOperandIndex2:
                    if (0 < operandIndex2) {
                      loopIndex = 1;
                      do {
                        operandVReg = (int *)IRInst__getOperandSource(inst1,loopIndex);
                        if (inst2 == operandVReg) {
                          IRInst__setOperandSource(inst1,loopIndex,inst,1,*(undefined4 *)(pass + 8));
                          break;
                        }
                        loopIndex = loopIndex + 1;
                      } while (loopIndex <= operandIndex2);
                    }
                  }
                  else {
                    operandVReg = (int *)IRInst__getOperandSource(inst1,operandIndex2);
                    operandIndex2 = operandIndex2 + -1;
                    if (inst2 != operandVReg) goto loopCheckOperandIndex2;
                    IRInst__setExtraOperandSource(inst1,inst,1,*(undefined4 *)(pass + 8));
                  }
                  loopIndex2 = loopIndex2 + 1;
                  userIndexDown = userIndexDown - 1;
                  userByteOffset = userByteOffset + -4;
                  if (vectorFilledCount2 == loopIndex2) goto LAB_0014e690;
                  vector = (uint *)inst2[4];
                } while( true );
              }
            }
          }
        }
      }
    }
  }
  return;
}

/* Inst__reassociate_14e6e4 @ 0x14e6e4 (672 bytes) */
int Inst__reassociate_14e6e4(inst, program)
  int inst;
  int program;
{
  uint vectorFilledCount2;
  uint vectorFilledCount;
  int sourceDef;
  int sourceDef2;
  int instOpcode;
  int candidateInst;
  int useCheck;
  uint workTopIndex;
  uint countBefore;
  int *userSlot;
  int *workTopSlot;
  int *workPushSlot;
  int slotByteOffset;
  int operandVReg;
  undefined4 operandVReg2;
  undefined4 operandVReg3;
  undefined4 staleArg5;
  undefined4 staleArg6;
  undefined4 staleArg7;
  undefined4 staleArg8;
  undefined4 staleArg9;
  int instOpcodeB;
  uint loopIndex;
  int userByteOffset;
  int inst1;
  uint *vector1;
  uint userIndexDown;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_48_buf [0x10];
  #define vecCapacity (*(uint *)(local_48_buf + 0x00))
  #define vecCount (*(uint *)(local_48_buf + 0x04))
  #define vecData (*(int *)(local_48_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_48_buf + 0x0c))
  
  instOpcode = *(int *)(*(int *)(inst + 0x88) + 8);
  if ((instOpcode == 0x12) || (instOpcode == 0x13)) {
    operandVReg2 = IRInst__getOperandSource(inst,1);
    operandVReg3 = IRInst__getOperandSource(inst,2);
    useCheck = IRInst__hasSingleUse(operandVReg2,program);
    if ((useCheck == 0) &&
       (((useCheck = IRInst__hasNoUses(operandVReg2,program,staleArg5,staleArg6,staleArg7,staleArg8,staleArg9), useCheck == 0 &&
         (useCheck = IRInst__hasSingleUse(operandVReg3,program), useCheck == 0)) &&
        (vecCount = IRInst__hasNoUses(operandVReg3,program,staleArg5,staleArg6,staleArg7,staleArg8,staleArg9), vecCount == 0)))) {
      vecArena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
      vecCapacity = 2;
      vecData = Arena__alloc(vecArena,8);
      instOpcodeB = *(int *)(*(int *)(inst + 0x88) + 8);
      sourceDef2 = IRInst__getOperandSource(inst,1);
      vector1 = *(uint **)(sourceDef2 + 0x10);
      vectorFilledCount = vector1[1];
      userIndexDown = vectorFilledCount - 1;
      if (-1 < (int)userIndexDown) {
        userByteOffset = userIndexDown * 4;
        loopIndex = 0;
        do {
          if (userIndexDown < *vector1) {
            vectorFilledCount2 = vector1[1];
            if (vectorFilledCount2 <= userIndexDown) {
              _memset(vectorFilledCount2 * 4 + vector1[2],0,(userIndexDown - vectorFilledCount2) * 4 + 4);
              vector1[1] = userIndexDown + 1;
            }
            userSlot = (int *)(userByteOffset + vector1[2]);
          }
          else {
            userSlot = (int *)Vector__elementRefGrow(vector1,userIndexDown);
          }
          inst1 = *userSlot;
          if ((instOpcodeB == *(int *)(*(int *)(inst1 + 0x88) + 8)) && (inst != inst1)) {
            sourceDef = IRInst__getOperandSource(inst1,1);
            operandVReg = IRInst__getOperandSource(inst,1);
            if (sourceDef == operandVReg) {
              sourceDef = IRInst__getOperandSource(inst1,2);
              operandVReg = IRInst__getOperandSource(inst,2);
              if (sourceDef != operandVReg) goto setSourceDef;
loopSetCountBefore:
              countBefore = vecCount;
              if (vecCount < vecCapacity) {
                slotByteOffset = vecCount * 4;
                _memset(slotByteOffset + vecData,0,4);
                vecCount = countBefore + 1;
                workPushSlot = (int *)(slotByteOffset + vecData);
              }
              else {
                workPushSlot = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
              }
              *workPushSlot = inst1;
            }
            else {
setSourceDef:
              sourceDef = IRInst__getOperandSource(inst1,2);
              operandVReg = IRInst__getOperandSource(inst,1);
              if (sourceDef == operandVReg) {
                sourceDef = IRInst__getOperandSource(inst1,1);
                operandVReg = IRInst__getOperandSource(inst,2);
                if (sourceDef == operandVReg) goto loopSetCountBefore;
              }
            }
          }
          loopIndex = loopIndex + 1;
          userIndexDown = userIndexDown - 1;
          userByteOffset = userByteOffset + -4;
          if (loopIndex == vectorFilledCount) break;
          vector1 = *(uint **)(sourceDef2 + 0x10);
        } while( true );
      }
      while (vecCount != 0) {
        workTopIndex = vecCount - 1;
        workTopSlot = (int *)0x0;
        if (workTopIndex < vecCount) {
          workTopSlot = (int *)(workTopIndex * 4 + vecData);
        }
        candidateInst = *workTopSlot;
        Vector__removeAt(&vecCapacity,workTopIndex);
        if ((*(uint *)(candidateInst + 0x14) & 1) != 0) {
          ((int (*)())Inst__replaceDuplicateInst)(inst,candidateInst,program);
        }
      }
      Arena__free(vecArena,vecData);
    }
  }
  return;
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* Inst__swapSharedTermBetweenUses @ 0x14e9e4 (2620 bytes) */
int Inst__swapSharedTermBetweenUses(useA, useB, pass, allowRewrite, allowOperandSwap)
  int *useA;
  int *useB;
  int pass;
  int allowRewrite;
  int allowOperandSwap;
{
  int operandRecord2;
  int lane3Flag;
  uint lane0Flag;
  int termIndexB;
  int termIndexA;
  int operandSlotAddrB;
  int precheckResult;
  int consumerInstA;
  int termByteOffsetA;
  int sourceDefOfB;
  uint termA;
  uint useOperandIndexBCopy;
  uint savedSelectWordB;
  uint useOperandIndexB;
  uint useOperandIndexBTmp;
  uint absOtherB;
  uint operandIndex4;
  int inst4;
  int operandIndex3;
  int operandIndex2;
  int inst3;
  int operandIndex;
  int inst2;
  int inst;
  undefined4 sourceDef2;
  int sourceDef;
  int operandRecord;
  int sourceDef3;
  bool consumerIsMul;
  int lane2Flag;
  undefined4 operandVReg2;
  undefined4 staleArg4Value;
  int selectsCompatibleA;
  int *operandVReg;
  uint firstSourceSelect;
  uint secondSourceSelect;
  uint termB;
  undefined4 compilerCtx;
  int nextTermSlotA;
  int nextTermSlotACopy;
  uint *matchFramePtr;
  int lane1Flag;
  int termByteOffsetB;
  int hasNoUsesResult;
  int nextTermIndexA;
  uint matchFrame [21];
  undefined4 maskedSelectOutA;
  undefined4 writeMaskOut;
  undefined4 maskedSelectOutB;
  undefined4 composedSelectOutA;
  undefined4 composedSelectOutB [3];
  
  consumerInstA = *useA;
  consumerIsMul = *(int *)(*(int *)(consumerInstA + 0x88) + 8) == 0x13;
  if (consumerIsMul) {
    precheckResult = ((int (*)())Use__negationParityEqual)(useA,useB);
    if (precheckResult == 0) {
      return 0;
    }
    consumerInstA = *useA;
  }
  sourceDefOfB = IRInst__getOperandSource(*useB,useB[1]);
  if ((consumerInstA != sourceDefOfB) &&
     (sourceDefOfB = *useB, consumerInstA = IRInst__getOperandSource(*useA,useA[1]), sourceDefOfB != consumerInstA)) {
    operandVReg2 = IRInst__getOperandSource(*useA,useA[1]);
    matchFrame[6] = IRInst__getOperandSource(operandVReg2,1);
    operandVReg2 = IRInst__getOperandSource(*useA,useA[1]);
    matchFrame[7] = IRInst__getOperandSource(operandVReg2,2);
    operandVReg2 = IRInst__getOperandSource(*useA,useA[1]);
    operandRecord = IRInst__getOperandRecord(operandVReg2,1);
    matchFrame[0] = *(uint *)(operandRecord + 0x10);
    operandVReg2 = IRInst__getOperandSource(*useA,useA[1]);
    operandRecord = IRInst__getOperandRecord(operandVReg2,2);
    matchFrame[1] = *(undefined4 *)(operandRecord + 0x10);
    sourceDef = IRInst__getOperandSource(*useA,useA[1]);
    matchFrame[2] = *(uint *)(sourceDef + 0xb8) & 1;
    sourceDef = IRInst__getOperandSource(*useA,useA[1]);
    matchFrame[3] = *(uint *)(sourceDef + 0xd0) & 1;
    sourceDef = IRInst__getOperandSource(*useA,useA[1]);
    matchFrame[4] = *(uint *)(sourceDef + 0xb8) >> 1 & 1;
    sourceDef = IRInst__getOperandSource(*useA,useA[1]);
    matchFrame[5] = *(uint *)(sourceDef + 0xd0) >> 1 & 1;
    operandVReg2 = IRInst__getOperandSource(*useB,useB[1]);
    matchFrame[0xb] = IRInst__getOperandSource(operandVReg2,1);
    operandVReg2 = IRInst__getOperandSource(*useB,useB[1]);
    matchFrame[0xc] = IRInst__getOperandSource(operandVReg2,2);
    useOperandIndexB = useB[1];
    operandVReg2 = IRInst__getOperandSource(*useB,useOperandIndexB + (((int)useOperandIndexB >> 1) +
                                          (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0)) * -2 + 1);
    matchFrame[0xd] = operandVReg2;
    sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
    operandRecord = IRInst__getOperandRecord(sourceDef2,1);
    matchFrame[0xe] = *(undefined4 *)(operandRecord + 0x10);
    sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
    operandRecord = IRInst__getOperandRecord(sourceDef2,2);
    useOperandIndexB = useB[1];
    matchFrame[0xf] = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(*useB,useOperandIndexB + (((int)useOperandIndexB >> 1) +
                                           (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0)) * -2 + 1);
    savedSelectWordB = matchFrame[0xe];
    matchFrame[0x10] = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(*useB,useB[1]);
    SelectWord__compose(&composedSelectOutA,savedSelectWordB,*(undefined4 *)(operandRecord + 0x10));
    savedSelectWordB = matchFrame[0xf];
    matchFrame[0xe] = composedSelectOutA;
    operandRecord = IRInst__getOperandRecord(*useB,useB[1]);
    SelectWord__compose(composedSelectOutB,savedSelectWordB,*(undefined4 *)(operandRecord + 0x10));
    matchFrame[0xf] = composedSelectOutB[0];
    sourceDef = IRInst__getOperandSource(*useB,useB[1]);
    matchFrame[0x11] = *(uint *)(sourceDef + 0xb8) & 1;
    sourceDef = IRInst__getOperandSource(*useB,useB[1]);
    operandIndex4 = useB[1];
    inst3 = *useB;
    matchFrame[0x12] = *(uint *)(sourceDef + 0xd0) & 1;
    matchFrame[0x13] =
         *(uint *)((operandIndex4 + (((int)operandIndex4 >> 1) + (uint)((int)operandIndex4 < 0 && (operandIndex4 & 1) != 0)) * -2) *
                   0x18 + inst3 + 0xb8) & 1;
    if (!consumerIsMul) {
      operandSlotAddrB = inst3 + operandIndex4 * 0x18 + 0x80;
      matchFrame[0x11] = (uint)((*(uint *)(operandSlotAddrB + 0x20) & 1) != matchFrame[0x11]);
      matchFrame[0x12] = *(uint *)(operandSlotAddrB + 0x20) & 1 ^ matchFrame[0x12];
    }
    sourceDef = IRInst__getOperandSource(inst3,operandIndex4);
    termIndexB = 1;
    matchFrame[8] = *(uint *)(sourceDef + 0xb8) >> 1 & 1;
    termByteOffsetB = 0;
    sourceDef = IRInst__getOperandSource(*useB,useB[1]);
    useOperandIndexBTmp = useB[1];
    termByteOffsetA = 0;
    matchFrame[9] = *(uint *)(sourceDef + 0xd0) >> 1 & 1;
    absOtherB = *(uint *)((useOperandIndexBTmp + (((int)useOperandIndexBTmp >> 1) + (uint)((int)useOperandIndexBTmp < 0 && (useOperandIndexBTmp & 1) != 0)) * -2
                      ) * 0x18 + *useB + 0xb8) >> 1 & 1;
    matchFrame[10] = absOtherB;
    termIndexA = 0;
    do {
      nextTermIndexA = termIndexA + 1;
      termA = *(uint *)((int)matchFrame + termByteOffsetA + 0x18);
      termB = *(uint *)((int)matchFrame + termByteOffsetB + 0x2c);
      matchFramePtr = (uint *)((nextTermIndexA / 3) * 3);
      nextTermSlotA = nextTermIndexA % 3;
      if ((termB == termA) &&
         (matchFramePtr = matchFrame + termIndexB, matchFrame[nextTermSlotA + 0xb] == matchFrame[termIndexB + 6])) {
loopCheckConsumerIsMul:
        if (((consumerIsMul) ||
            ((((*(int *)((int)matchFrame + termByteOffsetA + 0x10) == *(int *)((int)matchFrame + termByteOffsetB + 0x20) &&
               (matchFramePtr = matchFrame + termIndexB, matchFrame[termIndexB + 4] == matchFrame[nextTermSlotA + 8])) &&
              (*(int *)((int)matchFrame + termByteOffsetA + 8) == *(int *)((int)matchFrame + termByteOffsetB + 0x44))) &&
             (matchFrame[termIndexB + 2] == matchFrame[nextTermSlotA + 0x11])))) &&
           ((nextTermSlotACopy = nextTermSlotA,
            selectsCompatibleA = SelectWord__matches(*(undefined4 *)((int)matchFrame + termByteOffsetA),
                                 *(undefined4 *)((int)matchFrame + termByteOffsetB + 0x38)), selectsCompatibleA != 0 &&
            (nextTermSlotA = SelectWord__matches(matchFrame[termIndexB],matchFrame[nextTermSlotA + 0xe]), nextTermSlotA != 0)))) {
          if (allowRewrite != 0) {
            if (termIndexA == 2) {
              sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
              IRInst__setOperandSource(sourceDef2,2,operandVReg2,1,*(undefined4 *)(pass + 8));
              sourceDef = IRInst__getOperandSource(*useB,useB[1]);
              IROperand__setModifierBits(sourceDef + 0xbc,1,matchFrame[0x13]);
              sourceDef = IRInst__getOperandSource(*useB,useB[1]);
              IROperand__setModifierBits(sourceDef + 0xbc,2,absOtherB);
              operandVReg2 = IRInst__getOperandSource(*useB,useB[1]);
              savedSelectWordB = matchFrame[0x10];
              operandRecord = IRInst__getOperandRecord(operandVReg2,2);
              *(uint *)(operandRecord + 0x10) = savedSelectWordB;
              sourceDef = IRInst__getOperandSource(*useB,useB[1]);
              IROperand__setModifierBits(sourceDef + 0xa4,1,matchFrame[0x11]);
              sourceDef = IRInst__getOperandSource(*useB,useB[1]);
              IROperand__setModifierBits(sourceDef + 0xa4,2,matchFrame[8]);
              operandVReg2 = IRInst__getOperandSource(*useB,useB[1]);
              savedSelectWordB = matchFrame[0xe];
              operandRecord = IRInst__getOperandRecord(operandVReg2,1);
              *(uint *)(operandRecord + 0x10) = savedSelectWordB;
              useOperandIndexB = useB[1];
              IRInst__setOperandSource(*useB,useOperandIndexB + (((int)useOperandIndexB >> 1) +
                                            (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0)) * -2 + 1,
                           matchFrame[0xc],1,*(undefined4 *)(pass + 8));
              savedSelectWordB = matchFrame[0xf];
              useOperandIndexBCopy = useB[1];
              operandRecord = IRInst__getOperandRecord(*useB,useOperandIndexBCopy + (((int)useOperandIndexBCopy >> 1) +
                                                     (uint)((int)useOperandIndexBCopy < 0 && (useOperandIndexBCopy & 1) != 0)) *
                                                     -2 + 1);
              *(uint *)(operandRecord + 0x10) = savedSelectWordB;
              useOperandIndexB = useB[1];
              IROperand__setModifierBits((useOperandIndexB + (((int)useOperandIndexB >> 1) + (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0))
                                    * -2) * 0x18 + *useB + 0xa4,1,matchFrame[0x12]);
              useOperandIndexB = useB[1];
              IROperand__setModifierBits((useOperandIndexB + (((int)useOperandIndexB >> 1) + (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0))
                                    * -2) * 0x18 + *useB + 0xa4,2,matchFrame[9]);
              if (!consumerIsMul) {
                IROperand__setModifierBits(useB[1] * 0x18 + *useB + 0x8c,1,0);
              }
              inst = *useB;
              operandIndex2 = useB[1];
              operandRecord = IRInst__getOperandRecord(inst,0);
              WriteMask__fromSelectWord(matchFrame + 0x14,*(undefined4 *)(operandRecord + 0x10));
              SelectWord__maskUnused(&maskedSelectOutA,0x10203,matchFrame[0x14]);
              operandRecord = IRInst__getOperandRecord(inst,operandIndex2);
              *(undefined4 *)(operandRecord + 0x10) = maskedSelectOutA;
            }
            else if (termIndexA == 1) {
              sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
              IRInst__setOperandSource(sourceDef2,1,operandVReg2,1,*(undefined4 *)(pass + 8));
              sourceDef = IRInst__getOperandSource(*useB,useB[1]);
              IROperand__setModifierBits(sourceDef + 0xa4,1,matchFrame[0x13]);
              sourceDef = IRInst__getOperandSource(*useB,useB[1]);
              IROperand__setModifierBits(sourceDef + 0xa4,2,absOtherB);
              operandVReg2 = IRInst__getOperandSource(*useB,useB[1]);
              savedSelectWordB = matchFrame[0x10];
              operandRecord = IRInst__getOperandRecord(operandVReg2,1);
              *(uint *)(operandRecord + 0x10) = savedSelectWordB;
              sourceDef = IRInst__getOperandSource(*useB,useB[1]);
              IROperand__setModifierBits(sourceDef + 0xbc,1,matchFrame[0x12]);
              sourceDef = IRInst__getOperandSource(*useB,useB[1]);
              IROperand__setModifierBits(sourceDef + 0xbc,2,matchFrame[9]);
              operandVReg2 = IRInst__getOperandSource(*useB,useB[1]);
              savedSelectWordB = matchFrame[0xf];
              operandRecord = IRInst__getOperandRecord(operandVReg2,2);
              *(uint *)(operandRecord + 0x10) = savedSelectWordB;
              useOperandIndexB = useB[1];
              IRInst__setOperandSource(*useB,useOperandIndexB + (((int)useOperandIndexB >> 1) +
                                            (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0)) * -2 + 1,
                           matchFrame[0xb],1,*(undefined4 *)(pass + 8));
              savedSelectWordB = matchFrame[0xe];
              useOperandIndexBCopy = useB[1];
              operandRecord = IRInst__getOperandRecord(*useB,useOperandIndexBCopy + (((int)useOperandIndexBCopy >> 1) +
                                                     (uint)((int)useOperandIndexBCopy < 0 && (useOperandIndexBCopy & 1) != 0)) *
                                                     -2 + 1);
              *(uint *)(operandRecord + 0x10) = savedSelectWordB;
              useOperandIndexB = useB[1];
              IROperand__setModifierBits((useOperandIndexB + (((int)useOperandIndexB >> 1) + (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0))
                                    * -2) * 0x18 + *useB + 0xa4,1,matchFrame[0x11]);
              useOperandIndexB = useB[1];
              IROperand__setModifierBits((useOperandIndexB + (((int)useOperandIndexB >> 1) + (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0))
                                    * -2) * 0x18 + *useB + 0xa4,2,matchFrame[8]);
              if (!consumerIsMul) {
                IROperand__setModifierBits(useB[1] * 0x18 + *useB + 0x8c,1,0);
              }
              inst2 = *useB;
              operandIndex3 = useB[1];
              operandRecord = IRInst__getOperandRecord(inst2,0);
              WriteMask__fromSelectWord(&writeMaskOut,*(undefined4 *)(operandRecord + 0x10));
              SelectWord__maskUnused(&maskedSelectOutB,0x10203,writeMaskOut);
              operandRecord = IRInst__getOperandRecord(inst2,operandIndex3);
              *(undefined4 *)(operandRecord + 0x10) = maskedSelectOutB;
            }
            operandVReg2 = IRInst__getOperandSource(*useB,useB[1]);
            operandRecord = IRInst__getOperandRecord(operandVReg2,1);
            firstSourceSelect = *(uint *)(operandRecord + 0x10);
            operandVReg2 = IRInst__getOperandSource(*useB,useB[1]);
            operandRecord2 = IRInst__getOperandRecord(operandVReg2,2);
            secondSourceSelect = *(uint *)(operandRecord2 + 0x10);
            operandVReg2 = IRInst__getOperandSource(*useB,useB[1]);
            IRInst__getOperandRecord(operandVReg2,0);
            if ((firstSourceSelect >> 0x18 != 4) || (lane3Flag = 1, secondSourceSelect >> 0x18 != 4)) {
              lane3Flag = 0;
            }
            if (((firstSourceSelect >> 0x10 & 0xff) != 4) || (lane2Flag = 1, (secondSourceSelect >> 0x10 & 0xff) != 4)) {
              lane2Flag = 0;
            }
            if (((firstSourceSelect >> 8 & 0xff) != 4) || (lane1Flag = 1, (secondSourceSelect >> 8 & 0xff) != 4)) {
              lane1Flag = 0;
            }
            if (((firstSourceSelect & 0xff) != 4) || (lane0Flag = 1, (secondSourceSelect & 0xff) != 4)) {
              lane0Flag = 0;
            }
            sourceDef3 = IRInst__getOperandSource(*useB,useB[1]);
            *(uint *)(sourceDef3 + 0x9c) = lane0Flag | lane1Flag << 8 | lane2Flag << 0x10 | lane3Flag << 0x18;
            operandVReg2 = IRInst__getOperandSource(*useA,useA[1]);
            ((int (*)())Inst__hoistToOperandBlock)(pass,operandVReg2,pass);
            if (allowOperandSwap != 0) {
              operandVReg = (int *)IRInst__getOperandSource(*useB,useB[1]);
              operandIndex = useB[1];
              inst4 = *useB;
              operandVReg2 = IRInst__getOperandSource(*useA,useA[1]);
              compilerCtx = *(undefined4 *)(pass + 8);
              staleArg4Value = 1;
              IRInst__setOperandSource(inst4,operandIndex,operandVReg2,1,compilerCtx);
              hasNoUsesResult = IRInst__hasNoUses(operandVReg,pass,operandVReg2,staleArg4Value,compilerCtx,nextTermSlotACopy,matchFramePtr);
              if (hasNoUsesResult != 0) {
                (**(code **)(*operandVReg + 0xc))(operandVReg,1,*(undefined4 *)(pass + 8));
                return 1;
              }
            }
          }
          return 1;
        }
      }
      else if ((termB == matchFrame[termIndexB + 6]) && (termA == matchFrame[nextTermSlotA + 0xb])) {
        termIndexB = 0;
        termByteOffsetA = 4;
        goto loopCheckConsumerIsMul;
      }
      termByteOffsetB = termByteOffsetB + 4;
      termIndexA = nextTermIndexA;
    } while (nextTermIndexA != 3);
  }
  return 0;
}

/* Inst__swapMatchedOperandsBetweenUses @ 0x14f420 (4784 bytes) */
int Inst__swapMatchedOperandsBetweenUses(useA, useB, pass, allowRewrite, allowOperandSwap)
  int *useA;
  int *useB;
  int pass;
  int allowRewrite;
  int allowOperandSwap;
{
  uint lane0Flag;
  uint *termPtrA;
  uint *termB;
  int lane3Flag;
  int termIndexAPlusOne;
  int operandSlotAddrB;
  int operandSlotAddrA;
  int precheckResult;
  int consumerInstA;
  int selectsCompatible;
  int lane1Flag;
  int selectsCompatible2;
  int lane2Flag;
  int termByteOffsetB;
  undefined4 copiedSelectWord;
  uint useOperandIndexACopy;
  uint useOperandIndexBCopy;
  uint secondSourceSelect;
  uint savedSelectWordB2;
  uint savedSelectWordA;
  uint useOperandIndexB;
  uint set9;
  uint operandIndex10;
  uint operandIndex9;
  int operandIndex8;
  int inst10;
  int operandIndex7;
  int operandIndex6;
  int operandIndex5;
  int operandIndex4;
  int operandIndex3;
  int inst9;
  int inst8;
  int newSource;
  int operandIndex2;
  int inst7;
  int inst6;
  int inst5;
  int inst4;
  int inst3;
  int inst2;
  int operandIndex;
  int inst;
  undefined4 sourceDef;
  int sourceDef3;
  int operandRecord2;
  int sourceDef2;
  int operandRecord;
  bool consumerIsNotMul;
  bool foundMatch;
  int matchIndexOrSource;
  undefined4 savedSelectWordB;
  undefined4 operandVReg;
  int selectsCompatibleA;
  int matchCandidateByteOffsetA;
  int *updatedSourceInst;
  uint useOperandIndexA;
  uint firstSourceSelect;
  int compilerCtx;
  uint *termA;
  int nextTermSlotB;
  int matchedIndexA;
  int nextTermSlotA;
  uint *termSlotPtrB;
  uint *termSlotPtrA;
  int matchCandidateIndexA;
  int operandRecord3;
  uint *nextTermIndexB;
  int programHome;
  int allowRewriteHome;
  int allowOperandSwapHome;
  uint matchFrame [7];
  uint negateOp2A;
  uint negateOtherA;
  uint absOp1A;
  uint absOp2A;
  uint absOtherA;
  uint termInstsB [4];
  undefined4 selectWordOp2B;
  undefined4 selectWordOtherB;
  uint negateOp1B;
  uint negateOp2B;
  uint negateOtherB;
  uint termInstsA [4];
  undefined4 composedSelectB2;
  undefined4 destWriteMaskB2;
  undefined4 maskedDestSelectB2;
  undefined4 destWriteMaskB1;
  undefined4 maskedDestSelectB1;
  undefined4 destWriteMaskA2;
  undefined4 maskedDestSelectA2;
  undefined4 destWriteMaskA1;
  undefined4 maskedDestSelectA1;
  undefined4 composedSelectA1;
  undefined4 composedSelectA2;
  uint *termIndexB;
  int crossedMatch;
  uint absOtherAHome;
  undefined4 newSource2;
  uint *negateFlagsPtrB;
  uint *selectWordsPtrB;
  
  consumerInstA = *useA;
  consumerIsNotMul = *(int *)(*(int *)(consumerInstA + 0x88) + 8) != 0x13;
  programHome = pass;
  allowRewriteHome = allowRewrite;
  allowOperandSwapHome = allowOperandSwap;
  if (!consumerIsNotMul) {
    precheckResult = ((int (*)())Use__negationParityEqual)(useA,useB);
    if (precheckResult == 0) {
      return 0;
    }
    consumerInstA = *useA;
  }
  matchIndexOrSource = IRInst__getOperandSource(*useB,useB[1]);
  if ((consumerInstA == matchIndexOrSource) ||
     (matchIndexOrSource = *useB, consumerInstA = IRInst__getOperandSource(*useA,useA[1]), matchIndexOrSource == consumerInstA)) {
    return 0;
  }
  sourceDef = IRInst__getOperandSource(*useA,useA[1]);
  termInstsA[0] = IRInst__getOperandSource(sourceDef,1);
  sourceDef = IRInst__getOperandSource(*useA,useA[1]);
  termInstsA[1] = IRInst__getOperandSource(sourceDef,2);
  useOperandIndexA = useA[1];
  termInstsA[2] = IRInst__getOperandSource(*useA,useOperandIndexA + (((int)useOperandIndexA >> 1) +
                                              (uint)((int)useOperandIndexA < 0 && (useOperandIndexA & 1) != 0)) * -2 + 1);
  newSource2 = termInstsA[2];
  sourceDef = IRInst__getOperandSource(*useA,useA[1]);
  operandRecord = IRInst__getOperandRecord(sourceDef,1);
  matchFrame[3] = *(undefined4 *)(operandRecord + 0x10);
  sourceDef = IRInst__getOperandSource(*useA,useA[1]);
  operandRecord = IRInst__getOperandRecord(sourceDef,2);
  useOperandIndexA = useA[1];
  matchFrame[4] = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(*useA,useOperandIndexA + (((int)useOperandIndexA >> 1) +
                                         (uint)((int)useOperandIndexA < 0 && (useOperandIndexA & 1) != 0)) * -2 + 1);
  savedSelectWordA = matchFrame[3];
  matchFrame[5] = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(*useA,useA[1]);
  SelectWord__compose(&composedSelectA1,savedSelectWordA,*(undefined4 *)(operandRecord + 0x10));
  savedSelectWordA = matchFrame[4];
  matchFrame[3] = composedSelectA1;
  operandRecord = IRInst__getOperandRecord(*useA,useA[1]);
  SelectWord__compose(&composedSelectA2,savedSelectWordA,*(undefined4 *)(operandRecord + 0x10));
  matchFrame[4] = composedSelectA2;
  sourceDef2 = IRInst__getOperandSource(*useA,useA[1]);
  matchFrame[6] = *(uint *)(sourceDef2 + 0xb8) & 1;
  sourceDef2 = IRInst__getOperandSource(*useA,useA[1]);
  operandIndex9 = useA[1];
  inst8 = *useA;
  negateOp2A = *(uint *)(sourceDef2 + 0xd0) & 1;
  negateOtherA = *(uint *)((operandIndex9 + (((int)operandIndex9 >> 1) + (uint)((int)operandIndex9 < 0 && (operandIndex9 & 1) != 0)) *
                                -2) * 0x18 + inst8 + 0xb8) & 1;
  if (consumerIsNotMul) {
    operandSlotAddrA = inst8 + operandIndex9 * 0x18 + 0x80;
    matchFrame[6] = (uint)((*(uint *)(operandSlotAddrA + 0x20) & 1) != matchFrame[6]);
    negateOp2A = *(uint *)(operandSlotAddrA + 0x20) & 1 ^ negateOp2A;
  }
  sourceDef2 = IRInst__getOperandSource(inst8,operandIndex9);
  absOp1A = *(uint *)(sourceDef2 + 0xb8) >> 1 & 1;
  sourceDef2 = IRInst__getOperandSource(*useA,useA[1]);
  useOperandIndexA = useA[1];
  absOp2A = *(uint *)(sourceDef2 + 0xd0) >> 1 & 1;
  absOtherA = *(uint *)((useOperandIndexA + (((int)useOperandIndexA >> 1) + (uint)((int)useOperandIndexA < 0 && (useOperandIndexA & 1) != 0)) *
                                -2) * 0x18 + *useA + 0xb8) >> 1 & 1;
  absOtherAHome = absOtherA;
  sourceDef = IRInst__getOperandSource(*useB,useB[1]);
  termInstsB[0] = IRInst__getOperandSource(sourceDef,1);
  sourceDef = IRInst__getOperandSource(*useB,useB[1]);
  termInstsB[1] = IRInst__getOperandSource(sourceDef,2);
  useOperandIndexB = useB[1];
  operandVReg = IRInst__getOperandSource(*useB,useOperandIndexB + (((int)useOperandIndexB >> 1) +
                                        (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0)) * -2 + 1);
  termInstsB[2] = operandVReg;
  sourceDef = IRInst__getOperandSource(*useB,useB[1]);
  operandRecord = IRInst__getOperandRecord(sourceDef,1);
  termInstsB[3] = *(undefined4 *)(operandRecord + 0x10);
  sourceDef = IRInst__getOperandSource(*useB,useB[1]);
  operandRecord = IRInst__getOperandRecord(sourceDef,2);
  useOperandIndexB = useB[1];
  selectWordOp2B = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(*useB,useOperandIndexB + (((int)useOperandIndexB >> 1) +
                                         (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0)) * -2 + 1);
  savedSelectWordB2 = termInstsB[3];
  selectWordOtherB = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(*useB,useB[1]);
  SelectWord__compose(matchFrame + 0x18,savedSelectWordB2,*(undefined4 *)(operandRecord + 0x10));
  savedSelectWordB = selectWordOp2B;
  termInstsB[3] = termInstsA[3];
  operandRecord = IRInst__getOperandRecord(*useB,useB[1]);
  SelectWord__compose(&composedSelectB2,savedSelectWordB,*(undefined4 *)(operandRecord + 0x10));
  selectWordOp2B = composedSelectB2;
  sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
  negateOp1B = *(uint *)(sourceDef2 + 0xb8) & 1;
  sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
  operandIndex10 = useB[1];
  inst9 = *useB;
  negateOp2B = *(uint *)(sourceDef2 + 0xd0) & 1;
  negateOtherB = *(uint *)((operandIndex10 + (((int)operandIndex10 >> 1) + (uint)((int)operandIndex10 < 0 && (operandIndex10 & 1) != 0)) *
                                -2) * 0x18 + inst9 + 0xb8) & 1;
  if (consumerIsNotMul) {
    operandSlotAddrB = inst9 + operandIndex10 * 0x18 + 0x80;
    negateOp1B = (uint)((*(uint *)(operandSlotAddrB + 0x20) & 1) != negateOp1B);
    negateOp2B = *(uint *)(operandSlotAddrB + 0x20) & 1 ^ negateOp2B;
  }
  sourceDef2 = IRInst__getOperandSource(inst9,operandIndex10);
  matchFrame[0] = *(uint *)(sourceDef2 + 0xb8) >> 1 & 1;
  termByteOffsetB = 0;
  sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
  set9 = useB[1];
  matchFrame[1] = *(uint *)(sourceDef2 + 0xd0) >> 1 & 1;
  termIndexB = (uint *)0x0;
  set9 = *(uint *)((set9 + (((int)set9 >> 1) + (uint)((int)set9 < 0 && (set9 & 1) != 0)) * -2)
                    * 0x18 + *useB + 0xb8) >> 1 & 1;
  negateFlagsPtrB = matchFrame + 0x12;
  matchFrame[2] = set9;
  selectWordsPtrB = matchFrame + 0xf;
loopSetTermB:
  termB = *(uint **)((int)matchFrame + termByteOffsetB + 0x30);
  nextTermIndexB = (uint *)((int)termIndexB + 1);
  nextTermSlotB = (int)nextTermIndexB % 3;
  termIndexAPlusOne = 0;
  termPtrA = matchFrame + 0x15;
  do {
    compilerCtx = termIndexAPlusOne;
    termIndexAPlusOne = compilerCtx + 1;
    termA = (uint *)*termPtrA;
    nextTermSlotA = termIndexAPlusOne % 3;
    if ((termB == termA) && (matchFrame[nextTermSlotB + 0xc] == matchFrame[nextTermSlotA + 0x15])) {
      crossedMatch = 0;
      matchCandidateIndexA = compilerCtx;
loopSetMatchedIndexA:
      matchedIndexA = matchCandidateIndexA;
      if (consumerIsNotMul) {
        matchCandidateByteOffsetA = matchCandidateIndexA * 4;
        if ((((matchFrame[matchCandidateIndexA + 9] != *(uint *)((int)matchFrame + termByteOffsetB)) ||
             (termA = matchFrame + nextTermSlotB, matchFrame[nextTermSlotA + 9] != matchFrame[nextTermSlotB])) ||
            (matchFrame[matchCandidateIndexA + 6] != *(uint *)(termByteOffsetB + (int)negateFlagsPtrB))) ||
           (matchFrame[nextTermSlotA + 6] != matchFrame[nextTermSlotB + 0x12])) goto setTermPtrA;
      }
      else {
        matchCandidateByteOffsetA = matchCandidateIndexA << 2;
      }
      selectsCompatibleA = SelectWord__matches(*(undefined4 *)((int)matchFrame + matchCandidateByteOffsetA + 0xc),
                           *(undefined4 *)(termByteOffsetB + (int)selectWordsPtrB));
      if (((selectsCompatibleA != 0) &&
          (selectsCompatibleA = SelectWord__matches(matchFrame[nextTermSlotA + 3],matchFrame[nextTermSlotB + 0xf]), selectsCompatibleA != 0)) ||
         ((matchCandidateByteOffsetA = SelectWord__matches(*(undefined4 *)(termByteOffsetB + (int)selectWordsPtrB),
                                *(undefined4 *)((int)matchFrame + matchCandidateByteOffsetA + 0xc)), matchCandidateByteOffsetA != 0 &&
          (matchCandidateByteOffsetA = SelectWord__matches(matchFrame[nextTermSlotB + 0xf],matchFrame[nextTermSlotA + 3]), matchCandidateByteOffsetA != 0)))) {
        if (crossedMatch != 0) {
          matchedIndexA = nextTermSlotA;
          nextTermSlotA = matchCandidateIndexA;
        }
        if (allowRewriteHome == 0) {
          return 1;
        }
        foundMatch = true;
        goto checkNextTermIndexB;
      }
    }
    else {
      if ((termB == (uint *)matchFrame[nextTermSlotA + 0x15]) &&
         (termA == (uint *)matchFrame[nextTermSlotB + 0xc])) {
        crossedMatch = 1;
        matchCandidateIndexA = nextTermSlotA;
        nextTermSlotA = compilerCtx;
        goto loopSetMatchedIndexA;
      }
      crossedMatch = 0;
      matchedIndexA = compilerCtx;
    }
setTermPtrA:
    termPtrA = termPtrA + 1;
  } while (termIndexAPlusOne != 3);
  foundMatch = false;
checkNextTermIndexB:
  if (nextTermIndexB != (uint *)((int)((unsigned char *)0x0) + 3)) {
    termByteOffsetB = termByteOffsetB + 4;
    if (foundMatch) goto checkTermIndexB;
    termIndexB = nextTermIndexB;
    goto loopSetTermB;
  }
  if (!foundMatch) {
    return 0;
  }
checkTermIndexB:
  if (termIndexB == (uint *)((int)((unsigned char *)0x0) + 2)) {
    sourceDef = IRInst__getOperandSource(*useB,useB[1]);
    IRInst__setOperandSource(sourceDef,2,operandVReg,1,*(undefined4 *)(programHome + 8));
    sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
    IROperand__setModifierBits(sourceDef2 + 0xbc,1,negateOtherB);
    sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
    IROperand__setModifierBits(sourceDef2 + 0xbc,2,set9);
    operandVReg = IRInst__getOperandSource(*useB,useB[1]);
    savedSelectWordB = selectWordOtherB;
    operandRecord = IRInst__getOperandRecord(operandVReg,2);
    *(undefined4 *)(operandRecord + 0x10) = savedSelectWordB;
    sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
    IROperand__setModifierBits(sourceDef2 + 0xa4,1,negateOp1B);
    sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
    IROperand__setModifierBits(sourceDef2 + 0xa4,2,matchFrame[0]);
    sourceDef = IRInst__getOperandSource(*useB,useB[1]);
    savedSelectWordB2 = termInstsB[3];
    operandRecord = IRInst__getOperandRecord(sourceDef,1);
    allowRewrite = 1;
    *(uint *)(operandRecord + 0x10) = savedSelectWordB2;
    useOperandIndexB = useB[1];
    compilerCtx = *(int *)(programHome + 8);
    IRInst__setOperandSource(*useB,useOperandIndexB + (((int)useOperandIndexB >> 1) + (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0)) *
                                  -2 + 1,termInstsB[1],1,compilerCtx);
    savedSelectWordB = selectWordOp2B;
    useOperandIndexB = useB[1];
    operandRecord = IRInst__getOperandRecord(*useB,useOperandIndexB + (((int)useOperandIndexB >> 1) +
                                           (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0)) * -2 + 1);
    *(undefined4 *)(operandRecord + 0x10) = savedSelectWordB;
    useOperandIndexB = useB[1];
    IROperand__setModifierBits((useOperandIndexB + (((int)useOperandIndexB >> 1) + (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0)) * -2) *
                 0x18 + *useB + 0xa4,1,negateOp2B);
    useOperandIndexB = useB[1];
    IROperand__setModifierBits((useOperandIndexB + (((int)useOperandIndexB >> 1) + (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0)) * -2) *
                 0x18 + *useB + 0xa4,2,matchFrame[1]);
    if (consumerIsNotMul) {
      IROperand__setModifierBits(useB[1] * 0x18 + *useB + 0x8c,1,0);
    }
    inst4 = *useB;
    operandIndex3 = useB[1];
    operandRecord = IRInst__getOperandRecord(inst4,0);
    WriteMask__fromSelectWord(&destWriteMaskB2,*(undefined4 *)(operandRecord + 0x10));
    SelectWord__maskUnused(&maskedDestSelectB2,0x10203,destWriteMaskB2);
    operandRecord = IRInst__getOperandRecord(inst4,operandIndex3);
    *(undefined4 *)(operandRecord + 0x10) = maskedDestSelectB2;
  }
  else if (termIndexB == (uint *)((int)((unsigned char *)0x0) + 1)) {
    sourceDef = IRInst__getOperandSource(*useB,useB[1]);
    IRInst__setOperandSource(sourceDef,1,operandVReg,1,*(undefined4 *)(programHome + 8));
    sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
    IROperand__setModifierBits(sourceDef2 + 0xa4,1,negateOtherB);
    sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
    IROperand__setModifierBits(sourceDef2 + 0xa4,2,set9);
    operandVReg = IRInst__getOperandSource(*useB,useB[1]);
    savedSelectWordB = selectWordOtherB;
    operandRecord = IRInst__getOperandRecord(operandVReg,1);
    *(undefined4 *)(operandRecord + 0x10) = savedSelectWordB;
    sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
    IROperand__setModifierBits(sourceDef2 + 0xbc,1,negateOp2B);
    sourceDef2 = IRInst__getOperandSource(*useB,useB[1]);
    IROperand__setModifierBits(sourceDef2 + 0xbc,2,matchFrame[1]);
    operandVReg = IRInst__getOperandSource(*useB,useB[1]);
    savedSelectWordB = selectWordOp2B;
    operandRecord = IRInst__getOperandRecord(operandVReg,2);
    allowRewrite = 1;
    *(undefined4 *)(operandRecord + 0x10) = savedSelectWordB;
    useOperandIndexB = useB[1];
    compilerCtx = *(int *)(programHome + 8);
    IRInst__setOperandSource(*useB,useOperandIndexB + (((int)useOperandIndexB >> 1) + (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0)) *
                                  -2 + 1,termInstsB[0],1,compilerCtx);
    savedSelectWordB2 = termInstsB[3];
    useOperandIndexBCopy = useB[1];
    operandRecord = IRInst__getOperandRecord(*useB,useOperandIndexBCopy + (((int)useOperandIndexBCopy >> 1) +
                                            (uint)((int)useOperandIndexBCopy < 0 && (useOperandIndexBCopy & 1) != 0)) * -2 + 1);
    *(uint *)(operandRecord + 0x10) = savedSelectWordB2;
    useOperandIndexB = useB[1];
    IROperand__setModifierBits((useOperandIndexB + (((int)useOperandIndexB >> 1) + (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0)) * -2) *
                 0x18 + *useB + 0xa4,1,negateOp1B);
    useOperandIndexB = useB[1];
    IROperand__setModifierBits((useOperandIndexB + (((int)useOperandIndexB >> 1) + (uint)((int)useOperandIndexB < 0 && (useOperandIndexB & 1) != 0)) * -2) *
                 0x18 + *useB + 0xa4,2,matchFrame[0]);
    if (consumerIsNotMul) {
      IROperand__setModifierBits(useB[1] * 0x18 + *useB + 0x8c,1,0);
    }
    inst5 = *useB;
    operandIndex4 = useB[1];
    operandRecord = IRInst__getOperandRecord(inst5,0);
    WriteMask__fromSelectWord(&destWriteMaskB1,*(undefined4 *)(operandRecord + 0x10));
    SelectWord__maskUnused(&maskedDestSelectB1,0x10203,destWriteMaskB1);
    operandRecord = IRInst__getOperandRecord(inst5,operandIndex4);
    *(undefined4 *)(operandRecord + 0x10) = maskedDestSelectB1;
  }
  if (matchedIndexA == 2) {
    sourceDef = IRInst__getOperandSource(*useA,useA[1]);
    IRInst__setOperandSource(sourceDef,2,newSource2,1,*(undefined4 *)(programHome + 8));
    sourceDef2 = IRInst__getOperandSource(*useA,useA[1]);
    IROperand__setModifierBits(sourceDef2 + 0xbc,1,negateOtherA);
    sourceDef2 = IRInst__getOperandSource(*useA,useA[1]);
    IROperand__setModifierBits(sourceDef2 + 0xbc,2,absOtherAHome);
    sourceDef = IRInst__getOperandSource(*useA,useA[1]);
    savedSelectWordA = matchFrame[5];
    operandRecord = IRInst__getOperandRecord(sourceDef,2);
    *(uint *)(operandRecord + 0x10) = savedSelectWordA;
    sourceDef2 = IRInst__getOperandSource(*useA,useA[1]);
    IROperand__setModifierBits(sourceDef2 + 0xa4,1,matchFrame[6]);
    sourceDef2 = IRInst__getOperandSource(*useA,useA[1]);
    IROperand__setModifierBits(sourceDef2 + 0xa4,2,absOp1A);
    sourceDef = IRInst__getOperandSource(*useA,useA[1]);
    savedSelectWordA = matchFrame[3];
    operandRecord = IRInst__getOperandRecord(sourceDef,1);
    allowRewrite = 1;
    *(uint *)(operandRecord + 0x10) = savedSelectWordA;
    useOperandIndexA = useA[1];
    compilerCtx = *(int *)(programHome + 8);
    IRInst__setOperandSource(*useA,useOperandIndexA + (((int)useOperandIndexA >> 1) + (uint)((int)useOperandIndexA < 0 && (useOperandIndexA & 1) != 0)) *
                                  -2 + 1,termInstsA[1],1,compilerCtx);
    savedSelectWordA = matchFrame[4];
    useOperandIndexACopy = useA[1];
    operandRecord = IRInst__getOperandRecord(*useA,useOperandIndexACopy + (((int)useOperandIndexACopy >> 1) +
                                            (uint)((int)useOperandIndexACopy < 0 && (useOperandIndexACopy & 1) != 0)) * -2 + 1);
    *(uint *)(operandRecord + 0x10) = savedSelectWordA;
    useOperandIndexA = useA[1];
    IROperand__setModifierBits((useOperandIndexA + (((int)useOperandIndexA >> 1) + (uint)((int)useOperandIndexA < 0 && (useOperandIndexA & 1) != 0)) * -2) *
                 0x18 + *useA + 0xa4,1,negateOp2A);
    useOperandIndexA = useA[1];
    IROperand__setModifierBits((useOperandIndexA + (((int)useOperandIndexA >> 1) + (uint)((int)useOperandIndexA < 0 && (useOperandIndexA & 1) != 0)) * -2) *
                 0x18 + *useA + 0xa4,2,absOp2A);
    if (consumerIsNotMul) {
      IROperand__setModifierBits(useA[1] * 0x18 + *useA + 0x8c,1,0);
    }
    inst6 = *useA;
    operandIndex5 = useA[1];
    operandRecord = IRInst__getOperandRecord(inst6,0);
    WriteMask__fromSelectWord(&destWriteMaskA2,*(undefined4 *)(operandRecord + 0x10));
    SelectWord__maskUnused(&maskedDestSelectA2,0x10203,destWriteMaskA2);
    operandRecord = IRInst__getOperandRecord(inst6,operandIndex5);
    *(undefined4 *)(operandRecord + 0x10) = maskedDestSelectA2;
  }
  else if (matchedIndexA == 1) {
    sourceDef = IRInst__getOperandSource(*useA,useA[1]);
    IRInst__setOperandSource(sourceDef,1,newSource2,1,*(undefined4 *)(programHome + 8));
    sourceDef2 = IRInst__getOperandSource(*useA,useA[1]);
    IROperand__setModifierBits(sourceDef2 + 0xa4,1,negateOtherA);
    sourceDef2 = IRInst__getOperandSource(*useA,useA[1]);
    IROperand__setModifierBits(sourceDef2 + 0xa4,2,absOtherAHome);
    sourceDef = IRInst__getOperandSource(*useA,useA[1]);
    savedSelectWordA = matchFrame[5];
    operandRecord = IRInst__getOperandRecord(sourceDef,1);
    *(uint *)(operandRecord + 0x10) = savedSelectWordA;
    sourceDef2 = IRInst__getOperandSource(*useA,useA[1]);
    IROperand__setModifierBits(sourceDef2 + 0xbc,1,negateOp2A);
    sourceDef2 = IRInst__getOperandSource(*useA,useA[1]);
    IROperand__setModifierBits(sourceDef2 + 0xbc,2,absOp2A);
    sourceDef = IRInst__getOperandSource(*useA,useA[1]);
    savedSelectWordA = matchFrame[4];
    operandRecord = IRInst__getOperandRecord(sourceDef,2);
    allowRewrite = 1;
    *(uint *)(operandRecord + 0x10) = savedSelectWordA;
    useOperandIndexA = useA[1];
    compilerCtx = *(int *)(programHome + 8);
    IRInst__setOperandSource(*useA,useOperandIndexA + (((int)useOperandIndexA >> 1) + (uint)((int)useOperandIndexA < 0 && (useOperandIndexA & 1) != 0)) *
                                  -2 + 1,termInstsA[0],1,compilerCtx);
    savedSelectWordA = matchFrame[3];
    useOperandIndexACopy = useA[1];
    operandRecord = IRInst__getOperandRecord(*useA,useOperandIndexACopy + (((int)useOperandIndexACopy >> 1) +
                                            (uint)((int)useOperandIndexACopy < 0 && (useOperandIndexACopy & 1) != 0)) * -2 + 1);
    *(uint *)(operandRecord + 0x10) = savedSelectWordA;
    useOperandIndexA = useA[1];
    IROperand__setModifierBits((useOperandIndexA + (((int)useOperandIndexA >> 1) + (uint)((int)useOperandIndexA < 0 && (useOperandIndexA & 1) != 0)) * -2) *
                 0x18 + *useA + 0xa4,1,matchFrame[6]);
    useOperandIndexA = useA[1];
    IROperand__setModifierBits((useOperandIndexA + (((int)useOperandIndexA >> 1) + (uint)((int)useOperandIndexA < 0 && (useOperandIndexA & 1) != 0)) * -2) *
                 0x18 + *useA + 0xa4,2,absOp1A);
    if (consumerIsNotMul) {
      IROperand__setModifierBits(useA[1] * 0x18 + *useA + 0x8c,1,0);
    }
    inst7 = *useA;
    operandIndex6 = useA[1];
    operandRecord = IRInst__getOperandRecord(inst7,0);
    WriteMask__fromSelectWord(&destWriteMaskA1,*(undefined4 *)(operandRecord + 0x10));
    SelectWord__maskUnused(&maskedDestSelectA1,0x10203,destWriteMaskA1);
    operandRecord = IRInst__getOperandRecord(inst7,operandIndex6);
    *(undefined4 *)(operandRecord + 0x10) = maskedDestSelectA1;
  }
  sourceDef = IRInst__getOperandSource(*useA,useA[1]);
  operandRecord = IRInst__getOperandRecord(sourceDef,1);
  firstSourceSelect = *(uint *)(operandRecord + 0x10);
  sourceDef = IRInst__getOperandSource(*useA,useA[1]);
  operandRecord3 = IRInst__getOperandRecord(sourceDef,2);
  secondSourceSelect = *(uint *)(operandRecord3 + 0x10);
  sourceDef = IRInst__getOperandSource(*useA,useA[1]);
  IRInst__getOperandRecord(sourceDef,0);
  if ((firstSourceSelect >> 0x18 != 4) || (lane3Flag = 1, secondSourceSelect >> 0x18 != 4)) {
    lane3Flag = 0;
  }
  if (((firstSourceSelect >> 0x10 & 0xff) != 4) || (lane2Flag = 1, (secondSourceSelect >> 0x10 & 0xff) != 4)) {
    lane2Flag = 0;
  }
  if (((firstSourceSelect >> 8 & 0xff) != 4) || (lane1Flag = 1, (secondSourceSelect >> 8 & 0xff) != 4)) {
    lane1Flag = 0;
  }
  if (((firstSourceSelect & 0xff) != 4) || (lane0Flag = 1, (secondSourceSelect & 0xff) != 4)) {
    lane0Flag = 0;
  }
  sourceDef3 = IRInst__getOperandSource(*useA,useA[1]);
  *(uint *)(sourceDef3 + 0x9c) = lane0Flag | lane1Flag << 8 | lane2Flag << 0x10 | lane3Flag << 0x18;
  sourceDef = IRInst__getOperandSource(*useB,useB[1]);
  operandRecord = IRInst__getOperandRecord(sourceDef,1);
  firstSourceSelect = *(uint *)(operandRecord + 0x10);
  sourceDef = IRInst__getOperandSource(*useB,useB[1]);
  operandRecord3 = IRInst__getOperandRecord(sourceDef,2);
  secondSourceSelect = *(uint *)(operandRecord3 + 0x10);
  sourceDef = IRInst__getOperandSource(*useB,useB[1]);
  IRInst__getOperandRecord(sourceDef,0);
  if ((firstSourceSelect >> 0x18 != 4) || (lane3Flag = 1, secondSourceSelect >> 0x18 != 4)) {
    lane3Flag = 0;
  }
  if (((firstSourceSelect >> 0x10 & 0xff) != 4) || (lane2Flag = 1, (secondSourceSelect >> 0x10 & 0xff) != 4)) {
    lane2Flag = 0;
  }
  if (((firstSourceSelect >> 8 & 0xff) != 4) || (lane1Flag = 1, (secondSourceSelect >> 8 & 0xff) != 4)) {
    lane1Flag = 0;
  }
  if (((firstSourceSelect & 0xff) != 4) || (lane0Flag = 1, (secondSourceSelect & 0xff) != 4)) {
    lane0Flag = 0;
  }
  sourceDef3 = IRInst__getOperandSource(*useB,useB[1]);
  *(uint *)(sourceDef3 + 0x9c) = lane0Flag | lane1Flag << 8 | lane2Flag << 0x10 | lane3Flag << 0x18;
  sourceDef = IRInst__getOperandSource(*useB,useB[1]);
  ((int (*)())Inst__hoistToOperandBlock)(programHome,sourceDef,programHome);
  sourceDef = IRInst__getOperandSource(*useA,useA[1]);
  newSource = programHome;
  ((int (*)())Inst__hoistToOperandBlock)(programHome,sourceDef,programHome);
  termSlotPtrA = termIndexB;
  matchIndexOrSource = matchedIndexA;
  if (crossedMatch != 0) {
    matchIndexOrSource = nextTermSlotA;
    nextTermSlotA = matchedIndexA;
  }
  if (allowOperandSwapHome == 0) {
    return 1;
  }
  termSlotPtrB = termIndexB;
  selectsCompatible = SelectWord__matches(matchFrame[matchIndexOrSource + 3],matchFrame[(int)((int)termIndexB + 0xf)]);
  if (selectsCompatible == 0) {
loopSetMatchIndexOrSource:
    matchIndexOrSource = SelectWord__matches(matchFrame[(int)((int)termSlotPtrA + 0xf)],matchFrame[matchIndexOrSource + 3]);
    if (matchIndexOrSource != 0) {
      termSlotPtrB = matchFrame + nextTermSlotA;
      selectsCompatible2 = SelectWord__matches(matchFrame[nextTermSlotB + 0xf],matchFrame[nextTermSlotA + 3]);
      if (selectsCompatible2 != 0) {
        updatedSourceInst = (int *)IRInst__getOperandSource(*useA,useA[1]);
        inst = *useA;
        operandIndex7 = useA[1];
        newSource = IRInst__getOperandSource(*useB,useB[1]);
        compilerCtx = *(int *)(programHome + 8);
        allowRewrite = 1;
        IRInst__setOperandSource(inst,operandIndex7,newSource,1,compilerCtx);
        operandIndex = useB[1];
        inst10 = *useB;
        operandIndex2 = useA[1];
        inst3 = *useA;
        goto setOperandRecord2;
      }
    }
    updatedSourceInst = (int *)0x0;
  }
  else {
    termSlotPtrB = matchFrame + nextTermSlotB;
    selectsCompatible = SelectWord__matches(matchFrame[nextTermSlotA + 3],matchFrame[nextTermSlotB + 0xf]);
    if (selectsCompatible == 0) goto loopSetMatchIndexOrSource;
    updatedSourceInst = (int *)IRInst__getOperandSource(*useB,useB[1]);
    inst2 = *useB;
    operandIndex8 = useB[1];
    newSource = IRInst__getOperandSource(*useA,useA[1]);
    compilerCtx = *(int *)(programHome + 8);
    allowRewrite = 1;
    IRInst__setOperandSource(inst2,operandIndex8,newSource,1,compilerCtx);
    operandIndex = useA[1];
    inst10 = *useA;
    operandIndex2 = useB[1];
    inst3 = *useB;
setOperandRecord2:
    operandRecord2 = IRInst__getOperandRecord(inst10,operandIndex);
    copiedSelectWord = *(undefined4 *)(operandRecord2 + 0x10);
    operandRecord2 = IRInst__getOperandRecord(inst3,operandIndex2);
    *(undefined4 *)(operandRecord2 + 0x10) = copiedSelectWord;
  }
  newSource = IRInst__hasNoUses(updatedSourceInst,programHome,newSource,allowRewrite,compilerCtx,termA,termSlotPtrB);
  if (newSource == 0) {
    return 1;
  }
  (**(code **)(*updatedSourceInst + 0xc))(updatedSourceInst,1,*(undefined4 *)(programHome + 8));
  return 1;
}

/* Inst__reassociateUsePair @ 0x1506d0 (256 bytes) */
int Inst__reassociateUsePair(useA, useB, pass)
  undefined4 *useA;
  undefined4 useB;
  undefined4 pass;
{
  undefined4 sourceDef;
  int useAPrecheck;
  int useBPrecheck;
  int swapSharedTermBetweenUsesResult;
  undefined4 programCopy;
  undefined4 staleArg6;
  undefined4 staleArg7;
  undefined4 staleArg8;
  undefined4 staleArg9;
  
  programCopy = pass;
  useAPrecheck = ((int (*)())Use__sourceIsPlainSingleUse)(useA,pass,pass,staleArg6,staleArg7,staleArg8,staleArg9);
  useBPrecheck = ((int (*)())Use__sourceIsPlainSingleUse)(useB,pass,programCopy,staleArg6,staleArg7,staleArg8,staleArg9);
  if ((((useAPrecheck == 0) || (swapSharedTermBetweenUsesResult = ((int (*)())Inst__swapSharedTermBetweenUses)(useB,useA,pass,1,1), swapSharedTermBetweenUsesResult == 0)) &&
      ((useBPrecheck == 0 || (swapSharedTermBetweenUsesResult = ((int (*)())Inst__swapSharedTermBetweenUses)(useA,useB,pass,1,1), swapSharedTermBetweenUsesResult == 0)))) &&
     (((useAPrecheck == 0 || (useBPrecheck == 0)) ||
      (useAPrecheck = ((int (*)())Inst__swapMatchedOperandsBetweenUses)(useA,useB,pass,1,1), useAPrecheck == 0)))) {
    return;
  }
  sourceDef = IRInst__getOperandSource(*useA,useA[1]);
  ((int (*)())Inst__reassociate_14e6e4)(sourceDef,pass);
  return;
}

/* Inst__findReassociatePair @ 0x1507d0 (964 bytes) */
int Inst__findReassociatePair(useA, foundUse, program)
  int *useA;
  int *foundUse;
  int program;
{
  int swapMatchedResultB;
  int foundIsPlainSingleUseB;
  int hasNoUsesResult;
  int useAIsPlainSingleUse;
  int swapMatchedResult;
  int foundIsPlainSingleUse;
  int canCombine;
  int operandSource;
  bool moreComponents;
  int inst;
  int hasSingleUse;
  int loopIndex2;
  bool useAIsPlain;
  bool moreComponentsB;
  undefined4 operandVReg;
  int consumerKind;
  uint vectorFilledCount2;
  int *elementPtr;
  int producerOfUse;
  undefined4 operandVReg2;
  int swapSharedResult;
  int programAlias;
  undefined4 staleArg4;
  undefined4 staleArg5;
  undefined4 staleArg6;
  uint vectorFilledCount;
  int termOffsetB;
  int term;
  uint loopIndex;
  int termOffset;
  uint *vector;
  int consumerDesc;
  int termSources [6];
  
  *foundUse = 0;
  termOffset = 0;
  programAlias = program;
  termSources[0] = IRInst__getOperandSource(*useA,3 - useA[1]);
  loopIndex2 = 0;
  operandVReg = IRInst__getOperandSource(*useA,useA[1]);
  termSources[1] = IRInst__getOperandSource(operandVReg,1);
  operandVReg = IRInst__getOperandSource(*useA,useA[1]);
  termSources[2] = IRInst__getOperandSource(operandVReg,2);
  do {
    hasSingleUse = IRInst__hasSingleUse(*(undefined4 *)((int)termSources + termOffset),program);
    if (hasSingleUse == 0) {
      loopIndex2 = loopIndex2 + 1;
    }
    moreComponents = termOffset != 8;
    termOffset = termOffset + 4;
  } while (moreComponents);
  if (1 < loopIndex2) {
    termOffsetB = 0;
    consumerDesc = *(int *)(*useA + 0x88);
    consumerKind = *(int *)(consumerDesc + 8);
    useAIsPlainSingleUse = ((int (*)())Use__sourceIsPlainSingleUse)(useA,program,programAlias,staleArg4,staleArg5,staleArg6,consumerDesc);
    useAIsPlain = useAIsPlainSingleUse != 0;
    do {
      term = *(int *)((int)termSources + termOffsetB);
      hasNoUsesResult = IRInst__hasNoUses(term,program,programAlias,staleArg4,staleArg5,staleArg6,consumerDesc);
      if ((hasNoUsesResult == 0) && (hasNoUsesResult = IRInst__hasSingleUse(term,program), hasNoUsesResult == 0)) {
        vector = *(uint **)(term + 0x10);
        loopIndex = 0;
        vectorFilledCount = vector[1];
        if (0 < (int)vectorFilledCount) {
          while( true ) {
            if (loopIndex < *vector) {
              vectorFilledCount2 = vector[1];
              if (vectorFilledCount2 <= loopIndex) {
                programAlias = (loopIndex - vectorFilledCount2) * 4 + 4;
                _memset(vectorFilledCount2 * 4 + vector[2],0,programAlias);
                vector[1] = loopIndex + 1;
              }
              elementPtr = (int *)(loopIndex * 4 + vector[2]);
            }
            else {
              elementPtr = (int *)Vector__elementRefGrow(vector,loopIndex);
            }
            inst = *elementPtr;
            if (((consumerKind == *(int *)(*(int *)(inst + 0x88) + 8)) && (inst != *useA)) &&
               (producerOfUse = IRInst__getOperandSource(*useA,useA[1]), inst != producerOfUse)) {
              operandSource = IRInst__getOperandSource(inst,1);
              if ((term == operandSource) &&
                 (operandSource = IRInst__getOperandSource(inst,2), consumerKind == *(int *)(*(int *)(operandSource + 0x88) + 8))) {
                operandVReg = IRInst__getOperandSource(inst,1);
                operandVReg2 = IRInst__getOperandSource(inst,2);
                programAlias = program;
                canCombine = Inst__noBarrierBetween(operandVReg,operandVReg2,program);
                if (canCombine != 0) {
                  *foundUse = inst;
                  foundUse[1] = 2;
                  foundIsPlainSingleUse = ((int (*)())Use__sourceIsPlainSingleUse)(foundUse,program,programAlias,staleArg4,staleArg5,staleArg6,consumerDesc);
                  if (useAIsPlain) {
                    staleArg4 = 0;
                    staleArg5 = 0;
                    programAlias = program;
                    swapSharedResult = ((int (*)())Inst__swapSharedTermBetweenUses)(foundUse,useA,program,0,0);
                    if (swapSharedResult != 0) {
                      return;
                    }
                  }
                  if (foundIsPlainSingleUse != 0) {
                    staleArg4 = 0;
                    staleArg5 = 0;
                    programAlias = program;
                    swapSharedResult = ((int (*)())Inst__swapSharedTermBetweenUses)(useA,foundUse,program,0,0);
                    if (swapSharedResult != 0) {
                      return;
                    }
                  }
                  if ((useAIsPlain) && (foundIsPlainSingleUse != 0)) {
                    staleArg4 = 0;
                    staleArg5 = 0;
                    programAlias = program;
                    swapMatchedResult = ((int (*)())Inst__swapMatchedOperandsBetweenUses)(useA,foundUse,program,0,0);
                    if (swapMatchedResult != 0) {
                      return;
                    }
                  }
                }
              }
              producerOfUse = IRInst__getOperandSource(inst,2);
              if ((term == producerOfUse) &&
                 (producerOfUse = IRInst__getOperandSource(inst,1), consumerKind == *(int *)(*(int *)(producerOfUse + 0x88) + 8))) {
                operandVReg = IRInst__getOperandSource(inst,2);
                operandVReg2 = IRInst__getOperandSource(inst,1);
                programAlias = program;
                producerOfUse = Inst__noBarrierBetween(operandVReg,operandVReg2,program);
                if (producerOfUse != 0) {
                  *foundUse = inst;
                  foundUse[1] = 1;
                  foundIsPlainSingleUseB = ((int (*)())Use__sourceIsPlainSingleUse)(foundUse,program,programAlias,staleArg4,staleArg5,staleArg6,consumerDesc);
                  if (useAIsPlain) {
                    staleArg4 = 0;
                    staleArg5 = 0;
                    programAlias = program;
                    producerOfUse = ((int (*)())Inst__swapSharedTermBetweenUses)(foundUse,useA,program,0,0);
                    if (producerOfUse != 0) {
                      return;
                    }
                  }
                  if (foundIsPlainSingleUseB != 0) {
                    staleArg4 = 0;
                    staleArg5 = 0;
                    programAlias = program;
                    producerOfUse = ((int (*)())Inst__swapSharedTermBetweenUses)(useA,foundUse,program,0,0);
                    if (producerOfUse != 0) {
                      return;
                    }
                  }
                  if ((useAIsPlain) && (foundIsPlainSingleUseB != 0)) {
                    staleArg4 = 0;
                    staleArg5 = 0;
                    programAlias = program;
                    swapMatchedResultB = ((int (*)())Inst__swapMatchedOperandsBetweenUses)(useA,foundUse,program,0,0);
                    if (swapMatchedResultB != 0) {
                      return;
                    }
                  }
                }
              }
            }
            loopIndex = loopIndex + 1;
            if (vectorFilledCount == loopIndex) break;
            vector = *(uint **)(term + 0x10);
          }
        }
      }
      moreComponentsB = termOffsetB != 8;
      termOffsetB = termOffsetB + 4;
    } while (moreComponentsB);
    *foundUse = 0;
  }
  return;
}

/* Inst__reassociate_150b94 @ 0x150b94 (420 bytes) */
int Inst__reassociate_150b94(inst, pass)
  int inst;
  int pass;
{
  int operandSource;
  bool firstOperandReassociated;
  bool secondOperandReassociated;
  int instOpcode;
  int instOpcodeB;
  int reassociateRecord [6];
  
  reassociateRecord[1] = 0;
  reassociateRecord[0] = 0;
  instOpcode = *(int *)(*(int *)(inst + 0x88) + 8);
  if (instOpcode == 0x12) {
    operandSource = IRInst__getOperandSource(inst,1);
    if (*(int *)(*(int *)(operandSource + 0x88) + 8) == 0x12) {
loopStoreReassociateRecord:
      reassociateRecord[1] = 1;
      reassociateRecord[0] = inst;
    }
  }
  else if ((instOpcode == 0x13) &&
          (instOpcode = IRInst__getOperandSource(inst,1), *(int *)(*(int *)(instOpcode + 0x88) + 8) == 0x13))
  goto loopStoreReassociateRecord;
  reassociateRecord[3] = 0;
  reassociateRecord[2] = 0;
  if (reassociateRecord[0] != 0) {
    ((int (*)())Inst__findReassociatePair)(reassociateRecord,reassociateRecord + 2,pass);
  }
  firstOperandReassociated = reassociateRecord[2] != 0;
  if (firstOperandReassociated) {
    *(int *)(pass + 0x1f8) = *(int *)(pass + 0x1f8) + 1;
    ((int (*)())Inst__reassociateUsePair)(reassociateRecord + 2,reassociateRecord,pass);
  }
  reassociateRecord[0] = 0;
  instOpcodeB = *(int *)(*(int *)(inst + 0x88) + 8);
  if (instOpcodeB == 0x12) {
    operandSource = IRInst__getOperandSource(inst,2);
    if (*(int *)(*(int *)(operandSource + 0x88) + 8) != 0x12) goto checkReassociateRecord;
  }
  else if ((instOpcodeB != 0x13) ||
          (instOpcodeB = IRInst__getOperandSource(inst,2), *(int *)(*(int *)(instOpcodeB + 0x88) + 8) != 0x13))
  goto checkReassociateRecord;
  reassociateRecord[1] = 2;
  reassociateRecord[0] = inst;
checkReassociateRecord:
  if (reassociateRecord[0] == 0) {
    reassociateRecord[2] = reassociateRecord[0];
  }
  else {
    ((int (*)())Inst__findReassociatePair)(reassociateRecord,reassociateRecord + 2,pass);
  }
  secondOperandReassociated = reassociateRecord[2] != 0;
  if (secondOperandReassociated) {
    *(int *)(pass + 0x1f8) = *(int *)(pass + 0x1f8) + 1;
    ((int (*)())Inst__reassociateUsePair)(reassociateRecord + 2,reassociateRecord,pass);
  }
  return secondOperandReassociated || firstOperandReassociated;
}

/* Inst__collapseAddOfScaledMov @ 0x150d38 (1504 bytes) */
int Inst__collapseAddOfScaledMov(inst, program)
  int inst;
  int program;
{
  int src3Set;
  int isPresub;
  int lanesLeft2;
  int destLane;
  undefined4 src2SelectFinal;
  undefined4 src2Select;
  undefined4 src1Select;
  int depthBase;
  int lane;
  int lanesLeft;
  int src2Set;
  int src1Record;
  int otherRecord;
  int scaledOperandRecord;
  int movSourceRecord;
  int scaleConstant;
  uint yAbs;
  int cloneResult;
  int operandRecord4;
  int operandRecord2;
  int sourceDef;
  int operandRecord3;
  int operandRecord;
  bool moreSources;
  uint yNegate;
  uint otherOperandFlags;
  uint instFlags;
  int *a0;
  int isMov;
  int destRecord;
  int *operandVReg;
  void *inst2;
  int depthBasePlusOne;
  undefined4 destSelect;
  undefined4 otherSelect;
  int srcIndex;
  uint *flagsPtr;
  int compiler;
  undefined4 destRegisterOffset;
  undefined4 movSelect;
  int otherIndex;
  double scaleFactor;
  undefined4 destSelectWord;
  undefined4 scaleSelect;
  undefined4 scaleDestSelect;
  undefined4 scaleSelectCopy;
  float scaleLane0;
  float scaleLane1;
  float scaleLane2;
  float scaleLane3;
  undefined4 destWriteMask;
  undefined4 unusedMaskedSelect;
  undefined4 composedSelect;
  int extraSource;
  undefined4 otherSource;
  undefined4 scaledAbs;
  uint scaledNegate;
  undefined4 saturate;
  int useCount;
  int prevNode;
  
  compiler = *(int *)(program + 8);
  if (((inst != 0) && (*(int *)(*(int *)(inst + 0x88) + 8) == 0x12)) &&
     (*(int *)(inst + 0x124) == 0)) {
    srcIndex = 1;
    flagsPtr = (uint *)(inst + 0xb8);
    do {
      a0 = (int *)IRInst__getOperandSource(inst,srcIndex);
      isMov = (**(code **)(*a0 + 100))(a0);
      if (((isMov != 0) && (a0[0x48] == 0)) && (((a0[5] & 0x200U) == 0 && (a0[0x49] != 0)))) {
        scaleFactor = (double)((double (*)())outputScaleFromExponent)(a0[0x49]);
        scaleLane3 = (float)scaleFactor;
        scaleLane0 = (float)scaleFactor;
        scaleLane1 = (float)scaleFactor;
        scaleLane2 = (float)scaleFactor;
        operandRecord2 = IRInst__getOperandRecord(inst,0);
        destSelectWord = *(undefined4 *)(operandRecord2 + 0x10);
        operandRecord2 = IRInst__getOperandRecord(inst,0);
        WriteMask__fromSelectWord(&destWriteMask,*(undefined4 *)(operandRecord2 + 0x10));
        SelectWord__maskUnused(&unusedMaskedSelect,0x10203,destWriteMask);
        scaleSelect = unusedMaskedSelect;
        scaleConstant = (**(code **)(**(int **)(compiler + 0x30c) + 0x154))
                          (*(int **)(compiler + 0x30c),program,&scaleLane0,&scaleSelect);
        if (scaleConstant != 0) {
          prevNode = *(int *)(inst + 4);
          useCount = IRInst__useCount(inst,program);
          saturate = *(undefined4 *)(inst + 0x120);
          destRecord = IRInst__getOperandRecord(inst,0);
          destSelect = *(undefined4 *)(destRecord + 0x10);
          operandVReg = (int *)IRInst__getOperandSource(a0,1);
          movSourceRecord = IRInst__getOperandRecord(a0,1);
          movSelect = *(undefined4 *)(movSourceRecord + 0x10);
          scaledOperandRecord = IRInst__getOperandRecord(inst,srcIndex);
          SelectWord__compose(&composedSelect,movSelect,*(undefined4 *)(scaledOperandRecord + 0x10));
          src1Select = composedSelect;
          scaledNegate = (*flagsPtr ^ a0[0x2e]) & 1;
          if (((a0[0x2e] & 2U) != 0) || (scaledAbs = 0, (*flagsPtr & 2) != 0)) {
            scaledAbs = 1;
          }
          otherIndex = 2 - (uint)(srcIndex == 2);
          otherSource = IRInst__getOperandSource(inst,otherIndex);
          otherRecord = IRInst__getOperandRecord(inst,otherIndex);
          instFlags = *(uint *)(inst + 0x14);
          otherSelect = *(undefined4 *)(otherRecord + 0x10);
          otherOperandFlags = *(uint *)(otherIndex * 0x18 + inst + 0xa0);
          extraSource = 0;
          yNegate = otherOperandFlags & 1;
          yAbs = otherOperandFlags >> 1 & 1;
          if ((instFlags & 0x200) != 0) {
            extraSource = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
            instFlags = *(uint *)(inst + 0x14);
          }
          destRegisterOffset = *(undefined4 *)(inst + 0x98);
          inst2 = IRInst__create(0x14,*(undefined4 *)(program + 8));
          *(undefined4 *)((int)inst2 + 0x98) = destRegisterOffset;
          *(undefined4 *)((int)inst2 + 0x94) = *(undefined4 *)((int)inst2 + 0x14c);
          if ((instFlags & 2) != 0) {
            *(uint *)((int)inst2 + 0x14) = *(uint *)((int)inst2 + 0x14) | 2;
          }
          *(undefined4 *)((int)inst2 + 0xc) = *(undefined4 *)(inst + 0xc);
          *(undefined4 *)((int)inst2 + 0x120) = saturate;
          *(undefined4 *)((int)inst2 + 0x9c) = destSelect;
          IRInst__setOperandSource(inst2,1,operandVReg,0,compiler);
          src1Record = IRInst__getOperandRecord(inst2,1);
          *(undefined4 *)(src1Record + 0x10) = src1Select;
          IROperand__setModifierBits((int)inst2 + 0xa4,1,scaledNegate);
          IROperand__setModifierBits((int)inst2 + 0xa4,2,scaledAbs);
          src2Set = IRInst__setOperandSourceIfLegal(inst2,2,scaleConstant,0,0,compiler);
          src2Select = scaleSelect;
          operandRecord3 = IRInst__getOperandRecord(inst2,2);
          *(undefined4 *)(operandRecord3 + 0x10) = src2Select;
          IRInst__setOperandSource(inst2,2,scaleConstant,0,compiler);
          src3Set = IRInst__setOperandSourceIfLegal(inst2,3,otherSource,yAbs,yNegate,compiler);
          operandRecord4 = IRInst__getOperandRecord(inst2,3);
          *(undefined4 *)(operandRecord4 + 0x10) = otherSelect;
          IROperand__setModifierBits((int)inst2 + 0xd4,1,yNegate);
          IROperand__setModifierBits((int)inst2 + 0xd4,2,yAbs);
          if (extraSource != 0) {
            IRInst__setExtraOperandSource(inst2,extraSource,0,compiler);
          }
          *(int *)((int)inst2 + 0x160) = useCount + *(int *)(program + 0x478);
          if (src3Set != 0 && src2Set != 0) {
            destLane = 0;
            lanesLeft = 4;
            do {
              if (*(char *)((int)&destSelectWord + destLane) == '\x01') {
                *(undefined1 *)(destLane + (int)&scaleSelect) = 4;
              }
              src2SelectFinal = scaleSelect;
              destLane = destLane + 1;
              lanesLeft = lanesLeft + -1;
            } while (lanesLeft != 0);
            operandRecord = IRInst__getOperandRecord(inst2,2);
            *(undefined4 *)(operandRecord + 0x10) = src2SelectFinal;
            operandRecord = IRInst__getOperandRecord(scaleConstant,0);
            lane = 0;
            scaleSelectCopy = scaleSelect;
            scaleDestSelect = *(undefined4 *)(operandRecord + 0x10);
            lanesLeft2 = 4;
            do {
              if (*(byte *)((int)&scaleSelectCopy + lane) != 4) {
                *(undefined1 *)((int)&scaleDestSelect + (uint)*(byte *)((int)&scaleSelectCopy + lane)) = 0;
              }
              lane = lane + 1;
              lanesLeft2 = lanesLeft2 + -1;
            } while (lanesLeft2 != 0);
            *(undefined4 *)(scaleConstant + 0x9c) = scaleDestSelect;
            depthBase = *(int *)(program + 0x478);
            isPresub = (**(code **)(*operandVReg + 0x5c))(operandVReg);
            if ((isPresub == 0) || (isPresub = IRInst__hasSingleUse(a0,program), isPresub != 0)) {
              if (depthBase < operandVReg[0x58]) {
                operandVReg[0x58] = operandVReg[0x58] + 1;
              }
              else {
                operandVReg[0x58] = depthBase + 1;
              }
            }
            else {
              depthBasePlusOne = depthBase + 1;
              cloneResult = IRInst__clone(operandVReg,*(undefined4 *)(program + 8),0);
              *(undefined4 *)(cloneResult + 0x98) = 0x31;
              *(undefined4 *)(cloneResult + 0x94) = *(undefined4 *)(cloneResult + 0x14c);
              Block__insertInstAfter(operandVReg[0x56],operandVReg,cloneResult);
              *(int *)(cloneResult + 0x160) = depthBasePlusOne;
              sourceDef = IRInst__getOperandSource(cloneResult,1);
              if (depthBase < *(int *)(sourceDef + 0x160)) {
                *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
              }
              else {
                *(int *)(sourceDef + 0x160) = depthBasePlusOne;
              }
              if (1 < *(int *)(cloneResult + 0x84)) {
                sourceDef = IRInst__getOperandSource(cloneResult,2);
                if (depthBase < *(int *)(sourceDef + 0x160)) {
                  *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
                }
                else {
                  *(int *)(sourceDef + 0x160) = depthBasePlusOne;
                }
              }
              IRInst__setOperandSource(inst2,1,cloneResult,0,compiler);
            }
            if (depthBase < *(int *)(scaleConstant + 0x160)) {
              *(int *)(scaleConstant + 0x160) = *(int *)(scaleConstant + 0x160) + 1;
            }
            else {
              *(int *)(scaleConstant + 0x160) = depthBase + 1;
            }
            DList__unlink(inst);
            _memcpy(inst,inst2,0x164);
            Block__insertInstAfter(*(undefined4 *)(prevNode + 0x158),prevNode,inst);
            IRInst__dropCounterAndDeleteIfUnused(a0,*(undefined4 *)(program + 8));
            return 1;
          }
        }
      }
      moreSources = srcIndex != 2;
      flagsPtr = flagsPtr + 6;
      srcIndex = srcIndex + 1;
    } while (moreSources);
  }
  return 0;
}

/* Inst__sourceOneMatchesConstant @ 0x151318 (88 bytes) */
int Inst__sourceOneMatchesConstant(inst)
  undefined4 inst;
{
  int operandRecord;
  undefined4 callResult;
  undefined4 constantX;
  undefined4 constantY;
  undefined4 constantZ;
  undefined4 constantW;
  
  constantW = 0;
  constantX = 0;
  constantY = 0;
  constantZ = 0;
  operandRecord = IRInst__getOperandRecord(inst,0);
  callResult = IRInst__sourceMatchesConstant(inst,1,*(undefined4 *)(operandRecord + 0x10),&constantX);
  return callResult;
}

/* Inst__mergeSplatSourceInsts_00151370 @ 0x151370 (1340 bytes) */
int Inst__mergeSplatSourceInsts_00151370(inst, inst2, program)
  int *inst;
  int *inst2;
  int program;
{
  int checkIndex;
  int vcall5cResult;
  int vcall60Result;
  int vcall64Result;
  int loopIndex;
  int countdown;
  int resultScaleCode;
  int saturate;
  int afterInst;
  undefined4 sourceDef3;
  undefined4 operandRecord2;
  undefined4 sourceDef;
  int sourceDef4;
  int operandRecord;
  int sourceDef2;
  int *operandVReg;
  undefined1 componentByte;
  uint source1Flags;
  uint source1Flags2;
  int predicateResult;
  undefined4 selectWordToStore;
  undefined4 selectWordToStoreB;
  int countdownB;
  undefined4 newSrcA;
  undefined4 newSrcB;
  int *inst1;
  int *newSource;
  undefined4 operandSelectC;
  undefined4 destSelectInst2;
  int mergedLanes;
  undefined4 operandSelectB;
  undefined4 operandSelect;
  undefined4 newSrcAMask;
  undefined4 newSrcBMask;
  undefined4 newSrcAOperand1Select;
  undefined4 newSrcAOperand2Select;
  undefined4 newSrcBOperand1Select;
  undefined4 newSrcBOperand2Select;
  undefined4 instOperand1Select;
  undefined4 instOperand2Select;
  undefined4 counterSave0;
  undefined4 counterSave1;
  undefined4 counterSave2;
  undefined4 lastOperandRecord;
  int lastOperandSource;
  undefined4 lastOperandTail;
  undefined4 operandCopy;
  undefined4 operandCopyWord1;
  undefined4 operandCopyWord5;
  undefined4 readSelectOut;
  int selectWhereOut;
  int mergedLanesOut [5];
  
  vcall64Result = (**(code **)(*inst + 100))(inst,inst2,program);
  if ((vcall64Result != 0) && (vcall64Result = (**(code **)(*inst2 + 100))(inst2), vcall64Result != 0)) {
    sourceDef = IRInst__getOperandSource(inst,1);
    sourceDef3 = IRInst__getOperandSource(inst2,1);
    predicateResult = ((int (*)())Inst__opcodeOrSourcesDiffer)(sourceDef,sourceDef3);
    if (predicateResult == 0) {
      sourceDef2 = IRInst__getOperandSource(inst,1);
      sourceDef4 = IRInst__getOperandSource(inst2,1);
      if (((sourceDef2 != sourceDef4) && (inst2[0x48] == inst[0x48])) && (inst[0x49] == inst2[0x49])
         ) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        operandSelectC = *(undefined4 *)(operandRecord + 0x10);
        operandRecord = IRInst__getOperandRecord(inst,inst[0x21]);
        WriteMask__fromUsedLanes(&readSelectOut,*(undefined4 *)(operandRecord + 0x10));
        destSelectInst2 = readSelectOut;
        operandRecord = IRInst__getOperandRecord(inst2,0);
        SelectWord__markLanesWhereSecondIsOne(&selectWhereOut,readSelectOut,*(undefined4 *)(operandRecord + 0x10));
        checkIndex = 0;
        destSelectInst2 = selectWhereOut;
        countdownB = 4;
        do {
          if ((*(char *)((int)&operandSelectC + checkIndex) != '\x01') &&
             (*(char *)((int)&destSelectInst2 + checkIndex) != '\x01')) {
            return 0;
          }
          checkIndex = checkIndex + 1;
          countdownB = countdownB + -1;
        } while (countdownB != 0);
        if ((selectWhereOut != 0x1010101) &&
           ((checkIndex = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x30), checkIndex == 0 ||
            (((char)operandSelectC != '\0' && ((char)destSelectInst2 != '\0')))))) {
          SelectWord__mergeWrittenLanes(mergedLanesOut,destSelectInst2,operandSelectC);
          mergedLanes = mergedLanesOut[0];
          operandRecord = IRInst__getOperandRecord(inst,1);
          operandSelectB = *(undefined4 *)(operandRecord + 0x10);
          operandRecord = IRInst__getOperandRecord(inst2,1);
          loopIndex = 0;
          operandSelect = *(undefined4 *)(operandRecord + 0x10);
          newSrcBMask = 0x1010101;
          instOperand2Select = 0x4040404;
          countdown = 4;
          newSrcAMask = 0x1010101;
          newSrcAOperand1Select = 0x4040404;
          newSrcAOperand2Select = 0x4040404;
          newSrcBOperand1Select = 0x4040404;
          newSrcBOperand2Select = 0x4040404;
          instOperand1Select = 0x4040404;
          do {
            if (*(char *)((int)&mergedLanes + loopIndex) == '\0') {
              componentByte = (undefined1)loopIndex;
              if (*(char *)((int)&operandSelectC + loopIndex) == '\0') {
                *(undefined1 *)((int)&newSrcAOperand1Select + loopIndex) = *(undefined1 *)((int)&operandSelectB + loopIndex);
                *(undefined1 *)((int)&newSrcBOperand2Select + loopIndex) = componentByte;
              }
              else if (*(char *)((int)&destSelectInst2 + loopIndex) == '\0') {
                *(undefined1 *)((int)&newSrcBOperand1Select + loopIndex) = *(undefined1 *)((int)&operandSelect + loopIndex);
                *(undefined1 *)((int)&newSrcAOperand2Select + loopIndex) = componentByte;
              }
              *(undefined1 *)((int)&newSrcBMask + loopIndex) = 0;
              *(undefined1 *)((int)&instOperand2Select + loopIndex) = componentByte;
              *(undefined1 *)((int)&newSrcAMask + loopIndex) = 0;
              *(undefined1 *)((int)&instOperand1Select + loopIndex) = componentByte;
            }
            selectWordToStore = newSrcAMask;
            loopIndex = loopIndex + 1;
            countdown = countdown + -1;
          } while (countdown != 0);
          sourceDef3 = IRInst__getOperandSource(inst,1);
          newSrcA = ((int (*)())IRInst__createWithConstantOperands)(2,selectWordToStore,sourceDef3,program,*(undefined4 *)(program + 8),0.0);
          selectWordToStore = newSrcBMask;
          sourceDef3 = IRInst__getOperandSource(inst2,1);
          newSrcB = ((int (*)())IRInst__createWithConstantOperands)(2,selectWordToStore,sourceDef3,program,*(undefined4 *)(program + 8),0.0);
          selectWordToStore = newSrcAOperand1Select;
          operandRecord = IRInst__getOperandRecord(newSrcA,1);
          selectWordToStoreB = newSrcAOperand2Select;
          *(undefined4 *)(operandRecord + 0x10) = selectWordToStore;
          operandRecord = IRInst__getOperandRecord(newSrcA,2);
          selectWordToStore = newSrcBOperand1Select;
          *(undefined4 *)(operandRecord + 0x10) = selectWordToStoreB;
          operandRecord = IRInst__getOperandRecord(newSrcB,1);
          selectWordToStoreB = newSrcBOperand2Select;
          *(undefined4 *)(operandRecord + 0x10) = selectWordToStore;
          operandRecord = IRInst__getOperandRecord(newSrcB,2);
          source1Flags2 = inst2[0x2e];
          *(undefined4 *)(operandRecord + 0x10) = selectWordToStoreB;
          lastOperandRecord = 0;
          lastOperandSource = 0;
          lastOperandTail = 0;
          if ((inst2[5] & 0x200U) != 0) {
            IRInst__readLastOperand(inst2,&lastOperandRecord);
          }
          source1Flags = inst[0x2e];
          operandCopy = 0;
          operandCopyWord1 = 0;
          operandCopyWord5 = 0;
          resultScaleCode = inst[0x49];
          operandRecord2 = IRInst__getOperandRecord(inst,1);
          IROperand__copyFrom(&operandCopy,operandRecord2);
          counterSave0 = 0;
          counterSave1 = 0;
          counterSave2 = 0;
          IRInst__saveCounters(inst,&counterSave0,0xffffffff);
          afterInst = inst[1];
          DList__unlink(inst);
          IRInst__reinitAsBinary(inst,0x12,*(undefined4 *)(program + 8));
          Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,inst);
          IRInst__restoreCounters(inst,&counterSave0);
          saturate = inst2[0x48];
          inst[0x49] = resultScaleCode;
          inst[0x48] = saturate;
          operandRecord2 = IRInst__getOperandRecord(inst,1);
          IROperand__copyFrom(operandRecord2,&operandCopy);
          IRInst__copyOperandFrom(inst,2,inst2,1);
          inst[0x27] = mergedLanes;
          inst[0x25] = inst[0x53];
          inst[0x26] = 0;
          IRInst__setOperandSource(inst,1,newSrcA,0,*(undefined4 *)(program + 8));
          IROperand__setModifierBits(inst + 0x29,1,source1Flags & 1);
          IROperand__setModifierBits(inst + 0x29,2,source1Flags >> 1 & 1);
          selectWordToStore = instOperand1Select;
          operandRecord = IRInst__getOperandRecord(inst,1);
          *(undefined4 *)(operandRecord + 0x10) = selectWordToStore;
          IRInst__setOperandSource(inst,2,newSrcB,0,*(undefined4 *)(program + 8));
          IROperand__setModifierBits(inst + 0x2f,1,source1Flags2 & 1);
          IROperand__setModifierBits(inst + 0x2f,2,source1Flags2 >> 1 & 1);
          selectWordToStore = instOperand2Select;
          operandRecord = IRInst__getOperandRecord(inst,2);
          *(undefined4 *)(operandRecord + 0x10) = selectWordToStore;
          Block__insertInstBefore(inst[0x56],inst,newSrcB);
          Block__insertInstBefore(inst[0x56],inst,newSrcA);
          if (lastOperandSource != 0) {
            IRInst__setLastOperandFromRecord(inst,&lastOperandRecord,0,*(undefined4 *)(program + 8));
            if (*(int *)(program + 0x478) < *(int *)(lastOperandSource + 0x160)) {
              *(int *)(lastOperandSource + 0x160) = *(int *)(lastOperandSource + 0x160) + 1;
            }
            else {
              *(int *)(lastOperandSource + 0x160) = *(int *)(program + 0x478) + 1;
            }
          }
          vcall60Result = (**(code **)(*inst2 + 0x60))(inst2);
          inst1 = inst2;
          if (vcall60Result != 0) {
            inst1 = (int *)IRInst__getOperandSource(inst2,1);
          }
          sourceDef = IRInst__getOperandSource(inst1,1);
          newSource = (int *)IRInst__cloneIfPresub(sourceDef,program,0);
          vcall5cResult = (**(code **)(*newSource + 0x5c))();
          if (vcall5cResult == 0) {
            sourceDef2 = IRInst__getOperandSource(inst2,1);
            if (*(int *)(program + 0x478) < *(int *)(sourceDef2 + 0x160)) {
              *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
            }
            else {
              *(int *)(sourceDef2 + 0x160) = *(int *)(program + 0x478) + 1;
            }
          }
          else {
            IRInst__setOperandSource(inst1,1,newSource,0,*(undefined4 *)(program + 8));
            if (*(int *)(program + 0x478) < newSource[0x58]) {
              newSource[0x58] = newSource[0x58] + 1;
            }
            else {
              newSource[0x58] = *(int *)(program + 0x478) + 1;
            }
          }
          operandVReg = (int *)IRInst__getOperandSource(newSrcA,1);
          vcall60Result = (**(code **)(*operandVReg + 0x60))();
          if (vcall60Result != 0) {
            sourceDef = IRInst__getOperandSource(newSrcA,1);
            IRInst__foldConstantSourcesIntoClone(sourceDef,newSrcA,*(undefined4 *)(program + 8));
          }
          operandVReg = (int *)IRInst__getOperandSource(newSrcB,1);
          vcall60Result = (**(code **)(*operandVReg + 0x60))();
          if (vcall60Result != 0) {
            sourceDef = IRInst__getOperandSource(newSrcB,1);
            IRInst__foldConstantSourcesIntoClone(sourceDef,newSrcB,*(undefined4 *)(program + 8));
          }
          IRInst__dropCounterAndDeleteIfUnused(inst2,*(undefined4 *)(program + 8));
          return 1;
        }
      }
    }
  }
  return 0;
}

/* Inst__mergeSplatSourceInsts_00151a74 @ 0x151a74 (1896 bytes) */
int Inst__mergeSplatSourceInsts_00151a74(inst, inst2, program)
  int *inst;
  int *inst2;
  int program;
{
  uint remapB2;
  int mergedLanesCopy;
  int predicateResult;
  int splatComponentResult;
  int vcall5cResult;
  int vcall60Result;
  int vcall64Result;
  int loopIndexB;
  int loopIndex2;
  bool moreComponents;
  int *inst4;
  int *newSource;
  int afterInst;
  int splitRgbAlphaEnabled;
  undefined4 operandRecord3;
  undefined4 sourceDef;
  int operandRecord4;
  int sourceDef3;
  int operandRecord2;
  int sourceDef2;
  int *operandVReg;
  bool noThirdInst;
  int operandSelectWord;
  undefined4 compiler;
  undefined4 operandVReg2;
  int checkCountdown;
  int splatComponentResultB;
  uint callResult;
  int operandRecord;
  int *newSrcB;
  int *a0;
  int *newSrcC;
  int *inst3;
  uint srcAComponent;
  uint srcBComponent;
  undefined4 staleArg5;
  uint remapA1;
  uint remapA2;
  uint remapB1;
  uint loopIndex;
  undefined4 operandSelectD;
  undefined4 operandSelectC;
  undefined4 operandSelectB;
  undefined4 operandSelect;
  int mergedLanes;
  int newSrcAMask;
  int scratchFrame [5];
  int *inst1;
  undefined4 lastOperandTail;
  undefined4 operandCopy;
  undefined4 operandCopyWord1;
  undefined4 operandCopyWord5;
  int mergedLanesOut;
  undefined1 equalLanesOut [4];
  int mergeWrittenLanesOut [6];
  
  vcall64Result = (**(code **)(*inst + 100))(inst,inst2,program);
  if ((vcall64Result != 0) && (vcall64Result = (**(code **)(*inst2 + 100))(inst2), vcall64Result != 0)) {
    sourceDef = IRInst__getOperandSource(inst,1);
    operandVReg2 = IRInst__getOperandSource(inst2,1);
    predicateResult = ((int (*)())Inst__opcodeOrSourcesDiffer)(sourceDef,operandVReg2);
    if (predicateResult == 0) {
      sourceDef2 = IRInst__getOperandSource(inst,1);
      sourceDef3 = IRInst__getOperandSource(inst2,1);
      if (sourceDef2 != sourceDef3) {
        operandRecord2 = IRInst__getOperandRecord(inst,0);
        operandSelectD = *(undefined4 *)(operandRecord2 + 0x10);
        operandRecord4 = IRInst__getOperandRecord(inst2,0);
        loopIndex2 = 0;
        operandSelectC = *(undefined4 *)(operandRecord4 + 0x10);
        checkCountdown = 4;
        do {
          if ((*(char *)((int)&operandSelectD + loopIndex2) != '\x01') &&
             (*(char *)((int)&operandSelectC + loopIndex2) != '\x01')) {
            return 0;
          }
          loopIndex2 = loopIndex2 + 1;
          checkCountdown = checkCountdown + -1;
        } while (checkCountdown != 0);
        splitRgbAlphaEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x30);
        if ((splitRgbAlphaEnabled == 0) || (((char)operandSelectD != '\0' && ((char)operandSelectC != '\0')))) {
          operandRecord2 = IRInst__getOperandRecord(inst,1);
          operandSelectB = *(undefined4 *)(operandRecord2 + 0x10);
          operandRecord2 = IRInst__getOperandRecord(inst2,1);
          operandSelect = *(undefined4 *)(operandRecord2 + 0x10);
          lastOperandTail = 0;
          scratchFrame[4] = 0;
          inst1 = (int *)0x0;
          if ((inst2[5] & 0x200U) != 0) {
            IRInst__readLastOperand(inst2,scratchFrame + 4);
          }
          inst3 = inst1;
          noThirdInst = inst1 == (int *)0x0;
          if (noThirdInst) {
            operandSelectWord = 0x1010101;
          }
          else {
            operandRecord2 = IRInst__getOperandRecord(inst1,0);
            operandSelectWord = *(int *)(operandRecord2 + 0x10);
          }
          if ((((!noThirdInst) && (inst[0x49] == 0)) &&
              ((checkCountdown = (**(code **)(*inst3 + 100))(inst3), checkCountdown != 0 ||
               (checkCountdown = IRInst__hasSingleUse(inst3,program), checkCountdown == 0)))) &&
             ((((operandSelectWord != 0x1010100 && ((inst3[5] & 0x200U) == 0)) &&
               (checkCountdown = SelectWord__isSingleComponentConstant(operandSelectWord), checkCountdown != 0)) &&
              ((checkCountdown = SelectWord__isSingleComponentConstant(operandSelectD), checkCountdown != 0 &&
               (checkCountdown = SelectWord__isSingleComponentConstant(operandSelectC), checkCountdown != 0)))))) {
            if ((((inst[0x2e] & 1U) == (inst2[0x2e] & 1U)) &&
                ((((uint)inst[0x2e] >> 1 & 1) == ((uint)inst2[0x2e] >> 1 & 1) &&
                 (inst2[0x48] == inst[0x48])))) && (inst[0x49] == inst2[0x49])) {
              splatComponentResult = SelectWord__splatComponent(operandSelectD);
              splatComponentResultB = SelectWord__splatComponent(operandSelectC);
              callResult = SelectWord__splatComponent(operandSelectWord);
              SelectWord__mergeWrittenLanes(&mergedLanesOut,operandSelectC,operandSelectD);
              mergedLanes = mergedLanesOut;
              operandRecord = IRInst__getOperandRecord(inst3,0);
              SelectWord__markEqualLanes(equalLanesOut,*(undefined4 *)(operandRecord + 0x10),mergedLanes);
              SelectWord__mergeWrittenLanes(mergeWrittenLanesOut,operandSelectWord,mergedLanes);
              mergedLanes = mergeWrittenLanesOut[0];
              sourceDef = IRInst__getOperandSource(inst2,1);
              newSrcB = (int *)((int (*)())IRInst__createWithConstantOperands)(3,mergeWrittenLanesOut[0],sourceDef,program,*(undefined4 *)(program + 8),
                                           1.0);
              mergedLanesCopy = mergedLanes;
              sourceDef = IRInst__getOperandSource(inst,1);
              a0 = (int *)((int (*)())IRInst__createWithConstantOperands)(3,mergedLanesCopy,sourceDef,program,*(undefined4 *)(program + 8),1.0);
              compiler = *(undefined4 *)(program + 8);
              newSrcC = (int *)((int (*)())IRInst__createWithConstantOperands)(2,mergedLanes,inst3,program,compiler,0.0);
              if (*(int *)(program + 0x478) < inst3[0x58]) {
                inst3[0x58] = inst3[0x58] + 1;
              }
              else {
                inst3[0x58] = *(int *)(program + 0x478) + 1;
              }
              srcAComponent = (uint)*(byte *)((int)&operandSelectB + splatComponentResult);
              newSrcAMask = 0x1010101;
              *(undefined1 *)((int)&newSrcAMask + srcAComponent) = 0;
              scratchFrame[0] = 0x1010101;
              remapA1 = 0xffffffff;
              remapA2 = 0xffffffff;
              remapB1 = 0xffffffff;
              (**(code **)(*a0 + 0x88))(a0,1,srcAComponent,srcAComponent,compiler,staleArg5,*(code **)(*a0 + 0x88));
              srcBComponent = (uint)*(byte *)((int)&operandSelect + splatComponentResultB);
              *(undefined1 *)((int)scratchFrame + srcBComponent) = 0;
              remapB2 = 0xffffffff;
              loopIndex = 0;
              (**(code **)(*newSrcB + 0x88))(newSrcB,1,srcBComponent,srcBComponent);
              (**(code **)(*newSrcC + 0x88))(newSrcC,1,callResult,callResult);
              (**(code **)(*newSrcC + 0x88))(newSrcC,2,splatComponentResult,splatComponentResult);
              (**(code **)(*newSrcC + 0x88))(newSrcC,2,splatComponentResultB,splatComponentResultB);
              do {
                operandRecord2 = IRInst__getOperandRecord(a0,1);
                if (loopIndex != *(byte *)(loopIndex + operandRecord2 + 0x10)) {
                  if (((int)remapA1 < 0) && (callResult != loopIndex)) {
                    (**(code **)(*a0 + 0x88))(a0,2,loopIndex,loopIndex);
                    *(undefined1 *)((int)&newSrcAMask + loopIndex) = 0;
                    remapA1 = loopIndex;
                  }
                  else if ((int)remapA2 < 0) {
                    (**(code **)(*a0 + 0x88))(a0,3,loopIndex,loopIndex);
                    *(undefined1 *)((int)&newSrcAMask + loopIndex) = 0;
                    remapA2 = loopIndex;
                  }
                }
                operandRecord2 = IRInst__getOperandRecord(newSrcB,1);
                if (loopIndex != *(byte *)(loopIndex + operandRecord2 + 0x10)) {
                  if (((int)remapB1 < 0) && (callResult != loopIndex)) {
                    (**(code **)(*newSrcB + 0x88))(newSrcB,2,loopIndex,loopIndex);
                    *(undefined1 *)((int)scratchFrame + loopIndex) = 0;
                    remapB1 = loopIndex;
                  }
                  else if ((int)remapB2 < 0) {
                    (**(code **)(*newSrcB + 0x88))(newSrcB,3,loopIndex,loopIndex);
                    *(undefined1 *)((int)scratchFrame + loopIndex) = 0;
                    remapB2 = loopIndex;
                  }
                }
                moreComponents = loopIndex != 3;
                loopIndex = loopIndex + 1;
              } while (moreComponents);
              a0[0x27] = newSrcAMask;
              operandCopy = 0;
              newSrcB[0x27] = scratchFrame[0];
              operandCopyWord1 = 0;
              operandCopyWord5 = 0;
              operandRecord3 = IRInst__getOperandRecord(inst,1);
              IROperand__copyFrom(&operandCopy,operandRecord3);
              scratchFrame[1] = 0;
              scratchFrame[2] = 0;
              scratchFrame[3] = 0;
              IRInst__saveCounters(inst,scratchFrame + 1,0xffffffff);
              afterInst = inst[1];
              DList__unlink(inst);
              IRInst__reinitAsTrinary(inst,0x14,*(undefined4 *)(program + 8));
              loopIndexB = 0;
              Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,inst);
              IRInst__restoreCounters(inst,scratchFrame + 1);
              inst[0x48] = inst2[0x48];
              inst[0x25] = inst[0x53];
              inst[0x27] = mergedLanes;
              inst[0x26] = 0;
              inst[0x49] = 0;
              operandRecord3 = IRInst__getOperandRecord(inst,1);
              IROperand__copyFrom(operandRecord3,&operandCopy);
              IRInst__setOperandSource(inst,1,a0,0,*(undefined4 *)(program + 8));
              IROperand__setModifierBits(inst + 0x29,1,inst2[0x2e] & 1);
              IRInst__copyOperandFrom(inst,2,inst2,1);
              IRInst__setOperandSource(inst,2,newSrcB,0,*(undefined4 *)(program + 8));
              IROperand__setModifierBits(inst + 0x2f,1,0);
              IRInst__setOperandSource(inst,3,newSrcC,0,*(undefined4 *)(program + 8));
              operandRecord2 = IRInst__getOperandRecord(inst,3);
              *(undefined4 *)(operandRecord2 + 0x10) = 0x10204;
              do {
                operandRecord2 = IRInst__getOperandRecord(inst,1);
                if (*(char *)(loopIndexB + operandRecord2 + 0x10) == '\x04') {
                  operandRecord2 = IRInst__getOperandRecord(inst,2);
                  if (*(char *)(loopIndexB + operandRecord2 + 0x10) == '\x04') {
                    if (*(char *)((int)&mergedLanes + loopIndexB) == '\0') {
                      (**(code **)(*inst + 0x88))(inst,1,loopIndexB,remapA2);
                    }
                  }
                  else {
                    (**(code **)(*inst + 0x88))(inst,1,loopIndexB,remapA1);
                  }
                }
                operandRecord2 = IRInst__getOperandRecord(inst,2);
                if (*(char *)(loopIndexB + operandRecord2 + 0x10) == '\x04') {
                  operandRecord2 = IRInst__getOperandRecord(inst,1);
                  if (*(char *)(loopIndexB + operandRecord2 + 0x10) == '\x04') {
                    if (*(char *)((int)&mergedLanes + loopIndexB) == '\0') {
                      (**(code **)(*inst + 0x88))(inst,2,loopIndexB,remapB2);
                    }
                  }
                  else {
                    (**(code **)(*inst + 0x88))(inst,2,loopIndexB,remapB1);
                  }
                }
                moreComponents = loopIndexB != 3;
                loopIndexB = loopIndexB + 1;
              } while (moreComponents);
              Block__insertInstBefore(inst[0x56],inst,newSrcB);
              Block__insertInstBefore(inst[0x56],inst,a0);
              Block__insertInstBefore(inst[0x56],inst,newSrcC);
              vcall60Result = (**(code **)(*inst2 + 0x60))(inst2);
              inst4 = inst2;
              if (vcall60Result != 0) {
                inst4 = (int *)IRInst__getOperandSource(inst2,1);
              }
              sourceDef = IRInst__getOperandSource(inst4,1);
              newSource = (int *)IRInst__cloneIfPresub(sourceDef,program,0);
              vcall5cResult = (**(code **)(*newSource + 0x5c))();
              if (vcall5cResult == 0) {
                sourceDef2 = IRInst__getOperandSource(inst2,1);
                if (*(int *)(program + 0x478) < *(int *)(sourceDef2 + 0x160)) {
                  *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
                }
                else {
                  *(int *)(sourceDef2 + 0x160) = *(int *)(program + 0x478) + 1;
                }
              }
              else {
                IRInst__setOperandSource(inst4,1,newSource,0,*(undefined4 *)(program + 8));
                if (*(int *)(program + 0x478) < newSource[0x58]) {
                  newSource[0x58] = newSource[0x58] + 1;
                }
                else {
                  newSource[0x58] = *(int *)(program + 0x478) + 1;
                }
              }
              operandVReg = (int *)IRInst__getOperandSource(a0,1);
              vcall60Result = (**(code **)(*operandVReg + 0x60))();
              if (vcall60Result != 0) {
                sourceDef = IRInst__getOperandSource(a0,1);
                IRInst__foldConstantSourcesIntoClone(sourceDef,a0,*(undefined4 *)(program + 8));
              }
              operandVReg = (int *)IRInst__getOperandSource(newSrcB,1);
              vcall60Result = (**(code **)(*operandVReg + 0x60))();
              if (vcall60Result != 0) {
                sourceDef = IRInst__getOperandSource(newSrcB,1);
                IRInst__foldConstantSourcesIntoClone(sourceDef,newSrcB,*(undefined4 *)(program + 8));
              }
              IRInst__dropCounterAndDeleteIfUnused(inst2,*(undefined4 *)(program + 8));
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

/* Inst__mergeSplatSourceInsts_001524b8 @ 0x1524b8 (1648 bytes) */
int Inst__mergeSplatSourceInsts_001524b8(inst, inst2, program)
  int *inst;
  int *inst2;
  int program;
{
  int vcall60Result;
  int vcall64Result;
  int loopIndexC;
  int loopIndexB;
  bool moreComponents;
  int *inst3;
  int operandIndex;
  int afterInst;
  int cloneResult;
  undefined4 sourceDef4;
  undefined4 operandRecord2;
  undefined4 sourceDef2;
  int operandRecord3;
  int sourceDef5;
  int operandRecord;
  int sourceDef;
  int sourceDef3;
  int *operandVReg;
  bool laneAFree;
  bool noExtraSource;
  bool laneBFree;
  int loopIndex2;
  int candidateDestSelect;
  int destRegisterKind;
  int mergedSelectArg;
  int laneSlot2C;
  int opcodeOrSourcesDifferResult;
  undefined4 inst2DestSelectCopy;
  undefined4 compilerForPass;
  int resultScaleCode;
  int *createWithConstantOperandsResult;
  int *a0;
  int *candidateInst;
  uint componentValue;
  uint componentSentinel;
  undefined4 staleArg8;
  int laneSlot2A;
  int laneSlot1A;
  int laneSlot1B;
  int laneSlot2B;
  uint componentSentinelB;
  uint loopIndex;
  int countdownL;
  int candidateCheck;
  int laneSlotC;
  int countdown;
  undefined4 operandSelectC;
  undefined4 inst2DestSelect;
  undefined4 operandSelectB;
  undefined4 operandSelect;
  int mergedDestSelect;
  int constSelectWord;
  int lastOperandBuf [5];
  int *inst1;
  undefined4 lastOperandBuf0;
  undefined4 scaleOut;
  undefined4 zeroWordA;
  undefined4 zeroWordB;
  int mergeOut [3];
  
  vcall64Result = (**(code **)(*inst + 100))(inst,inst2,program);
  if ((vcall64Result != 0) && (vcall64Result = (**(code **)(*inst2 + 100))(inst2), vcall64Result != 0)) {
    sourceDef2 = IRInst__getOperandSource(inst,1);
    sourceDef4 = IRInst__getOperandSource(inst2,1);
    opcodeOrSourcesDifferResult = ((int (*)())Inst__opcodeOrSourcesDiffer)(sourceDef2,sourceDef4);
    if (opcodeOrSourcesDifferResult == 0) {
      sourceDef = IRInst__getOperandSource(inst,1);
      sourceDef5 = IRInst__getOperandSource(inst2,1);
      if (sourceDef != sourceDef5) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        operandSelectC = *(undefined4 *)(operandRecord + 0x10);
        operandRecord3 = IRInst__getOperandRecord(inst2,0);
        loopIndexB = 0;
        inst2DestSelect = *(undefined4 *)(operandRecord3 + 0x10);
        inst2DestSelectCopy = inst2DestSelect;
        countdownL = 4;
        do {
          if ((*(char *)((int)&operandSelectC + loopIndexB) != '\x01') &&
             (*(char *)((int)&inst2DestSelect + loopIndexB) != '\x01')) {
            return 0;
          }
          loopIndexB = loopIndexB + 1;
          countdownL = countdownL + -1;
        } while (countdownL != 0);
        if (((char)operandSelectC != '\0') &&
           ((*(unsigned char *)((unsigned char *)&(inst2DestSelect) + 3)) = (char)*(undefined4 *)(operandRecord3 + 0x10), (char)inst2DestSelect != '\0')) {
          inst2DestSelect = inst2DestSelectCopy;
          operandRecord = IRInst__getOperandRecord(inst,1);
          operandSelectB = *(undefined4 *)(operandRecord + 0x10);
          operandRecord = IRInst__getOperandRecord(inst2,1);
          operandSelect = *(undefined4 *)(operandRecord + 0x10);
          lastOperandBuf0 = 0;
          lastOperandBuf[4] = 0;
          inst1 = (int *)0x0;
          if ((inst2[5] & 0x200U) != 0) {
            IRInst__readLastOperand(inst2,lastOperandBuf + 4);
          }
          candidateInst = inst1;
          noExtraSource = inst1 == (int *)0x0;
          if (noExtraSource) {
            candidateDestSelect = 0x1010101;
          }
          else {
            operandRecord = IRInst__getOperandRecord(inst1,0);
            candidateDestSelect = *(int *)(operandRecord + 0x10);
          }
          resultScaleCode = inst[0x49];
          if ((((noExtraSource) || (resultScaleCode != 0)) ||
              ((candidateCheck = (**(code **)(*candidateInst + 100))(candidateInst), candidateCheck == 0 &&
               (candidateCheck = IRInst__hasSingleUse(candidateInst,program), candidateCheck != 0)))) ||
             ((((candidateDestSelect == 0x1010100 || (candidateDestSelect = SelectWord__isSingleComponentConstant(candidateDestSelect), candidateDestSelect == 0)) ||
               (candidateDestSelect = SelectWord__isSingleComponentConstant(operandSelectC), candidateDestSelect == 0)) ||
              (candidateDestSelect = SelectWord__isSingleComponentConstant(inst2DestSelect), candidateDestSelect == 0)))) {
            if ((((inst[0x2e] & 1U) == (inst2[0x2e] & 1U)) &&
                (((uint)inst[0x2e] >> 1 & 1) == ((uint)inst2[0x2e] >> 1 & 1))) &&
               ((inst2[0x48] == inst[0x48] && (inst[0x49] == inst2[0x49])))) {
              laneSlot2B = -1;
              laneAFree = true;
              SelectWord__mergeWrittenLanes(mergeOut,inst2DestSelect,operandSelectC);
              laneSlotC = -1;
              mergedDestSelect = mergeOut[0];
              countdown = 4;
              loopIndex2 = 0;
              laneSlot2C = -1;
              laneSlot1A = -1;
              laneBFree = laneAFree;
              do {
                laneSlot2A = laneSlot2C;
                laneSlot1B = laneSlot1A;
                if (*(char *)((int)&operandSelectC + loopIndex2) == '\0') {
                  laneSlot2A = loopIndex2;
                  if ((-1 < laneSlot2C) && (laneSlot2A = laneSlot2C, laneBFree)) {
                    laneBFree = loopIndex2 < 0;
                    laneSlotC = loopIndex2;
                  }
                }
                else if (((*(char *)((int)&inst2DestSelect + loopIndex2) == '\0') &&
                         (laneSlot1B = loopIndex2, -1 < laneSlot1A)) && (laneSlot1B = laneSlot1A, laneAFree)) {
                  laneAFree = loopIndex2 < 0;
                  laneSlot2B = loopIndex2;
                }
                loopIndex2 = loopIndex2 + 1;
                countdown = countdown + -1;
                laneSlot2C = laneSlot2A;
                laneSlot1A = laneSlot1B;
              } while (countdown != 0);
              sourceDef2 = IRInst__getOperandSource(inst2,1);
              createWithConstantOperandsResult = (int *)((int (*)())IRInst__createWithConstantOperands)(3,mergeOut[0],sourceDef2,program,*(undefined4 *)(program + 8),
                                           1.0);
              mergedSelectArg = mergedDestSelect;
              sourceDef2 = IRInst__getOperandSource(inst,1);
              compilerForPass = *(undefined4 *)(program + 8);
              a0 = (int *)((int (*)())IRInst__createWithConstantOperands)(3,mergedSelectArg,sourceDef2,program,compilerForPass,1.0);
              componentValue = (uint)*(byte *)((int)&operandSelectB + laneSlot2A);
              constSelectWord = 0x1010101;
              lastOperandBuf[0] = 0x1010101;
              *(undefined1 *)((int)&constSelectWord + componentValue) = 0;
              (**(code **)(*a0 + 0x88))(a0,1,componentValue,componentValue,compilerForPass,staleArg8,0x1010101);
              if (!laneBFree) {
                componentValue = (uint)*(byte *)((int)&operandSelectB + laneSlotC);
                *(undefined1 *)((int)&constSelectWord + componentValue) = 0;
                (**(code **)(*a0 + 0x88))(a0,1,componentValue,componentValue);
              }
              componentValue = (uint)*(byte *)((int)&operandSelect + laneSlot1B);
              *(undefined1 *)((int)lastOperandBuf + componentValue) = 0;
              (**(code **)(*createWithConstantOperandsResult + 0x88))(createWithConstantOperandsResult,1,componentValue,componentValue);
              if (!laneAFree) {
                componentValue = (uint)*(byte *)((int)&operandSelect + laneSlot2B);
                *(undefined1 *)((int)lastOperandBuf + componentValue) = 0;
                (**(code **)(*createWithConstantOperandsResult + 0x88))(createWithConstantOperandsResult,1,componentValue,componentValue);
              }
              componentSentinel = 0xffffffff;
              componentSentinelB = 0xffffffff;
              loopIndex = 0;
              do {
                operandRecord = IRInst__getOperandRecord(a0,1);
                if ((loopIndex != *(byte *)(loopIndex + operandRecord + 0x10)) && ((int)componentSentinel < 0)) {
                  (**(code **)(*a0 + 0x88))(a0,2,loopIndex,loopIndex);
                  *(undefined1 *)((int)&constSelectWord + loopIndex) = 0;
                  componentSentinel = loopIndex;
                }
                operandRecord = IRInst__getOperandRecord(createWithConstantOperandsResult,1);
                if ((loopIndex != *(byte *)(loopIndex + operandRecord + 0x10)) && ((int)componentSentinelB < 0)) {
                  (**(code **)(*createWithConstantOperandsResult + 0x88))(createWithConstantOperandsResult,2,loopIndex,loopIndex);
                  *(undefined1 *)((int)lastOperandBuf + loopIndex) = 0;
                  componentSentinelB = loopIndex;
                }
                moreComponents = loopIndex != 3;
                loopIndex = loopIndex + 1;
              } while (moreComponents);
              a0[0x27] = constSelectWord;
              scaleOut = 0;
              createWithConstantOperandsResult[0x27] = lastOperandBuf[0];
              zeroWordA = 0;
              zeroWordB = 0;
              operandRecord2 = IRInst__getOperandRecord(inst,1);
              IROperand__copyFrom(&scaleOut,operandRecord2);
              lastOperandBuf[1] = 0;
              lastOperandBuf[2] = 0;
              lastOperandBuf[3] = 0;
              IRInst__saveCounters(inst,lastOperandBuf + 1,0xffffffff);
              afterInst = inst[1];
              DList__unlink(inst);
              IRInst__reinitAsBinary(inst,0x13,*(undefined4 *)(program + 8));
              loopIndexC = 0;
              Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,inst);
              IRInst__restoreCounters(inst,lastOperandBuf + 1);
              inst[0x48] = inst2[0x48];
              inst[0x25] = inst[0x53];
              inst[0x27] = mergedDestSelect;
              inst[0x49] = resultScaleCode;
              inst[0x26] = 0;
              operandRecord2 = IRInst__getOperandRecord(inst,1);
              IROperand__copyFrom(operandRecord2,&scaleOut);
              IRInst__setOperandSource(inst,1,a0,0,*(undefined4 *)(program + 8));
              IROperand__setModifierBits(inst + 0x29,1,inst2[0x2e] & 1);
              IRInst__copyOperandFrom(inst,2,inst2,1);
              IRInst__setOperandSource(inst,2,createWithConstantOperandsResult,0,*(undefined4 *)(program + 8));
              IROperand__setModifierBits(inst + 0x2f,1,0);
              do {
                operandRecord = IRInst__getOperandRecord(inst,1);
                if (*(char *)(loopIndexC + operandRecord + 0x10) == '\x04') {
                  operandRecord = IRInst__getOperandRecord(inst,2);
                  if (*(char *)(loopIndexC + operandRecord + 0x10) == '\x04') {
                    if (*(char *)((int)&mergedDestSelect + loopIndexC) == '\0') {
                      (**(code **)(*inst + 0x88))(inst,1,loopIndexC,0xffffffff);
                    }
                  }
                  else {
                    (**(code **)(*inst + 0x88))(inst,1,loopIndexC,componentSentinel);
                  }
                }
                operandRecord = IRInst__getOperandRecord(inst,2);
                if (*(char *)(loopIndexC + operandRecord + 0x10) == '\x04') {
                  operandRecord = IRInst__getOperandRecord(inst,1);
                  if (*(char *)(loopIndexC + operandRecord + 0x10) == '\x04') {
                    if (*(char *)((int)&mergedDestSelect + loopIndexC) == '\0') {
                      (**(code **)(*inst + 0x88))(inst,2,loopIndexC,0xffffffff);
                    }
                  }
                  else {
                    (**(code **)(*inst + 0x88))(inst,2,loopIndexC,componentSentinelB);
                  }
                }
                moreComponents = loopIndexC != 3;
                loopIndexC = loopIndexC + 1;
              } while (moreComponents);
              Block__insertInstBefore(inst[0x56],inst,createWithConstantOperandsResult);
              Block__insertInstBefore(inst[0x56],inst,a0);
              if (!noExtraSource) {
                IRInst__setLastOperandFromRecord(inst,lastOperandBuf + 4,0,*(undefined4 *)(program + 8));
                if (*(int *)(program + 0x478) < candidateInst[0x58]) {
                  candidateInst[0x58] = candidateInst[0x58] + 1;
                }
                else {
                  candidateInst[0x58] = *(int *)(program + 0x478) + 1;
                }
              }
              vcall60Result = (**(code **)(*inst2 + 0x60))(inst2);
              inst3 = inst2;
              if (vcall60Result != 0) {
                inst3 = (int *)IRInst__getOperandSource(inst2,1);
              }
              sourceDef = IRInst__getOperandSource(inst3,1);
              if (sourceDef == 0) {
                destRegisterKind = inst3[0x2c];
              }
              else {
                sourceDef = IRInst__getOperandSource(inst3,1);
                destRegisterKind = *(int *)(sourceDef + 0x98);
              }
              if (destRegisterKind == 0x31) {
                sourceDef = IRInst__getOperandSource(inst3,1);
                cloneResult = IRInst__clone(sourceDef,*(undefined4 *)(program + 8),0);
                *(undefined4 *)(cloneResult + 0x98) = 0x31;
                *(undefined4 *)(cloneResult + 0x94) = *(undefined4 *)(cloneResult + 0x14c);
                Block__insertInstAfter(*(undefined4 *)(sourceDef + 0x158),sourceDef,cloneResult);
                *(int *)(cloneResult + 0x160) = *(int *)(program + 0x478) + 1;
                if (0 < *(int *)(cloneResult + 0x84)) {
                  operandIndex = 1;
                  do {
                    sourceDef3 = IRInst__getOperandSource(cloneResult,operandIndex);
                    if (*(int *)(program + 0x478) < *(int *)(sourceDef3 + 0x160)) {
                      *(int *)(sourceDef3 + 0x160) = *(int *)(sourceDef3 + 0x160) + 1;
                    }
                    else {
                      *(int *)(sourceDef3 + 0x160) = *(int *)(program + 0x478) + 1;
                    }
                    operandIndex = operandIndex + 1;
                  } while (operandIndex <= *(int *)(cloneResult + 0x84));
                }
                IRInst__setOperandSource(inst3,1,cloneResult,0,*(undefined4 *)(program + 8));
              }
              else {
                sourceDef = IRInst__getOperandSource(inst2,1);
                if (*(int *)(program + 0x478) < *(int *)(sourceDef + 0x160)) {
                  *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
                }
                else {
                  *(int *)(sourceDef + 0x160) = *(int *)(program + 0x478) + 1;
                }
              }
              operandVReg = (int *)IRInst__getOperandSource(a0,1);
              vcall60Result = (**(code **)(*operandVReg + 0x60))();
              if (vcall60Result != 0) {
                sourceDef2 = IRInst__getOperandSource(a0,1);
                IRInst__foldConstantSourcesIntoClone(sourceDef2,a0,*(undefined4 *)(program + 8));
              }
              operandVReg = (int *)IRInst__getOperandSource(createWithConstantOperandsResult,1);
              vcall60Result = (**(code **)(*operandVReg + 0x60))();
              if (vcall60Result != 0) {
                sourceDef2 = IRInst__getOperandSource(createWithConstantOperandsResult,1);
                IRInst__foldConstantSourcesIntoClone(sourceDef2,createWithConstantOperandsResult,*(undefined4 *)(program + 8));
              }
              IRInst__dropCounterAndDeleteIfUnused(inst2,*(undefined4 *)(program + 8));
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

/* Inst__mergeAddWithSharedConstant_00152ea8 @ 0x152ea8 (4720 bytes) */
int Inst__mergeAddWithSharedConstant_00152ea8(inst, inst2, program)
  int *inst;
  int *inst2;
  int program;
{
  int vcall64Result;
  undefined4 foundConstantLow;
  int srcOperandRecord;
  int writeIndex;
  int selectC;
  int fillIndexB;
  int componentIndexB;
  int operandCountB;
  int isPassThroughB;
  int fillCountdownA;
  int finalIndex;
  int fillIndexC;
  int componentIndexC;
  int operandCountC;
  int isPassThroughC;
  int fillCountdownB;
  int identitySelect;
  int fixCountdown;
  int selectA;
  int fillIndexA;
  int componentIndexA;
  int operandCountA;
  int checkCountdown;
  int componentIndex;
  int predicateResult;
  int checkIndex;
  bool isLastComponent;
  bool rewroteOperand;
  int operandIndex19;
  int operandIndex18;
  int operandIndex17;
  int operandIndex16;
  int operandIndex15;
  int afterInst;
  int operandIndex14;
  int operandIndex13;
  int operandIndex12;
  int operandIndex11;
  int operandIndex10;
  int operandIndex9;
  int operandIndex8;
  int operandIndex7;
  int operandIndex6;
  int operandIndex5;
  int operandIndex4;
  int operandIndex3;
  int operandIndex2;
  int operandIndex;
  undefined8 cloneResult;
  int splitRgbAlphaEnabled;
  undefined4 sourceDef7;
  undefined4 operandRecord2;
  undefined4 sourceDef;
  undefined8 sourceDef6;
  int sourceDef5;
  int operandRecord4;
  int sourceDef2;
  int operandRecord3;
  int sourceDef3;
  int operandRecord;
  int operandRecord7;
  int operandRecord5;
  int sourceDef4;
  int operandRecord6;
  int *operandVReg;
  int *operandVReg2;
  bool moreComponents;
  byte srcComponent;
  undefined1 componentByte;
  int constantCheckOrRef;
  undefined4 selectWordToStore;
  int packedHighRef;
  undefined4 componentSelectArg;
  int *newSrcA;
  int packedHighRefC;
  int *newSrcB;
  int *newSrcC;
  undefined4 foundConstantLowC;
  undefined4 staleArg3;
  undefined4 staleArg4;
  undefined4 staleArg5;
  undefined4 staleArg6;
  int *inst3;
  int *resultMaskPtrA;
  int *resultMaskPtrB;
  int *inst4;
  undefined4 compiler;
  code *setComponentFn;
  int fillCountdownC;
  uint componentSelect;
  int packedHighRefB;
  int identitySelectC;
  undefined8 foundConstant;
  undefined8 operandVReg3;
  undefined4 destSelectA;
  undefined4 destSelectB;
  int selectBytesA;
  int selectBytesB;
  int mergedLanes;
  undefined4 srcSelectA;
  undefined4 srcSelectB;
  undefined4 srcSelectC;
  undefined4 oneSelectA;
  undefined4 zeroSelectA;
  undefined4 oneSelectB;
  undefined4 zeroSelectB;
  undefined4 zeroSelectC;
  undefined4 counterSave0;
  undefined4 counterSave1;
  undefined4 counterSave2;
  undefined4 lastOperandRecord;
  int lastOperandSource;
  undefined4 lastOperandTail;
  undefined4 operandCopyA;
  undefined4 operandCopyAWord1;
  undefined4 operandCopyAWord5;
  undefined4 operandCopyB;
  undefined4 operandCopyBWord1;
  undefined4 operandCopyBWord5;
  undefined4 operandCopyC;
  undefined4 operandCopyCWord1;
  undefined4 operandCopyCWord5;
  undefined4 readSelectOut;
  int selectWhereOut;
  int mergedLanesOut;
  int oneOperandIndex;
  int resultScaleCode;
  undefined4 *srcSelectCPtr;
  undefined *globalsBase;
  int *selectBytesAPtr;
  int *selectBytesBPtr;
  int *resultMaskBytePtr;
  
  compiler = *(undefined4 *)(program + 8);
  vcall64Result = (**(code **)(*inst + 100))(inst,inst2,program);
  if (((vcall64Result != 0) && (*(int *)(inst2[0x22] + 8) == 0x12)) ||
     ((vcall64Result = (**(code **)(*inst2 + 100))(inst2), vcall64Result != 0 &&
      (*(int *)(inst[0x22] + 8) == 0x12)))) {
    sourceDef = IRInst__getOperandSource(inst,1);
    operandRecord = IRInst__getOperandRecord(inst,1);
    constantCheckOrRef = IRInst__allSelectsAreHwConstants(sourceDef,compiler,*(undefined4 *)(operandRecord + 0x10),staleArg3,staleArg4,staleArg5,staleArg6);
    sourceDef = IRInst__getOperandSource(inst2,1);
    operandRecord3 = IRInst__getOperandRecord(inst2,1);
    IRInst__allSelectsAreHwConstants(sourceDef,compiler,*(undefined4 *)(operandRecord3 + 0x10),staleArg3,staleArg4,staleArg5,staleArg6);
    if (((inst2[0x48] == inst[0x48]) && (inst[0x49] == inst2[0x49])) && (constantCheckOrRef == 0)) {
      operandRecord = IRInst__getOperandRecord(inst,0);
      destSelectA = *(int *)(operandRecord + 0x10);
      operandRecord = IRInst__getOperandRecord(inst,inst[0x21]);
      WriteMask__fromUsedLanes(&readSelectOut,*(undefined4 *)(operandRecord + 0x10));
      destSelectB = readSelectOut;
      operandRecord = IRInst__getOperandRecord(inst2,0);
      SelectWord__markLanesWhereSecondIsOne(&selectWhereOut,readSelectOut,*(undefined4 *)(operandRecord + 0x10));
      checkIndex = 0;
      destSelectB = selectWhereOut;
      checkCountdown = 4;
      do {
        if ((*(char *)((int)&destSelectA + checkIndex) != '\x01') &&
           (*(char *)((int)&destSelectB + checkIndex) != '\x01')) {
          return 0;
        }
        checkIndex = checkIndex + 1;
        checkCountdown = checkCountdown + -1;
      } while (checkCountdown != 0);
      splitRgbAlphaEnabled = Compiler__isOptionEnabled(compiler,0x30);
      if ((splitRgbAlphaEnabled == 0) || (((char)destSelectA != '\0' && ((char)destSelectB != '\0')))) {
        vcall64Result = (**(code **)(*inst + 100))(inst);
        if (vcall64Result == 0) {
          selectBytesB = destSelectB;
          selectBytesA = destSelectA;
          inst3 = inst2;
          inst4 = inst;
        }
        else {
          selectBytesB = destSelectA;
          selectBytesA = destSelectB;
          inst3 = inst;
          inst4 = inst2;
        }
        predicateResult = ((int (*)())Inst__constantLanesAllowFusion)(inst4);
        if ((predicateResult != 0) && ((inst4[0x2e] & 1U) == (inst4[0x34] & 1U))) {
          sourceDef = IRInst__getOperandSource(inst3,1);
          sourceDef7 = IRInst__getOperandSource(inst4,1);
          predicateResult = ((int (*)())Inst__opcodeOrSourcesDiffer)(sourceDef,sourceDef7);
          if (predicateResult == 0) {
            sourceDef = IRInst__getOperandSource(inst3,1);
            sourceDef7 = IRInst__getOperandSource(inst4,2);
            predicateResult = ((int (*)())Inst__opcodeOrSourcesDiffer)(sourceDef,sourceDef7);
            if (predicateResult == 0) {
              sourceDef3 = IRInst__getOperandSource(inst3,1);
              sourceDef2 = IRInst__getOperandSource(inst4,1);
              if (sourceDef3 != sourceDef2) {
                predicateResult = IRInst__getOperandSource(inst3,1);
                sourceDef2 = IRInst__getOperandSource(inst4,2);
                if ((predicateResult != sourceDef2) && (predicateResult = IRInst__hasSingleUse(inst2,program), predicateResult != 0)) {
                  SelectWord__mergeWrittenLanes(&mergedLanesOut,destSelectB,destSelectA);
                  mergedLanes = mergedLanesOut;
                  resultScaleCode = inst[0x49];
                  operandRecord = IRInst__getOperandRecord(inst4,1);
                  srcSelectA = *(undefined4 *)(operandRecord + 0x10);
                  operandRecord = IRInst__getOperandRecord(inst4,2);
                  srcSelectB = *(undefined4 *)(operandRecord + 0x10);
                  operandRecord = IRInst__getOperandRecord(inst3,1);
                  srcSelectC = *(undefined4 *)(operandRecord + 0x10);
                  operandVReg = (int *)IRInst__getOperandSource(inst4,1);
                  predicateResult = (**(code **)(*operandVReg + 0x60))(operandVReg);
                  if (predicateResult == 0) {
                    sourceDef = IRInst__getOperandSource(inst4,1);
                    newSrcA = (int *)((int (*)())IRInst__createWithConstantOperands)(3,0x1010101,sourceDef,program,compiler,1.0);
                    if (0 < newSrcA[0x21]) {
                      operandIndex12 = 1;
                      do {
                        sourceDef2 = IRInst__getOperandSource(newSrcA,operandIndex12);
                        if (*(int *)(program + 0x478) < *(int *)(sourceDef2 + 0x160)) {
                          *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
                        }
                        else {
                          *(int *)(sourceDef2 + 0x160) = *(int *)(program + 0x478) + 1;
                        }
                        operandIndex12 = operandIndex12 + 1;
                      } while (operandIndex12 <= newSrcA[0x21]);
                    }
                    selectWordToStore = srcSelectA;
                    zeroSelectA = 0;
                    operandIndex13 = 3;
                    oneSelectA = 0;
                    operandRecord3 = IRInst__getOperandRecord(newSrcA,1);
                    selectBytesAPtr = &selectBytesA;
                    *(undefined4 *)(operandRecord3 + 0x10) = selectWordToStore;
                    oneOperandIndex = 2;
                    globalsBase = &DAT_001b2eb8;
                  }
                  else {
                    sourceDef = IRInst__getOperandSource(inst4,1);
                    cloneResult = IRInst__clone(sourceDef,compiler,0);
                    newSrcA = (int *)((ulonglong)cloneResult >> 0x20);
                    foundConstantLow = (undefined4)cloneResult;
                    newSrcA[0x58] = *(int *)(program + 0x478) + 1;
                    newSrcA[0x25] = newSrcA[0x53];
                    if (0 < newSrcA[0x21]) {
                      operandIndex14 = 1;
                      do {
                        sourceDef6 = IRInst__getOperandSource(newSrcA,operandIndex14);
                        packedHighRef = (int)((ulonglong)sourceDef6 >> 0x20);
                        foundConstantLow = (undefined4)sourceDef6;
                        if (*(int *)(program + 0x478) < *(int *)(packedHighRef + 0x160)) {
                          *(int *)(packedHighRef + 0x160) = *(int *)(packedHighRef + 0x160) + 1;
                        }
                        else {
                          *(int *)(packedHighRef + 0x160) = *(int *)(program + 0x478) + 1;
                        }
                        operandIndex14 = operandIndex14 + 1;
                      } while (operandIndex14 <= newSrcA[0x21]);
                    }
                    foundConstant = ((int (*)())IRInst__findConstantOperandWithValue)(newSrcA,foundConstantLow,&oneSelectA,1.0);
                    oneOperandIndex = (int)((ulonglong)foundConstant >> 0x20);
                    if (oneOperandIndex == 0) {
                      ((void (*)())IRInst__setLiteralOperandAndSource)(newSrcA,(int)foundConstant,newSrcA[0x21] + 1,compiler,1.0);
                      operandIndex19 = newSrcA[0x21];
                      oneSelectA = 0;
                      operandVReg3 = IRInst__getOperandSource(newSrcA,operandIndex19);
                      constantCheckOrRef = (int)((ulonglong)operandVReg3 >> 0x20);
                      foundConstant = CONCAT44(operandIndex19,(int)operandVReg3);
                      if (*(int *)(program + 0x478) < *(int *)(constantCheckOrRef + 0x160)) {
                        *(int *)(constantCheckOrRef + 0x160) = *(int *)(constantCheckOrRef + 0x160) + 1;
                      }
                      else {
                        *(int *)(constantCheckOrRef + 0x160) = *(int *)(program + 0x478) + 1;
                        foundConstant = CONCAT44(operandIndex19,(int)operandVReg3);
                      }
                    }
                    oneOperandIndex = (int)((ulonglong)foundConstant >> 0x20);
                    foundConstant = ((int (*)())IRInst__findConstantOperandWithValue)(newSrcA,(int)foundConstant,&zeroSelectA,0.0);
                    operandIndex13 = (int)((ulonglong)foundConstant >> 0x20);
                    if (operandIndex13 == 0) {
                      ((void (*)())IRInst__setLiteralOperandAndSource)(newSrcA,(int)foundConstant,newSrcA[0x21] + 1,compiler,0.0);
                      operandIndex13 = newSrcA[0x21];
                      zeroSelectA = 0;
                      sourceDef2 = IRInst__getOperandSource(newSrcA,operandIndex13);
                      if (*(int *)(program + 0x478) < *(int *)(sourceDef2 + 0x160)) {
                        *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
                      }
                      else {
                        *(int *)(sourceDef2 + 0x160) = *(int *)(program + 0x478) + 1;
                      }
                    }
                    operandCountA = newSrcA[0x21];
                    if (operandCountA < 1) {
                      globalsBase = &DAT_001b2eb8;
                    }
                    else {
                      operandIndex6 = 1;
                      globalsBase = &DAT_001b2eb8;
                      do {
                        if (operandIndex6 == 0) {
                          newSrcA[0x27] = 0x4040404;
                        }
                        else {
                          operandRecord3 = IRInst__getOperandRecord(newSrcA,operandIndex6);
                          *(undefined4 *)(operandRecord3 + 0x10) = 0x4040404;
                          operandCountA = newSrcA[0x21];
                        }
                        operandIndex6 = operandIndex6 + 1;
                      } while (operandIndex6 <= operandCountA);
                    }
                    componentIndexA = 0;
                    selectBytesAPtr = &selectBytesA;
                    do {
                      if ((*(char *)(componentIndexA + (int)selectBytesAPtr) == '\0') &&
                         (srcComponent = *(byte *)((int)&srcSelectA + componentIndexA), 0 < newSrcA[0x21])) {
                        operandIndex7 = 1;
                        do {
                          operandRecord4 = IRInst__getOperandRecord(sourceDef,operandIndex7);
                          if (*(char *)((uint)srcComponent + operandRecord4 + 0x10) != '\x04') {
                            setComponentFn = *(code **)(*newSrcA + 0x88);
                            operandRecord4 = IRInst__getOperandRecord(sourceDef,operandIndex7);
                            (*setComponentFn)(newSrcA,operandIndex7,componentIndexA,
                                       *(undefined1 *)((uint)srcComponent + operandRecord4 + 0x10));
                            break;
                          }
                          operandIndex7 = operandIndex7 + 1;
                        } while (operandIndex7 <= newSrcA[0x21]);
                      }
                      moreComponents = componentIndexA != 3;
                      componentIndexA = componentIndexA + 1;
                    } while (moreComponents);
                    newSrcA[0x27] = selectBytesA;
                  }
                  fillCountdownA = 4;
                  srcSelectA = *(undefined4 *)(globalsBase + -0x2e68);
                  fillIndexA = 0;
                  do {
                    if (*(char *)(fillIndexA + (int)selectBytesAPtr) == '\0') {
                      *(char *)((int)&srcSelectA + fillIndexA) = (char)fillIndexA;
                    }
                    fillIndexA = fillIndexA + 1;
                    fillCountdownA = fillCountdownA + -1;
                  } while (fillCountdownA != 0);
                  operandVReg2 = (int *)IRInst__getOperandSource(inst4,2);
                  isPassThroughB = (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
                  selectA = selectBytesA;
                  if (isPassThroughB == 0) {
                    sourceDef = IRInst__getOperandSource(inst4,2);
                    newSrcB = (int *)((int (*)())IRInst__createWithConstantOperands)(3,selectA,sourceDef,program,compiler,1.0);
                    if (0 < newSrcB[0x21]) {
                      operandIndex15 = 1;
                      do {
                        sourceDef4 = IRInst__getOperandSource(newSrcB,operandIndex15);
                        if (*(int *)(program + 0x478) < *(int *)(sourceDef4 + 0x160)) {
                          *(int *)(sourceDef4 + 0x160) = *(int *)(sourceDef4 + 0x160) + 1;
                        }
                        else {
                          *(int *)(sourceDef4 + 0x160) = *(int *)(program + 0x478) + 1;
                        }
                        operandIndex15 = operandIndex15 + 1;
                      } while (operandIndex15 <= newSrcB[0x21]);
                    }
                    selectWordToStore = srcSelectB;
                    zeroSelectB = 0;
                    componentSelectArg = 2;
                    oneSelectB = 0;
                    operandRecord3 = IRInst__getOperandRecord(newSrcB,1);
                    *(undefined4 *)(operandRecord3 + 0x10) = selectWordToStore;
                    operandIndex16 = 3;
                  }
                  else {
                    sourceDef = IRInst__getOperandSource(inst4,2);
                    cloneResult = IRInst__clone(sourceDef,compiler,0);
                    newSrcB = (int *)((ulonglong)cloneResult >> 0x20);
                    foundConstantLow = (undefined4)cloneResult;
                    newSrcB[0x58] = *(int *)(program + 0x478) + 1;
                    newSrcB[0x25] = newSrcB[0x53];
                    if (0 < newSrcB[0x21]) {
                      operandIndex17 = 1;
                      do {
                        sourceDef6 = IRInst__getOperandSource(newSrcB,operandIndex17);
                        packedHighRefB = (int)((ulonglong)sourceDef6 >> 0x20);
                        foundConstantLow = (undefined4)sourceDef6;
                        if (*(int *)(program + 0x478) < *(int *)(packedHighRefB + 0x160)) {
                          *(int *)(packedHighRefB + 0x160) = *(int *)(packedHighRefB + 0x160) + 1;
                        }
                        else {
                          *(int *)(packedHighRefB + 0x160) = *(int *)(program + 0x478) + 1;
                        }
                        operandIndex17 = operandIndex17 + 1;
                      } while (operandIndex17 <= newSrcB[0x21]);
                    }
                    foundConstant = ((int (*)())IRInst__findConstantOperandWithValue)(newSrcB,foundConstantLow,&oneSelectB,1.0);
                    if ((int)((ulonglong)foundConstant >> 0x20) == 0) {
                      ((void (*)())IRInst__setLiteralOperandAndSource)(newSrcB,(int)foundConstant,newSrcB[0x21] + 1,compiler,1.0);
                      operandIndex8 = newSrcB[0x21];
                      oneSelectB = 0;
                      operandVReg3 = IRInst__getOperandSource(newSrcB,operandIndex8);
                      packedHighRef = (int)((ulonglong)operandVReg3 >> 0x20);
                      foundConstant = CONCAT44(operandIndex8,(int)operandVReg3);
                      if (*(int *)(program + 0x478) < *(int *)(packedHighRef + 0x160)) {
                        *(int *)(packedHighRef + 0x160) = *(int *)(packedHighRef + 0x160) + 1;
                      }
                      else {
                        *(int *)(packedHighRef + 0x160) = *(int *)(program + 0x478) + 1;
                        foundConstant = CONCAT44(operandIndex8,(int)operandVReg3);
                      }
                    }
                    componentSelectArg = (undefined4)((ulonglong)foundConstant >> 0x20);
                    foundConstant = ((int (*)())IRInst__findConstantOperandWithValue)(newSrcB,(int)foundConstant,&zeroSelectB,0.0);
                    operandIndex16 = (int)((ulonglong)foundConstant >> 0x20);
                    if (operandIndex16 == 0) {
                      ((void (*)())IRInst__setLiteralOperandAndSource)(newSrcB,(int)foundConstant,newSrcB[0x21] + 1,compiler,0.0);
                      operandIndex16 = newSrcB[0x21];
                      zeroSelectB = 0;
                      sourceDef4 = IRInst__getOperandSource(newSrcB,operandIndex16);
                      if (*(int *)(program + 0x478) < *(int *)(sourceDef4 + 0x160)) {
                        *(int *)(sourceDef4 + 0x160) = *(int *)(sourceDef4 + 0x160) + 1;
                      }
                      else {
                        *(int *)(sourceDef4 + 0x160) = *(int *)(program + 0x478) + 1;
                      }
                    }
                    operandCountB = newSrcB[0x21];
                    if (0 < operandCountB) {
                      operandIndex = 1;
                      identitySelect = *(int *)(globalsBase + -0x2e68);
                      do {
                        if (operandIndex == 0) {
                          newSrcB[0x27] = identitySelect;
                        }
                        else {
                          operandRecord5 = IRInst__getOperandRecord(newSrcB,operandIndex);
                          *(int *)(operandRecord5 + 0x10) = identitySelect;
                          operandCountB = newSrcB[0x21];
                        }
                        operandIndex = operandIndex + 1;
                      } while (operandIndex <= operandCountB);
                    }
                    componentIndexB = 0;
                    do {
                      if ((*(char *)(componentIndexB + (int)selectBytesAPtr) == '\0') &&
                         (srcComponent = *(byte *)((int)&srcSelectA + componentIndexB), 0 < newSrcB[0x21])) {
                        operandIndex18 = 1;
                        do {
                          operandRecord6 = IRInst__getOperandRecord(sourceDef,operandIndex18);
                          if (*(char *)((uint)srcComponent + operandRecord6 + 0x10) != '\x04') {
                            setComponentFn = *(code **)(*newSrcB + 0x88);
                            operandRecord6 = IRInst__getOperandRecord(sourceDef,operandIndex18);
                            (*setComponentFn)(newSrcB,operandIndex18,componentIndexB,
                                       *(undefined1 *)((uint)srcComponent + operandRecord6 + 0x10));
                            break;
                          }
                          operandIndex18 = operandIndex18 + 1;
                        } while (operandIndex18 <= newSrcB[0x21]);
                      }
                      moreComponents = componentIndexB != 3;
                      componentIndexB = componentIndexB + 1;
                    } while (moreComponents);
                    newSrcB[0x27] = selectBytesA;
                  }
                  fillCountdownB = 4;
                  srcSelectB = *(undefined4 *)(globalsBase + -0x2e68);
                  fillIndexB = 0;
                  do {
                    if (*(char *)(fillIndexB + (int)selectBytesAPtr) == '\0') {
                      *(char *)((int)&srcSelectB + fillIndexB) = (char)fillIndexB;
                    }
                    fillIndexB = fillIndexB + 1;
                    fillCountdownB = fillCountdownB + -1;
                  } while (fillCountdownB != 0);
                  isPassThroughC = (**(code **)(*inst3 + 0x60))(inst3);
                  selectC = selectBytesB;
                  if (isPassThroughC == 0) {
                    sourceDef = IRInst__getOperandSource(inst3,1);
                    newSrcC = (int *)((int (*)())IRInst__createWithConstantOperands)(2,selectC,sourceDef,program,compiler,0.0);
                    if (0 < newSrcC[0x21]) {
                      operandIndex9 = 1;
                      do {
                        sourceDef5 = IRInst__getOperandSource(newSrcC,operandIndex9);
                        if (*(int *)(program + 0x478) < *(int *)(sourceDef5 + 0x160)) {
                          *(int *)(sourceDef5 + 0x160) = *(int *)(sourceDef5 + 0x160) + 1;
                        }
                        else {
                          *(int *)(sourceDef5 + 0x160) = *(int *)(program + 0x478) + 1;
                        }
                        operandIndex9 = operandIndex9 + 1;
                      } while (operandIndex9 <= newSrcC[0x21]);
                    }
                    selectWordToStore = srcSelectC;
                    zeroSelectC = 0;
                    operandRecord5 = IRInst__getOperandRecord(newSrcC,1);
                    *(undefined4 *)(operandRecord5 + 0x10) = selectWordToStore;
                    operandIndex10 = 2;
                    selectBytesBPtr = &selectBytesB;
                  }
                  else {
                    sourceDef = IRInst__getOperandSource(inst3,1);
                    cloneResult = IRInst__clone(sourceDef,compiler,0);
                    newSrcC = (int *)((ulonglong)cloneResult >> 0x20);
                    foundConstantLowC = (undefined4)cloneResult;
                    newSrcC[0x58] = *(int *)(program + 0x478) + 1;
                    newSrcC[0x25] = newSrcC[0x53];
                    if (0 < newSrcC[0x21]) {
                      operandIndex11 = 1;
                      do {
                        sourceDef6 = IRInst__getOperandSource(newSrcC,operandIndex11);
                        packedHighRefC = (int)((ulonglong)sourceDef6 >> 0x20);
                        foundConstantLowC = (undefined4)sourceDef6;
                        if (*(int *)(program + 0x478) < *(int *)(packedHighRefC + 0x160)) {
                          *(int *)(packedHighRefC + 0x160) = *(int *)(packedHighRefC + 0x160) + 1;
                        }
                        else {
                          *(int *)(packedHighRefC + 0x160) = *(int *)(program + 0x478) + 1;
                        }
                        operandIndex11 = operandIndex11 + 1;
                      } while (operandIndex11 <= newSrcC[0x21]);
                    }
                    foundConstant = ((int (*)())IRInst__findConstantOperandWithValue)(newSrcC,foundConstantLowC,&zeroSelectC,0.0);
                    operandIndex10 = (int)((ulonglong)foundConstant >> 0x20);
                    if (operandIndex10 == 0) {
                      ((void (*)())IRInst__setLiteralOperandAndSource)(newSrcC,(int)foundConstant,newSrcC[0x21] + 1,compiler,0.0);
                      operandIndex10 = newSrcC[0x21];
                      zeroSelectC = 0;
                      sourceDef5 = IRInst__getOperandSource(newSrcC,operandIndex10);
                      if (*(int *)(program + 0x478) < *(int *)(sourceDef5 + 0x160)) {
                        *(int *)(sourceDef5 + 0x160) = *(int *)(sourceDef5 + 0x160) + 1;
                      }
                      else {
                        *(int *)(sourceDef5 + 0x160) = *(int *)(program + 0x478) + 1;
                      }
                    }
                    operandCountC = newSrcC[0x21];
                    if (0 < operandCountC) {
                      operandIndex2 = 1;
                      identitySelectC = *(int *)(globalsBase + -0x2e68);
                      do {
                        if (operandIndex2 == 0) {
                          newSrcC[0x27] = identitySelectC;
                        }
                        else {
                          operandRecord4 = IRInst__getOperandRecord(newSrcC,operandIndex2);
                          *(int *)(operandRecord4 + 0x10) = identitySelectC;
                          operandCountC = newSrcC[0x21];
                        }
                        operandIndex2 = operandIndex2 + 1;
                      } while (operandIndex2 <= operandCountC);
                    }
                    componentIndexC = 0;
                    selectBytesBPtr = &selectBytesB;
                    srcSelectCPtr = &srcSelectC;
                    do {
                      if ((*(char *)(componentIndexC + (int)selectBytesBPtr) == '\0') &&
                         (srcComponent = *(byte *)(componentIndexC + (int)srcSelectCPtr), 0 < newSrcC[0x21])) {
                        operandIndex3 = 1;
                        do {
                          operandRecord7 = IRInst__getOperandRecord(sourceDef,operandIndex3);
                          if (*(char *)((uint)srcComponent + operandRecord7 + 0x10) != '\x04') {
                            setComponentFn = *(code **)(*newSrcC + 0x88);
                            operandRecord7 = IRInst__getOperandRecord(sourceDef,operandIndex3);
                            (*setComponentFn)(newSrcC,operandIndex3,componentIndexC,
                                       *(undefined1 *)((uint)srcComponent + operandRecord7 + 0x10));
                            break;
                          }
                          operandIndex3 = operandIndex3 + 1;
                        } while (operandIndex3 <= newSrcC[0x21]);
                      }
                      moreComponents = componentIndexC != 3;
                      componentIndexC = componentIndexC + 1;
                    } while (moreComponents);
                    newSrcC[0x27] = selectBytesB;
                  }
                  fillIndexC = 0;
                  srcSelectC = *(undefined4 *)(globalsBase + -0x2e68);
                  fillCountdownC = 4;
                  do {
                    if (*(char *)(fillIndexC + (int)selectBytesBPtr) == '\0') {
                      *(char *)((int)&srcSelectC + fillIndexC) = (char)fillIndexC;
                    }
                    fillIndexC = fillIndexC + 1;
                    fillCountdownC = fillCountdownC + -1;
                  } while (fillCountdownC != 0);
                  resultMaskBytePtr = newSrcC + 0x27;
                  finalIndex = 0;
                  do {
                    if (*(char *)(finalIndex + (int)selectBytesAPtr) == '\0') {
                      *(char *)((int)&srcSelectC + finalIndex) = (char)finalIndex;
                      (**(code **)(*newSrcC + 0x88))(newSrcC,operandIndex10,finalIndex,zeroSelectC);
                      *(undefined1 *)resultMaskBytePtr = 0;
                      srcComponent = *(byte *)((int)&srcSelectA + finalIndex);
                      if (0 < newSrcA[0x21]) {
                        operandIndex4 = 1;
                        rewroteOperand = false;
                        do {
                          srcOperandRecord = IRInst__getOperandRecord(newSrcA,operandIndex4);
                          componentSelect = (uint)*(byte *)((uint)srcComponent + srcOperandRecord + 0x10);
                          if (((componentSelect != 4) &&
                              (srcOperandRecord = IRInst__getOperandSource(newSrcA,operandIndex4),
                              ((int)*(char *)(srcOperandRecord + 0x15c) >> (componentSelect & 0x3f) & 1U) != 0)) &&
                             (*(float *)(componentSelect * 0x18 + srcOperandRecord + 0x20) == 0.0)) {
                            rewroteOperand = true;
                            (**(code **)(*newSrcA + 0x88))(newSrcA,operandIndex4,componentSelect,4);
                            (**(code **)(*newSrcA + 0x88))(newSrcA,oneOperandIndex,componentSelect,oneSelectA);
                          }
                          operandIndex4 = operandIndex4 + 1;
                        } while (operandIndex4 <= newSrcA[0x21]);
                        if (rewroteOperand) goto setIsLastComponent;
                      }
                      srcComponent = *(byte *)((int)&srcSelectB + finalIndex);
                      if (0 < newSrcB[0x21]) {
                        operandIndex5 = 1;
                        do {
                          srcOperandRecord = IRInst__getOperandRecord(newSrcB,operandIndex5);
                          componentSelect = (uint)*(byte *)((uint)srcComponent + srcOperandRecord + 0x10);
                          if (((componentSelect != 4) &&
                              (srcOperandRecord = IRInst__getOperandSource(newSrcB,operandIndex5),
                              ((int)*(char *)(srcOperandRecord + 0x15c) >> (componentSelect & 0x3f) & 1U) != 0)) &&
                             (*(float *)(componentSelect * 0x18 + srcOperandRecord + 0x20) == 0.0)) {
                            (**(code **)(*newSrcB + 0x88))(newSrcB,operandIndex5,componentSelect,4);
                            (**(code **)(*newSrcB + 0x88))(newSrcB,componentSelectArg,componentSelect,oneSelectB);
                          }
                          operandIndex5 = operandIndex5 + 1;
                        } while (operandIndex5 <= newSrcB[0x21]);
                      }
                    }
setIsLastComponent:
                    isLastComponent = finalIndex == 3;
                    finalIndex = finalIndex + 1;
                    resultMaskBytePtr = (int *)((int)resultMaskBytePtr + 1);
                    if (isLastComponent) {
                      writeIndex = 0;
                      resultMaskPtrB = newSrcB + 0x27;
                      resultMaskPtrA = newSrcA + 0x27;
                      do {
                        if (*(char *)(writeIndex + (int)selectBytesBPtr) == '\0') {
                          (**(code **)(*newSrcA + 0x88))(newSrcA,operandIndex13,writeIndex,zeroSelectA);
                          *(undefined1 *)resultMaskPtrA = 0;
                          (**(code **)(*newSrcB + 0x88))(newSrcB,operandIndex16,writeIndex,zeroSelectB);
                          *(undefined1 *)resultMaskPtrB = 0;
                        }
                        moreComponents = writeIndex != 3;
                        resultMaskPtrA = (int *)((int)resultMaskPtrA + 1);
                        resultMaskPtrB = (int *)((int)resultMaskPtrB + 1);
                        writeIndex = writeIndex + 1;
                      } while (moreComponents);
                      componentIndex = 0;
                      fixCountdown = 4;
                      do {
                        if (*(char *)((int)&mergedLanes + componentIndex) == '\0') {
                          componentByte = (undefined1)componentIndex;
                          if (*(char *)((int)&srcSelectA + componentIndex) == '\x04') {
                            *(undefined1 *)((int)&srcSelectA + componentIndex) = componentByte;
                          }
                          if (*(char *)((int)&srcSelectB + componentIndex) == '\x04') {
                            *(undefined1 *)((int)&srcSelectB + componentIndex) = componentByte;
                          }
                          if (*(char *)((int)&srcSelectC + componentIndex) == '\x04') {
                            *(undefined1 *)((int)&srcSelectC + componentIndex) = componentByte;
                          }
                        }
                        componentIndex = componentIndex + 1;
                        fixCountdown = fixCountdown + -1;
                      } while (fixCountdown != 0);
                      lastOperandRecord = 0;
                      lastOperandSource = 0;
                      lastOperandTail = 0;
                      if ((inst2[5] & 0x200U) != 0) {
                        IRInst__readLastOperand(inst2,&lastOperandRecord);
                      }
                      operandCopyA = 0;
                      operandCopyAWord1 = 0;
                      operandCopyAWord5 = 0;
                      operandCopyB = 0;
                      operandCopyBWord1 = 0;
                      operandCopyBWord5 = 0;
                      operandCopyC = 0;
                      operandCopyCWord1 = 0;
                      operandCopyCWord5 = 0;
                      operandRecord2 = IRInst__getOperandRecord(inst3,1);
                      IROperand__copyFrom(&operandCopyC,operandRecord2);
                      operandRecord2 = IRInst__getOperandRecord(inst4,1);
                      IROperand__copyFrom(&operandCopyA,operandRecord2);
                      operandRecord2 = IRInst__getOperandRecord(inst4,2);
                      IROperand__copyFrom(&operandCopyB,operandRecord2);
                      counterSave0 = 0;
                      counterSave1 = 0;
                      counterSave2 = 0;
                      IRInst__saveCounters(inst,&counterSave0,0xffffffff);
                      afterInst = inst[1];
                      DList__unlink(inst);
                      IRInst__reinitAsTrinary(inst,0x14,compiler);
                      Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,inst);
                      inst[0x26] = 0;
                      inst[0x25] = inst[0x53];
                      IRInst__restoreCounters(inst,&counterSave0);
                      inst[0x48] = inst2[0x48];
                      inst[0x27] = mergedLanes;
                      inst[0x49] = resultScaleCode;
                      operandRecord2 = IRInst__getOperandRecord(inst,1);
                      IROperand__copyFrom(operandRecord2,&operandCopyA);
                      IRInst__setOperandSource(inst,1,newSrcA,0,compiler);
                      Block__insertInstBefore(inst[0x56],inst,newSrcA);
                      selectWordToStore = srcSelectA;
                      operandRecord = IRInst__getOperandRecord(inst,1);
                      *(undefined4 *)(operandRecord + 0x10) = selectWordToStore;
                      operandRecord2 = IRInst__getOperandRecord(inst,2);
                      IROperand__copyFrom(operandRecord2,&operandCopyB);
                      IRInst__setOperandSource(inst,2,newSrcB,0,compiler);
                      Block__insertInstBefore(inst[0x56],inst,newSrcB);
                      selectWordToStore = srcSelectB;
                      operandRecord = IRInst__getOperandRecord(inst,2);
                      *(undefined4 *)(operandRecord + 0x10) = selectWordToStore;
                      IROperand__setModifierBits(inst + 0x2f,1,0);
                      operandRecord2 = IRInst__getOperandRecord(inst,3);
                      IROperand__copyFrom(operandRecord2,&operandCopyC);
                      IRInst__setOperandSource(inst,3,newSrcC,0,compiler);
                      Block__insertInstBefore(inst[0x56],inst,newSrcC);
                      selectWordToStore = srcSelectC;
                      operandRecord = IRInst__getOperandRecord(inst,3);
                      *(undefined4 *)(operandRecord + 0x10) = selectWordToStore;
                      if (lastOperandSource != 0) {
                        IRInst__setLastOperandFromRecord(inst,&lastOperandRecord,0,compiler);
                        if (*(int *)(program + 0x478) < *(int *)(lastOperandSource + 0x160)) {
                          *(int *)(lastOperandSource + 0x160) = *(int *)(lastOperandSource + 0x160) + 1;
                        }
                        else {
                          *(int *)(lastOperandSource + 0x160) = *(int *)(program + 0x478) + 1;
                        }
                      }
                      sourceDef3 = IRInst__getOperandSource(inst2,1);
                      if (*(int *)(program + 0x478) < *(int *)(sourceDef3 + 0x160)) {
                        *(int *)(sourceDef3 + 0x160) = *(int *)(sourceDef3 + 0x160) + 1;
                      }
                      else {
                        *(int *)(sourceDef3 + 0x160) = *(int *)(program + 0x478) + 1;
                      }
                      if (inst4 == inst2) {
                        sourceDef3 = IRInst__getOperandSource(inst2,2);
                        if (*(int *)(program + 0x478) < *(int *)(sourceDef3 + 0x160)) {
                          *(int *)(sourceDef3 + 0x160) = *(int *)(sourceDef3 + 0x160) + 1;
                        }
                        else {
                          *(int *)(sourceDef3 + 0x160) = *(int *)(program + 0x478) + 1;
                        }
                      }
                      IRInst__dropCounterAndDeleteIfUnused(inst2,compiler);
                      return 1;
                    }
                  } while( true );
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

/* Inst__mergeMulWithSharedConstant_001541f0 @ 0x1541f0 (2132 bytes) */
int Inst__mergeMulWithSharedConstant_001541f0(node, inst, pass)
  int *node;
  int *inst;
  int pass;
{
  uint remapComponentB;
  uint remapComponentA;
  uint srcCComponent;
  int firstCompInst2;
  int lastOperandSource;
  int firstCompInst1;
  int mergedLanesCopy;
  int predicateResult;
  int vcall64ResultB;
  int vcall60Result;
  int vcall64Result;
  uint loopIndexD;
  int countdown;
  int loopIndexB;
  int loopIndex;
  bool moreComponents;
  int saturate;
  int afterInst;
  int splitRgbAlphaEnabled;
  undefined4 operandRecord2;
  undefined4 sourceDef;
  undefined4 sourceDef3;
  int operandRecord5;
  int operandRecord3;
  int sourceDef4;
  int operandRecord4;
  int sourceDef2;
  int operandRecord;
  int *operandVReg;
  bool noSecondCompInst1;
  bool hasSecondCompInst1;
  bool noSecondCompInst2;
  int checkResult;
  undefined4 savedDestSelect;
  int secondSelectsConstant;
  int secondCompInst2;
  int thirdCompInst2;
  int *a0;
  int *newSrcB;
  int *newSrcC;
  int *inst1;
  uint srcAComponent;
  undefined4 staleArg3;
  undefined4 staleArg4;
  undefined4 staleArg5;
  undefined4 staleArg6;
  int loopIndexC;
  int firstCompInst1Copy;
  int resultScaleCode;
  int firstCompInst2Copy;
  int secondCompInst1;
  int thirdCompInst1;
  uint remapComponentC;
  int *inst2;
  undefined4 compiler;
  uint srcBComponent;
  uint instFlags;
  int countdown2;
  undefined4 destSelectNode;
  undefined4 destSelectInst;
  int mergedLanes;
  undefined4 operandSelectC;
  undefined4 operandSelectB;
  undefined4 operandSelect;
  int newSrcASelect;
  int newSrcBSelect;
  int scratchFrame [9];
  undefined4 lastOperandTail;
  undefined4 operandCopyA;
  undefined4 operandCopyAWord1;
  undefined4 operandCopyAWord5;
  undefined4 operandCopyB;
  undefined4 operandCopyBWord1;
  undefined4 operandCopyBWord5;
  undefined4 operandCopyC;
  undefined4 operandCopyCWord1;
  undefined4 operandCopyCWord5;
  int mergedLanesOut [3];
  
  vcall64Result = (**(code **)(*node + 100))(node,inst,pass);
  if (((vcall64Result != 0) && (*(int *)(inst[0x22] + 8) == 0x13)) ||
     ((vcall64Result = (**(code **)(*inst + 100))(inst), vcall64Result != 0 &&
      (*(int *)(node[0x22] + 8) == 0x13)))) {
    sourceDef = IRInst__getOperandSource(node,1);
    compiler = *(undefined4 *)(pass + 8);
    operandRecord = IRInst__getOperandRecord(node,1);
    checkResult = IRInst__allSelectsAreHwConstants(sourceDef,compiler,*(undefined4 *)(operandRecord + 0x10),staleArg3,staleArg4,staleArg5,staleArg6);
    sourceDef = IRInst__getOperandSource(inst,1);
    compiler = *(undefined4 *)(pass + 8);
    operandRecord4 = IRInst__getOperandRecord(inst,1);
    secondSelectsConstant = IRInst__allSelectsAreHwConstants(sourceDef,compiler,*(undefined4 *)(operandRecord4 + 0x10),staleArg3,staleArg4,staleArg5,staleArg6);
    if ((inst[0x48] == node[0x48]) && (node[0x49] == inst[0x49])) {
      operandRecord3 = IRInst__getOperandRecord(node,0);
      destSelectNode = *(undefined4 *)(operandRecord3 + 0x10);
      operandRecord5 = IRInst__getOperandRecord(inst,0);
      loopIndexB = 0;
      destSelectInst = *(undefined4 *)(operandRecord5 + 0x10);
      countdown = 4;
      do {
        if ((*(char *)((int)&destSelectNode + loopIndexB) != '\x01') &&
           (*(char *)((int)&destSelectInst + loopIndexB) != '\x01')) {
          return 0;
        }
        loopIndexB = loopIndexB + 1;
        countdown = countdown + -1;
      } while (countdown != 0);
      splitRgbAlphaEnabled = Compiler__isOptionEnabled(*(undefined4 *)(pass + 8),0x30);
      if ((splitRgbAlphaEnabled == 0) || (((char)destSelectNode != '\0' && ((char)destSelectInst != '\0')))) {
        vcall64ResultB = (**(code **)(*node + 100))(node);
        savedDestSelect = destSelectNode;
        inst1 = inst;
        inst2 = node;
        if (vcall64ResultB == 0) {
          destSelectNode = destSelectInst;
          destSelectInst = savedDestSelect;
          inst1 = node;
          inst2 = inst;
          checkResult = secondSelectsConstant;
        }
        if (checkResult == 0) {
          sourceDef = IRInst__getOperandSource(inst2,1);
          sourceDef3 = IRInst__getOperandSource(inst1,1);
          predicateResult = ((int (*)())Inst__opcodeOrSourcesDiffer)(sourceDef,sourceDef3);
          if (predicateResult == 0) {
            sourceDef = IRInst__getOperandSource(inst2,1);
            sourceDef3 = IRInst__getOperandSource(inst1,2);
            predicateResult = ((int (*)())Inst__opcodeOrSourcesDiffer)(sourceDef,sourceDef3);
            if (predicateResult == 0) {
              sourceDef2 = IRInst__getOperandSource(inst2,1);
              sourceDef4 = IRInst__getOperandSource(inst1,1);
              if (sourceDef2 != sourceDef4) {
                checkResult = IRInst__getOperandSource(inst2,1);
                sourceDef4 = IRInst__getOperandSource(inst1,2);
                if ((checkResult != sourceDef4) && (checkResult = IRInst__hasSingleUse(inst,pass), checkResult != 0)) {
                  thirdCompInst2 = -1;
                  noSecondCompInst2 = true;
                  hasSecondCompInst1 = false;
                  SelectWord__mergeWrittenLanes(mergedLanesOut,destSelectInst,destSelectNode);
                  mergedLanes = mergedLanesOut[0];
                  resultScaleCode = node[0x49];
                  sourceDef = IRInst__getOperandSource(inst1,1);
                  secondCompInst2 = -1;
                  a0 = (int *)((int (*)())IRInst__createWithConstantOperands)(2,mergedLanesOut[0],sourceDef,pass,*(undefined4 *)(pass + 8),
                                           0.0);
                  mergedLanesCopy = mergedLanes;
                  sourceDef = IRInst__getOperandSource(inst1,2);
                  secondCompInst1 = -1;
                  newSrcB = (int *)((int (*)())IRInst__createWithConstantOperands)(2,mergedLanesCopy,sourceDef,pass,*(undefined4 *)(pass + 8),
                                               0.0);
                  mergedLanesCopy = mergedLanes;
                  sourceDef = IRInst__getOperandSource(inst2,1);
                  compiler = *(undefined4 *)(pass + 8);
                  thirdCompInst1 = -1;
                  newSrcC = (int *)((int (*)())IRInst__createWithConstantOperands)(2,mergedLanesCopy,sourceDef,pass,compiler,0.0);
                  operandRecord = IRInst__getOperandRecord(inst1,1);
                  operandSelectC = *(undefined4 *)(operandRecord + 0x10);
                  operandRecord = IRInst__getOperandRecord(inst1,2);
                  operandSelectB = *(undefined4 *)(operandRecord + 0x10);
                  operandRecord = IRInst__getOperandRecord(inst2,1);
                  operandSelect = *(undefined4 *)(operandRecord + 0x10);
                  scratchFrame[0] = 0x1010101;
                  loopIndexC = 0;
                  newSrcASelect = 0x1010101;
                  countdown2 = 4;
                  newSrcBSelect = 0x1010101;
                  firstCompInst1 = -1;
                  firstCompInst2 = -1;
                  noSecondCompInst1 = noSecondCompInst2;
                  do {
                    firstCompInst1Copy = firstCompInst1;
                    firstCompInst2Copy = firstCompInst2;
                    if (*(char *)((int)&destSelectNode + loopIndexC) == '\0') {
                      firstCompInst2Copy = loopIndexC;
                      if (-1 < firstCompInst2) {
                        if (noSecondCompInst2) {
                          noSecondCompInst2 = loopIndexC < 0;
                          firstCompInst2Copy = firstCompInst2;
                          secondCompInst2 = loopIndexC;
                        }
                        else {
                          firstCompInst2Copy = firstCompInst2;
                          if (thirdCompInst2 < 0) {
                            thirdCompInst2 = loopIndexC;
                          }
                        }
                      }
                    }
                    else if ((*(char *)((int)&destSelectInst + loopIndexC) == '\0') &&
                            (firstCompInst1Copy = loopIndexC, -1 < firstCompInst1)) {
                      if (noSecondCompInst1) {
                        noSecondCompInst1 = loopIndexC < 0;
                        hasSecondCompInst1 = 0 < loopIndexC;
                        firstCompInst1Copy = firstCompInst1;
                        secondCompInst1 = loopIndexC;
                      }
                      else {
                        firstCompInst1Copy = firstCompInst1;
                        if (thirdCompInst1 < 0) {
                          thirdCompInst1 = loopIndexC;
                        }
                      }
                    }
                    loopIndexC = loopIndexC + 1;
                    countdown2 = countdown2 + -1;
                    firstCompInst1 = firstCompInst1Copy;
                    firstCompInst2 = firstCompInst2Copy;
                  } while (countdown2 != 0);
                  srcBComponent = (uint)*(byte *)((int)&operandSelectB + firstCompInst1Copy);
                  srcAComponent = (uint)*(byte *)((int)&operandSelectC + firstCompInst1Copy);
                  *(undefined1 *)((int)&newSrcBSelect + srcBComponent) = 0;
                  *(undefined1 *)((int)&newSrcASelect + srcAComponent) = 0;
                  (**(code **)(*a0 + 0x88))(a0,1,srcAComponent,srcAComponent,compiler,staleArg5,(int)&destSelectNode + srcBComponent)
                  ;
                  (**(code **)(*newSrcB + 0x88))(newSrcB,1,srcBComponent,srcBComponent);
                  if (hasSecondCompInst1) {
                    srcBComponent = (uint)*(byte *)((int)&operandSelectB + secondCompInst1);
                    srcAComponent = (uint)*(byte *)((int)&operandSelectC + secondCompInst1);
                    *(undefined1 *)((int)&newSrcBSelect + srcBComponent) = 0;
                    *(undefined1 *)((int)&newSrcASelect + srcAComponent) = 0;
                    (**(code **)(*a0 + 0x88))
                              (a0,1,srcAComponent,srcAComponent,compiler,staleArg5,(int)&destSelectNode + srcBComponent);
                    (**(code **)(*newSrcB + 0x88))(newSrcB,1,srcBComponent,srcBComponent);
                    if (0 < thirdCompInst1) {
                      srcBComponent = (uint)*(byte *)((int)&operandSelectB + thirdCompInst1);
                      srcAComponent = (uint)*(byte *)((int)&operandSelectC + thirdCompInst1);
                      *(undefined1 *)((int)&newSrcBSelect + srcBComponent) = 0;
                      *(undefined1 *)((int)&newSrcASelect + srcAComponent) = 0;
                      (**(code **)(*a0 + 0x88))(a0,1,srcAComponent,srcAComponent,compiler,staleArg5,*a0);
                      (**(code **)(*newSrcB + 0x88))(newSrcB,1,srcBComponent,srcBComponent);
                    }
                  }
                  srcCComponent = (uint)*(byte *)((int)&operandSelect + firstCompInst2Copy);
                  *(undefined1 *)((int)scratchFrame + srcCComponent) = 0;
                  (**(code **)(*newSrcC + 0x88))(newSrcC,1,srcCComponent,srcCComponent);
                  if (!noSecondCompInst2) {
                    srcCComponent = (uint)*(byte *)((int)&operandSelect + secondCompInst2);
                    *(undefined1 *)((int)scratchFrame + srcCComponent) = 0;
                    (**(code **)(*newSrcC + 0x88))(newSrcC,1,srcCComponent,srcCComponent);
                    if (-1 < thirdCompInst2) {
                      srcCComponent = (uint)*(byte *)((int)&operandSelect + thirdCompInst2);
                      *(undefined1 *)((int)scratchFrame + srcCComponent) = 0;
                      (**(code **)(*newSrcC + 0x88))(newSrcC,1,srcCComponent,srcCComponent);
                    }
                  }
                  remapComponentA = 0xffffffff;
                  remapComponentB = 0xffffffff;
                  remapComponentC = 0xffffffff;
                  loopIndexD = 0;
                  do {
                    operandRecord = IRInst__getOperandRecord(a0,1);
                    if ((loopIndexD != *(byte *)(loopIndexD + operandRecord + 0x10)) && ((int)remapComponentA < 0)) {
                      (**(code **)(*a0 + 0x88))(a0,2,loopIndexD,loopIndexD);
                      *(undefined1 *)((int)&newSrcASelect + loopIndexD) = 0;
                      remapComponentA = loopIndexD;
                    }
                    operandRecord = IRInst__getOperandRecord(newSrcB,1);
                    if ((loopIndexD != *(byte *)(loopIndexD + operandRecord + 0x10)) && ((int)remapComponentB < 0)) {
                      (**(code **)(*newSrcB + 0x88))(newSrcB,2,loopIndexD,loopIndexD);
                      *(undefined1 *)((int)&newSrcBSelect + loopIndexD) = 0;
                      remapComponentB = loopIndexD;
                    }
                    operandRecord = IRInst__getOperandRecord(newSrcC,1);
                    if ((loopIndexD != *(byte *)(loopIndexD + operandRecord + 0x10)) && ((int)remapComponentC < 0)) {
                      (**(code **)(*newSrcC + 0x88))(newSrcC,2,loopIndexD,loopIndexD);
                      *(undefined1 *)((int)scratchFrame + loopIndexD) = 0;
                      remapComponentC = loopIndexD;
                    }
                    moreComponents = loopIndexD != 3;
                    loopIndexD = loopIndexD + 1;
                  } while (moreComponents);
                  lastOperandSource = 0;
                  a0[0x27] = newSrcASelect;
                  newSrcB[0x27] = newSrcBSelect;
                  newSrcC[0x27] = scratchFrame[0];
                  instFlags = inst[5];
                  if ((instFlags & 0x200) != 0) {
                    lastOperandSource = IRInst__getOperandSource(inst,inst[0x21]);
                    instFlags = inst[5];
                  }
                  scratchFrame[4] = 0;
                  scratchFrame[5] = 0;
                  lastOperandTail = 0;
                  if ((instFlags & 0x200) != 0) {
                    IRInst__readLastOperand(inst,scratchFrame + 4);
                  }
                  operandCopyA = 0;
                  operandCopyAWord1 = 0;
                  operandCopyAWord5 = 0;
                  operandCopyB = 0;
                  operandCopyBWord1 = 0;
                  operandCopyBWord5 = 0;
                  operandCopyC = 0;
                  operandCopyCWord1 = 0;
                  operandCopyCWord5 = 0;
                  afterInst = node[1];
                  operandRecord2 = IRInst__getOperandRecord(inst2,1);
                  IROperand__copyFrom(&operandCopyC,operandRecord2);
                  operandRecord2 = IRInst__getOperandRecord(inst1,1);
                  IROperand__copyFrom(&operandCopyA,operandRecord2);
                  operandRecord2 = IRInst__getOperandRecord(inst1,2);
                  IROperand__copyFrom(&operandCopyB,operandRecord2);
                  scratchFrame[3] = 0;
                  scratchFrame[1] = 0;
                  scratchFrame[2] = 0;
                  IRInst__saveCounters(node,scratchFrame + 1,0xffffffff);
                  DList__unlink(node);
                  IRInst__reinitAsTrinary(node,0x14,*(undefined4 *)(pass + 8));
                  if (lastOperandSource != 0) {
                    IRInst__setLastOperandFromRecord(node,scratchFrame + 4,0,*(undefined4 *)(pass + 8));
                    if (*(int *)(pass + 0x478) < *(int *)(lastOperandSource + 0x160)) {
                      *(int *)(lastOperandSource + 0x160) = *(int *)(lastOperandSource + 0x160) + 1;
                    }
                    else {
                      *(int *)(lastOperandSource + 0x160) = *(int *)(pass + 0x478) + 1;
                    }
                  }
                  IRInst__restoreCounters(node,scratchFrame + 1);
                  saturate = inst[0x48];
                  node[0x49] = resultScaleCode;
                  node[0x48] = saturate;
                  operandRecord2 = IRInst__getOperandRecord(node,3);
                  IROperand__copyFrom(operandRecord2,&operandCopyC);
                  loopIndex = 0;
                  operandRecord2 = IRInst__getOperandRecord(node,1);
                  IROperand__copyFrom(operandRecord2,&operandCopyA);
                  operandRecord2 = IRInst__getOperandRecord(node,2);
                  IROperand__copyFrom(operandRecord2,&operandCopyB);
                  do {
                    if (*(char *)((int)&mergedLanes + loopIndex) == '\0') {
                      operandRecord3 = IRInst__getOperandRecord(node,1);
                      if (*(char *)(loopIndex + operandRecord3 + 0x10) == '\x04') {
                        (**(code **)(*node + 0x88))(node,1,loopIndex,remapComponentA);
                      }
                      operandRecord3 = IRInst__getOperandRecord(node,2);
                      if (*(char *)(loopIndex + operandRecord3 + 0x10) == '\x04') {
                        (**(code **)(*node + 0x88))(node,2,loopIndex,remapComponentB);
                      }
                      operandRecord3 = IRInst__getOperandRecord(node,3);
                      if (*(char *)(loopIndex + operandRecord3 + 0x10) == '\x04') {
                        (**(code **)(*node + 0x88))(node,3,loopIndex,remapComponentC);
                      }
                    }
                    moreComponents = loopIndex != 3;
                    loopIndex = loopIndex + 1;
                  } while (moreComponents);
                  node[0x26] = 0;
                  node[0x25] = node[0x53];
                  Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,node);
                  IRInst__setOperandSource(node,1,a0,0,*(undefined4 *)(pass + 8));
                  IRInst__setOperandSource(node,2,newSrcB,0,*(undefined4 *)(pass + 8));
                  IRInst__setOperandSource(node,3,newSrcC,0,*(undefined4 *)(pass + 8));
                  Block__insertInstBefore(node[0x56],node,a0);
                  Block__insertInstBefore(node[0x56],node,newSrcB);
                  Block__insertInstBefore(node[0x56],node,newSrcC);
                  node[0x27] = mergedLanes;
                  sourceDef2 = IRInst__getOperandSource(inst,1);
                  if (*(int *)(pass + 0x478) < *(int *)(sourceDef2 + 0x160)) {
                    *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
                  }
                  else {
                    *(int *)(sourceDef2 + 0x160) = *(int *)(pass + 0x478) + 1;
                  }
                  if (inst1 == inst) {
                    sourceDef2 = IRInst__getOperandSource(inst1,2);
                    if (*(int *)(pass + 0x478) < *(int *)(sourceDef2 + 0x160)) {
                      *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
                    }
                    else {
                      *(int *)(sourceDef2 + 0x160) = *(int *)(pass + 0x478) + 1;
                    }
                  }
                  operandVReg = (int *)IRInst__getOperandSource(a0,1);
                  vcall60Result = (**(code **)(*operandVReg + 0x60))();
                  if (vcall60Result != 0) {
                    sourceDef = IRInst__getOperandSource(a0,1);
                    IRInst__foldConstantSourcesIntoClone(sourceDef,a0,*(undefined4 *)(pass + 8));
                  }
                  operandVReg = (int *)IRInst__getOperandSource(newSrcB,1);
                  vcall60Result = (**(code **)(*operandVReg + 0x60))();
                  if (vcall60Result != 0) {
                    sourceDef = IRInst__getOperandSource(newSrcB,1);
                    IRInst__foldConstantSourcesIntoClone(sourceDef,newSrcB,*(undefined4 *)(pass + 8));
                  }
                  operandVReg = (int *)IRInst__getOperandSource(newSrcC,1);
                  vcall60Result = (**(code **)(*operandVReg + 0x60))();
                  if (vcall60Result != 0) {
                    sourceDef = IRInst__getOperandSource(newSrcC,1);
                    IRInst__foldConstantSourcesIntoClone(sourceDef,newSrcC,*(undefined4 *)(pass + 8));
                  }
                  IRInst__dropCounterAndDeleteIfUnused(inst,*(undefined4 *)(pass + 8));
                  return 1;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

/* Inst__mergeComponentMovsIntoCnd @ 0x154dc0 (904 bytes) */
int Inst__mergeComponentMovsIntoCnd(inst, program)
  int *inst;
  int program;
{
  uint instSrc1Flags;
  uint instFlags;
  int lanesLeft2;
  int destRegister;
  int lastSplatComponent;
  int destRegisterOffset;
  int hwLimitsResult;
  int maskComponent;
  int lanesLeft;
  int laneIndex3;
  int laneIndex2;
  int maskSelectWord;
  int maskConstant;
  int laneIndex;
  int checkResult;
  int *src2Def;
  int firstWrittenComponentResult;
  int hasSingleUse;
  int firstWrittenComponentResult2;
  int operandRecord2;
  int sourceDef2;
  int operandRecord;
  int sourceDef;
  int useCount;
  bool onlyOneMov;
  bool moreLanes;
  undefined1 instLowSelect;
  undefined1 lastLowSelect;
  code *partnerCheck;
  uint maskWordHi;
  uint maskWordTop;
  int *lastSource;
  int instIsMov;
  int lastIsMov;
  int lastSingleComponent;
  int instSingleComponent;
  int instSplatComponent;
  undefined4 operandVReg;
  undefined4 staleArg7;
  undefined4 staleArg8;
  uint partnerNegate;
  uint partnerAbs;
  int compiler;
  int *partnerInst;
  undefined4 maskSelect;
  int instDestSelect;
  int mergedDestSelect;
  int lastDestSelect;
  undefined4 instSrc1Select;
  undefined4 partnerSrc1Select;
  undefined4 maskLane0;
  undefined4 maskLane1;
  undefined4 maskLane2;
  undefined4 maskLane3;
  int parentBlock;
  int prevNode;
  
  compiler = *(int *)(program + 8);
  if (((((inst != (int *)0x0) && ((inst[5] & 0x200U) != 0)) && (inst[0x48] == 0)) &&
      ((inst[0x49] == 0 &&
       (lastSource = (int *)IRInst__getOperandSource(inst,inst[0x21]), lastSource[0x48] == 0)))) &&
     (lastSource[0x49] == 0)) {
    instIsMov = (**(code **)(*inst + 100))(inst);
    lastIsMov = (**(code **)(*lastSource + 100))(lastSource);
    if ((instIsMov != 0) && (lastIsMov != 0)) {
      sourceDef = IRInst__getOperandSource(inst,1);
      sourceDef2 = IRInst__getOperandSource(lastSource,1);
      if (sourceDef == sourceDef2) {
        return 0;
      }
    }
    lastSingleComponent = IRInst__destIsSingleComponent(lastSource);
    instSingleComponent = IRInst__destIsSingleComponent(inst);
    if ((lastSingleComponent != 0) || (instSingleComponent != 0)) {
      operandRecord = IRInst__getOperandRecord(lastSource,0);
      lastDestSelect = *(int *)(operandRecord + 0x10);
      operandRecord = IRInst__getOperandRecord(inst,0);
      instDestSelect = *(int *)(operandRecord + 0x10);
      if ((instDestSelect != 0x1010100) && (lastDestSelect != 0x1010100)) {
        partnerInst = lastSource;
        if (instIsMov == 0) {
          if (lastIsMov == 0) {
            return 0;
          }
          lastIsMov = 0;
          partnerInst = inst;
          inst = lastSource;
        }
        hasSingleUse = IRInst__hasSingleUse(partnerInst,program);
        if (hasSingleUse == 0) {
          partnerCheck = *(code **)(*partnerInst + 0x4c);
        }
        else {
          partnerCheck = *(code **)(*partnerInst + 100);
        }
        checkResult = (*partnerCheck)(partnerInst);
        if (checkResult != 0) {
          laneIndex = 0;
          lanesLeft = 4;
          do {
            if ((*(char *)((int)&instDestSelect + laneIndex) != '\x01') &&
               (*(char *)((int)&lastDestSelect + laneIndex) != '\x01')) {
              return 0;
            }
            laneIndex = laneIndex + 1;
            lanesLeft = lanesLeft + -1;
          } while (lanesLeft != 0);
          maskLane1 = 0x3f800000;
          maskLane3 = 0;
          maskSelect = 0x10203;
          maskLane0 = 0;
          maskLane2 = 0;
          maskConstant = (**(code **)(**(int **)(compiler + 0x30c) + 0x154))
                            (*(int **)(compiler + 0x30c),program,&maskLane0,&maskSelect,staleArg7,staleArg8,
                             0x10203);
          if (maskConstant != 0) {
            lastSplatComponent = SelectWord__splatComponent(lastDestSelect);
            instSplatComponent = SelectWord__splatComponent(instDestSelect);
            maskComponent = instSplatComponent;
            if (-1 >= instSplatComponent) {
              maskComponent = lastSplatComponent;
            }
            if (maskSelect == 0x10203) {
              maskSelect = *(int *)(&DAT_001b0160 + maskComponent * 4);
            }
            else if (maskComponent == 0) {
              maskWordTop = (uint)maskSelect >> 0x18;
              maskWordHi = (uint)maskSelect >> 0x10;
              maskSelect = CONCAT13((char)maskWordHi,CONCAT12((char)maskWordTop,(*(unsigned short *)((unsigned char *)&(maskSelect) + 2))));
              hwLimitsResult = (**(code **)(**(int **)(compiler + 0x30c) + 0x100))
                                 (*(int **)(compiler + 0x30c),&maskSelect);
              if (hwLimitsResult == 0) {
                return 0;
              }
            }
            onlyOneMov = lastIsMov == 0;
            operandVReg = IRInst__getOperandSource(inst,1);
            src2Def = partnerInst;
            if (!onlyOneMov) {
              src2Def = (int *)IRInst__getOperandSource(partnerInst,1);
            }
            instFlags = inst[5];
            prevNode = inst[1];
            parentBlock = inst[0x56];
            useCount = IRInst__useCount(inst,program);
            instSrc1Flags = inst[0x2e];
            operandRecord = IRInst__getOperandRecord(inst,1);
            instSrc1Select = *(undefined4 *)(operandRecord + 0x10);
            if (onlyOneMov) {
              partnerAbs = 0;
              partnerNegate = 0;
              partnerSrc1Select = 0x10203;
            }
            else {
              partnerNegate = partnerInst[0x2e] & 1;
              partnerAbs = (uint)partnerInst[0x2e] >> 1 & 1;
              operandRecord = IRInst__getOperandRecord(partnerInst,1);
              partnerSrc1Select = *(undefined4 *)(operandRecord + 0x10);
            }
            destRegisterOffset = inst[0x26];
            destRegister = inst[0x25];
            DList__unlink(inst);
            if (-1 < instSplatComponent) {
              IRInst__reinitAsTrinary(inst,0x24,*(undefined4 *)(program + 8));
            }
            else {
              IRInst__reinitAsTrinary(inst,0x26,*(undefined4 *)(program + 8));
            }
            operandRecord2 = IRInst__getOperandRecord(inst,1);
            *(undefined4 *)(operandRecord2 + 0x10) = 0x10203;
            IRInst__setOperandSource(inst,1,maskConstant,0,compiler);
            maskSelectWord = maskSelect;
            operandRecord2 = IRInst__getOperandRecord(inst,1);
            *(int *)(operandRecord2 + 0x10) = maskSelectWord;
            IRInst__setOperandSource(inst,2,src2Def,0,compiler);
            IROperand__setModifierBits(inst + 0x2f,1,partnerNegate);
            IROperand__setModifierBits(inst + 0x2f,2,partnerAbs);
            IRInst__setOperandSource(inst,3,operandVReg,0,compiler);
            IROperand__setModifierBits(inst + 0x35,1,instSrc1Flags & 1);
            IROperand__setModifierBits(inst + 0x35,2,instSrc1Flags >> 1 & 1);
            firstWrittenComponentResult = SelectWord__firstWrittenComponent(instDestSelect);
            instLowSelect = *(undefined1 *)((int)&instSrc1Select + firstWrittenComponentResult);
            firstWrittenComponentResult2 = SelectWord__firstWrittenComponent(lastDestSelect);
            laneIndex2 = 0;
            mergedDestSelect = instDestSelect;
            lastLowSelect = *(undefined1 *)((int)&partnerSrc1Select + firstWrittenComponentResult2);
            lanesLeft2 = 4;
            do {
              if (*(char *)((int)&lastDestSelect + laneIndex2) != '\x01') {
                *(char *)((int)&mergedDestSelect + laneIndex2) = *(char *)((int)&lastDestSelect + laneIndex2);
              }
              laneIndex2 = laneIndex2 + 1;
              lanesLeft2 = lanesLeft2 + -1;
            } while (lanesLeft2 != 0);
            laneIndex3 = 0;
            inst[0x25] = destRegister;
            inst[0x27] = mergedDestSelect;
            inst[0x26] = destRegisterOffset;
            do {
              if (*(char *)((int)&mergedDestSelect + laneIndex3) == '\x01') {
                (**(code **)(*inst + 0x88))(inst,2,laneIndex3,4);
                (**(code **)(*inst + 0x88))(inst,3,laneIndex3,4);
                (**(code **)(*inst + 0x88))(inst,1,laneIndex3,4);
              }
              else if (*(char *)((int)&instDestSelect + laneIndex3) == '\0') {
                (**(code **)(*inst + 0x88))(inst,2,laneIndex3,lastLowSelect);
                (**(code **)(*inst + 0x88))
                          (inst,3,laneIndex3,*(undefined1 *)((int)&instSrc1Select + laneIndex3));
              }
              else if (*(char *)((int)&lastDestSelect + laneIndex3) == '\0') {
                (**(code **)(*inst + 0x88))
                          (inst,2,laneIndex3,*(undefined1 *)((int)&partnerSrc1Select + laneIndex3));
                (**(code **)(*inst + 0x88))(inst,3,laneIndex3,instLowSelect);
              }
              moreLanes = laneIndex3 != 3;
              laneIndex3 = laneIndex3 + 1;
            } while (moreLanes);
            if ((instFlags & 2) != 0) {
              inst[5] = inst[5] | 2;
            }
            inst[0x58] = useCount + *(int *)(program + 0x478);
            Block__insertInstAfter(parentBlock,prevNode,inst);
            if ((partnerInst[5] & 0x200U) != 0) {
              operandVReg = IRInst__getOperandSource(partnerInst,partnerInst[0x21]);
              IRInst__setExtraOperandSource(inst,operandVReg,0,compiler);
            }
            if (!onlyOneMov) {
              (**(code **)(*partnerInst + 0xc))(partnerInst,0,*(undefined4 *)(program + 8));
            }
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* Inst__threeSourcesAreRegisters_0015546c @ 0x15546c (488 bytes) */
int Inst__threeSourcesAreRegisters_0015546c(ctx, unusedArg2, inst, staleArg4)
  undefined4 ctx;
  undefined4 unusedArg2;
  int inst;
  uint staleArg4;
{
  int sourceDef;
  int sourceDef2;
  int *producerSource;
  int vcall5cResult;
  int instOrCheck;
  undefined4 operandVReg;
  undefined4 operandVReg2;
  undefined4 operandVReg3;
  undefined8 operandVReg4;
  
  if (*(int *)(*(int *)(inst + 0x88) + 8) != 0x25) {
    return 0;
  }
  instOrCheck = inst;
  operandVReg4 = IRInst__getOperandSource(inst,1);
  producerSource = (int *)((ulonglong)operandVReg4 >> 0x20);
  vcall5cResult = (**(code **)(*producerSource + 0x5c))(producerSource,(int)operandVReg4,instOrCheck,staleArg4);
  if (vcall5cResult != 0) {
    operandVReg4 = IRInst__getOperandSource(inst,2);
    producerSource = (int *)((ulonglong)operandVReg4 >> 0x20);
    vcall5cResult = (**(code **)(*producerSource + 0x5c))(producerSource,(int)operandVReg4,instOrCheck,staleArg4);
    if (vcall5cResult != 0) {
      operandVReg4 = IRInst__getOperandSource(inst,3);
      producerSource = (int *)((ulonglong)operandVReg4 >> 0x20);
      instOrCheck = (**(code **)(*producerSource + 0x5c))(producerSource,(int)operandVReg4,instOrCheck,staleArg4);
      if (instOrCheck != 0) {
        operandVReg = IRInst__getOperandSource(inst,1);
        operandVReg2 = IRInst__getOperandSource(inst,2);
        operandVReg3 = IRInst__getOperandSource(inst,3);
        sourceDef = IRInst__getOperandSource(operandVReg,1);
        sourceDef2 = IRInst__getOperandSource(operandVReg2,1);
        if (sourceDef == sourceDef2) {
          sourceDef = IRInst__getOperandSource(operandVReg,2);
          sourceDef2 = IRInst__getOperandSource(operandVReg2,2);
          if (sourceDef == sourceDef2) {
            sourceDef = IRInst__getOperandSource(operandVReg2,1);
            sourceDef2 = IRInst__getOperandSource(operandVReg3,1);
            if (sourceDef == sourceDef2) {
              IRInst__getOperandSource(operandVReg2,2);
              IRInst__getOperandSource(operandVReg3,2);
            }
          }
        }
        goto setSourceDef;
      }
    }
  }
  sourceDef = IRInst__getOperandSource(inst,1);
  sourceDef2 = IRInst__getOperandSource(inst,2);
  if (sourceDef == sourceDef2) {
    IRInst__getOperandSource(inst,2);
    IRInst__getOperandSource(inst,3);
  }
setSourceDef:
  sourceDef = IRInst__getOperandSource(inst,1);
  sourceDef2 = IRInst__getOperandSource(inst,2);
  if (sourceDef == sourceDef2) {
    IRInst__getOperandSource(inst,2);
    IRInst__getOperandSource(inst,3);
  }
  return 0;
}

/* Inst__mergeMinMaxWithSource_00155654 @ 0x155654 (1036 bytes) */
int Inst__mergeMinMaxWithSource_00155654(inst, operandIndex, inst2, pass)
  int *inst;
  int operandIndex;
  int inst2;
  int pass;
{
  int operandSelect;
  int vcall5cResult;
  int vcall14Result;
  int flagBit10Result;
  int cloneResult;
  int sourceDef2;
  int operandRecord;
  int sourceDef;
  int *operandVReg;
  int instOpcode;
  int targetTraitResult;
  int *target;
  int *operandVReg2;
  int passStamp;
  int operandVReg3;
  int passStampNext;
  undefined4 operandSelectB;
  int composedSelectOut [2];
  
  instOpcode = *(int *)(*(int *)(inst2 + 0x88) + 8);
  if ((instOpcode != 0x17) && (instOpcode != 0x19)) {
    return 0;
  }
  if (inst == (int *)0x0) {
    return 0;
  }
  vcall14Result = (**(code **)(*inst + 0x14))(inst);
  if (vcall14Result < operandIndex) {
    return 0;
  }
  if ((*(uint *)(inst2 + 0x14) & 0x200) != 0) {
    return 0;
  }
  if (*(int *)(inst2 + 0x120) != 0) {
    return 0;
  }
  if (*(int *)(inst2 + 0x124) != 0) {
    return 0;
  }
  target = *(int **)(*(int *)(pass + 8) + 0x30c);
  targetTraitResult = (**(code **)(*target + 0x88))(target);
  if ((targetTraitResult == 0) &&
     (targetTraitResult = OpcodeTraits__flagBit10(*(undefined4 *)(inst[0x22] + 8),*(undefined4 *)(pass + 8)),
     targetTraitResult == 0)) {
    return 0;
  }
  IRInst__getOperandSource(inst,operandIndex);
  operandVReg = (int *)IRInst__getOperandSource(inst2,1);
  operandVReg2 = (int *)IRInst__getOperandSource(inst2,2);
  if (operandVReg != operandVReg2) {
    vcall5cResult = (**(code **)(*operandVReg + 0x5c))(operandVReg);
    if (vcall5cResult == 0) {
      return 0;
    }
    vcall5cResult = (**(code **)(*operandVReg2 + 0x5c))(operandVReg2);
    if (vcall5cResult == 0) {
      return 0;
    }
    if (*(int *)(operandVReg[0x22] + 8) != *(int *)(operandVReg2[0x22] + 8)) {
      return 0;
    }
    sourceDef = IRInst__getOperandSource(operandVReg,1);
    sourceDef2 = IRInst__getOperandSource(operandVReg2,1);
    if (sourceDef != sourceDef2) {
      return 0;
    }
    vcall14Result = (**(code **)(*operandVReg + 0x14))(operandVReg);
    if (1 < vcall14Result) {
      sourceDef = IRInst__getOperandSource(operandVReg,2);
      sourceDef2 = IRInst__getOperandSource(operandVReg2,2);
      if (sourceDef != sourceDef2) {
        return 0;
      }
    }
  }
  if (((*(uint *)(inst2 + 0xb8) >> 1 & 1) == (*(uint *)(inst2 + 0xd0) >> 1 & 1)) &&
     ((*(uint *)(inst2 + 0xb8) & 1) == (*(uint *)(inst2 + 0xd0) & 1 ^ 1))) {
    operandRecord = IRInst__getOperandRecord(inst2,1);
    operandSelect = *(int *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(inst2,2);
    if (operandSelect == *(int *)(operandRecord + 0x10)) {
      passStamp = *(int *)(pass + 0x478);
      vcall5cResult = (**(code **)(*operandVReg + 0x5c))(operandVReg);
      if (vcall5cResult == 0) {
        if (passStamp < operandVReg[0x58]) {
          operandVReg[0x58] = operandVReg[0x58] + 1;
        }
        else {
          operandVReg[0x58] = passStamp + 1;
        }
        IRInst__setOperandSource(inst,operandIndex,operandVReg,0,*(undefined4 *)(pass + 8));
      }
      else {
        cloneResult = IRInst__clone(operandVReg,*(undefined4 *)(pass + 8),0);
        *(undefined4 *)(cloneResult + 0x98) = 0x31;
        *(undefined4 *)(cloneResult + 0x94) = *(undefined4 *)(cloneResult + 0x14c);
        passStampNext = passStamp + 1;
        Block__insertInstAfter(operandVReg[0x56],operandVReg,cloneResult);
        *(int *)(cloneResult + 0x160) = passStampNext;
        operandVReg3 = IRInst__getOperandSource(cloneResult,1);
        if (passStamp < *(int *)(operandVReg3 + 0x160)) {
          *(int *)(operandVReg3 + 0x160) = *(int *)(operandVReg3 + 0x160) + 1;
        }
        else {
          *(int *)(operandVReg3 + 0x160) = passStampNext;
        }
        if (1 < *(int *)(cloneResult + 0x84)) {
          operandVReg3 = IRInst__getOperandSource(cloneResult,2);
          if (passStamp < *(int *)(operandVReg3 + 0x160)) {
            *(int *)(operandVReg3 + 0x160) = *(int *)(operandVReg3 + 0x160) + 1;
          }
          else {
            *(int *)(operandVReg3 + 0x160) = passStampNext;
          }
        }
        IRInst__setOperandSource(inst,operandIndex,cloneResult,0,*(undefined4 *)(pass + 8));
      }
      operandRecord = IRInst__getOperandRecord(inst2,1);
      operandSelectB = *(undefined4 *)(operandRecord + 0x10);
      operandRecord = IRInst__getOperandRecord(inst,operandIndex);
      SelectWord__compose(composedSelectOut,operandSelectB,*(undefined4 *)(operandRecord + 0x10));
      if (operandIndex == 0) {
        inst[0x27] = composedSelectOut[0];
      }
      else {
        operandRecord = IRInst__getOperandRecord(inst,operandIndex);
        *(int *)(operandRecord + 0x10) = composedSelectOut[0];
      }
      flagBit10Result = OpcodeTraits__flagBit10(*(undefined4 *)(inst[0x22] + 8),*(undefined4 *)(pass + 8));
      if (flagBit10Result == 0) {
        IROperand__setModifierBits(inst + operandIndex * 6 + 0x23,2,1);
      }
      else {
        IROperand__setModifierBits(inst + operandIndex * 6 + 0x23,2,0);
      }
      if (*(int *)(*(int *)(inst2 + 0x88) + 8) == 0x19) {
        IROperand__setModifierBits(inst + operandIndex * 6 + 0x23,1,1);
      }
      *(int *)(pass + 0x1bc) = *(int *)(pass + 0x1bc) + 1;
      IRInst__dropCounterAndDeleteIfUnused(inst2,*(undefined4 *)(pass + 8));
      return 1;
    }
  }
  return 0;
}

/* Inst__collapseAlgebraic_00155a60 @ 0x155a60 (2056 bytes) */
int Inst__collapseAlgebraic_00155a60(inst, pass)
  void *inst;
  int pass;
{
  int *target;
  int operandRecord7;
  bool hasExtraSource;
  uint instFlagsA;
  uint instFlagsC;
  undefined4 savedField98C;
  undefined4 savedField94;
  undefined4 savedField98;
  undefined4 result;
  bool moreComponents;
  uint negateFlag;
  uint negateOperand1;
  undefined4 block;
  int *inst3;
  int afterInst3;
  int operandIndex5;
  int operandRecord1;
  int operandIndex4;
  int newSource2;
  int newSource;
  int afterInst2;
  int afterInst;
  int operandIndex3;
  int operandIndex2;
  int operandIndex;
  int cloneResult;
  int definingField1282;
  int areCompatibleResult;
  int hasSingleUse;
  int definingField1283;
  int areCompatibleResult2;
  int definingField128;
  undefined4 sourceDef;
  undefined4 sourceDef5;
  int operandRecord6;
  int sourceDef2;
  int operandRecord4;
  int useCount;
  int sourceDef3;
  int operandRecord;
  int operandRecord2;
  int sourceDef4;
  int operandRecord5;
  int sourceDef6;
  int sourceDef7;
  int operandRecord3;
  int *operandVReg;
  int *operandVReg2;
  bool swapFirst;
  bool multipleUses;
  bool swapSecond;
  bool singleUse;
  int destRecordC;
  int constMatchResultC;
  int destRecordD;
  int constMatchResultB;
  int operandLoopIdx;
  int producerOperandIdxB;
  int operandOpcode;
  int inst2Vtable;
  int producerOperandIdx;
  int producerOpcode;
  int instOpcode;
  int dropCounterAndDeleteIfUnusedResult;
  int setOperandSourceIfLegalResult3;
  int sourceDef8;
  int useCountResult2;
  int operandRecord8;
  uint modeTableEntry;
  uint operandModBitsA;
  uint savedFieldb8;
  uint operandModBitsB;
  uint savedFielde8;
  uint instFlagsB;
  int modeBitB;
  int operandIdxNext;
  int *inst2;
  int *candidateSource;
  undefined4 operandSelect;
  undefined4 savedField120;
  undefined4 operandSelect2;
  undefined4 savedField120B;
  int producerOperandA;
  int compatibleResult;
  int modeBitA;
  int producerSharedSource;
  int setOperandSourceIfLegalResult;
  int vcall5cResult;
  int vcallfcResult;
  void *newInst;
  int passStampC;
  undefined4 savedField120C;
  undefined4 operandSelect3;
  undefined4 savedField124;
  undefined4 operandSelect4;
  undefined4 operandSelect5;
  undefined4 savedField124B;
  undefined4 operandSelect6;
  int useCountA;
  int passStampB;
  int scaleUp;
  int matchesConstantResult;
  int setOperandSourceIfLegalResult2;
  int vcall5cResult2;
  int vcallfcResult2;
  int otherOperandIdx;
  int vcall5cResult3;
  undefined4 operandSelect7;
  int *swappedInst;
  undefined4 savedField98B;
  int vcall50Result;
  int flagBit0Result;
  int hasSingleUseResult;
  int destRecordInst3;
  int useCountB;
  int outputScale;
  int *inst1;
  undefined4 savedField94B;
  undefined4 constOne0;
  undefined4 constOne1;
  undefined4 constOne2;
  undefined4 constOne3;
  undefined4 constHalf0;
  undefined4 constHalf1;
  undefined4 constHalf2;
  undefined4 constHalf3;
  undefined4 constTwo0;
  undefined4 constTwo1;
  undefined4 constTwo2;
  undefined4 constTwo3;
  undefined4 lastOperandBuf0;
  undefined4 lastOperandBuf1;
  undefined4 lastOperandBuf2;
  uint readMaskB;
  uint writeMaskB;
  uint readMaskC;
  uint writeMaskC;
  undefined4 composedSelectA;
  undefined4 composedSelectB;
  uint readMaskA;
  uint writeMaskA;
  uint negateOperand3;
  uint absOperand3;
  undefined4 operandSource;
  int useCountResult;
  uint negateOperand3Saved;
  
  constOne3 = 0x3f800000;
  constOne0 = 0x3f800000;
  constOne1 = 0x3f800000;
  constOne2 = 0x3f800000;
  constHalf3 = 0x3f000000;
  constTwo3 = 0x40000000;
  constHalf0 = 0x3f000000;
  constHalf1 = 0x3f000000;
  constHalf2 = 0x3f000000;
  constTwo0 = 0x40000000;
  constTwo1 = 0x40000000;
  constTwo2 = 0x40000000;
  instOpcode = *(int *)(*(int *)((int)inst + 0x88) + 8);
  if (instOpcode == 0x12) {
loopSetResult:
    result = 0;
  }
  else {
    if (instOpcode != 0x14) {
      return 0;
    }
    inst2 = (int *)IRInst__getOperandSource(inst,1);
    operandVReg = (int *)IRInst__getOperandSource(inst,2);
    producerOpcode = *(int *)(inst2[0x22] + 8);
    if (((producerOpcode == 0x12) || (producerOpcode == 0x9b)) || (producerOpcode == 0x9a)) {
      producerOperandIdx = 1;
      otherOperandIdx = 2;
loopSetOutputScale:
      outputScale = *(int *)((int)inst + 0x124);
      operandRecord = IRInst__getOperandRecord(inst,0);
      matchesConstantResult = IRInst__sourceMatchesConstant(inst,otherOperandIdx,*(undefined4 *)(operandRecord + 0x10),&constHalf0);
      if (matchesConstantResult == 0) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        matchesConstantResult = IRInst__sourceMatchesConstant(inst,otherOperandIdx,*(undefined4 *)(operandRecord + 0x10),&constTwo0);
        if (matchesConstantResult == 0) {
          return 0;
        }
        outputScale = outputScale + 1;
        target = *(int **)(*(int *)(pass + 8) + 0x30c);
        vcallfcResult2 = (**(code **)(*target + 0xfc))(target,outputScale,inst);
        if (vcallfcResult2 == 0) {
          return 0;
        }
        scaleUp = 1;
      }
      else {
        outputScale = outputScale + -1;
        target = *(int **)(*(int *)(pass + 8) + 0x30c);
        scaleUp = 0;
        vcallfcResult = (**(code **)(*target + 0xfc))(target,outputScale,inst);
        if (vcallfcResult == 0) {
          return 0;
        }
      }
      sourceDef4 = IRInst__getOperandSource(inst2,1);
      producerSharedSource = IRInst__getOperandSource(inst2,2);
      definingField128 = IRInst__getDefiningField128(inst,3);
      if ((inst2[5] & 0x200U) != 0) {
        return 0;
      }
      operandRecord3 = IRInst__getOperandRecord(inst,producerOperandIdx);
      areCompatibleResult2 = SelectWord__areCompatible(*(undefined4 *)(operandRecord3 + 0x10),DAT_001b004c);
      if (areCompatibleResult2 == 0) {
        return 0;
      }
      definingField1283 = IRInst__getDefiningField128(inst,producerOperandIdx);
      if (definingField1283 != 0) {
        return 0;
      }
      sourceDef7 = IRInst__getOperandSource(inst,3);
      if (producerSharedSource == sourceDef7) {
        operandRecord3 = IRInst__getOperandRecord(inst,3);
        operandSelect = *(undefined4 *)(operandRecord3 + 0x10);
        operandRecord3 = IRInst__getOperandRecord(inst2,2);
        compatibleResult = SelectWord__areCompatible(operandSelect,*(undefined4 *)(operandRecord3 + 0x10));
        if ((compatibleResult == 0) || (compatibleResult = IRInst__getDefiningField128(inst2,2), definingField128 != compatibleResult)) goto setSourceDef6;
        if (*(int *)(inst2[0x22] + 8) == 0x9a) {
          producerOperandA = 2;
          operandIndex3 = 1;
          swapFirst = true;
          swapSecond = false;
        }
        else {
          producerOperandA = 2;
          operandIndex3 = 1;
          swapFirst = false;
          swapSecond = false;
        }
      }
      else {
setSourceDef6:
        sourceDef6 = IRInst__getOperandSource(inst,3);
        if (sourceDef4 != sourceDef6) {
          return 0;
        }
        operandRecord5 = IRInst__getOperandRecord(inst,3);
        operandSelect = *(undefined4 *)(operandRecord5 + 0x10);
        operandRecord5 = IRInst__getOperandRecord(inst2,1);
        areCompatibleResult = SelectWord__areCompatible(operandSelect,*(undefined4 *)(operandRecord5 + 0x10));
        if (areCompatibleResult == 0) {
          return 0;
        }
        definingField1282 = IRInst__getDefiningField128(inst2,1);
        if (definingField128 != definingField1282) {
          return 0;
        }
        producerSharedSource = sourceDef4;
        if (*(int *)(inst2[0x22] + 8) == 0x9a) {
          producerOperandA = 1;
          operandIndex3 = 2;
          swapFirst = false;
          swapSecond = true;
        }
        else {
          producerOperandA = 1;
          operandIndex3 = 2;
          swapFirst = false;
          swapSecond = false;
        }
      }
      hasSingleUse = IRInst__hasSingleUse(inst2,pass);
      if ((((hasSingleUse == 0) || ((*(uint *)((int)inst + 0xe8) & 2) != 0)) ||
          ((*(uint *)((int)inst + producerOperandIdx * 0x18 + 0xa0) & 2) != 0)) ||
         (((inst2[0x2e] & 2U) != 0 || ((inst2[0x34] & 2U) != 0)))) {
        return 0;
      }
      operandRecord3 = IRInst__getOperandRecord(inst,producerOperandIdx);
      SelectWord__readMask(&readMaskA,*(undefined4 *)(operandRecord3 + 0x10));
      operandRecord7 = IRInst__getOperandRecord(inst2,0);
      WriteMask__fromSelectWord(&writeMaskA,*(undefined4 *)(operandRecord7 + 0x10));
      if ((writeMaskA << 0x18 | (writeMaskA >> 8 & 0xff) << 0x10 | (writeMaskA >> 0x10 & 0xff) << 8 |
          writeMaskA >> 0x18) <
          (readMaskA << 0x18 | (readMaskA >> 8 & 0xff) << 0x10 | (readMaskA >> 0x10 & 0xff) << 8 |
          readMaskA >> 0x18)) {
        return 0;
      }
      if (writeMaskA != (writeMaskA & readMaskA)) {
        return 0;
      }
      if (inst2[0x48] != 0) {
        return 0;
      }
      if (inst2[0x49] != 0) {
        return 0;
      }
      if (((inst2[producerOperandA * 6 + 0x28] & 1U) != 0) || (modeBitA = 0, swapFirst)) {
        modeBitA = 1;
      }
      if (((inst2[operandIndex3 * 6 + 0x28] & 1U) != 0) || (modeBitB = 0, swapSecond)) {
        modeBitB = 1;
      }
      modeTableEntry = *(uint *)(&DAT_001b0060 +
                       (*(uint *)((int)inst + otherOperandIdx * 0x18 + 0xa0) & 1 |
                        (*(uint *)((int)inst + producerOperandIdx * 0x18 + 0xa0) & 1) << 1 |
                        (*(uint *)((int)inst + 0xe8) & 1) << 2 | modeBitA << 3 | modeBitB << 4 |
                       scaleUp << 5) * 4);
      if (-1 < (int)modeTableEntry) goto loopSetResult;
      newSource = 0;
      *(int *)(pass + 0x1b0) = *(int *)(pass + 0x1b0) + 1;
      operandRecord8 = IRInst__getOperandRecord(inst,0);
      operandSelect2 = *(undefined4 *)(operandRecord8 + 0x10);
      savedField120 = *(undefined4 *)((int)inst + 0x120);
      if ((*(uint *)((int)inst + 0x14) & 0x200) != 0) {
        newSource = IRInst__getOperandSource(inst,*(undefined4 *)((int)inst + 0x84));
      }
      useCountResult2 = IRInst__useCount(inst,pass);
      afterInst = *(int *)((int)inst + 4);
      if (0 < *(int *)((int)inst + 0x84)) {
        operandIndex = 1;
        do {
          operandIdxNext = operandIndex + 1;
          IRInst__setOperandSource(inst,operandIndex,0,0,*(undefined4 *)(pass + 8));
          operandIndex = operandIdxNext;
        } while (operandIdxNext <= *(int *)((int)inst + 0x84));
      }
      instFlagsA = *(uint *)((int)inst + 0x14);
      savedField98 = *(undefined4 *)((int)inst + 0x98);
      savedField94 = *(undefined4 *)((int)inst + 0x94);
      DList__unlink(inst);
      IRInst__reinitAsBinary(inst,0x12,*(undefined4 *)(pass + 8));
      *(undefined4 *)((int)inst + 0x9c) = operandSelect2;
      operandIndex2 = producerOperandA;
      if ((modeTableEntry & 0x40000000) == 0) {
        operandIndex2 = operandIndex3;
        operandIndex3 = producerOperandA;
      }
      *(undefined4 *)((int)inst + 0x94) = savedField94;
      *(undefined4 *)((int)inst + 0x98) = savedField98;
      if ((instFlagsA & 2) != 0) {
        *(uint *)((int)inst + 0x14) = *(uint *)((int)inst + 0x14) | 2;
      }
      sourceDef = IRInst__getOperandSource(inst2,operandIndex3);
      IRInst__setOperandSource(inst,1,sourceDef,0,*(undefined4 *)(pass + 8));
      sourceDef = IRInst__getOperandSource(inst2,operandIndex2);
      IRInst__setOperandSource(inst,2,sourceDef,0,*(undefined4 *)(pass + 8));
      operandRecord2 = IRInst__getOperandRecord(inst2,operandIndex3);
      operandSelect2 = *(undefined4 *)(operandRecord2 + 0x10);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord2 + 0x10) = operandSelect2;
      operandRecord2 = IRInst__getOperandRecord(inst2,operandIndex2);
      operandSelect2 = *(undefined4 *)(operandRecord2 + 0x10);
      operandRecord2 = IRInst__getOperandRecord(inst,2);
      *(undefined4 *)(operandRecord2 + 0x10) = operandSelect2;
      IROperand__setModifierBits((int)inst + 0xa4,1,modeTableEntry >> 0x1d & 1);
      IROperand__setModifierBits((int)inst + 0xbc,1,modeTableEntry >> 0x1c & 1);
      passStampC = *(int *)(pass + 0x478);
      *(undefined4 *)((int)inst + 0x120) = savedField120;
      *(int *)((int)inst + 0x124) = outputScale;
      *(int *)((int)inst + 0x160) = useCountResult2 + passStampC;
      if (newSource != 0) {
        IRInst__setExtraOperandSource(inst,newSource,0,*(undefined4 *)(pass + 8));
      }
      result = 0;
      Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,inst);
      passStampB = *(int *)(pass + 0x478);
      useCount = IRInst__useCount(producerSharedSource,pass);
      inst2Vtable = *inst2;
      *(int *)(producerSharedSource + 0x160) = passStampB + useCount + -1;
      (**(code **)(inst2Vtable + 0xc))(inst2,0,*(undefined4 *)(pass + 8));
    }
    else {
      operandOpcode = *(int *)(operandVReg[0x22] + 8);
      if (((operandOpcode == 0x12) || (operandOpcode == 0x9b)) || (operandOpcode == 0x9a)) {
        producerOperandIdx = 2;
        otherOperandIdx = 1;
        inst2 = operandVReg;
        goto loopSetOutputScale;
      }
      destRecordC = IRInst__getOperandRecord(inst,0);
      constMatchResultB = IRInst__sourceMatchesConstant(inst,2,*(undefined4 *)(destRecordC + 0x10),&constOne0);
      if (constMatchResultB == 0) {
        return 0;
      }
      if (*(int *)((int)inst + 0x124) == 1) {
        destRecordD = IRInst__getOperandRecord(inst,0);
        constMatchResultC = IRInst__sourceMatchesConstant(inst,3,*(undefined4 *)(destRecordD + 0x10),&constHalf0);
        if (constMatchResultC != 0) {
          return 0;
        }
      }
      newSource2 = 0;
      *(int *)(pass + 0x1b0) = *(int *)(pass + 0x1b0) + 1;
      sourceDef5 = IRInst__getOperandSource(inst,1);
      savedFieldb8 = *(uint *)((int)inst + 0xb8);
      operandRecord8 = IRInst__getOperandRecord(inst,1);
      operandSelect5 = *(undefined4 *)(operandRecord8 + 0x10);
      sourceDef = IRInst__getOperandSource(inst,3);
      savedFielde8 = *(uint *)((int)inst + 0xe8);
      operandRecord8 = IRInst__getOperandRecord(inst,3);
      negateOperand3Saved = *(uint *)((int)inst + 0xd0) & 1;
      operandSelect6 = *(undefined4 *)(operandRecord8 + 0x10);
      if ((*(uint *)((int)inst + 0x14) & 0x200) != 0) {
        newSource2 = IRInst__getOperandSource(inst,*(undefined4 *)((int)inst + 0x84));
      }
      useCountResult = IRInst__useCount(inst,pass);
      savedField120C = *(undefined4 *)((int)inst + 0x120);
      savedField124 = *(undefined4 *)((int)inst + 0x124);
      afterInst2 = *(int *)((int)inst + 4);
      operandRecord8 = IRInst__getOperandRecord(inst,0);
      instFlagsB = *(uint *)((int)inst + 0x14);
      operandSelect7 = *(undefined4 *)(operandRecord8 + 0x10);
      savedField98B = *(undefined4 *)((int)inst + 0x98);
      savedField94B = *(undefined4 *)((int)inst + 0x94);
      DList__unlink(inst);
      IRInst__reinitAsBinary(inst,0x12,*(undefined4 *)(pass + 8));
      *(undefined4 *)((int)inst + 0x94) = savedField94B;
      *(undefined4 *)((int)inst + 0x98) = savedField98B;
      if ((instFlagsB & 2) != 0) {
        *(uint *)((int)inst + 0x14) = *(uint *)((int)inst + 0x14) | 2;
      }
      *(undefined4 *)((int)inst + 0x9c) = operandSelect7;
      if (newSource2 != 0) {
        IRInst__setExtraOperandSource(inst,newSource2,0,*(undefined4 *)(pass + 8));
      }
      operandRecord1 = (int)inst + 0xa4;
      IRInst__setOperandSource(inst,1,sourceDef5,0,*(undefined4 *)(pass + 8));
      IROperand__setModifierBits(operandRecord1,1,savedFieldb8 & 1);
      IROperand__setModifierBits(operandRecord1,2,savedFieldb8 >> 1 & 1);
      operandRecord8 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord8 + 0x10) = operandSelect5;
      IRInst__setOperandSource(inst,2,sourceDef,0,*(undefined4 *)(pass + 8));
      IROperand__setModifierBits((int)inst + 0xbc,1,savedFielde8 & 1);
      IROperand__setModifierBits((int)inst + 0xbc,2,savedFielde8 >> 1 & 1);
      operandRecord8 = IRInst__getOperandRecord(inst,2);
      savedFieldb8 = *(uint *)((int)inst + 0xb8);
      *(undefined4 *)(operandRecord8 + 0x10) = operandSelect6;
      IROperand__setModifierBits(operandRecord1,1,negateOperand3Saved ^ savedFieldb8 & 1);
      *(undefined4 *)((int)inst + 0x120) = savedField120C;
      *(undefined4 *)((int)inst + 0x124) = savedField124;
      if (newSource2 != 0) {
        IRInst__setExtraOperandSource(inst,newSource2,0,*(undefined4 *)(pass + 8));
      }
      block = *(undefined4 *)(afterInst2 + 0x158);
      result = 1;
      *(int *)((int)inst + 0x160) = useCountResult + *(int *)(pass + 0x478);
      Block__insertInstAfter(block,afterInst2,inst);
    }
  }
  sourceDef8 = IRInst__getOperandSource(inst,1);
  if (*(int *)(*(int *)(sourceDef8 + 0x88) + 8) == 0x13) {
    producerOperandIdxB = 1;
    operandIndex4 = 2;
  }
  else {
    sourceDef8 = IRInst__getOperandSource(inst,2);
    if (*(int *)(*(int *)(sourceDef8 + 0x88) + 8) != 0x13) {
      return result;
    }
    producerOperandIdxB = 2;
    operandIndex4 = 1;
  }
  inst3 = (int *)IRInst__getOperandSource(inst,producerOperandIdxB);
  candidateSource = (int *)IRInst__getOperandSource(inst,operandIndex4);
  if ((producerOperandIdxB != 1) || (inst1 = candidateSource, *(int *)(candidateSource[0x22] + 8) != 0x13)) {
    inst1 = (int *)0x0;
  }
  useCountA = inst3[0x58] - *(int *)(pass + 0x478);
  if (useCountA < 0) {
    singleUse = false;
    multipleUses = false;
code_r0x00156484:
    useCountA = 0;
    swappedInst = inst3;
code_r0x001564cc:
    inst3 = swappedInst;
    useCountB = useCountA;
    if (!singleUse) goto code_r0x001564d0;
  }
  else {
    multipleUses = 1 < useCountA;
    singleUse = useCountA == 1;
    if (!multipleUses) goto code_r0x00156484;
    if (inst1 == (int *)0x0) {
      return result;
    }
    useCountB = inst1[0x58] - *(int *)(pass + 0x478);
    if (useCountB < 0) {
      useCountB = 0;
    }
    if (useCountB < useCountA) {
      multipleUses = 1 < useCountB;
      singleUse = useCountB == 1;
      producerOperandIdxB = 2;
      operandIndex4 = 1;
      swappedInst = inst1;
      inst1 = inst3;
      candidateSource = inst3;
      goto code_r0x001564cc;
    }
code_r0x001564d0:
    useCountA = 1;
    if (useCountB != 1) {
      return result;
    }
  }
  operandRecord6 = IRInst__getOperandRecord(inst,producerOperandIdxB);
  SelectWord__readMask(&readMaskB,*(undefined4 *)(operandRecord6 + 0x10));
  destRecordInst3 = IRInst__getOperandRecord(inst3,0);
  WriteMask__fromSelectWord(&writeMaskB,*(undefined4 *)(destRecordInst3 + 0x10));
  if ((((((readMaskB << 0x18 | (readMaskB >> 8 & 0xff) << 0x10 | (readMaskB >> 0x10 & 0xff) << 8 |
          readMaskB >> 0x18) <=
          (writeMaskB << 0x18 | (writeMaskB >> 8 & 0xff) << 0x10 | (writeMaskB >> 0x10 & 0xff) << 8 |
          writeMaskB >> 0x18)) && (writeMaskB == (writeMaskB & readMaskB))) && (inst3[0x48] == 0)) &&
      (inst3[0x49] == 0)) &&
     ((!multipleUses ||
      (((inst3[5] & 0x20000U) == 0 &&
       (((hasSingleUseResult = IRInst__hasSingleUse(inst,pass), hasSingleUseResult == 0 || (candidateSource[0x20] == 0)) ||
        ((flagBit0Result = RegKind__flagBit0(candidateSource[0x26]), flagBit0Result == 0 ||
         (((candidateSource[5] & 2U) != 0 || (vcall50Result = (**(code **)(*candidateSource + 0x50))(candidateSource), vcall50Result != 0))))
        )))))))) {
    vcall5cResult = (**(code **)(*candidateSource + 0x5c))(candidateSource);
    operandIndex5 = operandIndex4;
    if (vcall5cResult == 0) goto code_r0x00156744;
    operandVReg = (int *)IRInst__getOperandSource(inst3,1);
    vcall5cResult = (**(code **)(*operandVReg + 0x5c))();
    if (vcall5cResult == 0) {
      operandVReg = (int *)IRInst__getOperandSource(inst3,2);
      vcall5cResult = (**(code **)(*operandVReg + 0x5c))();
      if (vcall5cResult == 0) goto code_r0x00156744;
    }
  }
  if (inst1 == (int *)0x0) {
    return result;
  }
  if (useCountA != 1) {
    return result;
  }
  operandRecord = IRInst__getOperandRecord(inst,operandIndex4);
  SelectWord__readMask(&readMaskC,*(undefined4 *)(operandRecord + 0x10));
  operandRecord = IRInst__getOperandRecord(inst1,0);
  WriteMask__fromSelectWord(&writeMaskC,*(undefined4 *)(operandRecord + 0x10));
  if ((writeMaskC << 0x18 | (writeMaskC >> 8 & 0xff) << 0x10 | (writeMaskC >> 0x10 & 0xff) << 8 |
      writeMaskC >> 0x18) <
      (readMaskC << 0x18 | (readMaskC >> 8 & 0xff) << 0x10 | (readMaskC >> 0x10 & 0xff) << 8 |
      readMaskC >> 0x18)) {
    return result;
  }
  if (writeMaskC != (writeMaskC & readMaskC)) {
    return result;
  }
  if (inst1[0x48] != 0) {
    return result;
  }
  if (inst1[0x49] != 0) {
    return result;
  }
  operandVReg2 = (int *)IRInst__getOperandSource(inst,operandIndex4);
  vcall5cResult2 = (**(code **)(*operandVReg2 + 0x5c))();
  operandIndex5 = producerOperandIdxB;
  producerOperandIdxB = operandIndex4;
  inst3 = inst1;
  if (vcall5cResult2 != 0) {
    operandVReg = (int *)IRInst__getOperandSource(inst1,1);
    vcall5cResult3 = (**(code **)(*operandVReg + 0x5c))();
    if (vcall5cResult3 != 0) {
      return result;
    }
    operandVReg = (int *)IRInst__getOperandSource(inst1,2);
    vcall5cResult3 = (**(code **)(*operandVReg + 0x5c))();
    if (vcall5cResult3 != 0) {
      return result;
    }
  }
code_r0x00156744:
  operandSource = IRInst__getOperandSource(inst,operandIndex5);
  operandRecord4 = IRInst__getOperandRecord(inst,operandIndex5);
  operandSelect6 = *(undefined4 *)(operandRecord4 + 0x10);
  operandRecord4 = IRInst__getOperandRecord(inst,producerOperandIdxB);
  hasExtraSource = (*(uint *)((int)inst + 0x14) & 0x200) != 0;
  operandModBitsA = *(uint *)((int)inst + operandIndex5 * 0x18 + 0xa0);
  negateOperand3 = operandModBitsA & 1;
  absOperand3 = operandModBitsA >> 1 & 1;
  lastOperandBuf2 = 0;
  lastOperandBuf0 = 0;
  lastOperandBuf1 = 0;
  operandSelect3 = *(undefined4 *)(operandRecord4 + 0x10);
  savedField120B = *(undefined4 *)((int)inst + 0x120);
  savedField124B = *(undefined4 *)((int)inst + 0x124);
  if (hasExtraSource) {
    IRInst__readLastOperand(inst,&lastOperandBuf0);
  }
  useCount = IRInst__useCount(inst,pass);
  afterInst3 = *(int *)((int)inst + 4);
  operandRecord = IRInst__getOperandRecord(inst,0);
  operandSelect4 = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst3,2);
  operandSelect7 = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst3,1);
  operandModBitsB = *(uint *)((int)inst + producerOperandIdxB * 0x18 + 0xa0);
  negateOperand1 = operandModBitsB & 1;
  SelectWord__compose(&composedSelectA,*(undefined4 *)(operandRecord + 0x10),operandSelect3);
  SelectWord__compose(&composedSelectB,operandSelect7,operandSelect3);
  instFlagsC = *(uint *)((int)inst + 0x14);
  savedField98C = *(undefined4 *)((int)inst + 0x98);
  newInst = (void *)IRInst__create(0x14,*(undefined4 *)(pass + 8));
  if ((instFlagsC & 2) != 0) {
    *(uint *)((int)newInst + 0x14) = *(uint *)((int)newInst + 0x14) | 2;
  }
  *(undefined4 *)((int)newInst + 0xc) = *(undefined4 *)((int)inst + 0xc);
  *(undefined4 *)((int)newInst + 0x94) = *(undefined4 *)((int)newInst + 0x14c);
  *(undefined4 *)((int)newInst + 0x98) = savedField98C;
  *(undefined4 *)((int)newInst + 0x9c) = operandSelect4;
  *(undefined4 *)((int)newInst + 0x120) = savedField120B;
  *(undefined4 *)((int)newInst + 0x124) = savedField124B;
  sourceDef = IRInst__getOperandSource(inst3,1);
  setOperandSourceIfLegalResult3 = IRInst__setOperandSourceIfLegal(newInst,1,sourceDef,1,negateOperand1,*(undefined4 *)(pass + 8));
  sourceDef = IRInst__getOperandSource(inst3,2);
  setOperandSourceIfLegalResult2 = IRInst__setOperandSourceIfLegal(newInst,2,sourceDef,1,0,*(undefined4 *)(pass + 8));
  setOperandSourceIfLegalResult = IRInst__setOperandSourceIfLegal(newInst,3,operandSource,absOperand3,negateOperand3,*(undefined4 *)(pass + 8));
  operandRecord2 = IRInst__getOperandRecord(newInst,1);
  *(undefined4 *)(operandRecord2 + 0x10) = composedSelectA;
  operandRecord2 = IRInst__getOperandRecord(newInst,2);
  *(undefined4 *)(operandRecord2 + 0x10) = composedSelectB;
  operandRecord2 = IRInst__getOperandRecord(newInst,3);
  *(undefined4 *)(operandRecord2 + 0x10) = operandSelect6;
  if ((operandModBitsB & 2) == 0) {
    if (negateOperand1 == 0) {
      IROperand__setModifierBits((int)newInst + 0xa4,2,(uint)inst3[0x2e] >> 1 & 1);
      negateFlag = inst3[0x2e] & 1;
    }
    else {
      IROperand__setModifierBits((int)newInst + 0xa4,2,(uint)inst3[0x2e] >> 1 & 1);
      negateFlag = inst3[0x2e] & 1U ^ 1;
    }
    IROperand__setModifierBits((int)newInst + 0xa4,1,negateFlag);
    IROperand__setModifierBits((int)newInst + 0xbc,2,(uint)inst3[0x34] >> 1 & 1);
    IROperand__setModifierBits((int)newInst + 0xbc,1,inst3[0x34] & 1);
  }
  else {
    IROperand__setModifierBits((int)newInst + 0xa4,2,1);
    IROperand__setModifierBits((int)newInst + 0xa4,1,negateOperand1);
    IROperand__setModifierBits((int)newInst + 0xbc,2,1);
    IROperand__setModifierBits((int)newInst + 0xbc,1,0);
  }
  IROperand__setModifierBits((int)newInst + 0xd4,2,absOperand3);
  IROperand__setModifierBits((int)newInst + 0xd4,1,negateOperand3);
  if (hasExtraSource) {
    IRInst__setLastOperandFromRecord(newInst,&lastOperandBuf0,0,*(undefined4 *)(pass + 8));
  }
  *(int *)((int)newInst + 0x160) = useCount + *(int *)(pass + 0x478);
  if (setOperandSourceIfLegalResult != 0 && (setOperandSourceIfLegalResult2 != 0 && setOperandSourceIfLegalResult3 != 0)) {
    *(int *)(pass + 0x1b0) = *(int *)(pass + 0x1b0) + 1;
    sourceDef8 = IRInst__getOperandSource(inst3,1);
    if (*(int *)(pass + 0x478) < *(int *)(sourceDef8 + 0x160)) {
      *(int *)(sourceDef8 + 0x160) = *(int *)(sourceDef8 + 0x160) + 1;
    }
    else {
      *(int *)(sourceDef8 + 0x160) = *(int *)(pass + 0x478) + 1;
    }
    sourceDef8 = IRInst__getOperandSource(inst3,2);
    if (*(int *)(pass + 0x478) < *(int *)(sourceDef8 + 0x160)) {
      *(int *)(sourceDef8 + 0x160) = *(int *)(sourceDef8 + 0x160) + 1;
    }
    else {
      *(int *)(sourceDef8 + 0x160) = *(int *)(pass + 0x478) + 1;
    }
    DList__unlink(inst);
    _memcpy(inst,newInst,0x164);
    Block__insertInstAfter(*(undefined4 *)(afterInst3 + 0x158),afterInst3,inst);
    dropCounterAndDeleteIfUnusedResult = IRInst__dropCounterAndDeleteIfUnused(inst3,*(undefined4 *)(pass + 8));
    if (dropCounterAndDeleteIfUnusedResult == 0) {
      operandLoopIdx = 1;
      do {
        operandVReg = (int *)IRInst__getOperandSource(inst3,operandLoopIdx);
        vcall5cResult3 = (**(code **)(*operandVReg + 0x5c))();
        if (vcall5cResult3 == 0) {
          if (*(int *)(pass + 0x478) < operandVReg[0x58]) {
            operandVReg[0x58] = operandVReg[0x58] + 1;
          }
          else {
            operandVReg[0x58] = *(int *)(pass + 0x478) + 1;
          }
        }
        else {
          cloneResult = IRInst__clone(operandVReg,*(undefined4 *)(pass + 8),0);
          *(undefined4 *)(cloneResult + 0x98) = 0x31;
          *(undefined4 *)(cloneResult + 0x94) = *(undefined4 *)(cloneResult + 0x14c);
          IRInst__setOperandSource(newInst,1,cloneResult,0,*(undefined4 *)(pass + 8));
          Block__insertInstAfter(*(undefined4 *)(afterInst3 + 0x158),afterInst3,cloneResult);
          *(int *)(cloneResult + 0x160) = *(int *)(pass + 0x478) + 1;
          sourceDef3 = IRInst__getOperandSource(cloneResult,1);
          if (*(int *)(pass + 0x478) < *(int *)(sourceDef3 + 0x160)) {
            *(int *)(sourceDef3 + 0x160) = *(int *)(sourceDef3 + 0x160) + 1;
          }
          else {
            *(int *)(sourceDef3 + 0x160) = *(int *)(pass + 0x478) + 1;
          }
          if (1 < *(int *)(cloneResult + 0x84)) {
            sourceDef2 = IRInst__getOperandSource(cloneResult,2);
            if (*(int *)(pass + 0x478) < *(int *)(sourceDef2 + 0x160)) {
              *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
            }
            else {
              *(int *)(sourceDef2 + 0x160) = *(int *)(pass + 0x478) + 1;
            }
          }
        }
        moreComponents = operandLoopIdx != 2;
        operandLoopIdx = operandLoopIdx + 1;
      } while (moreComponents);
    }
  }
  return result;
}

/* Inst__destSelectsCompatible @ 0x156cb8 (144 bytes) */
int Inst__destSelectsCompatible(inst, inst2, pass)
  undefined4 inst;
  undefined4 inst2;
  int pass;
{
  int splitRgbAlphaEnabled;
  int operandRecord;
  undefined4 result;
  int operandSelect;
  int operandSelectB;
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  operandSelectB = *(int *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst2,0);
  operandSelect = *(int *)(operandRecord + 0x10);
  splitRgbAlphaEnabled = Compiler__isOptionEnabled(*(undefined4 *)(pass + 8),0x30);
  if (splitRgbAlphaEnabled == 0) {
loopSetResult:
    result = 1;
  }
  else {
    if (operandSelectB == DAT_001b0054) {
      if (operandSelectB == operandSelect) goto loopSetResult;
    }
    else if (DAT_001b0054 != operandSelect) goto loopSetResult;
    result = 0;
  }
  return result;
}

/* Inst__collapseAssociativeChain_00156d48 @ 0x156d48 (3576 bytes) */
int Inst__collapseAssociativeChain_00156d48(inst, pass, opcodeKind)
  int *inst;
  int pass;
  int opcodeKind;
{
  uint modifiersE;
  uint modifiersD;
  uint savedVregId;
  uint swappedOperandMods;
  int *vregSlot;
  int splatSelect;
  int maskedSelect;
  int defaultSelect;
  int composedSelect2;
  int operandFlagsOffset;
  int operandSelectD;
  int slotByteOffset;
  int operandSelect;
  int *operandSourceB;
  int countdown;
  int loopIndexB;
  int loopIndex;
  uint source2Flags2;
  uint source2Flags;
  uint source1Flags2;
  uint source1Flags;
  int destRegisterOffset2;
  int destRegisterOffset;
  int destRegister2;
  int destRegister;
  int *inst2;
  int *inst1;
  int operandIndex2;
  int operandIndex;
  int afterInst2;
  int afterInst;
  undefined4 sourceDef3;
  undefined4 sourceDef;
  int sourceDef2;
  int operandRecord;
  int operandRecord3;
  int operandRecord2;
  int operandRecord4;
  int *operandVReg;
  int *operandVReg2;
  bool moreComponents;
  uint instFlagsTmp;
  uint modifiersC;
  uint instFlagsSaved;
  uint instFlagsNew;
  uint modifiersF;
  int operandIdxOrResult;
  int operandRecordFold;
  int destRecordFold;
  int *inst3;
  int *elementPtr;
  int *chainA;
  undefined1 splatComponentResult;
  uint operandSwapIdx;
  undefined4 operandSelectE;
  int compilerCtx;
  undefined4 operandSelectF;
  undefined4 operandSelectG;
  undefined4 operandSelectH;
  undefined4 operandSelectI;
  int operandSelectB;
  int operandSelectC;
  int *chainEnd;
  int composedSelect1;
  int destSelect;
  int chainLength;
  int *chainEndInst;
  int counterSaveBuf;
  undefined4 counterSave2;
  undefined4 counterSave1;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_b0_buf [0x10];
  #define vecCapacity (*(uint *)(local_b0_buf + 0x00))
  #define vecCount (*(uint *)(local_b0_buf + 0x04))
  #define vecData (*(int *)(local_b0_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_b0_buf + 0x0c))
  int composedOutA;
  int composedOutB;
  undefined4 destWriteMask;
  int maskedDestSelect;
  undefined4 savedSrc3;
  uint savedSrc3Neg;
  uint savedSrc3Abs;
  int savedExtraSource;
  int savedSaturate;
  int savedScaleCode;
  int savedField150;
  int wasMad;
  int splatSelectA;
  int splatSelectB;
  int *counterSavePtr;
  
  chainLength = 0;
  compilerCtx = *(int *)(pass + 8);
  chainLength = ((int (*)())Inst__findDeepestChain)(inst,0,opcodeKind,pass,&chainEndInst,&chainLength);
  if (*(int *)(compilerCtx + 0x6ac) <= chainLength) {
    savedSrc3 = IRInst__getOperandSource(inst,3);
    savedSrc3Neg = inst[0x3a] & 1;
    savedSrc3Abs = (uint)inst[0x3a] >> 1 & 1;
    operandRecord = IRInst__getOperandRecord(inst,3);
    operandSelectE = *(undefined4 *)(operandRecord + 0x10);
    if (opcodeKind == 0x14) {
      savedSaturate = inst[0x48];
      savedExtraSource = 0;
      if ((inst[5] & 0x200U) != 0) {
        savedExtraSource = IRInst__getOperandSource(inst,inst[0x21]);
      }
      savedScaleCode = inst[0x49];
      sourceDef = IRInst__getOperandSource(inst,1);
      source1Flags = inst[0x2e];
      operandRecord = IRInst__getOperandRecord(inst,1);
      operandSelectI = *(undefined4 *)(operandRecord + 0x10);
      sourceDef3 = IRInst__getOperandSource(inst,2);
      source2Flags = inst[0x34];
      operandRecord = IRInst__getOperandRecord(inst,2);
      operandSelectH = *(undefined4 *)(operandRecord + 0x10);
      savedSrc3 = IRInst__getOperandSource(inst,3);
      savedSrc3Neg = inst[0x3a] & 1;
      savedSrc3Abs = (uint)inst[0x3a] >> 1 & 1;
      operandRecord = IRInst__getOperandRecord(inst,3);
      afterInst = inst[1];
      operandSelectE = *(undefined4 *)(operandRecord + 0x10);
      operandRecord = IRInst__getOperandRecord(inst,0);
      counterSavePtr = &counterSaveBuf;
      instFlagsNew = inst[5];
      operandSelect = *(int *)(operandRecord + 0x10);
      counterSave1 = 0;
      counterSaveBuf = 0;
      counterSave2 = 0;
      savedField150 = inst[0x54];
      destRegisterOffset = inst[0x26];
      IRInst__saveCounters(inst,counterSavePtr,0xffffffff);
      instFlagsSaved = inst[5];
      destRegister2 = inst[0x25];
      DList__unlink(inst);
      IRInst__reinitAsBinary(inst,0x13,*(undefined4 *)(pass + 8));
      if ((instFlagsNew & 0x4000) == 0) {
        instFlagsNew = inst[5] & 0xffffbfff;
        inst[5] = instFlagsNew;
      }
      else {
        instFlagsNew = inst[5] | 0x4000;
        inst[5] = instFlagsNew;
      }
      inst[0x25] = destRegister2;
      inst[0x26] = destRegisterOffset;
      if ((instFlagsSaved & 2) != 0) {
        inst[5] = instFlagsNew | 2;
      }
      inst[0x27] = operandSelect;
      opcodeKind = 0x13;
      IRInst__setOperandSource(inst,1,sourceDef,0,*(undefined4 *)(pass + 8));
      IROperand__setModifierBits(inst + 0x29,1,source1Flags & 1);
      IROperand__setModifierBits(inst + 0x29,2,source1Flags >> 1 & 1);
      operandRecord = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord + 0x10) = operandSelectI;
      IRInst__setOperandSource(inst,2,sourceDef3,0,*(undefined4 *)(pass + 8));
      IROperand__setModifierBits(inst + 0x2f,1,source2Flags & 1);
      IROperand__setModifierBits(inst + 0x2f,2,source2Flags >> 1 & 1);
      operandRecord = IRInst__getOperandRecord(inst,2);
      *(undefined4 *)(operandRecord + 0x10) = operandSelectH;
      IRInst__restoreCounters(inst,counterSavePtr);
      Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,inst);
      wasMad = 1;
    }
    else {
      wasMad = 0;
      savedField150 = 0;
      savedScaleCode = 0;
      savedSaturate = 0;
      savedExtraSource = 0;
    }
    operandRecord = IRInst__getOperandRecord(inst,0);
    loopIndex = 0;
    destRecordFold = *(int *)(operandRecord + 0x10);
    destSelect = destRecordFold;
    countdown = 4;
    do {
      inst1 = inst;
      if (*(char *)((int)&destSelect + loopIndex) == '\0') {
        splatSelectB = *(int *)(PTR_DAT_001e8b8c + loopIndex * 4);
        splatSelectA = *(int *)(PTR_DAT_001e8b64 + loopIndex * 4);
        break;
      }
      loopIndex = loopIndex + 1;
      countdown = countdown + -1;
    } while (countdown != 0);
    do {
      instFlagsTmp = inst1[5];
      inst1[5] = instFlagsTmp | 0x100000;
      operandIdxOrResult = ((instFlagsTmp & 0x4000) >> 0xe) + 1;
      operandVReg = (int *)IRInst__getOperandSource(inst1,operandIdxOrResult);
      if (opcodeKind != *(int *)(operandVReg[0x22] + 8)) break;
      operandRecord2 = IRInst__getOperandRecord(inst1,operandIdxOrResult);
      operandSelectB = *(int *)(operandRecord2 + 0x10);
      operandRecord2 = IRInst__getOperandRecord(operandVReg,1);
      operandSelectC = *(int *)(operandRecord2 + 0x10);
      SelectWord__compose(&composedOutA,operandSelectC,operandSelectB);
      composedSelect1 = composedOutA;
      if (operandSelectC != composedOutA) {
        operandRecord4 = IRInst__getOperandRecord(operandVReg,1);
        *(int *)(operandRecord4 + 0x10) = composedSelect1;
      }
      operandRecord2 = IRInst__getOperandRecord(operandVReg,2);
      operandSelectC = *(int *)(operandRecord2 + 0x10);
      SelectWord__compose(&composedOutB,operandSelectC,operandSelectB);
      composedSelect2 = composedOutB;
      if (operandSelectC != composedOutB) {
        operandRecord4 = IRInst__getOperandRecord(operandVReg,2);
        *(int *)(operandRecord4 + 0x10) = composedSelect2;
      }
      operandRecord2 = IRInst__getOperandRecord(operandVReg,0);
      if (*(int *)(operandRecord2 + 0x10) != destRecordFold) {
        operandVReg[0x27] = destSelect;
      }
      defaultSelect = DAT_001b004c;
      WriteMask__fromSelectWord(&destWriteMask,destSelect);
      SelectWord__maskUnused(&maskedDestSelect,defaultSelect,destWriteMask);
      maskedSelect = maskedDestSelect;
      if (operandSelectB != maskedDestSelect) {
        if (operandIdxOrResult == 0) {
          inst1[0x27] = maskedDestSelect;
        }
        else {
          operandIdxOrResult = IRInst__getOperandRecord(inst1,operandIdxOrResult);
          *(int *)(operandIdxOrResult + 0x10) = maskedSelect;
        }
      }
      inst1 = operandVReg;
    } while (operandVReg != chainEndInst);
    chainEnd = chainEndInst;
    inst1[5] = inst1[5] | 0x100000;
    vecArena = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
    vecCapacity = 2;
    vecCount = 0;
    vecData = Arena__alloc(vecArena,8);
    *(int *)(pass + 0x1c8) = *(int *)(pass + 0x1c8) + 1;
    chainA = inst;
    inst3 = inst;
    if (inst != chainEnd) {
      loopIndexB = 0;
      do {
        operandIdxOrResult = chainEnd[0x53];
        if (vecCount < vecCapacity) {
          slotByteOffset = vecCount * 4;
          vecCount = vecCount + 1;
          *(undefined4 *)(slotByteOffset + vecData) = 0;
          elementPtr = (int *)(slotByteOffset + vecData);
        }
        else {
          elementPtr = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
        }
        *elementPtr = operandIdxOrResult;
        chainEnd[0x53] = loopIndexB;
        loopIndexB = loopIndexB + 1;
        chainEnd = (int *)chainEnd[2];
      } while (inst != chainEnd);
    }
    for (; inst2 = chainEndInst, 2 < chainLength; chainLength = chainLength + -2) {
      operandSourceB = (int *)IRInst__getOperandSource(inst3,((uint)inst3[5] >> 0xe & 1) + 1);
      instFlagsTmp = inst3[5];
      operandFlagsOffset = 0xb0;
      if ((instFlagsTmp & 0x4000) == 0) {
        operandFlagsOffset = 0x98;
      }
      modifiersC = *(uint *)((int)inst3 + operandFlagsOffset + 0x20);
      operandFlagsOffset = 0xb0;
      if ((instFlagsTmp & 0x4000) == 0) {
        operandFlagsOffset = 0x98;
      }
      modifiersD = *(uint *)((int)inst3 + operandFlagsOffset + 0x20);
      operandRecord = IRInst__getOperandRecord(inst3,(instFlagsTmp >> 0xe & 1) + 1);
      operandSelectF = *(undefined4 *)(operandRecord + 0x10);
      operandVReg2 = (int *)IRInst__getOperandSource(operandSourceB,((uint)operandSourceB[5] >> 0xe & 1) + 1);
      instFlagsTmp = operandSourceB[5];
      operandFlagsOffset = 0xb0;
      if ((instFlagsTmp & 0x4000) == 0) {
        operandFlagsOffset = 0x98;
      }
      modifiersE = *(uint *)((int)operandSourceB + operandFlagsOffset + 0x20);
      operandFlagsOffset = 0xb0;
      if ((instFlagsTmp & 0x4000) == 0) {
        operandFlagsOffset = 0x98;
      }
      modifiersF = *(uint *)((int)operandSourceB + operandFlagsOffset + 0x20);
      operandRecord = IRInst__getOperandRecord(operandSourceB,(instFlagsTmp >> 0xe & 1) + 1);
      operandSelectI = *(undefined4 *)(operandRecord + 0x10);
      operandIdxOrResult = IRInst__getOperandSource(chainA,((uint)chainA[5] >> 0xe & 1 ^ 1) + 1);
      operandSwapIdx = (uint)chainA[5] >> 0xe & 1 ^ 1;
      swappedOperandMods = chainA[operandSwapIdx * 6 + 0x2e];
      operandRecord = IRInst__getOperandRecord(chainA,operandSwapIdx + 1);
      operandSelectG = *(undefined4 *)(operandRecord + 0x10);
      IRInst__setOperandSource(inst3,((uint)inst3[5] >> 0xe & 1) + 1,operandVReg2,0,compilerCtx);
      operandFlagsOffset = 0xb0;
      if ((inst3[5] & 0x4000U) == 0) {
        operandFlagsOffset = 0x98;
      }
      IROperand__setModifierBits((int)inst3 + operandFlagsOffset + 0xc,1,modifiersE & 1);
      operandFlagsOffset = 0xb0;
      if ((inst3[5] & 0x4000U) == 0) {
        operandFlagsOffset = 0x98;
      }
      IROperand__setModifierBits((int)inst3 + operandFlagsOffset + 0xc,2,modifiersF >> 1 & 1);
      operandRecord = IRInst__getOperandRecord(inst3,((uint)inst3[5] >> 0xe & 1) + 1);
      *(undefined4 *)(operandRecord + 0x10) = operandSelectI;
      IRInst__setOperandSource(chainA,((uint)chainA[5] >> 0xe & 1 ^ 1) + 1,operandSourceB,0,compilerCtx);
      IROperand__setModifierBits(chainA + ((uint)chainA[5] >> 0xe & 1 ^ 1) * 6 + 0x29,1,modifiersC & 1);
      IROperand__setModifierBits(chainA + ((uint)chainA[5] >> 0xe & 1 ^ 1) * 6 + 0x29,2,modifiersD >> 1 & 1);
      operandRecord = IRInst__getOperandRecord(chainA,((uint)chainA[5] >> 0xe & 1 ^ 1) + 1);
      *(undefined4 *)(operandRecord + 0x10) = operandSelectF;
      IRInst__setOperandSource(operandSourceB,((uint)operandSourceB[5] >> 0xe & 1) + 1,operandIdxOrResult,0,compilerCtx);
      operandFlagsOffset = 0xb0;
      if ((operandSourceB[5] & 0x4000U) == 0) {
        operandFlagsOffset = 0x98;
      }
      IROperand__setModifierBits((int)operandSourceB + operandFlagsOffset + 0xc,1,swappedOperandMods & 1);
      operandFlagsOffset = 0xb0;
      if ((operandSourceB[5] & 0x4000U) == 0) {
        operandFlagsOffset = 0x98;
      }
      IROperand__setModifierBits((int)operandSourceB + operandFlagsOffset + 0xc,2,swappedOperandMods >> 1 & 1);
      operandRecord = IRInst__getOperandRecord(operandSourceB,((uint)operandSourceB[5] >> 0xe & 1) + 1);
      *(undefined4 *)(operandRecord + 0x10) = operandSelectG;
      if (operandSourceB[0x53] < *(int *)(operandIdxOrResult + 0x14c)) {
        DList__unlink(operandSourceB);
        Block__insertInstBefore(chainA[0x56],chainA,operandSourceB);
      }
      chainA = operandSourceB;
      inst3 = operandVReg2;
    }
    for (; inst != inst2; inst2 = (int *)inst2[2]) {
      savedVregId = inst2[0x53];
      if (savedVregId < vecCapacity) {
        if (vecCount <= savedVregId) {
          _memset(vecCount * 4 + vecData,0,(savedVregId - vecCount) * 4 + 4);
          vecCount = savedVregId + 1;
        }
        vregSlot = (int *)(savedVregId * 4 + vecData);
      }
      else {
        vregSlot = (int *)Vector__elementRefGrow(&vecCapacity,savedVregId);
      }
      inst2[0x53] = *vregSlot;
      if ((inst2[5] & 0x100000U) != 0) {
        operandRecord = IRInst__getOperandRecord(inst2,1);
        operandRecordFold = SelectWord__isSplat(*(undefined4 *)(operandRecord + 0x10));
        if (operandRecordFold == 0) {
          sourceDef2 = IRInst__getOperandSource(inst2,1);
          if ((*(uint *)(sourceDef2 + 0x14) & 0x100000) != 0) {
            sourceDef = IRInst__getOperandSource(inst2,1);
            operandRecord = IRInst__getOperandRecord(sourceDef,0);
            operandRecordFold = SelectWord__isSingleComponentConstant(*(undefined4 *)(operandRecord + 0x10));
            if (operandRecordFold != 0) goto setOperandRecord;
          }
        }
        else {
setOperandRecord:
          operandRecord = IRInst__getOperandRecord(inst2,2);
          operandRecordFold = SelectWord__isSplat(*(undefined4 *)(operandRecord + 0x10));
          if (operandRecordFold == 0) {
            sourceDef2 = IRInst__getOperandSource(inst2,2);
            if ((*(uint *)(sourceDef2 + 0x14) & 0x100000) != 0) {
              sourceDef = IRInst__getOperandSource(inst2,2);
              operandRecord = IRInst__getOperandRecord(sourceDef,0);
              operandRecordFold = SelectWord__isSingleComponentConstant(*(undefined4 *)(operandRecord + 0x10));
              if (operandRecordFold != 0) goto setOperandIdxOrResult;
            }
          }
          else {
setOperandIdxOrResult:
            operandIdxOrResult = ((uint)inst2[5] >> 0xe & 1) + 1;
            inst2[0x27] = splatSelectA;
            operandRecord = IRInst__getOperandRecord(inst2,operandIdxOrResult);
            if (*(int *)(operandRecord + 0x10) == DAT_001b004c) {
              if (operandIdxOrResult == 0) {
                inst2[0x27] = splatSelectB;
              }
              else {
                operandRecord = IRInst__getOperandRecord(inst2,operandIdxOrResult);
                *(int *)(operandRecord + 0x10) = splatSelectB;
              }
            }
          }
        }
        for (operandIndex = 1; operandIdxOrResult = (**(code **)(*inst2 + 0x14))(inst2), operandIndex <= operandIdxOrResult;
            operandIndex = operandIndex + 1) {
          operandIdxOrResult = IRInst__getOperandSource(inst2,operandIndex);
          if ((*(uint *)(operandIdxOrResult + 0x14) & 0x100000) != 0) {
            operandRecord3 = IRInst__getOperandRecord(operandIdxOrResult,0);
            operandSelectF = *(undefined4 *)(operandRecord3 + 0x10);
            operandIdxOrResult = SelectWord__isSingleComponentConstant(operandSelectF);
            if (operandIdxOrResult != 0) {
              splatComponentResult = SelectWord__splatComponent(operandSelectF);
              operandIdxOrResult = 0;
              counterSaveBuf = DAT_001b0050;
              do {
                operandRecord2 = IRInst__getOperandRecord(inst2,0);
                if (*(char *)(operandIdxOrResult + operandRecord2 + 0x10) != '\x01') {
                  *(undefined1 *)((int)&counterSaveBuf + operandIdxOrResult) = splatComponentResult;
                }
                splatSelect = counterSaveBuf;
                moreComponents = operandIdxOrResult != 3;
                operandIdxOrResult = operandIdxOrResult + 1;
              } while (moreComponents);
              if (operandIndex == 0) {
                inst2[0x27] = counterSaveBuf;
              }
              else {
                operandIdxOrResult = IRInst__getOperandRecord(inst2,operandIndex);
                *(int *)(operandIdxOrResult + 0x10) = splatSelect;
              }
            }
          }
        }
      }
    }
    for (operandIndex2 = 1; operandIdxOrResult = (**(code **)(*inst + 0x14))(inst), operandIndex2 <= operandIdxOrResult;
        operandIndex2 = operandIndex2 + 1) {
      operandIdxOrResult = IRInst__getOperandSource(inst,operandIndex2);
      if ((*(uint *)(operandIdxOrResult + 0x14) & 0x100000) != 0) {
        operandRecord3 = IRInst__getOperandRecord(operandIdxOrResult,0);
        operandSelectF = *(undefined4 *)(operandRecord3 + 0x10);
        operandIdxOrResult = SelectWord__isSingleComponentConstant(operandSelectF);
        if (operandIdxOrResult != 0) {
          splatComponentResult = SelectWord__splatComponent(operandSelectF);
          operandIdxOrResult = 0;
          counterSaveBuf = DAT_001b0050;
          do {
            operandRecord2 = IRInst__getOperandRecord(inst,0);
            if (*(char *)(operandIdxOrResult + operandRecord2 + 0x10) != '\x01') {
              *(undefined1 *)((int)&counterSaveBuf + operandIdxOrResult) = splatComponentResult;
            }
            splatSelect = counterSaveBuf;
            moreComponents = operandIdxOrResult != 3;
            operandIdxOrResult = operandIdxOrResult + 1;
          } while (moreComponents);
          if (operandIndex2 == 0) {
            inst[0x27] = counterSaveBuf;
          }
          else {
            operandIdxOrResult = IRInst__getOperandRecord(inst,operandIndex2);
            *(int *)(operandIdxOrResult + 0x10) = splatSelect;
          }
        }
      }
    }
    for (; inst != chainEndInst; chainEndInst = (int *)chainEndInst[2]) {
      if ((chainEndInst[5] & 0x100000U) != 0) {
        chainEndInst[5] = chainEndInst[5] & 0xffefffff;
      }
    }
    inst[5] = inst[5] & 0xffefffff;
    if (wasMad != 0) {
      sourceDef = IRInst__getOperandSource(inst,1);
      source1Flags2 = inst[0x2e];
      operandRecord = IRInst__getOperandRecord(inst,1);
      operandSelectI = *(undefined4 *)(operandRecord + 0x10);
      sourceDef3 = IRInst__getOperandSource(inst,2);
      source2Flags2 = inst[0x34];
      operandRecord = IRInst__getOperandRecord(inst,2);
      operandSelectH = *(undefined4 *)(operandRecord + 0x10);
      afterInst2 = inst[1];
      operandRecord = IRInst__getOperandRecord(inst,0);
      instFlagsSaved = inst[5];
      operandSelectD = *(int *)(operandRecord + 0x10);
      counterSave1 = 0;
      counterSaveBuf = 0;
      counterSave2 = 0;
      destRegisterOffset2 = inst[0x26];
      destRegister = inst[0x25];
      IRInst__saveCounters(inst,&counterSaveBuf,0xffffffff);
      DList__unlink(inst);
      IRInst__reinitAsTrinary(inst,0x14,*(undefined4 *)(pass + 8));
      IRInst__restoreCounters(inst,&counterSaveBuf);
      inst[0x49] = 0;
      inst[0x25] = destRegister;
      inst[0x26] = destRegisterOffset2;
      inst[0x48] = 0;
      if ((instFlagsSaved & 2) != 0) {
        inst[5] = inst[5] | 2;
      }
      inst[0x27] = operandSelectD;
      inst[0x54] = savedField150;
      IRInst__setOperandSource(inst,1,sourceDef,0,*(undefined4 *)(pass + 8));
      IROperand__setModifierBits(inst + 0x29,1,source1Flags2 & 1);
      IROperand__setModifierBits(inst + 0x29,2,source1Flags2 >> 1 & 1);
      operandRecord = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord + 0x10) = operandSelectI;
      IRInst__setOperandSource(inst,2,sourceDef3,0,*(undefined4 *)(pass + 8));
      IROperand__setModifierBits(inst + 0x2f,1,source2Flags2 & 1);
      IROperand__setModifierBits(inst + 0x2f,2,source2Flags2 >> 1 & 1);
      operandRecord = IRInst__getOperandRecord(inst,2);
      *(undefined4 *)(operandRecord + 0x10) = operandSelectH;
      IRInst__setOperandSource(inst,3,savedSrc3,0,*(undefined4 *)(pass + 8));
      IROperand__setModifierBits(inst + 0x35,1,savedSrc3Neg);
      IROperand__setModifierBits(inst + 0x35,2,savedSrc3Abs);
      operandRecord = IRInst__getOperandRecord(inst,3);
      *(undefined4 *)(operandRecord + 0x10) = operandSelectE;
      inst[0x48] = savedSaturate;
      inst[0x49] = savedScaleCode;
      if (savedExtraSource != 0) {
        IRInst__setExtraOperandSource(inst,savedExtraSource,0,compilerCtx);
      }
      Block__insertInstAfter(*(undefined4 *)(afterInst2 + 0x158),afterInst2,inst);
    }
    Arena__free(vecArena,vecData);
  }
  return inst;
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* Inst__distributeSplatOperand_00157b78 @ 0x157b78 (1172 bytes) */
int Inst__distributeSplatOperand_00157b78(inst, operandIndex, pass)
  int inst;
  uint operandIndex;
  int pass;
{
  undefined4 operandSelectD;
  int isSplatResultC;
  int setOperandSourceIfLegalResultB;
  int isSplatResultB;
  int setOperandSourceIfLegalResult;
  int isSplatResult;
  int loopIndexB;
  int loopIndex;
  uint negateFlag;
  uint operandIndex3;
  int afterInst;
  undefined4 cloneResult;
  int sourceDef;
  int operandRecord4;
  int operandRecord2;
  int operandRecord3;
  bool moreComponents;
  uint selectLowBitsA;
  uint selectLowBitsB;
  uint negateFlag2;
  undefined4 laneMapWord;
  int afterInst2;
  int *chosenSource;
  int *operandVReg;
  int *operandVReg2;
  int vcall48Or4cResult;
  int callResult;
  int otherOperandRecordBase;
  int callResult2;
  undefined4 cloneResult2;
  int callResult3;
  int operandRecord;
  uint operandIndex2;
  undefined4 operandSelectB;
  undefined4 operandSelectC;
  undefined4 selectBytesValue;
  undefined4 producerSelectConst;
  undefined4 selectBytes;
  undefined4 operandSelect;
  undefined4 selectBytesCopy;
  undefined4 laneMapBytes [5];
  
  operandIndex3 = ~operandIndex & 3;
  sourceDef = IRInst__getOperandSource(inst,operandIndex);
  chosenSource = (int *)IRInst__getOperandSource(sourceDef,1);
  operandVReg = (int *)IRInst__getOperandSource(sourceDef,2);
  operandVReg2 = (int *)IRInst__getOperandSource(inst,operandIndex3);
  operandRecord3 = IRInst__getOperandRecord(inst,operandIndex3);
  operandSelectB = *(undefined4 *)(operandRecord3 + 0x10);
  operandRecord3 = IRInst__getOperandRecord(sourceDef,1);
  operandSelectC = *(undefined4 *)(operandRecord3 + 0x10);
  operandRecord3 = IRInst__getOperandRecord(sourceDef,2);
  selectBytes = *(undefined4 *)(operandRecord3 + 0x10);
  isSplatResult = SelectWord__isSplat(operandSelectB);
  isSplatResultB = SelectWord__isSplat(operandSelectC);
  isSplatResultC = SelectWord__isSplat(selectBytes);
  if ((isSplatResultB == 0) && (isSplatResultC == 0)) {
    return;
  }
  if (isSplatResult == 0) {
    return;
  }
  callResult = IRInst__sourceReadMaskAvoidsDestKind1(inst,operandIndex,sourceDef,pass);
  if (callResult == 0) {
    return;
  }
  if (isSplatResultB == 0) {
    if (isSplatResultC != 0) {
loopSetOperandIndex2:
      operandIndex2 = 1;
      selectBytes = operandSelectC;
      goto setVcall48Or4cResult;
    }
  }
  else if (isSplatResultC != 0) {
    vcall48Or4cResult = (**(code **)(*operandVReg + 0x48))(operandVReg);
    if ((vcall48Or4cResult != 0) || (vcall48Or4cResult = (**(code **)(*operandVReg + 0x4c))(operandVReg), vcall48Or4cResult != 0))
    goto loopSetOperandIndex2;
    vcall48Or4cResult = (**(code **)(*chosenSource + 0x48))(chosenSource);
    if ((vcall48Or4cResult == 0) && (vcall48Or4cResult = (**(code **)(*chosenSource + 0x4c))(chosenSource), vcall48Or4cResult == 0)) {
      return;
    }
  }
  operandIndex2 = 2;
  chosenSource = operandVReg;
setVcall48Or4cResult:
  vcall48Or4cResult = (**(code **)(*operandVReg2 + 0x48))(operandVReg2);
  if ((vcall48Or4cResult != 0) || (vcall48Or4cResult = (**(code **)(*operandVReg2 + 0x4c))(operandVReg2), vcall48Or4cResult != 0)) {
    cloneResult = IRInst__clone(sourceDef,*(undefined4 *)(pass + 8),0);
    cloneResult2 = IRInst__clone(inst,*(undefined4 *)(pass + 8),0);
    otherOperandRecordBase = inst + operandIndex3 * 0x18 + 0x80;
    negateFlag = *(uint *)(operandIndex2 * 0x18 + sourceDef + 0xa0) & 1;
    negateFlag2 = *(uint *)(otherOperandRecordBase + 0x20) & 1;
    setOperandSourceIfLegalResult = IRInst__setOperandSourceIfLegal(inst,operandIndex3,chosenSource,1,negateFlag,*(undefined4 *)(pass + 8));
    loopIndexB = 0;
    IROperand__setModifierBits(otherOperandRecordBase + 0xc,1,negateFlag);
    operandRecord2 = IRInst__getOperandRecord(inst,operandIndex);
    operandSelect = *(undefined4 *)(operandRecord2 + 0x10);
    selectBytesCopy = selectBytes;
    do {
      operandRecord2 = IRInst__getOperandRecord(inst,0);
      if (*(char *)(loopIndexB + operandRecord2 + 0x10) != '\x01') {
        *(undefined1 *)((int)&selectBytes + loopIndexB) =
             *(undefined1 *)((int)laneMapBytes + (*(byte *)((int)&operandSelect + loopIndexB) - 4));
      }
      moreComponents = loopIndexB != 3;
      loopIndexB = loopIndexB + 1;
    } while (moreComponents);
    loopIndex = 0;
    laneMapBytes[0] = DAT_001b005c;
    do {
      operandRecord4 = IRInst__getOperandRecord(inst,0);
      if (*(char *)(loopIndex + operandRecord4 + 0x10) == '\x01') {
        *(undefined1 *)((int)laneMapBytes + loopIndex) = 4;
        *(undefined1 *)((int)&selectBytes + loopIndex) = 4;
      }
      selectBytesValue = selectBytes;
      moreComponents = loopIndex != 3;
      loopIndex = loopIndex + 1;
    } while (moreComponents);
    operandRecord2 = IRInst__getOperandRecord(inst,operandIndex3);
    laneMapWord = laneMapBytes[0];
    *(undefined4 *)(operandRecord2 + 0x10) = selectBytesValue;
    operandRecord2 = IRInst__getOperandRecord(inst,operandIndex);
    producerSelectConst = DAT_001b0058;
    *(undefined4 *)(operandRecord2 + 0x10) = laneMapWord;
    *(undefined4 *)(sourceDef + 0x9c) = producerSelectConst;
    setOperandSourceIfLegalResultB = IRInst__setOperandSourceIfLegal(sourceDef,operandIndex2,operandVReg2,1,negateFlag2,*(undefined4 *)(pass + 8));
    IROperand__setModifierBits(operandIndex2 * 0x18 + sourceDef + 0x8c,1,negateFlag2);
    operandRecord4 = IRInst__getOperandRecord(sourceDef,~operandIndex2 & 3);
    operandSelectD = *(undefined4 *)(operandRecord4 + 0x10);
    callResult2 = SelectWord__firstUsedComponent(operandSelectB);
    callResult3 = SelectWord__firstUsedComponent(operandSelectD);
    selectLowBitsA = DAT_001b0050 & 0xffffff;
    selectLowBitsB = DAT_001b0050 & 0xffffff;
    operandRecord = IRInst__getOperandRecord(sourceDef,operandIndex2);
    *(uint *)(operandRecord + 0x10) = callResult2 << 0x18 | selectLowBitsA;
    operandRecord4 = IRInst__getOperandRecord(sourceDef,~operandIndex2 & 3);
    *(uint *)(operandRecord4 + 0x10) = callResult3 << 0x18 | selectLowBitsB;
    if (setOperandSourceIfLegalResultB == 0 || setOperandSourceIfLegalResult == 0) {
      afterInst = *(int *)(sourceDef + 4);
      DList__unlink(sourceDef);
      IRInst__copyBodyFrom(sourceDef,cloneResult);
      Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,sourceDef);
      afterInst2 = *(int *)(inst + 4);
      DList__unlink(inst);
      IRInst__copyBodyFrom(inst,cloneResult2);
      Block__insertInstAfter(*(undefined4 *)(afterInst2 + 0x158),afterInst2,inst);
      return;
    }
    DList__unlink(sourceDef);
    Block__insertInstBefore(*(undefined4 *)(inst + 0x158),inst,sourceDef);
    *(int *)(pass + 0x1c0) = *(int *)(pass + 0x1c0) + 1;
  }
  return;
}

/* Inst__canShiftTargetField @ 0x15800c (600 bytes) */
int Inst__canShiftTargetField(ctx, inst, targetFieldDelta, unusedArg4, laneMask, program)
  undefined4 ctx;
  int *inst;
  int targetFieldDelta;
  undefined4 unusedArg4;
  uint laneMask;
  int program;
{
  int vcall64Result;
  int countdown;
  int operandRecord;
  int operandIndexOrCheck;
  int hoistCheck;
  int destRecordCheck;
  int operandCountResult;
  int *laneByteCursorOrTarget;
  uint writeMaskOut [4];
  
LAB_0015802c:
  do {
    vcall64Result = (**(code **)(*inst + 100))(inst);
    if (vcall64Result != 0) {
      for (operandIndexOrCheck = 1; operandCountResult = (**(code **)(*inst + 0x14))(inst), operandIndexOrCheck <= operandCountResult;
          operandIndexOrCheck = operandIndexOrCheck + 1) {
        if ((((inst[operandIndexOrCheck * 6 + 0x28] & 1U) != 0) || ((inst[operandIndexOrCheck * 6 + 0x28] & 2U) != 0)) ||
           (operandCountResult = IRInst__isSourceSelectIdentity(inst,operandIndexOrCheck), operandCountResult == 0)) goto setHoistCheck;
      }
      if ((inst[0x48] == 0) && (inst[0x49] == 0)) {
        if (((inst[0x20] != 0) &&
            ((operandIndexOrCheck = RegKind__flagBit0(inst[0x26]), operandIndexOrCheck != 0 && ((inst[5] & 2U) == 0)))) &&
           (operandIndexOrCheck = (**(code **)(*inst + 0x50))(inst), operandIndexOrCheck == 0)) {
          countdown = 4;
          laneByteCursorOrTarget = inst;
          do {
            if ((uint)(*(byte *)(laneByteCursorOrTarget + 0x27) - 2) < 2) goto setHoistCheck;
            laneByteCursorOrTarget = (int *)((int)laneByteCursorOrTarget + 1);
            countdown = countdown + -1;
          } while (countdown != 0);
        }
        IRInst__getOperandRecord(inst,0);
        destRecordCheck = IRInst__operandKindClass(inst,0);
        if ((((destRecordCheck == 0) && ((inst[5] & 2U) == 0)) && ((inst[5] & 0x200U) == 0)) &&
           (destRecordCheck = IRInst__hasSingleUse(inst,program), destRecordCheck != 0)) {
          inst = (int *)IRInst__getOperandSource(inst,1);
          goto LAB_0015802c;
        }
      }
    }
setHoistCheck:
    hoistCheck = (**(code **)(*inst + 0x24))(inst);
    if (((hoistCheck == 0) || (hoistCheck = IRInst__hasSingleUse(inst,program), hoistCheck == 0)) ||
       ((inst[0x48] != 0 ||
        (laneByteCursorOrTarget = *(int **)(*(int *)(program + 8) + 0x30c),
        hoistCheck = (**(code **)(*laneByteCursorOrTarget + 0xfc))(laneByteCursorOrTarget,targetFieldDelta + inst[0x49],inst), hoistCheck == 0)))
       ) {
      return 0;
    }
    do {
      if ((inst[5] & 0x200U) == 0) {
        return 1;
      }
      inst = (int *)IRInst__getOperandSource(inst,inst[0x21]);
      operandRecord = IRInst__getOperandRecord(inst,0);
      WriteMask__fromSelectWord(writeMaskOut,*(undefined4 *)(operandRecord + 0x10));
    } while ((laneMask & writeMaskOut[0]) == 0);
  } while( true );
}

/* Inst__collapseAlgebraic_00158264 @ 0x158264 (828 bytes) */
int Inst__collapseAlgebraic_00158264(inst, operandIndex3, inst2, program)
  int inst;
  int operandIndex3;
  int inst2;
  int program;
{
  uint source2Flags;
  int afterInst;
  int operandIndex2;
  int operandIndex;
  undefined4 readMaskResult;
  int uniformSourceConstant;
  int hasSingleUse;
  int operandRecord2;
  int sourceDef;
  int operandRecord;
  bool moreComponents;
  int instOpcodeOrResult;
  int *operandVReg;
  undefined4 saturate;
  int *a0;
  int precheckResult;
  int operandIdxNext;
  int newOutputScale;
  int vcallfcCheck;
  int *target;
  uint inst2ModBitsA;
  uint instFlags;
  undefined4 resultScaleCode;
  undefined4 destRegisterOffset;
  undefined4 destRegister;
  undefined4 operandSelect;
  undefined4 operandSelectB;
  undefined4 operandSelectC;
  undefined4 compilerCtx;
  int hasSingleUseResultB;
  int destRecordOperandVReg;
  int useCountInst2;
  int vcallfcCheckB;
  int exponentFound;
  int foldAllowed;
  int opcodeKind;
  bool kindBelowAdd;
  bool negateLiteral;
  double literalMagnitude;
  int outputScaleDelta;
  undefined1 exponentPad [4];
  float literalValue;
  int lastOperandBuf0;
  int lastOperandSourceSave;
  int lastOperandBuf2;
  uint inst2ReadMask;
  uint operandVRegWriteMask;
  uint negateFlag;
  uint absFlag2;
  uint absFlag;
  undefined4 newSource;
  
  compilerCtx = *(undefined4 *)(program + 8);
  opcodeKind = *(int *)(*(int *)(inst2 + 0x88) + 8);
  if (inst == 0) {
    instOpcodeOrResult = 0;
  }
  else {
    instOpcodeOrResult = *(int *)(*(int *)(inst + 0x88) + 8);
  }
  if (opcodeKind == 0x14) {
    operandRecord2 = IRInst__getOperandRecord(inst2,0);
    uniformSourceConstant = IRInst__getUniformSourceConstant(inst2,2,*(undefined4 *)(operandRecord2 + 0x10),exponentPad);
    if (uniformSourceConstant == 0) goto loopSetInst2;
    operandVReg = (int *)IRInst__getOperandSource(inst2,1);
    operandRecord = IRInst__getOperandRecord(inst2,0);
    operandSelectC = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(inst2,operandIndex3);
    readMaskResult = SelectWord__readMask(&inst2ReadMask,*(undefined4 *)(operandRecord + 0x10));
    literalMagnitude = (double)literalValue;
    negateLiteral = literalMagnitude < 0.0;
    if (negateLiteral) {
      literalMagnitude = -literalMagnitude;
    }
    exponentFound = ((undefined4 (*)())tryOutputScaleExponent)(readMaskResult,&outputScaleDelta,literalMagnitude);
    if (((exponentFound != 0) && (outputScaleDelta != 0)) &&
       (foldAllowed = ((int (*)())Inst__canShiftTargetField)(inst2,operandVReg,outputScaleDelta,operandSelectC,inst2ReadMask,program), foldAllowed != 0)) {
      opcodeKind = 0x14;
      instOpcodeOrResult = 0;
      do {
        a0 = operandVReg;
        if (*(int *)(operandVReg[0x22] + 8) == 0x13) {
          operandIndex = 1;
          do {
            a0 = (int *)IRInst__getOperandSource(operandVReg,operandIndex);
            precheckResult = (**(code **)(*a0 + 0x24))(a0);
            if (((precheckResult != 0) && (precheckResult = IRInst__hasSingleUse(a0,program), precheckResult != 0)) &&
               ((a0[0x48] == 0 &&
                (((a0[5] & 0x200U) == 0 &&
                 (target = *(int **)(*(int *)(program + 8) + 0x30c),
                 vcallfcCheck = (**(code **)(*target + 0xfc))(target,a0[0x49] + outputScaleDelta,inst2),
                 vcallfcCheck != 0)))))) break;
            moreComponents = operandIndex != 2;
            operandIndex = operandIndex + 1;
            a0 = operandVReg;
          } while (moreComponents);
        }
        target = *(int **)(*(int *)(program + 8) + 0x30c);
        newOutputScale = a0[0x49] + outputScaleDelta;
        vcallfcCheckB = (**(code **)(*target + 0xfc))(target,newOutputScale,inst2);
        if (vcallfcCheckB != 0) {
          *(int *)(program + 0x1c4) = *(int *)(program + 0x1c4) + 1;
          a0[0x49] = newOutputScale;
          if (instOpcodeOrResult == 0) {
            newSource = IRInst__getOperandSource(inst2,3);
            operandRecord = IRInst__getOperandRecord(inst2,1);
            operandSelect = *(undefined4 *)(operandRecord + 0x10);
            operandRecord = IRInst__getOperandRecord(inst2,3);
            inst2ModBitsA = *(uint *)(inst2 + 0xe8);
            saturate = *(undefined4 *)(inst2 + 0x120);
            resultScaleCode = *(undefined4 *)(inst2 + 0x124);
            negateFlag = (uint)negateLiteral ^ *(uint *)(inst2 + 0xb8) & 1;
            absFlag = *(uint *)(inst2 + 0xb8) >> 1 & 1;
            absFlag2 = inst2ModBitsA >> 1 & 1;
            instFlags = *(uint *)(inst2 + 0x14);
            operandSelectB = *(undefined4 *)(operandRecord + 0x10);
            lastOperandBuf0 = instOpcodeOrResult;
            lastOperandSourceSave = instOpcodeOrResult;
            lastOperandBuf2 = instOpcodeOrResult;
            if ((instFlags & 0x200) != 0) {
              IRInst__readLastOperand(inst2,&lastOperandBuf0);
              instFlags = *(uint *)(inst2 + 0x14);
            }
            destRegisterOffset = *(undefined4 *)(inst2 + 0x98);
            destRegister = *(undefined4 *)(inst2 + 0x94);
            useCountInst2 = IRInst__useCount(inst2,program);
            afterInst = *(int *)(inst2 + 4);
            DList__unlink(inst2);
            if (0 < *(int *)(inst2 + 0x84)) {
              operandIndex2 = 1;
              do {
                operandIdxNext = operandIndex2 + 1;
                IRInst__setOperandSource(inst2,operandIndex2,0,0,compilerCtx);
                operandIndex2 = operandIdxNext;
              } while (operandIdxNext <= *(int *)(inst2 + 0x84));
            }
            IRInst__reinitAsBinary(inst2,0x12,*(undefined4 *)(program + 8));
            *(undefined4 *)(inst2 + 0x94) = destRegister;
            *(undefined4 *)(inst2 + 0x98) = destRegisterOffset;
            if ((instFlags & 2) != 0) {
              *(uint *)(inst2 + 0x14) = *(uint *)(inst2 + 0x14) | 2;
            }
            *(undefined4 *)(inst2 + 0x9c) = operandSelectC;
            IRInst__setOperandSource(inst2,1,operandVReg,0,compilerCtx);
            IRInst__setOperandSource(inst2,2,newSource,0,compilerCtx);
            operandRecord = IRInst__getOperandRecord(inst2,1);
            *(undefined4 *)(operandRecord + 0x10) = operandSelect;
            operandRecord = IRInst__getOperandRecord(inst2,2);
            *(undefined4 *)(operandRecord + 0x10) = operandSelectB;
            IROperand__setModifierBits(inst2 + 0xa4,2,absFlag);
            IROperand__setModifierBits(inst2 + 0xbc,2,absFlag2);
            IROperand__setModifierBits(inst2 + 0xa4,1,negateFlag);
            IROperand__setModifierBits(inst2 + 0xbc,1,inst2ModBitsA & 1);
            *(undefined4 *)(inst2 + 0x120) = saturate;
            *(undefined4 *)(inst2 + 0x124) = resultScaleCode;
            if (lastOperandSourceSave != 0) {
              IRInst__setLastOperandFromRecord(inst2,&lastOperandBuf0,0,compilerCtx);
            }
            opcodeKind = 0x12;
            Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,inst2);
            instOpcodeOrResult = 1;
            *(int *)(inst2 + 0x160) = useCountInst2 + *(int *)(program + 0x478);
          }
        }
        do {
          if ((operandVReg[5] & 0x200U) == 0) goto setKindBelowAdd;
          operandVReg = (int *)IRInst__getOperandSource(operandVReg,operandVReg[0x21]);
          destRecordOperandVReg = IRInst__getOperandRecord(operandVReg,0);
          WriteMask__fromSelectWord(&operandVRegWriteMask,*(undefined4 *)(destRecordOperandVReg + 0x10));
        } while ((inst2ReadMask & operandVRegWriteMask) == 0);
      } while( true );
    }
    opcodeKind = 0x14;
    instOpcodeOrResult = 0;
    kindBelowAdd = false;
loopCheckKindBelowAdd:
    if (kindBelowAdd) {
      return instOpcodeOrResult;
    }
    if (0x14 < opcodeKind) {
      return instOpcodeOrResult;
    }
    sourceDef = IRInst__getOperandSource(inst2,1);
    if ((((*(int *)(*(int *)(sourceDef + 0x88) + 8) == 0x13) &&
         (hasSingleUseResultB = IRInst__hasSingleUse(sourceDef,program), hasSingleUseResultB != 0)) && (*(int *)(sourceDef + 0x120) == 0))
       && ((*(int *)(sourceDef + 0x124) == 0 && ((*(uint *)(inst2 + 0xb8) & 2) == 0)))) {
      ((int (*)())Inst__distributeSplatOperand_00157b78)(inst2,1,program);
    }
    sourceDef = IRInst__getOperandSource(inst2,2);
    if (*(int *)(*(int *)(sourceDef + 0x88) + 8) != 0x13) {
      return instOpcodeOrResult;
    }
    hasSingleUse = IRInst__hasSingleUse(sourceDef,program);
    if (hasSingleUse == 0) {
      return instOpcodeOrResult;
    }
    if (*(int *)(sourceDef + 0x120) != 0) {
      return instOpcodeOrResult;
    }
    if (*(int *)(sourceDef + 0x124) != 0) {
      return instOpcodeOrResult;
    }
    source2Flags = *(uint *)(inst2 + 0xd0);
  }
  else {
    if (opcodeKind == 0x12) {
      if (instOpcodeOrResult != 0x12) {
loopSetInst2:
        inst2 = ((int (*)())Inst__collapseAssociativeChain_00156d48)(inst2,program,opcodeKind);
        if (((*(uint *)(inst + 0x14) & 0x200) == 0) || (operandIndex3 != *(int *)(inst + 0x84))) {
          IRInst__setOperandSource(inst,operandIndex3,inst2,0,compilerCtx);
        }
        else {
          IRInst__setExtraOperandSource(inst,inst2,0,compilerCtx);
        }
        goto setInstOpcodeOrResult;
      }
      instOpcodeOrResult = 0;
    }
    else {
      if (opcodeKind == 0x13) {
        if ((instOpcodeOrResult == 0x14) || (instOpcodeOrResult == 0x13)) {
          opcodeKind = 0x13;
          instOpcodeOrResult = 0;
          kindBelowAdd = false;
          goto loopCheckKindBelowAdd;
        }
        goto loopSetInst2;
      }
setInstOpcodeOrResult:
      instOpcodeOrResult = 0;
setKindBelowAdd:
      kindBelowAdd = opcodeKind < 0x12;
      if (opcodeKind != 0x12) goto loopCheckKindBelowAdd;
    }
    sourceDef = IRInst__getOperandSource(inst2,1);
    if (((((*(int *)(*(int *)(sourceDef + 0x88) + 8) == 0x12) &&
          (hasSingleUseResultB = IRInst__hasSingleUse(sourceDef,program), hasSingleUseResultB != 0)) && (*(int *)(sourceDef + 0x120) == 0))
        && ((*(int *)(sourceDef + 0x124) == 0 && ((*(uint *)(inst2 + 0xb8) & 2) == 0)))) &&
       (((*(uint *)(inst2 + 0xd0) & 2) != 0 &&
        (((*(uint *)(sourceDef + 0xb8) & 2) == 0 && ((*(uint *)(sourceDef + 0xd0) & 2) == 0)))))) {
      ((int (*)())Inst__distributeSplatOperand_00157b78)(inst2,1,program);
    }
    sourceDef = IRInst__getOperandSource(inst2,2);
    if (*(int *)(*(int *)(sourceDef + 0x88) + 8) != 0x12) {
      return instOpcodeOrResult;
    }
    hasSingleUse = IRInst__hasSingleUse(sourceDef,program);
    if (hasSingleUse == 0) {
      return instOpcodeOrResult;
    }
    if (*(int *)(sourceDef + 0x120) != 0) {
      return instOpcodeOrResult;
    }
    if (*(int *)(sourceDef + 0x124) != 0) {
      return instOpcodeOrResult;
    }
    if ((*(uint *)(inst2 + 0xb8) & 2) != 0) {
      return instOpcodeOrResult;
    }
    if ((*(uint *)(inst2 + 0xd0) & 2) == 0) {
      return instOpcodeOrResult;
    }
    if ((*(uint *)(sourceDef + 0xb8) & 2) != 0) {
      return instOpcodeOrResult;
    }
    source2Flags = *(uint *)(sourceDef + 0xd0);
  }
  if ((source2Flags & 2) == 0) {
    ((int (*)())Inst__distributeSplatOperand_00157b78)(inst2,2,program);
  }
  return instOpcodeOrResult;
}

