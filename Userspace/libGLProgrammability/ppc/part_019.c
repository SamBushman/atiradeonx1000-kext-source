#include "decls.h"

/* _GetRegisterTypeInfo @ 0x97c0b704 (544 bytes) */
int _GetRegisterTypeInfo(stream, regInfo)
  int stream;
  undefined4 *regInfo;
{
  uint constantX;
  int chunk;
  uint chunkWord;
  undefined4 usageList;
  int constantChunk;
  uint constantZ;
  uint constantY;
  double constantYDouble;
  double constantZDouble;
  double constantWDouble;
  
  switch(regInfo[1]) {
  case 0:
    chunk = _PPStreamChunkListChunkAtIndex(*(undefined4 *)(stream + 0x18),*regInfo);
    if (chunk != 0) {
      regInfo[2] = *(uint *)(chunk + 0xc) >> 0x1d;
      regInfo[3] = *(uint *)(chunk + 0xc) >> 0x1a & 7;
      regInfo[4] = *(uint *)(chunk + 0xc) >> 0x18 & 3;
    }
    regInfo[5] = 0;
    break;
  case 1:
    usageList = *(undefined4 *)(stream + 4);
    goto setChunk;
  case 2:
    chunk = _PPStreamChunkListChunkAtIndex(*(undefined4 *)(stream + 0x10),*regInfo);
    regInfo[2] = *(uint *)(chunk + 0xc) >> 0x1d;
    regInfo[3] = *(uint *)(chunk + 0xc) >> 0x1a & 7;
    chunkWord = *(uint *)(chunk + 0xc);
    regInfo[5] = 0;
    regInfo[4] = chunkWord >> 0x18 & 3;
    if ((*(uint *)(chunk + 0xc) >> 0x10 & 0x1f) == 0x11) {
      regInfo[5] = 1;
      constantChunk = _PPStreamChunkListChunkAtIndex
                        (*(undefined4 *)(stream + 0x2c),(uint)*(ushort *)(chunk + 0xe));
      constantY = *(uint *)(constantChunk + 0x10);
      constantX = *(uint *)(constantChunk + 0xc);
      constantZ = *(uint *)(constantChunk + 0x14);
      if (regInfo[3] == 1) {
        regInfo[9] = *(uint *)(constantChunk + 0x18);
        regInfo[6] = constantX;
        regInfo[7] = constantY;
        regInfo[8] = constantZ;
      }
      else {
        constantWDouble = (double)CONCAT44(0x43300000,*(uint *)(constantChunk + 0x18) ^ 0x80000000) - DOUBLE_97c30a58;
        constantYDouble = (double)CONCAT44(0x43300000,constantY ^ 0x80000000) - DOUBLE_97c30a58;
        constantZDouble = (double)CONCAT44(0x43300000,constantZ ^ 0x80000000) - DOUBLE_97c30a58;
        regInfo[6] = (float)((double)CONCAT44(0x43300000,constantX ^ 0x80000000) - DOUBLE_97c30a58);
        regInfo[7] = (float)constantYDouble;
        regInfo[8] = (float)constantZDouble;
        regInfo[9] = (float)constantWDouble;
      }
    }
    break;
  case 3:
    usageList = *(undefined4 *)(stream + 0x1c);
setChunk:
    chunk = _PPStreamChunkListChunkAtIndex(usageList,*regInfo);
    regInfo[2] = *(uint *)(chunk + 0xc) >> 0x1d;
    regInfo[3] = *(uint *)(chunk + 0xc) >> 0x1a & 7;
    chunkWord = *(uint *)(chunk + 0xc);
    regInfo[5] = 0;
    regInfo[4] = chunkWord >> 0x18 & 3;
    break;
  case 4:
    regInfo[5] = 0;
    regInfo[3] = 3;
    regInfo[2] = 0;
    regInfo[4] = 0;
  }
  return;
}

/* _FlattenIf @ 0x97c0b938 (3384 bytes) */
int _FlattenIf(stream, ifChunk, elseChunk, endifChunk)
  int stream;
  int ifChunk;
  int elseChunk;
  int endifChunk;
{
  int *modifiedPair;
  int *anlSizesBase;
  undefined4 *freedPair;
  int selectedRegister;
  int anlOperandOffset;
  int tableOffset;
  int pairTempInfo;
  uint swizzleComponent;
  uint destWordCopy;
  uint pairDestWord;
  uint oldSrcWord;
  uint killType;
  uint sourceIndex;
  uint destSizeBits;
  uint sizeShifted;
  uint newBankShifted;
  uint anlSizeShifted;
  uint killMaskWord;
  uint nextSourceIndex;
  uint sizeBits;
  uint killSrcWord;
  uint anlBankShifted;
  uint killPrecision;
  undefined4 branchValueInfo;
  undefined4 ifReverseTable;
  undefined4 addTempRegisterResult2;
  int modifiedRegister;
  int ifForwardTable;
  uint loopIndex;
  undefined4 srcOriginalCopy;
  undefined2 anlNumberHalf;
  uint *anlNegateSlot;
  uint *anlBanksBase;
  uint *anlNegatesBase;
  undefined1 *anlLoopEnd;
  uint condPrecision;
  uint condDestWord;
  undefined2 addTempRegisterResult;
  undefined4 destOriginalCopy;
  int branchOp;
  int sourceCount;
  undefined4 *tempInfo;
  int *condInfoSlot;
  undefined2 *anlNumberHalfCursor;
  uint condType;
  undefined1 *anlSrcCursor;
  undefined4 elseForwardTable;
  uint destSizeShifted;
  uint condComponent;
  int loopByteOffset;
  undefined4 elseReverseTable;
  int operandCursor;
  int endifChunkHome;
  undefined1 condInfo0 [8];
  undefined1 condInfo0Rest [40];
  undefined1 condInfo1 [48];
  uint op1Header;
  uint op1Flags;
  uint op1Dest0;
  undefined4 op1Dest1;
  uint op1Src0A;
  undefined4 op1Src0B;
  undefined4 op1Src1A;
  undefined4 op1Src1B;
  undefined4 op1Src2A;
  undefined4 op1Src2B;
  undefined4 op1AuxA;
  undefined4 op1AuxB;
  undefined4 op1Line;
  undefined4 op1Word13;
  uint keyIteratorOverlay;
  uint lookupKeyBank;
  undefined4 lookupKeyPrecision;
  undefined4 lookupKeyType;
  undefined4 keySizePairHeaderOverlay;
  uint pairOpFlags;
  uint pairOpDest0;
  uint pairOpDest1;
  uint pairOpSrc0A;
  uint pairOpSrc0B;
  undefined4 pairOpSrc1A;
  undefined4 pairOpSrc1B;
  undefined4 op2Header;
  uint op2Flags;
  uint op2Dest0;
  undefined4 op2Dest1;
  uint op2Src0A;
  undefined4 op2Src0B;
  undefined2 op2Src0BHigh;
  undefined4 op2Src1A;
  undefined4 op2Src1B;
  undefined4 op2Src2A;
  undefined4 op2Src2B;
  undefined4 op2AuxA;
  undefined4 op2AuxB;
  undefined4 op2Line;
  undefined4 op2Word13;
  undefined4 op3Header;
  uint op3Flags;
  uint op3Dest0;
  uint op3Dest1;
  uint op3Src0A;
  undefined4 op3Src0B;
  undefined2 op3Src0BHigh;
  undefined4 op3Src1A;
  undefined4 op3Src1B;
  undefined4 op3Src2A;
  undefined4 op3Src2B;
  undefined4 op3AuxA;
  undefined4 op3AuxB;
  undefined4 op3Line;
  undefined4 op3Word13;
  undefined1 *srcInfoPtrs;
  int srcInfoPtrs1;
  int srcInfoPtrs2;
  uint srcNegateFlags [4];
  int srcBroadcastFlags [4];
  undefined1 *condInfos [2];
  undefined8 condOpcodes;
  int branchTables [10];
  uint anlSrcBank0;
  undefined4 anlSrcBank1;
  uint anlSrcNumber0;
  undefined4 anlSrcNumber1;
  uint anlSrcNegate0;
  undefined4 anlSrcNegate1;
  int selectScratch [3];
  int *anlSrcSizesPtr;
  uint *anlSrcBanksPtr;
  uint *anlSrcNumbersPtr;
  uint *anlSrcNegatesPtr;
  undefined1 *anlSrcLoopEnd;
  
  condComponent = *(uint *)(ifChunk + 0x1c) >> 0x15 & 3;
  condOpcodes = 10;
  condInfos[1] = condInfo1;
  condInfos[0] = condInfo0;
  loopIndex = 0;
  loopByteOffset = 0;
  endifChunkHome = endifChunk;
  do {
    op1Line = *(undefined4 *)(ifChunk + 0x3c);
    op1Dest1 = 0;
    condPrecision = *(uint *)(ifChunk + 0x10) >> 0x12 & 3;
    op1Src0A = 0;
    op1Src0B = 0;
    condType = *(uint *)(ifChunk + 0x10) >> 0x17 & 7;
    op1Src1A = 0;
    op1Src1B = 0;
    op1Src2A = 0;
    op1Src2B = 0;
    op1AuxA = 0;
    op1AuxB = 0;
    op1Word13 = 0;
    condDestWord = condComponent << 10;
    op1Flags = condType << 0x17 | condPrecision << 0x12;
    op1Header = (*(uint *)((int)branchTables + loopByteOffset + -8) & 0xff) << 0x12 | 0x20000000;
    if (condComponent == 1) {
      condDestWord = 0x4400;
    }
    else if (1 < condComponent) {
      if (condComponent == 2) {
        condDestWord = 0x8800;
      }
      else if (condComponent == 3) {
        condDestWord = 0x10c00;
      }
    }
    else if (condComponent == 0) {
      condDestWord = 0x2000;
    }
    op1Dest0 = condDestWord | 0x20000;
    addTempRegisterResult = _AddTempRegister(stream,condPrecision,condType,(condDestWord & 0xc00) >> 10);
    op1Src0A = (*(uint *)(ifChunk + 0x1c) >> 0x1b & 1) << 0x1b |
                (*(uint *)(ifChunk + 0x1c) >> 0x17 & 7) << 0x17 |
                condComponent << 0x15 | op1Src0A & 0xf41fcfff;
    op1Dest1 = CONCAT22((*(unsigned short *)((unsigned char *)&(op1Dest1) + 0)),addTempRegisterResult);
    op1Src0B = CONCAT22((*(unsigned short *)((unsigned char *)&(op1Src0B) + 0)),*(undefined2 *)(ifChunk + 0x22));
    _PPStreamInsertOperationBeforeChunk(stream,&op1Header,0,0,ifChunk);
    loopIndex = loopIndex + 1;
    *(uint *)(*(int *)((int)condInfos + loopByteOffset) + 4) = op1Dest0 >> 0x11 & 7;
    **(uint **)((int)condInfos + loopByteOffset) = op1Dest1 & 0xffff;
    *(uint *)(*(int *)((int)condInfos + loopByteOffset) + 8) = op1Flags >> 0x12 & 3;
    *(uint *)(*(int *)((int)condInfos + loopByteOffset) + 0xc) = op1Flags >> 0x17 & 7;
    condInfoSlot = (int *)((int)condInfos + loopByteOffset);
    loopByteOffset = loopByteOffset + 4;
    *(uint *)(*condInfoSlot + 0x10) = op1Dest0 >> 10 & 3;
  } while (loopIndex < 2);
  elseForwardTable = 0;
  elseReverseTable = 0;
  ifForwardTable = _HashTableNew((*(uint *)(*(int *)(stream + 4) + 8) >> 5) + 1,regHashFunctionPtr,regEqualsFunctionPtr);
  ifReverseTable = _HashTableNew((*(uint *)(*(int *)(stream + 4) + 8) >> 5) + 1,regHashFunctionPtr,regEqualsFunctionPtr);
  if (elseChunk != 0) {
    elseForwardTable = _HashTableNew((*(uint *)(*(int *)(stream + 4) + 8) >> 5) + 1,regHashFunctionPtr,regEqualsFunctionPtr
                          );
    elseReverseTable = _HashTableNew((*(uint *)(*(int *)(stream + 4) + 8) >> 5) + 1,regHashFunctionPtr,regEqualsFunctionPtr
                          );
  }
  selectScratch[2] = _HashSetNew((*(uint *)(*(int *)(stream + 4) + 8) >> 5) + 1,regHashFunctionPtr,
                            regEqualsFunctionPtr);
  branchTables[0] = ifForwardTable;
  branchTables[1] = elseForwardTable;
  branchTables[2] = ifReverseTable;
  branchTables[3] = elseReverseTable;
  branchTables[4] = ifChunk;
  branchTables[5] = elseChunk;
  if (elseChunk == 0) {
    elseChunk = endifChunkHome;
  }
  loopIndex = 0;
  branchTables[6] = elseChunk;
  loopByteOffset = 0;
  branchTables[7] = endifChunkHome;
  do {
    branchOp = *(int *)((int)branchTables + loopByteOffset + 0x10);
    if ((branchOp != 0) &&
       (branchOp = *(int *)(branchOp + 8), branchOp != *(int *)((int)branchTables + loopByteOffset + 0x18))) {
      anlSrcSizesPtr = branchTables + 8;
      anlSrcBanksPtr = &anlSrcBank0;
      anlSrcNumbersPtr = &anlSrcNumber0;
      anlSrcNegatesPtr = &anlSrcNegate0;
      anlSrcLoopEnd = condInfo0Rest;
      do {
        sourceCount = _GetValidArgs(branchOp);
        if (0 < sourceCount) {
          operandCursor = branchOp;
          do {
            lookupKeyBank = *(uint *)(operandCursor + 0x1c) >> 0x17 & 7;
            keyIteratorOverlay = (uint)*(ushort *)(operandCursor + 0x22);
            tempInfo = (undefined4 *)
                      _HashTableGet(*(undefined4 *)((int)branchTables + loopByteOffset),&keyIteratorOverlay);
            if (tempInfo == (undefined4 *)0x0) {
              ((int (*)())_GetRegisterTypeInfo)(stream,&keyIteratorOverlay);
              srcOriginalCopy = _malloc(0x28);
              _memcpy(srcOriginalCopy,&keyIteratorOverlay,0x28);
              tempInfo = (undefined4 *)_malloc(0x28);
              _memcpy(tempInfo,&keyIteratorOverlay,0x28);
              tempInfo[1] = 1;
              addTempRegisterResult2 = _AddTempRegister(stream,lookupKeyPrecision,lookupKeyType,keySizePairHeaderOverlay);
              *tempInfo = addTempRegisterResult2;
              _HashTableAdd(*(undefined4 *)((int)branchTables + loopByteOffset),srcOriginalCopy,tempInfo);
              _HashTableAdd(*(undefined4 *)((int)branchTables + loopByteOffset + 8),tempInfo,srcOriginalCopy);
            }
            else {
              _HashTableGet(*(undefined4 *)((int)branchTables + loopByteOffset + 8),tempInfo);
            }
            sourceCount = sourceCount + -1;
            *(uint *)(operandCursor + 0x1c) =
                 (tempInfo[1] & 7) << 0x17 | *(uint *)(operandCursor + 0x1c) & 0xfc7fffff;
            *(undefined2 *)(operandCursor + 0x22) = *(undefined2 *)((int)tempInfo + 2);
            operandCursor = operandCursor + 8;
          } while (sourceCount != 0);
        }
        if ((*(uint *)(branchOp + 0x14) & 0x1e000) != 0) {
          lookupKeyBank = *(uint *)(branchOp + 0x14) >> 0x11 & 7;
          keyIteratorOverlay = (uint)*(ushort *)(branchOp + 0x1a);
          tempInfo = (undefined4 *)_HashTableGet(*(undefined4 *)((int)branchTables + loopByteOffset),&keyIteratorOverlay);
          if (tempInfo == (undefined4 *)0x0) {
            ((int (*)())_GetRegisterTypeInfo)(stream,&keyIteratorOverlay);
            destOriginalCopy = _malloc(0x28);
            _memcpy(destOriginalCopy,&keyIteratorOverlay,0x28);
            tempInfo = (undefined4 *)_malloc(0x28);
            _memcpy(tempInfo,&keyIteratorOverlay,0x28);
            tempInfo[1] = 1;
            addTempRegisterResult2 = _AddTempRegister(stream,lookupKeyPrecision,lookupKeyType,keySizePairHeaderOverlay);
            *tempInfo = addTempRegisterResult2;
            _HashTableAdd(*(undefined4 *)((int)branchTables + loopByteOffset),destOriginalCopy,tempInfo);
            _HashTableAdd(*(undefined4 *)((int)branchTables + loopByteOffset + 8),tempInfo,destOriginalCopy);
          }
          else {
            destOriginalCopy = _HashTableGet(*(undefined4 *)((int)branchTables + loopByteOffset + 8),tempInfo);
          }
          if (selectScratch[2] != 0) {
            _HashSetAdd(selectScratch[2],destOriginalCopy);
          }
          *(uint *)(branchOp + 0x14) = (tempInfo[1] & 7) << 0x11 | *(uint *)(branchOp + 0x14) & 0xfff1ffff;
          *(undefined2 *)(branchOp + 0x1a) = *(undefined2 *)((int)tempInfo + 2);
        }
        if ((*(uint *)(branchOp + 0xc) >> 0x12 & 0xff) == 0x4f) {
          op2Src0A = 0;
          op2Src0B = 0;
          op2Src1A = 0;
          op2Src1B = 0;
          op2Src2A = 0;
          op2Src2B = 0;
          op2AuxA = 0;
          op2AuxB = 0;
          op2Line = *(undefined4 *)(branchOp + 0x3c);
          op2Dest1 = 0;
          op2Header = 0x40900000;
          op2Word13 = 0;
          killPrecision = *(uint *)(branchOp + 0x10) >> 0x12 & 3;
          killMaskWord = condComponent << 10;
          killType = *(uint *)(branchOp + 0x10) >> 0x17 & 7;
          op2Flags = killType << 0x17 | killPrecision << 0x12;
          if (condComponent == 1) {
            killMaskWord = 0x4400;
          }
          else if (1 < condComponent) {
            if (condComponent == 2) {
              killMaskWord = 0x8800;
            }
            else if (condComponent == 3) {
              killMaskWord = 0x10c00;
            }
          }
          else if (condComponent == 0) {
            killMaskWord = 0x2000;
          }
          op2Dest0 = killMaskWord | 0x20000;
          addTempRegisterResult = _AddTempRegister(stream,killPrecision,killType,(killMaskWord & 0xc00) >> 10);
          anlLoopEnd = anlSrcLoopEnd;
          anlNegatesBase = anlSrcNegatesPtr;
          anlBanksBase = anlSrcBanksPtr;
          anlSizesBase = anlSrcSizesPtr;
          op2Dest1 = CONCAT22((*(unsigned short *)((unsigned char *)&(op2Dest1) + 0)),addTempRegisterResult);
          anlOperandOffset = 0;
          branchTables[8] = *(uint *)(branchOp + 0x1c) >> 0x15 & 3;
          branchTables[9] = condComponent;
          anlSrcBank0 = *(uint *)(branchOp + 0x1c) >> 0x17 & 7;
          anlSrcBank1 = *(undefined4 *)(*(int *)((int)condInfos + loopByteOffset) + 4);
          anlSrcNumber0 = (uint)*(ushort *)(branchOp + 0x22);
          anlSrcNumber1 = **(undefined4 **)((int)condInfos + loopByteOffset);
          anlNumberHalfCursor = (undefined2 *)((int)anlSrcNumbersPtr + 2);
          anlSrcNegate0 = (uint)((*(uint *)(branchOp + 0x1c) & 0x8000000) == 0);
          anlSrcNegate1 = 0;
          anlSrcCursor = condInfo0;
          do {
            oldSrcWord = *(uint *)(anlSrcCursor + 0xe0);
            *(uint *)(anlSrcCursor + 0xe0) = oldSrcWord & 0xffffcfff;
            anlSizeShifted = (*(uint *)(anlOperandOffset + (int)anlSizesBase) & 3) << 0x15;
            *(uint *)(anlSrcCursor + 0xe0) = anlSizeShifted | oldSrcWord & 0xff9fcfff;
            anlBankShifted = (*(uint *)(anlOperandOffset + (int)anlBanksBase) & 7) << 0x17;
            *(uint *)(anlSrcCursor + 0xe0) = anlBankShifted | anlSizeShifted | oldSrcWord & 0xfc1fcfff;
            anlNumberHalf = *anlNumberHalfCursor;
            anlNumberHalfCursor = anlNumberHalfCursor + 2;
            *(undefined2 *)(anlSrcCursor + 0xe6) = anlNumberHalf;
            anlNegateSlot = (uint *)(anlOperandOffset + (int)anlNegatesBase);
            anlOperandOffset = anlOperandOffset + 4;
            *(uint *)(anlSrcCursor + 0xe0) = (*anlNegateSlot & 1) << 0x1b | anlBankShifted | anlSizeShifted | oldSrcWord & 0xf41fcfff;
            anlSrcCursor = anlSrcCursor + 8;
          } while (anlSrcCursor <= anlLoopEnd);
          killSrcWord = *(uint *)(branchOp + 0x1c);
          newBankShifted = (op2Dest0 >> 0x11 & 7) << 0x17;
          *(uint *)(branchOp + 0x1c) = newBankShifted | killSrcWord & 0xfc7fffff;
          *(uint *)(branchOp + 0x1c) = condComponent << 0x15 | newBankShifted | killSrcWord & 0xfc1fffff | 0x8000000;
          *(undefined2 *)(branchOp + 0x22) = addTempRegisterResult;
          _PPStreamInsertOperationBeforeChunk(stream,&op2Header,0,0,branchOp);
        }
        branchOp = *(int *)(branchOp + 8);
      } while (branchOp != *(int *)((int)branchTables + loopByteOffset + 0x18));
    }
    loopIndex = loopIndex + 1;
    loopByteOffset = loopByteOffset + 4;
  } while (loopIndex < 2);
  loopIndex = 0;
  loopByteOffset = 0;
  do {
    if (*(int *)((int)branchTables + loopByteOffset + 0x10) != 0) {
      _HashSetIteratorSetup(**(undefined4 **)((int)branchTables + loopByteOffset),&keyIteratorOverlay);
      modifiedPair = (int *)_HashSetIteratorNext(&keyIteratorOverlay);
      while (modifiedPair != (int *)0x0) {
        pairTempInfo = modifiedPair[1];
        op2Src0A = 0;
        pairOpSrc1A = 0;
        pairOpSrc1B = 0;
        op2Header = 0;
        op2Flags = 0;
        op2Dest0 = 0;
        op2Dest1 = 0;
        op2Src0B = 0;
        keySizePairHeaderOverlay = 0x20000000;
        op2Src0A = *(undefined4 *)(*(int *)((int)branchTables + loopByteOffset + 0x10) + 0x3c);
        sizeShifted = (*(uint *)(pairTempInfo + 0x10) & 3) << 10;
        pairDestWord = sizeShifted | 0x6c;
        sizeBits = *(uint *)(pairTempInfo + 0x10) & 3;
        if (sizeBits == 1) {
loopSetPairDestWord:
          pairDestWord = pairDestWord | 0x4000;
loopSetPairDestWord2:
          pairDestWord = pairDestWord | 0x2000;
        }
        else {
          if (1 < sizeBits) {
            if (sizeBits != 2) {
              if (sizeBits != 3) goto setPairOpDest0;
              pairDestWord = sizeShifted | 0x1006c;
            }
            pairDestWord = pairDestWord | 0x8000;
            goto loopSetPairDestWord;
          }
          if (sizeBits == 0) goto loopSetPairDestWord2;
        }
setPairOpDest0:
        pairOpDest0 = (*(uint *)(pairTempInfo + 4) & 7) << 0x11 | pairDestWord;
        pairOpDest1 = (uint)*(ushort *)(pairTempInfo + 2);
        pairOpSrc0A = (*(uint *)(*modifiedPair + 4) & 7) << 0x17 |
                    ((pairDestWord & 0xc00) >> 10) << 0xc | 0xd8000;
        pairOpSrc0B = (uint)*(ushort *)(*modifiedPair + 2);
        pairOpFlags = (*(uint *)(pairTempInfo + 0x10) & 3) << 0x1a |
                    (*(uint *)(pairTempInfo + 0xc) & 7) << 0x17 | (*(uint *)(pairTempInfo + 8) & 3) << 0x12;
        _PPStreamInsertOperationAfterChunk
                  (stream,&keySizePairHeaderOverlay,0,0,*(undefined4 *)((int)branchTables + loopByteOffset + 0x10));
        modifiedPair = (int *)_HashSetIteratorNext(&keyIteratorOverlay);
      }
      _PPStreamRemoveOperation(stream,*(undefined4 *)((int)branchTables + loopByteOffset + 0x10));
    }
    loopIndex = loopIndex + 1;
    loopByteOffset = loopByteOffset + 4;
  } while (loopIndex < 2);
  _HashSetIteratorSetup(selectScratch[2],&op2Src2A);
  modifiedRegister = _HashSetIteratorNext(&op2Src2A);
  do {
    if (modifiedRegister == 0) {
      loopIndex = 0;
      loopByteOffset = 0;
      _PPStreamRemoveOperation(stream,endifChunkHome);
      do {
        if (*(undefined4 **)((int)branchTables + loopByteOffset) != (undefined4 *)0x0) {
          _HashSetIteratorSetup(**(undefined4 **)((int)branchTables + loopByteOffset),&op3Header);
          freedPair = (undefined4 *)_HashSetIteratorNext(&op3Header);
          while (freedPair != (undefined4 *)0x0) {
            _free(*freedPair);
            _free(freedPair[1]);
            freedPair = (undefined4 *)_HashSetIteratorNext(&op3Header);
          }
          _HashTableFree(*(undefined4 *)((int)branchTables + loopByteOffset));
          _HashTableFree(*(undefined4 *)((int)branchTables + loopByteOffset + 8));
        }
        loopIndex = loopIndex + 1;
        loopByteOffset = loopByteOffset + 4;
      } while (loopIndex < 2);
      _HashSetFree(selectScratch[2]);
      return;
    }
    selectScratch[0] = 0;
    selectScratch[1] = 0;
    loopIndex = 0;
    tableOffset = 0;
    do {
      if (*(int *)((int)branchTables + tableOffset) != 0) {
        branchValueInfo = _HashTableGet(*(int *)((int)branchTables + tableOffset),modifiedRegister);
        *(undefined4 *)((int)selectScratch + tableOffset) = branchValueInfo;
      }
      loopIndex = loopIndex + 1;
      tableOffset = tableOffset + 4;
    } while (loopIndex < 2);
    loopIndex = 0;
    tableOffset = 0;
    do {
      selectedRegister = *(int *)((int)selectScratch + tableOffset);
      if (*(int *)((int)selectScratch + tableOffset) == 0) {
        selectedRegister = modifiedRegister;
      }
      loopIndex = loopIndex + 1;
      *(int *)((int)selectScratch + tableOffset) = selectedRegister;
      tableOffset = tableOffset + 4;
    } while (loopIndex < 2);
    if (selectScratch[0] != selectScratch[1]) {
      op3Flags = 0;
      op3Word13 = 0;
      op3Header = 0x60f80000;
      op3Line = *(undefined4 *)(endifChunkHome + 0x3c);
      op3Src0A = 0;
      op3Src0B = 0;
      op3Src1A = 0;
      op3Src1B = 0;
      op3Src2A = 0;
      op3Src2B = 0;
      op3AuxA = 0;
      op3AuxB = 0;
      destSizeShifted = (*(uint *)(modifiedRegister + 0x10) & 3) << 10;
      op3Dest0 = destSizeShifted | 0x6c;
      destSizeBits = *(uint *)(modifiedRegister + 0x10) & 3;
      if (destSizeBits == 1) {
loopSetOp3Dest0:
        op3Dest0 = op3Dest0 | 0x4000;
loopSetOp3Dest02:
        op3Dest0 = op3Dest0 | 0x2000;
      }
      else {
        if (1 < destSizeBits) {
          if (destSizeBits != 2) {
            if (destSizeBits != 3) goto setOp3Dest0;
            op3Dest0 = destSizeShifted | 0x1006c;
          }
          op3Dest0 = op3Dest0 | 0x8000;
          goto loopSetOp3Dest0;
        }
        if (destSizeBits == 0) goto loopSetOp3Dest02;
      }
setOp3Dest0:
      op3Dest0 = (*(uint *)(modifiedRegister + 4) & 7) << 0x11 | op3Dest0;
      srcBroadcastFlags[2] = 0;
      srcNegateFlags[2] = 0;
      op3Dest1 = (uint)*(ushort *)(modifiedRegister + 2);
      srcInfoPtrs = condInfos[0];
      srcInfoPtrs1 = selectScratch[0];
      srcInfoPtrs2 = selectScratch[1];
      srcBroadcastFlags[0] = 1;
      srcBroadcastFlags[1] = 0;
      srcNegateFlags[0] = 1;
      srcNegateFlags[1] = 0;
      destWordCopy = op3Dest0;
      sourceIndex = 0;
      do {
        (&op3Src0A)[sourceIndex * 2] = (destWordCopy >> 10 & 3) << 0xc | (&op3Src0A)[sourceIndex * 2] & 0xffffcfff;
        swizzleComponent = condComponent;
        if (srcBroadcastFlags[sourceIndex] == 0) {
          swizzleComponent = 0;
        }
        (&op3Src0A)[sourceIndex * 2] = swizzleComponent << 0x15 | (&op3Src0A)[sourceIndex * 2] & 0xff9fffff;
        swizzleComponent = condComponent;
        if (srcBroadcastFlags[sourceIndex] == 0) {
          swizzleComponent = 1;
        }
        (&op3Src0A)[sourceIndex * 2] = swizzleComponent << 0x13 | (&op3Src0A)[sourceIndex * 2] & 0xffe7ffff;
        swizzleComponent = condComponent;
        if (srcBroadcastFlags[sourceIndex] == 0) {
          swizzleComponent = 2;
        }
        (&op3Src0A)[sourceIndex * 2] = swizzleComponent << 0x11 | (&op3Src0A)[sourceIndex * 2] & 0xfff9ffff;
        swizzleComponent = condComponent;
        if (srcBroadcastFlags[sourceIndex] == 0) {
          swizzleComponent = 3;
        }
        (&op3Src0A)[sourceIndex * 2] = swizzleComponent << 0xf | (&op3Src0A)[sourceIndex * 2] & 0xfffe7fff;
        nextSourceIndex = sourceIndex + 1;
        (&op3Src0A)[sourceIndex * 2] =
             (*(uint *)((&srcInfoPtrs)[sourceIndex] + 4) & 7) << 0x17 | (&op3Src0A)[sourceIndex * 2] & 0xfc7fffff;
        (&op3Src0BHigh)[sourceIndex * 4] = *(undefined2 *)((&srcInfoPtrs)[sourceIndex] + 2);
        (&op3Src0A)[sourceIndex * 2] =
             (srcNegateFlags[sourceIndex] & 1) << 0x1b | (&op3Src0A)[sourceIndex * 2] & 0xf7ffffff;
        destWordCopy = op3Dest0;
        sourceIndex = nextSourceIndex;
      } while (nextSourceIndex < 3);
      op3Flags = (*(uint *)(modifiedRegister + 0x10) & 3) << 0x1a |
                  (*(uint *)(modifiedRegister + 0xc) & 7) << 0x17 | (*(uint *)(modifiedRegister + 8) & 3) << 0x12;
      _PPStreamInsertOperationAfterChunk(stream,&op3Header,0,0,endifChunkHome);
    }
    modifiedRegister = _HashSetIteratorNext(&op2Src2A);
  } while( true );
}

