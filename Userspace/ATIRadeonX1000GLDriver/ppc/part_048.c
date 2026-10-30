#include "decls.h"

/* Inst__findLaneProducer @ 0x17bc58 (288 bytes) */
int Inst__findLaneProducer(inst, laneMask, relinkFlag, compilerCtx)
  undefined4 inst;
  uint laneMask;
  int relinkFlag;
  undefined4 compilerCtx;
{
  int *callResult2;
  int *source1;
  int callResult;
  undefined4 producerSelectWord;
  uint local_28 [3];
  
  callResult2 = (int *)IRInst__getOperandSource(inst,1);
  while( true ) {
    callResult = (**(code **)(*callResult2 + 0x40))(callResult2);
    if (callResult != 0) {
      return callResult2;
    }
    callResult = IRInst__getOperandRecord(callResult2,0);
    producerSelectWord = *(undefined4 *)(callResult + 0x10);
    callResult = FUN_00176534(inst,callResult2);
    if (callResult == 2) break;
    if ((callResult == 0) && (WriteMask__fromSelectWord(local_28,producerSelectWord), (laneMask & local_28[0]) != DAT_001b01e0)) {
      return callResult2;
    }
    callResult2 = (int *)IRInst__getOperandSource(callResult2,3);
  }
  if ((relinkFlag != 0) && (source1 = (int *)IRInst__getOperandSource(inst,1), callResult2 != source1)) {
    IRInst__setOperandSource(inst,1,callResult2,0,compilerCtx);
    return (int *)0x0;
  }
  return (int *)0x0;
}

/* ValueKey__rewriteAsMovOfOperandLane @ 0x17bd78 (388 bytes) */
int ValueKey__rewriteAsMovOfOperandLane(ctx, operandIndex, lane, resultScaleCode)
  int ctx;
  int operandIndex;
  int lane;
  undefined4 resultScaleCode;
{
  undefined4 operandSelectWord;
  int inst;
  int operandRecord2;
  int operandRecord;
  bool noExtraSource;
  byte laneSelectByte;
  uint operandFlags;
  int node;
  int inst2;
  uint instFlags;
  undefined4 operandRef3;
  undefined4 afterInst;
  undefined4 block;
  undefined4 operandValueNumber;
  undefined4 destSelectWord;
  undefined4 operandRef;
  undefined4 operandRef2;
  undefined4 saturate;
  undefined4 destRegister;
  undefined4 destRegisterOffset;
  undefined4 extraValueNumber;
  
  node = *(int *)(ctx + 0xb0);
  afterInst = *(undefined4 *)(node + 4);
  block = *(undefined4 *)(node + 0x158);
  DList__unlink(node);
  operandRef2 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  operandRecord2 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  inst = *(int *)(ctx + 0xb0);
  destSelectWord = *(undefined4 *)(operandRecord2 + 0x10);
  operandRef = *(undefined4 *)(operandIndex * 0x18 + inst + 0x8c);
  saturate = *(undefined4 *)(inst + 0x120);
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  inst2 = *(int *)(ctx + 0xb0);
  laneSelectByte = *(byte *)(lane + operandRecord + 0x10);
  instFlags = *(uint *)(inst2 + 0x14);
  operandFlags = *(uint *)(operandIndex * 0x18 + inst2 + 0xa0);
  operandValueNumber = *(undefined4 *)(operandIndex * 4 + ctx + 0x210);
  noExtraSource = (instFlags >> 9 & 1) == 0;
  if (noExtraSource) {
    operandRef3 = 0;
    extraValueNumber = 0;
  }
  else {
    extraValueNumber = *(undefined4 *)(*(int *)(inst2 + 0x84) * 4 + ctx + 0x210);
    operandRef3 = *(undefined4 *)(*(int *)(inst2 + 0x84) * 0x18 + inst2 + 0x8c);
  }
  destRegister = *(undefined4 *)(inst2 + 0x94);
  destRegisterOffset = *(undefined4 *)(inst2 + 0x98);
  IRInst__reinitAsMov(inst2,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(inst2,0,operandRef2);
  *(undefined4 *)(inst2 + 0x94) = destRegister;
  *(undefined4 *)(inst2 + 0x98) = destRegisterOffset;
  *(undefined4 *)(inst2 + 0x9c) = destSelectWord;
  *(undefined4 *)(inst2 + 0x120) = saturate;
  *(undefined4 *)(inst2 + 0x124) = resultScaleCode;
  IRInst__setOperandRef(inst2,1,operandRef);
  operandSelectWord = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)laneSelectByte * 4);
  operandRecord = IRInst__getOperandRecord(inst2,1);
  *(undefined4 *)(operandRecord + 0x10) = operandSelectWord;
  IROperand__setModifierBits(inst2 + 0xa4,1,operandFlags & 1);
  IROperand__setModifierBits(inst2 + 0xa4,2,operandFlags >> 1 & 1);
  *(undefined4 *)(ctx + 0x214) = operandValueNumber;
  if (noExtraSource) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(inst2,operandRef3);
    *(uint *)(inst2 + 0x14) = *(uint *)(inst2 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = extraValueNumber;
  }
  if ((instFlags & 0x200000) != 0) {
    *(uint *)(inst2 + 0x14) = *(uint *)(inst2 + 0x14) | 0x200000;
  }
  Block__insertInstAfter(block,afterInst,inst2);
  return inst2;
}

/* ValueKey__foldDot3SingleLaneSource @ 0x17bf70 (392 bytes) */
int ValueKey__foldDot3SingleLaneSource(ctx)
  int ctx;
{
  int lanesAreUnset;
  int exprRecord;
  bool notLastTriple;
  int zeroValueNumber;
  int operandRowOffset;
  float *exprRecord2;
  int *a0;
  int scaleAccepted;
  undefined4 a3;
  int scaleExponent;
  undefined4 a4;
  undefined4 a5;
  code *a6;
  int loopRemaining;
  int loopIndex;
  int *laneTriplePtr;
  
  loopRemaining = 2;
  exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0);
  zeroValueNumber = *(int *)(exprRecord + 4);
  do {
    a3 = 1;
    a4 = 1;
    a5 = 0;
    lanesAreUnset = ValueKey__lanesAreUnset(ctx,loopRemaining,1,1,1,0);
    if (lanesAreUnset != 0) {
      loopIndex = 0;
      laneTriplePtr = &DAT_001e6134;
      operandRowOffset = loopRemaining * 4;
      do {
        if ((zeroValueNumber == *(int *)((operandRowOffset + *laneTriplePtr) * 4 + ctx + 0x168)) &&
           (zeroValueNumber == *(int *)((operandRowOffset + laneTriplePtr[1]) * 4 + ctx + 0x168))) {
          exprRecord2 = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),
                                         *(undefined4 *)((operandRowOffset + laneTriplePtr[2]) * 4 + ctx + 0x168))
          ;
          if ((double)*exprRecord2 == 1.0) {
            scaleExponent = *(int *)(*(int *)(ctx + 0xb0) + 0x124);
LAB_0017c0b0:
            ((int (*)())ValueKey__rewriteAsMovOfOperandLane)(ctx,(loopRemaining == 1) + 1,loopIndex,scaleExponent);
            ValueKey__rebuild(ctx);
            return 1;
          }
          scaleExponent = ((int (*)())outputScaleExponent)((double)*exprRecord2);
          if (scaleExponent != 0) {
            a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
            scaleExponent = scaleExponent + *(int *)(*(int *)(ctx + 0xb0) + 0x124);
            a6 = *(code **)(*a0 + 0xfc);
            scaleAccepted = (*a6)(a0,scaleExponent,*(int *)(ctx + 0xb0),a3,a4,a5,a6);
            if (scaleAccepted != 0) goto LAB_0017c0b0;
          }
        }
        notLastTriple = loopIndex != 2;
        laneTriplePtr = laneTriplePtr + 3;
        loopIndex = loopIndex + 1;
      } while (notLastTriple);
    }
    loopRemaining = loopRemaining + -1;
    if (loopRemaining == 0) {
      return 0;
    }
  } while( true );
}

/* ValueKey__foldDot4UnitVectorSource @ 0x17c0f8 (332 bytes) */
int ValueKey__foldDot4UnitVectorSource(ctx)
  int ctx;
{
  int exprRecord;
  int laneEntryBase;
  int operandNumber;
  undefined4 unitLane;
  undefined4 resultScaleCode;
  int oneValueNumber;
  int laneValueNumber2;
  int laneValueNumber1;
  int loopRemaining;
  int zeroValueNumber;
  
  exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0);
  zeroValueNumber = *(int *)(exprRecord + 4);
  exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0x3f800000);
  operandNumber = 1;
  oneValueNumber = *(int *)(exprRecord + 4);
  loopRemaining = 2;
  laneEntryBase = ctx + 0x20;
  do {
    laneValueNumber1 = *(int *)(laneEntryBase + 0x16c);
    if ((((zeroValueNumber == laneValueNumber1) && (zeroValueNumber == *(int *)(laneEntryBase + 0x170))) &&
        (zeroValueNumber == *(int *)(laneEntryBase + 0x174))) && (oneValueNumber == *(int *)(laneEntryBase + 0x168))) {
      unitLane = 0;
      resultScaleCode = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124);
      goto LAB_0017c1c4;
    }
    if (zeroValueNumber == *(int *)(laneEntryBase + 0x168)) {
      laneValueNumber2 = *(int *)(laneEntryBase + 0x170);
      if (((zeroValueNumber == laneValueNumber2) && (laneValueNumber2 == *(int *)(laneEntryBase + 0x174))) && (oneValueNumber == laneValueNumber1)) {
        unitLane = 1;
        resultScaleCode = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124);
        goto LAB_0017c1c4;
      }
      if (zeroValueNumber == laneValueNumber1) {
        if ((zeroValueNumber == *(int *)(laneEntryBase + 0x174)) && (oneValueNumber == laneValueNumber2)) {
          unitLane = 2;
          resultScaleCode = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124);
LAB_0017c1c4:
          ((int (*)())ValueKey__rewriteAsMovOfOperandLane)(ctx,operandNumber,unitLane,resultScaleCode);
          ValueKey__rebuild(ctx);
          return 1;
        }
        if ((zeroValueNumber == laneValueNumber2) && (oneValueNumber == *(int *)(laneEntryBase + 0x174))) {
          unitLane = 3;
          resultScaleCode = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124);
          goto LAB_0017c1c4;
        }
      }
    }
    loopRemaining = loopRemaining + -1;
    laneEntryBase = laneEntryBase + -0x10;
    if (loopRemaining < 1) {
      return 0;
    }
    operandNumber = (loopRemaining == 1) + 1;
  } while( true );
}

/* ValueKey__rewriteAsMovOfOperand @ 0x17c244 (356 bytes) */
int ValueKey__rewriteAsMovOfOperand(ctx, operandIndex)
  int ctx;
  int operandIndex;
{
  int inst;
  int operandRecord2;
  int operandRecord;
  bool noExtraSource;
  uint operandFlags;
  int node;
  int inst2;
  uint instFlags;
  undefined4 operandRef3;
  undefined4 afterInst;
  undefined4 block;
  undefined4 operandValueNumber;
  undefined4 destSelectWord;
  undefined4 operandRef;
  undefined4 operandRef2;
  undefined4 saturate;
  undefined4 resultScaleCode;
  undefined4 operandSelectWord;
  undefined4 destRegister;
  undefined4 destRegisterOffset;
  undefined4 extraValueNumber;
  
  node = *(int *)(ctx + 0xb0);
  afterInst = *(undefined4 *)(node + 4);
  block = *(undefined4 *)(node + 0x158);
  DList__unlink(node);
  operandRef2 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  operandRecord2 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  inst = *(int *)(ctx + 0xb0);
  destSelectWord = *(undefined4 *)(operandRecord2 + 0x10);
  operandRef = *(undefined4 *)(operandIndex * 0x18 + inst + 0x8c);
  saturate = *(undefined4 *)(inst + 0x120);
  resultScaleCode = *(undefined4 *)(inst + 0x124);
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  inst2 = *(int *)(ctx + 0xb0);
  operandSelectWord = *(undefined4 *)(operandRecord + 0x10);
  instFlags = *(uint *)(inst2 + 0x14);
  operandFlags = *(uint *)(operandIndex * 0x18 + inst2 + 0xa0);
  operandValueNumber = *(undefined4 *)(operandIndex * 4 + ctx + 0x210);
  noExtraSource = (instFlags >> 9 & 1) == 0;
  if (noExtraSource) {
    operandRef3 = 0;
    extraValueNumber = 0;
  }
  else {
    extraValueNumber = *(undefined4 *)(*(int *)(inst2 + 0x84) * 4 + ctx + 0x210);
    operandRef3 = *(undefined4 *)(*(int *)(inst2 + 0x84) * 0x18 + inst2 + 0x8c);
  }
  destRegister = *(undefined4 *)(inst2 + 0x94);
  destRegisterOffset = *(undefined4 *)(inst2 + 0x98);
  IRInst__reinitAsMov(inst2,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(inst2,0,operandRef2);
  *(undefined4 *)(inst2 + 0x98) = destRegisterOffset;
  *(undefined4 *)(inst2 + 0x94) = destRegister;
  *(undefined4 *)(inst2 + 0x9c) = destSelectWord;
  *(undefined4 *)(inst2 + 0x120) = saturate;
  *(undefined4 *)(inst2 + 0x124) = resultScaleCode;
  IRInst__setOperandRef(inst2,1,operandRef);
  operandRecord = IRInst__getOperandRecord(inst2,1);
  *(undefined4 *)(operandRecord + 0x10) = operandSelectWord;
  IROperand__setModifierBits(inst2 + 0xa4,1,operandFlags & 1);
  IROperand__setModifierBits(inst2 + 0xa4,2,operandFlags >> 1 & 1);
  *(undefined4 *)(ctx + 0x214) = operandValueNumber;
  if (noExtraSource) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(inst2,operandRef3);
    *(uint *)(inst2 + 0x14) = *(uint *)(inst2 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = extraValueNumber;
  }
  if ((instFlags & 0x200000) != 0) {
    *(uint *)(inst2 + 0x14) = *(uint *)(inst2 + 0x14) | 0x200000;
  }
  Block__insertInstAfter(block,afterInst,inst2);
  return inst2;
}

/* ValueKey__replaceWithSource2IfSourcesEqual23 @ 0x17c41c (136 bytes) */
int ValueKey__replaceWithSource2IfSourcesEqual23(ctx)
  int ctx;
{
  uint uVar1;
  int callResult;
  uint uVar3;
  
  callResult = Inst__allWrittenLanesSatisfy(ctx,2,3);
  if (callResult != 0) {
    uVar3 = *(uint *)(*(int *)(ctx + 0xb0) + 0xe8);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    if (((uVar1 & 1) == (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      ((int (*)())ValueKey__rewriteAsMovOfOperand)(ctx,2);
      ValueKey__rebuild(ctx);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017c4a4 @ 0x17c4a4 (316 bytes) */
int FUN_0017c4a4(ctx)
  int ctx;
{
  uint word0xe8Bit0;
  uint word0xd0Bit0;
  int *a0;
  int inst;
  undefined4 mask;
  
  a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
  inst = (**(code **)(*a0 + 0x88))(a0);
  if (((inst == 0) || (inst = Inst__allWrittenLanesSatisfy(ctx,2,3), inst == 0)) ||
     (inst = Inst__allWrittenLanesSatisfy(ctx,1,3), inst == 0)) {
    return 0;
  }
  inst = *(int *)(ctx + 0xb0);
  if ((*(uint *)(inst + 0xb8) & 2) != 0) {
    return 0;
  }
  if ((*(uint *)(inst + 0xd0) & 2) != 0) {
    return 0;
  }
  if ((*(uint *)(inst + 0xe8) & 2) != 0) {
    return 0;
  }
  word0xe8Bit0 = *(uint *)(inst + 0xe8) & 1;
  word0xd0Bit0 = *(uint *)(inst + 0xd0) & 1;
  if ((*(uint *)(inst + 0xb8) & 1) == 0) {
    if (word0xd0Bit0 != 0) {
      return 0;
    }
    if (word0xe8Bit0 == 0) {
      return 0;
    }
  }
  else {
    if (word0xd0Bit0 == 0) {
      if (word0xe8Bit0 == 0) {
        return 0;
      }
      ((int (*)())ValueKey__rewriteAsMovOfOperand)(ctx,2);
      IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,2,1);
      inst = *(int *)(ctx + 0xb0);
      mask = 1;
      goto LAB_0017c5b4;
    }
    if (word0xe8Bit0 != 0) {
      return 0;
    }
  }
  ((int (*)())ValueKey__rewriteAsMovOfOperand)(ctx,2);
  inst = *(int *)(ctx + 0xb0);
  mask = 2;
LAB_0017c5b4:
  IROperand__setModifierBits(inst + 0xa4,mask,1);
  ValueKey__rebuild(ctx);
  return 1;
}

/* FUN_0017c5e0 @ 0x17c5e0 (404 bytes) */
int FUN_0017c5e0(ctx)
  int ctx;
{
  int currentProgram;
  int operandClass;
  int findInPtrSetResult;
  int compareCondition;
  int operandRecord;
  bool laneFlag;
  bool usedUniformConstant;
  int compareCode;
  int inst;
  undefined4 *exprRecord;
  int laneResult;
  int prevLaneResult;
  int loopIndex;
  int laneEntryPtr;
  
  usedUniformConstant = false;
  compareCode = signToCompareCode(0);
  loopIndex = 0;
  prevLaneResult = -1;
  laneEntryPtr = ctx;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    laneResult = prevLaneResult;
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      operandClass = *(int *)(laneEntryPtr + 0x178);
      if (operandClass < 0) {
        exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),operandClass);
        operandClass = signToCompareCode(*exprRecord);
        inst = *(int *)(ctx + 0xb0);
      }
      else {
        if (operandClass < 1) {
          return 0;
        }
        findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),operandClass);
        inst = *(int *)(ctx + 0xb0);
        operandClass = *(int *)(findInPtrSetResult + 0xc);
        if ((*(uint *)(inst + 0xb8) & 2) != 0) {
          operandClass = (DAT_001e61d0)[operandClass];
        }
        usedUniformConstant = true;
        if ((*(uint *)(inst + 0xb8) & 1) != 0) {
          operandClass = *(int *)(&DAT_001e61b8 + operandClass * 4);
        }
      }
      compareCondition = IRInst__getCompareCondition(inst);
      operandClass = *(int *)(&DAT_001e61e8 + (compareCondition * 6 + operandClass * 0x30 + compareCode) * 4);
      if (operandClass == 1) {
        laneResult = 2;
      }
      else if (operandClass == 2) {
        laneResult = 3;
      }
      else {
        if (operandClass == 0) {
          return 0;
        }
        laneResult = 0;
      }
      if ((prevLaneResult != -1) && (laneFlag = laneResult != prevLaneResult, laneResult = prevLaneResult, laneFlag)) {
        return 0;
      }
    }
    laneFlag = loopIndex == 3;
    laneEntryPtr = laneEntryPtr + 4;
    loopIndex = loopIndex + 1;
    prevLaneResult = laneResult;
    if (laneFlag) {
      if (usedUniformConstant) {
        currentProgram = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
        *(int *)(currentProgram + 0x134) = *(int *)(currentProgram + 0x134) + 1;
      }
      ((int (*)())ValueKey__rewriteAsMovOfOperand)(ctx,laneResult);
      ValueKey__rebuild(ctx);
      return 1;
    }
  } while( true );
}

/* ValueKey__foldMulByPlusMinusOne @ 0x17c774 (276 bytes) */
int ValueKey__foldMulByPlusMinusOne(ctx)
  int ctx;
{
  int lanesAllMatch;
  int exprRecord;
  bool bVar1;
  int iVar2;
  int loopIndex;
  undefined4 uVar4;
  
  loopIndex = 1;
  exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0x3f800000);
  uVar4 = *(undefined4 *)(exprRecord + 4);
  do {
    lanesAllMatch = Inst__writtenLanesAllMatchValue(ctx,uVar4,loopIndex);
    if (lanesAllMatch != 0) {
      ((int (*)())ValueKey__rewriteAsMovOfOperand)(ctx,(loopIndex == 1) + 1);
      ValueKey__rebuild(ctx);
      return 1;
    }
    bVar1 = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  loopIndex = 1;
  exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0xbf800000);
  uVar4 = *(undefined4 *)(exprRecord + 4);
  do {
    lanesAllMatch = Inst__writtenLanesAllMatchValue(ctx,uVar4,loopIndex);
    if (lanesAllMatch != 0) {
      iVar2 = (loopIndex == 1) + 1;
      ((int (*)())ValueKey__rewriteAsMovOfOperand)(ctx,iVar2);
      IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,1,
                   *(uint *)(iVar2 * 0x18 + *(int *)(ctx + 0xb0) + 0xa0) & 1 ^ 1);
      ValueKey__rebuild(ctx);
      return 1;
    }
    bVar1 = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  return 0;
}

/* ValueKey__replaceWithSource1IfSourcesEqual @ 0x17c888 (136 bytes) */
int ValueKey__replaceWithSource1IfSourcesEqual(ctx)
  int ctx;
{
  uint uVar1;
  int callResult;
  uint uVar3;
  
  callResult = Inst__allWrittenLanesSatisfy(ctx,1,2);
  if (callResult != 0) {
    uVar3 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar1 & 1) == (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      ((int (*)())ValueKey__rewriteAsMovOfOperand)(ctx,1);
      ValueKey__rebuild(ctx);
      return 1;
    }
  }
  return 0;
}

/* ValueKey__foldMinOfConstants @ 0x17c910 (516 bytes) */
int ValueKey__foldMinOfConstants(ctx)
  int ctx;
{
  int laneResult;
  int prevLaneOrProgram;
  int findInPtrSetResult;
  bool laneFlag;
  bool usedUniformConstant;
  uint operandFlags;
  int operandRecord;
  undefined4 *exprRecord;
  int operandCountOrValueNumber;
  int operandRecAddr;
  int loopIndex;
  int laneEntryPtr;
  int operandRecOffset;
  int *valueNumberPtr;
  int *loopPtr2;
  int operandClasses [10];
  
  usedUniformConstant = false;
  loopIndex = 0;
  laneEntryPtr = ctx + 0x170;
  prevLaneOrProgram = -1;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    laneResult = prevLaneOrProgram;
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      valueNumberPtr = (int *)(laneEntryPtr + 8);
      loopPtr2 = operandClasses;
      operandRecOffset = 0x98;
      for (operandRecord = 1;
          operandCountOrValueNumber = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0)),
          operandRecord <= operandCountOrValueNumber; operandRecord = operandRecord + 1) {
        operandCountOrValueNumber = *valueNumberPtr;
        if (operandCountOrValueNumber < 0) {
          exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),operandCountOrValueNumber);
          operandCountOrValueNumber = signToCompareCode(*exprRecord);
          *loopPtr2 = operandCountOrValueNumber;
        }
        else {
          if (operandCountOrValueNumber < 1) {
            return 0;
          }
          findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),operandCountOrValueNumber);
          operandCountOrValueNumber = *(int *)(findInPtrSetResult + 0xc);
          *loopPtr2 = operandCountOrValueNumber;
          operandRecAddr = *(int *)(ctx + 0xb0) + operandRecOffset;
          operandFlags = *(uint *)(operandRecAddr + 0x20);
          if ((operandFlags & 2) != 0) {
            *loopPtr2 = (DAT_001e61d0)[operandCountOrValueNumber];
            operandFlags = *(uint *)(operandRecAddr + 0x20);
          }
          usedUniformConstant = true;
          if ((operandFlags & 1) != 0) {
            *loopPtr2 = *(int *)(&DAT_001e61b8 + *loopPtr2 * 4);
          }
        }
        operandRecOffset = operandRecOffset + 0x18;
        loopPtr2 = loopPtr2 + 1;
        valueNumberPtr = valueNumberPtr + 4;
      }
      if ((operandClasses[0] != 3) || (operandClasses[1] != 3)) {
        laneResult = *(int *)(&DAT_001e6014 + (operandClasses[0] * 6 + operandClasses[1]) * 4);
        if (laneResult == 1) {
          laneResult = 1;
        }
        else if (laneResult == 2) {
          laneResult = 2;
        }
        else {
          if (laneResult == 0) {
            return 0;
          }
          laneResult = 0;
        }
        if ((prevLaneOrProgram != -1) && (laneFlag = laneResult != prevLaneOrProgram, laneResult = prevLaneOrProgram, laneFlag)) {
          return 0;
        }
      }
    }
    laneFlag = loopIndex == 3;
    laneEntryPtr = laneEntryPtr + 4;
    loopIndex = loopIndex + 1;
    prevLaneOrProgram = laneResult;
    if (laneFlag) {
      if (laneResult == -1) {
        laneResult = 1;
      }
      if (usedUniformConstant) {
        prevLaneOrProgram = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
        *(int *)(prevLaneOrProgram + 0x134) = *(int *)(prevLaneOrProgram + 0x134) + 1;
      }
      ((int (*)())ValueKey__rewriteAsMovOfOperand)(ctx,laneResult);
      ValueKey__rebuild(ctx);
      return 1;
    }
  } while( true );
}

/* ValueKey__foldMaxOfConstants @ 0x17cb14 (516 bytes) */
int ValueKey__foldMaxOfConstants(ctx)
  int ctx;
{
  int laneResult;
  int prevLaneOrProgram;
  int findInPtrSetResult;
  bool laneFlag;
  bool usedUniformConstant;
  uint operandFlags;
  int operandRecord;
  undefined4 *exprRecord;
  int operandCountOrValueNumber;
  int operandRecAddr;
  int loopIndex;
  int laneEntryPtr;
  int operandRecOffset;
  int *valueNumberPtr;
  int *loopPtr2;
  int operandClasses [10];
  
  usedUniformConstant = false;
  loopIndex = 0;
  laneEntryPtr = ctx + 0x170;
  prevLaneOrProgram = -1;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    laneResult = prevLaneOrProgram;
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      valueNumberPtr = (int *)(laneEntryPtr + 8);
      loopPtr2 = operandClasses;
      operandRecOffset = 0x98;
      for (operandRecord = 1;
          operandCountOrValueNumber = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0)),
          operandRecord <= operandCountOrValueNumber; operandRecord = operandRecord + 1) {
        operandCountOrValueNumber = *valueNumberPtr;
        if (operandCountOrValueNumber < 0) {
          exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),operandCountOrValueNumber);
          operandCountOrValueNumber = signToCompareCode(*exprRecord);
          *loopPtr2 = operandCountOrValueNumber;
        }
        else {
          if (operandCountOrValueNumber < 1) {
            return 0;
          }
          findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),operandCountOrValueNumber);
          operandCountOrValueNumber = *(int *)(findInPtrSetResult + 0xc);
          *loopPtr2 = operandCountOrValueNumber;
          operandRecAddr = *(int *)(ctx + 0xb0) + operandRecOffset;
          operandFlags = *(uint *)(operandRecAddr + 0x20);
          if ((operandFlags & 2) != 0) {
            *loopPtr2 = (DAT_001e61d0)[operandCountOrValueNumber];
            operandFlags = *(uint *)(operandRecAddr + 0x20);
          }
          usedUniformConstant = true;
          if ((operandFlags & 1) != 0) {
            *loopPtr2 = *(int *)(&DAT_001e61b8 + *loopPtr2 * 4);
          }
        }
        operandRecOffset = operandRecOffset + 0x18;
        loopPtr2 = loopPtr2 + 1;
        valueNumberPtr = valueNumberPtr + 4;
      }
      if ((operandClasses[0] != 3) || (operandClasses[1] != 3)) {
        laneResult = *(int *)(&DAT_001e60a4 + (operandClasses[0] * 6 + operandClasses[1]) * 4);
        if (laneResult == 1) {
          laneResult = 1;
        }
        else if (laneResult == 2) {
          laneResult = 2;
        }
        else {
          if (laneResult == 0) {
            return 0;
          }
          laneResult = 0;
        }
        if ((prevLaneOrProgram != -1) && (laneFlag = laneResult != prevLaneOrProgram, laneResult = prevLaneOrProgram, laneFlag)) {
          return 0;
        }
      }
    }
    laneFlag = loopIndex == 3;
    laneEntryPtr = laneEntryPtr + 4;
    loopIndex = loopIndex + 1;
    prevLaneOrProgram = laneResult;
    if (laneFlag) {
      if (laneResult == -1) {
        laneResult = 1;
      }
      if (usedUniformConstant) {
        prevLaneOrProgram = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
        *(int *)(prevLaneOrProgram + 0x134) = *(int *)(prevLaneOrProgram + 0x134) + 1;
      }
      ((int (*)())ValueKey__rewriteAsMovOfOperand)(ctx,laneResult);
      ValueKey__rebuild(ctx);
      return 1;
    }
  } while( true );
}

/* ValueKey__foldMadZeroMultiplicand @ 0x17cd18 (164 bytes) */
int ValueKey__foldMadZeroMultiplicand(ctx)
  int ctx;
{
  bool notLastOperand;
  int callResult;
  undefined4 zeroValueNumber;
  int loopIndex;
  
  callResult = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0);
  loopIndex = 1;
  zeroValueNumber = *(undefined4 *)(callResult + 4);
  do {
    callResult = Inst__writtenLanesAllMatchValue(ctx,zeroValueNumber,loopIndex);
    if (callResult != 0) {
      callResult = ValueKey__sourcesEqualOnWrittenLanes(ctx,0,3);
      if (callResult == 0) {
        ((int (*)())ValueKey__rewriteAsMovOfOperand)(ctx,3);
      }
      else {
        FUN_00177548(ctx);
      }
      ValueKey__rebuild(ctx);
      return 1;
    }
    notLastOperand = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (notLastOperand);
  return 0;
}

/* ValueKey__foldAddOfZeroSource @ 0x17cdbc (192 bytes) */
int ValueKey__foldAddOfZeroSource(ctx)
  int ctx;
{
  int callResult;
  int loopIndex;
  undefined4 candidateOperand;
  undefined4 zeroValueNumber;
  
  loopIndex = 1;
  callResult = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0);
  zeroValueNumber = *(undefined4 *)(callResult + 4);
  do {
    candidateOperand = 2;
    do {
      callResult = Inst__writtenLanesAllMatchValue(ctx,zeroValueNumber,loopIndex);
      if (callResult != 0) {
        callResult = ValueKey__sourcesEqualOnWrittenLanes(ctx,0,candidateOperand);
        if (callResult == 0) {
          ((int (*)())ValueKey__rewriteAsMovOfOperand)(ctx,candidateOperand);
        }
        else {
          FUN_00177548(ctx);
        }
        ValueKey__rebuild(ctx);
        return 1;
      }
      loopIndex = loopIndex + 1;
      if (2 < loopIndex) {
        return 0;
      }
      candidateOperand = 1;
    } while (loopIndex != 1);
  } while( true );
}

/* ValueKey__rewriteAsMovOfReplacement @ 0x17ce7c (284 bytes) */
int ValueKey__rewriteAsMovOfReplacement(ctx, replacement)
  int ctx;
  int replacement;
{
  undefined4 replacementSwizzle;
  int operandRecord;
  bool hasNoExtraSource;
  uint oldFlags;
  int node;
  int *vector;
  undefined4 *elementRef;
  undefined4 savedExtraSourceRef;
  undefined4 operandRef2;
  undefined4 afterInst;
  undefined4 block;
  undefined4 saturate;
  undefined4 resultScaleCode;
  undefined4 src0Swizzle;
  undefined4 operandRef;
  undefined4 destRegister;
  undefined4 destRegisterOffset;
  int member0xb0;
  
  node = *(int *)(ctx + 0xb0);
  afterInst = *(undefined4 *)(node + 4);
  block = *(undefined4 *)(node + 0x158);
  DList__unlink(node);
  operandRef = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  operandRecord = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  member0xb0 = *(int *)(ctx + 0xb0);
  src0Swizzle = *(undefined4 *)(operandRecord + 0x10);
  oldFlags = *(uint *)(member0xb0 + 0x14);
  saturate = *(undefined4 *)(member0xb0 + 0x120);
  resultScaleCode = *(undefined4 *)(member0xb0 + 0x124);
  hasNoExtraSource = (oldFlags >> 9 & 1) == 0;
  if (hasNoExtraSource) {
    savedExtraSourceRef = 0;
    operandRef2 = 0;
  }
  else {
    savedExtraSourceRef = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 4 + ctx + 0x210);
    operandRef2 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 0x18 + member0xb0 + 0x8c);
  }
  destRegister = *(undefined4 *)(member0xb0 + 0x94);
  destRegisterOffset = *(undefined4 *)(member0xb0 + 0x98);
  IRInst__reinitAsMov(member0xb0,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(member0xb0,0,operandRef);
  *(undefined4 *)(member0xb0 + 0x98) = destRegisterOffset;
  *(undefined4 *)(member0xb0 + 0x94) = destRegister;
  *(undefined4 *)(member0xb0 + 0x9c) = src0Swizzle;
  *(undefined4 *)(member0xb0 + 0x120) = saturate;
  *(undefined4 *)(member0xb0 + 0x124) = resultScaleCode;
  IRInst__setOperandRef(member0xb0,1,*(undefined4 *)(replacement + 0xc));
  replacementSwizzle = *(undefined4 *)(PTR_DAT_001e8b8c + *(int *)(replacement + 0x10) * 4);
  operandRecord = IRInst__getOperandRecord(member0xb0,1);
  *(undefined4 *)(operandRecord + 0x10) = replacementSwizzle;
  if (*(int *)(replacement + 0x18) != 0) {
    IROperand__setModifierBits(member0xb0 + 0xa4,1,1);
  }
  *(undefined4 *)(member0xb0 + 0x120) = saturate;
  *(undefined4 *)(member0xb0 + 0x124) = resultScaleCode;
  vector = *(int **)(*(int *)(member0xb0 + 0xa4) + 0x18);
  if (*vector == 0) {
    elementRef = (undefined4 *)Vector__elementRefGrow(vector,0);
  }
  else {
    if (vector[1] == 0) {
      *(undefined4 *)vector[2] = 0;
      vector[1] = 1;
    }
    elementRef = (undefined4 *)vector[2];
  }
  *(undefined4 *)(ctx + 0x214) = *elementRef;
  if (hasNoExtraSource) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(member0xb0,operandRef2);
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = savedExtraSourceRef;
  }
  if ((oldFlags & 0x200000) != 0) {
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200000;
  }
  Block__insertInstAfter(block,afterInst,member0xb0);
  return member0xb0;
}

