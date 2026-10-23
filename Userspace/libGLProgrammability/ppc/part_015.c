#include "decls.h"

/* _PPCRuntimeCompilerGetBaseIndexInRegister @ 0x97bda06c (16 bytes) */
int _PPCRuntimeCompilerGetBaseIndexInRegister(compiler, registerIndex)
  int compiler;
  int registerIndex;
{
  return *(undefined2 *)(registerIndex * 0x38 + compiler + 0x18);
}

/* _PPCRuntimeCompilerGetOffsetInRegister @ 0x97bda07c (88 bytes) */
int _PPCRuntimeCompilerGetOffsetInRegister(compiler, registerIndex)
  int compiler;
  int registerIndex;
{
  int registerRecord;
  int descriptorCopy [2];
  byte abStack_38 [40];
  
  registerRecord = registerIndex * 0x38 + compiler;
  _memcpy(descriptorCopy,registerRecord + 8,0x24);
  return *(undefined4 *)(descriptorCopy[0] + (uint)abStack_38[*(int *)(registerRecord + 4)] * 4);
}

/* _PPCRuntimeCompilerBuildTransferSwizzle @ 0x97bda0d4 (104 bytes) */
int _PPCRuntimeCompilerBuildTransferSwizzle(swizzleOut, sourceComponents, requestedComponents)
  undefined1 *swizzleOut;
  int sourceComponents;
  char *requestedComponents;
{
  char wantedComponent;
  uint loopIndex;
  undefined1 *swizzleLast;
  
  *swizzleOut = 0;
  swizzleOut[1] = 1;
  swizzleOut[2] = 2;
  swizzleOut[3] = 3;
  swizzleLast = swizzleOut + 3;
  do {
    wantedComponent = *requestedComponents;
    loopIndex = 0;
    requestedComponents = requestedComponents + 1;
    do {
      if (*(char *)(sourceComponents + loopIndex) == wantedComponent) {
        *swizzleOut = (char)loopIndex;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 4);
    swizzleOut = swizzleOut + 1;
    if (swizzleLast < swizzleOut) {
      return;
    }
  } while( true );
}

/* _PPCRuntimeCompilerSwizzleRegisterAV @ 0x97bda13c (2444 bytes) */
int _PPCRuntimeCompilerSwizzleRegisterAV(compiler, vectorReg, swizzle)
  int compiler;
  int vectorReg;
  uint *swizzle;
{
  uint shiftedSelectors;
  uint nextSelector;
  uint secondSelector;
  uint eqShiftB;
  uint equalRunStart;
  uint runStartOrInstWord;
  uint swizzleWordOrInst;
  uint shiftedSelectorsB;
  int srcRegB;
  int srcRegA;
  uint *codeCursor2;
  uint *codeCursor;
  int selectorBitBase;
  uint firstSelector;
  uint selectors;
  int ascendingRun;
  int equalRun;
  uint component3Selector;
  uint ascShiftB;
  uint *codeWritePtr;
  uint *nextCursor;
  uint ascShiftA;
  uint eqShiftA;
  uint *emitPtr2;
  
  swizzleWordOrInst = *swizzle;
  ascendingRun = 1;
  equalRun = 1;
  selectors = (swizzleWordOrInst & 0x3000000) << 4 | (swizzleWordOrInst & 0x30000) << 8 | (swizzleWordOrInst & 0x300) << 0xc |
          (swizzleWordOrInst & 3) << 0x10;
  runStartOrInstWord = 0;
  selectors = selectors | selectors >> 0x10;
  do {
    if (((selectors >> (runStartOrInstWord * -4 + 0x1c & 0x3f)) + 1 & 3) == (selectors >> (runStartOrInstWord * -4 + 0x18 & 0x3f) & 3)
       ) {
      selectorBitBase = runStartOrInstWord * 4 + 8;
      ascendingRun = 2;
      ascShiftA = 0x20 - selectorBitBase;
      ascShiftB = 0x1c - selectorBitBase;
      goto LAB_97bda1ac;
    }
    runStartOrInstWord = runStartOrInstWord + 1;
  } while ((int)runStartOrInstWord < 4);
  goto LAB_97bda240;
  while( true ) {
    equalRun = equalRun + 1;
    eqShiftA = eqShiftA - 4;
    eqShiftB = eqShiftB - 4;
    if (3 < equalRun) break;
LAB_97bda278:
    if ((selectors >> (eqShiftA & 0x3f) & 3) != (selectors >> (eqShiftB & 0x3f) & 3)) break;
  }
  if ((equalRunStart == 0) && (equalRun < 4)) {
    eqShiftA = 0x10;
    eqShiftB = 0xc;
    do {
      if ((selectors >> (eqShiftA & 0x3f) & 3) != (selectors >> (eqShiftB & 0x3f) & 3)) break;
      equalRun = equalRun + 1;
      equalRunStart = equalRunStart - 1 & 3;
      eqShiftA = eqShiftA + 4;
      eqShiftB = eqShiftB + 4;
    } while (equalRun < 4);
  }
  goto LAB_97bda304;
  while( true ) {
    ascendingRun = ascendingRun + 1;
    ascShiftA = ascShiftA - 4;
    ascShiftB = ascShiftB - 4;
    if (3 < ascendingRun) break;
LAB_97bda1ac:
    if (((selectors >> (ascShiftA & 0x3f)) + 1 & 3) != (selectors >> (ascShiftB & 0x3f) & 3)) break;
  }
  if ((runStartOrInstWord == 0) && (ascendingRun < 4)) {
    ascShiftA = 0x10;
    ascShiftB = 0xc;
    do {
      if (((selectors >> (ascShiftA & 0x3f)) + 1 & 3) != (selectors >> (ascShiftB & 0x3f) & 3)) break;
      ascendingRun = ascendingRun + 1;
      runStartOrInstWord = runStartOrInstWord - 1 & 3;
      ascShiftA = ascShiftA + 4;
      ascShiftB = ascShiftB + 4;
    } while (ascendingRun < 4);
  }
LAB_97bda240:
  equalRunStart = 0;
  do {
    if ((selectors >> (equalRunStart * -4 + 0x1c & 0x3f) & 3) == (selectors >> (equalRunStart * -4 + 0x18 & 0x3f) & 3)) {
      selectorBitBase = equalRunStart * 4 + 8;
      equalRun = 2;
      eqShiftA = 0x20 - selectorBitBase;
      eqShiftB = 0x1c - selectorBitBase;
      goto LAB_97bda278;
    }
    equalRunStart = equalRunStart + 1;
  } while ((int)equalRunStart < 4);
LAB_97bda304:
  if (equalRun == 4) {
    codeCursor = *(uint **)(compiler + 0xe30);
    *codeCursor = vectorReg << 0x15 | (selectors >> (equalRunStart * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | vectorReg << 0xb
              | 0x1000028c;
    *(uint **)(compiler + 0xe30) = codeCursor + 1;
    return;
  }
  if (ascendingRun == 4) {
    runStartOrInstWord = (swizzleWordOrInst & 0x3000000) >> 0x18;
    if (runStartOrInstWord == 0) {
      return;
    }
    swizzleWordOrInst = vectorReg << 0x15 | vectorReg << 0x10 | vectorReg << 0xb;
    runStartOrInstWord = runStartOrInstWord << 8;
LAB_97bda710:
    codeWritePtr = *(uint **)(compiler + 0xe30);
    runStartOrInstWord = swizzleWordOrInst | runStartOrInstWord & 0x300 | 0x1000002c;
LAB_97bdaabc:
    *codeWritePtr = runStartOrInstWord;
  }
  else {
    if (equalRun == 3) {
      swizzleWordOrInst = vectorReg << 0xb;
      runStartOrInstWord = selectors >> (equalRunStart * -4 + 0x10 & 0x3f);
      codeCursor = *(uint **)(compiler + 0xe30);
      *codeCursor = (selectors >> (equalRunStart * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | 0x600000 | swizzleWordOrInst | 0x1000028c;
      *(uint **)(compiler + 0xe30) = codeCursor + 1;
      srcRegA = vectorReg;
      if ((runStartOrInstWord & 0xf) != 0) {
        srcRegA = 4;
        codeCursor[1] = vectorReg << 0x10 | 0x800000U | swizzleWordOrInst | (runStartOrInstWord & 3) << 8 | 0x1000002c;
        *(uint **)(compiler + 0xe30) = codeCursor + 2;
      }
      codeCursor = *(uint **)(compiler + 0xe30);
      *codeCursor = vectorReg << 0x15 | 0x30000U | srcRegA << 0xb | 0x1000012c;
      codeWritePtr = codeCursor + 1;
      *(uint **)(compiler + 0xe30) = codeWritePtr;
      if (equalRunStart == 0) {
        return;
      }
      swizzleWordOrInst = vectorReg << 0x15 | vectorReg << 0x10 | swizzleWordOrInst;
      runStartOrInstWord = equalRunStart;
    }
    else {
      if (ascendingRun != 3) {
        if (equalRun == 2) {
          swizzleWordOrInst = vectorReg << 0xb;
          shiftedSelectorsB = selectors >> (equalRunStart * -4 + 0x14 & 0x3f);
          runStartOrInstWord = shiftedSelectorsB & 0xf;
          nextSelector = selectors >> (equalRunStart * -4 + 0x10 & 0x3f) & 0xf;
          codeCursor = *(uint **)(compiler + 0xe30);
          *codeCursor = (selectors >> (equalRunStart * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | 0x600000 | swizzleWordOrInst |
                    0x1000028c;
          emitPtr2 = codeCursor + 1;
          *(uint **)(compiler + 0xe30) = emitPtr2;
          if (nextSelector == (runStartOrInstWord + 1 & 3)) {
            srcRegA = vectorReg;
            if (runStartOrInstWord != 0) {
              srcRegA = 4;
              *emitPtr2 = vectorReg << 0x10 | 0x800000U | swizzleWordOrInst | (shiftedSelectorsB & 3) << 8 | 0x1000002c;
              *(uint **)(compiler + 0xe30) = codeCursor + 2;
            }
            codeCursor2 = *(uint **)(compiler + 0xe30);
            runStartOrInstWord = vectorReg << 0x15 | 0x30000U | srcRegA << 0xb | 0x1000022c;
LAB_97bda6e8:
            *codeCursor2 = runStartOrInstWord;
            nextCursor = codeCursor2 + 1;
          }
          else {
            if (nextSelector != runStartOrInstWord) {
              srcRegA = vectorReg;
              if (runStartOrInstWord != 0) {
                srcRegA = 4;
                *emitPtr2 = vectorReg << 0x10 | 0x800000U | swizzleWordOrInst | (shiftedSelectorsB & 3) << 8 | 0x1000002c;
                *(uint **)(compiler + 0xe30) = codeCursor + 2;
              }
              selectors = selectors >> (equalRunStart * -4 + 0x10 & 0x3f);
              codeCursor = *(uint **)(compiler + 0xe30);
              *codeCursor = srcRegA << 0xb | 0x1063012c;
              *(uint **)(compiler + 0xe30) = codeCursor + 1;
              srcRegA = vectorReg;
              if ((selectors & 0xf) != 0) {
                srcRegA = 4;
                codeCursor[1] = vectorReg << 0x10 | 0x800000U | swizzleWordOrInst | (selectors & 3) << 8 | 0x1000002c;
                *(uint **)(compiler + 0xe30) = codeCursor + 2;
              }
              codeCursor2 = *(uint **)(compiler + 0xe30);
              runStartOrInstWord = vectorReg << 0x15 | 0x30000U | srcRegA << 0xb | 0x1000012c;
              goto LAB_97bda6e8;
            }
            nextCursor = codeCursor + 3;
            codeCursor[2] = vectorReg << 0x15 | 0x1003222c;
            *emitPtr2 = runStartOrInstWord << 0x10 | 0x800000 | swizzleWordOrInst | 0x1000028c;
          }
          *(uint **)(compiler + 0xe30) = nextCursor;
          if (equalRunStart == 0) {
            return;
          }
          swizzleWordOrInst = vectorReg << 0x15 | vectorReg << 0x10 | swizzleWordOrInst;
          runStartOrInstWord = equalRunStart;
LAB_97bda70c:
          runStartOrInstWord = (4 - runStartOrInstWord) * 0x100;
          goto LAB_97bda710;
        }
        if (ascendingRun == 2) {
          firstSelector = selectors >> (runStartOrInstWord * -4 + 0x1c & 0x3f) & 0xf;
          srcRegA = vectorReg;
          if (firstSelector != 2) {
            codeCursor = *(uint **)(compiler + 0xe30);
            srcRegA = 3;
            *codeCursor = vectorReg << 0x10 | 0x600000U | vectorReg << 0xb | (firstSelector * 4 + 8) * 0x40 & 0x300
                      | 0x1000002c;
            *(uint **)(compiler + 0xe30) = codeCursor + 1;
          }
          shiftedSelectors = selectors >> (runStartOrInstWord * -4 + 0x14 & 0x3f);
          swizzleWordOrInst = shiftedSelectors & 0xf;
          secondSelector = selectors >> (runStartOrInstWord * -4 + 0x10 & 0x3f) & 0xf;
          if (secondSelector == (swizzleWordOrInst + 1 & 3)) {
            srcRegB = vectorReg;
            if (swizzleWordOrInst != 0) {
              codeCursor = *(uint **)(compiler + 0xe30);
              srcRegB = 4;
              *codeCursor = vectorReg << 0x10 | 0x800000U | vectorReg << 0xb | (shiftedSelectors & 3) << 8 |
                        0x1000002c;
              *(uint **)(compiler + 0xe30) = codeCursor + 1;
            }
            codeWritePtr = *(uint **)(compiler + 0xe30);
            *codeWritePtr = vectorReg << 0x15 | srcRegA << 0x10 | srcRegB << 0xb | 0x1000022c;
LAB_97bda854:
            *(uint **)(compiler + 0xe30) = codeWritePtr + 1;
          }
          else {
            if (secondSelector == swizzleWordOrInst) {
              codeCursor = *(uint **)(compiler + 0xe30);
              *codeCursor = swizzleWordOrInst << 0x10 | 0x800000 | vectorReg << 0xb | 0x1000028c;
              codeWritePtr = codeCursor + 1;
              *codeWritePtr = vectorReg << 0x15 | srcRegA << 0x10 | 0x1000222c;
              goto LAB_97bda854;
            }
            srcRegB = vectorReg;
            if (swizzleWordOrInst != 0) {
              codeCursor = *(uint **)(compiler + 0xe30);
              srcRegB = 4;
              *codeCursor = vectorReg << 0x10 | 0x800000U | vectorReg << 0xb | (shiftedSelectors & 3) << 8 |
                        0x1000002c;
              *(uint **)(compiler + 0xe30) = codeCursor + 1;
            }
            selectors = selectors >> (runStartOrInstWord * -4 + 0x10 & 0x3f);
            codeCursor = *(uint **)(compiler + 0xe30);
            *codeCursor = srcRegA << 0x10 | srcRegB << 0xb | 0x1060012c;
            *(uint **)(compiler + 0xe30) = codeCursor + 1;
            srcRegA = vectorReg;
            if ((selectors & 0xf) != 0) {
              srcRegA = 4;
              codeCursor[1] = vectorReg << 0x10 | 0x800000U | vectorReg << 0xb | (selectors & 3) << 8 |
                          0x1000002c;
              *(uint **)(compiler + 0xe30) = codeCursor + 2;
            }
            codeCursor = *(uint **)(compiler + 0xe30);
            *codeCursor = vectorReg << 0x15 | 0x30000U | srcRegA << 0xb | 0x1000012c;
            *(uint **)(compiler + 0xe30) = codeCursor + 1;
          }
          if (runStartOrInstWord == 0) {
            return;
          }
          swizzleWordOrInst = vectorReg << 0x15 | vectorReg << 0x10 | vectorReg << 0xb;
          goto LAB_97bda70c;
        }
        component3Selector = (swizzleWordOrInst & 0x3000000) >> 0x18;
        srcRegA = vectorReg;
        if (component3Selector != 3) {
          codeCursor = *(uint **)(compiler + 0xe30);
          srcRegA = 3;
          *codeCursor = vectorReg << 0x10 | 0x600000U | vectorReg << 0xb | (component3Selector * 4 + 4) * 0x40 & 0x300 |
                    0x1000002c;
          *(uint **)(compiler + 0xe30) = codeCursor + 1;
        }
        srcRegB = vectorReg;
        if ((swizzleWordOrInst & 0x30000) != 0) {
          codeCursor = *(uint **)(compiler + 0xe30);
          srcRegB = 4;
          *codeCursor = vectorReg << 0x10 | 0x800000U | vectorReg << 0xb | ((swizzleWordOrInst & 0x30000) >> 0x10) << 8
                    | 0x1000002c;
          *(uint **)(compiler + 0xe30) = codeCursor + 1;
        }
        codeCursor = *(uint **)(compiler + 0xe30);
        *codeCursor = srcRegA << 0x10 | srcRegB << 0xb | 0x1060012c;
        *(uint **)(compiler + 0xe30) = codeCursor + 1;
        srcRegA = vectorReg;
        if ((swizzleWordOrInst & 0x300) != 0) {
          srcRegA = 4;
          codeCursor[1] = vectorReg << 0x10 | 0x800000U | vectorReg << 0xb | swizzleWordOrInst & 0x300 | 0x1000002c;
          *(uint **)(compiler + 0xe30) = codeCursor + 2;
        }
        codeCursor = *(uint **)(compiler + 0xe30);
        *codeCursor = srcRegA << 0xb | 0x1063012c;
        *(uint **)(compiler + 0xe30) = codeCursor + 1;
        srcRegA = vectorReg;
        if ((swizzleWordOrInst & 3) != 0) {
          srcRegA = 4;
          codeCursor[1] = vectorReg << 0x10 | 0x800000U | vectorReg << 0xb | (swizzleWordOrInst & 3) << 8 | 0x1000002c;
          *(uint **)(compiler + 0xe30) = codeCursor + 2;
        }
        codeWritePtr = *(uint **)(compiler + 0xe30);
        runStartOrInstWord = vectorReg << 0x15 | 0x30000U | srcRegA << 0xb | 0x1000012c;
        goto LAB_97bdaabc;
      }
      firstSelector = selectors >> (runStartOrInstWord * -4 + 0x1c & 0x3f) & 0xf;
      srcRegA = vectorReg;
      if (firstSelector != 1) {
        codeCursor = *(uint **)(compiler + 0xe30);
        srcRegA = 3;
        *codeCursor = vectorReg << 0x10 | 0x600000U | vectorReg << 0xb | (firstSelector * 4 + 0xc) * 0x40 & 0x300 |
                  0x1000002c;
        *(uint **)(compiler + 0xe30) = codeCursor + 1;
      }
      selectors = selectors >> (runStartOrInstWord * -4 + 0x10 & 0x3f);
      srcRegB = vectorReg;
      if ((selectors & 0xf) != 0) {
        codeCursor = *(uint **)(compiler + 0xe30);
        srcRegB = 4;
        *codeCursor = vectorReg << 0x10 | 0x800000U | vectorReg << 0xb | (selectors & 3) << 8 | 0x1000002c;
        *(uint **)(compiler + 0xe30) = codeCursor + 1;
      }
      codeCursor = *(uint **)(compiler + 0xe30);
      *codeCursor = vectorReg << 0x15 | srcRegA << 0x10 | srcRegB << 0xb | 0x1000012c;
      codeWritePtr = codeCursor + 1;
      *(uint **)(compiler + 0xe30) = codeWritePtr;
      if (runStartOrInstWord == 0) {
        return;
      }
      swizzleWordOrInst = vectorReg << 0x15 | vectorReg << 0x10 | vectorReg << 0xb;
    }
    *codeWritePtr = swizzleWordOrInst | (4 - runStartOrInstWord) * 0x100 & 0x300 | 0x1000002c;
  }
  *(uint **)(compiler + 0xe30) = codeWritePtr + 1;
  return;
}

/* _PPCRuntimeCompilerFindVariableInfo @ 0x97bdaac8 (88 bytes) */
int _PPCRuntimeCompilerFindVariableInfo(compiler, variableKey, leftoverR5, leftoverR6, leftoverR7, leftoverR8, leftoverR9, leftoverR10)
  int compiler;
  int variableKey;
  undefined4 leftoverR5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  undefined4 leftoverR9;
  undefined4 leftoverR10;
{
  int *variableEntry;
  uint loopIndex;
  
  loopIndex = 0;
  variableEntry = *(int **)(compiler + 0xe00);
  if (*(uint *)(compiler + 0xe04) != 0) {
    do {
      if (variableKey == *variableEntry) {
        return variableEntry;
      }
      loopIndex = loopIndex + 1;
      variableEntry = variableEntry + 2;
    } while (loopIndex < *(uint *)(compiler + 0xe04));
  }
  return (int *)0x0;
}

/* _PPCRuntimeCompilerLoadSourceNO @ 0x97bdab20 (348 bytes) */
int _PPCRuntimeCompilerLoadSourceNO(compiler, opOffsets, opBank, opSwizzle, opIndexInfo, opStorage, opFlags5, opType, opWord7, opWord8, element, sourceSlot)
  int compiler;
  undefined4 opOffsets;
  undefined4 opBank;
  undefined4 opSwizzle;
  undefined4 opIndexInfo;
  undefined4 opStorage;
  undefined4 opFlags5;
  undefined4 opType;
  undefined4 opWord7;
  undefined4 opWord8;
  undefined4 element;
  int sourceSlot;
{
  int chunkIndex;
  uint loopIndex;
  int firstRegister;
  undefined *negateTemplate;
  undefined4 codeCursor;
  int registerIndex;
  uint loopIndex2;
  uint nextElement;
  undefined4 opOffsetsCopy;
  undefined4 opBankCopy;
  undefined4 opSwizzleCopy;
  undefined4 opIndexInfoCopy;
  undefined4 opStorageCopy;
  undefined4 opFlags5Copy;
  undefined4 opTypeCopy;
  
  firstRegister = sourceSlot * 4;
  opOffsetsCopy = opOffsets;
  opBankCopy = opBank;
  opSwizzleCopy = opSwizzle;
  opIndexInfoCopy = opIndexInfo;
  opStorageCopy = opStorage;
  opFlags5Copy = opFlags5;
  opTypeCopy = opType;
  if ((*(uint *)(compiler + 0xe50) & 4) != 0) {
    loopIndex = 0;
    do {
      registerIndex = firstRegister + loopIndex;
      _PPCRuntimeCompilerBackupRegister(compiler,registerIndex);
      loopIndex = loopIndex + 1;
      _PPCRuntimeCompilerDirtyRegister(compiler,registerIndex);
    } while (loopIndex < 4);
  }
  loopIndex2 = 0;
  do {
    nextElement = loopIndex2 + 1;
    _PPCRuntimeCompilerLoadRegister
              (compiler,firstRegister + loopIndex2,opOffsetsCopy,opBankCopy,opSwizzleCopy,opIndexInfoCopy,
               opStorageCopy,opFlags5Copy,opTypeCopy,opWord7,opWord8,loopIndex2);
    loopIndex2 = nextElement;
  } while (nextElement < 4);
  if ((*(unsigned char *)((unsigned char *)&(opStorageCopy) + 2)) == '\0') {
    return;
  }
  if (sourceSlot == 0) {
    codeCursor = *(undefined4 *)(compiler + 0xe30);
    negateTemplate = &_glpNegateSourceARTC;
  }
  else if (sourceSlot == 1) {
    codeCursor = *(undefined4 *)(compiler + 0xe30);
    negateTemplate = &_glpNegateSourceBRTC;
  }
  else {
    if (sourceSlot != 2) goto LAB_97bdac4c;
    codeCursor = *(undefined4 *)(compiler + 0xe30);
    negateTemplate = &_glpNegateSourceCRTC;
  }
  chunkIndex = _glpRTCAddAChunk_97bd7cbc(negateTemplate,codeCursor);
  *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + chunkIndex * 4;
LAB_97bdac4c:
  loopIndex = 0;
  do {
    registerIndex = firstRegister + loopIndex;
    loopIndex = loopIndex + 1;
    _PPCRuntimeCompilerDirtyRegister(compiler,registerIndex);
  } while (loopIndex < 4);
  return;
}

/* _PPCRuntimeCompilerLoadSourceAV @ 0x97bdac7c (268 bytes) */
int _PPCRuntimeCompilerLoadSourceAV(compiler, opOffsets, opBank, opSwizzle, opIndexInfo, opStorage, opFlags5, opType, opWord7, opWord8, element, sourceSlot)
  int compiler;
  int opOffsets;
  undefined4 opBank;
  undefined4 opSwizzle;
  undefined4 opIndexInfo;
  undefined4 opStorage;
  undefined4 opFlags5;
  undefined4 opType;
  undefined4 opWord7;
  undefined4 opWord8;
  int element;
  int sourceSlot;
{
  uint *codeCursor;
  int iStack0000001c;
  undefined4 opBankCopy;
  undefined4 opSwizzleCopy;
  undefined4 opIndexInfoCopy;
  undefined4 opStorageCopy;
  undefined4 opFlags5Copy;
  undefined4 opTypeCopy;
  
  iStack0000001c = opOffsets;
  opBankCopy = opBank;
  opSwizzleCopy = opSwizzle;
  opIndexInfoCopy = opIndexInfo;
  opStorageCopy = opStorage;
  opFlags5Copy = opFlags5;
  opTypeCopy = opType;
  if ((*(uint *)(compiler + 0xe50) & 4) != 0) {
    _PPCRuntimeCompilerBackupRegister(compiler,sourceSlot);
    _PPCRuntimeCompilerDirtyRegister(compiler,sourceSlot);
  }
  iStack0000001c = iStack0000001c + element * 0x10;
  _PPCRuntimeCompilerLoadRegister
            (compiler,sourceSlot,iStack0000001c,opBankCopy,opSwizzleCopy,opIndexInfoCopy,
             opStorageCopy,opFlags5Copy,opTypeCopy,opWord7,opWord8,0);
  if ((*(unsigned char *)((unsigned char *)&(opStorageCopy) + 2)) != '\0') {
    codeCursor = *(uint **)(compiler + 0xe30);
    *codeCursor = sourceSlot << 0x15 | sourceSlot << 0x10 | 0x10003cc4;
    *(uint **)(compiler + 0xe30) = codeCursor + 1;
    _PPCRuntimeCompilerDirtyRegister(compiler,sourceSlot);
    return;
  }
  return;
}

/* _PPCRuntimeCompilerWriteDestinationNO @ 0x97bdad88 (368 bytes) */
int _PPCRuntimeCompilerWriteDestinationNO(compiler, destIndex)
  int compiler;
  int destIndex;
{
  uint *codeCursor;
  uint storeRsField;
  uint loopIndex;
  int destDescWord0;
  undefined4 destDescWord1;
  undefined4 destDescWord2;
  undefined4 destDescWord3;
  undefined4 destDescWord4;
  undefined4 destDescWord5;
  undefined4 destDescWord6;
  undefined4 destDescWord7;
  undefined4 destDescWord8;
  
  _memcpy(&destDescWord0,*(int *)(compiler + 0xe28) + 0xc,0x24);
  storeRsField = 0x2000000;
  _PPCRuntimeCompilerDirtyRegister(compiler,0x10);
  _PPCRuntimeCompilerDirtyRegister(compiler,0x11);
  _PPCRuntimeCompilerDirtyRegister(compiler,0x12);
  _PPCRuntimeCompilerDirtyRegister(compiler,0x13);
  loopIndex = 0;
  do {
    if (((*(unsigned char *)((unsigned char *)&(destDescWord7) + 0)) >> (loopIndex & 0x3f) & 1) != 0) {
      if (((*(unsigned short *)((unsigned char *)&(destDescWord4) + 0)) == 1) || ((*(uint *)(compiler + 0xe50) & 4) == 0)) {
        codeCursor = *(uint **)(compiler + 0xe30);
        *codeCursor = storeRsField | (uint)(ushort)((*(unsigned short *)((unsigned char *)&(destDescWord4) + 0)) + 5) << 0x10 |
                  *(uint *)(loopIndex * 4 + destDescWord0 + destIndex * 0x10) & 0xffff | 0xd0000000;
        *(uint **)(compiler + 0xe30) = codeCursor + 1;
      }
      else {
        _PPCRuntimeCompilerDirtyRegistersWithData
                  (compiler,destDescWord0,destDescWord1,destDescWord2,destDescWord3,destDescWord4,destDescWord5,destDescWord6,destDescWord7,
                   destDescWord8,loopIndex);
        _PPCRuntimeCompilerSetRegister
                  (compiler,loopIndex + 0x10,destDescWord0,destDescWord1,destDescWord2,destDescWord3,destDescWord4,destDescWord5,
                   destDescWord6,destDescWord7,destDescWord8,0,loopIndex);
      }
    }
    loopIndex = loopIndex + 1;
    storeRsField = storeRsField + 0x200000;
  } while (loopIndex < 4);
  return;
}

/* _PPCRuntimeCompilerWriteDestinationAV @ 0x97bdaef8 (748 bytes) */
int _PPCRuntimeCompilerWriteDestinationAV(compiler, destIndex)
  int compiler;
  int destIndex;
{
  undefined4 *codeWritePtr;
  undefined4 *codeCursor;
  int instruction;
  undefined4 maskWord;
  undefined4 leftoverR4;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  undefined4 leftoverR9;
  undefined4 *swizzleDescPtr;
  undefined4 leftoverR10;
  int codeCursor2;
  int chunkBytes;
  int destDescWord0;
  undefined4 destDescWord1;
  undefined4 destDescWord2;
  undefined4 destDescWord3;
  undefined4 destDescWord4;
  undefined4 destDescWord5;
  undefined4 destDescWord6;
  uint destDescWord7;
  undefined4 destDescWord8;
  
  instruction = *(int *)(compiler + 0xe28);
  _memcpy(&destDescWord0,instruction + 0xc,0x24);
  destDescWord0 = destDescWord0 + destIndex * 0x10;
  _PPCRuntimeCompilerDirtyRegister(compiler,2);
  swizzleDescPtr = &destDescWord2;
  ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(compiler,2,swizzleDescPtr);
  _PPEmulatorVariableSwizzleFromMask(&destDescWord0,leftoverR4,swizzleDescPtr,leftoverR6,leftoverR7,leftoverR8,leftoverR9,leftoverR10);
  if (*(char *)(instruction + 6) != '\0') {
    chunkBytes = _glpRTCAddAChunk_97bd7cbc
                      (&_glpOpBuildConditionCodeAVRTC,*(undefined4 *)(compiler + 0xe30));
    codeCursor2 = *(int *)(compiler + 0xe30);
    chunkBytes = chunkBytes * 4;
    codeWritePtr = (undefined4 *)(codeCursor2 + chunkBytes);
    *(undefined4 **)(compiler + 0xe30) = codeWritePtr;
    if ((*(unsigned char *)((unsigned char *)&(destDescWord7) + 0)) == '\x0f') {
      *(undefined4 *)(codeCursor2 + chunkBytes) = 0x12852c84;
    }
    else {
      *(undefined4 *)(codeCursor2 + chunkBytes) = 0x10836a8c;
      *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 2;
      maskWord = 0x1063212c;
      if ((destDescWord7 & 0x1000000) == 0) {
        maskWord = 0x1063492c;
      }
      codeWritePtr[1] = maskWord;
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      maskWord = 0x1063212c;
      *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
      if ((destDescWord7 & 0x2000000) == 0) {
        maskWord = 0x1063492c;
      }
      *codeCursor = maskWord;
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      maskWord = 0x1063212c;
      *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
      if ((destDescWord7 & 0x4000000) == 0) {
        maskWord = 0x1063492c;
      }
      *codeCursor = maskWord;
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      maskWord = 0x1063212c;
      *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
      if ((destDescWord7 & 0x8000000) == 0) {
        maskWord = 0x1063492c;
      }
      *codeCursor = maskWord;
      codeWritePtr = *(undefined4 **)(compiler + 0xe30);
      *codeWritePtr = 0x129428ea;
    }
    *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 1;
  }
  if ((char)destDescWord4 != '\0') {
    _PPCRuntimeCompilerSaveAllTemporariesToMemory(compiler);
  }
  if (((((*(unsigned short *)((unsigned char *)&(destDescWord4) + 0)) == 1) || ((*(unsigned short *)((unsigned char *)&(destDescWord4) + 0)) == 9)) || ((*(uint *)(compiler + 0xe50) & 4) == 0))
     || ((destDescWord4 & 0xff) != 0)) {
    _PPCRuntimeCompilerSetRegister
              (compiler,2,destDescWord0,destDescWord1,destDescWord2,destDescWord3,destDescWord4,destDescWord5,destDescWord6,destDescWord7,
               destDescWord8,0,0);
    _PPCRuntimeCompilerSaveRegisterToMemory(compiler,2);
    _PPCRuntimeCompilerDirtyRegistersWithData
              (compiler,destDescWord0,destDescWord1,destDescWord2,destDescWord3,destDescWord4,destDescWord5,destDescWord6,destDescWord7,
               destDescWord8,0);
  }
  else {
    _PPCRuntimeCompilerDirtyRegistersWithData
              (compiler,destDescWord0,destDescWord1,destDescWord2,destDescWord3,destDescWord4,destDescWord5,destDescWord6,destDescWord7,
               destDescWord8,0);
    _PPCRuntimeCompilerSetRegister
              (compiler,2,destDescWord0,destDescWord1,destDescWord2,destDescWord3,destDescWord4,destDescWord5,destDescWord6,destDescWord7,
               destDescWord8,0,0);
  }
  return;
}

/* _PPCRuntimeCompilerTestConditionRegisterAV @ 0x97bdb1e4 (576 bytes) */
int _PPCRuntimeCompilerTestConditionRegisterAV(compiler, condDescWord0, condDescWord1, condDescWord2, condDescWord3, condDescWord4, condDescWord5, condDescWord6, conditionWord)
  int compiler;
  undefined4 condDescWord0;
  undefined4 condDescWord1;
  undefined4 condDescWord2;
  undefined4 condDescWord3;
  undefined4 condDescWord4;
  undefined4 condDescWord5;
  undefined4 condDescWord6;
  uint conditionWord;
{
  uint *codeCursor2;
  uint testWord;
  undefined4 *codeCursor;
  uint *codeWritePtr;
  undefined4 condDescWord0Copy;
  undefined4 condDescWord1Copy;
  undefined4 condDescWord2Copy;
  undefined4 condDescWord3Copy;
  undefined4 condDescWord4Copy;
  undefined4 condDescWord5Copy;
  undefined4 condDescWord6Copy;
  
  condDescWord0Copy = condDescWord0;
  condDescWord1Copy = condDescWord1;
  condDescWord2Copy = condDescWord2;
  condDescWord3Copy = condDescWord3;
  condDescWord4Copy = condDescWord4;
  condDescWord5Copy = condDescWord5;
  condDescWord6Copy = condDescWord6;
  switch(conditionWord >> 0x10 & 0xff) {
  case 0:
    codeWritePtr = *(uint **)(compiler + 0xe30);
    testWord = 0x10636a8c;
    goto LAB_97bdb424;
  case 1:
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x10b4a484;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(compiler,5,(int)&conditionWord + 2);
    codeCursor2 = *(uint **)(compiler + 0xe30);
    testWord = 0x10600000;
    break;
  case 2:
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x10b4a484;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(compiler,5,(int)&conditionWord + 2);
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    testWord = 0x10810000;
    goto LAB_97bdb338;
  case 3:
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x10b4a484;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(compiler,5,(int)&conditionWord + 2);
    codeCursor2 = *(uint **)(compiler + 0xe30);
    testWord = 0x10610000;
    break;
  case 4:
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x10b4a484;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(compiler,5,(int)&conditionWord + 2);
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    testWord = 0x10820000;
LAB_97bdb338:
    *codeCursor = 0x1060038c;
    codeCursor[1] = testWord | 0x38c;
    codeCursor[2] = 0x10651886;
    codeCursor[3] = 0x10852086;
    codeCursor[4] = 0x10632484;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 5;
    return;
  case 5:
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x10b4a484;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(compiler,5,(int)&conditionWord + 2);
    codeCursor2 = *(uint **)(compiler + 0xe30);
    testWord = 0x10620000;
    break;
  case 6:
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x10b4a484;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(compiler,5,(int)&conditionWord + 2);
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x1060038c;
    codeCursor[1] = 0x10651886;
    codeWritePtr = codeCursor + 3;
    codeCursor[2] = 0x10631d04;
    goto LAB_97bdb42c;
  case 7:
    codeWritePtr = *(uint **)(compiler + 0xe30);
    testWord = 0x10694c84;
LAB_97bdb424:
    *codeWritePtr = testWord;
    goto LAB_97bdb428;
  default:
    goto switchD_97bdb240_default;
  }
  *codeCursor2 = testWord | 0x38c;
  codeWritePtr = codeCursor2 + 1;
  *codeWritePtr = 0x10651886;
LAB_97bdb428:
  codeWritePtr = codeWritePtr + 1;
LAB_97bdb42c:
  *(uint **)(compiler + 0xe30) = codeWritePtr;
switchD_97bdb240_default:
  return;
}

/* _PPCRuntimeCompilerWriteFinalFragmentToBuffer @ 0x97bdb444 (568 bytes) */
int _PPCRuntimeCompilerWriteFinalFragmentToBuffer(compiler, leftoverR4, leftoverR5, leftoverR6, leftoverR7, leftoverR8, leftoverR9, leftoverR10)
  int compiler;
  undefined4 leftoverR4;
  undefined4 leftoverR5;
  undefined4 leftoverR6;
  undefined4 leftoverR7;
  undefined4 leftoverR8;
  undefined4 leftoverR9;
  undefined4 leftoverR10;
{
  undefined4 ppcRasterOpMachine_BufferMaskRTCAVResult;
  undefined4 ppcRasterOpMachine_LogicOpRTCAVResult;
  undefined4 ppcRasterOpMachine_BlendingRTCAVResult;
  undefined4 ppcRasterOpMachine_DepthAndStencilTestRTCAVResult;
  undefined4 *lastWordPtr;
  int convertInWordCount;
  undefined4 *codeCursor;
  int convertWordCount;
  bool colorMaskActive;
  bool logicOpActive;
  undefined4 ppcRasterOpMachine_AlphaTestRTCAVResult;
  uint framebufferFormat;
  undefined4 *cursorAfterFormatConvert;
  int emulator;
  
  emulator = *(int *)(compiler + 0xe20);
  colorMaskActive = false;
  if (((*(uint *)(*(int *)(emulator + 0xd80) + 0x3c) & 0x40) != 0) &&
     ((*(uint *)(*(int *)(emulator + 0xd80) + 0x70) & 0x1e0000) != 0x1e0000)) {
    colorMaskActive = true;
  }
  logicOpActive = false;
  if (((*(uint *)(*(int *)(emulator + 0xd80) + 0x3c) & 0x20) != 0) &&
     (3 < (*(uint *)(*(int *)(emulator + 0xd80) + 0x68) & 0xf))) {
    logicOpActive = true;
  }
  if ((*(uint *)(*(int *)(emulator + 0xd80) + 0x3c) & 1) != 0) {
    ppcRasterOpMachine_AlphaTestRTCAVResult = ((int (*)())_PPCRasterOpMachine_AlphaTestRTCAV)(compiler + 0xe14,*(undefined4 *)(compiler + 0xe30));
    emulator = *(int *)(compiler + 0xe20);
    *(undefined4 *)(compiler + 0xe30) = ppcRasterOpMachine_AlphaTestRTCAVResult;
  }
  if ((*(uint *)(*(int *)(emulator + 0xd80) + 0x3c) & 6) != 0) {
    ppcRasterOpMachine_DepthAndStencilTestRTCAVResult = ((int (*)())_PPCRasterOpMachine_DepthAndStencilTestRTCAV)(compiler + 0xe14,*(undefined4 *)(compiler + 0xe30));
    emulator = *(int *)(compiler + 0xe20);
    *(undefined4 *)(compiler + 0xe30) = ppcRasterOpMachine_DepthAndStencilTestRTCAVResult;
  }
  if ((((*(uint *)(*(int *)(emulator + 0xd80) + 0x3c) & 8) != 0) || (logicOpActive)) || (colorMaskActive)) {
    framebufferFormat = _PPEmulatorFramebufferFormat(emulator);
    if ((framebufferFormat & 0x8000) == 0) {
      framebufferFormat = _PPEmulatorFramebufferFormat(*(undefined4 *)(compiler + 0xe20));
      if ((framebufferFormat & 0x8000000) != 0) {
        codeCursor = *(undefined4 **)(compiler + 0xe30);
        *codeCursor = 0x7c4030ce;
        *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
      }
    }
    else {
      convertInWordCount = _glpRTCAddAChunk_97bd7cbc
                        (&_glpOpConvertARGB8888ToRGBAFFFF,*(undefined4 *)(compiler + 0xe30));
      *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + convertInWordCount * 4;
    }
    emulator = *(int *)(compiler + 0xe20);
  }
  if ((*(uint *)(*(int *)(emulator + 0xd80) + 0x3c) & 8) != 0) {
    ppcRasterOpMachine_BlendingRTCAVResult = ((int (*)())_PPCRasterOpMachine_BlendingRTCAV)(compiler + 0xe14,*(undefined4 *)(compiler + 0xe30));
    emulator = *(int *)(compiler + 0xe20);
    *(undefined4 *)(compiler + 0xe30) = ppcRasterOpMachine_BlendingRTCAVResult;
  }
  if ((*(uint *)(*(int *)(emulator + 0xd80) + 0x3c) & 0x20) != 0) {
    ppcRasterOpMachine_LogicOpRTCAVResult = ((int (*)())_PPCRasterOpMachine_LogicOpRTCAV)(compiler + 0xe14,*(undefined4 *)(compiler + 0xe30));
    *(undefined4 *)(compiler + 0xe30) = ppcRasterOpMachine_LogicOpRTCAVResult;
  }
  if (colorMaskActive) {
    ppcRasterOpMachine_BufferMaskRTCAVResult = ((int (*)())_PPCRasterOpMachine_BufferMaskRTCAV)(compiler + 0xe14,*(undefined4 *)(compiler + 0xe30));
    *(undefined4 *)(compiler + 0xe30) = ppcRasterOpMachine_BufferMaskRTCAVResult;
  }
  framebufferFormat = _PPEmulatorFramebufferFormat(*(undefined4 *)(compiler + 0xe20));
  if ((framebufferFormat & 0x8000) == 0) {
    framebufferFormat = _PPEmulatorFramebufferFormat(*(undefined4 *)(compiler + 0xe20));
    if ((framebufferFormat & 0x8000000) == 0) {
      return;
    }
    lastWordPtr = *(undefined4 **)(compiler + 0xe30);
    *lastWordPtr = 0x7e6031ce;
  }
  else {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x10739c84;
    cursorAfterFormatConvert = codeCursor + 1;
    *(undefined4 **)(compiler + 0xe30) = cursorAfterFormatConvert;
    convertWordCount = _glpRTCAddAChunk_97bd7cbc(&_glpOpConvertRGBAFFFFToARGB8888,cursorAfterFormatConvert);
    lastWordPtr = (undefined4 *)(*(int *)(compiler + 0xe30) + convertWordCount * 4);
    *(undefined4 *)(*(int *)(compiler + 0xe30) + convertWordCount * 4) = 0x7c60318e;
  }
  *(undefined4 **)(compiler + 0xe30) = lastWordPtr + 1;
  return;
}

/* _PPCRuntimeCompilerWritePrologNO @ 0x97bdb67c (828 bytes) */
int _PPCRuntimeCompilerWritePrologNO(compiler)
  int compiler;
{
  int programInfo;
  int gprCountdown;
  int ppcInstWord;
  int regIndex;
  int codeCursor3;
  int chunkIndex;
  uint *codeCursor2;
  undefined4 *codeCursor;
  uint saveOffset;
  int *fprSlotPtr;
  int fprCountdown;
  uint fprIndex;
  int programInfo2;
  
  gprCountdown = 0x13;
  regIndex = 0xd;
  saveOffset = 0x284;
  do {
    if ((regIndex != 0x10) || ((*(uint *)(*(int *)(compiler + 0xe24) + 0x34) & 0x200) != 0)) {
      codeCursor2 = *(uint **)(compiler + 0xe30);
      *codeCursor2 = regIndex << 0x15 | saveOffset & 0xffff | 0x90030000;
      *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
    }
    regIndex = regIndex + 1;
    saveOffset = saveOffset + 4;
    gprCountdown = gprCountdown + -1;
  } while (gprCountdown != 0);
  fprIndex = 0xe;
  fprCountdown = 0x12;
  saveOffset = 0x308;
  fprSlotPtr = (int *)(compiler + 0x33c);
  do {
    if ((fprIndex < 0x14) || (*fprSlotPtr != 0)) {
      codeCursor2 = *(uint **)(compiler + 0xe30);
      *codeCursor2 = fprIndex << 0x15 | saveOffset & 0xffff | 0xd0030000;
      *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
    }
    fprIndex = fprIndex + 1;
    fprSlotPtr = fprSlotPtr + 0xe;
    saveOffset = saveOffset + 4;
    fprCountdown = fprCountdown + -1;
  } while (fprCountdown != 0);
  if ((*(uint *)(*(int *)(compiler + 0xe24) + 0x34) & 0x400) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0xfd00048e;
    codeCursor[1] = 0xd1030350;
    codeCursor[2] = 0xffc0004c;
    codeCursor[3] = 0xffe0004c;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 4;
  }
  codeCursor = *(undefined4 **)(compiler + 0xe30);
  *codeCursor = 0x80430d9c;
  programInfo = *(int *)(compiler + 0xe24);
  *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  if ((*(uint *)(programInfo + 0x34) & 1) != 0) {
    codeCursor[1] = 0x80a30d84;
    programInfo = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
  }
  if ((*(uint *)(programInfo + 0x34) & 2) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x80c30d88;
    programInfo = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(programInfo + 0x34) & 4) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x80e30d8c;
    programInfo = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(programInfo + 0x34) & 8) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81030d90;
    programInfo = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(programInfo + 0x34) & 0x10) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81230d94;
    programInfo = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(programInfo + 0x34) & 0x20) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81430d98;
    programInfo = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if (((*(int *)(programInfo + 0x38) == 0x8804) || (*(int *)(programInfo + 0x38) == 0x8b30)) &&
     ((*(uint *)(programInfo + 0x34) & 0x1004) != 0)) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81830da4;
    codeCursor[1] = 0x81a30da0;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
  }
  chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpLoadOneAndZeroRTC,*(undefined4 *)(compiler + 0xe30));
  codeCursor3 = *(int *)(compiler + 0xe30);
  *(undefined4 *)(codeCursor3 + chunkIndex * 4) = 0x7c8903a6;
  ppcInstWord = codeCursor3 + chunkIndex * 4;
  programInfo2 = *(int *)(compiler + 0xe24);
  *(int *)(compiler + 0xe30) = ppcInstWord + 4;
  if ((*(int *)(programInfo2 + 0x38) != 0x8804) && (*(int *)(programInfo2 + 0x38) != 0x8b30)) {
    *(undefined4 *)(ppcInstWord + 4) = 0x3a2000ff;
    *(undefined4 *)(ppcInstWord + 8) = 0x3a400000;
    programInfo2 = *(int *)(compiler + 0xe24);
    *(int *)(compiler + 0xe30) = ppcInstWord + 0xc;
  }
  if ((*(int *)(programInfo2 + 0x38) == 0x8804) || (*(int *)(programInfo2 + 0x38) == 0x8b30)) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0xfd805890;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  return;
}

/* _PPCRuntimeCompilerWriteEpilogNO @ 0x97bdb9b8 (352 bytes) */
int _PPCRuntimeCompilerWriteEpilogNO(compiler)
  int compiler;
{
  int programInfo;
  int regIndex;
  undefined4 *codeCursor;
  int fprCountdown;
  uint *codeCursor2;
  uint saveOffset;
  int *fprSlotPtr;
  uint fprIndex;
  int gprCountdown;
  
  programInfo = *(int *)(compiler + 0xe24);
  if ((*(int *)(programInfo + 0x38) != 0x8804) && (*(int *)(programInfo + 0x38) != 0x8b30)) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x39e00008;
    codeCursor[1] = 0x7e317830;
    codeCursor[2] = 0x7e259378;
    programInfo = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 3;
  }
  if ((*(uint *)(programInfo + 0x34) & 0x400) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0xc1030350;
    codeCursor[1] = 0xfdfe458e;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
  }
  regIndex = 0xd;
  gprCountdown = 0x13;
  saveOffset = 0x284;
  do {
    if ((regIndex != 0x10) || ((*(uint *)(*(int *)(compiler + 0xe24) + 0x34) & 0x200) != 0)) {
      codeCursor2 = *(uint **)(compiler + 0xe30);
      *codeCursor2 = regIndex << 0x15 | saveOffset & 0xffff | 0x80030000;
      *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
    }
    regIndex = regIndex + 1;
    saveOffset = saveOffset + 4;
    gprCountdown = gprCountdown + -1;
  } while (gprCountdown != 0);
  fprIndex = 0xe;
  fprCountdown = 0x12;
  saveOffset = 0x308;
  fprSlotPtr = (int *)(compiler + 0x33c);
  do {
    if ((fprIndex < 0x14) || (*fprSlotPtr != 0)) {
      codeCursor2 = *(uint **)(compiler + 0xe30);
      *codeCursor2 = fprIndex << 0x15 | saveOffset & 0xffff | 0xc0030000;
      *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
    }
    fprIndex = fprIndex + 1;
    fprSlotPtr = fprSlotPtr + 0xe;
    saveOffset = saveOffset + 4;
    fprCountdown = fprCountdown + -1;
  } while (fprCountdown != 0);
  codeCursor = *(undefined4 **)(compiler + 0xe30);
  *codeCursor = 0x7ca32b78;
  codeCursor[1] = 0x4e800020;
  *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
  return;
}

/* _PPCRuntimeCompilerWritePrologAV @ 0x97bdbb18 (1132 bytes) */
int _PPCRuntimeCompilerWritePrologAV(compiler)
  int compiler;
{
  int programInfo2;
  int programInfo;
  int regIndex;
  undefined4 *codeCursor;
  uint framebufferFormat;
  int chunkIndex;
  undefined4 *cursorAfterMtctr;
  uint *codeCursor2;
  undefined4 *vectorInstWord;
  uint saveOffset;
  int codeCursor3;
  int ppcInstWord;
  int vectorSaveCountdown;
  int regCountdown;
  
  codeCursor = *(undefined4 **)(compiler + 0xe30);
  *codeCursor = 0x7c0042a6;
  vectorSaveCountdown = 0x20;
  *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  do {
    vectorSaveCountdown = vectorSaveCountdown + -1;
  } while (vectorSaveCountdown != 0);
  codeCursor = *(undefined4 **)(compiler + 0xe30);
  *codeCursor = 0x6405ffff;
  codeCursor[1] = 0x60a5ffff;
  codeCursor[2] = 0x7ca043a6;
  codeCursor[3] = 0x10ff038c;
  regCountdown = 0x13;
  codeCursor[4] = 0x10e73984;
  regIndex = 0xd;
  *(undefined4 **)(compiler + 0xe30) = codeCursor + 5;
  saveOffset = 0x284;
  do {
    if ((regIndex != 0x10) || ((*(uint *)(*(int *)(compiler + 0xe24) + 0x34) & 0x200) != 0)) {
      codeCursor2 = *(uint **)(compiler + 0xe30);
      *codeCursor2 = regIndex << 0x15 | saveOffset & 0xffff | 0x90030000;
      *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
    }
    regIndex = regIndex + 1;
    saveOffset = saveOffset + 4;
    regCountdown = regCountdown + -1;
  } while (regCountdown != 0);
  codeCursor = *(undefined4 **)(compiler + 0xe30);
  *codeCursor = 0x80430d9c;
  programInfo = *(int *)(compiler + 0xe24);
  *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  if ((*(uint *)(programInfo + 0x34) & 1) != 0) {
    codeCursor[1] = 0x80a30d84;
    programInfo = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
  }
  if ((*(uint *)(programInfo + 0x34) & 2) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x80c30d88;
    programInfo = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(programInfo + 0x34) & 4) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x80e30d8c;
    programInfo = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(programInfo + 0x34) & 8) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81030d90;
    programInfo = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(programInfo + 0x34) & 0x10) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81230d94;
    programInfo = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(programInfo + 0x34) & 0x20) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81430d98;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpLoadOneAndZeroAVRTC,*(undefined4 *)(compiler + 0xe30));
  codeCursor3 = *(int *)(compiler + 0xe30);
  programInfo2 = *(int *)(compiler + 0xe24);
  ppcInstWord = codeCursor3 + chunkIndex * 4;
  *(int *)(compiler + 0xe30) = ppcInstWord;
  if (((*(int *)(programInfo2 + 0x38) == 0x8804) || (*(int *)(programInfo2 + 0x38) == 0x8b30)) &&
     ((*(uint *)(programInfo2 + 0x34) & 0x1004) != 0)) {
    *(undefined4 *)(codeCursor3 + chunkIndex * 4) = 0x81830da4;
    *(undefined4 *)(ppcInstWord + 4) = 0x81a30da0;
    programInfo2 = *(int *)(compiler + 0xe24);
    *(int *)(compiler + 0xe30) = ppcInstWord + 8;
  }
  if ((*(int *)(programInfo2 + 0x38) != 0x8804) && (*(int *)(programInfo2 + 0x38) != 0x8b30)) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x39e01b70;
    codeCursor[1] = 0x7dcf10ce;
    codeCursor[2] = 0x39e01b80;
    codeCursor[3] = 0x7def10ce;
    codeCursor[4] = 0x39e00000;
    codeCursor[5] = 0x7e4f18ce;
    codeCursor[6] = 0x121f038c;
    codeCursor[7] = 0x12294c84;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 8;
  }
  codeCursor = *(undefined4 **)(compiler + 0xe30);
  *codeCursor = 0x7c8903a6;
  cursorAfterMtctr = codeCursor + 1;
  *(undefined4 **)(compiler + 0xe30) = cursorAfterMtctr;
  chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpLoadOneAndZeroRTC,cursorAfterMtctr);
  programInfo2 = *(int *)(compiler + 0xe24);
  *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + chunkIndex * 4;
  if ((*(int *)(programInfo2 + 0x38) == 0x8804) || (*(int *)(programInfo2 + 0x38) == 0x8b30)) {
    framebufferFormat = _PPEmulatorFramebufferFormat(*(undefined4 *)(compiler + 0xe20));
    if ((framebufferFormat & 0x8000) != 0) {
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      *codeCursor = 0x39e00040;
      codeCursor[1] = 0x7e4378ce;
      *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
    }
    programInfo2 = *(int *)(compiler + 0xe24);
  }
  if ((*(int *)(programInfo2 + 0x38) == 0x8804) || (*(int *)(programInfo2 + 0x38) == 0x8b30)) {
    if ((*(uint *)(programInfo2 + 0x34) & 4) != 0) {
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      *codeCursor = 0x7c6068ce;
      vectorInstWord = codeCursor + 1;
      *(undefined4 **)(compiler + 0xe30) = vectorInstWord;
      if ((*(uint *)(compiler + 0xe50) & 8) == 0) {
        *vectorInstWord = 0x11c9436a;
        programInfo2 = *(int *)(compiler + 0xe24);
        *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
      }
      else {
        *vectorInstWord = 0x1080190a;
        codeCursor[2] = 0x11c9236a;
        programInfo2 = *(int *)(compiler + 0xe24);
        *(undefined4 **)(compiler + 0xe30) = codeCursor + 3;
      }
    }
    if ((*(uint *)(programInfo2 + 0x34) & 0x1000) != 0) {
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      *codeCursor = 0xfd805890;
      codeCursor[1] = 0xc1ad0008;
      *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
    }
  }
  return;
}

