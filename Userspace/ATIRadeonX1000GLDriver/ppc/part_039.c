#include "decls.h"

/* KhanPs__vslot76_getBindingLimit @ 0x127ee4 (64 bytes) */
int KhanPs__vslot76_getBindingLimit(this, outLimit)
  int *this;
  undefined4 *outLimit;
{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*this + 0x138))(this,0);
  *outLimit = uVar1;
  return;
}

/* KhanPs__createSchedModels @ 0x127f24 (180 bytes) */
int KhanPs__createSchedModels(this, compiler)
  int this;
  undefined4 compiler;
{
  undefined4 *packModel;
  undefined *vtable;
  undefined4 *schedModel;
  undefined *baseModelVtable;
  
  schedModel = (undefined4 *)Compiler__allocateOrFail(compiler,0x6c);
  vtable = PTR_DAT_001e90f4;
  baseModelVtable = PTR_DAT_001e90fc + 8;
  schedModel[2] = compiler;
  *schedModel = baseModelVtable;
  schedModel[1] = 0;
  *schedModel = vtable + 8;
  PackState__reset(schedModel + 10);
  R520SchedModel__vslot2_reset(schedModel);
  schedModel[0x1a] = 0;
  *(undefined4 **)(this + 0x60) = schedModel;
  packModel = (undefined4 *)Compiler__allocateOrFail(compiler,0xc);
  vtable = PTR_DAT_001e9100;
  packModel[1] = 1;
  packModel[2] = 0;
  *packModel = vtable + 8;
  *(undefined4 **)(this + 100) = packModel;
  return;
}

/* FUN_00127fd8 @ 0x127fd8 (32 bytes) */
int FUN_00127fd8(param_1)
  undefined4 param_1;
{
  int extraout_r3;
  int unaff_r27;
  int *unaff_r30;
  
  *unaff_r30 = *(int *)(((unsigned char *)0x000011d0U) + unaff_r27) + 8;
  __Unwind_Resume(param_1);
  *(undefined4 *)(*(int *)(extraout_r3 + 8) + 0x2c) = 0x100;
  return;
}

/* KhanPs__vslot62_lookupTableEntry @ 0x127ff8 (36 bytes) */
int KhanPs__vslot62_lookupTableEntry(this, param_2)
  undefined4 this;
  int param_2;
{
  return *(undefined4 *)(PTR_PTR_001e910c + param_2 * 4);
}

/* KhanPs__vslot90_isProgramKind1 @ 0x12801c (20 bytes) */
int KhanPs__vslot90_isProgramKind1(this, param_2, param_3)
  undefined4 this;
  undefined4 param_2;
  int param_3;
{
  return *(int *)(param_3 + 0x138) == 1;
}

/* KhanPs__getOpcodeTraits @ 0x128030 (28 bytes) */
int KhanPs__getOpcodeTraits()
{
  return &DAT_001dca64;
}

/* KhanPs__vslot35_publishLimitsAndBindingTables @ 0x12804c (356 bytes) */
int KhanPs__vslot35_publishLimitsAndBindingTables(this, compiler, limitsBlob)
  int this;
  int compiler;
  undefined4 limitsBlob;
{
  int outputDstRecord;
  int lanesLeft2;
  int outputSrcRecord;
  int outputIndex;
  undefined1 *lanePairPtr;
  bool moreRecords;
  uint packedFlags;
  uint recordWord;
  int inputIndex;
  int inputSrcRecord;
  int inputBinding;
  int inputDstRecord;
  undefined1 *laneSrcCursor;
  undefined1 *laneDstCursor;
  int lanesLeft;
  
  _memcpy(compiler + 0x64c,limitsBlob,0x963c);
  inputIndex = 0;
  *(undefined4 *)(compiler + 0x104) = *(undefined4 *)(((unsigned char *)0x0000172c) + this);
  inputSrcRecord = this + 0x80;
  inputDstRecord = compiler + 0x100;
  inputBinding = this;
  do {
    laneSrcCursor = (undefined1 *)(inputSrcRecord + 0x14);
    laneDstCursor = (undefined1 *)(inputDstRecord + 0xc);
    *(char *)(inputDstRecord + 8) = (char)*(undefined4 *)(inputBinding + 0x68);
    lanesLeft = 4;
    *(char *)(inputDstRecord + 9) = (char)*(undefined4 *)(inputBinding + 0x6c);
    *(char *)(inputDstRecord + 10) = (char)*(undefined4 *)(inputBinding + 0x70);
    recordWord = *(uint *)(inputDstRecord + 8);
    packedFlags = (*(uint *)(inputBinding + 0x78) & 0xf) << 4;
    *(uint *)(inputDstRecord + 8) = packedFlags | recordWord & 0xffffff0f;
    *(uint *)(inputDstRecord + 8) = *(uint *)(inputBinding + 0x7c) & 1 | packedFlags | recordWord & 0xffffff0e;
    do {
      *laneDstCursor = *laneSrcCursor;
      lanePairPtr = laneSrcCursor + 4;
      laneSrcCursor = laneSrcCursor + 1;
      laneDstCursor[4] = *lanePairPtr;
      laneDstCursor = laneDstCursor + 1;
      lanesLeft = lanesLeft + -1;
    } while (lanesLeft != 0);
    moreRecords = inputIndex != 0x3f;
    inputDstRecord = inputDstRecord + 0xc;
    inputSrcRecord = inputSrcRecord + 0x34;
    inputBinding = inputBinding + 0x34;
    inputIndex = inputIndex + 1;
  } while (moreRecords);
  outputDstRecord = compiler + 0x400;
  outputIndex = 0;
  *(undefined4 *)(compiler + 0x408) = *(undefined4 *)(((unsigned char *)0x00001728) + this);
  outputSrcRecord = this + 0xd80;
  do {
    laneSrcCursor = (undefined1 *)(outputSrcRecord + 0x14);
    laneDstCursor = (undefined1 *)(outputDstRecord + 0x10);
    *(char *)(outputDstRecord + 0xc) = (char)*(undefined4 *)(this + 0xd68);
    lanesLeft2 = 4;
    *(char *)(outputDstRecord + 0xd) = (char)*(undefined4 *)(this + 0xd6c);
    *(char *)(outputDstRecord + 0xe) = (char)*(undefined4 *)(this + 0xd70);
    recordWord = *(uint *)(outputDstRecord + 0xc);
    packedFlags = (*(uint *)(this + 0xd78) & 0xf) << 4;
    *(uint *)(outputDstRecord + 0xc) = packedFlags | recordWord & 0xffffff0f;
    *(uint *)(outputDstRecord + 0xc) = *(uint *)(this + 0xd7c) & 1 | packedFlags | recordWord & 0xffffff0e;
    do {
      *laneDstCursor = *laneSrcCursor;
      lanePairPtr = laneSrcCursor + 4;
      laneSrcCursor = laneSrcCursor + 1;
      laneDstCursor[4] = *lanePairPtr;
      laneDstCursor = laneDstCursor + 1;
      lanesLeft2 = lanesLeft2 + -1;
    } while (lanesLeft2 != 0);
    moreRecords = outputIndex != 0x2f;
    outputDstRecord = outputDstRecord + 0xc;
    outputSrcRecord = outputSrcRecord + 0x34;
    this = this + 0x34;
    outputIndex = outputIndex + 1;
  } while (moreRecords);
  return 0;
}

/* KhanPs__vslot8_failNotSupported @ 0x1281b0 (56 bytes) */
int KhanPs__vslot8_failNotSupported(this, param_2, param_3, param_4, param_5, param_6, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int compiler;
{
  if (*(int *)(compiler + 0x6c4) != 0) {
    Compiler__fail(compiler,0xf);
  }
  return 0;
}

/* KhanPs__vslot58_matchImmediateConstantCode @ 0x1281f0 (344 bytes) */
int KhanPs__vslot58_matchImmediateConstantCode(this, constants, outSelectCode, laneSwizzle)
  undefined4 this;
  float *constants;
  undefined4 *outSelectCode;
  undefined4 laneSwizzle;
{
  int byteOffset;
  int lanesLeft2;
  unsigned int ghidra_home[8] = { this, constants, outSelectCode, laneSwizzle, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  float uniformValue;
  float sumOfLanes;
  bool firstLane;
  float *laneValueCursor;
  undefined4 *tableCursor;
  char *laneByteCursor;
  undefined4 tableCode;
  int lanesLeft;
  int lanesLeft3;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = laneSwizzle;
  firstLane = true;
  *outSelectCode = 0xffffffff;
  lanesLeft = 4;
  laneByteCursor = &(*(unsigned int *)((unsigned char *)ghidra_home + 12));
  laneValueCursor = constants;
  uniformValue = FLOAT_001aa0d4;
  do {
    if (*laneByteCursor != '\x04') {
      if (firstLane) {
        uniformValue = *laneValueCursor;
        firstLane = false;
      }
      else if (*laneValueCursor != uniformValue) {
        return 0;
      }
    }
    laneByteCursor = laneByteCursor + 1;
    laneValueCursor = laneValueCursor + 1;
    lanesLeft = lanesLeft + -1;
  } while (lanesLeft != 0);
  lanesLeft2 = 4;
  sumOfLanes = FLOAT_001aa0d4;
  do {
    sumOfLanes = sumOfLanes + uniformValue;
    lanesLeft2 = lanesLeft2 + -1;
  } while (lanesLeft2 != 0);
  (*(char *)((unsigned char *)ghidra_home + 12)) = (char)((uint)laneSwizzle >> 0x18);
  (*(char *)((unsigned char *)ghidra_home + 13)) = (char)((uint)laneSwizzle >> 0x10);
  (*(char *)((unsigned char *)ghidra_home + 14)) = (char)((uint)laneSwizzle >> 8);
  (*(char *)((unsigned char *)ghidra_home + 15)) = (char)laneSwizzle;
  tableCursor = &DAT_001aff0c;
  while( true ) {
    tableCode = *tableCursor;
    if ((((GH_U2F((unsigned int)(tableCursor[1])) == sumOfLanes) &&
         (((*(char *)((unsigned char *)ghidra_home + 12)) == '\x04' || (uniformValue == GH_U2F((unsigned int)(tableCursor[-4])))))) &&
        (((*(char *)((unsigned char *)ghidra_home + 13)) == '\x04' || (uniformValue == GH_U2F((unsigned int)(tableCursor[-3])))))) &&
       ((((*(char *)((unsigned char *)ghidra_home + 14)) == '\x04' || (uniformValue == GH_U2F((unsigned int)(tableCursor[-2])))) &&
        (((*(char *)((unsigned char *)ghidra_home + 15)) == '\x04' || (GH_U2F((unsigned int)(tableCursor[-1])) == uniformValue)))))) break;
    tableCursor = tableCursor + 6;
    if (tableCursor == (undefined4 *)&UNK_001aff54) {
      return 0;
    }
  }
  byteOffset = 0;
  lanesLeft3 = 4;
  do {
    *(float *)((int)constants + byteOffset) = uniformValue;
    byteOffset = byteOffset + 4;
    lanesLeft3 = lanesLeft3 + -1;
  } while (lanesLeft3 != 0);
  *outSelectCode = tableCode;
  return 1;
}

/* KhanPs__vslot73_seedValueNumbers @ 0x128348 (84 bytes) */
int KhanPs__vslot73_seedValueNumbers(this, param_2)
  undefined4 this;
  undefined4 param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_001aff74;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
    Compiler__valueNumberForExpr(param_2,uVar1);
  } while (puVar2 != &DAT_001aff9c);
  return;
}