/* ValueKey__rewriteAsMovOfValueKey @ 0x17d06c (368 bytes) */
int ValueKey__rewriteAsMovOfValueKey(ctx, valueKey, src1SwizzlePtr, negateFlag)
  int ctx;
  int valueKey;
  undefined4 *src1SwizzlePtr;
  undefined4 negateFlag;
{
  undefined4 src1Swizzle;
  int operandRef;
  int operandRecord;
  undefined4 arenaAt378;
  bool hasNoExtraSource;
  uint oldFlags;
  int node;
  undefined4 *newValueKey;
  undefined4 savedExtraSourceRef;
  undefined4 operandRef3;
  undefined4 afterInst;
  undefined4 block;
  undefined4 src0Swizzle;
  undefined4 destRegisterOffset;
  undefined4 operandRef2;
  undefined4 destRegister;
  int member0xb0;
  
  node = *(int *)(ctx + 0xb0);
  afterInst = *(undefined4 *)(node + 4);
  block = *(undefined4 *)(node + 0x158);
  DList__unlink(node);
  operandRef2 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  operandRecord = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  member0xb0 = *(int *)(ctx + 0xb0);
  src0Swizzle = *(undefined4 *)(operandRecord + 0x10);
  oldFlags = *(uint *)(member0xb0 + 0x14);
  hasNoExtraSource = (oldFlags >> 9 & 1) == 0;
  if (hasNoExtraSource) {
    savedExtraSourceRef = 0;
    operandRef3 = 0;
  }
  else {
    savedExtraSourceRef = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 4 + ctx + 0x210);
    operandRef3 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 0x18 + member0xb0 + 0x8c);
  }
  destRegister = *(undefined4 *)(member0xb0 + 0x94);
  destRegisterOffset = *(undefined4 *)(member0xb0 + 0x98);
  IRInst__reinitAsMov(member0xb0,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(member0xb0,0,operandRef2);
  operandRef = *(int *)(valueKey + 0x8c);
  *(undefined4 *)(member0xb0 + 0x94) = destRegister;
  *(undefined4 *)(member0xb0 + 0x98) = destRegisterOffset;
  *(undefined4 *)(member0xb0 + 0x9c) = src0Swizzle;
  if (*(int *)(*(int *)(operandRef + 0x2c) + 4) == 0) {
    arenaAt378 = *(undefined4 *)(*(int *)(ctx + 0x238) + 0x378);
    newValueKey = (undefined4 *)Arena__alloc(arenaAt378,0x240);
    *newValueKey = arenaAt378;
    newValueKey = newValueKey + 1;
    ValueKey__init(newValueKey,valueKey,*(undefined4 *)(ctx + 0x238));
    FUN_00174e0c(newValueKey);
    ValueKey__propagateLaneValues(newValueKey);
    VReg__pushDefinition(operandRef,*(undefined4 *)(*(int *)(valueKey + 0x158) + 0xb0),newValueKey);
  }
  IRInst__setOperandRef(member0xb0,1,operandRef);
  src1Swizzle = *src1SwizzlePtr;
  operandRecord = IRInst__getOperandRecord(member0xb0,1);
  *(undefined4 *)(operandRecord + 0x10) = src1Swizzle;
  IROperand__setModifierBits(member0xb0 + 0xa4,1,negateFlag);
  *(int *)(ctx + 0x214) = valueKey;
  if (hasNoExtraSource) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(member0xb0,operandRef3);
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = savedExtraSourceRef;
  }
  if ((oldFlags & 0x200000) != 0) {
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200000;
  }
  Block__insertInstAfter(block,afterInst,member0xb0);
  return member0xb0;
}

/* ValueKey__rewriteAsMovOfVec4Constant @ 0x17d26c (196 bytes) */
int ValueKey__rewriteAsMovOfVec4Constant(ctx, vec4Constant)
  int ctx;
  undefined4 vec4Constant;
{
  bool notLastLane;
  undefined4 operandValueNumber;
  int node;
  int operandRecord2;
  bool hasNoExtraSource;
  uint oldFlags;
  int laneWordPtr;
  int operandRecord;
  undefined4 savedExtraSourceRef;
  undefined4 afterInst;
  undefined4 block;
  undefined4 operandRef2;
  undefined4 src0Swizzle;
  undefined4 operandRef;
  int member0xb0;
  undefined4 destRegister;
  int loopIndex;
  undefined4 destRegisterOffset;
  
  node = *(int *)(ctx + 0xb0);
  afterInst = *(undefined4 *)(node + 4);
  block = *(undefined4 *)(node + 0x158);
  DList__unlink(node);
  operandRef = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  operandRecord2 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  member0xb0 = *(int *)(ctx + 0xb0);
  src0Swizzle = *(undefined4 *)(operandRecord2 + 0x10);
  oldFlags = *(uint *)(member0xb0 + 0x14);
  hasNoExtraSource = (oldFlags >> 9 & 1) == 0;
  if (hasNoExtraSource) {
    savedExtraSourceRef = 0;
    operandRef2 = 0;
  }
  else {
    savedExtraSourceRef = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 4 + ctx + 0x210);
    operandRef2 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 0x18 + member0xb0 + 0x8c);
  }
  destRegister = *(undefined4 *)(member0xb0 + 0x94);
  destRegisterOffset = *(undefined4 *)(member0xb0 + 0x98);
  IRInst__reinitAsMov(member0xb0,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(member0xb0,0,operandRef);
  *(undefined4 *)(member0xb0 + 0x94) = destRegister;
  *(undefined4 *)(member0xb0 + 0x98) = destRegisterOffset;
  if (hasNoExtraSource) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(member0xb0,operandRef2);
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = savedExtraSourceRef;
  }
  *(undefined4 *)(member0xb0 + 0x9c) = src0Swizzle;
  loopIndex = 0;
  operandValueNumber = ValueKey__setLiteralVec4Operand(1,vec4Constant,member0xb0,*(undefined4 *)(ctx + 0x238));
  *(undefined4 *)(ctx + 0x214) = operandValueNumber;
  laneWordPtr = ctx;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + operandRecord + 0x10) == '\x01') {
      *(undefined4 *)(laneWordPtr + 0x30) = 0;
    }
    notLastLane = loopIndex != 3;
    laneWordPtr = laneWordPtr + 4;
    loopIndex = loopIndex + 1;
  } while (notLastLane);
  if ((oldFlags & 0x200000) != 0) {
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200000;
  }
  Block__insertInstAfter(block,afterInst,member0xb0);
  return member0xb0;
}

/* ValueKey__foldCompareSameSourcesToConstant @ 0x17d3f8 (232 bytes) */
int ValueKey__foldCompareSameSourcesToConstant(param_1)
  int param_1;
{
  undefined4 *loopPtr;
  int loopRemaining;
  undefined4 uVar3;
  int loopRemaining2;
  undefined4 local_28 [8];
  
  loopRemaining = Inst__allWrittenLanesSatisfy(param_1,1,2);
  if (loopRemaining != 0) {
    loopRemaining = *(int *)(param_1 + 0xb0);
    if (((*(uint *)(loopRemaining + 0xb8) & 1) == (*(uint *)(loopRemaining + 0xd0) & 1)) &&
       ((*(uint *)(loopRemaining + 0xb8) >> 1 & 1) == (*(uint *)(loopRemaining + 0xd0) >> 1 & 1))) {
      loopRemaining = ((bool (*)())evaluateCompareFloats)(loopRemaining,(double)FLOAT_001aa0d4,(double)FLOAT_001aa0d4);
      uVar3 = 0x3f800000;
      if (loopRemaining == 0) {
        uVar3 = 0;
      }
      loopRemaining = 4;
      loopPtr = local_28;
      do {
        *loopPtr = 0x7ffffffe;
        loopPtr = loopPtr + 1;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
      loopRemaining = 0;
      loopRemaining2 = 4;
      do {
        *(undefined4 *)(loopRemaining + (int)local_28) = uVar3;
        loopRemaining = loopRemaining + 4;
        loopRemaining2 = loopRemaining2 + -1;
      } while (loopRemaining2 != 0);
      ((int (*)())ValueKey__rewriteAsMovOfVec4Constant)(param_1,local_28);
      ValueKey__rebuild(param_1);
      return 1;
    }
  }
  return 0;
}

/* ValueKey__replaceWithZeroIfSourcesEqual @ 0x17d4e0 (156 bytes) */
int ValueKey__replaceWithZeroIfSourcesEqual(ctx)
  int ctx;
{
  uint uVar1;
  int callResult;
  uint uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  callResult = FUN_00176fd4(ctx,1,2);
  if (callResult != 0) {
    uVar3 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar1 & 1) == (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      local_1c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      ((int (*)())ValueKey__rewriteAsMovOfVec4Constant)(ctx,&local_28);
      ValueKey__rebuild(ctx);
      return 1;
    }
  }
  return 0;
}

/* ValueKey__foldMulByZero @ 0x17d57c (148 bytes) */
int ValueKey__foldMulByZero(ctx)
  int ctx;
{
  bool notLastOperand;
  int callResult;
  undefined4 zeroValueNumber;
  int loopIndex;
  undefined4 zeroVec4X;
  undefined4 zeroVec4Y;
  undefined4 zeroVec4Z;
  undefined4 zeroVec4W;
  
  callResult = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0);
  loopIndex = 1;
  zeroValueNumber = *(undefined4 *)(callResult + 4);
  do {
    callResult = Inst__writtenLanesAllMatchValue(ctx,zeroValueNumber,loopIndex);
    if (callResult != 0) {
      zeroVec4W = 0;
      zeroVec4X = 0;
      zeroVec4Y = 0;
      zeroVec4Z = 0;
      ((int (*)())ValueKey__rewriteAsMovOfVec4Constant)(ctx,&zeroVec4X);
      ValueKey__rebuild(ctx);
      return 1;
    }
    notLastOperand = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (notLastOperand);
  return 0;
}

/* ValueKey__foldOppositeNegatesToZero @ 0x17d610 (156 bytes) */
int ValueKey__foldOppositeNegatesToZero(ctx)
  int ctx;
{
  uint word0xb8Flags;
  int callResult;
  uint word0xd0Flags;
  undefined4 zeroVec4X;
  undefined4 zeroVec4Y;
  undefined4 zeroVec4Z;
  undefined4 zeroVec4W;
  
  callResult = Inst__allWrittenLanesSatisfy(ctx,1,2);
  if (callResult != 0) {
    word0xd0Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    word0xb8Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((word0xb8Flags & 1) != (word0xd0Flags & 1)) && ((word0xb8Flags >> 1 & 1) == (word0xd0Flags >> 1 & 1))) {
      zeroVec4W = 0;
      zeroVec4X = 0;
      zeroVec4Y = 0;
      zeroVec4Z = 0;
      ((int (*)())ValueKey__rewriteAsMovOfVec4Constant)(ctx,&zeroVec4X);
      ValueKey__rebuild(ctx);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017d6ac @ 0x17d6ac (780 bytes) */
int FUN_0017d6ac(ctx, laneConstants)
  int ctx;
  float *laneConstants;
{
  bool moreLanes;
  byte valueFlags;
  float *loopPtr2;
  int byteOffset;
  int loopIndex;
  int loopRemaining2;
  int *hwLimits;
  undefined4 limitsFailed;
  undefined4 staleArg5;
  undefined4 staleArg6;
  float *loopPtr3;
  float commonValue;
  int loopRemaining;
  undefined4 destSelectMask;
  uint negatedConstants;
  float negatedConstantsTail [3];
  undefined4 writeMaskOut;
  undefined4 maskedSelect [4];
  
  loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
  WriteMask__fromSelectWord(&writeMaskOut,*(undefined4 *)(loopIndex + 0x10));
  SelectWord__maskUnused(maskedSelect,0x10203,writeMaskOut);
  loopIndex = *(int *)(ctx + 0x238);
  destSelectMask = maskedSelect[0];
  loopIndex = (**(code **)(**(int **)(loopIndex + 0x30c) + 0x154))
                    (*(int **)(loopIndex + 0x30c),*(undefined4 *)(loopIndex + 0x6c4),laneConstants,&destSelectMask,staleArg5
                     ,staleArg6,loopIndex);
  if (loopIndex == 0) {
    loopIndex = 4;
    loopPtr2 = (float *)&negatedConstants;
    do {
      *loopPtr2 = GH_U2F(0x7fff0000U);
      loopPtr2 = loopPtr2 + 1;
      loopIndex = loopIndex + -1;
    } while (loopIndex != 0);
    loopIndex = 0;
    loopPtr2 = (float *)&negatedConstants;
    loopPtr3 = laneConstants;
    do {
      loopRemaining2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if (*(char *)(loopIndex + loopRemaining2 + 0x10) != '\x01') {
        *loopPtr2 = -*loopPtr3;
      }
      moreLanes = loopIndex != 3;
      loopPtr2 = loopPtr2 + 1;
      loopPtr3 = loopPtr3 + 1;
      loopIndex = loopIndex + 1;
    } while (moreLanes);
    hwLimits = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
    loopIndex = (**(code **)(*hwLimits + 0x154))
                      (hwLimits,*(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4),&negatedConstants,&destSelectMask
                      );
    if (loopIndex == 0) {
      commonValue = GH_U2F(0x7fff0000U);
      loopIndex = 0;
      loopPtr2 = laneConstants;
      do {
        loopRemaining2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex + loopRemaining2 + 0x10) != '\x01') {
          Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238), *(unsigned int *)loopPtr2);
          if ((GH_F2U(commonValue) == 0x7fff0000U)) {
            commonValue = *loopPtr2;
          }
          else if (commonValue != *loopPtr2) {
            return 0;
          }
        }
        moreLanes = loopIndex != 3;
        loopPtr2 = loopPtr2 + 1;
        loopIndex = loopIndex + 1;
      } while (moreLanes);
      loopIndex = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238), GH_F2U(commonValue));
      if (*(byte *)(loopIndex + 8) == 0) {
        return 0;
      }
      valueFlags = *(byte *)(loopIndex + 9);
      if (((((valueFlags & 1) == 0) && ((valueFlags & 2) == 0)) && ((valueFlags & 4) == 0)) && ((valueFlags & 8) == 0))
      {
        if ((*(byte *)(loopIndex + 8) & 1) == 0) {
          loopIndex = ((int (*)())ValueKey__rewriteAsMovOfReplacement)(ctx,loopIndex);
          return loopIndex;
        }
        loopIndex = 0;
        loopRemaining2 = 4;
        do {
          *(float *)((int)laneConstants + loopIndex) = commonValue;
          loopIndex = loopIndex + 4;
          loopRemaining2 = loopRemaining2 + -1;
        } while (loopRemaining2 != 0);
        loopIndex = ((int (*)())ValueKey__rewriteAsMovOfVec4Constant)(ctx,laneConstants);
        return loopIndex;
      }
      loopRemaining2 = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(loopIndex + 0x14));
      loopPtr2 = (float *)&negatedConstants;
      if ((*(byte *)(loopRemaining2 + 8) & 1) == 0) {
        loopRemaining2 = ((int (*)())ValueKey__rewriteAsMovOfReplacement)(ctx,loopRemaining2);
      }
      else {
        do {
          *loopPtr2 = GH_U2F(0x7fff0000U);
          loopPtr2 = loopPtr2 + 1;
        } while (loopPtr2 != negatedConstantsTail);
        byteOffset = 0;
        loopRemaining = 4;
        do {
          *(undefined4 *)(byteOffset + (int)&negatedConstants) = *(undefined4 *)(loopRemaining2 + 0x14);
          byteOffset = byteOffset + 4;
          loopRemaining = loopRemaining + -1;
        } while (loopRemaining != 0);
        loopRemaining2 = ((int (*)())ValueKey__rewriteAsMovOfVec4Constant)(ctx,&negatedConstants);
      }
      valueFlags = *(byte *)(loopIndex + 9);
      if ((valueFlags & 1) != 0) {
        IROperand__setModifierBits(loopRemaining2 + 0xa4,1,1);
        valueFlags = *(byte *)(loopIndex + 9);
      }
      if ((valueFlags & 2) != 0) {
        *(undefined4 *)(loopRemaining2 + 0x124) = *(undefined4 *)(loopIndex + 0x1c);
        return loopRemaining2;
      }
      return loopRemaining2;
    }
    limitsFailed = 1;
  }
  else {
    limitsFailed = 0;
  }
  loopIndex = ((int (*)())ValueKey__rewriteAsMovOfValueKey)(ctx,loopIndex,&destSelectMask,limitsFailed);
  return loopIndex;
}

/* ValueKey__foldCompareOfConstants @ 0x17d9b8 (548 bytes) */
int ValueKey__foldCompareOfConstants(ctx)
  int ctx;
{
  int operandRecAddr;
  int operandClass;
  int firstOperandClass;
  int findInPtrSetResult;
  bool moreIterations;
  bool usedUniformConstant;
  uint operandFlags;
  int *loopPtr4;
  int loopIndex2;
  undefined4 *exprRecord;
  int compareClass;
  undefined4 result;
  int valueNumber;
  int *laneResults;
  int operandRecOffset;
  int *loopPtr3;
  int *valueNumberPtr;
  int loopIndex;
  int loopRemaining;
  int operandClasses [9];
  
  loopIndex = 4;
  laneResults = operandClasses + 2;
  loopPtr4 = laneResults;
  do {
    *loopPtr4 = 0x7ffffffe;
    loopPtr4 = loopPtr4 + 1;
    loopIndex = loopIndex + -1;
  } while (loopIndex != 0);
  loopIndex = 0;
  loopRemaining = 4;
  do {
    *(undefined4 *)(loopIndex + (int)laneResults) = 0x7ffffffe;
    loopIndex = loopIndex + 4;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  usedUniformConstant = false;
  loopIndex = 0;
  loopRemaining = ctx + 0x170;
  loopPtr4 = laneResults;
  do {
    loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + loopIndex2 + 0x10) != '\x01') {
      valueNumberPtr = (int *)(loopRemaining + 8);
      loopIndex2 = 1;
      loopPtr3 = operandClasses;
      operandRecOffset = 0x98;
      do {
        *loopPtr3 = 0;
        valueNumber = *valueNumberPtr;
        if (valueNumber < 0) {
          exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),valueNumber);
          operandClass = signToCompareCode(*exprRecord);
          *loopPtr3 = operandClass;
        }
        else {
          if (valueNumber < 1) goto LAB_0017dbc4;
          findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),valueNumber);
          compareClass = *(int *)(findInPtrSetResult + 0xc);
          *loopPtr3 = compareClass;
          operandRecAddr = *(int *)(ctx + 0xb0) + operandRecOffset;
          operandFlags = *(uint *)(operandRecAddr + 0x20);
          if ((operandFlags & 2) != 0) {
            *loopPtr3 = (DAT_001e61d0)[compareClass];
            operandFlags = *(uint *)(operandRecAddr + 0x20);
          }
          if ((operandFlags & 1) == 0) {
            operandClass = *loopPtr3;
            usedUniformConstant = true;
          }
          else {
            usedUniformConstant = true;
            operandClass = *(int *)(&DAT_001e61b8 + *loopPtr3 * 4);
            *loopPtr3 = operandClass;
          }
        }
        firstOperandClass = operandClasses[0];
        if (operandClass == 0) goto LAB_0017dbc4;
        moreIterations = loopIndex2 != 2;
        operandRecOffset = operandRecOffset + 0x18;
        loopPtr3 = loopPtr3 + 1;
        valueNumberPtr = valueNumberPtr + 4;
        loopIndex2 = loopIndex2 + 1;
      } while (moreIterations);
      loopIndex2 = IRInst__getCompareCondition(*(undefined4 *)(ctx + 0xb0));
      loopIndex2 = *(int *)(&DAT_001e61e8 + (loopIndex2 * 6 + firstOperandClass * 0x30 + operandClasses[1]) * 4);
      if (loopIndex2 == 1) {
        *loopPtr4 = 0x3f800000;
      }
      else if (loopIndex2 == 2) {
        *loopPtr4 = 0;
      }
      else if (loopIndex2 == 0) goto LAB_0017dbc4;
    }
    moreIterations = loopIndex != 3;
    loopRemaining = loopRemaining + 4;
    loopPtr4 = loopPtr4 + 1;
    loopIndex = loopIndex + 1;
  } while (moreIterations);
  loopIndex = ((int (*)())FUN_0017d6ac)(ctx,laneResults);
  if (loopIndex == 0) {
LAB_0017dbc4:
    result = 0;
  }
  else {
    if (usedUniformConstant) {
      loopIndex = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
      *(int *)(loopIndex + 0x134) = *(int *)(loopIndex + 0x134) + 1;
    }
    ValueKey__rebuild(ctx);
    result = 1;
  }
  return result;
}

/* FUN_0017dbdc @ 0x17dbdc (1104 bytes) */
int FUN_0017dbdc(ctx, laneResultsOut)
  int ctx;
  int *laneResultsOut;
{
  int partialFlag;
  int isOpcodeKindB;
  bool cannotFold;
  undefined4 exprRecord;
  bool moreLanes;
  int isOpcodeKindA;
  int loopRemaining;
  int loopIndex;
  int *loopPtr3;
  undefined4 opcode;
  int loopIndex2;
  int foldFlags [4];
  int laneResultOutD;
  int laneResultOutC;
  int laneResultOutB;
  int laneResultOutA [6];
  
  opcode = *(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8);
  isOpcodeKindA = FUN_00176564(opcode);
  if (isOpcodeKindA != 0) {
    return 0;
  }
  isOpcodeKindB = FUN_00176574(opcode);
  if (isOpcodeKindB == 0) {
    loopIndex = OpcodeTraits__flagBit7(opcode,*(undefined4 *)(ctx + 0x238));
    if ((loopIndex == 0) ||
       (loopIndex = OpcodeTraits__flagBit8(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                             *(undefined4 *)(ctx + 0x238)), loopIndex == 0)) {
      loopIndex = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(ctx + 0x238));
      if (loopIndex == 0) {
        partialFlag = 0;
        loopIndex2 = 0;
        loopIndex = ctx;
        loopPtr3 = laneResultsOut;
        do {
          foldFlags[0] = 0;
          loopRemaining = FUN_001767d8(ctx,loopIndex2);
          if (loopRemaining != 0) {
            FUN_00176c40(laneResultOutA,ctx,loopIndex2,foldFlags);
            *loopPtr3 = laneResultOutA[0];
            if (laneResultOutA[0] != 0x7ffffffe) {
              exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),laneResultOutA[0]);
              *(undefined4 *)(loopIndex + 0x30) = exprRecord;
            }
          }
          loopRemaining = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
          if ((*(char *)(loopIndex2 + loopRemaining + 0x10) == '\0') && (foldFlags[0] != 0)) {
            partialFlag = 1;
          }
          moreLanes = loopIndex2 != 3;
          loopPtr3 = loopPtr3 + 1;
          loopIndex = loopIndex + 4;
          loopIndex2 = loopIndex2 + 1;
        } while (moreLanes);
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(int *)(loopIndex + 0x10) == 0x1010101) goto LAB_0017dfa0;
        loopIndex = 0;
        loopPtr3 = laneResultsOut;
        do {
          loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
          if ((*(char *)(loopIndex + loopIndex2 + 0x10) != '\x01') && (*loopPtr3 == 0x7ffffffe))
          goto LAB_0017dfa0;
          moreLanes = loopIndex != 3;
          loopPtr3 = loopPtr3 + 1;
          loopIndex = loopIndex + 1;
        } while (moreLanes);
      }
      else {
        loopIndex = FUN_0017672c(ctx);
        if (loopIndex == 0) goto LAB_0017df9c;
        foldFlags[0] = isOpcodeKindB;
        FUN_001781a4(&laneResultOutB,ctx,foldFlags);
        partialFlag = foldFlags[0];
        if (laneResultOutB == 0x7ffffffe) goto LAB_0017dfa0;
        exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),laneResultOutB);
        loopRemaining = 4;
        loopIndex2 = 0;
        loopIndex = ctx;
        do {
          *(int *)((int)laneResultsOut + loopIndex2) = laneResultOutB;
          loopIndex2 = loopIndex2 + 4;
          *(undefined4 *)(loopIndex + 0x30) = exprRecord;
          loopIndex = loopIndex + 4;
          loopRemaining = loopRemaining + -1;
        } while (loopRemaining != 0);
      }
    }
    else {
      loopIndex = FUN_00178b1c(ctx);
      if (loopIndex == 0) {
LAB_0017df9c:
        partialFlag = 0;
LAB_0017dfa0:
        cannotFold = true;
        goto LAB_0017dd38;
      }
      foldFlags[0] = isOpcodeKindB;
      FUN_00176a94(&laneResultOutC,ctx,foldFlags);
      partialFlag = foldFlags[0];
      if (laneResultOutC == 0x7ffffffe) goto LAB_0017dfa0;
      exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),laneResultOutC);
      loopRemaining = 4;
      loopIndex2 = 0;
      loopIndex = ctx;
      do {
        *(int *)((int)laneResultsOut + loopIndex2) = laneResultOutC;
        loopIndex2 = loopIndex2 + 4;
        *(undefined4 *)(loopIndex + 0x30) = exprRecord;
        loopIndex = loopIndex + 4;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
    }
  }
  else {
    partialFlag = 0;
    loopIndex2 = 0;
    loopIndex = ctx;
    loopPtr3 = laneResultsOut;
    do {
      foldFlags[0] = 0;
      loopRemaining = FUN_00178a98(ctx,loopIndex2);
      if (loopRemaining != 0) {
        ValueKey__evalLitLane(&laneResultOutD,ctx,loopIndex2,(uint)foldFlags);
        *loopPtr3 = laneResultOutD;
        if (laneResultOutD != 0x7ffffffe) {
          exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),laneResultOutD);
          *(undefined4 *)(loopIndex + 0x30) = exprRecord;
        }
      }
      loopRemaining = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if ((*(char *)(loopIndex2 + loopRemaining + 0x10) == '\0') && (foldFlags[0] != 0)) {
        partialFlag = 1;
      }
      moreLanes = loopIndex2 != 3;
      loopPtr3 = loopPtr3 + 1;
      loopIndex = loopIndex + 4;
      loopIndex2 = loopIndex2 + 1;
    } while (moreLanes);
    loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(int *)(loopIndex + 0x10) == 0x1010101) goto LAB_0017dfa0;
    loopIndex = 0;
    loopPtr3 = laneResultsOut;
    do {
      loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if ((*(char *)(loopIndex + loopIndex2 + 0x10) != '\x01') && (*loopPtr3 == 0x7ffffffe)) goto LAB_0017dfa0;
      moreLanes = loopIndex != 3;
      loopPtr3 = loopPtr3 + 1;
      loopIndex = loopIndex + 1;
    } while (moreLanes);
  }
  cannotFold = false;
LAB_0017dd38:
  loopIndex = (**(code **)(**(int **)(ctx + 0xb0) + 100))(*(int **)(ctx + 0xb0));
  if ((loopIndex == 0) && (!cannotFold)) {
    loopIndex = ((int (*)())FUN_0017d6ac)(ctx,laneResultsOut);
    if (loopIndex != 0) {
      ValueKey__rebuild(ctx);
      return 1;
    }
    loopIndex = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
    *(int *)(loopIndex + 0x138) = *(int *)(loopIndex + 0x138) + 1;
    if ((*(int *)(*(int *)(ctx + 0xb0) + 0x120) != 0) && (partialFlag == 0)) {
      *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x120) = 0;
      ValueKey__rebuild(ctx);
      return 0;
    }
  }
  return 0;
}

