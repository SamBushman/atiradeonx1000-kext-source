#include "decls.h"

/* ValueKey__canonicalizeCommutativeOperands @ 0x1733a0 (156 bytes) */
int ValueKey__canonicalizeCommutativeOperands(ctx)
  int ctx;
{
  int flagBit0Result;
  int laneRowCursor;
  int loopIndex;
  int loopRemaining;
  
  flagBit0Result = OpcodeTraits__flagBit0(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                       *(undefined4 *)(ctx + 0x238));
  if (flagBit0Result != 0) {
    loopRemaining = 4;
    laneRowCursor = ctx;
    loopIndex = ctx;
    do {
      if (*(char *)(loopIndex + 0x228) != '\0') {
        if (*(int *)(laneRowCursor + 0x178) < *(int *)(laneRowCursor + 0x188)) {
          return 0;
        }
        if (*(int *)(laneRowCursor + 0x188) < *(int *)(laneRowCursor + 0x178)) {
          ValueKey__swapSources12(*(undefined4 *)(ctx + 0xb0),ctx + 0x210,
                       *(undefined4 *)(ctx + 0x238));
          return 1;
        }
      }
      loopIndex = loopIndex + 1;
      laneRowCursor = laneRowCursor + 4;
      loopRemaining = loopRemaining + -1;
    } while (loopRemaining != 0);
  }
  return 0;
}

/* ValueKey__markRegisterLiveInBlock @ 0x17343c (304 bytes) */
int ValueKey__markRegisterLiveInBlock(ctx, block)
  int ctx;
  int block;
{
  int vcall18Result;
  int liveSetWordRef;
  int instOrProgramRef;
  int *a0;
  uint registerId;
  
  a0 = *(int **)(*(int *)(ctx + 0xb0) + 0x8c);
  vcall18Result = (**(code **)(*a0 + 0x18))(a0,block);
  if (vcall18Result != 0) {
    instOrProgramRef = *(int *)(ctx + 0xb0);
    registerId = a0[7];
    liveSetWordRef = *(int *)(block + 0x128);
    if ((((*(int *)(*(int *)(instOrProgramRef + 0x88) + 8) == 0x12) && (*(int *)(instOrProgramRef + 0x120) == 0)) &&
        ((*(uint *)(instOrProgramRef + 0x14) & 0x200) == 0)) &&
       (((*(uint *)(instOrProgramRef + 0xb8) & 1) != 0 && ((*(uint *)(instOrProgramRef + 0xd0) & 1) == 0)))) {
      instOrProgramRef = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
      *(int *)(instOrProgramRef + 0xa8) = *(int *)(instOrProgramRef + 0xa8) + 1;
      IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,1,0);
      IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xbc,1,1);
      liveSetWordRef = (registerId >> 3 & 0x1ffffffc) + liveSetWordRef;
      *(uint *)(*(int *)(ctx + 0xb0) + 0x14) =
           *(uint *)(*(int *)(ctx + 0xb0) + 0x14) | 0x200000;
      *(uint *)(liveSetWordRef + 8) = 1 << (registerId & 0x1f) | *(uint *)(liveSetWordRef + 8);
      return;
    }
    liveSetWordRef = (registerId >> 3 & 0x1ffffffc) + liveSetWordRef;
    *(uint *)(liveSetWordRef + 8) =
         (-2 << (registerId & 0x1f) | 0xfffffffeU >> 0x20 - (registerId & 0x1f)) & *(uint *)(liveSetWordRef + 8);
  }
  return;
}

/* ValueKey__allRowsUniform @ 0x17356c (176 bytes) */
int ValueKey__allRowsUniform(ctx)
  int ctx;
{
  int callResult;
  int loopIndex;
  
  callResult = OpcodeTraits__flagBit7(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                       *(undefined4 *)(ctx + 0x238));
  if (callResult == 0) {
    loopIndex = 1;
    callResult = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0));
    if (callResult != 0) {
      while( true ) {
        callResult = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0));
        if (callResult < loopIndex) {
          return 1;
        }
        callResult = ((int (*)())ValueKey__rowLanesAllEqual)(ctx,loopIndex);
        if (callResult == 0) break;
        loopIndex = loopIndex + 1;
      }
    }
  }
  return 0;
}

/* IRInst__isCndFloatOp @ 0x17361c (28 bytes) */
int IRInst__isCndFloatOp(inst)
  int inst;
{
  return *(int *)(*(int *)(inst + 0x88) + 8) - 0x24U < 3;
}

/* ValueKey__eliminateTrivialInst @ 0x173638 (284 bytes) */
int ValueKey__eliminateTrivialInst(ctx)
  int ctx;
{
  int inst;
  int operandRecord;
  code *removeFn;
  int compilerRef;
  int *producerInst;
  
  inst = *(int *)(ctx + 0xb0);
  if (*(int *)(*(int *)(inst + 0x88) + 8) == 0x77) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    if (*(int *)(operandRecord + 0x10) == DAT_001b01b4) {
      *(uint *)(*(int *)(ctx + 0xb0) + 0x14) =
           *(uint *)(*(int *)(ctx + 0xb0) + 0x14) & 0xfffffff7;
      producerInst = *(int **)(ctx + 0xb0);
      compilerRef = *(int *)(ctx + 0x238);
      removeFn = *(code **)(*producerInst + 0xc);
      goto LAB_00173718;
    }
    inst = *(int *)(ctx + 0xb0);
  }
  if ((((*(uint *)(inst + 0x14) & 2) == 0) || (*(int *)(inst + 0x98) != 0x3b)) ||
     (*(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0x334) != 0)) {
    return 0;
  }
  *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) & 0xffffffef;
  compilerRef = *(int *)(ctx + 0x238);
  if ((*(uint *)(*(int *)(compilerRef + 0x6c4) + 0x30) & 0x4000) == 0) {
    Program__removeInst(*(int *)(compilerRef + 0x6c4),*(undefined4 *)(ctx + 0xb0));
    compilerRef = *(int *)(ctx + 0x238);
  }
  producerInst = *(int **)(ctx + 0xb0);
  removeFn = *(code **)(*producerInst + 0xc);
LAB_00173718:
  (*removeFn)(producerInst,0,compilerRef);
  *(uint *)(*(int *)(ctx + 0xb0) + 0x14) = *(uint *)(*(int *)(ctx + 0xb0) + 0x14) | 0x400;
  return 1;
}

/* ValueKey__tryMergeDestWith @ 0x173754 (280 bytes) */
int ValueKey__tryMergeDestWith(ctx, otherKey)
  int ctx;
  int otherKey;
{
  int countdown;
  int loopIndex;
  int operandRecord;
  int inst;
  int currentProgram;
  int operandRecord2;
  undefined4 result;
  undefined4 otherDestSelect;
  undefined4 keyDestSelect [6];
  
  inst = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),9);
  if (((inst == 0) ||
      (*(int *)(*(int *)(ctx + 0x238) + 0x658) <=
       *(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0xa8))) ||
     (inst = *(int *)(otherKey + 0xb0), (*(uint *)(inst + 0x14) & 1) == 0)) {
loopSetResult:
    result = 0;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,0);
    otherDestSelect = *(undefined4 *)(operandRecord + 0x10);
    operandRecord2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    loopIndex = 0;
    keyDestSelect[0] = *(undefined4 *)(operandRecord2 + 0x10);
    countdown = 4;
    do {
      if ((*(char *)((int)keyDestSelect + loopIndex) == '\0') &&
         (*(char *)((int)keyDestSelect + loopIndex + -4) == '\x01')) goto loopSetResult;
      loopIndex = loopIndex + 1;
      countdown = countdown + -1;
    } while (countdown != 0);
    currentProgram = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
    *(int *)(currentProgram + 0xa8) = *(int *)(currentProgram + 0xa8) + 1;
    currentProgram = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
    *(int *)(currentProgram + 0x140) = *(int *)(currentProgram + 0x140) + 1;
    ValueKey__rewriteAsMovOfValueKey(ctx,inst,&DAT_001b01bc,0);
    result = 1;
  }
  return result;
}

/* ValueKey__fillSourceLaneUsage @ 0x17386c (204 bytes) */
int ValueKey__fillSourceLaneUsage(ctx)
  int ctx;
{
  int callResult2;
  undefined4 inst2;
  int *keyInstPtr;
  undefined4 inst;
  int operandIdx;
  int callResult;
  undefined4 currentProgram;
  int laneUsageCursor;
  undefined4 sourceLaneMaskOut [4];
  
  keyInstPtr = *(int **)(ctx + 0xb0);
  if (*(int *)(keyInstPtr[0x22] + 8) == 0x8e) {
    inst = (**(code **)(*keyInstPtr + 0x7c))(keyInstPtr);
    callResult2 = IRInst__allSourcesDefined(inst);
    if (callResult2 == 0) {
      return;
    }
    keyInstPtr = *(int **)(ctx + 0xb0);
  }
  operandIdx = 1;
  laneUsageCursor = ctx;
  while( true ) {
    callResult = (**(code **)(*keyInstPtr + 0x14))(keyInstPtr);
    if (callResult < operandIdx) break;
    inst2 = *(undefined4 *)(ctx + 0xb0);
    currentProgram = *(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4);
    callResult = IRInst__getOperandRecord(inst2,0);
    IRInst__computeSourceLaneMask(sourceLaneMaskOut,inst2,operandIdx,currentProgram,*(undefined4 *)(callResult + 0x10));
    keyInstPtr = *(int **)(ctx + 0xb0);
    *(undefined4 *)(laneUsageCursor + 0x228) = sourceLaneMaskOut[0];
    operandIdx = operandIdx + 1;
    laneUsageCursor = laneUsageCursor + 4;
  }
  return;
}

/* ValueKey__init @ 0x173938 (136 bytes) */
int ValueKey__init(key, inst, compiler)
  undefined4 *key;
  undefined4 inst;
  undefined4 compiler;
{
  undefined4 *loopPtr;
  int loopRemaining;
  
  loopRemaining = 4;
  key[0x2c] = inst;
  key[0x8e] = compiler;
  loopPtr = key;
  do {
    loopPtr[8] = 0;
    loopPtr[4] = 0;
    *loopPtr = 0;
    loopPtr[0x1c] = 0;
    loopPtr[0x18] = 0;
    loopPtr[0x14] = 0;
    loopPtr[0x28] = 0;
    loopPtr[0x24] = 0;
    loopPtr[0x20] = 0;
    loopPtr[0xc] = 0;
    loopPtr[0x10] = 0;
    loopPtr = loopPtr + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  _memset(key + 0x2d,0,0x15c);
  return ((int (*)())ValueKey__fillSourceLaneUsage)(key);
}

/* ValueKey__initCopy @ 0x1739c0 (136 bytes) */
int ValueKey__initCopy(key, inst, compiler)
  undefined4 *key;
  undefined4 inst;
  undefined4 compiler;
{
  undefined4 *loopPtr;
  int loopRemaining;
  
  loopRemaining = 4;
  key[0x2c] = inst;
  key[0x8e] = compiler;
  loopPtr = key;
  do {
    loopPtr[8] = 0;
    loopPtr[4] = 0;
    *loopPtr = 0;
    loopPtr[0x1c] = 0;
    loopPtr[0x18] = 0;
    loopPtr[0x14] = 0;
    loopPtr[0x28] = 0;
    loopPtr[0x24] = 0;
    loopPtr[0x20] = 0;
    loopPtr[0xc] = 0;
    loopPtr[0x10] = 0;
    loopPtr = loopPtr + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  _memset(key + 0x2d,0,0x15c);
  return ((int (*)())ValueKey__fillSourceLaneUsage)(key);
}

/* IRInst__allOperandsSplat @ 0x173a48 (176 bytes) */
int IRInst__allOperandsSplat(inst, compiler)
  int *inst;
  undefined4 compiler;
{
  int callResult;
  int loopIndex;
  
  callResult = OpcodeTraits__flagBit7(*(undefined4 *)(inst[0x22] + 8),compiler);
  if (callResult == 0) {
    loopIndex = 1;
    callResult = (**(code **)(*inst + 0x14))(inst);
    if (callResult != 0) {
      while( true ) {
        callResult = (**(code **)(*inst + 0x14))(inst);
        if (callResult < loopIndex) {
          return 1;
        }
        callResult = IRInst__getOperandRecord(inst,loopIndex);
        callResult = SelectWord__isSplat(*(undefined4 *)(callResult + 0x10));
        if (callResult == 0) break;
        loopIndex = loopIndex + 1;
      }
    }
  }
  return 0;
}

/* ValueKey__laneFlagsAllowDest @ 0x173af8 (160 bytes) */
int ValueKey__laneFlagsAllowDest(ctx, laneFlags)
  int ctx;
  int *laneFlags;
{
  int loopIndex;
  bool moreComponents;
  int callResult;
  int operandRecord;
  undefined4 destSelect [9];
  
  if ((*(int *)(*(int *)(ctx + 0xb0) + 0x120) != 0) &&
     (callResult = OpcodeTraits__flag1WithoutFlag7(*(undefined4 *)(ctx + 0x238),*(int *)(ctx + 0xb0)), callResult != 0))
  {
    loopIndex = 0;
    do {
      operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      destSelect[0] = *(undefined4 *)(operandRecord + 0x10);
      if ((*(char *)((int)destSelect + loopIndex) == '\0') && (*laneFlags != 0)) {
        return;
      }
      moreComponents = loopIndex != 3;
      laneFlags = laneFlags + 1;
      loopIndex = loopIndex + 1;
    } while (moreComponents);
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x120) = 0;
  }
  return;
}

/* Program__eliminateRedundantInst @ 0x173b98 (324 bytes) */
int Program__eliminateRedundantInst(program, inst, block, pass)
  undefined4 program;
  int *inst;
  undefined4 block;
  int pass;
{
  undefined4 removed;
  int registerCheck;
  int staleArg4;
  undefined4 staleArg7;
  undefined4 staleArg8;
  
  if (*(int *)(inst[0x22] + 8) == 0x8e) {
    staleArg4 = pass;
    Block__recordDefinition(block,inst[0x23],program);
    (**(code **)(*inst + 0xc))
              (inst,0,*(undefined4 *)(pass + 8),staleArg4,staleArg7,staleArg8,*(code **)(*inst + 0xc));
    removed = 1;
    inst[5] = inst[5] | 0x400;
    *(int *)(pass + 0x150) = *(int *)(pass + 0x150) + 1;
  }
  else if (((inst[5] & 8U) == 0) && ((inst[5] & 0x10U) == 0)) {
    staleArg4 = pass;
    if ((((inst[0x20] != 0) && (registerCheck = RegKind__flagBit0(inst[0x26]), registerCheck != 0)) &&
        ((inst[5] & 2U) == 0)) && (registerCheck = (**(code **)(*inst + 0x50))(inst), registerCheck == 0))
    {
      Block__recordDefinition(block,inst[0x23],program);
    }
    (**(code **)(*inst + 0xc))
              (inst,0,*(undefined4 *)(pass + 8),staleArg4,staleArg7,staleArg8,*(code **)(*inst + 0xc));
    removed = 1;
    inst[5] = inst[5] | 0x400;
    *(int *)(pass + 0x14c) = *(int *)(pass + 0x14c) + 1;
  }
  else {
    removed = 0;
  }
  return removed;
}

/* ValueKey__rewriteAsSwizzleMov @ 0x173cdc (308 bytes) */
int ValueKey__rewriteAsSwizzleMov(ctx, inst)
  int ctx;
  int inst;
{
  int isOptionEnabled;
  int producerInst;
  int *userSlot;
  undefined4 changed;
  int programStats;
  uint vectorFilledCount;
  uint userTopIndex;
  uint *vector;
  undefined4 swizzleWord [4];
  undefined4 swizzleOut [4];
  
  isOptionEnabled = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),8);
  if ((isOptionEnabled == 0) ||
     (*(int *)(*(int *)(ctx + 0x238) + 0x658) <=
      *(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0xa8))) {
    changed = 0;
  }
  else {
    producerInst = *(int *)(inst + 0xb0);
    if ((*(uint *)(producerInst + 0x14) & 1) == 0) {
      vector = *(uint **)(*(int *)(producerInst + 0x8c) + 0x2c);
      vectorFilledCount = vector[1];
      userTopIndex = vectorFilledCount - 1;
      if (userTopIndex < *vector) {
        if (vectorFilledCount <= userTopIndex) {
          _memset(vectorFilledCount * 4 + vector[2],0,(userTopIndex - vectorFilledCount) * 4 + 4);
          vector[1] = vectorFilledCount;
        }
        userSlot = (int *)(userTopIndex * 4 + vector[2]);
      }
      else {
        userSlot = (int *)Vector__elementRefGrow(vector,userTopIndex);
      }
      producerInst = *(int *)(*userSlot + 0xb0);
    }
    ValueKey__computeSwizzleTo(swizzleOut,ctx,inst);
    swizzleWord[0] = swizzleOut[0];
    programStats = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
    *(int *)(programStats + 0xa8) = *(int *)(programStats + 0xa8) + 1;
    programStats = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
    *(int *)(programStats + 0x13c) = *(int *)(programStats + 0x13c) + 1;
    ValueKey__rewriteAsMovOfValueKey(ctx,producerInst,swizzleWord,0);
    changed = 1;
  }
  return changed;
}

