#include "decls.h"

/* ILReader__decodeInstruction @ 0xe4c40 (1764 bytes) */
int ILReader__decodeInstruction(ilReader, tokenIndexPtr, compiler)
  int ilReader;
  int *tokenIndexPtr;
  int compiler;
{
  int *sourceRecord;
  uint sourceModifierFlags;
  uint sourceFlags;
  uint extraWordFlag;
  uint destModifierFlags;
  uint destFlags;
  int sourceStartIndex;
  int destReplicaCount;
  int sourceCopyOffset;
  int sourceByteIndex;
  int sourceReplicaOffset;
  int sourceReplicaCount;
  int sourceSlotOffset;
  int sourceCount;
  int extraTokenCount;
  int streamCursor;
  int opcodeClass;
  int tailIndex;
  int destCount;
  int extraWordCount;
  int loopIndex6;
  int loopIndex4;
  int loopIndex3;
  int loopIndex;
  int loopIndex2;
  int loopIndex7;
  int loopIndex5;
  int *destRecord;
  short replicaNumber;
  uint tokenWord;
  uint repeatIndex;
  int streamBase;
  undefined4 opcode;
  undefined4 trailingTokenCount;
  int loopCountToken;
  int sourceCopyAddress;
  int tokenIndex;
  int fetchIndex;
  int operandStartIndex;
  int destModifierSlot;
  int destRecordOffset;
  uint *tokenWindow;
  int destTokenSlot;
  int destCopyOffset;
  int sourceTokenSlot;
  int sourceModifierSlot;
  
  *(undefined4 *)(ilReader + 0x60) = 0;
  tokenIndex = *tokenIndexPtr;
  *tokenIndexPtr = tokenIndex + 1;
  tokenIndex = ILReader__fetchToken(ilReader,tokenIndex);
  if (tokenIndex == 0) {
    *(int *)(ilReader + 0x34) = *(int *)(ilReader + 0x34) + 1;
    if ((*(int *)(ilReader + 0x30) != 0) && (*(int *)(ilReader + 0x84) == 0)) {
      *(undefined4 *)(ilReader + 0x84) = 1;
      *(undefined4 *)(ilReader + 0x7c) = 3;
      *(undefined4 *)(ilReader + 0x80) = 0;
      return 1;
    }
    return 0;
  }
  opcode = ILReader__currentOpcode(ilReader);
  tokenWindow = (uint *)(ilReader + 0x8c);
  opcodeClass = OpcodeRecord__getTranslationKind(opcode,*(undefined4 *)(*(int *)(compiler + 0x30c) + 0xc));
  if (opcodeClass == 6) {
    *(ushort *)(ilReader + 0x8e) =
         ((ushort)((uint)*(undefined4 *)(ilReader + 0x8c) >> 0x10) & 0x3fff) + 0xcf;
    opcode = ILReader__currentOpcode(ilReader);
  }
  switch(opcode) {
  case 0x76:
    if ((int)*tokenWindow < 0) {
      streamBase = *(int *)(ilReader + 0x28);
      *(undefined4 *)(ilReader + 0x58) = 2;
      fetchIndex = *tokenIndexPtr;
      streamCursor = *(int *)(ilReader + 0x74);
      *tokenIndexPtr = fetchIndex + 1;
      ILReader__fetchToken(ilReader,fetchIndex);
      fetchIndex = *tokenIndexPtr;
      loopIndex7 = 0;
      loopCountToken = *(int *)(fetchIndex * 4 + ilReader + 0x88);
      if (0 < loopCountToken) {
        while( true ) {
          loopIndex7 = loopIndex7 + 1;
          ILReader__fetchToken(ilReader,fetchIndex);
          if (loopCountToken == loopIndex7) break;
          fetchIndex = *tokenIndexPtr;
        }
        fetchIndex = *tokenIndexPtr;
      }
      *(int *)(fetchIndex * 4 + ilReader + 0x8c) = streamCursor - streamBase >> 2;
      return 1;
    }
    break;
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7e:
  case 0x7f:
  case 0x80:
  case 0x81:
  case 0x82:
  case 0x83:
  case 0x84:
  case 0x85:
  case 0x89:
    tokenWord = *tokenWindow;
    goto LAB_000e4e4c;
  case 0x7d:
    break;
  case 0x86:
  case 0x88:
  case 0x8a:
  case 0x8b:
  case 0x8c:
  case 0x8d:
    tokenWord = *tokenWindow;
    if ((tokenWord & 0x20000000) == 0) goto LAB_000e4e4c;
    extraWordCount = 2;
    *(undefined4 *)(ilReader + 0x60) = 1;
    tokenWord = *tokenWindow;
    goto LAB_000e4e50;
  case 0x87:
    extraTokenCount = 1;
    goto LAB_000e4e74;
  default:
    tokenWord = *(uint *)(ilReader + 0x8c);
LAB_000e4e4c:
    extraWordCount = 1;
LAB_000e4e50:
    if ((int)tokenWord < 0) {
      extraWordCount = extraWordCount + 1;
    }
    extraTokenCount = extraWordCount + -1;
    if ((tokenWord & 0x40000000) != 0) {
      extraTokenCount = extraWordCount;
    }
    if (0 < extraTokenCount) {
LAB_000e4e74:
      loopIndex6 = 0;
      do {
        fetchIndex = *tokenIndexPtr;
        loopIndex6 = loopIndex6 + 1;
        *tokenIndexPtr = fetchIndex + 1;
        ILReader__fetchToken(ilReader,fetchIndex);
      } while (extraTokenCount != loopIndex6);
    }
  }
  destCount = OpcodeRecord__getField8(opcode,*(undefined4 *)(*(int *)(compiler + 0x30c) + 0xc));
  sourceCount = OpcodeRecord__getOperandCount(opcode,*(undefined4 *)(*(int *)(compiler + 0x30c) + 0xc));
  trailingTokenCount = OpcodeRecord__getFieldC(opcode,*(undefined4 *)(*(int *)(compiler + 0x30c) + 0xc));
  *(undefined4 *)(ilReader + 0x5c) = trailingTokenCount;
  destReplicaCount = OpcodeRecord__getOperandByteB(opcode,0,*(undefined4 *)(*(int *)(compiler + 0x30c) + 0xc));
  operandStartIndex = *tokenIndexPtr;
  tokenIndex = operandStartIndex;
  if (destCount < 1) goto LAB_000e50f4;
  **(int **)(ilReader + 100) = operandStartIndex * 4 + ilReader + 0x8c;
  tokenIndex = *tokenIndexPtr;
  *tokenIndexPtr = tokenIndex + 1;
  ILReader__fetchToken(ilReader,tokenIndex);
  tokenIndex = *tokenIndexPtr;
  destTokenSlot = ilReader + tokenIndex * 4 + 0x7c;
  destFlags = *(uint *)(destTokenSlot + 0xc);
  if ((destFlags & 0x400000) != 0) {
    *tokenIndexPtr = tokenIndex + 1;
    ILReader__fetchToken(ilReader,tokenIndex);
    tokenIndex = *tokenIndexPtr;
    destFlags = *(uint *)(destTokenSlot + 0xc);
  }
  if ((destFlags & 0x23f0000) == 0x21e0000) {
    *tokenIndexPtr = tokenIndex + 1;
    ILReader__fetchToken(ilReader,tokenIndex);
    destFlags = *(uint *)(destTokenSlot + 0xc);
    tokenIndex = *tokenIndexPtr;
  }
  if ((destFlags & 0x1800000) == 0x800000) {
LAB_000e5044:
    *tokenIndexPtr = tokenIndex + 1;
    ILReader__fetchToken(ilReader,tokenIndex);
    tokenIndex = *tokenIndexPtr;
  }
  else if ((destFlags & 0x1800000) == 0x1000000) {
    *tokenIndexPtr = tokenIndex + 1;
    ILReader__fetchToken(ilReader,tokenIndex);
    tokenIndex = *tokenIndexPtr;
    destModifierSlot = ilReader + tokenIndex * 4 + 0x7c;
    destModifierFlags = *(uint *)(destModifierSlot + 0xc);
    if ((destModifierFlags & 0x400000) != 0) {
      *tokenIndexPtr = tokenIndex + 1;
      ILReader__fetchToken(ilReader,tokenIndex);
      tokenIndex = *tokenIndexPtr;
      destModifierFlags = *(uint *)(destModifierSlot + 0xc);
    }
    if (((destModifierFlags & 0x1800000) == 0) && (repeatIndex = 0, (destModifierFlags & 0x2000000) != 0)) {
      while( true ) {
        *tokenIndexPtr = tokenIndex + 1;
        ILReader__fetchToken(ilReader,tokenIndex);
        destModifierFlags = *(uint *)(destModifierSlot + 0xc);
        repeatIndex = repeatIndex + 1;
        if ((destModifierFlags >> 0x19 & 1) <= repeatIndex) break;
        tokenIndex = *tokenIndexPtr;
      }
      tokenIndex = *tokenIndexPtr;
    }
    else {
      destModifierFlags = *(uint *)(destModifierSlot + 0xc);
    }
    if ((destModifierFlags & 0x4000000) != 0) goto LAB_000e5044;
  }
  if ((*(uint *)(destTokenSlot + 0xc) & 0x4000000) != 0) {
    *tokenIndexPtr = tokenIndex + 1;
    ILReader__fetchToken(ilReader,tokenIndex);
    tokenIndex = *tokenIndexPtr;
  }
  if (0 < destReplicaCount) {
    loopIndex2 = 0;
    destRecordOffset = 0x14;
    destCopyOffset = 100;
    do {
      *(int *)(destRecordOffset + *(int *)(ilReader + 100)) = destCopyOffset + *(int *)(ilReader + 0x68);
      _memcpy(destCopyOffset + *(int *)(ilReader + 0x68),**(undefined4 **)(ilReader + 100),
              (tokenIndex - operandStartIndex) * 4);
      destCopyOffset = destCopyOffset + 100;
      replicaNumber = (short)loopIndex2;
      loopIndex2 = loopIndex2 + 1;
      destRecord = (int *)(destRecordOffset + *(int *)(ilReader + 100));
      destRecordOffset = destRecordOffset + 0x14;
      *(short *)(*destRecord + 2) = replicaNumber + *(short *)(destTokenSlot + 0xe) + 1;
    } while (destReplicaCount != loopIndex2);
    tokenIndex = *tokenIndexPtr;
  }
LAB_000e50f4:
  if (0 < sourceCount) {
    loopIndex = 0;
    sourceSlotOffset = 0x14;
    sourceStartIndex = tokenIndex;
    do {
      sourceByteIndex = loopIndex * 4;
      sourceReplicaCount = OpcodeRecord__getOperandByteB(opcode,destCount + loopIndex,*(undefined4 *)(*(int *)(compiler + 0x30c) + 0xc));
      *(int *)(*(int *)(ilReader + 0x6c) + sourceByteIndex) = sourceStartIndex * 4 + ilReader + 0x8c;
      tokenIndex = *tokenIndexPtr;
      *tokenIndexPtr = tokenIndex + 1;
      ILReader__fetchToken(ilReader,tokenIndex);
      extraWordFlag = **(uint **)(sourceByteIndex + *(int *)(ilReader + 0x6c)) >> 0x19 & 1;
      if (extraWordFlag == 0xffffffff) {
        tokenIndex = *tokenIndexPtr;
      }
      else {
        tokenIndex = *tokenIndexPtr;
        loopIndex3 = 0;
LAB_000e5190:
        sourceTokenSlot = ilReader + tokenIndex * 4 + 0x7c;
        sourceFlags = *(uint *)(sourceTokenSlot + 0xc);
        if ((sourceFlags & 0x400000) != 0) {
          *tokenIndexPtr = tokenIndex + 1;
          ILReader__fetchToken(ilReader,tokenIndex);
          sourceFlags = *(uint *)(sourceTokenSlot + 0xc);
          tokenIndex = *tokenIndexPtr;
        }
        sourceFlags = sourceFlags & 0x1800000;
        if (sourceFlags != 0) {
          if (sourceFlags == 0x800000) {
LAB_000e523c:
            *tokenIndexPtr = tokenIndex + 1;
            ILReader__fetchToken(ilReader,tokenIndex);
            tokenIndex = *tokenIndexPtr;
          }
          else if (sourceFlags == 0x1000000) {
            *tokenIndexPtr = tokenIndex + 1;
            ILReader__fetchToken(ilReader,tokenIndex);
            tokenIndex = *tokenIndexPtr;
            sourceModifierSlot = ilReader + tokenIndex * 4 + 0x7c;
            sourceModifierFlags = *(uint *)(sourceModifierSlot + 0xc);
            if ((sourceModifierFlags & 0x400000) != 0) {
              *tokenIndexPtr = tokenIndex + 1;
              ILReader__fetchToken(ilReader,tokenIndex);
              sourceModifierFlags = *(uint *)(sourceModifierSlot + 0xc);
              tokenIndex = *tokenIndexPtr;
            }
            if ((sourceModifierFlags & 0x4000000) != 0) goto LAB_000e523c;
          }
        }
        if ((*(uint *)(sourceTokenSlot + 0xc) & 0x4000000) != 0) {
          *tokenIndexPtr = tokenIndex + 1;
          ILReader__fetchToken(ilReader,tokenIndex);
          tokenIndex = *tokenIndexPtr;
        }
        loopIndex3 = loopIndex3 + 1;
        if (loopIndex3 != extraWordFlag + 1) {
          if (0 < loopIndex3) {
            *tokenIndexPtr = tokenIndex + 1;
            ILReader__fetchToken(ilReader,tokenIndex);
            tokenIndex = *tokenIndexPtr;
          }
          goto LAB_000e5190;
        }
      }
      if (0 < sourceReplicaCount) {
        sourceCopyOffset = sourceSlotOffset * 5;
        loopIndex4 = 0;
        sourceReplicaOffset = sourceSlotOffset;
        do {
          *(int *)(*(int *)(ilReader + 0x6c) + sourceReplicaOffset) = sourceCopyOffset + *(int *)(ilReader + 0x70);
          sourceCopyAddress = sourceCopyOffset + *(int *)(ilReader + 0x70);
          sourceCopyOffset = sourceCopyOffset + 100;
          _memcpy(sourceCopyAddress,*(undefined4 *)(sourceByteIndex + *(int *)(ilReader + 0x6c)),(tokenIndex - sourceStartIndex) * 4);
          sourceRecord = (int *)(*(int *)(ilReader + 0x6c) + sourceReplicaOffset);
          sourceReplicaOffset = sourceReplicaOffset + 0x14;
          replicaNumber = (short)loopIndex4;
          loopIndex4 = loopIndex4 + 1;
          *(short *)(*sourceRecord + 2) =
               replicaNumber + *(short *)(*(int *)(sourceByteIndex + *(int *)(ilReader + 0x6c)) + 2) + 1;
        } while (sourceReplicaCount != loopIndex4);
        tokenIndex = *tokenIndexPtr;
      }
      loopIndex = loopIndex + 1;
      sourceSlotOffset = sourceSlotOffset + 4;
      sourceStartIndex = tokenIndex;
    } while (sourceCount != loopIndex);
  }
  *(int *)(ilReader + 0x58) = tokenIndex;
  if (0 < *(int *)(ilReader + 0x5c)) {
    loopIndex5 = 0;
    do {
      tailIndex = *tokenIndexPtr;
      *tokenIndexPtr = tailIndex + 1;
      ILReader__fetchToken(ilReader,tailIndex);
      loopIndex5 = loopIndex5 + 1;
    } while (loopIndex5 < *(int *)(ilReader + 0x5c));
  }
  return 1;
}

