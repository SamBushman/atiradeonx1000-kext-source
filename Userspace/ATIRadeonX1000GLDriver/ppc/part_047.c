#include "decls.h"

/* ValueKey__compareClassForValueNumber @ 0x176ed4 (56 bytes) */
int ValueKey__compareClassForValueNumber(ctx, valueNumber)
  int ctx;
  int valueNumber;
{
  undefined4 result;
  int findInPtrSetResult;
  
  result = 0;
  if (0 < valueNumber) {
    findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),valueNumber);
    result = *(undefined4 *)(findInPtrSetResult + 0xc);
  }
  return result;
}

/* ValueKey__rangeClassForValueNumber @ 0x176f0c (56 bytes) */
int ValueKey__rangeClassForValueNumber(ctx, valueNumber)
  int ctx;
  int valueNumber;
{
  undefined4 result;
  int findInPtrSetResult;
  
  result = 0;
  if (0 < valueNumber) {
    findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),valueNumber);
    result = *(undefined4 *)(findInPtrSetResult + 0x10);
  }
  return result;
}

/* ValueKey__laneRelationHoldsOnWrittenLanes_176f44 @ 0x176f44 (144 bytes) */
int ValueKey__laneRelationHoldsOnWrittenLanes_176f44(ctx, sourceA, sourceB)
  int ctx;
  int sourceA;
  int sourceB;
{
  int laneRelation;
  bool lastLane;
  int operandRecord;
  int loopIndex;
  undefined4 *loopPtr2;
  undefined4 *loopPtr3;
  
  loopPtr2 = (undefined4 *)(sourceA * 0x10 + ctx + 0x168);
  loopPtr3 = (undefined4 *)(sourceB * 0x10 + ctx + 0x168);
  loopIndex = 0;
  while ((operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0),
         *(char *)(loopIndex + operandRecord + 0x10) == '\x01' ||
         (laneRelation = Compiler__valueNumbersRelatedByFields20(*loopPtr2,*loopPtr3,*(undefined4 *)(ctx + 0x238)), laneRelation != 0))) {
    lastLane = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopPtr3 = loopPtr3 + 1;
    loopIndex = loopIndex + 1;
    if (lastLane) {
      return 1;
    }
  }
  return 0;
}

/* ValueKey__laneRelationHoldsOnWrittenLanes_176fd4 @ 0x176fd4 (144 bytes) */
int ValueKey__laneRelationHoldsOnWrittenLanes_176fd4(ctx, sourceA, sourceB)
  int ctx;
  int sourceA;
  int sourceB;
{
  int laneRelation;
  bool lastLane;
  int operandRecord;
  int loopIndex;
  undefined4 *loopPtr2;
  undefined4 *loopPtr3;
  
  loopPtr2 = (undefined4 *)(sourceA * 0x10 + ctx + 0x168);
  loopPtr3 = (undefined4 *)(sourceB * 0x10 + ctx + 0x168);
  loopIndex = 0;
  while ((operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0),
         *(char *)(loopIndex + operandRecord + 0x10) == '\x01' ||
         (laneRelation = Compiler__valueNumbersRelatedByFields28(*loopPtr2,*loopPtr3,*(undefined4 *)(ctx + 0x238)), laneRelation != 0))) {
    lastLane = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopPtr3 = loopPtr3 + 1;
    loopIndex = loopIndex + 1;
    if (lastLane) {
      return 1;
    }
  }
  return 0;
}

/* Inst__writtenLanesAllMatchValue @ 0x177064 (128 bytes) */
int Inst__writtenLanesAllMatchValue(valueKey, value, row)
  int valueKey;
  int value;
  int row;
{
  bool lastLane;
  int operandRecord;
  int loopIndex;
  int *loopPtr2;
  
  loopPtr2 = (int *)(row * 0x10 + valueKey + 0x168);
  loopIndex = 0;
  while ((operandRecord = IRInst__getOperandRecord(*(undefined4 *)(valueKey + 0xb0),0),
         *(char *)(loopIndex + operandRecord + 0x10) == '\x01' || (*loopPtr2 == value))) {
    lastLane = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + 1;
    if (lastLane) {
      return 1;
    }
  }
  return 0;
}

/* ValueKey__commonLaneValue @ 0x1770e4 (204 bytes) */
int ValueKey__commonLaneValue(resultOut, ctx, sourceIndex)
  undefined4 *resultOut;
  int ctx;
  int sourceIndex;
{
  bool commonIsExpr;
  bool noLaneSeen;
  bool notLastLane;
  int operandRecord;
  undefined4 *exprRecord;
  int commonValueNumber;
  int loopIndex;
  int *loopPtr2;
  
  commonValueNumber = 0;
  commonIsExpr = false;
  noLaneSeen = true;
  loopPtr2 = (int *)(sourceIndex * 0x10 + ctx + 0x168);
  loopIndex = 0;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      if (noLaneSeen) {
        commonValueNumber = *loopPtr2;
        commonIsExpr = commonValueNumber < 0;
        noLaneSeen = commonValueNumber == 0;
      }
      else if (*loopPtr2 != commonValueNumber) goto LAB_00177184;
    }
    notLastLane = loopIndex != 3;
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + 1;
  } while (notLastLane);
  if (commonIsExpr) {
    exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),commonValueNumber);
    *resultOut = *exprRecord;
  }
  else {
LAB_00177184:
    *resultOut = 0x7ffffffe;
  }
  return resultOut;
}

/* ValueKey__computeLaneRangeClasses @ 0x1771b0 (236 bytes) */
int ValueKey__computeLaneRangeClasses(ctx)
  int *ctx;
{
  int operandRecord;
  bool lastLane;
  int rangeClass;
  float *exprRecord;
  int ptrSetEntry;
  int loopIndex;
  int *loopPtr2;
  
  loopIndex = 0;
  loopPtr2 = ctx;
  do {
    operandRecord = IRInst__getOperandRecord(ctx[0x2c],0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      if ((float *)loopPtr2[0xc] == (float *)0x0) {
        rangeClass = *loopPtr2;
        if (rangeClass < 0) {
          exprRecord = (float *)Compiler__exprRecordForValueNumber(ctx[0x8e],rangeClass);
          rangeClass = ((undefined4 (*)())classifyConstantRange)((double)*exprRecord);
        }
        else {
          ptrSetEntry = loopPtr2[0x10];
          if (ptrSetEntry == 0) {
            if (rangeClass < 1) {
              rangeClass = 0;
              goto LAB_00177254;
            }
            ptrSetEntry = Compiler__findInPtrSet(ctx[0x8e],rangeClass);
          }
          rangeClass = *(int *)(ptrSetEntry + 0x10);
        }
      }
      else {
        rangeClass = ((undefined4 (*)())classifyConstantRange)((double)*(float *)loopPtr2[0xc]);
      }
LAB_00177254:
      if (*(int *)(ctx[0x2c] + 0x120) == 0) {
        loopPtr2[0x14] = rangeClass;
      }
      else {
        loopPtr2[0x14] = (DAT_001e6158)[rangeClass];
      }
    }
    lastLane = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + 1;
    if (lastLane) {
      return;
    }
  } while( true );
}

/* ValueKey__computeLaneCompareCodes @ 0x17729c (224 bytes) */
int ValueKey__computeLaneCompareCodes(ctx)
  int *ctx;
{
  int operandRecord;
  bool lastLane;
  int valueNumber;
  undefined4 *exprRecord;
  int ptrSetEntry;
  int loopIndex;
  int *loopPtr2;
  
  loopIndex = 0;
  loopPtr2 = ctx;
  do {
    operandRecord = IRInst__getOperandRecord(ctx[0x2c],0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      exprRecord = (undefined4 *)loopPtr2[0xc];
      if (exprRecord == (undefined4 *)0x0) {
        valueNumber = *loopPtr2;
        if (valueNumber < 0) {
          exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(ctx[0x8e],valueNumber);
          goto LAB_00177304;
        }
        ptrSetEntry = loopPtr2[0x10];
        if (ptrSetEntry == 0) {
          if (0 < valueNumber) {
            ptrSetEntry = Compiler__findInPtrSet(ctx[0x8e],valueNumber);
            goto LAB_00177330;
          }
          valueNumber = 0;
        }
        else {
LAB_00177330:
          valueNumber = *(int *)(ptrSetEntry + 0xc);
        }
      }
      else {
LAB_00177304:
        valueNumber = signToCompareCode(*exprRecord);
      }
      if (*(int *)(ctx[0x2c] + 0x120) == 0) {
        loopPtr2[0x20] = valueNumber;
      }
      else {
        loopPtr2[0x20] = (DAT_001e61a0)[valueNumber];
      }
    }
    lastLane = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + 1;
    if (lastLane) {
      return;
    }
  } while( true );
}

/* ValueKey__sourcesEqualOnWrittenLanes @ 0x17737c (144 bytes) */
int ValueKey__sourcesEqualOnWrittenLanes(ctx, sourceA, sourceB)
  int ctx;
  int sourceA;
  int sourceB;
{
  bool lastLane;
  int operandRecord;
  int loopIndex;
  int *loopPtr2;
  int *loopPtr3;
  
  loopPtr2 = (int *)(sourceA * 0x10 + ctx + 0x168);
  loopPtr3 = (int *)(sourceB * 0x10 + ctx + 0x168);
  loopIndex = 0;
  while ((operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0),
         *(char *)(loopIndex + operandRecord + 0x10) == '\x01' || (*loopPtr2 == *loopPtr3))) {
    lastLane = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopPtr3 = loopPtr3 + 1;
    loopIndex = loopIndex + 1;
    if (lastLane) {
      return 1;
    }
  }
  return 0;
}

/* ValueKey__sourceIsSplatOfConstant @ 0x17740c (156 bytes) */
undefined4 ValueKey__sourceIsSplatOfConstant(int ctx,int sourceIndex,double constantValue)
{
  bool lastLane;
  int exprRecord;
  int operandRecord;
  int *loopPtr2;
  int loopIndex;
  
  loopPtr2 = (int *)(sourceIndex * 0x10 + ctx + 0x168);
  exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),GH_F2U((float)constantValue));
  loopIndex = 0;
  while ((operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0),
         *(char *)(loopIndex + operandRecord + 0x10) == '\x01' || (*loopPtr2 == *(int *)(exprRecord + 4)))) {
    lastLane = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + 1;
    if (lastLane) {
      return 1;
    }
  }
  return 0;
}

/* ValueKey__flagZeroSelectLanes @ 0x177548 (144 bytes) */
int ValueKey__flagZeroSelectLanes(ctx)
  int ctx;
{
  bool lastLane;
  int operandRecord;
  int loopIndex;
  
  loopIndex = 0;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + operandRecord + 0x10) == '\0') {
      *(undefined1 *)(loopIndex + *(int *)(ctx + 0xb0) + 0x9c) = 1;
    }
    lastLane = loopIndex != 3;
    loopIndex = loopIndex + 1;
  } while (lastLane);
  loopIndex = *(int *)(ctx + 0xb0);
  if ((*(uint *)(loopIndex + 0x14) & 0x200) == 0) {
    IRInst__appendSource(loopIndex,*(undefined4 *)(loopIndex + 0x8c));
    return;
  }
  return;
}

/* ValueKey__createLaneRecordsKind20 @ 0x1775d8 (224 bytes) */
int ValueKey__createLaneRecordsKind20(ctx)
  int ctx;
{
  int inst;
  int operandRecord;
  bool lastLane;
  int laneRecord;
  int loopIndex;
  int laneWordPtr;
  
  inst = *(int *)(ctx + 0xb0);
  if ((*(int *)(inst + 0x120) == 0) && (*(int *)(inst + 0x124) == 0)) {
    if (((*(uint *)(inst + 0xb8) & 2) == 0) && ((*(uint *)(inst + 0xb8) & 1) != 0)) {
      loopIndex = 0;
      laneWordPtr = ctx;
      while( true ) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        if ((*(char *)(loopIndex + operandRecord + 0x10) != '\x01') && (*(int *)(laneWordPtr + 0x30) == 0)) {
          laneRecord = *(int *)(laneWordPtr + 0x40);
          if (laneRecord == 0) {
            laneRecord = Compiler__internLaneExpr(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
            *(int *)(laneWordPtr + 0x40) = laneRecord;
          }
          *(int *)(laneRecord + 4) = ctx;
          *(int *)(*(int *)(laneWordPtr + 0x40) + 8) = loopIndex;
          *(undefined4 *)(*(int *)(laneWordPtr + 0x40) + 0x20) = 1;
          *(undefined4 *)(*(int *)(laneWordPtr + 0x40) + 0x24) = *(undefined4 *)(laneWordPtr + 0x178);
        }
        lastLane = loopIndex == 3;
        laneWordPtr = laneWordPtr + 4;
        loopIndex = loopIndex + 1;
        if (lastLane) break;
        inst = *(int *)(ctx + 0xb0);
      }
    }
  }
  return;
}

/* ValueKey__foldLaneToZeroIfSourcesCancel @ 0x1776b8 (144 bytes) */
int ValueKey__foldLaneToZeroIfSourcesCancel(ctx, lane)
  int ctx;
  int lane;
{
  uint word0xb8Flags;
  int callResult;
  undefined4 exprRecord;
  uint word0xd0Flags;
  int laneBase;
  
  laneBase = lane * 4 + ctx;
  callResult = ValueKey__valueNumbersRelated(ctx,*(undefined4 *)(laneBase + 0x178),*(undefined4 *)(laneBase + 0x188));
  if (callResult != 0) {
    word0xd0Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    word0xb8Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((word0xb8Flags & 1) == (word0xd0Flags & 1)) && ((word0xb8Flags >> 1 & 1) == (word0xd0Flags >> 1 & 1))) {
      exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0);
      *(undefined4 *)(laneBase + 0x30) = exprRecord;
      return 1;
    }
  }
  return 0;
}

/* ValueKey__canonicalizeCompareCondition @ 0x177748 (408 bytes) */
int ValueKey__canonicalizeCompareCondition(ctx)
  int ctx;
{
  int prevLaneClass;
  int condition;
  int findInPtrSetResult;
  bool laneFlag;
  uint operandFlags;
  int callResult;
  int *hwLimits;
  int conditionSupported;
  int operandRecord;
  undefined4 *exprRecord;
  int laneClass;
  int loopIndex;
  int laneEntryPtr;
  float compareConstOut [2];
  float compareConst;
  
  callResult = IRInst__getCompareCondition(*(undefined4 *)(ctx + 0xb0));
  ((int (*)())ValueKey__commonLaneValue)(compareConstOut,ctx,2);
  compareConst = compareConstOut[0];
  if ((compareConstOut[0] == FLOAT_001aa0d4) &&
     (hwLimits = *(int **)(*(int *)(ctx + 0x238) + 0x30c),
     conditionSupported = (**(code **)(*hwLimits + 0x2c))(hwLimits,callResult), conditionSupported == 0)) {
    loopIndex = 0;
    prevLaneClass = 0;
    laneEntryPtr = ctx;
    do {
      operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      laneClass = prevLaneClass;
      if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
        laneClass = *(int *)(laneEntryPtr + 0x178);
        if (laneClass < 0) {
          exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),laneClass);
          laneClass = signToCompareCode(*exprRecord);
        }
        else {
          if (laneClass < 1) {
            return;
          }
          findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),laneClass);
          laneClass = *(int *)(findInPtrSetResult + 0xc);
          operandFlags = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
          if ((operandFlags & 2) != 0) {
            laneClass = (DAT_001e61d0)[laneClass];
          }
          if ((operandFlags & 1) != 0) {
            laneClass = *(int *)(&DAT_001e61b8 + laneClass * 4);
          }
        }
        if (laneClass == 0) {
          return;
        }
        if ((prevLaneClass != 0) && (laneFlag = laneClass != prevLaneClass, laneClass = prevLaneClass, laneFlag)) {
          return;
        }
      }
      laneFlag = loopIndex != 3;
      laneEntryPtr = laneEntryPtr + 4;
      loopIndex = loopIndex + 1;
      prevLaneClass = laneClass;
    } while (laneFlag);
    hwLimits = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
    condition = (**(code **)(*hwLimits + 0x30))(hwLimits,callResult,laneClass);
    if (callResult != condition) {
      IRInst__setCompareCondition(*(undefined4 *)(ctx + 0xb0),condition);
      return;
    }
  }
  return;
}