/* Compiler__valueNumberForExpr @ 0x173e10 (268 bytes) */
int Compiler__valueNumberForExpr(compiler, exprKey)
  int compiler;
  undefined4 exprKey;
{
  undefined4 arenaAt378;
  undefined4 *exprRecord;
  undefined4 *exprAllocation;
  int *recordVectorSlot;
  uint vectorFilledCount;
  undefined4 nextNegativeValueNumberResult;
  uint *vector;
  
  *(undefined4 *)(*(int *)(compiler + 0x3f0) + 4) = 0;
  **(undefined4 **)(compiler + 0x3f0) = exprKey;
  exprRecord = (undefined4 *)
           HashTable__find(*(undefined4 *)(compiler + 0x3e4),*(undefined4 *)(compiler + 0x3f0));
  if (exprRecord == (undefined4 *)0x0) {
    arenaAt378 = *(undefined4 *)(compiler + 0x378);
    exprAllocation = (undefined4 *)Arena__alloc(arenaAt378,0x2c);
    exprRecord = exprAllocation + 1;
    *exprAllocation = arenaAt378;
    exprAllocation[1] = exprKey;
    exprAllocation[5] = 4;
    exprAllocation[8] = 0;
    exprAllocation[2] = 0;
    *(undefined1 *)(exprAllocation + 3) = 0;
    *(undefined1 *)((int)exprAllocation + 0xd) = 0;
    exprAllocation[4] = 0;
    exprAllocation[7] = 0;
    nextNegativeValueNumberResult = Compiler__nextNegativeValueNumber(compiler);
    exprAllocation[2] = nextNegativeValueNumberResult;
    HashTable__insert(*(undefined4 *)(compiler + 0x3e4),exprRecord);
    HashTable__insert(*(undefined4 *)(compiler + 0x3e0),exprRecord);
    vector = *(uint **)(compiler + 0x3d8);
    vectorFilledCount = vector[1];
    if (vectorFilledCount < *vector) {
      _memset(vectorFilledCount * 4 + vector[2],0,4);
      recordVectorSlot = (int *)(vectorFilledCount * 4 + vector[2]);
      vector[1] = vectorFilledCount + 1;
    }
    else {
      recordVectorSlot = (int *)Vector__elementRefGrow(vector,vectorFilledCount);
    }
    *recordVectorSlot = (int)exprRecord;
  }
  return exprRecord;
}

/* ValueKey__fill @ 0x173f1c (1680 bytes) */
int ValueKey__fill(ctx)
  int ctx;
{
  uint vecCountB;
  uint sourceComponent;
  uint topIndex;
  uint *modifierWords;
  int *laneValueCursor;
  int *laneValueCursor2;
  undefined4 *operandLaneValues;
  int instWord50;
  int instWord4d;
  int operandIdx;
  int sourceKey;
  int valueNumber;
  int countdownB;
  int sourceValueNumber;
  int instWord4f;
  int instWord4c;
  int laneByteOffset;
  int countdown;
  int laneIdxB;
  int operandSlot;
  int flagBit0Result;
  int vcall30Result;
  int instWord51;
  int vcall78Result;
  int vcall74Result;
  int fun172fb8Result;
  int vcall5cResult;
  int instWord4e;
  int laneWordCursor;
  int laneIdx;
  int keyInst;
  int operandCountCall;
  int flagBit9Result;
  int flagBit2Result;
  int vcall7cResult;
  int defFieldIndex;
  undefined8 operandSource;
  bool moreComponents;
  dword *operandIndex2;
  bool moreLanes;
  undefined4 *sourceLanePtr;
  undefined4 staleArg4;
  int operandCountLoop;
  int *topSlot;
  int operandRecord;
  undefined4 *exprRecord;
  undefined4 retR4;
  undefined4 retR4B;
  dword *staleArg5;
  undefined4 staleArg6;
  undefined4 staleArg7;
  int laneKeyBase;
  dword sourceKeyB;
  dword *operandIndex;
  uint vecCount;
  int *keyInstPtr;
  uint topIndexB;
  uint *sourceKeyVec;
  char *laneActiveFlagPtr;
  undefined8 vcall14Result;
  undefined4 destSelect [4];
  undefined4 absApplied;
  undefined4 negApplied;
  undefined4 absAppliedB;
  undefined4 negAppliedB [3];
  
  keyInstPtr = *(int **)(ctx + 0xb0);
  *(undefined4 *)(ctx + 0xb4) = *(undefined4 *)(keyInstPtr[0x22] + 8);
  if (keyInstPtr[0x20] != 0) {
    flagBit0Result = RegKind__flagBit0(keyInstPtr[0x26]);
    if (((flagBit0Result == 0) || ((keyInstPtr[5] & 2U) != 0)) ||
       (flagBit0Result = (**(code **)(*keyInstPtr + 0x50))(keyInstPtr), flagBit0Result != 0)) {
      keyInstPtr = *(int **)(ctx + 0xb0);
    }
    else {
      keyInstPtr = *(int **)(ctx + 0xb0);
      if ((keyInstPtr[5] & 0x40U) == 0) {
        *(undefined4 *)(ctx + 0xb8) = 0;
        *(undefined4 *)(ctx + 0xbc) = 0;
        goto storeCtx;
      }
    }
    *(int *)(ctx + 0xbc) = keyInstPtr[0x25];
    *(int *)(ctx + 0xb8) = keyInstPtr[0x26];
  }
storeCtx:
  *(int *)(ctx + 0xc0) = keyInstPtr[0x48];
  *(int *)(ctx + 0xc4) = keyInstPtr[0x49];
  defFieldIndex = 1;
  laneKeyBase = ctx;
  while( true ) {
    operandCountLoop = (**(code **)(*keyInstPtr + 0x14))(keyInstPtr);
    if (operandCountLoop < defFieldIndex) break;
    staleArg4 = IRInst__getDefiningField128(*(undefined4 *)(ctx + 0xb0),defFieldIndex);
    keyInstPtr = *(int **)(ctx + 0xb0);
    *(undefined4 *)(laneKeyBase + 0x1bc) = staleArg4;
    defFieldIndex = defFieldIndex + 1;
    laneKeyBase = laneKeyBase + 4;
  }
  vcall7cResult = (**(code **)(**(int **)(ctx + 0xb0) + 0x7c))(*(int **)(ctx + 0xb0));
  if (vcall7cResult == 0) {
    flagBit2Result = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                         *(undefined4 *)(ctx + 0x238));
    if (flagBit2Result != 0) {
      operandIndex = ((unsigned char *)0x0);
      flagBit9Result = OpcodeTraits__flagBit9(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(ctx + 0x238));
      if (flagBit9Result == 0) {
        while( true ) {
          operandIndex = (dword *)((int)operandIndex + 1);
          operandCountCall = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0));
          staleArg4 = retR4B;
          if (operandCountCall < (int)operandIndex) break;
          keyInst = *(int *)(ctx + 0xb0);
          sourceKeyVec = *(uint **)(*(int *)((int)operandIndex * 0x18 + keyInst + 0x8c) + 0x2c);
          vecCount = sourceKeyVec[1];
          topIndexB = vecCount - 1;
          if (topIndexB < *sourceKeyVec) {
            if (vecCount <= topIndexB) {
              _memset(vecCount * 4 + sourceKeyVec[2],0,(topIndexB - vecCount) * 4 + 4);
              sourceKeyVec[1] = vecCount;
              keyInst = *(int *)(ctx + 0xb0);
            }
            staleArg5 = (dword *)(topIndexB * 4 + sourceKeyVec[2]);
          }
          else {
            staleArg5 = (dword *)Vector__elementRefGrow(sourceKeyVec,topIndexB);
            keyInst = *(int *)(ctx + 0xb0);
          }
          sourceKeyB = *staleArg5;
          keyInst = IRInst__getOperandRecord(keyInst,operandIndex);
          destSelect[0] = *(undefined4 *)(keyInst + 0x10);
          laneValueCursor = (int *)((int)operandIndex * 0x10 + ctx + 0x168);
          modifierWords = (uint *)((int)operandIndex * 0x20 + ctx + 200);
          laneIdx = 0;
          do {
            if (*(byte *)((int)destSelect + laneIdx) != 4) {
              valueNumber = *(int *)((uint)*(byte *)((int)destSelect + laneIdx) * 4 + sourceKeyB + 0x20);
              if (valueNumber < 0) {
                exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),valueNumber);
                IRInst__applyAbsModifier(&absApplied,*(undefined4 *)(ctx + 0xb0),operandIndex,*exprRecord);
                staleArg5 = operandIndex;
                staleArg6 = absApplied;
                IRInst__applyNegateModifier(&negApplied,*(undefined4 *)(ctx + 0xb0),operandIndex,absApplied);
                valueNumber = ((int (*)())Compiler__valueNumberForExpr)(*(undefined4 *)(ctx + 0x238),negApplied);
                valueNumber = *(int *)(valueNumber + 4);
              }
              else {
                operandSlot = *(int *)(ctx + 0xb0) + (int)operandIndex * 0x18 + 0x80;
                *modifierWords = *(uint *)(operandSlot + 0x20) & 1;
                modifierWords[4] = *(uint *)(operandSlot + 0x20) >> 1 & 1;
              }
              *laneValueCursor = valueNumber;
            }
            moreComponents = laneIdx != 3;
            laneValueCursor = laneValueCursor + 1;
            modifierWords = modifierWords + 1;
            laneIdx = laneIdx + 1;
          } while (moreComponents);
        }
        goto setKeyInstPtr;
      }
    }
    keyInstPtr = *(int **)(ctx + 0xb0);
    operandIndex2 = ((unsigned char *)0x0);
    while( true ) {
      operandIndex2 = (dword *)((int)operandIndex2 + 1);
      vcall14Result = (**(code **)(*keyInstPtr + 0x14))(keyInstPtr);
      staleArg4 = (undefined4)vcall14Result;
      if ((int)((ulonglong)vcall14Result >> 0x20) < (int)operandIndex2) break;
      keyInstPtr = *(int **)(ctx + 0xb0);
      sourceKeyVec = *(uint **)(keyInstPtr[(int)operandIndex2 * 6 + 0x23] + 0x2c);
      vecCountB = sourceKeyVec[1];
      topIndex = vecCountB - 1;
      if (topIndex < *sourceKeyVec) {
        if (vecCountB <= topIndex) {
          staleArg5 = (dword *)((topIndex - vecCountB) * 4 + 4);
          _memset(vecCountB * 4 + sourceKeyVec[2],0,staleArg5);
          sourceKeyVec[1] = vecCountB;
          keyInstPtr = *(int **)(ctx + 0xb0);
        }
        topSlot = (int *)(topIndex * 4 + sourceKeyVec[2]);
      }
      else {
        topSlot = (int *)Vector__elementRefGrow(sourceKeyVec,topIndex);
        keyInstPtr = *(int **)(ctx + 0xb0);
      }
      sourceKey = *topSlot;
      laneActiveFlagPtr = (char *)((int)operandIndex2 * 4 + ctx + 0x224);
      laneValueCursor2 = (int *)((int)operandIndex2 * 0x10 + ctx + 0x168);
      modifierWords = (uint *)((int)operandIndex2 * 0x20 + ctx + 200);
      laneIdxB = 0;
      laneWordCursor = ctx;
      do {
        if (*laneActiveFlagPtr != '\0') {
          operandRecord = IRInst__getOperandRecord(keyInstPtr,operandIndex2);
          sourceComponent = (uint)*(byte *)(laneIdxB + operandRecord + 0x10);
          if (sourceComponent == 4) {
            keyInstPtr = *(int **)(ctx + 0xb0);
            *(undefined4 *)(laneWordCursor + 0x30) = 0;
            *(undefined4 *)(laneWordCursor + 0x40) = 0;
          }
          else {
            sourceValueNumber = *(int *)(sourceComponent * 4 + sourceKey + 0x20);
            if (sourceValueNumber < 0) {
              exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),sourceValueNumber);
              IRInst__applyAbsModifier(&absAppliedB,*(undefined4 *)(ctx + 0xb0),operandIndex2,*exprRecord);
              staleArg5 = operandIndex2;
              staleArg6 = absAppliedB;
              IRInst__applyNegateModifier(negAppliedB,*(undefined4 *)(ctx + 0xb0),operandIndex2,absAppliedB);
              sourceValueNumber = ((int (*)())Compiler__valueNumberForExpr)(*(undefined4 *)(ctx + 0x238),negAppliedB[0]);
              keyInstPtr = *(int **)(ctx + 0xb0);
              sourceValueNumber = *(int *)(sourceValueNumber + 4);
            }
            else {
              keyInstPtr = *(int **)(ctx + 0xb0);
              *modifierWords = keyInstPtr[(int)operandIndex2 * 6 + 0x28] & 1;
              modifierWords[4] = (uint)keyInstPtr[(int)operandIndex2 * 6 + 0x28] >> 1 & 1;
            }
            *laneValueCursor2 = sourceValueNumber;
          }
        }
        moreLanes = laneIdxB != 3;
        laneActiveFlagPtr = laneActiveFlagPtr + 1;
        laneWordCursor = laneWordCursor + 4;
        laneValueCursor2 = laneValueCursor2 + 1;
        modifierWords = modifierWords + 1;
        laneIdxB = laneIdxB + 1;
      } while (moreLanes);
    }
  }
  else {
    operandIdx = 1;
    staleArg4 = retR4;
    if (0 < *(int *)(vcall7cResult + 0x84)) {
      do {
        operandSource = IRInst__getOperandSource(vcall7cResult,operandIdx);
        staleArg4 = (undefined4)operandSource;
        if ((int)((ulonglong)operandSource >> 0x20) == 0) {
          countdown = 4;
          operandLaneValues = (undefined4 *)(operandIdx * 0x10 + ctx + 0x168);
          do {
            *operandLaneValues = 0;
            operandLaneValues = operandLaneValues + 1;
            countdown = countdown + -1;
          } while (countdown != 0);
        }
        else {
          countdownB = 4;
          operandLaneValues = (undefined4 *)(operandIdx * 0x10 + ctx + 0x168);
          laneByteOffset = 0;
          do {
            sourceLanePtr = (undefined4 *)(laneByteOffset + *(int *)(operandIdx * 4 + *(int *)(vcall7cResult + 0x138)));
            laneByteOffset = laneByteOffset + 4;
            *operandLaneValues = *sourceLanePtr;
            operandLaneValues = operandLaneValues + 1;
            countdownB = countdownB + -1;
          } while (countdownB != 0);
        }
        operandIdx = operandIdx + 1;
      } while (operandIdx <= *(int *)(vcall7cResult + 0x84));
    }
  }
