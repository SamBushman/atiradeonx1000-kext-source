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
int FUN_000e161c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x47c) != 0) {
    if (param_2 == 5) {
LAB_000e1644:
      *(undefined4 *)(param_1 + 0x318) = 1;
      *(int *)(param_1 + 0x478) = *(int *)(param_1 + 0x480) + -1;
      *(undefined4 *)(param_1 + 0x314) = 0;
      *(undefined4 *)(param_1 + 0x47c) = 0;
      return 1;
    }
    if (param_2 == 4) {
      iVar1 = 0;
      if (*(int *)(param_1 + 0x6bc) != 0) goto LAB_000e1644;
      goto LAB_000e16a4;
    }
  }
  iVar1 = *(int *)(param_1 + 0x6bc);
LAB_000e16a4:
  if ((iVar1 == 0) && (param_2 == 4)) {
    uVar2 = 1;
    *(undefined4 *)(param_1 + 0x318) = 1;
    *(undefined4 *)(param_1 + 0x6b8) = 1;
    *(undefined4 *)(param_1 + 0x314) = 0;
    *(undefined4 *)(param_1 + 0x6bc) = 1;
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
int Compiler__setBitInSelectedBlockB8(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = ((int (*)())Compiler__selectBlockByProgramFlags)(param_1);
  iVar1 = ((int)param_2 >> 5) + (uint)((int)param_2 < 0 && (param_2 & 0x1f) != 0);
  iVar2 = iVar1 * 4 + iVar2;
  *(uint *)(iVar2 + 0xb8) = 1 << (param_2 + iVar1 * -0x20 & 0x3f) | *(uint *)(iVar2 + 0xb8);
  return;
}

/* Compiler__setBitInSelectedBlockD8 @ 0xe175c (88 bytes) */
int Compiler__setBitInSelectedBlockD8(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = ((int (*)())Compiler__selectBlockByProgramFlags)(param_1);
  iVar1 = ((int)param_2 >> 5) + (uint)((int)param_2 < 0 && (param_2 & 0x1f) != 0);
  iVar2 = iVar1 * 4 + iVar2;
  *(uint *)(iVar2 + 0xd8) = 1 << (param_2 + iVar1 * -0x20 & 0x3f) | *(uint *)(iVar2 + 0xd8);
  return;
}

/* Compiler__setBitInSelectedBlock98 @ 0xe17b4 (88 bytes) */
int Compiler__setBitInSelectedBlock98(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = ((int (*)())Compiler__selectBlockByProgramFlags)(param_1);
  iVar1 = ((int)param_2 >> 5) + (uint)((int)param_2 < 0 && (param_2 & 0x1f) != 0);
  iVar2 = iVar1 * 4 + iVar2;
  *(uint *)(iVar2 + 0x98) = 1 << (param_2 + iVar1 * -0x20 & 0x3f) | *(uint *)(iVar2 + 0x98);
  return;
}

/* FUN_000e180c @ 0xe180c (124 bytes) */
int FUN_000e180c(compiler, param_2)
  int compiler;
  int param_2;
{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_2 * 4 + compiler;
  if (*(int *)(iVar2 + 0x370) == 0) {
    piVar1 = (int *)Compiler__allocateOrFail(compiler,0x2c);
    if (piVar1 != (int *)0x0) {
      piVar1[10] = 0;
      *piVar1 = compiler;
      piVar1[1] = 0;
      piVar1[2] = 0;
      piVar1[3] = 0;
      piVar1[4] = 0;
      piVar1[5] = 0;
      piVar1[6] = 0;
      piVar1[7] = 0;
      piVar1[8] = 0;
      piVar1[9] = 0;
    }
    *(int **)(iVar2 + 0x370) = piVar1;
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
    ((int (*)())FUN_000e180c)(compiler,loopCounter);
    bVar1 = loopCounter != 2;
    loopCounter = loopCounter + 1;
  } while (bVar1);
  allocation = Arena__alloc(*(undefined4 *)(compiler + 0x370),0x2000);
  *(undefined4 *)(compiler + 0x3a0) = allocation;
  *(undefined4 *)(compiler + 0x3a8) = 0;
  *(undefined4 *)(compiler + 0x3a4) = 0;
  return FUN_000e0850(compiler);
}

/* FUN_000e1920 @ 0xe1920 (232 bytes) */
int FUN_000e1920(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  undefined4 *param_1;
  undefined4 param_2;
  code *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
{
  int iVar1;
  undefined4 *puStack00000018;
  
  param_1[0x162] = 1;
  param_1[0xca] = param_6;
  param_1[0x11e] = 0x400;
  param_1[0xd7] = param_8;
  param_1[0xd8] = param_9;
  param_1[0xd9] = param_10;
  param_1[0xd6] = param_7;
  param_1[0xda] = param_11;
  param_1[0xd3] = param_4;
  *param_1 = param_5;
  param_1[199] = 1;
  param_1[0xd5] = param_2;
  param_1[0xdb] = param_12;
  param_1[1] = (int)(param_1 + 2) + (-(int)(param_1 + 2) & 7U);
  param_1[0xc3] = 0;
  param_1[0xc4] = 0;
  param_1[0x11f] = 0;
  param_1[0x120] = 0;
  param_1[0x1b1] = 0;
  param_1[0xd4] = param_3;
  param_1[200] = 0;
  param_1[0xdc] = 0;
  param_1[0xdd] = 0;
  param_1[0xde] = 0;
  puStack00000018 = param_1;
  iVar1 = (*param_3)(param_2,0x1744,param_3,param_4,param_5,param_6,param_7,param_1);
  *(undefined1 *)(puStack00000018 + 0xfe) = 0;
  if (iVar1 == 0) {
    puStack00000018[0xc5] = 2;
  }
  else {
    KhanPs__ctor_129130(iVar1,puStack00000018,0);
    puStack00000018[0xc3] = iVar1;
    iVar1 = _setjmp(puStack00000018[1]);
    if (iVar1 == 0) {
      ((int (*)())Compiler__resetState)(puStack00000018);
      FUN_000e13b4(puStack00000018);
    }
  }
  return;
}

/* FUN_000e1a48 @ 0xe1a48 (232 bytes) */
int FUN_000e1a48(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  undefined4 *param_1;
  undefined4 param_2;
  code *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
{
  int iVar1;
  undefined4 *puStack00000018;
  
  param_1[0x162] = 1;
  param_1[0xca] = param_6;
  param_1[0x11e] = 0x400;
  param_1[0xd7] = param_8;
  param_1[0xd8] = param_9;
  param_1[0xd9] = param_10;
  param_1[0xd6] = param_7;
  param_1[0xda] = param_11;
  param_1[0xd3] = param_4;
  *param_1 = param_5;
  param_1[199] = 1;
  param_1[0xd5] = param_2;
  param_1[0xdb] = param_12;
  param_1[1] = (int)(param_1 + 2) + (-(int)(param_1 + 2) & 7U);
  param_1[0xc3] = 0;
  param_1[0xc4] = 0;
  param_1[0x11f] = 0;
  param_1[0x120] = 0;
  param_1[0x1b1] = 0;
  param_1[0xd4] = param_3;
  param_1[200] = 0;
  param_1[0xdc] = 0;
  param_1[0xdd] = 0;
  param_1[0xde] = 0;
  puStack00000018 = param_1;
  iVar1 = (*param_3)(param_2,0x1744,param_3,param_4,param_5,param_6,param_7,param_1);
  *(undefined1 *)(puStack00000018 + 0xfe) = 0;
  if (iVar1 == 0) {
    puStack00000018[0xc5] = 2;
  }
  else {
    KhanPs__ctor_129130(iVar1,puStack00000018,0);
    puStack00000018[0xc3] = iVar1;
    iVar1 = _setjmp(puStack00000018[1]);
    if (iVar1 == 0) {
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
int Program__forwardMulOperandToUsers(program, passThroughR4, param_3, argR6, param_5, param_6, param_7)
  int program;
  undefined4 passThroughR4;
  undefined4 param_3;
  undefined4 argR6;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
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

/* FUN_000e2094 @ 0xe2094 (292 bytes) */
int FUN_000e2094(compiler, param_2)
  int compiler;
  int param_2;
{
  int pairInstructionsEnabled;
  int mapChannelsEnabled;
  int reduceDepEnabled;
  int markIgnoreUncoveredEnabled;
  int packInstsEnabled;
  int removeEmptyGraphEnabled;
  int peepholeEnabled;
  int deadCodeEnabled;
  undefined4 arenaAt378;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int argR6;
  undefined4 in_r7;
  undefined4 in_r8;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 arenaAt374;
  undefined4 *puVar7;
  undefined8 deleteComputationsThatCouldBeVsEnabled;
  
  ((int (*)())Compiler__propagateFlag5a1Bit1)(compiler);
  *(char **)(compiler + 0x5a8) = "INITIAL_INPUT";
  *(char **)(compiler + 0x5bc) = "BUILD_SSA";
  *(char **)(compiler + 0x5d0) = "REDUCE_DEP";
  *(char **)(compiler + 0x5e4) = "PEEPHOLE";
  *(char **)(compiler + 0x5f8) = "SCHED";
  *(char **)(compiler + 0x60c) = "REPLACE_PHI";
  pcVar4 = "ASSEMBLY";
  *(char **)(compiler + 0x620) = "GLOBAL_ALLOC";
  *(char **)(compiler + 0x634) = "ASSEMBLY";
  FUN_00115fa0(compiler);
  iVar1 = *(int *)(param_2 + 8) + -1;
  *(int *)(compiler + 0x52c) = iVar1;
  while (-1 < iVar1) {
    FUN_000e13b4(compiler);
    iVar1 = *(int *)(compiler + 0x52c);
    if (iVar1 < 2) {
      uVar5 = *(undefined4 *)(iVar1 * 4 + param_2 + 0xc);
    }
    else {
      pcVar4 = *(char **)(param_2 + 0x14);
      uVar5 = *(undefined4 *)(pcVar4 + iVar1 * 4);
    }
    arenaAt374 = *(undefined4 *)(compiler + COMP_arenaA);
    puVar3 = (undefined4 *)Arena__alloc(arenaAt374,0x484);
    *puVar3 = arenaAt374;
    Program__ctor_ee29c(puVar3 + 1,compiler);
    arenaAt378 = *(undefined4 *)(compiler + COMP_arenaB);
    *(undefined4 **)(compiler + COMP_currentProgram) = puVar3 + 1;
    puVar3 = (undefined4 *)Arena__alloc(arenaAt378,0x290);
    puVar7 = puVar3 + 1;
    *puVar3 = arenaAt378;
    iVar1 = compiler;
    ILReader__ctor_e5570(puVar7,uVar5,compiler);
    if ((*(uint *)(param_2 + 4) & 0x20) != 0) {
      iVar2 = *(int *)(compiler + 0x52c) + 1;
      if (iVar2 < 2) {
        uVar5 = *(undefined4 *)(iVar2 * 4 + param_2 + 0xc);
      }
      else {
        pcVar4 = *(char **)(param_2 + 0x14);
        uVar5 = *(undefined4 *)(pcVar4 + iVar2 * 4);
      }
      ((int (*)())setWord30)(puVar7,uVar5);
    }
    (**(code **)(**(int **)(compiler + COMP_target) + 0x60))(*(int **)(compiler + COMP_target));
    FUN_000ef498(*(undefined4 *)(compiler + COMP_currentProgram),puVar7);
    if (puVar7 != (undefined4 *)0x0) {
      ((int (*)())ILReader__dtor_e4934)(puVar7);
      Arena__free(*puVar3,puVar3);
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
      ((int (*)())Program__forwardMulOperandToUsers)(*(undefined4 *)(compiler + COMP_currentProgram),(int)deleteComputationsThatCouldBeVsEnabled,iVar1,argR6,in_r7,in_r8,pcVar4);
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
    FUN_000f29f4(*(undefined4 *)(compiler + COMP_currentProgram));
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaB));
    Scheduler__run(*(undefined4 *)(compiler + COMP_currentProgram));
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaB));
    FUN_00120cd4(*(undefined4 *)(compiler + COMP_currentProgram));
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaB));
    FUN_00134658(*(undefined4 *)(compiler + COMP_currentProgram));
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaB));
    FUN_000f60c4(*(undefined4 *)(compiler + COMP_currentProgram),compiler);
    *(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) =
         *(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) | 0x10000;
    pass_optimize_control_flow(*(undefined4 *)(compiler + COMP_currentProgram));
    ((int (*)())FUN_000e36bc)(*(undefined4 *)(compiler + COMP_currentProgram),*(int *)(compiler + 0x52c) * 4 + compiler + 0x484,
                 *(int *)(compiler + 0x52c));
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaB));
    FUN_0013061c(*(undefined4 *)(compiler + COMP_currentProgram),0);
    (**(code **)(**(int **)(compiler + COMP_target) + 0x38))
              (*(int **)(compiler + COMP_target),*(undefined4 *)(compiler + 0x52c),compiler);
    pcVar4 = (char *)**(undefined4 **)(compiler + COMP_target);
    iVar1 = *(int *)(compiler + 0x52c) * 4 + compiler;
    argR6 = compiler;
    (**(code **)(pcVar4 + 0x8c))
              (*(undefined4 **)(compiler + COMP_target),*(undefined4 *)(iVar1 + 0x524),
               *(undefined4 *)(iVar1 + 0x4d4));
    iVar1 = *(int *)(compiler + COMP_currentProgram);
    if (iVar1 != 0) {
      FUN_000ecfac(iVar1);
      Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
    }
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaA));
    List__freeAllNodes(*(undefined4 *)(compiler + COMP_arenaB));
    iVar1 = *(int *)(compiler + 0x52c) + -1;
    *(int *)(compiler + 0x52c) = iVar1;
  }
  return;
}