/* _PPCRuntimeCompilerWriteEpilogAV @ 0x97bdbf84 (304 bytes) */
int _PPCRuntimeCompilerWriteEpilogAV(compiler)
  int compiler;
{
  int regIndex;
  undefined4 *codeCursor;
  int chunkIndex;
  int programTarget;
  uint *codeCursor2;
  uint saveOffset;
  undefined4 *cursorAfterMove;
  int regCountdown;
  
  programTarget = *(int *)(*(int *)(compiler + 0xe24) + 0x38);
  if ((programTarget != 0x8804) && (programTarget != 0x8b30)) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x1210486c;
    codeCursor[1] = 0x39e0020e;
    codeCursor[2] = 0x10718484;
    codeCursor[3] = 0x7c6f194e;
    codeCursor[4] = 0x7caf1a2e;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 5;
  }
  regIndex = 0xd;
  regCountdown = 0x13;
  saveOffset = 0x284;
  do {
    if ((regIndex != 0x10) || ((*(uint *)(*(int *)(compiler + 0xe24) + 0x34) & 0x200) != 0)) {
      codeCursor2 = *(uint **)(compiler + 0xe30);
      *codeCursor2 = regIndex << 0x15 | saveOffset & 0xffff | 0x80030000;
      *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
    }
    regIndex = regIndex + 1;
    saveOffset = saveOffset + 4;
    regCountdown = regCountdown + -1;
  } while (regCountdown != 0);
  codeCursor = *(undefined4 **)(compiler + 0xe30);
  *codeCursor = 0x7ca32b78;
  cursorAfterMove = codeCursor + 1;
  *(undefined4 **)(compiler + 0xe30) = cursorAfterMove;
  chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpEpilogAVRTC,cursorAfterMove);
  *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + chunkIndex * 4;
  return;
}

/* _PPCRuntimeCompilerStride @ 0x97bdc0b4 (548 bytes) */
int _PPCRuntimeCompilerStride(compiler)
  int compiler;
{
  undefined4 *codeCursor;
  ushort immediateHalf;
  uint *codeCursor2;
  int programInfo;
  undefined4 *cursorAfterOps;
  
  programInfo = *(int *)(compiler + 0xe24);
  if ((*(int *)(programInfo + 0x38) == 0x8804) || (*(int *)(programInfo + 0x38) == 0x8b30)) {
    if (*(int *)(compiler + 0xe4c) == 0) {
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      *codeCursor = 0xed8c502a;
      cursorAfterOps = codeCursor + 1;
    }
    else {
      if ((*(uint *)(programInfo + 0x34) & 4) != 0) {
        codeCursor = *(undefined4 **)(compiler + 0xe30);
        *codeCursor = 0x10684b2c;
        codeCursor[1] = 0x11ce180a;
        *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
        if ((*(uint *)(compiler + 0xe50) & 8) != 0) {
          codeCursor[2] = 0x7c6068ce;
          codeCursor[3] = 0x7c8060ce;
          codeCursor[4] = 0x10a0728c;
          codeCursor[5] = 0x10a4196e;
          codeCursor[6] = 0x10c0290a;
          codeCursor[7] = 0x11ce336a;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 8;
        }
        programInfo = *(int *)(compiler + 0xe24);
      }
      if ((*(uint *)(programInfo + 0x34) & 0x1000) == 0) goto LAB_97bdc214;
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      *codeCursor = 0xed8c502a;
      codeCursor[1] = 0xc10d0008;
      codeCursor[2] = 0xc12c0008;
      codeCursor[3] = 0xeda9433a;
      cursorAfterOps = codeCursor + 4;
    }
    *(undefined4 **)(compiler + 0xe30) = cursorAfterOps;
    programInfo = *(int *)(compiler + 0xe24);
  }
  else {
    codeCursor2 = *(uint **)(compiler + 0xe30);
    *codeCursor2 = *(ushort *)(programInfo + 0xbe) | 0x38e70000;
    programInfo = *(int *)(compiler + 0xe24);
    *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
  }
LAB_97bdc214:
  if ((*(uint *)(programInfo + 0x34) & 2) != 0) {
    codeCursor2 = *(uint **)(compiler + 0xe30);
    *codeCursor2 = *(ushort *)(programInfo + 0xba) | 0x38c60000;
    programInfo = *(int *)(compiler + 0xe24);
    *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
  }
  if ((*(uint *)(programInfo + 0x34) & 0x1000) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81e30da8;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    immediateHalf = *(ushort *)(*(int *)(compiler + 0xe24) + 0xda);
    codeCursor[2] = 0x91e30da8;
    codeCursor[1] = immediateHalf | 0x39ef0000;
    programInfo = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 3;
  }
  if ((*(uint *)(programInfo + 0x34) & 0x4000) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81e30dac;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    immediateHalf = *(ushort *)(*(int *)(compiler + 0xe24) + 0xde);
    codeCursor[2] = 0x91e30dac;
    codeCursor[1] = immediateHalf | 0x39ef0000;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 3;
  }
  return;
}

/* _PPCRuntimeCompilerLoop @ 0x97bdc2d8 (92 bytes) */
int _PPCRuntimeCompilerLoop(compiler)
  int compiler;
{
  uint wordsBack;
  uint *codeCursor;
  
  codeCursor = *(uint **)(compiler + 0xe30);
  wordsBack = (uint)((int)codeCursor - *(int *)(compiler + 0xe38)) >> 2;
  if (wordsBack < 0x1fff) {
    *codeCursor = wordsBack * -4 & 0xfffc | 0x42000000;
    *(uint **)(compiler + 0xe30) = codeCursor + 1;
    return;
  }
  *codeCursor = 0x42400008;
  codeCursor[1] = (~wordsBack & 0xffffff) << 2 | 0x48000000;
  *(uint **)(compiler + 0xe30) = codeCursor + 2;
  return;
}

/* _PPCRuntimeCompilerCompileNO @ 0x97bdc334 (5348 bytes) */
int _PPCRuntimeCompilerCompileNO(compiler)
  int compiler;
{
  int sourceIndexOrRecord;
  int instructionRecord;
  undefined4 textureObjectOrCodeCursor;
  undefined4 srcDescWord7;
  undefined4 glpDCBReallocResult;
  int glpDCBReallocResult2;
  uint componentIndex;
  uint ppcOpBase;
  undefined4 ppcInstWord3;
  undefined4 codeWritePtr6;
  undefined4 *codeWritePtr5;
  int chunkByteOffset;
  int intTemp;
  int codeWordCount;
  undefined4 *codeCursor2;
  int codeCursor3;
  int instruction;
  int chunkIndex;
  int chunkIndex2;
  char saturate;
  byte dotComponentCount;
  ushort destBaseIndex;
  bool writesDestination;
  undefined4 *instructionListCursor;
  int passIndex;
  uint sourceCountOrTemp;
  uint loopIndex2;
  int sourceRecord;
  undefined4 codeBuffer;
  undefined *opTemplate;
  undefined4 srcDescWord0;
  undefined4 srcDescWord1OrCodePtr;
  undefined4 srcDescWord2;
  undefined4 srcDescWord3;
  int srcDescWord4OrTemp;
  undefined4 *nextInstructionOrLeftover;
  undefined4 srcDescWord8;
  undefined4 srcDescWord5;
  int codeCursor;
  int *srcDescWord6OrCodePtr;
  int codeBufferCapacity;
  uint componentCount;
  uint opcode;
  int *destRegisterOffsets;
  uint nextSourceIndex;
  uint *currentInst;
  
  _PPCRuntimeCompilerInitialise(compiler,0);
  codeBuffer = _glpDCBAlloc(0x2000);
  codeBufferCapacity = 0x2000;
  *(undefined4 *)(compiler + 0xe30) = codeBuffer;
  *(undefined4 *)(compiler + 0xe2c) = codeBuffer;
  ((int (*)())_PPCRuntimeCompilerWritePrologNO)(compiler);
  *(undefined4 *)(compiler + 0xe48) = 0;
  do {
    passIndex = *(int *)(compiler + 0xe48);
    if ((passIndex != 1) && (passIndex != 3)) {
      intTemp = *(int *)(compiler + 0xe24);
      instructionListCursor = *(undefined4 **)(intTemp + 0x120);
      *(undefined4 **)(compiler + 0xe28) = instructionListCursor;
      while (instructionListCursor != (undefined4 *)0x0) {
        currentInst = *(uint **)(compiler + 0xe28);
        componentCount = 1;
        writesDestination = true;
        sourceCountOrTemp = currentInst[0xc];
        opcode = *currentInst;
        saturate = *(char *)(currentInst + 1);
        if (sourceCountOrTemp != 0) {
          intTemp = 0;
          do {
            if ((*(char *)((int)currentInst + intTemp + 0x48) != '\0') &&
               (loopIndex2 = (uint)*(byte *)((int)currentInst + intTemp + 0x49), componentCount < loopIndex2)) {
              componentCount = loopIndex2;
            }
            intTemp = intTemp + 0x24;
            sourceCountOrTemp = sourceCountOrTemp - 1;
          } while (sourceCountOrTemp != 0);
        }
        if (opcode == 0x22) {
          if ((*(int *)(compiler + 0x380) == 0) &&
             (((destBaseIndex = *(ushort *)(currentInst + 7),
               sourceCountOrTemp = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x10), destBaseIndex != sourceCountOrTemp ||
               (destRegisterOffsets = (int *)currentInst[3],
               intTemp = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x10), *destRegisterOffsets != intTemp)) ||
              (currentInst = *(uint **)(compiler + 0xe28), (currentInst[10] & 0x1000000) == 0)))) {
            _PPCRuntimeCompilerBackupRegister(compiler,0x10);
            currentInst = *(uint **)(compiler + 0xe28);
          }
          if ((*(int *)(compiler + 0x3b8) == 0) &&
             (((destBaseIndex = *(ushort *)(currentInst + 7),
               sourceCountOrTemp = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x11), destBaseIndex != sourceCountOrTemp ||
               (sourceCountOrTemp = currentInst[3], intTemp = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x11),
               *(int *)(sourceCountOrTemp + 4) != intTemp)) ||
              (currentInst = *(uint **)(compiler + 0xe28), (currentInst[10] & 0x2000000) == 0)))) {
            _PPCRuntimeCompilerBackupRegister(compiler,0x11);
            currentInst = *(uint **)(compiler + 0xe28);
          }
          if ((*(int *)(compiler + 0x3f0) == 0) &&
             (((destBaseIndex = *(ushort *)(currentInst + 7),
               sourceCountOrTemp = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x12), destBaseIndex != sourceCountOrTemp ||
               (sourceCountOrTemp = currentInst[3], intTemp = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x12),
               *(int *)(sourceCountOrTemp + 8) != intTemp)) ||
              (currentInst = *(uint **)(compiler + 0xe28), (currentInst[10] & 0x4000000) == 0)))) {
            _PPCRuntimeCompilerBackupRegister(compiler,0x12);
            currentInst = *(uint **)(compiler + 0xe28);
          }
          if ((*(int *)(compiler + 0x428) == 0) &&
             (((destBaseIndex = *(ushort *)(currentInst + 7),
               sourceCountOrTemp = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x13), destBaseIndex != sourceCountOrTemp ||
               (sourceCountOrTemp = currentInst[3], intTemp = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x13),
               *(int *)(sourceCountOrTemp + 0xc) != intTemp)) ||
              (currentInst = *(uint **)(compiler + 0xe28), (currentInst[10] & 0x8000000) == 0)))) {
            _PPCRuntimeCompilerBackupRegister(compiler,0x13);
            currentInst = *(uint **)(compiler + 0xe28);
          }
          if ((*(char *)(currentInst + 0x12) == '\0') && (*(char *)(currentInst + 0x1b) == '\0')) {
            ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,currentInst[0xd],currentInst[0xe],currentInst[0xf],currentInst[0x10],currentInst[0x11],
                       currentInst[0x12],currentInst[0x13],currentInst[0x14],currentInst[0x15],0,0);
            instructionRecord = *(int *)(compiler + 0xe28);
            srcDescWord6OrCodePtr = *(int **)(instructionRecord + 0x70);
            srcDescWord1OrCodePtr = *(undefined4 *)(instructionRecord + 0x5c);
            srcDescWord2 = *(undefined4 *)(instructionRecord + 0x60);
            srcDescWord3 = *(undefined4 *)(instructionRecord + 100);
            srcDescWord4OrTemp = *(int *)(instructionRecord + 0x68);
            ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)(instructionRecord + 0x58),srcDescWord1OrCodePtr,srcDescWord2,srcDescWord3,srcDescWord4OrTemp,
                       *(undefined4 *)(instructionRecord + 0x6c),srcDescWord6OrCodePtr,*(undefined4 *)(instructionRecord + 0x74),
                       *(undefined4 *)(instructionRecord + 0x78),0,1);
            intTemp = _glpRTCAddAChunk_97bd7cbc(&_glpOpMultRTC,*(undefined4 *)(compiler + 0xe30));
            *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + intTemp * 4;
          }
          else if ((*(char *)(currentInst + 0x12) == '\0') ||
                  (*(char *)((int)currentInst + 0x49) != *(char *)((int)currentInst + 0x6d))) {
            sourceIndexOrRecord = 0;
            if (*(char *)(currentInst + 0x12) == '\0') {
              if (*(char *)(currentInst + 0x1b) != '\0') {
                ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,currentInst[0x16],currentInst[0x17],currentInst[0x18],currentInst[0x19],
                           currentInst[0x1a],currentInst[0x1b],currentInst[0x1c],currentInst[0x1d],currentInst[0x1e],0,1
                          );
                instruction = *(int *)(compiler + 0xe28);
                sourceIndexOrRecord = 1;
                srcDescWord8 = *(undefined4 *)(instruction + 0x54);
                srcDescWord7 = *(undefined4 *)(instruction + 0x50);
                srcDescWord6OrCodePtr = *(int **)(instruction + 0x4c);
                srcDescWord0 = *(undefined4 *)(instruction + 0x34);
                srcDescWord1OrCodePtr = *(undefined4 *)(instruction + 0x38);
                srcDescWord2 = *(undefined4 *)(instruction + 0x3c);
                srcDescWord3 = *(undefined4 *)(instruction + 0x40);
                srcDescWord4OrTemp = *(int *)(instruction + 0x44);
                srcDescWord5 = *(undefined4 *)(instruction + 0x48);
                goto LAB_97bdc778;
              }
            }
            else {
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,currentInst[0xd],currentInst[0xe],currentInst[0xf],currentInst[0x10],currentInst[0x11],
                         currentInst[0x12],currentInst[0x13],currentInst[0x14],currentInst[0x15],0,1);
              instruction = *(int *)(compiler + 0xe28);
              srcDescWord8 = *(undefined4 *)(instruction + 0x78);
              srcDescWord7 = *(undefined4 *)(instruction + 0x74);
              srcDescWord6OrCodePtr = *(int **)(instruction + 0x70);
              srcDescWord0 = *(undefined4 *)(instruction + 0x58);
              srcDescWord1OrCodePtr = *(undefined4 *)(instruction + 0x5c);
              srcDescWord2 = *(undefined4 *)(instruction + 0x60);
              srcDescWord3 = *(undefined4 *)(instruction + 100);
              srcDescWord4OrTemp = *(int *)(instruction + 0x68);
              srcDescWord5 = *(undefined4 *)(instruction + 0x6c);