setKeyInstPtr:
  keyInstPtr = *(int **)(ctx + 0xb0);
  instWord4c = keyInstPtr[0x4c];
  instWord4d = keyInstPtr[0x4d];
  instWord4e = keyInstPtr[0x4e];
  *(int *)(ctx + 0x1cc) = keyInstPtr[0x4b];
  *(int *)(ctx + 0x1d0) = instWord4c;
  *(int *)(ctx + 0x1d4) = instWord4d;
  *(int *)(ctx + 0x1d8) = instWord4e;
  instWord4f = keyInstPtr[0x4f];
  instWord50 = keyInstPtr[0x50];
  instWord51 = keyInstPtr[0x51];
  *(int *)(ctx + 0x1e8) = keyInstPtr[0x52];
  *(int *)(ctx + 0x1dc) = instWord4f;
  *(int *)(ctx + 0x1e0) = instWord50;
  *(int *)(ctx + 0x1e4) = instWord51;
  vcall30Result = (**(code **)(*keyInstPtr + 0x30))
                    (keyInstPtr,staleArg4,staleArg5,staleArg6,staleArg7,instWord51,ctx + 0x1cc,instWord50);
  if (vcall30Result == 0) {
    vcall5cResult = (**(code **)(**(int **)(ctx + 0xb0) + 0x5c))(*(int **)(ctx + 0xb0));
    if (vcall5cResult == 0) {
      fun172fb8Result = ValueKey__producerIsOpcode2aFlagged(ctx);
      if (fun172fb8Result == 0) {
        keyInstPtr = *(int **)(ctx + 0xb0);
        if ((*(int *)(keyInstPtr[0x22] + 8) == 0xf7) || (*(int *)(keyInstPtr[0x22] + 8) == 0xb4)) {
          *(int *)(ctx + 0x1d4) = keyInstPtr[0x53];
        }
      }
      else {
        keyInstPtr = *(int **)(ctx + 0xb0);
        *(int *)(ctx + 0x1d4) = keyInstPtr[0x53];
      }
    }
    else {
      keyInstPtr = *(int **)(ctx + 0xb0);
      *(undefined1 *)(ctx + 0x1ec) = 1;
    }
  }
  else {
    *(undefined4 *)(ctx + 0x1dc) = 0;
    _memcpy(ctx + 0x1ec,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x13c),0x24);
    keyInstPtr = *(int **)(ctx + 0xb0);
  }
  vcall74Result = (**(code **)(*keyInstPtr + 0x74))(keyInstPtr);
  if (vcall74Result != 0) {
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 300) = *(undefined4 *)(ctx + 0x188);
  }
  vcall78Result = (**(code **)(**(int **)(ctx + 0xb0) + 0x78))(*(int **)(ctx + 0xb0));
  if (vcall78Result != 0) {
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 300) = *(undefined4 *)(ctx + 0x188);
  }
  return;
}

/* ValueKey__rebuild @ 0x1745ac (68 bytes) */
int ValueKey__rebuild(valueKey)
  int valueKey;
{
  _memset(valueKey + 0xb4,0,0x15c);
  ((int (*)())ValueKey__fillSourceLaneUsage)(valueKey);
  return ((int (*)())ValueKey__fill)(valueKey);
}

/* ValueKey__simplifyAll @ 0x1745f0 (216 bytes) */
int ValueKey__simplifyAll(ctx)
  int ctx;
{
  int callResult;
  undefined4 result;
  
  callResult = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),9);
  result = 0;
  if (callResult != 0) {
    callResult = ValueKey__canonicalizeConstantSources(ctx);
    if (callResult != 0) {
      ((int (*)())ValueKey__rebuild)(ctx);
    }
    do {
      callResult = ValueKey__simplifyInstruction(ctx);
    } while (callResult != 0);
    callResult = ValueKey__rewriteUniformSwizzle(ctx);
    if (callResult != 0) {
      ((int (*)())ValueKey__rebuild)(ctx);
    }
    callResult = (**(code **)(**(int **)(ctx + 0xb0) + 0x24))(*(int **)(ctx + 0xb0));
    if ((callResult != 0) && (callResult = ValueKey__mixLiteralSources(ctx), callResult != 0)) {
      ((int (*)())ValueKey__rebuild)(ctx);
    }
    callResult = ValueKey__simplifyModifiersAndAddressing(ctx);
    result = 1;
    if (callResult != 0) {
      ((int (*)())ValueKey__rebuild)(ctx);
      result = 1;
    }
  }
  return result;
}

/* Compiler__internPointer @ 0x1746c8 (252 bytes) */
int Compiler__internPointer(compiler, pointerKey)
  int compiler;
  undefined4 pointerKey;
{
  undefined4 *pointerRecord;
  undefined4 *allocation;
  int *recordVectorSlot;
  uint vectorFilledCount;
  undefined4 arena;
  uint *vector;
  
  **(undefined4 **)(compiler + 0x3f4) = pointerKey;
  pointerRecord = (undefined4 *)
           HashTable__find(*(undefined4 *)(compiler + COMP_pointerSet),*(undefined4 *)(compiler + 0x3f4));
  if (pointerRecord == (undefined4 *)0x0) {
    arena = *(undefined4 *)(compiler + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arena,0x34);
    pointerRecord = allocation + 1;
    *allocation = arena;
    allocation[3] = 0xffffffff;
    allocation[0xc] = 0;
    allocation[2] = 0;
    allocation[4] = 0;
    allocation[5] = 0;
    allocation[6] = 0;
    allocation[7] = 0;
    allocation[9] = 0;
    allocation[10] = 0;
    allocation[0xb] = 0;
    allocation[1] = pointerKey;
    allocation[8] = 0;
    HashTable__insert(*(undefined4 *)(compiler + COMP_pointerSet),pointerRecord);
    vector = *(uint **)(compiler + 0x3dc);
    vectorFilledCount = vector[1];
    if (vectorFilledCount < *vector) {
      _memset(vectorFilledCount * 4 + vector[2],0,4);
      recordVectorSlot = (int *)(vectorFilledCount * 4 + vector[2]);
      vector[1] = vectorFilledCount + 1;
    }
    else {
      recordVectorSlot = (int *)Vector__elementRefGrow(vector,vectorFilledCount);
    }
    *recordVectorSlot = (int)pointerRecord;
  }
  return pointerRecord;
}

/* Compiler__findInScopes40c @ 0x1747c4 (196 bytes) */
int Compiler__findInScopes40c(key, scopeIndex, outermostScope, compiler)
  undefined4 key;
  uint scopeIndex;
  int outermostScope;
  int compiler;
{
  uint vectorFilledCount;
  undefined4 *scopeTableSlot;
  int callResult;
  int scopeByteOffset;
  uint *vector;
  
  if (outermostScope <= (int)scopeIndex) {
    scopeByteOffset = scopeIndex << 2;
    do {
      vector = *(uint **)(compiler + 0x40c);
      if (scopeIndex < *vector) {
        vectorFilledCount = vector[1];
        if (vectorFilledCount <= scopeIndex) {
          _memset(vectorFilledCount * 4 + vector[2],0,(scopeIndex - vectorFilledCount) * 4 + 4);
          vector[1] = scopeIndex + 1;
        }
        scopeTableSlot = (undefined4 *)(scopeByteOffset + vector[2]);
      }
      else {
        scopeTableSlot = (undefined4 *)Vector__elementRefGrow(vector,scopeIndex);
      }
      callResult = HashTable__find(*scopeTableSlot,key);
      if (callResult != 0) {
        return callResult;
      }
      scopeIndex = scopeIndex - 1;
      scopeByteOffset = scopeByteOffset + -4;
    } while (outermostScope <= (int)scopeIndex);
  }
  return 0;
}

/* Compiler__findInScopes408 @ 0x174888 (196 bytes) */
int Compiler__findInScopes408(key, scopeIndex, outermostScope, compiler)
  undefined4 key;
  uint scopeIndex;
  int outermostScope;
  int compiler;
{
  uint vectorFilledCount;
  undefined4 *scopeTableSlot;
  int callResult;
  int scopeByteOffset;
  uint *vector;
  
  if (outermostScope <= (int)scopeIndex) {
    scopeByteOffset = scopeIndex << 2;
    do {
      vector = *(uint **)(compiler + 0x408);
      if (scopeIndex < *vector) {
        vectorFilledCount = vector[1];
        if (vectorFilledCount <= scopeIndex) {
          _memset(vectorFilledCount * 4 + vector[2],0,(scopeIndex - vectorFilledCount) * 4 + 4);
          vector[1] = scopeIndex + 1;
        }
        scopeTableSlot = (undefined4 *)(scopeByteOffset + vector[2]);
      }
      else {
        scopeTableSlot = (undefined4 *)Vector__elementRefGrow(vector,scopeIndex);
      }
      callResult = HashTable__find(*scopeTableSlot,key);
      if (callResult != 0) {
        return callResult;
      }
      scopeIndex = scopeIndex - 1;
      scopeByteOffset = scopeByteOffset + -4;
    } while (outermostScope <= (int)scopeIndex);
  }
  return 0;
}

/* ValueKey__internScopedKey @ 0x17494c (440 bytes) */
int ValueKey__internScopedKey(ctx, scopeIndexHigh, scopeIndexLow)
  int ctx;
  undefined4 scopeIndexHigh;
  undefined4 scopeIndexLow;
{
  int loopIndex;
  bool moreComponents;
  int optionEnabled;
  int matchedInst;
  int foundKey;
  int laneKeyCursor;
  int compiler;
  undefined4 *allocation;
  int operandRecord;
  int *topSlot;
  int currentProgram;
  uint vectorFilledCount;
  undefined4 arena;
  undefined4 *loopPtr2;
  uint topIndex;
  uint *vector;
  
  optionEnabled = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),9);
  if ((optionEnabled != 0) &&
     (compiler = *(int *)(ctx + 0x238),
     *(int *)(*(int *)(compiler + 0x6c4) + 0xa8) < *(int *)(compiler + 0x658))) {
    arena = *(undefined4 *)(compiler + 0x378);
    loopIndex = 0;
    allocation = (undefined4 *)Arena__alloc(arena,0x240);
    *allocation = arena;
    allocation[0x2d] = *(undefined4 *)(ctx + 0xb0);
    loopPtr2 = allocation + 1;
    laneKeyCursor = ctx;
    do {
      operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if (*(char *)(loopIndex + operandRecord + 0x10) == '\x01') {
        loopPtr2[8] = 3;
      }
      else {
        loopPtr2[8] = *(undefined4 *)(laneKeyCursor + 0x20);
      }
      moreComponents = loopIndex != 3;
      loopPtr2 = loopPtr2 + 1;
      laneKeyCursor = laneKeyCursor + 4;
      loopIndex = loopIndex + 1;
    } while (moreComponents);
    foundKey = ((int (*)())Compiler__findInScopes408)(allocation + 1,scopeIndexHigh,scopeIndexLow,
                         *(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4));
    if (foundKey != 0) {
      matchedInst = *(int *)(foundKey + 0xb0);
      if ((*(uint *)(matchedInst + 0x14) & 1) == 0) {
        vector = *(uint **)(*(int *)(matchedInst + 0x8c) + 0x2c);
        vectorFilledCount = vector[1];
        topIndex = vectorFilledCount - 1;
        if (topIndex < *vector) {
          if (vectorFilledCount <= topIndex) {
            _memset(vectorFilledCount * 4 + vector[2],0,(topIndex - vectorFilledCount) * 4 + 4);
            vector[1] = vectorFilledCount;
          }
          topSlot = (int *)(topIndex * 4 + vector[2]);
        }
        else {
          topSlot = (int *)Vector__elementRefGrow(vector,topIndex);
        }
        matchedInst = *(int *)(*topSlot + 0xb0);
      }
      currentProgram = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
      *(int *)(currentProgram + 0xa8) = *(int *)(currentProgram + 0xa8) + 1;
      currentProgram = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
      *(int *)(currentProgram + 0x144) = *(int *)(currentProgram + 0x144) + 1;
      ValueKey__rewriteAsMovOfValueKey(ctx,matchedInst,&DAT_001b01bc,0);
      return 1;
    }
  }
  return 0;
}

