#include "decls.h"

/* _GetChunkAllocationSize @ 0x97b825bc (124 bytes) */
int _GetChunkAllocationSize(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  switch(param_1) {
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
    if (param_2 != 0) {
      return param_2 + 9;
    }
    return 8;
  default:
    return 0;
  }
  if (param_2 != 0) {
    return param_2 + 0x39;
  }
  return 0x38;
}

/* _PPStreamChunkListSort @ 0x97b82668 (156 bytes) */
int _PPStreamChunkListSort(stream)
  int *stream;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *stream;
  if (iVar2 == 0) {
    return;
  }
  while( true ) {
    bVar1 = false;
    if (iVar2 == 0) {
      return;
    }
    while (iVar4 = iVar2, iVar2 = *(int *)(iVar4 + 8), iVar2 != 0) {
      if (*(ushort *)(iVar2 + 0x12) < *(ushort *)(iVar4 + 0x12)) {
        if (*(int *)(iVar2 + 8) == 0) {
          stream[1] = iVar4;
        }
        else {
          *(int *)(*(int *)(iVar2 + 8) + 4) = iVar4;
        }
        iVar3 = *(int *)(iVar4 + 4);
        if (iVar3 == 0) {
          *stream = iVar2;
          iVar3 = *(int *)(iVar4 + 4);
        }
        else {
          *(int *)(iVar3 + 8) = iVar2;
        }
        bVar1 = true;
        *(int *)(iVar2 + 4) = iVar3;
        *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar2 + 8);
        *(int *)(iVar4 + 4) = iVar2;
        *(int *)(iVar2 + 8) = iVar4;
      }
    }
    if (!bVar1) break;
    iVar2 = *stream;
  }
  return;
}

/* _PPStreamAttachOperationsChunkList @ 0x97b82704 (56 bytes) */
int _PPStreamAttachOperationsChunkList(stream, param_2)
  int stream;
  undefined4 param_2;
{
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x20));
  *(undefined4 *)(stream + 0x20) = param_2;
  return;
}

/* _PPStreamChunkListFree @ 0x97b8273c (84 bytes) */
int _PPStreamChunkListFree(stream)
  int *stream;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = stream[2];
  iVar2 = *stream;
  if (0 < iVar1) {
    do {
      iVar3 = *(int *)(iVar2 + 8);
      _free(iVar2);
      iVar1 = iVar1 + -1;
      iVar2 = iVar3;
    } while (iVar1 != 0);
  }
  return _free(stream);
}

/* _PPStreamChunkListRemoveChunk @ 0x97b82790 (120 bytes) */
int _PPStreamChunkListRemoveChunk(stream, param_2)
  undefined4 *stream;
  int param_2;
{
  undefined4 extraout_r3;
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == 0) {
    *stream = *(undefined4 *)(param_2 + 8);
    iVar1 = *(int *)(param_2 + 4);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_2 + 8);
  }
  if (*(int *)(param_2 + 8) == 0) {
    stream[1] = iVar1;
  }
  else {
    *(int *)(*(int *)(param_2 + 8) + 4) = iVar1;
  }
  _free(param_2);
  stream[2] = stream[2] + -1;
  return extraout_r3;
}

/* _PPStreamAttachParamBindingsChunkList @ 0x97b82808 (56 bytes) */
int _PPStreamAttachParamBindingsChunkList(stream, param_2)
  int stream;
  undefined4 param_2;
{
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x10));
  *(undefined4 *)(stream + 0x10) = param_2;
  return;
}

/* _PPStreamAttachParamBindingArraysChunkList @ 0x97b82840 (56 bytes) */
int _PPStreamAttachParamBindingArraysChunkList(stream, param_2)
  int stream;
  undefined4 param_2;
{
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(stream + 0x14));
  *(undefined4 *)(stream + 0x14) = param_2;
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
int _PPStreamChunkListGetMaxIndex(stream)
  undefined4 *stream;
{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint loopIndex;
  
  puVar2 = (undefined1 *)*stream;
  uVar3 = 0;
  loopIndex = 1;
  do {
    if (puVar2 == (undefined1 *)0x0) {
      return uVar3;
    }
    switch(*puVar2) {
    case 0:
    case 2:
    case 3:
    case 4:
      uVar1 = (uint)*(ushort *)(puVar2 + 0x12);
      break;
    case 1:
      uVar1 = *(uint *)(puVar2 + 0xc);
      break;
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
      if (uVar3 < loopIndex) {
        uVar3 = loopIndex;
      }
      goto switchD_97b82c84_default;
    case 8:
      uVar1 = *(uint *)(puVar2 + 0xc) & 0x3ffff;
      break;
    case 0xb:
      return 0;
    default:
      goto switchD_97b82c84_default;
    }
    if (uVar3 < uVar1) {
      uVar3 = uVar1;
    }
switchD_97b82c84_default:
    puVar2 = *(undefined1 **)(puVar2 + 8);
    loopIndex = loopIndex + 1;
  } while( true );
}

