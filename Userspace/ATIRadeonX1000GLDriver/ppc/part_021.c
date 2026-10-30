#include "decls.h"

/* Compiler__propagateFlag5a1Bit1 @ 0xe15b8 (36 bytes) */
int Compiler__propagateFlag5a1Bit1(param_1)
  int param_1;
{
  uint uVar1;
  
  uVar1 = *(byte *)(param_1 + 0x5a1) >> 1 & 1;
  *(uint *)(*(int *)(param_1 + 0x370) + 0x28) = uVar1;
  *(uint *)(*(int *)(param_1 + 0x374) + 0x28) = uVar1;
  *(uint *)(*(int *)(param_1 + 0x378) + 0x28) = uVar1;
  return;
}

/* Compiler__selectEntry534ByProgramFlags @ 0xe15dc (64 bytes) */
int Compiler__selectEntry534ByProgramFlags(param_1)
  int param_1;
{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x6c4) + 0x30);
  if ((uVar1 & 1) != 0) {
    return *(undefined4 *)(param_1 + 0x534);
  }
  if ((uVar1 & 0x2000) != 0) {
    return *(undefined4 *)(param_1 + 0x538);
  }
  if ((uVar1 & 0x4000) != 0) {
    return *(undefined4 *)(param_1 + 0x53c);
  }
  return *(undefined4 *)(param_1 + 0x534);
}

/* FUN_000e161c @ 0xe161c (156 bytes) */
int FUN_000e161c(compiler, failureKind)
  int compiler;
  int failureKind;
{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(compiler + 0x47c) != 0) {
    if (failureKind == 5) {
LAB_000e1644:
      *(undefined4 *)(compiler + 0x318) = 1;
      *(int *)(compiler + 0x478) = *(int *)(compiler + 0x480) + -1;
      *(undefined4 *)(compiler + 0x314) = 0;
      *(undefined4 *)(compiler + 0x47c) = 0;
      return 1;
    }
    if (failureKind == 4) {
      iVar1 = 0;
      if (*(int *)(compiler + 0x6bc) != 0) goto LAB_000e1644;
      goto LAB_000e16a4;
    }
  }
  iVar1 = *(int *)(compiler + 0x6bc);
LAB_000e16a4:
  if ((iVar1 == 0) && (failureKind == 4)) {
    uVar2 = 1;
    *(undefined4 *)(compiler + 0x318) = 1;
    *(undefined4 *)(compiler + 0x6b8) = 1;
    *(undefined4 *)(compiler + 0x314) = 0;
    *(undefined4 *)(compiler + 0x6bc) = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* Compiler__selectBlockByProgramFlags @ 0xe16b8 (76 bytes) */
int Compiler__selectBlockByProgramFlags(param_1)
  int param_1;
{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x6c4) + 0x30);
  if ((uVar1 & 0x2000) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x398) + 0x38);
  }
  if ((uVar1 & 1) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x398) + 0x3c);
  }
  if ((uVar1 & 0x4000) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x398) + 0x40);
}

/* Compiler__setBitInSelectedBlockB8 @ 0xe1704 (88 bytes) */
int Compiler__setBitInSelectedBlockB8(program, bitIndex)
  undefined4 program;
  uint bitIndex;
{
  int wordIndex;
  int wordAddress;
  
  wordAddress = ((int (*)())Compiler__selectBlockByProgramFlags)(program);
  wordIndex = ((int)bitIndex >> 5) + (uint)((int)bitIndex < 0 && (bitIndex & 0x1f) != 0);
  wordAddress = wordIndex * 4 + wordAddress;
  *(uint *)(wordAddress + 0xb8) = 1 << (bitIndex + wordIndex * -0x20 & 0x3f) | *(uint *)(wordAddress + 0xb8);
  return;
}

/* Compiler__setBitInSelectedBlockD8 @ 0xe175c (88 bytes) */
int Compiler__setBitInSelectedBlockD8(program, bitIndex)
  undefined4 program;
  uint bitIndex;
{
  int wordIndex;
  int wordAddress;
  
  wordAddress = ((int (*)())Compiler__selectBlockByProgramFlags)(program);
  wordIndex = ((int)bitIndex >> 5) + (uint)((int)bitIndex < 0 && (bitIndex & 0x1f) != 0);
  wordAddress = wordIndex * 4 + wordAddress;
  *(uint *)(wordAddress + 0xd8) = 1 << (bitIndex + wordIndex * -0x20 & 0x3f) | *(uint *)(wordAddress + 0xd8);
  return;
}

/* Compiler__setBitInSelectedBlock98 @ 0xe17b4 (88 bytes) */
int Compiler__setBitInSelectedBlock98(program, bitIndex)
  undefined4 program;
  uint bitIndex;
{
  int wordIndex;
  int wordAddress;
  
  wordAddress = ((int (*)())Compiler__selectBlockByProgramFlags)(program);
  wordIndex = ((int)bitIndex >> 5) + (uint)((int)bitIndex < 0 && (bitIndex & 0x1f) != 0);
  wordAddress = wordIndex * 4 + wordAddress;
  *(uint *)(wordAddress + 0x98) = 1 << (bitIndex + wordIndex * -0x20 & 0x3f) | *(uint *)(wordAddress + 0x98);
  return;
}

/* Compiler__getOrCreateSlotObject @ 0xe180c (124 bytes) */
int Compiler__getOrCreateSlotObject(compiler, slotIndex)
  int compiler;
  int slotIndex;
{
  int *newObject;
  int slotAddr;
  
  slotAddr = slotIndex * 4 + compiler;
  if (*(int *)(slotAddr + 0x370) == 0) {
    newObject = (int *)Compiler__allocateOrFail(compiler,0x2c);
    if (newObject != (int *)0x0) {
      newObject[10] = 0;
      *newObject = compiler;
      newObject[1] = 0;
      newObject[2] = 0;
      newObject[3] = 0;
      newObject[4] = 0;
      newObject[5] = 0;
      newObject[6] = 0;
      newObject[7] = 0;
      newObject[8] = 0;
      newObject[9] = 0;
    }
    *(int **)(slotAddr + 0x370) = newObject;
  }
  return;
}