/* FUN_001778e0 @ 0x1778e0 (272 bytes) */
int FUN_001778e0(ctx)
  int ctx;
{
  int inst;
  int operandRecord;
  bool lastLane;
  int laneRecord;
  undefined4 firstLaneRecord;
  int laneWordPtr;
  int loopIndex;
  double outputScale;
  
  inst = *(int *)(ctx + 0xb0);
  if ((((*(int *)(inst + 0x120) == 0) && ((*(uint *)(inst + 0xb8) & 1) == 0)) &&
      ((*(uint *)(inst + 0xb8) & 2) == 0)) && (*(int *)(inst + 0x124) != 0)) {
    loopIndex = 0;
    laneWordPtr = ctx;
    while( true ) {
      operandRecord = IRInst__getOperandRecord(inst,0);
      if ((*(char *)(loopIndex + operandRecord + 0x10) != '\x01') && (*(int *)(laneWordPtr + 0x30) == 0)) {
        if (*(int *)(laneWordPtr + 0x40) == 0) {
          firstLaneRecord = Compiler__internLaneExpr(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
          *(undefined4 *)(laneWordPtr + 0x40) = firstLaneRecord;
        }
        laneRecord = Compiler__internLaneExpr(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
        *(int *)(laneWordPtr + 0x40) = laneRecord;
        *(int *)(laneRecord + 4) = ctx;
        *(int *)(*(int *)(laneWordPtr + 0x40) + 8) = loopIndex;
        *(undefined4 *)(*(int *)(laneWordPtr + 0x40) + 0x14) = 1;
        *(undefined4 *)(*(int *)(laneWordPtr + 0x40) + 0x18) = *(undefined4 *)(laneWordPtr + 0x178);
        laneRecord = *(int *)(laneWordPtr + 0x40);
        outputScale = (double)((double (*)())outputScaleFromExponent)(*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124));
        *(float *)(laneRecord + 0x1c) = (float)outputScale;
      }
      lastLane = loopIndex == 3;
      laneWordPtr = laneWordPtr + 4;
      loopIndex = loopIndex + 1;
      if (lastLane) break;
      inst = *(int *)(ctx + 0xb0);
    }
  }
  return;
}

/* ValueKey__createLaneRecordsKind28 @ 0x1779f0 (224 bytes) */
int ValueKey__createLaneRecordsKind28(ctx)
  int ctx;
{
  int inst;
  int operandRecord;
  bool lastLane;
  int laneRecord;
  int loopIndex;
  int laneWordPtr;
  
  inst = *(int *)(ctx + 0xb0);
  if ((*(int *)(inst + 0x120) == 0) && (*(int *)(inst + 0x124) == 0)) {
    if (((*(uint *)(inst + 0xb8) & 1) == 0) && ((*(uint *)(inst + 0xb8) & 2) == 0)) {
      loopIndex = 0;
      laneWordPtr = ctx;
      while( true ) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        if ((*(char *)(loopIndex + operandRecord + 0x10) != '\x01') && (*(int *)(laneWordPtr + 0x30) == 0)) {
          laneRecord = *(int *)(laneWordPtr + 0x40);
          if (laneRecord == 0) {
            laneRecord = Compiler__internLaneExpr(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
            *(int *)(laneWordPtr + 0x40) = laneRecord;
          }
          *(int *)(laneRecord + 4) = ctx;
          *(int *)(*(int *)(laneWordPtr + 0x40) + 8) = loopIndex;
          *(undefined4 *)(*(int *)(laneWordPtr + 0x40) + 0x28) = 1;
          *(undefined4 *)(*(int *)(laneWordPtr + 0x40) + 0x2c) = *(undefined4 *)(laneWordPtr + 0x178);
        }
        lastLane = loopIndex == 3;
        laneWordPtr = laneWordPtr + 4;
        loopIndex = loopIndex + 1;
        if (lastLane) break;
        inst = *(int *)(ctx + 0xb0);
      }
    }
  }
  return;
}

/* ValueKey__cancelNegatedSourcePair @ 0x177ad0 (124 bytes) */
int ValueKey__cancelNegatedSourcePair(ctx)
  int ctx;
{
  int member0xb0;
  undefined4 result;
  
  member0xb0 = *(int *)(ctx + 0xb0);
  if (((*(uint *)(member0xb0 + 0xb8) & 1) == 0) || ((*(uint *)(member0xb0 + 0xd0) & 1) == 0)) {
    result = 0;
  }
  else {
    IROperand__setModifierBits(member0xb0 + 0xa4,1,0);
    IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xbc,1,0);
    ValueKey__rebuild(ctx);
    result = 1;
  }
  return result;
}

/* ValueKey__insertMovOfOperandLane_177b4c @ 0x177b4c (388 bytes) */
int ValueKey__insertMovOfOperandLane_177b4c(ctx, operandIndex, lane)
  int ctx;
  int operandIndex;
  int lane;
{
  undefined4 srcSelectWord;
  int operandRecord;
  int callResult;
  int inst;
  undefined4 destSelectWord;
  undefined4 block;
  int operandOffset;
  
  block = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
  callResult = IRInst__create(0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(callResult,0,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  destSelectWord = *(undefined4 *)(PTR_DAT_001e8b64 + lane * 4);
  *(undefined4 *)(callResult + 0x94) = *(undefined4 *)(callResult + 0x14c);
  *(undefined4 *)(callResult + 0x9c) = destSelectWord;
  *(undefined4 *)(callResult + 0x98) = 0;
  operandOffset = operandIndex * 0x18 + 0x80;
  IRInst__setOperandRef(callResult,1,*(undefined4 *)(operandIndex * 0x18 + *(int *)(ctx + 0xb0) + 0x8c));
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),operandIndex);
  srcSelectWord = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)*(byte *)(lane + operandRecord + 0x10) * 4);
  operandRecord = IRInst__getOperandRecord(callResult,1);
  *(undefined4 *)(operandRecord + 0x10) = srcSelectWord;
  IROperand__setModifierBits(callResult + 0xa4,2,*(uint *)(*(int *)(ctx + 0xb0) + operandOffset + 0x20) >> 1 & 1);
  IROperand__setModifierBits(callResult + 0xa4,1,*(uint *)(*(int *)(ctx + 0xb0) + operandOffset + 0x20) & 1);
  *(undefined4 *)(callResult + 0x120) = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x120);
  *(undefined4 *)(callResult + 0x124) = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124);
  IRInst__appendSource(callResult,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  *(undefined1 *)(lane + *(int *)(ctx + 0xb0) + 0x9c) = 1;
  inst = *(int *)(ctx + 0xb0);
  if ((*(uint *)(inst + 0x14) & 0x200) == 0) {
    IRInst__appendSource(inst,*(undefined4 *)(inst + 0x8c));
    inst = *(int *)(ctx + 0xb0);
  }
  Block__insertInstAfter(block,inst,callResult);
  return callResult;
}

/* ValueKey__insertMovOfReplacementLane @ 0x177cd0 (324 bytes) */
int ValueKey__insertMovOfReplacementLane(ctx, replacement, lane)
  int ctx;
  int replacement;
  int lane;
{
  undefined4 srcSelectWord;
  int operandRecord;
  int callResult;
  int inst;
  undefined4 destSelectWord;
  undefined4 block;
  
  block = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
  callResult = IRInst__create(0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(callResult,0,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  destSelectWord = *(undefined4 *)(PTR_DAT_001e8b64 + lane * 4);
  *(undefined4 *)(callResult + 0x94) = *(undefined4 *)(callResult + 0x14c);
  *(undefined4 *)(callResult + 0x98) = 0;
  *(undefined4 *)(callResult + 0x9c) = destSelectWord;
  IRInst__setOperandRef(callResult,1,*(undefined4 *)(replacement + 0xc));
  srcSelectWord = *(undefined4 *)(PTR_DAT_001e8b8c + *(int *)(replacement + 0x10) * 4);
  operandRecord = IRInst__getOperandRecord(callResult,1);
  *(undefined4 *)(operandRecord + 0x10) = srcSelectWord;
  if (*(int *)(replacement + 0x18) != 0) {
    IROperand__setModifierBits(callResult + 0xa4,1,1);
  }
  *(undefined4 *)(callResult + 0x120) = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x120);
  *(undefined4 *)(callResult + 0x124) = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124);
  IRInst__appendSource(callResult,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  *(undefined1 *)(lane + *(int *)(ctx + 0xb0) + 0x9c) = 1;
  inst = *(int *)(ctx + 0xb0);
  if ((*(uint *)(inst + 0x14) & 0x200) == 0) {
    IRInst__appendSource(inst,*(undefined4 *)(inst + 0x8c));
    inst = *(int *)(ctx + 0xb0);
  }
  Block__insertInstAfter(block,inst,callResult);
  return callResult;
}

/* ValueKey__insertBinaryOfOperandsLane @ 0x177e14 (528 bytes) */
int ValueKey__insertBinaryOfOperandsLane(ctx, opcode, operandIndex, operandIndex2, lane)
  int ctx;
  undefined4 opcode;
  int operandIndex;
  int operandIndex2;
  int lane;
{
  int src2OperandOffset;
  undefined4 src2SelectWord;
  undefined4 src1SelectWord;
  int operandRecord;
  undefined *selectTable;
  int callResult;
  int inst;
  undefined4 destSelectWord;
  undefined4 block;
  int src1OperandOffset;
  
  block = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
  callResult = IRInst__create(opcode,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(callResult,0,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  destSelectWord = *(undefined4 *)(PTR_DAT_001e8b64 + lane * 4);
  *(undefined4 *)(callResult + 0x94) = *(undefined4 *)(callResult + 0x14c);
  *(undefined4 *)(callResult + 0x9c) = destSelectWord;
  *(undefined4 *)(callResult + 0x98) = 0;
  src1OperandOffset = operandIndex * 0x18 + 0x80;
  IRInst__setOperandRef(callResult,1,*(undefined4 *)(operandIndex * 0x18 + *(int *)(ctx + 0xb0) + 0x8c));
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),operandIndex);
  selectTable = PTR_DAT_001e8b8c;
  src1SelectWord = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)*(byte *)(lane + operandRecord + 0x10) * 4);
  operandRecord = IRInst__getOperandRecord(callResult,1);
  *(undefined4 *)(operandRecord + 0x10) = src1SelectWord;
  IROperand__setModifierBits(callResult + 0xa4,2,*(uint *)(*(int *)(ctx + 0xb0) + src1OperandOffset + 0x20) >> 1 & 1);
  IROperand__setModifierBits(callResult + 0xa4,1,*(uint *)(*(int *)(ctx + 0xb0) + src1OperandOffset + 0x20) & 1);
  src2OperandOffset = operandIndex2 * 0x18 + 0x80;
  IRInst__setOperandRef(callResult,2,*(undefined4 *)(operandIndex2 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c));
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),operandIndex2);
  src2SelectWord = *(undefined4 *)(selectTable + (uint)*(byte *)(lane + operandRecord + 0x10) * 4);
  operandRecord = IRInst__getOperandRecord(callResult,2);
  *(undefined4 *)(operandRecord + 0x10) = src2SelectWord;
  IROperand__setModifierBits(callResult + 0xbc,2,*(uint *)(*(int *)(ctx + 0xb0) + src2OperandOffset + 0x20) >> 1 & 1);
  IROperand__setModifierBits(callResult + 0xbc,1,*(uint *)(*(int *)(ctx + 0xb0) + src2OperandOffset + 0x20) & 1);
  *(undefined4 *)(callResult + 0x120) = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x120);
  *(undefined4 *)(callResult + 0x124) = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124);
  IRInst__appendSource(callResult,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  *(undefined1 *)(lane + *(int *)(ctx + 0xb0) + 0x9c) = 1;
  inst = *(int *)(ctx + 0xb0);
  if ((*(uint *)(inst + 0x14) & 0x200) == 0) {
    IRInst__appendSource(inst,*(undefined4 *)(inst + 0x8c));
    inst = *(int *)(ctx + 0xb0);
  }
  Block__insertInstAfter(block,inst,callResult);
  return callResult;
}

/* ValueKey__insertMovOfOperandLane @ 0x178024 (384 bytes) */
int ValueKey__insertMovOfOperandLane(ctx, operandIndex, lane, resultScaleCode)
  int ctx;
  int operandIndex;
  int lane;
  undefined4 resultScaleCode;
{
  undefined4 srcSelectWord;
  int operandRecord;
  int callResult;
  int inst;
  undefined4 destSelectWord;
  undefined4 block;
  int operandOffset;
  
  block = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
  callResult = IRInst__create(0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(callResult,0,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  destSelectWord = *(undefined4 *)(PTR_DAT_001e8b64 + lane * 4);
  *(undefined4 *)(callResult + 0x94) = *(undefined4 *)(callResult + 0x14c);
  *(undefined4 *)(callResult + 0x9c) = destSelectWord;
  *(undefined4 *)(callResult + 0x98) = 0;
  operandOffset = operandIndex * 0x18 + 0x80;
  IRInst__setOperandRef(callResult,1,*(undefined4 *)(operandIndex * 0x18 + *(int *)(ctx + 0xb0) + 0x8c));
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),operandIndex);
  srcSelectWord = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)*(byte *)(lane + operandRecord + 0x10) * 4);
  operandRecord = IRInst__getOperandRecord(callResult,1);
  *(undefined4 *)(operandRecord + 0x10) = srcSelectWord;
  IROperand__setModifierBits(callResult + 0xa4,2,*(uint *)(*(int *)(ctx + 0xb0) + operandOffset + 0x20) >> 1 & 1);
  IROperand__setModifierBits(callResult + 0xa4,1,*(uint *)(*(int *)(ctx + 0xb0) + operandOffset + 0x20) & 1);
  inst = *(int *)(ctx + 0xb0);
  *(undefined4 *)(callResult + 0x124) = resultScaleCode;
  *(undefined4 *)(callResult + 0x120) = *(undefined4 *)(inst + 0x120);
  IRInst__appendSource(callResult,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  *(undefined1 *)(lane + *(int *)(ctx + 0xb0) + 0x9c) = 1;
  inst = *(int *)(ctx + 0xb0);
  if ((*(uint *)(inst + 0x14) & 0x200) == 0) {
    IRInst__appendSource(inst,*(undefined4 *)(inst + 0x8c));
    inst = *(int *)(ctx + 0xb0);
  }
  Block__insertInstAfter(block,inst,callResult);
  return callResult;
}

