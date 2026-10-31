#include "decls.h"

/* IRInst__createWithConstantOperands @ 0x10bed0 (320 bytes) */
int IRInst__createWithConstantOperands(int operandCount,undefined4 destSelect,undefined4 newSource,int program,undefined4 compiler,double value)
{
  undefined4 defaultSelect;
  int newInst;
  int operandRecord;
  double thirdConstant;
  
  *(int *)(program + 0x228) = *(int *)(program + 0x228) + 1;
  newInst = IRLoadConst__vslot73(0xa2,compiler);
  *(undefined4 *)(newInst + 0x98) = 0x36;
  *(undefined4 *)(newInst + 0x94) = *(undefined4 *)(newInst + 0x14c);
  *(undefined4 *)(newInst + 0x9c) = destSelect;
  *(int *)(newInst + 0x84) = operandCount;
  IRInst__setOperandSource(newInst,1,newSource,*(uint *)(program + 0x30) >> 7 & 1,compiler);
  defaultSelect = swizzleAllUnused_001af9fc;
  operandRecord = IRInst__getOperandRecord(newInst,1);
  *(undefined4 *)(operandRecord + 0x10) = defaultSelect;
  ((void (*)())IRInst__makeLiteralVec4Float)(newInst,program,2,value,value,value,value);
  operandRecord = IRInst__getOperandRecord(newInst,2);
  *(undefined4 *)(operandRecord + 0x10) = defaultSelect;
  if (operandCount == 3) {
    thirdConstant = (double)FLOAT_001aa0d4;
    if (value == thirdConstant) {
      thirdConstant = (double)FLOAT_001aa0e8;
    }
    ((void (*)())IRInst__makeLiteralVec4Float)(newInst,program,3,thirdConstant,thirdConstant,thirdConstant,thirdConstant);
    defaultSelect = swizzleAllUnused_001af9fc;
    operandRecord = IRInst__getOperandRecord(newInst,3);
    *(undefined4 *)(operandRecord + 0x10) = defaultSelect;
  }
  *(int *)(newInst + 0x160) = *(int *)(program + 0x478) + 1;
  return newInst;
}

/* IRInst__reduceTernaryToBinary @ 0x10c010 (600 bytes) */
int IRInst__reduceTernaryToBinary(inst, operandIndex, compiler)
  int *inst;
  int operandIndex;
  int compiler;
{
  int newOpcode;
  int useCount;
  bool invertFirstNegate;
  uint modifiers1;
  uint modifiers2;
  uint modifiers3;
  int oldOpcode;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 operandVReg;
  int operandRecord;
  undefined4 operandVReg2;
  undefined4 select2;
  undefined4 operandVReg3;
  undefined4 select3;
  int keptSource;
  undefined4 select1;
  int extraSource;
  int ownerBlock;
  int nextLink;
  int regKind;
  int regNumber;
  int destSelect;
  int outputClampFlag;
  int scaleExponentWord;
  int *operand1Record;
  
  extraSource = 0;
  operandVReg = IRInst__getOperandSource(inst,1);
  modifiers1 = inst[0x2e];
  operandRecord = IRInst__getOperandRecord(inst,1);
  select1 = *(undefined4 *)(operandRecord + 0x10);
  operandVReg2 = IRInst__getOperandSource(inst,2);
  modifiers2 = inst[0x34];
  operandRecord = IRInst__getOperandRecord(inst,2);
  select2 = *(undefined4 *)(operandRecord + 0x10);
  operandVReg3 = IRInst__getOperandSource(inst,3);
  modifiers3 = inst[0x3a];
  operandRecord = IRInst__getOperandRecord(inst,3);
  select3 = *(undefined4 *)(operandRecord + 0x10);
  nextLink = inst[1];
  ownerBlock = inst[0x56];
  regKind = inst[0x26];
  regNumber = inst[0x25];
  operandRecord = IRInst__getOperandRecord(inst,0);
  destSelect = *(int *)(operandRecord + 0x10);
  outputClampFlag = inst[0x48];
  scaleExponentWord = inst[0x49];
  useCount = IRInst__useCount(inst,*(undefined4 *)(compiler + 0x6c4));
  if ((inst[5] & 0x200U) != 0) {
    extraSource = IRInst__getOperandSource(inst,inst[0x21]);
  }
  keptSource = IRInst__getOperandSource(inst,operandIndex);
  DList__unlink(inst);
  oldOpcode = *(int *)(inst[0x22] + 8);
  if (oldOpcode == 0x25) {
    invertFirstNegate = operandIndex == 2;
    newOpcode = 0xb2 - (uint)(operandIndex == 3);
  }
  else if (oldOpcode == 0x26) {
    invertFirstNegate = operandIndex == 2;
    newOpcode = (operandIndex == 3) + 0xb1;
  }
  else if (oldOpcode == 0x24) {
    if (operandIndex == 3) {
      newOpcode = 0xb0;
      invertFirstNegate = false;
    }
    else {
      newOpcode = 0xb3;
      invertFirstNegate = false;
    }
  }
  else {
    newOpcode = 0;
    invertFirstNegate = false;
  }
  IRInst__reinitAsBinary(inst,newOpcode,compiler);
  inst[0x49] = scaleExponentWord;
  inst[0x25] = regNumber;
  inst[0x26] = regKind;
  inst[0x27] = destSelect;
  operand1Record = inst + 0x29;
  inst[0x48] = outputClampFlag;
  inst[0x58] = useCount + *(int *)(*(int *)(compiler + 0x6c4) + 0x478);
  Block__insertInstAfter(ownerBlock,nextLink,inst);
  IRInst__setOperandSource(inst,1,operandVReg,0,compiler);
  IROperand__setModifierBits(operand1Record,1,modifiers1 & 1);
  IROperand__setModifierBits(operand1Record,2,modifiers1 >> 1 & 1);
  operandRecord = IRInst__getOperandRecord(inst,1);
  *(undefined4 *)(operandRecord + 0x10) = select1;
  if (invertFirstNegate) {
    IROperand__setModifierBits(operand1Record,1,inst[0x2e] & 1U ^ 1);
  }
  if (operandIndex == 3) {
    IRInst__setOperandSource(inst,2,operandVReg2,0,compiler);
    IROperand__setModifierBits(inst + 0x2f,1,modifiers2 & 1);
    IROperand__setModifierBits(inst + 0x2f,2,modifiers2 >> 1 & 1);
    operandRecord = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord + 0x10) = select2;
  }
  else {
    IRInst__setOperandSource(inst,2,operandVReg3,0,compiler);
    IROperand__setModifierBits(inst + 0x2f,1,modifiers3 & 1);
    IROperand__setModifierBits(inst + 0x2f,2,modifiers3 >> 1 & 1);
    operandRecord = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord + 0x10) = select3;
  }
  if (extraSource == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(*inst + 0x94);
  }
  else {
    UNRECOVERED_JUMPTABLE = *(code **)(*inst + 0x94);
    keptSource = extraSource;
  }
                    
                    
  return (*UNRECOVERED_JUMPTABLE)(inst,keptSource,compiler);
}

/* IRInst__removeDefaultSelectOperands @ 0x10c37c (256 bytes) */
int IRInst__removeDefaultSelectOperands(inst, compilerCtx)
  int inst;
  undefined4 compilerCtx;
{
  int operandRecord;
  undefined4 operandVReg;
  int loopIndex;
  int operandCount;
  int shiftIndex;
  
  operandCount = *(int *)(inst + 0x84);
  if (0 < operandCount) {
    loopIndex = 1;
    do {
      operandRecord = IRInst__getOperandRecord(inst,loopIndex);
      shiftIndex = loopIndex;
      if (*(int *)(operandRecord + 0x10) == swizzleAllUnused_001af9fc) {
        do {
          if (shiftIndex < operandCount) {
            IRInst__copyOperandFrom(inst,shiftIndex,inst,shiftIndex + 1);
            operandVReg = IRInst__getOperandSource(inst,shiftIndex + 1);
            IRInst__setOperandSource(inst,shiftIndex,operandVReg,0,compilerCtx);
          }
          else {
            IRInst__initOperandRecord(inst,shiftIndex);
            IRInst__setOperandSource(inst,shiftIndex,0,0,compilerCtx);
          }
          shiftIndex = shiftIndex + 1;
        } while (shiftIndex <= operandCount);
        operandCount = operandCount + -1;
        *(int *)(inst + 0x84) = operandCount;
      }
      else {
        loopIndex = loopIndex + 1;
      }
    } while (loopIndex <= operandCount);
  }
  return;
}

/* IRInst__canFoldConstantCompare @ 0x10c47c (500 bytes) */
int IRInst__canFoldConstantCompare(inst, pass)
  int *inst;
  int pass;
{
  int operandRecord;
  bool moreLanes;
  bool constantsAreZero;
  int sourceOpcode;
  int *sourceInst;
  int laneCountdown;
  undefined4 canFold;
  undefined4 staleArg5;
  undefined4 staleArg6;
  undefined4 staleArg7;
  undefined4 staleArg8;
  int laneByteIndex;
  int operandVReg;
  uint selectedLane;
  uint laneNumber;
  undefined8 operandVReg2;
  undefined4 swizzleWord [8];
  
  (**(code **)(*inst + 0x60))(inst,pass);
  operandVReg2 = IRInst__getOperandSource(inst,1);
  sourceInst = (int *)((ulonglong)operandVReg2 >> 0x20);
  sourceOpcode = *(int *)(sourceInst[0x22] + 8);
  if (((((sourceOpcode - 0x16U < 2) || (sourceOpcode == 0x19)) || (sourceOpcode == 0x31)) ||
      (((sourceOpcode == 0x13 || (sourceOpcode == 0x14)) || (sourceOpcode == 0x12)))) &&
     (operandVReg = *(int *)(*(int *)(pass + 0x6c4) + 0x228),
     sourceOpcode = (**(code **)(*sourceInst + 0x14))
                       (sourceInst,(int)operandVReg2,staleArg5,staleArg6,staleArg7,staleArg8,*(int *)(pass + 0x6c4)),
     operandVReg + sourceOpcode < *(int *)(pass + 0x664))) {
    constantsAreZero = true;
    if (1 < inst[0x21]) {
      sourceOpcode = 2;
      constantsAreZero = true;
      do {
        operandVReg = IRInst__getOperandSource(inst,sourceOpcode);
        if (*(int *)(operandVReg + 0x98) == 0x33) {
          operandRecord = IRInst__getOperandRecord(inst,sourceOpcode);
          laneByteIndex = 0;
          swizzleWord[0] = *(undefined4 *)(operandRecord + 0x10);
          laneCountdown = 4;
          do {
            if ((*(byte *)((int)swizzleWord + laneByteIndex) != 4) &&
               (*(float *)((uint)*(byte *)((int)swizzleWord + laneByteIndex) * 0x18 + operandVReg + 0x20) != 0.0)) {
              constantsAreZero = false;
              break;
            }
            laneByteIndex = laneByteIndex + 1;
            laneCountdown = laneCountdown + -1;
          } while (laneCountdown != 0);
        }
        sourceOpcode = sourceOpcode + 1;
      } while (sourceOpcode <= inst[0x21]);
    }
    if ((sourceInst[5] & 0x200U) != 0) {
      laneNumber = 0;
      do {
        sourceOpcode = IRInst__getOperandRecord(inst,1);
        selectedLane = (uint)*(byte *)(laneNumber + sourceOpcode + 0x10);
        if (((selectedLane != 4) && (sourceOpcode = IRInst__getOperandRecord(sourceInst,0), *(char *)(laneNumber + sourceOpcode + 0x10) == '\x01')
            ) && (selectedLane != laneNumber)) goto setCanFold;
        moreLanes = laneNumber != 3;
        laneNumber = laneNumber + 1;
      } while (moreLanes);
    }
    if ((!constantsAreZero) && (sourceOpcode = IRInst__compareResultIsConstant(sourceInst), sourceOpcode == 0)) {
      return 0;
    }
    canFold = 1;
  }
  else {
setCanFold:
    canFold = 0;
  }
  return canFold;
}

