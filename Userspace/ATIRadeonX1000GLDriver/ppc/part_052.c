#include "decls.h"

/* R300MachineAssembler__emitTexRecord @ 0x197b30 (692 bytes) */
int R300MachineAssembler__emitTexRecord(this, inst, unused, compiler)
  int *this;
  int inst;
  undefined4 unused;
  int compiler;
{
  int *operandVReg;
  undefined2 sourceRegister;
  int iVar2;
  int iVar3;
  byte texFlags;
  int irOpcode;
  int iVar7;
  
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  sourceRegister = thunk_FUN_00134de8(*(undefined4 *)(compiler + COMP_currentProgram),operandVReg);
  iVar2 = (**(code **)(**(int **)(compiler + COMP_target) + 0x7c))(*(int **)(compiler + COMP_target),inst);
  if (iVar2 == 0) {
    IRInst__getOperandRecord(inst,0);
  }
  *(undefined4 *)(this[0x18] * 0x48 + this[0x16]) = 2;
  *(undefined2 *)(this[0x18] * 0x48 + this[0x16] + 0xe) = sourceRegister;
  iVar2 = *(int *)(inst + 0x134);
  irOpcode = *(int *)(*(int *)(inst + 0x88) + 8);
  if (irOpcode != 0x77) {
    *(char *)(this[0x18] * 0x48 + this[0x16] + 0x19) = (char)iVar2;
    iVar7 = this[0x18];
    iVar3 = this[0x16];
    sourceRegister = thunk_FUN_00134de8(*(undefined4 *)(compiler + COMP_currentProgram),inst);
    *(undefined2 *)(iVar7 * 0x48 + iVar3 + 0xc) = sourceRegister;
  }
  else {
    *(undefined2 *)(this[0x18] * 0x48 + this[0x16] + 0xc) = 0;
    *(undefined4 *)(this[0x17] + 0x9370) = 1;
    *(undefined1 *)(this[0x18] * 0x48 + this[0x16] + 0x19) = 0;
  }
  iVar3 = (**(code **)(*operandVReg + 0x80))(operandVReg);
  if (iVar3 == 0) {
    *(undefined4 *)(iVar2 * 4 + this[0x17] + 0x9378) = 1;
  }
  if (*(int *)(PTR_DAT_001e913c + irOpcode * 0x38 + 0xc) != -1) {
    *(char *)(this[0x18] * 0x48 + this[0x16] + 0x1a) =
         (char)*(int *)(PTR_DAT_001e913c + irOpcode * 0x38 + 0xc);
  }
  texFlags = 0xc;
  iVar2 = *(int *)(iVar2 * 0xc + *(int *)(*(int *)(compiler + COMP_currentProgram) + 0x78) + 4);
  if (((iVar2 != 2) && (texFlags = 8, iVar2 != 3)) && (texFlags = 0, iVar2 == 1)) {
    texFlags = 0xe;
  }
  if (irOpcode != 0x77) {
    if (irOpcode - 0x75U < 2) {
      *(byte *)(this[0x18] * 0x48 + this[0x16] + 0x1f) = texFlags & 7;
    }
    else {
      *(byte *)(this[0x18] * 0x48 + this[0x16] + 0x1f) = texFlags;
    }
  }
  else {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x16] + 0x1f) = 0;
  }
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  iVar2 = (**(code **)(*operandVReg + 0x80))(operandVReg);
  if (iVar2 != 0) {
                    
                    
    (**(code **)(*this + 0x154))(this,1,inst,compiler);
    return;
  }
  return;
}

/* R300MachineAssembler__rgbSelectForLiteralFloat @ 0x197de4 (232 bytes) */
int R300MachineAssembler__rgbSelectForLiteralFloat(this, sourceIndex, selectOut, unused, inst)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  undefined4 unused;
  undefined4 inst;
{
  float literalValue;
  uint laneSelector;
  int operandVReg;
  int loopRemaining;
  int loopIndex;
  undefined4 swizzleWord [9];
  
  operandVReg = IRInst__getOperandSource(inst,sourceIndex);
  loopRemaining = IRInst__getOperandRecord(inst,sourceIndex);
  loopIndex = 0;
  swizzleWord[0] = *(undefined4 *)(loopRemaining + 0x10);
  loopRemaining = 4;
  do {
    laneSelector = (uint)*(byte *)((int)swizzleWord + loopIndex);
    if (laneSelector < 4) goto LAB_00197e50;
    loopIndex = loopIndex + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  laneSelector = 0;
LAB_00197e50:
  literalValue = *(float *)(laneSelector * 0x18 + operandVReg + 0x20);
  if (literalValue == FLOAT_001aa0d4) {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x14;
  }
  else if (literalValue == FLOAT_001aa10c) {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x16;
  }
  else if (literalValue == FLOAT_001aa0e8) {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x15;
  }
  return;
}

/* R300MachineAssembler__alphaSelectForLiteralFloat @ 0x197ecc (232 bytes) */
int R300MachineAssembler__alphaSelectForLiteralFloat(this, sourceIndex, selectOut, unused, inst)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  undefined4 unused;
  undefined4 inst;
{
  float literalValue;
  uint laneSelector;
  int operandVReg;
  int loopRemaining;
  int loopIndex;
  undefined4 swizzleWord [9];
  
  operandVReg = IRInst__getOperandSource(inst,sourceIndex);
  loopRemaining = IRInst__getOperandRecord(inst,sourceIndex);
  loopIndex = 0;
  swizzleWord[0] = *(undefined4 *)(loopRemaining + 0x10);
  loopRemaining = 4;
  do {
    laneSelector = (uint)*(byte *)((int)swizzleWord + loopIndex);
    if (laneSelector < 4) goto LAB_00197f38;
    loopIndex = loopIndex + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  laneSelector = 0;
LAB_00197f38:
  literalValue = *(float *)(laneSelector * 0x18 + operandVReg + 0x20);
  if (literalValue == FLOAT_001aa0d4) {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x10;
  }
  else if (literalValue == FLOAT_001aa10c) {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x12;
  }
  else if (literalValue == FLOAT_001aa0e8) {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x11;
  }
  return;
}

/* R300MachineAssembler__setTempDestination @ 0x197fb4 (208 bytes) */
int R300MachineAssembler__setTempDestination(this, writeRgb, writeAlpha, inst, destRegister)
  int this;
  int writeRgb;
  int writeAlpha;
  undefined4 inst;
  undefined4 destRegister;
{
  int recordBase;
  int operandRecord;
  undefined1 writeMask;
  int recordIndex;
  
  if (writeRgb != 0) {
    *(undefined2 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0xc) =
         (*(unsigned short *)((unsigned char *)&(destRegister) + 2));
    recordIndex = *(int *)(this + 0x60);
    recordBase = *(int *)(this + 0x58);
    operandRecord = IRInst__getOperandRecord(inst,0);
    writeMask = lanesToRgbMask(*(undefined4 *)(operandRecord + 0x10));
    *(undefined1 *)(recordIndex * 0x48 + recordBase + 0x14) = writeMask;
  }
  if (writeAlpha != 0) {
    *(undefined2 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x18) =
         (*(unsigned short *)((unsigned char *)&(destRegister) + 2));
    recordIndex = *(int *)(this + 0x60);
    recordBase = *(int *)(this + 0x58);
    operandRecord = IRInst__getOperandRecord(inst,0);
    *(bool *)(recordIndex * 0x48 + recordBase + 0x20) = *(char *)(operandRecord + 0x13) == '\0';
  }
  return;
}

/* R300MachineAssembler__setOutputDestination @ 0x198084 (296 bytes) */
int R300MachineAssembler__setOutputDestination(this, writeRgb, writeAlpha, inst)
  int this;
  int writeRgb;
  int writeAlpha;
  int inst;
{
  int operandRecord;
  int destRegister;
  int iVar1;
  undefined1 writeMask;
  int iVar3;
  int iVar4;
  undefined1 outputIndex;
  int destinationClass;
  
  destinationClass = *(int *)(inst + 0x98);
  destRegister = *(int *)(inst + 0x94);
  if (destinationClass == 9) {
    iVar1 = destRegister + 1;
    iVar3 = *(int *)(*(int *)(this + 0x5c) + 0x9374);
    if (iVar1 <= iVar3) {
      iVar1 = iVar3;
    }
    *(int *)(*(int *)(this + 0x5c) + 0x9374) = iVar1;
  }
  outputIndex = (undefined1)destRegister;
  if ((writeRgb != 0) && (destinationClass != 8)) {
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x16) = outputIndex;
    iVar3 = *(int *)(this + 0x60);
    iVar4 = *(int *)(this + 0x58);
    operandRecord = IRInst__getOperandRecord(inst,0);
    writeMask = lanesToRgbMask(*(undefined4 *)(operandRecord + 0x10));
    *(undefined1 *)(iVar3 * 0x48 + iVar4 + 0x15) = writeMask;
  }
  if (writeAlpha != 0) {
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x22) = outputIndex;
    if (destinationClass == 8) {
      *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x23) = 1;
    }
    else {
      iVar1 = *(int *)(this + 0x60);
      iVar4 = *(int *)(this + 0x58);
      destinationClass = IRInst__getOperandRecord(inst,0);
      *(bool *)(iVar1 * 0x48 + iVar4 + 0x21) = *(char *)(destinationClass + 0x13) == '\0';
    }
  }
  return;
}