/* _IsBadUsage @ 0x97c0c670 (208 bytes) */
int _IsBadUsage(operationChunk)
  int operationChunk;
{
  uint destWord;
  int sourceCount;
  uint *operandCursor;
  uint operandWord;
  uint badUsage;
  
  sourceCount = _GetValidArgs(operationChunk);
  badUsage = 0;
  if (0 < sourceCount) {
    operandCursor = (uint *)(operationChunk + 0x1c);
    do {
      operandWord = *operandCursor;
      operandCursor = operandCursor + 2;
      badUsage = badUsage | -(uint)(operandWord >> 0x15 & 3) >> 0x1f | operandWord >> 0x1b & 1 | operandWord >> 0x1f |
              operandWord >> 0xe & 1 | -(uint)(operandWord >> 0xc & 3) >> 0x1f;
      sourceCount = sourceCount + -1;
    } while (sourceCount != 0);
  }
  destWord = *(uint *)(operationChunk + 0x14);
  return badUsage | *(uint *)(operationChunk + 0x18) >> 0x1f | destWord >> 0xc & 1 |
         *(uint *)(operationChunk + 0x10) >> 0x14 & 1 | -(uint)(destWord & 0x1c000) >> 0x1f |
         -(uint)(destWord >> 10 & 3) >> 0x1f;
}

/* _ClearDestedOpRegisters @ 0x97c0c740 (220 bytes) */
int _ClearDestedOpRegisters(stream, hashSet, operationChunk, removeEntry)
  undefined4 stream;
  undefined4 hashSet;
  int operationChunk;
  int removeEntry;
{
  int knownRegister;
  uint destWord;
  int registerNumber;
  int lookupKeyRegister;
  uint lookupKeyBank;
  int firstIndex;
  int lastIndex [5];
  
  if ((*(uint *)(operationChunk + 0x14) & 0x1e000) != 0) {
    destWord = *(uint *)(operationChunk + 0x14);
    _GetRegisterIndicies
              (stream,&firstIndex,lastIndex,destWord >> 0x11 & 7,*(uint *)(operationChunk + 0x18) & 0xffff,
               *(uint *)(operationChunk + 0x18) >> 0x1f,destWord >> 0xc & 1,destWord >> 10 & 3);
    if (firstIndex <= lastIndex[0]) {
      registerNumber = firstIndex;
      do {
        lookupKeyBank = *(uint *)(operationChunk + 0x14) >> 0x11 & 7;
        lookupKeyRegister = registerNumber;
        knownRegister = _HashSetGet(hashSet,&lookupKeyRegister);
        if (knownRegister != 0) {
          if (removeEntry == 0) {
            *(undefined4 *)(knownRegister + 0x14) = 0;
          }
          else {
            _HashSetRemove(hashSet,knownRegister);
            _free(knownRegister);
          }
        }
        registerNumber = registerNumber + 1;
      } while (registerNumber <= lastIndex[0]);
    }
  }
  return;
}

/* _ClearDestedRegisters @ 0x97c0c81c (92 bytes) */
int _ClearDestedRegisters(stream, hashSet, firstOperation, endOperation)
  undefined4 stream;
  undefined4 hashSet;
  int firstOperation;
  int endOperation;
{
  for (; firstOperation != endOperation; firstOperation = *(int *)(firstOperation + 8)) {
    ((int (*)())_ClearDestedOpRegisters)(stream,hashSet,firstOperation,1);
  }
  return;
}

/* _ClearRegisterState @ 0x97c0c878 (100 bytes) */
int _ClearRegisterState(hashSet)
  undefined4 hashSet;
{
  int knownRegister;
  undefined1 setIterator [20];
  
  _HashSetIteratorSetup(hashSet,setIterator);
  knownRegister = _HashSetIteratorNext(setIterator);
  while (knownRegister != 0) {
    _HashSetRemove(hashSet,knownRegister);
    _free(knownRegister);
    knownRegister = _HashSetIteratorNext(setIterator);
  }
  return;
}

/* _EmulateOp @ 0x97c0c8dc (8892 bytes) */
int _EmulateOp(compileContext, inst, hashSet)
  int *compileContext;
  int inst;
  undefined4 hashSet;
{
  bool wCompareResult;
  float clampLoweredW;
  float clampLowered;
  float clampLowW;
  float clampResult;
  float clampInput;
  double logResult;
  undefined4 resultZBits;
  undefined4 resultYBits;
  int intComponent2;
  int componentIndex2;
  int remainingCount;
  int currentInst;
  int componentIndex;
  int intComponent;
  int remainingComponents;
  uint boolBit;
  float operandComponent;
  double powValue;
  double log2Value;
  double exp2Value;
  double sqrtValue;
  double mathAccumulator;
  float accumulator;
  float floatToInt;
  float scalarResult;
  float resultX;
  float resultW;
  float resultZ;
  float resultY;
  int isBadUsage;
  int chunk;
  double exp2Result2;
  double truncResult;
  double atanResult;
  double acosResult;
  double asinResult;
  double tanResult;
  double sinResult;
  double cosResult;
  double log2Result;
  double exp2Result;
  double sqrtResult;
  double floorResult;
  double ceilResult;
  double powResult;
  int loopIndex;
  int allocation;
  bool noDestination;
  bool resultKnown;
  float litYSave;
  float src0X;
  float src1Y;
  bool foldFailed;
  float component;
  undefined4 resultWBits;
  uint sizeMinusOne;
  float *srcComponentCursor;
  uint boolBitY;
  int validArgCount;
  int hashEntry;
  int nextComponent;
  float *src2;
  uint *instWords;
  int *operandKey;
  int destInfo;
  float *src1;
  uint *operandWordCursor;
  float *destValue;
  float *src0;
  double expResult;
  double magnitude;
  int operandIds [5];
  uint operandType;
  undefined4 intToFloatHigh;
  uint intToFloatLow;
  longlong intPairHi;
  longlong intPairLo;
  longlong convertScratchHigh;
  longlong convertScratchLow;
  float litYSaveSlot;
  
  operandIds[3] = 0;
  operandIds[0] = 0;
  operandIds[1] = 0;
  operandIds[2] = 0;
  loopIndex = 0;
  validArgCount = _GetValidArgs(inst);
  instWords = (uint *)(inst + 0xc);
  if (0 < validArgCount) {
    operandKey = operandIds + 4;
    operandWordCursor = instWords;
    do {
      operandIds[4] = (int)*(ushort *)((int)operandWordCursor + 0x16);
      operandType = operandWordCursor[4] >> 0x17 & 7;
      hashEntry = _HashSetGet(hashSet,operandKey);
      operandIds[loopIndex] = hashEntry;
      if (hashEntry == 0) {
        ((int (*)())_GetRegisterTypeInfo)(compileContext,operandKey);
        allocation = _malloc(0x28);
        operandIds[loopIndex] = allocation;
        _memcpy(allocation,operandKey,0x28);
        _HashSetAdd(hashSet,operandIds[loopIndex]);
      }
      loopIndex = loopIndex + 1;
      operandWordCursor = operandWordCursor + 2;
    } while (loopIndex < validArgCount);
  }
  destInfo = 0;
  noDestination = true;
  if ((*(uint *)(inst + 0x14) & 0x1e000) != 0) {
    operandIds[4] = (int)*(ushort *)(inst + 0x1a);
    operandKey = operandIds + 4;
    operandType = *(uint *)(inst + 0x14) >> 0x11 & 7;
    destInfo = _HashSetGet(hashSet,operandKey);
    noDestination = false;
    if (destInfo == 0) {
      ((int (*)())_GetRegisterTypeInfo)(compileContext,operandKey);
      destInfo = _malloc(0x28);
      _memcpy(destInfo,operandKey,0x28);
      _HashSetAdd(hashSet,destInfo);
      noDestination = destInfo == 0;
    }
  }
  if ((operandIds[0] == 0) ||
     (src0 = (float *)(operandIds[0] + 0x18), *(int *)(operandIds[0] + 0x14) == 0)) {
    src0 = (float *)0x0;
  }
  if ((operandIds[1] == 0) ||
     (src1 = (float *)(operandIds[1] + 0x18), *(int *)(operandIds[1] + 0x14) == 0)) {
    src1 = (float *)0x0;
  }
  if ((operandIds[2] == 0) ||
     (src2 = (float *)(operandIds[2] + 0x18), *(int *)(operandIds[2] + 0x14) == 0)) {
    src2 = (float *)0x0;
  }
  foldFailed = true;
  isBadUsage = ((int (*)())_IsBadUsage)(inst);
  destValue = (float *)(destInfo + 0x18);
  resultKnown = false;
  if (isBadUsage != 0) goto checkResultKnown;
  if (((validArgCount != 1) || (noDestination)) || (src0 == (float *)0x0)) goto loopCheckFoldFailed;
  foldFailed = false;
  switch(*instWords >> 0x12 & 0xff) {
  case 0:
    goto instWordsCase0;
  case 1:
    *destValue = 1.0;
    resultY = *src0;
    litYSave = resultY;
    if (resultY <= 0.0) {
      resultY = 0.0;
      litYSave = litYSaveSlot;
    }
    litYSaveSlot = litYSave;
    *(float *)(destInfo + 0x1c) = resultY;
    if (*src0 <= 0.0) {
      resultZ = 0.0;
    }
    else {
      powResult = _pow((double)src0[1],(double)src0[3]);
      resultZ = (float)powResult;
    }
    *(float *)(destInfo + 0x20) = resultZ;
loopSetResultWBits:
    resultWBits = 0x3f800000;
    goto loopStoreDestInfo;
  case 2:
    *destValue = ABS(*src0);
    *(float *)(destInfo + 0x1c) = ABS(src0[1]);
    *(float *)(destInfo + 0x20) = ABS(src0[2]);
    resultW = ABS(src0[3]);
    goto storeDestInfo7;
  case 3:
    ceilResult = _ceil((double)*src0);
    *destValue = (float)ceilResult;
    ceilResult = _ceil((double)src0[1]);
    *(float *)(destInfo + 0x1c) = (float)ceilResult;
    ceilResult = _ceil((double)src0[2]);
    *(float *)(destInfo + 0x20) = (float)ceilResult;
    mathAccumulator = _ceil((double)src0[3]);
    break;
  case 4:
    resultX = *src0;
    floorResult = _floor((double)resultX);
    *destValue = (float)((double)resultX - floorResult);
    resultY = src0[1];
    floorResult = _floor((double)resultY);
    *(float *)(destInfo + 0x1c) = (float)((double)resultY - floorResult);
    resultZ = src0[2];
    floorResult = _floor((double)resultZ);
    *(float *)(destInfo + 0x20) = (float)((double)resultZ - floorResult);
    resultW = src0[3];
    floorResult = _floor((double)resultW);
    *(float *)(destInfo + 0x24) = (float)((double)resultW - floorResult);
    goto loopCheckFoldFailed;
  case 5:
    floorResult = _floor((double)*src0);
    *destValue = (float)floorResult;
    floorResult = _floor((double)src0[1]);
    *(float *)(destInfo + 0x1c) = (float)floorResult;
    floorResult = _floor((double)src0[2]);
    *(float *)(destInfo + 0x20) = (float)floorResult;
    mathAccumulator = _floor((double)src0[3]);
    break;
  default:
    foldFailed = true;
    goto loopCheckFoldFailed;
  case 7:
    if (*src0 <= 0.0) {
      if (0.0 <= *src0) {
        resultX = 0.0;
      }
      else {
        resultX = -1.0;
      }
    }
    else {
      resultX = 1.0;
    }
    *destValue = resultX;
    if (src0[1] <= 0.0) {
      if (0.0 <= src0[1]) {
        resultYBits = 0;
      }
      else {
        resultYBits = 0xbf800000;
      }
    }
    else {
      resultYBits = 0x3f800000;
    }
    *(undefined4 *)(destInfo + 0x1c) = resultYBits;
    if (src0[2] <= 0.0) {
      if (0.0 <= src0[2]) {
        resultZBits = 0;
      }
      else {
        resultZBits = 0xbf800000;
      }
    }
    else {
      resultZBits = 0x3f800000;
    }
    *(undefined4 *)(destInfo + 0x20) = resultZBits;
    if (0.0 < src0[3]) goto loopSetResultWBits;
    if (0.0 <= src0[3]) goto loopSetResultWBits2;
    resultWBits = 0xbf800000;
    goto loopStoreDestInfo;
  case 8:
    if (((*src0 == 0.0) && (src0[1] == 0.0)) && (src0[2] == 0.0)) {
loopSetIntToFloatLow:
      intToFloatLow = 0;
      if (src0[3] == 0.0) goto setIntToFloatLow;
    }
    intToFloatLow = 1;
    goto setIntToFloatLow;
  case 9:
    intToFloatLow = 0;
    if (((*src0 != 0.0) && (src0[1] != 0.0)) && (src0[2] != 0.0)) goto loopSetIntToFloatLow;
setIntToFloatLow:
    intToFloatLow = intToFloatLow ^ 0x80000000;
    intToFloatHigh = 0x43300000;
    sqrtValue = (double)CONCAT44(0x43300000,intToFloatLow) - 4503601774854144.0;
loopSetScalarResult:
    scalarResult = (float)sqrtValue;
    goto storeDestInfo;
  case 10:
    resultX = 1.0;
    if (*src0 != 0.0) {
      resultX = 0.0;
    }
    *destValue = resultX;
    resultYBits = 0x3f800000;
    if (src0[1] != 0.0) {
      resultYBits = 0;
    }
    *(undefined4 *)(destInfo + 0x1c) = resultYBits;
    resultZBits = 0x3f800000;
    if (src0[2] != 0.0) {
      resultZBits = 0;
    }
    *(undefined4 *)(destInfo + 0x20) = resultZBits;
    resultWBits = 0x3f800000;
    if (src0[3] != 0.0) {
loopSetResultWBits2:
      resultWBits = 0;
    }
loopStoreDestInfo:
    *(undefined4 *)(destInfo + 0x24) = resultWBits;
    goto loopCheckFoldFailed;
  case 0xc:
    sqrtResult = _sqrt(ABS((double)*src0));
    *destValue = (float)sqrtResult;
    sqrtResult = _sqrt(ABS((double)src0[1]));
    *(float *)(destInfo + 0x1c) = (float)sqrtResult;
    sqrtResult = _sqrt(ABS((double)src0[2]));
    *(float *)(destInfo + 0x20) = (float)sqrtResult;
    mathAccumulator = _sqrt(ABS((double)src0[3]));
    break;
  case 0xd:
    if (*compileContext - 0x8b30U < 2) {
      sqrtResult = _sqrt(ABS((double)*src0));
      *destValue = (float)(1.0 / sqrtResult);
      sqrtResult = _sqrt(ABS((double)src0[1]));
      *(float *)(destInfo + 0x1c) = (float)(1.0 / sqrtResult);
      sqrtResult = _sqrt(ABS((double)src0[2]));
      *(float *)(destInfo + 0x20) = (float)(1.0 / sqrtResult);
      sqrtResult = _sqrt(ABS((double)src0[3]));
      *(float *)(destInfo + 0x24) = (float)(1.0 / sqrtResult);
      goto loopCheckFoldFailed;
    }
    sqrtResult = _sqrt(ABS((double)src0[3]));
    sqrtValue = 1.0 / sqrtResult;
    goto loopSetScalarResult;
  case 0xe:
    scalarResult = 1.0 / src0[3];
    goto storeDestInfo;
  case 0xf:
    operandComponent = src0[3];
    if (operandComponent <= 1.8446744e+19) {
      if (operandComponent < 5.421011e-20) {
        scalarResult = 1.8446744e+19;
        if (operandComponent < 0.0) {
          if (operandComponent <= -5.421011e-20) {
            scalarResult = -5.421011e-20;
            if (-1.8446744e+19 <= operandComponent) goto setScalarResult;
          }
          else {
            scalarResult = -1.8446744e+19;
          }
        }
      }
      else {
setScalarResult:
        scalarResult = 1.0 / operandComponent;
      }
    }
    else {
      scalarResult = 5.421011e-20;
    }
    goto storeDestInfo;
  case 0x10:
    if (1 < *compileContext - 0x8b30U) {
      mathAccumulator = _exp2((double)src0[3]);
      goto loopSetScalarResult2;
    }
    exp2Result = _exp2((double)*src0);
    *destValue = (float)exp2Result;
    exp2Result = _exp2((double)src0[1]);
    *(float *)(destInfo + 0x1c) = (float)exp2Result;
    exp2Result = _exp2((double)src0[2]);
    *(float *)(destInfo + 0x20) = (float)exp2Result;
    mathAccumulator = _exp2((double)src0[3]);
    break;
  case 0x11:
    floorResult = _floor((double)src0[3]);
    exp2Result2 = _exp2((double)(float)floorResult);
    *destValue = (float)exp2Result2;
    *(float *)(destInfo + 0x1c) = (float)((double)src0[3] - (double)(float)floorResult);
    exp2Value = _exp2((double)src0[3]);
    goto storeDestInfo2;
  case 0x12:
    mathAccumulator = 0.0;
    sizeMinusOne = *(uint *)(inst + 0x10) >> 0x1a & 3;
    if (sizeMinusOne != 0xffffffff) {
      remainingCount = sizeMinusOne + 1;
      srcComponentCursor = src0;
      do {
        component = *srcComponentCursor;
        srcComponentCursor = srcComponentCursor + 1;
        mathAccumulator = (double)(float)((double)component * (double)component + mathAccumulator);
        remainingCount = remainingCount + -1;
      } while (remainingCount != 0);
    }
    mathAccumulator = _sqrt(mathAccumulator);
loopSetScalarResult2:
    scalarResult = (float)mathAccumulator;
storeDestInfo:
    *(float *)(destInfo + 0x24) = scalarResult;
    *destValue = scalarResult;
    *(float *)(destInfo + 0x1c) = scalarResult;
    *(float *)(destInfo + 0x20) = scalarResult;
    goto loopCheckFoldFailed;
  case 0x13:
    if (1 < *compileContext - 0x8b30U) {
      mathAccumulator = (double)src0[3];
      if (mathAccumulator < 0.0) {
        mathAccumulator = 0.0;
      }
      mathAccumulator = _log2(mathAccumulator);
      goto loopSetScalarResult2;
    }
    log2Value = (double)*src0;
    if (log2Value < 0.0) {
      log2Value = 0.0;
    }
    log2Result = _log2(log2Value);
    *destValue = (float)log2Result;
    log2Value = (double)src0[1];
    if (log2Value < 0.0) {
      log2Value = 0.0;
    }
    log2Result = _log2(log2Value);
    *(float *)(destInfo + 0x1c) = (float)log2Result;
    log2Value = (double)src0[2];
    if (log2Value < 0.0) {
      log2Value = 0.0;
    }
    log2Result = _log2(log2Value);
    *(float *)(destInfo + 0x20) = (float)log2Result;
    mathAccumulator = (double)src0[3];
    if (mathAccumulator < 0.0) {
      mathAccumulator = 0.0;
    }
    mathAccumulator = _log2(mathAccumulator);
    break;
  case 0x14:
    magnitude = ABS((double)src0[3]);
    log2Result = _log2(magnitude);
    floorResult = _floor(log2Result);
    *destValue = (float)floorResult;
    exp2Result = _exp2((double)(float)floorResult);
    *(float *)(destInfo + 0x1c) = (float)(magnitude / exp2Result);
    if (magnitude < 0.0) {
      magnitude = 0.0;
    }
    exp2Value = _log2(magnitude);
storeDestInfo2:
    *(undefined4 *)(destInfo + 0x24) = 0x3f800000;
    *(float *)(destInfo + 0x20) = (float)exp2Value;
    goto loopCheckFoldFailed;
  case 0x15:
    sqrtValue = 0.0;
    sizeMinusOne = *(uint *)(inst + 0x10) >> 0x1a & 3;
    if (sizeMinusOne != 0xffffffff) {
      remainingCount = sizeMinusOne + 1;
      srcComponentCursor = src0;
      do {
        component = *srcComponentCursor;
        srcComponentCursor = srcComponentCursor + 1;
        sqrtValue = (double)(float)((double)component * (double)component + sqrtValue);
        remainingCount = remainingCount + -1;
      } while (remainingCount != 0);
    }
    sqrtResult = _sqrt(sqrtValue);
    componentIndex2 = 0;
    if ((*(uint *)(inst + 0x10) >> 0x1a & 3) != 0xffffffff) {
      do {
        nextComponent = componentIndex2 + 1;
        destValue[componentIndex2] = src0[componentIndex2] / (float)sqrtResult;
        componentIndex2 = nextComponent;
      } while (nextComponent < (int)((*(uint *)(inst + 0x10) >> 0x1a & 3) + 1));
    }
    goto loopCheckFoldFailed;
  case 0x16:
    scalarResult = 0.017453292;
    goto storeDestValue;
  case 0x17:
    scalarResult = 57.29578;
storeDestValue:
    *destValue = *src0 * scalarResult;
    *(float *)(destInfo + 0x1c) = src0[1] * scalarResult;
    *(float *)(destInfo + 0x20) = src0[2] * scalarResult;
    *(float *)(destInfo + 0x24) = src0[3] * scalarResult;
    goto loopCheckFoldFailed;
  case 0x18:
    cosResult = _cos((double)*src0);
    *destValue = (float)cosResult;
    sinResult = _sin((double)*src0);
    *(undefined4 *)(destInfo + 0x24) = 0;
    *(undefined4 *)(destInfo + 0x20) = 0;
    *(float *)(destInfo + 0x1c) = (float)sinResult;
    goto loopCheckFoldFailed;
  case 0x19:
    if (1 < *compileContext - 0x8b30U) {
      mathAccumulator = _sin((double)src0[3]);
      goto loopSetScalarResult2;
    }
    sinResult = _sin((double)*src0);
    *destValue = (float)sinResult;
    sinResult = _sin((double)src0[1]);
    *(float *)(destInfo + 0x1c) = (float)sinResult;
    sinResult = _sin((double)src0[2]);
    *(float *)(destInfo + 0x20) = (float)sinResult;
    mathAccumulator = _sin((double)src0[3]);
    break;
  case 0x1a:
    if (1 < *compileContext - 0x8b30U) {
      mathAccumulator = _cos((double)src0[3]);
      goto loopSetScalarResult2;
    }
    cosResult = _cos((double)*src0);
    *destValue = (float)cosResult;
    cosResult = _cos((double)src0[1]);
    *(float *)(destInfo + 0x1c) = (float)cosResult;
    cosResult = _cos((double)src0[2]);
    *(float *)(destInfo + 0x20) = (float)cosResult;
    mathAccumulator = _cos((double)src0[3]);
    break;
  case 0x1b:
    tanResult = _tan((double)*src0);
    *destValue = (float)tanResult;
    tanResult = _tan((double)src0[1]);
    *(float *)(destInfo + 0x1c) = (float)tanResult;
    tanResult = _tan((double)src0[2]);
    *(float *)(destInfo + 0x20) = (float)tanResult;
    mathAccumulator = _tan((double)src0[3]);
    break;
  case 0x1c:
    asinResult = _asin((double)*src0);
    *destValue = (float)asinResult;
    asinResult = _asin((double)src0[1]);
    *(float *)(destInfo + 0x1c) = (float)asinResult;
    asinResult = _asin((double)src0[2]);
    *(float *)(destInfo + 0x20) = (float)asinResult;
    mathAccumulator = _asin((double)src0[3]);
    break;
  case 0x1d:
    acosResult = _acos((double)*src0);
    *destValue = (float)acosResult;
    acosResult = _acos((double)src0[1]);
    *(float *)(destInfo + 0x1c) = (float)acosResult;
    acosResult = _acos((double)src0[2]);
    *(float *)(destInfo + 0x20) = (float)acosResult;
    mathAccumulator = _acos((double)src0[3]);
    break;
  case 0x1e:
    atanResult = _atan((double)*src0);
    *destValue = (float)atanResult;
    atanResult = _atan((double)src0[1]);
    *(float *)(destInfo + 0x1c) = (float)atanResult;
    atanResult = _atan((double)src0[2]);
    *(float *)(destInfo + 0x20) = (float)atanResult;
    mathAccumulator = _atan((double)src0[3]);
    break;
  case 0x48:
    *destValue = *src0;
    *(float *)(destInfo + 0x1c) = *src0;
    *(float *)(destInfo + 0x20) = *src0;
    resultW = *src0;
    goto storeDestInfo7;
  case 0x6c:
    if ((*(int *)(destInfo + 0xc) == 3) && (*(int *)(operandIds[0] + 0xc) == 1)) {
      truncResult = _trunc((double)*src0);
      *destValue = (float)truncResult;
      truncResult = _trunc((double)src0[1]);
      *(float *)(destInfo + 0x1c) = (float)truncResult;
      truncResult = _trunc((double)src0[2]);
      *(float *)(destInfo + 0x20) = (float)truncResult;
      mathAccumulator = _trunc((double)src0[3]);
      break;
    }
    if ((*(int *)(destInfo + 0xc) == 4) &&
       ((*(int *)(operandIds[0] + 0xc) == 1 || (*(int *)(operandIds[0] + 0xc) == 3)))) {
      resultX = 1.0;
      if (*src0 == 0.0) {
        resultX = 0.0;
      }
      *destValue = resultX;
      resultYBits = 0x3f800000;
      if (src0[1] == 0.0) {
        resultYBits = 0;
      }
      *(undefined4 *)(destInfo + 0x1c) = resultYBits;
      resultZBits = 0x3f800000;
      if (src0[2] == 0.0) {
        resultZBits = 0;
      }
      *(undefined4 *)(destInfo + 0x20) = resultZBits;
      resultWBits = 0x3f800000;
      if (src0[3] == 0.0) goto loopSetResultWBits2;
      goto loopStoreDestInfo;
    }
    goto instWordsCase0;
  case 0x6f:
    expResult = _exp((double)*src0);
    *destValue = (float)expResult;
    expResult = _exp((double)src0[1]);
    *(float *)(destInfo + 0x1c) = (float)expResult;
    expResult = _exp((double)src0[2]);
    *(float *)(destInfo + 0x20) = (float)expResult;
    mathAccumulator = _exp((double)src0[3]);
    break;
  case 0x70:
    logResult = _log((double)*src0);
    *destValue = (float)logResult;
    logResult = _log((double)src0[1]);
    *(float *)(destInfo + 0x1c) = (float)logResult;
    logResult = _log((double)src0[2]);
    *(float *)(destInfo + 0x20) = (float)logResult;
    mathAccumulator = _log((double)src0[3]);
  }
  *(float *)(destInfo + 0x24) = (float)mathAccumulator;
loopCheckFoldFailed:
  if (!foldFailed) goto checkNoDestination;
  foldFailed = false;
  if (((validArgCount != 2) || (noDestination)) || ((src0 == (float *)0x0 || (src1 == (float *)0x0))))
  goto checkFoldFailed;
  foldFailed = false;
  switch(*instWords >> 0x12 & 0xff) {
  case 0x1e:
    resultX = _atan2f(*src0,*src1);
    *destValue = resultX;
    resultY = _atan2f(src0[1],src1[1]);
    *(float *)(destInfo + 0x1c) = resultY;
    resultZ = _atan2f(src0[2],src1[2]);
    *(float *)(destInfo + 0x20) = resultZ;
    resultW = _atan2f(src0[3],src1[3]);
    *(float *)(destInfo + 0x24) = resultW;
    goto setFoldFailed;
  case 0x1f:
    *destValue = *src0 + *src1;
    *(float *)(destInfo + 0x1c) = src0[1] + src1[1];
    *(float *)(destInfo + 0x20) = src0[2] + src1[2];
    resultW = src0[3] + src1[3];
    goto loopSetFoldFailed3;
  case 0x20:
    *destValue = *src0 - *src1;
    *(float *)(destInfo + 0x1c) = src0[1] - src1[1];
    *(float *)(destInfo + 0x20) = src0[2] - src1[2];
    resultW = src0[3] - src1[3];
    goto loopSetFoldFailed3;
  default:
    foldFailed = true;
    goto setFoldFailed;
  case 0x22:
  case 0x23:
    *destValue = *src0 * *src1;
    *(float *)(destInfo + 0x1c) = src0[1] * src1[1];
    *(float *)(destInfo + 0x20) = src0[2] * src1[2];
    resultW = src0[3] * src1[3];
    goto loopSetFoldFailed3;
  case 0x24:
    boolBit = 0;
    if ((*src0 != 0.0) && (*src1 != 0.0)) {
      boolBit = 1;
    }
    boolBitY = 0;
    *destValue = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0);
    if ((src0[1] != 0.0) && (src1[1] != 0.0)) {
      boolBitY = 1;
    }
    boolBit = 0;
    *(float *)(destInfo + 0x1c) =
         (float)((double)CONCAT44(0x43300000,boolBitY ^ 0x80000000) - 4503601774854144.0);
    if ((src0[2] != 0.0) && (src1[2] != 0.0)) {
      boolBit = 1;
    }
    intToFloatLow = 0;
    *(float *)(destInfo + 0x20) =
         (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0);
    if (src0[3] != 0.0) {
loopSetIntToFloatLow2:
      intToFloatLow = 0;
      if (src1[3] != 0.0) goto loopSetIntToFloatLow3;
    }
    goto setIntToFloatLow2;
  case 0x25:
    boolBit = 0;
    if ((*src0 != 0.0) || (*src1 != 0.0)) {
      boolBit = 1;
    }
    boolBitY = 0;
    *destValue = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0);
    if ((src0[1] != 0.0) || (src1[1] != 0.0)) {
      boolBitY = 1;
    }
    boolBit = 0;
    *(float *)(destInfo + 0x1c) =
         (float)((double)CONCAT44(0x43300000,boolBitY ^ 0x80000000) - 4503601774854144.0);
    if ((src0[2] != 0.0) || (src1[2] != 0.0)) {
      boolBit = 1;
    }
    *(float *)(destInfo + 0x20) =
         (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0);
    if (src0[3] == 0.0) goto loopSetIntToFloatLow2;