/* ValueKey__evaluateConstantInstruction @ 0x1781a4 (404 bytes) */
int ValueKey__evaluateConstantInstruction(resultOut, valueKey, changedOut)
  float *resultOut;
  int valueKey;
  undefined4 *changedOut;
{
  int instFlagBit2Result;
  undefined4 *loopPtr2;
  int operandCount;
  int *loopPtr;
  int laneInputOffset;
  int loopRemaining;
  undefined4 laneInputs [6];
  int operandLaneSelect [6];
  float scaledResult;
  float clampedResult [2];
  
  loopRemaining = 5;
  *resultOut = GH_U2F(0x7fff0000U);
  loopPtr2 = laneInputs;
  do {
    *loopPtr2 = 0x7ffffffe;
    loopPtr2 = loopPtr2 + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  loopPtr = operandLaneSelect;
  laneInputOffset = 4;
  for (loopRemaining = 1;
      operandCount = (**(code **)(**(int **)(valueKey + 0xb0) + 0x14))(*(int **)(valueKey + 0xb0)),
      loopRemaining <= operandCount; loopRemaining = loopRemaining + 1) {
    instFlagBit2Result = OpcodeTraits__instFlagBit2(*(undefined4 *)(valueKey + 0x238),*(undefined4 *)(valueKey + 0xb0));
    if (instFlagBit2Result == 0) {
      *loopPtr = 0;
    }
    else if (loopRemaining == 2) {
      operandLaneSelect[1] = 0;
    }
    else if (loopRemaining == 3) {
      operandLaneSelect[2] = 1;
    }
    else if (loopRemaining == 1) {
      operandLaneSelect[0] = 3;
    }
    operandCount = *loopPtr;
    loopPtr = loopPtr + 1;
    loopPtr2 = (undefined4 *)
             Compiler__exprRecordForValueNumber(*(undefined4 *)(valueKey + 0x238),
                          *(undefined4 *)((laneInputOffset + operandCount) * 4 + valueKey + 0x168));
    *(undefined4 *)(laneInputOffset + (int)laneInputs) = *loopPtr2;
    laneInputOffset = laneInputOffset + 4;
  }
  loopPtr = *(int **)(*(int *)(valueKey + 0xb0) + 0x88);
  (**(code **)(*loopPtr + 4))(loopPtr,resultOut,laneInputs,*(undefined4 *)(valueKey + 0x238));
  if (*resultOut != 2.1474836e+09) {
    IRInst__scaleByOutputScale(&scaledResult,*(undefined4 *)(valueKey + 0xb0),*resultOut);
    *resultOut = scaledResult;
    IRInst__clampOutputValue(clampedResult,*(undefined4 *)(valueKey + 0xb0),scaledResult);
    if (clampedResult[0] != *resultOut) {
      *changedOut = 1;
      *resultOut = clampedResult[0];
    }
  }
  return resultOut;
}

/* ValueKey__classifyLaneRangeClass @ 0x178338 (656 bytes) */
int ValueKey__classifyLaneRangeClass(ctx, lane, clampFlagsOut)
  int ctx;
  int lane;
  int clampFlagsOut;
{
  int valueNumber;
  int resultClass;
  int laneNode;
  int keyInst;
  int findInPtrSetResult;
  int laneByteOffset;
  uint operandFlags;
  float *exprRecord;
  int operandCount;
  int operandRecAddr;
  int operandRecOffset;
  int operandNumber;
  int *valueNumberPtr;
  int *loopPtr;
  int operandClass [9];
  
  laneByteOffset = lane * 4;
  if (*(int *)(laneByteOffset + ctx + 0x30) == 0) {
    valueNumberPtr = (int *)(laneByteOffset + ctx + 0x178);
    loopPtr = operandClass;
    operandRecOffset = 0x98;
    for (operandNumber = 1;
        operandCount = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0)),
        operandNumber <= operandCount; operandNumber = operandNumber + 1) {
      valueNumber = *valueNumberPtr;
      if (valueNumber < 0) {
        exprRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),valueNumber);
        valueNumber = ((undefined4 (*)())classifyConstantRange)((double)*exprRecord);
        *loopPtr = valueNumber;
      }
      else if (valueNumber < 1) {
        *loopPtr = 0;
      }
      else {
        findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),valueNumber);
        valueNumber = *(int *)(findInPtrSetResult + 0x10);
        *loopPtr = valueNumber;
        operandRecAddr = *(int *)(ctx + 0xb0) + operandRecOffset;
        operandFlags = *(uint *)(operandRecAddr + 0x20);
        if ((operandFlags & 2) != 0) {
          *loopPtr = *(int *)(&DAT_001e6188 + valueNumber * 4);
          operandFlags = *(uint *)(operandRecAddr + 0x20);
        }
        if ((operandFlags & 1) != 0) {
          *loopPtr = *(int *)(&DAT_001e6170 + *loopPtr * 4);
        }
      }
      operandRecOffset = operandRecOffset + 0x18;
      loopPtr = loopPtr + 1;
      valueNumberPtr = valueNumberPtr + 4;
    }
    keyInst = *(int *)(ctx + 0xb0);
    switch(*(undefined4 *)(*(int *)(keyInst + 0x88) + 8)) {
    case 0x12:
      operandClass[0] = *(int *)(&DAT_001e5bf4 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    case 0x13:
      operandClass[0] = *(int *)(&DAT_001e5ad4 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    default:
      operandClass[0] = 0;
      break;
    case 0x17:
      operandClass[0] = *(int *)(&DAT_001e5a44 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    case 0x19:
      operandClass[0] = *(int *)(&DAT_001e59b4 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    case 0x24:
    case 0x25:
    case 0x26:
      operandClass[0] = *(int *)(&DAT_001e5b64 + (operandClass[1] * 6 + operandClass[2]) * 4);
      break;
    case 0x31: ;
    }
    if ((0 < *(int *)(keyInst + 0x124)) && (operandClass[0] != 2)) {
      operandClass[0] = 0;
    }
    resultClass = operandClass[0];
    if (*(int *)(keyInst + 0x120) != 0) {
      resultClass = (DAT_001e6158)[operandClass[0]];
      if (operandClass[0] == resultClass) {
        *(undefined4 *)(laneByteOffset + clampFlagsOut) = 0;
        resultClass = operandClass[0];
      }
      else {
        *(undefined4 *)(laneByteOffset + clampFlagsOut) = 1;
      }
    }
    laneNode = *(int *)(laneByteOffset + ctx + 0x40);
    if (laneNode == 0) {
      laneNode = Compiler__internLaneExpr(*(undefined4 *)(ctx + 0x238),lane,ctx);
      *(int *)(laneByteOffset + ctx + 0x40) = laneNode;
    }
    *(int *)(laneNode + 0x10) = resultClass;
  }
  return;
}

/* ValueKey__classifyLaneCompareClass @ 0x178648 (708 bytes) */
int ValueKey__classifyLaneCompareClass(ctx, lane)
  int ctx;
  int lane;
{
  int valueNumber;
  int laneEntryPtr2;
  int laneNode;
  int resultClass;
  int operandRecOffset;
  int findInPtrSetResult;
  uint operandFlags;
  int laneEntryPtr;
  undefined4 *exprRecord;
  int operandCount;
  int operandRecAddr;
  int operandRecOffset2;
  int operandNumber;
  int *valueNumberPtr;
  int *loopPtr;
  int operandClass [9];
  
  laneEntryPtr = lane * 4 + ctx;
  if (*(int *)(laneEntryPtr + 0x30) == 0) {
    valueNumberPtr = (int *)(laneEntryPtr + 0x178);
    loopPtr = operandClass;
    operandRecOffset = 0x98;
    operandRecOffset2 = 0x98;
    for (operandNumber = 1;
        operandCount = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0)),
        operandNumber <= operandCount; operandNumber = operandNumber + 1) {
      valueNumber = *valueNumberPtr;
      if (valueNumber < 0) {
        exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),valueNumber);
        valueNumber = signToCompareCode(*exprRecord);
        *loopPtr = valueNumber;
      }
      else {
        if (valueNumber < 1) {
          *loopPtr = 0;
          valueNumber = *(int *)(ctx + 0xb0) + operandRecOffset;
          operandFlags = *(uint *)(valueNumber + 0x20);
          if ((operandFlags & 2) != 0) {
            *loopPtr = DAT_001e61d0[0];
            operandFlags = *(uint *)(valueNumber + 0x20);
          }
        }
        else {
          findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),valueNumber);
          valueNumber = *(int *)(findInPtrSetResult + 0xc);
          *loopPtr = valueNumber;
          operandRecAddr = *(int *)(ctx + 0xb0) + operandRecOffset2;
          operandFlags = *(uint *)(operandRecAddr + 0x20);
          if ((operandFlags & 2) != 0) {
            *loopPtr = (DAT_001e61d0)[valueNumber];
            operandFlags = *(uint *)(operandRecAddr + 0x20);
          }
        }
        if ((operandFlags & 1) != 0) {
          *loopPtr = *(int *)(&DAT_001e61b8 + *loopPtr * 4);
        }
      }
      operandRecOffset2 = operandRecOffset2 + 0x18;
      operandRecOffset = operandRecOffset + 0x18;
      loopPtr = loopPtr + 1;
      valueNumberPtr = valueNumberPtr + 4;
    }
    switch(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8)) {
    case 0x12:
      resultClass = *(int *)(&DAT_001e5ec4 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    case 0x13:
      resultClass = *(int *)(&DAT_001e5c84 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    case 0x14:
      resultClass = *(int *)(&DAT_001e5ec4 +
                      (*(int *)(&DAT_001e5c84 + (operandClass[0] * 6 + operandClass[1]) * 4) * 6 +
                      operandClass[2]) * 4);
      break;
    default:
      resultClass = 0;
      break;
    case 0x17:
      resultClass = *(int *)(&DAT_001e5da4 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    case 0x19:
      resultClass = *(int *)(&DAT_001e5d14 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    case 0x24:
    case 0x25:
    case 0x26:
      resultClass = *(int *)(&DAT_001e5e34 + (operandClass[1] * 6 + operandClass[2]) * 4);
      break;
    case 0x31:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
      resultClass = operandClass[0];
    }
    if (*(int *)(*(int *)(ctx + 0xb0) + 0x120) != 0) {
      resultClass = (DAT_001e61a0)[resultClass];
    }
    laneEntryPtr2 = lane * 4 + ctx;
    laneNode = *(int *)(laneEntryPtr2 + 0x40);
    if (laneNode == 0) {
      laneNode = Compiler__internLaneExpr(*(undefined4 *)(ctx + 0x238),lane,ctx);
      *(int *)(laneEntryPtr2 + 0x40) = laneNode;
    }
    *(int *)(laneNode + 0xc) = resultClass;
  }
  return;
}

/* IRInst__isOpcode8bOr8c @ 0x1789d4 (28 bytes) */
int IRInst__isOpcode8bOr8c(inst)
  int inst;
{
  return *(int *)(*(int *)(inst + 0x88) + 8) - 0x8bU < 2;
}

/* ValueKey__sourcesHaveNoModifiers @ 0x1789f0 (168 bytes) */
int ValueKey__sourcesHaveNoModifiers(ctx)
  int ctx;
{
  int *a0;
  int callResult;
  uint opcodeOffset;
  int loopIndex;
  
  a0 = *(int **)(ctx + 0xb0);
  opcodeOffset = *(int *)(a0[0x22] + 8) - 0x12;
  if ((opcodeOffset < 0x20) && (loopIndex = 1, (1 << (opcodeOffset & 0x3f) & 0x800000a7U) != 0)) {
    while( true ) {
      callResult = (**(code **)(*a0 + 0x14))(a0);
      if (callResult < loopIndex) {
        return 1;
      }
      a0 = *(int **)(ctx + 0xb0);
      if (((a0[loopIndex * 6 + 0x28] & 1U) != 0) || ((a0[loopIndex * 6 + 0x28] & 2U) != 0)) break;
      loopIndex = loopIndex + 1;
    }
  }
  return 0;
}

/* ValueKey__sourceSignKnown @ 0x178a98 (132 bytes) */
int ValueKey__sourceSignKnown(ctx, queriedComponent)
  int ctx;
  int queriedComponent;
{
  if (*(int *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8) == 0x32) {
    if (queriedComponent == 1) {
      return *(uint *)(ctx + 0x178) >> 0x1f;
    }
    if (queriedComponent < 2) {
      if (queriedComponent == 0) {
        return 1;
      }
    }
    else {
      if (queriedComponent == 2) {
        if (((*(int *)(ctx + 0x178) < 0) && (*(int *)(ctx + 0x180) < 0)) &&
           (*(int *)(ctx + 0x184) < 0)) {
          return 1;
        }
        return 0;
      }
      if (queriedComponent == 3) {
        return 1;
      }
    }
  }
  return 0;
}

/* ValueKey__allDotInputsConstant @ 0x178b1c (360 bytes) */
int ValueKey__allDotInputsConstant(ctx)
  int ctx;
{
  bool moreComponents;
  int loopIndex;
  int *loopPtr4;
  undefined4 result;
  int loopIndex2;
  int loopIndex3;
  
  loopPtr4 = *(int **)(ctx + 0xb0);
  loopIndex = *(int *)(loopPtr4[0x22] + 8);
  if (loopIndex == 0x1c) {
    for (loopIndex = 1; loopIndex2 = (**(code **)(*loopPtr4 + 0x14))(loopPtr4), loopIndex <= loopIndex2; loopIndex = loopIndex + 1
        ) {
      loopIndex2 = 0;
      loopPtr4 = (int *)(loopIndex * 0x10 + ctx + 0x168);
      do {
        if (-1 < *loopPtr4) goto LAB_00178b50;
        moreComponents = loopIndex2 != 2;
        loopPtr4 = loopPtr4 + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (moreComponents);
      loopPtr4 = *(int **)(ctx + 0xb0);
    }
LAB_00178bc4:
    result = 1;
  }
  else {
    if (loopIndex < 0x1d) {
      if (loopIndex == 0x18) {
LAB_00178b6c:
        for (loopIndex = 1; loopIndex2 = (**(code **)(*loopPtr4 + 0x14))(loopPtr4), loopIndex <= loopIndex2;
            loopIndex = loopIndex + 1) {
          loopIndex2 = 4;
          loopPtr4 = (int *)(loopIndex * 0x10 + ctx + 0x168);
          do {
            if (-1 < *loopPtr4) goto LAB_00178b50;
            loopPtr4 = loopPtr4 + 1;
            loopIndex2 = loopIndex2 + -1;
          } while (loopIndex2 != 0);
          loopPtr4 = *(int **)(ctx + 0xb0);
        }
        goto LAB_00178bc4;
      }
    }
    else {
      if (loopIndex == 0x1d) goto LAB_00178b6c;
      if (loopIndex == 0x1e) {
        loopIndex = 1;
        loopIndex2 = ctx + 0x170;
        do {
          loopPtr4 = (int *)(loopIndex2 + 8);
          loopIndex3 = 0;
          do {
            if (-1 < *loopPtr4) goto LAB_00178b50;
            moreComponents = loopIndex3 != 1;
            loopPtr4 = loopPtr4 + 1;
            loopIndex3 = loopIndex3 + 1;
          } while (moreComponents);
          moreComponents = loopIndex != 2;
          loopIndex2 = loopIndex2 + 0x10;
          loopIndex = loopIndex + 1;
        } while (moreComponents);
        if (*(int *)(ctx + 0x1a0) < 0) goto LAB_00178bc4;
      }
    }
LAB_00178b50:
    result = 0;
  }
  return result;
}

/* ValueKey__singleLaneValueNumber @ 0x178c84 (244 bytes) */
int ValueKey__singleLaneValueNumber(resultOut, ctx, lane)
  undefined4 *resultOut;
  int ctx;
  int lane;
{
  int valueNumber;
  undefined4 *exprRecord;
  int laneBase;
  int *inst;
  
  inst = *(int **)(ctx + 0xb0);
  if (*(int *)(inst[0x22] + 8) == 0x32) {
    valueNumber = (**(code **)(*inst + 0x14))(inst);
    if (valueNumber == 1) {
      laneBase = lane * 0x10 + ctx;
      valueNumber = *(int *)(laneBase + 0x168);
      if ((valueNumber != *(int *)(laneBase + 0x16c)) || (valueNumber != *(int *)(laneBase + 0x174)))
      goto LAB_00178d10;
    }
    else {
      if (valueNumber != 3) goto LAB_00178d10;
      if (lane == 2) {
        valueNumber = *(int *)(ctx + 0x18c);
      }
      else if (lane == 3) {
        valueNumber = *(int *)(ctx + 0x1a4);
      }
      else {
        if (lane != 1) goto LAB_00178d10;
        valueNumber = *(int *)(ctx + 0x178);
      }
    }
    if (valueNumber < 0) {
      exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),valueNumber);
      *resultOut = *exprRecord;
      return resultOut;
    }
  }
LAB_00178d10:
  *resultOut = 0x7ffffffe;
  return resultOut;
}

/* ValueKey__dotOperandSplatValue @ 0x178d78 (280 bytes) */
int ValueKey__dotOperandSplatValue(resultOut, key, operandNumber)
  undefined4 *resultOut;
  int key;
  int operandNumber;
{
  int operandEntryPtr;
  int opcode;
  undefined4 *exprRecord;
  int splatValueNumber;
  
  opcode = *(int *)(*(int *)(*(int *)(key + 0xb0) + 0x88) + 8);
  if (opcode == 0x1c) {
    operandEntryPtr = operandNumber * 0x10 + key;
    splatValueNumber = *(int *)(operandEntryPtr + 0x168);
    if ((splatValueNumber != *(int *)(operandEntryPtr + 0x16c)) || (splatValueNumber != *(int *)(operandEntryPtr + 0x170))) goto LAB_00178de8;
  }
  else {
    if (opcode < 0x1d) {
      if (opcode != 0x18) goto LAB_00178de8;
    }
    else if (opcode != 0x1d) {
      if (opcode != 0x1e) goto LAB_00178de8;
      if (operandNumber - 1U < 2) {
        operandEntryPtr = operandNumber * 0x10 + key;
        splatValueNumber = *(int *)(operandEntryPtr + 0x168);
        if (splatValueNumber != *(int *)(operandEntryPtr + 0x16c)) goto LAB_00178de8;
      }
      else {
        splatValueNumber = *(int *)(operandNumber * 0x10 + key + 0x170);
      }
      goto LAB_00178e60;
    }
    operandEntryPtr = operandNumber * 0x10 + key;
    splatValueNumber = *(int *)(operandEntryPtr + 0x168);
    if (((splatValueNumber != *(int *)(operandEntryPtr + 0x16c)) || (splatValueNumber != *(int *)(operandEntryPtr + 0x170))) ||
       (splatValueNumber != *(int *)(operandEntryPtr + 0x174))) goto LAB_00178de8;
  }
LAB_00178e60:
  if (splatValueNumber < 0) {
    exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),splatValueNumber);
    *resultOut = *exprRecord;
    return resultOut;
  }
