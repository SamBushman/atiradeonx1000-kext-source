#include "decls.h"

/* FUN_0004c260 @ 0x4c260 (732 bytes) */
int FUN_0004c260(cmdCursor, programObj, stageSelect)
  undefined4 *cmdCursor;
  int programObj;
  int stageSelect;
{
  uint dirtyBits;
  uint registerPacketWord;
  uint dirtyRegisterMask;
  uint bitBase;
  undefined4 bankWord3;
  undefined4 bankWord2;
  undefined4 bankWord1;
  undefined4 *vectorOut;
  undefined *registerAddr;
  undefined *headerWordPtr;
  undefined4 *vectorWordPtr;
  int objCursor2;
  int objCursor;
  int loopIndex;
  bool moreBlocks;
  char bankEmitted;
  int wordByteOffset;
  uint registerNumber;
  undefined4 bankWord0;
  uint headerCountWord;
  undefined4 *packetOut;
  int vectorCount;
  undefined *bankHeaderPtr;
  int registerBlock;
  undefined4 *bankState;
  undefined *bankBase;
  uint headerPairCount;
  int vectorByteOffset;
  uint headerPairPos;
  int wordIndex;
  int wordsLeft;
  
  if (stageSelect == 0) {
    bankEmitted = ((unsigned char *)0x000010e9)[programObj];
    vectorCount = *(int *)(((unsigned char *)0x000036a8) + programObj);
    bankState = (undefined4 *)(programObj + 4);
    bankBase = ((unsigned char *)0x000010ec);
  }
  else {
    bankEmitted = ((unsigned char *)0x000010ea)[programObj];
    vectorCount = *(int *)(((unsigned char *)0x000036b4) + programObj);
    bankState = (undefined4 *)(programObj + 0x20);
    bankBase = ((unsigned char *)0x00001318);
  }
  bankBase = bankBase + programObj;
  if (vectorCount != 0) {
    if (bankEmitted == '\0') {
      headerPairPos = 0;
      bankHeaderPtr = bankBase + 0x44;
      packetOut = cmdCursor + 0xf;
      *cmdCursor = ((unsigned char *)0x00001181U);
      dataCacheBlockTouch(bankHeaderPtr);
      bankWord0 = *bankState;
      cmdCursor[2] = ((unsigned char *)0x00001189U);
      cmdCursor[1] = bankWord0;
      bankWord1 = bankState[1];
      cmdCursor[4] = ((unsigned char *)0x00001188U);
      cmdCursor[6] = ((unsigned char *)0x0000118cU);
      cmdCursor[5] = 0;
      cmdCursor[3] = bankWord1;
      bankWord2 = bankState[2];
      cmdCursor[8] = ((unsigned char *)0x0000118dU);
      cmdCursor[7] = bankWord2;
      bankWord3 = bankState[3];
      cmdCursor[10] = ((unsigned char *)0x0000118eU);
      cmdCursor[0xb] = 0;
      cmdCursor[0xc] = ((unsigned char *)0x000010c1U);
      cmdCursor[9] = bankWord3;
      cmdCursor[0xd] = *(undefined4 *)(bankBase + 0x44);
      cmdCursor[0xe] = (*(uint *)(bankBase + 0x44) & 0xf) << 0x10 | 0x10c8;
      headerCountWord = *(uint *)(bankBase + 0x44);
      headerPairCount = headerCountWord & 0xf;
      headerWordPtr = bankHeaderPtr;
      if (headerPairCount == 0) {
        headerPairPos = 0;
      }
      else {
        do {
          headerPairPos = headerPairPos + 2;
          *packetOut = *(undefined4 *)(headerWordPtr + 4);
          packetOut[1] = *(undefined4 *)(headerWordPtr + 8);
          packetOut = packetOut + 2;
          headerWordPtr = headerWordPtr + 8;
        } while (headerPairPos < headerPairCount);
      }
      if ((headerCountWord & 1) == 0) {
        *packetOut = *(undefined4 *)(bankHeaderPtr + headerPairPos * 4 + 4);
        packetOut = packetOut + 1;
      }
      cmdCursor = packetOut + 3;
      packetOut[1] = 0;
      *packetOut = ((unsigned char *)0x00001094U);
      packetOut[2] = (vectorCount * 6 + -1) * 0x10000 | 0x9095;
      if (0 < vectorCount) {
        loopIndex = 0;
        vectorByteOffset = 0;
        do {
          wordIndex = 0;
          wordsLeft = 6;
          vectorOut = cmdCursor;
          do {
            wordByteOffset = wordIndex * 4;
            wordIndex = wordIndex + 1;
            *vectorOut = *(undefined4 *)(wordByteOffset + vectorByteOffset + bankState[4]);
            vectorOut = vectorOut + 1;
            wordsLeft = wordsLeft + -1;
          } while (wordsLeft != 0);
          loopIndex = loopIndex + 1;
          cmdCursor = cmdCursor + 6;
          vectorByteOffset = vectorByteOffset + 0x18;
        } while (vectorCount != loopIndex);
      }
    }
    if (((unsigned char *)0x000010eb)[programObj] == '\0') {
      dataCacheBlockTouch(programObj);
      registerPacketWord = 0x10000;
      bitBase = 0;
      registerBlock = programObj + 0x80;
      objCursor = programObj;
      do {
        dirtyBits = *(uint *)(((unsigned char *)0x000010b8) + objCursor);
        if (dirtyBits != 0) {
          vectorWordPtr = (undefined4 *)(registerBlock + 0xc);
          registerNumber = bitBase;
          do {
            if ((dirtyBits & 1) != 0) {
              registerPacketWord = registerNumber & 0x1ff | registerPacketWord & 0xfffffe00;
              *cmdCursor = ((unsigned char *)0x00001094U);
              cmdCursor[2] = 0x39095;
              cmdCursor[1] = registerPacketWord;
              cmdCursor[3] = *vectorWordPtr;
              cmdCursor[4] = vectorWordPtr[1];
              cmdCursor[5] = vectorWordPtr[2];
              cmdCursor[6] = vectorWordPtr[3];
              cmdCursor = cmdCursor + 7;
            }
            dirtyBits = dirtyBits >> 1;
            registerNumber = (registerNumber & 0x1ff) + 1;
            vectorWordPtr = vectorWordPtr + 4;
          } while (dirtyBits != 0);
        }
        moreBlocks = bitBase != 0xe0;
        objCursor = objCursor + 4;
        registerBlock = registerBlock + 0x200;
        bitBase = bitBase + 0x20;
      } while (moreBlocks);
      dirtyRegisterMask = *(uint *)(((unsigned char *)0x00003748) + programObj);
      if (dirtyRegisterMask != 0) {
        registerAddr = ((unsigned char *)0x00001300U);
        objCursor2 = programObj;
        do {
          if ((dirtyRegisterMask & 1) != 0) {
            *cmdCursor = registerAddr;
            cmdCursor[1] = *(undefined4 *)(((unsigned char *)0x000036c8) + objCursor2);
            cmdCursor = cmdCursor + 2;
          }
          dirtyRegisterMask = dirtyRegisterMask >> 1;
          registerAddr = registerAddr + 1;
          objCursor2 = objCursor2 + 4;
        } while (dirtyRegisterMask != 0);
      }
    }
    if (stageSelect == 0) {
      ((unsigned char *)0x000010ea)[programObj] = 0;
      ((unsigned char *)0x000010e9)[programObj] = 1;
    }
    else {
      ((unsigned char *)0x000010e9)[programObj] = 0;
      ((unsigned char *)0x000010ea)[programObj] = 1;
    }
    ((unsigned char *)0x000010eb)[programObj] = 1;
  }
  return cmdCursor;
}

/* noop_4c540 @ 0x4c540 (4 bytes) */
int noop_4c540()
{
  return;
}

/* FUN_0004c560 @ 0x4c560 (440 bytes) */
int FUN_0004c560(glContext, programObj)
  int glContext;
  int programObj;
{
  undefined4 *cmdEnd;
  undefined4 *ctxWordPtr;
  int ctxWordOffset;
  int glContextWord1e68;
  char bankEmitted;
  undefined *bankBase;
  int vectorCount;
  undefined4 cmdBuffer;
  undefined4 *cmdAfterState;
  uint stageFlag;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 *cmdCursor;
  int wordsLeft;
  
  glContextWord1e68 = *(int *)(glContext + 0x1e68);
  if (glContextWord1e68 != programObj) {
    if (glContextWord1e68 != 0) {
      ((unsigned char *)0x000010e9)[glContextWord1e68] = 0;
      ((unsigned char *)0x000010ea)[*(int *)(glContext + 0x1e68)] = 0;
      ((unsigned char *)0x000010eb)[*(int *)(glContext + 0x1e68)] = 0;
    }
    ((unsigned char *)0x000010eb)[programObj] = 0;
    ((unsigned char *)0x000010e9)[programObj] = 0;
    ((unsigned char *)0x000010ea)[programObj] = 0;
  }
  *(int *)(glContext + 0x1e68) = programObj;
  if ((glContextWord1e68 != programObj) && (*(int *)(((unsigned char *)0x000010d8) + programObj) != 0)) {
    ((int (*)())gldValidateTexEnvColor)(glContext);
  }
  if (*(uint *)(glContext + 0x23e0) == 0) {
    bankEmitted = ((unsigned char *)0x000010e9)[programObj];
  }
  else {
    bankEmitted = ((unsigned char *)0x000010ea)[programObj];
  }
  if ((bankEmitted == '\0') || (((unsigned char *)0x000010eb)[programObj] == '\0')) {
    if ((*(uint *)(glContext + 0x23e0) & 0xff) == 0) {
      vectorCount = *(int *)(((unsigned char *)0x000036a8) + programObj);
      bankBase = ((unsigned char *)0x000010ec);
    }
    else {
      vectorCount = *(int *)(((unsigned char *)0x000036b4) + programObj);
      bankBase = ((unsigned char *)0x00001318);
    }
    cmdBuffer = (**(code **)(glContext + 0x2758))
                      (glContext,vectorCount * 6 + (*(uint *)(bankBase + programObj + 0x44) & 0xf) + 0x910);
    stageFlag = (uint)*(byte *)(glContext + 0x23e3);
    *(undefined4 *)(0x00002748 + glContext + 4) = cmdBuffer;
    cmdAfterState = (undefined4 *)((int (*)())FUN_0004c260)(cmdBuffer,programObj,stageFlag);
    *cmdAfterState = 0x7101d;
    *(undefined4 **)(0x00002748 + glContext + 4) = cmdAfterState + 1;
    wordsLeft = 8;
    ctxWordOffset = glContext;
    do {
      cmdCursor = *(undefined4 **)(0x00002748 + glContext + 4);
      ctxWordPtr = (undefined4 *)(ctxWordOffset + 0x1ee8);
      ctxWordOffset = ctxWordOffset + 4;
      *cmdCursor = *ctxWordPtr;
      *(undefined4 **)(0x00002748 + glContext + 4) = cmdCursor + 1;
      wordsLeft = wordsLeft + -1;
    } while (wordsLeft != 0);
    cmdEnd = cmdCursor + 5;
    cmdCursor[1] = ((unsigned char *)0x000011adU);
    cmdCursor[2] = *(undefined4 *)(0x00002348 + glContext + 4);
    cmdCursor[3] = ((unsigned char *)0x000010c0U);
    cmdCursor[4] = *(undefined4 *)(glContext + 0x1f2c);
    *(undefined4 **)(0x00002748 + glContext + 4) = cmdEnd;
    (**(code **)(glContext + 0x275c))(glContext,cmdEnd,stageFlag,in_r6,in_r7,in_r8,cmdEnd);
  }
  *(int *)(glContext + 0x1e64) = programObj;
  return;
}

/* gldValidateVertexStreams @ 0x4c720 (1632 bytes) */
int gldValidateVertexStreams(glContext, forceUpdate, unusedArg3, unusedArg4, unusedArg5)
  int glContext;
  int forceUpdate;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
{
  uint flagsNot2000;
  uint wField;
  uint wSlot;
  uint yField;
  uint shiftBits;
  uint streamComponentCount;
  uint zSlot;
  char startByte;
  uint oldEntryWord;
  uint startLow6;
  int startSigned;
  int streamsRemaining;
  int ySlot;
  uint vtxSizeWord;
  uint streamShift;
  int outVtxDwordCount;
  int streamsLeft;
  int streamIndex;
  int streamFlagCursor;
  uint componentStart;
  uint vapOutVtxFmt0;
  int glContextWord276c;
  int loopIndex;
  bool glContextWord23e0;
  byte streamFlagByte;
  uint shiftLow6;
  uint xSlot;
  undefined4 streamEntryWord7;
  int currentProgram;
  undefined *stateBlock;
  uint streamModeFlag;
  char selectedByteFlag;
  undefined *streamRegEntry;
  uint oldStateWord228;
  int startSignExt;
  int startInt;
  uint streamStateWord;
  uint glContextWord44;
  uint xSlotBits;
  undefined4 glContextWord1bb0;
  int outputFormatBitCount;
  uint streamComponentCounts;
  int streamCountdown;
  
  glContextWord44 = *(uint *)(glContext + 0x44);
  vapOutVtxFmt0 = *(uint *)(glContext + 0x1b9c);
  if (((glContextWord44 & 0x20000) != 0) && (currentProgram = *(int *)(glContext + 0x1e70), currentProgram != 0)) {
    if ((glContextWord44 & 0x2000) == 0) {
      selectedByteFlag = ((unsigned char *)0x00001136)[glContext];
    }
    else {
      selectedByteFlag = ((unsigned char *)0x000011d0)[glContext];
    }
    if (selectedByteFlag == '\0') {
      streamModeFlag = (uint)(*(int *)(glContext + 0x2768) == 0);
      goto LAB_0004c770;
    }
  }
  currentProgram = *(int *)(glContext + 0x1e5c);
  streamModeFlag = 1;
LAB_0004c770:
  glContextWord23e0 = *(int *)(glContext + 0x23e0) == 0;
  if (glContextWord23e0) {
    stateBlock = ((unsigned char *)0x000010ec);
  }
  else {
    stateBlock = ((unsigned char *)0x00001318);
  }
  stateBlock = stateBlock + currentProgram;
  if ((streamModeFlag == 0) || ((glContextWord44 & 0x100000) == 0)) {
    streamFlagCursor = 0;
  }
  else {
    streamFlagCursor = *(int *)(((unsigned char *)0x00001168) + glContext);
  }
  flagsNot2000 = -(uint)(glContextWord44 & 0x82000 ^ 0x2000) >> 0x1f;
  if (((((forceUpdate != 0) || (streamFlagCursor != 0)) || (streamModeFlag != *(uint *)(stateBlock + 0x228))) ||
      ((*(uint *)(stateBlock + 0x218) != vapOutVtxFmt0 ||
       (*(int *)(stateBlock + 0x220) != *(int *)(glContext + 0x1bb0))))) ||
     ((*(int *)(stateBlock + 0x21c) != *(int *)(glContext + 0x1ba0) ||
      (flagsNot2000 != *(uint *)(stateBlock + 0x224))))) {
    if ((glContextWord23e0) || (*(int *)(glContext + 0x2768) == 0)) {
      streamComponentCounts = *(uint *)(glContext + 0x1ba0);
    }
    else {
      streamComponentCounts = *(uint *)(glContext + 0x1ba0) & ~(7 << (*(int *)(glContext + 0x276c) * 3 & 0x3fU));
      *(uint *)(glContext + 0x1ba0) = streamComponentCounts;
    }
    oldStateWord228 = *(uint *)(stateBlock + 0x228);
    glContextWord1bb0 = *(undefined4 *)(glContext + 0x1bb0);
    *(uint *)(stateBlock + 0x218) = vapOutVtxFmt0;
    *(uint *)(stateBlock + 0x21c) = streamComponentCounts;
    *(uint *)(stateBlock + 0x224) = flagsNot2000;
    *(undefined4 *)(stateBlock + 0x220) = glContextWord1bb0;
    outputFormatBitCount = (vapOutVtxFmt0 >> 1 & 1) + (vapOutVtxFmt0 >> 2 & 1) + (vapOutVtxFmt0 >> 3 & 1) + (vapOutVtxFmt0 >> 4 & 1);
    *(uint *)(stateBlock + 0x228) = streamModeFlag << 0x1f | oldStateWord228 & 0x7fffffff;
    streamStateWord = (uint)(streamFlagCursor != 0) * 0x40000000 |
             (uint)(*(int *)(glContext + 0x2768) != 0) * 0x20000000 |
             streamModeFlag << 0x1f | oldStateWord228 & 0x1fffffff;
    *(uint *)(stateBlock + 0x228) = streamStateWord;
    if (outputFormatBitCount == 4) {
      outputFormatBitCount = 2;
    }
    if (streamStateWord == 4) {
      componentStart = 0;
      streamShift = 0;
      streamIndex = 0;
      streamCountdown = 8;
      streamRegEntry = stateBlock + 0xc0;
      do {
        glContextWord276c = *(int *)(glContext + 0x276c);
        startByte = (char)componentStart;
        if (glContextWord276c == streamIndex) {
          zSlot = 0x3e;
          *(uint *)(streamRegEntry + 8) =
               (startByte + 1) * 0x40 & 0xfc0U | componentStart & 0x3f | *(uint *)(streamRegEntry + 8) & 0xfffff000;
          if (2 < *(int *)(stateBlock + 0x210)) {
            zSlot = (int)startByte + 2U & 0x3f;
          }
          *(uint *)(stateBlock + glContextWord276c * 4 + 200) =
               zSlot << 0xc | *(uint *)(stateBlock + glContextWord276c * 4 + 200) & 0xff000fff | 0xfc0000;
          streamComponentCount = *(uint *)(stateBlock + 0x210);
        }
        else {
          startSignExt = (int)startByte;
          streamComponentCount = streamComponentCounts >> (streamShift & 0x3f) & 7;
          *(uint *)(streamRegEntry + 8) =
               (startSignExt + 3) * 0x40000 & 0xfc0000U |
               (startSignExt + 2) * 0x1000 & 0x3f000U |
               (startSignExt + 1) * 0x40 & 0xfc0U | componentStart & 0x3f | *(uint *)(streamRegEntry + 8) & 0xff000000;
        }
        componentStart = componentStart + streamComponentCount;
        streamShift = streamShift + 3;
        streamIndex = streamIndex + 1;
        streamRegEntry = streamRegEntry + 4;
        streamCountdown = streamCountdown + -1;
      } while (streamCountdown != 0);
    }
    else if (streamFlagCursor == 0) {
      if ((*(int *)(glContext + 0x23e0) == 0) || (*(int *)(glContext + 0x2768) == 0)) {
        componentStart = 0;
        streamShift = 0;
        streamRegEntry = stateBlock + 0xc0;
        streamsLeft = 8;
        do {
          startSigned = (int)(char)componentStart;
          shiftBits = streamShift & 0x3f;
          streamShift = streamShift + 3;
          xSlotBits = componentStart & 0x3f;
          componentStart = componentStart + (streamComponentCounts >> shiftBits & 7);
          *(uint *)(streamRegEntry + 8) =
               (startSigned + 3) * 0x40000 & 0xfc0000U |
               (startSigned + 2) * 0x1000 & 0x3f000U |
               (startSigned + 1) * 0x40 & 0xfc0U | xSlotBits | *(uint *)(streamRegEntry + 8) & 0xff000000;
          streamRegEntry = streamRegEntry + 4;
          streamsLeft = streamsLeft + -1;
        } while (streamsLeft != 0);
      }
      else {
        componentStart = 0;
        streamShift = 0;
        streamIndex = 0;
        streamCountdown = 8;
        streamRegEntry = stateBlock + 0xc0;
        do {
          glContextWord276c = *(int *)(glContext + 0x276c);
          startByte = (char)componentStart;
          if (glContextWord276c == streamIndex) {
            zSlot = 0x3e;
            *(uint *)(streamRegEntry + 8) =
                 (startByte + 1) * 0x40 & 0xfc0U | componentStart & 0x3f | *(uint *)(streamRegEntry + 8) & 0xfffff000;
            if (2 < *(int *)(stateBlock + 0x210)) {
              zSlot = (int)startByte + 2U & 0x3f;
            }
            *(uint *)(stateBlock + glContextWord276c * 4 + 200) =
                 zSlot << 0xc | *(uint *)(stateBlock + glContextWord276c * 4 + 200) & 0xff000fff | 0xfc0000;
            streamComponentCount = *(uint *)(stateBlock + 0x210);
          }
          else {
            startSignExt = (int)startByte;
            streamComponentCount = streamComponentCounts >> (streamShift & 0x3f) & 7;
            *(uint *)(streamRegEntry + 8) =
                 (startSignExt + 3) * 0x40000 & 0xfc0000U |
                 (startSignExt + 2) * 0x1000 & 0x3f000U |
                 (startSignExt + 1) * 0x40 & 0xfc0U | componentStart & 0x3f | *(uint *)(streamRegEntry + 8) & 0xff000000;
          }
          componentStart = componentStart + streamComponentCount;
          streamShift = streamShift + 3;
          streamIndex = streamIndex + 1;
          streamRegEntry = streamRegEntry + 4;
          streamCountdown = streamCountdown + -1;
        } while (streamCountdown != 0);
      }
    }
    else if (*(int *)(glContext + 0x23e0) == 0) {
      streamShift = 0;
      componentStart = 0;
      streamCountdown = 8;
      streamRegEntry = stateBlock + 0xc0;
      do {
        streamFlagByte = *(byte *)(streamFlagCursor + 0x71);
        if (streamFlagByte == 0) {
          wSlot = componentStart + 3 & 0xff;
          zSlot = componentStart + 2 & 0xff;
        }
        else {
          zSlot = 0x3e;
          if ((streamFlagByte & 4) != 0) {
            zSlot = componentStart + 2 & 0xff;
          }
          wSlot = componentStart + 3 & 0xff;
          if ((streamFlagByte & 8) == 0) {
            wSlot = 0x3f;
          }
        }
        ySlot = componentStart + 1;
        shiftLow6 = streamShift & 0x3f;
        streamFlagCursor = streamFlagCursor + 1;
        streamShift = streamShift + 3;
        xSlot = componentStart & 0x3f;
        componentStart = componentStart + (streamComponentCounts >> shiftLow6 & 7);
        *(uint *)(streamRegEntry + 8) =
             (wSlot & 0x3f) << 0x12 |
             (zSlot & 0x3f) << 0xc |
             ySlot * 0x40 & 0xfc0U | xSlot | *(uint *)(streamRegEntry + 8) & 0xff000000;
        streamRegEntry = streamRegEntry + 4;
        streamCountdown = streamCountdown + -1;
      } while (streamCountdown != 0);
    }
    else {
      streamShift = 0;
      componentStart = 0;
      streamsRemaining = 8;
      loopIndex = 0;
      streamRegEntry = stateBlock + 0xc0;
      do {
        oldEntryWord = *(uint *)(streamRegEntry + 8);
        startInt = (int)(char)componentStart;
        shiftBits = streamShift & 0x3f;
        streamShift = streamShift + 3;
        startLow6 = componentStart & 0x3f;
        componentStart = componentStart + (streamComponentCounts >> shiftBits & 7);
        yField = (startInt + 1) * 0x40 & 0xfc0;
        wField = (startInt + 3) * 0x40000 & 0xfc0000;
        *(uint *)(streamRegEntry + 8) =
             wField | (startInt + 2) * 0x1000 & 0x3f000U | yField | startLow6 | oldEntryWord & 0xff000000;
        streamFlagByte = *(byte *)(streamFlagCursor + 0x71);
        if (streamFlagByte != 0) {
          if ((streamFlagByte & 4) == 0) {
            *(uint *)(streamRegEntry + 8) = wField | yField | startLow6 | oldEntryWord & 0xff000000 | 0x3e000;
          }
          if ((streamFlagByte & 8) == 0) {
            *(uint *)(streamRegEntry + 8) = *(uint *)(streamRegEntry + 8) & 0xff03ffff | 0xfc0000;
          }
        }
        if (*(int *)(glContext + 0x276c) == loopIndex) {
          if (*(int *)(stateBlock + 0x210) == 2) {
            *(uint *)(streamRegEntry + 8) = *(uint *)(streamRegEntry + 8) & 0xfffc0fff | 0x3e000;
          }
          *(uint *)(streamRegEntry + 8) = *(uint *)(streamRegEntry + 8) & 0xff03ffff | 0xfc0000;
          componentStart = componentStart + *(int *)(stateBlock + 0x210);
        }
        loopIndex = loopIndex + 1;
        streamRegEntry = streamRegEntry + 4;
        streamFlagCursor = streamFlagCursor + 1;
        streamsRemaining = streamsRemaining + -1;
      } while (streamsRemaining != 0);
    }
    outVtxDwordCount = outputFormatBitCount;
    if ((componentStart == 0) && (outVtxDwordCount = 1, outputFormatBitCount != 0)) {
      outVtxDwordCount = outputFormatBitCount;
    }
    vtxSizeWord = outVtxDwordCount << 7 | componentStart & 0x7f | 0x40000;
    *(uint *)(stateBlock + 0x8c) = (flagsNot2000 ^ 1) << 10 | *(uint *)(stateBlock + 0x8c) & 0xffffe1ff;
    *(uint *)(stateBlock + 200) = *(uint *)(stateBlock + 200) & 0xf8ffffff;
    *(uint *)(stateBlock + 0x208) = vtxSizeWord;
    *(uint *)(stateBlock + 0xcc) = *(uint *)(stateBlock + 0xcc) & 0xf8ffffff | 0x1000000;
    *(uint *)(glContext + 0x1f2c) = vtxSizeWord;
    *(undefined4 *)(glContext + 0x1ee8) = *(undefined4 *)(stateBlock + 200);
    *(undefined4 *)(glContext + 0x1eec) = *(undefined4 *)(stateBlock + 0xcc);
    *(undefined4 *)(glContext + 0x1ef0) = *(undefined4 *)(stateBlock + 0xd0);
    *(undefined4 *)(glContext + 0x1ef4) = *(undefined4 *)(stateBlock + 0xd4);
    *(undefined4 *)(glContext + 0x1ef8) = *(undefined4 *)(stateBlock + 0xd8);
    *(undefined4 *)(glContext + 0x1efc) = *(undefined4 *)(stateBlock + 0xdc);
    *(undefined4 *)(glContext + 0x1f00) = *(undefined4 *)(stateBlock + 0xe0);
    streamEntryWord7 = *(undefined4 *)(stateBlock + 0xe4);
    *(uint *)(glContext + 0x1ba4) = streamComponentCounts;
    *(undefined4 *)(glContext + 0x1bb4) = glContextWord1bb0;
    *(undefined4 *)(glContext + 0x1f04) = streamEntryWord7;
    if ((*(uint *)(glContext + 0x44) & 0x20000000) != 0) {
      *(undefined4 *)(glContext + 0x277c) = 0xffffffff;
    }
  }
  return;
}