/* ILReader__beginRewrittenReplay_e5384 @ 0xe5384 (248 bytes) */
int ILReader__beginRewrittenReplay_e5384(ilReader, opcodeToken, tokenIndex, replacementToken, argR7, unusedR8)
  int ilReader;
  undefined4 opcodeToken;
  int tokenIndex;
  undefined4 replacementToken;
  undefined4 argR7;
  undefined4 unusedR8;
{
  undefined4 windowToken;
  int loopIndex;
  int tokenSlot;
  undefined4 *firstReplaySlot;
  undefined4 savedReadState;
  undefined4 savedSkipMode;
  undefined4 *windowCursor;
  uint replayStackCount;
  uint *replayStack;
  
  tokenSlot = tokenIndex * 4 + ilReader;
  savedSkipMode = *(undefined4 *)(ilReader + 0x80);
  savedReadState = *(undefined4 *)(ilReader + 0x7c);
  *(undefined2 *)(ilReader + 0x8e) = (*(unsigned short *)((unsigned char *)&(opcodeToken) + 2));
  *(int *)(tokenSlot + 0xa4) = *(int *)(ilReader + 0x74) - *(int *)(ilReader + 0x2c) >> 2;
  *(undefined4 *)(tokenSlot + 0x8c) = replacementToken;
  *(undefined4 *)(tokenSlot + 0x90) = argR7;
  *(undefined4 *)(tokenSlot + 0x94) = 0x29;
  *(undefined4 *)(tokenSlot + 0x98) = 0xffffffff;
  *(undefined4 *)(tokenSlot + 0x9c) = savedSkipMode;
  *(undefined4 *)(tokenSlot + 0xa0) = savedReadState;
  if (-1 < tokenIndex + 6) {
    loopIndex = 0;
    windowCursor = (undefined4 *)((tokenIndex + 6) * 4 + ilReader + 0x8c);
    do {
      replayStack = *(uint **)(ilReader + 0x88);
      windowToken = *windowCursor;
      replayStackCount = replayStack[1];
      if (replayStackCount < *replayStack) {
        _memset(replayStackCount * 4 + replayStack[2],0,4);
        firstReplaySlot = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
        replayStack[1] = replayStackCount + 1;
      }
      else {
        firstReplaySlot = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
      }
      loopIndex = loopIndex + 1;
      *firstReplaySlot = windowToken;
      windowCursor = windowCursor + -1;
    } while (tokenIndex + 7 != loopIndex);
  }
  *(undefined4 *)(ilReader + 0x7c) = 1;
  return;
}

/* ILReader__beginRewrittenReplay_e547c @ 0xe547c (244 bytes) */
int ILReader__beginRewrittenReplay_e547c(ilReader, opcodeToken, tokenIndex, replacementToken, argR7, unusedR8)
  int ilReader;
  undefined4 opcodeToken;
  int tokenIndex;
  undefined4 replacementToken;
  undefined4 argR7;
  undefined4 unusedR8;
{
  undefined4 windowToken;
  int loopIndex;
  int tokenSlot;
  undefined4 *firstReplaySlot;
  undefined4 savedReadState;
  undefined4 savedSkipMode;
  undefined4 *windowCursor;
  uint replayStackCount;
  uint *replayStack;
  
  tokenSlot = tokenIndex * 4 + ilReader;
  savedSkipMode = *(undefined4 *)(ilReader + 0x80);
  savedReadState = *(undefined4 *)(ilReader + 0x7c);
  *(undefined2 *)(ilReader + 0x8e) = (*(unsigned short *)((unsigned char *)&(opcodeToken) + 2));
  *(int *)(tokenSlot + 0xa0) = *(int *)(ilReader + 0x74) - *(int *)(ilReader + 0x2c) >> 2;
  *(undefined4 *)(tokenSlot + 0x8c) = replacementToken;
  *(undefined4 *)(tokenSlot + 0x90) = 0x29;
  *(undefined4 *)(tokenSlot + 0x94) = 0xffffffff;
  *(undefined4 *)(tokenSlot + 0x98) = savedSkipMode;
  *(undefined4 *)(tokenSlot + 0x9c) = savedReadState;
  if (-1 < tokenIndex + 5) {
    loopIndex = 0;
    windowCursor = (undefined4 *)((tokenIndex + 5) * 4 + ilReader + 0x8c);
    do {
      replayStack = *(uint **)(ilReader + 0x88);
      windowToken = *windowCursor;
      replayStackCount = replayStack[1];
      if (replayStackCount < *replayStack) {
        _memset(replayStackCount * 4 + replayStack[2],0,4);
        firstReplaySlot = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
        replayStack[1] = replayStackCount + 1;
      }
      else {
        firstReplaySlot = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
      }
      loopIndex = loopIndex + 1;
      *firstReplaySlot = windowToken;
      windowCursor = windowCursor + -1;
    } while (tokenIndex + 6 != loopIndex);
  }
  *(undefined4 *)(ilReader + 0x7c) = 1;
  return;
}