loopSetIntToFloatLow3:
    intToFloatLow = 1;
    goto setIntToFloatLow2;
  case 0x26:
    boolBit = 0;
    if (*src0 == 0.0) {
      if (*src1 != 0.0) {
loopSetBoolBit:
        boolBit = 1;
      }
    }
    else if (*src1 == 0.0) goto loopSetBoolBit;
    boolBitY = 0;
    *destValue = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0);
    if (src0[1] == 0.0) {
      if (src1[1] != 0.0) {
loopSetBoolBitY:
        boolBitY = 1;
      }
    }
    else if (src1[1] == 0.0) goto loopSetBoolBitY;
    boolBit = 0;
    *(float *)(destInfo + 0x1c) =
         (float)((double)CONCAT44(0x43300000,boolBitY ^ 0x80000000) - 4503601774854144.0);
    if (src0[2] == 0.0) {
      if (src1[2] != 0.0) {
loopSetBoolBit2:
        boolBit = 1;
      }
    }
    else if (src1[2] == 0.0) goto loopSetBoolBit2;
    intToFloatLow = 0;
    *(float *)(destInfo + 0x20) =
         (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0);
    if (src0[3] == 0.0) goto loopSetIntToFloatLow2;
    if (src1[3] == 0.0) goto loopSetIntToFloatLow3;
setIntToFloatLow2:
    intToFloatLow = intToFloatLow ^ 0x80000000;
    intToFloatHigh = 0x43300000;
    resultW = (float)((double)CONCAT44(0x43300000,intToFloatLow) - 4503601774854144.0);
    goto loopSetFoldFailed3;
  case 0x27:
    scalarResult = 0.0;
    componentIndex2 = 0;
    for (remainingComponents = (*(uint *)(inst + 0x10) >> 0x1a & 3) + 1; remainingComponents != 0; remainingComponents = remainingComponents + -1) {
      scalarResult = src0[componentIndex2] * src1[componentIndex2] + scalarResult;
      componentIndex2 = componentIndex2 + 1;
    }
    goto storeDestInfo5;
  case 0x28:
    scalarResult = src0[2] * src1[2] + *src0 * *src1 + src0[1] * src1[1];
    goto loopSetFoldFailed;
  case 0x29:
    scalarResult = src0[3] * src1[3] +
            src0[2] * src1[2] + *src0 * *src1 + src0[1] * src1[1];
    goto loopSetFoldFailed;
  case 0x2a:
    scalarResult = src0[2] * src1[2] + *src0 * *src1 + src0[1] * src1[1] + src1[3];
loopSetFoldFailed:
    foldFailed = true;
    *(float *)(destInfo + 0x24) = scalarResult;
    *destValue = scalarResult;
    *(float *)(destInfo + 0x1c) = scalarResult;
    *(float *)(destInfo + 0x20) = scalarResult;
    break;
  case 0x2b:
    if (*compileContext - 0x8b30U < 2) {
      mathAccumulator = 0.0;
      componentIndex2 = 0;
      for (remainingComponents = (*(uint *)(inst + 0x10) >> 0x1a & 3) + 1; remainingComponents != 0; remainingComponents = remainingComponents + -1)
      {
        mathAccumulator = (double)(float)((double)(src0[componentIndex2] - src1[componentIndex2]) *
                                 (double)(src0[componentIndex2] - src1[componentIndex2]) + mathAccumulator);
        componentIndex2 = componentIndex2 + 1;
      }
      mathAccumulator = _sqrt(mathAccumulator);
loopSetScalarResult3:
      scalarResult = (float)mathAccumulator;
      goto loopSetFoldFailed;
    }
    *destValue = 1.0;
    *(float *)(destInfo + 0x1c) = src0[1] * src1[1];
    *(float *)(destInfo + 0x20) = src0[2];
    resultW = src1[3];
    goto loopSetFoldFailed3;
  case 0x2c:
    resultX = *src1;
    if (*src0 < *src1) {
      resultX = *src0;
    }
    *destValue = resultX;
    resultY = src1[1];
    if (src0[1] < src1[1]) {
      resultY = src0[1];
    }
    *(float *)(destInfo + 0x1c) = resultY;
    resultZ = src1[2];
    if (src0[2] < src1[2]) {
      resultZ = src0[2];
    }
    *(float *)(destInfo + 0x20) = resultZ;
    operandComponent = src0[3];
    resultW = src1[3];
    if (operandComponent < resultW) {
loopSetResultW:
      resultW = operandComponent;
    }
    goto storeDestInfo3;
  case 0x2d:
    resultX = *src1;
    if (*src1 < *src0) {
      resultX = *src0;
    }
    *destValue = resultX;
    resultY = src1[1];
    if (src1[1] < src0[1]) {
      resultY = src0[1];
    }
    *(float *)(destInfo + 0x1c) = resultY;
    resultZ = src1[2];
    if (src1[2] < src0[2]) {
      resultZ = src0[2];
    }
    *(float *)(destInfo + 0x20) = resultZ;
    operandComponent = src0[3];
    resultW = src1[3];
    if (src1[3] < operandComponent) goto loopSetResultW;
storeDestInfo3:
    *(float *)(destInfo + 0x24) = resultW;
    goto setFoldFailed;
  case 0x2e:
    foldFailed = true;
    *destValue = src0[1] * src1[2] - src1[1] * src0[2];
    *(float *)(destInfo + 0x1c) = src0[2] * *src1 - src1[2] * *src0;
    resultZ = *src1;
    operandComponent = src0[1];
    src0X = *src0;
    src1Y = src1[1];
    *(undefined4 *)(destInfo + 0x24) = 0;
    *(float *)(destInfo + 0x20) = src0X * src1Y - resultZ * operandComponent;
    break;
  case 0x2f:
    scalarResult = 0.0;
    componentIndex2 = 0;
    for (remainingComponents = (*(uint *)(inst + 0x10) >> 0x1a & 3) + 1; remainingComponents != 0; remainingComponents = remainingComponents + -1) {
      scalarResult = src0[componentIndex2] * src1[componentIndex2] + scalarResult;
      componentIndex2 = componentIndex2 + 1;
    }
    scalarResult = scalarResult + scalarResult;
    foldFailed = true;
    *destValue = -(scalarResult * *src1 - *src0);
    *(float *)(destInfo + 0x1c) = -(scalarResult * src1[1] - src0[1]);
    *(float *)(destInfo + 0x20) = -(scalarResult * src1[2] - src0[2]);
    *(float *)(destInfo + 0x24) = -(scalarResult * src1[3] - src0[3]);
    break;
  case 0x30:
    scalarResult = 1.0;
    goto storeDestInfo5;
  case 0x31:
    resultX = 1.0;
    if (*src0 != *src1) {
      resultX = 0.0;
    }
    *destValue = resultX;
    resultYBits = 0x3f800000;
    if (src0[1] != src1[1]) {
      resultYBits = 0;
    }
    *(undefined4 *)(destInfo + 0x1c) = resultYBits;
    resultZBits = 0x3f800000;
    if (src0[2] != src1[2]) {
      resultZBits = 0;
    }
    *(undefined4 *)(destInfo + 0x20) = resultZBits;
    resultWBits = 0x3f800000;
    if (src0[3] != src1[3]) goto setResultWBits2;
    goto storeDestInfo4;
  case 0x32:
    resultX = 1.0;
    if (*src0 < *src1) {
      resultX = 0.0;
    }
    *destValue = resultX;
    resultYBits = 0x3f800000;
    if (src0[1] < src1[1]) {
      resultYBits = 0;
    }
    *(undefined4 *)(destInfo + 0x1c) = resultYBits;
    resultZBits = 0x3f800000;
    if (src0[2] < src1[2]) {
      resultZBits = 0;
    }
    *(undefined4 *)(destInfo + 0x20) = resultZBits;
    wCompareResult = src1[3] <= src0[3];
    goto setResultWBits;
  case 0x33:
    if (*src0 <= *src1) {
      resultX = 0.0;
    }
    else {
      resultX = 1.0;
    }
    *destValue = resultX;
    if (src0[1] <= src1[1]) {
      resultYBits = 0;
    }
    else {
      resultYBits = 0x3f800000;
    }
    *(undefined4 *)(destInfo + 0x1c) = resultYBits;
    if (src0[2] <= src1[2]) {
      resultZBits = 0;
    }
    else {
      resultZBits = 0x3f800000;
    }
    *(undefined4 *)(destInfo + 0x20) = resultZBits;
    if (src1[3] < src0[3]) {
loopSetResultWBits3:
      resultWBits = 0x3f800000;
      goto storeDestInfo4;
    }
    goto setResultWBits2;
  case 0x34:
    resultX = 1.0;
    if (*src1 < *src0) {
      resultX = 0.0;
    }
    *destValue = resultX;
    resultYBits = 0x3f800000;
    if (src1[1] < src0[1]) {
      resultYBits = 0;
    }
    *(undefined4 *)(destInfo + 0x1c) = resultYBits;
    resultZBits = 0x3f800000;
    if (src1[2] < src0[2]) {
      resultZBits = 0;
    }
    *(undefined4 *)(destInfo + 0x20) = resultZBits;
    wCompareResult = src0[3] <= src1[3];
setResultWBits:
    resultWBits = 0x3f800000;
    if (!wCompareResult) goto setResultWBits2;
    goto storeDestInfo4;
  case 0x35:
    if (*src1 <= *src0) {
      resultX = 0.0;
    }
    else {
      resultX = 1.0;
    }
    *destValue = resultX;
    if (src1[1] <= src0[1]) {
      resultYBits = 0;
    }
    else {
      resultYBits = 0x3f800000;
    }
    *(undefined4 *)(destInfo + 0x1c) = resultYBits;
    if (src1[2] <= src0[2]) {
      resultZBits = 0;
    }
    else {
      resultZBits = 0x3f800000;
    }
    *(undefined4 *)(destInfo + 0x20) = resultZBits;
    if (src0[3] < src1[3]) goto loopSetResultWBits3;
    goto setResultWBits2;
  case 0x36:
    resultX = 1.0;
    if (*src0 == *src1) {
      resultX = 0.0;
    }
    *destValue = resultX;
    resultYBits = 0x3f800000;
    if (src0[1] == src1[1]) {
      resultYBits = 0;
    }
    *(undefined4 *)(destInfo + 0x1c) = resultYBits;
    resultZBits = 0x3f800000;
    if (src0[2] == src1[2]) {
      resultZBits = 0;
    }
    *(undefined4 *)(destInfo + 0x20) = resultZBits;
    resultWBits = 0x3f800000;
    if (src0[3] != src1[3]) goto storeDestInfo4;
setResultWBits2:
    resultWBits = 0;
storeDestInfo4:
    *(undefined4 *)(destInfo + 0x24) = resultWBits;
    goto setFoldFailed;
  case 0x37:
    scalarResult = 0.0;
storeDestInfo5:
    *(float *)(destInfo + 0x24) = scalarResult;
    *destValue = scalarResult;
    *(float *)(destInfo + 0x1c) = scalarResult;
    *(float *)(destInfo + 0x20) = scalarResult;
setFoldFailed:
    foldFailed = !foldFailed;
    break;
  case 0x38:
    if (1 < *compileContext - 0x8b30U) {
      mathAccumulator = _pow((double)src0[3],(double)src1[3]);
      goto loopSetScalarResult3;
    }
    powResult = _pow((double)*src0,(double)*src1);
    *destValue = (float)powResult;
    powResult = _pow((double)src0[1],(double)src1[1]);
    *(float *)(destInfo + 0x1c) = (float)powResult;
    powResult = _pow((double)src0[2],(double)src1[2]);
    *(float *)(destInfo + 0x20) = (float)powResult;
    powValue = _pow((double)src0[3],(double)src1[3]);