/* freeAndNullField @ 0x4cde0 (72 bytes) */
int freeAndNullField(param_1)
  int param_1;
{
  /* issue #74 / #79: this is the stock's plain free-and-null helper again. It used to carry a
   * malloc_size() guard because the bad values it freed on CGLDestroyContext teardown (0x84c1,
   * 0x110001 in #74; 0x24 in FUN_0004b5d0, #79) looked like table entries - the guard hid a
   * real bug instead of fixing it: FUN_000b5fb0 dropped the object it hands the destroy
   * callback (`lwz r4,0x1448(r30)`, loaded before the branch, so its indirect-call argument
   * count missed it) and the destructor ran on whatever r4 held. With that fixed, cgl_probe
   * runs clean on real hardware WITHOUT the guard (5 runs, zero malloc warnings). */
  if (*(int *)(param_1 + 0x10) != 0) {
    _free(*(int *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}

/* FUN_0004ce30 @ 0x4ce30 (680 bytes) */
int FUN_0004ce30(glContext)
  int glContext;
{
  int glState;
  short depthFunc;
  bool hizBlocksFunc;
  bool depthTestEffective;
  int hizFunc;
  uint scHyperzEn;
  int zbBwCntl;
  uint oldHyperzEn;
  int fbConfig;
  int glStateBlock;
  
  glState = *(int *)(glContext + 4);
  oldHyperzEn = *(uint *)(glContext + 0x1ae0);
  zbBwCntl = *(int *)(glContext + 0x1ab0);
  glStateBlock = *(int *)(glState + 0x10);
  depthFunc = *(short *)(((unsigned char *)0x00002dc4) + glStateBlock);
  fbConfig = glState + 0x30;
  if (*(int *)(glState + 0x150) != 0) {
    fbConfig = *(int *)(glState + 0x150);
  }
  if (((((((unsigned char *)0x00002dc8)[glStateBlock] == '\0') || (((unsigned char *)0x00002e44)[glStateBlock] == '\0')) || (depthFunc == 0x200))
      || (depthFunc == 0x202)) ||
     (((*(double *)(0x00001830 + glStateBlock) == DOUBLE_001aa200 &&
       (*(double *)(glStateBlock + 0x1838) == DOUBLE_001aa200)) && (depthFunc == 0x203)))) {
    depthTestEffective = false;
  }
  else {
    depthTestEffective = true;
  }
  if (((*(char *)(fbConfig + 0xc5) == '\0') && (((unsigned char *)0x00002dc8)[glStateBlock] != '\0')) &&
     ((*(uint *)(glContext + 0x44) & 0x200) == 0)) {
    switch(depthFunc) {
    case 0x200:
    case 0x201:
    case 0x202:
    case 0x203:
      if ((*(uint *)(fbConfig + 0xc4) & 0xff00ff00) == 0) {
        hizBlocksFunc = true;
        hizFunc = 0x201;
      }
      else {
        hizBlocksFunc = false;
        hizFunc = 0x201;
      }
      break;
    case 0x204:
    case 0x205:
    case 0x206:
      if ((*(char *)(fbConfig + 0xc4) == '\0') && (*(char *)(fbConfig + 0xc6) != '\0')) {
        hizBlocksFunc = true;
        hizFunc = 0x204;
      }
      else {
        hizBlocksFunc = false;
        hizFunc = 0x204;
      }
      break;
    case 0x207:
      hizBlocksFunc = false;
      hizFunc = 0x207;
      break;
    default:
      hizBlocksFunc = false;
      hizFunc = 0x200;
    }
    if (((*(int *)(((unsigned char *)0x000031c0) + glStateBlock) == 0) ||
        ((((*(short *)(((unsigned char *)0x000031a2) + glStateBlock) == 0x1e00 &&
           (*(short *)(((unsigned char *)0x000031a4) + glStateBlock) == 0x1e00)) &&
          (*(short *)(((unsigned char *)0x000031ba) + glStateBlock) == 0x1e00)) &&
         (*(short *)(((unsigned char *)0x000031bc) + glStateBlock) == 0x1e00)))) && (!hizBlocksFunc)) {
      if (hizFunc == 0x204) {
        scHyperzEn = *(uint *)(glContext + 0x1ae0) | 3;
        *(uint *)(glContext + 0x1ae0) = scHyperzEn;
        *(uint *)(glContext + 0x1ab0) = *(uint *)(glContext + 0x1ab0) | 3;
      }
      else if (hizFunc == 0x207) {
        scHyperzEn = *(uint *)(glContext + 0x1ae0) & 0xfffffffe;
        *(uint *)(glContext + 0x1ae0) = scHyperzEn;
        *(uint *)(glContext + 0x1ab0) = *(uint *)(glContext + 0x1ab0) | 1;
      }
      else {
        scHyperzEn = *(uint *)(glContext + 0x1ae0) & 0xfffffffd | 1;
        *(uint *)(glContext + 0x1ae0) = scHyperzEn;
        *(uint *)(glContext + 0x1ab0) = *(uint *)(glContext + 0x1ab0) & 0xfffffffd | 1;
      }
      *(byte *)(fbConfig + 0xc6) = (byte)((scHyperzEn ^ 2) >> 1) & 1;
      if (depthTestEffective) {
        *(undefined1 *)(fbConfig + 0xc4) = 0;
        scHyperzEn = *(uint *)(glContext + 0x1ae0);
      }
      else {
        scHyperzEn = *(uint *)(glContext + 0x1ae0);
      }
      goto LAB_0004d0d0;
    }
  }
  scHyperzEn = *(uint *)(glContext + 0x1ae0) & 0xfffffffe;
  *(uint *)(glContext + 0x1ae0) = scHyperzEn;
  *(uint *)(glContext + 0x1ab0) = *(uint *)(glContext + 0x1ab0) & 0xfffffffe;
  if (depthTestEffective) {
    *(undefined1 *)(fbConfig + 0xc5) = 1;
    scHyperzEn = *(uint *)(glContext + 0x1ae0);
  }
LAB_0004d0d0:
  if ((oldHyperzEn == scHyperzEn) && (zbBwCntl == *(int *)(glContext + 0x1ab0))) {
    return;
  }
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x1000;
  return;
}

/* FUN_0004d100 @ 0x4d100 (1264 bytes) */
int FUN_0004d100(glContext)
  int glContext;
{
  uint oldWord1bd4;
  uint newWord1ab8;
  int earlyZCheckResult;
  uint zbZstencilcntl;
  int rb3dColorChannelMask;
  int glContextWord1e5c;
  uint fgAlphaFunc;
  bool flag18a4Bit4;
  bool blendSpecialEligible;
  uint blendSrcFactor;
  uint blendDstFactor;
  uint newWord1bd4;
  int glContextWord4;
  uint zbCntl;
  int glState;
  uint newAlphaFuncWord;
  uint word1a4cOrFlag;
  char blendEnabled;
  uint glContextWord44;
  uint glContextWord1ab8;
  
  fgAlphaFunc = *(uint *)(glContext + 0x1a4c);
  glContextWord1e5c = *(int *)(glContext + 0x1e5c);
  glState = *(int *)(*(int *)(glContext + 4) + 0x10);
  if ((((*(uint *)(glContext + 0x1a80) & 1) == 0) || ((*(uint *)(glContext + 0x1aa0) & 6) == 6)) ||
     (*(char *)(glContext + 0x23ed) != '\0')) {
    blendEnabled = ((unsigned char *)0x00002d66)[glState];
    goto LAB_0004d234;
  }
  if (((unsigned char *)0x00002d66)[glState] == '\0') {
    blendEnabled = '\0';
    if (((*(short *)(((unsigned char *)0x00002d80) + glState) != -0x7ffa) ||
        (*(int *)(((unsigned char *)0x00002d68) + glState) != *(int *)(((unsigned char *)0x00002d6c) + glState))) ||
       (((unsigned char *)0x00002b7e)[*(int *)(glContext + 4)] != '\0')) {
LAB_0004d234:
      if (blendEnabled != '\0') goto LAB_0004d240;
      goto LAB_0004d260;
    }
    blendSrcFactor = (uint)*(ushort *)(((unsigned char *)0x00002d68) + glState);
    blendDstFactor = (uint)*(ushort *)(((unsigned char *)0x00002d6a) + glState);
    flag18a4Bit4 = (*(uint *)(glContext + 0x8c) & 0x400000) == 0;
    if (((flag18a4Bit4) || (*(char *)(glContext + 0x2450) == '\0')) ||
       (blendSpecialEligible = true, (int)*(uint *)(glContext + 0x8c) < 0)) {
      blendSpecialEligible = false;
    }
    if (((flag18a4Bit4) || (blendSrcFactor != 0x302)) || (flag18a4Bit4 = false, blendDstFactor != 0x303)) {
      if (blendSpecialEligible) {
        if (blendSrcFactor == 0) {
          if (blendDstFactor == 0x301) {
LAB_0004d20c:
            if ((*(int *)(((unsigned char *)0x00001098) + glContextWord1e5c) == 1) &&
               (flag18a4Bit4 = true, *(double *)(0x00001830 + glState) != *(double *)(glState + 0x1838)))
            goto LAB_0004d5c4;
          }
        }
        else if (((blendSrcFactor == 1) || (blendSrcFactor == 0x306)) && (blendDstFactor == 1)) goto LAB_0004d20c;
      }
      goto LAB_0004d234;
    }
LAB_0004d5c4:
    *(uint *)(glContext + 0x1a4c) = *(uint *)(glContext + 0x1a4c) | 0x800;
    *(undefined1 *)(glContext + 0x1a4f) = 0;
    newAlphaFuncWord = *(uint *)(glContext + 0x1a4c) & 0xfffff8ff | 0x400;
    *(uint *)(glContext + 0x1a4c) = newAlphaFuncWord;
  }
  else {
LAB_0004d240:
    if (*(short *)(((unsigned char *)0x00002d64) + glState) == 0x207) {
LAB_0004d260:
      flag18a4Bit4 = false;
      newAlphaFuncWord = *(uint *)(glContext + 0x1a4c) & 0xfffff7ff;
      *(uint *)(glContext + 0x1a4c) = newAlphaFuncWord;
    }
    else {
      flag18a4Bit4 = false;
      newAlphaFuncWord = *(uint *)(glContext + 0x1a4c) | 0x800;
      *(uint *)(glContext + 0x1a4c) = newAlphaFuncWord;
    }
  }
  if (fgAlphaFunc != newAlphaFuncWord) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x200;
  }
  if (flag18a4Bit4) {
    *(uint *)(glContext + 0x18a4) = *(uint *)(glContext + 0x18a4) | 0x10;
    if ((*(uint *)(((unsigned char *)0x00001544) + glContextWord1e5c) & 0x10) == 0) {
LAB_0004d2c8:
      FUN_000b6580(glContext,0);
      (**(code **)(((unsigned char *)0x00001334) + glContext))(glContext,0);
      (**(code **)(glContext + 0x294c))(glContext,*(undefined4 *)(glContext + 0x1e5c));
    }
  }
  else {
    *(uint *)(glContext + 0x18a4) = *(uint *)(glContext + 0x18a4) & 0xffffffef;
    if ((*(uint *)(((unsigned char *)0x00001544) + glContextWord1e5c) & 0x10) != 0) goto LAB_0004d2c8;
  }
  ((int (*)())FUN_0004ce30)(glContext);
  zbCntl = *(uint *)(glContext + 0x1aa0);
  glContextWord1ab8 = *(uint *)(glContext + 0x1ab8);
  glContextWord4 = *(int *)(glContext + 4);
  newWord1ab8 = glContextWord1ab8 | 1;
  *(uint *)(glContext + 0x1ab8) = newWord1ab8;
  if ((((zbCntl & 6) != 6) && (((unsigned char *)0x00002b7e)[glContextWord4] == '\0')) &&
     (*(char *)(glContext + 0x23ed) == '\0')) {
    word1a4cOrFlag = *(uint *)(glContext + 0x1a4c);
    glContextWord44 = *(uint *)(glContext + 0x44);
    goto LAB_0004d460;
  }
  word1a4cOrFlag = *(uint *)(glContext + 0x1a4c);
  if ((word1a4cOrFlag & 0x800) == 0) {
    glContextWord44 = *(uint *)(glContext + 0x44);
    if ((glContextWord44 & 0x60020000) != 0x40000000) {
      if ((((unsigned char *)0x00002e2d)[*(int *)(glContextWord4 + 0x10)] != '\0') && ((glContextWord44 & 0x20000) == 0)) {
        glContextWord4 = gld_needsMultisampleResolve(glContextWord4,*(undefined4 *)(glContextWord4 + 0x26a0),blendSrcFactor,blendDstFactor,fgAlphaFunc,zbCntl,word1a4cOrFlag);
        if (glContextWord4 == 0) {
          zbCntl = *(uint *)(glContext + 0x1aa0);
          word1a4cOrFlag = *(uint *)(glContext + 0x1a4c);
          newWord1ab8 = *(uint *)(glContext + 0x1ab8);
          goto LAB_0004d440;
        }
        glContextWord4 = *(int *)(glContext + 4);
        zbCntl = *(uint *)(glContext + 0x1aa0);
        word1a4cOrFlag = *(uint *)(glContext + 0x1a4c);
        newWord1ab8 = *(uint *)(glContext + 0x1ab8);
        glContextWord44 = *(uint *)(glContext + 0x44);
      }
      glContextWord4 = *(int *)(glContextWord4 + 0x10);
      if (((((((unsigned char *)0x00002e2c)[glContextWord4] == '\0') || ((glContextWord44 & 0x20000) != 0)) ||
           (*(short *)(((unsigned char *)0x00002e28) + glContextWord4) == -1)) &&
          (((((unsigned char *)0x00003178)[glContextWord4] == '\0' || ((glContextWord44 & 0x20000) != 0)) ||
           ((*(short *)(((unsigned char *)0x00003170) + glContextWord4) != 0x1b02 &&
            (*(short *)(((unsigned char *)0x00003172) + glContextWord4) != 0x1b02)))))) &&
         (((word1a4cOrFlag & 0x10000) == 0 && ((glContextWord44 & 0x2000100) == 0)))) goto LAB_0004d460;
    }
  }
  else {
LAB_0004d440:
    glContextWord44 = *(uint *)(glContext + 0x44);
  }
  newWord1ab8 = newWord1ab8 & 0xfffffffe;
  *(uint *)(glContext + 0x1ab8) = newWord1ab8;
LAB_0004d460:
  if ((((word1a4cOrFlag & 0x800) != 0) && (*(int *)(glContext + 0x27b0) == 1)) &&
     (word1a4cOrFlag = *(uint *)(glContext + 0x8c) & 0x400000, word1a4cOrFlag != 0)) {
    newWord1ab8 = newWord1ab8 & 0xfffffffe;
    *(uint *)(glContext + 0x1ab8) = newWord1ab8;
  }
  if (((zbCntl & 2) != 0) && ((glContextWord44 >> 9 & 1) != 0)) {
    newWord1ab8 = newWord1ab8 & 0xfffffffe;
    *(uint *)(glContext + 0x1ab8) = newWord1ab8;
  }
  if (glContextWord1ab8 != newWord1ab8) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x20000;
  }
  if (*(int *)(glContext + 0x23dc) != 1) {
    oldWord1bd4 = *(uint *)(glContext + 0x1bd4);
    zbZstencilcntl = *(uint *)(glContext + 0x1aa4);
    earlyZCheckResult = gld_needsMultisampleResolve(*(undefined4 *)(glContext + 4),*(undefined4 *)(glContext + 0x2460),blendSrcFactor,blendDstFactor,
                         fgAlphaFunc,zbCntl,word1a4cOrFlag);
    if (earlyZCheckResult == 0) {
      if ((*(uint *)(glContext + 0x1ab8) & 1) == 0) {
        newWord1bd4 = *(uint *)(glContext + 0x1bd4) & 0xfffffffe;
        *(uint *)(glContext + 0x1bd4) = newWord1bd4;
        *(uint *)(glContext + 0x1aa4) = *(uint *)(glContext + 0x1aa4) & 0xf7ffffff;
      }
      else {
        rb3dColorChannelMask = *(int *)(0x00001af4 + glContext);
        newWord1bd4 = *(uint *)(glContext + 0x1bd4) | 1;
        *(uint *)(glContext + 0x1bd4) = newWord1bd4;
        if (rb3dColorChannelMask == 0) {
          *(uint *)(glContext + 0x1aa4) = *(uint *)(glContext + 0x1aa4) | 0x8000000;
        }
        else {
          *(uint *)(glContext + 0x1aa4) = *(uint *)(glContext + 0x1aa4) & 0xf7ffffff;
        }
      }
    }
    else {
      newWord1bd4 = *(uint *)(glContext + 0x1bd4);
      if ((newWord1bd4 & 1) != 0) {
        newWord1bd4 = newWord1bd4 & 0xfffffffe;
        *(uint *)(glContext + 0x1bd4) = newWord1bd4;
        *(uint *)(glContext + 0x1aa4) = *(uint *)(glContext + 0x1aa4) & 0xf7ffffff;
      }
    }
    if (((oldWord1bd4 & 1) != (newWord1bd4 & 1)) ||
       ((zbZstencilcntl >> 0x1b & 1) != (*(uint *)(glContext + 0x1aa4) >> 0x1b & 1))) {
      *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x20800;
    }
  }
  return;
}

/* FUN_0004d620 @ 0x4d620 (328 bytes) */
void FUN_0004d620(int glContext,undefined4 param_2,undefined4 unusedArgR5,undefined4 unused,double fparam_1)
{
  uint loopIndex;
  int iVar1;
  char cVar2;
  int iVar3;
  uint glContextWord44;
  int iVar5;
  
  glContextWord44 = *(uint *)(glContext + 0x44);
  if ((glContextWord44 & 0x20000) == 0) {
    FUN_000b6580(glContext,0);
                    
                    
    (**(code **)(glContext + 0x294c))(glContext,*(undefined4 *)(glContext + 0x1e5c));
    return;
  }
  if ((glContextWord44 & 0x2000) != 0) {
    ((undefined4 (*)())FUN_000afe40)(glContext,0,unusedArgR5,unused,fparam_1);
    return;
  }
  if ((glContextWord44 & 0x80100000) == 0x80000000) {
    if (*(short *)(((unsigned char *)0x00002d48) + *(int *)(*(int *)(glContext + 4) + 0x10)) == -0x7e06)
    goto LAB_0004d6ac;
  }
  else if ((glContextWord44 & 0x800000) != 0) {
LAB_0004d6ac:
    cVar2 = '\x01';
    goto LAB_0004d6b0;
  }
  cVar2 = '\0';
LAB_0004d6b0:
  iVar5 = *(int *)(((unsigned char *)0x00001154) + glContext);
  if (*(int *)(iVar5 + 4) != 0) {
    loopIndex = 0;
    iVar3 = 0;
    do {
      iVar1 = *(int *)(*(int *)(((unsigned char *)0x0000113c) + glContext) * 4 +
                      *(int *)(iVar3 + *(int *)(iVar5 + 0x88) + 0x70));
      if ((iVar1 != 0) && (((unsigned char *)0x0000120c)[iVar1] != cVar2)) {
        *(undefined4 *)(((unsigned char *)0x000016f0) + iVar1) = 1;
        *(undefined1 *)(iVar1 + 0x119) = 1;
        iVar5 = *(int *)(((unsigned char *)0x00001154) + glContext);
      }
      loopIndex = loopIndex + 1;
      iVar3 = iVar3 + 0x78;
    } while (loopIndex < *(uint *)(iVar5 + 4));
  }
  atifsCompileCurrentShader(glContext);
  return;
}

/* gldValidateViewportPolygonOffset @ 0x4d770 (840 bytes) */
void gldValidateViewportPolygonOffset(int glContext,double fprF1,double fprF2,double fprF3,double fprF4,double fprF5,double fprF6,double fprF7,double fprF8)
{
  float polyOffsetUnits;
  float polyOffsetUnitScale;
  float polyOffsetFactorScaled;
  uint newPolyOffsetBits;
  float yPixelScale;
  float xPixelScale;
  float halfHeight;
  float halfWidth;
  float centerY;
  double intToDoubleBias;
  uint viewportX;
  int glState;
  int glContextWord1c98;
  int glContextWord1c9c;
  int glContextWord1c90;
  int glContextWord1c94;
  int glContextWord1c88;
  uint glContextWord1b14;
  int glContextWord1c8c;
  int glStateBlock;
  
  intToDoubleBias = DOUBLE_001aa1e0;
  halfWidth = FLOAT_001aa10c;
  glState = *(int *)(glContext + 4);
  glContextWord1c9c = *(int *)(glContext + 0x1c9c);
  glContextWord1c98 = *(int *)(glContext + 0x1c98);
  glContextWord1c88 = *(int *)(glContext + 0x1c88);
  glContextWord1c94 = *(int *)(glContext + 0x1c94);
  glContextWord1c90 = *(int *)(glContext + 0x1c90);
  glContextWord1c8c = *(int *)(glContext + 0x1c8c);
  glStateBlock = *(int *)(glState + 0x10);
  yPixelScale = *(float *)(glState + 0x2a58);
  xPixelScale = *(float *)(glState + 0x2a54);
  *(undefined4 *)(glContext + 0x1c9c) = *(undefined4 *)(glStateBlock + 0x1818);
  *(undefined4 *)(glContext + 0x1c98) = *(undefined4 *)(glStateBlock + 0x1828);
  viewportX = *(uint *)(glStateBlock + 0x1840);
  halfHeight = yPixelScale * (float)((double)CONCAT44(0x43300000,*(uint *)(glStateBlock + 0x184c) ^ 0x80000000) -
                         intToDoubleBias) * halfWidth;
  centerY = yPixelScale * (float)((double)CONCAT44(0x43300000,*(uint *)(glStateBlock + 0x1844) ^ 0x80000000) -
                         intToDoubleBias) + halfHeight;
  halfWidth = xPixelScale * (float)((double)CONCAT44(0x43300000,*(uint *)(glStateBlock + 0x1848) ^ 0x80000000) -
                         intToDoubleBias) * halfWidth;
  if (*(char *)(glContext + 0x293c) != '\0') {
    centerY = yPixelScale * (float)((double)CONCAT44(0x43300000,*(uint *)(glState + 0x160) ^ 0x80000000) -
                           intToDoubleBias) - centerY;
    halfHeight = -halfHeight;
  }
  *(float *)(glContext + 0x1c8c) = halfWidth;
  *(float *)(glContext + 0x1c88) =
       xPixelScale * (float)((double)CONCAT44(0x43300000,viewportX ^ 0x80000000) - intToDoubleBias) + halfWidth;
  *(float *)(glContext + 0x1c94) = halfHeight;
  *(float *)(glContext + 0x1c90) = centerY;
  if (*(char *)(glContext + 0x124) != '\0') {
    *(undefined4 *)(glContext + 0x1c8c) = *(undefined4 *)(glContext + 0x2814);
    *(undefined4 *)(glContext + 0x1c94) = *(undefined4 *)(glContext + 0x2818);
  }
  *(undefined4 *)(glContext + 0x1ca8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1cb0) = 0x3f800000;
  if (((((glContextWord1c8c != *(int *)(glContext + 0x1c8c)) || (glContextWord1c88 != *(int *)(glContext + 0x1c88))) ||
       (glContextWord1c94 != *(int *)(glContext + 0x1c94))) ||
      ((glContextWord1c90 != *(int *)(glContext + 0x1c90) || (glContextWord1c9c != *(int *)(glContext + 0x1c9c))))) ||
     (glContextWord1c98 != *(int *)(glContext + 0x1c98))) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x80;
  }
  glContextWord1b14 = *(uint *)(0x00001b14 + glContext);
  newPolyOffsetBits = glContextWord1b14 & 0xfffffff8;
  *(uint *)(0x00001b14 + glContext) = newPolyOffsetBits;
  if ((((*(uint *)(((unsigned char *)0x0000317cU) + glStateBlock) & 0xffff0000) != 0) || (((unsigned char *)0x0000317b)[glStateBlock] != '\0'))
     && ((*(float *)(((unsigned char *)0x0000316c) + glStateBlock) != FLOAT_001aa0d4 ||
         (*(float *)(((unsigned char *)0x00003168) + glStateBlock) != FLOAT_001aa0d4)))) {
    if (((unsigned char *)0x0000317b)[glStateBlock] != '\0') {
      if (*(short *)(((unsigned char *)0x00003170) + glStateBlock) == 0x1b00) {
        newPolyOffsetBits = newPolyOffsetBits | 1;
        *(uint *)(0x00001b14 + glContext) = newPolyOffsetBits;
      }
      if (*(short *)(((unsigned char *)0x00003172) + glStateBlock) == 0x1b00) {
        newPolyOffsetBits = newPolyOffsetBits | 2;
        *(uint *)(0x00001b14 + glContext) = newPolyOffsetBits;
      }
    }
    if (((unsigned char *)0x0000317c)[glStateBlock] != '\0') {
      if (*(short *)(((unsigned char *)0x00003170) + glStateBlock) == 0x1b01) {
        newPolyOffsetBits = newPolyOffsetBits | 1;
        *(uint *)(0x00001b14 + glContext) = newPolyOffsetBits;
      }
      if (*(short *)(((unsigned char *)0x00003172) + glStateBlock) == 0x1b01) {
        newPolyOffsetBits = newPolyOffsetBits | 2;
        *(uint *)(0x00001b14 + glContext) = newPolyOffsetBits;
      }
    }
    if (((unsigned char *)0x0000317d)[glStateBlock] != '\0') {
      if (*(short *)(((unsigned char *)0x00003170) + glStateBlock) == 0x1b02) {
        newPolyOffsetBits = newPolyOffsetBits | 1;
        *(uint *)(0x00001b14 + glContext) = newPolyOffsetBits;
      }
      if (*(short *)(((unsigned char *)0x00003172) + glStateBlock) == 0x1b02) {
        newPolyOffsetBits = newPolyOffsetBits | 2;
        *(uint *)(0x00001b14 + glContext) = newPolyOffsetBits;
      }
    }
    polyOffsetFactorScaled = (float)((double)CONCAT44(0x43300000,*(undefined4 *)(glContext + 8)) - DOUBLE_001aa250) *
            *(float *)(((unsigned char *)0x00003168) + glStateBlock);
    polyOffsetUnitScale = FLOAT_001aa104;
    if ((*(uint *)(*(int *)(glContext + 4) + 0x154) & 0x30000) == 0x10000) {
      polyOffsetUnitScale = FLOAT_001aa164;
    }
    polyOffsetUnits = *(float *)(((unsigned char *)0x0000316c) + glStateBlock);
    *(float *)(glContext + 0x1b24) = polyOffsetFactorScaled;
    *(float *)(glContext + 0x1b1c) = polyOffsetFactorScaled;
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x20;
    *(float *)(glContext + 0x1b20) = polyOffsetUnitScale * polyOffsetUnits;
    *(float *)(glContext + 0x1b18) = polyOffsetUnitScale * polyOffsetUnits;
  }
  if (glContextWord1b14 != newPolyOffsetBits) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x20;
  }
  return;
}

/* gldValidateDepthTest @ 0x4dac0 (272 bytes) */
int gldValidateDepthTest(glContext)
  int glContext;
{
  int glState;
  uint oldZControl;
  uint depthControl;
  uint depthFunc;
  
  glState = *(int *)(*(int *)(glContext + 4) + 0x10);
  if ((((unsigned char *)0x00002dc8)[glState] == '\0') || (((unsigned char *)0x00001490)[glContext] == '\0')) {
    oldZControl = *(uint *)(glContext + 0x1930);
    *(uint *)(glContext + 0x1aa0) = *(uint *)(glContext + 0x1aa0) & 0xfffffffd;
  }
  else {
    depthFunc = (uint)*(ushort *)(((unsigned char *)0x00002dc4) + glState);
    depthControl = *(uint *)(glContext + 0x1aa0);
    oldZControl = *(uint *)(glContext + 0x1a50);
    *(uint *)(glContext + 0x1aa0) = depthControl | 2;
    if ((depthFunc == 0x202) ||
       (((depthFunc == 0x203 && (*(double *)(0x00001830 + glState) == DOUBLE_001aa200)) &&
        (*(double *)(glState + 0x1838) == DOUBLE_001aa200)))) {
      *(uint *)(glContext + 0x1aa0) = depthControl & 0xfffffffb | 2;
    }
    else {
      *(uint *)(glContext + 0x1aa0) = ((byte)((unsigned char *)0x00002e44)[glState] & 1) << 2 | depthControl & 0xfffffffb | 2
      ;
    }
    *(uint *)(glContext + 0x1aa4) =
         *(uint *)(&DAT_001db368 + (depthFunc & 7) * 4) & 7 | *(uint *)(glContext + 0x1aa4) & 0xfffffff8;
    if ((*(uint *)(glContext + 0x44) & 0x200) == 0) {
      depthControl = oldZControl & 0xfffffffe;
      *(uint *)(glContext + 0x1a50) = depthControl;
    }
    else {
      depthControl = oldZControl | 1;
      *(uint *)(glContext + 0x1a50) = depthControl;
    }
    if (oldZControl == depthControl) {
      oldZControl = *(uint *)(glContext + 0x1930);
    }
    else {
      oldZControl = *(uint *)(glContext + 0x1930) | 0x8000000;
      *(uint *)(glContext + 0x1930) = oldZControl;
    }
  }
  *(uint *)(glContext + 0x1930) = oldZControl | 0x800;
  return;
}

/* FUN_0004dbe0 @ 0x4dbe0 (76 bytes) */
int FUN_0004dbe0(glContext)
  int glContext;
{
  if (*(char *)(glContext + 0x124) != '\0') {
    ffvpSetupVertexOutputRouting(glContext);
  }
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x40000;
  return;
}

/* gldValidateTexEnvColor @ 0x4dc30 (220 bytes) */
int gldValidateTexEnvColor(glContext)
  int glContext;
{
  int constantOffset;
  uint unit;
  int unitState;
  int programConstants;
  int shadowCursor;
  uint unitCount;
  
  if ((*(uint *)(glContext + 0x44) & 0x20000) != 0) {
    return;
  }
  unitCount = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
  if ((uint)*(byte *)(glContext + 0x2b) <= (uint)(byte)((unsigned char *)0x000013b2)[glContext]) {
    unitCount = (uint)*(byte *)(glContext + 0x2b);
  }
  if (unitCount != 0) {
    unit = 0;
    unitState = glContext;
    shadowCursor = glContext;
    do {
      *(undefined4 *)(shadowCursor + 0x1f38) = *(undefined4 *)(unitState + 0x47c);
      *(undefined4 *)(shadowCursor + 0x1f3c) = *(undefined4 *)(unitState + 0x480);
      *(undefined4 *)(shadowCursor + 8000) = *(undefined4 *)(unitState + 0x484);
      *(undefined4 *)(shadowCursor + 0x1f44) = *(undefined4 *)(unitState + 0x488);
      programConstants = *(int *)(glContext + 0x1e68);
      if (programConstants != 0) {
        if ((1 << (unit & 0x3f) & *(uint *)(((unsigned char *)0x000010d8) + programConstants)) != 0) {
          constantOffset = unit * 0x10;
          *(undefined4 *)(constantOffset + programConstants + 0x8c) = *(undefined4 *)(shadowCursor + 0x1f38);
          *(undefined4 *)(constantOffset + *(int *)(glContext + 0x1e68) + 0x90) =
               *(undefined4 *)(shadowCursor + 0x1f3c);
          *(undefined4 *)(constantOffset + *(int *)(glContext + 0x1e68) + 0x94) = *(undefined4 *)(shadowCursor + 8000)
          ;
          *(undefined4 *)(constantOffset + *(int *)(glContext + 0x1e68) + 0x98) =
               *(undefined4 *)(shadowCursor + 0x1f44);
        }
      }
      unit = unit + 1;
      unitState = unitState + 0xcc;
      shadowCursor = shadowCursor + 0x10;
      unitCount = unitCount - 1;
    } while (unitCount != 0);
  }
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x4000000;
  return;
}

/* gldEmitScissorRegs @ 0x4dd10 (40 bytes) */
int gldEmitScissorRegs(glContext, packet)
  int glContext;
  undefined4 *packet;
{
  *packet = 0x110f8;
  packet[1] = *(undefined4 *)(glContext + 7000);
  packet[2] = *(undefined4 *)(glContext + 0x1b10);
  return packet + 3;
}

/* gldEmitViewportAndGuardBand @ 0x4dd40 (116 bytes) */
int gldEmitViewportAndGuardBand(glContext, packet)
  int glContext;
  undefined4 *packet;
{
  undefined4 glContextWord1c98;
  
  *packet = 0x50766;
  packet[1] = *(undefined4 *)(glContext + 0x1c8c);
  packet[2] = *(undefined4 *)(glContext + 0x1c88);
  packet[3] = *(undefined4 *)(glContext + 0x1c94);
  packet[4] = *(undefined4 *)(glContext + 0x1c90);
  packet[5] = *(undefined4 *)(glContext + 0x1c9c);
  glContextWord1c98 = *(undefined4 *)(glContext + 0x1c98);
  packet[7] = 0x30888;
  packet[6] = glContextWord1c98;
  packet[8] = *(undefined4 *)(glContext + 0x1ca8);
  packet[9] = *(undefined4 *)(glContext + 0x1cac);
  packet[10] = *(undefined4 *)(glContext + 0x1cb0);
  packet[0xb] = *(undefined4 *)(glContext + 0x1cb4);
  return packet + 0xc;
}

/* FUN_0004ddc0 @ 0x4ddc0 (104 bytes) */
int FUN_0004ddc0(glContext)
  int glContext;
{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
  *(undefined4 **)(0x00002748 + glContext + 4) = puVar1;
  puVar1[1] = 0;
  *puVar1 = ((unsigned char *)0x00001040U);
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
  *(int *)(0x00002748 + glContext + 4) = *(int *)(0x00002748 + glContext + 4) + 8;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(glContext,*(int *)(0x00002748 + glContext + 4));
  return;
}

/* FUN_0004de30 @ 0x4de30 (180 bytes) */
int FUN_0004de30(glContext, programEntry, unusedArg3, firstUnit, unitScalePtr, unitCount)
  int glContext;
  int programEntry;
  undefined4 unusedArg3;
  int firstUnit;
  undefined4 *unitScalePtr;
  int unitCount;
{
  undefined4 *constEntry;
  int programState;
  char *unitFlagCursor;
  
  if (programEntry == 0) {
    if (((*(uint *)(glContext + 0x44) & 0x20000) == 0) ||
       (programState = *(int *)(glContext + 0x1e70), programState == 0)) {
      programState = *(int *)(glContext + 0x1e5c);
    }
  }
  else {
    programState = programEntry + 0x124;
  }
  if (0 < unitCount) {
    unitFlagCursor = ((unsigned char *)0x00002ddcU) + firstUnit + programState;
    constEntry = (undefined4 *)(firstUnit * 0x10 + programState + 0x8c);
    do {
      if ((*unitFlagCursor != '\0') && (unitFlagCursor[0x100] == '\0')) {
        *constEntry = *unitScalePtr;
        constEntry[1] = unitScalePtr[1];
        constEntry[2] = unitScalePtr[2];
        constEntry[3] = unitScalePtr[3];
      }
      unitFlagCursor = unitFlagCursor + 1;
      unitScalePtr = unitScalePtr + 4;
      constEntry = constEntry + 4;
      unitCount = unitCount + -1;
    } while (unitCount != 0);
  }
  ((unsigned char *)0x000010eb)[programState] = 0;
  return;
}