/* ILReader__ctor_e5570 @ 0xe5570 (992 bytes) */
int ILReader__ctor_e5570(ilReader, tokenStream, compiler)
  int *ilReader;
  int tokenStream;
  int compiler;
{
  undefined4 *intConstSentinel;
  undefined4 *floatConstSentinel;
  undefined4 *boolConstSentinel;
  int tokenCursor;
  int intConstList;
  int floatConstList;
  int allocation2;
  undefined4 arenaAt378;
  undefined4 *vectorAlloc;
  undefined4 *replayStackSlot;
  undefined4 *firstReplaySlot;
  int boolConstList;
  int tokenStart;
  undefined4 allocation;
  uint replayStackCount;
  uint *replayStack;
  
  ilReader[0x1d] = tokenStream;
  ilReader[9] = tokenStream;
  ilReader[10] = tokenStream;
  *ilReader = compiler;
  ilReader[0xc] = 0;
  ilReader[0xd] = 0;
  ilReader[0xe] = 0;
  ilReader[0x12] = 0;
  ilReader[0x13] = 0;
  ilReader[0x14] = 0;
  ilReader[0x1f] = 0;
  ilReader[0x20] = 0;
  ilReader[0x21] = 0;
  arenaAt378 = *(undefined4 *)(compiler + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaAt378;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  ilReader[0x22] = (int)(vectorAlloc + 1);
  replayStackCount = vectorAlloc[2];
  if (replayStackCount < (uint)vectorAlloc[1]) {
    _memset(replayStackCount * 4 + vectorAlloc[3],0,4);
    firstReplaySlot = (undefined4 *)(replayStackCount * 4 + vectorAlloc[3]);
    vectorAlloc[2] = replayStackCount + 1;
  }
  else {
    firstReplaySlot = (undefined4 *)Vector__elementRefGrow(vectorAlloc + 1,replayStackCount);
  }
  *firstReplaySlot = 0;
  replayStack = (uint *)ilReader[0x22];
  replayStackCount = replayStack[1];
  if (replayStackCount < *replayStack) {
    _memset(replayStackCount * 4 + replayStack[2],0,4);
    replayStackSlot = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
    replayStack[1] = replayStackCount + 1;
  }
  else {
    replayStackSlot = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
  }
  *replayStackSlot = 2;
  replayStack = (uint *)ilReader[0x22];
  replayStackCount = replayStack[1];
  if (replayStackCount < *replayStack) {
    _memset(replayStackCount * 4 + replayStack[2],0,4);
    replayStackSlot = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
    replayStack[1] = replayStackCount + 1;
  }
  else {
    replayStackSlot = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
  }
  *replayStackSlot = 0;
  replayStack = (uint *)ilReader[0x22];
  replayStackCount = replayStack[1];
  if (replayStackCount < *replayStack) {
    _memset(replayStackCount * 4 + replayStack[2],0,4);
    replayStackSlot = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
    replayStack[1] = replayStackCount + 1;
  }
  else {
    replayStackSlot = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
  }
  *replayStackSlot = 0xffffffff;
  allocation2 = Arena__alloc(*(undefined4 *)(*ilReader + 0x378),0x50);
  ilReader[0x19] = allocation2;
  allocation2 = Arena__alloc(*(undefined4 *)(*ilReader + 0x378),0x50);
  ilReader[0x1b] = allocation2;
  allocation2 = Arena__alloc(*(undefined4 *)(*ilReader + 0x378),400);
  ilReader[0x1a] = allocation2;
  allocation2 = Arena__alloc(*(undefined4 *)(*ilReader + 0x378),400);
  ilReader[0x1c] = allocation2;
  arenaAt378 = *(undefined4 *)(*ilReader + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  ilReader[0xf] = (int)(vectorAlloc + 1);
  arenaAt378 = *(undefined4 *)(*ilReader + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  ilReader[0x11] = (int)(vectorAlloc + 1);
  arenaAt378 = *(undefined4 *)(*ilReader + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaAt378;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  ilReader[0x10] = (int)(vectorAlloc + 1);
  ilReader[0x15] = 0;
  boolConstSentinel = (undefined4 *)Arena__alloc(*(undefined4 *)(*ilReader + 0x378),0xc);
  ilReader[3] = (int)boolConstSentinel;
  *boolConstSentinel = 0xffffffff;
  *(undefined4 *)(ilReader[3] + 4) = 0;
  *(undefined4 *)(ilReader[3] + 8) = 0;
  boolConstList = ilReader[3];
  ilReader[4] = boolConstList;
  *(int *)(boolConstList + 8) = boolConstList;
  floatConstSentinel = (undefined4 *)Arena__alloc(*(undefined4 *)(*ilReader + 0x378),0x18);
  ilReader[7] = (int)floatConstSentinel;
  *floatConstSentinel = 0xffffffff;
  *(undefined4 *)(ilReader[7] + 4) = 0;
  *(undefined4 *)(ilReader[7] + 8) = 0;
  *(undefined4 *)(ilReader[7] + 0xc) = 0;
  *(undefined4 *)(ilReader[7] + 0x10) = 0;
  *(undefined4 *)(ilReader[7] + 0x14) = 0;
  floatConstList = ilReader[7];
  ilReader[8] = floatConstList;
  *(int *)(floatConstList + 0x14) = floatConstList;
  intConstSentinel = (undefined4 *)Arena__alloc(*(undefined4 *)(*ilReader + 0x378),0x18);
  ilReader[5] = (int)intConstSentinel;
  *intConstSentinel = 0xffffffff;
  *(undefined4 *)(ilReader[5] + 4) = 0;
  *(undefined4 *)(ilReader[5] + 8) = 0;
  *(undefined4 *)(ilReader[5] + 0xc) = 0;
  *(undefined4 *)(ilReader[5] + 0x10) = 0;
  *(undefined4 *)(ilReader[5] + 0x14) = 0;
  intConstList = ilReader[5];
  ilReader[6] = intConstList;
  *(int *)(intConstList + 0x14) = intConstList;
  tokenCursor = ilReader[9];
  ilReader[1] = tokenCursor;
  if (tokenCursor == 0) {
    tokenCursor = 0;
  }
  else {
    tokenCursor = tokenCursor + 4;
    ilReader[9] = tokenCursor;
  }
  ilReader[2] = tokenCursor;
  tokenStart = 0;
  if (tokenCursor != 0) {
    FUN_0019ee74(tokenCursor,*ilReader);
    tokenStart = ilReader[9] + 4;
    ilReader[9] = tokenStart;
  }
  ilReader[0x1d] = tokenStart;
  ilReader[0xb] = tokenStart;
  return;
}

/* ILReader__ctor_e59f0 @ 0xe59f0 (992 bytes) */
int ILReader__ctor_e59f0(ilReader, tokenStream, compiler)
  int *ilReader;
  int tokenStream;
  int compiler;
{
  undefined4 *intConstSentinel;
  undefined4 *floatConstSentinel;
  undefined4 *boolConstSentinel;
  int tokenCursor;
  int intConstList;
  int floatConstList;
  int allocation2;
  undefined4 arenaAt378;
  undefined4 *vectorAlloc;
  undefined4 *replayStackSlot;
  undefined4 *firstReplaySlot;
  int boolConstList;
  int tokenStart;
  undefined4 allocation;
  uint replayStackCount;
  uint *replayStack;
  
  ilReader[0x1d] = tokenStream;
  ilReader[9] = tokenStream;
  ilReader[10] = tokenStream;
  *ilReader = compiler;
  ilReader[0xc] = 0;
  ilReader[0xd] = 0;
  ilReader[0xe] = 0;
  ilReader[0x12] = 0;
  ilReader[0x13] = 0;
  ilReader[0x14] = 0;
  ilReader[0x1f] = 0;
  ilReader[0x20] = 0;
  ilReader[0x21] = 0;
  arenaAt378 = *(undefined4 *)(compiler + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaAt378;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  ilReader[0x22] = (int)(vectorAlloc + 1);
  replayStackCount = vectorAlloc[2];
  if (replayStackCount < (uint)vectorAlloc[1]) {
    _memset(replayStackCount * 4 + vectorAlloc[3],0,4);
    firstReplaySlot = (undefined4 *)(replayStackCount * 4 + vectorAlloc[3]);
    vectorAlloc[2] = replayStackCount + 1;
  }
  else {
    firstReplaySlot = (undefined4 *)Vector__elementRefGrow(vectorAlloc + 1,replayStackCount);
  }
  *firstReplaySlot = 0;
  replayStack = (uint *)ilReader[0x22];
  replayStackCount = replayStack[1];
  if (replayStackCount < *replayStack) {
    _memset(replayStackCount * 4 + replayStack[2],0,4);
    replayStackSlot = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
    replayStack[1] = replayStackCount + 1;
  }
  else {
    replayStackSlot = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
  }
  *replayStackSlot = 2;
  replayStack = (uint *)ilReader[0x22];
  replayStackCount = replayStack[1];
  if (replayStackCount < *replayStack) {
    _memset(replayStackCount * 4 + replayStack[2],0,4);
    replayStackSlot = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
    replayStack[1] = replayStackCount + 1;
  }
  else {
    replayStackSlot = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
  }
  *replayStackSlot = 0;
  replayStack = (uint *)ilReader[0x22];
  replayStackCount = replayStack[1];
  if (replayStackCount < *replayStack) {
    _memset(replayStackCount * 4 + replayStack[2],0,4);
    replayStackSlot = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
    replayStack[1] = replayStackCount + 1;
  }
  else {
    replayStackSlot = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
  }
  *replayStackSlot = 0xffffffff;
  allocation2 = Arena__alloc(*(undefined4 *)(*ilReader + 0x378),0x50);
  ilReader[0x19] = allocation2;
  allocation2 = Arena__alloc(*(undefined4 *)(*ilReader + 0x378),0x50);
  ilReader[0x1b] = allocation2;
  allocation2 = Arena__alloc(*(undefined4 *)(*ilReader + 0x378),400);
  ilReader[0x1a] = allocation2;
  allocation2 = Arena__alloc(*(undefined4 *)(*ilReader + 0x378),400);
  ilReader[0x1c] = allocation2;
  arenaAt378 = *(undefined4 *)(*ilReader + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  ilReader[0xf] = (int)(vectorAlloc + 1);
  arenaAt378 = *(undefined4 *)(*ilReader + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  ilReader[0x11] = (int)(vectorAlloc + 1);
  arenaAt378 = *(undefined4 *)(*ilReader + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaAt378;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  ilReader[0x10] = (int)(vectorAlloc + 1);
  ilReader[0x15] = 0;
  boolConstSentinel = (undefined4 *)Arena__alloc(*(undefined4 *)(*ilReader + 0x378),0xc);
  ilReader[3] = (int)boolConstSentinel;
  *boolConstSentinel = 0xffffffff;
  *(undefined4 *)(ilReader[3] + 4) = 0;
  *(undefined4 *)(ilReader[3] + 8) = 0;
  boolConstList = ilReader[3];
  ilReader[4] = boolConstList;
  *(int *)(boolConstList + 8) = boolConstList;
  floatConstSentinel = (undefined4 *)Arena__alloc(*(undefined4 *)(*ilReader + 0x378),0x18);
  ilReader[7] = (int)floatConstSentinel;
  *floatConstSentinel = 0xffffffff;
  *(undefined4 *)(ilReader[7] + 4) = 0;
  *(undefined4 *)(ilReader[7] + 8) = 0;
  *(undefined4 *)(ilReader[7] + 0xc) = 0;
  *(undefined4 *)(ilReader[7] + 0x10) = 0;
  *(undefined4 *)(ilReader[7] + 0x14) = 0;
  floatConstList = ilReader[7];
  ilReader[8] = floatConstList;
  *(int *)(floatConstList + 0x14) = floatConstList;
  intConstSentinel = (undefined4 *)Arena__alloc(*(undefined4 *)(*ilReader + 0x378),0x18);
  ilReader[5] = (int)intConstSentinel;
  *intConstSentinel = 0xffffffff;
  *(undefined4 *)(ilReader[5] + 4) = 0;
  *(undefined4 *)(ilReader[5] + 8) = 0;
  *(undefined4 *)(ilReader[5] + 0xc) = 0;
  *(undefined4 *)(ilReader[5] + 0x10) = 0;
  *(undefined4 *)(ilReader[5] + 0x14) = 0;
  intConstList = ilReader[5];
  ilReader[6] = intConstList;
  *(int *)(intConstList + 0x14) = intConstList;
  tokenCursor = ilReader[9];
  ilReader[1] = tokenCursor;
  if (tokenCursor == 0) {
    tokenCursor = 0;
  }
  else {
    tokenCursor = tokenCursor + 4;
    ilReader[9] = tokenCursor;
  }
  ilReader[2] = tokenCursor;
  tokenStart = 0;
  if (tokenCursor != 0) {
    FUN_0019ee74(tokenCursor,*ilReader);
    tokenStart = ilReader[9] + 4;
    ilReader[9] = tokenStart;
  }
  ilReader[0x1d] = tokenStart;
  ilReader[0xb] = tokenStart;
  return;
}

/* ILReader__nextInstruction @ 0xe5e70 (5640 bytes) */
int ILReader__nextInstruction(ilReader)
  int *ilReader;
{
  uint ifResultStackSizeB;
  uint scopeStackSizeB;
  uint destRegisterFile;
  undefined4 closedScope;
  uint tokenWord0Snapshot;
  uint ifResultStackSize;
  uint scopeStackCount;
  uint tokenWord1Snapshot;
  uint ifResultStackCount;
  uint loopCounter;
  uint savedStateStackCount;
  uint topIndex;
  uint replayStackCount;
  ushort skipCount;
  uint *scopeStack;
  uint *ifResultStack;
  uint *savedStateStack;
  undefined4 *newScope;
  undefined4 *ifResultStackSlotEntry;
  undefined4 *replayStackSlotEntry;
  int *savedStateStackTop;
  int *scopeStackTop;
  int *ifResultStackTop;
  int *savedStateStackSlot;
  int *replayStackSlot;
  int *scope;
  int restoredValue;
  int streamBaseSnapshotB;
  int scopeStackVec;
  int tokenWord2Snapshot;
  int constantRegister;
  int savedFlagSnapshotB;
  int extraOperandB;
  int streamBaseSnapshot;
  int poppedState;
  int savedStateStackVec;
  int labelValue;
  int firstDestToken;
  int loopNestingSnapshot;
  int savedFlagSnapshot;
  int skipModeSnapshot;
  int readStateSnapshot;
  int cursorSnapshot;
  int tokenReadOk;
  int writeCursor;
  int segmentStart;
  int preprocessConstantIfsEnabled2;
  int preprocessConstantIfsEnabled;
  short operandRegister;
  ushort opcode16;
  uint opcode;
  int iVar4;
  uint secondOperandToken;
  uint scopeStackSize;
  int replayStackVec;
  undefined4 dispatchOpcode;
  undefined4 *scopeStackTopEntry;
  undefined4 *scopeStackSlotEntry;
  int argR7;
  undefined4 staleArgR8;
  uint firstRegisterFile;
  uint waitLabel;
  int ifSkipDepth;
  int replaySkipDepth;
  uint *replayStack;
  int *replayStackTop;
  int extraOperandA;
  bool comparisonResult;
  int tokenCount;
  uint leftConstant;
  float rightConstant [10];
  
  ifSkipDepth = 0;
  waitLabel = 0;
  replaySkipDepth = 0;
LAB_000e5e9c:
  while( true ) {
    tokenCount = 0;
    if (ilReader[0x1f] == 3) {
      segmentStart = ilReader[0xc];
      ilReader[9] = segmentStart;
      ilReader[1] = segmentStart;
      if (segmentStart != 0) {
        ilReader[9] = segmentStart + 4;
      }
      writeCursor = ilReader[9];
      ilReader[2] = writeCursor;
      if (writeCursor != 0) {
        writeCursor = writeCursor + 4;
        ilReader[9] = writeCursor;
      }
      ilReader[0x1d] = writeCursor;
      ilReader[0x1f] = 0;
      ilReader[0xb] = writeCursor;
    }
    tokenReadOk = ((int (*)())ILReader__decodeInstruction)(ilReader,&tokenCount,*ilReader);
    if (tokenReadOk == 0) {
      return 0;
    }
    iVar4 = ilReader[0x20];
    if (iVar4 != 3) break;
    if (replaySkipDepth == 0) {
      opcode16 = *(ushort *)((int)ilReader + 0x8e);
      opcode = (uint)opcode16;
      if ((opcode16 < 0xbf) && (opcode16 == 0x29)) {
        ilReader[0x20] = 0;
        Vector__removeAt(ilReader[0xf],*(int *)(ilReader[0xf] + 4) + -1);
        goto LAB_000e5f48;
      }
    }
    else {
LAB_000e5f48:
      opcode = (uint)*(ushort *)((int)ilReader + 0x8e);
    }
    if (opcode < 0xbf) {
      if (((opcode - 0x34 < 2) || (opcode == 0x70)) || (opcode == 0x6f)) {
LAB_000e6000:
        replaySkipDepth = replaySkipDepth + 1;
      }
      else {
joined_r0x000e600c:
        if (opcode == 0x29) {
          replaySkipDepth = replaySkipDepth + -1;
        }
      }
    }
  }
  if (iVar4 == 2) {
    if (replaySkipDepth == 0) {
      opcode16 = *(ushort *)((int)ilReader + 0x8e);
      opcode = (uint)opcode16;
      if ((opcode16 < 0xbf) && ((opcode16 == 0x27 || (opcode16 == 0x29)))) {
        ilReader[0x20] = 0;
        if ((*(ushort *)((int)ilReader + 0x8e) < 0xbf) && (*(ushort *)((int)ilReader + 0x8e) == 0x29))
        {
          Vector__removeAt(ilReader[0xf],*(int *)(ilReader[0xf] + 4) + -1);
        }
        goto LAB_000e5e9c;
      }
    }
    else {
      opcode = (uint)*(ushort *)((int)ilReader + 0x8e);
    }
    if ((opcode < 0xbf) && (((opcode - 0x34 < 2 || (opcode == 0x70)) || (opcode == 0x6f))))
    goto LAB_000e6000;
    if (opcode < 0xbf) goto joined_r0x000e600c;
    goto LAB_000e5e9c;
  }
  if (iVar4 == 1) {
    if (((*(ushort *)((int)ilReader + 0x8e) < 0xbf) && (*(ushort *)((int)ilReader + 0x8e) == 0x32)) &&
       (waitLabel == *(ushort *)((int)ilReader + 0x92))) {
LAB_000e6ac4:
      ilReader[0x20] = 0;
    }
    goto LAB_000e5e9c;
  }
  ilReader[9] = (int)(ilReader + 0x23);
  if (iVar4 == 4) {
    iVar4 = ILReader__currentOpcode(ilReader);
    if ((iVar4 != 0x6d) && (iVar4 != 0x69)) goto LAB_000e5e9c;
    replayStackVec = ilReader[0x22];
    replayStackTop = (int *)0x0;
    replayStackCount = *(uint *)(replayStackVec + 4);
    if (replayStackCount - 1 < replayStackCount) {
      replayStackTop = (int *)((replayStackCount - 1) * 4 + *(int *)(replayStackVec + 8));
    }
    iVar4 = *replayStackTop;
    Vector__removeAt(replayStackVec,replayStackCount - 1);
    ilReader[0x20] = iVar4;
  }
  if (iVar4 == 5) {
    iVar4 = ILReader__currentOpcode(ilReader);
    if (iVar4 != 0x6d) goto LAB_000e5e9c;
    iVar4 = ilReader[0x22];
    replayStackTop = (int *)0x0;
    replayStackCount = *(uint *)(iVar4 + 4);
    if (replayStackCount - 1 < replayStackCount) {
      replayStackTop = (int *)((replayStackCount - 1) * 4 + *(int *)(iVar4 + 8));
    }
    poppedState = *replayStackTop;
    Vector__removeAt(iVar4,replayStackCount - 1);
    ilReader[0x20] = poppedState;
  }
  if (ilReader[0xe] != 0) {
    opcode = (uint)*(ushort *)((int)ilReader + 0x8e);
    if (0xbe < opcode) goto LAB_000e5e9c;
    if (((opcode != 0x28) && (opcode != 0x2b)) &&
       ((opcode != 0x29 && (((opcode != 0x2a && (opcode != 0x27)) && (opcode != 0x53)))))) {
      if (((opcode - 0x34 < 2) || (opcode == 0x3e)) ||
         ((opcode == 0x32 || ((opcode == 0x70 || (opcode == 0x6f)))))) {
        ifSkipDepth = ifSkipDepth + 1;
      }
      goto LAB_000e5e9c;
    }
    ifSkipDepth = ifSkipDepth + -1;
    if (0 < ifSkipDepth) goto LAB_000e5e9c;
    ilReader[0xe] = 0;
  }
  dispatchOpcode = ILReader__currentOpcode(ilReader);
  switch(dispatchOpcode) {
  case 6:
    scopeStackTopEntry = (undefined4 *)0x0;
    scopeStackSize = *(uint *)(ilReader[0x10] + 4);
    topIndex = scopeStackSize - 1;
    if (topIndex < scopeStackSize) {
      scopeStackTopEntry = (undefined4 *)(topIndex * 4 + *(int *)(ilReader[0x10] + 8));
    }
    scope = (int *)*scopeStackTopEntry;
    if ((*scope != 0x3e) && (*scope != 0x71)) {
      if (scope[5] == 0) {
        if (scope[3] == 0) {
          scope[1] = 0;
        }
        else {
          ilReader[0x23] = 0xe3;
        }
        goto switchD_000e61ac_caseD_a;
      }
      replayStack = (uint *)ilReader[0x22];
      iVar4 = ilReader[0x20];
      replayStackCount = replayStack[1];
      if (replayStackCount < *replayStack) {
        _memset(replayStackCount * 4 + replayStack[2],0,4);
        replayStackSlot = (int *)(replayStackCount * 4 + replayStack[2]);
        replayStack[1] = replayStackCount + 1;
      }
      else {
        replayStackSlot = (int *)Vector__elementRefGrow(replayStack,replayStackCount);
      }
      *replayStackSlot = iVar4;
      ilReader[0x20] = 5;
      break;
    }
  case 0x10:
    ilReader[0xe] = 1;
    goto switchD_000e61ac_caseD_a;
  case 7:
    leftConstant = 6;
    ((int (*)())ILReader__beginRewrittenReplay_e547c)(ilReader,0x34,tokenCount,6,argR7,staleArgR8);
    break;
  case 8:
    replayStack = (uint *)ilReader[0x22];
    cursorSnapshot = ilReader[0x1d];
    replayStackCount = replayStack[1];
    streamBaseSnapshot = ilReader[0xb];
    waitLabel = ilReader[0x24];
    if (replayStackCount < *replayStack) {
      _memset(replayStackCount * 4 + replayStack[2],0,4);
      replayStackSlot = (int *)(replayStackCount * 4 + replayStack[2]);
      replayStack[1] = replayStackCount + 1;
    }
    else {
      replayStackSlot = (int *)Vector__elementRefGrow(replayStack,replayStackCount);
    }
    *replayStackSlot = cursorSnapshot - streamBaseSnapshot >> 2;
    replayStack = (uint *)ilReader[0x22];
    readStateSnapshot = ilReader[0x1f];
    replayStackCount = replayStack[1];
    if (replayStackCount < *replayStack) {
      _memset(replayStackCount * 4 + replayStack[2],0,4);
      replayStackSlot = (int *)(replayStackCount * 4 + replayStack[2]);
      replayStack[1] = replayStackCount + 1;
    }
    else {
      replayStackSlot = (int *)Vector__elementRefGrow(replayStack,replayStackCount);
    }
    *replayStackSlot = readStateSnapshot;
    replayStack = (uint *)ilReader[0x22];
    skipModeSnapshot = ilReader[0x20];
    replayStackCount = replayStack[1];
    if (replayStackCount < *replayStack) {
      _memset(replayStackCount * 4 + replayStack[2],0,4);
      replayStackSlot = (int *)(replayStackCount * 4 + replayStack[2]);
      replayStack[1] = replayStackCount + 1;
    }
    else {
      replayStackSlot = (int *)Vector__elementRefGrow(replayStack,replayStackCount);
    }
    *replayStackSlot = skipModeSnapshot;
    replayStack = (uint *)ilReader[0x22];
    replayStackCount = replayStack[1];
    if (replayStackCount < *replayStack) {
      _memset(replayStackCount * 4 + replayStack[2],0,4);
      replayStackSlotEntry = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
      replayStack[1] = replayStackCount + 1;
    }
    else {
      replayStackSlotEntry = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
    }
    *replayStackSlotEntry = 0xffffffff;
    savedStateStack = (uint *)ilReader[0x11];
    savedFlagSnapshot = ilReader[0x14];
    ilReader[0x15] = ilReader[0x15] + 1;
    savedStateStackCount = savedStateStack[1];
    if (savedStateStackCount < *savedStateStack) {
      _memset(savedStateStackCount * 4 + savedStateStack[2],0,4);
      savedStateStackSlot = (int *)(savedStateStackCount * 4 + savedStateStack[2]);
      savedStateStack[1] = savedStateStackCount + 1;
    }
    else {
      savedStateStackSlot = (int *)Vector__elementRefGrow(savedStateStack,savedStateStackCount);
    }
    *savedStateStackSlot = savedFlagSnapshot;
    savedStateStack = (uint *)ilReader[0x11];
    loopNestingSnapshot = ilReader[0x13];
    savedStateStackCount = savedStateStack[1];
    if (savedStateStackCount < *savedStateStack) {
      _memset(savedStateStackCount * 4 + savedStateStack[2],0,4);
      savedStateStackSlot = (int *)(savedStateStackCount * 4 + savedStateStack[2]);
      savedStateStack[1] = savedStateStackCount + 1;
    }
    else {
      savedStateStackSlot = (int *)Vector__elementRefGrow(savedStateStack,savedStateStackCount);
    }
    *savedStateStackSlot = loopNestingSnapshot;
    savedStateStack = (uint *)ilReader[0x11];
    iVar4 = ilReader[0x12];
    savedStateStackCount = savedStateStack[1];
    if (savedStateStackCount < *savedStateStack) {
      _memset(savedStateStackCount * 4 + savedStateStack[2],0,4);
      savedStateStackSlot = (int *)(savedStateStackCount * 4 + savedStateStack[2]);
      savedStateStack[1] = savedStateStackCount + 1;
    }
    else {
      savedStateStackSlot = (int *)Vector__elementRefGrow(savedStateStack,savedStateStackCount);
    }
    *savedStateStackSlot = iVar4;
    ilReader[0x1f] = 0;
    ilReader[0x20] = 1;
    ilReader[0x1d] = ilReader[0xb];
    ilReader[0x13] = 0;
    ilReader[0x12] = 0;
    ilReader[0x14] = 0;
    break;
  case 9:
    leftConstant = 8;
    iVar4 = tokenCount + -1;
    argR7 = ilReader[tokenCount + 0x22];
    tokenCount = iVar4;
    ((int (*)())ILReader__beginRewrittenReplay_e5384)(ilReader,0x35,iVar4,8,argR7,staleArgR8);
    break;
  default:
    goto switchD_000e61ac_caseD_a;
  case 0xf:
    skipCount = *(ushort *)((int)ilReader + 0x92);
    if (skipCount != 0) {
      loopCounter = 0;
      do {
        loopCounter = loopCounter + 1;
        ILReader__fetchToken(ilReader,0);
      } while (skipCount != loopCounter);
    }
    break;
  case 0x1c:
    iVar4 = Compiler__isOptionEnabled(*ilReader,0);
    if (iVar4 == 0) {
      preprocessConstantIfsEnabled = Compiler__isOptionEnabled(*ilReader,1);
      if (preprocessConstantIfsEnabled != 0) {
        constantRegister = (int)(short)**(uint **)ilReader[0x19];
        destRegisterFile = **(uint **)ilReader[0x19] >> 0x10 & 0x3f;
        if (destRegisterFile == 1) {
          ((void (*)())ILReader__appendFloatConst)(ilReader,constantRegister,(double)GH_U2F((unsigned int)(ilReader[0x25])),(double)GH_U2F((unsigned int)(ilReader[0x26])),
                       (double)GH_U2F((unsigned int)(ilReader[0x27])),(double)GH_U2F((unsigned int)(ilReader[0x28])));
        }
        else if (destRegisterFile == 2) {
          ILReader__appendIntConst(ilReader,constantRegister,ilReader[0x25],ilReader[0x26],ilReader[0x27],ilReader[0x28]);
        }
      }
      goto switchD_000e61ac_caseD_a;
    }
    break;
  case 0x1d:
    iVar4 = Compiler__isOptionEnabled(*ilReader,0);
    if (iVar4 == 0) {
      tokenWord2Snapshot = ilReader[0x25];
      firstDestToken = *(int *)ilReader[0x19];
      preprocessConstantIfsEnabled2 = Compiler__isOptionEnabled(*ilReader,1);
      if (preprocessConstantIfsEnabled2 != 0) {
        ILReader__appendBoolConst(ilReader,(uint)*(ushort *)(firstDestToken + 2),(uint)(tokenWord2Snapshot != 0));
      }
      goto switchD_000e61ac_caseD_a;
    }
    break;
  case 0x27:
    ifResultStackTop = (int *)0x0;
    ifResultStackSize = *(uint *)(ilReader[0xf] + 4);
    topIndex = ifResultStackSize - 1;
    if (topIndex < ifResultStackSize) {
      ifResultStackTop = (int *)(topIndex * 4 + *(int *)(ilReader[0xf] + 8));
    }
    if ((*ifResultStackTop == 0) || (*ifResultStackTop != 1)) goto switchD_000e61ac_caseD_a;
    replaySkipDepth = 0;
    ilReader[0x20] = 3;
    break;
  case 0x29:
    iVar4 = ilReader[0xf];
    ifResultStackTop = (int *)0x0;
    ifResultStackCount = *(uint *)(iVar4 + 4);
    if (ifResultStackCount - 1 < ifResultStackCount) {
      ifResultStackTop = (int *)((ifResultStackCount - 1) * 4 + *(int *)(iVar4 + 8));
    }
    poppedState = *ifResultStackTop;
    Vector__removeAt(iVar4,ifResultStackCount - 1);
    if (poppedState != 0) goto LAB_000e6ac4;
    ilReader[0x12] = ilReader[0x12] + -1;
    scopeStackSizeB = *(uint *)(ilReader[0x10] + 4);
    if (0 < (int)scopeStackSizeB) {
      scopeStackTop = (int *)0x0;
      if (scopeStackSizeB - 1 < scopeStackSizeB) {
        scopeStackTop = (int *)((scopeStackSizeB - 1) * 4 + *(int *)(ilReader[0x10] + 8));
      }
      *(int *)(*scopeStackTop + 0xc) = *(int *)(*scopeStackTop + 0xc) + -1;
    }
    goto switchD_000e61ac_caseD_a;
  case 0x2a:
    scopeStackVec = ilReader[0x10];
    scopeStackTopEntry = (undefined4 *)0x0;
    scopeStackSizeB = *(uint *)(scopeStackVec + 4);
    if (scopeStackSizeB - 1 < scopeStackSizeB) {
      scopeStackTopEntry = (undefined4 *)((scopeStackSizeB - 1) * 4 + *(int *)(scopeStackVec + 8));
    }
    closedScope = *scopeStackTopEntry;
    Vector__removeAt(scopeStackVec,scopeStackSizeB - 1);
    Arena__free(*(undefined4 *)(*ilReader + 0x378),closedScope);
    ilReader[0x13] = ilReader[0x13] + -1;
    goto switchD_000e61ac_caseD_a;
  case 0x34:
    tokenWord1Snapshot = ilReader[0x24];
    extraOperandA = 0;
    tokenWord0Snapshot = ilReader[0x23];
    extraOperandB = 0;
    firstRegisterFile = tokenWord1Snapshot >> 0x10 & 0x3f;
    iVar4 = 1;
    if ((tokenWord1Snapshot & 0x400000) != 0) {
      extraOperandA = ilReader[0x25];
      iVar4 = 3;
    }
    secondOperandToken = ilReader[iVar4 + 0x23];
    if ((secondOperandToken & 0x400000) != 0) {
      extraOperandB = ilReader[iVar4 + 0x24];
    }
    if ((((firstRegisterFile != (secondOperandToken >> 0x10 & 0x3f)) || (firstRegisterFile != 1)) ||
        (iVar4 = Compiler__isOptionEnabled(*ilReader,1), iVar4 == 0)) ||
       ((iVar4 = ILReader__readFloatConst(ilReader,(int)(short)tokenWord1Snapshot,&leftConstant,extraOperandA), iVar4 == 0 ||
        (iVar4 = ILReader__readFloatConst(ilReader,(int)(short)secondOperandToken,rightConstant,extraOperandB), iVar4 == 0)))) {
      ifResultStack = (uint *)ilReader[0xf];
      ifResultStackSizeB = ifResultStack[1];
      if (ifResultStackSizeB < *ifResultStack) {
        _memset(ifResultStackSizeB * 4 + ifResultStack[2],0,4);
        ifResultStackSlotEntry = (undefined4 *)(ifResultStackSizeB * 4 + ifResultStack[2]);
        ifResultStack[1] = ifResultStackSizeB + 1;
      }
      else {
        ifResultStackSlotEntry = (undefined4 *)Vector__elementRefGrow(ifResultStack,ifResultStackSizeB);
      }
      *ifResultStackSlotEntry = 0;
      scopeStackVec = ilReader[0x10];
      ilReader[0x12] = ilReader[0x12] + 1;
      scopeStackSizeB = *(uint *)(scopeStackVec + 4);
      goto joined_r0x000e6a0c;
    }
    switch(tokenWord0Snapshot >> 0x10 & 7) {
    case 0:
      comparisonResult = GH_U2F((unsigned int)(leftConstant)) != rightConstant[0];
      break;
    case 1:
      comparisonResult = GH_U2F((unsigned int)(leftConstant)) == rightConstant[0];
      break;
    case 2:
      comparisonResult = rightConstant[0] <= GH_U2F((unsigned int)(leftConstant));
      break;
    case 3:
      comparisonResult = rightConstant[0] < GH_U2F((unsigned int)(leftConstant));
      break;
    case 4:
      comparisonResult = GH_U2F((unsigned int)(leftConstant)) <= rightConstant[0];
      break;
    case 5:
      comparisonResult = GH_U2F((unsigned int)(leftConstant)) < rightConstant[0];
      break;
    default:
      goto switchD_000e67b4_default;
    }
    if (comparisonResult) goto LAB_000e6870;
switchD_000e67b4_default:
    ifResultStack = (uint *)ilReader[0xf];
    ifResultStackCount = ifResultStack[1];
    if (ifResultStackCount < *ifResultStack) {
      _memset(ifResultStackCount * 4 + ifResultStack[2],0,4);
      ifResultStackSlotEntry = (undefined4 *)(ifResultStackCount * 4 + ifResultStack[2]);
      ifResultStack[1] = ifResultStackCount + 1;
    }
    else {
      ifResultStackSlotEntry = (undefined4 *)Vector__elementRefGrow(ifResultStack,ifResultStackCount);
    }
    replaySkipDepth = 0;
    *ifResultStackSlotEntry = 2;
    ilReader[0x20] = 2;
    break;
  case 0x35:
    operandRegister = *(short *)((int)ilReader + 0x92);
    labelValue = ILReader__lookupBoolConst(ilReader,(int)operandRegister);
    if (labelValue == -1) {
      ifResultStack = (uint *)ilReader[0xf];
      ifResultStackSizeB = ifResultStack[1];
      if (ifResultStackSizeB < *ifResultStack) {
        _memset(ifResultStackSizeB * 4 + ifResultStack[2],0,4);
        ifResultStackSlotEntry = (undefined4 *)(ifResultStackSizeB * 4 + ifResultStack[2]);
        ifResultStack[1] = ifResultStackSizeB + 1;
      }
      else {
        ifResultStackSlotEntry = (undefined4 *)Vector__elementRefGrow(ifResultStack,ifResultStackSizeB);
      }
      *ifResultStackSlotEntry = 0;
      ilReader[0x12] = ilReader[0x12] + 1;
      goto switchD_000e61ac_caseD_a;
    }
    iVar4 = ILReader__lookupBoolConst(ilReader,(int)operandRegister);
    if (iVar4 == 0) {
      ifResultStack = (uint *)ilReader[0xf];
      ilReader[0x20] = 2;
      ifResultStackCount = ifResultStack[1];
      if (ifResultStackCount < *ifResultStack) {
        _memset(ifResultStackCount * 4 + ifResultStack[2],0,4);
        ifResultStackSlotEntry = (undefined4 *)(ifResultStackCount * 4 + ifResultStack[2]);
        ifResultStack[1] = ifResultStackCount + 1;
      }
      else {
        ifResultStackSlotEntry = (undefined4 *)Vector__elementRefGrow(ifResultStack,ifResultStackCount);
      }
      replaySkipDepth = 0;
      *ifResultStackSlotEntry = 2;
    }
    else {
LAB_000e6870:
      ifResultStack = (uint *)ilReader[0xf];
      ifResultStackCount = ifResultStack[1];
      if (ifResultStackCount < *ifResultStack) {
        _memset(ifResultStackCount * 4 + ifResultStack[2],0,4);
        ifResultStackSlotEntry = (undefined4 *)(ifResultStackCount * 4 + ifResultStack[2]);
        ifResultStack[1] = ifResultStackCount + 1;
      }
      else {
        ifResultStackSlotEntry = (undefined4 *)Vector__elementRefGrow(ifResultStack,ifResultStackCount);
      }
      *ifResultStackSlotEntry = 1;
    }
    break;
  case 0x3e:
  case 0x71:
    ilReader[0x13] = ilReader[0x13] + 1;
  case 0x72:
    newScope = (undefined4 *)Arena__alloc(*(undefined4 *)(*ilReader + 0x378),0x18);
    *newScope = dispatchOpcode;
    newScope[3] = 0;
    newScope[1] = 0;
    newScope[2] = 0;
    scopeStack = (uint *)ilReader[0x10];
    scopeStackSizeB = scopeStack[1];
    if (scopeStackSizeB < *scopeStack) {
      _memset(scopeStackSizeB * 4 + scopeStack[2],0,4);
      scopeStackSlotEntry = (undefined4 *)(scopeStackSizeB * 4 + scopeStack[2]);
      scopeStack[1] = scopeStackSizeB + 1;
    }
    else {
      scopeStackSlotEntry = (undefined4 *)Vector__elementRefGrow(scopeStack,scopeStackSizeB);
    }
    *scopeStackSlotEntry = newScope;
    goto switchD_000e61ac_caseD_a;
  case 0x53:
    goto switchD_000e61ac_caseD_53;
  case 0x65:
    leftConstant = 6;
    ((int (*)())ILReader__beginRewrittenReplay_e547c)(ilReader,0x6f,tokenCount,6,argR7,staleArgR8);
    break;
  case 0x66:
    leftConstant = 6;
    ((int (*)())ILReader__beginRewrittenReplay_e547c)(ilReader,0x70,tokenCount,6,argR7,staleArgR8);
    break;
  case 0x67:
    leftConstant = 8;
    iVar4 = tokenCount + -1;
    argR7 = ilReader[tokenCount + 0x22];
    tokenCount = iVar4;
    ((int (*)())ILReader__beginRewrittenReplay_e5384)(ilReader,0x6f,iVar4,8,argR7,staleArgR8);
    break;
  case 0x68:
    leftConstant = 8;
    iVar4 = tokenCount + -1;
    argR7 = ilReader[tokenCount + 0x22];
    tokenCount = iVar4;
    ((int (*)())ILReader__beginRewrittenReplay_e5384)(ilReader,0x70,iVar4,8,argR7,staleArgR8);
    break;
  case 0x69:
    scopeStackTop = (int *)0x0;
    scopeStackSize = *(uint *)(ilReader[0x10] + 4);
    topIndex = scopeStackSize - 1;
    if (topIndex < scopeStackSize) {
      scopeStackTop = (int *)(topIndex * 4 + *(int *)(ilReader[0x10] + 8));
    }
    iVar4 = *scopeStackTop;
    if (*(int *)(iVar4 + 0x14) == 0) {
      if (*(int *)(iVar4 + 4) == 0) {
        if (*(int *)(iVar4 + 8) == 0) {
          *(undefined4 *)(iVar4 + 4) = 1;
          goto switchD_000e61ac_caseD_a;
        }
        ilReader[0x1d] = *(int *)(iVar4 + 8);
        ilReader[0x20] = 0;
        *(undefined4 *)(iVar4 + 8) = 0;
      }
      else if (*(int *)(iVar4 + 8) == 0) {
        *(int *)(iVar4 + 8) = ilReader[0x1d] + tokenCount * -4;
      }
    }
    break;
  case 0x6c:
    scopeStackTop = (int *)0x0;
    scopeStackSize = *(uint *)(ilReader[0x10] + 4);
    topIndex = scopeStackSize - 1;
    if (topIndex < scopeStackSize) {
      scopeStackTop = (int *)(topIndex * 4 + *(int *)(ilReader[0x10] + 8));
    }
    iVar4 = *scopeStackTop;
    *(int *)(iVar4 + 0x10) = ilReader[0x1d] + tokenCount * -4;
    if (*(int *)(iVar4 + 4) != 0) goto LAB_000e7400;
    if (*(int *)(iVar4 + 0x14) != 0) goto switchD_000e61ac_caseD_a;
    replayStack = (uint *)ilReader[0x22];
    iVar4 = ilReader[0x20];
    replayStackCount = replayStack[1];
    if (replayStackCount < *replayStack) {
      _memset(replayStackCount * 4 + replayStack[2],0,4);
      replayStackSlot = (int *)(replayStackCount * 4 + replayStack[2]);
      replayStack[1] = replayStackCount + 1;
    }
    else {
      replayStackSlot = (int *)Vector__elementRefGrow(replayStack,replayStackCount);
    }
    *replayStackSlot = iVar4;
    ilReader[0x20] = 4;
    break;
  case 0x6d:
    iVar4 = ilReader[0x10];
    scopeStackTop = (int *)0x0;
    scopeStackCount = *(uint *)(iVar4 + 4);
    if (scopeStackCount - 1 < scopeStackCount) {
      scopeStackTop = (int *)((scopeStackCount - 1) * 4 + *(int *)(iVar4 + 8));
    }
    poppedState = *scopeStackTop;
    if (*(int *)(poppedState + 4) == 0) {
      if (*(int *)(poppedState + 8) == 0) {
        if ((*(int *)(poppedState + 0x14) != 0) || (*(int *)(poppedState + 0x10) == 0)) {
          Vector__removeAt(iVar4,scopeStackCount - 1);
          goto switchD_000e61ac_caseD_a;
        }
        ilReader[0x1d] = *(int *)(poppedState + 0x10);
        *(undefined4 *)(poppedState + 0x14) = 1;
      }
      else {
        ilReader[0x1d] = *(int *)(poppedState + 8);
        scopeStackTop = (int *)0x0;
        scopeStackCount = *(uint *)(iVar4 + 4) - 1;
        if (scopeStackCount < *(uint *)(iVar4 + 4)) {
          scopeStackTop = (int *)(scopeStackCount * 4 + *(int *)(iVar4 + 8));
        }
        *(undefined4 *)(*scopeStackTop + 8) = 0;
        ilReader[0x1f] = 0;
      }
    }
    else {
      iVar4 = *(int *)(poppedState + 8);
      if (iVar4 == 0) {
        replayStack = (uint *)ilReader[0x22];
        iVar4 = ilReader[0x1d];
        replayStackCount = replayStack[1];
        streamBaseSnapshotB = ilReader[0xb];
        if (replayStackCount < *replayStack) {
          _memset(replayStackCount * 4 + replayStack[2],0,4);
          replayStackSlot = (int *)(replayStackCount * 4 + replayStack[2]);
          replayStack[1] = replayStackCount + 1;
        }
        else {
          replayStackSlot = (int *)Vector__elementRefGrow(replayStack,replayStackCount);
        }
        *replayStackSlot = (iVar4 - streamBaseSnapshotB) + -4 >> 2;
        replayStack = (uint *)ilReader[0x22];
        replayStackCount = replayStack[1];
        if (replayStackCount < *replayStack) {
          _memset(replayStackCount * 4 + replayStack[2],0,4);
          replayStackSlotEntry = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
          replayStack[1] = replayStackCount + 1;
        }
        else {
          replayStackSlotEntry = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
        }
        *replayStackSlotEntry = 0;
        replayStack = (uint *)ilReader[0x22];
        replayStackCount = replayStack[1];
        if (replayStackCount < *replayStack) {
          _memset(replayStackCount * 4 + replayStack[2],0,4);
          replayStackSlotEntry = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
          replayStack[1] = replayStackCount + 1;
        }
        else {
          replayStackSlotEntry = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
        }
        *replayStackSlotEntry = 0;
        replayStack = (uint *)ilReader[0x22];
        replayStackCount = replayStack[1];
        if (replayStackCount < *replayStack) {
          _memset(replayStackCount * 4 + replayStack[2],0,4);
          replayStackSlotEntry = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
          replayStack[1] = replayStackCount + 1;
        }
        else {
          replayStackSlotEntry = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
        }
        *replayStackSlotEntry = 0xffffffff;
        replayStack = (uint *)ilReader[0x22];
        replayStackCount = replayStack[1];
        if (replayStackCount < *replayStack) {
          _memset(replayStackCount * 4 + replayStack[2],0,4);
          replayStackSlotEntry = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
          replayStack[1] = replayStackCount + 1;
        }
        else {
          replayStackSlotEntry = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
        }
        *replayStackSlotEntry = 6;
        ilReader[0x1f] = 1;
        *(undefined4 *)(poppedState + 4) = 0;
      }
      else {
        replayStack = (uint *)ilReader[0x22];
        streamBaseSnapshotB = ilReader[0xb];
        replayStackCount = replayStack[1];
        if (replayStackCount < *replayStack) {
          _memset(replayStackCount * 4 + replayStack[2],0,4);
          replayStackSlot = (int *)(replayStackCount * 4 + replayStack[2]);
          replayStack[1] = replayStackCount + 1;
        }
        else {
          replayStackSlot = (int *)Vector__elementRefGrow(replayStack,replayStackCount);
        }
        *replayStackSlot = iVar4 - streamBaseSnapshotB >> 2;
        *(undefined4 *)(poppedState + 8) = 0;
        replayStack = (uint *)ilReader[0x22];
        replayStackCount = replayStack[1];
        if (replayStackCount < *replayStack) {
          _memset(replayStackCount * 4 + replayStack[2],0,4);
          replayStackSlotEntry = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
          replayStack[1] = replayStackCount + 1;
        }
        else {
          replayStackSlotEntry = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
        }
        *replayStackSlotEntry = 0;
        replayStack = (uint *)ilReader[0x22];
        replayStackCount = replayStack[1];
        if (replayStackCount < *replayStack) {
          _memset(replayStackCount * 4 + replayStack[2],0,4);
          replayStackSlotEntry = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
          replayStack[1] = replayStackCount + 1;
        }
        else {
          replayStackSlotEntry = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
        }
        *replayStackSlotEntry = 0;
        replayStack = (uint *)ilReader[0x22];
        replayStackCount = replayStack[1];
        if (replayStackCount < *replayStack) {
          _memset(replayStackCount * 4 + replayStack[2],0,4);
          replayStackSlotEntry = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
          replayStack[1] = replayStackCount + 1;
        }
        else {
          replayStackSlotEntry = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
        }
        *replayStackSlotEntry = 0xffffffff;
        replayStack = (uint *)ilReader[0x22];
        replayStackCount = replayStack[1];
        if (replayStackCount < *replayStack) {
          _memset(replayStackCount * 4 + replayStack[2],0,4);
          replayStackSlotEntry = (undefined4 *)(replayStackCount * 4 + replayStack[2]);
          replayStack[1] = replayStackCount + 1;
        }
        else {
          replayStackSlotEntry = (undefined4 *)Vector__elementRefGrow(replayStack,replayStackCount);
        }
        *replayStackSlotEntry = 6;
        ilReader[0x1f] = 1;
      }
    }
    break;
  case 0x6f:
  case 0x70:
    ifResultStack = (uint *)ilReader[0xf];
    ilReader[0x12] = ilReader[0x12] + 1;
    ifResultStackSizeB = ifResultStack[1];
    if (ifResultStackSizeB < *ifResultStack) {
      _memset(ifResultStackSizeB * 4 + ifResultStack[2],0,4);
      ifResultStackSlotEntry = (undefined4 *)(ifResultStackSizeB * 4 + ifResultStack[2]);
      ifResultStack[1] = ifResultStackSizeB + 1;
    }
    else {
      ifResultStackSlotEntry = (undefined4 *)Vector__elementRefGrow(ifResultStack,ifResultStackSizeB);
    }
    *ifResultStackSlotEntry = 0;
    scopeStackVec = ilReader[0x10];
    scopeStackSizeB = *(uint *)(scopeStackVec + 4);
joined_r0x000e6a0c:
    if (0 < (int)scopeStackSizeB) {
      scopeStackTop = (int *)0x0;
      if (scopeStackSizeB - 1 < scopeStackSizeB) {
        scopeStackTop = (int *)((scopeStackSizeB - 1) * 4 + *(int *)(scopeStackVec + 8));
      }
      *(int *)(*scopeStackTop + 0xc) = *(int *)(*scopeStackTop + 0xc) + 1;
    }
    goto switchD_000e61ac_caseD_a;
  case 0x73:
    if ((ilReader[0x12] != 0) || (ilReader[0x13] != 0)) {
      ilReader[0x14] = 1;
      ilReader[0x24] = ilReader[0x15];
      ilReader[0x17] = 1;
      ilReader[0x16] = 1;
      goto switchD_000e61ac_caseD_a;
    }
switchD_000e61ac_caseD_53:
    iVar4 = ilReader[0x15];
    savedFlagSnapshotB = ilReader[0x14];
    ilReader[0x15] = iVar4 + -1;
    if (iVar4 + -1 < 0) {
      ilReader[0x14] = 0;
      ilReader[0x12] = 0;
      ilReader[0x13] = 0;
    }
    else {
      savedStateStackVec = ilReader[0x11];
      savedStateStackTop = (int *)0x0;
      savedStateStackCount = *(uint *)(savedStateStackVec + 4);
      if (savedStateStackCount - 1 < savedStateStackCount) {
        savedStateStackTop = (int *)((savedStateStackCount - 1) * 4 + *(int *)(savedStateStackVec + 8));
      }
      restoredValue = *savedStateStackTop;
      Vector__removeAt(savedStateStackVec,savedStateStackCount - 1);
      savedStateStackVec = ilReader[0x11];
      ilReader[0x12] = restoredValue;
      savedStateStackTop = (int *)0x0;
      savedStateStackCount = *(uint *)(savedStateStackVec + 4);
      if (savedStateStackCount - 1 < savedStateStackCount) {
        savedStateStackTop = (int *)((savedStateStackCount - 1) * 4 + *(int *)(savedStateStackVec + 8));
      }
      restoredValue = *savedStateStackTop;
      Vector__removeAt(savedStateStackVec,savedStateStackCount - 1);
      iVar4 = ilReader[0x11];
      ilReader[0x13] = restoredValue;
      savedStateStackTop = (int *)0x0;
      savedStateStackCount = *(uint *)(iVar4 + 4);
      if (savedStateStackCount - 1 < savedStateStackCount) {
        savedStateStackTop = (int *)((savedStateStackCount - 1) * 4 + *(int *)(iVar4 + 8));
      }
      restoredValue = *savedStateStackTop;
      Vector__removeAt(iVar4,savedStateStackCount - 1);
      ilReader[0x14] = (uint)(restoredValue == 1);
    }
    ilReader[0x1f] = 1;
    if (savedFlagSnapshotB != 0) {
      ilReader[0x23] = 0x6e;
      ilReader[0x16] = 1;
      ilReader[0x17] = 1;
      ilReader[0x24] = ilReader[0x15] + 1;
      goto switchD_000e61ac_caseD_a;
    }
    break;
  case 0x74:
    leftConstant = 0x73;
    ((int (*)())ILReader__beginRewrittenReplay_e547c)(ilReader,0x6f,tokenCount,0x73,argR7,staleArgR8);
    break;
  case 0x75:
    leftConstant = 0x73;
    ((int (*)())ILReader__beginRewrittenReplay_e547c)(ilReader,0x70,tokenCount,0x73,argR7,staleArgR8);
  }
  goto LAB_000e5e9c;
LAB_000e7400:
  if (*(int *)(iVar4 + 0x14) != 0) {
switchD_000e61ac_caseD_a:
    DAT_001fa620 = tokenCount;
    ilReader[0xd] = ilReader[0xd] + 1;
    return 1;
  }
  goto LAB_000e5e9c;
}

/* Block__detach @ 0xe7658 (48 bytes) */
int Block__detach(block)
  int block;
{
  uint bitIndex;
  int bitsetWord;
  
  bitIndex = *(uint *)(block + 0xb4) & 0x1f;
  bitsetWord = (*(uint *)(block + 0xb4) >> 3 & 0x1ffffffc) + *(int *)(*(int *)(block + 0xac) + 0x3bc)
  ;
  *(uint *)(bitsetWord + 8) = (-2 << bitIndex | 0xfffffffeU >> 0x20 - bitIndex) & *(uint *)(bitsetWord + 8);
  return DListNode__unlinkAndDelete(block);
}

/* Block__appendInst @ 0xe7688 (60 bytes) */
int Block__appendInst(block, inst)
  int block;
  int inst;
{
  DList__insertBefore(inst,*(undefined4 *)(block + 0xcc));
  *(int *)(inst + 0x158) = block;
  return;
}

/* Block__prependInst @ 0xe76c4 (60 bytes) */
int Block__prependInst(block, inst)
  int block;
  int inst;
{
  DList__insertAfter(inst,*(undefined4 *)(block + 200));
  *(int *)(inst + 0x158) = block;
  return;
}

/* Block__insertInstBefore @ 0xe7700 (56 bytes) */
int Block__insertInstBefore(block, beforeInst, inst)
  undefined4 block;
  undefined4 beforeInst;
  int inst;
{
  DList__insertBefore(inst,beforeInst);
  *(undefined4 *)(inst + 0x158) = block;
  return;
}

/* Block__insertInstAfter @ 0xe7738 (56 bytes) */
int Block__insertInstAfter(block, afterInst, inst)
  undefined4 block;
  undefined4 afterInst;
  int inst;
{
  DList__insertAfter(inst,afterInst);
  *(undefined4 *)(inst + 0x158) = block;
  return;
}

/* Block__isSimple @ 0xe7770 (80 bytes) */
int Block__isSimple(block)
  int *block;
{
  undefined4 kindName;
  int compareResult;
  
  kindName = (**(code **)(*block + 0x4c))(block);
  compareResult = _strcmp(kindName,"SIMPLE");
  return compareResult == 0;
}

/* LoopHeader__getKindName @ 0xe77c0 (52 bytes) */
int LoopHeader__getKindName(this)
  int this;
{
  if (*(int *)(this + 0x134) != 0) {
    return "REP_HEADER";
  }
  return "LOOP_HEADER";
}

/* FUN_000e77f4 @ 0xe77f4 (16 bytes) */
int FUN_000e77f4(scope, breakTarget)
  int scope;
  undefined4 breakTarget;
{
  *(undefined4 *)(scope + 0x154) = breakTarget;
  *(undefined4 *)(scope + 0x150) = 1;
  return;
}

/* Block__getBranchInst @ 0xe7804 (188 bytes) */
int Block__getBranchInst(block, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int block;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  int *inst;
  int *nextInst;
  int isPseudo;
  
  inst = *(int **)(block + 0x98);
  for (nextInst = (int *)(*(int **)(block + 0x98))[2]; nextInst != (int *)0x0;
      nextInst = (int *)nextInst[2]) {
    if ((inst[5] & 1U) != 0) {
      isPseudo = (**(code **)(*inst + 0x34))(inst);
      if ((isPseudo == 0) && (isPseudo = (**(code **)(*inst + 0x38))(inst), isPseudo == 0)) {
        (**(code **)(*inst + 0x18))(inst);
        nextInst = (int *)inst[2];
      }
      else {
        nextInst = (int *)inst[2];
      }
    }
    inst = nextInst;
  }
  return *(undefined4 *)(block + 0x130);
}

/* Block__setField0xb8AndChildren @ 0xe78c0 (56 bytes) */
int Block__setField0xb8AndChildren(block, value)
  int block;
  undefined4 value;
{
  *(undefined4 *)(block + 0xb8) = value;
  if (*(int *)(block + 0x134) != 0) {
    *(undefined4 *)(*(int *)(block + 0x134) + 0xb8) = value;
  }
  if (*(int *)(block + 0x138) != 0) {
    *(undefined4 *)(*(int *)(block + 0x138) + 0xb8) = value;
  }
  if (*(int *)(block + 0x13c) == 0) {
    return;
  }
  *(undefined4 *)(*(int *)(block + 0x13c) + 0xb8) = value;
  return;
}

/* Block__isAncestorOf @ 0xe78f8 (44 bytes) */
int Block__isAncestorOf(ancestor, block)
  int ancestor;
  int block;
{
  do {
    if (block == ancestor) {
      return 1;
    }
    block = *(int *)(block + 0xf0);
  } while (block != 0);
  return 0;
}

/* Block__nearestCommonAncestor @ 0xe7924 (104 bytes) */
int Block__nearestCommonAncestor(blockA, blockB)
  int blockA;
  int blockB;
{
  int isAncestor;
  int ancestorBlock;
  
  while ((isAncestor = ((int (*)())Block__isAncestorOf)(blockA,blockB), ancestorBlock = blockA, isAncestor == 0 &&
         (isAncestor = ((int (*)())Block__isAncestorOf)(blockB,blockA), ancestorBlock = blockB, isAncestor == 0))) {
    blockA = *(int *)(blockA + 0xf0);
    blockB = *(int *)(blockB + 0xf0);
  }
  return ancestorBlock;
}

/* Block__vectorF8NonEmpty @ 0xe798c (20 bytes) */
int Block__vectorF8NonEmpty(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0xf8) + 4) != 0;
}

/* Block__hasMultipleSuccessors @ 0xe79a0 (24 bytes) */
int Block__hasMultipleSuccessors(block)
  int block;
{
  return 1 < *(uint *)(*(int *)(block + 0xd0) + 4);
}

/* FUN_000e79b8 @ 0xe79b8 (24 bytes) */
int FUN_000e79b8(param_1)
  int param_1;
{
  return 1 < *(uint *)(*(int *)(param_1 + 0xd4) + 4);
}

/* Block__successorCount @ 0xe79d0 (12 bytes) */
int Block__successorCount(block)
  int block;
{
  return *(undefined4 *)(*(int *)(block + 0xd0) + 4);
}

/* Block__predecessorCount @ 0xe79dc (12 bytes) */
int Block__predecessorCount(block)
  int block;
{
  return *(undefined4 *)(*(int *)(block + 0xd4) + 4);
}

/* Block__hasSuccessors @ 0xe79e8 (20 bytes) */
int Block__hasSuccessors(block)
  int block;
{
  return *(int *)(*(int *)(block + 0xd0) + 4) != 0;
}

/* Block__vectorD4NonEmpty @ 0xe79fc (20 bytes) */
int Block__vectorD4NonEmpty(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0xd4) + 4) != 0;
}

/* Block__hasDominatedChildren @ 0xe7a10 (20 bytes) */
int Block__hasDominatedChildren(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0xf4) + 4) != 0;
}

/* Block__popDefinitions @ 0xe7a24 (120 bytes) */
int Block__popDefinitions(block)
  int block;
{
  int definitionList;
  uint definitionCount;
  undefined4 *topSlot;
  undefined4 topVReg;
  
  definitionList = *(int *)(block + 0xc4);
  definitionCount = *(uint *)(definitionList + 4);
  while (definitionCount != 0) {
    topSlot = (undefined4 *)0x0;
    if (definitionCount - 1 < definitionCount) {
      topSlot = (undefined4 *)((definitionCount - 1) * 4 + *(int *)(definitionList + 8));
    }
    topVReg = *topSlot;
    Vector__removeAt(definitionList,definitionCount - 1);
    VReg__popDefinition(topVReg);
    definitionList = *(int *)(block + 0xc4);
    definitionCount = *(uint *)(definitionList + 4);
  }
  return;
}

/* Block__lastBlockOfChain_e7a9c @ 0xe7a9c (256 bytes) */
int Block__lastBlockOfChain_e7a9c(block)
  int *block;
{
  int *firstSuccessorSlot;
  int queryResult;
  int *chainBlock;
  
  chainBlock = (int *)block[0x4e];
  while ((((chainBlock != (int *)0x0 && (queryResult = ((int (*)())Block__hasSuccessors)(chainBlock), block = chainBlock, queryResult != 0)) &&
          (queryResult = (**(code **)(*chainBlock + 0x38))(chainBlock), queryResult == 0)) &&
         (queryResult = (**(code **)(*chainBlock + 0x3c))(chainBlock), queryResult == 0))) {
    queryResult = (**(code **)(*chainBlock + 0x2c))(chainBlock);
    if (queryResult == 0) {
      queryResult = (**(code **)(*chainBlock + 0x24))(chainBlock);
      if (queryResult == 0) {
        firstSuccessorSlot = (int *)0x0;
        if (*(int *)(chainBlock[0x34] + 4) != 0) {
          firstSuccessorSlot = *(int **)(chainBlock[0x34] + 8);
        }
        chainBlock = (int *)*firstSuccessorSlot;
        block = chainBlock;
      }
      else {
        chainBlock = (int *)chainBlock[0x4f];
        block = chainBlock;
      }
    }
    else {
      chainBlock = (int *)chainBlock[0x55];
      block = chainBlock;
    }
  }
  return block;
}

/* Block__lastBlockOfChain_e7b9c @ 0xe7b9c (252 bytes) */
int Block__lastBlockOfChain_e7b9c(block)
  int block;
{
  int *firstSuccessorSlot;
  int queryResult;
  int *chainBlock;
  
  chainBlock = *(int **)(block + 0x134);
  while ((((chainBlock != (int *)0x0 && (queryResult = ((int (*)())Block__hasSuccessors)(chainBlock), queryResult != 0)) &&
          (queryResult = (**(code **)(*chainBlock + 0x38))(chainBlock), queryResult == 0)) &&
         (queryResult = (**(code **)(*chainBlock + 0x3c))(chainBlock), queryResult == 0))) {
    queryResult = (**(code **)(*chainBlock + 0x2c))(chainBlock);
    if (queryResult == 0) {
      queryResult = (**(code **)(*chainBlock + 0x24))(chainBlock);
      if (queryResult == 0) {
        firstSuccessorSlot = (int *)0x0;
        if (*(int *)(chainBlock[0x34] + 4) != 0) {
          firstSuccessorSlot = *(int **)(chainBlock[0x34] + 8);
        }
        chainBlock = (int *)*firstSuccessorSlot;
      }
      else {
        chainBlock = (int *)chainBlock[0x4f];
      }
    }
    else {
      chainBlock = (int *)chainBlock[0x55];
    }
  }
  return chainBlock;
}

/* Block__resolveRedirect @ 0xe7c98 (88 bytes) */
int Block__resolveRedirect(block)
  int block;
{
  int *redirectTarget;
  
  redirectTarget = *(int **)(block + 0xa0);
  (**(code **)(*redirectTarget + 0x38))(redirectTarget);
  if ((*(uint *)(redirectTarget[1] + 0x14) & 8) != 0) {
    redirectTarget = *(int **)(redirectTarget[1] + 4);
  }
  return redirectTarget;
}

/* EntryBlock__insertInstruction @ 0xe7cf0 (108 bytes) */
int EntryBlock__insertInstruction(this, inst)
  int this;
  int inst;
{
  if (*(int *)(inst + 0x84) == 0) {
    DList__insertAfter(inst,*(undefined4 *)(this + 300));
    *(int *)(this + 300) = inst;
    *(int *)(inst + 0x158) = this;
  }
  else {
    IRInst__getOperandSource(inst,1);
    DList__insertAfter(inst,*(undefined4 *)(this + 300));
    *(int *)(inst + 0x158) = this;
  }
  return;
}

/* Block__getLoopFooterRegister @ 0xe7d5c (136 bytes) */
int Block__getLoopFooterRegister(block)
  int block;
{
  int sourceDef;
  int scanInst;
  int nextInstLink;
  
  scanInst = *(int *)(block + 0x98);
  nextInstLink = *(int *)(*(int *)(block + 0x98) + 8);
  while( true ) {
    if (nextInstLink == 0) {
      return 0;
    }
    if (((*(uint *)(scanInst + 0x14) & 1) != 0) && (*(int *)(*(int *)(scanInst + 0x88) + 8) == 0x81))
    break;
    scanInst = nextInstLink;
    nextInstLink = *(int *)(nextInstLink + 8);
  }
  sourceDef = IRInst__getOperandSource(scanInst,1);
  if (sourceDef == 0) {
    return *(undefined4 *)(scanInst + 0xac);
  }
  return *(undefined4 *)(sourceDef + 0x94);
}

/* Block__isInVectorD4Of @ 0xe7de4 (172 bytes) */
int Block__isInVectorD4Of(fromBlock, toBlock)
  int fromBlock;
  int toBlock;
{
  int loopCounter;
  uint loopIndex;
  int listEntry;
  uint loopCounterB;
  undefined4 isPredecessor;
  int byteOffset;
  
  loopIndex = 1;
  loopCounter = 0;
  do {
    if (*(uint *)(*(int *)(toBlock + 0xd4) + 4) < loopIndex) {
      isPredecessor = 0;
LAB_000e7e3c:
      loopCounterB = 1;
      for (byteOffset = 0;
          (loopCounterB <= *(uint *)(*(int *)(fromBlock + 0xd0) + 4) &&
          ((listEntry = *(int *)(*(int *)(*(int *)(fromBlock + 0xd0) + 8) + byteOffset), listEntry == 0 ||
           (toBlock != listEntry)))); byteOffset = byteOffset + 4) {
        loopCounterB = loopCounterB + 1;
      }
      return isPredecessor;
    }
    listEntry = *(int *)(loopCounter + *(int *)(*(int *)(toBlock + 0xd4) + 8));
    if ((listEntry != 0) && (fromBlock == listEntry)) {
      isPredecessor = 1;
      goto LAB_000e7e3c;
    }
    loopIndex = loopIndex + 1;
    loopCounter = loopCounter + 4;
  } while( true );
}

/* Block__findSimplePredecessor @ 0xe7e90 (168 bytes) */
int Block__findSimplePredecessor(block)
  int block;
{
  int isSimple;
  int *a0;
  int iVar1;
  int loopCounter;
  uint loopIndex;
  
  loopIndex = 1;
  loopCounter = 0;
  iVar1 = *(int *)(block + 0xd4);
  do {
    if (*(uint *)(iVar1 + 4) < loopIndex) {
      return (int *)0x0;
    }
    a0 = *(int **)(*(int *)(iVar1 + 8) + loopCounter);
    if (a0 != (int *)0x0) {
      isSimple = ((int (*)())Block__isSimple)(a0);
      if (isSimple != 0) {
        return a0;
      }
      iVar1 = (**(code **)(*a0 + 0x1c))(a0);
      if (iVar1 != 0) {
        return a0;
      }
      iVar1 = *(int *)(block + 0xd4);
    }
    loopIndex = loopIndex + 1;
    loopCounter = loopCounter + 4;
  } while( true );
}

/* Block__findSimpleSuccessor @ 0xe7f38 (168 bytes) */
int Block__findSimpleSuccessor(block)
  int block;
{
  int *successor;
  int successorVector;
  int byteOffset;
  uint loopIndex;
  
  loopIndex = 1;
  byteOffset = 0;
  successorVector = *(int *)(block + 0xd0);
  do {
    if (*(uint *)(successorVector + 4) < loopIndex) {
      return (int *)0x0;
    }
    successor = *(int **)(*(int *)(successorVector + 8) + byteOffset);
    if (successor != (int *)0x0) {
      successorVector = ((int (*)())Block__isSimple)(successor);
      if (successorVector != 0) {
        return successor;
      }
      successorVector = (**(code **)(*successor + 0x20))(successor);
      if (successorVector != 0) {
        return successor;
      }
      successorVector = *(int *)(block + 0xd0);
    }
    loopIndex = loopIndex + 1;
    byteOffset = byteOffset + 4;
  } while( true );
}

/* Block__successorIndex @ 0xe7fe0 (92 bytes) */
int Block__successorIndex(block, successor)
  int block;
  int successor;
{
  int listEntry;
  int loopCounter;
  uint loopIndex;
  int loopCounterB;
  
  loopIndex = 1;
  loopCounterB = 0;
  loopCounter = 0;
  do {
    if (*(uint *)(*(int *)(block + 0xd0) + 4) < loopIndex) {
      return -1;
    }
    listEntry = *(int *)(*(int *)(*(int *)(block + 0xd0) + 8) + loopCounterB);
    if (listEntry != 0) {
      if (listEntry == successor) {
        return loopCounter;
      }
      loopCounter = loopCounter + 1;
    }
    loopIndex = loopIndex + 1;
    loopCounterB = loopCounterB + 4;
  } while( true );
}

/* Block__predecessorIndex @ 0xe803c (92 bytes) */
int Block__predecessorIndex(block, predecessor)
  int block;
  int predecessor;
{
  int listEntry;
  int loopCounter;
  uint loopIndex;
  int loopCounterB;
  
  loopIndex = 1;
  loopCounterB = 0;
  loopCounter = 0;
  do {
    if (*(uint *)(*(int *)(block + 0xd4) + 4) < loopIndex) {
      return -1;
    }
    listEntry = *(int *)(*(int *)(*(int *)(block + 0xd4) + 8) + loopCounterB);
    if (listEntry != 0) {
      if (listEntry == predecessor) {
        return loopCounter;
      }
      loopCounter = loopCounter + 1;
    }
    loopIndex = loopIndex + 1;
    loopCounterB = loopCounterB + 4;
  } while( true );
}

/* Block__phiOperandIndexForPredecessor @ 0xe8098 (52 bytes) */
int Block__phiOperandIndexForPredecessor(block, predecessor)
  undefined4 block;
  undefined4 predecessor;
{
  int phiOperandIndex;
  int predecessorIndexResult;
  
  predecessorIndexResult = ((int (*)())Block__predecessorIndex)(block,predecessor);
  phiOperandIndex = -1;
  if (predecessorIndexResult != -1) {
    phiOperandIndex = predecessorIndexResult + 1;
  }
  return phiOperandIndex;
}

/* Block__nextUnvisitedSuccessor @ 0xe80cc (88 bytes) */
int Block__nextUnvisitedSuccessor(block, visitStamp)
  int block;
  int visitStamp;
{
  int successor;
  uint loopIndex;
  int loopCounter;
  
  loopIndex = 1;
  loopCounter = 0;
  while( true ) {
    if (*(uint *)(*(int *)(block + 0xd0) + 4) < loopIndex) {
      return 0;
    }
    successor = *(int *)(*(int *)(*(int *)(block + 0xd0) + 8) + loopCounter);
    if ((successor != 0) && (visitStamp != *(int *)(successor + 0x118))) break;
    loopIndex = loopIndex + 1;
    loopCounter = loopCounter + 4;
  }
  return successor;
}

/* Program__allocateBitSetIndex @ 0xe8124 (664 bytes) */
int Program__allocateBitSetIndex(program, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int program;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  uint wordOffsetOfBit;
  uint bitsLeft2;
  uint bitsLeft;
  uint bitsLeft3;
  uint newWordCapacity;
  uint bitInWord;
  int wordsLeft;
  uint loopCounter;
  uint *oldWordPtr;
  uint newBitCount;
  uint wordByteOffset;
  int *newBitSetData;
  undefined4 *newBitSetAlloc;
  int *clearCursor;
  uint *bitSet;
  undefined4 arenaAt374;
  uint bitCount;
  int bitsToClear;
  
  bitSet = *(uint **)(program + 0x3bc);
  bitCount = bitSet[1];
  if (bitCount == 0) {
LAB_000e8190:
    newBitCount = bitCount + 1;
    if (bitCount + 0x20 >> 5 == *bitSet) {
      bitSet[1] = newBitCount;
      if (bitCount < newBitCount) {
        bitsToClear = newBitCount - bitCount;
        do {
          wordByteOffset = bitCount >> 3 & 0x1ffffffc;
          bitInWord = bitCount & 0x1f;
          bitCount = bitCount + 1;
          *(uint *)((int)bitSet + wordByteOffset + 8) = *(uint *)((int)bitSet + wordByteOffset + 8) & ~(1 << bitInWord);
          bitsToClear = bitsToClear + -1;
        } while (bitsToClear != 0);
      }
      bitSet = *(uint **)(program + 0x3bc);
      bitsLeft = bitSet[1];
      if (bitsLeft != 0) {
        if ((bitSet[2] & 1) != 0) {
          loopCounter = 0;
          do {
            loopCounter = loopCounter + 1;
            bitsLeft = bitsLeft - 1;
            if (bitsLeft == 0) goto LAB_000e82ec;
          } while ((*(uint *)((int)bitSet + (loopCounter >> 3 & 0x1ffffffc) + 8) >> (loopCounter & 0x1f) & 1) !=
                   0);
          goto LAB_000e8388;
        }
        goto LAB_000e8324;
      }
    }
    else {
      newWordCapacity = bitCount + 0x41f >> 5;
      arenaAt374 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      newBitSetAlloc = (undefined4 *)Arena__alloc(arenaAt374,newWordCapacity * 4 + 0xc);
      newBitSetData = newBitSetAlloc + 1;
      *newBitSetAlloc = arenaAt374;
      newBitSetAlloc[1] = newWordCapacity;
      newBitSetAlloc[2] = bitCount + 0x400;
      if (newWordCapacity != 0) {
        clearCursor = newBitSetData;
        if (newWordCapacity == 0) {
          newWordCapacity = 1;
        }
        do {
          clearCursor[2] = 0;
          clearCursor = clearCursor + 1;
          newWordCapacity = newWordCapacity - 1;
        } while (newWordCapacity != 0);
      }
      *(int **)(program + 0x3bc) = newBitSetData;
      wordsLeft = *newBitSetData;
      if (wordsLeft != 0) {
        if (wordsLeft == 0) {
          wordsLeft = 1;
        }
        do {
          oldWordPtr = bitSet + 2;
          bitSet = bitSet + 1;
          newBitSetData[2] = newBitSetData[2] | *oldWordPtr;
          newBitSetData = newBitSetData + 1;
          wordsLeft = wordsLeft + -1;
        } while (wordsLeft != 0);
      }
      bitSet = *(uint **)(program + 0x3bc);
      bitsLeft2 = bitSet[1];
      if (bitsLeft2 != 0) {
        if ((bitSet[2] & 1) != 0) {
          loopCounter = 0;
          do {
            loopCounter = loopCounter + 1;
            bitsLeft2 = bitsLeft2 - 1;
            if (bitsLeft2 == 0) goto LAB_000e82ec;
          } while ((*(uint *)((int)bitSet + (loopCounter >> 3 & 0x1ffffffc) + 8) >> (loopCounter & 0x1f) & 1) !=
                   0);
          goto LAB_000e8388;
        }
        goto LAB_000e8324;
      }
    }
LAB_000e82ec:
    loopCounter = 0xffffffff;
  }
  else {
    if ((bitSet[2] & 1) != 0) {
      loopCounter = 0;
      bitsLeft3 = bitCount;
      do {
        loopCounter = loopCounter + 1;
        bitsLeft3 = bitsLeft3 - 1;
        if (bitsLeft3 == 0) goto LAB_000e8190;
      } while ((*(uint *)((int)bitSet + (loopCounter >> 3 & 0x1ffffffc) + 8) >> (loopCounter & 0x1f) & 1) != 0);
      if (loopCounter != 0xffffffff) goto LAB_000e8388;
      goto LAB_000e8190;
    }
LAB_000e8324:
    loopCounter = 0;
  }
LAB_000e8388:
  wordOffsetOfBit = loopCounter >> 3 & 0x1ffffffc;
  *(uint *)((int)bitSet + wordOffsetOfBit + 8) = 1 << (loopCounter & 0x1f) | *(uint *)((int)bitSet + wordOffsetOfBit + 8);
  return loopCounter;
}

/* Block__getFirstRealInst @ 0xe83bc (104 bytes) */
int Block__getFirstRealInst(block)
  int block;
{
  int opcodeId;
  int cursorInst;
  int *headInst;
  
  headInst = *(int **)(block + 0x98);
  (**(code **)(*headInst + 0x34))(headInst);
  cursorInst = headInst[2];
  opcodeId = *(int *)(*(int *)(cursorInst + 0x88) + 8);
  while (opcodeId == 0x8e) {
    cursorInst = *(int *)(cursorInst + 8);
    opcodeId = *(int *)(*(int *)(cursorInst + 0x88) + 8);
  }
  return cursorInst;
}

/* Block__insertAtStart @ 0xe8424 (216 bytes) */
int Block__insertAtStart(block, inst)
  int block;
  int inst;
{
  int *scanInst;
  int isPinnedInst;
  int *nextInstLink;
  
  if (*(int *)(*(int *)(*(int *)(*(int *)(block + 200) + 8) + 0x88) + 8) == 0x8e) {
    scanInst = *(int **)(block + 0x98);
    for (nextInstLink = (int *)(*(int **)(block + 0x98))[2]; nextInstLink != (int *)0x0;
        nextInstLink = (int *)nextInstLink[2]) {
      if (((scanInst[5] & 1U) != 0) && (*(int *)(scanInst[0x22] + 8) != 0x8e)) {
        isPinnedInst = (**(code **)(*scanInst + 0x34))(scanInst);
        if (isPinnedInst == 0) {
          ((int (*)())Block__insertInstBefore)(block,scanInst,inst);
          return;
        }
        nextInstLink = (int *)scanInst[2];
      }
      scanInst = nextInstLink;
    }
  }
  else {
    DList__insertAfter(inst,*(int *)(block + 200));
    *(int *)(inst + 0x158) = block;
  }
  return;
}

/* Block__verify @ 0xe84fc (468 bytes) */
int Block__verify(this, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int this;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  int compiler;
  bool isFirstFlagged;
  int *nextInstLookahead;
  int *nextInst;
  int loopCounter;
  uint loopIndex;
  int neighborBlock;
  uint loopIndex2;
  int *currentInst;
  
  loopCounter = 0;
  for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(this + 0xd4) + 4); loopIndex = loopIndex + 1) {
    neighborBlock = *(int *)(loopCounter + *(int *)(*(int *)(this + 0xd4) + 8));
    if (neighborBlock != 0) {
      for (loopIndex2 = 1; loopIndex2 <= *(uint *)(*(int *)(neighborBlock + 0xd0) + 4); loopIndex2 = loopIndex2 + 1) {
      }
    }
    loopCounter = loopCounter + 4;
  }
  loopCounter = 0;
  for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(this + 0xd0) + 4); loopIndex = loopIndex + 1) {
    neighborBlock = *(int *)(loopCounter + *(int *)(*(int *)(this + 0xd0) + 8));
    if (neighborBlock != 0) {
      for (loopIndex2 = 1; loopIndex2 <= *(uint *)(*(int *)(neighborBlock + 0xd4) + 4); loopIndex2 = loopIndex2 + 1) {
      }
    }
    loopCounter = loopCounter + 4;
  }
  nextInstLookahead = (int *)(*(int **)(this + 0x98))[2];
  if (nextInstLookahead != (int *)0x0) {
    loopCounter = 0;
    currentInst = *(int **)(this + 0x98);
    do {
      nextInst = nextInstLookahead;
      if ((currentInst[5] & 1U) != 0) {
        isFirstFlagged = loopCounter == 0;
        loopCounter = loopCounter + 1;
        if (isFirstFlagged) {
          (**(code **)(*currentInst + 0x34))(currentInst);
        }
        compiler = *(int *)(this + 0xa8);
        if (((*(uint *)(*(int *)(compiler + 0x6c4) + 0x30) & 4) != 0) &&
           (*(int *)(currentInst[0x22] + 8) == 0x8e)) {
          (**(code **)(*(int *)currentInst[1] + 0x34))((int *)currentInst[1]);
          compiler = *(int *)(this + 0xa8);
        }
        (**(code **)(*currentInst + 8))(currentInst,compiler);
        nextInst = (int *)currentInst[2];
      }
      nextInstLookahead = (int *)nextInst[2];
      currentInst = nextInst;
    } while ((int *)nextInst[2] != (int *)0x0);
  }
  return 1;
}