LAB_00178de8:
  *resultOut = 0x7ffffffe;
  return resultOut;
}

/* ValueKey__evalLitLane @ 0x178e90 (468 bytes) */
int ValueKey__evalLitLane(resultOut, key, lane, staleArg4)
  float *resultOut;
  int key;
  int lane;
  uint staleArg4;
{
  float clampHigh;
  float clampedExponent;
  float clampedX;
  float laneOneResult;
  float xValue;
  float *loopPtr;
  int loopRemaining;
  double logOrPow;
  double logTwo;
  float litInputs [15];
  
  loopRemaining = 5;
  loopPtr = litInputs;
  do {
    *loopPtr = GH_U2F(0x7fff0000U);
    loopPtr = loopPtr + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  *resultOut = GH_U2F(0x7fff0000U);
  if (*(int *)(*(int *)(*(int *)(key + 0xb0) + 0x88) + 8) == 0x32) {
    if (lane == 1) {
      loopPtr = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),
                                     *(undefined4 *)(key + 0x178));
      xValue = *loopPtr;
      clampedX = xValue;
      if (xValue < 0.0) {
        clampedX = 0.0;
      }
      laneOneResult = 0.0;
      if (-xValue < 0.0) {
        laneOneResult = clampedX;
      }
      *resultOut = laneOneResult;
    }
    else {
      if (lane < 2) {
        if (lane != 0) {
          return resultOut;
        }
      }
      else {
        if (lane == 2) {
          loopPtr = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),
                                         *(undefined4 *)(key + 0x178));
          litInputs[0] = *loopPtr;
          loopPtr = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),
                                         *(undefined4 *)(key + 0x17c));
          litInputs[1] = *loopPtr;
          if ((0.0 < litInputs[0]) && (0.0 < litInputs[1])) {
            loopPtr = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),
                                           *(undefined4 *)(key + 0x184));
            litInputs[3] = *loopPtr;
            clampedExponent = -128.0;
            if (-128.0 <= litInputs[3]) {
              clampHigh = 128.0;
              if (litInputs[3] - 128.0 < 0.0) {
                clampHigh = litInputs[3];
              }
              clampedExponent = litInputs[3];
              if (-(litInputs[3] - 128.0) < 0.0) {
                clampedExponent = clampHigh;
              }
            }
            logOrPow = _log((double)litInputs[1]);
            logTwo = _log(2.0);
            logOrPow = _pow(2.0,(double)(clampedExponent * (float)(logOrPow / logTwo)));
            *resultOut = (float)logOrPow;
            return resultOut;
          }
          *resultOut = 0.0;
          return resultOut;
        }
        if (lane != 3) {
          return resultOut;
        }
      }
      *resultOut = 1.0;
    }
  }
  return resultOut;
}

/* ValueKey__refreshExprRecordForOperand @ 0x179064 (212 bytes) */
int ValueKey__refreshExprRecordForOperand(ctx, operandIndex)
  int ctx;
  int operandIndex;
{
  byte exprFlags;
  undefined4 destRef;
  int callResult;
  undefined4 operandWord;
  
  (**(code **)(**(int **)(ctx + 0xb0) + 0x48))(*(int **)(ctx + 0xb0),operandIndex);
  operandWord = *(undefined4 *)(operandIndex * 0x18 + *(int *)(ctx + 0xb0) + 0x20);
  callResult = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),operandWord);
  if ((((*(char *)(callResult + 8) != '\0') && (exprFlags = *(byte *)(callResult + 9), (exprFlags & 1) == 0)) &&
      ((exprFlags & 2) == 0)) && (((exprFlags & 4) == 0 && ((exprFlags & 8) == 0)))) {
    return callResult;
  }
  *(undefined1 *)(callResult + 8) = 2;
  destRef = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  *(int *)(callResult + 0x10) = operandIndex;
  *(undefined4 *)(callResult + 0xc) = destRef;
  *(undefined4 *)(callResult + 0x14) = operandWord;
  *(undefined1 *)(callResult + 9) = 0;
  *(undefined4 *)(callResult + 0x1c) = 0;
  *(undefined4 *)(callResult + 0x18) = 0;
  ValueKey__callTargetHook12c(callResult,*(undefined4 *)(ctx + 0x238));
  return callResult;
}

/* ValueKey__insertTempCopyOfOperand @ 0x179138 (240 bytes) */
int ValueKey__insertTempCopyOfOperand(ctx, operandIndex)
  int ctx;
  int operandIndex;
{
  int operandValueNumberPtr;
  int blockPredicate;
  undefined4 operandRef2;
  int operandRef;
  undefined4 arenaAt378;
  int compiler;
  int callResult;
  undefined4 registerMap;
  undefined4 *allocation;
  int tempIndex;
  int *block;
  
  callResult = IRLoadConst__vslot73(0xa2,*(undefined4 *)(ctx + 0x238));
  compiler = *(int *)(ctx + 0x238);
  registerMap = *(undefined4 *)(*(int *)(compiler + 0x6c4) + 0x3ac);
  tempIndex = *(int *)(compiler + 0x3b0) + -1;
  *(int *)(compiler + 0x3b0) = tempIndex;
  operandRef = VRegPool__findOrCreate(registerMap,0x36,tempIndex,0);
  VReg__appendUser(operandRef,callResult);
  block = *(int **)(*(int *)(ctx + 0xb0) + 0x158);
  blockPredicate = (**(code **)(*block + 0x24))(block);
  if (blockPredicate == 0) {
    Block__insertInstBefore(block,*(undefined4 *)(ctx + 0xb0),callResult);
  }
  else {
    Block__appendInst(block[1],callResult);
  }
  if (*(int *)(*(int *)(operandRef + 0x2c) + 4) == 0) {
    arenaAt378 = *(undefined4 *)(*(int *)(ctx + 0x238) + 0x378);
    allocation = (undefined4 *)Arena__alloc(arenaAt378,0x240);
    *allocation = arenaAt378;
    ValueKey__init(allocation + 1,callResult,*(undefined4 *)(ctx + 0x238));
    Block__recordDefinition(block,operandRef,allocation + 1);
  }
  *(undefined4 *)(callResult + 300) = 1;
  *(undefined4 *)(callResult + 0x84) = 1;
  IRInst__setOperandRef(callResult,0,operandRef);
  operandRef2 = *(undefined4 *)(operandIndex * 0x18 + *(int *)(ctx + 0xb0) + 0x8c);
  IRInst__setOperandRef(callResult,1,operandRef2);
  operandValueNumberPtr = operandIndex * 4 + ctx;
  VReg__addUse(operandRef2,1,callResult);
  IRInst__setOperandSource(callResult,1,*(undefined4 *)(operandValueNumberPtr + 0x210),0,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(*(undefined4 *)(ctx + 0xb0),operandIndex,operandRef);
  VReg__addUse(operandRef,operandIndex,*(undefined4 *)(ctx + 0xb0));
  *(int *)(operandValueNumberPtr + 0x210) = callResult;
  return callResult;
}

/* ValueKey__operandDefinitionIsFlagBit8 @ 0x1792f0 (232 bytes) */
int ValueKey__operandDefinitionIsFlagBit8(ctx, operandIndex)
  int ctx;
  int operandIndex;
{
  int *a0;
  int callResult;
  int *elementRef;
  uint lastElementIndex;
  uint vectorFilledCount;
  uint *vector;
  int definingRow;
  
  a0 = *(int **)(ctx + 0xb0);
  vector = *(uint **)(a0[operandIndex * 6 + 0x23] + 0x2c);
  vectorFilledCount = vector[1];
  lastElementIndex = vectorFilledCount - 1;
  if (lastElementIndex < *vector) {
    if (vectorFilledCount <= lastElementIndex) {
      _memset(vectorFilledCount * 4 + vector[2],0,(lastElementIndex - vectorFilledCount) * 4 + 4);
      vector[1] = vectorFilledCount;
      a0 = *(int **)(ctx + 0xb0);
    }
    elementRef = (int *)(lastElementIndex * 4 + vector[2]);
  }
  else {
    elementRef = (int *)Vector__elementRefGrow(vector,lastElementIndex);
    a0 = *(int **)(ctx + 0xb0);
  }
  definingRow = *elementRef;
  callResult = (**(code **)(*a0 + 100))(a0);
  if ((callResult != 0) &&
     (callResult = OpcodeTraits__flagBit8(*(undefined4 *)(*(int *)(*(int *)(definingRow + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(ctx + 0x238)), callResult != 0)) {
    return 1;
  }
  return 0;
}

/* ValueKey__findLaneWithSameValue @ 0x1793d8 (560 bytes) */
int ValueKey__findLaneWithSameValue(ctx, operandIndex, laneEnableFlags)
  int ctx;
  int operandIndex;
  undefined4 laneEnableFlags;
{
  int laneValueNumber2;
  bool isLastLane;
  int operandRecord;
  unsigned int ghidra_home[8] = { ctx, operandIndex, laneEnableFlags, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool moreLanes;
  int laneValueNumber;
  undefined4 *exprRecord;
  int commonValueNumber;
  uint loopIndex4;
  int definingKey;
  char *loopPtr2;
  uint lastIndex;
  int loopIndex;
  int *loopPtr3;
  uint *vector;
  undefined4 absOut;
  undefined4 negatedOut;
  undefined4 absOut2;
  undefined4 negatedOut2 [4];
  
  loopPtr3 = (int *)(operandIndex * 0x10 + ctx + 0x168);
  commonValueNumber = 0;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = laneEnableFlags;
  loopPtr2 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  do {
    if (*loopPtr2 != '\0') {
      if (commonValueNumber == 0) {
        commonValueNumber = *loopPtr3;
      }
      else {
        loopIndex = Ptr__equalNonNull(commonValueNumber,*loopPtr3);
        if (loopIndex == 0) {
          return 4;
        }
      }
    }
    loopPtr2 = loopPtr2 + 1;
    loopPtr3 = loopPtr3 + 1;
  } while (loopPtr2 != &(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
  vector = *(uint **)(*(int *)(operandIndex * 0x18 + *(int *)(ctx + 0xb0) + 0x8c) + 0x2c);
  loopIndex4 = vector[1];
  lastIndex = loopIndex4 - 1;
  if (lastIndex < *vector) {
    if (loopIndex4 <= lastIndex) {
      _memset(loopIndex4 * 4 + vector[2],0,(lastIndex - loopIndex4) * 4 + 4);
      vector[1] = loopIndex4;
    }
    loopPtr3 = (int *)(lastIndex * 4 + vector[2]);
  }
  else {
    loopPtr3 = (int *)Vector__elementRefGrow(vector,lastIndex);
  }
  definingKey = *loopPtr3;
  loopIndex4 = 0;
  loopIndex = definingKey;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(definingKey + 0xb0),0);
    if (*(char *)(loopIndex4 + operandRecord + 0x10) != '\x01') {
      laneValueNumber = *(int *)(loopIndex + 0x20);
      if (laneValueNumber < 0) {
        exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),laneValueNumber);
        IRInst__applyAbsModifier(&absOut,*(undefined4 *)(ctx + 0xb0),operandIndex,*exprRecord);
        IRInst__applyNegateModifier(&negatedOut,*(undefined4 *)(ctx + 0xb0),operandIndex,absOut);
        laneValueNumber = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),negatedOut);
        laneValueNumber = *(int *)(laneValueNumber + 4);
      }
      if (laneValueNumber == commonValueNumber) {
        return loopIndex4;
      }
    }
    moreLanes = loopIndex4 != 3;
    loopIndex = loopIndex + 4;
    loopIndex4 = loopIndex4 + 1;
  } while (moreLanes);
  loopIndex = 0;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),operandIndex);
      loopIndex4 = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
      laneValueNumber2 = *(int *)(loopIndex4 * 4 + definingKey + 0x20);
      if (laneValueNumber2 < 0) {
        exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),laneValueNumber2);
        IRInst__applyAbsModifier(&absOut2,*(undefined4 *)(ctx + 0xb0),operandIndex,*exprRecord);
        IRInst__applyNegateModifier(negatedOut2,*(undefined4 *)(ctx + 0xb0),operandIndex,absOut2);
        laneValueNumber2 = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),negatedOut2[0]);
        laneValueNumber2 = *(int *)(laneValueNumber2 + 4);
      }
      if (laneValueNumber2 == commonValueNumber) {
        return loopIndex4;
      }
    }
    isLastLane = loopIndex == 3;
    loopIndex = loopIndex + 1;
    if (isLastLane) {
      return 4;
    }
  } while( true );
}

/* ValueKey__operandLanesEqual @ 0x179608 (456 bytes) */
int ValueKey__operandLanesEqual(ctx, lane, operandIndex, operandIndex2)
  int ctx;
  int lane;
  int operandIndex;
  int operandIndex2;
{
  byte laneSelect2;
  uint vectorFilledCount2;
  uint vectorFilledCount;
  uint *vector2;
  int inst;
  int operandRecord2;
  int operandRecord;
  byte laneSelect;
  int *elementRef;
  int firstValue;
  int secondValue;
  undefined4 callResult;
  uint lastElementIndex;
  uint lastElementIndex2;
  uint *vector;
  
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),operandIndex);
  laneSelect = *(byte *)(lane + operandRecord + 0x10);
  firstValue = *(int *)((operandIndex * 4 + lane) * 4 + ctx + 0x168);
  if (firstValue < 0) {
    inst = *(int *)(ctx + 0xb0);
    if (*(int *)(*(int *)(inst + 0x88) + 8) != 0x8e) {
      vector = *(uint **)(*(int *)(operandIndex * 0x18 + inst + 0x8c) + 0x2c);
      vectorFilledCount2 = vector[1];
      lastElementIndex = vectorFilledCount2 - 1;
      if (lastElementIndex < *vector) {
        if (vectorFilledCount2 <= lastElementIndex) {
          _memset(vectorFilledCount2 * 4 + vector[2],0,(lastElementIndex - vectorFilledCount2) * 4 + 4);
          vector[1] = vectorFilledCount2;
          inst = *(int *)(ctx + 0xb0);
        }
        elementRef = (int *)(lastElementIndex * 4 + vector[2]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector,lastElementIndex);
        inst = *(int *)(ctx + 0xb0);
      }
      firstValue = *(int *)((uint)laneSelect * 4 + *elementRef + 0x20);
    }
  }
  else {
    inst = *(int *)(ctx + 0xb0);
  }
  operandRecord2 = IRInst__getOperandRecord(inst,operandIndex2);
  laneSelect2 = *(byte *)(lane + operandRecord2 + 0x10);
  secondValue = *(int *)((operandIndex2 * 4 + lane) * 4 + ctx + 0x168);
  if ((secondValue < 0) && (*(int *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8) != 0x8e)) {
    vector2 = *(uint **)(*(int *)(operandIndex2 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c) + 0x2c);
    vectorFilledCount = vector2[1];
    lastElementIndex2 = vectorFilledCount - 1;
    if (lastElementIndex2 < *vector2) {
      if (vectorFilledCount <= lastElementIndex2) {
        _memset(vectorFilledCount * 4 + vector2[2],0,(lastElementIndex2 - vectorFilledCount) * 4 + 4);
        vector2[1] = vectorFilledCount;
      }
      elementRef = (int *)(lastElementIndex2 * 4 + vector2[2]);
    }
    else {
      elementRef = (int *)Vector__elementRefGrow(vector2,lastElementIndex2);
    }
    secondValue = *(int *)((uint)laneSelect2 * 4 + *elementRef + 0x20);
  }
  callResult = Ptr__equalNonNull(firstValue,secondValue);
  return callResult;
}