/* FUN_0004def0 @ 0x4def0 (2428 bytes) */
double FUN_0004def0(int glContext,undefined4 unusedArg2,uint unitIndexArg,undefined4 unitFormatArg,double fprF1,double fprF2,double fprF3,double fprF4,double fprF5,double fprF6,double fprF7,double fprF8,double fprF9)
{
  int boundProgramEntry;
  int boundProgramTexState;
  uint lodBiasField;
  uint texFormatWord;
  uint texFilterWord;
  uint depthKeyBase;
  uint depthModeKey;
  uint hwUnitIndex;
  int unitScalePtr;
  int unitVectorOffset;
  uint glContextWord44;
  int glContextWord27b4;
  uint txEnable;
  uint loopIndex;
  uint loopIndex2;
  int *nextUnitFlagPtr;
  float rectHeightFloat;
  short texBaseFormat;
  ushort activeUnitMask;
  float rectSumScaled;
  bool lodBiasFromProgram;
  double intToDoubleBias;
  char texObjByte31;
  uint unitCountdown;
  int unitScaleBase;
  uint unitBit;
  uint unitRectDim1;
  uint unitRectDim0;
  int programSlotOffset;
  int programTable;
  int unitWordOffset;
  int unitFlagCursor;
  int texObj;
  int programEntry;
  uint pendingUnitBits;
  int glContextWord1808;
  int texObjCursor;
  int unitRectCursor;
  int unitInfoCursor;
  int unitEnableCursor;
  uint uVar26;
  int texRegCursor;
  double extraout_f1;
  double in_stack_ffffff28;
  
  activeUnitMask = *(ushort *)(glContext + 0x32) | *(ushort *)(glContext + 0x34);
  pendingUnitBits = (uint)activeUnitMask;
  if ((activeUnitMask != 0) && (*(char *)(glContext + 0x121) != '\0')) {
    unitCountdown = (uint)(byte)((unsigned char *)0x000013b0)[glContext];
    if (unitCountdown == 0) {
LAB_0004df78:
      *(undefined1 *)(glContext + 0x120) = 0xff;
    }
    else {
      uVar26 = 0;
      if (*(int *)(glContext + 0x48) != 0) {
        uVar26 = 0;
        unitFlagCursor = glContext;
        do {
          uVar26 = uVar26 + 1;
          unitCountdown = unitCountdown - 1;
          if (unitCountdown == 0) goto LAB_0004df78;
          nextUnitFlagPtr = (int *)(unitFlagCursor + 0x4c);
          unitFlagCursor = unitFlagCursor + 4;
        } while (*nextUnitFlagPtr != 0);
        uVar26 = uVar26 & 0xff;
      }
      *(char *)(glContext + 0x120) = (char)uVar26;
      *(uint *)(glContext + 0x1878) = (uVar26 & 7) << 0x15 | *(uint *)(glContext + 0x1878) & 0xff1fffff;
      *(uint *)(glContext + 0x18a4) = (uVar26 & 7) << 0x1a | *(uint *)(glContext + 0x18a4) & 0xe3ffffff;
    }
  }
  glContextWord27b4 = *(int *)(glContext + 0x27b4);
  glContextWord1808 = *(int *)(glContext + 0x1808);
  txEnable = *(uint *)(glContext + 0x27b0) & ~(glContextWord27b4 << 8);
  *(uint *)(glContext + 0x27b0) = txEnable;
  intToDoubleBias = DOUBLE_001aa1e0;
  if (activeUnitMask != 0) {
    unitScaleBase = glContext + 0x28b4;
    loopIndex = 0;
    hwUnitIndex = 0;
    unitEnableCursor = glContext + 0x20;
    unitFlagCursor = glContext;
    texObjCursor = glContext;
    unitRectCursor = glContext;
    unitInfoCursor = glContext;
    texRegCursor = glContext;
    do {
      if ((pendingUnitBits & 1) != 0) {
        if (glContextWord1808 == 0) {
          texObj = *(int *)(((unsigned char *)0x000013f8) + texObjCursor);
          if (texObj == 0) {
            *(uint *)(glContext + 0x27b0) = *(uint *)(glContext + 0x27b0) & ~(1 << (loopIndex & 0x3f));
          }
          else {
            unitBit = 1 << (loopIndex & 0x3f);
            *(uint *)(glContext + 0x1934) = unitBit | *(uint *)(glContext + 0x1934);
            *(uint *)(glContext + 0x27b0) = unitBit | *(uint *)(glContext + 0x27b0);
            *(undefined4 *)(texRegCursor + 0x1d5c) = *(undefined4 *)(texObj + 0x1c);
            *(undefined4 *)(texRegCursor + 0x1d9c) = *(undefined4 *)(texObj + 0x20);
            *(undefined4 *)(texRegCursor + 0x1ddc) = *(undefined4 *)(texObj + 0x24);
            *(undefined4 *)(unitEnableCursor + 0x1dfc) = *(undefined4 *)(texObj + 0x28);
            *(uint *)(texRegCursor + 0x1cdc) = hwUnitIndex << 0x1c | *(uint *)(texObj + 0x14) & 0xfffffff;
            *(uint *)(texRegCursor + 0x1d1c) =
                 (*(ushort *)(unitInfoCursor + 0x46e) & 0x3ff) << 3 | *(uint *)(texObj + 0x18) & 0xffffe007;
            unitFormatArg = *(undefined4 *)(&DAT_001db98c + (uint)*(byte *)(glContext + 0x2941) * 4);
            unitIndexArg = loopIndex;
            fprF1 = (double)((double (*)())FUN_000b6f20)(glContext,texObj,loopIndex,unitFormatArg,fprF1,fprF2,fprF3
                                            ,fprF4,fprF5,fprF6,fprF7,fprF8,
                                            in_stack_ffffff28);
          }
        }
        else {
          unitBit = 1 << (loopIndex & 0x3f);
          *(uint *)(glContext + 0x1934) = unitBit | *(uint *)(glContext + 0x1934);
          if ((loopIndex == *(uint *)(glContext + 0x276c)) && (*(int *)(glContext + 0x2768) != 0)) {
            texObj = *(int *)(*(int *)(glContext + 0x2768) + 0xbc);
          }
          else {
            texObj = *(int *)(((unsigned char *)0x000013f8) + texObjCursor);
            if (texObj == 0) {
              *(uint *)(glContext + 0x27b0) = ~unitBit & *(uint *)(glContext + 0x27b0);
              *(uint *)(glContext + 0x27b4) = ~unitBit & *(uint *)(glContext + 0x27b4);
              goto LAB_0004e760;
            }
          }
          if ((*(uint *)(glContext + 0x44) & 0x20000) == 0) {
            if (((int)(uint)*(byte *)(glContext + 0x20) >> (loopIndex & 0x3f) & 1U) == 0) {
              lodBiasFromProgram = false;
              unitWordOffset = loopIndex << 2;
              *(uint *)(glContext + 0x27b4) = *(uint *)(glContext + 0x27b4) & ~unitBit;
            }
            else {
              unitVectorOffset = loopIndex * 0x10;
              unitRectDim0 = *(uint *)(unitRectCursor + 0x2854);
              unitRectDim1 = *(uint *)(unitRectCursor + 0x2858);
              unitScalePtr = unitScaleBase + unitVectorOffset;
              if (*(char *)(unitFlagCursor + 0x21) == '\x01') {
                rectHeightFloat = (float)((double)CONCAT44(0x43300000,*(uint *)(unitRectCursor + 0x285c) ^ 0x80000000)
                               - intToDoubleBias);
                *(float *)(unitScaleBase + unitVectorOffset) =
                     *(float *)(texObj + 0x44) /
                     (float)((double)CONCAT44(0x43300000,unitRectDim0 ^ 0x80000000) - intToDoubleBias);
                *(float *)(unitScalePtr + 4) = *(float *)(texObj + 0x44) / rectHeightFloat;
                rectSumScaled = (float)((double)CONCAT44(0x43300000,unitRectDim0 + unitRectDim1 ^ 0x80000000) - intToDoubleBias) *
                        FLOAT_001aa10c;
                *(float *)(unitScalePtr + 8) =
                     -(float)((double)CONCAT44(0x43300000,unitRectDim1 ^ 0x80000000) - intToDoubleBias) / rectHeightFloat;
                *(float *)(unitScalePtr + 0xc) = rectSumScaled / *(float *)(texObj + 0x44);
              }
              else {
                rectHeightFloat = (float)((double)CONCAT44(0x43300000,*(uint *)(unitRectCursor + 0x285c) ^ 0x80000000)
                               - intToDoubleBias);
                *(float *)(unitScaleBase + unitVectorOffset) =
                     *(float *)(texObj + 0x48) /
                     (float)((double)CONCAT44(0x43300000,unitRectDim0 ^ 0x80000000) - intToDoubleBias);
                *(float *)(unitScalePtr + 4) = *(float *)(texObj + 0x48) / rectHeightFloat;
                rectSumScaled = (float)((double)CONCAT44(0x43300000,unitRectDim0 + unitRectDim1 ^ 0x80000000) - intToDoubleBias) *
                        FLOAT_001aa10c;
                *(float *)(unitScalePtr + 8) =
                     -(float)((double)CONCAT44(0x43300000,unitRectDim1 ^ 0x80000000) - intToDoubleBias) / rectHeightFloat;
                *(float *)(unitScalePtr + 0xc) = rectSumScaled / *(float *)(texObj + 0x48);
              }
              unitWordOffset = loopIndex << 2;
              fprF1 = (double)((int (*)())FUN_0004de30)(glContext,0,loopIndex + 0x14,loopIndex + 0x14,unitScalePtr,1);
              lodBiasFromProgram = false;
              *(uint *)(glContext + 0x27b4) = unitBit | *(uint *)(glContext + 0x27b4);
            }
          }
          else {
            unitWordOffset = loopIndex * 4;
            texBaseFormat = *(short *)(texObj + 0x38);
            *(uint *)(unitWordOffset + *(int *)(((unsigned char *)0x00001144) + glContext) + 0x2c) =
                 (uint)*(byte *)(texObj + 0x30);
            programTable = *(int *)(((unsigned char *)0x00001154) + glContext);
            if (*(int *)(programTable + 4) != 0) {
              loopIndex2 = 0;
              programSlotOffset = 0;
              do {
                programEntry = *(int *)(*(int *)(((unsigned char *)0x0000113c) + glContext) * 4 +
                                 *(int *)(programSlotOffset + *(int *)(programTable + 0x88) + 0x70));
                if ((programEntry != 0) &&
                   ((bool)((unsigned char *)0x00002eb0)[loopIndex + programEntry] != (*(char *)(texObj + 0x30) == '\x02')))
                {
                  *(undefined4 *)(((unsigned char *)0x000016f0) + programEntry) = 1;
                  *(undefined1 *)(programEntry + 0x119) = 1;
                  programTable = *(int *)(((unsigned char *)0x00001154) + glContext);
                }
                loopIndex2 = loopIndex2 + 1;
                programSlotOffset = programSlotOffset + 0x78;
              } while (loopIndex2 < *(uint *)(programTable + 4));
            }
            if ((*(uint *)(glContext + 0x44) & 0x2000) == 0) {
LAB_0004e294:
              lodBiasFromProgram = false;
            }
            else {
              boundProgramEntry = *(int *)(*(int *)(((unsigned char *)0x00001130) + glContext) * 4 +
                               *(int *)(*(int *)(((unsigned char *)0x0000121c) + glContext) + 0x70));
              if (boundProgramEntry != 0) {
                boundProgramTexState = boundProgramEntry + 0x124;
              }
              else {
                boundProgramTexState = 0;
              }
              depthModeKey = 0;
              if (texBaseFormat == 0x1902) {
                depthKeyBase = (*(ushort *)(texObj + 0x5c) - 0x200) * 2;
                depthModeKey = depthKeyBase | 1;
                if (*(short *)(texObj + 0x58) == 0x1909) {
                  depthModeKey = depthKeyBase | 0x11;
                }
                else if (*(short *)(texObj + 0x58) == -0x7fb7) {
                  depthModeKey = depthKeyBase | 0x21;
                }
              }
              if (boundProgramTexState == 0) goto LAB_0004e294;
              if ((depthModeKey != *(uint *)(((unsigned char *)0x000015d0) + unitWordOffset + boundProgramTexState)) &&
                 (*(undefined4 *)(((unsigned char *)0x000015cc) + boundProgramTexState) = 1, boundProgramEntry != 0)) {
                *(undefined1 *)(boundProgramEntry + 0x119) = 1;
              }
              if (((unsigned char *)0x00001610)[loopIndex + boundProgramTexState] == '\0') goto LAB_0004e294;
              lodBiasFromProgram = true;
              if (*(float *)(((unsigned char *)0x00001620) + unitWordOffset + boundProgramTexState) !=
                  *(float *)(texObj + 0x4c) + *(float *)(unitInfoCursor + 0x470)) {
                boundProgramEntry = *(int *)(*(int *)(((unsigned char *)0x00001130) + glContext) * 4 +
                                 *(int *)(*(int *)(((unsigned char *)0x0000121c) + glContext) + 0x70));
                if (boundProgramEntry != 0) {
                  *(undefined1 *)(boundProgramEntry + 0x119) = 1;
                }
                lodBiasFromProgram = true;
                *(undefined4 *)(((unsigned char *)0x000015cc) + boundProgramTexState) = 1;
              }
            }
            *(uint *)(glContext + 0x27b4) = *(uint *)(glContext + 0x27b4) & ~unitBit;
          }
          *(uint *)(glContext + 0x27b0) = unitBit | *(uint *)(glContext + 0x27b0);
          *(undefined4 *)(texRegCursor + 0x1d5c) = *(undefined4 *)(texObj + 0x1c);
          *(undefined4 *)(texRegCursor + 0x1d9c) = *(undefined4 *)(texObj + 0x20);
          *(undefined4 *)(texRegCursor + 0x1ddc) = *(undefined4 *)(texObj + 0x24);
          *(undefined4 *)(unitWordOffset + glContext + 0x1e1c) = *(undefined4 *)(texObj + 0x28);
          *(uint *)(texRegCursor + 0x1cdc) = hwUnitIndex << 0x1c | *(uint *)(texObj + 0x14) & 0xfffffff;
          texFilterWord = *(uint *)(texObj + 0x18);
          if (lodBiasFromProgram) {
            texFilterWord = texFilterWord & 0xffffe007;
          }
          else {
            fprF2 = (double)*(float *)(texObj + 0x4c);
            if (fprF2 == (double)FLOAT_001aa0d4) {
              texFilterWord = (*(ushort *)(unitInfoCursor + 0x46e) & 0x3ff) << 3 | texFilterWord & 0xffffe007;
            }
            else {
              lodBiasField = ((int (*)())FUN_00086930)(glContext,(double)*(float *)(unitInfoCursor + 0x470),fprF2);
              texFilterWord = (lodBiasField & 0x3ff) << 3 | texFilterWord & 0xffffe007;
              fprF1 = extraout_f1;
            }
          }
          *(uint *)(texRegCursor + 0x1d1c) = texFilterWord;
          unitFormatArg = *(undefined4 *)(&DAT_001db98c + (uint)*(byte *)(glContext + 0x2941) * 4);
          unitIndexArg = loopIndex;
          fprF1 = (double)((double (*)())FUN_000b6f20)(glContext,texObj,loopIndex,unitFormatArg,fprF1,fprF2,fprF3,
                                          fprF4,fprF5,fprF6,fprF7,fprF8,
                                          in_stack_ffffff28);
          texFormatWord = *(uint *)(texObj + 0x14);
          if ((texFormatWord & 0x1e00) == 0xa00) {
            if ((texFormatWord & 7) == 4) {
              *(uint *)(unitWordOffset + glContext + 0x1cdc) =
                   *(uint *)(unitWordOffset + glContext + 0x1cdc) & 0xfffffff8 | 2;
              texFormatWord = *(uint *)(texObj + 0x14);
            }
            else if ((texFormatWord & 7) == 5) {
              *(uint *)(unitWordOffset + glContext + 0x1cdc) =
                   *(uint *)(unitWordOffset + glContext + 0x1cdc) & 0xfffffff8 | 3;
              texFormatWord = *(uint *)(texObj + 0x14);
            }
            if ((texFormatWord & 0x38) == 0x20) {
              *(uint *)(unitWordOffset + glContext + 0x1cdc) =
                   *(uint *)(unitWordOffset + glContext + 0x1cdc) & 0xffffffc7 | 0x10;
              texFormatWord = *(uint *)(texObj + 0x14);
            }
            else if ((texFormatWord & 0x38) == 0x28) {
              *(uint *)(unitWordOffset + glContext + 0x1cdc) =
                   *(uint *)(unitWordOffset + glContext + 0x1cdc) & 0xffffffc7 | 0x18;
              texFormatWord = *(uint *)(texObj + 0x14);
            }
            if ((texFormatWord & 0x1c0) == 0x100) {
              *(uint *)(unitWordOffset + glContext + 0x1cdc) =
                   *(uint *)(unitWordOffset + glContext + 0x1cdc) & 0xfffffe3f | 0x80;
            }
            else if ((texFormatWord & 0x1c0) == 0x140) {
              *(uint *)(unitWordOffset + glContext + 0x1cdc) =
                   *(uint *)(unitWordOffset + glContext + 0x1cdc) & 0xfffffe3f | 0xc0;
            }
          }
          texObjByte31 = *(char *)(texObj + 0x31);
          if (texObjByte31 != '\x03') {
            *(uint *)(unitWordOffset + glContext + 0x1cdc) = *(uint *)(unitWordOffset + glContext + 0x1cdc) & 0xfffffe3f
            ;
            texObjByte31 = *(char *)(texObj + 0x31);
          }
          if (texObjByte31 == '\x01') {
            *(uint *)(unitWordOffset + glContext + 0x1cdc) = *(uint *)(unitWordOffset + glContext + 0x1cdc) & 0xffffffc7
            ;
          }
          unitWordOffset = unitWordOffset + glContext;
          *(uint *)(unitWordOffset + 0x1d1c) =
               (*(ushort *)(unitInfoCursor + 0x46e) & 0x3ff) << 3 | *(uint *)(unitWordOffset + 0x1d1c) & 0xffffe007;
          if ((unitBit & *(uint *)(glContext + 0x27b4)) != 0) {
            *(undefined4 *)(texRegCursor + 0x1cfc) = *(undefined4 *)(texRegCursor + 0x1cdc);
            *(uint *)(unitEnableCursor + 0x1cdc) =
                 (hwUnitIndex + 8) * 0x10000000 | *(uint *)(unitEnableCursor + 0x1cdc) & 0xfffffff;
            *(undefined4 *)(texRegCursor + 0x1d3c) = *(undefined4 *)(texRegCursor + 0x1d1c);
            *(undefined4 *)(texRegCursor + 0x1d7c) = *(undefined4 *)(texRegCursor + 0x1d5c);
            *(undefined4 *)(texRegCursor + 0x1dbc) = *(undefined4 *)(texRegCursor + 0x1d9c);
            *(undefined4 *)(texRegCursor + 0x1dfc) = *(undefined4 *)(texRegCursor + 0x1ddc);
            *(undefined4 *)(texRegCursor + 0x1e3c) = *(undefined4 *)(texRegCursor + 0x1e1c);
            if (*(char *)(unitFlagCursor + 0x21) == '\x01') {
              *(uint *)(unitWordOffset + 0x1d5c) =
                   *(int *)(unitRectCursor + 0x2854) - 1U & 0x7ff | *(uint *)(unitWordOffset + 0x1d5c) & 0xfffff800;
              *(uint *)(unitEnableCursor + 0x1d5c) =
                   *(int *)(unitRectCursor + 0x285c) - 1U & 0x7ff | *(uint *)(unitEnableCursor + 0x1d5c) & 0xfffff800;
            }
            else {
              *(uint *)(unitWordOffset + 0x1d5c) =
                   (*(int *)(unitRectCursor + 0x2854) + -1) * 0x800 & 0x3ff800U |
                   *(uint *)(unitWordOffset + 0x1d5c) & 0xffc007ff;
              *(uint *)(unitEnableCursor + 0x1d5c) =
                   (*(int *)(unitRectCursor + 0x285c) + -1) * 0x800 & 0x3ff800U |
                   *(uint *)(unitEnableCursor + 0x1d5c) & 0xffc007ff;
            }
          }
        }
      }
LAB_0004e760:
      pendingUnitBits = pendingUnitBits >> 1;
      loopIndex = loopIndex + 1;
      hwUnitIndex = hwUnitIndex + 1 & 0xf;
      unitEnableCursor = unitEnableCursor + 4;
      texRegCursor = texRegCursor + 4;
      unitInfoCursor = unitInfoCursor + 0xcc;
      unitRectCursor = unitRectCursor + 0xc;
      texObjCursor = texObjCursor + 4;
      unitFlagCursor = unitFlagCursor + 1;
    } while (pendingUnitBits != 0);
    glContextWord27b4 = *(int *)(glContext + 0x27b4);
    txEnable = *(uint *)(glContext + 0x27b0);
  }
  glContextWord44 = *(uint *)(glContext + 0x44);
  *(uint *)(glContext + 0x27b0) = glContextWord27b4 << 8 | txEnable;
  if (((glContextWord44 & 0x100000) != 0) && (*(code **)((int)((unsigned char *)0x000011cc) + glContext) != (code *)0x0)) {
    fprF1 = (double)(**(code **)((int)((unsigned char *)0x000011cc) + glContext))(glContext);
    glContextWord44 = *(uint *)(glContext + 0x44);
  }
  if ((glContextWord44 & 0x20000) == 0) {
    FUN_000b6580(glContext,0);
                    
                    
    (**(code **)(glContext + 0x294c))(glContext,*(undefined4 *)(glContext + 0x1e5c));
    return;
  }
  if ((glContextWord44 & 0x2000) == 0) {
    atifsCompileCurrentShader(glContext);
    return;
  }
  ((undefined4 (*)())FUN_000afe40)(glContext,0,unitIndexArg,unitFormatArg,fprF1);
  return;
}