LAB_97bdc778:
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,srcDescWord0,srcDescWord1OrCodePtr,srcDescWord2,srcDescWord3,srcDescWord4OrTemp,srcDescWord5,srcDescWord6OrCodePtr,srcDescWord7,srcDescWord8,0,0);
            }
            if (componentCount == 2) {
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor + chunkIndex * 4) = 0xfd008090;
              sourceIndexOrRecord = sourceIndexOrRecord * 0x24 + *(int *)(compiler + 0xe28);
              *(int *)(compiler + 0xe30) = codeCursor + chunkIndex * 4 + 4;
              srcDescWord1OrCodePtr = *(undefined4 *)(sourceIndexOrRecord + 0x38);
              srcDescWord2 = *(undefined4 *)(sourceIndexOrRecord + 0x3c);
              srcDescWord3 = *(undefined4 *)(sourceIndexOrRecord + 0x40);
              srcDescWord4OrTemp = *(int *)(sourceIndexOrRecord + 0x44);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)(sourceIndexOrRecord + 0x34),srcDescWord1OrCodePtr,srcDescWord2,srcDescWord3,srcDescWord4OrTemp,
                         *(undefined4 *)(sourceIndexOrRecord + 0x48),*(undefined4 *)(sourceIndexOrRecord + 0x4c),
                         *(undefined4 *)(sourceIndexOrRecord + 0x50),*(undefined4 *)(sourceIndexOrRecord + 0x54),1,1);
              chunkByteOffset = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              srcDescWord6OrCodePtr = *(int **)(compiler + 0xe30);
              chunkByteOffset = chunkByteOffset << 2;
              ppcOpBase = 0xfe200000;
            }
            else if (componentCount == 3) {
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor + chunkIndex * 4) = 0xfd008090;
              *(int *)(compiler + 0xe30) = codeCursor + chunkIndex * 4 + 4;
              sourceRecord = sourceIndexOrRecord * 0x24 + *(int *)(compiler + 0xe28);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)(sourceRecord + 0x34),*(undefined4 *)(sourceRecord + 0x38),
                         *(undefined4 *)(sourceRecord + 0x3c),*(undefined4 *)(sourceRecord + 0x40),
                         *(undefined4 *)(sourceRecord + 0x44),*(undefined4 *)(sourceRecord + 0x48),
                         *(undefined4 *)(sourceRecord + 0x4c),*(undefined4 *)(sourceRecord + 0x50),
                         *(undefined4 *)(sourceRecord + 0x54),1,1);
              chunkIndex2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor3 = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor3 + chunkIndex2 * 4) = 0xfe208090;
              *(int *)(compiler + 0xe30) = codeCursor3 + chunkIndex2 * 4 + 4;
              sourceIndexOrRecord = sourceIndexOrRecord * 0x24 + *(int *)(compiler + 0xe28);
              srcDescWord1OrCodePtr = *(undefined4 *)(sourceIndexOrRecord + 0x38);
              srcDescWord2 = *(undefined4 *)(sourceIndexOrRecord + 0x3c);
              srcDescWord3 = *(undefined4 *)(sourceIndexOrRecord + 0x40);
              srcDescWord4OrTemp = *(int *)(sourceIndexOrRecord + 0x44);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)(sourceIndexOrRecord + 0x34),srcDescWord1OrCodePtr,srcDescWord2,srcDescWord3,srcDescWord4OrTemp,
                         *(undefined4 *)(sourceIndexOrRecord + 0x48),*(undefined4 *)(sourceIndexOrRecord + 0x4c),
                         *(undefined4 *)(sourceIndexOrRecord + 0x50),*(undefined4 *)(sourceIndexOrRecord + 0x54),2,1);
              chunkByteOffset = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              srcDescWord6OrCodePtr = *(int **)(compiler + 0xe30);
              chunkByteOffset = chunkByteOffset << 2;
              ppcOpBase = 0xfe400000;
            }
            else {
              if (componentCount != 4) goto LAB_97bdcb04;
              sourceIndexOrRecord = sourceIndexOrRecord * 0x24;
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor + chunkIndex * 4) = 0xfd008090;
              *(int *)(compiler + 0xe30) = codeCursor + chunkIndex * 4 + 4;
              sourceRecord = sourceIndexOrRecord + *(int *)(compiler + 0xe28);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)(sourceRecord + 0x34),*(undefined4 *)(sourceRecord + 0x38),
                         *(undefined4 *)(sourceRecord + 0x3c),*(undefined4 *)(sourceRecord + 0x40),
                         *(undefined4 *)(sourceRecord + 0x44),*(undefined4 *)(sourceRecord + 0x48),
                         *(undefined4 *)(sourceRecord + 0x4c),*(undefined4 *)(sourceRecord + 0x50),
                         *(undefined4 *)(sourceRecord + 0x54),1,1);
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor + chunkIndex * 4) = 0xfe208090;
              *(int *)(compiler + 0xe30) = codeCursor + chunkIndex * 4 + 4;
              sourceRecord = sourceIndexOrRecord + *(int *)(compiler + 0xe28);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)(sourceRecord + 0x34),*(undefined4 *)(sourceRecord + 0x38),
                         *(undefined4 *)(sourceRecord + 0x3c),*(undefined4 *)(sourceRecord + 0x40),
                         *(undefined4 *)(sourceRecord + 0x44),*(undefined4 *)(sourceRecord + 0x48),
                         *(undefined4 *)(sourceRecord + 0x4c),*(undefined4 *)(sourceRecord + 0x50),
                         *(undefined4 *)(sourceRecord + 0x54),2,1);
              chunkIndex2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor3 = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor3 + chunkIndex2 * 4) = 0xfe408090;
              *(int *)(compiler + 0xe30) = codeCursor3 + chunkIndex2 * 4 + 4;
              sourceIndexOrRecord = sourceIndexOrRecord + *(int *)(compiler + 0xe28);
              srcDescWord1OrCodePtr = *(undefined4 *)(sourceIndexOrRecord + 0x38);
              srcDescWord2 = *(undefined4 *)(sourceIndexOrRecord + 0x3c);
              srcDescWord3 = *(undefined4 *)(sourceIndexOrRecord + 0x40);
              srcDescWord4OrTemp = *(int *)(sourceIndexOrRecord + 0x44);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)(sourceIndexOrRecord + 0x34),srcDescWord1OrCodePtr,srcDescWord2,srcDescWord3,srcDescWord4OrTemp,
                         *(undefined4 *)(sourceIndexOrRecord + 0x48),*(undefined4 *)(sourceIndexOrRecord + 0x4c),
                         *(undefined4 *)(sourceIndexOrRecord + 0x50),*(undefined4 *)(sourceIndexOrRecord + 0x54),3,1);
              chunkByteOffset = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              srcDescWord6OrCodePtr = *(int **)(compiler + 0xe30);
              chunkByteOffset = chunkByteOffset << 2;
              ppcOpBase = 0xfe600000;
            }
            *(uint *)((int)srcDescWord6OrCodePtr + chunkByteOffset) = ppcOpBase | 0x8090;
            *(undefined4 *)((int)srcDescWord6OrCodePtr + chunkByteOffset + 4) = 0xfe004090;
            *(int *)(compiler + 0xe30) = (int)srcDescWord6OrCodePtr + chunkByteOffset + 8;
          }
LAB_97bdcb04:
          ((int (*)())_PPCRuntimeCompilerWriteDestinationNO)(compiler,0);
        }
        else {
          componentIndex = 0;
          if (componentCount != 0) {
            do {
              if ((*(int *)(compiler + 0x380) == 0) &&
                 (((destBaseIndex = *(ushort *)(currentInst + 7),
                   loopIndex2 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x10), destBaseIndex != loopIndex2
                   || (destRegisterOffsets = (int *)currentInst[3],
                      intTemp = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x10),
                      *destRegisterOffsets != intTemp)) ||
                  (currentInst = *(uint **)(compiler + 0xe28), (currentInst[10] & 0x1000000) == 0)))) {
                _PPCRuntimeCompilerBackupRegister(compiler,0x10);
                currentInst = *(uint **)(compiler + 0xe28);
              }
              if ((*(int *)(compiler + 0x3b8) == 0) &&
                 (((destBaseIndex = *(ushort *)(currentInst + 7),
                   loopIndex2 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x11), destBaseIndex != loopIndex2
                   || (loopIndex2 = currentInst[3],
                      intTemp = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x11),
                      *(int *)(loopIndex2 + 4) != intTemp)) ||
                  (currentInst = *(uint **)(compiler + 0xe28), (currentInst[10] & 0x2000000) == 0)))) {
                _PPCRuntimeCompilerBackupRegister(compiler,0x11);
                currentInst = *(uint **)(compiler + 0xe28);
              }
              if ((*(int *)(compiler + 0x3f0) == 0) &&
                 (((destBaseIndex = *(ushort *)(currentInst + 7),
                   loopIndex2 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x12), destBaseIndex != loopIndex2
                   || (loopIndex2 = currentInst[3],
                      intTemp = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x12),
                      *(int *)(loopIndex2 + 8) != intTemp)) ||
                  (currentInst = *(uint **)(compiler + 0xe28), (currentInst[10] & 0x4000000) == 0)))) {
                _PPCRuntimeCompilerBackupRegister(compiler,0x12);
                currentInst = *(uint **)(compiler + 0xe28);
              }
              if ((*(int *)(compiler + 0x428) == 0) &&
                 (((destBaseIndex = *(ushort *)(currentInst + 7),
                   loopIndex2 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x13), destBaseIndex != loopIndex2
                   || (loopIndex2 = currentInst[3],
                      intTemp = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x13),
                      *(int *)(loopIndex2 + 0xc) != intTemp)) ||
                  (currentInst = *(uint **)(compiler + 0xe28), (currentInst[10] & 0x8000000) == 0)))) {
                _PPCRuntimeCompilerBackupRegister(compiler,0x13);
                currentInst = *(uint **)(compiler + 0xe28);
              }
              if (currentInst[0xc] != 0) {
                intTemp = 0;
                loopIndex2 = 0;
                do {
                  nextSourceIndex = loopIndex2 + 1;
                  srcDescWord6OrCodePtr = *(int **)((int)currentInst + intTemp + 0x4c);
                  srcDescWord1OrCodePtr = *(undefined4 *)((int)currentInst + intTemp + 0x38);
                  srcDescWord2 = *(undefined4 *)((int)currentInst + intTemp + 0x3c);
                  srcDescWord3 = *(undefined4 *)((int)currentInst + intTemp + 0x40);
                  srcDescWord4OrTemp = *(int *)((int)currentInst + intTemp + 0x44);
                  ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)((int)currentInst + intTemp + 0x34),srcDescWord1OrCodePtr,srcDescWord2,srcDescWord3,
                             srcDescWord4OrTemp,*(undefined4 *)((int)currentInst + intTemp + 0x48),srcDescWord6OrCodePtr,
                             *(undefined4 *)((int)currentInst + intTemp + 0x50),
                             *(undefined4 *)((int)currentInst + intTemp + 0x54),componentIndex,loopIndex2);
                  currentInst = *(uint **)(compiler + 0xe28);
                  intTemp = intTemp + 0x24;
                  loopIndex2 = nextSourceIndex;
                } while (nextSourceIndex < currentInst[0xc]);
              }
              if (opcode < 0x15) {
                if (((0x12 < opcode) || (opcode == 1)) || ((opcode != 0 && (opcode - 0x10 < 2)))) {
LAB_97bdcd64:
                  _PPCRuntimeCompilerDirtyRegister(compiler,0);
                  _PPCRuntimeCompilerDirtyRegister(compiler,1);
                  _PPCRuntimeCompilerDirtyRegister(compiler,2);
                  _PPCRuntimeCompilerDirtyRegister(compiler,3);
                  _PPCRuntimeCompilerDirtyRegister(compiler,4);
                  _PPCRuntimeCompilerDirtyRegister(compiler,5);
                  _PPCRuntimeCompilerDirtyRegister(compiler,6);
                  _PPCRuntimeCompilerDirtyRegister(compiler,7);
                }
              }
              else {
                if (opcode == 0x38) goto LAB_97bdcd64;
                if (opcode == 0x48) {
                  _PPCRuntimeCompilerDirtyRegister(compiler,0);
                  _PPCRuntimeCompilerDirtyRegistersWithIndirectData(compiler);
                }
              }
              switch(opcode) {
              case 0:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpMovRTC;
                break;
              case 1:
                intTemp = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpShuffleSrcRTC,*(undefined4 *)(compiler + 0xe30));
                intTemp = *(int *)(compiler + 0xe30) + intTemp * 4;
                *(int *)(compiler + 0xe30) = intTemp;
                intTemp = _glpRTCAddAChunk_97bd7cbc(&_glpOpLogRTC,intTemp);
                intTemp = *(int *)(compiler + 0xe30) + intTemp * 4;
                *(int *)(compiler + 0xe30) = intTemp;
                intTemp = _glpRTCAddAChunk_97bd7cbc(&_glpOpRestoreSrcBRTC,intTemp);
                intTemp = *(int *)(compiler + 0xe30) + intTemp * 4;
                *(int *)(compiler + 0xe30) = intTemp;
                intTemp = _glpRTCAddAChunk_97bd7cbc(&_glpOpExpRTC,intTemp);
                intTemp = *(int *)(compiler + 0xe30) + intTemp * 4;
                *(int *)(compiler + 0xe30) = intTemp;
                opTemplate = &_glpOpShuffleDstRTC;
                break;
              case 2:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpAbsRTC;
                break;
              default:
                goto switchD_97bdcdfc_caseD_3;
              case 4:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpFrcRTC;
                break;
              case 5:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpFlrRTC;
                break;
              case 0xd:
                codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                opTemplate = &_glpOpRsqRTC;
                goto LAB_97bdcf9c;
              case 0xe:
                codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                opTemplate = &_glpOpRcpRTC;
                goto LAB_97bdcf9c;
              case 0x10:
                intTemp = *(int *)(compiler + 0xe30);
                goto LAB_97bdd288;
              case 0x11:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpExpRTC;
                break;
              case 0x13:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpLogRTC;
                goto LAB_97bdcfe4;
              case 0x14:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpLogRTC;
                break;
              case 0x1f:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpAddRTC;
                break;
              case 0x20:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpSubRTC;
                break;
              case 0x22:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpMultRTC;
                break;
              case 0x27:
                dotComponentCount = *(byte *)(*(int *)(compiler + 0xe28) + 5);
                if (dotComponentCount == 2) {
                  codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                  opTemplate = &_glpOpDot2RTC;
LAB_97bdd170:
                  intTemp = _glpRTCAddAChunk_97bd7cbc(opTemplate,codeWritePtr6);
                  *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + intTemp * 4;
                }
                else {
                  if (2 < dotComponentCount) {
                    if (dotComponentCount == 3) {
                      codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                      opTemplate = &_glpOpDot3RTC;
                    }
                    else {
                      if (dotComponentCount != 4) goto LAB_97bdd184;
                      codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                      opTemplate = &_glpOpDot4RTC;
                    }
                    goto LAB_97bdd170;
                  }
                  if (dotComponentCount == 1) {
                    codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                    opTemplate = &_glpOpDot1RTC;
                    goto LAB_97bdd170;
                  }
                }
LAB_97bdd184:
                intTemp = *(int *)(compiler + 0xe30);
                goto LAB_97bdcfb4;
              case 0x28:
                codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                opTemplate = &_glpOpDot3RTC;
                goto LAB_97bdcf9c;
              case 0x29:
                codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                opTemplate = &_glpOpDot4RTC;
                goto LAB_97bdcf9c;
              case 0x2a:
                codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                opTemplate = &_glpOpDphRTC;
LAB_97bdcf9c:
                intTemp = _glpRTCAddAChunk_97bd7cbc(opTemplate,codeWritePtr6);
                intTemp = *(int *)(compiler + 0xe30) + intTemp * 4;
                *(int *)(compiler + 0xe30) = intTemp;
LAB_97bdcfb4:
                opTemplate = &_glpOpSplatC0RTC;
                break;
              case 0x2b:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpDistRTC;
                break;
              case 0x2c:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpMinRTC;
                break;
              case 0x2d:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpMaxRTC;
                break;
              case 0x2e:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpXpdRTC;
                break;
              case 0x32:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpSetGERTC;
                break;
              case 0x35:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpSetLTRTC;
                break;
              case 0x38:
                intTemp = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpSaveSrcBRTC,*(undefined4 *)(compiler + 0xe30));
                intTemp = *(int *)(compiler + 0xe30) + intTemp * 4;
                *(int *)(compiler + 0xe30) = intTemp;
                intTemp = _glpRTCAddAChunk_97bd7cbc(&_glpOpLogRTC,intTemp);
                intTemp = *(int *)(compiler + 0xe30) + intTemp * 4;
                *(int *)(compiler + 0xe30) = intTemp;
                intTemp = _glpRTCAddAChunk_97bd7cbc(&_glpOpRestoreSrcBRTC,intTemp);
                intTemp = *(int *)(compiler + 0xe30) + intTemp * 4;
                *(int *)(compiler + 0xe30) = intTemp;
LAB_97bdd288:
                opTemplate = &_glpOpExpRTC;
LAB_97bdcfe4:
                intTemp = _glpRTCAddAChunk_97bd7cbc(opTemplate,intTemp);
                intTemp = *(int *)(compiler + 0xe30) + intTemp * 4;
                *(int *)(compiler + 0xe30) = intTemp;
                opTemplate = &_glpOpSplatC2RTC;
                break;
              case 0x3c:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpLerpRTC;
                break;
              case 0x3e:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpCmpRTC;
                break;
              case 0x3f:
                intTemp = *(int *)(compiler + 0xe30);
                opTemplate = &_glpOpMultAddRTC;
                break;
              case 0x41:
                intTemp = *(int *)(compiler + 0xe28);
                switch(*(undefined1 *)(intTemp + 0x60)) {
                case 0:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe000090;
                  break;
                case 1:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe000890;
                  break;
                case 2:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe001090;
                  break;
                case 3:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe001890;
                  break;
                case 4:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe000050;
                  break;
                case 5:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe000850;
                  break;
                case 6:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe001050;
                  break;
                case 7:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe001850;
                  break;
                case 8:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe005090;
                  break;
                case 9:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe005890;
                  break;
                case 10:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  *codeWritePtr5 = 0xfe005050;
                  intTemp = *(int *)(compiler + 0xe28);
                  *(undefined4 **)(compiler + 0xe30) = codeWritePtr5 + 1;
                default:
                  goto switchD_97bdd2fc_default;
                }
                *codeWritePtr5 = ppcInstWord3;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr5 + 1;
                intTemp = *(int *)(compiler + 0xe28);
switchD_97bdd2fc_default:
                switch(*(undefined1 *)(intTemp + 0x61)) {
                case 0:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe200090;
                  break;
                case 1:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe200890;
                  break;
                case 2:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe201090;
                  break;
                case 3:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe201890;
                  break;
                case 4:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe200050;
                  break;
                case 5:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe200850;
                  break;
                case 6:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe201050;
                  break;
                case 7:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe201850;
                  break;
                case 8:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe205090;
                  break;
                case 9:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe205890;
                  break;
                case 10:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  *codeWritePtr5 = 0xfe205050;
                  intTemp = *(int *)(compiler + 0xe28);
                  *(undefined4 **)(compiler + 0xe30) = codeWritePtr5 + 1;
                default:
                  goto switchD_97bdd41c_default;
                }
                *codeWritePtr5 = ppcInstWord3;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr5 + 1;
                intTemp = *(int *)(compiler + 0xe28);
switchD_97bdd41c_default:
                switch(*(undefined1 *)(intTemp + 0x62)) {
                case 0:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe400090;
                  break;
                case 1:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe400890;
                  break;
                case 2:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe401090;
                  break;
                case 3:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe401890;
                  break;
                case 4:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe400050;
                  break;
                case 5:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe400850;
                  break;
                case 6:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe401050;
                  break;
                case 7:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe401850;
                  break;
                case 8:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe405090;
                  break;
                case 9:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe405890;
                  break;
                case 10:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  *codeWritePtr5 = 0xfe405050;
                  intTemp = *(int *)(compiler + 0xe28);
                  *(undefined4 **)(compiler + 0xe30) = codeWritePtr5 + 1;
                default:
                  goto switchD_97bdd53c_default;
                }
                *codeWritePtr5 = ppcInstWord3;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr5 + 1;
                intTemp = *(int *)(compiler + 0xe28);
switchD_97bdd53c_default:
                switch(*(undefined1 *)(intTemp + 99)) {
                case 0:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe600090;
                  break;
                case 1:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe600890;
                  break;
                case 2:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe601090;
                  break;
                case 3:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe601890;
                  break;
                case 4:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe600050;
                  break;
                case 5:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe600850;
                  break;
                case 6:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe601050;
                  break;
                case 7:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe601850;
                  break;
                case 8:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe605090;
                  break;
                case 9:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe605890;
                  break;
                case 10:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe605050;
                  break;
                default:
                  goto switchD_97bdcdfc_caseD_3;
                }
                *codeWritePtr5 = ppcInstWord3;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr5 + 1;
                goto switchD_97bdcdfc_caseD_3;
              case 0x42:
                srcDescWord4OrTemp = *(int *)(compiler + 0xe20);
                if (*(int *)(*(int *)(srcDescWord4OrTemp + 0xd80) + 0x38) - 0x8b30U < 2) {
                  srcDescWord6OrCodePtr = *(int **)(*(int *)(compiler + 0xe28) + 0x58);
                  textureObjectOrCodeCursor = *(undefined4 *)
                            (*(int *)((uint)*(ushort *)(*(int *)(compiler + 0xe28) + 0x68) * 4 +
                                      srcDescWord4OrTemp + 0xd84) + *srcDescWord6OrCodePtr);
                }
                else {
                  textureObjectOrCodeCursor = *(undefined4 *)(*(int *)(compiler + 0xe28) + 0x10c);
                }
                ((int (*)())_PPCTextureSamplerAttachGLDContext)(*(undefined4 *)(compiler + 0xe1c),*(undefined4 *)(srcDescWord4OrTemp + 0xd9c));
                intTemp = *(int *)(*(int *)(compiler + 0xe28) + 0x110);
                if (intTemp == 2) {
                  srcDescWord1OrCodePtr = *(undefined4 *)(compiler + 0xe30);
                  textureObjectOrCodeCursor = ((int (*)())_PPCTextureSamplerSampleTexelRECTRTCNO)(*(undefined4 *)(compiler + 0xe1c),textureObjectOrCodeCursor,srcDescWord1OrCodePtr);
                }
                else {
                  if (intTemp != 3) goto switchD_97bdcdfc_caseD_3;
                  srcDescWord1OrCodePtr = *(undefined4 *)(compiler + 0xe30);
                  textureObjectOrCodeCursor = ((int (*)())_PPCTextureSamplerSampleTexel2DRTCNO)(*(undefined4 *)(compiler + 0xe1c),textureObjectOrCodeCursor,srcDescWord1OrCodePtr);
                }
                *(undefined4 *)(compiler + 0xe30) = textureObjectOrCodeCursor;
                goto switchD_97bdcdfc_caseD_3;
              case 0x48:
                if ((*(byte *)(*(int *)(compiler + 0xe28) + 0x28) & 1) != 0) {
                  intTemp = _glpRTCAddAChunk_97bd7cbc(&_glpOpArlRTC,*(undefined4 *)(compiler + 0xe30));
                  *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + intTemp * 4;
                }
              case 0x49:
              case 0x4a:
              case 0x4b:
              case 0x4c:
              case 0x4d:
              case 0x4f:
              case 0x55:
              case 0x56:
              case 0x57:
              case 0x58:
              case 0x59:
              case 0x5a:
                writesDestination = false;
                goto LAB_97bdd85c;
              case 0x5b:
                writesDestination = false;
                goto switchD_97bdcdfc_caseD_3;
              }
              intTemp = _glpRTCAddAChunk_97bd7cbc(opTemplate,intTemp);
              *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + intTemp * 4;
switchD_97bdcdfc_caseD_3:
              if (writesDestination) {
                if (saturate != '\0') {
                  intTemp = _glpRTCAddAChunk_97bd7cbc
                                    (&_glpOpSaturateRTC,*(undefined4 *)(compiler + 0xe30));
                  *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + intTemp * 4;
                }
                ((int (*)())_PPCRuntimeCompilerWriteDestinationNO)(compiler,componentIndex);
              }
LAB_97bdd85c:
              componentIndex = componentIndex + 1;
              if (componentCount <= componentIndex) break;
              currentInst = *(uint **)(compiler + 0xe28);
            } while( true );
          }
          intTemp = *(int *)(compiler + 0xe2c);
          if (codeBufferCapacity - 2000U < (uint)(*(int *)(compiler + 0xe30) - intTemp)) {
            codeBufferCapacity = codeBufferCapacity + 0x2000;
            glpDCBReallocResult2 = _glpDCBRealloc(intTemp,codeBufferCapacity);
            *(int *)(compiler + 0xe2c) = glpDCBReallocResult2;
            intTemp = glpDCBReallocResult2 - intTemp >> 2;
            if (intTemp != 0) {
              intTemp = intTemp * 4;
              srcDescWord6OrCodePtr = (int *)(*(int *)(compiler + 0xe3c) + intTemp);
              *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + intTemp;
              srcDescWord4OrTemp = *(int *)(compiler + 0xe40) + intTemp;
              *(int *)(compiler + 0xe34) = *(int *)(compiler + 0xe34) + intTemp;
              *(int *)(compiler + 0xe38) = *(int *)(compiler + 0xe38) + intTemp;
              *(int **)(compiler + 0xe3c) = srcDescWord6OrCodePtr;
              *(int *)(compiler + 0xe40) = srcDescWord4OrTemp;
            }
          }
        }
        intTemp = *(int *)(compiler + 0xe24);
        nextInstructionOrLeftover = (undefined4 *)(*(int *)(compiler + 0xe28) + 0x11c);
        if (*(int *)(compiler + 0xe28) == *(int *)(intTemp + 4)) {
          nextInstructionOrLeftover = (undefined4 *)0x0;
        }
        *(undefined4 **)(compiler + 0xe28) = nextInstructionOrLeftover;
        instructionListCursor = nextInstructionOrLeftover;
      }
      if ((*(int *)(intTemp + 0x38) != 0x8804) && (*(int *)(intTemp + 0x38) != 0x8b30)) {
        codeCursor2 = *(undefined4 **)(compiler + 0xe30);
        *codeCursor2 = 0xc0060010;
        nextInstructionOrLeftover = codeCursor2 + 1;
        *nextInstructionOrLeftover = 0xc0260014;
        codeCursor2[2] = 0xc0460018;
        codeCursor2[3] = 0xc066001c;
        *(undefined4 **)(compiler + 0xe30) = codeCursor2 + 4;
        intTemp = _glpRTCAddAChunk_97bd7cbc(&_glpOpClippingRTC,codeCursor2 + 4);
        *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + intTemp * 4;
      }
      passIndex = *(int *)(compiler + 0xe48);
      if (passIndex == 0) {
        _PPCRuntimeCompilerDirtyRegistersContainingAttributes(compiler);
        _PPCRuntimeCompilerDirtyRegistersContainingTemps(compiler);
        _PPCRuntimeCompilerDirtyRegistersContainingParams(compiler);
        passIndex = *(int *)(compiler + 0xe48);
        *(undefined4 *)(compiler + 0xe38) = *(undefined4 *)(compiler + 0xe30);
      }
      else if (passIndex == 2) {
        ((int (*)())_PPCRuntimeCompilerStride)(compiler);
        ((int (*)())_PPCRuntimeCompilerLoop)(compiler);
        passIndex = *(int *)(compiler + 0xe48);
      }
    }
    *(uint *)(compiler + 0xe48) = passIndex + 1U;
    if (3 < passIndex + 1U) {
      ((int (*)())_PPCRuntimeCompilerWriteEpilogNO)(compiler);
      codeWordCount = *(int *)(compiler + 0xe30) - *(int *)(compiler + 0xe2c) >> 2;
      glpDCBReallocResult = _glpDCBRealloc(*(int *)(compiler + 0xe2c),codeWordCount << 2);
      *(undefined4 *)(compiler + 0xe2c) = glpDCBReallocResult;
                    
                    
      (*_glpPushInstructions)(codeWordCount,glpDCBReallocResult,srcDescWord1OrCodePtr,srcDescWord2,srcDescWord3,srcDescWord4OrTemp,nextInstructionOrLeftover,srcDescWord6OrCodePtr);
      return;
    }
  } while( true );
}