/* LoopHeader__verify @ 0xe86f0 (236 bytes) */
int LoopHeader__verify(this, param_2, param_3, param_4, param_5, param_6, param_7)
  int this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  uint param_7;
{
  int *currentInst;
  int *nextInst;
  undefined4 r4AfterCall;
  undefined8 queryResult;
  
  currentInst = *(int **)(this + 0x98);
  for (nextInst = (int *)(*(int **)(this + 0x98))[2]; nextInst != (int *)0x0;
      nextInst = (int *)nextInst[2]) {
    param_7 = currentInst[5] & 1;
    if (param_7 != 0) {
      queryResult = (**(code **)(*currentInst + 0x34))(currentInst);
      param_2 = (undefined4)queryResult;
      if (((((int)((ulonglong)queryResult >> 0x20) == 0) &&
           (queryResult = (**(code **)(*currentInst + 0x38))(currentInst), param_2 = (undefined4)queryResult,
           (int)((ulonglong)queryResult >> 0x20) == 0)) && (*(int *)(currentInst[0x22] + 8) != 0x8e)) &&
         (queryResult = (**(code **)(*currentInst + 0x78))(currentInst), param_2 = (undefined4)queryResult,
         (int)((ulonglong)queryResult >> 0x20) == 0)) {
        (**(code **)(*currentInst + 0x3c))(currentInst);
        nextInst = (int *)currentInst[2];
        param_2 = r4AfterCall;
      }
      else {
        nextInst = (int *)currentInst[2];
      }
    }
    currentInst = nextInst;
  }
  return ((int (*)())Block__verify)(this,param_2,param_3,param_4,param_5,param_6,param_7);
}