loopSetFoldFailed2:
    foldFailed = true;
    *(float *)(destInfo + 0x24) = (float)powValue;
    break;
  case 0x39:
    floatToInt = *src1;
    if (2.1474836e+09 <= floatToInt) {
      intComponent2 = (int)(floatToInt - 2.1474836e+09);
      intPairLo = (longlong)intComponent2;
    }
    else {
      intComponent2 = (int)floatToInt;
      intPairHi = (longlong)intComponent2;
    }
    *destValue = src0[intComponent2];
    floatToInt = *src1;
    if (2.1474836e+09 <= floatToInt) {
      intComponent2 = (int)(floatToInt - 2.1474836e+09);
      intPairHi = (longlong)intComponent2;
    }
    else {
      intComponent2 = (int)floatToInt;
      intPairLo = (longlong)intComponent2;
    }
    *(float *)(destInfo + 0x1c) = src0[intComponent2];
    floatToInt = *src1;
    if (2.1474836e+09 <= floatToInt) {
      intComponent2 = (int)(floatToInt - 2.1474836e+09);
      intPairHi = (longlong)intComponent2;
    }
    else {
      intComponent2 = (int)floatToInt;
      intPairLo = (longlong)intComponent2;
    }
    *(float *)(destInfo + 0x20) = src0[intComponent2];
    floatToInt = *src1;
    if (2.1474836e+09 <= floatToInt) {
      intComponent2 = (int)(floatToInt - 2.1474836e+09);
      intPairHi = (longlong)intComponent2;
    }
    else {
      intComponent2 = (int)floatToInt;
      intPairLo = (longlong)intComponent2;
    }
    resultW = src0[intComponent2];
loopSetFoldFailed3:
    foldFailed = true;
    *(float *)(destInfo + 0x24) = resultW;
    break;
  case 0x3a:
    if (*(int *)(destInfo + 0xc) == 1) {
      *destValue = *src0 / *src1;
      *(float *)(destInfo + 0x1c) = src0[1] / src1[1];
      *(float *)(destInfo + 0x20) = src0[2] / src1[2];
      resultW = src0[3] / src1[3];
      goto loopSetFoldFailed3;
    }
    foldFailed = true;
    if (*(int *)(destInfo + 0xc) == 3) {
      truncResult = _trunc((double)(*src0 / *src1));
      *destValue = (float)truncResult;
      truncResult = _trunc((double)(src0[1] / src1[1]));
      *(float *)(destInfo + 0x1c) = (float)truncResult;
      truncResult = _trunc((double)(src0[2] / src1[2]));
      *(float *)(destInfo + 0x20) = (float)truncResult;
      powValue = _trunc((double)(src0[3] / src1[3]));
      goto loopSetFoldFailed2;
    }
    break;
  case 0x6d:
    floatToInt = *src1;
    if (2.1474836e+09 <= floatToInt) {
      intComponent2 = (int)(floatToInt - 2.1474836e+09);
      intPairHi = (longlong)intComponent2;
    }
    else {
      intComponent2 = (int)floatToInt;
      intPairLo = (longlong)intComponent2;
    }
    floatToInt = *src1;
    if (2.1474836e+09 <= floatToInt) {
      intComponent = (int)(floatToInt - 2.1474836e+09);
      convertScratchLow = (longlong)intComponent;
    }
    else {
      intComponent = (int)floatToInt;
      convertScratchHigh = (longlong)intComponent;
    }
    foldFailed = true;
    destValue[intComponent2] = src0[intComponent];
  }
checkFoldFailed:
  if (foldFailed) goto checkNoDestination;
  resultKnown = false;
  if ((((validArgCount != 3) || (noDestination)) || (src0 == (float *)0x0)) ||
     ((src1 == (float *)0x0 || (src2 == (float *)0x0)))) goto checkResultKnown;
  resultKnown = false;
  switch(*instWords >> 0x12 & 0xff) {
  case 0x3b:
    accumulator = 0.0;
    componentIndex = 0;
    for (componentIndex2 = (*(uint *)(inst + 0x10) >> 0x1a & 3) + 1; componentIndex2 != 0; componentIndex2 = componentIndex2 + -1) {
      accumulator = src2[componentIndex] * src1[componentIndex] + accumulator;
      componentIndex = componentIndex + 1;
    }
    if (0.0 <= accumulator) {
      *destValue = -*src0;
      *(float *)(destInfo + 0x1c) = -src0[1];
      *(float *)(destInfo + 0x20) = -src0[2];
      resultW = -src0[3];
    }
    else {
      *destValue = *src0;
      *(float *)(destInfo + 0x1c) = src0[1];
      *(float *)(destInfo + 0x20) = src0[2];
      resultW = src0[3];
    }
    break;
  case 0x3c:
    *destValue = *src0 * *src1 + (1.0 - *src0) * *src2;
    *(float *)(destInfo + 0x1c) = src0[1] * src1[1] + (1.0 - src0[1]) * src2[1];
    *(float *)(destInfo + 0x20) = src0[2] * src1[2] + (1.0 - src0[2]) * src2[2];
    resultW = src0[3] * src1[3] + (1.0 - src0[3]) * src2[3];
    break;
  case 0x3d:
    clampInput = *src0;
    operandComponent = *src1;
    clampResult = *src2;
    clampLowered = operandComponent;
    if (operandComponent < clampInput) {
      clampLowered = clampInput;
    }
    if ((clampLowered < clampResult) && (clampResult = operandComponent, operandComponent < clampInput)) {
      clampResult = clampInput;
    }
    *destValue = clampResult;
    clampInput = src0[1];
    operandComponent = src1[1];
    clampResult = src2[1];
    clampLowered = operandComponent;
    if (operandComponent < clampInput) {
      clampLowered = clampInput;
    }
    if ((clampLowered < clampResult) && (clampResult = operandComponent, operandComponent < clampInput)) {
      clampResult = clampInput;
    }
    *(float *)(destInfo + 0x1c) = clampResult;
    clampInput = src0[2];
    operandComponent = src1[2];
    clampResult = src2[2];
    clampLowered = operandComponent;
    if (operandComponent < clampInput) {
      clampLowered = clampInput;
    }
    if ((clampLowered < clampResult) && (clampResult = operandComponent, operandComponent < clampInput)) {
      clampResult = clampInput;
    }
    *(float *)(destInfo + 0x20) = clampResult;
    operandComponent = src0[3];
    clampLowW = src1[3];
    resultW = src2[3];
    clampLoweredW = clampLowW;
    if (clampLowW < operandComponent) {
      clampLoweredW = operandComponent;
    }
    if ((clampLoweredW < resultW) && (resultW = clampLowW, clampLowW < operandComponent)) {
      resultW = operandComponent;
    }
    goto storeDestInfo6;
  case 0x3e:
    if (0.0 <= *src0) {
      resultX = *src2;
    }
    else {
      resultX = *src1;
    }
    *destValue = resultX;
    if (0.0 <= src0[1]) {
      resultY = src2[1];
    }
    else {
      resultY = src1[1];
    }
    *(float *)(destInfo + 0x1c) = resultY;
    if (0.0 <= src0[2]) {
      resultZ = src2[2];
    }
    else {
      resultZ = src1[2];
    }
    *(float *)(destInfo + 0x20) = resultZ;
    if (0.0 <= src0[3]) {
      resultW = src2[3];
    }
    else {
      resultW = src1[3];
    }
storeDestInfo6:
    *(float *)(destInfo + 0x24) = resultW;
    goto setResultKnown;
  case 0x3f:
    *destValue = *src0 * *src1 + *src2;
    *(float *)(destInfo + 0x1c) = src0[1] * src1[1] + src2[1];
    *(float *)(destInfo + 0x20) = src0[2] * src1[2] + src2[2];
    resultW = src0[3] * src1[3] + src2[3];
    break;
  case 0x40:
    resultX = (*src2 - *src0) / (*src1 - *src0);
    if ((resultX <= 0.0) || (resultX < 1.0)) {
      if (resultX <= 0.0) {
        resultX = 0.0;
      }
    }
    else {
      resultX = 1.0;
    }
    *destValue = resultX * resultX * (3.0 - (resultX + resultX));
    resultY = (src2[1] - src0[1]) / (src1[1] - src0[1]);
    if ((resultY <= 0.0) || (resultY < 1.0)) {
      if (resultY <= 0.0) {
        resultY = 0.0;
      }
    }
    else {
      resultY = 1.0;
    }
    *(float *)(destInfo + 0x1c) = resultY * resultY * (3.0 - (resultY + resultY));
    resultZ = (src2[2] - src0[2]) / (src1[2] - src0[2]);
    if ((resultZ <= 0.0) || (resultZ < 1.0)) {
      if (resultZ <= 0.0) {
        resultZ = 0.0;
      }
    }
    else {
      resultZ = 1.0;
    }
    *(float *)(destInfo + 0x20) = resultZ * resultZ * (3.0 - (resultZ + resultZ));
    scalarResult = (src2[3] - src0[3]) / (src1[3] - src0[3]);
    if ((scalarResult <= 0.0) || (scalarResult < 1.0)) {
      if (scalarResult <= 0.0) {
        scalarResult = 0.0;
      }
    }
    else {
      scalarResult = 1.0;
    }
    scalarResult = scalarResult * scalarResult * (3.0 - (scalarResult + scalarResult));
loopSetResultKnown:
    resultKnown = true;
    *(float *)(destInfo + 0x24) = scalarResult;
    goto checkResultKnown;
  default:
    resultKnown = true;
    goto setResultKnown;
  case 0x68:
    scalarResult = 0.0;
    componentIndex = 0;
    for (componentIndex2 = (*(uint *)(inst + 0x10) >> 0x1a & 3) + 1; componentIndex2 != 0; componentIndex2 = componentIndex2 + -1) {
      scalarResult = src0[componentIndex] * src1[componentIndex] + scalarResult;
      componentIndex = componentIndex + 1;
    }
    operandComponent = *src2;
    sqrtValue = (double)-(operandComponent * operandComponent * (1.0 - scalarResult * scalarResult) - 1.0);
    if (0.0 <= sqrtValue) {
      sqrtResult = _sqrt(sqrtValue);
      scalarResult = (float)((double)(operandComponent * scalarResult) + sqrtResult);
      *destValue = *src2 * *src0 - scalarResult * *src1;
      *(float *)(destInfo + 0x1c) = *src2 * src0[1] - scalarResult * src1[1];
      *(float *)(destInfo + 0x20) = *src2 * src0[2] - scalarResult * src1[2];
      scalarResult = *src2 * src0[3] - scalarResult * src1[3];
      goto loopSetResultKnown;
    }
    *(float *)(destInfo + 0x24) = 0.0;
    *destValue = 0.0;
    *(float *)(destInfo + 0x1c) = 0.0;
    *(float *)(destInfo + 0x20) = 0.0;
setResultKnown:
    resultKnown = !resultKnown;
    goto checkResultKnown;
  }
  resultKnown = true;
  *(float *)(destInfo + 0x24) = resultW;
checkResultKnown:
  if (resultKnown) {
checkNoDestination:
    if (!noDestination) {
      *(undefined4 *)(destInfo + 0x14) = 1;
    }
  }
  else if (!noDestination) {
    ((int (*)())_ClearDestedOpRegisters)(compileContext,hashSet,inst,0);
  }
  switch(*instWords >> 0x12 & 0xff) {
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x54:
  case 0x55:
  case 0x58:
  case 0x59:
  case 0x69:
    ((int (*)())_ClearRegisterState)(hashSet);
    return;
  default:
    goto instWordsCase4e;
  case 0x56:
  case 0x57:
  case 0x6a:
    chunk = _PPStreamChunkListChunkAtIndex(compileContext[8],*(uint *)(inst + 0x10) & 0x3ffff);
    destInfo = *(int *)(chunk + 4);
    currentInst = inst;
    break;
  case 0x5a:
  case 0x5b:
  case 0x6b:
    chunk = _PPStreamChunkListChunkAtIndex(compileContext[8],*(uint *)(inst + 0x10) & 0x3ffff);
    currentInst = *(int *)(chunk + 4);
    destInfo = inst;
  }
  ((int (*)())_ClearDestedRegisters)(compileContext,hashSet,currentInst,destInfo);
instWordsCase4e:
  return;
instWordsCase0:
  *destValue = *src0;
  *(float *)(destInfo + 0x1c) = src0[1];
  *(float *)(destInfo + 0x20) = src0[2];
  resultW = src0[3];
storeDestInfo7:
  *(float *)(destInfo + 0x24) = resultW;
  goto loopCheckFoldFailed;
}

/* _UpdateScope @ 0x97c0efd8 (96 bytes) */
int _UpdateScope(operationChunk, scopeDepth)
  int operationChunk;
  int *scopeDepth;
{
  switch(*(uint *)(operationChunk + 0xc) >> 0x12 & 0xff) {
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x6a:
    *scopeDepth = *scopeDepth + 1;
    return;
  case 0x58:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
    goto operationChunkCase58;
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x6b:
    *scopeDepth = *scopeDepth + -1;
operationChunkCase58:
    return;
  default:
    return;
  }
}

/* _GetOpRegs @ 0x97c0f094 (240 bytes) */
int _GetOpRegs(stream, operationChunk, sourceInfos, destInfo)
  undefined4 stream;
  int operationChunk;
  uint *sourceInfos;
  uint *destInfo;
{
  int nextPadIndex;
  ushort *registerNumberPtr;
  int validArgs;
  int operandCursor;
  int sourcesLeft;
  int paddedCount;
  uint *sourceInfo;
  
  operandCursor = operationChunk + 0xc;
  validArgs = _GetValidArgs(operationChunk);
  paddedCount = 0;
  sourcesLeft = validArgs;
  sourceInfo = sourceInfos;
  if (0 < validArgs) {
    do {
      sourceInfo[1] = *(uint *)(operandCursor + 0x10) >> 0x17 & 7;
      registerNumberPtr = (ushort *)(operandCursor + 0x16);
      operandCursor = operandCursor + 8;
      *sourceInfo = (uint)*registerNumberPtr;
      ((int (*)())_GetRegisterTypeInfo)(stream,sourceInfo);
      sourcesLeft = sourcesLeft + -1;
      sourceInfo = sourceInfo + 10;
    } while (sourcesLeft != 0);
    paddedCount = validArgs;
    if (3 < validArgs) goto checkOperationChunk;
  }
  do {
    nextPadIndex = paddedCount + 1;
    sourceInfos[paddedCount * 10 + 1] = 500;
    paddedCount = nextPadIndex;
  } while (nextPadIndex < 4);
checkOperationChunk:
  if ((*(uint *)(operationChunk + 0x14) & 0x1e000) == 0) {
    destInfo[1] = 500;
    return;
  }
  destInfo[1] = *(uint *)(operationChunk + 0x14) >> 0x11 & 7;
  *destInfo = (uint)*(ushort *)(operationChunk + 0x1a);
  ((int (*)())_GetRegisterTypeInfo)(stream,destInfo);
  return;
}