/* _PPCRuntimeCompilerCompileAV @ 0x97bdda38 (15728 bytes) */
int _PPCRuntimeCompilerCompileAV(compiler)
  int compiler;
{
  undefined4 passStartCursor;
  uint branchWord;
  undefined4 *vectorInstWord6;
  int codeWritePtr4;
  int ppcInstWord;
  int codeWordCount;
  char dimensionByte;
  int codeCursorAfter;
  uint sourceComponent2;
  uint vectorInstWord4;
  undefined4 vectorInstWord3;
  uint ppcWord;
  uint vectorInstWord2;
  undefined4 grownCodeBuffer;
  undefined4 projectionEnabled;
  undefined4 destComponent;
  undefined4 passThroughR4;
  int passIndex;
  int codeBufferBase;
  int sourceOffset21;
  uint vectorInstWord;
  uint operandSelector;
  uint componentLoopIndex;
  undefined4 *codeWritePtr;
  int sourceOffset;
  int codeCursorAddr;
  int emittedWord;
  int chunkWordCount;
  int curInst;
  int sourceCount;
  int programInfo;
  undefined4 *codeCursor;
  undefined4 *codeCursor4;
  uint *codeCursor3;
  int *instruction2;
  int instruction;
  int codeCursor2;
  undefined8 chunkIndex2;
  int chunkIndex;
  uint loopIndex;
  bool storageMatches;
  char saturateFlag;
  byte dimension;
  bool writesDestination;
  undefined4 *instructionListHead;
  uint sourceComponent;
  uint textureTarget;
  undefined4 textureObject;
  int vectorInstWord5;
  int *codeWordPtr;
  int sourceRecord;
  uint operandWidth;
  uint *codeWritePtr2;
  uint *codeWritePtr3;
  undefined4 codeBuffer;
  undefined *opTemplate;
  undefined4 leftoverR4;
  undefined4 leftoverR4_00;
  undefined4 leftoverR4_01;
  undefined4 leftoverR4_02;
  undefined4 leftoverR4_03;
  undefined4 leftoverR4_04;
  undefined4 leftoverR4_05;
  undefined4 leftoverR4_06;
  undefined4 leftoverR4_07;
  undefined4 leftoverR4_08;
  undefined4 leftoverR4_09;
  undefined4 leftoverR4_10;
  undefined4 leftoverR4_11;
  undefined4 leftoverR4_12;
  undefined4 leftoverR4_13;
  undefined4 srcBankWord;
  undefined4 srcSwizzleWord;
  int srcIndexWord;
  int *srcStorageWord;
  undefined4 *inst;
  int operandOffset;
  undefined4 *paddedCursor;
  int *srcTypeWord;
  int codeBufferCapacity;
  uint elementCount;
  int opcode;
  uint nextComponentIndex;
  undefined8 emitResult64;
  
  _PPCRuntimeCompilerInitialise(compiler,1);
  codeBuffer = _glpDCBAlloc(0x2000);
  codeBufferCapacity = 0x2000;
  *(undefined4 *)(compiler + 0xe30) = codeBuffer;
  *(undefined4 *)(compiler + 0xe2c) = codeBuffer;
  ((int (*)())_PPCRuntimeCompilerWritePrologAV)(compiler);
  *(undefined4 *)(compiler + 0xe34) = *(undefined4 *)(compiler + 0xe30);
  *(undefined4 *)(compiler + 0xe48) = 0;
  passThroughR4 = leftoverR4;
  do {
    if (((1 < *(uint *)(compiler + 0xe48)) &&
        (programInfo = *(int *)(*(int *)(compiler + 0xe20) + 0xd80), (*(uint *)(programInfo + 0x3c) & 6) == 4))
       && ((*(uint *)(programInfo + 0x34) & 0xa000) == 0)) {
      emitResult64 = ((int (*)())_PPCRasterOpMachine_DepthTestRTCAV)(compiler + 0xe14,*(undefined4 *)(compiler + 0xe30));
      passThroughR4 = (undefined4)emitResult64;
      *(int *)(compiler + 0xe30) = (int)((ulonglong)emitResult64 >> 0x20);
    }
    programInfo = *(int *)(compiler + 0xe24);
    instructionListHead = *(undefined4 **)(programInfo + 0x120);
    *(undefined4 **)(compiler + 0xe28) = instructionListHead;
    while (instructionListHead != (undefined4 *)0x0) {
      elementCount = 1;
      writesDestination = true;
      instruction2 = *(int **)(compiler + 0xe28);
      instruction2[0x46] = *(int *)(compiler + 0xe30) - *(int *)(compiler + 0xe2c);
      opcode = *instruction2;
      sourceCount = *(int *)(*(int *)(compiler + 0xe28) + 0x30);
      saturateFlag = *(char *)(instruction2 + 1);
      if (sourceCount != 0) {
        operandOffset = 0;
        do {
          sourceRecord = operandOffset + *(int *)(compiler + 0xe28);
          if ((*(char *)(sourceRecord + 0x48) != '\0') &&
             (operandWidth = (uint)*(byte *)(sourceRecord + 0x49), elementCount < operandWidth)) {
            elementCount = operandWidth;
          }
          operandOffset = operandOffset + 0x24;
          sourceCount = sourceCount + -1;
        } while (sourceCount != 0);
      }
      if (opcode == 0x22) {
        _PPCRuntimeCompilerBackupRegister(compiler,2);
        _PPCRuntimeCompilerDirtyRegister(compiler,2);
        inst = *(undefined4 **)(compiler + 0xe28);
        if ((*(char *)(inst + 0x12) == '\0') && (*(char *)(inst + 0x1b) == '\0')) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],inst[0x12],
                     inst[0x13],inst[0x14],inst[0x15],0,0);
          curInst = *(int *)(compiler + 0xe28);
          srcTypeWord = *(int **)(curInst + 0x70);
          srcBankWord = *(undefined4 *)(curInst + 0x5c);
          srcSwizzleWord = *(undefined4 *)(curInst + 0x60);
          srcIndexWord = *(int *)(curInst + 100);
          srcStorageWord = *(int **)(curInst + 0x68);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                     *(undefined4 *)(curInst + 0x6c),srcTypeWord,*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),0,1);
          chunkWordCount = _glpRTCAddAChunk_97bd7cbc(&_glpOpMulAVRTC,*(undefined4 *)(compiler + 0xe30));
          chunkWordCount = *(int *)(compiler + 0xe30) + chunkWordCount * 4;
          *(int *)(compiler + 0xe30) = chunkWordCount;
          if (saturateFlag != '\0') {
            chunkWordCount = _glpRTCAddAChunk_97bd7cbc(&_glpOpSaturateAVRTC,chunkWordCount);
            *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + chunkWordCount * 4;
          }
LAB_97bdde9c:
          destComponent = 0;
LAB_97bddea4:
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,destComponent);
          passThroughR4 = leftoverR4_01;
          goto LAB_97be18e4;
        }
        if (((*(char *)(inst + 0x12) == '\0') || (*(char *)(inst + 0x1b) == '\0')) ||
           (*(char *)((int)inst + 0x49) != *(char *)((int)inst + 0x6d))) {
          if ((*(char *)(inst + 0x12) != '\0') && (1 < *(byte *)((int)inst + 0x6d))) {
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],inst[0x12],
                       inst[0x13],inst[0x14],inst[0x15],0,1);
            curInst = *(int *)(compiler + 0xe28);
            srcTypeWord = *(int **)(curInst + 0x70);
            srcBankWord = *(undefined4 *)(curInst + 0x5c);
            srcSwizzleWord = *(undefined4 *)(curInst + 0x60);
            srcIndexWord = *(int *)(curInst + 100);
            srcStorageWord = *(int **)(curInst + 0x68);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                       *(undefined4 *)(curInst + 0x6c),srcTypeWord,*(undefined4 *)(curInst + 0x74),
                       *(undefined4 *)(curInst + 0x78),0,0);
            if (elementCount == 2) {
              codeCursor = *(undefined4 **)(compiler + 0xe30);
              *codeCursor = 0x10a0028c;
              codeCursor[1] = 0x1045386e;
              curInst = *(int *)(compiler + 0xe28);
              *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
              srcTypeWord = *(int **)(curInst + 0x4c);
              srcBankWord = *(undefined4 *)(curInst + 0x38);
              srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
              srcIndexWord = *(int *)(curInst + 0x40);
              srcStorageWord = *(int **)(curInst + 0x44);
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                         *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                         *(undefined4 *)(curInst + 0x54),1,1);
              codeCursor = *(undefined4 **)(compiler + 0xe30);
              *codeCursor = 0x10a1028c;
              codeWritePtr2 = codeCursor + 1;
              *codeWritePtr2 = 0x1045106e;
            }
            else {
              if (elementCount == 3) {
                codeCursor = *(undefined4 **)(compiler + 0xe30);
                *codeCursor = 0x10a0028c;
                codeCursor[1] = 0x1045386e;
                curInst = *(int *)(compiler + 0xe28);
                *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                           *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                           *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                           *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                           *(undefined4 *)(curInst + 0x54),1,1);
                codeCursor = *(undefined4 **)(compiler + 0xe30);
                *codeCursor = 0x10a1028c;
                codeCursor[1] = 0x1045106e;
                curInst = *(int *)(compiler + 0xe28);
                *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
                srcTypeWord = *(int **)(curInst + 0x4c);
                srcBankWord = *(undefined4 *)(curInst + 0x38);
                srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
                srcIndexWord = *(int *)(curInst + 0x40);
                srcStorageWord = *(int **)(curInst + 0x44);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                           *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                           *(undefined4 *)(curInst + 0x54),2,1);
                codeCursor3 = *(uint **)(compiler + 0xe30);
                vectorInstWord2 = 0x10a20000;
              }
              else {
                if (elementCount != 4) goto LAB_97bdde9c;
                codeCursor = *(undefined4 **)(compiler + 0xe30);
                *codeCursor = 0x10a0028c;
                codeCursor[1] = 0x1045386e;
                curInst = *(int *)(compiler + 0xe28);
                *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                           *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                           *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                           *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                           *(undefined4 *)(curInst + 0x54),1,1);
                codeCursor = *(undefined4 **)(compiler + 0xe30);
                *codeCursor = 0x10a1028c;
                codeCursor[1] = 0x1045106e;
                curInst = *(int *)(compiler + 0xe28);
                *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                           *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                           *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                           *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                           *(undefined4 *)(curInst + 0x54),2,1);
                codeCursor = *(undefined4 **)(compiler + 0xe30);
                *codeCursor = 0x10a2028c;
                codeCursor[1] = 0x1045106e;
                curInst = *(int *)(compiler + 0xe28);
                *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
                srcTypeWord = *(int **)(curInst + 0x4c);
                srcBankWord = *(undefined4 *)(curInst + 0x38);
                srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
                srcIndexWord = *(int *)(curInst + 0x40);
                srcStorageWord = *(int **)(curInst + 0x44);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                           *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                           *(undefined4 *)(curInst + 0x54),3,1);
                codeCursor3 = *(uint **)(compiler + 0xe30);
                vectorInstWord2 = 0x10a30000;
              }
              *codeCursor3 = vectorInstWord2 | 0x28c;
              codeWritePtr2 = codeCursor3 + 1;
              *codeWritePtr2 = 0x1045106e;
            }
            goto LAB_97bdde94;
          }
          if ((*(char *)(inst + 0x1b) != '\0') && (1 < *(byte *)((int)inst + 0x49))) {
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                       inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,1);
            curInst = *(int *)(compiler + 0xe28);
            srcTypeWord = *(int **)(curInst + 0x4c);
            srcBankWord = *(undefined4 *)(curInst + 0x38);
            srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
            srcIndexWord = *(int *)(curInst + 0x40);
            srcStorageWord = *(int **)(curInst + 0x44);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                       *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                       *(undefined4 *)(curInst + 0x54),0,0);
            if (elementCount == 2) {
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp2AVRTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor2 = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor2 + chunkIndex * 4) = 0x10a5112c;
              curInst = *(int *)(compiler + 0xe28);
              *(int *)(compiler + 0xe30) = codeCursor2 + chunkIndex * 4 + 4;
              srcBankWord = *(undefined4 *)(curInst + 0x5c);
              srcSwizzleWord = *(undefined4 *)(curInst + 0x60);
              srcIndexWord = *(int *)(curInst + 100);
              srcStorageWord = *(int **)(curInst + 0x68);
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                         *(undefined4 *)(curInst + 0x6c),*(undefined4 *)(curInst + 0x70),
                         *(undefined4 *)(curInst + 0x74),*(undefined4 *)(curInst + 0x78),1,1);
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp2AVRTC,*(undefined4 *)(compiler + 0xe30));
              srcTypeWord = *(int **)(compiler + 0xe30);
              codeWordPtr = srcTypeWord + chunkIndex;
              emittedWord = 0x10a5132c;
LAB_97bdeef0:
              srcTypeWord[chunkIndex] = emittedWord;
              codeWordPtr[1] = 0x10452c84;
            }
            else {
              if (elementCount == 3) {
                chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp3AVRTC,*(undefined4 *)(compiler + 0xe30))
                ;
                codeCursor2 = *(int *)(compiler + 0xe30);
                *(undefined4 *)(codeCursor2 + chunkIndex * 4) = 0x10a5112c;
                curInst = *(int *)(compiler + 0xe28);
                *(int *)(compiler + 0xe30) = codeCursor2 + chunkIndex * 4 + 4;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                           *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                           *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                           *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                           *(undefined4 *)(curInst + 0x78),1,1);
                chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp3AVRTC,*(undefined4 *)(compiler + 0xe30))
                ;
                codeCursorAddr = *(int *)(compiler + 0xe30);
                *(undefined4 *)(codeCursorAddr + chunkIndex * 4) = 0x10a5112c;
                instruction = *(int *)(compiler + 0xe28);
                *(int *)(compiler + 0xe30) = codeCursorAddr + chunkIndex * 4 + 4;
                srcBankWord = *(undefined4 *)(instruction + 0x5c);
                srcSwizzleWord = *(undefined4 *)(instruction + 0x60);
                srcIndexWord = *(int *)(instruction + 100);
                srcStorageWord = *(int **)(instruction + 0x68);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(instruction + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                           *(undefined4 *)(instruction + 0x6c),*(undefined4 *)(instruction + 0x70),
                           *(undefined4 *)(instruction + 0x74),*(undefined4 *)(instruction + 0x78),2,1);
                chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp3AVRTC,*(undefined4 *)(compiler + 0xe30))
                ;
                srcTypeWord = *(int **)(compiler + 0xe30);
                codeWordPtr = srcTypeWord + chunkIndex;
                emittedWord = 0x10a5122c;
                goto LAB_97bdeef0;
              }
              if (elementCount != 4) goto LAB_97bdde9c;
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp4AVRTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor2 = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor2 + chunkIndex * 4) = 0x10a5112c;
              curInst = *(int *)(compiler + 0xe28);
              *(int *)(compiler + 0xe30) = codeCursor2 + chunkIndex * 4 + 4;
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                         *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                         *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                         *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                         *(undefined4 *)(curInst + 0x78),1,1);
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp4AVRTC,*(undefined4 *)(compiler + 0xe30));
              codeCursorAddr = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursorAddr + chunkIndex * 4) = 0x10a5112c;
              instruction = *(int *)(compiler + 0xe28);
              *(int *)(compiler + 0xe30) = codeCursorAddr + chunkIndex * 4 + 4;
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(instruction + 0x58),*(undefined4 *)(instruction + 0x5c),
                         *(undefined4 *)(instruction + 0x60),*(undefined4 *)(instruction + 100),
                         *(undefined4 *)(instruction + 0x68),*(undefined4 *)(instruction + 0x6c),
                         *(undefined4 *)(instruction + 0x70),*(undefined4 *)(instruction + 0x74),
                         *(undefined4 *)(instruction + 0x78),2,1);
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp4AVRTC,*(undefined4 *)(compiler + 0xe30));
              codeCursorAddr = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursorAddr + chunkIndex * 4) = 0x10a5112c;
              instruction = *(int *)(compiler + 0xe28);
              *(int *)(compiler + 0xe30) = codeCursorAddr + chunkIndex * 4 + 4;
              srcTypeWord = *(int **)(instruction + 0x70);
              srcBankWord = *(undefined4 *)(instruction + 0x5c);
              srcSwizzleWord = *(undefined4 *)(instruction + 0x60);
              srcIndexWord = *(int *)(instruction + 100);
              srcStorageWord = *(int **)(instruction + 0x68);
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(instruction + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                         *(undefined4 *)(instruction + 0x6c),srcTypeWord,*(undefined4 *)(instruction + 0x74),
                         *(undefined4 *)(instruction + 0x78),3,1);
              chunkWordCount = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp4AVRTC,*(undefined4 *)(compiler + 0xe30));
              codeWordPtr = (int *)(*(int *)(compiler + 0xe30) + chunkWordCount * 4);
              *(undefined4 *)(*(int *)(compiler + 0xe30) + chunkWordCount * 4) = 0x10a5112c;
              codeWordPtr[1] = 0x10452c84;
            }
            *(int **)(compiler + 0xe30) = codeWordPtr + 2;
            goto LAB_97bdde9c;
          }
          if ((*(char *)(inst + 0x12) == '\0') == 0) {
            sourceOffset = 0x54;
          }
          else {
            sourceOffset = 0x30;
          }
          sourceOffset21 = (uint)(*(char *)(inst + 0x12) == '\0') * 0x24;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)((int)inst + sourceOffset + 4),
                     *(undefined4 *)((int)inst + sourceOffset + 8),
                     *(undefined4 *)((int)inst + sourceOffset + 0xc),
                     *(undefined4 *)((int)inst + sourceOffset + 0x10),
                     *(undefined4 *)((int)inst + sourceOffset + 0x14),
                     *(undefined4 *)((int)inst + sourceOffset + 0x18),
                     *(undefined4 *)((int)inst + sourceOffset + 0x1c),
                     *(undefined4 *)((int)inst + sourceOffset + 0x20),
                     *(undefined4 *)((int)inst + sourceOffset + 0x24),0,0);
          curInst = sourceOffset21 + *(int *)(compiler + 0xe28);
          srcTypeWord = *(int **)(curInst + 0x4c);
          srcBankWord = *(undefined4 *)(curInst + 0x38);
          srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
          srcIndexWord = *(int *)(curInst + 0x40);
          srcStorageWord = *(int **)(curInst + 0x44);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                     *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),0,1);
          if (elementCount == 2) {
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            *codeCursor = 0x1040386e;
            *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,0);
            _PPCRuntimeCompilerBackupRegister(compiler,2);
            _PPCRuntimeCompilerDirtyRegister(compiler,2);
            sourceOffset21 = sourceOffset21 + *(int *)(compiler + 0xe28);
            srcTypeWord = *(int **)(sourceOffset21 + 0x4c);
            srcBankWord = *(undefined4 *)(sourceOffset21 + 0x38);
            srcSwizzleWord = *(undefined4 *)(sourceOffset21 + 0x3c);
            srcIndexWord = *(int *)(sourceOffset21 + 0x40);
            srcStorageWord = *(int **)(sourceOffset21 + 0x44);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(sourceOffset21 + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                       *(undefined4 *)(sourceOffset21 + 0x48),srcTypeWord,*(undefined4 *)(sourceOffset21 + 0x50),
                       *(undefined4 *)(sourceOffset21 + 0x54),1,1);
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            destComponent = 1;
          }
          else if (elementCount == 3) {
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            *codeCursor = 0x1040386e;
            *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,0);
            _PPCRuntimeCompilerBackupRegister(compiler,2);
            _PPCRuntimeCompilerDirtyRegister(compiler,2);
            curInst = sourceOffset21 + *(int *)(compiler + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                       *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                       *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                       *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                       *(undefined4 *)(curInst + 0x54),1,1);
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            *codeCursor = 0x1040386e;
            *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,1);
            _PPCRuntimeCompilerBackupRegister(compiler,2);
            _PPCRuntimeCompilerDirtyRegister(compiler,2);
            sourceOffset21 = sourceOffset21 + *(int *)(compiler + 0xe28);
            srcTypeWord = *(int **)(sourceOffset21 + 0x4c);
            srcBankWord = *(undefined4 *)(sourceOffset21 + 0x38);
            srcSwizzleWord = *(undefined4 *)(sourceOffset21 + 0x3c);
            srcIndexWord = *(int *)(sourceOffset21 + 0x40);
            srcStorageWord = *(int **)(sourceOffset21 + 0x44);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(sourceOffset21 + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                       *(undefined4 *)(sourceOffset21 + 0x48),srcTypeWord,*(undefined4 *)(sourceOffset21 + 0x50),
                       *(undefined4 *)(sourceOffset21 + 0x54),2,1);
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            destComponent = 2;
          }
          else {
            passThroughR4 = leftoverR4_02;
            if (elementCount != 4) goto LAB_97be18e4;
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            *codeCursor = 0x1040386e;
            *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,0);
            _PPCRuntimeCompilerBackupRegister(compiler,2);
            _PPCRuntimeCompilerDirtyRegister(compiler,2);
            curInst = sourceOffset21 + *(int *)(compiler + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                       *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                       *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                       *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                       *(undefined4 *)(curInst + 0x54),1,1);
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            *codeCursor = 0x1040386e;
            *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,1);
            _PPCRuntimeCompilerBackupRegister(compiler,2);
            _PPCRuntimeCompilerDirtyRegister(compiler,2);
            curInst = sourceOffset21 + *(int *)(compiler + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                       *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                       *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                       *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                       *(undefined4 *)(curInst + 0x54),2,1);
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            *codeCursor = 0x1040386e;
            *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,2);
            _PPCRuntimeCompilerBackupRegister(compiler,2);
            _PPCRuntimeCompilerDirtyRegister(compiler,2);
            sourceOffset21 = sourceOffset21 + *(int *)(compiler + 0xe28);
            srcTypeWord = *(int **)(sourceOffset21 + 0x4c);
            srcBankWord = *(undefined4 *)(sourceOffset21 + 0x38);
            srcSwizzleWord = *(undefined4 *)(sourceOffset21 + 0x3c);
            srcIndexWord = *(int *)(sourceOffset21 + 0x40);
            srcStorageWord = *(int **)(sourceOffset21 + 0x44);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(sourceOffset21 + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                       *(undefined4 *)(sourceOffset21 + 0x48),srcTypeWord,*(undefined4 *)(sourceOffset21 + 0x50),
                       *(undefined4 *)(sourceOffset21 + 0x54),3,1);
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            destComponent = 3;
          }
          *codeCursor = 0x1040386e;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
          goto LAB_97bddea4;
        }
        if (elementCount == 2) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],inst[0x12],
                     inst[0x13],inst[0x14],inst[0x15],0,0);
          curInst = *(int *)(compiler + 0xe28);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),0,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          codeCursor[2] = 0x3b000210;
          codeCursor[3] = 0x7c43c1ce;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),1,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          srcTypeWord = *(int **)(curInst + 0x4c);
          srcBankWord = *(undefined4 *)(curInst + 0x38);
          srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
          srcIndexWord = *(int *)(curInst + 0x40);
          srcStorageWord = *(int **)(curInst + 0x44);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                     *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),0,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeWritePtr = codeCursor + 1;
          *codeWritePtr = 0x104011ae;
LAB_97bdde5c:
          *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 1;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,1);
          _PPCRuntimeCompilerBackupRegister(compiler,2);
          _PPCRuntimeCompilerDirtyRegister(compiler,2);
          codeWritePtr2 = *(uint **)(compiler + 0xe30);
          ppcWord = 0x7c43c0ce;
          goto LAB_97bdde90;
        }
        if (elementCount == 3) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],inst[0x12],
                     inst[0x13],inst[0x14],inst[0x15],0,0);
          curInst = *(int *)(compiler + 0xe28);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),0,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),2,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c20a8c;
          codeCursor[1] = 0x104011ae;
          codeCursor[2] = 0x3b000210;
          codeCursor[3] = 0x7c43c1ce;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),1,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c20a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),0,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104011ae;
          codeCursor[2] = 0x3b200220;
          codeCursor[3] = 0x7c43c9ce;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),2,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          srcTypeWord = *(int **)(curInst + 0x4c);
          srcBankWord = *(undefined4 *)(curInst + 0x38);
          srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
          srcIndexWord = *(int *)(curInst + 0x40);
          srcStorageWord = *(int **)(curInst + 0x44);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                     *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),2,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c20a8c;
          codeCursor[1] = 0x104011ae;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,2);
          _PPCRuntimeCompilerBackupRegister(compiler,2);
          _PPCRuntimeCompilerDirtyRegister(compiler,2);
          codeWritePtr = *(undefined4 **)(compiler + 0xe30);
          *codeWritePtr = 0x7c43c8ce;
          goto LAB_97bdde5c;
        }
        passThroughR4 = leftoverR4_00;
        if (elementCount == 4) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],inst[0x12],
                     inst[0x13],inst[0x14],inst[0x15],0,0);
          curInst = *(int *)(compiler + 0xe28);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),0,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),2,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c20a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),3,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c30a8c;
          codeCursor[1] = 0x104011ae;
          codeCursor[2] = 0x3ae00210;
          codeCursor[3] = 0x7c43b9ce;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),1,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c30a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),2,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c20a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),0,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104011ae;
          codeCursor[2] = 0x3b000220;
          codeCursor[3] = 0x7c43c1ce;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),2,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),2,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c20a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),3,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c30a8c;
          codeCursor[1] = 0x104011ae;
          codeCursor[2] = 0x3b200230;
          codeCursor[3] = 0x7c43c9ce;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),3,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c30a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),2,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c20a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          srcTypeWord = *(int **)(curInst + 0x4c);
          srcBankWord = *(undefined4 *)(curInst + 0x38);
          srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
          srcIndexWord = *(int *)(curInst + 0x40);
          srcStorageWord = *(int **)(curInst + 0x44);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                     *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),0,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104011ae;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,3);
          _PPCRuntimeCompilerBackupRegister(compiler,2);
          _PPCRuntimeCompilerDirtyRegister(compiler,2);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x7c43c8ce;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,2);
          _PPCRuntimeCompilerBackupRegister(compiler,2);
          _PPCRuntimeCompilerDirtyRegister(compiler,2);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x7c43c0ce;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,1);
          _PPCRuntimeCompilerBackupRegister(compiler,2);
          _PPCRuntimeCompilerDirtyRegister(compiler,2);
          codeWritePtr2 = *(uint **)(compiler + 0xe30);
          ppcWord = 0x7c43b8ce;
          goto LAB_97bdde90;
        }
      }
      else {
        if ((opcode == 0x31) || (opcode == 0x36)) {
          _PPCRuntimeCompilerBackupRegister(compiler,2);
          _PPCRuntimeCompilerDirtyRegister(compiler,2);
          if (elementCount < 2) {
            curInst = *(int *)(compiler + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                       *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                       *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                       *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                       *(undefined4 *)(curInst + 0x54),0,0);
            curInst = *(int *)(compiler + 0xe28);
            srcTypeWord = *(int **)(curInst + 0x70);
            srcBankWord = *(undefined4 *)(curInst + 0x5c);
            srcSwizzleWord = *(undefined4 *)(curInst + 0x60);
            srcIndexWord = *(int *)(curInst + 100);
            srcStorageWord = *(int **)(curInst + 0x68);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                       *(undefined4 *)(curInst + 0x6c),srcTypeWord,*(undefined4 *)(curInst + 0x74),
                       *(undefined4 *)(curInst + 0x78),0,1);
            if (*(char *)(*(int *)(compiler + 0xe28) + 0x21) == '\x01') {
              dimensionByte = *(char *)(*(int *)(compiler + 0xe28) + 5);
              if (dimensionByte == '\x01') {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpSetAllEqualTo1AVRTC;
              }
              else if (dimensionByte == '\x02') {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpSetAllEqualTo2AVRTC;
              }
              else if (dimensionByte == '\x03') {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpSetAllEqualTo3AVRTC;
              }
              else {
                if (dimensionByte != '\x04') goto LAB_97bdf944;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpSetAllEqualTo4AVRTC;
              }
            }
            else {
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSetEqualToAVRTC;
            }
LAB_97bdf930:
            chunkWordCount = _glpRTCAddAChunk_97bd7cbc(opTemplate,codeWritePtr);
            *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + chunkWordCount * 4;
          }
          else {
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            *codeCursor = 0x10a84484;
            *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
            if (elementCount == 3) {
              loopIndex = 0;
              do {
                curInst = *(int *)(compiler + 0xe28);
                sourceComponent2 = loopIndex;
                if (*(char *)(curInst + 0x48) == '\0') {
                  sourceComponent2 = 0;
                }
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                           *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                           *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                           *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                           *(undefined4 *)(curInst + 0x54),sourceComponent2,0);
                curInst = *(int *)(compiler + 0xe28);
                operandWidth = loopIndex;
                if (*(char *)(curInst + 0x6c) == '\0') {
                  operandWidth = 0;
                }
                loopIndex = loopIndex + 1;
                srcTypeWord = *(int **)(curInst + 0x70);
                srcBankWord = *(undefined4 *)(curInst + 0x5c);
                srcSwizzleWord = *(undefined4 *)(curInst + 0x60);
                srcIndexWord = *(int *)(curInst + 100);
                srcStorageWord = *(int **)(curInst + 0x68);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                           *(undefined4 *)(curInst + 0x6c),srcTypeWord,*(undefined4 *)(curInst + 0x74),
                           *(undefined4 *)(curInst + 0x78),operandWidth,1);
                chunkWordCount = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpSetAllEqualTo3AVRTC,*(undefined4 *)(compiler + 0xe30));
                codeCursor2 = *(int *)(compiler + 0xe30);
                *(undefined4 *)(codeCursor2 + chunkWordCount * 4) = 0x10a5112c;
                *(int *)(compiler + 0xe30) = codeCursor2 + chunkWordCount * 4 + 4;
              } while (loopIndex < 3);
LAB_97bdf7ec:
              _PPCRuntimeCompilerBackupRegister(compiler,0);
              _PPCRuntimeCompilerDirtyRegister(compiler,0);
              codeCursor = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpAllAVRTC;
              *codeCursor = 0x10052c84;
              codeWritePtr = codeCursor + 1;
              *(undefined4 **)(compiler + 0xe30) = codeWritePtr;
              goto LAB_97bdf930;
            }
            if (elementCount < 4) {
              if (elementCount == 2) {
                loopIndex = 0;
                do {
                  curInst = *(int *)(compiler + 0xe28);
                  sourceComponent2 = loopIndex;
                  if (*(char *)(curInst + 0x48) == '\0') {
                    sourceComponent2 = 0;
                  }
                  ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                             *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                             *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                             *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                             *(undefined4 *)(curInst + 0x54),sourceComponent2,0);
                  curInst = *(int *)(compiler + 0xe28);
                  operandWidth = loopIndex;
                  if (*(char *)(curInst + 0x6c) == '\0') {
                    operandWidth = 0;
                  }
                  loopIndex = loopIndex + 1;
                  srcTypeWord = *(int **)(curInst + 0x70);
                  srcBankWord = *(undefined4 *)(curInst + 0x5c);
                  srcSwizzleWord = *(undefined4 *)(curInst + 0x60);
                  srcIndexWord = *(int *)(curInst + 100);
                  srcStorageWord = *(int **)(curInst + 0x68);
                  ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                             *(undefined4 *)(curInst + 0x6c),srcTypeWord,*(undefined4 *)(curInst + 0x74),
                             *(undefined4 *)(curInst + 0x78),operandWidth,1);
                  chunkWordCount = _glpRTCAddAChunk_97bd7cbc
                                    (&_glpOpSetAllEqualTo2AVRTC,*(undefined4 *)(compiler + 0xe30));
                  codeCursor2 = *(int *)(compiler + 0xe30);
                  *(undefined4 *)(codeCursor2 + chunkWordCount * 4) = 0x10a5112c;
                  *(int *)(compiler + 0xe30) = codeCursor2 + chunkWordCount * 4 + 4;
                } while (loopIndex < 2);
                goto LAB_97bdf7ec;
              }
            }
            else if (elementCount == 4) {
              loopIndex = 0;
              do {
                curInst = *(int *)(compiler + 0xe28);
                sourceComponent2 = loopIndex;
                if (*(char *)(curInst + 0x48) == '\0') {
                  sourceComponent2 = 0;
                }
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                           *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                           *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                           *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                           *(undefined4 *)(curInst + 0x54),sourceComponent2,0);
                curInst = *(int *)(compiler + 0xe28);
                operandWidth = loopIndex;
                if (*(char *)(curInst + 0x6c) == '\0') {
                  operandWidth = 0;
                }
                loopIndex = loopIndex + 1;
                srcTypeWord = *(int **)(curInst + 0x70);
                srcBankWord = *(undefined4 *)(curInst + 0x5c);
                srcSwizzleWord = *(undefined4 *)(curInst + 0x60);
                srcIndexWord = *(int *)(curInst + 100);
                srcStorageWord = *(int **)(curInst + 0x68);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                           *(undefined4 *)(curInst + 0x6c),srcTypeWord,*(undefined4 *)(curInst + 0x74),
                           *(undefined4 *)(curInst + 0x78),operandWidth,1);
                chunkWordCount = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpSetAllEqualTo4AVRTC,*(undefined4 *)(compiler + 0xe30));
                codeCursor2 = *(int *)(compiler + 0xe30);
                *(undefined4 *)(codeCursor2 + chunkWordCount * 4) = 0x10a5112c;
                *(int *)(compiler + 0xe30) = codeCursor2 + chunkWordCount * 4 + 4;
              } while (loopIndex < 4);
              goto LAB_97bdf7ec;
            }
          }