/* IfHeader__canFlatten @ 0xe87e4 (340 bytes) */
int IfHeader__canFlatten(ifHeader, outFlag)
  int *ifHeader;
  undefined4 *outFlag;
{
  int *successorEntry;
  int count;
  undefined4 *successorRef;
  int elseBlock;
  
  *outFlag = 0;
  count = DList__count(ifHeader[0x4e] + 0x90);
  if ((count < 3) && (count = DList__count(ifHeader[0x4d] + 0x90), count < 3)) {
    elseBlock = ifHeader[0x4e];
    count = ((int (*)())Block__successorCount)(elseBlock);
    if (count == 1) {
      count = *(int *)(elseBlock + 0xd0);
      successorEntry = (int *)0x0;
      if (*(int *)(count + 4) != 0) {
        successorEntry = *(int **)(count + 8);
      }
      if (((*successorEntry == ifHeader[0x4f]) && (count = ((int (*)())Block__successorCount)(ifHeader[0x4d]), count == 1)) &&
         (count = (**(code **)(*ifHeader + 0x40))(ifHeader), count == 0)) {
        successorRef = (undefined4 *)0x0;
        if (*(int *)(*(int *)(ifHeader[0x4d] + 0xd0) + 4) != 0) {
          successorRef = *(undefined4 **)(*(int *)(ifHeader[0x4d] + 0xd0) + 8);
        }
        count = (**(code **)(*(int *)*successorRef + 0x38))((int *)*successorRef);
        if (count != 0) {
          return 1;
        }
        successorRef = (undefined4 *)0x0;
        if (*(int *)(*(int *)(ifHeader[0x4d] + 0xd0) + 4) != 0) {
          successorRef = *(undefined4 **)(*(int *)(ifHeader[0x4d] + 0xd0) + 8);
        }
        count = (**(code **)(*(int *)*successorRef + 0x3c))((int *)*successorRef);
        if (count != 0) {
          *outFlag = 1;
          return 1;
        }
      }
    }
  }
  return 0;
}