/* R300MachineAssembler__assembleAluInstruction @ 0x1981ac (8500 bytes) */
int R300MachineAssembler__assembleAluInstruction(this, irInst)
  int *this;
  int *irInst;
{
  int *stagedArg4;
  uint swizzleLowByte;
  int *slotWordPtr;
  int *stagedArg3;
  int *slotIter;
  int *stagedArg2;
  int innerSource2;
  int innerSource;
  int sourceWidth;
  int vslot5cResult;
  int vslotDcResult;
  int vslot48Result;
  int vslot50Result;
  int vslot80Result;
  int alphaLanes;
  int selectsWFlag;
  int sourceKind;
  int isForwardableMov;
  int operandRecordTmp;
  undefined4 allocatedRegister;
  int *selectSrcIdx2;
  int *slotInst;
  int hwRegister;
  int srcOpcode;
  int sourceCount;
  bool isOpcode9aAlpha;
  bool maskByteNonZero;
  bool isOpcode9a;
  bool swizzleHighClear;
  uint classifyAlphaCopy;
  undefined4 registerIndex3;
  undefined4 registerIndex2;
  undefined4 registerIndex;
  undefined4 laneEnable;
  int *alphaHardwareOpcodeOut;
  int *swizzle2;
  int *swizzle;
  int anyEnabledLaneSelectsXyzResult;
  undefined4 sourceDef2;
  int *sourceDef;
  bool writesRgb;
  bool writesAlpha;
  bool isThirdSource;
  bool moreSlots;
  byte crFlagsByte;
  uint classifyRgbCopy;
  code *selectMethod;
  int clearOffset;
  uint usedMaskOld;
  uint classifyFlags;
  int *sourceInst;
  int hwRegister2;
  int hwRegister3;
  int selectsW;
  undefined4 operandSelectWord;
  undefined4 staleArg1;
  int *selectSrcIdx;
  int *loopPtr;
  int *loopPtr2;
  uint rgbUsedMaskOld;
  int *irInstWords;
  int picTableWord;
  int *a4;
  uint slotIndex;
  int *srcIdx;
  int *sourceDef3;
  undefined4 allocTable;
  int *piVar25;
  byte in_xer_so = 0;
  int clearCount;
  undefined8 operandVReg;
  int rgbHwOpcode;
  int alphaHwOpcode;
  int sourceRegister;
  int alphaSelect [4];
  int rgbMod [4];
  int alphaMod [4];
  int rgbSelect [4];
  int alphaLaneEnables;
  int classifyOut2b;
  undefined4 rgbLaneEnables;
  undefined4 srcpEnablesAlpha;
  int *composedSelect;
  uint swizzleMask;
  int *movInst;
  int sourceReplaced;
  uint classifyFlagBit4;
  uint classifyFlagBit2;
  uint classifyWritesAlpha;
  uint classifyWritesRgb;
  int irOpcode;
  int crFlagsWord;
  undefined *picBase;
  int *alphaModAlias;
  
  stagedArg2 = &alphaLaneEnables;
  stagedArg4 = &rgbHwOpcode;
  alphaHardwareOpcodeOut = &alphaHwOpcode;
  stagedArg3 = irInst;
  classifyFlags = R300MachineAssembler__classifyAluOperation(this,&rgbLaneEnables,stagedArg2,irInst,stagedArg4,alphaHardwareOpcodeOut);
  classifyWritesRgb = classifyFlags & 1;
  classifyWritesAlpha = classifyFlags >> 1 & 1;
  irOpcode = *(int *)(irInst[0x22] + 8);
  alphaModAlias = alphaMod;
  clearCount = 4;
  classifyFlagBit4 = classifyFlags >> 4 & 1;
  classifyFlagBit2 = classifyFlags >> 2 & 1;
  clearOffset = 0;
  do {
    *(undefined4 *)(clearOffset + (int)rgbSelect) = 0;
    *(undefined4 *)(clearOffset + (int)rgbMod) = 0;
    *(undefined4 *)(clearOffset + (int)alphaSelect) = 0;
    *(undefined4 *)(clearOffset + (int)alphaModAlias) = 0;
    clearOffset = clearOffset + 4;
    clearCount = clearCount + -1;
  } while (clearCount != 0);
  sourceCount = (**(code **)(*irInst + 0x14))(irInst);
  classifyRgbCopy = classifyWritesRgb;
  classifyAlphaCopy = classifyWritesAlpha;
  if (irOpcode == 0xb4) {
    sourceCount = 3;
LAB_00198290:
    srcIdx = (int *)((int)((unsigned char *)0x0) + 1);
    irInstWords = irInst + 0x26;
    writesRgb = classifyWritesRgb != 0;
    writesAlpha = classifyWritesAlpha != 0;
    crFlagsWord = (uint)(byte)(((int)classifyFlagBit4 < 0) << 3 | (0 < (int)classifyFlagBit4) << 2 |
                            (classifyFlagBit4 == 0) << 1 | in_xer_so & 1) << 0x1c;
    picBase = &DAT_001b81b8;
    do {
      operandRecordTmp = IRInst__getOperandRecord(irInst,srcIdx);
      swizzle = *(int **)(operandRecordTmp + 0x10);
      sourceRegister = -1;
      operandVReg = IRInst__getOperandSource(irInst,srcIdx);
      sourceInst = (int *)((ulonglong)operandVReg >> 0x20);
      picTableWord = *(int *)(picBase + -0x56f8);
      isForwardableMov = (**(code **)(*sourceInst + 0x60))(sourceInst,(int)operandVReg,stagedArg2,stagedArg3,stagedArg4,alphaHardwareOpcodeOut,picBase);
      if (isForwardableMov == 0) {
        sourceReplaced = 0;
        movInst = (int *)0x0;
      }
      else {
        movInst = sourceInst;
        operandRecordTmp = IRInst__getOperandRecord(sourceInst,1);
        operandSelectWord = *(undefined4 *)(operandRecordTmp + 0x10);
        operandRecordTmp = IRInst__getOperandRecord(irInst,srcIdx);
        picTableWord = *(int *)(operandRecordTmp + 0x10);
        SelectWord__compose(&composedSelect,operandSelectWord,picTableWord);
        swizzle = composedSelect;
        sourceInst = (int *)IRInst__getOperandSource(movInst,1);
        stagedArg4 = (int *)this[3];
        stagedArg3 = (int *)0x0;
        stagedArg2 = sourceInst;
        IRInst__setOperandSource(irInst,srcIdx,sourceInst,0,stagedArg4);
        if (srcIdx == (int *)0x0) {
          sourceReplaced = 1;
          irInst[0x27] = (int)swizzle;
        }
        else {
          operandRecordTmp = IRInst__getOperandRecord(irInst,srcIdx);
          *(int **)(operandRecordTmp + 0x10) = swizzle;
          sourceReplaced = 1;
        }
      }
      sourceKind = sourceInst[0x26];
      if (sourceKind != 0x2c) {
        if (sourceKind == 0x29) {
          stagedArg3 = (int *)this[3];
          stagedArg2 = srcIdx;
          /* dropped 2 args (found auditing #70 via ExtendIndirectCalls.java / ground-truth
           * disassembly): stock passes srcIdx and loopPtr2 (the value just computed above) too. */
          sourceRegister = (**(code **)(*this + 0x158))(this,irInst,srcIdx,stagedArg3);
LAB_0019852c:
          isThirdSource = srcIdx == (int *)((int)((unsigned char *)0x0) + 3);
          crFlagsByte = (byte)((uint)crFlagsWord >> 0x18);
          if ((isThirdSource) && (!(bool)(crFlagsByte >> 5 & 1))) {
            alphaSelect[2] = 0x11;
          }
          if (writesRgb) {
            laneEnable = rgbLaneEnables;
            if (isThirdSource) {
              if (!(bool)(crFlagsByte >> 5 & 1)) goto LAB_00199cdc;
              if (classifyFlagBit2 != 0) {
                laneEnable = srcpEnablesAlpha;
              }
            }
            selectsWFlag = anyEnabledLaneSelectsW(swizzle,laneEnable);
            anyEnabledLaneSelectsXyzResult = anyEnabledLaneSelectsXyz(swizzle,laneEnable);
            rgbSelect[(int)srcIdx] = 0x14;
            selectSrcIdx = srcIdx;
            if (selectsWFlag == 0) {
              if (anyEnabledLaneSelectsXyzResult != 0) {
                slotIndex = 1;
                slotWordPtr = this + 0xe;
                slotIter = this;
                do {
                  slotInst = (int *)slotIter[7];
                  stagedArg4 = (int *)(slotIndex - 1);
                  if ((sourceInst == slotInst) ||
                     ((((((((slotInst != (int *)0x0 && (sourceInst != (int *)0x0)) && (slotInst[0x20] != 0))
                          && ((selectsWFlag = RegKind__flagBit0(slotInst[0x26]), selectsWFlag != 0 &&
                              ((slotInst[5] & 2U) == 0)))) &&
                         ((selectsWFlag = (**(code **)(*slotInst + 0x50))(slotInst), selectsWFlag == 0 &&
                          ((sourceInst[0x20] != 0 && (selectsWFlag = RegKind__flagBit0(sourceInst[0x26]), selectsWFlag != 0)))))) &&
                        ((sourceInst[5] & 2U) == 0)) &&
                       (((selectsWFlag = (**(code **)(*sourceInst + 0x50))(sourceInst), selectsWFlag == 0 &&
                         ((*(uint *)(slotIter[7] + 0x14) & 0x40) != 0)) && ((sourceInst[5] & 0x40U) != 0))))
                      && (*(int *)(slotIter[7] + 0x94) == sourceInst[0x25])))) {
                    usedMaskOld = this[0x20];
                    *slotWordPtr = sourceRegister;
                    this[0x20] = 1 << (slotIndex & 0x3f) | usedMaskOld;
                    goto LAB_00199c88;
                  }
                  moreSlots = slotIndex != 3;
                  slotWordPtr = slotWordPtr + 1;
                  slotIter = slotIter + 1;
                  slotIndex = slotIndex + 1;
                } while (moreSlots);
                stagedArg4 = (int *)((int)((unsigned char *)0x0) + 3);
LAB_00199c88:
                selectMethod = *(code **)(*this + 0xf8);
                goto joined_r0x00199c90;
              }
            }
            else {
              if (anyEnabledLaneSelectsXyzResult == 0) {
                slotIndex = 1;
                slotWordPtr = this + 0x12;
                slotIter = this;
                do {
                  slotInst = (int *)slotIter[10];
                  stagedArg4 = (int *)(slotIndex - 1);
                  if ((sourceInst == slotInst) ||
                     ((((((slotInst != (int *)0x0 && (sourceInst != (int *)0x0)) &&
                         ((slotInst[0x20] != 0 &&
                          ((selectsWFlag = RegKind__flagBit0(slotInst[0x26]), selectsWFlag != 0 &&
                           ((slotInst[5] & 2U) == 0)))))) &&
                        (selectsWFlag = (**(code **)(*slotInst + 0x50))(slotInst), selectsWFlag == 0)) &&
                       (((sourceInst[0x20] != 0 && (selectsWFlag = RegKind__flagBit0(sourceInst[0x26]), selectsWFlag != 0)) &&
                        ((sourceInst[5] & 2U) == 0)))) &&
                      (((selectsWFlag = (**(code **)(*sourceInst + 0x50))(sourceInst), selectsWFlag == 0 &&
                        ((*(uint *)(slotIter[10] + 0x14) & 0x40) != 0)) &&
                       (((sourceInst[5] & 0x40U) != 0 && (*(int *)(slotIter[10] + 0x94) == sourceInst[0x25])))))))) {
                    usedMaskOld = this[0x21];
                    *slotWordPtr = sourceRegister;
                    this[0x21] = 1 << (slotIndex & 0x3f) | usedMaskOld;
                    goto LAB_00199b44;
                  }
                  moreSlots = slotIndex != 3;
                  slotWordPtr = slotWordPtr + 1;
                  slotIter = slotIter + 1;
                  slotIndex = slotIndex + 1;
                } while (moreSlots);
                stagedArg4 = (int *)((int)((unsigned char *)0x0) + 3);
LAB_00199b44:
                selectMethod = *(code **)(*this + 0xf4);
              }
              else {
                slotIndex = 1;
                slotWordPtr = this;
                slotIter = this;
                do {
                  slotInst = (int *)slotWordPtr[7];
                  stagedArg4 = (int *)(slotIndex - 1);
                  if (((sourceInst == slotInst) ||
                      ((((slotInst != (int *)0x0 && (sourceInst != (int *)0x0)) &&
                        ((slotInst[0x20] != 0 &&
                         ((((((selectsWFlag = RegKind__flagBit0(slotInst[0x26]), selectsWFlag != 0 &&
                              ((slotInst[5] & 2U) == 0)) &&
                             (selectsWFlag = (**(code **)(*slotInst + 0x50))(slotInst), selectsWFlag == 0)) &&
                            ((sourceInst[0x20] != 0 && (selectsWFlag = RegKind__flagBit0(sourceInst[0x26]), selectsWFlag != 0)))) &&
                           ((sourceInst[5] & 2U) == 0)) &&
                          ((selectsWFlag = (**(code **)(*sourceInst + 0x50))(sourceInst), selectsWFlag == 0 &&
                           ((*(uint *)(slotWordPtr[7] + 0x14) & 0x40) != 0)))))))) &&
                       (((sourceInst[5] & 0x40U) != 0 && (*(int *)(slotWordPtr[7] + 0x94) == sourceInst[0x25])))))) &&
                     ((slotInst = (int *)slotWordPtr[10], sourceInst == slotInst ||
                      ((((((slotInst != (int *)0x0 && (sourceInst != (int *)0x0)) && (slotInst[0x20] != 0)) &&
                         ((selectsWFlag = RegKind__flagBit0(slotInst[0x26]), selectsWFlag != 0 &&
                          ((slotInst[5] & 2U) == 0)))) &&
                        (((selectsWFlag = (**(code **)(*slotInst + 0x50))(slotInst), selectsWFlag == 0 &&
                          ((sourceInst[0x20] != 0 && (selectsWFlag = RegKind__flagBit0(sourceInst[0x26]), selectsWFlag != 0)))) &&
                         ((sourceInst[5] & 2U) == 0)))) &&
                       ((((selectsWFlag = (**(code **)(*sourceInst + 0x50))(sourceInst), selectsWFlag == 0 &&
                          ((*(uint *)(slotWordPtr[10] + 0x14) & 0x40) != 0)) && ((sourceInst[5] & 0x40U) != 0))
                        && (*(int *)(slotWordPtr[10] + 0x94) == sourceInst[0x25])))))))) {
                    rgbUsedMaskOld = this[0x20];
                    usedMaskOld = this[0x21];
                    slotIndex = 1 << (slotIndex & 0x3f);
                    slotIter[0x12] = sourceRegister;
                    this[0x20] = slotIndex | rgbUsedMaskOld;
                    this[0x21] = slotIndex | usedMaskOld;
                    slotIter[0xe] = sourceRegister;
                    goto LAB_001999e8;
                  }
                  moreSlots = slotIndex != 3;
                  slotWordPtr = slotWordPtr + 1;
                  slotIndex = slotIndex + 1;
                  slotIter = slotIter + 1;
                } while (moreSlots);
                stagedArg4 = (int *)((int)((unsigned char *)0x0) + 3);
LAB_001999e8:
                (**(code **)(*this + 0xf4))(this,srcIdx,rgbSelect,rgbMod,stagedArg4,swizzle);
                selectMethod = *(code **)(*this + 0xf8);
joined_r0x00199c90:
                if (isThirdSource) {
                  if ((bool)((byte)((uint)crFlagsWord >> 0x1d) & 1)) {
                    selectSrcIdx = (int *)((int)((unsigned char *)0x0) + 3);
                  }
                  else {
                    selectSrcIdx = (int *)((int)((unsigned char *)0x0) + 1);
                  }
                }
              }
              stagedArg2 = rgbSelect;
              stagedArg3 = rgbMod;
              /* dropped 4 args (found auditing #70 via ExtendIndirectCalls.java / ground-truth
               * disassembly): stock passes stagedArg2, stagedArg3, r21 (== stagedArg4: the search loop's
               * `r23 - 1`, or 3 only when the loop runs out - NOT a literal 3, #80), and swizzle
               * too - swizzle's real register (r27) is set once, early in the function, and never
               * reassigned before this call, same as the already-fixed 0xec/0xf0 calls above. */
              (*selectMethod)(this,selectSrcIdx,stagedArg2,stagedArg3,stagedArg4,swizzle);
              alphaHardwareOpcodeOut = swizzle;
            }
          }
LAB_00199cdc:
          if (writesAlpha) {
            operandRecordTmp = IRInst__getOperandRecord(irInst,srcIdx);
            swizzle2 = *(int **)(operandRecordTmp + 0x10);
            alphaLanes = alphaLaneEnables;
            if ((isThirdSource) && (classifyFlagBit2 != 0)) {
              alphaLanes = classifyOut2b;
            }
            selectsW = anyEnabledLaneSelectsW(swizzle2,alphaLanes);
            alphaLanes = anyEnabledLaneSelectsXyz(swizzle2,alphaLanes);
            alphaSelect[(int)srcIdx] = 0x10;
            if (selectsW != 0) {
              slotIndex = 1;
              slotWordPtr = this + 0x12;
              slotIter = this;
              do {
                slotInst = (int *)slotIter[10];
                stagedArg4 = (int *)(slotIndex - 1);
                if ((sourceInst == slotInst) ||
                   ((((slotInst != (int *)0x0 && (sourceInst != (int *)0x0)) &&
                     ((slotInst[0x20] != 0 &&
                      ((((selectsW = RegKind__flagBit0(slotInst[0x26]), selectsW != 0 &&
                         ((slotInst[5] & 2U) == 0)) &&
                        (selectsW = (**(code **)(*slotInst + 0x50))(slotInst), selectsW == 0)) &&
                       ((sourceInst[0x20] != 0 && (selectsW = RegKind__flagBit0(sourceInst[0x26]), selectsW != 0)))))))) &&
                    ((((sourceInst[5] & 2U) == 0 &&
                      ((selectsW = (**(code **)(*sourceInst + 0x50))(sourceInst), selectsW == 0 &&
                       ((*(uint *)(slotIter[10] + 0x14) & 0x40) != 0)))) &&
                     (((sourceInst[5] & 0x40U) != 0 && (*(int *)(slotIter[10] + 0x94) == sourceInst[0x25])))))))) {
                  usedMaskOld = this[0x21];
                  *slotWordPtr = sourceRegister;
                  this[0x21] = 1 << (slotIndex & 0x3f) | usedMaskOld;
                  goto LAB_00199e60;
                }
                moreSlots = slotIndex != 3;
                slotWordPtr = slotWordPtr + 1;
                slotIter = slotIter + 1;
                slotIndex = slotIndex + 1;
              } while (moreSlots);
              stagedArg4 = (int *)((int)((unsigned char *)0x0) + 3);
LAB_00199e60:
              selectSrcIdx = srcIdx;
              if (isThirdSource) {
                if ((bool)((byte)((uint)crFlagsWord >> 0x1d) & 1)) {
                  selectSrcIdx = (int *)((int)((unsigned char *)0x0) + 3);
                }
                else {
                  selectSrcIdx = (int *)((int)((unsigned char *)0x0) + 1);
                }
              }
              stagedArg2 = alphaSelect;
              stagedArg3 = alphaModAlias;
              alphaHardwareOpcodeOut = swizzle2;
              /* dropped 4 args (found auditing #70 via ExtendIndirectCalls.java / ground-truth
               * disassembly): stock passes loopPtr, loopPtr2, r21 (== a4, search-loop r23-1 / 3 on exhaustion - not a literal 3, #80), and piVar25 too. */
              (**(code **)(*this + 0xfc))(this,selectSrcIdx,stagedArg2,stagedArg3,stagedArg4,alphaHardwareOpcodeOut);
            }
            if (alphaLanes != 0) {
              slotIndex = 1;
              slotWordPtr = this + 0xe;
              slotIter = this;
              do {
                slotInst = (int *)slotIter[7];
                stagedArg4 = (int *)(slotIndex - 1);
                if ((sourceInst == slotInst) ||
                   (((((slotInst != (int *)0x0 && (sourceInst != (int *)0x0)) && (slotInst[0x20] != 0)) &&
                     ((((alphaLanes = RegKind__flagBit0(slotInst[0x26]), alphaLanes != 0 &&
                        ((slotInst[5] & 2U) == 0)) &&
                       ((alphaLanes = (**(code **)(*slotInst + 0x50))(slotInst), alphaLanes == 0 &&
                        ((sourceInst[0x20] != 0 && (alphaLanes = RegKind__flagBit0(sourceInst[0x26]), alphaLanes != 0)))))) &&
                      ((sourceInst[5] & 2U) == 0)))) &&
                    ((((alphaLanes = (**(code **)(*sourceInst + 0x50))(sourceInst), alphaLanes == 0 &&
                       ((*(uint *)(slotIter[7] + 0x14) & 0x40) != 0)) && ((sourceInst[5] & 0x40U) != 0)) &&
                     (*(int *)(slotIter[7] + 0x94) == sourceInst[0x25])))))) {
                  usedMaskOld = this[0x20];
                  *slotWordPtr = sourceRegister;
                  this[0x20] = 1 << (slotIndex & 0x3f) | usedMaskOld;
                  goto LAB_00199fdc;
                }
                moreSlots = slotIndex != 3;
                slotWordPtr = slotWordPtr + 1;
                slotIter = slotIter + 1;
                slotIndex = slotIndex + 1;
              } while (moreSlots);
              stagedArg4 = (int *)((int)((unsigned char *)0x0) + 3);
LAB_00199fdc:
              selectSrcIdx2 = srcIdx;
              if (isThirdSource) {
                if ((bool)((byte)((uint)crFlagsWord >> 0x1d) & 1)) {
                  selectSrcIdx2 = (int *)((int)((unsigned char *)0x0) + 3);
                }
                else {
                  selectSrcIdx2 = (int *)((int)((unsigned char *)0x0) + 1);
                }
              }
              stagedArg2 = alphaSelect;
              stagedArg3 = alphaModAlias;
              /* dropped 4 args (found auditing #70 via ExtendIndirectCalls.java / ground-truth
               * disassembly): stock passes stagedArg2, stagedArg3, r21 (== stagedArg4, not a literal 3, #80), and swizzle2 too -
               * swizzle2 directly, not selectSrcIdx2 (reassigned below, diverged from swizzle2 by here). */
              (**(code **)(*this + 0x100))(this,selectSrcIdx2,stagedArg2,stagedArg3,stagedArg4,swizzle2);
              alphaHardwareOpcodeOut = swizzle2;
            }
          }
        }
        else {
          if ((((sourceInst[0x20] != 0) && (sourceKind = RegKind__flagBit0(sourceKind), sourceKind != 0)) &&
              ((sourceInst[5] & 2U) == 0)) && (sourceKind = (**(code **)(*sourceInst + 0x50))(sourceInst), sourceKind == 0)) {
            sourceRegister = FUN_00134de8(*(undefined4 *)(this[3] + 0x6c4),sourceInst);
            vslot80Result = (**(code **)(*sourceInst + 0x80))(sourceInst);
            if (vslot80Result != 0) {
              stagedArg3 = (int *)this[3];
              stagedArg2 = irInst;
              /* dropped 2 args (found auditing #70 via ExtendIndirectCalls.java / ground-truth
               * disassembly): stock passes irInst and loopPtr2 too. */
              (**(code **)(*this + 0x154))(this,srcIdx,irInst,stagedArg3);
            }
            goto LAB_0019852c;
          }
          vslot50Result = (**(code **)(*sourceInst + 0x50))(sourceInst);
          if (vslot50Result != 0) {
            sourceRegister = thunk_FUN_00134de8(*(undefined4 *)(this[3] + 0x6c4),sourceInst);
            goto LAB_0019852c;
          }
          vslot48Result = (**(code **)(*sourceInst + 0x48))(sourceInst);
          if (vslot48Result != 0) {
            if (sourceInst[0x26] == 0x33) {
              stagedArg2 = &sourceRegister;
              /* dropped 1 arg (found auditing #70 via ExtendIndirectCalls.java / ground-truth
               * disassembly): stock passes &sourceRegister (loopPtr) too. */
              vslotDcResult = (**(code **)(*this + 0xdc))(this,sourceInst,stagedArg2);
              if (vslotDcResult == 0) {
                if ((srcIdx != (int *)((int)((unsigned char *)0x0) + 3)) ||
                   ((bool)((byte)((uint)crFlagsWord >> 0x1d) & 1))) {
                  if (writesRgb) {
                    stagedArg2 = rgbSelect;
                    stagedArg3 = rgbMod;
                    stagedArg4 = irInst;
                    /* dropped 3 args (found auditing #70 via ExtendIndirectCalls.java /
                     * ground-truth disassembly): stock passes loopPtr, loopPtr2, a4 too. */
                    (**(code **)(*this + 0xd4))(this,srcIdx,stagedArg2,stagedArg3,stagedArg4);
                  }
                  if (writesAlpha) {
                    stagedArg2 = alphaSelect;
                    stagedArg3 = alphaModAlias;
                    stagedArg4 = irInst;
                    /* dropped 3 args (found auditing #70 via ExtendIndirectCalls.java /
                     * ground-truth disassembly): stock passes loopPtr, loopPtr2, a4 too. */
                    (**(code **)(*this + 0xd8))(this,srcIdx,stagedArg2,stagedArg3,stagedArg4);
                  }
                }
                else {
                  alphaSelect[2] = 0x11;
                  stagedArg2 = alphaSelect;
                  stagedArg3 = alphaModAlias;
                  stagedArg4 = irInst;
                  (**(code **)(*this + 0xd8))
                            (this,3,alphaSelect,alphaModAlias,irInst,alphaHardwareOpcodeOut,*(code **)(*this + 0xd8)
                            );
                  alphaSelect[1] = alphaSelect[3];
                }
                goto LAB_0019a030;
              }
            }
            else {
              sourceRegister = sourceInst[0x25];
              stagedArg2 = sourceInst;
              R300MachineAssembler__trackMaxLevelAndAssemble(this,sourceRegister,sourceInst);
              sourceRegister = (**(code **)(*this + 0xe0))(this,sourceRegister);
            }
            goto LAB_0019852c;
          }
          vslot5cResult = (**(code **)(*sourceInst + 0x5c))(sourceInst);
          if (vslot5cResult == 0) goto LAB_0019852c;
          if ((srcIdx != (int *)((int)((unsigned char *)0x0) + 3)) ||
             ((bool)((byte)((uint)crFlagsWord >> 0x1d) & 1))) {
            if (writesRgb) {
              stagedArg2 = rgbSelect;
              stagedArg3 = rgbMod;
              stagedArg4 = swizzle;
              /* dropped 3 args (found auditing #70 via ExtendIndirectCalls.java /
               * ground-truth disassembly): stock passes loopPtr, loopPtr2, a4 too. */
              (**(code **)(*this + 0xec))(this,srcIdx,stagedArg2,stagedArg3,stagedArg4);
            }
            if (writesAlpha) {
              stagedArg2 = alphaSelect;
              stagedArg3 = alphaModAlias;
              stagedArg4 = swizzle;
              /* dropped 3 args (found auditing #70 via ExtendIndirectCalls.java /
               * ground-truth disassembly): stock passes loopPtr, loopPtr2, a4 too. */
              (**(code **)(*this + 0xf0))(this,srcIdx,stagedArg2,stagedArg3,stagedArg4);
            }
          }
          else {
            alphaSelect[2] = 0x11;
            stagedArg2 = alphaSelect;
            stagedArg3 = alphaModAlias;
            stagedArg4 = swizzle;
            (**(code **)(*this + 0xf0))
                      (this,1,alphaSelect,alphaModAlias,swizzle,alphaHardwareOpcodeOut,*(code **)(*this + 0xf0));
          }
          SelectWord__readMask(&swizzleMask,swizzle);
          swizzleLowByte = swizzleMask & 0xff;
          swizzleHighClear = (swizzleMask & 0xffffff00) == 0;
          srcOpcode = *(int *)(sourceInst[0x22] + 8);
          sourceWidth = (**(code **)(*sourceInst + 0x14))
                             (sourceInst,staleArg1,stagedArg2,stagedArg3,stagedArg4,alphaHardwareOpcodeOut,sourceInst[0x22],*(code **)(*sourceInst + 0x14));
          if (!swizzleHighClear) {
            this[0x20] = sourceWidth * 4 - 2U | this[0x20];
            (**(code **)(*this + 0xe4))
                      (this,*(undefined4 *)(PTR_DAT_001e913c + srcOpcode * 0x38 + 0xc),stagedArg2,
                       stagedArg3,stagedArg4,alphaHardwareOpcodeOut,PTR_DAT_001e913c + srcOpcode * 0x38);
          }
          maskByteNonZero = -1 < (int)-swizzleLowByte;
          if (!maskByteNonZero) {
            this[0x21] = sourceWidth * 4 - 2U | this[0x21];
            (**(code **)(*this + 0xe8))
                      (this,*(undefined4 *)(PTR_DAT_001e913c + srcOpcode * 0x38 + 0xc),stagedArg2,
                       stagedArg3,stagedArg4,alphaHardwareOpcodeOut,PTR_DAT_001e913c + srcOpcode * 0x38);
          }
          if (sourceWidth < 2) {
            if (sourceWidth != 1) goto LAB_0019a030;
            sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,1);
            if ((((sourceDef3[0x20] == 0) || (sourceWidth = RegKind__flagBit0(sourceDef3[0x26]), sourceWidth == 0)) ||
                ((sourceDef3[5] & 2U) != 0)) ||
               (sourceWidth = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), sourceWidth != 0)) {
              sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,1);
              vslot50Result = (**(code **)(*sourceDef3 + 0x50))(sourceDef3);
              if (vslot50Result != 0) goto LAB_001994a8;
              sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,1);
              hwRegister = 0;
              vslot48Result = (**(code **)(*sourceDef3 + 0x48))(sourceDef3);
              if (vslot48Result != 0) {
                innerSource = IRInst__getOperandSource(sourceInst,1);
                registerIndex = *(undefined4 *)(innerSource + 0x94);
                stagedArg2 = (int *)IRInst__getOperandSource(sourceInst,1);
                R300MachineAssembler__trackMaxLevelAndAssemble(this,registerIndex,stagedArg2);
                hwRegister = (**(code **)(*this + 0xe0))(this,registerIndex);
              }
            }
            else {
LAB_001994a8:
              allocTable = *(undefined4 *)(this[3] + 0x6c4);
              sourceDef2 = IRInst__getOperandSource(sourceInst,1);
              hwRegister = thunk_FUN_00134de8(allocTable,sourceDef2);
            }
            if (!swizzleHighClear) {
              innerSource = IRInst__getOperandSource(sourceInst,1);
              if ((((((innerSource != this[7]) && (innerSource = IRInst__getOperandSource(sourceInst,1), innerSource != 0)) &&
                    ((this[7] != 0 &&
                     ((sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,1), sourceDef3[0x20] != 0 &&
                      (innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource != 0)))))) &&
                   ((sourceDef3[5] & 2U) == 0)) &&
                  (((innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource == 0 &&
                    (sourceDef3 = (int *)this[7], sourceDef3[0x20] != 0)) &&
                   (innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource != 0)))) &&
                 ((((sourceDef3[5] & 2U) == 0 &&
                   (innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource == 0)) &&
                  ((innerSource = IRInst__getOperandSource(sourceInst,1), (*(uint *)(innerSource + 0x14) & 0x40) != 0 &&
                   ((*(uint *)(this[7] + 0x14) & 0x40) != 0)))))) {
                IRInst__getOperandSource(sourceInst,1);
              }
              this[0xe] = hwRegister;
            }
            if (!maskByteNonZero) {
              innerSource = IRInst__getOperandSource(sourceInst,1);
              if (((((innerSource != this[10]) && (innerSource = IRInst__getOperandSource(sourceInst,1), innerSource != 0)) &&
                   ((this[10] != 0 &&
                    (((sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,1), sourceDef3[0x20] != 0 &&
                      (innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource != 0)) &&
                     ((sourceDef3[5] & 2U) == 0)))))) &&
                  ((innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource == 0 &&
                   (sourceDef3 = (int *)this[10], sourceDef3[0x20] != 0)))) &&
                 ((innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource != 0 &&
                  ((((sourceDef3[5] & 2U) == 0 &&
                    (innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource == 0)) &&
                   ((innerSource = IRInst__getOperandSource(sourceInst,1), (*(uint *)(innerSource + 0x14) & 0x40) != 0 &&
                    ((*(uint *)(this[10] + 0x14) & 0x40) != 0)))))))) {
                IRInst__getOperandSource(sourceInst,1);
              }
              this[0x12] = hwRegister;
            }
          }
          else {
            sourceDef = (int *)IRInst__getOperandSource(sourceInst,1);
            if ((((sourceDef[0x20] == 0) || (sourceWidth = RegKind__flagBit0(sourceDef[0x26]), sourceWidth == 0)) ||
                ((sourceDef[5] & 2U) != 0)) ||
               (sourceWidth = (**(code **)(*sourceDef + 0x50))(sourceDef), sourceWidth != 0)) {
              sourceDef = (int *)IRInst__getOperandSource(sourceInst,1);
              sourceWidth = (**(code **)(*sourceDef + 0x50))(sourceDef);
              if (sourceWidth != 0) goto LAB_00198950;
              sourceDef = (int *)IRInst__getOperandSource(sourceInst,1);
              hwRegister2 = 0;
              sourceWidth = (**(code **)(*sourceDef + 0x48))(sourceDef);
              if (sourceWidth != 0) {
                sourceWidth = IRInst__getOperandSource(sourceInst,1);
                registerIndex2 = *(undefined4 *)(sourceWidth + 0x94);
                stagedArg2 = (int *)IRInst__getOperandSource(sourceInst,1);
                R300MachineAssembler__trackMaxLevelAndAssemble(this,registerIndex2,stagedArg2);
                hwRegister2 = (**(code **)(*this + 0xe0))(this,registerIndex2);
              }
            }
            else {
LAB_00198950:
              allocTable = *(undefined4 *)(this[3] + 0x6c4);
              sourceDef2 = IRInst__getOperandSource(sourceInst,1);
              hwRegister2 = thunk_FUN_00134de8(allocTable,sourceDef2);
            }
            sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,2);
            if (((sourceDef3[0x20] == 0) || (sourceWidth = RegKind__flagBit0(sourceDef3[0x26]), sourceWidth == 0)) ||
               (((sourceDef3[5] & 2U) != 0 ||
                (sourceWidth = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), sourceWidth != 0)))) {
              sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,2);
              vslot50Result = (**(code **)(*sourceDef3 + 0x50))(sourceDef3);
              if (vslot50Result != 0) goto LAB_00198a1c;
              sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,2);
              hwRegister3 = 0;
              vslot48Result = (**(code **)(*sourceDef3 + 0x48))(sourceDef3);
              if (vslot48Result != 0) {
                innerSource2 = IRInst__getOperandSource(sourceInst,2);
                registerIndex3 = *(undefined4 *)(innerSource2 + 0x94);
                stagedArg2 = (int *)IRInst__getOperandSource(sourceInst,2);
                R300MachineAssembler__trackMaxLevelAndAssemble(this,registerIndex3,stagedArg2);
                hwRegister3 = (**(code **)(*this + 0xe0))(this,registerIndex3);
              }
            }
            else {
LAB_00198a1c:
              allocTable = *(undefined4 *)(this[3] + 0x6c4);
              sourceDef2 = IRInst__getOperandSource(sourceInst,2);
              hwRegister3 = thunk_FUN_00134de8(allocTable,sourceDef2);
            }
            if (swizzleHighClear) {
LAB_00198f54:
              isOpcode9a = false;
            }
            else {
              innerSource = IRInst__getOperandSource(sourceInst,1);
              if (((innerSource != this[8]) &&
                  (((((innerSource = IRInst__getOperandSource(sourceInst,1), innerSource == 0 || (this[8] == 0)) ||
                     ((sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,1), sourceDef3[0x20] == 0 ||
                      (((innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource == 0 ||
                        ((sourceDef3[5] & 2U) != 0)) ||
                       (innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource != 0)))))) ||
                    ((sourceDef3 = (int *)this[8], sourceDef3[0x20] == 0 ||
                     (innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource == 0)))) ||
                   (((sourceDef3[5] & 2U) != 0 ||
                    (((innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource != 0 ||
                      (innerSource = IRInst__getOperandSource(sourceInst,1), (*(uint *)(innerSource + 0x14) & 0x40) == 0)) ||
                     (((*(uint *)(this[8] + 0x14) & 0x40) == 0 ||
                      (innerSource = IRInst__getOperandSource(sourceInst,1),
                      *(int *)(innerSource + 0x94) != *(int *)(this[8] + 0x94))))))))))) ||
                 ((innerSource = IRInst__getOperandSource(sourceInst,2), innerSource != this[7] &&
                  ((((innerSource = IRInst__getOperandSource(sourceInst,2), innerSource == 0 || (this[7] == 0)) ||
                    (sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,2), sourceDef3[0x20] == 0)) ||
                   (((innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource == 0 || ((sourceDef3[5] & 2U) != 0))
                    || ((((innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource != 0 ||
                          ((sourceDef3 = (int *)this[7], sourceDef3[0x20] == 0 ||
                           (innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource == 0)))) ||
                         ((sourceDef3[5] & 2U) != 0)) ||
                        ((((innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource != 0 ||
                           (innerSource = IRInst__getOperandSource(sourceInst,2), (*(uint *)(innerSource + 0x14) & 0x40) == 0)) ||
                          ((*(uint *)(this[7] + 0x14) & 0x40) == 0)) ||
                         (innerSource = IRInst__getOperandSource(sourceInst,2),
                         *(int *)(innerSource + 0x94) != *(int *)(this[7] + 0x94))))))))))))) {
                innerSource = IRInst__getOperandSource(sourceInst,1);
                if (((innerSource == this[7]) ||
                    ((((innerSource = IRInst__getOperandSource(sourceInst,1), innerSource != 0 && (this[7] != 0)) &&
                      ((sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,1), sourceDef3[0x20] != 0 &&
                       ((innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource != 0 &&
                        ((sourceDef3[5] & 2U) == 0)))))) &&
                     (((innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource == 0 &&
                       ((((sourceDef3 = (int *)this[7], sourceDef3[0x20] != 0 &&
                          (innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource != 0)) &&
                         ((sourceDef3[5] & 2U) == 0)) &&
                        ((innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource == 0 &&
                         (innerSource = IRInst__getOperandSource(sourceInst,1), (*(uint *)(innerSource + 0x14) & 0x40) != 0))))))
                      && (((*(uint *)(this[7] + 0x14) & 0x40) != 0 &&
                          (innerSource = IRInst__getOperandSource(sourceInst,1),
                          *(int *)(innerSource + 0x94) == *(int *)(this[7] + 0x94))))))))) &&
                   ((innerSource = IRInst__getOperandSource(sourceInst,2), innerSource == this[8] ||
                    (((((innerSource = IRInst__getOperandSource(sourceInst,2), innerSource != 0 && (this[8] != 0)) &&
                       ((sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,2), sourceDef3[0x20] != 0 &&
                        (((innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource != 0 &&
                          ((sourceDef3[5] & 2U) == 0)) &&
                         (innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource == 0)))))) &&
                      ((sourceDef3 = (int *)this[8], sourceDef3[0x20] != 0 &&
                       (innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource != 0)))) &&
                     (((sourceDef3[5] & 2U) == 0 &&
                      (((innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource == 0 &&
                        (innerSource = IRInst__getOperandSource(sourceInst,2), (*(uint *)(innerSource + 0x14) & 0x40) != 0)) &&
                       (((*(uint *)(this[8] + 0x14) & 0x40) != 0 &&
                        (innerSource = IRInst__getOperandSource(sourceInst,2),
                        *(int *)(innerSource + 0x94) == *(int *)(this[8] + 0x94))))))))))))) {
                  this[0xe] = hwRegister2;
                  this[0xf] = hwRegister3;
                  if ((srcOpcode == 0x9a) && (isOpcode9a = true, (irInstWords[8] & 2U) == 0)) goto LAB_00198f58;
                }
                goto LAB_00198f54;
              }
              isOpcode9a = false;
              this[0xf] = hwRegister2;
              this[0xe] = hwRegister3;
            }