LAB_97bdf944:
          if (opcode == 0x36) {
            codeWritePtr2 = *(uint **)(compiler + 0xe30);
            ppcWord = 0x1048104a;
LAB_97bdde90:
            *codeWritePtr2 = ppcWord;
LAB_97bdde94:
            *(uint **)(compiler + 0xe30) = codeWritePtr2 + 1;
          }
          goto LAB_97bdde9c;
        }
        operandWidth = 0;
        if (elementCount != 0) {
          do {
            _PPCRuntimeCompilerBackupRegister(compiler,2);
            _PPCRuntimeCompilerDirtyRegister(compiler,2);
            programInfo = *(int *)(compiler + 0xe28);
            passThroughR4 = leftoverR4_03;
            if (*(int *)(programInfo + 0x30) != 0) {
              operandOffset = 0;
              componentLoopIndex = 0;
              do {
                programInfo = operandOffset + programInfo;
                sourceComponent = operandWidth;
                if (*(char *)(programInfo + 0x48) == '\0') {
                  sourceComponent = 0;
                }
                nextComponentIndex = componentLoopIndex + 1;
                operandOffset = operandOffset + 0x24;
                srcTypeWord = *(int **)(programInfo + 0x4c);
                srcBankWord = *(undefined4 *)(programInfo + 0x38);
                srcSwizzleWord = *(undefined4 *)(programInfo + 0x3c);
                srcIndexWord = *(int *)(programInfo + 0x40);
                srcStorageWord = *(int **)(programInfo + 0x44);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(programInfo + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                           *(undefined4 *)(programInfo + 0x48),srcTypeWord,*(undefined4 *)(programInfo + 0x50),
                           *(undefined4 *)(programInfo + 0x54),sourceComponent,componentLoopIndex);
                programInfo = *(int *)(compiler + 0xe28);
                passThroughR4 = leftoverR4_04;
                componentLoopIndex = nextComponentIndex;
              } while (nextComponentIndex < *(uint *)(programInfo + 0x30));
            }
            switch(opcode) {
            case 1:
            case 0xb:
            case 0x10:
            case 0x11:
            case 0x13:
            case 0x14:
            case 0x18:
            case 0x2e:
            case 0x38:
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
            case 0x6f:
            case 0x70:
              _PPCRuntimeCompilerDirtyRegister(compiler,0);
              _PPCRuntimeCompilerDirtyRegister(compiler,1);
              passThroughR4 = leftoverR4_05;
              break;
            case 0x48:
              _PPCRuntimeCompilerDirtyRegistersWithIndirectData(compiler);
              passThroughR4 = leftoverR4_06;
            }
            switch(opcode) {
            case 0:
switchD_97bdfc38_caseD_0:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpMovAVRTC;
              break;
            case 1:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpLitAVRTC;
              break;
            case 2:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpAbsAVRTC;
              break;
            case 3:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpCeilAVRTC;
              break;
            case 4:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpFrcAVRTC;
              break;
            case 5:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpFlrAVRTC;
              break;
            default:
              goto switchD_97bdfc38_caseD_6;
            case 7:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSetSignAVRTC;
              break;
            case 8:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpAnyAVRTC;
              break;
            case 9:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpAllAVRTC;
              break;
            case 10:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpNotAVRTC;
              break;
            case 0xb:
              dimension = *(byte *)(*(int *)(compiler + 0xe28) + 5);
              if (dimension == 2) {
                emitResult64 = ((int (*)())_PPCNoiseGeneratorCalculate2DAVRTC)(*(int *)(compiler + 0xe20) + 0x360,
                                    *(undefined4 *)(compiler + 0xe30));
              }
              else if (dimension < 3) {
                if (dimension != 1) goto switchD_97bdfc38_caseD_6;
                emitResult64 = ((int (*)())_PPCNoiseGeneratorCalculate1DAVRTC)(*(int *)(compiler + 0xe20) + 0x360,
                                    *(undefined4 *)(compiler + 0xe30));
              }
              else if (dimension == 3) {
                emitResult64 = ((int (*)())_PPCNoiseGeneratorCalculate3DAVRTC)(*(int *)(compiler + 0xe20) + 0x360,
                                    *(undefined4 *)(compiler + 0xe30));
              }
              else {
                if (dimension != 4) goto switchD_97bdfc38_caseD_6;
                emitResult64 = ((int (*)())_PPCNoiseGeneratorCalculate4DAVRTC)(*(int *)(compiler + 0xe20) + 0x360,
                                    *(undefined4 *)(compiler + 0xe30));
              }
              goto LAB_97be1634;
            case 0xc:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSqrtAVRTC;
              break;
            case 0xd:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpRsqAVRTC;
              break;
            case 0xe:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpRcpAVRTC;
              break;
            case 0x10:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              goto LAB_97be04f0;
            case 0x11:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpExpAVRTC;
              break;
            case 0x12:
              dimension = *(byte *)(*(int *)(compiler + 0xe28) + 5);
              if (dimension == 2) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpLength2AVRTC;
              }
              else if (dimension < 3) {
                if (dimension != 1) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpLength1AVRTC;
              }
              else if (dimension == 3) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpLength3AVRTC;
              }
              else {
                if (dimension != 4) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpLength4AVRTC;
              }
              break;
            case 0x13:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpLg2AVRTC;
              break;
            case 0x14:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpLogAVRTC;
              break;
            case 0x15:
              dimension = *(byte *)(*(int *)(compiler + 0xe28) + 5);
              if (dimension == 2) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpNormalise2AVRTC;
              }
              else if (dimension < 3) {
                if (dimension != 1) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpNormalise1AVRTC;
              }
              else if (dimension == 3) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpNormalise3AVRTC;
              }
              else {
                if (dimension != 4) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpNormalise4AVRTC;
              }
              break;
            case 0x16:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpDegreesToRadiansAVRTC;
              break;
            case 0x17:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpRadiansToDegreesAVRTC;
              break;
            case 0x18:
              codeCursor = *(undefined4 **)(compiler + 0xe30);
              *codeCursor = 0x1003028c;
              codeWritePtr = codeCursor + 1;
              *(undefined4 **)(compiler + 0xe30) = codeWritePtr;
              chunkWordCount = _glpRTCAddAChunk_97bd7cbc(&_glpOpCosAVRTC,codeWritePtr);
              codeCursorAfter = *(int *)(compiler + 0xe30) + chunkWordCount * 4 + 4;
              *(undefined4 *)(*(int *)(compiler + 0xe30) + chunkWordCount * 4) = 0x10221484;
              *(int *)(compiler + 0xe30) = codeCursorAfter;
              chunkIndex2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpSinAVRTC,codeCursorAfter);
              passThroughR4 = (undefined4)chunkIndex2;
              vectorInstWord5 = (int)((ulonglong)chunkIndex2 >> 0x20) * 4;
              codeWritePtr3 = (uint *)(*(int *)(compiler + 0xe30) + vectorInstWord5 + 4);
              *(undefined4 *)(*(int *)(compiler + 0xe30) + vectorInstWord5) = 0x1041132c;
              goto LAB_97be1820;
            case 0x19:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSinAVRTC;
              break;
            case 0x1a:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpCosAVRTC;
              break;
            case 0x1f:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpAddAVRTC;
              break;
            case 0x20:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSubAVRTC;
              break;
            case 0x21:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpModAVRTC;
              break;
            case 0x23:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpMulAVRTC;
              break;
            case 0x24:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpLogicalAndAVRTC;
              break;
            case 0x25:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpLogicalOrAVRTC;
              break;
            case 0x26:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpLogicalXorAVRTC;
              break;
            case 0x27:
              dimension = *(byte *)(*(int *)(compiler + 0xe28) + 5);
              if (dimension == 2) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpDp2AVRTC;
                break;
              }
              if (dimension < 3) {
                if (dimension == 1) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  opTemplate = &_glpOpDp1AVRTC;
                  break;
                }
              }
              else {
                if (dimension == 3) goto switchD_97bdfc38_caseD_28;
                if (dimension == 4) goto switchD_97bdfc38_caseD_29;
              }
              goto switchD_97bdfc38_caseD_6;
            case 0x28:
switchD_97bdfc38_caseD_28:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpDp3AVRTC;
              break;
            case 0x29:
switchD_97bdfc38_caseD_29:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpDp4AVRTC;
              break;
            case 0x2a:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpDphAVRTC;
              break;
            case 0x2b:
              if (*(int *)(*(int *)(compiler + 0xe24) + 0x38) - 0x8b30U < 2) {
                dimension = *(byte *)(*(int *)(compiler + 0xe28) + 5);
                if (dimension == 2) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  opTemplate = &_glpOpDistance2GLSLAVRTC;
                }
                else if (dimension < 3) {
                  if (dimension != 1) goto switchD_97bdfc38_caseD_6;
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  opTemplate = &_glpOpDistance1GLSLAVRTC;
                }
                else if (dimension == 3) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  opTemplate = &_glpOpDistance3GLSLAVRTC;
                }
                else {
                  if (dimension != 4) goto switchD_97bdfc38_caseD_6;
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  opTemplate = &_glpOpDistance4GLSLAVRTC;
                }
              }
              else {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpDistanceARBVPFPAVRTC;
              }
              break;
            case 0x2c:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpMinAVRTC;
              break;
            case 0x2d:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpMaxAVRTC;
              break;
            case 0x2e:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpXpdAVRTC;
              break;
            case 0x2f:
              dimension = *(byte *)(*(int *)(compiler + 0xe28) + 5);
              if (dimension == 2) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpReflect2AVRTC;
              }
              else if (dimension < 3) {
                if (dimension != 1) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpReflect1AVRTC;
              }
              else if (dimension == 3) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpReflect3AVRTC;
              }
              else {
                if (dimension != 4) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpReflect4AVRTC;
              }
              break;
            case 0x30:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpStrAVRTC;
              break;
            case 0x32:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSgeAVRTC;
              break;
            case 0x33:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSgtAVRTC;
              break;
            case 0x34:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSleAVRTC;
              break;
            case 0x35:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSltAVRTC;
              break;
            case 0x37:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSflAVRTC;
              break;
            case 0x38:
              chunkWordCount = _glpRTCAddAChunk_97bd7cbc(&_glpOpLg2AVRTC,*(undefined4 *)(compiler + 0xe30));
              chunkWordCount = *(int *)(compiler + 0xe30) + chunkWordCount * 4;
              *(int *)(compiler + 0xe30) = chunkWordCount;
              chunkWordCount = _glpRTCAddAChunk_97bd7cbc(&_glpOpMulForPowAVRTC,chunkWordCount);
              codeWritePtr = (undefined4 *)(*(int *)(compiler + 0xe30) + chunkWordCount * 4);
              *(undefined4 **)(compiler + 0xe30) = codeWritePtr;
LAB_97be04f0:
              opTemplate = &_glpOpEx2AVRTC;
              break;
            case 0x39:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpScalarSelectAVRTC;
              break;
            case 0x3a:
              curInst = *(int *)(*(int *)(compiler + 0xe28) + 0x24);
              if (curInst == 1) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpDivideAVRTC;
              }
              else {
                if (curInst != 3) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpIntegerDivideAVRTC;
              }
              break;
            case 0x3b:
              dimension = *(byte *)(*(int *)(compiler + 0xe28) + 5);
              if (dimension == 2) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpFaceForward2AVRTC;
              }
              else if (dimension < 3) {
                if (dimension != 1) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpFaceForward1AVRTC;
              }
              else if (dimension == 3) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpFaceForward3AVRTC;
              }
              else {
                if (dimension != 4) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpFaceForward4AVRTC;
              }
              break;
            case 0x3c:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpLerpAVRTC;
              break;
            case 0x3d:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpClampAVRTC;
              break;
            case 0x3e:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpCmpAVRTC;
              break;
            case 0x3f:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpMadAVRTC;
              break;
            case 0x40:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSmoothStepAVRTC;
              break;
            case 0x41:
              curInst = *(int *)(compiler + 0xe28);
              srcStorageWord = (int *)(uint)*(byte *)(curInst + 99);
              operandSelector = (uint)*(byte *)(curInst + 0x61);
              srcTypeWord = (int *)(uint)*(byte *)(curInst + 0x62);
              switch(*(undefined1 *)(curInst + 0x60)) {
              case 0:
                if (operandSelector == 0) {
                  operandSelector = 0xffffffff;
                  if ((srcTypeWord == (int *)0x0) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x0)) {
                    srcStorageWord = (int *)0xffffffff;
                  }
LAB_97be06cc:
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord4 = 0x10400000;
LAB_97be07d8:
                  vectorInstWord4 = vectorInstWord4 | 0x28c;
LAB_97be0ad4:
                  *codeWritePtr2 = vectorInstWord4;
LAB_97be0ad8:
                  *(uint **)(compiler + 0xe30) = codeWritePtr2 + 1;
                  break;
                }
                if (operandSelector != 1) goto LAB_97be06cc;
                if (srcTypeWord != (int *)0x2) {
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1040022c;
                  goto LAB_97be0794;
                }
                if (srcStorageWord != (int *)0x3) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1040032c;
                  goto LAB_97be077c;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10400484;
                goto LAB_97be1470;
              case 1:
                if (operandSelector == 1) {
                  operandSelector = 0xffffffff;
                  if ((srcTypeWord == (int *)0x1) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x1)) {
                    srcStorageWord = (int *)0xffffffff;
                  }
LAB_97be0748:
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord4 = 0x10410000;
                  goto LAB_97be07d8;
                }
                if (operandSelector != 2) goto LAB_97be0748;
                if (srcTypeWord != (int *)0x3) {
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1040032c;
                  goto LAB_97be0794;
                }
                if (srcStorageWord != (int *)0x0) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10400484;
                  goto LAB_97be077c;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10400000;
                goto LAB_97be13a0;
              case 2:
                if (operandSelector == 2) {
                  operandSelector = 0xffffffff;
                  if ((srcTypeWord == (int *)0x2) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x2)) {
                    srcStorageWord = (int *)0xffffffff;
                  }
LAB_97be07d0:
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord4 = 0x10420000;
                  goto LAB_97be07d8;
                }
                if (operandSelector != 3) goto LAB_97be07d0;
                if (srcTypeWord != (int *)0x0) {
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10400484;
                  goto LAB_97be0794;
                }
                if (srcStorageWord != (int *)0x1) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10400000;
                  goto LAB_97be1050;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10400000;
                goto LAB_97be1040;
              case 3:
                if (operandSelector == 0) {
                  if (srcTypeWord != (int *)0x1) {
                    codeWritePtr2 = *(uint **)(compiler + 0xe30);
                    vectorInstWord = 0x10400000;
                    goto LAB_97be0c28;
                  }
                  if (srcStorageWord != (int *)0x2) {
                    codeWritePtr3 = *(uint **)(compiler + 0xe30);
                    vectorInstWord = 0x10400000;
                    goto LAB_97be0c18;
                  }
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10400000;
                  goto LAB_97be0c08;
                }
                if (operandSelector != 3) {
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord4 = 0x10400484;
                  goto LAB_97be0ad4;
                }
                if ((srcTypeWord == (int *)0x3) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x3)) {
                  srcStorageWord = (int *)0xffffffff;
                }
                codeWritePtr2 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1043028c;
                goto LAB_97be0794;
              case 4:
                if (operandSelector == 4) {
                  operandSelector = 0xffffffff;
                  if ((srcTypeWord == (int *)0x4) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x4)) {
                    srcStorageWord = (int *)0xffffffff;
                  }
LAB_97be08c4:
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord4 = 0x10400000;
LAB_97be0960:
                  *codeWritePtr = 0x10603cc4;
                  codeWritePtr2 = codeWritePtr + 1;
                  *codeWritePtr2 = vectorInstWord4 | 0x1a8c;
                  goto LAB_97be0ad8;
                }
                if (operandSelector != 5) goto LAB_97be08c4;
                if (srcTypeWord != (int *)0x6) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x10603cc4;
                  vectorInstWord = 0x10431a2c;
                  goto LAB_97be0e64;
                }
                if (srcStorageWord == (int *)0x7) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10403cc4;
                  goto LAB_97be1470;
                }
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord3 = 0x10603cc4;
                vectorInstWord = 0x10431b2c;
                goto LAB_97be1248;
              case 5:
                if (operandSelector == 5) {
                  operandSelector = 0xffffffff;
                  if ((srcTypeWord == (int *)0x5) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x5)) {
                    srcStorageWord = (int *)0xffffffff;
                  }
LAB_97be0954:
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord4 = 0x10410000;
                  goto LAB_97be0960;
                }
                if (operandSelector != 6) goto LAB_97be0954;
                if (srcTypeWord != (int *)0x7) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x10603cc4;
                  vectorInstWord = 0x10431b2c;
                  goto LAB_97be0e64;
                }
                if (srcStorageWord != (int *)0x4) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10403cc4;
                  goto LAB_97be077c;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10600000;
                vectorInstWord4 = 0x10430000;
                goto LAB_97be1484;
              case 6:
                if (operandSelector == 6) {
                  operandSelector = 0xffffffff;
                  if ((srcTypeWord == (int *)0x6) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x6)) {
                    srcStorageWord = (int *)0xffffffff;
                  }
LAB_97be09ec:
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord4 = 0x10420000;
                  goto LAB_97be0960;
                }
                if (operandSelector != 7) goto LAB_97be09ec;
                if (srcTypeWord != (int *)0x4) {
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10403cc4;
                  goto LAB_97be0794;
                }
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcStorageWord != (int *)0x5) {
                  vectorInstWord = 0x10430000;
                  goto LAB_97be1338;
                }
                vectorInstWord = 0x10430000;
                goto LAB_97be132c;
              case 7:
                if (operandSelector != 4) {
                  if (operandSelector != 7) {
                    codeWritePtr2 = *(uint **)(compiler + 0xe30);
                    vectorInstWord4 = 0x10403cc4;
                    goto LAB_97be0ad4;
                  }
                  if ((srcTypeWord == (int *)0x7) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x7)) {
                    srcStorageWord = (int *)0xffffffff;
                  }
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x10603cc4;
                  vectorInstWord = 0x10431a8c;
                  goto LAB_97be0e64;
                }
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcTypeWord != (int *)0x5) {
                  vectorInstWord = 0x10430000;
                  goto LAB_97be0fb8;
                }
                vectorInstWord = 0x10430000;
                if (srcStorageWord != (int *)0x6) goto LAB_97be0fac;
                vectorInstWord = 0x10430000;
                goto LAB_97be0ab4;
              case 8:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10484484;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 1;
                if (operandSelector != 8) break;
                if (srcTypeWord != (int *)0x8) goto switchD_97be0ba4_default;
                storageMatches = srcStorageWord == (int *)0x8;
LAB_97be0b40:
                if (storageMatches) goto switchD_97bdfc38_caseD_6;
                goto switchD_97be0fe8_default;
              case 9:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x1040038c;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 1;
                if (operandSelector != 9) break;
                if (srcTypeWord == (int *)0x9) {
                  storageMatches = srcStorageWord == (int *)0x9;
                  goto LAB_97be0b40;
                }
                goto switchD_97be0ba4_default;
              case 10:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10483cc4;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 1;
                if (operandSelector == 10) {
                  operandSelector = 0xffffffff;
                  if (srcTypeWord != (int *)0xa) goto switchD_97be0ba4_default;
                  srcTypeWord = (int *)0xffffffff;
                  if (srcStorageWord != (int *)0xa) goto switchD_97be0fe8_default;
                  srcStorageWord = (int *)0xffffffff;
                }
              }
              switch(operandSelector) {
              case 0:
                if (srcTypeWord == (int *)0x0) {
                  storageMatches = srcStorageWord == (int *)0x0;
                  codeCursor3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10600000;
LAB_97be0c50:
                  vectorInstWord = vectorInstWord | 0x28c;
                  goto LAB_97be0c54;
                }
                if (srcTypeWord != (int *)0x1) {
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10420000;
LAB_97be0c28:
                  vectorInstWord = vectorInstWord | 300;
                  goto LAB_97be0794;
                }
                if (srcStorageWord != (int *)0x2) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10420000;
LAB_97be0c18:
                  vectorInstWord = vectorInstWord | 0x22c;
                  goto LAB_97be077c;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10420000;
LAB_97be0c08:
                vectorInstWord = vectorInstWord | 0x32c;
                goto LAB_97be1470;
              case 1:
                if (srcTypeWord == (int *)0x1) {
                  storageMatches = srcStorageWord == (int *)0x1;
                  codeCursor3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10610000;
                  goto LAB_97be0c50;
                }
                if (srcTypeWord != (int *)0x2) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x1060012c;
                  goto LAB_97be0e60;
                }
                storageMatches = srcStorageWord == (int *)0x3;
                codeCursor3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1060012c;
                goto LAB_97be0c54;
              case 2:
                if (srcTypeWord == (int *)0x2) {
                  storageMatches = srcStorageWord == (int *)0x2;
                  codeCursor3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10620000;
                  goto LAB_97be0c50;
                }
                if (srcTypeWord != (int *)0x3) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x1060022c;
                  goto LAB_97be0e60;
                }
                storageMatches = srcStorageWord == (int *)0x0;
                codeCursor3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1060022c;
                goto LAB_97be0c54;
              case 3:
                if (srcTypeWord != (int *)0x0) {
                  if (srcTypeWord != (int *)0x3) {
                    codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                    vectorInstWord3 = 0x1060032c;
                    goto LAB_97be0e60;
                  }
                  storageMatches = srcStorageWord == (int *)0x3;
                  codeCursor3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10630000;
                  goto LAB_97be0c50;
                }
                storageMatches = srcStorageWord == (int *)0x1;
                codeCursor3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1060032c;
LAB_97be0c54:
                *codeCursor3 = vectorInstWord;
                codeWritePtr2 = codeCursor3 + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
LAB_97be0f9c:
                if (!storageMatches) {
                  vectorInstWord = 0x10420000;
LAB_97be0fac:
                  vectorInstWord = vectorInstWord | 0x1a2c;
                  goto LAB_97be133c;
                }
                vectorInstWord = 0x10420000;
LAB_97be0ab4:
                vectorInstWord = vectorInstWord | 0x1b2c;
                goto LAB_97be181c;
              case 4:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcTypeWord == (int *)0x4) {
                  storageMatches = srcStorageWord == (int *)0x4;
                  vectorInstWord = 0x10600000;
LAB_97be0da4:
                  *codeWritePtr2 = vectorInstWord | 0x1a8c;
                  goto LAB_97be0e24;
                }
                if (srcTypeWord == (int *)0x5) {
                  storageMatches = srcStorageWord == (int *)0x6;
                  goto LAB_97be0f9c;
                }
                codeWritePtr2 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1042192c;
LAB_97be0794:
                *codeWritePtr2 = vectorInstWord;
                break;
              case 5:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcTypeWord == (int *)0x5) {
                  storageMatches = srcStorageWord == (int *)0x5;
                  vectorInstWord = 0x10610000;
                  goto LAB_97be0da4;
                }
                if (srcTypeWord != (int *)0x6) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x1063192c;
                  goto LAB_97be0e60;
                }
                storageMatches = srcStorageWord == (int *)0x7;
                vectorInstWord = 0x1063192c;
LAB_97be0e1c:
                *codeWritePtr2 = vectorInstWord;
LAB_97be0e24:
                *(uint **)(compiler + 0xe30) = codeWritePtr2 + 1;
                if (!storageMatches) {
                  codeWritePtr3 = codeWritePtr2 + 2;
                  codeWritePtr2[1] = 0x10421a2c;
                  goto LAB_97be1344;
                }
                vectorInstWord = 0x10421b2c;
                goto LAB_97be1418;
              case 6:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcTypeWord == (int *)0x6) {
                  storageMatches = srcStorageWord == (int *)0x6;
                  vectorInstWord = 0x10620000;
                  goto LAB_97be0da4;
                }
                if (srcTypeWord == (int *)0x7) {
                  storageMatches = srcStorageWord == (int *)0x4;
                  vectorInstWord = 0x10631a2c;
                  goto LAB_97be0e1c;
                }
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord3 = 0x10631a2c;
LAB_97be0e60:
                vectorInstWord = 0x1042192c;
LAB_97be0e64:
                *codeWritePtr = vectorInstWord3;
                codeWritePtr2 = codeWritePtr + 1;
                *codeWritePtr2 = vectorInstWord;
                break;
              case 7:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                vectorInstWord6 = codeWritePtr + 1;
                *(undefined4 **)(compiler + 0xe30) = vectorInstWord6;
                if (srcTypeWord == (int *)0x4) {
                  storageMatches = srcStorageWord == (int *)0x5;
                  vectorInstWord3 = 0x10631b2c;
                }
                else {
                  if (srcTypeWord != (int *)0x7) {
                    *vectorInstWord6 = 0x10631b2c;
                    codeWritePtr[2] = 0x1042192c;
                    *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 3;
                    goto switchD_97be0ba4_default;
                  }
                  storageMatches = srcStorageWord == (int *)0x7;
                  vectorInstWord3 = 0x10631a8c;
                }
                *vectorInstWord6 = vectorInstWord3;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 2;
                if (storageMatches) {
                  codeWritePtr3 = codeWritePtr + 3;
                  codeWritePtr[2] = 0x10421b2c;
                  goto LAB_97be1820;
                }
                codeWritePtr3 = codeWritePtr + 3;
                codeWritePtr[2] = 0x10421a2c;
                goto LAB_97be1344;
              case 8:
                if (srcTypeWord != (int *)0x8) {
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1042412c;
                  goto LAB_97be0794;
                }
                if (srcStorageWord == (int *)0x8) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1042432c;
                  goto LAB_97be1470;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1042422c;
                goto LAB_97be077c;
              case 9:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x1060038c;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcTypeWord == (int *)0x9) {
                  storageMatches = srcStorageWord == (int *)0x9;
                  goto LAB_97be0f9c;
                }
LAB_97be0fb4:
                vectorInstWord = 0x10420000;
LAB_97be0fb8:
                *codeWritePtr2 = vectorInstWord | 0x192c;
                break;
              case 10:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10683cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcTypeWord != (int *)0xa) goto LAB_97be0fb4;
                storageMatches = srcStorageWord == (int *)0xa;
                goto LAB_97be0f9c;
              default:
                goto switchD_97be0ba4_default;
              }
              *(uint **)(compiler + 0xe30) = codeWritePtr2 + 1;
switchD_97be0ba4_default:
              switch((int)srcTypeWord) {
              case 0x0:
                if (srcStorageWord == (int *)0x0) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10600000;
LAB_97be1074:
                  vectorInstWord = vectorInstWord | 0x28c;
                  goto LAB_97be107c;
                }
                if (srcStorageWord != (int *)0x1) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10420000;
LAB_97be1050:
                  vectorInstWord = vectorInstWord | 300;
                  goto LAB_97be077c;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10420000;
LAB_97be1040:
                vectorInstWord = vectorInstWord | 0x22c;
                goto LAB_97be1470;
              case 0x1:
                if (srcStorageWord == (int *)0x1) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10610000;
                  goto LAB_97be1074;
                }
                if (srcStorageWord == (int *)0x2) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1060012c;
                  goto LAB_97be107c;
                }
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord3 = 0x1060012c;
LAB_97be1244:
                vectorInstWord = 0x1042192c;
LAB_97be1248:
                *codeWritePtr = vectorInstWord3;
                codeWritePtr3 = codeWritePtr + 1;
                *codeWritePtr3 = vectorInstWord;
                goto LAB_97be0780;
              case 0x2:
                if (srcStorageWord == (int *)0x2) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10620000;
                  goto LAB_97be1074;
                }
                if (srcStorageWord != (int *)0x3) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x1060022c;
                  goto LAB_97be1244;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1060022c;
                goto LAB_97be107c;
              case 0x3:
                if (srcStorageWord != (int *)0x0) {
                  if (srcStorageWord != (int *)0x3) {
                    codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                    vectorInstWord3 = 0x1060032c;
                    goto LAB_97be1244;
                  }
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10630000;
                  goto LAB_97be1074;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1060032c;
LAB_97be107c:
                vectorInstWord4 = 0x10421a2c;
                goto LAB_97be148c;
              case 0x4:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcStorageWord == (int *)0x4) {
                  vectorInstWord = 0x10600000;
LAB_97be11c0:
                  vectorInstWord = vectorInstWord | 0x1a8c;
                  goto LAB_97be1290;
                }
                if (srcStorageWord != (int *)0x5) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1042192c;
                  goto LAB_97be077c;
                }
                codeWritePtr3 = codeWritePtr + 2;
                *codeWritePtr2 = 0x10421a2c;
                goto LAB_97be1820;
              case 0x5:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcStorageWord == (int *)0x5) {
                  vectorInstWord = 0x10610000;
                  goto LAB_97be11c0;
                }
                if (srcStorageWord != (int *)0x6) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x1063192c;
                  goto LAB_97be1244;
                }
                vectorInstWord = 0x1063192c;
                goto LAB_97be1290;
              case 0x6:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcStorageWord == (int *)0x6) {
                  vectorInstWord = 0x10620000;
                  goto LAB_97be11c0;
                }
                if (srcStorageWord != (int *)0x7) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x10631a2c;
                  goto LAB_97be1244;
                }
                vectorInstWord = 0x10631a2c;
LAB_97be1290:
                *codeWritePtr2 = vectorInstWord;
                codeWritePtr2[1] = 0x10421a2c;
                *(uint **)(compiler + 0xe30) = codeWritePtr2 + 2;
                goto switchD_97bdfc38_caseD_6;
              case 0x7:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcStorageWord == (int *)0x4) {
                  vectorInstWord = 0x10631b2c;
                  goto LAB_97be1290;
                }
                vectorInstWord = 0x10630000;
                if (srcStorageWord == (int *)0x7) goto LAB_97be11c0;
                *codeWritePtr2 = 0x10631b2c;
                codeWritePtr[2] = 0x1042192c;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 3;
                break;
              case 0x8:
                if (srcStorageWord == (int *)0x8) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1042422c;
                  goto LAB_97be1470;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1042412c;
LAB_97be077c:
                *codeWritePtr3 = vectorInstWord;
LAB_97be0780:
                codeWritePtr3 = codeWritePtr3 + 1;
LAB_97be1344:
                *(uint **)(compiler + 0xe30) = codeWritePtr3;
                break;
              case 0x9:
                storageMatches = srcStorageWord == (int *)0x9;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord3 = 0x1060038c;
                goto LAB_97be1318;
              case 0xa:
                storageMatches = srcStorageWord == (int *)0xa;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord3 = 0x10683cc4;
LAB_97be1318:
                *codeWritePtr = vectorInstWord3;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (!storageMatches) {
                  vectorInstWord = 0x10420000;
LAB_97be1338:
                  vectorInstWord = vectorInstWord | 0x192c;
LAB_97be133c:
                  codeWritePtr3 = codeWritePtr2 + 1;
                  *codeWritePtr2 = vectorInstWord;
                  goto LAB_97be1344;
                }
                vectorInstWord = 0x10420000;
LAB_97be132c:
                vectorInstWord = vectorInstWord | 0x1a2c;
LAB_97be181c:
                codeWritePtr3 = codeWritePtr2 + 1;
                *codeWritePtr2 = vectorInstWord;
                goto LAB_97be1820;
              }
switchD_97be0fe8_default:
              switch((int)srcStorageWord) {
              case 0x0:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10420000;
LAB_97be13a0:
                vectorInstWord = vectorInstWord | 300;
                goto LAB_97be1470;
              case 0x1:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord4 = 0x10420000;
                vectorInstWord = 0x1060012c;
                break;
              case 0x2:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord4 = 0x10420000;
                vectorInstWord = 0x1060022c;
                break;
              case 0x3:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord4 = 0x10420000;
                vectorInstWord = 0x1060032c;
                break;
              case 0x4:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10600000;
                goto LAB_97be1480;
              case 0x5:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord = 0x1063192c;
                goto LAB_97be1404;
              case 0x6:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord = 0x10631a2c;
                goto LAB_97be1404;
              case 0x7:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord = 0x10631b2c;
LAB_97be1404:
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *codeWritePtr2 = vectorInstWord;
                vectorInstWord = 0x1042192c;
LAB_97be1418:
                codeWritePtr3 = codeWritePtr2 + 2;
                codeWritePtr2[1] = vectorInstWord;
                goto LAB_97be1820;
              case 0x8:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1042412c;
LAB_97be1470:
                *codeWritePtr3 = vectorInstWord;
                goto LAB_97be1494;
              case 0x9:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord4 = 0x10420000;
                vectorInstWord = 0x1060038c;
                break;
              case 0xa:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10680000;
LAB_97be1480:
                vectorInstWord4 = 0x10420000;
LAB_97be1484:
                vectorInstWord = vectorInstWord | 0x3cc4;
                break;
              default:
                goto switchD_97bdfc38_caseD_6;
              }
              vectorInstWord4 = vectorInstWord4 | 0x192c;
LAB_97be148c:
              *codeWritePtr3 = vectorInstWord;
              codeWritePtr3 = codeWritePtr3 + 1;
              *codeWritePtr3 = vectorInstWord4;
LAB_97be1494:
              codeWritePtr3 = codeWritePtr3 + 1;