/* Block__createEntryExitInsts @ 0xe8938 (132 bytes) */
int Block__createEntryExitInsts(block)
  int block;
{
  undefined4 *exitInst;
  undefined4 *instAlloc;
  undefined4 *entryInst;
  undefined4 arenaAt374;
  
  arenaAt374 = *(undefined4 *)(*(int *)(block + 0xa8) + 0x374);
  instAlloc = (undefined4 *)Arena__alloc(arenaAt374,0x168);
  *instAlloc = arenaAt374;
  entryInst = instAlloc + 1;
  IREntry__ctor_108d5c(entryInst,*(undefined4 *)(block + 0xa8));
  *(undefined4 **)(block + 200) = entryInst;
  DList__pushFront(block + 0x90,entryInst);
  *(int *)(*(int *)(block + 200) + 0x158) = block;
  arenaAt374 = *(undefined4 *)(*(int *)(block + 0xa8) + 0x374);
  instAlloc = (undefined4 *)Arena__alloc(arenaAt374,0x168);
  *instAlloc = arenaAt374;
  exitInst = instAlloc + 1;
  IRExit__ctor_108df4(exitInst,*(undefined4 *)(block + 0xa8));
  *(undefined4 **)(block + 0xcc) = exitInst;
  DList__pushBack(block + 0x90,exitInst);
  *(int *)(*(int *)(block + 0xcc) + 0x158) = block;
  return;
}