/* _PPStreamAddTempUsage @ 0x97b82d10 (108 bytes) */
int _PPStreamAddTempUsage(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *allocation;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  allocation = (undefined1 *)_calloc(0x1c,1);
  uVar3 = param_2[3];
  uVar2 = *(undefined4 *)(param_1 + 4);
  uVar4 = *param_2;
  uVar6 = param_2[1];
  uVar5 = param_2[2];
  *allocation = 0;
  *(undefined4 *)(allocation + 0xc) = uVar4;
  *(undefined4 *)(allocation + 0x10) = uVar6;
  *(undefined4 *)(allocation + 0x14) = uVar5;
  *(undefined4 *)(allocation + 0x18) = uVar3;
  return _PPStreamChunkListAddChunk(uVar2,allocation);
}

/* _PPEmulatorProgramCreate @ 0x97b82d7c (72 bytes) */
int _PPEmulatorProgramCreate()
{
  undefined4 uVar1;
  int allocation;
  
  allocation = _calloc(0x128,1);
  uVar1 = DAT_a7b7bda4;
  *(undefined4 *)(allocation + 0xc) = DAT_a7b7bda4;
  *(undefined4 *)(allocation + 8) = uVar1;
  /* dropped-return-value defect (class 25, issue #68) - stock leaves calloc's result in r3
   * through to blr; verified via Capstone disasm of the real 0x97b82d7c body. */
  return allocation;
}