/* ValueKey__forwardSource3LaneIfEqual @ 0x1797d0 (196 bytes) */
int ValueKey__forwardSource3LaneIfEqual(ctx, lane)
  int ctx;
  int lane;
{
  int laneBase;
  int inst;
  uint word0xd0Bit0;
  int lanesEqual;
  undefined4 exprRecordForValueNumberResult;
  uint word0xe8Flags;
  
  lanesEqual = ((int (*)())ValueKey__operandLanesEqual)(ctx,lane,2,3);
  if (lanesEqual != 0) {
    inst = *(int *)(ctx + 0xb0);
    word0xe8Flags = *(uint *)(inst + 0xe8);
    word0xd0Bit0 = *(uint *)(inst + 0xd0) & 1;
    if ((word0xd0Bit0 == (word0xe8Flags & 1)) && ((*(uint *)(inst + 0xd0) >> 1 & 1) == (word0xe8Flags >> 1 & 1))) {
      if ((*(int *)(inst + 0x120) == 0) &&
         (((*(int *)(inst + 0x124) == 0 && (word0xd0Bit0 == 0)) && ((word0xe8Flags & 2) == 0)))) {
        laneBase = lane * 4 + ctx;
        exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(laneBase + 0x198));
        *(undefined4 *)(laneBase + 0x30) = exprRecordForValueNumberResult;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* ValueKey__foldCompareSameSourcesValueNumber @ 0x179894 (184 bytes) */
int ValueKey__foldCompareSameSourcesValueNumber(ctx, lane)
  int ctx;
  int lane;
{
  int compareHolds;
  int inst;
  undefined4 exprRecord;
  int lanesEqual;
  undefined4 resultBits;
  
  lanesEqual = ((int (*)())ValueKey__operandLanesEqual)(ctx,lane,1,2);
  if (lanesEqual != 0) {
    inst = *(int *)(ctx + 0xb0);
    if (((*(uint *)(inst + 0xb8) & 1) == (*(uint *)(inst + 0xd0) & 1)) &&
       ((*(uint *)(inst + 0xb8) >> 1 & 1) == (*(uint *)(inst + 0xd0) >> 1 & 1))) {
      compareHolds = ((bool (*)())evaluateCompareFloats)(inst,(double)FLOAT_001aa0d4,(double)FLOAT_001aa0d4);
      resultBits = 0x3f800000;
      if (compareHolds == 0) {
        resultBits = 0;
      }
      exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),resultBits);
      *(undefined4 *)(lane * 4 + ctx + 0x30) = exprRecord;
      return 1;
    }
  }
  return 0;
}

/* ValueKey__forwardSelectedSourceBySign @ 0x17994c (232 bytes) */
int ValueKey__forwardSelectedSourceBySign(ctx, lane)
  int ctx;
  int lane;
{
  int valueNumber;
  uint word0xb8Flags;
  int lanesEqual;
  int *exprRecord;
  undefined4 exprRecordForValueNumberResult;
  uint word0xd0Flags;
  int laneBase;
  
  lanesEqual = ((int (*)())ValueKey__operandLanesEqual)(ctx,lane,1,2);
  if (lanesEqual != 0) {
    word0xd0Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    word0xb8Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((word0xb8Flags & 1) != (word0xd0Flags & 1)) && ((word0xb8Flags >> 1 & 1) == (word0xd0Flags >> 1 & 1))) {
      laneBase = lane * 4 + ctx;
      valueNumber = *(int *)(laneBase + 0x178);
      if (valueNumber < 0) {
        exprRecord = (int *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),valueNumber);
        if ((*(int *)(*(int *)(ctx + 0xb0) + 0x120) == 0) &&
           (*(int *)(*(int *)(ctx + 0xb0) + 0x124) == 0)) {
          exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),
                               *(undefined4 *)
                                (((1 - (*exprRecord >> 0x1f)) * 4 + lane) * 4 + ctx + 0x168));
          *(undefined4 *)(laneBase + 0x30) = exprRecordForValueNumberResult;
          return 1;
        }
        return 1;
      }
    }
  }
  return 0;
}

/* ValueKey__forwardSelectedSourceByPositive @ 0x179a34 (244 bytes) */
int ValueKey__forwardSelectedSourceByPositive(ctx, lane)
  int ctx;
  int lane;
{
  int selectedOperand;
  int valueNumber;
  uint word0xb8Flags;
  int lanesEqual;
  int *exprRecord;
  undefined4 exprRecordForValueNumberResult;
  uint word0xd0Flags;
  
  lanesEqual = ((int (*)())ValueKey__operandLanesEqual)(ctx,lane,1,2);
  if (lanesEqual != 0) {
    word0xd0Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    word0xb8Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((word0xb8Flags & 1) != (word0xd0Flags & 1)) && ((word0xb8Flags >> 1 & 1) == (word0xd0Flags >> 1 & 1))) {
      valueNumber = *(int *)(lane * 4 + ctx + 0x178);
      if (valueNumber < 0) {
        exprRecord = (int *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),valueNumber);
        selectedOperand = 1;
        if (0 < *exprRecord) {
          selectedOperand = 2;
        }
        if ((*(int *)(*(int *)(ctx + 0xb0) + 0x120) == 0) &&
           (*(int *)(*(int *)(ctx + 0xb0) + 0x124) == 0)) {
          exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),
                               *(undefined4 *)((selectedOperand * 4 + lane) * 4 + ctx + 0x168));
          *(undefined4 *)(lane * 4 + ctx + 0x30) = exprRecordForValueNumberResult;
          return 1;
        }
        return 1;
      }
    }
  }
  return 0;
}

/* ValueKey__foldLaneToZeroIfOppositeNegates @ 0x179b28 (148 bytes) */
int ValueKey__foldLaneToZeroIfOppositeNegates(ctx, lane)
  int ctx;
  int lane;
{
  uint word0xb8Flags;
  int callResult;
  undefined4 exprRecord;
  uint word0xd0Flags;
  
  callResult = ((int (*)())ValueKey__operandLanesEqual)(ctx,lane,1,2);
  if (callResult != 0) {
    word0xd0Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    word0xb8Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((word0xb8Flags & 1) != (word0xd0Flags & 1)) && ((word0xb8Flags >> 1 & 1) == (word0xd0Flags >> 1 & 1))) {
      exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0);
      *(undefined4 *)(lane * 4 + ctx + 0x30) = exprRecord;
      return 1;
    }
  }
  return 0;
}

/* ValueKey__allOperandLanesEqual @ 0x179bbc (136 bytes) */
int ValueKey__allOperandLanesEqual(ctx, lane)
  int ctx;
  undefined4 lane;
{
  int loopIndex;
  int callResult;
  
  loopIndex = *(int *)(*(int *)(ctx + 0xb0) + 0x84);
  if ((loopIndex != 1) && (1 < loopIndex)) {
    loopIndex = 2;
    do {
      callResult = ((int (*)())ValueKey__operandLanesEqual)(ctx,lane,loopIndex + -1,loopIndex);
      if (callResult == 0) {
        return 0;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex <= *(int *)(*(int *)(ctx + 0xb0) + 0x84));
  }
  return 1;
}

/* Inst__allWrittenLanesSatisfy @ 0x179c44 (124 bytes) */
int Inst__allWrittenLanesSatisfy(valueKey, operandA, operandB)
  int valueKey;
  undefined4 operandA;
  undefined4 operandB;
{
  int equalResult;
  bool lastLane;
  int operandRecord;
  int loopIndex;
  
  loopIndex = 0;
  while ((operandRecord = IRInst__getOperandRecord(*(undefined4 *)(valueKey + 0xb0),0),
         *(char *)(loopIndex + operandRecord + 0x10) == '\x01' ||
         (equalResult = ((int (*)())ValueKey__operandLanesEqual)(valueKey,loopIndex,operandA,operandB), equalResult != 0))) {
    lastLane = loopIndex == 3;
    loopIndex = loopIndex + 1;
    if (lastLane) {
      return 1;
    }
  }
  return 0;
}

/* ValueKey__forwardOtherSourceIfZero @ 0x179cc0 (240 bytes) */
int ValueKey__forwardOtherSourceIfZero(ctx, lane)
  int ctx;
  int lane;
{
  bool lastOperand;
  uint operandModifiers;
  int laneBase;
  int *operandConstant;
  undefined4 exprRecordForValueNumberResult;
  int member0xb0;
  int loopIndex;
  int *valueNumberPtr;
  
  loopIndex = 1;
  laneBase = lane * 4 + ctx;
  valueNumberPtr = (int *)(laneBase + 0x178);
  while ((-1 < *valueNumberPtr ||
         (operandConstant = (int *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*valueNumberPtr), *operandConstant != 0))) {
    lastOperand = loopIndex == 2;
    valueNumberPtr = valueNumberPtr + 4;
    loopIndex = loopIndex + 1;
    if (lastOperand) {
      return 0;
    }
  }
  member0xb0 = *(int *)(ctx + 0xb0);
  loopIndex = (loopIndex == 1) + 1;
  if ((((*(int *)(member0xb0 + 0x120) == 0) && (*(int *)(member0xb0 + 0x124) == 0)) &&
      (operandModifiers = *(uint *)(loopIndex * 0x18 + member0xb0 + 0xa0), (operandModifiers & 1) == 0)) && ((operandModifiers & 2) == 0)) {
    exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),
                         *(undefined4 *)((loopIndex * 4 + lane) * 4 + ctx + 0x168));
    *(undefined4 *)(laneBase + 0x30) = exprRecordForValueNumberResult;
    return 1;
  }
  return 1;
}

/* ValueKey__forwardAddendIfMultiplicandZero @ 0x179db0 (196 bytes) */
int ValueKey__forwardAddendIfMultiplicandZero(ctx, lane)
  int ctx;
  int lane;
{
  bool lastOperand;
  int laneBase;
  int *operandConstant;
  undefined4 exprRecordForValueNumberResult;
  int loopIndex;
  int *valueNumberPtr;
  
  laneBase = lane * 4 + ctx;
  valueNumberPtr = (int *)(laneBase + 0x178);
  loopIndex = 1;
  while ((-1 < *valueNumberPtr ||
         (operandConstant = (int *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*valueNumberPtr), *operandConstant != 0))) {
    lastOperand = loopIndex == 2;
    valueNumberPtr = valueNumberPtr + 4;
    loopIndex = loopIndex + 1;
    if (lastOperand) {
      return 0;
    }
  }
  loopIndex = *(int *)(ctx + 0xb0);
  if ((((*(int *)(loopIndex + 0x120) == 0) && (*(int *)(loopIndex + 0x124) == 0)) &&
      ((*(uint *)(loopIndex + 0xe8) & 1) == 0)) && ((*(uint *)(loopIndex + 0xe8) & 2) == 0)) {
    exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(laneBase + 0x198));
    *(undefined4 *)(laneBase + 0x30) = exprRecordForValueNumberResult;
    return 1;
  }
  return 1;
}

/* ValueKey__forwardSource1LaneIfEqual @ 0x179e74 (196 bytes) */
int ValueKey__forwardSource1LaneIfEqual(ctx, lane)
  int ctx;
  int lane;
{
  int laneBase;
  int inst;
  int lanesEqual;
  undefined4 exprRecordForValueNumberResult;
  uint word0xb8Flags;
  
  lanesEqual = ((int (*)())ValueKey__operandLanesEqual)(ctx,lane,1,2);
  if (lanesEqual != 0) {
    inst = *(int *)(ctx + 0xb0);
    word0xb8Flags = *(uint *)(inst + 0xb8);
    if (((word0xb8Flags & 1) == (*(uint *)(inst + 0xd0) & 1)) &&
       ((word0xb8Flags >> 1 & 1) == (*(uint *)(inst + 0xd0) >> 1 & 1))) {
      if ((*(int *)(inst + 0x120) == 0) &&
         (((*(int *)(inst + 0x124) == 0 && ((word0xb8Flags & 1) == 0)) && ((word0xb8Flags & 2) == 0)))) {
        laneBase = lane * 4 + ctx;
        exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(laneBase + 0x178));
        *(undefined4 *)(laneBase + 0x30) = exprRecordForValueNumberResult;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* ValueKey__forwardOtherSourceIfOne @ 0x179f38 (252 bytes) */
int ValueKey__forwardOtherSourceIfOne(ctx, lane)
  int ctx;
  int lane;
{
  bool lastOperand;
  uint operandModifiers;
  int laneBase;
  float *operandConstant;
  undefined4 exprRecordForValueNumberResult;
  int member0xb0;
  int loopIndex;
  int *valueNumberPtr;
  
  loopIndex = 1;
  laneBase = lane * 4 + ctx;
  valueNumberPtr = (int *)(laneBase + 0x178);
  while ((-1 < *valueNumberPtr ||
         (operandConstant = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*valueNumberPtr), *operandConstant != 1.0))
        ) {
    lastOperand = loopIndex == 2;
    valueNumberPtr = valueNumberPtr + 4;
    loopIndex = loopIndex + 1;
    if (lastOperand) {
      return 0;
    }
  }
  member0xb0 = *(int *)(ctx + 0xb0);
  loopIndex = (loopIndex == 1) + 1;
  if ((*(int *)(member0xb0 + 0x120) == 0) &&
     (((*(int *)(member0xb0 + 0x124) == 0 &&
       (operandModifiers = *(uint *)(loopIndex * 0x18 + member0xb0 + 0xa0), (operandModifiers & 1) == 0)) && ((operandModifiers & 2) == 0))))
  {
    exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),
                         *(undefined4 *)((loopIndex * 4 + lane) * 4 + ctx + 0x168));
    *(undefined4 *)(laneBase + 0x30) = exprRecordForValueNumberResult;
    return 1;
  }
  return 1;
}

/* ValueKey__forwardOperandByCompareToZero @ 0x17a034 (252 bytes) */
int ValueKey__forwardOperandByCompareToZero(ctx, lane)
  int ctx;
  int lane;
{
  int selectedValueNumber;
  int selectedOperand;
  undefined4 findInPtrSetResult;
  undefined4 exprRecordForValueNumberResult;
  undefined4 result;
  uint selectedOperandFlags;
  float *exprRecord2;
  float *exprRecord;
  int compareHolds;
  int member0xb0;
  int laneBase;
  
  laneBase = lane * 4 + ctx;
  result = 0;
  if (*(int *)(laneBase + 0x178) < 0) {
    exprRecord2 = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(int *)(laneBase + 0x178));
    exprRecord = (float *)Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0);
    compareHolds = ((bool (*)())evaluateCompareFloats)(*(undefined4 *)(ctx + 0xb0),(double)*exprRecord2,(double)*exprRecord);
    member0xb0 = *(int *)(ctx + 0xb0);
    selectedOperand = (compareHolds == 0) + 2;
    if ((((*(int *)(member0xb0 + 0x120) == 0) && (*(int *)(member0xb0 + 0x124) == 0)) &&
        (selectedOperandFlags = *(uint *)(selectedOperand * 0x18 + member0xb0 + 0xa0), (selectedOperandFlags & 1) == 0)) && ((selectedOperandFlags & 2) == 0)) {
      selectedValueNumber = *(int *)((selectedOperand * 4 + lane) * 4 + ctx + 0x168);
      if (selectedValueNumber < 0) {
        exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),selectedValueNumber);
        *(undefined4 *)(laneBase + 0x30) = exprRecordForValueNumberResult;
        return 1;
      }
      findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),selectedValueNumber);
      *(undefined4 *)(laneBase + 0x40) = findInPtrSetResult;
      return 1;
    }
    result = 1;
  }
  return result;
}

/* ValueKey__setLiteralVec4Operand @ 0x17a130 (284 bytes) */
int ValueKey__setLiteralVec4Operand(operandIndex, vec4Constant, inst, compiler)
  int operandIndex;
  float *vec4Constant;
  int inst;
  int compiler;
{
  int operandRecord;
  undefined4 arenaAt378;
  int *vector;
  undefined4 *allocation;
  int operandRef;
  undefined4 dummySelectWord;
  int vectorCapacity;
  undefined4 *newValueKey;
  
  dummySelectWord = DAT_001b01d8;
  if (operandIndex == 0) {
    *(undefined4 *)(inst + 0x9c) = DAT_001b01d8;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    *(undefined4 *)(operandRecord + 0x10) = dummySelectWord;
  }
  ((void (*)())IRInst__makeLiteralVec4Float)(inst,*(undefined4 *)(compiler + COMP_currentProgram),operandIndex,(double)*vec4Constant,(double)vec4Constant[1],
               (double)vec4Constant[2],(double)vec4Constant[3]);
  vector = *(int **)(*(int *)(operandIndex * 0x18 + inst + 0x8c) + 0x18);
  if (*vector == 0) {
    vector = (int *)Vector__elementRefGrow(vector,0);
  }
  else {
    if (vector[1] == 0) {
      *(undefined4 *)vector[2] = 0;
      vector[1] = 1;
    }
    vector = (int *)vector[2];
  }
  vectorCapacity = *vector;
  operandRef = *(int *)(vectorCapacity + 0x8c);
  if (*(int *)(*(int *)(operandRef + 0x2c) + 4) == 0) {
    arenaAt378 = *(undefined4 *)(compiler + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arenaAt378,0x240);
    newValueKey = allocation + 1;
    *allocation = arenaAt378;
    ValueKey__init(newValueKey,vectorCapacity,compiler);
    ValueKey__computeLaneFlags(newValueKey);
    ValueKey__propagateLaneValues(newValueKey);
    VReg__pushDefinition(operandRef,*(undefined4 *)(*(int *)(vectorCapacity + 0x158) + 0xb0),newValueKey);
  }
  IRInst__setOperandRef(inst,operandIndex,operandRef);
  return vectorCapacity;
}