/* _DetectConstantLoopsSimple @ 0x97c0f184 (2520 bytes) */
int _DetectConstantLoopsSimple(stream)
  int stream;
{
  int ifOpCursor;
  int nextSourceIndex;
  int previousScanOp;
  int nextRemoveOp;
  int sourceIndex;
  int scanCursor;
  undefined1 *tableBase;
  uint oldOperandWord;
  uint whileDestPrecisionShifted;
  uint whileSrcPrecisionShifted;
  uint flagsSizeShifted;
  uint srcPrecisionShifted;
  uint destWordCopy;
  uint destSizeShifted;
  uint bodyOpcode;
  uint notMismatch;
  uint precisionShifted;
  uint sizeShifted;
  uint whileTargetWord;
  uint emitSourceCount;
  uint whileSrcWord;
  uint typeShifted;
  uint srcSizeShifted;
  uint destSizeBits;
  int srcTableIndex;
  bool isBranchOp;
  int regEqualsFunctionResult;
  uint isBadUsage;
  uint loopIndex;
  bool limitIsSrc0;
  undefined2 registerNumber16;
  bool countsDown;
  bool foundStep;
  bool foundEndif;
  bool bodyIsSimple;
  uint notEligible;
  uint setupFailed;
  uint compareOpcode;
  int endOpCandidate;
  int endifOp;
  int isInclusive;
  uint stepIsSubtract;
  int whileOp;
  int initOp;
  int notOp;
  uint bodyOpWord;
  undefined1 *otherSourceInfo;
  int compareOp;
  undefined1 src0Info [40];
  undefined1 src123Infos [120];
  undefined1 destInfo [48];
  undefined1 stepInfo [12];
  int stepInfoType;
  int stepInfoSize;
  int stepInfoIsConstant;
  int stepInfoValueX;
  undefined1 counterInfo [12];
  int counterInfoType;
  int counterInfoSize;
  undefined1 initInfo [12];
  int initInfoType;
  int initInfoSize;
  undefined1 limitInfo [12];
  int limitInfoType;
  int limitInfoSize;
  undefined4 loopTempARegister;
  uint loopTempABank;
  uint loopTempAPrecision;
  uint loopTempAType;
  uint loopTempASize;
  undefined4 loopTempB [2];
  undefined4 loopTempBPrecision;
  undefined4 loopTempBType;
  undefined4 loopTempBSize;
  undefined4 loopTempC [2];
  undefined4 loopTempCPrecision;
  undefined4 loopTempCType;
  undefined4 loopTempCSize;
  undefined4 loopTempD [2];
  undefined4 loopTempDPrecision;
  undefined4 loopTempDType;
  undefined4 loopTempDSize;
  undefined4 loopTempE [2];
  undefined4 loopTempEPrecision;
  undefined4 loopTempEType;
  undefined4 loopTempESize;
  undefined4 loopTempF [2];
  undefined4 loopTempFPrecision;
  undefined4 loopTempFType;
  undefined4 loopTempFSize;
  undefined4 loopTempG [2];
  undefined4 loopTempGPrecision;
  undefined4 loopTempGType;
  undefined4 loopTempGSize;
  uint opcodeTable [12];
  int emitEnabledTable [7];
  int emitEnabledTable7;
  int emitEnabledTable8;
  uint sourceCountTable [12];
  undefined1 *srcPtrTable;
  uint srcPtrTable1;
  undefined1 *srcPtrTable2;
  uint srcPtrTable3;
  undefined1 *srcPtrTable4;
  uint srcPtrTable5;
  undefined4 *srcPtrTable6;
  undefined4 *srcPtrTable7;
  undefined4 *srcPtrTable8;
  undefined4 *srcPtrTable9;
  undefined4 *srcPtrTable10;
  undefined4 srcPtrTable11;
  undefined4 *srcPtrTable12;
  undefined4 *srcPtrTable13;
  undefined4 *srcPtrTable14;
  undefined4 *srcPtrTable15;
  undefined4 *srcPtrTable16;
  undefined4 *srcPtrTable17;
  undefined4 *destPtrTable [4];
  undefined4 *destPtrTable4;
  undefined4 *destPtrTable5;
  undefined4 *destPtrTable6;
  undefined4 *destPtrTable7;
  undefined4 *destPtrTable8;
  uint opHeader;
  uint opFlags;
  uint opDest0;
  uint opDest1;
  uint opSrc0A;
  undefined4 opSrc0B;
  undefined2 opSrc0BHigh;
  undefined4 opSrc1A;
  undefined4 opSrc1B;
  undefined4 opSrc2A;
  undefined4 opSrc2B;
  undefined4 opAuxA;
  undefined4 opAuxB;
  undefined4 opLine;
  undefined4 opWord13;
  int scopeDepth;
  int loopEndOp;
  
  whileOp = **(int **)(stream + 0x20);
  do {
    if (whileOp == 0) {
      return;
    }
    if ((*(uint *)(whileOp + 0xc) >> 0x12 & 0xff) == 0x6a) {
      initOp = *(int *)(whileOp + 4);
      loopEndOp = 0;
      bodyIsSimple = true;
      foundEndif = false;
      foundStep = false;
      if ((initOp == 0) || ((*(uint *)(initOp + 0xc) >> 0x12 & 0xff) != 0)) {
        setupFailed = 1;
      }
      else {
        ((int (*)())_GetOpRegs)(stream,initOp,src0Info,destInfo);
        setupFailed = ((int (*)())_IsBadUsage)(initOp);
        _memcpy(counterInfo,destInfo,0x28);
        _memcpy(initInfo,src0Info,0x28);
      }
      compareOp = *(int *)(whileOp + 8);
      notOp = *(int *)(compareOp + 8);
      endifOp = 0;
      limitIsSrc0 = false;
      ifOpCursor = *(int *)(notOp + 8);
      ((int (*)())_GetOpRegs)(stream,compareOp,src0Info,destInfo);
      stepIsSubtract = 0;
      isBadUsage = ((int (*)())_IsBadUsage)(compareOp);
      setupFailed = setupFailed | isBadUsage;
      regEqualsFunctionResult = _regEqualsFunction(counterInfo,src0Info);
      countsDown = false;
      isInclusive = 0;
      if (regEqualsFunctionResult == 0) {
        otherSourceInfo = src123Infos;
loopCallMemcpy:
        _memcpy(limitInfo,otherSourceInfo,0x28);
      }
      else {
        regEqualsFunctionResult = _regEqualsFunction(counterInfo,src123Infos);
        if (regEqualsFunctionResult == 0) {
          otherSourceInfo = src0Info;
          limitIsSrc0 = true;
          goto loopCallMemcpy;
        }
        setupFailed = 1;
      }
      compareOpcode = *(uint *)(compareOp + 0xc) >> 0x12 & 0xff;
      if (compareOpcode == 0x33) {
        countsDown = true;
      }
      else if (compareOpcode < 0x34) {
        if (compareOpcode == 0x32) {
          countsDown = true;
loopSetIsInclusive:
          isInclusive = 1;
        }
        else {
loopSetSetupFailed:
          setupFailed = 1;
        }
      }
      else {
        if (compareOpcode == 0x34) goto loopSetIsInclusive;
        if (compareOpcode != 0x35) goto loopSetSetupFailed;
      }
      if (limitIsSrc0) {
        countsDown = (bool)(countsDown ^ 1);
      }
      notMismatch = 0;
      if ((notOp == 0) || ((*(uint *)(notOp + 0xc) >> 0x12 & 0xff) != 10)) {
        notMismatch = 1;
      }
      notEligible = 0;
      if ((ifOpCursor == 0) || ((*(uint *)(ifOpCursor + 0xc) >> 0x12 & 0xff) != 0x55)) {
        notEligible = 1;
      }
      notEligible = setupFailed | notMismatch | notEligible;
      scopeDepth = 0;
      whileTargetWord = *(uint *)(whileOp + 0x10);
      endOpCandidate = loopEndOp;
      if (notEligible == 0) {
        previousScanOp = 0;
        scanCursor = whileOp;
        while ((((*(uint *)(scanCursor + 0xc) & 0x3ffff) != (whileTargetWord & 0x3ffff) || (previousScanOp == 0)) ||
               (endOpCandidate = previousScanOp, (*(uint *)(previousScanOp + 0xc) >> 0x12 & 0xff) != 0x6b))) {
          ((int (*)())_UpdateScope)(scanCursor,&scopeDepth);
          ((int (*)())_GetOpRegs)(stream,scanCursor,src0Info,destInfo);
          isBadUsage = ((int (*)())_IsBadUsage)(scanCursor);
          regEqualsFunctionResult = _regEqualsFunction(counterInfo,destInfo);
          if (regEqualsFunctionResult == 0) {
            notEligible = notEligible | isBadUsage | (uint)(1 < scopeDepth);
            if (foundStep) {
              notEligible = 1;
              goto setBodyOpWord;
            }
            bodyOpWord = *(uint *)(scanCursor + 0xc);
            foundStep = true;
            bodyOpcode = bodyOpWord >> 0x12 & 0xff;
            if (bodyOpcode != 0x1f) {
              if (bodyOpcode == 0x20) {
                stepIsSubtract = 1;
              }
              else {
                notEligible = 1;
              }
            }
            regEqualsFunctionResult = _regEqualsFunction(counterInfo,src0Info);
            otherSourceInfo = src123Infos;
            if (regEqualsFunctionResult == 0) {
loopCallMemcpy2:
              _memcpy(stepInfo,otherSourceInfo,0x28);
              goto setBodyOpWord;
            }
            regEqualsFunctionResult = _regEqualsFunction(counterInfo,src123Infos);
            if (regEqualsFunctionResult == 0) {
              notEligible = notEligible | stepIsSubtract;
              otherSourceInfo = src0Info;
              goto loopCallMemcpy2;
            }
            notEligible = 1;
          }
          else {
setBodyOpWord:
            bodyOpWord = *(uint *)(scanCursor + 0xc);
          }
          regEqualsFunctionResult = _regEqualsFunction(limitInfo,destInfo);
          bodyOpcode = bodyOpWord >> 0x12 & 0xff;
          notEligible = notEligible | regEqualsFunctionResult == 0;
          if (bodyOpcode == 0x4d) {
loopSetBodyIsSimple:
            bodyIsSimple = false;
          }
          else {
            if (bodyOpcode < 0x4e) {
              isBranchOp = bodyOpcode == 0x4b;
            }
            else {
              isBranchOp = bodyOpcode == 0x69;
            }
            if (isBranchOp) goto loopSetBodyIsSimple;
          }
          if (!foundEndif) {
            bodyOpcode = bodyOpWord >> 0x12 & 0xff;
            if (bodyOpcode == 0x55) {
              if (ifOpCursor != scanCursor) {
                bodyIsSimple = false;
              }
            }
            else if (bodyOpcode == 0x59) {
              foundEndif = true;
              endifOp = scanCursor;
            }
          }
          endOpCandidate = loopEndOp;
          if (((*(int *)(scanCursor + 8) == 0) || (notEligible != 0)) ||
             (previousScanOp = scanCursor, scanCursor = *(int *)(scanCursor + 8), !bodyIsSimple)) break;
        }
      }
      loopEndOp = endOpCandidate;
      if (((counterInfoType != 3) || (initInfoType != 3)) || ((limitInfoType != 3 || (stepInfoType != 3)))) {
        notEligible = 1;
      }
      if ((((counterInfoSize != 0) || (initInfoSize != 0)) || (limitInfoSize != 0)) || (stepInfoSize != 0)) {
        notEligible = 1;
      }
      notEligible = notEligible | stepInfoIsConstant == 0;
      if (stepInfoValueX < 0) {
        stepIsSubtract = stepIsSubtract ^ 1;
      }
      if (countsDown) {
        if (stepIsSubtract == 0) goto setNotEligible;
      }
      else if (stepIsSubtract != 0) {
setNotEligible:
        notEligible = 1;
      }
      if (((notEligible == 0) && (foundStep)) && (((foundEndif && ((ifOpCursor != 0 && (endifOp != 0)))) && (bodyIsSimple)))) {
        loopTempABank = 1;
        loopTempAType = 1;
        loopTempAPrecision = notEligible;
        loopTempASize = notEligible;
        loopTempARegister = _AddTempRegister(stream,0,1,0);
        _memcpy(loopTempB,&loopTempARegister,0x28);
        loopTempB[0] = _AddTempRegister(stream,loopTempBPrecision,loopTempBType,loopTempBSize);
        _memcpy(loopTempC,&loopTempARegister,0x28);
        loopTempC[0] = _AddTempRegister(stream,loopTempCPrecision,loopTempCType,loopTempCSize);
        _memcpy(loopTempD,&loopTempARegister,0x28);
        loopTempD[0] = _AddTempRegister(stream,loopTempDPrecision,loopTempDType,loopTempDSize);
        _memcpy(loopTempE,&loopTempARegister,0x28);
        loopTempE[0] = _AddTempRegister(stream,loopTempEPrecision,loopTempEType,loopTempESize);
        if (isInclusive != 0) {
          _memcpy(loopTempF,&loopTempARegister,0x28);
          loopTempF[0] = _AddTempRegister(stream,loopTempFPrecision,loopTempFType,loopTempFSize);
          _memcpy(loopTempG,&loopTempARegister,0x28);
          loopTempG[0] = _AddTempRegister(stream,loopTempGPrecision,loopTempGType,loopTempGSize);
        }
        _memcpy(opcodeTable,&detectConstantLoopsOpcodeTableInit_97c3aa40,0x24);
        emitEnabledTable[5] = 1;
        emitEnabledTable[0] = 1;
        emitEnabledTable[1] = 1;
        emitEnabledTable[2] = 1;
        emitEnabledTable[3] = 1;
        emitEnabledTable[4] = 1;
        emitEnabledTable[6] = isInclusive;
        emitEnabledTable7 = isInclusive;
        emitEnabledTable8 = isInclusive;
        _memcpy(sourceCountTable,&detectConstantLoopsSourceCountTableInit_97c3aa64,0x24);
        srcPtrTable = limitInfo;
        srcPtrTable2 = initInfo;
        srcPtrTable4 = stepInfo;
        srcPtrTable5 = notEligible;
        srcPtrTable1 = notEligible;
        srcPtrTable3 = notEligible;
        srcPtrTable6 = loopTempC;
        if (stepIsSubtract != 0) {
          srcPtrTable6 = loopTempD;
        }
        srcPtrTable7 = loopTempD;
        if (stepIsSubtract != 0) {
          srcPtrTable7 = loopTempC;
        }
        tableBase = src0Info;
        destPtrTable[0] = loopTempC;
        destPtrTable[1] = loopTempD;
        loopIndex = 0;
        destPtrTable[2] = loopTempE;
        destPtrTable[3] = loopTempB;
        destPtrTable8 = &loopTempARegister;
        srcPtrTable8 = loopTempB;
        srcPtrTable9 = loopTempE;
        srcPtrTable10 = &loopTempARegister;
        srcPtrTable12 = &loopTempARegister;
        srcPtrTable13 = loopTempE;
        srcPtrTable15 = loopTempB;
        srcPtrTable16 = &loopTempARegister;
        destPtrTable4 = &loopTempARegister;
        destPtrTable5 = &loopTempARegister;
        destPtrTable6 = loopTempF;
        destPtrTable7 = loopTempG;
        srcPtrTable11 = 0;
        srcPtrTable14 = loopTempF;
        srcPtrTable17 = loopTempG;
        do {
          if (*(int *)(tableBase + 0x310) != 0) {
            opSrc0A = 0;
            opSrc0B = 0;
            opSrc1A = 0;
            opSrc1B = 0;
            opSrc2A = 0;
            opSrc2B = 0;
            opAuxA = 0;
            opAuxB = 0;
            opFlags = 0;
            opLine = 0;
            opHeader = (*(uint *)(tableBase + 0x2e0) & 0xff) << 0x12;
            emitSourceCount = *(uint *)(tableBase + 0x340);
            opDest0 = 0;
            opDest1 = 0;
            opLine = *(undefined4 *)(whileOp + 0x3c);
            opHeader = emitSourceCount << 0x1d | opHeader;
            opWord13 = 0;
            destSizeShifted = (*(uint *)(*(int *)(tableBase + 0x3c0) + 0x10) & 3) << 10;
            opDest0 = destSizeShifted | 0x6c;
            destSizeBits = *(uint *)(*(int *)(tableBase + 0x3c0) + 0x10) & 3;
            if (destSizeBits == 1) {
loopSetOpDest0:
              opDest0 = opDest0 | 0x4000;
loopSetOpDest02:
              opDest0 = opDest0 | 0x2000;
            }
            else {
              if (1 < destSizeBits) {
                if (destSizeBits != 2) {
                  if (destSizeBits != 3) goto setOpDest0;
                  opDest0 = destSizeShifted | 0x1006c;
                }
                opDest0 = opDest0 | 0x8000;
                goto loopSetOpDest0;
              }
              if (destSizeBits == 0) goto loopSetOpDest02;
            }
setOpDest0:
            opDest0 = (*(uint *)(*(int *)(tableBase + 0x3c0) + 4) & 7) << 0x11 | opDest0;
            opDest1 = (uint)*(ushort *)(*(int *)(tableBase + 0x3c0) + 2);
            sourceIndex = 0;
            destWordCopy = opDest0;
            if ((emitSourceCount & 7) != 0) {
              do {
                oldOperandWord = (&opSrc0A)[sourceIndex * 2];
                srcSizeShifted = (destWordCopy >> 10 & 3) << 0xc;
                srcTableIndex = loopIndex * 2 + sourceIndex;
                (&opSrc0A)[sourceIndex * 2] = srcSizeShifted | oldOperandWord & 0xff804fff | 0xd8000;
                nextSourceIndex = sourceIndex + 1;
                srcPrecisionShifted = (*(uint *)((&srcPtrTable)[srcTableIndex] + 4) & 7) << 0x17;
                (&opSrc0A)[sourceIndex * 2] = srcPrecisionShifted | srcSizeShifted | oldOperandWord & 0xfc004fff | 0xd8000;
                registerNumber16 = *(undefined2 *)((&srcPtrTable)[srcTableIndex] + 2);
                (&opSrc0A)[sourceIndex * 2] = srcPrecisionShifted | srcSizeShifted | oldOperandWord & 0xf4004fff | 0xd8000;
                (&opSrc0BHigh)[sourceIndex * 4] = registerNumber16;
                sourceIndex = nextSourceIndex;
                destWordCopy = opDest0;
              } while (nextSourceIndex < (int)(emitSourceCount & 7));
            }
            flagsSizeShifted = (*(uint *)(*(int *)(tableBase + 0x3c0) + 8) & 3) << 0x12;
            opFlags = flagsSizeShifted;
            typeShifted = (*(uint *)(*(int *)(tableBase + 0x3c0) + 0xc) & 7) << 0x17;
            opFlags = typeShifted | flagsSizeShifted;
            opFlags = (*(uint *)(*(int *)(tableBase + 0x3c0) + 0x10) & 3) << 0x1a | typeShifted | flagsSizeShifted;
            _PPStreamInsertOperationBeforeChunk(stream,&opHeader,0,0,whileOp);
          }
          loopIndex = loopIndex + 1;
          tableBase = tableBase + 4;
        } while (loopIndex < 9);
        endifOp = *(int *)(endifOp + 8);
        while (ifOpCursor != endifOp) {
          nextRemoveOp = *(int *)(ifOpCursor + 8);
          _PPStreamRemoveOperation(stream,ifOpCursor);
          ifOpCursor = nextRemoveOp;
        }
        whileSrcWord = *(uint *)(whileOp + 0x1c);
        *(uint *)(whileOp + 0xc) = *(uint *)(whileOp + 0xc) & 0x1c03ffff | 0x215c0000;
        sizeShifted = (loopTempASize & 3) << 0xc;
        *(uint *)(whileOp + 0x1c) = sizeShifted | whileSrcWord & 0xff85cfff | 0xd8000;
        whileSrcPrecisionShifted = (loopTempABank & 7) << 0x17;
        *(uint *)(whileOp + 0x1c) = whileSrcPrecisionShifted | sizeShifted | whileSrcWord & 0xfc05cfff | 0xd8000;
        *(uint *)(whileOp + 0x1c) = whileSrcPrecisionShifted | sizeShifted | whileSrcWord & 0xf405cfff | 0xd8000;
        *(undefined2 *)(whileOp + 0x22) = (*(unsigned short *)((unsigned char *)&(loopTempARegister) + 2));
        whileSrcWord = *(uint *)(whileOp + 0x10);
        precisionShifted = (loopTempAPrecision & 3) << 0x12;
        *(uint *)(whileOp + 0x10) = precisionShifted | whileSrcWord & 0xfff3ffff;
        whileDestPrecisionShifted = (loopTempAType & 7) << 0x17;
        *(uint *)(whileOp + 0x10) = whileDestPrecisionShifted | precisionShifted | whileSrcWord & 0xfc73ffff;
        *(uint *)(whileOp + 0x10) = (loopTempASize & 3) << 0x1a | whileDestPrecisionShifted | precisionShifted | whileSrcWord & 0xf073ffff;
        *(uint *)(loopEndOp + 0xc) = *(uint *)(loopEndOp + 0xc) & 0xfc03ffff | 0x16c0000;
      }
    }
    whileOp = *(int *)(whileOp + 8);
  } while( true );
}

/* _UnrollConstantLoopsSimple @ 0x97c0fb5c (1808 bytes) */
int _UnrollConstantLoopsSimple(stream, allowRepify)
  int stream;
  int allowRepify;
{
  uint newOp;
  int patchesLeft;
  int tableByteOffset;
  int iterationCount;
  int repifyResult;
  int operandIndex;
  int anchorOp;
  int knownCountRegister;
  int operandTableIndex;
  int foundEnd;
  bool hasNext;
  uint newOpIndex;
  uint *labelSlot;
  bool isCountKnown;
  undefined4 knownRegisters;
  int scanCursor;
  uint operandWord;
  int nextOperandIndex;
  uint *tableBase;
  uint loopEndLabel;
  bool bodyIsStraightLine;
  uint *tableCursor;
  int previousOperation;
  int operationChunk;
  uint countInfoRegister;
  uint countInfoBank;
  int countInfoIsConstant;
  uint lookupKeyRegister;
  uint lookupKeyBank;
  longlong convertScratch;
  uint counterInfoRegister;
  uint counterInfoBank;
  undefined4 counterInfoPrecision;
  undefined4 counterInfoType;
  undefined4 oneConstRegister;
  undefined4 oneConstBank;
  undefined4 oneConstX;
  undefined4 oneConstY;
  undefined4 oneConstZ;
  undefined4 oneConstW;
  undefined4 condTempRegister;
  undefined4 condTempBank;
  undefined4 condTempPrecision;
  undefined4 condTempType;
  undefined4 condTempSize;
  uint newOps [8];
  int *insertAfterAnchors [4];
  undefined4 insertAfterAnchorsTail;
  uint insertBeforeAnchors [4];
  int *insertBeforeAnchorsTail;
  uint opcodeTable [4];
  undefined4 opcodeTableTail;
  uint sourceCountTable [4];
  undefined4 sourceCountTableTail;
  uint *operandPtrTable [9];
  undefined4 *operandPtrTableTail;
  uint *destPtrTable [8];
  uint opRecord [5];
  undefined4 opRecordSrc0B;
  undefined2 opRecordSrc0BHigh;
  undefined4 opRecordSrc1A;
  undefined4 opRecordSrc1B;
  undefined4 opRecordSrc2A;
  uint opRecordSrc2B;
  uint opRecordAuxA;
  undefined4 opRecordAuxB;
  undefined4 opRecordLine;
  undefined4 opRecordWord13;
  int loopStart;
  int loopEnd [5];
  
  knownRegisters = _HashSetNew((*(uint *)(*(int *)(stream + 4) + 8) >> 5) + 1,regHashFunctionPtr,regEqualsFunctionPtr);
  operationChunk = **(int **)(stream + 0x20);
  do {
    while( true ) {
      if (operationChunk == 0) {
        ((int (*)())_ClearRegisterState)(knownRegisters);
        _HashSetFree(knownRegisters);
        return;
      }
      if ((*(uint *)(operationChunk + 0xc) >> 0x12 & 0xff) == 0x57) break;
loopCallEmulateOp:
      ((int (*)())_EmulateOp)(stream,operationChunk,knownRegisters);
loopSetOperationChunk:
      operationChunk = *(int *)(operationChunk + 8);
    }
    isCountKnown = false;
    if (allowRepify != 0) {
      countInfoBank = *(uint *)(operationChunk + 0x1c) >> 0x17 & 7;
      countInfoRegister = (uint)*(ushort *)(operationChunk + 0x22);
      ((int (*)())_GetRegisterTypeInfo)(stream,&countInfoRegister);
      isCountKnown = countInfoIsConstant != 0;
    }
    if (isCountKnown) goto loopCallEmulateOp;
    loopEnd[0] = 0;
    bodyIsStraightLine = true;
    loopEndLabel = *(uint *)(operationChunk + 0x10) & 0x3ffff;
    hasNext = true;
    previousOperation = 0;
    scanCursor = operationChunk;
    while ((foundEnd = loopEnd[0], hasNext &&
           ((((*(uint *)(scanCursor + 0xc) & 0x3ffff) != loopEndLabel || (previousOperation == 0)) ||
            (foundEnd = previousOperation, (*(uint *)(previousOperation + 0xc) >> 0x12 & 0xff) != 0x5b))))) {
      switch(*(uint *)(scanCursor + 0xc) >> 0x12 & 0xff) {
      case 0x4b:
      case 0x54:
      case 0x69:
        if (loopEndLabel < (*(uint *)(scanCursor + 0x10) & 0x3ffff)) goto scanCursorCase4c;
        break;
      case 0x4c:
      case 0x4d:
scanCursorCase4c:
        bodyIsStraightLine = false;
      }
      hasNext = *(int *)(scanCursor + 8) != 0;
      previousOperation = scanCursor;
      scanCursor = *(int *)(scanCursor + 8);
    }
    loopEnd[0] = foundEnd;
    iterationCount = -1;
    lookupKeyBank = *(uint *)(operationChunk + 0x1c) >> 0x17 & 7;
    lookupKeyRegister = (uint)*(ushort *)(operationChunk + 0x22);
    loopStart = operationChunk;
    knownCountRegister = _HashSetGet(knownRegisters,&lookupKeyRegister);
    if (knownCountRegister == 0) {
loopSetTableBase:
      tableBase = &countInfoRegister;
      newOpIndex = 0;
      counterInfoBank = *(uint *)(loopStart + 0x1c) >> 0x17 & 7;
      counterInfoRegister = (uint)*(ushort *)(loopStart + 0x22);
      ((int (*)())_GetRegisterTypeInfo)(stream,&counterInfoRegister);
      oneConstX = 0x3f800000;
      oneConstW = 0;
      oneConstY = 0;
      oneConstZ = 0;
      oneConstBank = 2;
      oneConstRegister = _AddConstantParam(stream,counterInfoPrecision,counterInfoType,0,0x3f800000,0,0,0);
      condTempBank = 1;
      condTempType = 4;
      condTempPrecision = 0;
      condTempSize = 0;
      condTempRegister = _AddTempRegister(stream,0,4,0);
      insertAfterAnchors[0] = &loopStart;
      insertAfterAnchors[1] = (int *)newOps;
      insertAfterAnchors[2] = (int *)(newOps + 1);
      insertAfterAnchors[3] = (int *)(newOps + 2);
      insertBeforeAnchorsTail = loopEnd;
      opcodeTableTail = unrollConstantLoopsOpcodeTableInitTail_97c3aa98;
      newOps[0] = 0;
      newOps[1] = 0;
      newOps[2] = 0;
      newOps[3] = 0;
      newOps[4] = 0;
      insertAfterAnchorsTail = 0;
      insertBeforeAnchors[0] = 0;
      insertBeforeAnchors[1] = 0;
      insertBeforeAnchors[2] = 0;
      insertBeforeAnchors[3] = 0;
      opcodeTable[0] = unrollConstantLoopsOpcodeTableInit0_97c3aa88;
      opcodeTable[1] = unrollConstantLoopsOpcodeTableInit1_97c3aa8c;
      opcodeTable[2] = unrollConstantLoopsOpcodeTableInit2_97c3aa90;
      opcodeTable[3] = unrollConstantLoopsOpcodeTableInit3_97c3aa94;
      sourceCountTable[0] = unrollConstantLoopsSourceCountTableInit0_97c3aa9c;
      sourceCountTable[1] = unrollConstantLoopsSourceCountTableInit1_97c3aaa0;
      sourceCountTable[2] = unrollConstantLoopsSourceCountTableInit2_97c3aaa4;
      sourceCountTable[3] = unrollConstantLoopsSourceCountTableInit3_97c3aaa8;
      destPtrTable[3] = (uint *)0x0;
      destPtrTable[4] = &counterInfoRegister;
      operandPtrTable[0] = &counterInfoRegister;
      operandPtrTable[3] = (uint *)0x0;
      operandPtrTable[4] = (uint *)0x0;
      operandPtrTable[5] = (uint *)0x0;
      operandPtrTable[6] = (uint *)0x0;
      operandPtrTable[7] = (uint *)0x0;
      operandPtrTable[8] = &counterInfoRegister;
      destPtrTable[1] = (uint *)0x0;
      destPtrTable[2] = (uint *)0x0;
      tableByteOffset = 0;
      sourceCountTableTail = unrollConstantLoopsSourceCountTableInitTail_97c3aaac;
      operandPtrTableTail = &oneConstRegister;
      destPtrTable[0] = &condTempRegister;
      operandPtrTable[1] = &oneConstRegister;
      operandPtrTable[2] = &condTempRegister;
      tableCursor = tableBase;
      do {
        opRecord[4] = 0;
        opRecordSrc0B = 0;
        opRecordSrc1A = 0;
        opRecordSrc1B = 0;
        opRecordSrc2A = 0;
        opRecordSrc2B = 0;
        opRecordAuxA = 0;
        opRecordAuxB = 0;
        opRecord[0] = 0;
        opRecord[1] = 0;
        opRecord[2] = 0;
        opRecord[3] = 0;
        opRecordLine = 0;
        opRecordWord13 = 0;
        if ((int *)tableCursor[0x48] == (int *)0x0) {
          anchorOp = *(int *)tableCursor[0x50];
        }
        else {
          anchorOp = *(int *)tableCursor[0x48];
        }
        opRecord[0] = (tableCursor[0x58] & 0xff) << 0x12;
        opRecordLine = *(undefined4 *)(anchorOp + 0x3c);
        opRecord[0] = tableCursor[0x60] << 0x1d | opRecord[0];
        opRecord[1] = 0x1800000;
        if (tableCursor[0x74] != 0) {
          opRecord[2] = 0x6c;
          opRecord[2] = 0x206c;
          opRecord[2] = (*(uint *)(tableCursor[0x74] + 4) & 7) << 0x11 | 0x206c;
          opRecord[3] = (uint)*(ushort *)(tableCursor[0x74] + 2);
        }
        operandIndex = 0;
        if (0 < (int)tableCursor[0x60]) {
          do {
            operandWord = opRecord[operandIndex * 2 + 4];
            operandTableIndex = newOpIndex * 2 + operandIndex;
            opRecord[operandIndex * 2 + 4] = operandWord & 0xff81cfff | 0xd8000;
            nextOperandIndex = operandIndex + 1;
            opRecord[operandIndex * 2 + 4] =
                 (operandPtrTable[operandTableIndex][1] & 7) << 0x17 | operandWord & 0xfc01cfff | 0xd8000;
            (&opRecordSrc0BHigh)[operandIndex * 4] = (short)*operandPtrTable[operandTableIndex];
            operandIndex = nextOperandIndex;
          } while (nextOperandIndex < *(int *)((int)sourceCountTable + tableByteOffset));
        }
        if ((undefined4 *)tableCursor[0x48] == (undefined4 *)0x0) {
          newOp = _PPStreamInsertOperationBeforeChunk
                            (stream,opRecord,0,0,*(undefined4 *)tableCursor[0x50]);
        }
        else {
          newOp = _PPStreamInsertOperationAfterChunk
                            (stream,opRecord,0,0,*(undefined4 *)tableCursor[0x48]);
        }
        newOpIndex = newOpIndex + 1;
        tableCursor[0x40] = newOp;
        tableByteOffset = tableByteOffset + 4;
        tableCursor = tableCursor + 1;
      } while (newOpIndex < 5);
      opRecordSrc2A = 0;
      opRecordSrc2B = *(uint *)(*(int *)(newOps[3] + 8) + 0xc) & 0x3ffff;
      opRecord[1] = opRecordSrc2B;
      opRecord[2] = *(uint *)(loopStart + 0x10) & 0x3ffff;
      opRecord[4] = 0;
      opRecordAuxA = opRecord[2];
      patchesLeft = 5;
      opRecordAuxB = 0;
      opRecordLine = 0;
      opRecord[0] = 0;
      opRecord[3] = 0;
      do {
        tableCursor = tableBase + 0x40;
        labelSlot = tableBase + 0x7c;
        tableBase = tableBase + 1;
        *(uint *)(*tableCursor + 0x10) = *labelSlot & 0x3ffff | *(uint *)(*tableCursor + 0x10) & 0xfffc0000;
        patchesLeft = patchesLeft + -1;
      } while (patchesLeft != 0);
      *(uint *)(loopStart + 0xc) = *(uint *)(loopStart + 0xc) & 0xfc03ffff | 0x1a80000;
      *(uint *)(loopStart + 0xc) = *(uint *)(loopStart + 0xc) & 0x1fffffff;
      *(uint *)(loopEnd[0] + 0xc) = *(uint *)(loopEnd[0] + 0xc) & 0xfc03ffff | 0x1ac0000;
      *(uint *)(loopEnd[0] + 0x10) =
           *(uint *)(*(int *)(loopStart + 8) + 0xc) & 0x3ffff |
           *(uint *)(loopEnd[0] + 0x10) & 0xfffc0000;
      goto loopCallEmulateOp;
    }
    if (((*(int *)(knownCountRegister + 0x14) == 0) || (*(int *)(knownCountRegister + 0x10) != 0)) ||
       (*(int *)(knownCountRegister + 0xc) != 1)) {
      bodyIsStraightLine = false;
    }
    else {
      iterationCount = (int)*(float *)(knownCountRegister + 0x18);
      convertScratch = (longlong)iterationCount;
    }
    if (!bodyIsStraightLine) goto loopSetTableBase;
    operationChunk = *(int *)(loopStart + 4);
    if (((allowRepify == 0) || (iterationCount < 1)) ||
       (repifyResult = ((int (*)())_RepifyConstantLoopSimple)(stream,loopStart,loopEnd[0],iterationCount), repifyResult == 0)) {
      ((int (*)())_UnrollConstantLoopSimple)(stream,loopStart,loopEnd[0],iterationCount);
    }
    if (operationChunk != 0) goto loopSetOperationChunk;
    operationChunk = **(int **)(stream + 0x20);
  } while( true );
}