LAB_97be1820:
              *(uint **)(compiler + 0xe30) = codeWritePtr3;
              goto switchD_97bdfc38_caseD_6;
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
              srcStorageWord = *(int **)(compiler + 0xe20);
              if (*(int *)(srcStorageWord[0x360] + 0x38) - 0x8b30U < 2) {
                srcTypeWord = *(int **)(*(int *)(compiler + 0xe28) + 0x58);
                textureObject = *(undefined4 *)
                         (srcStorageWord[*(ushort *)(*(int *)(compiler + 0xe28) + 0x68) + 0x361] + *srcTypeWord);
              }
              else {
                textureObject = *(undefined4 *)(*(int *)(compiler + 0xe28) + 0x10c);
              }
              ((int (*)())_PPCTextureSamplerAttachGLDContext)(*(undefined4 *)(compiler + 0xe1c),srcStorageWord[0x367]);
              projectionEnabled = 0;
              if ((opcode == 0x43) || (opcode == 0x45)) {
                projectionEnabled = 1;
              }
              ((int (*)())_PPCTextureSamplerSetProjectionEnabled)(*(undefined4 *)(compiler + 0xe1c),projectionEnabled);
              ((int (*)())_PPCTextureSamplerSetLodBiasEnabled)(*(undefined4 *)(compiler + 0xe1c),(uint)(opcode - 0x44U < 2));
              if (((opcode == 0x44) &&
                  (programInfo = *(int *)(*(int *)(*(int *)(compiler + 0xe20) + 0xd80) + 0x38),
                  programInfo != 0x8b30)) && (programInfo != 0x8b31)) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x1043028c;
                codeWritePtr[1] = 0x1000436a;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 2;
              }
              textureTarget = *(uint *)(*(int *)(compiler + 0xe28) + 0x110);
              if (textureTarget == 2) {
                srcBankWord = *(undefined4 *)(compiler + 0xe30);
                emitResult64 = ((int (*)())_PPCTextureSamplerSampleTexelRECTRTCAV)(*(undefined4 *)(compiler + 0xe1c),textureObject,srcBankWord);
              }
              else {
                passThroughR4 = leftoverR4_07;
                if (textureTarget < 3) {
                  if (textureTarget != 1) goto switchD_97bdfc38_caseD_6;
                  srcBankWord = *(undefined4 *)(compiler + 0xe30);
                  emitResult64 = ((int (*)())_PPCTextureSamplerSampleTexel3DRTCAV)(*(undefined4 *)(compiler + 0xe1c),textureObject,srcBankWord);
                }
                else if (textureTarget == 3) {
                  srcBankWord = *(undefined4 *)(compiler + 0xe30);
                  emitResult64 = ((int (*)())_PPCTextureSamplerSampleTexel2DRTCAV)(*(undefined4 *)(compiler + 0xe1c),textureObject,srcBankWord);
                }
                else {
                  if (textureTarget != 4) goto switchD_97bdfc38_caseD_6;
                  srcBankWord = *(undefined4 *)(compiler + 0xe30);
                  emitResult64 = ((int (*)())_PPCTextureSamplerSampleTexel1DRTCAV)(*(undefined4 *)(compiler + 0xe1c),textureObject,srcBankWord);
                }
              }
LAB_97be1634:
              passThroughR4 = (undefined4)emitResult64;
              *(int *)(compiler + 0xe30) = (int)((ulonglong)emitResult64 >> 0x20);
              goto switchD_97bdfc38_caseD_6;
            case 0x48:
              if ((*(byte *)(*(int *)(compiler + 0xe28) + 0x28) & 1) != 0) {
                chunkIndex2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpArlAVRTC,*(undefined4 *)(compiler + 0xe30))
                ;
                passThroughR4 = (undefined4)chunkIndex2;
                *(int *)(compiler + 0xe30) =
                     *(int *)(compiler + 0xe30) + (int)((ulonglong)chunkIndex2 >> 0x20) * 4;
              }
            case 0x49:
            case 0x4a:
            case 0x4c:
            case 0x4f:
            case 0x56:
            case 0x57:
            case 0x59:
            case 0x5a:
            case 0x5b:
            case 0x6a:
              goto switchD_97bdfc38_caseD_49;
            case 0x4b:
              curInst = *(int *)(compiler + 0xe28);
              srcBankWord = *(undefined4 *)(curInst + 0x10);
              srcSwizzleWord = *(undefined4 *)(curInst + 0x14);
              srcIndexWord = *(int *)(curInst + 0x18);
              srcStorageWord = *(int **)(curInst + 0x1c);
              ((int (*)())_PPCRuntimeCompilerTestConditionRegisterAV)(compiler,*(undefined4 *)(curInst + 0xc),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                         *(undefined4 *)(curInst + 0x20),*(undefined4 *)(curInst + 0x24),
                         *(undefined4 *)(curInst + 0x28));
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              *codeWritePtr = 0x10634e86;
              codeWritePtr[1] = 0x4098000c;
              codeWritePtr[2] = 0x419a0008;
              srcTypeWord = codeWritePtr + 3;
              passThroughR4 = leftoverR4_08;
              goto LAB_97be16ec;
            case 0x4d:
              codeWritePtr2 = *(uint **)(compiler + 0xe30);
              *codeWritePtr2 = *(int *)(compiler + 0xe40) - (int)codeWritePtr2 & 0x3fffffcU | 0x48000000;
              *(uint **)(compiler + 0xe30) = codeWritePtr2 + 1;
              goto switchD_97bdfc38_caseD_49;
            case 0x54:
            case 0x58:
              codeWordPtr = *(int **)(*(int *)(compiler + 0xe20) + 0xd80);
              curInst = *codeWordPtr + *(int *)(*(int *)(compiler + 0xe28) + 8) * 0x11c;
              if ((uint)codeWordPtr[1] < curInst - 0x11cU) {
                codeWritePtr2 = *(uint **)(compiler + 0xe30);
                branchWord = *(int *)(compiler + 0xe40) - (int)codeWritePtr2;
              }
              else {
                codeWritePtr2 = *(uint **)(compiler + 0xe30);
                branchWord = *(int *)(curInst + -4) - ((int)codeWritePtr2 - *(int *)(compiler + 0xe2c));
              }
              *codeWritePtr2 = branchWord & 0x3fffffc | 0x48000000;
              goto LAB_97be17b0;
            case 0x55:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              codeWritePtr[1] = 0x40980008;
              srcTypeWord = codeWritePtr + 2;
              *codeWritePtr = 0x10604cc6;
LAB_97be16ec:
              *(int **)(compiler + 0xe30) = srcTypeWord;
              codeWordPtr = *(int **)(*(int *)(compiler + 0xe20) + 0xd80);
              curInst = *codeWordPtr + *(int *)(*(int *)(compiler + 0xe28) + 8) * 0x11c;
              if ((uint)codeWordPtr[1] < curInst - 0x11cU) {
                branchWord = *(int *)(compiler + 0xe40) - (int)srcTypeWord;
              }
              else {
                branchWord = *(int *)(curInst + -4) - ((int)srcTypeWord - *(int *)(compiler + 0xe2c));
              }
              codeWritePtr2 = *(uint **)(compiler + 0xe30);
              *codeWritePtr2 = branchWord & 0x3fffffc | 0x48000000;
LAB_97be17b0:
              *(uint **)(compiler + 0xe30) = codeWritePtr2 + 1;
switchD_97bdfc38_caseD_49:
              writesDestination = false;
              goto LAB_97be1860;
            case 0x68:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpRefractAVRTC;
              break;
            case 0x6b:
              codeWordPtr = *(int **)(*(int *)(compiler + 0xe20) + 0xd80);
              curInst = *codeWordPtr + *(int *)(*(int *)(compiler + 0xe28) + 8) * 0x11c;
              if ((uint)codeWordPtr[1] < curInst - 0x11cU) {
                codeWritePtr2 = *(uint **)(compiler + 0xe30);
                vectorInstWord = *(int *)(compiler + 0xe40) - (int)codeWritePtr2;
              }
              else {
                codeWritePtr2 = *(uint **)(compiler + 0xe30);
                vectorInstWord = *(int *)(curInst + -4) - ((int)codeWritePtr2 - *(int *)(compiler + 0xe2c));
              }
              vectorInstWord = vectorInstWord & 0x3fffffc | 0x48000000;
              writesDestination = false;
              goto LAB_97be181c;
            case 0x6c:
              curInst = *(int *)(compiler + 0xe28);
              if ((*(int *)(curInst + 0x24) == 3) && (*(int *)(curInst + 0x4c) == 1)) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpTruncateAVRTC;
              }
              else {
                if ((*(int *)(curInst + 0x24) != 4) ||
                   ((*(int *)(curInst + 0x4c) != 1 && (*(int *)(curInst + 0x4c) != 3))))
                goto switchD_97bdfc38_caseD_0;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpSetNotEqualToZeroAVRTC;
              }
              break;
            case 0x6d:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpDestinationScalarSelectAVRTC;
              break;
            case 0x6f:
              codeCursor4 = *(undefined4 **)(compiler + 0xe30);
              *codeCursor4 = 0x39e001b0;
              codeCursor4[1] = 0x7c6378ce;
              codeWritePtr = codeCursor4 + 3;
              codeCursor4[2] = 0x100038ee;
              opTemplate = &_glpOpEx2AVRTC;
              *(undefined4 **)(compiler + 0xe30) = codeWritePtr;
              break;
            case 0x70:
              chunkIndex2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpLg2AVRTC,*(undefined4 *)(compiler + 0xe30));
              passThroughR4 = (undefined4)chunkIndex2;
              srcIndexWord = *(int *)(compiler + 0xe30);
              ppcInstWord = (int)((ulonglong)chunkIndex2 >> 0x20) * 4;
              srcTypeWord = (int *)(srcIndexWord + ppcInstWord);
              srcStorageWord = srcTypeWord + 1;
              *(undefined4 *)(srcIndexWord + ppcInstWord) = 0x39e001c0;
              srcTypeWord[1] = 0x7c6378ce;
              srcTypeWord[2] = 0x104238ee;
              *(int **)(compiler + 0xe30) = srcTypeWord + 3;
              goto switchD_97bdfc38_caseD_6;
            }
            chunkIndex2 = _glpRTCAddAChunk_97bd7cbc(opTemplate,codeWritePtr);
            passThroughR4 = (undefined4)chunkIndex2;
            *(int *)(compiler + 0xe30) =
                 *(int *)(compiler + 0xe30) + (int)((ulonglong)chunkIndex2 >> 0x20) * 4;
switchD_97bdfc38_caseD_6:
            if (writesDestination) {
              if (saturateFlag != '\0') {
                chunkWordCount = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpSaturateAVRTC,*(undefined4 *)(compiler + 0xe30));
                *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + chunkWordCount * 4;
              }
              ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,operandWidth);
              passThroughR4 = leftoverR4_09;
            }
LAB_97be1860:
            operandWidth = operandWidth + 1;
          } while (operandWidth < elementCount);
        }
        codeWritePtr4 = *(int *)(compiler + 0xe2c);
        if (codeBufferCapacity - 3000U < (uint)(*(int *)(compiler + 0xe30) - codeWritePtr4)) {
          codeBufferCapacity = codeBufferCapacity + 0x2000;
          emitResult64 = _glpDCBRealloc(codeWritePtr4,codeBufferCapacity);
          codeBufferBase = (int)((ulonglong)emitResult64 >> 0x20);
          passThroughR4 = (undefined4)emitResult64;
          *(int *)(compiler + 0xe2c) = codeBufferBase;
          codeWritePtr4 = codeBufferBase - codeWritePtr4 >> 2;
          if (codeWritePtr4 != 0) {
            codeWritePtr4 = codeWritePtr4 * 4;
            srcTypeWord = (int *)(*(int *)(compiler + 0xe3c) + codeWritePtr4);
            *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + codeWritePtr4;
            srcStorageWord = (int *)(*(int *)(compiler + 0xe40) + codeWritePtr4);
            *(int *)(compiler + 0xe34) = *(int *)(compiler + 0xe34) + codeWritePtr4;
            *(int *)(compiler + 0xe38) = *(int *)(compiler + 0xe38) + codeWritePtr4;
            *(int **)(compiler + 0xe3c) = srcTypeWord;
            *(int **)(compiler + 0xe40) = srcStorageWord;
          }
        }
LAB_97be18e4:
        inst = *(undefined4 **)(compiler + 0xe28);
      }
      programInfo = *(int *)(compiler + 0xe24);
      instructionListHead = inst + 0x47;
      if (inst == *(undefined4 **)(programInfo + 4)) {
        instructionListHead = (undefined4 *)0x0;
      }
      *(undefined4 **)(compiler + 0xe28) = instructionListHead;
    }
    passIndex = *(int *)(compiler + 0xe48);
    if (passIndex == 0) {
      *(undefined4 **)(compiler + 0xe40) = *(undefined4 **)(compiler + 0xe30);
      inst = *(undefined4 **)(compiler + 0xe30);
      while (((uint)inst & 0xf) != 0) {
        *inst = 0x60000000;
        *(undefined4 **)(compiler + 0xe30) = inst + 1;
        inst = inst + 1;
      }
      _PPCRuntimeCompilerInitialise(compiler,1);
      passStartCursor = *(undefined4 *)(compiler + 0xe34);
      passThroughR4 = leftoverR4_10;
LAB_97be1ac8:
      passIndex = *(int *)(compiler + 0xe48);
      *(undefined4 *)(compiler + 0xe30) = passStartCursor;
    }
    else if (passIndex == 1) {
      _PPCRuntimeCompilerBackupRegister(compiler,0);
      _PPCRuntimeCompilerBackupRegister(compiler,1);
      _PPCRuntimeCompilerBackupRegister(compiler,2);
      _PPCRuntimeCompilerDirtyRegistersContainingAttributes(compiler);
      _PPCRuntimeCompilerDirtyRegistersContainingTemps(compiler);
      _PPCRuntimeCompilerDirtyRegistersContainingParams(compiler);
      if (((uint)*(undefined4 **)(compiler + 0xe30) & 0xf) != 0) {
        inst = (undefined4 *)0x60000000;
        codeWritePtr = *(undefined4 **)(compiler + 0xe30);
        do {
          paddedCursor = codeWritePtr + 1;
          *codeWritePtr = 0x60000000;
          *(undefined4 **)(compiler + 0xe30) = paddedCursor;
          codeWritePtr = paddedCursor;
        } while (((uint)paddedCursor & 0xf) != 0);
      }
      _PPCRuntimeCompilerInitialiseVariableInfo(compiler);
      passIndex = *(int *)(compiler + 0xe48);
      *(undefined4 *)(compiler + 0xe38) = *(undefined4 *)(compiler + 0xe30);
      passThroughR4 = leftoverR4_11;
    }
    else {
      if (passIndex == 2) {
        inst = *(undefined4 **)(compiler + 0xe30);
        *(undefined4 **)(compiler + 0xe40) = inst;
        if ((*(int *)(programInfo + 0x38) == 0x8804) || (*(int *)(programInfo + 0x38) == 0x8b30)) {
          if ((*(uint *)(programInfo + 0x34) & 2) != 0) {
            ((int (*)())_PPCRuntimeCompilerWriteFinalFragmentToBuffer)(compiler,passThroughR4,srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,inst,srcTypeWord);
            inst = *(undefined4 **)(compiler + 0xe30);
          }
        }
        else {
          _PPCRuntimeCompilerBackupRegister(compiler,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x39e00010;
          codeCursor[1] = 0x7c0678ce;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          programInfo = _glpRTCAddAChunk_97bd7cbc(&_glpOpClippingAVRTC,codeCursor + 2);
          inst = (undefined4 *)(*(int *)(compiler + 0xe30) + programInfo * 4);
          *(undefined4 **)(compiler + 0xe30) = inst;
        }
        *(undefined4 **)(compiler + 0xe3c) = inst;
        _PPCRuntimeCompilerBackupRegister(compiler,0);
        _PPCRuntimeCompilerBackupRegister(compiler,1);
        _PPCRuntimeCompilerBackupRegister(compiler,2);
        _PPCRuntimeCompilerDirtyRegistersContainingAttributes(compiler);
        _PPCRuntimeCompilerDirtyRegistersContainingTemps(compiler);
        _PPCRuntimeCompilerDirtyRegistersContainingParams(compiler);
        _PPCRuntimeCompilerInitialiseVariableInfo(compiler);
        passStartCursor = *(undefined4 *)(compiler + 0xe38);
        passThroughR4 = leftoverR4_12;
        goto LAB_97be1ac8;
      }
      if (passIndex == 3) {
        if ((*(int *)(programInfo + 0x38) == 0x8804) || (*(int *)(programInfo + 0x38) == 0x8b30)) {
          if ((*(uint *)(programInfo + 0x34) & 2) != 0) {
            ((int (*)())_PPCRuntimeCompilerWriteFinalFragmentToBuffer)(compiler,passThroughR4,srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,inst,srcTypeWord);
          }
        }
        else {
          _PPCRuntimeCompilerBackupRegister(compiler,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x39e00010;
          codeCursor[1] = 0x7c0678ce;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          programInfo = _glpRTCAddAChunk_97bd7cbc(&_glpOpClippingAVRTC,codeCursor + 2);
          *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + programInfo * 4;
        }
        ((int (*)())_PPCRuntimeCompilerStride)(compiler);
        ((int (*)())_PPCRuntimeCompilerLoop)(compiler);
        passIndex = *(int *)(compiler + 0xe48);
        passThroughR4 = leftoverR4_13;
      }
    }
    *(uint *)(compiler + 0xe48) = passIndex + 1U;
    if (3 < passIndex + 1U) {
      ((int (*)())_PPCRuntimeCompilerWriteEpilogAV)(compiler);
      codeWordCount = *(int *)(compiler + 0xe30) - *(int *)(compiler + 0xe2c) >> 2;
      grownCodeBuffer = _glpDCBRealloc(*(int *)(compiler + 0xe2c),codeWordCount << 2);
      *(undefined4 *)(compiler + 0xe2c) = grownCodeBuffer;
                    
                    
      (*_glpPushInstructions)(codeWordCount,grownCodeBuffer,srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,inst,srcTypeWord);
      return;
    }
  } while( true );
}

/* _PPCRuntimeCompilerGetCompiledResult @ 0x97be1be0 (8 bytes) */
int _PPCRuntimeCompilerGetCompiledResult(compiler)
  int compiler;
{
  return *(undefined4 *)(compiler + 0xe2c);
}

/* _PPCTextureSamplerCreate @ 0x97be1be8 (12 bytes) */
int _PPCTextureSamplerCreate()
{
  undefined4 allocation;
  
  allocation = _calloc(0x2c,1);
  return allocation;
}

/* _PPCTextureSamplerInitialise @ 0x97be1bf4 (16 bytes) */
int _PPCTextureSamplerInitialise(sampler)
  int sampler;
{
  *(undefined4 *)(sampler + 0x18) = 0xffffffff;
  *(undefined4 *)(sampler + 0x14) = 0xffffffff;
  return;
}

/* _PPCTextureSamplerAttachGLDContext @ 0x97be1c08 (8 bytes) */
int _PPCTextureSamplerAttachGLDContext(sampler, gldContext)
  undefined4 *sampler;
  undefined4 gldContext;
{
  *sampler = gldContext;
  return;
}

/* _PPCTextureSamplerSetProjectionEnabled @ 0x97be1c10 (8 bytes) */
int _PPCTextureSamplerSetProjectionEnabled(sampler, projectionEnabled)
  int sampler;
  undefined4 projectionEnabled;
{
  *(undefined4 *)(sampler + 0x20) = projectionEnabled;
  return;
}

/* _PPCTextureSamplerSetLodBiasEnabled @ 0x97be1c18 (8 bytes) */
int _PPCTextureSamplerSetLodBiasEnabled(sampler, lodBiasEnabled)
  int sampler;
  undefined4 lodBiasEnabled;
{
  *(undefined4 *)(sampler + 0x24) = lodBiasEnabled;
  return;
}

/* _PPCTextureSamplerAttachDerivatives @ 0x97be1c20 (12 bytes) */
void _PPCTextureSamplerAttachDerivatives(int sampler,undefined4 derivatives,double derivativeScale)
{
  *(float *)(sampler + 0x10) = (float)derivativeScale;
  *(undefined4 *)(sampler + 0xc) = derivatives;
  return;
}

/* _glpRTCAddAChunk_97be1c2c @ 0x97be1c2c (48 bytes) */
int _glpRTCAddAChunk_97be1c2c(chunk, dest)
  int *chunk;
  int *dest;
{
  int word;
  int wordCount;
  
  wordCount = 0;
  word = *chunk;
  while (word != 0) {
    *dest = word;
    wordCount = wordCount + 1;
    chunk = chunk + 1;
    dest = dest + 1;
    word = *chunk;
  }
  return wordCount;
}

/* _PPCTextureSamplerSampleTexel1DRTCNO @ 0x97be1c5c (8 bytes) */
int _PPCTextureSamplerSampleTexel1DRTCNO(sampler, textureUnit, codeCursor)
  undefined4 sampler;
  undefined4 textureUnit;
  undefined4 codeCursor;
{
  return codeCursor;
}

/* _PPCTextureSamplerSampleTexel2DRTCNO @ 0x97be1c64 (560 bytes) */
int _PPCTextureSamplerSampleTexel2DRTCNO(sampler, textureUnit, codeCursor)
  int *sampler;
  uint textureUnit;
  uint *codeCursor;
{
  int coordChunkWordCount;
  short wrapModeS;
  short wrapModeT;
  uint emittedWord;
  int *textureObject;
  undefined *coordChunk;
  int sampleWordCount;
  int borderMode;
  uint *emitPtr;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if (textureObject != (int *)0x0) {
    sampler[1] = (int)textureObject;
    wrapModeS = *(short *)(*textureObject + 0x10);
    wrapModeT = *(short *)(*textureObject + 0x12);
    if ((wrapModeS == -0x7ed3) || (wrapModeT == -0x7ed3)) {
      borderMode = 0x812d;
    }
    else if ((wrapModeS == 0x2900) || (borderMode = 0, wrapModeT == 0x2900)) {
      borderMode = 0x2900;
    }
    if (((sampler[5] != textureUnit) || (sampler[6] != 3)) || (sampler[7] != borderMode)) {
      *codeCursor = textureUnit * 4 & 0xfffc | 0x82220000;
      emitPtr = codeCursor + 1;
      if (wrapModeS == 0x2901) {
        *emitPtr = 0x82910160;
        emitPtr = codeCursor + 2;
      }
      if (wrapModeT == 0x2901) {
        *emitPtr = 0x82b10164;
        emitPtr = emitPtr + 1;
      }
      if (borderMode == 0x812d) {
        *emitPtr = 0x82510190;
        emitPtr[1] = 0xc1d10170;
        emitPtr[2] = 0xc1f10174;
        emittedWord = 0x823101c4;
      }
      else if (borderMode == 0x2900) {
        *emitPtr = 0x82510190;
        emitPtr[1] = 0xc1d10170;
        emitPtr[2] = 0xc1f10174;
        emittedWord = 0x823101c8;
      }
      else {
        *emitPtr = 0x82510140;
        emitPtr[1] = 0xc1d10120;
        emitPtr[2] = 0xc1f10124;
        emittedWord = 0x823101c0;
      }
      emitPtr[3] = emittedWord;
      codeCursor = emitPtr + 4;
      sampler[7] = borderMode;
      sampler[5] = textureUnit;
      sampler[6] = 3;
    }
    if (wrapModeS == 0x2901) {
      if (wrapModeT == 0x2901) {
        coordChunk = &_glpOpTexPrepareCoords2RRRTC;
      }
      else {
        coordChunk = &_glpOpTexPrepareCoords2RCRTC;
      }
    }
    else if (wrapModeT == 0x2901) {
      coordChunk = &_glpOpTexPrepareCoords2CRRTC;
    }
    else {
      coordChunk = &_glpOpTexPrepareCoords2CCRTC;
    }
    coordChunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(coordChunk,codeCursor);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSampleRTC,codeCursor + coordChunkWordCount);
    codeCursor = codeCursor + coordChunkWordCount + sampleWordCount;
  }
  return codeCursor;
}

/* _PPCTextureSamplerSampleTexel3DRTCNO @ 0x97be1e94 (8 bytes) */
int _PPCTextureSamplerSampleTexel3DRTCNO(sampler, textureUnit, codeCursor)
  undefined4 sampler;
  undefined4 textureUnit;
  undefined4 codeCursor;
{
  return codeCursor;
}

/* _PPCTextureSamplerSampleTexelRECTRTCNO @ 0x97be1e9c (488 bytes) */
int _PPCTextureSamplerSampleTexelRECTRTCNO(sampler, textureUnit, codeCursor)
  int *sampler;
  uint textureUnit;
  uint *codeCursor;
{
  int coordChunkWordCount;
  short wrapModeS;
  short wrapModeT;
  uint emittedWord;
  int *textureObject;
  int sampleWordCount;
  int borderMode;
  uint *emitPtr;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if (textureObject != (int *)0x0) {
    sampler[1] = (int)textureObject;
    wrapModeS = *(short *)(*textureObject + 0x10);
    wrapModeT = *(short *)(*textureObject + 0x12);
    if ((wrapModeS == -0x7ed3) || (wrapModeT == -0x7ed3)) {
      borderMode = 0x812d;
    }
    else if ((wrapModeS == 0x2900) || (borderMode = 0, wrapModeT == 0x2900)) {
      borderMode = 0x2900;
    }
    if ((sampler[5] != textureUnit) || (sampler[6] != 2)) {
      *codeCursor = textureUnit * 4 & 0xfffc | 0x82220000;
      emitPtr = codeCursor + 1;
      if (wrapModeS == 0x2901) {
        *emitPtr = 0x82910160;
        emitPtr = codeCursor + 2;
      }
      if (wrapModeT == 0x2901) {
        *emitPtr = 0x82b10164;
        emitPtr = emitPtr + 1;
      }
      if (borderMode == 0x812d) {
        *emitPtr = 0x82510190;
        emitPtr[1] = 0xc1d10170;
        emitPtr[2] = 0xc1f10174;
        emittedWord = 0x823101c4;
      }
      else if (borderMode == 0x2900) {
        *emitPtr = 0x82510190;
        emitPtr[1] = 0xc1d10170;
        emitPtr[2] = 0xc1f10174;
        emittedWord = 0x823101c8;
      }
      else {
        *emitPtr = 0x82510140;
        emitPtr[1] = 0xc1d10120;
        emitPtr[2] = 0xc1f10124;
        emittedWord = 0x823101c0;
      }
      emitPtr[3] = emittedWord;
      codeCursor = emitPtr + 4;
      sampler[7] = borderMode;
      sampler[5] = textureUnit;
      sampler[6] = 2;
    }
    coordChunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexPrepareCoords4CCRTC,codeCursor);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSampleRTC,codeCursor + coordChunkWordCount);
    codeCursor = codeCursor + coordChunkWordCount + sampleWordCount;
  }
  return codeCursor;
}

/* _PPCTextureSamplerWrapCoordinates1DRTCAV @ 0x97be2084 (144 bytes) */
int _PPCTextureSamplerWrapCoordinates1DRTCAV(sampler, codeCursor)
  int sampler;
  int codeCursor;
{
  short minFilter;
  short wrapModeS;
  undefined *coordChunk;
  int chunkWordCount;
  
  minFilter = *(short *)(**(int **)(sampler + 4) + 0x16);
  wrapModeS = *(short *)(**(int **)(sampler + 4) + 0x10);
  if (((minFilter == 0x2600) || (minFilter == 0x2700)) && (wrapModeS == 0x2900)) {
    wrapModeS = -0x7ed1;
  }
  if (wrapModeS == 0x2901) {
    coordChunk = &_glpOpTexWrapCoordsRRRAVRTC;
  }
  else {
    coordChunk = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(coordChunk,codeCursor);
  return codeCursor + chunkWordCount * 4;
}

/* _PPCTextureSamplerWrapCoordinates2DRTCAV @ 0x97be2114 (212 bytes) */
int _PPCTextureSamplerWrapCoordinates2DRTCAV(sampler, codeCursor)
  int sampler;
  int codeCursor;
{
  int chunkWordCount;
  short wrapModeS;
  undefined *coordChunk;
  int textureState;
  short wrapModeT;
  
  textureState = **(int **)(sampler + 4);
  wrapModeS = *(short *)(textureState + 0x10);
  wrapModeT = *(short *)(textureState + 0x12);
  if ((*(short *)(textureState + 0x16) == 0x2600) || (*(short *)(textureState + 0x16) == 0x2700)) {
    if (wrapModeS == 0x2900) {
      wrapModeS = -0x7ed1;
    }
    if (wrapModeT == 0x2900) {
      wrapModeT = -0x7ed1;
    }
  }
  if (wrapModeS == 0x2901) {
    if (wrapModeT == 0x2901) {
      coordChunk = &_glpOpTexWrapCoordsRRRAVRTC;
    }
    else {
      coordChunk = &_glpOpTexWrapCoordsRCCAVRTC;
    }
  }
  else if (wrapModeT == 0x2901) {
    coordChunk = &_glpOpTexWrapCoordsCRRAVRTC;
  }
  else {
    coordChunk = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(coordChunk,codeCursor);
  return codeCursor + chunkWordCount * 4;
}

/* _PPCTextureSamplerWrapCoordinates3DRTCAV @ 0x97be21e8 (328 bytes) */
int _PPCTextureSamplerWrapCoordinates3DRTCAV(sampler, codeCursor)
  int sampler;
  int codeCursor;
{
  int chunkWordCount;
  short wrapModeS;
  undefined *coordChunk;
  int textureState;
  short wrapModeR;
  short wrapModeT;
  
  textureState = **(int **)(sampler + 4);
  wrapModeS = *(short *)(textureState + 0x10);
  wrapModeT = *(short *)(textureState + 0x12);
  wrapModeR = *(short *)(textureState + 0x14);
  if ((*(short *)(textureState + 0x16) == 0x2600) || (*(short *)(textureState + 0x16) == 0x2700)) {
    if (wrapModeS == 0x2900) {
      wrapModeS = -0x7ed1;
    }
    if (wrapModeT == 0x2900) {
      wrapModeT = -0x7ed1;
    }
    if (wrapModeR == 0x2900) {
      wrapModeR = -0x7ed1;
    }
  }
  if (wrapModeS == 0x2901) {
    if (wrapModeT == 0x2901) {
      if (wrapModeR == 0x2901) {
        coordChunk = &_glpOpTexWrapCoordsRRRAVRTC;
      }
      else {
        coordChunk = &_glpOpTexWrapCoordsRRCAVRTC;
      }
    }
    else if (wrapModeR == 0x2901) {
      coordChunk = &_glpOpTexWrapCoordsRCRAVRTC;
    }
    else {
      coordChunk = &_glpOpTexWrapCoordsRCCAVRTC;
    }
  }
  else if (wrapModeT == 0x2901) {
    if (wrapModeR == 0x2901) {
      coordChunk = &_glpOpTexWrapCoordsCRRAVRTC;
    }
    else {
      coordChunk = &_glpOpTexWrapCoordsCRCAVRTC;
    }
  }
  else if (wrapModeR == 0x2901) {
    coordChunk = &_glpOpTexWrapCoordsCCRAVRTC;
  }
  else {
    coordChunk = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(coordChunk,codeCursor);
  return codeCursor + chunkWordCount * 4;
}

/* _PPCTextureSamplerSampleTexel1DRTCAV @ 0x97be2330 (780 bytes) */
int _PPCTextureSamplerSampleTexel1DRTCAV(sampler, textureUnit, codeCursor)
  int *sampler;
  int textureUnit;
  uint *codeCursor;
{
  undefined4 *resultCursor;
  undefined4 *emitCursor;
  uint *afterLambdaPtr;
  int lambdaWordCount;
  uint unitLoadWord;
  int *textureObject;
  uint *stateEmitPtr;
  
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 4) {
    sampler[10] = 1;
    if (sampler[9] != 0) {
      *codeCursor = 0x39e00200;
      codeCursor[1] = 0x7c4379ce;
      codeCursor = codeCursor + 2;
    }
    unitLoadWord = textureUnit * 4 & 0xfffcU | 0x82220000;
    *codeCursor = unitLoadWord;
    codeCursor[1] = 0x39e00120;
    codeCursor[2] = 0x7df178ce;
    codeCursor[3] = 0x39e00040;
    codeCursor[4] = 0x7c2c78ce;
    codeCursor[5] = 0x39ef00c0;
    codeCursor[6] = 0x7c4c78ce;
    lambdaWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexCalculateLambda1DAVRTC,codeCursor + 7);
    afterLambdaPtr = codeCursor + 7 + lambdaWordCount;
    *afterLambdaPtr = 0x39e00040;
    afterLambdaPtr[1] = 0x7c9178ce;
    afterLambdaPtr[2] = 0x1063200a;
    stateEmitPtr = afterLambdaPtr + 3;
    if (sampler[9] != 0) {
      *stateEmitPtr = 0x39e00200;
      afterLambdaPtr[4] = 0x7c4378ce;
      afterLambdaPtr[5] = 0x1063100a;
      stateEmitPtr = afterLambdaPtr + 6;
    }
    *stateEmitPtr = 0x39e00030;
    stateEmitPtr[1] = 0x7c3178ce;
    stateEmitPtr[2] = 0x39e00020;
    stateEmitPtr[3] = 0x7c5178ce;
    stateEmitPtr[4] = 0x1063144a;
    stateEmitPtr[5] = 0x10630c0a;
    stateEmitPtr[6] = 0x10601a8c;
    stateEmitPtr[7] = 0x10801b8a;
    stateEmitPtr[8] = 0x39e00200;
    stateEmitPtr[9] = 0x7c8379ce;
    stateEmitPtr[10] = 0x7f03782e;
    if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 2) {
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(sampler,textureUnit,stateEmitPtr + 0xb);
    }
    else {
      stateEmitPtr[0xb] = 0x10801aca;
      stateEmitPtr[0xc] = 0x1083204a;
      stateEmitPtr[0xd] = 0x39e00210;
      stateEmitPtr[0xe] = 0x7c8379ce;
      stateEmitPtr[0xf] = 0x39e00230;
      stateEmitPtr[0x10] = 0x7c0379ce;
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(sampler,textureUnit,stateEmitPtr + 0x11);
      *emitCursor = 0x39e00220;
      emitCursor[1] = 0x7c4379ce;
      emitCursor[2] = 0x3b180001;
      emitCursor[3] = 0x39e00230;
      emitCursor[4] = 0x7c0378ce;
      emitCursor[5] = unitLoadWord;
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(sampler,textureUnit,emitCursor + 6);
      *emitCursor = 0x39e00220;
      emitCursor[1] = 0x7c2378ce;
      emitCursor[2] = 0x39e00210;
      emitCursor[3] = 0x7c0378ce;
      emitCursor[4] = 0x1000028c;
      emitCursor[5] = 0x1068004a;
      emitCursor[6] = 0x1063386e;
      emitCursor[7] = 0x104018ae;
      emitCursor = emitCursor + 8;
    }
    return emitCursor;
  }
  sampler[10] = 0;
  resultCursor = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(sampler,textureUnit,codeCursor);
  return resultCursor;
}