/* ValueKey__setLiteralOperandsForOpcode @ 0x17a294 (320 bytes) */
int ValueKey__setLiteralOperandsForOpcode(ctx, vec4Constant, compiler)
  int ctx;
  float *vec4Constant;
  int compiler;
{
  int opcode;
  int member0xb0;
  undefined4 operandValueNumber;
  undefined4 secondVec4X;
  undefined4 secondVec4Y;
  undefined4 secondVec4Z;
  undefined4 secondVec4W;
  
  member0xb0 = *(int *)(ctx + 0xb0);
  opcode = *(int *)(*(int *)(member0xb0 + 0x88) + 8);
  if (opcode == 0x8b) {
    IRInst__initOperandRecord(member0xb0,1);
    operandValueNumber = ((int (*)())ValueKey__setLiteralVec4Operand)(1,vec4Constant,*(undefined4 *)(ctx + 0xb0),compiler);
    *(undefined4 *)(ctx + 0x214) = operandValueNumber;
    ((void (*)())IRInst__makeLiteralVec4Float)(*(undefined4 *)(ctx + 0xb0),*(undefined4 *)(compiler + 0x6c4),1,(double)*vec4Constant
                 ,(double)vec4Constant[1],(double)vec4Constant[2],(double)vec4Constant[3]);
    IRInst__initOperandRecord(*(undefined4 *)(ctx + 0xb0),2);
    secondVec4Y = DAT_001b01ec;
    secondVec4X = DAT_001b01e8;
    secondVec4Z = DAT_001b01f0;
    secondVec4W = DAT_001b01f4;
    operandValueNumber = ((int (*)())ValueKey__setLiteralVec4Operand)(2,&secondVec4X,*(undefined4 *)(ctx + 0xb0),compiler);
    *(undefined4 *)(ctx + 0x218) = operandValueNumber;
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 300) = 0;
  }
  else if (opcode == 0x8c) {
    IRInst__initOperandRecord(member0xb0,1);
    operandValueNumber = ((int (*)())ValueKey__setLiteralVec4Operand)(1,vec4Constant,*(undefined4 *)(ctx + 0xb0),compiler);
    *(undefined4 *)(ctx + 0x214) = operandValueNumber;
    ((void (*)())IRInst__makeLiteralVec4Float)(*(undefined4 *)(ctx + 0xb0),*(undefined4 *)(compiler + 0x6c4),1,(double)*vec4Constant
                 ,(double)vec4Constant[1],(double)vec4Constant[2],(double)vec4Constant[3]);
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 300) = 0;
  }
  return;
}

/* ValueKey__foldCompareOfFloatConstants @ 0x17a3d4 (884 bytes) */
int ValueKey__foldCompareOfFloatConstants(ctx)
  int ctx;
{
  int operandRecAddr;
  int operandClass;
  int firstOperandClass;
  bool isLastLane;
  bool branchTaken;
  int findInPtrSetResult;
  bool moreOperands;
  bool allOperandsFloatConst;
  float foldedResult;
  uint operandFlags;
  float laneResult;
  float *loopPtr3;
  float *loopPtr4;
  int loopIndex2;
  float *exprRecord;
  int compareClass;
  int valueNumber;
  float *laneResults;
  int operandRecOffset;
  int *valueNumberPtr;
  int *loopPtr5;
  bool usedUniformConstant;
  int loopIndex;
  int loopRemaining;
  int operandClasses [2];
  float laneConstants [9];
  int lanesAgree;
  
  loopIndex = 4;
  laneResults = laneConstants + 3;
  loopPtr3 = laneResults;
  do {
    *loopPtr3 = GH_U2F(0x7fff0000U);
    loopPtr3 = loopPtr3 + 1;
    loopIndex = loopIndex + -1;
  } while (loopIndex != 0);
  loopIndex = 0;
  loopRemaining = 4;
  do {
    *(undefined4 *)(loopIndex + (int)laneResults) = 0;
    loopIndex = loopIndex + 4;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  usedUniformConstant = false;
  lanesAgree = 1;
  loopIndex = 0;
  loopRemaining = ctx + 0x170;
  loopPtr3 = laneResults;
  foldedResult = FLOAT_001aa114;
  do {
    loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    loopPtr4 = laneConstants;
    if (*(char *)(loopIndex + loopIndex2 + 0x10) != '\x01') {
      do {
        *loopPtr4 = GH_U2F(0x7fff0000U);
        loopPtr4 = loopPtr4 + 1;
      } while (laneResults != loopPtr4);
      valueNumberPtr = (int *)(loopRemaining + 8);
      allOperandsFloatConst = true;
      loopIndex2 = 1;
      loopPtr5 = operandClasses;
      operandRecOffset = 0x98;
      loopPtr4 = laneConstants;
      do {
        loopPtr4 = loopPtr4 + 1;
        *loopPtr5 = 0;
        valueNumber = *valueNumberPtr;
        if (valueNumber < 0) {
          exprRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),valueNumber);
          *loopPtr4 = *exprRecord;
          operandClass = signToCompareCode(*(unsigned int *)exprRecord);
          *loopPtr5 = operandClass;
        }
        else {
          if (valueNumber < 1) {
            return 0;
          }
          findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),valueNumber);
          compareClass = *(int *)(findInPtrSetResult + 0xc);
          *loopPtr5 = compareClass;
          operandRecAddr = *(int *)(ctx + 0xb0) + operandRecOffset;
          operandFlags = *(uint *)(operandRecAddr + 0x20);
          if ((operandFlags & 2) != 0) {
            *loopPtr5 = (DAT_001e61d0)[compareClass];
            operandFlags = *(uint *)(operandRecAddr + 0x20);
          }
          if ((operandFlags & 1) == 0) {
            operandClass = *loopPtr5;
            usedUniformConstant = true;
            allOperandsFloatConst = false;
          }
          else {
            usedUniformConstant = true;
            allOperandsFloatConst = false;
            operandClass = *(int *)(&DAT_001e61b8 + *loopPtr5 * 4);
            *loopPtr5 = operandClass;
          }
        }
        firstOperandClass = operandClasses[0];
        if (operandClass == 0) {
          return 0;
        }
        moreOperands = loopIndex2 != 2;
        operandRecOffset = operandRecOffset + 0x18;
        loopPtr5 = loopPtr5 + 1;
        valueNumberPtr = valueNumberPtr + 4;
        loopIndex2 = loopIndex2 + 1;
      } while (moreOperands);
      if (allOperandsFloatConst) {
        loopIndex2 = ((bool (*)())evaluateCompareFloats)(*(undefined4 *)(ctx + 0xb0),(double)laneConstants[1],(double)laneConstants[2]
                            );
        laneResult = 0.0;
        if (loopIndex2 == 0) {
LAB_0017a608:
          laneResult = 1.0;
        }
        *loopPtr3 = laneResult;
      }
      else {
        loopIndex2 = IRInst__getCompareCondition(*(undefined4 *)(ctx + 0xb0));
        loopIndex2 = *(int *)(&DAT_001e61e8 + (loopIndex2 * 6 + firstOperandClass * 0x30 + operandClasses[1]) * 4);
        if (loopIndex2 == 1) {
          *loopPtr3 = 0.0;
        }
        else {
          if (loopIndex2 == 2) goto LAB_0017a608;
          if (loopIndex2 == 0) {
            return 0;
          }
        }
      }
      if (foldedResult == FLOAT_001aa114) {
        foldedResult = *loopPtr3;
      }
      else if (*loopPtr3 != foldedResult) {
        lanesAgree = 0;
      }
    }
    isLastLane = loopIndex == 3;
    loopRemaining = loopRemaining + 4;
    loopPtr3 = loopPtr3 + 1;
    loopIndex = loopIndex + 1;
    if (isLastLane) {
      if (usedUniformConstant) {
        loopIndex = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
        *(int *)(loopIndex + 0x134) = *(int *)(loopIndex + 0x134) + 1;
      }
      ((int (*)())ValueKey__setLiteralOperandsForOpcode)(ctx,laneResults,*(undefined4 *)(ctx + 0x238));
      loopIndex = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),0xd);
      if ((loopIndex != 0) && (lanesAgree != 0)) {
        loopPtr5 = *(int **)(*(int *)(ctx + 0xb0) + 0x158);
        branchTaken = foldedResult != FLOAT_001aa0d4;
        loopIndex = (**(code **)(*loopPtr5 + 0x24))(loopPtr5);
        if (loopIndex != 0) {
          if (branchTaken) {
            loopIndex = loopPtr5[0x4d];
          }
          else {
            loopIndex = loopPtr5[0x4e];
          }
          Program__removeDeadRegion(*(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4),loopPtr5,loopIndex,
                       loopPtr5[0x4f]);
          if (branchTaken) {
            loopIndex = 2;
          }
          else {
            loopIndex = 1;
          }
          loopPtr5[0x53] = loopIndex;
          return 1;
        }
      }
      return 1;
    }
  } while( true );
}

/* ValueKey__foldEqualSourcesCompareToLiteralOperands @ 0x17a748 (348 bytes) */
int ValueKey__foldEqualSourcesCompareToLiteralOperands(ctx)
  int ctx;
{
  int operandRecord;
  bool notLastLane;
  uint word0xb8Flags;
  undefined4 *loopPtr2;
  int loopRemaining;
  int compareCondition;
  uint word0xd0Flags;
  undefined4 *loopPtr3;
  int loopIndex;
  undefined4 replacementVec4 [8];
  
  loopRemaining = ((int (*)())Inst__allWrittenLanesSatisfy)(ctx,1,2);
  if (loopRemaining != 0) {
    word0xd0Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    word0xb8Flags = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((word0xb8Flags & 1) == (word0xd0Flags & 1)) && ((word0xb8Flags >> 1 & 1) == (word0xd0Flags >> 1 & 1))) {
      loopPtr3 = replacementVec4;
      loopRemaining = 4;
      loopPtr2 = loopPtr3;
      do {
        *loopPtr2 = 0x7ffffffe;
        loopPtr2 = loopPtr2 + 1;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
      loopRemaining = 0;
      loopIndex = 4;
      do {
        *(undefined4 *)(loopRemaining + (int)loopPtr3) = 0;
        loopRemaining = loopRemaining + 4;
        loopIndex = loopIndex + -1;
      } while (loopIndex != 0);
      loopRemaining = signToCompareCode(0);
      loopIndex = 0;
      do {
        operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
          compareCondition = IRInst__getCompareCondition(*(undefined4 *)(ctx + 0xb0));
          if (*(int *)(&DAT_001e61e8 + (compareCondition * 6 + loopRemaining * 0x31) * 4) == 1) {
            *loopPtr3 = 0;
          }
          else if (*(int *)(&DAT_001e61e8 + (compareCondition * 6 + loopRemaining * 0x31) * 4) == 2) {
            *loopPtr3 = 0x3f800000;
          }
        }
        notLastLane = loopIndex != 3;
        loopPtr3 = loopPtr3 + 1;
        loopIndex = loopIndex + 1;
      } while (notLastLane);
      ((int (*)())ValueKey__setLiteralOperandsForOpcode)(ctx,replacementVec4,*(undefined4 *)(ctx + 0x238));
      ValueKey__rebuild(ctx);
      return 1;
    }
  }
  return 0;
}

/* ValueKey__foldCompareAgainstZero @ 0x17a8a4 (680 bytes) */
int ValueKey__foldCompareAgainstZero(ctx)
  int ctx;
{
  int compareCondition;
  int findInPtrSetResult;
  int operandRecord;
  bool moreLanes;
  float foldedResult;
  bool usedUniformConstant;
  bool lanesAgree;
  uint *loopPtr2;
  int compareResultOrClass;
  undefined4 *exprRecord;
  int inst;
  int laneByteOffset;
  int loopIndex;
  int *blockRef;
  int loopRemaining;
  int loopRemaining2;
  uint laneResults;
  
  loopRemaining = 4;
  loopPtr2 = &laneResults;
  do {
    *loopPtr2 = 0x7ffffffe;
    loopPtr2 = loopPtr2 + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  loopRemaining = 0;
  loopRemaining2 = 4;
  do {
    *(undefined4 *)(loopRemaining + (int)&laneResults) = 0;
    loopRemaining = loopRemaining + 4;
    loopRemaining2 = loopRemaining2 + -1;
  } while (loopRemaining2 != 0);
  loopRemaining2 = signToCompareCode(0);
  usedUniformConstant = false;
  foldedResult = -1.0;
  lanesAgree = true;
  loopIndex = 0;
  laneByteOffset = 0;
  loopRemaining = ctx;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      compareResultOrClass = *(int *)(loopRemaining + 0x178);
      if (compareResultOrClass < 0) {
        exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),compareResultOrClass);
        compareResultOrClass = signToCompareCode(*exprRecord);
        inst = *(int *)(ctx + 0xb0);
      }
      else {
        if (compareResultOrClass < 1) {
          return 0;
        }
        findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),compareResultOrClass);
        inst = *(int *)(ctx + 0xb0);
        compareResultOrClass = *(int *)(findInPtrSetResult + 0xc);
        if ((*(uint *)(inst + 0xb8) & 2) != 0) {
          compareResultOrClass = (DAT_001e61d0)[compareResultOrClass];
        }
        usedUniformConstant = true;
        if ((*(uint *)(inst + 0xb8) & 1) != 0) {
          compareResultOrClass = *(int *)(&DAT_001e61b8 + compareResultOrClass * 4);
        }
      }
      compareCondition = IRInst__getCompareCondition(inst);
      compareResultOrClass = *(int *)(&DAT_001e61e8 + (compareCondition * 6 + compareResultOrClass * 0x30 + loopRemaining2) * 4);
      if (compareResultOrClass == 1) {
        *(undefined4 *)(laneByteOffset + (int)&laneResults) = 0;
      }
      else if (compareResultOrClass == 2) {
        *(undefined4 *)(laneByteOffset + (int)&laneResults) = 0x3f800000;
      }
      else if (compareResultOrClass == 0) {
        return 0;
      }
      if (foldedResult == -1.0) {
        foldedResult = *(float *)(laneByteOffset + (int)&laneResults);
      }
      else if (*(float *)(laneByteOffset + (int)&laneResults) != foldedResult) {
        lanesAgree = false;
      }
    }
    moreLanes = loopIndex != 3;
    laneByteOffset = laneByteOffset + 4;
    loopRemaining = loopRemaining + 4;
    loopIndex = loopIndex + 1;
  } while (moreLanes);
  if (usedUniformConstant) {
    loopRemaining = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
    *(int *)(loopRemaining + 0x134) = *(int *)(loopRemaining + 0x134) + 1;
  }
  ((int (*)())ValueKey__setLiteralOperandsForOpcode)(ctx,&laneResults,*(undefined4 *)(ctx + 0x238));
  loopRemaining = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),0xd);
  if ((loopRemaining != 0) && (lanesAgree)) {
    blockRef = *(int **)(*(int *)(ctx + 0xb0) + 0x158);
    loopRemaining = (**(code **)(*blockRef + 0x24))(blockRef);
    if (loopRemaining != 0) {
      if (foldedResult != 0.0) {
        loopRemaining = blockRef[0x4d];
      }
      else {
        loopRemaining = blockRef[0x4e];
      }
      Program__removeDeadRegion(*(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4),blockRef,loopRemaining,blockRef[0x4f]);
      if (foldedResult != 0.0) {
        loopRemaining = 2;
      }
      else {
        loopRemaining = 1;
      }
      blockRef[0x53] = loopRemaining;
      return 1;
    }
  }
  return 1;
}