/* KhanPs__vslot74_seedConstantValueNumbers @ 0x12839c (128 bytes) */
int KhanPs__vslot74_seedConstantValueNumbers(this, param_2)
  undefined4 this;
  undefined4 param_2;
{
  undefined4 seedExpr;
  int exprRecord;
  undefined4 *seedExprCursor;
  
  seedExprCursor = &DAT_001aff68;
  do {
    exprRecord = Compiler__valueNumberForExpr(param_2,*seedExprCursor);
    seedExpr = *seedExprCursor;
    *(undefined4 *)(exprRecord + 0x1c) = 0;
    seedExprCursor = seedExprCursor + 1;
    *(undefined4 *)(exprRecord + 0x14) = seedExpr;
    *(undefined1 *)(exprRecord + 8) = 1;
    *(undefined1 *)(exprRecord + 9) = 0;
    *(undefined4 *)(exprRecord + 0x18) = 0;
    FUN_0017629c(exprRecord,param_2);
  } while (seedExprCursor != &DAT_001aff74);
  return;
}

/* KhanPs__vslot85_findOrEncodeConstantVector @ 0x128430 (780 bytes) */
int KhanPs__vslot85_findOrEncodeConstantVector(this, program, constants, laneSwizzle)
  int *this;
  int program;
  dword *constants;
  int *laneSwizzle;
{
  int acceptsSwizzle;
  int byteOffset;
  int existingConstant;
  int candidate;
  int foundExact;
  int foundConstant;
  int *laneSwizzleArg;
  float uniformValue;
  bool firstLane;
  int *laneCursor;
  uint *fillCursor;
  char *pcVar5;
  int isUniform;
  dword *pdVar7;
  undefined4 constantPool;
  int lanesLeft;
  int lanesLeft2;
  uint constVec0;
  undefined4 constVec1;
  undefined4 constVec2;
  undefined4 constVec3;
  undefined4 constVec4;
  undefined4 constVec5;
  undefined4 constVec6;
  float uniformValueCopy;
  
  if (*laneSwizzle != 0x4040404) {
    pcVar5 = "In";
    uniformValue = 0.0;
    lanesLeft = 4;
    firstLane = true;
    isUniform = 1;
    laneCursor = laneSwizzle;
    pdVar7 = constants;
    do {
      if (*(char *)laneCursor != '\x04') {
        if (firstLane) {
          uniformValue = (float)*pdVar7;
          firstLane = false;
        }
        else if ((float)*pdVar7 != uniformValue) {
          isUniform = 0;
        }
      }
      laneCursor = (int *)((int)laneCursor + 1);
      pdVar7 = pdVar7 + 1;
      lanesLeft = lanesLeft + -1;
    } while (lanesLeft != 0);
    laneSwizzleArg = laneSwizzle;
    if (isUniform == 0) {
      existingConstant = Program__findOrCreateConstInst(program,constants,*laneSwizzle);
    }
    else {
      pcVar5 = "";
      lanesLeft = 4;
      fillCursor = &constVec0;
      do {
        *fillCursor = 0x7ffffffe;
        fillCursor = fillCursor + 1;
        lanesLeft = lanesLeft + -1;
      } while (lanesLeft != 0);
      pdVar7 = ((unsigned char *)0x4);
      byteOffset = 0;
      lanesLeft2 = 4;
      do {
        uniformValueCopy = uniformValue;
        *(float *)(byteOffset + (int)&constVec0) = uniformValue;
        byteOffset = byteOffset + 4;
        lanesLeft2 = lanesLeft2 + -1;
      } while (lanesLeft2 != 0);
      existingConstant = Program__findOrCreateConstInst(program,&constVec0,0x10203);
    }
    if (existingConstant != 0) {
      return existingConstant;
    }
    constantPool = *(undefined4 *)(program + 0x3ac);
    foundConstant = RegisterMap__findConstVectorExact(constantPool,constants,laneSwizzle,laneSwizzleArg,pcVar5,isUniform,pdVar7);
    if (foundConstant != 0) {
      return foundConstant;
    }
    if ((((((*(uint *)(program + 0x30) & 0x100) != 0) && (GH_U2F((unsigned int)(*constants)) == 0.0)) &&
         (GH_U2F((unsigned int)(constants[1])) == 1.0)) && ((GH_U2F((unsigned int)(constants[2])) == 0.0 && (GH_U2F((unsigned int)(constants[3])) == 0.0))))
       && (*laneSwizzle == 0x10203)) {
      FUN_000f4a24(constants,&constVec0);
      foundExact = FUN_000f5248(constantPool,constVec0,constVec1,constVec2,constVec3,constVec4,constVec5,constVec6);
      return foundExact;
    }
    candidate = RegisterMap__findConstVector(constantPool,constants,laneSwizzle,laneSwizzleArg);
    if ((candidate != 0) && (acceptsSwizzle = (**(code **)(*this + 0x100))(this,laneSwizzle), acceptsSwizzle != 0)) {
      return candidate;
    }
  }
  return 0;
}

/* KhanPs__vslot59_tryEncodeSourceConstant @ 0x12873c (500 bytes) */
int KhanPs__vslot59_tryEncodeSourceConstant(this, inst, srcIndex, laneSwizzle, compiler)
  undefined4 this;
  int *inst;
  int srcIndex;
  uint laneSwizzle;
  int compiler;
{
  int matchResult;
  float *tableCursor;
  uint laneMask;
  float *fillCursor;
  int lanesLeft;
  float constValues [4];
  float negatedValues [9];
  float negatedLastCopy;
  
  lanesLeft = 4;
  fillCursor = constValues;
  do {
    *fillCursor = GH_U2F(0x7fff0000U);
    fillCursor = fillCursor + 1;
    lanesLeft = lanesLeft + -1;
  } while (lanesLeft != 0);
  lanesLeft = 4;
  fillCursor = negatedValues;
  do {
    *fillCursor = GH_U2F(0x7fff0000U);
    fillCursor = fillCursor + 1;
    lanesLeft = lanesLeft + -1;
  } while (lanesLeft != 0);
  laneMask = laneSwizzle << 0x18 | (laneSwizzle & 0xff00) << 8 | laneSwizzle >> 8 & 0xff00 | laneSwizzle >> 0x18;
  tableCursor = (float *)&DAT_001aff08;
  while( true ) {
    constValues[1] = tableCursor[-2];
    constValues[0] = tableCursor[-3];
    constValues[2] = tableCursor[-1];
    negatedValues[0] = -constValues[0];
    constValues[3] = *tableCursor;
    negatedValues[1] = -constValues[1];
    negatedValues[2] = -constValues[2];
    negatedValues[3] = -constValues[3];
    negatedLastCopy = negatedValues[3];
    matchResult = IRInst__sourceMatchesConstant(inst,srcIndex,laneMask,constValues);
    if (matchResult != 0) {
      ((void (*)())IRInst__makeLiteralVec4Float)(inst,*(undefined4 *)(compiler + 0x6c4),srcIndex,(double)constValues[0],
                   (double)constValues[1],(double)constValues[2],(double)constValues[3]);
      return 1;
    }
    matchResult = (**(code **)(*inst + 0x8c))(inst);
    if ((matchResult != 0) && (matchResult = IRInst__sourceMatchesConstant(inst,srcIndex,laneMask,negatedValues), matchResult != 0)) break;
    tableCursor = tableCursor + 6;
    if (tableCursor == (float *)&DAT_001aff50) {
      return 0;
    }
  }
  ((void (*)())IRInst__makeLiteralVec4Float)(inst,*(undefined4 *)(compiler + 0x6c4),srcIndex,(double)constValues[0],
               (double)constValues[1],(double)constValues[2],(double)constValues[3]);
  if ((inst[srcIndex * 6 + 0x28] & 2U) != 0) {
    return 1;
  }
  IROperand__setModifierBits(inst + srcIndex * 6 + 0x23,1,inst[srcIndex * 6 + 0x28] & 1U ^ 1);
  return 1;
}

/* KhanPs__vslot9_createCompareInst @ 0x128930 (420 bytes) */
int KhanPs__vslot9_createCompareInst(this, compareKind, srcRegA, srcSwizzleA, srcRegB, srcSwizzleB, param_7, param_8, param_9, compiler)
  undefined4 this;
  int compareKind;
  int srcRegA;
  int srcSwizzleA;
  int srcRegB;
  int srcSwizzleB;
  undefined4 param_7;
  int param_8;
  undefined4 param_9;
  int compiler;
{
  unsigned int ghidra_home[8] = { this, compareKind, srcRegA, srcSwizzleA, srcRegB, srcSwizzleB, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  int callResult;
  undefined4 swizzleHandle;
  int operandRecord;
  int compareCondition;
  undefined4 program;
  int src1SelectWord;
  
  program = *(undefined4 *)(compiler + COMP_currentProgram);
  compareCondition = *(int *)(PTR_DAT_001e8b84 + compareKind * 4);
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
  callResult = IRInst__create(0x8b,compiler);
  swizzleHandle = Program__registerFileOfIlType(program,srcSwizzleA);
  operandRecord = IRInst__getOperandRecord(callResult,1);
  *(undefined4 *)(operandRecord + 0xc) = swizzleHandle;
  *(int *)(operandRecord + 8) = srcRegA;
  swizzleHandle = Program__registerFileOfIlType(program,srcSwizzleB);
  operandRecord = IRInst__getOperandRecord(callResult,2);
  *(undefined4 *)(operandRecord + 0xc) = swizzleHandle;
  *(int *)(operandRecord + 8) = srcRegB;
  Program__applySourceTokenToOperand(program,&(*(unsigned int *)((unsigned char *)ghidra_home + 24)),**(undefined4 **)(param_8 + 0x6c),1,callResult);
  Program__applySourceTokenToOperand(program,&(*(unsigned int *)((unsigned char *)ghidra_home + 24)),*(undefined4 *)(*(int *)(param_8 + 0x6c) + 4),2,callResult);
  if ((srcRegA == srcRegB) && (srcSwizzleA == srcSwizzleB)) {
    if ((*(uint *)(callResult + 0xb8) & 1) != (*(uint *)(callResult + 0xd0) & 1)) {
      if (((*(uint *)(callResult + 0xb8) & 2) == 0) && ((*(uint *)(callResult + 0xd0) & 2) == 0)) {
        operandRecord = IRInst__getOperandRecord(callResult,1);
        src1SelectWord = *(int *)(operandRecord + 0x10);
        operandRecord = IRInst__getOperandRecord(callResult,2);
        if (src1SelectWord == *(int *)(operandRecord + 0x10)) {
          if ((*(uint *)(callResult + 0xb8) & 1) != 0) {
            IROperand__setModifierBits(callResult + 0xa4,1,0);
            compareCondition = *(int *)(PTR_DAT_001e90f8 + compareCondition * 4);
          }
          IRInst__setIntConstantOperand4(callResult,program,2,0,0,0,0);
        }
      }
    }
  }
  *(int *)(callResult + 300) = compareCondition;
  return callResult;
}

/* KhanPs__vslot5_materializeSpecialRegister @ 0x128ad4 (680 bytes) */
int KhanPs__vslot5_materializeSpecialRegister(this, registerKind, compiler)
  undefined4 this;
  int registerKind;
  int compiler;
{
  int srcRecord;
  int canCombine;
  int userInst;
  undefined4 newRegister;
  undefined4 selectWord;
  int callResult;
  undefined4 constantPool;
  int *newInst;
  int nextRegNumber;
  int program;
  int listByteOffset;
  uint loopIndex;
  int operandIndex;
  double literalValue;
  
  if (registerKind == 1) {
    program = *(int *)(compiler + COMP_currentProgram);
    callResult = InternCache__find(*(undefined4 *)(program + 0x3ac),0x1b,0,0);
    if (callResult != 0) {
      IRLoadInterp__setLane(*(undefined4 *)(callResult + 0x38),3,3,8,0);
      constantPool = *(undefined4 *)(program + 0x3ac);
      nextRegNumber = *(int *)(compiler + 0x3ac) + -1;
      *(int *)(compiler + 0x3ac) = nextRegNumber;
      listByteOffset = 0;
      newRegister = InternCache__create(constantPool,0,nextRegNumber,0);
      for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(callResult + 0x14) + 4); loopIndex = loopIndex + 1) {
        userInst = *(int *)(listByteOffset + *(int *)(*(int *)(callResult + 0x14) + 8));
        if (((*(uint *)(userInst + 0x14) & 1) != 0) && (operandIndex = 1, 0 < *(int *)(userInst + 0x84))) {
          do {
            if (*(int *)(operandIndex * 0x18 + userInst + 0x98) == 0x1b) {
              IRInst__setOperandRef(userInst,operandIndex,newRegister);
            }
            operandIndex = operandIndex + 1;
          } while (operandIndex <= *(int *)(userInst + 0x84));
        }
        listByteOffset = listByteOffset + 4;
      }
      canCombine = FUN_000d9f3c(*(undefined4 *)(compiler + 0x398),0);
      if (canCombine == 0) {
        newInst = (int *)IRInst__create(0x14,compiler);
        IRInst__setOperandRef(newInst,0,newRegister);
        IRInst__setOperandRef(newInst,1,callResult);
        selectWord = DAT_001aff48;
        srcRecord = IRInst__getOperandRecord(newInst,1);
        literalValue = (double)FLOAT_001aa108;
        *(undefined4 *)(srcRecord + 0x10) = selectWord;
        ((void (*)())IRInst__makeLiteralVec4Float)(newInst,*(undefined4 *)(compiler + COMP_currentProgram),2,literalValue,literalValue,literalValue,literalValue);
        IROperand__setModifierBits(newInst + 0x2f,1,1);
        literalValue = (double)FLOAT_001aa0e8;
        ((void (*)())IRInst__makeLiteralVec4Float)(newInst,*(undefined4 *)(compiler + COMP_currentProgram),3,literalValue,literalValue,literalValue,literalValue);
        VReg__addUse(callResult,1,newInst);
        VReg__appendUser(newRegister,newInst);
        Block__appendInst(*(undefined4 *)(program + 0x3a0),newInst);
        (**(code **)(*newInst + 8))(newInst,compiler);
      }
      else {
        newInst = (int *)IRInst__create(0x31,compiler);
        IRInst__setOperandRef(newInst,0,newRegister);
        IRInst__setOperandRef(newInst,1,callResult);
        selectWord = DAT_001affa4;
        srcRecord = IRInst__getOperandRecord(newInst,1);
        *(undefined4 *)(srcRecord + 0x10) = selectWord;
        VReg__addUse(callResult,1,newInst);
        VReg__appendUser(newRegister,newInst);
        Block__appendInst(*(undefined4 *)(program + 0x3a0),newInst);
        (**(code **)(*newInst + 8))(newInst,compiler);
      }
    }
  }
  return;
}