LAB_00198f58:
            if (maskByteNonZero) {
LAB_0019941c:
              isOpcode9aAlpha = false;
            }
            else {
              innerSource = IRInst__getOperandSource(sourceInst,1);
              if (((innerSource != this[0xb]) &&
                  (((((((innerSource = IRInst__getOperandSource(sourceInst,1), innerSource == 0 || (this[0xb] == 0)) ||
                       (sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,1), sourceDef3[0x20] == 0)) ||
                      ((innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource == 0 ||
                       ((sourceDef3[5] & 2U) != 0)))) ||
                     (innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource != 0)) ||
                    (((sourceDef3 = (int *)this[0xb], sourceDef3[0x20] == 0 ||
                      (innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource == 0)) ||
                     (((sourceDef3[5] & 2U) != 0 ||
                      (((innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource != 0 ||
                        (innerSource = IRInst__getOperandSource(sourceInst,1), (*(uint *)(innerSource + 0x14) & 0x40) == 0)) ||
                       ((*(uint *)(this[0xb] + 0x14) & 0x40) == 0)))))))) ||
                   (innerSource = IRInst__getOperandSource(sourceInst,1),
                   *(int *)(innerSource + 0x94) != *(int *)(this[0xb] + 0x94))))) ||
                 ((innerSource = IRInst__getOperandSource(sourceInst,2), innerSource != this[10] &&
                  ((((innerSource = IRInst__getOperandSource(sourceInst,2), innerSource == 0 || (this[10] == 0)) ||
                    ((sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,2), sourceDef3[0x20] == 0 ||
                     ((innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource == 0 || ((sourceDef3[5] & 2U) != 0)
                      ))))) ||
                   (((innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource != 0 ||
                     (((sourceDef3 = (int *)this[10], sourceDef3[0x20] == 0 ||
                       (innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource == 0)) ||
                      ((sourceDef3[5] & 2U) != 0)))) ||
                    (((innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource != 0 ||
                      (innerSource = IRInst__getOperandSource(sourceInst,2), (*(uint *)(innerSource + 0x14) & 0x40) == 0)) ||
                     (((*(uint *)(this[10] + 0x14) & 0x40) == 0 ||
                      (innerSource = IRInst__getOperandSource(sourceInst,2),
                      *(int *)(innerSource + 0x94) != *(int *)(this[10] + 0x94))))))))))))) {
                innerSource = IRInst__getOperandSource(sourceInst,1);
                if (((innerSource == this[10]) ||
                    ((((innerSource = IRInst__getOperandSource(sourceInst,1), innerSource != 0 && (this[10] != 0)) &&
                      (((sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,1), sourceDef3[0x20] != 0 &&
                        ((((innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource != 0 &&
                           ((sourceDef3[5] & 2U) == 0)) &&
                          (innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource == 0)) &&
                         ((sourceDef3 = (int *)this[10], sourceDef3[0x20] != 0 &&
                          (innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource != 0)))))) &&
                       ((sourceDef3[5] & 2U) == 0)))) &&
                     (((innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource == 0 &&
                       (innerSource = IRInst__getOperandSource(sourceInst,1), (*(uint *)(innerSource + 0x14) & 0x40) != 0)) &&
                      (((*(uint *)(this[10] + 0x14) & 0x40) != 0 &&
                       (innerSource = IRInst__getOperandSource(sourceInst,1),
                       *(int *)(innerSource + 0x94) == *(int *)(this[10] + 0x94))))))))) &&
                   ((innerSource = IRInst__getOperandSource(sourceInst,2), innerSource == this[0xb] ||
                    (((((innerSource = IRInst__getOperandSource(sourceInst,2), innerSource != 0 && (this[0xb] != 0)) &&
                       (sourceDef3 = (int *)IRInst__getOperandSource(sourceInst,2), sourceDef3[0x20] != 0)) &&
                      (((innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource != 0 &&
                        ((sourceDef3[5] & 2U) == 0)) &&
                       ((innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource == 0 &&
                        ((sourceDef3 = (int *)this[0xb], sourceDef3[0x20] != 0 &&
                         (innerSource = RegKind__flagBit0(sourceDef3[0x26]), innerSource != 0)))))))) &&
                     (((sourceDef3[5] & 2U) == 0 &&
                      ((((innerSource = (**(code **)(*sourceDef3 + 0x50))(sourceDef3), innerSource == 0 &&
                         (innerSource = IRInst__getOperandSource(sourceInst,2), (*(uint *)(innerSource + 0x14) & 0x40) != 0)) &&
                        ((*(uint *)(this[0xb] + 0x14) & 0x40) != 0)) &&
                       (innerSource = IRInst__getOperandSource(sourceInst,2),
                       *(int *)(innerSource + 0x94) == *(int *)(this[0xb] + 0x94))))))))))) {
                  this[0x12] = hwRegister2;
                  this[0x13] = hwRegister3;
                  if ((srcOpcode == 0x9a) && (isOpcode9aAlpha = true, (irInstWords[8] & 2U) == 0)) goto LAB_00199420;
                }
                goto LAB_0019941c;
              }
              isOpcode9aAlpha = false;
              this[0x13] = hwRegister2;
              this[0x12] = hwRegister3;
            }
LAB_00199420:
            if ((isOpcode9a) || (isOpcode9aAlpha)) {
              stagedArg2 = (int *)(irInstWords[8] & 1U ^ 1);
              IROperand__setModifierBits(irInstWords + 3,1,stagedArg2);
            }
          }
        }
LAB_0019a030:
        if (sourceReplaced != 0) {
          if (writesAlpha) {
            (**(code **)(*this + 0x10c))(this,srcIdx,alphaModAlias,movInst,picTableWord);
          }
          if (writesRgb) {
            (**(code **)(*this + 0x108))(this,srcIdx,rgbMod,movInst,picTableWord);
          }
          stagedArg4 = (int *)this[3];
          stagedArg3 = (int *)0x0;
          stagedArg2 = movInst;
          IRInst__setOperandSource(irInst,srcIdx,movInst,0,stagedArg4);
          if (srcIdx == (int *)0x0) {
            irInst[0x27] = picTableWord;
          }
          else {
            operandRecordTmp = IRInst__getOperandRecord(irInst,srcIdx);
            *(int *)(operandRecordTmp + 0x10) = picTableWord;
          }
        }
      }
      srcIdx = (int *)((int)srcIdx + 1);
      irInstWords = irInstWords + 6;
    } while ((int)srcIdx <= sourceCount);
  }
  else if (0 < sourceCount) goto LAB_00198290;
  (**(code **)(*this + 0x118))(this,this[0x20],this + 0xd,this[0x21],this + 0x11);
  (**(code **)(*this + 0x11c))
            (this,irInst,classifyWritesRgb,rgbSelect,rgbMod,classifyWritesAlpha,alphaSelect,alphaModAlias);
  if (irInst[0x26] == 0x2c) {
LAB_0019a1f4:
    selectMethod = *(code **)(*this + 0x124);
  }
  else {
    if ((((irInst[0x20] != 0) && (sourceCount = RegKind__flagBit0(irInst[0x26]), sourceCount != 0)) &&
        (((irInst[5] & 2U) == 0 && (sourceCount = (**(code **)(*irInst + 0x50))(irInst), sourceCount == 0))))
       || (sourceCount = (**(code **)(*irInst + 0x50))(irInst), sourceCount != 0)) {
      selectMethod = *(code **)(*this + 0x120);
      allocatedRegister = thunk_FUN_00134de8(*(undefined4 *)(this[3] + 0x6c4),irInst);
      (*selectMethod)(this,classifyWritesRgb,classifyWritesAlpha,irInst,allocatedRegister);
      goto LAB_0019a230;
    }
    if ((irInst[5] & 2U) != 0) goto LAB_0019a1f4;
    if ((irInst[5] & 0x80000U) == 0) goto LAB_0019a230;
    selectMethod = *(code **)(*this + 0x128);
  }
  (*selectMethod)(this,classifyWritesRgb,classifyWritesAlpha,irInst);
LAB_0019a230:
  if (classifyRgbCopy != 0) {
    (**(code **)(*this + 300))(this,rgbHwOpcode,irOpcode,irInst);
  }
  if (classifyAlphaCopy != 0) {
    (**(code **)(*this + 0x130))(this,alphaHwOpcode,irOpcode,irInst);
  }
  return;
}

/* maxSigned @ 0x19a2e0 (16 bytes) */
int maxSigned(firstValue, secondValue)
  int firstValue;
  int secondValue;
{
  if (secondValue < firstValue) {
    return firstValue;
  }
  return secondValue;
}

/* R300VMachineAssembler__finishProgram @ 0x19a2f0 (120 bytes) */
int R300VMachineAssembler__finishProgram(this)
  int this;
{
  **(undefined4 **)(this + 0x50) =
       *(undefined4 *)(*(int *)(*(int *)(this + 0xc) + 0x30c) + 0x40);
  *(undefined4 *)(*(int *)(this + 0x50) + 0xc) = *(undefined4 *)(this + 0x24);
  *(undefined4 *)(*(int *)(this + 0x50) + 0x10) = *(undefined4 *)(this + 0x58);
  *(int *)(*(int *)(this + 0x50) + 0x14) = *(int *)(this + 0x34) + 1;
  *(int *)(*(int *)(this + 0x50) + 0x18) = *(int *)(this + 0x38) + 1;
  *(undefined4 *)(*(int *)(this + 0x50) + 0x1c) = *(undefined4 *)(this + 0x2c);
  *(undefined4 *)(*(int *)(this + 0x50) + 0x20) = *(undefined4 *)(this + 0x30);
  *(int *)(*(int *)(this + 0x50) + 0x24) = *(int *)(this + 0x4c) + 1;
  return;
}

/* R300VMachineAssembler__clearInstructionByte3 @ 0x19a368 (28 bytes) */
int R300VMachineAssembler__clearInstructionByte3(this)
  int this;
{
  *(undefined1 *)(*(int *)(this + 0x58) * 0x10 + *(int *)(this + 0x44) + 3) = 0;
  return;
}

/* R300VMachineAssembler__nextInstruction @ 0x19a384 (56 bytes) */
int R300VMachineAssembler__nextInstruction(this)
  int this;
{
  ((int (*)())R300VMachineAssembler__clearInstructionByte3)(this);
  *(int *)(this + 0x58) = *(int *)(this + 0x58) + 1;
  return;
}

/* R300VMachineAssembler__logStatistics @ 0x19a3bc (172 bytes) */
int R300VMachineAssembler__logStatistics(this, quiet, unused1, unused2, unused3, printfArg6, printfArg7, printfArg8)
  int this;
  int quiet;
  undefined4 unused1;
  undefined4 unused2;
  undefined4 unused3;
  undefined4 printfArg6;
  undefined4 printfArg7;
  undefined4 printfArg8;
{
  int candidateAluCount;
  int totalCount;
  int packedPercent;
  
  totalCount = *(int *)(this + 0x5c) + *(int *)(this + 0x58);
  Compiler__logf(*(undefined4 *)(this + 0xc),
               "Assembler : emits %d cf, %d alu -> %d total instruction(s)\n",
               *(int *)(this + 0x5c),*(int *)(this + 0x58),totalCount,printfArg6,printfArg7,printfArg8);
  Compiler__logf(*(undefined4 *)(this + 0xc),
               "INFO:# of control flow %d, # of exec %d instructions\n",
               *(undefined4 *)(this + 0x5c),*(undefined4 *)(this + 0x58),totalCount,printfArg6,printfArg7
               ,printfArg8);
  if (quiet == 0) {
    candidateAluCount = *(int *)(this + 0x78);
    packedPercent = 0;
    if (candidateAluCount != 0) {
      packedPercent = (*(int *)(this + 0x74) * 100) / candidateAluCount;
    }
    Compiler__logf(*(undefined4 *)(this + 0xc),
                 "Assembler : of %d candidate alu instruction(s), %d are packed (%%%d)\n",candidateAluCount,
                 *(int *)(this + 0x74),packedPercent,printfArg6,printfArg7,printfArg8);
    return;
  }
  return;
}

