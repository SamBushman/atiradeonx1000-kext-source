#include "decls.h"

/* _GetChunkAllocationSize @ 0x97b825bc (124 bytes) */
int _GetChunkAllocationSize(chunkKind, extraSize)
  undefined4 chunkKind;
  int extraSize;
{
  switch(chunkKind) {
  case 0:
  case 3:
  case 10:
    return 0x10;
  case 1:
    return 4;
  case 2:
  case 4:
  case 5:
  case 6:
  case 7:
  case 9:
    return 8;
  case 8:
    break;
  case 0xb:
    if (extraSize != 0) {
      return extraSize + 9;
    }
    return 8;
  default:
    return 0;
  }
  if (extraSize != 0) {
    return extraSize + 0x39;
  }
  return 0x38;
}

/* _PPStreamChunkListSort @ 0x97b82668 (156 bytes) */
int _PPStreamChunkListSort(chunkList)
  int *chunkList;
{
  bool swapped;
  int next;
  int prevOfCurrent;
  int current;
  
  next = *chunkList;
  if (next == 0) {
    return;
  }
  while( true ) {
    swapped = false;
    if (next == 0) {
      return;
    }
    while (current = next, next = *(int *)(current + 8), next != 0) {
      if (*(ushort *)(next + 0x12) < *(ushort *)(current + 0x12)) {
        if (*(int *)(next + 8) == 0) {
          chunkList[1] = current;
        }
        else {
          *(int *)(*(int *)(next + 8) + 4) = current;
        }
        prevOfCurrent = *(int *)(current + 4);
        if (prevOfCurrent == 0) {
          *chunkList = next;
          prevOfCurrent = *(int *)(current + 4);
        }
        else {
          *(int *)(prevOfCurrent + 8) = next;
        }
        swapped = true;
        *(int *)(next + 4) = prevOfCurrent;
        *(undefined4 *)(current + 8) = *(undefined4 *)(next + 8);
        *(int *)(current + 4) = next;
        *(int *)(next + 8) = current;
      }
    }
    if (!swapped) break;
    next = *chunkList;
  }
  return;
}

/* _PPStreamAttachOperationsChunkList @ 0x97b82704 (56 bytes) */
int _PPStreamAttachOperationsChunkList(stream, chunkList)
  int stream;
  undefined4 chunkList;
{
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x20));
  *(undefined4 *)(stream + 0x20) = chunkList;
  return;
}

/* _PPStreamChunkListFree @ 0x97b8273c (84 bytes) */
int _PPStreamChunkListFree(chunkList)
  int *chunkList;
{
  int chunksLeft;
  int chunk;
  int nextChunk;
  
  chunksLeft = chunkList[2];
  chunk = *chunkList;
  if (0 < chunksLeft) {
    do {
      nextChunk = *(int *)(chunk + 8);
      _free(chunk);
      chunksLeft = chunksLeft + -1;
      chunk = nextChunk;
    } while (chunksLeft != 0);
  }
  return _free(chunkList);
}

/* _PPStreamChunkListRemoveChunk @ 0x97b82790 (120 bytes) */
int _PPStreamChunkListRemoveChunk(chunkList, chunk)
  undefined4 *chunkList;
  int chunk;
{
  undefined4 r3Out;
  int prev;
  
  prev = *(int *)(chunk + 4);
  if (prev == 0) {
    *chunkList = *(undefined4 *)(chunk + 8);
    prev = *(int *)(chunk + 4);
  }
  else {
    *(undefined4 *)(prev + 8) = *(undefined4 *)(chunk + 8);
  }
  if (*(int *)(chunk + 8) == 0) {
    chunkList[1] = prev;
  }
  else {
    *(int *)(*(int *)(chunk + 8) + 4) = prev;
  }
  _free(chunk);
  chunkList[2] = chunkList[2] + -1;
  return r3Out;
}

/* _PPStreamAttachParamBindingsChunkList @ 0x97b82808 (56 bytes) */
int _PPStreamAttachParamBindingsChunkList(stream, chunkList)
  int stream;
  undefined4 chunkList;
{
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x10));
  *(undefined4 *)(stream + 0x10) = chunkList;
  return;
}

/* _PPStreamAttachParamBindingArraysChunkList @ 0x97b82840 (56 bytes) */
int _PPStreamAttachParamBindingArraysChunkList(stream, chunkList)
  int stream;
  undefined4 chunkList;
{
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x14));
  *(undefined4 *)(stream + 0x14) = chunkList;
  return;
}

/* _PPStreamGetStream @ 0x97b82878 (964 bytes) */
int _PPStreamGetStream(stream, packed, entryCountOut)
  undefined4 *stream;
  undefined4 *packed;
  int *entryCountOut;
{
  int maxIndex;
  undefined4 chunkCount;
  int entryPos;
  uint endPos;
  int listEntryCount [7];
  
  _PPStreamChunkListGetStream(stream[1],0,listEntryCount,stream);
  entryPos = listEntryCount[0];
  _PPStreamChunkListGetStream(stream[6],0,listEntryCount,stream);
  entryPos = entryPos + listEntryCount[0];
  _PPStreamChunkListGetStream(stream[4],0,listEntryCount,stream);
  entryPos = entryPos + listEntryCount[0];
  _PPStreamChunkListGetStream(stream[7],0,listEntryCount,stream);
  entryPos = entryPos + listEntryCount[0];
  _PPStreamChunkListGetStream(stream[5],0,listEntryCount,stream);
  entryPos = entryPos + listEntryCount[0];
  _PPStreamChunkListGetStream(stream[2],0,listEntryCount,stream);
  entryPos = entryPos + listEntryCount[0];
  _PPStreamChunkListGetStream(stream[0xc],0,listEntryCount,stream);
  entryPos = entryPos + listEntryCount[0];
  _PPStreamChunkListGetStream(stream[8],0,listEntryCount,stream);
  entryPos = entryPos + listEntryCount[0];
  _PPStreamChunkListGetStream(stream[10],0,listEntryCount,stream);
  entryPos = entryPos + listEntryCount[0];
  _PPStreamChunkListGetStream(stream[0xb],0,listEntryCount,stream);
  entryPos = (entryPos - (entryPos + 0xeU & 1)) + 0x10 + listEntryCount[0];
  *entryCountOut = entryPos;
  if (packed != (undefined4 *)0x0) {
    _memset(packed,0,entryPos * 8);
    *packed = *stream;
    packed[2] = *entryCountOut;
    if (*(int *)(stream[3] + 8) == 0) {
      packed[6] = 0;
    }
    else {
      maxIndex = ((int (*)())_PPStreamChunkListGetMaxIndex)(stream[3]);
      packed[6] = maxIndex + 1;
    }
    chunkCount = *(undefined4 *)(stream[1] + 8);
    packed[5] = 0xe;
    packed[4] = chunkCount;
    _PPStreamChunkListGetStream(stream[1],packed + 0x1c,listEntryCount,stream);
    entryPos = listEntryCount[0] + 0xe;
    packed[8] = *(undefined4 *)(stream[6] + 8);
    packed[9] = entryPos;
    _PPStreamChunkListGetStream(stream[6],packed + entryPos * 2,listEntryCount,stream);
    entryPos = entryPos + listEntryCount[0];
    packed[10] = *(undefined4 *)(stream[4] + 8);
    packed[0xb] = entryPos;
    _PPStreamChunkListGetStream(stream[4],packed + entryPos * 2,listEntryCount,stream);
    entryPos = entryPos + listEntryCount[0];
    packed[0xc] = *(undefined4 *)(stream[7] + 8);
    packed[0xd] = entryPos;
    _PPStreamChunkListGetStream(stream[7],packed + entryPos * 2,listEntryCount,stream);
    entryPos = entryPos + listEntryCount[0];
    packed[0xe] = *(undefined4 *)(stream[5] + 8);
    packed[0xf] = entryPos;
    _PPStreamChunkListGetStream(stream[5],packed + entryPos * 2,listEntryCount,stream);
    entryPos = entryPos + listEntryCount[0];
    packed[0x10] = *(undefined4 *)(stream[2] + 8);
    packed[0x11] = entryPos;
    _PPStreamChunkListGetStream(stream[2],packed + entryPos * 2,listEntryCount,stream);
    entryPos = entryPos + listEntryCount[0];
    packed[0x12] = *(undefined4 *)(stream[0xc] + 8);
    packed[0x13] = entryPos;
    _PPStreamChunkListGetStream(stream[0xc],packed + entryPos * 2,listEntryCount,stream);
    chunkCount = *(undefined4 *)(stream[8] + 8);
    entryPos = entryPos + listEntryCount[0];
    packed[0x15] = entryPos;
    packed[0x14] = chunkCount;
    _PPStreamChunkListGetStream(stream[8],packed + entryPos * 2,listEntryCount,stream);
    entryPos = entryPos + listEntryCount[0];
    if (listEntryCount[0] != 0) {
      packed[entryPos * 2] =
           *(uint *)(*(int *)(stream[8] + 4) + 0xc) >> 3 & 0x1c000000 |
           packed[entryPos * 2] & 0xe3ffffff;
    }
    chunkCount = *(undefined4 *)(stream[10] + 8);
    packed[0x19] = entryPos;
    packed[0x18] = chunkCount;
    _PPStreamChunkListGetStream(stream[10],packed + entryPos * 2,listEntryCount,stream);
    endPos = entryPos + listEntryCount[0];
    packed[0x16] = 0;
    packed[0x17] = endPos;
    entryPos = (endPos - (endPos & 1)) + 2;
    packed[0x1a] = *(undefined4 *)(stream[0xb] + 8);
    packed[0x1b] = entryPos;
    _PPStreamChunkListGetStream(stream[0xb],packed + entryPos * 2,listEntryCount,stream);
  }
  return;
}