/* Compiler__resetState @ 0xe1888 (152 bytes) */
int Compiler__resetState(compiler)
  int compiler;
{
  int loopCounter;
  bool bVar1;
  int iVar2;
  undefined4 allocation;
  int loopCounterB;
  
  loopCounterB = 0x14;
  *(undefined4 *)(compiler + 0x530) = 0;
  *(undefined4 *)(compiler + 0x6c0) = 0;
  *(undefined4 *)(compiler + 0x314) = 0;
  *(undefined4 *)(compiler + 0x584) = 0;
  iVar2 = compiler;
  do {
    *(undefined4 *)(iVar2 + 0x484) = 0;
    *(undefined4 *)(iVar2 + 0x4d4) = 0;
    *(undefined4 *)(iVar2 + 0x534) = 0;
    iVar2 = iVar2 + 4;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  loopCounter = 0;
  do {
    ((int (*)())Compiler__getOrCreateSlotObject)(compiler,loopCounter);
    bVar1 = loopCounter != 2;
    loopCounter = loopCounter + 1;
  } while (bVar1);
  allocation = Arena__alloc(*(undefined4 *)(compiler + 0x370),0x2000);
  *(undefined4 *)(compiler + 0x3a0) = allocation;
  *(undefined4 *)(compiler + 0x3a8) = 0;
  *(undefined4 *)(compiler + 0x3a4) = 0;
  return Compiler__setDefaultOptions(compiler);
}

/* Compiler__init_e1920 @ 0xe1920 (232 bytes) */
int Compiler__init_e1920(compiler, allocatorUserData, allocateFn, freeFn, callbackField0, callbackField328, callbackField358, callbackField35c, callbackField360, callbackField364, callbackField368, callbackField36c)
  undefined4 *compiler;
  undefined4 allocatorUserData;
  code *allocateFn;
  undefined4 freeFn;
  undefined4 callbackField0;
  undefined4 callbackField328;
  undefined4 callbackField358;
  undefined4 callbackField35c;
  undefined4 callbackField360;
  undefined4 callbackField364;
  undefined4 callbackField368;
  undefined4 callbackField36c;
{
  int hwObject;
  undefined4 *puStack00000018;
  
  compiler[0x162] = 1;
  compiler[0xca] = callbackField328;
  compiler[0x11e] = 0x400;
  compiler[0xd7] = callbackField35c;
  compiler[0xd8] = callbackField360;
  compiler[0xd9] = callbackField364;
  compiler[0xd6] = callbackField358;
  compiler[0xda] = callbackField368;
  compiler[0xd3] = freeFn;
  *compiler = callbackField0;
  compiler[199] = 1;
  compiler[0xd5] = allocatorUserData;
  compiler[0xdb] = callbackField36c;
  compiler[1] = (int)(compiler + 2) + (-(int)(compiler + 2) & 7U);
  compiler[0xc3] = 0;
  compiler[0xc4] = 0;
  compiler[0x11f] = 0;
  compiler[0x120] = 0;
  compiler[0x1b1] = 0;
  compiler[0xd4] = allocateFn;
  compiler[200] = 0;
  compiler[0xdc] = 0;
  compiler[0xdd] = 0;
  compiler[0xde] = 0;
  puStack00000018 = compiler;
  hwObject = (*allocateFn)(allocatorUserData,0x1744,allocateFn,freeFn,callbackField0,callbackField328,callbackField358,compiler);
  *(undefined1 *)(puStack00000018 + 0xfe) = 0;
  if (hwObject == 0) {
    puStack00000018[0xc5] = 2;
  }
  else {
    KhanPs__ctor_129130(hwObject,puStack00000018,0);
    puStack00000018[0xc3] = hwObject;
    hwObject = _setjmp(puStack00000018[1]);
    if (hwObject == 0) {
      ((int (*)())Compiler__resetState)(puStack00000018);
      FUN_000e13b4(puStack00000018);
    }
  }
  return;
}

/* Compiler__init_e1a48 @ 0xe1a48 (232 bytes) */
int Compiler__init_e1a48(compiler, allocatorUserData, allocateFn, freeFn, callbackField0, callbackField328, callbackField358, callbackField35c, callbackField360, callbackField364, callbackField368, callbackField36c)
  undefined4 *compiler;
  undefined4 allocatorUserData;
  code *allocateFn;
  undefined4 freeFn;
  undefined4 callbackField0;
  undefined4 callbackField328;
  undefined4 callbackField358;
  undefined4 callbackField35c;
  undefined4 callbackField360;
  undefined4 callbackField364;
  undefined4 callbackField368;
  undefined4 callbackField36c;
{
  int hwObject;
  undefined4 *puStack00000018;
  
  compiler[0x162] = 1;
  compiler[0xca] = callbackField328;
  compiler[0x11e] = 0x400;
  compiler[0xd7] = callbackField35c;
  compiler[0xd8] = callbackField360;
  compiler[0xd9] = callbackField364;
  compiler[0xd6] = callbackField358;
  compiler[0xda] = callbackField368;
  compiler[0xd3] = freeFn;
  *compiler = callbackField0;
  compiler[199] = 1;
  compiler[0xd5] = allocatorUserData;
  compiler[0xdb] = callbackField36c;
  compiler[1] = (int)(compiler + 2) + (-(int)(compiler + 2) & 7U);
  compiler[0xc3] = 0;
  compiler[0xc4] = 0;
  compiler[0x11f] = 0;
  compiler[0x120] = 0;
  compiler[0x1b1] = 0;
  compiler[0xd4] = allocateFn;
  compiler[200] = 0;
  compiler[0xdc] = 0;
  compiler[0xdd] = 0;
  compiler[0xde] = 0;
  puStack00000018 = compiler;
  hwObject = (*allocateFn)(allocatorUserData,0x1744,allocateFn,freeFn,callbackField0,callbackField328,callbackField358,compiler);
  *(undefined1 *)(puStack00000018 + 0xfe) = 0;
  if (hwObject == 0) {
    puStack00000018[0xc5] = 2;
  }
  else {
    KhanPs__ctor_129130(hwObject,puStack00000018,0);
    puStack00000018[0xc3] = hwObject;
    hwObject = _setjmp(puStack00000018[1]);
    if (hwObject == 0) {
      ((int (*)())Compiler__resetState)(puStack00000018);
      FUN_000e13b4(puStack00000018);
    }
  }
  return;
}

/* Compiler__setHardwareFamily @ 0xe1b70 (172 bytes) */
int Compiler__setHardwareFamily(compiler, chipFamily)
  int compiler;
  int chipFamily;
{
  int iVar1;
  
  if (*(int *)(compiler + 0x30c) != 0) {
    (**(code **)(compiler + 0x34c))(*(undefined4 *)(compiler + 0x354),*(int *)(compiler + 0x30c));
    *(undefined4 *)(compiler + 0x30c) = 0;
  }
  if (0 < chipFamily) {
    if (chipFamily < 4) {
      iVar1 = Compiler__allocateOrFail(compiler,0x10);
      if (iVar1 != 0) {
        KhanChip__ctor_10e114(iVar1,compiler);
      }
      *(int *)(compiler + 0x310) = iVar1;
      if (chipFamily == 2) {
        FUN_0010dd54(*(undefined4 *)(iVar1 + 4));
        *(undefined4 *)(0x00001740 + *(int *)(*(int *)(compiler + 0x310) + 8)) = 2;
      }
    }
    else if (chipFamily == 4) {
      iVar1 = Compiler__allocateOrFail(compiler,0x10);
      if (iVar1 != 0) {
        FudoChip__ctor_10e1d8(iVar1,compiler);
      }
      *(int *)(compiler + 0x310) = iVar1;
    }
  }
  return;
}

/* Program__forwardMulOperandToUsers @ 0xe1c50 (916 bytes) */
int Program__forwardMulOperandToUsers(program, passThroughR4, unusedArg3, argR6, unusedArg5, unusedArg6, unusedArg7)
  int program;
  undefined4 passThroughR4;
  undefined4 unusedArg3;
  undefined4 argR6;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  int *userSlot;
  int *replacementSource;
  int userByteOffset;
  int nextBlock;
  int *operandVReg;
  int *operandVReg2;
  int block;
  int *nextInst;
  int *followingInst;
  int iVar4;
  uint userCountCheck;
  undefined4 compiler;
  uint userCount;
  uint loopIndex2;
  int *inst;
  uint userIndex;
  int loopIndex;
  uint *userVector;
  int userInst;
  
  if (((*(uint *)(program + 0x30) & 1) == 0) && ((*(uint *)(program + 0x30) & 0x2000) != 0)) {
    compiler = *(undefined4 *)(program + 8);
    block = *(int *)(program + 900);
    for (nextBlock = *(int *)(*(int *)(program + 900) + 8); nextBlock != 0; nextBlock = *(int *)(nextBlock + 8)) {
      nextInst = (int *)(*(int **)(block + 0x98))[2];
      inst = *(int **)(block + 0x98);
      if (nextInst != (int *)0x0) {
        do {
          followingInst = nextInst;
          if ((inst[5] & 1U) != 0) {
            if (*(int *)(inst[0x22] + 8) == 0x13) {
              replacementSource = (int *)IRInst__getOperandSource(inst,1);
              operandVReg = (int *)IRInst__getOperandSource(inst,2);
              iVar4 = (**(code **)(*replacementSource + 0x4c))(replacementSource);
              if (((iVar4 != 0) && (iVar4 = (**(code **)(*operandVReg + 0x48))(operandVReg), iVar4 != 0)) ||
                 ((iVar4 = (**(code **)(*operandVReg + 0x4c))(operandVReg), iVar4 != 0 &&
                  (iVar4 = (**(code **)(*replacementSource + 0x48))(replacementSource), iVar4 != 0)))) {
                iVar4 = (**(code **)(*replacementSource + 0x4c))(replacementSource);
                if (iVar4 == 0) {
                  replacementSource = operandVReg;
                }
                userVector = (uint *)inst[4];
                userCount = userVector[1];
                userIndex = userCount - 1;
                if (-1 < (int)userIndex) {
                  userByteOffset = userIndex * 4;
                  loopIndex2 = 0;
                  do {
                    if (userIndex < *userVector) {
                      userCountCheck = userVector[1];
                      if (userCountCheck <= userIndex) {
                        _memset(userCountCheck * 4 + userVector[2],0,(userIndex - userCountCheck) * 4 + 4);
                        userVector[1] = userIndex + 1;
                      }
                      userSlot = (int *)(userByteOffset + userVector[2]);
                    }
                    else {
                      userSlot = (int *)Vector__elementRefGrow(userVector,userIndex);
                    }
                    userInst = *userSlot;
                    if (0 < *(int *)(userInst + 0x84)) {
                      loopIndex = 1;
                      do {
                        operandVReg = (int *)IRInst__getOperandSource(userInst,loopIndex);
                        if (inst == operandVReg) {
                          IRInst__setOperandSource(userInst,loopIndex,replacementSource,1,compiler);
                          break;
                        }
                        loopIndex = loopIndex + 1;
                      } while (loopIndex <= *(int *)(userInst + 0x84));
                    }
                    loopIndex2 = loopIndex2 + 1;
                    userIndex = userIndex - 1;
                    userByteOffset = userByteOffset + -4;
                    if (userCount == loopIndex2) break;
                    userVector = (uint *)inst[4];
                  } while( true );
                }
              }
            }
            iVar4 = (**(code **)(*inst + 100))(inst);
            if ((iVar4 != 0) && ((inst[0x49] != 0 || (inst[0x48] != 0)))) {
              operandVReg2 = (int *)IRInst__getOperandSource(inst,1);
              iVar4 = (**(code **)(*operandVReg2 + 0x4c))(operandVReg2);
              if (iVar4 != 0) {
                userVector = (uint *)inst[4];
                userCount = userVector[1];
                userIndex = userCount - 1;
                if (-1 < (int)userIndex) {
                  userByteOffset = userIndex * 4;
                  loopIndex2 = 0;
                  do {
                    if (userIndex < *userVector) {
                      userCountCheck = userVector[1];
                      if (userCountCheck <= userIndex) {
                        _memset(userCountCheck * 4 + userVector[2],0,(userIndex - userCountCheck) * 4 + 4);
                        userVector[1] = userIndex + 1;
                      }
                      userSlot = (int *)(userByteOffset + userVector[2]);
                    }
                    else {
                      userSlot = (int *)Vector__elementRefGrow(userVector,userIndex);
                    }
                    userInst = *userSlot;
                    if (0 < *(int *)(userInst + 0x84)) {
                      loopIndex = 1;
                      do {
                        operandVReg = (int *)IRInst__getOperandSource(userInst,loopIndex);
                        if (inst == operandVReg) {
                          IRInst__setOperandSource(userInst,loopIndex,operandVReg2,1,compiler);
                          break;
                        }
                        loopIndex = loopIndex + 1;
                      } while (loopIndex <= *(int *)(userInst + 0x84));
                    }
                    loopIndex2 = loopIndex2 + 1;
                    userIndex = userIndex - 1;
                    userByteOffset = userByteOffset + -4;
                    if (loopIndex2 == userCount) break;
                    userVector = (uint *)inst[4];
                  } while( true );
                }
              }
            }
            followingInst = (int *)inst[2];
          }
          nextInst = (int *)followingInst[2];
          inst = followingInst;
        } while ((int *)followingInst[2] != (int *)0x0);
        nextBlock = *(int *)(block + 8);
      }
      block = nextBlock;
    }
  }
  return;
}