/* FUN_000e2524 @ 0xe2524 (324 bytes) */
int FUN_000e2524(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  int iVar2;
  int iStack00000018;
  int iStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  
  *(undefined4 *)(param_1 + 0x398) = param_5;
  iStack00000018 = param_1;
  iStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  FUN_000e0ca8(param_1);
  do {
    iVar1 = _setjmp(*(undefined4 *)(iStack00000018 + 4));
    if (iVar1 == 0) {
      ((int (*)())Compiler__resetState)(iStack00000018);
      FUN_000e0cd0(iStack00000018,uStack00000024);
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
      ((int (*)())FUN_000e2094)(iStack00000018,iVar1);
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

/* FUN_000e2668 @ 0xe2668 (280 bytes) */
int FUN_000e2668(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  int iVar2;
  int iStack00000018;
  int iStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  
  *(undefined4 *)(param_1 + 0x398) = param_7;
  iStack00000018 = param_1;
  iStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  FUN_000e0ca8(param_1);
  do {
    iVar1 = _setjmp(*(undefined4 *)(iStack00000018 + 4));
    if (iVar1 == 0) {
      ((int (*)())Compiler__resetState)(iStack00000018);
      FUN_000e0cd0(iStack00000018,uStack00000028);
      iVar1 = FUN_00193b3c(uStack00000020,uStack00000024,iStack00000018);
      *(int *)(iStack00000018 + 0x524) = iStack0000001c;
      *(undefined4 *)(iStack0000001c + 0xf8) = 0;
      *(undefined4 *)(iStack0000001c + 0xfc) =
           *(undefined4 *)(*(int *)(iStack00000018 + 0x398) + 0x28);
      ((int (*)())FUN_000e2094)(iStack00000018,iVar1);
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

/* FUN_000e2780 @ 0xe2780 (140 bytes) */
int FUN_000e2780(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  param_1[0xa4] = param_1[0xa4] + *(int *)(param_2 + 4);
  param_1[0xa5] = param_1[0xa5] + *(int *)(param_2 + 8);
  param_1[0xa6] = param_1[0xa6] + *(int *)(param_2 + 0xc);
  param_1[0xa7] = param_1[0xa7] + *(int *)(param_2 + 0x10);
  param_1[0xa8] = param_1[0xa8] + *(int *)(param_2 + 0x14);
  param_1[0xa9] = param_1[0xa9] + *(int *)(param_2 + 0x18);
  param_1[0xaa] = param_1[0xaa] + *(int *)(param_2 + 0x1c);
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x1c))(*(int **)(param_2 + 0x20),*param_1);
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
int FUN_000e2bf4(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  for (piVar2 = (int *)(*(int **)(param_1 + 8))[2]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2])
  {
    if (((piVar1[5] & 1U) != 0) && (*(int *)(piVar1[0x22] + 8) != 0x57)) {
      (**(code **)(*piVar1 + 0x84))(piVar1,param_2);
      piVar2 = (int *)piVar1[2];
    }
    piVar1 = piVar2;
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
        FUN_000d9d74(emitContext,destRegisterId,(uint)(laneRecord == 1),loopCounter,targetBlock,0);
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
            FUN_000d9c90(emitContext2,destRegisterId3,laneValueInt,loopCounter,targetBlock,0);
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
            FUN_000d9e98(emitContext3,destRegisterId2,loopCounter,laneKind,laneValue0,laneValue1,laneValue2,laneValue3,laneValue4,targetBlock);
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
        FUN_000d9e58(emitContext,destRegisterId,programArg,(int)laneHigh,loopCounter,targetBlock);
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
int MachineAssembler__visitIfHeaderStatic(this, block, param_3, param_4, param_5, param_6, param_7)
  int *this;
  int block;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 sourceDef;
  int iVar1;
  int branchInst;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  
  branchInst = Block__getBranchInst(block,block,param_3,param_4,param_5,param_6,param_7);
  uVar5 = *(undefined4 *)(param_4 + 0x6c4);
  iVar1 = *(int *)(branchInst + 300);
  sourceDef = IRInst__getOperandSource(branchInst,1);
  uVar3 = thunk_FUN_00134de8(uVar5,sourceDef);
  (**(code **)(*this + 0x34))(this,param_3,*(undefined4 *)(block + 0xdc));
  uVar3 = (**(code **)(*this + 0x98))(this,iVar1 != 1,uVar3,0);
  puVar7 = *(uint **)(this[4] + 0x24);
  uVar6 = puVar7[1];
  if (uVar6 < *puVar7) {
    _memset(uVar6 * 4 + puVar7[2],0,4);
    puVar4 = (undefined4 *)(uVar6 * 4 + puVar7[2]);
    puVar7[1] = uVar6 + 1;
  }
  else {
    puVar4 = (undefined4 *)Vector__elementRefGrow(puVar7,uVar6);
  }
  *puVar4 = uVar3;
  return;
}

/* FUN_000e3244 @ 0xe3244 (196 bytes) */
int FUN_000e3244(param_1)
  int param_1;
{
  int *a0;
  int iVar1;
  
  a0 = *(int **)(param_1 + 0x20);
  if (a0 != (int *)0x0) {
    (**(code **)(*a0 + 4))(a0);
  }
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
    return;
  }
  return;
}

/* FUN_000e3308 @ 0xe3308 (196 bytes) */
int FUN_000e3308(param_1)
  int param_1;
{
  int *a0;
  int iVar1;
  
  a0 = *(int **)(param_1 + 0x20);
  if (a0 != (int *)0x0) {
    (**(code **)(*a0 + 4))(a0);
  }
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 != 0) {
    Arena__free(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
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

/* FUN_000e3544 @ 0xe3544 (340 bytes) */
int FUN_000e3544(compiler, param_2, param_3)
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

/* FUN_000e36bc @ 0xe36bc (652 bytes) */
int FUN_000e36bc(param_1, param_2, param_3)
  uint *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint uVar6;
  int compressEnabled;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  /* NOTE (issue #64): auStack_78/auStack_74/local_54 declared as 3 separate adjacent locals sharing one
   * real stock stack region. "local_54" is NOT a separate buffer after auStack_74 - per stock disassembly
   * (r1+0x3c=auStack_74, r1+0x5c=local_54, frame size 0xb0) it's simply the name for auStack_74's own
   * word index 8 (0x74-0x54=0x20=8 words in). FUN_000e3544(auStack_74,...) writes auStack_74[0] through
   * auStack_74[0xd] (up to +0x34 bytes, i.e. through frame offset r1+0x70) - CONFIRMED by reading that
   * callee's own body - so auStack_74's real required size is 0x38 bytes, not the 0x20 the auStack_74..
   * local_54 gap alone would suggest (an earlier version of this fix under-sized it at 0x28 total, which
   * still let FUN_000e3544's tail writes (words 9-0xd, past local_54) overflow past this whole buffer -
   * confirmed live: that overflow was clobbering a saved register in the CALLER's (FUN_000e2094's) frame,
   * corrupting its r30 and causing a second crash further into gldCreateContext). Those extra words are
   * never read back by any other statement in this function (no name exists for them, hence no overflow
   * was visible from local C code alone) - only sized correctly by checking the callee's real write range
   * against stock disassembly. Same defect class as the Scheduler__run/Scheduler__scheduleBlock/Scheduler__packDotProductCandidates/
   * Inst__distributeResultScale fixes already landed on this issue. */
  undefined1 auStack_e36bc_combined [0x40];
#define auStack_78 (auStack_e36bc_combined + 0x0)
#define auStack_74 (auStack_e36bc_combined + 0x4)
#define local_54 (*(int **)(auStack_e36bc_combined + 0x24))
  
  ((int (*)())FUN_000e3544)(auStack_74,param_1,param_3);
  (**(code **)(*local_54 + 0x18))(local_54,*param_1);
  piVar1 = (int *)param_1[0xe1];
  for (piVar3 = (int *)((int *)param_1[0xe1])[2]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
    iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1);
    if ((iVar2 == 0) || (iVar2 = IfHeader__canFlatten(piVar1,auStack_78), iVar2 == 0)) {
      iVar2 = Block__predecessorCount(piVar1);
      if (0 < iVar2) {
        piVar4 = (int *)piVar1[0x35];
        if (*piVar4 == 0) {
          puVar5 = (undefined4 *)Vector__elementRefGrow(piVar4,0);
        }
        else {
          if (piVar4[1] == 0) {
            *(undefined4 *)piVar4[2] = 0;
            piVar4[1] = 1;
          }
          puVar5 = (undefined4 *)piVar4[2];
        }
        piVar4 = (int *)*puVar5;
        if (((piVar4 != (int *)0x0) && (iVar2 = (**(code **)(*piVar4 + 0x24))(piVar4), iVar2 != 0))
           && (piVar1 == (int *)piVar4[0x4e])) {
          ((int (*)())FUN_000e2ee4)(auStack_74,piVar4);
        }
      }
      ((int (*)())FUN_000e2838)(auStack_74,(uint)piVar1,*param_1);
    }
    else {
      ((int (*)())FUN_000e280c)(piVar1,auStack_74,auStack_78);
      piVar3 = *(int **)(piVar1[0x4f] + 8);
    }
    piVar1 = piVar3;
  }
  (**(code **)(*local_54 + 0x10))(local_54);
  uVar6 = (**(code **)(*local_54 + 0x20))(local_54);
  param_1[1] = uVar6;
  ((int (*)())FUN_000e2780)(param_1,auStack_74);
  iVar2 = ((int (*)())FUN_000e284c)(auStack_74);
  compressEnabled = Compiler__isOptionEnabled(param_1[2],0x4d);
  if (compressEnabled == 0) {
    if (iVar2 != 0) goto LAB_000e3900;
  }
  else if (iVar2 != 0) {
    if (*param_1 == 0) {
      *param_1 = 1;
      uVar6 = param_1[1];
      (**(code **)(*local_54 + 0xc))(local_54);
      ((int (*)())FUN_000e36bc)(param_1,param_2,param_3);
      ((int (*)())FUN_000e284c)(auStack_74);
      Compiler__logf(param_1[2],"Compression : size reduced from %d to %d  (%%%d)\n",uVar6,
                   param_1[1],(int)((uVar6 - param_1[1]) * 100) / (int)uVar6,in_r8,in_r9,in_r10);
      goto LAB_000e392c;
    }
LAB_000e3900:
    Compiler__fail(param_1[2],5);
  }
  (**(code **)(*local_54 + 0x24))(local_54,param_2,param_3);
LAB_000e392c:
  return ((int (*)())FUN_000e3308)(auStack_74);
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
  int iVar1;
  uint uVar2;
  int *newInst;
  undefined4 uVar4;
  int loopCounterB;
  undefined4 local_38 [4];
  undefined4 local_28;
  int local_24 [3];
  
  newInst = (int *)IRInst__create(0x31,compiler);
  iVar1 = *(int *)(inst + 0x94);
  newInst[0x26] = *(int *)(inst + 0x98);
  newInst[0x25] = iVar1;
  if ((*(uint *)(inst + 0x14) & 0x40) == 0) {
    uVar2 = newInst[5] & 0xffffffbf;
    newInst[5] = uVar2;
  }
  else {
    uVar2 = newInst[5] | 0x40;
    newInst[5] = uVar2;
  }
  if ((*(uint *)(inst + 0x14) & 0x20) == 0) {
    newInst[5] = uVar2 & 0xffffffdf;
  }
  else {
    newInst[5] = uVar2 | 0x20;
  }
  IRInst__setOperandSource(newInst,1,inst2,0,compiler);
  operandRecord = IRInst__getOperandRecord(inst2,0);
  uVar4 = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst,0);
  local_38[0] = *(undefined4 *)(operandRecord + 0x10);
  if ((*(uint *)(inst2 + 0x14) & 0x200) != 0) {
    do {
      inst2 = IRInst__getOperandSource(inst2,*(undefined4 *)(inst2 + 0x84));
      operandRecord = IRInst__getOperandRecord(inst2,0);
      SelectWord__mergeWrittenLanes(&local_28,uVar4,*(undefined4 *)(operandRecord + 0x10));
      uVar4 = local_28;
    } while ((*(uint *)(inst2 + 0x14) & 0x200) != 0);
  }
  loopCounter = 0;
  loopCounterB = 4;
  do {
    if (*(char *)((int)local_38 + loopCounter) == '\x01') {
      *(undefined1 *)((int)local_38 + loopCounter) = 0;
    }
    else {
      *(undefined1 *)((int)local_38 + loopCounter) = 1;
    }
    loopCounter = loopCounter + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  SelectWord__markLanesWhereSecondIsOne(local_24,uVar4,local_38[0]);
  newInst[0x27] = local_24[0];
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
int FUN_000e3b88(param_1, block, beforeInst, param_4)
  int *param_1;
  int block;
  int *beforeInst;
  undefined4 *param_4;
{
  undefined4 sourceDef;
  int operandRecord;
  int operandRecord2;
  int *operandVReg;
  int *operandVReg4;
  int *operandVReg3;
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int *operandVReg2;
  int *piVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int *piVar13;
  int iVar14;
  undefined4 local_58;
  int *local_54 [4];
  undefined4 local_44 [3];
  
  *param_4 = 0;
  if ((beforeInst == *(int **)(block + 8)) || ((*(uint *)(beforeInst[1] + 0x14) & 4) == 0)) {
    if (beforeInst != (int *)0x0) {
      iVar14 = 0;
      piVar13 = beforeInst;
      do {
        uVar4 = piVar13[5];
        if ((uVar4 & 1) != 0) {
          local_54[iVar14] = (int *)0x0;
          if ((piVar13[5] & 0x200U) != 0) {
            if ((piVar13[5] & 2U) == 0) {
              operandVReg4 = (int *)IRInst__getOperandSource(piVar13,piVar13[0x21]);
              iVar6 = (**(code **)(*operandVReg4 + 0x50))(operandVReg4);
              if ((iVar6 == 0) && ((piVar13[5] & 0x800000U) == 0)) {
                uVar11 = thunk_FUN_00134de8(*(undefined4 *)(*param_1 + 0x6c4),piVar13);
                iVar6 = ((int (*)())IRInst__lastSourceKeyEquals)(piVar13,uVar11,*param_1);
                if (iVar6 == 0) {
                  local_54[iVar14] = piVar13;
                  iVar14 = iVar14 + 1;
                  piVar13[5] = piVar13[5] | 0x800000;
                }
              }
            }
            else {
              IRInst__setOperandSource(piVar13,piVar13[0x21],0,0,*param_1);
              piVar13[0x21] = piVar13[0x21] + -1;
              piVar13[5] = piVar13[5] & 0xfffffdff;
            }
          }
          if ((piVar13[0x20] == 0) || (iVar6 = RegKind__flagBit0(piVar13[0x26]), iVar6 == 0)) {
            uVar4 = piVar13[5];
          }
          else {
            uVar4 = piVar13[5];
            if ((uVar4 & 2) == 0) {
              (**(code **)(*piVar13 + 0x50))(piVar13);
              uVar4 = piVar13[5];
            }
          }
        }
        piVar13 = (int *)piVar13[2];
      } while ((piVar13 != (int *)0x0) && ((uVar4 & 4) != 0));
    }
    else {
      piVar13 = (int *)0x0;
      iVar14 = 0;
    }
    piVar8 = local_54[0];
    piVar13 = (int *)piVar13[1];
    if (iVar14 != 0) {
      bVar1 = iVar14 == 2;
      if (bVar1) {
        iVar14 = thunk_FUN_00134de8(*(undefined4 *)(*param_1 + 0x6c4),local_54[0]);
        operandVReg3 = (int *)IRInst__getOperandSource(piVar8,piVar8[0x21]);
        piVar9 = local_54[1];
        iVar6 = thunk_FUN_00134de8(*(undefined4 *)(*param_1 + 0x6c4),local_54[1]);
        operandVReg2 = (int *)IRInst__getOperandSource(piVar9,piVar9[0x21]);
        if ((iVar14 == iVar6) && (operandVReg3 == operandVReg2)) {
          param_1[1] = param_1[1] + 1;
          iVar14 = ((int (*)())IRInst__createMovForDest)(piVar8,operandVReg2,*param_1);
          FUN_000f47a8(iVar14,piVar8,piVar9);
          Block__insertInstAfter(piVar13[0x56],piVar13,iVar14);
          return iVar14;
        }
        iVar6 = ((int (*)())IRInst__lastSourceKeyEquals)(piVar8,iVar6,*param_1);
        if (iVar6 == 0) {
          bVar2 = true;
          param_1[1] = param_1[1] + 1;
          piVar8 = (int *)((int (*)())IRInst__createMovForDest)(piVar8,operandVReg3,*param_1);
          Block__insertInstAfter(piVar13[0x56],piVar13,piVar8);
          local_54[0] = piVar9;
          piVar13 = piVar8;
        }
        else {
          iVar14 = ((int (*)())IRInst__lastSourceKeyEquals)(piVar9,iVar14,*param_1);
          if (iVar14 == 0) {
            bVar2 = true;
            param_1[1] = param_1[1] + 1;
            piVar8 = (int *)((int (*)())IRInst__createMovForDest)(piVar9,operandVReg2,*param_1);
            Block__insertInstAfter(piVar13[0x56],piVar13,piVar8);
            piVar13 = piVar8;
          }
          else if (operandVReg3 == piVar9) {
            bVar2 = false;
            param_1[1] = param_1[1] + 1;
            piVar8 = (int *)((int (*)())IRInst__createMovForDest)(piVar8,piVar9,*param_1);
            Block__insertInstAfter(piVar13[0x56],piVar13,piVar8);
            local_54[0] = piVar9;
            piVar13 = piVar8;
          }
          else {
            if (piVar8 != operandVReg2) {
              bVar2 = true;
              bVar1 = true;
              goto LAB_000e4140;
            }
            bVar2 = false;
            param_1[1] = param_1[1] + 1;
            piVar8 = (int *)((int (*)())IRInst__createMovForDest)(piVar9,piVar8,*param_1);
            Block__insertInstAfter(piVar13[0x56],piVar13,piVar8);
            piVar13 = piVar8;
          }
        }
      }
      else {
        bVar2 = true;
        if (iVar14 != 1) {
LAB_000e4140:
          piVar8 = local_54[0];
          sourceDef = IRInst__getOperandSource(local_54[0],local_54[0][0x21]);
          param_1[2] = param_1[2] + 1;
          iVar10 = piVar8[0x26];
          iVar6 = piVar8[0x25];
          uVar12 = ((int (*)())FUN_000e2a04)(param_1,(uint)(iVar10 != 0));
          iVar14 = ((int (*)())FUN_000e2f04)(piVar8,uVar12,iVar10,sourceDef,*param_1);
          Block__insertInstBefore(beforeInst[0x56],beforeInst,iVar14);
          piVar9 = piVar13;
          if (bVar1) {
            sourceDef = IRInst__getOperandSource(local_54[1],local_54[1][0x21]);
            param_1[1] = param_1[1] + 1;
            piVar9 = (int *)((int (*)())IRInst__createMovForDest)(local_54[1],sourceDef,*param_1);
            Block__insertInstAfter(piVar13[0x56],piVar13,piVar9);
            IRInst__setOperandSource(local_54[1],local_54[1][0x21],0,0,*param_1);
            local_54[1][0x21] = local_54[1][0x21] + -1;
            local_54[1][5] = local_54[1][5] & 0xfffffdff;
          }
          if (bVar2) {
            param_1[1] = param_1[1] + 1;
            piVar13 = (int *)IRInst__clone(piVar8,*param_1,0);
            DList__insertBefore(piVar13,piVar8);
            IRInst__setOperandSource(piVar13,piVar13[0x21],0,0,*param_1);
            piVar13[0x21] = piVar13[0x21] + -1;
            piVar13[5] = piVar13[5] & 0xfffffdff;
            if (piVar9 == piVar8) {
              piVar9 = piVar13;
            }
            uVar4 = piVar8[5];
            DList__unlink(piVar8);
            IRInst__reinitAsMov(piVar8,0x31,*param_1);
            piVar8[0x25] = iVar6;
            piVar8[0x26] = iVar10;
            if ((uVar4 & 0x40) == 0) {
              uVar3 = piVar8[5] & 0xffffffbf;
              piVar8[5] = uVar3;
            }
            else {
              uVar3 = piVar8[5] | 0x40;
              piVar8[5] = uVar3;
            }
            if ((uVar4 & 0x20) == 0) {
              piVar8[5] = uVar3 & 0xffffffdf;
            }
            else {
              piVar8[5] = uVar3 | 0x20;
            }
            IRInst__setOperandSource(piVar8,1,piVar13,0,*param_1);
            DList__insertAfter(piVar8,piVar9);
          }
          *param_4 = 1;
          return iVar14;
        }
      }
      piVar8 = local_54[0];
      iVar14 = thunk_FUN_00134de8(*(undefined4 *)(*param_1 + 0x6c4),local_54[0]);
      operandRecord = IRInst__getOperandRecord(piVar8,0);
      local_58 = *(undefined4 *)(operandRecord + 0x10);
      operandVReg = (int *)IRInst__getOperandSource(piVar8,piVar8[0x21]);
      iVar6 = thunk_FUN_00134de8(*(undefined4 *)(*param_1 + 0x6c4),operandVReg);
      if (beforeInst != (int *)0x0) {
        bVar1 = false;
        piVar5 = beforeInst;
        do {
          uVar4 = piVar5[5];
          if ((uVar4 & 1) != 0) {
            iVar10 = thunk_FUN_00134de8(*(undefined4 *)(*param_1 + 0x6c4),piVar5);
            if ((iVar6 == iVar10) && (piVar5 != operandVReg)) {
              bVar1 = true;
            }
            if (piVar5 == piVar8) {
              uVar4 = piVar8[5];
            }
            else {
              iVar10 = thunk_FUN_00134de8(*(undefined4 *)(*param_1 + 0x6c4),piVar5);
              uVar11 = local_58;
              if (iVar14 == iVar10) {
                operandRecord2 = IRInst__getOperandRecord(piVar5,0);
                SelectWord__mergeWrittenLanes(local_54 + 3,uVar11,*(undefined4 *)(operandRecord2 + 0x10));
                local_58 = local_54[3];
                uVar4 = piVar5[5];
              }
              else {
                uVar4 = piVar5[5];
              }
            }
          }
          piVar5 = (int *)piVar5[2];
        } while ((piVar5 != (int *)0x0) && ((uVar4 & 4) != 0));
        piVar5 = beforeInst;
        if (bVar1) {
          do {
            uVar4 = piVar5[5];
            if ((uVar4 & 1) != 0) {
              iVar6 = ((int (*)())FUN_000e2acc)(piVar5,iVar14,*param_1);
              if (iVar6 != 0) {
LAB_000e413c:
                bVar1 = false;
                goto LAB_000e4140;
              }
              uVar4 = piVar5[5];
              if ((uVar4 & 0x200) != 0) {
                iVar6 = ((int (*)())IRInst__lastSourceKeyEquals)(piVar5,iVar14,*param_1);
                if (iVar6 != 0) goto LAB_000e413c;
                uVar4 = piVar5[5];
              }
            }
            piVar5 = (int *)piVar5[2];
            if ((piVar5 == (int *)0x0) || ((uVar4 & 4) == 0)) {
              param_1[1] = param_1[1] + 1;
              iVar14 = ((int (*)())IRInst__createMovForDest)(piVar8,operandVReg,*param_1);
              Block__insertInstBefore(beforeInst[0x56],beforeInst,iVar14);
              IRInst__setOperandSource(piVar8,piVar8[0x21],0,0,*param_1);
              piVar8[0x21] = piVar8[0x21] + -1;
              piVar8[5] = piVar8[5] & 0xfffffdff;
              IRInst__setExtraOperandSource(piVar8,iVar14,0,*param_1);
              *param_4 = 1;
              return iVar14;
            }
          } while( true );
        }
      }
      param_1[1] = param_1[1] + 1;
      iVar14 = ((int (*)())IRInst__createMovForDest)(piVar8,operandVReg,*param_1);
      iVar10 = 4;
      iVar6 = 0;
      do {
        if (*(char *)((int)&local_58 + iVar6) == '\x01') {
          *(undefined1 *)((int)&local_58 + iVar6) = 0;
        }
        else {
          *(undefined1 *)((int)&local_58 + iVar6) = 1;
        }
        iVar6 = iVar6 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      operandRecord = IRInst__getOperandRecord(iVar14,0);
      SelectWord__markLanesWhereSecondIsOne(local_44,*(undefined4 *)(operandRecord + 0x10),local_58);
      local_58 = local_44[0];
      *(undefined4 *)(iVar14 + 0x9c) = local_44[0];
      Block__insertInstAfter(piVar13[0x56],piVar13,iVar14);
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
int setWord30(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x30) = param_2;
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

/* FUN_000e468c @ 0xe468c (132 bytes) */
int FUN_000e468c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x14) + 0x14);
  while (*piVar1 != param_2) {
    if (*(int **)(param_1 + 0x18) == piVar1) {
      return 0;
    }
    piVar1 = (int *)piVar1[5];
    if (piVar1 == (int *)0x0) {
      return 0;
    }
  }
  if (param_3 < 4) {
    *param_4 = piVar1[param_3 + 1];
    return 1;
  }
  if (param_3 != 4) {
    if (param_3 != 5) {
      return 0;
    }
    *param_4 = 1;
    return 1;
  }
  *param_4 = 0;
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