/* ValueKey__rewriteAsMovOfOperandWithScale @ 0x17e02c (268 bytes) */
int ValueKey__rewriteAsMovOfOperandWithScale(ctx, operandIndex, resultScaleCode)
  int ctx;
  int operandIndex;
  undefined4 resultScaleCode;
{
  int inst;
  int operandRecord2;
  int operandRecord;
  bool noExtraSource;
  undefined4 ref;
  uint operandFlags;
  int node;
  int keyInst;
  uint instFlags;
  undefined4 blockRef;
  undefined4 extraValueNumber;
  undefined4 saturate;
  undefined4 operandRef;
  undefined4 operandValueNumber;
  undefined4 destSelectWord;
  undefined4 operandRef2;
  undefined4 operandSelectWord;
  undefined4 operandRef3;
  undefined4 savedDestRegister;
  undefined4 savedDestRegisterOffset;
  
  node = *(int *)(ctx + 0xb0);
  ref = *(undefined4 *)(node + 4);
  blockRef = *(undefined4 *)(node + 0x158);
  DList__unlink(node);
  operandRef3 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  operandRecord2 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  inst = *(int *)(ctx + 0xb0);
  destSelectWord = *(undefined4 *)(operandRecord2 + 0x10);
  operandRef2 = *(undefined4 *)(operandIndex * 0x18 + inst + 0x8c);
  saturate = *(undefined4 *)(inst + 0x120);
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  keyInst = *(int *)(ctx + 0xb0);
  operandSelectWord = *(undefined4 *)(operandRecord + 0x10);
  instFlags = *(uint *)(keyInst + 0x14);
  operandFlags = *(uint *)(operandIndex * 0x18 + keyInst + 0xa0);
  operandValueNumber = *(undefined4 *)(operandIndex * 4 + ctx + 0x210);
  noExtraSource = (instFlags >> 9 & 1) == 0;
  if (noExtraSource) {
    extraValueNumber = 0;
    operandRef = 0;
  }
  else {
    extraValueNumber = *(undefined4 *)(*(int *)(keyInst + 0x84) * 4 + ctx + 0x210);
    operandRef = *(undefined4 *)(*(int *)(keyInst + 0x84) * 0x18 + keyInst + 0x8c);
  }
  savedDestRegister = *(undefined4 *)(keyInst + 0x94);
  savedDestRegisterOffset = *(undefined4 *)(keyInst + 0x98);
  IRInst__reinitAsMov(keyInst,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(keyInst,0,operandRef3);
  *(undefined4 *)(keyInst + 0x94) = savedDestRegister;
  *(undefined4 *)(keyInst + 0x98) = savedDestRegisterOffset;
  if (noExtraSource) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(keyInst,operandRef);
    *(uint *)(keyInst + 0x14) = *(uint *)(keyInst + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = extraValueNumber;
  }
  *(undefined4 *)(keyInst + 0x9c) = destSelectWord;
  IRInst__setOperandRef(keyInst,1,operandRef2);
  operandRecord = IRInst__getOperandRecord(keyInst,1);
  *(undefined4 *)(operandRecord + 0x10) = operandSelectWord;
  IROperand__setModifierBits(keyInst + 0xa4,1,operandFlags & 1);
  IROperand__setModifierBits(keyInst + 0xa4,2,operandFlags >> 1 & 1);
  *(undefined4 *)(keyInst + 0x120) = saturate;
  *(undefined4 *)(keyInst + 0x124) = resultScaleCode;
  *(undefined4 *)(ctx + 0x214) = operandValueNumber;
  if ((instFlags & 0x200000) != 0) {
    *(uint *)(keyInst + 0x14) = *(uint *)(keyInst + 0x14) | 0x200000;
  }
  DList__insertAfter(keyInst,ref);
  *(undefined4 *)(keyInst + 0x158) = blockRef;
  return;
}

/* ValueKey__foldMulPowerOfTwoIntoOutputScale @ 0x17e1f4 (324 bytes) */
int ValueKey__foldMulPowerOfTwoIntoOutputScale(ctx)
  int ctx;
{
  int operandBase;
  int scaleExponent;
  bool notLastOperand;
  bool isPositive;
  int isOutputScale;
  int scaleAccepted;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int *a0;
  int loopIndex;
  double magnitude;
  float operandValue [7];
  
  loopIndex = 1;
  do {
    ValueKey__commonLaneValue(operandValue,ctx,loopIndex);
    if ((GH_F2U(operandValue[0]) != 0x7fff0000U)) {
      isPositive = -1 < (int)GH_F2U(operandValue[0]);
      if (isPositive) {
        magnitude = (double)operandValue[0];
      }
      else {
        magnitude = -(double)operandValue[0];
      }
      isOutputScale = ((undefined4 (*)())isOutputScaleValue)(magnitude);
      if (isOutputScale != 0) {
        scaleExponent = ((int (*)())outputScaleExponent)(magnitude);
        a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
        scaleExponent = scaleExponent + *(int *)(*(int *)(ctx + 0xb0) + 0x124);
        scaleAccepted = (**(code **)(*a0 + 0xfc))(a0,scaleExponent,*(int *)(ctx + 0xb0),in_r6,in_r7,in_r8,a0);
        if (scaleAccepted != 0) {
          loopIndex = (loopIndex == 1) + 1;
          if (!isPositive) {
            operandBase = *(int *)(ctx + 0xb0) + loopIndex * 0x18 + 0x80;
            IROperand__setModifierBits(operandBase + 0xc,1,(*(uint *)(operandBase + 0x20) ^ 1) & 1);
          }
          ((int (*)())ValueKey__rewriteAsMovOfOperandWithScale)(ctx,loopIndex,scaleExponent);
          ValueKey__rebuild(ctx);
          return 1;
        }
      }
    }
    notLastOperand = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (notLastOperand);
  return 0;
}

/* ValueKey__foldEqualSourcesIntoOutputScale @ 0x17e338 (188 bytes) */
int ValueKey__foldEqualSourcesIntoOutputScale(ctx)
  int ctx;
{
  int limitAccepted;
  int lanesAllSatisfy;
  int inst;
  int *a0;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int a1;
  
  lanesAllSatisfy = Inst__allWrittenLanesSatisfy(ctx,1,2);
  if (lanesAllSatisfy != 0) {
    inst = *(int *)(ctx + 0xb0);
    if (((*(uint *)(inst + 0xb8) & 1) == (*(uint *)(inst + 0xd0) & 1)) &&
       ((*(uint *)(inst + 0xb8) >> 1 & 1) == (*(uint *)(inst + 0xd0) >> 1 & 1))) {
      a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
      a1 = *(int *)(inst + 0x124) + 1;
      limitAccepted = (**(code **)(*a0 + 0xfc))(a0,a1,inst,in_r6,in_r7,in_r8,*(int *)(inst + 0x124));
      if (limitAccepted != 0) {
        ((int (*)())ValueKey__rewriteAsMovOfOperandWithScale)(ctx,2,a1);
        ValueKey__rebuild(ctx);
        return 1;
      }
    }
  }
  return 0;
}

/* ValueKey__rewriteAsBinaryOfOperands @ 0x17e3f4 (348 bytes) */
int ValueKey__rewriteAsBinaryOfOperands(ctx, newOpcode, operandIndex, operandIndex2)
  int ctx;
  undefined4 newOpcode;
  int operandIndex;
  int operandIndex2;
{
  int inst3;
  int inst2;
  int inst;
  int currentDefinition;
  int operandRecord;
  int operandRecord2;
  bool noExtraSource;
  undefined4 ref;
  undefined4 blockRef;
  uint src1Flags;
  int rebuiltInst;
  undefined4 operandRef4;
  uint src2Flags;
  int node;
  undefined4 destSelectWord;
  undefined4 operandRef;
  undefined4 src1SelectWord;
  undefined4 src2SelectWord;
  undefined4 saturate;
  undefined4 resultScaleCode;
  undefined4 destRegister;
  undefined4 destRegisterOffset;
  undefined4 operandRef2;
  undefined4 src1ValueNumber;
  undefined4 extraValueNumber;
  undefined4 src2ValueNumber;
  undefined4 operandRef3;
  
  inst = *(int *)(ctx + 0xb0);
  ref = *(undefined4 *)(inst + 4);
  blockRef = *(undefined4 *)(inst + 0x158);
  destRegister = *(undefined4 *)(inst + 0x94);
  destRegisterOffset = *(undefined4 *)(inst + 0x98);
  operandRef2 = *(undefined4 *)(inst + 0x8c);
  operandRecord = IRInst__getOperandRecord(inst,0);
  inst2 = *(int *)(ctx + 0xb0);
  destSelectWord = *(undefined4 *)(operandRecord + 0x10);
  operandRef = *(undefined4 *)(operandIndex * 0x18 + inst2 + 0x8c);
  saturate = *(undefined4 *)(inst2 + 0x120);
  resultScaleCode = *(undefined4 *)(inst2 + 0x124);
  operandRecord = IRInst__getOperandRecord(inst2,operandIndex);
  inst3 = *(int *)(ctx + 0xb0);
  src1SelectWord = *(undefined4 *)(operandRecord + 0x10);
  src1Flags = *(uint *)(operandIndex * 0x18 + inst3 + 0xa0);
  operandRef4 = *(undefined4 *)(operandIndex2 * 0x18 + inst3 + 0x8c);
  operandRecord2 = IRInst__getOperandRecord(inst3,operandIndex2);
  node = *(int *)(ctx + 0xb0);
  src2SelectWord = *(undefined4 *)(operandRecord2 + 0x10);
  noExtraSource = (*(uint *)(node + 0x14) & 0x200) == 0;
  src2Flags = *(uint *)(operandIndex2 * 0x18 + node + 0xa0);
  src1ValueNumber = *(undefined4 *)(operandIndex * 4 + ctx + 0x210);
  src2ValueNumber = *(undefined4 *)(operandIndex2 * 4 + ctx + 0x210);
  if (noExtraSource) {
    extraValueNumber = 0;
    operandRef3 = 0;
  }
  else {
    extraValueNumber = *(undefined4 *)(*(int *)(node + 0x84) * 4 + ctx + 0x210);
    operandRef3 = *(undefined4 *)(*(int *)(node + 0x84) * 0x18 + node + 0x8c);
  }
  DList__unlink(node);
  rebuiltInst = *(int *)(ctx + 0xb0);
  IRInst__reinitAsBinary(rebuiltInst,newOpcode,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(rebuiltInst,0,operandRef2);
  *(undefined4 *)(rebuiltInst + 0x94) = destRegister;
  *(undefined4 *)(rebuiltInst + 0x98) = destRegisterOffset;
  if (noExtraSource) {
    currentDefinition = VReg__currentDefinition(operandRef2,*(undefined4 *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0x3a0)
                        ,*(undefined4 *)(ctx + 0x238));
    *(undefined4 *)(ctx + 0x21c) = *(undefined4 *)(currentDefinition + 0xb0);
  }
  else {
    IRInst__appendSource(rebuiltInst,operandRef3);
    *(uint *)(rebuiltInst + 0x14) = *(uint *)(rebuiltInst + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x21c) = extraValueNumber;
  }
  *(undefined4 *)(rebuiltInst + 0x9c) = destSelectWord;
  *(undefined4 *)(rebuiltInst + 0x120) = saturate;
  *(undefined4 *)(rebuiltInst + 0x124) = resultScaleCode;
  IRInst__setOperandRef(rebuiltInst,1,operandRef);
  operandRecord = IRInst__getOperandRecord(rebuiltInst,1);
  *(undefined4 *)(operandRecord + 0x10) = src1SelectWord;
  IROperand__setModifierBits(rebuiltInst + 0xa4,1,src1Flags & 1);
  IROperand__setModifierBits(rebuiltInst + 0xa4,2,src1Flags >> 1 & 1);
  IRInst__setOperandRef(rebuiltInst,2,operandRef4);
  operandRecord = IRInst__getOperandRecord(rebuiltInst,2);
  *(undefined4 *)(operandRecord + 0x10) = src2SelectWord;
  IROperand__setModifierBits(rebuiltInst + 0xbc,1,src2Flags & 1);
  IROperand__setModifierBits(rebuiltInst + 0xbc,2,src2Flags >> 1 & 1);
  *(undefined4 *)(ctx + 0x218) = src2ValueNumber;
  *(undefined4 *)(ctx + 0x214) = src1ValueNumber;
  DList__insertAfter(rebuiltInst,ref);
  *(undefined4 *)(rebuiltInst + 0x158) = blockRef;
  return;
}

/* ValueKey__foldMadZeroAddend @ 0x17e658 (112 bytes) */
int ValueKey__foldMadZeroAddend(param_1)
  int param_1;
{
  int callResult;
  
  callResult = Compiler__valueNumberForExpr(*(undefined4 *)(param_1 + 0x238),0);
  callResult = Inst__writtenLanesAllMatchValue(param_1,*(undefined4 *)(callResult + 4),3);
  if (callResult != 0) {
    ((int (*)())ValueKey__rewriteAsBinaryOfOperands)(param_1,0x13,1,2);
    ValueKey__rebuild(param_1);
  }
  return callResult != 0;
}

/* ValueKey__foldMadByPlusMinusOne @ 0x17e6c8 (280 bytes) */
int ValueKey__foldMadByPlusMinusOne(ctx)
  int ctx;
{
  bool bVar1;
  int callResult;
  undefined4 uVar3;
  int loopIndex;
  
  callResult = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0x3f800000);
  loopIndex = 1;
  uVar3 = *(undefined4 *)(callResult + 4);
  do {
    callResult = Inst__writtenLanesAllMatchValue(ctx,uVar3,loopIndex);
    if (callResult != 0) {
      ((int (*)())ValueKey__rewriteAsBinaryOfOperands)(ctx,0x12,(loopIndex == 1) + 1,3);
      ValueKey__rebuild(ctx);
      return 1;
    }
    bVar1 = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  callResult = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0xbf800000);
  loopIndex = 1;
  uVar3 = *(undefined4 *)(callResult + 4);
  do {
    callResult = Inst__writtenLanesAllMatchValue(ctx,uVar3,loopIndex);
    if (callResult != 0) {
      ((int (*)())ValueKey__rewriteAsBinaryOfOperands)(ctx,0x12,(loopIndex == 1) + 1,3);
      IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,1,
                   (*(uint *)(*(int *)(ctx + 0xb0) + 0xb8) ^ 1) & 1);
      ValueKey__rebuild(ctx);
      return 1;
    }
    bVar1 = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017e7e0 @ 0x17e7e0 (604 bytes) */
int FUN_0017e7e0(ctx)
  int ctx;
{
  undefined4 tmpSelectWord;
  undefined4 operandRef5;
  bool hasExtraSource;
  uint src1Flags;
  uint src2Flags;
  int loopIndex;
  uint src3Flags;
  int loopRemaining;
  int *newInst;
  undefined4 operandRef6;
  undefined4 savedDestRegister;
  undefined4 savedDestRegisterOffset;
  undefined4 src2SelectWord;
  undefined4 operandRef2;
  undefined4 src1SelectWord;
  undefined4 operandRef3;
  undefined4 operandRef4;
  int member0xb0;
  undefined4 afterInst;
  int *operandCursor;
  undefined4 block;
  int destSelectWord;
  undefined4 tmpSelect [3];
  undefined4 src3SelectWord;
  undefined4 operandRef;
  uint absFlag;
  int savedResultScale;
  int savedSaturate;
  
  loopIndex = *(int *)(ctx + 0xb0);
  block = *(undefined4 *)(loopIndex + 0x158);
  afterInst = *(undefined4 *)(loopIndex + 4);
  savedDestRegister = *(undefined4 *)(loopIndex + 0x94);
  savedDestRegisterOffset = *(undefined4 *)(loopIndex + 0x98);
  operandRef4 = *(undefined4 *)(loopIndex + 0x8c);
  loopIndex = IRInst__getOperandRecord(loopIndex,0);
  destSelectWord = *(int *)(loopIndex + 0x10);
  loopIndex = *(int *)(ctx + 0xb0);
  savedSaturate = *(int *)(loopIndex + 0x120);
  savedResultScale = *(int *)(loopIndex + 0x124);
  operandRef3 = *(undefined4 *)(loopIndex + 0xa4);
  loopRemaining = IRInst__getOperandRecord(loopIndex,1);
  loopIndex = *(int *)(ctx + 0xb0);
  src1SelectWord = *(undefined4 *)(loopRemaining + 0x10);
  src1Flags = *(uint *)(loopIndex + 0xb8);
  operandRef2 = *(undefined4 *)(loopIndex + 0xbc);
  loopRemaining = IRInst__getOperandRecord(loopIndex,2);
  loopIndex = *(int *)(ctx + 0xb0);
  src2SelectWord = *(undefined4 *)(loopRemaining + 0x10);
  src2Flags = *(uint *)(loopIndex + 0xd0);
  operandRef6 = *(undefined4 *)(loopIndex + 0xd4);
  loopIndex = IRInst__getOperandRecord(loopIndex,3);
  loopRemaining = *(int *)(ctx + 0xb0);
  src3SelectWord = *(undefined4 *)(loopIndex + 0x10);
  src3Flags = *(uint *)(loopRemaining + 0xe8);
  hasExtraSource = (*(uint *)(loopRemaining + 0x14) >> 9 & 1) != 0;
  absFlag = src3Flags >> 1 & 1;
  if (hasExtraSource) {
    operandRef = *(undefined4 *)(*(int *)(loopRemaining + 0x84) * 0x18 + loopRemaining + 0x8c);
  }
  else {
    operandRef = 0;
  }
  DList__unlink(loopRemaining);
  member0xb0 = *(int *)(ctx + 0xb0);
  IRInst__reinitAsBinary(member0xb0,0x13,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(block,afterInst,member0xb0);
  newInst = (int *)IRInst__create(0x12,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(block,*(undefined4 *)(ctx + 0xb0),newInst);
  loopIndex = *(int *)(ctx + 0x238);
  operandRef5 = *(undefined4 *)(*(int *)(loopIndex + 0x6c4) + 0x3ac);
  loopRemaining = *(int *)(loopIndex + 0x3ac) + -1;
  *(int *)(loopIndex + 0x3ac) = loopRemaining;
  operandRef5 = FUN_00127608(operandRef5,0,loopRemaining,0);
  IRInst__setOperandRef(member0xb0,0,operandRef5);
  IRInst__setOperandRef(member0xb0,1,operandRef3);
  loopIndex = IRInst__getOperandRecord(member0xb0,1);
  *(undefined4 *)(loopIndex + 0x10) = src1SelectWord;
  IROperand__setModifierBits(member0xb0 + 0xa4,1,src1Flags & 1);
  IROperand__setModifierBits(member0xb0 + 0xa4,2,src1Flags >> 1 & 1);
  IRInst__setOperandRef(member0xb0,2,operandRef2);
  loopIndex = IRInst__getOperandRecord(member0xb0,2);
  *(undefined4 *)(loopIndex + 0x10) = src2SelectWord;
  IROperand__setModifierBits(member0xb0 + 0xbc,1,src2Flags & 1);
  IROperand__setModifierBits(member0xb0 + 0xbc,2,src2Flags >> 1 & 1);
  *(undefined4 *)(member0xb0 + 0x94) = savedDestRegister;
  *(undefined4 *)(member0xb0 + 0x98) = savedDestRegisterOffset;
  *(int *)(member0xb0 + 0x9c) = destSelectWord;
  FUN_0012306c(operandRef5,member0xb0);
  loopIndex = 0;
  tmpSelect[0] = DAT_001b01dc;
  loopRemaining = 4;
  do {
    if (*(char *)((int)tmpSelect + loopIndex + -4) == '\0') {
      *(char *)((int)tmpSelect + loopIndex) = (char)loopIndex;
    }
    loopIndex = loopIndex + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  IRInst__setOperandRef(newInst,0,operandRef4);
  newInst[0x27] = destSelectWord;
  IRInst__setOperandRef(newInst,1,operandRef5);
  tmpSelectWord = tmpSelect[0];
  loopIndex = IRInst__getOperandRecord(newInst,1);
  *(undefined4 *)(loopIndex + 0x10) = tmpSelectWord;
  IRInst__setOperandRef(newInst,2,operandRef6);
  loopIndex = IRInst__getOperandRecord(newInst,2);
  *(undefined4 *)(loopIndex + 0x10) = src3SelectWord;
  IROperand__setModifierBits(newInst + 0x2f,1,src3Flags & 1);
  IROperand__setModifierBits(newInst + 0x2f,2,absFlag);
  newInst[0x48] = savedSaturate;
  newInst[0x49] = savedResultScale;
  FUN_0012306c(operandRef4,newInst);
  loopIndex = 1;
  operandCursor = newInst;
  while( true ) {
    loopRemaining = (**(code **)(*newInst + 0x14))(newInst);
    if (loopRemaining < loopIndex) break;
    VReg__addUse(operandCursor[0x29],loopIndex,newInst);
    loopIndex = loopIndex + 1;
    operandCursor = operandCursor + 6;
  }
  if (hasExtraSource) {
    IRInst__appendSource(member0xb0,operandRef);
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200;
    VReg__addUse(operandRef,*(undefined4 *)(member0xb0 + 0x84),member0xb0);
    IRInst__appendSource(newInst,operandRef4);
    newInst[5] = newInst[5] | 0x200;
    VReg__addUse(operandRef4,newInst[0x21],newInst);
  }
  _memset((void *)(ctx + 0xb4),0,0x15c);
  ValueKey__fillSourceLaneUsage(ctx);
  return ValueKey__fill(ctx);
}

/* ValueKey__rewriteAsAdd @ 0x17ebb0 (508 bytes) */
int ValueKey__rewriteAsAdd(ctx, valueKey, src1Swizzle, negateFlag)
  int ctx;
  int valueKey;
  undefined4 src1Swizzle;
  undefined4 negateFlag;
{
  int operandRef;
  int node;
  int inst3;
  int inst2;
  int operandRecord;
  int operandRecord2;
  undefined4 arenaAt378;
  bool hasExtraSource;
  undefined4 member0x21c;
  int inst;
  uint src2ModifierBits;
  int useScanPtr;
  undefined4 *loopPtr2;
  undefined4 src2Swizzle;
  undefined4 operandRef3;
  undefined4 operandRef4;
  undefined4 savedExtraSourceRef;
  undefined4 src0Swizzle;
  undefined4 destRegister;
  undefined4 destRegisterOffset;
  undefined4 afterInst;
  undefined4 block;
  undefined4 saturate;
  undefined4 resultScaleCode;
  int loopIndex;
  undefined4 operandRef2;
  
  inst = *(int *)(ctx + 0xb0);
  afterInst = *(undefined4 *)(inst + 4);
  block = *(undefined4 *)(inst + 0x158);
  destRegister = *(undefined4 *)(inst + 0x94);
  destRegisterOffset = *(undefined4 *)(inst + 0x98);
  operandRef4 = *(undefined4 *)(inst + 0x8c);
  operandRecord = IRInst__getOperandRecord(inst,0);
  inst2 = *(int *)(ctx + 0xb0);
  member0x21c = *(undefined4 *)(ctx + 0x21c);
  resultScaleCode = *(undefined4 *)(inst2 + 0x124);
  src0Swizzle = *(undefined4 *)(operandRecord + 0x10);
  saturate = *(undefined4 *)(inst2 + 0x120);
  operandRef3 = *(undefined4 *)(inst2 + 0xd4);
  operandRecord2 = IRInst__getOperandRecord(inst2,3);
  node = *(int *)(ctx + 0xb0);
  src2Swizzle = *(undefined4 *)(operandRecord2 + 0x10);
  src2ModifierBits = *(uint *)(node + 0xe8);
  hasExtraSource = (*(uint *)(node + 0x14) >> 9 & 1) != 0;
  if (hasExtraSource) {
    savedExtraSourceRef = *(undefined4 *)(*(int *)(node + 0x84) * 4 + ctx + 0x210);
    operandRef2 = *(undefined4 *)(*(int *)(node + 0x84) * 0x18 + node + 0x8c);
  }
  else {
    savedExtraSourceRef = 0;
    operandRef2 = 0;
  }
  DList__unlink(node);
  inst3 = *(int *)(ctx + 0xb0);
  IRInst__reinitAsBinary(inst3,0x12,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(block,afterInst,inst3);
  *(undefined4 *)(inst3 + 0x120) = saturate;
  *(undefined4 *)(inst3 + 0x124) = resultScaleCode;
  *(undefined4 *)(inst3 + 0x94) = destRegister;
  *(undefined4 *)(inst3 + 0x98) = destRegisterOffset;
  IRInst__setOperandRef(inst3,0,operandRef4);
  operandRef = *(int *)(valueKey + 0x8c);
  *(undefined4 *)(inst3 + 0x9c) = src0Swizzle;
  if (*(int *)(*(int *)(operandRef + 0x2c) + 4) == 0) {
    arenaAt378 = *(undefined4 *)(*(int *)(ctx + 0x238) + 0x378);
    loopPtr2 = (undefined4 *)Arena__alloc(arenaAt378,0x240);
    *loopPtr2 = arenaAt378;
    loopPtr2 = loopPtr2 + 1;
    ValueKey__init(loopPtr2,valueKey,*(undefined4 *)(ctx + 0x238));
    FUN_00174e0c(loopPtr2);
    ValueKey__propagateLaneValues(loopPtr2);
    VReg__pushDefinition(operandRef,*(undefined4 *)(*(int *)(valueKey + 0x158) + 0xb0),loopPtr2);
  }
  IRInst__setOperandRef(inst3,1,operandRef);
  operandRecord = IRInst__getOperandRecord(inst3,1);
  *(undefined4 *)(operandRecord + 0x10) = src1Swizzle;
  IROperand__setModifierBits(inst3 + 0xa4,1,negateFlag);
  IRInst__setOperandRef(inst3,2,operandRef3);
  operandRecord = IRInst__getOperandRecord(inst3,2);
  *(undefined4 *)(operandRecord + 0x10) = src2Swizzle;
  IROperand__setModifierBits(inst3 + 0xbc,1,src2ModifierBits & 1);
  IROperand__setModifierBits(inst3 + 0xbc,2,src2ModifierBits >> 1 & 1);
  if (hasExtraSource) {
    IRInst__appendSource(inst3,operandRef2);
    *(uint *)(inst3 + 0x14) = *(uint *)(inst3 + 0x14) | 0x200;
  }
  *(int *)(ctx + 0x214) = valueKey;
  *(undefined4 *)(ctx + 0x218) = member0x21c;
  if (!hasExtraSource) {
    savedExtraSourceRef = 0;
  }
  *(undefined4 *)(ctx + 0x21c) = savedExtraSourceRef;
  FUN_0012306c(operandRef4,inst3);
  if (0 < *(int *)(inst3 + 0x84)) {
    loopIndex = 1;
    useScanPtr = inst3;
    do {
      loopPtr2 = (undefined4 *)(useScanPtr + 0xa4);
      useScanPtr = useScanPtr + 0x18;
      VReg__addUse(*loopPtr2,loopIndex,inst3);
      loopIndex = loopIndex + 1;
    } while (loopIndex <= *(int *)(inst3 + 0x84));
  }
  _memset((void *)(ctx + 0xb4),0,0x15c);
  ValueKey__fillSourceLaneUsage(ctx);
  ValueKey__fill(ctx);
  return;
}

/* FUN_0017ee68 @ 0x17ee68 (468 bytes) */
int FUN_0017ee68(ctx)
  int ctx;
{
  bool hasExtraSource;
  undefined4 resultScaleCode;
  undefined4 saturate;
  undefined4 operandRef2;
  int node;
  int inst2;
  int inst;
  int operandIndex;
  int operandRecord;
  bool isLastLane;
  uint selectConstA;
  uint selectConstA2;
  undefined *selectTable;
  int newValueNumber;
  undefined4 operandRef3;
  undefined4 selectTemp;
  undefined4 selectTemp2;
  undefined4 operandRef4;
  undefined4 destSelectWord;
  int origOpcode;
  undefined4 operandValueNumber;
  undefined4 operandRef;
  uint operandSelect;
  undefined4 savedDestRegister;
  undefined4 savedDestRegisterOffset;
  int loopIndex;
  int rebuiltInst;
  undefined4 block;
  undefined4 afterInst;
  float laneValues [5];
  
  loopIndex = 1;
  while ((FUN_00178d78(laneValues,ctx,loopIndex), laneValues[0] != FLOAT_001aa0e8 &&
         (laneValues[0] != FLOAT_001aa114))) {
    isLastLane = loopIndex == 2;
    loopIndex = loopIndex + 1;
    if (isLastLane) {
      return 0;
    }
  }
  inst = *(int *)(ctx + 0xb0);
  operandIndex = (loopIndex == 1) + 1;
  operandRef4 = *(undefined4 *)(inst + 0x8c);
  origOpcode = *(int *)(*(int *)(inst + 0x88) + 8);
  loopIndex = IRInst__getOperandRecord(inst,0);
  inst2 = *(int *)(ctx + 0xb0);
  destSelectWord = *(undefined4 *)(loopIndex + 0x10);
  operandRef = *(undefined4 *)(operandIndex * 0x18 + inst2 + 0x8c);
  saturate = *(undefined4 *)(inst2 + 0x120);
  resultScaleCode = *(undefined4 *)(inst2 + 0x124);
  loopIndex = IRInst__getOperandRecord(inst2,operandIndex);
  node = *(int *)(ctx + 0xb0);
  operandSelect = *(uint *)(loopIndex + 0x10);
  operandValueNumber = *(undefined4 *)(operandIndex * 4 + ctx + 0x210);
  hasExtraSource = (*(uint *)(node + 0x14) >> 9 & 1) != 0;
  if (hasExtraSource) {
    operandRef3 = *(undefined4 *)(*(int *)(node + 0x84) * 0x18 + node + 0x8c);
  }
  else {
    operandRef3 = 0;
  }
  afterInst = *(undefined4 *)(node + 4);
  savedDestRegister = *(undefined4 *)(node + 0x94);
  savedDestRegisterOffset = *(undefined4 *)(node + 0x98);
  block = *(undefined4 *)(node + 0x158);
  DList__unlink(node);
  rebuiltInst = *(int *)(ctx + 0xb0);
  IRInst__reinitAsBinary(rebuiltInst,0x12,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(block,afterInst,rebuiltInst);
  loopIndex = *(int *)(ctx + 0x238);
  newValueNumber = *(int *)(loopIndex + 0x3ac) + -1;
  operandRef2 = *(undefined4 *)(*(int *)(loopIndex + 0x6c4) + 0x3ac);
  *(int *)(loopIndex + 0x3ac) = newValueNumber;
  operandRef2 = FUN_00127608(operandRef2,0,newValueNumber,0);
  FUN_0012306c(operandRef2,*(undefined4 *)(ctx + 0xb0));
  IRInst__setOperandRef(*(undefined4 *)(ctx + 0xb0),0,operandRef2);
  *(undefined4 *)(rebuiltInst + 0x94) = savedDestRegister;
  *(undefined4 *)(rebuiltInst + 0x98) = savedDestRegisterOffset;
  IRInst__setOperandRef(rebuiltInst,1,operandRef);
  IRInst__setOperandRef(rebuiltInst,2,operandRef);
  loopIndex = IRInst__create(0x12,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(block,rebuiltInst,loopIndex);
  IRInst__setOperandRef(loopIndex,0,operandRef4);
  *(undefined4 *)(loopIndex + 0x94) = savedDestRegister;
  *(undefined4 *)(loopIndex + 0x98) = savedDestRegisterOffset;
  *(undefined4 *)(loopIndex + 0x9c) = destSelectWord;
  if (hasExtraSource) {
    IRInst__appendSource(loopIndex,operandRef3);
    *(uint *)(loopIndex + 0x14) = *(uint *)(loopIndex + 0x14) | 0x200;
  }
  *(undefined4 *)(loopIndex + 0x120) = saturate;
  *(undefined4 *)(loopIndex + 0x124) = resultScaleCode;
  *(undefined4 *)(ctx + 0x218) = operandValueNumber;
  *(undefined4 *)(ctx + 0x214) = operandValueNumber;
  selectTable = PTR_DAT_001e8b8c;
  selectConstA = DAT_001b01d8;
  if (origOpcode == 0x1c) {
    selectTemp = *(undefined4 *)(PTR_DAT_001e8b8c + (operandSelect >> 0x16 & 0x3fc));
    *(uint *)(rebuiltInst + 0x9c) = DAT_001b01d0 & 0xffffff;
    operandRecord = IRInst__getOperandRecord(rebuiltInst,1);
    selectTemp2 = *(undefined4 *)(selectTable + (operandSelect >> 0xe & 0x3fc));
    *(undefined4 *)(operandRecord + 0x10) = selectTemp;
    operandRecord = IRInst__getOperandRecord(rebuiltInst,2);
    *(undefined4 *)(operandRecord + 0x10) = selectTemp2;
    IRInst__setOperandRef(loopIndex,1,operandRef2);
    IRInst__setOperandRef(loopIndex,2,operandRef);
    selectTemp = *(undefined4 *)selectTable;
    operandRecord = IRInst__getOperandRecord(loopIndex,1);
    *(undefined4 *)(operandRecord + 0x10) = selectTemp;
    selectTemp = *(undefined4 *)(selectTable + (operandSelect >> 6 & 0x3fc));
    loopIndex = IRInst__getOperandRecord(loopIndex,2);
    *(undefined4 *)(loopIndex + 0x10) = selectTemp;
  }
  else if (origOpcode == 0x1d) {
    *(uint *)(rebuiltInst + 0x9c) = DAT_001b01d0 & 0xffff;
    operandRecord = IRInst__getOperandRecord(rebuiltInst,1);
    selectConstA2 = DAT_001b01d8;
    *(uint *)(operandRecord + 0x10) = operandSelect & 0xff0000 | operandSelect & 0xff000000 | selectConstA & 0xffff;
    operandRecord = IRInst__getOperandRecord(rebuiltInst,2);
    *(uint *)(operandRecord + 0x10) = (operandSelect & 0xff) << 0x10 | (operandSelect & 0xff00) << 0x10 | selectConstA2 & 0xffff;
    IRInst__setOperandRef(loopIndex,1,operandRef2);
    IRInst__setOperandRef(loopIndex,2,operandRef2);
    selectTable = PTR_DAT_001e8b8c;
    selectTemp = *(undefined4 *)PTR_DAT_001e8b8c;
    operandRecord = IRInst__getOperandRecord(loopIndex,1);
    selectTemp2 = *(undefined4 *)(selectTable + 4);
    *(undefined4 *)(operandRecord + 0x10) = selectTemp;
    loopIndex = IRInst__getOperandRecord(loopIndex,2);
    *(undefined4 *)(loopIndex + 0x10) = selectTemp2;
  }
  ValueKey__rebuild(ctx);
  return 1;
}

/* ValueKey__foldMulOfConstants @ 0x17f1f8 (512 bytes) */
int ValueKey__foldMulOfConstants(ctx)
  int ctx;
{
  int *hwLimits;
  int operandRecord;
  bool moreLanes;
  float *loopPtr2;
  int valueNumber;
  float *exprRecord;
  undefined4 productNegated;
  undefined4 staleArg5;
  undefined4 staleArg6;
  int *valueNumberPtr;
  int loopIndex;
  int loopRemaining;
  undefined4 destMask;
  uint laneProducts;
  float operandConsts [7];
  undefined4 writeMaskOut;
  undefined4 maskedSelect [4];
  
  loopIndex = 5;
  loopPtr2 = operandConsts;
  do {
    *loopPtr2 = GH_U2F(0x7fff0000U);
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + -1;
  } while (loopIndex != 0);
  loopPtr2 = (float *)&laneProducts;
  do {
    *loopPtr2 = GH_U2F(0x7fff0000U);
    loopPtr2 = loopPtr2 + 1;
  } while (loopPtr2 != operandConsts);
  loopIndex = 0;
  loopRemaining = 4;
  do {
    *(undefined4 *)(loopIndex + (int)&laneProducts) = 0x7ffffffe;
    loopIndex = loopIndex + 4;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  loopIndex = 0;
  loopRemaining = ctx + 0x170;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      valueNumberPtr = (int *)(loopRemaining + 8);
      loopPtr2 = operandConsts + 1;
      do {
        valueNumber = *valueNumberPtr;
        if (-1 < valueNumber) {
          return 0;
        }
        valueNumberPtr = valueNumberPtr + 4;
        exprRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),valueNumber);
        *loopPtr2 = *exprRecord;
        loopPtr2 = loopPtr2 + 1;
      } while (loopPtr2 != operandConsts + 3);
      (&laneProducts)[loopIndex] = (uint)GH_F2U((float)((operandConsts[1] * operandConsts[2])));
    }
    moreLanes = loopIndex != 3;
    loopRemaining = loopRemaining + 4;
    loopIndex = loopIndex + 1;
  } while (moreLanes);
  loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
  WriteMask__fromSelectWord(&writeMaskOut,*(undefined4 *)(loopIndex + 0x10));
  SelectWord__maskUnused(maskedSelect,0x10203,writeMaskOut);
  loopIndex = *(int *)(ctx + 0x238);
  destMask = maskedSelect[0];
  loopIndex = (**(code **)(**(int **)(loopIndex + 0x30c) + 0x154))
                    (*(int **)(loopIndex + 0x30c),*(undefined4 *)(loopIndex + 0x6c4),&laneProducts,&destMask,
                     staleArg5,staleArg6,loopIndex);
  if (loopIndex == 0) {
    loopIndex = 0;
    loopPtr2 = (float *)&laneProducts;
    do {
      loopRemaining = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if (*(char *)(loopIndex + loopRemaining + 0x10) != '\x01') {
        *loopPtr2 = -*loopPtr2;
      }
      moreLanes = loopIndex != 3;
      loopPtr2 = loopPtr2 + 1;
      loopIndex = loopIndex + 1;
    } while (moreLanes);
    hwLimits = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
    loopIndex = (**(code **)(*hwLimits + 0x154))
                      (hwLimits,*(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4),&laneProducts,&destMask
                      );
    if (loopIndex == 0) {
      return 0;
    }
    productNegated = 1;
  }
  else {
    productNegated = 0;
  }
  ((int (*)())ValueKey__rewriteAsAdd)(ctx,loopIndex,destMask,productNegated);
  return 1;
}

/* ValueKey__foldMinMaxOfNegatedPair @ 0x17f3f8 (412 bytes) */
int ValueKey__foldMinMaxOfNegatedPair(ctx, signFlag)
  int ctx;
  uint signFlag;
{
  int hwPredicateResult;
  int lanesAllSatisfy;
  int inst;
  int operandRecord;
  bool lastLane;
  bool signNotSeen;
  int laneWordPtr;
  uint *exprRecord;
  int *a0;
  uint signBit;
  int loopIndex;
  undefined4 writeMaskWord [6];
  
  lanesAllSatisfy = Inst__allWrittenLanesSatisfy(ctx,1,2);
  if (lanesAllSatisfy != 0) {
    inst = *(int *)(ctx + 0xb0);
    if (((*(uint *)(inst + 0xb8) & 1) != (*(uint *)(inst + 0xd0) & 1)) &&
       ((*(uint *)(inst + 0xb8) >> 1 & 1) == (*(uint *)(inst + 0xd0) >> 1 & 1))) {
      signNotSeen = true;
      operandRecord = IRInst__getOperandRecord(inst,0);
      signBit = 0;
      loopIndex = 0;
      writeMaskWord[0] = *(undefined4 *)(operandRecord + 0x10);
      laneWordPtr = ctx;
      do {
        if (*(char *)((int)writeMaskWord + loopIndex) == '\0') {
          if (-1 < *(int *)(laneWordPtr + 0x178)) {
LAB_0017f514:
            a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
            hwPredicateResult = (**(code **)(*a0 + 0x88))(a0);
            if (hwPredicateResult == 0) {
              return 0;
            }
            ((int (*)())ValueKey__rewriteAsMovOfOperand)(ctx,1);
            IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,2,1);
            IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,1,signFlag ^ 1);
            ValueKey__rebuild(ctx);
            return 1;
          }
          exprRecord = (uint *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(int *)(laneWordPtr + 0x178));
          if (signNotSeen) {
            signBit = *exprRecord >> 0x1f;
            signNotSeen = false;
          }
          else if (*exprRecord >> 0x1f != signBit) goto LAB_0017f514;
        }
        lastLane = loopIndex == 3;
        laneWordPtr = laneWordPtr + 4;
        loopIndex = loopIndex + 1;
        if (lastLane) {
          ((int (*)())ValueKey__rewriteAsMovOfOperand)(ctx,1);
          IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,1,(uint)(signFlag == signBit));
          IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,2,0);
          ValueKey__rebuild(ctx);
          return 1;
        }
      } while( true );
    }
  }
  return 0;
}

/* ValueKey__foldMaxOfNegatedPair @ 0x17f594 (8 bytes) */
int ValueKey__foldMaxOfNegatedPair(param_1)
  undefined4 param_1;
{
  undefined4 callResult;
  
  callResult = ((int (*)())ValueKey__foldMinMaxOfNegatedPair)(param_1,1);
  return callResult;
}

/* ValueKey__foldMinOfNegatedPair @ 0x17f59c (8 bytes) */
int ValueKey__foldMinOfNegatedPair(param_1)
  undefined4 param_1;
{
  undefined4 callResult;
  
  callResult = ((int (*)())ValueKey__foldMinMaxOfNegatedPair)(param_1,0);
  return callResult;
}

/* FUN_0017f5a4 @ 0x17f5a4 (488 bytes) */
int FUN_0017f5a4(ctx)
  int ctx;
{
  int loopIndex;
  int *inst;
  undefined4 operandRef;
  int iVar4;
  int *piVar5;
  
  loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
  loopIndex = FUN_000f2e18(*(undefined4 *)(loopIndex + 0x10));
  if (loopIndex == 0) {
    inst = (int *)IRInst__clone(*(undefined4 *)(ctx + 0xb0),*(undefined4 *)(ctx + 0x238),0)
    ;
    loopIndex = *(int *)(ctx + 0x238);
    operandRef = *(undefined4 *)(*(int *)(loopIndex + 0x6c4) + 0x3ac);
    iVar4 = *(int *)(loopIndex + 0x3ac) + -1;
    *(int *)(loopIndex + 0x3ac) = iVar4;
    operandRef = FUN_00127608(operandRef,0,iVar4,0);
    FUN_0012306c(operandRef,*(undefined4 *)(ctx + 0xb0));
    IRInst__setOperandRef(*(undefined4 *)(ctx + 0xb0),0,operandRef);
    loopIndex = inst[0x23];
    *(undefined1 *)(*(int *)(ctx + 0xb0) + 0x9f) = 1;
    inst[0x27] = 0x1010100;
    FUN_0012306c(loopIndex,inst);
    loopIndex = 1;
    piVar5 = inst;
    while( true ) {
      iVar4 = (**(code **)(*inst + 0x14))(inst);
      if (iVar4 < loopIndex) break;
      VReg__addUse(piVar5[0x29],loopIndex,inst);
      loopIndex = loopIndex + 1;
      piVar5 = piVar5 + 6;
    }
    if ((*(uint *)(*(int *)(ctx + 0xb0) + 0x14) & 0x200) == 0) {
      IRInst__appendSource(*(int *)(ctx + 0xb0),operandRef);
      VReg__addUse(operandRef,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x84),*(int *)(ctx + 0xb0));
      *(uint *)(*(int *)(ctx + 0xb0) + 0x14) =
           *(uint *)(*(int *)(ctx + 0xb0) + 0x14) | 0x200;
      loopIndex = VReg__currentDefinition(operandRef,*(undefined4 *)
                                  (*(int *)(*(uint *)(ctx + 0x238) + 0x6c4) + 0x3a0),
                           *(uint *)(ctx + 0x238));
      *(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x84) * 4 + ctx + 0x210) =
           *(undefined4 *)(loopIndex + 0xb0);
      IRInst__appendSource(inst,operandRef);
      VReg__addUse(operandRef,inst[0x21],inst);
      inst[5] = inst[5] | 0x200;
    }
    else {
      IRInst__setOperandRef(inst,inst[0x21],operandRef);
      VReg__addUse(operandRef,inst[0x21],inst);
    }
    ValueKey__rebuild(ctx);
    Block__insertInstAfter(*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158),*(int *)(ctx + 0xb0),inst);
    return;
  }
  return;
}