/* _PPCTextureSamplerSampleTexel2DRTCAV @ 0x97be263c (780 bytes) */
int _PPCTextureSamplerSampleTexel2DRTCAV(sampler, textureUnit, codeCursor)
  int *sampler;
  int textureUnit;
  uint *codeCursor;
{
  undefined4 *resultCursor;
  undefined4 *emitCursor;
  uint *afterLambdaPtr;
  int lambdaWordCount;
  uint unitLoadWord;
  int *textureObject;
  uint *stateEmitPtr;
  
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 4) {
    sampler[10] = 1;
    if (sampler[9] != 0) {
      *codeCursor = 0x39e00200;
      codeCursor[1] = 0x7c4379ce;
      codeCursor = codeCursor + 2;
    }
    unitLoadWord = textureUnit * 4 & 0xfffcU | 0x82220000;
    *codeCursor = unitLoadWord;
    codeCursor[1] = 0x39e00120;
    codeCursor[2] = 0x7df178ce;
    codeCursor[3] = 0x39e00040;
    codeCursor[4] = 0x7c2c78ce;
    codeCursor[5] = 0x39ef00c0;
    codeCursor[6] = 0x7c4c78ce;
    lambdaWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexCalculateLambda2DAVRTC,codeCursor + 7);
    afterLambdaPtr = codeCursor + 7 + lambdaWordCount;
    *afterLambdaPtr = 0x39e00040;
    afterLambdaPtr[1] = 0x7c9178ce;
    afterLambdaPtr[2] = 0x1063200a;
    stateEmitPtr = afterLambdaPtr + 3;
    if (sampler[9] != 0) {
      *stateEmitPtr = 0x39e00200;
      afterLambdaPtr[4] = 0x7c4378ce;
      afterLambdaPtr[5] = 0x1063100a;
      stateEmitPtr = afterLambdaPtr + 6;
    }
    *stateEmitPtr = 0x39e00030;
    stateEmitPtr[1] = 0x7c3178ce;
    stateEmitPtr[2] = 0x39e00020;
    stateEmitPtr[3] = 0x7c5178ce;
    stateEmitPtr[4] = 0x1063144a;
    stateEmitPtr[5] = 0x10630c0a;
    stateEmitPtr[6] = 0x10601a8c;
    stateEmitPtr[7] = 0x10801b8a;
    stateEmitPtr[8] = 0x39e00200;
    stateEmitPtr[9] = 0x7c8379ce;
    stateEmitPtr[10] = 0x7f03782e;
    if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 2) {
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(sampler,textureUnit,stateEmitPtr + 0xb);
    }
    else {
      stateEmitPtr[0xb] = 0x10801aca;
      stateEmitPtr[0xc] = 0x1083204a;
      stateEmitPtr[0xd] = 0x39e00210;
      stateEmitPtr[0xe] = 0x7c8379ce;
      stateEmitPtr[0xf] = 0x39e00230;
      stateEmitPtr[0x10] = 0x7c0379ce;
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(sampler,textureUnit,stateEmitPtr + 0x11);
      *emitCursor = 0x39e00220;
      emitCursor[1] = 0x7c4379ce;
      emitCursor[2] = 0x3b180001;
      emitCursor[3] = 0x39e00230;
      emitCursor[4] = 0x7c0378ce;
      emitCursor[5] = unitLoadWord;
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(sampler,textureUnit,emitCursor + 6);
      *emitCursor = 0x39e00220;
      emitCursor[1] = 0x7c2378ce;
      emitCursor[2] = 0x39e00210;
      emitCursor[3] = 0x7c0378ce;
      emitCursor[4] = 0x1000028c;
      emitCursor[5] = 0x1068004a;
      emitCursor[6] = 0x1063386e;
      emitCursor[7] = 0x104018ae;
      emitCursor = emitCursor + 8;
    }
    return emitCursor;
  }
  sampler[10] = 0;
  resultCursor = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(sampler,textureUnit,codeCursor);
  return resultCursor;
}

/* _PPCTextureSamplerSampleTexel3DRTCAV @ 0x97be2948 (780 bytes) */
int _PPCTextureSamplerSampleTexel3DRTCAV(sampler, textureUnit, codeCursor)
  int *sampler;
  int textureUnit;
  uint *codeCursor;
{
  undefined4 *resultCursor;
  undefined4 *emitCursor;
  uint *afterLambdaPtr;
  int lambdaWordCount;
  uint unitLoadWord;
  int *textureObject;
  uint *stateEmitPtr;
  
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 4) {
    sampler[10] = 1;
    if (sampler[9] != 0) {
      *codeCursor = 0x39e00200;
      codeCursor[1] = 0x7c4379ce;
      codeCursor = codeCursor + 2;
    }
    unitLoadWord = textureUnit * 4 & 0xfffcU | 0x82220000;
    *codeCursor = unitLoadWord;
    codeCursor[1] = 0x39e00120;
    codeCursor[2] = 0x7df178ce;
    codeCursor[3] = 0x39e00040;
    codeCursor[4] = 0x7c2c78ce;
    codeCursor[5] = 0x39ef00c0;
    codeCursor[6] = 0x7c4c78ce;
    lambdaWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexCalculateLambda3DAVRTC,codeCursor + 7);
    afterLambdaPtr = codeCursor + 7 + lambdaWordCount;
    *afterLambdaPtr = 0x39e00040;
    afterLambdaPtr[1] = 0x7c9178ce;
    afterLambdaPtr[2] = 0x1063200a;
    stateEmitPtr = afterLambdaPtr + 3;
    if (sampler[9] != 0) {
      *stateEmitPtr = 0x39e00200;
      afterLambdaPtr[4] = 0x7c4378ce;
      afterLambdaPtr[5] = 0x1063100a;
      stateEmitPtr = afterLambdaPtr + 6;
    }
    *stateEmitPtr = 0x39e00030;
    stateEmitPtr[1] = 0x7c3178ce;
    stateEmitPtr[2] = 0x39e00020;
    stateEmitPtr[3] = 0x7c5178ce;
    stateEmitPtr[4] = 0x1063144a;
    stateEmitPtr[5] = 0x10630c0a;
    stateEmitPtr[6] = 0x10601a8c;
    stateEmitPtr[7] = 0x10801b8a;
    stateEmitPtr[8] = 0x39e00200;
    stateEmitPtr[9] = 0x7c8379ce;
    stateEmitPtr[10] = 0x7f03782e;
    if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 2) {
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(sampler,textureUnit,stateEmitPtr + 0xb);
    }
    else {
      stateEmitPtr[0xb] = 0x10801aca;
      stateEmitPtr[0xc] = 0x1083204a;
      stateEmitPtr[0xd] = 0x39e00210;
      stateEmitPtr[0xe] = 0x7c8379ce;
      stateEmitPtr[0xf] = 0x39e00230;
      stateEmitPtr[0x10] = 0x7c0379ce;
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(sampler,textureUnit,stateEmitPtr + 0x11);
      *emitCursor = 0x39e00220;
      emitCursor[1] = 0x7c4379ce;
      emitCursor[2] = 0x3b180001;
      emitCursor[3] = 0x39e00230;
      emitCursor[4] = 0x7c0378ce;
      emitCursor[5] = unitLoadWord;
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(sampler,textureUnit,emitCursor + 6);
      *emitCursor = 0x39e00220;
      emitCursor[1] = 0x7c2378ce;
      emitCursor[2] = 0x39e00210;
      emitCursor[3] = 0x7c0378ce;
      emitCursor[4] = 0x1000028c;
      emitCursor[5] = 0x1068004a;
      emitCursor[6] = 0x1063386e;
      emitCursor[7] = 0x104018ae;
      emitCursor = emitCursor + 8;
    }
    return emitCursor;
  }
  sampler[10] = 0;
  resultCursor = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(sampler,textureUnit,codeCursor);
  return resultCursor;
}

/* _PPCTextureSamplerSampleTexel1DFromLevelRTCAV @ 0x97be2c58 (960 bytes) */
int _PPCTextureSamplerSampleTexel1DFromLevelRTCAV(sampler, textureUnit, codeCursor)
  int *sampler;
  uint textureUnit;
  uint *codeCursor;
{
  int sampleWordCount;
  int wrapEndAddr;
  int chunkWordCount;
  bool isLinearFilter;
  short wrapModeS;
  ushort minFilter;
  int lambdaComputed;
  int textureState;
  uint emittedWord;
  int borderMode;
  int *textureObject;
  uint *stateEmitPtr;
  undefined4 *emitPtr;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if (textureObject == (int *)0x0) {
    return codeCursor;
  }
  sampler[1] = (int)textureObject;
  textureState = *textureObject;
  borderMode = 0x812d;
  wrapModeS = *(short *)(textureState + 0x10);
  if ((wrapModeS != -0x7ed3) &&
     (((wrapModeS != 0x2900 || (*(short *)(textureState + 0x16) == 0x2600)) ||
      (borderMode = 0x2900, *(short *)(textureState + 0x16) == 0x2700)))) {
    borderMode = 0;
  }
  if (((sampler[5] == textureUnit) && (sampler[6] == 4)) && (sampler[7] == borderMode)) {
    lambdaComputed = sampler[10];
    if (lambdaComputed != 0) goto LAB_97be2d14;
  }
  else {
    lambdaComputed = sampler[10];
LAB_97be2d14:
    if (lambdaComputed == 0) {
      emittedWord = 0x3a310120;
      *codeCursor = textureUnit * 4 & 0xfffc | 0x82220000;
    }
    else {
      *codeCursor = 0x1ef800d0;
      emittedWord = 0x7e31ba14;
      codeCursor = codeCursor + 1;
      *codeCursor = 0x3a310120;
    }
    codeCursor[1] = emittedWord;
    stateEmitPtr = codeCursor + 2;
    if (wrapModeS == 0x2901) {
      *stateEmitPtr = 0x39e00040;
      codeCursor[3] = 0x7e3178ce;
      stateEmitPtr = codeCursor + 4;
    }
    if (borderMode == 0x812d) {
      *stateEmitPtr = 0x82510070;
      stateEmitPtr[1] = 0x39e00050;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e00080;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823100a4;
    }
    else if (borderMode == 0x2900) {
      *stateEmitPtr = 0x82510070;
      stateEmitPtr[1] = 0x39e00050;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e00080;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823100a8;
    }
    else {
      *stateEmitPtr = 0x82510020;
      stateEmitPtr[1] = 0x39e00000;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e00030;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823100a0;
    }
    stateEmitPtr[5] = emittedWord;
    sampler[5] = textureUnit;
    codeCursor = stateEmitPtr + 6;
    sampler[6] = 4;
    sampler[7] = borderMode;
    textureState = *textureObject;
  }
  minFilter = *(ushort *)(textureState + 0x16);
  if (minFilter == 0x2700) {
LAB_97be2ebc:
    if (sampler[8] != 0) {
      chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedAVRTC,codeCursor);
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(sampler,codeCursor + chunkWordCount);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample1DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x10431c84;
  }
  else {
    if (minFilter < 0x2701) {
      if (minFilter == 0x2600) goto LAB_97be2ebc;
      isLinearFilter = minFilter == 0x2601;
LAB_97be2eb4:
      if (!isLinearFilter) {
        return codeCursor;
      }
    }
    else {
      if (minFilter == 0x2702) goto LAB_97be2ebc;
      if (0x2701 < minFilter) {
        isLinearFilter = minFilter == 0x2703;
        goto LAB_97be2eb4;
      }
    }
    if (sampler[8] != 0) {
      chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,codeCursor);
    codeCursor[chunkWordCount] = 0x10c00484;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(sampler,codeCursor + chunkWordCount + 1);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample1DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1020228c;
    emitPtr[1] = 0x104138ee;
    emitPtr[2] = 0x100a4b2c;
    emitPtr[3] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(sampler,emitPtr + 4);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample1DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x10202a8c;
    emitPtr = emitPtr + 1;
    *emitPtr = 0x104110ee;
  }
  return emitPtr + 1;
}

/* _PPCTextureSamplerSampleTexel2DFromLevelRTCAV @ 0x97be3018 (1172 bytes) */
int _PPCTextureSamplerSampleTexel2DFromLevelRTCAV(sampler, textureUnit, codeCursor)
  int *sampler;
  uint textureUnit;
  uint *codeCursor;
{
  int sampleWordCount;
  int wrapEndAddr;
  int chunkWordCount;
  bool isLinearFilter;
  short wrapModeS;
  short wrapModeT;
  ushort minFilter;
  int lambdaComputed;
  int textureState;
  uint emittedWord;
  int borderMode;
  int *textureObject;
  uint *stateEmitPtr;
  undefined4 *emitPtr;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if (textureObject == (int *)0x0) {
    return codeCursor;
  }
  sampler[1] = (int)textureObject;
  textureState = *textureObject;
  wrapModeS = *(short *)(textureState + 0x10);
  wrapModeT = *(short *)(textureState + 0x12);
  if ((wrapModeS == -0x7ed3) || (wrapModeT == -0x7ed3)) {
    borderMode = 0x812d;
  }
  else if ((((wrapModeS != 0x2900) && (wrapModeT != 0x2900)) || (*(short *)(textureState + 0x16) == 0x2600)) ||
          (borderMode = 0x2900, *(short *)(textureState + 0x16) == 0x2700)) {
    borderMode = 0;
  }
  if (((sampler[5] == textureUnit) && (sampler[6] == 3)) && (sampler[7] == borderMode)) {
    lambdaComputed = sampler[10];
    if (lambdaComputed != 0) goto LAB_97be30f0;
  }
  else {
    lambdaComputed = sampler[10];
LAB_97be30f0:
    if (lambdaComputed == 0) {
      emittedWord = 0x3a310120;
      *codeCursor = textureUnit * 4 & 0xfffc | 0x82220000;
    }
    else {
      *codeCursor = 0x1ef800d0;
      emittedWord = 0x7e31ba14;
      codeCursor = codeCursor + 1;
      *codeCursor = 0x3a310120;
    }
    codeCursor[1] = emittedWord;
    stateEmitPtr = codeCursor + 2;
    if ((wrapModeS == 0x2901) || (wrapModeT == 0x2901)) {
      *stateEmitPtr = 0x39e00040;
      codeCursor[3] = 0x7e3178ce;
      stateEmitPtr = codeCursor + 4;
    }
    if (borderMode == 0x812d) {
      *stateEmitPtr = 0x82510070;
      stateEmitPtr[1] = 0x39e00050;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e00080;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823100a4;
    }
    else if (borderMode == 0x2900) {
      *stateEmitPtr = 0x82510070;
      stateEmitPtr[1] = 0x39e00050;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e00080;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823100a8;
    }
    else {
      *stateEmitPtr = 0x82510020;
      stateEmitPtr[1] = 0x39e00000;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e00030;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823100a0;
    }
    stateEmitPtr[5] = emittedWord;
    sampler[5] = textureUnit;
    codeCursor = stateEmitPtr + 6;
    sampler[6] = 3;
    sampler[7] = borderMode;
    textureState = *textureObject;
  }
  minFilter = *(ushort *)(textureState + 0x16);
  if (minFilter == 0x2700) {
LAB_97be32a0:
    if (sampler[8] != 0) {
      chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedAVRTC,codeCursor);
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(sampler,codeCursor + chunkWordCount);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x10431c84;
  }
  else {
    if (minFilter < 0x2701) {
      if (minFilter == 0x2600) goto LAB_97be32a0;
      isLinearFilter = minFilter == 0x2601;
LAB_97be3298:
      if (!isLinearFilter) {
        return codeCursor;
      }
    }
    else {
      if (minFilter == 0x2702) goto LAB_97be32a0;
      if (0x2701 < minFilter) {
        isLinearFilter = minFilter == 0x2703;
        goto LAB_97be3298;
      }
    }
    if (sampler[8] != 0) {
      chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,codeCursor);
    codeCursor[chunkWordCount] = 0x10c00484;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(sampler,codeCursor + chunkWordCount + 1);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10200a8c;
    emitPtr[3] = 0x104138ee;
    emitPtr[4] = 0x100a4a2c;
    emitPtr[5] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(sampler,emitPtr + 6);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10200a8c;
    emitPtr[3] = 0x104110ee;
    emitPtr[4] = 0x100a4b2c;
    emitPtr[5] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(sampler,emitPtr + 6);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10200a8c;
    emitPtr[3] = 0x104110ee;
    emitPtr[4] = 0x1003528c;
    emitPtr[5] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(sampler,emitPtr + 6);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10200a8c;
    emitPtr = emitPtr + 3;
    *emitPtr = 0x104110ee;
  }
  return emitPtr + 1;
}

/* _PPCTextureSamplerSampleTexel3DFromLevelRTCAV @ 0x97be34ac (1612 bytes) */
int _PPCTextureSamplerSampleTexel3DFromLevelRTCAV(sampler, textureUnit, codeCursor)
  int *sampler;
  uint textureUnit;
  uint *codeCursor;
{
  int sampleWordCount;
  int wrapEndAddr;
  int chunkWordCount;
  bool isLinearFilter;
  short wrapModeS;
  short wrapModeT;
  ushort minFilter;
  int lambdaComputed;
  int textureState;
  uint emittedWord;
  int *textureObject;
  int borderMode;
  uint *stateEmitPtr;
  undefined4 *emitPtr;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if (textureObject == (int *)0x0) {
    return codeCursor;
  }
  sampler[1] = (int)textureObject;
  textureState = *textureObject;
  wrapModeS = *(short *)(textureState + 0x10);
  wrapModeT = *(short *)(textureState + 0x12);
  if (((wrapModeS == -0x7ed3) || (wrapModeT == -0x7ed3)) || (*(short *)(textureState + 0x14) == -0x7ed3)) {
    borderMode = 0x812d;
  }
  else if ((((wrapModeS != 0x2900) && (wrapModeT != 0x2900)) && (*(short *)(textureState + 0x14) != 0x2900)) ||
          ((*(short *)(textureState + 0x16) == 0x2600 ||
           (borderMode = 0x2900, *(short *)(textureState + 0x16) == 0x2700)))) {
    borderMode = 0;
  }
  if (((sampler[5] == textureUnit) && (sampler[6] == 1)) && (sampler[7] == borderMode)) {
    lambdaComputed = sampler[10];
    if (lambdaComputed != 0) goto LAB_97be359c;
  }
  else {
    lambdaComputed = sampler[10];
LAB_97be359c:
    if (lambdaComputed == 0) {
      emittedWord = 0x3a310120;
      *codeCursor = textureUnit * 4 & 0xfffc | 0x82220000;
    }
    else {
      *codeCursor = 0x1ef800d0;
      emittedWord = 0x7e31ba14;
      codeCursor = codeCursor + 1;
      *codeCursor = 0x3a310120;
    }
    codeCursor[1] = emittedWord;
    stateEmitPtr = codeCursor + 2;
    if ((wrapModeS == 0x2901) || (wrapModeT == 0x2901)) {
      *stateEmitPtr = 0x39e00040;
      codeCursor[3] = 0x7e3178ce;
      stateEmitPtr = codeCursor + 4;
    }
    if (borderMode == 0x812d) {
      *stateEmitPtr = 0x82510070;
      stateEmitPtr[1] = 0x82710074;
      stateEmitPtr[2] = 0x39e00050;
      stateEmitPtr[3] = 0x7df178ce;
      stateEmitPtr[4] = 0x39e00080;
      stateEmitPtr[5] = 0x7e1178ce;
      emittedWord = 0x823100a4;
    }
    else if (borderMode == 0x2900) {
      *stateEmitPtr = 0x82510070;
      stateEmitPtr[1] = 0x82710074;
      stateEmitPtr[2] = 0x39e00050;
      stateEmitPtr[3] = 0x7df178ce;
      stateEmitPtr[4] = 0x39e00080;
      stateEmitPtr[5] = 0x7e1178ce;
      emittedWord = 0x823100a8;
    }
    else {
      *stateEmitPtr = 0x82510020;
      stateEmitPtr[1] = 0x82710024;
      stateEmitPtr[2] = 0x39e00000;
      stateEmitPtr[3] = 0x7df178ce;
      stateEmitPtr[4] = 0x39e00030;
      stateEmitPtr[5] = 0x7e1178ce;
      emittedWord = 0x823100a0;
    }
    stateEmitPtr[6] = emittedWord;
    sampler[5] = textureUnit;
    codeCursor = stateEmitPtr + 7;
    sampler[6] = 1;
    sampler[7] = borderMode;
    textureState = *textureObject;
  }
  minFilter = *(ushort *)(textureState + 0x16);
  if (minFilter == 0x2700) {
LAB_97be376c:
    if (sampler[8] != 0) {
      chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedAVRTC,codeCursor);
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,codeCursor + chunkWordCount);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x10431c84;
  }
  else {
    if (minFilter < 0x2701) {
      if (minFilter == 0x2600) goto LAB_97be376c;
      isLinearFilter = minFilter == 0x2601;
LAB_97be3764:
      if (!isLinearFilter) {
        return codeCursor;
      }
    }
    else {
      if (minFilter == 0x2702) goto LAB_97be376c;
      if (0x2701 < minFilter) {
        isLinearFilter = minFilter == 0x2703;
        goto LAB_97be3764;
      }
    }
    if (sampler[8] != 0) {
      chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,codeCursor);
    codeCursor[chunkWordCount] = 0x10c00484;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,codeCursor + chunkWordCount + 1);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10044a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr[5] = 0x104138ee;
    emitPtr[6] = 0x100a4a2c;
    emitPtr[7] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,emitPtr + 8);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10044a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr[5] = 0x104110ee;
    emitPtr[6] = 0x100a4b2c;
    emitPtr[7] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,emitPtr + 8);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10044a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr[5] = 0x104110ee;
    emitPtr[6] = 0x1003528c;
    emitPtr[7] = 0x10004a2c;
    emitPtr[8] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,emitPtr + 9);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10044a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr[5] = 0x104110ee;
    emitPtr[6] = 0x100a492c;
    emitPtr[7] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,emitPtr + 8);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10054a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr[5] = 0x104110ee;
    emitPtr[6] = 0x1003528c;
    emitPtr[7] = 0x1009032c;
    emitPtr[8] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,emitPtr + 9);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10054a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr[5] = 0x104110ee;
    emitPtr[6] = 0x1003528c;
    emitPtr[7] = 0x1000492c;
    emitPtr[8] = 0x1000022c;
    emitPtr[9] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,emitPtr + 10);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10054a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr[5] = 0x104110ee;
    emitPtr[6] = 0x1003528c;
    emitPtr[7] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,emitPtr + 8);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10054a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr = emitPtr + 5;
    *emitPtr = 0x104110ee;
  }
  return emitPtr + 1;
}

/* _PPCTextureSamplerSampleTexelRECTFromLevelRTCAV @ 0x97be3af8 (1084 bytes) */
int _PPCTextureSamplerSampleTexelRECTFromLevelRTCAV(sampler, textureUnit, codeCursor)
  int *sampler;
  uint textureUnit;
  uint *codeCursor;
{
  int sampleWordCount;
  int chunkWordsThenEnd;
  int floatToIntWordCount;
  uint *emitPtr;
  uint *stateEmitPtr;
  int textureState;
  bool isLinearFilter;
  short wrapModeS;
  short wrapModeT;
  ushort minFilter;
  uint emittedWord;
  int borderMode;
  int *textureObject;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if (textureObject == (int *)0x0) {
    return codeCursor;
  }
  sampler[1] = (int)textureObject;
  textureState = *textureObject;
  wrapModeS = *(short *)(textureState + 0x10);
  wrapModeT = *(short *)(textureState + 0x12);
  if ((wrapModeS == -0x7ed3) || (wrapModeT == -0x7ed3)) {
    borderMode = 0x812d;
  }
  else if ((((wrapModeS != 0x2900) && (wrapModeT != 0x2900)) || (*(short *)(textureState + 0x16) == 0x2600)) ||
          (borderMode = 0x2900, *(short *)(textureState + 0x16) == 0x2700)) {
    borderMode = 0;
  }
  if (((sampler[5] != textureUnit) || (sampler[6] != 2)) || (sampler[7] != borderMode)) {
    *codeCursor = textureUnit * 4 & 0xfffc | 0x82220000;
    stateEmitPtr = codeCursor + 1;
    if ((wrapModeS == 0x2901) || (wrapModeT == 0x2901)) {
      *stateEmitPtr = 0x39e00160;
      codeCursor[2] = 0x7e3178ce;
      stateEmitPtr = codeCursor + 3;
    }
    if (borderMode == 0x812d) {
      *stateEmitPtr = 0x82510190;
      stateEmitPtr[1] = 0x39e00170;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e001a0;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823101c4;
    }
    else if (borderMode == 0x2900) {
      *stateEmitPtr = 0x82510190;
      stateEmitPtr[1] = 0x39e00170;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e001a0;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823101c8;
    }
    else {
      *stateEmitPtr = 0x82510140;
      stateEmitPtr[1] = 0x39e00120;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e00150;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823101c0;
    }
    stateEmitPtr[5] = emittedWord;
    sampler[7] = borderMode;
    codeCursor = stateEmitPtr + 6;
    sampler[5] = textureUnit;
    sampler[6] = 2;
    textureState = *textureObject;
  }
  minFilter = *(ushort *)(textureState + 0x16);
  if (minFilter == 0x2700) {
LAB_97be3d34:
    floatToIntWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntDenormalisedAVRTC,codeCursor);
    emitPtr = codeCursor + floatToIntWordCount;
    chunkWordsThenEnd = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,emitPtr);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,emitPtr + chunkWordsThenEnd);
    emitPtr = emitPtr + chunkWordsThenEnd + sampleWordCount;
    *emitPtr = 0x10431c84;
  }
  else {
    if (minFilter < 0x2701) {
      if (minFilter == 0x2600) goto LAB_97be3d34;
      isLinearFilter = minFilter == 0x2601;
LAB_97be3d2c:
      if (!isLinearFilter) {
        return codeCursor;
      }
    }
    else {
      if (minFilter == 0x2702) goto LAB_97be3d34;
      if (0x2701 < minFilter) {
        isLinearFilter = minFilter == 0x2703;
        goto LAB_97be3d2c;
      }
    }
    floatToIntWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntDenormalisedWithLERPValuesAVRTC,codeCursor);
    emitPtr = codeCursor + floatToIntWordCount;
    *emitPtr = 0x10c00484;
    emitPtr = emitPtr + 1;
    chunkWordsThenEnd = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,emitPtr);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,emitPtr + chunkWordsThenEnd);
    emitPtr = emitPtr + chunkWordsThenEnd + sampleWordCount;
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10200a8c;
    emitPtr[3] = 0x104138ee;
    emitPtr[4] = 0x100a4a2c;
    emitPtr[5] = 0x10060780;
    emitPtr = emitPtr + 6;
    chunkWordsThenEnd = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,emitPtr);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,emitPtr + chunkWordsThenEnd);
    emitPtr = emitPtr + chunkWordsThenEnd + sampleWordCount;
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10200a8c;
    emitPtr[3] = 0x104110ee;
    emitPtr[4] = 0x100a4b2c;
    emitPtr[5] = 0x10060780;
    emitPtr = emitPtr + 6;
    chunkWordsThenEnd = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,emitPtr);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,emitPtr + chunkWordsThenEnd);
    emitPtr = emitPtr + chunkWordsThenEnd + sampleWordCount;
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10200a8c;
    emitPtr[3] = 0x104110ee;
    emitPtr[4] = 0x1003528c;
    emitPtr[5] = 0x10060780;
    emitPtr = emitPtr + 6;
    chunkWordsThenEnd = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,emitPtr);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,emitPtr + chunkWordsThenEnd);
    emitPtr = emitPtr + chunkWordsThenEnd + sampleWordCount;
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10200a8c;
    emitPtr = emitPtr + 3;
    *emitPtr = 0x104110ee;
  }
  return emitPtr + 1;
}

/* _PPCNoiseGeneratorCreate @ 0x97be3f34 (56 bytes) */
int _PPCNoiseGeneratorCreate()
{
  undefined4 allocation;
  
  allocation = _malloc(0xa20);
  ((int (*)())_PPCNoiseGeneratorInitialise)(allocation);
  return allocation;
}

/* _PPCNoiseGeneratorInitialise @ 0x97be3f6c (280 bytes) */
int _PPCNoiseGeneratorInitialise(noiseTable)
  undefined1 *noiseTable;
{
  int duplicateCountdown;
  undefined1 *duplicateCursor;
  uint loopIndex;
  undefined1 swapByte;
  undefined4 gradientWord;
  uint randomResult;
  int swapIndex;
  float *gradientCursor;
  uint randomResult2;
  undefined1 *shuffleCursor;
  
  _memset(noiseTable,0,0xa20);
  loopIndex = 0;
  gradientCursor = (float *)(noiseTable + 0x210);
  do {
    noiseTable[loopIndex] = (char)loopIndex;
    randomResult = _random();
    loopIndex = loopIndex + 1;
    *gradientCursor = (float)(((double)CONCAT44(0x43300000,
                                        (randomResult + (((int)randomResult >> 9) +
                                                 (uint)((int)randomResult < 0 && (randomResult & 0x1ff) != 0)) *
                                                 -0x200) - 0x100 ^ 0x80000000) - 4503601774854144.0)
                     * 0.00390625);
    gradientCursor = gradientCursor + 1;
  } while (loopIndex < 0x100);
  shuffleCursor = noiseTable + 0xff;
  do {
    swapByte = *shuffleCursor;
    randomResult2 = _random();
    swapIndex = randomResult2 + (((int)randomResult2 >> 8) + (uint)((int)randomResult2 < 0 && (randomResult2 & 0xff) != 0)) * -0x100;
    *shuffleCursor = noiseTable[swapIndex];
    shuffleCursor = shuffleCursor + -1;
    noiseTable[swapIndex] = swapByte;
  } while (shuffleCursor != noiseTable);
  duplicateCountdown = 0x102;
  duplicateCursor = noiseTable;
  do {
    gradientWord = *(undefined4 *)(duplicateCursor + 0x210);
    noiseTable[0x100] = *noiseTable;
    noiseTable = noiseTable + 1;
    *(undefined4 *)(duplicateCursor + 0x610) = gradientWord;
    duplicateCursor = duplicateCursor + 4;
    duplicateCountdown = duplicateCountdown + -1;
  } while (duplicateCountdown != 0);
  return duplicateCursor;
}

/* _glpRTCAddAChunk_97be4088 @ 0x97be4088 (48 bytes) */
int _glpRTCAddAChunk_97be4088(chunk, dest)
  int *chunk;
  int *dest;
{
  int word;
  int wordCount;
  
  wordCount = 0;
  word = *chunk;
  while (word != 0) {
    *dest = word;
    wordCount = wordCount + 1;
    chunk = chunk + 1;
    dest = dest + 1;
    word = *chunk;
  }
  return wordCount;
}

/* _PPCNoiseGeneratorCalculate1DAVRTC @ 0x97be40b8 (228 bytes) */
int _PPCNoiseGeneratorCalculate1DAVRTC(noiseTable, codeCursor)
  undefined4 noiseTable;
  undefined4 *codeCursor;
{
  undefined4 *vectorInstWord;
  int glpRTCAddAChunkResult;
  int glpRTCAddAChunkResult2;
  uint loopIndex;
  undefined4 *vectorInstWord2;
  
  *codeCursor = 0x11a8400a;
  codeCursor[1] = 0x102b5c84;
  vectorInstWord2 = codeCursor + 2;
  loopIndex = 0;
  do {
    loopIndex = loopIndex + 1;
    glpRTCAddAChunkResult = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpFirstStageAVRTC,vectorInstWord2);
    glpRTCAddAChunkResult2 = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpSecondStage1DAVRTC,vectorInstWord2 + glpRTCAddAChunkResult);
    vectorInstWord = vectorInstWord2 + glpRTCAddAChunkResult + glpRTCAddAChunkResult2;
    *vectorInstWord = 0x1122486e;
    vectorInstWord[1] = 0x10003b6e;
    vectorInstWord[2] = 0x10213aee;
    vectorInstWord2 = vectorInstWord + 3;
  } while (loopIndex < 6);
  *vectorInstWord2 = 0x10494c84;
  vectorInstWord[4] = 0x1120038c;
  vectorInstWord[5] = 0x39c00030;
  vectorInstWord[6] = 0x7dae18ce;
  return vectorInstWord + 7;
}