/* KhanPs__vslot75_registerConstantMultiples @ 0x128d7c (596 bytes) */
int KhanPs__vslot75_registerConstantMultiples(this, constRecord, compiler, param_4, param_5, param_6, param_7)
  undefined4 this;
  float *constRecord;
  undefined4 compiler;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool moreMultiples;
  int exprRecord2;
  bool isLastMultiple;
  float recordValue;
  byte kindFlags;
  int multiple;
  int exprRecord;
  float *multipleCursor;
  
  if (*(char *)(constRecord + 2) == '\0') {
    return;
  }
  kindFlags = *(byte *)((int)constRecord + 9);
  if ((kindFlags & 1) != 0) {
    return;
  }
  if ((kindFlags & 2) != 0) {
    return;
  }
  if ((kindFlags & 4) != 0) {
    return;
  }
  if ((kindFlags & 8) != 0) {
    return;
  }
  exprRecord2 = Compiler__valueNumberForExpr(compiler,GH_F2U(-constRecord[5]));
  if (*(char *)(exprRecord2 + 8) == '\0') {
    kindFlags = *(byte *)(exprRecord2 + 9);
  }
  else {
    kindFlags = *(byte *)(exprRecord2 + 9);
    if (((((kindFlags & 1) == 0) && ((kindFlags & 2) == 0)) && ((kindFlags & 4) == 0)) && ((kindFlags & 8) == 0))
    goto LAB_00128e28;
  }
  if (((kindFlags & 1) == 0) || ((kindFlags & 2) != 0)) {
    *(undefined4 *)(exprRecord2 + 0x20) = 0x31;
    IROperand__copyRegisterAndSelect(exprRecord2,constRecord);
    recordValue = constRecord[5];
    *(undefined1 *)(exprRecord2 + 9) = 1;
    *(float *)(exprRecord2 + 0x14) = recordValue;
    *(undefined4 *)(exprRecord2 + 0x1c) = 0;
    *(undefined4 *)(exprRecord2 + 0x18) = 1;
  }
LAB_00128e28:
  multiple = -3;
  multipleCursor = (float *)&DAT_001aff4c;
  do {
    exprRecord = Compiler__valueNumberForExpr(compiler,GH_F2U(*constRecord * *multipleCursor));
    if (*(char *)(exprRecord + 8) == '\0') {
      kindFlags = *(byte *)(exprRecord + 9);
LAB_00128e98:
      if ((((kindFlags & 1) == 0) || ((kindFlags & 2) != 0)) && (((kindFlags & 2) == 0 || ((kindFlags & 1) != 0))))
      {
        *(undefined4 *)(exprRecord + 0x20) = 0x31;
        IROperand__copyRegisterAndSelect(exprRecord,constRecord);
        recordValue = constRecord[5];
        *(int *)(exprRecord + 0x1c) = multiple;
        *(undefined1 *)(exprRecord + 9) = 2;
        *(float *)(exprRecord + 0x14) = recordValue;
        *(undefined4 *)(exprRecord + 0x18) = 0;
      }
    }
    else {
      kindFlags = *(byte *)(exprRecord + 9);
      if ((((kindFlags & 1) != 0) || ((kindFlags & 2) != 0)) || (((kindFlags & 4) != 0 || ((kindFlags & 8) != 0))))
      goto LAB_00128e98;
    }
    isLastMultiple = multiple == 3;
    multipleCursor = multipleCursor + 1;
    multiple = multiple + 1;
    if (isLastMultiple) {
      multipleCursor = (float *)&DAT_001aff4c;
      multiple = -3;
      do {
        exprRecord = Compiler__valueNumberForExpr(compiler,GH_F2U(-*constRecord * *multipleCursor));
        if (*(char *)(exprRecord + 8) == '\0') {
          *(undefined4 *)(exprRecord + 0x20) = 0x31;
          IROperand__copyRegisterAndSelect(exprRecord,constRecord);
          recordValue = constRecord[5];
          *(undefined1 *)(exprRecord + 9) = 3;
          *(float *)(exprRecord + 0x14) = recordValue;
          *(undefined4 *)(exprRecord + 0x18) = 1;
          *(int *)(exprRecord + 0x1c) = multiple;
        }
        moreMultiples = multiple != 3;
        multipleCursor = multipleCursor + 1;
        multiple = multiple + 1;
      } while (moreMultiples);
      return;
    }
  } while( true );
}

/* KhanPs__ctor_128fd0 @ 0x128fd0 (312 bytes) */
int KhanPs__ctor_128fd0(this, param_2, param_3)
  undefined4 *this;
  undefined4 param_2;
  int param_3;
{
  undefined *vtable;
  
  HwLimits__dtor_10dad8(this);
  this[7] = 0;
  vtable = PTR_DAT_001e9104;
  this[0xe] = 9;
  this[0x10] = 0x60;
  this[1] = vtable;
  this[0x15] = 4;
  *this = &PTR_FUN_001ead88;
  this[8] = 0x7fffffff;
  this[0xf] = 0x10;
  this[0x14] = 0x20;
  this[0x16] = 0xfffffffd;
  this[0x17] = 3;
  this[0xb] = 0x20;
  this[10] = 0x10;
  BitSet__initDefault(this);
  BitSet__setBit(this,0x30);
  BitSet__setBit(this,0x31);
  BitSet__setBit(this,0x36);
  BitSet__setBit(this,0x39);
  BitSet__setBit(this,0x3b);
  BitSet__setBit(this,0x3c);
  BitSet__setBit(this,0x40);
  BitSet__setBit(this,0x41);
  BitSet__setBit(this,0x42);
  this[2] = this[2] | 0x20000;
  ((int (*)())KhanPs__vslot96_installHardwareTables)(this);
  if (param_3 != 0) {
    ((int (*)())KhanPs__createSchedModels)(this,param_2);
  }
  return;
}

/* KhanPs__ctor_129130 @ 0x129130 (312 bytes) */
int KhanPs__ctor_129130(this, param_2, param_3)
  undefined4 *this;
  undefined4 param_2;
  int param_3;
{
  undefined *vtable;
  
  HwLimits__dtor_10dad8(this);
  this[7] = 0;
  vtable = PTR_DAT_001e9104;
  this[0xe] = 9;
  this[0x10] = 0x60;
  this[1] = vtable;
  this[0x15] = 4;
  *this = &PTR_FUN_001ead88;
  this[8] = 0x7fffffff;
  this[0xf] = 0x10;
  this[0x14] = 0x20;
  this[0x16] = 0xfffffffd;
  this[0x17] = 3;
  this[0xb] = 0x20;
  this[10] = 0x10;
  BitSet__initDefault(this);
  BitSet__setBit(this,0x30);
  BitSet__setBit(this,0x31);
  BitSet__setBit(this,0x36);
  BitSet__setBit(this,0x39);
  BitSet__setBit(this,0x3b);
  BitSet__setBit(this,0x3c);
  BitSet__setBit(this,0x40);
  BitSet__setBit(this,0x41);
  BitSet__setBit(this,0x42);
  this[2] = this[2] | 0x20000;
  ((int (*)())KhanPs__vslot96_installHardwareTables)(this);
  if (param_3 != 0) {
    ((int (*)())KhanPs__createSchedModels)(this,param_2);
  }
  return;
}

/* FudoVs__createSchedModels @ 0x129290 (176 bytes) */
int FudoVs__createSchedModels(this, param_2)
  int this;
  undefined4 param_2;
{
  undefined4 *secondarySchedModel;
  undefined *vtable;
  undefined4 *vertexSchedModel;
  undefined *vertexSchedVtable;
  
  vertexSchedModel = (undefined4 *)Compiler__allocateOrFail(param_2,0x3c);
  vtable = PTR_DAT_001e9110;
  vertexSchedVtable = PTR_DAT_001e90fc + 8;
  vertexSchedModel[2] = param_2;
  *vertexSchedModel = vertexSchedVtable;
  vertexSchedModel[1] = 0;
  *vertexSchedModel = vtable + 8;
  R300VSchedModel__vslot2_reset(vertexSchedModel);
  SchedModel__resetCounters(vertexSchedModel);
  vertexSchedModel[0xe] = 0;
  *(undefined4 **)(this + 0x60) = vertexSchedModel;
  secondarySchedModel = (undefined4 *)Compiler__allocateOrFail(param_2,0xc);
  vtable = PTR_DAT_001e9100;
  secondarySchedModel[1] = 1;
  secondarySchedModel[2] = 0;
  *secondarySchedModel = vtable + 8;
  *(undefined4 **)(this + 100) = secondarySchedModel;
  return;
}

/* KhanVs__vslot76_getBindingLimits @ 0x129350 (96 bytes) */
int KhanVs__vslot76_getBindingLimits(this, outLimits)
  int *this;
  undefined4 *outLimits;
{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*this + 0x138))(this,0);
  *outLimits = uVar1;
  uVar1 = (**(code **)(*this + 0x140))(this,0);
  outLimits[1] = uVar1;
  return;
}