/* IRInst__foldConstantSourcesIntoClone @ 0x10c670 (1240 bytes) */
int IRInst__foldConstantSourcesIntoClone(inst, inst2, pass)
  int inst;
  int *inst2;
  int pass;
{
  double constantValueB;
  uint savedLaneSelectByte;
  uint candidateLaneByteB;
  bool moreLanesB;
  int laneIndexB;
  int laneIndex;
  int foundOperandNumberB;
  int shiftSourceNumber;
  int foundOperandNumberA;
  int insertedOperandNumberB;
  int foundSlotB;
  int targetOperandCount;
  int insertedOperandNumber;
  int foundSlotA;
  int sourceOperandNumber;
  undefined8 allHwConstantsResult;
  undefined4 rebuiltSwizzle;
  undefined4 sourceDef3;
  undefined8 sourceDef2;
  int operandRecord3;
  int operandRecord5;
  int operandRecord4;
  int sourceDef;
  int operandRecord2;
  int loopIndex2;
  int loopIndex;
  bool moreLanes;
  int *sourceInst;
  int sourceIsCopyBarrier;
  int *clonedSourceDef;
  int destSwizzleWord;
  int operandRecord;
  undefined4 sourceSwizzleWord;
  undefined4 staleArg6;
  undefined4 staleArg7;
  undefined4 staleArg8;
  undefined4 staleArg9;
  int inputBasePlusOne;
  int inputBase;
  uint candidateLaneByte;
  uint laneSelectByte;
  double constantValueA;
  undefined8 findResult;
  undefined4 swizzleWord;
  int foundSlotOut [6];
  
  sourceInst = (int *)IRInst__getOperandSource(inst,1);
  operandRecord2 = IRInst__getOperandRecord(inst,1);
  sourceSwizzleWord = *(undefined4 *)(operandRecord2 + 0x10);
  allHwConstantsResult = IRInst__allSelectsAreHwConstants(sourceInst,pass,sourceSwizzleWord,staleArg6,staleArg7,staleArg8,staleArg9);
  if ((int)((ulonglong)allHwConstantsResult >> 0x20) == 0) {
    inputBase = *(int *)(*(int *)(pass + 0x6c4) + 0x478);
    sourceIsCopyBarrier = (**(code **)(*sourceInst + 0x5c))
                      (sourceInst,(int)allHwConstantsResult,sourceSwizzleWord,staleArg6,staleArg7,staleArg8,*(int *)(pass + 0x6c4));
    if (sourceIsCopyBarrier == 0) {
      if (inputBase < sourceInst[0x58]) {
        sourceInst[0x58] = sourceInst[0x58] + 1;
      }
      else {
        sourceInst[0x58] = inputBase + 1;
      }
    }
    else {
      inputBasePlusOne = inputBase + 1;
      clonedSourceDef = (int *)IRInst__clone(sourceInst,pass,0);
      clonedSourceDef[0x26] = 0x31;
      clonedSourceDef[0x25] = clonedSourceDef[0x53];
      Block__insertInstAfter(sourceInst[0x56],sourceInst,clonedSourceDef);
      clonedSourceDef[0x58] = inputBasePlusOne;
      sourceDef = IRInst__getOperandSource(clonedSourceDef,1);
      if (inputBase < *(int *)(sourceDef + 0x160)) {
        *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
      }
      else {
        *(int *)(sourceDef + 0x160) = inputBasePlusOne;
      }
      sourceInst = clonedSourceDef;
      if (1 < clonedSourceDef[0x21]) {
        sourceDef = IRInst__getOperandSource(clonedSourceDef,2);
        if (inputBase < *(int *)(sourceDef + 0x160)) {
          *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
        }
        else {
          *(int *)(sourceDef + 0x160) = inputBasePlusOne;
        }
      }
    }
    IRInst__setOperandSource(inst2,1,sourceInst,0,pass);
    if ((*(uint *)(*(int *)(pass + 0x6c4) + 0x30) & 8) == 0) {
      IRInst__setOperandRef(inst2,1,*(undefined4 *)(inst + 0xa4));
    }
    else {
      IRInst__dropCounterAndDeleteIfUnused(inst,pass);
    }
    laneIndex = 0;
    swizzleWord = 0x4040404;
    do {
      operandRecord3 = IRInst__getOperandRecord(inst2,1);
      laneSelectByte = (uint)*(byte *)(laneIndex + operandRecord3 + 0x10);
      if (laneSelectByte != 4) {
        operandRecord3 = IRInst__getOperandRecord(inst,1);
        if (*(char *)(laneSelectByte + operandRecord3 + 0x10) == '\x04') {
          if (1 < *(int *)(inst + 0x84)) {
            sourceOperandNumber = 2;
            do {
              operandRecord5 = IRInst__getOperandRecord(inst,sourceOperandNumber);
              candidateLaneByte = (uint)*(byte *)(laneSelectByte + operandRecord5 + 0x10);
              if (candidateLaneByte != 4) {
                sourceDef2 = IRInst__getOperandSource(inst,sourceOperandNumber);
                constantValueA = (double)*(float *)(candidateLaneByte * 0x18 + (int)((ulonglong)sourceDef2 >> 0x20) + 0x20);
                findResult = ((int (*)())IRInst__findConstantOperandWithValue)(inst2,(int)sourceDef2,foundSlotOut,constantValueA);
                foundSlotA = foundSlotOut[0];
                foundOperandNumberA = (int)((ulonglong)findResult >> 0x20);
                if (foundOperandNumberA == 0) {
                  insertedOperandNumber = inst2[0x21];
                  ((void (*)())IRInst__setLiteralOperandAndSource)(inst2,(int)findResult,insertedOperandNumber + 1,pass,constantValueA);
                  (**(code **)(*inst2 + 0x88))(inst2,insertedOperandNumber + 1,laneIndex,laneIndex);
                }
                else if (foundSlotOut[0] != laneIndex) {
                  operandRecord4 = IRInst__getOperandRecord(inst2,foundOperandNumberA);
                  (**(code **)(*inst2 + 0x88))
                            (inst2,foundOperandNumberA,laneIndex,*(undefined1 *)(foundSlotA + operandRecord4 + 0x10));
                }
                break;
              }
              sourceOperandNumber = sourceOperandNumber + 1;
            } while (sourceOperandNumber <= *(int *)(inst + 0x84));
          }
        }
        else {
          operandRecord3 = IRInst__getOperandRecord(inst,1);
          *(undefined1 *)((int)foundSlotOut + laneIndex + -4) = *(undefined1 *)(laneSelectByte + operandRecord3 + 0x10);
        }
      }
      rebuiltSwizzle = swizzleWord;
      moreLanes = laneIndex != 3;
      laneIndex = laneIndex + 1;
    } while (moreLanes);
    operandRecord2 = IRInst__getOperandRecord(inst2,1);
    *(undefined4 *)(operandRecord2 + 0x10) = rebuiltSwizzle;
  }
  else {
    operandRecord2 = IRInst__getOperandRecord(inst2,1);
    targetOperandCount = inst2[0x21];
    swizzleWord = *(undefined4 *)(operandRecord2 + 0x10);
    if (1 < targetOperandCount) {
      shiftSourceNumber = 2;
      loopIndex = 1;
      do {
        sourceDef3 = IRInst__getOperandSource(inst2,shiftSourceNumber);
        IRInst__setOperandSource(inst2,loopIndex,sourceDef3,0,pass);
        operandRecord4 = IRInst__getOperandRecord(inst2,shiftSourceNumber);
        destSwizzleWord = *(int *)(operandRecord4 + 0x10);
        if (loopIndex == 0) {
          inst2[0x27] = destSwizzleWord;
        }
        else {
          operandRecord = IRInst__getOperandRecord(inst2,loopIndex);
          *(int *)(operandRecord + 0x10) = destSwizzleWord;
        }
        shiftSourceNumber = shiftSourceNumber + 1;
        loopIndex = loopIndex + 1;
      } while (shiftSourceNumber <= targetOperandCount);
    }
    inst2[0x21] = targetOperandCount + -1;
    laneIndexB = 0;
    do {
      savedLaneSelectByte = (uint)*(byte *)((int)foundSlotOut + laneIndexB + -4);
      if ((savedLaneSelectByte != 4) && (0 < *(int *)(inst + 0x84))) {
        loopIndex2 = 1;
        do {
          operandRecord5 = IRInst__getOperandRecord(inst,loopIndex2);
          candidateLaneByteB = (uint)*(byte *)(savedLaneSelectByte + operandRecord5 + 0x10);
          if (candidateLaneByteB != 4) {
            sourceDef2 = IRInst__getOperandSource(inst,loopIndex2);
            constantValueB = (double)*(float *)(candidateLaneByteB * 0x18 + (int)((ulonglong)sourceDef2 >> 0x20) + 0x20);
            findResult = ((int (*)())IRInst__findConstantOperandWithValue)(inst2,(int)sourceDef2,foundSlotOut,constantValueB);
            foundSlotB = foundSlotOut[0];
            foundOperandNumberB = (int)((ulonglong)findResult >> 0x20);
            if (foundOperandNumberB == 0) {
              insertedOperandNumberB = inst2[0x21];
              ((void (*)())IRInst__setLiteralOperandAndSource)(inst2,(int)findResult,insertedOperandNumberB + 1,pass,constantValueB);
              (**(code **)(*inst2 + 0x88))(inst2,insertedOperandNumberB + 1,laneIndexB,laneIndexB);
            }
            else if (foundSlotOut[0] != laneIndexB) {
              operandRecord4 = IRInst__getOperandRecord(inst2,foundOperandNumberB);
              (**(code **)(*inst2 + 0x88))
                        (inst2,foundOperandNumberB,laneIndexB,*(undefined1 *)(foundSlotB + operandRecord4 + 0x10));
            }
            break;
          }
          loopIndex2 = loopIndex2 + 1;
        } while (loopIndex2 <= *(int *)(inst + 0x84));
      }
      moreLanesB = laneIndexB != 3;
      laneIndexB = laneIndexB + 1;
    } while (moreLanesB);
    IRInst__dropCounterAndDeleteIfUnused(inst,pass);
  }
  return;
}