/* ValueKey__markUsesBetweenBlocks @ 0x174b04 (476 bytes) */
int ValueKey__markUsesBetweenBlocks(ctx, startBlockIndex, endBlockIndex)
  int ctx;
  uint startBlockIndex;
  int endBlockIndex;
{
  int vcall18Result;
  int vcall14Result;
  uint vectorFilledCount;
  int *useSlot;
  int *currentInst;
  int *operandSourceInst;
  uint useCount;
  int *blockSlot;
  int blockByteOffset;
  int operandRecordBase;
  int targetState;
  uint loopIndex2;
  int blockUseVector;
  uint sourceBitIndex;
  int operandByteOffset;
  int loopIndex;
  uint *vector;
  uint blockIndex;
  uint usesLeft;
  
  loopIndex = 1;
  operandByteOffset = 0x18;
  currentInst = *(int **)(ctx + 0xb0);
  vector = *(uint **)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0x410);
  do {
    vcall14Result = (**(code **)(*currentInst + 0x14))(currentInst);
    if (vcall14Result < loopIndex) {
      return;
    }
    operandSourceInst = *(int **)(operandByteOffset + *(int *)(ctx + 0xb0) + 0x8c);
    vcall18Result = (**(code **)(*operandSourceInst + 0x18))(operandSourceInst);
    if ((vcall18Result != 0) && (sourceBitIndex = operandSourceInst[7], endBlockIndex <= (int)startBlockIndex)) {
      blockByteOffset = startBlockIndex << 2;
      blockIndex = startBlockIndex;
      do {
        if (blockIndex < *vector) {
          vectorFilledCount = vector[1];
          if (vectorFilledCount <= blockIndex) {
            _memset(vectorFilledCount * 4 + vector[2],0,(blockIndex - vectorFilledCount) * 4 + 4);
            vector[1] = blockIndex + 1;
          }
          blockSlot = (int *)(blockByteOffset + vector[2]);
        }
        else {
          blockSlot = (int *)Vector__elementRefGrow(vector,blockIndex);
        }
        blockUseVector = *(int *)(*blockSlot + 0xc4);
        useCount = *(uint *)(blockUseVector + 4);
        if (0 < (int)useCount) {
          loopIndex2 = 0;
          usesLeft = useCount;
          do {
            useSlot = (int *)0x0;
            if (loopIndex2 < useCount) {
              useSlot = (int *)(loopIndex2 * 4 + *(int *)(blockUseVector + 8));
            }
            if (operandSourceInst == (int *)*useSlot) {
              if ((*(uint *)((sourceBitIndex >> 3 & 0x1ffffffc) + *(int *)(*blockSlot + 0x128) + 8) >>
                   (sourceBitIndex & 0x1f) & 1) != 0) {
                currentInst = *(int **)(ctx + 0xb0);
                if ((*(uint *)((int)currentInst + operandByteOffset + 0xa0) & 2) == 0) {
                  targetState = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
                  *(int *)(targetState + 0xa8) = *(int *)(targetState + 0xa8) + 1;
                  operandRecordBase = *(int *)(ctx + 0xb0) + operandByteOffset + 0x80;
                  IROperand__setModifierBits(operandRecordBase + 0xc,1,*(uint *)(operandRecordBase + 0x20) & 1 ^ 1);
                  currentInst = *(int **)(ctx + 0xb0);
                }
                goto setLoopIndex;
              }
              break;
            }
            loopIndex2 = loopIndex2 + 1;
            usesLeft = usesLeft - 1;
          } while (usesLeft != 0);
        }
        blockIndex = blockIndex - 1;
        blockByteOffset = blockByteOffset + -4;
      } while (endBlockIndex <= (int)blockIndex);
    }
    currentInst = *(int **)(ctx + 0xb0);
setLoopIndex:
    loopIndex = loopIndex + 1;
    operandByteOffset = operandByteOffset + 0x18;
  } while( true );
}

/* Compiler__internLaneExpr @ 0x174ce0 (300 bytes) */
int Compiler__internLaneExpr(compiler, keyValueB, keyValueA)
  int compiler;
  undefined4 keyValueB;
  undefined4 keyValueA;
{
  undefined4 arenaAt378;
  undefined4 *exprRecord;
  undefined4 *exprAllocation;
  int *recordVectorSlot;
  undefined4 nextValueNumberResult;
  uint vectorFilledCount;
  uint *vector;
  
  *(undefined4 *)(*(int *)(compiler + 0x3f4) + 4) = keyValueA;
  *(undefined4 *)(*(int *)(compiler + 0x3f4) + 8) = keyValueB;
  exprRecord = (undefined4 *)
           HashTable__find(*(undefined4 *)(compiler + 0x3ec),*(undefined4 *)(compiler + 0x3f4));
  if (exprRecord == (undefined4 *)0x0) {
    arenaAt378 = *(undefined4 *)(compiler + 0x378);
    exprAllocation = (undefined4 *)Arena__alloc(arenaAt378,0x34);
    exprRecord = exprAllocation + 1;
    *exprAllocation = arenaAt378;
    exprAllocation[3] = 0xffffffff;
    exprAllocation[8] = 0;
    exprAllocation[1] = 0;
    exprAllocation[0xc] = 0;
    exprAllocation[2] = 0;
    exprAllocation[4] = 0;
    exprAllocation[5] = 0;
    exprAllocation[6] = 0;
    exprAllocation[7] = 0;
    exprAllocation[9] = 0;
    exprAllocation[10] = 0;
    exprAllocation[0xb] = 0;
    nextValueNumberResult = Compiler__nextValueNumber(compiler);
    exprAllocation[2] = keyValueA;
    exprAllocation[1] = nextValueNumberResult;
    exprAllocation[3] = keyValueB;
    HashTable__insert(*(undefined4 *)(compiler + 1000),exprRecord);
    HashTable__insert(*(undefined4 *)(compiler + 0x3ec),exprRecord);
    vector = *(uint **)(compiler + 0x3dc);
    vectorFilledCount = vector[1];
    if (vectorFilledCount < *vector) {
      _memset(vectorFilledCount * 4 + vector[2],0,4);
      recordVectorSlot = (int *)(vectorFilledCount * 4 + vector[2]);
      vector[1] = vectorFilledCount + 1;
    }
    else {
      recordVectorSlot = (int *)Vector__elementRefGrow(vector,vectorFilledCount);
    }
    *recordVectorSlot = (int)exprRecord;
  }
  return exprRecord;
}