/* _PPEmulatorProgramInitialiseHandleBanks @ 0x97b82dc4 (288 bytes) */
int _PPEmulatorProgramInitialiseHandleBanks(emulator, param_2, param_3, param_4, param_5)
  int emulator;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  uint uVar2;
  undefined4 allocation;
  uint loopIndex;
  int iVar5;
  
  loopIndex = 0;
  do {
    if (*(int *)(emulator + 0x80) != 0) {
      _free(*(int *)(emulator + 0x80));
    }
    *(undefined4 *)(emulator + 0x80) = 0;
    *(undefined4 *)(emulator + 0x84) = 0;
    *(undefined4 *)(emulator + 0x88) = 0;
    iVar1 = param_3;
    if (((((loopIndex == 1) || (iVar1 = param_2, loopIndex == 0)) || (iVar1 = param_4, loopIndex == 2)) ||
        (iVar1 = param_5, loopIndex == 3)) && (iVar1 != 0)) {
      iVar5 = 0x20;
      do {
        if (iVar1 << (0x20U - iVar5 & 0x3f) < 0) {
          if (iVar5 != 0) {
            uVar2 = *(uint *)(emulator + 0x88);
            do {
              uVar2 = uVar2 << 1 | 1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
            *(uint *)(emulator + 0x88) = uVar2;
          }
          break;
        }
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      uVar2 = iVar1 << 1 & ~*(uint *)(emulator + 0x88);
      *(uint *)(emulator + 0x84) = uVar2;
      allocation = _malloc(uVar2 << 4);
      *(undefined4 *)(emulator + 0x80) = allocation;
      _memset(allocation,0,*(int *)(emulator + 0x84) << 4);
    }
    loopIndex = loopIndex + 1;
    emulator = emulator + 0xc;
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
int _PPStreamChunkListChunkAtIndex(stream, param_2)
  undefined4 *stream;
  uint param_2;
{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  for (puVar2 = (undefined1 *)*stream; puVar2 != (undefined1 *)0x0;
      puVar2 = *(undefined1 **)(puVar2 + 8)) {
    switch(*puVar2) {
    case 0:
    case 2:
    case 3:
    case 4:
      uVar1 = (uint)*(ushort *)(puVar2 + 0x12);
      break;
    case 1:
      uVar1 = *(uint *)(puVar2 + 0xc);
      break;
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
      uVar1 = uVar3;
      break;
    case 8:
      uVar1 = *(uint *)(puVar2 + 0xc) & 0x3ffff;
      break;
    case 0xb:
      goto LAB_97b83e9c;
    default:
      goto switchD_97b83e20_default;
    }
    if (uVar1 == param_2) {
      return puVar2;
    }
switchD_97b83e20_default:
    uVar3 = uVar3 + 1;
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
  int iVar1;
  undefined4 ppParserAttachStringResult;
  
  iVar1 = *(int *)(parser + 0x448);
  while (iVar1 != 0) {
    ((int (*)())_PPParserRemoveScope)(parser,iVar1);
    iVar1 = *(int *)(parser + 0x448);
  }
  ppParserAttachStringResult = _PPParserAttachString(parser,0,0);
  return ppParserAttachStringResult;
}

/* _PPParserRemoveScope @ 0x97b83f2c (68 bytes) */
int _PPParserRemoveScope(parser, param_2)
  int parser;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x1c);
  if (iVar1 == 0) {
    *(undefined4 *)(parser + 0x448) = *(undefined4 *)(param_2 + 0x20);
    iVar1 = *(int *)(param_2 + 0x1c);
  }
  else {
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  }
  if (*(int *)(param_2 + 0x20) == 0) {
    *(int *)(parser + 0x44c) = iVar1;
  }
  else {
    *(int *)(*(int *)(param_2 + 0x20) + 0x1c) = iVar1;
  }
  return ((int (*)())_PPParserScopeFree)(param_2);
}

/* _PPParserScopeFree @ 0x97b83f70 (116 bytes) */
int _PPParserScopeFree(parser)
  int *parser;
{
  int iVar1;
  
  iVar1 = *parser;
  while (iVar1 != 0) {
    ((int (*)())_PPParserScopeRemoveIdentifier)(parser,iVar1);
    iVar1 = *parser;
  }
  iVar1 = parser[2];
  while (iVar1 != 0) {
    ((int (*)())_PPParserScopeRemoveMacro)(parser,iVar1);
    iVar1 = parser[2];
  }
  return _free(parser);
}

/* _PPParserScopeRemoveIdentifier @ 0x97b83fe4 (68 bytes) */
int _PPParserScopeRemoveIdentifier(parser, param_2)
  undefined4 *parser;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x1c);
  if (iVar1 == 0) {
    *parser = *(undefined4 *)(param_2 + 0x20);
    iVar1 = *(int *)(param_2 + 0x1c);
  }
  else {
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  }
  if (*(int *)(param_2 + 0x20) == 0) {
    parser[1] = iVar1;
  }
  else {
    *(int *)(*(int *)(param_2 + 0x20) + 0x1c) = iVar1;
  }
  return ((int (*)())_PPParserIdentifierFree)(param_2);
}

/* _PPParserIdentifierFree @ 0x97b84028 (52 bytes) */
int _PPParserIdentifierFree(parser)
  undefined4 parser;
{
  _PPParserIdentifierSetName(parser,0);
  return _free(parser);
}

/* _PPParserScopeRemoveMacro @ 0x97b8405c (68 bytes) */
int _PPParserScopeRemoveMacro(parser, param_2)
  int parser;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x18);
  if (iVar1 == 0) {
    *(undefined4 *)(parser + 8) = *(undefined4 *)(param_2 + 0x1c);
    iVar1 = *(int *)(param_2 + 0x18);
  }
  else {
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  }
  if (*(int *)(param_2 + 0x1c) == 0) {
    *(int *)(parser + 0xc) = iVar1;
  }
  else {
    *(int *)(*(int *)(param_2 + 0x1c) + 0x18) = iVar1;
  }
  return ((int (*)())_PPParserMacroFree)(param_2);
}

/* _PPParserMacroFree @ 0x97b840a0 (144 bytes) */
int _PPParserMacroFree(parser)
  undefined4 *parser;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint loopIndex;
  
  loopIndex = 0;
  _free(*parser);
  _free(parser[1]);
  uVar1 = parser[2];
  if (uVar1 == 0) {
    iVar3 = parser[3];
  }
  else {
    iVar3 = parser[3];
    do {
      iVar2 = *(int *)(loopIndex * 4 + iVar3);
      if (iVar2 != 0) {
        _free(iVar2);
        uVar1 = parser[2];
        iVar3 = parser[3];
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < uVar1);
  }
  if (iVar3 != 0) {
    _free(iVar3);
  }
  return _free(parser);
}