/* FUN_0004e880 @ 0x4e880 (252 bytes) */
int FUN_0004e880(glContext)
  int glContext;
{
  uint glContextWord243c;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  if (*(int *)(glContext + 0x243c) != 0) {
    glContextWord243c = *(int *)(glContext + 0x243c) + 1U >> 1;
    puVar2 = (uint *)(**(code **)(glContext + 0x2758))(glContext,glContextWord243c * 2 + 2);
    *(uint **)(0x00002748 + glContext + 4) = puVar2;
    uVar4 = (glContextWord243c - 1) * 0x10000;
    *puVar2 = uVar4 | 0x854;
    puVar2[glContextWord243c + 1] = uVar4 | 0x878;
    if (glContextWord243c != 0) {
      iVar3 = 0;
      uVar4 = glContextWord243c;
      do {
        *(undefined4 *)((int)puVar2 + iVar3 + 4) =
             *(undefined4 *)(iVar3 + *(int *)(glContext + 0x2440));
        *(undefined4 *)((int)puVar2 + iVar3 + glContextWord243c * 4 + 8) =
             *(undefined4 *)(iVar3 + *(int *)(glContext + 0x2444));
        iVar3 = iVar3 + 4;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
    *(uint *)(0x00002748 + glContext + 4) = glContextWord243c * 8 + *(int *)(0x00002748 + glContext + 4) + 8;
                    
                    
    (*UNRECOVERED_JUMPTABLE)(glContext,*(int *)(0x00002748 + glContext + 4));
    return;
  }
  return;
}

/* FUN_0004e990 @ 0x4e990 (208 bytes) */
int FUN_0004e990(glContext)
  int glContext;
{
  uint uVar1;
  int iVar2;
  double dVar3;
  
  uVar1 = *(uint *)(*(int *)(glContext + 4) + 0x154) & 0x30000;
  dVar3 = DOUBLE_001aa288;
  if (((uVar1 != 0x20000) && (uVar1 != 0x30000)) && (dVar3 = DOUBLE_001aa280, uVar1 == 0x10000)) {
    dVar3 = DOUBLE_001aa278;
  }
  dVar3 = dVar3 * *(double *)(((unsigned char *)0x00002d88) + *(int *)(*(int *)(glContext + 4) + 0x10));
  if (DOUBLE_001aa1e8 <= dVar3) {
    iVar2 = (int)(dVar3 - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    iVar2 = (int)dVar3;
  }
  return iVar2;
}

/* gldValidatePolygonMode @ 0x4ea70 (260 bytes) */
double gldValidatePolygonMode(int glContext,double fprF1,double fprF2,double fprF3,double fprF4,double fprF5,double fprF6,double fprF7,double fprF8)
{
  short backPolygonMode;
  short frontPolygonMode;
  uint newModeWord;
  int glStateBlock;
  uint oldModeWord;
  
  oldModeWord = *(uint *)(glContext + 0x1b3c);
  glStateBlock = *(int *)(*(int *)(glContext + 4) + 0x10);
  if (*(int *)(((unsigned char *)0x00003170) + glStateBlock) == 0x1b021b02) {
    newModeWord = oldModeWord & 0xfffffffc;
    *(uint *)(glContext + 0x1b3c) = newModeWord;
  }
  else {
    *(uint *)(glContext + 0x1b3c) = oldModeWord & 0xfffffffc | 1;
    frontPolygonMode = *(short *)(((unsigned char *)0x00003170) + glStateBlock);
    if (frontPolygonMode == 0x1b01) {
      *(uint *)(glContext + 0x1b3c) = oldModeWord & 0xffffff8c | 0x11;
    }
    else if (frontPolygonMode == 0x1b02) {
      *(uint *)(glContext + 0x1b3c) = oldModeWord & 0xffffff8c | 0x21;
    }
    else if (frontPolygonMode == 0x1b00) {
      *(uint *)(glContext + 0x1b3c) = oldModeWord & 0xffffff8c | 1;
    }
    backPolygonMode = *(short *)(((unsigned char *)0x00003172) + glStateBlock);
    if (backPolygonMode == 0x1b01) {
      newModeWord = *(uint *)(glContext + 0x1b3c) & 0xfffffc7f | 0x80;
      *(uint *)(glContext + 0x1b3c) = newModeWord;
    }
    else if (backPolygonMode == 0x1b02) {
      newModeWord = *(uint *)(glContext + 0x1b3c) & 0xfffffc7f | 0x100;
      *(uint *)(glContext + 0x1b3c) = newModeWord;
    }
    else if (backPolygonMode == 0x1b00) {
      newModeWord = *(uint *)(glContext + 0x1b3c) & 0xfffffc7f;
      *(uint *)(glContext + 0x1b3c) = newModeWord;
    }
    else {
      newModeWord = *(uint *)(glContext + 0x1b3c);
    }
  }
  if (oldModeWord != newModeWord) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x2000;
  }
  ((void (*)())gldValidateViewportPolygonOffset)(glContext,fprF1,fprF2,fprF3,fprF4,fprF5,fprF6,fprF7,fprF8);
  return;
}

/* FUN_0004eba0 @ 0x4eba0 (476 bytes) */
int FUN_0004eba0(glContext, param_2, staleArgR5, staleArgR6, staleArgR7, staleArgR8, staleArgR9)
  int glContext;
  undefined4 param_2;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  undefined4 staleArgR9;
{
  int glContextWord4;
  int glStateBlock;
  int resolveFlag;
  int depthBiasScale;
  undefined4 drawSurface;
  int glState;
  int glContextWord8;
  int glContextWord2768;
  double extraout_f1;
  double extraout_f1_00;
  double dVar6;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  glContextWord4 = *(int *)(glContext + 4);
  glContextWord2768 = *(int *)(glContext + 0x2768);
  glContextWord8 = *(int *)(glContext + 8);
  if ((((((unsigned char *)0x00002e2d)[*(int *)(glContextWord4 + 0x10)] == '\0') ||
       ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
      (glContextWord4 = gld_needsMultisampleResolve(glContextWord4,*(undefined4 *)(glContextWord4 + 0x26a0),staleArgR5,staleArgR6,staleArgR7,staleArgR8,
                            staleArgR9), glContextWord4 != 0)) || (glContextWord2768 == 0)) {
    glState = *(int *)(glContext + 4);
    depthBiasScale = ((uint (*)())FUN_000a3560)(glContext,(double)*(float *)(((unsigned char *)0x00002e20) + *(int *)(glState + 0x10)));
    drawSurface = *(undefined4 *)(*(int *)(glContext + 4) + 0x26a0);
    *(short *)(glContext + 0x1b42) = (short)((uint)(glContextWord8 * depthBiasScale) >> 1);
    resolveFlag = gld_needsMultisampleResolve(*(int *)(glContext + 4),drawSurface,staleArgR5,staleArgR6,staleArgR7,staleArgR8,glState);
    dVar6 = extraout_f1_00;
    if (resolveFlag == 0) {
      *(uint *)(glContext + 0x1b40) = *(uint *)(glContext + 0x1b40) & 0xfffcffff | 0x20000;
    }
    else {
      *(uint *)(glContext + 0x1b40) = *(uint *)(glContext + 0x1b40) & 0xfffcffff | 0x30000;
    }
  }
  else {
    *(short *)(glContext + 0x1b42) = (short)*(undefined4 *)(glContextWord2768 + 0x18);
    *(uint *)(glContext + 0x1b40) = *(uint *)(glContext + 0x1b40) & 0xfffcffff | 0x30000;
    dVar6 = extraout_f1;
  }
  glStateBlock = *(int *)(*(int *)(glContext + 4) + 0x10);
  if (((((unsigned char *)0x00002e2c)[glStateBlock] != '\0') && ((*(uint *)(glContext + 0x44) & 0x20000) == 0)) &&
     (*(short *)(((unsigned char *)0x00002e28) + glStateBlock) != -1)) {
    *(uint *)(glContext + 0x1b64) =
         (uint)(int)(FLOAT_001aa0e8 /
               ((float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00002e24) + glStateBlock) ^ 0x80000000) -
                       DOUBLE_001aa1e0) * FLOAT_001aa0fc *
               (float)((double)CONCAT44(0x43300000,glContextWord8) - DOUBLE_001aa250))) & 0xfffffffc |
         *(uint *)(glContext + 0x1b64) & 3;
  }
  if (glContextWord2768 != 0) {
    *(undefined4 *)(glContext + 0x1b70) = *(undefined4 *)(glContextWord2768 + 0x24);
  }
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x4000;
  ((void (*)())gldValidateViewportPolygonOffset)(glContext,dVar6,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* FUN_0004ed90 @ 0x4ed90 (692 bytes) */
int FUN_0004ed90(glContext)
  int glContext;
{
  uint registerDirty;
  float glContextWord104;
  float glContextWord100;
  float fVar1;
  float fVar2;
  undefined2 uVar3;
  int iVar4;
  uint glContextWord44;
  int glContextWord8;
  int glContextWord2768;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  glContextWord2768 = *(int *)(glContext + 0x2768);
  glContextWord8 = *(int *)(glContext + 8);
  iVar4 = FUN_000a3670(glContext);
  glContextWord44 = *(uint *)(glContext + 0x44);
  if (((glContextWord44 & 0x60020000) == 0x40000000) && (glContextWord2768 != 0)) {
    *(short *)(glContext + 0x1ccc) = (short)*(undefined4 *)(glContextWord2768 + 4);
    *(short *)(glContext + 0x1cce) = (short)*(undefined4 *)(glContextWord2768 + 4);
    *(undefined4 *)(glContext + 0x1cc0) = *(undefined4 *)(glContextWord2768 + 0xc);
    *(undefined4 *)(glContext + 0x1cc8) = *(undefined4 *)(glContextWord2768 + 0x10);
  }
  else {
    if (iVar4 == 0) {
      uVar3 = (undefined2)((uint)(glContextWord8 * *(int *)(glContext + 0xe4)) >> 1);
    }
    else {
      uVar3 = (undefined2)((uint)(int)(glContextWord8 * (int)(*(float *)(glContext + 0xf0) + FLOAT_001aa10c)) >> 1);
    }
    *(undefined2 *)(glContext + 0x1cce) = uVar3;
    *(undefined2 *)(glContext + 0x1ccc) = uVar3;
  }
  if ((glContextWord44 & 0x60020000) == 0x40000000) {
    if (iVar4 == 0) {
      glContextWord100 = *(float *)(glContext + 0x100) + FLOAT_001aa0e8;
      glContextWord104 = *(float *)(glContext + 0x104) + FLOAT_001aa0e8;
    }
    else {
      if ((glContextWord44 & 0x80) != 0) {
        fVar2 = *(float *)(((unsigned char *)0x000013c4) + glContext);
        fVar1 = (float)((double)CONCAT44(0x43300000,glContextWord8) - DOUBLE_001aa250);
        *(short *)(glContext + 0x1cd0) =
             (short)((int)(fVar1 * *(float *)(((unsigned char *)0x000013c8U) + glContext)) >> 1);
        *(short *)(glContext + 0x1cd2) = (short)((int)(fVar1 * fVar2) >> 1);
        goto LAB_0004efc0;
      }
      glContextWord100 = *(float *)(glContext + 0x100);
      glContextWord104 = *(float *)(glContext + 0x104);
    }
    *(short *)(glContext + 0x1cd2) = (short)((uint)(int)(glContextWord8 * (int)glContextWord100) >> 1);
    *(short *)(glContext + 0x1cd0) = (short)((uint)(int)(glContextWord8 * (int)glContextWord104) >> 1);
  }
  else if ((glContextWord44 & 0x80) == 0) {
    *(short *)(glContext + 0x1cd2) = (short)((uint)(glContextWord8 * *(int *)(glContext + 0x108)) >> 1);
    *(short *)(glContext + 0x1cd0) = (short)((uint)(glContextWord8 * *(int *)(glContext + 0x10c)) >> 1);
  }
  else {
    iVar4 = *(int *)(((unsigned char *)0x000013d4) + glContext);
    *(short *)(glContext + 0x1cd2) = (short)(glContextWord8 * *(int *)(((unsigned char *)0x000013d0U) + glContext) >> 1);
    *(short *)(glContext + 0x1cd0) = (short)(glContextWord8 * iVar4 >> 1);
  }
LAB_0004efc0:
  *(uint *)(glContext + 0x1b74) = *(uint *)(glContext + 0x1b74) & 0xffff3fff;
  if ((glContextWord44 & 0x20000000) == 0) {
    *(undefined4 *)(glContext + 0x1cbc) = 0;
    *(undefined4 *)(glContext + 0x1cc4) = 0;
  }
  else {
    *(undefined4 *)(glContext + 0x1cc0) = 0x3f800000;
    *(undefined4 *)(glContext + 0x1cbc) = 0;
    *(undefined4 *)(glContext + 0x1cc4) = 0x3f800000;
    *(undefined4 *)(glContext + 0x1cc8) = 0;
  }
  if (*(int *)(glContext + 0x2768) == 0) {
    if ((glContextWord44 & 0x20000000) == 0) {
      *(undefined4 *)(glContext + 0x1b50) = 7;
      if ((*(uint *)(glContext + 0x1a64) & 0x10) != 0) {
        *(uint *)(glContext + 0x1a64) = *(uint *)(glContext + 0x1a64) & 0xffffffef;
        registerDirty = *(uint *)(glContext + 0x1930) | 0x2000;
        *(uint *)(glContext + 0x1930) = registerDirty;
        goto LAB_0004f054;
      }
    }
  }
  registerDirty = *(uint *)(glContext + 0x1930);
LAB_0004f054:
  *(uint *)(glContext + 0x1930) = registerDirty | 0xc08000;
  ((void (*)())gldValidateViewportPolygonOffset)(glContext,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* gldValidateCullFace @ 0x4f080 (192 bytes) */
int gldValidateCullFace(glContext)
  int glContext;
{
  short cullMode;
  uint faceControl;
  int glState;
  
  glState = *(int *)(*(int *)(glContext + 4) + 0x10);
  if (((unsigned char *)0x000013b8)[glContext] == '\0') {
    if (*(short *)(((unsigned char *)0x00003174) + glState) == 0x900) goto LAB_0004f0c0;
  }
  else if (*(short *)(((unsigned char *)0x00003174) + glState) != 0x900) {
LAB_0004f0c0:
    faceControl = *(uint *)(glContext + 0x1b30) & 0xfffffffb;
    *(uint *)(glContext + 0x1b30) = faceControl;
    goto LAB_0004f0dc;
  }
  faceControl = *(uint *)(glContext + 0x1b30) | 4;
  *(uint *)(glContext + 0x1b30) = faceControl;
LAB_0004f0dc:
  if (((unsigned char *)0x0000317a)[glState] == '\0') {
    *(uint *)(glContext + 0x1b30) = faceControl & 0xfffffffc;
  }
  else {
    cullMode = *(short *)(((unsigned char *)0x00003176) + glState);
    if (cullMode == 0x405) {
      *(uint *)(glContext + 0x1b30) = faceControl & 0xfffffffe | 2;
    }
    else if (cullMode == 0x408) {
      *(uint *)(glContext + 0x1b30) = faceControl | 3;
    }
    else if (cullMode == 0x404) {
      *(uint *)(glContext + 0x1b30) = faceControl & 0xfffffffd | 1;
    }
  }
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x400;
  return;
}

/* FUN_0004f160 @ 0x4f160 (352 bytes) */
int FUN_0004f160(glContext, channel)
  int glContext;
  int channel;
{
  double redScaled;
  double blueScaled;
  uint channelByte;
  int glStateBlock;
  uint highBits;
  double greenScaled;
  
  glStateBlock = *(int *)(*(int *)(glContext + 4) + 0x10);
  if (channel == 2) {
    greenScaled = (double)(*(float *)(((unsigned char *)0x00002de4) + glStateBlock) * FLOAT_001aa0f0);
    if (DOUBLE_001aa1e8 <= greenScaled) {
      channelByte = (int)(greenScaled - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      channelByte = (uint)(int)(*(float *)(((unsigned char *)0x00002de4) + glStateBlock) * FLOAT_001aa0f0);
    }
  }
  else if (channel == 3) {
    blueScaled = (double)(*(float *)(((unsigned char *)0x00002de8) + glStateBlock) * FLOAT_001aa0f0);
    if (DOUBLE_001aa1e8 <= blueScaled) {
      channelByte = (int)(blueScaled - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      channelByte = (uint)(int)(*(float *)(((unsigned char *)0x00002de8) + glStateBlock) * FLOAT_001aa0f0);
    }
  }
  else {
    if (channel != 1) {
      channelByte = 0;
      highBits = 0;
      goto LAB_0004f2c8;
    }
    redScaled = (double)(*(float *)(((unsigned char *)0x00002de0) + glStateBlock) * FLOAT_001aa0f0);
    if (DOUBLE_001aa1e8 <= redScaled) {
      channelByte = (int)(redScaled - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      channelByte = (uint)(int)(*(float *)(((unsigned char *)0x00002de0) + glStateBlock) * FLOAT_001aa0f0);
    }
  }
  highBits = channelByte >> 6;
  channelByte = channelByte << 2;
LAB_0004f2c8:
  return highBits & 3 | channelByte;
}

/* FUN_0004f2e0 @ 0x4f2e0 (616 bytes) */
void FUN_0004f2e0(int glContext,undefined4 param_2,undefined4 unusedArgR5,undefined4 unused,double fparam_1)
{
  byte colorFormatIndex;
  short sVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar3 = PTR_DAT_001e88c8;
  colorFormatIndex = *(byte *)(glContext + 0x293f);
  if ((*(uint *)(glContext + 0x44) & 0x1002000) == 0x1000000) {
    iVar4 = *(int *)(*(int *)(glContext + 4) + 0x10);
    sVar2 = *(short *)(((unsigned char *)0x00002e04) + iVar4);
    if (sVar2 == 0x801) {
      *(undefined4 *)(glContext + 0x134) = 0;
      *(float *)(glContext + 0x138) =
           -(*(float *)(((unsigned char *)0x00002df0) + iVar4) * *(float *)(((unsigned char *)0x00002df0) + iVar4));
    }
    else if (sVar2 == 0x2601) {
      *(float *)(glContext + 0x134) =
           *(float *)(((unsigned char *)0x00002df8) + iVar4) * *(float *)(((unsigned char *)0x00002dfc) + iVar4);
      *(float *)(glContext + 0x138) = -*(float *)(((unsigned char *)0x00002dfc) + iVar4);
    }
    else if (sVar2 == 0x800) {
      *(undefined4 *)(glContext + 0x134) = 0;
      *(float *)(glContext + 0x138) = -*(float *)(((unsigned char *)0x00002df0) + iVar4);
    }
    *(uint *)(glContext + 0x18a4) = *(uint *)(glContext + 0x18a4) & 0xfdffffff;
    *(uint *)(glContext + 0x1a64) = *(uint *)(glContext + 0x1a64) & 0xfffffff8 | 1;
    *(uint *)(glContext + 0x1878) = *(uint *)(glContext + 0x1878) & 0xffefffff;
    *(uint *)(glContext + 0x1aec) = *(uint *)(glContext + 0x1aec) & 0xfffffff9 | 1;
    *(undefined4 *)(glContext + 0x1a78) = 0x3f800000;
    *(undefined4 *)(glContext + 0x1a7c) = 0xbf800000;
    if (*(char *)(glContext + 0x121) != '\0') {
      *(undefined1 *)(glContext + 0x121) = 0;
      *(undefined1 *)(glContext + 0x29) = 1;
      *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x1000;
    }
  }
  else {
    *(uint *)(glContext + 0x1aec) = *(uint *)(glContext + 0x1aec) & 0xfffffffe;
    *(uint *)(glContext + 0x18a4) = *(uint *)(glContext + 0x18a4) & 0xfdffffff;
    *(uint *)(glContext + 0x1878) = *(uint *)(glContext + 0x1878) & 0xffefffff;
    if (*(char *)(glContext + 0x121) != '\0') {
      *(undefined1 *)(glContext + 0x121) = 0;
      *(undefined1 *)(glContext + 0x29) = 1;
      *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x1000;
    }
  }
  if ((*(uint *)(glContext + 0x44) & 0x20000) == 0) {
    FUN_000b6580(glContext,0);
    (**(code **)(glContext + 0x294c))(glContext,*(undefined4 *)(glContext + 0x1e5c));
  }
  else if ((*(uint *)(glContext + 0x44) & 0x2000) == 0) {
    atifsCompileCurrentShader(glContext);
  }
  else {
    ((undefined4 (*)())FUN_000afe40)(glContext,0,unusedArgR5,unused,fparam_1);
  }
  uVar5 = ((int (*)())FUN_0004f160)(glContext,*(uint *)(puVar3 + (uint)colorFormatIndex * 0x24 + 0x1c) >> 0x1e);
  *(uint *)(glContext + 0x1a54) = uVar5 & 0x3ff | *(uint *)(glContext + 0x1a54) & 0xfffffc00;
  uVar5 = ((int (*)())FUN_0004f160)(glContext,*(uint *)(puVar3 + (uint)colorFormatIndex * 0x24 + 0x18) >> 1 & 3);
  *(uint *)(glContext + 0x1a58) = uVar5 & 0x3ff | *(uint *)(glContext + 0x1a58) & 0xfffffc00;
  uVar5 = ((int (*)())FUN_0004f160)(glContext,*(uint *)(puVar3 + (uint)colorFormatIndex * 0x24 + 0x18) >> 3 & 3);
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 1;
  *(uint *)(glContext + 0x1a5c) = uVar5 & 0x3ff | *(uint *)(glContext + 0x1a5c) & 0xfffffc00;
  return;
}

/* gldValidateScissor @ 0x4f550 (452 bytes) */
int gldValidateScissor(glContext)
  int glContext;
{
  bool changed;
  uint bottom;
  uint left;
  uint scaledLeft;
  uint top;
  uint oldTopLeft;
  uint right;
  
  left = 0;
  scaledLeft = (uint)(int)((float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00001358) + glContext) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) * *(float *)(glContext + 0x2814));
  bottom = (uint)(int)(*(float *)(glContext + 0x2818) *
                 (float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00001364) + glContext) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) - FLOAT_001aa0e8);
  top = (uint)(int)((float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x0000135c) + glContext) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) * *(float *)(glContext + 0x2818));
  right = (uint)(int)(*(float *)(glContext + 0x2814) *
                 (float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00001360) + glContext) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) - FLOAT_001aa0e8);
  if (-1 < (int)scaledLeft) {
    left = scaledLeft & 0xffff;
  }
  if ((int)(uint)*(ushort *)(((unsigned char *)0x000013bc) + glContext) < (int)right) {
    right = (uint)*(ushort *)(((unsigned char *)0x000013bc) + glContext);
  }
  if (((unsigned char *)0x000013b8)[glContext] == '\0') {
    scaledLeft = 0;
    if (-1 < (int)top) {
      scaledLeft = top & 0xffff;
    }
    if ((int)(*(ushort *)(((unsigned char *)0x000013ba) + glContext) - 1) < (int)bottom) {
      bottom = *(ushort *)(((unsigned char *)0x000013ba) + glContext) - 1;
    }
  }
  else {
    scaledLeft = 0xffff;
    if (-2 < (int)top) {
      scaledLeft = top & 0xffff;
    }
    if ((int)(uint)*(ushort *)(((unsigned char *)0x000013ba) + glContext) < (int)bottom) {
      bottom = (uint)*(ushort *)(((unsigned char *)0x000013ba) + glContext);
    }
  }
  oldTopLeft = *(uint *)(glContext + 7000);
  top = *(uint *)(glContext + 0x1b10);
  scaledLeft = (scaledLeft & 0x1fff) << 0xd | left & 0x1fff | oldTopLeft & 0xfc000000;
  bottom = (bottom & 0x1fff) << 0xd | right & 0x1fff | top & 0xfc000000;
  *(uint *)(glContext + 7000) = scaledLeft;
  *(uint *)(glContext + 0x1b10) = bottom;
  if ((oldTopLeft != scaledLeft) || (changed = false, top != bottom)) {
    changed = true;
  }
  if (changed) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 2;
    return;
  }
  return;
}

/* gldInitStateDefaults @ 0x4f720 (1348 bytes) */
int gldInitStateDefaults(glContext)
  int glContext;
{
  uint glContextWord2454;
  uint scEdgerule;
  float fVar1;
  int glContextWord23d0;
  undefined4 uVar3;
  uint rb3dRopcntl;
  uint rb3dColorChannelMask;
  int iVar6;
  
  *(undefined4 *)(glContext + 0x1bd0) = 0;
  *(undefined4 *)(glContext + 0x1930) = 0;
  *(undefined4 *)(glContext + 0x1934) = 0;
  *(undefined4 *)(glContext + 0x1938) = 0;
  *(undefined4 *)(glContext + 0x193c) = 0;
  *(undefined4 *)(glContext + 0x1a4c) = 0;
  *(undefined4 *)(glContext + 0x1a50) = 0;
  *(undefined4 *)(glContext + 0x1a54) = 0;
  *(undefined4 *)(glContext + 0x1a58) = 0;
  *(undefined4 *)(glContext + 0x1a5c) = 0;
  *(undefined4 *)(glContext + 0x1aec) = 0;
  *(undefined4 *)(glContext + 0x1bcc) = 0;
  if ((*(uint *)(glContext + 0x2454) & 0x8000000) != 0) {
    *(undefined4 *)(glContext + 0x1bcc) = 1;
  }
  if (*(int *)(glContext + 0x23dc) == 2) {
    *(uint *)(glContext + 0x1bd0) = *(uint *)(glContext + 0x1bd0) & 0xfffffffc | 3;
  }
  else {
    *(uint *)(glContext + 0x1bd0) = *(uint *)(glContext + 0x1bd0) & 0xfffffffc | 1;
  }
  rb3dColorChannelMask = *(uint *)(0x00001af4 + glContext);
  rb3dRopcntl = *(uint *)(glContext + 0x1af8);
  *(undefined4 *)(glContext + 0x1b70) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1cc0) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1cc8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1b4c) = 2;
  *(undefined4 *)(glContext + 0x1a64) = 0;
  *(undefined4 *)(glContext + 0x1cbc) = 0;
  *(undefined4 *)(glContext + 0x1cc4) = 0;
  *(undefined4 *)(glContext + 0x1ccc) = 0;
  *(undefined4 *)(glContext + 0x1cd0) = 0;
  *(undefined4 *)(glContext + 0x1b64) = 0;
  *(undefined4 *)(glContext + 0x1b68) = 0;
  *(undefined4 *)(glContext + 0x1b6c) = 0;
  *(undefined4 *)(glContext + 0x1a70) = 0;
  *(undefined4 *)(glContext + 0x1a74) = 0;
  *(undefined4 *)(glContext + 0x1b3c) = 0;
  *(undefined4 *)(glContext + 0x1b44) = 0;
  *(undefined4 *)(glContext + 0x1a78) = 0;
  *(undefined4 *)(glContext + 0x1a7c) = 0;
  *(undefined4 *)(glContext + 0x1a60) = 0;
  *(undefined4 *)(glContext + 0x1b54) = 0x50005;
  *(undefined4 *)(glContext + 0x1b40) = 0x20000;
  *(undefined4 *)(glContext + 0x1b50) = 7;
  *(undefined4 *)(glContext + 0x1b2c) = 0x30000;
  *(undefined4 *)(glContext + 0x1a6c) = 0x5666666;
  *(undefined4 *)(glContext + 0x1a68) = 0x55666666;
  *(undefined4 *)(glContext + 0x1a80) = 0x20220000;
  *(undefined1 *)(glContext + 0x247c) = 1;
  *(undefined4 *)(glContext + 0x1b48) = 1;
  *(uint *)(0x00001af4 + glContext) = rb3dColorChannelMask | 0xf;
  *(undefined4 *)(glContext + 8) = 0xc;
  *(undefined4 *)(glContext + 0x23c0) = 0;
  scEdgerule = *(uint *)(glContext + 0x1abc);
  *(undefined4 *)(glContext + 0x1af0) = 0;
  *(uint *)(glContext + 0x1af8) = rb3dRopcntl & 0xfffffffb;
  *(undefined4 *)(glContext + 0x1ae0) = 0;
  *(undefined4 *)(glContext + 7000) = 0;
  *(undefined4 *)(glContext + 0x1b10) = 0;
  *(undefined4 *)(glContext + 0x1b60) = 0xffffff;
  *(undefined4 *)(glContext + 0x1bd4) = 0;
  *(undefined4 *)(glContext + 0x1b30) = 0;
  *(undefined4 *)(0x00001b14 + glContext) = 0;
  *(undefined4 *)(glContext + 0x1b28) = 0;
  *(undefined4 *)(glContext + 0x27b0) = 0;
  *(uint *)(glContext + 0x1abc) = scEdgerule & 0xc0000000 | 0x2da49525;
  _memset(glContext + 0x1cdc,0,0x40);
  *(undefined4 *)(0x00002348 + glContext) = 0x1b0f;
  *(undefined4 *)(glContext + 0x233c) = 0x1b0f;
  *(undefined4 *)(glContext + 0x2340) = 0x1b0f;
  *(undefined4 *)(glContext + 0x2344) = 0x1b0f;
  FUN_0004ab60(glContext);
  glContextWord2454 = *(uint *)(glContext + 0x2454);
  *(undefined4 *)(glContext + 0x1b7c) = 0x80006a;
  if ((int)glContextWord2454 < 0) {
    *(undefined4 *)(glContext + 0x1b7c) = 0x80086a;
  }
  else if ((glContextWord2454 & 0x8000000) == 0) {
    if ((glContextWord2454 & 0x2000000) == 0) {
      *(undefined4 *)(glContext + 0x1b7c) = 0x80046a;
    }
    else {
      *(undefined4 *)(glContext + 0x1b7c) = 0x80026a;
    }
  }
  else {
    *(undefined4 *)(glContext + 0x1b7c) = 0x80056a;
  }
  *(undefined4 *)(glContext + 0x1b80) = 2;
  *(undefined4 *)(glContext + 0x1ca0) = 0;
  *(undefined4 *)(glContext + 0x1b9c) = 0;
  *(undefined4 *)(glContext + 0x1ba0) = 0;
  *(undefined4 *)(glContext + 0x1cb4) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1ca8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1cac) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1cb0) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1b74) = 0;
  *(undefined4 *)(glContext + 0x1b98) = 0;
  *(undefined4 *)(glContext + 0x1bc8) = 0;
  *(undefined4 *)(glContext + 0x1ab0) = 0xc0800;
  *(undefined1 *)(glContext + 0x23ec) = 1;
  *(undefined4 *)(glContext + 0x1b84) = 0x43f;
  *(uint *)(glContext + 0x1b7c) = *(uint *)(glContext + 0x1b7c) & 0xffc3ffff | 0x300000;
  *(undefined4 *)(glContext + 0x1b88) = 0xffff;
  *(undefined4 *)(glContext + 0x1aa0) = 0x10;
  if (*(char *)(glContext + 0x2451) != '\0') {
    *(undefined4 *)(glContext + 0x1ab0) = 0xc3800;
  }
  *(undefined4 *)(glContext + 0x1aa8) = 0;
  *(undefined1 *)(glContext + 0x1aab) = 0;
  *(undefined1 *)(glContext + 0x1aa9) = 0xff;
  *(undefined1 *)(glContext + 0x1aaa) = 0xff;
  *(undefined4 *)(glContext + 0x1ae4) = 0;
  fVar1 = FLOAT_001aa150;
  *(undefined4 *)(glContext + 0x1a98) = 0;
  *(undefined4 *)(glContext + 0x1a9c) = 0;
  *(undefined4 *)(glContext + 0x1afc) = 0;
  *(undefined4 *)(glContext + 0x1ae8) = 0;
  *(undefined4 *)(glContext + 0x1ab4) = 0;
  *(undefined4 *)(glContext + 0x1aa4) = 0;
  *(float *)(glContext + 0x1b38) = fVar1;
  *(undefined4 *)(glContext + 0x1bd8) = 1;
  *(uint *)(glContext + 0x1cd4) = *(uint *)(glContext + 0x1cd4) & 0xfffc0003;
  *(undefined4 *)(glContext + 0x2358) = 0xffffffff;
  *(undefined4 *)(glContext + 0x235c) = 0;
  *(uint *)(glContext + 0x1cd8) = *(uint *)(glContext + 0x1cd8) & 0xffffc00f;
  *(uint *)(glContext + 0x1ab8) = *(uint *)(glContext + 0x1ab8) | 1;
  *(undefined4 *)(0x00001b34 + glContext) = 0;
  glContextWord23d0 = *(int *)(glContext + 0x23d0);
  iVar6 = glContextWord23d0 * 0xb4;
  *(undefined4 *)(glContext + 0x2360) = DAT_001db928;
  *(undefined4 *)(glContext + 0x2364) = DAT_001db92c;
  *(undefined4 *)(glContext + 0x236c) = DAT_001db934;
  *(undefined4 *)(0x00002368 + glContext) = DAT_001db930;
  *(undefined4 *)(glContext + 0x2370) = DAT_001db938;
  *(undefined4 *)(glContext + 0x2374) = *(undefined4 *)(&DAT_001db5b8 + iVar6);
  *(undefined4 *)(glContext + 0x237c) = *(undefined4 *)(&DAT_001db5c0 + iVar6);
  *(undefined4 *)(glContext + 0x2378) = *(undefined4 *)(&DAT_001db5bc + iVar6);
  *(undefined4 *)(glContext + 0x2380) = *(undefined4 *)(&DAT_001db5c4 + iVar6);
  *(undefined4 *)(glContext + 0x2384) = *(undefined4 *)(&DAT_001db2d4 + iVar6);
  *(undefined4 *)(0x00002388 + glContext) = *(undefined4 *)(&DAT_001db2d8 + iVar6);
  *(undefined4 *)(glContext + 0x2398) = *(undefined4 *)(&DAT_001db2e0 + iVar6);
  *(undefined **)(glContext + 0x238c) = (PTR_FUN_001db2dc)[glContextWord23d0 * 0x2d];
  *(undefined4 *)(glContext + 0x239c) = *(undefined4 *)(&DAT_001db2e4 + iVar6);
  *(undefined4 *)(glContext + 0x2390) = *(undefined4 *)(&DAT_001db2e8 + iVar6);
  *(undefined4 *)(glContext + 0x23a0) = *(undefined4 *)(&DAT_001db2f0 + iVar6);
  *(undefined **)(glContext + 0x2394) = (PTR_FUN_001db2ec)[glContextWord23d0 * 0x2d];
  uVar3 = *(undefined4 *)(&DAT_001db2f4 + iVar6);
  *(undefined4 *)(glContext + 0x23c4) = 0;
  *(undefined4 *)(glContext + 0x23c8) = 0;
  *(undefined4 *)(glContext + 0x23cc) = 0;
  *(undefined4 *)(glContext + 0x23a4) = uVar3;
  if (glContextWord23d0 == 4) {
    *(undefined4 *)(glContext + 0x23c8) = 0x101fe;
    *(undefined4 *)(glContext + 0x23cc) = 0x101fe;
    *(undefined4 *)(glContext + 0x23c4) = 0x111;
  }
  *(undefined1 *)(glContext + 0x29) = 1;
  *(undefined2 *)(glContext + 0x34) = 0xffff;
  *(undefined1 *)(glContext + 0x2e) = 3;
  *(undefined1 *)(glContext + 0x2a) = 1;
  *(undefined2 *)(glContext + 0x32) = 0xffff;
  *(undefined4 *)(glContext + 0x23e0) = 0;
  *(undefined4 *)(glContext + 0x1bac) = 0;
  *(undefined4 *)(glContext + 0x1bb0) = 0;
  *(undefined4 *)(glContext + 0x1bbc) = 0;
  *(undefined4 *)(glContext + 0x1bc0) = 0;
  *(undefined4 *)(glContext + 0x1bc4) = 0;
  *(undefined4 *)(glContext + 0x2354) = 0;
  *(undefined4 *)(glContext + 0x3c) = 0x800015ff;
  *(undefined1 *)(glContext + 0x2d) = 0xf;
  *(undefined1 *)(glContext + 0x2c) = 0xff;
  *(undefined4 *)(glContext + 0x38) = 0x7ffff;
  *(undefined4 *)(glContext + 0x40) = 0x7ffff;
  *(undefined1 *)(glContext + 0x30) = 7;
  *(undefined4 *)(glContext + 0x1bb8) = 0xaaaaa;
  return;
}