/* FUN_0017f78c @ 0x17f78c (96 bytes) */
int FUN_0017f78c(ctx)
  int ctx;
{
  int iVar1;
  
  if ((*(int *)(*(int *)(ctx + 0xb0) + 0x98) != 0x2c) &&
     (iVar1 = FUN_0011379c(*(undefined4 *)(ctx + 0x238),*(int *)(ctx + 0xb0)), iVar1 != 0))
  {
    ((int (*)())FUN_0017f5a4)(ctx);
    return;
  }
  return;
}

/* ValueKey__simplifyInstruction @ 0x17f7ec (1848 bytes) */
int ValueKey__simplifyInstruction(ctx)
  int ctx;
{
  bool notLastLane;
  int loopIndex;
  int *loopPtr3;
  int *loopPtr4;
  int loopIndex2;
  int laneResults [8];
  
  if ((*(int *)(*(int *)(ctx + 0xb0) + 0x80) == 1) &&
     (loopIndex = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0), *(int *)(loopIndex + 0x10) == DAT_001b01d0)) {
    return 0;
  }
  loopPtr4 = laneResults;
  loopIndex = 4;
  loopPtr3 = loopPtr4;
  do {
    *loopPtr3 = 0x7ffffffe;
    loopPtr3 = loopPtr3 + 1;
    loopIndex = loopIndex + -1;
  } while (loopIndex != 0);
  loopIndex2 = 4;
  loopIndex = 0;
  do {
    *(undefined4 *)(loopIndex + (int)loopPtr4) = 0x7ffffffe;
    loopIndex = loopIndex + 4;
    loopIndex2 = loopIndex2 + -1;
  } while (loopIndex2 != 0);
  loopIndex = ((int (*)())FUN_0017dbdc)(ctx,loopPtr4);
  if (loopIndex != 0) {
    return 0;
  }
  loopPtr3 = (int *)Opcode__getInfo(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8));
  loopIndex = (**(code **)(*loopPtr3 + 0x14))(loopPtr3,ctx,loopPtr4,*(undefined4 *)(ctx + 0x238));
  if (loopIndex == 0) {
    return 0;
  }
  loopIndex2 = *(int *)(ctx + 0xb0);
  loopIndex = *(int *)(*(int *)(loopIndex2 + 0x88) + 8);
  if (loopIndex == 0x1d) {
    ValueKey__cancelNegatedSourcePair(ctx);
    loopIndex = ((int (*)())ValueKey__foldDot4UnitVectorSource)(ctx);
    if (loopIndex != 0) {
      return 0;
    }
    loopIndex = ValueKey__foldDotPowerOfTwoIntoOutputScale(ctx);
    if (loopIndex != 0) {
      return 1;
    }
    loopIndex = FUN_001766bc(ctx);
joined_r0x0017f980:
    if (loopIndex != 0) {
      return 1;
    }
  }
  else if (loopIndex < 0x1e) {
    if (loopIndex == 0x17) {
      loopIndex = ((int (*)())ValueKey__foldMaxOfConstants)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())ValueKey__replaceWithSource1IfSourcesEqual)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())ValueKey__foldMaxOfNegatedPair)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex2 = 0;
      loopPtr3 = loopPtr4;
      do {
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
          loopIndex = *(int *)(ctx + 0x238);
          if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*loopPtr3 == 0x7ffffffe) && (loopIndex = ValueKey__forwardSource1LaneIfEqual(ctx,loopIndex2), loopIndex == 0)) {
            ValueKey__forwardSelectedSourceBySign(ctx,loopIndex2);
          }
        }
        notLastLane = loopIndex2 != 3;
        loopPtr3 = loopPtr3 + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (notLastLane);
    }
    else if (loopIndex < 0x18) {
      if (loopIndex == 0x13) {
        ValueKey__cancelNegatedSourcePair(ctx);
        loopIndex = ((int (*)())ValueKey__foldMulByZero)(ctx);
        if (loopIndex != 0) {
          return 0;
        }
        loopIndex = ((int (*)())ValueKey__foldMulByPlusMinusOne)(ctx);
        if (loopIndex != 0) {
          return 0;
        }
        loopIndex = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),0xc);
        if ((loopIndex != 0) && (loopIndex = ((int (*)())ValueKey__foldMulPowerOfTwoIntoOutputScale)(ctx), loopIndex != 0)) {
          return 0;
        }
        loopIndex2 = 0;
        loopPtr3 = loopPtr4;
        do {
          loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
          if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
            loopIndex = *(int *)(ctx + 0x238);
            if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
            goto LAB_0017fe30;
            if ((*loopPtr3 == 0x7ffffffe) && (loopIndex = FUN_001768d4(ctx,loopIndex2), loopIndex == 0)) {
              ValueKey__forwardOtherSourceIfOne(ctx,loopIndex2);
            }
          }
          notLastLane = loopIndex2 != 3;
          loopPtr3 = loopPtr3 + 1;
          loopIndex2 = loopIndex2 + 1;
        } while (notLastLane);
      }
      else {
        if (loopIndex != 0x14) goto LAB_0017fe28;
        ValueKey__cancelNegatedSourcePair(ctx);
        loopIndex = ((int (*)())ValueKey__foldMadZeroMultiplicand)(ctx);
        if (loopIndex != 0) {
          return 0;
        }
        loopIndex = ((int (*)())ValueKey__foldMadByPlusMinusOne)(ctx);
        if (loopIndex != 0) {
          return 1;
        }
        loopIndex = ((int (*)())ValueKey__foldMadZeroAddend)(ctx);
        if (loopIndex != 0) {
          return 1;
        }
        loopIndex = ((int (*)())ValueKey__foldMulOfConstants)(ctx);
        if (loopIndex != 0) {
          return 1;
        }
        loopIndex2 = 0;
        loopPtr3 = loopPtr4;
        do {
          loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
          if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
            loopIndex = *(int *)(ctx + 0x238);
            if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
            goto LAB_0017fe30;
            if (*loopPtr3 == 0x7ffffffe) {
              ValueKey__forwardAddendIfMultiplicandZero(ctx,loopIndex2);
            }
          }
          notLastLane = loopIndex2 != 3;
          loopPtr3 = loopPtr3 + 1;
          loopIndex2 = loopIndex2 + 1;
        } while (notLastLane);
      }
    }
    else {
      if (loopIndex != 0x19) {
        if (loopIndex == 0x1c) {
          ValueKey__cancelNegatedSourcePair(ctx);
          loopIndex = ((int (*)())ValueKey__foldDot3SingleLaneSource)(ctx);
          if (loopIndex != 0) {
            return 0;
          }
          loopIndex = ValueKey__foldDotPowerOfTwoIntoOutputScale(ctx);
          goto joined_r0x0017f980;
        }
LAB_0017fe28:
        loopIndex = *(int *)(ctx + 0x238);
        goto LAB_0017fe34;
      }
      loopIndex = ((int (*)())ValueKey__foldMinOfConstants)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())ValueKey__replaceWithSource1IfSourcesEqual)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())ValueKey__foldMinOfNegatedPair)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex2 = 0;
      loopPtr3 = loopPtr4;
      do {
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
          loopIndex = *(int *)(ctx + 0x238);
          if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*loopPtr3 == 0x7ffffffe) && (loopIndex = ValueKey__forwardSource1LaneIfEqual(ctx,loopIndex2), loopIndex == 0)) {
            ValueKey__forwardSelectedSourceByPositive(ctx,loopIndex2);
          }
        }
        notLastLane = loopIndex2 != 3;
        loopPtr3 = loopPtr3 + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (notLastLane);
    }
  }
  else if (loopIndex < 0x2b) {
    if (loopIndex < 0x27) {
      if (loopIndex < 0x24) goto LAB_0017fe28;
      loopIndex = ((int (*)())FUN_0017c5e0)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())ValueKey__replaceWithSource2IfSourcesEqual23)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())FUN_0017c4a4)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex2 = 0;
      loopPtr3 = loopPtr4;
      do {
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
          loopIndex = *(int *)(ctx + 0x238);
          if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*loopPtr3 == 0x7ffffffe) && (loopIndex = FUN_0017a034(ctx,loopIndex2), loopIndex == 0)) {
            ValueKey__forwardSource3LaneIfEqual(ctx,loopIndex2);
          }
        }
        notLastLane = loopIndex2 != 3;
        loopPtr3 = loopPtr3 + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (notLastLane);
    }
    else {
      loopIndex = ((int (*)())ValueKey__foldCompareOfConstants)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())ValueKey__foldCompareSameSourcesToConstant)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex2 = 0;
      loopPtr3 = loopPtr4;
      do {
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
          loopIndex = *(int *)(ctx + 0x238);
          if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*loopPtr3 == 0x7ffffffe) && (loopIndex = FUN_00176954(ctx,loopIndex2), loopIndex == 0)) {
            ValueKey__foldCompareSameSourcesValueNumber(ctx,loopIndex2);
          }
        }
        notLastLane = loopIndex2 != 3;
        loopPtr3 = loopPtr3 + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (notLastLane);
    }
  }
  else {
    if (loopIndex == 0x8b) {
      loopIndex = FUN_0017a748(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = FUN_0017a3d4(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      FUN_00177748(ctx);
      loopIndex2 = *(int *)(ctx + 0xb0);
      loopIndex = *(int *)(ctx + 0x238);
      goto LAB_0017fe34;
    }
    if (loopIndex != 0x8c) goto LAB_0017fe28;
    loopIndex = FUN_0017a8a4(ctx);
    if (loopIndex != 0) {
      return 0;
    }
  }
  loopIndex2 = *(int *)(ctx + 0xb0);
  loopIndex = *(int *)(ctx + 0x238);
LAB_0017fe34:
  loopIndex = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(loopIndex2 + 0x88) + 8),loopIndex);
  if ((loopIndex == 0) &&
     (loopIndex = OpcodeTraits__flagBit8(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(ctx + 0x238)), loopIndex == 0)) {
    loopIndex = 0;
    do {
      if (*(int *)(*(int *)(ctx + 0x238) + 0x658) <=
          *(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0xa8)) {
        return 0;
      }
      if (*loopPtr4 != 0x7ffffffe) {
        FUN_001765a4(ctx,*loopPtr4,loopIndex);
      }
      notLastLane = loopIndex != 3;
      loopPtr4 = loopPtr4 + 1;
      loopIndex = loopIndex + 1;
    } while (notLastLane);
  }
  else {
    loopIndex = 0;
    do {
      if (*(int *)(*(int *)(ctx + 0x238) + 0x658) <=
          *(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0xa8)) {
        return 0;
      }
      if (*loopPtr4 != 0x7ffffffe) {
        FUN_001765a4(ctx,*loopPtr4,loopIndex);
      }
      notLastLane = loopIndex != 3;
      loopPtr4 = loopPtr4 + 1;
      loopIndex = loopIndex + 1;
    } while (notLastLane);
  }
  return 0;
LAB_0017fe30:
  loopIndex2 = *(int *)(ctx + 0xb0);
  goto LAB_0017fe34;
}

/* FUN_00180154 @ 0x180154 (888 bytes) */
int FUN_00180154(ctx)
  int ctx;
{
  int operandsMatch2;
  int operandsMatch;
  int operandRecord;
  bool loopContinue;
  uint inst0xb8Flags;
  int laneRecord;
  uint inst0xd0Flags;
  int loopIndex;
  int loopIndex2;
  
  switch(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8)) {
  case 0x16:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
    FUN_0017662c(ctx);
    loopIndex = 0;
    loopIndex2 = ctx;
    do {
      operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if (((*(char *)(loopIndex + operandRecord + 0x10) != '\x01') && (*(int *)(loopIndex2 + 0x30) == 0)) &&
         (*(int *)(*(int *)(ctx + 0xb0) + 0x124) < 1)) {
        laneRecord = *(int *)(loopIndex2 + 0x40);
        if (laneRecord == 0) {
          laneRecord = FUN_00174ce0(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
          *(int *)(loopIndex2 + 0x40) = laneRecord;
        }
        *(undefined4 *)(laneRecord + 0x10) = 4;
      }
      loopContinue = loopIndex != 3;
      loopIndex2 = loopIndex2 + 4;
      loopIndex = loopIndex + 1;
    } while (loopContinue);
    return;
  default:
    return;
  case 0x1c:
    break;
  case 0x1d:
    loopIndex = 0;
    loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(int *)(loopIndex2 + 0x10) != DAT_001b01d0) {
      loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      loopIndex = SelectWord__firstWrittenComponent(*(undefined4 *)(loopIndex2 + 0x10));
    }
    if (*(int *)(loopIndex * 4 + ctx + 0x30) == 0) {
      inst0xd0Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
      inst0xb8Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
      if (((inst0xb8Flags & 1) == (inst0xd0Flags & 1)) && ((inst0xb8Flags >> 1 & 1) == (inst0xd0Flags >> 1 & 1))) {
        loopIndex2 = 0;
        do {
          operandsMatch = ValueKey__operandLanesEqual(ctx,loopIndex2,1,2);
          if (operandsMatch == 0) {
            return;
          }
          loopContinue = loopIndex2 != 3;
          loopIndex2 = loopIndex2 + 1;
        } while (loopContinue);
        loopIndex2 = *(int *)(loopIndex * 4 + ctx + 0x40);
        if (loopIndex2 == 0) {
          loopIndex2 = FUN_00174ce0(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
        }
        *(undefined4 *)(loopIndex2 + 0xc) = 4;
        loopIndex = 4;
        do {
          *(int *)(ctx + 0x40) = loopIndex2;
          ctx = ctx + 4;
          loopIndex = loopIndex + -1;
        } while (loopIndex != 0);
      }
    }
    return;
  }
  loopIndex = 0;
  loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
  if (*(int *)(loopIndex2 + 0x10) != DAT_001b01d0) {
    loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    loopIndex = SelectWord__firstWrittenComponent(*(undefined4 *)(loopIndex2 + 0x10));
  }
  if (*(int *)(loopIndex * 4 + ctx + 0x30) == 0) {
    inst0xd0Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    inst0xb8Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((inst0xb8Flags & 1) == (inst0xd0Flags & 1)) && ((inst0xb8Flags >> 1 & 1) == (inst0xd0Flags >> 1 & 1))) {
      loopIndex2 = 0;
      do {
        operandsMatch2 = ValueKey__operandLanesEqual(ctx,loopIndex2,1,2);
        if (operandsMatch2 == 0) {
          return;
        }
        loopContinue = loopIndex2 != 2;
        loopIndex2 = loopIndex2 + 1;
      } while (loopContinue);
      loopIndex2 = *(int *)(loopIndex * 4 + ctx + 0x40);
      if (loopIndex2 == 0) {
        loopIndex2 = FUN_00174ce0(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
      }
      loopIndex = 4;
      *(undefined4 *)(loopIndex2 + 0xc) = 4;
      do {
        *(int *)(ctx + 0x40) = loopIndex2;
        ctx = ctx + 4;
        loopIndex = loopIndex + -1;
      } while (loopIndex != 0);
    }
  }
  return;
}

/* ValueKey__canonicalizeConstantSources @ 0x180250 (1504 bytes) */
int ValueKey__canonicalizeConstantSources(key)
  int key;
{
  int selectTest;
  int laneUsedRow;
  int sourceKindCode;
  int regCheck;
  int vslot28Result;
  int vslot68Result;
  int canonSelectCopy;
  int flagBit0;
  int flagBit2Result;
  int operandRecord2;
  int operandRecord;
  bool moreChannels;
  bool hasNegativeConstant;
  char otherLaneSelect;
  int keyWordPtr;
  float *constantRecord;
  int operandCount;
  int loopIndex2;
  char *loopPtr5;
  int loopIndex3;
  int valueNumberRowPtr;
  int *loopPtr6;
  char *loopPtr4;
  undefined4 changed;
  int loopIndex;
  uint vectorFilledCount;
  uint lastEntryIndex;
  int *loopPtr7;
  uint *vector;
  int loopRemaining;
  int origSelect;
  int canonSelect [3];
  int maskedSelectOut;
  int maskScratch [7];
  
  loopPtr7 = *(int **)(key + 0xb0);
  if (*(int *)(loopPtr7[0x22] + 8) == 0x77) {
    operandRecord = IRInst__getOperandRecord(loopPtr7,1);
    canonSelect[0] = *(int *)(operandRecord + 0x10);
    hasNegativeConstant = false;
    loopIndex = 0;
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),0);
    origSelect = *(int *)(operandRecord + 0x10);
    keyWordPtr = key;
    do {
      if (*(int *)(keyWordPtr + 0x178) < 0) {
        constantRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),*(int *)(keyWordPtr + 0x178));
        maskScratch[1] = 0;
        if (0.0 <= *constantRecord) {
          if ((*(uint *)(*(int *)(*(int *)(key + 0x238) + 0x30c) + 8) & 0x1000) != 0) {
            *(undefined1 *)((int)canonSelect + loopIndex) = 4;
            *(undefined1 *)((int)canonSelect + loopIndex + -4) = 1;
          }
        }
        else {
          hasNegativeConstant = true;
        }
      }
      moreChannels = loopIndex != 3;
      keyWordPtr = keyWordPtr + 4;
      loopIndex = loopIndex + 1;
    } while (moreChannels);
    if (hasNegativeConstant) {
      hasNegativeConstant = false;
      loopIndex = 0;
      keyWordPtr = key;
      do {
        if (((*(uint *)(*(int *)(*(int *)(key + 0x238) + 0x30c) + 8) & 0x1000) != 0) &&
           (*(int *)(keyWordPtr + 0x178) < 0)) {
          constantRecord = (float *)Compiler__exprRecordForValueNumber(*(int *)(key + 0x238),*(int *)(keyWordPtr + 0x178));
          maskScratch[1] = 0;
          if (*constantRecord < 0.0) {
            if (hasNegativeConstant) {
              *(undefined1 *)((int)canonSelect + loopIndex) = 4;
              *(undefined1 *)((int)canonSelect + loopIndex + -4) = 1;
            }
            hasNegativeConstant = true;
          }
        }
        moreChannels = loopIndex != 3;
        keyWordPtr = keyWordPtr + 4;
        loopIndex = loopIndex + 1;
      } while (moreChannels);
    }
    loopIndex = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),1);
    canonSelectCopy = canonSelect[0];
    if (canonSelect[0] == *(int *)(loopIndex + 0x10)) {
      loopPtr7 = *(int **)(key + 0xb0);
      goto LAB_001803f4;
    }
    changed = 1;
    loopIndex = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),1);
    *(int *)(loopIndex + 0x10) = canonSelectCopy;
    *(int *)(*(int *)(key + 0xb0) + 0x9c) = origSelect;
    loopPtr7 = *(int **)(key + 0xb0);
  }
  else {
LAB_001803f4:
    changed = 0;
  }
  if (loopPtr7[0x20] == 0) {
LAB_001807f4:
    vslot68Result = (**(code **)(*loopPtr7 + 0x68))(loopPtr7);
    if (vslot68Result != 0) goto LAB_00180440;
  }
  else {
    flagBit0 = RegKind__flagBit0(loopPtr7[0x26]);
    if (((flagBit0 == 0) || ((loopPtr7[5] & 2U) != 0)) ||
       (flagBit0 = (**(code **)(*loopPtr7 + 0x50))(loopPtr7), flagBit0 != 0)) {
      loopPtr7 = *(int **)(key + 0xb0);
      goto LAB_001807f4;
    }
LAB_00180440:
    vslot28Result = (**(code **)(**(int **)(key + 0xb0) + 0x28))(*(int **)(key + 0xb0));
    if ((vslot28Result == 0) || ((*(uint *)(*(int *)(*(int *)(key + 0x238) + 0x30c) + 8) & 0x800) != 0))
    {
      loopPtr7 = *(int **)(key + 0xb0);
      goto LAB_001804a4;
    }
  }
  loopPtr7 = *(int **)(key + 0xb0);
  if (*(int *)(loopPtr7[0x22] + 8) != 0x77) {
    return changed;
  }
  if ((*(uint *)(*(int *)(*(int *)(key + 0x238) + 0x30c) + 8) & 0x800) == 0) {
    return changed;
  }
LAB_001804a4:
  loopIndex = 1;
  keyWordPtr = key;
  do {
    operandCount = (**(code **)(*loopPtr7 + 0x14))(loopPtr7);
    if (operandCount < loopIndex) {
      return changed;
    }
    regCheck = thunk_FUN_001268a4(*(undefined4 *)(loopIndex * 0x18 + *(int *)(key + 0xb0) + 0x98));
    if (regCheck != 0) {
      vector = *(uint **)(*(int *)(loopIndex * 0x18 + *(int *)(key + 0xb0) + 0x8c) + 0x2c);
      vectorFilledCount = vector[1];
      lastEntryIndex = vectorFilledCount - 1;
      if (lastEntryIndex < *vector) {
        if (vectorFilledCount <= lastEntryIndex) {
          _memset(vectorFilledCount * 4 + vector[2],0,(lastEntryIndex - vectorFilledCount) * 4 + 4);
          vector[1] = vectorFilledCount;
        }
        loopPtr7 = (int *)(lastEntryIndex * 4 + vector[2]);
      }
      else {
        loopPtr7 = (int *)Vector__elementRefGrow(vector,lastEntryIndex);
      }
      if ((*(int *)(*(int *)(*(int *)(*loopPtr7 + 0xb0) + 0x88) + 8) != 0x8e) ||
         (*(int *)(*loopPtr7 + 0xb4) != 0)) {
        sourceKindCode = ValueKey__findLaneWithSameValue(key,loopIndex,*(undefined4 *)(keyWordPtr + 0x228));
        if (sourceKindCode == 4) {
          operandRecord2 = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),loopIndex);
          origSelect = *(int *)(operandRecord2 + 0x10);
          operandRecord2 = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),loopIndex);
          canonSelect[0] = *(int *)(operandRecord2 + 0x10);
          flagBit2Result = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(*(int *)(key + 0xb0) + 0x88) + 8),
                               *(undefined4 *)(key + 0x238));
          if (flagBit2Result == 0) {
            SelectWord__maskUnused(maskScratch,canonSelect[0],*(undefined4 *)(keyWordPtr + 0x228));
            canonSelect[0] = maskScratch[0];
          }
          laneUsedRow = key + loopIndex * 4 + 0x220;
          valueNumberRowPtr = key + loopIndex * 0x10 + 0x160;
          loopPtr5 = (char *)(laneUsedRow + 4);
          loopPtr7 = (int *)(valueNumberRowPtr + 8);
          loopIndex2 = 0;
          do {
            if (*loopPtr5 != '\0') {
              loopRemaining = 4;
              loopPtr4 = (char *)(laneUsedRow + 4);
              loopPtr6 = (int *)(valueNumberRowPtr + 8);
              loopIndex3 = 0;
              do {
                if (*loopPtr4 != '\0') {
                  if (loopIndex3 == loopIndex2) break;
                  if ((*loopPtr7 == *loopPtr6) &&
                     (otherLaneSelect = *(char *)((int)canonSelect + loopIndex3 + -4),
                     *(char *)((int)canonSelect + loopIndex2) != otherLaneSelect)) {
                    *(char *)((int)canonSelect + loopIndex2) = otherLaneSelect;
                    break;
                  }
                }
                loopIndex3 = loopIndex3 + 1;
                loopPtr4 = loopPtr4 + 1;
                loopPtr6 = loopPtr6 + 1;
                loopRemaining = loopRemaining + -1;
              } while (loopRemaining != 0);
            }
            hasNegativeConstant = loopIndex2 != 3;
            loopPtr5 = loopPtr5 + 1;
            loopPtr7 = loopPtr7 + 1;
            loopIndex2 = loopIndex2 + 1;
          } while (hasNegativeConstant);
          if ((canonSelect[0] != origSelect) &&
             (loopPtr7 = *(int **)(*(int *)(key + 0x238) + 0x30c),
             loopIndex2 = (**(code **)(*loopPtr7 + 0x104))
                               (loopPtr7,*(undefined4 *)(key + 0xb0),loopIndex,canonSelect,0),
             selectTest = canonSelect[0], loopIndex2 != 0)) {
            loopIndex2 = *(int *)(key + 0xb0);
            if (loopIndex == 0) {
LAB_00180784:
              changed = 1;
              *(int *)(loopIndex2 + 0x9c) = selectTest;
            }
            else {
              changed = 1;
              loopIndex2 = IRInst__getOperandRecord(loopIndex2,loopIndex);
              *(int *)(loopIndex2 + 0x10) = selectTest;
            }
          }
        }
        else {
          origSelect = *(int *)(PTR_DAT_001e8b8c + sourceKindCode * 4);
          flagBit2Result = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(*(int *)(key + 0xb0) + 0x88) + 8),
                               *(undefined4 *)(key + 0x238));
          if (flagBit2Result == 0) {
            SelectWord__maskUnused(&maskedSelectOut,origSelect,*(undefined4 *)(keyWordPtr + 0x228));
            origSelect = maskedSelectOut;
          }
          selectTest = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),loopIndex);
          if ((origSelect != *(int *)(selectTest + 0x10)) &&
             (loopPtr7 = *(int **)(*(int *)(key + 0x238) + 0x30c),
             loopIndex2 = (**(code **)(*loopPtr7 + 0x104))
                               (loopPtr7,*(undefined4 *)(key + 0xb0),loopIndex,&origSelect,0),
             selectTest = origSelect, loopIndex2 != 0)) {
            loopIndex2 = *(int *)(key + 0xb0);
            if (loopIndex == 0) goto LAB_00180784;
            changed = 1;
            loopIndex2 = IRInst__getOperandRecord(loopIndex2,loopIndex);
            *(int *)(loopIndex2 + 0x10) = selectTest;
          }
        }
      }
    }
    loopPtr7 = *(int **)(key + 0xb0);
    loopIndex = loopIndex + 1;
    keyWordPtr = keyWordPtr + 4;
  } while( true );
}

/* ValueKey__simplifyModifiersAndAddressing @ 0x180830 (2472 bytes) */
int ValueKey__simplifyModifiersAndAddressing(key)
  int key;
{
  int zeroInst;
  int copyIndex;
  int newSourceInst;
  int operandRecordTmp;
  int kindTest;
  int operandNumber;
  int sourceKindTest;
  int keyWordPtr2;
  int testResult;
  int isOpcode8bOr8c;
  int keyWordPtr;
  int optionEnabled;
  undefined4 currentProgram;
  undefined4 copySelectWord2;
  undefined4 copySelectWord;
  uint invertedLanes;
  uint invertedWriteMask;
  undefined4 negatedPass;
  uint firstEnabledSelect;
  uint lanesCovered;
  uint creatorWriteMask;
  int exprSlotPtr;
  int vslot40Result;
  bool moreChannels2;
  bool allConstant;
  bool moreWords;
  int operandRecord2;
  uint vectorFilledCount4;
  uint vectorFilledCount3;
  uint vectorFilledCount2;
  uint vectorFilledCount;
  undefined4 opcode;
  undefined4 arena;
  undefined4 inst1;
  undefined4 operandRef2;
  undefined4 operandRef;
  uint *vector4;
  uint *vector3;
  uint *vector2;
  int newSource;
  int operandIndex;
  bool moreChannels;
  bool absIsNoOp;
  bool negateAbsIsNoOp;
  int loopIndex4;
  float *addressRecord;
  int loopIndex5;
  void *inst;
  int *callResult;
  void *inst2;
  int loopRemaining;
  undefined4 *loopPtr9;
  int *loopPtr7;
  int operandRecord;
  int loopIndex;
  undefined4 changed;
  int loopIndex2;
  int keyWordPtr3;
  uint lastEntryIndex;
  int operandCount;
  undefined4 sourceRegister;
  uint lastEntryIndex2;
  undefined4 definingKey;
  uint lastEntryIndex3;
  int *loopPtr8;
  void *inst3;
  char *loopPtr6;
  uint *vector;
  int loopIndex3;
  double floorValue;
  uint laneMask;
  uint constVecLane0;
  int constVecOrInsts [3];
  longlong roundAsInt64;
  longlong floorAsInt64;
  uint readMaskOut;
  uint writeMaskOut;
  undefined4 clearedLanesOut;
  undefined4 selectWordOut;
  uint writeMaskOut2;
  undefined4 clearedLanesOut2;
  undefined4 selectWordOut2;
  int valueNumberOut4;
  int valueNumberOut3;
  int valueNumberOut2;
  int valueNumberOut1;
  uint maskScratch [3];
  
  if (*(int *)(*(int *)(key + 0x238) + 0x658) <=
      *(int *)(*(int *)(*(int *)(key + 0x238) + 0x6c4) + 0xa8)) {
    return 0;
  }
  loopPtr8 = *(int **)(key + 0xb0);
  changed = 0;
  for (operandIndex = 1; loopIndex4 = (**(code **)(*loopPtr8 + 0x14))(loopPtr8), operandIndex <= loopIndex4;
      operandIndex = operandIndex + 1) {
    loopPtr8 = *(int **)(key + 0xb0);
    if ((loopPtr8[operandIndex * 6 + 0x28] & 2U) != 0) {
      vector = *(uint **)(loopPtr8[operandIndex * 6 + 0x23] + 0x2c);
      vectorFilledCount2 = vector[1];
      lastEntryIndex = vectorFilledCount2 - 1;
      if (lastEntryIndex < *vector) {
        if (vectorFilledCount2 <= lastEntryIndex) {
          _memset(vectorFilledCount2 * 4 + vector[2],0,(lastEntryIndex - vectorFilledCount2) * 4 + 4);
          vector[1] = vectorFilledCount2;
          loopPtr8 = *(int **)(key + 0xb0);
        }
        loopPtr9 = (undefined4 *)(lastEntryIndex * 4 + vector[2]);
      }
      else {
        loopPtr9 = (undefined4 *)Vector__elementRefGrow(vector,lastEntryIndex);
        loopPtr8 = *(int **)(key + 0xb0);
      }
      definingKey = *loopPtr9;
      absIsNoOp = true;
      loopPtr6 = (char *)(operandIndex * 4 + key + 0x224);
      negateAbsIsNoOp = true;
      loopIndex4 = 0;
      do {
        if (*loopPtr6 != '\0') {
          sourceKindTest = IRInst__getOperandRecord(loopPtr8,operandIndex);
          sourceKindTest = ValueKey__sourceKindIs4(definingKey,(uint)*(byte *)(loopIndex4 + sourceKindTest + 0x10));
          if (sourceKindTest == 0) {
            sourceKindTest = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),operandIndex);
            sourceKindTest = ValueKey__sourceKindIs1(definingKey,(uint)*(byte *)(loopIndex4 + sourceKindTest + 0x10));
            if ((sourceKindTest == 0) || (!negateAbsIsNoOp)) {
LAB_00180a10:
              loopPtr8 = *(int **)(key + 0xb0);
              goto LAB_00180a14;
            }
            loopPtr8 = *(int **)(key + 0xb0);
            absIsNoOp = false;
          }
          else {
            if (!absIsNoOp) goto LAB_00180a10;
            loopPtr8 = *(int **)(key + 0xb0);
            negateAbsIsNoOp = false;
          }
        }
        moreChannels = loopIndex4 != 3;
        loopPtr6 = loopPtr6 + 1;
        loopIndex4 = loopIndex4 + 1;
      } while (moreChannels);
      if (absIsNoOp) {
        IROperand__setModifierBits(loopPtr8 + operandIndex * 6 + 0x23,2,0);
        loopPtr8 = *(int **)(key + 0xb0);
        changed = 1;
      }
      else if ((negateAbsIsNoOp) && ((loopPtr8[operandIndex * 6 + 0x28] & 1U) != 0)) {
        changed = 1;
        IROperand__setModifierBits(loopPtr8 + operandIndex * 6 + 0x23,2,0);
        IROperand__setModifierBits(operandIndex * 0x18 + *(int *)(key + 0xb0) + 0x8c,1,0);
        loopPtr8 = *(int **)(key + 0xb0);
      }
    }