/* _instructionIndexHashFunction @ 0x97c102e8 (4 bytes) */
int _instructionIndexHashFunction()
{
  return;
}

/* _UnrollConstantLoopSimple @ 0x97c102f4 (596 bytes) */
int _UnrollConstantLoopSimple(stream, loopStart, loopEnd, iterationCount)
  int stream;
  int loopStart;
  int loopEnd;
  int iterationCount;
{
  int endOfCopies;
  int operationAfterEnd;
  int nextOperation;
  int mappedLabel;
  bool isFirstInsert;
  int removeCursor;
  undefined4 labelMap;
  int insertionPoint;
  int copyCursor;
  int bodyOperation;
  undefined4 opHeader;
  undefined4 opFlags;
  undefined4 opDest0;
  undefined4 opDest1;
  undefined4 opSrc0A;
  undefined4 opSrc0B;
  undefined4 opSrc1A;
  undefined4 opSrc1B;
  undefined4 opSrc2A;
  undefined4 opSrc2B;
  undefined4 opAuxA;
  undefined4 opAuxB;
  undefined4 opLine;
  undefined4 opWord13;
  
  insertionPoint = loopEnd;
  if (0 < iterationCount) {
    labelMap = _HashTableNew((*(uint *)(*(int *)(stream + 0x20) + 8) >> 5) + 1,ptrTo_instructionIndexHashFunction_a7b7bf78,
                          ptrTo_instructionIndexEqualsFunction_a7b7bf74);
    do {
      copyCursor = 0;
      isFirstInsert = true;
      for (bodyOperation = *(int *)(loopStart + 8); (bodyOperation != 0 && (bodyOperation != loopEnd));
          bodyOperation = *(int *)(bodyOperation + 8)) {
        insertionPoint = _PPStreamInsertOperationAfterChunk(stream,bodyOperation + 0xc,0,0,insertionPoint);
        if (isFirstInsert) {
          copyCursor = insertionPoint;
        }
        isFirstInsert = isFirstInsert && insertionPoint == 0;
        _HashTableAdd(labelMap,(*(uint *)(bodyOperation + 0xc) & 0x3ffff) + 1,
                      (*(uint *)(insertionPoint + 0xc) & 0x3ffff) + 1);
      }
      opFlags = 0;
      opHeader = 0x1b80000;
      opDest0 = 0;
      opDest1 = 0;
      opSrc0A = 0;
      opSrc0B = 0;
      opSrc1A = 0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opAuxA = 0;
      opAuxB = 0;
      opLine = 0;
      opWord13 = 0;
      insertionPoint = _PPStreamInsertOperationAfterChunk(stream,&opHeader,0,0,insertionPoint);
      _HashTableAdd(labelMap,(*(uint *)(loopEnd + 0xc) & 0x3ffff) + 1,
                    (*(uint *)(insertionPoint + 0xc) & 0x3ffff) + 1);
      if (isFirstInsert) {
        copyCursor = insertionPoint;
      }
      if (!isFirstInsert || insertionPoint != 0) {
        do {
          if (copyCursor == insertionPoint) break;
          mappedLabel = _HashTableGet(labelMap,(*(uint *)(copyCursor + 0x10) & 0x3ffff) + 1);
          if (mappedLabel != 0) {
            *(uint *)(copyCursor + 0x10) = mappedLabel - 1U & 0x3ffff | *(uint *)(copyCursor + 0x10) & 0xfffc0000;
          }
          copyCursor = *(int *)(copyCursor + 8);
        } while (copyCursor != 0);
      }
      iterationCount = iterationCount + -1;
    } while (0 < iterationCount);
    _HashTableFree(labelMap);
  }
  operationAfterEnd = *(int *)(loopEnd + 8);
  endOfCopies = *(int *)(insertionPoint + 8);
  nextOperation = operationAfterEnd;
  while (removeCursor = nextOperation, removeCursor != endOfCopies) {
    nextOperation = *(int *)(removeCursor + 8);
    if ((*(uint *)(removeCursor + 0xc) >> 0x12 & 0xff) == 0x6e) {
      _PPStreamRemoveOperation(stream,removeCursor);
    }
  }
  while (loopStart != operationAfterEnd) {
    nextOperation = *(int *)(loopStart + 8);
    _PPStreamRemoveOperation(stream,loopStart);
    loopStart = nextOperation;
  }
  return;
}

/* _RepifyConstantLoopSimple @ 0x97c10548 (384 bytes) */
int _RepifyConstantLoopSimple(compileContext, loopStart, loopEnd, iterationCount)
  int compileContext;
  int loopStart;
  int loopEnd;
  uint iterationCount;
{
  uint opcode;
  undefined4 knownRegisters;
  int knownRegister;
  undefined2 addConstantParamResult;
  int isConstantLoop;
  int bodyOperation;
  uint lookupKeyRegister;
  uint lookupKeyBank;
  float constantX;
  undefined4 constantY;
  undefined4 constantZ;
  undefined4 constantW;
  undefined4 convertHigh;
  uint convertLow;
  
  knownRegisters = _HashSetNew((*(uint *)(*(int *)(compileContext + 4) + 8) >> 5) + 1,regHashFunctionPtr,regEqualsFunctionPtr);
  bodyOperation = *(int *)(loopStart + 8);
  isConstantLoop = 1;
  do {
    if ((bodyOperation == 0) || (bodyOperation == loopEnd)) goto callClearRegisterState;
    opcode = *(uint *)(bodyOperation + 0xc) >> 0x12 & 0xff;
    if ((opcode == 0x57) || (opcode == 0x48)) {
      lookupKeyBank = *(uint *)(bodyOperation + 0x1c) >> 0x17 & 7;
      lookupKeyRegister = (uint)*(ushort *)(bodyOperation + 0x22);
      knownRegister = _HashSetGet(knownRegisters,&lookupKeyRegister);
      if ((knownRegister == 0) || (*(int *)(knownRegister + 0x14) == 0)) {
        isConstantLoop = 0;
callClearRegisterState:
        ((int (*)())_ClearRegisterState)(knownRegisters);
        _HashSetFree(knownRegisters);
        if (isConstantLoop != 0) {
          convertLow = iterationCount ^ 0x80000000;
          convertHigh = 0x43300000;
          constantW = 0;
          constantY = 0;
          constantZ = 0;
          constantX = (float)((double)CONCAT44(0x43300000,convertLow) - DOUBLE_97c30a58);
          *(uint *)(loopStart + 0x1c) = *(uint *)(loopStart + 0x1c) & 0xfc7fffff | 0x1000000;
          addConstantParamResult = _AddConstantParam(compileContext,0,1,0,constantX,0,0,0);
          *(undefined2 *)(loopStart + 0x22) = addConstantParamResult;
        }
        return isConstantLoop;
      }
    }
    ((int (*)())_EmulateOp)(compileContext,bodyOperation,knownRegisters);
    bodyOperation = *(int *)(bodyOperation + 8);
  } while( true );
}

/* _ConstantPropagateFold @ 0x97c106c8 (536 bytes) */
int _ConstantPropagateFold(compileContext)
  int compileContext;
{
  int knownDestRegister;
  uint operandWord;
  undefined4 knownRegisters;
  int operandsLeft;
  int knownRegister;
  undefined2 addConstantParamResult;
  int operandCursor;
  int operationChunk;
  uint lookupKeyRegister;
  uint lookupKeyBank;
  longlong convertScratch;
  
  knownRegisters = _HashSetNew((*(uint *)(*(int *)(compileContext + 4) + 8) >> 5) + 1,regHashFunctionPtr,regEqualsFunctionPtr);
  for (operationChunk = **(int **)(compileContext + 0x20); operationChunk != 0; operationChunk = *(int *)(operationChunk + 8)) {
    operandCursor = operationChunk + 0xc;
    operandsLeft = _GetValidArgs(operationChunk);
    if (0 < operandsLeft) {
      do {
        if (*(int *)(operandCursor + 0x10) < 0) {
          lookupKeyBank = 4;
          lookupKeyRegister = 0;
          knownRegister = _HashSetGet(knownRegisters,&lookupKeyRegister);
          if ((knownRegister != 0) && (*(int *)(knownRegister + 0x14) != 0)) {
            *(uint *)(operandCursor + 0x10) = *(uint *)(operandCursor + 0x10) & 0x7fffffff;
            convertScratch = (longlong)(int)*(float *)(knownRegister + 0x18);
            *(short *)(operandCursor + 0x16) =
                 *(short *)(operandCursor + 0x16) + (short)(int)*(float *)(knownRegister + 0x18);
          }
        }
        operandWord = *(uint *)(operandCursor + 0x10);
        if (((((operandWord & 0x600000) == 0) && ((operandWord & 0x8000000) == 0)) && (-1 < (int)operandWord)) &&
           (((operandWord & 0x4000) == 0 && ((operandWord & 0x3000) == 0)))) {
          lookupKeyBank = operandWord >> 0x17 & 7;
          lookupKeyRegister = (uint)*(ushort *)(operandCursor + 0x16);
          knownRegister = _HashSetGet(knownRegisters,&lookupKeyRegister);
          if ((knownRegister != 0) && (*(int *)(knownRegister + 0x14) != 0)) {
            *(uint *)(operandCursor + 0x10) = *(uint *)(operandCursor + 0x10) & 0xfc7fffff | 0x1000000;
            addConstantParamResult = _AddConstantParam(compileContext,*(undefined4 *)(knownRegister + 8),
                                      *(undefined4 *)(knownRegister + 0xc),*(undefined4 *)(knownRegister + 0x10),
                                      *(undefined4 *)(knownRegister + 0x18),*(undefined4 *)(knownRegister + 0x1c),
                                      *(undefined4 *)(knownRegister + 0x20),*(undefined4 *)(knownRegister + 0x24));
            *(undefined2 *)(operandCursor + 0x16) = addConstantParamResult;
          }
        }
        operandsLeft = operandsLeft + -1;
        operandCursor = operandCursor + 8;
      } while (operandsLeft != 0);
    }
    if (*(int *)(operationChunk + 0x18) < 0) {
      lookupKeyBank = 4;
      lookupKeyRegister = 0;
      knownDestRegister = _HashSetGet(knownRegisters,&lookupKeyRegister);
      if ((knownDestRegister != 0) && (*(int *)(knownDestRegister + 0x14) != 0)) {
        *(uint *)(operationChunk + 0x18) = *(uint *)(operationChunk + 0x18) & 0x7fffffff;
        convertScratch = (longlong)(int)*(float *)(knownDestRegister + 0x18);
        *(short *)(operationChunk + 0x1a) = *(short *)(operationChunk + 0x1a) + (short)(int)*(float *)(knownDestRegister + 0x18);
      }
    }
    ((int (*)())_EmulateOp)(compileContext,operationChunk,knownRegisters);
  }
  ((int (*)())_ClearRegisterState)(knownRegisters);
  return _HashSetFree(knownRegisters);
}

/* _glpDCBAlloc @ 0x97c108e0 (68 bytes) */
int _glpDCBAlloc(byteCount)
  int byteCount;
{
  int allocation;
  uint alignedBlock;
  
  allocation = _malloc(byteCount + 0x3fU & 0xffffffe0);
  alignedBlock = 0;
  if (allocation != 0) {
    alignedBlock = allocation + 0x20U & 0xffffffe0;
    *(char *)(alignedBlock - 1) = (char)alignedBlock - (char)allocation;
  }
  return alignedBlock;
}

/* _glpDCBRealloc @ 0x97c10924 (256 bytes) */
int _glpDCBRealloc(block, newSize)
  int block;
  int newSize;
{
  uint glpDCBAllocResult;
  int byteOffset;
  uint newHeaderOffset;
  uint alignedBlock;
  int wordsLeft;
  int allocation;
  int wordIndex;
  uint oldHeaderOffset;
  
  if (newSize < 1) {
    if (block != 0) {
      ((int (*)())_glpDCBFree)(block);
    }
    alignedBlock = 0;
  }
  else {
    if (block == 0) {
      glpDCBAllocResult = ((int (*)())_glpDCBAlloc)(newSize);
      return glpDCBAllocResult;
    }
    oldHeaderOffset = (uint)*(byte *)(block + -1);
    allocation = _realloc(block - oldHeaderOffset,newSize + 0x3fU & 0xffffffe0);
    alignedBlock = 0;
    if (allocation != 0) {
      alignedBlock = allocation + 0x20U & 0xffffffe0;
      newHeaderOffset = alignedBlock - allocation & 0xff;
      if (newHeaderOffset != oldHeaderOffset) {
        wordsLeft = newSize + 3 >> 2;
        if (newHeaderOffset < oldHeaderOffset) {
          wordIndex = 0;
          if (0 < wordsLeft) {
            do {
              byteOffset = wordIndex * 4;
              wordIndex = wordIndex + 1;
              *(undefined4 *)(byteOffset + alignedBlock) = *(undefined4 *)(byteOffset + allocation + oldHeaderOffset);
              wordsLeft = wordsLeft + -1;
            } while (wordsLeft != 0);
          }
        }
        else {
          wordIndex = wordsLeft + -1;
          if (-1 < wordIndex) {
            do {
              byteOffset = wordIndex * 4;
              wordIndex = wordIndex + -1;
              *(undefined4 *)(byteOffset + alignedBlock) = *(undefined4 *)(byteOffset + allocation + oldHeaderOffset);
              wordsLeft = wordsLeft + -1;
            } while (wordsLeft != 0);
          }
        }
        *(char *)(alignedBlock - 1) = (char)(alignedBlock - allocation);
      }
    }
  }
  return alignedBlock;
}

/* _glpDCBFree @ 0x97c10a24 (12 bytes) */
int _glpDCBFree(block)
  int block;
{
  undefined4 freeReturn;
  
  _free(block - (uint)*(byte *)(block + -1));
  return freeReturn;
}

/* _PPParserMacroCreateFromMacro @ 0x97c10a30 (200 bytes) */
int _PPParserMacroCreateFromMacro(sourceMacro)
  undefined4 *sourceMacro;
{
  undefined4 *newMacro;
  int length;
  undefined4 allocation;
  uint loopIndex;
  
  newMacro = (undefined4 *)_PPParserMacroCreate();
  loopIndex = 0;
  length = _strlen(*sourceMacro);
  allocation = _calloc(length + 1,1);
  *newMacro = allocation;
  _memmove(allocation,*sourceMacro,length);
  length = _strlen(sourceMacro[1]);
  allocation = _calloc(length + 1,1);
  newMacro[1] = allocation;
  _memmove(allocation,sourceMacro[1],length);
  _PPParserMacroSetParamStringsCount(newMacro,sourceMacro[2]);
  if (sourceMacro[2] != 0) {
    do {
      _PPParserMacroSetParamString(newMacro,loopIndex,*(undefined4 *)(loopIndex * 4 + sourceMacro[3]));
      loopIndex = loopIndex + 1;
    } while (loopIndex < (uint)sourceMacro[2]);
  }
  return newMacro;
}

/* _PPParserIdentifierCreateFromIdentifier @ 0x97c10af8 (100 bytes) */
int _PPParserIdentifierCreateFromIdentifier(sourceIdentifier)
  undefined4 *sourceIdentifier;
{
  undefined1 copiedFlagByte;
  undefined4 copiedField4;
  int ppParserIdentifierCreateResult;
  undefined4 copiedKind;
  undefined4 copiedField18;
  
  ppParserIdentifierCreateResult = _PPParserIdentifierCreate();
  _PPParserIdentifierSetName(ppParserIdentifierCreateResult,*sourceIdentifier);
  copiedField18 = sourceIdentifier[6];
  copiedField4 = sourceIdentifier[1];
  copiedKind = sourceIdentifier[3];
  copiedFlagByte = *(undefined1 *)(sourceIdentifier + 4);
  *(undefined4 *)(ppParserIdentifierCreateResult + 8) = sourceIdentifier[2];
  *(undefined4 *)(ppParserIdentifierCreateResult + 4) = copiedField4;
  *(undefined4 *)(ppParserIdentifierCreateResult + 0xc) = copiedKind;
  *(undefined1 *)(ppParserIdentifierCreateResult + 0x10) = copiedFlagByte;
  *(undefined4 *)(ppParserIdentifierCreateResult + 0x18) = copiedField18;
  return ppParserIdentifierCreateResult;
}

/* _PPParserScopeCreateFromScope @ 0x97c10b5c (172 bytes) */
int _PPParserScopeCreateFromScope(sourceScope)
  int *sourceScope;
{
  undefined4 ppParserMacroCreateFromMacroResult;
  int scopeWord10;
  int newScope;
  undefined4 ppParserIdentifierCreateFromIdentifierResult;
  int scopeWord18;
  int macroCursor;
  int identifierCursor;
  
  identifierCursor = *sourceScope;
  macroCursor = sourceScope[2];
  newScope = _calloc(0x24,1);
  scopeWord18 = sourceScope[6];
  scopeWord10 = sourceScope[4];
  *(int *)(newScope + 0x14) = sourceScope[5];
  *(int *)(newScope + 0x10) = scopeWord10;
  *(int *)(newScope + 0x18) = scopeWord18;
  for (; identifierCursor != 0; identifierCursor = *(int *)(identifierCursor + 0x20)) {
    ppParserIdentifierCreateFromIdentifierResult = ((int (*)())_PPParserIdentifierCreateFromIdentifier)(identifierCursor);
    _PPParserScopeAddIdentifier(newScope,ppParserIdentifierCreateFromIdentifierResult);
  }
  for (; macroCursor != 0; macroCursor = *(int *)(macroCursor + 0x1c)) {
    ppParserMacroCreateFromMacroResult = ((int (*)())_PPParserMacroCreateFromMacro)(macroCursor);
    _PPParserScopeAddMacro(newScope,ppParserMacroCreateFromMacroResult);
  }
  return newScope;
}

/* _PPParserInitFromParent @ 0x97c10c08 (16 bytes) */
int _PPParserInitFromParent(parser, parentParser)
  int parser;
  int parentParser;
{
  return _memcpy(parser + 0x450,parentParser + 0x450,0x3c);
}

/* _PPParserInherit @ 0x97c10c18 (44 bytes) */
int _PPParserInherit(parser, sourceParser)
  int parser;
  int sourceParser;
{
  undefined4 inheritedWord30;
  undefined4 inheritedWord20;
  undefined4 inheritedWord28;
  undefined4 inheritedWord24;
  
  inheritedWord30 = *(undefined4 *)(sourceParser + 0x30);
  inheritedWord20 = *(undefined4 *)(sourceParser + 0x20);
  inheritedWord24 = *(undefined4 *)(sourceParser + 0x24);
  inheritedWord28 = *(undefined4 *)(sourceParser + 0x28);
  *(undefined4 *)(parser + 0x2c) = *(undefined4 *)(sourceParser + 0x2c);
  *(undefined4 *)(parser + 0x30) = inheritedWord30;
  *(undefined4 *)(parser + 0x20) = inheritedWord20;
  *(undefined4 *)(parser + 0x24) = inheritedWord24;
  *(undefined4 *)(parser + 0x28) = inheritedWord28;
  return;
}

/* _PPParserDeclareNVAddressRegisters @ 0x97c10c44 (92 bytes) */
int _PPParserDeclareNVAddressRegisters(parser)
  int parser;
{
  int ppParserIdentifierCreateResult;
  
  ppParserIdentifierCreateResult = _PPParserIdentifierCreate();
  _PPParserIdentifierSetName(ppParserIdentifierCreateResult,"a0");
  *(undefined4 *)(ppParserIdentifierCreateResult + 0xc) = 0xffffffff;
  *(undefined4 *)(ppParserIdentifierCreateResult + 8) = 0;
  return _PPParserScopeAddIdentifier(*(undefined4 *)(parser + 0x44c),ppParserIdentifierCreateResult);
}

/* _PPParserParseBlock @ 0x97c10ca0 (236 bytes) */
int _PPParserParseBlock(parser)
  int parser;
{
  int compareResult;
  int part;
  int resultCode;
  undefined4 ppParserScopeCreateResult;
  char token [260];
  
  part = _PPParserGetPart(parser,token,0);
  resultCode = 0x2d;
  if (part != 0) {
    compareResult = _memcmp(token,"START",6);
    resultCode = 7;
    if (compareResult == 0) {
      ppParserScopeCreateResult = _PPParserScopeCreate(parser);
      _PPParserAddScope(parser,ppParserScopeCreateResult);
      resultCode = 0;
    }
    compareResult = _memcmp(token,"END",4);
    if (compareResult == 0) {
      _PPParserRemoveScope(parser,*(undefined4 *)(parser + 0x44c));
      resultCode = 0;
    }
    if (resultCode == 0) {
      part = _PPParserGetPart(parser,token,0);
      resultCode = 0x2d;
      if ((part != 0) && (resultCode = 0x1e, token[0] == ';')) {
        resultCode = 0;
      }
    }
  }
  return resultCode;
}

/* _PPParserParseDefaultArray @ 0x97c10d8c (240 bytes) */
int _PPParserParseDefaultArray(parser, arraySize)
  undefined4 parser;
  int *arraySize;
{
  int integer;
  int part;
  int resultCode;
  char token [260];
  
  part = _PPParserGetPart(parser,token,0);
  resultCode = 0x2d;
  if ((part != 0) && (resultCode = 0xb, token[0] == '[')) {
    part = _PPParserGetPart(parser,token,0);
    resultCode = 0x2d;
    if (part != 0) {
      if (token[0] == ']') {
        *arraySize = 0;
      }
      else {
        _PPParserReturnPart(parser);
        integer = _PPParserGetInteger(parser,arraySize);
        if (integer != 0) {
          return integer;
        }
        if (*arraySize < 0) {
          return 0x23;
        }
        part = _PPParserGetPart(parser,token,0);
        if (part == 0) {
          return 0x2d;
        }
        if (token[0] != ']') {
          return 0xb;
        }
      }
      resultCode = 0;
    }
  }
  return resultCode;
}

/* _PPParserParseRangeArray @ 0x97c10e7c (320 bytes) */
int _PPParserParseRangeArray(parser, rangeStart, rangeEnd)
  undefined4 parser;
  int *rangeStart;
  int *rangeEnd;
{
  int compareResult;
  int part;
  int resultCode;
  char token [256];
  
  part = _PPParserGetPart(parser,token,0);
  resultCode = 0x2d;
  if ((part != 0) && (resultCode = 0xb, token[0] == '[')) {
    resultCode = _PPParserGetInteger(parser,rangeStart);
    if ((resultCode == 0) && (resultCode = 0x23, -1 < *rangeStart)) {
      part = _PPParserGetPart(parser,token,0);
      resultCode = 0x2d;
      if (part != 0) {
        if (token[0] == ']') {
          resultCode = 0;
          *rangeEnd = *rangeStart;
        }
        else {
          compareResult = _memcmp(token,"..",3);
          resultCode = 0xb;
          if (((compareResult == 0) && (resultCode = _PPParserGetInteger(parser,rangeEnd), resultCode == 0)) &&
             (resultCode = 0x23, *rangeStart <= *rangeEnd)) {
            part = _PPParserGetPart(parser,token,0);
            resultCode = 0x2d;
            if ((part != 0) && (resultCode = 0xb, token[0] == ']')) {
              resultCode = 0;
            }
          }
        }
      }
    }
  }
  return resultCode;
}