/* FUN_0004fc80 @ 0x4fc80 (252 bytes) */
int FUN_0004fc80(ctx, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int ctx;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
  uint param_8;
{
  int iVar1;
  int iVar2;
  
  if (*(char *)(ctx + 0x1868) != '\0') {
    iVar2 = 0;
    param_5 = *(uint *)(param_5 * 4 + *(int *)(ctx + 0x1864));
    if (param_5 == 0x16) goto LAB_0004fcb4;
  }
  iVar2 = 0xf;
LAB_0004fcb4:
  if ((param_2 & 1) == 0) {
    iVar1 = (param_2 >> 1) * 4 + ctx;
    *(uint *)(iVar1 + 0x1be4) =
         (param_8 & 1) << 0xf |
         (param_7 & 1) << 0xe |
         (param_6 & 1) << 0xd |
         (param_5 & 0x1f) << 8 |
         (param_4 & 0xf) << 4 | param_3 & 0xf | *(uint *)(iVar1 + 0x1be4) & 0xffff0000;
    *(uint *)(iVar1 + 0x1c04) = iVar2 << 0xc | *(uint *)(iVar1 + 0x1c04) & 0xffff0000 | 0x688;
  }
  else {
    iVar1 = (param_2 >> 1) * 4 + ctx;
    *(uint *)(iVar1 + 0x1be4) =
         param_8 << 0x1f |
         (param_7 & 1) << 0x1e |
         (param_6 & 1) << 0x1d |
         (param_5 & 0x1f) << 0x18 |
         (param_4 & 0xf) << 0x14 | (param_3 & 0xf) << 0x10 | *(uint *)(iVar1 + 0x1be4) & 0xffff;
    *(uint *)(iVar1 + 0x1c04) = iVar2 << 0x1c | *(uint *)(iVar1 + 0x1c04) & 0xffff | 0x6880000;
  }
  return;
}

/* extvsUpdateVertexAttributeConstants @ 0x4fd80 (492 bytes) */
int extvsUpdateVertexAttributeConstants(glContext)
  int glContext;
{
  int cmdEnd;
  int glContextWord1e70;
  bool moreAttribs;
  uint attribX;
  uint attribY;
  uint attribZ;
  uint attribW;
  int attribVectorOffset;
  code *streamSetCurrent;
  uint *cmdBuffer;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int cacheEntry;
  int cachedAttribPtr;
  int currentShader;
  int shaderState;
  undefined *attribRegister;
  uint attribIndex;
  int ctxCursor;
  int attribByteOffset;
  
  shaderState = *(int *)(((unsigned char *)0x00001154) + glContext);
  currentShader = shaderState + 0x10;
  if (((unsigned char *)0x00001134)[glContext] == '\0') {
    currentShader = *(int *)(((unsigned char *)0x00001144) + glContext);
  }
  attribIndex = 0;
  attribRegister = ((unsigned char *)0x00001300U);
  attribByteOffset = 0;
  ctxCursor = glContext;
  do {
    glContextWord1e70 = *(int *)(glContext + 0x1e70);
    if ((((1 << (attribIndex & 0x3f) & *(uint *)(((unsigned char *)0x000010b8) + glContextWord1e70)) != 0) &&
        (*(char *)(*(int *)(currentShader + 0x28) + attribByteOffset) == '\0')) &&
       (*(char *)(attribByteOffset + *(int *)(shaderState + 0xc)) != '\0')) {
      attribX = *(uint *)(attribByteOffset + *(int *)(shaderState + 0xc) + 4);
      attribVectorOffset = attribIndex * 0x10;
      cachedAttribPtr = attribVectorOffset + glContextWord1e70;
      attribY = *(uint *)(*(int *)(shaderState + 0xc) + attribByteOffset + 8);
      attribZ = *(uint *)(attribByteOffset + *(int *)(shaderState + 0xc) + 0xc);
      attribW = *(uint *)(attribByteOffset + *(int *)(shaderState + 0xc) + 0x10);
      if (((attribX != *(uint *)(cachedAttribPtr + 0x8c)) || (attribY != *(uint *)(cachedAttribPtr + 0x90))) ||
         ((attribZ != *(uint *)(cachedAttribPtr + 0x94) || (attribW != *(uint *)(cachedAttribPtr + 0x98))))) {
        *(uint *)(attribVectorOffset + glContextWord1e70 + 0x8c) = attribX;
        *(uint *)(attribVectorOffset + *(int *)(glContext + 0x1e70) + 0x90) = attribY;
        cacheEntry = attribVectorOffset + *(int *)(glContext + 0x1e70);
        *(uint *)(cacheEntry + 0x94) = attribZ;
        *(uint *)(attribVectorOffset + *(int *)(glContext + 0x1e70) + 0x98) = attribW;
        *(uint *)(ctxCursor + 0x1f38) = attribX;
        *(uint *)(ctxCursor + 0x1f3c) = attribY;
        *(uint *)(ctxCursor + 8000) = attribZ;
        *(uint *)(ctxCursor + 0x1f44) = attribW;
        cmdBuffer = (uint *)(**(code **)(glContext + 0x2758))(glContext,5,in_r5,in_r6,in_r7,in_r8,cacheEntry);
        *(uint **)(0x00002748 + glContext + 4) = cmdBuffer;
        cmdBuffer[4] = attribW;
        *cmdBuffer = (uint)attribRegister | 0x30000;
        cmdBuffer[1] = attribX;
        cmdBuffer[2] = attribY;
        cmdBuffer[3] = attribZ;
        cmdEnd = *(int *)(0x00002748 + glContext + 4);
        streamSetCurrent = *(code **)(glContext + 0x275c);
        *(int *)(0x00002748 + glContext + 4) = cmdEnd + 0x14;
        (*streamSetCurrent)(glContext,cmdEnd + 0x14);
        *(undefined4 *)(glContext + 0x1e68) = 0;
      }
    }
    moreAttribs = attribIndex != 7;
    attribByteOffset = attribByteOffset + 0x14;
    ctxCursor = ctxCursor + 0x10;
    attribRegister = attribRegister + 4;
    attribIndex = attribIndex + 1;
  } while (moreAttribs);
  return;
}

/* gldValidateAlphaTest @ 0x4ff70 (416 bytes) */
int gldValidateAlphaTest(glContext)
  int glContext;
{
  float alphaScale;
  int alphaFuncCode;
  undefined2 alphaRef16;
  undefined1 alphaRefByte;
  int glState;
  uint alphaFunc;
  
  alphaScale = FLOAT_001aa168;
  glState = *(int *)(*(int *)(glContext + 4) + 0x10);
  if (((unsigned char *)0x00002d66)[glState] == '\0') {
    *(uint *)(glContext + 0x1a4c) = *(uint *)(glContext + 0x1a4c) & 0xfffff7ff;
  }
  else {
    switch(*(undefined2 *)(((unsigned char *)0x00002d64) + glState)) {
    case 0x201:
      alphaFunc = 1;
      alphaFuncCode = 1;
      break;
    case 0x202:
      alphaFunc = 2;
      alphaFuncCode = 2;
      break;
    case 0x203:
      alphaFunc = 3;
      alphaFuncCode = 3;
      break;
    case 0x204:
      alphaFunc = 4;
      alphaFuncCode = 4;
      break;
    case 0x205:
      alphaFunc = 5;
      alphaFuncCode = 5;
      break;
    case 0x206:
      alphaFunc = 6;
      alphaFuncCode = 6;
      break;
    case 0x207:
      alphaFunc = 7;
      alphaFuncCode = 7;
      break;
    default:
      alphaFunc = 0;
      alphaFuncCode = 0;
    }
    alphaRefByte = 0xff;
    *(uint *)(glContext + 0x1a4c) = alphaFuncCode << 8 | *(uint *)(glContext + 0x1a4c) & 0xfffff8ff;
    if ((uint)(int)(*(float *)(((unsigned char *)0x00002d60) + glState) * alphaScale) < 0x100) {
      alphaRefByte = (undefined1)(int)(*(float *)(((unsigned char *)0x00002d60) + glState) * alphaScale);
    }
    *(undefined1 *)(glContext + 0x1a4f) = alphaRefByte;
    if ((*(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x3c00) ==
        0x2800) {
      alphaRef16 = ((uint (*)())floatToHalfBits)((double)*(float *)(((unsigned char *)0x00002d60) + glState));
      *(undefined2 *)(glContext + 0x1bde) = alphaRef16;
    }
    else {
      *(short *)(glContext + 0x1bde) =
           (short)(int)(*(float *)(((unsigned char *)0x00002d60) + glState) * FLOAT_001aa154 + FLOAT_001aa10c);
    }
    *(uint *)(glContext + 0x1a4c) =
         -(alphaFunc ^ 7) >> 0x14 & 0x800 | *(uint *)(glContext + 0x1a4c) & 0xfffff7ff | 0x1000;
  }
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x200;
  return;
}

/* FUN_00050140 @ 0x50140 (424 bytes) */
int FUN_00050140(glContext, param_2, param_3, param_4, param_5, param_6)
  int glContext;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  uint glContextWord1b2c;
  byte colorFormatIndex;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  
  puVar2 = PTR_DAT_001e88c8;
  colorFormatIndex = *(byte *)(glContext + 0x293f);
  iVar4 = *(int *)(*(int *)(glContext + 4) + 0x10);
  if ((*(uint *)(glContext + 0x18a4) & 0x3fffc0) == 0) {
    *(undefined4 *)(0x00001af4 + glContext) = 0;
  }
  else {
    uVar3 = (uint)(((unsigned char *)0x00002e40)[iVar4] == '\x01') *
            ((byte)PTR_DAT_001e88c8[(uint)colorFormatIndex * 0x24 + 0x1c] & 0xf);
    *(uint *)(0x00001af4 + glContext) = uVar3;
    uVar3 = uVar3 | (uint)(((unsigned char *)0x00002e41)[iVar4] == '\x01') *
                    (*(uint *)(puVar2 + (uint)colorFormatIndex * 0x24 + 0x1c) >> 0x14 & 0xf);
    *(uint *)(0x00001af4 + glContext) = uVar3;
    uVar3 = uVar3 | (uint)(((unsigned char *)0x00002e42)[iVar4] == '\x01') *
                    (*(ushort *)(puVar2 + (uint)colorFormatIndex * 0x24 + 0x1c) & 0xf);
    *(uint *)(0x00001af4 + glContext) = uVar3;
    *(uint *)(0x00001af4 + glContext) =
         uVar3 | (uint)(((unsigned char *)0x00002e43)[iVar4] == '\x01') *
                 (*(uint *)(puVar2 + (uint)colorFormatIndex * 0x24 + 0x1c) >> 0xc & 0xf);
  }
  glContextWord1b2c = *(uint *)(glContext + 0x1b2c);
  *(uint *)(glContext + 0x1b2c) = glContextWord1b2c & 0xfffcffff | 0x30000;
  if (*(int *)(((unsigned char *)0x00003194) + iVar4) == 0x1d01) {
    *(uint *)(glContext + 0x1bb8) = *(uint *)(glContext + 0x1bb8) & 0xfff0ffff | 0xa0000;
    *(uint *)(glContext + 0x1b2c) = glContextWord1b2c & 0xfffc0000 | 0x3aaaa;
  }
  else {
    *(uint *)(glContext + 0x1b2c) = glContextWord1b2c & 0xfffcc0c0 | 0x31515;
    if ((*(uint *)(glContext + 0x44) & 0x2000) == 0) {
      *(uint *)(glContext + 0x1b2c) = glContextWord1b2c & 0xfffc0000 | 0x39595;
    }
    else {
      *(uint *)(glContext + 0x1b2c) = glContextWord1b2c & 0xfffc0000 | 0x35555;
    }
    *(uint *)(glContext + 0x1bb8) = *(uint *)(glContext + 0x1bb8) & 0xfff0ffff | 0x50000;
  }
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x10;
  return;
}

/* gldEmitHardwareState @ 0x50300 (3048 bytes) */
int gldEmitHardwareState(glContext)
  int glContext;
{
  undefined4 ctxWord278;
  undefined *finalCallArgR5;
  int reserveResult;
  int streamCurrent;
  undefined4 streamStateWord;
  undefined4 allocatedPacket;
  undefined4 unitShadowValue5;
  undefined4 unitShadowValue3;
  undefined4 unitShadowValue2;
  undefined4 unitShadowValue1;
  uint dirtyUnitMask;
  undefined4 *texUnitShadowPtr4;
  undefined4 *packetCursor;
  uint rb3dBlendcntl;
  uint fgFogBlend;
  uint fgAlphaFunc;
  undefined4 ctxWord27c;
  undefined4 vapVtxNumArrays;
  undefined4 ctxWord2608;
  undefined4 ctxWord2604;
  undefined4 ctxWord25e4;
  undefined4 ctxWord25c0;
  undefined4 ctxWord25b0;
  undefined4 ctxWord2598;
  undefined4 gbZPeqConfig;
  undefined4 suDepthOffset;
  undefined4 zbZstencilcntl;
  undefined4 zbZtop;
  undefined4 rb3dConstantColorGb;
  undefined4 rb3dConstantColorAr;
  undefined4 rb3dConstantColor;
  undefined4 rb3dAblendcntl;
  undefined4 gaSolidBa;
  undefined4 gbSelect;
  undefined4 fgFogColorB;
  undefined4 fgAlphaValue;
  undefined4 fgDepthSrc;
  undefined4 rb3dRopcntl;
  undefined4 gaPointSize;
  undefined4 gaPointMinmax;
  undefined4 ctxWord1e14;
  undefined4 ctxWord1e10;
  undefined4 ctxWord1e0c;
  undefined4 vapTexToColorCntl;
  undefined4 suTexWrapPs3;
  undefined4 ps3VtxFmt;
  undefined4 ps3TexSource;
  undefined4 gbPs3Enable;
  undefined4 gaColorControl1df8;
  undefined4 scEdgerule;
  undefined4 vapPscSgnNormCntl;
  undefined4 vapClipCntl;
  undefined4 vapVtxStateCntl;
  undefined4 vapVtxSize;
  undefined4 vapOutVtxFmt1;
  undefined4 ctxWord1ee0;
  undefined4 gaColorControl;
  undefined4 gaFogOffset;
  undefined4 rb3dColorClearValue;
  undefined4 suTexWrap;
  undefined4 gaEnhance;
  undefined4 rb3dAaresolveCtl;
  undefined4 scScreendoor;
  undefined4 gbMspos1;
  undefined4 gbAaConfig;
  undefined4 gaLineS1;
  undefined4 gaLineStippleValue;
  undefined4 gaLineStippleConfig;
  undefined4 gaTriangleStipple;
  undefined4 gbEnable;
  undefined4 gaLineCntl;
  undefined4 gaRoundMode;
  undefined4 suCullMode;
  undefined4 vapCntlStatus;
  undefined4 rb3dDitherCtl;
  code *streamSetCurrent;
  undefined4 *packet;
  undefined4 *packetEnd;
  undefined4 passThroughR5;
  undefined4 *texUnitShadowPtr5;
  undefined *engineCapsEntry;
  undefined4 passThroughR6;
  int unitIndex;
  undefined4 finalCallArgR6;
  undefined4 passThroughR7;
  undefined4 a4;
  undefined4 passThroughR8;
  undefined4 a5;
  undefined4 unitShadowValue0;
  int glStateBlock;
  undefined4 *texUnitShadowPtr0;
  undefined4 *texUnitShadowPtr1;
  undefined4 *texUnitShadowPtr2;
  undefined4 *texUnitShadowPtr3;
  uint ctxWord2cc;
  
  glStateBlock = *(int *)(*(int *)(glContext + 4) + 0x10);
  packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,6);
  packet[1] = 0;
  *packet = ((unsigned char *)0x000010a4U);
  *(undefined4 **)(0x00002748 + glContext + 4) = packet + 2;
  (**(code **)(glContext + 0x275c))(glContext,packet + 2);
  packet = (undefined4 *)
           (**(code **)(glContext + 0x2758))
                     (glContext,4,passThroughR5,passThroughR6,passThroughR7,passThroughR8,*(code **)(glContext + 0x2758));
  *packet = ((unsigned char *)0x00001393U);
  packet[1] = 10;
  packet[2] = ((unsigned char *)0x000013c6U);
  packet[3] = 3;
  *(undefined4 **)(0x00002748 + glContext + 4) = packet + 4;
  (**(code **)(glContext + 0x275c))(glContext,packet + 4,passThroughR5,passThroughR6,passThroughR7,passThroughR8,3);
  packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0x1b4);
  *(undefined4 **)(0x00002748 + glContext + 4) = packet;
  *packet = ((unsigned char *)0x00001394U);
  packetEnd = packet + 0x5a;
  rb3dDitherCtl = *(undefined4 *)(glContext + 0x1af0);
  packet[2] = 0x850;
  packet[1] = rb3dDitherCtl;
  vapCntlStatus = *(undefined4 *)(glContext + 0x1b80);
  packet[4] = 0x110ad;
  packet[3] = vapCntlStatus;
  packet[5] = *(undefined4 *)(0x00001b14 + glContext);
  suCullMode = *(undefined4 *)(glContext + 0x1b30);
  packet[7] = 0x110a2;
  packet[6] = suCullMode;
  packet[8] = *(undefined4 *)(glContext + 0x1b3c);
  gaRoundMode = *(undefined4 *)(glContext + 0x1b48);
  packet[10] = ((unsigned char *)0x0000108dU);
  packet[9] = gaRoundMode;
  gaLineCntl = *(undefined4 *)(glContext + 0x1b40);
  packet[0xc] = ((unsigned char *)0x00001002U);
  packet[0xb] = gaLineCntl;
  gbEnable = *(undefined4 *)(glContext + 0x1b50);
  packet[0xe] = ((unsigned char *)0x00001085U);
  packet[0xd] = gbEnable;
  gaTriangleStipple = *(undefined4 *)(glContext + 0x1b54);
  packet[0x10] = ((unsigned char *)0x0000108eU);
  packet[0xf] = gaTriangleStipple;
  gaLineStippleConfig = *(undefined4 *)(glContext + 0x1b64);
  packet[0x12] = ((unsigned char *)0x00001098U);
  packet[0x11] = gaLineStippleConfig;
  gaLineStippleValue = *(undefined4 *)(glContext + 0x1b68);
  packet[0x14] = 0x11099;
  packet[0x13] = gaLineStippleValue;
  packet[0x15] = *(undefined4 *)(glContext + 0x1b6c);
  gaLineS1 = *(undefined4 *)(glContext + 0x1b70);
  packet[0x19] = 0x11007;
  packet[0x18] = 0;
  packet[0x17] = 0x823;
  packet[0x16] = gaLineS1;
  packet[0x1a] = *(undefined4 *)(glContext + 0x1a64);
  gbAaConfig = *(undefined4 *)(glContext + 0x1a60);
  packet[0x1c] = 0x11004;
  packet[0x1b] = gbAaConfig;
  packet[0x1d] = *(undefined4 *)(glContext + 0x1a68);
  gbMspos1 = *(undefined4 *)(glContext + 0x1a6c);
  packet[0x1f] = ((unsigned char *)0x000010faU);
  packet[0x1e] = gbMspos1;
  scScreendoor = *(undefined4 *)(glContext + 0x1b60);
  packet[0x21] = ((unsigned char *)0x000013a2U);
  packet[0x20] = scScreendoor;
  rb3dAaresolveCtl = *(undefined4 *)(glContext + 0x23c0);
  packet[0x23] = ((unsigned char *)0x0000109dU);
  packet[0x22] = rb3dAaresolveCtl;
  gaEnhance = *(undefined4 *)(glContext + 0x1b4c);
  packet[0x25] = ((unsigned char *)0x000010a8U);
  packet[0x24] = gaEnhance;
  suTexWrap = *(undefined4 *)(glContext + 0x1b28);
  packet[0x27] = 0x311a9;
  packet[0x26] = suTexWrap;
  packet[0x28] = *(undefined4 *)(glContext + 0x233c);
  packet[0x29] = *(undefined4 *)(glContext + 0x2340);
  packet[0x2a] = *(undefined4 *)(glContext + 0x2344);
  packet[0x2b] = *(undefined4 *)(0x00002348 + glContext);
  packet[0x2c] = ((unsigned char *)0x00001385U);
  rb3dColorClearValue = *(undefined4 *)(glContext + 0x1a94);
  packet[0x2e] = 0x110a5;
  packet[0x2d] = rb3dColorClearValue;
  packet[0x2f] = *(undefined4 *)(glContext + 0x1a7c);
  gaFogOffset = *(undefined4 *)(glContext + 0x1a78);
  packet[0x31] = ((unsigned char *)0x0000109eU);
  packet[0x30] = gaFogOffset;
  gaColorControl = *(undefined4 *)(glContext + 0x1b2c);
  packet[0x33] = 0x861;
  packet[0x32] = gaColorControl;
  ctxWord1ee0 = *(undefined4 *)(glContext + 0x1ca0);
  packet[0x35] = 0x10824;
  packet[0x34] = ctxWord1ee0;
  packet[0x36] = *(undefined4 *)(glContext + 0x1b9c);
  vapOutVtxFmt1 = *(undefined4 *)(glContext + 0x1ba0);
  packet[0x38] = 0x1082c;
  packet[0x37] = vapOutVtxFmt1;
  packet[0x39] = *(undefined4 *)(glContext + 0x1b84);
  vapVtxSize = *(undefined4 *)(glContext + 0x248c);
  packet[0x3b] = 0x860;
  packet[0x3a] = vapVtxSize;
  vapVtxStateCntl = *(undefined4 *)(glContext + 0x1b78);
  packet[0x3d] = 0x887;
  packet[0x3c] = vapVtxStateCntl;
  vapClipCntl = *(undefined4 *)(glContext + 0x1b74);
  packet[0x3f] = 0x8a2;
  packet[0x3e] = vapClipCntl;
  packet[0x40] = *(undefined4 *)(glContext + 0x1b88);
  packet[0x41] = 0x877;
  vapPscSgnNormCntl = *(undefined4 *)(glContext + 0x1cb8);
  packet[0x43] = 0x1084d;
  packet[0x46] = 0x5c8;
  packet[0x44] = 0xffffff;
  packet[0x47] = 0x8000;
  packet[0x48] = 0xc0001000;
  packet[0x4a] = ((unsigned char *)0x000010eaU);
  packet[0x49] = 0;
  packet[0x42] = vapPscSgnNormCntl;
  packet[0x45] = 0;
  scEdgerule = *(undefined4 *)(glContext + 0x1abc);
  packet[0x4c] = ((unsigned char *)0x00001096U);
  packet[0x4b] = scEdgerule;
  gaColorControl1df8 = *(undefined4 *)(glContext + 0x1bb8);
  packet[0x4e] = ((unsigned char *)0x00001046U);
  packet[0x4d] = gaColorControl1df8;
  gbPs3Enable = *(undefined4 *)(glContext + 0x1bbc);
  packet[0x50] = ((unsigned char *)0x00001048U);
  packet[0x4f] = gbPs3Enable;
  ps3TexSource = *(undefined4 *)(glContext + 0x1bc0);
  packet[0x52] = ((unsigned char *)0x00001047U);
  packet[0x51] = ps3TexSource;
  ps3VtxFmt = *(undefined4 *)(glContext + 0x1bb0);
  packet[0x54] = ((unsigned char *)0x00001045U);
  packet[0x53] = ps3VtxFmt;
  suTexWrapPs3 = *(undefined4 *)(glContext + 0x1bc4);
  packet[0x56] = 0x886;
  packet[0x55] = suTexWrapPs3;
  vapTexToColorCntl = *(undefined4 *)(glContext + 0x1bc8);
  packet[0x59] = 2;
  packet[0x58] = ((unsigned char *)0x00001180U);
  packet[0x57] = vapTexToColorCntl;
  if ((*(uint *)(glContext + 0x2454) & 0x8000000) != 0) {
    packetEnd = packet + 0x62;
    packet[0x5a] = ((unsigned char *)0x000012fbU);
    ctxWord1e0c = *(undefined4 *)(glContext + 0x1bcc);
    packet[0x5c] = ((unsigned char *)0x000012faU);
    packet[0x5b] = ctxWord1e0c;
    ctxWord1e10 = *(undefined4 *)(glContext + 0x1bd0);
    packet[0x5e] = ((unsigned char *)0x000010e6U);
    packet[0x5d] = ctxWord1e10;
    ctxWord1e14 = *(undefined4 *)(glContext + 0x1bd4);
    packet[0x60] = ((unsigned char *)0x000011f2U);
    packet[0x5f] = ctxWord1e14;
    packet[0x61] = *(undefined4 *)(glContext + 0x1bd8);
  }
  streamSetCurrent = *(code **)(glContext + 0x275c);
  *(undefined4 **)(0x00002748 + glContext + 4) = packetEnd;
  (*streamSetCurrent)(glContext,packetEnd);
  ((int (*)())FUN_0004e880)(glContext);
  dirtyUnitMask = *(uint *)(glContext + 0x27b0) |
           (*(uint *)(glContext + 0x27b0) & *(uint *)(glContext + 0x27b4)) << 8;
  if (dirtyUnitMask != 0) {
    texUnitShadowPtr0 = (undefined4 *)(glContext + 0x1cdc);
    texUnitShadowPtr1 = (undefined4 *)(glContext + 0x1d1c);
    texUnitShadowPtr2 = (undefined4 *)(glContext + 0x1d5c);
    texUnitShadowPtr3 = (undefined4 *)(glContext + 0x1d9c);
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0xe0);
    unitIndex = *(int *)(glContext + 0x1938);
    texUnitShadowPtr4 = (undefined4 *)(glContext + 0x1ddc);
    texUnitShadowPtr5 = (undefined4 *)(glContext + 0x1e1c);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    do {
      if ((dirtyUnitMask & 1) != 0) {
        *packet = ((unsigned char *)0x00001100) + unitIndex;
        unitShadowValue0 = *texUnitShadowPtr0;
        packet[2] = ((unsigned char *)0x00001110) + unitIndex;
        packet[1] = unitShadowValue0;
        unitShadowValue1 = *texUnitShadowPtr1;
        packet[4] = ((unsigned char *)0x00001120U) + unitIndex;
        packet[3] = unitShadowValue1;
        unitShadowValue2 = *texUnitShadowPtr2;
        packet[6] = ((unsigned char *)0x00001130) + unitIndex;
        packet[5] = unitShadowValue2;
        unitShadowValue3 = *texUnitShadowPtr3;
        packet[8] = ((unsigned char *)0x00001170U) + unitIndex;
        packet[7] = unitShadowValue3;
        unitShadowValue5 = *texUnitShadowPtr5;
        packet[10] = ((unsigned char *)0x00001160) + unitIndex;
        packet[0xc] = ((unsigned char *)0x00001140) + unitIndex;
        packet[0xb] = 0;
        packet[9] = unitShadowValue5;
        packet[0xd] = *texUnitShadowPtr4;
        packet = packet + 0xe;
      }
      dirtyUnitMask = dirtyUnitMask >> 1;
      unitIndex = unitIndex + 1;
      texUnitShadowPtr0 = texUnitShadowPtr0 + 1;
      texUnitShadowPtr1 = texUnitShadowPtr1 + 1;
      texUnitShadowPtr2 = texUnitShadowPtr2 + 1;
      texUnitShadowPtr3 = texUnitShadowPtr3 + 1;
      texUnitShadowPtr5 = texUnitShadowPtr5 + 1;
      texUnitShadowPtr4 = texUnitShadowPtr4 + 1;
    } while (dirtyUnitMask != 0);
    streamSetCurrent = *(code **)(glContext + 0x275c);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    (*streamSetCurrent)(glContext,packet);
  }
  if ((*(uint *)(glContext + 0x44) & 0x100) != 0) {
    if ((*(uint *)(glContext + 0x27b0) & 1) == 0) {
      packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,4);
      packetEnd = packet + 4;
      *packet = ((unsigned char *)0x00001041U);
      packet[1] = (*(uint *)(glContext + 0x27b0) | 1) << (*(uint *)(glContext + 0x1938) & 0x3f);
      unitIndex = *(int *)(glContext + 0x1938);
      packet[3] = 0;
      packet[2] = ((unsigned char *)0x00001100) + unitIndex;
      goto LAB_00050920;
    }
  }
  packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
  packetEnd = packet + 2;
  *packet = ((unsigned char *)0x00001041U);
  packet[1] = *(int *)(glContext + 0x27b0) << (*(uint *)(glContext + 0x1938) & 0x3f);