/* ValueKey__computeLaneFlags @ 0x174e0c (2764 bytes) */
int ValueKey__computeLaneFlags(valueKey)
  int *valueKey;
{
  int laneCounter;
  int laneConstRecord;
  int scaledValueCopy;
  int exprRecordWord;
  int keyInstB;
  int recordValueNumber;
  int clampedValue;
  int laneIdx;
  int valueNumber;
  int laneByteOffset;
  int producerKind;
  int *laneValuePtr2;
  int *laneExprRecord2;
  int *keyInstPtr2;
  int *laneExprRecord;
  int *laneValuePtrAt;
  int *laneValuePtr;
  int compareFloatsResult;
  int destRecordKeyB;
  int destRecordKey;
  int predicateResult;
  int flagBit8Result;
  int flagBit9Result;
  int flagBit2Result;
  int keyInst;
  uint loopIndex3;
  int *callResult2;
  int operandRecord2;
  int vcall64Result;
  int vcall48Result;
  int countdown3;
  int vcall50Result;
  int vcall60Result;
  int loopIndex2;
  int callResult;
  int countdown2;
  int countdown;
  int loopIndex;
  int returnZero_172f24Result;
  bool isLast;
  bool moreComponents;
  undefined4 inst2;
  int inst;
  undefined4 nextValueNumberResult;
  int operandRecord;
  undefined4 clampChanged;
  int callResult4;
  int *operandLaneKeyPtr;
  undefined4 *exprRecordForValueNumberResultB;
  float *exprRecordForValueNumberResult;
  int keyInstC;
  uint operandModifierBits;
  bool laneClamped;
  int compilerForKey;
  int operandIndex;
  int *keyInstPtr;
  int selectedValueNumber;
  int laneFlags [5];
  int clampedValueD;
  int scaledValueC;
  int clampedValueC;
  int scaledValueB;
  int clampedValueB;
  int scaledValueA;
  int clampedValueA [3];
  float constantValue;
  
  keyInstPtr = (int *)valueKey[0x2c];
  laneFlags[0] = 1;
  laneFlags[1] = 1;
  laneFlags[2] = 1;
  laneFlags[3] = 1;
  if (*(int *)(keyInstPtr[0x22] + 8) == 0x8e) {
    inst2 = (**(code **)(*keyInstPtr + 0x7c))(keyInstPtr);
    callResult = IRInst__allSourcesDefined(inst2);
    if (callResult == 0) goto setLoopIndex2;
    keyInstPtr = (int *)valueKey[0x2c];
  }
  callResult4 = IRInst__isProjectionOfOpcode2a(keyInstPtr);
  if ((((callResult4 != 0) || (callResult4 = IRInst__isProjectionOfClass26or3a(valueKey[0x2c]), callResult4 != 0)) ||
      (keyInstPtr = (int *)valueKey[0x2c], *(int *)(keyInstPtr[0x22] + 8) == 0xb4)) ||
     ((callResult4 = (**(code **)(*keyInstPtr + 0x6c))(keyInstPtr), callResult4 != 0 ||
      (callResult4 = (**(code **)(*(int *)valueKey[0x2c] + 0x58))((int *)valueKey[0x2c]), callResult4 != 0)))) {
setLoopIndex2:
    loopIndex2 = 0;
    laneValuePtr = valueKey;
    do {
      compilerForKey = valueKey[0x8e];
      nextValueNumberResult = Compiler__nextValueNumber(compilerForKey);
      callResult2 = (int *)((int (*)())Compiler__internPointer)(compilerForKey,nextValueNumberResult);
      callResult2[2] = loopIndex2;
      callResult2[1] = (int)valueKey;
      HashTable__insert(*(undefined4 *)(valueKey[0x8e] + 1000),callResult2);
      HashTable__insert(*(undefined4 *)(valueKey[0x8e] + 0x3ec),callResult2);
      moreComponents = loopIndex2 != 3;
      loopIndex2 = loopIndex2 + 1;
      *laneValuePtr = *callResult2;
      laneValuePtr = laneValuePtr + 1;
    } while (moreComponents);
    return;
  }
  vcall60Result = (**(code **)(*(int *)valueKey[0x2c] + 0x60))((int *)valueKey[0x2c]);
  if (vcall60Result != 0) {
    inst = valueKey[0x2c];
    loopIndex2 = 0;
    laneValuePtr = valueKey;
    do {
      operandRecord = IRInst__getOperandRecord(inst,0);
      if (*(char *)(loopIndex2 + operandRecord + 0x10) == '\x01') {
        inst = valueKey[0x2c];
      }
      else {
        inst = valueKey[0x2c];
        if (0 < *(int *)(inst + 0x84)) {
          operandIndex = 1;
          operandLaneKeyPtr = valueKey + loopIndex2 + 0x5e;
          do {
            operandRecord = IRInst__getOperandRecord(inst,operandIndex);
            if (*(char *)(loopIndex2 + operandRecord + 0x10) != '\x04') {
              inst = valueKey[0x2c];
              *laneValuePtr = *operandLaneKeyPtr;
              break;
            }
            inst = valueKey[0x2c];
            operandIndex = operandIndex + 1;
            operandLaneKeyPtr = operandLaneKeyPtr + 4;
          } while (operandIndex <= *(int *)(inst + 0x84));
        }
      }
      isLast = loopIndex2 == 3;
      laneValuePtr = laneValuePtr + 1;
      loopIndex2 = loopIndex2 + 1;
      if (isLast) {
        loopIndex2 = 0;
        laneValuePtr = valueKey;
        while( true ) {
          operandRecord = IRInst__getOperandRecord(inst,0);
          if (*(char *)(loopIndex2 + operandRecord + 0x10) == '\x01') {
            *laneValuePtr = 2;
          }
          isLast = loopIndex2 == 3;
          laneValuePtr = laneValuePtr + 1;
          loopIndex2 = loopIndex2 + 1;
          if (isLast) break;
          inst = valueKey[0x2c];
        }
        return;
      }
    } while( true );
  }
  vcall50Result = (**(code **)(*(int *)valueKey[0x2c] + 0x50))((int *)valueKey[0x2c]);
  if (vcall50Result != 0) {
    countdown3 = 4;
    laneValuePtr = valueKey;
    do {
      *laneValuePtr = 1;
      laneValuePtr = laneValuePtr + 1;
      countdown3 = countdown3 + -1;
    } while (countdown3 != 0);
    goto callValueKey_laneFlagsAllowDest;
  }
  vcall48Result = (**(code **)(*(int *)valueKey[0x2c] + 0x48))((int *)valueKey[0x2c]);
  if (vcall48Result == 0) {
    keyInst = valueKey[0x2c];
  }
  else {
    keyInst = valueKey[0x2c];
    producerKind = *(int *)(keyInst + 0x98);
    if (((producerKind == 2) || (producerKind == 0xc)) || (producerKind == 0x33)) {
      loopIndex3 = 0;
      laneValuePtr = valueKey;
      while( true ) {
        if (((int)*(char *)(keyInst + 0x15c) >> (loopIndex3 & 0x3f) & 1U) == 0) {
          callResult2 = (int *)((int (*)())Compiler__internLaneExpr)(valueKey[0x8e],loopIndex3,valueKey);
          laneValuePtr[0x10] = (int)callResult2;
          *laneValuePtr = *callResult2;
        }
        else {
          callResult = ValueKey__refreshExprRecordForOperand(valueKey,loopIndex3);
          *laneValuePtr = *(int *)(callResult + 4);
        }
        isLast = loopIndex3 == 3;
        laneValuePtr = laneValuePtr + 1;
        loopIndex3 = loopIndex3 + 1;
        if (isLast) break;
        keyInst = valueKey[0x2c];
      }
      goto callValueKey_laneFlagsAllowDest;
    }
  }
  flagBit2Result = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(keyInst + 0x88) + 8),valueKey[0x8e]);
  if ((((flagBit2Result == 0) ||
       (flagBit9Result = OpcodeTraits__flagBit9(*(undefined4 *)(*(int *)(valueKey[0x2c] + 0x88) + 8),valueKey[0x8e]),
       flagBit9Result != 0)) &&
      (flagBit8Result = OpcodeTraits__flagBit8(*(undefined4 *)(*(int *)(valueKey[0x2c] + 0x88) + 8),valueKey[0x8e]),
      flagBit8Result == 0)) &&
     ((predicateResult = ((int (*)())IRInst__allOperandsSplat)(valueKey[0x2c],valueKey[0x8e]), predicateResult == 0 &&
      (predicateResult = ((int (*)())ValueKey__allRowsUniform)(valueKey), predicateResult == 0)))) {
    keyInst = valueKey[0x2c];
    returnZero_172f24Result = returnZero_172f24(keyInst);
    if (returnZero_172f24Result == 0) {
      clampChanged = 0;
      loopIndex = 0;
      laneByteOffset = 0;
      laneValuePtr = valueKey;
      do {
        destRecordKey = IRInst__getOperandRecord(keyInst,0);
        if (*(char *)(loopIndex + destRecordKey + 0x10) != '\x01') {
          keyInstPtr2 = (int *)valueKey[0x2c];
          if (*(int *)(keyInstPtr2[0x22] + 8) == 0x8e) {
            callResult = ValueKey__allOperandLanesEqual(valueKey,loopIndex);
            if (callResult == 0) {
              callResult2 = (int *)((int (*)())Compiler__internLaneExpr)(valueKey[0x8e],loopIndex,valueKey);
              exprRecordWord = *callResult2;
            }
            else {
              exprRecordWord = laneValuePtr[0x5e];
            }
            *laneValuePtr = exprRecordWord;
          }
          else {
            vcall64Result = (**(code **)(*keyInstPtr2 + 100))(keyInstPtr2);
            if (vcall64Result == 0) {
              callResult = ((int (*)())IRInst__isCndFloatOp)(valueKey[0x2c]);
              if ((callResult == 0) || (-1 < laneValuePtr[0x5e])) {
                if (laneValuePtr[0xc] != 0) {
                  *laneValuePtr = *(int *)(laneValuePtr[0xc] + 4);
                  goto setIsLast;
                }
              }
              else {
                exprRecordForValueNumberResult = (float *)Compiler__exprRecordForValueNumber(valueKey[0x8e],laneValuePtr[0x5e]);
                constantValue = *exprRecordForValueNumberResult;
                compareFloatsResult = ((bool (*)())evaluateCompareFloats)(valueKey[0x2c],(double)constantValue,0.0);
                compareFloatsResult = (compareFloatsResult == 0) + 2;
                selectedValueNumber = valueKey[compareFloatsResult * 4 + loopIndex + 0x5a];
                if (selectedValueNumber < 0) {
                  exprRecordForValueNumberResultB = (undefined4 *)Compiler__exprRecordForValueNumber(valueKey[0x8e],selectedValueNumber);
                  IRInst__scaleByOutputScale(&scaledValueA,valueKey[0x2c],*exprRecordForValueNumberResultB);
                  scaledValueCopy = scaledValueA;
                  IRInst__clampOutputValue(clampedValueA,valueKey[0x2c],scaledValueA);
                  clampedValue = clampedValueA[0];
                  if (clampedValueA[0] != scaledValueCopy) goto setClampChanged;
                  goto setScaledValueCopy;
                }
                keyInstC = valueKey[0x2c];
                if ((((*(int *)(keyInstC + 0x120) == 0) && (*(int *)(keyInstC + 0x124) == 0)) &&
                    (operandModifierBits = *(uint *)(compareFloatsResult * 0x18 + keyInstC + 0xa0), (operandModifierBits & 1) == 0)) &&
                   ((operandModifierBits & 2) == 0)) goto storeLaneValuePtr;
              }
loopCallValueKey_classifyLaneCompareClass:
              ValueKey__classifyLaneCompareClass(valueKey,loopIndex);
              ValueKey__classifyLaneRangeClass(valueKey,loopIndex,laneFlags);
              laneExprRecord2 = (int *)laneValuePtr[0x10];
              *laneValuePtr = *laneExprRecord2;
              laneValuePtr[0x20] = laneExprRecord2[3];
              laneValuePtr[0x14] = laneExprRecord2[4];
            }
            else {
              selectedValueNumber = laneValuePtr[0x5e];
              if (selectedValueNumber < 0) {
                exprRecordForValueNumberResultB = (undefined4 *)Compiler__exprRecordForValueNumber(valueKey[0x8e],selectedValueNumber);
                IRInst__scaleByOutputScale(&scaledValueB,valueKey[0x2c],*exprRecordForValueNumberResultB);
                scaledValueCopy = scaledValueB;
                IRInst__clampOutputValue(&clampedValueB,valueKey[0x2c],scaledValueB);
                clampedValue = clampedValueB;
                if (clampedValueB != scaledValueCopy) {
setClampChanged:
                  clampChanged = 1;
                  scaledValueCopy = clampedValue;
                }
setScaledValueCopy:
                scaledValueCopy = ((int (*)())Compiler__valueNumberForExpr)(valueKey[0x8e],scaledValueCopy);
                recordValueNumber = *(int *)(scaledValueCopy + 4);
                operandRecord2 = IRInst__getOperandRecord(valueKey[0x2c],0);
                if (*(char *)(loopIndex + operandRecord2 + 0x10) == '\0') {
                  *(undefined4 *)((int)laneFlags + laneByteOffset) = clampChanged;
                }
                *laneValuePtr = recordValueNumber;
              }
              else {
                keyInst = valueKey[0x2c];
                if (((*(int *)(keyInst + 0x120) != 0) || (*(int *)(keyInst + 0x124) != 0)) ||
                   (((*(uint *)(keyInst + 0xb8) & 1) != 0 || ((*(uint *)(keyInst + 0xb8) & 2) != 0))))
                goto loopCallValueKey_classifyLaneCompareClass;
storeLaneValuePtr:
                *laneValuePtr = selectedValueNumber;
                callResult = ValueKey__compareClassForValueNumber(valueKey,selectedValueNumber);
                laneValuePtr[0x20] = callResult;
                callResult = ValueKey__rangeClassForValueNumber(valueKey,selectedValueNumber);
                laneValuePtr[0x14] = callResult;
              }
            }
          }
        }
setIsLast:
        isLast = loopIndex == 3;
        laneByteOffset = laneByteOffset + 4;
        laneValuePtr = laneValuePtr + 1;
        loopIndex = loopIndex + 1;
        if (isLast) goto callValueKey_laneFlagsAllowDest;
        keyInst = valueKey[0x2c];
      } while( true );
    }
  }
  else {
    keyInst = valueKey[0x2c];
  }
  destRecordKeyB = IRInst__getOperandRecord(keyInst,0);
  laneByteOffset = 0;
  if (*(int *)(destRecordKeyB + 0x10) != 0x1010101) {
    operandRecord2 = IRInst__getOperandRecord(valueKey[0x2c],0);
    laneByteOffset = SelectWord__firstWrittenComponent(*(undefined4 *)(operandRecord2 + 0x10));
  }
  vcall64Result = (**(code **)(*(int *)valueKey[0x2c] + 100))((int *)valueKey[0x2c]);
  if (vcall64Result == 0) {
    callResult = ((int (*)())IRInst__isCndFloatOp)(valueKey[0x2c]);
    if (callResult == 0) {
      laneConstRecord = (valueKey + laneByteOffset)[0xc];
      if (laneConstRecord != 0) {
loopSetValueNumber:
        valueNumber = *(int *)(laneConstRecord + 4);
        laneCounter = 0;
        laneByteOffset = 0;
        goto setCountdown2;
      }
      ValueKey__classifyLaneCompareClass(valueKey,laneByteOffset);
      ValueKey__classifyLaneRangeClass(valueKey,laneByteOffset,laneFlags);
      countdown = 4;
      laneCounter = 0;
      laneValuePtr = valueKey;
      do {
        laneValuePtr[0x10] = (valueKey + laneByteOffset)[0x10];
        laneValuePtr = laneValuePtr + 1;
        *(int *)((int)laneFlags + laneCounter) = laneFlags[laneByteOffset];
        laneCounter = laneCounter + 4;
        countdown = countdown + -1;
      } while (countdown != 0);
    }
    else {
      laneValuePtrAt = valueKey + laneByteOffset;
      if (laneValuePtrAt[0x5e] < 0) {
        exprRecordForValueNumberResult = (float *)Compiler__exprRecordForValueNumber(valueKey[0x8e],laneValuePtrAt[0x5e]);
        constantValue = *exprRecordForValueNumberResult;
        compareFloatsResult = ((bool (*)())evaluateCompareFloats)(valueKey[0x2c],(double)constantValue,0.0);
        compareFloatsResult = (compareFloatsResult == 0) + 2;
        valueNumber = valueKey[compareFloatsResult * 4 + laneByteOffset + 0x5a];
        if (valueNumber < 0) {
          laneClamped = false;
          exprRecordForValueNumberResultB = (undefined4 *)Compiler__exprRecordForValueNumber(valueKey[0x8e],valueNumber);
          IRInst__scaleByOutputScale(&scaledValueC,valueKey[0x2c],*exprRecordForValueNumberResultB);
          IRInst__clampOutputValue(&clampedValueC,valueKey[0x2c],scaledValueC);
          clampedValueD = clampedValueC;
          if (clampedValueC != scaledValueC) goto setLaneClamped;
          goto setCallResult;
        }
        keyInstB = valueKey[0x2c];
        if (((*(int *)(keyInstB + 0x120) == 0) && (*(int *)(keyInstB + 0x124) == 0)) &&
           ((operandModifierBits = *(uint *)(compareFloatsResult * 0x18 + keyInstB + 0xa0), (operandModifierBits & 1) == 0 && ((operandModifierBits & 2) == 0)
            ))) goto setLaneCounter;
        ValueKey__classifyLaneCompareClass(valueKey,laneByteOffset);
        ValueKey__classifyLaneRangeClass(valueKey,laneByteOffset,laneFlags);
        countdown3 = 4;
        laneIdx = 0;
        laneValuePtr = valueKey;
        do {
          laneValuePtr[0x10] = (valueKey + laneByteOffset)[0x10];
          laneValuePtr = laneValuePtr + 1;
          *(int *)((int)laneFlags + laneIdx) = laneFlags[laneByteOffset];
          laneIdx = laneIdx + 4;
          countdown3 = countdown3 + -1;
        } while (countdown3 != 0);
      }
      else {
        laneConstRecord = laneValuePtrAt[0xc];
        if (laneConstRecord != 0) goto loopSetValueNumber;
        ValueKey__classifyLaneCompareClass(valueKey,laneByteOffset);
        ValueKey__classifyLaneRangeClass(valueKey,laneByteOffset,laneFlags);
        countdown = 4;
        laneCounter = 0;
        laneValuePtr2 = valueKey;
        do {
          laneValuePtr2[0x10] = laneValuePtrAt[0x10];
          laneValuePtr2 = laneValuePtr2 + 1;
          *(int *)((int)laneFlags + laneCounter) = laneFlags[laneByteOffset];
          laneCounter = laneCounter + 4;
          countdown = countdown + -1;
        } while (countdown != 0);
      }
    }
    laneExprRecord = (int *)(valueKey + laneByteOffset)[0x10];
    laneByteOffset = laneExprRecord[4];
    valueNumber = *laneExprRecord;
    laneCounter = laneExprRecord[3];
  }
  else {
    valueNumber = valueKey[laneByteOffset + 0x5e];
    if (valueNumber < 0) {
      laneClamped = false;
      exprRecordForValueNumberResultB = (undefined4 *)Compiler__exprRecordForValueNumber(valueKey[0x8e],valueNumber);
      IRInst__scaleByOutputScale(laneFlags + 4,valueKey[0x2c],*exprRecordForValueNumberResultB);
      IRInst__clampOutputValue(&clampedValueD,valueKey[0x2c],laneFlags[4]);
      scaledValueC = laneFlags[4];
      if (clampedValueD != laneFlags[4]) {
setLaneClamped:
        laneClamped = true;
        scaledValueC = clampedValueD;
      }
setCallResult:
      callResult = ((int (*)())Compiler__valueNumberForExpr)(valueKey[0x8e],scaledValueC);
      valueNumber = *(int *)(callResult + 4);
      if ((*(int *)(valueKey[0x2c] + 0x120) == 0) || (laneClamped)) {
        laneCounter = 0;
        laneByteOffset = 0;
      }
      else {
        laneCounter = 0;
        laneByteOffset = 0;
        *(undefined4 *)(valueKey[0x2c] + 0x120) = 0;
      }
    }
    else {
      keyInst = valueKey[0x2c];
      if ((((*(int *)(keyInst + 0x120) == 0) && (*(int *)(keyInst + 0x124) == 0)) &&
          ((*(uint *)(keyInst + 0xb8) & 1) == 0)) && ((*(uint *)(keyInst + 0xb8) & 2) == 0)) {
setLaneCounter:
        laneCounter = ValueKey__compareClassForValueNumber(valueKey,valueNumber);
        laneByteOffset = ValueKey__rangeClassForValueNumber(valueKey,valueNumber);
      }
      else {
        ValueKey__classifyLaneCompareClass(valueKey,laneByteOffset);
        ValueKey__classifyLaneRangeClass(valueKey,laneByteOffset,laneFlags);
        laneExprRecord = (int *)valueKey[laneByteOffset + 0x10];
        laneByteOffset = laneExprRecord[4];
        valueNumber = *laneExprRecord;
        laneCounter = laneExprRecord[3];
      }
    }
  }
setCountdown2:
  countdown2 = 4;
  laneValuePtr = valueKey;
  do {
    *laneValuePtr = valueNumber;
    laneValuePtr[0x20] = laneCounter;
    laneValuePtr[0x14] = laneByteOffset;
    laneValuePtr = laneValuePtr + 1;
    countdown2 = countdown2 + -1;
  } while (countdown2 != 0);
callValueKey_laneFlagsAllowDest:
  ((int (*)())ValueKey__laneFlagsAllowDest)(valueKey,laneFlags);
  ValueKey__computeLaneCompareCodes(valueKey);
  ValueKey__computeLaneRangeClasses(valueKey);
  return;
}