/* IRInst__foldCompareResultIntoCopy @ 0x10cb48 (1156 bytes) */
int IRInst__foldCompareResultIntoCopy(inst, pass)
  int inst;
  int pass;
{
  int *copyInstFromList;
  uint recordLaneByte;
  int passArg;
  bool atLastLane;
  int operandNumberC;
  int maskCountdown;
  int operandNumberB;
  int operandNumberA;
  int laneCountdown;
  int operandNumberD;
  int maskLaneIndex;
  int laneNumber;
  int sourceBlock;
  int laneByteIndex;
  undefined4 sourceDef;
  int operandRecord2;
  int operandRecord3;
  int operandRecord;
  int sourceDef2;
  bool moreLanes;
  int inputBase;
  int *operandVReg;
  int foundOperand;
  int *newSource;
  int operandCountLimit;
  int laneStep;
  undefined4 staleArg4;
  undefined4 staleArg8;
  undefined4 fallbackSourceValue;
  undefined4 *copyListCursor;
  uint laneSelector;
  int *copyInst;
  int operandNumber;
  double fparam_1;
  undefined8 constantSearchResult;
  int destMaskWord;
  undefined4 sourceDestMaskWord;
  undefined4 swizzleWord;
  int selectSwizzle;
  undefined4 operandSwizzle;
  int foundOperandSlots [2];
  undefined4 copyInsts [5];
  float foldedCompareResult [4];
  
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  inputBase = *(int *)(*(int *)(pass + 0x6c4) + 0x478);
  if (inputBase < operandVReg[0x58]) {
    operandVReg[0x58] = operandVReg[0x58] + 1;
  }
  else {
    operandVReg[0x58] = inputBase + 1;
  }
  operandRecord = IRInst__getOperandRecord(inst,1);
  swizzleWord = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst,0);
  destMaskWord = *(int *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(operandVReg,0);
  sourceDestMaskWord = *(undefined4 *)(operandRecord + 0x10);
  if ((operandVReg[5] & 0x200U) != 0) {
    laneByteIndex = 0;
    laneCountdown = 4;
    do {
      if ((*(byte *)((int)&swizzleWord + laneByteIndex) != 4) &&
         (*(char *)((int)&sourceDestMaskWord + (uint)*(byte *)((int)&swizzleWord + laneByteIndex)) == '\x01')) {
        *(undefined1 *)((int)&destMaskWord + laneByteIndex) = 1;
        *(undefined1 *)((int)&swizzleWord + laneByteIndex) = 4;
      }
      laneByteIndex = laneByteIndex + 1;
      laneCountdown = laneCountdown + -1;
    } while (laneCountdown != 0);
  }
  sourceBlock = operandVReg[0x56];
  copyListCursor = copyInsts;
  for (operandNumberA = 1; operandCountLimit = (**(code **)(*operandVReg + 0x14))(operandVReg), operandNumberA <= operandCountLimit;
      operandNumberA = operandNumberA + 1) {
    laneStep = 0;
    *(int *)(*(int *)(pass + 0x6c4) + 0x228) = *(int *)(*(int *)(pass + 0x6c4) + 0x228) + 1;
    copyInst = (int *)IRLoadConst__vslot73(0xa2,pass);
    *copyListCursor = copyInst;
    copyInst[0x26] = 0x36;
    copyInst[0x25] = copyInst[0x53];
    copyInst[0x21] = 1;
    copyInst[0x4b] = 1;
    sourceDef = IRInst__getOperandSource(operandVReg,operandNumberA);
    passArg = pass;
    IRInst__setOperandSource(copyInst,1,sourceDef,0,pass);
    copyInst[0x27] = destMaskWord;
    operandRecord3 = IRInst__getOperandRecord(operandVReg,operandNumberA);
    operandSwizzle = *(undefined4 *)(operandRecord3 + 0x10);
    do {
      laneSelector = (uint)*(byte *)((int)&swizzleWord + laneStep);
      if (laneSelector != 4) {
        (**(code **)(*copyInst + 0x88))
                  (copyInst,1,laneStep,(uint)*(byte *)((int)foundOperandSlots + (laneSelector - 4)),passArg,staleArg8,
                   (int)&destMaskWord + laneSelector);
      }
      moreLanes = laneStep != 3;
      laneStep = laneStep + 1;
    } while (moreLanes);
    Block__insertInstBefore(sourceBlock,operandVReg,copyInst);
    newSource = (int *)IRInst__getOperandSource(copyInst,1);
    operandCountLimit = (**(code **)(*newSource + 0x60))(newSource);
    if (operandCountLimit != 0) {
      sourceDef = IRInst__getOperandSource(copyInst,1);
      ((int (*)())IRInst__foldConstantSourcesIntoClone)(sourceDef,copyInst,pass);
    }
    IRInst__setOperandSource(operandVReg,operandNumberA,copyInst,0,pass);
    copyListCursor = copyListCursor + 1;
    copyInst[0x58] = *(int *)(*(int *)(pass + 0x6c4) + 0x478) + 1;
  }
  laneNumber = 0;
  do {
    if ((*(char *)((int)&destMaskWord + laneNumber) != '\x01') &&
       (*(char *)((int)&swizzleWord + laneNumber) == '\x04')) {
      if (1 < *(int *)(inst + 0x84)) {
        operandNumber = 2;
        do {
          operandCountLimit = IRInst__getOperandRecord(inst,operandNumber);
          recordLaneByte = (uint)*(byte *)(laneNumber + operandCountLimit + 0x10);
          if (recordLaneByte != 4) {
            sourceDef2 = IRInst__getOperandSource(inst,operandNumber);
            fallbackSourceValue = *(undefined4 *)(recordLaneByte * 0x18 + sourceDef2 + 0x20);
            goto setCopyListCursor;
          }
          operandNumber = operandNumber + 1;
        } while (operandNumber <= *(int *)(inst + 0x84));
      }
      fallbackSourceValue = 0;
setCopyListCursor:
      copyListCursor = copyInsts;
      for (operandNumberB = 1; operandCountLimit = (**(code **)(*operandVReg + 0x14))(operandVReg), operandNumberB <= operandCountLimit;
          operandNumberB = operandNumberB + 1) {
        IRInst__foldCompareConstResult(foldedCompareResult,operandVReg,operandNumberB,fallbackSourceValue,pass);
        fparam_1 = (double)foldedCompareResult[0];
        copyInstFromList = (int *)*copyListCursor;
        constantSearchResult = ((int (*)())IRInst__findConstantOperandWithValue)(copyInstFromList,staleArg4,foundOperandSlots,fparam_1);
        operandCountLimit = foundOperandSlots[0];
        foundOperand = (int)((ulonglong)constantSearchResult >> 0x20);
        if (foundOperand == 0) {
          operandCountLimit = copyInstFromList[0x21];
          ((void (*)())IRInst__setLiteralOperandAndSource)(copyInstFromList,(int)constantSearchResult,operandCountLimit + 1,pass,fparam_1);
          (**(code **)(*copyInstFromList + 0x88))(copyInstFromList,operandCountLimit + 1,laneNumber,laneNumber);
        }
        else {
          operandRecord2 = IRInst__getOperandRecord(copyInstFromList,foundOperand);
          (**(code **)(*copyInstFromList + 0x88))(copyInstFromList,foundOperand,laneNumber,*(undefined1 *)(operandCountLimit + operandRecord2 + 0x10));
        }
        copyListCursor = copyListCursor + 1;
      }
    }
    atLastLane = laneNumber == 3;
    laneNumber = laneNumber + 1;
    if (atLastLane) {
      maskLaneIndex = 0;
      operandVReg[0x27] = destMaskWord;
      selectSwizzle = 0x10203;
      maskCountdown = 4;
      do {
        if (*(char *)((int)&destMaskWord + maskLaneIndex) == '\x01') {
          *(undefined1 *)((int)&selectSwizzle + maskLaneIndex) = 4;
        }
        maskLaneIndex = maskLaneIndex + 1;
        maskCountdown = maskCountdown + -1;
      } while (maskCountdown != 0);
      for (operandNumberD = 1; operandCountLimit = (**(code **)(*operandVReg + 0x14))(operandVReg), operandNumberC = selectSwizzle,
          operandNumberD <= operandCountLimit; operandNumberD = operandNumberD + 1) {
        if (operandNumberD == 0) {
          operandVReg[0x27] = selectSwizzle;
        }
        else {
          operandCountLimit = IRInst__getOperandRecord(operandVReg,operandNumberD);
          *(int *)(operandCountLimit + 0x10) = operandNumberC;
        }
      }
      IRInst__dropCounterAndDeleteIfUnused(inst,pass);
      return operandVReg;
    }
  } while( true );
}

/* IRInst__foldMovSourceSelect @ 0x10cfcc (400 bytes) */
int IRInst__foldMovSourceSelect(outSelect, inst, operandIndex, program)
  undefined4 *outSelect;
  undefined4 inst;
  undefined4 operandIndex;
  int program;
{
  int hasNoUsesResult;
  int isMovLike;
  undefined4 sourceDef;
  int operandRecord;
  int loopIndex;
  byte selectByte;
  int *a0;
  int splatLane;
  int srcRecord;
  undefined4 innerSelect;
  undefined4 trackUses;
  undefined4 compilerArg;
  undefined4 staleR8;
  undefined4 staleR9;
  undefined4 composedSelect [2];
  
  a0 = (int *)IRInst__getOperandSource(inst,operandIndex);
  isMovLike = (**(code **)(*a0 + 0x60))(a0);
  if (isMovLike != 0) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    splatLane = SelectWord__splatComponent(*(undefined4 *)(operandRecord + 0x10));
    srcRecord = IRInst__getOperandRecord(inst,operandIndex);
    selectByte = *(byte *)(splatLane + srcRecord + 0x10);
    if (-1 < splatLane) {
      IRInst__getOperandRecord(a0,0);
    }
    for (loopIndex = 1; srcRecord = (**(code **)(*a0 + 0x14))(a0), loopIndex <= srcRecord; loopIndex = loopIndex + 1) {
      srcRecord = IRInst__getOperandRecord(a0,loopIndex);
      if (*(char *)((uint)selectByte + srcRecord + 0x10) != '\x04') {
        sourceDef = IRInst__getOperandSource(a0,loopIndex);
        compilerArg = *(undefined4 *)(program + 8);
        trackUses = 1;
        IRInst__setOperandSource(inst,operandIndex,sourceDef,1,compilerArg);
        hasNoUsesResult = IRInst__hasNoUses(a0,program,sourceDef,trackUses,compilerArg,staleR8,staleR9);
        if (hasNoUsesResult != 0) {
          (**(code **)(*a0 + 0xc))(a0,1,*(undefined4 *)(program + 8));
        }
        operandRecord = IRInst__getOperandRecord(a0,loopIndex);
        innerSelect = *(undefined4 *)(operandRecord + 0x10);
        operandRecord = IRInst__getOperandRecord(inst,operandIndex);
        SelectWord__compose(composedSelect,innerSelect,*(undefined4 *)(operandRecord + 0x10));
        *outSelect = composedSelect[0];
        return outSelect;
      }
    }
  }
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  *outSelect = *(undefined4 *)(operandRecord + 0x10);
  return outSelect;
}

/* IRInst__replaceWithMovOfSource @ 0x10d15c (448 bytes) */
int IRInst__replaceWithMovOfSource(inst, operandIndex, trackUses, compiler)
  int *inst;
  int operandIndex;
  int trackUses;
  int compiler;
{
  int operandRecord3;
  int operandRecord2;
  uint operandModifiers;
  int useCount;
  int destSelect;
  undefined4 operandVReg;
  int operandRecord;
  undefined4 operandVReg2;
  int nextLink;
  int ownerBlock;
  int debugVector;
  undefined4 operandSelect;
  int outputClampFlag;
  int scaleExponentWord;
  int program;
  int otherIndex;
  undefined4 lastOperandRecord;
  int lastOperandSource;
  undefined4 lastOperandFlags;
  
  program = *(int *)(compiler + 0x6c4);
  nextLink = inst[2];
  ownerBlock = inst[0x56];
  debugVector = inst[4];
  useCount = IRInst__useCount(inst,program);
  operandRecord3 = IRInst__getOperandRecord(inst,0);
  destSelect = *(int *)(operandRecord3 + 0x10);
  lastOperandFlags = 0;
  lastOperandRecord = 0;
  lastOperandSource = 0;
  outputClampFlag = inst[0x48];
  scaleExponentWord = inst[0x49];
  if ((inst[5] & 0x200U) != 0) {
    IRInst__readLastOperand(inst,&lastOperandRecord);
  }
  operandVReg = IRInst__getOperandSource(inst,operandIndex);
  operandModifiers = inst[operandIndex * 6 + 0x28];
  otherIndex = 1;
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  operandSelect = *(undefined4 *)(operandRecord + 0x10);
  if (trackUses == 0) {
    for (; operandRecord = (**(code **)(*inst + 0x14))(inst), otherIndex <= operandRecord; otherIndex = otherIndex + 1) {
      if (otherIndex != operandIndex) {
        operandVReg2 = IRInst__getOperandSource(inst,otherIndex);
        IRInst__dropCounterAndDeleteIfUnused(operandVReg2,compiler);
      }
    }
    DList__unlink(inst);
  }
  else {
    (**(code **)(*inst + 0xc))(inst,1,compiler);
  }
  IRInst__reinitAsMov(inst,0x31,*(undefined4 *)(program + 8));
  inst[4] = debugVector;
  inst[0x58] = useCount + *(int *)(program + 0x478);
  inst[0x26] = 0;
  inst[0x25] = inst[0x53];
  inst[0x48] = outputClampFlag;
  inst[0x49] = scaleExponentWord;
  inst[0x27] = destSelect;
  IRInst__setOperandSource(inst,1,operandVReg,0,compiler);
  IROperand__setModifierBits(inst + 0x29,1,operandModifiers & 1);
  IROperand__setModifierBits(inst + 0x29,2,operandModifiers >> 1 & 1);
  operandRecord2 = IRInst__getOperandRecord(inst,1);
  *(undefined4 *)(operandRecord2 + 0x10) = operandSelect;
  if (lastOperandSource != 0) {
    IRInst__setLastOperandFromRecord(inst,&lastOperandRecord,trackUses,compiler);
  }
  return Block__insertInstBefore(ownerBlock,nextLink,inst);
}