/* KhanVs__vslot77_getBindingLimits @ 0x1293b0 (72 bytes) */
int KhanVs__vslot77_getBindingLimits(this, outLimits)
  int *this;
  undefined4 *outLimits;
{
  undefined4 uVar1;
  
  *outLimits = 0;
  uVar1 = (**(code **)(*this + 0x138))(this,0);
  outLimits[1] = uVar1;
  return;
}

/* KhanVs__vslot80_getLimit_0x14 @ 0x1293f8 (8 bytes) */
int KhanVs__vslot80_getLimit_0x14()
{
  return 0x14;
}

/* KhanVs__vslot60_isZeroOrOne @ 0x129408 (60 bytes) */
undefined4 KhanVs__vslot60_isZeroOrOne(double fparam_1)
{
  if ((fparam_1 != (double)FLOAT_001aa0d4) && (fparam_1 != (double)FLOAT_001aa0e8)) {
    return 0;
  }
  return 1;
}

/* KhanVs__vslot73_noOp @ 0x129444 (4 bytes) */
int KhanVs__vslot73_noOp()
{
  return;
}

/* KhanVs__vslot99_matchesRegisterMapEntry @ 0x129448 (48 bytes) */
int KhanVs__vslot99_matchesRegisterMapEntry(this, param_2, param_3)
  undefined4 this;
  uint param_2;
  int param_3;
{
  return *(byte *)(param_2 * 0xc +
                   *(int *)(*(int *)(*(int *)(param_3 + 8) + 0x52c) * 4 + *(int *)(param_3 + 8) +
                           0x524) + 0x10a) == param_2;
}

/* KhanVs__vslot35_publishLimitsAndBindingTables @ 0x129478 (504 bytes) */
int KhanVs__vslot35_publishLimitsAndBindingTables(this, compiler, limitsBlob)
  int this;
  int compiler;
  int *limitsBlob;
{
  int lanesLeft;
  int lanesLeft2;
  int inputDstRecord;
  int outputSrcRecord;
  int inputSrcRecord;
  int outputIndex;
  int inputIndex;
  int publishedRecord;
  int outputDstRecord;
  int inputBinding;
  int inputBindingCursor;
  int inputCount;
  uint loopIndex;
  undefined1 *lanePairPtr;
  bool moreRecords;
  uint recordWord;
  int maxVnTransforms;
  int limit66c;
  int limit668;
  int limit65c;
  int maxMixInsts;
  uint packedFlags;
  undefined1 *laneSrcCursor;
  int limit660;
  undefined1 *laneDstCursor;
  
  _memcpy(*(undefined4 *)(compiler + 0x650),limitsBlob[1],*limitsBlob << 4);
  _memcpy(*(undefined4 *)(compiler + 0x654),limitsBlob[2],900);
  maxVnTransforms = limitsBlob[3];
  limit65c = limitsBlob[4];
  limit660 = limitsBlob[5];
  maxMixInsts = limitsBlob[6];
  limit668 = limitsBlob[7];
  limit66c = limitsBlob[8];
  *(int *)(compiler + 0x670) = limitsBlob[9];
  *(int *)(compiler + 0x658) = maxVnTransforms;
  *(int *)(compiler + 0x65c) = limit65c;
  *(int *)(compiler + 0x660) = limit660;
  *(int *)(compiler + 0x664) = maxMixInsts;
  *(int *)(compiler + 0x668) = limit668;
  *(int *)(compiler + 0x66c) = limit66c;
  inputCount = *(int *)(((unsigned char *)0x0000172c) + this);
  *(int *)(compiler + 0x104) = inputCount;
  if (inputCount != 0) {
    loopIndex = 0;
    inputBindingCursor = this;
    do {
      loopIndex = loopIndex + 1;
      publishedRecord = *(int *)(inputBindingCursor + 0x70) * 0xc + compiler;
      *(uint *)(inputBindingCursor + 0x68) = (uint)*(byte *)(publishedRecord + 0x108);
      *(uint *)(inputBindingCursor + 0x6c) = (uint)*(byte *)(publishedRecord + 0x109);
      inputBindingCursor = inputBindingCursor + 0x34;
    } while (loopIndex < *(uint *)(compiler + 0x104));
  }
  inputIndex = 0;
  inputSrcRecord = this + 0x80;
  inputDstRecord = compiler + 0x100;
  inputBinding = this;
  do {
    laneSrcCursor = (undefined1 *)(inputSrcRecord + 0x14);
    laneDstCursor = (undefined1 *)(inputDstRecord + 0xc);
    *(char *)(inputDstRecord + 8) = (char)*(undefined4 *)(inputBinding + 0x68);
    lanesLeft = 4;
    *(char *)(inputDstRecord + 9) = (char)*(undefined4 *)(inputBinding + 0x6c);
    *(char *)(inputDstRecord + 10) = (char)*(undefined4 *)(inputBinding + 0x70);
    recordWord = *(uint *)(inputDstRecord + 8);
    packedFlags = (*(uint *)(inputBinding + 0x78) & 0xf) << 4;
    *(uint *)(inputDstRecord + 8) = packedFlags | recordWord & 0xffffff0f;
    *(uint *)(inputDstRecord + 8) = *(uint *)(inputBinding + 0x7c) & 1 | packedFlags | recordWord & 0xffffff0e;
    do {
      *laneDstCursor = *laneSrcCursor;
      lanePairPtr = laneSrcCursor + 4;
      laneSrcCursor = laneSrcCursor + 1;
      laneDstCursor[4] = *lanePairPtr;
      laneDstCursor = laneDstCursor + 1;
      lanesLeft = lanesLeft + -1;
    } while (lanesLeft != 0);
    moreRecords = inputIndex != 0x3f;
    inputDstRecord = inputDstRecord + 0xc;
    inputSrcRecord = inputSrcRecord + 0x34;
    inputBinding = inputBinding + 0x34;
    inputIndex = inputIndex + 1;
  } while (moreRecords);
  outputDstRecord = compiler + 0x400;
  outputIndex = 0;
  *(undefined4 *)(compiler + 0x408) = *(undefined4 *)(((unsigned char *)0x00001728) + this);
  outputSrcRecord = this + 0xd80;
  do {
    laneSrcCursor = (undefined1 *)(outputSrcRecord + 0x14);
    laneDstCursor = (undefined1 *)(outputDstRecord + 0x10);
    *(char *)(outputDstRecord + 0xc) = (char)*(undefined4 *)(this + 0xd68);
    lanesLeft2 = 4;
    *(char *)(outputDstRecord + 0xd) = (char)*(undefined4 *)(this + 0xd6c);
    *(char *)(outputDstRecord + 0xe) = (char)*(undefined4 *)(this + 0xd70);
    recordWord = *(uint *)(outputDstRecord + 0xc);
    packedFlags = (*(uint *)(this + 0xd78) & 0xf) << 4;
    *(uint *)(outputDstRecord + 0xc) = packedFlags | recordWord & 0xffffff0f;
    *(uint *)(outputDstRecord + 0xc) = *(uint *)(this + 0xd7c) & 1 | packedFlags | recordWord & 0xffffff0e;
    do {
      *laneDstCursor = *laneSrcCursor;
      lanePairPtr = laneSrcCursor + 4;
      laneSrcCursor = laneSrcCursor + 1;
      laneDstCursor[4] = *lanePairPtr;
      laneDstCursor = laneDstCursor + 1;
      lanesLeft2 = lanesLeft2 + -1;
    } while (lanesLeft2 != 0);
    moreRecords = outputIndex != 0x2f;
    outputDstRecord = outputDstRecord + 0xc;
    outputSrcRecord = outputSrcRecord + 0x34;
    this = this + 0x34;
    outputIndex = outputIndex + 1;
  } while (moreRecords);
  return 0;
}

/* KhanVs__getOpcodeTraits @ 0x129678 (28 bytes) */
int KhanVs__getOpcodeTraits()
{
  return &DAT_001df1fc;
}

/* FudoVs__vslot8_failNotSupported @ 0x129694 (56 bytes) */
int FudoVs__vslot8_failNotSupported(this, param_2, param_3, param_4, param_5, param_6, compiler)
  undefined4 this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int compiler;
{
  if (*(int *)(compiler + 0x6c4) != 0) {
    Compiler__fail(compiler,0xf);
  }
  return 0;
}

/* KhanVs__vslot22_appendRegisterBindingWithLaneArrays @ 0x1296cc (124 bytes) */
int KhanVs__vslot22_appendRegisterBindingWithLaneArrays(this, laneValues, laneComponents, bindingKind, registerNumber, laneMask)
  int this;
  undefined4 *laneValues;
  undefined1 *laneComponents;
  undefined4 bindingKind;
  undefined4 registerNumber;
  uint laneMask;
{
  int recordLaneBase;
  int record;
  uint lane;
  int lanesLeft;
  
  record = *(int *)(((unsigned char *)0x00001728) + this);
  *(int *)(((unsigned char *)0x00001728) + this) = record + 1;
  lane = 0;
  record = this + record * 0x34 + 0xd60;
  recordLaneBase = record + 8;
  *(undefined4 *)(record + 8) = bindingKind;
  *(undefined4 *)(record + 0x24) = 1;
  *(undefined4 *)(record + 0x1c) = 1;
  lanesLeft = 4;
  *(undefined4 *)(record + 0x10) = registerNumber;
  *(undefined4 *)(record + 0xc) = registerNumber;
  *(uint *)(record + 0x18) = laneMask;
  do {
    if ((laneMask & 1 << (lane & 0x3f)) != 0) {
      *(char *)(recordLaneBase + 0x2c) = (char)*laneValues;
      *(undefined1 *)(recordLaneBase + 0x30) = *laneComponents;
    }
    lane = lane + 1;
    laneValues = laneValues + 1;
    recordLaneBase = recordLaneBase + 1;
    laneComponents = laneComponents + 1;
    lanesLeft = lanesLeft + -1;
  } while (lanesLeft != 0);
  return;
}

/* KhanVs__vslot21_appendRegisterBinding @ 0x129748 (156 bytes) */
int KhanVs__vslot21_appendRegisterBinding(this, regIndex, bindingKind, param_4, laneSelectWord, param_6, param_7, param_8, param_9, param_10)
  int this;
  undefined4 regIndex;
  int bindingKind;
  undefined4 param_4;
  undefined4 laneSelectWord;
  int param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  int record;
  
  record = *(int *)(((unsigned char *)0x00001728) + this);
  *(int *)(((unsigned char *)0x00001728) + this) = record + 1;
  record = this + record * 0x34 + 0xd60;
  *(int *)(record + 8) = bindingKind;
  *(undefined4 *)(record + 0x1c) = 1;
  *(undefined4 *)(record + 0xc) = param_4;
  *(undefined1 *)(record + 0x37) = (undefined1)regIndex;
  *(undefined1 *)(record + 0x34) = (undefined1)regIndex;
  *(undefined1 *)(record + 0x35) = (undefined1)regIndex;
  *(undefined1 *)(record + 0x36) = (undefined1)regIndex;
  if (bindingKind == 4) {
    *(undefined1 *)(record + 0x3b) = 3;
    *(undefined1 *)(record + 0x38) = 3;
    *(undefined1 *)(record + 0x39) = 3;
    *(undefined1 *)(record + 0x3a) = 3;
  }
  else {
    *(char *)(record + 0x38) = (char)((uint)laneSelectWord >> 0x18);
    *(char *)(record + 0x39) = (char)((uint)laneSelectWord >> 0x10);
    *(char *)(record + 0x3a) = (char)((uint)laneSelectWord >> 8);
    *(char *)(record + 0x3b) = (char)laneSelectWord;
  }
  *(undefined4 *)(record + 0x10) = param_10;
  *(uint *)(record + 0x24) = (uint)(param_6 == 0);
  *(undefined4 *)(record + 0x18) = param_9;
  return;
}