LAB_00180a14: ;
  }
  optionEnabled = Compiler__isOptionEnabled(*(undefined4 *)(key + 0x238),10);
  if (optionEnabled != 0) {
    loopIndex4 = 0x18;
    keyWordPtr = key;
    for (operandNumber = 1;
        loopIndex5 = (**(code **)(**(int **)(key + 0xb0) + 0x14))(*(int **)(key + 0xb0)),
        operandNumber <= loopIndex5; operandNumber = operandNumber + 1) {
      loopIndex5 = IRInst__operandKindClass(*(undefined4 *)(key + 0xb0),operandNumber);
      if (loopIndex5 == 2) {
        vector2 = *(uint **)(*(int *)(loopIndex4 + *(int *)(key + 0xb0) + 0x8c) + 0x2c);
        vectorFilledCount = vector2[1];
        lastEntryIndex2 = vectorFilledCount - 1;
        if (lastEntryIndex2 < *vector2) {
          if (vectorFilledCount <= lastEntryIndex2) {
            _memset(vectorFilledCount * 4 + vector2[2],0,(lastEntryIndex2 - vectorFilledCount) * 4 + 4);
            vector2[1] = vectorFilledCount;
          }
          loopPtr8 = (int *)(lastEntryIndex2 * 4 + vector2[2]);
        }
        else {
          loopPtr8 = (int *)Vector__elementRefGrow(vector2,lastEntryIndex2);
        }
        loopIndex2 = *loopPtr8;
        loopIndex5 = *(int *)(loopIndex2 + 0x178);
        if (loopIndex5 < 0) {
          addressRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),loopIndex5);
          if (*(int *)(*(int *)(loopIndex2 + 0xb0) + 300) == 0) {
            floorValue = _floor((double)*addressRecord);
            loopIndex5 = (int)floorValue;
            floorAsInt64 = (longlong)loopIndex5;
          }
          else {
            floorValue = _floor((double)*addressRecord + 0.5);
            loopIndex5 = (int)floorValue;
            roundAsInt64 = (longlong)loopIndex5;
          }
          loopIndex2 = IRInst__getDefiningField128(*(undefined4 *)(key + 0xb0),operandNumber);
          loopIndex5 = loopIndex5 + loopIndex2;
          if (*(int *)(*(int *)(*(int *)(key + 0x238) + 0x30c) + 0x2c) <= loopIndex5) {
            loopIndex5 = 0;
          }
          loopIndex2 = *(int *)(key + 0xb0);
          operandRef2 = *(undefined4 *)(*(int *)(*(int *)(key + 0x238) + 0x6c4) + 0x3ac);
          if ((operandNumber < 1) || (loopIndex = IRInst__getOperandSource(loopIndex2,operandNumber), loopIndex == 0)) {
            sourceRegister = *(undefined4 *)(loopIndex4 + loopIndex2 + 0x98);
          }
          else {
            loopIndex2 = IRInst__getOperandSource(loopIndex2,operandNumber);
            sourceRegister = *(undefined4 *)(loopIndex2 + 0x98);
          }
          loopIndex2 = RegKind__flagBit7(sourceRegister);
          if (loopIndex2 == 0) {
            operandRef2 = FUN_00127608(operandRef2,0,loopIndex5,0);
          }
          else {
            operandRef2 = FUN_00127608(operandRef2,2,loopIndex5,0);
          }
          IRInst__setOperandRef(*(undefined4 *)(key + 0xb0),operandNumber,operandRef2);
          VReg__addUse(operandRef2,operandNumber,*(undefined4 *)(key + 0xb0));
          loopIndex5 = VReg__currentDefinition(operandRef2,*(undefined4 *)
                                       (*(int *)(*(uint *)(key + 0x238) + 0x6c4) + 0x3a0),
                               *(uint *)(key + 0x238));
          *(undefined4 *)(keyWordPtr + 0x214) = *(undefined4 *)(loopIndex5 + 0xb0);
        }
      }
      loopIndex4 = loopIndex4 + 0x18;
      keyWordPtr = keyWordPtr + 4;
    }
  }
  loopPtr8 = *(int **)(key + 0xb0);
  if (loopPtr8[0x20] == 0) {
LAB_001818e8:
    if (((loopPtr8[5] & 2U) != 0) || (isOpcode8bOr8c = IRInst__isOpcode8bOr8c(loopPtr8), isOpcode8bOr8c != 0))
    goto LAB_00180cb4;
  }
  else {
    testResult = RegKind__flagBit0(loopPtr8[0x26]);
    if (((testResult == 0) || ((loopPtr8[5] & 2U) != 0)) ||
       (testResult = (**(code **)(*loopPtr8 + 0x50))(loopPtr8), testResult != 0)) {
      loopPtr8 = *(int **)(key + 0xb0);
      goto LAB_001818e8;
    }
    loopPtr8 = *(int **)(key + 0xb0);
LAB_00180cb4:
    keyWordPtr2 = key;
    for (loopIndex4 = 1; operandCount = (**(code **)(*loopPtr8 + 0x14))(loopPtr8), loopIndex4 <= operandCount;
        loopIndex4 = loopIndex4 + 1) {
      vector3 = *(uint **)(*(int *)(loopIndex4 * 0x18 + *(int *)(key + 0xb0) + 0x8c) + 0x2c);
      vectorFilledCount3 = vector3[1];
      lastEntryIndex = vectorFilledCount3 - 1;
      if (lastEntryIndex < *vector3) {
        if (vectorFilledCount3 <= lastEntryIndex) {
          _memset(vectorFilledCount3 * 4 + vector3[2],0,(lastEntryIndex - vectorFilledCount3) * 4 + 4);
          vector3[1] = vectorFilledCount3;
        }
        loopPtr8 = (int *)(lastEntryIndex * 4 + vector3[2]);
      }
      else {
        loopPtr8 = (int *)Vector__elementRefGrow(vector3,lastEntryIndex);
      }
      loopPtr8 = *(int **)(*loopPtr8 + 0xb0);
      kindTest = (**(code **)(*loopPtr8 + 0x74))(loopPtr8);
      if (((kindTest != 0) && (*(int *)(loopPtr8[0x22] + 8) == 0xfb)) &&
         (kindTest = IRInst__operandKindClass(*(undefined4 *)(key + 0xb0),loopIndex4), kindTest == 0)) {
        operandRecordTmp = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),loopIndex4);
        SelectWord__readMask(&readMaskOut,*(undefined4 *)(operandRecordTmp + 0x10));
        laneMask = readMaskOut;
        loopPtr7 = (int *)((int (*)())Inst__findLaneProducer)(loopPtr8,readMaskOut,1,*(undefined4 *)(key + 0x238));
        if (loopPtr7 != (int *)0x0) {
          vslot40Result = (**(code **)(*loopPtr7 + 0x40))(loopPtr7);
          if (vslot40Result == 0) {
            operandRecord2 = IRInst__getOperandRecord(loopPtr7,0);
            WriteMask__fromSelectWord(&writeMaskOut,*(undefined4 *)(operandRecord2 + 0x10));
            creatorWriteMask = writeMaskOut;
            invertedWriteMask = ~writeMaskOut;
            if (((invertedWriteMask << 0x18 | (invertedWriteMask & 0xff00) << 8 | invertedWriteMask >> 8 & 0xff00 | invertedWriteMask >> 0x18) &
                laneMask) == 0) {
              newSourceInst = IRInst__getOperandSource(loopPtr7,1);
              *(int *)(keyWordPtr2 + 0x214) = newSourceInst;
              operandRef = *(undefined4 *)(newSourceInst + 0x8c);
              inst1 = *(undefined4 *)(key + 0xb0);
            }
            else {
              inst = IRInst__create(0x31,*(undefined4 *)(key + 0x238));
              IRInst__setOperandRef(inst,0,loopPtr8[0x23]);
              *(undefined4 *)((int)inst + 0x98) = 0;
              *(undefined4 *)((int)inst + 0x94) = *(undefined4 *)((int)inst + 0x14c);
              newSource = IRInst__getOperandSource(loopPtr7,1);
              IRInst__setOperandRef(inst,1,*(undefined4 *)(newSource + 0x8c));
              IRInst__setOperandSource(inst,1,newSource,0,*(undefined4 *)(key + 0x238));
              invertedLanes = ~(creatorWriteMask & laneMask);
              laneBytes__clearSetLanes(&clearedLanesOut,creatorWriteMask & laneMask);
              *(undefined4 *)((int)inst + 0x9c) = clearedLanesOut;
              FUN_000f370c(&selectWordOut,clearedLanesOut);
              copySelectWord = selectWordOut;
              operandRecord2 = IRInst__getOperandRecord(inst,1);
              *(undefined4 *)(operandRecord2 + 0x10) = copySelectWord;
              copyIndex = 0;
              constVecLane0 = (uint)inst;
              laneMask = (invertedLanes << 0x18 | (invertedLanes & 0xff00) << 8 | invertedLanes >> 8 & 0xff00 |
                         invertedLanes >> 0x18) & laneMask;
              if (laneMask == 0) {
LAB_00181100:
                loopPtr8 = constVecOrInsts + copyIndex + -1;
                loopIndex5 = 0;
                do {
                  loopIndex = *loopPtr8;
                  Block__insertInstBefore(*(undefined4 *)(*(int *)(key + 0xb0) + 0x158),
                               *(int *)(key + 0xb0),loopIndex);
                  FUN_0012306c(*(undefined4 *)(loopIndex + 0x8c),loopIndex);
                  loopIndex2 = IRInst__getOperandSource(loopIndex,1);
                  VReg__addUse(*(undefined4 *)(loopIndex2 + 0x8c),1,loopIndex);
                  arena = *(undefined4 *)(*(int *)(key + 0x238) + 0x378);
                  loopPtr9 = (undefined4 *)Arena__alloc(arena,0x240);
                  *loopPtr9 = arena;
                  loopPtr9 = loopPtr9 + 1;
                  ValueKey__init(loopPtr9,loopIndex,*(undefined4 *)(key + 0x238));
                  loopIndex5 = loopIndex5 + 1;
                  loopPtr8 = loopPtr8 + -1;
                  ValueKey__loadSourceDefinitions(loopPtr9,*(undefined4 *)
                                        (*(int *)(*(int *)(key + 0x238) + 0x6c4) + 0x3a0));
                  ValueKey__fill(loopPtr9);
                  FUN_00174e0c(loopPtr9);
                  FUN_00175b40(loopPtr9);
                  ValueKey__propagateLaneValues(loopPtr9);
                  Block__recordDefinition(*(undefined4 *)(*(int *)(key + 0xb0) + 0x158),
                               *(undefined4 *)(loopIndex + 0x8c),loopPtr9);
                } while (copyIndex + 1 != loopIndex5);
              }
              else {
                loopPtr7 = constVecOrInsts;
                loopIndex5 = 1;
                inst3 = inst;
                do {
                  copyIndex = loopIndex5;
                  callResult = (int *)((int (*)())Inst__findLaneProducer)(loopPtr8,laneMask,0,*(undefined4 *)(key + 0x238));
                  if (callResult == (int *)0x0) goto LAB_00181220;
                  inst2 = IRInst__create(0x31,*(undefined4 *)(key + 0x238));
                  IRInst__setOperandRef(inst2,0,loopPtr8[0x23]);
                  *(undefined4 *)((int)inst2 + 0x98) = 0;
                  *(undefined4 *)((int)inst2 + 0x94) = *(undefined4 *)((int)inst2 + 0x14c);
                  IRInst__appendSource(inst3,*(undefined4 *)((int)inst2 + 0x8c));
                  IRInst__setExtraOperandSource(inst3,inst2,0,*(undefined4 *)(key + 0x238));
                  loopIndex5 = IRInst__getOperandRecord(callResult,0);
                  WriteMask__fromSelectWord(&writeMaskOut2,*(undefined4 *)(loopIndex5 + 0x10));
                  lanesCovered = writeMaskOut2 & laneMask;
                  laneBytes__clearSetLanes(&clearedLanesOut2,lanesCovered);
                  *(undefined4 *)((int)inst2 + 0x9c) = clearedLanesOut2;
                  FUN_000f370c(&selectWordOut2,clearedLanesOut2);
                  copySelectWord2 = selectWordOut2;
                  loopIndex5 = IRInst__getOperandRecord(inst2,1);
                  *(undefined4 *)(loopIndex5 + 0x10) = copySelectWord2;
                  loopIndex5 = (**(code **)(*callResult + 0x40))(callResult);
                  if (loopIndex5 == 0) {
                    loopIndex5 = IRInst__getOperandSource(callResult,1);
                    IRInst__setOperandRef(inst2,1,*(undefined4 *)(loopIndex5 + 0x8c));
                    IRInst__setOperandSource(inst2,1,loopIndex5,0,*(undefined4 *)(key + 0x238));
                  }
                  else {
                    loopIndex5 = *(int *)(*(int *)(key + 0x238) + 0x6c4);
                    loopIndex5 = FUN_00123c08(loopIndex5,*(undefined4 *)(loopIndex5 + 0x3a0),0);
                    loopIndex5 = *(int *)(loopIndex5 + 0xb0);
                    IRInst__setOperandRef(inst2,1,*(undefined4 *)(loopIndex5 + 0x8c));
                    IRInst__setOperandSource(inst2,1,loopIndex5,0,*(undefined4 *)(key + 0x238));
                    laneMask = 0;
                  }
                  lanesCovered = ~lanesCovered;
                  laneMask = (lanesCovered << 0x18 | (lanesCovered & 0xff00) << 8 | lanesCovered >> 8 & 0xff00 |
                             lanesCovered >> 0x18) & laneMask;
                  *loopPtr7 = (int)inst2;
                  loopPtr7 = loopPtr7 + 1;
                  loopIndex5 = copyIndex + 1;
                  inst3 = inst2;
                } while (laneMask != 0);
                if (copyIndex + 1 == 0) goto LAB_00181220;
                if (-1 < copyIndex) goto LAB_00181100;
              }
              *(void **)(keyWordPtr2 + 0x214) = inst;
              operandRef = *(undefined4 *)((int)inst + 0x8c);
              inst1 = *(undefined4 *)(key + 0xb0);
            }
          }
          else {
            zeroInst = *(int *)(*(int *)(key + 0x238) + 0x6c4);
            zeroInst = FUN_00123c08(zeroInst,*(undefined4 *)(zeroInst + 0x3a0),0);
            zeroInst = *(int *)(zeroInst + 0xb0);
            inst1 = *(undefined4 *)(key + 0xb0);
            *(int *)(keyWordPtr2 + 0x214) = zeroInst;
            operandRef = *(undefined4 *)(zeroInst + 0x8c);
          }
          IRInst__setOperandRef(inst1,loopIndex4,operandRef);
          VReg__addUse(operandRef,loopIndex4,*(undefined4 *)(key + 0xb0));
        }
      }
LAB_00181220:
      loopPtr8 = *(int **)(key + 0xb0);
      keyWordPtr2 = keyWordPtr2 + 4;
    }
    loopPtr8 = *(int **)(key + 0xb0);
  }
  if (loopPtr8[0x20] != 0) {
    testResult = RegKind__flagBit0(loopPtr8[0x26]);
    if (((testResult != 0) && ((loopPtr8[5] & 2U) == 0)) &&
       (testResult = (**(code **)(*loopPtr8 + 0x50))(loopPtr8), testResult == 0)) {
      loopPtr8 = *(int **)(key + 0xb0);
      goto code_r0x001812b0;
    }
    loopPtr8 = *(int **)(key + 0xb0);
  }
  if (((loopPtr8[5] & 2U) == 0) && (isOpcode8bOr8c = IRInst__isOpcode8bOr8c(loopPtr8), isOpcode8bOr8c == 0)) {
    return changed;
  }
code_r0x001812b0:
  loopIndex2 = 1;
  exprSlotPtr = key + 0x170;
  loopIndex5 = key + 0x224;
  loopIndex4 = 4;
  keyWordPtr3 = key;
  do {
    loopIndex = (**(code **)(*loopPtr8 + 0x14))(loopPtr8);
    if (loopIndex < loopIndex2) {
      return changed;
    }
    loopPtr8 = *(int **)(key + 0xb0);
    opcode = *(undefined4 *)(loopPtr8[0x22] + 8);
    loopRemaining = FUN_00176564(opcode);
    loopIndex = 0x7ffffffe;
    if (loopRemaining == 0) {
      loopIndex = FUN_00176574(opcode);
      if (loopIndex == 0) {
        loopIndex = OpcodeTraits__flagBit7(opcode,*(undefined4 *)(key + 0x238));
        if (loopIndex == 0) {
          loopIndex = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(*(int *)(key + 0xb0) + 0x88) + 8),
                                *(undefined4 *)(key + 0x238));
          if (loopIndex == 0) {
            ValueKey__commonLaneValue(&valueNumberOut1,key,loopIndex2);
            loopPtr8 = *(int **)(key + 0xb0);
            loopIndex = valueNumberOut1;
          }
          else {
            FUN_001769f4(&valueNumberOut2,key,loopIndex2);
            loopPtr8 = *(int **)(key + 0xb0);
            loopIndex = valueNumberOut2;
          }
        }
        else {
          FUN_00178d78(&valueNumberOut3,key,loopIndex2);
          loopPtr8 = *(int **)(key + 0xb0);
          loopIndex = valueNumberOut3;
        }
      }
      else {
        ValueKey__singleLaneValueNumber(&valueNumberOut4,key,loopIndex2);
        loopPtr8 = *(int **)(key + 0xb0);
        loopIndex = valueNumberOut4;
      }
    }
    if ((loopPtr8[5] & 2U) == 0) {
code_r0x001813e0:
      if (((loopPtr8[loopIndex2 * 6 + 0x26] == 0x33) || (loopPtr8[loopIndex2 * 6 + 0x26] == 0xc)) ||
         (*(int *)(loopIndex5 + 4) == 0)) goto code_r0x001816c0;
      loopPtr6 = (char *)(loopIndex5 + 4);
      constVecOrInsts[2] = 0;
      loopPtr8 = (int *)(exprSlotPtr + 8);
      constVecLane0 = 0;
      allConstant = true;
      constVecOrInsts[0] = 0;
      loopRemaining = 0;
      constVecOrInsts[1] = 0;
      do {
        if (*loopPtr6 != '\0') {
          if (*loopPtr8 < 0) {
            loopPtr9 = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),*loopPtr8);
            *(undefined4 *)((int)constVecOrInsts + loopRemaining + -4) = *loopPtr9;
          }
          else {
            allConstant = false;
          }
        }
        moreWords = loopRemaining != 0xc;
        loopPtr6 = loopPtr6 + 1;
        loopPtr8 = loopPtr8 + 1;
        loopRemaining = loopRemaining + 4;
      } while (moreWords);
      currentProgram = *(undefined4 *)(*(int *)(key + 0x238) + 0x6c4);
      SelectWord__maskUnused(maskScratch,0x10203,*(undefined4 *)(keyWordPtr3 + 0x228));
      laneMask = maskScratch[0];
      if (loopIndex != 0x7ffffffe) {
        loopPtr8 = *(int **)(*(int *)(key + 0x238) + 0x30c);
        loopRemaining = (**(code **)(*loopPtr8 + 0x154))(loopPtr8,currentProgram,&constVecLane0,&laneMask);
        if (loopRemaining == 0) {
          loopIndex3 = 4;
          loopPtr6 = (char *)(loopIndex4 + key + 0x224);
          loopRemaining = 0;
          do {
            if (*loopPtr6 != '\0') {
              *(float *)(loopRemaining + (int)&constVecLane0) = -*(float *)(loopRemaining + (int)&constVecLane0);
            }
            loopPtr6 = loopPtr6 + 1;
            loopRemaining = loopRemaining + 4;
            loopIndex3 = loopIndex3 + -1;
          } while (loopIndex3 != 0);
          goto code_r0x00181590;
        }
code_r0x001815cc:
        negatedPass = 0;
code_r0x001815d0:
        loopPtr8 = *(int **)(key + 0xb0);
        if (loopPtr8[loopIndex2 * 6 + 0x26] != *(int *)(loopRemaining + 0x98)) {
          loopPtr7 = *(int **)(*(int *)(key + 0x238) + 0x30c);
          loopIndex3 = (**(code **)(*loopPtr7 + 0x11c))(loopPtr7,loopPtr8,loopIndex2,loopRemaining,0,negatedPass);
          if (loopIndex3 == 0) goto code_r0x001816bc;
          changed = ValueKey__setOperandFromValueKey(key,loopIndex2,loopRemaining,laneMask,negatedPass,0,
                                *(undefined4 *)(key + 0x238));
          loopIndex3 = 0;
          *(undefined4 *)(keyWordPtr3 + 0x214) = changed;
          loopRemaining = key;
          do {
            operandRecord = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),0);
            if (*(char *)(loopIndex3 + operandRecord + 0x10) == '\x01') {
              *(undefined4 *)(loopRemaining + 0x30) = 0;
            }
            moreChannels2 = loopIndex3 != 3;
            loopRemaining = loopRemaining + 4;
            loopIndex3 = loopIndex3 + 1;
          } while (moreChannels2);
          loopPtr8 = *(int **)(key + 0xb0);
          changed = 1;
        }
        goto code_r0x001816c0;
      }
      if (allConstant) {
        loopPtr8 = *(int **)(*(int *)(key + 0x238) + 0x30c);
        loopRemaining = (**(code **)(*loopPtr8 + 0x154))(loopPtr8,currentProgram,&constVecLane0,&laneMask);
        if (loopRemaining != 0) goto code_r0x001815cc;
        loopIndex3 = 4;
        loopPtr6 = (char *)(loopIndex4 + key + 0x224);
        loopRemaining = 0;
        do {
          if (*loopPtr6 != '\0') {
            *(float *)(loopRemaining + (int)&constVecLane0) = -*(float *)(loopRemaining + (int)&constVecLane0);
          }
          loopPtr6 = loopPtr6 + 1;
          loopRemaining = loopRemaining + 4;
          loopIndex3 = loopIndex3 + -1;
        } while (loopIndex3 != 0);
code_r0x00181590:
        loopPtr8 = *(int **)(*(int *)(key + 0x238) + 0x30c);
        negatedPass = 1;
        loopRemaining = (**(code **)(*loopPtr8 + 0x154))(loopPtr8,currentProgram,&constVecLane0,&laneMask);
        if (loopRemaining != 0) goto code_r0x001815d0;
code_r0x001816bc:
        loopPtr8 = *(int **)(key + 0xb0);
        goto code_r0x001816c0;
      }
      loopPtr8 = *(int **)(key + 0xb0);
    }
    else {
      loopRemaining = (**(code **)(**(int **)(*(int *)(key + 0x238) + 0x30c) + 0xbc))();
      if (loopRemaining != 0) {
        loopPtr8 = *(int **)(key + 0xb0);
        goto code_r0x001813e0;
      }
      loopPtr8 = *(int **)(key + 0xb0);
code_r0x001816c0:
      if (loopIndex != 0x7ffffffe) {
        if (*(int *)(loopPtr8[0x22] + 8) != 0x8e) {
          loopPtr6 = (char *)(loopIndex5 + 4);
          loopRemaining = 4;
          loopIndex = 0;
          do {
            if (*loopPtr6 != '\0') {
              loopRemaining = IRInst__getOperandRecord(loopPtr8,loopIndex2);
              loopPtr8 = *(int **)(key + 0xb0);
              firstEnabledSelect = (uint)*(byte *)(loopIndex + loopRemaining + 0x10);
              goto code_r0x00181700;
            }
            loopIndex = loopIndex + 1;
            loopPtr6 = loopPtr6 + 1;
            loopRemaining = loopRemaining + -1;
          } while (loopRemaining != 0);
          firstEnabledSelect = 0;
code_r0x00181700:
          vector4 = *(uint **)(loopPtr8[loopIndex2 * 6 + 0x23] + 0x2c);
          vectorFilledCount4 = vector4[1];
          lastEntryIndex3 = vectorFilledCount4 - 1;
          if (lastEntryIndex3 < *vector4) {
            if (vectorFilledCount4 <= lastEntryIndex3) {
              _memset(vectorFilledCount4 * 4 + vector4[2],0,(lastEntryIndex3 - vectorFilledCount4) * 4 + 4);
              vector4[1] = vectorFilledCount4;
            }
            loopPtr8 = (int *)(lastEntryIndex3 * 4 + vector4[2]);
          }
          else {
            loopPtr8 = (int *)Vector__elementRefGrow(vector4,lastEntryIndex3);
          }
          loopPtr8 = (int *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),
                                        *(undefined4 *)(firstEnabledSelect * 4 + *loopPtr8 + 0x20));
          loopIndex = *loopPtr8;
        }
        loopPtr8 = (int *)Compiler__valueNumberForExpr(*(undefined4 *)(key + 0x238),loopIndex);
        if (*loopPtr8 == 0) {
          loopPtr8 = *(int **)(key + 0xb0);
          if ((loopPtr8[loopIndex2 * 6 + 0x28] & 2U) != 0) {
            changed = 1;
            IROperand__setModifierBits(loopPtr8 + loopIndex2 * 6 + 0x23,2,0);
            loopPtr8 = *(int **)(key + 0xb0);
          }
          if ((loopPtr8[loopIndex2 * 6 + 0x28] & 1U) != 0) {
            changed = 1;
            IROperand__setModifierBits(loopPtr8 + loopIndex2 * 6 + 0x23,1,0);
            loopPtr8 = *(int **)(key + 0xb0);
          }
        }
        else if (*loopPtr8 < 1) {
          loopPtr8 = *(int **)(key + 0xb0);
          if ((loopPtr8[loopIndex2 * 6 + 0x28] & 2U) != 0) {
            changed = 1;
            IROperand__setModifierBits(loopPtr8 + loopIndex2 * 6 + 0x23,2,0);
            loopIndex = *(int *)(key + 0xb0) + loopIndex2 * 0x18 + 0x80;
            IROperand__setModifierBits(loopIndex + 0xc,1,(*(uint *)(loopIndex + 0x20) ^ 1) & 1);
            loopPtr8 = *(int **)(key + 0xb0);
          }
        }
        else {
          loopPtr8 = *(int **)(key + 0xb0);
          if ((loopPtr8[loopIndex2 * 6 + 0x28] & 2U) != 0) {
            changed = 1;
            IROperand__setModifierBits(loopPtr8 + loopIndex2 * 6 + 0x23,2,0);
            loopPtr8 = *(int **)(key + 0xb0);
          }
        }
      }
    }
    loopIndex2 = loopIndex2 + 1;
    loopIndex4 = loopIndex4 + 4;
    loopIndex5 = loopIndex5 + 4;
    exprSlotPtr = exprSlotPtr + 0x10;
    keyWordPtr3 = keyWordPtr3 + 4;
  } while( true );
}

/* Inst__isFoldableSingleUse @ 0x181928 (140 bytes) */
int Inst__isFoldableSingleUse(param_1, param_2, program)
  int *param_1;
  int param_2;
  undefined4 program;
{
  int hasSingleUse;
  undefined4 uVar2;
  
  hasSingleUse = IRInst__hasSingleUse(param_1,program);
  if ((((hasSingleUse == 0) || (hasSingleUse = (**(code **)(*param_1 + 0x68))(param_1), hasSingleUse != 0)) ||
      ((param_1[5] & 0x200U) != 0)) ||
     ((*(int *)(param_1[0x22] + 8) == 0x8e || (uVar2 = 1, param_1[0x56] != param_2)))) {
    uVar2 = 0;
  }
  return uVar2;
}

/* Inst__compareScheduleSlack @ 0x1819b4 (252 bytes) */
int Inst__compareScheduleSlack(inst, inst2)
  int *inst;
  int *inst2;
{
  int componentsA;
  int componentsB;
  
  if ((((inst[0x20] == 0) || (componentsA = RegKind__flagBit0(inst[0x26]), componentsA == 0)) ||
      ((inst[5] & 2U) != 0)) || (componentsA = (**(code **)(*inst + 0x50))(inst), componentsA != 0)) {
    componentsA = 0;
  }
  else {
    componentsA = IRInst__countWrittenComponents(inst);
  }
  if (((inst2[0x20] == 0) || (componentsB = RegKind__flagBit0(inst2[0x26]), componentsB == 0)) ||
     (((inst2[5] & 2U) != 0 || (componentsB = (**(code **)(*inst2 + 0x50))(inst2), componentsB != 0)))) {
    componentsB = 0;
  }
  else {
    componentsB = IRInst__countWrittenComponents(inst2);
  }
  return inst2[0x54] - componentsB < inst[0x54] - componentsA;
}

/* Pass__recordFlaggedInstructions @ 0x181ab0 (208 bytes) */
int Pass__recordFlaggedInstructions(pass, block, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int *pass;
  int block;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  int nextLink;
  int nextNode;
  undefined4 *allocation;
  int *elementRef;
  int loopIndex;
  int currentNode;
  uint vectorFilledCount;
  undefined4 arenaAt378;
  uint *vector;
  
  nextLink = *(int *)(*(int *)(block + 0x98) + 8);
  if (nextLink != 0) {
    loopIndex = 0;
    currentNode = *(int *)(block + 0x98);
    do {
      nextNode = nextLink;
      if ((*(uint *)(currentNode + 0x14) & 1) != 0) {
        *(int *)(currentNode + 0x150) = loopIndex;
        arenaAt378 = *(undefined4 *)(*pass + 0x378);
        allocation = (undefined4 *)Arena__alloc(arenaAt378,0x1c);
        *allocation = arenaAt378;
        vector = (uint *)pass[7];
        vectorFilledCount = vector[1];
        if (vectorFilledCount < *vector) {
          _memset(vectorFilledCount * 4 + vector[2],0,4);
          elementRef = (int *)(vectorFilledCount * 4 + vector[2]);
          vector[1] = vectorFilledCount + 1;
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(vector,vectorFilledCount);
        }
        *elementRef = (int)(allocation + 1);
        loopIndex = loopIndex + 1;
        nextNode = *(int *)(currentNode + 8);
      }
      nextLink = *(int *)(nextNode + 8);
      currentNode = nextNode;
    } while (*(int *)(nextNode + 8) != 0);
  }
  return;
}