/* _PPCNoiseGeneratorCalculate2DAVRTC @ 0x97be419c (228 bytes) */
int _PPCNoiseGeneratorCalculate2DAVRTC(noiseTable, codeCursor)
  undefined4 noiseTable;
  undefined4 *codeCursor;
{
  undefined4 *vectorInstWord;
  int glpRTCAddAChunkResult;
  int glpRTCAddAChunkResult2;
  uint loopIndex;
  undefined4 *vectorInstWord2;
  
  *codeCursor = 0x11a8400a;
  codeCursor[1] = 0x102b5c84;
  vectorInstWord2 = codeCursor + 2;
  loopIndex = 0;
  do {
    loopIndex = loopIndex + 1;
    glpRTCAddAChunkResult = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpFirstStageAVRTC,vectorInstWord2);
    glpRTCAddAChunkResult2 = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpSecondStage2DAVRTC,vectorInstWord2 + glpRTCAddAChunkResult);
    vectorInstWord = vectorInstWord2 + glpRTCAddAChunkResult + glpRTCAddAChunkResult2;
    *vectorInstWord = 0x1122486e;
    vectorInstWord[1] = 0x10003b6e;
    vectorInstWord[2] = 0x10213aee;
    vectorInstWord2 = vectorInstWord + 3;
  } while (loopIndex < 6);
  *vectorInstWord2 = 0x10494c84;
  vectorInstWord[4] = 0x1120038c;
  vectorInstWord[5] = 0x39c00030;
  vectorInstWord[6] = 0x7dae18ce;
  return vectorInstWord + 7;
}

/* _PPCNoiseGeneratorCalculate3DAVRTC @ 0x97be4280 (228 bytes) */
int _PPCNoiseGeneratorCalculate3DAVRTC(noiseTable, codeCursor)
  undefined4 noiseTable;
  undefined4 *codeCursor;
{
  undefined4 *vectorInstWord;
  int glpRTCAddAChunkResult;
  int glpRTCAddAChunkResult2;
  uint loopIndex;
  undefined4 *vectorInstWord2;
  
  *codeCursor = 0x11a8400a;
  codeCursor[1] = 0x102b5c84;
  vectorInstWord2 = codeCursor + 2;
  loopIndex = 0;
  do {
    loopIndex = loopIndex + 1;
    glpRTCAddAChunkResult = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpFirstStageAVRTC,vectorInstWord2);
    glpRTCAddAChunkResult2 = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpSecondStage3DAVRTC,vectorInstWord2 + glpRTCAddAChunkResult);
    vectorInstWord = vectorInstWord2 + glpRTCAddAChunkResult + glpRTCAddAChunkResult2;
    *vectorInstWord = 0x1122486e;
    vectorInstWord[1] = 0x10003b6e;
    vectorInstWord[2] = 0x10213aee;
    vectorInstWord2 = vectorInstWord + 3;
  } while (loopIndex < 6);
  *vectorInstWord2 = 0x10494c84;
  vectorInstWord[4] = 0x1120038c;
  vectorInstWord[5] = 0x39c00030;
  vectorInstWord[6] = 0x7dae18ce;
  return vectorInstWord + 7;
}

/* _PPCNoiseGeneratorCalculate4DAVRTC @ 0x97be4364 (8 bytes) */
int _PPCNoiseGeneratorCalculate4DAVRTC(noiseTable, codeCursor)
  undefined4 noiseTable;
  undefined4 codeCursor;
{
  return codeCursor;
}

/* _PPCRasterOpMachineCreate @ 0x97be436c (60 bytes) */
int _PPCRasterOpMachineCreate()
{
  undefined4 allocation;
  
  allocation = _calloc(8,1);
  ((int (*)())_PPCRasterOpMachineInitialise)(allocation);
  return allocation;
}

/* _PPCRasterOpMachineInitialise @ 0x97be43a8 (16 bytes) */
int _PPCRasterOpMachineInitialise(machine)
  undefined4 *machine;
{
  machine[1] = 0;
  *machine = 0;
  return;
}

/* _PPCRasterOpMachineAttachEmulatorContext @ 0x97be43bc (8 bytes) */
int _PPCRasterOpMachineAttachEmulatorContext(machine, emulatorContext)
  undefined4 *machine;
  undefined4 emulatorContext;
{
  *machine = emulatorContext;
  return;
}

/* _PPCRasterOpMachineAttachRuntimeCompiler @ 0x97be43c4 (8 bytes) */
int _PPCRasterOpMachineAttachRuntimeCompiler(machine, runtimeCompiler)
  int machine;
  undefined4 runtimeCompiler;
{
  *(undefined4 *)(machine + 4) = runtimeCompiler;
  return;
}

/* _PPCRasterOpMachine_DepthTestRTCAV @ 0x97be43cc (272 bytes) */
int _PPCRasterOpMachine_DepthTestRTCAV(machine, codeCursor)
  int *machine;
  uint *codeCursor;
{
  uint skipWords;
  uint branchWord;
  uint depthFunc;
  uint depthState;
  int compiler;
  
  compiler = machine[1];
  depthState = *(uint *)(*(int *)(*machine + 0xd80) + 0x50);
  depthFunc = depthState & 7;
  if ((depthFunc != 0) && (depthFunc != 7)) {
    *codeCursor = 0x81e30da8;
    codeCursor[1] = 0xc10f0000;
    codeCursor[2] = 0xfc0d4000;
    codeCursor = codeCursor + 3;
  }
  skipWords = (uint)(*(int *)(compiler + 0xe3c) - (int)codeCursor) >> 2;
  switch(depthState & 7) {
  case 0:
    *codeCursor = (skipWords & 0xffffff) << 2 | 0x48000000;
    goto LAB_97be44f0;
  case 1:
    branchWord = 0x41800000;
    break;
  case 2:
    branchWord = 0x41820000;
    break;
  case 3:
    branchWord = 0x40810000;
    break;
  case 4:
    branchWord = 0x41810000;
    break;
  case 5:
    branchWord = 0x40820000;
    break;
  case 6:
    branchWord = 0x40800000;
    break;
  default:
    goto switchD_97be4464_caseD_7;
  }
  *codeCursor = branchWord | 8;
  codeCursor = codeCursor + 1;
  *codeCursor = (skipWords - 1) * 4 & 0x3fffffc | 0x48000000;
LAB_97be44f0:
  codeCursor = codeCursor + 1;
switchD_97be4464_caseD_7:
  return codeCursor;
}

/* _PPCRasterOpMachine_DepthAndStencilTestRTCAV @ 0x97be44fc (1172 bytes) */
int _PPCRasterOpMachine_DepthAndStencilTestRTCAV(machine, codeCursor)
  int *machine;
  uint *codeCursor;
{
  uint *stencilUpdateCursor;
  uint *finalUpdateCursor;
  uint depthBranchWord;
  uint stencilBranchWord;
  uint *tailEmitPtr;
  bool bufferMaskDisabled;
  uint stencilRef;
  bool stencilEnabled;
  int rasterState;
  uint stencilState;
  uint *emitPtr;
  uint *stencilTestEnd;
  uint depthFunc;
  uint writeMasks;
  uint stageFlags;
  int emulator;
  uint stencilValueMask;
  int compiler;
  uint stencilWriteMask;
  uint *branchFixupPtr;
  
  emulator = *machine;
  branchFixupPtr = (uint *)0x0;
  compiler = machine[1];
  rasterState = *(int *)(emulator + 0xd80);
  stencilState = *(uint *)(rasterState + 0x48);
  stageFlags = *(uint *)(rasterState + 0x3c);
  stencilRef = *(uint *)(rasterState + 0x4c) >> 0x18;
  bufferMaskDisabled = (stageFlags >> 6 & 1) == 0;
  depthFunc = *(uint *)(*(int *)(emulator + 0xd80) + 0x50);
  writeMasks = *(uint *)(*(int *)(emulator + 0xd80) + 0x70);
  if (bufferMaskDisabled) {
    stencilWriteMask = 0xff;
  }
  else {
    stencilWriteMask = writeMasks >> 8 & 0xff;
  }
  stencilEnabled = (stageFlags & 2) != 0;
  stencilValueMask = *(uint *)(rasterState + 0x4c) >> 8 & 0xff;
  if (!stencilEnabled) goto LAB_97be4754;
  *codeCursor = 0x83430dac;
  codeCursor[1] = 0x8b3a0000;
  stencilTestEnd = codeCursor + 2;
  emitPtr = stencilTestEnd;
  switch(stencilState >> 0xc & 7) {
  case 0:
    stencilState = stencilState >> 0xf;
    codeCursor = stencilTestEnd;
    goto LAB_97be47b8;
  case 1:
    *stencilTestEnd = stencilRef & stencilValueMask | 0x3ba00000;
    codeCursor[3] = stencilValueMask | 0x733e0000;
    stencilBranchWord = 0x41800000;
    break;
  case 2:
    *stencilTestEnd = stencilRef & stencilValueMask | 0x3ba00000;
    codeCursor[3] = stencilValueMask | 0x733e0000;
    stencilBranchWord = 0x41820000;
    break;
  case 3:
    *stencilTestEnd = stencilRef & stencilValueMask | 0x3ba00000;
    codeCursor[3] = stencilValueMask | 0x733e0000;
    stencilBranchWord = 0x40810000;
    break;
  case 4:
    *stencilTestEnd = stencilRef & stencilValueMask | 0x3ba00000;
    codeCursor[3] = stencilValueMask | 0x733e0000;
    stencilBranchWord = 0x41810000;
    break;
  case 5:
    *stencilTestEnd = stencilRef & stencilValueMask | 0x3ba00000;
    codeCursor[3] = stencilValueMask | 0x733e0000;
    stencilBranchWord = 0x40820000;
    break;
  case 6:
    *stencilTestEnd = stencilRef & stencilValueMask | 0x3ba00000;
    codeCursor[3] = stencilValueMask | 0x733e0000;
    stencilBranchWord = 0x40800000;
    break;
  case 7:
    *stencilTestEnd = 0x48000000;
    emitPtr = codeCursor + 3;
    branchFixupPtr = stencilTestEnd;
  default:
    goto switchD_97be45d8_default;
  }
  codeCursor[4] = 0x7c1df000;
  branchFixupPtr = codeCursor + 5;
  *branchFixupPtr = stencilBranchWord;
  emitPtr = codeCursor + 6;
switchD_97be45d8_default:
  stencilUpdateCursor = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(stencilState >> 0xf & 7,0x1a,0x19,stencilRef,stencilWriteMask,emitPtr);
  codeCursor = stencilUpdateCursor + 1;
  *stencilUpdateCursor = *(int *)(compiler + 0xe3c) - (int)stencilUpdateCursor & 0x3fffffcU | 0x48000000;
  *branchFixupPtr = *branchFixupPtr | (int)codeCursor - (int)branchFixupPtr & 0xfffcU;
LAB_97be4754:
  if ((stageFlags & 4) == 0) {
    if (!stencilEnabled) {
      return codeCursor;
    }
    finalUpdateCursor = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(stencilState >> 0x15 & 7,0x1a,0x19,stencilRef,stencilWriteMask,codeCursor);
    return finalUpdateCursor;
  }
  switch(depthFunc & 7) {
  case 0:
    if (stencilEnabled) {
      stencilState = stencilState >> 0x12;
LAB_97be47b8:
      codeCursor = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(stencilState & 7,0x1a,0x19,stencilRef,stencilWriteMask,codeCursor);
    }
    *codeCursor = *(int *)(compiler + 0xe3c) - (int)codeCursor & 0x3fffffcU | 0x48000000;
    return codeCursor + 1;
  case 1:
    *codeCursor = 0x81e30da8;
    codeCursor[1] = 0xc10f0000;
    depthBranchWord = 0x41800000;
    break;
  case 2:
    *codeCursor = 0x81e30da8;
    codeCursor[1] = 0xc10f0000;
    depthBranchWord = 0x41820000;
    break;
  case 3:
    *codeCursor = 0x81e30da8;
    codeCursor[1] = 0xc10f0000;
    depthBranchWord = 0x40810000;
    break;
  case 4:
    *codeCursor = 0x81e30da8;
    codeCursor[1] = 0xc10f0000;
    depthBranchWord = 0x41810000;
    break;
  case 5:
    *codeCursor = 0x81e30da8;
    codeCursor[1] = 0xc10f0000;
    depthBranchWord = 0x40820000;
    break;
  case 6:
    *codeCursor = 0x81e30da8;
    codeCursor[1] = 0xc10f0000;
    depthBranchWord = 0x40800000;
    break;
  case 7:
    *codeCursor = 0x81e30da8;
    depthBranchWord = 0x48000000;
    goto LAB_97be48e0;
  default:
    goto switchD_97be4784_default;
  }
  codeCursor = codeCursor + 2;
  *codeCursor = 0xfc0d4000;
LAB_97be48e0:
  branchFixupPtr = codeCursor + 1;
  *branchFixupPtr = depthBranchWord;
  codeCursor = codeCursor + 2;
switchD_97be4784_default:
  if (stencilEnabled) {
    codeCursor = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(stencilState >> 0x12 & 7,0x1a,0x19,stencilRef,stencilWriteMask,codeCursor);
  }
  *codeCursor = *(int *)(compiler + 0xe3c) - (int)codeCursor & 0x3fffffcU | 0x48000000;
  tailEmitPtr = codeCursor + 1;
  *branchFixupPtr = *branchFixupPtr | (int)tailEmitPtr - (int)branchFixupPtr & 0xfffcU;
  if (stencilEnabled) {
    tailEmitPtr = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(stencilState >> 0x15 & 7,0x1a,0x19,stencilRef,stencilWriteMask,tailEmitPtr);
  }
  if ((bufferMaskDisabled) || ((writeMasks & 0x10000) != 0)) {
    *tailEmitPtr = 0xd1af0000;
    tailEmitPtr = tailEmitPtr + 1;
  }
  return tailEmitPtr;
}

/* _PPCRasterOpMachine_AlphaTestRTCAV @ 0x97be49d0 (616 bytes) */
int _PPCRasterOpMachine_AlphaTestRTCAV(machine, codeCursor)
  int *machine;
  uint *codeCursor;
{
  uint compareWord;
  uint framebufferFormat;
  float clampBound;
  uint alphaFunc;
  float alphaRef;
  int rasterState;
  uint alphaState;
  uint branchField;
  double alphaRefScaled;
  
  branchField = 0;
  rasterState = *(int *)(*machine + 0xd80);
  alphaState = *(uint *)(rasterState + 0x40);
  alphaRef = *(float *)(rasterState + 0x44);
  alphaFunc = alphaState & 7;
  if ((alphaFunc != 7) && (alphaFunc != 0)) {
    framebufferFormat = _PPEmulatorFramebufferFormat(*machine);
    if ((framebufferFormat & 0x1c000) == 0) {
      *codeCursor = 0x3b000210;
      codeCursor[1] = 0x7e63c1ce;
      codeCursor[2] = 0xc123021c;
      codeCursor[3] = (uint)(int)alphaRef >> 0x10 | 0x3de00000;
      codeCursor[4] = (uint)(int)alphaRef & 0xffff | 0x61ef0000;
      codeCursor[5] = 0x91e30210;
      codeCursor[6] = 0xc1030210;
      compareWord = 0xfc094000;
    }
    else {
      clampBound = TAllocation__guardBlockSize;
      if ((alphaRef < TAllocation__guardBlockSize) || (clampBound = FLOAT_97c3acd8, FLOAT_97c3acd8 < alphaRef))
      {
        alphaRef = clampBound;
      }
      alphaRef = alphaRef * FLOAT_97c3acbc + FLOAT_97c3acc0;
      alphaRefScaled = (double)alphaRef;
      if (DOUBLE_97c30a78 <= alphaRefScaled) {
        compareWord = (uint)(int)(alphaRefScaled - DOUBLE_97c30a78);
      }
      else {
        compareWord = (uint)(int)alphaRef;
      }
      *codeCursor = 0x10734c0a;
      codeCursor[1] = 0x1063444a;
      codeCursor[2] = 0x10635b2e;
      codeCursor[3] = 0x10601b8a;
      codeCursor[4] = 0x3b000210;
      codeCursor[5] = 0x7c63c1ce;
      compareWord = compareWord & 0xffff | 0x2c170000;
      codeCursor[6] = 0x82e3021c;
    }
    codeCursor[7] = compareWord;
    codeCursor = codeCursor + 8;
    branchField = (uint)(*(int *)(machine[1] + 0xe3c) - (int)codeCursor) >> 2;
  }
  switch(alphaState & 7) {
  case 0:
    branchField = *(int *)(machine[1] + 0xe3c) - (int)codeCursor & 0x3fffffcU | 0x48000000;
    break;
  case 1:
    branchField = (branchField & 0x3fff) << 2 | 0x40800000;
    break;
  case 2:
    branchField = (branchField & 0x3fff) << 2 | 0x40820000;
    break;
  case 3:
    branchField = (branchField & 0x3fff) << 2 | 0x41810000;
    break;
  case 4:
    branchField = (branchField & 0x3fff) << 2 | 0x40810000;
    break;
  case 5:
    branchField = (branchField & 0x3fff) << 2 | 0x41820000;
    break;
  case 6:
    branchField = (branchField & 0x3fff) << 2 | 0x41800000;
    break;
  default:
    goto switchD_97be4bb8_caseD_7;
  }
  *codeCursor = branchField;
  codeCursor = codeCursor + 1;
switchD_97be4bb8_caseD_7:
  return codeCursor;
}

/* _PPCRasterOpMachine_BlendingRTCAV @ 0x97be4c58 (888 bytes) */
int _PPCRasterOpMachine_BlendingRTCAV(machine, codeCursor)
  int *machine;
  uint *codeCursor;
{
  undefined4 *emitPtrAlpha;
  uint alphaEquationWord;
  uint rgbEquationWord;
  uint blendField;
  undefined4 *emitPtr;
  bool equationsEqual;
  undefined4 *factorEnd;
  uint blendState;
  int vectorRegSel;
  
  vectorRegSel = 0x13;
  blendState = *(uint *)(*(int *)(*machine + 0xd80) + 0x58);
  blendField = _PPEmulatorFramebufferFormat(*machine);
  if ((blendField & 0x8000000) == 0) {
    *codeCursor = 0x1273444a;
    codeCursor[1] = 0x12734c0a;
    codeCursor = codeCursor + 2;
  }
  if ((1 < (blendState >> 0x10 & 7) - 3) || (1 < (blendState >> 0x13 & 7) - 3)) {
    if (((((blendState & 0xf) - 8 < 4) ||
         (((blendField = blendState >> 4 & 0xf, blendField == 8 || (blendField == 9)) || (blendField == 10)))) ||
        ((((blendField == 0xb || (blendField = blendState >> 8 & 0xf, blendField == 8)) || (blendField == 9)) ||
         ((blendField == 10 || (blendField == 0xb)))))) ||
       ((blendField = blendState >> 0xc & 0xf, blendField == 8 ||
        (((blendField == 9 || (blendField == 10)) || (blendField == 0xb)))))) {
      *codeCursor = 0x81e30d9c;
      codeCursor[1] = 0x81ef00d8;
      codeCursor[2] = 0x39c02d70;
      codeCursor[3] = 0x7ccf70ce;
      codeCursor = codeCursor + 4;
    }
    emitPtr = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(codeCursor,0,blendState & 0xf);
    blendField = blendState >> 4 & 0xf;
    if ((blendState & 0xf) != blendField) {
      factorEnd = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(emitPtr,3,blendField);
      emitPtr = factorEnd + 1;
      *factorEnd = 0x10001b6a;
    }
    codeCursor = (uint *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(emitPtr,1,blendState >> 8 & 0xf);
    blendField = blendState >> 0xc & 0xf;
    if ((blendState >> 8 & 0xf) != blendField) {
      emitPtrAlpha = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(codeCursor,3,blendField);
      codeCursor = emitPtrAlpha + 1;
      *emitPtrAlpha = 0x10211b6a;
    }
  }
  blendField = blendState >> 0x10 & 7;
  equationsEqual = blendField == (blendState >> 0x13 & 7);
  if (!equationsEqual) {
    vectorRegSel = 3;
  }
  switch(blendField) {
  case 0:
    *codeCursor = 0x1093482e;
    codeCursor = codeCursor + 1;
    *codeCursor = vectorRegSel << 0x15 | 0x1002206e;
    goto LAB_97be4f04;
  case 1:
    *codeCursor = 0x1093482e;
    rgbEquationWord = vectorRegSel << 0x15 | 0x1004284a;
    break;
  case 2:
    *codeCursor = 0x1093482e;
    rgbEquationWord = vectorRegSel << 0x15 | 0x1005204a;
    break;
  case 3:
    rgbEquationWord = vectorRegSel << 0x15 | 0x1013144a;
    goto LAB_97be4f00;
  case 4:
    rgbEquationWord = vectorRegSel << 0x15 | 0x1013140a;
LAB_97be4f00:
    *codeCursor = rgbEquationWord;
    goto LAB_97be4f04;
  default:
    goto switchD_97be4e5c_default;
  }
  codeCursor[1] = 0x10a2486e;
  codeCursor = codeCursor + 2;
  *codeCursor = rgbEquationWord;
LAB_97be4f04:
  codeCursor = codeCursor + 1;
switchD_97be4e5c_default:
  if (equationsEqual) {
    return codeCursor;
  }
  switch(blendState >> 0x13 & 7) {
  case 0:
    alphaEquationWord = 0x1262206e;
    *codeCursor = 0x1093482e;
    goto LAB_97be4f88;
  case 1:
    *codeCursor = 0x1093482e;
    alphaEquationWord = 0x1264284a;
    break;
  case 2:
    *codeCursor = 0x1093482e;
    alphaEquationWord = 0x1265204a;
    break;
  case 3:
    alphaEquationWord = 0x1273144a;
    goto LAB_97be4fc4;
  case 4:
    alphaEquationWord = 0x1273140a;
LAB_97be4fc4:
    *codeCursor = alphaEquationWord;
    goto LAB_97be4fc8;
  default:
    goto switchD_97be4f38_default;
  }
  codeCursor = codeCursor + 1;
  *codeCursor = 0x10a2486e;
LAB_97be4f88:
  codeCursor = codeCursor + 1;
  *codeCursor = alphaEquationWord;
LAB_97be4fc8:
  codeCursor = codeCursor + 1;
switchD_97be4f38_default:
  *codeCursor = vectorRegSel << 0x10 | 0x12609b6a;
  return codeCursor + 1;
}

/* _PPCRasterOpMachine_LogicOpRTCAV @ 0x97be4ff8 (520 bytes) */
int _PPCRasterOpMachine_LogicOpRTCAV(machine, codeCursor)
  int *machine;
  uint *codeCursor;
{
  uint opWord2;
  uint opWord;
  uint logicOp;
  uint logicOpState;
  
  logicOpState = *(uint *)(*(int *)(*machine + 0xd80) + 0x68);
  logicOp = logicOpState & 0xf;
  if ((logicOp < 3) || (logicOp == 4)) {
    if (logicOp == 1) {
      opWord = 0x12684484;
    }
    else if (logicOp < 2) {
      if (logicOp != 0) {
        return codeCursor;
      }
      opWord = 0x12694c84;
    }
    else {
      if (logicOp == 2) {
        return codeCursor;
      }
      if (logicOp != 4) {
        return codeCursor;
      }
      opWord = 0x12621484;
    }
    *codeCursor = opWord;
    goto LAB_97be507c;
  }
  if (logicOp != 5) {
    *codeCursor = 0x10734b2e;
    codeCursor[1] = 0x10601b8a;
    codeCursor = codeCursor + 2;
  }
  logicOpState = logicOpState & 0xf;
  if (logicOpState != 3) {
    *codeCursor = 0x10824b2e;
    codeCursor[1] = 0x1080238a;
    codeCursor = codeCursor + 2;
  }
  switch(logicOpState) {
  case 3:
    opWord = 0x10c30000;
    goto LAB_97be5148;
  default:
    goto switchD_97be5104_caseD_4;
  case 5:
    opWord = 0x10c40000;
LAB_97be5148:
    opWord = opWord | 0x4d04;
    break;
  case 6:
    opWord = 0x10c32404;
    break;
  case 7:
    opWord = 0x10c32404;
    goto LAB_97be51a0;
  case 8:
    opWord = 0x10c32484;
    break;
  case 9:
    opWord = 0x10c32504;
    break;
  case 10:
    opWord = 0x10c324c4;
    break;
  case 0xb:
    opWord = 0x10c324c4;
LAB_97be51a0:
    opWord2 = 0x10c64d04;
LAB_97be51d8:
    *codeCursor = opWord;
    codeCursor = codeCursor + 1;
    *codeCursor = opWord2;
    goto LAB_97be51e0;
  case 0xc:
    opWord = 0x10c32444;
    break;
  case 0xd:
    opWord = 0x10c41c44;
    break;
  case 0xe:
    opWord = 0x10840000;
    goto LAB_97be51cc;
  case 0xf:
    opWord = 0x10630000;
LAB_97be51cc:
    opWord = opWord | 0x4d04;
    opWord2 = 0x10c32484;
    goto LAB_97be51d8;
  }
  *codeCursor = opWord;
LAB_97be51e0:
  codeCursor = codeCursor + 1;
switchD_97be5104_caseD_4:
  *codeCursor = 0x39e00020;
  codeCursor[1] = 0x7c6378ce;
  codeCursor[2] = 0x10c61c04;
  codeCursor[3] = 0x10c0330a;
  codeCursor[4] = 0x39e00070;
  codeCursor[5] = 0x7c6378ce;
  codeCursor = codeCursor + 6;
  *codeCursor = 0x126648ee;
LAB_97be507c:
  return codeCursor + 1;
}

/* _PPCRasterOpMachine_BufferMaskRTCAV @ 0x97be5234 (208 bytes) */
int _PPCRasterOpMachine_BufferMaskRTCAV(machine, codeCursor)
  int *machine;
  undefined4 *codeCursor;
{
  uint writeMasks;
  undefined4 colorMaskWord;
  
  colorMaskWord = 0x1063492c;
  writeMasks = *(uint *)(*(int *)(*machine + 0xd80) + 0x70);
  *codeCursor = 0x10836a8c;
  if ((writeMasks & 0x20000) == 0) {
    colorMaskWord = 0x1063212c;
  }
  codeCursor[1] = colorMaskWord;
  colorMaskWord = 0x1063492c;
  if ((writeMasks & 0x40000) == 0) {
    colorMaskWord = 0x1063212c;
  }
  codeCursor[2] = colorMaskWord;
  colorMaskWord = 0x1063492c;
  if ((writeMasks & 0x80000) == 0) {
    colorMaskWord = 0x1063212c;
  }
  codeCursor[3] = colorMaskWord;
  colorMaskWord = 0x1063492c;
  if ((writeMasks & 0x100000) == 0) {
    colorMaskWord = 0x1063212c;
  }
  codeCursor[4] = colorMaskWord;
  codeCursor[5] = 0x127310ea;
  return codeCursor + 6;
}

/* _PPCRasterOpMachineCalculateBlendingFactorsRTCAV @ 0x97be5304 (400 bytes) */
int _PPCRasterOpMachineCalculateBlendingFactorsRTCAV(codeCursor, vectorReg, blendFactor)
  uint *codeCursor;
  int vectorReg;
  undefined4 blendFactor;
{
  uint factorWord;
  uint factorWord2;
  
  switch(blendFactor) {
  case 0:
    factorWord = vectorReg << 0x15 | 0x10094c84;
    break;
  case 1:
    factorWord = vectorReg << 0x15 | 0x10084484;
    break;
  case 2:
    factorWord = vectorReg << 0x15 | 0x10139c84;
    break;
  case 3:
    factorWord = vectorReg << 0x15 | 0x1008984a;
    break;
  case 4:
    factorWord = vectorReg << 0x15 | 0x10039a8c;
    break;
  case 5:
    factorWord = vectorReg << 0x15 | vectorReg << 0xb | 0x10080000;
    factorWord2 = vectorReg << 0x15 | 0x10039a8c;
    goto LAB_97be545c;
  case 6:
    factorWord = vectorReg << 0x15 | 0x1003128c;
    break;
  case 7:
    factorWord = vectorReg << 0x15 | vectorReg << 0xb | 0x10080000;
    factorWord2 = vectorReg << 0x15 | 0x1003128c;
    goto LAB_97be545c;
  case 8:
    factorWord = vectorReg << 0x15 | 0x10063484;
    break;
  case 9:
    factorWord = vectorReg << 0x15 | 0x1008304a;
    break;
  case 10:
    factorWord = vectorReg << 0x15 | 0x1003328c;
    break;
  case 0xb:
    factorWord = vectorReg << 0x15 | vectorReg << 0xb | 0x10080000;
    factorWord2 = vectorReg << 0x15 | 0x1003328c;
LAB_97be545c:
    *codeCursor = factorWord2;
    codeCursor = codeCursor + 1;
    *codeCursor = factorWord | 0x4a;
    goto LAB_97be5394;
  case 0xc:
    factorWord = vectorReg << 0x15 | 0x10021484;
    break;
  case 0xd:
    factorWord = vectorReg << 0x15 | 0x1008104a;
    break;
  case 0xe:
    factorWord = vectorReg << 0x15;
    factorWord2 = factorWord | vectorReg << 0x10;
    *codeCursor = factorWord | 0x1008104a;
    codeCursor[1] = factorWord2 | 0x10009c4a;
    codeCursor[2] = factorWord | vectorReg << 0xb | 0x1003028c;
    codeCursor = codeCursor + 3;
    *codeCursor = factorWord2 | 0x1000436a;
    goto LAB_97be5394;
  default:
    return codeCursor;
  }
  *codeCursor = factorWord;
LAB_97be5394:
  return codeCursor + 1;
}

/* _PPCRasterOpMachineUpdateStencilBufferRTCAV @ 0x97be54d0 (468 bytes) */
int _PPCRasterOpMachineUpdateStencilBufferRTCAV(stencilOp, stencilPtrReg, valueReg, stencilRef, writeMask, codeCursor)
  undefined4 stencilOp;
  int stencilPtrReg;
  uint valueReg;
  uint stencilRef;
  uint writeMask;
  uint *codeCursor;
{
  uint clearBitsWord;
  uint deltaLoadWord;
  uint *emitPtr;
  
  switch(stencilOp) {
  case 0:
    *codeCursor = writeMask ^ 0xffff | valueReg << 0x15 | 0x701e0000;
    emitPtr = codeCursor + 1;
    *emitPtr = stencilPtrReg << 0x10 | 0x9bc00000;
    goto LAB_97be5588;
  case 1:
    return codeCursor;
  case 2:
    *codeCursor = writeMask ^ 0xffff | valueReg << 0x15 | 0x701e0000;
    codeCursor[1] = stencilRef & writeMask | 0x3be00000;
    emitPtr = codeCursor + 2;
    *emitPtr = 0x7fdefb78;
    goto LAB_97be5580;
  case 3:
    *codeCursor = (valueReg & 0x1f) << 0x10 | 0x2c0000ff;
    codeCursor[1] = valueReg << 0x10 | 0x3be00000;
    codeCursor[2] = 0x40800008;
    clearBitsWord = writeMask ^ 0xffff | valueReg << 0x15;
    deltaLoadWord = valueReg << 0x10 | 0x3be00001;
    break;
  case 4:
    *codeCursor = (valueReg & 0x1f) << 0x10 | 0x2c000000;
    codeCursor[1] = valueReg << 0x10 | 0x3be00000;
    codeCursor[2] = 0x40810008;
    clearBitsWord = writeMask ^ 0xffff | valueReg << 0x15;
    deltaLoadWord = valueReg << 0x10 | 0x3be0ffff;
    break;
  case 5:
    *codeCursor = writeMask ^ 0xffff | valueReg << 0x15 | 0x701e0000;
    codeCursor[1] = valueReg << 0x15 | valueReg << 0xb | 0x7c1f00f8;
    codeCursor[2] = writeMask | 0x73ff0000;
    codeCursor[3] = 0x7fdefb78;
    codeCursor[4] = stencilPtrReg << 0x10 | 0x9bc00000;
    return codeCursor + 5;
  case 6:
    clearBitsWord = writeMask ^ 0xffff | valueReg << 0x15;
    deltaLoadWord = valueReg << 0x10 | 0x3be00001;
    goto LAB_97be55e8;
  case 7:
    clearBitsWord = writeMask ^ 0xffff | valueReg << 0x15;
    deltaLoadWord = valueReg << 0x10 | 0x3be0ffff;
LAB_97be55e8:
    *codeCursor = deltaLoadWord;
    emitPtr = codeCursor + 1;
    *emitPtr = 0x73ff00ff;
    goto LAB_97be55f4;
  default:
    return codeCursor;
  }
  emitPtr = codeCursor + 3;
  *emitPtr = deltaLoadWord;
LAB_97be55f4:
  emitPtr[1] = clearBitsWord | 0x701e0000;
  emitPtr[2] = writeMask | 0x73ff0000;
  emitPtr = emitPtr + 3;
  *emitPtr = 0x7fdefb78;
LAB_97be5580:
  emitPtr = emitPtr + 1;
  *emitPtr = stencilPtrReg << 0x10 | 0x9bc00000;
LAB_97be5588:
  return emitPtr + 1;
}