/* Block__initVectors @ 0xe8a08 (376 bytes) */
int Block__initVectors(block)
  int block;
{
  undefined4 arenaAt374;
  undefined4 *vectorAlloc;
  undefined4 allocation;
  
  arenaAt374 = *(undefined4 *)(*(int *)(block + 0xa8) + 0x374);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt374,0x14);
  *vectorAlloc = arenaAt374;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt374;
  vectorAlloc[2] = 0;
  allocation = Arena__alloc(arenaAt374,8);
  vectorAlloc[3] = allocation;
  *(undefined4 **)(block + 0xc4) = vectorAlloc + 1;
  arenaAt374 = *(undefined4 *)(*(int *)(block + 0xa8) + 0x374);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt374,0x14);
  *vectorAlloc = arenaAt374;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt374;
  vectorAlloc[2] = 0;
  allocation = Arena__alloc(arenaAt374,8);
  vectorAlloc[3] = allocation;
  *(undefined4 **)(block + 0xf8) = vectorAlloc + 1;
  arenaAt374 = *(undefined4 *)(*(int *)(block + 0xa8) + 0x374);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt374,0x14);
  *vectorAlloc = arenaAt374;
  vectorAlloc[1] = 2;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaAt374;
  allocation = Arena__alloc(arenaAt374,8);
  vectorAlloc[3] = allocation;
  *(undefined4 **)(block + 0xf4) = vectorAlloc + 1;
  arenaAt374 = *(undefined4 *)(*(int *)(block + 0xa8) + 0x374);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt374,0x14);
  vectorAlloc[1] = 2;
  *vectorAlloc = arenaAt374;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaAt374;
  allocation = Arena__alloc(arenaAt374,8);
  vectorAlloc[3] = allocation;
  *(undefined4 **)(block + 0xd0) = vectorAlloc + 1;
  arenaAt374 = *(undefined4 *)(*(int *)(block + 0xa8) + 0x374);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt374,0x14);
  vectorAlloc[1] = 2;
  *vectorAlloc = arenaAt374;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaAt374;
  allocation = Arena__alloc(arenaAt374,8);
  vectorAlloc[3] = allocation;
  *(undefined4 **)(block + 0xd4) = vectorAlloc + 1;
  return;
}

/* FUN_000e8bac @ 0xe8bac (104 bytes) */
int FUN_000e8bac(block)
  int block;
{
  int *definitionSlot;
  
  definitionSlot = *(int **)(*(int *)(*(int *)(block + 0x148) + 0xa4) + 0x18);
  if (*definitionSlot == 0) {
    definitionSlot = (int *)Vector__elementRefGrow(definitionSlot,0);
  }
  else {
    if (definitionSlot[1] == 0) {
      *(undefined4 *)definitionSlot[2] = 0;
      definitionSlot[1] = 1;
    }
    definitionSlot = (int *)definitionSlot[2];
  }
  return *(undefined4 *)(*definitionSlot + 0x50);
}

/* FUN_000e8c14 @ 0xe8c14 (104 bytes) */
int FUN_000e8c14(block)
  int block;
{
  int *definitionSlot;
  
  definitionSlot = *(int **)(*(int *)(*(int *)(block + 0x148) + 0xa4) + 0x18);
  if (*definitionSlot == 0) {
    definitionSlot = (int *)Vector__elementRefGrow(definitionSlot,0);
  }
  else {
    if (definitionSlot[1] == 0) {
      *(undefined4 *)definitionSlot[2] = 0;
      definitionSlot[1] = 1;
    }
    definitionSlot = (int *)definitionSlot[2];
  }
  return *(undefined4 *)(*definitionSlot + 0x38);
}

/* FUN_000e8c7c @ 0xe8c7c (104 bytes) */
int FUN_000e8c7c(block)
  int block;
{
  int *definitionSlot;
  
  definitionSlot = *(int **)(*(int *)(*(int *)(block + 0x148) + 0xa4) + 0x18);
  if (*definitionSlot == 0) {
    definitionSlot = (int *)Vector__elementRefGrow(definitionSlot,0);
  }
  else {
    if (definitionSlot[1] == 0) {
      *(undefined4 *)definitionSlot[2] = 0;
      definitionSlot[1] = 1;
    }
    definitionSlot = (int *)definitionSlot[2];
  }
  return *(undefined4 *)(*definitionSlot + 0x20);
}

/* Block__addDominatedChild @ 0xe8ce4 (120 bytes) */
int Block__addDominatedChild(block, child)
  int block;
  undefined4 child;
{
  undefined4 *vectorSlot;
  uint vectorSize;
  uint *childrenVector;
  
  childrenVector = *(uint **)(block + 0xf4);
  vectorSize = childrenVector[1];
  if (vectorSize < *childrenVector) {
    _memset(vectorSize * 4 + childrenVector[2],0,4);
    vectorSlot = (undefined4 *)(vectorSize * 4 + childrenVector[2]);
    childrenVector[1] = vectorSize + 1;
  }
  else {
    vectorSlot = (undefined4 *)Vector__elementRefGrow(childrenVector,vectorSize);
  }
  *vectorSlot = child;
  return;
}

/* Block__appendPredecessor @ 0xe8d5c (120 bytes) */
int Block__appendPredecessor(block, predecessor)
  int block;
  undefined4 predecessor;
{
  undefined4 *vectorSlot;
  uint vectorSize;
  uint *predecessorVector;
  
  predecessorVector = *(uint **)(block + 0xd4);
  vectorSize = predecessorVector[1];
  if (vectorSize < *predecessorVector) {
    _memset(vectorSize * 4 + predecessorVector[2],0,4);
    vectorSlot = (undefined4 *)(vectorSize * 4 + predecessorVector[2]);
    predecessorVector[1] = vectorSize + 1;
  }
  else {
    vectorSlot = (undefined4 *)Vector__elementRefGrow(predecessorVector,vectorSize);
  }
  *vectorSlot = predecessor;
  return;
}