/* _PPParserParseIndirectArray @ 0x97c10fbc (620 bytes) */
int _PPParserParseIndirectArray(parser, indexWord, outOffset)
  int parser;
  uint *indexWord;
  int *outOffset;
{
  int integer2;
  int part2;
  int integer;
  int part;
  bool offsetOutOfRange;
  uint newIndexWord;
  int addressIdentifier;
  int componentIndex;
  undefined4 resultCode;
  char token [256];
  undefined4 relativeOffset;
  
  part = _PPParserGetPart(parser,token,0);
  if (part == 0) {
    return 0x2d;
  }
  if (token[0] != '[') {
    return 0xb;
  }
  integer = _PPParserGetInteger(parser,outOffset);
  if (integer == 0) {
    if (*outOffset < 0) {
      return 0x23;
    }
  }
  else {
    _PPParserReturnPart(parser);
    part = _PPParserGetPart(parser,token,0);
    if (part == 0) {
      return 0x2d;
    }
    addressIdentifier = _PPParserScopeFindIdentifier(*(undefined4 *)(parser + 0x44c),token);
    if (addressIdentifier == 0) {
      return 0x1a;
    }
    if (*(int *)(addressIdentifier + 0xc) != -1) {
      return 0x16;
    }
    part2 = _PPParserGetPart(parser,token,0);
    if (part2 == 0) {
      return 0x2d;
    }
    if (token[0] != '.') {
      return 0xd;
    }
    if (part2 != 1) {
      return 0xd;
    }
    part2 = _PPParserGetPart(parser,token,0);
    if (part2 == 0) {
      return 0x2d;
    }
    if (part2 != 1) {
      return 0xd;
    }
    if ((*(uint *)(parser + 0x48c) & 0x10) == 0) {
      if (token[0] != 'x') {
        return 0xd;
      }
      newIndexWord = *indexWord & 0xcfffffff;
    }
    else if (token[0] == 'x') {
      newIndexWord = *indexWord & 0xcfffffff;
    }
    else if (token[0] < 'y') {
      if (token[0] != 'w') {
        return 0xd;
      }
      newIndexWord = *indexWord | 0x30000000;
    }
    else {
      if (token[0] == 'y') {
        newIndexWord = *indexWord;
        componentIndex = 1;
      }
      else {
        if (token[0] != 'z') {
          return 0xd;
        }
        newIndexWord = *indexWord;
        componentIndex = 2;
      }
      newIndexWord = componentIndex << 0x1c | newIndexWord & 0xcfffffff;
    }
    *indexWord = newIndexWord;
    integer2 = _PPParserGetInteger(parser,&relativeOffset);
    if (integer2 != 0) {
      _PPParserReturnPart(parser);
      relativeOffset = 0;
    }
    if ((*(uint *)(parser + 0x48c) & 0x10) == 0) {
      offsetOutOfRange = 0x7f < relativeOffset + 0x40U;
    }
    else {
      offsetOutOfRange = 0x1ff < relativeOffset + 0x100U;
    }
    if (offsetOutOfRange) {
      return 0x24;
    }
    *(undefined1 *)((int)indexWord + 3) = (undefined1)relativeOffset;
    *indexWord = (*(uint *)(addressIdentifier + 8) & 1) << 0x1e | *indexWord & 0xbfffffff | 0x80000000;
  }
  part = _PPParserGetPart(parser,token,0);
  resultCode = 0x2d;
  if ((part != 0) && (resultCode = 0xb, token[0] == ']')) {
    resultCode = 0;
  }
  return resultCode;
}

/* _PPParserParseAddressDeclaration @ 0x97c11228 (340 bytes) */
int _PPParserParseAddressDeclaration(parser)
  int parser;
{
  int ppParserIdentifierCreateResult;
  int ppParserValidateNameResult;
  int part;
  int scope;
  int ppParserScopeAddIdentifierResult;
  uint loopIndex;
  uint usageIndex;
  char token [256];
  undefined4 addressUsage [7];
  
  loopIndex = 0;
  while( true ) {
    part = _PPParserGetPart(parser,token,0);
    if (part == 0) {
      return 0x2d;
    }
    ppParserValidateNameResult = _PPParserValidateName(parser,token);
    if (ppParserValidateNameResult != 0) {
      return 0x12;
    }
    ppParserIdentifierCreateResult = _PPParserIdentifierCreate();
    _PPParserIdentifierSetName(ppParserIdentifierCreateResult,token);
    *(undefined4 *)(ppParserIdentifierCreateResult + 0xc) = 0xffffffff;
    *(uint *)(ppParserIdentifierCreateResult + 8) = *(int *)(*(int *)(parser + 0x44c) + 0x10) + loopIndex;
    ppParserScopeAddIdentifierResult = _PPParserScopeAddIdentifier(*(undefined4 *)(parser + 0x44c),ppParserIdentifierCreateResult);
    if (ppParserScopeAddIdentifierResult != 0) {
      _PPParserIdentifierFree(ppParserIdentifierCreateResult);
      return 0x1c;
    }
    loopIndex = loopIndex + 1;
    part = _PPParserGetPart(parser,token,0);
    if (part == 0) break;
    if (token[0] == ';') {
      scope = *(int *)(parser + 0x44c);
      if (*(uint *)(parser + 0x46c) < *(int *)(scope + 0x10) + loopIndex) {
        return 0x37;
      }
      usageIndex = 0;
      if (loopIndex != 0) {
        while( true ) {
          addressUsage[0] = *(undefined4 *)(scope + 0x10);
          _PPStreamAddAddressUsage(*(undefined4 *)(parser + 0x1c),addressUsage);
          usageIndex = usageIndex + 1;
          *(int *)(*(int *)(parser + 0x44c) + 0x10) =
               *(int *)(*(int *)(parser + 0x44c) + 0x10) + 1;
          if (loopIndex <= usageIndex) break;
          scope = *(int *)(parser + 0x44c);
        }
      }
      return 0;
    }
    if (token[0] != ',') {
      return 0x1f;
    }
  }
  return 0x2d;
}

/* _PPParserParseBranchLabel @ 0x97c1137c (68 bytes) */
int _PPParserParseBranchLabel(parser, labelBuffer, outLength)
  undefined4 parser;
  undefined4 labelBuffer;
  int *outLength;
{
  int part;
  undefined4 resultCode;
  
  part = _PPParserGetPart(parser,labelBuffer,0);
  *outLength = part;
  resultCode = 0x2d;
  if (part != 0) {
    resultCode = 0;
  }
  return resultCode;
}

/* _PPParserParseLabel @ 0x97c113c0 (256 bytes) */
int _PPParserParseLabel(parser, labelName, nameLength)
  int parser;
  undefined4 labelName;
  int nameLength;
{
  int compareLength;
  int nameCompare;
  int stream;
  int compareResult;
  int partLength;
  undefined4 resultCode;
  int labelChunk;
  char token [264];
  
  partLength = _PPParserGetPart(parser,token,0);
  resultCode = 3;
  if (partLength != 0) {
    if (token[0] == ':') {
      stream = *(int *)(parser + 0x1c);
      labelChunk = **(int **)(stream + 0x24);
      if (labelChunk != 0) {
        do {
          if ((nameLength == *(int *)(labelChunk + 0x10)) &&
             (nameCompare = _strncmp(labelName,labelChunk + 0x14,nameLength), nameCompare == 0)) {
            return 0x1d;
          }
          labelChunk = *(int *)(labelChunk + 8);
        } while (labelChunk != 0);
        stream = *(int *)(parser + 0x1c);
      }
      compareLength = nameLength;
      if (6 < nameLength) {
        compareLength = 6;
      }
      compareResult = _memcmp(labelName,"start",compareLength);
      if (compareResult == 0) {
        *(undefined1 *)(parser + 0x440) = 1;
      }
      _PPStreamAddLabel(stream,labelName,nameLength);
      resultCode = 0;
    }
    else {
      _PPParserReturnPart(parser);
      resultCode = 3;
    }
  }
  return resultCode;
}

/* _PPParserParseAddressDestination @ 0x97c114c0 (348 bytes) */
int _PPParserParseAddressDestination(parser, destWord)
  int parser;
  uint *destWord;
{
  uint parserFlags;
  int part2;
  undefined2 registerNumber;
  int ppParserScopeFindIdentifierResult;
  int resultCode;
  int part;
  uint destWord1;
  char token [256];
  
  part2 = _PPParserGetPart(parser,token,0);
  resultCode = 0x2d;
  if (part2 != 0) {
    ppParserScopeFindIdentifierResult = _PPParserScopeFindIdentifier(*(undefined4 *)(parser + 0x44c),token);
    resultCode = 0x19;
    if ((ppParserScopeFindIdentifierResult != 0) && (resultCode = 0x16, *(int *)(ppParserScopeFindIdentifierResult + 0xc) == -1)) {
      destWord1 = *destWord;
      *destWord = destWord1 | 0x2000;
      if ((*(uint *)(parser + 0x48c) & 0x10) == 0) {
        destWord1 = destWord1 & 0xfffe3fff | 0x2000;
      }
      else {
        destWord1 = destWord1 | 0x1e000;
      }
      *destWord = destWord1;
      part = _PPParserGetPart(parser,token,0);
      resultCode = 0x2d;
      if (part != 0) {
        if ((token[0] == '.') && (part == 1)) {
          resultCode = _PPParserParseDestinationMask(parser,destWord);
          if (resultCode != 0) {
            return resultCode;
          }
          parserFlags = *(uint *)(parser + 0x48c);
          if (((parserFlags & 0x10) == 0) && ((*destWord & 0x1e000) != 0x2000)) {
            return 0xc;
          }
        }
        else {
          if ((*(uint *)(parser + 0x48c) & 0x10) == 0) {
            return 0xc;
          }
          _PPParserReturnPart(parser);
          parserFlags = *(uint *)(parser + 0x48c);
        }
        if (((parserFlags & 0x10) == 0) ||
           (resultCode = ((int (*)())_PPParserParseBranchCondition)(parser,destWord,0), resultCode == 0)) {
          registerNumber = *(undefined2 *)(ppParserScopeFindIdentifierResult + 10);
          *destWord = *destWord & 0xfff1ffff | 0x80000;
          resultCode = 0;
          *(undefined2 *)((int)destWord + 6) = registerNumber;
        }
      }
    }
  }
  return resultCode;
}

/* _PPParserParseBranchCondition @ 0x97c1161c (972 bytes) */
int _PPParserParseBranchCondition(parser, conditionWord, opcode)
  int parser;
  uint *conditionWord;
  int opcode;
{
  int swizzleComponent;
  uint swizzleIndex;
  bool needsParens;
  bool isSwizzleLetter;
  char swizzleChar;
  uint patchedWord;
  uint newConditionWord;
  int tokenLength;
  int conditionCode;
  char *swizzleCursor;
  char token [256];
  
  needsParens = opcode != 0x55;
  if (needsParens) {
    tokenLength = _PPParserGetPart(parser,token,0);
    if (tokenLength == 0) {
      return 0x2d;
    }
    if (token[0] != '(') {
      _PPParserReturnPart(parser);
      return 0;
    }
  }
  tokenLength = _PPParserGetPart(parser,token,0);
  if (tokenLength == 0) {
    return 0x2d;
  }
  if (*(int *)(parser + 0x48c) == 0x34) {
    if (1 < tokenLength - 2U) {
      return 0x10;
    }
  }
  else if (tokenLength != 2) {
    return 0x10;
  }
  conditionCode = _memcmp(token,"TR",2);
  if (conditionCode == 0) {
    newConditionWord = *conditionWord & 0x8fffffff;
  }
  else {
    conditionCode = _memcmp(token,"EQ",2);
    if (conditionCode == 0) {
      newConditionWord = *conditionWord;
      conditionCode = 1;
    }
    else {
      conditionCode = _memcmp(token,"GE",2);
      if (conditionCode == 0) {
        newConditionWord = *conditionWord;
        conditionCode = 2;
      }
      else {
        conditionCode = _memcmp(token,"GT",2);
        if (conditionCode == 0) {
          newConditionWord = *conditionWord;
          conditionCode = 3;
        }
        else {
          conditionCode = _memcmp(token,"LE",2);
          if (conditionCode == 0) {
            newConditionWord = *conditionWord;
            conditionCode = 4;
          }
          else {
            conditionCode = _memcmp(token,"LT",2);
            if (conditionCode == 0) {
              newConditionWord = *conditionWord;
              conditionCode = 5;
            }
            else {
              conditionCode = _memcmp(token,"NE",2);
              if (conditionCode != 0) {
                conditionCode = _memcmp(token,"FL",2);
                if (conditionCode != 0) {
                  return 0x10;
                }
                newConditionWord = *conditionWord | 0x70000000;
                goto storeConditionWord;
              }
              newConditionWord = *conditionWord;
              conditionCode = 6;
            }
          }
        }
      }
    }
    newConditionWord = conditionCode << 0x1c | newConditionWord & 0x8fffffff;
  }
storeConditionWord:
  *conditionWord = newConditionWord;
  if ((*(int *)(parser + 0x48c) == 0x34) && (tokenLength == 3)) {
    if (token[2] == '0') {
      newConditionWord = *conditionWord & 0x7fffffff;
    }
    else {
      if (token[2] != '1') goto setTokenLength;
      newConditionWord = *conditionWord | 0x80000000;
    }
    *conditionWord = newConditionWord;
  }
setTokenLength:
  tokenLength = _PPParserGetPart(parser,token,0);
  if (tokenLength == 0) {
    return 0x2d;
  }
  if ((needsParens) && (token[0] == ')')) {
    return 0;
  }
  if ((token[0] != '.') || (tokenLength != 1)) {
    return 0x10;
  }
  tokenLength = _PPParserGetPart(parser,token,0);
  if (tokenLength == 0) {
    return 0x2d;
  }
  if ((tokenLength != 1) && (tokenLength != 4)) {
    return 0x10;
  }
  swizzleIndex = 0;
  swizzleCursor = token;
  do {
    swizzleChar = *swizzleCursor;
    if (swizzleChar == 'x') {
      swizzleComponent = 0;
    }
    else {
      if (swizzleChar < 'y') {
        isSwizzleLetter = swizzleChar == 'w';
        swizzleComponent = 3;
      }
      else {
        if (swizzleChar == 'y') {
          swizzleComponent = 1;
          goto checkSwizzleIndex;
        }
        isSwizzleLetter = swizzleChar == 'z';
        swizzleComponent = 2;
      }
      if (!isSwizzleLetter) {
        return 0x10;
      }
    }
checkSwizzleIndex:
    if (swizzleIndex == 1) {
      patchedWord = swizzleComponent << 0x18 | *conditionWord & 0xfcffffff;
loopStoreConditionWord:
      *conditionWord = patchedWord;
    }
    else {
      if (swizzleIndex == 0) {
        patchedWord = swizzleComponent << 0x1a | *conditionWord & 0xf3ffffff;
        goto loopStoreConditionWord;
      }
      if (swizzleIndex == 2) {
        patchedWord = swizzleComponent << 0x16 | *conditionWord & 0xff3fffff;
        goto loopStoreConditionWord;
      }
      if (swizzleIndex == 3) {
        patchedWord = swizzleComponent << 0x14 | *conditionWord & 0xffcfffff;
        goto loopStoreConditionWord;
      }
    }
    if (tokenLength == 4) {
      swizzleCursor = swizzleCursor + 1;
    }
    swizzleIndex = swizzleIndex + 1;
    if (3 < swizzleIndex) {
      if (needsParens) {
        tokenLength = _PPParserGetPart(parser,token,0);
        if (tokenLength == 0) {
          return 0x2d;
        }
        if (token[0] != ')') {
          return 0x10;
        }
      }
      return 0;
    }
  } while( true );
}

/* _PPParserParseAddressSourceVar @ 0x97c119e8 (140 bytes) */
int _PPParserParseAddressSourceVar(parser, sourceWord)
  int parser;
  uint *sourceWord;
{
  int part;
  undefined2 registerNumber;
  undefined4 resultCode;
  int ppParserScopeFindIdentifierResult;
  undefined1 token [260];
  
  part = _PPParserGetPart(parser,token,0);
  resultCode = 0x2d;
  if (part != 0) {
    ppParserScopeFindIdentifierResult = _PPParserScopeFindIdentifier(*(undefined4 *)(parser + 0x44c),token);
    resultCode = 0x1a;
    if ((ppParserScopeFindIdentifierResult != 0) && (resultCode = 0x16, *(int *)(ppParserScopeFindIdentifierResult + 0xc) == -1)) {
      registerNumber = *(undefined2 *)(ppParserScopeFindIdentifierResult + 10);
      *sourceWord = *sourceWord & 0xfc7fffff | 0x2000000;
      resultCode = 0;
      *(undefined2 *)((int)sourceWord + 6) = registerNumber;
    }
  }
  return resultCode;
}

/* _PPParserParseMacroDeclaration @ 0x97c11a74 (720 bytes) */
int _PPParserParseMacroDeclaration(parser)
  int *parser;
{
  int replaceText;
  int part;
  int currentLine;
  undefined4 resultCode;
  int macro;
  uint lastParamIndex;
  uint paramCount;
  uint loopIndex;
  int replaceLength;
  char token [256];
  int savedPosition;
  int savedLine;
  
  part = _PPParserGetPart(parser,token,0);
  resultCode = 0x2d;
  if ((part != 0) && (resultCode = 10, token[0] == '{')) {
    part = _PPParserGetPart(parser,token,0);
    resultCode = 0x2d;
    if (part != 0) {
      macro = _PPParserMacroCreate();
      _PPParserMacroSetSearchString(parser,macro,token,part);
      savedPosition = parser[3];
      savedLine = parser[4];
      lastParamIndex = 0;
      while( true ) {
        part = _PPParserGetPart(parser,token,0);
        if (part == 0) {
          return 0x2d;
        }
        paramCount = lastParamIndex + 1;
        part = _PPParserGetPart(parser,token,0);
        if (part == 0) {
          return 0x2d;
        }
        if (token[0] == '}') break;
        lastParamIndex = paramCount;
        if (token[0] != ',') {
          return 0x1f;
        }
      }
      loopIndex = 0;
      _PPParserMacroSetParamStringsCount(macro,paramCount);
      parser[4] = savedLine;
      parser[3] = savedPosition;
      if (paramCount != 0) {
        do {
          _PPParserGetPart(parser,token,0);
          _PPParserMacroSetParamString(macro,loopIndex,token);
          if (loopIndex != lastParamIndex) {
            _PPParserGetPart(parser,token,0);
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex < paramCount);
      }
      part = _PPParserGetPart(parser,token,0);
      resultCode = 0x2d;
      if ((part != 0) && (resultCode = 10, token[0] == '}')) {
        part = _PPParserGetPart(parser,token,0);
        resultCode = 0x2d;
        if ((part != 0) && (resultCode = 10, token[0] == '=')) {
          part = _PPParserGetPart(parser,token,0);
          resultCode = 0x2d;
          if ((part != 0) && (resultCode = 10, token[0] == '{')) {
            currentLine = parser[4];
            *(int *)(macro + 0x10) = parser[3];
            *(int *)(macro + 0x14) = currentLine;
            savedPosition = parser[3];
            savedLine = parser[4];
            while( true ) {
              part = _PPParserGetPart(parser,token,0);
              resultCode = 0x2d;
              if (part == 0) break;
              if (token[0] == '}') {
                replaceLength = (parser[3] - savedPosition) + -2;
                replaceText = _malloc((parser[3] - savedPosition) + -1);
                _memmove(replaceText,*parser + savedPosition,replaceLength);
                *(undefined1 *)(replaceText + replaceLength) = 0;
                _PPParserMacroSetReplaceString(parser,macro,replaceText);
                part = _PPParserGetPart(parser,token,0);
                if (part == 0) {
                  return 0x2d;
                }
                if (token[0] != ';') {
                  return 0x1e;
                }
                _PPParserScopeAddMacro(parser[0x113],macro);
                return 0;
              }
            }
          }
        }
      }
    }
  }
  return resultCode;
}

/* _PPParserExpandMacro @ 0x97c11d44 (664 bytes) */
int _PPParserExpandMacro(parser, macro)
  int parser;
  undefined4 *macro;
{
  undefined4 allocation2;
  undefined4 ppParserScopeCreateFromScopeResult;
  int childParser;
  undefined4 length;
  int replaceString;
  int part;
  int ppParserParseResult;
  undefined4 resultCode;
  undefined4 *argumentStrings;
  undefined4 callLine;
  undefined4 callPosition;
  int commaCount;
  uint argCount;
  uint loopIndex;
  undefined4 *argumentCursor;
  char token [256];
  undefined4 savedPosition;
  undefined4 savedLine;
  
  savedPosition = *(undefined4 *)(parser + 0xc);
  savedLine = *(undefined4 *)(parser + 0x10);
  commaCount = 0;
  do {
    part = _PPParserGetPart(parser,token,0);
    if (part == 0) {
      return 0x2d;
    }
    if (token[0] == ',') {
      commaCount = commaCount + 1;
    }
  } while (token[0] != ';');
  argCount = commaCount + 1;
  resultCode = 0x26;
  if (argCount == macro[2]) {
    loopIndex = 0;
    argumentStrings = (undefined4 *)_calloc(4,argCount);
    *(undefined4 *)(parser + 0x10) = savedLine;
    *(undefined4 *)(parser + 0xc) = savedPosition;
    if (argCount != 0) {
      do {
        allocation2 = _calloc(0x100,1);
        argumentStrings[loopIndex] = allocation2;
        _PPParserGetPart(parser,token,0);
        if ((token[0] != ',') && (token[0] != ';')) {
          while( true ) {
            _strcat(argumentStrings[loopIndex],token);
            _PPParserGetPart(parser,token,0);
            if ((token[0] == ',') || (token[0] == ';')) break;
            _strcat(argumentStrings[loopIndex]," ");
          }
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < argCount);
    }
    replaceString = _PPParserMacroGetReplaceString(macro,*(undefined4 *)(parser + 0x48c),argumentStrings,0);
    loopIndex = 0;
    allocation2 = _malloc(replaceString + 1);
    _PPParserMacroGetReplaceString(macro,*(undefined4 *)(parser + 0x48c),argumentStrings,allocation2);
    argumentCursor = argumentStrings;
    if (argCount != 0) {
      do {
        loopIndex = loopIndex + 1;
        _free(*argumentCursor);
        argumentCursor = argumentCursor + 1;
      } while (loopIndex < argCount);
    }
    _free(argumentStrings);
    childParser = _PPParserCreate(*(undefined4 *)(parser + 0x48c));
    ((int (*)())_PPParserInitFromParent)(childParser,parser);
    ((int (*)())_PPParserInherit)(childParser,parser);
    ppParserScopeCreateFromScopeResult = ((int (*)())_PPParserScopeCreateFromScope)(*(undefined4 *)(parser + 0x44c));
    _PPParserAddScope(childParser,ppParserScopeCreateFromScopeResult);
    _PPParserAttachString(childParser,allocation2,0);
    _PPParserAttachStream(childParser,*(undefined4 *)(parser + 0x1c));
    callPosition = *(undefined4 *)(parser + 0xc);
    *(byte *)(childParser + 0x441) = *(byte *)(childParser + 0x441) | 1;
    callLine = *(undefined4 *)(parser + 0x10);
    *(undefined4 *)(childParser + 0x14) = callPosition;
    *(undefined4 *)(childParser + 0x18) = callLine;
    *(byte *)(childParser + 0x441) = *(byte *)(childParser + 0x441) | 2;
    ppParserParseResult = _PPParserParse(childParser);
    if (ppParserParseResult == 0) {
      ((int (*)())_PPParserInherit)(parser,childParser);
      _PPParserFree(childParser);
      _free(allocation2);
      resultCode = 0;
    }
    else {
      ((int (*)())_PPParserBuildErrorString)(childParser,ppParserParseResult,*macro);
      length = _strlen(childParser + 0x3c);
      _memmove(parser + 0x3c,childParser + 0x3c,length);
      _PPParserFree(childParser);
      resultCode = 2;
    }
  }
  return resultCode;
}

/* _PPParserBuildErrorString @ 0x97c11fdc (912 bytes) */
int _PPParserBuildErrorString(parser, errorCode, macroName)
  int parser;
  undefined4 errorCode;
  int macroName;
{
  char *message;
  int lineNumber;
  undefined1 characterState [16];
  undefined1 hintToken [264];
  
  switch(errorCode) {
  default:
    message = "";
    break;
  case 4:
    message = "missing or invalid version";
    break;
  case 5:
    message = "unrecognised option";
    break;
  case 6:
    message = "unrecognised statement";
    break;
  case 7:
    message = "unrecognised block parameter";
    break;
  case 8:
    message = "unexpected option";
    break;
  case 9:
    message = "unexpected statement";
    break;
  case 10:
    message = "malformed declaration";
    break;
  case 0xb:
    message = "malformed array specifier";
    break;
  case 0xc:
    message = "malformed destination mask";
    break;
  case 0xd:
    message = "malformed source swizzle";
    break;
  case 0xe:
    message = "malformed source texture";
    break;
  case 0xf:
    message = "malformed extended swizzle code";
    break;
  case 0x10:
    message = "invalid condition mask";
    break;
  case 0x11:
    message = "invalid texture coordinate plane";
    break;
  case 0x12:
    message = "invalid identifier name";
    break;
  case 0x13:
    message = "invalid attribute pair";
    break;
  case 0x14:
    message = "invalid swizzle for scalar op";
    break;
  case 0x15:
    message = "invalid number";
    break;
  case 0x16:
    message = "invalid address identifier";
    break;
  case 0x17:
    message = "invalid source identifier";
    break;
  case 0x18:
    message = "invalid dest identifier";
    break;
  case 0x19:
    message = "undefined destination identifier";
    break;
  case 0x1a:
    message = "undefined source identifier";
    break;
  case 0x1b:
    message = "undefined branch label";
    break;
  case 0x1c:
    message = "an identifier with this name already exists";
    break;
  case 0x1d:
    message = "duplicate branch label";
    break;
  case 0x1e:
    message = "missing semicolon";
    break;
  case 0x1f:
    message = "missing comma";
    break;
  case 0x20:
    message = "identifier is not an array";
    break;
  case 0x21:
    message = "identifier is an array";
    break;
  case 0x22:
    message = "use of result.position illegal with ARB_position_invariant";
    break;
  case 0x23:
    message = "out of range array index";
    break;
  case 0x24:
    message = "out of range indirect offset";
    break;
  case 0x25:
    message = "incorrect array component count";
    break;
  case 0x26:
    message = "incorrect argument count for macro";
    break;
  case 0x27:
    message = "conflicting option specification";
    break;
  case 0x28:
    message = "conflicting texture target";
    break;
  case 0x29:
    message = "impossible array";
    break;
  case 0x2a:
    message = "precision qualifier only allowed for temporaries or outputs";
    break;
  case 0x2b:
    message = "unpack instructions cannot take SHORT source";
    break;
  case 0x2c:
    message = "pack instructions cannot take SHORT destination";
    break;
  case 0x2d:
    message = "unexpected end of program";
    break;
  case 0x2e:
    message = "program env limit exceeded";
    break;
  case 0x2f:
    message = "program local limit exceeded";
    break;
  case 0x30:
    message = "program matrices limit exceeded";
    break;
  case 0x31:
    message = "program matrix stack depth exceeded";
    break;
  case 0x32:
    message = "program instruction count exceeded";
    break;
  case 0x33:
    message = "program temporary count exceeded";
    break;
  case 0x34:
    message = "program parameter count exceeded";
    break;
  case 0x35:
  case 0x36:
    message = "program attribute count exceeded";
    break;
  case 0x37:
    message = "program address registers limit exceeded";
    break;
  case 0x38:
    message = "texture unit limit exceeded";
    break;
  case 0x39:
    message = "vertex unit limit exceeded";
    break;
  case 0x3a:
    message = "palette matrix limit exceeded";
    break;
  case 0x3b:
    message = "clip plane limit exceeded";
    break;
  case 0x3c:
    message = "light limit exceeded";
    break;
  case 0x3d:
    message = "vertex attribute limit exceeded";
  }
  _PPParserReturnPart(parser);
  _PPParserGetPart(parser,hintToken,0);
  _PPParserReturnCharacter(parser,characterState);
  lineNumber = *(int *)(parser + 0x10) + 1;
  _PPParserGetCharacter(parser,characterState);
  if (macroName == 0) {
    _sprintf((char *)(parser + 0x3c),"Error on line %u: %s (hint: \'%s\')",lineNumber,message,hintToken
            );
  }
  else {
    _sprintf((char *)(parser + 0x3c),"Error in macro %s on line %u: %s (hint: \'%s\')",macroName,
             lineNumber,message,hintToken);
  }
  return;
}

/* _pow_10 @ 0x97c12464 (156 bytes) */
double _pow_10(int exponent)
{
  undefined *tableEntry;
  double result;
  
  result = DOUBLE_97c30a60;
  if (exponent < 1) {
    if (-1 < exponent) {
      return DOUBLE_97c30a60;
    }
    for (; exponent < -0x20; exponent = exponent + 0x20) {
      result = result * DOUBLE_97c30aa8;
    }
    tableEntry = &_down_1 + exponent * -8;
  }
  else {
    for (; 0x20 < exponent; exponent = exponent + -0x20) {
      result = result * DOUBLE_97c30ab0;
    }
    tableEntry = &_up_0 + exponent * 8;
  }
  return result * *(double *)(tableEntry + -8);
}

/* _glp_strtod @ 0x97c12500 (824 bytes) */
double _glp_strtod(byte *str,undefined4 *endPtr)
{
  byte *exponentDigitCursor;
  byte *exponentStart;
  byte *fractionDigitCursor;
  double exponentValue;
  double fraction;
  double pow_10Result;
  bool isDecimalPoint;
  bool sawDigits;
  bool isExponentNegative;
  bool isNegative;
  int digitsLeft;
  byte currentChar;
  byte *integerDigitCursor;
  byte *fractionStart;
  double value;
  double placeValue;
  double exponentPlaceValue;
  byte *endCursor;
  
  isNegative = false;
  isExponentNegative = false;
  sawDigits = false;
  if (*str == 0x2b) {
loopSetStr:
    str = str + 1;
  }
  else if (*str == 0x2d) {
    isNegative = true;
    goto loopSetStr;
  }
  currentChar = *str;
  isDecimalPoint = currentChar == 0x2e;
  endCursor = str;
  value = DOUBLE_97c30a48;
  if (currentChar == 0) {
loopCheckIsDecimalPoint:
    if (isDecimalPoint) goto setFractionStart;
  }
  else {
    if (!isDecimalPoint) {
      if ((currentChar != 0x65) && (integerDigitCursor = str, currentChar != 0x45)) {
        while (currentChar - 0x30 < 10) {
          currentChar = integerDigitCursor[1];
          integerDigitCursor = integerDigitCursor + 1;
        }
        if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
          endCursor = integerDigitCursor;
        }
        integerDigitCursor = integerDigitCursor + -1;
        if (str <= integerDigitCursor) {
          digitsLeft = (int)integerDigitCursor - (int)(str + -1);
          placeValue = DOUBLE_97c30a60;
          do {
            currentChar = *integerDigitCursor;
            integerDigitCursor = integerDigitCursor + -1;
            value = ((double)CONCAT44(0x43300000,(int)(char)currentChar - 0x30U ^ 0x80000000) -
                    DOUBLE_97c30a58) * placeValue + value;
            placeValue = placeValue * DOUBLE_97c30a50;
            digitsLeft = digitsLeft + -1;
          } while (digitsLeft != 0);
        }
        currentChar = *endCursor;
        sawDigits = true;
        isDecimalPoint = currentChar == 0x2e;
      }
      goto loopCheckIsDecimalPoint;
    }
setFractionStart:
    fractionStart = endCursor + 1;
    currentChar = endCursor[1];
    fractionDigitCursor = fractionStart;
    while (currentChar - 0x30 < 10) {
      fractionDigitCursor = fractionDigitCursor + 1;
      currentChar = *fractionDigitCursor;
    }
    fraction = DOUBLE_97c30a48;
    if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
      endCursor = fractionDigitCursor;
    }
    while (fractionDigitCursor = fractionDigitCursor + -1, fractionStart <= fractionDigitCursor) {
      fraction = fraction * DOUBLE_97c30ab8 +
               ((double)CONCAT44(0x43300000,(int)(char)*fractionDigitCursor - 0x30U ^ 0x80000000) -
               DOUBLE_97c30a58);
    }
    sawDigits = true;
    currentChar = *endCursor;
    value = fraction * DOUBLE_97c30ab8 + value;
  }
  if ((!sawDigits) || ((currentChar != 0x65 && (currentChar != 0x45)))) goto checkIsNegative;
  exponentStart = endCursor + 1;
  if (*exponentStart == 0x2b) {
loopSetExponentStart:
    exponentStart = endCursor + 2;
  }
  else if (*exponentStart == 0x2d) {
    isExponentNegative = true;
    goto loopSetExponentStart;
  }
  currentChar = *exponentStart;
  exponentDigitCursor = exponentStart;
  while (currentChar - 0x30 < 10) {
    exponentDigitCursor = exponentDigitCursor + 1;
    currentChar = *exponentDigitCursor;
  }
  endCursor = exponentStart;
  if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
    endCursor = exponentDigitCursor;
  }
  exponentDigitCursor = exponentDigitCursor + -1;
  exponentValue = DOUBLE_97c30a48;
  if (exponentStart <= exponentDigitCursor) {
    digitsLeft = (int)exponentDigitCursor - (int)(exponentStart + -1);
    exponentPlaceValue = DOUBLE_97c30a60;
    do {
      currentChar = *exponentDigitCursor;
      exponentDigitCursor = exponentDigitCursor + -1;
      exponentValue = ((double)CONCAT44(0x43300000,(int)(char)currentChar - 0x30U ^ 0x80000000) - DOUBLE_97c30a58
               ) * exponentPlaceValue + exponentValue;
      exponentPlaceValue = exponentPlaceValue * DOUBLE_97c30a50;
      digitsLeft = digitsLeft + -1;
    } while (digitsLeft != 0);
  }
  if (isExponentNegative) {
    exponentValue = -exponentValue;
  }
  pow_10Result = (double)((double (*)())_pow_10)((int)exponentValue);
  value = value * pow_10Result;