/* R300VMachineAssembler__copyControlFlowToOutput @ 0x19a484 (132 bytes) */
int R300VMachineAssembler__copyControlFlowToOutput(this)
  int this;
{
  undefined4 srcWord5;
  undefined4 srcWord4;
  undefined4 *srcEntryWords;
  undefined4 srcWord1;
  int loopIndex;
  int entryOffset;
  undefined4 srcWord3;
  int dstEntry;
  undefined4 srcWord2;
  int srcEntry;
  
  **(undefined4 **)(this + 0x54) = *(undefined4 *)(this + 0x5c);
  if (*(int *)(this + 0x5c) < 1) {
    return;
  }
  loopIndex = 0;
  entryOffset = 0;
  do {
    loopIndex = loopIndex + 1;
    srcEntry = entryOffset + *(int *)(this + 0x40);
    srcEntryWords = (undefined4 *)(entryOffset + *(int *)(this + 0x40));
    srcWord1 = *(undefined4 *)(srcEntry + 4);
    dstEntry = entryOffset + *(int *)(this + 0x54);
    srcWord2 = *(undefined4 *)(srcEntry + 8);
    srcWord3 = *(undefined4 *)(srcEntry + 0xc);
    entryOffset = entryOffset + 0x1c;
    *(undefined4 *)(dstEntry + 4) = *srcEntryWords;
    *(undefined4 *)(dstEntry + 8) = srcWord1;
    *(undefined4 *)(dstEntry + 0xc) = srcWord2;
    *(undefined4 *)(dstEntry + 0x10) = srcWord3;
    srcWord4 = *(undefined4 *)(srcEntry + 0x10);
    srcWord5 = *(undefined4 *)(srcEntry + 0x14);
    *(undefined4 *)(dstEntry + 0x1c) = *(undefined4 *)(srcEntry + 0x18);
    *(undefined4 *)(dstEntry + 0x14) = srcWord4;
    *(undefined4 *)(dstEntry + 0x18) = srcWord5;
  } while (loopIndex < *(int *)(this + 0x5c));
  return;
}

/* R300VMachineAssembler__vslot_noOp_19a508 @ 0x19a508 (4 bytes) */
int R300VMachineAssembler__vslot_noOp_19a508()
{
  return;
}

/* R300VMachineAssembler__vslot_noOp_19a50c @ 0x19a50c (4 bytes) */
int R300VMachineAssembler__vslot_noOp_19a50c()
{
  return;
}

/* R300VMachineAssembler__clearCurrentInstruction @ 0x19a510 (40 bytes) */
int R300VMachineAssembler__clearCurrentInstruction(this)
  int this;
{
  int instructionByteOffset;
  int instructionWords;
  
  instructionByteOffset = *(int *)(this + 0x58) * 0x10;
  instructionWords = instructionByteOffset + *(int *)(this + 0x44);
  *(undefined4 *)(instructionByteOffset + *(int *)(this + 0x44)) = 0;
  *(undefined4 *)(instructionWords + 0xc) = 0;
  *(undefined4 *)(instructionWords + 4) = 0;
  *(undefined4 *)(instructionWords + 8) = 0;
  return;
}

/* opcodeInfoIsVsFlagBit2 @ 0x19a538 (48 bytes) */
int opcodeInfoIsVsFlagBit2(unusedThis, irInst)
  undefined4 unusedThis;
  int irInst;
{
  return *(uint *)(PTR_DAT_001e9140 + *(int *)(*(int *)(irInst + 0x88) + 8) * 0x38) >> 2 & 1;
}

/* R300VMachineAssembler__transitionState @ 0x19a568 (176 bytes) */
int R300VMachineAssembler__transitionState(this, event)
  int this;
  int event;
{
  int loopIndex;
  int loopRemaining;
  
  loopRemaining = (event * 5 + *(int *)(this + 0x1c)) * 4;
  loopIndex = *(int *)(&DAT_001e6668 + loopRemaining);
  loopRemaining = *(int *)(&DAT_001e66cc + loopRemaining);
  *(int *)(this + 0x1c) = loopIndex;
  if (loopIndex == -1) {
    *(undefined4 *)(this + 0x1c) = 2;
  }
  else if (loopRemaining < 1) {
    if (loopRemaining < 0) {
      loopRemaining = -loopRemaining;
      loopIndex = *(int *)(this + 0x58);
      do {
        loopIndex = loopIndex + -1;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
      *(int *)(this + 0x58) = loopIndex;
    }
  }
  else {
    loopIndex = 0;
    do {
      loopIndex = loopIndex + 1;
      ((int (*)())R300VMachineAssembler__nextInstruction)(this);
    } while (loopIndex != loopRemaining);
  }
  return;
}

/* R300VMachineAssembler__vslot2_exceedsLimits @ 0x19a618 (120 bytes) */
int R300VMachineAssembler__vslot2_exceedsLimits(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  
  Compiler__logf(*(int *)(param_1 + 0xc),"next_sp = %d, max = %d\n",*(undefined4 *)(param_1 + 0x58),
               *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30c) + 0x40),param_5,param_6,
               param_7,param_8);
  if ((*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30c) + 0x40) < *(int *)(param_1 + 0x58)) ||
     (uVar1 = 0, 0x10 < *(int *)(param_1 + 0x5c))) {
    uVar1 = 1;
  }
  return uVar1;
}

/* R300VMachineAssembler__vslot49_advanceInstruction @ 0x19a690 (16 bytes) */
int R300VMachineAssembler__vslot49_advanceInstruction(this)
  int this;
{
  *(int *)(this + 0x58) = *(int *)(this + 0x58) + 1;
  return;
}

/* R300VMachineAssembler__vslot48_declareAndAssemble @ 0x19a6a0 (80 bytes) */
int R300VMachineAssembler__vslot48_declareAndAssemble(this, node)
  int *this;
  undefined4 node;
{
  ConstRecord__emitStores(node,this,this[3]);
                    
                    
  (**(code **)(*this + 0x88))(this,node);
  return;
}

/* vsSourceSelectForConstant @ 0x19a6f0 (192 bytes) */
int vsSourceSelectForConstant(sourceBlock, sourceNumber, negateOut)
  int sourceBlock;
  int sourceNumber;
  undefined4 *negateOut;
{
  float literalValue;
  
  *negateOut = 0;
  if (3 < sourceNumber) {
    if (sourceNumber < 6) {
      return 4;
    }
    if (sourceNumber == 6) {
      return 5;
    }
  }
  literalValue = *(float *)(sourceNumber * 0x18 + sourceBlock + 0x20);
  if (literalValue == FLOAT_001aa0e8) {
    return 5;
  }
  if ((literalValue != FLOAT_001aa0d4) && (literalValue == FLOAT_001aa114)) {
    *negateOut = 1;
    return 5;
  }
  return 4;
}

/* copyLaneWord @ 0x19a7b0 (92 bytes) */
int copyLaneWord(laneBlock, sourceLane, destLane)
  int laneBlock;
  int sourceLane;
  int destLane;
{
  undefined4 *destPtr;
  undefined4 *sourcePtr;
  
  sourcePtr = (undefined4 *)(laneBlock + 8);
  if (((sourceLane != 2) && (sourcePtr = (undefined4 *)(laneBlock + 0xc), sourceLane != 3)) &&
     (sourcePtr = (undefined4 *)0x0, sourceLane == 1)) {
    sourcePtr = (undefined4 *)(laneBlock + 4);
  }
  destPtr = (undefined4 *)(laneBlock + 8);
  if (((destLane != 2) && (destPtr = (undefined4 *)(laneBlock + 0xc), destLane != 3)) &&
     (destPtr = (undefined4 *)0x0, destLane == 1)) {
    destPtr = (undefined4 *)(laneBlock + 4);
  }
  *destPtr = *sourcePtr;
  return;
}

/* R300VMachineAssembler__vslot15_assembleUnlessConstantMove @ 0x19a80c (156 bytes) */
int R300VMachineAssembler__vslot15_assembleUnlessConstantMove(this, inst, extra1, compiler)
  int *this;
  int inst;
  undefined4 extra1;
  undefined4 compiler;
{
  int *a0;
  int callResult;
  
  a0 = (int *)IRInst__getOperandSource(inst,1);
  callResult = (**(code **)(*a0 + 0x50))(a0);
  if ((callResult != 0) && (*(int *)(inst + 0x144) != 0)) {
    return;
  }
                    
                    
  (**(code **)(*this + 0x38))(this,inst,extra1,compiler);
  return;
}

/* R300VMachineAssembler__vslot16_noOp @ 0x19a8a8 (4 bytes) */
int R300VMachineAssembler__vslot16_noOp()
{
  return;
}

/* R300VMachineAssembler__vslot18_callSlot14 @ 0x19a8ac (16 bytes) */
int R300VMachineAssembler__vslot18_callSlot14(this)
  int *this;
{
                    
                    
  (**(code **)(*this + 0x38))();
  return;
}

/* R300VMachineAssembler__vslot19_callSlot14 @ 0x19a8bc (16 bytes) */
int R300VMachineAssembler__vslot19_callSlot14(this)
  int *this;
{
                    
                    
  (**(code **)(*this + 0x38))();
  return;
}

/* R300VMachineAssembler__vslot43_beginLoop @ 0x19a8d4 (128 bytes) */
int R300VMachineAssembler__vslot43_beginLoop(this, node)
  int this;
  int node;
{
  int loopId;
  
  if ((1 < *(int *)(node + 0x130)) && (*(int *)(this + 0x5c) != 0x10)) {
    loopId = *(int *)(node + 300);
    *(int *)(this + 0x70) = loopId;
    *(undefined4 *)(loopId * 0xc + *(int *)(this + 0x60)) = *(undefined4 *)(this + 0x58);
    *(undefined4 *)(*(int *)(this + 0x70) * 0xc + *(int *)(this + 0x60) + 8) =
         *(undefined4 *)(this + 0x1c);
    ((int (*)())R300VMachineAssembler__transitionState)(this,3);
    *(undefined4 *)(this + 100) = 1;
  }
  return;
}

/* R300VMachineAssembler__vslot44_endLoopBody @ 0x19a954 (92 bytes) */
int R300VMachineAssembler__vslot44_endLoopBody(this)
  int this;
{
  if (*(int *)(this + 100) != 0) {
    ((int (*)())R300VMachineAssembler__transitionState)(this,3);
    *(undefined4 *)(*(int *)(this + 0x70) * 0xc + *(int *)(this + 0x60) + 4) =
         *(undefined4 *)(this + 0x58);
    *(undefined4 *)(this + 100) = 1;
  }
  return;
}

/* R300VMachineAssembler__appendControlFlowEntry @ 0x19a9b0 (44 bytes) */
int R300VMachineAssembler__appendControlFlowEntry(this, fieldA, fieldB)
  int this;
  undefined4 fieldA;
  undefined4 fieldB;
{
  int entry;
  undefined4 instructionCount;
  
  instructionCount = *(undefined4 *)(this + 0x58);
  entry = *(int *)(this + 0x5c) * 0x1c + *(int *)(this + 0x40);
  *(int *)(this + 0x5c) = *(int *)(this + 0x5c) + 1;
  *(undefined4 *)(entry + 0x18) = fieldB;
  *(undefined4 *)(entry + 0x10) = instructionCount;
  *(undefined4 *)(entry + 0x14) = fieldA;
  return;
}

/* R300VMachineAssembler__vslot45_endLoop @ 0x19a9dc (160 bytes) */
int R300VMachineAssembler__vslot45_endLoop(this, node)
  int this;
  int node;
{
  int loopId;
  
  if ((1 < *(int *)(node + 0x130)) && (*(int *)(this + 0x5c) != 0x10)) {
    *(undefined4 *)(this + 0x68) = *(undefined4 *)(this + 0x58);
    *(undefined4 *)(this + 0x6c) = *(undefined4 *)(this + 0x1c);
    loopId = *(int *)(node + 300);
    *(int *)(this + 0x70) = loopId;
    *(undefined4 *)(this + 0x58) = *(undefined4 *)(loopId * 0xc + *(int *)(this + 0x60));
    ((int (*)())R300VMachineAssembler__transitionState)(this,4);
    loopId = *(int *)(this + 0x70) * 0xc;
    ((int (*)())R300VMachineAssembler__appendControlFlowEntry)(this,*(undefined4 *)(loopId + *(int *)(this + 0x60)),
                 *(undefined4 *)(loopId + *(int *)(this + 0x60) + 4));
    *(undefined4 *)(this + 100) = 1;
  }
  return;
}

/* R300VMachineAssembler__vslot46_leaveLoop @ 0x19aa7c (92 bytes) */
int R300VMachineAssembler__vslot46_leaveLoop(this)
  int this;
{
  if (*(int *)(this + 100) != 0) {
    ((int (*)())R300VMachineAssembler__transitionState)(this,3);
    *(undefined4 *)(this + 0x70) = 0xffffffff;
    *(undefined4 *)(this + 0x58) = *(undefined4 *)(this + 0x68);
    *(undefined4 *)(this + 0x1c) = *(undefined4 *)(this + 0x6c);
    *(undefined4 *)(this + 100) = 0;
  }
  return;
}

/* R300VMachineAssembler__vslot27_assembleOrFail @ 0x19aaf4 (100 bytes) */
int R300VMachineAssembler__vslot27_assembleOrFail(this, node, extra1, extra2, extra3, compiler)
  undefined4 this;
  int *node;
  undefined4 extra1;
  undefined4 extra2;
  undefined4 extra3;
  undefined4 compiler;
{
  int callResult;
  
  callResult = (**(code **)(*node + 0x40))(node,node,extra1,extra2,extra3,compiler);
  if (callResult == 0) {
    Compiler__fail(compiler,0xf);
    return;
  }
  return;
}

/* R300VMachineAssembler__vslot25_assembleOrFail @ 0x19ab60 (100 bytes) */
int R300VMachineAssembler__vslot25_assembleOrFail(this, node, extra1, compiler)
  undefined4 this;
  int *node;
  undefined4 extra1;
  undefined4 compiler;
{
  int callResult;
  
  callResult = (**(code **)(*node + 0x40))(node,node,extra1,compiler);
  if (callResult == 0) {
    Compiler__fail(compiler,0xf);
    return;
  }
  return;
}

/* R300VMachineAssembler__vslot28_assembleChildOrFail @ 0x19abc4 (100 bytes) */
int R300VMachineAssembler__vslot28_assembleChildOrFail(this, node, extra1, compiler)
  undefined4 this;
  int node;
  undefined4 extra1;
  undefined4 compiler;
{
  int callResult;
  
  callResult = (**(code **)(**(int **)(node + 300) + 0x40))
                    (*(int **)(node + 300),node,extra1,compiler);
  if (callResult == 0) {
    Compiler__fail(compiler,0xf);
    return;
  }
  return;
}

/* R300VMachineAssembler__vslot38_appendCallEntry @ 0x19ac2c (120 bytes) */
int R300VMachineAssembler__vslot38_appendCallEntry(this, entryField0, entryField3)
  int this;
  undefined4 entryField0;
  undefined4 entryField3;
{
  int entry;
  int entryByteOffset;
  
  ((int (*)())R300VMachineAssembler__transitionState)(this,4);
  entryByteOffset = *(int *)(this + 0x5c) * 0x1c;
  *(int *)(this + 0x5c) = *(int *)(this + 0x5c) + 1;
  entry = entryByteOffset + *(int *)(this + 0x40);
  *(undefined4 *)(entryByteOffset + *(int *)(this + 0x40)) = entryField0;
  *(undefined4 *)(entry + 8) = 0x35;
  *(undefined4 *)(entry + 0xc) = entryField3;
  entryByteOffset = *(int *)(this + 0x58);
  *(undefined4 *)(entry + 0x18) = 0;
  *(undefined4 *)(entry + 0x14) = 0;
  *(int *)(entry + 0x10) = entryByteOffset + -2;
  return;
}

/* R300VMachineAssembler__vslot42_noOp @ 0x19aca4 (4 bytes) */
int R300VMachineAssembler__vslot42_noOp()
{
  return;
}

/* R300VMachineAssembler__init @ 0x19acb0 (328 bytes) */
int R300VMachineAssembler__init(this, program, allocatorArg, compiler)
  int this;
  undefined4 program;
  undefined4 allocatorArg;
  int compiler;
{
  undefined4 allocation;
  int programInstructionLimit;
  undefined4 uVar2;
  int maxInstructions;
  
  *(int *)(this + 0xc) = compiler;
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(compiler + COMP_target);
  maxInstructions = *(int *)(compiler + COMP_nextInstId) << 4;
  programInstructionLimit = *(int *)(*(int *)(compiler + COMP_target) + 0x40) << 4;
  if (maxInstructions < programInstructionLimit) {
    maxInstructions = programInstructionLimit;
  }
  allocation = Arena__alloc(*(undefined4 *)(compiler + COMP_arenaA),maxInstructions);
  *(undefined4 *)(this + 0x44) = allocation;
  allocation = Arena__alloc(*(undefined4 *)(compiler + COMP_arenaA),*(int *)(compiler + COMP_nextInstId) * 0x38);
  *(undefined4 *)(this + 0x40) = allocation;
  allocation = Arena__alloc(*(undefined4 *)(compiler + COMP_arenaA),900);
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x54) = allocation;
  allocation = Arena__alloc(*(undefined4 *)(compiler + COMP_arenaA),*(int *)(compiler + COMP_nextInstId) << 3);
  *(undefined4 *)(this + 8) = allocation;
  uVar2 = FUN_000e14e4(compiler,0x28,allocatorArg);
  *(undefined4 *)(this + 0x50) = uVar2;
  _memset(uVar2,0,0x28);
  **(int **)(this + 0x50) = maxInstructions;
  *(undefined4 *)(*(int *)(this + 0x50) + 4) = *(undefined4 *)(this + 0x44);
  *(undefined4 *)(*(int *)(this + 0x50) + 8) = *(undefined4 *)(this + 0x54);
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x10) = program;
  *(undefined4 *)(this + 0x70) = 0xffffffff;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  return;
}

/* R300VMachineAssembler__vslot6_setLoopStack @ 0x19adf8 (136 bytes) */
int R300VMachineAssembler__vslot6_setLoopStack(this, enable)
  int this;
  int enable;
{
  int loopStackLevels;
  int compilerPtr;
  undefined4 loopStack;
  
  if (enable == 0) {
    *(undefined4 *)(*(int *)(this + 0xc) + 0x3d4) = 0;
  }
  else {
    compilerPtr = *(int *)(this + 0xc);
    if (*(int *)(compilerPtr + 0x3d4) == 0) {
      *(undefined4 *)(compilerPtr + 0x3d4) = 1;
      compilerPtr = *(int *)(this + 0xc);
    }
    loopStackLevels = *(int *)(compilerPtr + 0x3d4);
    Arena__free(*(undefined4 *)(compilerPtr + 0x374),*(undefined4 *)(this + 0x60));
    loopStack = Arena__alloc(*(undefined4 *)(*(int *)(this + 0xc) + 0x374),loopStackLevels * 0xc);
    *(undefined4 *)(this + 0x60) = loopStack;
  }
  return;
}

/* R300VMachineAssembler__vslot24_assembleWithTarget @ 0x19ae80 (104 bytes) */
int R300VMachineAssembler__vslot24_assembleWithTarget(this, node, block)
  int *this;
  int node;
  undefined4 block;
{
  undefined4 nodeHandle;
  code *UNRECOVERED_JUMPTABLE;
  
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*this + 0x9c);
  nodeHandle = FUN_000e7d5c(node);
                    
                    
  (*UNRECOVERED_JUMPTABLE)(this,nodeHandle,*(undefined4 *)(node + 0x134));
  return;
}