/* _PPStreamChunkListGetMaxIndex @ 0x97b82c3c (164 bytes) */
int _PPStreamChunkListGetMaxIndex(chunkList)
  undefined4 *chunkList;
{
  uint chunkIndex;
  undefined1 *chunk;
  uint maxIndex;
  uint loopIndex;
  
  chunk = (undefined1 *)*chunkList;
  maxIndex = 0;
  loopIndex = 1;
  do {
    if (chunk == (undefined1 *)0x0) {
      return maxIndex;
    }
    switch(*chunk) {
    case 0:
    case 2:
    case 3:
    case 4:
      chunkIndex = (uint)*(ushort *)(chunk + 0x12);
      break;
    case 1:
      chunkIndex = *(uint *)(chunk + 0xc);
      break;
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
      if (maxIndex < loopIndex) {
        maxIndex = loopIndex;
      }
      goto switchD_97b82c84_default;
    case 8:
      chunkIndex = *(uint *)(chunk + 0xc) & 0x3ffff;
      break;
    case 0xb:
      return 0;
    default:
      goto switchD_97b82c84_default;
    }
    if (maxIndex < chunkIndex) {
      maxIndex = chunkIndex;
    }
switchD_97b82c84_default:
    chunk = *(undefined1 **)(chunk + 8);
    loopIndex = loopIndex + 1;
  } while( true );
}

/* _PPStreamAddTempUsage @ 0x97b82d10 (108 bytes) */
int _PPStreamAddTempUsage(stream, usage)
  int stream;
  undefined4 *usage;
{
  undefined1 *allocation;
  undefined4 usageList;
  undefined4 usageWord3;
  undefined4 usageWord0;
  undefined4 usageWord2;
  undefined4 usageWord1;
  
  allocation = (undefined1 *)_calloc(0x1c,1);
  usageWord3 = usage[3];
  usageList = *(undefined4 *)(stream + 4);
  usageWord0 = *usage;
  usageWord1 = usage[1];
  usageWord2 = usage[2];
  *allocation = 0;
  *(undefined4 *)(allocation + 0xc) = usageWord0;
  *(undefined4 *)(allocation + 0x10) = usageWord1;
  *(undefined4 *)(allocation + 0x14) = usageWord2;
  *(undefined4 *)(allocation + 0x18) = usageWord3;
  return _PPStreamChunkListAddChunk(usageList,allocation);
}

/* _PPEmulatorProgramCreate @ 0x97b82d7c (72 bytes) */
int _PPEmulatorProgramCreate()
{
  undefined4 defaultWord;
  int allocation;
  
  allocation = _calloc(0x128,1);
  defaultWord = DAT_a7b7bda4;
  *(undefined4 *)(allocation + 0xc) = DAT_a7b7bda4;
  *(undefined4 *)(allocation + 8) = defaultWord;
  /* dropped-return-value defect (class 25, issue #68) - stock leaves calloc's result in r3
   * through to blr; verified via Capstone disasm of the real 0x97b82d7c body. */
  return allocation;
}

/* _PPEmulatorProgramInitialiseHandleBanks @ 0x97b82dc4 (288 bytes) */
int _PPEmulatorProgramInitialiseHandleBanks(bank, bank0Max, bank1Max, bank2Max, bank3Max)
  int bank;
  int bank0Max;
  int bank1Max;
  int bank2Max;
  int bank3Max;
{
  int bankMax;
  uint handleMask;
  undefined4 allocation;
  uint loopIndex;
  int bitsLeft;
  
  loopIndex = 0;
  do {
    if (*(int *)(bank + 0x80) != 0) {
      _free(*(int *)(bank + 0x80));
    }
    *(undefined4 *)(bank + 0x80) = 0;
    *(undefined4 *)(bank + 0x84) = 0;
    *(undefined4 *)(bank + 0x88) = 0;
    bankMax = bank1Max;
    if (((((loopIndex == 1) || (bankMax = bank0Max, loopIndex == 0)) || (bankMax = bank2Max, loopIndex == 2)) ||
        (bankMax = bank3Max, loopIndex == 3)) && (bankMax != 0)) {
      bitsLeft = 0x20;
      do {
        if (bankMax << (0x20U - bitsLeft & 0x3f) < 0) {
          if (bitsLeft != 0) {
            handleMask = *(uint *)(bank + 0x88);
            do {
              handleMask = handleMask << 1 | 1;
              bitsLeft = bitsLeft + -1;
            } while (bitsLeft != 0);
            *(uint *)(bank + 0x88) = handleMask;
          }
          break;
        }
        bitsLeft = bitsLeft + -1;
      } while (bitsLeft != 0);
      handleMask = bankMax << 1 & ~*(uint *)(bank + 0x88);
      *(uint *)(bank + 0x84) = handleMask;
      allocation = _malloc(handleMask << 4);
      *(undefined4 *)(bank + 0x80) = allocation;
      _memset(allocation,0,*(int *)(bank + 0x84) << 4);
    }
    loopIndex = loopIndex + 1;
    bank = bank + 0xc;
    if (3 < loopIndex) {
      return;
    }
  } while( true );
}