/* Compiler__findInScopes404 @ 0x1758d8 (356 bytes) */
int Compiler__findInScopes404(valueKey, scopeIndexHigh, scopeIndexLow, program)
  undefined4 *valueKey;
  uint scopeIndexHigh;
  int scopeIndexLow;
  int program;
{
  int countdown;
  uint vectorFilledCount2;
  uint *vector2;
  undefined4 *foundEntry;
  undefined4 copiedWord;
  undefined4 *loopPtr;
  uint vectorFilledCount;
  undefined4 *scopeTableSlot;
  undefined4 *scopeTableSlotB;
  uint *vector;
  uint scopeIndex;
  int scopeByteOffset;
  
  if (scopeIndexLow <= (int)scopeIndexHigh) {
    scopeByteOffset = scopeIndexHigh << 2;
    scopeIndex = scopeIndexHigh;
    do {
      vector = *(uint **)(program + 0x404);
      if (scopeIndex < *vector) {
        vectorFilledCount = vector[1];
        if (vectorFilledCount <= scopeIndex) {
          _memset(vectorFilledCount * 4 + vector[2],0,(scopeIndex - vectorFilledCount) * 4 + 4);
          vector[1] = scopeIndex + 1;
        }
        scopeTableSlot = (undefined4 *)(scopeByteOffset + vector[2]);
      }
      else {
        scopeTableSlot = (undefined4 *)Vector__elementRefGrow(vector,scopeIndex);
      }
      foundEntry = (undefined4 *)HashTable__find(*scopeTableSlot,valueKey);
      if (foundEntry != (undefined4 *)0x0) {
        countdown = 4;
        loopPtr = foundEntry;
        do {
          copiedWord = *loopPtr;
          loopPtr = loopPtr + 1;
          *valueKey = copiedWord;
          valueKey = valueKey + 1;
          countdown = countdown + -1;
        } while (countdown != 0);
        return foundEntry;
      }
      scopeIndex = scopeIndex - 1;
      scopeByteOffset = scopeByteOffset + -4;
    } while (scopeIndexLow <= (int)scopeIndex);
  }
  ((int (*)())ValueKey__computeLaneFlags)(valueKey);
  vector2 = *(uint **)(program + 0x404);
  if (scopeIndexHigh < *vector2) {
    vectorFilledCount2 = vector2[1];
    if (vectorFilledCount2 <= scopeIndexHigh) {
      _memset(vectorFilledCount2 * 4 + vector2[2],0,(scopeIndexHigh - vectorFilledCount2) * 4 + 4);
      vector2[1] = scopeIndexHigh + 1;
    }
    scopeTableSlotB = (undefined4 *)(scopeIndexHigh * 4 + vector2[2]);
  }
  else {
    scopeTableSlotB = (undefined4 *)Vector__elementRefGrow(vector2,scopeIndexHigh);
  }
  HashTable__insert(*scopeTableSlotB,valueKey);
  return (undefined4 *)0x0;
}

/* Compiler__internFloatConstant @ 0x175a3c (260 bytes) */
undefined4 * Compiler__internFloatConstant(int compiler,undefined4 unusedArg2,undefined4 valueNumber,double constantValue)
{
  undefined4 *exprRecord;
  undefined4 *allocation;
  int *recordVectorSlot;
  uint vectorFilledCount;
  undefined4 arena;
  uint *vector;
  
  *(undefined4 *)(*(int *)(compiler + 0x3f0) + 4) = valueNumber;
  **(float **)(compiler + 0x3f0) = (float)constantValue;
  exprRecord = (undefined4 *)
           HashTable__find(*(undefined4 *)(compiler + 0x3e4),*(undefined4 *)(compiler + 0x3f0));
  if (exprRecord == (undefined4 *)0x0) {
    arena = *(undefined4 *)(compiler + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x2c);
    exprRecord = allocation + 1;
    *allocation = arena;
    allocation[1] = (float)constantValue;
    allocation[5] = 4;
    allocation[8] = 0;
    *(undefined1 *)(allocation + 3) = 0;
    *(undefined1 *)((int)allocation + 0xd) = 0;
    allocation[4] = 0;
    allocation[7] = 0;
    allocation[2] = valueNumber;
    HashTable__insert(*(undefined4 *)(compiler + 0x3e4),exprRecord);
    HashTable__insert(*(undefined4 *)(compiler + 0x3e0),exprRecord);
    vector = *(uint **)(compiler + 0x3d8);
    vectorFilledCount = vector[1];
    if (vectorFilledCount < *vector) {
      _memset(vectorFilledCount * 4 + vector[2],0,4);
      recordVectorSlot = (int *)(vectorFilledCount * 4 + vector[2]);
      vector[1] = vectorFilledCount + 1;
    }
    else {
      recordVectorSlot = (int *)Vector__elementRefGrow(vector,vectorFilledCount);
    }
    *recordVectorSlot = (int)exprRecord;
  }
  return exprRecord;
}

/* ValueKey__initSourceLaneKinds @ 0x175b40 (620 bytes) */
int ValueKey__initSourceLaneKinds(valueKey)
  undefined4 *valueKey;
{
  int keyInst;
  int projectionCheckResult;
  int fun113734Result;
  int splitRgbAlphaEnabled;
  int flagBit9Result;
  int flagBit8Result;
  int flagBit2Result;
  int vcall64Result;
  int ptrEqualResult;
  int destOperandRecord;
  int countdown;
  bool moreComponents;
  undefined4 sourceField70;
  undefined4 sourceFieldA0;
  int *topSlot;
  undefined4 staleArg6;
  undefined4 staleArg7;
  undefined4 staleArg8;
  int keyOpcodeInfo;
  undefined4 sourceLaneValue;
  uint topIndex;
  int loopIndex;
  uint vectorFilledCount;
  int sourceKey;
  uint *vector;
  undefined4 *loopPtr2;
  undefined4 destSelect [7];
  
  keyInst = valueKey[0x2c];
  if ((*(uint *)(keyInst + 0x14) & 0x200) == 0) {
    countdown = 4;
    do {
      valueKey[4] = 1;
      valueKey = valueKey + 1;
      countdown = countdown + -1;
    } while (countdown != 0);
  }
  else {
    vector = *(uint **)(*(int *)(*(int *)(keyInst + 0x84) * 0x18 + keyInst + 0x8c) + 0x2c);
    vectorFilledCount = vector[1];
    topIndex = vectorFilledCount - 1;
    if (topIndex < *vector) {
      if (vectorFilledCount <= topIndex) {
        _memset(vectorFilledCount * 4 + vector[2],0,(topIndex - vectorFilledCount) * 4 + 4);
        vector[1] = vectorFilledCount;
        keyInst = valueKey[0x2c];
      }
      topSlot = (int *)(topIndex * 4 + vector[2]);
    }
    else {
      topSlot = (int *)Vector__elementRefGrow(vector,topIndex);
      keyInst = valueKey[0x2c];
    }
    sourceKey = *topSlot;
    destOperandRecord = IRInst__getOperandRecord(keyInst,0);
    loopIndex = 0;
    destSelect[0] = *(undefined4 *)(destOperandRecord + 0x10);
    loopPtr2 = valueKey;
    do {
      sourceLaneValue = *(undefined4 *)(sourceKey + 0x20);
      if (((*(char *)((int)destSelect + loopIndex) == '\x01') &&
          (ptrEqualResult = ((int (*)())Ptr__equalNonNull)(*loopPtr2,sourceLaneValue), ptrEqualResult != 0)) &&
         (vcall64Result = (**(code **)(*(int *)valueKey[0x2c] + 100))((int *)valueKey[0x2c]), vcall64Result == 0)) {
        flagBit2Result = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(valueKey[0x2c] + 0x88) + 8),valueKey[0x8e]);
        if (flagBit2Result == 0) {
loopSetKeyOpcodeInfo:
          keyOpcodeInfo = *(int *)(valueKey[0x2c] + 0x88);
          flagBit8Result = OpcodeTraits__flagBit8(*(undefined4 *)(keyOpcodeInfo + 8),valueKey[0x8e]);
          if (flagBit8Result == 0) goto setMoreComponents;
        }
        else {
          keyOpcodeInfo = *(int *)(valueKey[0x2c] + 0x88);
          flagBit9Result = OpcodeTraits__flagBit9(*(undefined4 *)(keyOpcodeInfo + 8),valueKey[0x8e]);
          if (flagBit9Result != 0) goto loopSetKeyOpcodeInfo;
        }
        splitRgbAlphaEnabled = Compiler__isOptionEnabled(valueKey[0x8e],0x30);
        if (((splitRgbAlphaEnabled == 0) || (loopIndex != 3)) &&
           (fun113734Result = OpcodeTraits__instFlagBit2_113734(valueKey[0x8e],valueKey[0x2c],topSlot,staleArg6,staleArg7,staleArg8,keyOpcodeInfo),
           fun113734Result == 0)) {
          *(int *)(*(int *)(valueKey[0x8e] + 0x6c4) + 0xa8) =
               *(int *)(*(int *)(valueKey[0x8e] + 0x6c4) + 0xa8) + 1;
          *(undefined1 *)(loopIndex + valueKey[0x2c] + 0x9c) = 0;
        }
      }
setMoreComponents:
      moreComponents = loopIndex != 3;
      sourceField70 = *(undefined4 *)(sourceKey + 0x70);
      sourceFieldA0 = *(undefined4 *)(sourceKey + 0xa0);
      loopIndex = loopIndex + 1;
      loopPtr2[4] = sourceLaneValue;
      sourceKey = sourceKey + 4;
      loopPtr2[0x18] = sourceField70;
      loopPtr2[0x24] = sourceFieldA0;
      loopPtr2 = loopPtr2 + 1;
    } while (moreComponents);
    projectionCheckResult = IRInst__writesAllLanes(valueKey[0x2c]);
    if ((projectionCheckResult == 0) && (projectionCheckResult = IRInst__isProjectionOfOpcode2a(valueKey[0x2c]), projectionCheckResult == 0)) {
      *(int *)(*(int *)(valueKey[0x8e] + 0x6c4) + 0xa8) =
           *(int *)(*(int *)(valueKey[0x8e] + 0x6c4) + 0xa8) + 1;
      keyInst = valueKey[0x2c];
      IRInst__setOperandSource(keyInst,*(undefined4 *)(keyInst + 0x84),0,0,valueKey[0x8e]);
      *(int *)(keyInst + 0x84) = *(int *)(keyInst + 0x84) + -1;
      *(uint *)(keyInst + 0x14) = *(uint *)(keyInst + 0x14) & 0xfffffdff;
    }
  }
  return;
}