/* R300VMachineAssembler__vslot30_assembleBlockThenSlot40 @ 0x19aee8 (88 bytes) */
int R300VMachineAssembler__vslot30_assembleBlockThenSlot40(this, node, block)
  int *this;
  int node;
  undefined4 block;
{
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
                    
                    
  (**(code **)(*this + 0xa0))(this,0);
  return;
}

/* R300VMachineAssembler__vslot37_patchControlFlowTarget @ 0x19af40 (252 bytes) */
int R300VMachineAssembler__vslot37_patchControlFlowTarget(this, node)
  int this;
  int *node;
{
  uint cfTopIndex;
  int *lastEntryPtr;
  uint cfStackCount;
  int callResult;
  int conditionRegister;
  
  conditionRegister = node[0x4e];
  callResult = DList__count(conditionRegister + 0x90);
  if ((callResult < 3) && (callResult = Block__hasSuccessors(conditionRegister), callResult != 0)) {
    lastEntryPtr = (int *)0x0;
    if (*(int *)(*(int *)(conditionRegister + 0xd0) + 4) != 0) {
      lastEntryPtr = *(int **)(*(int *)(conditionRegister + 0xd0) + 8);
    }
    if (*lastEntryPtr == node[0x4f]) {
      return;
    }
  }
  callResult = (**(code **)(*node + 0x40))(node);
  if (callResult != 0) {
    lastEntryPtr = (int *)0x0;
    callResult = *(int *)(*(int *)(this + 0x10) + 0x24);
    cfStackCount = *(uint *)(callResult + 4);
    cfTopIndex = cfStackCount - 1;
    if (cfTopIndex < cfStackCount) {
      lastEntryPtr = (int *)(cfTopIndex * 4 + *(int *)(callResult + 8));
    }
    callResult = *lastEntryPtr;
    ((int (*)())R300VMachineAssembler__transitionState)(this,4);
    *(int *)(callResult + 0x14) = *(int *)(this + 0x58) + -2;
    return;
  }
  Compiler__fail(*(undefined4 *)(this + 0xc),0xf);
  return;
}

/* R300VMachineAssembler__findFoldableMovePair @ 0x19b03c (908 bytes) */
int R300VMachineAssembler__findFoldableMovePair(this, block, groupHead, foldNotNeededOut)
  int this;
  undefined4 block;
  int *groupHead;
  undefined4 *foldNotNeededOut;
{
  int *movInst;
  int *insertAfterInst;
  int *hwLimitsObj;
  int srcIdx2;
  int mathSrcOffset5;
  int vectorRegClass5;
  int srcIdx;
  int src1RegId;
  int blockRef;
  int numSources;
  int destOffset;
  int mathSrcOffset;
  undefined4 sourceDef2;
  int operandRecord;
  int sourceDef;
  bool noMathHazard;
  bool groupContinues;
  int isMathEngine;
  int *resultInst;
  int regBias;
  int numSourcesLoopBound;
  undefined4 tempRegId;
  int *vectorInst;
  int *mathInst;
  int *groupCursor;
  uint instFlags;
  int vectorRegClass;
  undefined4 allocTable;
  
  *foldNotNeededOut = 0;
  resultInst = (int *)0x0;
  if (groupHead != (int *)0x0) {
    vectorInst = (int *)0x0;
    mathInst = (int *)0x0;
    groupContinues = false;
    noMathHazard = true;
    groupCursor = groupHead;
    do {
      instFlags = groupCursor[5];
      if ((instFlags & 1) != 0) {
        if ((instFlags & 4) != 0) {
          groupContinues = true;
        }
        isMathEngine = ((int (*)())opcodeInfoIsVsFlagBit2)(*(undefined4 *)(this + 0x88),groupCursor);
        if (isMathEngine == 0) {
          if ((instFlags & 0x10000) == 0) {
            vectorInst = groupCursor;
          }
        }
        else {
          mathInst = groupCursor;
          if (groupCursor[0x26] == 1) {
            destOffset = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),groupCursor);
            hwLimitsObj = *(int **)(*(int *)(this + 0xc) + 0x30c);
            regBias = (**(code **)(*hwLimitsObj + 0x138))(hwLimitsObj,0);
            if ((uint)(destOffset - regBias) < 4) {
              numSources = (**(code **)(*groupCursor + 0x14))(groupCursor);
              if (1 < numSources) {
                sourceDef = IRInst__getOperandSource(groupCursor,1);
                src1RegId = *(int *)(sourceDef + 0x94);
                sourceDef = IRInst__getOperandSource(groupCursor,2);
                if (src1RegId != *(int *)(sourceDef + 0x94)) goto LAB_0019b168;
              }
              instFlags = groupCursor[5];
              goto LAB_0019b144;
            }
LAB_0019b168:
            instFlags = groupCursor[5];
          }
          noMathHazard = false;
        }
      }
LAB_0019b144:
      groupCursor = (int *)groupCursor[2];
    } while ((groupCursor != (int *)0x0) && ((instFlags & 4) != 0));
    resultInst = groupHead;
    if ((vectorInst != (int *)0x0) && (mathInst != (int *)0x0)) {
      if (noMathHazard) {
        *foldNotNeededOut = 1;
      }
      else if (groupContinues) {
        *(int *)(*(int *)(this + 0x10) + 0x14) = *(int *)(*(int *)(this + 0x10) + 0x14) + 1;
        insertAfterInst = (int *)groupCursor[1];
        blockRef = groupHead[0x56];
        if (insertAfterInst == mathInst) {
          *(uint *)(mathInst[1] + 0x14) = *(uint *)(mathInst[1] + 0x14) & 0xfffffffb;
        }
        else {
          mathInst[5] = mathInst[5] & 0xfffffffb;
          DList__unlink(mathInst);
          Block__insertInstAfter(blockRef,insertAfterInst,mathInst);
        }
        for (srcIdx = 1; numSourcesLoopBound = (**(code **)(*mathInst + 0x14))(mathInst), resultInst = vectorInst,
            srcIdx <= numSourcesLoopBound; srcIdx = srcIdx + 1) {
          vectorRegClass = vectorInst[0x26];
          numSourcesLoopBound = IRInst__getOperandSource(mathInst,srcIdx);
          if (vectorRegClass == *(int *)(numSourcesLoopBound + 0x98)) {
            numSourcesLoopBound = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),vectorInst);
            allocTable = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
            sourceDef2 = IRInst__getOperandSource(mathInst,srcIdx);
            mathSrcOffset = thunk_FUN_00134de8(allocTable,sourceDef2);
            if (numSourcesLoopBound == mathSrcOffset) {
              srcIdx2 = 1;
              movInst = (int *)IRInst__create(0x31,*(undefined4 *)(this + 0xc));
              tempRegId = RegAlloc__allocateFirstFreeInClass(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),0);
              operandRecord = IRInst__getOperandRecord(movInst,0);
              *(undefined4 *)(operandRecord + 0xc) = 0;
              *(undefined4 *)(operandRecord + 8) = tempRegId;
              IRInst__setOperandSource(movInst,1,vectorInst,0,*(undefined4 *)(this + 0xc));
              Block__insertInstBefore(blockRef,vectorInst,movInst);
              *(int *)(*(int *)(this + 0x10) + 0x18) =
                   *(int *)(*(int *)(this + 0x10) + 0x18) + 1;
              if (movInst == (int *)0x0) {
                return vectorInst;
              }
              for (; blockRef = (**(code **)(*mathInst + 0x14))(mathInst), srcIdx2 <= blockRef;
                  srcIdx2 = srcIdx2 + 1) {
                vectorRegClass5 = vectorInst[0x26];
                blockRef = IRInst__getOperandSource(mathInst,srcIdx2);
                if (vectorRegClass5 == *(int *)(blockRef + 0x98)) {
                  blockRef = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),vectorInst
                                            );
                  allocTable = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
                  sourceDef2 = IRInst__getOperandSource(mathInst,srcIdx2);
                  mathSrcOffset5 = thunk_FUN_00134de8(allocTable,sourceDef2);
                  if (blockRef == mathSrcOffset5) {
                    IRInst__setOperandSource(mathInst,srcIdx2,movInst,0,*(undefined4 *)(this + 0xc));
                  }
                }
              }
              return movInst;
            }
          }
        }
      }
    }
  }
  return resultInst;
}

/* R300VMachineAssembler__assembleBlock @ 0x19b3c8 (728 bytes) */
int R300VMachineAssembler__assembleBlock(this, block)
  int *this;
  int block;
{
  int *operandVReg;
  uint *flagsPtr;
  uint instFlags;
  int iVar3;
  int *groupInst;
  int *piVar5;
  int *cursorInst;
  int lookahead [9];
  
  piVar5 = *(int **)(block + 8);
  if (piVar5[2] == 0) {
    return;
  }
  do {
    iVar3 = (**(code **)(*this + 8))(this);
    if (iVar3 != 0) {
      Compiler__fail(this[3],5);
    }
    iVar3 = this[3];
    if (**(int **)(iVar3 + 0x6c4) == 0) {
      groupInst = (int *)FUN_000e3b88(this[4],block,piVar5,lookahead);
      if ((groupInst == (int *)0x0) || (lookahead[0] == 0)) {
        iVar3 = this[3];
      }
      else {
        iVar3 = this[3];
        piVar5 = groupInst;
      }
    }
    groupInst = piVar5;
    if (**(int **)(iVar3 + 0x6c4) == 0) {
      groupInst = (int *)((int (*)())R300VMachineAssembler__findFoldableMovePair)(this,block,piVar5,this + 0x1f);
      iVar3 = this[3];
    }
    iVar3 = IRInst__isCoalescableMov(groupInst,*(undefined4 *)(iVar3 + 0x6c4));
    if ((((iVar3 == 0) || (instFlags = groupInst[5], (instFlags & 4) != 0)) || ((int)instFlags < 0)) ||
       ((instFlags & 0x1000) != 0)) {
      (**(code **)(*this + 0xbc))(this);
      cursorInst = groupInst;
      piVar5 = groupInst;
      do {
        if (piVar5 == (int *)0x0) break;
        instFlags = cursorInst[5];
        if ((instFlags & 1) != 0) {
          if ((instFlags & 0x10000) == 0) {
            iVar3 = (**(code **)(*cursorInst + 0x68))(cursorInst);
            if (iVar3 != 0) {
              operandVReg = (int *)IRInst__getOperandSource(cursorInst,1);
              iVar3 = (**(code **)(*operandVReg + 0x50))(operandVReg);
              if ((iVar3 != 0) && (cursorInst[0x51] != 0)) {
                return;
              }
            }
            ((int (*)())R300VMachineAssembler__transitionState)(this,2);
            (**(code **)(*cursorInst + 0x1c))(cursorInst,this,0,this[3]);
          }
          else {
            iVar3 = (**(code **)(*cursorInst + 0x48))(cursorInst);
            if (iVar3 != 0) {
              (**(code **)(*this + 0xc0))(this,cursorInst,this[3]);
            }
          }
          (**(code **)(*cursorInst + 0x20))(cursorInst,this,0,this[3]);
          instFlags = cursorInst[5];
        }
        cursorInst = (int *)cursorInst[2];
        piVar5 = (int *)(instFlags & 4);
      } while (cursorInst != (int *)0x0);
      iVar3 = (**(code **)(*groupInst + 0x24))(groupInst);
      if (iVar3 == 0) {
        cursorInst = (int *)groupInst[2];
      }
      else {
        (**(code **)(*this + 0xc4))(this);
        cursorInst = (int *)groupInst[2];
      }
    }
    else {
      *(int *)(this[4] + 0xc) = *(int *)(this[4] + 0xc) + 1;
      cursorInst = (int *)groupInst[2];
    }
    do {
      piVar5 = cursorInst;
      flagsPtr = (uint *)(groupInst + 5);
      if ((int *)piVar5[2] == (int *)0x0) {
        return;
      }
      cursorInst = (int *)piVar5[2];
      groupInst = piVar5;
    } while ((*flagsPtr & 4) != 0);
  } while( true );
}

/* R300VMachineAssembler__vslot40_endControlFlowBlock @ 0x19b6a0 (168 bytes) */
int R300VMachineAssembler__vslot40_endControlFlowBlock(this)
  int this;
{
  uint entryStart;
  int openStack;
  uint openCount;
  int *topSlot;
  int cfEntry;
  
  ((int (*)())R300VMachineAssembler__transitionState)(this,3);
  topSlot = (int *)0x0;
  openStack = *(int *)(*(int *)(this + 0x10) + 0x28);
  openCount = *(uint *)(openStack + 4);
  if (openCount - 1 < openCount) {
    topSlot = (int *)((openCount - 1) * 4 + *(int *)(openStack + 8));
  }
  cfEntry = *topSlot;
  Vector__removeAt(openStack,openCount - 1);
  entryStart = *(uint *)(cfEntry + 0x10);
  *(int *)(cfEntry + 0x18) = *(int *)(this + 0x58) + -2;
  if (entryStart < *(uint *)(this + 0x2c)) {
    *(int *)(this + 0x2c) = *(int *)(this + 0x58) + -1;
    entryStart = *(uint *)(cfEntry + 0x10);
  }
  if (entryStart < *(uint *)(this + 0x30)) {
    *(int *)(this + 0x30) = *(int *)(this + 0x58) + -1;
  }
  return;
}

/* R300VMachineAssembler__vslot39_appendBranchEntry @ 0x19b748 (192 bytes) */
int R300VMachineAssembler__vslot39_appendBranchEntry(this, entryField3, entryField1)
  int this;
  undefined4 entryField3;
  undefined4 entryField1;
{
  int entryIndex;
  int *pushedSlot;
  uint pushIndex;
  uint *openStack;
  int entry;
  
  ((int (*)())R300VMachineAssembler__transitionState)(this,4);
  entryIndex = *(int *)(this + 0x5c);
  *(int *)(this + 0x5c) = entryIndex + 1;
  entry = entryIndex * 0x1c + *(int *)(this + 0x40);
  *(undefined4 *)(entry + 8) = 0x3e;
  entryIndex = *(int *)(this + 0x58);
  *(undefined4 *)(entry + 0xc) = entryField3;
  *(undefined4 *)(entry + 4) = entryField1;
  *(int *)(entry + 0x10) = entryIndex + -2;
  openStack = *(uint **)(*(int *)(this + 0x10) + 0x28);
  pushIndex = openStack[1];
  if (pushIndex < *openStack) {
    _memset(pushIndex * 4 + openStack[2],0,4);
    pushedSlot = (int *)(pushIndex * 4 + openStack[2]);
    openStack[1] = pushIndex + 1;
  }
  else {
    pushedSlot = (int *)Vector__elementRefGrow(openStack,pushIndex);
  }
  *pushedSlot = entry;
  return;
}

/* R300VMachineAssembler__vslot29_endIfBlock @ 0x19b808 (180 bytes) */
int R300VMachineAssembler__vslot29_endIfBlock(this)
  int this;
{
  uint entryStart;
  int openStack;
  uint openCount;
  int *topSlot;
  int cfEntry;
  
  topSlot = (int *)0x0;
  openStack = *(int *)(*(int *)(this + 0x10) + 0x24);
  openCount = *(uint *)(openStack + 4);
  if (openCount - 1 < openCount) {
    topSlot = (int *)((openCount - 1) * 4 + *(int *)(openStack + 8));
  }
  cfEntry = *topSlot;
  Vector__removeAt(openStack,openCount - 1);
  *(undefined4 *)(cfEntry + 0x18) = *(undefined4 *)(this + 0x58);
  if (*(int *)(cfEntry + 0x14) == 0) {
    entryStart = *(uint *)(cfEntry + 0x10);
    *(uint *)(cfEntry + 0x14) = entryStart;
  }
  else {
    entryStart = *(uint *)(cfEntry + 0x10);
  }
  if (entryStart < *(uint *)(this + 0x2c)) {
    *(undefined4 *)(this + 0x2c) = *(undefined4 *)(this + 0x58);
    entryStart = *(uint *)(cfEntry + 0x10);
  }
  if (entryStart < *(uint *)(this + 0x30)) {
    *(undefined4 *)(this + 0x30) = *(undefined4 *)(this + 0x58);
  }
  return ((int (*)())R300VMachineAssembler__transitionState)(this,3);
}

/* R300VMachineAssembler__create @ 0x19b8bc (96 bytes) */
int R300VMachineAssembler__create(unusedThis, compiler)
  undefined4 unusedThis;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaB);
  allocation = (undefined4 *)Arena__alloc(arena,0x90);
  *allocation = arena;
  allocation[1] = &PTR_FUN_001eb808;
  allocation[7] = 0;
  return allocation + 1;
}

/* MachineAssembler__dtor_19b91c @ 0x19b91c (124 bytes) */
int MachineAssembler__dtor_19b91c(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001eb808;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[2]);
  this[2] = 0;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[0x18]);
  this[0x11] = 0;
  *this = PTR_DAT_001e914c + 8;
  return;
}

/* MachineAssembler__dtor_19b9ac @ 0x19b9ac (124 bytes) */
int MachineAssembler__dtor_19b9ac(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001eb808;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[2]);
  this[2] = 0;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[0x18]);
  this[0x11] = 0;
  *this = PTR_DAT_001e914c + 8;
  return;
}

/* R300VMachineAssembler__deleting_dtor @ 0x19ba3c (136 bytes) */
int R300VMachineAssembler__deleting_dtor(this)
  undefined4 *this;
{
  undefined *baseVtable;
  undefined4 *blockStart;
  int arenaHeader;
  
  *this = &PTR_FUN_001eb808;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[2]);
  this[2] = 0;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[0x18]);
  baseVtable = PTR_DAT_001e914c;
  this[0x11] = 0;
  *this = baseVtable + 8;
  if (this == (undefined4 *)0x0) {
    return;
  }
  arenaHeader = this[-1];
  if ((*(int *)(arenaHeader + 0x28) != 0) &&
     (blockStart = *(undefined4 **)(arenaHeader + 0x14), blockStart == this + -1)) {
    _memset(blockStart,0,*(int *)(arenaHeader + 8) - (int)blockStart);
    *(undefined4 *)(arenaHeader + 8) = *(undefined4 *)(arenaHeader + 0x14);
  }
  return;
}