/* _PPEmulatorProgramConvertFromPPStream @ 0x97b82ee4 (2768 bytes) */
int _PPEmulatorProgramConvertFromPPStream(emulator, ppStream)
  undefined4 *emulator;
  undefined4 *ppStream;
{
  int constDest;
  int constByteOffset;
  int constIndex;
  int opChunk;
  int constsLeft;
  int optionsLeft;
  int srcIndex;
  int constChunk;
  int optionChunk;
  uint opCount;
  int destBindingChunk;
  int srcBindingChunk;
  uint srcOperandLoop;
  undefined4 allocation;
  ushort operandOrdinal;
  byte fieldByte;
  uint workWord3;
  uint workWord4;
  int *optionList;
  int texChunk;
  int registerFileBase;
  undefined4 constWord3;
  uint *inst;
  undefined4 constWord2;
  undefined4 constWord1;
  int *constantList;
  uint workWord;
  uint workWord2;
  int *texBindingList;
  undefined4 outputBindingList;
  undefined4 paramBindingList;
  int attribBindingList;
  uint engineFlags;
  uint texUnit;
  int srcWordOffset;
  uint opIndex;
  uint registerAddr;
  int srcRecOffset;
  int texLeft;
  int *opList;
  uint *opHeader;
  
  registerAddr = 0;
  engineFlags = 0xf;
  emulator[0xe] = *ppStream;
  opList = (int *)ppStream[8];
  attribBindingList = ppStream[6];
  optionList = (int *)ppStream[0xc];
  texBindingList = (int *)ppStream[10];
  outputBindingList = ppStream[7];
  paramBindingList = ppStream[4];
  constantList = (int *)ppStream[0xb];
  opCount = opList[2];
  emulator[0xd] = 0;
  emulator[0x2f] = *(int *)(attribBindingList + 8) << 4;
  optionChunk = *optionList;
  for (optionsLeft = optionList[2]; optionsLeft != 0; optionsLeft = optionsLeft + -1) {
    if (*(char *)(optionChunk + 0xf) == '\x06') {
      emulator[0xb] = 1;
    }
    else if (*(char *)(optionChunk + 0xf) == '\a') {
      emulator[0xc] = 1;
    }
    optionChunk = *(int *)(optionChunk + 8);
  }
  if ((emulator[0xc] != 0) || (*(int *)PTR_DAT_a7b7c100 == 0)) {
    engineFlags = 7;
  }
  if ((emulator[0xb] != 0) ||
     ((*(int *)PTR_DAT_a7b7c100 == 0 && ((emulator[0xe] - 0x8b30 < 2 || (emulator[0xe] == 0x8804))))))
  {
    engineFlags = engineFlags & 0xfffffffd;
  }
  constsLeft = constantList[2];
  constChunk = *constantList;
  if (constsLeft != 0) {
    constIndex = 0;
    allocation = _malloc(constsLeft << 4);
    emulator[0x2c] = allocation;
    for (; constsLeft != 0; constsLeft = constsLeft + -1) {
      constByteOffset = constIndex * 0x10;
      constWord3 = *(undefined4 *)(constChunk + 0x18);
      constIndex = constIndex + 1;
      constWord1 = *(undefined4 *)(constChunk + 0x10);
      constWord2 = *(undefined4 *)(constChunk + 0x14);
      constDest = constByteOffset + emulator[0x2c];
      *(undefined4 *)(constByteOffset + emulator[0x2c]) = *(undefined4 *)(constChunk + 0xc);
      *(undefined4 *)(constDest + 0xc) = constWord3;
      *(undefined4 *)(constDest + 4) = constWord1;
      *(undefined4 *)(constDest + 8) = constWord2;
      constChunk = *(int *)(constChunk + 8);
    }
  }
  if (opCount != 0) {
    inst = (uint *)_calloc(0x11c,opCount);
    opIndex = 0;
    *emulator = inst;
    emulator[1] = inst + opCount * 0x47 + -0x47;
    opChunk = *opList;
    emulator[0x48] = inst;
    if (opCount != 0) {
      do {
        opHeader = (uint *)(opChunk + 0xc);
        *inst = *(uint *)(opChunk + 0xc) >> 0x12 & 0xff;
        *(byte *)(inst + 1) = (byte)(*(uint *)(opChunk + 0x10) >> 0x14) & 1;
        if (emulator[0xe] - 0x8b30 < 2) {
          *(byte *)((int)inst + 5) =
               ((byte)((uint)*(undefined4 *)(opChunk + 0x10) >> 0x1a) & 3) + 1;
        }
        else {
          *(undefined1 *)((int)inst + 5) = 4;
        }
        *(byte *)((int)inst + 6) = (byte)(*(uint *)(opChunk + 0x10) >> 0x16) & 1;
        inst[2] = *(uint *)(opChunk + 0x10) & 0x3ffff;
        inst[0x45] = *(uint *)(opChunk + 0x3c);
        if ((*opHeader & 0x3ffff) == 0) {
          emulator[0x48] = inst;
        }
        workWord = *inst;
        switch(workWord) {
        default:
          goto switchD_97b83138_caseD_0;
        case 1:
        case 0x11:
        case 0x13:
        case 0x14:
        case 0x2b:
        case 0x38:
        case 0x41:
          workWord = emulator[0xd] | 0x40;
          break;
        case 0x48:
          workWord = emulator[0xd] | 0x200;
        }
        emulator[0xd] = workWord;
        workWord = *inst;
switchD_97b83138_caseD_0:
        switch(workWord) {
        case 4:
        case 5:
        case 0x11:
        case 0x42:
        case 0x43:
        case 0x48:
          workWord = emulator[0xd] | 0x400;
          break;
        default:
          goto switchD_97b832a0_caseD_6;
        case 0x4b:
        case 0x4c:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
        case 0x59:
        case 0x5a:
        case 0x5b:
          workWord = emulator[0xd] | 0x800;
          break;
        case 0x4f:
          workWord = emulator[0xd] | 0x8000;
        }
        emulator[0xd] = workWord;
        workWord = *inst;
switchD_97b832a0_caseD_6:
        if (workWord == 0x4e) {
          *inst = 0x22;
        }
        workWord = *(uint *)(opChunk + 0x14) >> 0x11 & 7;
        if (workWord == 1) {
          *(undefined2 *)(inst + 7) = 0;
          emulator[0xd] = emulator[0xd] | 1;
          registerAddr = emulator[0x20] + (uint)*(ushort *)(opChunk + 0x1a) * 0x10;
        }
        else if (workWord == 3) {
          destBindingChunk = ((int (*)())_PPStreamChunkListChunkAtIndex)(outputBindingList,(uint)*(ushort *)(opChunk + 0x1a));
          if ((*(uint *)(destBindingChunk + 0xc) >> 0x10 & 0xf) == 7) {
            emulator[0xd] = emulator[0xd] | 0x2000;
            *(undefined2 *)(inst + 7) = 9;
          }
          else {
            *(undefined2 *)(inst + 7) = 1;
          }
          emulator[0xd] = emulator[0xd] | 2;
          registerAddr = emulator[0x23] + (uint)*(ushort *)(destBindingChunk + 0x12) * 0x10;
        }
        inst[3] = registerAddr;
        if (*(int *)(opChunk + 0x18) < 0) {
          *(undefined1 *)((int)inst + 0x1f) = 1;
          *(short *)(inst + 6) = (short)(char)((uint)(*(int *)(opChunk + 0x18) << 4) >> 0x18);
        }
        *(undefined1 *)((int)inst + 0x1e) = 0;
        if (emulator[0xe] - 0x8b30 < 2) {
          *(byte *)(inst + 5) = (byte)((uint)*(undefined4 *)(opChunk + 0x14) >> 8) & 3;
          *(byte *)((int)inst + 0x15) = (byte)(*(uint *)(opChunk + 0x14) >> 6) & 3;
          *(byte *)((int)inst + 0x16) = (byte)(*(uint *)(opChunk + 0x14) >> 4) & 3;
          *(byte *)((int)inst + 0x17) = (byte)(*(uint *)(opChunk + 0x14) >> 2) & 3;
        }
        else {
          *(undefined1 *)(inst + 5) = 0;
          *(undefined1 *)((int)inst + 0x15) = 1;
          *(undefined1 *)((int)inst + 0x16) = 2;
          *(undefined1 *)((int)inst + 0x17) = 3;
        }
        if (*(short *)(inst + 7) == 9) {
          fieldByte = 4;
LAB_97b835e0:
          *(byte *)(inst + 10) = fieldByte;
        }
        else {
          *(undefined1 *)(inst + 10) = 0xf;
          workWord = *(uint *)(opChunk + 0x14);
          if ((workWord & 0x2000) == 0) {
            *(undefined1 *)(inst + 10) = 0xe;
            workWord = *(uint *)(opChunk + 0x14);
          }
          if ((workWord & 0x4000) == 0) {
            *(byte *)(inst + 10) = *(byte *)(inst + 10) & 0xfd;
            workWord = *(uint *)(opChunk + 0x14);
          }
          if ((workWord & 0x8000) == 0) {
            *(byte *)(inst + 10) = *(byte *)(inst + 10) & 0xfb;
            workWord = *(uint *)(opChunk + 0x14);
          }
          if ((workWord & 0x10000) == 0) {
            fieldByte = *(byte *)(inst + 10) & 0xf7;
            goto LAB_97b835e0;
          }
        }
        if (emulator[0xe] - 0x8b30 < 2) {
          *(byte *)(inst + 8) = (byte)(*(uint *)(opChunk + 0x14) >> 0xc) & 1;
          *(byte *)((int)inst + 0x21) = ((byte)(*(uint *)(opChunk + 0x14) >> 10) & 3) + 1;
          workWord = *(uint *)(opChunk + 0x10) >> 0x17 & 7;
        }
        else {
          *(undefined1 *)(inst + 8) = 0;
          workWord = 1;
          *(undefined1 *)((int)inst + 0x21) = 4;
        }
        inst[9] = workWord;
        workWord2 = *inst;
        *(byte *)((int)inst + 0x29) = (byte)((uint)*(undefined4 *)(opChunk + 0x14) >> 0x1c) & 7;
        *(byte *)((int)inst + 0x2a) = (byte)((uint)*(undefined4 *)(opChunk + 0x14) >> 0x1a) & 3;
        *(byte *)((int)inst + 0x2b) = (byte)((uint)*(undefined4 *)(opChunk + 0x14) >> 0x18) & 3;
        *(byte *)(inst + 0xb) = (byte)(*(uint *)(opChunk + 0x14) >> 0x16) & 3;
        *(byte *)((int)inst + 0x2d) = (byte)(*(uint *)(opChunk + 0x14) >> 0x14) & 3;
        workWord = *opHeader >> 0x1d;
        inst[0xc] = workWord;
        if (workWord2 == 0x41) {
          workWord3 = 1;
LAB_97b83714:
          inst[0xc] = workWord3;
        }
        else if (workWord2 == 0x6d) {
          workWord = 3;
          inst[0xc] = 3;
          workWord2 = *(uint *)(opChunk + 0x18);
          workWord3 = *(uint *)(opChunk + 0x14);
          *(uint *)(opChunk + 0x2c) = workWord2 & 0x80000000 | *(uint *)(opChunk + 0x2c) & 0x7fffffff;
          *(char *)(opChunk + 0x2f) = (char)(workWord2 >> 0x14);
          *(short *)(opChunk + 0x32) = (short)workWord2;
          *(uint *)(opChunk + 0x2c) =
               (workWord3 >> 10 & 3) << 0xc |
               (workWord3 >> 0xc & 1) << 0xe |
               (workWord3 >> 0x11 & 7) << 0x17 | *(uint *)(opChunk + 0x2c) & 0xfc080fff | 0xd8000;
          workWord2 = *inst;
        }
        else if (workWord2 - 0x42 < 4) {
          workWord3 = workWord - 1;
          goto LAB_97b83714;
        }
        srcOperandLoop = 0;
        srcIndex = 0;
        if (workWord != 0) {
          do {
            if (workWord2 == 0x41) {
              if (srcOperandLoop != 1) goto LAB_97b837e4;
              *(byte *)(inst + srcIndex * 9 + 0xf) = (byte)(*(uint *)(opChunk + 0x24) >> 0xc) & 0xf;
              *(byte *)((int)inst + srcIndex * 0x24 + 0x3d) =
                   (byte)((uint)*(undefined4 *)(opChunk + 0x24) >> 8) & 0xf;
              *(byte *)((int)inst + srcIndex * 0x24 + 0x3e) =
                   (byte)(*(uint *)(opChunk + 0x24) >> 4) & 0xf;
              *(byte *)((int)inst + srcIndex * 0x24 + 0x3f) =
                   (byte)*(undefined4 *)(opChunk + 0x24) & 0xf;
              goto LAB_97b83af4;
            }
            if ((0x40 < workWord2) && (workWord2 < 0x46)) {
              if (1 < emulator[0xe] - 0x8b30) {
                if (srcOperandLoop == 1) {
                  inst[0x44] = *(uint *)(opChunk + 0x24) >> 5 & 7;
                  workWord4 = *(uint *)(opChunk + 0x24);
                  goto LAB_97b83794;
                }
                goto LAB_97b837e4;
              }
              if (srcOperandLoop != 2) goto LAB_97b837e4;
              inst[0x44] = *(uint *)(opChunk + 0x2c) >> 5 & 7;
              workWord4 = *(uint *)(opChunk + 0x2c);
LAB_97b83794:
              srcIndex = srcIndex + -1;
              inst[0x43] = workWord4 & 0x1f;
              goto LAB_97b83af8;
            }
LAB_97b837e4:
            srcRecOffset = srcIndex * 0x24;
            srcWordOffset = srcOperandLoop * 8;
            inst[srcIndex * 9 + 0x13] = 1;
            workWord2 = opHeader[srcOperandLoop * 2 + 4] >> 0x17 & 7;
            if (workWord2 == 1) {
              *(undefined2 *)(inst + srcIndex * 9 + 0x11) = 0;
              registerFileBase = emulator[0x20];
              emulator[0xd] = emulator[0xd] | 1;
              operandOrdinal = *(ushort *)((int)opHeader + srcWordOffset + 0x16);
              inst[srcIndex * 9 + 0xe] = 0;
              registerAddr = registerFileBase + (uint)operandOrdinal * 0x10;
              goto LAB_97b839f4;
            }
            if (1 < workWord2) {
              if (workWord2 == 2) {
                srcBindingChunk = ((int (*)())_PPStreamChunkListChunkAtIndex)(paramBindingList,(uint)*(ushort *)((int)opHeader + srcWordOffset + 0x16));
                registerAddr = *(uint *)(srcBindingChunk + 0xc) >> 0x10 & 0x1f;
                if (registerAddr == 1) {
                  *(undefined2 *)(inst + srcIndex * 9 + 0x11) = 5;
                  registerFileBase = emulator[0x29];
                  registerAddr = emulator[0xd] | 0x20;
                }
                else if (registerAddr == 0x11) {
                  *(undefined2 *)(inst + srcIndex * 9 + 0x11) = 3;
                  registerFileBase = emulator[0x29];
                  registerAddr = emulator[0xd] | 8;
                }
                else {
                  *(undefined2 *)(inst + srcIndex * 9 + 0x11) = 4;
                  registerFileBase = emulator[0x29];
                  registerAddr = emulator[0xd] | 0x10;
                }
                emulator[0xd] = registerAddr;
                registerAddr = registerFileBase + (uint)*(ushort *)(srcBindingChunk + 0x12) * 0x10;
                inst[srcIndex * 9 + 0xe] = 3;
                inst[srcIndex * 9 + 0x13] = *(uint *)(srcBindingChunk + 0xc) >> 0x1a & 7;
              }
              goto LAB_97b839f4;
            }
            if (workWord2 != 0) goto LAB_97b839f4;
            srcBindingChunk = ((int (*)())_PPStreamChunkListChunkAtIndex)(attribBindingList,(uint)*(ushort *)((int)opHeader + srcWordOffset + 0x16));
            *(undefined2 *)(inst + srcIndex * 9 + 0x11) = 2;
            switch(*(uint *)(srcBindingChunk + 0xc) >> 0x10 & 0xf) {
            default:
              goto switchD_97b83930_caseD_0;
            case 1:
              registerAddr = emulator[0xd] | 0x10080;
              break;
            case 2:
              registerAddr = emulator[0xd] | 0x20000;
              break;
            case 3:
              registerAddr = emulator[0xd] | 0x40000;
              break;
            case 5:
              registerAddr = emulator[0xd] | 0x80000;
              break;
            case 7:
              emulator[0xd] = emulator[0xd] | 1 << (*(uint *)(srcBindingChunk + 0xc) & 0x1f) + 0x14;
              goto switchD_97b83930_caseD_0;
            case 9:
              if ((*(uint *)(srcBindingChunk + 0xc) & 0x1f) == 0) {
                registerAddr = emulator[0xd] | 0x100;
                break;
              }
              goto switchD_97b83930_caseD_0;
            }
            emulator[0xd] = registerAddr;
switchD_97b83930_caseD_0:
            registerFileBase = emulator[0x26];
            emulator[0xd] = emulator[0xd] | 4;
            operandOrdinal = *(ushort *)(srcBindingChunk + 0x12);
            inst[srcIndex * 9 + 0xe] = 2;
            registerAddr = registerFileBase + (uint)operandOrdinal * 0x10;
LAB_97b839f4:
            inst[srcIndex * 9 + 0xd] = registerAddr;
            workWord2 = opHeader[srcOperandLoop * 2 + 4];
            if ((int)workWord2 < 0) {
              *(undefined1 *)((int)inst + srcRecOffset + 0x47) = 1;
              *(short *)(inst + srcIndex * 9 + 0x10) = (short)(char)opHeader[srcOperandLoop * 2 + 4];
              workWord2 = opHeader[srcOperandLoop * 2 + 4];
            }
            *(byte *)((int)inst + srcRecOffset + 0x46) = (byte)(workWord2 >> 0x1b) & 1;
            *(undefined1 *)(inst + srcIndex * 9 + 0x14) = 0xf;
            if (emulator[0xe] - 0x8b30 < 2) {
              *(byte *)(inst + srcIndex * 9 + 0x12) = (byte)(opHeader[srcOperandLoop * 2 + 4] >> 0xe) & 1;
              *(byte *)((int)inst + srcRecOffset + 0x49) =
                   ((byte)(opHeader[srcOperandLoop * 2 + 4] >> 0xc) & 3) + 1;
            }
            else {
              *(undefined1 *)((int)inst + srcRecOffset + 0x49) = 4;
              *(undefined1 *)(inst + srcIndex * 9 + 0x12) = 0;
            }
            if (*(char *)((int)inst + srcRecOffset + 0x49) == '\x01') {
              *(byte *)(inst + srcIndex * 9 + 0xf) = (byte)(opHeader[srcOperandLoop * 2 + 4] >> 0x15) & 3;
              *(byte *)((int)inst + srcRecOffset + 0x3d) = (byte)(opHeader[srcOperandLoop * 2 + 4] >> 0x15) & 3;
              *(byte *)((int)inst + srcRecOffset + 0x3e) = (byte)(opHeader[srcOperandLoop * 2 + 4] >> 0x15) & 3;
              fieldByte = (byte)(opHeader[srcOperandLoop * 2 + 4] >> 0x15);
            }
            else {
              *(byte *)(inst + srcIndex * 9 + 0xf) = (byte)(opHeader[srcOperandLoop * 2 + 4] >> 0x15) & 3;
              *(byte *)((int)inst + srcRecOffset + 0x3d) = (byte)(opHeader[srcOperandLoop * 2 + 4] >> 0x13) & 3;
              *(byte *)((int)inst + srcRecOffset + 0x3e) = (byte)(opHeader[srcOperandLoop * 2 + 4] >> 0x11) & 3;
              fieldByte = (byte)(opHeader[srcOperandLoop * 2 + 4] >> 0xf);
            }
            *(byte *)((int)inst + srcRecOffset + 0x3f) = fieldByte & 3;
LAB_97b83af4:
            workWord2 = *inst;
LAB_97b83af8:
            srcOperandLoop = srcOperandLoop + 1;
            srcIndex = srcIndex + 1;
          } while (srcOperandLoop < workWord);
        }
        if (engineFlags != 0) {
          switch(workWord2) {
          case 0xf:
          case 0x1b:
          case 0x1c:
          case 0x1d:
          case 0x1e:
          case 0x4a:
          case 0x4c:
          case 0x4f:
          case 0x56:
          case 0x57:
          case 0x5a:
          case 0x5b:
            engineFlags = engineFlags & 0xfffffffd;
          }
        }
        switch(workWord2) {
        case 0x4a:
        case 0x56:
        case 0x57:
        case 0x5a:
        case 0x5b:
          engineFlags = 0;
        }
        opHeader = inst + 0x47;
        opChunk = *(int *)(opChunk + 8);
        if (inst == (uint *)emulator[1]) {
          opHeader = (uint *)0x0;
        }
        opIndex = opIndex + 1;
        inst = opHeader;
      } while (opIndex < opCount);
    }
    if ((emulator[0xe] == 0x8804) || (emulator[0xe] == 0x8b30)) {
      texChunk = *texBindingList;
      for (texLeft = texBindingList[2]; texLeft != 0; texLeft = texLeft + -1) {
        emulator[0xf] = emulator[0xf] | 1 << (*(uint *)(texChunk + 0xc) >> 0x18 & 7);
        texUnit = *(uint *)(texChunk + 0xc) >> 0x18 & 7;
        if (texUnit == 2) {
          texUnit = emulator[0xd] | 0x1000;
LAB_97b83d90:
          emulator[0xd] = texUnit;
        }
        else if (texUnit == 1) {
          texUnit = emulator[0xd] | 0x4000;
          goto LAB_97b83d90;
        }
        registerAddr = *(uint *)(texChunk + 0xc);
        texUnit = registerAddr >> 0x15 & 0x38;
        *(undefined4 *)((int)emulator + texUnit + 0x44) = *(undefined4 *)(texChunk + 0x10);
        *(uint *)((int)emulator + texUnit + 0x40) = registerAddr;
        texChunk = *(int *)(texChunk + 8);
      }
    }
    if ((emulator[0xd] & 0x800) != 0) {
      engineFlags = engineFlags & 0xfffffffb;
    }
    emulator[0x49] = engineFlags;
  }
  return;
}