/* Compiler__releaseChipAndPools @ 0xe1fe4 (160 bytes) */
int Compiler__releaseChipAndPools(compiler, releaseChip)
  int compiler;
  int releaseChip;
{
  int iVar1;
  
  if ((releaseChip != 0) && (*(int *)(compiler + 0x310) != 0)) {
    FUN_0010defc(*(int *)(compiler + 0x310),compiler);
    (**(code **)(compiler + 0x34c))
              (*(undefined4 *)(compiler + 0x354),*(undefined4 *)(compiler + 0x310));
  }
  iVar1 = compiler;
  do {
    if (*(int *)(iVar1 + 0x370) != 0) {
      List__freeAllNodes(*(int *)(iVar1 + 0x370));
      (**(code **)(compiler + 0x34c))
                (*(undefined4 *)(compiler + 0x354),*(undefined4 *)(iVar1 + 0x370));
      *(undefined4 *)(iVar1 + 0x370) = 0;
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 != compiler + 0xc);
  return;
}

/* Compiler__compileStages @ 0xe2094 (292 bytes) */
int Compiler__compileStages(compiler, compileRequest)
  int compiler;
  int compileRequest;
{
  undefined4 secondSource;
  undefined4 *readerAlloc;
  int currentProgramValue;
  int stageByteOffset;
  int compilerArg;
  int stageIndexCopy;
  int pairInstructionsEnabled;
  int mapChannelsEnabled;
  int reduceDepEnabled;
  int markIgnoreUncoveredEnabled;
  int packInstsEnabled;
  int removeEmptyGraphEnabled;
  int peepholeEnabled;
  int deadCodeEnabled;
  undefined4 arenaAt378;
  int stageIndex;
  int nextStageIndex;
  undefined4 *programAlloc;
  int argR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  char *sourceTable;
  undefined4 stageSource;
  undefined4 arenaAt374;
  undefined4 *ilReader;
  undefined8 deleteComputationsThatCouldBeVsEnabled;
  
  ((int (*)())Compiler__propagateFlag5a1Bit1)(compiler);
  *(char **)(compiler + 0x5a8) = "INITIAL_INPUT";
  *(char **)(compiler + 0x5bc) = "BUILD_SSA";
  *(char **)(compiler + 0x5d0) = "REDUCE_DEP";
  *(char **)(compiler + 0x5e4) = "PEEPHOLE";
  *(char **)(compiler + 0x5f8) = "SCHED";
  *(char **)(compiler + 0x60c) = "REPLACE_PHI";
  sourceTable = "ASSEMBLY";
  *(char **)(compiler + 0x620) = "GLOBAL_ALLOC";
  *(char **)(compiler + 0x634) = "ASSEMBLY";
  FUN_00115fa0(compiler);
  stageIndex = *(int *)(compileRequest + 8) + -1;
  *(int *)(compiler + 0x52c) = stageIndex;
  while (-1 < stageIndex) {
    FUN_000e13b4(compiler);
    stageIndexCopy = *(int *)(compiler + 0x52c);
    if (stageIndexCopy < 2) {
      stageSource = *(undefined4 *)(stageIndexCopy * 4 + compileRequest + 0xc);
    }
    else {
      sourceTable = *(char **)(compileRequest + 0x14);
      stageSource = *(undefined4 *)(sourceTable + stageIndexCopy * 4);
    }
    arenaAt374 = *(undefined4 *)(compiler + COMP_arenaA);
    programAlloc = (undefined4 *)Arena__alloc(arenaAt374,0x484);
    *programAlloc = arenaAt374;
    Program__ctor_ee29c(programAlloc + 1,compiler);
    arenaAt378 = *(undefined4 *)(compiler + COMP_arenaB);
    *(undefined4 **)(compiler + COMP_currentProgram) = programAlloc + 1;
    readerAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x290);
    ilReader = readerAlloc + 1;
    *readerAlloc = arenaAt378;
    compilerArg = compiler;
    ILReader__ctor_e5570(ilReader,stageSource,compiler);
    if ((*(uint *)(compileRequest + 4) & 0x20) != 0) {
      nextStageIndex = *(int *)(compiler + 0x52c) + 1;
      if (nextStageIndex < 2) {
        secondSource = *(undefined4 *)(nextStageIndex * 4 + compileRequest + 0xc);
      }
      else {
        sourceTable = *(char **)(compileRequest + 0x14);
        secondSource = *(undefined4 *)(sourceTable + nextStageIndex * 4);
      }
      ((int (*)())setWord30)(ilReader,secondSource);
    }
    (**(code **)(**(int **)(compiler + COMP_target) + 0x60))(*(int **)(compiler + COMP_target));
    Program__initAndTranslate(*(undefined4 *)(compiler + COMP_currentProgram),ilReader);
    if (ilReader != (undefined4 *)0x0) {
      ((int (*)())ILReader__dtor_e4934)(ilReader);
      Arena__free(*readerAlloc,readerAlloc);
    }
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaB));
    FUN_00122de8(*(undefined4 *)(compiler + COMP_currentProgram));
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaB));
    reduceDepEnabled = Compiler__isOptionEnabled(compiler,0xf);
    if (reduceDepEnabled != 0) {
      FUN_0013d3b8(*(undefined4 *)(compiler + COMP_currentProgram));
      FUN_0013da3c(*(undefined4 *)(compiler + COMP_currentProgram));
    }
    mapChannelsEnabled = Compiler__isOptionEnabled(compiler,0x34);
    if (mapChannelsEnabled != 0) {
      FUN_0013a8a4(*(undefined4 *)(compiler + COMP_currentProgram));
    }
    pairInstructionsEnabled = Compiler__isOptionEnabled(compiler,0x35);
    if (pairInstructionsEnabled != 0) {
      FUN_0013fc38(*(undefined4 *)(compiler + COMP_currentProgram));
    }
    deleteComputationsThatCouldBeVsEnabled = Compiler__isOptionEnabled(compiler,0x10);
    if ((int)((ulonglong)deleteComputationsThatCouldBeVsEnabled >> 0x20) != 0) {
      ((int (*)())Program__forwardMulOperandToUsers)(*(undefined4 *)(compiler + COMP_currentProgram),(int)deleteComputationsThatCouldBeVsEnabled,compilerArg,argR6,staleArgR7,staleArgR8,sourceTable);
    }
    *(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) = *(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) | 0x80
    ;
    deadCodeEnabled = Compiler__isOptionEnabled(compiler,0x11);
    if (deadCodeEnabled != 0) {
      Program__eliminateDeadInstsAndRecountUses(*(undefined4 *)(compiler + COMP_currentProgram),0);
    }
    peepholeEnabled = Compiler__isOptionEnabled(compiler,0x1a);
    if (peepholeEnabled == 0) {
      *(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) =
           *(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 0xffffff7f;
    }
    else {
      pass_rewrite(*(undefined4 *)(compiler + COMP_currentProgram));
    }
    removeEmptyGraphEnabled = Compiler__isOptionEnabled(compiler,0x20);
    if (removeEmptyGraphEnabled != 0) {
      pass_remove_empty_graphs(*(undefined4 *)(compiler + COMP_currentProgram));
    }
    packInstsEnabled = Compiler__isOptionEnabled(compiler,0x12);
    if (packInstsEnabled != 0) {
      FUN_0013da3c(*(undefined4 *)(compiler + COMP_currentProgram));
      *(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) =
           *(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) | 0x80;
      deadCodeEnabled = Compiler__isOptionEnabled(compiler,0x11);
      if (deadCodeEnabled != 0) {
        Program__eliminateDeadInstsAndRecountUses(*(undefined4 *)(compiler + COMP_currentProgram),0);
      }
      FUN_0014657c(*(undefined4 *)(compiler + COMP_currentProgram));
      *(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) =
           *(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 0xffffff7f;
    }
    markIgnoreUncoveredEnabled = Compiler__isOptionEnabled(compiler,0x22);
    if (markIgnoreUncoveredEnabled != 0) {
      FUN_00139d40(*(undefined4 *)(compiler + COMP_currentProgram));
    }
    pass_assign_slots(*(undefined4 *)(compiler + COMP_currentProgram));
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaB));
    Scheduler__run(*(undefined4 *)(compiler + COMP_currentProgram));
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaB));
    FUN_00120cd4(*(undefined4 *)(compiler + COMP_currentProgram));
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaB));
    FUN_00134658(*(undefined4 *)(compiler + COMP_currentProgram));
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaB));
    Program__dumpConstantRegisters(*(undefined4 *)(compiler + COMP_currentProgram),compiler);
    *(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) =
         *(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) | 0x10000;
    pass_optimize_control_flow(*(undefined4 *)(compiler + COMP_currentProgram));
    ((int (*)())MachineCodeWriter__encodeProgram)(*(undefined4 *)(compiler + COMP_currentProgram),*(int *)(compiler + 0x52c) * 4 + compiler + 0x484,
                 *(int *)(compiler + 0x52c));
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaB));
    FUN_0013061c(*(undefined4 *)(compiler + COMP_currentProgram),0);
    (**(code **)(**(int **)(compiler + COMP_target) + 0x38))
              (*(int **)(compiler + COMP_target),*(undefined4 *)(compiler + 0x52c),compiler);
    sourceTable = (char *)**(undefined4 **)(compiler + COMP_target);
    stageByteOffset = *(int *)(compiler + 0x52c) * 4 + compiler;
    argR6 = compiler;
    (**(code **)(sourceTable + 0x8c))
              (*(undefined4 **)(compiler + COMP_target),*(undefined4 *)(stageByteOffset + 0x524),
               *(undefined4 *)(stageByteOffset + 0x4d4));
    currentProgramValue = *(int *)(compiler + COMP_currentProgram);
    if (currentProgramValue != 0) {
      Program__dtor_ecfac(currentProgramValue);
      Arena__free(*(undefined4 *)(currentProgramValue + -4),currentProgramValue + -4);
    }
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaA));
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaB));
    stageIndex = *(int *)(compiler + 0x52c) + -1;
    *(int *)(compiler + 0x52c) = stageIndex;
  }
  return;
}

/* Compiler__compileWithRetry @ 0xe2524 (324 bytes) */
int Compiler__compileWithRetry(compiler, result, request, requestFlags, compileInput)
  int compiler;
  int result;
  undefined4 request;
  undefined4 requestFlags;
  undefined4 compileInput;
{
  int iVar1;
  int iVar2;
  int iStack00000018;
  int iStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  
  *(undefined4 *)(compiler + 0x398) = compileInput;
  iStack00000018 = compiler;
  iStack0000001c = result;
  uStack00000020 = request;
  uStack00000024 = requestFlags;
  FUN_000e0ca8(compiler);
  do {
    iVar1 = _setjmp(*(undefined4 *)(iStack00000018 + 4));
    if (iVar1 == 0) {
      ((int (*)())Compiler__resetState)(iStack00000018);
      Compiler__applyRequestFlags(iStack00000018,uStack00000024);
      iVar1 = FUN_00193c00(uStack00000020,iStack00000018);
      *(int *)(iStack00000018 + 0x524) = iStack0000001c;
      if ((*(uint *)(iVar1 + 4) & 4) == 0) {
        if ((*(uint *)(iVar1 + 4) & 2) == 0) {
          *(undefined4 *)(iStack0000001c + 0xf8) = 2;
        }
        else {
          *(undefined4 *)(iStack0000001c + 0xf8) = 0;
        }
      }
      else {
        *(undefined4 *)(iStack0000001c + 0xf8) = 1;
      }
      *(undefined4 *)(iStack0000001c + 0xfc) =
           *(undefined4 *)(*(int *)(iStack00000018 + 0x398) + 0x28);
      ((int (*)())Compiler__compileStages)(iStack00000018,iVar1);
      if (iVar1 != 0) {
        FUN_00193be8(iVar1);
        Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
      }
    }
    *(undefined4 *)(iStack00000018 + 0x4d8) = 0;
    *(undefined4 *)(iStack00000018 + 0x484) = 0;
    *(undefined4 *)(iStack00000018 + 0x4d4) = 0;
    *(undefined4 *)(iStack00000018 + 0x488) = 0;
    iVar1 = *(int *)(iStack00000018 + 0x314);
    FUN_000e0e28(iStack00000018);
    ((int (*)())Compiler__releaseChipAndPools)(iStack00000018,0);
  } while ((iVar1 != 0) && (iVar2 = ((int (*)())FUN_000e161c)(iStack00000018,iVar1), iVar2 != 0));
  return iVar1;
}

/* Compiler__compile @ 0xe2668 (280 bytes) */
int Compiler__compile(compiler, shader, sourceA, sourceB, optionsArg, unusedArg6, emitContext)
  int compiler;
  int shader;
  undefined4 sourceA;
  undefined4 sourceB;
  undefined4 optionsArg;
  undefined4 unusedArg6;
  undefined4 emitContext;
{
  int iVar1;
  int retryHandled;
  int iStack00000018;
  int iStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  
  *(undefined4 *)(compiler + 0x398) = emitContext;
  iStack00000018 = compiler;
  iStack0000001c = shader;
  uStack00000020 = sourceA;
  uStack00000024 = sourceB;
  uStack00000028 = optionsArg;
  FUN_000e0ca8(compiler);
  do {
    iVar1 = _setjmp(*(undefined4 *)(iStack00000018 + 4));
    if (iVar1 == 0) {
      ((int (*)())Compiler__resetState)(iStack00000018);
      Compiler__applyRequestFlags(iStack00000018,uStack00000028);
      iVar1 = FUN_00193b3c(uStack00000020,uStack00000024,iStack00000018);
      *(int *)(iStack00000018 + 0x524) = iStack0000001c;
      *(undefined4 *)(iStack0000001c + 0xf8) = 0;
      *(undefined4 *)(iStack0000001c + 0xfc) =
           *(undefined4 *)(*(int *)(iStack00000018 + 0x398) + 0x28);
      ((int (*)())Compiler__compileStages)(iStack00000018,iVar1);
      if (iVar1 != 0) {
        FUN_00193be8(iVar1);
        Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
      }
    }
    *(undefined4 *)(iStack00000018 + 0x4d8) = 0;
    *(undefined4 *)(iStack00000018 + 0x484) = 0;
    *(undefined4 *)(iStack00000018 + 0x4d4) = 0;
    *(undefined4 *)(iStack00000018 + 0x488) = 0;
    iVar1 = *(int *)(iStack00000018 + 0x314);
    FUN_000e0e28(iStack00000018);
    ((int (*)())Compiler__releaseChipAndPools)(iStack00000018,0);
  } while ((iVar1 != 0) && (retryHandled = ((int (*)())FUN_000e161c)(iStack00000018,iVar1), retryHandled != 0));
  return iVar1;
}

/* MachineCodeWriter__accumulateStats @ 0xe2780 (140 bytes) */
int MachineCodeWriter__accumulateStats(writer, encoderState)
  undefined4 *writer;
  int encoderState;
{
  writer[0xa4] = writer[0xa4] + *(int *)(encoderState + 4);
  writer[0xa5] = writer[0xa5] + *(int *)(encoderState + 8);
  writer[0xa6] = writer[0xa6] + *(int *)(encoderState + 0xc);
  writer[0xa7] = writer[0xa7] + *(int *)(encoderState + 0x10);
  writer[0xa8] = writer[0xa8] + *(int *)(encoderState + 0x14);
  writer[0xa9] = writer[0xa9] + *(int *)(encoderState + 0x18);
  writer[0xaa] = writer[0xaa] + *(int *)(encoderState + 0x1c);
                    
                    
  (**(code **)(**(int **)(encoderState + 0x20) + 0x1c))(*(int **)(encoderState + 0x20),*writer);
  return;
}

/* FUN_000e280c @ 0xe280c (44 bytes) */
int FUN_000e280c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x6c))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,param_3,param_2,
             *(undefined4 *)(param_1 + 0xa8));
  return;
}

/* FUN_000e2838 @ 0xe2838 (20 bytes) */
int FUN_000e2838(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
                    
                    
  (**(code **)(**(int **)(param_1 + 0x20) + 0x30))(*(int **)(param_1 + 0x20),param_2,param_3);
  return;
}

/* FUN_000e284c @ 0xe284c (20 bytes) */
int FUN_000e284c(param_1)
  int param_1;
{
  undefined4 uVar1;
  
                    
                    
  uVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 8))(*(int **)(param_1 + 0x20));
  return uVar1;
}