/* R300VMachineAssembler__encodeDestinationWord @ 0x19baf4 (1596 bytes) */
int R300VMachineAssembler__encodeDestinationWord(this, inst, instructionWords)
  int this;
  int *inst;
  uint *instructionWords;
{
  uint destOffset;
  uint word0New;
  uint destSelectWord;
  uint word0;
  uint word1Old2;
  int src3RegClass;
  int src3Def;
  undefined4 newMax;
  int destRecord;
  int hwBase;
  int destRegIndex;
  int destAddrMode;
  int destRegType;
  int flagBit2;
  int src1Reg;
  int isMix1;
  int numSources;
  int destRegType2;
  int hwOpcode;
  int *operandVReg;
  bool isMathInst;
  int opcode;
  undefined1 opcodeByte;
  int *hwLimits;
  int opcodeTable;
  undefined4 srcDefTemp;
  int src1RegClass;
  int callResult;
  int src2RegClass;
  int isMix3;
  int src3RegOffset;
  uint word1Old;
  uint swizzleSelFromWord1;
  uint swizzleSelFromWord2;
  uint word3Old;
  undefined4 allocTable;
  
  hwLimits = *(int **)(*(int *)(this + 0xc) + 0x30c);
  opcodeTable = (**(code **)(*hwLimits + 0x16c))(hwLimits,inst,instructionWords);
  opcode = *(int *)(inst[0x22] + 8);
  hwOpcode = *(int *)(opcode * 0x38 + opcodeTable + 0xc);
  if (opcode == 0x32) {
    word3Old = instructionWords[3];
    isMathInst = true;
    word1Old = instructionWords[1];
    swizzleSelFromWord2 = instructionWords[2] >> 0x10 & 7;
    swizzleSelFromWord1 = word1Old >> 0xd & 7;
    instructionWords[1] = swizzleSelFromWord2 << 0x16 |
                 swizzleSelFromWord2 << 0x13 | swizzleSelFromWord2 << 0x10 | swizzleSelFromWord2 << 0xd | instructionWords[2] & 0xfe001fff;
    *(byte *)((int)instructionWords + 3) = (byte)hwOpcode | 0x40;
    instructionWords[2] = swizzleSelFromWord1 << 0x16 | swizzleSelFromWord1 << 0x13 | swizzleSelFromWord1 << 0x10 | word1Old & 0xfe00ffff;
    instructionWords[3] = (word3Old & 0xfff81fff) >> 3 & 0x380000 |
                 (word3Old & 0xffff1fff) >> 6 & 0x70000 | word3Old >> 9 & 0xe000 | word3Old & 0xffc01fff;
  }
  else if (hwOpcode == -1) {
    if (opcode < 0x32) {
      if (opcode < 0x30) {
        if (opcode == 0x1c) {
          isMathInst = true;
          *(undefined1 *)((int)instructionWords + 3) = 1;
          instructionWords[1] = instructionWords[1] & 0xfe3fffff | 0x1000000;
          instructionWords[2] = instructionWords[2] & 0xfe3fffff | 0x1000000;
        }
        else {
          if (opcode != 0x28) goto LAB_0019bc7c;
          word1Old2 = instructionWords[1];
          isMathInst = true;
          *(undefined1 *)((int)instructionWords + 3) = 10;
          instructionWords[1] = instructionWords[2];
          instructionWords[2] = word1Old2;
        }
      }
      else {
LAB_0019bbfc:
        isMathInst = false;
        *(undefined1 *)((int)instructionWords + 3) = 7;
        instructionWords[2] = instructionWords[1];
      }
    }
    else {
      if (opcode == 0x66) goto LAB_0019bbfc;
      if (opcode != 0xa5) goto LAB_0019bc7c;
      isMathInst = true;
      *(undefined1 *)((int)instructionWords + 3) = 5;
      instructionWords[3] = instructionWords[2];
    }
  }
  else {
    *(byte *)((int)instructionWords + 3) = (byte)hwOpcode;
LAB_0019bc7c:
    isMathInst = true;
  }
  numSources = (**(code **)(*inst + 0x14))(inst);
  if (numSources != 3) goto LAB_0019bee4;
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  isMix1 = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (isMix1 == 0) {
    allocTable = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
    srcDefTemp = IRInst__getOperandSource(inst,1);
    src1Reg = thunk_FUN_00134de8(allocTable,srcDefTemp);
    src1RegClass = IRInst__getOperandSource(inst,1);
    src1RegClass = *(int *)(src1RegClass + 0x98);
  }
  else {
    allocTable = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
    srcDefTemp = IRInst__getOperandSource(inst,1);
    srcDefTemp = IRInst__getOperandSource(srcDefTemp,1);
    src1Reg = thunk_FUN_00134de8(allocTable,srcDefTemp);
    srcDefTemp = IRInst__getOperandSource(inst,1);
    src1RegClass = IRInst__getOperandSource(srcDefTemp,1);
    src1RegClass = *(int *)(src1RegClass + 0x98);
  }
  operandVReg = (int *)IRInst__getOperandSource(inst,2);
  callResult = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (callResult == 0) {
    allocTable = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
    srcDefTemp = IRInst__getOperandSource(inst,2);
    callResult = thunk_FUN_00134de8(allocTable,srcDefTemp);
    src2RegClass = IRInst__getOperandSource(inst,2);
    src2RegClass = *(int *)(src2RegClass + 0x98);
  }
  else {
    allocTable = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
    srcDefTemp = IRInst__getOperandSource(inst,2);
    srcDefTemp = IRInst__getOperandSource(srcDefTemp,1);
    callResult = thunk_FUN_00134de8(allocTable,srcDefTemp);
    srcDefTemp = IRInst__getOperandSource(inst,2);
    src2RegClass = IRInst__getOperandSource(srcDefTemp,1);
    src2RegClass = *(int *)(src2RegClass + 0x98);
  }
  operandVReg = (int *)IRInst__getOperandSource(inst,3);
  isMix3 = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (isMix3 == 0) {
    allocTable = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
    srcDefTemp = IRInst__getOperandSource(inst,3);
    src3RegOffset = thunk_FUN_00134de8(allocTable,srcDefTemp);
    src3Def = IRInst__getOperandSource(inst,3);
    src3RegClass = *(int *)(src3Def + 0x98);
  }
  else {
    allocTable = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
    srcDefTemp = IRInst__getOperandSource(inst,3);
    srcDefTemp = IRInst__getOperandSource(srcDefTemp,1);
    src3RegOffset = thunk_FUN_00134de8(allocTable,srcDefTemp);
    srcDefTemp = IRInst__getOperandSource(inst,3);
    src3Def = IRInst__getOperandSource(srcDefTemp,1);
    src3RegClass = *(int *)(src3Def + 0x98);
  }
  if (((((src1RegClass != 0) || (src2RegClass != 0)) || (src3RegClass != 0)) || ((src1Reg == callResult || (callResult == src3RegOffset))))
     || (src1Reg == src3RegOffset)) goto LAB_0019bee4;
  opcodeByte = 0;
  if (hwOpcode == 4) {
LAB_0019bed0:
    *(undefined1 *)((int)instructionWords + 3) = opcodeByte;
  }
  else if (hwOpcode == 0xb) {
    opcodeByte = 1;
    goto LAB_0019bed0;
  }
  *(byte *)((int)instructionWords + 3) = (byte)*instructionWords | 0x80;
LAB_0019bee4:
  flagBit2 = ((int (*)())opcodeInfoIsVsFlagBit2)(*(undefined4 *)(this + 0x88),inst);
  if ((flagBit2 != 0) && (isMathInst)) {
    *(byte *)((int)instructionWords + 3) = (byte)*instructionWords | 0x40;
  }
  destRegType = inst[0x26];
  if ((destRegType == 5) && (inst[0x25] == 0)) {
    *(undefined4 *)(this + 0x2c) = *(undefined4 *)(this + 0x58);
    destRegType = inst[0x26];
  }
  *instructionWords = (*(uint *)(&DAT_001b2ad0 + destRegType * 4) & 0xf) << 8 | *instructionWords & 0xfffff0ff;
  destAddrMode = IRInst__operandKindClass(inst,0);
  if (destAddrMode == 1) {
    *(undefined4 *)(this + 0x24) = 1;
    *instructionWords = *instructionWords | 0x1000;
    destOffset = IRInst__getDefiningField128(inst,0);
    word0 = *instructionWords;
  }
  else if (destAddrMode == 2) {
    destOffset = 0;
    *(undefined4 *)(this + 0x24) = 1;
    word0 = *instructionWords & 0x1fffffff | 0x20000000;
    *instructionWords = word0;
  }
  else {
    word0 = *instructionWords;
    destOffset = 0;
  }
  if (((word0 & 0xf00) == 0x200) || ((word0 & 0xf00) == 0x300)) {
    if (destAddrMode == 0) {
      destOffset = destOffset + inst[0x25];
    }
    else {
      destOffset = destOffset + *(int *)(*(int *)(*(int *)(this + 0xc) + 0x6c4) + 0x3f0);
    }
  }
  else if (destAddrMode == 0) {
    destRegIndex = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),inst);
    destRegType2 = inst[0x26];
    destOffset = destOffset + destRegIndex;
    if (destRegType2 == 1) {
      hwLimits = *(int **)(*(int *)(this + 0xc) + 0x30c);
      hwBase = (**(code **)(*hwLimits + 0x138))(hwLimits,0);
      destOffset = destOffset - hwBase;
      newMax = ((int (*)())maxSigned)(*(undefined4 *)(this + 0x38),destOffset);
      *(undefined4 *)(this + 0x38) = newMax;
      destRegType2 = inst[0x26];
    }
    if (destRegType2 == 0) {
      newMax = ((int (*)())maxSigned)(*(undefined4 *)(this + 0x34),destOffset);
      *(undefined4 *)(this + 0x34) = newMax;
      word0 = *instructionWords;
    }
    else {
      word0 = *instructionWords;
    }
  }
  *instructionWords = (destOffset & 0x7f) << 0xd | word0 & 0xfff01fff;
  destRecord = IRInst__getOperandRecord(inst,0);
  destSelectWord = *(uint *)(destRecord + 0x10);
  word0New = (uint)((destSelectWord & 0xff) == 0) << 0x17 |
           (uint)((destSelectWord >> 8 & 0xff) == 0) << 0x16 |
           (uint)((destSelectWord >> 0x10 & 0xff) == 0) << 0x15 |
           (uint)(destSelectWord >> 0x18 == 0) << 0x14 | *instructionWords & 0xff0fffff;
  *instructionWords = word0New;
  if (inst[0x48] != 0) {
    flagBit2 = ((int (*)())opcodeInfoIsVsFlagBit2)(*(undefined4 *)(this + 0x88),inst);
    if ((flagBit2 == 0) || (!isMathInst)) {
      *instructionWords = word0New | 0x1000000;
    }
    else {
      *instructionWords = word0New | 0x2000000;
    }
  }
  return;
}

/* R300VMachineAssembler__encodeSourceOperand @ 0x19c130 (2376 bytes) */
int R300VMachineAssembler__encodeSourceOperand(this, inst, instructionWords, sourceNumber, operandSlot)
  int this;
  int inst;
  int instructionWords;
  int sourceNumber;
  int operandSlot;
{
  uint vsSourceSelectForConstantResult;
  uint offsetBits;
  uint src2Word;
  uint swizzleYField;
  uint laneNegateValue;
  uint laneByte;
  uint addrSelCleared;
  uint savedSrcWord9;
  uint srcTypeBits9;
  uint negateBase9;
  uint oldWord4;
  uint swizzleWField;
  uint addrMode1Bit;
  uint savedSrcWord3;
  uint negateFlag;
  uint negXField;
  undefined4 laneSrcInst;
  undefined4 src1DefInst;
  undefined4 constSwizzle;
  uint swizzleZField;
  uint addrMode0Copy;
  uint negateFlagInv;
  uint constSelectBits;
  int *hwLimitsObj;
  int laneOperandRecord;
  int src1DefForClass;
  int isTempClass;
  int laneByteOff;
  int isMixResult;
  int swizzleMatchResult;
  int defOperandRecord;
  int vsFlagBit2;
  int sourceOperandRecord;
  bool moreLanes;
  byte laneSelectByte;
  byte composedLaneByte;
  uint negYField;
  uint negZField;
  uint savedSrcWord;
  uint savedSrcWord2;
  uint addrSelBits;
  uint addrMode0Bit;
  int *srcDefInst;
  int instructionWordsAlias;
  uint addrMode1Copy;
  int loopIndex;
  int srcRegClass;
  int *regDefInst;
  int regBias;
  int callResult;
  undefined4 allocTable;
  undefined4 passThroughR8;
  int loopIndex2;
  uint uVar19;
  uint *sourceWord;
  undefined8 swizzlePair;
  uint local_88;
  uint origSwizzle;
  int constNegated;
  uint laneSelect [4];
  uint laneNegate [5];
  uint composedSwizzleOut;
  uint *laneSelectPtr;
  
  sourceWord = (uint *)(instructionWords + 8);
  if (((operandSlot != 2) && (sourceWord = (uint *)(instructionWords + 0xc), operandSlot != 3)) &&
     (sourceWord = (uint *)0x0, operandSlot == 1)) {
    sourceWord = (uint *)(instructionWords + 4);
  }
  instructionWordsAlias = instructionWords;
  loopIndex2 = sourceNumber;
  srcDefInst = (int *)IRInst__getOperandSource(inst,sourceNumber);
  if (srcDefInst[0x26] == 0x33) {
    if (sourceNumber < 2) {
      *sourceWord = *sourceWord & 0xffffe018;
      *(undefined4 *)(this + 0x80) = 1;
    }
    else {
      savedSrcWord = *sourceWord;
      uVar19 = *(uint *)(instructionWords + 4) & 7;
      *sourceWord = uVar19 | savedSrcWord & 0xfffffff8;
      addrMode0Bit = *(uint *)(instructionWords + 4) & 0x10;
      *sourceWord = addrMode0Bit | uVar19 | savedSrcWord & 0xffffffe8;
      addrMode1Copy = *(uint *)(instructionWords + 4) & 0x80000000;
      *sourceWord = addrMode1Copy | addrMode0Bit | uVar19 | savedSrcWord & 0x7fffffe8;
      addrSelBits = *(uint *)(instructionWords + 4) & 0x60000000;
      *sourceWord = addrSelBits | addrMode1Copy | addrMode0Bit | uVar19 | savedSrcWord & 0x1fffffe8;
      *sourceWord = *(uint *)(instructionWords + 4) & 0x1fe0 |
                 addrSelBits | addrMode1Copy | addrMode0Bit | uVar19 | savedSrcWord & 0x1fffe008;
    }
    sourceOperandRecord = IRInst__getOperandRecord(inst,sourceNumber);
    uVar19 = *(uint *)(sourceOperandRecord + 0x10);
    negateBase9 = *(uint *)(sourceNumber * 0x18 + inst + 0xa0) & 1;
    vsFlagBit2 = ((int (*)())opcodeInfoIsVsFlagBit2)(*(undefined4 *)(this + 0x88),inst);
    if (vsFlagBit2 != 0) {
      if (sourceNumber != 1) {
        uVar19 = uVar19 >> 0x18;
      }
      constSelectBits = ((int (*)())vsSourceSelectForConstant)(srcDefInst,uVar19 & 0xff,&constNegated);
      savedSrcWord = *sourceWord;
      constSelectBits = constSelectBits & 7;
      uVar19 = constSelectBits << 0xd;
      *sourceWord = uVar19 | savedSrcWord & 0xffff1fff;
      negateFlag = negateBase9 ^ 1;
      if (constNegated == 0) {
        negateFlag = negateBase9;
      }
      *sourceWord = negateFlag << 0x19 | uVar19 | savedSrcWord & 0xfdff1fff;
      *sourceWord = negateFlag << 0x1c |
                 constSelectBits << 0x16 |
                 negateFlag << 0x1b |
                 constSelectBits << 0x13 |
                 negateFlag << 0x1a | constSelectBits << 0x10 | negateFlag << 0x19 | uVar19 | savedSrcWord & 0xe0001fff;
      return;
    }
    constSelectBits = ((int (*)())vsSourceSelectForConstant)(srcDefInst,uVar19 >> 0x18,&constNegated);
    savedSrcWord = *sourceWord;
    constSelectBits = (constSelectBits & 7) << 0xd;
    *sourceWord = constSelectBits | savedSrcWord & 0xffff1fff;
    negateFlag = negateBase9 ^ 1;
    if (constNegated == 0) {
      negateFlag = negateBase9;
    }
    *sourceWord = negateFlag << 0x19 | constSelectBits | savedSrcWord & 0xfdff1fff;
    constSelectBits = ((int (*)())vsSourceSelectForConstant)(srcDefInst,uVar19 >> 0x10 & 0xff,&constNegated);
    savedSrcWord = *sourceWord;
    constSelectBits = (constSelectBits & 7) << 0x10;
    *sourceWord = constSelectBits | savedSrcWord & 0xfff8ffff;
    negateFlag = negateBase9 ^ 1;
    if (constNegated == 0) {
      negateFlag = negateBase9;
    }
    *sourceWord = negateFlag << 0x1a | constSelectBits | savedSrcWord & 0xfbf8ffff;
    constSelectBits = ((int (*)())vsSourceSelectForConstant)(srcDefInst,uVar19 >> 8 & 0xff,&constNegated);
    savedSrcWord = *sourceWord;
    constSelectBits = (constSelectBits & 7) << 0x13;
    *sourceWord = constSelectBits | savedSrcWord & 0xffc7ffff;
    negateFlag = negateBase9 ^ 1;
    if (constNegated == 0) {
      negateFlag = negateBase9;
    }
    *sourceWord = negateFlag << 0x1b | constSelectBits | savedSrcWord & 0xf7c7ffff;
    vsSourceSelectForConstantResult = ((int (*)())vsSourceSelectForConstant)(srcDefInst,uVar19 & 0xff,&constNegated);
    savedSrcWord3 = *sourceWord;
    uVar19 = (vsSourceSelectForConstantResult & 7) << 0x16;
    *sourceWord = uVar19 | savedSrcWord3 & 0xfe3fffff;
    negateFlagInv = negateBase9 ^ 1;
    if (constNegated == 0) {
      negateFlagInv = negateBase9;
    }
    *sourceWord = negateFlagInv << 0x1c | uVar19 | savedSrcWord3 & 0xee3fffff;
    return;
  }
  loopIndex = (**(code **)(*srcDefInst + 0x60))(srcDefInst);
  if (loopIndex == 0) {
    loopIndex = IRInst__operandKindClass(inst,sourceNumber);
    srcRegClass = srcDefInst[0x26];
    allocTable = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
    regDefInst = srcDefInst;
LAB_0019c490:
    uVar19 = thunk_FUN_00134de8(allocTable,regDefInst);
    *sourceWord = *(uint *)(&DAT_001b2c14 + srcRegClass * 4) & 7 | *sourceWord & 0xfffffff8;
    if (srcRegClass == 0x37) {
      *(undefined4 *)(this + 0x30) = *(undefined4 *)(this + 0x58);
    }
    else if (srcRegClass == 1) {
      hwLimitsObj = *(int **)(*(int *)(this + 0xc) + 0x30c);
      regBias = (**(code **)(*hwLimitsObj + 0x138))(hwLimitsObj,0);
      uVar19 = uVar19 - regBias;
    }
  }
  else {
    loopIndex = IRInst__operandKindClass(srcDefInst,1);
    srcRegClass = IRInst__getOperandSource(srcDefInst,1);
    srcRegClass = *(int *)(srcRegClass + 0x98);
    if (srcRegClass != 0x33) {
      allocTable = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
      regDefInst = (int *)IRInst__getOperandSource(srcDefInst,1);
      goto LAB_0019c490;
    }
    if (sourceNumber < 2) {
      uVar19 = 0;
      *sourceWord = *sourceWord & 0xfffffff8;
      *(undefined4 *)(this + 0x80) = 1;
    }
    else {
      savedSrcWord = *sourceWord;
      srcTypeBits9 = *(uint *)(instructionWords + 4) & 7;
      *sourceWord = srcTypeBits9 | savedSrcWord & 0xfffffff8;
      addrMode0Copy = *(uint *)(instructionWords + 4) & 0x10;
      uVar19 = *(uint *)(instructionWords + 4) >> 5 & 0xff;
      *sourceWord = addrMode0Copy | srcTypeBits9 | savedSrcWord & 0xffffffe8;
      addrMode1Bit = *(uint *)(instructionWords + 4) & 0x80000000;
      *sourceWord = addrMode1Bit | addrMode0Copy | srcTypeBits9 | savedSrcWord & 0x7fffffe8;
      *sourceWord = *(uint *)(instructionWords + 4) & 0x60000000 | addrMode1Bit | addrMode0Copy | srcTypeBits9 | savedSrcWord & 0x1fffffe8;
    }
  }
  isTempClass = RegKind__flagBit7(srcDefInst[0x26]);
  callResult = (**(code **)(*srcDefInst + 0x60))(srcDefInst);
  if (callResult != 0) {
    src1DefForClass = IRInst__getOperandSource(srcDefInst,1);
    if (src1DefForClass == 0) {
      isTempClass = srcDefInst[0x2c];
    }
    else {
      isTempClass = IRInst__getOperandSource(srcDefInst,1);
      isTempClass = *(int *)(isTempClass + 0x98);
    }
    isTempClass = RegKind__flagBit7(isTempClass);
  }
  if ((isTempClass != 0) && (*(uint *)(this + 0x4c) < uVar19)) {
    *(uint *)(this + 0x4c) = uVar19;
  }
  if (loopIndex - 1U < 2) {
    loopIndex = (**(code **)(*srcDefInst + 0x60))(srcDefInst);
    if (loopIndex == 0) {
      swizzlePair = IRInst__getDefiningField128(inst,sourceNumber);
    }
    else {
      swizzlePair = IRInst__getDefiningField128(srcDefInst,1);
    }
    uVar19 = (uint)((ulonglong)swizzlePair >> 0x20);
    *(undefined4 *)(this + 0x24) = 1;
    if (srcRegClass == 0x28) {
      *(undefined4 *)(this + 0x4c) = 0xff;
    }
    else if (srcRegClass != 0x29) {
      if (srcRegClass == 0x26) {
        *(undefined4 *)(this + 0x4c) = 0xff;
        savedSrcWord9 = *sourceWord;
        *sourceWord = savedSrcWord9 | 0x10;
        instructionWordsAlias = (**(code **)(*srcDefInst + 0x60))(srcDefInst,(int)swizzlePair,instructionWordsAlias,loopIndex2,operandSlot,passThroughR8,savedSrcWord9 | 0x10);
        if (instructionWordsAlias == 0) {
          defOperandRecord = IRInst__getOperandRecord(srcDefInst,1);
          constSwizzle = *(undefined4 *)(defOperandRecord + 0x10);
        }
        else {
          src1DefInst = IRInst__getOperandSource(srcDefInst,1);
          defOperandRecord = IRInst__getOperandRecord(src1DefInst,1);
          constSwizzle = *(undefined4 *)(defOperandRecord + 0x10);
        }
        swizzleMatchResult = SelectWord__areCompatible(constSwizzle,0);
        if (swizzleMatchResult != 0) {
          addrSelCleared = *sourceWord & 0x9fffffff;
          *sourceWord = addrSelCleared;
          goto LAB_0019c710;
        }
        swizzleMatchResult = SelectWord__areCompatible(constSwizzle,0x1010101);
        if (swizzleMatchResult != 0) {
          addrSelCleared = *sourceWord & 0x9fffffff | 0x20000000;
          *sourceWord = addrSelCleared;
          goto LAB_0019c710;
        }
        swizzleMatchResult = SelectWord__areCompatible(constSwizzle,0x2020202);
        if (swizzleMatchResult != 0) {
          addrSelCleared = *sourceWord & 0x9fffffff | 0x40000000;
          *sourceWord = addrSelCleared;
          goto LAB_0019c710;
        }
        swizzleMatchResult = SelectWord__areCompatible(constSwizzle,0x3030303);
        if (swizzleMatchResult != 0) {
          addrSelCleared = *sourceWord & 0x9fffffff | 0x60000000;
          *sourceWord = addrSelCleared;
          goto LAB_0019c710;
        }
      }
      goto LAB_0019c70c;
    }
    addrSelCleared = *sourceWord & 0x9fffffff | 0x80000000;
    *sourceWord = addrSelCleared;
  }
  else {
LAB_0019c70c:
    addrSelCleared = *sourceWord;
  }
LAB_0019c710:
  *sourceWord = (uVar19 & 0xff) << 5 | addrSelCleared & 0xffffe01f;
  uVar19 = *(uint *)(sourceNumber * 0x18 + inst + 0xa0) & 1;
  sourceOperandRecord = IRInst__getOperandRecord(inst,sourceNumber);
  local_88 = *(uint *)(sourceOperandRecord + 0x10);
  isMixResult = (**(code **)(*srcDefInst + 0x60))(srcDefInst);
  if (isMixResult == 0) {
    laneSelect[0] = *(uint *)(&DAT_001b2be8 + (local_88 >> 0x18) * 4);
    laneSelect[2] = *(uint *)(&DAT_001b2be8 + (local_88 >> 8 & 0xff) * 4);
    laneSelect[3] = *(uint *)(&DAT_001b2be8 + (local_88 & 0xff) * 4);
    laneSelect[1] = *(uint *)(&DAT_001b2be8 + (local_88 >> 0x10 & 0xff) * 4);
    laneNegate[0] = uVar19;
    laneNegate[1] = uVar19;
    laneNegate[2] = uVar19;
    laneNegate[3] = uVar19;
  }
  else {
    defOperandRecord = IRInst__getOperandRecord(srcDefInst,1);
    origSwizzle = local_88;
    SelectWord__compose(&composedSwizzleOut,*(undefined4 *)(defOperandRecord + 0x10),local_88);
    local_88 = composedSwizzleOut;
    loopIndex2 = 0;
    laneByteOff = 0;
    laneSelectPtr = laneSelect;
    do {
      laneSelectByte = *(byte *)((int)&origSwizzle + loopIndex2);
      if (laneSelectByte != 4) {
        if ((srcRegClass == 0x33) || (composedLaneByte = *(byte *)((int)&local_88 + loopIndex2), composedLaneByte == 4)) {
          if (0 < srcDefInst[0x21]) {
            loopIndex = 1;
            do {
              laneOperandRecord = IRInst__getOperandRecord(srcDefInst,loopIndex);
              laneByte = (uint)*(byte *)((uint)laneSelectByte + laneOperandRecord + 0x10);
              if (laneByte != 4) {
                laneSrcInst = IRInst__getOperandSource(srcDefInst,loopIndex);
                laneSrcInst = ((int (*)())vsSourceSelectForConstant)(laneSrcInst,laneByte,&constNegated);
                *(undefined4 *)(laneByteOff + (int)laneSelectPtr) = laneSrcInst;
                laneNegateValue = uVar19;
                if (constNegated != 0) {
                  laneNegateValue = (uint)(uVar19 == 0);
                }
                *(uint *)((int)laneNegate + laneByteOff) = laneNegateValue;
                break;
              }
              loopIndex = loopIndex + 1;
            } while (loopIndex <= srcDefInst[0x21]);
          }
        }
        else {
          *(uint *)((int)laneNegate + laneByteOff) = uVar19;
          *(undefined4 *)(laneByteOff + (int)laneSelect) = *(undefined4 *)(&DAT_001b2be8 + (uint)composedLaneByte * 4)
          ;
        }
      }
      moreLanes = loopIndex2 != 3;
      laneByteOff = laneByteOff + 4;
      loopIndex2 = loopIndex2 + 1;
    } while (moreLanes);
  }
  vsFlagBit2 = ((int (*)())opcodeInfoIsVsFlagBit2)(*(undefined4 *)(this + 0x88),inst);
  if (vsFlagBit2 == 0) {
    savedSrcWord2 = *sourceWord;
    uVar19 = (laneSelect[0] & 7) << 0xd;
    *sourceWord = uVar19 | savedSrcWord2 & 0xffff1fff;
    swizzleYField = (laneSelect[1] & 7) << 0x10;
    *sourceWord = swizzleYField | uVar19 | savedSrcWord2 & 0xfff81fff;
    swizzleZField = (laneSelect[2] & 7) << 0x13;
    *sourceWord = swizzleZField | swizzleYField | uVar19 | savedSrcWord2 & 0xffc01fff;
    swizzleWField = (laneSelect[3] & 7) << 0x16;
    *sourceWord = swizzleWField | swizzleZField | swizzleYField | uVar19 | savedSrcWord2 & 0xfe001fff;
    negXField = (laneNegate[0] & 1) << 0x19;
    *sourceWord = negXField | swizzleWField | swizzleZField | swizzleYField | uVar19 | savedSrcWord2 & 0xfc001fff;
    negYField = (laneNegate[1] & 1) << 0x1a;
    *sourceWord = negYField | negXField | swizzleWField | swizzleZField | swizzleYField | uVar19 | savedSrcWord2 & 0xf8001fff;
    negZField = (laneNegate[2] & 1) << 0x1b;
    *sourceWord = negZField | negYField | negXField | swizzleWField | swizzleZField | swizzleYField | uVar19 | savedSrcWord2 & 0xf0001fff;
    uVar19 = (laneNegate[3] & 1) << 0x1c |
             negZField | negYField | negXField | swizzleWField | swizzleZField | swizzleYField | uVar19 | savedSrcWord2 & 0xe0001fff;
    *sourceWord = uVar19;
  }
  else {
    if (sourceNumber == 1) {
      savedSrcWord9 = *sourceWord;
      uVar19 = (laneSelect[3] & 7) << 0xd;
      *sourceWord = uVar19 | savedSrcWord9 & 0xffff1fff;
      uVar19 = (laneNegate[3] & 1) << 0x19 | uVar19 | savedSrcWord9 & 0xfdff1fff;
      *sourceWord = uVar19;
    }
    else if (sourceNumber == 2) {
      savedSrcWord9 = *sourceWord;
      uVar19 = (laneSelect[0] & 7) << 0xd;
      *sourceWord = uVar19 | savedSrcWord9 & 0xffff1fff;
      uVar19 = (laneNegate[0] & 1) << 0x19 | uVar19 | savedSrcWord9 & 0xfdff1fff;
      *sourceWord = uVar19;
    }
    else {
      uVar19 = *sourceWord;
    }
    uVar19 = (uVar19 & 0x2000000) << 3 |
             (uVar19 & 0x2000000) << 2 |
             (uVar19 & 0x2000000) << 1 |
             (uVar19 & 0xe000) << 9 |
             (uVar19 & 0xe000) << 6 | (uVar19 & 0xe000) << 3 | uVar19 & 0xe200ffff;
    *sourceWord = uVar19;
  }
  if ((*(int *)(this + 0x84) != 0) && ((uVar19 & 0x80000010) == 0)) {
    src2Word = *(uint *)(instructionWords + 0xc);
    *(uint *)(instructionWords + 0xc) = uVar19 & 3 | src2Word & 0xfffffffc;
    *(uint *)(instructionWords + 0xc) = *sourceWord & 0x1fe0 | uVar19 & 3 | src2Word & 0xffffe01c;
  }
  if ((*(int *)(this + 0x80) != 0) && (sourceNumber == 2)) {
    oldWord4 = *(uint *)(instructionWords + 4);
    uVar19 = *sourceWord & 7;
    *(uint *)(instructionWords + 4) = uVar19 | oldWord4 & 0xfffffff8;
    offsetBits = *sourceWord & 0x1fe0;
    *(uint *)(instructionWords + 4) = offsetBits | uVar19 | oldWord4 & 0xffffe018;
    addrMode0Copy = *sourceWord & 0x10;
    *(uint *)(instructionWords + 4) = addrMode0Copy | offsetBits | uVar19 | oldWord4 & 0xffffe008;
    savedSrcWord = *sourceWord;
    *(uint *)(instructionWords + 4) = savedSrcWord & 0x80000000 | addrMode0Copy | offsetBits | uVar19 | oldWord4 & 0x7fffe008;
    *(uint *)(instructionWords + 4) =
         *sourceWord & 0x60000000 | savedSrcWord & 0x80000000 | addrMode0Copy | offsetBits | uVar19 | oldWord4 & 0x1fffe008;
  }
  return;
}