/* _PPParserGetScalars @ 0x97b84130 (200 bytes) */
int _PPParserGetScalars(parser, param_2, param_3)
  undefined4 parser;
  float *param_2;
  int param_3;
{
  int part;
  int loopIndex;
  double glp_strtodResult;
  char local_130 [256];
  char *local_30 [5];
  
  loopIndex = 0;
  while( true ) {
    part = _PPParserGetPart(parser,local_130,1);
    if (part == 0) {
      return 0x2d;
    }
    glp_strtodResult = (double)((double (*)())_glp_strtod)(local_130,local_30);
    *param_2 = (float)glp_strtodResult;
    if (local_30[0] != local_130 + part) {
      return 0x15;
    }
    loopIndex = loopIndex + 1;
    param_2 = param_2 + 1;
    if (loopIndex == param_3) {
      return 0;
    }
    part = _PPParserGetPart(parser,local_130,0);
    if (part == 0) break;
    if (local_130[0] != ',') {
      _PPParserReturnPart(parser);
      return 0;
    }
  }
  return 0x2d;
}

/* _PPStreamAddConstant @ 0x97b841f8 (108 bytes) */
int _PPStreamAddConstant(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 *allocation;
  undefined4 uVar6;
  
  allocation = (undefined1 *)_calloc(0x1c,1);
  uVar1 = param_2[3];
  uVar6 = *(undefined4 *)(param_1 + 0x2c);
  uVar2 = *param_2;
  uVar3 = param_2[1];
  uVar4 = param_2[2];
  *allocation = 10;
  *(undefined4 *)(allocation + 0xc) = uVar2;
  *(undefined4 *)(allocation + 0x10) = uVar3;
  *(undefined4 *)(allocation + 0x14) = uVar4;
  *(undefined4 *)(allocation + 0x18) = uVar1;
  return _PPStreamChunkListAddChunk(uVar6,allocation);
}