/* Program__valueNumberInst @ 0x175dac (1208 bytes) */
int Program__valueNumberInst(program, valueNumber, outermostScope, keyRef, block)
  int program;
  uint valueNumber;
  undefined4 outermostScope;
  int *keyRef;
  undefined4 block;
{
  int valueKey2;
  int currentDefinition2;
  int currentDefinition;
  int valueKey;
  uint *vector2;
  int inst;
  int eliminateRedundantInstResult;
  int canonicalizeCommutativeOperandsResult;
  int valueNumberEnabled;
  int lookupResultA;
  int vcall64Result;
  int vcall68Result;
  int callResult;
  int lookupResultB;
  int callResult2;
  uint vectorFilledCount;
  undefined4 *vectorElementRef;
  undefined4 result;
  int *keyInst2;
  int keyInst;
  uint *vector;
  
  valueNumberEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),7);
  if ((valueNumberEnabled == 0) || (*(int *)(*(int *)(program + 8) + 0x654) <= *(int *)(program + 0x14c))) {
loopSetResult:
    result = 0;
  }
  else {
    ValueKey__maybeRefineSources(*keyRef);
    ((int (*)())ValueKey__fill)(*keyRef);
    valueKey = *keyRef;
    if (*(int *)(*(int *)(*(int *)(valueKey + 0xb0) + 0x88) + 8) == 0x8e) {
loopSetValueKey:
      valueKey = ((int (*)())ValueKey__eliminateTrivialInst)(valueKey);
      if (valueKey == 0) {
        ValueKey__createLaneRecordsByOpcode(*keyRef);
        canonicalizeCommutativeOperandsResult = ((int (*)())ValueKey__canonicalizeCommutativeOperands)(*keyRef);
        if (canonicalizeCommutativeOperandsResult != 0) {
          ((int (*)())ValueKey__rebuild)(*keyRef);
        }
        callResult = ((int (*)())Compiler__findInScopes404)(*keyRef,valueNumber,outermostScope,program);
        ((int (*)())ValueKey__initSourceLaneKinds)(*keyRef);
        ValueKey__propagateLaneValues(*keyRef);
        callResult2 = ((int (*)())Compiler__findInScopes408)(*keyRef,valueNumber,outermostScope,program);
        if (callResult2 == 0) {
          lookupResultB = (**(code **)(**(int **)(*keyRef + 0xb0) + 100))(*(int **)(*keyRef + 0xb0));
          if ((((lookupResultB == 0) &&
               (lookupResultB = (**(code **)(**(int **)(*keyRef + 0xb0) + 0x68))
                                  (*(int **)(*keyRef + 0xb0)), lookupResultB == 0)) &&
              (lookupResultB = ValueKey__producerIsOpcode2aFlagged(*keyRef), lookupResultB == 0)) &&
             (lookupResultB = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),8), lookupResultB != 0)) {
            callResult2 = ((int (*)())Compiler__findInScopes40c)(*keyRef,valueNumber,outermostScope,program);
            if ((callResult2 != 0) && (callResult2 = ((int (*)())ValueKey__rewriteAsSwizzleMov)(*keyRef,callResult2), callResult2 != 0)) {
              keyInst = *(int *)(*keyRef + 0xb0);
              currentDefinition2 = VReg__currentDefinition(*(undefined4 *)(keyInst + 0xa4),*(undefined4 *)(program + 0x3a0),
                                   *(uint *)(program + 8));
              if ((keyInst == *(int *)(currentDefinition2 + 0xb0)) &&
                 (currentDefinition2 = Program__tryEliminateRedundantCopy(program,*(undefined4 *)(*keyRef + 0xb0),block), currentDefinition2 != 0
                 )) goto setResult;
              goto setValueKey2;
            }
            valueKey2 = *keyRef;
            keyInst2 = *(int **)(valueKey2 + 0xb0);
            if (keyInst2[0x20] != 0) {
              lookupResultB = RegKind__flagBit0(keyInst2[0x26]);
              if (((lookupResultB == 0) || ((keyInst2[5] & 2U) != 0)) ||
                 (lookupResultB = (**(code **)(*keyInst2 + 0x50))(keyInst2), lookupResultB != 0)) goto setValueKey2;
              vector = *(uint **)(program + 0x40c);
              if (valueNumber < *vector) {
                vectorFilledCount = vector[1];
                if (vectorFilledCount <= valueNumber) {
                  _memset(vectorFilledCount * 4 + vector[2],0,(valueNumber - vectorFilledCount) * 4 + 4);
                  vector[1] = valueNumber + 1;
                }
                vectorElementRef = (undefined4 *)(valueNumber * 4 + vector[2]);
              }
              else {
                vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,valueNumber);
              }
              HashTable__insert(*vectorElementRef,*keyRef);
              valueKey2 = *keyRef;
            }
          }
          else {
setValueKey2:
            valueKey2 = *keyRef;
          }
          valueKey2 = (**(code **)(**(int **)(valueKey2 + 0xb0) + 100))(*(int **)(valueKey2 + 0xb0));
          if ((((valueKey2 == 0) &&
               (valueKey2 = (**(code **)(**(int **)(*keyRef + 0xb0) + 0x68))
                                  (*(int **)(*keyRef + 0xb0)), valueKey2 == 0)) &&
              (valueKey2 = ValueKey__producerIsOpcode2aFlagged(*keyRef), valueKey2 == 0)) &&
             (((callResult != 0 && (callResult = ((int (*)())ValueKey__tryMergeDestWith)(*keyRef,callResult), callResult != 0)) ||
              (callResult = ((int (*)())ValueKey__internScopedKey)(*keyRef,valueNumber,outermostScope), callResult != 0)))) {
            inst = *(int *)(*keyRef + 0xb0);
            currentDefinition = VReg__currentDefinition(*(undefined4 *)(inst + 0xa4),*(undefined4 *)(program + 0x3a0),
                                 *(uint *)(program + 8));
            if ((inst == *(int *)(currentDefinition + 0xb0)) &&
               (currentDefinition = Program__tryEliminateRedundantCopy(program,inst,block), currentDefinition != 0)) goto setResult;
          }
          vcall68Result = (**(code **)(**(int **)(*keyRef + 0xb0) + 0x68))(*(int **)(*keyRef + 0xb0));
          if (vcall68Result == 0) {
            vector2 = *(uint **)(program + 0x408);
            if (valueNumber < *vector2) {
              vectorFilledCount = vector2[1];
              if (vectorFilledCount <= valueNumber) {
                _memset(vectorFilledCount * 4 + vector2[2],0,(valueNumber - vectorFilledCount) * 4 + 4);
                vector2[1] = valueNumber + 1;
              }
              vectorElementRef = (undefined4 *)(valueNumber * 4 + vector2[2]);
            }
            else {
              vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector2,valueNumber);
            }
            HashTable__insert(*vectorElementRef,*keyRef);
            return 0;
          }
          goto loopSetResult;
        }
        eliminateRedundantInstResult = ((int (*)())Program__eliminateRedundantInst)(callResult2,*(undefined4 *)(*keyRef + 0xb0),block,program);
        if (eliminateRedundantInstResult == 0) goto loopSetResult;
        *keyRef = callResult2;
        vcall64Result = (**(code **)(**(int **)(callResult2 + 0xb0) + 100))(*(int **)(callResult2 + 0xb0));
        if (vcall64Result == 0) {
          lookupResultA = *(int *)(*keyRef + 0xb0);
          if (*(int *)(lookupResultA + 0x160) <= *(int *)(program + 0x478)) {
            *(int *)(lookupResultA + 0x160) = *(int *)(program + 0x478) + 1;
            return 1;
          }
          *(int *)(lookupResultA + 0x160) = *(int *)(lookupResultA + 0x160) + 1;
          return 1;
        }
      }
    }
    else {
      valueKey = ((int (*)())ValueKey__simplifyAll)(valueKey);
      if ((valueKey == 0) ||
         (valueKey = Program__tryEliminateRedundantCopy(program,*(undefined4 *)(*keyRef + 0xb0),block), valueKey == 0)) {
        valueKey = *keyRef;
        goto loopSetValueKey;
      }
    }
setResult:
    result = 1;
  }
  return result;
}

/* Ptr__equalNonNull @ 0x176264 (28 bytes) */
int Ptr__equalNonNull(ptrA, ptrB)
  int ptrA;
  int ptrB;
{
  if ((ptrA == ptrB) && (ptrA != 0)) {
    return 1;
  }
  return 0;
}

/* IROperand__copyRegisterAndSelect @ 0x176280 (28 bytes) */
int IROperand__copyRegisterAndSelect(dstRecord, srcRecord)
  int dstRecord;
  int srcRecord;
{
  undefined1 registerKindByte;
  undefined4 selectWord;
  
  registerKindByte = *(undefined1 *)(srcRecord + 8);
  selectWord = *(undefined4 *)(srcRecord + 0xc);
  *(undefined4 *)(dstRecord + 0x10) = *(undefined4 *)(srcRecord + 0x10);
  *(undefined1 *)(dstRecord + 8) = registerKindByte;
  *(undefined4 *)(dstRecord + 0xc) = selectWord;
  return;
}

/* ValueKey__callTargetHook12c @ 0x17629c (32 bytes) */
int ValueKey__callTargetHook12c(inst, compiler)
  undefined4 inst;
  int compiler;
{
                    
                    
  (**(code **)(**(int **)(compiler + 0x30c) + 300))(*(int **)(compiler + 0x30c),inst,compiler);
  return;
}

/* noop_1762bc @ 0x1762bc (4 bytes) */
int noop_1762bc()
{
  return;
}

/* Compiler__internLaneExprs1to3 @ 0x1762c0 (68 bytes) */
int Compiler__internLaneExprs1to3(compiler)
  undefined4 compiler;
{
  bool moreComponents;
  int loopIndex;
  
  loopIndex = 1;
  do {
    ((int (*)())Compiler__internPointer)(compiler,loopIndex);
    moreComponents = loopIndex != 3;
    loopIndex = loopIndex + 1;
  } while (moreComponents);
  return;
}

/* KhanPs__vslot56_scaleFloat @ 0x176304 (32 bytes) */
double KhanPs__vslot56_scaleFloat(double value)
{
  return (double)(float)(value * (double)FLOAT_001aa1cc);
}

/* signToCompareCode @ 0x176324 (44 bytes) */
int signToCompareCode(value)
  int value;
{
  if (value == 0) {
    return 3;
  }
  if (0 < value) {
    return 5;
  }
  if (value < 0) {
    return 1;
  }
  return 0;
}

/* classifyConstantRange @ 0x176350 (148 bytes) */
undefined4 classifyConstantRange(double value)
{
  if (value == (double)FLOAT_001aa0e8) {
    return 1;
  }
  if (value == (double)FLOAT_001aa114) {
    return 3;
  }
  if (value == (double)FLOAT_001aa0d4) {
    return 2;
  }
  if (((double)FLOAT_001aa0d4 <= value) && (value <= (double)FLOAT_001aa0e8)) {
    return 4;
  }
  if ((double)FLOAT_001aa114 <= value) {
    if (value <= (double)FLOAT_001aa0d4) {
      return 5;
    }
  }
  return 0;
}

/* ValueKey__rowLanesAllEqual @ 0x1763e4 (144 bytes) */
int ValueKey__rowLanesAllEqual(key, row)
  int key;
  int row;
{
  bool moreComponents;
  int callResult;
  int firstLaneValue;
  int loopIndex;
  int *loopPtr3;
  char *loopPtr2;
  
  loopPtr2 = (char *)(row * 4 + key + 0x224);
  loopPtr3 = (int *)(row * 0x10 + key + 0x168);
  firstLaneValue = 0;
  loopIndex = 0;
  do {
    if (*loopPtr2 != '\0') {
      if (firstLaneValue == 0) {
        firstLaneValue = *loopPtr3;
      }
      else {
        callResult = ((int (*)())Ptr__equalNonNull)(firstLaneValue,*loopPtr3);
        if (callResult == 0) {
          return 0;
        }
      }
    }
    moreComponents = loopIndex != 3;
    loopPtr2 = loopPtr2 + 1;
    loopPtr3 = loopPtr3 + 1;
    loopIndex = loopIndex + 1;
  } while (moreComponents);
  return 1;
}

/* ValueKey__findOrInsertLiteral @ 0x176474 (104 bytes) */
int ValueKey__findOrInsertLiteral(undefined4 unusedArg1,int key,int row,double literal)
{
  bool isLast;
  int loopIndex;
  float *loopPtr2;
  
  loopIndex = 1;
  loopPtr2 = (float *)(key + row * 0x10 + -0xc);
  while( true ) {
    if ((double)*loopPtr2 == literal) {
      return loopIndex + 1;
    }
    if ((double)*loopPtr2 == (double)FLOAT_001aa114) break;
    isLast = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + 1;
    if (isLast) {
      return 0;
    }
  }
  *loopPtr2 = (float)literal;
  return loopIndex + 1;
}

/* ValueKey__sourceWordIs4 @ 0x1764e0 (28 bytes) */
int ValueKey__sourceWordIs4(key, sourceIndex)
  int key;
  int sourceIndex;
{
  return *(int *)(sourceIndex * 4 + key + 0x70) == 4;
}

/* ValueKey__sourceKindIs1 @ 0x1764fc (28 bytes) */
int ValueKey__sourceKindIs1(key, sourceIndex)
  int key;
  int sourceIndex;
{
  return *(int *)(sourceIndex * 4 + key + 0xa0) == 1;
}

/* ValueKey__sourceKindIs4 @ 0x176518 (28 bytes) */
int ValueKey__sourceKindIs4(key, sourceIndex)
  int key;
  int sourceIndex;
{
  return *(int *)(sourceIndex * 4 + key + 0xa0) == 4;
}

/* ValueKey__compareValueNumbers @ 0x176534 (48 bytes) */
int ValueKey__compareValueNumbers(keyA, keyB)
  int keyA;
  int keyB;
{
  if (*(int *)(keyA + 300) == *(int *)(keyB + 300)) {
    return 0;
  }
  if ((*(int *)(keyA + 300) < 0) && (*(int *)(keyB + 300) < 0)) {
    return 1;
  }
  return 2;
}

/* Opcode__isF9 @ 0x176564 (16 bytes) */
int Opcode__isF9(opcode)
  int opcode;
{
  return opcode == 0xf9;
}

/* Opcode__isOneOf1fOr32OrA7A8 @ 0x176574 (48 bytes) */
int Opcode__isOneOf1fOr32OrA7A8(opcode)
  int opcode;
{
  if (opcode == 0x32) {
    return 1;
  }
  if (opcode < 0x33) {
    if (opcode == 0x1f) {
      return 1;
    }
  }
  else if (opcode - 0xa7U < 2) {
    return 1;
  }
  return 0;
}

/* ValueKey__setRowLiteral @ 0x1765a4 (64 bytes) */
int ValueKey__setRowLiteral(key, literalValue, row)
  int key;
  undefined4 literalValue;
  int row;
{
  undefined4 valueNumberForExprResult;
  
  valueNumberForExprResult = ((int (*)())Compiler__valueNumberForExpr)(*(undefined4 *)(key + 0x238),literalValue);
  *(undefined4 *)(row * 4 + key + 0x30) = valueNumberForExprResult;
  return;
}

/* FudoPs__vslot12_lookupTable6x @ 0x1765e4 (44 bytes) */
int FudoPs__vslot12_lookupTable6x(this, row, column)
  undefined4 this;
  int row;
  int column;
{
  return *(undefined4 *)(&fudoPsClassTable6x6_001e5f54 + (row * 6 + column) * 4);
}

/* FudoPs__vslot11_isNotType2Or5 @ 0x176610 (28 bytes) */
int FudoPs__vslot11_isNotType2Or5(this, typeCode)
  undefined4 this;
  int typeCode;
{
  if ((typeCode != 2) && (typeCode != 5)) {
    return 1;
  }
  return 0;
}

/* ValueKey__markUnsetLanesUnknown @ 0x17662c (144 bytes) */
int ValueKey__markUnsetLanesUnknown(ctx)
  int ctx;
{
  int operandRecord;
  bool moreComponents;
  int valueRecord;
  int loopIndex;
  int laneCursor;
  
  loopIndex = 0;
  laneCursor = ctx;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if ((*(char *)(loopIndex + operandRecord + 0x10) != '\x01') && (*(int *)(laneCursor + 0x30) == 0)) {
      valueRecord = *(int *)(laneCursor + 0x40);
      if (valueRecord == 0) {
        valueRecord = ((int (*)())Compiler__internLaneExpr)(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
        *(int *)(laneCursor + 0x40) = valueRecord;
      }
      *(undefined4 *)(valueRecord + 0xc) = 4;
    }
    moreComponents = loopIndex != 3;
    laneCursor = laneCursor + 4;
    loopIndex = loopIndex + 1;
  } while (moreComponents);
  return;
}

/* ValueKey__replaceWithMovIfZero @ 0x1766bc (112 bytes) */
int ValueKey__replaceWithMovIfZero(ctx)
  int ctx;
{
  int valueNumberForExprResult;
  undefined4 opcodeInfo;
  int producerInst;
  undefined4 changed;
  
  valueNumberForExprResult = ((int (*)())Compiler__valueNumberForExpr)(*(undefined4 *)(ctx + 0x238),0);
  if ((*(int *)(valueNumberForExprResult + 4) == *(int *)(ctx + 0x184)) ||
     (changed = 0, *(int *)(valueNumberForExprResult + 4) == *(int *)(ctx + 0x194))) {
    producerInst = *(int *)(ctx + 0xb0);
    opcodeInfo = Opcode__getInfo(0x1c);
    *(undefined4 *)(producerInst + 0x88) = opcodeInfo;
    ((int (*)())ValueKey__rebuild)(ctx);
    changed = 1;
  }
  return changed;
}

/* ValueKey__allRowsKnown @ 0x17672c (172 bytes) */
int ValueKey__allRowsKnown(ctx)
  int ctx;
{
  int rowOffset;
  int vcall14Result;
  int loopIndex;
  
  loopIndex = 1;
  while( true ) {
    vcall14Result = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0));
    if (vcall14Result < loopIndex) {
      return 1;
    }
    rowOffset = OpcodeTraits__instFlagBit2(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(ctx + 0xb0));
    if ((rowOffset == 0) || ((rowOffset = 3, loopIndex != 1 && (rowOffset = 1, loopIndex != 3)))) {
      rowOffset = 0;
    }
    if (-1 < *(int *)((loopIndex * 4 + rowOffset) * 4 + ctx + 0x168)) break;
    loopIndex = loopIndex + 1;
  }
  return 0;
}