/* Block__appendSuccessor @ 0xe8dd4 (120 bytes) */
int Block__appendSuccessor(block, successor)
  int block;
  undefined4 successor;
{
  undefined4 *vectorSlot;
  uint vectorSize;
  uint *successorVector;
  
  successorVector = *(uint **)(block + 0xd0);
  vectorSize = successorVector[1];
  if (vectorSize < *successorVector) {
    _memset(vectorSize * 4 + successorVector[2],0,4);
    vectorSlot = (undefined4 *)(vectorSize * 4 + successorVector[2]);
    successorVector[1] = vectorSize + 1;
  }
  else {
    vectorSlot = (undefined4 *)Vector__elementRefGrow(successorVector,vectorSize);
  }
  *vectorSlot = successor;
  return;
}

/* Block__connect @ 0xe8e4c (96 bytes) */
int Block__connect(fromBlock, toBlock)
  undefined4 fromBlock;
  undefined4 toBlock;
{
  int alreadyLinked;
  
  alreadyLinked = ((int (*)())Block__isInVectorD4Of)(fromBlock,toBlock);
  if (alreadyLinked == 0) {
    ((int (*)())Block__appendSuccessor)(fromBlock,toBlock);
    ((int (*)())Block__appendPredecessor)(toBlock,fromBlock);
    return;
  }
  return;
}

/* Block__replaceRegionEdges @ 0xe8eac (608 bytes) */
int Block__replaceRegionEdges(oldFirst, oldLast, newBlock)
  int oldFirst;
  int oldLast;
  undefined4 newBlock;
{
  uint *neighborSuccessors;
  int loopCounter;
  uint loopIndex2;
  int neighborEdgeTarget;
  undefined4 *edgeSlot;
  int neighbor;
  int edgeVector;
  uint edgeCount;
  uint *neighborPredecessors;
  int loopCounterB;
  uint edgeIndex;
  uint lastEdgeIndex;
  uint loopIndex;
  
  loopIndex = 1;
  loopCounterB = 0;
  edgeVector = *(int *)(oldFirst + 0xd4);
  do {
    if (*(uint *)(edgeVector + 4) < loopIndex) {
      edgeVector = *(int *)(oldLast + 0xd0);
      loopIndex = 1;
      loopCounterB = 0;
      do {
        if (*(uint *)(edgeVector + 4) < loopIndex) {
          return;
        }
        neighbor = *(int *)(loopCounterB + *(int *)(edgeVector + 8));
        if (neighbor != 0) {
          ((int (*)())Block__appendSuccessor)(newBlock,neighbor);
          loopCounter = 0;
          lastEdgeIndex = 0xffffffff;
          for (loopIndex2 = 1; loopIndex2 <= *(uint *)(*(int *)(neighbor + 0xd4) + 4); loopIndex2 = loopIndex2 + 1) {
            neighborEdgeTarget = *(int *)(*(int *)(*(int *)(neighbor + 0xd4) + 8) + loopCounter);
            edgeIndex = lastEdgeIndex;
            if ((neighborEdgeTarget != 0) && (edgeIndex = lastEdgeIndex + 1, oldLast == neighborEdgeTarget)) {
              neighborPredecessors = *(uint **)(neighbor + 0xd4);
              if (edgeIndex < *neighborPredecessors) {
                edgeCount = neighborPredecessors[1];
                if (edgeCount <= edgeIndex) {
                  _memset(edgeCount * 4 + neighborPredecessors[2],0,(edgeIndex - edgeCount) * 4 + 4);
                  neighborPredecessors[1] = lastEdgeIndex + 2;
                }
                edgeSlot = (undefined4 *)(edgeIndex * 4 + neighborPredecessors[2]);
              }
              else {
                edgeSlot = (undefined4 *)Vector__elementRefGrow(neighborPredecessors,edgeIndex);
              }
              *edgeSlot = newBlock;
              edgeVector = *(int *)(oldLast + 0xd0);
              goto LAB_000e9098;
            }
            loopCounter = loopCounter + 4;
            lastEdgeIndex = edgeIndex;
          }
          edgeVector = *(int *)(oldLast + 0xd0);
        }
LAB_000e9098:
        loopIndex = loopIndex + 1;
        loopCounterB = loopCounterB + 4;
      } while( true );
    }
    neighbor = *(int *)(loopCounterB + *(int *)(edgeVector + 8));
    if (neighbor != 0) {
      ((int (*)())Block__appendPredecessor)(newBlock,neighbor);
      loopCounter = 0;
      lastEdgeIndex = 0xffffffff;
      for (loopIndex2 = 1; loopIndex2 <= *(uint *)(*(int *)(neighbor + 0xd0) + 4); loopIndex2 = loopIndex2 + 1) {
        neighborEdgeTarget = *(int *)(loopCounter + *(int *)(*(int *)(neighbor + 0xd0) + 8));
        edgeIndex = lastEdgeIndex;
        if ((neighborEdgeTarget != 0) && (edgeIndex = lastEdgeIndex + 1, oldFirst == neighborEdgeTarget)) {
          neighborSuccessors = *(uint **)(neighbor + 0xd0);
          if (edgeIndex < *neighborSuccessors) {
            edgeCount = neighborSuccessors[1];
            if (edgeCount <= edgeIndex) {
              _memset(edgeCount * 4 + neighborSuccessors[2],0,(edgeIndex - edgeCount) * 4 + 4);
              neighborSuccessors[1] = lastEdgeIndex + 2;
            }
            edgeSlot = (undefined4 *)(edgeIndex * 4 + neighborSuccessors[2]);
          }
          else {
            edgeSlot = (undefined4 *)Vector__elementRefGrow(neighborSuccessors,edgeIndex);
          }
          *edgeSlot = newBlock;
          edgeVector = *(int *)(oldFirst + 0xd4);
          goto LAB_000e8f80;
        }
        loopCounter = loopCounter + 4;
        lastEdgeIndex = edgeIndex;
      }
      edgeVector = *(int *)(oldFirst + 0xd4);
    }
LAB_000e8f80:
    loopIndex = loopIndex + 1;
    loopCounterB = loopCounterB + 4;
  } while( true );
}

/* Block__addDominanceFrontier @ 0xe910c (120 bytes) */
int Block__addDominanceFrontier(block, frontierBlock)
  int block;
  undefined4 frontierBlock;
{
  undefined4 *vectorSlot;
  uint vectorSize;
  uint *frontierVector;
  
  frontierVector = *(uint **)(block + 0xf8);
  vectorSize = frontierVector[1];
  if (vectorSize < *frontierVector) {
    _memset(vectorSize * 4 + frontierVector[2],0,4);
    vectorSlot = (undefined4 *)(vectorSize * 4 + frontierVector[2]);
    frontierVector[1] = vectorSize + 1;
  }
  else {
    vectorSlot = (undefined4 *)Vector__elementRefGrow(frontierVector,vectorSize);
  }
  *vectorSlot = frontierBlock;
  return;
}

/* Block__getPredecessor @ 0xe9184 (136 bytes) */
int Block__getPredecessor(block, index)
  int block;
  uint index;
{
  uint count;
  undefined4 *elementRef;
  uint *vectorHeader;
  
  vectorHeader = *(uint **)(block + 0xd4);
  if (index < *vectorHeader) {
    count = vectorHeader[1];
    if (count <= index) {
      _memset(count * 4 + vectorHeader[2],0,(index - count) * 4 + 4);
      vectorHeader[1] = index + 1;
    }
    elementRef = (undefined4 *)(index * 4 + vectorHeader[2]);
  }
  else {
    elementRef = (undefined4 *)Vector__elementRefGrow(vectorHeader,index);
  }
  return *elementRef;
}

/* Block__getSuccessor @ 0xe920c (136 bytes) */
int Block__getSuccessor(block, index)
  int block;
  uint index;
{
  uint count;
  undefined4 *elementRef;
  uint *vectorHeader;
  
  vectorHeader = *(uint **)(block + 0xd0);
  if (index < *vectorHeader) {
    count = vectorHeader[1];
    if (count <= index) {
      _memset(count * 4 + vectorHeader[2],0,(index - count) * 4 + 4);
      vectorHeader[1] = index + 1;
    }
    elementRef = (undefined4 *)(index * 4 + vectorHeader[2]);
  }
  else {
    elementRef = (undefined4 *)Vector__elementRefGrow(vectorHeader,index);
  }
  return *elementRef;
}

/* FUN_000e9294 @ 0xe9294 (280 bytes) */
int FUN_000e9294(ifHeader)
  int ifHeader;
{
  int secondPredecessorQuery;
  int firstPredecessorQuery;
  int firstArmPredecessorCount;
  int secondSuccessorQuery;
  int firstSuccessorQuery;
  int *predecessor;
  int firstArmSuccessorCount;
  int *successor;
  undefined4 armBlock;
  
  armBlock = *(undefined4 *)(ifHeader + 0x134);
  firstArmSuccessorCount = ((int (*)())Block__successorCount)(armBlock);
  if ((firstArmSuccessorCount == 1) && (firstArmSuccessorCount = ((int (*)())Block__successorCount)(*(undefined4 *)(ifHeader + 0x138)), firstArmSuccessorCount == 1)) {
    successor = (int *)((int (*)())Block__getSuccessor)(armBlock,0);
    firstSuccessorQuery = (**(code **)(*successor + 0x28))(successor);
    if (firstSuccessorQuery != 0) {
      successor = (int *)((int (*)())Block__getSuccessor)(*(undefined4 *)(ifHeader + 0x138),0);
      secondSuccessorQuery = (**(code **)(*successor + 0x28))(successor);
      if (secondSuccessorQuery != 0) {
        armBlock = *(undefined4 *)(ifHeader + 0x134);
        firstArmPredecessorCount = ((int (*)())Block__predecessorCount)(armBlock);
        if ((firstArmPredecessorCount == 1) && (firstArmPredecessorCount = ((int (*)())Block__predecessorCount)(*(undefined4 *)(ifHeader + 0x138)), firstArmPredecessorCount == 1)) {
          predecessor = (int *)((int (*)())Block__getPredecessor)(armBlock,0);
          firstPredecessorQuery = (**(code **)(*predecessor + 0x24))(predecessor);
          if (firstPredecessorQuery != 0) {
            predecessor = (int *)((int (*)())Block__getPredecessor)(*(undefined4 *)(ifHeader + 0x138),0);
            secondPredecessorQuery = (**(code **)(*predecessor + 0x24))(predecessor);
            if (secondPredecessorQuery != 0) {
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

/* Block__bypass @ 0xe93ac (900 bytes) */
int Block__bypass(block, predBlock, succBlock)
  int *block;
  int *predBlock;
  int *succBlock;
{
  uint *succPredecessors;
  int blockSuccessors;
  int blockPredecessors;
  int loopCounterB;
  uint loopIndex2;
  int *listEntry;
  undefined4 *vectorSlot;
  int loopCounter;
  uint vectorSize;
  int succVtable0x20Result;
  int loopCounterC;
  uint loopIndex;
  uint *predSuccessors;
  
  loopIndex = 0;
  (**(code **)(*block + 0x20))(block,predBlock,succBlock);
  (**(code **)(*block + 0x1c))(block);
  loopCounterB = 0;
  for (loopIndex2 = 1; loopIndex2 <= *(uint *)(predBlock[0x34] + 4); loopIndex2 = loopIndex2 + 1) {
    listEntry = *(int **)(loopCounterB + *(int *)(predBlock[0x34] + 8));
    if (listEntry != (int *)0x0) {
      if (block == listEntry) {
        succVtable0x20Result = (**(code **)(*succBlock + 0x20))(succBlock);
        if ((succVtable0x20Result == 0) || ((*(uint *)(block[0x2b] + 0x30) & 2) != 0)) {
          predSuccessors = (uint *)predBlock[0x34];
          if (loopIndex < *predSuccessors) {
            vectorSize = predSuccessors[1];
            if (vectorSize <= loopIndex) {
              _memset(vectorSize * 4 + predSuccessors[2],0,(loopIndex - vectorSize) * 4 + 4);
              predSuccessors[1] = loopIndex + 1;
            }
            vectorSlot = (undefined4 *)(loopIndex * 4 + predSuccessors[2]);
          }
          else {
            vectorSlot = (undefined4 *)Vector__elementRefGrow(predSuccessors,loopIndex);
          }
          *vectorSlot = succBlock;
        }
        else {
          Vector__removeAt(predBlock[0x34],loopIndex);
        }
        break;
      }
      loopIndex = loopIndex + 1;
    }
    loopCounterB = loopCounterB + 4;
  }
  blockPredecessors = block[0x35];
  loopCounter = 0;
  loopCounterC = 0;
  for (loopIndex2 = 1; loopIndex2 <= *(uint *)(blockPredecessors + 4); loopIndex2 = loopIndex2 + 1) {
    listEntry = *(int **)(loopCounterC + *(int *)(blockPredecessors + 8));
    if (listEntry != (int *)0x0) {
      if (predBlock == listEntry) {
        Vector__removeAt(blockPredecessors,loopCounter);
        break;
      }
      loopCounter = loopCounter + 1;
    }
    loopCounterC = loopCounterC + 4;
  }
  succPredecessors = (uint *)succBlock[0x35];
  loopIndex = 0;
  loopCounterB = 0;
  for (loopIndex2 = 1; loopIndex2 <= succPredecessors[1]; loopIndex2 = loopIndex2 + 1) {
    if (*(int **)(succPredecessors[2] + loopCounterB) != (int *)0x0) {
      if (block == *(int **)(succPredecessors[2] + loopCounterB)) {
        if (loopIndex < *succPredecessors) {
          vectorSize = succPredecessors[1];
          if (vectorSize <= loopIndex) {
            _memset(vectorSize * 4 + succPredecessors[2],0,(loopIndex - vectorSize) * 4 + 4);
            succPredecessors[1] = loopIndex + 1;
          }
          vectorSlot = (undefined4 *)(loopIndex * 4 + succPredecessors[2]);
        }
        else {
          vectorSlot = (undefined4 *)Vector__elementRefGrow(succPredecessors,loopIndex);
        }
        *vectorSlot = predBlock;
        break;
      }
      loopIndex = loopIndex + 1;
    }
    loopCounterB = loopCounterB + 4;
  }
  blockSuccessors = block[0x34];
  loopCounter = 0;
  loopIndex2 = 1;
  loopCounterC = 0;
  do {
    if (*(uint *)(blockSuccessors + 4) < loopIndex2) {
LAB_000e9610:
      if ((*(uint *)(block[0x2b] + 0x30) & 2) == 0) {
        succVtable0x20Result = (**(code **)(*succBlock + 0x20))(succBlock);
        if ((succVtable0x20Result == 0) || (succVtable0x20Result = ((int (*)())Block__successorCount)(predBlock), succVtable0x20Result != 0)) {
          (**(code **)(*predBlock + 0x48))(predBlock);
        }
        succVtable0x20Result = (**(code **)(*succBlock + 0x20))(succBlock);
        if ((succVtable0x20Result != 0) && (succVtable0x20Result = ((int (*)())Block__predecessorCount)(succBlock), succVtable0x20Result == 0)) {
          return 1;
        }
      }
      else {
        (**(code **)(*predBlock + 0x48))(predBlock);
      }
      (**(code **)(*succBlock + 0x48))(succBlock);
      return 1;
    }
    listEntry = *(int **)(*(int *)(blockSuccessors + 8) + loopCounterC);
    if (listEntry != (int *)0x0) {
      if (succBlock == listEntry) {
        Vector__removeAt(blockSuccessors,loopCounter);
        goto LAB_000e9610;
      }
      loopCounter = loopCounter + 1;
    }
    loopIndex2 = loopIndex2 + 1;
    loopCounterC = loopCounterC + 4;
  } while( true );
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl LoopHeader__getKindName");
asm(".set LoopHeader__getKindName, _LoopHeader__getKindName");
asm(".globl FUN_000e7cf0");
asm(".set FUN_000e7cf0, _EntryBlock__insertInstruction");
asm(".globl Block__verify");
asm(".set Block__verify, _Block__verify");
asm(".globl LoopHeader__verify");
asm(".set LoopHeader__verify, _LoopHeader__verify");