/* _PPStreamChunkListChunkAtIndex @ 0x97b83ddc (152 bytes) */
int _PPStreamChunkListChunkAtIndex(chunkList, index)
  undefined4 *chunkList;
  uint index;
{
  uint chunkIndex;
  undefined1 *chunk;
  uint position;
  
  position = 0;
  for (chunk = (undefined1 *)*chunkList; chunk != (undefined1 *)0x0;
      chunk = *(undefined1 **)(chunk + 8)) {
    switch(*chunk) {
    case 0:
    case 2:
    case 3:
    case 4:
      chunkIndex = (uint)*(ushort *)(chunk + 0x12);
      break;
    case 1:
      chunkIndex = *(uint *)(chunk + 0xc);
      break;
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
      chunkIndex = position;
      break;
    case 8:
      chunkIndex = *(uint *)(chunk + 0xc) & 0x3ffff;
      break;
    case 0xb:
      goto LAB_97b83e9c;
    default:
      goto switchD_97b83e20_default;
    }
    if (chunkIndex == index) {
      return chunk;
    }
switchD_97b83e20_default:
    position = position + 1;
  }
LAB_97b83e9c:
  return (undefined1 *)0x0;
}

/* _PPParserFree @ 0x97b83ea4 (48 bytes) */
int _PPParserFree(parser)
  undefined4 parser;
{
  ((int (*)())_PPParserShutdown)(parser);
  return _free(parser);
}

/* _PPParserShutdown @ 0x97b83ed4 (88 bytes) */
int _PPParserShutdown(parser)
  int parser;
{
  int scope;
  undefined4 ppParserAttachStringResult;
  
  scope = *(int *)(parser + 0x448);
  while (scope != 0) {
    ((int (*)())_PPParserRemoveScope)(parser,scope);
    scope = *(int *)(parser + 0x448);
  }
  ppParserAttachStringResult = _PPParserAttachString(parser,0,0);
  return ppParserAttachStringResult;
}

/* _PPParserRemoveScope @ 0x97b83f2c (68 bytes) */
int _PPParserRemoveScope(parser, scope)
  int parser;
  int scope;
{
  int prev;
  
  prev = *(int *)(scope + 0x1c);
  if (prev == 0) {
    *(undefined4 *)(parser + 0x448) = *(undefined4 *)(scope + 0x20);
    prev = *(int *)(scope + 0x1c);
  }
  else {
    *(undefined4 *)(prev + 0x20) = *(undefined4 *)(scope + 0x20);
  }
  if (*(int *)(scope + 0x20) == 0) {
    *(int *)(parser + 0x44c) = prev;
  }
  else {
    *(int *)(*(int *)(scope + 0x20) + 0x1c) = prev;
  }
  return ((int (*)())_PPParserScopeFree)(scope);
}

/* _PPParserScopeFree @ 0x97b83f70 (116 bytes) */
int _PPParserScopeFree(scope)
  int *scope;
{
  int entry;
  
  entry = *scope;
  while (entry != 0) {
    ((int (*)())_PPParserScopeRemoveIdentifier)(scope,entry);
    entry = *scope;
  }
  entry = scope[2];
  while (entry != 0) {
    ((int (*)())_PPParserScopeRemoveMacro)(scope,entry);
    entry = scope[2];
  }
  return _free(scope);
}

/* _PPParserScopeRemoveIdentifier @ 0x97b83fe4 (68 bytes) */
int _PPParserScopeRemoveIdentifier(scope, identifier)
  undefined4 *scope;
  int identifier;
{
  int prev;
  
  prev = *(int *)(identifier + 0x1c);
  if (prev == 0) {
    *scope = *(undefined4 *)(identifier + 0x20);
    prev = *(int *)(identifier + 0x1c);
  }
  else {
    *(undefined4 *)(prev + 0x20) = *(undefined4 *)(identifier + 0x20);
  }
  if (*(int *)(identifier + 0x20) == 0) {
    scope[1] = prev;
  }
  else {
    *(int *)(*(int *)(identifier + 0x20) + 0x1c) = prev;
  }
  return ((int (*)())_PPParserIdentifierFree)(identifier);
}