/* Block__accept @ 0xe2860 (36 bytes) */
int Block__accept(this, traversal)
  int this;
  int traversal;
{
                    
                    
  (**(code **)(**(int **)(traversal + 0x20) + 0x34))
            (*(int **)(traversal + 0x20),this + 0x90,*(undefined4 *)(this + 0xdc));
  return;
}

/* IfFooterStatic__accept @ 0xe28f0 (96 bytes) */
int IfFooterStatic__accept(this, traversal)
  int this;
  int traversal;
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(this + 0xdc);
  (**(code **)(**(int **)(traversal + 0x20) + 0x74))(*(int **)(traversal + 0x20),traversal);
                    
                    
  (**(code **)(**(int **)(traversal + 0x20) + 0x34))(*(int **)(traversal + 0x20),this + 0x90,uVar1);
  return;
}

/* FUN_000e2a04 @ 0xe2a04 (64 bytes) */
int FUN_000e2a04(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (iVar1 < 0) {
    iVar1 = FUN_00130690(*(undefined4 *)(param_1 + 0x34),param_2);
    *(int *)(param_1 + 0x30) = iVar1;
  }
  return iVar1;
}

/* moduloDifference @ 0xe2a44 (16 bytes) */
int moduloDifference(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = param_1 - param_2;
  if (-1 < iVar1) {
    return iVar1;
  }
  return iVar1 + param_3;
}

/* IRStartCallRoutine__acceptCallPseudo @ 0xe2a54 (28 bytes) */
int IRStartCallRoutine__acceptCallPseudo(this, visitor)
  undefined4 this;
  int *visitor;
{
                    
                    
  (**(code **)(*visitor + 0xac))(visitor,this);
  return;
}

/* IREndCallRoutine__acceptCallPseudo @ 0xe2a70 (28 bytes) */
int IREndCallRoutine__acceptCallPseudo(this, visitor)
  undefined4 this;
  int *visitor;
{
                    
                    
  (**(code **)(*visitor + 0xb0))(visitor,this);
  return;
}

/* IRStartMakeCall__acceptCallPseudo @ 0xe2a8c (28 bytes) */
int IRStartMakeCall__acceptCallPseudo(this, visitor)
  undefined4 this;
  int *visitor;
{
                    
                    
  (**(code **)(*visitor + 0xb4))(visitor,this);
  return;
}

/* IREndMakeCall__acceptCallPseudo @ 0xe2aa8 (28 bytes) */
int IREndMakeCall__acceptCallPseudo(this, visitor)
  undefined4 this;
  int *visitor;
{
                    
                    
  (**(code **)(*visitor + 0xb8))(visitor,this);
  return;
}

/* FUN_000e2acc @ 0xe2acc (156 bytes) */
int FUN_000e2acc(inst, param_2, param_3)
  int *inst;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int loopIndex;
  
  loopIndex = 1;
  while( true ) {
    iVar2 = (**(code **)(*inst + 0x14))(inst);
    if (iVar2 < loopIndex) {
      return 0;
    }
    iVar2 = IRInst__getOperandSource(inst,loopIndex);
    iVar1 = thunk_FUN_00134de8(*(undefined4 *)(param_3 + 0x6c4),iVar2);
    if ((iVar1 == param_2) && (iVar2 = RegKind__flagBit7(*(undefined4 *)(iVar2 + 0x98)), iVar2 == 0))
    break;
    loopIndex = loopIndex + 1;
  }
  return 1;
}

/* FUN_000e2b68 @ 0xe2b68 (140 bytes) */
int FUN_000e2b68(inst, operandIndex)
  undefined4 inst;
  undefined4 operandIndex;
{
  int operandRecord;
  int *a0;
  int iVar1;
  undefined4 local_18 [2];
  
  a0 = (int *)IRInst__getOperandSource(inst,operandIndex);
  iVar1 = (**(code **)(*a0 + 0x48))(a0);
  if ((iVar1 != 0) && (a0[0x26] == 0xc)) {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    SelectWord__compose(local_18,a0[0x55],*(undefined4 *)(operandRecord + 0x10));
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    *(undefined4 *)(operandRecord + 0x10) = local_18[0];
  }
  return;
}

/* FUN_000e2bf4 @ 0xe2bf4 (132 bytes) */
int FUN_000e2bf4(block, callArg)
  int block;
  undefined4 callArg;
{
  int *scanInst;
  int *nextInstLink;
  
  scanInst = *(int **)(block + 8);
  for (nextInstLink = (int *)(*(int **)(block + 8))[2]; nextInstLink != (int *)0x0; nextInstLink = (int *)nextInstLink[2])
  {
    if (((scanInst[5] & 1U) != 0) && (*(int *)(scanInst[0x22] + 8) != 0x57)) {
      (**(code **)(*scanInst + 0x84))(scanInst,callArg);
      nextInstLink = (int *)scanInst[2];
    }
    scanInst = nextInstLink;
  }
  return;
}

/* ConstRecord__emitStores @ 0xe2c78 (620 bytes) */
int ConstRecord__emitStores(constRecord, hwDescription, program)
  int constRecord;
  int *hwDescription;
  int program;
{
  undefined4 laneValue2;
  undefined4 destRegisterId3;
  undefined4 laneValue3;
  undefined4 laneValueInt;
  undefined4 laneValue1;
  int recordKind2;
  int programArg;
  int laneRecordB;
  int laneRecord0;
  bool notLastLane;
  short laneHigh;
  int recordKind;
  int laneKind;
  undefined4 targetBlock;
  float laneFloat;
  uint loopCounter;
  undefined4 emitContext2;
  int laneValuePtr;
  undefined4 laneValue0;
  undefined4 laneValue4;
  undefined4 destRegisterId;
  undefined4 destRegisterId2;
  undefined4 emitContext3;
  undefined4 emitContext;
  int laneRecord;
  
  recordKind = *(int *)(constRecord + 0x98);
  if (recordKind == 3) {
    loopCounter = 0;
    laneRecord0 = constRecord;
    do {
      if (((int)*(char *)(constRecord + 0x15c) >> (loopCounter & 0x3f) & 1U) != 0) {
        laneRecord = *(int *)(laneRecord0 + 0x20);
        destRegisterId = *(undefined4 *)(constRecord + 0x94);
        emitContext = *(undefined4 *)(program + 0x398);
        targetBlock = ((int (*)())Compiler__selectBlockByProgramFlags)(program);
        ConstBank__storeBoolLane(emitContext,destRegisterId,(uint)(laneRecord == 1),loopCounter,targetBlock,0);
      }
      notLastLane = loopCounter != 3;
      laneRecord0 = laneRecord0 + 0x18;
      loopCounter = loopCounter + 1;
    } while (notLastLane);
    return;
  }
  if (recordKind < 4) {
    if (recordKind != 2) {
      return;
    }
  }
  else {
    if (recordKind == 4) {
      loopCounter = 0;
      laneRecordB = constRecord;
      laneRecord = constRecord;
      do {
        if (((int)*(char *)(constRecord + 0x15c) >> (loopCounter & 0x3f) & 1U) != 0) {
          laneKind = *(int *)(laneRecord + 0x1c);
          if (laneKind == 3) {
            destRegisterId3 = *(undefined4 *)(constRecord + 0x94);
            laneValueInt = *(undefined4 *)(laneRecord + 0x20);
            emitContext2 = *(undefined4 *)(program + 0x398);
            targetBlock = ((int (*)())Compiler__selectBlockByProgramFlags)(program);
            ConstBank__storeIntLane(emitContext2,destRegisterId3,laneValueInt,loopCounter,targetBlock,0);
          }
          else {
            destRegisterId2 = *(undefined4 *)(laneRecordB + 0x94);
            laneValue0 = *(undefined4 *)(laneRecord + 0x20);
            laneValue1 = *(undefined4 *)(laneRecord + 0x24);
            laneValue2 = *(undefined4 *)(laneRecord + 0x28);
            laneValue3 = *(undefined4 *)(laneRecord + 0x2c);
            emitContext3 = *(undefined4 *)(program + 0x398);
            laneValue4 = *(undefined4 *)(laneRecord + 0x30);
            targetBlock = ((int (*)())Compiler__selectBlockByProgramFlags)(program);
            ConstBank__addMappedEntry(emitContext3,destRegisterId2,loopCounter,laneKind,laneValue0,laneValue1,laneValue2,laneValue3,laneValue4,targetBlock);
          }
        }
        notLastLane = loopCounter != 3;
        laneRecordB = laneRecordB + 0x18;
        laneRecord = laneRecord + 0x18;
        loopCounter = loopCounter + 1;
      } while (notLastLane);
      return;
    }
    if (recordKind != 0xc) {
      return;
    }
  }
  recordKind2 = *(int *)(constRecord + 0x98);
  loopCounter = 0;
  laneValuePtr = constRecord + 0x1c;
  programArg = program;
  laneRecord = constRecord;
  do {
    if (((int)*(char *)(constRecord + 0x15c) >> (loopCounter & 0x3f) & 1U) != 0) {
      if (*(int *)(laneRecord + 0x1c) == 1) {
        destRegisterId = *(undefined4 *)(constRecord + 0x94);
        laneHigh = *(short *)(laneRecord + 0x22);
        emitContext = *(undefined4 *)(program + 0x398);
        programArg = (int)*(short *)(laneRecord + 0x20);
        targetBlock = ((int (*)())Compiler__selectBlockByProgramFlags)(program);
        scStoreIntConstantComponent(emitContext,destRegisterId,programArg,(int)laneHigh,loopCounter,targetBlock);
      }
      else {
        laneFloat = GH_U2F((unsigned int)((**(code **)(*hwDescription + 0x8c))(hwDescription,laneValuePtr)));
        destRegisterId = *(undefined4 *)(constRecord + 0x94);
        emitContext = *(undefined4 *)(program + 0x398);
        targetBlock = ((int (*)())Compiler__selectBlockByProgramFlags)(program);
        ((undefined4 (*)())scStoreConstantComponent)(emitContext,destRegisterId,programArg,loopCounter,targetBlock,(uint)(recordKind2 == 0xc),(double)laneFloat);
      }
    }
    notLastLane = loopCounter != 3;
    laneValuePtr = laneValuePtr + 0x18;
    laneRecord = laneRecord + 0x18;
    loopCounter = loopCounter + 1;
  } while (notLastLane);
  return;
}

/* FUN_000e2ee4 @ 0xe2ee4 (32 bytes) */
int FUN_000e2ee4(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
                    
                    
  (**(code **)(*(int *)param_1[8] + 0x94))((int *)param_1[8],param_2,param_2 + 0x90,*param_1);
  return;
}

/* FUN_000e2f04 @ 0xe2f04 (136 bytes) */
int FUN_000e2f04(param_1, param_2, param_3, newSource, compiler)
  int param_1;
  int param_2;
  int param_3;
  undefined4 newSource;
  undefined4 compiler;
{
  int *newInst;
  
  newInst = (int *)IRInst__create(0x31,compiler);
  newInst[0x25] = param_2;
  newInst[0x26] = param_3;
  IRInst__setOperandSource(newInst,1,newSource,0,compiler);
  *(int *)(param_1 + 0x94) = param_2;
  *(int *)(param_1 + 0x98) = param_3;
  (**(code **)(*newInst + 0x84))(newInst,*(undefined4 *)(param_1 + 0x11c));
  return newInst;
}

/* IRInst__lastSourceKeyEquals @ 0xe2f8c (76 bytes) */
int IRInst__lastSourceKeyEquals(inst, key, compiler)
  int inst;
  int key;
  int compiler;
{
  undefined4 operandVReg;
  int iVar2;
  
  operandVReg = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
  iVar2 = thunk_FUN_00134de8(*(undefined4 *)(compiler + 0x6c4),operandVReg);
  return iVar2 == key;
}