/* KhanVs__vslot100_appendIdentityRegisterBinding @ 0x1297e4 (112 bytes) */
int KhanVs__vslot100_appendIdentityRegisterBinding(this, bindingValue, regIndex)
  int this;
  undefined4 bindingValue;
  undefined4 regIndex;
{
  int record;
  
  record = *(int *)(((unsigned char *)0x0000172c) + this);
  *(int *)(((unsigned char *)0x0000172c) + this) = record + 1;
  record = this + record * 0x34 + 0x60;
  *(undefined4 *)(record + 8) = 5;
  *(undefined1 *)(record + 0x38) = 0;
  *(undefined1 *)(record + 0x3a) = 2;
  *(undefined4 *)(record + 0x10) = bindingValue;
  *(undefined1 *)(record + 0x37) = (undefined1)regIndex;
  *(undefined1 *)(record + 0x39) = 1;
  *(undefined1 *)(record + 0x3b) = 3;
  *(undefined4 *)(record + 0x18) = 0xf;
  *(undefined4 *)(record + 0x1c) = 1;
  *(undefined4 *)(record + 0xc) = bindingValue;
  *(undefined1 *)(record + 0x34) = (undefined1)regIndex;
  *(undefined1 *)(record + 0x35) = (undefined1)regIndex;
  *(undefined1 *)(record + 0x36) = (undefined1)regIndex;
  return;
}

/* KhanVs__vslot58_matchImmediateConstantCode @ 0x129854 (312 bytes) */
int KhanVs__vslot58_matchImmediateConstantCode(this, constants, outSelectCode, laneSwizzle)
  undefined4 this;
  float *constants;
  int *outSelectCode;
  undefined4 laneSwizzle;
{
  int codeAccum;
  int lanesLeft2;
  float *fillCursor;
  unsigned int ghidra_home[8] = { this, constants, outSelectCode, laneSwizzle, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  float laneValue;
  int *weightPtr;
  float *laneValueCursor;
  int weightOffset;
  char *laneByteBase;
  char *laneByteCursor;
  int lanesLeft;
  int lanesLeft3;
  int laneWeights [4];
  longlong laneValueInt;
  undefined4 minusOneBits;
  
  laneByteBase = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 12));
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = laneSwizzle;
  *outSelectCode = -1;
  lanesLeft = 4;
  laneValueCursor = constants;
  laneByteCursor = laneByteBase;
  while ((((*laneByteCursor == '\x04' || (laneValue = *laneValueCursor, laneValue == FLOAT_001aa0d4)) ||
          (laneValue == FLOAT_001aa0e8)) || (minusOneBits = 0xbf800000, laneValue == -1.0))) {
    laneByteCursor = laneByteCursor + 1;
    laneValueCursor = laneValueCursor + 1;
    lanesLeft = lanesLeft + -1;
    if (lanesLeft == 0) {
      lanesLeft2 = (int)laneByteCursor - (int)laneByteBase;
      fillCursor = constants;
      do {
        if (*laneByteBase == '\x04') {
          *fillCursor = 0.0;
        }
        laneWeights[3] = DAT_001affcc;
        laneWeights[2] = DAT_001affc8;
        laneByteBase = laneByteBase + 1;
        fillCursor = fillCursor + 1;
        lanesLeft2 = lanesLeft2 + -1;
      } while (lanesLeft2 != 0);
      codeAccum = 0;
      weightOffset = 0;
      laneWeights[1] = DAT_001affc4;
      laneWeights[0] = DAT_001affc0;
      lanesLeft3 = 4;
      *outSelectCode = 0;
      do {
        laneValue = *constants;
        constants = constants + 1;
        laneValueInt = (longlong)(int)laneValue;
        weightPtr = (int *)((int)laneWeights + weightOffset);
        weightOffset = weightOffset + 4;
        codeAccum = (int)laneValue * *weightPtr + codeAccum;
        *outSelectCode = codeAccum;
        lanesLeft3 = lanesLeft3 + -1;
      } while (lanesLeft3 != 0);
      return 1;
    }
  }
  return 0;
}

/* KhanVs__vslot74 @ 0x12998c (128 bytes) */
int KhanVs__vslot74(this, param_2)
  undefined4 this;
  undefined4 param_2;
{
  undefined4 seedExpr;
  int exprRecord;
  undefined4 *seedExprCursor;
  
  seedExprCursor = &DAT_001affb0;
  do {
    exprRecord = Compiler__valueNumberForExpr(param_2,*seedExprCursor);
    seedExpr = *seedExprCursor;
    *(undefined4 *)(exprRecord + 0x1c) = 0;
    seedExprCursor = seedExprCursor + 1;
    *(undefined4 *)(exprRecord + 0x14) = seedExpr;
    *(undefined1 *)(exprRecord + 8) = 1;
    *(undefined1 *)(exprRecord + 9) = 0;
    *(undefined4 *)(exprRecord + 0x18) = 0;
    FUN_0017629c(exprRecord,param_2);
  } while (seedExprCursor != &DAT_001affb8);
  return;
}

/* KhanVs__vslot59_tryEncodeSourceConstant @ 0x129a0c (316 bytes) */
int KhanVs__vslot59_tryEncodeSourceConstant(this, inst, srcIndex, laneSwizzle, compiler)
  undefined4 this;
  undefined4 inst;
  undefined4 srcIndex;
  uint laneSwizzle;
  int compiler;
{
  int lanesLeft;
  int srcRecord;
  char laneMaskByte;
  float laneValue;
  int *a0;
  int isConstant;
  undefined4 result;
  float *valueCursor;
  int lane;
  uint laneMaskWord;
  undefined4 srcSelectWord;
  uint constLane0;
  float constLane1;
  float constLane2;
  float constLane3;
  undefined4 minusOneBits;
  
  laneMaskWord = laneSwizzle << 0x18 | (laneSwizzle & 0xff00) << 8 | laneSwizzle >> 8 & 0xff00 | laneSwizzle >> 0x18;
  a0 = (int *)IRInst__getOperandSource(inst,srcIndex);
  isConstant = (**(code **)(*a0 + 0x48))(a0);
  if (isConstant == 0) {
LAB_00129b30:
    result = 0;
  }
  else {
    srcRecord = IRInst__getOperandRecord(inst,srcIndex);
    lane = 0;
    srcSelectWord = *(undefined4 *)(srcRecord + 0x10);
    lanesLeft = 4;
    valueCursor = (float *)&constLane0;
    do {
      laneMaskByte = *(char *)((int)&laneMaskWord + lane);
      *valueCursor = 0.0;
      if (laneMaskByte == '\0') {
        if ((((int)*(char *)(a0 + 0x57) >> (*(byte *)((int)&srcSelectWord + lane) & 0x3f) & 1U) == 0) ||
           (((laneValue = GH_U2F((unsigned int)(a0[(uint)*(byte *)((int)&srcSelectWord + lane) * 6 + 8])), laneValue != 0.0 &&
             (laneValue != 1.0)) && (minusOneBits = 0xbf800000, laneValue != -1.0)))) goto LAB_00129b30;
        *valueCursor = laneValue;
      }
      lane = lane + 1;
      valueCursor = valueCursor + 1;
      lanesLeft = lanesLeft + -1;
    } while (lanesLeft != 0);
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,*(undefined4 *)(compiler + 0x6c4),srcIndex,(double)GH_U2F((unsigned int)(constLane0)),
                 (double)constLane1,(double)constLane2,(double)constLane3);
    result = 1;
  }
  return result;
}

/* KhanVs__vslot71_canCombineSources @ 0x129b48 (632 bytes) */
int KhanVs__vslot71_canCombineSources(this, inst, replacedSourceIndex, inst2, param_5, param_6, compiler)
  undefined4 this;
  int *inst;
  int replacedSourceIndex;
  int *inst2;
  undefined4 param_5;
  undefined4 param_6;
  int compiler;
{
  int slotIndex;
  int defTemp;
  int isMixResult;
  int regNumber;
  bool slotsFull;
  int *operandVReg;
  int loopIndex2;
  bool moreInit;
  int tableEntry;
  int tableInitOffset;
  int *piVar4;
  undefined4 operandVReg2;
  int numSources;
  int loopIndex3;
  int *inst3;
  int regClass;
  int loopIndex;
  int seenRegs [10];
  
  tableInitOffset = 0;
  do {
    moreInit = tableInitOffset != 8;
    *(undefined4 *)(tableInitOffset + (int)seenRegs) = 0xffffffff;
    *(undefined4 *)(tableInitOffset + (int)(seenRegs + 3)) = 0xffffffff;
    tableInitOffset = tableInitOffset + 4;
  } while (moreInit);
  loopIndex3 = 0;
  loopIndex2 = 0;
  loopIndex = 1;
  inst3 = inst;
  do {
    numSources = (**(code **)(*inst + 0x14))(inst);
    if (numSources < loopIndex) {
      return 1;
    }
    if ((*(uint *)(*(int *)(compiler + 0x6c4) + 0x30) & 8) == 0) {
      if (loopIndex == replacedSourceIndex) {
        regClass = inst2[0x26];
        regNumber = *(int *)(inst2[0x23] + 8);
      }
      else {
        regNumber = inst3[0x2b];
        regClass = inst3[0x2c];
      }
LAB_00129cc4:
      switch(regClass) {
      case 2:
      case 0xc:
      case 0x26:
      case 0x28:
        slotIndex = 0;
        piVar4 = seenRegs;
        while( true ) {
          tableEntry = *piVar4;
          piVar4 = piVar4 + 1;
          if (tableEntry == -1) break;
          if ((regNumber == tableEntry) || (slotsFull = slotIndex == 2, slotIndex = slotIndex + 1, slotsFull))
          goto switchD_00129ce4_caseD_0;
        }
        loopIndex3 = loopIndex3 + 1;
        seenRegs[slotIndex] = regNumber;
        break;
      case 0x29:
      case 0x37:
        slotIndex = 0;
        piVar4 = seenRegs + 3;
        while( true ) {
          tableEntry = *piVar4;
          piVar4 = piVar4 + 1;
          if (tableEntry == -1) break;
          if ((regNumber == tableEntry) || (slotsFull = slotIndex == 2, slotIndex = slotIndex + 1, slotsFull))
          goto switchD_00129ce4_caseD_0;
        }
        loopIndex2 = loopIndex2 + 1;
        seenRegs[slotIndex + 3] = regNumber;
      }
    }
    else {
      if (loopIndex == replacedSourceIndex) {
        isMixResult = (**(code **)(*inst2 + 0x60))(inst2);
        if (isMixResult == 0) {
          regNumber = inst2[0x25];
          regClass = inst2[0x26];
        }
        else {
          defTemp = IRInst__getOperandSource(inst2,1);
          regClass = *(int *)(defTemp + 0x98);
          defTemp = IRInst__getOperandSource(inst2,1);
          regNumber = *(int *)(defTemp + 0x94);
        }
        goto LAB_00129cc4;
      }
      defTemp = IRInst__getOperandSource(inst,loopIndex);
      if (defTemp != 0) {
        operandVReg = (int *)IRInst__getOperandSource(inst,loopIndex);
        isMixResult = (**(code **)(*operandVReg + 0x60))(operandVReg);
        if (isMixResult == 0) {
          defTemp = IRInst__getOperandSource(inst,loopIndex);
          regClass = *(int *)(defTemp + 0x98);
          defTemp = IRInst__getOperandSource(inst,loopIndex);
          regNumber = *(int *)(defTemp + 0x94);
        }
        else {
          operandVReg2 = IRInst__getOperandSource(inst,loopIndex);
          defTemp = IRInst__getOperandSource(operandVReg2,1);
          regClass = *(int *)(defTemp + 0x98);
          operandVReg2 = IRInst__getOperandSource(inst,loopIndex);
          defTemp = IRInst__getOperandSource(operandVReg2,1);
          regNumber = *(int *)(defTemp + 0x94);
        }
        goto LAB_00129cc4;
      }
    }
switchD_00129ce4_caseD_0:
    if ((1 < loopIndex3) || (inst3 = inst3 + 6, 1 < loopIndex2)) {
      return 0;
    }
    loopIndex = loopIndex + 1;
  } while( true );
}