/* _PPParserIdentifierFree @ 0x97b84028 (52 bytes) */
int _PPParserIdentifierFree(parser)
  undefined4 parser;
{
  _PPParserIdentifierSetName(parser,0);
  return _free(parser);
}

/* _PPParserScopeRemoveMacro @ 0x97b8405c (68 bytes) */
int _PPParserScopeRemoveMacro(scope, macro)
  int scope;
  int macro;
{
  int prev;
  
  prev = *(int *)(macro + 0x18);
  if (prev == 0) {
    *(undefined4 *)(scope + 8) = *(undefined4 *)(macro + 0x1c);
    prev = *(int *)(macro + 0x18);
  }
  else {
    *(undefined4 *)(prev + 0x1c) = *(undefined4 *)(macro + 0x1c);
  }
  if (*(int *)(macro + 0x1c) == 0) {
    *(int *)(scope + 0xc) = prev;
  }
  else {
    *(int *)(*(int *)(macro + 0x1c) + 0x18) = prev;
  }
  return ((int (*)())_PPParserMacroFree)(macro);
}

/* _PPParserMacroFree @ 0x97b840a0 (144 bytes) */
int _PPParserMacroFree(macro)
  undefined4 *macro;
{
  uint paramCount;
  int paramString;
  int paramArray;
  uint loopIndex;
  
  loopIndex = 0;
  _free(*macro);
  _free(macro[1]);
  paramCount = macro[2];
  if (paramCount == 0) {
    paramArray = macro[3];
  }
  else {
    paramArray = macro[3];
    do {
      paramString = *(int *)(loopIndex * 4 + paramArray);
      if (paramString != 0) {
        _free(paramString);
        paramCount = macro[2];
        paramArray = macro[3];
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < paramCount);
  }
  if (paramArray != 0) {
    _free(paramArray);
  }
  return _free(macro);
}

/* _PPParserGetScalars @ 0x97b84130 (200 bytes) */
int _PPParserGetScalars(parser, values, count)
  undefined4 parser;
  float *values;
  int count;
{
  int part;
  int loopIndex;
  double glp_strtodResult;
  char partBuf [256];
  char *numberEnd [5];
  
  loopIndex = 0;
  while( true ) {
    part = _PPParserGetPart(parser,partBuf,1);
    if (part == 0) {
      return 0x2d;
    }
    glp_strtodResult = (double)((double (*)())_glp_strtod)(partBuf,numberEnd);
    *values = (float)glp_strtodResult;
    if (numberEnd[0] != partBuf + part) {
      return 0x15;
    }
    loopIndex = loopIndex + 1;
    values = values + 1;
    if (loopIndex == count) {
      return 0;
    }
    part = _PPParserGetPart(parser,partBuf,0);
    if (part == 0) break;
    if (partBuf[0] != ',') {
      _PPParserReturnPart(parser);
      return 0;
    }
  }
  return 0x2d;
}

/* _PPStreamAddConstant @ 0x97b841f8 (108 bytes) */
int _PPStreamAddConstant(stream, constant)
  int stream;
  undefined4 *constant;
{
  undefined4 constantW;
  undefined4 constantX;
  undefined4 constantY;
  undefined4 constantZ;
  undefined1 *allocation;
  undefined4 constantList;
  
  allocation = (undefined1 *)_calloc(0x1c,1);
  constantW = constant[3];
  constantList = *(undefined4 *)(stream + 0x2c);
  constantX = *constant;
  constantY = constant[1];
  constantZ = constant[2];
  *allocation = 10;
  *(undefined4 *)(allocation + 0xc) = constantX;
  *(undefined4 *)(allocation + 0x10) = constantY;
  *(undefined4 *)(allocation + 0x14) = constantZ;
  *(undefined4 *)(allocation + 0x18) = constantW;
  return _PPStreamChunkListAddChunk(constantList,allocation);
}

/* _PPParserParseTempDeclaration @ 0x97b84264 (468 bytes) */
int _PPParserParseTempDeclaration(parser, tempMode)
  int parser;
  int tempMode;
{
  int ppParserIdentifierCreateResult;
  int ppParserValidateNameResult;
  int arrayResult;
  int part;
  int part2;
  int scope;
  int ppParserScopeAddIdentifierResult;
  uint tempCount;
  uint loopIndex;
  char partBuf [256];
  int usageModeWord;
  uint usageOrdinal;
  undefined4 usageWord2;
  undefined4 usageWord3;
  undefined4 arrayIndex [6];
  
  arrayIndex[0] = 0;
  tempCount = 0;
  do {
    part2 = _PPParserGetPart(parser,partBuf,0);
    if (part2 == 0) {
      return 0x2d;
    }
    ppParserValidateNameResult = _PPParserValidateName(parser,partBuf);
    if (ppParserValidateNameResult != 0) {
      return 0x12;
    }
    ppParserIdentifierCreateResult = _PPParserIdentifierCreate();
    _PPParserIdentifierSetName(ppParserIdentifierCreateResult,partBuf);
    *(undefined4 *)(ppParserIdentifierCreateResult + 0xc) = 1;
    *(int *)(ppParserIdentifierCreateResult + 0x14) = tempMode;
    *(uint *)(ppParserIdentifierCreateResult + 8) = *(int *)(*(int *)(parser + 0x44c) + 0x14) + tempCount;
    ppParserScopeAddIdentifierResult = _PPParserScopeAddIdentifier(*(undefined4 *)(parser + 0x44c),ppParserIdentifierCreateResult);
    if (ppParserScopeAddIdentifierResult != 0) {
      ((int (*)())_PPParserIdentifierFree)(ppParserIdentifierCreateResult);
      return 0x1c;
    }
    part = _PPParserGetPart(parser,partBuf,0);
    if (part == 0) {
      return 0x2d;
    }
    if (partBuf[0] == '[') {
      _PPParserReturnPart(parser);
      arrayResult = _PPParserParseArray(parser,arrayIndex);
      if (arrayResult != 0) {
        return arrayResult;
      }
      *(undefined1 *)(ppParserIdentifierCreateResult + 0x10) = 1;
      *(undefined4 *)(ppParserIdentifierCreateResult + 4) = arrayIndex[0];
      part = _PPParserGetPart(parser,partBuf,0);
      if (part == 0) {
        return 0x2d;
      }
    }
    tempCount = tempCount + *(int *)(ppParserIdentifierCreateResult + 4);
    if (partBuf[0] == ';') {
      scope = *(int *)(parser + 0x44c);
      if (*(uint *)(parser + 0x460) < *(int *)(scope + 0x14) + tempCount) {
        return 0x33;
      }
      loopIndex = 0;
      if (tempCount != 0) {
        while( true ) {
          loopIndex = loopIndex + 1;
          usageWord3 = 0;
          usageWord2 = 0;
          usageModeWord = tempMode << 0x1d;
          usageOrdinal = (uint)*(ushort *)(scope + 0x16);
          ((int (*)())_PPStreamAddTempUsage)(*(undefined4 *)(parser + 0x1c),&usageModeWord);
          *(int *)(*(int *)(parser + 0x44c) + 0x14) =
               *(int *)(*(int *)(parser + 0x44c) + 0x14) + 1;
          if (tempCount <= loopIndex) break;
          scope = *(int *)(parser + 0x44c);
        }
      }
      return 0;
    }
  } while (partBuf[0] == ',');
  return 0x1f;
}

/* _PPParserParseSourceSwizzle @ 0x97b84438 (396 bytes) */
int _PPParserParseSourceSwizzle(parser, operand, swizzleGiven)
  int parser;
  uint *operand;
  undefined4 *swizzleGiven;
{
  undefined4 status;
  uint operandWord;
  int component;
  int part;
  int charIndex;
  uint swizzleSets;
  uint loopIndex;
  undefined1 partBuf [256];
  
  part = _PPParserGetPart(parser,partBuf,0);
  swizzleSets = 0;
  status = 0x2d;
  if (part != 0) {
    if (part != 1) {
      if (part != 4) {
        return 0xd;
      }
    }
    else {
      *swizzleGiven = 1;
    }
    loopIndex = 0;
    charIndex = 0;
    do {
      switch(partBuf[charIndex]) {
      case 0x61:
        swizzleSets = swizzleSets | 2;
        break;
      case 0x62:
        swizzleSets = swizzleSets | 2;
        goto LAB_97b84574;
      default:
        goto switchD_97b844cc_caseD_63;
      case 0x67:
        swizzleSets = swizzleSets | 2;
        goto LAB_97b84568;
      case 0x72:
        swizzleSets = swizzleSets | 2;
        goto LAB_97b8455c;
      case 0x77:
        swizzleSets = swizzleSets | 1;
        break;
      case 0x78:
        swizzleSets = swizzleSets | 1;
LAB_97b8455c:
        component = 0;
        goto LAB_97b84584;
      case 0x79:
        swizzleSets = swizzleSets | 1;
LAB_97b84568:
        component = 1;
        goto LAB_97b84584;
      case 0x7a:
        swizzleSets = swizzleSets | 1;
LAB_97b84574:
        component = 2;
        goto LAB_97b84584;
      }
      component = 3;
LAB_97b84584:
      if (loopIndex == 1) {
        operandWord = component << 0x13 | *operand & 0xffe7ffff;
LAB_97b845d4:
        *operand = operandWord;
      }
      else {
        if (loopIndex == 0) {
          operandWord = component << 0x15 | *operand & 0xff9fffff;
          goto LAB_97b845d4;
        }
        if (loopIndex == 2) {
          operandWord = component << 0x11 | *operand & 0xfff9ffff;
          goto LAB_97b845d4;
        }
        if (loopIndex == 3) {
          operandWord = component << 0xf | *operand & 0xfffe7fff;
          goto LAB_97b845d4;
        }
      }
      if (part != 1) {
        charIndex = charIndex + 1;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 4);
    if ((swizzleSets == 3) || ((swizzleSets == 2 && ((*(uint *)(parser + 0x48c) & 2) == 0)))) {
switchD_97b844cc_caseD_63:
      status = 0xd;
    }
    else {
      status = 0;
    }
  }
  return status;
}

/* _PPParserParseDestinationMask @ 0x97b8462c (412 bytes) */
int _PPParserParseDestinationMask(parser, operand)
  int parser;
  uint *operand;
{
  uint maskWord;
  uint part;
  undefined4 status;
  uint loopIndex;
  uint swizzleSets;
  undefined1 partBuf [260];
  
  part = _PPParserGetPart(parser,partBuf,0);
  swizzleSets = 0;
  status = 0x2d;
  if (part != 0) {
    loopIndex = 0;
    *operand = *operand & 0xfffe1fff;
    if (part != 0) {
      do {
        switch(partBuf[loopIndex]) {
        case 0x61:
          if ((*operand & 0x10000) != 0) {
            return 0xc;
          }
          maskWord = *operand | 0x10000;
          break;
        case 0x62:
          if ((*operand & 0x8000) != 0) {
            return 0xc;
          }
          maskWord = *operand | 0x8000;
          break;
        default:
          goto LAB_97b8481c;
        case 0x67:
          if ((*operand & 0x4000) != 0) {
            return 0xc;
          }
          maskWord = *operand | 0x4000;
          break;
        case 0x72:
          if ((*operand & 0x2000) != 0) {
            return 0xc;
          }
          maskWord = *operand | 0x2000;
          break;
        case 0x77:
          if ((*operand & 0x10000) != 0) {
            return 0xc;
          }
          maskWord = *operand | 0x10000;
          goto LAB_97b84778;
        case 0x78:
          if ((*operand & 0x2000) != 0) {
            return 0xc;
          }
          maskWord = *operand | 0x2000;
          goto LAB_97b84778;
        case 0x79:
          if ((*operand & 0x4000) != 0) {
            return 0xc;
          }
          maskWord = *operand | 0x4000;
          goto LAB_97b84778;
        case 0x7a:
          if ((*operand & 0x8000) != 0) {
            return 0xc;
          }
          maskWord = *operand | 0x8000;
LAB_97b84778:
          *operand = maskWord;
          swizzleSets = swizzleSets | 1;
          goto LAB_97b847e8;
        }
        *operand = maskWord;
        swizzleSets = swizzleSets | 2;
LAB_97b847e8:
        loopIndex = loopIndex + 1;
      } while (loopIndex < part);
      if ((swizzleSets == 3) || ((swizzleSets == 2 && ((*(uint *)(parser + 0x48c) & 2) == 0)))) {
LAB_97b8481c:
        return 0xc;
      }
    }
    status = 0;
  }
  return status;
}

/* _PPParserParseTextureSourceVar @ 0x97b84830 (704 bytes) */
int _PPParserParseTextureSourceVar(parser, operand)
  int parser;
  uint *operand;
{
  int arrayResult;
  int compareResult;
  int part;
  uint unit;
  int shift;
  int status;
  uint ashldi3Result;
  uint currentUnitBits;
  uint clearMaskLo;
  uint newTargetBitsLo;
  uint unitTargetsLo;
  uint unitTargetsHi;
  uint targetCode;
  char partBuf [256];
  uint arrayIndex [6];
  
  part = _PPParserGetPart(parser,partBuf,0);
  status = 0x2d;
  if (part != 0) {
    compareResult = _memcmp(partBuf,"texture",8);
    status = 0xe;
    if (compareResult == 0) {
      part = _PPParserGetPart(parser,partBuf,0);
      status = 0x2d;
      if (part != 0) {
        if (partBuf[0] == '[') {
          _PPParserReturnPart(parser);
          arrayResult = _PPParserParseArray(parser,arrayIndex);
          if (arrayResult != 0) {
            return arrayResult;
          }
          if (*(uint *)(parser + 0x474) <= arrayIndex[0]) {
            return 0x38;
          }
          part = _PPParserGetPart(parser,partBuf,0);
          if (part == 0) {
            return 0x2d;
          }
        }
        else {
          arrayIndex[0] = 0;
        }
        status = 0x1f;
        if (partBuf[0] == ',') {
          part = _PPParserGetPart(parser,partBuf,0);
          unit = arrayIndex[0];
          status = 0x2d;
          if (part != 0) {
            unitTargetsLo = *(uint *)(parser + 0x34);
            unitTargetsHi = *(uint *)(parser + 0x38);
            ((int (*)())___lshrdi3)(unitTargetsLo,unitTargetsHi,arrayIndex[0] << 2);
            compareResult = _memcmp(partBuf,"CUBE",5);
            targetCode = 0;
            if (compareResult != 0) {
              compareResult = _memcmp(partBuf,"3D",3);
              targetCode = 1;
              if (compareResult != 0) {
                compareResult = _memcmp(partBuf,"RECT",5);
                targetCode = 2;
                if (compareResult != 0) {
                  compareResult = _memcmp(partBuf,"2D",3);
                  targetCode = 3;
                  if (compareResult != 0) {
                    compareResult = _memcmp(partBuf,"1D",3);
                    targetCode = 4;
                    if (compareResult != 0) {
                      compareResult = _memcmp(partBuf,"SHADOWRECT",0xb);
                      targetCode = 5;
                      if (compareResult != 0) {
                        compareResult = _memcmp(partBuf,"SHADOW2D",9);
                        targetCode = 6;
                        if (compareResult != 0) {
                          compareResult = _memcmp(partBuf,"SHADOW1D",9);
                          targetCode = 7;
                          if (compareResult != 0) {
                            return 0xe;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            if ((currentUnitBits & 0xf) == 0xf) {
              shift = unit << 2;
              ashldi3Result = ((int (*)())___ashldi3)(0,0xf,shift);
              unitTargetsLo = unitTargetsLo & ~ashldi3Result;
              unitTargetsHi = unitTargetsHi & ~clearMaskLo;
              *(uint *)(parser + 0x34) = unitTargetsLo;
              *(uint *)(parser + 0x38) = unitTargetsHi;
              ashldi3Result = ((int (*)())___ashldi3)(0,targetCode,shift);
              *(uint *)(parser + 0x34) = unitTargetsLo | ashldi3Result;
              *(uint *)(parser + 0x38) = unitTargetsHi | newTargetBitsLo;
            }
            else if ((currentUnitBits & 0xf) != targetCode) {
              return 0x28;
            }
            status = 0;
            *operand = unit & 0x1f | targetCode << 5 | *operand & 0xffffff00;
          }
        }
      }
    }
  }
  return status;
}

/* ___lshrdi3 @ 0x97b84af0 (96 bytes) */
undefined8 ___lshrdi3(valueHi, valueLo, shift)
  uint valueHi;
  uint valueLo;
  uint shift;
{
  uint complementOrResultHi;
  undefined4 resultLo;
  
  if (shift == 0) {
    return CONCAT44(valueLo,valueHi);
  }
  complementOrResultHi = 0x20 - shift;
  if ((int)complementOrResultHi < 1) {
    complementOrResultHi = valueHi >> (-complementOrResultHi & 0x3f);
    resultLo = 0;
  }
  else {
    resultLo = valueHi >> (shift & 0x3f);
    complementOrResultHi = valueLo >> (shift & 0x3f) | valueHi << (complementOrResultHi & 0x3f);
  }
  return CONCAT44(complementOrResultHi,resultLo);
}

/* ___ashldi3 @ 0x97b84b50 (96 bytes) */
undefined8 ___ashldi3(valueHi, valueLo, shift)
  int valueHi;
  uint valueLo;
  uint shift;
{
  uint complementOrResultHi;
  undefined4 resultLo;
  
  if (shift == 0) {
    return CONCAT44(valueLo,valueHi);
  }
  complementOrResultHi = 0x20 - shift;
  if ((int)complementOrResultHi < 1) {
    complementOrResultHi = valueLo << (-complementOrResultHi & 0x3f);
    resultLo = 0;
  }
  else {
    resultLo = valueLo << (shift & 0x3f);
    complementOrResultHi = valueHi << (shift & 0x3f) | valueLo >> (complementOrResultHi & 0x3f);
  }
  return CONCAT44(resultLo,complementOrResultHi);
}

/* _PPStreamGetTexOperationCount @ 0x97b84bb0 (60 bytes) */
int _PPStreamGetTexOperationCount(stream)
  int stream;
{
  int count;
  int opChunk;
  
  count = 0;
  opChunk = **(int **)(stream + 0x20);
  if (opChunk != 0) {
    do {
      if ((*(uint *)(opChunk + 0xc) >> 0x12 & 0xff) - 0x42 < 3) {
        count = count + 1;
      }
      opChunk = *(int *)(opChunk + 8);
    } while (opChunk != 0);
    return count;
  }
  return count;
}

/* _PPEmulatorFree @ 0x97b84bec (60 bytes) */
int _PPEmulatorFree(emulator)
  int emulator;
{
  _InterpreterFree(*(undefined4 *)(emulator + 0xdf0));
  _free(*(undefined4 *)(emulator + 0xd84));
  return _free(emulator);
}

/* _PPStreamFree @ 0x97b84c28 (140 bytes) */
int _PPStreamFree(stream)
  int stream;
{
  undefined4 r3Out;
  
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 4));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 8));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0xc));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x10));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x14));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x18));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x1c));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x20));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x24));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x2c));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x28));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x30));
  _free(stream);
  return r3Out;
}