/* MachineAssembler__vslot34_declareDestinationLanesByClass @ 0xe2fd8 (360 bytes) */
int MachineAssembler__vslot34_declareDestinationLanesByClass(this, inst)
  int this;
  int inst;
{
  int loopCounter;
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int operandRecord;
  
  iVar2 = *(int *)(inst + 0x98);
  if ((iVar2 == 2) || (iVar2 == 0xc)) {
    loopCounter = 0;
    uVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),inst);
    do {
      operandRecord = IRInst__getOperandRecord(inst,0);
      if (*(char *)(loopCounter + operandRecord + 0x10) != '\x01') {
        ((int (*)())Compiler__setBitInSelectedBlock98)(*(undefined4 *)(this + 0xc),uVar3);
      }
      bVar1 = loopCounter != 3;
      loopCounter = loopCounter + 1;
    } while (bVar1);
  }
  else if (iVar2 == 4) {
    loopCounter = 0;
    uVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),inst);
    do {
      operandRecord = IRInst__getOperandRecord(inst,0);
      if (*(char *)(loopCounter + operandRecord + 0x10) != '\x01') {
        ((int (*)())Compiler__setBitInSelectedBlockD8)(*(undefined4 *)(this + 0xc),uVar3);
      }
      bVar1 = loopCounter != 3;
      loopCounter = loopCounter + 1;
    } while (bVar1);
  }
  else if (iVar2 == 3) {
    loopCounter = 0;
    uVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),inst);
    do {
      operandRecord = IRInst__getOperandRecord(inst,0);
      if (*(char *)(loopCounter + operandRecord + 0x10) != '\x01') {
        ((int (*)())Compiler__setBitInSelectedBlockB8)(*(undefined4 *)(this + 0xc),uVar3);
      }
      bVar1 = loopCounter != 3;
      loopCounter = loopCounter + 1;
    } while (bVar1);
  }
  return;
}

/* MachineAssembler__visitIfHeaderStatic @ 0xe3140 (260 bytes) */
int MachineAssembler__visitIfHeaderStatic(this, block, param_3, compiler, unusedArg5, unusedArg6, unusedArg7)
  int *this;
  int block;
  undefined4 param_3;
  int compiler;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  undefined4 emittedBranch;
  undefined4 sourceDef;
  int branchFlag;
  int branchInst;
  undefined4 conditionRegister;
  undefined4 *vectorSlot;
  undefined4 currentProgram;
  uint stackSize;
  uint *resultStack;
  
  branchInst = Block__getBranchInst(block,block,param_3,compiler,unusedArg5,unusedArg6,unusedArg7);
  currentProgram = *(undefined4 *)(compiler + 0x6c4);
  branchFlag = *(int *)(branchInst + 300);
  sourceDef = IRInst__getOperandSource(branchInst,1);
  conditionRegister = thunk_FUN_00134de8(currentProgram,sourceDef);
  (**(code **)(*this + 0x34))(this,param_3,*(undefined4 *)(block + 0xdc));
  emittedBranch = (**(code **)(*this + 0x98))(this,branchFlag != 1,conditionRegister,0);
  resultStack = *(uint **)(this[4] + 0x24);
  stackSize = resultStack[1];
  if (stackSize < *resultStack) {
    _memset(stackSize * 4 + resultStack[2],0,4);
    vectorSlot = (undefined4 *)(stackSize * 4 + resultStack[2]);
    resultStack[1] = stackSize + 1;
  }
  else {
    vectorSlot = (undefined4 *)Vector__elementRefGrow(resultStack,stackSize);
  }
  *vectorSlot = emittedBranch;
  return;
}

/* EncoderState__destroy_e3244 @ 0xe3244 (196 bytes) */
int EncoderState__destroy_e3244(encoder)
  int encoder;
{
  int arrayAlloc24;
  int arrayAlloc2c;
  int *sinkObject;
  int arrayAlloc28;
  
  sinkObject = *(int **)(encoder + 0x20);
  if (sinkObject != (int *)0x0) {
    (**(code **)(*sinkObject + 4))(sinkObject);
  }
  arrayAlloc28 = *(int *)(encoder + 0x28);
  if (arrayAlloc28 != 0) {
    Arena__free(*(undefined4 *)(arrayAlloc28 + 0xc),*(undefined4 *)(arrayAlloc28 + 8));
    Arena__free(*(undefined4 *)(arrayAlloc28 + -4),arrayAlloc28 + -4);
  }
  arrayAlloc2c = *(int *)(encoder + 0x2c);
  if (arrayAlloc2c != 0) {
    Arena__free(*(undefined4 *)(arrayAlloc2c + 0xc),*(undefined4 *)(arrayAlloc2c + 8));
    Arena__free(*(undefined4 *)(arrayAlloc2c + -4),arrayAlloc2c + -4);
  }
  arrayAlloc24 = *(int *)(encoder + 0x24);
  if (arrayAlloc24 != 0) {
    Arena__free(*(undefined4 *)(arrayAlloc24 + 0xc),*(undefined4 *)(arrayAlloc24 + 8));
    Arena__free(*(undefined4 *)(arrayAlloc24 + -4),arrayAlloc24 + -4);
    return;
  }
  return;
}

/* EncoderState__destroy_e3308 @ 0xe3308 (196 bytes) */
int EncoderState__destroy_e3308(encoder)
  int encoder;
{
  int arrayAlloc24;
  int arrayAlloc2c;
  int *sinkObject;
  int arrayAlloc28;
  
  sinkObject = *(int **)(encoder + 0x20);
  if (sinkObject != (int *)0x0) {
    (**(code **)(*sinkObject + 4))(sinkObject);
  }
  arrayAlloc28 = *(int *)(encoder + 0x28);
  if (arrayAlloc28 != 0) {
    Arena__free(*(undefined4 *)(arrayAlloc28 + 0xc),*(undefined4 *)(arrayAlloc28 + 8));
    Arena__free(*(undefined4 *)(arrayAlloc28 + -4),arrayAlloc28 + -4);
  }
  arrayAlloc2c = *(int *)(encoder + 0x2c);
  if (arrayAlloc2c != 0) {
    Arena__free(*(undefined4 *)(arrayAlloc2c + 0xc),*(undefined4 *)(arrayAlloc2c + 8));
    Arena__free(*(undefined4 *)(arrayAlloc2c + -4),arrayAlloc2c + -4);
  }
  arrayAlloc24 = *(int *)(encoder + 0x24);
  if (arrayAlloc24 != 0) {
    Arena__free(*(undefined4 *)(arrayAlloc24 + 0xc),*(undefined4 *)(arrayAlloc24 + 8));
    Arena__free(*(undefined4 *)(arrayAlloc24 + -4),arrayAlloc24 + -4);
    return;
  }
  return;
}