/* _PPParserParseTempDeclaration @ 0x97b84264 (468 bytes) */
int _PPParserParseTempDeclaration(parser, param_2)
  int parser;
  int param_2;
{
  int ppParserIdentifierCreateResult;
  int ppParserValidateNameResult;
  int arrayResult;
  int part;
  int part2;
  int iVar1;
  int ppParserScopeAddIdentifierResult;
  uint uVar3;
  uint loopIndex;
  char local_140 [256];
  int local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30 [6];
  
  local_30[0] = 0;
  uVar3 = 0;
  do {
    part2 = _PPParserGetPart(parser,local_140,0);
    if (part2 == 0) {
      return 0x2d;
    }
    ppParserValidateNameResult = _PPParserValidateName(parser,local_140);
    if (ppParserValidateNameResult != 0) {
      return 0x12;
    }
    ppParserIdentifierCreateResult = _PPParserIdentifierCreate();
    _PPParserIdentifierSetName(ppParserIdentifierCreateResult,local_140);
    *(undefined4 *)(ppParserIdentifierCreateResult + 0xc) = 1;
    *(int *)(ppParserIdentifierCreateResult + 0x14) = param_2;
    *(uint *)(ppParserIdentifierCreateResult + 8) = *(int *)(*(int *)(parser + 0x44c) + 0x14) + uVar3;
    ppParserScopeAddIdentifierResult = _PPParserScopeAddIdentifier(*(undefined4 *)(parser + 0x44c),ppParserIdentifierCreateResult);
    if (ppParserScopeAddIdentifierResult != 0) {
      ((int (*)())_PPParserIdentifierFree)(ppParserIdentifierCreateResult);
      return 0x1c;
    }
    part = _PPParserGetPart(parser,local_140,0);
    if (part == 0) {
      return 0x2d;
    }
    if (local_140[0] == '[') {
      _PPParserReturnPart(parser);
      arrayResult = _PPParserParseArray(parser,local_30);
      if (arrayResult != 0) {
        return arrayResult;
      }
      *(undefined1 *)(ppParserIdentifierCreateResult + 0x10) = 1;
      *(undefined4 *)(ppParserIdentifierCreateResult + 4) = local_30[0];
      part = _PPParserGetPart(parser,local_140,0);
      if (part == 0) {
        return 0x2d;
      }
    }
    uVar3 = uVar3 + *(int *)(ppParserIdentifierCreateResult + 4);
    if (local_140[0] == ';') {
      iVar1 = *(int *)(parser + 0x44c);
      if (*(uint *)(parser + 0x460) < *(int *)(iVar1 + 0x14) + uVar3) {
        return 0x33;
      }
      loopIndex = 0;
      if (uVar3 != 0) {
        while( true ) {
          loopIndex = loopIndex + 1;
          local_34 = 0;
          local_38 = 0;
          local_40 = param_2 << 0x1d;
          local_3c = (uint)*(ushort *)(iVar1 + 0x16);
          ((int (*)())_PPStreamAddTempUsage)(*(undefined4 *)(parser + 0x1c),&local_40);
          *(int *)(*(int *)(parser + 0x44c) + 0x14) =
               *(int *)(*(int *)(parser + 0x44c) + 0x14) + 1;
          if (uVar3 <= loopIndex) break;
          iVar1 = *(int *)(parser + 0x44c);
        }
      }
      return 0;
    }
  } while (local_140[0] == ',');
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
int _PPParserParseDestinationMask(parser, param_2)
  int parser;
  uint *param_2;
{
  uint uVar1;
  uint part;
  undefined4 uVar3;
  uint loopIndex;
  uint uVar5;
  undefined1 local_110 [260];
  
  part = _PPParserGetPart(parser,local_110,0);
  uVar5 = 0;
  uVar3 = 0x2d;
  if (part != 0) {
    loopIndex = 0;
    *param_2 = *param_2 & 0xfffe1fff;
    if (part != 0) {
      do {
        switch(local_110[loopIndex]) {
        case 0x61:
          if ((*param_2 & 0x10000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x10000;
          break;
        case 0x62:
          if ((*param_2 & 0x8000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x8000;
          break;
        default:
          goto LAB_97b8481c;
        case 0x67:
          if ((*param_2 & 0x4000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x4000;
          break;
        case 0x72:
          if ((*param_2 & 0x2000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x2000;
          break;
        case 0x77:
          if ((*param_2 & 0x10000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x10000;
          goto LAB_97b84778;
        case 0x78:
          if ((*param_2 & 0x2000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x2000;
          goto LAB_97b84778;
        case 0x79:
          if ((*param_2 & 0x4000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x4000;
          goto LAB_97b84778;
        case 0x7a:
          if ((*param_2 & 0x8000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x8000;
LAB_97b84778:
          *param_2 = uVar1;
          uVar5 = uVar5 | 1;
          goto LAB_97b847e8;
        }
        *param_2 = uVar1;
        uVar5 = uVar5 | 2;
LAB_97b847e8:
        loopIndex = loopIndex + 1;
      } while (loopIndex < part);
      if ((uVar5 == 3) || ((uVar5 == 2 && ((*(uint *)(parser + 0x48c) & 2) == 0)))) {
LAB_97b8481c:
        return 0xc;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
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
undefined8 ___lshrdi3(param_1, param_2, param_3)
  uint param_1;
  uint param_2;
  uint param_3;
{
  uint uVar1;
  undefined4 uStack_30;
  
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  uVar1 = 0x20 - param_3;
  if ((int)uVar1 < 1) {
    uVar1 = param_1 >> (-uVar1 & 0x3f);
    uStack_30 = 0;
  }
  else {
    uStack_30 = param_1 >> (param_3 & 0x3f);
    uVar1 = param_2 >> (param_3 & 0x3f) | param_1 << (uVar1 & 0x3f);
  }
  return CONCAT44(uVar1,uStack_30);
}

/* ___ashldi3 @ 0x97b84b50 (96 bytes) */
undefined8 ___ashldi3(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  uint uVar1;
  undefined4 uStack_2c;
  
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  uVar1 = 0x20 - param_3;
  if ((int)uVar1 < 1) {
    uVar1 = param_2 << (-uVar1 & 0x3f);
    uStack_2c = 0;
  }
  else {
    uStack_2c = param_2 << (param_3 & 0x3f);
    uVar1 = param_1 << (param_3 & 0x3f) | param_2 >> (uVar1 & 0x3f);
  }
  return CONCAT44(uStack_2c,uVar1);
}

/* _PPStreamGetTexOperationCount @ 0x97b84bb0 (60 bytes) */
int _PPStreamGetTexOperationCount(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = **(int **)(param_1 + 0x20);
  if (iVar2 != 0) {
    do {
      if ((*(uint *)(iVar2 + 0xc) >> 0x12 & 0xff) - 0x42 < 3) {
        iVar1 = iVar1 + 1;
      }
      iVar2 = *(int *)(iVar2 + 8);
    } while (iVar2 != 0);
    return iVar1;
  }
  return iVar1;
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
  undefined4 extraout_r3;
  
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
  return extraout_r3;
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
  undefined4 uVar1;
  int iVar2;
  undefined4 ppParserMacroCreateResult;
  int iVar4;
  int part2;
  char local_130 [256];
  undefined4 local_30;
  undefined4 local_2c;
  
  part = _PPParserGetPart(parser,local_130,0);
  uVar1 = 0x2d;
  if (part != 0) {
    ppParserMacroCreateResult = _PPParserMacroCreate();
    _PPParserMacroSetSearchString(parser,ppParserMacroCreateResult,local_130,part);
    part = _PPParserGetPart(parser,local_130,0);
    uVar1 = 0x2d;
    if ((part != 0) && (uVar1 = 10, local_130[0] == '=')) {
      local_30 = *(undefined4 *)(parser + 0xc);
      iVar2 = 0;
      local_2c = *(undefined4 *)(parser + 0x10);
      while( true ) {
        part3 = _PPParserGetPart(parser,local_130,0);
        uVar1 = 0x2d;
        if (part3 == 0) break;
        if (local_130[0] == ';') {
          if (iVar2 == 0) {
            return 10;
          }
          *(undefined4 *)(parser + 0x10) = local_2c;
          *(undefined4 *)(parser + 0xc) = local_30;
          allocation = _malloc(iVar2 + 2);
          iVar4 = 0;
          while( true ) {
            part2 = _PPParserGetPart(parser,allocation + iVar4,0);
            if (part2 == 0) {
              return 0x2d;
            }
            if (*(char *)(allocation + iVar4) == ';') break;
            *(undefined1 *)(allocation + iVar4 + part2) = 0x20;
            iVar4 = iVar4 + part2 + 1;
          }
          *(undefined1 *)(allocation + iVar4) = 0;
          ((int (*)())_PPParserMacroSetReplaceString)(parser,ppParserMacroCreateResult,allocation);
          _PPParserScopeAddMacro(*(undefined4 *)(parser + 0x44c),ppParserMacroCreateResult);
          return 0;
        }
        iVar2 = iVar2 + part3 + 1;
      }
    }
  }
  return uVar1;
}

/* _PPParserMacroSetReplaceString @ 0x97b84ed8 (64 bytes) */
int _PPParserMacroSetReplaceString(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
{
  if (*(int *)(param_2 + 4) != 0) {
    _free(*(int *)(param_2 + 4));
  }
  *(undefined4 *)(param_2 + 4) = param_3;
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
  undefined4 uVar1;
  
                    
                    
  uVar1 = (*dyld_func_lookup_pointer)();
  return uVar1;
}

/* ___initialize_Cplusplus @ 0x97b85418 (88 bytes) */
int ___initialize_Cplusplus()
{
  undefined4 uStack_28;
  
  ((int (*)())__dyld_func_lookup)();
  if ((void *)uStack_28 != (void *)0) {
    ((int (*)())uStack_28)(PTR___mh_dylib_header_a7b7c0a0);
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
int _InitStringTable(param_1)
  int *param_1;
{
  int allocation;
  
  allocation = _malloc(0x4000);
  *param_1 = allocation;
  if (allocation != 0) {
    param_1[2] = 0x4000;
    param_1[1] = 1;
  }
  return (uint)(allocation != 0);
}

/* _FreeStringTable @ 0x97b8552c (72 bytes) */
int _FreeStringTable(param_1)
  int *param_1;
{
  undefined4 extraout_r3;
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*param_1 != 0) {
    _free(*param_1);
    uVar1 = extraout_r3;
  }
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return uVar1;
}

/* _HashString @ 0x97b85574 (68 bytes) */
int _HashString(param_1)
  char *param_1;
{
  char ch;
  uint uVar2;
  
  uVar2 = 0;
  ch = *param_1;
  while (ch != '\0') {
    param_1 = param_1 + 1;
    uVar2 = uVar2 * 0x34c3 + ch * 0xc5 ^ (int)uVar2 >> 2;
    ch = *param_1;
  }
  return uVar2 & 0x7fffffff;
}

/* _HashString2 @ 0x97b855b8 (64 bytes) */
int _HashString2(param_1)
  char *param_1;
{
  int iVar1;
  uint uVar2;
  char ch;
  
  ch = *param_1;
  uVar2 = 0;
  if (ch != '\0') {
    do {
      iVar1 = (int)ch;
      param_1 = param_1 + 1;
      ch = *param_1;
      uVar2 = uVar2 * 0x2d9 + iVar1 * 0x25 ^ (int)uVar2 >> 1;
    } while (ch != '\0');
    return uVar2;
  }
  return uVar2;
}

/* _AddString @ 0x97b855f8 (156 bytes) */
int _AddString(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int length;
  int allocation;
  int iVar3;
  
  length = _strlen(param_2);
  iVar3 = param_1[1];
  if (param_1[2] <= iVar3 + length + 1) {
    allocation = _malloc(param_1[2] << 1);
    _memcpy(allocation,*param_1,param_1[2]);
    _free(*param_1);
    iVar3 = param_1[1];
    *param_1 = allocation;
  }
  _strcpy(*param_1 + iVar3,param_2);
  param_1[1] = param_1[1] + length + 1;
  return iVar3;
}

/* _InitHashTable @ 0x97b85694 (160 bytes) */
int _InitHashTable(param_1, param_2)
  int *param_1;
  int param_2;
{
  int allocation;
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  allocation = _malloc(param_2 << 3);
  *param_1 = allocation;
  uVar4 = 0;
  if (allocation != 0) {
    iVar3 = 0;
    param_1[1] = param_2;
    if (0 < param_2) {
      do {
        iVar1 = iVar3 * 8;
        iVar3 = iVar3 + 1;
        *(undefined4 *)(iVar1 + *param_1) = 0;
        *(undefined4 *)(iVar1 + *param_1 + 4) = 0;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    iVar3 = 4;
    param_1[2] = 0;
    piVar2 = param_1 + 3;
    do {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar4 = 1;
  }
  return uVar4;
}

/* _FreeHashTable @ 0x97b85734 (72 bytes) */
int _FreeHashTable(param_1)
  int *param_1;
{
  if (*param_1 != 0) {
    _free(*param_1);
  }
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return;
}

/* _GrowAtomTable @ 0x97b8577c (256 bytes) */
int _GrowAtomTable(param_1, param_2)
  int param_1;
  int param_2;
{
  int allocation;
  int allocation2;
  
  if (*(int *)(param_1 + 0x34) < param_2) {
    if (*(int *)(param_1 + 0x28) == 0) {
      allocation = _malloc(param_2 << 2);
      allocation2 = _malloc(param_2 << 2);
      *(undefined4 *)(param_1 + 0x34) = 0;
    }
    else {
      allocation = _realloc(*(int *)(param_1 + 0x28),param_2 << 2);
      allocation2 = _realloc(*(undefined4 *)(param_1 + 0x2c),param_2 << 2);
    }
    if ((allocation == 0) || (allocation2 == 0)) {
      if (allocation != 0) {
        *(int *)(param_1 + 0x28) = allocation;
      }
      if (allocation2 != 0) {
        *(int *)(param_1 + 0x28) = allocation2;
      }
      return 0xffffffff;
    }
    _memset(*(int *)(param_1 + 0x34) * 4 + allocation,0,(param_2 - *(int *)(param_1 + 0x34)) * 4);
    _memset(*(int *)(param_1 + 0x34) * 4 + allocation2,0,(param_2 - *(int *)(param_1 + 0x34)) * 4);
    *(int *)(param_1 + 0x34) = param_2;
    *(int *)(param_1 + 0x28) = allocation;
    *(int *)(param_1 + 0x2c) = allocation2;
  }
  return 0;
}

/* _lReverse @ 0x97b8587c (64 bytes) */
int _lReverse(param_1)
  uint param_1;
{
  uint uVar1;
  uint uVar2;
  int loopIndex;
  
  uVar2 = 0;
  loopIndex = 0;
  if (param_1 != 0) {
    do {
      uVar1 = param_1 & 1;
      param_1 = param_1 >> 1;
      loopIndex = loopIndex + 1;
      uVar2 = uVar2 << 1 | uVar1;
    } while (param_1 != 0);
    if (0x13 < loopIndex) {
      return uVar2;
    }
  }
  return uVar2 << (0x14U - loopIndex & 0x3f);
}

/* _AllocateAtom @ 0x97b858bc (120 bytes) */
int _AllocateAtom(param_1)
  int param_1;
{
  int iVar1;
  undefined4 lReverseResult;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (*(int *)(param_1 + 0x34) <= iVar1) {
    ((int (*)())_GrowAtomTable)(param_1,iVar1 << 1);
    iVar1 = *(int *)(param_1 + 0x30);
  }
  *(undefined4 *)(iVar1 * 4 + *(int *)(param_1 + 0x28)) = 0xffffffff;
  lReverseResult = ((int (*)())_lReverse)(*(undefined4 *)(param_1 + 0x30));
  *(undefined4 *)(*(int *)(param_1 + 0x30) * 4 + *(int *)(param_1 + 0x2c)) = lReverseResult;
  iVar1 = *(int *)(param_1 + 0x30);
  *(int *)(param_1 + 0x30) = iVar1 + 1;
  return iVar1;
}

/* _SetAtomValue @ 0x97b85934 (40 bytes) */
int _SetAtomValue(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0x28)) =
       *(undefined4 *)(param_3 * 8 + *(int *)(param_1 + 0xc));
  *(int *)(param_3 * 8 + *(int *)(param_1 + 0xc) + 4) = param_2;
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
int _IncreaseHashTableSize(param_1)
  int param_1;
{
  int initAtomTableResult;
  int iVar1;
  undefined4 uVar2;
  int findHashLocResult;
  int iVar4;
  int local_50 [3];
  int local_44;
  int local_40;
  int local_28;
  int local_20;
  
  _memcpy(local_50,param_1,0x38);
  initAtomTableResult = _InitAtomTable(param_1,local_40 * 2 + 1);
  uVar2 = 0;
  if (initAtomTableResult != 0) {
    iVar1 = *(int *)(param_1 + 0x30);
    if (iVar1 < local_20) {
      do {
        iVar4 = local_50[0] + *(int *)(iVar1 * 4 + local_28);
        findHashLocResult = ((int (*)())_FindHashLoc)(local_50,iVar4);
        _AddAtomFixed(param_1,iVar4,*(undefined4 *)(findHashLocResult * 8 + local_44 + 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < local_20);
    }
    _FreeAtomTable(local_50);
    uVar2 = 1;
  }
  return uVar2;
}

/* _LookUpAddStringHash @ 0x97b85b24 (144 bytes) */
int _LookUpAddStringHash(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int findHashLocResult;
  undefined4 addStringResult;
  
  while( true ) {
    findHashLocResult = ((int (*)())_FindHashLoc)(param_1,param_2);
    if (-1 < findHashLocResult) break;
    ((int (*)())_IncreaseHashTableSize)(param_1);
  }
  iVar1 = findHashLocResult * 8;
  if (*(int *)(iVar1 + *(int *)(param_1 + 0xc)) == 0) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    addStringResult = ((int (*)())_AddString)(param_1,param_2);
    *(undefined4 *)(iVar1 + *(int *)(param_1 + 0xc)) = addStringResult;
    *(undefined4 *)(iVar1 + *(int *)(param_1 + 0xc) + 4) = 0;
  }
  return findHashLocResult;
}

/* _LookUpAddString @ 0x97b85bb4 (104 bytes) */
int _LookUpAddString(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int lookUpAddStringHashResult;
  int iVar2;
  
  lookUpAddStringHashResult = ((int (*)())_LookUpAddStringHash)(param_1,param_2);
  iVar2 = *(int *)(lookUpAddStringHashResult * 8 + *(int *)(param_1 + 0xc) + 4);
  if (iVar2 == 0) {
    iVar2 = ((int (*)())_AllocateAtom)(param_1);
    ((int (*)())_SetAtomValue)(param_1,iVar2,lookUpAddStringHashResult);
  }
  return iVar2;
}

/* _GetAtomString @ 0x97b85c1c (144 bytes) */
int _GetAtomString(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  if ((0 < param_2) && (param_2 < param_1[0xc])) {
    iVar1 = *(int *)(param_2 * 4 + param_1[10]);
    if ((0 < iVar1) && (iVar1 < param_1[1])) {
      return (char *)(*param_1 + iVar1);
    }
    return "<internal error: bad soffset>";
  }
  if (param_2 == 0) {
    return "<null atom>";
  }
  if (param_2 == -1) {
    return "<EOF>";
  }
  return "<invalid atom>";
}

/* _GetReversedAtom @ 0x97b85cac (44 bytes) */
int _GetReversedAtom(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((0 < param_2) && (param_2 < *(int *)(param_1 + 0x30))) {
    return *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0x2c));
  }
  return 0;
}