/* IRInst__canonicalizeCommutativeOperands @ 0x10d358 (372 bytes) */
int IRInst__canonicalizeCommutativeOperands(inst, compiler)
  int inst;
  uint compiler;
{
  undefined4 src2Kind;
  int flagBit7Result;
  int uniformSourceConstant;
  int sourceDef;
  int operandRecord;
  int flagBit0Result;
  int uniformSourceConstant2;
  undefined4 destSelect;
  undefined4 src1Kind;
  undefined1 constantBuf1 [4];
  float constantValue1;
  undefined1 constantBuf2 [4];
  float constantValue2;
  
  flagBit0Result = OpcodeTraits__flagBit0(*(undefined4 *)(*(int *)(inst + 0x88) + 8),compiler);
  if (flagBit0Result != 0) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    destSelect = *(undefined4 *)(operandRecord + 0x10);
    uniformSourceConstant = IRInst__getUniformSourceConstant(inst,1,destSelect,constantBuf1);
    uniformSourceConstant2 = IRInst__getUniformSourceConstant(inst,2,destSelect,constantBuf2);
    if (uniformSourceConstant == 0) {
      sourceDef = IRInst__getOperandSource(inst,1);
      src1Kind = *(undefined4 *)(sourceDef + 0x98);
      sourceDef = IRInst__getOperandSource(inst,2);
      src2Kind = *(undefined4 *)(sourceDef + 0x98);
      flagBit7Result = RegKind__flagBit7(src1Kind);
      if (flagBit7Result == 0) {
        return;
      }
      flagBit7Result = RegKind__flagBit7(src2Kind);
      if (flagBit7Result != 0) {
        return;
      }
    }
    else if (uniformSourceConstant2 != 0) {
      if ((((constantValue1 != 1.0) && (constantValue1 != -1.0)) && (constantValue1 != 2.0)) && (constantValue1 != -2.0)) {
        return;
      }
      if (constantValue2 == 1.0) {
        return;
      }
      if (constantValue2 == -1.0) {
        return;
      }
      if (constantValue2 == 2.0) {
        return;
      }
      if (constantValue2 == -2.0) {
        return;
      }
    }
    IRInst__swapOperands(inst,1,2,compiler);
  }
  return;
}

/* IRInst__convertCompareToBinaryAlu @ 0x10d4cc (280 bytes) */
int IRInst__convertCompareToBinaryAlu(inst, compiler)
  int inst;
  int compiler;
{
  int compareCondition;
  int operandRecord;
  uint negate1;
  uint negate2;
  undefined4 defaultSelect;
  undefined4 operandVReg;
  int iVar5;
  undefined4 operandVReg2;
  undefined4 newOpcode;
  undefined4 staleR5;
  undefined4 staleR6;
  undefined4 staleR7;
  undefined4 staleR8;
  undefined4 staleR9;
  undefined4 select2;
  uint abs2;
  undefined4 select1;
  uint abs1;
  undefined4 instId;
  int *block;
  undefined8 blockQuery;
  
  operandVReg = IRInst__getOperandSource(inst,1);
  negate1 = *(uint *)(inst + 0xb8) & 1;
  abs1 = *(uint *)(inst + 0xb8) >> 1 & 1;
  operandRecord = IRInst__getOperandRecord(inst,1);
  select1 = *(undefined4 *)(operandRecord + 0x10);
  operandVReg2 = IRInst__getOperandSource(inst,2);
  negate2 = *(uint *)(inst + 0xd0) & 1;
  abs2 = *(uint *)(inst + 0xd0) >> 1 & 1;
  operandRecord = IRInst__getOperandRecord(inst,2);
  defaultSelect = swizzleXYYY_001af9dc;
  block = *(int **)(inst + 0x158);
  select2 = *(undefined4 *)(operandRecord + 0x10);
  instId = *(undefined4 *)(inst + 0x14c);
  blockQuery = (**(code **)(*block + 0x24))(block);
  if ((int)((ulonglong)blockQuery >> 0x20) != 0) {
    Block__getBranchInst(block,(int)blockQuery,staleR5,staleR6,staleR7,staleR8,staleR9);
    block[0x4c] = 0;
  }
  DList__unlink(inst);
  compareCondition = IRInst__getCompareCondition(inst);
  newOpcode = *(undefined4 *)(PTR_DAT_001e8c70 + compareCondition * 4);
  iVar5 = *(int *)(PTR_DAT_001e8c6c + compareCondition * 4);
  *(int *)(*(int *)(compiler + 0x6c4) + 0x21c) = *(int *)(*(int *)(compiler + 0x6c4) + 0x21c) + 1;
  IRInst__reinitAsBinary(inst,newOpcode,compiler);
  *(undefined4 *)(inst + 0x94) = instId;
  *(undefined4 *)(inst + 0x98) = 0;
  *(undefined4 *)(inst + 0x9c) = defaultSelect;
  if (iVar5 == 0) {
    IRInst__setOperandSource(inst,1,operandVReg,0,compiler);
    IROperand__setModifierBits(inst + 0xa4,1,negate1);
    IROperand__setModifierBits(inst + 0xa4,2,abs1);
    operandRecord = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord + 0x10) = select1;
    IRInst__setOperandSource(inst,2,operandVReg2,0,compiler);
    IROperand__setModifierBits(inst + 0xbc,1,negate2);
    IROperand__setModifierBits(inst + 0xbc,2,abs2);
    operandRecord = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord + 0x10) = select2;
  }
  else {
    IRInst__setOperandSource(inst,2,operandVReg,0,compiler);
    IROperand__setModifierBits(inst + 0xbc,1,negate1);
    IROperand__setModifierBits(inst + 0xbc,2,abs1);
    operandRecord = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord + 0x10) = select1;
    IRInst__setOperandSource(inst,1,operandVReg2,0,compiler);
    IROperand__setModifierBits(inst + 0xa4,1,negate2);
    IROperand__setModifierBits(inst + 0xa4,2,abs2);
    operandRecord = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord + 0x10) = select2;
  }
  return;
}

/* IRInst__foldConstantFactor @ 0x10d730 (636 bytes) */
int IRInst__foldConstantFactor(inst, newSource, newSelect, compiler)
  int inst;
  int *newSource;
  uint newSelect;
  int compiler;
{
  int operandRecord2;
  int useCount;
  uint negate1;
  uint negate2;
  undefined4 operandVReg;
  int operandRecord;
  undefined4 operandVReg2;
  int isConstant;
  undefined4 operandVReg3;
  undefined4 operandVReg4;
  undefined4 select2;
  undefined4 select1;
  uint abs2;
  uint abs1;
  undefined4 regKind;
  undefined4 destSelect;
  undefined4 regNumber;
  int program;
  
  operandVReg = IRInst__getOperandSource(inst,1);
  negate1 = *(uint *)(inst + 0xb8) & 1;
  abs1 = *(uint *)(inst + 0xb8) >> 1 & 1;
  operandRecord = IRInst__getOperandRecord(inst,1);
  select1 = *(undefined4 *)(operandRecord + 0x10);
  operandVReg2 = IRInst__getOperandSource(inst,2);
  negate2 = *(uint *)(inst + 0xd0) & 1;
  abs2 = *(uint *)(inst + 0xd0) >> 1 & 1;
  operandRecord = IRInst__getOperandRecord(inst,2);
  program = *(int *)(compiler + 0x6c4);
  select2 = *(undefined4 *)(operandRecord + 0x10);
  useCount = IRInst__useCount(inst,program);
  regKind = *(undefined4 *)(inst + 0x98);
  regNumber = *(undefined4 *)(inst + 0x94);
  operandRecord2 = IRInst__getOperandRecord(inst,0);
  destSelect = *(undefined4 *)(operandRecord2 + 0x10);
  DList__unlink(inst);
  isConstant = (**(code **)(*newSource + 0x48))(newSource);
  if ((isConstant != 0) && (((int)*(char *)(newSource + 0x57) >> (newSelect >> 0x18 & 0x3f) & 1U) != 0)) {
    operandVReg3 = IRInst__getOperandSource(inst,1);
    operandVReg4 = IRInst__getOperandSource(inst,2);
    *(int *)(program + 0x220) = *(int *)(program + 0x220) + 1;
    IRInst__reinitAsMov(inst,0x31,compiler);
    *(undefined4 *)(inst + 0x94) = regNumber;
    *(undefined4 *)(inst + 0x98) = regKind;
    *(undefined4 *)(inst + 0x9c) = destSelect;
    *(int *)(inst + 0x160) = useCount + *(int *)(program + 0x478);
    if (GH_U2F((unsigned int)(newSource[(newSelect >> 0x18) * 6 + 8])) == FLOAT_001aa0d4) {
      IRInst__setOperandSource(inst,1,operandVReg,0,compiler);
      IROperand__setModifierBits(inst + 0xa4,1,negate1);
      IROperand__setModifierBits(inst + 0xa4,2,abs1);
      operandRecord = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord + 0x10) = select1;
      operandVReg3 = operandVReg4;
    }
    else {
      IRInst__setOperandSource(inst,1,operandVReg2,0,compiler);
      IROperand__setModifierBits(inst + 0xa4,1,negate2);
      IROperand__setModifierBits(inst + 0xa4,2,abs2);
      operandRecord = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord + 0x10) = select2;
    }
    IRInst__dropCounterAndDeleteIfUnused(operandVReg3,compiler);
    return;
  }
  *(int *)(program + 0x224) = *(int *)(program + 0x224) + 1;
  IRInst__reinitAsTrinary(inst,0x24,compiler);
  *(undefined4 *)(inst + 0x94) = regNumber;
  *(undefined4 *)(inst + 0x98) = regKind;
  *(undefined4 *)(inst + 0x9c) = destSelect;
  *(int *)(inst + 0x160) = useCount + *(int *)(program + 0x478);
  IRInst__setOperandSource(inst,1,newSource,0,compiler);
  if (*(int *)(program + 0x478) < newSource[0x58]) {
    newSource[0x58] = newSource[0x58] + 1;
  }
  else {
    newSource[0x58] = *(int *)(program + 0x478) + 1;
  }
  operandRecord = IRInst__getOperandRecord(inst,1);
  *(uint *)(operandRecord + 0x10) = newSelect;
  IRInst__setOperandSource(inst,3,operandVReg,0,compiler);
  IROperand__setModifierBits(inst + 0xd4,1,negate1);
  IROperand__setModifierBits(inst + 0xd4,2,abs1);
  operandRecord = IRInst__getOperandRecord(inst,3);
  *(undefined4 *)(operandRecord + 0x10) = select1;
  IRInst__setOperandSource(inst,2,operandVReg2,0,compiler);
  IROperand__setModifierBits(inst + 0xbc,1,negate2);
  IROperand__setModifierBits(inst + 0xbc,2,abs2);
  operandRecord = IRInst__getOperandRecord(inst,2);
  *(undefined4 *)(operandRecord + 0x10) = select2;
  return;
}

/* HwLimits__vslot24_resetBindingTables @ 0x10da84 (84 bytes) */
int HwLimits__vslot24_resetBindingTables(this)
  int this;
{
  *(undefined4 *)(((unsigned char *)0x00001730) + this) = 0;
  *(undefined4 *)(((unsigned char *)0x0000172c) + this) = 0;
  *(undefined4 *)(((unsigned char *)0x00001728) + this) = 0;
  _memset(this + 0x68,0,0xd00);
  return _memset(this + 0xd68,0,0x9c0);
}

/* HwLimits__dtor_10dad8 @ 0x10dad8 (128 bytes) */
int HwLimits__dtor_10dad8(this)
  undefined4 *this;
{
  this[5] = 1;
  this[4] = 1;
  this[0x19] = 0;
  this[2] = 0;
  this[6] = 0;
  *this = &ptrTo_HwLimits__dtor_001ea5b0;
  this[9] = 0;
  this[10] = 0;
  this[0xb] = 0;
  this[0xc] = 0;
  this[0xd] = 0;
  this[0xe] = 0;
  this[0xf] = 0;
  this[0x10] = 0;
  this[0x11] = 0;
  this[0x12] = 0;
  this[0x13] = 0;
  this[0x14] = 0;
  this[0x15] = 0;
  this[0x16] = 0;
  this[0x17] = 0;
  this[0x18] = 0;
  return;
}

/* HwLimits__dtor_10db58 @ 0x10db58 (128 bytes) */
int HwLimits__dtor_10db58(this)
  undefined4 *this;
{
  this[5] = 1;
  this[4] = 1;
  this[0x19] = 0;
  this[2] = 0;
  this[6] = 0;
  *this = &ptrTo_HwLimits__dtor_001ea5b0;
  this[9] = 0;
  this[10] = 0;
  this[0xb] = 0;
  this[0xc] = 0;
  this[0xd] = 0;
  this[0xe] = 0;
  this[0xf] = 0;
  this[0x10] = 0;
  this[0x11] = 0;
  this[0x12] = 0;
  this[0x13] = 0;
  this[0x14] = 0;
  this[0x15] = 0;
  this[0x16] = 0;
  this[0x17] = 0;
  this[0x18] = 0;
  return;
}