/* _PPEmulatorProgramFree @ 0x97b84cb4 (180 bytes) */
int _PPEmulatorProgramFree(emulator)
  int *emulator;
{
  if (emulator[7] != 0) {
    _glpDCBFree(emulator[7]);
  }
  if (emulator[8] != 0) {
    _glpDCBFree(emulator[8]);
  }
  if (emulator[5] != 0) {
    _glpDCBFree(emulator[5]);
  }
  if (emulator[6] != 0) {
    _glpDCBFree(emulator[6]);
  }
  if (*emulator != 0) {
    _free(*emulator);
    *emulator = 0;
  }
  if (emulator[0x2c] != 0) {
    _free(emulator[0x2c]);
    emulator[0x2c] = 0;
  }
  ((int (*)())_PPEmulatorProgramInitialiseHandleBanks)(emulator,0,0,0,0);
  return _free(emulator);
}

/* _PPParserParseAliasDeclaration @ 0x97b84d68 (368 bytes) */
int _PPParserParseAliasDeclaration(parser)
  int parser;
{
  int part3;
  int allocation;
  int part;
  undefined4 status;
  int bodyLength;
  undefined4 ppParserMacroCreateResult;
  int writePos;
  int part2;
  char partBuf [256];
  undefined4 savedPos;
  undefined4 savedLine;
  
  part = _PPParserGetPart(parser,partBuf,0);
  status = 0x2d;
  if (part != 0) {
    ppParserMacroCreateResult = _PPParserMacroCreate();
    _PPParserMacroSetSearchString(parser,ppParserMacroCreateResult,partBuf,part);
    part = _PPParserGetPart(parser,partBuf,0);
    status = 0x2d;
    if ((part != 0) && (status = 10, partBuf[0] == '=')) {
      savedPos = *(undefined4 *)(parser + 0xc);
      bodyLength = 0;
      savedLine = *(undefined4 *)(parser + 0x10);
      while( true ) {
        part3 = _PPParserGetPart(parser,partBuf,0);
        status = 0x2d;
        if (part3 == 0) break;
        if (partBuf[0] == ';') {
          if (bodyLength == 0) {
            return 10;
          }
          *(undefined4 *)(parser + 0x10) = savedLine;
          *(undefined4 *)(parser + 0xc) = savedPos;
          allocation = _malloc(bodyLength + 2);
          writePos = 0;
          while( true ) {
            part2 = _PPParserGetPart(parser,allocation + writePos,0);
            if (part2 == 0) {
              return 0x2d;
            }
            if (*(char *)(allocation + writePos) == ';') break;
            *(undefined1 *)(allocation + writePos + part2) = 0x20;
            writePos = writePos + part2 + 1;
          }
          *(undefined1 *)(allocation + writePos) = 0;
          ((int (*)())_PPParserMacroSetReplaceString)(parser,ppParserMacroCreateResult,allocation);
          _PPParserScopeAddMacro(*(undefined4 *)(parser + 0x44c),ppParserMacroCreateResult);
          return 0;
        }
        bodyLength = bodyLength + part3 + 1;
      }
    }
  }
  return status;
}