/* KhanVs__vslot85_findOrEncodeConstantVector @ 0x129eb4 (344 bytes) */
int KhanVs__vslot85_findOrEncodeConstantVector(this, program, constants, laneSwizzle)
  undefined4 this;
  int program;
  dword *constants;
  int *laneSwizzle;
{
  int byteOffset;
  int existingConstant;
  int candidate;
  int foundConstant;
  int *laneSwizzleArg;
  float uniformValue;
  bool firstLane;
  int *laneCursor;
  uint *fillCursor;
  char *pcVar5;
  int isUniform;
  dword *pdVar7;
  undefined4 constantPool;
  int lanesLeft;
  int lanesLeft2;
  uint uniformVec0;
  float uniformValueCopy;
  
  if (*laneSwizzle != 0x4040404) {
    pcVar5 = "te()\n";
    uniformValue = 0.0;
    lanesLeft = 4;
    firstLane = true;
    isUniform = 1;
    laneCursor = laneSwizzle;
    pdVar7 = constants;
    do {
      if (*(char *)laneCursor != '\x04') {
        if (firstLane) {
          uniformValue = (float)*pdVar7;
          firstLane = false;
        }
        else if ((float)*pdVar7 != uniformValue) {
          isUniform = 0;
        }
      }
      laneCursor = (int *)((int)laneCursor + 1);
      pdVar7 = pdVar7 + 1;
      lanesLeft = lanesLeft + -1;
    } while (lanesLeft != 0);
    laneSwizzleArg = laneSwizzle;
    if (isUniform == 0) {
      existingConstant = Program__findOrCreateConstInst(program,constants,*laneSwizzle);
    }
    else {
      pcVar5 = "";
      lanesLeft = 4;
      fillCursor = &uniformVec0;
      do {
        *fillCursor = 0x7ffffffe;
        fillCursor = fillCursor + 1;
        lanesLeft = lanesLeft + -1;
      } while (lanesLeft != 0);
      pdVar7 = ((unsigned char *)0x4);
      byteOffset = 0;
      lanesLeft2 = 4;
      do {
        uniformValueCopy = uniformValue;
        *(float *)(byteOffset + (int)&uniformVec0) = uniformValue;
        byteOffset = byteOffset + 4;
        lanesLeft2 = lanesLeft2 + -1;
      } while (lanesLeft2 != 0);
      existingConstant = Program__findOrCreateConstInst(program,&uniformVec0,0x10203);
    }
    if (existingConstant != 0) {
      return existingConstant;
    }
    constantPool = *(undefined4 *)(program + 0x3ac);
    foundConstant = RegisterMap__findConstVectorExact(constantPool,constants,laneSwizzle,laneSwizzleArg,pcVar5,isUniform,pdVar7);
    if (foundConstant != 0) {
      return foundConstant;
    }
    candidate = RegisterMap__findConstVector(constantPool,constants,laneSwizzle,laneSwizzleArg);
    if (candidate != 0) {
      return candidate;
    }
  }
  return 0;
}

/* KhanVs__vslot9_createCompareInst @ 0x12a00c (480 bytes) */
int KhanVs__vslot9_createCompareInst(this, compareKind, src1Register, param_4, src2Register, param_6, param_7, param_8, param_9, compiler)
  undefined4 this;
  undefined4 compareKind;
  undefined4 src1Register;
  undefined4 param_4;
  undefined4 src2Register;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
  undefined4 param_9;
  int compiler;
{
  undefined4 arena;
  int loadRecord;
  undefined4 operandIndexC;
  undefined4 operandIndexB;
  undefined4 operandIndexA;
  bool sourcesInOrder;
  undefined4 compareInst;
  unsigned int ghidra_home[8] = { this, compareKind, src1Register, param_4, src2Register, param_6, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool swapRequested;
  undefined4 opcode;
  undefined4 aux1;
  int operandRecord;
  undefined4 aux2;
  undefined4 *allocation;
  int compilerCopy;
  undefined4 uVar8;
  undefined4 *loadInst;
  int newRegNumber;
  
  compilerCopy = compiler;
  uVar8 = *(undefined4 *)(compiler + COMP_currentProgram);
  switch(compareKind) {
  case 0:
    opcode = 0x27;
    swapRequested = false;
    break;
  case 1:
    opcode = 0x2a;
    swapRequested = false;
    break;
  case 2:
    opcode = 0x28;
    swapRequested = true;
    break;
  case 3:
    opcode = 0x29;
    swapRequested = true;
    break;
  case 4:
    opcode = 0x28;
    swapRequested = false;
    break;
  case 5:
    opcode = 0x29;
    swapRequested = false;
    break;
  default:
    opcode = 0xb5;
    swapRequested = false;
  }
  sourcesInOrder = !swapRequested;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
  compareInst = IRInst__create(opcode,compiler);
  aux1 = Program__registerFileOfIlType(uVar8,param_4);
  operandRecord = IRInst__getOperandRecord(compareInst,2 - (uint)sourcesInOrder);
  *(undefined4 *)(operandRecord + 0xc) = aux1;
  *(undefined4 *)(operandRecord + 8) = src1Register;
  if (sourcesInOrder) {
    operandIndexA = 2;
  }
  else {
    operandIndexA = 1;
  }
  aux2 = Program__registerFileOfIlType(uVar8,param_6);
  operandRecord = IRInst__getOperandRecord(compareInst,operandIndexA);
  *(undefined4 *)(operandRecord + 0xc) = aux2;
  *(undefined4 *)(operandRecord + 8) = src2Register;
  if (sourcesInOrder) {
    operandIndexB = 1;
  }
  else {
    operandIndexB = 2;
  }
  Program__applySourceTokenToOperand(uVar8,&(*(unsigned int *)((unsigned char *)ghidra_home + 24)),**(undefined4 **)(param_8 + 0x6c),operandIndexB,compareInst);
  if (sourcesInOrder) {
    operandIndexC = 2;
  }
  else {
    operandIndexC = 1;
  }
  Program__applySourceTokenToOperand(uVar8,&(*(unsigned int *)((unsigned char *)ghidra_home + 24)),*(undefined4 *)(*(int *)(param_8 + 0x6c) + 4),operandIndexC,compareInst);
  newRegNumber = *(int *)(compilerCopy + 0x3ac) + -1;
  *(int *)(compilerCopy + 0x3ac) = newRegNumber;
  operandRecord = IRInst__getOperandRecord(compareInst,0);
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(int *)(operandRecord + 8) = newRegNumber;
  Program__appendInst(uVar8,compareInst,param_9);
  arena = *(undefined4 *)(compilerCopy + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  loadInst = allocation + 1;
  *allocation = arena;
  IRInst__ctor_10502c(loadInst,0x8c,compilerCopy);
  loadRecord = IRInst__getOperandRecord(loadInst,1);
  *(int *)(loadRecord + 8) = newRegNumber;
  *(undefined4 *)(loadRecord + 0xc) = 0;
  allocation[0x4c] = 0;
  return loadInst;
}

/* KhanVs__vslot89_assignLoadBindings @ 0x12a260 (352 bytes) */
int KhanVs__vslot89_assignLoadBindings(this, program)
  int *this;
  int program;
{
  int curInst;
  int bindingCheck;
  int optionEnabled;
  int nextNode2;
  int operandRecord;
  int inst;
  int nextInst;
  int bindingIndex;
  int nextNode;
  
  if (*(int *)(program + 0x3d4) == 0) {
    inst = *(int *)(*(int *)(program + 0x3a0) + 0x98);
    nextNode = *(int *)(inst + 8);
    if (nextNode != 0) {
      bindingIndex = 0;
      do {
        nextInst = nextNode;
        if (((*(uint *)(inst + 0x14) & 1) != 0) && (*(int *)(*(int *)(inst + 0x88) + 8) == 0xa4))
        {
          optionEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x3e);
          if ((optionEnabled == 0) ||
             (bindingCheck = (**(code **)(*this + 0x18c))(this,*(undefined4 *)(inst + 0x94),program)
             , bindingCheck != 0)) {
            (**(code **)(*this + 400))(this,*(undefined4 *)(inst + 0x94),bindingIndex);
            operandRecord = IRInst__getOperandRecord(inst,0);
            *(int *)(operandRecord + 8) = bindingIndex;
            nextInst = *(int *)(inst + 8);
            bindingIndex = bindingIndex + 1;
          }
          else {
            nextInst = *(int *)(inst + 8);
          }
        }
        nextNode = *(int *)(nextInst + 8);
        inst = nextInst;
      } while (*(int *)(nextInst + 8) != 0);
    }
  }
  else {
    curInst = *(int *)(*(int *)(program + 0x3a0) + 0x98);
    for (nextNode2 = *(int *)(curInst + 8); nextNode2 != 0; nextNode2 = *(int *)(nextNode2 + 8)) {
      if (((*(uint *)(curInst + 0x14) & 1) != 0) && (*(int *)(*(int *)(curInst + 0x88) + 8) == 0xa4)) {
        (**(code **)(*this + 400))
                  (this,*(undefined4 *)(curInst + 0x94),*(undefined4 *)(curInst + 0x94));
        nextNode2 = *(int *)(curInst + 8);
      }
      curInst = nextNode2;
    }
  }
  return;
}

/* KhanVs__vslot75_registerConstantMultiples @ 0x12a3c0 (248 bytes) */
int KhanVs__vslot75_registerConstantMultiples(this, constRecord, compiler, param_4, param_5, param_6, param_7)
  undefined4 this;
  int constRecord;
  undefined4 compiler;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 recordValueBits;
  byte kindFlags;
  int exprRecord;
  
  if ((((*(char *)(constRecord + 8) != '\0') && (kindFlags = *(byte *)(constRecord + 9), (kindFlags & 1) == 0)) &&
      ((kindFlags & 2) == 0)) && (((kindFlags & 4) == 0 && ((kindFlags & 8) == 0)))) {
    exprRecord = Compiler__valueNumberForExpr(compiler,GH_F2U(-*(float *)(constRecord + 0x14)));
    if (*(char *)(exprRecord + 8) == '\0') {
      kindFlags = *(byte *)(exprRecord + 9);
    }
    else {
      kindFlags = *(byte *)(exprRecord + 9);
      if ((((kindFlags & 1) == 0) && ((kindFlags & 2) == 0)) && (((kindFlags & 4) == 0 && ((kindFlags & 8) == 0))))
      {
        return;
      }
    }
    if (((kindFlags & 1) == 0) || ((kindFlags & 2) != 0)) {
      *(undefined4 *)(exprRecord + 0x20) = 0x31;
      IROperand__copyRegisterAndSelect(exprRecord,constRecord);
      recordValueBits = *(undefined4 *)(constRecord + 0x14);
      *(undefined1 *)(exprRecord + 9) = 1;
      *(undefined4 *)(exprRecord + 0x14) = recordValueBits;
      *(undefined4 *)(exprRecord + 0x1c) = 0;
      *(undefined4 *)(exprRecord + 0x18) = 1;
    }
  }
  return;
}