/* BitSet__setBit @ 0x10dbd8 (36 bytes) */
int BitSet__setBit(bits, bitIndex)
  int bits;
  uint bitIndex;
{
  int byteAddr;
  
  byteAddr = ((int)bitIndex >> 3) + bits;
  ((unsigned char *)0x00001734)[byteAddr] = (byte)(1 << (bitIndex & 7)) | ((unsigned char *)0x00001734)[byteAddr];
  return;
}

/* BitSet__clearBit @ 0x10dbfc (36 bytes) */
int BitSet__clearBit(bits, bitIndex)
  int bits;
  uint bitIndex;
{
  int byteAddr;
  
  byteAddr = ((int)bitIndex >> 3) + bits;
  ((unsigned char *)0x00001734)[byteAddr] =
       ((byte)(-2 << (bitIndex & 7)) | (byte)(0xfffffffe >> 0x20 - (bitIndex & 7))) &
       ((unsigned char *)0x00001734)[byteAddr];
  return;
}

/* BitSet__initDefault @ 0x10dc20 (124 bytes) */
int BitSet__initDefault(bits)
  int bits;
{
  bool moreBits;
  int cursor;
  int remaining;
  
  remaining = 5;
  cursor = bits;
  do {
    ((unsigned char *)0x00001734)[cursor] = 0xff;
    cursor = cursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  remaining = 6;
  cursor = bits;
  do {
    ((unsigned char *)0x00001739)[cursor] = 0;
    cursor = cursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  cursor = 0x28;
  do {
    ((int (*)())BitSet__setBit)(bits,cursor);
    moreBits = cursor != 0x2c;
    cursor = cursor + 1;
  } while (moreBits);
  return;
}

/* BitSet__testBit @ 0x10dc9c (28 bytes) */
int BitSet__testBit(bits, bitIndex)
  int bits;
  uint bitIndex;
{
  return (int)(uint)(byte)((unsigned char *)0x00001734)[((int)bitIndex >> 3) + bits] >> (bitIndex & 7) & 1;
}

/* HwLimits__vslot77_getBindingLimitsDefault @ 0x10dcb8 (12 bytes) */
int HwLimits__vslot77_getBindingLimitsDefault(this, outLimits)
  undefined4 this;
  undefined4 *outLimits;
{
  *outLimits = 0;
  return;
}

/* HwLimits__vslot10_failNotSupported @ 0x10dcc4 (56 bytes) */
int HwLimits__vslot10_failNotSupported()
{
  
  if (*(int *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)) + 0x6c4) != 0) {
    Compiler__fail((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),0xf);
  }
  return 0;
}

/* HwLimits__vslot20_createInstWithOwner @ 0x10dd08 (68 bytes) */
int HwLimits__vslot20_createInstWithOwner(this, owner, compiler)
  undefined4 this;
  undefined4 owner;
  undefined4 compiler;
{
  int newInst;
  
  newInst = IRLoadVertex__new_109810(0xa4,compiler);
  *(undefined4 *)(newInst + 300) = owner;
  *(uint *)(newInst + 0x14) = *(uint *)(newInst + 0x14) & 0xffff7fff;
  return;
}

/* HwLimits__installDefaults @ 0x10dd54 (120 bytes) */
int HwLimits__installDefaults(hwLimits)
  int hwLimits;
{
  undefined *defaultDataA;
  undefined *defaultFunction;
  undefined *defaultDataB;
  int limitsBlock;
  
  limitsBlock = *(int *)(hwLimits + 0xc);
  *(undefined4 *)(limitsBlock + 0xc78) = 0;
  *(undefined4 *)(limitsBlock + 0x2a0) = 0;
  defaultDataB = PTR_DAT_001e8c84;
  defaultFunction = ptrTo_IRUnary__new_107df4_001e8c7c;
  defaultDataA = PTR_DAT_001e8c78;
  *(undefined4 *)(limitsBlock + 0xc60) = 0x4c;
  *(undefined **)(limitsBlock + 0xd08) = defaultDataA;
  *(undefined **)(limitsBlock + 0xc9c) = defaultDataB;
  *(undefined4 *)(limitsBlock + 0xc70) = 4;
  *(undefined **)(limitsBlock + 0xc74) = defaultFunction;
  *(undefined4 *)(limitsBlock + 0x288) = 0x4d;
  *(undefined4 *)(limitsBlock + 0x298) = 4;
  *(undefined **)(limitsBlock + 0x29c) = defaultFunction;
  *(undefined **)(*(int *)(hwLimits + 0xc) + 0xe28) = defaultDataB;
  return;
}

/* Compiler__getResourceModel @ 0x10ddcc (12 bytes) */
int Compiler__getResourceModel(compiler)
  int compiler;
{
  return *(undefined4 *)(*(int *)(compiler + 0x30c) + 0x60);
}

/* Compiler__getThreadModel @ 0x10ddd8 (12 bytes) */
int Compiler__getThreadModel(compiler)
  int compiler;
{
  return *(undefined4 *)(*(int *)(compiler + 0x30c) + 100);
}

/* Vslot__returnConst0x10c @ 0x10dde4 (8 bytes) */
int Vslot__returnConst0x10c()
{
  return 0x10c;
}

/* KhanPs__vslot16_getConstant0xb5 @ 0x10ddec (8 bytes) */
int KhanPs__vslot16_getConstant0xb5()
{
  return 0xb5;
}

/* HwLimits__vslot8_failNotSupported @ 0x10ddfc (56 bytes) */
int HwLimits__vslot8_failNotSupported(this, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6, compiler)
  undefined4 this;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  int compiler;
{
  if (*(int *)(compiler + 0x6c4) != 0) {
    Compiler__fail(compiler,0xf);
  }
  return 0;
}

/* HwLimits__vslot9_failNotSupported @ 0x10de34 (56 bytes) */
int HwLimits__vslot9_failNotSupported()
{
  
  if (*(int *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)) + 0x6c4) != 0) {
    Compiler__fail((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)),0xf);
  }
  return 0;
}

/* Program__emitLoadVertexAttr @ 0x10de6c (140 bytes) */
int Program__emitLoadVertexAttr(unusedArg1, program, unusedArg3, vertexAttrWord, unusedArg5, insertRef)
  undefined4 unusedArg1;
  int program;
  undefined4 unusedArg3;
  uint *vertexAttrWord;
  undefined4 unusedArg5;
  undefined4 insertRef;
{
  uint attrWordCopy;
  undefined4 loadVReg;
  int loadVertexInst;
  undefined4 compiler;
  undefined4 vregList;
  
  attrWordCopy = *vertexAttrWord;
  vregList = *(undefined4 *)(program + 0x3ac);
  compiler = *(undefined4 *)(program + 8);
  loadVReg = Program__registerFileOfIlType(program,*vertexAttrWord >> 0x10 & 0x3f);
  loadVReg = VRegPool__findOrCreate(vregList,loadVReg,(int)(short)attrWordCopy,0);
  loadVertexInst = IRLoadVertex__new_109810(0xa4,compiler);
  IRInst__setOperandRef(loadVertexInst,0,loadVReg);
  *(int *)(loadVertexInst + 300) = (int)(short)attrWordCopy;
  return Program__appendInst(program,loadVertexInst,insertRef);
}

/* ChipShaders__release @ 0x10defc (340 bytes) */
int ChipShaders__release(this, compiler)
  int this;
  int compiler;
{
  int entry;
  int firstEntry;
  undefined4 *shaderObject;
  
  entry = *(int *)(this + 4);
  firstEntry = 0;
  if (entry != 0) {
    shaderObject = *(undefined4 **)(entry + 0x60);
    if (shaderObject != (undefined4 *)0x0) {
      (**(code **)*shaderObject)(shaderObject);
      (**(code **)(compiler + 0x34c))(*(undefined4 *)(compiler + 0x354),shaderObject);
      entry = *(int *)(this + 4);
    }
    if (*(int *)(entry + 100) != 0) {
      /* issue #79 class: r4 = `lwz r4,0x64(r2)` (compared, then the release argument); the sibling in the
       * second block passes the same field */
      (**(code **)(compiler + 0x34c))(*(undefined4 *)(compiler + 0x354),*(int *)(entry + 100));
      entry = *(int *)(this + 4);
    }
    (**(code **)(compiler + 0x34c))(*(undefined4 *)(compiler + 0x354),entry);
    firstEntry = *(int *)(this + 4);
  }
  entry = *(int *)(this + 8);
  if ((firstEntry != entry) && (entry != 0)) {
    shaderObject = *(undefined4 **)(entry + 0x60);
    if (shaderObject != (undefined4 *)0x0) {
      (**(code **)*shaderObject)(shaderObject);
      (**(code **)(compiler + 0x34c))(*(undefined4 *)(compiler + 0x354),shaderObject);
      entry = *(int *)(this + 8);
    }
    if (*(int *)(entry + 100) != 0) {
      (**(code **)(compiler + 0x34c))(*(undefined4 *)(compiler + 0x354),*(int *)(entry + 100));
      entry = *(int *)(this + 8);
    }
    (**(code **)(compiler + 0x34c))(*(undefined4 *)(compiler + 0x354),entry);
  }
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 4) = 0;
  return;
}

/* KhanChip__ctor_10e050 @ 0x10e050 (172 bytes) */
int KhanChip__ctor_10e050(this, allocContext)
  undefined4 *this;
  undefined4 allocContext;
{
  undefined *vtable;
  int limitsObject;
  
  this[2] = 0;
  vtable = PTR_DAT_001e8c88;
  this[1] = 0;
  *this = vtable + 8;
  *this = PTR_DAT_001e8c74 + 8;
  limitsObject = Compiler__allocateOrFail(allocContext,0x1740);
  if (limitsObject != 0) {
    KhanVs__ctor_12a578(limitsObject,allocContext,1);
  }
  this[1] = limitsObject;
  limitsObject = Compiler__allocateOrFail(allocContext,0x1744);
  if (limitsObject != 0) {
    KhanPs__ctor_129130(limitsObject,allocContext,1);
  }
  this[2] = limitsObject;
  return;
}

/* KhanChip__ctor_10e114 @ 0x10e114 (172 bytes) */
int KhanChip__ctor_10e114(this, allocContext)
  undefined4 *this;
  undefined4 allocContext;
{
  undefined *vtable;
  int limitsObject;
  
  this[2] = 0;
  vtable = PTR_DAT_001e8c88;
  this[1] = 0;
  *this = vtable + 8;
  *this = PTR_DAT_001e8c74 + 8;
  limitsObject = Compiler__allocateOrFail(allocContext,0x1740);
  if (limitsObject != 0) {
    KhanVs__ctor_12a578(limitsObject,allocContext,1);
  }
  this[1] = limitsObject;
  limitsObject = Compiler__allocateOrFail(allocContext,0x1744);
  if (limitsObject != 0) {
    KhanPs__ctor_129130(limitsObject,allocContext,1);
  }
  this[2] = limitsObject;
  return;
}

/* FudoChip__ctor_10e1d8 @ 0x10e1d8 (176 bytes) */
int FudoChip__ctor_10e1d8(this, allocContext)
  undefined4 *this;
  undefined4 allocContext;
{
  undefined *vtable;
  int allocated;
  undefined *baseVtable;
  
  vtable = PTR_DAT_001e8c80;
  baseVtable = PTR_DAT_001e8c74 + 8;
  this[2] = 0;
  *this = baseVtable;
  this[1] = 0;
  *this = vtable + 8;
  allocated = Compiler__allocateOrFail(allocContext,0x1740);
  if (allocated != 0) {
    FudoVs__ctor_12a8bc(allocated,allocContext,1);
  }
  this[1] = allocated;
  allocated = Compiler__allocateOrFail(allocContext,0x1944);
  if (allocated != 0) {
    FudoPs__ctor_1920e0(allocated,allocContext,1);
  }
  this[2] = allocated;
  return;
}