LAB_00050920:
  streamSetCurrent = *(code **)(glContext + 0x275c);
  *(undefined4 **)(0x00002748 + glContext + 4) = packetEnd;
  (*streamSetCurrent)(glContext,packetEnd);
  allocatedPacket = (**(code **)(glContext + 0x2758))(glContext,0x90);
  *(undefined4 *)(0x00002748 + glContext + 4) = allocatedPacket;
  packet = (undefined4 *)((int (*)())gldEmitViewportAndGuardBand)(glContext,allocatedPacket);
  packetCursor = packet + 9;
  *packet = ((unsigned char *)0x0000108cU);
  gaPointMinmax = *(undefined4 *)(glContext + 0x1cd0);
  packet[2] = ((unsigned char *)0x00001087U);
  packet[1] = gaPointMinmax;
  gaPointSize = *(undefined4 *)(glContext + 0x1ccc);
  packet[4] = 0x31080;
  packet[3] = gaPointSize;
  packet[5] = *(undefined4 *)(glContext + 0x1cbc);
  packet[6] = *(undefined4 *)(glContext + 0x1cc4);
  packet[7] = *(undefined4 *)(glContext + 0x1cc0);
  packet[8] = *(undefined4 *)(glContext + 0x1cc8);
  if ((*(int *)(((unsigned char *)0x000031c0) + glStateBlock) != 0) && (((unsigned char *)0x00001491)[glContext] != '\0')) {
    packetCursor = packet + 0xb;
    packet[9] = ((unsigned char *)0x000013c2U);
    packet[10] = *(undefined4 *)(glContext + 0x1aa8);
  }
  packet = packetCursor + 4;
  *packetCursor = ((unsigned char *)0x00001386U);
  rb3dRopcntl = *(undefined4 *)(glContext + 0x1af8);
  packetCursor[2] = ((unsigned char *)0x00001383U);
  packetCursor[1] = rb3dRopcntl;
  packetCursor[3] = *(undefined4 *)(0x00001af4 + glContext);
  if ((*(uint *)(0x00001b14 + glContext) & 3) != 0) {
    packet = packetCursor + 9;
    packetCursor[4] = 0x310a9;
    packetCursor[5] = *(undefined4 *)(glContext + 0x1b1c);
    packetCursor[6] = *(undefined4 *)(glContext + 0x1b18);
    packetCursor[7] = *(undefined4 *)(glContext + 0x1b24);
    packetCursor[8] = *(undefined4 *)(glContext + 0x1b20);
  }
  packet = (undefined4 *)((int (*)())gldEmitScissorRegs)(glContext,packet);
  engineCapsEntry = PTR_DAT_001e88c8;
  *packet = 0x112f5;
  fgAlphaFunc = *(uint *)(glContext + 0x1a4c);
  packet[1] = fgAlphaFunc;
  if ((*(uint *)(engineCapsEntry + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    packet[1] = fgAlphaFunc & 0xfffff7ff;
  }
  fgDepthSrc = *(undefined4 *)(glContext + 0x1a50);
  packet[3] = ((unsigned char *)0x000012f8U);
  packet[2] = fgDepthSrc;
  fgAlphaValue = *(undefined4 *)(glContext + 0x1bdc);
  packet[5] = 0x212f2;
  packet[4] = fgAlphaValue;
  packet[6] = *(undefined4 *)(glContext + 0x1a54);
  packet[7] = *(undefined4 *)(glContext + 0x1a58);
  fgFogColorB = *(undefined4 *)(glContext + 0x1a5c);
  packet[9] = ((unsigned char *)0x00001007U);
  packet[8] = fgFogColorB;
  gbSelect = *(undefined4 *)(glContext + 0x1a64);
  packet[0xb] = ((unsigned char *)0x000012f0U);
  packet[10] = gbSelect;
  fgFogBlend = *(uint *)(glContext + 0x1aec);
  packet[0xc] = fgFogBlend;
  if ((*(uint *)(engineCapsEntry + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    packet[0xc] = fgFogBlend & 0xfffffffe;
  }
  packet[0xd] = 0x1109f;
  packet[0xe] = *(undefined4 *)(glContext + 0x1a70);
  gaSolidBa = *(undefined4 *)(glContext + 0x1a74);
  packet[0x10] = 0x11381;
  packet[0xf] = gaSolidBa;
  rb3dBlendcntl = *(uint *)(glContext + 0x1a80);
  packet[0x11] = rb3dBlendcntl;
  if ((*(uint *)(engineCapsEntry + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x4000) == 0) {
    packet[0x11] = rb3dBlendcntl & 0xfffffffc;
  }
  rb3dAblendcntl = *(undefined4 *)(glContext + 0x1a84);
  packet[0x13] = ((unsigned char *)0x00001384U);
  packet[0x12] = rb3dAblendcntl;
  a5 = 0x113a8;
  a4 = 0x413de;
  finalCallArgR6 = 0x313e9;
  finalCallArgR5 = ((unsigned char *)0x000813adU);
  rb3dConstantColor = *(undefined4 *)(glContext + 0x1a88);
  packet[0x15] = ((unsigned char *)0x000013beU);
  packet[0x14] = rb3dConstantColor;
  rb3dConstantColorAr = *(undefined4 *)(glContext + 0x1a8c);
  packet[0x17] = ((unsigned char *)0x000013bfU);
  packet[0x16] = rb3dConstantColorAr;
  rb3dConstantColorGb = *(undefined4 *)(glContext + 0x1a90);
  packet[0x19] = ((unsigned char *)0x000013c5U);
  packet[0x18] = rb3dConstantColorGb;
  zbZtop = *(undefined4 *)(glContext + 0x1ab8);
  packet[0x1b] = 0x113c0;
  packet[0x1a] = zbZtop;
  packet[0x1c] = *(undefined4 *)(glContext + 0x1aa0);
  zbZstencilcntl = *(undefined4 *)(glContext + 0x1aa4);
  packet[0x1e] = 0x110b0;
  packet[0x1d] = zbZstencilcntl;
  packet[0x1f] = *(undefined4 *)(glContext + 0x1b38);
  suDepthOffset = *(undefined4 *)(0x00001b34 + glContext);
  packet[0x21] = ((unsigned char *)0x0000100aU);
  packet[0x20] = suDepthOffset;
  gbZPeqConfig = *(undefined4 *)(glContext + 0x2354);
  packet[0x23] = 0x113a8;
  packet[0x22] = gbZPeqConfig;
  packet[0x24] = *(undefined4 *)(glContext + 0x235c);
  ctxWord2598 = *(undefined4 *)(glContext + 0x2358);
  packet[0x26] = 0x413de;
  packet[0x25] = ctxWord2598;
  packet[0x27] = *(undefined4 *)(glContext + 0x2360);
  packet[0x28] = *(undefined4 *)(glContext + 0x2364);
  packet[0x29] = *(undefined4 *)(0x00002368 + glContext);
  packet[0x2a] = *(undefined4 *)(glContext + 0x236c);
  ctxWord25b0 = *(undefined4 *)(glContext + 0x2370);
  packet[0x2c] = 0x313e9;
  packet[0x2b] = ctxWord25b0;
  packet[0x2d] = *(undefined4 *)(glContext + 0x2374);
  packet[0x2e] = *(undefined4 *)(glContext + 0x2378);
  packet[0x2f] = *(undefined4 *)(glContext + 0x237c);
  ctxWord25c0 = *(undefined4 *)(glContext + 0x2380);
  packet[0x31] = ((unsigned char *)0x000813adU);
  packet[0x30] = ctxWord25c0;
  packet[0x32] = *(undefined4 *)(glContext + 0x2384);
  packet[0x33] = *(undefined4 *)(0x00002388 + glContext);
  packet[0x34] = *(undefined4 *)(glContext + 0x238c);
  packet[0x35] = *(undefined4 *)(glContext + 0x2390);
  packet[0x36] = *(undefined4 *)(glContext + 0x2394);
  packet[0x37] = *(undefined4 *)(glContext + 0x2398);
  packet[0x38] = *(undefined4 *)(glContext + 0x239c);
  packet[0x39] = *(undefined4 *)(glContext + 0x23a0);
  ctxWord25e4 = *(undefined4 *)(glContext + 0x23a4);
  packet[0x3b] = ((unsigned char *)0x000013e6U);
  packet[0x3a] = ctxWord25e4;
  ctxWord2604 = *(undefined4 *)(glContext + 0x23c4);
  packet[0x3d] = ((unsigned char *)0x000013e7U);
  packet[0x3c] = ctxWord2604;
  ctxWord2608 = *(undefined4 *)(glContext + 0x23c8);
  packet[0x3f] = ((unsigned char *)0x000013e8U);
  packet[0x3e] = ctxWord2608;
  packet[0x40] = *(undefined4 *)(glContext + 0x23cc);
  if ((*(uint *)(glContext + 0x44) & 0x20000) == 0) {
    *(undefined4 *)(glContext + 0x1e68) = 0;
  }
  streamSetCurrent = *(code **)(glContext + 0x275c);
  *(undefined4 **)(0x00002748 + glContext + 4) = packet + 0x41;
  /* issue #79 class: `stw r4,0x274c(r30)` leaves the new write pointer in r4 for the `bctrl` at
   * 0x50d10 - the callback is (ctx, write pointer), like every sibling call through 0x275c */
  (*streamSetCurrent)(glContext,packet + 0x41);
  if (*(int *)(glContext + 0x2494) != 0) {
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0x12);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    *packet = 0x830;
    vapVtxNumArrays = *(undefined4 *)(glContext + 0x2490);
    packet[2] = 0x831;
    packet[1] = vapVtxNumArrays;
    streamStateWord = **(undefined4 **)(glContext + 0x2494);
    packet[4] = 0x834;
    packet[3] = streamStateWord;
    streamStateWord = *(undefined4 *)(*(int *)(glContext + 0x2494) + 4);
    packet[6] = 0x837;
    packet[5] = streamStateWord;
    streamStateWord = *(undefined4 *)(*(int *)(glContext + 0x2494) + 8);
    packet[8] = 0x83a;
    packet[7] = streamStateWord;
    streamStateWord = *(undefined4 *)(*(int *)(glContext + 0x2494) + 0xc);
    packet[10] = 0x83d;
    packet[9] = streamStateWord;
    streamStateWord = *(undefined4 *)(*(int *)(glContext + 0x2494) + 0x10);
    packet[0xc] = 0x840;
    packet[0xb] = streamStateWord;
    streamStateWord = *(undefined4 *)(*(int *)(glContext + 0x2494) + 0x14);
    packet[0xe] = 0x843;
    packet[0xd] = streamStateWord;
    streamStateWord = *(undefined4 *)(*(int *)(glContext + 0x2494) + 0x18);
    packet[0x10] = 0x846;
    packet[0xf] = streamStateWord;
    packet[0x11] = *(undefined4 *)(*(int *)(glContext + 0x2494) + 0x1c);
    streamCurrent = *(int *)(0x00002748 + glContext + 4);
    streamSetCurrent = *(code **)(glContext + 0x275c);
    *(int *)(0x00002748 + glContext + 4) = streamCurrent + 0x48;
    (*streamSetCurrent)(glContext,streamCurrent + 0x48,finalCallArgR5,finalCallArgR6,a4,a5,packet);
  }
  reserveResult = FUN_0004aa00(glContext,1);
  if (reserveResult == 0) {
    (**(code **)(((unsigned char *)0x00001330) + glContext))(glContext,0xc0100000);
    (**(code **)(((unsigned char *)0x00001338) + glContext))(glContext);
    FUN_00086710(glContext);
  }
  ctxWord2cc = *(uint *)(glContext + 0x8c);
  *(undefined1 *)(glContext + 0x23ec) = 1;
  *(uint *)(glContext + 0x8c) = ctxWord2cc | 0x58000;
  if ((((ctxWord2cc & 0x50000000) == 0) && (*(code **)(((unsigned char *)0x000012b0) + glContext) != (code *)0x0)) &&
     ((ctxWord2cc & 0x200000) != 0)) {
    ctxWord278 = *(undefined4 *)(glContext + 0x38);
    ctxWord27c = *(undefined4 *)(glContext + 0x3c);
    (**(code **)(((unsigned char *)0x000012b0) + glContext))(glContext);
    *(undefined4 *)(glContext + 0x38) = ctxWord278;
    *(undefined4 *)(glContext + 0x3c) = ctxWord27c;
  }
  else {
    *(undefined1 *)(glContext + 0x23ec) = 1;
    ffvpRunStateHook(glContext);
  }
  *(undefined1 *)(glContext + 0x23ec) = 1;
  return;
}

/* FUN_00050ef0 @ 0x50ef0 (284 bytes) */
int FUN_00050ef0(glContext, param_2, param_3, param_4)
  int glContext;
  uint param_2;
  uint param_3;
  uint param_4;
{
  code *streamSetCurrent;
  uint glContextWord1b7c;
  undefined4 *a6;
  int iVar3;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0x80 / param_2;
  if (0x80 / param_3 < 0x80 / param_2) {
    uVar4 = 0x80 / param_3;
  }
  if (10 < uVar4) {
    uVar4 = 10;
  }
  uVar5 = 6;
  if ((param_4 != 0) && (uVar5 = 0x80 / param_4, 6 < uVar5)) {
    uVar5 = 6;
  }
  glContextWord1b7c = *(uint *)(glContext + 0x1b7c);
  if ((uVar4 != (glContextWord1b7c & 0xf)) || (uVar5 != (glContextWord1b7c >> 4 & 0xf))) {
    *(undefined1 *)(glContext + 0x23ec) = 1;
    *(uint *)(glContext + 0x1b7c) = (uVar5 & 0xf) << 4 | uVar4 & 0xf | glContextWord1b7c & 0xffffff00;
  }
  if (*(char *)(glContext + 0x23ec) != '\0') {
    a6 = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,4);
    *(undefined4 **)(0x00002748 + glContext + 4) = a6;
    a6[1] = 0;
    *a6 = 0x8a1;
    a6[2] = 0x820;
    a6[3] = *(undefined4 *)(glContext + 0x1b7c);
    iVar3 = *(int *)(0x00002748 + glContext + 4);
    streamSetCurrent = *(code **)(glContext + 0x275c);
    *(int *)(0x00002748 + glContext + 4) = iVar3 + 0x10;
    (*streamSetCurrent)(glContext,iVar3 + 0x10,param_3,param_4,in_r7,in_r8,a6);
    *(undefined1 *)(glContext + 0x23ec) = 0;
  }
  return;
}

/* gldValidateStencil @ 0x51010 (1024 bytes) */
int gldValidateStencil(glContext)
  int glContext;
{
  ushort backZfailOp;
  ushort backZpassOp;
  ushort backFailOp;
  ushort frontZfailOp;
  ushort frontZpassOp;
  ushort frontFailOp;
  int hwFrontFailOp;
  int hwFrontZpassOp;
  int hwFrontZfailOp;
  int hwBackFailOp;
  int hwBackZpassOp;
  int glState;
  int hwBackZfailOp;
  uint backFuncBits;
  uint frontFuncBits;
  
  glState = *(int *)(*(int *)(glContext + 4) + 0x10);
  if ((*(int *)(((unsigned char *)0x000031c0) + glState) == 0) || (((unsigned char *)0x00001491)[glContext] == '\0')) {
    *(undefined1 *)(glContext + 0x23ed) = 0;
    *(uint *)(glContext + 0x1aa0) = *(uint *)(glContext + 0x1aa0) & 0xfffffffe;
    goto LAB_00051404;
  }
  hwFrontFailOp = 3;
  *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) | 0x20000000;
  frontFailOp = *(ushort *)(((unsigned char *)0x000031a2) + glState);
  frontFuncBits = *(uint *)(&DAT_001db348 + (*(ushort *)(((unsigned char *)0x000031a0) + glState) & 7) * 4);
  if (frontFailOp != 0x1e02) {
    if (frontFailOp < 0x1e03) {
      hwFrontFailOp = 5;
      if (((frontFailOp != 0x150a) && (hwFrontFailOp = 2, frontFailOp != 0x1e01)) && (hwFrontFailOp = 1, frontFailOp != 0)) {
LAB_000510a0:
        hwFrontFailOp = 0;
      }
    }
    else {
      hwFrontFailOp = 6;
      if ((frontFailOp != 0x8507) && (hwFrontFailOp = 7, frontFailOp != 0x8508)) {
        if (frontFailOp != 0x1e03) goto LAB_000510a0;
        hwFrontFailOp = 4;
      }
    }
  }
  frontZpassOp = *(ushort *)(((unsigned char *)0x000031a6) + glState);
  hwFrontZpassOp = 3;
  if (frontZpassOp != 0x1e02) {
    if (frontZpassOp < 0x1e03) {
      hwFrontZpassOp = 5;
      if (((frontZpassOp != 0x150a) && (hwFrontZpassOp = 2, frontZpassOp != 0x1e01)) && (hwFrontZpassOp = 1, frontZpassOp != 0)) {
LAB_0005111c:
        hwFrontZpassOp = 0;
      }
    }
    else {
      hwFrontZpassOp = 6;
      if ((frontZpassOp != 0x8507) && (hwFrontZpassOp = 7, frontZpassOp != 0x8508)) {
        if (frontZpassOp != 0x1e03) goto LAB_0005111c;
        hwFrontZpassOp = 4;
      }
    }
  }
  frontZfailOp = *(ushort *)(((unsigned char *)0x000031a4) + glState);
  hwFrontZfailOp = 3;
  if (frontZfailOp != 0x1e02) {
    if (frontZfailOp < 0x1e03) {
      hwFrontZfailOp = 5;
      if (((frontZfailOp != 0x150a) && (hwFrontZfailOp = 2, frontZfailOp != 0x1e01)) && (hwFrontZfailOp = 1, frontZfailOp != 0)) {
LAB_0005119c:
        hwFrontZfailOp = 0;
      }
    }
    else {
      hwFrontZfailOp = 6;
      if ((frontZfailOp != 0x8507) && (hwFrontZfailOp = 7, frontZfailOp != 0x8508)) {
        if (frontZfailOp != 0x1e03) goto LAB_0005119c;
        hwFrontZfailOp = 4;
      }
    }
  }
  hwBackFailOp = 3;
  *(char *)(glContext + 0x1aab) = (char)*(undefined4 *)(((unsigned char *)0x0000319c) + glState);
  *(char *)(glContext + 0x1aaa) = (char)*(undefined4 *)(((unsigned char *)0x00003198) + glState);
  *(char *)(glContext + 0x1aa9) = (char)*(undefined4 *)(((unsigned char *)0x00002e38) + glState);
  backFailOp = *(ushort *)(((unsigned char *)0x000031ba) + glState);
  backFuncBits = *(uint *)(&DAT_001db348 + (*(ushort *)(((unsigned char *)0x000031b8) + glState) & 7) * 4);
  if (backFailOp != 0x1e02) {
    if (backFailOp < 0x1e03) {
      hwBackFailOp = 5;
      if (((backFailOp != 0x150a) && (hwBackFailOp = 2, backFailOp != 0x1e01)) && (hwBackFailOp = 1, backFailOp != 0)) {
LAB_00051244:
        hwBackFailOp = 0;
      }
    }
    else {
      hwBackFailOp = 6;
      if ((backFailOp != 0x8507) && (hwBackFailOp = 7, backFailOp != 0x8508)) {
        if (backFailOp != 0x1e03) goto LAB_00051244;
        hwBackFailOp = 4;
      }
    }
  }
  backZpassOp = *(ushort *)(((unsigned char *)0x000031be) + glState);
  hwBackZpassOp = 3;
  if (backZpassOp != 0x1e02) {
    if (backZpassOp < 0x1e03) {
      hwBackZpassOp = 5;
      if (((backZpassOp != 0x150a) && (hwBackZpassOp = 2, backZpassOp != 0x1e01)) && (hwBackZpassOp = 1, backZpassOp != 0)) {
LAB_000512bc:
        hwBackZpassOp = 0;
      }
    }
    else {
      hwBackZpassOp = 6;
      if ((backZpassOp != 0x8507) && (hwBackZpassOp = 7, backZpassOp != 0x8508)) {
        if (backZpassOp != 0x1e03) goto LAB_000512bc;
        hwBackZpassOp = 4;
      }
    }
  }
  backZfailOp = *(ushort *)(((unsigned char *)0x000031bc) + glState);
  hwBackZfailOp = 3;
  if (backZfailOp != 0x1e02) {
    if (backZfailOp < 0x1e03) {
      hwBackZfailOp = 5;
      if (((backZfailOp != 0x150a) && (hwBackZfailOp = 2, backZfailOp != 0x1e01)) && (hwBackZfailOp = 1, backZfailOp != 0)) {
LAB_0005133c:
        hwBackZfailOp = 0;
      }
    }
    else {
      hwBackZfailOp = 6;
      if ((backZfailOp != 0x8507) && (hwBackZfailOp = 7, backZfailOp != 0x8508)) {
        if (backZfailOp != 0x1e03) goto LAB_0005133c;
        hwBackZfailOp = 4;
      }
    }
  }
  *(undefined1 *)(glContext + 0x23ed) = 1;
  *(uint *)(glContext + 0x1aa0) = *(uint *)(glContext + 0x1aa0) | 1;
  *(uint *)(glContext + 0x1aa4) =
       hwBackZfailOp << 0x18 |
       hwBackZpassOp << 0x15 |
       hwFrontZfailOp << 0xc |
       hwFrontZpassOp << 9 |
       hwBackFailOp << 0x12 |
       (backFuncBits & 7) << 0xf |
       hwFrontFailOp << 6 | (frontFuncBits & 7) << 3 | *(uint *)(glContext + 0x1aa4) & 0xf8000007;
  if ((*(int *)(((unsigned char *)0x00002e38) + glState) == 0) ||
     (hwBackZfailOp == 0 && (hwBackZpassOp == 0 && (hwFrontZfailOp == 0 && (hwFrontZpassOp == 0 && (hwBackFailOp == 0 && hwFrontFailOp == 0)))))) {
    *(undefined1 *)(glContext + 0x23ed) = 0;
  }
LAB_00051404:
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x808;
  return;
}

/* gldValidateBlend @ 0x51420 (3152 bytes) */
int gldValidateBlend(glContext)
  int glContext;
{
  double blendBlueScaled;
  double blendGreenScaled;
  double blendRedScaled;
  undefined2 blendHalfGreen;
  undefined2 blendHalfBlue;
  undefined2 blendHalfAlpha;
  int readsDestinationFlag;
  uint newLogicOpWord;
  uint blendColorBlueByte;
  int blendColorAlphaByte;
  int blendColorRedByte;
  int blendColorGreenByte;
  ushort dstFactorAlpha;
  ushort dstFactorRgb;
  ushort srcFactorRgb;
  ushort equationRgb;
  ushort equationAlpha;
  ushort srcFactorAlpha;
  bool usesDestinationColor;
  bool usesDestinationAlpha;
  float fixedPointRound;
  float fixedPointScale;
  int hwSrcFactorAlpha;
  int hwDstFactorAlpha;
  uint oldBlendWord0;
  int blendFuncKey;
  uint oldDirtyBits1930;
  int hwEquationAlpha;
  undefined2 blendHalfRed;
  int hwSrcFactorRgb;
  int hwDstFactorRgb;
  uint oldBlendWord0Saved;
  int blendFastPathMode;
  int hwEquationRgb;
  uint oldLogicOpWord;
  int glState;
  double blendColorScale;
  double intRangeBias;
  
  oldBlendWord0Saved = *(uint *)(glContext + 0x1a80);
  oldLogicOpWord = *(uint *)(0x00001af4 + glContext + 4);
  glState = *(int *)(*(int *)(glContext + 4) + 0x10);
  *(uint *)(glContext + 0x1a80) = oldBlendWord0Saved & 0x3ffffffe;
  if (((((unsigned char *)0x00002d84)[glState] == '\0') || (((unsigned char *)0x00002e33)[glState] != '\0')) ||
     ((*(int *)(((unsigned char *)0x00002d80) + glState) == -0x7ff97ffa &&
      ((((*(short *)(((unsigned char *)0x00002d68) + glState) == 1 && (*(short *)(((unsigned char *)0x00002d6c) + glState) == 1)) &&
        (*(short *)(((unsigned char *)0x00002d6a) + glState) == 0)) && (*(short *)(((unsigned char *)0x00002d6e) + glState) == 0))))))
  goto LAB_00051ee0;
  equationRgb = *(ushort *)(((unsigned char *)0x00002d80) + glState);
  if (equationRgb == 0x8008) {
    usesDestinationColor = true;
    hwEquationRgb = 5;
  }
  else if (equationRgb < 0x8009) {
    if (equationRgb == 0x8007) {
      usesDestinationColor = true;
      hwEquationRgb = 4;
    }
    else {
LAB_000514ec:
      usesDestinationColor = false;
      hwEquationRgb = 0;
    }
  }
  else if (equationRgb == 0x800a) {
    usesDestinationColor = false;
    hwEquationRgb = 2;
  }
  else {
    if (equationRgb != 0x800b) goto LAB_000514ec;
    usesDestinationColor = false;
    hwEquationRgb = 6;
  }
  equationAlpha = *(ushort *)(((unsigned char *)0x00002d82) + glState);
  if (equationAlpha == 0x8008) {
    usesDestinationAlpha = true;
    hwEquationAlpha = 5;
  }
  else if (equationAlpha < 0x8009) {
    if (equationAlpha == 0x8007) {
      usesDestinationAlpha = true;
      hwEquationAlpha = 4;
    }
    else {
LAB_0005157c:
      usesDestinationAlpha = false;
      hwEquationAlpha = 0;
    }
  }
  else if (equationAlpha == 0x800a) {
    usesDestinationAlpha = false;
    hwEquationAlpha = 2;
  }
  else {
    if (equationAlpha != 0x800b) goto LAB_0005157c;
    usesDestinationAlpha = false;
    hwEquationAlpha = 6;
  }
  srcFactorRgb = *(ushort *)(((unsigned char *)0x00002d68) + glState);
  if (srcFactorRgb == 0x305) {
    hwSrcFactorAlpha = 0x29;
    usesDestinationColor = true;
    hwSrcFactorRgb = 0x29;
  }
  else if (srcFactorRgb < 0x306) {
    if (srcFactorRgb == 0x301) {
      hwSrcFactorAlpha = 0x23;
      hwSrcFactorRgb = 0x23;
    }
    else if (srcFactorRgb < 0x302) {
      if (srcFactorRgb == 0) {
        hwSrcFactorAlpha = 0x20;
        hwSrcFactorRgb = 0x20;
      }
      else {
        if (srcFactorRgb != 0x300) goto LAB_00051614;
        hwSrcFactorAlpha = 0x22;
        hwSrcFactorRgb = 0x22;
      }
    }
    else if (srcFactorRgb == 0x303) {
      hwSrcFactorAlpha = 0x27;
      hwSrcFactorRgb = 0x27;
    }
    else if (srcFactorRgb < 0x304) {
      hwSrcFactorAlpha = 0x26;
      hwSrcFactorRgb = 0x26;
    }
    else {
      hwSrcFactorAlpha = 0x28;
      usesDestinationColor = true;
      hwSrcFactorRgb = 0x28;
    }
  }
  else if (srcFactorRgb == 0x8001) {
    hwSrcFactorAlpha = 0x2b;
    hwSrcFactorRgb = 0x2b;
  }
  else if (srcFactorRgb < 0x8002) {
    if (srcFactorRgb == 0x307) {
      hwSrcFactorAlpha = 0x25;
      usesDestinationColor = true;
      hwSrcFactorRgb = 0x25;
    }
    else if (srcFactorRgb < 0x307) {
      hwSrcFactorAlpha = 0x24;
      usesDestinationColor = true;
      hwSrcFactorRgb = 0x24;
    }
    else if (srcFactorRgb == 0x308) {
      hwSrcFactorAlpha = 0x2a;
      usesDestinationColor = true;
      hwSrcFactorRgb = 0x2a;
    }
    else {
LAB_00051614:
      hwSrcFactorAlpha = 0x21;
      hwSrcFactorRgb = 0x21;
    }
  }
  else if (srcFactorRgb == 0x8003) {
    hwSrcFactorRgb = 0x2d;
    hwSrcFactorAlpha = 0x2d;
  }
  else if (srcFactorRgb < 0x8003) {
    hwSrcFactorAlpha = 0x2c;
    hwSrcFactorRgb = 0x2c;
  }
  else {
    if (srcFactorRgb != 0x8004) goto LAB_00051614;
    hwSrcFactorAlpha = 0x2e;
    hwSrcFactorRgb = 0x2e;
  }
  srcFactorAlpha = *(ushort *)(((unsigned char *)0x00002d6c) + glState);
  if (srcFactorRgb != srcFactorAlpha) {
    if (srcFactorAlpha == 0x305) {
      usesDestinationAlpha = true;
      hwSrcFactorAlpha = 0x29;
    }
    else if (srcFactorAlpha < 0x306) {
      hwSrcFactorAlpha = 0x23;
      if (srcFactorAlpha != 0x301) {
        if (srcFactorAlpha < 0x302) {
          hwSrcFactorAlpha = 0x20;
          if ((srcFactorAlpha != 0) && (hwSrcFactorAlpha = 0x22, srcFactorAlpha != 0x300)) goto LAB_0005179c;
        }
        else {
          hwSrcFactorAlpha = 0x27;
          if ((srcFactorAlpha != 0x303) && (hwSrcFactorAlpha = 0x26, 0x303 < srcFactorAlpha)) {
            usesDestinationAlpha = true;
            hwSrcFactorAlpha = 0x28;
          }
        }
      }
    }
    else {
      hwSrcFactorAlpha = 0x2b;
      if (srcFactorAlpha != 0x8001) {
        if (srcFactorAlpha < 0x8002) {
          if (srcFactorAlpha == 0x307) {
            usesDestinationAlpha = true;
            hwSrcFactorAlpha = 0x25;
          }
          else if (srcFactorAlpha < 0x307) {
            usesDestinationAlpha = true;
            hwSrcFactorAlpha = 0x24;
          }
          else {
            if (srcFactorAlpha != 0x308) goto LAB_0005179c;
            usesDestinationAlpha = true;
            hwSrcFactorAlpha = 0x2a;
          }
        }
        else {
          hwSrcFactorAlpha = 0x2d;
          if (((srcFactorAlpha != 0x8003) && (hwSrcFactorAlpha = 0x2c, 0x8002 < srcFactorAlpha)) &&
             (hwSrcFactorAlpha = 0x2e, srcFactorAlpha != 0x8004)) {
LAB_0005179c:
            hwSrcFactorAlpha = 0x21;
          }
        }
      }
    }
  }
  dstFactorRgb = *(ushort *)(((unsigned char *)0x00002d6a) + glState);
  if (dstFactorRgb == 0x305) {
    hwDstFactorAlpha = 0x29;
    usesDestinationColor = true;
    hwDstFactorRgb = 0x29;
  }
  else if (dstFactorRgb < 0x306) {
    if (dstFactorRgb == 0x301) {
      hwDstFactorAlpha = 0x23;
      usesDestinationColor = true;
      hwDstFactorRgb = 0x23;
    }
    else if (dstFactorRgb < 0x302) {
      if (dstFactorRgb == 1) {
        hwDstFactorAlpha = 0x21;
        usesDestinationColor = true;
        hwDstFactorRgb = 0x21;
      }
      else {
        if (dstFactorRgb != 0x300) goto LAB_000518a4;
        hwDstFactorAlpha = 0x22;
        usesDestinationColor = true;
        hwDstFactorRgb = 0x22;
      }
    }
    else if (dstFactorRgb == 0x303) {
      hwDstFactorAlpha = 0x27;
      usesDestinationColor = true;
      hwDstFactorRgb = 0x27;
    }
    else if (dstFactorRgb < 0x304) {
      hwDstFactorAlpha = 0x26;
      usesDestinationColor = true;
      hwDstFactorRgb = 0x26;
    }
    else {
      hwDstFactorAlpha = 0x28;
      usesDestinationColor = true;
      hwDstFactorRgb = 0x28;
    }
  }
  else if (dstFactorRgb == 0x8001) {
    hwDstFactorAlpha = 0x2b;
    usesDestinationColor = true;
    hwDstFactorRgb = 0x2b;
  }
  else if (dstFactorRgb < 0x8002) {
    if (dstFactorRgb == 0x306) {
      hwDstFactorAlpha = 0x24;
      usesDestinationColor = true;
      hwDstFactorRgb = 0x24;
    }
    else if (dstFactorRgb == 0x307) {
      hwDstFactorAlpha = 0x25;
      usesDestinationColor = true;
      hwDstFactorRgb = 0x25;
    }
    else {
LAB_000518a4:
      hwDstFactorAlpha = 0x20;
      hwDstFactorRgb = 0x20;
    }
  }
  else if (dstFactorRgb == 0x8003) {
    hwDstFactorAlpha = 0x2d;
    usesDestinationColor = true;
    hwDstFactorRgb = 0x2d;
  }
  else if (dstFactorRgb < 0x8003) {
    hwDstFactorAlpha = 0x2c;
    usesDestinationColor = true;
    hwDstFactorRgb = 0x2c;
  }
  else {
    if (dstFactorRgb != 0x8004) goto LAB_000518a4;
    hwDstFactorAlpha = 0x2e;
    usesDestinationColor = true;
    hwDstFactorRgb = 0x2e;
  }
  dstFactorAlpha = *(ushort *)(((unsigned char *)0x00002d6e) + glState);
  if (dstFactorRgb != dstFactorAlpha) {
    if (dstFactorAlpha == 0x305) {
      usesDestinationAlpha = true;
      hwDstFactorAlpha = 0x29;
    }
    else if (dstFactorAlpha < 0x306) {
      if (dstFactorAlpha == 0x301) {
        usesDestinationAlpha = true;
        hwDstFactorAlpha = 0x23;
      }
      else if (dstFactorAlpha < 0x302) {
        if (dstFactorAlpha == 1) {
          usesDestinationAlpha = true;
          hwDstFactorAlpha = 0x21;
        }
        else {
          if (dstFactorAlpha != 0x300) goto LAB_00051a20;
          usesDestinationAlpha = true;
          hwDstFactorAlpha = 0x22;
        }
      }
      else if (dstFactorAlpha == 0x303) {
        usesDestinationAlpha = true;
        hwDstFactorAlpha = 0x27;
      }
      else if (dstFactorAlpha < 0x304) {
        usesDestinationAlpha = true;
        hwDstFactorAlpha = 0x26;
      }
      else {
        usesDestinationAlpha = true;
        hwDstFactorAlpha = 0x28;
      }
    }
    else if (dstFactorAlpha == 0x8001) {
      usesDestinationAlpha = true;
      hwDstFactorAlpha = 0x2b;
    }
    else if (dstFactorAlpha < 0x8002) {
      if (dstFactorAlpha == 0x306) {
        usesDestinationAlpha = true;
        hwDstFactorAlpha = 0x24;
      }
      else if (dstFactorAlpha == 0x307) {
        usesDestinationAlpha = true;
        hwDstFactorAlpha = 0x25;
      }
      else {
LAB_00051a20:
        hwDstFactorAlpha = 0x20;
      }
    }
    else if (dstFactorAlpha == 0x8003) {
      usesDestinationAlpha = true;
      hwDstFactorAlpha = 0x2d;
    }
    else if (dstFactorAlpha < 0x8003) {
      usesDestinationAlpha = true;
      hwDstFactorAlpha = 0x2c;
    }
    else {
      if (dstFactorAlpha != 0x8004) goto LAB_00051a20;
      usesDestinationAlpha = true;
      hwDstFactorAlpha = 0x2e;
    }
  }
  if ((equationRgb == 0x8006) &&
     (blendFuncKey = *(int *)(((unsigned char *)0x00002d68) + glState), blendFuncKey == *(int *)(((unsigned char *)0x00002d6c) + glState))) {
    if ((blendFuncKey == 0x3020303) || ((blendFuncKey == 0x3020001 || (blendFuncKey == 0x303)))) {
      blendFastPathMode = 1;
    }
    else if ((((blendFuncKey == 0x301) || (blendFuncKey == 0x10001)) || (blendFuncKey == 0x3060001)) ||
            (blendFuncKey == 0x3040001)) {
      blendFastPathMode = 2;
      if ((*(uint *)(glContext + 0x8c) & 0x400000) == 0) goto LAB_00051c10;
    }
    else if (blendFuncKey == 0x3070001) {
LAB_00051c10:
      blendFastPathMode = 3;
    }
    else {
      blendFastPathMode = 4;
      if ((blendFuncKey != 0x3030001) && (blendFastPathMode = 6, blendFuncKey != 0x3060000)) goto LAB_00051c00;
    }
  }
  else {
LAB_00051c00:
    blendFastPathMode = 0;
  }
  oldBlendWord0 = *(uint *)(glContext + 0x1a80);
  *(uint *)(glContext + 0x1a80) = oldBlendWord0 | 3;
  blendColorScale = DOUBLE_001aa258;
  intRangeBias = DOUBLE_001aa1e8;
  if ((usesDestinationColor) || (readsDestinationFlag = 0, usesDestinationAlpha)) {
    readsDestinationFlag = 1;
  }
  *(uint *)(glContext + 0x1a84) =
       hwDstFactorAlpha << 0x18 | hwSrcFactorAlpha << 0x10 | hwEquationAlpha << 0xc | *(uint *)(glContext + 0x1a84) & 0xc0c08fff;
  *(uint *)(glContext + 0x1a80) =
       hwDstFactorRgb << 0x18 |
       hwSrcFactorRgb << 0x10 | hwEquationRgb << 0xc | blendFastPathMode << 3 | readsDestinationFlag << 2 | oldBlendWord0 & 0xc0c08fc3 | 3;
  blendColorScale = (double)*(float *)(((unsigned char *)0x00002d7c) + glState) * blendColorScale;
  if (intRangeBias <= blendColorScale) {
    blendColorAlphaByte = (int)(blendColorScale - intRangeBias) + -0x80000000;
  }
  else {
    blendColorAlphaByte = (int)blendColorScale;
  }
  blendRedScaled = (double)*(float *)(((unsigned char *)0x00002d70) + glState) * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= blendRedScaled) {
    blendColorRedByte = (int)(blendRedScaled - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    blendColorRedByte = (int)blendRedScaled;
  }
  blendGreenScaled = (double)*(float *)(((unsigned char *)0x00002d74) + glState) * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= blendGreenScaled) {
    blendColorGreenByte = (int)(blendGreenScaled - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    blendColorGreenByte = (int)blendGreenScaled;
  }
  blendBlueScaled = (double)*(float *)(((unsigned char *)0x00002d78) + glState) * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= blendBlueScaled) {
    blendColorBlueByte = (int)(blendBlueScaled - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    blendColorBlueByte = (uint)(int)blendBlueScaled;
  }
  *(uint *)(glContext + 0x1a88) = blendColorAlphaByte << 0x18 | blendColorRedByte << 0x10 | blendColorGreenByte << 8 | blendColorBlueByte;
  fixedPointScale = FLOAT_001aa154;
  fixedPointRound = FLOAT_001aa10c;
  if ((*(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x3c00) ==
      0x2800) {
    blendHalfRed = ((uint (*)())floatToHalfBits)((double)*(float *)(((unsigned char *)0x00002d70) + glState));
    *(undefined2 *)(glContext + 0x1a8e) = blendHalfRed;
    blendHalfAlpha = ((uint (*)())floatToHalfBits)((double)*(float *)(((unsigned char *)0x00002d7c) + glState));
    *(undefined2 *)(glContext + 0x1a8c) = blendHalfAlpha;
    blendHalfBlue = ((uint (*)())floatToHalfBits)((double)*(float *)(((unsigned char *)0x00002d78) + glState));
    *(undefined2 *)(glContext + 0x1a92) = blendHalfBlue;
    blendHalfGreen = ((uint (*)())floatToHalfBits)((double)*(float *)(((unsigned char *)0x00002d74) + glState));
    *(undefined2 *)(glContext + 0x1a90) = blendHalfGreen;
  }
  else {
    *(short *)(glContext + 0x1a8e) =
         (short)(int)(*(float *)(((unsigned char *)0x00002d70) + glState) * FLOAT_001aa154 + FLOAT_001aa10c);
    *(short *)(glContext + 0x1a8c) = (short)(int)(*(float *)(((unsigned char *)0x00002d7c) + glState) * fixedPointScale + fixedPointRound);
    *(short *)(glContext + 0x1a92) = (short)(int)(*(float *)(((unsigned char *)0x00002d78) + glState) * fixedPointScale + fixedPointRound);
    *(short *)(glContext + 0x1a90) = (short)(int)(*(float *)(((unsigned char *)0x00002d74) + glState) * fixedPointScale + fixedPointRound);
  }
LAB_00051ee0:
  if ((((unsigned char *)0x00002ddc)[glState] == '\0') || ((*(uint *)(*(int *)(glContext + 4) + 0x154) & 0xf) != 3))
  {
    *(uint *)(glContext + 0x1af0) = *(uint *)(glContext + 0x1af0) & 0xfffffff0 | 5;
  }
  else {
    *(uint *)(glContext + 0x1af0) = *(uint *)(glContext + 0x1af0) & 0xfffffff0 | 6;
  }
  if ((((unsigned char *)0x00002e33)[glState] == '\0') || (((unsigned char *)0x00001492)[glContext] != '\0')) {
    newLogicOpWord = *(uint *)(0x00001af4 + glContext + 4) & 0xfffffffb;
    *(uint *)(0x00001af4 + glContext + 4) = newLogicOpWord;
  }
  else {
    switch(*(undefined2 *)(((unsigned char *)0x00002e30) + glState)) {
    case 0x1500:
      glState = 0;
      break;
    case 0x1501:
      glState = 8;
      break;
    case 0x1502:
      glState = 4;
      break;
    default:
      glState = 0xc;
      break;
    case 0x1504:
      glState = 2;
      break;
    case 0x1505:
      glState = 10;
      break;
    case 0x1506:
      glState = 6;
      break;
    case 0x1507:
      glState = 0xe;
      break;
    case 0x1508:
      glState = 1;
      break;
    case 0x1509:
      glState = 9;
      break;
    case 0x150a:
      glState = 5;
      break;
    case 0x150b:
      glState = 0xd;
      break;
    case 0x150c:
      glState = 3;
      break;
    case 0x150d:
      glState = 0xb;
      break;
    case 0x150e:
      glState = 7;
      break;
    case 0x150f:
      glState = 0xf;
    }
    newLogicOpWord = glState << 8 | *(uint *)(0x00001af4 + glContext + 4) & 0xfffff0ff | 4;
    *(uint *)(0x00001af4 + glContext + 4) = newLogicOpWord;
  }
  oldDirtyBits1930 = *(uint *)(glContext + 0x1930);
  *(uint *)(glContext + 0x1930) = oldDirtyBits1930 | 4;
  if (oldLogicOpWord != newLogicOpWord) {
    *(uint *)(glContext + 0x1930) = oldDirtyBits1930 | 0x10004;
  }
  if (((oldBlendWord0Saved & 1) == 0) && ((*(uint *)(glContext + 0x1a80) & 1) != 0)) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x100;
  }
  return;
}

/* gldValidateViewport @ 0x520c0 (436 bytes) */
double gldValidateViewport(int glContext,double fprF1,double fprF2,double fprF3,double fprF4,double fprF5,double fprF6,double fprF7,double fprF8)
{
  float yPixelScale;
  float xPixelScale;
  float halfHeight;
  float halfWidth;
  float centerY;
  double intToDoubleBias;
  uint viewportX;
  int glState;
  int glContextWord1c98;
  int glContextWord1c9c;
  int glContextWord1c90;
  int glContextWord1c94;
  int glContextWord1c88;
  int glStateBlock;
  int glContextWord1c8c;
  
  intToDoubleBias = DOUBLE_001aa1e0;
  halfWidth = FLOAT_001aa10c;
  glState = *(int *)(glContext + 4);
  glContextWord1c9c = *(int *)(glContext + 0x1c9c);
  glContextWord1c98 = *(int *)(glContext + 0x1c98);
  glContextWord1c88 = *(int *)(glContext + 0x1c88);
  glContextWord1c94 = *(int *)(glContext + 0x1c94);
  glContextWord1c90 = *(int *)(glContext + 0x1c90);
  glContextWord1c8c = *(int *)(glContext + 0x1c8c);
  glStateBlock = *(int *)(glState + 0x10);
  yPixelScale = *(float *)(glState + 0x2a58);
  xPixelScale = *(float *)(glState + 0x2a54);
  *(undefined4 *)(glContext + 0x1c9c) = *(undefined4 *)(glStateBlock + 0x1818);
  *(undefined4 *)(glContext + 0x1c98) = *(undefined4 *)(glStateBlock + 0x1828);
  viewportX = *(uint *)(glStateBlock + 0x1840);
  halfHeight = yPixelScale * (float)((double)CONCAT44(0x43300000,*(uint *)(glStateBlock + 0x184c) ^ 0x80000000) -
                         intToDoubleBias) * halfWidth;
  centerY = yPixelScale * (float)((double)CONCAT44(0x43300000,*(uint *)(glStateBlock + 0x1844) ^ 0x80000000) -
                         intToDoubleBias) + halfHeight;
  halfWidth = xPixelScale * (float)((double)CONCAT44(0x43300000,*(uint *)(glStateBlock + 0x1848) ^ 0x80000000) -
                         intToDoubleBias) * halfWidth;
  if (*(char *)(glContext + 0x293c) != '\0') {
    centerY = yPixelScale * (float)((double)CONCAT44(0x43300000,*(uint *)(glState + 0x160) ^ 0x80000000) -
                           intToDoubleBias) - centerY;
    halfHeight = -halfHeight;
  }
  *(float *)(glContext + 0x1c8c) = halfWidth;
  *(float *)(glContext + 0x1c88) =
       xPixelScale * (float)((double)CONCAT44(0x43300000,viewportX ^ 0x80000000) - intToDoubleBias) + halfWidth;
  *(float *)(glContext + 0x1c94) = halfHeight;
  *(float *)(glContext + 0x1c90) = centerY;
  if (*(char *)(glContext + 0x124) != '\0') {
    *(undefined4 *)(glContext + 0x1c8c) = *(undefined4 *)(glContext + 0x2814);
    *(undefined4 *)(glContext + 0x1c94) = *(undefined4 *)(glContext + 0x2818);
  }
  *(undefined4 *)(glContext + 0x1ca8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1cb0) = 0x3f800000;
  if ((((glContextWord1c8c != *(int *)(glContext + 0x1c8c)) || (glContextWord1c88 != *(int *)(glContext + 0x1c88))) ||
      (glContextWord1c94 != *(int *)(glContext + 0x1c94))) ||
     (((glContextWord1c90 != *(int *)(glContext + 0x1c90) || (glContextWord1c9c != *(int *)(glContext + 0x1c9c))) ||
      (glContextWord1c98 != *(int *)(glContext + 0x1c98))))) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x80;
  }
  ((int (*)())gldValidateScissor)(glContext);
  return;
}