/* R300VMachineAssembler__encodeDualMathOperands @ 0x19ca78 (1916 bytes) */
int R300VMachineAssembler__encodeDualMathOperands(this, inst, instructionWords)
  int this;
  int *inst;
  uint *instructionWords;
{
  uint newDualMathWord;
  uint selectWord1;
  uint oldDualMathWord;
  uint source2Word;
  uint opcodeTraitWord;
  uint selectWord2;
  uint src2Select;
  uint src1Select;
  uint negateBit2;
  uint negateBit1;
  int regBias;
  int srcRegister;
  undefined4 sourceDef2;
  undefined4 sourceDef;
  int operandRecord;
  uint source1Flags;
  int *operandVReg;
  byte laneSelectByte;
  uint source1Word;
  uint srcRegisterIndex;
  int loopIndex;
  int *hwLimits;
  int srcIsMov;
  undefined4 srcSelectWord;
  int *hwLimitsObj8;
  int regBias9;
  uint *a2;
  undefined4 passThroughR6;
  undefined4 passThroughR7;
  undefined4 passThroughR8;
  uint dualMathFlags;
  uint *dualMathWord;
  undefined4 currentProgram;
  undefined8 srcOffsetPair;
  undefined8 maxPair;
  int constNegated [4];
  uint composedSwizzle1;
  uint composedSwizzle2 [2];
  
  dualMathWord = instructionWords + 3;
  *instructionWords = *instructionWords | 0x10000000;
  a2 = instructionWords;
  IRInst__operandKindClass(inst,1);
  loopIndex = (**(code **)(*inst + 0x14))(inst);
  if (loopIndex == 2) {
    IRInst__operandKindClass(inst,2);
  }
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  loopIndex = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (loopIndex == 0) {
    loopIndex = operandVReg[0x26];
  }
  else {
    loopIndex = IRInst__getOperandSource(operandVReg,1);
    loopIndex = *(int *)(loopIndex + 0x98);
  }
  if (loopIndex == 0x37) {
    *(undefined4 *)(this + 0x30) = *(undefined4 *)(this + 0x58);
  }
  srcIsMov = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (srcIsMov == 0) {
    srcOffsetPair = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),operandVReg);
  }
  else {
    currentProgram = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
    sourceDef2 = IRInst__getOperandSource(operandVReg,1);
    srcOffsetPair = thunk_FUN_00134de8(currentProgram,sourceDef2);
  }
  srcRegister = (int)((ulonglong)srcOffsetPair >> 0x20);
  if (loopIndex == 1) {
    hwLimitsObj8 = *(int **)(*(int *)(this + 0xc) + 0x30c);
    regBias9 = (**(code **)(*hwLimitsObj8 + 0x138))(hwLimitsObj8,0);
    maxPair = ((int (*)())maxSigned)(*(undefined4 *)(this + 0x38),srcRegister - regBias9);
    srcOffsetPair = CONCAT44(srcRegister - regBias9,(int)maxPair);
    *(int *)(this + 0x38) = (int)((ulonglong)maxPair >> 0x20);
  }
  else if (loopIndex == 0) {
    maxPair = ((int (*)())maxSigned)(*(undefined4 *)(this + 0x34),srcRegister);
    srcOffsetPair = CONCAT44(srcRegister,(int)maxPair);
    *(int *)(this + 0x34) = (int)((ulonglong)maxPair >> 0x20);
  }
  srcRegisterIndex = (uint)((ulonglong)srcOffsetPair >> 0x20);
  source1Flags = inst[0x2e];
  if ((source1Flags & 2) == 0) {
    dualMathFlags = *dualMathWord;
  }
  else {
    dualMathFlags = *dualMathWord | 8;
    *dualMathWord = dualMathFlags;
    source1Flags = inst[0x2e];
  }
  if ((source1Flags & 1) != 0) {
    dualMathFlags = dualMathFlags | 0x2000000;
    *dualMathWord = dualMathFlags;
  }
  if ((inst[0x34] & 1U) != 0) {
    dualMathFlags = dualMathFlags | 0x4000000;
    *dualMathWord = dualMathFlags;
  }
  if (operandVReg[0x26] == 0x33) {
    source1Word = instructionWords[1];
    if ((source1Word & 0x80000010) == 0) {
      *dualMathWord = source1Word & 3 | dualMathFlags & 0xfffffffc;
      *dualMathWord = instructionWords[1] & 0x1fe0 | source1Word & 3 | dualMathFlags & 0xffffe01c;
    }
    else {
      source2Word = instructionWords[2];
      if ((source2Word & 0x80000010) == 0) {
        *dualMathWord = source2Word & 3 | dualMathFlags & 0xfffffffc;
        *dualMathWord = instructionWords[2] & 0x1fe0 | source2Word & 3 | dualMathFlags & 0xffffe01c;
      }
      else if (((source1Word & 7) == 0) && ((source2Word & 7) == 0)) {
        *dualMathWord = dualMathFlags & 0xffffe01c | 2;
      }
      else {
        *dualMathWord = dualMathFlags & 0xffffe01c;
      }
    }
    *(undefined4 *)(this + 0x84) = 1;
    loopIndex = IRInst__getOperandRecord(inst,1);
    src1Select = ((int (*)())vsSourceSelectForConstant)(operandVReg,(uint)*(byte *)(loopIndex + 0x13),constNegated);
    oldDualMathWord = *dualMathWord;
    src1Select = (src1Select & 7) << 0xd;
    *dualMathWord = src1Select | oldDualMathWord & 0xffff1fff;
    negateBit1 = oldDualMathWord >> 0x19 & 1;
    if (constNegated[0] != 0) {
      negateBit1 = 1 - negateBit1;
    }
    *dualMathWord = (negateBit1 & 1) << 0x19 | src1Select | oldDualMathWord & 0xfdff1fff;
    loopIndex = (**(code **)(*inst + 0x14))(inst);
    if (1 < loopIndex) {
      sourceDef2 = IRInst__getOperandSource(inst,2);
      loopIndex = IRInst__getOperandRecord(inst,2);
      src2Select = ((int (*)())vsSourceSelectForConstant)(sourceDef2,(uint)*(byte *)(loopIndex + 0x10),constNegated);
      oldDualMathWord = *dualMathWord;
      src2Select = (src2Select & 7) << 0x10;
      *dualMathWord = src2Select | oldDualMathWord & 0xfff8ffff;
      negateBit2 = oldDualMathWord >> 0x1a & 1;
      if (constNegated[0] != 0) {
        negateBit2 = 1 - negateBit2;
      }
      *dualMathWord = (negateBit2 & 1) << 0x1a | src2Select | oldDualMathWord & 0xfbf8ffff;
    }
    goto LAB_0019d024;
  }
  *dualMathWord = *(uint *)(&DAT_001b2c14 + loopIndex * 4) & 3 | dualMathFlags & 0xfffffffc;
  loopIndex = (**(code **)(*operandVReg + 0x60))(operandVReg,(int)srcOffsetPair,a2,passThroughR6,passThroughR7,passThroughR8,loopIndex * 4);
  if (loopIndex == 0) {
    loopIndex = RegKind__flagBit7(operandVReg[0x26]);
  }
  else {
    loopIndex = IRInst__getOperandSource(operandVReg,1);
    loopIndex = RegKind__flagBit7(*(undefined4 *)(loopIndex + 0x98));
  }
  if ((loopIndex != 0) && (*(uint *)(this + 0x4c) < srcRegisterIndex)) {
    *(uint *)(this + 0x4c) = srcRegisterIndex;
  }
  *dualMathWord = (srcRegisterIndex & 0xff) << 5 | *dualMathWord & 0xffffe01f;
  loopIndex = IRInst__getOperandRecord(inst,1);
  selectWord1 = *(uint *)(loopIndex + 0x10);
  loopIndex = (**(code **)(*inst + 0x14))(inst);
  selectWord2 = selectWord1;
  if (1 < loopIndex) {
    loopIndex = IRInst__getOperandRecord(inst,2);
    selectWord2 = *(uint *)(loopIndex + 0x10);
  }
  loopIndex = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (loopIndex == 0) {
    loopIndex = (**(code **)(*inst + 0x14))(inst);
    if (loopIndex < 2) {
      selectWord1 = *(uint *)(&DAT_001b2be8 + (selectWord1 & 0xff) * 4);
      selectWord2 = selectWord1;
    }
    else {
      selectWord1 = *(uint *)(&DAT_001b2be8 + (selectWord1 & 0xff) * 4);
      selectWord2 = *(uint *)(&DAT_001b2be8 + (selectWord2 >> 0x16 & 0x3fc));
    }
  }
  else {
    loopIndex = IRInst__getOperandRecord(operandVReg,1);
    srcSelectWord = *(undefined4 *)(loopIndex + 0x10);
    SelectWord__compose(&composedSwizzle1,srcSelectWord,selectWord1);
    if (((selectWord1 & 0xff) == 4) || ((composedSwizzle1 & 0xff) == 4)) {
      loopIndex = 1;
      if (0 < operandVReg[0x21]) {
        do {
          operandRecord = IRInst__getOperandRecord(operandVReg,loopIndex);
          laneSelectByte = *(byte *)(operandRecord + 0x13);
          if (laneSelectByte != 4) {
            sourceDef = IRInst__getOperandSource(operandVReg,loopIndex);
            selectWord1 = ((int (*)())vsSourceSelectForConstant)(sourceDef,(uint)laneSelectByte,constNegated);
            goto LAB_0019cf10;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex <= operandVReg[0x21]);
      }
      selectWord1 = 0;
    }
    else {
      selectWord1 = *(uint *)(&DAT_001b2be8 + (composedSwizzle1 & 0xff) * 4);
    }
LAB_0019cf10:
    loopIndex = (**(code **)(*inst + 0x14))(inst);
    if (1 < loopIndex) {
      SelectWord__compose(composedSwizzle2,srcSelectWord,selectWord2);
      if ((selectWord2 >> 0x18 != 4) && (composedSwizzle2[0] >> 0x18 != 4)) {
        selectWord2 = *(uint *)(&DAT_001b2be8 + (composedSwizzle2[0] >> 0x18) * 4);
        goto LAB_0019d014;
      }
      loopIndex = 1;
      if (0 < operandVReg[0x21]) {
        do {
          operandRecord = IRInst__getOperandRecord(operandVReg,loopIndex);
          laneSelectByte = *(byte *)(operandRecord + 0x10);
          if (laneSelectByte != 4) {
            sourceDef2 = IRInst__getOperandSource(operandVReg,loopIndex);
            selectWord2 = ((int (*)())vsSourceSelectForConstant)(sourceDef2,(uint)laneSelectByte,constNegated);
            goto LAB_0019d014;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex <= operandVReg[0x21]);
      }
    }
    selectWord2 = 0;
  }
LAB_0019d014:
  *dualMathWord = (selectWord2 & 7) << 0x10 | (selectWord1 & 7) << 0xd | *dualMathWord & 0xfff81fff;
LAB_0019d024:
  hwLimits = *(int **)(*(int *)(this + 0xc) + 0x30c);
  loopIndex = (**(code **)(*hwLimits + 0x16c))(hwLimits);
  opcodeTraitWord = *(uint *)(*(int *)(inst[0x22] + 8) * 0x38 + loopIndex + 0xc);
  if (opcodeTraitWord == 0xffffffff) {
    if (*(int *)(inst[0x22] + 8) == 0x66) {
      *dualMathWord = *dualMathWord & 0xfe18ffff | 0x1450000;
    }
  }
  else {
    newDualMathWord = (opcodeTraitWord & 0xf) << 0x15 | *dualMathWord & 0xfe1fffff;
    *dualMathWord = newDualMathWord;
    if (0xf < (int)opcodeTraitWord) {
      *dualMathWord = newDualMathWord | 4;
    }
  }
  loopIndex = IRInst__getOperandRecord(inst,0);
  loopIndex = *(int *)(loopIndex + 0x10);
  if (loopIndex == 0x10101) {
    *dualMathWord = *dualMathWord & 0xe7ffffff;
  }
  else if (loopIndex == 0x1000101) {
    *dualMathWord = *dualMathWord & 0xe7ffffff | 0x8000000;
  }
  else if (loopIndex == 0x1010001) {
    *dualMathWord = *dualMathWord & 0xe7ffffff | 0x10000000;
  }
  else if (loopIndex == 0x1010100) {
    *dualMathWord = *dualMathWord & 0xe7ffffff | 0x18000000;
  }
  loopIndex = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),inst);
  hwLimits = *(int **)(*(int *)(this + 0xc) + 0x30c);
  regBias = (**(code **)(*hwLimits + 0x138))(hwLimits,0);
  *dualMathWord = (loopIndex - regBias) * 0x80000 & 0x180000U | *dualMathWord & 0xffe7ffff;
  if (inst[0x48] != 0) {
    hwLimits = *(int **)(*(int *)(this + 0xc) + 0x30c);
    (**(code **)(*hwLimits + 0x80))(hwLimits);
    *instructionWords = *instructionWords | 0x2000000;
  }
  return;
}