/* KhanVs__createSchedModels @ 0x12a4b8 (176 bytes) */
int KhanVs__createSchedModels(this, compiler)
  int this;
  undefined4 compiler;
{
  undefined4 *packModel;
  undefined *vtable;
  undefined4 *schedModel;
  undefined *baseModelVtable;
  
  schedModel = (undefined4 *)Compiler__allocateOrFail(compiler,0x3c);
  vtable = PTR_DAT_001e9110;
  baseModelVtable = PTR_DAT_001e90fc + 8;
  schedModel[2] = compiler;
  *schedModel = baseModelVtable;
  schedModel[1] = 0;
  *schedModel = vtable + 8;
  R300VSchedModel__vslot2_reset(schedModel);
  SchedModel__resetCounters(schedModel);
  schedModel[0xe] = 0;
  *(undefined4 **)(this + 0x60) = schedModel;
  packModel = (undefined4 *)Compiler__allocateOrFail(compiler,0xc);
  vtable = PTR_DAT_001e9100;
  packModel[1] = 1;
  packModel[2] = 0;
  *packModel = vtable + 8;
  *(undefined4 **)(this + 100) = packModel;
  return;
}

/* KhanVs__ctor_12a578 @ 0x12a578 (288 bytes) */
int KhanVs__ctor_12a578(this, param_2, param_3)
  undefined4 *this;
  undefined4 param_2;
  int param_3;
{
  undefined *vtable;
  
  HwLimits__dtor_10dad8(this);
  vtable = PTR_DAT_001e9114;
  this[4] = 5;
  this[1] = vtable;
  this[6] = 0x48;
  this[5] = 2;
  this[0x12] = 0x3ff;
  *this = &PTR_FUN_001eaf20;
  this[8] = 0x7fffffff;
  this[0xf] = 0x10;
  this[0x10] = 0x100;
  this[0x13] = 4;
  this[0x14] = 0x20;
  this[0x15] = 1;
  this[2] = this[2] | 0x2000;
  this[7] = 4;
  this[0xb] = 0x100;
  this[9] = 0x100;
  this[10] = 0x100;
  this[0xe] = 0x10;
  this[0x11] = 4;
  BitSet__initDefault(this);
  BitSet__setBit(this,0x3a);
  BitSet__setBit(this,0x3e);
  BitSet__setBit(this,0x3f);
  BitSet__setBit(this,0x4d);
  this[0x19] = 0;
  this[0x18] = 0;
  ((int (*)())KhanVs__vslot96_installHardwareTables)(this);
  if (param_3 != 0) {
    ((int (*)())KhanVs__createSchedModels)(this,param_2);
  }
  return;
}

/* KhanVs__ctor_12a6c0 @ 0x12a6c0 (288 bytes) */
int KhanVs__ctor_12a6c0(this, param_2, param_3)
  undefined4 *this;
  undefined4 param_2;
  int param_3;
{
  undefined *vtable;
  
  HwLimits__dtor_10dad8(this);
  vtable = PTR_DAT_001e9114;
  this[4] = 5;
  this[1] = vtable;
  this[6] = 0x48;
  this[5] = 2;
  this[0x12] = 0x3ff;
  *this = &PTR_FUN_001eaf20;
  this[8] = 0x7fffffff;
  this[0xf] = 0x10;
  this[0x10] = 0x100;
  this[0x13] = 4;
  this[0x14] = 0x20;
  this[0x15] = 1;
  this[2] = this[2] | 0x2000;
  this[7] = 4;
  this[0xb] = 0x100;
  this[9] = 0x100;
  this[10] = 0x100;
  this[0xe] = 0x10;
  this[0x11] = 4;
  BitSet__initDefault(this);
  BitSet__setBit(this,0x3a);
  BitSet__setBit(this,0x3e);
  BitSet__setBit(this,0x3f);
  BitSet__setBit(this,0x4d);
  this[0x19] = 0;
  this[0x18] = 0;
  ((int (*)())KhanVs__vslot96_installHardwareTables)(this);
  if (param_3 != 0) {
    ((int (*)())KhanVs__createSchedModels)(this,param_2);
  }
  return;
}

/* FudoVs__ctor_12a808 @ 0x12a808 (124 bytes) */
int FudoVs__ctor_12a808(this, allocContext, param_3)
  undefined4 *this;
  undefined4 allocContext;
  int param_3;
{
  ((int (*)())KhanVs__ctor_12a6c0)(this,allocContext,0);
  *this = &PTR_FUN_001eb0c0;
  this[6] = 0x80;
  this[0x10] = 0x400;
  this[2] = this[2] | 0x10100;
  ((int (*)())FudoVs__vslot96_installHardwareTables)(this);
  if (param_3 != 0) {
    ((int (*)())FudoVs__createSchedModels)(this,allocContext);
  }
  return;
}

/* FudoVs__ctor_12a8bc @ 0x12a8bc (124 bytes) */
int FudoVs__ctor_12a8bc(this, allocContext, param_3)
  undefined4 *this;
  undefined4 allocContext;
  int param_3;
{
  ((int (*)())KhanVs__ctor_12a6c0)(this,allocContext,0);
  *this = &PTR_FUN_001eb0c0;
  this[6] = 0x80;
  this[0x10] = 0x400;
  this[2] = this[2] | 0x10100;
  ((int (*)())FudoVs__vslot96_installHardwareTables)(this);
  if (param_3 != 0) {
    ((int (*)())FudoVs__createSchedModels)(this,allocContext);
  }
  return;
}

/* KhanVs__vslot96_installHardwareTables @ 0x12a970 (116 bytes) */
int KhanVs__vslot96_installHardwareTables(this)
  int this;
{
  PTR_DAT_001e27bc = PTR_DAT_001e9120;
  *(undefined **)(this + 0xc) = &DAT_001e1994;
  PTR_DAT_001e260c = PTR_DAT_001e911c;
  PTR_DAT_001e1c34 = PTR_DAT_001e9128;
  DAT_001e1c2c = 5;
  DAT_001e1c30 = 0;
  PTR_DAT_001e269c = PTR_DAT_001e9124;
  PTR_DAT_001e2630 = PTR_DAT_001e9118;
  DAT_001e2604 = 5;
  DAT_001e2608 = 0;
  return;
}

/* FudoVs__vslot96_installHardwareTables @ 0x12a9e4 (116 bytes) */
int FudoVs__vslot96_installHardwareTables(this)
  int this;
{
  *(undefined **)(this + 0xc) = &DAT_001e1994;
  DAT_001e25f4 = 0x4c;
  PTR_DAT_001e27bc = PTR_DAT_001e8c84;
  DAT_001e1c2c = 4;
  DAT_001e1c30 = PTR_FUN_001e8c7c;
  PTR_DAT_001e1c34 = (undefined *)0x0;
  DAT_001e1c1c = 0x4d;
  PTR_DAT_001e269c = PTR_DAT_001e8c78;
  DAT_001e2604 = 4;
  DAT_001e2608 = PTR_FUN_001e8c7c;
  PTR_DAT_001e260c = (undefined *)0x0;
  PTR_DAT_001e2630 = PTR_DAT_001e8c84;
  return;
}

/* KhanPs__vslot96_installHardwareTables @ 0x12aa58 (32 bytes) */
int KhanPs__vslot96_installHardwareTables(this)
  int this;
{
  *(undefined **)(this + 0xc) = &DAT_001e39a4;
  return;
}

/* FUN_0012aa78 @ 0x12aa78 (104 bytes) */
int FUN_0012aa78(compiler, param_2, param_3, param_4, param_5)
  int compiler;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  if (((*(int *)(param_5 + 0x140) == 0) ||
      (param_2 * param_4 + param_3 <= *(int *)(*(int *)(compiler + COMP_target) + 0x2c))) &&
     ((*(int *)(compiler + 0x318) == 0 ||
      ((param_2 <= *(int *)(compiler + 0x478) &&
       (param_2 * (*(int *)(compiler + COMP_nextInstId) - *(int *)(param_5 + 0x130)) <=
        *(int *)(compiler + 0x478) << 1)))))) {
    return 0;
  }
  return 1;
}

/* FUN_0012aae0 @ 0x12aae0 (36 bytes) */
int FUN_0012aae0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 < 1) {
    return;
  }
  *(undefined4 *)(param_1 + 0x47c) = 1;
  if (param_2 <= *(int *)(param_1 + 0x480)) {
    return;
  }
  *(int *)(param_1 + 0x480) = param_2;
  return;
}

/* FUN_0012ab04 @ 0x12ab04 (108 bytes) */
int FUN_0012ab04(inst)
  int *inst;
{
  int iVar1;
  int loopIndex;
  
  loopIndex = 0;
  while( true ) {
    iVar1 = (**(code **)(*inst + 0x14))(inst);
    if (iVar1 < loopIndex) {
      return 0;
    }
    iVar1 = IRInst__operandKindClass(inst,loopIndex);
    if (iVar1 == 1) break;
    loopIndex = loopIndex + 1;
  }
  return 1;
}

/* pass_optimize_control_flow @ 0x12ab80 (88 bytes) */
int pass_optimize_control_flow(program)
  int program;
{
  int *targetDescription;
  
  targetDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  (**(code **)(*targetDescription + 0x74))(targetDescription,program);
  return Program__beginPass(program,(int)"optimize_control_flow");
}

/* IfHeader__swapArms @ 0x12abd8 (128 bytes) */
int IfHeader__swapArms(program, ifHeader)
  undefined4 program;
  int ifHeader;
{
  int condition;
  undefined4 extraout_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 branchInst;
  
  branchInst = *(undefined4 *)(ifHeader + 0x134);
  *(undefined4 *)(ifHeader + 0x134) = *(undefined4 *)(ifHeader + 0x138);
  *(undefined4 *)(ifHeader + 0x138) = branchInst;
  DList__unlink(branchInst);
  DList__insertBefore(branchInst,*(undefined4 *)(ifHeader + 0x13c));
  branchInst = Block__getBranchInst(ifHeader,extraout_r4,in_r5,in_r6,in_r7,in_r8,in_r9);
  condition = IRInst__getCompareCondition(branchInst);
  IRInst__setCompareCondition(branchInst,*(undefined4 *)(PTR_DAT_001e912c + condition * 4));
  return ifHeader;
}

/* FUN_0012ac58 @ 0x12ac58 (452 bytes) */
int FUN_0012ac58(targetLoop, block)
  int targetLoop;
  int *block;
{
  int successorQuery20;
  int successorQuery28;
  int currentQuery38;
  int successorQuery2c;
  int successorQuery24;
  int footerQuery2c;
  int *predecessor;
  int *successor;
  int successorLoopInfo;
  int *piVar2;
  
  piVar2 = (int *)block[0x4b];
  while( true ) {
    while( true ) {
      while( true ) {
        successor = (int *)Block__getSuccessor(block,0);
        successorLoopInfo = (**(code **)(*successor + 0x10))(successor);
        if ((successorLoopInfo != 0) && (*(int *)(successorLoopInfo + 300) == targetLoop)) {
          footerQuery2c = (**(code **)(*piVar2 + 0x2c))(piVar2);
          predecessor = (int *)Block__getPredecessor(piVar2,(uint)(footerQuery2c != 0));
          return predecessor;
        }
        successorQuery24 = (**(code **)(*successor + 0x24))(successor);
        if (successorQuery24 == 0) break;
        block = (int *)successor[0x4f];
      }
      successorQuery2c = (**(code **)(*successor + 0x2c))(successor);
      if (successorQuery2c == 0) break;
      block = (int *)successor[0x55];
    }
    currentQuery38 = (**(code **)(*block + 0x38))(block);
    if ((currentQuery38 != 0) || (currentQuery38 = (**(code **)(*block + 0x3c))(block), currentQuery38 != 0)) break;
    successorQuery28 = (**(code **)(*successor + 0x28))(successor);
    if ((successorQuery28 == 0) && (successorQuery28 = (**(code **)(*successor + 0x30))(successor), successorQuery28 == 0)) {
      successorQuery20 = (**(code **)(*successor + 0x20))(successor);
      if (successorQuery20 == 0) {
        block = (int *)Block__getSuccessor(block,0);
      }
    }
    else {
      piVar2 = (int *)successor[0x4b];
      block = successor;
    }
  }
  return block;
}