/* FudoChip__ctor_10e2a0 @ 0x10e2a0 (176 bytes) */
int FudoChip__ctor_10e2a0(this, allocContext)
  undefined4 *this;
  undefined4 allocContext;
{
  undefined *vtable;
  int allocated;
  undefined *baseVtable;
  
  vtable = PTR_DAT_001e8c80;
  baseVtable = PTR_DAT_001e8c74 + 8;
  this[2] = 0;
  *this = baseVtable;
  this[1] = 0;
  *this = vtable + 8;
  allocated = Compiler__allocateOrFail(allocContext,0x1740);
  if (allocated != 0) {
    FudoVs__ctor_12a8bc(allocated,allocContext,1);
  }
  this[1] = allocated;
  allocated = Compiler__allocateOrFail(allocContext,0x1944);
  if (allocated != 0) {
    FudoPs__ctor_1920e0(allocated,allocContext,1);
  }
  this[2] = allocated;
  return;
}

/* RegKind__laneSourceCount @ 0x10e368 (76 bytes) */
int RegKind__laneSourceCount(regKind)
  int regKind;
{
  int laneSourceCount;
  int widthKind;
  
  laneSourceCount = 3;
  if (regKind != 0x18) {
    widthKind = RegKind__vectorWidthKind(regKind);
    laneSourceCount = 1;
    if (widthKind != 0x15) {
      laneSourceCount = (uint)(widthKind == 0x16) << 1;
    }
  }
  return laneSourceCount;
}

/* Array__firstIndexOfEntry @ 0x10e3b4 (88 bytes) */
int Array__firstIndexOfEntry(valueTable, position)
  int valueTable;
  int position;
{
  int *nextEntryRef;
  int foundIndex;
  int searchedValue;
  
  if (0 < position) {
    foundIndex = 0;
    searchedValue = *(int *)(position * 4 + valueTable + 4);
    if (searchedValue == *(int *)(valueTable + 4)) {
      return foundIndex;
    }
    while( true ) {
      foundIndex = foundIndex + 1;
      position = position + -1;
      if (position == 0) break;
      nextEntryRef = (int *)(valueTable + 8);
      valueTable = valueTable + 4;
      if (searchedValue == *nextEntryRef) {
        return foundIndex;
      }
    }
  }
  return -1;
}

/* Lane__remapValue @ 0x10e40c (84 bytes) */
int Lane__remapValue(kind, value)
  int kind;
  int value;
{
  if (kind != 0x16) {
    if (kind != 0x17) {
      return value;
    }
    if (value == 0) {
      return 1;
    }
    if (value != 1) {
      return value;
    }
    return 3;
  }
  if (value == 0) {
    return value;
  }
  if (value != 1) {
    return value;
  }
  return 2;
}

/* PackEntry__computeLaneMap @ 0x10e460 (140 bytes) */
int PackEntry__computeLaneMap(entryA, entryB, laneMapOut)
  int *entryA;
  int *entryB;
  int laneMapOut;
{
  bool moreLanes;
  int laneByteOffset;
  int *candidateLaneCursor;
  int matchedLane;
  int candidatesLeft;
  
  if ((*entryA != *entryB) && (entryA[5] <= entryB[5])) {
    laneByteOffset = 0;
    do {
      if (entryA[1] == 0) {
        *(undefined4 *)(laneMapOut + laneByteOffset) = 0xffffffff;
      }
      else {
        candidatesLeft = 4;
        matchedLane = 0;
        candidateLaneCursor = entryB;
        while (entryA[1] != candidateLaneCursor[1]) {
          matchedLane = matchedLane + 1;
          candidateLaneCursor = candidateLaneCursor + 1;
          candidatesLeft = candidatesLeft + -1;
          if (candidatesLeft == 0) {
            return 0;
          }
        }
        *(int *)(laneByteOffset + laneMapOut) = matchedLane;
      }
      moreLanes = laneByteOffset != 0xc;
      entryA = entryA + 1;
      laneByteOffset = laneByteOffset + 4;
    } while (moreLanes);
    return 1;
  }
  return 0;
}

/* Compare__ascendingByWrittenComponents @ 0x10e4ec (68 bytes) */
int Compare__ascendingByWrittenComponents(inst, inst2)
  undefined4 inst;
  undefined4 inst2;
{
  int countWrittenComponentsResult;
  int countWrittenComponentsResult2;
  
  countWrittenComponentsResult = IRInst__countWrittenComponents(inst);
  countWrittenComponentsResult2 = IRInst__countWrittenComponents(inst2);
  return countWrittenComponentsResult < countWrittenComponentsResult2;
}

/* Index__scaleForMode @ 0x10e530 (44 bytes) */
int Index__scaleForMode(mode, value)
  int mode;
  int value;
{
  if (mode == 6) {
    return value << 1;
  }
  if (mode != 7) {
    return value;
  }
  return value * 2 + 1;
}

/* Vslot__outZeroReturnZero @ 0x10e55c (16 bytes) */
int Vslot__outZeroReturnZero(unusedArg1, unusedArg2, unusedArg3, out)
  undefined4 unusedArg1;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 *out;
{
  *out = 0;
  return 0;
}

/* Program__assignHwRegsToVertexLoads @ 0x10e56c (200 bytes) */
int Program__assignHwRegsToVertexLoads(backend, program)
  int *backend;
  int program;
{
  int nextHwRegister;
  int nextInstLink;
  int inst;
  
  if (*(int *)(program + 0x3d4) == 0) {
    inst = *(int *)(program + 0x3a0);
    nextHwRegister = (**(code **)(*backend + 0xe4))(backend);
    inst = *(int *)(inst + 0x98);
    for (nextInstLink = *(int *)(inst + 8); nextInstLink != 0; nextInstLink = *(int *)(nextInstLink + 8)) {
      if (((*(uint *)(inst + 0x14) & 1) != 0) && (*(int *)(*(int *)(inst + 0x88) + 8) == 0xa4)) {
        while (nextInstLink = RegAlloc__testBit42c(program,nextHwRegister), nextInstLink == 0) {
          nextHwRegister = nextHwRegister + 1;
        }
        Program__markHwRegUsed(program,nextHwRegister);
        nextInstLink = *(int *)(inst + 8);
        *(int *)(inst + 0x94) = nextHwRegister;
        *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) | 0x40;
      }
      inst = nextInstLink;
    }
  }
  return;
}

/* IRInst__query68AndWord4fNotIn6_7 @ 0x10e634 (92 bytes) */
int IRInst__query68AndWord4fNotIn6_7(outputInst)
  int *outputInst;
{
  int query68;
  undefined4 result;
  
  query68 = (**(code **)(*outputInst + 0x68))(outputInst);
  if ((query68 == 0) || (result = 1, outputInst[0x4f] - 6U < 2)) {
    result = 0;
  }
  return result;
}

/* IRInst__query68AndWord4fIs18 @ 0x10e690 (88 bytes) */
int IRInst__query68AndWord4fIs18(inst)
  int *inst;
{
  int query68;
  undefined4 result;
  
  query68 = (**(code **)(*inst + 0x68))(inst);
  if ((query68 == 0) || (result = 1, inst[0x4f] != 0x18)) {
    result = 0;
  }
  return result;
}

/* IRInst__query68AndWord4fIn16_17 @ 0x10e6e8 (92 bytes) */
int IRInst__query68AndWord4fIn16_17(inst)
  int *inst;
{
  int query68;
  undefined4 result;
  
  query68 = (**(code **)(*inst + 0x68))(inst);
  if ((query68 == 0) || (result = 1, 1 < inst[0x4f] - 0x16U)) {
    result = 0;
  }
  return result;
}

/* IRInst__query68AndWord4fNotMasked @ 0x10e744 (116 bytes) */
int IRInst__query68AndWord4fNotMasked(inst)
  int *inst;
{
  int query68;
  undefined4 result;
  
  query68 = (**(code **)(*inst + 0x68))(inst);
  if ((query68 == 0) ||
     (((uint)inst[0x4f] < 0x19 && ((1 << (inst[0x4f] & 0x3fU) & 0x1c000c0U) != 0)))) {
    result = 0;
  }
  else {
    result = 1;
  }
  return result;
}

/* LaneInfo__ctor_10e7b8 @ 0x10e7b8 (92 bytes) */
int LaneInfo__ctor_10e7b8(laneInfo, source)
  int *laneInfo;
  int source;
{
  int laneSourceCount;
  int remainingLanes;
  
  laneInfo[5] = 0;
  *laneInfo = source;
  laneSourceCount = ((int (*)())RegKind__laneSourceCount)(*(undefined4 *)(source + 0x13c));
  remainingLanes = 4;
  laneInfo[6] = laneSourceCount;
  do {
    laneInfo[1] = 0;
    laneInfo[7] = 0;
    laneInfo = laneInfo + 1;
    remainingLanes = remainingLanes + -1;
  } while (remainingLanes != 0);
  return;
}

/* LaneInfo__ctor_10e814 @ 0x10e814 (92 bytes) */
int LaneInfo__ctor_10e814(laneInfo, source)
  int *laneInfo;
  int source;
{
  int laneSourceCount;
  int remainingLanes;
  
  laneInfo[5] = 0;
  *laneInfo = source;
  laneSourceCount = ((int (*)())RegKind__laneSourceCount)(*(undefined4 *)(source + 0x13c));
  remainingLanes = 4;
  laneInfo[6] = laneSourceCount;
  do {
    laneInfo[1] = 0;
    laneInfo[7] = 0;
    laneInfo = laneInfo + 1;
    remainingLanes = remainingLanes + -1;
  } while (remainingLanes != 0);
  return;
}

/* Compare__descendingByRemappedKey @ 0x10e870 (84 bytes) */
int Compare__descendingByRemappedKey(lhsRef, rhsRef)
  int *lhsRef;
  int *rhsRef;
{
  int lhsKey;
  int rhsElement;
  int rhsKey;
  
  rhsElement = *rhsRef;
  lhsKey = ((int (*)())Lane__remapValue)(*(undefined4 *)(*lhsRef + 0x13c),*(undefined4 *)(*lhsRef + 0x140));
  rhsKey = ((int (*)())Lane__remapValue)(*(undefined4 *)(rhsElement + 0x13c),*(undefined4 *)(rhsElement + 0x140));
  return rhsKey < lhsKey;
}

/* Compare__descendingByField140 @ 0x10e8c4 (32 bytes) */
int Compare__descendingByField140(lhsRef, rhsRef)
  int *lhsRef;
  int *rhsRef;
{
  return *(int *)(*rhsRef + 0x140) < *(int *)(*lhsRef + 0x140);
}

/* PackEntry__assignLaneSources @ 0x10e8e4 (120 bytes) */
int PackEntry__assignLaneSources(packEntry, sourceLaneCursor)
  undefined4 *packEntry;
  undefined4 *sourceLaneCursor;
{
  int operandRecord;
  bool moreLanes;
  int laneCount;
  int laneIndex;
  undefined4 *laneSlotCursor;
  
  laneIndex = 0;
  laneSlotCursor = packEntry;
  do {
    operandRecord = IRInst__getOperandRecord(*packEntry,0);
    if (*(char *)(laneIndex + operandRecord + 0x10) != '\x01') {
      laneCount = packEntry[5];
      laneSlotCursor[1] = *sourceLaneCursor;
      packEntry[5] = laneCount + 1;
    }
    moreLanes = laneIndex != 3;
    sourceLaneCursor = sourceLaneCursor + 1;
    laneSlotCursor = laneSlotCursor + 1;
    laneIndex = laneIndex + 1;
  } while (moreLanes);
  return;
}

/* PackEntry__activeLaneCount @ 0x10e95c (116 bytes) */
int PackEntry__activeLaneCount(packEntry)
  undefined4 *packEntry;
{
  bool moreLanes;
  int destOperandRecord;
  int activeLaneCount;
  int laneIndex;
  undefined4 *laneSlotCursor;
  
  activeLaneCount = 0;
  laneIndex = 0;
  laneSlotCursor = packEntry;
  do {
    if ((laneSlotCursor[7] != 0) ||
       (destOperandRecord = IRInst__getOperandRecord(*packEntry,0), *(char *)(laneIndex + destOperandRecord + 0x10) == '\0')) {
      activeLaneCount = activeLaneCount + 1;
    }
    moreLanes = laneIndex != 3;
    laneSlotCursor = laneSlotCursor + 1;
    laneIndex = laneIndex + 1;
  } while (moreLanes);
  return activeLaneCount;
}

/* PackEntry__laneNeedsZero @ 0x10e9d0 (96 bytes) */
int PackEntry__laneNeedsZero(candidateGroup, laneIndex)
  undefined4 *candidateGroup;
  int laneIndex;
{
  int operandRecord;
  
  if ((candidateGroup[laneIndex + 7] == 0) &&
     (operandRecord = IRInst__getOperandRecord(*candidateGroup,0), *(char *)(laneIndex + operandRecord + 0x10) == '\x01')) {
    return 1;
  }
  return 0;
}