/* R300VMachineAssembler__vslot14_assembleInstruction @ 0x19d1f4 (572 bytes) */
int R300VMachineAssembler__vslot14_assembleInstruction(this, inst)
  int this;
  int *inst;
{
  int srcRecord;
  int numSources;
  int flagBit2;
  int slotByteOffset;
  int instSlotTable;
  uint *instructionWords;
  
  instSlotTable = *(int *)(this + 8);
  slotByteOffset = *(int *)(this + 0x58) * 8;
  if (*(int *)(instSlotTable + slotByteOffset) == 0) {
    *(int **)(instSlotTable + slotByteOffset) = inst;
  }
  else {
    *(int **)(instSlotTable + slotByteOffset + 4) = inst;
  }
  instructionWords = (uint *)(*(int *)(this + 0x58) * 0x10 + *(int *)(this + 0x44));
  flagBit2 = ((int (*)())opcodeInfoIsVsFlagBit2)(*(undefined4 *)(this + 0x88),inst);
  if ((flagBit2 == 0) || (*(int *)(this + 0x7c) == 0)) {
    *(undefined4 *)(this + 0x84) = 0;
    *(undefined4 *)(this + 0x80) = 0;
    numSources = (**(code **)(*inst + 0x14))(inst);
    if (0 < numSources) {
      ((int (*)())R300VMachineAssembler__encodeSourceOperand)(this,inst,instructionWords,1,1);
    }
    numSources = (**(code **)(*inst + 0x14))(inst);
    if (numSources < 2) {
      ((int (*)())copyLaneWord)(instructionWords,1,2);
    }
    else {
      ((int (*)())R300VMachineAssembler__encodeSourceOperand)(this,inst,instructionWords,2,2);
    }
    numSources = (**(code **)(*inst + 0x14))(inst);
    if (numSources < 3) {
      if (*(int *)(this + 0x7c) == 0) {
        ((int (*)())copyLaneWord)(instructionWords,2,3);
      }
    }
    else {
      ((int (*)())R300VMachineAssembler__encodeSourceOperand)(this,inst,instructionWords,3,3);
    }
    ((int (*)())R300VMachineAssembler__encodeDestinationWord)(this,inst,instructionWords);
  }
  else {
    numSources = (**(code **)(*inst + 0x14))(inst);
    if (1 < numSources) {
      IRInst__getOperandSource(inst,1);
      IRInst__getOperandSource(inst,2);
    }
    numSources = (**(code **)(*inst + 0x14))(inst);
    if (0 < numSources) {
      srcRecord = IRInst__getOperandRecord(inst,1);
      SelectWord__isSplat(*(undefined4 *)(srcRecord + 0x10));
    }
    ((int (*)())R300VMachineAssembler__encodeDualMathOperands)(this,inst,instructionWords);
  }
  if (inst[0x47] == 2) {
    *instructionWords = *instructionWords & 0xf7ffffff | 0x4000000;
  }
  else if (inst[0x47] == 3) {
    *instructionWords = *instructionWords | 0xc000000;
  }
  return;
}

/* R300VMachineAssembler__getOrAllocateScratchRegister @ 0x19d430 (68 bytes) */
int R300VMachineAssembler__getOrAllocateScratchRegister(this, registerAllocator)
  int this;
  undefined4 registerAllocator;
{
  undefined4 uVar1;
  
  if (*(int *)(this + 0x8c) < 0) {
    uVar1 = RegAlloc__allocateFirstFreeInClass(registerAllocator,0);
    *(undefined4 *)(this + 0x8c) = uVar1;
  }
  return;
}

/* R520VMachineAssembler__vslot33_noOp @ 0x19d474 (4 bytes) */
int R520VMachineAssembler__vslot33_noOp()
{
  return;
}

/* R520VMachineAssembler__vslot12_visitNode @ 0x19d478 (140 bytes) */
int R520VMachineAssembler__vslot12_visitNode(this, node, visitFlag)
  int this;
  int *node;
  int visitFlag;
{
  uint topKindIndex;
  uint predKindCount;
  undefined4 *topKindSlot;
  
  if (visitFlag == 0) {
    topKindSlot = (undefined4 *)0x0;
    predKindCount = *(uint *)(*(int *)(this + 0x94) + 4);
    topKindIndex = predKindCount - 1;
    if (topKindIndex < predKindCount) {
      topKindSlot = (undefined4 *)(topKindIndex * 4 + *(int *)(*(int *)(this + 0x94) + 8));
    }
    FUN_000e2bf4(node + 0x24,*topKindSlot);
  }
                    
                    
  (**(code **)(*node + 0x44))(node,*(undefined4 *)(this + 0x10),visitFlag);
  return;
}

/* R520VMachineAssembler__getOrCreateConstantZeroInst @ 0x19d4e8 (116 bytes) */
int R520VMachineAssembler__getOrCreateConstantZeroInst(this)
  int this;
{
  int zeroInst;
  undefined4 zeroRegister;
  undefined4 *instAlloc;
  undefined4 arenaAt378;
  
  zeroInst = *(int *)(this + 0x90);
  if (zeroInst == 0) {
    zeroRegister = RegAlloc__allocateFirstFreeInClass(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),0);
    arenaAt378 = *(undefined4 *)(*(int *)(this + 0xc) + 0x378);
    instAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x168);
    *instAlloc = arenaAt378;
    IRLoadTemp__ctor_109554(instAlloc + 1,*(undefined4 *)(this + 0xc));
    *(undefined4 **)(this + 0x90) = instAlloc + 1;
    instAlloc[0x27] = 0;
    instAlloc[0x26] = zeroRegister;
    zeroInst = *(int *)(this + 0x90);
  }
  return zeroInst;
}

/* R520VMachineAssembler__vslot37_closeConditional @ 0x19d590 (528 bytes) */
int R520VMachineAssembler__vslot37_closeConditional(this, node, extra1, compiler)
  int this;
  int *node;
  undefined4 extra1;
  int compiler;
{
  int *cfTopSlot;
  uint cfTopIndex;
  int *newInst;
  undefined4 sourceSelect;
  uint pushIndex;
  uint cfStackCount;
  int callResult;
  undefined4 *pushedSlot;
  int zeroInst;
  int *firstElemSlot;
  int conditionBlock;
  uint *predKindStack;
  
  conditionBlock = node[0x4e];
  callResult = DList__count(conditionBlock + 0x90);
  if ((callResult < 3) && (callResult = Block__hasSuccessors(conditionBlock), callResult != 0)) {
    firstElemSlot = (int *)0x0;
    if (*(int *)(*(int *)(conditionBlock + 0xd0) + 4) != 0) {
      firstElemSlot = *(int **)(*(int *)(conditionBlock + 0xd0) + 8);
    }
    if (*firstElemSlot == node[0x4f]) {
      return;
    }
  }
  callResult = (**(code **)(*node + 0x40))(node);
  if (callResult == 0) {
    if ((node[0x51] == 0) || (*(int *)(*(int *)(this + 0x94) + 4) != 2)) {
      if (**(int **)(compiler + COMP_currentProgram) == 0) {
        newInst = (int *)IRInst__create(0x57,compiler);
        zeroInst = ((int (*)())R520VMachineAssembler__getOrCreateConstantZeroInst)(this);
        callResult = DAT_001b2d50;
        newInst[0x25] = *(int *)(zeroInst + 0x94);
        newInst[0x27] = callResult;
        newInst[0x26] = 0;
        IRInst__setOperandSource(newInst,1,zeroInst,0,compiler);
        sourceSelect = DAT_001b2d4c;
        callResult = IRInst__getOperandRecord(newInst,1);
        *(undefined4 *)(callResult + 0x10) = sourceSelect;
        (**(code **)(*newInst + 0x84))(newInst,0);
        Block__prependInst(conditionBlock,newInst);
        return;
      }
    }
    else {
      Vector__removeAt(*(int *)(this + 0x94),1);
      predKindStack = *(uint **)(this + 0x94);
      pushIndex = predKindStack[1];
      if (pushIndex < *predKindStack) {
        _memset(pushIndex * 4 + predKindStack[2],0,4);
        pushedSlot = (undefined4 *)(pushIndex * 4 + predKindStack[2]);
        predKindStack[1] = pushIndex + 1;
      }
      else {
        pushedSlot = (undefined4 *)Vector__elementRefGrow(predKindStack,pushIndex);
      }
      *pushedSlot = 2;
    }
  }
  else {
    cfTopSlot = (int *)0x0;
    callResult = *(int *)(*(int *)(this + 0x10) + 0x24);
    cfStackCount = *(uint *)(callResult + 4);
    cfTopIndex = cfStackCount - 1;
    if (cfTopIndex < cfStackCount) {
      cfTopSlot = (int *)(cfTopIndex * 4 + *(int *)(callResult + 8));
    }
    callResult = *cfTopSlot;
    ((int (*)())R300VMachineAssembler__transitionState)(this,4);
    *(int *)(callResult + 0x14) = *(int *)(this + 0x58) + -2;
  }
  return;
}

/* R520VMachineAssembler__vslot32_assembleWithPredicateClear @ 0x19d7a0 (184 bytes) */
int R520VMachineAssembler__vslot32_assembleWithPredicateClear(this, node, block, compiler)
  int *this;
  int node;
  undefined4 block;
  undefined4 compiler;
{
  int destSelect;
  int zeroInst;
  int *newInst;
  int zeroRegister;
  
  if (**(int **)(node + 0xac) == 0) {
    zeroInst = ((int (*)())R520VMachineAssembler__getOrCreateConstantZeroInst)(this);
    zeroRegister = *(int *)(zeroInst + 0x94);
    newInst = (int *)IRInst__create(0x59,compiler);
    destSelect = DAT_001b2d50;
    newInst[0x25] = zeroRegister;
    newInst[0x26] = 0;
    newInst[0x27] = destSelect;
    (**(code **)(*newInst + 0x84))(newInst,3);
    Block__appendInst(node,newInst);
  }
                    
                    
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl R300MachineAssembler__emitTexRecord");
asm(".set R300MachineAssembler__emitTexRecord, _R300MachineAssembler__emitTexRecord");
asm(".globl R300MachineAssembler__rgbSelectForLiteralFloat");
asm(".set R300MachineAssembler__rgbSelectForLiteralFloat, _R300MachineAssembler__rgbSelectForLiteralFloat");
asm(".globl R300MachineAssembler__alphaSelectForLiteralFloat");
asm(".set R300MachineAssembler__alphaSelectForLiteralFloat, _R300MachineAssembler__alphaSelectForLiteralFloat");
asm(".globl R300MachineAssembler__setTempDestination");
asm(".set R300MachineAssembler__setTempDestination, _R300MachineAssembler__setTempDestination");
asm(".globl R300MachineAssembler__setOutputDestination");
asm(".set R300MachineAssembler__setOutputDestination, _R300MachineAssembler__setOutputDestination");
asm(".globl R300MachineAssembler__assembleAluInstruction");
asm(".set R300MachineAssembler__assembleAluInstruction, _R300MachineAssembler__assembleAluInstruction");
asm(".globl R300VMachineAssembler__finishProgram");
asm(".set R300VMachineAssembler__finishProgram, _R300VMachineAssembler__finishProgram");
asm(".globl R300VMachineAssembler__logStatistics");
asm(".set R300VMachineAssembler__logStatistics, _R300VMachineAssembler__logStatistics");
asm(".globl R300VMachineAssembler__copyControlFlowToOutput");
asm(".set R300VMachineAssembler__copyControlFlowToOutput, _R300VMachineAssembler__copyControlFlowToOutput");
asm(".globl R300VMachineAssembler__clearCurrentInstruction");
asm(".set R300VMachineAssembler__clearCurrentInstruction, _R300VMachineAssembler__clearCurrentInstruction");
asm(".globl R300VMachineAssembler__vslot2_exceedsLimits");
asm(".set R300VMachineAssembler__vslot2_exceedsLimits, _R300VMachineAssembler__vslot2_exceedsLimits");
asm(".globl R300VMachineAssembler__vslot49_advanceInstruction");
asm(".set R300VMachineAssembler__vslot49_advanceInstruction, _R300VMachineAssembler__vslot49_advanceInstruction");
asm(".globl R300VMachineAssembler__vslot48_declareAndAssemble");
asm(".set R300VMachineAssembler__vslot48_declareAndAssemble, _R300VMachineAssembler__vslot48_declareAndAssemble");
asm(".globl R300VMachineAssembler__vslot15_assembleUnlessConstantMove");
asm(".set R300VMachineAssembler__vslot15_assembleUnlessConstantMove, _R300VMachineAssembler__vslot15_assembleUnlessConstantMove");
asm(".globl R300VMachineAssembler__vslot16_noOp");
asm(".set R300VMachineAssembler__vslot16_noOp, _R300VMachineAssembler__vslot16_noOp");
asm(".globl R300VMachineAssembler__vslot18_callSlot14");
asm(".set R300VMachineAssembler__vslot18_callSlot14, _R300VMachineAssembler__vslot18_callSlot14");
asm(".globl R300VMachineAssembler__vslot19_callSlot14");
asm(".set R300VMachineAssembler__vslot19_callSlot14, _R300VMachineAssembler__vslot19_callSlot14");
asm(".globl R300VMachineAssembler__vslot43_beginLoop");
asm(".set R300VMachineAssembler__vslot43_beginLoop, _R300VMachineAssembler__vslot43_beginLoop");
asm(".globl R300VMachineAssembler__vslot44_endLoopBody");
asm(".set R300VMachineAssembler__vslot44_endLoopBody, _R300VMachineAssembler__vslot44_endLoopBody");
asm(".globl R300VMachineAssembler__vslot45_endLoop");
asm(".set R300VMachineAssembler__vslot45_endLoop, _R300VMachineAssembler__vslot45_endLoop");
asm(".globl R300VMachineAssembler__vslot46_leaveLoop");
asm(".set R300VMachineAssembler__vslot46_leaveLoop, _R300VMachineAssembler__vslot46_leaveLoop");
asm(".globl R300VMachineAssembler__vslot27_assembleOrFail");
asm(".set R300VMachineAssembler__vslot27_assembleOrFail, _R300VMachineAssembler__vslot27_assembleOrFail");
asm(".globl R300VMachineAssembler__vslot25_assembleOrFail");
asm(".set R300VMachineAssembler__vslot25_assembleOrFail, _R300VMachineAssembler__vslot25_assembleOrFail");
asm(".globl R300VMachineAssembler__vslot28_assembleChildOrFail");
asm(".set R300VMachineAssembler__vslot28_assembleChildOrFail, _R300VMachineAssembler__vslot28_assembleChildOrFail");
asm(".globl R300VMachineAssembler__vslot38_appendCallEntry");
asm(".set R300VMachineAssembler__vslot38_appendCallEntry, _R300VMachineAssembler__vslot38_appendCallEntry");
asm(".globl R300VMachineAssembler__vslot42_noOp");
asm(".set R300VMachineAssembler__vslot42_noOp, _R300VMachineAssembler__vslot42_noOp");
asm(".globl R300VMachineAssembler__init");
asm(".set R300VMachineAssembler__init, _R300VMachineAssembler__init");
asm(".globl R300VMachineAssembler__vslot6_setLoopStack");
asm(".set R300VMachineAssembler__vslot6_setLoopStack, _R300VMachineAssembler__vslot6_setLoopStack");
asm(".globl R300VMachineAssembler__vslot24_assembleWithTarget");
asm(".set R300VMachineAssembler__vslot24_assembleWithTarget, _R300VMachineAssembler__vslot24_assembleWithTarget");
asm(".globl R300VMachineAssembler__vslot30_assembleBlockThenSlot40");
asm(".set R300VMachineAssembler__vslot30_assembleBlockThenSlot40, _R300VMachineAssembler__vslot30_assembleBlockThenSlot40");
asm(".globl R300VMachineAssembler__vslot37_patchControlFlowTarget");
asm(".set R300VMachineAssembler__vslot37_patchControlFlowTarget, _R300VMachineAssembler__vslot37_patchControlFlowTarget");
asm(".globl R300VMachineAssembler__assembleBlock");
asm(".set R300VMachineAssembler__assembleBlock, _R300VMachineAssembler__assembleBlock");
asm(".globl R300VMachineAssembler__vslot40_endControlFlowBlock");
asm(".set R300VMachineAssembler__vslot40_endControlFlowBlock, _R300VMachineAssembler__vslot40_endControlFlowBlock");
asm(".globl R300VMachineAssembler__vslot39_appendBranchEntry");
asm(".set R300VMachineAssembler__vslot39_appendBranchEntry, _R300VMachineAssembler__vslot39_appendBranchEntry");
asm(".globl R300VMachineAssembler__vslot29_endIfBlock");
asm(".set R300VMachineAssembler__vslot29_endIfBlock, _R300VMachineAssembler__vslot29_endIfBlock");
asm(".globl R300VMachineAssembler__create");
asm(".set R300VMachineAssembler__create, _R300VMachineAssembler__create");
asm(".globl MachineAssembler__dtor_19b9ac");
asm(".set MachineAssembler__dtor_19b9ac, _MachineAssembler__dtor_19b9ac");
asm(".globl R300VMachineAssembler__deleting_dtor");
asm(".set R300VMachineAssembler__deleting_dtor, _R300VMachineAssembler__deleting_dtor");
asm(".globl R300VMachineAssembler__vslot14_assembleInstruction");
asm(".set R300VMachineAssembler__vslot14_assembleInstruction, _R300VMachineAssembler__vslot14_assembleInstruction");
asm(".globl R520VMachineAssembler__vslot33_noOp");
asm(".set R520VMachineAssembler__vslot33_noOp, _R520VMachineAssembler__vslot33_noOp");
asm(".globl R520VMachineAssembler__vslot12_visitNode");
asm(".set R520VMachineAssembler__vslot12_visitNode, _R520VMachineAssembler__vslot12_visitNode");
asm(".globl R520VMachineAssembler__vslot37_closeConditional");
asm(".set R520VMachineAssembler__vslot37_closeConditional, _R520VMachineAssembler__vslot37_closeConditional");
asm(".globl R520VMachineAssembler__vslot32_assembleWithPredicateClear");
asm(".set R520VMachineAssembler__vslot32_assembleWithPredicateClear, _R520VMachineAssembler__vslot32_assembleWithPredicateClear");