/* FUN_0012ae1c @ 0x12ae1c (80 bytes) */
int FUN_0012ae1c(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x30))(param_1);
  if (iVar1 != 0) {
    param_1 = *(int **)(param_1[0x4b] + 0x154);
  }
  return param_1;
}

/* FUN_0012ae6c @ 0x12ae6c (132 bytes) */
int FUN_0012ae6c(block, param_2, param_3, param_4, param_5, param_6, param_7)
  int block;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int *inst;
  int *nextInstLink;
  int instQuery28;
  
  inst = *(int **)(block + 0x98);
  nextInstLink = (int *)(*(int **)(block + 0x98))[2];
  do {
    if (nextInstLink == (int *)0x0) {
      return 0;
    }
    if ((inst[5] & 1U) != 0) {
      instQuery28 = (**(code **)(*inst + 0x28))(inst);
      if (instQuery28 != 0) {
        return 1;
      }
      nextInstLink = (int *)inst[2];
    }
    inst = nextInstLink;
    nextInstLink = (int *)nextInstLink[2];
  } while( true );
}

/* FUN_0012aef0 @ 0x12aef0 (248 bytes) */
int FUN_0012aef0(param_1, firstBlock, block)
  undefined4 param_1;
  undefined4 firstBlock;
  int block;
{
  undefined4 successor;
  int isSimple;
  undefined4 mergeResult;
  int *nextInst;
  int *inst;
  
  isSimple = Block__isSimple(firstBlock);
  if ((((isSimple == 0) || (isSimple = Block__isSimple(block), isSimple == 0)) ||
      (isSimple = Block__successorCount(firstBlock), isSimple != 1)) ||
     ((isSimple = Block__predecessorCount(block), isSimple != 1 || (isSimple = Block__hasSuccessors(block), isSimple == 0)))) {
    mergeResult = 0;
  }
  else {
    nextInst = *(int **)(*(int *)(block + 200) + 8);
    while (inst = nextInst, isSimple = (**(code **)(*inst + 0x38))(inst), isSimple == 0) {
      nextInst = (int *)inst[2];
      if ((inst[5] & 1U) != 0) {
        DList__unlink(inst);
        Block__appendInst(firstBlock,inst);
      }
    }
    successor = Block__getSuccessor(block,0);
    Block__bypassAndDetach(block,firstBlock,successor);
    mergeResult = 1;
  }
  return mergeResult;
}

/* FUN_0012afe8 @ 0x12afe8 (344 bytes) */
int FUN_0012afe8(acceptFooterOnly, targetLoop, block, stopBlock)
  int acceptFooterOnly;
  int targetLoop;
  int *block;
  int *stopBlock;
{
  int enclosingLoopInfo;
  int blockQuery30;
  int blockQuery28;
  int blockQuery2c;
  int blockQuery24;
  
  if (block != (int *)0x0) {
    do {
      blockQuery24 = (**(code **)(*block + 0x24))(block);
      if (blockQuery24 == 0) {
        blockQuery2c = (**(code **)(*block + 0x2c))(block);
        if (blockQuery2c == 0) {
          blockQuery28 = (**(code **)(*block + 0x28))(block);
          if (blockQuery28 != 0) {
            if (acceptFooterOnly == 0) {
              return block;
            }
            if (stopBlock != block) {
              return block;
            }
            return stopBlock;
          }
          blockQuery30 = (**(code **)(*block + 0x30))(block);
          if (blockQuery30 != 0) {
            return block;
          }
          enclosingLoopInfo = (**(code **)(*block + 0x10))(block);
          if (((enclosingLoopInfo != 0) && (acceptFooterOnly == 0)) &&
             (enclosingLoopInfo = (**(code **)(*block + 0x10))(block), *(int *)(enclosingLoopInfo + 300) == targetLoop)) {
            return block;
          }
        }
        else {
          block = (int *)block[0x54];
        }
      }
      else {
        block = (int *)block[0x4f];
      }
      block = (int *)Block__getSuccessor(block,0);
    } while (block != (int *)0x0);
  }
  return (int *)0x0;
}

/* FUN_0012b140 @ 0x12b140 (264 bytes) */
int FUN_0012b140(block)
  int *block;
{
  int iVar1;
  
  iVar1 = *block;
  do {
    iVar1 = (**(code **)(iVar1 + 0x2c))(block);
    if (iVar1 == 0) {
      block = (int *)Block__getPredecessor(block,0);
    }
    else {
      block = (int *)Block__findSimplePredecessor(block);
    }
    while( true ) {
      while( true ) {
        if (block == (int *)0x0) {
          return (int *)0x0;
        }
        iVar1 = (**(code **)(*block + 0x24))(block);
        if (iVar1 != 0) {
          return block;
        }
        iVar1 = (**(code **)(*block + 0x28))(block);
        if (iVar1 == 0) break;
        block = (int *)Block__getPredecessor(block[0x4b],0);
      }
      iVar1 = (**(code **)(*block + 0x34))(block);
      if (iVar1 == 0) break;
      block = (int *)Block__findSimplePredecessor(block[0x4b]);
    }
    iVar1 = *block;
  } while( true );
}

/* FUN_0012b248 @ 0x12b248 (144 bytes) */
int FUN_0012b248(param_1, block, program)
  int param_1;
  undefined4 block;
  int program;
{
  undefined4 inst;
  int operandRecord;
  undefined4 sourceValue;
  int newVRegId;
  
  newVRegId = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(program + 8) + 0x3ac) = newVRegId;
  inst = IRInst__create(0x31,*(undefined4 *)(program + 8));
  operandRecord = IRInst__getOperandRecord(inst,0);
  sourceValue = *(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(int *)(operandRecord + 8) = newVRegId;
  IRInst__setOperandRef(inst,1,sourceValue);
  IRInst__bindOperandRegisters(program,inst);
  Block__appendInst(block,inst);
  return newVRegId;
}

/* FUN_0012b2d8 @ 0x12b2d8 (132 bytes) */
int FUN_0012b2d8(param_1, block, param_3, param_4)
  int param_1;
  undefined4 block;
  undefined4 param_3;
  int param_4;
{
  undefined4 callResult;
  int operandRecord;
  undefined4 uVar3;
  
  callResult = IRInst__create(0x31,*(undefined4 *)(param_4 + 8));
  operandRecord = IRInst__getOperandRecord(callResult,0);
  uVar3 = *(undefined4 *)(param_1 + 0xa4);
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = param_3;
  IRInst__setOperandRef(callResult,1,uVar3);
  IRInst__bindOperandRegisters(param_4,callResult);
  Block__appendInst(block,callResult);
  return callResult;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_00127ee4");
asm(".set FUN_00127ee4, _KhanPs__vslot76_getBindingLimit");
asm(".globl FUN_00127f24");
asm(".set FUN_00127f24, _KhanPs__createSchedModels");
asm(".globl FUN_00127fd8");
asm(".set FUN_00127fd8, _FUN_00127fd8");
asm(".globl FUN_00127ff8");
asm(".set FUN_00127ff8, _KhanPs__vslot62_lookupTableEntry");
asm(".globl FUN_0012801c");
asm(".set FUN_0012801c, _KhanPs__vslot90_isProgramKind1");
asm(".globl KhanPs__getOpcodeTraits");
asm(".set KhanPs__getOpcodeTraits, _KhanPs__getOpcodeTraits");
asm(".globl FUN_0012804c");
asm(".set FUN_0012804c, _KhanPs__vslot35_publishLimitsAndBindingTables");
asm(".globl FUN_001281b0");
asm(".set FUN_001281b0, _KhanPs__vslot8_failNotSupported");
asm(".globl FUN_001281f0");
asm(".set FUN_001281f0, _KhanPs__vslot58_matchImmediateConstantCode");
asm(".globl FUN_00128348");
asm(".set FUN_00128348, _KhanPs__vslot73_seedValueNumbers");
asm(".globl FUN_0012839c");
asm(".set FUN_0012839c, _KhanPs__vslot74_seedConstantValueNumbers");
asm(".globl FUN_00128430");
asm(".set FUN_00128430, _KhanPs__vslot85_findOrEncodeConstantVector");
asm(".globl FUN_0012873c");
asm(".set FUN_0012873c, _KhanPs__vslot59_tryEncodeSourceConstant");
asm(".globl FUN_00128930");
asm(".set FUN_00128930, _KhanPs__vslot9_createCompareInst");
asm(".globl FUN_00128ad4");
asm(".set FUN_00128ad4, _KhanPs__vslot5_materializeSpecialRegister");
asm(".globl FUN_00128d7c");
asm(".set FUN_00128d7c, _KhanPs__vslot75_registerConstantMultiples");
asm(".globl FUN_00129290");
asm(".set FUN_00129290, _FudoVs__createSchedModels");
asm(".globl FUN_00129350");
asm(".set FUN_00129350, _KhanVs__vslot76_getBindingLimits");
asm(".globl FUN_001293b0");
asm(".set FUN_001293b0, _KhanVs__vslot77_getBindingLimits");
asm(".globl FUN_001293f8");
asm(".set FUN_001293f8, _KhanVs__vslot80_getLimit_0x14");
asm(".globl FUN_00129408");
asm(".set FUN_00129408, _KhanVs__vslot60_isZeroOrOne");
asm(".globl FUN_00129444");
asm(".set FUN_00129444, _KhanVs__vslot73_noOp");
asm(".globl FUN_00129448");
asm(".set FUN_00129448, _KhanVs__vslot99_matchesRegisterMapEntry");
asm(".globl FUN_00129478");
asm(".set FUN_00129478, _KhanVs__vslot35_publishLimitsAndBindingTables");
asm(".globl KhanVs__getOpcodeTraits");
asm(".set KhanVs__getOpcodeTraits, _KhanVs__getOpcodeTraits");
asm(".globl FUN_00129694");
asm(".set FUN_00129694, _FudoVs__vslot8_failNotSupported");
asm(".globl FUN_001296cc");
asm(".set FUN_001296cc, _KhanVs__vslot22_appendRegisterBindingWithLaneArrays");
asm(".globl FUN_00129748");
asm(".set FUN_00129748, _KhanVs__vslot21_appendRegisterBinding");
asm(".globl FUN_001297e4");
asm(".set FUN_001297e4, _KhanVs__vslot100_appendIdentityRegisterBinding");
asm(".globl FUN_00129854");
asm(".set FUN_00129854, _KhanVs__vslot58_matchImmediateConstantCode");
asm(".globl KhanVs__vslot74");
asm(".set KhanVs__vslot74, _KhanVs__vslot74");
asm(".globl FUN_00129a0c");
asm(".set FUN_00129a0c, _KhanVs__vslot59_tryEncodeSourceConstant");
asm(".globl FUN_00129b48");
asm(".set FUN_00129b48, _KhanVs__vslot71_canCombineSources");
asm(".globl FUN_00129eb4");
asm(".set FUN_00129eb4, _KhanVs__vslot85_findOrEncodeConstantVector");
asm(".globl FUN_0012a00c");
asm(".set FUN_0012a00c, _KhanVs__vslot9_createCompareInst");
asm(".globl FUN_0012a260");
asm(".set FUN_0012a260, _KhanVs__vslot89_assignLoadBindings");
asm(".globl FUN_0012a3c0");
asm(".set FUN_0012a3c0, _KhanVs__vslot75_registerConstantMultiples");
asm(".globl FUN_0012a4b8");
asm(".set FUN_0012a4b8, _KhanVs__createSchedModels");
asm(".globl FUN_0012a970");
asm(".set FUN_0012a970, _KhanVs__vslot96_installHardwareTables");
asm(".globl FUN_0012a9e4");
asm(".set FUN_0012a9e4, _FudoVs__vslot96_installHardwareTables");
asm(".globl FUN_0012aa58");
asm(".set FUN_0012aa58, _KhanPs__vslot96_installHardwareTables");