/* ValueKey__foldDotPowerOfTwoIntoOutputScale @ 0x17ab4c (472 bytes) */
int ValueKey__foldDotPowerOfTwoIntoOutputScale(ctx)
  int ctx;
{
  int operandRecAddr;
  int keyInst;
  bool moreOperands;
  bool notNegative;
  int scaleCodeOrFlag;
  int limitsOk;
  undefined4 literalValueNumber;
  undefined4 staleArg4;
  undefined4 staleArg5;
  undefined4 staleArg6;
  int *a0;
  int operandRecOffset;
  int loopIndex;
  undefined4 *loopPtr2;
  double absValue;
  undefined4 unitConst0;
  undefined4 unitConst1;
  undefined4 unitConst2;
  undefined4 unitConst3;
  float laneValue [7];
  
  loopIndex = 1;
  operandRecOffset = 0x98;
  loopPtr2 = (undefined4 *)(ctx + 0x214);
  do {
    ((int (*)())ValueKey__dotOperandSplatValue)(laneValue,ctx,loopIndex);
    if ((GH_F2U(laneValue[0]) != 0x7ffffffeU)) {
      notNegative = -1 < (int)GH_F2U(laneValue[0]);
      if (notNegative) {
        absValue = (double)laneValue[0];
      }
      else {
        absValue = -(double)laneValue[0];
      }
      if ((absValue != 1.0) && (scaleCodeOrFlag = ((undefined4 (*)())isOutputScaleValue)(absValue), scaleCodeOrFlag != 0)) {
        scaleCodeOrFlag = ((int (*)())outputScaleExponent)(absValue);
        a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
        scaleCodeOrFlag = scaleCodeOrFlag + *(int *)(*(int *)(ctx + 0xb0) + 0x124);
        limitsOk = (**(code **)(*a0 + 0xfc))(a0,scaleCodeOrFlag,*(int *)(ctx + 0xb0),staleArg4,staleArg5,staleArg6,a0);
        if (limitsOk != 0) {
          unitConst0 = 0x3f800000;
          unitConst1 = 0x3f800000;
          unitConst2 = 0x3f800000;
          unitConst3 = 0x3f800000;
          literalValueNumber = ((int (*)())ValueKey__setLiteralVec4Operand)(loopIndex,&unitConst0,*(undefined4 *)(ctx + 0xb0),
                               *(undefined4 *)(ctx + 0x238));
          keyInst = *(int *)(ctx + 0xb0);
          *loopPtr2 = literalValueNumber;
          *(int *)(keyInst + 0x124) = scaleCodeOrFlag;
          IROperand__setModifierBits(operandRecOffset + *(int *)(ctx + 0xb0) + 0xc,1,0);
          IROperand__setModifierBits(operandRecOffset + *(int *)(ctx + 0xb0) + 0xc,2,0);
          if (!notNegative) {
            operandRecAddr = *(int *)(ctx + 0xb0) + ((loopIndex == 1) - 1) * 0x18 + 0xb0;
            IROperand__setModifierBits(operandRecAddr + 0xc,1,(*(uint *)(operandRecAddr + 0x20) ^ 1) & 1);
          }
          ValueKey__rebuild(ctx);
          return 1;
        }
      }
    }
    moreOperands = loopIndex != 2;
    loopPtr2 = loopPtr2 + 1;
    operandRecOffset = operandRecOffset + 0x18;
    loopIndex = loopIndex + 1;
  } while (moreOperands);
  return 0;
}

/* ValueKey__insertSplatMov @ 0x17ad24 (260 bytes) */
int ValueKey__insertSplatMov(ctx, fillValue, operandIndex)
  int ctx;
  undefined4 fillValue;
  int operandIndex;
{
  int inst;
  int fillOffset;
  int callResult;
  undefined4 swizzle;
  undefined4 block;
  int loopRemaining;
  undefined4 fillVec4 [8];
  
  block = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
  callResult = IRInst__create(0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(callResult,0,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  swizzle = *(undefined4 *)(PTR_DAT_001e8b64 + operandIndex * 4);
  fillOffset = 0;
  *(undefined4 *)(callResult + 0x94) = *(undefined4 *)(callResult + 0x14c);
  loopRemaining = 4;
  *(undefined4 *)(callResult + 0x98) = 0;
  *(undefined4 *)(callResult + 0x9c) = swizzle;
  do {
    *(undefined4 *)(fillOffset + (int)fillVec4) = fillValue;
    fillOffset = fillOffset + 4;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  ((int (*)())ValueKey__setLiteralVec4Operand)(1,fillVec4,callResult,*(undefined4 *)(ctx + 0x238));
  IRInst__appendSource(callResult,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  *(undefined1 *)(operandIndex + *(int *)(ctx + 0xb0) + 0x9c) = 1;
  inst = *(int *)(ctx + 0xb0);
  if ((*(uint *)(inst + 0x14) & 0x200) == 0) {
    IRInst__appendSource(inst,*(undefined4 *)(inst + 0x8c));
    inst = *(int *)(ctx + 0xb0);
  }
  Block__insertInstAfter(block,inst,callResult);
  return callResult;
}

/* ValueKey__setOperandFromValueKey @ 0x17ae28 (172 bytes) */
int ValueKey__setOperandFromValueKey(ctx, operandIndex, valueKey, swizzle, negateFlag, absFlag, compiler)
  int ctx;
  int operandIndex;
  int valueKey;
  undefined4 swizzle;
  undefined4 negateFlag;
  undefined4 absFlag;
  int compiler;
{
  int operandRef;
  int operandRecord;
  undefined4 *allocation;
  undefined4 arena;
  int operandOffset;
  undefined4 *newValueKey;
  
  operandRef = *(int *)(valueKey + 0x8c);
  if (*(int *)(*(int *)(operandRef + 0x2c) + 4) == 0) {
    arena = *(undefined4 *)(compiler + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arena,0x240);
    newValueKey = allocation + 1;
    *allocation = arena;
    ValueKey__init(newValueKey,valueKey,compiler);
    ValueKey__computeLaneFlags(newValueKey);
    ValueKey__propagateLaneValues(newValueKey);
    VReg__pushDefinition(operandRef,*(undefined4 *)(*(int *)(valueKey + 0x158) + 0xb0),newValueKey);
  }
  IRInst__setOperandRef(*(undefined4 *)(ctx + 0xb0),operandIndex,operandRef);
  if (operandIndex == 0) {
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x9c) = swizzle;
  }
  else {
    operandRecord = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),operandIndex);
    *(undefined4 *)(operandRecord + 0x10) = swizzle;
  }
  operandOffset = operandIndex * 0x18 + 0x80;
  IROperand__setModifierBits(operandOffset + *(int *)(ctx + 0xb0) + 0xc,1,negateFlag);
  IROperand__setModifierBits(operandOffset + *(int *)(ctx + 0xb0) + 0xc,2,absFlag);
  return valueKey;
}

/* ValueKey__commonLaneValue_17af58 @ 0x17af58 (200 bytes) */
int ValueKey__commonLaneValue_17af58(resultOut, ctx, sourceIndex)
  undefined4 *resultOut;
  int ctx;
  int sourceIndex;
{
  bool commonIsExpr;
  bool noLaneSeen;
  int loopIndex;
  int loopRemaining;
  undefined4 *exprRecord;
  int commonValueNumber;
  int *loopPtr2;
  undefined4 writeMaskWord [6];
  
  loopPtr2 = (int *)(sourceIndex * 0x10 + ctx + 0x168);
  loopRemaining = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
  commonValueNumber = 0;
  commonIsExpr = false;
  noLaneSeen = true;
  loopIndex = 0;
  writeMaskWord[0] = *(undefined4 *)(loopRemaining + 0x10);
  loopRemaining = 4;
  do {
    if (*(char *)((int)writeMaskWord + loopIndex) != '\x01') {
      if (noLaneSeen) {
        commonValueNumber = *loopPtr2;
        commonIsExpr = commonValueNumber < 0;
        noLaneSeen = commonValueNumber == 0;
      }
      else if (*loopPtr2 != commonValueNumber) goto LAB_0017affc;
    }
    loopIndex = loopIndex + 1;
    loopPtr2 = loopPtr2 + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  if (commonIsExpr) {
    exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),commonValueNumber);
    *resultOut = *exprRecord;
  }
  else {
LAB_0017affc:
    *resultOut = 0x7ffffffe;
  }
  return resultOut;
}

/* FUN_0017b020 @ 0x17b020 (268 bytes) */
int FUN_0017b020(ctx, operandIndex)
  int ctx;
  int operandIndex;
{
  int src1Record;
  int src0Record;
  int *elementRef;
  int *definingInst;
  int predicateResult;
  uint vectorFilledCount;
  uint lastElementIndex;
  uint *vector;
  int definingRow;
  
  vector = *(uint **)(*(int *)(operandIndex * 0x18 + *(int *)(ctx + 0xb0) + 0x8c) + 0x2c);
  vectorFilledCount = vector[1];
  lastElementIndex = vectorFilledCount - 1;
  if (lastElementIndex < *vector) {
    if (vectorFilledCount <= lastElementIndex) {
      _memset(vectorFilledCount * 4 + vector[2],0,(lastElementIndex - vectorFilledCount) * 4 + 4);
      vector[1] = vectorFilledCount;
    }
    elementRef = (int *)(lastElementIndex * 4 + vector[2]);
  }
  else {
    elementRef = (int *)Vector__elementRefGrow(vector,lastElementIndex);
  }
  definingRow = *elementRef;
  definingInst = *(int **)(definingRow + 0xb0);
  predicateResult = (**(code **)(*definingInst + 100))(definingInst);
  if (((predicateResult != 0) &&
      (src0Record = IRInst__getOperandRecord(*(undefined4 *)(definingRow + 0xb0),0), *(int *)(src0Record + 0x10) == 0)) &&
     (src1Record = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),1), *(int *)(src1Record + 0x10) == 0x10203)) {
    return 1;
  }
  return 0;
}