/* _PPParserMacroSetReplaceString @ 0x97b84ed8 (64 bytes) */
int _PPParserMacroSetReplaceString(parser, macro, replaceString)
  undefined4 parser;
  int macro;
  undefined4 replaceString;
{
  if (*(int *)(macro + 4) != 0) {
    _free(*(int *)(macro + 4));
  }
  *(undefined4 *)(macro + 4) = replaceString;
  return;
}

/* _PPParserMacroGetReplaceString @ 0x97b84f18 (320 bytes) */
int _PPParserMacroGetReplaceString(macro, unusedArg2, argStrings, outBuf)
  int macro;
  undefined4 unusedArg2;
  int argStrings;
  int outBuf;
{
  char curChar;
  int paramOffset;
  int paramLength;
  int outLength;
  char *wordStart;
  char *nextWord;
  uint loopIndex;
  int wordLength;
  
  outLength = 0;
  curChar = **(char **)(macro + 4);
  wordStart = *(char **)(macro + 4);
  do {
    if (curChar == '\0') {
      if (outBuf != 0) {
        *(undefined1 *)(outBuf + outLength) = 0;
      }
      return outLength;
    }
    for (wordLength = 0; (curChar = wordStart[wordLength], curChar != ' ' && (curChar != '\n')); wordLength = wordLength + 1) {
    }
    loopIndex = 0;
    nextWord = wordStart + wordLength + 1;
    if (*(int *)(macro + 8) != 0) {
      do {
        paramOffset = loopIndex * 4;
        paramLength = _strlen(*(undefined4 *)(paramOffset + *(int *)(macro + 0xc)));
        if ((wordLength == paramLength) &&
           (paramLength = _strncmp(wordStart,*(undefined4 *)(paramOffset + *(int *)(macro + 0xc)),wordLength),
           paramLength == 0)) {
          wordStart = *(char **)(paramOffset + argStrings);
          wordLength = _strlen(wordStart);
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < *(uint *)(macro + 8));
    }
    if (outBuf != 0) {
      _memmove(outBuf + outLength,wordStart,wordLength + 1);
      *(char *)(outBuf + outLength + wordLength) = curChar;
    }
    outLength = outLength + wordLength + 1;
    curChar = *nextWord;
    wordStart = nextWord;
  } while( true );
}

/* _PPParserParseSwizzleCode @ 0x97b85058 (620 bytes) */
int _PPParserParseSwizzleCode(parser, operand)
  int parser;
  uint *operand;
{
  uint partLength;
  int part2;
  uint component;
  int part;
  uint swizzleSets;
  int loopIndex;
  int negateComponent;
  char partBuf;
  char partBuf1;
  
  swizzleSets = 0;
  loopIndex = 0;
  do {
    partLength = _PPParserGetPart(parser,&partBuf,0);
    negateComponent = 0;
    if (partLength == 0) {
      return 0x2d;
    }
    if (2 < partLength) {
      return 0xf;
    }
    if (partBuf == '+') {
LAB_97b850c8:
      if (partLength == 2) {
        partBuf = partBuf1;
      }
      else {
        part = _PPParserGetPart(parser,&partBuf,0);
        if (part == 0) {
          return 0x2d;
        }
        if (part != 1) {
          return 0xf;
        }
      }
    }
    else {
      if (partBuf == '-') {
        negateComponent = 1;
        goto LAB_97b850c8;
      }
      if (partLength == 2) {
        return 0xf;
      }
    }
    switch(partBuf) {
    case '0':
      component = 9;
      break;
    case '1':
      component = 10;
      if (negateComponent == 0) {
        component = 8;
      }
      break;
    default:
      return 0xf;
    case 'a':
      swizzleSets = swizzleSets | 2;
      goto LAB_97b85300;
    case 'b':
      swizzleSets = swizzleSets | 2;
      goto LAB_97b852e8;
    case 'g':
      swizzleSets = swizzleSets | 2;
      goto LAB_97b852d0;
    case 'r':
      swizzleSets = swizzleSets | 2;
      goto LAB_97b852c0;
    case 'w':
      swizzleSets = swizzleSets | 1;
LAB_97b85300:
      component = 7;
      if (negateComponent == 0) {
        component = 3;
      }
      break;
    case 'x':
      swizzleSets = swizzleSets | 1;
LAB_97b852c0:
      component = negateComponent << 2;
      break;
    case 'y':
      swizzleSets = swizzleSets | 1;
LAB_97b852d0:
      component = 5;
      if (negateComponent == 0) {
        component = 1;
      }
      break;
    case 'z':
      swizzleSets = swizzleSets | 1;
LAB_97b852e8:
      component = 6;
      if (negateComponent == 0) {
        component = 2;
      }
    }
    if ((swizzleSets == 3) || ((swizzleSets == 2 && ((*(uint *)(parser + 0x48c) & 2) == 0)))) {
      return 0xd;
    }
    if (loopIndex == 1) {
      component = component << 8 | *operand & 0xfffff0ff;
LAB_97b85380:
      *operand = component;
LAB_97b85398:
      if (loopIndex == 3) {
        return 0;
      }
    }
    else {
      if (loopIndex == 0) {
        component = component << 0xc | *operand & 0xffff0fff;
        goto LAB_97b85380;
      }
      if (loopIndex == 2) {
        component = component << 4 | *operand & 0xffffff0f;
        goto LAB_97b85380;
      }
      if (loopIndex == 3) {
        *operand = component | *operand & 0xfffffff0;
        goto LAB_97b85398;
      }
    }
    part2 = _PPParserGetPart(parser,&partBuf,0);
    if (part2 == 0) {
      return 0x2d;
    }
    loopIndex = loopIndex + 1;
    if (partBuf != ',') {
      return 0xf;
    }
  } while( true );
}

/* __dyld_func_lookup @ 0x97b853f8 (32 bytes) */
int __dyld_func_lookup()
{
  undefined4 result;
  
                    
                    
  result = (*dyld_func_lookup_pointer)();
  return result;
}

/* ___initialize_Cplusplus @ 0x97b85418 (88 bytes) */
int ___initialize_Cplusplus()
{
  undefined4 initializerFn;
  
  ((int (*)())__dyld_func_lookup)();
  if ((void *)initializerFn != (void *)0) {
    ((int (*)())initializerFn)(PTR___mh_dylib_header_a7b7c0a0);
  }
  return;
}

/* _dyld_func_lookup_call_97b85470 @ 0x97b85470 (32 bytes) */
int _dyld_func_lookup_call_97b85470()
{
  ((int (*)())__dyld_func_lookup)();
  return;
}

/* InitProcess @ 0x97b85490 (36 bytes) */
int InitProcess()
{
  InitializeGlobalPools();
  return 1;
}

/* DetachProcess @ 0x97b854b4 (36 bytes) */
int DetachProcess()
{
  FreeGlobalPools();
  return 1;
}

/* _InitStringTable @ 0x97b854d8 (84 bytes) */
int _InitStringTable(stringTable)
  int *stringTable;
{
  int allocation;
  
  allocation = _malloc(0x4000);
  *stringTable = allocation;
  if (allocation != 0) {
    stringTable[2] = 0x4000;
    stringTable[1] = 1;
  }
  return (uint)(allocation != 0);
}

/* _FreeStringTable @ 0x97b8552c (72 bytes) */
int _FreeStringTable(stringTable)
  int *stringTable;
{
  undefined4 r3Out;
  undefined4 result;
  
  result = 0;
  if (*stringTable != 0) {
    _free(*stringTable);
    result = r3Out;
  }
  stringTable[2] = 0;
  *stringTable = 0;
  stringTable[1] = 0;
  return result;
}

/* _HashString @ 0x97b85574 (68 bytes) */
int _HashString(string)
  char *string;
{
  char ch;
  uint hash;
  
  hash = 0;
  ch = *string;
  while (ch != '\0') {
    string = string + 1;
    hash = hash * 0x34c3 + ch * 0xc5 ^ (int)hash >> 2;
    ch = *string;
  }
  return hash & 0x7fffffff;
}

/* _HashString2 @ 0x97b855b8 (64 bytes) */
int _HashString2(string)
  char *string;
{
  int chValue;
  uint hash;
  char ch;
  
  ch = *string;
  hash = 0;
  if (ch != '\0') {
    do {
      chValue = (int)ch;
      string = string + 1;
      ch = *string;
      hash = hash * 0x2d9 + chValue * 0x25 ^ (int)hash >> 1;
    } while (ch != '\0');
    return hash;
  }
  return hash;
}

/* _AddString @ 0x97b855f8 (156 bytes) */
int _AddString(stringTable, string)
  int *stringTable;
  undefined4 string;
{
  int length;
  int allocation;
  int offset;
  
  length = _strlen(string);
  offset = stringTable[1];
  if (stringTable[2] <= offset + length + 1) {
    allocation = _malloc(stringTable[2] << 1);
    _memcpy(allocation,*stringTable,stringTable[2]);
    _free(*stringTable);
    offset = stringTable[1];
    *stringTable = allocation;
  }
  _strcpy(*stringTable + offset,string);
  stringTable[1] = stringTable[1] + length + 1;
  return offset;
}

/* _InitHashTable @ 0x97b85694 (160 bytes) */
int _InitHashTable(htable, tableSize)
  int *htable;
  int tableSize;
{
  int entries;
  int entryOffset;
  int *counterCursor;
  int index;
  undefined4 success;
  
  entries = _malloc(tableSize << 3);
  *htable = entries;
  success = 0;
  if (entries != 0) {
    index = 0;
    htable[1] = tableSize;
    if (0 < tableSize) {
      do {
        entryOffset = index * 8;
        index = index + 1;
        *(undefined4 *)(entryOffset + *htable) = 0;
        *(undefined4 *)(entryOffset + *htable + 4) = 0;
        tableSize = tableSize + -1;
      } while (tableSize != 0);
    }
    index = 4;
    htable[2] = 0;
    counterCursor = htable + 3;
    do {
      *counterCursor = 0;
      counterCursor = counterCursor + 1;
      index = index + -1;
    } while (index != 0);
    success = 1;
  }
  return success;
}

/* _FreeHashTable @ 0x97b85734 (72 bytes) */
int _FreeHashTable(htable)
  int *htable;
{
  if (*htable != 0) {
    _free(*htable);
  }
  htable[2] = 0;
  *htable = 0;
  htable[1] = 0;
  return;
}

/* _GrowAtomTable @ 0x97b8577c (256 bytes) */
int _GrowAtomTable(atable, newSize)
  int atable;
  int newSize;
{
  int allocation;
  int allocation2;
  
  if (*(int *)(atable + 0x34) < newSize) {
    if (*(int *)(atable + 0x28) == 0) {
      allocation = _malloc(newSize << 2);
      allocation2 = _malloc(newSize << 2);
      *(undefined4 *)(atable + 0x34) = 0;
    }
    else {
      allocation = _realloc(*(int *)(atable + 0x28),newSize << 2);
      allocation2 = _realloc(*(undefined4 *)(atable + 0x2c),newSize << 2);
    }
    if ((allocation == 0) || (allocation2 == 0)) {
      if (allocation != 0) {
        *(int *)(atable + 0x28) = allocation;
      }
      if (allocation2 != 0) {
        *(int *)(atable + 0x28) = allocation2;
      }
      return 0xffffffff;
    }
    _memset(*(int *)(atable + 0x34) * 4 + allocation,0,(newSize - *(int *)(atable + 0x34)) * 4);
    _memset(*(int *)(atable + 0x34) * 4 + allocation2,0,(newSize - *(int *)(atable + 0x34)) * 4);
    *(int *)(atable + 0x34) = newSize;
    *(int *)(atable + 0x28) = allocation;
    *(int *)(atable + 0x2c) = allocation2;
  }
  return 0;
}

/* _lReverse @ 0x97b8587c (64 bytes) */
int _lReverse(value)
  uint value;
{
  uint lowBit;
  uint reversed;
  int loopIndex;
  
  reversed = 0;
  loopIndex = 0;
  if (value != 0) {
    do {
      lowBit = value & 1;
      value = value >> 1;
      loopIndex = loopIndex + 1;
      reversed = reversed << 1 | lowBit;
    } while (value != 0);
    if (0x13 < loopIndex) {
      return reversed;
    }
  }
  return reversed << (0x14U - loopIndex & 0x3f);
}

/* _AllocateAtom @ 0x97b858bc (120 bytes) */
int _AllocateAtom(atable)
  int atable;
{
  int atom;
  undefined4 lReverseResult;
  
  atom = *(int *)(atable + 0x30);
  if (*(int *)(atable + 0x34) <= atom) {
    ((int (*)())_GrowAtomTable)(atable,atom << 1);
    atom = *(int *)(atable + 0x30);
  }
  *(undefined4 *)(atom * 4 + *(int *)(atable + 0x28)) = 0xffffffff;
  lReverseResult = ((int (*)())_lReverse)(*(undefined4 *)(atable + 0x30));
  *(undefined4 *)(*(int *)(atable + 0x30) * 4 + *(int *)(atable + 0x2c)) = lReverseResult;
  atom = *(int *)(atable + 0x30);
  *(int *)(atable + 0x30) = atom + 1;
  return atom;
}

/* _SetAtomValue @ 0x97b85934 (40 bytes) */
int _SetAtomValue(atable, atom, hashSlot)
  int atable;
  int atom;
  int hashSlot;
{
  *(undefined4 *)(atom * 4 + *(int *)(atable + 0x28)) =
       *(undefined4 *)(hashSlot * 8 + *(int *)(atable + 0xc));
  *(int *)(hashSlot * 8 + *(int *)(atable + 0xc) + 4) = atom;
  return;
}

/* _FindHashLoc @ 0x97b8595c (264 bytes) */
int _FindHashLoc(htable, key)
  int *htable;
  undefined4 key;
{
  int hashStringResult;
  int hashString2Result;
  int compareResult;
  uint probeHash;
  int entryOffset;
  int probeOffset;
  int slot;
  int *visitedCursor;
  int loopIndex;
  int firstSlot;
  int visitedSlots [4];
  
  hashStringResult = ((int (*)())_HashString)(key);
  slot = hashStringResult - (hashStringResult / htable[4]) * htable[4];
  entryOffset = *(int *)(slot * 8 + htable[3]);
  if ((entryOffset != 0) && (entryOffset = _strcmp(key,*htable + entryOffset), entryOffset != 0)) {
    loopIndex = 0;
    hashString2Result = ((int (*)())_HashString2)(key);
    visitedCursor = &firstSlot;
    firstSlot = slot;
    do {
      probeHash = slot + hashString2Result & 0x7fffffff;
      slot = probeHash - ((int)probeHash / htable[4]) * htable[4];
      probeOffset = *(int *)(slot * 8 + htable[3]);
      if (probeOffset == 0) {
        htable[loopIndex + 6] = htable[loopIndex + 6] + 1;
        return slot;
      }
      compareResult = _strcmp(key,*htable + probeOffset);
      if (compareResult == 0) {
        return slot;
      }
      loopIndex = loopIndex + 1;
      visitedCursor = visitedCursor + 1;
      *visitedCursor = slot;
    } while (loopIndex < 3);
    slot = -1;
  }
  return slot;
}

/* _IncreaseHashTableSize @ 0x97b85a64 (192 bytes) */
int _IncreaseHashTableSize(atable)
  int atable;
{
  int initAtomTableResult;
  int atom;
  undefined4 success;
  int findHashLocResult;
  int atomString;
  int oldTable [3];
  int oldHashEntries;
  int oldHashSize;
  int oldAtomToString;
  int oldNextFree;
  
  _memcpy(oldTable,atable,0x38);
  initAtomTableResult = _InitAtomTable(atable,oldHashSize * 2 + 1);
  success = 0;
  if (initAtomTableResult != 0) {
    atom = *(int *)(atable + 0x30);
    if (atom < oldNextFree) {
      do {
        atomString = oldTable[0] + *(int *)(atom * 4 + oldAtomToString);
        findHashLocResult = ((int (*)())_FindHashLoc)(oldTable,atomString);
        _AddAtomFixed(atable,atomString,*(undefined4 *)(findHashLocResult * 8 + oldHashEntries + 4));
        atom = atom + 1;
      } while (atom < oldNextFree);
    }
    _FreeAtomTable(oldTable);
    success = 1;
  }
  return success;
}

/* _LookUpAddStringHash @ 0x97b85b24 (144 bytes) */
int _LookUpAddStringHash(atable, string)
  int atable;
  undefined4 string;
{
  int entryOffset;
  int findHashLocResult;
  undefined4 addStringResult;
  
  while( true ) {
    findHashLocResult = ((int (*)())_FindHashLoc)(atable,string);
    if (-1 < findHashLocResult) break;
    ((int (*)())_IncreaseHashTableSize)(atable);
  }
  entryOffset = findHashLocResult * 8;
  if (*(int *)(entryOffset + *(int *)(atable + 0xc)) == 0) {
    *(int *)(atable + 0x14) = *(int *)(atable + 0x14) + 1;
    addStringResult = ((int (*)())_AddString)(atable,string);
    *(undefined4 *)(entryOffset + *(int *)(atable + 0xc)) = addStringResult;
    *(undefined4 *)(entryOffset + *(int *)(atable + 0xc) + 4) = 0;
  }
  return findHashLocResult;
}

/* _LookUpAddString @ 0x97b85bb4 (104 bytes) */
int _LookUpAddString(atable, string)
  int atable;
  undefined4 string;
{
  int lookUpAddStringHashResult;
  int atom;
  
  lookUpAddStringHashResult = ((int (*)())_LookUpAddStringHash)(atable,string);
  atom = *(int *)(lookUpAddStringHashResult * 8 + *(int *)(atable + 0xc) + 4);
  if (atom == 0) {
    atom = ((int (*)())_AllocateAtom)(atable);
    ((int (*)())_SetAtomValue)(atable,atom,lookUpAddStringHashResult);
  }
  return atom;
}

/* _GetAtomString @ 0x97b85c1c (144 bytes) */
int _GetAtomString(atable, atom)
  int *atable;
  int atom;
{
  int stringOffset;
  
  if ((0 < atom) && (atom < atable[0xc])) {
    stringOffset = *(int *)(atom * 4 + atable[10]);
    if ((0 < stringOffset) && (stringOffset < atable[1])) {
      return (char *)(*atable + stringOffset);
    }
    return "<internal error: bad soffset>";
  }
  if (atom == 0) {
    return "<null atom>";
  }
  if (atom == -1) {
    return "<EOF>";
  }
  return "<invalid atom>";
}

/* _GetReversedAtom @ 0x97b85cac (44 bytes) */
int _GetReversedAtom(atable, atom)
  int atable;
  int atom;
{
  if ((0 < atom) && (atom < *(int *)(atable + 0x30))) {
    return *(undefined4 *)(atom * 4 + *(int *)(atable + 0x2c));
  }
  return 0;
}