/* RebuildState__computeNodeLevels @ 0x181b80 (896 bytes) */
int RebuildState__computeNodeLevels(rebuildState, block, maxLevelOut, schedCostOut, staleArg5, staleArg6, staleArg7)
  int rebuildState;
  int block;
  int *maxLevelOut;
  undefined4 *schedCostOut;
  undefined4 staleArg5;
  undefined4 staleArg6;
  undefined4 staleArg7;
{
  int newLevel;
  undefined4 *elementRef2;
  int *elementRef;
  uint vectorFilledCount4;
  uint vectorFilledCount3;
  uint vectorFilledCount2;
  uint *vector4;
  uint *vector3;
  uint *vector2;
  int inst2;
  int sourceDef;
  int inst;
  int sourceLevelPlusOne;
  uint vectorFilledCount;
  undefined4 *nodeRec;
  int nodeDepth;
  int *consumerNode;
  int *sourceNode;
  undefined4 schedCost;
  uint nodeSlot;
  int loopIndex;
  uint *vector;
  
  inst = *(int *)(block + 0x98);
  for (loopIndex = *(int *)(*(int *)(block + 0x98) + 8); loopIndex != 0; loopIndex = *(int *)(loopIndex + 8))
  {
    if ((*(uint *)(inst + 0x14) & 1) != 0) {
      vector = *(uint **)(rebuildState + 0x1c);
      nodeSlot = *(uint *)(inst + 0x150);
      if (nodeSlot < *vector) {
        vectorFilledCount = vector[1];
        if (vectorFilledCount <= nodeSlot) {
          _memset(vectorFilledCount * 4 + vector[2],0,(nodeSlot - vectorFilledCount) * 4 + 4);
          vector[1] = nodeSlot + 1;
        }
        nodeRec = (undefined4 *)(nodeSlot * 4 + vector[2]);
      }
      else {
        nodeRec = (undefined4 *)Vector__elementRefGrow(vector,nodeSlot);
      }
      nodeRec = (undefined4 *)*nodeRec;
      *nodeRec = 1;
      nodeRec[1] = 1;
      nodeRec[2] = 0;
      nodeRec[3] = 0;
      nodeRec[4] = 0;
      nodeRec[5] = 1;
      if ((*(int *)(*(int *)(inst + 0x88) + 8) != 0x8e) && (0 < *(int *)(inst + 0x84))) {
        loopIndex = 1;
        do {
          sourceDef = IRInst__getOperandSource(inst,loopIndex);
          if (block == *(int *)(sourceDef + 0x158)) {
            vector2 = *(uint **)(rebuildState + 0x1c);
            nodeSlot = *(uint *)(sourceDef + 0x150);
            if (nodeSlot < *vector2) {
              vectorFilledCount2 = vector2[1];
              if (vectorFilledCount2 <= nodeSlot) {
                _memset(vectorFilledCount2 * 4 + vector2[2],0,(nodeSlot - vectorFilledCount2) * 4 + 4);
                vector2[1] = nodeSlot + 1;
              }
              elementRef = (int *)(nodeSlot * 4 + vector2[2]);
            }
            else {
              elementRef = (int *)Vector__elementRefGrow(vector2,nodeSlot);
            }
            sourceLevelPlusOne = *(int *)(*elementRef + 4) + 1;
            nodeDepth = nodeRec[1];
            if ((int)nodeRec[1] < sourceLevelPlusOne) {
              nodeDepth = sourceLevelPlusOne;
            }
            nodeRec[1] = nodeDepth;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex <= *(int *)(inst + 0x84));
      }
      loopIndex = *(int *)(inst + 8);
    }
    inst = loopIndex;
  }
  *maxLevelOut = 0;
  SchedModel__resetCounters(*(undefined4 *)(rebuildState + 8));
  inst2 = *(int *)(block + 0xa0);
  for (loopIndex = *(int *)(*(int *)(block + 0xa0) + 4); loopIndex != 0; loopIndex = *(int *)(loopIndex + 4))
  {
    if (((*(uint *)(inst2 + 0x14) & 1) != 0) && (*(int *)(*(int *)(inst2 + 0x88) + 8) != 0x8e)) {
      vector3 = *(uint **)(rebuildState + 0x1c);
      nodeSlot = *(uint *)(inst2 + 0x150);
      if (nodeSlot < *vector3) {
        vectorFilledCount3 = vector3[1];
        if (vectorFilledCount3 <= nodeSlot) {
          _memset(vectorFilledCount3 * 4 + vector3[2],0,(nodeSlot - vectorFilledCount3) * 4 + 4);
          vector3[1] = nodeSlot + 1;
        }
        elementRef2 = (undefined4 *)(nodeSlot * 4 + vector3[2]);
      }
      else {
        elementRef2 = (undefined4 *)Vector__elementRefGrow(vector3,nodeSlot);
      }
      consumerNode = (int *)*elementRef2;
      FUN_00172204(*(undefined4 *)(rebuildState + 8),inst2);
      if (0 < *(int *)(inst2 + 0x84)) {
        loopIndex = 1;
        do {
          sourceDef = IRInst__getOperandSource(inst2,loopIndex);
          if (block == *(int *)(sourceDef + 0x158)) {
            vector4 = *(uint **)(rebuildState + 0x1c);
            nodeSlot = *(uint *)(sourceDef + 0x150);
            if (nodeSlot < *vector4) {
              vectorFilledCount4 = vector4[1];
              if (vectorFilledCount4 <= nodeSlot) {
                _memset(vectorFilledCount4 * 4 + vector4[2],0,(nodeSlot - vectorFilledCount4) * 4 + 4);
                vector4[1] = nodeSlot + 1;
              }
              elementRef2 = (undefined4 *)(nodeSlot * 4 + vector4[2]);
            }
            else {
              elementRef2 = (undefined4 *)Vector__elementRefGrow(vector4,nodeSlot);
            }
            sourceNode = (int *)*elementRef2;
            newLevel = *sourceNode;
            if (*sourceNode < *consumerNode + 1) {
              newLevel = *consumerNode + 1;
            }
            sourceNode[4] = loopIndex;
            *sourceNode = newLevel;
            sourceNode[3] = inst2;
            if (newLevel < *maxLevelOut) {
              newLevel = *maxLevelOut;
            }
            *maxLevelOut = newLevel;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex <= *(int *)(inst2 + 0x84));
      }
      loopIndex = *(int *)(inst2 + 4);
    }
    inst2 = loopIndex;
  }
  schedCost = (**(code **)(**(int **)(rebuildState + 8) + 0x5c))(*(int **)(rebuildState + 8));
  *schedCostOut = schedCost;
  return;
}

/* Block__flattenAndRebuildAddMulTree @ 0x181f00 (220 bytes) */
int Block__flattenAndRebuildAddMulTree(compiler, block, inst)
  int *compiler;
  int block;
  int inst;
{
  int lookaheadNode2;
  int nextNode;
  int scaleRemaining;
  int rightNode;
  int firstJoinInst;
  int indexPlusOne;
  int sourceInst;
  undefined4 savedSelectWord;
  undefined4 selectConstC;
  undefined4 selectConstB;
  uint entryIndex;
  uint instSlotIndex;
  uint operandFlags;
  uint worklistSize;
  int lookaheadNode3;
  int moveNode;
  int instOpcode;
  int entryInst;
  int scaleHiLoop;
  int scaleHiTail;
  int scaleLoTail;
  int otherOperand;
  int joinInst;
  int listedInst;
  int operandRecord6;
  int scaleHiPair;
  int scaleLoPair;
  int compilerPtr;
  int prevByteOffset;
  int operandRecord7;
  int useOperandIndex;
  int lookaheadNode;
  int elementByteOffset2;
  int operandRecord5;
  int leftNode;
  int elementByteOffset;
  uint vectorCapacity2;
  uint vectorCapacity;
  undefined4 *allocation2;
  int *elementRef3;
  int isSplat;
  uint source1Flags;
  uint vectorSize6;
  uint vectorSize5;
  uint vectorSize4;
  uint vectorSize3;
  uint vectorFilledCount5;
  uint vectorFilledCount4;
  uint vectorFilledCount3;
  uint vectorSize2;
  uint vectorFilledCount2;
  uint vectorFilledCount;
  int vectorSize1;
  uint vectorSize;
  uint vectorSizeB;
  uint vectorSizeC;
  undefined4 *elementRefB;
  int *elementRef;
  undefined4 inst8;
  undefined4 inst7;
  undefined4 inst6;
  undefined4 inst5;
  undefined4 inst4;
  undefined4 inst3;
  uint negateFlag;
  uint *vector8;
  uint *vector7;
  uint *vector6;
  uint *vector5;
  int *inst2;
  int operandRecord4;
  int inst1;
  int operandRecord1;
  int compilerCtx;
  undefined4 allocation;
  undefined4 sourceDef;
  int newInst2;
  int operandRecord;
  int operandRecord2;
  int operandRecord3;
  int newInst;
  undefined4 arenaAt378;
  bool moreOperands;
  uint pairLoopIndex;
  int operandByteOffset;
  int modifierLoopIndex;
  undefined4 *vectorAlloc3;
  undefined4 *vectorAlloc;
  undefined4 *vectorAlloc2;
  int *lastElementRef;
  uint lane2Select;
  int entryOrdinal;
  undefined4 *elementRef4;
  int *elementRef2;
  int operandPtr;
  uint prevIndex;
  int currentInst;
  uint *vector;
  uint *vector2;
  uint *vector3;
  int operandSlot;
  int scaleLoLoop;
  undefined4 selectConstA;
  uint lastIndex;
  uint *vector4;
  uint *operandFlagsPtr;
  int operandIndex;
  uint lane1Select;
  undefined1 chainList [8];
  int listNode;
  uint laneSelect3;
  uint laneSelect2;
  uint laneSelect1;
  undefined4 opcode;
  
  arenaAt378 = *(undefined4 *)(*compiler + 0x378);
  vectorAlloc3 = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  vector = vectorAlloc3 + 1;
  *vectorAlloc3 = arenaAt378;
  vectorAlloc3[1] = 2;
  vectorAlloc3[4] = arenaAt378;
  vectorAlloc3[2] = 0;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc3[3] = allocation;
  arenaAt378 = *(undefined4 *)(*compiler + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  vector3 = vectorAlloc + 1;
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  arenaAt378 = *(undefined4 *)(*compiler + 0x378);
  vectorAlloc2 = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  vector2 = vectorAlloc2 + 1;
  *vectorAlloc2 = arenaAt378;
  vectorAlloc2[1] = 2;
  vectorAlloc2[2] = 0;
  vectorAlloc2[4] = arenaAt378;
  allocation = Arena__alloc(arenaAt378,8);
  vectorSize2 = vectorAlloc3[2];
  worklistSize = *vector;
  vectorAlloc2[3] = allocation;
  if (vectorSize2 < worklistSize) {
    _memset((void *)(vectorSize2 * 4 + vectorAlloc3[3]),0,4);
    elementRef3 = (int *)(vectorSize2 * 4 + vectorAlloc3[3]);
    vectorAlloc3[2] = vectorSize2 + 1;
  }
  else {
    elementRef3 = (int *)Vector__elementRefGrow(vector,vectorSize2);
  }
  *elementRef3 = inst;
  while (worklistSize = vectorAlloc3[2], worklistSize != 0) {
    lastElementRef = (int *)0x0;
    if (worklistSize - 1 < worklistSize) {
      lastElementRef = (int *)((worklistSize - 1) * 4 + vectorAlloc3[3]);
    }
    currentInst = *lastElementRef;
    operandSlot = 1;
    Vector__removeAt(vector,worklistSize - 1);
    operandFlagsPtr = (uint *)(currentInst + 0xb8);
    operandByteOffset = 0x18;
    do {
      sourceInst = IRInst__getOperandSource(currentInst,operandSlot);
      if (block == *(int *)(sourceInst + 0x158)) {
        vector4 = (uint *)compiler[7];
        worklistSize = *(uint *)(sourceInst + 0x150);
        if (worklistSize < *vector4) {
          vectorFilledCount3 = vector4[1];
          if (vectorFilledCount3 <= worklistSize) {
            _memset((void *)(vectorFilledCount3 * 4 + vector4[2]),0,(worklistSize - vectorFilledCount3) * 4 + 4);
            vector4[1] = worklistSize + 1;
          }
          elementRef3 = (int *)(worklistSize * 4 + vector4[2]);
        }
        else {
          elementRef3 = (int *)Vector__elementRefGrow(vector4,worklistSize);
        }
        if (*(int *)(*elementRef3 + 0x14) == 0) {
          if (((*operandFlagsPtr & 2) != 0) && (*(int *)(*(int *)(sourceInst + 0x88) + 8) == 0x13)) {
            modifierLoopIndex = 1;
            operandPtr = sourceInst + 0x98;
            do {
              IROperand__setModifierBits(operandPtr + 0xc,2,1);
              if ((*(uint *)(operandPtr + 0x20) & 1) != 0) {
                IROperand__setModifierBits(operandPtr + 0xc,1,0);
              }
              moreOperands = modifierLoopIndex != 2;
              operandPtr = operandPtr + 0x18;
              modifierLoopIndex = modifierLoopIndex + 1;
            } while (moreOperands);
            IROperand__setModifierBits(operandByteOffset + currentInst + 0x8c,2,0);
          }
          operandFlags = *(uint *)(operandByteOffset + currentInst + 0xa0);
          if ((((operandFlags & 1) != 0) && ((operandFlags & 2) == 0)) &&
             (*(int *)(*(int *)(sourceInst + 0x88) + 8) == 0x12)) {
            modifierLoopIndex = 1;
            operandPtr = sourceInst + 0x98;
            do {
              IROperand__setModifierBits(operandPtr + 0xc,1,*(uint *)(operandPtr + 0x20) & 1 ^ 1);
              moreOperands = modifierLoopIndex != 2;
              operandPtr = operandPtr + 0x18;
              modifierLoopIndex = modifierLoopIndex + 1;
            } while (moreOperands);
            IROperand__setModifierBits(operandByteOffset + currentInst + 0x8c,1,0);
          }
          worklistSize = vectorAlloc3[2];
          if (worklistSize < *vector) {
            _memset((void *)(worklistSize * 4 + vectorAlloc3[3]),0,4);
            elementRef3 = (int *)(worklistSize * 4 + vectorAlloc3[3]);
            vectorAlloc3[2] = worklistSize + 1;
          }
          else {
            elementRef3 = (int *)Vector__elementRefGrow(vector,worklistSize);
          }
          *elementRef3 = sourceInst;
        }
      }
      moreOperands = operandSlot != 2;
      operandByteOffset = operandByteOffset + 0x18;
      operandFlagsPtr = operandFlagsPtr + 6;
      operandSlot = operandSlot + 1;
    } while (moreOperands);
    operandRecord = IRInst__getOperandRecord(currentInst,1);
    isSplat = SelectWord__isSplat(*(undefined4 *)(operandRecord + 0x10));
    if (isSplat != 0) {
      operandRecord = IRInst__getOperandRecord(currentInst,2);
      SelectWord__isSplat(*(undefined4 *)(operandRecord + 0x10));
    }
    operandRecord = IRInst__getOperandRecord(currentInst,1);
    isSplat = SelectWord__isSplat(*(undefined4 *)(operandRecord + 0x10));
    if (isSplat == 0) {
      operandRecord = IRInst__getOperandRecord(currentInst,2);
      isSplat = SelectWord__isSplat(*(undefined4 *)(operandRecord + 0x10));
      if (isSplat != 0) {
        vectorSize = vectorAlloc[2];
        if (vectorSize < *vector3) {
          _memset((void *)(vectorSize * 4 + vectorAlloc[3]),0,4);
          elementRef3 = (int *)(vectorSize * 4 + vectorAlloc[3]);
          vectorAlloc[2] = vectorSize + 1;
        }
        else {
          elementRef3 = (int *)Vector__elementRefGrow(vector3,vectorSize);
        }
        *elementRef3 = currentInst;
        worklistSize = vectorAlloc2[2];
        if (worklistSize < *vector2) {
          _memset((void *)(worklistSize * 4 + vectorAlloc2[3]),0,4);
          elementRef4 = (undefined4 *)(worklistSize * 4 + vectorAlloc2[3]);
          vectorAlloc2[2] = worklistSize + 1;
        }
        else {
          elementRef4 = (undefined4 *)Vector__elementRefGrow(vector2,worklistSize);
        }
        *elementRef4 = 2;
      }
    }
    else {
      vectorSize = vectorAlloc[2];
      if (vectorSize < *vector3) {
        _memset((void *)(vectorSize * 4 + vectorAlloc[3]),0,4);
        elementRef3 = (int *)(vectorSize * 4 + vectorAlloc[3]);
        vectorAlloc[2] = vectorSize + 1;
      }
      else {
        elementRef3 = (int *)Vector__elementRefGrow(vector3,vectorSize);
      }
      *elementRef3 = currentInst;
      worklistSize = vectorAlloc2[2];
      if (worklistSize < *vector2) {
        _memset((void *)(worklistSize * 4 + vectorAlloc2[3]),0,4);
        elementRef4 = (undefined4 *)(worklistSize * 4 + vectorAlloc2[3]);
        vectorAlloc2[2] = worklistSize + 1;
      }
      else {
        elementRef4 = (undefined4 *)Vector__elementRefGrow(vector2,worklistSize);
      }
      *elementRef4 = 1;
    }
  }
  instOpcode = *(int *)(*(int *)(inst + 0x88) + 8);
  if ((instOpcode == 0x13) || (instOpcode == 0x14)) {
    opcode = 0x13;
  }
  else {
    opcode = 0x12;
    if (instOpcode != 0x12) {
      opcode = 0;
    }
  }
  DListNode__init(chainList);
  vectorSize1 = vectorAlloc[2];
  lastIndex = vectorSize1 - 1;
  pairLoopIndex = lastIndex;
  if ((int)lastIndex < 1) {
    scaleRemaining = 0;
  }
  else {
    elementByteOffset = lastIndex * 4;
    prevByteOffset = elementByteOffset + -4;
    scaleRemaining = 0;
    indexPlusOne = vectorSize1;
    do {
      newInst = IRInst__create(opcode,*compiler);
      selectConstA = DAT_001b0210;
      *(undefined4 *)(newInst + 0x94) = *(undefined4 *)(newInst + 0x14c);
      prevIndex = pairLoopIndex - 1;
      *(undefined4 *)(newInst + 0x98) = 0;
      *(undefined4 *)(newInst + 0x9c) = selectConstA;
      vectorCapacity2 = *vector3;
      if (prevIndex < vectorCapacity2) {
        vectorSize3 = vectorAlloc[2];
        if (vectorSize3 <= prevIndex) {
          _memset((void *)(vectorSize3 * 4 + vectorAlloc[3]),0,(prevIndex - vectorSize3) * 4 + 4);
          vectorCapacity2 = *vector3;
          vectorAlloc[2] = pairLoopIndex;
        }
        elementRef = (int *)(prevByteOffset + vectorAlloc[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector3,prevIndex);
        vectorCapacity2 = *vector3;
      }
      if (inst != *elementRef) {
        if (prevIndex < vectorCapacity2) {
          vectorSize4 = vectorAlloc[2];
          if (vectorSize4 <= prevIndex) {
            _memset((void *)(vectorSize4 * 4 + vectorAlloc[3]),0,(prevIndex - vectorSize4) * 4 + 4);
            vectorCapacity2 = *vector3;
            vectorAlloc[2] = pairLoopIndex;
          }
          elementRef = (int *)(prevByteOffset + vectorAlloc[3]);
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(vector3,prevIndex);
          vectorCapacity2 = *vector3;
        }
        scaleRemaining = scaleRemaining + *(int *)(*elementRef + 0x124);
      }
      if (pairLoopIndex < vectorCapacity2) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= pairLoopIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = indexPlusOne;
        }
        elementRef = (int *)(elementByteOffset + vectorAlloc[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector3,pairLoopIndex);
      }
      if (inst != *elementRef) {
        if (pairLoopIndex < *vector3) {
          vectorSizeB = vectorAlloc[2];
          if (vectorSizeB <= pairLoopIndex) {
            _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
            vectorAlloc[2] = indexPlusOne;
          }
          elementRef = (int *)(elementByteOffset + vectorAlloc[3]);
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(vector3,pairLoopIndex);
        }
        scaleRemaining = scaleRemaining + *(int *)(*elementRef + 0x124);
      }
      if (scaleRemaining != 0) {
        scaleLoLoop = *(int *)(*(int *)(*compiler + 0x30c) + 0x58);
        if (scaleRemaining < scaleLoLoop) {
          *(int *)(newInst + 0x124) = scaleLoLoop;
          scaleRemaining = scaleRemaining - *(int *)(*(int *)(*compiler + 0x30c) + 0x58);
        }
        else {
          scaleHiLoop = *(int *)(*(int *)(*compiler + 0x30c) + 0x5c);
          if (scaleHiLoop < scaleRemaining) {
            *(int *)(newInst + 0x124) = scaleHiLoop;
            scaleRemaining = scaleRemaining - *(int *)(*(int *)(*compiler + 0x30c) + 0x5c);
          }
          else {
            *(int *)(newInst + 0x124) = scaleRemaining;
            scaleRemaining = 0;
          }
        }
      }
      if (prevIndex < *vector3) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = pairLoopIndex;
        }
        elementRefB = (undefined4 *)(prevByteOffset + vectorAlloc[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector3,prevIndex);
      }
      inst3 = *elementRefB;
      if (prevIndex < *vector2) {
        vectorSizeB = vectorAlloc2[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc2[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc2[2] = pairLoopIndex;
        }
        elementRefB = (undefined4 *)(prevByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector2,prevIndex);
      }
      sourceDef = IRInst__getOperandSource(inst3,*elementRefB);
      IRInst__setOperandSource(newInst,1,sourceDef,0,*compiler);
      if (pairLoopIndex < *vector3) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= pairLoopIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = indexPlusOne;
        }
        elementRefB = (undefined4 *)(elementByteOffset + vectorAlloc[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector3,pairLoopIndex);
      }
      inst4 = *elementRefB;
      if (pairLoopIndex < *vector2) {
        vectorSizeB = vectorAlloc2[2];
        if (vectorSizeB <= pairLoopIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc2[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
          vectorAlloc2[2] = indexPlusOne;
        }
        elementRefB = (undefined4 *)(elementByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector2,pairLoopIndex);
      }
      sourceDef = IRInst__getOperandSource(inst4,*elementRefB);
      IRInst__setOperandSource(newInst,2,sourceDef,0,*compiler);
      if (prevIndex < *vector3) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = pairLoopIndex;
        }
        elementRefB = (undefined4 *)(prevByteOffset + vectorAlloc[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector3,prevIndex);
      }
      inst5 = *elementRefB;
      if (prevIndex < *vector2) {
        vectorSizeB = vectorAlloc2[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc2[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc2[2] = pairLoopIndex;
        }
        elementRefB = (undefined4 *)(prevByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector2,prevIndex);
      }
      operandRecord2 = IRInst__getOperandRecord(inst5,*elementRefB);
      SelectWord__fillUnusedWithFirstUsed(&laneSelect3,*(undefined4 *)(operandRecord2 + 0x10));
      lane1Select = laneSelect3 & 0xff;
      if (pairLoopIndex < *vector3) {
        vectorSize5 = vectorAlloc[2];
        if (vectorSize5 <= pairLoopIndex) {
          _memset((void *)(vectorSize5 * 4 + vectorAlloc[3]),0,(pairLoopIndex - vectorSize5) * 4 + 4);
          vectorAlloc[2] = indexPlusOne;
        }
        elementRefB = (undefined4 *)(elementByteOffset + vectorAlloc[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector3,pairLoopIndex);
      }
      inst6 = *elementRefB;
      if (pairLoopIndex < *vector2) {
        vectorSize6 = vectorAlloc2[2];
        if (vectorSize6 <= pairLoopIndex) {
          _memset((void *)(vectorSize6 * 4 + vectorAlloc2[3]),0,(pairLoopIndex - vectorSize6) * 4 + 4);
          vectorAlloc2[2] = indexPlusOne;
        }
        elementRefB = (undefined4 *)(elementByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector2,pairLoopIndex);
      }
      operandRecord2 = IRInst__getOperandRecord(inst6,*elementRefB);
      SelectWord__fillUnusedWithFirstUsed(&laneSelect2,*(undefined4 *)(operandRecord2 + 0x10));
      lane2Select = laneSelect2 & 0xff;
      operandRecord2 = IRInst__getOperandRecord(newInst,1);
      *(uint *)(operandRecord2 + 0x10) = lane1Select | 0x4040400;
      operandRecord2 = IRInst__getOperandRecord(newInst,2);
      *(uint *)(operandRecord2 + 0x10) = lane2Select | 0x4040400;
      if (prevIndex < *vector3) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = pairLoopIndex;
        }
        elementRef = (int *)(prevByteOffset + vectorAlloc[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector3,prevIndex);
      }
      entryInst = *elementRef;
      if (prevIndex < *vector2) {
        vectorSizeB = vectorAlloc2[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc2[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc2[2] = pairLoopIndex;
        }
        elementRef = (int *)(prevByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector2,prevIndex);
      }
      IROperand__setModifierBits(newInst + 0xa4,1,*(uint *)(*elementRef * 0x18 + entryInst + 0xa0) & 1);
      if (pairLoopIndex < *vector3) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= pairLoopIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = indexPlusOne;
        }
        elementRef = (int *)(elementByteOffset + vectorAlloc[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector3,pairLoopIndex);
      }
      entryInst = *elementRef;
      if (pairLoopIndex < *vector2) {
        vectorSizeB = vectorAlloc2[2];
        if (vectorSizeB <= pairLoopIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc2[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
          vectorAlloc2[2] = indexPlusOne;
        }
        elementRef = (int *)(elementByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector2,pairLoopIndex);
      }
      IROperand__setModifierBits(newInst + 0xbc,1,*(uint *)(*elementRef * 0x18 + entryInst + 0xa0) & 1);
      if (prevIndex < *vector3) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = pairLoopIndex;
        }
        elementRef = (int *)(prevByteOffset + vectorAlloc[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector3,prevIndex);
      }
      entryInst = *elementRef;
      if (prevIndex < *vector2) {
        vectorSizeB = vectorAlloc2[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc2[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc2[2] = pairLoopIndex;
        }
        elementRef = (int *)(prevByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector2,prevIndex);
      }
      IROperand__setModifierBits(newInst + 0xa4,2,*(uint *)(*elementRef * 0x18 + entryInst + 0xa0) >> 1 & 1);
      if (pairLoopIndex < *vector3) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= pairLoopIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = indexPlusOne;
        }
        elementRef = (int *)(elementByteOffset + vectorAlloc[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector3,pairLoopIndex);
      }
      entryInst = *elementRef;
      if (pairLoopIndex < *vector2) {
        vectorSizeB = vectorAlloc2[2];
        if (vectorSizeB <= pairLoopIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc2[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
          vectorAlloc2[2] = indexPlusOne;
        }
        elementRef = (int *)(elementByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector2,pairLoopIndex);
      }
      IROperand__setModifierBits(newInst + 0xbc,2,*(uint *)(*elementRef * 0x18 + entryInst + 0xa0) >> 1 & 1);
      *(undefined4 *)(newInst + 0x150) = *(undefined4 *)(compiler[7] + 4);
      arenaAt378 = *(undefined4 *)(*compiler + 0x378);
      allocation2 = (undefined4 *)Arena__alloc(arenaAt378,0x1c);
      *allocation2 = arenaAt378;
      vector5 = (uint *)compiler[7];
      vectorFilledCount4 = vector5[1];
      if (vectorFilledCount4 < *vector5) {
        _memset((void *)(vectorFilledCount4 * 4 + vector5[2]),0,4);
        elementRef3 = (int *)(vectorFilledCount4 * 4 + vector5[2]);
        vector5[1] = vectorFilledCount4 + 1;
      }
      else {
        elementRef3 = (int *)Vector__elementRefGrow(vector5,vectorFilledCount4);
      }
      *elementRef3 = (int)(allocation2 + 1);
      DList__pushBack(chainList,newInst);
      pairLoopIndex = pairLoopIndex - 2;
      elementByteOffset = elementByteOffset + -8;
      prevByteOffset = prevByteOffset + -8;
      indexPlusOne = indexPlusOne + -2;
    } while (0 < (int)pairLoopIndex);
  }
  leftNode = listNode;
  if (pairLoopIndex == 0) {
    firstJoinInst = IRInst__create(opcode,*compiler);
    selectConstA = DAT_001b0210;
    *(undefined4 *)(firstJoinInst + 0x98) = 0;
    *(undefined4 *)(firstJoinInst + 0x94) = *(undefined4 *)(firstJoinInst + 0x14c);
    *(undefined4 *)(firstJoinInst + 0x9c) = selectConstA;
    if (*vector3 == 0) {
      elementRef = (int *)Vector__elementRefGrow(vector3,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      elementRef = (int *)vectorAlloc[3];
    }
    if (inst != *elementRef) {
      if (*vector3 == 0) {
        elementRef = (int *)Vector__elementRefGrow(vector3,0);
      }
      else {
        if (vectorAlloc[2] == 0) {
          *(undefined4 *)vectorAlloc[3] = 0;
          vectorAlloc[2] = 1;
        }
        elementRef = (int *)vectorAlloc[3];
      }
      scaleRemaining = scaleRemaining + *(int *)(*elementRef + 0x124);
    }
    if (scaleRemaining == 0) {
      compilerPtr = *compiler;
      scaleRemaining = 0;
    }
    else {
      scaleLoPair = *(int *)(*(int *)(*compiler + 0x30c) + 0x58);
      if (scaleRemaining < scaleLoPair) {
        *(int *)(firstJoinInst + 0x124) = scaleLoPair;
        compilerPtr = *compiler;
        scaleRemaining = scaleRemaining - *(int *)(*(int *)(compilerPtr + 0x30c) + 0x58);
      }
      else {
        scaleHiPair = *(int *)(*(int *)(*compiler + 0x30c) + 0x5c);
        if (scaleHiPair < scaleRemaining) {
          *(int *)(firstJoinInst + 0x124) = scaleHiPair;
          compilerPtr = *compiler;
          scaleRemaining = scaleRemaining - *(int *)(*(int *)(compilerPtr + 0x30c) + 0x5c);
        }
        else {
          *(int *)(firstJoinInst + 0x124) = scaleRemaining;
          scaleRemaining = 0;
          compilerPtr = *compiler;
        }
      }
    }
    IRInst__setOperandSource(firstJoinInst,1,leftNode,0,compilerPtr);
    selectConstB = UNK_001b020c;
    operandRecord6 = IRInst__getOperandRecord(firstJoinInst,1);
    *(undefined4 *)(operandRecord6 + 0x10) = selectConstB;
    if (*vector3 == 0) {
      elementRefB = (undefined4 *)Vector__elementRefGrow(vector3,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      elementRefB = (undefined4 *)vectorAlloc[3];
    }
    inst7 = *elementRefB;
    if (*vector2 == 0) {
      elementRefB = (undefined4 *)Vector__elementRefGrow(vector2,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      elementRefB = (undefined4 *)vectorAlloc2[3];
    }
    sourceDef = IRInst__getOperandSource(inst7,*elementRefB);
    IRInst__setOperandSource(firstJoinInst,2,sourceDef,0,*compiler);
    if (*vector3 == 0) {
      elementRefB = (undefined4 *)Vector__elementRefGrow(vector3,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      elementRefB = (undefined4 *)vectorAlloc[3];
    }
    inst8 = *elementRefB;
    if (*vector2 == 0) {
      elementRefB = (undefined4 *)Vector__elementRefGrow(vector2,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      elementRefB = (undefined4 *)vectorAlloc2[3];
    }
    operandRecord6 = IRInst__getOperandRecord(inst8,*elementRefB);
    SelectWord__fillUnusedWithFirstUsed(&laneSelect1,*(undefined4 *)(operandRecord6 + 0x10));
    operandRecord6 = IRInst__getOperandRecord(firstJoinInst,2);
    *(uint *)(operandRecord6 + 0x10) = laneSelect1 & 0xff | 0x4040400;
    if (*vector3 == 0) {
      elementRef = (int *)Vector__elementRefGrow(vector3,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      elementRef = (int *)vectorAlloc[3];
    }
    listedInst = *elementRef;
    if (*vector2 == 0) {
      elementRef = (int *)Vector__elementRefGrow(vector2,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      elementRef = (int *)vectorAlloc2[3];
    }
    IROperand__setModifierBits(firstJoinInst + 0xbc,1,*(uint *)(*elementRef * 0x18 + listedInst + 0xa0) & 1);
    if (*vector3 == 0) {
      elementRef = (int *)Vector__elementRefGrow(vector3,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      elementRef = (int *)vectorAlloc[3];
    }
    listedInst = *elementRef;
    if (*vector2 == 0) {
      elementRef = (int *)Vector__elementRefGrow(vector2,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      elementRef = (int *)vectorAlloc2[3];
    }
    IROperand__setModifierBits(firstJoinInst + 0xbc,2,*(uint *)(*elementRef * 0x18 + listedInst + 0xa0) >> 1 & 1);
    DList__pushBack(chainList,firstJoinInst);
    *(undefined4 *)(firstJoinInst + 0x150) = *(undefined4 *)(compiler[7] + 4);
    arenaAt378 = *(undefined4 *)(*compiler + 0x378);
    allocation2 = (undefined4 *)Arena__alloc(arenaAt378,0x1c);
    *allocation2 = arenaAt378;
    vector6 = (uint *)compiler[7];
    vectorFilledCount = vector6[1];
    if (vectorFilledCount < *vector6) {
      _memset((void *)(vectorFilledCount * 4 + vector6[2]),0,4);
      elementRef3 = (int *)(vectorFilledCount * 4 + vector6[2]);
      vector6[1] = vectorFilledCount + 1;
    }
    else {
      elementRef3 = (int *)Vector__elementRefGrow(vector6,vectorFilledCount);
    }
    *elementRef3 = (int)(allocation2 + 1);
    leftNode = *(int *)(leftNode + 8);
  }
  while (rightNode = *(int *)(leftNode + 8), *(int *)(rightNode + 8) != 0) {
    joinInst = IRInst__create(opcode,*compiler);
    selectConstA = DAT_001b0210;
    *(undefined4 *)(joinInst + 0x98) = 0;
    *(undefined4 *)(joinInst + 0x94) = *(undefined4 *)(joinInst + 0x14c);
    *(undefined4 *)(joinInst + 0x9c) = selectConstA;
    if (scaleRemaining == 0) {
      compilerCtx = *compiler;
    }
    else {
      scaleLoTail = *(int *)(*(int *)(*compiler + 0x30c) + 0x58);
      if (scaleRemaining < scaleLoTail) {
        *(int *)(joinInst + 0x124) = scaleLoTail;
        compilerCtx = *compiler;
        scaleRemaining = scaleRemaining - *(int *)(*(int *)(compilerCtx + 0x30c) + 0x58);
      }
      else {
        scaleHiTail = *(int *)(*(int *)(*compiler + 0x30c) + 0x5c);
        if (scaleHiTail < scaleRemaining) {
          *(int *)(joinInst + 0x124) = scaleHiTail;
          compilerCtx = *compiler;
          scaleRemaining = scaleRemaining - *(int *)(*(int *)(compilerCtx + 0x30c) + 0x5c);
        }
        else {
          *(int *)(joinInst + 0x124) = scaleRemaining;
          scaleRemaining = 0;
          compilerCtx = *compiler;
        }
      }
    }
    IRInst__setOperandSource(joinInst,1,leftNode,0,compilerCtx);
    IRInst__setOperandSource(joinInst,2,rightNode,0,*compiler);
    selectConstB = UNK_001b020c;
    operandRecord5 = IRInst__getOperandRecord(joinInst,1);
    *(undefined4 *)(operandRecord5 + 0x10) = selectConstB;
    operandRecord5 = IRInst__getOperandRecord(joinInst,2);
    *(undefined4 *)(operandRecord5 + 0x10) = selectConstB;
    DList__pushBack(chainList,joinInst);
    *(undefined4 *)(joinInst + 0x150) = *(undefined4 *)(compiler[7] + 4);
    arenaAt378 = *(undefined4 *)(*compiler + 0x378);
    allocation2 = (undefined4 *)Arena__alloc(arenaAt378,0x1c);
    *allocation2 = arenaAt378;
    vector7 = (uint *)compiler[7];
    vectorFilledCount2 = vector7[1];
    if (vectorFilledCount2 < *vector7) {
      _memset((void *)(vectorFilledCount2 * 4 + vector7[2]),0,4);
      elementRef3 = (int *)(vectorFilledCount2 * 4 + vector7[2]);
      vector7[1] = vectorFilledCount2 + 1;
    }
    else {
      elementRef3 = (int *)Vector__elementRefGrow(vector7,vectorFilledCount2);
    }
    *elementRef3 = (int)(allocation2 + 1);
    leftNode = *(int *)(rightNode + 8);
  }
  if (-1 < (int)lastIndex) {
    elementByteOffset2 = lastIndex * 4;
    entryOrdinal = 0;
    scaleRemaining = vectorSize1;
    do {
      vectorCapacity = *vector3;
      entryIndex = lastIndex - entryOrdinal;
      if (entryIndex < vectorCapacity) {
        vectorSizeC = vectorAlloc[2];
        if (vectorSizeC <= entryIndex) {
          _memset((void *)(vectorSizeC * 4 + vectorAlloc[3]),0,(entryIndex - vectorSizeC) * 4 + 4);
          vectorCapacity = *vector3;
          vectorAlloc[2] = scaleRemaining;
        }
        elementRef = (int *)(elementByteOffset2 + vectorAlloc[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector3,entryIndex);
        vectorCapacity = *vector3;
      }
      if (inst == *elementRef) goto code_r0x001836f0;
      if (entryIndex < vectorCapacity) {
        vectorSize = vectorAlloc[2];
        if (vectorSize <= entryIndex) {
          _memset((void *)(vectorSize * 4 + vectorAlloc[3]),0,(entryIndex - vectorSize) * 4 + 4);
          vectorAlloc[2] = scaleRemaining;
        }
        elementRefB = (undefined4 *)(elementByteOffset2 + vectorAlloc[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector3,entryIndex);
      }
      inst2 = (int *)*elementRefB;
      if (entryIndex < *vector2) {
        vectorSize = vectorAlloc2[2];
        if (vectorSize <= entryIndex) {
          _memset((void *)(vectorSize * 4 + vectorAlloc2[3]),0,(entryIndex - vectorSize) * 4 + 4);
          vectorAlloc2[2] = scaleRemaining;
        }
        elementRef2 = (int *)(elementByteOffset2 + vectorAlloc2[3]);
      }
      else {
        elementRef2 = (int *)Vector__elementRefGrow(vector2,entryIndex);
      }
      otherOperand = (*elementRef2 == 1) + 1;
      IRInst__hasSingleUse(inst2,compiler[1]);
      vector8 = (uint *)compiler[7];
      instSlotIndex = inst2[0x54];
      if (instSlotIndex < *vector8) {
        vectorFilledCount5 = vector8[1];
        if (vectorFilledCount5 <= instSlotIndex) {
          _memset((void *)(vectorFilledCount5 * 4 + vector8[2]),0,(instSlotIndex - vectorFilledCount5) * 4 + 4);
          vector8[1] = instSlotIndex + 1;
        }
        elementRef2 = (int *)(instSlotIndex * 4 + vector8[2]);
      }
      else {
        elementRef2 = (int *)Vector__elementRefGrow(vector8,instSlotIndex);
      }
      operandIndex = *(int *)(*elementRef2 + 0x10);
      inst1 = *(int *)(*elementRef2 + 0xc);
      sourceDef = IRInst__getOperandSource(inst2,otherOperand);
      IRInst__setOperandSource(inst1,operandIndex,sourceDef,0,*compiler);
      operandRecord3 = IRInst__getOperandRecord(inst2,otherOperand);
      savedSelectWord = *(undefined4 *)(operandRecord3 + 0x10);
      operandRecord3 = IRInst__getOperandRecord(inst1,operandIndex);
      *(undefined4 *)(operandRecord3 + 0x10) = savedSelectWord;
      if ((*(uint *)(operandIndex * 0x18 + inst1 + 0xa0) & 1) == 0) {
        negateFlag = inst2[otherOperand * 6 + 0x28] & 1;
      }
      else {
        negateFlag = inst2[otherOperand * 6 + 0x28] & 1U ^ 1;
      }
      operandRecord1 = operandIndex * 0x18 + inst1 + 0x8c;
      IROperand__setModifierBits(operandRecord1,1,negateFlag);
      IROperand__setModifierBits(operandRecord1,2,(uint)inst2[otherOperand * 6 + 0x28] >> 1 & 1);
      (**(code **)(*inst2 + 0xc))(inst2,0,*compiler);
      entryOrdinal = entryOrdinal + 1;
      elementByteOffset2 = elementByteOffset2 + -4;
      scaleRemaining = scaleRemaining + -1;
    } while (entryOrdinal != vectorSize1);
  }
  vectorCapacity = *vector3;
code_r0x001836f0:
  if (vectorCapacity == 0) {
    elementRef = (int *)Vector__elementRefGrow(vector3,0);
  }
  else {
    if (vectorAlloc[2] == 0) {
      *(undefined4 *)vectorAlloc[3] = 0;
      vectorAlloc[2] = 1;
    }
    elementRef = (int *)vectorAlloc[3];
  }
  if (inst == *elementRef) {
    lookaheadNode = *(int *)(listNode + 8);
    moveNode = listNode;
    while (nextNode = lookaheadNode, nextNode != 0) {
      DList__unlink(moveNode);
      Block__insertInstBefore(block,inst,moveNode);
      moveNode = nextNode;
      lookaheadNode = *(int *)(nextNode + 8);
    }
    if (*vector2 == 0) {
      elementRef = (int *)Vector__elementRefGrow(vector2,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      elementRef = (int *)vectorAlloc2[3];
    }
    useOperandIndex = *elementRef;
    IRInst__setOperandSource(inst,useOperandIndex,*(undefined4 *)(inst + 4),0,*compiler);
    selectConstB = UNK_001b020c;
    operandRecord = IRInst__getOperandRecord(inst,useOperandIndex);
    *(undefined4 *)(operandRecord + 0x10) = selectConstB;
    operandRecord4 = useOperandIndex * 0x18 + inst + 0x8c;
    IROperand__setModifierBits(operandRecord4,1,0);
    IROperand__setModifierBits(operandRecord4,2,0);
  }
  else {
    newInst2 = IRInst__create(opcode,*compiler);
    *(undefined4 *)(newInst2 + 0x98) = 0;
    *(undefined4 *)(newInst2 + 0x94) = *(undefined4 *)(newInst2 + 0x14c);
    operandRecord7 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(newInst2 + 0x9c) = *(undefined4 *)(operandRecord7 + 0x10);
    sourceDef = IRInst__getOperandSource(inst,1);
    IRInst__setOperandSource(newInst2,1,sourceDef,0,*compiler);
    sourceDef = IRInst__getOperandSource(inst,2);
    IRInst__setOperandSource(newInst2,2,sourceDef,0,*compiler);
    operandRecord7 = IRInst__getOperandRecord(inst,1);
    savedSelectWord = *(undefined4 *)(operandRecord7 + 0x10);
    operandRecord7 = IRInst__getOperandRecord(newInst2,1);
    *(undefined4 *)(operandRecord7 + 0x10) = savedSelectWord;
    operandRecord7 = IRInst__getOperandRecord(inst,2);
    savedSelectWord = *(undefined4 *)(operandRecord7 + 0x10);
    operandRecord7 = IRInst__getOperandRecord(newInst2,2);
    source1Flags = *(uint *)(inst + 0xb8);
    *(undefined4 *)(operandRecord7 + 0x10) = savedSelectWord;
    IROperand__setModifierBits(newInst2 + 0xa4,1,source1Flags & 1);
    IROperand__setModifierBits(newInst2 + 0xbc,1,*(uint *)(inst + 0xd0) & 1);
    IROperand__setModifierBits(newInst2 + 0xa4,2,*(uint *)(inst + 0xb8) >> 1 & 1);
    IROperand__setModifierBits(newInst2 + 0xbc,2,*(uint *)(inst + 0xd0) >> 1 & 1);
    Block__insertInstBefore(block,inst,newInst2);
    IRInst__setOperandSource(inst,1,newInst2,0,*compiler);
    selectConstC = UNK_001b0208;
    operandRecord = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord + 0x10) = selectConstC;
    IROperand__setModifierBits(inst + 0xa4,1,0);
    IROperand__setModifierBits(inst + 0xa4,2,0);
    lookaheadNode3 = *(int *)(listNode + 8);
    while (lookaheadNode2 = lookaheadNode3, lookaheadNode2 != 0) {
      DList__unlink(listNode);
      Block__insertInstBefore(block,inst,listNode);
      listNode = lookaheadNode2;
      lookaheadNode3 = *(int *)(lookaheadNode2 + 8);
    }
    IRInst__setOperandSource(inst,2,*(undefined4 *)(inst + 4),0,*compiler);
    selectConstB = UNK_001b020c;
    operandRecord = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord + 0x10) = selectConstB;
    IROperand__setModifierBits(inst + 0xbc,1,0);
    IROperand__setModifierBits(inst + 0xbc,2,0);
    IRInst__clearSourceSelectsOfUnwrittenComponents(inst);
  }
  if (vector2 != (uint *)0x0) {
    Arena__free(vectorAlloc2[4],vectorAlloc2[3]);
    Arena__free(*vectorAlloc2,vectorAlloc2);
  }
  if (vector3 != (uint *)0x0) {
    Arena__free(vectorAlloc[4],vectorAlloc[3]);
    Arena__free(*vectorAlloc,vectorAlloc);
  }
  if (vector != (uint *)0x0) {
    Arena__free(vectorAlloc3[4],vectorAlloc3[3]);
    Arena__free(*vectorAlloc3,vectorAlloc3);
  }
  return 1;
}

/* FUN_00183ac8 @ 0x183ac8 (212 bytes) */
int FUN_00183ac8(param_1)
  int param_1;
{
  uint vectorFilledCount;
  int *elementRef;
  int iVar3;
  uint vectorFilledCount2;
  uint loopIndex;
  uint *vector;
  
  loopIndex = 0;
  vector = *(uint **)(param_1 + 0x1c);
  vectorFilledCount2 = vector[1];
  if (0 < (int)vectorFilledCount2) {
    while( true ) {
      if (loopIndex < *vector) {
        vectorFilledCount = vector[1];
        if (vectorFilledCount <= loopIndex) {
          _memset(vectorFilledCount * 4 + vector[2],0,(loopIndex - vectorFilledCount) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        elementRef = (int *)(loopIndex * 4 + vector[2]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector,loopIndex);
      }
      loopIndex = loopIndex + 1;
      iVar3 = *elementRef;
      if (iVar3 != 0) {
        Arena__free(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
      }
      if (vectorFilledCount2 == loopIndex) break;
      vector = *(uint **)(param_1 + 0x1c);
    }
    vector = *(uint **)(param_1 + 0x1c);
  }
  vector[1] = 0;
  return;
}

/* Block__rebuildAddMulTreesWhereProfitable @ 0x183b9c (1152 bytes) */
int Block__rebuildAddMulTreesWhereProfitable(rebuildState, block, staleArg3, staleArg4, staleArg5, staleArg6, opcodeInfo)
  int rebuildState;
  int block;
  undefined4 staleArg3;
  undefined4 staleArg4;
  undefined4 staleArg5;
  undefined4 staleArg6;
  int opcodeInfo;
{
  int producerNode;
  int opcode;
  int nextNode;
  uint vectorFilledCount3;
  uint vectorFilledCount2;
  uint *vector3;
  uint *vector2;
  int sourceDef2;
  int sourceDef;
  int nodeRec;
  uint vectorFilledCount;
  int *elementRef;
  int curNode;
  int callResult;
  int opcodeKind;
  int inst;
  uint nodeSlot;
  uint *vector;
  int costLow;
  int costHigh [8];
  
  ((int (*)())Pass__recordFlaggedInstructions)(rebuildState,block,staleArg3,staleArg4,staleArg5,staleArg6,opcodeInfo);
LAB_00183bcc:
  ((int (*)())RebuildState__computeNodeLevels)(rebuildState,block,&costLow,costHigh,staleArg5,staleArg6,opcodeInfo);
  if ((costLow < costHigh[0]) &&
     (nodeRec = *(int *)(rebuildState + 8),
     *(int *)(nodeRec + 0x14) < *(int *)(nodeRec + 0xc) - *(int *)(nodeRec + 0x10))) {
    nextNode = *(int *)(*(int *)(block + 0x98) + 8);
    inst = *(int *)(block + 0x98);
    if (nextNode != 0) {
      do {
        curNode = nextNode;
        if ((*(uint *)(inst + 0x14) & 1) != 0) {
          opcodeInfo = *(int *)(inst + 0x88);
          opcode = *(int *)(opcodeInfo + 8);
          if ((opcode == 0x13) || (opcode == 0x14)) {
            opcodeKind = 0x13;
          }
          else {
            opcodeKind = 0x12;
            if (opcode != 0x12) goto LAB_00183fe8;
          }
          vector = *(uint **)(rebuildState + 0x1c);
          nodeSlot = *(uint *)(inst + 0x150);
          if (nodeSlot < *vector) {
            vectorFilledCount = vector[1];
            if (vectorFilledCount <= nodeSlot) {
              _memset(vectorFilledCount * 4 + vector[2],0,(nodeSlot - vectorFilledCount) * 4 + 4);
              vector[1] = nodeSlot + 1;
              opcodeInfo = *(int *)(inst + 0x88);
            }
            elementRef = (int *)(nodeSlot * 4 + vector[2]);
          }
          else {
            elementRef = (int *)Vector__elementRefGrow(vector,nodeSlot);
            opcodeInfo = *(int *)(inst + 0x88);
          }
          nodeRec = *elementRef;
          if ((((((opcodeKind == *(int *)(opcodeInfo + 8)) && (*(int *)(inst + 0x120) == 0)) &&
                ((*(uint *)(inst + 0x14) & 0x200) == 0)) &&
               (((opcodeKind != 0x12 || (*(int *)(inst + 0x124) == 0)) &&
                ((curNode = IRInst__getOperandRecord(inst,0), *(int *)(curNode + 0x10) != DAT_001b021c &&
                 ((curNode = IRInst__getOperandRecord(inst,0), *(int *)(curNode + 0x10) != DAT_001b0218 &&
                  (curNode = IRInst__getOperandRecord(inst,0), *(int *)(curNode + 0x10) != DAT_001b0214)))))))) &&
              (curNode = IRInst__getOperandRecord(inst,0), *(int *)(curNode + 0x10) != DAT_001b0210)) &&
             ((((curNode = IRInst__hasSingleUse(inst,*(undefined4 *)(rebuildState + 4)), curNode != 0 &&
                (curNode = *(int *)(nodeRec + 0xc), curNode != 0)) &&
               (opcodeKind == *(int *)(*(int *)(curNode + 0x88) + 8))) &&
              ((curNode = IRInst__isSourceSelectIdentity(curNode,*(undefined4 *)(nodeRec + 0x10)), curNode != 0 &&
               ((opcodeKind != 0x12 ||
                (opcodeInfo = *(int *)(nodeRec + 0xc),
                (*(uint *)(*(int *)(nodeRec + 0x10) * 0x18 + opcodeInfo + 0xa0) & 2) == 0)))))))) {
            *(undefined4 *)(nodeRec + 0x14) = 0;
          }
          sourceDef = IRInst__getOperandSource(inst,1);
          sourceDef2 = IRInst__getOperandSource(inst,2);
          callResult = IRInst__getOperandRecord(inst,1);
          callResult = SelectWord__isSplat(*(undefined4 *)(callResult + 0x10));
          if (callResult == 0) {
LAB_00183e40:
            callResult = IRInst__getOperandRecord(inst,1);
            callResult = SelectWord__isSplat(*(undefined4 *)(callResult + 0x10));
            if (callResult == 0) {
              callResult = IRInst__getOperandRecord(inst,2);
              callResult = SelectWord__isSplat(*(undefined4 *)(callResult + 0x10));
              if (callResult != 0) goto LAB_00183e78;
            }
          }
          else {
            callResult = IRInst__getOperandRecord(inst,2);
            callResult = SelectWord__isSplat(*(undefined4 *)(callResult + 0x10));
            if (callResult != 0) goto LAB_00183e40;
LAB_00183e78:
            *(int *)(nodeRec + 8) = *(int *)(nodeRec + 8) + 1;
          }
          if (block == *(int *)(sourceDef + 0x158)) {
            vector2 = *(uint **)(rebuildState + 0x1c);
            nodeSlot = *(uint *)(sourceDef + 0x150);
            if (nodeSlot < *vector2) {
              vectorFilledCount2 = vector2[1];
              if (vectorFilledCount2 <= nodeSlot) {
                _memset(vectorFilledCount2 * 4 + vector2[2],0,(nodeSlot - vectorFilledCount2) * 4 + 4);
                vector2[1] = nodeSlot + 1;
              }
              elementRef = (int *)(nodeSlot * 4 + vector2[2]);
            }
            else {
              elementRef = (int *)Vector__elementRefGrow(vector2,nodeSlot);
            }
            producerNode = *elementRef;
            if ((producerNode != 0) && (*(int *)(producerNode + 0x14) == 0)) {
              *(int *)(nodeRec + 8) = *(int *)(nodeRec + 8) + *(int *)(producerNode + 8);
            }
          }
          if (block == *(int *)(sourceDef2 + 0x158)) {
            vector3 = *(uint **)(rebuildState + 0x1c);
            nodeSlot = *(uint *)(sourceDef2 + 0x150);
            if (nodeSlot < *vector3) {
              vectorFilledCount3 = vector3[1];
              if (vectorFilledCount3 <= nodeSlot) {
                _memset(vectorFilledCount3 * 4 + vector3[2],0,(nodeSlot - vectorFilledCount3) * 4 + 4);
                vector3[1] = nodeSlot + 1;
              }
              elementRef = (int *)(nodeSlot * 4 + vector3[2]);
            }
            else {
              elementRef = (int *)Vector__elementRefGrow(vector3,nodeSlot);
            }
            producerNode = *elementRef;
            if ((producerNode != 0) && (*(int *)(producerNode + 0x14) == 0)) {
              *(int *)(nodeRec + 8) = *(int *)(nodeRec + 8) + *(int *)(producerNode + 8);
            }
          }
          if (((*(int *)(nodeRec + 0x14) != 0) && (1 < *(int *)(nodeRec + 8))) &&
             (nodeRec = ((int (*)())Block__flattenAndRebuildAddMulTree)(rebuildState,block,inst), nodeRec != 0)) goto LAB_00183bcc;
          curNode = *(int *)(inst + 8);
        }
LAB_00183fe8:
        nextNode = *(int *)(curNode + 8);
        inst = curNode;
        if (*(int *)(curNode + 8) == 0) break;
      } while( true );
    }
  }
  return ((int (*)())FUN_00183ac8)(rebuildState);
}

/* pass_height_reduction @ 0x18401c (144 bytes) */
int pass_height_reduction(rebuildState, program, staleArg3, staleArg4, staleArg5, staleArg6, staleArg7)
  int *rebuildState;
  int program;
  undefined4 staleArg3;
  undefined4 staleArg4;
  undefined4 staleArg5;
  undefined4 staleArg6;
  undefined4 staleArg7;
{
  int instVector;
  int nextPassNode;
  int nodeVector;
  int blockNode;
  int vectorByteOffset;
  int resourceModel;
  int listCount;
  undefined4 arenaAt378;
  int nextBlockNode;
  int inst;
  int compiler;
  undefined4 *vectorAlloc;
  char *nextPassName;
  char *passName;
  undefined4 allocation;
  int *passListNode;
  uint loopIndex;
  
  rebuildState[1] = program;
  compiler = *(int *)(program + 8);
  *rebuildState = compiler;
  resourceModel = Compiler__getResourceModel(compiler);
  rebuildState[2] = resourceModel;
  arenaAt378 = *(undefined4 *)(*rebuildState + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  vectorAlloc[1] = 2;
  *vectorAlloc = arenaAt378;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaAt378;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  rebuildState[7] = (int)(vectorAlloc + 1);
  blockNode = *(int *)(rebuildState[1] + 900);
  nextBlockNode = *(int *)(blockNode + 8);
  while (nextBlockNode != 0) {
    listCount = DList__count(blockNode + 0x90);
    if (2 < listCount) {
      ((int (*)())Block__rebuildAddMulTreesWhereProfitable)(rebuildState,blockNode,staleArg3,staleArg4,staleArg5,staleArg6,staleArg7);
    }
    blockNode = *(int *)(blockNode + 8);
    nextBlockNode = *(int *)(blockNode + 8);
  }
  nodeVector = rebuildState[7];
  if (nodeVector != 0) {
    Arena__free(*(undefined4 *)(nodeVector + 0xc),*(undefined4 *)(nodeVector + 8));
    Arena__free(*(undefined4 *)(nodeVector + -4),nodeVector + -4);
  }
  passName = "height_reduction";
  passListNode = *(int **)(program + 900);
  nextPassNode = passListNode[2];
  while (nextPassNode != 0) {
    (**(code **)(*passListNode + 0x48))(passListNode,passName);
    passListNode = (int *)passListNode[2];
    passName = nextPassName;
    nextPassNode = passListNode[2];
  }
  instVector = *(int *)(program + 0x3c4);
  vectorByteOffset = 0;
  for (loopIndex = 1; loopIndex <= *(uint *)(instVector + 4); loopIndex = loopIndex + 1) {
    inst = *(int *)(*(int *)(instVector + 8) + vectorByteOffset);
    if ((*(uint *)(inst + 0x14) & 1) != 0) {
      IRInst__getOperandRecord(inst,0);
      instVector = *(int *)(program + 0x3c4);
    }
    vectorByteOffset = vectorByteOffset + 4;
  }
  return 1;
}

/* FUN_0018413c @ 0x18413c (224 bytes) */
int FUN_0018413c(compilerRef, passArg, block, beforeInst)
  int *compilerRef;
  undefined4 passArg;
  undefined4 block;
  int *beforeInst;
{
  uint operandCount;
  uint countStackTopIndex;
  uint vectorCapacity;
  undefined4 *elementRef;
  uint vectorSize8;
  uint vectorSize7;
  uint vectorSize6;
  uint vectorSize4;
  uint vectorSize3;
  uint vectorSize2;
  uint vectorSize;
  int *inst;
  int operandIndex;
  undefined4 allocation;
  undefined4 sourceDef;
  undefined4 arenaAt378;
  uint stackSize;
  int *vectorAlloc2;
  undefined4 *vectorAlloc;
  undefined4 *vectorAlloc3;
  undefined4 *stackTopRef;
  uint vectorSize5;
  int *walkInst;
  uint *vector2;
  uint *vector3;
  uint *vector;
  int loopIndex;
  undefined4 sourceInstEntry;
  int neededCount;
  int *countStackTopRef;
  uint loopIndex2;
  
  loopIndex = *(int *)(*compilerRef + 0x378);
  vectorAlloc2 = (int *)Arena__alloc(loopIndex,0x14);
  vector2 = (uint *)(vectorAlloc2 + 1);
  *vectorAlloc2 = loopIndex;
  vectorAlloc2[1] = 2;
  vectorAlloc2[4] = loopIndex;
  vectorAlloc2[2] = 0;
  loopIndex = Arena__alloc(loopIndex,8);
  vectorAlloc2[3] = loopIndex;
  arenaAt378 = *(undefined4 *)(*compilerRef + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  vector = vectorAlloc + 1;
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  arenaAt378 = *(undefined4 *)(*compilerRef + 0x378);
  vectorAlloc3 = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  vector3 = vectorAlloc3 + 1;
  *vectorAlloc3 = arenaAt378;
  vectorAlloc3[1] = 2;
  vectorAlloc3[2] = 0;
  vectorAlloc3[4] = arenaAt378;
  allocation = Arena__alloc(arenaAt378,8);
  loopIndex2 = vectorAlloc2[2];
  vectorCapacity = *vector2;
  vectorAlloc3[3] = allocation;
  if (loopIndex2 < vectorCapacity) {
    _memset((void *)(loopIndex2 * 4 + vectorAlloc2[3]),0,4);
    elementRef = (undefined4 *)(loopIndex2 * 4 + vectorAlloc2[3]);
    vectorAlloc2[2] = loopIndex2 + 1;
  }
  else {
    elementRef = (undefined4 *)Vector__elementRefGrow(vector2,loopIndex2);
  }
  *elementRef = beforeInst;
  vectorSize = vectorAlloc[2];
  if (vectorSize < *vector) {
    _memset((void *)(vectorSize * 4 + vectorAlloc[3]),0,4);
    elementRef = (undefined4 *)(vectorSize * 4 + vectorAlloc[3]);
    vectorAlloc[2] = vectorSize + 1;
    goto code_r0x00184480;
  }
code_r0x00184474:
  elementRef = (undefined4 *)Vector__elementRefGrow(vector,vectorSize);
code_r0x00184480:
  *elementRef = 1;
  do {
    vectorSize2 = vectorAlloc2[2];
    if (vectorSize2 == 0) {
      if (*vector2 == 0) {
        elementRef = (undefined4 *)Vector__elementRefGrow(vector2,0);
      }
      else {
        _memset((void *)vectorAlloc2[3],0,4);
        elementRef = (undefined4 *)vectorAlloc2[3];
        vectorAlloc2[2] = 1;
      }
      *elementRef = beforeInst;
      stackSize = vectorAlloc[2];
      if (stackSize < *vector) {
        _memset((void *)(stackSize * 4 + vectorAlloc[3]),0,4);
        elementRef = (undefined4 *)(stackSize * 4 + vectorAlloc[3]);
        vectorAlloc[2] = stackSize + 1;
      }
      else {
        elementRef = (undefined4 *)Vector__elementRefGrow(vector,stackSize);
      }
      *elementRef = 1;
      while (stackSize = vectorAlloc2[2], stackSize != 0) {
        stackTopRef = (undefined4 *)0x0;
        if (stackSize - 1 < stackSize) {
          stackTopRef = (undefined4 *)((stackSize - 1) * 4 + vectorAlloc2[3]);
        }
        walkInst = (int *)*stackTopRef;
        loopIndex = ((int (*)())Inst__isFoldableSingleUse)(walkInst,block,passArg);
        if ((loopIndex == 0) && (beforeInst != walkInst)) {
          Vector__removeAt(vector2,vectorAlloc2[2] + -1);
          Vector__removeAt(vector,vectorAlloc[2] + -1);
        }
        else {
          countStackTopRef = (int *)0x0;
          stackSize = vectorAlloc[2] - 1;
          if (stackSize < (uint)vectorAlloc[2]) {
            countStackTopRef = (int *)(stackSize * 4 + vectorAlloc[3]);
          }
          neededCount = *countStackTopRef;
          loopIndex = (**(code **)(*walkInst + 0x14))(walkInst);
          if (loopIndex < neededCount) {
            Vector__removeAt(vector2,vectorAlloc2[2] + -1);
            Vector__removeAt(vector,vectorAlloc[2] + -1);
            if (beforeInst != walkInst) {
              DList__unlink(walkInst);
              Block__insertInstBefore(block,beforeInst,walkInst);
            }
          }
          else {
            stackSize = (**(code **)(*walkInst + 0x14))(walkInst);
            if (0 < (int)stackSize) {
              loopIndex = 1;
              do {
                sourceDef = IRInst__getOperandSource(walkInst,loopIndex);
                loopIndex2 = vectorAlloc3[2];
                if (loopIndex2 < *vector3) {
                  _memset((void *)(loopIndex2 * 4 + vectorAlloc3[3]),0,4);
                  elementRef = (undefined4 *)(loopIndex2 * 4 + vectorAlloc3[3]);
                  vectorAlloc3[2] = loopIndex2 + 1;
                }
                else {
                  elementRef = (undefined4 *)Vector__elementRefGrow(vector3,loopIndex2);
                }
                loopIndex = loopIndex + 1;
                *elementRef = sourceDef;
              } while (loopIndex <= (int)stackSize);
            }
            Vector__shellSort(vector3,Inst__compareScheduleSlack);
            Vector__removeAt(vector,vectorAlloc[2] + -1);
            loopIndex2 = vectorAlloc[2];
            if (loopIndex2 < *vector) {
              _memset((void *)(loopIndex2 * 4 + vectorAlloc[3]),0,4);
              walkInst = (int *)(loopIndex2 * 4 + vectorAlloc[3]);
              vectorAlloc[2] = loopIndex2 + 1;
            }
            else {
              walkInst = (int *)Vector__elementRefGrow(vector,loopIndex2);
            }
            *walkInst = stackSize + 1;
            if (0 < (int)stackSize) {
              loopIndex2 = 0;
              do {
                if (loopIndex2 < *vector3) {
                  vectorSize5 = vectorAlloc3[2];
                  if (vectorSize5 <= loopIndex2) {
                    _memset((void *)(vectorSize5 * 4 + vectorAlloc3[3]),0,(loopIndex2 - vectorSize5) * 4 + 4);
                    vectorAlloc3[2] = loopIndex2 + 1;
                  }
                  elementRef = (undefined4 *)(loopIndex2 * 4 + vectorAlloc3[3]);
                }
                else {
                  elementRef = (undefined4 *)Vector__elementRefGrow(vector3,loopIndex2);
                }
                loopIndex2 = loopIndex2 + 1;
                vectorSize6 = vectorAlloc2[2];
                sourceInstEntry = *elementRef;
                if (vectorSize6 < *vector2) {
                  _memset((void *)(vectorSize6 * 4 + vectorAlloc2[3]),0,4);
                  elementRef = (undefined4 *)(vectorSize6 * 4 + vectorAlloc2[3]);
                  vectorAlloc2[2] = vectorSize6 + 1;
                }
                else {
                  elementRef = (undefined4 *)Vector__elementRefGrow(vector2,vectorSize6);
                }
                *elementRef = sourceInstEntry;
                vectorSize7 = vectorAlloc[2];
                if (vectorSize7 < *vector) {
                  _memset((void *)(vectorSize7 * 4 + vectorAlloc[3]),0,4);
                  elementRef = (undefined4 *)(vectorSize7 * 4 + vectorAlloc[3]);
                  vectorAlloc[2] = vectorSize7 + 1;
                }
                else {
                  elementRef = (undefined4 *)Vector__elementRefGrow(vector,vectorSize7);
                }
                *elementRef = 1;
              } while (stackSize != loopIndex2);
            }
            vectorAlloc3[2] = 0;
          }
        }
      }
      if (vector3 != (uint *)0x0) {
        Arena__free(vectorAlloc3[4],vectorAlloc3[3]);
        Arena__free(*vectorAlloc3,vectorAlloc3);
      }
      if (vector != (uint *)0x0) {
        Arena__free(vectorAlloc[4],vectorAlloc[3]);
        Arena__free(*vectorAlloc,vectorAlloc);
      }
      if (vector2 == (uint *)0x0) {
        return;
      }
      Arena__free(vectorAlloc2[4],vectorAlloc2[3]);
      loopIndex = *vectorAlloc2;
      if ((*(int *)(loopIndex + 0x28) != 0) && (walkInst = *(int **)(loopIndex + 0x14), walkInst == vectorAlloc2)) {
        _memset(walkInst,0,*(int *)(loopIndex + 8) - (int)walkInst);
        *(undefined4 *)(loopIndex + 8) = *(undefined4 *)(loopIndex + 0x14);
      }
      return;
    }
    stackTopRef = (undefined4 *)0x0;
    if (vectorSize2 - 1 < vectorSize2) {
      stackTopRef = (undefined4 *)((vectorSize2 - 1) * 4 + vectorAlloc2[3]);
    }
    inst = (int *)*stackTopRef;
    countStackTopIndex = vectorAlloc[2] - 1;
    walkInst = (int *)0x0;
    if (countStackTopIndex < (uint)vectorAlloc[2]) {
      walkInst = (int *)(countStackTopIndex * 4 + vectorAlloc[3]);
    }
    operandIndex = *walkInst;
    loopIndex = ((int (*)())Inst__isFoldableSingleUse)(inst,block,passArg);
    if ((loopIndex == 0) && (beforeInst != inst)) {
      inst[0x54] = 0;
    }
    else {
      loopIndex = (**(code **)(*inst + 0x14))(inst);
      if (operandIndex <= loopIndex) break;
      operandCount = (**(code **)(*inst + 0x14))(inst);
      if (0 < (int)operandCount) {
        loopIndex = 1;
        do {
          sourceDef = IRInst__getOperandSource(inst,loopIndex);
          loopIndex2 = vectorAlloc3[2];
          if (loopIndex2 < *vector3) {
            _memset((void *)(loopIndex2 * 4 + vectorAlloc3[3]),0,4);
            elementRef = (undefined4 *)(loopIndex2 * 4 + vectorAlloc3[3]);
            vectorAlloc3[2] = loopIndex2 + 1;
          }
          else {
            elementRef = (undefined4 *)Vector__elementRefGrow(vector3,loopIndex2);
          }
          loopIndex = loopIndex + 1;
          *elementRef = sourceDef;
        } while (loopIndex <= (int)operandCount);
      }
      Vector__shellSort(vector3,Inst__compareScheduleSlack);
      if (0 < (int)operandCount) {
        loopIndex2 = 0;
        loopIndex = 0;
        do {
          if (loopIndex2 < *vector3) {
            vectorSize8 = vectorAlloc3[2];
            if (vectorSize8 <= loopIndex2) {
              _memset((void *)(vectorSize8 * 4 + vectorAlloc3[3]),0,(loopIndex2 - vectorSize8) * 4 + 4);
              vectorAlloc3[2] = loopIndex2 + 1;
            }
            elementRef = (undefined4 *)(loopIndex2 * 4 + vectorAlloc3[3]);
          }
          else {
            elementRef = (undefined4 *)Vector__elementRefGrow(vector3,loopIndex2);
          }
          loopIndex2 = loopIndex2 + 1;
          walkInst = (int *)*elementRef;
          if ((((walkInst[0x20] == 0) || (operandIndex = RegKind__flagBit0(walkInst[0x26]), operandIndex == 0)) ||
              ((walkInst[5] & 2U) != 0)) ||
             (operandIndex = (**(code **)(*walkInst + 0x50))(walkInst), operandIndex != 0)) {
            operandIndex = 0;
          }
          else {
            operandIndex = IRInst__countWrittenComponents(walkInst);
          }
          loopIndex = loopIndex + operandIndex;
          if (loopIndex <= walkInst[0x54]) {
            loopIndex = walkInst[0x54];
          }
        } while (operandCount != loopIndex2);
      }
      else {
        loopIndex = 0;
      }
      vectorAlloc3[2] = 0;
      inst[0x54] = loopIndex;
    }
    Vector__removeAt(vector2,vectorAlloc2[2] + -1);
    Vector__removeAt(vector,vectorAlloc[2] + -1);
  } while( true );
  sourceDef = IRInst__getOperandSource(inst,operandIndex);
  vectorSize3 = vectorAlloc2[2];
  if (vectorSize3 < *vector2) {
    _memset((void *)(vectorSize3 * 4 + vectorAlloc2[3]),0,4);
    elementRef = (undefined4 *)(vectorSize3 * 4 + vectorAlloc2[3]);
    vectorAlloc2[2] = vectorSize3 + 1;
  }
  else {
    elementRef = (undefined4 *)Vector__elementRefGrow(vector2,vectorSize3);
  }
  *elementRef = sourceDef;
  Vector__removeAt(vector,vectorAlloc[2] + -1);
  vectorSize4 = vectorAlloc[2];
  if (vectorSize4 < *vector) {
    _memset((void *)(vectorSize4 * 4 + vectorAlloc[3]),0,4);
    walkInst = (int *)(vectorSize4 * 4 + vectorAlloc[3]);
    vectorAlloc[2] = vectorSize4 + 1;
  }
  else {
    walkInst = (int *)Vector__elementRefGrow(vector,vectorSize4);
  }
  *walkInst = operandIndex + 1;
  vectorSize = vectorAlloc[2];
  if (*vector <= vectorSize) goto code_r0x00184474;
  _memset((void *)(vectorSize * 4 + vectorAlloc[3]),0,4);
  elementRef = (undefined4 *)(vectorSize * 4 + vectorAlloc[3]);
  vectorAlloc[2] = vectorSize + 1;
  goto code_r0x00184480;
}

/* pass_minreg_order @ 0x184ab4 (280 bytes) */
int pass_minreg_order(scheduler, program)
  undefined4 scheduler;
  int program;
{
  int block;
  int nextBlock;
  int *nextInst;
  int *currentInst;
  int *inst;
  
  block = *(int *)(program + PROG_blockListHead);
  for (nextBlock = *(int *)(*(int *)(program + PROG_blockListHead) + 8); nextBlock != 0; nextBlock = *(int *)(nextBlock + 8)) {
    nextInst = (int *)(*(int **)(block + 0xa0))[1];
    inst = *(int **)(block + 0xa0);
    if (nextInst != (int *)0x0) {
      do {
        currentInst = nextInst;
        nextBlock = (**(code **)(*inst + 0x34))(inst);
        if ((((nextBlock == 0) && (nextBlock = (**(code **)(*inst + 0x38))(inst), nextBlock == 0)) &&
            (nextBlock = (**(code **)(*inst + 0x14))(inst), 0 < nextBlock)) &&
           (nextBlock = ((int (*)())Inst__isFoldableSingleUse)(inst,block,program), nextBlock == 0)) {
          ((int (*)())FUN_0018413c)(scheduler,program,block,inst);
        }
        nextInst = (int *)currentInst[1];
        inst = currentInst;
      } while (nextInst != (int *)0x0);
      nextBlock = *(int *)(block + 8);
    }
    block = nextBlock;
  }
  return Program__beginPass(program,(int)"minreg_order");
}

/* compareIntsAscending @ 0x184bcc (36 bytes) */
int compareIntsAscending(param_1, param_2)
  uint param_1;
  uint param_2;
{
  if (param_1 == param_2) {
    return 0;
  }
  if (param_2 < param_1) {
    return 1;
  }
  return 0xffffffff;
}

/* ObjectVector__allSatisfyPredicate24 @ 0x184bf0 (232 bytes) */
int ObjectVector__allSatisfyPredicate24(owner)
  int owner;
{
  uint vectorFilledCount;
  uint vectorFilledCount2;
  undefined4 *elementRef;
  int callResult;
  uint loopIndex;
  int elementOffset;
  uint elementIndex;
  uint *vector;
  
  vector = *(uint **)(owner + 0x10);
  vectorFilledCount = vector[1];
  elementIndex = vectorFilledCount - 1;
  if (-1 < (int)elementIndex) {
    elementOffset = elementIndex * 4;
    loopIndex = 0;
    while( true ) {
      if (elementIndex < *vector) {
        vectorFilledCount2 = vector[1];
        if (vectorFilledCount2 <= elementIndex) {
          _memset(vectorFilledCount2 * 4 + vector[2],0,(elementIndex - vectorFilledCount2) * 4 + 4);
          vector[1] = elementIndex + 1;
        }
        elementRef = (undefined4 *)(elementOffset + vector[2]);
      }
      else {
        elementRef = (undefined4 *)Vector__elementRefGrow(vector,elementIndex);
      }
      callResult = (**(code **)(*(int *)*elementRef + 0x24))((int *)*elementRef);
      if (callResult == 0) {
        return 0;
      }
      loopIndex = loopIndex + 1;
      elementIndex = elementIndex - 1;
      elementOffset = elementOffset + -4;
      if (vectorFilledCount == loopIndex) break;
      vector = *(uint **)(owner + 0x10);
    }
  }
  return 1;
}

/* Inst__isMulDotWithinLimits @ 0x184cd8 (164 bytes) */
int Inst__isMulDotWithinLimits(this, arg2, passContext)
  int *this;
  undefined4 arg2;
  int passContext;
{
  int opcode;
  int testResult;
  int *hwLimitsObj;
  undefined4 result;
  
  testResult = (**(code **)(*this + 0x24))(this,arg2,passContext);
  if (((testResult == 0) ||
      (hwLimitsObj = *(int **)(*(int *)(passContext + 8) + 0x30c),
      testResult = (**(code **)(*hwLimitsObj + 0xfc))(hwLimitsObj,this[0x49] + -1,this), testResult == 0)) ||
     ((opcode = *(int *)(this[0x22] + 8), opcode != 0x13 && ((opcode != 0x1c && (opcode != 0x1d))))))
  {
    result = 0;
  }
  else {
    result = 1;
  }
  return result;
}

/* Inst__splitAndMerge @ 0x184d7c (372 bytes) */
int Inst__splitAndMerge(param_1, program)
  int param_1;
  undefined4 program;
{
  uint vectorFilledCount2;
  uint vectorFilledCount;
  undefined4 *elementRef;
  int callResult;
  uint loopIndex;
  uint *vector;
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x13) {
    vector = *(uint **)(param_1 + 0x10);
    vectorFilledCount = vector[1];
    if (0 < (int)vectorFilledCount) {
      loopIndex = 0;
      do {
        if (loopIndex < *vector) {
          if (vectorFilledCount <= loopIndex) {
            _memset(vectorFilledCount * 4 + vector[2],0,(loopIndex - vectorFilledCount) * 4 + 4);
            vector[1] = loopIndex + 1;
          }
          elementRef = (undefined4 *)(loopIndex * 4 + vector[2]);
        }
        else {
          elementRef = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
        }
        callResult = Inst__canFuseAddMul(*elementRef,program,0);
        if (callResult == 0) {
          return;
        }
        vector = *(uint **)(param_1 + 0x10);
        loopIndex = loopIndex + 1;
        vectorFilledCount = vector[1];
      } while ((int)loopIndex < (int)vectorFilledCount);
    }
    vectorFilledCount2 = vector[1];
    if (0 < (int)vectorFilledCount2) {
      loopIndex = 0;
      do {
        if (loopIndex < *vector) {
          if (vectorFilledCount2 <= loopIndex) {
            _memset(vectorFilledCount2 * 4 + vector[2],0,(loopIndex - vectorFilledCount2) * 4 + 4);
            vector[1] = loopIndex + 1;
          }
          elementRef = (undefined4 *)(loopIndex * 4 + vector[2]);
        }
        else {
          elementRef = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
        }
        loopIndex = loopIndex + 1;
        Inst__collapseAddOfMulToMad(*elementRef,program,1,0);
        vector = *(uint **)(param_1 + 0x10);
        vectorFilledCount2 = vector[1];
      } while ((int)loopIndex < (int)vectorFilledCount2);
    }
  }
  return;
}

/* IRInst__foldResultScaleIntoUsers @ 0x184ef0 (2440 bytes) */
int IRInst__foldResultScaleIntoUsers(producerInst, scaleExponent, program)
  int *producerInst;
  uint scaleExponent;
  int program;
{
  uint producerOperandFlags;
  uint vectorFilledCount;
  uint prevUserIndex;
  uint *laneConstPtr;
  int useCount;
  int operandRecordTmp;
  int userOpcode;
  int prevUser;
  int uniformFound;
  int fillByteOffset;
  int fillCounter;
  int savedField10;
  uint otherOperandFlags;
  int *userInst;
  int *userElemRef;
  float uniformConstValue;
  int *elementRef;
  int *inst;
  undefined4 sourceDef;
  int operandRecord;
  int operandRecord2;
  float scaleMultiplier2;
  float scaleMultiplier;
  uint userVectorCount;
  int testResult;
  int *hwLimits;
  uint userIndex;
  undefined4 *userSlotRef;
  undefined4 canFold;
  int *operandSrc;
  int otherOperandReg;
  undefined4 operandVReg;
  int producerOperandReg;
  int producerOperandRegOffset;
  int otherOperandRegOffset;
  undefined4 producerSelectWord;
  int operandIndex;
  int operandIndex2;
  uint userScanIndex;
  uint *userVector;
  uint *vector;
  int fillCount;
  double scaledConst;
  undefined1 validateScratch [4];
  uint laneConstants;
  uint uniformKind;
  float uniformValue;
  undefined4 convHi1;
  uint convLo1;
  undefined4 convHi2;
  uint convLo2;
  undefined4 convHi3;
  uint convLo3;
  undefined4 convHi4;
  uint convLo4;
  undefined4 convHi5;
  uint convLo5;
  undefined4 convHi6;
  uint convLo6;
  undefined4 convHi7;
  uint convLo7;
  undefined4 convHi8;
  uint convLo8;
  undefined4 otherSelectWord;
  int savedDestSelect;
  int savedSaturate;
  int savedResultScale;
  int block;
  int afterInst;
  int doubleScaleExponent;
  
  testResult = (**(code **)(*producerInst + 0x24))(producerInst,scaleExponent,program);
  if ((((testResult == 0) ||
       (hwLimits = *(int **)(*(int *)(program + 8) + 0x30c),
       testResult = (**(code **)(*hwLimits + 0xfc))(hwLimits,scaleExponent + producerInst[0x49],0), testResult == 0)) ||
      ((producerInst[5] & 0x200U) != 0)) ||
     ((producerInst[0x48] != 0 || (testResult = (**(code **)(*producerInst + 0x5c))(producerInst), testResult != 0)))) {
LAB_00185098:
    canFold = 0;
  }
  else {
    Vector__shellSort(producerInst[4],compareIntsAscending);
    userVector = (uint *)producerInst[4];
    userIndex = userVector[1];
    if (0 < (int)userIndex) {
      userScanIndex = 0;
      do {
        if (userScanIndex < *userVector) {
          if (userIndex <= userScanIndex) {
            _memset(userIndex * 4 + userVector[2],0,(userScanIndex - userIndex) * 4 + 4);
            userVector[1] = userScanIndex + 1;
          }
          userSlotRef = (undefined4 *)(userScanIndex * 4 + userVector[2]);
        }
        else {
          userSlotRef = (undefined4 *)Vector__elementRefGrow(userVector,userScanIndex);
        }
        inst = (int *)*userSlotRef;
        if ((((inst[5] & 0x200U) != 0) ||
            (testResult = (**(code **)(*inst + 0x28))(inst), testResult != 0)) ||
           (testResult = (**(code **)(*inst + 0x5c))(inst), testResult != 0)) goto LAB_00185098;
        testResult = *(int *)(inst[0x22] + 8);
        if (testResult == 0x31) {
LAB_001850bc:
          if ((((inst[0x21] != 2) || (operandSrc = (int *)IRInst__getOperandSource(inst,1), producerInst != operandSrc))
              || (operandSrc = (int *)IRInst__getOperandSource(inst,2), producerInst != operandSrc)) ||
             (operandSrc = *(int **)(*(int *)(program + 8) + 0x30c),
             testResult = (**(code **)(*operandSrc + 0xfc))(operandSrc,inst[0x49] + scaleExponent * -2,0), testResult == 0
             )) {
LAB_001851b4:
            operandSrc = *(int **)(*(int *)(program + 8) + 0x30c);
            testResult = (**(code **)(*operandSrc + 0xfc))(operandSrc,inst[0x49] - scaleExponent,0);
            goto joined_r0x001851e0;
          }
        }
        else {
          if (0x31 < testResult) {
            if ((testResult == 0x36) || (testResult == 0x66)) goto LAB_001850bc;
            if (testResult == 0x34) {
LAB_00185124:
              operandSrc = (int *)IRInst__getOperandSource(inst,1);
              if ((producerInst != operandSrc) || (operandSrc = (int *)IRInst__getOperandSource(inst,2), producerInst != operandSrc)
                 ) {
                if ((int)scaleExponent < 0) {
                  convLo1 = 1 << (-scaleExponent & 0x3f) ^ 0x80000000;
                  convHi1 = 0x43300000;
                  scaleMultiplier = (float)((double)CONCAT44(0x43300000,convLo1) - 4503601774854144.0);
                }
                else {
                  convHi2 = 0x43300000;
                  convLo2 = 1 << (scaleExponent & 0x3f) ^ 0x80000000;
                  scaleMultiplier = 1.0 / (float)((double)CONCAT44(0x43300000,convLo2) - 4503601774854144.0)
                  ;
                }
                fillCounter = 4;
                laneConstPtr = &laneConstants;
                do {
                  *laneConstPtr = 0x7ffffffe;
                  laneConstPtr = laneConstPtr + 1;
                  fillCounter = fillCounter + -1;
                } while (fillCounter != 0);
                fillByteOffset = 0;
                fillCount = 4;
                do {
                  *(float *)(fillByteOffset + (int)&laneConstants) = scaleMultiplier;
                  fillByteOffset = fillByteOffset + 4;
                  fillCount = fillCount + -1;
                } while (fillCount != 0);
                goto LAB_0018533c;
              }
              goto LAB_001851b4;
            }
            goto LAB_00185098;
          }
          if (testResult == 0x13) goto LAB_001850bc;
          if (testResult != 0x14) {
            if (testResult == 0x12) goto LAB_00185124;
            goto LAB_00185098;
          }
          uniformFound = IRInst__getOperandRecord(inst,0);
          uniformFound = IRInst__getUniformSourceConstant(inst,2,*(undefined4 *)(uniformFound + 0x10),&uniformKind);
          uniformConstValue = uniformValue;
          if (((uniformFound == 0) || (uniformKind != 2)) ||
             (inst = (int *)IRInst__getOperandSource(inst,1), producerInst != inst)) goto LAB_00185098;
          if ((int)scaleExponent < 0) {
            convLo3 = 1 << (-scaleExponent & 0x3f) ^ 0x80000000;
            convHi3 = 0x43300000;
            scaleMultiplier2 = (float)((double)CONCAT44(0x43300000,convLo3) - 4503601774854144.0);
          }
          else {
            convHi4 = 0x43300000;
            convLo4 = 1 << (scaleExponent & 0x3f) ^ 0x80000000;
            scaleMultiplier2 = 1.0 / (float)((double)CONCAT44(0x43300000,convLo4) - 4503601774854144.0);
          }
          laneConstPtr = &laneConstants;
          do {
            *laneConstPtr = 0x7ffffffe;
            laneConstPtr = laneConstPtr + 1;
          } while (&uniformKind != laneConstPtr);
          fillByteOffset = 0;
          fillCount = 4;
          do {
            *(float *)(fillByteOffset + (int)&laneConstants) = uniformConstValue * scaleMultiplier2;
            fillByteOffset = fillByteOffset + 4;
            fillCount = fillCount + -1;
          } while (fillCount != 0);
LAB_0018533c:
          hwLimits = *(int **)(*(int *)(program + 8) + 0x30c);
          testResult = (**(code **)(*hwLimits + 0xe8))
                            (hwLimits,&laneConstants,validateScratch,0x10203,*(int *)(program + 8));
joined_r0x001851e0:
          if (testResult == 0) goto LAB_00185098;
        }
        userVector = (uint *)producerInst[4];
        userScanIndex = userScanIndex + 1;
        userIndex = userVector[1];
      } while ((int)userScanIndex < (int)userIndex);
    }
    userIndex = userIndex - 1;
    if (-1 < (int)userIndex) {
      doubleScaleExponent = scaleExponent << 1;
      do {
        if (0 < (int)userIndex) {
          prevUserIndex = userIndex - 1;
          if (prevUserIndex < *userVector) {
            userVectorCount = userVector[1];
            vector = userVector;
            if (userVectorCount <= prevUserIndex) {
              _memset(userVectorCount * 4 + userVector[2],0,(prevUserIndex - userVectorCount) * 4 + 4);
              userVector[1] = userIndex;
              vector = (uint *)producerInst[4];
            }
            userElemRef = (int *)(prevUserIndex * 4 + userVector[2]);
          }
          else {
            userElemRef = (int *)Vector__elementRefGrow(userVector,prevUserIndex);
            vector = (uint *)producerInst[4];
          }
          prevUser = *userElemRef;
          if (userIndex < *vector) {
            vectorFilledCount = vector[1];
            if (vectorFilledCount <= userIndex) {
              _memset(vectorFilledCount * 4 + vector[2],0,(userIndex - vectorFilledCount) * 4 + 4);
              vector[1] = userIndex + 1;
            }
            elementRef = (int *)(userIndex * 4 + vector[2]);
          }
          else {
            elementRef = (int *)Vector__elementRefGrow(vector,userIndex);
          }
          if (prevUser != *elementRef) {
            userVector = (uint *)producerInst[4];
            goto LAB_0018545c;
          }
          goto LAB_00185964;
        }
LAB_0018545c:
        if (userIndex < *userVector) {
          vectorFilledCount = userVector[1];
          if (vectorFilledCount <= userIndex) {
            _memset(vectorFilledCount * 4 + userVector[2],0,(userIndex - vectorFilledCount) * 4 + 4);
            userVector[1] = userIndex + 1;
          }
          userSlotRef = (undefined4 *)(userIndex * 4 + userVector[2]);
        }
        else {
          userSlotRef = (undefined4 *)Vector__elementRefGrow(userVector,userIndex);
        }
        userInst = (int *)*userSlotRef;
        userOpcode = *(int *)(userInst[0x22] + 8);
        if (userOpcode == 0x31) {
LAB_0018550c:
          if ((userInst[0x21] == 2) &&
             ((operandSrc = (int *)IRInst__getOperandSource(userInst,1), producerInst == operandSrc &&
              (operandSrc = (int *)IRInst__getOperandSource(userInst,2), producerInst == operandSrc)))) {
            userInst[0x49] = userInst[0x49] - doubleScaleExponent;
          }
          else {
LAB_00185628:
            userInst[0x49] = userInst[0x49] - scaleExponent;
          }
        }
        else {
          if (userOpcode < 0x32) {
            if (userOpcode != 0x13) {
              if (userOpcode == 0x14) {
                operandRecordTmp = IRInst__getOperandRecord(userInst,0);
                IRInst__getUniformSourceConstant(userInst,2,*(undefined4 *)(operandRecordTmp + 0x10),&uniformKind);
                if ((int)scaleExponent < 0) {
                  convLo7 = 1 << (-scaleExponent & 0x3f) ^ 0x80000000;
                  convHi7 = 0x43300000;
                  scaleMultiplier = (float)((double)CONCAT44(0x43300000,convLo7) - 4503601774854144.0);
                }
                else {
                  convHi8 = 0x43300000;
                  convLo8 = 1 << (scaleExponent & 0x3f) ^ 0x80000000;
                  scaleMultiplier = 1.0 / (float)((double)CONCAT44(0x43300000,convLo8) - 4503601774854144.0)
                  ;
                }
                scaledConst = (double)(uniformValue * scaleMultiplier);
                IROperand__setModifierBits(userInst + 0x2f,1,0);
                IROperand__setModifierBits(userInst + 0x2f,2,0);
                ((void (*)())IRInst__makeLiteralVec4Float)(userInst,program,2,scaledConst,scaledConst,scaledConst,scaledConst);
              }
              else if (userOpcode == 0x12) goto LAB_00185558;
              goto LAB_00185964;
            }
            goto LAB_0018550c;
          }
          if ((userOpcode == 0x36) || (userOpcode == 0x66)) goto LAB_0018550c;
          if (userOpcode == 0x34) {
LAB_00185558:
            operandSrc = (int *)IRInst__getOperandSource(userInst,1);
            if ((producerInst != operandSrc) || (operandSrc = (int *)IRInst__getOperandSource(userInst,2), producerInst != operandSrc))
            {
              if ((int)scaleExponent < 0) {
                convLo5 = 1 << (-scaleExponent & 0x3f) ^ 0x80000000;
                convHi5 = 0x43300000;
                scaleMultiplier = (float)((double)CONCAT44(0x43300000,convLo5) - 4503601774854144.0);
              }
              else {
                convHi6 = 0x43300000;
                convLo6 = 1 << (scaleExponent & 0x3f) ^ 0x80000000;
                scaleMultiplier = 1.0 / (float)((double)CONCAT44(0x43300000,convLo6) - 4503601774854144.0);
              }
              scaledConst = (double)scaleMultiplier;
              afterInst = userInst[1];
              block = userInst[0x56];
              DList__unlink(userInst);
              operandRecordTmp = IRInst__getOperandRecord(userInst,0);
              savedDestSelect = *(int *)(operandRecordTmp + 0x10);
              savedResultScale = userInst[0x49];
              savedSaturate = userInst[0x48];
              useCount = IRInst__useCount(userInst,program);
              savedField10 = userInst[4];
              operandSrc = (int *)IRInst__getOperandSource(userInst,1);
              if (producerInst == operandSrc) {
                operandIndex2 = 1;
                operandIndex = 2;
              }
              else {
                IRInst__getOperandSource(userInst,2);
                operandIndex2 = 2;
                operandIndex = 1;
              }
              producerOperandRegOffset = userInst[operandIndex2 * 6 + 0x26];
              producerOperandReg = userInst[operandIndex2 * 6 + 0x25];
              operandRecord2 = IRInst__getOperandRecord(userInst,operandIndex2);
              producerOperandFlags = userInst[operandIndex2 * 6 + 0x28];
              producerSelectWord = *(undefined4 *)(operandRecord2 + 0x10);
              sourceDef = IRInst__getOperandSource(userInst,operandIndex2);
              otherOperandRegOffset = userInst[operandIndex * 6 + 0x26];
              otherOperandReg = userInst[operandIndex * 6 + 0x25];
              operandRecord = IRInst__getOperandRecord(userInst,operandIndex);
              otherSelectWord = *(undefined4 *)(operandRecord + 0x10);
              otherOperandFlags = userInst[operandIndex * 6 + 0x28];
              operandVReg = IRInst__getOperandSource(userInst,operandIndex);
              (**(code **)(*userInst + 0xc))(userInst,1,*(undefined4 *)(program + 8));
              IRInst__reinitAsTrinary(userInst,0x14,*(undefined4 *)(program + 8));
              userInst[4] = savedField10;
              userInst[0x25] = userInst[0x53];
              userInst[0x26] = 0;
              userInst[0x27] = savedDestSelect;
              userInst[0x48] = savedSaturate;
              userInst[0x49] = savedResultScale;
              userInst[0x58] = useCount + *(int *)(program + 0x478);
              IRInst__setOperandSource(userInst,1,sourceDef,1,*(undefined4 *)(program + 8));
              operandRecordTmp = IRInst__getOperandRecord(userInst,1);
              *(int *)(operandRecordTmp + 0xc) = producerOperandRegOffset;
              *(int *)(operandRecordTmp + 8) = producerOperandReg;
              operandRecordTmp = IRInst__getOperandRecord(userInst,1);
              *(undefined4 *)(operandRecordTmp + 0x10) = producerSelectWord;
              IROperand__setModifierBits(userInst + 0x29,2,producerOperandFlags >> 1 & 1);
              IROperand__setModifierBits(userInst + 0x29,1,producerOperandFlags & 1);
              IRInst__setOperandSource(userInst,3,operandVReg,1,*(undefined4 *)(program + 8));
              operandRecordTmp = IRInst__getOperandRecord(userInst,3);
              *(int *)(operandRecordTmp + 0xc) = otherOperandRegOffset;
              *(int *)(operandRecordTmp + 8) = otherOperandReg;
              operandRecordTmp = IRInst__getOperandRecord(userInst,3);
              *(undefined4 *)(operandRecordTmp + 0x10) = otherSelectWord;
              IROperand__setModifierBits(userInst + 0x35,2,otherOperandFlags >> 1 & 1);
              IROperand__setModifierBits(userInst + 0x35,1,otherOperandFlags & 1);
              ((void (*)())IRInst__makeLiteralVec4Float)(userInst,program,2,scaledConst,scaledConst,scaledConst,scaledConst);
              Block__insertInstAfter(block,afterInst,userInst);
              goto LAB_00185964;
            }
            goto LAB_00185628;
          }
        }
LAB_00185964:
        userIndex = userIndex - 1;
        if ((int)userIndex < 0) break;
        userVector = (uint *)producerInst[4];
      } while( true );
    }
    canFold = 1;
    producerInst[0x49] = scaleExponent + producerInst[0x49];
  }
  return canFold;
}

/* Inst__tryDp3Add @ 0x1859bc (640 bytes) */
int Inst__tryDp3Add(inst, program, compiler)
  int inst;
  int program;
  undefined4 compiler;
{
  uint dotSrc1Flags;
  undefined4 sourceDef;
  uint addendFlags;
  uint dotSrc2Flags;
  int callResult;
  int *dotInst;
  int *operandVReg;
  undefined4 operandVReg2;
  undefined4 prevNode;
  undefined4 block;
  int addendIndex;
  undefined4 saturate;
  undefined4 resultScale;
  undefined4 destSelect;
  undefined4 addendSelect;
  undefined4 src1Select;
  int extraSource;
  undefined4 addendSelect3;
  undefined4 addendDef;
  uint addendNegate;
  uint addendAbs;
  undefined4 dotSrc2Select;
  undefined4 dotSrc1Select;
  undefined4 addendOperandSelect;
  
  callResult = IRInst__getOperandRecord(inst,1);
  src1Select = *(undefined4 *)(callResult + 0x10);
  callResult = IRInst__getOperandRecord(inst,2);
  addendSelect = *(undefined4 *)(callResult + 0x10);
  callResult = IRInst__getOperandRecord(inst,0);
  destSelect = *(undefined4 *)(callResult + 0x10);
  if (((*(int *)(*(int *)(inst + 0x88) + 8) == 0x12) &&
      (callResult = SelectWord__isSplat(src1Select), callResult != 0)) && (callResult = SelectWord__isSplat(addendSelect), callResult != 0)) {
    dotInst = (int *)IRInst__getOperandSource(inst,1);
    operandVReg = (int *)IRInst__getOperandSource(inst,2);
    if (((*(int *)(dotInst[0x22] + 8) == 0x1c) && (callResult = IRInst__hasSingleUse(dotInst,program), callResult != 0))
       && (((*(uint *)(inst + 0xb8) & 1) == 0 && ((*(uint *)(inst + 0xb8) & 2) == 0)))) {
      callResult = FUN_00146788(dotInst,program);
      addendIndex = 2;
      if (callResult != 0) goto LAB_00185afc;
    }
    if (((*(int *)(operandVReg[0x22] + 8) == 0x1c) && (callResult = IRInst__hasSingleUse(operandVReg,program), callResult != 0))
       && (((*(uint *)(inst + 0xd0) & 1) == 0 &&
           (((*(uint *)(inst + 0xd0) & 2) == 0 &&
            (callResult = FUN_00146788(operandVReg,program), callResult != 0)))))) {
      addendIndex = 1;
      dotInst = operandVReg;
      addendSelect = src1Select;
LAB_00185afc:
      addendDef = IRInst__getOperandSource(inst,addendIndex);
      addendFlags = *(uint *)(addendIndex * 0x18 + inst + 0xa0);
      extraSource = 0;
      addendNegate = addendFlags & 1;
      addendAbs = addendFlags >> 1 & 1;
      callResult = IRInst__getOperandRecord(inst,addendIndex);
      addendOperandSelect = *(undefined4 *)(callResult + 0x10);
      sourceDef = IRInst__getOperandSource(dotInst,1);
      dotSrc1Flags = dotInst[0x2e];
      callResult = IRInst__getOperandRecord(dotInst,1);
      dotSrc1Select = *(undefined4 *)(callResult + 0x10);
      operandVReg2 = IRInst__getOperandSource(dotInst,2);
      dotSrc2Flags = dotInst[0x34];
      callResult = IRInst__getOperandRecord(dotInst,2);
      dotSrc2Select = *(undefined4 *)(callResult + 0x10);
      prevNode = *(undefined4 *)(inst + 4);
      block = *(undefined4 *)(inst + 0x158);
      callResult = IRInst__useCount(inst,program);
      saturate = *(undefined4 *)(inst + 0x120);
      resultScale = *(undefined4 *)(inst + 0x124);
      if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
        extraSource = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
      }
      DList__unlink(inst);
      IRInst__reinitAsTrinary(inst,0xa3,compiler);
      *(undefined4 *)(inst + 0x98) = 0;
      *(undefined4 *)(inst + 0x94) = *(undefined4 *)(inst + 0x14c);
      *(undefined4 *)(inst + 0x9c) = destSelect;
      *(undefined4 *)(inst + 0x120) = saturate;
      *(undefined4 *)(inst + 0x124) = resultScale;
      *(int *)(inst + 0x160) = callResult + *(int *)(program + 0x478);
      if (extraSource != 0) {
        IRInst__setExtraOperandSource(inst,extraSource,0,compiler);
      }
      Block__insertInstAfter(block,prevNode,inst);
      IRInst__setOperandSource(inst,1,sourceDef,0,*(undefined4 *)(program + 8));
      IROperand__setModifierBits(inst + 0xa4,1,dotSrc1Flags & 1);
      IROperand__setModifierBits(inst + 0xa4,2,dotSrc1Flags >> 1 & 1);
      callResult = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(callResult + 0x10) = dotSrc1Select;
      IRInst__setOperandSource(inst,2,operandVReg2,0,*(undefined4 *)(program + 8));
      IROperand__setModifierBits(inst + 0xbc,1,dotSrc2Flags & 1);
      IROperand__setModifierBits(inst + 0xbc,2,dotSrc2Flags >> 1 & 1);
      callResult = IRInst__getOperandRecord(inst,2);
      *(undefined4 *)(callResult + 0x10) = dotSrc2Select;
      IRInst__setOperandSource(inst,3,addendDef,0,*(undefined4 *)(program + 8));
      IROperand__setModifierBits(inst + 0xd4,1,addendNegate);
      IROperand__setModifierBits(inst + 0xd4,2,addendAbs);
      callResult = IRInst__getOperandRecord(inst,3);
      *(undefined4 *)(callResult + 0x10) = addendOperandSelect;
      SelectWord__fillUnusedWithFirstUsed(&addendSelect3,addendSelect);
      callResult = IRInst__getOperandRecord(inst,3);
      *(undefined4 *)(callResult + 0x10) = addendSelect3;
                    
                    
      (**(code **)(*dotInst + 0xc))(dotInst,0,*(undefined4 *)(program + 8));
      return;
    }
  }
  return;
}

/* FUN_00185da4 @ 0x185da4 (1900 bytes) */
int FUN_00185da4(operandIndex, negateOperand, inst, inst2, inst3, program, commitChange, checkFits, replacementOut, altMovInst)
  int operandIndex;
  int negateOperand;
  int *inst;
  int *inst2;
  int *inst3;
  int program;
  int commitChange;
  int checkFits;
  undefined4 *replacementOut;
  int altMovInst;
{
  undefined4 composedSelectCopy;
  undefined4 result;
  int selectWordCopy;
  int *operandVReg;
  bool sourceHandled;
  bool commit;
  int loopIndex;
  int *hwLimits;
  int loopRemaining;
  int operandCount;
  undefined4 operandSelectWord;
  undefined4 movSelectWord;
  int loopIndex2;
  code *setLaneFn;
  undefined4 composedSelect;
  int operandSelectBytes [3];
  undefined4 composeOut;
  int selectWordOut;
  undefined4 writeMaskOut;
  int maskedSelect [4];
  
  loopIndex = IRInst__getOperandRecord(inst3,1);
  movSelectWord = *(undefined4 *)(loopIndex + 0x10);
  loopIndex = IRInst__getOperandRecord(inst,operandIndex);
  operandSelectWord = *(undefined4 *)(loopIndex + 0x10);
  SelectWord__compose(&composeOut,movSelectWord,operandSelectWord);
  composedSelect = composeOut;
  hwLimits = *(int **)(*(int *)(program + 8) + 0x30c);
  loopIndex = (**(code **)(*hwLimits + 0x108))(hwLimits,&composedSelect);
  if (loopIndex == 0) {
    *(int *)(program + 0x20c) = *(int *)(program + 0x20c) + 1;
    return 0;
  }
  if ((negateOperand == 0) || ((inst[operandIndex * 6 + 0x28] & 2U) != 0)) {
LAB_00185ea8:
    if (commitChange == 0) goto LAB_00185f24;
  }
  else {
    if ((*(int *)(inst2[0x22] + 8) == 0x9a) && (inst2[0x2c] == inst2[0x32])) {
      IRInst__swapOperands(inst2,1,2,*(uint *)(program + 8));
      negateOperand = 0;
      goto LAB_00185ea8;
    }
    if (commitChange == 0) goto LAB_00185f24;
    loopIndex = (**(code **)(*inst + 0x60))(inst);
    if (loopIndex != 0) {
      return 0;
    }
    IROperand__setModifierBits(inst + operandIndex * 6 + 0x23,1,inst[operandIndex * 6 + 0x28] & 1U ^ 1);
  }
  composedSelectCopy = composedSelect;
  loopIndex = IRInst__getOperandRecord(inst,operandIndex);
  *(undefined4 *)(loopIndex + 0x10) = composedSelectCopy;
  IRInst__setOperandSource(inst,operandIndex,inst2,0,*(undefined4 *)(program + 8));
LAB_00185f24:
  commit = commitChange != 0;
  FUN_000f32cc(&selectWordOut,composedSelect);
  inst2[0x27] = selectWordOut;
  if ((checkFits != 0) && (loopIndex = SchedModel__instructionFitsAlone(inst,*(undefined4 *)(program + 8)), loopIndex == 0)) {
    loopIndex = 0;
    for (loopIndex2 = 1; loopRemaining = (**(code **)(*inst + 0x14))(inst), loopIndex2 <= loopRemaining;
        loopIndex2 = loopIndex2 + 1) {
      loopRemaining = FUN_000f3b10(inst,loopIndex2);
      if (loopRemaining != 0) {
        loopRemaining = loopIndex + 1;
        loopIndex = loopIndex + 2;
        if (loopIndex2 != operandIndex) {
          loopIndex = loopRemaining;
        }
      }
      FUN_000f3b68(inst,loopIndex2);
    }
    if (3 < loopIndex) {
      for (loopIndex = 1; loopIndex2 = (**(code **)(*inst + 0x14))(inst), loopIndex <= loopIndex2;
          loopIndex = loopIndex + 1) {
        if (operandIndex == loopIndex) {
          loopIndex2 = (**(code **)(*inst3 + 100))(inst3);
          if (loopIndex2 != 0) {
            operandVReg = (int *)IRInst__getOperandSource(inst3,1);
            goto LAB_0018601c;
          }
        }
        else {
          operandVReg = (int *)IRInst__getOperandSource(inst,loopIndex);
LAB_0018601c:
          loopIndex2 = IRInst__getOperandRecord(inst,loopIndex);
          operandSelectBytes[0] = *(int *)(loopIndex2 + 0x10);
          loopIndex2 = SelectWord__isSplat(operandSelectBytes[0]);
          if (loopIndex2 != 0) {
            loopIndex2 = FUN_0011379c(*(undefined4 *)(program + 8),operandVReg);
            if ((loopIndex2 == 0) || (loopIndex2 = IRInst__hasSingleUse(operandVReg,program), loopIndex2 == 0)) {
              sourceHandled = false;
            }
            else {
              loopIndex2 = FUN_000f2cac(operandSelectBytes[0]);
              operandVReg[0x27] = 0x1010100;
              for (loopRemaining = 1; operandCount = (**(code **)(*operandVReg + 0x14))(operandVReg), loopRemaining <= operandCount;
                  loopRemaining = loopRemaining + 1) {
                setLaneFn = *(code **)(*operandVReg + 0x88);
                operandCount = IRInst__getOperandRecord(operandVReg,loopRemaining);
                (*setLaneFn)(operandVReg,loopRemaining,3,*(undefined1 *)(loopIndex2 + operandCount + 0x10));
                (**(code **)(*operandVReg + 0x88))(operandVReg,loopRemaining,loopIndex2,4);
              }
              loopIndex2 = 0;
              loopRemaining = 4;
              do {
                if (*(char *)((int)operandSelectBytes + loopIndex2) != '\x04') {
                  *(undefined1 *)((int)operandSelectBytes + loopIndex2) = 3;
                }
                operandCount = operandSelectBytes[0];
                loopIndex2 = loopIndex2 + 1;
                loopRemaining = loopRemaining + -1;
              } while (loopRemaining != 0);
              if (loopIndex == 0) {
                sourceHandled = true;
                inst[0x27] = operandSelectBytes[0];
              }
              else {
                loopIndex2 = IRInst__getOperandRecord(inst,loopIndex);
                sourceHandled = true;
                *(int *)(loopIndex2 + 0x10) = operandCount;
              }
            }
            loopIndex2 = OpcodeTraits__flagBit8(*(undefined4 *)(operandVReg[0x22] + 8),*(undefined4 *)(program + 8));
            if (loopIndex2 != 0) {
              loopIndex2 = IRInst__hasSingleUse(operandVReg,program);
              if (loopIndex2 == 0) {
                *(undefined1 *)((int)operandVReg + 0x9f) = 0;
              }
              else {
                operandVReg[0x27] = 0x1010100;
              }
              loopIndex2 = 0;
              loopRemaining = 4;
              do {
                if (*(char *)((int)operandSelectBytes + loopIndex2) != '\x04') {
                  *(undefined1 *)((int)operandSelectBytes + loopIndex2) = 3;
                }
                selectWordCopy = operandSelectBytes[0];
                loopIndex2 = loopIndex2 + 1;
                loopRemaining = loopRemaining + -1;
              } while (loopRemaining != 0);
              if (loopIndex == 0) {
                inst[0x27] = operandSelectBytes[0];
              }
              else {
                loopIndex2 = IRInst__getOperandRecord(inst,loopIndex);
                *(int *)(loopIndex2 + 0x10) = selectWordCopy;
              }
LAB_001861f8:
              if (loopIndex == operandIndex) {
                inst2[0x27] = 0x1010100;
                for (loopIndex = 1; loopIndex2 = (**(code **)(*inst2 + 0x14))(inst2), loopIndex <= loopIndex2;
                    loopIndex = loopIndex + 1) {
                  if (loopIndex == 0) {
                    inst2[0x27] = 0x4040404;
                  }
                  else {
                    loopIndex2 = IRInst__getOperandRecord(inst2,loopIndex);
                    *(undefined4 *)(loopIndex2 + 0x10) = 0x4040404;
                  }
                  (**(code **)(*inst2 + 0x88))(inst2,loopIndex,3,3);
                }
              }
              break;
            }
            if (sourceHandled) goto LAB_001861f8;
          }
        }
      }
    }
  }
  loopIndex = SchedModel__instructionFitsAlone(inst,*(undefined4 *)(program + 8));
  if ((loopIndex == 0) && (checkFits != 0)) {
    if (commit) {
      if (altMovInst == 0) {
        IRInst__setOperandSource(inst,operandIndex,inst3,0,*(undefined4 *)(program + 8));
      }
      else {
        IRInst__setOperandSource(inst,operandIndex,altMovInst,0,*(undefined4 *)(program + 8));
      }
      loopIndex = IRInst__getOperandRecord(inst,operandIndex);
      *(undefined4 *)(loopIndex + 0x10) = operandSelectWord;
      if ((negateOperand != 0) && ((inst[operandIndex * 6 + 0x28] & 2U) == 0)) {
        IROperand__setModifierBits(inst + operandIndex * 6 + 0x23,1,inst[operandIndex * 6 + 0x28] & 1U ^ 1);
      }
    }
    if (altMovInst == 0) {
      inst3[0x54] = *(int *)(program + 0x474) + -1;
    }
    else {
      *(int *)(altMovInst + 0x150) = *(int *)(program + 0x474) + -1;
    }
    result = 0;
    *(int *)(program + 0x208) = *(int *)(program + 0x208) + 1;
  }
  else {
    if (commit) {
      *(int *)(program + 0x200) = *(int *)(program + 0x200) + 1;
      Block__insertInstBefore(inst[0x56],inst,inst2);
      inst2[0x58] = *(int *)(program + 0x478) + 1;
    }
    loopIndex = IRInst__getOperandRecord(inst2,0);
    WriteMask__fromSelectWord(&writeMaskOut,*(undefined4 *)(loopIndex + 0x10));
    SelectWord__maskUnused(maskedSelect,0x10203,writeMaskOut);
    if (0 < inst2[0x21]) {
      loopIndex = 1;
      do {
        if (commit) {
          loopIndex2 = IRInst__getOperandSource(inst2,loopIndex);
          if (*(int *)(program + 0x478) < *(int *)(loopIndex2 + 0x160)) {
            *(int *)(loopIndex2 + 0x160) = *(int *)(loopIndex2 + 0x160) + 1;
          }
          else {
            *(int *)(loopIndex2 + 0x160) = *(int *)(program + 0x478) + 1;
          }
        }
        loopIndex2 = (**(code **)(*inst2 + 0x14))(inst2);
        if (loopIndex <= loopIndex2) {
          if (loopIndex == 0) {
            inst2[0x27] = maskedSelect[0];
          }
          else {
            loopIndex2 = IRInst__getOperandRecord(inst2,loopIndex);
            *(int *)(loopIndex2 + 0x10) = maskedSelect[0];
          }
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= inst2[0x21]);
    }
    if (commit) {
      if (altMovInst == 0) {
        inst3[5] = inst3[5] | 0x40000;
        IRInst__dropCounterAndDeleteIfUnused(inst3,*(undefined4 *)(program + 8));
      }
      else {
        *(uint *)(altMovInst + 0x14) = *(uint *)(altMovInst + 0x14) | 0x40000;
        IRInst__dropCounterAndDeleteIfUnused(altMovInst,*(undefined4 *)(program + 8));
        DList__unlink(inst3);
      }
    }
    result = 1;
    if (replacementOut != (undefined4 *)0x0) {
      *replacementOut = inst2;
    }
  }
  return result;
}