/* FUN_00052280 @ 0x52280 (2608 bytes) */
int FUN_00052280(glContext)
  int glContext;
{
  uint padCountdown;
  uint padWords;
  undefined4 *nextPacket;
  undefined4 *packet;
  undefined4 unitShadowValue5;
  undefined4 unitShadowValue3;
  undefined4 unitShadowValue2;
  undefined4 unitShadowValue1;
  int glState;
  int unitIndex;
  uint registerDirty;
  uint fgAlphaFunc;
  uint rb3dBlendcntl;
  uint fgFogBlend;
  undefined4 glContextWord2370;
  undefined4 vapVtxSize;
  undefined4 glContextWord1ca0;
  undefined4 gbMspos1;
  undefined4 gbAaConfig;
  undefined4 suDepthOffset;
  undefined4 usOutFmt3;
  undefined4 rb3dColorChannelMask;
  undefined4 gaLineStippleConfig;
  undefined4 gaPointT1;
  undefined4 gaPointSize;
  undefined4 vapOutVtxFmt1;
  undefined4 gbSelect;
  undefined4 gbEnable;
  undefined4 gaPolyMode;
  undefined4 scHyperzEn;
  undefined4 rb3dConstantColorAr;
  undefined4 rb3dDitherCtl;
  undefined4 rb3dConstantColor;
  undefined4 rb3dAblendcntl;
  undefined4 gaFogOffset;
  undefined4 fgFogColorB;
  undefined *engineCapsEntry;
  undefined4 unitShadowValue0;
  code *streamSetCurrent;
  uint dirtyUnitMask;
  uint *puVar5;
  undefined4 *puVar6;
  undefined4 *texUnitShadowPtr4;
  undefined4 *texUnitShadowPtr5;
  int iVar9;
  int iVar10;
  undefined4 *texUnitShadowPtr3;
  uint dirtyBits;
  undefined4 *texUnitShadowPtr0;
  undefined4 *texUnitShadowPtr1;
  undefined4 *texUnitShadowPtr2;
  int iVar16;
  
  dirtyBits = *(uint *)(glContext + 0x1930);
  dirtyUnitMask = *(uint *)(glContext + 0x1934) & *(uint *)(glContext + 0x27b0);
  dirtyUnitMask = dirtyUnitMask | (dirtyUnitMask & *(uint *)(glContext + 0x27b4)) << 8;
  if (dirtyUnitMask != 0) {
    texUnitShadowPtr0 = (undefined4 *)(glContext + 0x1cdc);
    texUnitShadowPtr1 = (undefined4 *)(glContext + 0x1d1c);
    texUnitShadowPtr2 = (undefined4 *)(glContext + 0x1d5c);
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0xe0);
    iVar9 = *(int *)(glContext + 0x1938);
    texUnitShadowPtr3 = (undefined4 *)(glContext + 0x1d9c);
    texUnitShadowPtr4 = (undefined4 *)(glContext + 0x1ddc);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    texUnitShadowPtr5 = (undefined4 *)(glContext + 0x1e1c);
    do {
      if ((dirtyUnitMask & 1) != 0) {
        *packet = ((unsigned char *)0x00001100) + iVar9;
        unitShadowValue0 = *texUnitShadowPtr0;
        packet[2] = ((unsigned char *)0x00001110) + iVar9;
        packet[1] = unitShadowValue0;
        unitShadowValue1 = *texUnitShadowPtr1;
        packet[4] = ((unsigned char *)0x00001120U) + iVar9;
        packet[3] = unitShadowValue1;
        unitShadowValue2 = *texUnitShadowPtr2;
        packet[6] = ((unsigned char *)0x00001130) + iVar9;
        packet[5] = unitShadowValue2;
        unitShadowValue3 = *texUnitShadowPtr3;
        packet[8] = ((unsigned char *)0x00001170U) + iVar9;
        packet[7] = unitShadowValue3;
        unitShadowValue5 = *texUnitShadowPtr5;
        packet[10] = ((unsigned char *)0x00001160) + iVar9;
        packet[0xc] = ((unsigned char *)0x00001140) + iVar9;
        packet[0xb] = 0;
        packet[9] = unitShadowValue5;
        packet[0xd] = *texUnitShadowPtr4;
        packet = packet + 0xe;
      }
      dirtyUnitMask = dirtyUnitMask >> 1;
      iVar9 = iVar9 + 1;
      texUnitShadowPtr0 = texUnitShadowPtr0 + 1;
      texUnitShadowPtr1 = texUnitShadowPtr1 + 1;
      texUnitShadowPtr2 = texUnitShadowPtr2 + 1;
      texUnitShadowPtr3 = texUnitShadowPtr3 + 1;
      texUnitShadowPtr5 = texUnitShadowPtr5 + 1;
      texUnitShadowPtr4 = texUnitShadowPtr4 + 1;
    } while (dirtyUnitMask != 0);
    streamSetCurrent = *(code **)(glContext + 0x275c);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    (*streamSetCurrent)(glContext,packet);
  }
  if (((*(uint *)(glContext + 0x44) & 0x100) == 0) || ((*(uint *)(glContext + 0x27b0) & 1) != 0)) {
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
    nextPacket = packet + 2;
    *packet = ((unsigned char *)0x00001041U);
    packet[1] = *(int *)(glContext + 0x27b0) << (*(uint *)(glContext + 0x1938) & 0x3f);
  }
  else {
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,4);
    nextPacket = packet + 4;
    *packet = ((unsigned char *)0x00001041U);
    packet[1] = (*(uint *)(glContext + 0x27b0) | 1) << (*(uint *)(glContext + 0x1938) & 0x3f);
    unitIndex = *(int *)(glContext + 0x1938);
    packet[3] = 0;
    packet[2] = ((unsigned char *)0x00001100) + unitIndex;
  }
  streamSetCurrent = *(code **)(glContext + 0x275c);
  *(undefined4 **)(0x00002748 + glContext + 4) = nextPacket;
  (*streamSetCurrent)(glContext,nextPacket);
  if (dirtyBits == 0) {
    *(undefined4 *)(glContext + 0x1934) = 0;
  }
  else {
    nextPacket = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0xde);
    *(undefined4 **)(0x00002748 + glContext + 4) = nextPacket;
    packet = nextPacket;
    if ((dirtyBits & 0x100) != 0) {
      packet = nextPacket + 2;
      *nextPacket = ((unsigned char *)0x00001393U);
      nextPacket[1] = 10;
    }
    if ((dirtyBits & 0x2000000) != 0) {
      *packet = ((unsigned char *)0x000013c6U);
      packet[1] = 3;
      packet = packet + 2;
    }
    if ((dirtyBits & 1) != 0) {
      *packet = 0x212f2;
      packet[1] = *(undefined4 *)(glContext + 0x1a54);
      packet[2] = *(undefined4 *)(glContext + 0x1a58);
      engineCapsEntry = PTR_DAT_001e88c8;
      fgFogColorB = *(undefined4 *)(glContext + 0x1a5c);
      packet[4] = ((unsigned char *)0x000012f0U);
      packet[3] = fgFogColorB;
      fgFogBlend = *(uint *)(glContext + 0x1aec);
      packet[5] = fgFogBlend;
      if ((*(uint *)(engineCapsEntry + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
        packet[5] = fgFogBlend & 0xfffffffe;
      }
      packet[6] = 0x110a5;
      packet[7] = *(undefined4 *)(glContext + 0x1a7c);
      gaFogOffset = *(undefined4 *)(glContext + 0x1a78);
      packet[9] = ((unsigned char *)0x00001007U);
      packet[8] = gaFogOffset;
      packet[10] = *(undefined4 *)(glContext + 0x1a64);
      packet = packet + 0xb;
    }
    engineCapsEntry = PTR_DAT_001e88c8;
    if ((dirtyBits & 4) != 0) {
      *packet = 0x11381;
      rb3dBlendcntl = *(uint *)(glContext + 0x1a80);
      packet[1] = rb3dBlendcntl;
      if ((*(uint *)(engineCapsEntry + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x4000) == 0) {
        packet[1] = rb3dBlendcntl & 0xfffffffc;
      }
      rb3dAblendcntl = *(undefined4 *)(glContext + 0x1a84);
      packet[3] = ((unsigned char *)0x00001384U);
      packet[2] = rb3dAblendcntl;
      rb3dConstantColor = *(undefined4 *)(glContext + 0x1a88);
      packet[5] = ((unsigned char *)0x00001394U);
      packet[4] = rb3dConstantColor;
      rb3dDitherCtl = *(undefined4 *)(glContext + 0x1af0);
      packet[7] = ((unsigned char *)0x000013beU);
      packet[6] = rb3dDitherCtl;
      rb3dConstantColorAr = *(undefined4 *)(glContext + 0x1a8c);
      packet[9] = ((unsigned char *)0x000013bfU);
      packet[8] = rb3dConstantColorAr;
      packet[10] = *(undefined4 *)(glContext + 0x1a90);
      packet = packet + 0xb;
    }
    if ((dirtyBits & 0x10000) != 0) {
      *packet = ((unsigned char *)0x00001386U);
      packet[1] = *(undefined4 *)(glContext + 0x1af8);
      packet = packet + 2;
    }
    if ((dirtyBits & 0x200) != 0) {
      *packet = ((unsigned char *)0x000012f5U);
      engineCapsEntry = PTR_DAT_001e88c8;
      fgAlphaFunc = *(uint *)(glContext + 0x1a4c);
      packet[1] = fgAlphaFunc;
      if ((*(uint *)(engineCapsEntry + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
        packet[1] = fgAlphaFunc & 0xfffff7ff;
      }
      packet[2] = ((unsigned char *)0x000012f8U);
      packet[3] = *(undefined4 *)(glContext + 0x1bdc);
      packet = packet + 4;
    }
    if ((dirtyBits & 0x8000000) != 0) {
      *packet = ((unsigned char *)0x000012f6U);
      packet[1] = *(undefined4 *)(glContext + 0x1a50);
      packet = packet + 2;
    }
    nextPacket = packet;
    if ((dirtyBits & 0x20000) != 0) {
      nextPacket = packet + 2;
      *packet = ((unsigned char *)0x000013c5U);
      packet[1] = *(undefined4 *)(glContext + 0x1ab8);
      if (1 < *(int *)(glContext + 0x23dc)) {
        nextPacket = packet + 4;
        packet[2] = ((unsigned char *)0x000010e6U);
        packet[3] = *(undefined4 *)(glContext + 0x1bd4);
      }
    }
    if ((dirtyBits & 0x800) != 0) {
      *nextPacket = 0x113c0;
      nextPacket[1] = *(undefined4 *)(glContext + 0x1aa0);
      nextPacket[2] = *(undefined4 *)(glContext + 0x1aa4);
      nextPacket = nextPacket + 3;
    }
    if ((dirtyBits & 8) != 0) {
      *nextPacket = ((unsigned char *)0x000013c2U);
      nextPacket[1] = *(undefined4 *)(glContext + 0x1aa8);
      nextPacket = nextPacket + 2;
    }
    if ((dirtyBits & 0x1000) != 0) {
      glState = *(int *)(glContext + 4);
      puVar5 = *(uint **)(glState + 0x1d8);
      *puVar5 = (int)nextPacket - (int)puVar5 >> 2 | *puVar5;
      *(undefined4 **)(glState + 0x1d8) = nextPacket;
      *nextPacket = 0x2f000000;
      nextPacket[1] = ((unsigned char *)0x000010e9U);
      scHyperzEn = *(undefined4 *)(glContext + 0x1ae0);
      nextPacket[3] = ((unsigned char *)0x000013c7U);
      nextPacket[2] = scHyperzEn;
      nextPacket[4] = *(undefined4 *)(glContext + 0x1ab0);
      nextPacket = nextPacket + 5;
    }
    if ((dirtyBits & 0x20) != 0) {
      *nextPacket = 0x410a9;
      nextPacket[1] = *(undefined4 *)(glContext + 0x1b1c);
      nextPacket[2] = *(undefined4 *)(glContext + 0x1b18);
      nextPacket[3] = *(undefined4 *)(glContext + 0x1b24);
      nextPacket[4] = *(undefined4 *)(glContext + 0x1b20);
      nextPacket[5] = *(undefined4 *)(0x00001b14 + glContext);
      nextPacket = nextPacket + 6;
    }
    if ((dirtyBits & 0x2000) != 0) {
      *nextPacket = ((unsigned char *)0x000010a2U);
      gaPolyMode = *(undefined4 *)(glContext + 0x1b3c);
      nextPacket[2] = ((unsigned char *)0x00001002U);
      nextPacket[1] = gaPolyMode;
      gbEnable = *(undefined4 *)(glContext + 0x1b50);
      nextPacket[4] = ((unsigned char *)0x00001007U);
      nextPacket[3] = gbEnable;
      gbSelect = *(undefined4 *)(glContext + 0x1a64);
      nextPacket[6] = 0x825;
      nextPacket[5] = gbSelect;
      vapOutVtxFmt1 = *(undefined4 *)(glContext + 0x1ba0);
      nextPacket[8] = ((unsigned char *)0x00001048U);
      nextPacket[7] = vapOutVtxFmt1;
      nextPacket[9] = *(undefined4 *)(glContext + 0x1bc0);
      nextPacket = nextPacket + 10;
    }
    if ((dirtyBits & 0x8000) != 0) {
      *nextPacket = ((unsigned char *)0x00001087U);
      gaPointSize = *(undefined4 *)(glContext + 0x1ccc);
      nextPacket[2] = 0x31080;
      nextPacket[1] = gaPointSize;
      nextPacket[3] = *(undefined4 *)(glContext + 0x1cbc);
      nextPacket[4] = *(undefined4 *)(glContext + 0x1cc4);
      nextPacket[5] = *(undefined4 *)(glContext + 0x1cc0);
      gaPointT1 = *(undefined4 *)(glContext + 0x1cc8);
      nextPacket[7] = ((unsigned char *)0x0000108cU);
      nextPacket[6] = gaPointT1;
      nextPacket[8] = *(undefined4 *)(glContext + 0x1cd0);
      nextPacket = nextPacket + 9;
    }
    if ((dirtyBits & 0x4000) != 0) {
      *nextPacket = 0x1108d;
      nextPacket[1] = *(undefined4 *)(glContext + 0x1b40);
      gaLineStippleConfig = *(undefined4 *)(glContext + 0x1b64);
      nextPacket[3] = ((unsigned char *)0x0000109aU);
      nextPacket[2] = gaLineStippleConfig;
      nextPacket[4] = *(undefined4 *)(glContext + 0x1b70);
      nextPacket = nextPacket + 5;
    }
    if ((dirtyBits & 0x10) != 0) {
      *nextPacket = ((unsigned char *)0x00001383U);
      rb3dColorChannelMask = *(undefined4 *)(0x00001af4 + glContext);
      nextPacket[2] = ((unsigned char *)0x0000109eU);
      nextPacket[1] = rb3dColorChannelMask;
      nextPacket[3] = *(undefined4 *)(glContext + 0x1b2c);
      nextPacket = nextPacket + 4;
    }
    if ((dirtyBits & 0x40) != 0) {
      *nextPacket = 0x311a9;
      nextPacket[1] = *(undefined4 *)(glContext + 0x233c);
      nextPacket[2] = *(undefined4 *)(glContext + 0x2340);
      nextPacket[3] = *(undefined4 *)(glContext + 0x2344);
      usOutFmt3 = *(undefined4 *)(0x00002348 + glContext);
      nextPacket[5] = ((unsigned char *)0x000010b1U);
      nextPacket[4] = usOutFmt3;
      suDepthOffset = *(undefined4 *)(0x00001b34 + glContext);
      nextPacket[7] = ((unsigned char *)0x000010b0U);
      nextPacket[6] = suDepthOffset;
      nextPacket[8] = *(undefined4 *)(glContext + 0x1b38);
      nextPacket = nextPacket + 9;
    }
    if ((dirtyBits & 0x400) != 0) {
      *nextPacket = ((unsigned char *)0x000010aeU);
      nextPacket[1] = *(undefined4 *)(glContext + 0x1b30);
      nextPacket = nextPacket + 2;
    }
    if ((dirtyBits & 0x80000) != 0) {
      *nextPacket = ((unsigned char *)0x00001008U);
      gbAaConfig = *(undefined4 *)(glContext + 0x1a60);
      nextPacket[2] = 0x11004;
      nextPacket[1] = gbAaConfig;
      nextPacket[3] = *(undefined4 *)(glContext + 0x1a68);
      gbMspos1 = *(undefined4 *)(glContext + 0x1a6c);
      nextPacket[5] = ((unsigned char *)0x000010faU);
      nextPacket[4] = gbMspos1;
      nextPacket[6] = *(undefined4 *)(glContext + 0x1b60);
      nextPacket = nextPacket + 7;
    }
    if ((dirtyBits & 2) != 0) {
      nextPacket = (undefined4 *)((int (*)())gldEmitScissorRegs)(glContext,nextPacket);
    }
    if ((dirtyBits & 0x80) != 0) {
      nextPacket = (undefined4 *)((int (*)())gldEmitViewportAndGuardBand)(glContext,nextPacket);
    }
    packet = nextPacket;
    if ((dirtyBits & 0x40000) != 0) {
      packet = nextPacket + 10;
      *nextPacket = 0x10860;
      nextPacket[1] = *(undefined4 *)(glContext + 0x1b78);
      glContextWord1ca0 = *(undefined4 *)(glContext + 0x1ca0);
      nextPacket[3] = 0x82d;
      nextPacket[2] = glContextWord1ca0;
      vapVtxSize = *(undefined4 *)(glContext + 0x1ca4);
      nextPacket[5] = 0x10824;
      nextPacket[4] = vapVtxSize;
      nextPacket[6] = *(undefined4 *)(glContext + 0x1b9c);
      vapOutVtxFmt1 = *(undefined4 *)(glContext + 0x1ba0);
      nextPacket[8] = ((unsigned char *)0x00001047U);
      nextPacket[7] = vapOutVtxFmt1;
      nextPacket[9] = *(undefined4 *)(glContext + 0x1bb0);
      if ((-1 < (int)dirtyBits) || (*(char *)(glContext + 0x1868) != '\0')) {
        iVar16 = 8;
        nextPacket[10] = ((unsigned char *)0x000010c0U);
        iVar10 = 0;
        nextPacket[0xb] = *(undefined4 *)(glContext + 0x1f2c);
        nextPacket[0xc] = *(uint *)(glContext + 0x1f28) | 0x70000;
        iVar9 = glContext;
        do {
          puVar6 = (undefined4 *)(iVar9 + 0x1ee8);
          iVar9 = iVar9 + 4;
          *(undefined4 *)((int)nextPacket + iVar10 + 0x34) = *puVar6;
          iVar10 = iVar10 + 4;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        packet = nextPacket + 0x15;
      }
    }
    if ((dirtyBits & 0x400000) != 0) {
      *packet = 0x887;
      packet[1] = *(undefined4 *)(glContext + 0x1b74);
      packet = packet + 2;
    }
    if ((dirtyBits & 0x800000) != 0) {
      *packet = ((unsigned char *)0x00001002U);
      gbEnable = *(undefined4 *)(glContext + 0x1b50);
      packet[2] = 0x825;
      packet[1] = gbEnable;
      vapOutVtxFmt1 = *(undefined4 *)(glContext + 0x1ba0);
      packet[4] = ((unsigned char *)0x00001048U);
      packet[3] = vapOutVtxFmt1;
      packet[5] = *(undefined4 *)(glContext + 0x1bc0);
      packet = packet + 6;
    }
    if ((dirtyBits & 0x4000000) != 0) {
      *(undefined4 *)(glContext + 0x1e68) = 0;
    }
    if ((dirtyBits & 0x10000000) != 0) {
      *packet = 0x413de;
      packet[1] = *(undefined4 *)(glContext + 0x2360);
      packet[2] = *(undefined4 *)(glContext + 0x2364);
      packet[3] = *(undefined4 *)(0x00002368 + glContext);
      packet[4] = *(undefined4 *)(glContext + 0x236c);
      glContextWord2370 = *(undefined4 *)(glContext + 0x2370);
      packet[6] = 0x313e9;
      packet[5] = glContextWord2370;
      packet[7] = *(undefined4 *)(glContext + 0x2374);
      packet[8] = *(undefined4 *)(glContext + 0x2378);
      packet[9] = *(undefined4 *)(glContext + 0x237c);
      packet[10] = *(undefined4 *)(glContext + 0x2380);
      packet = packet + 0xb;
    }
    if ((dirtyBits & 0x20000000) != 0) {
      *packet = ((unsigned char *)0x000813adU);
      packet[1] = *(undefined4 *)(glContext + 0x2384);
      packet[2] = *(undefined4 *)(0x00002388 + glContext);
      packet[3] = *(undefined4 *)(glContext + 0x238c);
      packet[4] = *(undefined4 *)(glContext + 0x2390);
      packet[5] = *(undefined4 *)(glContext + 0x2394);
      packet[6] = *(undefined4 *)(glContext + 0x2398);
      packet[7] = *(undefined4 *)(glContext + 0x239c);
      packet[8] = *(undefined4 *)(glContext + 0x23a0);
      packet[9] = *(undefined4 *)(glContext + 0x23a4);
      packet = packet + 10;
    }
    padWords = (uint)-(int)packet >> 2 & 0xf;
    nextPacket = packet;
    for (padCountdown = padWords; padCountdown != 0; padCountdown = padCountdown - 1) {
      *nextPacket = 0x80000000;
      nextPacket = nextPacket + 1;
    }
    streamSetCurrent = *(code **)(glContext + 0x275c);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet + padWords;
    (*streamSetCurrent)(glContext,packet + padWords);
    registerDirty = *(uint *)(glContext + 0x1930);
    if ((registerDirty & 0xc0100000) != 0) {
      (**(code **)(((unsigned char *)0x00001330) + glContext))(glContext,0xc0100000);
      registerDirty = *(uint *)(glContext + 0x1930);
    }
    if ((registerDirty & 0x200000) != 0) {
      FUN_00086710(glContext);
      registerDirty = *(uint *)(glContext + 0x1930);
    }
    if ((registerDirty & 0x1000000) != 0) {
      FUN_00086840(glContext);
    }
    *(undefined4 *)(glContext + 0x1934) = 0;
    *(undefined4 *)(glContext + 0x1930) = 0;
  }
  return;
}

/* FUN_00052cc0 @ 0x52cc0 (372 bytes) */
int FUN_00052cc0(glContext)
  int glContext;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  puVar2 = PTR_FUN_001e89b8;
  puVar1 = PTR_FUN_001e89b0;
  uVar3 = 0;
  if (glContext != -0x1168) {
    if (*(char *)(glContext + 0x1868) == '\0') {
      *(undefined **)(((unsigned char *)0x000011a0) + glContext) = PTR_FUN_001e89c4;
      *(undefined **)(((unsigned char *)0x000011a8) + glContext) = puVar2;
      puVar1 = PTR_FUN_001e89d8;
      *(undefined **)(((unsigned char *)0x000011a4) + glContext) = PTR_FUN_001e89c8;
      *(undefined **)(((unsigned char *)0x000011b0) + glContext) = puVar1;
      puVar1 = PTR_FUN_001e89a8;
      *(undefined **)(((unsigned char *)0x000011ac) + glContext) = PTR_LAB_001e89cc;
      *(undefined **)(((unsigned char *)0x00001190) + glContext) = puVar1;
      puVar1 = PTR_FUN_001e89e8;
      *(undefined **)(((unsigned char *)0x00001194) + glContext) = PTR_FUN_001e89b4;
      *(undefined **)(((unsigned char *)0x0000119c) + glContext) = puVar1;
      *(undefined **)(((unsigned char *)0x00001198) + glContext) = PTR_FUN_001e89a4;
    }
    else {
      *(undefined **)(((unsigned char *)0x000011a0) + glContext) = PTR_FUN_001e89bc;
      *(undefined **)(((unsigned char *)0x000011a8) + glContext) = puVar1;
      puVar1 = PTR_FUN_001e89d8;
      *(undefined **)(((unsigned char *)0x000011a4) + glContext) = PTR_FUN_001e89d0;
      *(undefined **)(((unsigned char *)0x000011b0) + glContext) = puVar1;
      puVar1 = PTR_FUN_001e89a0;
      *(undefined **)(((unsigned char *)0x000011ac) + glContext) = PTR_LAB_001e89d4;
      *(undefined **)(((unsigned char *)0x00001190) + glContext) = puVar1;
      puVar1 = PTR_FUN_001e89dc;
      *(undefined **)(((unsigned char *)0x00001194) + glContext) = PTR_FUN_001e89e4;
      *(undefined **)(((unsigned char *)0x0000119c) + glContext) = puVar1;
      *(undefined **)(((unsigned char *)0x00001198) + glContext) = PTR_FUN_001e89c0;
    }
    puVar1 = PTR_FUN_001e89ac;
    if (*(char *)(glContext + 0x1868) == '\0') {
      *(undefined4 *)(((unsigned char *)0x00001354) + glContext) = 0;
      *(undefined4 *)(((unsigned char *)0x0000134c) + glContext) = 0;
      *(undefined **)(((unsigned char *)0x00001350) + glContext) = PTR_FUN_001e89e0;
    }
    else {
      *(undefined4 *)(((unsigned char *)0x00001354) + glContext) = 0;
      *(undefined4 *)(((unsigned char *)0x0000134c) + glContext) = 0;
      *(undefined **)(((unsigned char *)0x00001350) + glContext) = puVar1;
    }
    ((unsigned char *)0x000013b0)[glContext] = 8;
    extvsInitState(glContext);
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_00052e60 @ 0x52e60 (112 bytes) */
int FUN_00052e60(glContext, arg2, param_3)
  int glContext;
  undefined4 arg2;
  uint param_3;
{
  undefined4 uVar1;
  
  *(undefined4 *)(0x00002748 + glContext + 4) = arg2;
  *(uint *)(glContext + 0x44) =
       (param_3 & 1) << 0x13 | (param_3 & 1) << 0x14 | *(uint *)(glContext + 0x44) & 0xffe7ffff;
  if (*(char *)(glContext + 0x1868) == '\0') {
    extvsValidateProgramState(glContext,arg2);
  }
  else {
    (**(code **)((int)((unsigned char *)0x000011cc) + glContext))(glContext);
  }
  uVar1 = *(undefined4 *)(0x00002748 + glContext + 4);
  *(undefined1 *)(glContext + 0x2d) = 0;
  return uVar1;
}

/* FUN_00052ee0 @ 0x52ee0 (128 bytes) */
int FUN_00052ee0(ctx, position)
  int ctx;
  undefined4 position;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(((unsigned char *)0x00001168) + ctx) + 0x1c;
  iVar1 = extvsSymbolListGetIndex(iVar2,position);
  if (iVar1 == 0) {
    iVar2 = *(int *)(((unsigned char *)0x0000116c) + ctx) + 0x14;
    iVar1 = extvsSymbolListGetIndex(iVar2,position);
    if (iVar1 == 0) {
      return -0x3ffcf000;
    }
  }
  iVar1 = *(int *)(iVar1 * 0x54 + *(int *)(iVar2 + 4));
  if (iVar1 == 0) {
    return -0x3ffcf000;
  }
  return iVar1;
}

/* FUN_00052f60 @ 0x52f60 (148 bytes) */
int FUN_00052f60(ctx, position)
  int ctx;
  undefined4 position;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(((unsigned char *)0x00001168) + ctx) + 0x1c;
  iVar1 = extvsSymbolListGetIndex(iVar2,position);
  if (iVar1 == 0) {
    iVar2 = *(int *)(((unsigned char *)0x0000116c) + ctx) + 0x14;
    iVar1 = extvsSymbolListGetIndex(iVar2,position);
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = *(int *)(iVar1 * 0x54 + *(int *)(iVar2 + 4) + 4);
  if (iVar1 == 0) {
    iVar1 = 0x81;
  }
  return iVar1;
}

/* FUN_00053000 @ 0x53000 (52 bytes) */
int FUN_00053000(glContext, updateFlags)
  int glContext;
  uint updateFlags;
{
  byte bVar1;
  
  bVar1 = 0xc;
  if ((updateFlags & 2) == 0) {
    bVar1 = 0;
  }
  *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x1000;
  *(byte *)(glContext + 0x2d) = bVar1 | *(byte *)(glContext + 0x2d);
  *(undefined1 *)(glContext + 0x29) = 1;
  return;
}

/* FUN_00053040 @ 0x53040 (20 bytes) */
int FUN_00053040(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if (param_2 != 0) {
    return 0x882;
  }
  return 4;
}

/* noop_53060 @ 0x53060 (4 bytes) */
int noop_53060(ctx)
  undefined4 ctx;
{
  /* hidden-argument defect (hidden_params.py) - real body is a single `blr`: an identity function
   * on r3, and its one real caller (part_005.c) does supply a real ctx. */
  return ctx;
}

/* extvsConstantsDirty @ 0x53070 (36 bytes) */
int extvsConstantsDirty(ctx)
  int ctx;
{
  if ((*(int *)(((unsigned char *)0x00001168) + ctx) != 0) &&
     (*(char *)(*(int *)(((unsigned char *)0x00001168) + ctx) + 0x10) != '\0')) {
    return 1;
  }
  return 0;
}

/* extvsClearConstantsDirty @ 0x530a0 (24 bytes) */
int extvsClearConstantsDirty(ctx)
  int ctx;
{
  if (*(int *)(((unsigned char *)0x00001168) + ctx) == 0) {
    return;
  }
  *(undefined1 *)(*(int *)(((unsigned char *)0x00001168) + ctx) + 0x10) = 0;
  return;
}

/* FUN_000530c0 @ 0x530c0 (184 bytes) */
int FUN_000530c0(ctx, symbolId, outInfo)
  int ctx;
  int symbolId;
  undefined4 *outInfo;
{
  int entriesLeft;
  int matchedRecord;
  int entryCursor;
  
  matchedRecord = *(int *)(((unsigned char *)0x00001168) + ctx);
  if ((matchedRecord == 0) || (symbolId != *(int *)(matchedRecord + 8))) {
    entriesLeft = *(int *)(*(int *)(((unsigned char *)0x0000116c) + ctx) + 4);
    if (entriesLeft == 0) {
LAB_00053150:
      outInfo[4] = 0;
      *outInfo = 0;
      outInfo[1] = 0;
      outInfo[2] = 0;
      outInfo[3] = 0;
      return;
    }
    entryCursor = *(int *)(*(int *)(((unsigned char *)0x0000116c) + ctx) + 0xc);
    do {
      matchedRecord = entryCursor;
      if (*(int *)(entryCursor + 8) != symbolId) {
        matchedRecord = 0;
      }
      entriesLeft = entriesLeft + -1;
      if (entriesLeft == 0) {
        if (matchedRecord == 0) goto LAB_00053150;
        break;
      }
      entryCursor = entryCursor + 0x7c;
    } while (matchedRecord == 0);
  }
  *outInfo = *(undefined4 *)(matchedRecord + 0x54);
  outInfo[1] = *(int *)(matchedRecord + 0x5c) + *(int *)(matchedRecord + 0x60);
  outInfo[2] = *(undefined4 *)(matchedRecord + 100);
  outInfo[3] = *(undefined4 *)(matchedRecord + 0x58);
  outInfo[4] = *(undefined4 *)(matchedRecord + 0x68);
  return;
}

/* FUN_00053190 @ 0x53190 (116 bytes) */
int FUN_00053190(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(((unsigned char *)0x00001168) + param_1);
  if ((iVar1 != 0) && (uVar2 = (uint)(byte)((unsigned char *)0x000013b0)[param_1], uVar2 != 0)) {
    uVar4 = 0;
    uVar3 = 0;
    if (uVar2 == 0) {
      uVar2 = 1;
    }
    do {
      if (*(char *)(iVar1 + 0x71) != '\0') {
        uVar3 = uVar3 | 1 << (uVar4 & 0x3f);
      }
      uVar4 = uVar4 + 1;
      iVar1 = iVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    return uVar3;
  }
  return 0;
}

/* extvsGetOrCreateStateSymbol @ 0x53220 (284 bytes) */
int extvsGetOrCreateStateSymbol(ctx, stateKind, constantIndex, dataType, storageClass, stateFlags)
  int ctx;
  int stateKind;
  int constantIndex;
  undefined4 dataType;
  undefined4 storageClass;
  undefined4 stateFlags;
{
  int *newEntry;
  int *bucketEntry;
  int symbolId;
  uint hashBucket;
  int symbolList;
  
  hashBucket = (stateKind + constantIndex) * 4 & 0x7c;
  bucketEntry = *(int **)(hashBucket + *(int *)(((unsigned char *)0x0000116c) + ctx) + 0x28);
  while( true ) {
    if (bucketEntry == (int *)0x0) {
      symbolList = *(int *)(((unsigned char *)0x0000116c) + ctx) + 0x14;
      symbolId = extvsCreateSymbol(ctx,symbolList,dataType,storageClass,0x87e1,0,0,constantIndex);
      if (symbolId != 0) {
        symbolList = extvsSymbolListGetSymbol(symbolList,symbolId);
        *(undefined4 *)(symbolList + 0x50) = stateFlags;
        *(int *)(symbolList + 0x48) = stateKind;
        *(undefined1 *)(symbolList + 0x44) = 1;
        *(int *)(symbolList + 0x4c) = constantIndex;
        newEntry = (int *)(**(code **)(ctx + 0xc))(0x10);
        *newEntry = stateKind;
        newEntry[1] = constantIndex;
        newEntry[2] = symbolId;
        newEntry[3] = *(int *)(hashBucket + *(int *)(((unsigned char *)0x0000116c) + ctx) + 0x28);
        *(int **)(hashBucket + *(int *)(((unsigned char *)0x0000116c) + ctx) + 0x28) = newEntry;
      }
      return symbolId;
    }
    if ((stateKind == *bucketEntry) && (constantIndex == bucketEntry[1])) break;
    bucketEntry = (int *)bucketEntry[3];
  }
  return bucketEntry[2];
}

/* glGenSymbolsEXT_impl @ 0x53340 (368 bytes) */
int glGenSymbolsEXT_impl(ctx, dataType, storageClass, entryWord2c, elementCount, constantIndex)
  int ctx;
  int dataType;
  int storageClass;
  int entryWord2c;
  uint elementCount;
  int constantIndex;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint loopIndex;
  undefined4 uVar5;
  
  if (((dataType - 0x87beU < 3) &&
      (((((storageClass - 0x87c1U < 2 || (storageClass == 0x87c4)) || (storageClass == 0x87c3)) ||
        ((storageClass == -3 || (storageClass == -2)))) || (storageClass == -1)))) && (entryWord2c - 0x87e0U < 2)) {
    if (((storageClass - 0x87c3U < 2) || (storageClass == -3)) || ((storageClass == -2 || (storageClass == -1)))) {
      iVar3 = *(int *)(((unsigned char *)0x00001168) + ctx) + 0x1c;
      if (((unsigned char *)0x00001170)[ctx] == '\0') goto LAB_000534a0;
    }
    else {
      iVar3 = *(int *)(((unsigned char *)0x0000116c) + ctx) + 0x14;
    }
    uVar5 = extvsCreateSymbol(ctx,iVar3,dataType,storageClass,entryWord2c,0,elementCount,constantIndex);
    if (1 < elementCount) {
      loopIndex = 1;
      do {
        iVar1 = elementCount - loopIndex;
        iVar2 = loopIndex + constantIndex;
        loopIndex = loopIndex + 1;
        extvsCreateSymbol(ctx,iVar3,dataType,storageClass,entryWord2c,uVar5,iVar1,iVar2);
      } while (elementCount != loopIndex);
    }
  }
  else {
LAB_000534a0:
    uVar5 = 0;
  }
  return uVar5;
}

/* FUN_000534c0 @ 0x534c0 (260 bytes) */
int FUN_000534c0(ctx, elementCount, kindArray, elementValues, symbolOut)
  int ctx;
  uint elementCount;
  byte *kindArray;
  undefined4 *elementValues;
  undefined4 *symbolOut;
{
  int extvsState;
  undefined4 createdSymbol;
  uint elementIndex;
  uint nextElementIndex;
  undefined4 storageClassTable [8];
  
  storageClassTable[0] = DAT_001aa584;
  storageClassTable[2] = DAT_001aa58c;
  storageClassTable[1] = DAT_001aa588;
  extvsState = *(int *)(((unsigned char *)0x00001168) + ctx);
  createdSymbol = extvsCreateSymbol(ctx,extvsState + 0x1c,0x87bf,storageClassTable[*kindArray],0x87e1,0,elementCount,*elementValues);
  *symbolOut = createdSymbol;
  if (1 < elementCount) {
    elementIndex = 1;
    do {
      nextElementIndex = elementIndex + 1;
      createdSymbol = extvsCreateSymbol(ctx,extvsState + 0x1c,0x87bf,storageClassTable[kindArray[elementIndex]],0x87e1,*symbolOut,
                           elementCount - elementIndex,elementValues[elementIndex]);
      symbolOut[elementIndex] = createdSymbol;
      elementIndex = nextElementIndex;
    } while (elementCount != nextElementIndex);
  }
  return;
}

/* extvsShaderOp1Explicit @ 0x53610 (136 bytes) */
int extvsShaderOp1Explicit(glContext, op, dstId, dstMask, src0Id, src0Swizzle)
  int glContext;
  undefined4 op;
  undefined4 dstId;
  undefined4 dstMask;
  undefined4 src0Id;
  undefined4 src0Swizzle;
{
  if (((unsigned char *)0x00001170)[glContext] != '\0') {
    extvsAppendInstruction(glContext,*(undefined4 *)(((unsigned char *)0x00001168) + glContext),op,dstId,dstMask,src0Id,
                 src0Swizzle,0,&DAT_001db998,0,&DAT_001db998);
  }
  return;
}

/* extvsShaderOp2Explicit @ 0x536a0 (144 bytes) */
int extvsShaderOp2Explicit(glContext, op, dstId, dstMask, src0Id, src0Swizzle, src1Id, src1Swizzle)
  int glContext;
  undefined4 op;
  undefined4 dstId;
  undefined4 dstMask;
  undefined4 src0Id;
  undefined4 src0Swizzle;
  undefined4 src1Id;
  undefined4 src1Swizzle;
{
  if (((unsigned char *)0x00001170)[glContext] != '\0') {
    extvsAppendInstruction(glContext,*(undefined4 *)(((unsigned char *)0x00001168) + glContext),op,dstId,dstMask,src0Id,
                 src0Swizzle,src1Id,src1Swizzle,0,&DAT_001db998);
  }
  return;
}

/* extvsShaderOp3Explicit @ 0x53730 (132 bytes) */
int extvsShaderOp3Explicit(glContext, op, dstId, dstMask, src0Id, src0Swizzle, src1Id, src1Swizzle, src2Id, src2Swizzle)
  int glContext;
  undefined4 op;
  undefined4 dstId;
  undefined4 dstMask;
  undefined4 src0Id;
  undefined4 src0Swizzle;
  undefined4 src1Id;
  undefined4 src1Swizzle;
  undefined4 src2Id;
  undefined4 src2Swizzle;
{
  if (((unsigned char *)0x00001170)[glContext] != '\0') {
    extvsAppendInstruction(glContext,*(undefined4 *)(((unsigned char *)0x00001168) + glContext),op,dstId,dstMask,src0Id,
                 src0Swizzle,src1Id,src1Swizzle,src2Id,src2Swizzle);
  }
  return;
}

/* glSwizzleEXT_impl @ 0x537c0 (276 bytes) */
int glSwizzleEXT_impl(glContext, res, inId, inSwizzleArg, outX, outY, outZ, outW)
  int glContext;
  int res;
  undefined4 inId;
  undefined4 inSwizzleArg;
  int outX;
  uint outY;
  uint outZ;
  uint outW;
{
  int appendResult;
  int extvsState;
  int outSelectX;
  uint outSelectY;
  uint outSelectZ;
  uint outSelectW;
  
  if (((((((unsigned char *)0x00001170)[glContext] != '\0') && (outX - 0x87d5U < 0xb)) && (0x87d4 < outY)) &&
      ((outY < 0x87e0 && (0x87d4 < outZ)))) &&
     ((outZ < 0x87e0 && ((0x87d4 < outW && (outW < 0x87e0)))))) {
    extvsState = *(int *)(((unsigned char *)0x00001168) + glContext);
    outSelectX = outX;
    outSelectY = outY;
    outSelectZ = outZ;
    outSelectW = outW;
    appendResult = extvsAppendInstruction(glContext,extvsState,0x879a,res,inId,inSwizzleArg,&outSelectX,0,&DAT_001db998,0,
                         &DAT_001db998);
    if ((appendResult != 0) && (res - 0x879dU < 0x10)) {
      *(undefined1 *)((res - 0x879dU) + extvsState + 0x44) = 1;
    }
  }
  return;
}

/* extvsBeginShader @ 0x538e0 (164 bytes) */
int extvsBeginShader(ctx)
  int ctx;
{
  undefined4 uVar1;
  
  if (((unsigned char *)0x00001170)[ctx] == '\0') {
    uVar1 = *(undefined4 *)(((unsigned char *)0x00001168) + ctx);
    ((unsigned char *)0x00001170)[ctx] = 1;
    extvsFreeShaderObject(ctx,uVar1);
    extvsInitShaderObject(ctx,uVar1);
    *(undefined4 *)(((unsigned char *)0x00001184) + ctx) = 0;
    *(undefined4 *)(((unsigned char *)0x00001174) + ctx) = 0;
    *(undefined4 *)(((unsigned char *)0x0000117c) + ctx) = 0;
    *(undefined4 *)(((unsigned char *)0x00001178) + ctx) = 0;
    *(undefined4 *)(((unsigned char *)0x00001180) + ctx) = 0;
    if ((*(uint *)(ctx + 0x44) & 0x100000) != 0) {
      *(undefined1 *)(ctx + 0x29) = 1;
      *(uint *)(ctx + 0x38) = *(uint *)(ctx + 0x38) | 0x1000;
      *(byte *)(ctx + 0x2d) = *(byte *)(ctx + 0x2d) | 7;
    }
  }
  return;
}

/* extvsEndShader @ 0x53990 (244 bytes) */
int extvsEndShader(ctx)
  int ctx;
{
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int a1;
  
  if (((unsigned char *)0x00001170)[ctx] != '\0') {
    a1 = *(int *)(((unsigned char *)0x00001168) + ctx);
    ((unsigned char *)0x00001170)[ctx] = 0;
    extvsOptimizeProgram(ctx,a1);
    (**(code **)(((unsigned char *)0x00001190) + ctx))(ctx,a1);
    (**(code **)(((unsigned char *)0x00001194) + ctx))(ctx,a1);
    (**(code **)(((unsigned char *)0x0000119c) + ctx))
              (ctx,a1,in_r5,in_r6,in_r7,in_r8,*(code **)(((unsigned char *)0x0000119c) + ctx));
    *(undefined4 *)(((unsigned char *)0x00001174) + ctx) = *(undefined4 *)(a1 + 0x54);
    *(undefined4 *)(((unsigned char *)0x0000117c) + ctx) = *(undefined4 *)(a1 + 0x58);
    *(undefined4 *)(((unsigned char *)0x00001178) + ctx) = *(undefined4 *)(a1 + 0x5c);
    *(undefined4 *)(((unsigned char *)0x00001180) + ctx) = *(undefined4 *)(a1 + 0x60);
    *(undefined4 *)(((unsigned char *)0x00001184) + ctx) = *(undefined4 *)(a1 + 100);
    if ((*(uint *)(ctx + 0x44) & 0x100000) != 0) {
      *(uint *)(ctx + 0x38) = *(uint *)(ctx + 0x38) | 0x1000;
      *(byte *)(ctx + 0x2d) = *(byte *)(ctx + 0x2d) | 7;
      *(undefined1 *)(ctx + 0x29) = 1;
    }
  }
  return;
}

/* extvsFindShaderIndex @ 0x53a90 (100 bytes) */
int extvsFindShaderIndex(shaderTable, shaderId)
  int shaderTable;
  int shaderId;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(shaderTable + 4);
  if (iVar4 != 0) {
    if (shaderId == *(int *)(*(int *)(shaderTable + 0xc) + 8)) {
      return 0;
    }
    piVar3 = (int *)(*(int *)(shaderTable + 0xc) + 0x84);
    iVar2 = 0;
    while( true ) {
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) break;
      iVar1 = *piVar3;
      piVar3 = piVar3 + 0x1f;
      if (shaderId == iVar1) {
        return iVar2;
      }
    }
  }
  return -1;
}

/* extvsGetShaderById @ 0x53b00 (84 bytes) */
int extvsGetShaderById(glContext, shaderId)
  int glContext;
  undefined4 shaderId;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(((unsigned char *)0x0000116c) + glContext);
  iVar2 = ((int (*)())extvsFindShaderIndex)(iVar3,shaderId);
  iVar1 = 0;
  if (-1 < iVar2) {
    iVar1 = iVar2 * 0x7c + *(int *)(iVar3 + 0xc);
  }
  return iVar1;
}

/* extvsBindShader @ 0x53b60 (568 bytes) */
int extvsBindShader(glContext, shaderId)
  int glContext;
  undefined4 shaderId;
{
  uint ctxFlags;
  int boundShader;
  int newShaderArray;
  int shaderIndex;
  uint shaderCount;
  int refCount;
  int shaderEntry;
  uint vertexProgramEnable;
  uint oldStateWord;
  int shaderTable;
  
  shaderTable = *(int *)(((unsigned char *)0x0000116c) + glContext);
  refCount = *(int *)(*(int *)(((unsigned char *)0x00001168) + glContext) + 0xc);
  if (refCount != 0) {
    *(int *)(*(int *)(((unsigned char *)0x00001168) + glContext) + 0xc) = refCount + -1;
  }
  if (((unsigned char *)0x00001170)[glContext] == '\0') {
    shaderIndex = ((int (*)())extvsFindShaderIndex)(shaderTable,shaderId);
    if (shaderIndex < 0) {
      shaderCount = *(uint *)(shaderTable + 4);
      if ((shaderCount & 0xf) == 0) {
        newShaderArray = (**(code **)(glContext + 0xc))(shaderCount * 0x7c + 0x7c0);
        if (newShaderArray == 0) {
          return;
        }
        (**(code **)(((unsigned char *)0x00001344) + glContext))
                  (newShaderArray,*(undefined4 *)(shaderTable + 0xc),*(int *)(shaderTable + 4) * 0x7c);
        (**(code **)(glContext + 0x18))(*(undefined4 *)(shaderTable + 0xc));
        *(int *)(shaderTable + 0xc) = newShaderArray;
        extvsRefreshBoundVertexPrograms(glContext);
        shaderCount = *(uint *)(shaderTable + 4);
      }
      extvsInitShaderObject(glContext,shaderCount * 0x7c + *(int *)(shaderTable + 0xc));
      *(undefined4 *)(*(int *)(shaderTable + 4) * 0x7c + *(int *)(shaderTable + 0xc) + 8) = shaderId;
      *(undefined4 *)(((unsigned char *)0x00001188) + glContext) = *(undefined4 *)(shaderTable + 4);
      *(int *)(shaderTable + 4) = *(int *)(shaderTable + 4) + 1;
      *(undefined4 *)(((unsigned char *)0x00001184) + glContext) = 0;
      *(undefined4 *)(((unsigned char *)0x00001174) + glContext) = 0;
      *(undefined4 *)(((unsigned char *)0x0000117c) + glContext) = 0;
      *(undefined4 *)(((unsigned char *)0x00001178) + glContext) = 0;
      *(undefined4 *)(((unsigned char *)0x00001180) + glContext) = 0;
    }
    else {
      shaderEntry = *(int *)(shaderTable + 0xc);
      *(int *)(((unsigned char *)0x00001188) + glContext) = shaderIndex;
      shaderEntry = shaderIndex * 0x7c + shaderEntry;
      *(undefined4 *)(((unsigned char *)0x00001174) + glContext) = *(undefined4 *)(shaderEntry + 0x54);
      *(undefined4 *)(((unsigned char *)0x0000117c) + glContext) = *(undefined4 *)(shaderEntry + 0x58);
      *(undefined4 *)(((unsigned char *)0x00001178) + glContext) = *(undefined4 *)(shaderEntry + 0x5c);
      *(undefined4 *)(((unsigned char *)0x00001180) + glContext) = *(undefined4 *)(shaderEntry + 0x60);
      *(undefined4 *)(((unsigned char *)0x00001184) + glContext) = *(undefined4 *)(shaderEntry + 100);
    }
    boundShader = *(int *)(((unsigned char *)0x00001188) + glContext) * 0x7c + *(int *)(shaderTable + 0xc);
    *(int *)(((unsigned char *)0x00001168) + glContext) = boundShader;
    *(int *)(boundShader + 0xc) = *(int *)(boundShader + 0xc) + 1;
    ctxFlags = *(uint *)(glContext + 0x44);
    if ((ctxFlags & 0x800000) != 0) {
      oldStateWord = *(uint *)(glContext + 0x18a4);
      if ((ctxFlags & 0x100000) == 0) {
        if ((((int)ctxFlags < 0) &&
            (*(short *)(((unsigned char *)0x00002d48) + *(int *)(*(int *)(glContext + 4) + 0x10)) == -0x7e06)) ||
           (vertexProgramEnable = 0, (ctxFlags & 0x80800000) == 0x800000)) {
          vertexProgramEnable = 1;
        }
      }
      else {
        vertexProgramEnable = *(char *)(*(int *)(((unsigned char *)0x00001168) + glContext) + 0x6e) == '\0' ^ 1;
      }
      *(uint *)(glContext + 0x18a4) = vertexProgramEnable << 2 | oldStateWord & 0xfffffffb;
      if ((oldStateWord >> 2 & 1) != vertexProgramEnable) {
        *(undefined1 *)(glContext + 0x29) = 1;
        *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x20;
      }
    }
  }
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl noop_4c540");
asm(".set noop_4c540, _noop_4c540");
asm(".globl FUN_0004c560");
asm(".set FUN_0004c560, _FUN_0004c560");
asm(".globl gldValidateVertexStreams");
asm(".set gldValidateVertexStreams, _gldValidateVertexStreams");
asm(".globl FUN_0004dbe0");
asm(".set FUN_0004dbe0, _FUN_0004dbe0");
asm(".globl FUN_0004de30");
asm(".set FUN_0004de30, _FUN_0004de30");

/* issue #75 (follow-up #3): Ghidra recognized this as a THUNK - a pure trampoline stub that
 * just branches straight to the real function below, no different behavior or arguments - but
 * decls.h declares "thunk_FUN_xxx" as its own separate extern function that nothing in this
 * corpus ever DEFINES a body for. The stock ld apparently tolerated the resulting undefined
 * reference (never actually called in a way that mattered, or silently resolved some other
 * way); ld64 leaves it a real unresolved lazy symbol, crashing the moment this call path is
 * first taken. Real fix: alias the thunk name directly onto the real function, so calling
 * "thunk_FUN_xxx" IS calling FUN_xxx - which is exactly what the original binary's trampoline
 * did. */
asm(".globl _thunk_FUN_00053b60");
asm(".set _thunk_FUN_00053b60, _extvsBindShader");