/* Program__callBackendFinish @ 0x10ea30 (164 bytes) */
int Program__callBackendFinish(program)
  int program;
{
  uint programFlags;
  code *UNRECOVERED_JUMPTABLE;
  int *targetObject;
  int compiler;
  
  compiler = *(int *)(program + 8);
  programFlags = *(uint *)(*(int *)(compiler + 0x6c4) + 0x30);
  if ((programFlags & 1) == 0) {
    if ((programFlags & 0x2000) == 0) {
      return;
    }
    targetObject = *(int **)(compiler + 0x30c);
    UNRECOVERED_JUMPTABLE = *(code **)(*targetObject + 0x15c);
  }
  else {
    (**(code **)(**(int **)(compiler + 0x30c) + 0x164))(*(int **)(compiler + 0x30c),program);
    targetObject = *(int **)(*(int *)(program + 8) + 0x30c);
    UNRECOVERED_JUMPTABLE = *(code **)(*targetObject + 0x160);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(targetObject,program);
  return;
}

/* PsBackend__bindExportRegisters @ 0x10ead4 (484 bytes) */
int PsBackend__bindExportRegisters(hwState, program, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int hwState;
  int program;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  int otherExportInst;
  int outputBaseC;
  int outputBaseA;
  int colorExportInst;
  int exportKind;
  int laneKindOfLane0;
  int *otherExportCursor;
  int *colorExportCursor;
  int *nextInstLink;
  int *nextInstAdvance;
  int instQuery68;
  int outputBaseB;
  int otherExportCount;
  int colorExportCount;
  int *depthExport;
  int *exportInst;
  int colorExports [16];
  int otherExports [18];
  
  exportInst = *(int **)(*(int *)(program + 0x3a8) + 0x98);
  nextInstLink = (int *)exportInst[2];
  if (nextInstLink == (int *)0x0) {
    depthExport = (int *)0x0;
    otherExportCount = 0;
    colorExportCount = 0;
  }
  else {
    depthExport = (int *)0x0;
    otherExportCount = 0;
    colorExportCount = 0;
    do {
      nextInstAdvance = nextInstLink;
      if ((exportInst[5] & 1U) == 0) goto setNextInstLink;
      instQuery68 = (**(code **)(*exportInst + 0x68))(exportInst);
      if (instQuery68 == 0) {
loopSetNextInstAdvance:
        nextInstAdvance = (int *)exportInst[2];
      }
      else {
        laneKindOfLane0 = IRLoadInterp__laneKind_104ee4(exportInst,0);
        if (((laneKindOfLane0 == 0xb) || (laneKindOfLane0 = IRLoadInterp__laneKind_104ee4(exportInst,0), laneKindOfLane0 == 0xc)) ||
           (laneKindOfLane0 = IRLoadInterp__laneKind_104ee4(exportInst,0), laneKindOfLane0 == 1)) {
          *(undefined4 *)(hwState + 0x17c8) = 1;
        }
        exportKind = exportInst[0x4f];
        if (exportKind == 6) goto loopSetNextInstAdvance;
        if (exportKind == 0x18) {
          nextInstAdvance = (int *)exportInst[2];
          depthExport = exportInst;
        }
        else {
          if (exportKind == 7) goto loopSetNextInstAdvance;
          if (exportKind - 0x16U < 2) {
            colorExports[colorExportCount] = (int)exportInst;
            colorExportCount = colorExportCount + 1;
            nextInstAdvance = (int *)exportInst[2];
          }
          else {
            otherExports[otherExportCount] = (int)exportInst;
            nextInstAdvance = (int *)exportInst[2];
            otherExportCount = otherExportCount + 1;
          }
        }
      }
setNextInstLink:
      nextInstLink = (int *)nextInstAdvance[2];
      exportInst = nextInstAdvance;
    } while ((int *)nextInstAdvance[2] != (int *)0x0);
  }
  if (*(int *)(program + 0x3e4) != 0) {
    *(int *)(program + 0x3f0) = -*(int *)(program + 1000);
    if (0 < colorExportCount) {
      colorExportCursor = colorExports;
      do {
        colorExportInst = *colorExportCursor;
        colorExportCursor = colorExportCursor + 1;
        outputBaseB = *(int *)(program + 0x3f0);
        *(undefined4 *)(colorExportInst + 0x98) = 5;
        *(int *)(colorExportInst + 0x94) = *(int *)(colorExportInst + 0x140) + outputBaseB;
        colorExportCount = colorExportCount + -1;
      } while (colorExportCount != 0);
    }
    if (depthExport != (int *)0x0) {
      outputBaseC = *(int *)(program + 0x3f0);
      depthExport[0x26] = 5;
      depthExport[0x25] = depthExport[0x50] + outputBaseC;
    }
    if (0 < otherExportCount) {
      otherExportCursor = otherExports;
      do {
        otherExportInst = *otherExportCursor;
        otherExportCursor = otherExportCursor + 1;
        outputBaseA = *(int *)(program + 0x3f0);
        *(undefined4 *)(otherExportInst + 0x98) = 5;
        *(int *)(otherExportInst + 0x94) = *(int *)(otherExportInst + 0x140) + outputBaseA;
        otherExportCount = otherExportCount + -1;
      } while (otherExportCount != 0);
    }
  }
  return;
}

/* IRInst__destMaskHasGap @ 0x10ecb8 (148 bytes) */
int IRInst__destMaskHasGap(inst)
  undefined4 inst;
{
  int operandRecord;
  bool sawOne;
  int byteIndex;
  int remaining;
  int operandWordBytes [9];
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  operandWordBytes[0] = *(int *)(operandRecord + 0x10);
  if (*(int *)(operandRecord + 0x10) != DAT_001afa18) {
    sawOne = false;
    remaining = 4;
    byteIndex = 0;
    do {
      if (*(char *)((int)operandWordBytes + byteIndex) == '\0') {
        if (sawOne) {
          return 1;
        }
      }
      else if (*(char *)((int)operandWordBytes + byteIndex) == '\x01') {
        sawOne = true;
      }
      byteIndex = byteIndex + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return 0;
}

/* KhanPs__vslot87_assignInterpolatorBindings @ 0x10ed4c (540 bytes) */
int KhanPs__vslot87_assignInterpolatorBindings(this, program)
  int *this;
  int program;
{
  uint bindingFlags;
  int laneKind;
  int loadInst;
  int operandRecord;
  bool moreLanes;
  int isInterpLoad;
  int laneUsed;
  int laneIndex;
  int otherLaneInfo;
  undefined4 kindCode;
  int *nextLink;
  int *nextInst;
  uint remainingLanes;
  int interpolatorIndex;
  uint otherLane;
  uint laneGroup;
  code *appendBinding;
  uint loopIndex;
  int *inst;
  
  inst = *(int **)(*(int *)(program + 0x3a0) + 0x98);
  nextLink = (int *)inst[2];
  if (nextLink != (int *)0x0) {
    interpolatorIndex = 0;
    do {
      nextInst = nextLink;
      if ((inst[5] & 1U) != 0) {
        isInterpLoad = (**(code **)(*inst + 0x4c))(inst);
        if (isInterpLoad == 0) {
          nextInst = (int *)inst[2];
        }
        else {
          remainingLanes = 0xf;
          loopIndex = 0;
          loadInst = (**(code **)(*inst + 0x80))(inst);
          *(undefined4 *)(loadInst + 0x98) = 0;
          *(int *)(loadInst + 0x94) = interpolatorIndex;
          *(uint *)(loadInst + 0x14) = *(uint *)(loadInst + 0x14) | 0x40;
          Program__markHwRegUsed(program,interpolatorIndex);
          do {
            laneUsed = IRLoadInterp__laneUsed(loadInst,loopIndex);
            if ((laneUsed != 0) && (laneGroup = 1 << (loopIndex & 0x3f), (laneGroup & remainingLanes) != 0)) {
              laneKind = IRLoadInterp__laneKind(loadInst,loopIndex);
              otherLane = loopIndex + 1;
              laneIndex = IRLoadInterp__laneIndex(loadInst,loopIndex);
              if ((int)otherLane < 4) {
                do {
                  otherLaneInfo = IRLoadInterp__laneUsed(loadInst,otherLane);
                  if (((otherLaneInfo != 0) && (otherLaneInfo = IRLoadInterp__laneKind(loadInst,otherLane), otherLaneInfo == laneKind)) &&
                     (otherLaneInfo = IRLoadInterp__laneIndex(loadInst,otherLane), laneIndex == otherLaneInfo)) {
                    laneGroup = laneGroup | 1 << (otherLane & 0x3f);
                  }
                  moreLanes = otherLane != 3;
                  otherLane = otherLane + 1;
                } while (moreLanes);
              }
              if (laneGroup != 0) {
                remainingLanes = remainingLanes - laneGroup;
                appendBinding = *(code **)(*this + 0x54);
                kindCode = Table__interpolatorKindToCode(program,laneKind);
                operandRecord = IRInst__getOperandRecord(loadInst,1);
                bindingFlags = *(uint *)(loadInst + 0x13c);
                (*appendBinding)(this,interpolatorIndex,kindCode,laneIndex,*(undefined4 *)(operandRecord + 0x10),bindingFlags & 1,
                           bindingFlags >> 2 & 1,bindingFlags >> 1 & 1);
              }
            }
            loopIndex = loopIndex + 1;
          } while ((int)loopIndex < 4);
          nextInst = (int *)inst[2];
          interpolatorIndex = interpolatorIndex + 1;
        }
      }
      nextLink = (int *)nextInst[2];
      inst = nextInst;
    } while ((int *)nextInst[2] != (int *)0x0);
  }
  return;
}

/* PsBackend__assignInterpolatorRegisters @ 0x10ef68 (1052 bytes) */
int PsBackend__assignInterpolatorRegisters(psBackend, program, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int *psBackend;
  int program;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  int loadInst;
  int isInterpLoadB;
  int laneIndexValue;
  uint remainingLaneMask;
  uint nextFreeRegister;
  int laneUsedB;
  int laneKind;
  int operandRecord;
  bool moreLanes;
  int *nextInstLink;
  int *inst;
  int isInterpLoad;
  undefined4 interpolatorCode;
  int *cursorInst;
  undefined4 compiler;
  uint followingLane;
  uint laneGroupMask;
  uint assignedRegister;
  uint fixedRegister;
  int regLimitOrScratch;
  uint savedNextFreeRegister;
  int fixedRegBase;
  code *bindInterpolatorFn;
  int fixedStreamKey;
  uint loopIndex;
  int entryBlock;
  undefined1 laneSelects [20];
  
  entryBlock = *(int *)(program + 0x3a4);
  if (entryBlock == 0) {
    entryBlock = *(int *)(program + 0x3a0);
  }
  compiler = *(undefined4 *)(program + 8);
  fixedStreamKey = *(int *)(program + 0x3f4);
  fixedRegBase = *(int *)(program + 1000);
  regLimitOrScratch = *(int *)(program + 0x3ec);
  if (*(int *)(program + 0x3e4) != 0) {
    inst = *(int **)(entryBlock + 0x98);
    nextInstLink = (int *)inst[2];
    if ((int *)inst[2] == (int *)0x0) goto checkInst;
    do {
      cursorInst = nextInstLink;
      if ((inst[5] & 1U) != 0) {
        isInterpLoad = (**(code **)(*inst + 0x4c))(inst);
        if ((((isInterpLoad == 0) || (isInterpLoad = inst[0x52], fixedStreamKey != inst[0x51])) || (isInterpLoad < fixedRegBase))
           || (regLimitOrScratch <= isInterpLoad)) {
          cursorInst = (int *)inst[2];
        }
        else {
          fixedRegister = isInterpLoad - fixedRegBase;
          Program__markHwRegUsed(program,fixedRegister);
          RegAlloc__clearBit430(program,fixedRegister);
          inst[0x25] = fixedRegister;
          inst[0x26] = 0;
          inst[5] = inst[5] | 0x40;
          if (*(int *)(program + 0x80) < (int)fixedRegister) {
            *(uint *)(program + 0x80) = fixedRegister;
          }
          *(uint *)(program + 0x88) = 1 << (fixedRegister & 0x3f) | *(uint *)(program + 0x88);
          cursorInst = (int *)inst[2];
        }
      }
      nextInstLink = (int *)cursorInst[2];
      inst = cursorInst;
    } while ((int *)cursorInst[2] != (int *)0x0);
  }
  inst = *(int **)(entryBlock + 0x98);
checkInst:
  if ((int *)inst[2] != (int *)0x0) {
    nextInstLink = (int *)inst[2];
    nextFreeRegister = 0;
    do {
      cursorInst = nextInstLink;
      savedNextFreeRegister = nextFreeRegister;
      if ((inst[5] & 1U) != 0) {
        isInterpLoadB = (**(code **)(*inst + 0x4c))(inst);
        if (isInterpLoadB != 0) {
          loadInst = (**(code **)(*inst + 0x80))(inst);
          if (((*(uint *)(loadInst + 0x14) & 0x40) == 0) || (*(int *)(loadInst + 0x98) != 0)) {
            for (; regLimitOrScratch = (**(code **)(*psBackend + 0x138))(psBackend,*(undefined4 *)(program + 8)),
                (int)nextFreeRegister < regLimitOrScratch; nextFreeRegister = nextFreeRegister + 1) {
              regLimitOrScratch = Program__isHwRegAllowed(program,nextFreeRegister);
              if ((regLimitOrScratch != 0) && (regLimitOrScratch = RegAlloc__testBit42c(program,nextFreeRegister), regLimitOrScratch != 0)) {
                savedNextFreeRegister = nextFreeRegister + 1;
                assignedRegister = nextFreeRegister;
                goto callProgram_markHwRegUsed;
              }
            }
            assignedRegister = 0xffffffff;
            savedNextFreeRegister = nextFreeRegister;
callProgram_markHwRegUsed:
            Program__markHwRegUsed(program,assignedRegister);
            *(undefined4 *)(loadInst + 0x98) = 0;
            *(uint *)(loadInst + 0x94) = assignedRegister;
            if (*(int *)(program + 0x80) < (int)assignedRegister) {
              *(uint *)(program + 0x80) = assignedRegister;
            }
            *(uint *)(program + 0x88) = 1 << (assignedRegister & 0x3f) | *(uint *)(program + 0x88);
            *(uint *)(loadInst + 0x14) = *(uint *)(loadInst + 0x14) | 0x40;
          }
          else {
            assignedRegister = *(uint *)(loadInst + 0x94);
          }
          if (((int)assignedRegister < 0) ||
             (regLimitOrScratch = (**(code **)(*psBackend + 0x138))(psBackend,*(undefined4 *)(program + 8)),
             regLimitOrScratch <= (int)assignedRegister)) {
            Compiler__fail(compiler,4);
          }
          regLimitOrScratch = *(int *)(loadInst + 0x144);
          if ((regLimitOrScratch != 0x1b) && (regLimitOrScratch != 0x23)) {
            if (regLimitOrScratch == 0x24) {
              *(uint *)(loadInst + 0x148) = assignedRegister;
            }
            remainingLaneMask = 0xf;
            loopIndex = 0;
            do {
              regLimitOrScratch = IRLoadInterp__laneUsed(loadInst,loopIndex);
              if ((regLimitOrScratch != 0) && (laneGroupMask = 1 << (loopIndex & 0x3f), (laneGroupMask & remainingLaneMask) != 0)) {
                laneKind = IRLoadInterp__laneKind(loadInst,loopIndex);
                laneIndexValue = IRLoadInterp__laneIndex(loadInst,loopIndex);
                regLimitOrScratch = 1;
                if (laneKind != 7) {
                  regLimitOrScratch = laneIndexValue;
                }
                followingLane = loopIndex + 1;
                if ((int)followingLane < 4) {
                  do {
                    laneUsedB = IRLoadInterp__laneUsed(loadInst,followingLane);
                    if (((laneUsedB != 0) && (laneUsedB = IRLoadInterp__laneKind(loadInst,followingLane), laneUsedB == laneKind)) &&
                       (laneUsedB = IRLoadInterp__laneIndex(loadInst,followingLane), laneIndexValue == laneUsedB)) {
                      laneGroupMask = laneGroupMask | 1 << (followingLane & 0x3f);
                    }
                    moreLanes = followingLane != 3;
                    followingLane = followingLane + 1;
                  } while (moreLanes);
                }
                if (laneGroupMask != 0) {
                  IRLoadInterp__laneSelects(laneSelects,loadInst);
                  bindInterpolatorFn = *(code **)(*psBackend + 0x54);
                  remainingLaneMask = remainingLaneMask - laneGroupMask;
                  interpolatorCode = Table__interpolatorKindToCode(program,laneKind);
                  operandRecord = IRInst__getOperandRecord(loadInst,1);
                  laneGroupMask = *(uint *)(loadInst + 0x13c);
                  (*bindInterpolatorFn)(psBackend,assignedRegister,interpolatorCode,regLimitOrScratch,*(undefined4 *)(operandRecord + 0x10),laneGroupMask & 1,
                             laneGroupMask >> 2 & 1,laneGroupMask >> 1 & 1);
                }
              }
              loopIndex = loopIndex + 1;
            } while ((int)loopIndex < 4);
          }
        }
        cursorInst = (int *)inst[2];
      }
      nextInstLink = (int *)cursorInst[2];
      nextFreeRegister = savedNextFreeRegister;
      inst = cursorInst;
    } while ((int *)cursorInst[2] != (int *)0x0);
  }
  return;
}

/* PackEntry__lanesFitVector @ 0x10f38c (328 bytes) */
int PackEntry__lanesFitVector(entry, vector)
  undefined4 *entry;
  uint *vector;
{
  bool moreEntryLanes;
  undefined4 *vectorElementRef;
  int operandRecord2;
  int operandRecord;
  bool moreOtherLanes;
  uint vectorCount;
  undefined4 *entryLaneCursor;
  int otherLaneIndex;
  int otherLanesLeft;
  int otherInst;
  int entryLaneIndex;
  int *vectorElement;
  uint loopIndex;
  int *otherLaneCursor;
  
  vectorCount = vector[1];
  if (vectorCount != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *vector) {
        if (vectorCount <= loopIndex) {
          _memset(vectorCount * 4 + vector[2],0,(loopIndex - vectorCount) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        vectorElementRef = (undefined4 *)(loopIndex * 4 + vector[2]);
      }
      else {
        vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
      }
      loopIndex = loopIndex + 1;
      vectorElement = (int *)*vectorElementRef;
      entryLaneIndex = 0;
      entryLaneCursor = entry;
      do {
        operandRecord = IRInst__getOperandRecord(*entry,0);
        if (*(char *)(entryLaneIndex + operandRecord + 0x10) != '\x01') {
          otherLaneIndex = 0;
          otherLaneCursor = vectorElement;
          do {
            operandRecord2 = IRInst__getOperandRecord(*vectorElement,0);
            if ((*(char *)(otherLaneIndex + operandRecord2 + 0x10) != '\x01') && (otherLaneCursor[1] == entryLaneCursor[1])) {
              otherLanesLeft = vectorElement[5];
              otherInst = *vectorElement;
              otherLaneCursor[1] = 0;
              vectorElement[5] = otherLanesLeft + -1;
              *(undefined1 *)(otherLaneIndex + otherInst + 0x9c) = 1;
            }
            moreOtherLanes = otherLaneIndex != 3;
            otherLaneCursor = otherLaneCursor + 1;
            otherLaneIndex = otherLaneIndex + 1;
          } while (moreOtherLanes);
        }
        moreEntryLanes = entryLaneIndex != 3;
        entryLaneCursor = entryLaneCursor + 1;
        entryLaneIndex = entryLaneIndex + 1;
      } while (moreEntryLanes);
      vectorCount = vector[1];
    } while (loopIndex < vectorCount);
  }
  return;
}

/* Program__classifyExportInsts @ 0x10f4d4 (560 bytes) */
int Program__classifyExportInsts(program)
  int program;
{
  uint *exportList424;
  uint *exportList420;
  uint listCount;
  undefined4 *listSlotRef;
  int destKindClass;
  uint *exportList41c;
  undefined4 exportInst;
  uint loopIndex;
  
  exportList41c = *(uint **)(program + 0x41c);
  listCount = exportList41c[1];
  if (listCount != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *exportList41c) {
        if (listCount <= loopIndex) {
          _memset(listCount * 4 + exportList41c[2],0,(loopIndex - listCount) * 4 + 4);
          exportList41c[1] = loopIndex + 1;
        }
        listSlotRef = (undefined4 *)(loopIndex * 4 + exportList41c[2]);
      }
      else {
        listSlotRef = (undefined4 *)Vector__elementRefGrow(exportList41c,loopIndex);
      }
      exportInst = *(undefined4 *)*listSlotRef;
      IRInst__getOperandRecord(exportInst,0);
      destKindClass = IRInst__operandKindClass(exportInst,0);
      if (destKindClass != 0) {
        return 1;
      }
      exportList41c = *(uint **)(program + 0x41c);
      loopIndex = loopIndex + 1;
      listCount = exportList41c[1];
    } while (loopIndex < listCount);
  }
  exportList420 = *(uint **)(program + 0x420);
  listCount = exportList420[1];
  if (listCount != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *exportList420) {
        if (listCount <= loopIndex) {
          _memset(listCount * 4 + exportList420[2],0,(loopIndex - listCount) * 4 + 4);
          exportList420[1] = loopIndex + 1;
        }
        listSlotRef = (undefined4 *)(loopIndex * 4 + exportList420[2]);
      }
      else {
        listSlotRef = (undefined4 *)Vector__elementRefGrow(exportList420,loopIndex);
      }
      exportInst = *(undefined4 *)*listSlotRef;
      IRInst__getOperandRecord(exportInst,0);
      destKindClass = IRInst__operandKindClass(exportInst,0);
      if (destKindClass != 0) {
        return 1;
      }
      exportList420 = *(uint **)(program + 0x420);
      loopIndex = loopIndex + 1;
      listCount = exportList420[1];
    } while (loopIndex < listCount);
  }
  exportList424 = *(uint **)(program + 0x424);
  listCount = exportList424[1];
  if (listCount != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *exportList424) {
        if (listCount <= loopIndex) {
          _memset(listCount * 4 + exportList424[2],0,(loopIndex - listCount) * 4 + 4);
          exportList424[1] = loopIndex + 1;
        }
        listSlotRef = (undefined4 *)(loopIndex * 4 + exportList424[2]);
      }
      else {
        listSlotRef = (undefined4 *)Vector__elementRefGrow(exportList424,loopIndex);
      }
      exportInst = *(undefined4 *)*listSlotRef;
      IRInst__getOperandRecord(exportInst,0);
      destKindClass = IRInst__operandKindClass(exportInst,0);
      if (destKindClass != 0) {
        return 1;
      }
      exportList424 = *(uint **)(program + 0x424);
      loopIndex = loopIndex + 1;
      listCount = exportList424[1];
    } while (loopIndex < listCount);
  }
  return 0;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_0010da84");