/* ValueKey__mixLiteralSources @ 0x17b12c (2112 bytes) */
int ValueKey__mixLiteralSources(key)
  int key;
{
  int slotOffset;
  undefined4 operandKey;
  undefined4 savedIdentitySelect;
  undefined4 foldedHandle;
  undefined4 defaultSelectWord;
  int literalIndex;
  int operandNumber;
  int isForwardableMov;
  int isRepresentable;
  int valueNumber;
  uint vectorFilledCount2;
  uint vectorFilledCount;
  uint *vector2;
  int inst2;
  int operandIndex;
  int inst;
  int firstUnwrittenComponentResult;
  undefined4 sourceDef;
  int operandRecord;
  int operandRecord2;
  bool moreIterations;
  byte laneSelectByte;
  int *literalMovTableBase;
  undefined4 operandRegisterKind;
  int loopIndex2;
  int movOrFlag;
  int loopIndex3;
  int *loopPtr7;
  float *literalRecord;
  int operandSource;
  int *loopPtr5;
  int *loopPtr6;
  undefined4 *loopPtr8;
  undefined4 staleArg5;
  undefined4 staleArg6;
  code *a6;
  int laneUsedPtr;
  int operandIndex2;
  uint lastEntryIndex;
  undefined1 *loopPtr9;
  uint lastEntryIndex2;
  char *loopPtr4;
  uint *vector;
  int loopIndex;
  double literalValueArg;
  undefined8 literalResult;
  int literalMovTable [6];
  undefined1 literalCountPad [4];
  int literalCountByOperand [4];
  undefined4 identitySelects [4];
  undefined4 identitySelectsTail;
  undefined4 defaultSelects [5];
  undefined4 literalPool [23];
  float foldedValue;
  int changed;
  int *literalMovAlias;
  undefined1 *literalCountPadAlias;
  int *literalCountAlias;
  undefined *picBaseB;
  undefined4 *literalPoolAlias;
  undefined *picBaseA;
  int *literalMovTableAlias;
  
  loopIndex2 = Compiler__isOptionEnabled(*(undefined4 *)(key + 0x238),0xb);
  if (((loopIndex2 == 0) || (loopIndex2 = Compiler__isOptionEnabled(*(undefined4 *)(key + 0x238),0x3a), loopIndex2 == 0)) ||
     (*(int *)(*(int *)(key + 0x238) + 0x664) <=
      *(int *)(*(int *)(*(int *)(key + 0x238) + 0x6c4) + 0x228))) {
    changed = 0;
  }
  else {
    literalPoolAlias = literalPool;
    loopIndex2 = 0;
    do {
      loopPtr8 = literalPoolAlias + loopIndex2 * 4;
      loopIndex = 4;
      do {
        *loopPtr8 = 0xbf800000;
        loopPtr8 = loopPtr8 + 1;
        loopIndex = loopIndex + -1;
      } while (loopIndex != 0);
      moreIterations = loopIndex2 != 4;
      loopIndex2 = loopIndex2 + 1;
    } while (moreIterations);
    picBaseB = &DAT_001ab134;
    literalCountPadAlias = literalCountPad;
    loopIndex = 5;
    picBaseA = &DAT_001ab134;
    loopIndex2 = 0;
    do {
      *(undefined4 *)((int)literalMovTable + loopIndex2 + 4) = 0;
      loopPtr9 = literalCountPadAlias;
      *(undefined4 *)((int)identitySelects + loopIndex2) = 0x1010101;
      *(undefined4 *)(loopPtr9 + loopIndex2) = 0;
      *(undefined4 *)((int)defaultSelects + loopIndex2) = 0x4040404;
      loopIndex2 = loopIndex2 + 4;
      loopIndex = loopIndex + -1;
    } while (loopIndex != 0);
    loopPtr7 = literalMovTable + 2;
    loopPtr6 = literalCountByOperand;
    literalMovTableAlias = literalMovTable;
    loopIndex = key + 0x170;
    laneUsedPtr = key + 0x224;
    loopIndex2 = 0x18;
    changed = 0;
    literalMovAlias = loopPtr7;
    literalCountAlias = loopPtr6;
    for (operandIndex2 = 1;
        loopIndex3 = (**(code **)(**(int **)(key + 0xb0) + 0x14))(*(int **)(key + 0xb0)),
        operandIndex2 <= loopIndex3; operandIndex2 = operandIndex2 + 1) {
      loopIndex3 = *(int *)(key + 0xb0);
      if ((operandIndex2 < 1) || (operandSource = IRInst__getOperandSource(loopIndex3,operandIndex2), operandSource == 0)) {
        operandRegisterKind = *(undefined4 *)(loopIndex2 + loopIndex3 + 0x98);
      }
      else {
        loopIndex3 = IRInst__getOperandSource(loopIndex3,operandIndex2);
        operandRegisterKind = *(undefined4 *)(loopIndex3 + 0x98);
      }
      loopIndex3 = RegKind__flagBit6(operandRegisterKind);
      if (loopIndex3 == 0) {
        loopPtr4 = (char *)(laneUsedPtr + 4);
        loopPtr5 = (int *)(loopIndex + 8);
        loopIndex3 = 0;
        do {
          if (*loopPtr4 != '\0') {
            operandRecord2 = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),operandIndex2);
            literalMovTableBase = literalMovTableAlias;
            laneSelectByte = *(byte *)(loopIndex3 + operandRecord2 + 0x10);
            slotOffset = (uint)laneSelectByte + operandIndex2 * 4;
            *(undefined1 *)((int)literalMovTableAlias + slotOffset + 0x2c) = 0;
            *(byte *)((int)literalMovTableAlias + slotOffset + 0x40) = laneSelectByte;
            if (*loopPtr5 < 0) {
              literalRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),*loopPtr5);
              movOrFlag = (**(code **)(**(int **)(*(int *)(key + 0x238) + 0x30c) + 0xf0))
                                ((double)*literalRecord);
              if (movOrFlag != 0) {
                if (*loopPtr7 == 0) {
                  movOrFlag = ((int (*)())ValueKey__insertTempCopyOfOperand)(key,operandIndex2);
                  *loopPtr7 = movOrFlag;
                  *loopPtr6 = 1;
                  changed = 1;
                }
                literalResult = ((int (*)())ValueKey__findOrInsertLiteral)(movOrFlag,literalPoolAlias,operandIndex2,(double)*literalRecord);
                literalIndex = (int)((ulonglong)literalResult >> 0x20);
                if (*loopPtr6 < literalIndex) {
                  ((void (*)())IRInst__setLiteralOperandAndSource)(*loopPtr7,(int)literalResult,literalIndex,*(undefined4 *)(key + 0x238),
                               (double)*literalRecord);
                  *loopPtr6 = literalIndex;
                }
                a6 = *(code **)(*(int *)*loopPtr7 + 0x88);
                (*a6)((int *)*loopPtr7,literalIndex,(uint)laneSelectByte,loopIndex3,staleArg5,staleArg6,a6);
                *(undefined1 *)((int)literalMovTableBase + slotOffset + 0x40) = 4;
              }
            }
          }
          moreIterations = loopIndex3 != 3;
          loopPtr4 = loopPtr4 + 1;
          loopPtr5 = loopPtr5 + 1;
          loopIndex3 = loopIndex3 + 1;
        } while (moreIterations);
      }
      loopIndex2 = loopIndex2 + 0x18;
      laneUsedPtr = laneUsedPtr + 4;
      loopIndex = loopIndex + 0x10;
      loopPtr7 = loopPtr7 + 1;
      loopPtr6 = loopPtr6 + 1;
    }
    loopIndex2 = 0;
    loopIndex = 5;
    do {
      loopPtr9 = literalCountPadAlias;
      if (*(int *)((int)literalMovTable + loopIndex2 + 4) == 0) {
        defaultSelectWord = *(undefined4 *)(((unsigned char *)0x000050a8) + (int)picBaseB);
        *(undefined4 *)((int)identitySelects + loopIndex2) = *(undefined4 *)(((unsigned char *)0x0000509c) + (int)picBaseA);
        *(undefined4 *)(loopPtr9 + loopIndex2) = 0;
        *(undefined4 *)((int)defaultSelects + loopIndex2) = defaultSelectWord;
      }
      loopIndex2 = loopIndex2 + 4;
      loopIndex = loopIndex + -1;
    } while (loopIndex != 0);
    loopPtr7 = *(int **)(key + 0xb0);
    if ((((loopPtr7[5] & 0x200U) != 0) && (loopPtr7[0x48] == 0)) && (loopPtr7[0x49] == 0)) {
      loopIndex2 = ((int (*)())ValueKey__sourcesHaveNoModifiers)(key);
      if (loopIndex2 != 0) {
        loopIndex = 0;
        loopIndex2 = key;
        do {
          operandRecord = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),0);
          if (*(char *)(loopIndex + operandRecord + 0x10) == '\x01') {
            inst = *(int *)(key + 0xb0);
            vector = *(uint **)(*(int *)(*(int *)(inst + 0x84) * 0x18 + inst + 0x8c) + 0x2c);
            vectorFilledCount2 = vector[1];
            lastEntryIndex = vectorFilledCount2 - 1;
            if (lastEntryIndex < *vector) {
              if (vectorFilledCount2 <= lastEntryIndex) {
                _memset(vectorFilledCount2 * 4 + vector[2],0,(lastEntryIndex - vectorFilledCount2) * 4 + 4);
                vector[1] = vectorFilledCount2;
                inst = *(int *)(key + 0xb0);
              }
              loopPtr7 = (int *)(lastEntryIndex * 4 + vector[2]);
            }
            else {
              loopPtr7 = (int *)Vector__elementRefGrow(vector,lastEntryIndex);
              inst = *(int *)(key + 0xb0);
            }
            operandIndex2 = *loopPtr7;
            operandRecord = IRInst__getOperandRecord(inst,0);
            literalMovTable[0] = *(int *)(operandRecord + 0x10);
            valueNumber = *(int *)(loopIndex * 4 + operandIndex2 + 0x20);
            if (valueNumber < 0) {
              literalRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),valueNumber);
              isRepresentable = (**(code **)(**(int **)(*(int *)(key + 0x238) + 0x30c) + 0xf0))
                                 ((double)*literalRecord);
              if (isRepresentable != 0) {
                loopPtr7 = literalMovAlias;
                loopPtr6 = literalCountAlias;
                for (operandIndex = 1;
                    operandIndex2 = (**(code **)(**(int **)(key + 0xb0) + 0x14))
                                       (*(int **)(key + 0xb0)), operandIndex <= operandIndex2;
                    operandIndex = operandIndex + 1) {
                  if (*loopPtr7 == 0) {
                    loopIndex3 = ((int (*)())ValueKey__insertTempCopyOfOperand)(key,operandIndex);
                    operandIndex2 = operandIndex * 4;
                    *loopPtr7 = loopIndex3;
                    *loopPtr6 = 1;
                    loopPtr9 = (undefined1 *)((int)defaultSelects + operandIndex * 4);
                    loopPtr8 = identitySelects + operandIndex;
                    loopIndex3 = 0;
                    do {
                      if (*(char *)((int)literalMovTable + loopIndex3) == '\0') {
                        operandRecord2 = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),operandIndex);
                        *loopPtr9 = *(undefined1 *)(loopIndex3 + operandRecord2 + 0x10);
                        *(undefined1 *)loopPtr8 = 0;
                        (**(code **)(**(int **)(key + 0xb0) + 0x88))
                                  (*(int **)(key + 0xb0),operandIndex,loopIndex3,loopIndex3);
                      }
                      moreIterations = loopIndex3 != 3;
                      loopPtr9 = loopPtr9 + 1;
                      loopPtr8 = (undefined4 *)((int)loopPtr8 + 1);
                      loopIndex3 = loopIndex3 + 1;
                    } while (moreIterations);
                    changed = 1;
                  }
                  else {
                    operandIndex2 = operandIndex << 2;
                  }
                  foldedHandle = IRInst__foldCompareConstResult(&foldedValue, *(undefined4 *)(key + 0xb0), operandIndex, *(unsigned int *)literalRecord, *(undefined4 *)(key + 0x238));
                  literalValueArg = (double)foldedValue;
                  literalResult = ((int (*)())ValueKey__findOrInsertLiteral)(foldedHandle,literalPoolAlias,operandIndex,literalValueArg);
                  loopIndex3 = (int)((ulonglong)literalResult >> 0x20);
                  if (*loopPtr6 < loopIndex3) {
                    ((void (*)())IRInst__setLiteralOperandAndSource)(*loopPtr7,(int)literalResult,loopIndex3,*(undefined4 *)(key + 0x238),literalValueArg
                                );
                    *loopPtr6 = loopIndex3;
                  }
                  loopPtr6 = loopPtr6 + 1;
                  firstUnwrittenComponentResult = SelectWord__firstUnwrittenComponent(*(undefined4 *)((int)identitySelects + operandIndex2));
                  loopPtr5 = (int *)*loopPtr7;
                  loopPtr7 = loopPtr7 + 1;
                  (**(code **)(*loopPtr5 + 0x88))(loopPtr5,loopIndex3,firstUnwrittenComponentResult,firstUnwrittenComponentResult);
                  *(undefined1 *)((int)identitySelects + firstUnwrittenComponentResult + operandIndex2) = 0;
                  (**(code **)(**(int **)(key + 0xb0) + 0x88))
                            (*(int **)(key + 0xb0),operandIndex,loopIndex,firstUnwrittenComponentResult);
                }
                *(undefined1 *)(loopIndex + *(int *)(key + 0xb0) + 0x9c) = 0;
                *(float **)(loopIndex2 + 0x30) = literalRecord;
              }
            }
          }
          moreIterations = loopIndex != 3;
          loopIndex2 = loopIndex2 + 4;
          loopIndex = loopIndex + 1;
        } while (moreIterations);
      }
      loopPtr7 = *(int **)(key + 0xb0);
    }
    loopIndex2 = 1;
    while (loopIndex = (**(code **)(*loopPtr7 + 0x14))(loopPtr7), loopIndex2 <= loopIndex) {
      loopIndex = loopIndex2 + 1;
      inst2 = literalMovTable[loopIndex];
      if (inst2 != 0) {
        *(int *)(inst2 + 0x9c) = literalCountByOperand[loopIndex2 + 4];
        savedIdentitySelect = (&identitySelectsTail)[loopIndex];
        loopIndex2 = IRInst__getOperandRecord(inst2,1);
        *(undefined4 *)(loopIndex2 + 0x10) = savedIdentitySelect;
        IRInst__removeDefaultSelectOperands(inst2,*(undefined4 *)(key + 0x238));
      }
      loopPtr7 = *(int **)(key + 0xb0);
      loopIndex2 = loopIndex;
    }
    loopPtr7 = literalMovTable + 2;
    for (loopIndex2 = 1;
        loopIndex = (**(code **)(**(int **)(key + 0xb0) + 0x14))(*(int **)(key + 0xb0)),
        loopIndex2 <= loopIndex; loopIndex2 = loopIndex2 + 1) {
      loopIndex = *loopPtr7;
      if (loopIndex != 0) {
        loopPtr6 = (int *)IRInst__getOperandSource(loopIndex,1);
        isForwardableMov = (**(code **)(*loopPtr6 + 0x60))(loopPtr6);
        if (isForwardableMov != 0) {
          sourceDef = IRInst__getOperandSource(loopIndex,1);
          IRInst__foldConstantSourcesIntoClone(sourceDef,loopIndex,*(undefined4 *)(key + 0x238));
        }
      }
      loopPtr7 = loopPtr7 + 1;
    }
    loopPtr7 = literalMovTable + 2;
    loopIndex = 0x18;
    loopIndex2 = key;
    for (operandNumber = 1;
        operandIndex2 = (**(code **)(**(int **)(key + 0xb0) + 0x14))(*(int **)(key + 0xb0)),
        operandNumber <= operandIndex2; operandNumber = operandNumber + 1) {
      operandIndex2 = *loopPtr7;
      if (operandIndex2 != 0) {
        vector2 = *(uint **)(*(int *)(loopIndex + *(int *)(key + 0xb0) + 0x8c) + 0x2c);
        vectorFilledCount = vector2[1];
        lastEntryIndex2 = vectorFilledCount - 1;
        if (lastEntryIndex2 < *vector2) {
          if (vectorFilledCount <= lastEntryIndex2) {
            _memset(vectorFilledCount * 4 + vector2[2],0,(lastEntryIndex2 - vectorFilledCount) * 4 + 4);
            vector2[1] = vectorFilledCount;
          }
          loopPtr8 = (undefined4 *)(lastEntryIndex2 * 4 + vector2[2]);
        }
        else {
          loopPtr8 = (undefined4 *)Vector__elementRefGrow(vector2,lastEntryIndex2);
        }
        operandKey = *loopPtr8;
        ValueKey__fillSourceLaneUsage(operandKey);
        ValueKey__fill(operandKey);
        ValueKey__computeLaneFlags(operandKey);
        ValueKey__initSourceLaneKinds(operandKey);
        ValueKey__propagateLaneValues(operandKey);
        *(int *)(loopIndex2 + 0x214) = operandIndex2;
      }
      loopPtr7 = loopPtr7 + 1;
      loopIndex = loopIndex + 0x18;
      loopIndex2 = loopIndex2 + 4;
    }
    if (changed != 0) {
      loopIndex2 = 4;
      do {
        loopIndex2 = loopIndex2 + -1;
      } while (loopIndex2 != 0);
    }
  }
  return changed;
}

/* ValueKey__rewriteUniformSwizzle @ 0x17b96c (748 bytes) */
int ValueKey__rewriteUniformSwizzle(ctx)
  int ctx;
{
  undefined4 valueRow;
  uint instFlags;
  uint lastElementIndex2;
  bool lastLane2;
  bool notLastLane;
  uint vectorFilledCount2;
  uint *vector2;
  bool lastLane;
  bool allSourceLanesMatch;
  int loopIndex3;
  int *elementRef;
  undefined4 *elementRef2;
  undefined4 swizzleRewritten;
  uint lastElementIndex;
  undefined4 newSwizzleWord;
  uint vectorFilledCount;
  int firstValueRow;
  int loopIndex;
  uint *vector;
  int loopIndex2;
  undefined4 newSwizzle [8];
  
  if ((*(int *)(*(int *)(ctx + 0x238) + 0x658) <=
       *(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0xa8)) ||
     (loopIndex3 = (**(code **)(**(int **)(ctx + 0xb0) + 100))(*(int **)(ctx + 0xb0)), loopIndex3 == 0
     )) {
    return 0;
  }
  loopIndex3 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),1);
  loopIndex3 = SelectWord__isIdentity(*(undefined4 *)(loopIndex3 + 0x10));
  if (loopIndex3 == 0) {
    loopIndex3 = *(int *)(ctx + 0xb0);
    vector = *(uint **)(*(int *)(loopIndex3 + 0xa4) + 0x2c);
    vectorFilledCount = vector[1];
    lastElementIndex = vectorFilledCount - 1;
    if (lastElementIndex < *vector) {
      if (vectorFilledCount <= lastElementIndex) {
        _memset(vectorFilledCount * 4 + vector[2],0,(lastElementIndex - vectorFilledCount) * 4 + 4);
        vector[1] = vectorFilledCount;
        loopIndex3 = *(int *)(ctx + 0xb0);
      }
      elementRef = (int *)(lastElementIndex * 4 + vector[2]);
    }
    else {
      elementRef = (int *)Vector__elementRefGrow(vector,lastElementIndex);
      loopIndex3 = *(int *)(ctx + 0xb0);
    }
    firstValueRow = *elementRef;
    allSourceLanesMatch = true;
    loopIndex2 = 0;
    loopIndex = firstValueRow;
    while( true ) {
      loopIndex3 = IRInst__getOperandRecord(loopIndex3,0);
      if (*(char *)(loopIndex2 + loopIndex3 + 0x10) != '\x01') {
        loopIndex3 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),1);
        loopIndex3 = Ptr__equalNonNull(*(undefined4 *)
                              ((uint)*(byte *)(loopIndex2 + loopIndex3 + 0x10) * 4 + firstValueRow + 0x20),
                             *(undefined4 *)(loopIndex + 0x20));
        if (loopIndex3 == 0) {
          allSourceLanesMatch = false;
        }
      }
      lastLane = loopIndex2 == 3;
      loopIndex = loopIndex + 4;
      loopIndex2 = loopIndex2 + 1;
      if (lastLane) break;
      loopIndex3 = *(int *)(ctx + 0xb0);
    }
    if (allSourceLanesMatch) {
      loopIndex3 = 0;
      newSwizzle[0] = 0x4040404;
      do {
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex3 + loopIndex + 0x10) != '\x01') {
          *(char *)((int)newSwizzle + loopIndex3) = (char)loopIndex3;
        }
        newSwizzleWord = newSwizzle[0];
        notLastLane = loopIndex3 != 3;
        loopIndex3 = loopIndex3 + 1;
      } while (notLastLane);
      swizzleRewritten = 1;
      loopIndex3 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),1);
      *(undefined4 *)(loopIndex3 + 0x10) = newSwizzleWord;
      goto LAB_0017bb2c;
    }
  }
  swizzleRewritten = 0;
LAB_0017bb2c:
  loopIndex3 = *(int *)(ctx + 0xb0);
  if ((*(int *)(loopIndex3 + 0x120) != 0) && (*(int *)(loopIndex3 + 0x124) == 0)) {
    vector2 = *(uint **)(*(int *)(loopIndex3 + 0xa4) + 0x2c);
    vectorFilledCount2 = vector2[1];
    lastElementIndex2 = vectorFilledCount2 - 1;
    if (lastElementIndex2 < *vector2) {
      if (vectorFilledCount2 <= lastElementIndex2) {
        _memset(vectorFilledCount2 * 4 + vector2[2],0,(lastElementIndex2 - vectorFilledCount2) * 4 + 4);
        vector2[1] = vectorFilledCount2;
        loopIndex3 = *(int *)(ctx + 0xb0);
      }
      elementRef2 = (undefined4 *)(lastElementIndex2 * 4 + vector2[2]);
    }
    else {
      elementRef2 = (undefined4 *)Vector__elementRefGrow(vector2,lastElementIndex2);
      loopIndex3 = *(int *)(ctx + 0xb0);
    }
    instFlags = *(uint *)(loopIndex3 + 0xb8);
    loopIndex = 0;
    valueRow = *elementRef2;
    while( true ) {
      loopIndex3 = IRInst__getOperandRecord(loopIndex3,0);
      if (*(char *)(loopIndex + loopIndex3 + 0x10) != '\x01') {
        loopIndex3 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),1);
        loopIndex3 = ValueKey__sourceWordIs4(valueRow,(uint)*(byte *)(loopIndex + loopIndex3 + 0x10));
        if (loopIndex3 == 0) {
          return swizzleRewritten;
        }
        if ((instFlags & 1) != 0) {
          return swizzleRewritten;
        }
      }
      lastLane2 = loopIndex == 3;
      loopIndex = loopIndex + 1;
      if (lastLane2) break;
      loopIndex3 = *(int *)(ctx + 0xb0);
    }
    swizzleRewritten = 1;
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x120) = 0;
  }
  return swizzleRewritten;
}