/* FUN_000e33cc @ 0xe33cc (340 bytes) */
int FUN_000e33cc(compiler, param_2, param_3)
  int *compiler;
  int param_2;
  undefined4 param_3;
{
  undefined4 arenaAt378;
  int iVar1;
  undefined4 *vectorAlloc;
  int *piVar3;
  undefined4 allocation;
  
  iVar1 = *(int *)(param_2 + 8);
  compiler[0xd] = param_2;
  compiler[0xc] = -1;
  *compiler = iVar1;
  compiler[1] = 0;
  compiler[2] = 0;
  compiler[3] = 0;
  compiler[4] = 0;
  compiler[5] = 0;
  compiler[6] = 0;
  compiler[7] = 0;
  arenaAt378 = *(undefined4 *)(iVar1 + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  compiler[10] = (int)(vectorAlloc + 1);
  arenaAt378 = *(undefined4 *)(*compiler + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  compiler[0xb] = (int)(vectorAlloc + 1);
  arenaAt378 = *(undefined4 *)(*compiler + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaAt378;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  compiler[9] = (int)(vectorAlloc + 1);
  piVar3 = *(int **)(*compiler + 0x30c);
  piVar3 = (int *)(**(code **)(*piVar3 + 0x68))(piVar3,*compiler);
  compiler[8] = (int)piVar3;
                    
                    
  (**(code **)(*piVar3 + 0x14))(piVar3,compiler,param_3,*compiler);
  return;
}

/* EncoderState__init @ 0xe3544 (340 bytes) */
int EncoderState__init(encoder, program, sinkArg)
  int *encoder;
  int program;
  undefined4 sinkArg;
{
  int compilerObj;
  undefined4 arenaAt378;
  undefined4 *vectorAlloc;
  int *sinkObject;
  undefined4 allocation;
  
  compilerObj = *(int *)(program + 8);
  encoder[0xd] = program;
  encoder[0xc] = -1;
  *encoder = compilerObj;
  encoder[1] = 0;
  encoder[2] = 0;
  encoder[3] = 0;
  encoder[4] = 0;
  encoder[5] = 0;
  encoder[6] = 0;
  encoder[7] = 0;
  arenaAt378 = *(undefined4 *)(compilerObj + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  encoder[10] = (int)(vectorAlloc + 1);
  arenaAt378 = *(undefined4 *)(*encoder + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  encoder[0xb] = (int)(vectorAlloc + 1);
  arenaAt378 = *(undefined4 *)(*encoder + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaAt378;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  encoder[9] = (int)(vectorAlloc + 1);
  sinkObject = *(int **)(*encoder + 0x30c);
  sinkObject = (int *)(**(code **)(*sinkObject + 0x68))(sinkObject,*encoder);
  encoder[8] = (int)sinkObject;
                    
                    
  (**(code **)(*sinkObject + 0x14))(sinkObject,encoder,sinkArg,*encoder);
  return;
}

/* MachineCodeWriter__encodeProgram @ 0xe36bc (652 bytes) */
int MachineCodeWriter__encodeProgram(writer, outBuffer, outSize)
  uint *writer;
  undefined4 outBuffer;
  undefined4 outSize;
{
  int *firstPredecessor;
  int programTooLarge;
  int predecessorQueryResult;
  int predecessorCount;
  int *block;
  int blockIsIfHeader;
  int *nextBlock;
  int *predecessorVector;
  undefined4 *predecessorSlot;
  uint sizeBeforeCompression;
  int compressEnabled;
  undefined4 staleArgR8;
  undefined4 staleArgR9;
  undefined4 staleArgR10;
  /* NOTE (issue #64): auStack_78/auStack_74/local_54 declared as 3 separate adjacent locals sharing one
   * real stock stack region. "local_54" is NOT a separate buffer after auStack_74 - per stock disassembly
   * (r1+0x3c=auStack_74, r1+0x5c=local_54, frame size 0xb0) it's simply the name for auStack_74's own
   * word index 8 (0x74-0x54=0x20=8 words in). EncoderState__init(auStack_74,...) writes auStack_74[0] through
   * auStack_74[0xd] (up to +0x34 bytes, i.e. through frame offset r1+0x70) - CONFIRMED by reading that
   * callee's own body - so auStack_74's real required size is 0x38 bytes, not the 0x20 the auStack_74..
   * local_54 gap alone would suggest (an earlier version of this fix under-sized it at 0x28 total, which
   * still let EncoderState__init's tail writes (words 9-0xd, past local_54) overflow past this whole buffer -
   * confirmed live: that overflow was clobbering a saved register in the CALLER's (Compiler__compileStages's) frame,
   * corrupting its r30 and causing a second crash further into gldCreateContext). Those extra words are
   * never read back by any other statement in this function (no name exists for them, hence no overflow
   * was visible from local C code alone) - only sized correctly by checking the callee's real write range
   * against stock disassembly. Same defect class as the Scheduler__run/Scheduler__scheduleBlock/Scheduler__packDotProductCandidates/
   * Inst__distributeResultScale fixes already landed on this issue. */
  undefined1 auStack_e36bc_combined [0x40];
#define auStack_78 (auStack_e36bc_combined + 0x0)
#define auStack_74 (auStack_e36bc_combined + 0x4)
#define local_54 (*(int **)(auStack_e36bc_combined + 0x24))
  
  ((int (*)())EncoderState__init)(auStack_74,writer,outSize);
  (**(code **)(*local_54 + 0x18))(local_54,*writer);
  block = (int *)writer[0xe1];
  for (nextBlock = (int *)((int *)writer[0xe1])[2]; nextBlock != (int *)0x0; nextBlock = (int *)nextBlock[2]) {
    blockIsIfHeader = (**(code **)(*block + 0x24))(block);
    if ((blockIsIfHeader == 0) || (blockIsIfHeader = IfHeader__canFlatten(block,auStack_78), blockIsIfHeader == 0)) {
      predecessorCount = Block__predecessorCount(block);
      if (0 < predecessorCount) {
        predecessorVector = (int *)block[0x35];
        if (*predecessorVector == 0) {
          predecessorSlot = (undefined4 *)Vector__elementRefGrow(predecessorVector,0);
        }
        else {
          if (predecessorVector[1] == 0) {
            *(undefined4 *)predecessorVector[2] = 0;
            predecessorVector[1] = 1;
          }
          predecessorSlot = (undefined4 *)predecessorVector[2];
        }
        firstPredecessor = (int *)*predecessorSlot;
        if (((firstPredecessor != (int *)0x0) && (predecessorQueryResult = (**(code **)(*firstPredecessor + 0x24))(firstPredecessor), predecessorQueryResult != 0))
           && (block == (int *)firstPredecessor[0x4e])) {
          ((int (*)())FUN_000e2ee4)(auStack_74,firstPredecessor);
        }
      }
      ((int (*)())FUN_000e2838)(auStack_74,(uint)block,*writer);
    }
    else {
      ((int (*)())FUN_000e280c)(block,auStack_74,auStack_78);
      nextBlock = *(int **)(block[0x4f] + 8);
    }
    block = nextBlock;
  }
  (**(code **)(*local_54 + 0x10))(local_54);
  sizeBeforeCompression = (**(code **)(*local_54 + 0x20))(local_54);
  writer[1] = sizeBeforeCompression;
  ((int (*)())MachineCodeWriter__accumulateStats)(writer,auStack_74);
  programTooLarge = ((int (*)())FUN_000e284c)(auStack_74);
  compressEnabled = Compiler__isOptionEnabled(writer[2],0x4d);
  if (compressEnabled == 0) {
    if (programTooLarge != 0) goto LAB_000e3900;
  }
  else if (programTooLarge != 0) {
    if (*writer == 0) {
      *writer = 1;
      sizeBeforeCompression = writer[1];
      (**(code **)(*local_54 + 0xc))(local_54);
      ((int (*)())MachineCodeWriter__encodeProgram)(writer,outBuffer,outSize);
      ((int (*)())FUN_000e284c)(auStack_74);
      Compiler__logf(writer[2],"Compression : size reduced from %d to %d  (%%%d)\n",sizeBeforeCompression,
                   writer[1],(int)((sizeBeforeCompression - writer[1]) * 100) / (int)sizeBeforeCompression,staleArgR8,staleArgR9,staleArgR10);
      goto LAB_000e392c;
    }
LAB_000e3900:
    Compiler__fail(writer[2],5);
  }
  (**(code **)(*local_54 + 0x24))(local_54,outBuffer,outSize);
LAB_000e392c:
  return ((int (*)())EncoderState__destroy_e3308)(auStack_74);
}
#undef auStack_78
#undef auStack_74
#undef local_54

/* IRInst__createMovForDest @ 0xe3968 (396 bytes) */
int IRInst__createMovForDest(inst, inst2, compiler)
  int inst;
  int inst2;
  undefined4 compiler;
{
  int loopCounter;
  int operandRecord;
  int destRegisterNumber;
  uint flagWord;
  int *newInst;
  undefined4 mergedSelect;
  int loopCounterB;
  undefined4 destMask [4];
  undefined4 local_28;
  int markedSelect [3];
  
  newInst = (int *)IRInst__create(0x31,compiler);
  destRegisterNumber = *(int *)(inst + 0x94);
  newInst[0x26] = *(int *)(inst + 0x98);
  newInst[0x25] = destRegisterNumber;
  if ((*(uint *)(inst + 0x14) & 0x40) == 0) {
    flagWord = newInst[5] & 0xffffffbf;
    newInst[5] = flagWord;
  }
  else {
    flagWord = newInst[5] | 0x40;
    newInst[5] = flagWord;
  }
  if ((*(uint *)(inst + 0x14) & 0x20) == 0) {
    newInst[5] = flagWord & 0xffffffdf;
  }
  else {
    newInst[5] = flagWord | 0x20;
  }
  IRInst__setOperandSource(newInst,1,inst2,0,compiler);
  operandRecord = IRInst__getOperandRecord(inst2,0);
  mergedSelect = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst,0);
  destMask[0] = *(undefined4 *)(operandRecord + 0x10);
  if ((*(uint *)(inst2 + 0x14) & 0x200) != 0) {
    do {
      inst2 = IRInst__getOperandSource(inst2,*(undefined4 *)(inst2 + 0x84));
      operandRecord = IRInst__getOperandRecord(inst2,0);
      SelectWord__mergeWrittenLanes(&local_28,mergedSelect,*(undefined4 *)(operandRecord + 0x10));
      mergedSelect = local_28;
    } while ((*(uint *)(inst2 + 0x14) & 0x200) != 0);
  }
  loopCounter = 0;
  loopCounterB = 4;
  do {
    if (*(char *)((int)destMask + loopCounter) == '\x01') {
      *(undefined1 *)((int)destMask + loopCounter) = 0;
    }
    else {
      *(undefined1 *)((int)destMask + loopCounter) = 1;
    }
    loopCounter = loopCounter + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  SelectWord__markLanesWhereSecondIsOne(markedSelect,mergedSelect,destMask[0]);
  newInst[0x27] = markedSelect[0];
  (**(code **)(*newInst + 0x84))(newInst,*(undefined4 *)(inst + 0x11c));
  return newInst;
}

/* FUN_000e3af4 @ 0xe3af4 (148 bytes) */
int FUN_000e3af4(inst, compilerCtx)
  uint inst;
  undefined4 compilerCtx;
{
  uint uVar1;
  
  uVar1 = inst;
  do {
    if (uVar1 == 0) {
      return;
    }
    uVar1 = *(uint *)(inst + 0x14);
    if (((uVar1 & 1) != 0) && ((uVar1 & 0x200) != 0)) {
      IRInst__setOperandSource(inst,*(undefined4 *)(inst + 0x84),0,0,compilerCtx);
      uVar1 = *(uint *)(inst + 0x14) & 0xfffffdff;
      *(int *)(inst + 0x84) = *(int *)(inst + 0x84) + -1;
      *(uint *)(inst + 0x14) = uVar1;
    }
    inst = *(uint *)(inst + 8);
    uVar1 = uVar1 & 4;
  } while (inst != 0);
  return;
}

/* FUN_000e3b88 @ 0xe3b88 (1848 bytes) */
int FUN_000e3b88(ctx, block, beforeInst, changedOut)
  int *ctx;
  int block;
  int *beforeInst;
  undefined4 *changedOut;
{
  int firstKeyEqualResult;
  int secondPendingKey;
  undefined4 writtenLanesCopy;
  bool keyReused;
  int lanesLeft;
  int scanKey;
  int *insertAfterInst;
  int laneIndex;
  int keyEqualResultB;
  int moveBlocked;
  int sourceKey;
  int savedRegisterNumber;
  undefined4 sourceDef;
  int operandRecord;
  int operandRecord2;
  int *operandVReg;
  int *operandVReg4;
  int *operandVReg3;
  bool hasTwoPending;
  bool needsClone;
  uint flagWord;
  uint instFlags;
  int *scanCursor;
  int queryResult;
  int *operandVReg2;
  int *firstPending;
  int *secondPending;
  int savedRegisterFile;
  undefined4 instKeyB;
  undefined4 slotId;
  int *scanInst;
  int iVar14;
  undefined4 writtenLanes;
  int *pendingInsts [4];
  undefined4 mergedLanes [3];
  
  *changedOut = 0;
  if ((beforeInst == *(int **)(block + 8)) || ((*(uint *)(beforeInst[1] + 0x14) & 4) == 0)) {
    if (beforeInst != (int *)0x0) {
      iVar14 = 0;
      scanInst = beforeInst;
      do {
        instFlags = scanInst[5];
        if ((instFlags & 1) != 0) {
          pendingInsts[iVar14] = (int *)0x0;
          if ((scanInst[5] & 0x200U) != 0) {
            if ((scanInst[5] & 2U) == 0) {
              operandVReg4 = (int *)IRInst__getOperandSource(scanInst,scanInst[0x21]);
              queryResult = (**(code **)(*operandVReg4 + 0x50))(operandVReg4);
              if ((queryResult == 0) && ((scanInst[5] & 0x800000U) == 0)) {
                instKeyB = thunk_FUN_00134de8(*(undefined4 *)(*ctx + 0x6c4),scanInst);
                queryResult = ((int (*)())IRInst__lastSourceKeyEquals)(scanInst,instKeyB,*ctx);
                if (queryResult == 0) {
                  pendingInsts[iVar14] = scanInst;
                  iVar14 = iVar14 + 1;
                  scanInst[5] = scanInst[5] | 0x800000;
                }
              }
            }
            else {
              IRInst__setOperandSource(scanInst,scanInst[0x21],0,0,*ctx);
              scanInst[0x21] = scanInst[0x21] + -1;
              scanInst[5] = scanInst[5] & 0xfffffdff;
            }
          }
          if ((scanInst[0x20] == 0) || (queryResult = RegKind__flagBit0(scanInst[0x26]), queryResult == 0)) {
            instFlags = scanInst[5];
          }
          else {
            instFlags = scanInst[5];
            if ((instFlags & 2) == 0) {
              (**(code **)(*scanInst + 0x50))(scanInst);
              instFlags = scanInst[5];
            }
          }
        }
        scanInst = (int *)scanInst[2];
      } while ((scanInst != (int *)0x0) && ((instFlags & 4) != 0));
    }
    else {
      scanInst = (int *)0x0;
      iVar14 = 0;
    }
    firstPending = pendingInsts[0];
    scanInst = (int *)scanInst[1];
    if (iVar14 != 0) {
      hasTwoPending = iVar14 == 2;
      if (hasTwoPending) {
        iVar14 = thunk_FUN_00134de8(*(undefined4 *)(*ctx + 0x6c4),pendingInsts[0]);
        operandVReg3 = (int *)IRInst__getOperandSource(firstPending,firstPending[0x21]);
        secondPending = pendingInsts[1];
        secondPendingKey = thunk_FUN_00134de8(*(undefined4 *)(*ctx + 0x6c4),pendingInsts[1]);
        operandVReg2 = (int *)IRInst__getOperandSource(secondPending,secondPending[0x21]);
        if ((iVar14 == secondPendingKey) && (operandVReg3 == operandVReg2)) {
          ctx[1] = ctx[1] + 1;
          iVar14 = ((int (*)())IRInst__createMovForDest)(firstPending,operandVReg2,*ctx);
          FUN_000f47a8(iVar14,firstPending,secondPending);
          Block__insertInstAfter(scanInst[0x56],scanInst,iVar14);
          return iVar14;
        }
        firstKeyEqualResult = ((int (*)())IRInst__lastSourceKeyEquals)(firstPending,secondPendingKey,*ctx);
        if (firstKeyEqualResult == 0) {
          needsClone = true;
          ctx[1] = ctx[1] + 1;
          firstPending = (int *)((int (*)())IRInst__createMovForDest)(firstPending,operandVReg3,*ctx);
          Block__insertInstAfter(scanInst[0x56],scanInst,firstPending);
          pendingInsts[0] = secondPending;
          scanInst = firstPending;
        }
        else {
          iVar14 = ((int (*)())IRInst__lastSourceKeyEquals)(secondPending,iVar14,*ctx);
          if (iVar14 == 0) {
            needsClone = true;
            ctx[1] = ctx[1] + 1;
            firstPending = (int *)((int (*)())IRInst__createMovForDest)(secondPending,operandVReg2,*ctx);
            Block__insertInstAfter(scanInst[0x56],scanInst,firstPending);
            scanInst = firstPending;
          }
          else if (operandVReg3 == secondPending) {
            needsClone = false;
            ctx[1] = ctx[1] + 1;
            firstPending = (int *)((int (*)())IRInst__createMovForDest)(firstPending,secondPending,*ctx);
            Block__insertInstAfter(scanInst[0x56],scanInst,firstPending);
            pendingInsts[0] = secondPending;
            scanInst = firstPending;
          }
          else {
            if (firstPending != operandVReg2) {
              needsClone = true;
              hasTwoPending = true;
              goto LAB_000e4140;
            }
            needsClone = false;
            ctx[1] = ctx[1] + 1;
            firstPending = (int *)((int (*)())IRInst__createMovForDest)(secondPending,firstPending,*ctx);
            Block__insertInstAfter(scanInst[0x56],scanInst,firstPending);
            scanInst = firstPending;
          }
        }
      }
      else {
        needsClone = true;
        if (iVar14 != 1) {
LAB_000e4140:
          firstPending = pendingInsts[0];
          sourceDef = IRInst__getOperandSource(pendingInsts[0],pendingInsts[0][0x21]);
          ctx[2] = ctx[2] + 1;
          savedRegisterFile = firstPending[0x26];
          savedRegisterNumber = firstPending[0x25];
          slotId = ((int (*)())FUN_000e2a04)(ctx,(uint)(savedRegisterFile != 0));
          iVar14 = ((int (*)())FUN_000e2f04)(firstPending,slotId,savedRegisterFile,sourceDef,*ctx);
          Block__insertInstBefore(beforeInst[0x56],beforeInst,iVar14);
          insertAfterInst = scanInst;
          if (hasTwoPending) {
            sourceDef = IRInst__getOperandSource(pendingInsts[1],pendingInsts[1][0x21]);
            ctx[1] = ctx[1] + 1;
            insertAfterInst = (int *)((int (*)())IRInst__createMovForDest)(pendingInsts[1],sourceDef,*ctx);
            Block__insertInstAfter(scanInst[0x56],scanInst,insertAfterInst);
            IRInst__setOperandSource(pendingInsts[1],pendingInsts[1][0x21],0,0,*ctx);
            pendingInsts[1][0x21] = pendingInsts[1][0x21] + -1;
            pendingInsts[1][5] = pendingInsts[1][5] & 0xfffffdff;
          }
          if (needsClone) {
            ctx[1] = ctx[1] + 1;
            scanInst = (int *)IRInst__clone(firstPending,*ctx,0);
            DList__insertBefore(scanInst,firstPending);
            IRInst__setOperandSource(scanInst,scanInst[0x21],0,0,*ctx);
            scanInst[0x21] = scanInst[0x21] + -1;
            scanInst[5] = scanInst[5] & 0xfffffdff;
            if (insertAfterInst == firstPending) {
              insertAfterInst = scanInst;
            }
            instFlags = firstPending[5];
            DList__unlink(firstPending);
            IRInst__reinitAsMov(firstPending,0x31,*ctx);
            firstPending[0x25] = savedRegisterNumber;
            firstPending[0x26] = savedRegisterFile;
            if ((instFlags & 0x40) == 0) {
              flagWord = firstPending[5] & 0xffffffbf;
              firstPending[5] = flagWord;
            }
            else {
              flagWord = firstPending[5] | 0x40;
              firstPending[5] = flagWord;
            }
            if ((instFlags & 0x20) == 0) {
              firstPending[5] = flagWord & 0xffffffdf;
            }
            else {
              firstPending[5] = flagWord | 0x20;
            }
            IRInst__setOperandSource(firstPending,1,scanInst,0,*ctx);
            DList__insertAfter(firstPending,insertAfterInst);
          }
          *changedOut = 1;
          return iVar14;
        }
      }
      firstPending = pendingInsts[0];
      iVar14 = thunk_FUN_00134de8(*(undefined4 *)(*ctx + 0x6c4),pendingInsts[0]);
      operandRecord = IRInst__getOperandRecord(firstPending,0);
      writtenLanes = *(undefined4 *)(operandRecord + 0x10);
      operandVReg = (int *)IRInst__getOperandSource(firstPending,firstPending[0x21]);
      sourceKey = thunk_FUN_00134de8(*(undefined4 *)(*ctx + 0x6c4),operandVReg);
      if (beforeInst != (int *)0x0) {
        keyReused = false;
        scanCursor = beforeInst;
        do {
          instFlags = scanCursor[5];
          if ((instFlags & 1) != 0) {
            scanKey = thunk_FUN_00134de8(*(undefined4 *)(*ctx + 0x6c4),scanCursor);
            if ((sourceKey == scanKey) && (scanCursor != operandVReg)) {
              keyReused = true;
            }
            if (scanCursor == firstPending) {
              instFlags = firstPending[5];
            }
            else {
              scanKey = thunk_FUN_00134de8(*(undefined4 *)(*ctx + 0x6c4),scanCursor);
              writtenLanesCopy = writtenLanes;
              if (iVar14 == scanKey) {
                operandRecord2 = IRInst__getOperandRecord(scanCursor,0);
                SelectWord__mergeWrittenLanes(pendingInsts + 3,writtenLanesCopy,*(undefined4 *)(operandRecord2 + 0x10));
                writtenLanes = pendingInsts[3];
                instFlags = scanCursor[5];
              }
              else {
                instFlags = scanCursor[5];
              }
            }
          }
          scanCursor = (int *)scanCursor[2];
        } while ((scanCursor != (int *)0x0) && ((instFlags & 4) != 0));
        scanCursor = beforeInst;
        if (keyReused) {
          do {
            instFlags = scanCursor[5];
            if ((instFlags & 1) != 0) {
              moveBlocked = ((int (*)())FUN_000e2acc)(scanCursor,iVar14,*ctx);
              if (moveBlocked != 0) {
LAB_000e413c:
                hasTwoPending = false;
                goto LAB_000e4140;
              }
              instFlags = scanCursor[5];
              if ((instFlags & 0x200) != 0) {
                keyEqualResultB = ((int (*)())IRInst__lastSourceKeyEquals)(scanCursor,iVar14,*ctx);
                if (keyEqualResultB != 0) goto LAB_000e413c;
                instFlags = scanCursor[5];
              }
            }
            scanCursor = (int *)scanCursor[2];
            if ((scanCursor == (int *)0x0) || ((instFlags & 4) == 0)) {
              ctx[1] = ctx[1] + 1;
              iVar14 = ((int (*)())IRInst__createMovForDest)(firstPending,operandVReg,*ctx);
              Block__insertInstBefore(beforeInst[0x56],beforeInst,iVar14);
              IRInst__setOperandSource(firstPending,firstPending[0x21],0,0,*ctx);
              firstPending[0x21] = firstPending[0x21] + -1;
              firstPending[5] = firstPending[5] & 0xfffffdff;
              IRInst__setExtraOperandSource(firstPending,iVar14,0,*ctx);
              *changedOut = 1;
              return iVar14;
            }
          } while( true );
        }
      }
      ctx[1] = ctx[1] + 1;
      iVar14 = ((int (*)())IRInst__createMovForDest)(firstPending,operandVReg,*ctx);
      lanesLeft = 4;
      laneIndex = 0;
      do {
        if (*(char *)((int)&writtenLanes + laneIndex) == '\x01') {
          *(undefined1 *)((int)&writtenLanes + laneIndex) = 0;
        }
        else {
          *(undefined1 *)((int)&writtenLanes + laneIndex) = 1;
        }
        laneIndex = laneIndex + 1;
        lanesLeft = lanesLeft + -1;
      } while (lanesLeft != 0);
      operandRecord = IRInst__getOperandRecord(iVar14,0);
      SelectWord__markLanesWhereSecondIsOne(mergedLanes,*(undefined4 *)(operandRecord + 0x10),writtenLanes);
      writtenLanes = mergedLanes[0];
      *(undefined4 *)(iVar14 + 0x9c) = mergedLanes[0];
      Block__insertInstAfter(scanInst[0x56],scanInst,iVar14);
      return iVar14;
    }
  }
  return 0;
}

/* FUN_000e43ec @ 0xe43ec (20 bytes) */
int FUN_000e43ec(ilReader)
  int ilReader;
{
  return *(int *)(ilReader + 0x7c) == 3;
}

/* setWord30 @ 0xe4400 (8 bytes) */
int setWord30(object, value)
  int object;
  undefined4 value;
{
  *(undefined4 *)(object + 0x30) = value;
  return;
}

/* ILReader__currentOpcode @ 0xe4408 (8 bytes) */
int ILReader__currentOpcode(ilReader)
  int ilReader;
{
  /* issue #64 live-repro (2nd crash, past the calloc(44) fix): *(ilReader+0x8e) is a "current
   * token subtype" cache that can transiently hold an out-of-range value (confirmed: every other
   * reader in this file - ILReader__fetchToken:2265, and part_022.c:840/842/852/854/858 - checks
   * `< 0xbf` before trusting it, resetting to 0 otherwise). This function, this field's only
   * other reader, returned it raw with no such check - live-verified the caller (ILReader__decodeInstruction)
   * then used the unclamped value (0xc000 in the reproducing run) as an unbounded switch/table
   * index, crashing in FUN_000e4710's table lookup three calls later. Added the same clamp every
   * other consumer already has. */
  undefined2 opcode;
  opcode = *(undefined2 *)(ilReader + 0x8e);
  if (0xbe < (ushort)opcode) {
    opcode = 0;
  }
  return opcode;
}

/* ILReader__lookupBoolConst @ 0xe4410 (64 bytes) */
int ILReader__lookupBoolConst(ilReader, registerIndex)
  int ilReader;
  int registerIndex;
{
  int *boolRecord;
  
  boolRecord = *(int **)(*(int *)(ilReader + 0xc) + 8);
  do {
    if (*boolRecord == registerIndex) {
      return boolRecord[1];
    }
  } while ((*(int **)(ilReader + 0x10) != boolRecord) &&
          (boolRecord = (int *)boolRecord[2], boolRecord != (int *)0x0));
  return -1;
}

/* ILReader__appendIntConst @ 0xe4450 (116 bytes) */
int ILReader__appendIntConst(ilReader, registerIndex, constX, constY, constZ, constW)
  int *ilReader;
  undefined4 registerIndex;
  undefined4 constX;
  undefined4 constY;
  undefined4 constZ;
  undefined4 constW;
{
  undefined4 *record;
  
  record = (undefined4 *)Arena__alloc(*(undefined4 *)(*ilReader + 0x378),0x18);
  record[5] = 0;
  *record = registerIndex;
  record[1] = constX;
  record[2] = constY;
  record[3] = constZ;
  record[4] = constW;
  *(undefined4 **)(ilReader[6] + 0x14) = record;
  ilReader[6] = (int)record;
  return;
}

/* ILReader__readFloatConst @ 0xe44c4 (456 bytes) */
int ILReader__readFloatConst(ilReader, registerIndex, outValues, sourceToken)
  int ilReader;
  int registerIndex;
  int outValues;
  uint sourceToken;
{
  uint laneOffset;
  float dividedComponent;
  float divisor;
  float laneValue;
  float modifiedComponent;
  float zeroConst;
  float oneConst;
  uint laneSelect;
  float biasConst;
  int *constRecord;
  uint divideSelect;
  uint byteOffset;
  int lanesLeft;
  
  biasConst = FLOAT_001aa10c;
  oneConst = FLOAT_001aa0e8;
  zeroConst = FLOAT_001aa0d4;
  divideSelect = sourceToken >> 0x15 & 7;
  constRecord = *(int **)(*(int *)(ilReader + 0x1c) + 0x14);
  do {
    if (*constRecord == registerIndex) {
      lanesLeft = 4;
      byteOffset = 0;
      do {
        laneSelect = sourceToken >> (byteOffset & 0x3f) & 7;
        if (laneSelect < 4) {
          laneValue = GH_U2F((unsigned int)(constRecord[laneSelect + 1]));
        }
        else {
          laneValue = FLOAT_001aa0d4;
          if ((laneSelect != 4) && (laneValue = FLOAT_001aa0e8, laneSelect != 5)) {
            return 0;
          }
        }
        if ((sourceToken & 0x10000) != 0) {
          laneValue = oneConst - laneValue;
        }
        if ((sourceToken >> 0x11 & 1) != 0) {
          laneValue = laneValue - biasConst;
        }
        if ((sourceToken >> 0x12 & 1) != 0) {
          laneValue = laneValue + laneValue;
        }
        modifiedComponent = laneValue;
        if ((((sourceToken & 0x80000) != 0) && (modifiedComponent = FLOAT_001aa114, zeroConst <= laneValue)) &&
           (modifiedComponent = FLOAT_001aa0e8, laneValue == zeroConst)) {
          modifiedComponent = FLOAT_001aa0d4;
        }
        *(float *)(outValues + byteOffset) = modifiedComponent;
        byteOffset = byteOffset + 4;
        lanesLeft = lanesLeft + -1;
      } while (lanesLeft != 0);
      divisor = FLOAT_001aa0e8;
      if (((sourceToken & 0xe00000) != 0) && (divideSelect != 0)) {
        if (divideSelect < 4) {
          divisor = *(float *)(outValues + divideSelect * 4);
        }
        else if (divideSelect == 4) {
          return 0;
        }
      }
      laneOffset = 0;
      lanesLeft = 4;
      do {
        dividedComponent = *(float *)(laneOffset + outValues) / divisor;
        if ((sourceToken & 0x100000) != 0) {
          dividedComponent = ABS(dividedComponent);
        }
        if ((8 << (laneOffset & 0x3f) & sourceToken) != 0) {
          dividedComponent = -dividedComponent;
        }
        *(float *)(laneOffset + outValues) = dividedComponent;
        laneOffset = laneOffset + 4;
        lanesLeft = lanesLeft + -1;
      } while (lanesLeft != 0);
      return 1;
    }
  } while ((constRecord != *(int **)(ilReader + 0x20)) &&
          (constRecord = (int *)constRecord[5], constRecord != (int *)0x0));
  return 0;
}

/* ILReader__lookupConstComponent @ 0xe468c (132 bytes) */
int ILReader__lookupConstComponent(ilReader, registerNumber, componentIndex, outValue)
  int ilReader;
  int registerNumber;
  int componentIndex;
  int *outValue;
{
  int *constRecord;
  
  constRecord = *(int **)(*(int *)(ilReader + 0x14) + 0x14);
  while (*constRecord != registerNumber) {
    if (*(int **)(ilReader + 0x18) == constRecord) {
      return 0;
    }
    constRecord = (int *)constRecord[5];
    if (constRecord == (int *)0x0) {
      return 0;
    }
  }
  if (componentIndex < 4) {
    *outValue = constRecord[componentIndex + 1];
    return 1;
  }
  if (componentIndex != 4) {
    if (componentIndex != 5) {
      return 0;
    }
    *outValue = 1;
    return 1;
  }
  *outValue = 0;
  return 1;
}

/* FUN_000e4710 @ 0xe4710 (20 bytes) */
int FUN_000e4710(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  return *(undefined1 *)(param_2 + param_1 * 0x24 + param_3 + 0x1c);
}

/* ILReader__appendBoolConst @ 0xe4724 (92 bytes) */
int ILReader__appendBoolConst(ilReader, registerIndex, value)
  int *ilReader;
  undefined4 registerIndex;
  undefined4 value;
{
  undefined4 *record;
  
  record = (undefined4 *)Arena__alloc(*(undefined4 *)(*ilReader + 0x378),0xc);
  record[2] = 0;
  *record = registerIndex;
  record[1] = value;
  *(undefined4 **)(ilReader[4] + 8) = record;
  ilReader[4] = (int)record;
  return;
}

/* ILReader__appendFloatConst @ 0xe4780 (116 bytes) */
void ILReader__appendFloatConst(int *ilReader,undefined4 registerIndex,double constX,double constY,double constZ,double constW)
{
  undefined4 *record;
  
  record = (undefined4 *)Arena__alloc(*(undefined4 *)(*ilReader + 0x378),0x18);
  record[5] = 0;
  *record = registerIndex;
  record[1] = (float)constX;
  record[2] = (float)constY;
  record[3] = (float)constZ;
  record[4] = (float)constW;
  *(undefined4 **)(ilReader[8] + 0x14) = record;
  ilReader[8] = (int)record;
  return;
}

/* FUN_000e47f4 @ 0xe47f4 (60 bytes) */
int FUN_000e47f4(ilReader)
  int ilReader;
{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(ilReader + 0x40) + 4);
  if (uVar2 == 0) {
    return 0xbf;
  }
  puVar1 = (undefined4 *)0x0;
  if (uVar2 - 1 < uVar2) {
    puVar1 = (undefined4 *)((uVar2 - 1) * 4 + *(int *)(*(int *)(ilReader + 0x40) + 8));
  }
  return *(undefined4 *)*puVar1;
}

/* ILReader__dtor_e4830 @ 0xe4830 (260 bytes) */
int ILReader__dtor_e4830(ilReader)
  int *ilReader;
{
  int vectorHeader;
  
  vectorHeader = ilReader[0xf];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = ilReader[0x10];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = ilReader[0x22];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = ilReader[0x11];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  Arena__free(*(undefined4 *)(*ilReader + 0x378),ilReader[0x19]);
  Arena__free(*(undefined4 *)(*ilReader + 0x378),ilReader[0x1a]);
  Arena__free(*(undefined4 *)(*ilReader + 0x378),ilReader[0x1b]);
  Arena__free(*(undefined4 *)(*ilReader + 0x378),ilReader[0x1c]);
  ilReader[0x1a] = 0;
  ilReader[0x19] = 0;
  return;
}

/* ILReader__dtor_e4934 @ 0xe4934 (260 bytes) */
int ILReader__dtor_e4934(ilReader)
  int *ilReader;
{
  int vectorHeader;
  
  vectorHeader = ilReader[0xf];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = ilReader[0x10];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = ilReader[0x22];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  vectorHeader = ilReader[0x11];
  if (vectorHeader != 0) {
    Arena__free(*(undefined4 *)(vectorHeader + 0xc),*(undefined4 *)(vectorHeader + 8));
    Arena__free(*(undefined4 *)(vectorHeader + -4),vectorHeader + -4);
  }
  Arena__free(*(undefined4 *)(*ilReader + 0x378),ilReader[0x19]);
  Arena__free(*(undefined4 *)(*ilReader + 0x378),ilReader[0x1a]);
  Arena__free(*(undefined4 *)(*ilReader + 0x378),ilReader[0x1b]);
  Arena__free(*(undefined4 *)(*ilReader + 0x378),ilReader[0x1c]);
  ilReader[0x1a] = 0;
  ilReader[0x19] = 0;
  return;
}

/* ILReader__fetchToken @ 0xe4a38 (520 bytes) */
int ILReader__fetchToken(ilReader, tokenIndex)
  int ilReader;
  int tokenIndex;
{
  undefined4 poppedWord;
  int replayStack;
  bool isFirstToken;
  bool replayFinished;
  uint replayStackCount;
  int readState;
  int streamBase;
  int tokenSlot;
  ushort opcode;
  undefined4 *replayStackTop;
  undefined4 streamToken;
  int *replayStackLast;
  int poppedOffset;
  
  isFirstToken = tokenIndex == 0;
  tokenSlot = tokenIndex * 4 + ilReader;
  do {
    readState = *(int *)(ilReader + 0x7c);
    if (readState == 1) {
      replayStack = *(int *)(ilReader + 0x88);
      replayStackTop = (undefined4 *)0x0;
      replayStackCount = *(uint *)(replayStack + 4);
      if (replayStackCount - 1 < replayStackCount) {
        replayStackTop = (undefined4 *)((replayStackCount - 1) * 4 + *(int *)(replayStack + 8));
      }
      poppedWord = *replayStackTop;
      Vector__removeAt(replayStack,replayStackCount - 1);
      readState = *(int *)(ilReader + 0x7c);
      *(undefined4 *)(tokenSlot + 0x8c) = poppedWord;
    }
    else {
      if (readState == 2) {
        *(undefined4 *)(tokenSlot + 0x8c) = 0x2b;
        return 0;
      }
      if (readState == 0) {
        streamToken = **(undefined4 **)(ilReader + 0x74);
        *(undefined4 **)(ilReader + 0x74) = *(undefined4 **)(ilReader + 0x74) + 1;
        *(undefined4 *)(tokenSlot + 0x8c) = streamToken;
      }
    }
    opcode = *(ushort *)(ilReader + 0x8e);
    if (0xbe < opcode) {
      opcode = 0;
    }
    if (((readState == 1) && (isFirstToken)) && (*(int *)(ilReader + 0x8c) == -1)) {
      replayStack = *(int *)(ilReader + 0x88);
      replayStackTop = (undefined4 *)0x0;
      replayStackCount = *(uint *)(replayStack + 4);
      if (replayStackCount - 1 < replayStackCount) {
        replayStackTop = (undefined4 *)((replayStackCount - 1) * 4 + *(int *)(replayStack + 8));
      }
      poppedWord = *replayStackTop;
      Vector__removeAt(replayStack,replayStackCount - 1);
      replayStack = *(int *)(ilReader + 0x88);
      *(undefined4 *)(ilReader + 0x80) = poppedWord;
      replayStackTop = (undefined4 *)0x0;
      replayStackCount = *(uint *)(replayStack + 4);
      if (replayStackCount - 1 < replayStackCount) {
        replayStackTop = (undefined4 *)((replayStackCount - 1) * 4 + *(int *)(replayStack + 8));
      }
      poppedWord = *replayStackTop;
      Vector__removeAt(replayStack,replayStackCount - 1);
      replayStack = *(int *)(ilReader + 0x88);
      *(undefined4 *)(ilReader + 0x7c) = poppedWord;
      replayStackLast = (int *)0x0;
      replayStackCount = *(uint *)(replayStack + 4);
      streamBase = *(int *)(ilReader + 0x2c);
      if (replayStackCount - 1 < replayStackCount) {
        replayStackLast = (int *)((replayStackCount - 1) * 4 + *(int *)(replayStack + 8));
      }
      poppedOffset = *replayStackLast;
      Vector__removeAt(replayStack,replayStackCount - 1);
      replayFinished = true;
      *(int *)(ilReader + 0x74) = streamBase + poppedOffset * 4;
    }
    else {
      replayFinished = false;
    }
    if (*(int *)(ilReader + 0x80) == 0) {
      if (isFirstToken && opcode == 0x2b) {
        *(undefined4 *)(ilReader + 0x7c) = 2;
        return 0;
      }
      if (isFirstToken && opcode == 0x28) {
        *(undefined4 *)(ilReader + 0x7c) = 2;
        return 0;
      }
    }
    if (!replayFinished) {
      return 1;
    }
  } while( true );
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl Block__accept");
asm(".set Block__accept, _Block__accept");
asm(".globl IfFooterStatic__accept");
asm(".set IfFooterStatic__accept, _IfFooterStatic__accept");
asm(".globl IRStartCallRoutine__acceptCallPseudo");
asm(".set IRStartCallRoutine__acceptCallPseudo, _IRStartCallRoutine__acceptCallPseudo");
asm(".globl IREndCallRoutine__acceptCallPseudo");
asm(".set IREndCallRoutine__acceptCallPseudo, _IREndCallRoutine__acceptCallPseudo");
asm(".globl IRStartMakeCall__acceptCallPseudo");
asm(".set IRStartMakeCall__acceptCallPseudo, _IRStartMakeCall__acceptCallPseudo");
asm(".globl IREndMakeCall__acceptCallPseudo");
asm(".set IREndMakeCall__acceptCallPseudo, _IREndMakeCall__acceptCallPseudo");
asm(".globl FUN_000e2fd8");
asm(".set FUN_000e2fd8, _MachineAssembler__vslot34_declareDestinationLanesByClass");
asm(".globl MachineAssembler__visitIfHeaderStatic");
asm(".set MachineAssembler__visitIfHeaderStatic, _MachineAssembler__visitIfHeaderStatic");