/* ValueKey__rowKnown @ 0x1767d8 (124 bytes) */
int ValueKey__rowKnown(ctx, row)
  int ctx;
  int row;
{
  int valueNumber;
  int vcall14Result;
  int loopIndex;
  int *valueCursor;
  
  valueCursor = (int *)(row * 4 + ctx + 0x178);
  loopIndex = 1;
  while( true ) {
    vcall14Result = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0));
    if (vcall14Result < loopIndex) {
      return 1;
    }
    valueNumber = *valueCursor;
    valueCursor = valueCursor + 4;
    if (-1 < valueNumber) break;
    loopIndex = loopIndex + 1;
  }
  return 0;
}

/* ValueKey__lanesAreUnset @ 0x176854 (128 bytes) */
int ValueKey__lanesAreUnset(key, row, testLane0, testLane1, testLane2, testLane3)
  int key;
  int row;
  int testLane0;
  int testLane1;
  int testLane2;
  int testLane3;
{
  if (((((testLane0 == 0) || (*(int *)(row * 0x10 + key + 0x168) < 0)) &&
       ((testLane1 == 0 || (*(int *)(row * 0x10 + key + 0x16c) < 0)))) &&
      ((testLane2 == 0 || (*(int *)(row * 0x10 + key + 0x170) < 0)))) &&
     ((testLane3 == 0 || (*(int *)(row * 0x10 + key + 0x174) < 0)))) {
    return 1;
  }
  return 0;
}

/* ValueKey__findKnownRowRecord @ 0x1768d4 (128 bytes) */
int ValueKey__findKnownRowRecord(key, row)
  int key;
  int row;
{
  bool isLast;
  int rowBase;
  int *exprRecordForValueNumberResult;
  int loopIndex;
  int *valueCursor;
  
  rowBase = row * 4 + key;
  valueCursor = (int *)(rowBase + 0x178);
  loopIndex = 1;
  while ((-1 < *valueCursor ||
         (exprRecordForValueNumberResult = (int *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),*valueCursor), *exprRecordForValueNumberResult != 0))) {
    isLast = loopIndex == 2;
    valueCursor = valueCursor + 4;
    loopIndex = loopIndex + 1;
    if (isLast) {
      return 0;
    }
  }
  *(int **)(rowBase + 0x30) = exprRecordForValueNumberResult;
  return 1;
}

/* ValueKey__foldCompareLiterals @ 0x176954 (160 bytes) */
int ValueKey__foldCompareLiterals(ctx, row)
  int ctx;
  int row;
{
  float *exprRecordForValueNumberResult;
  float *exprRecordForValueNumberResultB;
  undefined4 valueNumberForExprResult;
  undefined4 literalOrResult;
  int rowBase;
  int evaluateCompareFloatsResult;
  
  rowBase = row * 4 + ctx;
  if ((*(int *)(rowBase + 0x178) < 0) && (*(int *)(rowBase + 0x188) < 0)) {
    exprRecordForValueNumberResult = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(int *)(rowBase + 0x178));
    exprRecordForValueNumberResultB = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(rowBase + 0x188));
    evaluateCompareFloatsResult = ((bool (*)())evaluateCompareFloats)(*(undefined4 *)(ctx + 0xb0),(double)*exprRecordForValueNumberResult,(double)*exprRecordForValueNumberResultB);
    literalOrResult = 0x3f800000;
    if (evaluateCompareFloatsResult == 0) {
      literalOrResult = 0;
    }
    valueNumberForExprResult = ((int (*)())Compiler__valueNumberForExpr)(*(undefined4 *)(ctx + 0x238),literalOrResult);
    literalOrResult = 1;
    *(undefined4 *)(row * 4 + ctx + 0x30) = valueNumberForExprResult;
  }
  else {
    literalOrResult = 0;
  }
  return literalOrResult;
}

/* ValueKey__getRowLaneValue @ 0x1769f4 (160 bytes) */
int ValueKey__getRowLaneValue(outValue, key, lane)
  undefined4 *outValue;
  int key;
  int lane;
{
  int rowOrValueNumber;
  undefined4 *exprRecordForValueNumberResult;
  
  rowOrValueNumber = OpcodeTraits__instFlagBit2(*(undefined4 *)(key + 0x238),*(undefined4 *)(key + 0xb0));
  if ((rowOrValueNumber == 0) || ((rowOrValueNumber = 3, lane != 1 && (rowOrValueNumber = 1, lane != 3)))) {
    rowOrValueNumber = 0;
  }
  rowOrValueNumber = *(int *)((lane * 4 + rowOrValueNumber) * 4 + key + 0x168);
  if (rowOrValueNumber < 0) {
    exprRecordForValueNumberResult = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),rowOrValueNumber);
    *outValue = *exprRecordForValueNumberResult;
  }
  else {
    *outValue = 0x7ffffffe;
  }
  return outValue;
}

/* ValueKey__evaluateConstantInst @ 0x176a94 (428 bytes) */
int ValueKey__evaluateConstantInst(outValue, valueKey, outClampedFlag)
  float *outValue;
  int valueKey;
  undefined4 *outClampedFlag;
{
  bool moreLanes;
  undefined4 valueNumberTable;
  undefined4 *loopPtr;
  int *opcodeInfo;
  undefined4 operand1ValueNumber;
  undefined4 operand3ValueNumber;
  undefined4 operand2ValueNumber;
  int laneByteOffset;
  int loopRemaining;
  undefined4 operand1Values [4];
  undefined4 operand2Values [4];
  undefined4 operand3Values [4];
  float scaledValue;
  float clampedValue;
  float param_3_w;
  
  loopRemaining = 4;
  *outValue = GH_U2F(0x7fff0000U);
  loopPtr = operand1Values;
  do {
    *loopPtr = 0x7ffffffe;
    loopPtr = loopPtr + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  loopRemaining = 4;
  loopPtr = operand2Values;
  do {
    *loopPtr = 0x7ffffffe;
    loopPtr = loopPtr + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  loopRemaining = 4;
  loopPtr = operand3Values;
  do {
    *loopPtr = 0x7ffffffe;
    loopPtr = loopPtr + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  laneByteOffset = 0;
  loopRemaining = valueKey;
  do {
    valueNumberTable = *(undefined4 *)(valueKey + 0x238);
    operand1ValueNumber = *(undefined4 *)(loopRemaining + 0x178);
    *(undefined4 *)(laneByteOffset + (int)operand1Values) = 0;
    loopPtr = (undefined4 *)Compiler__exprRecordForValueNumber(valueNumberTable,operand1ValueNumber);
    if (loopPtr != (undefined4 *)0x0) {
      *(undefined4 *)(laneByteOffset + (int)operand1Values) = *loopPtr;
    }
    valueNumberTable = *(undefined4 *)(valueKey + 0x238);
    operand2ValueNumber = *(undefined4 *)(loopRemaining + 0x188);
    *(undefined4 *)(laneByteOffset + (int)operand2Values) = 0;
    loopPtr = (undefined4 *)Compiler__exprRecordForValueNumber(valueNumberTable,operand2ValueNumber);
    if (loopPtr != (undefined4 *)0x0) {
      *(undefined4 *)(laneByteOffset + (int)operand2Values) = *loopPtr;
    }
    valueNumberTable = *(undefined4 *)(valueKey + 0x238);
    operand3ValueNumber = *(undefined4 *)(loopRemaining + 0x198);
    *(undefined4 *)(laneByteOffset + (int)operand3Values) = 0;
    loopPtr = (undefined4 *)Compiler__exprRecordForValueNumber(valueNumberTable,operand3ValueNumber);
    if (loopPtr != (undefined4 *)0x0) {
      *(undefined4 *)(laneByteOffset + (int)operand3Values) = *loopPtr;
    }
    moreLanes = laneByteOffset != 0xc;
    loopRemaining = loopRemaining + 4;
    laneByteOffset = laneByteOffset + 4;
  } while (moreLanes);
  *outValue = GH_U2F(0x7fff0000U);
  opcodeInfo = *(int **)(*(int *)(valueKey + 0xb0) + 0x88);
  (**(code **)(*opcodeInfo + 8))
            (opcodeInfo,outValue,operand1Values,operand2Values,operand3Values,*(undefined4 *)(valueKey + 0x238));
  param_3_w = *outValue;
  if (param_3_w != FLOAT_001aa1d0) {
    IRInst__scaleByOutputScale(&scaledValue,*(undefined4 *)(valueKey + 0xb0),param_3_w);
    *outValue = scaledValue;
    IRInst__clampOutputValue(&clampedValue,*(undefined4 *)(valueKey + 0xb0),scaledValue);
    if (clampedValue != *outValue) {
      *outClampedFlag = 1;
      *outValue = clampedValue;
    }
  }
  return outValue;
}

/* ValueKey__evaluateConstantLane @ 0x176c40 (300 bytes) */
int ValueKey__evaluateConstantLane(resultOut, valueKey, laneIndex, clampedFlag)
  int *resultOut;
  int valueKey;
  int laneIndex;
  undefined4 *clampedFlag;
{
  int countdown;
  undefined4 *exprRecordForValueNumberResult;
  int callResult;
  int *opcodeInfo;
  undefined4 staleArg7;
  undefined4 staleArg8;
  undefined4 *loopPtr2;
  code *evalFn;
  undefined4 *laneValueCursor;
  int operandIdx;
  undefined4 constOperandValues [8];
  int scaledResult;
  int clampedResult [2];
  
  countdown = 5;
  loopPtr2 = constOperandValues;
  do {
    *loopPtr2 = 0x7ffffffe;
    loopPtr2 = loopPtr2 + 1;
    countdown = countdown + -1;
  } while (countdown != 0);
  loopPtr2 = constOperandValues;
  operandIdx = 1;
  *resultOut = 0x7ffffffe;
  laneValueCursor = (undefined4 *)(laneIndex * 4 + valueKey + 0x178);
  while( true ) {
    loopPtr2 = loopPtr2 + 1;
    callResult = (**(code **)(**(int **)(valueKey + 0xb0) + 0x14))(*(int **)(valueKey + 0xb0));
    if (callResult < operandIdx) break;
    operandIdx = operandIdx + 1;
    exprRecordForValueNumberResult = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(valueKey + 0x238),*laneValueCursor);
    *loopPtr2 = *exprRecordForValueNumberResult;
    laneValueCursor = laneValueCursor + 4;
  }
  opcodeInfo = *(int **)(*(int *)(valueKey + 0xb0) + 0x88);
  evalFn = *(code **)(*opcodeInfo + 4);
  (*evalFn)(opcodeInfo,resultOut,constOperandValues,*(undefined4 *)(valueKey + 0x238),staleArg7,staleArg8,evalFn);
  if (*resultOut != 0x7ffffffe) {
    IRInst__scaleByOutputScale(&scaledResult,*(undefined4 *)(valueKey + 0xb0),*resultOut);
    *resultOut = scaledResult;
    IRInst__clampOutputValue(clampedResult,*(undefined4 *)(valueKey + 0xb0),scaledResult);
    if (clampedResult[0] != *resultOut) {
      *clampedFlag = 1;
      *resultOut = clampedResult[0];
    }
  }
  return resultOut;
}

/* Compiler__valueNumbersRelatedByFields20 @ 0x176d6c (160 bytes) */
int Compiler__valueNumbersRelatedByFields20(valueNumberA, valueNumberB, compiler)
  int valueNumberA;
  int valueNumberB;
  undefined4 compiler;
{
  int findInPtrSetResult;
  int findInPtrSetResultB;
  undefined4 related;
  
  if ((((valueNumberA < 1) || (valueNumberB < 1)) || (findInPtrSetResult = Compiler__findInPtrSet(compiler,valueNumberA), findInPtrSetResult == 0)) ||
     ((findInPtrSetResultB = Compiler__findInPtrSet(compiler,valueNumberB), findInPtrSetResultB == 0 ||
      (((*(int *)(findInPtrSetResult + 0x20) == 0 || (valueNumberB != *(int *)(findInPtrSetResult + 0x24))) &&
       ((*(int *)(findInPtrSetResultB + 0x20) == 0 || (valueNumberA != *(int *)(findInPtrSetResultB + 0x24))))))))) {
    related = 0;
  }
  else {
    related = 1;
  }
  return related;
}

/* Compiler__valueNumbersRelatedByFields28 @ 0x176e20 (160 bytes) */
int Compiler__valueNumbersRelatedByFields28(valueNumberA, valueNumberB, compiler)
  int valueNumberA;
  int valueNumberB;
  undefined4 compiler;
{
  int findInPtrSetResult;
  int findInPtrSetResultB;
  undefined4 related;
  
  if ((((valueNumberA < 1) || (valueNumberB < 1)) || (findInPtrSetResult = Compiler__findInPtrSet(compiler,valueNumberA), findInPtrSetResult == 0)) ||
     ((findInPtrSetResultB = Compiler__findInPtrSet(compiler,valueNumberB), findInPtrSetResultB == 0 ||
      (((*(int *)(findInPtrSetResult + 0x28) == 0 || (valueNumberB != *(int *)(findInPtrSetResult + 0x2c))) &&
       ((*(int *)(findInPtrSetResultB + 0x28) == 0 || (valueNumberA != *(int *)(findInPtrSetResultB + 0x2c))))))))) {
    related = 0;
  }
  else {
    related = 1;
  }
  return related;
}

/* ValueKey__valueNumbersRelated @ 0x176ec0 (20 bytes) */
int ValueKey__valueNumbersRelated(key, valueNumberA, valueNumberB)
  int key;
  undefined4 valueNumberA;
  undefined4 valueNumberB;
{
  undefined4 callResult;
  
  callResult = ((int (*)())Compiler__valueNumbersRelatedByFields28)(valueNumberA,valueNumberB,*(undefined4 *)(key + 0x238));
  return callResult;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_00176304");
asm(".set FUN_00176304, _KhanPs__vslot56_scaleFloat");
asm(".globl FUN_001765e4");
asm(".set FUN_001765e4, _FudoPs__vslot12_lookupTable6x");
asm(".globl FUN_00176610");
asm(".set FUN_00176610, _FudoPs__vslot11_isNotType2Or5");