asm(".set FUN_0010da84, _HwLimits__vslot24_resetBindingTables");
asm(".globl FUN_0010dcb8");
asm(".set FUN_0010dcb8, _HwLimits__vslot77_getBindingLimitsDefault");
asm(".globl FUN_0010dcc4");
asm(".set FUN_0010dcc4, _HwLimits__vslot10_failNotSupported");
asm(".globl FUN_0010dd08");
asm(".set FUN_0010dd08, _HwLimits__vslot20_createInstWithOwner");
asm(".globl FUN_0010ddec");
asm(".set FUN_0010ddec, _KhanPs__vslot16_getConstant0xb5");
asm(".globl FUN_0010ddfc");
asm(".set FUN_0010ddfc, _HwLimits__vslot8_failNotSupported");
asm(".globl FUN_0010de34");
asm(".set FUN_0010de34, _HwLimits__vslot9_failNotSupported");
asm(".globl Program__emitLoadVertexAttr");
asm(".set Program__emitLoadVertexAttr, _Program__emitLoadVertexAttr");
asm(".globl FUN_0010ed4c");
asm(".set FUN_0010ed4c, _KhanPs__vslot87_assignInterpolatorBindings");
asm(".globl PsBackend__assignInterpolatorRegisters");
asm(".set PsBackend__assignInterpolatorRegisters, _FUN_0010ef68");