checkIsNegative:
  if (isNegative) {
    value = -value;
  }
  if (endPtr != (undefined4 *)0x0) {
    *endPtr = endCursor;
  }
  return value;
}

/* _glp_dtostr @ 0x97c12838 (1096 bytes) */
char * _glp_dtostr(undefined4 unusedArg1,undefined4 unusedArg2,char *outBuffer,uint bufferSize,double value,double tolerance,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  char *exponentReverseEnd;
  char *result;
  char *exponentStart;
  double tenForFraction;
  double fraction;
  double roundedValue;
  double scaledValue;
  double pow_10Result2;
  double pow_10Result;
  double roundResult;
  double floorResult2;
  double floorResult;
  char *exponentCursor;
  char swapTemp;
  double tenth;
  int swapSpan;
  char *bufferEnd;
  char *writeCursor;
  char *reverseEnd;
  double zero;
  double ten;
  double scaledTolerance;
  double quotient;
  uint exponent [6];
  
  zero = DOUBLE_97c30a48;
  bufferEnd = outBuffer + bufferSize;
  if (tolerance <= DOUBLE_97c30a48) {
    tolerance = DOUBLE_97c30ac0;
  }
  if (bufferSize < 2) {
    return (char *)0x0;
  }
  if (value < DOUBLE_97c30a48) {
    value = -value;
    *outBuffer = '-';
    outBuffer = outBuffer + 1;
  }
  scaledTolerance = tolerance;
  if (zero < value) {
    if ((value < DOUBLE_97c30ac8) || (DOUBLE_97c30ad8 < value)) {
      _frexp(value,exponent);
      roundResult = _round(((double)CONCAT44(0x43300000,exponent[0] ^ 0x80000000) - DOUBLE_97c30a58) *
                     DOUBLE_97c30ad0);
      exponent[0] = (uint)(int)roundResult;
      pow_10Result = (double)((double (*)())_pow_10)(exponent[0]);
      pow_10Result2 = (double)((double (*)())_pow_10)(-exponent[0]);
      scaledTolerance = tolerance * pow_10Result;
      scaledValue = value * pow_10Result2;
    }
    else {
      exponent[0] = 0;
      scaledValue = value;
    }
    for (; DOUBLE_97c30a50 <= scaledValue + tolerance * DOUBLE_97c30a88; scaledValue = scaledValue * DOUBLE_97c30ab8) {
      exponent[0] = exponent[0] + 1;
      scaledTolerance = scaledTolerance * DOUBLE_97c30a50;
    }
    for (; scaledValue + tolerance * DOUBLE_97c30a88 < DOUBLE_97c30a60; scaledValue = scaledValue * DOUBLE_97c30a50) {
      exponent[0] = exponent[0] - 1;
      scaledTolerance = scaledTolerance * DOUBLE_97c30ab8;
    }
    if (3 < (int)(((int)exponent[0] >> 0x1f ^ exponent[0]) - ((int)exponent[0] >> 0x1f)))
    goto setRoundedValue;
  }
  exponent[0] = 0;
  scaledValue = value;
  tolerance = scaledTolerance;
setRoundedValue:
  roundedValue = tolerance * DOUBLE_97c30a88 + scaledValue;
  floorResult = _floor(roundedValue);
  tenth = DOUBLE_97c30ab8;
  ten = DOUBLE_97c30a50;
  writeCursor = outBuffer;
  while (tolerance < floorResult) {
    if (writeCursor == bufferEnd) {
      return (char *)0x0;
    }
    quotient = floorResult * tenth;
    floorResult = _floor(quotient);
    *writeCursor = (char)(int)((quotient - floorResult) * ten) + '0';
    writeCursor = writeCursor + 1;
  }
  if (outBuffer < writeCursor) {
    swapSpan = (int)writeCursor - (int)outBuffer;
    reverseEnd = writeCursor;
    while (1 < swapSpan) {
      reverseEnd = reverseEnd + -1;
      swapTemp = *reverseEnd;
      *reverseEnd = *outBuffer;
      *outBuffer = swapTemp;
      outBuffer = outBuffer + 1;
      swapSpan = (int)reverseEnd - (int)outBuffer;
    }
  }
  else {
    *writeCursor = '0';
    writeCursor = writeCursor + 1;
  }
  floorResult2 = _floor(roundedValue);
  tenForFraction = DOUBLE_97c30a50;
  fraction = roundedValue - floorResult2;
  if (fraction <= tolerance) {
    if (exponent[0] == 0) {
      if ((int)bufferEnd - (int)writeCursor < 2) {
        return (char *)0x0;
      }
      *writeCursor = '.';
      writeCursor[1] = '0';
      writeCursor = writeCursor + 2;
    }
  }
  else {
    if (writeCursor == bufferEnd) {
      return (char *)0x0;
    }
    *writeCursor = '.';
    writeCursor = writeCursor + 1;
    do {
      if (writeCursor == bufferEnd) {
        return (char *)0x0;
      }
      fraction = fraction * tenForFraction;
      tolerance = tolerance * tenForFraction;
      floorResult2 = _floor(fraction);
      fraction = fraction - floorResult2;
      *writeCursor = (char)(int)floorResult2 + '0';
      writeCursor = writeCursor + 1;
    } while (tolerance < fraction);
  }
  if (exponent[0] != 0) {
    if ((int)bufferEnd - (int)writeCursor < 3) {
      return (char *)0x0;
    }
    *writeCursor = 'e';
    exponentStart = writeCursor + 1;
    exponentCursor = exponentStart;
    if ((int)exponent[0] < 0) {
      exponent[0] = -exponent[0];
      *exponentStart = '-';
      exponentStart = writeCursor + 2;
      exponentCursor = exponentStart;
    }
    while (writeCursor = exponentCursor, 0 < (int)exponent[0]) {
      if (writeCursor == bufferEnd) {
        return (char *)0x0;
      }
      *writeCursor = (char)exponent[0] + (char)((int)exponent[0] / 10) * -10 + '0';
      exponent[0] = (int)exponent[0] / 10;
      exponentCursor = writeCursor + 1;
    }
    swapSpan = (int)writeCursor - (int)exponentStart;
    exponentReverseEnd = writeCursor;
    while (1 < swapSpan) {
      exponentReverseEnd = exponentReverseEnd + -1;
      swapTemp = *exponentReverseEnd;
      *exponentReverseEnd = *exponentStart;
      *exponentStart = swapTemp;
      exponentStart = exponentStart + 1;
      swapSpan = (int)exponentReverseEnd - (int)exponentStart;
    }
  }
  result = (char *)0x0;
  if (writeCursor != bufferEnd) {
    *writeCursor = '\0';
    result = writeCursor;
  }
  return result;
}

/* std____throw_bad_exception @ 0x97c12c80 (68 bytes) */
int std____throw_bad_exception()
{
  undefined *destructor;
  undefined *typeInfo;
  undefined4 *exceptionObject;
  
  exceptionObject = (undefined4 *)___cxa_allocate_exception(4);
  typeInfo = PTR_typeinfo_a7b7c180;
  destructor = PTR___ZNSt13bad_exceptionD1Ev_a7b7c17c;
  *exceptionObject = PTR_vtable_a7b7c184 + 8;
                    
  ___cxa_throw(exceptionObject,typeInfo,destructor);
}

/* std____throw_bad_alloc @ 0x97c12cc4 (68 bytes) */
int std____throw_bad_alloc()
{
  undefined *destructor;
  undefined *typeInfo;
  undefined4 *exceptionObject;
  
  exceptionObject = (undefined4 *)___cxa_allocate_exception(4);
  typeInfo = PTR_typeinfo_a7b7c174;
  destructor = PTR___ZNSt9bad_allocD1Ev_a7b7c170;
  *exceptionObject = PTR_vtable_a7b7c178 + 8;
                    
  ___cxa_throw(exceptionObject,typeInfo,destructor);
}

/* std____throw_bad_cast @ 0x97c12d08 (68 bytes) */
int std____throw_bad_cast()
{
  undefined *destructor;
  undefined *typeInfo;
  undefined4 *exceptionObject;
  
  exceptionObject = (undefined4 *)___cxa_allocate_exception(4);
  typeInfo = PTR_typeinfo_a7b7c168;
  destructor = PTR___ZNSt8bad_castD1Ev_a7b7c164;
  *exceptionObject = PTR_vtable_a7b7c16c + 8;
                    
  ___cxa_throw(exceptionObject,typeInfo,destructor);
}

/* std____throw_bad_typeid @ 0x97c12d4c (68 bytes) */
int std____throw_bad_typeid()
{
  undefined *destructor;
  undefined *typeInfo;
  undefined4 *exceptionObject;
  
  exceptionObject = (undefined4 *)___cxa_allocate_exception(4);
  typeInfo = PTR_typeinfo_a7b7c15c;
  destructor = PTR___ZNSt10bad_typeidD1Ev_a7b7c158;
  *exceptionObject = PTR_vtable_a7b7c160 + 8;
                    
  ___cxa_throw(exceptionObject,typeInfo,destructor);
}

/* std____throw_logic_error @ 0x97c12d90 (108 bytes) */
int std____throw_logic_error(str)
  char *str;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  void *this;
  char reservation;
  byte cr0Reg;
  int messageString [4];
  unsigned char stringAllocator [16];
  undefined1 destroyAllocator [24];
  
  __ZNSsC1EPKcRKSaIcE(messageString,str,stringAllocator);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt11logic_errorC1ERKSs(this,(unsigned char *)messageString);
  refCountPtr = (int *)(messageString[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(messageString[0] + -0xc),destroyAllocator);
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c154,PTR___ZNSt11logic_errorD1Ev_a7b7c150);
}

/* std____throw_domain_error @ 0x97c12e18 (108 bytes) */
int std____throw_domain_error(str)
  char *str;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  void *this;
  char reservation;
  byte cr0Reg;
  int messageString [4];
  unsigned char stringAllocator [16];
  undefined1 destroyAllocator [24];
  
  __ZNSsC1EPKcRKSaIcE(messageString,str,stringAllocator);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt12domain_errorC1ERKSs(this,(unsigned char *)messageString);
  refCountPtr = (int *)(messageString[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(messageString[0] + -0xc),destroyAllocator);
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c14c,PTR___ZNSt12domain_errorD1Ev_a7b7c148);
}

/* std____throw_invalid_argument @ 0x97c12ea0 (108 bytes) */
int std____throw_invalid_argument(str)
  char *str;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  void *this;
  char reservation;
  byte cr0Reg;
  int messageString [4];
  unsigned char stringAllocator [16];
  undefined1 destroyAllocator [24];
  
  __ZNSsC1EPKcRKSaIcE(messageString,str,stringAllocator);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt16invalid_argumentC1ERKSs(this,(unsigned char *)messageString);
  refCountPtr = (int *)(messageString[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(messageString[0] + -0xc),destroyAllocator);
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c144,PTR___ZNSt16invalid_argumentD1Ev_a7b7c140);
}

/* std____throw_length_error @ 0x97c12f28 (108 bytes) */
int std____throw_length_error(str)
  char *str;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  void *this;
  char reservation;
  byte cr0Reg;
  int messageString [4];
  unsigned char stringAllocator [16];
  undefined1 destroyAllocator [24];
  
  __ZNSsC1EPKcRKSaIcE(messageString,str,stringAllocator);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt12length_errorC1ERKSs(this,(unsigned char *)messageString);
  refCountPtr = (int *)(messageString[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(messageString[0] + -0xc),destroyAllocator);
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c13c,PTR___ZNSt12length_errorD1Ev_a7b7c138);
}

/* std____throw_out_of_range @ 0x97c12fb0 (108 bytes) */
int std____throw_out_of_range(str)
  char *str;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  void *this;
  char reservation;
  byte cr0Reg;
  int messageString [4];
  unsigned char stringAllocator [16];
  undefined1 destroyAllocator [24];
  
  __ZNSsC1EPKcRKSaIcE(messageString,str,stringAllocator);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt12out_of_rangeC1ERKSs(this,(unsigned char *)messageString);
  refCountPtr = (int *)(messageString[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(messageString[0] + -0xc),destroyAllocator);
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c134,PTR___ZNSt12out_of_rangeD1Ev_a7b7c130);
}

/* std____throw_runtime_error @ 0x97c13038 (108 bytes) */
int std____throw_runtime_error(str)
  char *str;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  void *this;
  char reservation;
  byte cr0Reg;
  int messageString [4];
  unsigned char stringAllocator [16];
  undefined1 destroyAllocator [24];
  
  __ZNSsC1EPKcRKSaIcE(messageString,str,stringAllocator);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt13runtime_errorC1ERKSs(this,(unsigned char *)messageString);
  refCountPtr = (int *)(messageString[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(messageString[0] + -0xc),destroyAllocator);
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c12c,PTR___ZNSt13runtime_errorD1Ev_a7b7c128);
}

/* std____throw_range_error @ 0x97c130c0 (108 bytes) */
int std____throw_range_error(str)
  char *str;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  void *this;
  char reservation;
  byte cr0Reg;
  int messageString [4];
  unsigned char stringAllocator [16];
  undefined1 destroyAllocator [24];
  
  __ZNSsC1EPKcRKSaIcE(messageString,str,stringAllocator);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt11range_errorC1ERKSs(this,(unsigned char *)messageString);
  refCountPtr = (int *)(messageString[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(messageString[0] + -0xc),destroyAllocator);
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c124,PTR___ZNSt11range_errorD1Ev_a7b7c120);
}

/* std____throw_overflow_error @ 0x97c13148 (108 bytes) */
int std____throw_overflow_error(str)
  char *str;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  void *this;
  char reservation;
  byte cr0Reg;
  int messageString [4];
  unsigned char stringAllocator [16];
  undefined1 destroyAllocator [24];
  
  __ZNSsC1EPKcRKSaIcE(messageString,str,stringAllocator);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt14overflow_errorC1ERKSs(this,(unsigned char *)messageString);
  refCountPtr = (int *)(messageString[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(messageString[0] + -0xc),destroyAllocator);
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c11c,PTR___ZNSt14overflow_errorD1Ev_a7b7c118);
}

/* std____throw_underflow_error @ 0x97c131d0 (108 bytes) */
int std____throw_underflow_error(str)
  char *str;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  void *this;
  char reservation;
  byte cr0Reg;
  int messageString [4];
  unsigned char stringAllocator [16];
  undefined1 destroyAllocator [24];
  
  __ZNSsC1EPKcRKSaIcE(messageString,str,stringAllocator);
  this = (void *)___cxa_allocate_exception(8);
  __ZNSt15underflow_errorC1ERKSs(this,(unsigned char *)messageString);
  refCountPtr = (int *)(messageString[0] + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(messageString[0] + -0xc),destroyAllocator);
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c114,PTR___ZNSt15underflow_errorD1Ev_a7b7c110);
}

/* __ZNKSs7_M_dataEv @ 0x97c13258 (8 bytes) */
int __ZNKSs7_M_dataEv(this)
  void *this;
{
  return *(undefined4 *)this;
}

/* __ZNSs7_M_dataEPc @ 0x97c13260 (12 bytes) */
int __ZNSs7_M_dataEPc(this, str)
  void *this;
  char *str;
{
  *(char **)this = str;
  return str;
}

/* __ZNKSs6_M_repEv @ 0x97c1326c (12 bytes) */
int __ZNKSs6_M_repEv(this)
  void *this;
{
  return *(int *)this + -0xc;
}

/* __ZNKSs9_M_ibeginEv @ 0x97c13278 (12 bytes) */
int __ZNKSs9_M_ibeginEv(this, stringObject)
  undefined4 *this;
  undefined4 *stringObject;
{
  *this = *stringObject;
  return;
}

/* __ZNKSs4sizeEv @ 0x97c13284 (12 bytes) */
int __ZNKSs4sizeEv(this)
  void *this;
{
  return *(undefined4 *)(*(int *)this + -0xc);
}

/* __ZNKSs7_M_iendEv @ 0x97c13290 (20 bytes) */
int __ZNKSs7_M_iendEv(this, stringObject)
  int *this;
  int *stringObject;
{
  *this = *stringObject + *(int *)(*stringObject + -0xc);
  return;
}

/* __ZNKSs4_Rep12_M_is_leakedEv @ 0x97c132a4 (12 bytes) */
int __ZNKSs4_Rep12_M_is_leakedEv(this)
  void *this;
{
  return *(uint *)((int)this + 8) >> 0x1f;
}

